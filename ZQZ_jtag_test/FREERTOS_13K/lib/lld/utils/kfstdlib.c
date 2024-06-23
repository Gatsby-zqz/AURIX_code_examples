/**********************************************************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 **********************************************************************************************************************
 *  @File Name       : kfstdlib.c
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

/**********************************************************************************************************************
 *                                               QAC Warnings
 **********************************************************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 3673 EOF # Keep Register Address Pointer as it is. */

/**********************************************************************************************************************
 *                                               Include Files                                                        *
 **********************************************************************************************************************/
#include "kfstdlib.h"

#ifdef KF_DRV_STDLIB_ASSERT
#include "dev_assert.h"
#define KF_STDLIB_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_STDLIB_ASSERT(x) ((void)0U)
#endif
/**********************************************************************************************************************
 *                                          File Version Check                                               *
 **********************************************************************************************************************/

/**********************************************************************************************************************
 **                        Macro  Definitions
 **********************************************************************************************************************/
/* Used to mask internal parameters to ensure an upper limit of 3, respectively 31 */
#define KFSTDLIB_MASK_3  (0x03U)
#define KFSTDLIB_MASK_31 (0x1FU)

/* Return the number of bytes that are missing to the next 32-bit boundary */
#define KFSTDLIB_ALIGN_OFFSET(ptr) (uint32_t)(((uint32_t)(ptr)-4U) & KFSTDLIB_MASK_3)

/**********************************************************************************************************************
 *                                          Local Function Declarations                                               *
 **********************************************************************************************************************/
#if (KFSTDLIB_USE_LIBRARY_FUNCTIONS == STD_OFF)
#if (KFSTDLIB_RUNTIME_OPTIMIZATION == STD_ON)

/**
 * @brief Initializes up to 3 bytes at DstPtr to the character U8Src (any alignment)
 *
 * @param Dst8Ptr
 * @param U8Src
 * @param Length
 * @return void
 */
KF_FORCE_INLINE void kfStdLib_MemSet_8bits_3bytes(uint8_t *const Dst8Ptr, uint8_t U8Src, uint32_t Length)
{
#if (KFSTDLIB_USE_JUMPTABLES == STD_ON)
    /*  Initialize up to 3 bytes using a jump table */
    switch (Length)
    {
    case 3U:
        Dst8Ptr[2] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 2U:
        Dst8Ptr[1] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 1U:
        Dst8Ptr[0] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    default: /* PRQA S 2014 1 # intentionally empty default clause */
        break;
    }
#else
    uint32_t RemainLength;
    /*  Linearly initialize the bytes using a loop */
    for (RemainLength = 0; RemainLength < Length; RemainLength++)
    {
        Dst8Ptr[RemainLength] = U8Src;
    }
#endif
}

/**
 * @brief:Initializes up to 31 bytes at DstPtr to the character U8Src(any alignment)
 * @param in:[Dst8Ptr][U8Src][Length]
 * @param out:None
 * @retval:None
 */
KF_FORCE_INLINE void kfStdLib_MemSet_8bits_31bytes(uint8_t *const Dst8Ptr, uint8_t U8Src, uint32_t Length)
{
#if (KFSTDLIB_USE_JUMPTABLES == STD_ON)
    /*  Initialize up to 31 bytes using a jump table */
    switch (Length)
    {
    case 31U:
        Dst8Ptr[30] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 30U:
        Dst8Ptr[29] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 29U:
        Dst8Ptr[28] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 28U:
        Dst8Ptr[27] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 27U:
        Dst8Ptr[26] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 26U:
        Dst8Ptr[25] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 25U:
        Dst8Ptr[24] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 24U:
        Dst8Ptr[23] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 23U:
        Dst8Ptr[22] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 22U:
        Dst8Ptr[21] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 21U:
        Dst8Ptr[20] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 20U:
        Dst8Ptr[19] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 19U:
        Dst8Ptr[18] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 18U:
        Dst8Ptr[17] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 17U:
        Dst8Ptr[16] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 16U:
        Dst8Ptr[15] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 15U:
        Dst8Ptr[14] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 14U:
        Dst8Ptr[13] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 13U:
        Dst8Ptr[12] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 12U:
        Dst8Ptr[11] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 11U:
        Dst8Ptr[10] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 10U:
        Dst8Ptr[9] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 9U:
        Dst8Ptr[8] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 8U:
        Dst8Ptr[7] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 7U:
        Dst8Ptr[6] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 6U:
        Dst8Ptr[5] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 5U:
        Dst8Ptr[4] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 4U:
        Dst8Ptr[3] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 3U:
        Dst8Ptr[2] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 2U:
        Dst8Ptr[1] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    case 1U:
        Dst8Ptr[0] = U8Src;
        /* PRQA S 2003 1 # intentionally no break */
    default: /* PRQA S 2014 1 # intentionally empty default clause */
        break;
    }
#else
    uint32_t RemainLength;
    /*  Linearly initialize the bytes using a loop */
    for (RemainLength = 0; RemainLength < Length; RemainLength++)
    {
        Dst8Ptr[RemainLength] = U8Src;
    }
#endif
}

/**
 * @brief:Initializes memory at DstPtr to the character nSrc (32-bit aligned)
 * @param in:[Dst32Ptr][U8Src][Length]
 * @param out:None
 * @retval:None
 */

/**
 * @brief Initializes memory at DstPtr to the character nSrc (32-bit aligned)
 *
 * @param Dst32Ptr
 * @param U8Src
 * @param Length
 * @return void
 */
KF_FORCE_INLINE void kfStdLib_MemSet_32bitsAligned(uint32_t *Dst32Ptr, const uint8_t U8Src, const uint32_t Length)
{
    uint32_t u32Pos       = 0U;
    uint32_t RemainLength = 0U;
    uint32_t u32Src = (uint32_t)(((uint32_t)U8Src << 24U) | ((uint32_t)U8Src << 16U) | ((uint32_t)U8Src << 8U) | U8Src);
    /* Linearly initialize 16-byte blocks using 32-bit accesses in a loop */
    /* PRQA S 3544 3 # Possible: Using a tainted variable in a loop control expression */
    for (RemainLength = Length; RemainLength >= 16U; RemainLength -= 16U)
    {
        /* PRQA S 2985 1 # This redundant is to improve readability */
        Dst32Ptr[u32Pos + 0U] = u32Src;
        Dst32Ptr[u32Pos + 1U] = u32Src;
        Dst32Ptr[u32Pos + 2U] = u32Src;
        Dst32Ptr[u32Pos + 3U] = u32Src;
        u32Pos += 4U;
    }
#if (KFSTDLIB_USE_JUMPTABLES == STD_ON)
    /*  Initialize the RemainLength block using a jump table */
    switch (RemainLength)
    {
    case 15U:
    case 14U:
    case 13U:
    case 12U:
        Dst32Ptr[u32Pos] = u32Src;
        u32Pos++;
        /* PRQA S 2003 1 # intentionally no break */
    case 11U:
    case 10U:
    case 9U:
    case 8U:
        Dst32Ptr[u32Pos] = u32Src;
        u32Pos++;
        /* PRQA S 2003 1 # intentionally no break */
    case 7U:
    case 6U:
    case 5U:
    case 4U:
        Dst32Ptr[u32Pos] = u32Src;
        u32Pos++;
        /* PRQA S 2003 1 # intentionally no break */
    case 3U:
    case 2U:
    case 1U:
        /* PRQA S 0751 3 # Casting to char pointer type.*/
        kfStdLib_MemSet_8bits_3bytes((uint8_t *)&Dst32Ptr[u32Pos], U8Src, (uint32_t)(RemainLength & KFSTDLIB_MASK_3));
        /* PRQA S 2003 1 # intentionally no break */
    default: /* PRQA S 2014 1 # intentionally empty default clause */
        break;
    }
#else
    /*  Initialize the RemainLength block using a byte-wise algorithm */
    kfStdLib_MemSet_8bits_31bytes((uint8_t *)&Dst32Ptr[u32Pos], U8Src, (uint32_t)(RemainLength & KFSTDLIB_MASK_31));
#endif
}

/**
 * @brief Copies up to 3 bytes from SrcPtr to DstPtr (any alignment).
 *
 * @param Dst8Ptr
 * @param Src8Ptr
 * @param Length
 * @return void
 */
KF_FORCE_INLINE void
kfStdLib_MemCopy_8bits_3bytes(uint8_t *Dst8Ptr, const uint8_t *const Src8Ptr, const uint32_t Length)
{
#if (KFSTDLIB_USE_JUMPTABLES == STD_ON)
    /*  Copy up to 3 bytes using a jump table */
    switch (Length)
    {
    case 3U:
        Dst8Ptr[2] = Src8Ptr[2];
        /* PRQA S 2003 1 # intentionally no break */
    case 2U:
        Dst8Ptr[1] = Src8Ptr[1];
        /* PRQA S 2003 1 # intentionally no break */
    case 1U:
        Dst8Ptr[0] = Src8Ptr[0];
        /* PRQA S 2003 1 # intentionally no break */
    default: /* PRQA S 2014 1 # intentionally empty default clause */
        break;
    }
#else
    uint32_t RemainLength = 0U;
    /*  Linearly copy the bytes using a loop */
    for (RemainLength = 0U; RemainLength < Length; RemainLength++)
    {
        Dst8Ptr[RemainLength] = Src8Ptr[RemainLength];
    }
#endif
}

/**
 * @brief Copies up to 31 bytes from SrcPtr to DstPtr (any alignment).
 *
 * @param Dst8Ptr
 * @param Src8Ptr
 * @param Length
 * @return void
 */
KF_FORCE_INLINE void
kfStdLib_MemCopy_8bits_31bytes(uint8_t *Dst8Ptr, const uint8_t *const Src8Ptr, const uint32_t Length)
{
#if (KFSTDLIB_USE_JUMPTABLES == STD_ON)
    /*  Copy up to 31 bytes using a jump table */
    switch (Length)
    {
    case 31U:
        Dst8Ptr[30] = Src8Ptr[30];
        /* PRQA S 2003 1 # intentionally no break */
    case 30U:
        Dst8Ptr[29] = Src8Ptr[29];
        /* PRQA S 2003 1 # intentionally no break */
    case 29U:
        Dst8Ptr[28] = Src8Ptr[28];
        /* PRQA S 2003 1 # intentionally no break */
    case 28U:
        Dst8Ptr[27] = Src8Ptr[27];
        /* PRQA S 2003 1 # intentionally no break */
    case 27U:
        Dst8Ptr[26] = Src8Ptr[26];
        /* PRQA S 2003 1 # intentionally no break */
    case 26U:
        Dst8Ptr[25] = Src8Ptr[25];
        /* PRQA S 2003 1 # intentionally no break */
    case 25U:
        Dst8Ptr[24] = Src8Ptr[24];
        /* PRQA S 2003 1 # intentionally no break */
    case 24U:
        Dst8Ptr[23] = Src8Ptr[23];
        /* PRQA S 2003 1 # intentionally no break */
    case 23U:
        Dst8Ptr[22] = Src8Ptr[22];
        /* PRQA S 2003 1 # intentionally no break */
    case 22U:
        Dst8Ptr[21] = Src8Ptr[21];
        /* PRQA S 2003 1 # intentionally no break */
    case 21U:
        Dst8Ptr[20] = Src8Ptr[20];
        /* PRQA S 2003 1 # intentionally no break */
    case 20U:
        Dst8Ptr[19] = Src8Ptr[19];
        /* PRQA S 2003 1 # intentionally no break */
    case 19U:
        Dst8Ptr[18] = Src8Ptr[18];
        /* PRQA S 2003 1 # intentionally no break */
    case 18U:
        Dst8Ptr[17] = Src8Ptr[17];
        /* PRQA S 2003 1 # intentionally no break */
    case 17U:
        Dst8Ptr[16] = Src8Ptr[16];
        /* PRQA S 2003 1 # intentionally no break */
    case 16U:
        Dst8Ptr[15] = Src8Ptr[15];
        /* PRQA S 2003 1 # intentionally no break */
    case 15U:
        Dst8Ptr[14] = Src8Ptr[14];
        /* PRQA S 2003 1 # intentionally no break */
    case 14U:
        Dst8Ptr[13] = Src8Ptr[13];
        /* PRQA S 2003 1 # intentionally no break */
    case 13U:
        Dst8Ptr[12] = Src8Ptr[12];
        /* PRQA S 2003 1 # intentionally no break */
    case 12U:
        Dst8Ptr[11] = Src8Ptr[11];
        /* PRQA S 2003 1 # intentionally no break */
    case 11U:
        Dst8Ptr[10] = Src8Ptr[10];
        /* PRQA S 2003 1 # intentionally no break */
    case 10U:
        Dst8Ptr[9] = Src8Ptr[9];
        /* PRQA S 2003 1 # intentionally no break */
    case 9U:
        Dst8Ptr[8] = Src8Ptr[8];
        /* PRQA S 2003 1 # intentionally no break */
    case 8U:
        Dst8Ptr[7] = Src8Ptr[7];
        /* PRQA S 2003 1 # intentionally no break */
    case 7U:
        Dst8Ptr[6] = Src8Ptr[6];
        /* PRQA S 2003 1 # intentionally no break */
    case 6U:
        Dst8Ptr[5] = Src8Ptr[5];
        /* PRQA S 2003 1 # intentionally no break */
    case 5U:
        Dst8Ptr[4] = Src8Ptr[4];
        /* PRQA S 2003 1 # intentionally no break */
    case 4U:
        Dst8Ptr[3] = Src8Ptr[3];
        /* PRQA S 2003 1 # intentionally no break */
    case 3U:
        Dst8Ptr[2] = Src8Ptr[2];
        /* PRQA S 2003 1 # intentionally no break */
    case 2U:
        Dst8Ptr[1] = Src8Ptr[1];
        /* PRQA S 2003 1 # intentionally no break */
    case 1U:
        Dst8Ptr[0] = Src8Ptr[0];
        /* PRQA S 2003 1 # intentionally no break */
    default: /* PRQA S 2014 1 # intentionally empty default clause */
        break;
    }
#else
    uint32_t RemainLength = 0U;
    /*  Linearly copy the bytes using a loop */
    for (RemainLength = 0; RemainLength < Length; RemainLength++)
    {
        Dst8Ptr[RemainLength] = Src8Ptr[RemainLength];
    }
#endif
}

/**
 * @brief Copies 32-bit aligned data from SrcPtr to DstPtr.
 *
 * @param Dst32Ptr
 * @param Src32Ptr
 * @param Length
 * @return void
 */
KF_FORCE_INLINE void
kfStdLib_MemCopy_32bitsAligned(uint32_t *Dst32Ptr, const uint32_t *const Src32Ptr, const uint32_t Length)
{
    uint32_t Pos          = 0U;
    uint32_t RemainLength = 0U;
    /*  Linearly copy 16-byte blocks using 32-bit accesses in a loop */
    /* PRQA S 3544 3 # Possible: Using a tainted variable in a loop control expression */
    for (RemainLength = Length; RemainLength >= 16U; RemainLength -= 16U)
    {
        /* PRQA S 2985 1 # This redundant is to improve readability */
        Dst32Ptr[Pos + 0U] = Src32Ptr[Pos + 0U];
        Dst32Ptr[Pos + 1U] = Src32Ptr[Pos + 1U];
        Dst32Ptr[Pos + 2U] = Src32Ptr[Pos + 2U];
        Dst32Ptr[Pos + 3U] = Src32Ptr[Pos + 3U];
        Pos += 4U;
    }
#if (KFSTDLIB_USE_JUMPTABLES == STD_ON)
    /*  Copy the RemainLength block using a jump table */
    switch (RemainLength)
    {
    case 15U:
    case 14U:
    case 13U:
    case 12U:
        Dst32Ptr[Pos] = Src32Ptr[Pos];
        Pos++;
        /* PRQA S 2003 1 # intentionally no break */
    case 11U:
    case 10U:
    case 9U:
    case 8U:
        Dst32Ptr[Pos] = Src32Ptr[Pos];
        Pos++;
        /* PRQA S 2003 1 # intentionally no break */
    case 7U:
    case 6U:
    case 5U:
    case 4U:
        Dst32Ptr[Pos] = Src32Ptr[Pos];
        Pos++;
        /* PRQA S 2003 1 # intentionally no break */
    case 3U:
    case 2U:
    case 1U:
        /* PRQA S 0751 3 # Casting to char pointer type.*/
        kfStdLib_MemCopy_8bits_3bytes(
          (uint8_t *)&Dst32Ptr[Pos], (const uint8_t *)&Src32Ptr[Pos], (uint32_t)(RemainLength & KFSTDLIB_MASK_3));
        /* PRQA S 2003 1 # intentionally no break */
    default: /* PRQA S 2014 1 # intentionally empty default clause */
        break;
    }
#else
    /*  Copy the RemainLength block using a byte-wise algorithm */
    kfStdLib_MemCopy_8bits_31bytes(
      (uint8_t *)&Dst32Ptr[Pos], (const uint8_t *)&Src32Ptr[Pos], (uint32_t)(RemainLength & KFSTDLIB_MASK_31));

#endif
}

/**
 * @brief Copies a partial word of 1 to 3 bytes from SrcPtr to DstPtr to reach a 32-bit boundary (any alignment).
 *
 *
 * @param Dst8Ptr
 * @param Src32Ptr
 * @param Length
 * @param Pos
 * @return void
 */
KF_FORCE_INLINE void kfStdLib_MemCopy_8bits_PartialWord(
  uint8_t *Dst8Ptr, uint32_t *const Src32Ptr, const uint32_t Length, uint32_t *const Pos)
{
#if (KFSTDLIB_USE_JUMPTABLES == STD_ON)
    /* Copy 1 to 3 bytes using a jump table and adapt '*Pos' and '*Src32Ptr' for little endian byte order */
    switch (Length)
    {
    case 3U:
        Dst8Ptr[*Pos] = (uint8_t)*Src32Ptr;
        (*Pos)++;
        (*Src32Ptr) >>= 8U;
        /* PRQA S 2003 1 # intentionally no break */
    case 2U:
        Dst8Ptr[*Pos] = (uint8_t)*Src32Ptr;
        (*Pos)++;
        (*Src32Ptr) >>= 8U;
        /* PRQA S 2003 1 # intentionally no break */
    default: /* case 1 - Length is always in range [1..3] */
        Dst8Ptr[*Pos] = (uint8_t)*Src32Ptr;
        (*Pos)++;
        (*Src32Ptr) >>= 8U;
        break;
    }
#else
    uint32_t RemainLength = 0U;
    /*  Linearly copy the bytes using a loop and adapt '*Pos' and '*Src32Ptr' for little endian byte order */
    for (RemainLength = 0U; RemainLength < Length; RemainLength++)
    {
        Dst8Ptr[*Pos] = (uint8_t)(uint8_t)*Src32Ptr;
        (*Pos)++;
        (*Src32Ptr) >>= 8U;
    }
#endif
}

/**
 * @brief Copies data from 32-bit aligned SrcPtr to unaligned DstPtr.
 *
 * @param Dst8Ptr
 * @param Src32Ptr
 * @param Length
 * @param DstOffset
 * @return void
 */
KF_FORCE_INLINE void kfStdLib_MemCopy32Unaligned(
  uint8_t *Dst8Ptr, const uint32_t *const Src32Ptr, const uint32_t Length, const uint32_t DstOffset)
{
    uint32_t Pos          = 0U;
    uint32_t SrcPos       = 0U;
    uint32_t RemainLength = Length;
    /*  If more than 32 bytes have to be copied */
    if (RemainLength >= 32U)
    {
        uint32_t  u32Prev = 0U;
        uint32_t *Dst32Ptr;
        /*  Copy the first partial word to reach the 32-bit boundary and adjust the destination pointer */
        u32Prev = Src32Ptr[SrcPos];
        RemainLength -= 4U;
        kfStdLib_MemCopy_8bits_PartialWord(Dst8Ptr, &u32Prev, DstOffset, &Pos);
        /* At this point 'Dst8Ptr[Pos]' is aligned to a 32-bit boundary */
        /* PRQA S 0310 4 # Casting to different object pointer type. */
        /* PRQA S 3305 2 # Pointer cast to stricter alignment. */
        Dst32Ptr = (uint32_t *)&Dst8Ptr[Pos];
        Pos      = 0U;
        SrcPos   = 1U;
        /*  Linearly copy 16-byte blocks using 32-bit accesses by correcting the byte displacement of dst and src */
        if (DstOffset == 3U) /* 24-bit displacement */
        {
            for (; RemainLength >= 16U; RemainLength -= 16U)
            {
                uint32_t x0, x1, x2, x3, x4;
                /* PRQA S 2985 1 # This redundant is to improve readability */
                x1 = Src32Ptr[SrcPos + 0U];
                x2 = Src32Ptr[SrcPos + 1U];
                x3 = Src32Ptr[SrcPos + 2U];
                x4 = Src32Ptr[SrcPos + 3U];

                x0      = u32Prev | (x1 << 8U);
                x1      = (x1 >> 24U) | (x2 << 8U);
                x2      = (x2 >> 24U) | (x3 << 8U);
                x3      = (x3 >> 24U) | (x4 << 8U);
                u32Prev = x4 >> 24U;

                /* PRQA S 2985 1 # This redundant is to improve readability */
                Dst32Ptr[Pos + 0U] = x0;
                Dst32Ptr[Pos + 1U] = x1;
                Dst32Ptr[Pos + 2U] = x2;
                Dst32Ptr[Pos + 3U] = x3;
                Pos += 4U;
                SrcPos += 4U;
            }
        }
        else if (DstOffset == 2U) /* 16-bit displacement */
        {
            for (; RemainLength >= 16U; RemainLength -= 16U)
            {
                uint32_t x0, x1, x2, x3, x4;
                /* PRQA S 2985 1 # This redundant is to improve readability */
                x1 = Src32Ptr[SrcPos + 0U];
                x2 = Src32Ptr[SrcPos + 1U];
                x3 = Src32Ptr[SrcPos + 2U];
                x4 = Src32Ptr[SrcPos + 3U];

                x0      = u32Prev | (x1 << 16U);
                x1      = (x1 >> 16U) | (x2 << 16U);
                x2      = (x2 >> 16U) | (x3 << 16U);
                x3      = (x3 >> 16U) | (x4 << 16U);
                u32Prev = x4 >> 16U;

                /* PRQA S 2985 1 # This redundant is to improve readability */
                Dst32Ptr[Pos + 0U] = x0;
                Dst32Ptr[Pos + 1U] = x1;
                Dst32Ptr[Pos + 2U] = x2;
                Dst32Ptr[Pos + 3U] = x3;
                Pos += 4U;
                SrcPos += 4U;
            }
        }
        else /* DstOffset == 1 - 8-bit displacement */
        {
            for (; RemainLength >= 16U; RemainLength -= 16U)
            {
                uint32_t x0, x1, x2, x3, x4;
                /* PRQA S 2985 1 # This redundant is to improve readability */
                x1 = Src32Ptr[SrcPos + 0U];
                x2 = Src32Ptr[SrcPos + 1U];
                x3 = Src32Ptr[SrcPos + 2U];
                x4 = Src32Ptr[SrcPos + 3U];

                x0      = u32Prev | (x1 << 24U);
                x1      = (x1 >> 8U) | (x2 << 24U);
                x2      = (x2 >> 8U) | (x3 << 24U);
                x3      = (x3 >> 8U) | (x4 << 24U);
                u32Prev = x4 >> 8U;

                /* PRQA S 2985 1 # This redundant is to improve readability */
                Dst32Ptr[Pos + 0U] = x0;
                Dst32Ptr[Pos + 1U] = x1;
                Dst32Ptr[Pos + 2U] = x2;
                Dst32Ptr[Pos + 3U] = x3;
                Pos += 4U;
                SrcPos += 4U;
            }
        }
        /*  Linearly copy the RemainLength words using a loop */
        {
            uint32_t prevShift = (DstOffset << 3U) & KFSTDLIB_MASK_31;
            uint32_t xShift    = 32U - prevShift;
            /* At this point RemainLength is < 16 byte */
            for (; RemainLength >= 4U; RemainLength -= 4U)
            {
                uint32_t x0, x1;
                x1            = Src32Ptr[SrcPos];
                x0            = u32Prev | (x1 << xShift);
                u32Prev       = x1 >> prevShift;
                Dst32Ptr[Pos] = x0;
                Pos++;
                SrcPos++;
            }
        }
        /* Copy the RemainLength partial word using a byte-wise algorithm */
        /* PRQA S 1338,0751 3 # The parameter '%1s' is being modified. */
        Dst8Ptr = (uint8_t *)&Dst32Ptr[Pos];
        Pos     = 0U;
        kfStdLib_MemCopy_8bits_PartialWord(Dst8Ptr, &u32Prev, (4U - DstOffset), &Pos);
    }
    else
    {
        /* deliberately left blank to avoid QAC violation * (Rule 2000 ) */
    }
    /* Copy the RemainLength bytes using a byte-wise algorithm */
    /* PRQA S 0751 3 # Casting to char pointer type.*/
    kfStdLib_MemCopy_8bits_31bytes(&Dst8Ptr[Pos], (const uint8_t *)&Src32Ptr[SrcPos], (uint32_t)RemainLength);
}
#endif

/**********************************************************************************************************************
 *                                          Global Function Definition                                               *
 **********************************************************************************************************************/

/**
 * @brief Initializes memory to a specified pattern.
 *
 * @param DstPtr
 * @param U8Src
 * @param Length
 */
void kfStdLib_MemSet(void *DstPtr, uint8_t U8Src, kfStdLib_LengthType Length)
{
    KF_STDLIB_ASSERT(DstPtr != NULL_PTR);
    kfStdLib_LengthType RemainLength = Length;
#if (KFSTDLIB_RUNTIME_OPTIMIZATION == STD_ON)
    RemainLength = Length;
    /*  If less than 32 bytes have to be initialized */
    if (RemainLength < 32U)
    {
        /*  Use a byte-wise algorithm */
        /* PRQA S 0316 1 # This cast is ensured for address conversion  */
        kfStdLib_MemSet_8bits_31bytes((uint8_t *)DstPtr, U8Src, (uint32_t)RemainLength);
    }
    else
    {
        /* Get the destination pointer offset to the next 32-bit boundary */
        /* PRQA S 0326 3 # Cast between a pointer to void and an integral type. */
        const uint32_t DstOffset = KFSTDLIB_ALIGN_OFFSET(DstPtr);
        /*  If the destination is not aligned */
        if (DstOffset != 0U)
        {
            /*  Initialize the amount of to reach the boundary on 'DstPtr' and adjust the pointer */
            /* PRQA S 0316 1 # This cast is ensured for address conversion  */
            kfStdLib_MemSet_8bits_3bytes((uint8_t *)DstPtr, U8Src, DstOffset);
            /* PRQA S 1338 2 # The parameter '%1s' is being modified. */
            /* PRQA S 0316 1 # This cast is ensured for address conversion  */
            DstPtr = &((uint8_t *)DstPtr)[DstOffset];
            RemainLength -= DstOffset;
        }
        else
        {
            /* deliberately left blank to avoid QAC violation * (Rule 2000 ) */
        }
        /*  The pointer is aligned, use the 32-bit aligned memset */
        /* PRQA S 0316 1 # This cast is ensured for address conversion  */
        kfStdLib_MemSet_32bitsAligned((uint32_t *)DstPtr, U8Src, RemainLength);
    }
#else
    for (RemainLength = 0; RemainLength < Length; RemainLength++)
    {
        ((uint8_t *)(DstPtr))[RemainLength] = U8Src;
    }
#endif
}

/**
 * @brief Copies data from one memory location to another.
 *
 * @param DstPtr
 * @param SrcPtr
 * @param Length
 */
void kfStdLib_MemCopy(void *DstPtr, void *SrcPtr, kfStdLib_LengthType Length)
{
    KF_STDLIB_ASSERT(DstPtr != NULL_PTR);
    KF_STDLIB_ASSERT(SrcPtr != NULL_PTR);
    kfStdLib_LengthType RemainLength = Length;

#if (KFSTDLIB_RUNTIME_OPTIMIZATION == STD_ON)
    /*  If less than 32 bytes have to be copied */
    if (RemainLength < 32U)
    {
        /*  Use a byte-wise algorithm */
        /* PRQA S 0316 2 # This cast is ensured for address conversion  */
        kfStdLib_MemCopy_8bits_31bytes((uint8_t *)DstPtr, (const uint8_t *)SrcPtr, (uint32_t)RemainLength);
    }
    else
    {
        /* Get the source pointer offset to the next 32-bit boundary */
        /* PRQA S 0326 3 # Cast between a pointer to void and an integral type. */
        uint32_t nSrcOffset = KFSTDLIB_ALIGN_OFFSET(SrcPtr);
        uint32_t DstOffset;
        /*  If the source is not aligned */
        if (nSrcOffset != 0U)
        {
            /*  Copy the amount of bytes to reach the boundary on 'SrcPtr' and adjust the pointers */
            /* PRQA S 0316 1 # This cast is ensured for address conversion  */
            kfStdLib_MemCopy_8bits_3bytes((uint8_t *)DstPtr, (const uint8_t *)SrcPtr, nSrcOffset);
            /* PRQA S 1338 2 # The parameter '%1s' is being modified. */
            /* PRQA S 0316 1 # This cast is ensured for address conversion  */
            SrcPtr = &((uint8_t *)SrcPtr)[nSrcOffset];
            /* PRQA S 1338 2 # The parameter '%1s' is being modified. */
            /* PRQA S 0316 1 # This cast is ensured for address conversion  */
            DstPtr = &((uint8_t *)DstPtr)[nSrcOffset];
            RemainLength -= nSrcOffset;
        }
        else
        {
            /* deliberately left blank to avoid QAC violation * (Rule 2000 ) */
        }
        /* Get the destination pointer offset to the next 32-bit boundary */
        /* PRQA S 0326 3 # Cast between a pointer to void and an integral type. */
        DstOffset = KFSTDLIB_ALIGN_OFFSET(DstPtr);
        /*  If destination is aligned */
        if (DstOffset == 0U)
        {
            /*  Both pointers are aligned, use the 32-bit aligned memcpy */
            /* PRQA S 0316 1 # This cast is ensured for address conversion  */
            kfStdLib_MemCopy_32bitsAligned((uint32_t *)DstPtr, (const uint32_t *)SrcPtr, RemainLength);
        }
        else
        {
            /*  Use the 32-bit unaligned memcpy */
            /* PRQA S 0316 1 # This cast is ensured for address conversion  */
            kfStdLib_MemCopy32Unaligned((uint8_t *)DstPtr, (const uint32_t *)SrcPtr, RemainLength, DstOffset);
        }
    }
#else
    /*  Linearly copy Length bytes using a loop */
    for (RemainLength = 0; RemainLength < Length; RemainLength++)
    {
        ((uint8_t *)(DstPtr))[RemainLength] = ((const uint8_t *)(SrcPtr))[RemainLength];
    }
#endif
}

/**
 * @brief Copies Length 16-bit blocks starting at SrcPtr to another memory location starting at DstPtr.
 *
 * @param Dst16Ptr
 * @param Src16Ptr
 * @param Length
 */
void kfStdLib_MemCopy16(uint16_t *Dst16Ptr, const uint16_t *const Src16Ptr, kfStdLib_LengthType Length)
{
    KF_STDLIB_ASSERT(Dst16Ptr != NULL_PTR);
    KF_STDLIB_ASSERT(Src16Ptr != NULL_PTR);
    kfStdLib_LengthType RemainLength = 0U;

    /* Linearly copy Length 16-bit blocks using a loop */
    /* PRQA S 3544 3 # Possible: Using a tainted variable in a loop control expression */
    for (RemainLength = 0U; RemainLength < Length; RemainLength++)
    {
        (Dst16Ptr)[RemainLength] = (Src16Ptr)[RemainLength];
    }
}

/**
 * @brief Copies Length 32-bit blocks starting at SrcPtr to another memory location starting at DstPtr.
 *
 * @param Dst32Ptr
 * @param Src32Ptr
 * @param Length
 */
void kfStdLib_MemCopy32(uint32_t *Dst32Ptr, const uint32_t *const Src32Ptr, kfStdLib_LengthType Length)
{
    KF_STDLIB_ASSERT(Dst32Ptr != NULL_PTR);
    KF_STDLIB_ASSERT(Src32Ptr != NULL_PTR);
    kfStdLib_LengthType RemainLength = 0U;

    /* Linearly copy Length 32-bit blocks using a loop */
    /* PRQA S 3544 3 # Possible: Using a tainted variable in a loop control expression */
    for (RemainLength = 0U; RemainLength < Length; RemainLength++)
    {
        (Dst32Ptr)[RemainLength] = (Src32Ptr)[RemainLength];
    }
}

#endif

/**
 * @brief Uses kfStdLib_MemCopy() to copy Length bytes starting at SrcPtr to another memory location starting at DstPtr,
 * if DstSize is greater than or equal to Length.
 *
 * @param DstPtr
 * @param DstSize
 * @param SrcPtr
 * @param Length
 */
void kfStdLib_MemCopy_s(void *DstPtr, kfStdLib_LengthType DstSize, void *SrcPtr, kfStdLib_LengthType Length)
{
    if (Length > DstSize)
    {
    }
    else
    {
        /*  Call kfStdLib_MemCopy() */
        kfStdLib_MemCopy(DstPtr, SrcPtr, Length);
    }
}

/* EOF */
