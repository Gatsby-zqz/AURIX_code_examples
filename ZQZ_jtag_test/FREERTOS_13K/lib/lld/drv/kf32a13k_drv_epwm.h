/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_epwm.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2024-01-02
 *  @Version         : V0.0.1.240102_alpha
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
 *  |2024-01-02                                       |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/

#ifndef KF32A1x8_DRV_EPWM_H_
#define KF32A1x8_DRV_EPWM_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a13k_reg_epwm.h"

#ifdef KF_DRV_EPWM_ASSERT
#include "dev_assert.h"
#define KF_DRV_EPWM_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_EPWM_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/

typedef enum
{
    EPWM_SUSPEND_MODE_NONE = 0,
    EPWM_SUSPEND_MODE_STOP = 2,
} Epwm_SuspendMode_t;
#define CHECK_EPWM_SUSPEND_MODE(MODE) ((MODE == EPWM_SUSPEND_MODE_NONE) || (MODE == EPWM_SUSPEND_MODE_STOP))

typedef enum
{
    EPWM_MASTER_TAG_ID0,
    EPWM_MASTER_TAG_ID1,
    EPWM_MASTER_TAG_ID2,
    EPWM_MASTER_TAG_ID3,
    EPWM_MASTER_TAG_ID4,
    EPWM_MASTER_TAG_ID5,
    EPWM_MASTER_TAG_ID6,
    EPWM_MASTER_TAG_ID7,
    EPWM_MASTER_TAG_ID8,
    EPWM_MASTER_TAG_ID9,
    EPWM_MASTER_TAG_ID10,
    EPWM_MASTER_TAG_ID11,
    EPWM_MASTER_TAG_ID12,
    EPWM_MASTER_TAG_ID13,
    EPWM_MASTER_TAG_ID14,
    EPWM_MASTER_TAG_ID15,
    EPWM_MASTER_TAG_ID16,
    EPWM_MASTER_TAG_ID17,
    EPWM_MASTER_TAG_ID18,
    EPWM_MASTER_TAG_ID19,
    EPWM_MASTER_TAG_ID20,
    EPWM_MASTER_TAG_ID21,
    EPWM_MASTER_TAG_ID22,
    EPWM_MASTER_TAG_ID23,
    EPWM_MASTER_TAG_ID24,
    EPWM_MASTER_TAG_ID25,
    EPWM_MASTER_TAG_ID26,
    EPWM_MASTER_TAG_ID27,
    EPWM_MASTER_TAG_ID28,
    EPWM_MASTER_TAG_ID29,
    EPWM_MASTER_TAG_ID30,
    EPWM_MASTER_TAG_ID31,
} Epwm_MasterTAGId_t;
#define CHECK_EPWM_MASTER_TAG_ID(ID) (!(ID >> 5U))

/* EPWM 定时器工作模式 */
typedef enum
{
    /* 定时器模式 */
    EPWM_TIMING_MODE,
    /* 计数模式 */
    EPWM_COUNT_MODE,
} Epwm_TimerWorkMode_t;
#define CHECK_EPWM_TIMER_WORK_MODE(MODE) (!(MODE >> 1U))

/* EPWM 时钟源选择 */
typedef enum
{
    /* 时钟源 f_SPB */
    EPWM_CLOCK_SOURCE_F_SPB,
    /* 时钟源 f_TMR */
    EPWM_CLOCK_SOURCE_F_TMR,
} Epwm_ClockSource_t;
#define CHECK_EPWM_CLOCK_SOURCE_MODE(SOURCE) (!(SOURCE >> 1U))

/* 定时器计数方式 */
typedef enum
{
    EPWM_COUNTING_MANNER_UP_UP_FLAG,
    EPWM_COUNTING_MANNER_DOWN_DOWN_FLAG,
    EPWM_COUNTING_MANNER_UP_DOWN_UP_FLAG,
    EPWM_COUNTING_MANNER_UP_DOWN_DOWN_FLAG,
    EPWM_COUNTING_MANNER_UP_DOWN_BOTH_FLAG,
} Epwm_CountingManner_t;
#define CHECK_EPWM_COUNTING_MANNER(MANNER) ((uint32_t)MANNER <= EPWM_COUNTING_UP_DOWN_BOTH_FLAG)

/* 同步事件输出 SYNCO 选择 */
typedef enum
{
    /* 禁止 SYNCO 输出 */
    EPWM_DISABLE_SYNCO,
    /* 计数值等于0值脉冲 */
    EPWM_TX_COUNT_EQU_ZERO,
    /* 计数值等于RB值脉冲 */
    EPWM_TX_COUNT_EQU_RB,
    /* SYNCI 以及 SWFSYNC */
    EPWM_SYNCI_AND_SWFSYNC,
} Epwm_SyncEvent_t;
#define CHECK_EPWM_SYNC_EVENT(EVENT) (!(EVENT >> 2U))

/* 相位方向控制 */
typedef enum
{
    /* 同步事件触发后向上计数 */
    EPWM_PHASE_RELOAD_COUNT_DOWN,
    /* 同步事件触发后向下计数 */
    EPWM_PHASE_RELOAD_COUNT_UP,
} Epwm_PhaseReloadDirection_t;
#define CHECK_EPWM_PHASE_RELOAD_DIRECTION(DIRECTION) (!(DIRECTION >> 1U))

/* EPWM 输出路径 */
typedef enum
{
    /** EPWM A路输出 */
    EPWM_OUTPUT_A,
    /** EPWM B路输出 */
    EPWM_OUTPUT_B,
    /** EPWM C路输出 */
    EPWM_OUTPUT_C,
    /** EPWM D路输出 */
    EPWM_OUTPUT_D,
} Epwm_Output_t;
#define CHECK_EPWM_OUTPUT(OUTPUT) (!(OUTPUT >> 2U))

/* 消隐窗口极性 */
typedef enum
{
    /* 消隐窗口高电平有效 */
    EPWM_BLANK_WINDOW_POLARITY_HIGH,
    /* 消隐窗口低电平有效 */
    EPWM_BLANK_WINDOW_POLARITY_LOW,
} Epwm_BlankWindowPolarity_t;
#define CHECK_BLANK_WINDOW_POLARITY(POLARITY) (!(POLARITY >> 1U))

/* 消隐窗口偏置参考点 */
typedef enum
{
    /* 消隐窗口偏置参考点为计数器为 0 */
    EPWM_BLANK_WINDOW_REF_CNT_0,
    /* 消隐窗口偏置参考点为计数器为 PPX */
    EPWM_BLANK_WINDOW_REF_CNT_PPX,
} Epwm_BlankWindowRef_t;
#define CHECK_BLANK_WINDOW_REF(REF) (!(REF >> 1U))

/* 双边死区模式选择 */
typedef enum
{
    /* 优先上升沿死区 */
    EPWM_DEAD_ZONE_EDGE_RAISE,
    /* 优先下降沿死区 */
    EPWM_DEAD_ZONE_EDGE_FALL,
} Epwm_DeadZoneEdge_t;
#define CHECK_DEAD_ZONE_EDGE(EDGE) (!(EDGE >> 1U))

/* 同步输入信号滤波时钟分频 */
typedef enum
{
    /* 1:1分频 */
    EPWM_SYNC_FILTER_PRESCALE_1,
    /* 1:2分频 */
    EPWM_SYNC_FILTER_PRESCALE_2,
    /* 1:3分频 */
    EPWM_SYNC_FILTER_PRESCALE_3,
    /* 1:4分频 */
    EPWM_SYNC_FILTER_PRESCALE_4,
    /* 1:5分频 */
    EPWM_SYNC_FILTER_PRESCALE_5,
    /* 1:6分频 */
    EPWM_SYNC_FILTER_PRESCALE_6,
    /* 1:7分频 */
    EPWM_SYNC_FILTER_PRESCALE_7,
    /* 1:8分频 */
    EPWM_SYNC_FILTER_PRESCALE_8,
    /* 1:9分频 */
    EPWM_SYNC_FILTER_PRESCALE_9,
    /* 1:10分频 */
    EPWM_SYNC_FILTER_PRESCALE_10,
    /* 1:11分频 */
    EPWM_SYNC_FILTER_PRESCALE_11,
    /* 1:12分频 */
    EPWM_SYNC_FILTER_PRESCALE_12,
    /* 1:13分频 */
    EPWM_SYNC_FILTER_PRESCALE_13,
    /* 1:14分频 */
    EPWM_SYNC_FILTER_PRESCALE_14,
    /* 1:15分频 */
    EPWM_SYNC_FILTER_PRESCALE_15,
    /* 1:16分频 */
    EPWM_SYNC_FILTER_PRESCALE_16,
} Epwm_SyncFilterPrescale_t;
#define CHECK_SYNC_FILTER_PRESCALE(PRESCALE) (!(PRESCALE >> 4U))

/* 同步输入信号滤波延时 */
typedef enum
{
    /* 延时1个滤波时钟 */
    EPWM_SYNC_FILTER_DELAY_1,
    /* 延时2个滤波时钟 */
    EPWM_SYNC_FILTER_DELAY_2,
    /* 延时3个滤波时钟 */
    EPWM_SYNC_FILTER_DELAY_3,
    /* 延时4个滤波时钟 */
    EPWM_SYNC_FILTER_DELAY_4,
    /* 延时5个滤波时钟 */
    EPWM_SYNC_FILTER_DELAY_5,
    /* 延时6个滤波时钟 */
    EPWM_SYNC_FILTER_DELAY_6,
    /* 延时7个滤波时钟 */
    EPWM_SYNC_FILTER_DELAY_7,
} Epwm_SyncFilterDelay_t;
#define CHECK_SYNC_FILTER_DELAY(DELAY) (!(DELAY >> 3U))

/* 外部时钟输入滤波时钟分频 */
typedef enum
{
    /* 1:1分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_1,
    /* 1:2分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_2,
    /* 1:3分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_3,
    /* 1:4分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_4,
    /* 1:5分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_5,
    /* 1:6分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_6,
    /* 1:7分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_7,
    /* 1:8分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_8,
    /* 1:9分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_9,
    /* 1:10分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_10,
    /* 1:11分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_11,
    /* 1:12分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_12,
    /* 1:13分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_13,
    /* 1:14分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_14,
    /* 1:15分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_15,
    /* 1:16分频 */
    EPWM_EXTERN_CLOCK_FILTER_PRESCALE_16,
} Epwm_ExternClockFilterPrescale_t;
#define CHECK_EXTERN_CLOCK_FILTER_PRESCALE(PRESCALE) (!(PRESCALE >> 4U))

/* 外部时钟输入滤波延时 */
typedef enum
{
    /* 延时1个滤波时钟 */
    EPWM_EXTERN_CLOCK_DELAY_1,
    /* 延时2个滤波时钟 */
    EPWM_EXTERN_CLOCK_DELAY_2,
    /* 延时3个滤波时钟 */
    EPWM_EXTERN_CLOCK_DELAY_3,
    /* 延时4个滤波时钟 */
    EPWM_EXTERN_CLOCK_DELAY_4,
    /* 延时5个滤波时钟 */
    EPWM_EXTERN_CLOCK_DELAY_5,
    /* 延时6个滤波时钟 */
    EPWM_EXTERN_CLOCK_DELAY_6,
    /* 延时7个滤波时钟 */
    EPWM_EXTERN_CLOCK_DELAY_7,
} Epwm_ExternClockFilterDelay_t;
#define CHECK_EXTERN_CLOCK_FILTER_DELAY(DELAY) (!(DELAY >> 3U))

typedef enum
{
    EPWM_CAPIF_NO_EFFECT_ON_CAP_EVENT,
    EPWM_DISABLE_CAP_EVENT_WHEN_CAPIF_SET,
} Epwm_CaptureMode_t;
#define CHECK_CAPTURE_MODE(MODE) (!(MODE >> 1U))

/* EPWM事件正常输出电平*/
typedef enum
{
    /* 不触发该事件、 无动作 */
    EPWM_OUTPUT_LEVEL_NONE,
    /* 输出低电平 */
    EPWM_OUTPUT_LEVEL_LOW,
    /* 输出高电平 */
    EPWM_OUTPUT_LEVEL_HIGH,
    /* 输出时,翻转电平 */
    EPWM_OUTPUT_LEVEL_TOGGLE,
} Epwm_OutputLevel_t;
#define CHECK_EPWM_OUTPUT_LEVEL(LEVEL) (!(LEVEL >> 2U))

typedef enum
{
    /* 无动作 */
    EPWM_FORCE_OUTPUT_LEVEL_NONE,
    /* 输出低电平 */
    EPWM_FORCE_OUTPUT_LEVEL_LOW,
    /* 输出高电平 */
    EPWM_FORCE_OUTPUT_LEVEL_HIGH,
    /* 禁止连续输出 */
    EPWM_FORCE_OUTPUT_LEVEL_FORBIDDEN,
} Epwm_ForceConOutputLevel_t;
#define CHECK_EPWM_FORCE_CONTINUOUS_OUTPUT_LEVEL(LEVEL) (!(LEVEL >> 2U))

/* EPWM 输出事件 */
typedef enum
{
    /* CNT计数值等于0 */
    EPWM_OUTPUT_TX_EQU_ZERO,
    /* CNT计数值等于PPX */
    EPWM_OUTPUT_TX_EQU_PERIOD,
    /* CNT计数值等于RA,且计数方向向上 */
    EPWM_OUTPUT_TX_EQU_RA_COUNT_UP,
    /* CNT计数值等于RA,且计数方向向下 */
    EPWM_OUTPUT_TX_EQU_RA_COUNT_DOWN,
    /* CNT计数值等于RB,且计数方向向上 */
    EPWM_OUTPUT_TX_EQU_RB_COUNT_UP,
    /* CNT计数值等于RB,且计数方向向下 */
    EPWM_OUTPUT_TX_EQU_RB_COUNT_DOWN,
} Epwm_OutputEvent_t;
#define CHECK_EPWM_OUTPUT_EVENT(EVENT) ((uint32_t)(EVENT) <= (uint32_t)EPWM_OUTPUT_TX_EQU_RB_COUNT_DOWN)

/* EPWM独立更新寄存器 */
typedef enum
{
    /* PPX周期寄存器 */
    EPWM_UPDATE_REG_PPX,
    /* PRSC预分频寄存器 */
    EPWM_UPDATE_REG_PRSC,
    /* RA占空比寄存器 */
    EPWM_UPDATE_REG_RA,
    /* RB占空比寄存器 */
    EPWM_UPDATE_REG_RB,
    /* RC占空比寄存器 */
    EPWM_UPDATE_REG_RC,
    /* RD占空比寄存器 */
    EPWM_UPDATE_REG_RD,
    /* ACTL A路输出控制寄存器 */
    EPWM_UPDATE_REG_ACTL,
    /* BCTL B路输出控制寄存器 */
    EPWM_UPDATE_REG_BCTL,

    /* HRRA 高精度占空比寄存器A */
    EPWM_UPDATE_REG_HRRA,
    /* HRRB 高精度占空比寄存器B */
    EPWM_UPDATE_REG_HRRB,
    /* DB 死区寄存器 */
    EPWM_UPDATE_REG_DB,
    /* HRDB 高精度死区寄存器 */
    EPWM_UPDATE_REG_HRDB,
    /* HRPHS 高精度相位寄存器 */
    EPWM_UPDATE_REG_HRPHS,
    /* HRCFG 高精度配置寄存器 */
    EPWM_UPDATE_REG_HRCFG,
} Epwm_UpdateReg_t;
#define CHECK_EPWM_UPDATE_REG(REG) ((uint32_t)REG <= (uint32_t)EPWM_UPDATE_REG_HRCFG)

/* EPWM独立更新事件 */
typedef enum
{
    /** 计数器计数值等于0时更新 */
    EPWM_UPDATE_EVENT_CNT_EQU_ZERO,
    /** 计数器计数值等于PPX值时更新 */
    EPWM_UPDATE_EVENT_CNT_EQU_PPX,
    /** 计数器计数值等于0或者等于PPX值时更新 */
    EPWM_UPDATE_EVENT_BOTH,
    /** 输入同步信号时更新 */
    EPWM_UPDATE_EVENT_SYNC,
} Epwm_UpdateEvent_t;
#define CHECK_EPWM_UPDATE_EVENT(EVENT) (!(EVENT >> 2U))

/* EPWM 更新方式 */
typedef enum
{
    /* 周期更新 */
    EPWM_UPDATE_PERIODIC,
    /* 立即更新 */
    EPWM_UPDATE_NOW,
} Epwm_UpdateMode_t;
#define CHECK_UPDATE_MODE(MODE) (!(MODE >> 1U))

/* EPWM 滤波时钟分频 */
typedef enum
{
    /* 1:1 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_1,
    /* 1:2 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_2,
    /* 1:3 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_3,
    /* 1:4 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_4,
    /* 1:5 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_5,
    /* 1:6 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_6,
    /* 1:7 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_7,
    /* 1:8 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_8,
    /* 1:9 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_9,
    /* 1:10 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_10,
    /* 1:11 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_11,
    /* 1:12 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_12,
    /* 1:13 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_13,
    /* 1:14 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_14,
    /* 1:15 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_15,
    /* 1:16 分频*/
    EPWM_CAPTURE_FILTER_PRESCALE_16,
} Epwm_CaptureFilterPrescale_t;
#define CHECK_EPWM_CAPTURE_FILTER_PRESCALE(PRESCALE) (!(PRESCALE >> 4U))

/* 捕捉通道滤波延时 */
typedef enum
{
    /* 延时1个滤波时钟 */
    EPWM_CAPTURE_DELAY_1,
    /* 延时2个滤波时钟 */
    EPWM_CAPTURE_DELAY_2,
    /* 延时3个滤波时钟 */
    EPWM_CAPTURE_DELAY_3,
    /* 延时4个滤波时钟 */
    EPWM_CAPTURE_DELAY_4,
    /* 延时5个滤波时钟 */
    EPWM_CAPTURE_DELAY_5,
    /* 延时6个滤波时钟 */
    EPWM_CAPTURE_DELAY_6,
    /* 延时7个滤波时钟 */
    EPWM_CAPTURE_DELAY_7,
} Epwm_CaptureFilterDelay_t;
#define CHECK_EPWM_CAPTURE_FILTER_DELAY(DELAY) (!(DELAY >> 3U))

/* EPWM 死区输出选择 */
typedef enum
{
    /* 上升/下降沿死区模块都被旁路 */
    EPWM_DEAD_OUT_RAISE_PASS_FALL_PASS,
    /* 上升沿死区模块被旁路,下降沿死区模块使能 */
    EPWM_DEAD_OUT_RAISE_PASS_FALL_ENABLE,
    /* 下降沿死区模块被旁路,上升沿死区模块使能 */
    EPWM_DEAD_OUT_RAISE_ENABLE_FALL_PASS,
    /* 上升/下降沿死区模块都使能 */
    EPWM_DEAD_OUT_RAISE_ENABLE_FALL_ENABLE,
} Epwm_DeadOutput_t;
#define CHECK_EPWM_DEAD_OUTPUT_EVENT(EVENT) (!(EVENT >> 2U))

/** EPWM 死区输出极性 */
typedef enum
{
    /* 波形发生模块的A,B路输出都不翻转 */
    EPWM_DEAD_A_NONE_B_NONE,
    /* 波形发生模块的A路翻转,B路输出不翻转 */
    EPWM_DEAD_A_TOGGLE_B_NONE,
    /* 波形发生模块的A路不翻转,B路输出翻转 */
    EPWM_DEAD_A_NONE_B_TOGGLE,
    /* 波形发生模块的A,B路输出都翻转 */
    EPWM_DEAD_A_TOGGLE_B_TOGGLE,
} Epwm_DeadPolarity_t;
#define CHECK_EPWM_DEAD_POLAR(SEL) (!(SEL >> 2U))

/* EPWM 死区输入 */
typedef enum
{
    /* 波形发生模块的A路输出作为上升沿,下降沿的输入 */
    EPWM_DEAD_IN_A_RAISE_A_FALL,
    /* 波形发生模块的B路输出作为上升沿输入,A路输出作为下降沿输入 */
    EPWM_DEAD_IN_B_RAISE_A_FALL,
    /* 波形发生模块的A路输出作为上升沿输入,B路输出作为下降沿输入 */
    EPWM_DEAD_IN_A_RAISE_B_FALL,
    /* 波形发生模块的B路输出作为上升沿,下降沿的输入 */
    EPWM_DEAD_IN_B_RAISE_B_FALL,
} Epwm_DeadInput_t;
#define CHECK_EPWM_DEAD_INPUT(INPUT) (!(INPUT >> 2U))

/* EPWM 滤波时钟分频 */
typedef enum
{
    /* 1个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_1,
    /* 2个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_2,
    /* 3个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_3,
    /* 4个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_4,
    /* 5个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_5,
    /* 6个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_6,
    /* 7个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_7,
    /* 8个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_8,
    /* 9个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_9,
    /* 10个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_10,
    /* 11个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_11,
    /* 12个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_12,
    /* 13个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_13,
    /* 14个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_14,
    /* 15个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_15,
    /* 16个斩波时钟周期*/
    EPWM_CHOPPER_WIDTH_FIRST_16,
} Epwm_ChopperWidthFirst_t;
#define CHECK_EPWM_CHOPPER_WIDTH_FIRST(PRESCALE) (!(PRESCALE >> 4U))

/* EPWM PCLK占空比 */
typedef enum
{
    /* 7/8占空比*/
    EPWM_PCLK_DUTY_7_DIV_8,
    /* 6/8占空比*/
    EPWM_PCLK_DUTY_6_DIV_8,
    /* 5/8占空比*/
    EPWM_PCLK_DUTY_5_DIV_8,
    /* 4/8占空比*/
    EPWM_PCLK_DUTY_4_DIV_8,
    /* 3/8占空比*/
    EPWM_PCLK_DUTY_3_DIV_8,
    /* 2/8占空比*/
    EPWM_PCLK_DUTY_2_DIV_8,
    /* 1/8占空比*/
    EPWM_PCLK_DUTY_1_DIV_8,
} Epwm_ChopperPclkDuty_t;
#define CHECK_EPWM_CHOPPER_PCLK_DUTY(DUTY) ((uint32_t)DUTY <= EPWM_PCLK_DUTY_1_DIV_8)

typedef enum
{
    /* 1:1 分频*/
    EPWM_CHOPPER_PCLK_PRESCALE_1,
    /* 1:2 分频*/
    EPWM_CHOPPER_PCLK_PRESCALE_2,
    /* 1:3 分频*/
    EPWM_CHOPPER_PCLK_PRESCALE_3,
    /* 1:4 分频*/
    EPWM_CHOPPER_PCLK_PRESCALE_4,
    /* 1:5 分频*/
    EPWM_CHOPPER_PCLK_PRESCALE_5,
    /* 1:6 分频*/
    EPWM_CHOPPER_PCLK_PRESCALE_6,
    /* 1:7 分频*/
    EPWM_CHOPPER_PCLK_PRESCALE_7,
    /* 1:8 分频*/
    EPWM_CHOPPER_PCLK_PRESCALE_8,
} Epwm_ChopperPclkPrescale_t;
#define CHECK_EPWM_CHOPPER_PCLK_PRESCALE(PRESCALE) (!(PRESCALE >> 3U))

/* EPWM自动关断输出电平 */
typedef enum
{
    /* 关断时,输出为低电平 */
    EPWM_SHUTDOWN_LEVEL_LOW = 0x0U,
    /* 关断时,输出为高电平 */
    EPWM_SHUTDOWN_LEVEL_HIGH = 0x1U,
    /* 关断时,输出为高阻态 */
    EPWM_SHUTDOWN_LEVEL_HI_Z = 0x3U,
} Epwm_ShutdownLevel_t;
#define CHECK_EPWM_SHUTDOWN_LEVEL(LEVEL) (!(LEVEL >> 2))

/* EPWM自动关断源 */
typedef enum
{
    /* TZ0 */
    EPWM_SHUTDOWN_SOURCE_TZ0,
    /* TZ1 */
    EPWM_SHUTDOWN_SOURCE_TZ1,
    /* TZ2 */
    EPWM_SHUTDOWN_SOURCE_TZ2,
    /* TZ3 */
    EPWM_SHUTDOWN_SOURCE_TZ3,
    /* TZ4 */
    EPWM_SHUTDOWN_SOURCE_TZ4,
    /* TZ5 */
    EPWM_SHUTDOWN_SOURCE_TZ5,
    /* TZ6 */
    EPWM_SHUTDOWN_SOURCE_TZ6,
    /* TZ6 */
    EPWM_SHUTDOWN_SOURCE_TZ7,
    /* TZ8*/
    EPWM_SHUTDOWN_SOURCE_TZ8,
    /* TZ9 */
    EPWM_SHUTDOWN_SOURCE_TZ9,
    /* TZ10 */
    EPWM_SHUTDOWN_SOURCE_TZ10,
    /* TZ11 */
    EPWM_SHUTDOWN_SOURCE_TZ11,
    /* TZ12 */
    EPWM_SHUTDOWN_SOURCE_TZ12,
    /* TZ13 */
    EPWM_SHUTDOWN_SOURCE_TZ13,
    /* TZ14 */
    EPWM_SHUTDOWN_SOURCE_TZ14,
    /* TZ15 */
    EPWM_SHUTDOWN_SOURCE_TZ15,
} Epwm_ShutdownSource_t;
#define CHECK_EPWM_SHUTDOWN_SOURCE(SOURCE) (!(SOURCE >> 2))

/* TZy 关断信号使能控制 */
typedef enum
{
    /* 使能 TZy 关断，高电平有效 */
    EPWM_TZ_SHUTDOWN_HIGH_ACTIVE = 0x1U,
    /* 使能 TZy 关断，低电平有效 */
    EPWM_TZ_SHUTDOWN_LOW_ACTIVE = 0x2U,
    /* 禁止 TZy 关断控制 */
    EPWM_TZ_SHUTDOWN_DISABLE = 0x3U,
} Epwm_TzShutdownMode_t;
#define CHECK_EPWM_TZ_SHUTDOWN_MODE(MODE) (!(MODE >> 2))

/* 高精度延迟边沿类型 */
typedef enum
{
    /* 通道A下降沿 */
    EPWM_CHA_FALL,
    /* 通道A上升沿 */
    EPWM_CHA_RAISE,
    /* 通道B下降沿 */
    EPWM_CHB_FALL,
    /* 通道B上升沿 */
    EPWM_CHB_RAISE,
} Epwm_HiResEdge_t;
#define CHECK_EPWM_HI_RES_EDGE(EDGE) (!(EDGE >> 2))

/* EPWM AD事件触发模式 */
typedef enum
{
    /* 在任意计数方向上都可触发AD */
    EPWM_EVENT_TRIGGER_BOTH = 0x0U,
    /* 在计数方向向上的时候触发AD */
    EPWM_EVENT_TRIGGER_COUNT_UP = 0x1U,
    /* 在计数方向向下的时候触发AD */
    EPWM_EVENT_TRIGGER_COUNT_DOWN = 0x3U,
} Epwm_EventTriggerMode_t;
#define CHECK_EPWM_EVENT_TRIGGER(SEL) ((uint32_t)(SEL) < (uint32_t)EPWM_EVENT_TRIGGER_COUNT_DOWN)

/* EPWM AD触发事件 */
typedef enum
{
    /* 定时器值等于零脉冲 */
    EPWM_EVENT_TX_EQU_ZERO,
    /* 定时器值等于 PP 脉冲 */
    EPWM_EVENT_TX_EQU_PPX,
    /* 定时器值等于占空比 A 寄存器脉冲 */
    EPWM_EVENT_TX_EQU_RA,
    /* 定时器值等于占空比 B 寄存器脉冲 */
    EPWM_EVENT_TX_EQU_RB,
    /* 定时器值等于占空比 C 寄存器脉冲 */
    EPWM_EVENT_TX_EQU_RC,
    /* 定时器值等于占空比 D 寄存器脉冲 */
    EPWM_EVENT_TX_EQU_RD,
    /* 同步输入信号 SYNCIN */
    EPWM_EVENT_SYNCI,
} Epwm_AdTriggerEvent_t;
/* 检查AD触发事件 */
#define CHECK_EPWM_AD_TRIGGER_EVENT(SEL) ((uint32_t)SEL <= (uint32_t)EPWM_EVENT_SYNCI)

/* 触发AD事件周期 */
typedef enum
{
    /* 每1次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_1,
    /* 每2次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_2,
    /* 每3次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_3,
    /* 每4次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_4,
    /* 每5次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_5,
    /* 每6次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_6,
    /* 每7次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_7,
    /* 每8次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_8,
    /* 每9次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_9,
    /* 每10次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_10,
    /* 每11次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_11,
    /* 每12次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_12,
    /* 每13次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_13,
    /* 每14次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_14,
    /* 每15次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_15,
    /* 每16次触发信号产生触发 AD 事件 */
    EPWM_RIGGER_AD_EVENT_PERIOD_16,
} Epwm_TriggerADEventPeriod_t;
#define CHECK_EPWM_TRIGGER_AD_EVENT_PERIOD(PERIOD) (!(PERIOD >> 4U))

/* 影子寄存器 */
typedef enum
{
    /* RA的影子寄存器*/
    EPWM_SHADOW_REG_RA,
    /* RB的影子寄存器*/
    EPWM_SHADOW_REG_RB,
    /* RC的影子寄存器*/
    EPWM_SHADOW_REG_RC,
    /* RD的影子寄存器*/
    EPWM_SHADOW_REG_RD,
    /* PPX的影子寄存器*/
    EPWM_SHADOW_REG_PPX,
    /* PRSC的影子寄存器*/
    EPWM_SHADOW_REG_PRSC,
    /* CTLA的影子寄存器*/
    EPWM_SHADOW_REG_ACTL,
    /* CTLB的影子寄存器*/
    EPWM_SHADOW_REG_BCTL,
    /* HRRA的影子寄存器*/
    EPWM_SHADOW_REG_HRRA,
    /* HRRB的影子寄存器*/
    EPWM_SHADOW_REG_HRRB,
    /* DBT的影子寄存器*/
    EPWM_SHADOW_REG_DBT,
    /* HRDB的影子寄存器*/
    EPWM_SHADOW_REG_HRDB,
    /* HRPHS的影子寄存器*/
    EPWM_SHADOW_REG_HRPHS,
    /* HRCFG的影子寄存器*/
    EPWM_SHADOW_REG_HRCFG,
    /* CAP的影子寄存器*/
    EPWM_SHADOW_REG_CAP,
} Epwm_ShadowReg_t;
/* 检查影子寄存器*/
#define CHECK_EPWM_SHADOW_REG(REG) ((uint32_t)(REG) <= (uint32_t)EPWM_SHADOW_REG_CAP)

/* EPWM 中断,DMA触发事件 */
typedef enum
{
    /* 定时器溢出 */
    EPWM_INDEX_OVERFLOW_EVENT,
    /* 更新事件 */
    EPWM_INDEX_UPDATE_EVENT,
    /* 关断事件 */
    EPWM_INDEX_SHUTDOWN_EVENT,
    /* 定时器计数等于RA事件 */
    EPWM_INDEX_TX_EQU_RA_EVENT,
    /* 定时器计数等于RB事件 */
    EPWM_INDEX_TX_EQU_RB_EVENT,
    /* 定时器计数等于RC事件 */
    EPWM_INDEX_TX_EQU_RC_EVENT,
    /* 定时器计数等于RD事件 */
    EPWM_INDEX_TX_EQU_RD_EVENT,
    /* 捕捉事件 */
    EPWM_CAPTURE_EVENT,
    /* 定时器触发 AD 事件0 */
    EPWM_AD_TRIGGER_EVENT_ZERO,
    /* 定时器触发 AD 事件1 */
    EPWM_AD_TRIGGER_EVENT_ONE,
} Epwm_InterruptIndex_t;
/* 检查中断事件*/
#define CHECK_EPWM_INTERRUPT(INDEX) ((uint32_t)(INDEX) <= (uint32_t)EPWM_AD_TRIGGER_EVENT_ONE)

/* EPWM 清除中断标志索引*/
typedef enum
{
    /* 定时器溢出 */
    EPWM_INDEX_CLR_OVERFLOW_EVENT = 0U,
    /* 更新事件 */
    EPWM_INDEX_CLR_UPDATE_EVENT = 1U,
    /* 关断事件 */
    EPWM_INDEX_CLR_SHUTDOWN_EVENT = 2U,
    /* 定时器计数等于RA事件 */
    EPWM_INDEX_CLR_TX_EQU_RA_EVENT = 3U,
    /* 定时器计数等于RB事件 */
    EPWM_INDEX_CLR_TX_EQU_RB_EVENT = 4U,
    /* 定时器计数等于RC事件 */
    EPWM_INDEX_CLR_TX_EQU_RC_EVENT = 5U,
    /* 定时器计数等于RD事件 */
    EPWM_INDEX_CLR_TX_EQU_RD_EVENT = 6U,

    /* 定时器触发 AD 事件0 */
    EPWM_CLR_AD_TRIGGER_EVENT_ZERO = 9U,
    /* 定时器触发 AD 事件1 */
    EPWM_CLR_AD_TRIGGER_EVENT_ONE = 10U,
} Epwm_InterruptClearIndex_t;
#define CHECK_EPWM_INTERRUPT_CLEAR(INDEX)                                                                              \
    (((uint32_t)(INDEX) <= (uint32_t)EPWM_INDEX_CLR_TX_EQU_RD_EVENT) || (INDEX == EPWM_CLR_AD_TRIGGER_EVENT_ZERO) ||   \
     (INDEX == EPWM_CLR_AD_TRIGGER_EVENT_ONE))

/* 捕获事件清除模式*/
typedef enum
{
    EPWM_CAP_CLEAR_MODE_NONE,
    EPWM_CAP_CLEAR_MODE_EQU_ZERO,
    EPWM_CAP_CLEAR_MODE_EQU_PERIOD,
    EPWM_CAP_CLEAR_MODE_SOFT,
} Epwm_CapClearMode_t;
/**检查捕获清除模式*/
#define CHECK_CAP_CLEAR_MODE(MODE) (!(MODE >> 2U))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief Epwm模块使能/禁止
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Status 使能/禁止状态
 *                false  Epwm 使能
 *                true   Epwm 禁止
 * @retval void
 */
KF_INLINE void Epwm_LL_SetModuleDisabled(Epwm_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CLKC.bits.DISR, Status);
}

/**
 * @brief Epwm获取模块禁止状态
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval bool
 *        false Epwm模块已使能
 *        true Epwm模块已禁止
 */
KF_INLINE bool Epwm_LL_GetModuleStatus(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return REG_READ(Module->EPWM_CLKC.bits.DISS);
}

/**
 * @brief Epwm设置休眠模式
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Status:
 *                false   Epwm 进入休眠模式
 *                true   Epwm 关闭休眠模式
 * @retval void
 */
KF_INLINE void Epwm_LL_SetSleepModeDisabled(Epwm_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CLKC.bits.EDIS, Status);
}

/*  EPWM_INFO_T */

/**
 * @brief Epwm获取模块版本号
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param void
 * @retval uint32_t 模块版本号
 */
KF_INLINE uint32_t Epwm_LL_GetModuleVersion(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return REG_READ(Module->EPWM_INFO.bits.MODREV);
}

/**
 * @brief Epwm获取模块类型
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param void
 * @retval uint32_t 模块类型
 */
KF_INLINE uint32_t Epwm_LL_GetModuleType(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return REG_READ(Module->EPWM_INFO.bits.MODTYPE);
}

/**
 * @brief Epwm获取模块编号
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param void
 * @retval uint32_t 模块编号
 */
KF_INLINE uint32_t Epwm_LL_GetModuleNumber(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return REG_READ(Module->EPWM_INFO.bits.MODNUM);
}

/*  EPWM_DBG_T */

/**
 * @brief Epwm返回模块挂起状态
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param void
 * @retval bool
 *              false Epwm模块未挂起
 *              false Epwm模块挂起
 */
KF_INLINE bool Epwm_LL_IsModuleSuspended(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return (bool)REG_READ(Module->EPWM_DBG.bits.SUSEPWMA);
}

/**
 * @brief Epwm模块设置挂起
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param SuspendMode Epwm模块挂起模式
 *                EPWM_SUSPEND_MODE_NONE 不挂起
 *                EPWM_SUSPEND_MODE_STOP 64位计数器停止
 * @retval void
 */
KF_INLINE void Epwm_LL_SetSuspendMode(Epwm_RegisterMap_t *const Module, const Epwm_SuspendMode_t SuspendMode)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_SUSPEND_MODE(SuspendMode));
    EPWM_DBG_T regValue = {0U};

    regValue.reg       = REG_READ(Module->EPWM_DBG.reg);
    regValue.bits.SUSP = true;
    regValue.bits.SUS  = SuspendMode;
    REG_WRITE(Module->EPWM_DBG.reg, regValue.reg);
}

/*  EPWM_RST0_T */
/*  EPWM_RST1_T */

/**
 * @brief 复位Epwm模块
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_ResetModule(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_RST0.bits.RST, 1U);
    REG_WRITE(Module->EPWM_RST1.bits.RST, 1U);
}

/*  EPWM_RSTCLR_T */

/**
 * @brief 清除Epwm模块复位状态
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_ClearResetStatus(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_RSTCLR.bits.CLR, 1U);
}

/**
 * @brief 获取Epwm模块复位状态
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval bool
 *              false 模块没有复位
 *              true 模块已复位
 */
KF_INLINE bool Epwm_LL_GetResetStatus(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return (bool)REG_READ(Module->EPWM_RST0.bits.RSTSTA);
}

/*  EPWM_ACES0_T */

/**
 * @brief 设置EPWM模块Master TAG ID访问权限
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Id Master TAG ID
 * @param Status bool
 *        false 写访问没有执行
 *        true 写访问执行
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetAccessEnabled(Epwm_RegisterMap_t *const Module, const Epwm_MasterTAGId_t Id, const bool Status)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_MASTER_TAG_ID(Id));
    REG_BITS_WRITE(Module->EPWM_ACES0.reg, (1U << Id), ((uint32_t)Status << Id));
}

/*  EPWM_CTL0_T */

/**
 * @brief EPWM模块使能 /禁止
 *
 *
 * @param Module 指向EPWM内存结构的指针
 * @param Status bool
 *                false 禁止定时器，暂停计数
 *                true 使能定时器，启动计数
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTimerEnabled(Epwm_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    /* TODO: 位域名与手册不一致 */
    REG_WRITE(Module->EPWM_CTL0.bits.EN, Status);
}

/**
 * @brief 设置EPWM定时器工作模式
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Mode 定时器工作模式
 *                EPWM_TIMING_MODE 定时模式
 *                EPWM_COUNT_MODE 计数模式，时钟为引脚 EXCLK 输入
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTimerWorkMode(Epwm_RegisterMap_t *const Module, const Epwm_TimerWorkMode_t Mode)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_TIMER_WORK_MODE(Mode));
    Module->EPWM_CTL0.bits.CS = (uint32_t)Mode;
}

/**
 * @brief EPWM模块门控使能
 *
 * @param Module 指向EPWM内存结构的指针
 * @param EnableStatus 门控使能状态
 *                false 禁止门控模式
 *                true  使能门控模式，门控信号为 EXCLK 引脚
 * @retval void
 */
KF_INLINE void Epwm_LL_SetGatingEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL0.bits.GATEEN, EnableStatus);
}

/**
 * @brief 计数模式下外部触发脉冲输入同步控制
 * @attention 仅计数模式有效
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 同步使能状态
 *                  false 不使能 外部触发脉冲作为计数时钟
 *                  true  使能 外部触发脉冲与工作时钟同步后作为计数时钟
 * @retval void
 */
KF_INLINE void Epwm_LL_SetExternalPulseSyncEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL0.bits.TXSY, EnableStatus);
}

/**
 * @brief 选择EPWM时钟源
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param WorkClock EPWM时钟源
 *                EPWM_CLOCK_SOURCE_F_SPB  时钟源 f_SPB
 *                EPWM_CLOCK_SOURCE_F_TMR  时钟源 f_TMR
 * @retval void
 */
KF_INLINE void Epwm_LL_SelectClockSource(Epwm_RegisterMap_t *const Module, const Epwm_ClockSource_t ClockSource)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_CLOCK_SOURCE_MODE(ClockSource));
    Module->EPWM_CTL0.bits.CLKSEL = (uint32_t)ClockSource;
}

/**
 * @brief EPWM模块设置计数方式
 *
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Manner 计数方式选择
 *                EPWM_COUNTING_MANNER_UP_UP_FLAG 向上计数，上溢产生中断标志
 *                EPWM_COUNTING_MANNER_DOWN_DOWN_FLAG 向下计数，下溢产生中断标志
 *                EPWM_COUNTING_MANNER_UP_DOWN_UP_FLAG 向上向下计数，上溢产生中断标志
 *                EPWM_COUNTING_MANNER_UP_DOWN_DOWN_FLAG 向上向下计数，下溢产生中断标志
 *                EPWM_COUNTING_MANNER_UP_DOWN_BOTH_FLAG 向上向下计数，上溢和下溢均产生中断标志
 * @retval void
 */
KF_INLINE void Epwm_LL_SetCounterManner(Epwm_RegisterMap_t *const Module, const Epwm_CountingManner_t Manner)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_COUNTING_MANNER(Manner));
    REG_WRITE(Module->EPWM_CTL0.bits.CMS, Manner);
}

/**
 * @brief EPWM模块使能/禁止相位重载
 *
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 相位重载使能
 * @retval void
 */
KF_INLINE void Epwm_LL_SetPhaseReloadEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL0.bits.PHSEN, EnableStatus);
}

/**
 * @brief EPWM模块选择输出同步事件类型
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param SelectedEvent 选择需要输出的同步事件类型
 *                  EPWM_DISABLE_SYNCO
 *                  EPWM_TX_COUNT_EQU_ZERO
 *                  EPWM_TX_COUNT_EQU_RB
 *                  EPWM_SYNCI_AND_SWFSYNC
 * @retval void
 */
KF_INLINE void Epwm_LL_SelectSyncOutputEvent(Epwm_RegisterMap_t *const Module, const Epwm_SyncEvent_t SelectedEvent)
{
    /* PRQA S 3397,3400 2 */ /* Extra parentheses recommended */
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_SYNC_EVENT(SelectedEvent));

    Module->EPWM_CTL0.bits.SYNCOSEL = (uint32_t)SelectedEvent;
}

/**
 * @brief  软件产生触发同步事件
 * @attention 该位由硬件自动清零
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_GenerateSoftwareSyncEvent(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL0.bits.SWFSYNC, true);
}

/**
 * @brief EPWM模块设置同步事件发生后的计数方向
 * @attention 仅在在向上向下计数模式下有效
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Direction 计数方向
 *                EPWM_PHASE_RELOAD_COUNT_UP  同步事件触发后向上计数
 *                EPWM_PHASE_RELOAD_COUNT_DOWN 同步事件触发后向下计数
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetPhaseReloadDirection(Epwm_RegisterMap_t *const Module, const Epwm_PhaseReloadDirection_t Direction)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_PHASE_RELOAD_DIRECTION(Direction));
    REG_WRITE(Module->EPWM_CTL0.bits.PHSDIR, Direction);
}

/**
 * @brief EPWM模块通道输出 AQ 波形发生控制子模块寄存器锁
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param EnableStatus
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetAQRegisterLockEnabled(Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    if (Output == EPWM_OUTPUT_A)
    {
        REG_WRITE(Module->EPWM_CTL0.bits.AQLOCKA, EnableStatus);
    }
    else
    {
        REG_WRITE(Module->EPWM_CTL0.bits.AQLOCKB, EnableStatus);
    }
}

/**
 * @brief EPWM设置DB 死区控制子模块寄存器锁
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DisableStatus 禁止状态
 *                false 允许 DB 子模块寄存器写操作
 *                true 禁止 DB 子模块寄存器写操作
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDBRegisterWriteDisabled(Epwm_RegisterMap_t *const Module, const bool DisableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL0.bits.DBLOCK, DisableStatus);
}

/**
 * @brief EPWM设置PC斩波控制子模块寄存器锁
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DisableStatus 禁止状态
 *                false 允许 PC 子模块寄存器写操作
 *                true 禁止 PC 子模块寄存器写操作
 * @retval void
 */
KF_INLINE void Epwm_LL_SetPCRegisterWriteDisabled(Epwm_RegisterMap_t *const Module, const bool DisableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL0.bits.PCLOCK, DisableStatus);
}

/**
 * @brief EPWM设置ET事件管理子模块寄存器锁
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DisableStatus 禁止状态
 *                false 允许 ET 子模块寄存器写操作
 *                true 禁止 ET 子模块寄存器写操作
 * @retval void
 */
KF_INLINE void Epwm_LL_SetETRegisterWriteDisabled(Epwm_RegisterMap_t *const Module, const bool DisableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL0.bits.ETLOCK, DisableStatus);
}

/**
 * @brief EPWM设置HRPWM 高精度 PWM 子模块寄存器锁
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DisableStatus 禁止状态
 *                false 允许 HRPWM 子模块寄存器写操作
 *                true 禁止 HRPWM 子模块寄存器写操作
 * @retval void
 */
KF_INLINE void Epwm_LL_SetHRRegisterWriteDisabled(Epwm_RegisterMap_t *const Module, const bool DisableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL0.bits.HRLOCK, DisableStatus);
}

/**
 * @brief 配置同步信号触发更新使能
 *
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 禁止同步输入信号触发更新
 *                true 允许同步输入信号触发更新
 * @retval void
 */
KF_INLINE void Epwm_LL_SetSyncSignalTriggerUpdate(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL0.bits.UDSYNEN, EnableStatus);
}

/**
 * @brief 设置EPWM模块响应上一级 EPWM 发送的 LINK 请求
 * @note 使能后，可被上一级 EPWM 写信号控制寄存器写操作
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 禁止寄存器使用 LINK 功能
 *                true 允许寄存器使用 LINK 功能
 * @retval void
 */
KF_INLINE void Epwm_LL_SetLinkToUpperLevel(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL0.bits.BLINKEN, EnableStatus);
}

/* EPWM_CTL1_T */

/**
 * @brief 软件清零 CAPIF
 * @attention  该操作仅在CAPIC<1:0>=11 时有效
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_ClearCaptureFlagSoftware(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_CTL1.bits.SWCLRPF, true);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_WRITE(Module->EPWM_CTL1.bits.SWCLRPF, false);
}

/**
 * @brief 设置EPWM模块消隐窗口使能
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 禁止消隐窗口
 *                true 使能消隐窗口
 * @retval void
 */
KF_INLINE void Epwm_LL_SetBlankWindowEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_CTL1.bits.BWINDEN, EnableStatus);
}

/**
 * @brief EPWM模块选择消隐窗口极性
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Polarity 极性
 *                EPWM_BLANK_WINDOW_POLARITY_HIGH 高电平有效
 *                EPWM_BLANK_WINDOW_POLARITY_LOW 低电平有效
 * @retval void
 */
KF_INLINE void
Epwm_LL_SelectBlankWindowPolarity(Epwm_RegisterMap_t *const Module, const Epwm_BlankWindowPolarity_t Polarity)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_BLANK_WINDOW_POLARITY(Polarity));
    REG_WRITE(Module->EPWM_CTL1.bits.BWINDPOL, Polarity);
}

/**
 * @brief EPWM模块选择消隐窗口偏置参考点
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Reference 偏置参考点
 *
 * @retval void
 */
KF_INLINE void
Epwm_LL_SelectBlankWindowReference(Epwm_RegisterMap_t *const Module, const Epwm_BlankWindowRef_t Reference)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_BLANK_WINDOW_REF(Reference));
    REG_WRITE(Module->EPWM_CTL1.bits.BWINDTSEL, Reference);
}

/**
 * @brief EPWM模块使能双边死区模式
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 不使能双边死区模式
 *                true 使能双边死区模式
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDoubleDeadZoneEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL1.bits.DUDBEN, EnableStatus);
}

/**
 * @brief EPWM模块选择死区模式
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Edge 死区边沿
 *                EPWM_DEAD_ZONE_EDGE_RAISE 优先上升沿死区
 *                EPWM_DEAD_ZONE_EDGE_FALL 优先下降沿死区
 * @retval void
 */
KF_INLINE void Epwm_LL_SelectDoubleDeadZoneEdge(Epwm_RegisterMap_t *const Module, const Epwm_DeadZoneEdge_t Edge)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_DEAD_ZONE_EDGE(Module));
    REG_WRITE(Module->EPWM_CTL1.bits.DUDBSEL, Edge);
}

/**
 * @brief EPWM模块使能同步模式
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 同步输入选择连续模式
 *                true 同步输入选择单次模式
 * @retval void
 */
KF_INLINE void Epwm_LL_SetSyncInputMode(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_CTL1.bits.SYNCIOS, EnableStatus);
}

/**
 * @brief EPWM模块选择触发信号模式
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 模式选择
 *                false 触发信号选择连续模式
 *                true 触发信号选择单次模式
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTriggerSingleModeEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL1.bits.TRGIOS, EnableStatus);
}

/**
 * @brief EPWM模块设置同步输入信号滤波使能/禁止
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 模式选择
 *                false 禁止同步输入信号输入滤波
 *                true 使能同步输入信号输入滤波
 * @retval void
 */
KF_INLINE void Epwm_LL_SetSyncFilterEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL1.bits.SYNCFEN, EnableStatus);
}

/**
 * @brief EPWM模块设置同步输入信号滤波分频
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Prescale 分频
 *                EPWM_SYNC_FILTER_PRESCALE_1 1:1分频
 *                EPWM_SYNC_FILTER_PRESCALE_2 1:2分频
 *                EPWM_SYNC_FILTER_PRESCALE_3 1:3分频
 *                EPWM_SYNC_FILTER_PRESCALE_4 1:4分频
 *                EPWM_SYNC_FILTER_PRESCALE_5 1:5分频
 *                EPWM_SYNC_FILTER_PRESCALE_6 1:6分频
 *                EPWM_SYNC_FILTER_PRESCALE_7 1:7分频
 *                EPWM_SYNC_FILTER_PRESCALE_8 1:8分频
 *                EPWM_SYNC_FILTER_PRESCALE_9 1:9分频
 *                EPWM_SYNC_FILTER_PRESCALE_10 1:10分频
 *                EPWM_SYNC_FILTER_PRESCALE_11 1:11分频
 *                EPWM_SYNC_FILTER_PRESCALE_12 1:12分频
 *                EPWM_SYNC_FILTER_PRESCALE_13 1:13分频
 *                EPWM_SYNC_FILTER_PRESCALE_14 1:14分频
 *                EPWM_SYNC_FILTER_PRESCALE_15 1:15分频
 *                EPWM_SYNC_FILTER_PRESCALE_16 1:16分频
 * @retval void
 */
KF_INLINE void Epwm_LL_SetSyncFilterPrescale(Epwm_RegisterMap_t *const Module, Epwm_SyncFilterPrescale_t Prescale)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_SYNC_FILTER_PRESCALE(Prescale));
    REG_WRITE(Module->EPWM_CTL1.bits.SYFDIV, Prescale);
}

/**
 * @brief EPWM模块设置同步输入信号滤波延时
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Delay 滤波延时
 *                EPWM_SYNC_FILTER_DELAY_1 延时1个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_2 延时2个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_3 延时3个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_4 延时4个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_5 延时5个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_6 延时6个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_7 延时7个滤波时钟
 * @retval void
 */
KF_INLINE void Epwm_LL_SetSyncFilterDelay(Epwm_RegisterMap_t *const Module, Epwm_SyncFilterDelay_t Delay)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_SYNC_FILTER_DELAY(Delay));
    REG_WRITE(Module->EPWM_CTL1.bits.SYDELAY, Delay);
}

/**
 * @brief EPWM模块使能/禁止外部时钟引脚输入滤波
 *
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 外部时钟输入滤波使能
 *                false 禁止外部时钟引脚输入滤波
 *                true 使能外部时钟引脚输入滤波
 * @retval void
 */
KF_INLINE void Epwm_LL_SetExternClockFilterEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CTL1.bits.CKFEN, EnableStatus);
}

/**
 * @brief EPWM模块设置外部时钟输入滤波分频
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Prescale 分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_1 1:1分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_2 1:2分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_3 1:3分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_4 1:4分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_5 1:5分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_6 1:6分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_7 1:7分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_8 1:8分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_9 1:9分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_10 1:10分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_11 1:11分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_12 1:12分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_13 1:13分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_14 1:14分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_15 1:15分频
 *                EPWM_EXTERN_CLOCK_FILTER_PRESCALE_16 1:16分频
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetExternClockFilterPrescale(Epwm_RegisterMap_t *const Module, Epwm_ExternClockFilterPrescale_t Prescale)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EXTERN_CLOCK_FILTER_PRESCALE(Prescale));
    REG_WRITE(Module->EPWM_CTL1.bits.CKFDIV, Prescale);
}

/**
 * @brief EPWM模块设置同步输入信号滤波延时
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Delay 滤波延时
 *                EPWM_SYNC_FILTER_DELAY_1 延时1个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_2 延时2个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_3 延时3个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_4 延时4个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_5 延时5个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_6 延时6个滤波时钟
 *                EPWM_SYNC_FILTER_DELAY_7 延时7个滤波时钟
 * @retval void
 */
KF_INLINE void Epwm_LL_SetExternClockFilterDelay(Epwm_RegisterMap_t *const Module, Epwm_ExternClockFilterDelay_t Delay)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EXTERN_CLOCK_FILTER_DELAY(Delay));
    REG_WRITE(Module->EPWM_CTL1.bits.CKDELAY, Delay);
}

/**
 * @brief EPWM模块选择捕捉模式
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Mode 捕捉模式
 *                EPWM_CAPIF_NO_EFFECT_ON_CAP_EVENT CAPIF 不影响捕捉事件的发生
 *                EPWM_DISABLE_CAP_EVENT_WHEN_CAPIF_SET 在 CAPIF 置 1 期间禁止捕捉事件的发生

 * @retval void
 */
KF_INLINE void Epwm_LL_SelectCaptureMode(Epwm_RegisterMap_t *const Module, const Epwm_CaptureMode_t Mode)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CAPCTL.bits.CAPMOD, Mode);
}

/**
 * @brief EPWM模块设置触发事件使能/禁止相位重载
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus
 *                false 禁止触发事件产生相位重载
 *                true 使能触发事件产生相位重载
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTrigEventEnablePhaseReload(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_CTL1.bits.LPHSEN, EnableStatus);
}

/**
 * @brief 设置EPWM模块正常输出电平
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param Level 正常输出电平
 *                EPWM_OUTPUT_LEVEL_NONE 不触发该事件
 *                EPWM_OUTPUT_LEVEL_LOW 输出低电平
 *                EPWM_OUTPUT_LEVEL_HIGH 输出高电平
 *                EPWM_OUTPUT_LEVEL_TOGGLE 翻转电平
 * @param Event 输出事件
 *                EPWM_OUTPUT_TX_EQU_ZERO CNT计数值等于0
 *                EPWM_OUTPUT_TX_EQU_PERIOD CNT计数值等于PPX
 *                EPWM_OUTPUT_TX_EQU_RA_COUNT_UP CNT计数值等于RA,且计数方向向上
 *                EPWM_OUTPUT_TX_EQU_RA_COUNT_DOWN CNT计数值等于RA,且计数方向向下
 *                EPWM_OUTPUT_TX_EQU_RB_COUNT_UP CNT计数值等于RB,且计数方向向上
 *                EPWM_OUTPUT_TX_EQU_RB_COUNT_DOWN CNT计数值等于RB,且计数方向向下
 * @retval void
 */
KF_INLINE void Epwm_LL_SetOutput(Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output,
                                 const Epwm_OutputLevel_t Level, const Epwm_OutputEvent_t Event)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT_LEVEL(Level));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT_EVENT(Event));

    REG_BITS_WRITE(
      (&(Module->EPWM_ACTL.reg))[Output], 0x3U << ((uint32_t)Event << 1U), (uint32_t)Level << ((uint32_t)Event << 1U));
}

/**
 * @brief 设置 EPWM 单次强制输出电平
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param Level 单次强制输出电平
 *                EPWM_OUTPUT_LEVEL_NONE 无动作
 *                EPWM_OUTPUT_LEVEL_LOW 输出低电平
 *                EPWM_OUTPUT_LEVEL_HIGH 输出高电平
 *                EPWM_OUTPUT_LEVEL_TOGGLE 翻转电平
 * @retval void
 */
KF_INLINE void Epwm_LL_SetForceOutputSingle(
  Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const Epwm_OutputLevel_t Level)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT_LEVEL(Level));
    if (EPWM_OUTPUT_A == Output)
    {
        REG_WRITE(Module->EPWM_ACTL.bits.ACTSFA, Level);
    }
    else
    {
        REG_WRITE(Module->EPWM_BCTL.bits.ACTSFB, Level);
    }
}

/**
 * @brief 设置 EPWM 连续强制输出电平
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param Level 单次强制输出电平
 *                EPWM_FORCE_OUTPUT_LEVEL_NONE 无动作
 *                EPWM_FORCE_OUTPUT_LEVEL_LOW 输出低电平
 *                EPWM_FORCE_OUTPUT_LEVEL_HIGH 输出高电平
 *                EPWM_FORCE_OUTPUT_LEVEL_FORBIDDEN 禁止连续输出
 * @retval void
 */
KF_INLINE void Epwm_LL_SetForceOutputContinuous(
  Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const Epwm_ForceConOutputLevel_t Level)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_FORCE_CONTINUOUS_OUTPUT_LEVEL(Level));

    if (EPWM_OUTPUT_A == Output)
    {
        REG_WRITE(Module->EPWM_ACTL.bits.CSFA, Level);
    }
    else if (EPWM_OUTPUT_B == Output)
    {
        REG_WRITE(Module->EPWM_BCTL.bits.CSFB, Level);
    }
    else
    {
    }
}

/**
 * @brief 设置 EPWM 单次强制输出使能状态
 * @attention 写一后,产生一个计数周期的脉冲,然后该位硬件自动清零,且该位不需要等待更新信号
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param EnableStatus 使能状态
 *                false: 禁止通道单次强制输出
 *                true: 使能通道单次强制输出
 * @retval void
 */
KF_INLINE void Epwm_LL_SetForceOutputStatusSingle(
  Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const bool EnableStatus)
{
    /* PRQA S 3397,3400 3 */ /* Extra parentheses recommended */
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));

    if (EPWM_OUTPUT_A == Output)
    {
        REG_WRITE(Module->EPWM_ACTL.bits.OTSFA, EnableStatus);
    }
    else
    {
        REG_WRITE(Module->EPWM_BCTL.bits.OTSFB, EnableStatus);
    }
}

/**
 * @brief 设置EPWM独立更新使能状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param UpdateReg 需要更新的寄存器
 *                EPWM_UPDATE_REG_PPX PPX周期寄存器
 *                EPWM_UPDATE_REG_PRSC PRSC预分频寄存器
 *                EPWM_UPDATE_REG_RA RA占空比寄存器
 *                EPWM_UPDATE_REG_RB RB占空比寄存器
 *                EPWM_UPDATE_REG_RC RC占空比寄存器
 *                EPWM_UPDATE_REG_RD RD占空比寄存器
 *                EPWM_UPDATE_REG_ACTL ACTL A路输出控制寄存器
 *                EPWM_UPDATE_REG_BCTL BCTL B路输出控制寄存器
 *                EPWM_UPDATE_REG_HRRA HRRA高精度占空比寄存器A
 *                EPWM_UPDATE_REG_HRRB HRRB高精度占空比寄存器B
 *                EPWM_UPDATE_REG_DB DB死区寄存器
 *                EPWM_UPDATE_REG_HRDB HRDB 高精度死区寄存器
 *                EPWM_UPDATE_REG_HRPHS HRPHS 高精度相位寄存器
 * @param EnableStatus 使能状态
 *                fasle 禁止更新
 *                true 使能更新
 * @retval void
 */
KF_INLINE void Epwm_LL_SetRegisterUpdateEnabled(
  Epwm_RegisterMap_t *const Module, const Epwm_UpdateReg_t UpdateReg, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_UPDATE_REG(UpdateReg));
    uint32_t Mask =
      (uint32_t)UpdateReg >= EPWM_UPDATE_REG_HRRA
        ? (((uint32_t)UpdateReg - EPWM_UPDATE_REG_HRRA) * 3U + 8U)
        : ((uint32_t)UpdateReg * 3U);
    REG_BITS_WRITE((&Module->EPWM_UDCTL0.reg)[((uint32_t)((uint32_t)UpdateReg >= EPWM_UPDATE_REG_HRRA) << 1U)],
                   (uint32_t)0x1U << Mask, (uint32_t)EnableStatus << Mask);
}

/**
 * @brief 设置EPWM独立更新事件
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param UpdateReg 需要更新的寄存器
 *                EPWM_UPDATE_REG_PPX PPX周期寄存器
 *                EPWM_UPDATE_REG_PRSC PRSC预分频寄存器
 *                EPWM_UPDATE_REG_RA RA占空比寄存器
 *                EPWM_UPDATE_REG_RB RB占空比寄存器
 *                EPWM_UPDATE_REG_RC RC占空比寄存器
 *                EPWM_UPDATE_REG_RD RD占空比寄存器
 *                EPWM_UPDATE_REG_ACTL ACTL A路输出控制寄存器
 *                EPWM_UPDATE_REG_BCTL BCTL B路输出控制寄存器
 *                EPWM_UPDATE_REG_HRRA HRRA高精度占空比寄存器A
 *                EPWM_UPDATE_REG_HRRB HRRB高精度占空比寄存器B
 *                EPWM_UPDATE_REG_DB DB死区寄存器
 *                EPWM_UPDATE_REG_HRDB HRDB 高精度死区寄存器
 *                EPWM_UPDATE_REG_HRPHS HRPHS 高精度相位寄存器
 *                EPWM_UPDATE_REG_HRCFG HRCFG 高精度配置寄存器
 * @param UpdateEvent 更新事件
 *                EPWM_UPDATE_EVENT_CNT_EQU_ZERO 计数器计数值等于0时更新
 *                EPWM_UPDATE_EVENT_CNT_EQU_PPX 计数器计数值等于PPX值时更新
 *                EPWM_UPDATE_EVENT_BOTH 计数器计数值等于0或者等于PPX值时更新
 *                EPWM_UPDATE_EVENT_SYNC 输入同步信号时更新
 * @retval void
 */
KF_INLINE void Epwm_LL_SetIndependentUpdateEvent(
  Epwm_RegisterMap_t *const Module, const Epwm_UpdateReg_t UpdateReg, const Epwm_UpdateEvent_t UpdateEvent)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_UPDATE_REG(UpdateReg));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_UPDATE_EVENT(UpdateEvent));
    uint32_t Mask =
      (uint32_t)UpdateReg >= EPWM_UPDATE_REG_HRRA
        ? (((uint32_t)UpdateReg - EPWM_UPDATE_REG_HRRA) * 3U + 9U)
        : ((uint32_t)UpdateReg * 3U + 1U);
    REG_BITS_WRITE((&Module->EPWM_UDCTL0.reg)[((uint32_t)((uint32_t)UpdateReg >= EPWM_UPDATE_REG_HRRA) << 1U)],
                   (uint32_t)0x3U << Mask, (uint32_t)UpdateEvent << Mask);
}

/**
 * @brief 设置EPWM全局更新使能
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 全局更新
 *                true 使能独立更新
 * @retval void
 */
KF_INLINE void Epwm_LL_SetIndependentUpdateEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_UDCTL0.bits.GBUDEN, EnableStatus);
}

/**
 * @brief EPWM产生更新事件
 * @details 初始化定时器的计数器并更新周期、占空比、预分频器、输出控制寄存器
 * @attention 该位自动清零，不受 UDEN 控制
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_GenerateUpdateEvent(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_UDCTL1.bits.UR, true);
}

/**
 * @brief 设置更新事件控制
 * @attention UDEN=1 时有效
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Mode
 *                EPWM_UPDATE_PERIODIC 周期更新
 *                EPWM_UPDATE_NOW 立即更新
 * @retval void
 */
KF_INLINE void Epwm_LL_SetUpdateEventMode(Epwm_RegisterMap_t *const Module, const Epwm_UpdateMode_t Mode)
{
    /* PRQA S 3397,3400 2 */ /* Extra parentheses recommended */
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_UPDATE_MODE(Mode));

    Module->EPWM_UDCTL1.bits.UDEVT = (uint32_t)Mode;
}

/**
 * @brief 设置更新使能
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 禁止占空比、周期、输出控制、预分频寄存器更新
 *                true 允许占空比、周期、输出控制、预分频寄存器更新
 * @retval void
 */
KF_INLINE void Epwm_LL_SetUpdateEventEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_UDCTL1.bits.UDEN, EnableStatus);
}

/**
 * @brief 设置EPWM全局更新事件,预分频系数
 * @details 每有 CLDPRCS<7:0>+1 次更新触发事件发生时,才会进行一次真正的寄存器更新
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Scaler 预分频系数
 *                  0x0 ~ 0xff
 * @retval void
 */
KF_INLINE void Epwm_LL_SetGlobalUpdateScaler(Epwm_RegisterMap_t *const Module, const uint8_t Scaler)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_UDCTL2.bits.CLDPRCS, Scaler);
}

/**
 * @brief 设置EPWM捕捉使能
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false  禁止捕捉功能
 *                true  使能捕捉功能
 * @retval void
 */
KF_INLINE void Epwm_LL_SetCaptureEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_CAPCTL.bits.CAPEN, EnableStatus);
}

/**
 * @brief EPWM模块选择捕捉事件
 * @details 信号 CAPS
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param CaptureEvent 捕捉事件
 *                false 选择捕捉专用引脚 CAP 进行捕捉
 *                true 选择 A 引脚进行捕捉
 * @retval void
 */
KF_INLINE void Epwm_LL_SelectCaptureEvent(Epwm_RegisterMap_t *const Module, const bool CaptureEvent)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_CAPCTL.bits.CAPSEL, CaptureEvent);
}

/**
 * @brief 设置EPWM捕捉输入引脚滤波使能
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false  禁止捕捉引脚输入滤波
 *                true  使能捕捉引脚输入滤波
 * @retval void
 */
KF_INLINE void Epwm_LL_SetCaptureFilterEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_CAPCTL.bits.CAPFEN, EnableStatus);
}

/**
 * @brief 设置EPWM捕捉引脚滤波时钟分频，滤波时钟为 fEPWM
 *
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Prescale
 *                EPWM_CAPTURE_FILTER_PRESCALE_1 1:1分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_2 1:2分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_3 1:3分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_4 1:4分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_5 1:5分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_6 1:6分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_7 1:7分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_8 1:8分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_9 1:9分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_10 1:10分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_11 1:11分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_12 1:12分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_13 1:13分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_14 1:14分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_15 1:15分频
 *                EPWM_CAPTURE_FILTER_PRESCALE_16 1:16分频
 * @retval void
 */
KF_INLINE void Epwm_LL_SetCaptureFilterPrescale(Epwm_RegisterMap_t *const Module, Epwm_CaptureFilterPrescale_t Prescale)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_CAPTURE_FILTER_PRESCALE(Prescale));
    REG_WRITE(Module->EPWM_CAPCTL.bits.CFDIV, Prescale);
}

/**
 * @brief 设置EPWM模块捕捉通道延时滤波
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Delay 滤波延时
 *                EPWM_CAPTURE_DELAY_1 延时1个滤波时钟
 *                EPWM_CAPTURE_DELAY_2 延时2个滤波时钟
 *                EPWM_CAPTURE_DELAY_3 延时3个滤波时钟
 *                EPWM_CAPTURE_DELAY_4 延时4个滤波时钟
 *                EPWM_CAPTURE_DELAY_5 延时5个滤波时钟
 *                EPWM_CAPTURE_DELAY_6 延时6个滤波时钟
 *                EPWM_CAPTURE_DELAY_7 延时7个滤波时钟
 * @retval void
 */
KF_INLINE void Epwm_LL_SetCaptureFilterDelay(Epwm_RegisterMap_t *const Module, Epwm_CaptureFilterDelay_t Delay)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_CAPTURE_FILTER_DELAY(Delay));
    REG_WRITE(Module->EPWM_CAPCTL.bits.CFDELAY, Delay);
}

/**
 * @brief EPWM选择死区模块输出模式
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DeadInput 死区模块输出模式
 *                  EPWM_DEAD_OUT_RAISE_PASS_FALL_PASS 上升/下降沿死区模块都被旁路
 *                  EPWM_DEAD_OUT_RAISE_PASS_FALL_ENABLE 上升沿死区模块被旁路,下降沿死区模块使能
 *                  EPWM_DEAD_OUT_RAISE_ENABLE_FALL_PASS 下降沿死区模块被旁路,上升沿死区模块使能
 *                  EPWM_DEAD_OUT_RAISE_ENABLE_FALL_ENABLE 上升/下降沿死区模块都使能
 * @retval void
 */
KF_INLINE void Epwm_LL_SelectDeadZoneOutputMode(Epwm_RegisterMap_t *const Module, const Epwm_DeadOutput_t DeadOutput)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_DEAD_OUTPUT_EVENT(DeadOutput));
    REG_WRITE(Module->EPWM_DBCTL.bits.OUTMODE, DeadOutput);
}

/**
 * @brief 选择死区模块输入极性
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DeadPolarity 死区模块输入极性
 *                EPWM_DEAD_A_NONE_B_NONE 波形发生模块的A,B路输出都不翻转
 *                EPWM_DEAD_A_TOGGLE_B_NONE 波形发生模块的A路翻转,B路输出不翻转
 *                EPWM_DEAD_A_NONE_B_TOGGLE 波形发生模块的A路不翻转,B路输出翻转
 *                EPWM_DEAD_A_TOGGLE_B_TOGGLE 波形发生模块的A,B路输出都翻转
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDeadZonePolarity(Epwm_RegisterMap_t *const Module, const Epwm_DeadPolarity_t DeadPolarity)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_DEAD_POLAR(DeadPolarity));
    REG_WRITE(Module->EPWM_DBCTL.bits.POLSEL, DeadPolarity);
}

/**
 * @brief EPWM选择死区模块输入
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DeadInput 死区模块输入
 *                EPWM_DEAD_IN_A_RAISE_A_FALL 波形发生模块的A路输出作为上升沿,下降沿的输入
 *                EPWM_DEAD_IN_B_RAISE_A_FALL 波形发生模块的B路输出作为上升沿输入,A路输出作为下降沿输入
 *                EPWM_DEAD_IN_A_RAISE_B_FALL 波形发生模块的A路输出作为上升沿输入,B路输出作为下降沿输入
 *                EPWM_DEAD_IN_B_RAISE_B_FALL 波形发生模块的B路输出作为上升沿,下降沿的输入
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDeadZoneInput(Epwm_RegisterMap_t *const Module, const Epwm_DeadInput_t DeadInput)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_DEAD_INPUT(DeadInput));
    Module->EPWM_DBCTL.bits.INMODE = (uint32_t)DeadInput;
}

/**
 * @brief EPWM设置下降沿死区时间
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DelayTime 下降沿死区时间
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDeadDelayTimeFall(Epwm_RegisterMap_t *const Module, const uint16_t DelayTime)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_DBT.bits.FDBT, DelayTime);
}

/**
 * @brief EPWM设置上升沿死区时间
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DelayTime 上升沿死区时间
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDeadDelayTimeRise(Epwm_RegisterMap_t *const Module, const uint16_t DelayTime)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_DBT.bits.RDBT, DelayTime);
}

/**
 * @brief EPWM设置斩波模块使能
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 禁止斩波
 *                true 使能斩波
 * @retval void
 */
KF_INLINE void Epwm_LL_SetChopperEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_PCCTL.bits.CHPEN, EnableStatus);
}

/**
 * @brief EPWM设置斩波第一个脉冲宽度
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Width 斩波第一个脉冲宽度
 *                EPWM_CHOPPER_WIDTH_FIRST_1 1个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_2 2个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_3 3个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_4 4个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_5 5个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_6 6个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_7 7个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_8 8个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_9 9个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_10 10个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_11 11个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_12 12个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_13 13个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_14 14个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_15 15个斩波时钟周期
 *                EPWM_CHOPPER_WIDTH_FIRST_16 16个斩波时钟周期
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetFirstPulseWidthOfChopper(Epwm_RegisterMap_t *const Module, const Epwm_ChopperWidthFirst_t Width)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_CHOPPER_WIDTH_FIRST(Width));

    REG_WRITE(Module->EPWM_PCCTL.bits.OSHTWTH, Width);
}

/**
 * @brief EPWM设置斩波PCLK占空比
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param PclkDuty 占空比
 *                EPWM_PCLK_DUTY_7_DIV_8 7/8 占空比
 *                EPWM_PCLK_DUTY_6_DIV_8 6/8 占空比
 *                EPWM_PCLK_DUTY_5_DIV_8 5/8 占空比
 *                EPWM_PCLK_DUTY_4_DIV_8 4/8 占空比
 *                EPWM_PCLK_DUTY_3_DIV_8 3/8 占空比
 *                EPWM_PCLK_DUTY_2_DIV_8 2/8 占空比
 *                EPWM_PCLK_DUTY_1_DIV_8 1/8 占空比
 * @retval void
 */
KF_INLINE void Epwm_LL_SetPclkDutyCycle(Epwm_RegisterMap_t *const Module, const Epwm_ChopperPclkDuty_t PclkDuty)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_CHOPPER_PCLK_DUTY(PclkDuty));

    REG_WRITE(Module->EPWM_PCCTL.bits.CHPDUTY, PclkDuty);
}

/**
 * @brief 设置EPWM模块斩波频率
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param PclkFrequency
 *                EPWM_CHOPPER_PCLK_PRESCALE_1 1:1分频
 *                EPWM_CHOPPER_PCLK_PRESCALE_2 1:2分频
 *                EPWM_CHOPPER_PCLK_PRESCALE_3 1:3分频
 *                EPWM_CHOPPER_PCLK_PRESCALE_4 1:4分频
 *                EPWM_CHOPPER_PCLK_PRESCALE_5 1:5分频
 *                EPWM_CHOPPER_PCLK_PRESCALE_6 1:6分频
 *                EPWM_CHOPPER_PCLK_PRESCALE_7 1:7分频
 *                EPWM_CHOPPER_PCLK_PRESCALE_8 1:8分频
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetPclkFrequency(Epwm_RegisterMap_t *const Module, const Epwm_ChopperPclkPrescale_t PclkFrequency)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_CHOPPER_PCLK_PRESCALE(PclkFrequency));
    REG_WRITE(Module->EPWM_PCCTL.bits.CHPFREQ, PclkFrequency);
}

/**
 * @brief 设置EPWM自动关断控制使能
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 禁止关断控制
 *                true 使能关断控制
 * @retval void
 */
KF_INLINE void Epwm_LL_SetShutdownEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_TZSCTL.bits.PXAEN, EnableStatus);
}

/**
 * @brief 设置EPWM自动重启使能
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 自动关闭时，PXASE 由软件清零，以重启 EPWM
 *                true 自动关闭时，当关闭事件消失，PXASE 位将自动清零，EPWM 自动重启
 * @retval void
 */
KF_INLINE void Epwm_LL_SetAutoRestartEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_TZSCTL.bits.PXRSEN, EnableStatus);
}

/**
 * @brief 设置EPWM引脚关断状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param ShutdownLevel 关断状态
 *                EPWM_SHUTDOWN_LEVEL_LOW 关断时,输出为低电平
 *                EPWM_SHUTDOWN_LEVEL_HIGH 关断时,输出为高电平
 *                EPWM_SHUTDOWN_LEVEL_HI_Z 关断时,输出为高阻态
 * @retval void
 */
KF_INLINE void Epwm_LL_SetShutdownOutput(
  Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const Epwm_ShutdownLevel_t ShutdownLevel)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_SHUTDOWN_LEVEL(ShutdownLevel));

    if (EPWM_OUTPUT_A == Output)
    {
        Module->EPWM_TZSCTL.bits.PXSSA = (uint32_t)ShutdownLevel;
    }
    else
    {
        Module->EPWM_TZSCTL.bits.PXSSB = (uint32_t)ShutdownLevel;
    }
}

/**
 * @brief EPWM模块Tz自动关断源选择
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Source 关断源
 *                EPWM_SHUTDOWN_SOURCE_TZ0 TZ0
 *                EPWM_SHUTDOWN_SOURCE_TZ1 TZ1
 *                EPWM_SHUTDOWN_SOURCE_TZ2 TZ2
 *                EPWM_SHUTDOWN_SOURCE_TZ3 TZ3
 *                EPWM_SHUTDOWN_SOURCE_TZ4 TZ4
 *                EPWM_SHUTDOWN_SOURCE_TZ5 TZ5
 *                EPWM_SHUTDOWN_SOURCE_TZ6 TZ6
 *                EPWM_SHUTDOWN_SOURCE_TZ7 TZ7
 *                EPWM_SHUTDOWN_SOURCE_TZ8 TZ8
 *                EPWM_SHUTDOWN_SOURCE_TZ9 TZ9
 *                EPWM_SHUTDOWN_SOURCE_TZ10 TZ10
 *                EPWM_SHUTDOWN_SOURCE_TZ11 TZ11
 *                EPWM_SHUTDOWN_SOURCE_TZ12 TZ12
 *                EPWM_SHUTDOWN_SOURCE_TZ13 TZ13
 *                EPWM_SHUTDOWN_SOURCE_TZ14 TZ14
 *                EPWM_SHUTDOWN_SOURCE_TZ15 TZ15
 * @retval void
 */
KF_INLINE void Epwm_LL_SetShutdownTzSource(Epwm_RegisterMap_t *const Module, Epwm_ShutdownSource_t Source)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_SHUTDOWN_SOURCE(Source));
    REG_WRITE(Module->EPWM_TZSCTL.bits.TZSEL, Source);
}

/**
 * @brief QEI模块错误中断标志信号使能控制
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 禁用该标志作为关断信号
 *                true 使能该标志作为关断信号
 * @retval void
 */
KF_INLINE void Epwm_LL_SetQeiErrorShutdownEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_TZSCTL.bits.PXQEIIFEN, EnableStatus);
}

/**
 * @brief 振荡器模块错误中断标志信号使能控制
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param EnableStatus 使能状态
 *                false 禁用该标志作为关断信号
 *                true 使能该标志作为关断信号
 * @retval void
 */
KF_INLINE void Epwm_LL_SetClkErrorShutdownEnabled(Epwm_RegisterMap_t *const Module, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_TZSCTL.bits.PXCLKIFEN, EnableStatus);
}

/**
 * @brief TZy 关断信号模式设置
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Mode Tz关断信号模式
 *                EPWM_TZ_SHUTDOWN_HIGH_ACTIVE 使能 TZy 关断，高电平有效
 *                EPWM_TZ_SHUTDOWN_LOW_ACTIVE 使能 TZy 关断，低电平有效
 *                EPWM_TZ_SHUTDOWN_DISABLE 禁止 TZy 关断控制
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTzShutdownMode(Epwm_RegisterMap_t *const Module, const Epwm_TzShutdownMode_t Mode)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_TZ_SHUTDOWN_MODE(Mode));
    REG_WRITE(Module->EPWM_TZSCTL.bits.PXTZEN, Mode);
}

/**
 * @brief 设置EPWM 通道高精度功能使能状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param EnableStatus 使能状态
 *                false 禁止通道高精度功能
 *                true 使能通道高精度功能
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetHiResolutionEnabled(Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    if (Output == EPWM_OUTPUT_A)
    {
        REG_WRITE(Module->EPWM_HRACTL.bits.HRENA, EnableStatus);
    }
    else
    {
        REG_WRITE(Module->EPWM_HRBCTL.bits.HRENB, EnableStatus);
    }
}

/**
 * @brief EPWM设置HRPWM通道输出控制
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param EnableStatus 使能状态
 *                false 通道输出经过高精度处理
 *                true 通道输出不经过高精度处理
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetHiResOutputEnabled(Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    if (Output == EPWM_OUTPUT_A)
    {
        REG_WRITE(Module->EPWM_HRACTL.bits.HRSELA, EnableStatus);
    }
    else
    {
        REG_WRITE(Module->EPWM_HRBCTL.bits.HRSELB, EnableStatus);
    }
}

/**
 * @brief EPWM设置占空比高精度使能状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param EnableStatus 使能状态
 *                false 禁止高精度占空比延时功能
 *                true 使能高精度占空比延时功能
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetHiResDutyCycleEnabled(Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    if (Output == EPWM_OUTPUT_A)
    {
        REG_WRITE(Module->EPWM_HRACTL.bits.HRDENA, EnableStatus);
    }
    else
    {
        REG_WRITE(Module->EPWM_HRBCTL.bits.HRDENB, EnableStatus);
    }
}

/**
 * @brief EPWM设置周期高精度使能状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param EnableStatus 使能状态
 *                false  禁止高精度周期延时功能
 *                true 使能高精度周期延时功能
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetHiResPeriodEnabled(Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    if (Output == EPWM_OUTPUT_A)
    {
        REG_WRITE(Module->EPWM_HRACTL.bits.HRPENA, EnableStatus);
    }
    else
    {
        REG_WRITE(Module->EPWM_HRBCTL.bits.HRPENB, EnableStatus);
    }
}

/**
 * @brief EPWM设置死区上升沿高精度使能状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param EnableStatus 使能状态
 *                false  禁止高精度死区上升沿延时功能
 *                true 使能高精度死区上升沿延时功能
 * @retval void
 */
KF_INLINE void Epwm_LL_SetHiResDeadZoneRaiseEdgeEnabled(
  Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    if (Output == EPWM_OUTPUT_A)
    {
        REG_WRITE(Module->EPWM_HRACTL.bits.HRRENA, EnableStatus);
    }
    else
    {
        REG_WRITE(Module->EPWM_HRBCTL.bits.HRRENB, EnableStatus);
    }
}

/**
 * @brief EPWM设置死区下降沿高精度使能状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param EnableStatus 使能状态
 *                false  禁止高精度死区下降沿延时功能
 *                true 使能高精度死区下降沿延时功能
 * @retval void
 */
KF_INLINE void Epwm_LL_SetHiResDeadZoneFallEdgeEnabled(
  Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    if (Output == EPWM_OUTPUT_A)
    {
        REG_WRITE(Module->EPWM_HRACTL.bits.HRFENA, EnableStatus);
    }
    else
    {
        REG_WRITE(Module->EPWM_HRBCTL.bits.HRFENB, EnableStatus);
    }
}

/**
 * @brief EPWM设置相位高精度使能状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param EnableStatus 使能状态
 *                false  禁止高精度相位功能
 *                true 使能高精度相位功能
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetHiResPhaseEnabled(Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    if (Output == EPWM_OUTPUT_A)
    {
        REG_WRITE(Module->EPWM_HRACTL.bits.HRPHSENA, EnableStatus);
    }
    else
    {
        REG_WRITE(Module->EPWM_HRBCTL.bits.HRPHSENB, EnableStatus);
    }
}

/**
 * @brief EPWM设置高精度占空比
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetHiResDutyCycle(Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const uint8_t Duty)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    REG_WRITE(((uint8_t *)&Module->EPWM_HRRA.reg)[(uint32_t)Output << 2], Duty);
}

/**
 * @brief EPWM设置高精度上升沿死区时间
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Time 上升沿死区时间
 * @retval void
 */
KF_INLINE void Epwm_LL_SetHiResDelayTimeRaise(Epwm_RegisterMap_t *const Module, const uint8_t Time)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_HRDB.bits.HRR, Time);
}

/**
 * @brief EPWM设置高精度下降沿死区时间
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Time 下降沿死区时间
 * @retval void
 */
KF_INLINE void Epwm_LL_SetHiResDelayTimeFall(Epwm_RegisterMap_t *const Module, const uint8_t Time)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_HRDB.bits.HRF, Time);
}

/**
 * @brief EPWM设置高精度周期值
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Period 周期值
 * @retval void
 */
KF_INLINE void Epwm_LL_SetHiResPeriod(Epwm_RegisterMap_t *const Module, const uint8_t Period)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_HRPHS.bits.HRPRE, Period);
}

/**
 * @brief EPWM设置高精度相位值
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Phase 相位值
 * @retval void
 */
KF_INLINE void Epwm_LL_SetHiResPhase(Epwm_RegisterMap_t *const Module, const uint8_t Phase)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_HRPHS.bits.HRPHS, Phase);
}

/**
 * @brief EPWM设置延时波形计数次数
 * @details 由于 PWM
 * 经过高精度的处理，会导致每次输出会在上一次输出的基础上有一定的相位后移，延时计数次数用来保证最大允许的相位后移，每处理
 * TIMS<7:0> 个 PWM 波形，就会重新将原始信号载入到 HRPWM，同时延时次数的计数再次从 0 开始计数。
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Value
 * @retval void
 */
KF_INLINE void Epwm_LL_SetHiResDelayTimes(Epwm_RegisterMap_t *const Module, const uint8_t Value)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_HRCFG.bits.TIMS, Value);
}

/**
 * @brief EPWM设置高精度步长
 * @details 高精度步长数，表示每一个计数时钟中包含的细粒度步数
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Step 步长
 * @retval void
 */
KF_INLINE void Epwm_LL_SetHiResStepNum(Epwm_RegisterMap_t *const Module, const uint8_t Step)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_HRCFG.bits.STEP, Step);
}

/**
 * @brief EPWM获取高精度MEP延长步数
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Edge
 *                EPWM_CHA_FALL 通道A下降沿
 *                EPWM_CHA_RAISE 通道A上升沿
 *                EPWM_CHB_FALL 通道B下降沿
 *                EPWM_CHB_RAISE 通道B上升沿
 * @retval uint8_t 高精度MEP延长步数
 */
KF_INLINE uint8_t Epwm_LL_GetHiResDelayStep(const Epwm_RegisterMap_t *const Module, const Epwm_HiResEdge_t Edge)
{
    uint32_t Mask;

    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_HI_RES_EDGE(Module));

    Mask = (uint32_t)Edge << 3U;
    return (uint8_t)(REG_BITS_READ(Module->EPWM_HRDELAY.reg, (0xFFU << Mask), Mask));
}

/**
 * @brief 设置触发AD事件触发使能状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Event 事件序号
 *                false 事件0 输出触发 AD 信号：ADTG0
 *                true 事件1 输出触发 AD 信号：ADTG1
 * @param EnableStatus 事件触发使能状态
 *                false 不使能触发事件
 *                true 使能触发事件
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetTriggerEventEnabled(Epwm_RegisterMap_t *const Module, const bool Event, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    uint32_t Mask = (uint32_t)Event << 4U;
    REG_BITS_WRITE(Module->EPWM_ETCTL0.reg, (uint32_t)0x1U << Mask, (uint32_t)EnableStatus << Mask);
}

/**
 * @brief 软件触发AD事件
 * @details 产生一次触发AD事件脉冲,该位由硬件自动清零
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Event 事件序号
 *                false 事件0 输出触发 AD 信号：ADTG0
 *                true 事件1 输出触发 AD 信号：ADTG1
 * @retval void
 */
KF_INLINE void Epwm_LL_TriggerEventBySoftware(Epwm_RegisterMap_t *const Module, const bool Event)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    uint32_t Mask = ((uint32_t)Event << 4U) + 3U;
    REG_BIT_SET(Module->EPWM_ETCTL0.reg, (uint32_t)0x1U << Mask);
}

/**
 * @brief 设置事件触发模式
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Event 事件序号
 *                false 事件0 输出触发 AD 信号：ADTG0
 *                true 事件1 输出触发 AD 信号：ADTG1
 * @param Mode 触发模式
 *                EPWM_EVENT_TRIGGER_BOTH 在任意计数方向上都可触发AD
 *                EPWM_EVENT_TRIGGER_COUNT_UP 在计数方向向上的时候触发AD
 *                EPWM_EVENT_TRIGGER_COUNT_DOWN 在计数方向向下的时候触发AD
 * @retval void
 */
KF_INLINE void
Epwm_LL_SelectTriggerModeOfEvent(Epwm_RegisterMap_t *const Module, const bool Event, const Epwm_EventTriggerMode_t Mode)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_EVENT_TRIGGER(Mode));
    uint32_t Mask = ((uint32_t)Event << 4U) + 8U;
    REG_BITS_WRITE(Module->EPWM_ETCTL0.reg, (uint32_t)0x3U << Mask, (uint32_t)Mode << Mask);
}

/**
 * @brief EPWM选择触发AD事件
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Event 事件序号
 *                false 事件0 输出触发 AD 信号：ADTG0
 *                true 事件1 输出触发 AD 信号：ADTG1
 * @param  Trigger 触发AD的事件
 *                  EPWM_EVENT_TX_EQU_ZERO 定时器值等于零脉冲
 *                  EPWM_EVENT_TX_EQU_PPX 定时器值等于 PP 脉冲
 *                  EPWM_EVENT_TX_EQU_RA 定时器值等于占空比 A 寄存器脉冲
 *                  EPWM_EVENT_TX_EQU_RB 定时器值等于占空比 B 寄存器脉冲
 *                  EPWM_EVENT_TX_EQU_RC 定时器值等于占空比 C 寄存器脉冲
 *                  EPWM_EVENT_TX_EQU_RD 定时器值等于占空比 D 寄存器脉冲
 *                  EPWM_EVENT_SYNCI 同步输入信号 SYNCIN
 * @retval void
 */
KF_INLINE void
Epwm_LL_SelectTriggerAdEvent(Epwm_RegisterMap_t *const Module, const bool Event, const Epwm_AdTriggerEvent_t Trigger)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_AD_TRIGGER_EVENT(Trigger));
    uint32_t Mask = (uint32_t)Event << 4U;
    REG_BITS_WRITE(Module->EPWM_ETCTL1.reg, (uint32_t)0x7U << Mask, (uint32_t)Trigger << Mask);
}

/**
 * @brief EPWM设置触发AD的周期
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Event 事件序号
 *                false 事件0 输出触发 AD 信号：ADTG0
 *                true 事件1 输出触发 AD 信号：ADTG1
 * @param  Period 触发周期
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_1 每1次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_2 每2次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_3 每3次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_4 每4次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_5 每5次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_6 每6次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_7 每7次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_8 每8次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_9 每9次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_10 每10次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_11 每11次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_12 每12次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_13 每13次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_14 每14次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_15 每15次触发信号产生触发 AD 事件
 *                 EPWM_RIGGER_AD_EVENT_PERIOD_16 每16次触发信号产生触发 AD 事件
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetTriggerAdPeriod(Epwm_RegisterMap_t *const Module, const bool Event, const Epwm_TriggerADEventPeriod_t Period)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_TRIGGER_AD_EVENT_PERIOD(Period));
    uint32_t Mask = ((uint32_t)Event << 4) + 3U;
    REG_BITS_WRITE(Module->EPWM_ETCTL1.reg, (uint32_t)0xFU << Mask, (uint32_t)Period << Mask);
}

/**
 * @brief EPWM获取触发AD信号数量
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Event 事件序号
 *                false 事件0 输出触发 AD 信号：ADTG0
 *                true 事件1 输出触发 AD 信号：ADTG1
 * @retval uint32_t 触发信号数量,0x1 ~ 0x10
 */
KF_INLINE uint32_t Epwm_LL_GetTriggerAdSignalTimes(Epwm_RegisterMap_t *const Module, const bool Event)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    uint32_t Mask = ((uint32_t)Event << 4U) + 7U;
    return (REG_BITS_READ(Module->EPWM_ETCTL1.reg, 0xFU << Mask, Mask));
}

/**
 * @brief EPWM设置消隐窗口宽度
 *
 *
 * @param Module
 * @param Width
 * @return
 */
KF_INLINE void Epwm_LL_SetBlankWindowWidth(Epwm_RegisterMap_t *const Module, const uint16_t Width)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_BWCFG.bits.BWIDTH, Width);
}

/**
 * @brief EPWM设置消隐窗口偏置
 *
 *
 * @param Module
 * @param Offset
 * @return
 */
KF_INLINE void Epwm_LL_SetBlankWindowOffset(Epwm_RegisterMap_t *const Module, const uint16_t Offset)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_BWCFG.bits.BWOFFSET, Offset);
}

/**
 * @brief EPWM获取消隐窗口偏置
 * @details 在每次偏置参考点将 BWOFFSET<15:0>值加载到该16 位计数器中并开始向下计数
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval uint16_t 消隐窗口偏置,0x0 ~ 0xFFFF
 */
KF_INLINE uint16_t Epwm_LL_GetBlankWindowOffset(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return (uint16_t)REG_READ(Module->EPWM_BWCNT.bits.OFFCNT);
}

/**
 * @brief EPWM获取消隐窗口宽度
 * @details 在每次偏置计数器计数到 0 时将 BWIDTH<15:0>值加载到该计数器中并开始向下计数。
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval uint16_t 消隐窗口宽度,0x0 ~ 0xFFFF
 */
KF_INLINE uint16_t Epwm_LL_GetBlankWindowWidth(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return (uint16_t)REG_READ(Module->EPWM_BWCNT.bits.WITCNT);
}

/**
 * @brief EPWM获取计数方向
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval bool  计数方向
 *                  false 当前计数方向为向上计数
 *                  true 当前计数方向为向下计数
 */
KF_INLINE bool Epwm_LL_GetCountDirection(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return (bool)REG_READ(Module->EPWM_STA.bits.DIR);
}

/**
 * @brief EPWM获取计数器达到最大值状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval bool  计数值达到最大值状态位
 *              false 计数值没有达到过最大值 0xFFFF FFFF
 *              true 计数值达到最大值 0xFFFF FFFF
 */
KF_INLINE bool Epwm_LL_GetCountReachMaxStatus(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return (bool)REG_READ(Module->EPWM_STA.bits.CNTMAX);
}

/**
 * @brief EPWM清除计数器达到最大值状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_ClearCountReachMaxStatus(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    /**
     * @brief 此处不使用位域操作，因为：当多个标志置1时，写1清零操作可能导致读-改-写的方式误清其他标志位；
     * @attention 若指令集中CLR指令不会对其他位执行写操作，且编译器会使用CLR指令，则可用位域操作
     *
     */
    REG_WRITE(Module->EPWM_STA.reg, 2U);
}

/**
 * @brief EPWM获取外部同步事件输入状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval bool  外部同步事件输入状态
 *              false 没有外部同步事件输入
 *              true 有外部同步事件输入
 */
KF_INLINE bool Epwm_LL_GetSyncEventInputStatus(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return (bool)REG_READ((Module->EPWM_STA.bits.SYNCI));
}

/**
 * @brief EPWM清除外部同步事件输入状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_ClearSyncEventInputStatus(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    /**
     * @brief 此处不使用位域操作，因为：当多个标志置1时，写1清零操作可能导致读-改-写的方式误清其他标志位；
     * @attention 若指令集中CLR指令不会对其他位执行写操作，且编译器会使用CLR指令，则可用位域操作
     *
     */
    REG_WRITE(Module->EPWM_STA.reg, 4U);
}

/**
 * @brief 获取影子寄存器空满标志
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param  ShadowReg 影子寄存器
 *                  EPWM_SHADOW_REG_RA EPWMx_RA的影子寄存器
 *                  EPWM_SHADOW_REG_RB EPWMx_RB的影子寄存器
 *                  EPWM_SHADOW_REG_RC EPWMx_RC的影子寄存器
 *                  EPWM_SHADOW_REG_RD EPWMx_RD的影子寄存器
 *                  EPWM_SHADOW_REG_PPX Tx_PPX的影子寄存器
 *                  EPWM_SHADOW_REG_PRSC Tx_PRSC的影子寄存器
 *                  EPWM_SHADOW_REG_ACTL EPWMx_ACTL的影子寄存器
 *                  EPWM_SHADOW_REG_BCTL EPWMx_BCTL的影子寄存器
 *                  EPWM_SHADOW_REG_HRRA EPWMx_HRRA的影子寄存器
 *                  EPWM_SHADOW_REG_HRRB EPWMx_HRRB的影子寄存器
 *                  EPWM_SHADOW_REG_DBT EPWMx_DBT的影子寄存器
 *                  EPWM_SHADOW_REG_HRDB EPWMx_HRDB的影子寄存器
 *                  EPWM_SHADOW_REG_HRPHS EPWMx_HRPHS的影子寄存器
 *                  EPWM_SHADOW_REG_HRCFG EPWMx_HRCFG的影子寄存器
 *                  EPWM_SHADOW_REG_CAP EPWMx_CAP的影子寄存器
 * @retval void
 */
KF_INLINE bool Epwm_LL_GetShadowRegSta(const Epwm_RegisterMap_t *const Module, const Epwm_ShadowReg_t ShadowReg)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_SHADOW_REG(ShadowReg));
    uint32_t Mask = ShadowReg + 8U;
    return (bool)(REG_BITS_READ(Module->EPWM_STA.reg, (0x1U << Mask), Mask));
}

/**
 * @brief EPWM获取自动关断事件状态
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval bool
 *                false EPWM 正常工作
 *                true 发生了关断事件，EPWM 为关闭状态
 */
KF_INLINE bool Epwm_LL_GetShutdownStatus(Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return (bool)Module->EPWM_STA.bits.PXASE;
}

/**
 * @brief  设置EPWM定时器的计数值
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Count: 定时器计数值
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WriteTimerCount(Epwm_RegisterMap_t *const Module, const uint32_t Count)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_CNT.reg, Count);
}

/**
 * @brief  获取EPWM定时器当前计数值
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval uint32_t: 定时器当前计数值
 */
KF_INLINE uint32_t Epwm_LL_ReadTimerCount(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    return REG_READ(Module->EPWM_CNT.reg);
}

/**
 * @brief  设置EPWM定时器相位值
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Phase: 定时器相位值
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WritePhaseValue(Epwm_RegisterMap_t *const Module, const uint32_t Phase)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_PHS.reg, Phase);
}

/**
 * @brief  读取EPWM定时器相位值
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval uint32_t: 定时器相位值
 */
KF_INLINE uint32_t Epwm_LL_ReadPhaseValue(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return REG_READ(Module->EPWM_PHS.reg);
}

/**
 * @brief  设置EPWM定时器周期值
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Period: 定时器周期值
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WritePeriodValue(Epwm_RegisterMap_t *const Module, const uint32_t Period)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    REG_WRITE(Module->EPWM_PPX.reg, Period);
}

/**
 * @brief  读取EPWM定时器周期值
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval uint32_t: 定时器周期值
 */
KF_INLINE uint32_t Epwm_LL_ReadPeriodValue(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));

    return REG_READ(Module->EPWM_PPX.reg);
}

/**
 * @brief  设置EPWM预分频系数
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Scaler: 预分频系数
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WritePrescalerValue(Epwm_RegisterMap_t *const Module, const uint32_t Scaler)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    REG_WRITE(Module->EPWM_PRSC.reg, Scaler);
}

/**
 * @brief  读取EPWM定时器预分频系数
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval uint32_t: 预分频系数
 */
KF_INLINE uint32_t Epwm_LL_ReadPrescalerValue(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return REG_READ(Module->EPWM_PRSC.reg);
}

/**
 * @brief 设置EPWM占空比寄存器
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 *                EPWM_OUTPUT_C 通道C
 *                EPWM_OUTPUT_D 通道D
 * @param Value
 * @retval void
 */
KF_INLINE void
Epwm_LL_WriteDutyCycleValue(Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output, const uint32_t Value)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    REG_WRITE((&Module->EPWM_RA.reg)[(uint32_t)Output], Value);
}

/**
 * @brief 获取EPWM占空比寄存器值
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param Output EPWM输出路径
 *                EPWM_OUTPUT_A 通道A
 *                EPWM_OUTPUT_B 通道B
 * @param Value 写入值
 * @retval uint32_t 占空比寄存器值
 */
KF_INLINE uint32_t Epwm_LL_ReadDutyCycleValue(const Epwm_RegisterMap_t *const Module, const Epwm_Output_t Output)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    return (&Module->EPWM_RA.reg)[(uint32_t)Output];
}

/**
 * @brief 获取EPWM捕捉值
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @retval uint32_t 捕捉寄存器值
 */
KF_INLINE uint32_t Epwm_LL_ReadCaptureValue(const Epwm_RegisterMap_t *const Module)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    return REG_READ(Module->EPWM_CAP.reg);
}

/**
 * @brief EPWM获取中断标志
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param IntIndex 中断索引
 *                EPWM_INDEX_OVERFLOW_EVENT 定时器溢出
 *                EPWM_INDEX_UPDATE_EVENT 更新事件
 *                EPWM_INDEX_SHUTDOWN_EVENT 关断事件
 *                EPWM_INDEX_TX_EQU_RA_EVENT 定时器计数等于RA事件
 *                EPWM_INDEX_TX_EQU_RB_EVENT 定时器计数等于RB事件
 *                EPWM_INDEX_TX_EQU_RC_EVENT 定时器计数等于RC事件
 *                EPWM_INDEX_TX_EQU_RD_EVENT 定时器计数等于RD事件
 *                EPWM_CAPTURE_EVENT 捕捉事件
 *                EPWM_AD_TRIGGER_EVENT_ZERO 定时器触发AD事件0
 *                EPWM_AD_TRIGGER_EVENT_ONE 定时器触发AD事件1
 * @retval bool
 *              false 未发生该事件触发中断
 *              true 发生该事件触发中断
 */
KF_INLINE bool Epwm_LL_GetIntrFlag(const Epwm_RegisterMap_t *const Module, const Epwm_InterruptIndex_t IntIndex)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_INTERRUPT(IntIndex));
    return (bool)REG_BITS_READ(Module->EPWM_IF.reg, 1U << (uint32_t)IntIndex, (uint32_t)IntIndex);
}

/**
 * @brief EPWM设置中断使能
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param IntIndex 中断索引
 *                EPWM_INDEX_OVERFLOW_EVENT 定时器溢出
 *                EPWM_INDEX_UPDATE_EVENT 更新事件
 *                EPWM_INDEX_SHUTDOWN_EVENT 关断事件
 *                EPWM_INDEX_TX_EQU_RA_EVENT 定时器计数等于RA事件
 *                EPWM_INDEX_TX_EQU_RB_EVENT 定时器计数等于RB事件
 *                EPWM_INDEX_TX_EQU_RC_EVENT 定时器计数等于RC事件
 *                EPWM_INDEX_TX_EQU_RD_EVENT 定时器计数等于RD事件
 *                EPWM_CAPTURE_EVENT 捕捉事件
 *                EPWM_AD_TRIGGER_EVENT_ZERO 定时器触发AD事件0
 *                EPWM_AD_TRIGGER_EVENT_ONE 定时器触发AD事件1
 * @param EnableStatus 使能状态
 *                false 禁止中断
 *                true 使能中端
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetIntrEnabled(Epwm_RegisterMap_t *const Module, const Epwm_InterruptIndex_t IntIndex, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_INTERRUPT(IntIndex));
    REG_BITS_WRITE(
      Module->EPWM_IE.reg, (uint32_t)0x1U << (uint32_t)IntIndex, (uint32_t)EnableStatus << (uint32_t)IntIndex);
}

/**
 * @brief 清除EPWM中断标志
 * @attention EPWM_IC寄存器标志置1后硬件自动清零
 * @attention CAPIC特殊清除机制，不通过此API清除
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param IntIndex 中断清除索引
 *                EPWM_INDEX_OVERFLOW_EVENT 定时器溢出
 *                EPWM_INDEX_UPDATE_EVENT 更新事件
 *                EPWM_INDEX_SHUTDOWN_EVENT 关断事件
 *                EPWM_INDEX_TX_EQU_RA_EVENT 定时器计数等于RA事件
 *                EPWM_INDEX_TX_EQU_RB_EVENT 定时器计数等于RB事件
 *                EPWM_INDEX_TX_EQU_RC_EVENT 定时器计数等于RC事件
 *                EPWM_INDEX_TX_EQU_RD_EVENT 定时器计数等于RD事件
 *                EPWM_AD_TRIGGER_EVENT_ZERO 定时器触发AD事件0
 *                EPWM_AD_TRIGGER_EVENT_ONE 定时器触发AD事件1
 * @param EnableStatus 使能状态
 *                false 禁止中断
 *                true 使能中端
 * @retval void
 */
KF_INLINE void Epwm_LL_ClearIntrFlag(Epwm_RegisterMap_t *const Module, const Epwm_InterruptClearIndex_t IntIndex)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_INTERRUPT_CLEAR(IntIndex));
    REG_BIT_SET(Module->EPWM_IC.reg, (uint32_t)0x1U << (uint32_t)IntIndex);
}

/**
 * @brief PWM设置CAPIF清零模式
 *
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param ClearMode 清零模式
 *                EPWM_CAP_CLEAR_MODE_NONE 不清除
 *                EPWM_CAP_CLEAR_MODE_EQU_ZERO 计数器匹配 0 时清零捕捉标志位
 *                EPWM_CAP_CLEAR_MODE_EQU_PERIOD 计数值匹配周期值时清零捕捉标志位
 *                EPWM_CAP_CLEAR_MODE_SOFT 软件清零捕捉标志位
 * @retval void
 */
KF_INLINE void Epwm_LL_SetCapClearMode(Epwm_RegisterMap_t *const Module, const Epwm_CapClearMode_t ClearMode)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_CAP_CLEAR_MODE(ClearMode));
    REG_WRITE(Module->EPWM_IC.bits.CAPIC, ClearMode);
}

/**
 * @brief 软件置位EPWM中断标志
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param IntIndex 中断索引
 *                EPWM_INDEX_OVERFLOW_EVENT 定时器溢出
 *                EPWM_INDEX_UPDATE_EVENT 更新事件
 *                EPWM_INDEX_SHUTDOWN_EVENT 关断事件
 *                EPWM_INDEX_TX_EQU_RA_EVENT 定时器计数等于RA事件
 *                EPWM_INDEX_TX_EQU_RB_EVENT 定时器计数等于RB事件
 *                EPWM_INDEX_TX_EQU_RC_EVENT 定时器计数等于RC事件
 *                EPWM_INDEX_TX_EQU_RD_EVENT 定时器计数等于RD事件
 *                EPWM_CAPTURE_EVENT 捕捉事件
 *                EPWM_AD_TRIGGER_EVENT_ZERO 定时器触发AD事件0
 *                EPWM_AD_TRIGGER_EVENT_ONE 定时器触发AD事件1
 * @param EnableStatus 使能状态
 *                false 禁止中断
 *                true 使能中端
 * @retval void
 */
KF_INLINE void Epwm_LL_SoftwareSetIntrFlag(Epwm_RegisterMap_t *const Module, const Epwm_InterruptIndex_t IntIndex)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_INTERRUPT(IntIndex));
    REG_BIT_SET(Module->EPWM_IS.reg, (uint32_t)0x1U << (uint32_t)IntIndex);
}

/**
 * @brief  EPWM设置DMA使能
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DmaIndex DMA索引
 *                EPWM_INDEX_OVERFLOW_EVENT 定时器溢出
 *                EPWM_INDEX_UPDATE_EVENT 更新事件
 *                EPWM_INDEX_SHUTDOWN_EVENT 关断事件
 *                EPWM_INDEX_TX_EQU_RA_EVENT 定时器计数等于RA事件
 *                EPWM_INDEX_TX_EQU_RB_EVENT 定时器计数等于RB事件
 *                EPWM_INDEX_TX_EQU_RC_EVENT 定时器计数等于RC事件
 *                EPWM_INDEX_TX_EQU_RD_EVENT 定时器计数等于RD事件
 *                EPWM_CAPTURE_EVENT 捕捉事件
 *                EPWM_AD_TRIGGER_EVENT_ZERO 定时器触发AD事件0
 *                EPWM_AD_TRIGGER_EVENT_ONE 定时器触发AD事件1
 * @param EnableStatus 使能状态
 *                false 禁止DMA
 *                true 使能DMA
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTriggerDmaEnabled(
  Epwm_RegisterMap_t *const Module, const Epwm_InterruptIndex_t DmaIndex, const bool EnableStatus)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_INTERRUPT(DmaIndex));
    REG_BITS_WRITE(
      Module->EPWM_DE.reg, (uint32_t)0x1U << (uint32_t)DmaIndex, (uint32_t)EnableStatus << (uint32_t)DmaIndex);
}

/**
 * @brief EPWM获取触发DMA标志
 *
 * @param Module 指向EPWM内存结构的指针
 *                EPWM11_PTR~EPWM14_PTR
 *                EPWM21_PTR~EPWM24_PTR
 *                EPWM31_PTR~EPWM34_PTR
 * @param DmaIndex DMA索引
 *                EPWM_INDEX_OVERFLOW_EVENT 定时器溢出
 *                EPWM_INDEX_UPDATE_EVENT 更新事件
 *                EPWM_INDEX_SHUTDOWN_EVENT 关断事件
 *                EPWM_INDEX_TX_EQU_RA_EVENT 定时器计数等于RA事件
 *                EPWM_INDEX_TX_EQU_RB_EVENT 定时器计数等于RB事件
 *                EPWM_INDEX_TX_EQU_RC_EVENT 定时器计数等于RC事件
 *                EPWM_INDEX_TX_EQU_RD_EVENT 定时器计数等于RD事件
 *                EPWM_CAPTURE_EVENT 捕捉事件
 *                EPWM_AD_TRIGGER_EVENT_ZERO 定时器触发AD事件0
 *                EPWM_AD_TRIGGER_EVENT_ONE 定时器触发AD事件1
 * @retval bool
 *              false 未发生该事件触发DMA
 *              true 发生该事件触发DMA
 */
KF_INLINE bool Epwm_LL_GetDmaTriggeredFlag(Epwm_RegisterMap_t *const Module, const Epwm_InterruptIndex_t DmaIndex)
{
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH(Module));
    KF_DRV_EPWM_ASSERT(CHECK_EPWM_INTERRUPT(DmaIndex));
    return (bool)REG_BITS_READ(Module->EPWM_DF.reg, 1U << (uint32_t)DmaIndex, (uint32_t)DmaIndex);
}
#ifdef __cplusplus
}
#endif
#endif
/* EOF */
