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
#ifdef SIMULATION

#include "kf32a13k_reg_simulation_rtc.h"
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CLKC_ADDR);
    regValue &= ~HWIO_RTC_CLKC_RTC_CLKC_DISR_MASK;
    regValue |= Status << HWIO_RTC_CLKC_RTC_CLKC_DISR_SHFT;
    REG_WRITE(HWIO_RTC_CLKC_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CLKC.bits.DISR, Status);
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_CLKC.bits.DISS));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_INFO.bits.MODREV));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_INFO.bits.MODTYPE));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_INFO.bits.MODNUM));
#endif
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
#ifdef SIMULATION
    regValue.reg       = REG_READ(HWIO_RTC_DBG_ADDR);
    regValue.bits.SUSP = true;
    regValue.bits.SUS  = Mode;
    REG_WRITE(HWIO_RTC_DBG_ADDR, regValue.reg);
    // TODO: check if correct

#else
    regValue.reg       = REG_READ(RTC_PTR->RTC_DBG.reg);
    regValue.bits.SUSP = true;
    regValue.bits.SUS  = Mode;

    REG_WRITE(RTC_PTR->RTC_DBG.reg, regValue.reg);
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return ((Rtc_SuspendMode_t)REG_READ(RTC_PTR->RTC_DBG.bits.SUS));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_DBG.bits.SUSSTA));
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_RSTCLR_ADDR);
    regValue &= ~HWIO_RTC_RSTCLR_RTC_RSTCLR_CLR_MASK;
    regValue |= Status << HWIO_RTC_RSTCLR_RTC_RSTCLR_CLR_SHFT;
    REG_WRITE(HWIO_RTC_RSTCLR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_RSTCLR.bits.CLR, Status);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_RST0_ADDR);
    regValue &= ~HWIO_RTC_RST0_RTC_RST0_RST_MASK;
    regValue |= Status << HWIO_RTC_RST0_RTC_RST0_RST_SHFT;
    REG_WRITE(HWIO_RTC_RST0_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_RST0.bits.RST, Status);
#endif
#ifdef SIMULATION
    regValue = REG_READ(HWIO_RTC_RST1_ADDR);
    regValue &= ~HWIO_RTC_RST1_RTC_RST1_RST_MASK;
    regValue |= Status << HWIO_RTC_RST1_RTC_RST1_RST_SHFT;
    REG_WRITE(HWIO_RTC_RST1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_RST1.bits.RST, Status);
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_RST0.bits.RSTSTA));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    REG_BITS_WRITE(RTC_PTR->RTC_ACES0.reg, MASK_1_BIT << AccessEnable, Status << AccessEnable);
#endif
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
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_RTC_ACES0_ADDR, MASK_1_BIT << AccessEnable, AccessEnable));
    // TODO: check if correct

#else
    return (REG_BITS_READ(RTC_PTR->RTC_ACES0.reg, MASK_1_BIT << AccessEnable, AccessEnable));
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_EN_MASK;
    regValue |= Status << HWIO_RTC_CTL_RTC_CTL_EN_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.EN, Status);
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_CTL.bits.RTOFF));
#endif
}

/**
 * @brief 设置RTC进入配置模式
 *
 *
 * @param Status
 *         true:进入配置模式
 */
KF_INLINE void Rtc_LL_SetConfigModeEnabled(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_CNF_MASK;
    regValue |= true << HWIO_RTC_CTL_RTC_CTL_CNF_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.CNF, Status);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_HT_MASK;
    regValue |= HourDisplayMode << HWIO_RTC_CTL_RTC_CTL_HT_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.HT, HourDisplayMode);
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_CTL.bits.LIF));
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_CKTP_MASK;
    regValue |= Divide << HWIO_RTC_CTL_RTC_CTL_CKTP_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.CKTP, Divide);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_TSCH0_MASK;
    regValue |= Status << HWIO_RTC_CTL_RTC_CTL_TSCH0_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.TSCH, Status);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_CLKSEL_MASK;
    regValue |= ClockSource << HWIO_RTC_CTL_RTC_CTL_CLKSEL_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.CLKSEL, ClockSource);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_SUB1H_MASK;
    regValue |= Status << HWIO_RTC_CTL_RTC_CTL_SUB1H_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.SUB1H, Status);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_ADD1H_MASK;
    regValue |= Status << HWIO_RTC_CTL_RTC_CTL_ADD1H_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.ADD1H, Status);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_TSEN_MASK;
    regValue |= Status << HWIO_RTC_CTL_RTC_CTL_TSEN_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.TSEN, Status);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_TSEDGE_MASK;
    regValue |= TriggerEdge << HWIO_RTC_CTL_RTC_CTL_TSEDGE_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.TSEDGE, TriggerEdge);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CTL_ADDR);
    regValue &= ~HWIO_RTC_CTL_RTC_CTL_CAL_MASK;
    regValue |= Value << HWIO_RTC_CTL_RTC_CTL_CAL_SHFT;
    REG_WRITE(HWIO_RTC_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CTL.bits.CAL, Value);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_TTCTL_ADDR);
    regValue &= ~HWIO_RTC_TTCTL_RTC_TTCTL_TTWKPEN_MASK;
    regValue |= Status << HWIO_RTC_TTCTL_RTC_TTCTL_TTWKPEN_SHFT;
    REG_WRITE(HWIO_RTC_TTCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_TTCTL.bits.TTWKPEN, Status);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_TTCTL_ADDR);
    regValue &= ~HWIO_RTC_TTCTL_RTC_TTCTL_TTPRESEN_MASK;
    regValue |= Status << HWIO_RTC_TTCTL_RTC_TTCTL_TTPRESEN_SHFT;
    REG_WRITE(HWIO_RTC_TTCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_TTCTL.bits.TTPRESEN, Status);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_TTCTL_ADDR);
    regValue &= ~HWIO_RTC_TTCTL_RTC_TTCTL_TTSEL_MASK;
    regValue |= TTOutDivide << HWIO_RTC_TTCTL_RTC_TTCTL_TTSEL_SHFT;
    REG_WRITE(HWIO_RTC_TTCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_TTCTL.bits.TTSEL, TTOutDivide);
#endif
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
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ALRS, time);
#endif
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
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ASEN, Status);
#endif
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
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ALRM, time);
#endif
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
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.AMEN, Status);
#endif
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
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ALRH, time);
#endif
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
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.AMPM, HourFormat);
#endif
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
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.AHEN, Status);
#endif
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
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ALRW, time);
#endif
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
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.AWEN, Status);
#endif
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
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(RTC_PTR->RTC_ALR[Alarm].bits.ALREN, Status);
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_TM.bits.SEC));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_TM.bits.MIN));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_TM.bits.HOUR));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_TM.bits.AMPM));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_TM.bits.WEK));
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_TM_ADDR);
    regValue &= ~HWIO_RTC_TM_RTC_TM_SEC_MASK;
    regValue |= Second << HWIO_RTC_TM_RTC_TM_SEC_SHFT;
    REG_WRITE(HWIO_RTC_TM_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_TM.bits.SEC, Second);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_TM_ADDR);
    regValue &= ~HWIO_RTC_TM_RTC_TM_MIN_MASK;
    regValue |= Minute << HWIO_RTC_TM_RTC_TM_MIN_SHFT;
    REG_WRITE(HWIO_RTC_TM_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_TM.bits.MIN, Minute);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_TM_ADDR);
    regValue &= ~HWIO_RTC_TM_RTC_TM_HOUR_MASK;
    regValue |= Hour << HWIO_RTC_TM_RTC_TM_HOUR_SHFT;
    REG_WRITE(HWIO_RTC_TM_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_TM.bits.HOUR, Hour);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_TM_ADDR);
    regValue &= ~HWIO_RTC_TM_RTC_TM_AMPM_MASK;
    regValue |= HourFormat << HWIO_RTC_TM_RTC_TM_AMPM_SHFT;
    REG_WRITE(HWIO_RTC_TM_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_TM.bits.AMPM, HourFormat);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_TM_ADDR);
    regValue &= ~HWIO_RTC_TM_RTC_TM_WEK_MASK;
    regValue |= Week << HWIO_RTC_TM_RTC_TM_WEK_SHFT;
    REG_WRITE(HWIO_RTC_TM_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_TM.bits.WEK, Week);
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_DT.bits.DAY));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_DT.bits.MTH));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_DT.bits.YEAR));
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_INFO_RTC_INFO_MODTYPE_MASK);
    regValue &= ~HWIO_RTC_DT_RTC_DT_DAY_MASK;
    regValue |= Day << HWIO_RTC_DT_RTC_DT_DAY_SHFT;
    REG_WRITE(HWIO_RTC_INFO_RTC_INFO_MODTYPE_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_DT.bits.DAY, Day);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_INFO_RTC_INFO_MODTYPE_MASK);
    regValue &= ~HWIO_RTC_DT_RTC_DT_MTH_MASK;
    regValue |= Mouth << HWIO_RTC_DT_RTC_DT_MTH_SHFT;
    REG_WRITE(HWIO_RTC_INFO_RTC_INFO_MODTYPE_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_DT.bits.MTH, Mouth);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_INFO_RTC_INFO_MODTYPE_MASK);
    regValue &= ~HWIO_RTC_DT_RTC_DT_YEAR_MASK;
    regValue |= Year << HWIO_RTC_DT_RTC_DT_YEAR_SHFT;
    REG_WRITE(HWIO_RTC_INFO_RTC_INFO_MODTYPE_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_DT.bits.YEAR, Year);
#endif
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
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_RTC_TIM_ADDR, MASK_16_BIT << (POS_16_SHIFT * Timer), POS_16_SHIFT * Timer));
    // TODO: check if correct

#else
    return (REG_BITS_READ(RTC_PTR->RTC_TIM.reg, MASK_16_BIT << (POS_16_SHIFT * Timer), POS_16_SHIFT * Timer));
#endif
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
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_RTC_TIM_ADDR, MASK_16_BIT << (POS_16_SHIFT * Timer), TimerCount << (POS_16_SHIFT * Timer));
    // TODO: check if correct

#else
    REG_BITS_WRITE(RTC_PTR->RTC_TIM.reg, MASK_16_BIT << (POS_16_SHIFT * Timer), TimerCount << (POS_16_SHIFT * Timer));
#endif
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
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_RTC_TIM_ADDR, MASK_4_BIT << (POS_4_SHIFT * Timer),
                   TimerClockSource << (POS_4_SHIFT * Timer)); // TODO: check if correct

#else
    REG_BITS_WRITE(
      RTC_PTR->RTC_TIMCTL.reg, MASK_4_BIT << (POS_4_SHIFT * Timer), TimerClockSource << (POS_4_SHIFT * Timer));
#endif
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
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_RTC_TIM_ADDR, MASK_1_BIT << (Timer + POS_8_OFFSET), Status << (Timer + POS_8_OFFSET));
    // TODO: check if correct

#else
    REG_BITS_WRITE(RTC_PTR->RTC_TIMCTL.reg, MASK_1_BIT << (Timer + POS_8_OFFSET), Status << (Timer + POS_8_OFFSET));
#endif
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
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_RTC_CTL_RTC_CTL_LIF_MASK, MASK_1_BIT << Flag, Flag));
    // TODO: check if correct

#else
    return (REG_BITS_READ(RTC_PTR->RTC_IF.reg, MASK_1_BIT << Flag, Flag));
#endif
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
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_RTC_IC_ADDR, MASK_1_BIT << Flag, Status << Flag);
    // TODO: check if correct

#else
    REG_BITS_WRITE(RTC_PTR->RTC_IC.reg, MASK_1_BIT << Flag, Status << Flag);
#endif
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
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_RTC_CLKC_RTC_CLKC_DISR_MASK, MASK_1_BIT << Flag, Status << Flag);
    // TODO: check if correct

#else
    REG_BITS_WRITE(RTC_PTR->RTC_IS.reg, MASK_1_BIT << Flag, Status << Flag);
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_TMB.bits.SECB));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_TMB.bits.MINB));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_TMB.bits.HOURB));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_TMB.bits.AMPMB));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_TMB.bits.WEKB));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_DTB.bits.DAYB));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_DTB.bits.MTHB));
#endif
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
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(RTC_PTR->RTC_DTB.bits.YEARB));
#endif
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
#ifdef SIMULATION
// TODO: Error: cannot findRTC_FASTEST the correct register name please correct
#else
    REG_WRITE(RTC_PTR->RTC_FASTEST.bits.FASTTESTEN, Status);
#endif
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
#ifdef SIMULATION
// TODO: Error: cannot findRTC_FASTEST the correct register name please correct
#else
    REG_BITS_WRITE(RTC_PTR->RTC_FASTEST.reg, MASK_1_BIT << FastTestEn, Status << FastTestEn);
#endif
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
#ifdef SIMULATION
    REG_WRITE(HWIO_RTC_CLKDIV_ADDR, Prescale);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CLKDIV.reg, Prescale);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_CLKTEST_ADDR);
    regValue &= ~HWIO_RTC_CLKTEST_RTC_CLKTEST_CLKTESTEN_MASK;
    regValue |= Status << HWIO_RTC_CLKTEST_RTC_CLKTEST_CLKTESTEN_SHFT;
    REG_WRITE(HWIO_RTC_CLKTEST_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_CLKTEST.bits.CLKTESTEN, Status);
#endif
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
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RTC_TTCTL_ADDR);
    regValue &= ~HWIO_RTC_TTCTL_RTC_TTCTL_TTWKPEN_MASK;
    regValue |= Tick << HWIO_RTC_TTCTL_RTC_TTCTL_TTWKPEN_SHFT;
    REG_WRITE(HWIO_RTC_TTCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(RTC_PTR->RTC_TTCTL.bits.TT, Tick);
#endif
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
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_RTC_IE_ADDR, MASK_1_BIT << Flag, Status << Flag);
    // TODO: check if correct

#else
    REG_BITS_WRITE(RTC_PTR->RTC_IE.reg, MASK_1_BIT << Flag, Status << Flag);
#endif
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
