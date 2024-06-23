/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_systick.h
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
#ifndef KF32A13K_DRV_SYSTICK_H_
#define KF32A13K_DRV_SYSTICK_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a13k_reg_systick.h"

#ifdef KF_DRV_SYSTICK_ASSERT
#include "dev_assert.h"
#define KF_DRV_SYSTICK_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_SYSTICK_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION
#define SYSTICK_MODULE_BASE_ADDR SYSTICK0_ADDR
#include "kf32a13k_reg_simulation_systick.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    SYSTICK_SUSPEND_MODE_NONE = 0,
    SYSTICK_SUSPEND_MODE_STOP = 2,
} Systick_SuspendMode_t;
#define CHECK_SYSTICKSUSPEND_MODE(MODE) ((MODE == SYSTICK_SUSPEND_MODE_NONE) || (MODE == SYSTICK_SUSPEND_MODE_STOP))

typedef enum
{
    SYSTICK_MASTER_TAG_ID0,
    SYSTICK_MASTER_TAG_ID1,
    SYSTICK_MASTER_TAG_ID2,
    SYSTICK_MASTER_TAG_ID3,
    SYSTICK_MASTER_TAG_ID4,
    SYSTICK_MASTER_TAG_ID5,
    SYSTICK_MASTER_TAG_ID6,
    SYSTICK_MASTER_TAG_ID7,
    SYSTICK_MASTER_TAG_ID8,
    SYSTICK_MASTER_TAG_ID9,
    SYSTICK_MASTER_TAG_ID10,
    SYSTICK_MASTER_TAG_ID11,
    SYSTICK_MASTER_TAG_ID12,
    SYSTICK_MASTER_TAG_ID13,
    SYSTICK_MASTER_TAG_ID14,
    SYSTICK_MASTER_TAG_ID15,
    SYSTICK_MASTER_TAG_ID16,
    SYSTICK_MASTER_TAG_ID17,
    SYSTICK_MASTER_TAG_ID18,
    SYSTICK_MASTER_TAG_ID19,
    SYSTICK_MASTER_TAG_ID20,
    SYSTICK_MASTER_TAG_ID21,
    SYSTICK_MASTER_TAG_ID22,
    SYSTICK_MASTER_TAG_ID23,
    SYSTICK_MASTER_TAG_ID24,
    SYSTICK_MASTER_TAG_ID25,
    SYSTICK_MASTER_TAG_ID26,
    SYSTICK_MASTER_TAG_ID27,
    SYSTICK_MASTER_TAG_ID28,
    SYSTICK_MASTER_TAG_ID29,
    SYSTICK_MASTER_TAG_ID30,
    SYSTICK_MASTER_TAG_ID31,
} Systick_MasterTAGId_t;
#define CHECK_SYSTICKMASTERTAG_ID(ID) ((uint32_t)ID <= SYSTICK_MASTER_TAG_ID31)

typedef enum
{
    SYSTICK_INTR_CMP0,
    SYSTICK_INTR_CMP1,
    SYSTICK_INTR_OVERFLOW,
} Systick_IntrEnableFlagMask_t;

typedef enum
{
    SYSTICK_INTR_INDEX_CMP0,
    SYSTICK_INTR_INDEX_CMP1,
    SYSTICK_INTR_INDEX_OVERFLOW,
    SYSTICK_INTR_INDEX_CAPERR,
    SYSTICK_INTR_INDEX_TIM0ERR,
} Systick_IntrMask_t;

typedef enum
{
    SYSTICK_COMPARATOR_0,
    SYSTICK_COMPARATOR_1,
} Systick_Comparator_t;
#define CHECK_SYSTICK_COMPARATOR(COMPARATOR) (!(COMPARATOR >> 1))

typedef enum
{
    SYSTICK_COMPARATOR_OFFSET0,
    SYSTICK_COMPARATOR_OFFSET1,
    SYSTICK_COMPARATOR_OFFSET2,
    SYSTICK_COMPARATOR_OFFSET3,
    SYSTICK_COMPARATOR_OFFSET4,
    SYSTICK_COMPARATOR_OFFSET5,
    SYSTICK_COMPARATOR_OFFSET6,
    SYSTICK_COMPARATOR_OFFSET7,
    SYSTICK_COMPARATOR_OFFSET8,
    SYSTICK_COMPARATOR_OFFSET9,
    SYSTICK_COMPARATOR_OFFSET10,
    SYSTICK_COMPARATOR_OFFSET11,
    SYSTICK_COMPARATOR_OFFSET12,
    SYSTICK_COMPARATOR_OFFSET13,
    SYSTICK_COMPARATOR_OFFSET14,
    SYSTICK_COMPARATOR_OFFSET15,
    SYSTICK_COMPARATOR_OFFSET16,
    SYSTICK_COMPARATOR_OFFSET17,
    SYSTICK_COMPARATOR_OFFSET18,
    SYSTICK_COMPARATOR_OFFSET19,
    SYSTICK_COMPARATOR_OFFSET20,
    SYSTICK_COMPARATOR_OFFSET21,
    SYSTICK_COMPARATOR_OFFSET22,
    SYSTICK_COMPARATOR_OFFSET23,
    SYSTICK_COMPARATOR_OFFSET24,
    SYSTICK_COMPARATOR_OFFSET25,
    SYSTICK_COMPARATOR_OFFSET26,
    SYSTICK_COMPARATOR_OFFSET27,
    SYSTICK_COMPARATOR_OFFSET28,
    SYSTICK_COMPARATOR_OFFSET29,
    SYSTICK_COMPARATOR_OFFSET30,
    SYSTICK_COMPARATOR_OFFSET31,
} Systick_ComparatorOffset_t;
#define CHECK_SYSTICK_COMPARATOR_OFFSET(OFFSET) ((uint32_t)OFFSET <= SYSTICK_COMPARATOR_OFFSET31)

typedef enum
{
    SYSTICK_COMPARATOR_SIZE_1BIT,
    SYSTICK_COMPARATOR_SIZE_2BITS,
    SYSTICK_COMPARATOR_SIZE_3BITS,
    SYSTICK_COMPARATOR_SIZE_4BITS,
    SYSTICK_COMPARATOR_SIZE_5BITS,
    SYSTICK_COMPARATOR_SIZE_6BITS,
    SYSTICK_COMPARATOR_SIZE_7BITS,
    SYSTICK_COMPARATOR_SIZE_8BITS,
    SYSTICK_COMPARATOR_SIZE_9BITS,
    SYSTICK_COMPARATOR_SIZE_10BITS,
    SYSTICK_COMPARATOR_SIZE_11BITS,
    SYSTICK_COMPARATOR_SIZE_12BITS,
    SYSTICK_COMPARATOR_SIZE_13BITS,
    SYSTICK_COMPARATOR_SIZE_14BITS,
    SYSTICK_COMPARATOR_SIZE_15BITS,
    SYSTICK_COMPARATOR_SIZE_16BITS,
    SYSTICK_COMPARATOR_SIZE_17BITS,
    SYSTICK_COMPARATOR_SIZE_18BITS,
    SYSTICK_COMPARATOR_SIZE_19BITS,
    SYSTICK_COMPARATOR_SIZE_20BITS,
    SYSTICK_COMPARATOR_SIZE_21BITS,
    SYSTICK_COMPARATOR_SIZE_22BITS,
    SYSTICK_COMPARATOR_SIZE_23BITS,
    SYSTICK_COMPARATOR_SIZE_24BITS,
    SYSTICK_COMPARATOR_SIZE_25BITS,
    SYSTICK_COMPARATOR_SIZE_26BITS,
    SYSTICK_COMPARATOR_SIZE_27BITS,
    SYSTICK_COMPARATOR_SIZE_28BITS,
    SYSTICK_COMPARATOR_SIZE_29BITS,
    SYSTICK_COMPARATOR_SIZE_30BITS,
    SYSTICK_COMPARATOR_SIZE_31BITS,
    SYSTICK_COMPARATOR_SIZE_32BITS,
} Systick_ComparatorSize_t;
#define CHECK_SYSTICK_COMPARATOR_SIZE(SIZE) ((uint32_t)SIZE <= SYSTICK_COMPARATOR_SIZE_32BITS)

typedef enum
{
    SYSTICK_INTERRUPT_STIR0,
    SYSTICK_INTERRUPT_STIR1,
} Systick_ComparatorInterrupt_t;
#define CHECK_SYSTICK_INTERRUPT(INTERRUPT) (!(INTERRUPT >> 1))

typedef enum
{
    SYSTICK_TEST_RESULT_INVALID,
    SYSTICK_TEST_RESULT_SUCCESS,
    SYSTICK_TEST_RESULT_FAIL,
} Systick_TestStatus_t;

#define CHECK_SYSTICK_MODULE(MODULE) ((MODULE == SYSTICK0_PTR) || (MODULE == SYSTICK1_PTR))
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/*  SYSTICK_CLKC_T */

/**
 * @brief Systick模块使能/禁止
 * @param Module: 指向Systick内存结构的指针
 * @param Status:
 *        false   Systick 使能
 *        true   Systick 禁止
 * @retval void
 */
KF_INLINE void Systick_LL_SetModuleDisabled(Systick_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_CLKC_ADDR + offsetAddr);
    regValue &= ~HWIO_ST0_CLKC_ST0_CLKC_DISR_MASK;
    regValue |= Status << HWIO_ST0_CLKC_ST0_CLKC_DISR_SHFT;
    REG_WRITE(offsetAddr + HWIO_ST0_CLKC_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->SYSTICK_CLKC.bits.DISR, Status);
#endif
}

/**
 * @brief Systick获取模块禁止状态
 * @param Module: 指向Systick内存结构的指针
 * @retval bool
 *        false Systick模块已使能
 *        true Systick模块已禁止
 */
KF_INLINE bool Systick_LL_GetModuleStatus(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_CLKC_ADDR + offsetAddr);
    regValue &= HWIO_ST0_CLKC_ST0_CLKC_DISS_MASK;
    regValue = regValue >> HWIO_ST0_CLKC_ST0_CLKC_DISS_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_CLKC.bits.DISS));
#endif
}

/**
 * @brief Systick设置休眠模式
 * @param Module: 指向Systick内存结构的指针
 * @param Status:
 *        false   Systick 关闭休眠模式
 *        true   Systick 进入休眠模式
 * @retval void
 */
KF_INLINE void Systick_LL_SetSleepModeEnabled(Systick_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_CLKC_ADDR + offsetAddr);
    regValue &= ~HWIO_ST0_CLKC_ST0_CLKC_EDIS_MASK;
    regValue |= Status << HWIO_ST0_CLKC_ST0_CLKC_EDIS_SHFT;
    REG_WRITE(offsetAddr + HWIO_ST0_CLKC_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->SYSTICK_CLKC.bits.EDIS, Status);
#endif
}

/*  SYSTICK_INFO_T */

/**
 * @brief Systick获取模块版本号
 *
 * @param Module: 指向Systick内存结构的指针
 * @retval uint32_t 模块版本号
 */
KF_INLINE uint32_t Systick_LL_GetModuleVersion(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_INFO_ADDR + offsetAddr);
    regValue &= HWIO_ST0_INFO_ST0_INFO_MODREV_MASK;
    regValue = regValue >> HWIO_ST0_INFO_ST0_INFO_MODREV_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_INFO.bits.MODREV));
#endif
}

/**
 * @brief Systick获取模块类型
 *
 * @param Module: 指向Systick内存结构的指针
 * @retval uint32_t 模块类型
 */
KF_INLINE uint32_t Systick_LL_GetModuleType(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_INFO_ADDR + offsetAddr);
    regValue &= HWIO_ST0_INFO_ST0_INFO_MODTYPE_MASK;
    regValue = regValue >> HWIO_ST0_INFO_ST0_INFO_MODTYPE_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_INFO.bits.MODTYPE));
#endif
}

/**
 * @brief Systick获取模块编号
 *
 * @param Module: 指向Systick内存结构的指针
 * @retval uint32_t 模块编号
 */
KF_INLINE uint32_t Systick_LL_GetModuleNumber(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_INFO_ADDR + offsetAddr);
    regValue &= HWIO_ST0_INFO_ST0_INFO_MODNUM_MASK;
    regValue = regValue >> HWIO_ST0_INFO_ST0_INFO_MODNUM_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_INFO.bits.MODNUM));
#endif
}

/*  SYSTICK_DBG_T */

/**
 * @brief Systick返回模块挂起状态
 *
 * @param Module: 指向Systick内存结构的指针
 * @retval bool
 *        false Systick模块未挂起
 *        false Systick模块挂起
 */
KF_INLINE bool Systick_LL_IsModuleSuspended(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_DBG_ADDR + offsetAddr);
    regValue &= HWIO_ST0_DBG_ST0_DBG_SUSSTA_MASK;
    regValue = regValue >> HWIO_ST0_DBG_ST0_DBG_SUSSTA_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_DBG.bits.SUSSTA));
#endif
}

/**
 * @brief Systick模块设置挂起
 *
 * @param Module: 指向Systick内存结构的指针
 * @param SuspendMode Systick模块挂起模式
 *        SYSTICK_SUSPEND_MODE_NONE 不挂起
 *        SYSTICK_SUSPEND_MODE_STOP 64位计数器停止
 * @retval void
 */
KF_INLINE void Systick_LL_SetSuspendMode(Systick_RegisterMap_t *const Module, const Systick_SuspendMode_t SuspendMode)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICKSUSPEND_MODE(SuspendMode));

    SYSTICK_DBG_T regValue = {0U};
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    regValue.reg        = REG_READ(HWIO_ST0_DBG_ADDR + offsetAddr);
    regValue.bits.SUSP  = true;
    regValue.bits.SUS   = SuspendMode;
    REG_WRITE(offsetAddr + HWIO_ST0_DBG_ADDR, regValue.reg);
    // TODO: check if correct

#else
    regValue.reg       = REG_READ(Module->SYSTICK_DBG.reg);
    regValue.bits.SUSP = true;
    regValue.bits.SUS  = SuspendMode;
    REG_WRITE(Module->SYSTICK_DBG.reg, regValue.reg);
#endif
}

/*  SYSTICK_RST0_T */
/*  SYSTICK_RST1_T */

/**
 * @brief 复位Systick模块
 *
 * @param Module: 指向Systick内存结构的指针
 * @retval void
 */
KF_INLINE void Systick_LL_ResetModule(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_RSTx0_ADDR + offsetAddr);
    regValue &= ~HWIO_ST0_RSTx0_ST0_RSTx0_RST_MASK;
    regValue |= 1U << HWIO_ST0_RSTx0_ST0_RSTx0_RST_SHFT;
    REG_WRITE(offsetAddr + HWIO_ST0_RSTx0_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->SYSTICK_RST0.bits.RST, 1U);
#endif
#ifdef SIMULATION
    offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    regValue   = REG_READ(HWIO_ST0_RSTx1_ADDR + offsetAddr);
    regValue &= ~HWIO_ST0_RSTx0_ST0_RSTx0_RST_MASK;
    regValue |= 1U << HWIO_ST0_RSTx0_ST0_RSTx0_RST_SHFT;
    REG_WRITE(offsetAddr + HWIO_ST0_RSTx1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->SYSTICK_RST1.bits.RST, 1U);
#endif
}

/*  SYSTICK_RSTCLR_T */

/**
 * @brief 清除Systick模块复位状态
 *
 * @param Module: 指向Systick内存结构的指针
 * @retval void
 */
KF_INLINE void Systick_LL_ClearResetStatus(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_RSTxCLR_ADDR + offsetAddr);
    regValue &= ~HWIO_ST0_RSTxCLR_ST0_RSTxCLR_CLR_MASK;
    regValue |= 1U << HWIO_ST0_RSTxCLR_ST0_RSTxCLR_CLR_SHFT;
    REG_WRITE(offsetAddr + HWIO_ST0_RSTxCLR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->SYSTICK_RSTCLR.bits.CLR, 1U);
#endif
}

/**
 * @brief 获取Systick模块复位状态
 *
 * @param Module: 指向Systick内存结构的指针
 * @retval bool
 *        false 模块没有复位
 *        true 模块已复位
 */
KF_INLINE bool Systick_LL_GetResetStatus(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_RSTx0_ADDR + offsetAddr);
    regValue &= HWIO_ST0_RSTx0_ST0_RSTx0_RSTSTA_MASK;
    regValue = regValue >> HWIO_ST0_RSTx0_ST0_RSTx0_RSTSTA_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_RST0.bits.RSTSTA));
#endif
}

/*  SYSTICK_ACES0_T */

/**
 * @brief 设置Master TAG ID访问权限
 *
 * @param Module: 指向Systick内存结构的指针
 * @param Id Master TAG ID
 * @param Status bool
 *        false 写访问没有执行
 *        true 写访问执行
 * @return
 */
KF_INLINE void
Systick_LL_SetAccessEnabled(Systick_RegisterMap_t *const Module, const Systick_MasterTAGId_t Id, const bool Status)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICKMASTERTAG_ID(Id));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_ACES0_ADDR + offsetAddr);
    regValue &= ~(1U << Id);
    regValue |= ((uint32_t)Status << Id);

    REG_WRITE(offsetAddr + HWIO_ST0_ACES0_ADDR, regValue);
    // TODO: check if correct

#else
    REG_BITS_WRITE(Module->SYSTICK_ACES0.reg, (1U << Id), ((uint32_t)Status << Id));
#endif
}

/*  SYSTICK_TIM0_T */

/**
 * @brief Systick获取低32位计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @retval uint32_t 低32位计数值
 */
KF_INLINE uint32_t Systick_LL_GetLowerTimer(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_ST0_TIM0_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_TIM0.reg));
#endif
}

/*  SYSTICK_TIM1_T */

/**
 * @brief Systick获取TIM1计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint32_t
 */
KF_INLINE uint32_t Systick_LL_GetOffset4Timer(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_ST0_TIM1_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_TIM1.reg));
#endif
}

/*  SYSTICK_TIM2_T */

/**
 * @brief Systick获取TIM2计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint32_t
 */
KF_INLINE uint32_t Systick_LL_GetOffset8Timer(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_ST0_TIM2_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_TIM2.reg));
#endif
}

/*  SYSTICK_TIM3_T */

/**
 * @brief Systick获取TIM3计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint32_t
 */
KF_INLINE uint32_t Systick_LL_GetOffset12Timer(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_ST0_TIM3_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_TIM3.reg));
#endif
}

/*  SYSTICK_TIM4_T */

/**
 * @brief Systick获取TIM4计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint32_t
 */
KF_INLINE uint32_t Systick_LL_GetOffset16Timer(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_ST0_TIM4_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_TIM4.reg));
#endif
}

/*  SYSTICK_TIM5_T */

/**
 * @brief Systick获取TIM5计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint32_t
 */
KF_INLINE uint32_t Systick_LL_GetOffset20Timer(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_ST0_TIM5_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_TIM5.reg));
#endif
}

/*  SYSTICK_TIM6_T */

/**
 * @brief Systick获取TIM6计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint32_t
 */
KF_INLINE uint32_t Systick_LL_GetOffset32Timer(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_ST0_TIM6_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_TIM6.reg));
#endif
}

/*  SYSTICK_CAP_T */

/**
 * @brief Systick获取定时器计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint64_t
 */
KF_INLINE uint64_t Systick_LL_GetTimer(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    uint64_t result;
    uint32_t Reg_Cap;
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    result              = REG_READ(offsetAddr + HWIO_ST0_TIM0_ADDR);
    // TODO: check if correct

#else
    result  = REG_READ(Module->SYSTICK_TIM0.reg);
#endif
#ifdef SIMULATION
    offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    Reg_Cap    = REG_READ(offsetAddr + HWIO_ST0_CAP_ADDR);
    // TODO: check if correct

#else
    Reg_Cap = REG_READ(Module->SYSTICK_CAP.reg);
#endif
    result |= ((uint64_t)Reg_Cap) << 32U;
    return (result);
}

/**
 * @brief Systick获取当前定时器计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint64_t
 */
KF_INLINE uint64_t Systick_LL_GetTimerNow(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    uint64_t result;
    uint32_t Reg_Cap;
    __asm volatile("DSI");
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    result              = REG_READ(offsetAddr + HWIO_ST0_TIM0_ADDR);
    // TODO: check if correct

#else
    result  = REG_READ(Module->SYSTICK_TIM0.reg);
#endif
#ifdef SIMULATION
    offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    Reg_Cap    = REG_READ(offsetAddr + HWIO_ST0_CAP_ADDR);
    // TODO: check if correct

#else
    Reg_Cap = REG_READ(Module->SYSTICK_CAP.reg);
#endif
    result |= ((uint64_t)Reg_Cap) << 32U;
    __asm volatile("ENI");
    return (result);
}

/**
 * @brief
 *
 *
 * @param Module
 * @retval  uint32_t
 */
KF_INLINE uint32_t Systick_LL_GetCaptureValue(Systick_RegisterMap_t *const Module)
{
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_ST0_CAP_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_CAP.reg));
#endif
}

/*  SYSTICK_CMP_T */

/**
 * @brief 获取比较器值
 *
 * @param Module: 指向Systick内存结构的指针
 * @param Comparator
 *        SYSTICK_COMPARATOR_0 比较器0
 *        SYSTICK_COMPARATOR_1 比较器1
 * @retval 比较器值
 */
KF_INLINE uint32_t Systick_LL_GetCompare(Systick_RegisterMap_t *const Module, const Systick_Comparator_t Comparator)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_COMPARATOR(Comparator));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = 0;
    switch (Comparator)
    {
    case SYSTICK_COMPARATOR_0:
        regValue = REG_READ(offsetAddr + HWIO_ST0_CMP0_ADDR);
        break;
    case SYSTICK_COMPARATOR_1:
        regValue = REG_READ(offsetAddr + HWIO_ST0_CMP1_ADDR);
        break;
    default:
        break;
    }
#else
    return (REG_READ((Module->SYSTICK_CMP)[Comparator].bits.CMPVAL));
#endif
}

/**
 * @brief 设置比较器值
 *
 * @param Module: 指向Systick内存结构的指针
 * @param Comparator
 *        SYSTICK_COMPARATOR_0 比较器0
 *        SYSTICK_COMPARATOR_1 比较器1
 * @param ticks
 *
 * @retval void
 */
KF_INLINE void Systick_LL_UpdateCompare(
  Systick_RegisterMap_t *const Module, const Systick_Comparator_t Comparator, const uint32_t Ticks)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_COMPARATOR(Comparator));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    switch (Comparator)
    {
    case SYSTICK_COMPARATOR_0:
        REG_WRITE(offsetAddr + HWIO_ST0_CMP0_ADDR, Ticks);
        break;
    case SYSTICK_COMPARATOR_1:
        REG_WRITE(offsetAddr + HWIO_ST0_CMP1_ADDR, Ticks);
        break;

    default:
        break;
    }
#else
    REG_WRITE((Module->SYSTICK_CMP)[Comparator].bits.CMPVAL, Ticks);
#endif
}

/**
 * @brief 更新Systick比较器值为当前比较值 + Ticks
 *
 * @param Module: 指向Systick内存结构的指针
 * @param Comparator
 *        SYSTICK_COMPARATOR_0 比较器0
 *        SYSTICK_COMPARATOR_1 比较器1
 * @param ticks
 *
 * @retval void
 */
KF_INLINE void Systick_LL_IncreaseCompare(
  Systick_RegisterMap_t *const Module, const Systick_Comparator_t Comparator, const uint32_t Ticks)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_COMPARATOR(Comparator));
    uint32_t reg;
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    switch (Comparator)
    {
    case SYSTICK_COMPARATOR_0:
        REG_WRITE(offsetAddr + HWIO_ST0_CMP0_ADDR, REG_READ(offsetAddr + HWIO_ST0_CMP0_ADDR) + Ticks);
        break;
    case SYSTICK_COMPARATOR_1:
        REG_WRITE(offsetAddr + HWIO_ST0_CMP1_ADDR, REG_READ(offsetAddr + HWIO_ST0_CMP1_ADDR) + Ticks);
        break;
    default:
        break;
    }
#else
    reg = REG_READ((Module->SYSTICK_CMP)[Comparator].bits.CMPVAL) + Ticks;
#endif
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE((Module->SYSTICK_CMP)[Comparator].bits.CMPVAL, reg);
#endif
}

/*  SYSTICK_CMPCTL_T */

/**
 * @brief 设置比较器
 *
 * @param Module: 指向Systick内存结构的指针
 * @param Comparator
 *        SYSTICK_COMPARATOR_0 比较器0
 *        SYSTICK_COMPARATOR_1 比较器1
 * @param Offset
 *        SYSTICK_COMPARATOR_OFFSET0 起始位0
 *        ...
 *        SYSTICK_COMPARATOR_OFFSET31 起始位31
 * @param Size
 *        SYSTICK_COMPARATOR_SIZE_1BIT 比较范围1位
 *        SYSTICK_COMPARATOR_SIZE_32BITS 比较范围32位
 * @param Interrupt
 *        SYSTICK_INTERRUPT_STIR0 选择中断输出 STIR0
 *        SYSTICK_INTERRUPT_STIR1 选择中断输出 STIR1
 * @return
 */
KF_INLINE void Systick_LL_SetCompareControl(
  Systick_RegisterMap_t *const Module, const Systick_Comparator_t Comparator, const Systick_ComparatorOffset_t Offset,
  const Systick_ComparatorSize_t Size, const Systick_ComparatorInterrupt_t Interrupt)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_COMPARATOR(Comparator));
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_COMPARATOR_OFFSET(Offset));
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_COMPARATOR_SIZE(Size));
    if (Comparator == SYSTICK_COMPARATOR_0)
    {
#ifdef SIMULATION
        uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
        uint32_t regValue   = REG_READ(HWIO_ST0_CMPCTL_ADDR + offsetAddr);
        regValue &= ~HWIO_ST0_CMPCTL_ST0_CMPCTL_MSIZE0_MASK;
        regValue |= Size << HWIO_ST0_CMPCTL_ST0_CMPCTL_MSIZE0_SHFT;
        REG_WRITE(offsetAddr + HWIO_ST0_CMPCTL_ADDR, regValue);
        // TODO: check if correct

#else
        REG_WRITE(Module->SYSTICK_CMPCTL.bits.MSIZE0, Size);
#endif
#ifdef SIMULATION
        offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
        regValue   = REG_READ(HWIO_ST0_CMPCTL_ADDR + offsetAddr);
        regValue &= ~HWIO_ST0_CMPCTL_ST0_CMPCTL_MSTART0_MASK;
        regValue |= Offset << HWIO_ST0_CMPCTL_ST0_CMPCTL_MSTART0_SHFT;
        REG_WRITE(offsetAddr + HWIO_ST0_CMPCTL_ADDR, regValue);
        // TODO: check if correct

#else
        REG_WRITE(Module->SYSTICK_CMPCTL.bits.MSTART0, Offset);
#endif
#ifdef SIMULATION
        offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
        regValue   = REG_READ(HWIO_ST0_ICR_ADDR + offsetAddr);
        regValue &= ~HWIO_ST0_ICR_ST0_ICR_CMP0IFSEL_MASK;
        regValue |= Interrupt << HWIO_ST0_ICR_ST0_ICR_CMP0IFSEL_SHFT;
        REG_WRITE(offsetAddr + HWIO_ST0_ICR_ADDR, regValue);
        // TODO: check if correct

#else
        REG_WRITE(Module->SYSTICK_ICR.bits.CMP0IFSEL, Interrupt);
#endif
    }
    else
    {
#ifdef SIMULATION
        uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
        uint32_t regValue   = REG_READ(HWIO_ST0_CMPCTL_ADDR + offsetAddr);
        regValue &= ~HWIO_ST0_CMPCTL_ST0_CMPCTL_MSIZE1_MASK;
        regValue |= Size << HWIO_ST0_CMPCTL_ST0_CMPCTL_MSIZE1_SHFT;
        REG_WRITE(offsetAddr + HWIO_ST0_CMPCTL_ADDR, regValue);
        // TODO: check if correct

#else
        REG_WRITE(Module->SYSTICK_CMPCTL.bits.MSIZE1, Size);
#endif
#ifdef SIMULATION
        offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
        regValue   = REG_READ(HWIO_ST0_CMPCTL_ADDR + offsetAddr);
        regValue &= ~HWIO_ST0_CMPCTL_ST0_CMPCTL_MSTART1_MASK;
        regValue |= Offset << HWIO_ST0_CMPCTL_ST0_CMPCTL_MSTART1_SHFT;
        REG_WRITE(offsetAddr + HWIO_ST0_CMPCTL_ADDR, regValue);
#else
        REG_WRITE(Module->SYSTICK_CMPCTL.bits.MSTART1, Offset);
#endif
#ifdef SIMULATION
        offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
        regValue   = REG_READ(HWIO_ST0_ICR_ADDR + offsetAddr);
        regValue &= ~HWIO_ST0_ICR_ST0_ICR_CMP1IFSEL_MASK;
        regValue |= Interrupt << HWIO_ST0_ICR_ST0_ICR_CMP1IFSEL_SHFT;
        REG_WRITE(offsetAddr + HWIO_ST0_ICR_ADDR, regValue);
        // TODO: check if correct

#else
        REG_WRITE(Module->SYSTICK_ICR.bits.CMP1IFSEL, Interrupt);
#endif
    }
}

/*  SYSTICK_ICR_T */

/**
 * @brief 使能定时器技术到重载值时重载
 *
 * @param Module: 指向Systick内存结构的指针
 * @param Status
 * false 不重载
 * true 重载
 * @retval void
 */
KF_INLINE void Systick_LL_EnableTimerOverload(Systick_RegisterMap_t *const Module, const bool Status)
{

    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_ICR_ADDR + offsetAddr);
    regValue &= ~0x80000000;
    regValue |= Status << 31;
    REG_WRITE(offsetAddr + HWIO_ST0_ICR_ADDR, regValue);
    // TODO: check if correct
#else
    REG_BIT_SET(Module->SYSTICK_ICR.bits.OVERFLOWMOD, Status);
#endif
}

/**
 * @brief Systick返回比较标志状态
 *
 * @param Module: 指向Systick内存结构的指针
 * @param IntrMask
 *   SYSTICK_INTR_CMP0
 *   SYSTICK_INTR_CMP1
 *   SYSTICK_INTR_OVERFLOW
 * @retval
 *        false 中断请求标志位清零
 *        true 中断请求标志位置位
 * @attention 这个标志位不会产生中断，在CMPxIE使能的情况下，即使该标志位没有清零，中断也只能由比较匹配事件产生
 */
KF_INLINE bool Systick_LL_GetIntrFlag(Systick_RegisterMap_t *const Module, const Systick_IntrEnableFlagMask_t IntrMask)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_COMPARATOR(Comparator));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (bool)(REG_BITS_READ(
      offsetAddr + HWIO_ST0_ICR_ADDR, (1U << (1U + ((uint32_t)IntrMask << 2))),
      ((1U + ((uint32_t)IntrMask << 2))))); // TODO: check if correct

#else
    return (bool)(REG_BITS_READ(
      Module->SYSTICK_ICR.reg, (1U << (1U + ((uint32_t)IntrMask << 2))), ((1U + ((uint32_t)IntrMask << 2)))));
#endif
}

/**
 * @brief Systick 比较中断使能控制
 *
 * @param Module: 指向Systick内存结构的指针
 * @param IntrMask
 *   SYSTICK_INTR_CMP0
 *   SYSTICK_INTR_CMP1
 *   SYSTICK_INTR_OVERFLOW
 * @param Status
 *        false 禁止中断
 *        true 使能中断
 * @return KF_INLINE
 */
KF_INLINE void Systick_LL_SetIntrEnabled(
  Systick_RegisterMap_t *const Module, const Systick_IntrEnableFlagMask_t IntrMask, const bool Status)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_COMPARATOR(Comparator));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_ICR_ADDR + offsetAddr);
    regValue &= ~(1U << ((uint32_t)IntrMask << 2));
    regValue |= ((uint32_t)Status << ((uint32_t)IntrMask << 2));
    REG_WRITE(offsetAddr + HWIO_ST0_ICR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_BITS_WRITE(
      Module->SYSTICK_ICR.reg, (1U << ((uint32_t)IntrMask << 2)), ((uint32_t)Status << ((uint32_t)IntrMask << 2)));
#endif
}

/*  SYSTICK_ISCR_T */

/**
 * @brief Systick 中断清零寄存器
 *
 * @param Module: 指向Systick内存结构的指针
 * @param IntrMask
 *   SYSTICK_INTR_INDEX_CMP0,
 *   SYSTICK_INTR_INDEX_CMP1,
 *   SYSTICK_INTR_INDEX_OVERFLOW,
 *   SYSTICK_INTR_INDEX_CAPERR,
 *   SYSTICK_INTR_INDEX_TIM0ERR,
 * @return KF_INLINE
 */
KF_INLINE void Systick_LL_ClearIntrFlag(Systick_RegisterMap_t *const Module, const Systick_IntrMask_t IntrMask)
{
    uint32_t Mask;
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));

    Mask = (uint32_t)0x1U << ((uint32_t)IntrMask << 1U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_ISCR_ADDR + offsetAddr);
    regValue |= (Mask);

    REG_WRITE(offsetAddr + HWIO_ST0_ISCR_ADDR, regValue);
#else
    REG_BIT_SET(Module->SYSTICK_ISCR.reg, Mask);
#endif
}

/**
 * @brief Systick 中断清零寄存器
 *
 * @param Module: 指向Systick内存结构的指针
 * @param IntrMask
 *   SYSTICK_INTR_INDEX_CMP0,
 *   SYSTICK_INTR_INDEX_CMP1,
 *   SYSTICK_INTR_INDEX_OVERFLOW,
 *   SYSTICK_INTR_INDEX_CAPERR,
 *   SYSTICK_INTR_INDEX_TIM0ERR,
 * @return KF_INLINE
 */
KF_INLINE void Systick_LL_SetIntrFlag(Systick_RegisterMap_t *const Module, const Systick_IntrMask_t IntrMask)
{
    uint32_t Mask;
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));

    Mask = (uint32_t)0x1U << (((uint32_t)IntrMask << 1U) + 1U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_ISCR_ADDR + offsetAddr);
    regValue |= (Mask);

    REG_WRITE(offsetAddr + HWIO_ST0_ISCR_ADDR, regValue);
#else
    REG_BIT_SET(Module->SYSTICK_ISCR.reg, Mask);
#endif
}

/**
 * @brief Systick获取备份TIM0计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint32_t
 */
KF_INLINE uint32_t Systick_LL_GetLowerTimerBackup(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_ST0_TIM0SV_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_TIM0SV.reg));
#endif
}

/**
 * @brief Systick获取备份CAP值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint32_t
 */
KF_INLINE uint32_t Systick_LL_GetCapBackup(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_ST0_CAPSV_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->SYSTICK_CAPSV.reg));
#endif
}

/**
 * @brief Systick获取备份定时器计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint64_t
 */
KF_INLINE uint64_t Systick_LL_GetTimerBackup(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    uint64_t result;
    uint32_t Reg_CAPSV;
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    result              = REG_READ(offsetAddr + HWIO_ST0_TIM0SV_ADDR);
    // TODO: check if correct

#else
    result    = REG_READ(Module->SYSTICK_TIM0SV.reg);
#endif
#ifdef SIMULATION
    offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    Reg_CAPSV  = REG_READ(offsetAddr + HWIO_ST0_CAPSV_ADDR);
    // TODO: check if correct

#else
    Reg_CAPSV = REG_READ(Module->SYSTICK_CAPSV.reg);
#endif
    result |= ((uint64_t)Reg_CAPSV) << 32U;
    return (result);
}

/**
 * @brief Systick获取当前备份定时器计数值
 *
 * @param Module: 指向Systick内存结构的指针
 * @return uint64_t
 */
KF_INLINE uint64_t Systick_LL_GetTimerBackupNow(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    uint64_t result;
    uint32_t Reg_CAPSV;
    __asm volatile("DSI");
    result = Module->SYSTICK_TIM0SV.reg;
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    Reg_CAPSV           = REG_READ(offsetAddr + HWIO_ST0_CAPSV_ADDR);
    // TODO: check if correct

#else
    Reg_CAPSV = REG_READ(Module->SYSTICK_CAPSV.reg);
#endif
    result |= ((uint64_t)Reg_CAPSV) << 32U;
    __asm volatile("ENI");
    return (result);
}

/**
 * @brief 设置定时器高位溢出重载值
 *
 * @param Module: 指向Systick内存结构的指针
 * @param Value 重载值
 *
 * @retval void
 */
KF_INLINE void Systick_LL_SetTimerHighOverflowValue(Systick_RegisterMap_t *const Module, const uint32_t Value)
{
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + 0xF000015c, Value);
#else
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    REG_WRITE(Module->SYSTICK_OVH.bits.OVERFLOWVAL_H, Value);
#endif
}

/**
 * @brief 设置定时器低位溢出重载值
 *
 * @param Module: 指向Systick内存结构的指针
 * @param Value 重载值
 *
 * @retval void
 */
KF_INLINE void Systick_LL_SetTimerLowOverflowValue(Systick_RegisterMap_t *const Module, const uint32_t Value)
{
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + 0xF0000160, Value);
#else
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    REG_WRITE(Module->SYSTICK_OVL.bits.OVERFLOWVAL_L, Value);
#endif
}

/**
 * @brief Systick设置备份寄存器测试模式
 *
 * @param Module: 指向Systick内存结构的指针
 * @param Status
 *        false  正常模式
 *        true  测试模式
 * @retval
 */
KF_INLINE void Systick_LL_SetTestEnabled(Systick_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_TEST_ADDR + offsetAddr);
    regValue &= ~HWIO_ST0_TEST_ST0_TEST_TESTEN_MASK;
    regValue |= Status << HWIO_ST0_TEST_ST0_TEST_TESTEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_ST0_TEST_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->SYSTICK_TEST.bits.TESTEN, Status);
#endif
}

/**
 * @brief Systick获取测试结果
 *
 * @param Module: 指向Systick内存结构的指针
 * @retval Systick_TestStatus_t
 *        SYSTICK_TEST_RESULT_INVALID 无效
 *        SYSTICK_TEST_RESULT_SUCCESS 成功
 *        SYSTICK_TEST_RESULT_FAIL 失败
 */
KF_INLINE Systick_TestStatus_t Systick_LL_GetTestStatus(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
    Systick_TestStatus_t result;
    uint8_t              Bits_TESTNG;
    uint8_t              Bits_TESTOK;
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_TEST_ADDR + offsetAddr);
    regValue &= HWIO_ST0_TEST_ST0_TEST_TESTNG_MASK;
    regValue    = regValue >> HWIO_ST0_TEST_ST0_TEST_TESTNG_SHFT;
    Bits_TESTNG = (regValue);
    // TODO: check if correct

#else
    Bits_TESTNG = REG_READ(Module->SYSTICK_TEST.bits.TESTNG);
#endif
#ifdef SIMULATION
    offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    regValue   = REG_READ(HWIO_ST0_TEST_ADDR + offsetAddr);
    regValue &= HWIO_ST0_TEST_ST0_TEST_TESTOK_MASK;
    regValue    = regValue >> HWIO_ST0_TEST_ST0_TEST_TESTOK_SHFT;
    Bits_TESTOK = (regValue);
    // TODO: check if correct

#else
    Bits_TESTOK = REG_READ(Module->SYSTICK_TEST.bits.TESTOK);
#endif
    result = (Systick_TestStatus_t)((Bits_TESTNG << 1) | Bits_TESTOK);
    return result;
}

/**
 * @brief 清除测试标志位
 *
 * @param Module: 指向Systick内存结构的指针
 * @retval
 */
KF_INLINE void Systick_LL_ClearTestStatus(Systick_RegisterMap_t *const Module)
{
    KF_DRV_SYSTICK_ASSERT(CHECK_SYSTICK_MODULE(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~SYSTICK_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_ST0_TEST_ADDR + offsetAddr);
    regValue &= ~HWIO_ST0_TEST_ST0_TEST_TESTC_MASK;
    regValue |= 1U << HWIO_ST0_TEST_ST0_TEST_TESTC_SHFT;
    REG_WRITE(offsetAddr + HWIO_ST0_TEST_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->SYSTICK_TEST.bits.TESTC, 1U);
#endif
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
