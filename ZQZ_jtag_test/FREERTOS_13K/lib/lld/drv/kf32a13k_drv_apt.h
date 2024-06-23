/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_apt.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-24
 *  @Version         : V0.0.1.231224_alpha
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
 *  |2023-12-24                                       |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/

#ifndef KF32DA13K_DRV_APT_H_
#define KF32DA13K_DRV_APT_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a13k_reg_apt.h"

#ifdef KF_DRV_APT_ASSERT
#include "dev_assert.h"
#define KF_DRV_APT_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_APT_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/

typedef enum
{
    APT_SUSPEND_MODE_NONE = 0,
    APT_SUSPEND_MODE_STOP = 2,
} Apt_SuspendMode_t;
#define CHECK_APT_SUSPEND_MODE(MODE) ((MODE == APT_SUSPEND_MODE_NONE) || (MODE == APT_SUSPEND_MODE_STOP))

typedef enum
{
    APT_MASTER_TAG_ID0,
    APT_MASTER_TAG_ID1,
    APT_MASTER_TAG_ID2,
    APT_MASTER_TAG_ID3,
    APT_MASTER_TAG_ID4,
    APT_MASTER_TAG_ID5,
    APT_MASTER_TAG_ID6,
    APT_MASTER_TAG_ID7,
    APT_MASTER_TAG_ID8,
    APT_MASTER_TAG_ID9,
    APT_MASTER_TAG_ID10,
    APT_MASTER_TAG_ID11,
    APT_MASTER_TAG_ID12,
    APT_MASTER_TAG_ID13,
    APT_MASTER_TAG_ID14,
    APT_MASTER_TAG_ID15,
    APT_MASTER_TAG_ID16,
    APT_MASTER_TAG_ID17,
    APT_MASTER_TAG_ID18,
    APT_MASTER_TAG_ID19,
    APT_MASTER_TAG_ID20,
    APT_MASTER_TAG_ID21,
    APT_MASTER_TAG_ID22,
    APT_MASTER_TAG_ID23,
    APT_MASTER_TAG_ID24,
    APT_MASTER_TAG_ID25,
    APT_MASTER_TAG_ID26,
    APT_MASTER_TAG_ID27,
    APT_MASTER_TAG_ID28,
    APT_MASTER_TAG_ID29,
    APT_MASTER_TAG_ID30,
    APT_MASTER_TAG_ID31,
    APT_MASTER_TAG_ID32,
    APT_MASTER_TAG_ID33,
    APT_MASTER_TAG_ID34,
    APT_MASTER_TAG_ID35,
    APT_MASTER_TAG_ID36,
    APT_MASTER_TAG_ID37,
    APT_MASTER_TAG_ID38,
    APT_MASTER_TAG_ID39,
    APT_MASTER_TAG_ID40,
    APT_MASTER_TAG_ID41,
    APT_MASTER_TAG_ID42,
    APT_MASTER_TAG_ID43,
    APT_MASTER_TAG_ID44,
    APT_MASTER_TAG_ID45,
    APT_MASTER_TAG_ID46,
    APT_MASTER_TAG_ID47,
    APT_MASTER_TAG_ID48,
    APT_MASTER_TAG_ID49,
    APT_MASTER_TAG_ID50,
    APT_MASTER_TAG_ID51,
    APT_MASTER_TAG_ID52,
    APT_MASTER_TAG_ID53,
    APT_MASTER_TAG_ID54,
    APT_MASTER_TAG_ID55,
    APT_MASTER_TAG_ID56,
    APT_MASTER_TAG_ID57,
    APT_MASTER_TAG_ID58,
    APT_MASTER_TAG_ID59,
    APT_MASTER_TAG_ID60,
    APT_MASTER_TAG_ID61,
    APT_MASTER_TAG_ID62,
    APT_MASTER_TAG_ID63,
} Apt_MasterTAGId_t;
#define CHECK_APT_MASTER_TAG_ID(ID) (!(ID >> 6))

/**定时器计数方式*/
typedef enum
{
    APT_COUNTING_MANNER_UP_UP_FLAG,
    APT_COUNTING_MANNER_DOWN_DOWN_FLAG,
    APT_COUNTING_MANNER_UP_DOWN_UP_FLAG,
    APT_COUNTING_MANNER_UP_DOWN_DOWN_FLAG,
    APT_COUNTING_MANNER_UP_DOWN_BOTH_FLAG,
} Apt_CountingManner_t;
#define CHECK_APT_COUNTING_MANNER(MANNER) ((uint32_t)MANNER <= APT_COUNTING_UP_DOWN_BOTH_FLAG)

typedef enum
{
    APT_COUNTING_SOURCE_NO_SOURCE,
    APT_COUNTING_SOURCE_EXTCLK1,
    APT_COUNTING_SOURCE_EXTCLK2,
    APT_COUNTING_SOURCE_EXTCLK3,
    APT_COUNTING_SOURCE_EXTCLK4,
    APT_COUNTING_SOURCE_TRGI,
} Apt_CountingSource_t;
#define CHECK_APT_COUNTING_SOURCE(SOURCE) ((uint32_t)SOURCE <= APT_COUNTING_SOURCE_TRGI)

typedef enum
{
    APT_SLAVE_MODE_DISABLED,
    APT_SLAVE_MODE_TRIGGER_MODE,
    APT_SLAVE_MODE_GATING_MODE,
    APT_SLAVE_MODE_RESET_MODE,
} Apt_SlaveMode_t;
#define CHECK_APT_SLAVE_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    APT_TRIGGER_INPUT_SOURCE_TRGI0,
    APT_TRIGGER_INPUT_SOURCE_TRGI1,
    APT_TRIGGER_INPUT_SOURCE_TRGI2,
    APT_TRIGGER_INPUT_SOURCE_TRGI3,
    APT_TRIGGER_INPUT_SOURCE_TRGI4,
    APT_TRIGGER_INPUT_SOURCE_TRGI5,
    APT_TRIGGER_INPUT_SOURCE_TRGI6,
    APT_TRIGGER_INPUT_SOURCE_TRGI7,
    APT_TRIGGER_INPUT_SOURCE_TRGI8,
    APT_TRIGGER_INPUT_SOURCE_TRGI9,
    APT_TRIGGER_INPUT_SOURCE_TRGI10,
    APT_TRIGGER_INPUT_SOURCE_TRGI11,
    APT_TRIGGER_INPUT_SOURCE_TRGI12,
    APT_TRIGGER_INPUT_SOURCE_TRGI13,
    APT_TRIGGER_INPUT_SOURCE_TRGI14,
    APT_TRIGGER_INPUT_SOURCE_TRGI15,
    APT_TRIGGER_INPUT_SOURCE_TRGI16,
    APT_TRIGGER_INPUT_SOURCE_TRGI17,
    APT_TRIGGER_INPUT_SOURCE_TRGI18,
    APT_TRIGGER_INPUT_SOURCE_TRGI19,
    APT_TRIGGER_INPUT_SOURCE_TRGI20,
    APT_TRIGGER_INPUT_SOURCE_TRGI21,
    APT_TRIGGER_INPUT_SOURCE_TRGI22,
    APT_TRIGGER_INPUT_SOURCE_TRGI23,
    APT_TRIGGER_INPUT_SOURCE_TRGI24,
    APT_TRIGGER_INPUT_SOURCE_TRGI25,
    APT_TRIGGER_INPUT_SOURCE_TRGI26,
    APT_TRIGGER_INPUT_SOURCE_TRGI27,
    APT_TRIGGER_INPUT_SOURCE_TRGI28,
    APT_TRIGGER_INPUT_SOURCE_TRGI29,
    APT_TRIGGER_INPUT_SOURCE_TRGI30,
    APT_TRIGGER_INPUT_SOURCE_TRGI31,
} Apt_TriggerInputSource_t;
#define CHECK_APT_TRIGGER_INPUT_SOURCE(SOURCE) (!(SOURCE >> 5))

typedef enum
{
    APT_TRIGGER_OUTPUT_SOURCE_DISABLED,
    APT_TRIGGER_OUTPUT_SOURCE_EN,
    APT_TRIGGER_OUTPUT_SOURCE_OVERFLOW,
    APT_TRIGGER_OUTPUT_SOURCE_UPDATE,
    APT_TRIGGER_OUTPUT_SOURCE_TRIGGER,
    APT_TRIGGER_OUTPUT_SOURCE_CC1IF,
} Apt_TriggerOutputSource_t;
#define CHECK_APT_TRIGGER_OUTPUT_SOURCE(SOURCE) ((uint32_t)SOURCE <= APT_TRIGGER_OUTPUT_SOURCE_CC1IF)

typedef enum
{
    APT_OVERFLOW_TRIGGER_AD_DISABLED,
    APT_OVERFLOW_TRIGGER_AD_UPPER,
    APT_OVERFLOW_TRIGGER_AD_LOWER,
    APT_OVERFLOW_TRIGGER_AD_BOTH,
} Apt_OverflowTriggerADMode_t;
#define CHECK_APT_OVERFLOW_TRIGGER_AD_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    APT_COMPARATOR_RESET_TIMER_IN_RISE_EDGE,
    APT_COMPARATOR_RESET_TIMER_IN_FALL_EDGE,
} Apt_ComparatorRstTimerMode_t;
#define CHECK_APT_COMPARATOR_RESET_TIMER_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    APT_COMPARATOR_MODULE_0,
    APT_COMPARATOR_MODULE_1,
    APT_COMPARATOR_MODULE_2,
    APT_COMPARATOR_MODULE_3,
} Apt_ComparatorModule_t;
#define CHECK_APT_COMPARATOR_MODULE(MODULE) (!(MODULE >> 2))

typedef enum
{
    APT_EXTERN_CLOCK_INPUT_DIVIDE_1,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_2,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_3,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_4,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_5,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_6,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_7,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_8,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_9,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_10,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_11,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_12,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_13,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_14,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_15,
    APT_EXTERN_CLOCK_INPUT_DIVIDE_16,
} Apt_ExternClockInputFilterDivide_t;
#define CHECK_APT_EXTERN_CLOCK_INPUT_DIVIDE(DIVIDE) (!(DIVIDE >> 4))

typedef enum
{
    APT_EXTERN_CLOCK_INPUT_DELAY_0_FILTER_CLOCK,
    APT_EXTERN_CLOCK_INPUT_DELAY_1_FILTER_CLOCK,
    APT_EXTERN_CLOCK_INPUT_DELAY_2_FILTER_CLOCK,
    APT_EXTERN_CLOCK_INPUT_DELAY_3_FILTER_CLOCK,
    APT_EXTERN_CLOCK_INPUT_DELAY_4_FILTER_CLOCK,
    APT_EXTERN_CLOCK_INPUT_DELAY_5_FILTER_CLOCK,
    APT_EXTERN_CLOCK_INPUT_DELAY_6_FILTER_CLOCK,
    APT_EXTERN_CLOCK_INPUT_DELAY_7_FILTER_CLOCK,
} Apt_ExternClockInputFilterDelay_t;
#define CHECK_APT_EXTERN_CLOCK_INPUT_DELAY(DELAY) (!(DELAY >> 3))

typedef enum
{
    APT_PHASE_RELOAD_MODE_CONTINUE,
    APT_PHASE_RELOAD_MODE_SINGLE,
} Apt_PhaseReloadMode_t;
#define CHECK_APT_PHASE_RELOAD_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    APT_PHASE_RELOAD_TIMING_CNT_EQUAL_0,
    APT_PHASE_RELOAD_TIMING_CNT_EQUAL_PPX,
    APT_PHASE_RELOAD_TIMING_TRGI,
    APT_PHASE_RELOAD_TIMING_SOFTWARE,
} Apt_PhaseReloadTiming_t;
#define CHECK_APT_PHASE_RELOAD_TIMING(TIMING) (!(TIMING >> 2))

typedef enum
{
    APT_PHASE_RELOAD_PRESCALE_1,
    APT_PHASE_RELOAD_PRESCALE_2,
    APT_PHASE_RELOAD_PRESCALE_3,
    APT_PHASE_RELOAD_PRESCALE_4,
    APT_PHASE_RELOAD_PRESCALE_5,
    APT_PHASE_RELOAD_PRESCALE_6,
    APT_PHASE_RELOAD_PRESCALE_7,
    APT_PHASE_RELOAD_PRESCALE_8,
    APT_PHASE_RELOAD_PRESCALE_9,
    APT_PHASE_RELOAD_PRESCALE_10,
    APT_PHASE_RELOAD_PRESCALE_11,
    APT_PHASE_RELOAD_PRESCALE_12,
    APT_PHASE_RELOAD_PRESCALE_13,
    APT_PHASE_RELOAD_PRESCALE_14,
    APT_PHASE_RELOAD_PRESCALE_15,
    APT_PHASE_RELOAD_PRESCALE_16,
} Apt_PhaseReloadPrescale_t;
#define CHECK_APT_PHASE_RELOAD_PRESCALE(PRESCALE) (!(PRESCALE >> 4))

typedef enum
{
    APT_PHASE_RELOAD_0_TIMES,
    APT_PHASE_RELOAD_1_TIMES,
    APT_PHASE_RELOAD_2_TIMES,
    APT_PHASE_RELOAD_3_TIMES,
    APT_PHASE_RELOAD_4_TIMES,
    APT_PHASE_RELOAD_5_TIMES,
    APT_PHASE_RELOAD_6_TIMES,
    APT_PHASE_RELOAD_7_TIMES,
    APT_PHASE_RELOAD_8_TIMES,
    APT_PHASE_RELOAD_9_TIMES,
    APT_PHASE_RELOAD_10_TIMES,
    APT_PHASE_RELOAD_11_TIMES,
    APT_PHASE_RELOAD_12_TIMES,
    APT_PHASE_RELOAD_13_TIMES,
    APT_PHASE_RELOAD_14_TIMES,
    APT_PHASE_RELOAD_15_TIMES,
} Apt_PhaseReloadNumOfTimes_t;
#define CHECK_APT_PHASE_RELOAD_NUM_OF_TIMES(TIMES) (!(TIMES >> 4))

typedef enum
{
    APT_PHASE_RELOAD_COUNT_UP,
    APT_PHASE_RELOAD_COUNT_DOWN,
} Apt_PhaseReloadDirection_t;
#define CHECK_APT_PHASE_RELOAD_DIRECTION(DIRECTION) (!(DIRECTION >> 1))

typedef enum
{
    APT_PRESCALE2_DIVIDER_1,
    APT_PRESCALE2_DIVIDER_2,
    APT_PRESCALE2_DIVIDER_3,
    APT_PRESCALE2_DIVIDER_4,
    APT_PRESCALE2_DIVIDER_5,
    APT_PRESCALE2_DIVIDER_6,
    APT_PRESCALE2_DIVIDER_7,
    APT_PRESCALE2_DIVIDER_8,
    APT_PRESCALE2_DIVIDER_9,
    APT_PRESCALE2_DIVIDER_10,
    APT_PRESCALE2_DIVIDER_11,
    APT_PRESCALE2_DIVIDER_12,
    APT_PRESCALE2_DIVIDER_13,
    APT_PRESCALE2_DIVIDER_14,
    APT_PRESCALE2_DIVIDER_15,
    APT_PRESCALE2_DIVIDER_16,
} Apt_Prescale2_t;
#define CHECK_APT_PRESCALE2_DIVIDER(DIVIDER) (!(DIVIDER >> 4))

typedef enum
{
    APT_TIMER_UPDATE_PERIODIC,
    APT_TIMER_UPDATE_NOW,
} Apt_TimerUpdateMode_t;
#define CHECK_APT_TIMER_UPDATE_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    APT_TRGI_UPDATE_NOW,
    APT_TRGI_UPDATE_WHEN_PERIOD_MATCH,
} Apt_TrigUpdateMode_t;
#define CHECK_APT_TRGI_UPDATE_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    APT_CHANNEL_1,
    APT_CHANNEL_2,
    APT_CHANNEL_3,
} Apt_Channel_t;
#define CHECK_APT_CHANNEL(CHANNEL) ((uint32_t)CHANNEL <= APT_CHANNEL_3)

typedef enum
{
    APT_CHANNEL_MODE_CLOSE = 0x0U,

    APT_CHANNEL_MODE_CAP_PWM = 0x3U,
    APT_CHANNEL_MODE_CAP     = 0x4U,

    APT_CHANNEL_MODE_CMP_GEN_EVENT      = 0x7U,
    APT_CHANNEL_MODE_CMP_HIGHT_LEVEL    = 0x8U,
    APT_CHANNEL_MODE_CMP_LOW_LEVEL      = 0x9U,
    APT_CHANNEL_MODE_CMP_DISABLE_OUTPUT = 0xAU,
    APT_CHANNEL_MODE_CMP_DISABLE_TOGGLE = 0xBU,

    APT_CHANNEL_MODE_PWM_FREEDOM = 0xCU,
} Apt_ChannelMode_t;
#define CHECK_APT_CHANNEL_MODE(MODE)                                                                                   \
    ((MODE == APT_CHANNEL_MODE_CLOSE) || (MODE == APT_CHANNEL_MODE_CAP_PWM) || (MODE == APT_CHANNEL_MODE_CAP) ||       \
     (MODE == APT_CHANNEL_MODE_CMP_GEN_EVENT) || (MODE == APT_CHANNEL_MODE_CMP_HIGHT_LEVEL) ||                         \
     (MODE == APT_CHANNEL_MODE_CMP_LOW_LEVEL) || (MODE == APT_CHANNEL_MODE_CMP_DISABLE_OUTPUT) ||                      \
     (MODE == APT_CHANNEL_MODE_CMP_DISABLE_TOGGLE) || (MODE == APT_CHANNEL_MODE_PWM_FREEDOM))

typedef enum

{
    APT_SINGLE_PULSE_MODE_CONTINUE,
    APT_SINGLE_PULSE_MODE_ONE_SHOT,
} Apt_SinglePulseMode_t;
#define CHECK_APT_SINGLE_PULSE_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    APT_OUTPUT_CTRL_PWM_ACTIVE_HIGH,
    APT_OUTPUT_CTRL_PWM_ACTIVE_LOW,
    APT_OUTPUT_CTRL_PWM_FORCE_HIGH,
    APT_OUTPUT_CTRL_PWM_FORCE_LOW,
} Apt_OutputCtrl_t;
#define CHECK_APT_OUTPUT_CTRL(OUTPUT) (!(OUTPUT >> 2))

typedef enum
{
    APT_SHUTDOWN_SOURCE_DISABLED,
    APT_SHUTDOWN_SOURCE_BKIN_LOW,
    APT_SHUTDOWN_SOURCE_CMP0_HIGH,
    APT_SHUTDOWN_SOURCE_CMP1_HIGH,
    APT_SHUTDOWN_SOURCE_CMP2_HIGH,
    APT_SHUTDOWN_SOURCE_CMP3_HIGH,
    APT_SHUTDOWN_SOURCE_ERU,
} Apt_ShutDownSource_t;
#define CHECK_APT_SHUTDOWN_SOURCE(SOURCE) ((uint32_t)SOURCE <= APT_SHUTDOWN_SOURCE_ERU)

typedef enum
{
    APT_SHUTDOWN_OUTPUT_LEVEL_LOW,
    APT_SHUTDOWN_OUTPUT_LEVEL_HIGH,
    APT_SHUTDOWN_OUTPUT_LEVEL_Z,
    APT_SHUTDOWN_OUTPUT_LEVEL_Z_1,
} Apt_ShutdownOutputLevel_t;
#define CHECK_APT_SHUTDOWN_OUTPUT_LEVEL(LEVEL) (!(LEVEL >> 2))

typedef enum
{
    APT_ZERO_POINT_DETECT_CLOCK_FPRS,
    APT_ZERO_POINT_DETECT_CLOCK_FPRS_2,
    APT_ZERO_POINT_DETECT_CLOCK_FPRS_4,
    APT_ZERO_POINT_DETECT_CLOCK_FPRS_8,
    APT_ZERO_POINT_DETECT_CLOCK_FPRS_16,
    APT_ZERO_POINT_DETECT_CLOCK_FPRS_32,
    APT_ZERO_POINT_DETECT_CLOCK_FPRS_64,
    APT_ZERO_POINT_DETECT_CLOCK_FPRS_128,
    APT_ZERO_POINT_DETECT_CLOCK_FPRS_256,
    APT_ZERO_POINT_DETECT_CLOCK_FPRS_512,
} Apt_ZeroPointDetectClock_t;
#define CHECK_APT_ZERO_POINT_DETECT_CLOCK(CLOCK) ((uint32_t)CLOCK <= APT_ZERO_POINT_DETECT_CLOCK_FPRS_512)

typedef enum
{
    APT_ZERO_POINT_DETECT_VOLTAGE_15,
    APT_ZERO_POINT_DETECT_VOLTAGE_25,
    APT_ZERO_POINT_DETECT_VOLTAGE_35,
    APT_ZERO_POINT_DETECT_VOLTAGE_45,
    APT_ZERO_POINT_DETECT_VOLTAGE_55,
} Apt_ZeroPointDetectVoltage_t;
#define CHECK_APT_ZERO_POINT_DETECT_VOLTAGE(VOLTAGE) ((uint32_t)VOLTAGE <= APT_ZERO_POINT_DETECT_VOLTAGE_55)

typedef enum
{
    APT_ZERO_POINT_DETECT_PIN_NO_EFFECT,
    APT_ZERO_POINT_DETECT_PIN_HI_Z,
} Apt_ZeroPointDetectPinCtrl_t;
#define CHECK_APT_ZERO_POINT_DETECT(PINCTRL) (!(PINCTRL >> 1))

typedef enum
{
    APT_HALL_TEMPLATE_0,
    APT_HALL_TEMPLATE_1,
    APT_HALL_TEMPLATE_2,
    APT_HALL_TEMPLATE_3,
    APT_HALL_TEMPLATE_4,
    APT_HALL_TEMPLATE_5,
    APT_HALL_TEMPLATE_6,
    APT_HALL_TEMPLATE_7,
} Apt_HallTemplate_t;
#define CHECK_APT_HALL_TEMPLATE(TEMPLATE) (!(TEMPLATE >> 3))

typedef enum
{
    APT_DITHER_COUNTER_VALUE_0,
    APT_DITHER_COUNTER_VALUE_1,
    APT_DITHER_COUNTER_VALUE_2,
    APT_DITHER_COUNTER_VALUE_3,
    APT_DITHER_COUNTER_VALUE_4,
    APT_DITHER_COUNTER_VALUE_5,
    APT_DITHER_COUNTER_VALUE_6,
    APT_DITHER_COUNTER_VALUE_7,
    APT_DITHER_COUNTER_VALUE_8,
    APT_DITHER_COUNTER_VALUE_9,
    APT_DITHER_COUNTER_VALUE_10,
    APT_DITHER_COUNTER_VALUE_11,
    APT_DITHER_COUNTER_VALUE_12,
    APT_DITHER_COUNTER_VALUE_13,
    APT_DITHER_COUNTER_VALUE_14,
    APT_DITHER_COUNTER_VALUE_15,
    APT_DITHER_COUNTER_VALUE_16,
    APT_DITHER_COUNTER_VALUE_17,
    APT_DITHER_COUNTER_VALUE_18,
    APT_DITHER_COUNTER_VALUE_19,
    APT_DITHER_COUNTER_VALUE_20,
    APT_DITHER_COUNTER_VALUE_21,
    APT_DITHER_COUNTER_VALUE_22,
    APT_DITHER_COUNTER_VALUE_23,
    APT_DITHER_COUNTER_VALUE_24,
    APT_DITHER_COUNTER_VALUE_25,
    APT_DITHER_COUNTER_VALUE_26,
    APT_DITHER_COUNTER_VALUE_27,
    APT_DITHER_COUNTER_VALUE_28,
    APT_DITHER_COUNTER_VALUE_29,
    APT_DITHER_COUNTER_VALUE_30,
    APT_DITHER_COUNTER_VALUE_31,
} Apt_DitherCounterIncVal_t;
#define CHECK_APT_DITHER_COUNTER_INC_VALUE(VALUE) (!(VALUE >> 5))

typedef enum
{
    APT_CCR_TRIG_AD_DIRECTION_UP,
    APT_CCR_TRIG_AD_DIRECTION_DOWN,
} Apt_CcrTrigAdDirection_t;
#define CHECK_APT_TRIG_AD_DIRECTION(DIR) (!(DIR >> 1))

typedef enum
{
    APT_COUNTING_DIRECTION_UP,
    APT_COUNTING_DIRECTION_DOWN,
} Apt_CountingDirection_t;
#define CHECK_APT_COUNTING_DIRECTION(DIR) (!(DIR >> 1))

typedef enum
{
    APT_CAPTURE_MODE_CONTINUE,
    APT_CAPTURE_MODE_ONE_SHOT,
} Apt_ChannelCaptureMode_t;
#define CHECK_APT_CHANNEL_CAPTURE_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    APT_CAPTURE_EDGE_RISE,
    APT_CAPTURE_EDGE_FALL,
} Apt_ChannelCaptureEdge_t;
#define CHECK_APT_CHANNEL_CAPTURE_EDGE(EDGE) (!(EDGE >> 1))

typedef enum
{
    APT_CAPTURE_CH1H,
    APT_CAPTURE_CH2H,
    APT_CAPTURE_CH3H,
    APT_CAPTURE_CMP1,
    APT_CAPTURE_CMP2,
    APT_CAPTURE_CMP3,
    APT_CAPTURE_CMP4,
} Apt_ChannelCapturePin_t;
#define CHECK_APT_CHANNEL_CAPTURE_PIN(PIN) (!(PIN >> 3))

typedef enum
{
    APT_CAPTURE_PRESCALE_1,
    APT_CAPTURE_PRESCALE_2,
    APT_CAPTURE_PRESCALE_3,
    APT_CAPTURE_PRESCALE_4,
    APT_CAPTURE_PRESCALE_5,
    APT_CAPTURE_PRESCALE_6,
    APT_CAPTURE_PRESCALE_7,
    APT_CAPTURE_PRESCALE_8,
} Apt_ChannelCapturePrescale_t;
#define CHECK_APT_CHANNEL_CAPTURE_PRESCALE(PRESCALE) (!(PRESCALE >> 3))

typedef enum
{
    APT_CAPTURE_TIMES_0,
    APT_CAPTURE_TIMES_1,
    APT_CAPTURE_TIMES_2,
    APT_CAPTURE_TIMES_3,
    APT_CAPTURE_TIMES_4,
    APT_CAPTURE_TIMES_5,
    APT_CAPTURE_TIMES_6,
    APT_CAPTURE_TIMES_7,
    APT_CAPTURE_TIMES_8,
    APT_CAPTURE_TIMES_9,
    APT_CAPTURE_TIMES_10,
    APT_CAPTURE_TIMES_11,
    APT_CAPTURE_TIMES_12,
    APT_CAPTURE_TIMES_13,
    APT_CAPTURE_TIMES_14,
    APT_CAPTURE_TIMES_15,
} Apt_ChannelCaptureTimes_t;
#define CHECK_APT_CHANNEL_CAPTURE_TIMES(TIMES) (!(TIMES >> 4))

typedef enum
{
    APT_CAPTURE_FILTER_PRESCALE_1,
    APT_CAPTURE_FILTER_PRESCALE_2,
    APT_CAPTURE_FILTER_PRESCALE_3,
    APT_CAPTURE_FILTER_PRESCALE_4,
    APT_CAPTURE_FILTER_PRESCALE_5,
    APT_CAPTURE_FILTER_PRESCALE_6,
    APT_CAPTURE_FILTER_PRESCALE_7,
    APT_CAPTURE_FILTER_PRESCALE_8,
    APT_CAPTURE_FILTER_PRESCALE_9,
    APT_CAPTURE_FILTER_PRESCALE_10,
    APT_CAPTURE_FILTER_PRESCALE_11,
    APT_CAPTURE_FILTER_PRESCALE_12,
    APT_CAPTURE_FILTER_PRESCALE_13,
    APT_CAPTURE_FILTER_PRESCALE_14,
    APT_CAPTURE_FILTER_PRESCALE_15,
    APT_CAPTURE_FILTER_PRESCALE_16,
} Apt_ChannelCaptureFilterPrescale_t;
#define CHECK_APT_CHANNEL_CAPTURE_FILTER_PRESCALE(PRESCALE) (!(PRESCALE >> 4))

typedef enum
{
    APT_CAPTURE_FILTER_TIMES_1,
    APT_CAPTURE_FILTER_TIMES_2,
    APT_CAPTURE_FILTER_TIMES_3,
    APT_CAPTURE_FILTER_TIMES_4,
    APT_CAPTURE_FILTER_TIMES_5,
    APT_CAPTURE_FILTER_TIMES_6,
    APT_CAPTURE_FILTER_TIMES_7,
    APT_CAPTURE_FILTER_TIMES_8,
} Apt_ChannelCaptureFilterTimes_t;
#define CHECK_APT_CHANNEL_CAPTURE_FILTER_TIMES(TIMES) (!(TIMES >> 3))

typedef enum
{
    APT_INTERRUPT_FLAG_OVERFLOW       = 0,
    APT_INTERRUPT_FLAG_CHANNEL1_EVENT = 2,
    APT_INTERRUPT_FLAG_CHANNEL2_EVENT = 3,
    APT_INTERRUPT_FLAG_CHANNEL3_EVENT = 4,
    APT_INTERRUPT_FLAG_TRIGGER_EVENT  = 6,
    APT_INTERRUPT_FLAG_UPDATE_EVENT   = 8,
    APT_INTERRUPT_FLAG_HALL_ERROR     = 10,
    APT_INTERRUPT_FLAG_HALL_MODIFY    = 11,
} Apt_InterruptGetIndex_t;
#define CHECK_APT_INTERRUPT_FLAG_INDEX(INDEX)                                                                          \
    ((INDEX == APT_INTERRUPT_FLAG_OVERFLOW) || (INDEX == APT_INTERRUPT_FLAG_TRIGGER_EVENT) ||                          \
     (INDEX == APT_INTERRUPT_FLAG_CHANNEL1_EVENT) || (INDEX == APT_INTERRUPT_FLAG_CHANNEL2_EVENT) ||                   \
     (INDEX == APT_INTERRUPT_FLAG_CHANNEL3_EVENT) || (INDEX == APT_INTERRUPT_FLAG_UPDATE_EVENT) ||                     \
     (INDEX == APT_INTERRUPT_FLAG_HALL_ERROR) || (INDEX == APT_INTERRUPT_FLAG_HALL_MODIFY))

typedef enum
{
    APT_INTERRUPT_LINE_0,
    APT_INTERRUPT_LINE_1,
    APT_INTERRUPT_LINE_2,
    APT_INTERRUPT_LINE_3,
} Apt_ServiceInterruptLine_t;
#define CHECK_APT_INTERRUPT_LINE(LINE) (!(LINE >> 2))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief Apt模块使能/禁止
 * @param Module 指向APT内存结构的指针
 * @param Status 使能/禁止状态
 *        false   Apt 使能
 *        true   Apt 禁止
 * @retval void
 */
KF_INLINE void Apt_LL_SetModuleDisabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_CLKC.bits.DISR, Status);
}

/**
 * @brief Apt获取模块禁止状态
 * @param Module 指向APT内存结构的指针
 *
 * @retval bool
 *        false Apt模块已使能
 *        true Apt模块已禁止
 */
KF_INLINE bool Apt_LL_GetModuleStatus(const Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    return (REG_READ(Module->APT_CLKC.bits.DISS));
}

/**
 * @brief Apt设置休眠模式
 * @param Module 指向APT内存结构的指针
 * @param Status:
 *        false   Apt 关闭休眠模式
 *        true   Apt 进入休眠模式
 * @retval void
 */
KF_INLINE void Apt_LL_SetSleepModeEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_CLKC.bits.EDIS, Status);
}

/*  APT_INFO_T */

/**
 * @brief Apt获取模块版本号
 * @param Module 指向APT内存结构的指针
 *
 * @param void
 * @retval uint32_t 模块版本号
 */
KF_INLINE uint32_t Apt_LL_GetModuleVersion(const Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    return (REG_READ(Module->APT_INFO.bits.MODREV));
}

/**
 * @brief Apt获取模块类型
 * @param Module 指向APT内存结构的指针
 *
 * @param void
 * @retval uint32_t 模块类型
 */
KF_INLINE uint32_t Apt_LL_GetModuleType(const Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    return (REG_READ(Module->APT_INFO.bits.MODTYPE));
}

/**
 * @brief Apt获取模块编号
 * @param Module 指向APT内存结构的指针
 *
 * @param void
 * @retval uint32_t 模块编号
 */
KF_INLINE uint32_t Apt_LL_GetModuleNumber(const Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    return (REG_READ(Module->APT_INFO.bits.MODNUM));
}

/*  APT_DBG_T */

/**
 * @brief Apt返回模块挂起状态
 * @param Module 指向APT内存结构的指针
 *
 * @param void
 * @retval bool
 *        false Apt模块未挂起
 *        false Apt模块挂起
 */
KF_INLINE bool Apt_LL_IsModuleSuspended(const Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    return (REG_READ(Module->APT_DBG.bits.SUSSTA));
}

/**
 * @brief Apt模块设置挂起
 * @param Module 指向APT内存结构的指针
 *
 * @param SuspendMode Apt模块挂起模式
 *        APT_SUSPEND_MODE_NONE 不挂起
 *        APT_SUSPEND_MODE_STOP 64位计数器停止
 * @retval void
 */
KF_INLINE void Apt_LL_SetSuspendMode(Apt_RegisterMap_t *const Module, const Apt_SuspendMode_t SuspendMode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_SUSPEND_MODE(SuspendMode));

    APT_DBG_T regValue = {0};

    regValue.reg       = REG_READ(Module->APT_DBG.reg);
    regValue.bits.SUSP = true;
    regValue.bits.SUS  = SuspendMode;

    REG_WRITE(Module->APT_DBG.reg, regValue.reg);
}

/*  APT_RST0_T */
/*  APT_RST1_T */

/**
 * @brief 复位Apt模块
 * @param Module 指向APT内存结构的指针
 *
 * @retval
 */
KF_INLINE void Apt_LL_ResetModule(Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_RST0.bits.RST, 1U);
    REG_WRITE(Module->APT_RST1.bits.RST, 1U);
}

/*  APT_RSTCLR_T */

/**
 * @brief 清除Apt模块复位状态
 * @param Module 指向APT内存结构的指针
 *
 * @retval
 */
KF_INLINE void Apt_LL_ClearResetStatus(Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_RSTCLR.bits.CLR, 1U);
}

/**
 * @brief 获取Apt模块复位状态
 * @param Module 指向APT内存结构的指针
 *
 * @retval bool
 *        false 模块没有复位
 *        true 模块已复位
 */
KF_INLINE bool Apt_LL_GetResetStatus(const Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    return (REG_READ(Module->APT_RST0.bits.RSTSTA));
}

/*  APT_ACES0_T */

/**
 * @brief 设置APT模块Master TAG ID访问权限
 *
 * @param Module 指向APT内存结构的指针
 * @param Id Master TAG ID
 * @param Status bool
 *        false 写访问没有执行
 *        true 写访问执行
 * @return
 */
KF_INLINE void Apt_LL_SetAccessEnabled(Apt_RegisterMap_t *const Module, const Apt_MasterTAGId_t Id, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_MASTER_TAG_ID(Id));
    if (Id < APT_MASTER_TAG_ID32)
    {
        REG_BITS_WRITE(Module->APT_ACES0.reg, (1U << Id), ((uint32_t)Status << Id));
    }
    else
    {
        REG_BITS_WRITE(
          Module->APT_ACES1.reg, (1U << (Id - APT_MASTER_TAG_ID32)), ((uint32_t)Status << (Id - APT_MASTER_TAG_ID32)));
    }
}

/*  APT_T1CTL1_T */

/**
 * @brief APT模块使能 /禁止
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status bool
 *                false 停止 T1，计数器暂停计数
 *                true 启动 T1，计数器开始计数
 * @return
 */
KF_INLINE void Apt_LL_SetTimerEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1CTL1.bits.EN, Status);
}

/**
 * @brief APT模块设置计数方式
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Manner 计数方式选择
 *                APT_COUNTING_MANNER_UP_UP_FLAG 向上计数，上溢产生中断标志
 *                APT_COUNTING_MANNER_DOWN_DOWN_FLAG 向下计数，下溢产生中断标志
 *                APT_COUNTING_MANNER_UP_DOWN_UP_FLAG 向上向下计数，上溢产生中断标志
 *                APT_COUNTING_MANNER_UP_DOWN_DOWN_FLAG 向上向下计数，下溢产生中断标志
 *                APT_COUNTING_MANNER_UP_DOWN_BOTH_FLAG 向上向下计数，上溢和下溢均产生中断标志
 * @retval void
 */
KF_INLINE void Apt_LL_SetCounterManner(Apt_RegisterMap_t *const Module, const Apt_CountingManner_t Manner)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_COUNTING_MANNER(Manner));
    REG_WRITE(Module->APT_T1CTL1.bits.CMS, Manner);
}

/**
 * @brief APT模块设置计数时钟源
 * @details 选择的时钟会与 fAPT同步
 *
 * @param Module 指向APT内存结构的指针
 * @param Source 计数源
 *                APT_COUNTING_SOURCE_NO_SOURCE 不选择计数源，计数器每个时钟都计数
 *                APT_COUNTING_SOURCE_EXTCLK1 计数源为 EXTCLK1，在 EXTCLK1 上升沿计数
 *                APT_COUNTING_SOURCE_EXTCLK2 计数源为 EXTCLK2，在 EXTCLK2 上升沿计数
 *                APT_COUNTING_SOURCE_EXTCLK3 计数源为 EXTCLK3，在 EXTCLK3 上升沿计数
 *                APT_COUNTING_SOURCE_EXTCLK4 计数源为 EXTCLK4，在 EXTCLK4 上升沿计数
 *                APT_COUNTING_SOURCE_TRGI 计数源为 TRGI，上升沿到来时计数值+1
 * @retval void
 */
KF_INLINE void Apt_LL_SetCounterSource(Apt_RegisterMap_t *const Module, const Apt_CountingSource_t Source)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_COUNTING_SOURCE(Module));
    REG_WRITE(Module->APT_T1CTL1.bits.CLKMUX, Source);
}

/**
 * @brief APT模块选择从模式
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Mode 从模式选择
 *                APT_SLAVE_MODE_DISABLED 从模式禁止
 *                APT_SLAVE_MODE_TRIGGER_MODE 触发模式
 *                APT_SLAVE_MODE_GATING_MODE 门控模式
 *                APT_SLAVE_MODE_RESET_MODE 复位模式
 * @return
 */
KF_INLINE void Apt_LL_SelectSlaveMode(Apt_RegisterMap_t *const Module, const Apt_SlaveMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_SLAVE_MODE(Mode));
    REG_WRITE(Module->APT_T1CTL1.bits.SMS, Mode);
}

/**
 * @brief APT模块选择TRGI触发输入
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Source 触发输入源
 *                APT_TRIGGER_INPUT_SOURCE_TRGI0
 *                APT_TRIGGER_INPUT_SOURCE_TRGI1
 *                APT_TRIGGER_INPUT_SOURCE_TRGI2
 *                APT_TRIGGER_INPUT_SOURCE_TRGI3
 *                APT_TRIGGER_INPUT_SOURCE_TRGI4
 *                APT_TRIGGER_INPUT_SOURCE_TRGI5
 *                APT_TRIGGER_INPUT_SOURCE_TRGI6
 *                APT_TRIGGER_INPUT_SOURCE_TRGI7
 *                APT_TRIGGER_INPUT_SOURCE_TRGI8
 *                APT_TRIGGER_INPUT_SOURCE_TRGI9
 *                APT_TRIGGER_INPUT_SOURCE_TRGI10
 *                APT_TRIGGER_INPUT_SOURCE_TRGI11
 *                APT_TRIGGER_INPUT_SOURCE_TRGI12
 *                APT_TRIGGER_INPUT_SOURCE_TRGI13
 *                APT_TRIGGER_INPUT_SOURCE_TRGI14
 *                APT_TRIGGER_INPUT_SOURCE_TRGI15
 *                APT_TRIGGER_INPUT_SOURCE_TRGI16
 *                APT_TRIGGER_INPUT_SOURCE_TRGI17
 *                APT_TRIGGER_INPUT_SOURCE_TRGI18
 *                APT_TRIGGER_INPUT_SOURCE_TRGI19
 *                APT_TRIGGER_INPUT_SOURCE_TRGI20
 *                APT_TRIGGER_INPUT_SOURCE_TRGI21
 *                APT_TRIGGER_INPUT_SOURCE_TRGI22
 *                APT_TRIGGER_INPUT_SOURCE_TRGI23
 *                APT_TRIGGER_INPUT_SOURCE_TRGI24
 *                APT_TRIGGER_INPUT_SOURCE_TRGI25
 *                APT_TRIGGER_INPUT_SOURCE_TRGI26
 *                APT_TRIGGER_INPUT_SOURCE_TRGI27
 *                APT_TRIGGER_INPUT_SOURCE_TRGI28
 *                APT_TRIGGER_INPUT_SOURCE_TRGI29
 *                APT_TRIGGER_INPUT_SOURCE_TRGI30
 *                APT_TRIGGER_INPUT_SOURCE_TRGI31
 * @retval void
 */
KF_INLINE void Apt_LL_SelectTriggerInputSource(Apt_RegisterMap_t *const Module, const Apt_TriggerInputSource_t Source)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_TRIGGER_INPUT_SOURCE(Source));
    REG_WRITE(Module->APT_T1CTL1.bits.TRGIS, Source);
}

/**
 * @brief APT模块选择TRGI触发输出
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Source 触发输出选择
 *                APT_TRIGGER_OUTPUT_SOURCE_DISABLED 禁止 TRGO 输出
 *                APT_TRIGGER_OUTPUT_SOURCE_EN TRGO 输出源选择 EN 信号
 *                APT_TRIGGER_OUTPUT_SOURCE_OVERFLOW TRGO 输出源选择溢出信号
 *                APT_TRIGGER_OUTPUT_SOURCE_UPDATE TRGO 输出源选择更新信号
 *                APT_TRIGGER_OUTPUT_SOURCE_TRIGGER TRGO 输出源选择触发信号
 *                APT_TRIGGER_OUTPUT_SOURCE_CC1IF TRGO 输出源选择 CC1IF 信号
 * @return
 */
KF_INLINE void Apt_LL_SelectTriggerOutputSource(Apt_RegisterMap_t *const Module, const Apt_TriggerOutputSource_t Source)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_TRIGGER_OUTPUT_SOURCE(Source));
    REG_WRITE(Module->APT_T1CTL1.bits.TRGOS, Source);
}

/**
 * @brief APT模块选择T1溢出中断触发AD模式
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Mode 触发模式
 *                APT_OVERFLOW_TRIGGER_AD_DISABLED 禁止上溢和下溢触发 AD
 *                APT_OVERFLOW_TRIGGER_AD_UPPER 使能上溢触发 AD
 *                APT_OVERFLOW_TRIGGER_AD_LOWER 使能下溢触发 AD
 *                APT_OVERFLOW_TRIGGER_AD_BOTH 使能上溢和下溢触发 AD
 * @retval void
 */
KF_INLINE void
Apt_LL_SelectOverflowTriggerADMode(Apt_RegisterMap_t *const Module, const Apt_OverflowTriggerADMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_OVERFLOW_TRIGGER_AD_MODE(Mode));
    REG_WRITE(Module->APT_T1CTL1.bits.OFS, Mode);
}

/*  APT_T1CTL2_T */

/**
 * @brief APT模块使能/禁止比较器清零定时器功能
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 使能/禁止状态
 *                false 禁止比较器清零定时器功能
 *                true 使能比较器清零定时器功能
 * @retval void
 */
KF_INLINE void Apt_LL_SetComparatorRstTimerEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1CTL2.bits.CCTEN, Status);
}

/**
 * @brief APT模块选择比较器清零定时器模式
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Mode 比较器清零定时器模式
 *                APT_COMPARATOR_RESET_TIMER_IN_RISE_EDGE 比较器输出信号检测到上升沿时，清零定时器
 *                APT_COMPARATOR_RESET_TIMER_IN_FALL_EDGE 比较器输出信号检测到下降沿时，清零定时器
 * @retval void
 */
KF_INLINE void
Apt_LL_SelectComparatorRstTimerMode(Apt_RegisterMap_t *const Module, const Apt_ComparatorRstTimerMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_COMPARATOR_RESET_TIMER_MODE(Mode));
    REG_WRITE(Module->APT_T1CTL2.bits.CRSET, Mode);
}

/**
 * @brief APT模块选择用于清零定时器的比价器模块
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Comparator 比较器模块
 *                APT_COMPARATOR_MODULE_0 选择比较器 0，信号T1_ZERO0
 *                APT_COMPARATOR_MODULE_1 选择比较器 1，信号T1_ZERO1
 *                APT_COMPARATOR_MODULE_2 选择比较器 2，信号T1_ZERO2
 *                APT_COMPARATOR_MODULE_3 选择比较器 3，信号T1_ZERO3
 * @retval void
 */
KF_INLINE void
Apt_LL_SelectComparatorForRstTimer(Apt_RegisterMap_t *const Module, const Apt_ComparatorModule_t Comparator)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_COMPARATOR_MODULE(Module));
    REG_WRITE(Module->APT_T1CTL2.bits.CCTSEL, Comparator);
}

/**
 * @brief APT模块使能/禁止外部时钟引脚输入滤波
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 外部时钟输入滤波使能
 *                false 禁止外部时钟引脚输入滤波
 *                true 使能外部时钟引脚输入滤波
 * @retval void
 */
KF_INLINE void Apt_LL_SetExternClockInputFilterEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1CTL2.bits.TCKFEN, Status);
}

/**
 * @brief APT模块设置外部时钟输入滤波时钟分频
 * @note 滤波时钟为计数时钟
 *
 * @param Module 指向APT内存结构的指针
 * @param Divide 外部时钟输入滤波时钟分频\
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_1 1:1分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_2 1:2 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_3 1:3 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_4 1:4 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_5 1:5 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_6 1:6 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_7 1:7 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_8 1:8 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_9 1:9 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_10 1:10 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_11 1:11 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_12 1:12 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_13 1:13 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_14 1:14 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_15 1:15 分频
 *                APT_EXTERN_CLOCK_INPUT_DIVIDE_16 1:16 分频
 * @retval void
 */
KF_INLINE void
Apt_LL_SetExternClockFilterDivide(Apt_RegisterMap_t *const Module, const Apt_ExternClockInputFilterDivide_t Divide)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_EXTERN_CLOCK_INPUT_DIVIDE(Divide));
    REG_WRITE(Module->APT_T1CTL2.bits.TCKDIV, Divide);
}

/**
 * @brief APT模块设置外部时钟输入滤波延时
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Delay
 *                APT_EXTERN_CLOCK_INPUT_DELAY_0_FILTER_CLOCK 不延时
 *                APT_EXTERN_CLOCK_INPUT_DELAY_1_FILTER_CLOCK 延时 1 个滤波时钟
 *                APT_EXTERN_CLOCK_INPUT_DELAY_2_FILTER_CLOCK 延时 2 个滤波时钟
 *                APT_EXTERN_CLOCK_INPUT_DELAY_3_FILTER_CLOCK 延时 3 个滤波时钟
 *                APT_EXTERN_CLOCK_INPUT_DELAY_4_FILTER_CLOCK 延时 4 个滤波时钟
 *                APT_EXTERN_CLOCK_INPUT_DELAY_5_FILTER_CLOCK 延时 5 个滤波时钟
 *                APT_EXTERN_CLOCK_INPUT_DELAY_6_FILTER_CLOCK 延时 6 个滤波时钟
 *                APT_EXTERN_CLOCK_INPUT_DELAY_7_FILTER_CLOCK 延时 7 个滤波时钟
 * @retval void
 */
KF_INLINE void
Apt_LL_SetExternClockFilterDelay(Apt_RegisterMap_t *const Module, const Apt_ExternClockInputFilterDelay_t Delay)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_EXTERN_CLOCK_INPUT_DELAY(Delay));
    REG_WRITE(Module->APT_T1CTL2.bits.TCKDELAY, Delay);
}

/*  APT_T1PHSCTL_T */

/**
 * @brief APT模块使能/禁止相位重载
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 相位重载使能
 * @return
 */
KF_INLINE void Apt_LL_SetPhaseReloadEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1PHSCTL.bits.PHSEN, Status);
}

/**
 * @brief APT模块选择相位重载模式
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Mode 相位重载模式
 *                APT_PHASE_RELOAD_MODE_CONTINUE 连续模式
 *                APT_PHASE_RELOAD_MODE_SINGLE 单次模式
 * @return
 */
KF_INLINE void Apt_LL_SelectPhaseReloadMode(Apt_RegisterMap_t *const Module, const Apt_PhaseReloadMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_PHASE_RELOAD_MODE(Module));
    REG_WRITE(Module->APT_T1PHSCTL.bits.PHSMODE, Mode);
}

/**
 * @brief APT模块设置/禁止软件触发相位重载
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 相位重载软件触发
 *                false 禁止软件触发相位重载
 *                true 软件触发相位重载
 * @return KF_INLINE
 */
KF_INLINE void Apt_LL_SetSoftwareTriggerPhaseReload(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1PHSCTL.bits.PHSW, Status);
}

/**
 * @brief APT模块选择相位重载时机
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Timing 相位重载时机
 *                APT_PHASE_RELOAD_TIMING_CNT_EQUAL_0 当计数值匹配 0 时发生相位重载
 *                APT_PHASE_RELOAD_TIMING_CNT_EQUAL_PPX 当计数值匹配周期值时发生相位重载
 *                APT_PHASE_RELOAD_TIMING_TRGI 选择 TRGI 触发相位重载
 *                APT_PHASE_RELOAD_TIMING_SOFTWARE 选择软件触发相位重载
 * @retval void
 */
KF_INLINE void Apt_LL_SelectPhaseReloadTiming(Apt_RegisterMap_t *const Module, const Apt_PhaseReloadTiming_t Timing)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_PHASE_RELOAD_TIMING(Timing));
    REG_WRITE(Module->APT_T1PHSCTL.bits.PHSSEL, Timing);
}

/**
 * @brief APT模块设置相位重载事件预分频
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Prescale 相位重载事件预分频
 *                APT_PHASE_RELOAD_PRESCALE_1 每有1次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_2 每有2次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_3 每有3次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_4 每有4次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_5 每有5次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_6 每有6次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_7 每有7次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_8 每有8次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_9 每有9次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_10 每有10次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_11 每有11次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_12 每有12次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_13 每有13次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_14 每有14次PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_15 每有15次 PHSSEL选择的事件发生，产生一次有效相位重载事件
 *                APT_PHASE_RELOAD_PRESCALE_16 每有16次PHSSEL选择的事件发生，产生一次有效相位重载事件
 * @return
 */
KF_INLINE void Apt_LL_SetPhaseReloadPrescale(Apt_RegisterMap_t *const Module, const Apt_PhaseReloadPrescale_t Prescale)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_PHASE_RELOAD_PRESCALE(Prescale));
    REG_WRITE(Module->APT_T1PHSCTL.bits.PHSPRSC, Prescale);
}

/**
 * @brief APT模块设置相位重载次数
 * @details 在连续相位重载连续模式下进行Times次相位重载操作后就停止重载, 当 PHSTIME = 0b0001
 * 时，表示只允许进行一次有效的相位重载，等价于单次模式z
 *
 * @param Module 指向APT内存结构的指针
 * @param Times 相位重载次数
 *                APT_PHASE_RELOAD_0_TIMES
 *                APT_PHASE_RELOAD_1_TIMES
 *                APT_PHASE_RELOAD_2_TIMES
 *                APT_PHASE_RELOAD_3_TIMES
 *                APT_PHASE_RELOAD_4_TIMES
 *                APT_PHASE_RELOAD_5_TIMES
 *                APT_PHASE_RELOAD_6_TIMES
 *                APT_PHASE_RELOAD_7_TIMES
 *                APT_PHASE_RELOAD_8_TIMES
 *                APT_PHASE_RELOAD_9_TIMES
 *                APT_PHASE_RELOAD_10_TIMES
 *                APT_PHASE_RELOAD_11_TIMES
 *                APT_PHASE_RELOAD_12_TIMES
 *                APT_PHASE_RELOAD_13_TIMES
 *                APT_PHASE_RELOAD_14_TIMES
 *                APT_PHASE_RELOAD_15_TIMES
 * @return
 */
KF_INLINE void Apt_LL_SetPhaseReloadTimes(Apt_RegisterMap_t *const Module, const Apt_PhaseReloadNumOfTimes_t Times)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_PHASE_RELOAD_NUM_OF_TIMES(Module));
    REG_WRITE(Module->APT_T1PHSCTL.bits.PHSTIME, Times);
}

/**
 * @brief APT模块使能/禁止相位重载次数控制
 * @attention 仅在连续模式下有效
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 相位重载次数控制
 *                false 不限重载次数
 *                true 重载次数由 PHSTIME 确定
 * @retval
 */
KF_INLINE void Apt_LL_SetPhaseReloadTimesControlEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1PHSCTL.bits.PHSTIEN, Status);
}

/**
 * @brief APT模块设置重载发生后的计数方向
 * @attention 仅在在向上向下计数模式下有效
 *
 * @param Module 指向APT内存结构的指针
 * @param Direction 计数方向
 *                APT_PHASE_RELOAD_COUNT_UP 相位重载之后向上计数
 *                APT_PHASE_RELOAD_COUNT_DOWN 相位重载之后向下计数
 * @return
 */
KF_INLINE void
Apt_LL_SetPhaseReloadDirection(Apt_RegisterMap_t *const Module, const Apt_PhaseReloadDirection_t Direction)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_PHASE_RELOAD_DIRECTION(Direction));
    REG_WRITE(Module->APT_T1PHSCTL.bits.PHSDIR, Direction);
}

/*  APT_T1CNT_T */

/**
 * @brief APT模块配置定时器值
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Value 设置的值 0~0xFFFFFFFF
 * @return
 */
KF_INLINE void Apt_LL_SetCounter(Apt_RegisterMap_t *const Module, const uint32_t Value)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1CNT.reg, Value);
}

/**
 * @brief APT模块获取计数值
 * @attention 写APT_T1CNT寄存器的值只会在向上/向上向下计数方式下的启动时作为初始值载入
 *
 * @param Module 指向APT内存结构的指针
 * @retval 计数器值
 */
KF_INLINE uint32_t Apt_LL_GetCounter(const Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    return (REG_READ(Module->APT_T1CNT.reg));
}

/*  APT_T1PRSC1_T */

/**
 * @brief APT模块配置预分频
 * @details 可以将计数器的时钟频率按 1 到（FFFF FFFFh+1）之间的任意值分频，它是一个基于 32 位寄存器控制的 32
 * 位计数器。这个控制寄存器带有缓冲器，它能够在工作时被改变。新的预分频器参数在下一个计数周期开始时被采用。
 *
 * @param Module 指向APT内存结构的指针
 * @param Prescale 预分频值 0~0xFFFFFFFF, 实际分频1:1~1:(0xFFFFFFFF+1)
 * @return
 */
KF_INLINE void Apt_LL_SetPrescale1(Apt_RegisterMap_t *const Module, const uint32_t Prescale)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1PRSC1.reg, Prescale);
}

/*  APT_T1PRSC2_T */

/**
 * @brief APT模块配置分配器2分配比
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Prescale 预分频
 *                APT_PRESCALE2_DIVIDER_1 1:1 分频
 *                APT_PRESCALE2_DIVIDER_2 1:2 分频
 *                APT_PRESCALE2_DIVIDER_3 1:3 分频
 *                APT_PRESCALE2_DIVIDER_4 1:4 分频
 *                APT_PRESCALE2_DIVIDER_5 1:5 分频
 *                APT_PRESCALE2_DIVIDER_6 1:6 分频
 *                APT_PRESCALE2_DIVIDER_7 1:7 分频
 *                APT_PRESCALE2_DIVIDER_8 1:8 分频
 *                APT_PRESCALE2_DIVIDER_9 1:9 分频
 *                APT_PRESCALE2_DIVIDER_10 1:10 分频
 *                APT_PRESCALE2_DIVIDER_11 1:11 分频
 *                APT_PRESCALE2_DIVIDER_12 1:12 分频
 *                APT_PRESCALE2_DIVIDER_13 1:13 分频
 *                APT_PRESCALE2_DIVIDER_14 1:14 分频
 *                APT_PRESCALE2_DIVIDER_15 1:15 分频
 *                APT_PRESCALE2_DIVIDER_16 1:16 分频
 * @return
 */
KF_INLINE void Apt_LL_SetPrescale2(Apt_RegisterMap_t *const Module, const Apt_Prescale2_t Prescale)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_PRESCALE2_DIVIDER(Module));
    REG_WRITE(Module->APT_T1PRSC2.bits.CKBS, Prescale);
}

/*  APT_T1PPX_T */

/**
 * @brief APT模块配置周期
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Prescale 周期值 0~0xFFFFFFFF
 * @return
 */
KF_INLINE void Apt_LL_SetPeriod(Apt_RegisterMap_t *const Module, const uint32_t Period)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1PPX.bits.PPX, Period);
}

/**
 * @brief APT模块获取周期
 *
 *
 * @param Module 指向APT内存结构的指针
 * @retval 周期寄存器值
 */
KF_INLINE uint32_t Apt_LL_GetPeriod(const Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    return (REG_READ(Module->APT_T1PPX.bits.PPX));
}

/*  APT_T1PHS_T */

/**
 * @brief APT模块配置相位值，在同步事件发生时，会将该值加载到计数器CNT中。
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Phase 相位值 0~0xFFFFFFFF
 * @return
 */
KF_INLINE void Apt_LL_SetPhase(Apt_RegisterMap_t *const Module, const uint32_t Phase)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1PHS.bits.PHS, Phase);
}

/**
 * @brief APT模块获取相位值
 *
 *
 * @param Module 指向APT内存结构的指针
 * @retval 相位寄存器值
 */
KF_INLINE uint32_t Apt_LL_GetPhase(const Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    return (REG_READ(Module->APT_T1PHS.bits.PHS));
}

/*  APT_T1CCR0_T */

/**
 * @brief APT模块设置T1触发AD寄存器0值
 * @details 当 T1 计数值等于 T1CCR0时，产生脉冲信号去触发 AD
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Value T1CCR0设定值
 * @return
 */
KF_INLINE void Apt_LL_SetTrigAdcReg0(Apt_RegisterMap_t *const Module, const uint32_t Value)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1CCR0.bits.T1CCR0, Value);
}

/*  APT_T1CCR1_T */

/**
 * @brief APT模块设置T1触发AD寄存器1值
 * @details 当 T1 计数值等于 T1CCR1时，产生脉冲信号去触发 AD
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Value T1CCR1设定值
 * @return
 */
KF_INLINE void Apt_LL_SetTrigAdcReg1(Apt_RegisterMap_t *const Module, const uint32_t Value)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_T1CCR1.bits.T1CCR1, Value);
}

/*  APT_UDCTL_T */
/**
 * @brief APT模块设置T1更新使能/禁止
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status bool
 *                false 禁止以 T1 为时基的占空比、周期、输出控制、预分频、周期计数寄存器更新
 *                true 允许以 T1 为时基的占空比、周期、输出控制、预分频、周期计数寄存器更新
 * @retval void
 */
KF_INLINE void Apt_LL_SetT1UpdateEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_UDCTL.bits.T1UDEN, Status);
}

/**
 * @brief APT模块设置控制寄存器更新模式
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Mode 更新模式
 *                APT_TIMER_UPDATE_PERIODIC 当定时器 UDTIM1 为 0 时更新以 T1 为时基的输出控制寄存器
 *
 *                APT_TIMER_UPDATE_NOW 立即更新以 T1 为时基的输出控制寄存器
 * @return
 */
KF_INLINE void Apt_LL_SetT1CtrlRegUpdateEventMode(Apt_RegisterMap_t *const Module, Apt_TimerUpdateMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_TIMER_UPDATE_MODE(Mode));
    REG_WRITE(Module->APT_UDCTL.bits.T1UDEVT0, Mode);
}

/**
 * @brief APT模块设置占空比、周期、预分频、更新计数器寄存器更新模式
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Mode 更新模式
 *                APT_TIMER_UPDATE_PERIODIC
 * 当定时器UDTIM1为0时更新以T1为时基的占空比、周期、预分频、更新计数器寄存器，并将定时器清零
 *
 *                APT_TIMER_UPDATE_NOW 立即更新以 T1 为时基的占空比、周期、预分频、更新计数器寄存器，并将定时器清零
 * @return
 */
KF_INLINE void Apt_LL_SetT1UpdateEventMode(Apt_RegisterMap_t *const Module, Apt_TimerUpdateMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_TIMER_UPDATE_MODE(Mode));
    REG_WRITE(Module->APT_UDCTL.bits.T1UDEVT1, Mode);
}

/**
 * @brief APT模块立即产生更新事件
 * @details 初始化定时器 APT 的计数器并更新占空比、输出控制寄存器
 *
 * @param Module 指向APT内存结构的指针
 * @return
 */
KF_INLINE void Apt_LL_SetT1UpdateImmediately(Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_UDCTL.bits.T1UDR, 1U);
}

/**
 * @brief APT模块设置T1溢出脉冲更新占空比和输出控制功能使能/禁止
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status bool
 *                false 禁止 T1 溢出脉冲更新占空比和输出控制功能
 *                true 使能 T1 溢出脉冲更新占空比和输出控制功能
 * @return
 */
KF_INLINE void Apt_LL_SetT1OverflowUpdateEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_UDCTL.bits.T1OUDREN, Status);
}

/**
 * @brief APT模块设置重载使能/禁止
 * @details 设置发生立即更新事件时，是否重载相位值PHS；仅在使用 T1UDEVT1 产生立即更新事件的时候生效。
 *
 * @param Module 指向APT内存结构的指针
 * @param Status bool
 *                false 不重载相位值，更新事件发生时，将计数器复位（向上计数/向上向下计数模式下复位到
 * 0；向下计数模式下复位到 PPX）
 *
 *                true 更新事件发生时，将相位值PHS加载到计数器中
 * @return
 */
KF_INLINE void Apt_LL_SetTxPhaseReloadEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_UDCTL.bits.UDREN, Status);
}

/**
 * @brief:  APT模块设置TRGI触发控制寄存器更新使能/禁止
 * @attention 在 T1UDEN=1 时有效
 * @param Module 指向APT内存结构的指针
 * @param Status bool
 *          false   禁止 TRGI 触发更新输出控制寄存器
 *          true   使能 TRGI 触发更新输出控制寄存器
 * @retval void
 */
KF_INLINE void Apt_LL_SetTrigUpdateCtrlRegEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_UDCTL.bits.TRGUDEN0, Status);
}

/**
 * @brief:  APT模块设置TRGI触发更新使能/禁止
 * @attention 在 T1UDEN=1 时有效
 * @param Module 指向APT内存结构的指针
 * @param Status bool
 *          false   禁止 TRGI 触发更新占空比、周期、预分频寄存器
 *          true   使能 TRGI 触发更新占空比、周期、预分频寄存器
 * @retval void
 */
KF_INLINE void Apt_LL_SetTrigUpdateEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_UDCTL.bits.TRGUDEN1, Status);
}

/**
 * @brief APT模块设置输出控制寄存器TRGI触发更新模式
 *
 * @param Module 指向APT内存结构的指针
 * @param Mode 模式
 *                APT_TRGI_UPDATE_NOW TRGI 发生时立即更新输出控制寄存器
 *                APT_TRGI_UPDATE_WHEN_PERIOD_MATCH TRGI 发生后，再等到周期匹配时才更新输出控制寄存器
 * @return KF_INLINE
 */
KF_INLINE void Apt_LL_SetTrigUpdateCtrlRegMode(Apt_RegisterMap_t *const Module, const Apt_TrigUpdateMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_TRGI_UPDATE_MODE(Mode));
    REG_WRITE(Module->APT_UDCTL.bits.TUDMODE0, Mode);
}

/**
 * @brief APT模块设置占空比、周期、预分频寄存器TRGI触发更新模式
 *
 * @param Module 指向APT内存结构的指针
 * @param Mode 模式
 *                APT_TRGI_UPDATE_NOW TRGI 发生时立即更新占空比、周期、预分频寄存器
 *                APT_TRGI_UPDATE_WHEN_PERIOD_MATCH TRGI 发生后，再等到周期匹配时才更新占空比、周期、预分频寄存器
 * @return KF_INLINE
 */
KF_INLINE void Apt_LL_SetTrigUpdateMode(Apt_RegisterMap_t *const Module, const Apt_TrigUpdateMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_TRGI_UPDATE_MODE(Mode));
    REG_WRITE(Module->APT_UDCTL.bits.TUDMODE1, Mode);
}

/**
 * @brief APT模块设置通道的捕捉输入滤波使能/禁止
 *
 * @param Module 指向APT内存结构的指针
 * @param Channel 捕捉通道
 * @param Status 使能状态
 *                true    使能捕捉输入滤波
 *                false   禁止使能捕捉输入滤波
 * @retval void
 */
KF_INLINE void
Apt_LL_SetCaptureFilterEnabled(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    REG_BITS_WRITE(
      Module->APT_UDCTL.reg, (0x1U << (25U + (uint32_t)Channel)), ((uint32_t)Status << (25U + (uint32_t)Channel)));
}

/*  APT_UDTIM1_T */

/**
 * @brief 设置更新计数器值
 * @details 当使能 APT 的更新功能时，若 UDCTL 寄存器中的 T1UDEVT0=0，
 * 只有在计数值匹配 UDTIM1 的值时才会匹配更新 T1为时基的
 * 输出控制、输出配置寄存器。
 * 若 UDCTL 寄存器中的 T1UDEVT1=0，
 * 则只有在UDTIM1的值向下计数到0时
 * 才会更新T1为时基的占空比、周期、预分频寄存器到缓冲器中。
 *
 * @param Module 指向Apt内存结构的指针
 * @param Value 要写入UDTIM1的更新计数值
 * @retval void
 */
KF_INLINE void Apt_LL_SetTxUpdateCounter(Apt_RegisterMap_t *const Module, const uint8_t Value)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));

    REG_WRITE(Module->APT_UDTIM1.bits.UDCNT, Value);
}

/*  APT_CHCTL1_T */

/**
 * @brief APT模块选择通道工作模式
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel 通道
 * @param Mode 通道工作模式
 *                APT_CHANNEL_MODE_CLOSE 捕捉/比较关闭
 *                APT_CHANNEL_MODE_CAP_PWM PWM测量模式（特殊捕捉模式），在上升沿和下降沿发生捕捉
 *                APT_CHANNEL_MODE_CAP 捕捉模式
 *                APT_CHANNEL_MODE_CMP_GEN_EVENT 比较模式，比较匹配时产生特殊事件(清零定时器，触发 AD)
 *                APT_CHANNEL_MODE_CMP_HIGHT_LEVEL 比较模式，比较匹配时输出高电平
 *                APT_CHANNEL_MODE_CMP_LOW_LEVEL 比较模式，比较匹配时输出低电平
 *                APT_CHANNEL_MODE_CMP_DISABLE_OUTPUT 比较模式，比较匹配时引脚不输出
 *                APT_CHANNEL_MODE_CMP_DISABLE_TOGGLE 比较模式，匹配时输出电平翻转
 *                APT_CHANNEL_MODE_PWM_FREEDOM 自由模式
 * @retval void
 */
KF_INLINE void
Apt_LL_SelectChannelMode(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const Apt_ChannelMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL_MODE(Mode));

    REG_BITS_WRITE(
      Module->APT_CHCTL1.reg, ((uint32_t)0xFU << ((uint32_t)Channel << 2)), ((uint32_t)Mode << (uint32_t)Channel << 2));
}

/**
 * @brief APT模块设置霍尔模式使能
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 使能状态
 *                false 禁止霍尔模式
 *                true 使能霍尔模式
 * @return
 */
KF_INLINE void Apt_LL_SetHallModeEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_CHCTL1.bits.HMEN, Status);
}

/**
 * @brief APT模块设置霍尔模板比较使能
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 使能状态
 *                false 禁止霍尔模式模板比较
 *                true 使能霍尔模式模板比较
 * @return
 */
KF_INLINE void Apt_LL_SetHallTemplateCompareEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_CHCTL1.bits.HMPEN, Status);
}

/**
 * @brief APT模块设置单脉冲模式使能
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 使能状态
 *                false 禁止单脉冲模式
 *                true 使能单脉冲模式
 * @return
 */
KF_INLINE void Apt_LL_SetSinglePulseModeEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_CHCTL1.bits.SPMEN, Status);
}

/**
 * @brief APT模块选择单脉冲模式
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Mode
 *                APT_SINGLE_PULSE_MODE_CONTINUE 单脉冲模式下，计数溢出后 EN 位保持为1，
 *                下次触发源到来时会再次触发单脉冲输出
 *
 *                APT_SINGLE_PULSE_MODE_ONE_SHOT 单脉冲模式下，计数溢出后 EN 位清 0
 * @return
 */
KF_INLINE void Apt_LL_SelectSinglePulseMode(Apt_RegisterMap_t *const Module, Apt_SinglePulseMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_SINGLE_PULSE_MODE(Mode));
    REG_WRITE(Module->APT_CHCTL1.bits.SPMS, Mode);
}

/*  APT_CHCTL2_T */

/**
 * @brief APT模块设置通道端口输出控制
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Channel 通道
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Output
 *                APT_OUTPUT_CTRL_PWM_ACTIVE_HIGH PWM 输出，高有效
 *                APT_OUTPUT_CTRL_PWM_ACTIVE_LOW PWM 输出，低有效
 *                APT_OUTPUT_CTRL_PWM_FORCE_HIGH 强制低电平输出
 *                APT_OUTPUT_CTRL_PWM_FORCE_LOW 强制高电平输出
 * @return
 */
KF_INLINE void
Apt_LL_SetChannelOutputCtrl(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const Apt_OutputCtrl_t Output)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_OUTPUT_CTRL(Output));
    REG_BITS_WRITE(Module->APT_CHCTL2.reg, (0x3U << (((uint32_t)Channel << 2U) + 2U)),
                   ((uint32_t)Output << (((uint32_t)Channel << 2U) + 2U)));
}

/*  APT_CHCTL3_T */

/**
 * @brief APT模块捕捉测试模式使能/禁止
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 使能状态
 *                false 计数器正常工作
 *                true 进入捕捉测试模式
 * @return
 */
KF_INLINE void Apt_LL_SetCaptureTestEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_CHCTL3.bits.CAPTST, Status);
}

/**
 * @brief APT模块全局时基模式使能/禁止
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 使能状态
 *                false 禁止 GTB 模式
 *                true 使能 GTB 模式
 * @return
 */
KF_INLINE void Apt_LL_SetGlobalTimeBaseEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_CHCTL3.bits.GTBEN, Status);
}

/**
 * @brief APT模块设置全局时基GTB输出状态
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 使能状态
 * @return
 */
KF_INLINE void Apt_LL_GetGlobalTimeBaseStatus(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_CHCTL3.bits.GTBEOUT, Status);
}

/*  APT_ASCTL1_T */

/**
 * @brief APT模块设置自动关断源
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Channel 通道
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Source 自动关断源
 *                APT_SHUTDOWN_SOURCE_DISABLED 禁止自动关断
 *                APT_SHUTDOWN_SOURCE_BKIN_LOW BKIN 低电平
 *                APT_SHUTDOWN_SOURCE_CMP0_HIGH CMP0模块输出高电平
 *                APT_SHUTDOWN_SOURCE_CMP1_HIGH CMP1模块输出高电平
 *                APT_SHUTDOWN_SOURCE_CMP2_HIGH CMP2模块输出高电平
 *                APT_SHUTDOWN_SOURCE_CMP3_HIGH CMP3模块输出高电平
 *                APT_SHUTDOWN_SOURCE_ERU ERU
 * @return
 */
KF_INLINE void Apt_LL_SetShutDownSource(
  Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const Apt_ShutDownSource_t Source)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_SHUTDOWN_SOURCE(Source));

    REG_BITS_WRITE(
      Module->APT_ASCTL1.reg, (0x7U << ((uint32_t)Channel * 3)), ((uint32_t)Source << ((uint32_t)Channel * 3)));
}

/**
 * @brief APT模块设置PWM自动关断重启使能
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Status 使能状态
 *                false 自动关闭时，由软件置 1 控制位 ASEySTACLR 清零 ASEySTA，重启输出信号
 *                true 自动关闭时，一旦关闭事件消失，ASEySTA 将自动清零，输出信号自动重启
 * @return
 */
KF_INLINE void Apt_LL_SetPwmAutoRestartEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_ASCTL1.bits.RSEN, Status);
}

/*  APT_ASCTL2_T */

/**
 * @brief APT模块设置自动关断时输出引脚电平
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Channel 通道
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Level 输出引脚电平
 *                APT_SHUTDOWN_OUTPUT_LEVEL_LOW 驱动 CHyH 为低电平
 *                APT_SHUTDOWN_OUTPUT_LEVEL_HIGH 驱动 CHyH 为高电平
 *                APT_SHUTDOWN_OUTPUT_LEVEL_Z 驱动 CHyH 为三态
 *                APT_SHUTDOWN_OUTPUT_LEVEL_Z_1 驱动 CHyH 为三态
 * @return
 */
KF_INLINE void Apt_LL_SetPwmShutdownOutputLevel(
  Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const Apt_ShutdownOutputLevel_t Level)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_SHUTDOWN_OUTPUT_LEVEL(Level));
    REG_BITS_WRITE(Module->APT_ASCTL2.reg, (0x3U << (((uint32_t)Channel << 2U) + 2U)),
                   ((uint32_t)Level << (((uint32_t)Channel << 2U) + 2U)));
}

/**
 * @brief APT模块清除自动关断状态标志
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Channel 通道
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @return
 */
KF_INLINE void Apt_LL_ClearPwmShutdownStatus(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    REG_BIT_SET(Module->APT_ASCTL2.reg, (1U << ((uint32_t)Channel + 16U)));
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(Module->APT_ASCTL2.reg, (1U << ((uint32_t)Channel + 16U)));
}

/*  APT_ZPDCTL1_T */

/**
 * @brief APT模块零点检测时序控制
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Channel 通道
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Status 使能状态
 *                false 禁止比较器结果写入到 ZPDySTA 位
 *                true 使能比较器结果写入到 ZPDySTA 位
 * @return
 */
KF_INLINE void
Apt_LL_SetZeroPointDetectSequence(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    REG_BITS_WRITE(Module->APT_ZPDCTL1.reg, (1U << (uint32_t)Channel), ((uint32_t)Status << (uint32_t)Channel));
}

/**
 * @brief APT模块设置零点检测时钟
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Clock 零点检测时钟
 *                 APT_ZERO_POINT_DETECT_CLOCK_FPRS f_PRS
 *                APT_ZERO_POINT_DETECT_CLOCK_FPRS_2  f_PRS/2
 *                APT_ZERO_POINT_DETECT_CLOCK_FPRS_4 f_PRS/4
 *                APT_ZERO_POINT_DETECT_CLOCK_FPRS_8 f_PRS/8
 *                APT_ZERO_POINT_DETECT_CLOCK_FPRS_16 f_PRS/16
 *                APT_ZERO_POINT_DETECT_CLOCK_FPRS_32 f_PRS/32
 *                APT_ZERO_POINT_DETECT_CLOCK_FPRS_64 f_PRS/64
 *                APT_ZERO_POINT_DETECT_CLOCK_FPRS_128 f_PRS/128
 *                APT_ZERO_POINT_DETECT_CLOCK_FPRS_256 f_PRS/256
 *                APT_ZERO_POINT_DETECT_CLOCK_FPRS_512  f_PRS/512
 * @return
 */
KF_INLINE void Apt_LL_SetZeroPointDetectClock(Apt_RegisterMap_t *const Module, Apt_ZeroPointDetectClock_t Clock)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_ZERO_POINT_DETECT_CLOCK(Clock));
    REG_WRITE(Module->APT_ZPDCTL1.bits.ZCLK, Clock);
}

/*  APT_ZPDCTL2_T */

/**
 * @brief APT模块选择零点检测电压
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Voltage
 *                APT_ZERO_POINT_DETECT_VOLTAGE_15 0.15V
 *                APT_ZERO_POINT_DETECT_VOLTAGE_25 0.25V
 *                APT_ZERO_POINT_DETECT_VOLTAGE_35 0.35V
 *                APT_ZERO_POINT_DETECT_VOLTAGE_45 0.45V
 *                APT_ZERO_POINT_DETECT_VOLTAGE_55 0.55V
 * @return
 */
KF_INLINE void Apt_LL_SelectZeroPointDetectVoltage(
  Apt_RegisterMap_t *const Module, Apt_Channel_t Channel, Apt_ZeroPointDetectVoltage_t Voltage)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_ZERO_POINT_DETECT_VOLTAGE(Voltage));
    REG_BITS_WRITE(
      Module->APT_ZPDCTL2.reg, (0x7U << (uint32_t)Channel * 3), ((uint32_t)Voltage << (uint32_t)Channel * 3));
}

/**
 * @brief APT模块选择零点检测使能/禁止
 *
 * @param Module 指向APT内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Status 使能状态
 *                false 禁止零点检测比较器操作
 *                true 使能零点检测比较器操作
 * @return KF_INLINE
 */
KF_INLINE void
Apt_LL_SetZeroPointDetectEnabled(Apt_RegisterMap_t *const Module, Apt_Channel_t Channel, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    REG_BITS_WRITE(
      Module->APT_ZPDCTL2.reg, (1U << ((uint32_t)Channel + 12U)), ((uint32_t)Status << ((uint32_t)Channel + 12U)));
}

/**
 * @brief APT模块零点检测状态清零
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @return
 */
KF_INLINE void Apt_LL_ClearZeroPointDetectStatus(Apt_RegisterMap_t *const Module, Apt_Channel_t Channel)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    REG_BIT_SET(Module->APT_ZPDCTL2.reg, (1U << ((uint32_t)Channel + 16U)));
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(Module->APT_ZPDCTL2.reg, (1U << ((uint32_t)Channel + 16U)));
}

/*  APT_ZPDPORT_T */

/**
 * @brief APT模块设置零点检测端口控制
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param PinStatus
 *                APT_ZERO_POINT_DETECT_PIN_NO_EFFECT 无作用
 *                APT_ZERO_POINT_DETECT_PIN_HI_Z 将引脚设置为三态
 * @return
 */
KF_INLINE void Apt_LL_SetZeroPointDetectPinCtrl(
  Apt_RegisterMap_t *const Module, Apt_Channel_t Channel, Apt_ZeroPointDetectPinCtrl_t PinStatus)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_ZERO_POINT_DETECT(PinStatus));
    REG_BITS_WRITE(Module->APT_ZPDPORT.reg, (1U << (((uint32_t)Channel << 1U) + 1U)),
                   ((uint32_t)PinStatus << (((uint32_t)Channel << 1U) + 1U)));
}

/*  APT_HPCTL_T */

/**
 * @brief APT模块设置当前霍尔模式输入模板
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Template 输入模板
 * @return
 */
KF_INLINE void Apt_LL_SetHallInputCurrentTemplate(Apt_RegisterMap_t *const Module, Apt_HallTemplate_t Template)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_HALL_TEMPLATE(Template));
    REG_WRITE(Module->APT_HPCTL.bits.CURHP, Template);
}

/**
 * @brief APT模块设置期望霍尔模式输入模板
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Template 输入模板
 * @return
 */
KF_INLINE void Apt_LL_SetHallInputExpectTemplate(Apt_RegisterMap_t *const Module, Apt_HallTemplate_t Template)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_HALL_TEMPLATE(Template));
    REG_WRITE(Module->APT_HPCTL.bits.EXPHP, Template);
}

/**
 * @brief APT模块设置抖动计数器增量值
 *
 *
 * @param Module 指向APT内存结构的指针
 * @param Value 抖动计数器增量值
 * @return
 */
KF_INLINE void Apt_LL_SetDitherCounterIncVal(Apt_RegisterMap_t *const Module, Apt_DitherCounterIncVal_t Value)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_DITHER_COUNTER_INC_VALUE(Module));
    REG_WRITE(Module->APT_DITCTL.bits.FRCVAL, Value);
}

/**
 * @brief APT模块设置边沿抖动使能状态
 * @param Module: 指向APT内存结构的指针
 * @param Status:
 *                true   使能边沿抖动
 *                false   禁止边沿抖动
 * @retval void
 */
KF_INLINE void Apt_LL_SetEdgeDitherEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_DITCTL.bits.DEDEN, Status);
}

/**
 * @brief: APT模块设置周期抖动使能状态
 * @param Module: 指向APT内存结构的指针
 * @param Status:
 *                true   使能周期抖动
 *                false   禁止周期抖动
 * @retval void
 */
KF_INLINE void Apt_LL_SetPeriodicDitherEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    REG_WRITE(Module->APT_DITCTL.bits.DPEEN, Status);
}

/**
 * @brief APT模块设置CCR0触发AD计数方向选择使能
 *
 * @param Module 指向Apt内存结构的指针
 * @param Status 使能状态
 *                false 只要计数值等于 T1CCR0 寄存器值，就会触发 AD
 *                true 触发 AD 时机由 T1CCR0SEL 选择
 * @retval void
 */
KF_INLINE void Apt_LL_SetCCR0TrigAdEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));

    REG_WRITE(Module->APT_CCRCTL.bits.T1CCR0SEN, Status);
}

/**
 * @brief APT模块设置CCR1触发AD计数方向选择使能
 *
 * @param Module 指向Apt内存结构的指针
 * @param Status 使能状态
 *                false 只要计数值等于 T1CCR1 寄存器值，就会触发 AD
 *                true 触发 AD 时机由 T1CCR1SEL 选择
 * @retval void
 */
KF_INLINE void Apt_LL_SetCCR1TrigAdEnabled(Apt_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));

    REG_WRITE(Module->APT_CCRCTL.bits.T1CCR1SEN, Status);
}

/**
 * @brief APT模块选择T1CCR0 触发 AD 计数方向选择
 *          true  向下计数且计数值等于 T1CCR0 寄存器值时，触发 AD
 *          false  向上计数且计数值等于 T1CCR0 寄存器值时，触发 AD
 * @param Module 指向Apt内存结构的指针
 * @param Dir 计数方向
 *
 * @retval void
 */
KF_INLINE void
Apt_LL_SelectTxCcr0TrigAdCountDirection(Apt_RegisterMap_t *const Module, const Apt_CcrTrigAdDirection_t Dir)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_TRIG_AD_DIRECTION(Dir));
    REG_WRITE(Module->APT_CCRCTL.bits.T1CCR0SEL, Dir);
}

/**
 * @brief APT模块选择T1CCR1 触发 AD 计数方向选择
 *          true  向下计数且计数值等于 T1CCR1 寄存器值时，触发 AD
 *          false  向上计数且计数值等于 T1CCR1 寄存器值时，触发 AD
 * @param Module 指向Apt内存结构的指针
 * @param Dir 计数方向
 *
 * @retval void
 */
KF_INLINE void
Apt_LL_SelectTxCcr1TrigAdCountDirection(Apt_RegisterMap_t *const Module, const Apt_CcrTrigAdDirection_t Dir)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_TRIG_AD_DIRECTION(Dir));
    REG_WRITE(Module->APT_CCRCTL.bits.T1CCR1SEL, Dir);
}

/*  APT_APT_CAPCTL1_T */

/**
 * @brief APT模块设置通道捕捉使能/禁止
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Status 使能状态
 *                false 禁止通道捕捉功能
 *                true 使能通道捕捉功能
 * @retval void
 */
KF_INLINE void
Apt_LL_SetChannelCaptureEnabled(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));

    REG_BITS_WRITE(Module->APT_CAPCTL1.reg, (0x1U << (uint32_t)Channel), ((uint32_t)Status << (uint32_t)Channel));
}

/**
 * @brief APT模块设置通道捕捉模式
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Mode 捕捉模式
 *                APT_CAPTURE_MODE_CONTINUE 连续捕捉
 *                APT_CAPTURE_MODE_ONE_SHOT 单次捕捉
 * @retval void
 */
KF_INLINE void Apt_LL_SetChannelCaptureMode(
  Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const Apt_ChannelCaptureMode_t Mode)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL_CAPTURE_MODE(Mode));
    REG_BITS_WRITE(
      Module->APT_CAPCTL1.reg, (0x1U << ((uint32_t)Channel + 8U)), ((uint32_t)Mode << ((uint32_t)Channel + 8U)));
}

/**
 * @brief APT模块设置通道捕捉边沿
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Edge 边沿
 *                APT_CAPTURE_EDGE_RISE 上升沿
 *                APT_CAPTURE_EDGE_FALL 下降沿
 * @retval void
 */
KF_INLINE void Apt_LL_SetChannelCaptureEdge(
  Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const Apt_ChannelCaptureEdge_t Edge)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL_CAPTURE_EDGE(Edge));
    REG_BITS_WRITE(
      Module->APT_CAPCTL1.reg, (0x1U << ((uint32_t)Channel + 4U)), ((uint32_t)Edge << ((uint32_t)Channel + 4U)));
}

/**
 * @brief APT模块设置捕捉次数控制使能/禁止
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Status
 *                false 不控制捕捉次数
 *                true 捕捉次数由 CAPTIME 寄存器决定
 * @retval void
 */
KF_INLINE void Apt_LL_SetChannelCaptureTimesControllable(
  Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    REG_BITS_WRITE(
      Module->APT_CAPCTL1.reg, (0x1U << ((uint32_t)Channel + 12)), ((uint32_t)Status << ((uint32_t)Channel + 12)));
}

/**
 * @brief APT模块设置捕捉输入滤波使能
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Status
 *                false 禁止捕捉输入滤波
 *                true 使能捕捉输入滤波
 * @return KF_INLINE
 */
KF_INLINE void
Apt_LL_SetChannelCaptureFilterEnabled(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    REG_BITS_WRITE(
      Module->APT_CAPCTL1.reg, (0x1U << ((uint32_t)Channel + 16)), ((uint32_t)Status << ((uint32_t)Channel + 16)));
}

/*  APT_CAPCTL2_T */

/**
 * @brief APT模块选择捕捉输入引脚
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Pin
 *   APT_CAPTURE_CH1H  选择CH1H作为捕捉输入
 *   APT_CAPTURE_CH2H  选择CH2H作为捕捉输入
 *   APT_CAPTURE_CH3H  选择CH3H作为捕捉输入
 *   APT_CAPTURE_CMP1  选择CMP1输出作为捕捉输入
 *   APT_CAPTURE_CMP2  选择CMP2输出作为捕捉输入
 *   APT_CAPTURE_CMP3  选择CMP3输出作为捕捉输入
 *   APT_CAPTURE_CMP4  选择CMP4输出作为捕捉输入
 * @return
 */
KF_INLINE void Apt_LL_SelectChannelCapturePin(
  Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const Apt_ChannelCapturePin_t Pin)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL_CAPTURE_PIN(Pin));
    REG_BITS_WRITE(
      Module->APT_CAPCTL2.reg, (0x7U << ((uint32_t)Channel * 3)), ((uint32_t)Pin << ((uint32_t)Channel * 3)));
}

/*  APT_CAPPRSC_T */

/**
 * @brief APT模块设置通道捕捉分频
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Prescale
 *                APT_CAPTURE_PRESCALE_1 1次有效沿发生时，才会进行一次真正的有效捕捉事件
 *                APT_CAPTURE_PRESCALE_2 2次有效沿发生时，才会进行一次真正的有效捕捉事件
 *                APT_CAPTURE_PRESCALE_3 3次有效沿发生时，才会进行一次真正的有效捕捉事件
 *                APT_CAPTURE_PRESCALE_4 4次有效沿发生时，才会进行一次真正的有效捕捉事件
 *                APT_CAPTURE_PRESCALE_5 5次有效沿发生时，才会进行一次真正的有效捕捉事件
 *                APT_CAPTURE_PRESCALE_6 6次有效沿发生时，才会进行一次真正的有效捕捉事件
 *                APT_CAPTURE_PRESCALE_7 7次有效沿发生时，才会进行一次真正的有效捕捉事件
 *                APT_CAPTURE_PRESCALE_8 8次有效沿发生时，才会进行一次真正的有效捕捉事件
 * @return
 */
KF_INLINE void Apt_LL_SetChannelCapturePrescale(
  Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const Apt_ChannelCapturePrescale_t Prescale)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL_CAPTURE_PRESCALE(Prescale));
    REG_BITS_WRITE(
      Module->APT_CAPPRSC.reg, (0x7U << ((uint32_t)Channel * 3)), ((uint32_t)Prescale << ((uint32_t)Channel * 3)));
}

/*  APT_CAPTIME_T */

/**
 * @brief APT模块设置通道捕捉次数
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Prescale
 *                APT_CAPTURE_TIMES_0 0次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_1 1次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_2 2次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_3 3次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_4 4次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_5 5次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_6 6次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_7 7次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_8 8次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_9 9次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_10 10次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_11 11次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_12 12次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_13 13次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_14 14次有效捕捉事件就停止捕捉
 *                APT_CAPTURE_TIMES_15 15次有效捕捉事件就停止捕捉
 * @retval void
 */
KF_INLINE void Apt_LL_SetChannelCaptureTimes(
  Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const Apt_ChannelCaptureTimes_t Times)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL_CAPTURE_TIMES(Times));
    REG_BITS_WRITE(
      Module->APT_CAPTIME.reg, (0x7U << ((uint32_t)Channel * 3)), ((uint32_t)Times << ((uint32_t)Channel * 3)));
}

/*  APT_CAPFLT_T */

/**
 * @brief APT模块设置通道捕捉输入滤波时钟分频
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Prescale 分频
 *                APT_CAPTURE_FILTER_PRESCALE_1 1分频(默认)
 *                APT_CAPTURE_FILTER_PRESCALE_2 2分频
 *                APT_CAPTURE_FILTER_PRESCALE_3 3分频
 *                APT_CAPTURE_FILTER_PRESCALE_4 4分频
 *                APT_CAPTURE_FILTER_PRESCALE_5 5分频
 *                APT_CAPTURE_FILTER_PRESCALE_6 6分频
 *                APT_CAPTURE_FILTER_PRESCALE_7 7分频
 *                APT_CAPTURE_FILTER_PRESCALE_8 8分频
 *                APT_CAPTURE_FILTER_PRESCALE_9 9分频
 *                APT_CAPTURE_FILTER_PRESCALE_10 10分频
 *                APT_CAPTURE_FILTER_PRESCALE_11 11分频
 *                APT_CAPTURE_FILTER_PRESCALE_12 12分频
 *                APT_CAPTURE_FILTER_PRESCALE_13 13分频
 *                APT_CAPTURE_FILTER_PRESCALE_14 14分频
 *                APT_CAPTURE_FILTER_PRESCALE_15 15分频
 *                APT_CAPTURE_FILTER_PRESCALE_16 16分频
 * @return
 */
KF_INLINE void Apt_LL_SetChannelCaptureFilterPrescale(
  Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, Apt_ChannelCaptureFilterPrescale_t Prescale)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL_CAPTURE_FILTER_PRESCALE(Prescale));
    REG_BITS_WRITE(
      Module->APT_CAPFLT.reg, (0xFU << ((uint32_t)Channel << 2)), ((uint32_t)Prescale << ((uint32_t)Channel << 2)));
}

/**
 * @brief APT模块设置通道捕捉输入滤波次数
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Times 滤波次数
 *                APT_CAPTURE_FILTER_TIMES_1 滤波长度为1
 *                APT_CAPTURE_FILTER_TIMES_2 滤波长度为2
 *                APT_CAPTURE_FILTER_TIMES_3 滤波长度为3
 *                APT_CAPTURE_FILTER_TIMES_4 滤波长度为4
 *                APT_CAPTURE_FILTER_TIMES_5 滤波长度为5
 *                APT_CAPTURE_FILTER_TIMES_6 滤波长度为6
 *                APT_CAPTURE_FILTER_TIMES_7 滤波长度为7
 *                APT_CAPTURE_FILTER_TIMES_8 滤波长度为8
 * @return
 */
KF_INLINE void Apt_LL_SetChannelCaptureFilterTimes(
  Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, Apt_ChannelCaptureFilterTimes_t Times)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL_CAPTURE_FILTER_TIMES(Channel));
    REG_BITS_WRITE(Module->APT_CAPFLT.reg, (0x7U << ((uint32_t)Channel * 3 + 16)),
                   ((uint32_t)Times << ((uint32_t)Channel * 3 + 16)));
}

/*  APT_STA_T */

/**
 * @brief APT模块获取T1计数方向
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @retval bool
 *              false 向上计数
 *              true 向下计数
 */
KF_INLINE bool Apt_LL_GetT1CounterDirection(Apt_RegisterMap_t *const Module)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    return (bool)(REG_READ(Module->APT_STA.bits.T1DIR));
}

/**
 * @brief APT模块返回自动关断事件状态
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @retval bool
 *                false 通道正常工作
 *                true 通道发生了关闭事件，通道关闭
 */
KF_INLINE bool Apt_LL_GetChannelShutdownStatus(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    return (bool)(REG_BITS_READ(Module->APT_STA.reg, (1U << ((uint32_t)Channel + 2)), ((uint32_t)Channel + 2)));
}

/**
 * @brief APT模块返回检测零点状态
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @retval bool
 *                false 检测到感应电压（未检测到零点）
 *                true 未检测到感应电压（检测到零点）
 */
KF_INLINE bool Apt_LL_GetChannelZeroPointStatus(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    return (bool)(REG_BITS_READ(Module->APT_STA.reg, (1U << ((uint32_t)Channel + 6)), ((uint32_t)Channel + 6)));
}

/*  APT_C1_T */
/*  APT_C2_T */
/*  APT_C3_T */

/**
 * @brief APT模块返回捕捉寄存器值
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @retval uint32_t 捕捉寄存器值
 */
KF_INLINE uint32_t Apt_LL_GetCaptureRegisterValue(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    return REG_READ((&Module->APT_C1.reg)[(uint32_t)Channel * 2]);
}

/*  APT_BC1_T */
/*  APT_BC2_T */
/*  APT_BC3_T */

/**
 * @brief APT模块返回备用捕捉寄存器值
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @retval uint32_t 备用捕捉寄存器值
 */
KF_INLINE uint32_t Apt_LL_GetBackupCaptureRegisterValue(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    return REG_READ((&Module->APT_BC1.reg)[(uint32_t)Channel * 2]);
}

/*  APT_R1_T */
/*  APT_R2_T */
/*  APT_R3_T */
/**
 * @brief APT模块返回比较寄存器值
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @retval uint32_t 比较寄存器值
 */
KF_INLINE uint32_t Apt_LL_GetCompareRegisterValue(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    return (REG_READ((&Module->APT_R1.reg)[(uint32_t)Channel]));
}

/**
 * @brief APT模块设置比较寄存器值
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Channel
 *                APT_CHANNEL_1
 *                APT_CHANNEL_2
 *                APT_CHANNEL_3
 * @param Value 输入值
 * @retval void
 */
KF_INLINE void
Apt_LL_SetCompareRegisterValue(Apt_RegisterMap_t *const Module, const Apt_Channel_t Channel, const uint32_t Value)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_CHANNEL(Channel));
    REG_WRITE((&Module->APT_R1.reg)[(uint32_t)Channel], Value);
}

/*  APT_IF_T */

/**
 * @brief 获取APT模块中断状态
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Index
 *                APT_INTERRUPT_FLAG_OVERFLOW 溢出事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL1_EVENT 通道1捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL2_EVENT 通道2捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL3_EVENT 通道3捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_TRIGGER_EVENT T1 触发事件中断标志
 *                APT_INTERRUPT_FLAG_UPDATE_EVENT T1 更新事件中断标志
 *                APT_INTERRUPT_FLAG_HALL_ERROR  霍尔错误中断标志
 *                APT_INTERRUPT_FLAG_HALL_MODIFY 霍尔修改中断标志
 * @return bool
 * false 未发生中断
 * true 发生中断
 */
KF_INLINE bool Apt_LL_GetIntrFlag(Apt_RegisterMap_t *const Module, Apt_InterruptGetIndex_t Index)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_INTERRUPT_FLAG_INDEX(Index));
    return ((bool)REG_BITS_READ(Module->APT_IF.reg, (1U << (uint32_t)Index), (uint32_t)Index));
}

/*  APT_IE_T */

/**
 * @brief APT模块设置中断使能/禁止
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Index
 *                APT_INTERRUPT_FLAG_OVERFLOW 溢出事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL1_EVENT 通道1捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL2_EVENT 通道2捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL3_EVENT 通道3捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_TRIGGER_EVENT T1 触发事件中断标志
 *                APT_INTERRUPT_FLAG_UPDATE_EVENT T1 更新事件中断标志
 *                APT_INTERRUPT_FLAG_HALL_ERROR  霍尔错误中断标志
 *                APT_INTERRUPT_FLAG_HALL_MODIFY 霍尔修改中断标志
 * @param Status 中断使能状态
 *                false 中断禁止
 *                true 中断使能
 * @retval
 */
KF_INLINE void Apt_LL_SetIntrEnabled(Apt_RegisterMap_t *const Module, Apt_InterruptGetIndex_t Index, const bool Status)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_INTERRUPT_FLAG_INDEX(Index));
    REG_BITS_WRITE(Module->APT_IE.reg, (1U << (uint32_t)Index), ((uint32_t)Status << (uint32_t)Index));
}

/*  APT_IC_T */

/**
 * @brief APT模块清除中断标志
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Index
 *                APT_INTERRUPT_FLAG_OVERFLOW 溢出事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL1_EVENT 通道1捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL2_EVENT 通道2捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL3_EVENT 通道3捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_TRIGGER_EVENT T1 触发事件中断标志
 *                APT_INTERRUPT_FLAG_UPDATE_EVENT T1 更新事件中断标志
 *                APT_INTERRUPT_FLAG_HALL_ERROR  霍尔错误中断标志
 *                APT_INTERRUPT_FLAG_HALL_MODIFY 霍尔修改中断标志
 * @retval void
 */
KF_INLINE void Apt_LL_ClearIntrFlag(Apt_RegisterMap_t *const Module, Apt_InterruptGetIndex_t Index)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_INTERRUPT_FLAG_INDEX(Index));
    REG_BIT_SET(Module->APT_IC.reg, (1U << (uint32_t)Index));
}

/*  APT_IS_T */

/**
 * @brief APT模块置位中断标志
 *
 *
 * @param Module 指向Apt内存结构的指针
 * @param Index
 *                APT_INTERRUPT_FLAG_OVERFLOW 溢出事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL1_EVENT 通道1捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL2_EVENT 通道2捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL3_EVENT 通道3捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_TRIGGER_EVENT T1 触发事件中断标志
 *                APT_INTERRUPT_FLAG_UPDATE_EVENT T1 更新事件中断标志
 *                APT_INTERRUPT_FLAG_HALL_ERROR  霍尔错误中断标志
 *                APT_INTERRUPT_FLAG_HALL_MODIFY 霍尔修改中断标志
 * @retval void
 */
KF_INLINE void Apt_LL_SetIntrFlag(Apt_RegisterMap_t *const Module, Apt_InterruptGetIndex_t Index)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_INTERRUPT_FLAG_INDEX(Index));
    REG_BIT_SET(Module->APT_IS.reg, (1U << (uint32_t)Index));
}

/*  APT_INP_T */

/**
 * @brief APT模块选择中断节点
 *
 * @param Module 指向Apt内存结构的指针
 * @param Index
 *                APT_INTERRUPT_FLAG_OVERFLOW 溢出事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL1_EVENT 通道1捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL2_EVENT 通道2捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_CHANNEL3_EVENT 通道3捕捉/比较事件中断标志
 *                APT_INTERRUPT_FLAG_TRIGGER_EVENT T1 触发事件中断标志
 *                APT_INTERRUPT_FLAG_UPDATE_EVENT T1 更新事件中断标志
 *                APT_INTERRUPT_FLAG_HALL_ERROR  霍尔错误中断标志
 *                APT_INTERRUPT_FLAG_HALL_MODIFY 霍尔修改中断标志
 * @param Line
 *                APT_INTERRUPT_LINE_0 中断线0
 *                APT_INTERRUPT_LINE_1 中断线1
 *                APT_INTERRUPT_LINE_2 中断线2
 *                APT_INTERRUPT_LINE_3 中断线3
 * @return KF_INLINE
 */
KF_INLINE void Apt_LL_SelecServiceIntrLine(
  Apt_RegisterMap_t *const Module, Apt_InterruptGetIndex_t Index, Apt_ServiceInterruptLine_t Line)
{
    KF_DRV_APT_ASSERT(CHECK_APT_ALL_PERIPH(Module));
    KF_DRV_APT_ASSERT(CHECK_APT_INTERRUPT_FLAG_INDEX(Index));
    KF_DRV_APT_ASSERT(CHECK_APT_INTERRUPT_LINE(Line));
    REG_BITS_WRITE(Module->APT_INP.reg, (3U << ((uint32_t)Index * 2)), ((uint32_t)Line << ((uint32_t)Index * 2)));
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
