/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_qei.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-25
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
 *  |2023-12-27  |V1.0     |Zhang Quanzhen  | New Creat
 *****************************************************************************/
#ifndef KF32A1x8_DRV_QEI_H_
#define KF32A1x8_DRV_QEI_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_qei.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_QEI_ASSERT
#include "dev_assert.h"
#define KF_DRV_QEI_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_QEI_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    QEI_NOSUSPEND   = 0U,
    QEI_STOPCOUNTER = 2U
} Qei_SuspendMode_t;

#define CHECK_QEI_SUSPENDMODE(Mode)   (Mode == QEI_NOSUSPEND) ||(Mode == ModeQEI_STOPCOUNTER))

typedef enum
{
    QEI_ACCESS_ENABLE_0,
    QEI_ACCESS_ENABLE_1,
    QEI_ACCESS_ENABLE_2,
    QEI_ACCESS_ENABLE_3,
    QEI_ACCESS_ENABLE_4,
    QEI_ACCESS_ENABLE_5,
    QEI_ACCESS_ENABLE_6,
    QEI_ACCESS_ENABLE_7,
    QEI_ACCESS_ENABLE_8,
    QEI_ACCESS_ENABLE_9,
    QEI_ACCESS_ENABLE_10,
    QEI_ACCESS_ENABLE_11,
    QEI_ACCESS_ENABLE_12,
    QEI_ACCESS_ENABLE_13,
    QEI_ACCESS_ENABLE_14,
    QEI_ACCESS_ENABLE_15,
    QEI_ACCESS_ENABLE_16,
    QEI_ACCESS_ENABLE_17,
    QEI_ACCESS_ENABLE_18,
    QEI_ACCESS_ENABLE_19,
    QEI_ACCESS_ENABLE_20,
    QEI_ACCESS_ENABLE_21,
    QEI_ACCESS_ENABLE_22,
    QEI_ACCESS_ENABLE_23,
    QEI_ACCESS_ENABLE_24,
    QEI_ACCESS_ENABLE_25,
    QEI_ACCESS_ENABLE_26,
    QEI_ACCESS_ENABLE_27,
    QEI_ACCESS_ENABLE_28,
    QEI_ACCESS_ENABLE_29,
    QEI_ACCESS_ENABLE_30,
    QEI_ACCESS_ENABLE_31
} Qei_AccessEnableType_t;

#define CHECK_QEI_ACCESSENABLE(AccessEnable) ((AccessEnable >> POS_5_SHIFT) == 0U)

typedef enum
{
    /* 1:1 分频*/
    QEI_PRESCALE_1,
    /* 1:2 分频*/
    QEI_PRESCALE_2,
    /* 1:4 分频*/
    QEI_PRESCALE_4,
    /* 1:8 分频*/
    QEI_PRESCALE_8,
    /* 1:16 分频*/
    QEI_PRESCALE_16,
    /* 1:32 分频*/
    QEI_PRESCALE_32,
    /* 1:64 分频*/
    QEI_PRESCALE_64,
    /* 1:128 分频*/
    QEI_PRESCALE_128,
} Qei_PrescaleType_t;

#define CHECK_QEI_ACCESSENABLE(Prescale) ((Prescale >> POS_3_SHIFT) == 0U)

typedef enum
{
    LPCLK_INLTF,
    LPCLK_RESERVED
} Qei_LPClockSourceType_t;

#define CHECK_QEI_LPCLKSOURCE(ClkSource) ((ClkSource == LPCLK_INLTF) || (ClkSource == LPCLK_RESERVED))

typedef enum
{
    CLK_TMR,
    CLK_SPB,
    CLK_RESERVED,
    CLK_LPCLK
} Qei_ClockSourceType_t;

#define CHECK_QEI_CLKSOURCE(ClkSource)                                                                                 \
    ((ClkSource == CLK_TMR) || (ClkSource == CLK_SPB) || (ClkSource == CLK_RESERVED) || (ClkSource == CLK_LPCLK))

typedef enum
{
    TIMER_UPCOUNT,
    TIMER_DOWNCOUNT,
    COUNTER_UPCOUNT,
    COUNTER_DOWNCOUNT,
    QEIX2_INDEXRESET,
    QEIX2_PPXRESET,
    QEIX4_INDEXRESET,
    QEIX4_PPXRESET
} Qei_ModeType_t;

#define CHECK_QEI_MODE(Mode) ((Mode >> POS_3_SHIFT) == 0U)

typedef enum
{
    INDEXSTATE_LOW,
    INDEXSTATE_HIGH
} Qei_IndexStateType_t;

#define CHECK_QEI_INDEXSTATE(State) ((State == INDEXSTATE_LOW) || (State == INDEXSTATE_HIGH))

typedef enum
{
    POS_COUNTDOWN,
    POS_COUNTUP
} Qei_PosDirectionType_t;

#define CHECK_QEI_POSDIR(Direction) ((Direction == POS_COUNTDOWN) || (Direction == POS_COUNTUP))

typedef enum
{
    COUNTERROR_FLAG,
    PHASEERROR_FLAG,
    OVERFLOW_FLAG
} Qei_FlagType_t;

#define CHECK_QEI_FLAG(Flag) ((Flag == COUNTERROR_FLAG) || (Flag == PHASEERROR_FLAG) || (Flag == OVERFLOW_FLAG))

typedef enum
{
    COUNTERROR_INT,
    PHASEERROR_INT,
    OVERFLOW_INT
} Qei_IntType_t;

#define CHECK_QEI_INT(Int) ((Int == COUNTERROR_INT) || (Int == PHASEERROR_INT) || (Int == OVERFLOW_INT))

#define CHECK_QEI_BOOL(Bool)     ((Bool >> POS_1_SHIFT) == 0U)
#define CHECK_QEI_MODULE(Module) ((Module == QEI0_PTR) || (Module == QEI1_PTR) || (Module == QEI2_PTR))
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 禁止QEI模块
 *
 *
 * @param Module
 * @param Status
 *        true:禁止模块
 *        false:无操作
 * @retval void
 */
KF_INLINE void Qei_LL_DisableQEI(Qei_RegisterMap_t *const Module, bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_CLKC.bits.DISR, Status);
}

/**
 * @brief 获取QEI模块状态
 *
 *
 * @param Module
 * @param void
 * @retval bool
 *         true:模块已禁止
 *         false:模块已使能
 */
KF_INLINE bool Qei_LL_GetModuleState(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_READ(Module->QEI_CLKC.bits.DISS));
}

/**
 * @brief 设置QEI模块睡眠状态
 *
 *
 * @param Module
 * @param Status
 *         true:使能睡眠模式
 *         false:禁止睡眠模式
 * @retval void
 */
KF_INLINE void Qei_LL_EnableSleepMode(Qei_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_CLKC.bits.EDIS, Status);
}

/**
 * @brief 设置QEI模块睡眠状态
 *
 *
 * @param Module
 * @retval Status
 *         true:模块未进入睡眠模式
 *         false:模块进入睡眠模式
 */
KF_INLINE bool Qei_LL_GetSleepMode(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_READ(Module->QEI_CLKC.bits.EDIS));
}

/**
 * @brief 获取QEI模块版本信息
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Qei_LL_GetModuleVersion(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_READ(Module->QEI_INFO.bits.MODREV));
}

/**
 * @brief 获取QEI模块类型信息
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Qei_LL_GetModuleType(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_READ(Module->QEI_INFO.bits.MODTYPE));
}

/**
 * @brief 获取QEI模块ID信息
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Qei_LL_GetModuleId(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_READ(Module->QEI_INFO.bits.MODNUM));
}

/**
 * @brief 设置QEI调试挂起模式
 *
 *
 * @param Module
 * @param Mode
 *        QEI_NOSUSPEND
 *        QEI_STOPCOUNTER
 * @retval  void
 */
KF_INLINE void Qei_LL_SetDebugSuspendMode(Qei_RegisterMap_t *const Module, Qei_SuspendMode_t Mode)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    KF_DRV_QEI_ASSERT(CHECK_QEI_SUSPENDMODE(Mode));
    REG_WRITE(Module->QEI_DBG.bits.SUSP, true);
    REG_WRITE(Module->QEI_DBG.bits.SUS, Mode);
    REG_WRITE(Module->QEI_DBG.bits.SUSP, false);
}

/**
 * @brief 获取QEI调试挂起模式
 *
 *
 * @param Module
 * @retval Qei_SuspendMode_t
 *         QEI_NOSUSPEND
 *         QEI_STOPCOUNTER
 */
KF_INLINE Qei_SuspendMode_t Qei_LL_GetDebugSuspendMode(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return ((Qei_SuspendMode_t)REG_READ(Module->QEI_DBG.bits.SUS));
}

/**
 * @brief 获取QEI调试挂起状态
 *
 *
 * @param Module
 * @retval bool
 *         true: 模块已挂起
 *         false: 模块未挂起
 */
KF_INLINE bool Qei_LL_GetDebugSuspend(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_READ(Module->QEI_DBG.bits.SUSSTA));
}

/**
 * @brief 清零QEI 复位状态
 *
 *
 * @param  Module
 * @param  bool
 *         true: 清零复位状态
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Qei_LL_ClearRst(Qei_RegisterMap_t *const Module, bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_RSTCLR.bits.CLR, Status);
}

/**
 * @brief 请求QEI 复位
 *
 *
 * @param  Module
 * @param  bool
 *         true: 请求模块复位
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Qei_LL_ResetModule(Qei_RegisterMap_t *const Module, bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_RST0.bits.RST, Status);
    REG_WRITE(Module->QEI_RST1.bits.RST, Status);
}

/**
 * @brief 获取QEI复位状态
 *
 *
 * @param Module
 * @ retval bool
 *          true: 模块已经复位
 *          false: 模块没有复位
 */
KF_INLINE bool Qei_LL_GetResetState(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_READ(Module->QEI_RST0.bits.RSTSTA));
}

/**
 * @brief 使能QEI访问控制
 *
 *
 * @param Module
 * @param AccessEnable :具体访问使能通道
 * @retval void
 */
KF_INLINE void Qei_LL_EnableAccess(Qei_RegisterMap_t *const Module, Qei_AccessEnableType_t AccessEnable)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    KF_DRV_QEI_ASSERT(CHECK_QEI_ACCESSEMABLE(AccessEnable));
    REG_BIT_SET(Module->QEI_ACES0.reg, MASK_1_BIT << AccessEnable);
}

/**
 * @brief 获取QEI访问状态
 *
 *
 * @param Module
 * @param AccessEnable :具体访问使能通道
 * @retval bool
 */
KF_INLINE bool Qei_LL_GetAccess(Qei_RegisterMap_t *const Module, Qei_AccessEnableType_t AccessEnable)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    KF_DRV_QEI_ASSERT(CHECK_QEI_ACCESSEMABLE(AccessEnable));
    return (REG_BITS_READ(Module->QEI_ACES0.reg, MASK_1_BIT << AccessEnable, AccessEnable));
}

/**
 * @brief 设置QEI低功耗时钟源
 *
 *
 * @param Module
 * @param Qei_LPClockSourceType_t
 *        LPCLK_INLTF
 *        LPCLK_RESERVED
 * @retval void
 */
KF_INLINE void Qei_LL_SetLpClkSource(Qei_RegisterMap_t *const Module, const Qei_LPClockSourceType_t ClockSource)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    KF_DRV_QEI_ASSERT(CHECK_QEI_LPCLKSOURCE(ClockSource));
    REG_WRITE(Module->QEI_CTL.bits.LPCLK, ClockSource);
}

/**
 * @brief 设置QEI工作时钟时钟源
 *
 *
 * @param Module
 * @param Qei_ClockSourceType_t
 *        CLK_TMR
 *        CLK_SPB
 *        CLK_RESERVED
 *        CLK_LPCLK
 * @retval void
 */
KF_INLINE void Qei_LL_SetClkSource(Qei_RegisterMap_t *const Module, const Qei_ClockSourceType_t ClockSource)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    KF_DRV_QEI_ASSERT(CHECK_QEI_CLKSOURCE(ClockSource));
    REG_WRITE(Module->QEI_CTL.bits.QEICLK, ClockSource);
}

/**
 * @brief 设置QEI工作模式
 *
 *
 * @param Module
 * @param Qei_ModeType_t
 *        TIMER_UPCOUNT
 *        TIMER_DOWNCOUNT
 *        COUNTER_UPCOUNT
 *        COUNTER_DOWNCOUNT
 *        QEIX2_INDEXRESET
 *        QEIX2_PPXRESET
 *        QEIX4_INDEXRESET
 *        QEIX4_PPXRESET
 * @retval void
 */
KF_INLINE void Qei_LL_SetMode(Qei_RegisterMap_t *const Module, const Qei_ModeType_t Mode)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODE(Mode));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_CTL.bits.QEIMOD, Mode);
}

/**
 * @brief 使能QEI位置计数器复位
 *
 *
 * @param Module
 * @param bool
 *        true:索引脉冲复位位置计数器
 *        false:索引脉冲不复位位置计数器
 * @retval void
 */
KF_INLINE void Qei_LL_EnablePulseResetPosCounter(Qei_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_CTL.bits.INDRES, Status);
}

/**
 * @brief 使能QEI计数方向输出
 *
 *
 * @param Module
 * @param bool
 *        true:使能计数方向DIR输出
 *        false:禁止计数方向DIR输出
 * @retval void
 */
KF_INLINE void Qei_LL_EnableCountDirectionOutPut(Qei_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_CTL.bits.DIROUT, Status);
}

/**
 * @brief 使能QEI模块
 *
 *
 * @param Module
 * @param bool
 *        true:使能QEI模块，开始计数
 *        false:禁止QEI模块，暂停计数
 * @retval void
 */
KF_INLINE void Qei_LL_EnableQEI(Qei_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_CTL.bits.EN, Status);
}

/**
 * @brief 设置QEI A相和B相输入交换选择
 *
 *
 * @param Module
 * @param bool
 *        true:A相和B相输入交换
 *        false:A相和B相不交换
 * @retval void
 */
KF_INLINE void Qei_LL_SwapAB(Qei_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_FLTCTL.bits.SWPAB, Status);
}

/**
 * @brief 使能QEI 数字滤波器
 *
 *
 * @param Module
 * @param bool
 *        true:使能滤波功能
 *        false:禁止滤波功能
 * @retval void
 */
KF_INLINE void Qei_LL_EnableFilter(Qei_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_FLTCTL.bits.FLTEN, Status);
}

/**
 * @brief 使能QEI 数字滤波器
 *
 *
 * @param Module
 * @param ClockDivide
 * @retval void
 */
KF_INLINE void Qei_LL_SetFilterClockDivide(Qei_RegisterMap_t *const Module, const Qei_PrescaleType_t ClockDivide)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    KF_DRV_QEI_ASSERT(((ClockDivide) >> POS_3_SHIFT) == 0U);
    Module->QEI_FLTCTL.bits.FLTCK = ClockDivide;
}

/**
 * @brief 使能QEI 相位检测滤波
 *
 *
 * @param Module
 * @param Status
 *        true:使能相位检测滤波
 *        false:禁止相位检测滤波
 * @retval void
 */
KF_INLINE void Qei_LL_EnablePhaseDetectFilter(Qei_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_FLTCTL.bits.PHDFEN, Status);
}

/**
 * @brief 设置QEI相位检测滤波选择位
 *
 *
 * @param Module
 * @param count
 * @retval void
 */
KF_INLINE void Qei_LL_SetFilterCount(Qei_RegisterMap_t *const Module, const uint32_t Count)
{
    KF_DRV_QEI_ASSERT((Count >> POS_10_OFFSET) == 0U);
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_WRITE(Module->QEI_FLTCTL.bits.PHFSEL, Count);
}

/**
 * @brief 设置QEI计数器当前值
 *
 *
 * @param Module
 * @param count
 * @retval void
 */
KF_INLINE void Qei_LL_SetCount(Qei_RegisterMap_t *const Module, const uint32_t Count)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    KF_DRV_QEI_ASSERT((Count >> POS_16_OFFSET) == 0U);
    REG_WRITE(Module->QEI_CNT.bits.CNT, Count);
}

/**
 * @brief 获取QEI计数器当前值
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Qei_LL_GetCount(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_READ(Module->QEI_CNT.bits.CNT));
}

/**
 * @brief 设置QEI计数器周期值
 *
 *
 * @param Module
 * @param count
 * @retval void
 */
KF_INLINE void Qei_LL_SetPeriod(Qei_RegisterMap_t *const Module, const uint32_t Period)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    KF_DRV_QEI_ASSERT((Period >> POS_16_OFFSET) == 0U);
    REG_WRITE(Module->QEI_PPX.bits.PPX, Period);
}

/**
 * @brief 获取QEI计数器周期值
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Qei_LL_GetPeriod(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_READ(Module->QEI_PPX.bits.PPX));
}

/**
 * @brief 设置QEI计数器预分频
 *
 *
 * @param Module
 * @retval void
 */
KF_INLINE void Qei_LL_SetPrescale(Qei_RegisterMap_t *const Module, const uint32_t Prescale)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    KF_DRV_QEI_ASSERT((Prescale >> POS_16_OFFSET) == 0U);
    REG_WRITE(Module->QEI_PRSC.bits.PRSC, Prescale);
}

/**
 * @brief 获取QEI计数器预分频
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Qei_LL_GetPrescale(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_READ(Module->QEI_PRSC.bits.PRSC));
}

/**
 * @brief 获取QEI索引引脚INDEX状态
 *
 *
 * @param Module
 * @retval Qei_IndexStateType_t
 *         INDEXSTATE_LOW
 *         INDEXSTATE_HIGH
 */
KF_INLINE Qei_IndexStateType_t Qei_LL_GetIndexState(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return ((Qei_IndexStateType_t)REG_READ(Module->QEI_STA.bits.INDEX));
}

/**
 * @brief 获取QEI位置计数器方向状态
 *
 *
 * @param Module
 * @retval Qei_PosDirectionType_t
 *         POS_COUNTDOWN
 *         POS_COUNTUP
 */
KF_INLINE Qei_PosDirectionType_t Qei_LL_GetPosCountPos(Qei_RegisterMap_t *const Module)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return ((Qei_PosDirectionType_t)REG_READ(Module->QEI_STA.bits.DIR));
}

/**
 * @brief 获取QET标志位状态
 *
 *
 * @param Module
 * @param Qei_FlagType_t
 *        COUNTERROR_FLAG
 *        PHASEERROR_FLAG
 *        OVERFLOW_FLAG
 * @retval bool
 *         true:相应标志位处于置位状态
 *         false:相应标志位处于清零状态
 */
KF_INLINE bool Qei_LL_GetFlag(Qei_RegisterMap_t *const Module, Qei_FlagType_t Flag)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_FLAG(Flag));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    return (REG_BITS_READ(Module->QEI_IF.reg, MASK_1_BIT << Flag, Flag));
}

/**
 * @brief 清除QEI相应标志位
 *
 *
 * @param Module
 * @param Qei_FlagType_t
 *        COUNTERROR_FLAG
 *        PHASEERROR_FLAG
 *        OVERFLOW_FLAG
 * @param bool
 *        true:清除相应标志位
 *        false:无作用
 * @retval void
 */
KF_INLINE void Qei_LL_ClearFlag(Qei_RegisterMap_t *const Module, Qei_FlagType_t Flag, const bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_FLAG(Flag));
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_BITS_WRITE(Module->QEI_IC.reg, MASK_1_BIT << Flag, (uint32_t)Status << Flag);
}

/**
 * @brief 置位QEI相应标志位
 *
 *
 * @param Module
 * @param Qei_FlagType_t
 *        COUNTERROR_FLAG
 *        PHASEERROR_FLAG
 *        OVERFLOW_FLAG
 * @param bool
 *        true:置位相应标志位
 *        false:无作用
 * @retval void
 */
KF_INLINE void Qei_LL_SetFlag(Qei_RegisterMap_t *const Module, Qei_FlagType_t Flag, const bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_FLAG(Flag));
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_BITS_WRITE(Module->QEI_IS.reg, MASK_1_BIT << Flag, (uint32_t)Status << Flag);
}

/**
 * @brief 设置QEI相应中断
 *
 *
 * @param Module
 * @param Qei_IntType_t
 *        COUNTERROR_INT
 *        PHASEERROR_INT
 *        OVERFLOW_INT
 * @param bool
 *        true:使能相应中断
 *        false:禁止相应中断
 * @retval void
 */
KF_INLINE void Qei_LL_SetInt(Qei_RegisterMap_t *const Module, Qei_IntType_t Int, const bool Status)
{
    KF_DRV_QEI_ASSERT(CHECK_QEI_INT(Int));
    KF_DRV_QEI_ASSERT(CHECK_QEI_BOOL(Status));
    KF_DRV_QEI_ASSERT(CHECK_QEI_MODULE(Module));
    REG_BITS_WRITE(Module->QEI_IE.reg, MASK_1_BIT << Int, (uint32_t)Status << Int);
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
