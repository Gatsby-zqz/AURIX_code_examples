/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_adcs.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-07
 *  @Version         : V0.0.1.231207_alpha
 *  @Description     : This document describes the C language document template
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2023-12-07    |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/
#ifndef KF32DA13K_DRV_ADCS_H_
#define KF32DA13K_DRV_ADCS_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a13k_reg_adcs.h"

#ifdef KF_DRV_ADCS_ASSERT
#include "dev_assert.h"
#define KF_DRV_ADCS_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_ADCS_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    ADC0,
    ADC1,
    ADC2,
    ADC3,
} Adcs_Module_t;
#define CHECK_ADC_MODULE(MODULE) (!(MODULE >> 2U))

typedef enum
{
    ADCS_CHANNEL_0,
    ADCS_CHANNEL_1,
    ADCS_CHANNEL_2,
    ADCS_CHANNEL_3,
    ADCS_CHANNEL_4,
    ADCS_CHANNEL_5,
    ADCS_CHANNEL_6,
    ADCS_CHANNEL_7,
    ADCS_CHANNEL_8,
    ADCS_CHANNEL_9,
    ADCS_CHANNEL_10,
    ADCS_CHANNEL_11,
    ADCS_CHANNEL_12,
    ADCS_CHANNEL_13,
    ADCS_CHANNEL_14,
    ADCS_CHANNEL_15,
} Adcs_Channel_t;
#define CHECK_ADC_CHANNEL(CHANNEL) (!(CHANNEL >> 4U))

typedef enum
{
    ADCS_RESULT_REG_0,
    ADCS_RESULT_REG_1,
    ADCS_RESULT_REG_2,
    ADCS_RESULT_REG_3,
    ADCS_RESULT_REG_4,
    ADCS_RESULT_REG_5,
    ADCS_RESULT_REG_6,
    ADCS_RESULT_REG_7,
    ADCS_RESULT_REG_8,
    ADCS_RESULT_REG_9,
    ADCS_RESULT_REG_10,
    ADCS_RESULT_REG_11,
    ADCS_RESULT_REG_12,
    ADCS_RESULT_REG_13,
    ADCS_RESULT_REG_14,
    ADCS_RESULT_REG_15,
} Adcs_Result_Reg_t;
#define CHECK_ADC_RESULT_REG(REG) (!(REG >> 4U))

typedef enum
{
    ADCS_QUEUE_0,
    ADCS_QUEUE_1,
    ADCS_QUEUE_2,
} Adcs_Queue_t;
#define CHECK_ADC_QUEUE(QUEUE) ((uint32_t)QUEUE <= ADCS_QUEUE_2)

typedef enum
{
    ADCS_OTGB01_TRIGGER_0,
    ADCS_OTGB01_TRIGGER_1,
    ADCS_OTGB01_TRIGGER_2,
} Adcs_OTGB01_Trigger_t;
#define CHECK_ADC_OTGB_TRIGGER(TRIGGER) ((uint32_t)TRIGGER <= ADCS_OTGB01_TRIGGER_2)

typedef enum
{
    ADCS_OTGB01_BUS_0,
    ADCS_OTGB01_BUS_1,
} Adcs_OTGB01_Bus_t;
#define CHECK_ADC_OTGB_BUS(BUS) (!(BUS >> 1U))

typedef enum
{
    ADCS_SUSPEND_MODE_NONE,
    ADCS_SUSPEND_MODE_HARD,
    ADCS_SUSPEND_MODE_SOFT,
} Adcs_SuspendMode_t;
#define CHECK_ADC_SUSPENDMODE(MODE) ((uint32_t)MODE <= ADCS_SUSPEND_MODE_SOFT)

typedef enum
{
    ADCS_MASTER_TAG_ID0,
    ADCS_MASTER_TAG_ID1,
    ADCS_MASTER_TAG_ID2,
    ADCS_MASTER_TAG_ID3,
    ADCS_MASTER_TAG_ID4,
    ADCS_MASTER_TAG_ID5,
    ADCS_MASTER_TAG_ID6,
    ADCS_MASTER_TAG_ID7,
    ADCS_MASTER_TAG_ID8,
    ADCS_MASTER_TAG_ID9,
    ADCS_MASTER_TAG_ID10,
    ADCS_MASTER_TAG_ID11,
    ADCS_MASTER_TAG_ID12,
    ADCS_MASTER_TAG_ID13,
    ADCS_MASTER_TAG_ID14,
    ADCS_MASTER_TAG_ID15,
    ADCS_MASTER_TAG_ID16,
    ADCS_MASTER_TAG_ID17,
    ADCS_MASTER_TAG_ID18,
    ADCS_MASTER_TAG_ID19,
    ADCS_MASTER_TAG_ID20,
    ADCS_MASTER_TAG_ID21,
    ADCS_MASTER_TAG_ID22,
    ADCS_MASTER_TAG_ID23,
    ADCS_MASTER_TAG_ID24,
    ADCS_MASTER_TAG_ID25,
    ADCS_MASTER_TAG_ID26,
    ADCS_MASTER_TAG_ID27,
    ADCS_MASTER_TAG_ID28,
    ADCS_MASTER_TAG_ID29,
    ADCS_MASTER_TAG_ID30,
    ADCS_MASTER_TAG_ID31,
} Adcs_MasterTAGId_t;
#define CHECK_ADCS_MASTERTAG_ID(ID) ((uint32_t)ID <= ADCS_MASTER_TAG_ID31)

typedef enum
{
    ADCS_ANALOG_CLOCK_MODE_SYNCHRONIZE,
    ADCS_ANALOG_CLOCK_MODE_UNSYNCHRONIZE,
} Adcs_AnalogClockMode_t;
#define CHECK_ADC_ANALOG_CLOCK_MODE(MODE) (!(MODE >> 1U))

typedef enum
{
    ADCS_SUPPLY_VOLTAGE_LEVEL_AUTO,
    ADCS_SUPPLY_VOLTAGE_LEVEL_UPPER,
    ADCS_SUPPLY_VOLTAGE_LEVEL_LOWER,
} Adcs_SupplyVoltageLevelControl_t;
#define CHECK_ADC_SUPPLY_VOLTAGE_LEVEL(VOLTAGE) ((uint32_t)VOLTAGE <= ADCS_SUPPLY_VOLTAGE_LEVEL_LOWER)

typedef enum
{
    ADCS_STARTUP_CALIBRATION_NOACTION,
    ADCS_STARTUP_CALIBRATION_INITIATE,
} Adcs_StartupCalibration_t;
#define CHECK_ADC_STARTUP_CALIBRATION(x) (!(x >> 1U))

#define CHECK_ADC_BOUNDARY_LIMIT(BOUNDARY) (!(BOUNDARY >> 11))

typedef struct
{
    Adcs_AnalogClockMode_t           AnalogClockMode;
    Adcs_SupplyVoltageLevelControl_t SupplyVoltageLevel;
    Adcs_StartupCalibration_t        CalibrationControl;
} Adcs_GlobalConfig_t;

typedef enum
{
    ADCS_GLB_RESULT_COMMON_GROUP0_SERVICE_LINE_0,
    ADCS_GLB_RESULT_COMMON_GROUP0_SERVICE_LINE_1,
    ADCS_GLB_RESULT_COMMON_GROUP0_SERVICE_LINE_2,
    ADCS_GLB_RESULT_COMMON_GROUP0_SERVICE_LINE_3,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_0,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_1,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_2,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_3,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_0,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_1,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_2,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_3,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_4,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_5,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_6,
    ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_7,
} Adcs_GlobalResultServiceLine_t;
#define CHECK_ADC_GLB_RESULT_SERVICE_LINE(LINE) (!(LINE >> 4))

typedef enum
{
    ADCS_DIAGNOSTIC_PULL_DEVICE_VDDM,
    ADCS_DIAGNOSTIC_PULL_DEVICE_VSSM,
    ADCS_DIAGNOSTIC_PULL_DEVICE_VDDM_DIV2,
    ADCS_DIAGNOSTIC_PULL_DEVICE_VDDM_DIV3_MULT2,
} Adcs_DiagPullDevice_t;
#define CHECK_ADC_DIAGNOSTIC_PULL_DEVICE(DEVICE) (!(DEVICE >> 2))

typedef enum
{
    ADCS_EMUX_INTERFACE_0,
    ADCS_EMUX_INTERFACE_1,
} Adcs_EmuxInterface_t;
#define CHECK_ADC_EMUX_INTERFACE(INTERFACE) (!(INTERFACE >> 1))

typedef enum
{
    ADCS_EMUX_PORT_0,
    ADCS_EMUX_PORT_1,
    ADCS_EMUX_PORT_2,
    ADCS_EMUX_PORT_3,
    ADCS_EMUX_PORT_4,
    ADCS_EMUX_PORT_5,
    ADCS_EMUX_PORT_6,
    ADCS_EMUX_PORT_7,
    ADCS_EMUX_PORT_8,
    ADCS_EMUX_PORT_9,
    ADCS_EMUX_PORT_10,
    ADCS_EMUX_PORT_11,
    ADCS_EMUX_PORT_12,
    ADCS_EMUX_PORT_13,
    ADCS_EMUX_PORT_14,
    ADCS_EMUX_PORT_15,
} Adcs_EmuxInterfacePort_t;
#define CHECK_ADC_EMUX_PORT(PORT) (!(PORT >> 4))

typedef enum
{
    ADCS_INNER_TRIGGER_SOURCE_0,
    ADCS_INNER_TRIGGER_SOURCE_1,
} Adcs_InnerTriggerSource_t;
#define CHECK_ADC_INNER_TRIGGER_SOURCE(SOURCE) (!(SOURCE >> 1))

typedef enum
{
    ADCS_ANALOG_CONVERTER_MODE_OFF,
    ADCS_ANALOG_CONVERTER_MODE_SLOW_STANDBY,
    ADCS_ANALOG_CONVERTER_MODE_FAST_STANDBY,
    ADCS_ANALOG_CONVERTER_MODE_NORMAL,
} Adcs_AnalogConverterMode_t;
#define CHECK_ADC_ANALOG_CONVERTER_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    ADCS_CURRENT_CONVERT_REQ_SOURCE_QUEUE0,
    ADCS_CURRENT_CONVERT_REQ_SOURCE_QUEUE1,
    ADCS_CURRENT_CONVERT_REQ_SOURCE_QUEUE2,
    ADCS_CURRENT_CONVERT_REQ_SOURCE_SYNC,
} Adcs_CurrentConvertedRequestSource_t;
#define CHECK_ADC_CURRENT_CONVERT_REQ_SOURCE(SOURCE) (!(SOURCE >> 2))

typedef enum
{
    ADCS_ARBITRATE_PRIORITY_0,
    ADCS_ARBITRATE_PRIORITY_1,
    ADCS_ARBITRATE_PRIORITY_2,
    ADCS_ARBITRATE_PRIORITY_3,
} Adcs_ArbitratePriority_t;
#define CHECK_ADC_ARBITRATE_PRIORITY(PRIORITY) (!(PRIORITY >> 2))

typedef enum
{
    ADCS_ARBITRATE_MODE_WAIT_FOR_START,
    ADCS_ARBITRATE_MODE_CANCEL_INJECT_REPEAT,
} Adcs_ArbitrateMode_t;
#define CHECK_ADC_ARBITRATE_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    ADCS_IDLE_PRECHARGE_CURRENTLEVEL,
    ADCS_IDLE_PRECHARGE_REFERENCE_DIV2,
} Adcs_IdlePrechargeMode_t;
#define CHECK_ADC_IDLE_PRECHARGE_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    ADCS_ANALOG_CLOCK_SYNC_DELAY_0,
    ADCS_ANALOG_CLOCK_SYNC_DELAY_1,
    ADCS_ANALOG_CLOCK_SYNC_DELAY_2,
    ADCS_ANALOG_CLOCK_SYNC_DELAY_3,
    ADCS_ANALOG_CLOCK_SYNC_DELAY_4,
    ADCS_ANALOG_CLOCK_SYNC_DELAY_5,
    ADCS_ANALOG_CLOCK_SYNC_DELAY_6,
    ADCS_ANALOG_CLOCK_SYNC_DELAY_7,
} Adcs_AnalogClockSyncDelay_t;
#define CHECK_ADCS_ANALOG_CLOCK_SYNC_DELAY(DELAY) ((uint32_t)DELAY <= ADCS_ANALOG_CLOCK_SYNC_DELAY_7)

typedef enum
{
    ADCS_ANALOG_CLOCK_DIVIDER_2_1,
    ADCS_ANALOG_CLOCK_DIVIDER_2,
    ADCS_ANALOG_CLOCK_DIVIDER_3,
    ADCS_ANALOG_CLOCK_DIVIDER_4,
    ADCS_ANALOG_CLOCK_DIVIDER_5,
    ADCS_ANALOG_CLOCK_DIVIDER_6,
    ADCS_ANALOG_CLOCK_DIVIDER_7,
    ADCS_ANALOG_CLOCK_DIVIDER_8,
    ADCS_ANALOG_CLOCK_DIVIDER_9,
    ADCS_ANALOG_CLOCK_DIVIDER_10,
    ADCS_ANALOG_CLOCK_DIVIDER_11,
    ADCS_ANALOG_CLOCK_DIVIDER_12,
    ADCS_ANALOG_CLOCK_DIVIDER_13,
    ADCS_ANALOG_CLOCK_DIVIDER_14,
    ADCS_ANALOG_CLOCK_DIVIDER_15,
    ADCS_ANALOG_CLOCK_DIVIDER_16,
    ADCS_ANALOG_CLOCK_DIVIDER_17,
    ADCS_ANALOG_CLOCK_DIVIDER_18,
    ADCS_ANALOG_CLOCK_DIVIDER_19,
    ADCS_ANALOG_CLOCK_DIVIDER_20,
    ADCS_ANALOG_CLOCK_DIVIDER_21,
    ADCS_ANALOG_CLOCK_DIVIDER_22,
    ADCS_ANALOG_CLOCK_DIVIDER_23,
    ADCS_ANALOG_CLOCK_DIVIDER_25,
    ADCS_ANALOG_CLOCK_DIVIDER_26,
    ADCS_ANALOG_CLOCK_DIVIDER_27,
    ADCS_ANALOG_CLOCK_DIVIDER_28,
    ADCS_ANALOG_CLOCK_DIVIDER_29,
    ADCS_ANALOG_CLOCK_DIVIDER_30,
    ADCS_ANALOG_CLOCK_DIVIDER_31,
    ADCS_ANALOG_CLOCK_DIVIDER_32,
} Adcs_AnalogClockDivider_t;
#define CHECK_ADC_ANALOG_CLOCK_DIVIDER(DIVIDE) (!(DIVIDE >> 5))

#define CHECK_ADC_ALIAS(ALIAS) (!(ALIAS >> 5))

typedef enum
{
    ADCS_SYNC_MASTER_SELF,
    ADCS_SYNC_MASTER_CI1,
    ADCS_SYNC_MASTER_CI2,
    ADCS_SYNC_MASTER_CI3,
} Adcs_SyncMasterIndex_t;
#define CHECK_ADC_SYNC_MASTER_INDEX(INDEX) (!(INDEX >> 2))

typedef enum
{
    ADCS_RESULT_REGISTER_CH_RESTGT,
    ADCS_RESULT_REGISTER_1,
    ADCS_RESULT_REGISTER_2,
    ADCS_RESULT_REGISTER_3,
    ADCS_RESULT_REGISTER_4,
    ADCS_RESULT_REGISTER_5,
    ADCS_RESULT_REGISTER_6,
    ADCS_RESULT_REGISTER_7,
    ADCS_RESULT_REGISTER_8,
    ADCS_RESULT_REGISTER_9,
    ADCS_RESULT_REGISTER_10,
    ADCS_RESULT_REGISTER_11,
    ADCS_RESULT_REGISTER_12,
    ADCS_RESULT_REGISTER_13,
    ADCS_RESULT_REGISTER_14,
    ADCS_RESULT_REGISTER_15,
} Adcs_Queue_ResultRegister_t;
#define CHECK_ADC_QUEUE_RESULT_REGISTER(REGISTER) (!(REGISTER >> 4))

typedef enum
{
    ADCS_QUEUE_TRIGGER_SOURCE_EXTERN,
    ADCS_QUEUE_TRIGGER_SOURCE_NEXT,
    ADCS_QUEUE_TRIGGER_SOURCE_LAST,
    ADCS_QUEUE_TRIGGER_SOURCE_PREVIOUS,
} Adcs_Queue_TriggerSource_t;
#define CHECK_ADC_QUEUE_TRIGGER_SOURCE(TRIGGER) (!(TRIGGER >> 2))

typedef enum
{
    ADCS_QUEUE_TRIGGER_MODE_NO_TRIGGER,
    ADCS_QUEUE_TRIGGER_MODE_RISE,
    ADCS_QUEUE_TRIGGER_MODE_FALL,
    ADCS_QUEUE_TRIGGER_MODE_EITHER,
} Adcs_Queue_TriggerMode_t;
#define CHECK_ADC_QUEUE_TRIGGER_MODE(MODE) (!(MODE >> 2))

#define CHECK_ADC_QUEUE_EXTERNAL_TRIGGER_SOURCE(TRIGGER) (!(TRIGGER >> 7))
#define CHECK_ADC_QUEUE_GATING_SOURCE(SOURCE)            (!(SOURCE >> 7))

typedef enum
{
    ADCS_QUEUE_GATING_DISABLE,
    ADCS_QUEUE_GATING_EITHER,
    ADCS_QUEUE_GATING_HIGH,
    ADCS_QUEUE_GATING_LOW,
} Adcs_Queue_GatingMode_t;
#define CHECK_ADC_QUEUE_GATING_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    ADCS_QUEUE_TIMER_FALL,
    ADCS_QUEUE_TIMER_RISE,
} Adcs_Queue_TimerEdge_t;
#define CHECK_ADC_QUEUE_TIMER_EDGE(MODE) (!(MODE >> 1))

typedef enum
{
    ADCS_QUEUE_REG_REFILL_DISABLED,
    ADCS_QUEUE_REG_REFILL_ENABLED,
} Adcs_Queue_Reg_Refill_t;
#define CHECK_ADC_QUEUE_REFILL(STATUS) (!(STATUS >> 1))

typedef enum
{
    ADCS_QUEUE_REG_SOURCE_INTERRUPT_DISABLED,
    ADCS_QUEUE_REG_SOURCE_INTERRUPT_ENABLED,
} Adcs_Queue_Reg_SourceInterruptEnable_t;
#define CHECK_ADC_QUEUE_SOURCE_INTERRUPT_ENABLE(STATUS) (!(STATUS >> 1))

typedef enum
{
    ADCS_QUEUE_REG_EXTERN_TRIGGER_WAIT_DISABLED,
    ADCS_QUEUE_REG_EXTERN_TRIGGER_WAIT_ENABLED,
} Adcs_Queue_Reg_ExternTriggerWaitEnable_t;
#define CHECK_ADC_QUEUE_EXTERN_TRIGGER_WAIT_ENABLE(STATUS) (!(STATUS >> 1))

typedef union
{
    struct
    {
        uint32_t              RequestChannelNumber           :5;
        bool                  RefillEnabled                  :1;
        bool                  SourceInterruptEnabled         :1;
        bool                  ExternTriggerWaitEnabled       :1;
        bool                  ConvertValid                   :1;
        bool                  PullDownEnabled                :1;
        bool                  MultiplexerDiagPullDownEnabled :1;
        bool                  MultiplexerDiagPullUpEnabled   :1;
        bool                  ConvertDiagEnabled             :1;
        Adcs_DiagPullDevice_t DiagPullDevice                 :2;
        uint32_t              Reserve                        :17;
    } bits;
    uint32_t reg;
} Adcs_Queue_Reg_t;

typedef union
{
    struct
    {
        uint32_t              RequestChannelNumber           :5;
        bool                  RefillEnabled                  :1;
        bool                  SourceInterruptEnabled         :1;
        bool                  ExternTriggerWaitEnabled       :1;
        uint32_t              Reserve0                       :1;
        bool                  PullDownEnabled                :1;
        bool                  MultiplexerDiagPullDownEnabled :1;
        bool                  MultiplexerDiagPullUpEnabled   :1;
        bool                  ConvertDiagEnabled             :1;
        Adcs_DiagPullDevice_t DiagPullDevice                 :2;
        uint32_t              Reserve1                       :17;
    } bits;
    uint32_t reg;
} Adcs_Queue_InputReg_t;

typedef enum
{
    ADCS_QUEUE_SEQUENCE_MODE_DISABLED,
    ADCS_QUEUE_SEQUENCE_MODE_1,
    ADCS_QUEUE_SEQUENCE_MODE_2,
    ADCS_QUEUE_SEQUENCE_MODE_3,
} Adcs_Queue_SequenceMode_t;
#define CHECK_ADC_QUEUE_SEQUENCE_MODE(MODE) (!(MODE >> 2))

#define CHECK_ADC_QUEUE_SEQUENCE_START_VALUE(VALUE)      (!(VALUE >> 10))
#define CHECK_ADC_QUEUE_SEQUENCE_SWITCH_OFF_VALUE(VALUE) (!(VALUE >> 10))

typedef enum
{
    ADCS_CHANNEL_EVENT_MODULE_SERVICE_LINE_0,
    ADCS_CHANNEL_EVENT_MODULE_SERVICE_LINE_1,
    ADCS_CHANNEL_EVENT_MODULE_SERVICE_LINE_2,
    ADCS_CHANNEL_EVENT_MODULE_SERVICE_LINE_3,
    ADCS_CHANNEL_EVENT_COMMON_SERVICE_LINE_0,
    ADCS_CHANNEL_EVENT_COMMON_SERVICE_LINE_1,
    ADCS_CHANNEL_EVENT_COMMON_SERVICE_LINE_2,
    ADCS_CHANNEL_EVENT_COMMON_SERVICE_LINE_3,
    ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_0,
    ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_1,
    ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_2,
    ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_3,
    ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_4,
    ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_5,
    ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_6,
    ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_7,
} Adcs_ChannelEventServiceLine_t;
#define CHECK_ADC_CHANNEL_EVENT_SERVICE_LINE(LINE) (!(LINE >> 4))

typedef enum
{
    ADCS_RESULT_EVENT_MODULE_SERVICE_LINE_0,
    ADCS_RESULT_EVENT_MODULE_SERVICE_LINE_1,
    ADCS_RESULT_EVENT_MODULE_SERVICE_LINE_2,
    ADCS_RESULT_EVENT_MODULE_SERVICE_LINE_3,
    ADCS_RESULT_EVENT_COMMON_SERVICE_LINE_0,
    ADCS_RESULT_EVENT_COMMON_SERVICE_LINE_1,
    ADCS_RESULT_EVENT_COMMON_SERVICE_LINE_2,
    ADCS_RESULT_EVENT_COMMON_SERVICE_LINE_3,
    ADCS_RESULT_EVENT_SERVICE_LINE_OFF_0,
    ADCS_RESULT_EVENT_SERVICE_LINE_OFF_1,
    ADCS_RESULT_EVENT_SERVICE_LINE_OFF_2,
    ADCS_RESULT_EVENT_SERVICE_LINE_OFF_3,
    ADCS_RESULT_EVENT_SERVICE_LINE_OFF_4,
    ADCS_RESULT_EVENT_SERVICE_LINE_OFF_5,
    ADCS_RESULT_EVENT_SERVICE_LINE_OFF_6,
    ADCS_RESULT_EVENT_SERVICE_LINE_OFF_7,
} Adcs_ResultEventServiceLine_t;
#define CHECK_ADC_RESULT_EVENT_SERVICE_LINE(LINE) (!(LINE >> 4))

typedef enum
{
    ADCS_SOURCE_EVENT_MODULE_SERVICE_LINE_0,
    ADCS_SOURCE_EVENT_MODULE_SERVICE_LINE_1,
    ADCS_SOURCE_EVENT_MODULE_SERVICE_LINE_2,
    ADCS_SOURCE_EVENT_MODULE_SERVICE_LINE_3,
    ADCS_SOURCE_EVENT_COMMON_SERVICE_LINE_0,
    ADCS_SOURCE_EVENT_COMMON_SERVICE_LINE_1,
    ADCS_SOURCE_EVENT_COMMON_SERVICE_LINE_2,
    ADCS_SOURCE_EVENT_COMMON_SERVICE_LINE_3,
    ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_0,
    ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_1,
    ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_2,
    ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_3,
    ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_4,
    ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_5,
    ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_6,
    ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_7,
} Adcs_SourceEventServiceLine_t;
#define CHECK_ADC_SOURCE_EVENT_SERVICE_LINE(LINE) (!(LINE >> 4))

typedef enum
{
    ADCS_SOFT_TRIGGER_MODULE_SERVICE_LINE_0,
    ADCS_SOFT_TRIGGER_MODULE_SERVICE_LINE_1,
    ADCS_SOFT_TRIGGER_MODULE_SERVICE_LINE_2,
    ADCS_SOFT_TRIGGER_MODULE_SERVICE_LINE_3,
    ADCS_SOFT_TRIGGER_COMMON_SERVICE_LINE_0,
    ADCS_SOFT_TRIGGER_COMMON_SERVICE_LINE_1,
    ADCS_SOFT_TRIGGER_COMMON_SERVICE_LINE_2,
    ADCS_SOFT_TRIGGER_COMMON_SERVICE_LINE_3,
} Adcs_SoftTriggerServiceLine_t;
#define CHECK_ADC_SOFT_TRIGGER_SERVICE_LINE(LINE) (!(LINE >> 3))

typedef enum
{
    ADCS_EXTERN_MUX_MODE_SOFT_CONTROL,
    ADCS_EXTERN_MUX_MODE_SOFT_STEADY,
    ADCS_EXTERN_MUX_MODE_SOFT_SINGLE_STEP,
    ADCS_EXTERN_MUX_MODE_SOFT_SEQUENCE,
    ADCS_EXTERN_MUX_MODE_SOFT_BLOCK,
} Adcs_ExternMuxMode_t;
#define CHECK_ADC_EMUX_MODE(MODE) ((uint32_t)MODE <= ADCS_EXTERN_MUX_MODE_SOFT_BLOCK)

typedef enum
{
    ADCS_EXTERN_MUX_CODING_BINARY,
    ADCS_EXTERN_MUX_CODING_GRAY,
} Adcs_ExternMuxCodingScheme_t;
#define CHECK_ADC_EMUX_CODING(CODING) (!(CODING >> 1))

typedef enum
{
    ADCS_EXTERN_MUX_SAMPLE_TIME_SETTING_CHANGE,
    ADCS_EXTERN_MUX_SAMPLE_TIME_ALWAYS,
} Adcs_ExternMuxSampleTime_t;
#define CHECK_ADC_EMUX_SAMPLE_TIME(TIME) (!(TIME >> 1))

typedef enum
{
    ADCS_EXTERN_MUX_SELECT_CHANNEL_0,
    ADCS_EXTERN_MUX_SELECT_CHANNEL_1,
    ADCS_EXTERN_MUX_SELECT_CHANNEL_2,
    ADCS_EXTERN_MUX_SELECT_CHANNEL_3,
    ADCS_EXTERN_MUX_SELECT_CHANNEL_4,
    ADCS_EXTERN_MUX_SELECT_CHANNEL_5,
    ADCS_EXTERN_MUX_SELECT_CHANNEL_6,
    ADCS_EXTERN_MUX_SELECT_CHANNEL_7,
} Adcs_ExternMuxSelectChannel_t;
#define CHECK_ADC_EMUX_SELECT_CHANNEL(CHANNEL) (!(CHANNEL >> 3))

typedef enum
{
    ADCS_CHANNEL_BOUNDARY_GROUP0,
    ADCS_CHANNEL_BOUNDARY_GROUP1,
    ADCS_CHANNEL_BOUNDARY_GLOBAL0,
    ADCS_CHANNEL_BOUNDARY_GLOBAL1,
} Adcs_BoundarySelection_t;
#define CHECK_ADC_CHANNEL_BOUNDARY(BOUNDARY) (!(BOUNDARY >> 2))

typedef enum
{
    ADCS_CHANNEL_COMPARE_MODE_NOCHECK,
    ADCS_CHANNEL_COMPARE_MODE_EVENT_IN_AREA,
    ADCS_CHANNEL_COMPARE_MODE_EVENT_OUT_AREA,
    ADCS_CHANNEL_COMPARE_MODE_EVENT_ALWAYS,
} Adcs_ChannelCompareMode_t;
#define CHECK_ADC_CHANNEL_COMPARE_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    ADCS_CHANNEL_REFERENCE_VOLT_VAREF,
    ADCS_CHANNEL_REFERENCE_VOLT_CHANNEL0,
} Adcs_ChannelReferenceVolt_t;
#define CHECK_ADC_CHANNEL_REFERENCE_VOLT(VOLT) (!(VOLT >> 1))

typedef enum
{
    ADCS_CHANNEL_UPPER_BOUNDARY_BNDSELU,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES1,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES2,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES3,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES4,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES5,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES6,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES7,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES8,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES9,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES10,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES11,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES12,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES13,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES14,
    ADCS_CHANNEL_UPPER_BOUNDARY_RES15,
} Adcs_ChannelUpperBoundarySelection_t;
#define CHECK_ADC_CHANNEL_UPPER_BOUNDARY(BOUNDARY) (!(BOUNDARY >> 4))

typedef enum
{
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_0,
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_1,
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_2,
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_4,
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_8,
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_16,
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_32,
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_64,
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_128,
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_256,
    ADCS_CHANNEL_ADDITION_SAMPLE_TIME_512,
} Adcs_ChannelSampleTime_t;
#define CHECK_ADCS_CHANNEL_ADDITION_SAMPLE_TIME(TIME) ((uint32_t)TIME <= ADCS_CHANNEL_ADDITION_SAMPLE_TIME_512)

typedef enum
{
    ADCS_CHANNEL_PRECHARGE_MODE_INPUT = 1,
    ADCS_CHANNEL_PRECHARGE_MODE_VAREF = 2,
    ADCS_CHANNEL_PRECHARGE_MODE_VAGND = 3,
} Adcs_ChannelPrechargeMode_t;
#define CHECK_ADC_CHANNEL_PRECHARGE_MODE(MODE) ((!(MODE >> 2)) && (MODE))

typedef enum
{
    ADCS_RESULT_DATA_REDUCTION_0,
    ADCS_RESULT_DATA_REDUCTION_2,
    ADCS_RESULT_DATA_REDUCTION_3,
    ADCS_RESULT_DATA_REDUCTION_4,
    ADCS_RESULT_DATA_REDUCTION_5,
    ADCS_RESULT_DATA_REDUCTION_6,
    ADCS_RESULT_DATA_REDUCTION_7,
    ADCS_RESULT_DATA_REDUCTION_8,
    ADCS_RESULT_DATA_REDUCTION_9,
    ADCS_RESULT_DATA_REDUCTION_10,
    ADCS_RESULT_DATA_REDUCTION_11,
    ADCS_RESULT_DATA_REDUCTION_12,
    ADCS_RESULT_DATA_REDUCTION_13,
    ADCS_RESULT_DATA_REDUCTION_14,
    ADCS_RESULT_DATA_REDUCTION_15,
    ADCS_RESULT_DATA_REDUCTION_16,
} Adcs_ResultDataReduction_t;
#define CHECK_ADC_RESULT_DATA_REDUCTION(REDUCTION) (!(REDUCTION >> 4))

typedef enum
{
    ADCS_RESULT_DATA_FIR_COEFF_0,
    ADCS_RESULT_DATA_FIR_COEFF_1,
    ADCS_RESULT_DATA_FIR_COEFF_2,
    ADCS_RESULT_DATA_FIR_COEFF_3,
    ADCS_RESULT_DATA_FIR_COEFF_4,
    ADCS_RESULT_DATA_FIR_COEFF_5,
    ADCS_RESULT_DATA_FIR_COEFF_6,
    ADCS_RESULT_DATA_FIR_COEFF_7,
    ADCS_RESULT_DATA_FIR_COEFF_8,
    ADCS_RESULT_DATA_FIR_COEFF_9,
    ADCS_RESULT_DATA_FIR_COEFF_10,
    ADCS_RESULT_DATA_FIR_COEFF_11,
    ADCS_RESULT_DATA_FIR_COEFF_12,
    ADCS_RESULT_DATA_FIR_COEFF_13,
    ADCS_RESULT_DATA_IIR_COEFF_0,
    ADCS_RESULT_DATA_IIR_COEFF_1,
} Adcs_ResultDataFIRCoeff_t;
#define CHECK_ADC_RESULT_DATA_FIR_COEFF(COEFF) (!(COEFF >> 4))

typedef enum
{
    ADCS_RESULT_STANDARD_REDUCTION,
    ADCS_RESULT_DATA_FILTER,
    ADCS_RESULT_DIFFERENTIAL,
} Adcs_ResultDataModificationMode_t;
#define CHECK_ADC_RESULT_DATA_MODIFICATION_MODE(MODE) ((uint32_t)REDUCTION <= ADCS_RESULT_DIFFERENTIAL)

typedef enum
{
    ADCS_RESULT_FIFO_SEPERATE_RESULT_REG,
    ADCS_RESULT_FIFO_FIFO_STRUCTURE,
    ADCS_RESULT_FIFO_MAX_MODE,
    ADCS_RESULT_FIFO_MIN_MODE,
} Adcs_ResultFifoMode_t;
#define CHECK_ADC_RESULT_FIFO_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    ADCS_CMP_SAMPLE_TIME_0,
    ADCS_CMP_SAMPLE_TIME_1,
    ADCS_CMP_SAMPLE_TIME_2,
    ADCS_CMP_SAMPLE_TIME_4,
    ADCS_CMP_SAMPLE_TIME_8,
    ADCS_CMP_SAMPLE_TIME_16,
    ADCS_CMP_SAMPLE_TIME_32,
    ADCS_CMP_SAMPLE_TIME_64,
    ADCS_CMP_SAMPLE_TIME_128,
    ADCS_CMP_SAMPLE_TIME_256,
    ADCS_CMP_SAMPLE_TIME_512,
} Adcs_CMPSampleTime_t;
#define CHECK_ADCS_CMP_SAMPLE_TIME(TIME) ((uint32_t)TIME <= ADCS_CMP_SAMPLE_TIME_512)

typedef enum
{
    ADCS_CMP_PRECHARGE_MODE_OFF,
    ADCS_CMP_PRECHARGE_MODE_INPUT,
    ADCS_CMP_PRECHARGE_MODE_VAREF,
    ADCS_CMP_PRECHARGE_MODE_VAGND,
} Adcs_CmpChannelPrechargeMode_t;
#define CHECK_ADC_CMP_RECHARGE_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    ADCS_CMP_CHANNEL_EVENT_NEVER,
    ADCS_CMP_CHANNEL_EVENT_ABOVE_COMPARE_VALUE,
    ADCS_CMP_CHANNEL_EVENT_BELOW_COMPARE_VALUE,
    ADCS_CMP_CHANNEL_EVENT_ABOVE_OR_BELOW_COMPARE_VALUE,
} Adcs_CMPChannelEventMode_t;
#define CHECK_ADC_CMP_CHANNEL_EVENT_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_2_1,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_2,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_3,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_4,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_5,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_6,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_7,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_8,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_9,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_10,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_11,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_12,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_13,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_14,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_15,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_16,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_17,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_18,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_19,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_20,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_21,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_22,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_23,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_25,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_26,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_27,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_28,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_29,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_30,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_31,
    ADCS_CMP_ANALOG_CLOCK_DIVIDER_32,
} Adcs_CMPAnalogClockDivider_t;
#define CHECK_ADC_CMP_ANALOG_CLOCK_DIVIDER(DIVIDE) (!(DIVIDE >> 5))

typedef enum
{
    ADCS_CMP_EXTERN_TRIGGER_A,
    ADCS_CMP_EXTERN_TRIGGER_B,
    ADCS_CMP_EXTERN_TRIGGER_C,
    ADCS_CMP_EXTERN_TRIGGER_D,
    ADCS_CMP_EXTERN_TRIGGER_E,
    ADCS_CMP_EXTERN_TRIGGER_F,
    ADCS_CMP_EXTERN_TRIGGER_G,
    ADCS_CMP_EXTERN_TRIGGER_H,
    ADCS_CMP_EXTERN_TRIGGER_I,
    ADCS_CMP_EXTERN_TRIGGER_J,
    ADCS_CMP_EXTERN_TRIGGER_K,
    ADCS_CMP_EXTERN_TRIGGER_L,
    ADCS_CMP_EXTERN_TRIGGER_M,
    ADCS_CMP_EXTERN_TRIGGER_N,
    ADCS_CMP_EXTERN_TRIGGER_O,
    ADCS_CMP_EXTERN_TRIGGER_P,
} Adcs_CMPExternTrigger_t;
#define CHECK_ADC_CMP_EXTERN_TRIGGER(TRIGGER) (!(TRIGGER >> 4))

typedef enum
{
    ADCS_CMP_TRIGGER_MODE_NO_TRIGGER,
    ADCS_CMP_TRIGGER_MODE_FALLING_EDGE,
    ADCS_CMP_TRIGGER_MODE_RISING_EDGE,
    ADCS_CMP_TRIGGER_MODE_ANY_EDGE,
} Adcs_CMPTriggerOperationMode_t;
#define CHECK_ADC_CMP_TRIGGER_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    ADCS_CMP_GATE_MODE_NO_GATE,
    ADCS_CMP_GATE_MODE_ALTERNATE_VALUE_MODE,
    ADCS_CMP_GATE_MODE_LOCK_BOUNDARY_VALUE_MODE,
} Adcs_CMPGateOperationMode_t;
#define CHECK_ADC_CMP_GATE_MOD(MODE) ((uint32_t)MODE <= ADCS_CMP_GATE_MODE_LOCK_BOUNDARY_VALUE_MODE)

#define CHECK_ADC_CMP_CHANNEL(CHANNEL) (!(CHANNEL >> 5))

typedef enum
{
    ADCS_CMP_STOP,
    ADCS_CMP_ALWAYS_RUN,
} Adcs_CMPRunMode_t;
#define CHECK_ADC_CMP_RUN_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    ADCS_CMP_RAMP_RUN_STOP,
    ADCS_CMP_RAMP_RUN_MODE_1,
    ADCS_CMP_RAMP_RUN_MODE_2,
    ADCS_CMP_RAMP_RUN_MODE_3,
} Adcs_CMPRampRunMode_t;
#define CHECK_ADC_CMP_RAMP_RUN_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    ADCS_CMP_RAMP_DOWN,
    ADCS_CMP_RAMP_UP,
} Adcs_CMPRampDirection_t;
#define CHECK_ADC_CMP_RAMP_DIRECTION(DIRECTION) (!(DIRECTION >> 1))

typedef enum
{
    ADCS_CMP_ANALOG_DELAY_0,
    ADCS_CMP_ANALOG_DELAY_1,
    ADCS_CMP_ANALOG_DELAY_2,
    ADCS_CMP_ANALOG_DELAY_3,
} Adcs_CMPAnalogClkDelay_t;
#define CHECK_ADC_CMP_ANALOG_DELAY(DELAY) (!(DELAY >> 2))

typedef enum
{
    ADCS_CMP_REQUEST_GENERATE_CONDITION_OFF,
    ADCS_CMP_REQUEST_GENERATE_CONDITION_RAMP_OFF,
    ADCS_CMP_REQUEST_GENERATE_CONDITION_NEW_VALUE,
    ADCS_CMP_REQUEST_GENERATE_CONDITION_NEW_RESULT,
} Adcs_CMPRequestGenerateCondition_t;
#define CHECK_ADC_CMP_REQUEST_GENERATE_CONDITION(CONDITION) (!(CONDITION >> 2))

typedef enum
{
    ADCS_CMP_AUTO_UPDATE_MODE_SOFTWARE,
    ADCS_CMP_AUTO_UPDATE_MODE_ALTERNATE_VALUE,
    ADCS_CMP_AUTO_UPDATE_MODE_RAMP_COUNTER,
    ADCS_CMP_AUTO_UPDATE_MODE_ANALOG_SOURCE,
} Adcs_CMPAutomaticUpdateMode_t;
#define CHECK_ADC_CMP_AUTO_UPDATE_MODE(MODE) (!(MODE >> 2))

#define CHECK_ADC_CMP_REFERENCE_VALUE(VALUE) (!(VALUE >> 10))

typedef enum
{
    ADCS_CMP_PRECHARGE_OFF,
    ADCS_CMP_PRECHARGE_CYCLE_1,
    ADCS_CMP_PRECHARGE_CYCLE_2,
    ADCS_CMP_PRECHARGE_CYCLE_3,
    ADCS_CMP_PRECHARGE_CYCLE_4,
    ADCS_CMP_PRECHARGE_CYCLE_5,
    ADCS_CMP_PRECHARGE_CYCLE_6,
    ADCS_CMP_PRECHARGE_CYCLE_7,
    ADCS_CMP_PRECHARGE_CYCLE_8,
    ADCS_CMP_PRECHARGE_CYCLE_9,
    ADCS_CMP_PRECHARGE_CYCLE_10,
    ADCS_CMP_PRECHARGE_CYCLE_11,
    ADCS_CMP_PRECHARGE_CYCLE_12,
    ADCS_CMP_PRECHARGE_CYCLE_13,
    ADCS_CMP_PRECHARGE_CYCLE_14,
    ADCS_CMP_PRECHARGE_CYCLE_15,
} Adcs_CMPPreChargeCycle_t;
#define CHECK_ADC_CMP_PRECHARGE_CYCLE(CYCLE) (!(CYCLE >> 4))

typedef enum
{
    ADCS_CMP_BOUNDARY_ACTIVATION_MODE_0,
    ADCS_CMP_BOUNDARY_ACTIVATION_MODE_1,
} Adcs_CMPBoundaryActivationMode_t;
#define CHECK_ADC_CMP_BOUNDARY_ACTIVATION_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    ADCS_CMP_BOUNDARY_FLAG_SW_CONTROL_NO_ACTION,
    ADCS_CMP_BOUNDARY_FLAG_SW_CONTROL_CLEAR,
    ADCS_CMP_BOUNDARY_FLAG_SW_CONTROL_SET,
    ADCS_CMP_BOUNDARY_FLAG_SW_CONTROL_TOGGLE,
} Adcs_CMPBoundaryFlagSwControl_t;
#define CHECK_ADC_CMP_BOUNDARY_FLAG_SW_CONTROL(CONTROL) (!(CONTROL >> 2))

#define CHECK_ADC_CMP_HYSTERESIS_VALUE(VALUE) (!(VALUE >> 10))

typedef enum
{
    ADCS_HYST_INDEX_CMP_VALUE,
    ADCS_HYST_INDEX_RAMP_END,
    ADCS_HYST_INDEX_FCR_EDGE,
} Adcs_HystGetIndex_t;
#define CHECK_ADCS_HYST_GET_INDEX(INDEX) ((uint32_t)INDEX <= ADCS_HYST_INDEX_FCR_EDGE)

typedef enum
{
    ADCS_CHANNEL_PRECHARGE_OFF,
    ADCS_CHANNEL_PRECHARGE_CYCLE_1,
    ADCS_CHANNEL_PRECHARGE_CYCLE_2,
    ADCS_CHANNEL_PRECHARGE_CYCLE_3,
    ADCS_CHANNEL_PRECHARGE_CYCLE_4,
    ADCS_CHANNEL_PRECHARGE_CYCLE_5,
    ADCS_CHANNEL_PRECHARGE_CYCLE_6,
    ADCS_CHANNEL_PRECHARGE_CYCLE_7,
    ADCS_CHANNEL_PRECHARGE_CYCLE_8,
    ADCS_CHANNEL_PRECHARGE_CYCLE_9,
    ADCS_CHANNEL_PRECHARGE_CYCLE_10,
    ADCS_CHANNEL_PRECHARGE_CYCLE_11,
    ADCS_CHANNEL_PRECHARGE_CYCLE_12,
    ADCS_CHANNEL_PRECHARGE_CYCLE_13,
    ADCS_CHANNEL_PRECHARGE_CYCLE_14,
    ADCS_CHANNEL_PRECHARGE_CYCLE_15,
} Adcs_ChannelPreChargeCycle_t;
#define CHECK_ADC_CHANNEL_PRECHARGE_CYCLE(CYCLE) (!(CYCLE >> 4))

typedef enum
{
    EMUX0,
    EMUX1,
} Adcs_ExternMux_t;
#define CHECK_ADC_EXTERN_MUX(MUX) (!(MUX >> 1))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/
/******************************************************************************
 *                      Local Variables
 ******************************************************************************/
/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

void Adcs_LL_SetSyncConvertMaster(const Adcs_Module_t CurrentModule, const Adcs_Module_t MasterModule);

/*  ADCS_CLKC_T */

/**
 * @brief Adcs模块使能/禁止
 * @param AdcModule:
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status:
 *        false   Adc 使能
 *        true    Adc 禁止
 * @retval void
 */
KF_INLINE void Adcs_LL_SetModuleDisabled(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_CLKC[AdcModule].bits.CLKEN, Status);
}

/**
 * @brief Adcs返回模块状态
 *
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @return
 *        false   Adc 模块时钟使能
 *        true    Adc 模块时钟禁止
 */
KF_INLINE bool Adcs_LL_GetModuleStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (ADCS_PTR->ADCS_CLKC[AdcModule].bits.STA == 0);
}

/**
 * @brief Adcs设置睡眠模式使能控制
 * @details 用于控制模块对睡眠信号的反应情况
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status:
 *        false   Adcs 睡眠模块请求信号有效
 *        true   Adcs 模块无视睡眠信号
 * @retval void
 */
KF_INLINE void Adcs_LL_SetSleepModeDisabled(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_CLKC[AdcModule].bits.SLPEN, Status);
}

/**
 * @brief Adcs获取模块修订号
 *
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval
 */
KF_INLINE uint8_t Adcs_LL_GetModuleRevision(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return ((uint8_t)(ADCS_PTR->ADCS_SUBID[AdcModule].bits.ADCREV));
}

/**
 * @brief Adcs获取模块类型
 *
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval
 */
KF_INLINE uint8_t Adcs_LL_GetModuleType(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return ((uint8_t)(ADCS_PTR->ADCS_SUBID[AdcModule].bits.ADCTYPE));
}

/**
 * @brief Adcs设置OTGB01
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Trigger
 *        ADCS_OTGB01_TRIGGER_0 没有触发器置位输出
 *        ADCS_OTGB01_TRIGGER_1 TS16_SSIGC，ADC 的采样信号
 *        ADCS_OTGB01_TRIGGER_2 TS16_SSIGF，输入比较通道的采样信号
 * @param Bus
 *        ADCS_OTGB01_BUS_0 触发设置被输出到 OTGB0
 *        ADCS_OTGB01_BUS_1 触发设置被输出到 OTGB1
 * @retval void
 */
KF_INLINE void
Adcs_LL_SetOTGB01(const Adcs_Module_t AdcModule, const Adcs_OTGB01_Trigger_t Trigger, const Adcs_OTGB01_Bus_t Bus)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_OTGB_TRIGGER(Trigger));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_OTGB_BUS(Bus));
    REG_WRITE(ADCS_PTR->ADCS_DBG[AdcModule].bits.TG_P, 1U);
    REG_WRITE(ADCS_PTR->ADCS_DBG[AdcModule].bits.TGS, Trigger);
    REG_WRITE(ADCS_PTR->ADCS_DBG[AdcModule].bits.TG_B, Bus);
    REG_WRITE(ADCS_PTR->ADCS_DBG[AdcModule].bits.TG_P, 0U);
}

/**
 * @brief Adcs设置挂起模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param SuspendMode
    ADCS_SUSPEND_MODE_NONE,
    ADCS_SUSPEND_MODE_HARD,
    ADCS_SUSPEND_MODE_SOFT,
 * @retval void
 */
KF_INLINE void Adcs_LL_SetSuspendMode(const Adcs_Module_t AdcModule, Adcs_SuspendMode_t SuspendMode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_SUSPENDMODE(SuspendMode));

    ADCS_DBG_T regValue = {0};

    regValue.reg        = REG_READ(ADCS_PTR->ADCS_DBG[AdcModule].reg);
    regValue.bits.SUS_P = true;
    regValue.bits.SUS   = SuspendMode;

    REG_WRITE(ADCS_PTR->ADCS_DBG[AdcModule].bits.SUS_P, regValue.reg);
}

/**
 * @brief Adcs获取模块挂起状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 模块未挂起
 *        true 模块挂起
 */
KF_INLINE bool Adcs_LL_GetSuspendStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->ADCS_DBG[AdcModule].bits.SUSSTA);
}

/**
 * @brief 清除Adcs模块复位状态
 * @details 将寄存器 ADCx_RST0.RSTSTAT 位域清零
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval
 */
KF_INLINE void Adcs_LL_ClearResetStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_RSTCLR[AdcModule].bits.CLR, 1U);
}

/**
 * @brief 复位Adcs模块
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval
 */
KF_INLINE void Adcs_LL_ResetModule(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_RST0[AdcModule].bits.RST, 1U);
    REG_WRITE(ADCS_PTR->ADCS_RST1[AdcModule].bits.RST, 1U);
}

/**
 * @brief 清除Adcs模块复位状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 模块没有复位
 *        true 模块已复位
 */
KF_INLINE bool Adcs_LL_GetResetStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (ADCS_PTR->ADCS_RST0[AdcModule].bits.RSTSTAT);
}

/**
 * @brief 设置Master TAG ID访问权限
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Id Master TAG ID
 * @param Status bool
 *        false 写访问没有执行
 *        true 写访问执行
 * @return
 */
KF_INLINE void Adcs_LL_SetAccessEnabled(const Adcs_Module_t AdcModule, const Adcs_MasterTAGId_t Id, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADCS_MASTERTAG_ID(Id));
    REG_BITS_WRITE(ADCS_PTR->ADCS_ACCEN0[AdcModule].reg, (1U << Id), ((uint32_t)Status << Id));
}

/**
 * @brief Adcs模块设置模拟时钟产生方式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *        ADCS_ANALOG_CLOCK_MODE_SYNCHRONIZE 同步
 *        ADCS_ANALOG_CLOCK_MODE_UNSYNCHRONIZE 异步
 * @retval void
 */
KF_INLINE void Adcs_LL_SetAnalogClockGenerateMode(const Adcs_Module_t AdcModule, Adcs_AnalogClockMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_ANALOG_CLOCK_MODE(Mode));
    REG_WRITE(ADCS_PTR->ADCS_GCTL[AdcModule].bits.USC, Mode);
}

/**
 * @brief Adcs模块设置供电电压电平
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *  ADCS_SUPPLY_VOLTAGE_LEVEL_AUTO 自动控制，电压范围通过供应电源控制
 *  ADCS_SUPPLY_VOLTAGE_LEVEL_UPPER 最大电压
 *  ADCS_SUPPLY_VOLTAGE_LEVEL_LOWER 最低电压
 * @retval KF_INLINE
 */
KF_INLINE void
Adcs_LL_SetSupplyVoltageLevelControl(const Adcs_Module_t AdcModule, Adcs_SupplyVoltageLevelControl_t Voltage)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_SUPPLY_VOLTAGE_LEVEL(Voltage));
    REG_WRITE(ADCS_PTR->ADCS_GCTL[AdcModule].bits.SUPVSEL, Voltage);
}

/**
 * @brief Adcs模块设置启动校准
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *        ADCS_STARTUP_CALIBRATION_NOACTION 无影响
 *        ADCS_STARTUP_CALIBRATION_INITIATE 使能初始校准
 * @retval KF_INLINE
 */
KF_INLINE void
Adcs_LL_SetStartupCalibration(const Adcs_Module_t AdcModule, Adcs_StartupCalibration_t CalibrationControl)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_STARTUP_CALIBRATION(Voltage));
    REG_WRITE(ADCS_PTR->ADCS_GCTL[AdcModule].bits.QJZ, CalibrationControl);
}

/**
 * @brief Adcs模块设置USC、SUPVSEL 位域的写权限
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval void
 */
KF_INLINE void Adcs_LL_EnableGCTLWriteControl(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_GCTL[AdcModule].bits.CPWC, 1U);
}

/**
 * @brief 设置Adcs模块全局配置
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param GlobalConfig
 * @retval void
 */
KF_INLINE void Adcs_LL_SetGlobalConfigurations(const Adcs_Module_t AdcModule, Adcs_GlobalConfig_t *GlobalConfig)
{
    Adcs_LL_EnableGCTLWriteControl(AdcModule);
    Adcs_LL_SetAnalogClockGenerateMode(AdcModule, GlobalConfig->AnalogClockMode);
    Adcs_LL_SetSupplyVoltageLevelControl(AdcModule, GlobalConfig->SupplyVoltageLevel);
    Adcs_LL_SetStartupCalibration(AdcModule, GlobalConfig->CalibrationControl);
}

/**
 * @brief 设置Adcs模块通道控制寄存器权限保护
 * @details 受保护的寄存器: ADCx_CHCTLy
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status
 *        false 寄存器所有权限打开
 *        true 通道控制寄存器写权限被锁住
 * @retval void
 */
KF_INLINE void Adcs_LL_SetChannelControlRegisterProtection(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    ADCS_PTR->ADCS_ACESP0[AdcModule].bits.APC = (uint32_t)Status;
}

/**
 * @brief 设置Adcs模块初始化寄存器权限保护
 * @details 受保护的寄存器: ADCx_ARBCTL,ADCx_ARBPTY,ADCx_ICLASS0/1,ADCx_SYNCTL
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status
 *        false 寄存器所有权限打开
 *        true 通道控制寄存器写权限被锁住
 * @retval void
 */
KF_INLINE void Adcs_LL_SetInitRegisterProtection(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    ADCS_PTR->ADCS_ACESP0[AdcModule].bits.API = (uint32_t)Status;
}

/**
 * @brief 设置Adcs模块服务中断寄存器权限保护
 * @details 受保护的寄存器: ADCx_SEF,ADCx_SENP,ADCx_CEF,ADCx_CENP0/1,ADCx_REF,ADCx_RENP0/1,ADCx_STRGACT
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status
 *        false 寄存器所有权限打开
 *        true 通道控制寄存器写权限被锁住
 * @retval void
 */
KF_INLINE void Adcs_LL_SetServiceIntrRegisterProtection(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    ADCS_PTR->ADCS_ACESP1[AdcModule].bits.APS = (uint32_t)Status;
}

/**
 * @brief 设置Adcs模块结果寄存器权限保护
 * @details 受保护的寄存器: ADCx_RCTLy,ADCx_BOUNDSEL,ADCx_RES
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status
 *        false 寄存器所有权限打开
 *        true 通道控制寄存器写权限被锁住
 * @retval void
 */
KF_INLINE void Adcs_LL_SetResultRegisterProtection(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    ADCS_PTR->ADCS_ACESP1[AdcModule].bits.APR = (uint32_t)Status;
}

/**
 * @brief 设置Adcs模块比较通道寄存器权限保护
 * @details 受保护的寄存器: CMPy_BOUNDF,CMPy_HYST,CMPx_CCTL, CMPy_MOD,CMPy_RAMPCTL0/1
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status
 *        false 寄存器所有权限打开
 *        true 通道控制寄存器写权限被锁住
 * @retval void
 */
KF_INLINE void Adcs_LL_SetCmpRegisterProtection(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    ADCS_PTR->ADCS_ACESP2[AdcModule].bits.APF = (uint32_t)Status;
}

/**
 * @brief 设置Adcs模块全局配置寄存器权限保护
 * @details 受保护的寄存器: ADCx_GCTL
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status
 *        false 寄存器所有权限打开
 *        true 通道控制寄存器写权限被锁住
 * @retval void
 */
KF_INLINE void Adcs_LL_SetGloblalCfgRegisterProtection(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    ADCS_PTR->ADCS_ACESP2[AdcModule].bits.APGC = (uint32_t)Status;
}

/**
 * @brief 设置Adcs模块外部多路复用器寄存器权限保护
 * @details 受保护的寄存器: ADCx_EMUXCSEL,ADCx_EMUXCTL,ADCx_EMUXCSEL
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status
 *        false 寄存器所有权限打开
 *        true 通道控制寄存器写权限被锁住
 * @retval void
 */
KF_INLINE void Adcs_LL_SetExternalMuxRegisterProtection(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    ADCS_PTR->ADCS_ACESP2[AdcModule].bits.APEM = (uint32_t)Status;
}

/**
 * @brief 设置Adcs模块测试寄存器权限保护
 * @details 受保护的寄存器: ADCx_GEF,ADCx_GTE
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status
 *        false 寄存器所有权限打开
 *        true 通道控制寄存器写权限被锁住
 * @retval void
 */
KF_INLINE void Adcs_LL_SetTestRegisterProtection(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    ADCS_PTR->ADCS_ACESP2[AdcModule].bits.APTF = (uint32_t)Status;
}

/**
 * @brief Adcs模块设置全局检查边界值0
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Boundary 边界值
 * @retval void
 */
KF_INLINE void Adcs_LL_SetGlobalBoundary0(const Adcs_Module_t AdcModule, const uint32_t Boundary)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_BOUNDARY_LIMIT(Boundary));
    REG_WRITE(ADCS_PTR->ADCS_GBOUNDSEL[AdcModule].bits.BOUND0, Boundary);
}

/**
 * @brief Adcs模块设置全局检查边界值1
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Boundary 边界值
 * @retval void
 */
KF_INLINE void Adcs_LL_SetGlobalBoundary1(const Adcs_Module_t AdcModule, const uint32_t Boundary)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_BOUNDARY_LIMIT(Boundary));
    REG_WRITE(ADCS_PTR->ADCS_GBOUNDSEL[AdcModule].bits.BOUND1, Boundary);
}

/**
 * @brief 全局结果事件标志位
 *
 * @param AdcModule
 * @retval bool
 *        false 没有结果事件
 *        true 新的结果被保存到全局结果寄存器 ADCx_GRES
 */
KF_INLINE bool Adcs_LL_GetGlobalResultEventStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return ((bool)ADCS_PTR->ADCS_GEF[AdcModule].bits.REGF);
}

/**
 * @brief Adcs模块清除全局结果事件标志位
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval void
 */
KF_INLINE void Adcs_LL_ClearGlobalResultEventStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_GEF[AdcModule].bits.REGC, 1U);
    __asm volatile("NOP");
    __asm volatile("NOP");
    __asm volatile("NOP");
    REG_WRITE(ADCS_PTR->ADCS_GEF[AdcModule].bits.REGC, 0U);
}

/**
 * @brief Adcs设置全局结果服务中断指针节点
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Pointer
 *        ADCS_GLB_RESULT_COMMON_GROUP0_SERVICE_LINE_0 选择公共服务中断组 0 的服务中断线 0
 *        ADCS_GLB_RESULT_COMMON_GROUP0_SERVICE_LINE_1 选择公共服务中断组 0 的服务中断线 1
 *        ADCS_GLB_RESULT_COMMON_GROUP0_SERVICE_LINE_2 选择公共服务中断组 0 的服务中断线 2
 *        ADCS_GLB_RESULT_COMMON_GROUP0_SERVICE_LINE_3 选择公共服务中断组 0 的服务中断线 3
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_0 选择公共服务中断组 1 的服务中断线 0
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_1 选择公共服务中断组 1 的服务中断线 1
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_2 选择公共服务中断组 1 的服务中断线 2
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_3 选择公共服务中断组 1 的服务中断线 3
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_0 没有选择服务中断线
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_1 没有选择服务中断线
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_2 没有选择服务中断线
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_3 没有选择服务中断线
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_4 没有选择服务中断线
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_5 没有选择服务中断线
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_6 没有选择服务中断线
 *        ADCS_GLB_RESULT_COMMON_GROUP1_SERVICE_LINE_OFF_7 没有选择服务中断线
 * @retval void
 */
KF_INLINE void Adcs_LL_SelectGlobalServiceLine(const Adcs_Module_t AdcModule, const Adcs_GlobalResultServiceLine_t Line)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_GLB_RESULT_SERVICE_LINE(Line));
    REG_WRITE(ADCS_PTR->ADCS_GENP[AdcModule].bits.REV0NP, Line);
}

/**
 * @brief Adcs设置全局诊断
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Channel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Group 转换器组号
 * @param Device 转换器诊断拉动设备
 *        ADCS_DIAGNOSTIC_PULL_DEVICE_VDDM
 *        ADCS_DIAGNOSTIC_PULL_DEVICE_VSS,
 *        ADCS_DIAGNOSTIC_PULL_DEVICE_VDDM_DIV2
 *        ADCS_DIAGNOSTIC_PULL_DEVICE_VDDM_DIV3_MULT2
 * @param Enabled
 *        false 转换器诊断不使能
 *        true 转换器诊断使能
 * @retval void
 */
KF_INLINE void Adcs_LL_SetGlobalDiagnosticConfig(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t Channel, const uint32_t Group, const Adcs_DiagPullDevice_t Device,
  bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(Channel));
    KF_DRV_ADCS_ASSERT(!(Group >> 4));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_DIAGNOSTIC_PULL_DEVICE(Device));
    REG_WRITE(ADCS_PTR->ADCS_GTESTCTL[AdcModule].bits.CDWC, 1U);
    REG_WRITE(ADCS_PTR->ADCS_GTESTCTL[AdcModule].bits.CDCH, Channel);
    REG_WRITE(ADCS_PTR->ADCS_GTESTCTL[AdcModule].bits.CDGR, Group);
    REG_WRITE(ADCS_PTR->ADCS_GTESTCTL[AdcModule].bits.CDSEL, Device);
    REG_WRITE(ADCS_PTR->ADCS_GTESTCTL[AdcModule].bits.CDEN, Enabled);
    REG_WRITE(ADCS_PTR->ADCS_GTESTCTL[AdcModule].bits.CDWC, 0U);
}

/**
 * @brief Adcs模块下拉诊断使能
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false 下拉诊断设备断开
 *        true 下拉诊断设备激活
 * @retval void
 */
KF_INLINE void Adcs_LL_EnableGlobalPullDownDiag(const Adcs_Module_t AdcModule, bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_GTESTCTL[AdcModule].bits.PDD, Enabled);
}

/**
 * @brief Adcs模块多路复用器下拉设备使能
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false 下拉诊断设备断开
 *        true 下拉诊断设备激活
 * @retval void
 */
KF_INLINE void Adcs_LL_EnableGlobalMuxPullDownDiag(const Adcs_Module_t AdcModule, bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_GTESTCTL[AdcModule].bits.MDPD, Enabled);
}

/**
 * @brief Adcs模块多路复用器上拉设备使能
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false 上拉诊断设备断开
 *        true 上拉诊断设备激活
 * @retval void
 */
KF_INLINE void Adcs_LL_EnableGlobalMuxPullUpDiag(const Adcs_Module_t AdcModule, bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_GTESTCTL[AdcModule].bits.MDPU, Enabled);
}

/**
 * @brief Adcs模块测试队列使能
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false 测试队列关闭,队列 2 只能作为正常的转换队列，诊断配置将无效
 *        true 测试队列开启，队列 2 内的诊断配置起作用
 * @retval void
 */
KF_INLINE void Adcs_LL_EnableGlobalTestQueue(const Adcs_Module_t AdcModule, bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_GTESTE[AdcModule].bits.TFEP, Enabled);
}

/**
 * @brief Adcs模块设置全局结果覆盖次数
 * @details 数据被覆盖一定次数后，新数据写入标志位 ADCx_GRES.VF 才能置 1，进而触发一次中断
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Counter
 * @retval void
 */
KF_INLINE void Adcs_LL_SetGlobalResultCoverCounter(const Adcs_Module_t AdcModule, const uint8_t Counter)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_GRESCTL[AdcModule].bits.RINTCNT, Counter);
}

/**
 * @brief Adcs模块设置全局数据压缩控制
 * @details 累加次数设置，只有当全局结果寄存器累加到一定次数时 ADCx_GRES.VF 才能置 1，进而触发一次中断
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 * @retval void
 */
KF_INLINE void Adcs_LL_SetGlobalDataReductionMode(const Adcs_Module_t AdcModule, const uint32_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(!(Mode >> 4));
    REG_WRITE(ADCS_PTR->ADCS_GRESCTL[AdcModule].bits.DRCTL, Mode);
}

/**
 * @brief Adcs模块设置全局数据压缩控制
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval void
 */
KF_INLINE void Adcs_LL_ClearGlobalResultCoverFlag(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_GRESCTL[AdcModule].bits.CFCLR, 1U);
}

/**
 * @brief Adcs模块设置全局结果寄存器等待阅读模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status
 *        false 覆盖模式
 *        true 等待阅读模式
 * @retval void
 */
KF_INLINE void Adcs_LL_SetGlobalResultWaitForReadModeEnabled(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_GRESCTL[AdcModule].bits.WFR, Status);
}

/**
 * @brief Adcs模块设置服务中断请求使能
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Status
 *        false 服务中断请求禁止
 *        true 服务中断请求使能
 * @retval void
 */
KF_INLINE void Adcs_LL_SetServiceRequestEnabled(const Adcs_Module_t AdcModule, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_GRESCTL[AdcModule].bits.SRGEN, Status);
}

/**
 * @brief Adcs模块获取全局结果寄存器转换结果
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval uint16_t 转换结果
 */
KF_INLINE uint16_t Adcs_LL_GetConvertResultFromGlobalResult(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (ADCS_PTR->ADCS_GRES[AdcModule].bits.RESULT);
}

/**
 * @brief Adcs模块获取全局结果寄存器转换结果通道号
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval uint32_t 转换结果通道号
 */
KF_INLINE uint32_t Adcs_LL_GetConvertChannelFromGlobalResult(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (ADCS_PTR->ADCS_GRES[AdcModule].bits.CH);
}

/**
 * @brief Adcs模块获取全局结果寄存器转换结果多路复用器
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval uint32_t 转换结果多路复用器
 */
KF_INLINE uint32_t Adcs_LL_GetConvertMuxFromGlobalResult(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (ADCS_PTR->ADCS_GRES[AdcModule].bits.EMUX);
}

/**
 * @brief Adcs模块获取全局结果寄存器转换结果队列号
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval uint32_t 转换结果来自的队列号
 */
KF_INLINE uint32_t Adcs_LL_GetConvertQueueFromGlobalResult(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (ADCS_PTR->ADCS_GRES[AdcModule].bits.CRS);
}

/**
 * @brief Adcs模块获取全局结果寄存器数据被覆盖标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 该结果寄存器 RESULT 位域的值没有被覆盖
 *        true 该结果寄存器 RESULT 位域的值没有被覆盖
 */
KF_INLINE bool Adcs_LL_GetGlobalResultOverWriteStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (ADCS_PTR->ADCS_GRES[AdcModule].bits.CF);
}

/**
 * @brief Adcs模块获取全局结果寄存器数据有效标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 没有新的数据写入到 RESULT 中
 *        true 一个新的数据被写入位域 RESULT 中，或之前的数据没有被读取
 */
KF_INLINE bool Adcs_LL_GetGlobalResultValidStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (ADCS_PTR->ADCS_GRES[AdcModule].bits.VF);
}

/**
 * @brief Adcs模块多路复用器接口选择
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param EmuxInterface
 *  ADCS_EMUX_INTERFACE_0 外部多路复用器接口 0
 *  ADCS_EMUX_INTERFACE_1 外部多路复用器接口 1
 * @param Port
 * @retval void
 */
KF_INLINE void Adcs_LL_SelectEmuxInterface(
  const Adcs_Module_t AdcModule, const Adcs_EmuxInterface_t EmuxInterface, const Adcs_EmuxInterfacePort_t Port)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_EMUX_PORT(Port));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_EMUX_INTERFACE(Port));
    if (EmuxInterface == ADCS_EMUX_INTERFACE_0)
    {
        REG_WRITE(ADCS_PTR->ADCS_EMUXISEL[AdcModule].bits.EMUXITF0, Port);
    }
    else
    {
        REG_WRITE(ADCS_PTR->ADCS_EMUXISEL[AdcModule].bits.EMUXITF1, Port);
    }
}

/**
 * @brief Adcs模块获取触发器计数器值
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval void
 */
KF_INLINE uint32_t Adcs_LL_GetTriggerSequenceCounter(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (ADCS_PTR->ADCS_TRGCTL[AdcModule].bits.TSC);
}

/**
 * @brief Adcs模块获取队列2激活标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 队列 2 没有被激活
 *        true 队列 2 正在运行一个转换序列
 */
KF_INLINE bool Adcs_LL_GetQueueActivateStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->ADCS_TRGCTL[AdcModule].bits.QACT);
}

/**
 * @brief Adcs模块获取非法触发标志
 * @details 当队列 2 正在运行时，又来了一个触发信号时，该触发信号将作为非法触发信号
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 没有非法触发信号
 *        true 检测到非法触发信号
 */
KF_INLINE bool Adcs_LL_GetOverflowStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->ADCS_TRGCTL[AdcModule].bits.OV);
}

/**
 * @brief Adcs模块设置触发计数器初始值
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param StartValue
 * @return void
 */
KF_INLINE void Adcs_LL_SetTriggerSquenceStartValue(const Adcs_Module_t AdcModule, const uint32_t StartValue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(!(StartValue >> 6));
    REG_WRITE(ADCS_PTR->ADCS_TRGCTL[AdcModule].bits.TSCSET, StartValue);
}

/**
 * @brief Adcs模块选择内部触发信号
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Source
 *        ADCS_INNER_TRIGGER_SOURCE_0 选择内部触发信号 Q0
 *        ADCS_INNER_TRIGGER_SOURCE_1 选择内部触发信号 Q1
 * @retval void
 */
KF_INLINE void Adcs_LL_SelectInnerTriggerSource(const Adcs_Module_t AdcModule, const Adcs_InnerTriggerSource_t Source)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_EMUX_INTERFACE(Source));
    REG_WRITE(ADCS_PTR->ADCS_TRGCTL[AdcModule].bits.ITSEL, Source);
}

/**
 * @brief Adcs模块禁止服务中断信号产生
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Disabled
 *        false 源事件产生一个服务中断信号
 *        true 禁止服务中断信号产生
 * @retval void
 */
KF_INLINE void Adcs_LL_SetServiceRequestDisabled(const Adcs_Module_t AdcModule, const bool Disabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_TRGCTL[AdcModule].bits.SIE, Disabled);
}

/**
 * @brief Adcs模块清除非法触发信号指示位 OV 和队列 2 激活指示位QACT
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval void
 */
KF_INLINE void Adcs_LL_ClearTriggerFlag(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_TRGCTL[AdcModule].bits.COV, 1U);
}

/**
 * @brief Adcs模块工作模式设置
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *        ADCS_ANALOG_CONVERTER_MODE_OFF 转换器关闭模式，ADC 模拟部分关闭，数字逻辑部分变为初始状态
 *        ADCS_ANALOG_CONVERTER_MODE_SLOW_STANDBY 慢速待机模式，当 ADC 接收到任务后，需要唤醒时间，时间为 5μs
 *        ADCS_ANALOG_CONVERTER_MODE_FAST_STANDBY 快速待机模式，当 ADC 接收到任务后，需要唤醒时间，时间为 1μs
 *        ADCS_ANALOG_CONVERTER_MODE_NORMAL 正常模式，转换器一直保持激活状态
 * @retval void
 */
KF_INLINE void Adcs_LL_SetAnalogConvertControl(const Adcs_Module_t AdcModule, Adcs_AnalogConverterMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_ANALOG_CONVERTER_MODE(Mode));
    REG_WRITE(ADCS_PTR->ADCS_ARBCTL[AdcModule].bits.ANONC, Mode);
}

/**
 * @brief 获取Adcs模块工作模式s
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval void
 */
KF_INLINE Adcs_AnalogConverterMode_t Adcs_LL_GetAnalogConvertControl(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (Adcs_AnalogConverterMode_t)(ADCS_PTR->ADCS_ARBCTL[AdcModule].bits.ANONS);
}

/**
 * @brief Adcs模块获取当前转换请求源
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval Adcs_CurrentConvertedRequestSource_t
 *        ADCS_CURRENT_CONVERT_REQ_SOURCE_QUEUE0 当前或上一个的转换信息来自队列 0
 *        ADCS_CURRENT_CONVERT_REQ_SOURCE_QUEUE1 当前或上一个的转换信息来自队列 1
 *        ADCS_CURRENT_CONVERT_REQ_SOURCE_QUEUE2 当前或上一个的转换信息来自队列 2
 *        ADCS_CURRENT_CONVERT_REQ_SOURCE_SYNC 当前或上一个的转换信息来自同步转换请求
 */
KF_INLINE Adcs_CurrentConvertedRequestSource_t Adcs_LL_GetAnalogConvertRequestSource(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (Adcs_CurrentConvertedRequestSource_t)(ADCS_PTR->ADCS_ARBCTL[AdcModule].bits.CSRC);
}

/**
 * @brief Adcs 获取当前转换通道
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval Adcs_Channel_t
 */
KF_INLINE Adcs_Channel_t Adcs_LL_GetCurrentConvertChannel(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (Adcs_Channel_t)(ADCS_PTR->ADCS_ARBCTL[AdcModule].bits.CHNR);
}

/**
 * @brief Adcs 获取当前转换是否为同步平行转换状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 当前转换为正常转换或没有运行转换
 *        true 当前正在运行的转换为同步平行转换
 */
KF_INLINE bool Adcs_LL_GetCurrentConvertSyncStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->ADCS_ARBCTL[AdcModule].bits.SYNRUN);
}

/**
 * @brief Adcs 获取当前转换启动校准状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 校准已经完成或还没有开始
 *        true 当前校准正在执行
 */
KF_INLINE bool Adcs_LL_GetCurrentConvertCalibrationStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->ADCS_ARBCTL[AdcModule].bits.CAL);
}

/**
 * @brief Adcs 获取当前转换运行状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 没有转换在运行
 *        true 当前有转换在运行
 */
KF_INLINE bool Adcs_LL_GetCurrentConvertRunningStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->ADCS_ARBCTL[AdcModule].bits.BUSY);
}

/**
 * @brief Adcs 获取当前转换采样状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 当前正在转换或处于空闲状态
 *        true 当前正对输入信号进行采样
 */
KF_INLINE bool Adcs_LL_GetCurrentConvertSampleStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->ADCS_ARBCTL[AdcModule].bits.SAMPLE);
}

/**
 * @brief 设置仲裁优先级
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param ArbitrateEnable 仲裁使能
 *        false 仲裁被禁止
 *        true 仲裁输入被打开
 * @param Priority 优先级
 *        ADCS_ARBITRATE_PRIORITY_0 优先级0
 *        ADCS_ARBITRATE_PRIORITY_1 优先级1
 *        ADCS_ARBITRATE_PRIORITY_2 优先级2
 *        ADCS_ARBITRATE_PRIORITY_3 优先级3
 * @param Mode 模式
 *  ADCS_ARBITRATE_MODE_WAIT_FOR_START 等待-开始模式
 *  ADCS_ARBITRATE_MODE_CANCEL_INJECT_REPEAT 取消-注入-重启模式
 * @param Queue 队列号
 *  ADCS_QUEUE_0 队列0
 *  ADCS_QUEUE_1 队列1
 *  ADCS_QUEUE_2 队列2
 * @reval void
 */
KF_INLINE void Adcs_LL_SetArbiterPriority(
  const Adcs_Module_t AdcModule, const bool ArbitrateEnable, const Adcs_ArbitratePriority_t Priority,
  const Adcs_ArbitrateMode_t Mode, const Adcs_Queue_t Queue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(Queue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_ARBITRATE_PRIORITY(Priority));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_ARBITRATE_MODE(Mode));
    if (ArbitrateEnable)
    {
        REG_BIT_SET(ADCS_PTR->ADCS_ARBPTY[AdcModule].reg, (1U << (24U + (uint32_t)Queue)));
        REG_BITS_WRITE(ADCS_PTR->ADCS_ARBPTY[AdcModule].reg, (3U << ((uint32_t)Queue << 2U)),
                       ((uint32_t)Priority << ((uint32_t)Queue << 2U)));
        REG_BITS_WRITE(ADCS_PTR->ADCS_ARBPTY[AdcModule].reg, (1U << (3U + ((uint32_t)Queue << 2U))),
                       ((uint32_t)Mode << (3U + ((uint32_t)Queue << 2U))));
    }
    else
    {
        REG_BIT_CLR(ADCS_PTR->ADCS_ARBPTY[AdcModule].reg, (1U << (24U + (uint32_t)Queue)));
    }
}

/**
 * @brief Adcs模块选择空闲预充电平
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *        ADCS_IDLE_PRECHARGE_CURRENTLEVEL 没有预充电
 *        ADCS_IDLE_PRECHARGE_REFERENCE_DIV2 采样电容被预充电到参考电压的一半
 * @retval void
 */
KF_INLINE void Adcs_LL_SelectIdlePrechargeLevel(const Adcs_Module_t AdcModule, const Adcs_IdlePrechargeMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_IDLE_PRECHARGE_MODE(Mode));
    REG_WRITE(ADCS_PTR->ADCS_ANCTL[AdcModule].bits.IPE, Mode);
}

/**
 * @brief Adcs模块断路诊断使能控制
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled bool
 *        false  断路诊断使能关闭
 *        true  断路诊断使能打开
 * @retval void
 */
KF_INLINE void Adcs_LL_EnableOpenCircuitDiag(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_ANCTL[AdcModule].bits.BE, Enabled);
}

/**
 * @brief Adcs模块设置模拟时钟同步延迟
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Delay
 *        ADCS_ANALOG_CLOCK_SYNC_DELAY_0 没有延迟
 *        ADCS_ANALOG_CLOCK_SYNC_DELAY_1 1个时钟的延迟
 *        ADCS_ANALOG_CLOCK_SYNC_DELAY_2 2个时钟的延迟
 *        ADCS_ANALOG_CLOCK_SYNC_DELAY_3 3个时钟的延迟
 *        ADCS_ANALOG_CLOCK_SYNC_DELAY_4 4个时钟的延迟
 *        ADCS_ANALOG_CLOCK_SYNC_DELAY_5 5个时钟的延迟
 *        ADCS_ANALOG_CLOCK_SYNC_DELAY_6 6个时钟的延迟
 *        ADCS_ANALOG_CLOCK_SYNC_DELAY_7 7个时钟的延迟
 * @retval void
 */
KF_INLINE void Adcs_LL_SetAnalogClockSyncDelay(const Adcs_Module_t AdcModule, const Adcs_AnalogClockSyncDelay_t Delay)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADCS_ANALOG_CLOCK_SYNC_DELAY(Delay));
    REG_WRITE(ADCS_PTR->ADCS_ANCTL[AdcModule].bits.ACSD, Delay);
}

/**
 * @brief Adcs模块采样时间同步使能
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false 没有同步控制
 *        true 采样开启与相位同步信号同步
 * @retval void
 */
KF_INLINE void Adcs_LL_EnableSampleTimingSync(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_ANCTL[AdcModule].bits.SSE, Enabled);
}

/**
 * @brief Adcs模块外设时钟分频预分频参数设置
 * @details ADCICLK=ADCCLK/CP
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Divider
 * @retval void
 */
KF_INLINE void Adcs_LL_SetAnalogClockDivider(const Adcs_Module_t AdcModule, Adcs_AnalogClockDivider_t Divider)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_ANALOG_CLOCK_DIVIDER(Divider));
    REG_WRITE(ADCS_PTR->ADCS_ANCTL[AdcModule].bits.CLKPDIV, Divider);
}

/**
 * @brief Adcs模块设置通道0别名
 * @details 将用于通道 0 的转换切换到其他通道中
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Alias
 * @retval void
 */
KF_INLINE void Adcs_LL_SetAliasForChannel0Request(const Adcs_Module_t AdcModule, const uint32_t Alias)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_ALIAS(Alias));
    REG_WRITE(ADCS_PTR->ADCS_ALIAS[AdcModule].bits.ALIAS0, Alias);
}

/**
 * @brief Adcs模块设置通道1别名
 * @details 将用于通道 1 的转换切换到其他通道中
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Alias
 * @retval void
 */
KF_INLINE void Adcs_LL_SetAliasForChannel1Request(const Adcs_Module_t AdcModule, const uint32_t Alias)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_ALIAS(Alias));
    REG_WRITE(ADCS_PTR->ADCS_ALIAS[AdcModule].bits.ALIAS1, Alias);
}

/**
 * @brief Adcs模块设置检查边界值0
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Boundary 边界值
 * @retval void
 */
KF_INLINE void Adcs_LL_SetBoundary0(const Adcs_Module_t AdcModule, const uint32_t Boundary)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_BOUNDARY_LIMIT(Boundary));
    REG_WRITE(ADCS_PTR->ADCS_BOUNDSEL[AdcModule].bits.BOUND0, Boundary);
}

/**
 * @brief Adcs模块设置检查边界值1
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Boundary 边界值
 * @retval void
 */
KF_INLINE void Adcs_LL_SetBoundary1(const Adcs_Module_t AdcModule, const uint32_t Boundary)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_BOUNDARY_LIMIT(Boundary));
    REG_WRITE(ADCS_PTR->ADCS_BOUNDSEL[AdcModule].bits.BOUND1, Boundary);
}

/**
 * @brief Adcs模块设置同步平行转换所属主机
 *
 * @attention 不同模块CI1、CI2、CI3连接的ADC模块不同(例如，ADC0的CI1为ADC1,
 * ADC1的CI1为ADC0，具体参考手册《同步平行转换》）
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param MasterIndex
 *        ADCS_SYNC_MASTER_SELF 本ADC模块为主控制方
 *        ADCS_SYNC_MASTER_CI1 本ADC模块为从属方，控制信息来源输入CI1
 *        ADCS_SYNC_MASTER_CI2 本ADC模块为从属方，控制信息来源输入CI2
 *        ADCS_SYNC_MASTER_CI3 本ADC模块为从属方，控制信息来源输入CI3
 * @retval void
 */
KF_INLINE void
Adcs_LL_SetSyncConvertMasterIndex(const Adcs_Module_t AdcModule, const Adcs_SyncMasterIndex_t MasterIndex)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_SYNC_MASTER_INDEX(MasterIndex));
    REG_WRITE(ADCS_PTR->ADCS_SYNCTL[AdcModule].bits.STSEL, MasterIndex);
    if (MasterIndex != ADCS_SYNC_MASTER_SELF)
    {
        REG_BIT_SET(ADCS_PTR->ADCS_SYNCTL[AdcModule].reg, (0x00000008U << MasterIndex));
    }
    else
    {
    }
}

/**
 * @brief Adcs模块x选择队列n的结果寄存器
 *
 * @details 每次的ADC转换都需要将转换值写入到目标结果寄存器中，
 * 每个ADC都含还有16个目标结果寄存器ADCx_RESy(x=0-3,y=0-15) ，
 * 且每个ADC模块还有一个全局目标结果寄存器ADCx_GRES
 * 该API通过队列源控制寄存器ADCx_QCTLn.RESSEL选择目标结果寄存器，
 * 但是该方式只能选择ADC模块的后15个结果寄存器
 *
 * @attention 当该位域配置为 0H 时，可以通过通道控制寄存器ADCx_CHCTLy.RESTGT及ADCx_CHCTLy.RESREG
 * 选择全局目标结果寄存器(0-15)或ADC内部所有的结果寄存器。
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param Register
 *        ADCS_RESULT_REGISTER_CH_RESTGT 使用ADCx_CHCTLy.RESTGT去选择结果寄存器
 *        ADCS_RESULT_REGISTER_1 将转换结果保存到结果寄存器 ADCx_RES1中
 *        ADCS_RESULT_REGISTER_2 将转换结果保存到结果寄存器 ADCx_RES2中
 *        ADCS_RESULT_REGISTER_3 将转换结果保存到结果寄存器 ADCx_RES3中
 *        ADCS_RESULT_REGISTER_4 将转换结果保存到结果寄存器 ADCx_RES4中
 *        ADCS_RESULT_REGISTER_5 将转换结果保存到结果寄存器 ADCx_RES5中
 *        ADCS_RESULT_REGISTER_6 将转换结果保存到结果寄存器 ADCx_RES6中
 *        ADCS_RESULT_REGISTER_7 将转换结果保存到结果寄存器 ADCx_RES7中
 *        ADCS_RESULT_REGISTER_8 将转换结果保存到结果寄存器 ADCx_RES8中
 *        ADCS_RESULT_REGISTER_9 将转换结果保存到结果寄存器 ADCx_RES9中
 *        ADCS_RESULT_REGISTER_10 将转换结果保存到结果寄存器 ADCx_RES10中
 *        ADCS_RESULT_REGISTER_11 将转换结果保存到结果寄存器 ADCx_RES11中
 *        ADCS_RESULT_REGISTER_12 将转换结果保存到结果寄存器 ADCx_RES12中
 *        ADCS_RESULT_REGISTER_13 将转换结果保存到结果寄存器 ADCx_RES13中
 *        ADCS_RESULT_REGISTER_14 将转换结果保存到结果寄存器 ADCx_RES14中
 *        ADCS_RESULT_REGISTER_15 将转换结果保存到结果寄存器 ADCx_RES15中
 * @retval void
 */
KF_INLINE void Adcs_LL_SelectResultRegister(
  const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, Adcs_Queue_ResultRegister_t Register)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE_RESULT_REGISTER(Register));
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.RESSEL, Register);
}

/**
 * @brief Adcs模块x选择队列n触发源、触发信号操作模式、触发输入信号选择
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param Trigger
 *  ADCS_QUEUE_TRIGGER_SOURCE_EXTERN 外部触发，通过 STSEL 选择
 *  ADCS_QUEUE_TRIGGER_SOURCE_NEXT 下一个 ADC 的内部触发信号
 *  ADCS_QUEUE_TRIGGER_SOURCE_LAST 最后一个 ADC 的内部触发信号
 *  ADCS_QUEUE_TRIGGER_SOURCE_PREVIOUS 上一个 ADC 的内部触发信号
 * @param ExtTriggerSignal
 外部触发输入信号选择，等于7FH时使用门信号作为触发信号，可见《用户手册》ADC和比较器触发信号来源表
 * @param Mode 触发信号操作模式
    ADCS_QUEUE_TRIGGER_MODE_NO_TRIGGER 没有外部触发信号
    ADCS_QUEUE_TRIGGER_MODE_RISE 触发输入信号上升沿有效
    ADCS_QUEUE_TRIGGER_MODE_FALL 触发输入信号下降沿有效
    ADCS_QUEUE_TRIGGER_MODE_EITHER 触发输入信号上升沿和下降沿都有效
 * @retval void
 */
KF_INLINE void Adcs_LL_SetQueueTriggerOperatingConfig(
  const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const Adcs_Queue_TriggerSource_t TriggerSource,
  const uint8_t ExtTriggerSignal, const Adcs_Queue_TriggerMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE_TRIGGER_SOURCE(TriggerSource));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE_TRIGGER_MODE(Mode));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE_EXTERNAL_TRIGGER_SOURCE(ExtTriggerSignal));
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.GTWC, 1U);
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.XTMOD, Mode);
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.TRSEL, TriggerSource);
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.XTSEL, ExtTriggerSignal);
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.GTWC, 0U);
}

/**
 * @brief 获取Adcs模块x队列n外部触发电平
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE bool Adcs_LL_GetQueueExtTriggerLevel(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    return (bool)(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.XTLVL);
}

/**
 * @brief Adcs模块x选择队列n门控信号
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param Gating  当 Gating=7FH 时，使用内部触发信号用于队列 2
 * @return KF_INLINE
 */
KF_INLINE void
Adcs_LL_SelectQueueGatingSource(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const uint8_t Gating)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE_GATING_SOURCE(Gating));
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.GTWC, 1U);
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.GTSEL, Gating);
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.GTWC, 0U);
}

/**
 * @brief 获取Adcs模块x队列n门控信号电平
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @retval bool
 */
KF_INLINE bool Adcs_LL_GetQueueGatingLevel(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    return (bool)(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.GTLVL);
}

/**
 * @brief Adcs模块x队列n使能外部触发信号
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param enabled
 *         false 外部触发信号被禁止
 *         true 外部触发信号使能
 * @return KF_INLINE
 */
KF_INLINE void
Adcs_LL_EnableQueueExtTrigger(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const bool enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    REG_WRITE(ADCS_PTR->ADCS_QMOD[AdcModule][AdcQueue].bits.EXTRGEN, enabled);
}

/**
 * @brief Adcs模块x队列n使能门信号
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param Mode
 *        ADCS_QUEUE_GATING_DISABLE 没有转换请求被发送
 *        ADCS_QUEUE_GATING_EITHER 不论门信号电平大小都可以发送转换请求信号
 *        ADCS_QUEUE_GATING_HIGH 只有当门信号为高电平时，才能发送转换请求信号
 *        ADCS_QUEUE_GATING_LOW 只有当门信号为低电平时，才能发送转换请求信号
 * @retval void
 */
KF_INLINE void Adcs_LL_SetQueueGatingMode(
  const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const Adcs_Queue_GatingMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE_GATING_MODE(Mode));
    REG_WRITE(ADCS_PTR->ADCS_QMOD[AdcModule][AdcQueue].bits.GTEN, Mode);
}

/**
 * @brief Adcs模块使能队列0多通道同时采样
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false 单端输入模式
 *        true 多通道同时采样模式
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableQueue0MultipleChannelMode(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][ADCS_QUEUE_0].bits.INMOD, Enabled);
}

/**
 * @brief Adcs模块使能队列1差分模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false 单端输入模式
 *        true 多通道差分模式
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableQueue1DifferentialMode(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][ADCS_QUEUE_1].bits.INMOD, Enabled);
}

/**
 * @brief Adcs模块x队列n设置定时器触发模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param Edge
 *        ADCS_QUEUE_TIMER_FALL 下降沿有效
 *        ADCS_QUEUE_TIMER_RISE 上升沿有效
 * @retval void
 */
KF_INLINE void Adcs_LL_SelectQueueTimerEdge(
  const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const Adcs_Queue_TimerEdge_t Edge)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE_TIMER_EDGE(Edge));
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.TMWC, 1U);
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.TMEN, Edge);
    REG_WRITE(ADCS_PTR->ADCS_QCTL[AdcModule][AdcQueue].bits.TMWC, 0U);
}

/**
 * @brief Adcs模块x队列n清除有效标志位
 *
 * @details 队列第 0 阶或备份区中的保存的信息将被清理
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_ClearQueueValidFlag(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    REG_WRITE(ADCS_PTR->ADCS_QMOD[AdcModule][AdcQueue].bits.CLRF, 1U);
}

/**
 * @brief Adcs模块x队列n清除有效标志位
 *
 * @details 队列第 0 阶或备份区中的保存的信息将被清理
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_StartQueueBySoftTrigger(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    REG_WRITE(ADCS_PTR->ADCS_QMOD[AdcModule][AdcQueue].bits.TREV, 1U);
}

/**
 * @brief Adcs模块x队列n清除队列内所有的转换信息
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_ClearQueue(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    REG_WRITE(ADCS_PTR->ADCS_QMOD[AdcModule][AdcQueue].bits.FLUSH, 1U);
}

/**
 * @brief Adcs模块x队列n清除队列事件标志位EV
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_ClearQueueEvent(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    REG_WRITE(ADCS_PTR->ADCS_QMOD[AdcModule][AdcQueue].bits.CEF, 1U);
}

/**
 *
 * @brief Adcs模块x队列n禁止重复执行被取消的转换
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param Status
 *        fasle 被取消的转换信息可以重复执行
 *        true 被取消的转换信息被丢弃
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_DisableQueueRepeateCancelledConvert(
  const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    REG_WRITE(ADCS_PTR->ADCS_QMOD[AdcModule][AdcQueue].bits.RPTDIS, Status);
}

/**
 * @brief Adcs模块x队列n获取队列已满状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @retval bool
 *        false 队列未满
 *        true 队列已满
 */
KF_INLINE bool Adcs_LL_IsQueueFull(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    return (ADCS_PTR->ADCS_QSTA[AdcModule][AdcQueue].bits.FILL == 0xF);
}

/**
 * @brief Adcs模块x队列n获取队列有效转换信息数量
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @retval bool
 *        false 队列未满
 *        true 队列已满
 */
KF_INLINE uint32_t Adcs_LL_GetQueueFill(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    return (ADCS_PTR->ADCS_QSTA[AdcModule][AdcQueue].bits.FILL);
}

/**
 * @brief Adcs模块x队列n获取队列空状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @retval bool
 *        false 队列未满
 *        true 队列已满
 */
KF_INLINE bool Adcs_LL_IsQueueEmpty(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    return (ADCS_PTR->ADCS_QSTA[AdcModule][AdcQueue].bits.EMPTY);
}

/**
 * @brief Adcs模块x队列n获取触发事件状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @retval bool
 *        false 没有触发事件
 *        true 发生了一个触发事件
 */
KF_INLINE bool Adcs_LL_IsQueueEventOccur(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    return (ADCS_PTR->ADCS_QSTA[AdcModule][AdcQueue].bits.EF);
}

/**
 * @brief Adcs模块x队列n获取队列寄存器0
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE Adcs_Queue_Reg_t Adcs_LL_GetQueueReg0(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    Adcs_Queue_Reg_t ret;
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    ret.reg = ADCS_PTR->ADCS_Q0R[AdcModule][AdcQueue].reg;
    return ret;
}

/**
 * @brief Adcs模块x队列n获取队列备份寄存器
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE Adcs_Queue_Reg_t Adcs_LL_GetQueueRegBackup(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    Adcs_Queue_Reg_t ret;
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    ret.reg = ADCS_PTR->ADCS_QBKU[AdcModule][AdcQueue].reg;
    return ret;
}

/**
 * @brief Adcs模块x队列n写入队列
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param Config 队列配置指针
 *        RequestChannelNumber 请求通道
 *        RefillEnabled 自动填充控制
 *        SourceInterruptEnabled 中断信号产生控制
 *        ExternTriggerWaitEnabled 触发信号等待控制
 *        PullDownEnabled 下拉诊断配置
 *        MultiplexerDiagPullDownEnabled 多路复用器下拉设备使能
 *        MultiplexerDiagPullUpEnabled   多路复用器上拉设备使能
 *        ConvertDiagEnabled 转换器诊断使能
 *        DiagPullDevice 转换器诊断拉动设备选择
 *
 * @return KF_INLINE
 */
KF_INLINE void
Adcs_LL_AddQueue(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const Adcs_Queue_InputReg_t *Config)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL((*Config).bits.RequestChannelNumber));
    ADCS_PTR->ADCS_QIN[AdcModule][AdcQueue].reg = (*Config).reg;
}

/**
 * @brief Adcs模块x队列n设置触发定时器工作模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param Mode
 *        ADCS_QUEUE_SEQUENCE_MODE_DISABLED 触发定时器关闭
 *        ADCS_QUEUE_SEQUENCE_MODE_1 从第 1 个定时器周期开始，每个周期产生一个触发信号
 *        ADCS_QUEUE_SEQUENCE_MODE_2 只在第 2 个定时器周期产生一个触发信号
 *        ADCS_QUEUE_SEQUENCE_MODE_3 从第 2 个定时器周期开始，每个周期产生一个触发信号
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetQueueSequenceMode(
  const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const Adcs_Queue_SequenceMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE_SEQUENCE_MODE(AdcQueue));
    REG_WRITE(ADCS_PTR->ADCS_REQTCTL[AdcModule][AdcQueue].bits.SEQMOD, Mode);
}

/**
 * @brief Adcs模块x队列n设置触发定时器开启值
 * @details 定时触发器的开启值，定时器一旦开启，将会从该位域设定的值开始，
 * 以 16×ADCCLK 为步长不断的减1，然后再从该值开始不断的减一.
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param StartValue
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetQueueSequenceStartValue(
  const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const uint32_t StartValue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE_SEQUENCE_START_VALUE(StartValue));
    REG_WRITE(ADCS_PTR->ADCS_REQTCTL[AdcModule][AdcQueue].bits.SEQTIMSET, StartValue);
}

/**
 * @brief Adcs模块x队列n软件开启触发定时器
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_StartQueueSequenceTimerBySoftware(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    REG_WRITE(ADCS_PTR->ADCS_REQTCTL[AdcModule][AdcQueue].bits.REQTS, 1U);
}

/**
 * @brief Adcs模块x队列n使能外部信号开启触发定时器
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param Enabled
 *        false 外部触发信号启动触发定时器关闭
 *        true 外部触发信号已设定的变化沿开启触发定时器
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableQueueSequenceTimerExternTrigger(
  const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    REG_WRITE(ADCS_PTR->ADCS_REQTCTL[AdcModule][AdcQueue].bits.ENTR, Enabled);
}

/**
 * @brief Adcs模块x队列n设置定时器关断值
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param SwitchOffValue
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetQueueSequenceTimerSwitchOffValue(
  const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, const uint32_t SwitchOffValue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE_SEQUENCE_SWITCH_OFF_VALUE(SwitchOffValue));
    REG_WRITE(ADCS_PTR->ADCS_REQTCTL[AdcModule][AdcQueue].bits.SEQTIMOFF, SwitchOffValue);
}

/**
 * @brief Adcs模块x队列n获取触发定时器当前的计数值
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE uint32_t Adcs_LL_GetQueueSequenceTimerCounter(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    return (ADCS_PTR->ADCS_REQTST[AdcModule][AdcQueue].bits.SEQTIMER);
}

/**
 * @brief Adcs模块获取通道事件标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @return KF_INLINE
 */
KF_INLINE bool Adcs_LL_GetChannelEventStatus(const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    return (
      bool)(REG_BITS_READ(ADCS_PTR->ADCS_CEF[AdcModule].reg, (1U << (uint32_t)AdcChannel), ((uint32_t)AdcChannel)));
}

/**
 * @brief Adcs模块软件触发通道事件
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetChannelEventBySoftware(const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_BIT_SET(ADCS_PTR->ADCS_CEF[AdcModule].reg, (1U << ((uint32_t)AdcChannel + 16)));
}

/**
 * @brief Adcs模块x获取队列源事件状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE bool Adcs_LL_GetQueueSourceEventStatus(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    return (bool)REG_BITS_READ(ADCS_PTR->ADCS_SEF[AdcModule].reg, (1U << (uint32_t)AdcQueue), ((uint32_t)AdcQueue));
}

/**
 * @brief Adcs模块x软件触发队列源事件
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetQueueSourceEventBySoftware(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    REG_BIT_SET(ADCS_PTR->ADCS_SEF[AdcModule].reg, (1U << ((uint32_t)AdcQueue + 4)));
}

/**
 * @brief Adcs模块设置通道事件中断线
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Pointer
 *        ADCS_CHANNEL_EVENT_MODULE_SERVICE_LINE_0 选择ADCx的服务中断线0
 *        ADCS_CHANNEL_EVENT_MODULE_SERVICE_LINE_1 选择ADCx的服务中断线1
 *        ADCS_CHANNEL_EVENT_MODULE_SERVICE_LINE_2 选择ADCx的服务中断线2
 *        ADCS_CHANNEL_EVENT_MODULE_SERVICE_LINE_3 选择ADCx的服务中断线3
 *        ADCS_CHANNEL_EVENT_COMMON_SERVICE_LINE_0 选择公共服务中断线0
 *        ADCS_CHANNEL_EVENT_COMMON_SERVICE_LINE_1 选择公共服务中断线1
 *        ADCS_CHANNEL_EVENT_COMMON_SERVICE_LINE_2 选择公共服务中断线2
 *        ADCS_CHANNEL_EVENT_COMMON_SERVICE_LINE_3 选择公共服务中断线3
 *        ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_0 没有选择服务中断线
 *        ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_1 没有选择服务中断线
 *        ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_2 没有选择服务中断线
 *        ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_3 没有选择服务中断线
 *        ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_4 没有选择服务中断线
 *        ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_5 没有选择服务中断线
 *        ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_6 没有选择服务中断线
 *        ADCS_CHANNEL_EVENT_SERVICE_LINE_OFF_7 没有选择服务中断线
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetChannelEventServiceLine(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, Adcs_ChannelEventServiceLine_t Line)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL_EVENT_SERVICE_LINE(Line));
    if (AdcChannel < ADCS_CHANNEL_8)
    {
        REG_BITS_WRITE(ADCS_PTR->ADCS_CENP0[AdcModule].reg, (0xFU << ((uint32_t)AdcChannel << 2U)),
                       ((uint32_t)Line << ((uint32_t)AdcChannel << 2U)));
    }
    else
    {
        REG_BITS_WRITE(ADCS_PTR->ADCS_CENP1[AdcModule].reg, (0xFU << (((uint32_t)AdcChannel - ADCS_CHANNEL_8) << 2U)),
                       ((uint32_t)Line << (((uint32_t)AdcChannel - ADCS_CHANNEL_8) << 2U)));
    }
}

/**
 * @brief Adcs模块设置通道事件中断线
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param ResultReg 结果寄存器
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @param Line
 *        ADCS_RESULT_EVENT_MODULE_SERVICE_LINE_0 选择ADCx的服务中断线0
 *        ADCS_RESULT_EVENT_MODULE_SERVICE_LINE_1 选择ADCx的服务中断线1
 *        ADCS_RESULT_EVENT_MODULE_SERVICE_LINE_2 选择ADCx的服务中断线2
 *        ADCS_RESULT_EVENT_MODULE_SERVICE_LINE_3 选择ADCx的服务中断线3
 *        ADCS_RESULT_EVENT_COMMON_SERVICE_LINE_0 选择公共服务中断线0
 *        ADCS_RESULT_EVENT_COMMON_SERVICE_LINE_1 选择公共服务中断线1
 *        ADCS_RESULT_EVENT_COMMON_SERVICE_LINE_2 选择公共服务中断线2
 *        ADCS_RESULT_EVENT_COMMON_SERVICE_LINE_3 选择公共服务中断线3
 *        ADCS_RESULT_EVENT_SERVICE_LINE_OFF_0 没有选择服务中断线
 *        ADCS_RESULT_EVENT_SERVICE_LINE_OFF_1 没有选择服务中断线
 *        ADCS_RESULT_EVENT_SERVICE_LINE_OFF_2 没有选择服务中断线
 *        ADCS_RESULT_EVENT_SERVICE_LINE_OFF_3 没有选择服务中断线
 *        ADCS_RESULT_EVENT_SERVICE_LINE_OFF_4 没有选择服务中断线
 *        ADCS_RESULT_EVENT_SERVICE_LINE_OFF_5 没有选择服务中断线
 *        ADCS_RESULT_EVENT_SERVICE_LINE_OFF_6 没有选择服务中断线
 *        ADCS_RESULT_EVENT_SERVICE_LINE_OFF_7 没有选择服务中断线
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetResultEventServiceLine(
  const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t ResultReg, Adcs_ResultEventServiceLine_t Line)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(ResultReg));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_EVENT_SERVICE_LINE(Line));
    if (ResultReg < ADCS_RESULT_REG_8)
    {
        REG_BITS_WRITE(ADCS_PTR->ADCS_RENP0[AdcModule].reg, (0xFU << ((uint32_t)ResultReg << 2U)),
                       ((uint32_t)Line << ((uint32_t)ResultReg << 2U)));
    }
    else
    {
        REG_BITS_WRITE(ADCS_PTR->ADCS_RENP1[AdcModule].reg, (0xFU << (((uint32_t)ResultReg - ADCS_RESULT_REG_8) << 2U)),
                       ((uint32_t)Line << (((uint32_t)ResultReg - ADCS_RESULT_REG_8) << 2U)));
    }
}

/**
 * @brief Adcs模块设置源事件中断线
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @param Line
 *        ADCS_SOURCE_EVENT_MODULE_SERVICE_LINE_0 选择ADCx的服务中断线0
 *        ADCS_SOURCE_EVENT_MODULE_SERVICE_LINE_1 选择ADCx的服务中断线1
 *        ADCS_SOURCE_EVENT_MODULE_SERVICE_LINE_2 选择ADCx的服务中断线2
 *        ADCS_SOURCE_EVENT_MODULE_SERVICE_LINE_3 选择ADCx的服务中断线3
 *        ADCS_SOURCE_EVENT_COMMON_SERVICE_LINE_0 选择公共服务中断线0
 *        ADCS_SOURCE_EVENT_COMMON_SERVICE_LINE_1 选择公共服务中断线1
 *        ADCS_SOURCE_EVENT_COMMON_SERVICE_LINE_2 选择公共服务中断线2
 *        ADCS_SOURCE_EVENT_COMMON_SERVICE_LINE_3 选择公共服务中断线3
 *        ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_0 没有选择服务中断线
 *        ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_1 没有选择服务中断线
 *        ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_2 没有选择服务中断线
 *        ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_3 没有选择服务中断线
 *        ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_4 没有选择服务中断线
 *        ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_5 没有选择服务中断线
 *        ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_6 没有选择服务中断线
 *        ADCS_SOURCE_EVENT_SERVICE_LINE_OFF_7 没有选择服务中断线
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetSourceEventServiceLine(
  const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue, Adcs_SourceEventServiceLine_t Line)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_SOURCE_EVENT_SERVICE_LINE(Line));
    REG_BITS_WRITE(ADCS_PTR->ADCS_SENP[AdcModule].reg, (0xFU << ((uint32_t)AdcQueue << 2U)),
                   ((uint32_t)Line << ((uint32_t)AdcQueue << 2U)));
}

/**
 * @brief Adcs模块软件触发中断线
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Line
 *        ADCS_SOFT_TRIGGER_MODULE_SERVICE_LINE_0 软件激活ADCx的服务中断线0
 *        ADCS_SOFT_TRIGGER_MODULE_SERVICE_LINE_1 软件激活ADCx的服务中断线1
 *        ADCS_SOFT_TRIGGER_MODULE_SERVICE_LINE_2 软件激活ADCx的服务中断线2
 *        ADCS_SOFT_TRIGGER_MODULE_SERVICE_LINE_3 软件激活ADCx的服务中断线3
 *        ADCS_SOFT_TRIGGER_COMMON_SERVICE_LINE_0 软件激活ADCx对应的公共服务中断线0
 *        ADCS_SOFT_TRIGGER_COMMON_SERVICE_LINE_1 软件激活ADCx对应的公共服务中断线1
 *        ADCS_SOFT_TRIGGER_COMMON_SERVICE_LINE_2 软件激活ADCx对应的公共服务中断线2
 *        ADCS_SOFT_TRIGGER_COMMON_SERVICE_LINE_3 软件激活ADCx对应的公共服务中断线3
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_TriggerServiceLineBySoftware(const Adcs_Module_t AdcModule, Adcs_SoftTriggerServiceLine_t Line)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_SOFT_TRIGGER_SERVICE_LINE(AdcModule));
    if (Line < ADCS_SOFT_TRIGGER_COMMON_SERVICE_LINE_0)
    {
        REG_BIT_SET(ADCS_PTR->ADCS_STRGACT[AdcModule].reg, (1U << (uint32_t)Line));
    }
    else
    {
        REG_BIT_SET(ADCS_PTR->ADCS_STRGACT[AdcModule].reg, (1U << ((uint32_t)Line + 4U)));
    }
}

/**
 * @brief 设置Adcs模块外部多路复用器
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *        ADCS_EXTERN_MUX_MODE_SOFT_CONTROL 软件控制
 *        ADCS_EXTERN_MUX_MODE_SOFT_STEADY 稳步模式
 *        ADCS_EXTERN_MUX_MODE_SOFT_SINGLE_STEP 单步模式
 *        ADCS_EXTERN_MUX_MODE_SOFT_SEQUENCE 顺序模式
 *        ADCS_EXTERN_MUX_MODE_SOFT_BLOCK 块模式
 * @param Code
 *        ADCS_EXTERN_MUX_CODING_BINARY 输出的多路选通控制为二进制编码
 *        ADCS_EXTERN_MUX_CODING_GRAY 输出的多路选通控制为格雷编码
 * @param SampleTime
 *        ADCS_EXTERN_MUX_SAMPLE_TIME_SETTING_CHANGE 当外部多路复用器通道改变时，
 *                                    选择 ESAMPTIME作为采样时间控制，否则选择 SAMPTIME 进行控制
 *        ADCS_EXTERN_MUX_SAMPLE_TIME_ALWAYS 所有的外部通道都采用 ESAMPTIME 作为采样时间
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetExternMuxConfig(const Adcs_Module_t AdcModule, Adcs_ExternMuxMode_t Mode,
                                          Adcs_ExternMuxCodingScheme_t Code, Adcs_ExternMuxSampleTime_t SampleTime)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_EMUX_MODE(Mode));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_EMUX_CODING(Code));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_EMUX_SAMPLE_TIME(SampleTime));
    REG_WRITE(ADCS_PTR->ADCS_EMUXCTL[AdcModule].bits.EMXWC, 1U);
    REG_WRITE(ADCS_PTR->ADCS_EMUXCTL[AdcModule].bits.EMUXMOD, Mode);
    REG_WRITE(ADCS_PTR->ADCS_EMUXCTL[AdcModule].bits.EMXCOD, Code);
    REG_WRITE(ADCS_PTR->ADCS_EMUXCTL[AdcModule].bits.EMXWC, 0U);
}

/**
 * @brief Adcs模块选择多路复用器开始外部通道
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Channel
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_0 外部通道0
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_1 外部通道1
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_2 外部通道2
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_3 外部通道3
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_4 外部通道4
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_5 外部通道5
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_6 外部通道6
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_7 外部通道7
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SelectExternMuxStartChannel(const Adcs_Module_t AdcModule, Adcs_ExternMuxSelectChannel_t Channel)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_EMUX_SELECT_CHANNEL(Channel));
    REG_WRITE(ADCS_PTR->ADCS_EMUXCTL[AdcModule].bits.EMUXSEL, Channel);
}

/**
 * @brief Adcs模块选择多路复用器块模式外部通道
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Channel
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_0 外部通道0
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_1 外部通道1
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_2 外部通道2
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_3 外部通道3
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_4 外部通道4
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_5 外部通道5
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_6 外部通道6
 *        ADCS_EXTERN_MUX_SELECT_CHANNEL_7 外部通道7
 * @return KF_INLINE
 */
KF_INLINE void
Adcs_LL_SelectExternMuxBlockModeChannel(const Adcs_Module_t AdcModule, Adcs_ExternMuxSelectChannel_t Channel)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_EMUX_SELECT_CHANNEL(Channel));
    REG_WRITE(ADCS_PTR->ADCS_EMUXCTL[AdcModule].bits.EMUXCCB, Channel);
}

/**
 * @brief Adcs模块获取当前多路复用器选择的通道号
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval Adcs_ExternMuxSelectChannel_t 当前多路复用器选择的通道号
 */
KF_INLINE Adcs_ExternMuxSelectChannel_t Adcs_LL_GetExternMuxCurrentChannel(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (Adcs_ExternMuxSelectChannel_t)(ADCS_PTR->ADCS_EMUXCTL[AdcModule].bits.EMUXACT);
}

/**
 * @brief Adcs模块设置内部通道连接至外部多路复用器
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Status
 *        fasle 模拟输入通道不连接至外部多路复用器
 *        true 模拟输入通道连接至外部多路复用器
 * @return KF_INLINE
 */
KF_INLINE void
Adcs_SwitchAnalogChannelToExternMux(const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_BITS_WRITE(ADCS_PTR->ADCS_EMUXCSEL[AdcModule].bits.EMUXCH, (1U << (uint32_t)AdcChannel),
                   ((uint32_t)Status << (uint32_t)AdcChannel));
}

/**
 * @brief Adcs模块读取结果有效标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param ResultReg 结果寄存器
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @retval bool
 *        false 结果寄存器ADCx_RESy.RESULT 没有新的有效值或未读取的值
 *        true 结果寄存器ADCx_RESy.RESULT 写入新值，或之前的值还未读取
 */
KF_INLINE bool Adcs_GetResultRegValidStatus(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t ResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(ResultReg));
    return (bool)(REG_BITS_READ(ADCS_PTR->ADCS_VF[AdcModule].reg, (1U << (uint32_t)ResultReg), ((uint32_t)ResultReg)));
}

/**
 * @brief Adcs模块清除结果寄存器有效标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param ResultReg 结果寄存器
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @return KF_INLINE
 */
KF_INLINE bool Adcs_LL_ClearResultRegValidStatus(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t ResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(ResultReg));
    return (bool)(REG_BIT_SET(ADCS_PTR->ADCS_VF[AdcModule].reg, (1U << (uint32_t)ResultReg)));
}

/**
 * @brief Adcs模块选择通道比较中下边界值
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Boundary
 *        ADCS_CHANNEL_BOUNDARY_GROUP0 使用组边界值 0
 *        ADCS_CHANNEL_BOUNDARY_GROUP1 使用组边界值 1
 *        ADCS_CHANNEL_BOUNDARY_GLOBAL0 使用全局边界值 0
 *        ADCS_CHANNEL_BOUNDARY_GLOBAL1 使用全局边界值 1
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SelectChannelLowerBoundary(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const Adcs_BoundarySelection_t Boundary)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL_BOUNDARY(Boundary));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.BNDSELL, Boundary);
}

/**
 * @brief Adcs模块选择通道比较中上边界值
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Boundary
 *        ADCS_CHANNEL_BOUNDARY_GROUP0 使用组边界值 0
 *        ADCS_CHANNEL_BOUNDARY_GROUP1 使用组边界值 1
 *        ADCS_CHANNEL_BOUNDARY_GLOBAL0 使用全局边界值 0
 *        ADCS_CHANNEL_BOUNDARY_GLOBAL1 使用全局边界值 1
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SelectChannelUpperBoundary(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const Adcs_BoundarySelection_t Boundary)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL_BOUNDARY(Boundary));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.BNDSELU, Boundary);
}

/**
 * @brief Adcs模块选择通道事件产生条件
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Boundary
 *        ADCS_CHANNEL_BOUNDARY_GROUP0 使用组边界值 0
 *        ADCS_CHANNEL_BOUNDARY_GROUP1 使用组边界值 1
 *        ADCS_CHANNEL_BOUNDARY_GLOBAL0 使用全局边界值 0
 *        ADCS_CHANNEL_BOUNDARY_GLOBAL1 使用全局边界值 1
 * @param Mode
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SelectChannelEventCompareMode(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const Adcs_ChannelCompareMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL_COMPARE_MODE(Mode));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.CHEVMOD, Mode);
}

/**
 * @brief Adcs模块选择通道参考电压
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Synchonize
 *        false 没有同步转换请求
 *        true 该通道有同步转换请求
 * @return KF_INLINE
 */
KF_INLINE void
Adcs_LL_SetChannelSyncRequest(const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const bool Synchonize)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.SYNC, Synchonize);
}

/**
 * @brief Adcs模块设置参考电压
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Voltage
 *        ADCS_CHANNEL_REFERENCE_VOLT_VAREF 选择 VAREF 作为转换参考电压
 *        ADCS_CHANNEL_REFERENCE_VOLT_CHANNEL0 选择通道 0 的输入电压作为转换参考电压
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetChannelReferenceVoltage(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const Adcs_ChannelReferenceVolt_t Voltage)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL_REFERENCE_VOLT(Voltage));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.REFSEL, Voltage);
}

/**
 * @brief Adcs模块选择通道上边界
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Voltage
 *        ADCS_CHANNEL_UPPER_BOUNDARY_BNDSELU 通过位域 BNDSELU 选择上边界值，通过位域BNDSELL 选择下边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES1 使用结果寄存器 ADCx_RES1 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES2 使用结果寄存器 ADCx_RES2 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES3 使用结果寄存器 ADCx_RES3 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES4 使用结果寄存器 ADCx_RES4 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES5 使用结果寄存器 ADCx_RES5 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES6 使用结果寄存器 ADCx_RES6 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES7 使用结果寄存器 ADCx_RES7 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES8 使用结果寄存器 ADCx_RES8 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES9 使用结果寄存器 ADCx_RES9 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES10 使用结果寄存器 ADCx_RES10 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES11 使用结果寄存器 ADCx_RES11 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES12 使用结果寄存器 ADCx_RES12 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES13 使用结果寄存器 ADCx_RES13 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES14 使用结果寄存器 ADCx_RES14 作为上边界值
 *        ADCS_CHANNEL_UPPER_BOUNDARY_RES15 使用结果寄存器 ADCx_RES15 作为上边界值
 *
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetChannelBoundaryMode(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const Adcs_ChannelUpperBoundarySelection_t Boundary)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL_UPPER_BOUNDARY(Boundary));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.BNDSELX, Boundary);
}

/**
 * @brief Adcs模块选择通道目标结果寄存器
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param ResultReg 结果寄存器
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 *
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SelectChannelResultRegister(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const Adcs_Result_Reg_t ResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(ResultReg));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.RESREG, ResultReg);
}

/**
 * @brief Adcs模块选择通道选择全局结果寄存器
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param GlobalRegSelected
 *         false 选择 ADC 内部结果寄存器
 *         true 选择全局结果寄存器
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SelectChannelGlobalResultReg(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const bool GlobalRegSelected)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.RESTGT, GlobalRegSelected);
}

/**
 * @brief Adcs模块通道选择结果左对齐
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param rightAlignedStorage
 *         false 右对齐
 *         true 左对齐
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetResultLeftAligned(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const bool leftAlignedStorage)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.RESPOS, leftAlignedStorage);
}

/**
 * @brief Adcs模块通道设置额外采样时间
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param SampleTime
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_0 0个额外的模拟时钟周期
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_1 1个额外的模拟时钟周期
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_2 2个额外的模拟时钟周期
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_4 4个额外的模拟时钟周期
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_8 8个额外的模拟时钟周期
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_16  16个额外的模拟时钟周期
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_32  32个额外的模拟时钟周期
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_64  64个额外的模拟时钟周期
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_128 128个额外的模拟时钟周期
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_256 256个额外的模拟时钟周期
 *        ADCS_CHANNEL_ADDITION_SAMPLE_TIME_512 512个额外的模拟时钟周期
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetAdditionalSampleTime(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const Adcs_ChannelSampleTime_t SampleTime)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADCS_CHANNEL_ADDITION_SAMPLE_TIME(AdcChannel));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.BNDSELL, SampleTime);
}

/**
 * @brief Adcs模块通道断路诊断/输入缓冲预充电选择
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param SampleTime
 *        ADCS_CHANNEL_PRECHARGE_MODE_INPUT
 *        ADCS_CHANNEL_PRECHARGE_MODE_VAREF
 *        ADCS_CHANNEL_PRECHARGE_MODE_VAGND
 * @param Mode
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SelectRechargeMode(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const Adcs_ChannelPrechargeMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL_PRECHARGE_MODE(Mode));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.PERCCH, Mode);
}

/**
 * @brief
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param DetectEnabled
 *        false 断路诊断关闭/输入缓冲关闭
 *        true 断路诊断使能/输入缓冲打开
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_ChannelEnableBrokenLineDetection(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const bool DetectEnabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_WRITE(ADCS_PTR->ADCS_CHCTL[AdcModule][AdcChannel].bits.PERCEN, DetectEnabled);
}

/**
 * @brief Adcs模块设置转换结果被覆盖次数
 * @details 只有当转换结果被覆盖到一定次数后，ADCx_RESy.VF 标志位才置 1, 只适合非数据压缩模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @param CoverNumOfTimes
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetResultCoverTimes(
  const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg, const uint8_t CoverNumOfTimes)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    REG_WRITE(ADCS_PTR->ADCS_RCTL[AdcModule][AdcResultReg].bits.RINTCNT, CoverNumOfTimes);
}

/**
 * @brief Adcs模块设置数据压缩次数
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @param DataReductionNumOfTimes
 *        ADCS_RESULT_DATA_REDUCTION_0
 *        ADCS_RESULT_DATA_REDUCTION_1
 *        ADCS_RESULT_DATA_REDUCTION_2
 *        ADCS_RESULT_DATA_REDUCTION_3
 *        ADCS_RESULT_DATA_REDUCTION_4
 *        ADCS_RESULT_DATA_REDUCTION_5
 *        ADCS_RESULT_DATA_REDUCTION_6
 *        ADCS_RESULT_DATA_REDUCTION_7
 *        ADCS_RESULT_DATA_REDUCTION_8
 *        ADCS_RESULT_DATA_REDUCTION_9
 *        ADCS_RESULT_DATA_REDUCTION_10
 *        ADCS_RESULT_DATA_REDUCTION_11
 *        ADCS_RESULT_DATA_REDUCTION_12
 *        ADCS_RESULT_DATA_REDUCTION_13
 *        ADCS_RESULT_DATA_REDUCTION_14
 *        ADCS_RESULT_DATA_REDUCTION_15
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetResultDataReductionTimes(
  const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg,
  const Adcs_ResultDataReduction_t DataReductionNumOfTimes)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_DATA_REDUCTION(DataReductionNumOfTimes));
    REG_WRITE(ADCS_PTR->ADCS_RCTL[AdcModule][AdcResultReg].bits.DRCTR, DataReductionNumOfTimes);
}

/**
 * @brief Adcs模块设置数据FIR、IIR滤波系数
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @param DataReductionNumOfTimes
 *        ADCS_RESULT_DATA_FIR_COEFF_0
 *        ADCS_RESULT_DATA_FIR_COEFF_1
 *        ADCS_RESULT_DATA_FIR_COEFF_2
 *        ADCS_RESULT_DATA_FIR_COEFF_3
 *        ADCS_RESULT_DATA_FIR_COEFF_4
 *        ADCS_RESULT_DATA_FIR_COEFF_5
 *        ADCS_RESULT_DATA_FIR_COEFF_6
 *        ADCS_RESULT_DATA_FIR_COEFF_7
 *        ADCS_RESULT_DATA_FIR_COEFF_8
 *        ADCS_RESULT_DATA_FIR_COEFF_9
 *        ADCS_RESULT_DATA_FIR_COEFF_10
 *        ADCS_RESULT_DATA_FIR_COEFF_11
 *        ADCS_RESULT_DATA_FIR_COEFF_12
 *        ADCS_RESULT_DATA_FIR_COEFF_13
 *        ADCS_RESULT_DATA_IIR_COEFF_0
 *        ADCS_RESULT_DATA_IIR_COEFF_1
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetResultDataFIRCoeff(
  const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg, const Adcs_ResultDataFIRCoeff_t DataFIRCoeff)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_DATA_FIR_COEFF(DataFIRCoeff));
    REG_WRITE(ADCS_PTR->ADCS_RCTL[AdcModule][AdcResultReg].bits.DRCTR, DataFIRCoeff);
}

/**
 * @brief Adcs模块设置结果数据修改模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @param Mode
 *        ADCS_RESULT_STANDARD_REDUCTION 数据压缩
 *        ADCS_RESULT_DATA_FILTER 数据滤波
 *        ADCS_RESULT_DIFFERENTIAL 差分模式
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetResultDataModificationMode(
  const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg, const Adcs_ResultDataModificationMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_DATA_MODIFICATION_MODE(AdcResultReg));
    REG_WRITE(ADCS_PTR->ADCS_RCTL[AdcModule][AdcResultReg].bits.DMM, AdcResultReg);
}

/**
 * @brief Adcs模块清除结果覆盖标志CF
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_ClearResultCoverFlag(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    REG_WRITE(ADCS_PTR->ADCS_RCTL[AdcModule][AdcResultReg].bits.CFCLR, 1U);
}

/**
 * @brief Adcs模块使能/禁止等待-阅读模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @param WaitForReadEnabled
 *        false 覆盖模式
 *        true 等待-阅读模式
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableResultWaitForReadMode(
  const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg, const bool WaitForReadEnabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    REG_WRITE(ADCS_PTR->ADCS_RCTL[AdcModule][AdcResultReg].bits.WFR, WaitForReadEnabled);
}

/**
 * @brief Adcs模块设置结果FIFO模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @param Mode
 *        ADCS_RESULT_FIFO_SEPERATE_RESULT_REG 单独式结果寄存器
 *        ADCS_RESULT_FIFO_FIFO_STRUCTURE FIFO 的一部分
 *        ADCS_RESULT_FIFO_MAX_MODE 最大值模式
 *        ADCS_RESULT_FIFO_MIN_MODE 最小值模式
 * @retval void
 */
KF_INLINE void Adcs_LL_SetResultFifoMode(
  const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg, const Adcs_ResultFifoMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_FIFO_MODE(Mode));
    REG_WRITE(ADCS_PTR->ADCS_RCTL[AdcModule][AdcResultReg].bits.FEN, Mode);
}

/**
 * @brief Adcs模块设置结果事件服务中断使能
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @param Enabled
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableResultServiceRequest(
  const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    REG_WRITE(ADCS_PTR->ADCS_RCTL[AdcModule][AdcResultReg].bits.SRGEN, Enabled);
}

/**
 * @brief Adcs模块获取结果寄存器转换结果
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @retval uint16_t 转换结果
 */
KF_INLINE uint16_t Adcs_LL_GetConvertResult(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    return (ADCS_PTR->ADCS_RES[AdcModule][AdcResultReg].bits.RESULT);
}

/**
 * @brief Adcs模块获取结果寄存器转换结果通道号
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @retval uint32_t 转换结果通道号
 */
KF_INLINE uint32_t Adcs_LL_GetConvertChannel(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    return (ADCS_PTR->ADCS_RES[AdcModule][AdcResultReg].bits.CHNR);
}

/**
 * @brief Adcs模块获取结果寄存器转换结果多路复用器
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @retval uint32_t 转换结果多路复用器
 */
KF_INLINE uint32_t Adcs_LL_GetConvertMux(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    return (ADCS_PTR->ADCS_RES[AdcModule][AdcResultReg].bits.EMUX);
}

/**
 * @brief Adcs模块获取结果寄存器转换结果队列号
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @retval uint32_t 转换结果来自的队列号
 */
KF_INLINE uint32_t Adcs_LL_GetConvertQueue(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    return (ADCS_PTR->ADCS_RES[AdcModule][AdcResultReg].bits.CRS);
}

/**
 * @brief Adcs模块获取结果寄存器数据被覆盖标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @retval bool
 *        false 该结果寄存器 RESULT 位域的值没有被覆盖
 *        true 该结果寄存器 RESULT 位域的值没有被覆盖
 */
KF_INLINE bool Adcs_LL_GetResultOverWriteStatus(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    return (ADCS_PTR->ADCS_RES[AdcModule][AdcResultReg].bits.CF);
}

/**
 * @brief Adcs模块获取结果寄存器数据有效标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @retval bool
 *        false 没有新的数据写入到 RESULT 中
 *        true 一个新的数据被写入位域 RESULT 中，或之前的数据没有被读取
 */
KF_INLINE bool Adcs_LL_GetResultValidStatus(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    return (ADCS_PTR->ADCS_RES[AdcModule][AdcResultReg].bits.VF);
}

/**
 * @brief Adcs模块设置比较器采样时间
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param SampleTime
 *        ADCS_CMP_SAMPLE_TIME_0 采样时间添加0个额外的模拟时钟
 *        ADCS_CMP_SAMPLE_TIME_1 采样时间添加1个额外的模拟时钟
 *        ADCS_CMP_SAMPLE_TIME_2 采样时间添加2个额外的模拟时钟
 *        ADCS_CMP_SAMPLE_TIME_4 采样时间添加4个额外的模拟时钟
 *        ADCS_CMP_SAMPLE_TIME_8 采样时间添加8个额外的模拟时钟
 *        ADCS_CMP_SAMPLE_TIME_16 采样时间添加16个额外的模拟时钟
 *        ADCS_CMP_SAMPLE_TIME_32 采样时间添加32个额外的模拟时钟
 *        ADCS_CMP_SAMPLE_TIME_64 采样时间添加64个额外的模拟时钟
 *        ADCS_CMP_SAMPLE_TIME_128 采样时间添加128个额外的模拟时钟
 *        ADCS_CMP_SAMPLE_TIME_256 采样时间添加256个额外的模拟时钟
 *        ADCS_CMP_SAMPLE_TIME_512 采样时间添加512个额外的模拟时钟
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPSampleTime(const Adcs_Module_t AdcModule, const Adcs_CMPSampleTime_t SampleTime)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADCS_CMP_SAMPLE_TIME(SampleTime));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.CPWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.STCF, SampleTime);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.CPWC, 0U);
}

/**
 * @brief Adcs模块选择比较器预充电电压
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SelectCMPPreChargeMode(const Adcs_Module_t AdcModule, const Adcs_CmpChannelPrechargeMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_RECHARGE_MODE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.PERCCH, Mode);
}

/**
 * @brief Adcs模块使能比较器服务中断请求
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        fasle 禁止服务中断信号的产生
 *        true 使能服务中断信号的产生
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableCMPServiceRequest(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.INT_EN, Enabled);
}

/**
 * @brief Adcs模块使能比较器前校准
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        fasle 无影响
 *        true 前校准使能
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableCMPPreCalibration(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.QJZ, Enabled);
}

/**
 * @brief Adcs模块设置比较器通道事件产生模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *        ADCS_CMP_CHANNEL_EVENT_NEVER 不产生通道事件
 *        ADCS_CMP_CHANNEL_EVENT_ABOVE_COMPARE_VALUE 当模拟输入值比比较值高时可以产生通道事件
 *        ADCS_CMP_CHANNEL_EVENT_BELOW_COMPARE_VALUE 当模拟输入值比比较值低时可以产生通道事件
 *        ADCS_CMP_CHANNEL_EVENT_ABOVE_OR_BELOW_COMPARE_VALUE 当模拟输入值高于或低于比较值时都可以产生通道事件
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPChannelEventMode(const Adcs_Module_t AdcModule, const Adcs_CMPChannelEventMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_CHANNEL_EVENT_MODE(Mode));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.CPWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.CHEVMOD, Mode);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.CPWC, 0U);
}

/**
 * @brief Adcs模块设置比较器模拟时钟分频
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Divider
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_2_1
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_2
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_3
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_4
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_5
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_6
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_7
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_8
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_9
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_10
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_11
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_12
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_13
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_14
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_15
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_16
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_17
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_18
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_19
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_20
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_21
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_22
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_23
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_25
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_26
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_27
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_28
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_29
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_30
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_31
 *        ADCS_CMP_ANALOG_CLOCK_DIVIDER_32
 * @return KF_INLINE
 */
KF_INLINE void
Adcs_LL_SetCMPAnalogClockDivider(const Adcs_Module_t AdcModule, const Adcs_CMPAnalogClockDivider_t Divider)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_ANALOG_CLOCK_DIVIDER(Divider));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.CPWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.CLKPDIV, Divider);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.CPWC, 0U);
}

/**
 * @brief Adcs模块选择比较器外部触发源
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Trigger
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SelectCMPExternTrigger(const Adcs_Module_t AdcModule, const Adcs_CMPExternTrigger_t Trigger)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_EXTERN_TRIGGER(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTSEL, Trigger);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTWC, 0U);
}

/**
 * @brief Adcs模块使能比较器外部触发信号翻转
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false 外部触发输入信号不翻转
 *        true 外部触发输入信号翻转
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableCMPExternTriggerToggle(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTPOL, Enabled);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTWC, 0U);
}

/**
 * @brief Adcs模块设置比较器触发模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *        ADCS_CMP_TRIGGER_MODE_NO_TRIGGER 外部触发信号关闭
 *        ADCS_CMP_TRIGGER_MODE_FALLING_EDGE 触发输入信号上升沿有效
 *        ADCS_CMP_TRIGGER_MODE_RISING_EDGE 触发输入信号下降沿有效
 *        ADCS_CMP_TRIGGER_MODE_ANY_EDGE 触发输入信号上升沿和下降沿都有效
 * @return KF_INLINE
 */
KF_INLINE void
Adcs_LL_SetCMPTriggerOperationMode(const Adcs_Module_t AdcModule, const Adcs_CMPTriggerOperationMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_TRIGGER_MODE(Mode));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTMOD, Mode);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTWC, 0U);
}

/**
 * @brief Adcs模块设置比较器门控模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *  ADCS_CMP_GATE_MODE_NO_GATE 没有门功能
 *  ADCS_CMP_GATE_MODE_ALTERNATE_VALUE_MODE 交替值模式
 *  ADCS_CMP_GATE_MODE_LOCK_BOUNDARY_VALUE_MODE 锁边界值模式
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPGateMode(const Adcs_Module_t AdcModule, const Adcs_CMPGateOperationMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_GATE_MOD(Mode));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.GTMOD, Mode);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTWC, 0U);
}

/**
 * @brief Adcs模块设置比较器通道
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Channel
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPChannel(const Adcs_Module_t AdcModule, const uint8_t Channel)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_CHANNEL(Channel));
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.FCCHNR, Channel);
    REG_WRITE(ADCS_PTR->CMP_CCTL[AdcModule].bits.XTWC, 0U);
}

/**
 * @brief Adcs模块设置比较器运行模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *         ADCS_CMP_STOP 停止进行比较
 *         ADCS_CMP_ALWAYS_RUN 一直运行
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPRunMode(const Adcs_Module_t AdcModule, const Adcs_CMPRunMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_RUN_MODE(Mode));

    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.RUNCOMP, Mode);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 0U);
}

/**
 * @brief Adcs模块设置比较器梯度工作模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *        ADCS_CMP_RAMP_RUN_STOP 梯度停止工作
 *        ADCS_CMP_RAMP_RUN_MODE_1 当 ADCx_RAMPCTL0 被写入值时就立刻开始
 *        ADCS_CMP_RAMP_RUN_MODE_2 触发输入信号变化沿符合变化就可以开始
 *        ADCS_CMP_RAMP_RUN_MODE_3 当 ADCx_RAMPCTL0 被写入值时就立刻开始工作，
 *                                                               在触发输入信号的有效沿时停止工作
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPRampRunMode(const Adcs_Module_t AdcModule, const Adcs_CMPRampRunMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_RAMP_RUN_MODE(Mode));
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.RUNRAMP, Mode);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 0U);
}

/**
 * @brief Adcs模块设置比较器梯度变化方向
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Direction
 *        ADCS_CMP_RAMP_DOWN 梯度向下变化，当梯度值小于等于 FCRCOMPB 时停止变化
 *        ADCS_CMP_RAMP_UP 梯度向上变化，当梯度值大于等于 FCRCOMPB 时停止变化
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPRampDirection(const Adcs_Module_t AdcModule, const Adcs_CMPRampDirection_t Direction)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_RAMP_DIRECTION(Direction));
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCRDIR, Direction);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 0U);
}

/**
 * @brief Adcs模块使能比较器模拟转换器
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false  模拟转换器关闭
 *        true  正常运行
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableCMPAnalogConverter(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.ANON, Enabled);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 0U);
}

/**
 * @brief Adcs模块设置比较器模拟时钟同步延迟
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Delay
 * ADCS_CMP_ANALOG_DELAY_0 没有延迟
 * ADCS_CMP_ANALOG_DELAY_1 延迟 1 个时钟周期
 * ADCS_CMP_ANALOG_DELAY_2 延迟 2 个时钟周期
 * ADCS_CMP_ANALOG_DELAY_3 延迟 3 个时钟周期
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPAnalogClockDelay(const Adcs_Module_t AdcModule, const Adcs_CMPAnalogClkDelay_t Delay)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_ANALOG_DELAY(Delay));
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.ACSD, Delay);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 0U);
}

/**
 * @brief Adcs模块设置比较器触发间隔
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Interval
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPTriggerInterval(const Adcs_Module_t AdcModule, const uint8_t Interval)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCRTRIV, Interval);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 0U);
}

/**
 * @brief Adcs模块设置比较器中断请求产生条件
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Condition
 *        ADCS_CMP_REQUEST_GENERATE_CONDITION_OFF 服务中断信号关闭
 *        ADCS_CMP_REQUEST_GENERATE_CONDITION_RAMP_OFF 当梯度值变化到最后时产生一个服务中断信号
 *        ADCS_CMP_REQUEST_GENERATE_CONDITION_NEW_VALUE 当 FCREF 被写入新的值时产生一个服务中断信号
 *        ADCS_CMP_REQUEST_GENERATE_CONDITION_NEW_RESULT 比较结果变化沿符合要求时产生一个服务中断信号
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPRequestGeneratedCondition(
  const Adcs_Module_t AdcModule, const Adcs_CMPRequestGenerateCondition_t Condition)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_REQUEST_GENERATE_CONDITION(Condition));
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.SRG, Condition);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 0U);
}

/**
 * @brief Adcs模块设置比较器自动更新模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *        ADCS_CMP_AUTO_UPDATE_MODE_SOFTWARE 软件写入
 *        ADCS_CMP_AUTO_UPDATE_MODE_ALTERNATE_VALUE 交替值写入
 *        ADCS_CMP_AUTO_UPDATE_MODE_RAMP_COUNTER 梯度变化值，将梯度的变化值写入 FCREF 中
 *        ADCS_CMP_AUTO_UPDATE_MODE_ANALOG_SOURCE HDI 口写入，将 ADC 的第 16 个结果寄存器写入到FCREF 中
 * @retval void
 */
KF_INLINE void
Adcs_LL_SetCMPAutomaticUpdateMode(const Adcs_Module_t AdcModule, const Adcs_CMPAutomaticUpdateMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_AUTO_UPDATE_MODE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.AUE, Mode);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 0U);
}

/**
 * @brief Adcs模块使能比较器同步采样
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false  没有同步操作
 *        true  采样启动同步于相位同步信号
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableCMPSynchronizeSample(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.SSE, Enabled);
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCMWC, 0U);
}

/**
 * @brief Adcs模块设置比较器参考值
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param ReferenceValue
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPReferenceValue(const Adcs_Module_t AdcModule, const uint16_t ReferenceValue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_REFERENCE_VALUE(ReferenceValue));
    REG_WRITE(ADCS_PTR->CMP_MOD[AdcModule].bits.FCREF, ReferenceValue);
}

/**
 * @brief Adcs模块设置比较器梯度值A
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param ValueA
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPValueA(const Adcs_Module_t AdcModule, const uint16_t ValueA)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_REFERENCE_VALUE(ValueA));
    REG_WRITE(ADCS_PTR->CMP_RAMPCTL0[AdcModule].bits.FSWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_RAMPCTL0[AdcModule].bits.FCRCOMPA, ValueA);
    REG_WRITE(ADCS_PTR->CMP_RAMPCTL0[AdcModule].bits.FSWC, 0U);
}

/**
 * @brief Adcs模块设置比较器梯度值B
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param ValueA
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPValueB(const Adcs_Module_t AdcModule, const uint16_t ValueB)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_REFERENCE_VALUE(ValueB));

    REG_WRITE(ADCS_PTR->CMP_RAMPCTL1[AdcModule].bits.FCRCOMPB, ValueB);
}

/**
 * @brief Adcs模块设置比较器预充电采样时间
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Cycle
 *        ADCS_CMP_PRECHARGE_OFF 不进行预充电配置
 *        ADCS_CMP_PRECHARGE_CYCLE_1 预充电 1 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_2 预充电 2 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_3 预充电 3 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_4 预充电 4个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_5 预充电 5 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_6 预充电 6 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_7 预充电 7 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_8 预充电 8 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_9 预充电 9 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_10 预充电 10 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_11 预充电 11 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_12 预充电 12 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_13 预充电 13 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_14 预充电 14 个模拟时钟周期
 *        ADCS_CMP_PRECHARGE_CYCLE_15 预充电 15 个模拟时钟周期
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPPrechargeCycle(const Adcs_Module_t AdcModule, const Adcs_CMPPreChargeCycle_t Cycle)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_PRECHARGE_CYCLE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_RAMPCTL0[AdcModule].bits.FSWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_RAMPCTL0[AdcModule].bits.AIPF, Cycle);
    REG_WRITE(ADCS_PTR->CMP_RAMPCTL0[AdcModule].bits.FSWC, 0U);
}

/**
 * @brief Adcs模块设置比较器梯度值变化时间间隔
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Width
 *        00H 8 个 ADCCLK 时钟周期
 *        01H 16 个 ADCCLK 时钟周期
 *        ...
 *        FFH 2048 个 ADCCLK 时钟周期
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetCMPRampStepWidth(const Adcs_Module_t AdcModule, const uint8_t Width)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_RAMPCTL0[AdcModule].bits.FSWC, 1U);
    REG_WRITE(ADCS_PTR->CMP_RAMPCTL0[AdcModule].bits.FCRSTEP, Width);
    REG_WRITE(ADCS_PTR->CMP_RAMPCTL0[AdcModule].bits.FSWC, 0U);
}

/**
 * @brief Adcs模块获取比较器边界标志位
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @return KF_INLINE
 */
KF_INLINE bool Adcs_LL_GetCMPBoundaryFlagStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (ADCS_PTR->CMP_BOUNDF[AdcModule].bits.BFL);
}

/**
 * @brief Adcs模块边界标志位触发中断产生使能控制
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false 中断禁止
 *        true 使能边界标志位触发中断线
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableCMPBoundaryServiceRequest(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_BOUNDF[AdcModule].bits.BF_INT_EN, Enabled);
}

/**
 * @brief Adcs模块选择边界标志激活模式
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Mode
 *        ADCS_CMP_BOUNDARY_ACTIVATION_MODE_0 比较结果值FCR=1时，将BFL置1，当FCR=0时，将BFL清零
 *        ADCS_CMP_BOUNDARY_ACTIVATION_MODE_1 比较结果值FCR=0时，将BFL置1，当FCR=1时，将BFL清零
 * @return KF_INLINE
 */
KF_INLINE void
Adcs_LL_SelectCMPBoundaryFlagActivationMode(const Adcs_Module_t AdcModule, const Adcs_CMPBoundaryActivationMode_t Mode)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_BOUNDARY_ACTIVATION_MODE(Mode));
    REG_WRITE(ADCS_PTR->CMP_BOUNDF[AdcModule].bits.BFA, Mode);
}

/**
 * @brief Adcs模块设置BFL翻转
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false BFL值不翻转
 *        true BFL值翻转
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableCMPBoundaryFlagInversion(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_BOUNDF[AdcModule].bits.BFI, Enabled);
}

/**
 * @brief Adcs模块软件设置比较器BFL
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Control
 *        ADCS_CMP_BOUNDARY_FLAG_SW_CONTROL_NO_ACTION 无影响
 *        ADCS_CMP_BOUNDARY_FLAG_SW_CONTROL_CLEAR 清除 BFL 值
 *        ADCS_CMP_BOUNDARY_FLAG_SW_CONTROL_SET 置位 BFL 值
 *        ADCS_CMP_BOUNDARY_FLAG_SW_CONTROL_TOGGLE 翻转 BFL 值
 * @return KF_INLINE
 */
KF_INLINE void
Adcs_LL_SetCMPBoundaryFlagSWControl(const Adcs_Module_t AdcModule, const Adcs_CMPBoundaryFlagSwControl_t Control)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_BOUNDARY_FLAG_SW_CONTROL(Control));
    REG_WRITE(ADCS_PTR->CMP_BOUNDF[AdcModule].bits.BFS, Control);
}

/**
 * @brief Adcs模块比较器边界标志位模式控制
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 *        false 比较结果 FCR 不可以控制 BFL 的值
 *        true 比较结果 FCR 可以控制 BFL 的值
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableCMPFCRControlBoundaryFlag(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_BOUNDF[AdcModule].bits.BFM, Enabled);
}

/**
 * @brief Adcs模块获取比较器超时状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 通道 x 转换没有超时
 *        true 通道 x 转换超时
 */
KF_INLINE bool Adcs_LL_GetCMPTimeoutStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->CMP_BOUNDF[AdcModule].bits.TIMOUT);
}

/**
 * @brief Adcs模块清除比较器超时状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_ClearCMPTimeoutStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_BOUNDF[AdcModule].bits.TIMOUT, 1U);
}

/**
 * @brief Adcs模块使能比较器超时中断
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Enabled
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableCMPTimeoutServiceRequest(const Adcs_Module_t AdcModule, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_BOUNDF[AdcModule].bits.TIMOUT, 1U);
}

/**
 * @brief Adcs模块获取比较器结果
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 输入的模拟信号电平低于参考比较值
 *        true 输入的模拟信号电平高于参考比较值
 */
KF_INLINE bool Adcs_LL_GetFastCompareResultStatus(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->CMP_BOUNDF[AdcModule].bits.FCR);
}

/**
 * @brief Adcs模块获取比较器结果有效标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @retval bool
 *        false 没有新的比较结果写入
 *        true 一个新的比较结果被写入，或之前的比较结果未被读取
 */
KF_INLINE bool Adcs_LL_IsCMPNewResultAvailable(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->CMP_BOUNDF[AdcModule].bits.VF);
}

/**
 * @brief Adcs模块设置比较器迟滞低Delta值
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Value
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetHYSTLowerDeltaValue(const Adcs_Module_t AdcModule, const uint32_t Value)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_HYSTERESIS_VALUE(AdcModule));
    REG_WRITE(ADCS_PTR->CMP_HYST[AdcModule].bits.DELTALOW, Value);
}

/**
 * @brief Adcs模块设置比较器迟滞高Delta值
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Value
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetHYSTUpperDeltaValue(const Adcs_Module_t AdcModule, const uint32_t Value)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CMP_HYSTERESIS_VALUE(Value));
    REG_WRITE(ADCS_PTR->CMP_HYST[AdcModule].bits.DELTAUP, Value);
}

/**
 * @brief Adcs模块获取迟滞状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Index
 * @return KF_INLINE
 */
KF_INLINE bool Adcs_LL_GetHYSTStatus(const Adcs_Module_t AdcModule, const Adcs_HystGetIndex_t Index)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADCS_HYST_GET_INDEX(Index));
    return (bool)(REG_BITS_READ(
      ADCS_PTR->CMP_HYST[AdcModule].reg, (1U << (28U + (uint32_t)Index)), ((28U + (uint32_t)Index))));
}

/**
 * @brief Adcs模块获取迟滞状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param Index
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_ClearHYSTStatus(const Adcs_Module_t AdcModule, const Adcs_HystGetIndex_t Index)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADCS_HYST_GET_INDEX(Index));
    REG_BIT_SET(ADCS_PTR->CMP_HYST[AdcModule].reg, (1U << (12U + (uint32_t)Index)));
}

/**
 * @brief Adcs模块清除通道事件标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_ClearChannelEvent(const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_BIT_SET(ADCS_PTR->ADC_CEFCLR[AdcModule].reg, (1U << (uint32_t)AdcChannel));
}

/**
 * @brief Adcs模块清除通道事件标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_ClearResultEvent(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    REG_BIT_SET(ADCS_PTR->ADC_REFCLR[AdcModule].reg, (1U << (uint32_t)AdcResultReg));
}

/**
 * @brief Adcs模块清除源事件标志
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcQueue
 *        ADCS_QUEUE_0 队列0
 *        ADCS_QUEUE_1 队列1
 *        ADCS_QUEUE_2 队列2
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_ClearSourceEvent(const Adcs_Module_t AdcModule, const Adcs_Queue_t AdcQueue)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_QUEUE(AdcQueue));
    REG_BIT_SET(ADCS_PTR->ADC_SEFCLR[AdcModule].reg, (1U << (uint32_t)AdcQueue));
}

/**
 * @brief Adcs模块获取平均结果
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @return KF_INLINE
 */
KF_INLINE uint16_t Adcs_LL_GetAverageResult(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    return (uint16_t)(ADCS_PTR->ADC_AVERSULT[AdcModule][AdcResultReg].bits.RESULT);
}

/**
 * @brief Adcs模块获取结果有效状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcResultReg
 *        ADCS_RESULT_REG_0
 *        ADCS_RESULT_REG_1
 *        ADCS_RESULT_REG_2
 *        ADCS_RESULT_REG_3
 *        ADCS_RESULT_REG_4
 *        ADCS_RESULT_REG_5
 *        ADCS_RESULT_REG_6
 *        ADCS_RESULT_REG_7
 *        ADCS_RESULT_REG_8
 *        ADCS_RESULT_REG_9
 *        ADCS_RESULT_REG_10
 *        ADCS_RESULT_REG_11
 *        ADCS_RESULT_REG_12
 *        ADCS_RESULT_REG_13
 *        ADCS_RESULT_REG_14
 *        ADCS_RESULT_REG_15
 * @return KF_INLINE
 */
KF_INLINE bool Adcs_LL_IsAverageResultValid(const Adcs_Module_t AdcModule, const Adcs_Result_Reg_t AdcResultReg)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_RESULT_REG(AdcResultReg));
    return (bool)(ADCS_PTR->ADC_AVERSULT[AdcModule][AdcResultReg].bits.VF);
}

/**
 * @brief Adcs模块获取全局平均结果
 *

 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @return KF_INLINE
 */
KF_INLINE uint16_t Adcs_LL_GetGlobalAverageResult(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (uint16_t)(ADCS_PTR->ADC_GAVERSULT[AdcModule].bits.RESULT);
}

/**
 * @brief Adcs模块获取全局结果有效状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @return KF_INLINE
 */
KF_INLINE bool Adcs_LL_IsGlobalAverageResultValid(const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    return (bool)(ADCS_PTR->ADC_GAVERSULT[AdcModule].bits.VF);
}

/**
 * @brief Adcs模块设置通道模拟输入缓冲预充电
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Cycle
 *        ADCS__PRECHARGE_OFF 不进行预充电配置
 *        ADCS__PRECHARGE_CYCLE_1 预充电 1 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_2 预充电 2 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_3 预充电 3 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_4 预充电 4个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_5 预充电 5 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_6 预充电 6 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_7 预充电 7 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_8 预充电 8 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_9 预充电 9 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_10 预充电 10 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_11 预充电 11 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_12 预充电 12 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_13 预充电 13 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_14 预充电 14 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_15 预充电 15 个模拟时钟周期
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetChannelPrechargeCycle(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const Adcs_ChannelPreChargeCycle_t Cycle)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL_PRECHARGE_CYCLE(AdcModule));
    REG_WRITE(ADCS_PTR->ADC_CHINF[AdcModule][AdcChannel].bits.AIPS, Cycle);
}

/**
 * @brief Adcs模块使能通道伪随机采样
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Enabled
 *        fasle 设置的采样时间
 *        true 伪随机移动采样的末尾
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableChannelPseudoRandomSample(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_WRITE(ADCS_PTR->ADC_CHINF[AdcModule][AdcChannel].bits.SESPS, Enabled);
}

/**
 * @brief Adcs模块返回通道转换超时状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @retval bool
 *        false 通道转换没有超时
 *        true 通道转换超时
 */
KF_INLINE bool Adcs_LL_IsChannelConvertTimeout(const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    return (bool)(ADCS_PTR->ADC_CHINF[AdcModule][AdcChannel].bits.TIMOUT);
}

/**
 * @brief Adcs模块清除通道转换超时状态
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @retval void
 */
KF_INLINE void Adcs_LL_ClearChannelConvertTimeoutStatus(const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_WRITE(ADCS_PTR->ADC_CHINF[AdcModule][AdcChannel].bits.TIMOUT, 1U);
}

/**
 * @brief Adcs模块使能通道转换超时中断
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Status
 *        false 禁止通道转换超时时触发中断
 *        true 使能通道转换超时时触发中断
 * @retval void
 */
KF_INLINE void Adcs_LL_EnableChannelConvertServiceRequest(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const bool Status)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_WRITE(ADCS_PTR->ADC_CHINF[AdcModule][AdcChannel].bits.TIMOUTEN, Status);
}

/**
 * @brief Adcs模块设置通道外部模拟输入缓冲预充电
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Cycle
 *        ADCS__PRECHARGE_OFF 不进行预充电配置
 *        ADCS__PRECHARGE_CYCLE_1 预充电 1 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_2 预充电 2 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_3 预充电 3 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_4 预充电 4个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_5 预充电 5 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_6 预充电 6 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_7 预充电 7 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_8 预充电 8 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_9 预充电 9 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_10 预充电 10 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_11 预充电 11 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_12 预充电 12 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_13 预充电 13 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_14 预充电 14 个模拟时钟周期
 *        ADCS__PRECHARGE_CYCLE_15 预充电 15 个模拟时钟周期
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SetChannelExternPrechargeCycle(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const Adcs_ChannelPreChargeCycle_t Cycle)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL_PRECHARGE_CYCLE(AdcModule));
    REG_WRITE(ADCS_PTR->ADC_CHINF[AdcModule][AdcChannel].bits.AIPS, Cycle);
}

/**
 * @brief Adcs模块使能通道外部输入伪随机采样
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Enabled
 *        fasle 设置的采样时间
 *        true 伪随机移动采样的末尾
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableChannelExternPseudoRandomSample(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_WRITE(ADCS_PTR->ADC_CHINF[AdcModule][AdcChannel].bits.SESPE, Enabled);
}

/**
 * @brief Adcs模块使能通道事件中断
 *
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @param AdcChannel 通道号
 *        ADCS_CHANNEL_0
 *        ADCS_CHANNEL_1
 *        ADCS_CHANNEL_2
 *        ADCS_CHANNEL_3
 *        ADCS_CHANNEL_4
 *        ADCS_CHANNEL_5
 *        ADCS_CHANNEL_6
 *        ADCS_CHANNEL_7
 *        ADCS_CHANNEL_8
 *        ADCS_CHANNEL_9
 *        ADCS_CHANNEL_10
 *        ADCS_CHANNEL_11
 *        ADCS_CHANNEL_12
 *        ADCS_CHANNEL_13
 *        ADCS_CHANNEL_14
 *        ADCS_CHANNEL_15
 * @param Enabled
 *        fasle 通道事件无法触发中断线
 *        true 通道事件可以触发中断线
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_EnableChannelEventServiceRequest(
  const Adcs_Module_t AdcModule, const Adcs_Channel_t AdcChannel, const bool Enabled)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_CHANNEL(AdcChannel));
    REG_WRITE(ADCS_PTR->ADC_CHINF[AdcModule][AdcChannel].bits.CHEVENT_EN, Enabled);
}

/**
 * @brief Adcs选择外扩通道接口
 *
 * @param AdcEmux
 * EMUX0 外扩通道控制接口 VADCEMUX0 控制选择来源
 * EMUX1 外扩通道控制接口 VADCEMUX1 控制选择来源
 * @param AdcModule
 *        ADC0 ADC模块0
 *        ADC1 ADC模块1
 *        ADC2 ADC模块2
 *        ADC3 ADC模块3
 * @return KF_INLINE
 */
KF_INLINE void Adcs_LL_SelectEmuxModule(const Adcs_ExternMux_t AdcEmux, const Adcs_Module_t AdcModule)
{
    KF_DRV_ADCS_ASSERT(CHECK_ADC_MODULE(AdcModule));
    KF_DRV_ADCS_ASSERT(CHECK_ADC_EXTERN_MUX(AdcEmux));
    REG_BITS_WRITE(ADCS_PTR->ADC_EMUXITFCSEL.reg, (0xFU << ((uint32_t)AdcEmux << 4U)),
                   ((1U << (uint32_t)AdcModule) << ((uint32_t)AdcEmux << 4U)));
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
