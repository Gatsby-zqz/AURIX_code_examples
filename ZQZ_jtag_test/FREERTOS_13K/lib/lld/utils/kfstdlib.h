/**********************************************************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 **********************************************************************************************************************
 *  @File Name       : kfstdlib.h
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
 *  |2023-04-15   |V1.0     |Zhang quanzhen     |New create
 *  |2023-05-29   |V2.0     |Zhai Yu     |Refactor
 **********************************************************************************************************************/
#ifndef KFSTDLIB_H
#define KFSTDLIB_H

/**********************************************************************************************************************
 *                                               QAC Warnings
 **********************************************************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/**********************************************************************************************************************
 *                                               Include Files                                                        *
 **********************************************************************************************************************/
#include <stdint.h>
#include "kf_types.h"
#include "kfstdlib_cfg.h"
/**********************************************************************************************************************
 * CONFIGURATION CHECK
 **********************************************************************************************************************/

#ifndef KFSTDLIB_USE_LIBRARY_FUNCTIONS
#error "KFSTDLIB_USE_LIBRARY_FUNCTIONS has to be defined.. check KFStdLib_Cfg.h!"
#endif

#ifndef KFSTDLIB_RUNTIME_OPTIMIZATION
#error "KFSTDLIB_RUNTIME_OPTIMIZATION has to be defined.. check KFStdLib_Cfg.h!"
#endif

#ifndef KFSTDLIB_USE_JUMPTABLES
#error "KFSTDLIB_USE_JUMPTABLES has to be defined.. check KFStdLib_Cfg.h!"
#endif

#ifndef KF_DRV_STDLIB_ASSERT
#error "KF_DRV_STDLIB_ASSERT has to be defined.. check KFStdLib_Cfg.h!"
#endif

#ifndef KFSTDLIB_DUMMY_STATEMENT
#error "KFSTDLIB_DUMMY_STATEMENT has to be defined.. check KFStdLib_Cfg.h!"
#endif

/* Large data support */
#ifndef KFSTDLIB_SUPPORT_LARGE_DATA
#define KFSTDLIB_SUPPORT_LARGE_DATA STD_ON
#endif

#if (KFSTDLIB_USE_LIBRARY_FUNCTIONS == STD_OFF)
#if ((KFSTDLIB_SUPPORT_LARGE_DATA == STD_OFF) && (KFSTDLIB_RUNTIME_OPTIMIZATION == STD_ON))
#error "KFSTDLIB_RUNTIME_OPTIMIZATION must not be enabled if large data support is not given!"
#endif
#endif

/**********************************************************************************************************************
 *                                               Global Constant Macros
 *********************************************************************************************************************/
/* API service IDs */
#define KFSTDLIB_SID_MEM_SET          (0x00U)
#define KFSTDLIB_SID_MEM_COPY         (0x01U)
#define KFSTDLIB_SID_MEM_COPY_16      (0x02U)
#define KFSTDLIB_SID_MEM_COPY_32      (0x03U)
#define KFSTDLIB_SID_MEM_COPY_S       (0x04U)
#define KFSTDLIB_SID_GET_VERSION_INFO (0x05U)

/* Error codes */
#define KFSTDLIB_E_NO_ERROR      (0x00U)
#define KFSTDLIB_E_PARAM_POINTER (0x01U)
#define KFSTDLIB_E_PARAM_SIZE    (0x02U)

/**********************************************************************************************************************
 *                                          Global Data Types
 **********************************************************************************************************************/
#if (KFSTDLIB_SUPPORT_LARGE_DATA == STD_ON)
typedef uint32_t kfStdLib_LengthType;
#else
typedef uint16_t kfStdLib_LengthType;
#endif

/**********************************************************************************************************************
 *                                         Global Function Macros (Macro Api)
 *********************************************************************************************************************/
#if (KFSTDLIB_USE_LIBRARY_FUNCTIONS == STD_OFF)

#define KFStdLib_MemClr(DstPtr, Length) kfStdLib_MemSet((DstPtr), 0, (Length))

#endif

#if (KFSTDLIB_SUPPORT_LARGE_DATA == STD_ON)

#define KFStdLib_MemClrLarge(DstPtr, Length) KFStdLib_MemClr((DstPtr), (Length))

#define kfStdLib_MemSetLarge(DstPtr, SrcPtr, Length) kfStdLib_MemSet((DstPtr), (SrcPtr), (Length))

#define kfStdLib_MemCpyLarge(DstPtr, SrcPtr, Length) kfStdLib_MemCopy((DstPtr), (SrcPtr), (Length))

#define kfStdLib_MemCpy16Large(Dst16Ptr, Src16Ptr, Length) kfStdLib_MemCopy16((Dst16Ptr), (Src16Ptr), (Length))

#define kfStdLib_MemCpy32Large(Dst32Ptr, Src32Ptr, Length) kfStdLib_MemCopy32((Dst32Ptr), (Src32Ptr), (Length))

#define kfStdLib_MemCpyLarge_s(DstPtr, DstSize, SrcPtr, Length)                                                        \
    kfStdLib_MemCopy_s((DstPtr), (DstSize), (SrcPtr), (Length))

#endif

#ifndef KFStdLib_MemClrMacro

#define KFStdLib_MemClrMacro(DstPtr, Length)                                                                           \
    do                                                                                                                 \
    {                                                                                                                  \
        kfStdLib_LengthType __i;                                                                                       \
        for (__i = 0U; __i < (Length); ++__i)                                                                          \
        {                                                                                                              \
            (DstPtr)[__i] = 0U;                                                                                        \
        }                                                                                                              \
    } while (0U)
#endif

#ifndef kfStdLib_MemSetMacro

#define kfStdLib_MemSetMacro(DstPtr, SrcPtr, Length)                                                                   \
    do                                                                                                                 \
    {                                                                                                                  \
        kfStdLib_LengthType __i;                                                                                       \
        for (__i = 0U; __i < (Length); ++__i)                                                                          \
        {                                                                                                              \
            (DstPtr)[__i] = (SrcPtr);                                                                                  \
        }                                                                                                              \
    } while (0U)
#endif

#ifndef kfStdLib_MemCpyMacro

#define kfStdLib_MemCpyMacro(DstPtr, SrcPtr, Length)                                                                   \
    do                                                                                                                 \
    {                                                                                                                  \
        kfStdLib_LengthType __i;                                                                                       \
        for (__i = 0U; __i < (Length); ++__i)                                                                          \
        {                                                                                                              \
            (DstPtr)[__i] = (SrcPtr)[__i];                                                                             \
        }                                                                                                              \
    } while (0U)
#endif

#ifndef kfStdLib_MemCpyMacro_s

#define kfStdLib_MemCpyMacro_s(DstPtr, nDstSize, SrcPtr, Length)                                                       \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((nDstSize) >= (Length))                                                                                    \
        {                                                                                                              \
            kfStdLib_MemCpyMacro((DstPtr), (SrcPtr), (Length));                                                        \
        }                                                                                                              \
    } while (0U)
#endif

/**********************************************************************************************************************
 **                        Export Functions
 **********************************************************************************************************************/
#if (KFSTDLIB_USE_LIBRARY_FUNCTIONS == STD_OFF)
void kfStdLib_MemSet(void *DstPtr, uint8_t U8Src, kfStdLib_LengthType Length);

void kfStdLib_MemCopy(void *DstPtr, void *SrcPtr, kfStdLib_LengthType Length);

void kfStdLib_MemCopy16(uint16_t *Dst16Ptr, const uint16_t *const Src16Ptr, kfStdLib_LengthType Length);

void kfStdLib_MemCopy32(uint32_t *Dst32Ptr, const uint32_t *const Src32Ptr, kfStdLib_LengthType Length);

#endif

void kfStdLib_MemCopy_s(void *DstPtr, kfStdLib_LengthType DstSize, void *SrcPtr, kfStdLib_LengthType Length);

/**********************************************************************************************************************
 **                        API Macros
 **********************************************************************************************************************/
#ifndef kfStdLib_MemCpyRom
#define kfStdLib_MemCpyRom(d, s, c) kfStdLib_MemCopy((d), (s), (c))
#endif

#define KFStdMemClr(d, c)        KFStdLib_MemClr((d), (c))
#define KFStdMemNearClr(d, c)    KFStdLib_MemClr((d), (c))
#define KFStdMemFarClr(d, c)     KFStdLib_MemClr((d), (c))
#define KFStdMemSet(d, p, c)     kfStdLib_MemSet((d), (p), (c))
#define KFStdMemNearSet(d, p, c) kfStdLib_MemSet((d), (p), (c))
#define KFStdMemFarSet(d, p, c)  kfStdLib_MemSet((d), (p), (c))

#define KFStdMemCpy(d, s, c)               kfStdLib_MemCopy((d), (s), (c))
#define KFStdMemCpyRom(d, s, c)            kfStdLib_MemCpyRom((d), (s), (c))
#define KFStdMemCpyRamToRam(d, s, c)       kfStdLib_MemCopy((d), (s), (c))
#define KFStdMemCpyRomToRam(d, s, c)       kfStdLib_MemCpyRom((d), (s), (c))
#define KFStdMemCpyRamToNearRam(d, s, c)   kfStdLib_MemCopy((d), (s), (c))
#define KFStdMemCpyRomToNearRam(d, s, c)   kfStdLib_MemCpyRom((d), (s), (c))
#define KFStdMemCpyRamToFarRam(d, s, c)    kfStdLib_MemCopy((d), (s), (c))
#define KFStdMemCpyRomToFarRam(d, s, c)    kfStdLib_MemCpyRom((d), (s), (c))
#define KFStdMemCpyFarRamToRam(d, s, c)    kfStdLib_MemCopy((d), (s), (c))
#define KFStdMemCpyFarRamToFarRam(d, s, c) kfStdLib_MemCopy((d), (s), (c))
#define KFStdMemCpyFarRomToFarRam(d, s, c) kfStdLib_MemCpyRom((d), (s), (c))
#define KFStdRamMemCpy(d, s, c)            kfStdLib_MemCopy((d), (s), (c))
#define KFStdRomMemCpy(d, s, c)            kfStdLib_MemCpyRom((d), (s), (c))

#define KFStdMemCpy16(d, s, c)             kfStdLib_MemCopy16((d), (s), (c))
#define KFStdMemCpy16RamToRam(d, s, c)     kfStdLib_MemCopy16((d), (s), (c))
#define KFStdMemCpy16RamToNearRam(d, s, c) kfStdLib_MemCopy16((d), (s), (c))
#define KFStdMemCpy16NearRamToRam(d, s, c) kfStdLib_MemCopy16((d), (s), (c))
#define KFStdMemCpy16RamToFarRam(d, s, c)  kfStdLib_MemCopy16((d), (s), (c))
#define KFStdMemCpy16FarRamToRam(d, s, c)  kfStdLib_MemCopy16((d), (s), (c))
#define KFStdRamMemCpy16(d, s, c)          kfStdLib_MemCopy16((d), (s), (c))

#define KFStdMemCpy32(d, s, c)             kfStdLib_MemCopy32((d), (s), (c))
#define KFStdMemCpy32RamToRam(d, s, c)     kfStdLib_MemCopy32((d), (s), (c))
#define KFStdMemCpy32RamToNearRam(d, s, c) kfStdLib_MemCopy32((d), (s), (c))
#define KFStdMemCpy32NearRamToRam(d, s, c) kfStdLib_MemCopy32((d), (s), (c))
#define KFStdMemCpy32RamToFarRam(d, s, c)  kfStdLib_MemCopy32((d), (s), (c))
#define KFStdMemCpy32FarRamToRam(d, s, c)  kfStdLib_MemCopy32((d), (s), (c))
#define KFStdRamMemCpy32(d, s, c)          kfStdLib_MemCopy32((d), (s), (c))

#ifndef kfStdLib_MemCpyRomMacro
#define kfStdLib_MemCpyRomMacro(d, s, c) kfStdLib_MemCpyMacro((d), (s), (c))
#endif

#define KFStdMemClr_Macro(d, c)       KFStdLib_MemClrMacro((d), (c))
#define KFStdMemSet_Macro(d, p, c)    kfStdLib_MemSetMacro((d), (p), (c))
#define KFStdMemCpy_Macro(d, s, c)    kfStdLib_MemCpyMacro((d), (s), (c))
#define KFStdMemCpyRom_Macro(d, s, c) kfStdLib_MemCpyRomMacro((d), (s), (c))

#endif

/* EOF */
