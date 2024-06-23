/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_hw_systick.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2024-2-21
 *  @Version         : V0.0.1.240221_alpha
 *  @Description     : This document describes the C language document template
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyrght protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2024-2-21    |V1.0    |Wei Xing     | New Creat
 *****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                      MISRA-C Rules Violations
 ******************************************************************************/

/******************************************************************************
 **                      QAC Warnings
 ******************************************************************************/

/******************************************************************************
 **                      Include Files
 ******************************************************************************/
#include "kf32a13k_hw_systick.h"
#include "kf32a13k_drv_systick.h"
#include "kf32a13k_hw_clk.h"
#include "kf32a13k_reg_systick.h"
#include <dev_assert.h>
#include <kf_types.h>
#include <stdbool.h>
#include <stdint.h>

/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                      Type definitions
 ******************************************************************************/

/******************************************************************************
**                     Variable Declarations
******************************************************************************/

/******************************************************************************
 **                      Function definitions
 ******************************************************************************/

/**
 * @brief 禁止Systick模块
 *
 *
 * @param Module
 */
void Systick_Hw_DisableModule(Systick_RegisterMap_t *const Module)
{
/*TODO: ENDINIT清零，解除系统关键寄存器保护*/
#if 0
    uint32_t password = Scu_LL_WdtGetCpuWdgPassword();
    uint32_t coreID = Cpu_getCoreIndex();
    SCU_LL_ClearCpuEndinit(coreID, password);
#endif
    Systick_LL_SetModuleDisabled(Module, true);
#if 0
    SCU_LL_SetCpuEndinit(coreID, password);
#endif
}

/**
 * @brief 使能Systick模块
 *
 *
 * @param Module
 */
void Systick_Hw_EnableModule(Systick_RegisterMap_t *const Module)
{
/*TODO: ENDINIT清零，解除系统关键寄存器保护*/
#if 0
    uint32_t password = Scu_LL_WdtGetCpuWdgPassword();
    uint32_t coreID = Cpu_getCoreIndex();
    SCU_LL_ClearCpuEndinit(coreID, password);
#endif
    Systick_LL_SetModuleDisabled(Module, false);
#if 0
    SCU_LL_SetCpuEndinit(coreID, password);
#endif
}

/**
 * @brief 挂起Systick模块
 *
 *
 * @param Module
 * @retval 挂起状态
 *              false: 未挂起
 *              true: 挂起
 */
bool Systick_Hw_EnableSuspend(Systick_RegisterMap_t *const Module)
{
    /*TODO: 检查OCDS是否使能*/
    Systick_LL_SetSuspendMode(Module, SYSTICK_SUSPEND_MODE_STOP);
    return (bool)(Systick_LL_IsModuleSuspended(Module));
}

/**
 * @brief 解除挂起Systick模块
 *
 *
 * @param Module
 * @retval 挂起状态
 *              false: 未挂起
 *              true: 挂起
 */
bool Systick_Hw_DisableSuspend(Systick_RegisterMap_t *const Module)
{
    /*TODO: 检查OCDS是否使能*/
    Systick_LL_SetSuspendMode(Module, SYSTICK_SUSPEND_MODE_NONE);
    return (bool)(Systick_LL_IsModuleSuspended(Module));
}

/**
 * @brief Systick模块关闭休眠模式
 *
 * @param Module
 */
void Systick_Hw_DisableSleepMode(Systick_RegisterMap_t *const Module)
{
/*TODO: ENDINIT清零，解除系统关键寄存器保护*/
#if 0
        uint32_t password = Scu_LL_WdtGetCpuWdgPassword();
        uint32_t coreID = Cpu_getCoreIndex();
        SCU_LL_ClearCpuEndinit(coreID, password);
#endif
    Systick_LL_SetSleepModeEnabled(Module, false);
#if 0
        SCU_LL_SetCpuEndinit(coreID, password);
#endif
}

/**
 * @brief Systick模块打开休眠模式
 *
 *
 * @param Module
 */
void Systick_Hw_EnableSleepMode(Systick_RegisterMap_t *const Module)
{
/*TODO: ENDINIT清零，解除系统关键寄存器保护*/
#if 0
        uint32_t password = Scu_LL_WdtGetCpuWdgPassword();
        uint32_t coreID = Cpu_getCoreIndex();
        SCU_LL_ClearCpuEndinit(coreID, password);
#endif
    Systick_LL_SetSleepModeEnabled(Module, true);
#if 0
        SCU_LL_SetCpuEndinit(coreID, password);
#endif
}

/**
 * @brief 初始化比较器
 *
 *
 * @param Module
 * @param Config
 * @return
 */
bool Systick_Hw_InitCompare(Systick_RegisterMap_t *const Module, const Systick_CompareConfig_t *Config)
{
    bool ret = true;
    if ((Config->Comparator == SYSTICK_COMPARATOR_0) || (Config->Comparator == SYSTICK_COMPARATOR_1))
    {
        uint32_t offsetTimer = 0;
        Systick_LL_SetCompareControl(
          Module, (Systick_Comparator_t)Config->Comparator, (Systick_ComparatorOffset_t)Config->ComparatorOffset,
          (Systick_ComparatorSize_t)Config->ComparatorSize, (Systick_ComparatorInterrupt_t)Config->ComparatorInterrupt);
        /* 配置比较器Ticks */
        offsetTimer = (uint32_t)(Systick_LL_GetTimer(Module) >> Config->ComparatorOffset);
        Systick_LL_UpdateCompare(Module, (Systick_Comparator_t)Config->Comparator, offsetTimer + Config->Ticks);
        /* 使能中断前清除中断标志，以避免寄存器的复位值引起比较匹配中断 */
        /** @attention 修改比较值以后再清标志 */
        Systick_LL_ClearIntrFlag(Module, (Systick_IntrMask_t)Config->Comparator);
        Systick_LL_SetIntrEnabled(Module, (Systick_IntrEnableFlagMask_t)Config->Comparator, Config->EnableInterrupt);
    }
    else
    {
        ret = false;
    }
    return ret;
}

void Systick_Hw_ResetModule(Systick_RegisterMap_t *const Module)
{
    uint16_t password = Scu_Hw_WdtGetCpuWdgPassword(SCU_HW_CPU0);
    Scu_Hw_WdtClearCpuEndinit(SCU_HW_CPU0, password);
    Systick_LL_ResetModule(Module);

    // while (!Systick_LL_GetResetStatus(Module));

    Systick_LL_ClearResetStatus(Module);
    Systick_LL_SetSleepModeEnabled(Module, false);
    Systick_LL_SetModuleDisabled(Module, false);
    Scu_Hw_WdtSetCpuEndinit(SCU_HW_CPU0, password);
}

/**
 * @brief Systick延迟us
 * @attention 该程序不可重入，调用时建议使用临界区保护
 *
 * @param UsTime
 */
void Systick_Hw_Cmp0DelayUs(uint32_t UsTime)
{
#ifdef SIMULATION
    float freq = 20000000.;
#else
    float freq = Clk_Hw_GetSysClkFrequency();
#endif
    uint32_t ticks = (uint32_t)((float)UsTime * freq / 1000000.F);
    if (ticks > 0)
    {
        Systick_CompareConfig_t Config = {
          .Comparator          = SYSTICK_HW_COMPARATOR_0,
          .ComparatorInterrupt = SYSTICK_HW_INTERRUPT_STIR0,
          .ComparatorOffset    = SYSTICK_HW_COMPARATOR_OFFSET0,
          .ComparatorSize      = SYSTICK_HW_COMPARATOR_SIZE_32BITS,
          .Ticks               = ticks,
          .EnableInterrupt     = false,
        };
        Systick_Hw_InitCompare(SYSTICK0_PTR, &Config);
        while (!Systick_LL_GetIntrFlag(SYSTICK0_PTR, SYSTICK_INTR_CMP0))
        {
        }
        Systick_LL_ClearIntrFlag(SYSTICK0_PTR, SYSTICK_INTR_INDEX_CMP0);
    }
    else
    {
    }
}

/**
 * @brief Systick延迟ms
 * @attention 该程序不可重入，调用时建议使用临界区保护
 *
 * @param UsTime
 */
void Systick_Hw_Cmp0DelayMs(uint32_t MsTime)
{
#ifdef SIMULATION
    float freq = 20000000.;
#else
    float freq = Clk_Hw_GetSysClkFrequency();
#endif
    uint32_t ticks = (uint32_t)((float)MsTime * freq / 1000.F);
    if (ticks > 0)
    {
        Systick_CompareConfig_t Config = {
          .Comparator          = SYSTICK_HW_COMPARATOR_0,
          .ComparatorInterrupt = SYSTICK_HW_INTERRUPT_STIR0,
          .ComparatorOffset    = SYSTICK_HW_COMPARATOR_OFFSET0,
          .ComparatorSize      = SYSTICK_HW_COMPARATOR_SIZE_32BITS,
          .Ticks               = ticks,
          .EnableInterrupt     = false,
        };
        Systick_Hw_InitCompare(SYSTICK0_PTR, &Config);
        while (!Systick_LL_GetIntrFlag(SYSTICK0_PTR, SYSTICK_INTR_CMP0))
        {
        }
        Systick_LL_ClearIntrFlag(SYSTICK0_PTR, SYSTICK_INTR_INDEX_CMP0);
    }
    else
    {
    }
}

/**
 * @brief Systick延迟us
 * @attention 该程序不可重入，调用时建议使用临界区保护
 *
 * @param UsTime
 */
void Systick_Hw_Cmp1DelayUs(uint32_t UsTime)
{
#ifdef SIMULATION
    float freq = 20000000.;
#else
    float freq = Clk_Hw_GetSysClkFrequency();
#endif
    uint32_t ticks = (uint32_t)((float)UsTime * freq / 1000000.F);
    if (ticks > 0)
    {
        Systick_CompareConfig_t Config = {
          .Comparator          = SYSTICK_HW_COMPARATOR_1,
          .ComparatorInterrupt = SYSTICK_HW_INTERRUPT_STIR1,
          .ComparatorOffset    = SYSTICK_HW_COMPARATOR_OFFSET0,
          .ComparatorSize      = SYSTICK_HW_COMPARATOR_SIZE_32BITS,
          .Ticks               = ticks,
          .EnableInterrupt     = false,
        };
        Systick_Hw_InitCompare(SYSTICK0_PTR, &Config);
        while (!Systick_LL_GetIntrFlag(SYSTICK0_PTR, SYSTICK_INTR_CMP1))
        {
        }
        Systick_LL_ClearIntrFlag(SYSTICK0_PTR, SYSTICK_INTR_INDEX_CMP1);
    }
    else
    {
    }
}

/**
 * @brief Systick延迟ms
 * @attention 该程序不可重入，调用时建议使用临界区保护
 *
 * @param UsTime
 */
void Systick_Hw_Cmp1DelayMs(uint32_t MsTime)
{
#ifdef SIMULATION
    float freq = 20000000.;
#else
    float freq = Clk_Hw_GetSysClkFrequency();
#endif
    uint32_t ticks = (uint32_t)((float)MsTime * freq / 1000.F);
    if (ticks > 0)
    {
        Systick_CompareConfig_t Config = {
          .Comparator          = SYSTICK_HW_COMPARATOR_1,
          .ComparatorInterrupt = SYSTICK_HW_INTERRUPT_STIR1,
          .ComparatorOffset    = SYSTICK_HW_COMPARATOR_OFFSET1,
          .ComparatorSize      = SYSTICK_HW_COMPARATOR_SIZE_32BITS,
          .Ticks               = ticks,
          .EnableInterrupt     = false,
        };
        Systick_Hw_InitCompare(SYSTICK0_PTR, &Config);
        while (!Systick_LL_GetIntrFlag(SYSTICK0_PTR, SYSTICK_INTR_CMP1))
        {
        }
        Systick_LL_ClearIntrFlag(SYSTICK0_PTR, SYSTICK_INTR_INDEX_CMP1);
    }
    else
    {
    }
}

/**
 * @brief Systick溢出配置
 *
 * @param Config
 */
void Systick_Hw_InitOverflow(Systick_RegisterMap_t *const Module, const Systick_OverflowConfig_t *Config)
{
    Systick_LL_SetTimerHighOverflowValue(Module, Config->OVH);
    Systick_LL_SetTimerLowOverflowValue(Module, Config->OVL);
    Systick_LL_ClearIntrFlag(Module, SYSTICK_INTR_INDEX_OVERFLOW);
    Systick_LL_SetIntrEnabled(Module, SYSTICK_INTR_OVERFLOW, Config->OverflowIntrEnable);
    Systick_LL_EnableTimerOverload(Module, Config->OverflowEnable);
}

/**
 * @brief Systick服务请求节点初始化
 *
 *
 * @param Module
 * @param Priority
 * @param TypeOfService
 * @param Line
 * @param EnableState
 * @return
 */
bool Systick_Hw_IntrRequestNodeInit(
  Systick_RegisterMap_t *const Module, const uint32_t Priority, const Int_SourceType_t TypeOfService,
  const Systick_Hw_ServiceInterruptLineType Line, const bool EnableState)
{
    bool                      ret = true;
    volatile Intr_IrqEnumType ServiceRequestNodeIndex;
#ifdef SIMULATION
    switch ((uint64_t)Module)
#else
    switch ((uint32_t)Module)
#endif
    {
    case SYSTICK0_ADDR:
        ServiceRequestNodeIndex = (Intr_IrqEnumType)((uint32_t)HW_SYSTICK0SR0_IRQn + (uint32_t)Line);
        break;
    case SYSTICK1_ADDR:
        ServiceRequestNodeIndex = (Intr_IrqEnumType)((uint32_t)HW_SYSTICK1SR0_IRQn + (uint32_t)Line);
        break;
    default:
        ret = false;
        break;
    }
    if (ret)
    {
        /*TODO: 超时判断 */
        do
        {
            // Int_LL_EnableServiceRequest(ServiceRequestNodeIndex, false);
            __asm__ volatile("PUSH R0");
            __asm__ volatile("MOV R0,#0xF00302C4");
            __asm__ volatile("CLR [R0], #10");
            __asm__ volatile("POP R0");
        } while (Int_LL_GetServiceRequest(ServiceRequestNodeIndex));
        /*TODO: 超时判断 */
        do
        {
            Int_LL_ClearIntRequestState(ServiceRequestNodeIndex, true);
        } while (Int_LL_GetIntRequestState(ServiceRequestNodeIndex));
        Int_LL_SetServiceType(ServiceRequestNodeIndex, TypeOfService);
        // Int_LL_SetServiceRequestPriority(ServiceRequestNodeIndex, Priority);
        // Int_LL_EnableServiceRequest(ServiceRequestNodeIndex, EnableState);
        __asm__ volatile("PUSH R0");
        __asm__ volatile("PUSH R1");
        __asm__ volatile("PUSH R2");
        __asm__ volatile("PUSH R3");
        __asm__ volatile("MOV R0,#0xF00302C4");
        __asm__ volatile("MOV R2,#0xfffffe00");
        __asm__ volatile("LD.W R3, [R0]");
        __asm__ volatile("ANL R3, R2");
        __asm__ volatile("MOV R2,#0x1FF");
        __asm__ volatile("MOV R1, #1");
        __asm__ volatile("ANL R1, R2");
        __asm__ volatile("ORL R3, R1");
        __asm__ volatile("ST.W [R0], R3");
        __asm__ volatile("POP R3");
        __asm__ volatile("POP R2");
        __asm__ volatile("POP R1");
        __asm__ volatile("POP R0");

        __asm__ volatile("PUSH R0");
        __asm__ volatile("MOV R0,#0xF00302C4");
        __asm__ volatile("SET [R0], #10");
        __asm__ volatile("POP R0");
    }
    else
    {
    }
    return ret;
}

void Systick_Hw_UpdateCompare(Systick_RegisterMap_t *const Module, Systick_Hw_Comparator_t Comparator, uint32_t Ticks)
{
    Systick_LL_UpdateCompare(Module, (Systick_Comparator_t)Comparator, Ticks);
}
#ifdef __cplusplus
}
#endif

/* EOF */
