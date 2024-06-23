/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_iom.h
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
 *                              REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2023-12-21  |V1.0     |Zhang Quanzhen  | New Creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_IOM_H_
#define KF32A13K_DRV_IOM_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_iom.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_IOM_ASSERT
#include "dev_assert.h"
#define KF_DRV_IOM_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_IOM_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION

#include "kf32a13k_reg_simulation_iom.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    IOM_NOSUSPEND   = 0U,
    IOM_STOPCOUNTER = 2U
} Iom_SuspendMode_t;

#define CHECK_IOM_SUSPENDMODE(Mode) ((Mode == IOM_NOSUSPEND) || (Mode == IOM_STOPCOUNTER))

typedef enum
{
    IOM_ACCESS_ENABLE_0,
    IOM_ACCESS_ENABLE_1,
    IOM_ACCESS_ENABLE_2,
    IOM_ACCESS_ENABLE_3,
    IOM_ACCESS_ENABLE_4,
    IOM_ACCESS_ENABLE_5,
    IOM_ACCESS_ENABLE_6,
    IOM_ACCESS_ENABLE_7,
    IOM_ACCESS_ENABLE_8,
    IOM_ACCESS_ENABLE_9,
    IOM_ACCESS_ENABLE_10,
    IOM_ACCESS_ENABLE_11,
    IOM_ACCESS_ENABLE_12,
    IOM_ACCESS_ENABLE_13,
    IOM_ACCESS_ENABLE_14,
    IOM_ACCESS_ENABLE_15,
    IOM_ACCESS_ENABLE_16,
    IOM_ACCESS_ENABLE_17,
    IOM_ACCESS_ENABLE_18,
    IOM_ACCESS_ENABLE_19,
    IOM_ACCESS_ENABLE_20,
    IOM_ACCESS_ENABLE_21,
    IOM_ACCESS_ENABLE_22,
    IOM_ACCESS_ENABLE_23,
    IOM_ACCESS_ENABLE_24,
    IOM_ACCESS_ENABLE_25,
    IOM_ACCESS_ENABLE_26,
    IOM_ACCESS_ENABLE_27,
    IOM_ACCESS_ENABLE_28,
    IOM_ACCESS_ENABLE_29,
    IOM_ACCESS_ENABLE_30,
    IOM_ACCESS_ENABLE_31
} Iom_AccessEnableType_t;

// MARK:注意实际使用一次只使能一个通道还是一次使能多个通道
#define CHECK_IOM_ACCESSEMABLE(AccessEnable) ((AccessEnable >> POS_5_SHIFT) == 0U)

typedef enum
{
    DOUBLEEDGE_DELAY_FILTERMODE,
    DOUBLEEDGE_IMMEDIATE_FILTERMODE,
    POSEDGEIMMEDIATE_FILTERMODE,
    NEGEDGEIMMEDIATE_FILTERMODE,
    POSEDGEDELAY_NEGDEGEIMMEDIATE_FILTERMODE,
    POSEDGEIMMEDIATE_NEGDEGEDELAY_FILTERMODE,
    POSEDGETRIGGER_FILTERMODE,
    NEGEDGETRIGGER_FILTERMODE
} Iom_FilterModeType_t;

#define CHECK_IOM_FILTERMODE(Mode) ((Mode >> POS_3_SHIFT) == 0U)

typedef enum
{
    MONITOR_SOL,
    MONITOR_MON0,
    MONITOR_MON1,
    MONITOR_MON2
} Iom_InputMonitorSignalType_t;

#define CHECK_IOM_INPUTMONITORSIGNAL(Signal) ((Signal >> POS_2_SHIFT) == 0U)

typedef enum
{
    FILTERTIMER_DECREASE,
    FILTERTIMER_CLEAR
} Iom_FltErrorTimerAction_t;

#define CHECK_IOM_FILTERTIMERACTION(Action) ((Action == FILTERTIMER_DECREASE) || (Action == FILTERTIMER_CLEAR))

typedef enum
{
    REFER_SOL,
    REFER_MON0,
    REFER_MON1,
    REFER_MON2
} Iom_InputReferSignalType_t;

#define CHECK_IOM_REFERSIGNAL(Signal) ((Signal >> POS_2_SHIFT) == 0U)

typedef enum
{
    EVENTWINDOW_OPERATE_FREE,
    EVENTWINDOW_OPERATE_SIGNAL
} Iom_EventWindowModeType_t;

#define CHECK_IOM_EVENTWINMODE(Mode) ((Mode == EVENTWINDOW_OPERATE_FREE) || (Mode == EVENTWINDOW_OPERATE_SIGNAL))

typedef enum
{
    EVENTWINDOW_SIGNAL_REFER,
    EVENTWINDOW_SIGNAL_MONITOR
} Iom_EventWindowSourceType_t;

#define CHECK_IOM_EVENTWINSOURCE(Source)                                                                               \
    ((Source == EVENTWINDOW_SIGNAL_REFER) || (Source == EVENTWINDOW_SIGNAL_MONITOR))

typedef enum
{
    CLEAR_NONE_CONTROL_NONE,
    CLEAR_POS_CONTROL_NONE,
    CLEAR_NEG_CONTROL_NONE,
    CLEAR_DOUBLE_CONTROL_NONE,
    CLEAR_NONE_CONTROL_POS,
    CLEAR_POS_CONTROL_POS,
    CLEAR_NEG_CONTROL_POS,
    CLEAR_DOUBLE_CONTROL_POS,
    CLEAR_NONE_CONTROL_NEG,
    CLEAR_POS_CONTROL_NEG,
    CLEAR_NEG_CONTROL_NEG,
    CLEAR_DOUBLE_CONTROL_NEG,
    CLEAR_NONE_CONTROL_DOUBLE,
    CLEAR_POS_CONTROL_DOUBLE,
    CLEAR_NEG_CONTROL_DOUBLE,
    CLEAR_DOUBLE_CONTROL_DOUBLE
} Iom_EventWindowActEdgeType_t;

#define CHECK_IOM_EVENTWINACTEDGE(Edge) ((Edge >> POS_4_SHIFT) == 0U)

typedef enum
{
    MONITOR_FILTER0,
    MONITOR_FILTER1,
    MONITOR_FILTER2,
    MONITOR_FILTER3,
    MONITOR_FILTER4,
    MONITOR_FILTER5,
    MONITOR_FILTER6,
    MONITOR_FILTER7,
    MONITOR_FILTER8,
    MONITOR_FILTER9,
    MONITOR_FILTER10,
    MONITOR_FILTER11,
    MONITOR_FILTER12,
    MONITOR_FILTER13,
    MONITOR_FILTER14,
    MONITOR_FILTER15
} Iom_MonitorChannelType_t;

#define CHECK_IOM_MONITORCHANNEL(MonitorChannel) ((MonitorChannel >> POS_4_SHIFT) == 0U)

typedef enum
{
    REFER_FILTER0,
    REFER_FILTER1,
    REFER_FILTER2,
    REFER_FILTER3,
    REFER_FILTER4,
    REFER_FILTER5,
    REFER_FILTER6,
    REFER_FILTER7,
    REFER_FILTER8,
    REFER_FILTER9,
    REFER_FILTER10,
    REFER_FILTER11,
    REFER_FILTER12,
    REFER_FILTER13,
    REFER_FILTER14,
    REFER_FILTER15
} Iom_ReferChannelType_t;

#define CHECK_IOM_REFERCHANNEL(ReferChannel) ((ReferChannel >> POS_4_SHIFT) == 0U)

typedef enum
{
    IOM_EVENT0,
    IOM_EVENT1,
    IOM_EVENT2,
    IOM_EVENT3,
    IOM_EVENT4,
    IOM_EVENT5,
    IOM_EVENT6,
    IOM_EVENT7,
    IOM_EVENT8,
    IOM_EVENT9,
    IOM_EVENT10,
    IOM_EVENT11,
    IOM_EVENT12,
    IOM_EVENT13,
    IOM_EVENT14,
    IOM_EVENT15
} Iom_EventChannelType_t;

#define CHECK_IOM_EVENTCHANNEL(EventChannel) ((EventChannel >> POS_4_SHIFT) == 0U)

typedef enum
{
    IOM_FILTER0,
    IOM_FILTER1,
    IOM_FILTER2,
    IOM_FILTER3,
    IOM_FILTER4,
    IOM_FILTER5,
    IOM_FILTER6,
    IOM_FILTER7,
    IOM_FILTER8,
    IOM_FILTER9,
    IOM_FILTER10,
    IOM_FILTER11,
    IOM_FILTER12,
    IOM_FILTER13,
    IOM_FILTER14,
    IOM_FILTER15
} Iom_FilterChannelType_t;

#define CHECK_IOM_FILTERCHANNEL(FilterChannel) ((FilterChannel >> POS_4_SHIFT) == 0U)

typedef enum
{
    IOM_TIMER0,
    IOM_TIMER1,
    IOM_TIMER2,
    IOM_TIMER3
} Iom_TimerType_t;

#define CHECK_IOM_TIMER(Timer) ((Timer >> POS_2_SHIFT) == 0U)

typedef enum
{
    EXOR_EN0,
    EXOR_EN1,
    EXOR_EN2,
    EXOR_EN3,
    EXOR_EN4,
    EXOR_EN5,
    EXOR_EN6,
    EXOR_EN7
} Iom_EXOREnableType_t;

#define CHECK_IOM_EXORENABLE(ExorEnable) ((ExorEnable >> POS_3_SHIFT) == 0U)
#define CHECK_IOM_BOOL(Bool)             ((Bool >> POS_1_SHIFT) == 0U)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief 禁止IOM模块
 *
 *
 * @param Status
 *        true:禁止模块
 *        false:无操作
 * @retval void
 */
KF_INLINE void Iom_LL_DisableModule(bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CLKC_ADDR );
    regValue &= ~HWIO_IOM_CLKC_IOM_CLKC_DISR_MASK;
    regValue |=  Status<<HWIO_IOM_CLKC_IOM_CLKC_DISR_SHFT;
    REG_WRITE(HWIO_IOM_CLKC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CLKC.bits.DISR, Status);
#endif
}

/**
 * @brief 获取IOM模块状态
 *
 *
 * @param void
 * @retval bool
 *         true:模块已禁止
 *         false:模块已使能
 */
KF_INLINE bool Iom_LL_GetModuleState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_CLKC.bits.DISS));
#endif
}

/**
 * @brief 设置IOM模块睡眠状态
 *
 *
 * @param Status
 *         true:模块未进入睡眠模式
 *         false:模块进入睡眠模式
 * @retval void
 */
KF_INLINE void Iom_LL_DisableSleepMode(const bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CLKC_ADDR );
    regValue &= ~HWIO_IOM_CLKC_IOM_CLKC_EDIS_MASK;
    regValue |=  Status<<HWIO_IOM_CLKC_IOM_CLKC_EDIS_SHFT;
    REG_WRITE(HWIO_IOM_CLKC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CLKC.bits.EDIS, Status);
#endif
}

/**
 * @brief 设置IOM模块睡眠状态
 *
 * @param  void
 * @retval Status
 *         true:模块未进入睡眠模式
 *         false:模块进入睡眠模式
 */
KF_INLINE bool Iom_LL_GetSleepMode(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_CLKC.bits.EDIS));
#endif
}

/**
 * @brief 设置IOM输入时钟分频
 *
 *
 * @param ClockDivide:输出时钟分频
 * @retval void
 */
KF_INLINE void Iom_LL_SetInputClockDivide(const uint32_t ClockDivide)
{
    KF_DRV_IOM_ASSERT((ClockDivide >> POS_8_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CLKC_ADDR );
    regValue &= ~HWIO_IOM_CLKC_IOM_CLKC_RMC_MASK;
    regValue |=  ClockDivide<<HWIO_IOM_CLKC_IOM_CLKC_RMC_SHFT;
    REG_WRITE(HWIO_IOM_CLKC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CLKC.bits.RMC, ClockDivide);
#endif
}

/**
 * @brief 获取IOM模块版本信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Iom_LL_GetModuleVersion(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_INFO.bits.MODREV));
#endif
}

/**
 * @brief 获取IOM模块类型信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Iom_LL_GetModuleType(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_INFO.bits.MODTYPE));
#endif
}

/**
 * @brief 获取IOM模块ID信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Iom_LL_GetModuleId(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_INFO.bits.MODNUM));
#endif
}

/**
 * @brief 设置IOM调试挂起模式
 *
 *
 * @param Mode
 *        IOM_NOSUSPEND
 *        IOM_STOPCOUNTER
 * @retval  void
 */
KF_INLINE void Iom_LL_SetDebugSuspendMode(Iom_SuspendMode_t Mode)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_SUSPENDMODE(Mode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_DBG_ADDR );
    regValue &= ~HWIO_IOM_DBG_IOM_DBG_SUSP_MASK;
    regValue |=  true<<HWIO_IOM_DBG_IOM_DBG_SUSP_SHFT;
    REG_WRITE(HWIO_IOM_DBG_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_DBG.bits.SUSP, true);
#endif
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_DBG_ADDR );
    regValue &= ~HWIO_IOM_DBG_IOM_DBG_SUS_MASK;
    regValue |=  Mode<<HWIO_IOM_DBG_IOM_DBG_SUS_SHFT;
    REG_WRITE(HWIO_IOM_DBG_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_DBG.bits.SUS, Mode);
#endif
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_DBG_ADDR );
    regValue &= ~HWIO_IOM_DBG_IOM_DBG_SUSP_MASK;
    regValue |=  false<<HWIO_IOM_DBG_IOM_DBG_SUSP_SHFT;
    REG_WRITE(HWIO_IOM_DBG_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_DBG.bits.SUSP, false);
#endif
}

/**
 * @brief 获取IOM调试挂起模式
 *
 *
 * @param void
 * @retval Iom_SuspendMode_t
 *         IOM_NOSUSPEND
 *         IOM_STOPCOUNTER
 */
KF_INLINE Iom_SuspendMode_t Iom_LL_GetDebugSuspendMode(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Iom_SuspendMode_t)REG_READ(IOM_PTR->IOM_DBG.bits.SUS));
#endif
}

/**
 * @brief 获取IOM调试挂起状态
 *
 *
 * @param void
 * @retval bool
 *         true: 模块已挂起
 *         false: 模块未挂起
 */
KF_INLINE bool Iom_LL_GetDebugSuspend(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_DBG.bits.SUSSTA));
#endif
}

/**
 * @brief 清零IOM 复位状态
 *
 *
 * @param  bool
 *         true: 清零复位状态
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Iom_LL_ClearRst(bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_RSTCLR_ADDR );
    regValue &= ~HWIO_IOM_RSTCLR_IOM_RSTCLR_CLR_MASK;
    regValue |=  Status<<HWIO_IOM_RSTCLR_IOM_RSTCLR_CLR_SHFT;
    REG_WRITE(HWIO_IOM_RSTCLR_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_RSTCLR.bits.CLR, Status);
#endif
}

/**
 * @brief 请求IOM 复位
 *
 *
 * @param  bool
 *         true: 请求模块复位
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Iom_LL_ResetModule(bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_RST0_ADDR );
    regValue &= ~HWIO_IOM_RST0_IOM_RST0_RST_MASK;
    regValue |=  Status<<HWIO_IOM_RST0_IOM_RST0_RST_SHFT;
    REG_WRITE(HWIO_IOM_RST0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_RST0.bits.RST, Status);
#endif
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_RST1_ADDR );
    regValue &= ~HWIO_IOM_RST1_IOM_RST1_RST_MASK;
    regValue |=  Status<<HWIO_IOM_RST1_IOM_RST1_RST_SHFT;
    REG_WRITE(HWIO_IOM_RST1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_RST1.bits.RST, Status);
#endif
}

/**
 * @brief 获取IOM复位状态
 *
 *
 * @ param void
 * @ retval bool
 *          true: 模块已经复位
 *          false: 模块没有复位
 */
KF_INLINE bool Iom_LL_GetResetState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_RST0.bits.RSTSTA));
#endif
}

/**
 * @brief 使能IOM访问控制
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval void
 */
KF_INLINE void Iom_LL_EnableAccess(Iom_AccessEnableType_t AccessEnable)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_ACCESSEMABLE(AccessEnable));
#ifdef SIMULATION
//TODO:
#else
    REG_BIT_SET(IOM_PTR->IOM_ACES0.reg, MASK_1_BIT << AccessEnable);
#endif
}

/**
 * @brief 获取IOM访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE bool Iom_LL_GetAccess(Iom_AccessEnableType_t AccessEnable)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_ACCESSEMABLE(AccessEnable));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_IOM_ACES0_ADDR, MASK_1_BIT << AccessEnable, AccessEnable));
//TODO: check if correct

#else
    return (REG_BITS_READ(IOM_PTR->IOM_ACES0.reg, MASK_1_BIT << AccessEnable, AccessEnable));
#endif
}

/**
 * @brief 设置IOM滤波器比较值
 *
 *
 * @ param Compare
 * @ retval void
 */
KF_INLINE void Iom_LL_SetFilterComPare(const uint32_t Compare)
{
    KF_DRV_IOM_ASSERT((Compare >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL0_ADDR );
    regValue &= ~HWIO_IOM_CTL0_IOM_CTL0_CMP_MASK;
    regValue |=  Compare<<HWIO_IOM_CTL0_IOM_CTL0_CMP_SHFT;
    REG_WRITE(HWIO_IOM_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL0.bits.CMP, Compare);
#endif
}

/**
 * @brief 获取IOM滤波器比较值
 *
 *
 * @ param void
 * @ retval uint32_t
 */
KF_INLINE uint32_t Iom_LL_GetFilterComPare(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_CTL0.bits.CMP));
#endif
}

/**
 * @brief 设置IOM滤波器与预分频通道操作模式
 *
 *
 * @ param Iom_FilterModeType_t
 *         DOUBLEEDGE_DELAY_FILTERMODE,
 *         DOUBLEEDGE_IMMEDIATE_FILTERMODE,
 *         POSEDGEIMMEDIATE_FILTERMODE,
 *         NEGEDGEIMMEDIATE_FILTERMODE,
 *         POSEDGEDELAY_NEGDEGEIMMEDIATE_FILTERMODE,
 *         POSEDGEIMMEDIATE_NEGDEGEDELAY_FILTERMODE,
 *         POSEDGETRIGGER_FILTERMODE,
 *         NEGEDGETRIGGER_FILTERMODE
 * @ retval void
 */
KF_INLINE void Iom_LL_SetFilterMode(Iom_FilterModeType_t FilterMode)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_FILTERMODE(FilterMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL0_ADDR );
    regValue &= ~HWIO_IOM_CTL0_IOM_CTL0_MOD_MASK;
    regValue |=  FilterMode<<HWIO_IOM_CTL0_IOM_CTL0_MOD_SHFT;
    REG_WRITE(HWIO_IOM_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL0.bits.MOD, FilterMode);
#endif
}

/**
 * @brief 获取IOM滤波器与预分频通道操作模式
 *
 *
 * @ param void
 * @ retval Iom_FilterModeType_t
 *         DOUBLEEDGE_DELAY_FILTERMODE,
 *         DOUBLEEDGE_IMMEDIATE_FILTERMODE,
 *         POSEDGEIMMEDIATE_FILTERMODE,
 *         NEGEDGEIMMEDIATE_FILTERMODE,
 *         POSEDGEDELAY_NEGDEGEIMMEDIATE_FILTERMODE,
 *         POSEDGEIMMEDIATE_NEGDEGEDELAY_FILTERMODE,
 *         POSEDGETRIGGER_FILTERMODE,
 *         NEGEDGETRIGGER_FILTERMODE
 */
KF_INLINE Iom_FilterModeType_t Iom_LL_GetFilterMode(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Iom_FilterModeType_t)REG_READ(IOM_PTR->IOM_CTL0.bits.MOD));
#endif
}

/**
 * @brief 设置IOM监控输入信号
 *
 *
 * @ param Iom_InputMonitorSignalType_t
 *         MONITOR_SOL,
 *         MONITOR_MON0,
 *         MONITOR_MON1,
 *         MONITOR_MON2,
 * @ retval void
 */
KF_INLINE void Iom_LL_SetInputMonitorSignal(Iom_InputMonitorSignalType_t InputMonitorSignal)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_INPUTMONITORSIGNAL(InputMonitorSignal));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL0_ADDR );
    regValue &= ~HWIO_IOM_CTL0_IOM_CTL0_ISM_MASK;
    regValue |=  InputMonitorSignal<<HWIO_IOM_CTL0_IOM_CTL0_ISM_SHFT;
    REG_WRITE(HWIO_IOM_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL0.bits.ISM, InputMonitorSignal);
#endif
}

/**
 * @brief 获取IOM监控输入信号
 *
 *
 * @ param void
 * @ retval Iom_InputMonitorSignalType_t
 *         MONITOR_SOL,
 *         MONITOR_MON0,
 *         MONITOR_MON1,
 *         MONITOR_MON2
 */
KF_INLINE Iom_InputMonitorSignalType_t Iom_LL_GetInputMonitorSignal(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Iom_InputMonitorSignalType_t)REG_READ(IOM_PTR->IOM_CTL0.bits.ISM));
#endif
}

/**
 * @brief 设置IOM通道遇故障时定时器行为
 *
 *
 * @ param Iom_FltErrorTimerAction_t
 *         FILTERTIMER_DECREASE,
 *         FILTERTIMER_CLEAR
 * @ retval void
 *
 */
KF_INLINE void Iom_LL_SetFilterErrorTimerAction(Iom_FltErrorTimerAction_t TimerAction)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_FILTERTIMERACTION(TimerAction));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL0_ADDR );
    regValue &= ~HWIO_IOM_CTL0_IOM_CTL0_RTG_MASK;
    regValue |=  TimerAction<<HWIO_IOM_CTL0_IOM_CTL0_RTG_SHFT;
    REG_WRITE(HWIO_IOM_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL0.bits.RTG, TimerAction);
#endif
}

/**
 * @brief 获取IOM通道遇故障时定时器行为
 *
 *
 * @ param void
 * @ retval Iom_InputMonitorSignalType_t
 *         MONITOR_SOL,
 *         MONITOR_MON0,
 *         MONITOR_MON1,
 *         MONITOR_MON2,
 */
KF_INLINE Iom_FltErrorTimerAction_t Iom_LL_GetFilterErrorTimerAction(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Iom_FltErrorTimerAction_t)REG_READ(IOM_PTR->IOM_CTL0.bits.RTG));
#endif
}

/**
 * @brief 设置IOM参考输入信号
 *
 *
 * @ param Iom_InputReferSignalType_t
 *         REFER_SOL,
 *         REFER_MON0,
 *         REFER_MON1,
 *         REFER_MON2
 * @ retval void
 */
KF_INLINE void Iom_LL_SetInputReferSignal(Iom_InputReferSignalType_t InputReferSignal)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_REFERSIGNAL(InputReferSignal));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL0_ADDR );
    regValue &= ~HWIO_IOM_CTL0_IOM_CTL0_ISM_MASK;
    regValue |=  InputReferSignal<<HWIO_IOM_CTL0_IOM_CTL0_ISM_SHFT;
    REG_WRITE(HWIO_IOM_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL0.bits.ISM, InputReferSignal);
#endif
}

/**
 * @brief 获取IOM参考输入信号
 *
 *
 * @ param void
 * @ retval Iom_InputReferSignalType_t
 *         REFER_SOL,
 *         REFER_MON0,
 *         REFER_MON1,
 *         REFER_MON2
 */
KF_INLINE Iom_InputReferSignalType_t Iom_LL_GetInputReferSignal(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Iom_InputReferSignalType_t)REG_READ(IOM_PTR->IOM_CTL0.bits.ISM));
#endif
}

/**
 * @brief 设置IOM参考输入信号取反
 *
 *
 * @ param Status
 *         true:Filter的参考信号取反
 *         false:Filter的参考信号不取反
 * @ retval void
 */
KF_INLINE void Iom_LL_ReverseReferSignal(const bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL1_ADDR );
    regValue &= ~HWIO_IOM_CTL1_IOM_CTL1_IVR_MASK;
    regValue |=  Status<<HWIO_IOM_CTL1_IOM_CTL1_IVR_SHFT;
    REG_WRITE(HWIO_IOM_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL1.bits.IVR, Status);
#endif
}

/**
 * @brief 获取IOM参考输入信号取反状态
 *
 *
 * @ param void
 * @ retval bool
 *          true:Filter的参考信号取反
 *          false:Filter的参考信号不取反
 */
KF_INLINE bool Iom_LL_GetReferSignalReverseState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_CTL1.bits.IVR));
#endif
}

/**
 * @brief 设置IOM监控输入信号取反
 *
 *
 * @ param Status
 *         true:Filter的监控信号取反
 *         false:Filter的监控信号不取反
 * @ retval void
 */
KF_INLINE void Iom_LL_ReverseMonitorSignal(const bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL1_ADDR );
    regValue &= ~HWIO_IOM_CTL1_IOM_CTL1_IVM_MASK;
    regValue |=  Status<<HWIO_IOM_CTL1_IOM_CTL1_IVM_SHFT;
    REG_WRITE(HWIO_IOM_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL1.bits.IVM, Status);
#endif
}

/**
 * @brief 获取IOM监控输入信号取反状态
 *
 *
 * @ param void
 * @ retval bool
 *          true:Filter的参考信号取反
 *          false:Filter的参考信号不取反
 */
KF_INLINE bool Iom_LL_GetMonitorSignalReverseState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_CTL1.bits.IVM));
#endif
}

/**
 * @brief 设置IOM监控资源
 *
 *
 * @ param Status
 *          true:监控信号是FLT和EXOR进行运算
 *          false:监控信号直接来源于FLT
 * @ retval void
 */
KF_INLINE void Iom_LL_SetMonitorSource(const bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL1_ADDR );
    regValue &= ~HWIO_IOM_CTL1_IOM_CTL1_MOS_MASK;
    regValue |=  Status<<HWIO_IOM_CTL1_IOM_CTL1_MOS_SHFT;
    REG_WRITE(HWIO_IOM_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL1.bits.MOS, Status);
#endif
}

/**
 * @brief 获取IOM监控资源
 *
 *
 * @ param void
 * @ retval bool
 *          true:监控信号是FLT和EXOR进行运算
 *          false:监控信号直接来源于FLT
 */
KF_INLINE bool Iom_LL_GetMonitorSource(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_CTL1.bits.MOS));
#endif
}

/**
 * @brief 设置IOM事件窗口产生模式
 *
 *
 * @ param Iom_EventWindowModeType_t
 *         EVENTWINDOW_OPERATE_FREE,
 *         EVENTWINDOW_OPERATE_SIGNAL
 * @ retval void
 */
KF_INLINE void Iom_LL_SetEventWindowMode(Iom_EventWindowModeType_t EventWindowMode)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_EVENTWINMODE(EventWindowMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL1_ADDR );
    regValue &= ~HWIO_IOM_CTL1_IOM_CTL1_RMS_MASK;
    regValue |=  EventWindowMode<<HWIO_IOM_CTL1_IOM_CTL1_RMS_SHFT;
    REG_WRITE(HWIO_IOM_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL1.bits.RMS, EventWindowMode);
#endif
}

/**
 * @brief 获取IOM事件窗口产生模式
 *
 *
 * @ param void
 * @ retval bool
 *          true:监控信号是FLT和EXOR进行运算
 *          false:监控信号直接来源于FLT
 */
KF_INLINE Iom_EventWindowModeType_t Iom_LL_GetEventWindowMode(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Iom_EventWindowModeType_t)REG_READ(IOM_PTR->IOM_CTL1.bits.RMS));
#endif
}

/**
 *
 * @brief 设置IOM事件窗口产生源
 *
 *
 * @ param Iom_EventWindowSourceType_t
 *         EVENTWINDOW_SIGNAL_REFER,
 *         EVENTWINDOW_SIGNAL_MONITOR
 * @ retval void
 */
KF_INLINE void Iom_LL_SetEventWindowSource(Iom_EventWindowSourceType_t EventWindowSource)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_EVENTWINSOURCE(EventWindowSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL1_ADDR );
    regValue &= ~HWIO_IOM_CTL1_IOM_CTL1_EWS_MASK;
    regValue |=  EventWindowSource<<HWIO_IOM_CTL1_IOM_CTL1_EWS_SHFT;
    REG_WRITE(HWIO_IOM_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL1.bits.EWS, EventWindowSource);
#endif
}

/**
 *
 * @brief 获取IOM事件窗口产生源
 *
 *
 * @ param void
 * @ retval Iom_EventWindowSourceType_t
 *          EVENTWINDOW_SIGNAL_REFER,
 *          EVENTWINDOW_SIGNAL_MONITOR
 */
KF_INLINE Iom_EventWindowSourceType_t Iom_LL_GetEventWindowSource(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Iom_EventWindowSourceType_t)REG_READ(IOM_PTR->IOM_CTL1.bits.EWS));
#endif
}

/**
 *
 * @brief 禁止IOM事件产生传输
 *
 *
 * @ param Status
 *         true:禁止事件产生
 *         false:不禁止事件产生
 * @ retval void
 */
KF_INLINE void Iom_LL_ProhibitEvent(const bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL1_ADDR );
    regValue &= ~HWIO_IOM_CTL1_IOM_CTL1_DISEV_MASK;
    regValue |=  Status<<HWIO_IOM_CTL1_IOM_CTL1_DISEV_SHFT;
    REG_WRITE(HWIO_IOM_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL1.bits.DISEV, Status);
#endif
}

/**
 *
 * @brief 设置IOM事件窗口激活沿
 *
 *
 * @ param Iom_EventWindowActEdgeType_t
 *    CLEAR_NONE_CONTROL_NONE,
 *    CLEAR_POS_CONTROL_NONE,
 *    CLEAR_NEG_CONTROL_NONE,
 *    CLEAR_DOUBLE_CONTROL_NONE,
 *    CLEAR_NONE_CONTROL_POS,
 *    CLEAR_POS_CONTROL_POS,
 *    CLEAR_NEG_CONTROL_POS,
 *    CLEAR_DOUBLE_CONTROL_POS,
 *    CLEAR_NONE_CONTROL_NEG,
 *    CLEAR_POS_CONTROL_NEG,
 *    CLEAR_NEG_CONTROL_NEG,
 *    CLEAR_DOUBLE_CONTROL_NEG,
 *    CLEAR_NONE_CONTROL_DOUBLE,
 *    CLEAR_POS_CONTROL_DOUBLE,
 *    CLEAR_NEG_CONTROL_DOUBLE,
 *    CLEAR_DOUBLE_CONTROL_DOUBLE,
 * @ retval void
 */
KF_INLINE void Iom_LL_SetEventWindowActEdge(const Iom_EventWindowActEdgeType_t ActEdge)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_EVENTWINACTEDGE(ActEdge));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL1_ADDR );
    regValue &= ~HWIO_IOM_CTL1_IOM_CTL1_EDS_MASK;
    regValue |=  ActEdge<<HWIO_IOM_CTL1_IOM_CTL1_EDS_SHFT;
    REG_WRITE(HWIO_IOM_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL1.bits.EDS, ActEdge);
#endif
}

/**
 *
 * @brief 获取IOM事件窗口激活沿
 *
 *
 * @ param void
 * @ retval Iom_EventWindowActEdgeType_t
 *    CLEAR_NONE_CONTROL_NONE,
 *    CLEAR_PO_SCONTROL_NONE,
 *    CLEAR_NEG_CONTROL_NONE,
 *    CLEAR_DOUBLE_CONTROL_NONE,
 *    CLEAR_NONE_CONTROL_POS,
 *    CLEAR_POS_CONTROL_POS,
 *    CLEAR_NEG_CONTROL_POS,
 *    CLEAR_DOUBLE_CONTROL_POS,
 *    CLEAR_NONE_CONTROL_NEG,
 *    CLEAR_POS_CONTROL_NEG,
 *    CLEAR_NEG_CONTROL_NEG,
 *    CLEAR_DOUBLE_CONTROL_NEG,
 *    CLEAR_NONE_CONTROL_DOUBLE,
 *    CLEAR_POS_CONTROL_DOUBLE,
 *    CLEAR_NEG_CONTROL_DOUBLE,
 *    CLEAR_DOUBLE_CONTROL_DOUBLE,
 */
KF_INLINE Iom_EventWindowActEdgeType_t Iom_LL_GetEventWindowActEdge(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Iom_EventWindowActEdgeType_t)REG_READ(IOM_PTR->IOM_CTL1.bits.EDS));
#endif
}

/**
 * @brief 设置IOM事件窗口取反
 *
 *
 * @ param Status
 *         true:设置事件窗口取反
 *         false:设置事件窗口不取反
 * @ retval void
 */
KF_INLINE void Iom_LL_ReverseEventWindow(const bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
#ifdef SIMULATION
//TODO: Error: cannot find the correct registerHWIO_IOM_CTL1_ADDR with bit IVE name please correct
#else
    REG_WRITE(IOM_PTR->IOM_CTL1.bits.IVE, Status);
#endif
}

/**
 * @brief 获取IOM监控输入信号取反状态
 *
 *
 * @ param void
 * @ retval bool
 *          true:事件窗口已取反
 *          false:事件窗口未取反
 */
KF_INLINE bool Iom_LL_GetReverseWindowReverseState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_CTL1.bits.IVE));
#endif
}

/**
 * @brief 设置IOM监控输入通道
 *
 *
 * @ param Iom_MonitorChannelType_t
 *         MONITOR_FILTER0,
 *         MONITOR_FILTER1,
 *         MONITOR_FILTER2,
 *         MONITOR_FILTER3,
 *         MONITOR_FILTER4,
 *         MONITOR_FILTER5,
 *         MONITOR_FILTER6,
 *         MONITOR_FILTER7,
 *         MONITOR_FILTER8,
 *         MONITOR_FILTER9,
 *         MONITOR_FILTER10,
 *         MONITOR_FILTER11,
 *         MONITOR_FILTER12,
 *         MONITOR_FILTER13,
 *         MONITOR_FILTER14,
 *         MONITOR_FILTER15,
 * @ retval void
 */
KF_INLINE void Iom_LL_SetMonitorChannel(Iom_MonitorChannelType_t MonitorChannel)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_MONITORCHANNEL(MonitorChannel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL1_ADDR );
    regValue &= ~HWIO_IOM_CTL1_IOM_CTL1_MCS_MASK;
    regValue |=  MonitorChannel<<HWIO_IOM_CTL1_IOM_CTL1_MCS_SHFT;
    REG_WRITE(HWIO_IOM_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL1.bits.MCS, MonitorChannel);
#endif
}

/**
 * @brief 获取IOM监控输入通道
 *
 *
 * @ param void
 * @ retval Iom_MonitorChannelType_t
 *         MONITOR_FILTER0,
 *         MONITOR_FILTER1,
 *         MONITOR_FILTER2,
 *         MONITOR_FILTER3,
 *         MONITOR_FILTER4,
 *         MONITOR_FILTER5,
 *         MONITOR_FILTER6,
 *         MONITOR_FILTER7,
 *         MONITOR_FILTER8,
 *         MONITOR_FILTER9,
 *         MONITOR_FILTER10,
 *         MONITOR_FILTER11,
 *         MONITOR_FILTER12,
 *         MONITOR_FILTER13,
 *         MONITOR_FILTER14,
 *         MONITOR_FILTER15,
 */
KF_INLINE Iom_MonitorChannelType_t Iom_LL_GetMonitorChannel(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Iom_MonitorChannelType_t)REG_READ(IOM_PTR->IOM_CTL1.bits.MCS));
#endif
}

/**
 * @brief 设置IOM参考输入通道
 *
 *
 * @ param Iom_ReferChannelType_t
 *         REFER_FILTER0,
 *         REFER_FILTER1,
 *         REFER_FILTER2,
 *         REFER_FILTER3,
 *         REFER_FILTER4,
 *         REFER_FILTER5,
 *         REFER_FILTER6,
 *         REFER_FILTER7,
 *         REFER_FILTER8,
 *         REFER_FILTER9,
 *         REFER_FILTER10,
 *         REFER_FILTER11,
 *         REFER_FILTER12,
 *         REFER_FILTER13,
 *         REFER_FILTER14,
 *         REFER_FILTER15
 * @ retval void
 */
KF_INLINE void Iom_LL_SetReferChannel(Iom_ReferChannelType_t ReferChannel)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_REFERCHANNEL(ReferChannel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_IOM_CTL1_ADDR );
    regValue &= ~HWIO_IOM_CTL1_IOM_CTL1_RCS_MASK;
    regValue |=  ReferChannel<<HWIO_IOM_CTL1_IOM_CTL1_RCS_SHFT;
    REG_WRITE(HWIO_IOM_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(IOM_PTR->IOM_CTL1.bits.RCS, ReferChannel);
#endif
}

/**
 * @brief 获取IOM监控输入通道
 *
 *
 * @ param void
 * @ retval Iom_ReferChannelType_t
 *         REFER_FILTER0,
 *         REFER_FILTER1,
 *         REFER_FILTER2,
 *         REFER_FILTER3,
 *         REFER_FILTER4,
 *         REFER_FILTER5,
 *         REFER_FILTER6,
 *         REFER_FILTER7,
 *         REFER_FILTER8,
 *         REFER_FILTER9,
 *         REFER_FILTER10,
 *         REFER_FILTER11,
 *         REFER_FILTER12,
 *         REFER_FILTER13,
 *         REFER_FILTER14,
 *         REFER_FILTER15
 */
KF_INLINE Iom_ReferChannelType_t Iom_LL_GetReferChannel(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Iom_ReferChannelType_t)REG_READ(IOM_PTR->IOM_CTL1.bits.RCS));
#endif
}

/**
 * @brief 设置IOM定时器事件通道
 *
 *
 * @ param Iom_TimerType_t
 *        IOM_TIMER0,
 *        IOM_TIMER1,
 *        IOM_TIMER2,
 *        IOM_TIMER3
 * @ param Iom_EventChannelType_t
 *         IOM_EVENT0,
 *         IOM_EVENT1,
 *         IOM_EVENT2,
 *         IOM_EVENT3,
 *         IOM_EVENT4,
 *         IOM_EVENT5,
 *         IOM_EVENT6,
 *         IOM_EVENT7,
 *         IOM_EVENT8,
 *         IOM_EVENT9,
 *         IOM_EVENT10,
 *         IOM_EVENT11,
 *         IOM_EVENT12,
 *         IOM_EVENT13,
 *         IOM_EVENT14,
 *         IOM_EVENT15
 * @ retval void
 */
KF_INLINE void Iom_LL_SetTimerEventChannel(Iom_TimerType_t Timer, Iom_EventChannelType_t Channel)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_TIMER(Timer));
    KF_DRV_IOM_ASSERT(CHECK_IOM_EVENTCHANNEL(Channel));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_IOM_CTL2_ADDR ,  Channel << (Timer * POS_8_SHIFT));
//TODO: check if correct

#else
    REG_BITS_WRITE(IOM_PTR->IOM_CTL2.reg, MASK_4_BIT << (Timer * POS_8_SHIFT), Channel << (Timer * POS_8_SHIFT));
#endif
}

/**
 * @brief 设置IOM定时器阈值
 *
 *
 * @ param Iom_TimerType_t
 *        IOM_TIMER0,
 *        IOM_TIMER1,
 *        IOM_TIMER2,
 *        IOM_TIMER3
 * @ param ThresHold:定时器阈值
 * @ retval void
 */
KF_INLINE void Iom_LL_SetTimerThresHold(Iom_TimerType_t Timer, const uint32_t ThresHold)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_TIMER(Timer));
    KF_DRV_IOM_ASSERT((ThresHold >> POS_4_SHIFT) == 0U);
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_IOM_CTL2_ADDR ,                    ThresHold << (Timer * POS_8_SHIFT + POS_4_OFFSET));//TODO: check if correct

#else
    REG_BITS_WRITE(IOM_PTR->IOM_CTL2.reg, MASK_4_BIT << (Timer * POS_8_SHIFT + POS_4_OFFSET),
                   ThresHold << (Timer * POS_8_SHIFT + POS_4_OFFSET));
#endif
}

/**
 * @brief 获取IOM Filter下降沿故障标志
 *
 *
 * @ param Iom_FilterChannelType_t
 *         IOM_FILTER0,
 *         IOM_FILTER1,
 *         IOM_FILTER2,
 *         IOM_FILTER3,
 *         IOM_FILTER4,
 *         IOM_FILTER5,
 *         IOM_FILTER6,
 *         IOM_FILTER7,
 *         IOM_FILTER8,
 *         IOM_FILTER9,
 *         IOM_FILTER10,
 *         IOM_FILTER11,
 *         IOM_FILTER12,
 *         IOM_FILTER13,
 *         IOM_FILTER14,
 *         IOM_FILTER15
 * @ retval bool
 *          true:Filter在下降沿检测到故障
 *          false:Filter在下降沿未检测到故障
 */
KF_INLINE bool Iom_LL_GetNegEdgeErrorState(const Iom_FilterChannelType_t FilterChannel)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_FILTERCHANNEL(FilterChannel));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_IOM_CTL2_ADDR, MASK_1_BIT << FilterChannel, FilterChannel));
//TODO: check if correct

#else
    return (REG_BITS_READ(IOM_PTR->IOM_CTL2.reg, MASK_1_BIT << FilterChannel, FilterChannel));
#endif
}

/**
 * @brief 获取IOM Filter下降沿故障标志
 *
 *
 * @ param Iom_TimerType_t
 *         IOM_FILTER0,
 *         IOM_FILTER1,
 *         IOM_FILTER2,
 *         IOM_FILTER3,
 *         IOM_FILTER4,
 *         IOM_FILTER5,
 *         IOM_FILTER6,
 *         IOM_FILTER7,
 *         IOM_FILTER8,
 *         IOM_FILTER9,
 *         IOM_FILTER10,
 *         IOM_FILTER11,
 *         IOM_FILTER12,
 *         IOM_FILTER13,
 *         IOM_FILTER14,
 *         IOM_FILTER15
 * @ retval bool
 *          true:Filter在上升沿沿检测到故障
 *          false:Filter在上升沿未检测到故障
 */
KF_INLINE bool Iom_LL_GetPosEdgeErrorState(const Iom_FilterChannelType_t FilterChannel)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_FILTERCHANNEL(FilterChannel));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_IOM_CTL2_ADDR, MASK_1_BIT << (FilterChannel + POS_16_OFFSET), FilterChannel + POS_16_OFFSET));//TODO: check if correct

#else
    return (REG_BITS_READ(
      IOM_PTR->IOM_CTL2.reg, MASK_1_BIT << (FilterChannel + POS_16_OFFSET), FilterChannel + POS_16_OFFSET));
#endif
}

/**
 * @brief 获取IOM Filter当前计数值
 *
 *
 * @ param void
 * @ retval uint32_t
 */
KF_INLINE uint32_t Iom_LL_GetFilterCount(void)
{
    // TODO:需确定和4个Filter Timer 阈值的对应关系
#ifdef SIMULATION
    return (REG_READ(HWIO_IOM_TIM_ADDR));
//TODO: check if correct

#else
    return (REG_READ(IOM_PTR->IOM_TIM.reg));
#endif
}

/**
 * @brief 获取IOM Compare当前计数值
 *
 *
 * @ param void
 * @ retval uint32_t
 */
KF_INLINE uint32_t Iom_LL_GetCompareCount(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_EWC.bits.CNT));
#endif
}

/**
 * @brief 获取IOM Compare溢出标志位
 *
 *
 * @ param void
 * @ retval bool
 *          true:比较器计数值已达到最大值
 *          false:比较器计数值未达到最大值
 */
KF_INLINE bool Iom_LL_GetCompareOverFlowFlag(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_EWC.bits.CNTO));
#endif
}

/**
 * @brief 获取IOM事件窗口当前计数值
 *
 *
 * @ param void
 * @ retval uint32_t
 */
KF_INLINE bool Iom_LL_GetEventCount(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(IOM_PTR->IOM_EWS.bits.THR));
#endif
}

/**
 * @brief 设置IOM EXOR组合器输入
 *
 *
 * @ param EXOREnType
 *         EXOR_EN0
 *         EXOR_EN1
 *         EXOR_EN2
 *         EXOR_EN3
 *         EXOR_EN4
 *         EXOR_EN5
 *         EXOR_EN6
 *         EXOR_EN7
 * @ param Status
 *         true:使能EXOR输入
 *         false:禁止EXOR输入
 * @ retval void
 */
KF_INLINE void Iom_LL_SetEXORInput(const Iom_EXOREnableType_t EXOREnType, const bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_EXORENABLE(EXOREnType));
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_IOM_EXOR_ADDR ,  Status << EXOREnType);
//TODO: check if correct

#else
    REG_BITS_WRITE(IOM_PTR->IOM_EXOR.reg, MASK_1_BIT << EXOREnType, Status << EXOREnType);
#endif
}

/**
 * @brief 设置IOM 全局事件单个事件输出
 *
 *
 * @ param Iom_EventChannelType_t
 *         IOM_EVENT0
 *         IOM_EVENT1
 *         IOM_EVENT2
 *         IOM_EVENT3
 *         IOM_EVENT4
 *         IOM_EVENT5
 *         IOM_EVENT6
 *         IOM_EVENT7
 *         IOM_EVENT8
 *         IOM_EVENT9
 *         IOM_EVENT10
 *         IOM_EVENT11
 *         IOM_EVENT12
 *         IOM_EVENT13
 *         IOM_EVENT14
 *         IOM_EVENT15
 * @ param Status
 *         true:全局事件生成中包含通道事件输出
 *         false:全局事件生成中不包含通道事件输出
 * @ retval void
 */
KF_INLINE void Iom_LL_SetGlobalEvent(const Iom_EventChannelType_t EventChannel, const bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_EVENTCHANNEL(EventChannel));
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
    // TODO:不确定使用具体使用功能
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_IOM_ECR_ADDR ,  Status << EventChannel);
//TODO: check if correct

#else
    REG_BITS_WRITE(IOM_PTR->IOM_ECR.reg, MASK_1_BIT << EventChannel, Status << EventChannel);
#endif
}

/**
 * @brief 设置IOM 全局事件单个事件输出
 *
 *
 * @ param Iom_TimerType_t
 *         IOM_TIMER0
 *         IOM_TIMER1
 *         IOM_TIMER2
 *         IOM_TIMER3
 * @ param Status
 *         true:全局事件生成中包含通道事件输出
 *         false:全局事件生成中不包含通道事件输出
 * @ retval void
 */
KF_INLINE void Iom_LL_SetCountAlarm(const Iom_TimerType_t TimerType, const bool Status)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_TIMER(TimerType));
    KF_DRV_IOM_ASSERT(CHECK_IOM_BOOL(Status));
    // TODO:不确定TimerType
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_IOM_ECR_ADDR ,  Status << (TimerType + POS_16_OFFSET));//TODO: check if correct

#else
    REG_BITS_WRITE(
      IOM_PTR->IOM_ECR.reg, MASK_1_BIT << (TimerType + POS_16_OFFSET), Status << (TimerType + POS_16_OFFSET));
#endif
}

/**
 * @brief 获取IOM 通道触发状态
 *
 *
 * @ param Status
 *         true:通道触发一个系统事件
 *         false:通道不会触发一个系统事件
 * @ retval void
 */
KF_INLINE bool Iom_LL_GetTriggerAState(const Iom_FilterChannelType_t Channel)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_FILTERCHANNEL(Channel));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_IOM_ETM0_ADDR, MASK_1_BIT << Channel, Channel));
//TODO: check if correct

#else
    return (REG_BITS_READ(IOM_PTR->IOM_ETM0.reg, MASK_1_BIT << Channel, Channel));
#endif
}

/**
 * @brief 获取IOM 通道触发状态
 *
 *
 * @ param Status
 *         true:通道触发一个系统事件
 *         false:通道不会触发一个系统事件
 * @ retval void
 */
KF_INLINE bool Iom_LL_GetTriggerBState(const Iom_FilterChannelType_t Channel)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_FILTERCHANNEL(Channel));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_IOM_ETM0_ADDR, MASK_1_BIT << (Channel + POS_16_OFFSET), (Channel + POS_16_OFFSET)));
//TODO: check if correct

#else
    return (REG_BITS_READ(IOM_PTR->IOM_ETM0.reg, MASK_1_BIT << (Channel + POS_16_OFFSET), (Channel + POS_16_OFFSET)));
#endif
}

/**
 * @brief 获取IOM 通道触发状态
 *
 *
 * @ param Status
 *         true:通道触发一个系统事件
 *         false:通道不会触发一个系统事件
 * @ retval void
 */
KF_INLINE bool Iom_LL_GetTriggerCState(const Iom_FilterChannelType_t Channel)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_FILTERCHANNEL(Channel));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_IOM_ETM1_ADDR, MASK_1_BIT << Channel, Channel));
//TODO: check if correct

#else
    return (REG_BITS_READ(IOM_PTR->IOM_ETM1.reg, MASK_1_BIT << Channel, Channel));
#endif
}

/**
 * @brief 获取IOM 通道触发状态
 *
 *
 * @ param Status
 *         true:通道触发一个系统事件
 *         false:通道不会触发一个系统事件
 * @ retval void
 */
KF_INLINE bool Iom_LL_GetTriggerDState(const Iom_FilterChannelType_t Channel)
{
    KF_DRV_IOM_ASSERT(CHECK_IOM_FILTERCHANNEL(Channel));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_IOM_ETM1_ADDR, MASK_1_BIT << (Channel + POS_16_OFFSET), (Channel + POS_16_OFFSET)));
//TODO: check if correct

#else
    return (REG_BITS_READ(IOM_PTR->IOM_ETM1.reg, MASK_1_BIT << (Channel + POS_16_OFFSET), (Channel + POS_16_OFFSET)));
#endif
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
