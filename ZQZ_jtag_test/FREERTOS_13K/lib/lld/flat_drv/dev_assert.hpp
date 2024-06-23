/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : dev_assert.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2023-06-25
 *  @Version         : V0.0.1.230625_alpha
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyrght protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2021-12-23  |V1.0     |Zhai yu     |New creat
 *  |2022-11-18  |V1.1     |Zhai Yu     | QAC compliance check
 *****************************************************************************/
#ifndef DEV_ASSERT_H
#define DEV_ASSERT_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(KF_DEV_ERROR_DETECT)

#include "kflog.h"
#include <stdbool.h>
/* PRQA S 3006 EOF */ /* This function contains a mixture of in-line
                         assembler statements and C statements. */
/* PRQA S 1006 EOF */ /* This in-line assembler construct is a language
                         extension. The code has been ignored */
/* PRQA S 5209 EOF */ /* MISRA DIR 4.6 violation - Use of basic type int */
/* PRQA S 3625 EOF */ /* Type 'char' has been used in the declaration of an
                         object or a function. */

/**
 * @brief Implement default assert macro
 *
 * @param[in] x
 * @param[in] file
 * @param[in] line
 */
static inline void DevAssert(bool x, const char *const file, int line)
{
    if (!x)
    {
        kf_printf("%s,%d\r\n", file, line);
        asm("DSI");
        asm("NOP");
        asm("BREAK");
        /* PRQA S 2870 1 */
        for (;;)
        {
        }
    }
    else
    {
    }
}
#define KF_DEV_ASSERT(x) DevAssert((bool)(x), __FILE__, __LINE__)
#else
/* Assert macro does nothing */
#define KF_DEV_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
