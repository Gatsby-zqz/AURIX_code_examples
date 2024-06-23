//****************************************************************************************
//*
//* File Name: Kfx_Ssw.h
//* Project Name: FreeRTOS_13K
//* Version: v1.0
//* Date: 2024-06-03 14:42:26
//* Author: chipon
//*
//****************************************************************************************/
// #include <KF32DA2218SQVWS.h>

// asm(".include		\"KF32DA2218SQVWS.inc\"	");

#ifndef KFX_SSW_C_
#define KFX_SSW_C_

/******************************************************************************/
/*--------------------------------   Typedefs  -------------------------------*/
/******************************************************************************/

typedef volatile union
{
    unsigned char      *ucPtr;
    unsigned short     *usPtr;
    unsigned int       *uiPtr;
    unsigned long long *ullPtr;
} Kfx_Ssw_CTablePtr;

/**  Structure definition for the BMHD
 * Based on BMI and start address respective CRC and Inverted CRC values has to be calculated and updated.
 * CRC-32 polynomial as defined in the IEEE 802.3 standard is used to generate the CRC value. The CRC algorithm
 * treats input data as a stream of bits.
 *
 * Eg. To calculate the CRC data has to given in big-endian order.
 * for the below values:
 *    bmi    = 0x00FE
 *    bmhdid = 0xB359
 *    stad   = 0xA00A0000
 * CRC calculation:
 *    Input        = 0xB35900FEA00A0000
 *    CRC value    = 0x3CEED0A6
 *    CRC Inverted = 0xC3112F59
 */
typedef struct
{
    unsigned short bmi;           /**<  0x000: Boot Mode Index (BMI)*/
    unsigned short bmhdid;        /**<  0x002: Boot Mode Header ID (CODE) = B359H*/
    unsigned int   stad;          /**<  0x004: User Code start address*/
    unsigned int   crc;           /**<  0x008: Check Result for the BMI Header (offset 000H - 007H)*/
    unsigned int   crcInv;        /**<  0x00C: Inverted Check Result for the BMI Header (offset 000H - 007H)*/
    unsigned int   reserved0[60]; /**<  0x010: Reserved area (60 words) till the offset 0x100*/
    unsigned int   pw[8];         /**<  0x100: Password protection (8 words) till the offset 0x120 */
    unsigned int   reserved1[52]; /**<  0x120: Reserved area (52 words) till the offset 0x1F0*/
    unsigned int   confirmation;  /**<  0x1F0: 32-bit CODE, (always same)*/
} Kfx_Ssw_Bmhd;

/******************************************************************************/

#include "Cpu_Intrinsics.h"
/*******************************************************************************
*******************************************************************************/
extern unsigned int __START0[]; /**< Pointer to the startup code */
extern unsigned int __START1[]; /**< Pointer to the startup code */

extern unsigned int __USTACK0[];     /**< user stack end */
extern unsigned int __ISTACK0[];     /**< interrupt stack end */
extern unsigned int __INTTAB_CPU0[]; /**< Interrupt vector table */

extern unsigned int __USTACK1[];     /**< user stack end */
extern unsigned int __ISTACK1[];     /**< interrupt stack end */
extern unsigned int __INTTAB_CPU1[]; /**< Interrupt vector table */
/*******************************************************************************
*******************************************************************************/
extern unsigned int __clear_table[]; /**< clear table entry */
extern unsigned int __copy_table[];  /**< copy table entry */

/******************************************************************************/
typedef void (*Kfx_Isr)(void);

// section like  .intvec_tc1_213

#define KFX_WEAK_INTERRUPT(isr, vectabNum, prio)                                                                       \
    __attribute__((weak))                                                                                              \
    __attribute__((section(".intvec_tc" #vectabNum "_" #prio))) void __iVecEntry##vectabNum##_##prio(void)             \
    {                                                                                                                  \
        __asm__("SJMP       $");                                                                                       \
    }

#define KFX_INTERRUPT_INTERNAL(isr, vectabNum, prio)                                                                   \
    __attribute__((section(".intvec_tc" #vectabNum "_" #prio))) void __iVecEntry##vectabNum##_##prio(void)             \
    {                                                                                                                  \
        __asm__("PUSH      R5");                                                                                       \
        __asm__("PUSH      LR");                                                                                       \
        __asm__("MOV  R5,  #" #isr "");                                                                                \
        __asm__("LJMP       R5");                                                                                      \
        __asm__("POP       LR");                                                                                       \
        __asm__("POP       R5");                                                                                       \
        __asm__("MRET");                                                                                               \
    }                                                                                                                  \
    __attribute__((section(".text_cpu" #vectabNum))) void isr(void)

#define KFX_INTERRUPT_FLOAT_INTERNAL(isr, vectabNum, prio)                                                             \
    __attribute__((section(".intvec_tc" #vectabNum "_" #prio))) void __iVecEntry##vectabNum##_##prio(void)             \
    {                                                                                                                  \
        __asm__("PUSH      R5");                                                                                       \
        __asm__("FPUSH  S0,{S0-S7}");                                                                                  \
        __asm__("FPUSH  S8,{S8-S15}");                                                                                 \
        __asm__("MOV  R5,  #" #isr "");                                                                                \
        __asm__("ADD       LR, PC, #8");                                                                               \
        __asm__("JMP       R5");                                                                                       \
        __asm__("FPOP  S8,{S8-S15}");                                                                                  \
        __asm__("FPOP  S0,{S0-S8}");                                                                                   \
        __asm__("POP       R5");                                                                                       \
        __asm__("MRET");                                                                                               \
    }                                                                                                                  \
    __attribute__((interrupt)) __attribute__((section(".text_cpu" #vectabNum))) void isr(void)
/******************************************************************************/
/*                         Exported prototypes                                */
/******************************************************************************/

#endif
