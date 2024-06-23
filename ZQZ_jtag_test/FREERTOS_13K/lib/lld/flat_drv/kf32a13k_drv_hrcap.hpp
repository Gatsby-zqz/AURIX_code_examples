/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_hrcap.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-28
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
 *  |2023-12-28  |V1.0     |Zhang Quanzhen  | New Creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_HRCAP_H_
#define KF32A13K_DRV_HRCAP_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_hrcap.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_HRCAP_ASSERT
#include "dev_assert.h"
#define KF_DRV_HRCAP_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_HRCAP_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION
#define HRCAP_MODULE_BASE_ADDR HRCAP0_ADDR
#include "kf32a13k_reg_simulation_hrcap.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    HRCAP_NOSUSPEND   = 0U,
    HRCAP_STOPCOUNTER = 2U
} Hrcap_SuspendMode_t;

#define CHECK_HRCAP_SUSPENDMODE(Mode)   (Mode == HRCAP_NOSUSPEND) ||(Mode == ModeHRCAP_STOPCOUNTER))

typedef enum
{
    HRCAP_ACCESS_ENABLE_0,
    HRCAP_ACCESS_ENABLE_1,
    HRCAP_ACCESS_ENABLE_2,
    HRCAP_ACCESS_ENABLE_3,
    HRCAP_ACCESS_ENABLE_4,
    HRCAP_ACCESS_ENABLE_5,
    HRCAP_ACCESS_ENABLE_6,
    HRCAP_ACCESS_ENABLE_7,
    HRCAP_ACCESS_ENABLE_8,
    HRCAP_ACCESS_ENABLE_9,
    HRCAP_ACCESS_ENABLE_10,
    HRCAP_ACCESS_ENABLE_11,
    HRCAP_ACCESS_ENABLE_12,
    HRCAP_ACCESS_ENABLE_13,
    HRCAP_ACCESS_ENABLE_14,
    HRCAP_ACCESS_ENABLE_15,
    HRCAP_ACCESS_ENABLE_16,
    HRCAP_ACCESS_ENABLE_17,
    HRCAP_ACCESS_ENABLE_18,
    HRCAP_ACCESS_ENABLE_19,
    HRCAP_ACCESS_ENABLE_20,
    HRCAP_ACCESS_ENABLE_21,
    HRCAP_ACCESS_ENABLE_22,
    HRCAP_ACCESS_ENABLE_23,
    HRCAP_ACCESS_ENABLE_24,
    HRCAP_ACCESS_ENABLE_25,
    HRCAP_ACCESS_ENABLE_26,
    HRCAP_ACCESS_ENABLE_27,
    HRCAP_ACCESS_ENABLE_28,
    HRCAP_ACCESS_ENABLE_29,
    HRCAP_ACCESS_ENABLE_30,
    HRCAP_ACCESS_ENABLE_31
} Hrcap_AccessEnableType_t;

#define CHECK_HRCAP_ACCESSENABLE(AccessEnable) ((AccessEnable >> POS_5_SHIFT) == 0U)

typedef enum
{
    CLOCK_FTMR,
    CLOCK_FSPB
} Hrcap_ClockSourceType_t;

#define CHECK_HRCAP_CLOCKSOURCE(Source)   (Source == CLOCK_FTMR) ||(Source == CLOCK_FSPB))

typedef enum
{
    HRCAP_INPUT0,
    HRCAP_INPUT1,
    HRCAP_INPUT2,
    HRCAP_INPUT3,
    HRCAP_INPUT4,
    HRCAP_INPUT5,
    HRCAP_INPUT6,
    HRCAP_INPUT7
} Hrcap_CaptureInputSourceType_t;

#define CHECK_HRCAP_CAPINPUTSOURCE(Source) ((Source >> POS_3_SHIFT) == 0U)

typedef enum
{
    HRCAP_INDEX0,
    HRCAP_INDEX1
} Hrcap_CaptureIndexType_t;

#define CHECK_HRCAP_CAPINDEX(Index) ((Index == HRCAP_INDEX0) || (Index == HRCAP_INDEX1))

typedef enum
{
    RISECAP_FLAG,
    FALLCAP_FLAG,
    TIMEROVERFLOW_FLAG,
    RISEOVERFLOW_FLAG
} Hrcap_FlagType_t;

#define CHECK_HRCAP_FLAG(Flag)                                                                                         \
    ((Flag == RISECAP_FLAG) || (Flag == FALLCAP_FLAG) || (Flag == TIMEROVERFLOW_FLAG) || (Flag == RISEOVERFLOW_FLAG))

typedef enum
{
    RISECAP_INT,
    FALLCAP_INT,
    TIMEROVERFLOW_INT,
    RISEOVERFLOW_INT
} Hrcap_IntType_t;

#define CHECK_HRCAP_INT(Int)                                                                                           \
    ((Int == RISECAP_INT) || (Int == FALLCAP_INT) || (Int == TIMEROVERFLOW_INT) || (Int == RISEOVERFLOW_INT))

#define CHECK_HRCAP_BOOL(Bool)     ((Bool >> POS_1_SHIFT) == 0U)
#define CHECK_HRCAP_MODULE(Module) ((Module == HRCAP0_PTR) || (Module == HRCAP1_PTR) || (Module == HRCAP2_PTR))
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 禁止HRCAP模块
 *
 *
 * @param Module
 * @param Status
 *        true:禁止模块
 *        false:无操作
 * @retval void
 */
KF_INLINE void Hrcap_LL_DisableModule(Hrcap_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_BOOL(Status));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CLKC_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_CLKC_HRCAP0_CLKC_DISR_MASK;
    regValue |=  Status<<HWIO_HRCAP0_CLKC_HRCAP0_CLKC_DISR_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_CLKC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_CLKC.bits.DISR, Status);
#endif
}

/**
 * @brief 获取HRCAP模块状态
 *
 *
 * @param Module
 * @param void
 * @retval bool
 *         true:模块已禁止
 *         false:模块已使能
 */
KF_INLINE bool Hrcap_LL_GetModuleState(Hrcap_RegisterMap_t *const Module)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CLKC_ADDR + offsetAddr);
    regValue &= HWIO_HRCAP0_CLKC_HRCAP0_CLKC_DISS_MASK;
    regValue = regValue >> HWIO_HRCAP0_CLKC_HRCAP0_CLKC_DISS_SHFT;
    return ((regValue));
//TODO: check if correct

#else
    return (REG_READ(Module->HRCAP_CLKC.bits.DISS));
#endif
}

/**
 * @brief 设置HRCAP模块睡眠状态
 *
 *
 * @param Module
 * @param Status
 *         true:模块未进入睡眠模式
 *         false:模块进入睡眠模式
 * @retval void
 */
KF_INLINE void Hrcap_LL_DisableSleepMode(Hrcap_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_BOOL(Status));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CLKC_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_CLKC_HRCAP0_CLKC_EDIS_MASK;
    regValue |=  Status<<HWIO_HRCAP0_CLKC_HRCAP0_CLKC_EDIS_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_CLKC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_CLKC.bits.EDIS, Status);
#endif
}

/**
 * @brief 设置HRCAP模块睡眠状态
 *
 *
 * @param Module
 * @retval Status
 *         true:模块未进入睡眠模式
 *         false:模块进入睡眠模式
 */
KF_INLINE bool Hrcap_LL_GetSleepMode(Hrcap_RegisterMap_t *const Module)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CLKC_ADDR + offsetAddr);
    regValue &= HWIO_HRCAP0_CLKC_HRCAP0_CLKC_EDIS_MASK;
    regValue = regValue >> HWIO_HRCAP0_CLKC_HRCAP0_CLKC_EDIS_SHFT;
    return ((regValue));
//TODO: check if correct

#else
    return (REG_READ(Module->HRCAP_CLKC.bits.EDIS));
#endif
}

/**
 * @brief 获取HRCAP模块版本信息
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Hrcap_LL_GetModuleVersion(Hrcap_RegisterMap_t *const Module)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_INFO_ADDR + offsetAddr);
    regValue &= HWIO_HRCAP0_INFO_HRCAP0_INFO_MODREV_MASK;
    regValue = regValue >> HWIO_HRCAP0_INFO_HRCAP0_INFO_MODREV_SHFT;
    return ((regValue));
//TODO: check if correct

#else
    return (REG_READ(Module->HRCAP_INFO.bits.MODREV));
#endif
}

/**
 * @brief 获取HRCAP模块类型信息
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Hrcap_LL_GetModuleType(Hrcap_RegisterMap_t *const Module)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_INFO_ADDR + offsetAddr);
    regValue &= HWIO_HRCAP0_INFO_HRCAP0_INFO_MODTYPE_MASK;
    regValue = regValue >> HWIO_HRCAP0_INFO_HRCAP0_INFO_MODTYPE_SHFT;
    return ((regValue));
//TODO: check if correct

#else
    return (REG_READ(Module->HRCAP_INFO.bits.MODTYPE));
#endif
}

/**
 * @brief 获取HRCAP模块ID信息
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Hrcap_LL_GetModuleId(Hrcap_RegisterMap_t *const Module)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_INFO_ADDR + offsetAddr);
    regValue &= HWIO_HRCAP0_INFO_HRCAP0_INFO_MODNUM_MASK;
    regValue = regValue >> HWIO_HRCAP0_INFO_HRCAP0_INFO_MODNUM_SHFT;
    return ((regValue));
//TODO: check if correct

#else
    return (REG_READ(Module->HRCAP_INFO.bits.MODNUM));
#endif
}

/**
 * @brief 设置HRCAP调试挂起模式
 *
 *
 * @param Module
 * @param Mode
 *        HRCAP_NOSUSPEND
 *        HRCAP_STOPCOUNTER
 * @retval  void
 */
KF_INLINE void Hrcap_LL_SetDebugSuspendMode(Hrcap_RegisterMap_t *const Module, Hrcap_SuspendMode_t Mode)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_SUSPENDMODE(Mode));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_DBG_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_DBG_HRCAP0_DBG_SUSP_MASK;
    regValue |=  true<<HWIO_HRCAP0_DBG_HRCAP0_DBG_SUSP_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_DBG_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_DBG.bits.SUSP, true);
#endif
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_DBG_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_DBG_HRCAP0_DBG_SUS_MASK;
    regValue |=  Mode<<HWIO_HRCAP0_DBG_HRCAP0_DBG_SUS_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_DBG_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_DBG.bits.SUS, Mode);
#endif
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_DBG_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_DBG_HRCAP0_DBG_SUSP_MASK;
    regValue |=  false<<HWIO_HRCAP0_DBG_HRCAP0_DBG_SUSP_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_DBG_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_DBG.bits.SUSP, false);
#endif
}

/**
 * @brief 获取HRCAP调试挂起模式
 *
 *
 * @param Module
 * @retval Hrcap_SuspendMode_t
 *         HRCAP_NOSUSPEND
 *         HRCAP_STOPCOUNTER
 */
KF_INLINE Hrcap_SuspendMode_t Hrcap_LL_GetDebugSuspendMode(Hrcap_RegisterMap_t *const Module)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_DBG_ADDR + offsetAddr);
    regValue &= HWIO_HRCAP0_DBG_HRCAP0_DBG_SUS_MASK;
    regValue = regValue >> HWIO_HRCAP0_DBG_HRCAP0_DBG_SUS_SHFT;
    return ((Hrcap_SuspendMode_t)(regValue));
//TODO: check if correct

#else
    return ((Hrcap_SuspendMode_t)REG_READ(Module->HRCAP_DBG.bits.SUS));
#endif
}

/**
 * @brief 获取HRCAP调试挂起状态
 *
 *
 * @param Module
 * @retval bool
 *         true: 模块已挂起
 *         false: 模块未挂起
 */
KF_INLINE bool Hrcap_LL_GetDebugSuspend(Hrcap_RegisterMap_t *const Module)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_DBG_ADDR + offsetAddr);
    regValue &= HWIO_HRCAP0_DBG_HRCAP0_DBG_SUSSTA_MASK;
    regValue = regValue >> HWIO_HRCAP0_DBG_HRCAP0_DBG_SUSSTA_SHFT;
    return ((regValue));
//TODO: check if correct

#else
    return (REG_READ(Module->HRCAP_DBG.bits.SUSSTA));
#endif
}

/**
 * @brief 清零HRCAP 复位状态
 *
 *
 * @param  Module
 * @param  bool
 *         true: 清零复位状态
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Hrcap_LL_ClearRst(Hrcap_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_BOOL(Status));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_RSTCLR_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_RSTCLR_HRCAP0_RSTCLR_CLR_MASK;
    regValue |=  Status<<HWIO_HRCAP0_RSTCLR_HRCAP0_RSTCLR_CLR_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_RSTCLR_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_RSTCLR.bits.CLR, Status);
#endif
}

/**
 * @brief 请求HRCAP 复位
 *
 *
 * @param  Module
 * @param  bool
 *         true: 请求模块复位
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Hrcap_LL_ResetModule(Hrcap_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_BOOL(Status));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_RST0_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_RST0_HRCAP0_RST0_RST_MASK;
    regValue |=  Status<<HWIO_HRCAP0_RST0_HRCAP0_RST0_RST_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_RST0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_RST0.bits.RST, Status);
#endif
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_RST1_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_RST1_HRCAP0_RST1_RST_MASK;
    regValue |=  Status<<HWIO_HRCAP0_RST1_HRCAP0_RST1_RST_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_RST1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_RST1.bits.RST, Status);
#endif
}

/**
 * @brief 获取HRCAP复位状态
 *
 *
 * @param Module
 * @ retval bool
 *          true: 模块已经复位
 *          false: 模块没有复位
 */
KF_INLINE bool Hrcap_LL_GetResetState(Hrcap_RegisterMap_t *const Module)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_RST0_ADDR + offsetAddr);
    regValue &= HWIO_HRCAP0_RST0_HRCAP0_RST0_RSTSTA_MASK;
    regValue = regValue >> HWIO_HRCAP0_RST0_HRCAP0_RST0_RSTSTA_SHFT;
    return ((regValue));
//TODO: check if correct

#else
    return (REG_READ(Module->HRCAP_RST0.bits.RSTSTA));
#endif
}

/**
 * @brief 使能HRCAP访问控制
 *
 *
 * @param Module
 * @param AccessEnable :具体访问使能通道
 * @retval void
 */
KF_INLINE void Hrcap_LL_EnableAccess(Hrcap_RegisterMap_t *const Module, Hrcap_AccessEnableType_t AccessEnable)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
//TODO:
#else
    REG_BIT_SET(Module->HRCAP_ACES0.reg, MASK_1_BIT << AccessEnable);
#endif
}

/**
 * @brief 获取HRCAP访问状态
 *
 *
 * @param Module
 * @param AccessEnable :具体访问使能通道
 * @retval bool
 *         true:访问使能
 *         false:访问没有使能
 */
KF_INLINE bool Hrcap_LL_GetAccess(Hrcap_RegisterMap_t *const Module, Hrcap_AccessEnableType_t AccessEnable)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    return (REG_BITS_READ(offsetAddr + HWIO_HRCAP0_ACES0_ADDR, MASK_1_BIT << AccessEnable, AccessEnable));
//TODO: check if correct

#else
    return (REG_BITS_READ(Module->HRCAP_ACES0.reg, MASK_1_BIT << AccessEnable, AccessEnable));
#endif
}

/**
 * @brief 使能HRCAP工作
 *
 *
 * @param Module
 * @param bool
 *        true:使能HRCAP模块
 *        false:禁止HRCAP模块
 * @retval void
 */
KF_INLINE void Hrcap_LL_EnableHRCAP(Hrcap_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_BOOL(Status));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_CTL_HRCAP0_CTL_EN_MASK;
    regValue |=  Status<<HWIO_HRCAP0_CTL_HRCAP0_CTL_EN_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_CTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_CTL.bits.EN, Status);
#endif
}

/**
 * @brief 软件复位HRCAP模块
 *
 *
 * @param Module
 * @retval void
 */
KF_INLINE void Hrcap_LL_ResetHRCAP(Hrcap_RegisterMap_t *const Module)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_CTL_HRCAP0_CTL_SWRST_MASK;
    regValue |=  true<<HWIO_HRCAP0_CTL_HRCAP0_CTL_SWRST_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_CTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_CTL.bits.SWRST, true);
#endif
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_CTL_HRCAP0_CTL_SWRST_MASK;
    regValue |=  false<<HWIO_HRCAP0_CTL_HRCAP0_CTL_SWRST_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_CTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_CTL.bits.SWRST, false);
#endif
}

/**
 * @brief 设置HRCAP工作时钟源
 *
 *
 * @param Module
 * @param Hrcap_ClockSourceType_t
 *        CLOCK_FTMR
 *        CLOCK_FSPB
 * @retval void
 */
KF_INLINE void Hrcap_LL_SetHRCAPClockSource(Hrcap_RegisterMap_t *const Module, Hrcap_ClockSourceType_t ClockSource)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_CLOCKSOURCE(ClockSource));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_CTL_HRCAP0_CTL_CLKSEL_MASK;
    regValue |=  ClockSource<<HWIO_HRCAP0_CTL_HRCAP0_CTL_CLKSEL_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_CTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_CTL.bits.CLKSEL, ClockSource);
#endif
}

/**
 * @brief 设置HRCAP捕捉输入选择
 *
 *
 * @param Module
 * @param Hrcap_CaptureInputSourceType_t
 *        HRCAP_INPUT0
 *        HRCAP_INPUT1
 *        HRCAP_INPUT2
 *        HRCAP_INPUT3
 *        HRCAP_INPUT4
 *        HRCAP_INPUT5
 *        HRCAP_INPUT6
 *        HRCAP_INPUT7
 * @retval void
 */
KF_INLINE void
Hrcap_LL_SetHRCAPInputSource(Hrcap_RegisterMap_t *const Module, Hrcap_CaptureInputSourceType_t InputSource)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_CAPINPUTSOURCE(InputSource));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_HRCAP0_CTL_HRCAP0_CTL_CAPINSEL_MASK;
    regValue |=  InputSource<<HWIO_HRCAP0_CTL_HRCAP0_CTL_CAPINSEL_SHFT;
    REG_WRITE( offsetAddr + HWIO_HRCAP0_CTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->HRCAP_CTL.bits.CAPINSEL, InputSource);
#endif
}

/**
 * @brief 获取HRCAP当前计数值
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Hrcap_LL_GetCurrentCount(Hrcap_RegisterMap_t *const Module)
{
    // TODO:不确定该位是否可写
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CNT_ADDR + offsetAddr);
    regValue &= HWIO_HRCAP0_CNT_HRCAP0_CNT_COUNTER_MASK;
    regValue = regValue >> HWIO_HRCAP0_CNT_HRCAP0_CNT_COUNTER_SHFT;
    return ((regValue));
//TODO: check if correct

#else
    return (REG_READ(Module->HRCAP_CNT.bits.COUNTER));
#endif
}

/**
 * @brief 获取HRCAP锁存计数值
 *
 *
 * @param Module
 * @retval uint32_t
 */
KF_INLINE uint32_t Hrcap_LL_GetLockedCount(Hrcap_RegisterMap_t *const Module)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CNT_ADDR + offsetAddr);
    regValue &= HWIO_HRCAP0_CNT_HRCAP0_CNT_COUNTERSR_MASK;
    regValue = regValue >> HWIO_HRCAP0_CNT_HRCAP0_CNT_COUNTERSR_SHFT;
    return ((regValue));
//TODO: check if correct

#else
    return (REG_READ(Module->HRCAP_CNT.bits.COUNTERSR));
#endif
}

/**
 * @brief 获取HRCAP上升沿整数捕捉值
 *
 *
 * @param Module
 * @param Hrcap_CaptureIndexType_t
 *        HRCAP_INDEX0
 *        HRCAP_INDEX1
 * @retval uint32_t
 */
KF_INLINE uint32_t
Hrcap_LL_GetRiseIntegerCount(Hrcap_RegisterMap_t *const Module, const Hrcap_CaptureIndexType_t CaptureIndex)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_CAPINDEX(CaptureIndex));
#ifdef SIMULATION
//TODO: cannot process please check 
#else
    return (REG_READ(Module->HRCAP_RISE[CaptureIndex].bits.RISE));
#endif
}

/**
 * @brief 获取HRCAP下降沿沿整数捕捉值
 *
 *
 * @param Module
 * @param Hrcap_CaptureIndexType_t
 *        HRCAP_INDEX0
 *        HRCAP_INDEX1
 * @retval uint32_t
 */
KF_INLINE uint32_t
Hrcap_LL_GetFallIntegerCount(Hrcap_RegisterMap_t *const Module, const Hrcap_CaptureIndexType_t CaptureIndex)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_CAPINDEX(CaptureIndex));
#ifdef SIMULATION
//TODO: cannot process please check 
#else
    return (REG_READ(Module->HRCAP_FALL[CaptureIndex].bits.FALL));
#endif
}

/**
 * @brief 获取HRCAP上升沿小数捕捉值
 *
 *
 * @param Module
 * @param Hrcap_CaptureIndexType_t
 *        HRCAP_INDEX0
 *        HRCAP_INDEX1
 * @retval uint32_t
 */
KF_INLINE uint32_t
Hrcap_LL_GetRiseDecimalCount(Hrcap_RegisterMap_t *const Module, const Hrcap_CaptureIndexType_t CaptureIndex)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_CAPINDEX(CaptureIndex));
#ifdef SIMULATION
//TODO: cannot process please check 
#else
    return (REG_READ(Module->HRCAP_HRRISE[CaptureIndex].bits.HRRISE));
#endif
}

/**
 * @brief 获取HRCAP下降沿小数捕捉值
 *
 *
 * @param Module
 * @param Hrcap_CaptureIndexType_t
 *        HRCAP_INDEX0
 *        HRCAP_INDEX1
 * @retval uint32_t
 */
KF_INLINE uint32_t
Hrcap_LL_GetFallDecimalCount(Hrcap_RegisterMap_t *const Module, const Hrcap_CaptureIndexType_t CaptureIndex)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_CAPINDEX(CaptureIndex));
#ifdef SIMULATION
//TODO: cannot process please check 
#else
    return (REG_READ(Module->HRCAP_HRFALL[CaptureIndex].bits.HRFALL));
#endif
}

/**
 * @brief 获取HRCAP相应标志位状态
 *
 *
 * @param Module
 * @param Hrcap_FlagType_t
 *        RISECAP_FLAG
 *        FALLCAP_FLAG
 *        TIMEROVERFLOW_FLAG
 *        RISEOVERFLOW_FLAG
 * @retval bool
 *         true:请求标志位置位
 *         false:请求标志位未置位
 */
KF_INLINE bool Hrcap_LL_GetFlag(Hrcap_RegisterMap_t *const Module, const Hrcap_FlagType_t Flag)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_FLAG(Flag));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    return (REG_BITS_READ(offsetAddr + HWIO_HRCAP0_IF_ADDR, MASK_1_BIT << Flag, Flag));
//TODO: check if correct

#else
    return (REG_BITS_READ(Module->HRCAP_IF.reg, MASK_1_BIT << Flag, Flag));
#endif
}

/**
 * @brief 设置HRCAP相应中断
 *
 *
 * @param Module
 * @param Hrcap_IntType_t
 *        RISECAP_INT
 *        FALLCAP_INT
 *        TIMEROVERFLOW_INT
 *        RISEOVERFLOW_INT
 * @param Status
 *        true:使能相应中断
 *        false:禁止相应中断
 * @retval void
 */
KF_INLINE void Hrcap_LL_SetInt(Hrcap_RegisterMap_t *const Module, const Hrcap_IntType_t Int, const bool Status)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_INT(Int));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_BOOL(Status));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_IE_ADDR + offsetAddr);
    regValue &= ~ MASK_1_BIT << Int;
    regValue |=  (uint32_t)Status << Int;

    REG_WRITE(offsetAddr + HWIO_HRCAP0_IE_ADDR , regValue);
//TODO: check if correct

#else
    REG_BITS_WRITE(Module->HRCAP_IE.reg, MASK_1_BIT << Int, (uint32_t)Status << Int);
#endif
}

/**
 * @brief 清除HRCAP相应标志位状态
 *
 *
 * @param Module
 * @param Hrcap_FlagType_t
 *        RISECAP_FLAG
 *        FALLCAP_FLAG
 *        TIMEROVERFLOW_FLAG
 *        RISEOVERFLOW_FLAG
 * @param bool
 *         true:清除相应标志位
 *         false:无作用
 * @retval void
 */
KF_INLINE void Hrcap_LL_ClearFlag(Hrcap_RegisterMap_t *const Module, const Hrcap_FlagType_t Flag, const bool Status)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_FLAG(Flag));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_BOOL(Status));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_IC_ADDR + offsetAddr);
    regValue &= ~ MASK_1_BIT << Flag;
    regValue |=  (uint32_t)Status << Flag;

    REG_WRITE(offsetAddr + HWIO_HRCAP0_IC_ADDR , regValue);
//TODO: check if correct

#else
    REG_BITS_WRITE(Module->HRCAP_IC.reg, MASK_1_BIT << Flag, (uint32_t)Status << Flag);
#endif
}

/**
 * @brief 置位HRCAP相应标志位状态
 *
 *
 * @param Module
 * @param Hrcap_FlagType_t
 *        RISECAP_FLAG
 *        FALLCAP_FLAG
 *        TIMEROVERFLOW_FLAG
 *        RISEOVERFLOW_FLAG
 * @param bool
 *         true:置位相应标志位
 *         false:无作用
 * @retval void
 */
KF_INLINE void Hrcap_LL_SetFlag(Hrcap_RegisterMap_t *const Module, const Hrcap_FlagType_t Flag, const bool Status)
{
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_FLAG(Flag));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_BOOL(Status));
    KF_DRV_HRCAP_ASSERT(CHECK_HRCAP_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~HRCAP_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_HRCAP0_CLKC_HRCAP0_CLKC_DISR_MASK + offsetAddr);
    regValue &= ~ MASK_1_BIT << Flag;
    regValue |=  (uint32_t)Status << Flag;

    REG_WRITE(offsetAddr + HWIO_HRCAP0_CLKC_HRCAP0_CLKC_DISR_MASK , regValue);
//TODO: check if correct

#else
    REG_BITS_WRITE(Module->HRCAP_IS.reg, MASK_1_BIT << Flag, (uint32_t)Status << Flag);
#endif
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
