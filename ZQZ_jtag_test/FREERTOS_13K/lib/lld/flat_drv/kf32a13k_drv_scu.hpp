/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_scu.h
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
 *  |2023-12-20  |V1.0     |Zhang Quanzhen  | New Creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_SCU_H_
#define KF32A13K_DRV_SCU_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_scu.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_SCU_ASSERT
#include "dev_assert.h"
#define KF_DRV_SCU_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_SCU_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION
#include "kf32a13k_reg_simulation_scu.h"

#endif
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    SCU_CPU0,
    SCU_CPU1,
} Scu_CPUType_t;

typedef enum
{
    SCU_TRAPESR0,
    SCU_TRAPESR1,
    SCU_TRAPSOFT,
    SCU_TRAPSMU,
} Scu_TrapType_t;

typedef enum
{
    BYTE_HALF_K,
    BYTE_1_M,
    BYTE_2_M,
    BYTE_3_M,
    BYTE_4_M,
    BYTE_5_M,
    BYTE_6_M,
    BYTE_7_M,
    BYTE_9_M,
} Scu_FlashSizeType_t;

typedef enum
{
    PACKAGE_BARE,
    PACKAGE_TQFP100,
    PACKAGE_TQFP176,
    PACKAGE_BGA180,
    PACKAGE_LFBGA292
} Scu_PackageType_t;

typedef enum
{
    SCU_ACCESS_00,
    SCU_ACCESS_10,
} Scu_AccessP0Type_t;

typedef enum
{
    SCU_ACCESS_01,
    SCU_ACCESS_11,
} Scu_AccessP1Type_t;

typedef enum
{
    SCU_ACCESS_ENABLE_0,
    SCU_ACCESS_ENABLE_1,
    SCU_ACCESS_ENABLE_2,
    SCU_ACCESS_ENABLE_3,
    SCU_ACCESS_ENABLE_4,
    SCU_ACCESS_ENABLE_5,
    SCU_ACCESS_ENABLE_6,
    SCU_ACCESS_ENABLE_7,
    SCU_ACCESS_ENABLE_8,
    SCU_ACCESS_ENABLE_9,
    SCU_ACCESS_ENABLE_10,
    SCU_ACCESS_ENABLE_11,
    SCU_ACCESS_ENABLE_12,
    SCU_ACCESS_ENABLE_13,
    SCU_ACCESS_ENABLE_14,
    SCU_ACCESS_ENABLE_15,
    SCU_ACCESS_ENABLE_16,
    SCU_ACCESS_ENABLE_17,
    SCU_ACCESS_ENABLE_18,
    SCU_ACCESS_ENABLE_19,
    SCU_ACCESS_ENABLE_20,
    SCU_ACCESS_ENABLE_21,
    SCU_ACCESS_ENABLE_22,
    SCU_ACCESS_ENABLE_23,
    SCU_ACCESS_ENABLE_24,
    SCU_ACCESS_ENABLE_25,
    SCU_ACCESS_ENABLE_26,
    SCU_ACCESS_ENABLE_27,
    SCU_ACCESS_ENABLE_28,
    SCU_ACCESS_ENABLE_29,
    SCU_ACCESS_ENABLE_30,
    SCU_ACCESS_ENABLE_31
} Scu_AccessEnableType_t;

#define CHECK_SCU_ACCESSENABLE(AccessEnable) ((AccessEnable >> POS_5_SHIFT) == 0U)

typedef enum
{
    LSTEST_CPU,
    LSTEST_PFIO,
} Scu_LockStepTestType_t;

typedef enum
{
    DEPTH_ESR0,
    DEPTH_ESR1,
} Scu_ESRType_t;

typedef enum
{
    OVERLAY_CPU0,
    OVERLAY_CPU1,
} Scu_OverLayType_t;

typedef enum
{
    RCU_EDG0,
    RCU_EDG1,
} Scu_EDGType_t;

typedef enum
{
    NO_TRIGGER,
    ONE_RISE_EDGE_ONE_TRIGGER,
    ONE_FALL_EDGE_ONE_TRIGGER,
    ONE_RISE_OR_FALL_ONE_TRIGGER,
} Rcu_EDGMODType_t;

typedef enum
{
    SCUERU_INPUTCHANNEL_0,
    SCUERU_INPUTCHANNEL_1,
    SCUERU_INPUTCHANNEL_2,
    SCUERU_INPUTCHANNEL_3,
    SCUERU_INPUTCHANNEL_4,
    SCUERU_INPUTCHANNEL_5,
    SCUERU_INPUTCHANNEL_6,
    SCUERU_INPUTCHANNEL_7,
} Scu_EruInputChannelType_t;

typedef enum
{
    SCUERU_TRIGGERCHANNEL_0,
    SCUERU_TRIGGERCHANNEL_1,
    SCUERU_TRIGGERCHANNEL_2,
    SCUERU_TRIGGERCHANNEL_3,
    SCUERU_TRIGGERCHANNEL_4,
    SCUERU_TRIGGERCHANNEL_5,
    SCUERU_TRIGGERCHANNEL_6,
    SCUERU_TRIGGERCHANNEL_7,
} Scu_EruTriggerChannelType_t;

typedef enum
{
    SCUERU_OUTPUTCHANNEL_0,
    SCUERU_OUTPUTCHANNEL_1,
    SCUERU_OUTPUTCHANNEL_2,
    SCUERU_OUTPUTCHANNEL_3,
    SCUERU_OUTPUTCHANNEL_4,
    SCUERU_OUTPUTCHANNEL_5,
    SCUERU_OUTPUTCHANNEL_6,
    SCUERU_OUTPUTCHANNEL_7,
} Scu_EruOutputChannelType_t;

typedef enum
{
    SCUERU_EXTERNALINPUT_A,
    SCUERU_EXTERNALINPUT_B,
    SCUERU_EXTERNALINPUT_C,
    SCUERU_EXTERNALINPUT_D,
    SCUERU_EXTERNALINPUT_E,
    SCUERU_EXTERNALINPUT_F,
} Scu_EruExternalInputType_t;

typedef enum
{
    SCUERU_INTGATEPATTERN_NONE,
    SCUERU_INTGATEPATTERN_NONE_ALWAYSACTIVE,
    SCUERU_INTGATEPATTERN_NONE_PATTERNMATCH,
    SCUERU_INTGATEPATTERN_NONE_PATTERNMISS,
} Scu_EruIntGatePatternType_t;

typedef enum
{
    SCUERU_FILRQ0A,
    SCUERU_FILRQ5A,
    SCUERU_FILRQ2A,
    SCUERU_FILRQ3A,
    SCUERU_FILRQ0C,
    SCUERU_FILRQ1C,
    SCUERU_FILRQ3C,
    SCUERU_FILRQ2C,
    SCUERU_FILRQ4A,
    SCUERU_FILRQ6A,
    SCUERU_FILRQ1A,
    SCUERU_FILRQ7A,
    SCUERU_FILRQ6D,
    SCUERU_FILRQ4D,
    SCUERU_FILRQ2B,
    SCUERU_FILRQ3B,
    SCUERU_FILRQ7C,
} Scu_EruFilterPin_t;

typedef enum
{
    SCUERU_FILTER_DIV_DISABLE,
    SCUERU_FILTER_DIV_1,
    SCUERU_FILTER_DIV_2,
    SCUERU_FILTER_DIV_3,
    SCUERU_FILTER_DIV_4,
    SCUERU_FILTER_DIV_5,
    SCUERU_FILTER_DIV_6,
    SCUERU_FILTER_DIV_7,
    SCUERU_FILTER_DIV_8,
    SCUERU_FILTER_DIV_9,
    SCUERU_FILTER_DIV_10,
    SCUERU_FILTER_DIV_11,
    SCUERU_FILTER_DIV_12,
    SCUERU_FILTER_DIV_13,
    SCUERU_FILTER_DIV_14,
    SCUERU_FILTER_DIV_15,
} Scu_EruFilterClkDiv_t;

typedef enum
{
    SCUERU_FILTER_DEPTH_DISABLE,
    SCUERU_FILTER_DEPTH_1,
    SCUERU_FILTER_DEPTH_2,
    SCUERU_FILTER_DEPTH_3,
    SCUERU_FILTER_DEPTH_4,
    SCUERU_FILTER_DEPTH_5,
    SCUERU_FILTER_DEPTH_6,
    SCUERU_FILTER_DEPTH_7,
    SCUERU_FILTER_DEPTH_8,
    SCUERU_FILTER_DEPTH_9,
    SCUERU_FILTER_DEPTH_10,
    SCUERU_FILTER_DEPTH_11,
    SCUERU_FILTER_DEPTH_12,
    SCUERU_FILTER_DEPTH_13,
    SCUERU_FILTER_DEPTH_14,
    SCUERU_FILTER_DEPTH_15,
} Scu_EruFilterDepth_t;

typedef enum
{
    SCUWDT_DIVBY_16384,
    SCUWDT_DIVBY_64,
    SCUWDT_DIVBY_256,
    SCUWDT_DIVBY_512,
    SCUWDT_DIVBY_1024,
    SCUWDT_DIVBY_2048,
    SCUWDT_DIVBY_4096,
    SCUWDT_DIVBY_8192,
} Scu_WdtDivType_t;

typedef enum
{
    SCUWDT_STATUS_FLAG_ACCESS_ERROR           = 0U,
    SCUWDT_STATUS_FLAG_OVERFLOW_ERROR         = 1U,
    SCUWDT_STATUS_FLAG_DISABLED               = 4U,
    SCUWDT_STATUS_FLAG_TIMEOUT                = 5U,
    SCUWDT_STATUS_FLAG_UNLOCK_RESTRICTION     = 6U,
    SCUWDT_STATUS_FLAG_PASSWORD_AUTO_SEQUENCE = 7U,
    SCUWDT_STATUS_FLAG_TIMER_CHECK            = 8U,
} Scu_WdtStatusFlag_t;

typedef enum
{
    SCUGLB_STATUS_FLAG_ACCESS_ERROR   = 0U,
    SCUGLB_STATUS_FLAG_OVERFLOW_ERROR = 1U,
    SCUGLB_STATUS_FLAG_IS0            = 2U,
    SCUGLB_STATUS_FLAG_IS1            = 3U,
    SCUGLB_STATUS_FLAG_IS2            = 4U,
    SCUGLB_STATUS_FLAG_DISABLED       = 5U,
    SCUGLB_STATUS_FLAG_TIMEOUT        = 6U,
} Scu_GlobalEnInitStatusFlag_t;

typedef enum
{
    SCUWDT_CLK_SYS    = 0U,
    SCUWDT_CLK_INTLF  = 1U,
    SCUWDT_CLK_EXTLF  = 2U,
    SCUWDT_CLK_BACKUP = 3U,
} Scu_WdtClk_t;

typedef enum
{
    SCURCU_RESET_COLDPOWERON,
    SCURCU_RESET_SYSTEM,
    SCURCU_RESET_APPLICATION,
    SCURCU_RESET_WARMPOWERON,
    SCURCU_RESET_DEBUG,
    SCURCU_RESET_UNDEFINED,
} Scu_RcuResetType_t;

typedef enum
{
    SCURCU_TRIGGER_ESR0      = 0U,
    SCURCU_TRIGGER_ESR1      = 1U,
    SCURCU_TRIGGER_SMUALL    = 2U,
    SCURCU_TRIGGER_SMU       = 3U,
    SCURCU_TRIGGER_SW        = 4U,
    SCURCU_TRIGGER_STM0      = 5U,
    SCURCU_TRIGGER_STM1      = 6U,
    SCURCU_TRIGGER_PORST     = 16U,
    SCURCU_TRIGGER_CB0       = 18U,
    SCURCU_TRIGGER_CB1       = 19U,
    SCURCU_TRIGGER_CB3       = 20U,
    SCURCU_TRIGGER_DCDC11    = 21U,
    SCURCU_TRIGGER_LDO33     = 22U,
    SCURCU_TRIGGER_SWD       = 23U,
    SCURCU_TRIGGER_HSMS      = 24U,
    SCURCU_TRIGGER_HSMA      = 25U,
    SCURCU_TRIGGER_STBYR     = 26U,
    SCURCU_TRIGGER_LBPORST   = 27U,
    SCURCU_TRIGGER_LBTERM    = 28U,
    SCURCU_TRIGGER_UNDEFINED = 29U,
} Scu_RcuTriggerType_t;

typedef enum
{
    SCU_EMERGENCY_STOP_FLAG_SET   = 1U,
    SCU_EMERGENCY_STOP_FLAG_CLEAR = 2U,
} Scu_EmergencyStopFlag_t;

typedef enum
{
    SCU_EMERGENCY_STOP_POLARITY_HIGH = 0U,
    SCU_EMERGENCY_STOP_POLARITY_LOW  = 1U,
} Scu_EmergencyStopInputPolarity_t;

typedef enum
{
    SCU_EMERGENCY_STOP_MODE_SYNC  = 0U,
    SCU_EMERGENCY_STOP_MODE_ASYNC = 1U,
} Scu_EmergencyStopMode_t;

typedef enum
{
    SCU_EMERGENCY_STOP_PORTA = 0U,
    SCU_EMERGENCY_STOP_PORTB = 1U,
} Scu_EmergencyStopPort_t;

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                     SCU System Control Export Functions
 ******************************************************************************/

/**
 * @brief 设置ERU输入引脚滤波器使能
 *
 * @param Pin 设置滤波使能的引脚
 * @param State 是否使能
 *
 * @retval void
 */
KF_INLINE void Scu_LL_SetERUFilterPinEnabled(Scu_EruFilterPin_t Pin, bool State)
{
#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_EIFCTL_ADDR);
    regValue &= ~(1u << Pin);
    regValue |= (State << Pin);
    REG_WRITE(HWIO_SCU_EIFCTL_ADDR, regValue);
#else
    REG_BITS_WRITE(SCU_PTR->SCU_EIFCTL.reg, (1U << Pin), State);
#endif
}

/**
 * @brief 获取ERU输入引脚滤波器使能
 *
 * @param Pin 获取滤波使能的引脚
 *
 * @retval bool 是否使能
 */
KF_INLINE bool Scu_LL_GetERUFilterPinEnabled(Scu_EruFilterPin_t Pin)
{
#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_EIFCTL_ADDR);
    regValue &= (1u << Pin);
    regValue >>= (Pin);
    return ((regValue > 0U) ? true : false);
#else
    return (bool)(REG_BITS_READ(SCU_PTR->SCU_EIFCTL.reg, (1U << Pin), Pin));
#endif
}

/**
 * @brief 设置ERU数字滤波器时钟分频
 *
 * @param Div 时钟分频系数
 *
 * @retval void
 */
KF_INLINE void Scu_LL_SetERUFilterClkDiv(Scu_EruFilterClkDiv_t Div)
{
#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_EIFCTL_ADDR);
    regValue &= (~HWIO_SCU_EIFCTL_SCU_EIFCTL_FILTDIV_MASK);
    regValue |= (Div << HWIO_SCU_EIFCTL_SCU_EIFCTL_FILTDIV_SHFT);
    REG_WRITE(HWIO_SCU_EIFCTL_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_EIFCTL.bits.FILTDIV, Div);
#endif
}

/**
 * @brief 设置ERU数字滤波深度
 *
 * @param Depth ERU数字滤波深度
 *
 * @retval void
 */
KF_INLINE void Scu_LL_SetERUFilterDepth(Scu_EruFilterDepth_t Depth)
{
#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_EIFCTL_ADDR);
    regValue &= (~HWIO_SCU_EIFCTL_SCU_EIFCTL_DEPTH_MASK);
    regValue |= (Depth << HWIO_SCU_EIFCTL_SCU_EIFCTL_DEPTH_SHFT);
    REG_WRITE(HWIO_SCU_EIFCTL_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_EIFCTL.bits.DEPTH, Depth);
#endif
}

/**
 * @brief 紧急停止输入极性选择
 *
 * @param Polarity
 *          SCU_EMERGENCY_STOP_POLARITY_HIGH - 高电平有效
 *          SCU_EMERGENCY_STOP_POLARITY_LOW - 低电平有效
 *
 * @retval void
 */
KF_INLINE void Scu_LL_SetEmergencyStopInputPolarity(Scu_EmergencyStopInputPolarity_t Polarity)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_ESCTL_ADDR);
    regValue &= ~HWIO_SCU_ESCTL_SCU_ESCTL_POL_MASK;
    regValue |= Polarity << HWIO_SCU_ESCTL_SCU_ESCTL_POL_SHFT;
    REG_WRITE(HWIO_SCU_ESCTL_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_ESCTL.bits.POL, Polarity);
#endif
}

/**
 * @brief 紧急停止模式选择
 *
 * @param Mode
 *          SCU_EMERGENCY_STOP_MODE_SYNC - 同步模式
 *          SCU_EMERGENCY_STOP_MODE_ASYNC - 异步模式
 *
 * @retval void
 */
KF_INLINE void Scu_LL_SetEmergencyStopMode(Scu_EmergencyStopMode_t Mode)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_ESCTL_ADDR);
    regValue &= ~HWIO_SCU_ESCTL_SCU_ESCTL_MODE_MASK;
    regValue |= Mode << HWIO_SCU_ESCTL_SCU_ESCTL_MODE_SHFT;
    REG_WRITE(HWIO_SCU_ESCTL_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_ESCTL.bits.MODE, Mode);
#endif
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
KF_INLINE void Scu_LL_SetEmergencyStopFlagEnabled(bool State)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_ESCTL_ADDR);
    regValue &= ~HWIO_SCU_ESCTL_SCU_ESCTL_ENON_MASK;
    regValue |= State << HWIO_SCU_ESCTL_SCU_ESCTL_ENON_SHFT;
    REG_WRITE(HWIO_SCU_ESCTL_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_ESCTL.bits.ENON, State);
#endif
}

/**
 * @brief 紧急停止输入引脚选择
 *
 * @param Select
 *          SCU_EMERGENCY_STOP_PORTA - PortA触发紧急停止
 *          SCU_EMERGENCY_STOP_PORTB - PortB触发紧急停止
 *
 * @retval void
 */
KF_INLINE void Scu_LL_EmergencyStopPortSelect(Scu_EmergencyStopPort_t Select)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_ESCTL_ADDR);
    regValue &= ~HWIO_SCU_ESCTL_SCU_ESCTL_PSEL_MASK;
    regValue |= Select << HWIO_SCU_ESCTL_SCU_ESCTL_PSEL_SHFT;
    REG_WRITE(HWIO_SCU_ESCTL_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_ESCTL.bits.PSEL, Select);
#endif
}

/**
 * @brief 获取紧急停止标志位
 *
 * @retval bool
 */
KF_INLINE bool Scu_LL_GetEmergencyStopFlag(void)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue &= HWIO_SCU_ESCTL_SCU_ESCTL_EMSF_MASK;
    regValue = regValue >> HWIO_SCU_ESCTL_SCU_ESCTL_EMSF_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return (REG_BIT_BOOLED(SCU_PTR->SCU_ESCTL.bits.EMSF, (1U << 16U)));
#endif
}

/**
 * @brief 获取SMU触发紧急停止标志位
 *
 * @retval bool
 */
KF_INLINE bool Scu_LL_GetSafetyEmergencyStopFlag(void)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue &= HWIO_SCU_ESCTL_SCU_ESCTL_SEMSF_MASK;
    regValue = regValue >> HWIO_SCU_ESCTL_SCU_ESCTL_SEMSF_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return (REG_BIT_BOOLED(SCU_PTR->SCU_ESCTL.bits.SEMSF, (1U << 17U)));
#endif
}

/**
 * @brief 修改安全控制紧急停止标志位
 *
 * @param Select
 *          SCU_EMERGENCY_STOP_FLAG_SET - 置位
 *          SCU_EMERGENCY_STOP_FLAG_CLEAR - 清零
 *
 * @retval void
 */
KF_INLINE void Scu_LL_SafetyEmergencyStopFlagSelect(Scu_EmergencyStopFlag_t Select)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_ESSWCTL_ADDR);
    regValue &= ~HWIO_SCU_ESSWCTL_SCU_ESSWCTL_SEMSFM_MASK;
    regValue |= Select << HWIO_SCU_ESSWCTL_SCU_ESSWCTL_SEMSFM_SHFT;
    REG_WRITE(HWIO_SCU_ESSWCTL_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_ESSWCTL.bits.SEMSFM, Select);
#endif
}

/**
 * @brief 修改紧急停止标志位
 *
 * @param Select
 *          SCU_EMERGENCY_STOP_FLAG_SET - 置位
 *          SCU_EMERGENCY_STOP_FLAG_CLEAR - 清零
 *
 * @retval void
 */
KF_INLINE void Scu_LL_EmergencyStopFlagSelect(Scu_EmergencyStopFlag_t Select)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_ESSWCTL_ADDR);
    regValue &= ~HWIO_SCU_ESSWCTL_SCU_ESSWCTL_EMSFM_MASK;
    regValue |= Select << HWIO_SCU_ESSWCTL_SCU_ESSWCTL_EMSFM_SHFT;
    REG_WRITE(HWIO_SCU_ESSWCTL_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_ESSWCTL.bits.EMSFM, Select);
#endif
}

/**
 * @brief 信号边沿检测控制
 * @param EDG
 * RCU_EDG0,
 * RCU_EDG1,
 * @param Signal
 *   NO_TRIGGER
 *   ONE_RISE_EDGE_ONE_TRIGGER
 *   ONE_FALL_EDGE_ONE_TRIGGER
 *   ONE_RISE_OR_FALL_ONE_TRIGGER
 * @retval void
 */
KF_INLINE void Scu_LL_RcuSetSignalEdgeCtl(Scu_EDGType_t EDG, Rcu_EDGMODType_t Signal)
{
#ifdef SIMULATION
    if (RCU_EDG0 == EDG)
    {
        uint32_t regValue = REG_READ(HWIO_SCU_EDG0_ADDR);
        regValue &= ~HWIO_SCU_EDG0_SCU_EDG0_EDGMOD_MASK;
        regValue |= Signal << HWIO_SCU_EDG0_SCU_EDG0_EDGMOD_SHFT;
        REG_WRITE(HWIO_SCU_EDG0_ADDR, regValue);
    }
    else
    {
        uint32_t regValue = REG_READ(HWIO_RCU_EDG1_ADDR);
        regValue &= ~HWIO_RCU_EDG1_RCU_EDG1_EDGMOD_MASK;
        regValue |= Signal << HWIO_RCU_EDG1_RCU_EDG1_EDGMOD_SHFT;
        REG_WRITE(HWIO_RCU_EDG1_ADDR, regValue);
    }
#else
    REG_WRITE(SCU_PTR->RCU_EDG[EDG].bits.EDGMOD, Signal);
#endif
}

/**
 * @brief 获取SCU模块版本信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_GetModuleVersion(void)
{
#ifdef SIMULATION
    return ((REG_READ(HWIO_SCU_ID_ADDR) & HWIO_SCU_ID_SCU_ID_REVISION_MASK) >> HWIO_SCU_ID_SCU_ID_REVISION_SHFT);
#else
    return (REG_READ(SCU_PTR->SCU_ID.bits.REVISION));
#endif
}

/**
 * @brief 获取SCU模块类型信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_GetModuleType(void)
{
#ifdef SIMULATION
    return ((REG_READ(HWIO_SCU_ID_ADDR) & HWIO_SCU_ID_SCU_ID_TYPE_MASK) >> HWIO_SCU_ID_SCU_ID_TYPE_SHFT);
#else
    return (REG_READ(SCU_PTR->SCU_ID.bits.TYPE));
#endif
}

/**
 * @brief 获取SCU模块ID信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_GetModuleId(void)
{
#ifdef SIMULATION
    return ((REG_READ(HWIO_SCU_ID_ADDR) & HWIO_SCU_ID_SCU_ID_NUMBER_MASK) >> HWIO_SCU_ID_SCU_ID_NUMBER_SHFT);
#else
    return (REG_READ(SCU_PTR->SCU_ID.bits.NUMBER));
#endif
}

/**
 * @brief 获取SCU CHIP PFLASH 大小
 *
 *
 * @param void
 * @retval Scu_FlashSizeType_t
 */
KF_INLINE Scu_FlashSizeType_t Scu_LL_GetChipFlashSize(void)
{
#ifdef SIMULATION
    return (Scu_FlashSizeType_t)((REG_READ(HWIO_SCU_CHIPID_ADDR) & HWIO_SCU_CHIPID_SCU_CHIPID_FSIZE_MASK) >>
                                 HWIO_SCU_CHIPID_SCU_CHIPID_FSIZE_SHFT);
#else
    return ((Scu_FlashSizeType_t)REG_READ(SCU_PTR->SCU_CHIPID.bits.FSIZE));
#endif
}

/**
 * @brief 获取SCU CHIP 封装信息
 *
 *
 * @param void
 * @retval Scu_PackageType_t
 */
KF_INLINE Scu_PackageType_t Scu_LL_GetPackageInfo(void)
{
#ifdef SIMULATION
    return (Scu_PackageType_t)((REG_READ(HWIO_SCU_CHIPID_ADDR) & HWIO_SCU_CHIPID_SCU_CHIPID_CHPK_MASK) >>
                               HWIO_SCU_CHIPID_SCU_CHIPID_CHPK_SHFT);
#else
    return ((Scu_PackageType_t)REG_READ(SCU_PTR->SCU_CHIPID.bits.CHPK));
#endif
}

/**
 * @brief 获取SCU CHIP ID信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_GetChipID(void)
{
#ifdef SIMULATION
    return (
      (REG_READ(HWIO_SCU_CHIPID_ADDR) & HWIO_SCU_CHIPID_SCU_CHIPID_CHID_MASK) >> HWIO_SCU_CHIPID_SCU_CHIPID_CHID_SHFT);
#else
    return (REG_READ(SCU_PTR->SCU_CHIPID.bits.CHID));
#endif
}

/**
 * @brief 获取SCU CHIP 程序版本信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_GetFlashDriverID(void)
{
#ifdef SIMULATION
    return ((REG_READ(HWIO_SCU_CHIPID_ADDR) & HWIO_SCU_CHIPID_SCU_CHIPID_UCORE_MASK) >>
            HWIO_SCU_CHIPID_SCU_CHIPID_UCORE_SHFT);
#else
    return (REG_READ(SCU_PTR->SCU_CHIPID.bits.UCORE));
#endif
}

/**
 * @brief 获取SCU FACTORY 信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_GetFactoryInfo(void)
{
#ifdef SIMULATION
    return (
      (REG_READ(HWIO_SCU_CHIPID_ADDR) & HWIO_SCU_MANID_SCU_MANID_INFO_MASK) >> HWIO_SCU_MANID_SCU_MANID_INFO_SHFT);
#else
    return (REG_READ(SCU_PTR->SCU_MANID.bits.INFO));
#endif
}

/**
 * @brief 使能SCU访问控制
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval void
 */
KF_INLINE void Scu_LL_EnableAccess(Scu_AccessP0Type_t AccessType, Scu_AccessEnableType_t AccessEnable)
{
    KF_DRV_SCU_ASSERT(CHECK_SCU_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_ACCEN00_ADDR + ((uint32_t)AccessType << 3));
    regValue |= (MASK_1_BIT << AccessEnable);
    REG_WRITE(HWIO_SCU_ACCEN00_ADDR + ((uint32_t)AccessType << 3), regValue);
#else
    if (SCU_ACCESS_00 == AccessType)
    {
        REG_BIT_SET(SCU_PTR->SCU_ACCEN00.reg, MASK_1_BIT << AccessEnable);
    }
    else
    {
        REG_BIT_SET(SCU_PTR->SCU_ACCEN10.reg, MASK_1_BIT << AccessEnable);
    }
#endif
}

/**
 * @brief 获取SCU访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE bool Scu_LL_GetAccess(Scu_AccessP0Type_t AccessType, Scu_AccessEnableType_t AccessEnable)
{
    KF_DRV_SCU_ASSERT(CHECK_SCU_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
    return (
      REG_BITS_READ(HWIO_SCU_ACCEN00_ADDR + ((uint32_t)AccessType << 3), MASK_1_BIT << AccessEnable, AccessEnable));
#else
    if (SCU_ACCESS_00 == AccessType)
    {
        return (REG_BITS_READ(SCU_PTR->SCU_ACCEN00.reg, MASK_1_BIT << AccessEnable, AccessEnable));
    }
    else
    {
        return (REG_BITS_READ(SCU_PTR->SCU_ACCEN10.reg, MASK_1_BIT << AccessEnable, AccessEnable));
    }
#endif
}

/**
 * @brief 设置CPU0锁步状态
 *
 *
 * @ param bool
 *         true:启用锁步状态
 *         false:禁用锁步状态
 * @ retval void
 */
KF_INLINE void Scu_LL_SetLockStep(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0LCKCTL_ADDR);
    regValue &= ~HWIO_SCU_CPU0LCKCTL_SCU_CPU0LCKCTL_CPU0LSEN_MASK;
    regValue |= Status << HWIO_SCU_CPU0LCKCTL_SCU_CPU0LCKCTL_CPU0LSEN_SHFT;
    REG_WRITE(HWIO_SCU_CPU0LCKCTL_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_CPU0LCKCTL.bits.CPU0LSEN, Status);
#endif
}

/**
 * @brief 获取CPU0锁步状态
 *
 *
 * @ param void
 * @ retval bool
 *         true:CPU0处于锁步模式下
 *         false:CPU0未在锁步模式下
 */
KF_INLINE bool Scu_LL_GetLockStep(void)
{
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_SCU_CPU0LCKSTA_ADDR, HWIO_SCU_CPU0LCKSTA_SCU_CPU0LCKSTA_CPU0LSSTA_MASK,
                          HWIO_SCU_CPU0LCKSTA_SCU_CPU0LCKSTA_CPU0LSSTA_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_CPU0LCKSTA.bits.CPU0LSSTA));
#endif
}

/**
 * @brief 设置CPU0 锁步测试
 *
 *
 * @ param Scu_LockStepTestType_t
 *         LSTEST_CPU
 *         LSTEST_PFIO
 *         bool
 *         true:对相应的测试类型进行故障注入
 *         false:无作用
 * @ retval void
 */
KF_INLINE void Scu_LL_SetLockStepTest(Scu_LockStepTestType_t TestType, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0LCKTEST_ADDR);
    regValue &= ~(MASK_1_BIT << (POS_16_SHIFT * TestType));
    regValue |= (Status << (POS_16_SHIFT * TestType));
    REG_WRITE(HWIO_SCU_CPU0LCKTEST_ADDR, regValue);
#else
    REG_BITS_WRITE(
      SCU_PTR->SCU_CPU0LCKTEST.reg, MASK_1_BIT << (POS_16_SHIFT * TestType), Status << (POS_16_SHIFT * TestType));
#endif
}

// TODO:相关 LBIST 功能需要理解清楚并补充相应API

/**
 * @brief 设置CPU 覆盖控制
 *
 *
 * @ param Scu_OverLayType_t
 *         OVERLAY_CPU0
 *         OVERLAY_CPU0
 *         bool
 *         true:启用覆盖控制
 *         false:禁用覆盖控制
 * @ retval void
 */
KF_INLINE void Scu_LL_SetOverLay(Scu_OverLayType_t OverLay, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_OVLAYCTL0_ADDR);
    regValue &= ~(MASK_1_BIT << OverLay);
    regValue |= (Status << OverLay);
    REG_WRITE(HWIO_SCU_OVLAYCTL0_ADDR, regValue);
#else
    REG_BITS_WRITE(SCU_PTR->SCU_OVLAYCTL0.reg, MASK_1_BIT << OverLay, Status << OverLay);
#endif
}

// TODO:相关 OVERLAY 功能需要理解清楚并补充相应API

/******************************************************************************
 *                     RCU Export Functions
 ******************************************************************************/
/**
 * @brief APRSTA位清零
 * @param bool
 * false 无影响
 * true 清除APRSTA
 * @retval void
 */
KF_INLINE void Scu_LL_RcuClrAPRSTRA(bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RCU_OUTCF_ADDR);
    regValue &= ~HWIO_RCU_OUTCF_RCU_OUTCF_APRSTACLR_MASK;
    regValue |= Status << HWIO_RCU_OUTCF_RCU_OUTCF_APRSTACLR_SHFT;
    REG_WRITE(HWIO_RCU_OUTCF_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->RCU_OUTCF.bits.APRSTACLR, Status);
#endif
}

/**
 * @brief 应用程序复位指示
 * @param void
 * @retval void
 * false 自从上次清零后未检测到应用程序复位
 * true 自从上次清零后检测到应用程序复位
 */
KF_INLINE bool Scu_LL_RcuAppProgramReset(void)
{
#ifdef SIMULATION
    return (
      REG_BITS_READ(HWIO_RCU_OUTCF_ADDR, HWIO_RCU_OUTCF_RCU_OUTCF_APRSTA_MASK, HWIO_RCU_OUTCF_RCU_OUTCF_APRSTA_SHFT));
#else
    return REG_READ(SCU_PTR->RCU_OUTCF.bits.APRSTA);
#endif
}

/**
 * @brief 设置数字滤波器比较深度
 * @ param Scu_ESRType_t
 *         DEPTH_ESR0
 *         DEPTH_ESR1
 * @ uint8_t
 * @ retval void
 */
KF_INLINE void Scu_LL_SetDigitalFilterDepth(Scu_ESRType_t EsrType, const uint8_t Depth)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RCU_DEPTH_ADDR);
    regValue &= ~(MASK_4_BIT << (POS_16_SHIFT * EsrType));
    regValue |= (Depth << (POS_16_SHIFT * EsrType));
    REG_WRITE(HWIO_RCU_DEPTH_ADDR, regValue);
#else
    REG_BITS_WRITE(SCU_PTR->RCU_DEPTH.reg, MASK_4_BIT << (POS_16_SHIFT * EsrType), Depth << (POS_16_SHIFT * Depth));
#endif
}

/**
 * @brief 获取 指定触发请求状态
 *
 *
 * @param Scu_RcuTriggerType_t
 * @retval bool
 *         true:产生相应触发类型的请求
 *         false:没有产生相应触发类型的请求
 */
KF_INLINE bool Scu_LL_RcuGetResetTriggerState(Scu_RcuTriggerType_t RcuTrigger)
{
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_RCU_STA_ADDR, (MASK_1_BIT << RcuTrigger), RcuTrigger));
#else
    return (REG_BITS_READ(SCU_PTR->RCU_STA.reg, MASK_1_BIT << RcuTrigger, RcuTrigger));
#endif
}

/**
 * @brief 设置 指定触发类型
 *
 *
 * @param Scu_RcuTriggerType_t
 * @param Scu_RcuResetType_t
 * @retval void
 */
KF_INLINE void Scu_LL_RcuSetResetType(Scu_RcuTriggerType_t RcuTrigger, Scu_RcuResetType_t ResetType)
{
    // TODO:需要确定RCU_CTL0 BIT6~BIT7是 SMUMOD 还是 SACURMOD
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RCU_CTL0_ADDR);
    regValue &= ~(MASK_2_BIT << (RcuTrigger * POS_2_SHIFT));
    regValue |= (ResetType << (RcuTrigger * POS_2_SHIFT));
    REG_WRITE(HWIO_RCU_CTL0_ADDR, regValue);
#else
    REG_BITS_WRITE(
      SCU_PTR->RCU_CTL0.reg, MASK_2_BIT << (RcuTrigger * POS_2_SHIFT), ResetType << (RcuTrigger * POS_2_SHIFT));
#endif
}

/**
 * @brief 获取 指定触发类型
 *
 *
 * @param Scu_RcuTriggerType_t
 * @retval Scu_RcuResetType_t
 */
KF_INLINE Scu_RcuResetType_t Scu_LL_RcuGetResetType(Scu_RcuTriggerType_t RcuTrigger)
{
    // TODO:需要确定RCU_CTL0 BIT6~BIT7是 SMUMOD 还是 SACURMOD
#ifdef SIMULATION
    return ((Scu_RcuResetType_t)REG_BITS_READ(
      HWIO_RCU_CTL0_ADDR, MASK_2_BIT << (RcuTrigger * POS_2_SHIFT), RcuTrigger * POS_2_SHIFT));
#else
    return ((Scu_RcuResetType_t)REG_BITS_READ(
      SCU_PTR->RCU_CTL0.reg, MASK_2_BIT << (RcuTrigger * POS_2_SHIFT), RcuTrigger * POS_2_SHIFT));
#endif
}

/**
 * @brief 设置 用户复位信息
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_RcuSetResetInfo(uint32_t ResetInfo)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RCU_CTL1_ADDR);
    regValue &= ~HWIO_RCU_CTL1_RCU_CTL1_USINFOR_MASK;
    regValue |= ResetInfo << HWIO_RCU_CTL1_RCU_CTL1_USINFOR_SHFT;
    REG_WRITE(HWIO_RCU_CTL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(SCU_PTR->RCU_CTL1.bits.USINFOR, ResetInfo);
#endif
}

/**
 * @brief 获取 用户复位信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_RcuGetResetInfo(void)
{
#ifdef SIMULATION
    return (
      REG_BITS_READ(HWIO_RCU_CTL1_ADDR, HWIO_RCU_CTL1_RCU_CTL1_USINFOR_MASK, HWIO_RCU_CTL1_RCU_CTL1_USINFOR_SHFT));
#else
    return (REG_READ(SCU_PTR->RCU_CTL1.bits.USINFOR));
#endif
}

/**
 * @brief 产生一次软件复位
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Scu_LL_RcuEnableSoftReset(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RCU_SW_ADDR);
    regValue &= ~HWIO_RCU_SW_RCU_SW_SWRQ_MASK;
    regValue |= true << HWIO_RCU_SW_RCU_SW_SWRQ_SHFT;
    REG_WRITE(HWIO_RCU_SW_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->RCU_SW.bits.SWRQ, true);
#endif
}

/**
 * @brief 清除冷复位状态
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Scu_LL_RcuClearColdResetStatus(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_RCU_CTL1_ADDR);
    regValue &= ~HWIO_RCU_CTL1_RCU_CTL1_COLDCLR_MASK;
    regValue |= (true << HWIO_RCU_CTL1_RCU_CTL1_COLDCLR_SHFT);
    REG_WRITE(HWIO_RCU_CTL1_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->RCU_CTL1.bits.COLDCLR, true);
#endif
}

/******************************************************************************
 *                     WDT Export Functions
 ******************************************************************************/
/**
 * @brief 获取CPUx看门狗状态
 *
 * @param CPU
 * @param Flag 待获取状态标志位
 *
 * @retval bool
 */
KF_INLINE bool Scu_LL_GetCpuWdtStatus(Scu_CPUType_t CPU, Scu_WdtStatusFlag_t Flag)
{
#if SIMULATION
    uint32_t regValue = 0U;

    if (SCU_CPU0 == CPU)
    {
        regValue = REG_READ(HWIO_SCU_CPU0WDTSTA_ADDR);
    }
    else
    {
        regValue = REG_READ(HWIO_SCU_CPU1WDTSTA_ADDR);
    }

    regValue &= (1U << Flag);
    regValue = regValue >> Flag;

    return ((regValue > 0U) ? true : false);

#else
    bool retVal = true;

    retVal = REG_BIT_BOOLED(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTSTA.reg, (1U << Flag));

    return retVal;
#endif
}

/**
 * @brief 获取CPUx看门狗计数器检查公差
 *
 * @param CPU
 *
 * @retval bool
 */
KF_INLINE uint8_t Scu_LL_GetCpuWdtCheckTolerance(Scu_CPUType_t CPU)
{
#if SIMULATION
    uint32_t regValue = 0U;

    if (SCU_CPU0 == CPU)
    {
        regValue = REG_READ(HWIO_SCU_CPU0WDTSTA_ADDR);
    }
    else
    {
        regValue = REG_READ(HWIO_SCU_CPU1WDTSTA_ADDR);
    }

    regValue &= HWIO_SCU_CPU0WDTSTA_SCU_CPU0WDTSTA_TCT_MASK;
    regValue = regValue >> HWIO_SCU_CPU0WDTSTA_SCU_CPU0WDTSTA_TCT_SHFT;

    return (uint8_t)regValue;

#else
    uint8_t retVal = 0U;

    retVal = REG_READ(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTSTA.bits.TCT);

    return retVal;
#endif
}

/**
 * @brief 获取CPUx看门狗超时计数器值
 *
 * @param CPU
 *
 * @retval bool
 */
KF_INLINE uint16_t Scu_LL_GetCpuWdtTimerValue(Scu_CPUType_t CPU)
{
#if SIMULATION
    uint32_t regValue = 0U;

    if (SCU_CPU0 == CPU)
    {
        regValue = REG_READ(HWIO_SCU_CPU0WDTSTA_ADDR);
    }
    else
    {
        regValue = REG_READ(HWIO_SCU_CPU1WDTSTA_ADDR);
    }

    regValue &= HWIO_SCU_CPU0WDTSTA_SCU_CPU0WDTSTA_TIM_MASK;
    regValue = regValue >> HWIO_SCU_CPU0WDTSTA_SCU_CPU0WDTSTA_TIM_SHFT;

    return (uint16_t)regValue;

#else
    uint16_t retVal = 0U;

    retVal = REG_READ(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTSTA.bits.TIM);

    return retVal;
#endif
}

/**
 * @brief 获取CPU 看门狗控制寄存器0锁定状态
 *
 *
 * @param CPU
 * @retval bool
 *         true:寄存器被锁定
 *         false:寄存器被解锁
 */
KF_INLINE bool Scu_LL_WdtGetCpuRegLockState(Scu_CPUType_t CPU)
{
    // TODO:LCK位是否可以使用软件操作，是否可以全部使用硬件操作
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_SCU_CPU0WDTCTL0_ADDR, HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_MASK,
                          HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.bits.LCK));
#endif
}

/**
 * @brief 锁定CPU 看门狗控制寄存器0
 *
 *
 * @param CPU
 * @retval void
 */
KF_INLINE void Scu_LL_WdtlockCpuReg(Scu_CPUType_t CPU)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
    regValue &= ~HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK;
    regValue |= (true << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT);
    REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
    while (REG_BITS_READ(HWIO_SCU_CPU0WDTCTL0_ADDR, HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK,
                         HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT) == false)
        ;
#else
    REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.bits.ENDINIT, true);
    while (SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.bits.ENDINIT == false)
        ;
#endif
}

/**
 * @brief 解锁CPU 看门狗控制寄存器0锁定状态
 *
 *
 * @param CPU
 * @retval void
 */
KF_INLINE void Scu_LL_WdtUnlockCpuReg(Scu_CPUType_t CPU)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
    regValue &= ~HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK;
    regValue |= (false << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT);
    REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
    while (REG_BITS_READ(HWIO_SCU_CPU0WDTCTL0_ADDR, HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK,
                         HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT) == true)
        ;
#else
    REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.bits.ENDINIT, false);
    while (SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.bits.ENDINIT == true)
        ;
#endif
}

/**
 * @brief 获取CPU 受SE保护的寄存器访问状态
 *
 *
 * @param CPU
 * @retval bool
 */
KF_INLINE bool Scu_LL_WdtGetCpuEndInit(Scu_CPUType_t CPU)
{
#ifdef SIMULATION
    return (bool)(REG_BITS_READ(
      HWIO_SCU_CPU0WDTCTL0_ADDR, HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK,
      HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.bits.ENDINIT));
#endif
}

/**
 * @brief 设置CPU 看门狗 Password
 *
 *
 * @param CPU
 * @param PassWord
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetCpuWdgPassword(Scu_CPUType_t CPU, uint32_t PassWord)
{
    // TODO:passWord写时是否需要异或操作
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
    regValue &= ~HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_MASK;
    regValue |= (PassWord << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_SHFT);
    REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.bits.PW, PassWord);
#endif
}

/**
 * @brief 获取CPU 看门狗 Password
 *
 *
 * @param CPU
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_WdtGetCpuWdgPassword(Scu_CPUType_t CPU)
{
    uint32_t password;
#ifdef SIMULATION
    password = REG_BITS_READ(
      HWIO_SCU_CPU0WDTCTL0_ADDR, HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_MASK,
      HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_SHFT);
#else
    password = REG_READ(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.bits.PW);
#endif

    // TODO:不确定是否需要异或操作
    password ^= 0x003F;
    return password;
}

/**
 * @brief 设置CPU 看门狗 Reload
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetCpuWdgReload(Scu_CPUType_t CPU, uint32_t Reload)
{
    // TODO:passWord写时是否需要异或操作
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
    regValue &= ~HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_MASK;
    regValue |= (Reload << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_SHFT);
    REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.bits.REL, Reload);
#endif
}

/**
 * @brief 获取CPU 看门狗 Reload
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE uint32_t Scu_LL_WdtGetCpuWdgReload(Scu_CPUType_t CPU)
{
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_SCU_CPU0WDTCTL0_ADDR, HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_MASK,
                          HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.bits.REL));
#endif
}

/**
 * @brief 获取SAFETY 看门狗控制寄存器0锁定状态
 *
 *
 * @param CPU
 * @retval bool
 *         true:寄存器被锁定
 *         false:寄存器被解锁
 */
KF_INLINE bool Scu_LL_WdtGetSafetyRegLockState(void)
{
    // TODO:LCK位是否可以使用软件操作，是否可以全部使用硬件操作
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_SWDTCTL0_ADDR, HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_MASK, HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_SWDTCTL0.bits.LCK));
#endif
}

/**
 * @brief 锁定SAFETY 受SE保护的寄存器访问状态
 *
 *
 * @param CPU
 * @retval void
 */
KF_INLINE void Scu_LL_WdtlockSafetyReg(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
    regValue &= ~HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK;
    regValue |= true << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT;
    REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_SWDTCTL0.bits.ENDINIT, true);
#endif
#ifdef SIMULATION
    while (REG_BITS_READ(HWIO_SCU_SWDTCTL0_ADDR, HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK,
                         HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT) == false)
        ;
#else
    while (REG_READ(SCU_PTR->SCU_SWDTCTL0.bits.ENDINIT) == false)
        ;
#endif
}

/**
 * @brief 解锁SAFETY 受SE保护的寄存器访问状态
 *
 *
 * @param CPU
 * @retval void
 */
KF_INLINE void Scu_LL_WdtUnlockSafetyReg(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
    regValue &= ~HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK;
    regValue |= false << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT;
    REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_SWDTCTL0.bits.ENDINIT, false);
#endif
#ifdef SIMULATION
    while (REG_BITS_READ(HWIO_SCU_SWDTCTL0_ADDR, HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK,
                         HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT) == true)
        ;
#else
    while (REG_READ(SCU_PTR->SCU_SWDTCTL0.bits.ENDINIT) == true)
        ;
#endif
}

/**
 * @brief 获取SAFETY 受SE保护的寄存器访问状态
 *
 *
 * @param void
 * @retval bool
 */
KF_INLINE bool Scu_LL_WdtGetSafetyEndInit(void)
{
#ifdef SIMULATION
    return (bool)(REG_BITS_READ(
      HWIO_SCU_SWDTCTL0_ADDR, HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK,
      HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_SWDTCTL0.bits.ENDINIT));
#endif
}

/**
 * @brief 设置SAFETY 看门狗 Password
 *
 *
 * @param Password
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetSafetyWdgPassword(uint32_t Password)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
    regValue &= ~HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_MASK;
    regValue |= Password << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_SHFT;
    REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);

#else
    REG_WRITE(SCU_PTR->SCU_SWDTCTL0.bits.PW, Password);
#endif
}

/**
 * @brief 设置SAFETY 看门狗 Reload
 *
 *
 * @param Reload
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetSafetyWdgReload(uint32_t Reload)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
    regValue &= ~HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_MASK;
    regValue |= Reload << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_SHFT;
    REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_SWDTCTL0.bits.REL, Reload);
#endif
}

/**
 * @brief 获取SAFETY 看门狗 Password
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_WdtGetSafetyWdgPassword(void)
{
    uint32_t password;
#ifdef SIMULATION
    password = REG_BITS_READ(
      HWIO_SCU_SWDTCTL0_ADDR, HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_MASK, HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_SHFT);
#else
    password = REG_READ(SCU_PTR->SCU_SWDTCTL0.bits.PW);
#endif
    // TODO:不确定是否需要异或操作
    password ^= 0x003F;
    return password;
}

/**
 * @brief 获取SAFETY 看门狗 Reload
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_WdtGetSafetyWdgReload(void)
{
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_SWDTCTL0_ADDR, HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_MASK, HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_SWDTCTL0.bits.REL));
#endif
}

/**
 * @brief 设置Global 看门狗 Reload
 *
 *
 * @param Reload
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetGlobalWdgReload(uint16_t Reload)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_GECTL0_ADDR);
    regValue &= ~(HWIO_SCU_GECTL0_SCU_GECTL0_REL_MASK);
    regValue |= Reload << HWIO_SCU_GECTL0_SCU_GECTL0_REL_SHFT;

    REG_WRITE(HWIO_SCU_GECTL0_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_GECTL0.bits.REL, Reload);
#endif
}

/**
 * @brief 获取Global 看门狗 Reload
 *
 *
 * @param Reload
 * @retval void
 */
KF_INLINE uint16_t Scu_LL_WdtGetGlobalWdgReload(void)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_GECTL0_ADDR);
    regValue &= HWIO_SCU_GECTL0_SCU_GECTL0_REL_MASK;
    regValue = regValue >> HWIO_SCU_GECTL0_SCU_GECTL0_REL_SHFT;

    return (uint16_t)regValue;
#else
    return (REG_READ(SCU_PTR->SCU_GECTL0.bits.REL));
#endif
}

/**
 * @brief 获取Global看门狗超时计数器值
 *
 * @retval uint16_t
 */
KF_INLINE uint16_t Scu_LL_GetGlobalWdtTimerValue()
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_GESTA_ADDR);
    regValue &= HWIO_SCU_GESTA_SCU_GESTA_TIM_MASK;
    regValue = regValue >> HWIO_SCU_GESTA_SCU_GESTA_TIM_SHFT;

    return (uint16_t)regValue;

#else
    uint16_t retVal = 0U;

    retVal = REG_READ(SCU_PTR->SCU_GESTA.bits.TIM);

    return retVal;
#endif
}

/**
 * @brief 全局看门狗定时器时钟选择位
 *
 * @param Clk
 *
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSelectGlobalWdgClk(Scu_WdtClk_t Clk)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_GECTL1_ADDR);
    regValue &= ~(HWIO_SCU_GECTL1_SCU_GECTL1_CSEL_MASK);
    regValue |= Clk << HWIO_SCU_GECTL1_SCU_GECTL1_CSEL_SHFT;

    REG_WRITE(HWIO_SCU_GECTL1_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_GECTL1.bits.CSEL, Clk);
#endif
}

/**
 * @brief 全局看门狗定时器时钟分频
 *
 * @param Div
 *
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSelectGlobalWdgClkDivide(Scu_WdtDivType_t Div)
{
#ifdef SIMULATION
    uint32_t divide   = (((uint32_t)Div & (~3U)) << 2U | ((uint32_t)Div & 3U));
    uint32_t mask     = 0x26U;
    uint32_t shift    = 1U;
    uint32_t regValue = REG_READ(HWIO_SCU_GECTL1_ADDR);
    regValue &= ~mask;
    regValue |= (divide << shift);
    REG_WRITE(HWIO_SCU_GECTL1_ADDR, regValue);
#else
    switch (Div)
    {
    case SCUWDT_DIVBY_16384: {
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_64: {
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_256: {
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_512: {
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_1024: {
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_2048: {
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_4096: {
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_8192: {
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_GECTL1.bits.IR2, 1U);
    }
    break;
    default:
        break;
    }
#endif
}

/**
 * @brief 请求禁用全局看门狗
 *
 *
 * @param bool
 *          false - 激活
 *          true - 禁用
 * @retval void
 */
KF_INLINE void Scu_LL_WdtRequestGlobalWdgDisable(const bool Status)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_GECTL1_ADDR);
    regValue &= ~(HWIO_SCU_GECTL1_SCU_GECTL1_DR_MASK);
    regValue |= Status << HWIO_SCU_GECTL1_SCU_GECTL1_DR_SHFT;

    REG_WRITE(SCU_PTR->SCU_GECTL1.reg, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_GECTL1.bits.DR, Status);
#endif
}

/**
 * @brief 获取全局ENDINIT状态
 *
 * @param CPU
 * @param Flag 待获取状态标志位
 *
 * @retval bool
 */
KF_INLINE bool Scu_LL_GetGlobalEndInitStatus(Scu_GlobalEnInitStatusFlag_t Flag)
{
#if SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_SCU_GESTA_ADDR);
    regValue &= (1U << Flag);
    regValue = regValue >> Flag;

    return ((regValue > 0U) ? true : false);
#else
    bool retVal = true;

    retVal = REG_BIT_BOOLED(SCU_PTR->SCU_GESTA.reg, (1U << Flag));

    return retVal;
#endif
}

/**
 * @brief 锁定GLOBAL 受SE保护的寄存器访问状态
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Scu_LL_WdtlockGlobalReg(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_GECTL0_ADDR);
    regValue &= ~HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_MASK;
    regValue |= true << HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_SHFT;
    REG_WRITE(HWIO_SCU_GECTL0_ADDR, regValue);

#else
    REG_WRITE(SCU_PTR->SCU_GECTL0.bits.ENDINIT, true);
#endif
#ifdef SIMULATION
    while (REG_BITS_READ(HWIO_SCU_GECTL0_ADDR, HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_MASK,
                         HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_SHFT) == false)
        ;
#else
    while (REG_READ(SCU_PTR->SCU_GECTL0.bits.ENDINIT) == false)
        ;
#endif
}

/**
 * @brief 解锁GLOBAL 受SE保护的寄存器访问状态
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Scu_LL_WdtUnlockGlobalReg(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_GECTL0_ADDR);
    regValue &= ~HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_MASK;
    regValue |= false << HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_SHFT;
    REG_WRITE(HWIO_SCU_GECTL0_ADDR, regValue);

#else
    REG_WRITE(SCU_PTR->SCU_GECTL0.bits.ENDINIT, false);
#endif
#ifdef SIMULATION
    while (REG_BITS_READ(HWIO_SCU_GECTL0_ADDR, HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_MASK,
                         HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_SHFT) == true)
        ;
#else
    while (REG_READ(SCU_PTR->SCU_GECTL0.bits.ENDINIT) == true)
        ;
#endif
}

/**
 * @brief 获取GLOBAL 受SE保护的寄存器访问状态
 *
 *
 * @param void
 * @retval bool
 */
KF_INLINE bool Scu_LL_WdtGetGlobalEndInit(void)
{
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_GECTL0_ADDR, HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_MASK, HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_GECTL0.bits.ENDINIT));
#endif
}

/**
 * @brief 设置GLOBAL 看门狗 Password
 *
 *
 * @param Password
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetGlobalWdgPassword(uint32_t Password)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_GECTL0_ADDR);
    regValue &= ~HWIO_SCU_GECTL0_SCU_GECTL0_EPW_MASK;
    regValue |= Password << HWIO_SCU_GECTL0_SCU_GECTL0_EPW_SHFT;
    REG_WRITE(HWIO_SCU_GECTL0_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_GECTL0.bits.EPW, Password);
#endif
}

/**
 * @brief 获取GLOBAL 看门狗 Password
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_WdtGetGlobalWdgPassword(void)
{
    uint32_t password;
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_GECTL0_ADDR, HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_MASK, HWIO_SCU_GECTL0_SCU_GECTL0_ENDINIT_SHFT));
#else
    password = REG_READ(SCU_PTR->SCU_GECTL0.bits.EPW);
#endif
    // TODO:不确定是否需要异或操作
    password ^= 0x003F;
    return password;
}

/**
 * @brief 锁定SafetyAccess 受SE保护的寄存器访问状态
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Scu_LL_WdtlockSafetyAccessReg(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SGECTL0_ADDR);
    regValue &= ~HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_MASK;
    regValue |= true << HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_SHFT;
    REG_WRITE(HWIO_SCU_SGECTL0_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_SGECTL0.bits.ENDINIT, true);
#endif
#ifdef SIMULATION
    while (REG_BITS_READ(HWIO_SCU_SGECTL0_ADDR, HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_MASK,
                         HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_SHFT) == false)
        ;
#else
    while (REG_READ(SCU_PTR->SCU_SGECTL0.bits.ENDINIT) == false)
        ;
#endif
}

/**
 * @brief 解锁SafetyAccess 受SE保护的寄存器访问状态
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Scu_LL_WdtUnlockSafetyAccessReg(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SGECTL0_ADDR);
    regValue &= ~HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_MASK;
    regValue |= false << HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_SHFT;
    REG_WRITE(HWIO_SCU_SGECTL0_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_SGECTL0.bits.ENDINIT, false);
#endif
#ifdef SIMULATION
    while (REG_BITS_READ(HWIO_SCU_SGECTL0_ADDR, HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_MASK,
                         HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_SHFT) == true)
        ;
#else
    while (REG_READ(SCU_PTR->SCU_SGECTL0.bits.ENDINIT) == true)
        ;
#endif
}

/**
 * @brief 获取SafetyAccess 受SE保护的寄存器访问状态
 *
 *
 * @param void
 * @retval bool
 */
KF_INLINE bool Scu_LL_WdtGetSafetyAccessEndInit(void)
{
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_SGECTL0_ADDR, HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_MASK, HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_SGECTL0.bits.ENDINIT));
#endif
}

/**
 * @brief 设置安全访问控制寄存器
 *
 *
 * @param Password
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetSafetyAccessPassword(uint32_t Password)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SGECTL0_ADDR);
    regValue &= ~HWIO_SCU_SGECTL0_SCU_SGECTL0_EPW_MASK;
    regValue |= Password << HWIO_SCU_SGECTL0_SCU_SGECTL0_EPW_SHFT;
    REG_WRITE(HWIO_SCU_SGECTL0_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_SGECTL0.bits.EPW, Password);
#endif
}

/**
 * @brief 获取安全访问寄存器Password
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_WdtGetSafetyAccessPassword(void)
{
    uint32_t password;
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_SGECTL0_ADDR, HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_MASK, HWIO_SCU_SGECTL0_SCU_SGECTL0_ENDINIT_SHFT));
#else
    password = REG_READ(SCU_PTR->SCU_SGECTL0.bits.EPW);
#endif
    // TODO:不确定是否需要异或操作
    password ^= 0x003F;
    return password;
}

/**
 * @brief 获取安全访问超时计数器的重加载值
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_WdtGetSafetyAccessReloadValue(void)
{
#if SIMULATION
    uint32_t regValue = 0U;
    regValue          = REG_READ(HWIO_SCU_SGECTL0_ADDR);
    regValue &= HWIO_SCU_SGECTL0_SCU_SGECTL0_REL_MASK;
    regValue = regValue >> HWIO_SCU_SGECTL0_SCU_SGECTL0_REL_SHFT;
    return (uint16_t)regValue;
#else
    return (REG_READ(SCU_PTR->SCU_SGECTL0.bits.REL));
#endif
}

/**
 * @brief 设置安全访问超时定时器奇数时钟分频选择
 *
 *
 * @param Scu_WdtDivType_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetSafetyAccessClockDivide(const Scu_WdtDivType_t Div)
{
#ifdef SIMULATION
    uint32_t divide   = (((uint32_t)Div & (~3U)) << 2U | ((uint32_t)Div & 3U));
    uint32_t mask     = 0x26U;
    uint32_t shift    = 1U;
    uint32_t regValue = REG_READ(HWIO_SCU_SGECTL1_ADDR);
    regValue &= ~mask;
    regValue |= (divide << shift);
    REG_WRITE(HWIO_SCU_SGECTL1_ADDR, regValue);
#else
    switch (ScuDiv)
    {
    case SCUWDT_DIVBY_16384: {
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_64: {
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_256: {
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_512: {
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_1024: {
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_2048: {
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_4096: {
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_8192: {
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.IR2, 1U);
    }
    break;
    default:
        break;
    }
#endif
}

/**
 * @brief Disable模式请求位
 *
 *
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_WdtRequestSafetyAccessDisable(const bool Status)
{
#if SIMULATION
    uint32_t regValue = 0U;
    regValue          = REG_READ(HWIO_SCU_SGECTL1_ADDR);
    regValue &= ~(HWIO_SCU_SGECTL1_SCU_SGECTL1_DR_MASK);
    regValue |= Status << HWIO_SCU_SGECTL1_SCU_SGECTL1_DR_SHFT;
    REG_WRITE(SCU_PTR->SCU_SGECTL1.reg, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.DR, Status);
#endif
}

/**
 * @brief 安全访问寄存器看门狗定时器时钟选择位
 *
 *
 * @param Scu_WdtClk_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSelectSafetyAccessWdgClk(Scu_WdtClk_t Clk)
{
#if SIMULATION
    uint32_t regValue = 0U;
    regValue          = REG_READ(HWIO_SCU_SGECTL1_ADDR);
    regValue &= ~(HWIO_SCU_SGECTL1_SCU_SGECTL1_CSEL_MASK);
    regValue |= Clk << HWIO_SCU_SGECTL1_SCU_SGECTL1_CSEL_SHFT;
    REG_WRITE(HWIO_SCU_SGECTL1_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_SGECTL1.bits.CSEL, Clk);
#endif
}

/**
 * @brief 获取SafetyAccess寄存器状态
 *
 * @param Flag 待获取状态标志位
 *
 * @retval bool
 */
KF_INLINE bool Scu_LL_GetSafetyAccessEndInitStatus(Scu_GlobalEnInitStatusFlag_t Flag)
{
#if SIMULATION
    uint32_t regValue = 0U;
    regValue          = REG_READ(HWIO_SCU_SGESTA_ADDR);
    regValue &= (1U << Flag);
    regValue = regValue >> Flag;
    return ((regValue > 0U) ? true : false);
#else
    bool retVal = true;
    retVal      = REG_BIT_BOOLED(SCU_PTR->SCU_SGESTA.reg, (1U << Flag));
    return retVal;
#endif
}

/**
 * @brief 获取SafetyAccess超时计数器值
 *
 * @retval uint16_t
 */
KF_INLINE uint16_t Scu_LL_GetSafetyAccessTimerValue()
{
#if SIMULATION
    uint32_t regValue = 0U;
    regValue          = REG_READ(HWIO_SCU_SGESTA_ADDR);
    regValue &= HWIO_SCU_SGESTA_SCU_SGESTA_TIM_MASK;
    regValue = regValue >> HWIO_SCU_SGESTA_SCU_SGESTA_TIM_SHFT;
    return (uint16_t)regValue;
#else
    uint16_t retVal = 0U;
    retVal          = REG_READ(SCU_PTR->SCU_SGESTA.bits.TIM);
    return retVal;
#endif
}

/**
 * @brief 请求禁用 CPU 看门狗
 *
 *
 * @param Scu_CPUType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_WdtRequestCpuWdgDisable(Scu_CPUType_t CPU, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2));
    regValue &= ~HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_DR_MASK;
    regValue |= Status << HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_DR_SHFT;
    REG_WRITE(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2), regValue);
#else
    REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.DR, Status);
#endif
}

/**
 * @brief 请求 CPU看门狗解锁限制
 *
 *
 * @param Scu_CPUType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_WdtRequestCpuWdgUnlockRestriction(Scu_CPUType_t CPU, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2));
    regValue &= ~HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_UR_MASK;
    regValue |= Status << HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_UR_SHFT;
    REG_WRITE(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2), regValue);
#else
    REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.UR, Status);
#endif
}

/**
 * @brief 获取 CPU看门狗解锁限制
 *
 *
 * @param Scu_CPUType_t
 * @retval bool
 */
KF_INLINE bool Scu_LL_WdtGetCpuWdgUnlockRestriction(Scu_CPUType_t CPU)
{
#ifdef SIMULATION
    return REG_BITS_READ(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2), HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_UR_MASK,
                         HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_UR_SHFT);
#else
    return (REG_READ(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.UR));
#endif
}

/**
 * @brief 请求 CPU看门狗自动密码序列
 *
 *
 * @param Scu_CPUType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_WdtRequestCpuWdgAutomaticPassword(Scu_CPUType_t CPU, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2));
    regValue &= ~HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_PAR_MASK;
    regValue |= Status << HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_PAR_SHFT;
    REG_WRITE(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2), regValue);
#else
    REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.PAR, Status);
#endif
}

/**
 * @brief 获取 CPU看门狗自动密码序列
 *
 *
 * @param Scu_CPUType_t
 * @param bool
 * @retval void
 */
KF_INLINE bool Scu_LL_WdtGetCpuWdgAutomaticPassword(Scu_CPUType_t CPU)
{
#ifdef SIMULATION
    return (bool)REG_BITS_READ(
      HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2), HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_PAR_MASK,
      HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_PAR_SHFT);
#else
    return (REG_READ(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.PAR));
#endif
}

/**
 * @brief 设置 CPU看门狗定时器校验
 *
 *
 * @param Scu_CPUType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_WdtRequestCpuWdgTimeCheck(Scu_CPUType_t CPU, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2));
    regValue &= ~HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_TCR_MASK;
    regValue |= Status << HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_TCR_SHFT;
    REG_WRITE(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2), Status);
#else
    REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.TCR, Status);
#endif
}

/**
 * @brief 获取 CPU看门狗定时器校验
 *
 *
 * @param Scu_CPUType_t
 * @retval bool
 */
KF_INLINE bool Scu_LL_WdtGetCpuWdgTimeCheck(Scu_CPUType_t CPU)
{
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2), HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_TCR_MASK,
      HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_TCR_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.TCR));
#endif
}

/**
 * @brief 设置 CPU看门狗定时器校验冗余度
 *
 *
 * @param Scu_CPUType_t
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetCpuWdgCheckTolerance(Scu_CPUType_t CPU, const uint32_t Tolerance)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2));
    regValue &= ~HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_TCTR_MASK;
    regValue |= Tolerance << HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_TCTR_SHFT;
    REG_WRITE(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2), regValue);
#else
    REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.TCTR, Tolerance);
#endif
}

/**
 * @brief 获取 CPU看门狗定时器校验冗余度
 *
 *
 * @param Scu_CPUType_t
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_WdtGetCpuWdgCheckTolerance(Scu_CPUType_t CPU)
{
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2), HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_TCTR_MASK,
      HWIO_SCU_CPU0WDTCTL1_SCU_CPU0WDTCTL1_TCTR_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.TCTR));
#endif
}

/**
 * @brief 设置 CPU看门狗定时器奇数时钟分频选择
 *
 *
 * @param Scu_CPUType_t
 * @param Scu_WdtDivType_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetCpuWdgClockDivide(Scu_CPUType_t CPU, const Scu_WdtDivType_t ScuDiv)
{
#ifdef SIMULATION
    uint32_t divide   = (((uint32_t)ScuDiv & (~3U)) << 2U | ((uint32_t)ScuDiv & 3U));
    uint32_t mask     = 0x26U;
    uint32_t shift    = 1U;
    uint32_t regValue = REG_READ(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2));
    regValue &= ~mask;
    regValue |= (divide << shift);
    REG_WRITE(HWIO_SCU_CPU0WDTCTL1_ADDR + ((uint32_t)CPU << 2), regValue);
#else
    switch (ScuDiv)
    {
    case SCUWDT_DIVBY_16384: {
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_64: {
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_256: {
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_512: {
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_1024: {
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_2048: {
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_4096: {
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_8192: {
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL1.bits.IR2, 1U);
    }
    break;
    default:
        break;
    }
#endif
}

/**
 * @brief 请求禁用 Safety 看门狗
 *
 *
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_WdtRequestSafetyWdgDisable(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SWDTCTL1_ADDR);
    regValue &= ~HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_DR_MASK;
    regValue |= Status << HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_DR_SHFT;
    REG_WRITE(HWIO_SCU_SWDTCTL1_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.DR, Status);
#endif
}

/**
 * @brief 请求 Safety 看门狗解锁限制
 *
 *
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_WdtRequestSafetyWdgUnlockRestriction(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SWDTCTL1_ADDR);
    regValue &= ~HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_UR_MASK;
    regValue |= Status << HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_UR_SHFT;
    REG_WRITE(HWIO_SCU_SWDTCTL1_ADDR, regValue);
#else
    REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.UR, Status);
#endif
}

/**
 * @brief 获取 Safety 看门狗解锁限制
 *
 *
 * @param void
 * @retval bool
 */
KF_INLINE bool Scu_LL_WdtGetSafetyWdgUnlockRestriction(void)
{
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_SWDTCTL1_ADDR, HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_UR_MASK, HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_UR_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_SWDTCTL1.bits.UR));
#endif
}

/**
 * @brief 请求 Safety 看门狗自动密码序列
 *
 *
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_WdtRequestSafetyWdgAutomaticPassword(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SWDTCTL1_ADDR);
    regValue &= ~HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_PAR_MASK;
    regValue |= Status << HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_PAR_SHFT;
    REG_WRITE(HWIO_SCU_SWDTCTL1_ADDR, regValue);

#else
    REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.PAR, Status);
#endif
}

/**
 * @brief 获取 Safety 看门狗解锁限制
 *
 *
 * @param void
 * @retval bool
 */
KF_INLINE bool Scu_LL_WdtGetSafetyWdgAutomaticPassword(void)
{
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_SWDTCTL1_ADDR, HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_PAR_MASK, HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_PAR_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_SWDTCTL1.bits.PAR));
#endif
}

/**
 * @brief 请求 Safety 看门狗定时器校验
 *
 *
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_WdtRequestSafetyWdgTimeCheck(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SWDTCTL1_ADDR);
    regValue &= ~HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_TCR_MASK;
    regValue |= Status << HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_TCR_SHFT;
    REG_WRITE(HWIO_SCU_SWDTCTL1_ADDR, regValue);

#else
    REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.TCR, Status);
#endif
}

/**
 * @brief 获取 Safety 看门狗定时器校验
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE bool Scu_LL_WdtGetSafetyWdgTimeCheck(void)
{
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_SWDTCTL1_ADDR, HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_TCR_MASK, HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_TCR_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_SWDTCTL1.bits.TCR));
#endif
}

/**
 * @brief  请求 Safety 看门狗定时器校验冗余度
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetSafetyWdgCheckTolerance(const uint32_t Tolerance)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_SWDTCTL1_ADDR);
    regValue &= ~HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_TCTR_MASK;
    regValue |= Tolerance << HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_TCTR_SHFT;
    REG_WRITE(HWIO_SCU_SWDTCTL1_ADDR, regValue);

#else
    REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.TCTR, Tolerance);
#endif
}

/**
 * @brief  获取 Safety 看门狗定时器校验冗余度
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_WdtGetSafetyWdgCheckTolerance(void)
{
#ifdef SIMULATION
    return (REG_BITS_READ(
      HWIO_SCU_SWDTCTL1_ADDR, HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_TCTR_MASK, HWIO_SCU_SWDTCTL1_SCU_SWDTCTL1_TCTR_SHFT));
#else
    return (REG_READ(SCU_PTR->SCU_SWDTCTL1.bits.TCTR));
#endif
}

/**
 * @brief 设置 Safety 看门狗定时器奇数时钟分频选择
 *
 *
 * @param Scu_WdtDivType_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetSafetyWdgClockDivide(const Scu_WdtDivType_t ScuDiv)
{
#ifdef SIMULATION
    uint32_t divide   = (((uint32_t)ScuDiv & (~3U)) << 2U | ((uint32_t)ScuDiv & 3U));
    uint32_t mask     = 0x26U;
    uint32_t shift    = 1U;
    uint32_t regValue = REG_READ(HWIO_SCU_SWDTCTL1_ADDR);
    regValue &= ~mask;
    regValue |= (divide << shift);
    REG_WRITE(HWIO_SCU_SWDTCTL1_ADDR, regValue);
#else
    switch (ScuDiv)
    {
    case SCUWDT_DIVBY_16384: {
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_64: {
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_256: {
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_512: {
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR2, 0U);
    }
    break;
    case SCUWDT_DIVBY_1024: {
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_2048: {
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR1, 0U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_4096: {
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR0, 0U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR2, 1U);
    }
    break;
    case SCUWDT_DIVBY_8192: {
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR0, 1U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR1, 1U);
        REG_WRITE(SCU_PTR->SCU_SWDTCTL1.bits.IR2, 1U);
    }
    break;
    default:
        break;
    }
#endif
}

/******************************************************************************
 *                     TRAP Export Functions
 ******************************************************************************/

/**
 * @brief
 *
 *
 * @param Scu_CPUType_t
 * @param Scu_TrapType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_TrapEnable(const Scu_CPUType_t CPU, Scu_TrapType_t Trap, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_TRAPEN_ADDR);
    regValue &= ~(MASK_1_BIT << (CPU * POS_8_SHIFT + Trap));
    regValue |= (Status << (CPU * POS_8_SHIFT + Trap));
    REG_WRITE(HWIO_SCU_TRAPEN_ADDR, regValue);
#else
    REG_BITS_WRITE(
      SCU_PTR->SCU_TRAPEN.reg, MASK_1_BIT << (CPU * POS_8_SHIFT + Trap), Status << (CPU * POS_8_SHIFT + Trap));
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_CPUType_t
 * @param Scu_TrapType_t
 * @retval bool
 */
KF_INLINE bool Scu_LL_TrapGetEnable(const Scu_CPUType_t CPU, Scu_TrapType_t Trap)
{

#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_SCU_TRAPEN_ADDR, MASK_1_BIT << (CPU * POS_8_SHIFT + Trap), (CPU * POS_8_SHIFT + Trap)));
#else
    return (
      REG_BITS_READ(SCU_PTR->SCU_TRAPEN.reg, MASK_1_BIT << (CPU * POS_8_SHIFT + Trap), (CPU * POS_8_SHIFT + Trap)));
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_TrapType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_TrapSetFlag(Scu_TrapType_t Trap, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_TRAPSET_ADDR);
    regValue &= ~(MASK_1_BIT << Trap);
    regValue |= (Status << Trap);
    REG_WRITE(HWIO_SCU_TRAPSET_ADDR, regValue);
#else
    REG_BITS_WRITE(SCU_PTR->SCU_TRAPSET.reg, MASK_1_BIT << Trap, Status << Trap);
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_TrapType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_TrapClearFlag(Scu_TrapType_t Trap, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SCU_TRAPCLR_ADDR);
    regValue &= ~(MASK_1_BIT << Trap);
    regValue |= (Status << Trap);
    REG_WRITE(HWIO_SCU_TRAPCLR_ADDR, regValue);
#else
    REG_BITS_WRITE(SCU_PTR->SCU_TRAPCLR.reg, MASK_1_BIT << Trap, Status << Trap);
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_TrapType_t
 * @retval bool
 */
KF_INLINE bool Scu_LL_TrapGetFlag(Scu_TrapType_t Trap)
{
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_SCU_TRAPSTA_ADDR, MASK_1_BIT << Trap, Trap));
#else
    return (REG_BITS_READ(SCU_PTR->SCU_TRAPSTA.reg, MASK_1_BIT << Trap, Trap));
#endif
}
/******************************************************************************
 *                     EMS Export Functions
 ******************************************************************************/

/******************************************************************************
 *                     ERU Export Functions
 ******************************************************************************/
/**
 * @brief clear input channel state
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Scu_LL_EruClearAllEventFlag(void)
{
#ifdef SIMULATION
// TODO:
#else
    REG_BITS_WRITE(SCU_PTR->SCU_INTFCTL.reg, (MASK_8_BIT << POS_16_OFFSET), (0xFFU << POS_16_OFFSET));
#endif
}

/**
 * @brief
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_EruGetAllFlag(void)
{
#ifdef SIMULATION
    return (REG_READ(HWIO_SCU_EIFSTA_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(SCU_PTR->SCU_EIFSTA.reg));
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @retval void
 */
KF_INLINE void Scu_LL_EruClearEventFlag(Scu_EruInputChannelType_t InputChannel)
{
#ifdef SIMULATION
// TODO:
#else
    REG_BITS_WRITE(SCU_PTR->SCU_INTFCTL.reg, (MASK_1_BIT << (InputChannel + POS_16_OFFSET)),
                   ((uint32_t) true << (InputChannel + POS_16_OFFSET)));
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @retval bool
 */
KF_INLINE bool Scu_LL_EruGetEventFlag(Scu_EruInputChannelType_t InputChannel)
{
#ifdef SIMULATION
// TODO:REG_BITS_READ cannot process
#else
    return (REG_BITS_READ(SCU_PTR->SCU_EIFSTA.reg, MASK_1_BIT << InputChannel, InputChannel));
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @retval void
 */
KF_INLINE void Scu_LL_EruSetEventFlag(Scu_EruInputChannelType_t InputChannel)
{
#ifdef SIMULATION
// TODO:
#else
    REG_BITS_WRITE(SCU_PTR->SCU_INTFCTL.reg, (MASK_1_BIT << InputChannel), ((uint32_t) true << InputChannel));
#endif
}

/**
 * * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @retval void
 */
KF_INLINE void Scu_LL_EruClearInputChannelConfiguration(Scu_EruInputChannelType_t InputChannel)
{
    uint32_t index = (InputChannel >> POS_1_SHIFT);
    if (InputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO:
#else
        REG_BITS_WRITE(SCU_PTR->SCU_EICCTL[index].reg, MASK_16_BIT << POS_16_OFFSET, (uint32_t) false << POS_16_OFFSET);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO:
#else
        REG_BITS_WRITE(SCU_PTR->SCU_EICCTL[index].reg, MASK_16_BIT << POS_0_OFFSET, (uint32_t) false << POS_0_OFFSET);
#endif
    }
}

/**
 * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_EruGetInputChannelConfiguration(Scu_EruInputChannelType_t InputChannel)
{
    uint32_t retValue = 0U;
    uint32_t index    = (InputChannel >> POS_1_SHIFT);
    if (InputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO:REG_BITS_READ cannot process
#else
        retValue = REG_BITS_READ(SCU_PTR->SCU_EICCTL[index].reg, MASK_16_BIT << POS_16_OFFSET, POS_16_OFFSET);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO:REG_BITS_READ cannot process
#else
        retValue = REG_BITS_READ(SCU_PTR->SCU_EICCTL[index].reg, MASK_16_BIT << POS_0_OFFSET, POS_0_OFFSET);
#endif
    }
    return retValue;
}

/**
 * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @param Scu_EruExternalInputType_t
 * @retval void
 */
KF_INLINE void
Scu_LL_EruSelectExternalInput(Scu_EruInputChannelType_t InputChannel, Scu_EruExternalInputType_t InputSignal)
{
    uint32_t index = (InputChannel >> POS_1_SHIFT);
    if (InputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.EXISI, InputSignal);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.EXIS2I, InputSignal);
#endif
    }
}

/**
 * @brief
 *
 *
 * @param Scu_EruTriggerChannelType_t
 * @retval void
 */
KF_INLINE void Scu_LL_EruClearOutputChannelConfiguration(Scu_EruTriggerChannelType_t OutputChannel)
{
    uint32_t index = (OutputChannel >> POS_1_SHIFT);
    if (OutputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO:
#else
        REG_BITS_WRITE(SCU_PTR->SCU_IGCTL[index].reg, MASK_16_BIT << POS_16_OFFSET, (uint32_t) false << POS_16_OFFSET);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO:
#else
        REG_BITS_WRITE(SCU_PTR->SCU_IGCTL[index].reg, MASK_16_BIT << POS_0_OFFSET, (uint32_t) false << POS_0_OFFSET);
#endif
    }
}

/**
 * @brief clear input channel configuration
 *
 *
 * @param Scu_EruTriggerChannelType_t
 * @retval uint32_t
 */
KF_INLINE uint32_t Scu_LL_EruGetOutputChannelConfiguration(Scu_EruTriggerChannelType_t OutputChannel)
{
    uint32_t retValue = 0U;
    uint32_t index    = (OutputChannel >> POS_1_SHIFT);
    if (OutputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO:REG_BITS_READ cannot process
#else
        retValue = REG_BITS_READ(SCU_PTR->SCU_IGCTL[index].reg, MASK_16_BIT << POS_16_OFFSET, POS_16_OFFSET);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO:REG_BITS_READ cannot process
#else
        retValue = REG_BITS_READ(SCU_PTR->SCU_IGCTL[index].reg, MASK_16_BIT << POS_0_OFFSET, POS_0_OFFSET);
#endif
    }
    return retValue;
}

/**
 * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @param Scu_EruTriggerChannelType_t
 * @retval void
 */
KF_INLINE void
Scu_LL_EruSelectTrigger(Scu_EruInputChannelType_t InputChannel, Scu_EruTriggerChannelType_t TriggerConnect)
{
    uint32_t index = (InputChannel >> POS_1_SHIFT);
    if (InputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.INPI, TriggerConnect);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.INP2I, TriggerConnect);
#endif
    }
}

/**
 * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_EruSetAutoClear(Scu_EruInputChannelType_t InputChannel, const bool Status)
{
    uint32_t index = (InputChannel >> POS_1_SHIFT);
    if (InputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.LDENI, Status);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.LDEN2I, Status);
#endif
    }
}

/**
 * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_EruSetFallingEdgeDetection(Scu_EruInputChannelType_t InputChannel, const bool Status)
{
    uint32_t index = (InputChannel >> POS_1_SHIFT);
    if (InputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.FENI, Status);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.FEN2I, Status);
#endif
    }
}

/**
 * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_EruSetRisingEdgeDetection(Scu_EruInputChannelType_t InputChannel, const bool Status)
{
    uint32_t index = (InputChannel >> POS_1_SHIFT);
    if (InputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.RENI, Status);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.REN2I, Status);
#endif
    }
}

/**
 * @brief
 *
 *
 * @param Scu_EruInputChannelType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_EruSetTriggerPulse(Scu_EruInputChannelType_t InputChannel, const bool Status)
{
    uint32_t index = (InputChannel >> POS_1_SHIFT);
    if (InputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.EIENI, Status);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_EICCTL[index].bits.EIEN2I, Status);
#endif
    }
}

/**
 * @brief
 *
 *
 * @param Scu_EruOutputChannelType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_EruSetPatternDetectionTrigger(Scu_EruOutputChannelType_t OutputChannel, const bool Status)
{
    uint32_t index = (OutputChannel >> POS_1_SHIFT);
    if (OutputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_IGCTL[index].bits.GEENI, Status);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_IGCTL[index].bits.GEEN2I, Status);
#endif
    }
}

/**
 * @brief
 *
 *
 * @param Scu_EruOutputChannelType_t
 * @retval void
 */
KF_INLINE bool Scu_LL_EruGetPatternDetectionResult(Scu_EruOutputChannelType_t OutputChannel)
{
#ifdef SIMULATION
// TODO:REG_BITS_READ cannot process
#else
    return (REG_BITS_READ(SCU_PTR->SCU_PDRSTA.reg, MASK_1_BIT << OutputChannel, OutputChannel));
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_EruOutputChannelType_t
 * @retval void
 */
KF_INLINE uint32_t Scu_LL_EruGetWholeDetectionResult(Scu_EruOutputChannelType_t OutputChannel)
{
#ifdef SIMULATION
    return (REG_READ(HWIO_SCU_PDRSTA_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(SCU_PTR->SCU_PDRSTA.reg));
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_EruOutputChannelType_t
 * @param Scu_EruInputChannelType_t
 * @param bool
 * @retval void
 */
KF_INLINE void Scu_LL_EruSetFlagPatternDetection(
  Scu_EruOutputChannelType_t OutputChannel, Scu_EruInputChannelType_t InputChannel, const bool Status)
{
    uint32_t index = (OutputChannel >> POS_1_SHIFT);
    if (OutputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO:
#else
        REG_BITS_WRITE(SCU_PTR->SCU_IGCTL[index].reg, MASK_1_BIT << (POS_16_OFFSET + InputChannel),
                       Status << (POS_16_OFFSET + InputChannel));
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO:
#else
        REG_BITS_WRITE(SCU_PTR->SCU_IGCTL[index].reg, MASK_1_BIT << InputChannel, Status << InputChannel);
#endif
    }
}

/**
 * @brief
 *
 *
 * @param Scu_EruOutputChannelType_t
 * @param Scu_EruIntGatePatternType_t
 * @retval void
 */
KF_INLINE void
Scu_LL_EruSetInterruptGatingPattern(Scu_EruOutputChannelType_t OutputChannel, Scu_EruIntGatePatternType_t GatePattern)
{
    uint32_t index = (OutputChannel >> POS_1_SHIFT);
    if (OutputChannel & POS_1_SHIFT)
    {
        // for odd channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_IGCTL[index].bits.IGPI, GatePattern);
#endif
    }
    else
    {
        // for even channels
#ifdef SIMULATION
// TODO: cannot process please check
#else
        REG_WRITE(SCU_PTR->SCU_IGCTL[index].bits.IGP2I, GatePattern);
#endif
    }
}

/**
 * @brief
 *
 *
 * @param Scu_CPUType_t
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtClearCpuEndinitInline(Scu_CPUType_t CPU, uint32_t Password)
{
    uint32_t regValue;
    uint32_t Rel = Scu_LL_WdtGetCpuWdgReload(CPU);
    if (Scu_LL_WdtGetCpuRegLockState(CPU))
    {
#ifdef SIMULATION
        if (SCU_CPU0 == CPU)
        {
            regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
            regValue &=
              (~(HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_MASK |
                 HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_MASK));
            regValue |=
              (1U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT |
               0U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_SHFT |
               Password << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_SHFT |
               Rel << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_SHFT);
            REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
        }
        else
        {
            regValue = REG_READ(HWIO_SCU_CPU1WDTCTL0_ADDR);
            regValue &=
              (~(HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_MASK |
                 HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_MASK));
            regValue |=
              (1U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_SHFT |
               0U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_SHFT |
               Password << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_SHFT |
               Rel << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_SHFT);
            REG_WRITE(HWIO_SCU_CPU1WDTCTL0_ADDR, regValue);
        }
        // TODO: check if correct
#else
        SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.reg = (1U << 0U) | (0U << 1U) | (Password << 2U) | (Rel << 16U);
#endif
    }

#ifdef SIMULATION
    if (SCU_CPU0 == CPU)
    {
        regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
        regValue &=
          (~(HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_MASK |
             HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_MASK));
        regValue |=
          (0U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT |
           1U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_SHFT |
           Password << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_SHFT |
           Rel << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
    }
    else
    {
        regValue = REG_READ(HWIO_SCU_CPU1WDTCTL0_ADDR);
        regValue &=
          (~(HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_MASK |
             HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_MASK));
        regValue |=
          (0U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_SHFT |
           1U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_SHFT |
           Password << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_SHFT |
           Rel << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_CPU1WDTCTL0_ADDR, regValue);
    }
    // TODO: check if correct
#else
    SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.reg = (0U << 0U) | (1U << 1U) | (Password << 2U) | (Rel << 16U);
#endif

#ifdef FPGA_WDT
    while (1U == Scu_LL_WdtGetCpuEndInit(CPU))
    {
    }
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_CPUType_t
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetCpuEndinitInline(Scu_CPUType_t CPU, uint32_t Password)
{
    uint32_t regValue;
    uint32_t Rel = Scu_LL_WdtGetCpuWdgReload(CPU);
    if (Scu_LL_WdtGetCpuRegLockState(CPU))
    {
#ifdef SIMULATION
        if (SCU_CPU0 == CPU)
        {
            regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
            regValue &=
              (~(HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_MASK |
                 HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_MASK));
            regValue |=
              (1U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT |
               0U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_SHFT |
               Password << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_SHFT |
               Rel << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_SHFT);
            REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
        }
        else
        {
            regValue = REG_READ(HWIO_SCU_CPU1WDTCTL0_ADDR);
            regValue &=
              (~(HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_MASK |
                 HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_MASK));
            regValue |=
              (1U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_SHFT |
               0U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_SHFT |
               Password << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_SHFT |
               Rel << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_SHFT);
            REG_WRITE(HWIO_SCU_CPU1WDTCTL0_ADDR, regValue);
        }
        // TODO: check if correct
#else
        SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.reg = (1U << 0U) | (0U << 1U) | (Password << 2U) | (Rel << 16U);
#endif
    }

#ifdef SIMULATION
    if (SCU_CPU0 == CPU)
    {
        regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
        regValue &=
          (~(HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_MASK |
             HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_MASK));
        regValue |=
          (1U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT |
           1U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_SHFT |
           Password << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_SHFT |
           Rel << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
    }
    else
    {
        regValue = REG_READ(HWIO_SCU_CPU1WDTCTL0_ADDR);
        regValue &=
          (~(HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_MASK |
             HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_MASK));
        regValue |=
          (1U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_SHFT |
           1U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_SHFT |
           Password << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_SHFT |
           Rel << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_CPU1WDTCTL0_ADDR, regValue);
    }
    // TODO: check if correct
#else
    SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.reg = (1U << 0U) | (1U << 1U) | (Password << 2U) | (Rel << 16U);
#endif

#ifdef FPGA_WDT
    while (0U == Scu_LL_WdtGetCpuEndInit(CPU))
    {
    }
#endif
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtClearSafetyEndinitInline(uint32_t Password)
{
    uint32_t regValue;
    uint32_t Rel = Scu_LL_WdtGetSafetyWdgReload();
    if (Scu_LL_WdtGetSafetyRegLockState())
    {
#ifdef SIMULATION
        regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
        regValue &= (~(HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_MASK |
                       HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_MASK));
        regValue |=
          (1U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT | 0U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_SHFT |
           Password << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_SHFT | Rel << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
        SCU_PTR->SCU_SWDTCTL0.reg = (1U << 0U) | (0U << 1U) | (Password << 2U) | (Rel << 16U);
#endif
    }

#ifdef SIMULATION
    regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
    regValue &= (~(HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_MASK |
                   HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_MASK));
    regValue |= (0U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT | 1U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_SHFT |
                 Password << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_SHFT | Rel << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_SHFT);
    REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
    SCU_PTR->SCU_SWDTCTL0.reg = (0U << 0U) | (1U << 1U) | (Password << 2U) | (Rel << 16U);
#endif

#ifdef FPGA_WDT
    while (1U == Scu_LL_WdtGetSafetyEndInit())
    {
    }
#endif
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtSetSafetyEndinitInline(uint32_t Password)
{
    uint32_t regValue;
    uint32_t Rel = Scu_LL_WdtGetSafetyWdgReload();
    if (Scu_LL_WdtGetSafetyRegLockState())
    {
#ifdef SIMULATION
        regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
        regValue &= (~(HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_MASK |
                       HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_MASK));
        regValue |=
          (1U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT | 0U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_SHFT |
           Password << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_SHFT | Rel << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
        SCU_PTR->SCU_SWDTCTL0.reg = (1U << 0U) | (0U << 1U) | (Password << 2U) | (Rel << 16U);
#endif
    }

#ifdef SIMULATION
    regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
    regValue &= (~(HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_MASK |
                   HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_MASK));
    regValue |= (1U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT | 1U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_SHFT |
                 Password << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_SHFT | Rel << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_SHFT);
    REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
    SCU_PTR->SCU_SWDTCTL0.reg = (1U << 0U) | (1U << 1U) | (Password << 2U) | (Rel << 16U);
#endif

#ifdef FPGA_WDT
    while (0U == Scu_LL_WdtGetSafetyEndInit())
    {
    }
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_CPUType_t
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtChangeCpuWdgPasswordInline(Scu_CPUType_t CPU, uint32_t Password, uint32_t NewPassword)
{
    uint32_t regValue;
    uint32_t Rel = Scu_LL_WdtGetCpuWdgReload(CPU);
    if (Scu_LL_WdtGetCpuRegLockState(CPU))
    {
#ifdef SIMULATION
        if (SCU_CPU0 == CPU)
        {
            regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
            regValue &=
              (~(HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_MASK |
                 HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_MASK));
            regValue |=
              (1U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT |
               0U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_SHFT |
               Password << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_SHFT |
               Rel << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_SHFT);
            REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
        }
        else
        {
            regValue = REG_READ(HWIO_SCU_CPU1WDTCTL0_ADDR);
            regValue &=
              (~(HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_MASK |
                 HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_MASK));
            regValue |=
              (1U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_SHFT |
               0U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_SHFT |
               Password << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_SHFT |
               Rel << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_SHFT);
            REG_WRITE(HWIO_SCU_CPU1WDTCTL0_ADDR, regValue);
        }
        // TODO: check if correct
#else
        SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.reg = (1U << 0U) | (0U << 1U) | (Password << 2U) | (Rel << 16U);
#endif
    }

#ifdef SIMULATION
    if (SCU_CPU0 == CPU)
    {
        regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
        regValue &=
          (~(HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_MASK |
             HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_MASK));
        regValue |=
          (0U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT |
           1U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_SHFT |
           NewPassword << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_SHFT |
           Rel << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
    }
    else
    {
        regValue = REG_READ(HWIO_SCU_CPU1WDTCTL0_ADDR);
        regValue &=
          (~(HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_MASK |
             HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_MASK));
        regValue |=
          (0U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_SHFT |
           1U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_SHFT |
           NewPassword << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_SHFT |
           Rel << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_CPU1WDTCTL0_ADDR, regValue);
    }
    // TODO: check if correct
#else
    SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.reg = (0U << 0U) | (1U << 1U) | (NewPassword << 2U) | (Rel << 16U);
#endif

#ifdef FPGA_WDT
    while (1U == Scu_LL_WdtGetCpuEndInit(CPU))
    {
    }
#endif
}

/**
 * @brief
 *
 *
 * @param Scu_CPUType_t
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtChangeCpuWdgReloadInline(Scu_CPUType_t CPU, uint32_t Password, uint32_t Reload)
{
    uint32_t regValue;
    uint32_t Rel = Scu_LL_WdtGetCpuWdgReload(CPU);
    if (Scu_LL_WdtGetCpuRegLockState(CPU))
    {
#ifdef SIMULATION
        if (SCU_CPU0 == CPU)
        {
            regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
            regValue &=
              (~(HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_MASK |
                 HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_MASK));
            regValue |=
              (1U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT |
               0U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_SHFT |
               Password << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_SHFT |
               Rel << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_SHFT);
            REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
        }
        else
        {
            regValue = REG_READ(HWIO_SCU_CPU1WDTCTL0_ADDR);
            regValue &=
              (~(HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_MASK |
                 HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_MASK));
            regValue |=
              (1U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_SHFT |
               0U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_SHFT |
               Password << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_SHFT |
               Rel << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_SHFT);
            REG_WRITE(HWIO_SCU_CPU1WDTCTL0_ADDR, regValue);
        }
        // TODO: check if correct
#else
        SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.reg = (1U << 0U) | (0U << 1U) | (Password << 2U) | (Rel << 16U);
#endif
    }

#ifdef SIMULATION
    if (SCU_CPU0 == CPU)
    {
        regValue = REG_READ(HWIO_SCU_CPU0WDTCTL0_ADDR);
        regValue &=
          (~(HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_MASK |
             HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_MASK | HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_MASK));
        regValue |=
          (0U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_ENDINIT_SHFT |
           1U << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_LCK_SHFT |
           Password << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_PW_SHFT |
           Reload << HWIO_SCU_CPU0WDTCTL0_SCU_CPU0WDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_CPU0WDTCTL0_ADDR, regValue);
    }
    else
    {
        regValue = REG_READ(HWIO_SCU_CPU1WDTCTL0_ADDR);
        regValue &=
          (~(HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_MASK |
             HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_MASK | HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_MASK));
        regValue |=
          (0U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_ENDINIT_SHFT |
           1U << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_LCK_SHFT |
           Password << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_PW_SHFT |
           Reload << HWIO_SCU_CPU1WDTCTL0_SCU_CPU1WDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_CPU1WDTCTL0_ADDR, regValue);
    }
    // TODO: check if correct
#else
    SCU_PTR->SCU_CPUWDT[CPU].SCU_CPUWDTCTL0.reg = (0U << 0U) | (1U << 1U) | (Password << 2U) | (Reload << 16U);
#endif

#ifdef FPGA_WDT
    while (1U == Scu_LL_WdtGetCpuEndInit(CPU))
    {
    }
#endif
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtChangeSafetyWdgPasswordInline(uint32_t Password, uint32_t NewPassword)
{
    uint32_t regValue;
    uint32_t Rel = Scu_LL_WdtGetSafetyWdgReload();
    if (Scu_LL_WdtGetSafetyRegLockState())
    {
#ifdef SIMULATION
        regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
        regValue &= (~(HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_MASK |
                       HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_MASK));
        regValue |=
          (1U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT | 0U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_SHFT |
           Password << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_SHFT | Rel << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
        SCU_PTR->SCU_SWDTCTL0.reg = (1U << 0U) | (0U << 1U) | (Password << 2U) | (Rel << 16U);
#endif
    }

#ifdef SIMULATION
    regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
    regValue &= (~(HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_MASK |
                   HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_MASK));
    regValue |=
      (0U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT | 1U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_SHFT |
       NewPassword << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_SHFT | Rel << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_SHFT);
    REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
    SCU_PTR->SCU_SWDTCTL0.reg = (0U << 0U) | (1U << 1U) | (NewPassword << 2U) | (Rel << 16U);
#endif

#ifdef FPGA_WDT
    while (1U == Scu_LL_WdtGetCpuEndInit())
    {
    }
#endif
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Scu_LL_WdtChangeSafetyWdgReload(uint32_t Password, uint32_t Reload)
{
    uint32_t regValue;
    uint32_t Rel = Scu_LL_WdtGetSafetyWdgReload();
    if (Scu_LL_WdtGetSafetyRegLockState())
    {
#ifdef SIMULATION
        regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
        regValue &= (~(HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_MASK |
                       HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_MASK));
        regValue |=
          (1U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT | 0U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_SHFT |
           Password << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_SHFT | Rel << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_SHFT);
        REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
        SCU_PTR->SCU_SWDTCTL0.reg = (1U << 0U) | (0U << 1U) | (Password << 2U) | (Rel << 16U);
#endif
    }

#ifdef SIMULATION
    regValue = REG_READ(HWIO_SCU_SWDTCTL0_ADDR);
    regValue &= (~(HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_MASK |
                   HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_MASK | HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_MASK));
    regValue |=
      (0U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_ENDINIT_SHFT | 1U << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_LCK_SHFT |
       Password << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_PW_SHFT | Reload << HWIO_SCU_SWDTCTL0_SCU_SWDTCTL0_REL_SHFT);
    REG_WRITE(HWIO_SCU_SWDTCTL0_ADDR, regValue);
#else
    SCU_PTR->SCU_SWDTCTL0.reg = (0U << 0U) | (1U << 1U) | (Password << 2U) | (Reload << 16U);
#endif

#ifdef FPGA_WDT
    while (1U == Scu_LL_WdtGetSafetyEndInit())
    {
    }
#endif
}
#ifdef __cplusplus
}
#endif
#endif
/* EOF */
