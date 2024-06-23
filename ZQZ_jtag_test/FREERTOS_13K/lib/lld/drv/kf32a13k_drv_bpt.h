/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_bpt.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-22
 *  @Version         : V0.0.1.231222_alpha
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
 *  |2023-12-22                                       |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/
#ifndef KF32DA13K_DRV_BPT_H_
#define KF32DA13K_DRV_BPT_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a13k_reg_bpt.h"

#ifdef KF_DRV_BPT_ASSERT
#include "dev_assert.h"
#define KF_DRV_BPT_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_BPT_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/

typedef enum
{
    BPT_SUSPEND_MODE_NONE = 0,
    BPT_SUSPEND_MODE_STOP = 2,
} Bpt_SuspendMode_t;
#define CHECK_BPT_SUSPEND_MODE(MODE) ((MODE == BPT_SUSPEND_MODE_NONE) || (MODE == BPT_SUSPEND_MODE_STOP))

typedef enum
{
    BPT_MASTER_TAG_ID0,
    BPT_MASTER_TAG_ID1,
    BPT_MASTER_TAG_ID2,
    BPT_MASTER_TAG_ID3,
    BPT_MASTER_TAG_ID4,
    BPT_MASTER_TAG_ID5,
    BPT_MASTER_TAG_ID6,
    BPT_MASTER_TAG_ID7,
    BPT_MASTER_TAG_ID8,
    BPT_MASTER_TAG_ID9,
    BPT_MASTER_TAG_ID10,
    BPT_MASTER_TAG_ID11,
    BPT_MASTER_TAG_ID12,
    BPT_MASTER_TAG_ID13,
    BPT_MASTER_TAG_ID14,
    BPT_MASTER_TAG_ID15,
    BPT_MASTER_TAG_ID16,
    BPT_MASTER_TAG_ID17,
    BPT_MASTER_TAG_ID18,
    BPT_MASTER_TAG_ID19,
    BPT_MASTER_TAG_ID20,
    BPT_MASTER_TAG_ID21,
    BPT_MASTER_TAG_ID22,
    BPT_MASTER_TAG_ID23,
    BPT_MASTER_TAG_ID24,
    BPT_MASTER_TAG_ID25,
    BPT_MASTER_TAG_ID26,
    BPT_MASTER_TAG_ID27,
    BPT_MASTER_TAG_ID28,
    BPT_MASTER_TAG_ID29,
    BPT_MASTER_TAG_ID30,
    BPT_MASTER_TAG_ID31,
    BPT_MASTER_TAG_ID32,
    BPT_MASTER_TAG_ID33,
    BPT_MASTER_TAG_ID34,
    BPT_MASTER_TAG_ID35,
    BPT_MASTER_TAG_ID36,
    BPT_MASTER_TAG_ID37,
    BPT_MASTER_TAG_ID38,
    BPT_MASTER_TAG_ID39,
    BPT_MASTER_TAG_ID40,
    BPT_MASTER_TAG_ID41,
    BPT_MASTER_TAG_ID42,
    BPT_MASTER_TAG_ID43,
    BPT_MASTER_TAG_ID44,
    BPT_MASTER_TAG_ID45,
    BPT_MASTER_TAG_ID46,
    BPT_MASTER_TAG_ID47,
    BPT_MASTER_TAG_ID48,
    BPT_MASTER_TAG_ID49,
    BPT_MASTER_TAG_ID50,
    BPT_MASTER_TAG_ID51,
    BPT_MASTER_TAG_ID52,
    BPT_MASTER_TAG_ID53,
    BPT_MASTER_TAG_ID54,
    BPT_MASTER_TAG_ID55,
    BPT_MASTER_TAG_ID56,
    BPT_MASTER_TAG_ID57,
    BPT_MASTER_TAG_ID58,
    BPT_MASTER_TAG_ID59,
    BPT_MASTER_TAG_ID60,
    BPT_MASTER_TAG_ID61,
    BPT_MASTER_TAG_ID62,
    BPT_MASTER_TAG_ID63,
} Bpt_MasterTAGId_t;
#define CHECK_BPT_MASTER_TAG_ID(ID) (!(ID >> 6))

/**定时器计数方式*/
typedef enum
{
    BPT_COUNTING_MANNER_UP_UP_FLAG,
    BPT_COUNTING_MANNER_DOWN_DOWN_FLAG,
    BPT_COUNTING_MANNER_UP_DOWN_UP_FLAG,
    BPT_COUNTING_MANNER_UP_DOWN_DOWN_FLAG,
    BPT_COUNTING_MANNER_UP_DOWN_BOTH_FLAG,
} Bpt_CountingManner_t;
#define CHECK_BPT_COUNTING_MANNER(MANNER) ((uint32_t)MANNER <= BPT_COUNTING_UP_DOWN_BOTH_FLAG)

typedef enum
{
    BPT_COUNTING_SOURCE_NO_SOURCE,
    BPT_COUNTING_SOURCE_EXTCLK1,
    BPT_COUNTING_SOURCE_EXTCLK2,
    BPT_COUNTING_SOURCE_EXTCLK3,
    BPT_COUNTING_SOURCE_EXTCLK4,
    BPT_COUNTING_SOURCE_TRGI,
} Bpt_CountingSource_t;
#define CHECK_BPT_COUNTING_SOURCE(SOURCE) ((uint32_t)SOURCE <= BPT_COUNTING_SOURCE_TRGI)

typedef enum
{
    BPT_SINGLE_PULSE_KEEP_EN_BIT,
    BPT_SINGLE_PULSE_SWITCH_OFF_EN_BIT,
} Bpt_SinglePulseMode_t;
#define CHECK_BPT_SINGLE_PULSE_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    BPT_SLAVE_MODE_DISABLED,
    BPT_SLAVE_MODE_TRIGGER_MODE,
    BPT_SLAVE_MODE_GATING_MODE,
    BPT_SLAVE_MODE_RESET_MODE,
} Bpt_SlaveMode_t;
#define CHECK_BPT_SLAVE_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    BPT_TRIGGER_INPUT_SOURCE_TRGI0,
    BPT_TRIGGER_INPUT_SOURCE_TRGI1,
    BPT_TRIGGER_INPUT_SOURCE_TRGI2,
    BPT_TRIGGER_INPUT_SOURCE_TRGI3,
    BPT_TRIGGER_INPUT_SOURCE_TRGI4,
    BPT_TRIGGER_INPUT_SOURCE_TRGI5,
    BPT_TRIGGER_INPUT_SOURCE_TRGI6,
    BPT_TRIGGER_INPUT_SOURCE_TRGI7,
    BPT_TRIGGER_INPUT_SOURCE_TRGI8,
    BPT_TRIGGER_INPUT_SOURCE_TRGI9,
    BPT_TRIGGER_INPUT_SOURCE_TRGI10,
    BPT_TRIGGER_INPUT_SOURCE_TRGI11,
    BPT_TRIGGER_INPUT_SOURCE_TRGI12,
    BPT_TRIGGER_INPUT_SOURCE_TRGI13,
    BPT_TRIGGER_INPUT_SOURCE_TRGI14,
    BPT_TRIGGER_INPUT_SOURCE_TRGI15,
    BPT_TRIGGER_INPUT_SOURCE_TRGI16,
    BPT_TRIGGER_INPUT_SOURCE_TRGI17,
    BPT_TRIGGER_INPUT_SOURCE_TRGI18,
    BPT_TRIGGER_INPUT_SOURCE_TRGI19,
    BPT_TRIGGER_INPUT_SOURCE_TRGI20,
    BPT_TRIGGER_INPUT_SOURCE_TRGI21,
    BPT_TRIGGER_INPUT_SOURCE_TRGI22,
    BPT_TRIGGER_INPUT_SOURCE_TRGI23,
    BPT_TRIGGER_INPUT_SOURCE_TRGI24,
    BPT_TRIGGER_INPUT_SOURCE_TRGI25,
    BPT_TRIGGER_INPUT_SOURCE_TRGI26,
    BPT_TRIGGER_INPUT_SOURCE_TRGI27,
    BPT_TRIGGER_INPUT_SOURCE_TRGI28,
    BPT_TRIGGER_INPUT_SOURCE_TRGI29,
    BPT_TRIGGER_INPUT_SOURCE_TRGI30,
    BPT_TRIGGER_INPUT_SOURCE_TRGI31,
} Bpt_TriggerInputSource_t;
#define CHECK_BPT_TRIGGER_INPUT_SOURCE(SOURCE) (!(SOURCE >> 5))

typedef enum
{
    BPT_TRIGGER_OUTPUT_SOURCE_DISABLED,
    BPT_TRIGGER_OUTPUT_SOURCE_EN,
    BPT_TRIGGER_OUTPUT_SOURCE_OVERFLOW,
    BPT_TRIGGER_OUTPUT_SOURCE_UPDATE,
} Bpt_TriggerOutputSource_t;
#define CHECK_BPT_TRIGGER_OUTPUT_SOURCE(SOURCE) (!(SOURCE >> 2))

typedef enum
{
    BPT_TIMER_UPDATE_PERIODIC,
    BPT_TIMER_UPDATE_NOW,
} Bpt_TimerUpdateMode_t;
#define CHECK_BPT_TIMER_UPDATE_MODE(MODE) (!(MODE >> 1))

typedef enum
{
    BPT_COUNTING_DIRECTION_UP,
    BPT_COUNTING_DIRECTION_DOWN,
} Bpt_CountingDirection_t;
#define CHECK_BPT_COUNTING_DIRECTION(DIR) (!(DIR >> 1))

typedef enum
{
    BPT_INTERRUPT_FLAG_OVERFLOW      = 0,
    BPT_INTERRUPT_FLAG_TRIGGER_EVENT = 5,
    BPT_INTERRUPT_FLAG_UPDATE_EVENT  = 6,
} Bpt_InterruptFlagIndex_t;
#define CHECK_BPT_INTERRUPT_FLAG_INDEX(INDEX)                                                                          \
    ((INDEX == BPT_INTERRUPT_FLAG_OVERFLOW) || (INDEX == BPT_INTERRUPT_FLAG_TRIGGER_EVENT) ||                          \
     (INDEX == BPT_INTERRUPT_FLAG_UPDATE_EVENT))

typedef enum
{
    BPT_TEST_OUTPUT_CNT,
    BPT_TEST_OUTPUT_UDTIM,
    BPT_TEST_OUTPUT_CLK_DIV,
    BPT_TEST_OUTPUT_UPDATE
} Bpt_TestModeOutput_t;
#define CHECK_BPT_TEST_MODE_OUTPUT(OUTPUT) ((OUTPUT <= BPT_TEST_OUTPUT_UPDATE)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief Bpt模块使能/禁止
 * @param Module 指向BPT内存结构的指针
 * @param Status 使能/禁止状态
 *                false   Bpt 使能
 *                true   Bpt 禁止
 * @retval void
 */
KF_INLINE void Bpt_LL_SetModuleDisabled(BPT_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_CLKC.bits.DISR, Status);
}

/**
 * @brief Bpt获取模块禁止状态
 * @param Module 指向BPT内存结构的指针
 *
 * @retval bool
 *               false Bpt模块已使能
 *               true Bpt模块已禁止
 */
KF_INLINE bool Bpt_LL_GetModuleStatus(BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    return (REG_READ(Module->BPT_CLKC.bits.DISS));
}

/**
 * @brief Bpt设置休眠模式
 * @param Module 指向BPT内存结构的指针
 * @param Status:
 *                false   Bpt 使能休眠模式
 *                true   Bpt 禁止休眠模式
 * @retval void
 */
KF_INLINE void Bpt_LL_SetSleepModeDisabled(BPT_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_CLKC.bits.EDIS, Status);
}

/*  BPT_INFO_T */

/**
 * @brief Bpt获取模块版本号
 * @param Module 指向BPT内存结构的指针
 *
 * @param void
 * @retval uint32_t 模块版本号
 */
KF_INLINE uint32_t Bpt_LL_GetModuleVersion(const BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    return (REG_READ(Module->BPT_INFO.bits.MODREV));
}

/**
 * @brief Bpt获取模块类型
 * @param Module 指向BPT内存结构的指针
 *
 * @param void
 * @retval uint32_t 模块类型
 */
KF_INLINE uint32_t Bpt_LL_GetModuleType(const BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    return (REG_READ(Module->BPT_INFO.bits.MODTYPE));
}

/**
 * @brief Bpt获取模块编号
 * @param Module 指向BPT内存结构的指针
 *
 * @param void
 * @retval uint32_t 模块编号
 */
KF_INLINE uint32_t Bpt_LL_GetModuleNumber(const BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    return (REG_READ(Module->BPT_INFO.bits.MODNUM));
}

/*  BPT_DBG_T */

/**
 * @brief Bpt返回模块挂起状态
 * @param Module 指向BPT内存结构的指针
 *
 * @param void
 * @retval bool
 *               false Bpt模块未挂起
 *               false Bpt模块挂起
 */
KF_INLINE bool Bpt_LL_IsModuleSuspended(const BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    return (REG_READ(Module->BPT_DBG.bits.SUSSTA));
}

/**
 * @brief Bpt模块设置挂起
 * @param Module 指向BPT内存结构的指针
 *
 * @param SuspendMode Bpt模块挂起模式
 *                BPT_SUSPEND_MODE_NONE 不挂起
 *                BPT_SUSPEND_MODE_STOP 64位计数器停止
 * @retval void
 */
KF_INLINE void Bpt_LL_SetSuspendMode(BPT_RegisterMap_t *const Module, const Bpt_SuspendMode_t SuspendMode)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_SUSPEND_MODE(SuspendMode));

    BPT_DBG_T regValue = {0U};

    regValue.reg = REG_READ(Module->BPT_DBG.reg);
    regValue.bits.SUSP = true;
    regValue.bits.SUS  = SuspendMode;
    REG_WRITE(Module->BPT_DBG.reg, regValue.reg);
}

/*  BPT_RST0_T */
/*  BPT_RST1_T */

/**
 * @brief 复位Bpt模块
 * @param Module 指向BPT内存结构的指针
 *
 * @retval
 */
KF_INLINE void Bpt_LL_ResetModule(BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_RST0.bits.RST, 1U);
    REG_WRITE(Module->BPT_RST1.bits.RST, 1U);
}

/*  BPT_RSTCLR_T */

/**
 * @brief 清除Bpt模块复位状态
 * @param Module 指向BPT内存结构的指针
 *
 * @retval
 */
KF_INLINE void Bpt_LL_ClearResetStatus(BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_RSTCLR.bits.CLR, 1U);
}

/**
 * @brief 获取Bpt模块复位状态
 * @param Module 指向BPT内存结构的指针
 *
 * @retval bool
 *        false 模块没有复位
 *        true 模块已复位
 */
KF_INLINE bool Bpt_LL_GetResetStatus(const BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    return (REG_READ(Module->BPT_RST0.bits.RSTSTA));
}

/*  BPT_ACES0_T */

/**
 * @brief 设置BPT模块Master TAG ID访问权限
 *
 * @param Module 指向BPT内存结构的指针
 * @param Id Master TAG ID
 * @param Status bool
 *        false 写访问没有执行
 *        true 写访问执行
 * @retval void
 */
KF_INLINE void Bpt_LL_SetAccessEnabled(BPT_RegisterMap_t *const Module, const Bpt_MasterTAGId_t Id, const bool Status)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_MASTER_TAG_ID(Id));
    if (Id < BPT_MASTER_TAG_ID32)
    {
        REG_BITS_WRITE(Module->BPT_ACES0.reg, (1U << Id), ((uint32_t)Status << Id));
    }
    else
    {
        REG_BITS_WRITE(
          Module->BPT_ACES1.reg, (1U << (Id - BPT_MASTER_TAG_ID32)), ((uint32_t)Status << (Id - BPT_MASTER_TAG_ID32)));
    }
}

/*  BPT_CTL1_T */

/**
 * @brief BPT模块使能 /禁止
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Status bool
 *                false 停止定时器，计数器暂停计数
 *                true 启动定时器，计数器开始计数
 * @retval void
 */
KF_INLINE void Bpt_LL_SetTimerEnabled(BPT_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_CTL1.bits.EN, Status);
}

/**
 * @brief BPT模块设置计数方式
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Manner 计数方式选择
 *                BPT_COUNTING_MANNER_UP_UP_FLAG 向上计数，上溢产生中断标志
 *                BPT_COUNTING_MANNER_DOWN_DOWN_FLAG 向下计数，下溢产生中断标志
 *                BPT_COUNTING_MANNER_UP_DOWN_UP_FLAG 向上向下计数，上溢产生中断标志
 *                BPT_COUNTING_MANNER_UP_DOWN_DOWN_FLAG 向上向下计数，下溢产生中断标志
 *                BPT_COUNTING_MANNER_UP_DOWN_BOTH_FLAG 向上向下计数，上溢和下溢均产生中断标志
 * @retval void
 */
KF_INLINE void Bpt_LL_SetCounterManner(BPT_RegisterMap_t *const Module, const Bpt_CountingManner_t Manner)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_COUNTING_MANNER(Manner));
    REG_WRITE(Module->BPT_CTL1.bits.CMS, Manner);
}

/**
 * @brief BPT模块设置计数时钟源
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Source 计数源
 *                BPT_COUNTING_SOURCE_NO_SOURCE 不选择计数源，计数器每个时钟都计数
 *                BPT_COUNTING_SOURCE_EXTCLK1 计数源为 EXTCLK1，在 EXTCLK1 上升沿计数
 *                BPT_COUNTING_SOURCE_EXTCLK2 计数源为 EXTCLK2，在 EXTCLK2 上升沿计数
 *                BPT_COUNTING_SOURCE_EXTCLK3 计数源为 EXTCLK3，在 EXTCLK3 上升沿计数
 *                BPT_COUNTING_SOURCE_EXTCLK4 计数源为 EXTCLK4，在 EXTCLK4 上升沿计数
 *                BPT_COUNTING_SOURCE_TRGI 计数源为 TRGI，上升沿到来时计数值+1
 * @retval void
 */
KF_INLINE void Bpt_LL_SetCounterSource(BPT_RegisterMap_t *const Module, const Bpt_CountingSource_t Source)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_COUNTING_SOURCE(Module));
    REG_WRITE(Module->BPT_CTL1.bits.CLKSMUX, Source);
}

/**
 * @brief BPT模块使能单脉冲输出模式
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Status bool
 *                false 禁止单脉冲输出模式
 *                true 使能单脉冲输出模式
 * @retval void
 */
KF_INLINE void Bpt_LL_EnableSinglePulseMode(BPT_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_CTL1.bits.SPM, Status);
}

/**
 * @brief BPT模块设置单脉冲输出模式
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Mode 单脉冲输出模式
 *                BPT_SINGLE_PULSE_KEEP_EN_BIT 单脉冲输出后不关闭 EN 位
 *                BPT_SINGLE_PULSE_SWITCH_OFF_EN_BIT 单脉冲输出后关闭 EN 位
 * @retval void
 */
KF_INLINE void Bpt_LL_SetSinglePulseMode(BPT_RegisterMap_t *const Module, const Bpt_SinglePulseMode_t Mode)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_SINGLE_PULSE_MODE(Module));
    REG_WRITE(Module->BPT_CTL1.bits.SPMST, Mode);
}

/**
 * @brief BPT模块使能主从模式同步
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Status bool
 *                false 未使能
 *                true 触发输入上的事件将被延迟，以使主、从定时器同步响应外部触发
 * @retval void
 */
KF_INLINE void Bpt_LL_EnableMasterSlaveModeSync(BPT_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_CTL1.bits.MSSYNC, Status);
}

/**
 * @brief BPT模块使能计数时钟同步
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Status bool
 *                false 未使能
 *                true 非 fBPT 时钟源下，使用 fBPT 时钟源进行同步
 * @retval void
 */
KF_INLINE void Bpt_LL_EnableCounterClockSync(BPT_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_CTL1.bits.SY, Status);
}

/**
 * @brief BPT模块选择从模式
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Mode 从模式选择
 *                BPT_SLAVE_MODE_DISABLED 从模式禁止
 *                BPT_SLAVE_MODE_TRIGGER_MODE 触发模式
 *                BPT_SLAVE_MODE_GATING_MODE 门控模式
 *                BPT_SLAVE_MODE_RESET_MODE 复位模式
 * @retval void
 */
KF_INLINE void Bpt_LL_SelectSlaveMode(BPT_RegisterMap_t *const Module, const Bpt_SlaveMode_t Mode)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_SLAVE_MODE(Mode));
    REG_WRITE(Module->BPT_CTL1.bits.SMS, Mode);
}

/**
 * @brief BPT模块选择TRGI触发输入
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Source 触发输入源
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI0
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI1
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI2
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI3
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI4
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI5
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI6
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI7
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI8
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI9
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI10
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI11
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI12
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI13
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI14
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI15
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI16
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI17
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI18
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI19
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI20
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI21
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI22
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI23
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI24
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI25
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI26
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI27
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI28
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI29
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI30
 *                BPT_TRIGGER_INPUT_SOURCE_TRGI31
 * @retval void
 */
KF_INLINE void Bpt_LL_SelectTriggerInputSource(BPT_RegisterMap_t *const Module, const Bpt_TriggerInputSource_t Source)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_TRIGGER_INPUT_SOURCE(Source));
    REG_WRITE(Module->BPT_CTL1.bits.TRGIS, Source);
}

/**
 * @brief BPT模块选择TRGO触发输出
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Source 触发输出选择
 *                BPT_TRIGGER_OUTPUT_SOURCE_DISABLED 禁止 TRGO 输出
 *                BPT_TRIGGER_OUTPUT_SOURCE_EN TRGO 输出源选择 EN 信号
 *                BPT_TRIGGER_OUTPUT_SOURCE_OVERFLOW TRGO 输出源选择溢出信号
 *                BPT_TRIGGER_OUTPUT_SOURCE_UPDATE TRGO 输出源选择更新信号
 * @retval void
 */
KF_INLINE void Bpt_LL_SelectTriggerOutputSource(BPT_RegisterMap_t *const Module, const Bpt_TriggerOutputSource_t Source)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_TRIGGER_OUTPUT_SOURCE(Source));
    REG_WRITE(Module->BPT_CTL1.bits.TRGOS, Source);
}

/*  BPT_CTL2_T */

/**
 * @brief BPT模块使能/禁止更新
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Status bool
 *                false 禁止以 BPT 为时基的占空比、周期、输出控制、预分频、周期计数寄存器更新
 *                true 允许以 BPT 为时基的占空比、周期、输出控制、预分频、周期计数寄存器更新
 * @retval void
 */
KF_INLINE void Bpt_LL_SetTimerUpdateEnabled(BPT_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_CTL2.bits.TXUDEN, Status);
}

/**
 * @brief BPT模块设置更新模式
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Mode 更新模式
 *                BPT_TIMER_UPDATE_PERIODIC 周期更新，当定时器 BPT 为 0（向上计数时）或为 PP 值（向下计数）时
 *                                                                  且 BPT_UDTIMX 计数到设定值时更新以 BPT
 * 为时基的占空比、周期、输出控制、 预分频、周期计数寄存器到缓冲器中 BPT_TIMER_UPDATE_NOW 立刻更新，产生更新事件，更新以
 * BPT 为时基的占空比、周期、输出控制、预分频、 周期计数寄存器到缓冲器中，并将定时器复位
 * @retval void
 */
KF_INLINE void Bpt_LL_SetTimerUpdateEventMode(BPT_RegisterMap_t *const Module, Bpt_TimerUpdateMode_t Mode)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_TIMER_UPDATE_MODE(Module));
    REG_WRITE(Module->BPT_CTL2.bits.TXUDEVT, Mode);
}

/**
 * @brief BPT模块立即产生更新事件
 * @details 初始化定时器 BPT 的计数器并更新周期、占空比、预分频器、输出控制寄存器
 *
 * @param Module 指向BPT内存结构的指针
 * @retval void
 */
KF_INLINE void Bpt_LL_SetTimerUpdateImmediately(BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_CTL2.bits.TXUR, 1U);
}

/*  BPT_CNT_T */

/**
 * @brief BPT模块配置定时器值
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Value 设置的值 0~0xFFFFFFFF
 * @retval void
 */
KF_INLINE void Bpt_LL_SetCounter(BPT_RegisterMap_t *const Module, const uint32_t Value)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_CNT.reg, Value);
}

/**
 * @brief BPT模块配置预分频
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Prescale 预分频值 0~0xFFFFFFFF
 * @retval void
 */
KF_INLINE void Bpt_LL_SetPrescale(BPT_RegisterMap_t *const Module, const uint32_t Prescale)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_PRSC.reg, Prescale);
}

/**
 * @brief BPT模块配置周期
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Prescale 周期值 0~0xFFFFFFFF
 * @retval void
 */
KF_INLINE void Bpt_LL_SetPeriod(BPT_RegisterMap_t *const Module, const uint32_t Period)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_PPX.reg, Period);
}

/**
 * @brief BPT模块获取周期
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @retval 周期寄存器值
 */
KF_INLINE uint32_t Bpt_LL_GetPeriod(const BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    return (REG_READ(Module->BPT_PPX.reg));
}

/**
 * @brief BPT模块获取计数值
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @retval 计数器值
 */
KF_INLINE uint32_t Bpt_LL_GetCounter(const BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    return (REG_READ(Module->BPT_CNT.reg));
}

/**
 * @brief BPT模块设置更新计数器
 * @details 当使能更新功能时，若 BPT_CTL2 寄存器中的TXUDEN=1 ， TXUDEVT=0 ， 则只有在BPT_UDTIM 的值向下计数到 0
 * 时才会更新 BPT为时基的预分频器、周期、占空比、输出控制、输出配置寄存器
 * @param Module 指向BPT内存结构的指针
 * @param Counter 更新计数值
 * @retval void
 */
KF_INLINE void Bpt_LL_SetUpdateCounter(BPT_RegisterMap_t *const Module, const uint8_t Counter)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    REG_WRITE(Module->BPT_UDTIM.bits.UDCNT, Counter);
}

/**
 * @brief BPT模块获取当前计数方向
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @retval Bpt_CountingDirection_t
 *              BPT_COUNTING_DIRECTION_UP 向上计数
 *              BPT_COUNTING_DIRECTION_DOWN 向下计数
 */
KF_INLINE Bpt_CountingDirection_t Bpt_LL_GetCurrentCountingDirection(const BPT_RegisterMap_t *const Module)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    return (Bpt_CountingDirection_t)(REG_READ(Module->BPT_STA.bits.DIR));
}

/**
 * @brief BPT模块获取中断标志
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Index 中断标志索引
 *                BPT_INTERRUPT_FLAG_OVERFLOW 溢出中断
 *                BPT_INTERRUPT_FLAG_TRIGGER_EVENT 触发事件中断
 *                BPT_INTERRUPT_FLAG_UPDATE_EVENT 更新事件中断
 * @retval bool
 *              false 相应事件未发生
 *              true 相应事件发生
 */
KF_INLINE bool Bpt_LL_GetIntrFlag(const BPT_RegisterMap_t *const Module, const Bpt_InterruptFlagIndex_t Index)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_INTERRUPT_FLAG_INDEX(Index));
    return (bool)(REG_BITS_READ(Module->BPT_IF.reg, (1U << (uint32_t)Index), ((uint32_t)Index)));
}

/**
 * @brief BPT模块设置中断使能/禁止
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Index 中断标志索引
 *                BPT_INTERRUPT_FLAG_OVERFLOW 溢出中断
 *                BPT_INTERRUPT_FLAG_TRIGGER_EVENT 触发事件中断
 *                BPT_INTERRUPT_FLAG_UPDATE_EVENT 更新事件中断
 * @param Status
 *               false 禁止相应事件中断
 *               true 使能相应事件中断
 * @retval void
 */
KF_INLINE void
Bpt_LL_SetIntrEnabled(BPT_RegisterMap_t *const Module, const Bpt_InterruptFlagIndex_t Index, const bool Status)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_INTERRUPT_FLAG_INDEX(Index));
    REG_BITS_WRITE(Module->BPT_IE.reg, (1U << (uint32_t)Index), ((uint32_t)Status << (uint32_t)Index));
}

/**
 * @brief BPT模块清除中断标志
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Index 中断标志索引
 *                BPT_INTERRUPT_FLAG_OVERFLOW 溢出中断
 *                BPT_INTERRUPT_FLAG_TRIGGER_EVENT 触发事件中断
 *                BPT_INTERRUPT_FLAG_UPDATE_EVENT 更新事件中断
 * @retval void
 */
KF_INLINE void Bpt_LL_ClearIntrFlag(BPT_RegisterMap_t *const Module, const Bpt_InterruptFlagIndex_t Index)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_INTERRUPT_FLAG_INDEX(Index));
    REG_BIT_SET(Module->BPT_IC.reg, (1U << (uint32_t)Index));
}

/**
 * @brief BPT模块软件置1事件中断标志
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @param Index 中断标志索引
 *                BPT_INTERRUPT_FLAG_OVERFLOW 溢出中断
 *                BPT_INTERRUPT_FLAG_TRIGGER_EVENT 触发事件中断
 *                BPT_INTERRUPT_FLAG_UPDATE_EVENT 更新事件中断
 * @retval void
 */
KF_INLINE void Bpt_LL_SetIntrFlag(BPT_RegisterMap_t *const Module, const Bpt_InterruptFlagIndex_t Index)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_ALL_PERIPH(Module));
    KF_DRV_BPT_ASSERT(CHECK_BPT_INTERRUPT_FLAG_INDEX(Index));
    REG_BIT_SET(Module->BPT_IS.reg, (1U << (uint32_t)Index));
}

/**
 * @brief 使能Bpt测试模式
 *
 *
 * @param Module 指向BPT内存结构的指针
 * @retval void
 */
KF_INLINE void Bpt_LL_EnableTestMode(BPT_RegisterMap_t *const Module)
{
    REG_WRITE(Module->BPT_TM.bits.TMEN, true);
}

/**
 * @brief 选择Bpt测试模式输出
 *
 * @param Module 指向BPT内存结构的指针
 * @param Output 测试模式输出
 * @retval void
 */
KF_INLINE void Bpt_LL_SetTestModeOutput(BPT_RegisterMap_t *const Module, const Bpt_TestModeOutput_t Output)
{
    KF_DRV_BPT_ASSERT(CHECK_BPT_TEST_MODE_OUTPUT(Output));

    REG_WRITE(Module->BPT_TM.bits.TMSEL, Output);
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
