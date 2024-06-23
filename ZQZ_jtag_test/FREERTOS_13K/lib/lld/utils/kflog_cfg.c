/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kflog_cfg.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
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
#ifndef FREERTOS_TEST
#if (INTERNAL_PRINT == STD_ON)
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "kflog.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Parameters Config
 ******************************************************************************/
static Utlin_Hw_BitTimingControlType_t Utlin_BitTimingConfig = {
  .SampleMode          = UTLIN_SAMPLESPERBIT_ONE,
  .SamplePointPosition = UTLIN_SAMPLEPOINTPOSITION_1,
};

static Utlin_BitTimingType_t Utlin_BitTimeingConfig = {
  .Prescaler           = 1U,
  .Oversampling        = UTLIN_OVERSAMPLINGFACTOR_4,
  .BitTimingControlPtr = &Utlin_BitTimingConfig,
};

static Utlin_FrameControlType_t Utlin_FrameConfig = {
  .IdleDelay    = UTLIN_IDLEDELAY_0,
  .StopBit      = STOP_0_BIT,
  .FrameMode    = UTLIN_HW_FRAMEMODE_UART,
  .ParityMode   = UTLIN_PARITY_ODD,
  .DataLength   = UTLIN_DATALENGTH_1,
  .ParityEnable = false,
};

static Utlin_FifoControlType_t Utlin_FifoConfig = {
  .InWidth              = UTLIN_HW_TXFIFOINPUTWIDTH_0,
  .OutWidth             = UTLIN_HW_RXFIFOOUTPUTWIDTH_0,
  .TxFifoInterruptLevel = UTLIN_HW_TXFIFOINTERRUPTLEVEL_0,
  .RxFifoInterruptLevel = UTLIN_HW_RXFIFOINTERRUPTLEVEL_1,
  .FifoMode             = UTLIN_HW_SINGLE_TRANSMISSION,
};

static Utlin_InterruptConfigType_t Utlin_IntrConfig = {
  .TxPriority    = 0U,
  .RxPriority    = 0U,
  .ErPriority    = 0U,
  .TypeOfService = UTLIN_HW_SERVICE_CPU0,
};

const Utlin_ConfigType_t Utlin_KflogConfig = {
  .Module          = UTLIN0_PTR,
  .BitTimingPtr    = &Utlin_BitTimeingConfig,
  .FrameControlPtr = &Utlin_FrameConfig,
  .FifoControlPtr  = &Utlin_FifoConfig,
  .InterruptPtr    = &Utlin_IntrConfig,
  .TxBufferPtr     = NULL_PTR,
  .RxBufferPtr     = NULL_PTR,
  .TxBufferSize    = 0U,
  .RxBufferSize    = 0U,
  .ClockSource     = UTLIN_S_CLOCK,
  .LoopBack        = false,
};

#endif
#endif
/* EOF */
