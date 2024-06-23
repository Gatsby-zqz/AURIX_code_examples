//****************************************************************************************
//*
//* File Name: Cpu0_Main.c
//* Project Name: FreeRTOS_13K
//* Version: v1.0
//* Date: 2024-06-03 14:42:26
//* Author: chipon
//*
//****************************************************************************************/
// #include <KF32DA2218SQVWS.h>

// asm(".include		\"KF32DA2218SQVWS.inc\"	");
#include "app_task.h"
#include "kf_types.h"
#include "Kfx_Ssw.h"
#include "kf32a13k_drv_int.h"
#include "RtosTestCfg.h"

// #define INTR_TEST            1

#ifdef INTR_TEST
static uint32_t systickIntrNum = 0;
static uint32_t gpsrIntrNum    = 0;
void            interruptSystick(void)
{
    systickIntrNum++;
    if (systickIntrNum % 1000 == 0)
    {
        /* 触发软件中断 */
        Int_LL_SetIntRequestState(HW_GP0SR0_IRQn, true);
    }
}

void interruptSwGp0Sr0(void)
{
    gpsrIntrNum++;
}
#else
extern void interruptSwGp0Sr0(void);
extern void interruptSystick(void);
#endif
KFX_INTERRUPT_INTERNAL(interruptSystick, 0, 1);
KFX_INTERRUPT_INTERNAL(interruptSwGp0Sr0, 0, 0);

void core0_main(void)
{
#ifdef INTR_TEST
    extern void vPortSetupTimerInterrupt(void);
    vPortSetupTimerInterrupt();
#else
    RtosTc01();
#endif
    while (1)
        ;
}

//****************************************************************************************/
