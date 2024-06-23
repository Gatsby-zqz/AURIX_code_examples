/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kflog.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2024-02-14
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
 *  |2022-09-06  |V1.0     |wangning     |New creat
 *  |2022-11-18  |V1.1     |Zhai Yu     | QAC compliance check
 *****************************************************************************/
#ifndef _KF_PRINTF_H
#define _KF_PRINTF_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef FREERTOS_TEST
/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 * MISRA RULE 1.2 - Language extensions should not be used
 * MISRA RULE 20.10 - The # and ## preprocessor operators should not be used
 * MISRA DIR 4.6 - Use of basic type int
 */

/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 3412,3435 EOF */
/* PRQA S 4589 EOF */
/* PRQA S 4590 EOF */
/* PRQA S 1038 EOF */
/* PRQA S 1307 EOF */ /* Unnamed 'struct' and 'union' types may cause
                         portability problems when moving to C++. */
/* PRQA S 0342,0341 EOF # Suppress MISRA RULE 20.10 */
/* PRQA S 5209 EOF */ /* MISRA DIR 4.6 violation - Use of basic type int */
/* PRQA S 3625 EOF */ /* Type 'char' has been used in the declaration of an
                         object or a function. */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "bspcfg.h"
#include "kf32a13k_hw_gpio.h"
#include "kf32a13k_hw_utlin.h"
#include "kf_types.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#ifdef SIMULATION
#include <time.h>
#define LOG_FILE "log.txt"

#ifdef __cplusplus
#define FUNC_NAME __func__
#else
#ifdef __GUNC__
#define FUNC_NAME __FUNCTION__
#else
#define FUNC_NAME "UnkonwnFunction"
#endif
#endif
/**
 * @brief log function marco, use as save log to debug
 *  please include "kflog.h" before use it.
 *
 * @ param message
 * @ use example：
 * kf_printf("BptTc01 search case had been running %d",i);
 * kf_printf("count_bpt %d count_apt %d",count_bpt,count_apt);
 */
#define kf_printf(msg, ...)                                                                                            \
    do                                                                                                                 \
    {                                                                                                                  \
        FILE *log_file = fopen(LOG_FILE, "a");                                                                         \
        if (log_file)                                                                                                  \
        {                                                                                                              \
            time_t     rawTime;                                                                                        \
            struct tm *timeInfo;                                                                                       \
            char       time_str[80];                                                                                   \
            time(&rawTime);                                                                                            \
            timeInfo = localtime(&rawTime);                                                                            \
                                                                                                                       \
            strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeInfo);                                       \
            fprintf(log_file, "[%s] [%s] " msg "\n", time_str, FUNC_NAME, ##__VA_ARGS__);                              \
            fclose(log_file);                                                                                          \
        }                                                                                                              \
        printf("[%s] " msg "\n", FUNC_NAME, ##__VA_ARGS__);                                                            \
    } while (0)

#elif (INTERNAL_PRINT == STD_ON)
/**
 * @brief:log level
 */
#ifndef KF_LOG_LEVEL
#define KF_LOG_LEVEL 0U
#endif

#define KF_LOG_DEBUG         (1U << 0U)
#define KF_LOG_INFO          (1U << 1U)
#define KF_LOG_WARN          (1U << 2U)
#define KF_LOG_ERROR         (1U << 3U)

/**
 * @brief:The properties printed when the log module is registered
 */
#define KF_LOG_OPT_FUNC      ((uint32_t)(1U << 0U))
#define KF_LOG_OPT_LINE      ((uint32_t)(1U << 1U))
#define KF_LOG_OPT_FILE      ((uint32_t)(1U << 2U))
#define KF_LOG_OPT_TICK      ((uint32_t)(1U << 3U))

/**
 * @brief:Registering the Log module
 */
#define KF_REF_LOG(TAG)      extern Log_PrintfType log_##TAG##_module;
#define KF_REG_LOG(TAG, OPT) Log_PrintfType log_##TAG##_module = {.name = #TAG, .opt = (OPT)};

/**
 * @brief:Log output, including debugging, information, alarm, and error, is
 * generated by calling different interfaces
 */

#if (KF_LOG_DEBUG > KF_LOG_LEVEL)
#define KFLOG_D(TAG, MSG, ...)                                                                                         \
    kfLog_Printf((Log_PrintfType *)&log_##TAG##_module, __func__, __LINE__, __FILE__, MSG, ##__VA_ARGS__)
#else
#define KFLOG_D(TAG, MSG, ...)
#endif

#if (KF_LOG_INFO > KF_LOG_LEVEL)
#define KFLOG_I(TAG, MSG, ...)                                                                                         \
    kfLog_Printf((Log_PrintfType *)&log_##TAG##_module, __func__, __LINE__, __FILE__, MSG, ##__VA_ARGS__)
#else
#define KFLOG_I(TAG, MSG, ...)
#endif

#if (KF_LOG_WARN > KF_LOG_LEVEL)
#define KFLOG_W(TAG, MSG, ...)                                                                                         \
    kfLog_Printf((Log_PrintfType *)&log_##TAG##_module, __func__, __LINE__, __FILE__, MSG, ##__VA_ARGS__)
#else
#define KFLOG_W(TAG, MSG, ...)
#endif

#if (KF_LOG_ERROR > KF_LOG_LEVEL)
#define KFLOG_E(TAG, MSG, ...)                                                                                         \
    kfLog_Printf((Log_PrintfType *)&log_##TAG##_module, __func__, __LINE__, __FILE__, MSG, ##__VA_ARGS__)
#else
#define KFLOG_E(TAG, MSG, ...)
#endif

/**
 * @brief:Pure output (pure), without the registration module header
 */
#define kf_printf(MSG, ...) kfLog_Printf(NULL, __func__, __LINE__, __FILE__, MSG "\r\n", ##__VA_ARGS__)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/* PRQA S 3630 ++ */
/**
 * @brief: Log Output module information
 */
typedef struct
{
    /** @brief Module Name  */
    char *name;
    /** @brief Information Properties */
    uint32_t opt;
} Log_PrintfType;
/* PRQA S 3630 -- */

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

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
extern void kfLog_Printf(const Log_PrintfType *const plog_module, const char *pfun, int line, const char *pfile,
                         const char *format, ...);

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
extern void kfLog_Init(void);

#else
#define KF_REF_LOG(TAG)
#define KF_REG_LOG(TAG, OPT)
#define KFLOG_D(TAG, MSG, ...)
#define KFLOG_I(TAG, MSG, ...)
#define KFLOG_W(TAG, MSG, ...)
#define KFLOG_E(TAG, MSG, ...)
#define kf_printf(MSG, ...) ((const char *)0U)
#define kfLog_Init()
#endif
#endif /* FREERTOS_TEST */
#ifdef __cplusplus
}
#endif

#endif
/* EOF */
