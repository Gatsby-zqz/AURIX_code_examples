/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_rtc.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-20
 *  @Version         : V0.0.1.231207_alpha
 *  @Description     : This document describes the C language document template
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2023-12-20  |V1.0     |Zhang Quanzhen  | New Creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_RTC_H_
#define KF32A13K_DRV_RTC_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_rtc.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_RTC_ASSERT
#include "dev_assert.h"
#define KF_DRV_RTC_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_RTC_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    RTC_NOSUSPEND   = 0U,
    RTC_STOPCOUNTER = 2U
} Rtc_SuspendMode_t;

#define CHECK_RTC_SUSPENDMODE(Mode) ((Mode == RTC_NOSUSPEND) || (Mode == RTC_STOPCOUNTER))

typedef enum
{
    RTC_ACCESS_ENABLE_0,
    RTC_ACCESS_ENABLE_1,
    RTC_ACCESS_ENABLE_2,
    RTC_ACCESS_ENABLE_3,
    RTC_ACCESS_ENABLE_4,
    RTC_ACCESS_ENABLE_5,
    RTC_ACCESS_ENABLE_6,
    RTC_ACCESS_ENABLE_7,
    RTC_ACCESS_ENABLE_8,
    RTC_ACCESS_ENABLE_9,
    RTC_ACCESS_ENABLE_10,
    RTC_ACCESS_ENABLE_11,
    RTC_ACCESS_ENABLE_12,
    RTC_ACCESS_ENABLE_13,
    RTC_ACCESS_ENABLE_14,
    RTC_ACCESS_ENABLE_15,
    RTC_ACCESS_ENABLE_16,
    RTC_ACCESS_ENABLE_17,
    RTC_ACCESS_ENABLE_18,
    RTC_ACCESS_ENABLE_19,
    RTC_ACCESS_ENABLE_20,
    RTC_ACCESS_ENABLE_21,
    RTC_ACCESS_ENABLE_22,
    RTC_ACCESS_ENABLE_23,
    RTC_ACCESS_ENABLE_24,
    RTC_ACCESS_ENABLE_25,
    RTC_ACCESS_ENABLE_26,
    RTC_ACCESS_ENABLE_27,
    RTC_ACCESS_ENABLE_28,
    RTC_ACCESS_ENABLE_29,
    RTC_ACCESS_ENABLE_30,
    RTC_ACCESS_ENABLE_31
} Rtc_AccessEnableType_t;

#define CHECK_RTC_ACCESSENABLE(AccessEnable) ((AccessEnable >> POS_5_SHIFT) == 0U)

typedef enum
{
    HOUR_24,
    HOUR_12
} Rtc_HourDisplayModeType_t;

#define CHECK_RTC_HOURDISMODE(Mode) ((Mode == HOUR_24) || (Mode == HOUR_12))

typedef enum
{
    CLOCK_DIVIDE_128,
    CLOCK_DIVIDE_32,
    CLOCK_DIVIDE_8,
    CLOCK_DIVIDE_2
} Rtc_ClockSourceDivideType_t;

#define CHECK_RTC_CLOCKSOURCEDIV(ClkDiv) ((ClkDiv >> POS_2_SHIFT) == 0U)

typedef enum
{
    NO_CLOCK,
    CDU_CLOCK,
    ELF_CLOCK,
    ILF_CLOCK
} Rtc_ClockSourceType_t;

#define CHECK_RTC_CLOCKSOURCE(ClkSource) ((ClkSource >> POS_2_SHIFT) == 0U)

typedef enum
{
    POSEDGE_TRIGGER,
    NEGEDGE_TRIGGER
} Rtc_TriggerEdgeType_t;

#define CHECK_RTC_TRIGGEREDGE(Edge) ((Edge == POSEDGE_TRIGGER) || (Edge == NEGEDGE_TRIGGER))

typedef enum
{
    TTOUT_DIVIDE_2,
    TTOUT_DIVIDE_4,
    TTOUT_DIVIDE_8,
    TTOUT_DIVIDE_16
} Rtc_TTOutDivideType_t;

#define CHECK_RTC_TTOUTDIV(TTODiv) ((TTODiv >> POS_2_SHIFT) == 0U)

typedef enum
{
    TT_SECOND_1,
    TT_SECOND_1_2,
    TT_SECOND_1_4,
    TT_SECOND_1_8,
    TT_SECOND_1_16,
    TT_SECOND_1_32,
    TT_SECOND_1_64,
    TT_SECOND_1_128
} Rtc_TTType_t;

#define CHECK_RTC_TTType(TTType) ((TTType >> POS_3_SHIFT) == 0U)

typedef enum
{
    ALARM_A,
    ALARM_B
} Rtc_AlarmType_t;

#define CHECK_RTC_ALARMType(Alarm) ((Alarm == ALARM_A) || (Alarm == ALARM_B))

typedef enum
{
    HOUR_AM,
    HOUR_PM
} Rtc_HourFormatType_t;

#define CHECK_RTC_HOURFORMAT(HourFormat) ((HourFormat == HOUR_AM) || (HourFormat == HOUR_PM))

typedef enum
{
    TIMER_0,
    TIMER_1
} Rtc_TimerType_t;

#define CHECK_RTC_TIMER(Timer) ((Timer == TIMER_0) || (Timer == TIMER_1))

typedef enum
{
    SOURCE_DIVIDE_128,
    SOURCE_DIVIDE_512,
    SOURCE_DIVIDE_1024,
    SOURCE_DIVIDE_2048,
    SOURCE_DIVIDE_8192,
    SOURCE_1_SECOND,
    SOURCE_1_MINUTE,
    SOURCE_1_HOUR
} Rtc_TimerClockSourceType_t;

#define CHECK_RTC_TIMERCLOCKSOURCE(Source) ((Source >> POS_3_SHIFT) == 0U)

typedef enum
{
    INT_SECOND             = 0U,
    INT_MINUTE             = 1U,
    INT_HOUR               = 2U,
    INT_DAY                = 3U,
    INT_ALARMA             = 4U,
    INT_ALARMB             = 5U,
    INT_TIMERTICK          = 6U,
    INT_TIMER0             = 8U,
    INT_TIMER1             = 9U,
    INT_TIMESTAMP_OVERFLOW = 10U,
    INT_TIMESTAMP          = 11U,
    INT_WEEK               = 13U,
    INT_MOUTH              = 14U,
    INT_YEAR               = 15U,
} Rtc_IntType_t;

#define CHECK_RTC_INT(Int)                                                                                             \
    ((Int == INT_SECOND) || (Int == INT_MINUTE) || (Int == INT_HOUR) || (Int == INT_DAY) || (Int == INT_ALARMA) ||     \
     (Int == INT_ALARMB) || (Int == INT_TIMERTICK) || (Int == INT_TIMER0) || (Int == INT_TIMER1) ||                    \
     (Int == INT_TIMESTAMP_OVERFLOW) || (Int == INT_TIMESTAMP) || (Int == INT_WEEK) || (Int == INT_MOUTH) ||           \
     (Int == INT_YEAR))

typedef enum
{
    SECOND_FLAG             = 0U,
    MINUTE_FLAG             = 1U,
    HOUR_FLAG               = 2U,
    DAY_FLAG                = 3U,
    ALARMA_FLAG             = 4U,
    ALARMB_FLAG             = 5U,
    TIMERTICK_FLAG          = 6U,
    TIMER0_FLAG             = 8U,
    TIMER1_FLAG             = 9U,
    TIMESTAMP_OVERFLOW_FLAG = 10U,
    TIMESTAMP_FLAG          = 11U,
    WEEK_FLAG               = 13U,
    MOUTH_FLAG              = 14U,
    YEAR_FLAG               = 15U,
} Rtc_FlagType_t;

#define CHECK_RTC_FLAG(Flag)                                                                                           \
    ((Flag == SECOND_FLAG) || (Flag == MINUTE_FLAG) || (Flag == HOUR_FLAG) || (Flag == DAY_FLAG) ||                    \
     (Flag == ALARMA_FLAG) || (Flag == ALARMB_FLAG) || (Flag == TIMERTICK_FLAG) || (Flag == TIMER0_FLAG) ||            \
     (Flag == TIMER1_FLAG) || (Flag == TIMESTAMP_OVERFLOW_FLAG) || (Flag == TIMESTAMP_FLAG) || (Flag == WEEK_FLAG) ||  \
     (Flag == MOUTH_FLAG) || (Flag == YEAR_FLAG))

typedef enum
{
    MINTESTEN   = 26U,
    HOURTESTEN  = 27U,
    DAYTESTEN   = 28U,
    WEEKTESTEN  = 29U,
    MONTHTESTEN = 30U,
    YEARTESTEN  = 31U
} Rtc_FastTestEnType_t;

#define CHECK_RTC_FASTTESTEN(TestEnable)                                                                               \
    ((TestEnable == MINTESTEN) || (TestEnable == HOURTESTEN) || (TestEnable == DAYTESTEN) ||                           \
     (TestEnable == WEEKTESTEN) || (TestEnable == MONTHTESTEN) || (TestEnable == YEARTESTEN))

typedef enum
{
    TEST_OUTPUT_YEAR,
    TEST_OUTPUT_MONTH,
    TEST_OUTPUT_DAY,
    TEST_OUTPUT_HOUR,
    TEST_OUTPUT_MINUTE,
    TEST_OUTPUT_SECOND,
    TEST_OUTPUT_WEEK,
    TEST_OUTPUT_ALL
} Rtc_TestModeOutput_t;

#define CHECK_RTC_TEST_MODE_OUTPUT(OUTPUT) ((OUTPUT <= TEST_OUTPUT_ALL)

#define CHECK_RTC_BOOL(Bool) ((Bool >> POS_1_SHIFT) == 0U)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief RTC禁止请求
 *
 *
 * @param Status
 *        true:禁止模块
 *        false:使能模块
 * @retval void
 */
KF_INLINE void Rtc_LL_SetRTCEnabled(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_CLKC.bits.DISR, Status);
}

/**
 * @brief 获取RTC模块状态
 *
 *
 * @param void
 * @retval bool
 *         true:模块已禁止
 *         false:模块已使能
 */
KF_INLINE bool Rtc_LL_GetModuleState(void)
{
    return (REG_READ(RTC_PTR->RTC_CLKC.bits.DISS));
}

/**
 * @brief 获取RTC模块版本信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetModuleVersion(void)
{
    return (REG_READ(RTC_PTR->RTC_INFO.bits.MODREV));
}

/**
 * @brief 获取RTC模块类型信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetModuleType(void)
{
    return (REG_READ(RTC_PTR->RTC_INFO.bits.MODTYPE));
}

/**
 * @brief 获取RTC模块ID信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetModuleId(void)
{
    return (REG_READ(RTC_PTR->RTC_INFO.bits.MODNUM));
}

/**
 * @brief 设置RTC调试挂起模式
 *
 *
 * @param Mode
 *        RTC_NOSUSPEND
 *        RTC_STOPCOUNTER
 * @retval  void
 */
KF_INLINE void Rtc_LL_SetDebugSuspendMode(Rtc_SuspendMode_t Mode)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_SUSPENDMODE(Mode));

    RTC_DBG_T regValue = {0U};

    regValue.reg       = REG_READ(RTC_PTR->RTC_DBG.reg);
    regValue.bits.SUSP = true;
    regValue.bits.SUS  = Mode;

    REG_WRITE(RTC_PTR->RTC_DBG.reg, regValue.reg);
}

/**
 * @brief 获取RTC调试挂起模式
 *
 *
 * @param void
 * @retval Rtc_SuspendMode_t
 *         RTC_NOSUSPEND
 *         RTC_STOPCOUNTER
 */
KF_INLINE Rtc_SuspendMode_t Rtc_LL_GetDebugSuspendMode(void)
{
    return ((Rtc_SuspendMode_t)REG_READ(RTC_PTR->RTC_DBG.bits.SUS));
}

/**
 * @brief 获取RTC调试挂起状态
 *
 *
 * @param void
 * @retval bool
 *         true: 模块已挂起
 *         false: 模块未挂起
 */
KF_INLINE bool Rtc_LL_GetDebugSuspend(void)
{
    return (REG_READ(RTC_PTR->RTC_DBG.bits.SUSSTA));
}

/**
 * @brief 清零RTC 复位状态
 *
 *
 * @param  bool
 *         true: 清零复位状态
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Rtc_LL_ClearRst(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_RSTCLR.bits.CLR, Status);
}

/**
 * @brief 请求RTC 复位
 *
 *
 * @param  bool
 *         true: 请求模块复位
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Rtc_LL_ResetModule(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_RST0.bits.RST, Status);
    REG_WRITE(RTC_PTR->RTC_RST1.bits.RST, Status);
}

/**
 * @brief 获取RTC复位状态
 *
 *
 * @param void
 * @retval bool
 *          true: 模块已经复位
 *          false: 模块没有复位
 */
KF_INLINE bool Rtc_LL_GetResetState(void)
{
    return (REG_READ(RTC_PTR->RTC_RST0.bits.RSTSTA));
}

/**
 * @brief 使能RTC访问控制
 *
 *
 * @param AccessEnable :具体访问使能通道
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableAccess(Rtc_AccessEnableType_t AccessEnable, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_ACCESSENABLE(AccessEnable));
    REG_BITS_WRITE(RTC_PTR->RTC_ACES0.reg, MASK_1_BIT << AccessEnable, Status << AccessEnable);
}

/**
 * @brief 获取RTC访问状态
 *
 *
 * @param AccessEnable :具体访问使能通道
 * @retval bool
 */
KF_INLINE bool Rtc_LL_GetAccess(Rtc_AccessEnableType_t AccessEnable)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_ACCESSENABLE(AccessEnable));
    return (REG_BITS_READ(RTC_PTR->RTC_ACES0.reg, MASK_1_BIT << AccessEnable, AccessEnable));
}

/**
 * @brief 设置RTC工作状态
 *
 *
 * @param Status
 *         true:使能RTC
 *         false:禁止RTC
 * @retval void
 */
KF_INLINE void Rtc_LL_Enable(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_CTL.bits.EN, Status);
}

/**
 * @brief 获取RTC写操作状态
 *
 *
 * @param void
 * @retval bool
 *          true:上一次对RTC写操作已完成
 *          false:上一次对RTC写操作仍在进行中
 */
KF_INLINE bool Rtc_LL_GetWriteState(void)
{
    return (REG_READ(RTC_PTR->RTC_CTL.bits.RTOFF));
}

/**
 * @brief 设置RTC进入配置模式
 *
 *
 * @param Status
 *         true:进入配置模式
 *         false:退出配置模式
 * @retval void
 */
KF_INLINE void Rtc_LL_SetConfigModeEnabled(const bool Status)
{
    REG_WRITE(RTC_PTR->RTC_CTL.bits.CNF, Status);
}

/**
 * @brief 设置RTC小时显示类型
 *
 *
 * @param Rtc_HourDisplayModeType_t
 *         HOUR_24
 *         HOUR_12
 * @retval void
 */
KF_INLINE void Rtc_LL_SetHourDisplayMode(Rtc_HourDisplayModeType_t HourDisplayMode)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_HOURDISMODE(HourDisplayMode));
    REG_WRITE(RTC_PTR->RTC_CTL.bits.HT, HourDisplayMode);
}

/**
 * @brief 获取RTC闰年指示标志
 *
 *
 * @param void
 * @retval bool
 *          true:当前年份为闰年
 *          false:当前年份为平年
 */
KF_INLINE bool Rtc_LL_GetLeapYearFlag(void)
{
    return (REG_READ(RTC_PTR->RTC_CTL.bits.LIF));
}

/**
 * @brief 获取RTC时钟源分频
 *
 *
 * @param Rtc_ClockSourceDivideType_t
 *         CLOCK_DIVIDE_128
 *         CLOCK_DIVIDE_32
 *         CLOCK_DIVIDE_8
 *         CLOCK_DIVIDE_2
 * @retval void
 */
KF_INLINE void Rtc_LL_SetClockSourceDivide(Rtc_ClockSourceDivideType_t Divide)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_CLOCKSOURCEDIV(Divide));
    REG_WRITE(RTC_PTR->RTC_CTL.bits.CKTP, Divide);
}

/**
 * @brief 使能RTC通道时间戳
 *
 *
 * @param Status
 *         true:使能通道时间戳功能
 *         false:禁止通道时间戳功能
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableTimeStampChannel(const bool Status)
{
    // TODO:如何指定时间戳通道
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_CTL.bits.TSCH, Status);
}

/**
 * @brief 设置RTC工作时钟源
 *
 *
 * @param Rtc_ClockSourceType_t
 *         NO_CLOCK
 *         CDU_CLOCK
 *         ELF_CLOCK
 *         ILF_CLOCK
 * @retval void
 */
KF_INLINE void Rtc_LL_SetClockSource(const Rtc_ClockSourceType_t ClockSource)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_CLOCKSOURCE(ClockSource));
    REG_WRITE(RTC_PTR->RTC_CTL.bits.CLKSEL, ClockSource);
}

/**
 * @brief 设置RTC时间减小一小时
 *
 *
 * @param Status
 *         true:RTC时间减小一小时
 *         false:RTC时间正常计数
 * @retval void
 */
KF_INLINE void Rtc_LL_DecreaseOneHour(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_CTL.bits.SUB1H, Status);
}

/**
 * @brief 设置RTC时间增加一小时
 *
 *
 * @param Status
 *         true:RTC时间增加一小时
 *         false:RTC时间正常计数
 * @retval void
 */
KF_INLINE void Rtc_LL_IncreaseOneHour(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_CTL.bits.ADD1H, Status);
}

/**
 * @brief 使能RTC时间戳
 *
 *
 * @param Status
 *         true:使能时间戳功能
 *         false:禁止时间戳功能
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableTimeStamp(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_CTL.bits.TSEN, Status);
}

/**
 * @brief 设置RTC触发沿类型
 *
 *
 * @param Rtc_TriggerEdgeType_t
 *         POSEDGE_TRIGGER
 *         NEGEDGE_TRIGGER
 * @retval void
 */
KF_INLINE void Rtc_LL_SetTriggerEdge(const Rtc_TriggerEdgeType_t TriggerEdge)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_TRIGGEREDGE(TriggerEdge));
    REG_WRITE(RTC_PTR->RTC_CTL.bits.TSEDGE, TriggerEdge);
}

/**
 * @brief 设置RTC时钟校准值
 *
 *
 * @param Value 校准值
 * @retval void
 */
KF_INLINE void Rtc_LL_SetClkCorrectionValue(const uint8_t Value)
{
    REG_WRITE(RTC_PTR->RTC_CTL.bits.CAL, Value);
}

/**
 * @brief 使能RTC时钟节拍输出唤醒
 *
 *
 * @param Status
 *         true:使能RTC时钟节拍输出唤醒
 *         false:不使能RTC时钟节拍输出唤醒
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableTimerTickWakeup(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_TTCTL.bits.TTWKPEN, Status);
}

/**
 * @brief 使能RTC时钟节拍唤醒分频
 *
 *
 * @param Status
 *         true:使能RTC时钟节拍分频
 *         false:不使能RTC时钟节拍分频
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableTimerTickDivide(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_TTCTL.bits.TTPRESEN, Status);
}

/**
 * @brief 设置RTC时钟节拍唤醒分频
 *
 *
 * @param Rtc_TTOutDivideType_t
 *         TTOUT_DIVIDE_2
 *         TTOUT_DIVIDE_4
 *         TTOUT_DIVIDE_8
 *         TTOUT_DIVIDE_16
 * @retval void
 */
KF_INLINE void Rtc_LL_SetTimerTickDivide(const Rtc_TTOutDivideType_t TTOutDivide)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_TTOUTDIV(TTOutDivide));
    REG_WRITE(RTC_PTR->RTC_TTCTL.bits.TTSEL, TTOutDivide);
}

/**
 * @brief 设置RTC闹钟中断秒时间
 *
 *
 * @param Rtc_AlarmType_t
 *         ALARM_A
 *         ALARM_B
 * @param time:秒时间
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmSecond(const Rtc_AlarmType_t Alarm, const uint32_t time)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_ALARMType(Alarm));
    KF_DRV_RTC_ASSERT((time >> POS_7_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ALRS, time);
}

/**
 * @brief 使能RTC闹钟秒使能
 *
 *
 * @param Rtc_AlarmType_t
 *         ALARM_A
 *         ALARM_B
 * @param Status
 *         true:使能闹钟秒钟位
 *         false:禁止闹钟秒钟位
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableAlarmSecond(const Rtc_AlarmType_t Alarm, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    KF_DRV_RTC_ASSERT(CHECK_RTC_ALARMType(Alarm));
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ASEN, Status);
}

/**
 * @brief 设置RTC闹钟中断分时间
 *
 *
 * @param Rtc_AlarmType_t
 *         ALARM_A
 *         ALARM_B
 * @param time:分时间
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmMinute(const Rtc_AlarmType_t Alarm, const uint32_t time)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_ALARMType(Alarm));
    KF_DRV_RTC_ASSERT((time >> POS_7_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ALRM, time);
}

/**
 * @brief 使能RTC闹钟分使能
 *
 *
 * @param Rtc_AlarmType_t
 *         ALARM_A
 *         ALARM_B
 * @param Status
 *         true:使能闹钟分钟位
 *         false:禁止闹钟分钟位
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableAlarmMinute(const Rtc_AlarmType_t Alarm, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    KF_DRV_RTC_ASSERT(CHECK_RTC_ALARMType(Alarm));
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.AMEN, Status);
}

/**
 * @brief 设置RTC闹钟中断小时时间
 *
 *
 * @param Rtc_AlarmType_t
 *         ALARM_A
 *         ALARM_B
 * @param time:小时时间
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmHour(const Rtc_AlarmType_t Alarm, const uint32_t time)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_ALARMType(Alarm));
    KF_DRV_RTC_ASSERT((time >> POS_6_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ALRH, time);
}

/**
 * @brief 设置RTC闹钟中断小时格式
 *
 *
 * @param Rtc_AlarmType_t
 *         ALARM_A
 *         ALARM_B
 * @param Rtc_HourFormatType_t
 *         HOUR_AM
 *         HOUR_PM
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmHourFormat(const Rtc_AlarmType_t Alarm, const Rtc_HourFormatType_t HourFormat)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_ALARMType(Alarm));
    KF_DRV_RTC_ASSERT(CHECK_RTC_HOURFORMAT(HourFormat));
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.AMPM, HourFormat);
}

/**
 * @brief 使能RTC闹钟小时使能
 *
 *
 * @param Rtc_AlarmType_t
 *         ALARM_A
 *         ALARM_B
 * @param Status
 *         true:使能闹钟小时位
 *         false:禁止闹钟小时位
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableAlarmHour(const Rtc_AlarmType_t Alarm, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    KF_DRV_RTC_ASSERT(CHECK_RTC_ALARMType(Alarm));
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.AHEN, Status);
}

/**
 * @brief 设置RTC闹钟中断小时时间
 *
 *
 * @param Rtc_AlarmType_t
 *         ALARM_A
 *         ALARM_B
 * @param time:周时间
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmWeek(const Rtc_AlarmType_t Alarm, const uint32_t time)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_ALARMType(Alarm));
    KF_DRV_RTC_ASSERT((time >> POS_3_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ALRW, time);
}

/**
 * @brief 使能RTC闹钟周使能
 *
 *
 * @param Rtc_AlarmType_t
 *         ALARM_A
 *         ALARM_B
 * @param Status
 *         true:使能闹钟周位
 *         false:禁止闹钟周位
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableAlarmWeek(const Rtc_AlarmType_t Alarm, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    KF_DRV_RTC_ASSERT(CHECK_RTC_ALARMType(Alarm));
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.AWEN, Status);
}

/**
 * @brief 使能RTC闹钟使能
 *
 *
 * @param Rtc_AlarmType_t
 *         ALARM_A
 *         ALARM_B
 * @param Status
 *         true:使能闹钟
 *         false:禁止闹钟
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableAlarm(const Rtc_AlarmType_t Alarm, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    KF_DRV_RTC_ASSERT(CHECK_RTC_ALARMType(Alarm));
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ALREN, Status);
}

/**
 * @brief 获取RTC时钟秒钟
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetSecond(void)
{
    return (REG_READ(RTC_PTR->RTC_TM.bits.SEC));
}

/**
 * @brief 获取RTC时钟分钟
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetMinute(void)
{
    return (REG_READ(RTC_PTR->RTC_TM.bits.MIN));
}

/**
 * @brief 获取RTC时钟小时
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetHour(void)
{
    return (REG_READ(RTC_PTR->RTC_TM.bits.HOUR));
}

/**
 * @brief 获取RTC时钟小时格式
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetHourFormat(void)
{
    return (REG_READ(RTC_PTR->RTC_TM.bits.AMPM));
}

/**
 * @brief 获取RTC时钟星期
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetWeek(void)
{
    return (REG_READ(RTC_PTR->RTC_TM.bits.WEK));
}

/**
 * @brief 设置RTC时钟秒钟
 *
 *
 * @param  uint32_t
 * @retval void
 */
KF_INLINE void Rtc_LL_SetSecond(const uint32_t Second)
{
    KF_DRV_RTC_ASSERT((Second >> POS_7_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_TM.bits.SEC, Second);
}

/**
 * @brief 设置RTC时钟分钟
 *
 *
 * @param  uint32_t
 * @retval void
 */
KF_INLINE void Rtc_LL_SetMinute(const uint32_t Minute)
{
    KF_DRV_RTC_ASSERT((Minute >> POS_7_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_TM.bits.MIN, Minute);
}

/**
 * @brief 设置RTC时钟小时
 *
 *
 * @param  uint32_t
 * @retval void
 */
KF_INLINE void Rtc_LL_SetHour(const uint32_t Hour)
{
    KF_DRV_RTC_ASSERT((Hour >> POS_6_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_TM.bits.HOUR, Hour);
}

/**
 * @brief 获取RTC时钟分钟
 *
 *
 * @param  Rtc_HourFormatType_t
 *          HOUR_AM
 *          HOUR_PM
 * @retval void
 */
KF_INLINE void Rtc_LL_SetHourFormat(const Rtc_HourFormatType_t HourFormat)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_HOURFORMAT(HourFormat));
    REG_WRITE(RTC_PTR->RTC_TM.bits.AMPM, HourFormat);
}

/**
 * @brief 获取RTC时钟星期
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE void Rtc_LL_SetWeek(const uint32_t Week)
{
    KF_DRV_RTC_ASSERT((Week >> POS_3_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_TM.bits.WEK, Week);
}

/**
 * @brief 获取RTC时钟日期
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetDay(void)
{
    return (REG_READ(RTC_PTR->RTC_DT.bits.DAY));
}

/**
 * @brief 获取RTC时钟月份
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetMonth(void)
{
    return (REG_READ(RTC_PTR->RTC_DT.bits.MTH));
}

/**
 * @brief 获取RTC时钟年份
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetYear(void)
{
    return (REG_READ(RTC_PTR->RTC_DT.bits.YEAR));
}

/**
 * @brief 获取RTC时钟日期
 *
 *
 * @param  uint32_t
 * @retval void
 */
KF_INLINE void Rtc_LL_SetDay(const uint32_t Day)
{
    KF_DRV_RTC_ASSERT((Day >> POS_6_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_DT.bits.DAY, Day);
}

/**
 * @brief 获取RTC时钟月份
 *
 *
 * @param  uint32_t
 * @retval void
 */
KF_INLINE void Rtc_LL_SetMouth(const uint32_t Mouth)
{
    KF_DRV_RTC_ASSERT((Mouth >> POS_5_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_DT.bits.MTH, Mouth);
}

/**
 * @brief 获取RTC时钟年份
 *
 *
 * @param  uint32_t
 * @retval void
 */
KF_INLINE void Rtc_LL_SetYear(const uint32_t Year)
{
    KF_DRV_RTC_ASSERT((Year >> POS_8_SHIFT) == 0U);
    REG_WRITE(RTC_PTR->RTC_DT.bits.YEAR, Year);
}

/**
 * @brief 获取RTC定时器当前计数值
 *
 *
 * @param  Rtc_TimerType_t
 *          TIMER_0
 *          TIMER_1
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetTimerCount(const Rtc_TimerType_t Timer)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_TIMER(Timer));
    return (REG_BITS_READ(RTC_PTR->RTC_TIM.reg, MASK_16_BIT << (POS_16_SHIFT * Timer), POS_16_SHIFT * Timer));
}

/**
 * @brief 设置RTC定时器当前计数值
 *
 *
 * @param  Rtc_TimerType_t
 *          TIMER_0
 *          TIMER_1
 * @param  uint32_t
 * @retval void
 */
KF_INLINE void Rtc_LL_SetTimerCount(const Rtc_TimerType_t Timer, const uint32_t TimerCount)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_TIMER(Timer));
    KF_DRV_RTC_ASSERT((TimerCount >> POS_16_SHIFT) == 0U);
    REG_BITS_WRITE(RTC_PTR->RTC_TIM.reg, MASK_16_BIT << (POS_16_SHIFT * Timer), TimerCount << (POS_16_SHIFT * Timer));
}

/**
 * @brief 设置RTC定时器时钟源
 *
 *
 * @param  Rtc_TimerType_t
 *          TIMER_0
 *          TIMER_1
 * @param  Rtc_TimerClockSourceType_t
 *          SOURCE_DIVIDE_128
 *          SOURCE_DIVIDE_512
 *          SOURCE_DIVIDE_1024
 *          SOURCE_DIVIDE_2048
 *          SOURCE_DIVIDE_8192
 *          SOURCE_1_SECOND
 *          SOURCE_1_MINUTE
 *          SOURCE_1_HOUR
 * @retval void
 */
KF_INLINE void
Rtc_LL_SetTimerClockSource(const Rtc_TimerType_t Timer, const Rtc_TimerClockSourceType_t TimerClockSource)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_TIMER(Timer));
    KF_DRV_RTC_ASSERT(CHECK_RTC_TIMERCLOCKSOURCE(TimerClockSource));
    REG_BITS_WRITE(
      RTC_PTR->RTC_TIMCTL.reg, MASK_4_BIT << (POS_4_SHIFT * Timer), TimerClockSource << (POS_4_SHIFT * Timer));
}

/**
 * @brief 使能RTC定时器
 *
 *
 * @param  Rtc_TimerType_t
 *          TIMER_0
 *          TIMER_1
 * @param  Status
 *          true:使能RTC定时器
 *          false:禁止RTC定时器
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableTimer(const Rtc_TimerType_t Timer, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    KF_DRV_RTC_ASSERT(CHECK_RTC_TIMER(Timer));
    REG_BITS_WRITE(RTC_PTR->RTC_TIMCTL.reg, MASK_1_BIT << (Timer + POS_8_OFFSET), Status << (Timer + POS_8_OFFSET));
}

/**
 * @brief 获取RTC中断标志位
 *
 *
 * @param  Rtc_FlagType_t
 *          SECOND_FLAG
 *          MINUTE_FLAG
 *          HOUR_FLAG
 *          DAY_FLAG
 *          ALARMA_FLAG
 *          ALARMB_FLAG
 *          TIMERTICK_FLAG
 *          TIMER0_FLAG
 *          TIMER1_FLAG
 *          TIMESTAMP_OVERFLOW_FLAG
 *          TIMESTAMP_FLAG
 *          WEEK_FLAG
 *          MOUTH_FLAG
 *          YEAR_FLAG
 * @retval bool
 *          true:相应标志位置位
 *          false:相应标志位未置位
 */
KF_INLINE bool Rtc_LL_GetFlag(const Rtc_FlagType_t Flag)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_FLAG(Flag));
    return (REG_BITS_READ(RTC_PTR->RTC_IF.reg, MASK_1_BIT << Flag, Flag));
}

/**
 * @brief 清零RTC中断标志位
 *
 *
 * @param  Rtc_IntType_t
 *          SECOND_FLAG
 *          MINUTE_FLAG
 *          HOUR_FLAG
 *          DAY_FLAG
 *          ALARMA_FLAG
 *          ALARMB_FLAG
 *          TIMERTICK_FLAG
 *          TIMER0_FLAG
 *          TIMER1_FLAG
 *          TIMESTAMP_OVERFLOW_FLAG
 *          TIMESTAMP_FLAG
 *          WEEK_FLAG
 *          MOUTH_FLAG
 *          YEAR_FLAG
 * @param  Status
 *          true:清零相应中断标志位
 *          false:不清零相应中断标志位
 * @retval void
 */
KF_INLINE void Rtc_LL_ClearFlag(const Rtc_FlagType_t Flag, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    KF_DRV_RTC_ASSERT(CHECK_RTC_FLAG(Flag));
    REG_BITS_WRITE(RTC_PTR->RTC_IC.reg, MASK_1_BIT << Flag, Status << Flag);
}

/**
 * @brief 置一RTC中断标志位
 *
 *
 * @param  Rtc_IntType_t
 *          SECOND_FLAG
 *          MINUTE_FLAG
 *          HOUR_FLAG
 *          DAY_FLAG
 *          ALARMA_FLAG
 *          ALARMB_FLAG
 *          TIMERTICK_FLAG
 *          TIMER0_FLAG
 *          TIMER1_FLAG
 *          TIMESTAMP_OVERFLOW_FLAG
 *          TIMESTAMP_FLAG
 *          WEEK_FLAG
 *          MOUTH_FLAG
 *          YEAR_FLAG
 * @param  Status
 *          true:置一相应中断标志位
 *          false:无操作
 * @retval void
 */
KF_INLINE void Rtc_LL_SetFlag(const Rtc_FlagType_t Flag, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    KF_DRV_RTC_ASSERT(CHECK_RTC_FLAG(Flag));
    REG_BITS_WRITE(RTC_PTR->RTC_IS.reg, MASK_1_BIT << Flag, Status << Flag);
}

/**
 * @brief 获取RTC时钟秒钟备份
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetBackUpSecond(void)
{
    return (REG_READ(RTC_PTR->RTC_TMB.bits.SECB));
}

/**
 * @brief 获取RTC时钟分钟备份
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetBackUpMinute(void)
{
    return (REG_READ(RTC_PTR->RTC_TMB.bits.MINB));
}

/**
 *
 * @brief 获取RTC时钟小时备份
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetBackUpHour(void)
{
    return (REG_READ(RTC_PTR->RTC_TMB.bits.HOURB));
}

/**
 *
 * @brief 获取RTC时钟小时备份
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetBackUpHourFormat(void)
{
    return (REG_READ(RTC_PTR->RTC_TMB.bits.AMPMB));
}

/**
 *
 * @brief 获取RTC时钟星期备份
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetBackUpWeek(void)
{
    return (REG_READ(RTC_PTR->RTC_TMB.bits.WEKB));
}

/**
 *
 * @brief 获取RTC时钟日期备份
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetBackUpDay(void)
{
    return (REG_READ(RTC_PTR->RTC_DTB.bits.DAYB));
}

/**
 *
 * @brief 获取RTC时钟月份备份
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetBackUpMouth(void)
{
    return (REG_READ(RTC_PTR->RTC_DTB.bits.MTHB));
}

/**
 *
 * @brief 获取RTC时钟年份备份
 *
 *
 * @param  void
 * @retval uint32_t
 */
KF_INLINE uint32_t Rtc_LL_GetBackUpYear(void)
{
    return (REG_READ(RTC_PTR->RTC_DTB.bits.YEARB));
}

/**
 *
 * @brief 设置RTC快速测试
 *
 *
 * @param  bool
 *          true:使能快递测试
 *          false:禁止快速测试
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableFastTest(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_FASTEST.bits.FASTTESTEN, Status);
}

/**
 *
 * @brief 设置RTC具体功能快速测试
 *
 *
 * @param  Rtc_FastTestEnType_t
 *          MINTESTEN
 *          HOURTESTEN
 *          DAYTESTEN
 *          WEEKTESTEN
 *          MONTHTESTEN
 *          YEARTESTEN
 * @param  bool
 *          true:使能相应功能快速测试
 *          false:禁止相应功能快速测试
 * @retval void
 */
KF_INLINE void Rtc_LL_SetEnableFast(Rtc_FastTestEnType_t FastTestEn, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    KF_DRV_RTC_ASSERT(CHECK_RTC_FASTTESTEN(FastTestEn));
    REG_BITS_WRITE(RTC_PTR->RTC_FASTEST.reg, MASK_1_BIT << FastTestEn, Status << FastTestEn);
}

/**
 *
 * @brief 设置RTC时钟分频
 *
 *
 * @param  uint32_t
 * @retval void
 */
KF_INLINE void Rtc_LL_SetClockPrescale(const uint32_t Prescale)
{
    REG_WRITE(RTC_PTR->RTC_CLKDIV.reg, Prescale);
}

/**
 *
 * @brief 使能RTC工作时钟测试
 *
 *
 * @param  bool
 *          true:使能RTC工作时钟测试
 *          false:禁止RTC工作时钟测试
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableClockTest(const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    REG_WRITE(RTC_PTR->RTC_CLKTEST.bits.CLKTESTEN, Status);
}

/**
 * @brief 设置RTC时钟时间节拍
 *
 *
 * @param RTC_TTType_t
 *                TT_SECOND_1
 *                TT_SECOND_1_2
 *                TT_SECOND_1_4
 *                TT_SECOND_1_8
 *                TT_SECOND_1_16
 *                TT_SECOND_1_32
 *                TT_SECOND_1_64
 *                TT_SECOND_1_128
 * @retval void
 */
KF_INLINE void Rtc_LL_SetTickTime(const Rtc_TTType_t Tick)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_TTType(Tick));
    REG_WRITE(RTC_PTR->RTC_TTCTL.bits.TT, Tick);
}

/**
 * @brief 使能RTC中断
 *
 *
 * @param  Rtc_IntType_t
 *          SECOND_FLAG
 *          MINUTE_FLAG
 *          HOUR_FLAG
 *          DAY_FLAG
 *          ALARMA_FLAG
 *          ALARMB_FLAG
 *          TIMERTICK_FLAG
 *          TIMER0_FLAG
 *          TIMER1_FLAG
 *          TIMESTAMP_OVERFLOW_FLAG
 *          TIMESTAMP_FLAG
 *          WEEK_FLAG
 *          MOUTH_FLAG
 *          YEAR_FLAG
 * @param  Status
 *          true:使能中断
 *          false:禁止中断
 * @retval void
 */
KF_INLINE void Rtc_LL_SetIntrEnabled(const Rtc_FlagType_t Flag, const bool Status)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_BOOL(Status));
    KF_DRV_RTC_ASSERT(CHECK_RTC_FLAG(Flag));
    REG_BITS_WRITE(RTC_PTR->RTC_IE.reg, MASK_1_BIT << Flag, Status << Flag);
}

/**
 * @brief 使能RTC测试模式
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Rtc_LL_EnableTestMode(void)
{
    REG_WRITE(RTC_PTR->RTC_TMODE.bits.TMEN, true);
}

/**
 * @brief 选择RTC测试模式输出
 *
 *
 * @param Output 测试模式输出
 * @retval void
 */
KF_INLINE void Rtc_LL_SetTestModeOutput(const Rtc_TestModeOutput_t Output)
{
    KF_DRV_RTC_ASSERT(CHECK_RTC_TEST_MODE_OUTPUT(Output));

    REG_WRITE(RTC_PTR->RTC_TMODE.bits.TMSEL, Output);
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
