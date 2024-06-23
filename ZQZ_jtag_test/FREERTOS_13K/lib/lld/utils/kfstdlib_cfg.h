/**********************************************************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 **********************************************************************************************************************
 *  @File Name       : kfstdlib_cfg.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2024-02-14
 *  @Version         : V1.0.0
 *  @Description     : This document describes the C language document template.
 **********************************************************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd All rights reserved.
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 **********************************************************************************************************************
 *                                               REVISION HISTORY
 **********************************************************************************************************************
 *  |Date        |Version  |Author       |Description
 **********************************************************************************************************************
 *  |2023-4-15   |V1.0     |Zhang quanzhen     |New create
 **********************************************************************************************************************/
#ifndef KFSTDLIB_CFG_H
#define KFSTDLIB_CFG_H

/**********************************************************************************************************************
 *                                               QAC Warnings
 **********************************************************************************************************************/
/**
 * @page QAC Warnings
 *
 */

/**********************************************************************************************************************
 *                                               Include Files
 **********************************************************************************************************************/
#include "kf_types.h"
/**********************************************************************************************************************
 *                                               General configuration
 **********************************************************************************************************************/

/**
 * KFSTDLIB_USE_LIBRARY_FUNCTIONS
 *
 * If set to STD_ON all memory manipulation routines are mapped to external functions (e.g. compiler libraries or other
 * implementations that are optimized for the target platform). This is recommended when using 16bit MCUs for example
 * as the generic KFStdLib implementation provides optimized routines only for 32bit platforms.
 *
 * Values:
 * STD_ON  - Use external memory manipulation functions - requires additional configuration, see below.
 * STD_OFF - Use generic memory manipulation functions provided by KFStdLib
 *
 * Default:
 * STD_OFF
 */
#define KFSTDLIB_USE_LIBRARY_FUNCTIONS STD_OFF

/**
 * KFSTDLIB_RUNTIME_OPTIMIZATION
 *
 * If set to STD_ON optimized routines are used to increase the performance of the memory manipulation functions.
 * The setting if this define is only relevant if KFSTDLIB_USE_LIBRARY_FUNCTIONS == STD_OFF.
 *
 * Values:
 * STD_ON  - Use optimized routines for memory operations (runtime efficient, but increases code size)
 * STD_OFF - Use simple routines for memory operations (code efficient, but significantly increases runtime)
 *
 * Default:
 * STD_ON
 */
#define KFSTDLIB_RUNTIME_OPTIMIZATION STD_ON

/**
 * KFSTDLIB_USE_JUMPTABLES
 *
 * If set to STD_ON jump tables are used to increase the performance of the memory manipulation functions.
 * The setting of this define is only relevant if KFSTDLIB_USE_LIBRARY_FUNCTIONS == STD_OFF and
 * KFSTDLIB_RUNTIME_OPTIMIZATION == STD_ON.
 *
 * Values:
 * STD_ON  - Use jump tables for memory operations (runtime efficient in general, but may depend on compiler)
 * STD_OFF - Use loops for memory operations (code efficient, also use this if the compiler generates no efficient
 *           code for the jump tables)
 *
 * Default:
 * STD_ON
 */
#define KFSTDLIB_USE_JUMPTABLES STD_ON

/**
 * KFSTDLIB_DEV_ERROR_DETECT
 *
 * If set to STD_ON the development error detection is enabled. In this case the pointer arguments of all global
 * module functions are checked. If any NULL_PTR is passed, these functions return without performing any action.
 * Please note that this setting is only relevant for development error detection and has no influence on
 * MICROSAR SafeBSW.
 *
 * Values:
 * STD_ON  - Check function arguments
 * STD_OFF - Disable development error detection
 *
 * Default:
 * STD_OFF
 */
#define KF_DRV_STDLIB_ASSERT STD_ON

/**
 * KFSTDLIB_DUMMY_STATEMENT
 *
 * Expression that is used for dummy statements to avoid compile warnings about unused identifiers.
 *
 * Example values:
 * (void)(v)
 * (v)=(v)
 * or leave the definition empty to disable the usage of dummy statements
 *
 * Default:
 * (void)(v)
 */
#define KFSTDLIB_DUMMY_STATEMENT(v) (void)(v)

/**********************************************************************************************************************
 *  Additional configuration if KFSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON
 **********************************************************************************************************************/
#if (KFSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON)
#include "string.h"
/**
 * Memory manipulation library functions.
 *
 * If KFSTDLIB_USE_LIBRARY_FUNCTIONS is set to STD_ON it is necessary to specify memory manipulation functions by
 * overwriting the definitions below. The error directive has to be removed.
 *
 * NOTE:
 * - If the external functionality is not able to handle more than 65535 bytes it is necessary to define
 *   KFSTDLIB_SUPPORT_LARGE_DATA to STD_OFF.
 * - It has to be ensured that the specified functions are able to copy from and to all memory locations independently
 *   of the pointer length. The specified functions must behave synchronously.
 */
#define KFSTDLIB_SUPPORT_LARGE_DATA STD_ON

/* Set nCnt bytes to zero at DstPtr (any alignment) */
#define KFStdLib_MemClr(DstPtr, nCnt) memset((DstPtr), 0U, (nCnt))

/* Set nCnt bytes to the character nSrc at DstPtr (any alignment) */
#define kfStdLib_MemSet(DstPtr, nSrc, nCnt) memset((DstPtr), (nSrc), (nCnt))

/* Copy nCnt bytes from SrcPtr to DstPtr (any alignment) */
#define kfStdLib_MemCopy(DstPtr, SrcPtr, nCnt) memcpy((DstPtr), (SrcPtr), (nCnt))

/* Copy nCnt 16bit blocks from SrcPtr to DstPtr (both pointers 16-bit aligned) */
#define kfStdLib_MemCopy16(DstPtr, SrcPtr, nCnt) memcpy((DstPtr), (SrcPtr), ((nCnt) << 1U))

/* Copy nCnt 32bit blocks from SrcPtr to DstPtr (both pointers 32-bit aligned) */
#define kfStdLib_MemCopy32(DstPtr, SrcPtr, nCnt) memcpy((DstPtr), (SrcPtr), ((nCnt) << 2U))

#endif
/**********************************************************************************************************************
 * Compatibility for legacy Vector modules - can be ignored in general
 **********************************************************************************************************************/

#if defined(KFSTD_ENABLE_INTCTRL_HANDLING) || defined(KFSTD_ENABLE_DEFAULT_INTCTRL) ||                                 \
  defined(KFSTD_ENABLE_OSEK_INTCTRL) || defined(KFSTD_ENABLE_APPL_INTCTRL)
/**
 * Compatibility for legacy Vector modules.
 *
 * Legacy Vector modules that are used in a MICROSAR stack might rely on interrupt handling functionalities that
 * are no longer supported by KFStdLib. Map relevant calls to functionalities that are provided by the MICROSAR stack
 * or application. KFStdSuspendAllInterrupts() and KFStdResumeAllInterrupts() can be mapped to an exclusive area that
 * is provided by the BSW scheduler for example.
 */
#error "KFStdLib_GenericAsr does not support interrupt control handling!"

#endif

#endif /* KFSTDLIB_CFG_H */
/* EOF */
