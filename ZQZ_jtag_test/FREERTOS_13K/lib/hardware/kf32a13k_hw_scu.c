/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_hw_scu.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2024-1-10
 *  @Version         : V0.0.1.230625_alpha
 *  @Description     : This document describes the C language document template
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyrght protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2024-1-10    |V1.0    |Zhang Quanzhen     | New
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
#include "kf32a13k_hw_scu.h"
#include "kf32a13k_drv_scu.h"
#include "dev_assert.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/
#define SCURCU_PERFORM_RESET_DELAY (90000U)

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
 * @ief 设置ERU外部输入通道及触发单元

 * @param InputChannel 外部输入通道
 * @param Signal 通道触发单元
 *
 * @retval void
 */
void Scu_Hw_SelectEruExternalInput(Scu_Hw_EruInputChannel_t InputChannel, Scu_Hw_EruInputSelect_t Signal)
{
    Scu_LL_EruSelectExternalInput((Scu_EruInputChannelType_t)InputChannel, (Scu_EruExternalInputType_t)Signal);
}

/**
 * @brief 设置ERU输入引脚滤波器使能
 *
 * @param Pin 设置滤波使能的引脚
 * @param State 是否使能
 *
 * @retval void
 */
void Scu_Hw_SetERUFilterPinEnabled(Scu_Hw_EruFilterPin_t Pin, bool State)
{
    Scu_LL_SetERUFilterPinEnabled((Scu_EruFilterPin_t)Pin, State);
}

/**
 * @brief 获取ERU输入引脚滤波器使能
 *
 * @param Pin 获取滤波使能的引脚
 *
 * @retval bool 是否使能
 */
bool Scu_Hw_GetERUFilterPinEnabled(Scu_Hw_EruFilterPin_t Pin)
{
    return Scu_LL_GetERUFilterPinEnabled((Scu_EruFilterPin_t)Pin);
}

/**
 * @brief 设置ERU数字滤波器时钟分频
 *
 * @param Div 时钟分频系数
 *
 * @retval void
 */
void Scu_Hw_SetERUFilterClkDiv(Scu_Hw_EruFilterClkDiv_t Div)
{
    Scu_LL_SetERUFilterClkDiv((Scu_EruFilterClkDiv_t)Div);
}

/**
 * @brief 设置ERU数字滤波深度
 *
 * @param Depth ERU数字滤波深度
 *
 * @retval void
 */
void Scu_Hw_SetERUFilterDepth(Scu_Hw_EruFilterDepth_t Depth)
{
    Scu_LL_SetERUFilterDepth((Scu_EruFilterDepth_t)Depth);
}

/**
 * @brief 紧急停止输入极性选择
 *
 * @param Polarity
 *          SCU_HW_EMERGENCY_STOP_POLARITY_HIGH - 高电平有效
 *          SCU_HW_EMERGENCY_STOP_POLARITY_LOW - 低电平有效
 *
 * @retval void
 */
void Scu_Hw_SetEmergencyStopInputPolarity(Scu_Hw_EmergencyStopInputPolarity_t Polarity)
{
    Scu_LL_SetEmergencyStopInputPolarity((Scu_EmergencyStopInputPolarity_t)Polarity);
}

/**
 * @brief 紧急停止模式选择
 *
 * @param Mode
 *          SCU_HW_EMERGENCY_STOP_MODE_SYNC - 同步模式
 *          SCU_HW_EMERGENCY_STOP_MODE_ASYNC - 异步模式
 *
 * @retval void
 */
void Scu_Hw_SetEmergencyStopMode(Scu_Hw_EmergencyStopMode_t Mode)
{
    Scu_LL_SetEmergencyStopMode((Scu_EmergencyStopMode_t)Mode);
}

/**
 * @brief EMSF标志位使能
 *
 * @param State
 *          false - 禁止置位EMSF标志位
 *          true - 允许置位EMSF标志位
 *
 * @retval void
 */
void Scu_Hw_SetEmergencyStopFlagEnabled(bool State)
{
    Scu_LL_SetEmergencyStopFlagEnabled(State);
}

/**
 * @brief 紧急停止输入引脚选择
 *
 * @param Select
 *          SCU_HW_EMERGENCY_STOP_PORTA - PortA触发紧急停止
 *          SCU_HW_EMERGENCY_STOP_PORTB - PortB触发紧急停止
 *
 * @retval void
 */
void Scu_Hw_EmergencyStopPortSelect(Scu_Hw_EmergencyStopPort_t Select)
{
    Scu_LL_EmergencyStopPortSelect((Scu_EmergencyStopPort_t)Select);
}

/**
 * @brief 修改安全控制紧急停止标志位
 *
 * @param Select
 *          SCU_HW_EMERGENCY_STOP_FLAG_SET - 置位
 *          SCU_HW_EMERGENCY_STOP_FLAG_CLEAR - 清零
 *
 * @retval void
 */
void Scu_Hw_SafetyEmergencyStopFlagSelect(Scu_Hw_EmergencyStopFlag_t Select)
{
    Scu_LL_SafetyEmergencyStopFlagSelect((Scu_EmergencyStopFlag_t)Select);
}

/**
 * @brief 获取紧急停止标志位
 *
 * @retval bool
 */
bool Scu_Hw_GetEmergencyStopFlag(void)
{
    return Scu_LL_GetSafetyEmergencyStopFlag();
}

/**
 * @brief 获取SMU触发紧急停止标志位
 *
 * @retval bool
 */
bool Scu_Hw_GetSafetyEmergencyStopFlag(void)
{
    return Scu_LL_GetSafetyEmergencyStopFlag();
}

/**
 * @brief 修改紧急停止标志位
 *
 * @param Select
 *          SCU_HW_EMERGENCY_STOP_FLAG_SET - 置位
 *          SCU_HW_EMERGENCY_STOP_FLAG_CLEAR - 清零
 *
 * @retval void
 */
void Scu_Hw_EmergencyStopFlagSelect(Scu_Hw_EmergencyStopFlag_t Select)
{
    Scu_LL_EmergencyStopFlagSelect((Scu_EmergencyStopFlag_t)Select);
}

/**
 * @brief 使能陷阱触发类型
 *
 * @param CPU 待响应CPU
 * @param Trap 陷阱类型
 * @param Status 是否使能
 *
 * @retval void
 */
void Scu_Hw_SetTrapEnabled(const Scu_Hw_CPUType_t CPU, Scu_Hw_Trap_t Trap, const bool Status)
{
    Scu_LL_TrapEnable((Scu_CPUType_t)CPU, (Scu_TrapType_t)Trap, Status);
}

/**
 * @brief 获取陷阱使能触发类型
 *
 * @param CPU 待响应CPU
 * @param Trap 陷阱类型
 *
 * @retval bool
 */
bool Scu_Hw_GetTrapEnabledStatus(const Scu_Hw_CPUType_t CPU, Scu_Hw_Trap_t Trap)
{
    return Scu_LL_TrapGetEnable((Scu_CPUType_t)CPU, (Scu_TrapType_t)Trap);
}

/**
 * @brief 手动陷阱置位
 *
 * @param Trap 陷阱类型

 * @retval void
 */
void Scu_Hw_TriggerTrap(Scu_Hw_Trap_t Trap)
{
    Scu_LL_TrapSetFlag((Scu_TrapType_t)Trap, true);
}

/**
 * @brief 清除陷阱标志
 *
 * @param Trap 陷阱类型
 *
 * @retval void
 */
void Scu_Hw_ClearTrapFlag(Scu_Hw_Trap_t Trap)
{
    Scu_LL_TrapClearFlag((Scu_TrapType_t)Trap, true);
}

/**
 * @brief 获取陷阱置位标志
 *
 * @param Trap 陷阱类型
 *
 * @retval bool
 */
bool Scu_Hw_GetTrapTriggerFlag(Scu_Hw_Trap_t Trap)
{
    return (Scu_LL_TrapGetFlag((Scu_TrapType_t)Trap));
}

/**
 * @brief 获取CPUx看门狗计数器检查公差
 *
 * @param CPU
 *
 * @retval bool
 */
uint8_t Scu_Hw_GetCpuWdtCheckTolerance(Scu_Hw_CPUType_t CPU)
{
    return Scu_LL_GetCpuWdtCheckTolerance((Scu_CPUType_t)CPU);
}

/**
 * @brief 获取CPUx看门狗超时计数器值
 *
 * @param CPU
 *
 * @retval bool
 */
uint16_t Scu_Hw_GetCpuWdtTimerValue(Scu_Hw_CPUType_t CPU)
{
    return Scu_LL_GetCpuWdtTimerValue((Scu_CPUType_t)CPU);
}

/**
 * @brief 获取CPUx看门狗状态
 *
 * @param CPU
 * @param Flag 待获取状态标志位
 *
 * @retval bool
 */
bool Scu_Hw_GetCpuWdtStatus(Scu_Hw_CPUType_t CPU, Scu_Hw_WdtStatusFlag_t Flag)
{
    return Scu_LL_GetCpuWdtStatus((Scu_CPUType_t)CPU, (Scu_WdtStatusFlag_t)Flag);
}

/**
 * @brief 获取CPU 看门狗 Reload
 *
 * @param CPU
 * @retval uint32_t
 */
uint32_t Scu_Hw_WdtGetCpuWdgReload(Scu_Hw_CPUType_t CPU)
{
    return Scu_LL_WdtGetCpuWdgReload((Scu_CPUType_t)CPU);
}

/**
 * @brief 获取CPU看门狗控制寄存器0锁定状态
 *
 * @param CPU
 * @retval bool
 *         true:寄存器被锁定
 *         false:寄存器被解锁
 */
bool Scu_Hw_WdtGetCpuRegLockState(Scu_Hw_CPUType_t CPU)
{
    return Scu_LL_WdtGetCpuRegLockState((Scu_CPUType_t)CPU);
}

/**
 * @brief 允许访问受 Endinit 保护的 CPU看门狗寄存器
 *
 *
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtClearCpuEndinit(Scu_Hw_CPUType_t CPU, uint32_t Password)
{
    Scu_LL_WdtClearCpuEndinitInline(CPU, Password);
}

/**
 * @brief 禁止访问受 Endinit 保护的 CPU看门狗寄存器
 *
 *
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtSetCpuEndinit(Scu_Hw_CPUType_t CPU, uint32_t Password)
{
    Scu_LL_WdtSetCpuEndinitInline(CPU, Password);
}

/**
 * @brief 改变CPU 看门狗密码
 *
 *
 * @param uint32_t
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtChangeCpuWdgPassword(Scu_Hw_CPUType_t CPU, uint32_t Password, uint32_t NewPassword)
{
    Scu_LL_WdtChangeCpuWdgPasswordInline(CPU, Password, NewPassword);
}

/**
 * @brief 改变CPU 看门狗重加载值
 *
 *
 * @param uint32_t
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtChangeCpuWdgReload(Scu_Hw_CPUType_t CPU, uint32_t Password, uint32_t Reload)
{
    Scu_LL_WdtChangeCpuWdgReloadInline(CPU, Password, Reload);
}

/**
 * @brief 允许访问受 Endinit 保护的 安全看门狗寄存器
 *
 *
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtClearSafetyEndinit(uint32_t Password)
{
    Scu_LL_WdtClearSafetyEndinitInline(Password);
}

/**
 * @brief 禁止访问受 Endinit 保护的 安全看门狗寄存器
 *
 *
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtSetSafetyEndinit(uint32_t Password)
{
    Scu_LL_WdtSetSafetyEndinitInline(Password);
}

/**
 * @brief 改变Safety 看门狗密码
 *
 *
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtChangeSafetyWdgPassword(uint32_t Password, uint32_t NewPassword)
{
    Scu_LL_WdtChangeSafetyWdgPasswordInline(Password, NewPassword);
}

/**
 * @brief 改变Safety 看门狗重加载值
 *
 *
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtChangeSafetyWdgReload(uint32_t Password, uint32_t Reload)
{
    Scu_LL_WdtChangeSafetyWdgReload(Password, Reload);
}

/**
 * @brief 允许访问受 Endinit 保护的 Global 看门狗寄存器
 *
 *
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtClearGlobalEndinit(uint32_t Password)
{
    // TODO:需要确定使用方式
    if (true == Scu_LL_WdtGetGlobalEndInit())
    {
        Scu_LL_WdtSetGlobalWdgPassword(Password);
        Scu_LL_WdtUnlockGlobalReg();
    }
}

/**
 * @brief 禁止访问受 Endinit 保护的 Global 看门狗寄存器
 *
 *
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtSetGlobalEndinit(uint32_t Password)
{
    // TODO:需要确定使用方式
    if (false == Scu_LL_WdtGetGlobalEndInit())
    {
        Scu_LL_WdtSetGlobalWdgPassword(Password);
        Scu_LL_WdtUnlockGlobalReg();
    }
}

/**
 * @brief 改变Global 看门狗密码
 *
 *
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtChangeGlobalWdgPassword(uint32_t Password, uint32_t NewPassword)
{
    // TODO:需要确定使用方式
    if (true == Scu_LL_WdtGetGlobalEndInit())
    {
        Scu_LL_WdtSetGlobalWdgPassword(Password);
        Scu_LL_WdtUnlockGlobalReg();
    }
    Scu_LL_WdtSetGlobalWdgPassword(NewPassword);
    Scu_LL_WdtlockGlobalReg();
}

/**
 * @brief 关闭CPU 看门狗
 *
 *
 * @param uint32_t
 * @param uint32_t

 * @retval void
 */
void Scu_Hw_WdtDisableCpuWdg(Scu_Hw_CPUType_t CPU, uint32_t Password)
{
    /* Select CPU Watchdog based on Core Id */
    Scu_Hw_WdtClearCpuEndinit(CPU, Password);
    Scu_LL_WdtRequestCpuWdgDisable((Scu_CPUType_t)CPU, true);
    Scu_Hw_WdtSetCpuEndinit(CPU, Password);
}

/**
 * @brief 使能CPU 看门狗
 *
 *
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtEnableCpuWdg(Scu_Hw_CPUType_t CPU, uint32_t Password)
{
    /* Select CPU Watchdog based on Core Id */
    Scu_Hw_WdtClearCpuEndinit(CPU, Password);
    Scu_LL_WdtRequestCpuWdgDisable((Scu_CPUType_t)CPU, false);
    Scu_Hw_WdtSetCpuEndinit(CPU, Password);
}

/**
 * @brief 禁止Safety 看门狗
 *
 *
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtDisableSafetyWdg(uint32_t Password)
{
    Scu_Hw_WdtClearSafetyEndinit(Password);
    Scu_LL_WdtRequestSafetyWdgDisable(true);
    Scu_Hw_WdtSetSafetyEndinit(Password);
}

/**
 * @brief 使能Safety 看门狗
 *
 *
 * @param uint32_t
 * @retval void
 */
void Scu_Hw_WdtEnableSafetyWdg(uint32_t Password)
{
    Scu_Hw_WdtClearSafetyEndinit(Password);
    Scu_LL_WdtRequestSafetyWdgDisable(false);
    Scu_Hw_WdtSetSafetyEndinit(Password);
}

/**
 * @brief 初始化 CPU看门狗
 *
 *
 * @param uint32_t
 * @param Scu_WdtConfigType_t
 * @retval void
 */
void Scu_Hw_WdtInitCpuWdg(Scu_Hw_CPUType_t CPU, Scu_WdtConfigType_t *ConfigPtr)
{
    uint32_t password = 0U;
    if (true == Scu_LL_WdtGetCpuRegLockState((Scu_CPUType_t)CPU))
    {
        Scu_LL_WdtlockCpuReg((Scu_CPUType_t)CPU);
        password = Scu_LL_WdtGetCpuWdgPassword((Scu_CPUType_t)CPU);
        Scu_LL_WdtSetCpuWdgPassword((Scu_CPUType_t)CPU, password);
    }
    Scu_LL_WdtUnlockCpuReg((Scu_CPUType_t)CPU);
    Scu_LL_WdtSetCpuWdgPassword((Scu_CPUType_t)CPU, ConfigPtr->Password);
    Scu_LL_WdtSetCpuWdgReload((Scu_CPUType_t)CPU, ConfigPtr->Reload);
    Scu_LL_WdtSetCpuWdgClockDivide((Scu_CPUType_t)CPU, (Scu_WdtDivType_t)ConfigPtr->InputFrequency);
    Scu_LL_WdtRequestCpuWdgDisable((Scu_CPUType_t)CPU, ConfigPtr->DisableWatchdog);
    Scu_LL_WdtRequestCpuWdgUnlockRestriction((Scu_CPUType_t)CPU, ConfigPtr->EnableSmuRestriction);
    Scu_LL_WdtRequestCpuWdgAutomaticPassword((Scu_CPUType_t)CPU, ConfigPtr->EnableAutomaticPasswordChange);
    Scu_LL_WdtRequestCpuWdgTimeCheck((Scu_CPUType_t)CPU, ConfigPtr->EnableTimerCheck);
    Scu_LL_WdtSetCpuWdgCheckTolerance((Scu_CPUType_t)CPU, ConfigPtr->TimerCheckTolerance);
    Scu_Hw_WdtSetCpuEndinit(CPU, ConfigPtr->Password);
}

/**
 * @brief 初始化 Safety看门狗
 *
 *
 * @param uint32_t
 * @param Scu_WdtConfigType_t
 * @retval void
 */
void Scu_Hw_WdtInitSafetyWdg(Scu_WdtConfigType_t *ConfigPtr)
{
    uint32_t password = 0U;
    if (Scu_LL_WdtGetSafetyRegLockState())
    {
        Scu_LL_WdtlockSafetyReg();
        password = Scu_LL_WdtGetSafetyWdgPassword();
        Scu_LL_WdtSetSafetyWdgPassword(password);
    }
    Scu_LL_WdtUnlockSafetyReg();
    Scu_LL_WdtSetSafetyWdgPassword(ConfigPtr->Password);
    Scu_LL_WdtSetSafetyWdgReload(ConfigPtr->Reload);
    Scu_LL_WdtSetSafetyWdgClockDivide((Scu_WdtDivType_t)ConfigPtr->InputFrequency);
    Scu_LL_WdtRequestSafetyWdgDisable(ConfigPtr->DisableWatchdog);
    Scu_LL_WdtRequestSafetyWdgUnlockRestriction(ConfigPtr->EnableSmuRestriction);
    Scu_LL_WdtRequestSafetyWdgAutomaticPassword(ConfigPtr->EnableAutomaticPasswordChange);
    Scu_LL_WdtRequestSafetyWdgTimeCheck(ConfigPtr->EnableTimerCheck);
    Scu_LL_WdtSetSafetyWdgCheckTolerance(ConfigPtr->TimerCheckTolerance);
    Scu_Hw_WdtSetSafetyEndinit(ConfigPtr->Password);
}

/**
 * @brief 获取CPU MCU复位类型及复位触发源
 *
 *
 * @param void
 * @retval Scu_RcuResetCodeType_t
 */
Scu_RcuResetCodeType_t Scu_Hw_RcuEvaluateReset(void)
{
    Scu_RcuResetCodeType_t resetCode;
    resetCode.ResetType    = SCURCU_HW_RESET_UNDEFINED;
    resetCode.ResetTrigger = SCURCU_HW_TRIGGER_UNDEFINED;
    resetCode.ResetReason  = 0U;
    if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_ESR0))
    {
        resetCode.ResetTrigger = SCURCU_HW_TRIGGER_ESR0;
        resetCode.ResetType    = (Scu_Hw_RcuResetType_t)Scu_LL_RcuGetResetType(SCURCU_TRIGGER_ESR0);
    }
    else if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_ESR1))
    {
        resetCode.ResetTrigger = SCURCU_HW_TRIGGER_ESR1;
        resetCode.ResetType    = (Scu_Hw_RcuResetType_t)Scu_LL_RcuGetResetType(SCURCU_TRIGGER_ESR1);
    }
    else if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_SMUALL))
    {
        resetCode.ResetTrigger = SCURCU_HW_TRIGGER_SMUALL;
        resetCode.ResetType    = SCURCU_HW_RESET_UNDEFINED;
    }
    else if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_SMU))
    {
        resetCode.ResetTrigger = SCURCU_HW_TRIGGER_SMU;
        resetCode.ResetType    = (Scu_Hw_RcuResetType_t)Scu_LL_RcuGetResetType(SCURCU_TRIGGER_SMU);
    }
    else if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_SW))
    {
        resetCode.ResetTrigger = SCURCU_HW_TRIGGER_SW;
        resetCode.ResetType    = (Scu_Hw_RcuResetType_t)Scu_LL_RcuGetResetType(SCURCU_TRIGGER_SW);
    }
    else if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_STM0))
    {
        resetCode.ResetTrigger = SCURCU_HW_TRIGGER_STM0;
        resetCode.ResetType    = (Scu_Hw_RcuResetType_t)Scu_LL_RcuGetResetType(SCURCU_TRIGGER_STM0);
    }
    else if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_STM1))
    {
        resetCode.ResetTrigger = SCURCU_HW_TRIGGER_STM1;
        resetCode.ResetType    = (Scu_Hw_RcuResetType_t)Scu_LL_RcuGetResetType(SCURCU_TRIGGER_STM1);
    }
    else if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_CB0))
    {
        resetCode.ResetTrigger = SCURCU_HW_TRIGGER_CB0;
        resetCode.ResetType    = SCURCU_HW_RESET_SYSTEM;
    }
    else if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_CB1))
    {
        resetCode.ResetTrigger = SCURCU_HW_TRIGGER_CB1;
        resetCode.ResetType    = SCURCU_HW_RESET_DEBUG;
    }
    else if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_CB3))
    {
        resetCode.ResetTrigger = SCURCU_HW_TRIGGER_CB3;
        resetCode.ResetType    = SCURCU_HW_RESET_APPLICATION;
    }
    else
    {
        if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_DCDC11))
        {
            resetCode.ResetTrigger = SCURCU_HW_TRIGGER_DCDC11;
            resetCode.ResetType    = SCURCU_HW_RESET_COLDPOWERON;
        }
        if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_LDO33))
        {
            resetCode.ResetTrigger = SCURCU_HW_TRIGGER_LDO33;
            resetCode.ResetType    = SCURCU_HW_RESET_COLDPOWERON;
        }
        if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_SWD))
        {
            resetCode.ResetTrigger = SCURCU_HW_TRIGGER_SWD;
            resetCode.ResetType    = SCURCU_HW_RESET_COLDPOWERON;
        }
        if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_HSMS))
        {
            resetCode.ResetTrigger = SCURCU_HW_TRIGGER_HSMS;
            resetCode.ResetType    = SCURCU_HW_RESET_COLDPOWERON;
        }
        if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_HSMA))
        {
            resetCode.ResetTrigger = SCURCU_HW_TRIGGER_HSMA;
            resetCode.ResetType    = SCURCU_HW_RESET_COLDPOWERON;
        }
        if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_STBYR))
        {
            resetCode.ResetTrigger = SCURCU_HW_TRIGGER_STBYR;
            resetCode.ResetType    = SCURCU_HW_RESET_COLDPOWERON;
        }
        if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_LBPORST))
        {
            resetCode.ResetTrigger = SCURCU_HW_TRIGGER_LBPORST;
            resetCode.ResetType    = SCURCU_HW_RESET_COLDPOWERON;
        }
        if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_LBTERM))
        {
            resetCode.ResetTrigger = SCURCU_HW_TRIGGER_LBTERM;
            resetCode.ResetType    = SCURCU_HW_RESET_COLDPOWERON;
        }
    }
    if (Scu_LL_RcuGetResetTriggerState(SCURCU_TRIGGER_PORST))
    {
        if (SCURCU_RESET_COLDPOWERON != (Scu_RcuResetType_t)resetCode.ResetType)
        {
            resetCode.ResetTrigger = SCURCU_HW_TRIGGER_PORST;
            resetCode.ResetType    = SCURCU_HW_RESET_WARMPOWERON;
        }
    }
    return resetCode;
}

/**
 * @brief 请求 MCU触发一次复位
 *
 *
 * @param Scu_Hw_CPUType_t
 * @param Scu_RcuResetType_t
 * @param UserResetInfo
 * @retval void
 */
void Scu_Hw_RcuPerformReset(Scu_Hw_CPUType_t CPU, Scu_Hw_RcuResetType_t ResetType, uint32_t UserResetInfo)
{
    uint32_t index = SCURCU_PERFORM_RESET_DELAY;
    uint32_t password;
    password = Scu_LL_WdtGetSafetyWdgPassword();
    Scu_Hw_WdtClearSafetyEndinit(password);
    if (SCURCU_RESET_SYSTEM == (Scu_RcuResetType_t)ResetType)
    {
        Scu_LL_RcuSetResetType(SCURCU_TRIGGER_SW, SCURCU_RESET_SYSTEM);
    }
    else
    {
        Scu_LL_RcuSetResetType(SCURCU_TRIGGER_SW, SCURCU_RESET_APPLICATION);
    }
    password = Scu_LL_WdtGetCpuWdgPassword((Scu_CPUType_t)CPU);
    Scu_Hw_WdtClearCpuEndinit(CPU, password);
    Scu_LL_RcuSetResetInfo(UserResetInfo);
    Scu_LL_RcuEnableSoftReset();
    /* Add some delay for HW to reset */
    while (index--)
        ;
}

/**
 * @brief 清除 MCU冷复位状态位
 *
 *
 * @param Scu_Hw_CPUType_t
 * @param Scu_RcuResetType_t
 * @param UserResetInfo
 * @retval void
 */
void Scu_Hw_RcuClearColdResetStatus(Scu_Hw_CPUType_t CPU)
{
    uint32_t password;
    password = Scu_LL_WdtGetCpuWdgPassword((Scu_CPUType_t)CPU);
    Scu_Hw_WdtClearCpuEndinit(CPU, password);
    Scu_LL_RcuClearColdResetStatus();
    Scu_Hw_WdtSetCpuEndinit(CPU, password);
}

/**
 * @brief 设置 MCU复位触发源及复位类型
 *
 *
 * @param Scu_Hw_CPUType_t
 * @param Scu_RcuResetType_t
 * @retval void
 */
void Scu_Hw_ConfigResetRequestTrigger(Scu_Hw_RcuTriggerType_t Trigger, Scu_Hw_RcuResetType_t ResetType)
{
    uint32_t password;
    password = Scu_LL_WdtGetSafetyWdgPassword();
    Scu_Hw_WdtClearSafetyEndinit(password);
    Scu_LL_RcuSetResetType((Scu_RcuTriggerType_t)Trigger, (Scu_RcuResetType_t)ResetType);
    Scu_Hw_WdtSetSafetyEndinit(password);
}

/**
 * @brief 获取CPU 看门狗 Password
 *
 *
 * @param CPU
 * @retval uint32_t
 */
uint32_t Scu_Hw_WdtGetCpuWdgPassword(Scu_Hw_CPUType_t CPU)
{
    return (Scu_LL_WdtGetCpuWdgPassword((Scu_CPUType_t)CPU));
}

/**
 * @brief 获取SAFETY 看门狗 Password
 *
 *
 * @retval uint32_t
 */
uint32_t Scu_Hw_WdtGetSafetyPassword()
{
    return (Scu_LL_WdtGetSafetyWdgPassword());
}

/**
 * @brief 获取GLOBAL 看门狗 Password
 *
 *
 * @retval uint32_t
 */
uint32_t Scu_Hw_WdtGetGlobalPassword()
{
    return (Scu_LL_WdtGetGlobalWdgPassword());
}

#ifdef __cplusplus
}
#endif

/* EOF */
