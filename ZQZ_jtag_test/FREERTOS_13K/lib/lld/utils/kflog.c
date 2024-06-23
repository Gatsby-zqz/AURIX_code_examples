/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kflog.c
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2024-04-23
 *  @Version         : V1.0.0
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyrght protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2024-04-23  |V1.0     |ZhanaQuanzhen|New creat
 *****************************************************************************/

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 * MISRA DIR 4.6 - Use of basic type int
 * MISRA RULE 17.1 - Use of variable arguments handling identifier: va_arg,
 * va_start, va_end, va_copy
 * MISRA RULE 17.8 - A function parameter should not be modified
 * MISRA RULE 11.4 - Cast between a pointer to volatile object and an integral
 * type.
 * MISRA RULE 8.9 - An object should be defined at block scope if its identifier
 * only appears in a single function
 * MISRA RULE 8.4 - A compatible declaration shall be visible when an object or
 * function with external linkage is defined
 * MISRA RULE 20.5 - #undef should not be used
 */

/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 0303 EOF # Register Address Cast is allowed */
/* PRQA S 5209 EOF #Suppress MISRA DIR 4.6 violation */
/* PRQA S 1337,5130,5140 EOF #Suppress MISRA RULE 17.1 */
/* PRQA S 4442 EOF #Suppress MISRA RULE 10.3 */
/* PRQA S 3218 EOF #Suppress MISRA RULE 8.9 */
/* PRQA S 1339 EOF #Suppress MISRA RULE 17.8 */
/* PRQA S 0841 EOF #Suppress MISRA RULE 20.5 */
/* PRQA S 0769 EOF */ /* A 'break' statement has been used to terminate an
                         iteration statement. */
/* PRQA S 3416 EOF */ /* Logical operation performed on expression */
/* PRQA S 0702 EOF */ /* Result of sizeof operator is not explicitly cast. */
/* PRQA S 1441 EOF */ /* pass a function parameter of enum type. */
/* PRQA S 2000 EOF */ /* No 'else' clause exists for this 'if' statement. */
/* PRQA S 2839 EOF */ /* Possible: Non-null terminated string used in a string
                         function. */
/* PRQA S 3227 EOF */ /* The parameter is never modified and so it could be
                         declared with the 'const' qualifier. */
/* PRQA S 3625 EOF */ /* Type 'char' has been used in the declaration of an
                         object or a function. */
/* PRQA S 0751 EOF */ /* Casting to char pointer type. */
/* PRQA S 3408 EOF #Suppress MISRA RULE 8.4 violation */

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "kflog.h"
#ifndef FREERTOS_TEST
#if (INTERNAL_PRINT == STD_ON)
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Parameters Config
 ******************************************************************************/
extern const Utlin_ConfigType_t Utlin_KflogConfig;
static Utlin_HwType_t           Utlin_KflogHw;

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#define KFLOG_UART_MAX_DATA_LEN ((uint32_t)256U)
#define KFLOG_UART_MAX_LINE_NUM ((uint32_t)12U)

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
static void kfLog_UartSend(const uint8_t *pSendData, int32_t SendLen);

/******************************************************************************
**                     Variable Declarations
******************************************************************************/

/**
 * @brief log output buffer
 */
static char kvLog_SendData[KFLOG_UART_MAX_DATA_LEN] = {0};
static char kvLog_LineNum[KFLOG_UART_MAX_LINE_NUM]  = {0};

/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/* PRQA S 2889,0771 ++ */ /* This function has more than one 'return' path. */
/* PRQA S 2934 ++ */      /* Possible: Computing an invalid pointer value. */

/**
 * @brief send data and waits for completion
 * @param pSendData-send data point
 * SendLen-send data length
 *
 * @retval void
 */
static void kfLog_UartSend(const uint8_t *pSendData, int32_t SendLen)
{
    uint8_t ret;

    if (((uint8_t *)0U == pSendData) || (0U == SendLen))
    {
        return;
    }
    (void)Utlin_Hw_Write(&Utlin_KflogHw, (void *)pSendData, &SendLen, 0U);
}
/* PRQA S 2889,0771 -- */

/**
 * @brief Pin configuration of uart. PA3 and PE7 are used by default. If other
 * pins are used, you can copy this function in the file used, without using a
 * weak definition
 *
 *
 * @retval void
 */
__attribute__((weak)) void kfLog_UartPinInit(void)
{
#define UART_RX_PIN   (GPIO_PIN_INDEX_0)
#define UART_TX_PIN   (GPIO_PIN_INDEX_0)
#define UART_RX_REMAP (GPIO_PIN_REMAP_AF3)
#define UART_TX_REMAP (GPIO_PIN_REMAP_AF3)
    // TODO:need to confirm
    Gpio_RegisterMap_t *const UartRxPortAddrPtr = GPIO0_PTR;
    Gpio_RegisterMap_t *const UartTxPortAddrPtr = GPIO0_PTR;

    /* init uart rx */
    /* assign PODR register to config value */
    Gpio_LL_WriteOpenDrainStatus(UartRxPortAddrPtr, UART_RX_PIN, 0U);

    /* assign PDR register to config value */
    Gpio_LL_WritePullUpDownStatus(UartRxPortAddrPtr, UART_RX_PIN, GPIO_PIN_PUPD_NONE0);

    /* assign RMPL register and OMOD to config value */

    /* assign PMOD register to config value */

    /* init uart tx */
    /* assign PODR register to config value */
    Gpio_LL_WriteOpenDrainStatus(UartTxPortAddrPtr, UART_TX_PIN, 0U);

    /* assign PDR register to config value */
    Gpio_LL_WritePullUpDownStatus(UartTxPortAddrPtr, UART_TX_PIN, GPIO_PIN_PUPD_NONE0);

    /* assign PMOD register to config value */

    /* assign RMPL register and OMOD to config value */
#undef UART_RX_PIN
#undef UART_TX_PIN
#undef UART_RX_REMAP
#undef UART_TX_REMAP
}

/**
 * @brief Log information output
 *
 * @param plog_module Information about the registered module
 * @param pfun function name
 * @param line line num
 * @param pfile The file path
 * @param format varargs
 * @param ...
 *
 * @retval void
 */
void kfLog_Printf(const Log_PrintfType *const plog_module, const char *pfun, int line, const char *pfile,
                  const char *format, ...)
{
    va_list  args;
    uint16_t TmpLen = 0U;

    if ((NULL_PTR == pfile) || (NULL_PTR == pfun) || (NULL_PTR == format))
    {
        return;
    }

    (void)memset(kvLog_SendData, 0, sizeof(kvLog_SendData));
    (void)memset(kvLog_LineNum, 0, sizeof(kvLog_LineNum));

    do
    {
        /* module name */
        if ((NULL_PTR != plog_module) && (NULL_PTR != plog_module->name))
        {
            if ((strlen(plog_module->name) + 2U) > (sizeof(kvLog_SendData) - 1U))
            {
                break;
            }
            (void)sprintf(kvLog_SendData, "[%s]", plog_module->name);
            TmpLen = (uint16_t)strlen(kvLog_SendData);
            /* PRQA S 3344,4399 1 */ /* MISRA RULE 14.4 */
            if (plog_module->opt & KF_LOG_OPT_FUNC)
            {
                /* PRQA S 3383 1 */ /* Arithmetric won't wraparound */
                if ((TmpLen + strlen(pfun) + 2U) > (sizeof(kvLog_SendData) - 1U))
                {
                    break;
                }
                (void)sprintf(&kvLog_SendData[strlen(kvLog_SendData)], "[%s]", pfun);
                TmpLen = (uint16_t)strlen(kvLog_SendData);
            }
            /* PRQA S 3344,4399 1 */ /* MISRA RULE 14.4 */
            if (plog_module->opt & KF_LOG_OPT_LINE)
            {
                (void)sprintf(kvLog_LineNum, "%d", line);
                if ((TmpLen + strlen(kvLog_LineNum) + 2U) > (sizeof(kvLog_SendData) - 1U))
                {
                    break;
                }
                (void)sprintf(&kvLog_SendData[strlen(kvLog_SendData)], "[%d]", line);
                TmpLen = (uint16_t)strlen(kvLog_SendData);
            }
            /* PRQA S 3344,4399 1 */ /* MISRA RULE 14.4 */
            if (plog_module->opt & KF_LOG_OPT_FILE)
            {
                if ((TmpLen + strlen(pfile) + 2U) > (sizeof(kvLog_SendData) - 1U))
                {
                    break;
                }
                (void)sprintf(&kvLog_SendData[strlen(kvLog_SendData)], "[%s]", pfile);
                TmpLen = (uint16_t)strlen(kvLog_SendData);
            }
        }
        /* PRQA S 3432 ++ */     /* Simple macro argument expression is not
                           parenthesized. */
        /* PRQA S 0488,0751 1 */ /* Performing pointer arithmetic. */
        va_start(args, format);
        /* PRQA S 0432 2 */ /* Function argument is not of compatible pointer
                               type. */
        if ((TmpLen + strlen(format) + strlen(args)) > (sizeof(kvLog_SendData) - 1U))
        {
            /* PRQA S 2983 1 */ /* This assignment is redundant */
            va_end(args);
            break;
        }

        (void)vsprintf(&kvLog_SendData[strlen(kvLog_SendData)], format, args);
        /* PRQA S 2983 1 */ /* This assignment is redundant */
        va_end(args);
        /* PRQA S 3432 -- */
    } while (0);

    /* send data */
    kfLog_UartSend((uint8_t *)kvLog_SendData, (uint16_t)strlen(kvLog_SendData));
}

/**
 * @brief Log output initialization
 * 1.The default value is UART0. If you need to change the value, change the
 * KFLOG_UART_DEV
 * 2.The default baud rate is 230400
 * 3.8bits Data , 1 stop bit, no flow control, Odd parity
 *
 *
 * @retval void
 */
void kfLog_Init(void)
{
#if (PIN_PRINT == STD_ON)
    /* uart pin init */
    kfLog_UartPinInit();
#endif
    Utlin_Hw_Init(&Utlin_KflogHw, &Utlin_KflogConfig);
}
#endif
#endif
/* EOF */
