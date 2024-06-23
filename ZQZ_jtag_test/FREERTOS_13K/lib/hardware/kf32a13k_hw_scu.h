/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_hw_scu.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-06-25
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
 *  |2023-1-10    |V1.0    |Zhang Quanzhen  | New
 *****************************************************************************/
#ifndef KF32A13K_HW_Scu_H
#define KF32A13K_HW_Scu_H

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
/* Add or remove header files on your request, REMOVE THIS COMMENT LINE */
#include "dev_assert.h"
#include "kf32a13k_reg_scu.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>
/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                      Typedef  Definitions
 ******************************************************************************/
typedef enum
{
    SCURCU_HW_RESET_COLDPOWERON,
    SCURCU_HW_RESET_SYSTEM,
    SCURCU_HW_RESET_APPLICATION,
    SCURCU_HW_RESET_WARMPOWERON,
    SCURCU_HW_RESET_DEBUG,
    SCURCU_HW_RESET_UNDEFINED,
} Scu_Hw_RcuResetType_t;

typedef enum
{
    SCURCU_HW_TRIGGER_ESR0      = 0U,
    SCURCU_HW_TRIGGER_ESR1      = 1U,
    SCURCU_HW_TRIGGER_SMUALL    = 2U,
    SCURCU_HW_TRIGGER_SMU       = 3U,
    SCURCU_HW_TRIGGER_SW        = 4U,
    SCURCU_HW_TRIGGER_STM0      = 5U,
    SCURCU_HW_TRIGGER_STM1      = 6U,
    SCURCU_HW_TRIGGER_PORST     = 16U,
    SCURCU_HW_TRIGGER_CB0       = 18U,
    SCURCU_HW_TRIGGER_CB1       = 19U,
    SCURCU_HW_TRIGGER_CB3       = 20U,
    SCURCU_HW_TRIGGER_DCDC11    = 21U,
    SCURCU_HW_TRIGGER_LDO33     = 22U,
    SCURCU_HW_TRIGGER_SWD       = 23U,
    SCURCU_HW_TRIGGER_HSMS      = 24U,
    SCURCU_HW_TRIGGER_HSMA      = 25U,
    SCURCU_HW_TRIGGER_STBYR     = 26U,
    SCURCU_HW_TRIGGER_LBPORST   = 27U,
    SCURCU_HW_TRIGGER_LBTERM    = 28U,
    SCURCU_HW_TRIGGER_UNDEFINED = 29U,
} Scu_Hw_RcuTriggerType_t;

typedef enum
{
    SCUWDT_HW_DIVBY_16384,
    SCUWDT_HW_DIVBY_64,
    SCUWDT_HW_DIVBY_256,
    SCUWDT_HW_DIVBY_512,
    SCUWDT_HW_DIVBY_1024,
    SCUWDT_HW_DIVBY_2048,
    SCUWDT_HW_DIVBY_4096,
    SCUWDT_HW_DIVBY_8192,
} Scu_Hw_WdtDivType_t;

typedef enum
{
    SCUWDT_HW_STATUS_FLAG_ACCESS_ERROR           = 0U,
    SCUWDT_HW_STATUS_FLAG_OVERFLOW_ERROR         = 1U,
    SCUWDT_HW_STATUS_FLAG_DISABLED               = 4U,
    SCUWDT_HW_STATUS_FLAG_TIMEOUT                = 5U,
    SCUWDT_HW_STATUS_FLAG_UNLOCK_RESTRICTION     = 6U,
    SCUWDT_HW_STATUS_FLAG_PASSWORD_AUTO_SEQUENCE = 7U,
    SCUWDT_HW_STATUS_FLAG_TIMER_CHECK            = 8U,
} Scu_Hw_WdtStatusFlag_t;

typedef struct
{
    Scu_Hw_RcuResetType_t   ResetType;    /**< \brief Reset Type */
    Scu_Hw_RcuTriggerType_t ResetTrigger; /**< \brief reset Trigger */
    uint16_t                ResetReason;  /**< \brief Reset Reason */
} Scu_RcuResetCodeType_t;

/** \brief Configuration structure for Scu Watchdog.
 * IfxScuWdt_Config is a type describing configuration structure of CPU and
 * Safety WDT registers defined in IfxScuWdt.h file.
 */
typedef struct
{
    uint32_t            Password;
    uint32_t            Reload;
    uint32_t            TimerCheckTolerance;
    Scu_Hw_WdtDivType_t InputFrequency;
    bool                DisableWatchdog;
    bool                EnableTimerCheck;
    bool                EnableSmuRestriction;
    bool                EnableAutomaticPasswordChange;
    bool                ClrInternalResetFlag;
} Scu_WdtConfigType_t;

typedef enum
{
    SCU_HW_CPU0,
    SCU_HW_CPU1,
} Scu_Hw_CPUType_t;

typedef enum
{
    SCU_HW_TRAPESR0,
    SCU_HW_TRAPESR1,
    SCU_HW_TRAPSOFT,
    SCU_HW_TRAPSMU,
} Scu_Hw_Trap_t;

typedef enum
{
    SCU_HW_EMERGENCY_STOP_FLAG_SET   = 1U,
    SCU_HW_EMERGENCY_STOP_FLAG_CLEAR = 2U,
} Scu_Hw_EmergencyStopFlag_t;

typedef enum
{
    SCU_HW_EMERGENCY_STOP_POLARITY_HIGH = 0U,
    SCU_HW_EMERGENCY_STOP_POLARITY_LOW  = 1U,
} Scu_Hw_EmergencyStopInputPolarity_t;

typedef enum
{
    SCU_HW_EMERGENCY_STOP_MODE_SYNC  = 0U,
    SCU_HW_EMERGENCY_STOP_MODE_ASYNC = 1U,
} Scu_Hw_EmergencyStopMode_t;

typedef enum
{
    SCU_HW_EMERGENCY_STOP_PORTA = 0U,
    SCU_HW_EMERGENCY_STOP_PORTB = 1U,
} Scu_Hw_EmergencyStopPort_t;

typedef enum
{
    SCU_HW_ERU_FILRQ0A,
    SCU_HW_ERU_FILRQ5A,
    SCU_HW_ERU_FILRQ2A,
    SCU_HW_ERU_FILRQ3A,
    SCU_HW_ERU_FILRQ0C,
    SCU_HW_ERU_FILRQ1C,
    SCU_HW_ERU_FILRQ3C,
    SCU_HW_ERU_FILRQ2C,
    SCU_HW_ERU_FILRQ4A,
    SCU_HW_ERU_FILRQ6A,
    SCU_HW_ERU_FILRQ1A,
    SCU_HW_ERU_FILRQ7A,
    SCU_HW_ERU_FILRQ6D,
    SCU_HW_ERU_FILRQ4D,
    SCU_HW_ERU_FILRQ2B,
    SCU_HW_ERU_FILRQ3B,
    SCU_HW_ERU_FILRQ7C,
} Scu_Hw_EruFilterPin_t;

typedef enum
{
    SCU_HW_ERU_FILTER_DIV_DISABLE,
    SCU_HW_ERU_FILTER_DIV_1,
    SCU_HW_ERU_FILTER_DIV_2,
    SCU_HW_ERU_FILTER_DIV_3,
    SCU_HW_ERU_FILTER_DIV_4,
    SCU_HW_ERU_FILTER_DIV_5,
    SCU_HW_ERU_FILTER_DIV_6,
    SCU_HW_ERU_FILTER_DIV_7,
    SCU_HW_ERU_FILTER_DIV_8,
    SCU_HW_ERU_FILTER_DIV_9,
    SCU_HW_ERU_FILTER_DIV_10,
    SCU_HW_ERU_FILTER_DIV_11,
    SCU_HW_ERU_FILTER_DIV_12,
    SCU_HW_ERU_FILTER_DIV_13,
    SCU_HW_ERU_FILTER_DIV_14,
    SCU_HW_ERU_FILTER_DIV_15,
} Scu_Hw_EruFilterClkDiv_t;

typedef enum
{
    SCU_HW_ERU_FILTER_DEPTH_DISABLE,
    SCU_HW_ERU_FILTER_DEPTH_1,
    SCU_HW_ERU_FILTER_DEPTH_2,
    SCU_HW_ERU_FILTER_DEPTH_3,
    SCU_HW_ERU_FILTER_DEPTH_4,
    SCU_HW_ERU_FILTER_DEPTH_5,
    SCU_HW_ERU_FILTER_DEPTH_6,
    SCU_HW_ERU_FILTER_DEPTH_7,
    SCU_HW_ERU_FILTER_DEPTH_8,
    SCU_HW_ERU_FILTER_DEPTH_9,
    SCU_HW_ERU_FILTER_DEPTH_10,
    SCU_HW_ERU_FILTER_DEPTH_11,
    SCU_HW_ERU_FILTER_DEPTH_12,
    SCU_HW_ERU_FILTER_DEPTH_13,
    SCU_HW_ERU_FILTER_DEPTH_14,
    SCU_HW_ERU_FILTER_DEPTH_15,
} Scu_Hw_EruFilterDepth_t;

typedef enum
{
    SCU_HW_ERU_INPUT_CHANNEL_0,
    SCU_HW_ERU_INPUT_CHANNEL_1,
    SCU_HW_ERU_INPUT_CHANNEL_2,
    SCU_HW_ERU_INPUT_CHANNEL_3,
    SCU_HW_ERU_INPUT_CHANNEL_4,
    SCU_HW_ERU_INPUT_CHANNEL_5,
    SCU_HW_ERU_INPUT_CHANNEL_6,
    SCU_HW_ERU_INPUT_CHANNEL_7,
} Scu_Hw_EruInputChannel_t;

typedef enum
{
    SCU_HW_ERU_INPUT_A,
    SCU_HW_ERU_INPUT_B,
    SCU_HW_ERU_INPUT_C,
    SCU_HW_ERU_INPUT_D,
    SCU_HW_ERU_INPUT_E,
    SCU_HW_ERU_INPUT_F,
} Scu_Hw_EruInputSelect_t;

/******************************************************************************
 **                      Public Functions
 ******************************************************************************/
/******************************************************************************
 *                     RCU Export Functions
 ******************************************************************************/
Scu_RcuResetCodeType_t Scu_Hw_RcuEvaluateReset(void);
void Scu_Hw_RcuPerformReset(Scu_Hw_CPUType_t CPU, Scu_Hw_RcuResetType_t ResetType, uint32_t UserResetInfo);
void Scu_Hw_RcuClearColdResetStatus(Scu_Hw_CPUType_t CPU);
void Scu_Hw_ConfigResetRequestTrigger(Scu_Hw_RcuTriggerType_t Trigger, Scu_Hw_RcuResetType_t ResetType);

/******************************************************************************
 *                     WDT Export Functions
 ******************************************************************************/
void     Scu_Hw_WdtClearCpuEndinit(Scu_Hw_CPUType_t CPU, uint32_t Password);
void     Scu_Hw_WdtSetCpuEndinit(Scu_Hw_CPUType_t CPU, uint32_t Password);
void     Scu_Hw_WdtChangeCpuWdgPassword(Scu_Hw_CPUType_t CPU, uint32_t Password, uint32_t NewPassword);
void     Scu_Hw_WdtChangeCpuWdgReload(Scu_Hw_CPUType_t CPU, uint32_t Password, uint32_t Reload);
uint32_t Scu_Hw_WdtGetCpuWdgReload(Scu_Hw_CPUType_t CPU);
void     Scu_Hw_WdtClearSafetyEndinit(uint32_t Password);
void     Scu_Hw_WdtSetSafetyEndinit(uint32_t Password);
void     Scu_Hw_WdtChangeSafetyWdgPassword(uint32_t Password, uint32_t NewPassword);
void     Scu_Hw_WdtChangeSafetyWdgReload(uint32_t Password, uint32_t Reload);
void     Scu_Hw_WdtClearGlobalEndinit(uint32_t Password);
void     Scu_Hw_WdtSetGlobalEndinit(uint32_t Password);
void     Scu_Hw_WdtChangeGlobalWdgPassword(uint32_t Password, uint32_t NewPassword);
void     Scu_Hw_WdtDisableCpuWdg(Scu_Hw_CPUType_t CPU, uint32_t Password);
void     Scu_Hw_WdtEnableCpuWdg(Scu_Hw_CPUType_t CPU, uint32_t Password);
void     Scu_Hw_WdtDisableSafetyWdg(uint32_t Password);
void     Scu_Hw_WdtEnableSafetyWdg(uint32_t Password);
void     Scu_Hw_WdtInitCpuWdg(Scu_Hw_CPUType_t CPU, Scu_WdtConfigType_t *ConfigPtr);
void     Scu_Hw_WdtInitSafetyWdg(Scu_WdtConfigType_t *ConfigPtr);
uint32_t Scu_Hw_WdtGetCpuWdgPassword(Scu_Hw_CPUType_t CPU);
uint32_t Scu_Hw_WdtGetSafetyPassword(void);
uint32_t Scu_Hw_WdtGetGlobalPassword(void);
bool     Scu_Hw_WdtGetCpuRegLockState(Scu_Hw_CPUType_t CPU);
bool     Scu_Hw_GetCpuWdtStatus(Scu_Hw_CPUType_t CPU, Scu_Hw_WdtStatusFlag_t Flag);
uint8_t  Scu_Hw_GetCpuWdtCheckTolerance(Scu_Hw_CPUType_t CPU);
uint16_t Scu_Hw_GetCpuWdtTimerValue(Scu_Hw_CPUType_t CPU);
void     Scu_Hw_SetTrapEnabled(const Scu_Hw_CPUType_t CPU, Scu_Hw_Trap_t Trap, const bool Status);
bool     Scu_Hw_GetTrapEnabledStatus(const Scu_Hw_CPUType_t CPU, Scu_Hw_Trap_t Trap);
void     Scu_Hw_TriggerTrap(Scu_Hw_Trap_t Trap);
void     Scu_Hw_ClearTrapFlag(Scu_Hw_Trap_t Trap);
bool     Scu_Hw_GetTrapTriggerFlag(Scu_Hw_Trap_t Trap);
void     Scu_Hw_SafetyEmergencyStopFlagSelect(Scu_Hw_EmergencyStopFlag_t Select);
void     Scu_Hw_EmergencyStopFlagSelect(Scu_Hw_EmergencyStopFlag_t Select);
void     Scu_Hw_SetEmergencyStopInputPolarity(Scu_Hw_EmergencyStopInputPolarity_t Polarity);
void     Scu_Hw_SetEmergencyStopMode(Scu_Hw_EmergencyStopMode_t Mode);
void     Scu_Hw_SetEmergencyStopFlagEnabled(bool State);
void     Scu_Hw_EmergencyStopPortSelect(Scu_Hw_EmergencyStopPort_t Select);
void     Scu_Hw_SetERUFilterPinEnabled(Scu_Hw_EruFilterPin_t Pin, bool State);
bool     Scu_Hw_GetERUFilterPinEnabled(Scu_Hw_EruFilterPin_t Pin);
void     Scu_Hw_SetERUFilterClkDiv(Scu_Hw_EruFilterClkDiv_t Div);
void     Scu_Hw_SetERUFilterDepth(Scu_Hw_EruFilterDepth_t Depth);
void     Scu_Hw_SelectEruExternalInput(Scu_Hw_EruInputChannel_t InputChannel, Scu_Hw_EruInputSelect_t Signal);
bool     Scu_Hw_GetSafetyEmergencyStopFlag(void);
bool     Scu_Hw_GetEmergencyStopFlag(void);

#ifdef __cplusplus
}
#endif

#endif

/* EOF */
