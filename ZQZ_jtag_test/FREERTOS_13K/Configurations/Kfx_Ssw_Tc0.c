//****************************************************************************************
//*
//* File Name: Kfx_Ssw_Tc0.c
//* Project Name: FreeRTOS_13K
//* Version: v1.0
//* Date: 2024-06-03 14:42:26
//* Author: chipon
//*
//****************************************************************************************/
// #include <KF32DA2218SQVWS.h>

// asm(".include		\"KF32DA2218SQVWS.inc\"	");

/*
 * Kfx_Ssw_Tc0.c
 * Startup Software for Core1
 *  Created on: 2024-3-29
 *      Author: chipon
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Kfx_Ssw.h"

/*********************************************************************************
 * - startup code :init sram
 *********************************************************************************/

#if defined(__GNUC__)
#pragma GCC optimize "O2"
#endif

void Kfx_Ssw_C_InitInline(void)
{
    Kfx_Ssw_CTablePtr pBlockDest, pBlockSrc;
    unsigned int      uiLength, uiCnt;
    unsigned int     *pTable;
    /* clear table */
    pTable = (unsigned int *)&__clear_table;

    while (pTable)
    {
        pBlockDest.uiPtr = (unsigned int *)*pTable++;
        uiLength         = *pTable++;

        /* we are finished when length == -1 */
        if (uiLength == 0xFFFFFFFF)
        {
            break;
        }

        uiCnt = uiLength / 8;

        while (uiCnt--)
        {
            *pBlockDest.ullPtr++ = 0;
        }

        if (uiLength & 0x4)
        {
            *pBlockDest.uiPtr++ = 0;
        }

        if (uiLength & 0x2)
        {
            *pBlockDest.usPtr++ = 0;
        }

        if (uiLength & 0x1)
        {
            *pBlockDest.ucPtr = 0;
        }
    }

    /* copy table */
    pTable = (unsigned int *)&__copy_table;

    while (pTable)
    {
        pBlockSrc.uiPtr  = (unsigned int *)*pTable++;
        pBlockDest.uiPtr = (unsigned int *)*pTable++;
        uiLength         = *pTable++;

        /* we are finished when length == -1 */
        if (uiLength == 0xFFFFFFFF)
        {
            break;
        }

        uiCnt = uiLength / 8;

        while (uiCnt--)
        {
            *pBlockDest.ullPtr++ = *pBlockSrc.ullPtr++;
        }

        if (uiLength & 0x4)
        {
            *pBlockDest.uiPtr++ = *pBlockSrc.uiPtr++;
        }

        if (uiLength & 0x2)
        {
            *pBlockDest.usPtr++ = *pBlockSrc.usPtr++;
        }

        if (uiLength & 0x1)
        {
            *pBlockDest.ucPtr = *pBlockSrc.ucPtr;
        }
    }
}

/*********************************************************************************
 * - startup code
 *********************************************************************************/
static void __StartUpSoftware(void);

static void __StartUpSoftware_Phase2(void);
static void __StartUpSoftware_Phase3ApplicationResetPath(void);
static void __StartUpSoftware_Phase3PowerOnResetPath(void);
static void __StartUpSoftware_Phase4(void);
static void __StartUpSoftware_Phase5(void);
static void __StartUpSoftware_Phase6(void);

void __Core0_start(void);
/*********************************************************************************
 * - startup code
 *********************************************************************************/
_WEAK void hardware_init_hook(void) {}

_WEAK void software_init_hook(void) {}

static void __StartUpSoftware(void) {}

static void __StartUpSoftware_Phase2(void) {}

static void __StartUpSoftware_Phase3PowerOnResetPath(void) {}
static void __StartUpSoftware_Phase3ApplicationResetPath(void) {}
static void __StartUpSoftware_Phase4(void) {}
static void __StartUpSoftware_Phase5(void) {}

static void __StartUpSoftware_Phase6(void) {}
/*********************************************************************************
 * - startup code
 *********************************************************************************/
extern unsigned int __USTACK0[];      /**< user stack end */
extern unsigned int __ISTACK0[];      /**< interrupt stack end */
extern unsigned int __INTTAB_CPU0[];  /**< interrupt vector table */
extern unsigned int __TRAPTAB_CPU0[]; /**< trap vector table */
void                __Core0_start(void)
{

    /* Hook functions to initialize application specific HW extensions */
    hardware_init_hook();

    /* Hook functions to initialize application specific SW extensions */
    software_init_hook();

    /* Initialization of C runtime variables and CPP constructors and destructors */
    Kfx_Ssw_C_InitInline();
    __asm__ volatile("PUSH R0" ::: "memory");
    /* BTV */
    __asm__ volatile("MOV R0, %0" ::"r"((unsigned int)__TRAPTAB_CPU0) : "R0");
    __asm__ volatile("CSRW R0, #0x188" ::: "R0");
    __asm__ volatile("SYNC");
    /* BIV */
    __asm__ volatile("MOV R0, %0" ::"r"((unsigned int)__INTTAB_CPU0) : "R0");
    __asm__ volatile("CSRW R0, #0x186" ::: "R0");
    __asm__ volatile("SYNC");
    /* ISP */
    __asm__ volatile("MOV R0, %0" ::"r"((unsigned int)__ISTACK0) : "R0");
    __asm__ volatile("CSRW R0, #0x189" ::: "R0");
    __asm__ volatile("SYNC");
    /* SP */
    __asm__ volatile("MOV SP, %0" ::"r"((unsigned int)__USTACK0) : "R0");
    __asm__ volatile("SYNC");

    __asm__ volatile("POP R0" ::: "memory");
    /* RETURN_FROM_MAIN */
    extern void core0_main(void);
    __jumpToFunctionWithLink(core0_main); /* Jump to main function of CPU0 */

    /* Go into infinite loop, normally the code shall not reach here */
    __Loop();
}
