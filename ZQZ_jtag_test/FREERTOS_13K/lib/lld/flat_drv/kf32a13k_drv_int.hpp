/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_int.h
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
 *  |2023-12-25  |V1.0     |Zhang Quanzhen  | New Creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_INT_H_
#define KF32A13K_DRV_INT_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_int.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_INT_ASSERT
#include "dev_assert.h"
#define KF_DRV_INT_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_INT_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION

#include "kf32a13k_reg_simulation_int.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    INT_CPU0,
    INT_CPU1
} Int_CpuSourceType_t;

#define CHECK_INT_CPUSOURCE(CPUSOURCE) ((CPUSOURCE == INT_CPU0) || (CPUSOURCE == INT_CPU1))

typedef enum
{
    INT_SOURCECPU0,
    INT_SOURCECPU1,
    INT_SOURCEDMA,
} Int_SourceType_t;

#define CHECK_INT_SOURCE(SOURCE) ((SOURCE == INT_SOURCECPU0) || (SOURCE == INT_SOURCECPU1) || (SOURCE == INT_SOURCEDMA))

typedef enum
{
    MONITOR_CPU0,
    MONITOR_DMA,
    MONITOR_CPU1,
    MONITOR_CPU2
} Int_MonitorType_t;

#define CHECK_INT_MONITOR(SOURCE) ((SOURCE >> POS_2_SHIFT) == 0U)

typedef enum
{
    INT_ACCESS_ENABLE_0,
    INT_ACCESS_ENABLE_1,
    INT_ACCESS_ENABLE_2,
    INT_ACCESS_ENABLE_3,
    INT_ACCESS_ENABLE_4,
    INT_ACCESS_ENABLE_5,
    INT_ACCESS_ENABLE_6,
    INT_ACCESS_ENABLE_7,
    INT_ACCESS_ENABLE_8,
    INT_ACCESS_ENABLE_9,
    INT_ACCESS_ENABLE_10,
    INT_ACCESS_ENABLE_11,
    INT_ACCESS_ENABLE_12,
    INT_ACCESS_ENABLE_13,
    INT_ACCESS_ENABLE_14,
    INT_ACCESS_ENABLE_15,
    INT_ACCESS_ENABLE_16,
    INT_ACCESS_ENABLE_17,
    INT_ACCESS_ENABLE_18,
    INT_ACCESS_ENABLE_19,
    INT_ACCESS_ENABLE_20,
    INT_ACCESS_ENABLE_21,
    INT_ACCESS_ENABLE_22,
    INT_ACCESS_ENABLE_23,
    INT_ACCESS_ENABLE_24,
    INT_ACCESS_ENABLE_25,
    INT_ACCESS_ENABLE_26,
    INT_ACCESS_ENABLE_27,
    INT_ACCESS_ENABLE_28,
    INT_ACCESS_ENABLE_29,
    INT_ACCESS_ENABLE_30,
    INT_ACCESS_ENABLE_31
} Int_AccessEnableType_t;

#define CHECK_INT_ACCESSENABLE(Enable) ((Enable >> POS_5_SHIFT) == 0U)

typedef enum
{
    INT_OTGB0,
    INT_OTGB1
} Int_OTGBType_t;

#define CHECK_INT_OTGB(OTGB) ((OTGB == INT_OTGB0) || (OTGB = INT_OTGB1))

typedef enum
{
    INT_OTGB0_BIT7_0,
    INT_OTGB0_BIT15_8,
    INT_OTGB1_BIT7_0,
    INT_OTGB1_BIT15_8
} Int_OTGBCoverType_t;

#define CHECK_INT_OTGBCOVER(OTGBCOVER) ((OTGBCOVER >> POS_2_SHIFT) == 0U)

typedef enum
{
    INT_COVERTRIGGER_NONE,
    INT_COVERTRIGGER_TS8_IS,
    INT_COVERTRIGGER_TS8_SPA
} Int_OTGBCoverTriggerType_t;

#define CHECK_INT_OTGBCOVERTRIGGER(OTGBCOVERTRIGGER)                                                                   \
    ((OTGBCOVERTRIGGER == INT_COVERTRIGGER_NONE) || (OTGBCOVERTRIGGER == INT_COVERTRIGGER_TS8_IS) ||                   \
     (OTGBCOVERTRIGGER == INT_COVERTRIGGER_TS8_SPA))

typedef enum
{
    INT_IRQ0,
    INT_IRQ1,
    INT_IRQ2,
    INT_IRQ3
} Int_TriggerType_t;

#define CHECK_INT_TRIGGER(TRIGGER) ((TRIGGER >> POS_2_SHIFT) == 0U)

typedef enum
{
    INT_TRIG0,
    INT_TRIG1,
    INT_TRIG2,
    INT_TRIG3,
    INT_TRIG4,
    INT_TRIG5,
    INT_TRIG6,
    INT_TRIG7,
} Int_BoardcastTriggerType_t;

#define CHECK_INT_BOARDCASTTRIGGER(BOARDCASTTRIGGER) ((BOARDCASTTRIGGER >> POS_3_SHIFT) == 0U)

typedef enum
{
    INT_SERIAL_MODE = 0x5A5A5A5A,
    INT_CONTINUOUS_MODE
} Int_ModeType_t;

#define CHECK_INT_BOOL(Bool) ((Bool >> POS_1_SHIFT) == 0U)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/
// TODO：需要获取到最新的中断向量表
/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief 进入临界区并返回当前当前中断状态
 *
 * @param void
 * @retval uint32_t 中断状态
 */
KF_INLINE uint32_t Intr_LL_EnterCritical(void)
{
    uint32_t r = false;
    // uint32_t r = INTR_RM.CTRL0.bits.AIE;
    // TODO:全局中断时钟位
    DISABLE_INTERRUPT();
    return r;
}

/**
 * @brief 根据中断状态是否使能中断
 *
 * @param[in] v 中断状态位
 * @retval none
 */
KF_INLINE void Intr_LL_ExitCritical(uint32_t v)
{
    if (v > 0U)
    {
        ENABLE_INTERRUPT();
    }
    else
    {
        NOP();
    }
}
/**
 * @brief 获取INT模块版本信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetModuleVersion(void)
{
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(INT_PTR->INT_ID.bits.MODREV));
#endif
}

/**
 * @brief 获取INT模块类型信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetModuleType(void)
{
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(INT_PTR->INT_ID.bits.MODTYPE));
#endif
}

/**
 * @brief 获取INT模块ID信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetModuleId(void)
{
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(INT_PTR->INT_ID.bits.MODNUM));
#endif
}

/**
 * @brief 使能INT访问控制
 *
 *
 * @ param AccessEnable :使能主端TAG IDx的访问
 * @ retval void
 */
KF_INLINE void Int_LL_EnableConfigAccess(Int_AccessEnableType_t AccessEnable)
{
    // TODO:需要确定X的具体含义
    KF_DRV_INT_ASSERT(CHECK_INT_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
// TODO:
#else
    REG_BIT_SET(INT_PTR->INT_CFG0.reg, MASK_1_BIT << AccessEnable);
#endif
}

/**
 * @brief 获取INT访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 *          true:主端TAG IDx的访问有写权限
 *          false:主端TAG IDx的访问无写权限
 */
KF_INLINE bool Int_LL_GetConfigAccess(Int_AccessEnableType_t AccessEnable)
{
    // TODO:需要确定X的具体含义
    KF_DRV_INT_ASSERT(CHECK_INT_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_INT_CFG0_ADDR, MASK_1_BIT << AccessEnable, AccessEnable));
    // TODO: check if correct

#else
    return (REG_BITS_READ(INT_PTR->INT_CFG0.reg, MASK_1_BIT << AccessEnable, AccessEnable));
#endif
}

/**
 * @brief 使能INT访问控制
 *
 *
 * @ param Int_CpuSourceType_t
 *         INT_CPU0
 *          INT_CPU1
 * @ param AccessEnable :使能主端TAG IDx的访问
 * @ retval void
 */
KF_INLINE void Int_LL_EnableSRBAccess(const Int_CpuSourceType_t CpuSource, const Int_AccessEnableType_t AccessEnable)
{
    // TODO:需要确定X的具体含义
    KF_DRV_INT_ASSERT(CHECK_INT_CPUSOURCE(CpuSource));
    KF_DRV_INT_ASSERT(CHECK_INT_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
// TODO:
#else
    REG_BIT_SET(INT_PTR->INT_ACES_SRB0[CpuSource].reg, MASK_1_BIT << AccessEnable);
#endif
}

/**
 * @brief 获取INT访问状态
 *
 *
 * @ param Int_CpuSourceType_t
 *         INT_CPU0
 *          INT_CPU1
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 *          true:主端TAG IDx的访问有写权限
 *          false:主端TAG IDx的访问无写权限
 */
KF_INLINE bool Int_LL_GetSRBAccess(const Int_CpuSourceType_t CpuSource, const Int_AccessEnableType_t AccessEnable)
{
    // TODO:需要确定X的具体含义
    KF_DRV_INT_ASSERT(CHECK_INT_CPUSOURCE(CpuSource));
    KF_DRV_INT_ASSERT(CHECK_INT_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_BITS_READ(INT_PTR->INT_ACES_SRB0[CpuSource].reg, MASK_1_BIT << AccessEnable, AccessEnable));
#endif
}

/**
 * @brief 使能INT访问控制
 *
 *
 * @ param AccessEnable :使能主端TAG IDx的访问
 * @ retval void
 */
KF_INLINE void Int_LL_EnableTOSAccess(const Int_SourceType_t IntSource, const Int_AccessEnableType_t AccessEnable)
{
    // TODO:需要确定X的具体含义
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(IntSource));
    KF_DRV_INT_ASSERT(CHECK_INT_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
// TODO:
#else
    REG_BIT_SET(INT_PTR->INT_ACES_TOS0[IntSource].reg, MASK_1_BIT << AccessEnable);
#endif
}

/**
 * @brief 获取INT访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 *          true:主端TAG IDx的访问有写权限
 *          false:主端TAG IDx的访问无写权限
 */
KF_INLINE bool Int_LL_GetTOSAccess(const Int_SourceType_t IntSource, const Int_AccessEnableType_t AccessEnable)
{
    // TODO:需要确定X的具体含义
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(IntSource));
    KF_DRV_INT_ASSERT(CHECK_INT_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_BITS_READ(INT_PTR->INT_ACES_TOS0[IntSource].reg, MASK_1_BIT << AccessEnable, AccessEnable));
#endif
}

/**
 * @brief 获取INT OTBG状态
 *
 *
 * @ param Int_OTGBType_t
 *         INT_OTGB0
 *         INT_OTGB1
 * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetOTBGState(const Int_OTGBType_t OTGB)
{
    KF_DRV_INT_ASSERT(CHECK_INT_OTGB(OTGB));
#ifdef SIMULATION
// TODO: Error: cannot findOOBS the correct register name please correct
#else
    return (REG_BITS_READ(INT_PTR->OOBS.bits.OTGB0, MASK_16_BIT << (OTGB * POS_16_SHIFT), OTGB * POS_16_SHIFT));
#endif
}

/**
 * @brief 使能INT OTGB输出触发
 *
 *
 * @ param bool
 *         true:TS16_SSI触发
 *         false:无触发设置输出
 * @ retval void
 */
KF_INLINE void Int_LL_EnableOTBGOutput(const bool Status)
{
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
// TODO: Error: cannot findOSSIC the correct register name please correct
#else
    REG_WRITE(INT_PTR->OSSIC.bits.TGS, Status);
#endif
}

/**
 * @brief 设置INT OTGB总线选择
 *
 *
 * @ param Int_OTGBType_t
 *         INT_OTGB0:由OTGB0输出触发设置
 *         INT_OTGB1:由OTGB1输出触发设置
 * @ retval void
 */
KF_INLINE void Int_LL_SetOTBGOutput(const Int_OTGBType_t OTGB)
{
    KF_DRV_INT_ASSERT(CHECK_INT_OTGB(OTGB));
#ifdef SIMULATION
// TODO: Error: cannot findOSSIC the correct register name please correct
#else
    REG_WRITE(INT_PTR->OSSIC.bits.TGB, OTGB);
#endif
}

/**
 * @brief 设置INT OTGB总线选择
 *
 *
 * @ param Int_OTGBType_t
 *         INT_OTGB0:由OTGB0输出触发设置
 *         INT_OTGB1:由OTGB1输出触发设置
 * @ retval void
 */
KF_INLINE void Int_LL_SetOBS(const Int_OTGBType_t OTGB)
{
    KF_DRV_INT_ASSERT(CHECK_INT_OTGB(OTGB));
#ifdef SIMULATION
// TODO: Error: cannot findOSSIC the correct register name please correct
#else
    REG_WRITE(INT_PTR->OSSIC.bits.TGB, OTGB);
#endif
}

/**
 * @brief 设置INT OTGB覆盖触发源
 *
 *
 * @ param Int_OTGBCoverType_t
 *         INT_COVERTRIGGER_NONE
 *         INT_COVERTRIGGER_TS8_IS
 *         INT_COVERTRIGGER_TS8_SPA
 * @ retval void
 */
KF_INLINE void Int_LL_SetOBSCoverTrigger(const Int_OTGBCoverType_t OTGBCoverTrigger)
{
    KF_DRV_INT_ASSERT(CHECK_INT_OTGBCOVERTRIGGER(OTGBCoverTrigger));
#ifdef SIMULATION
// TODO: Error: cannot findOIXTS the correct register name please correct
#else
    REG_WRITE(INT_PTR->OIXTS.bits.TGS, OTGBCoverTrigger);
#endif
}

/**
 * @brief 设置INT OTGB覆盖字节
 *
 *
 * @ param Int_OTGBCoverType_t
 *         INT_OTGB0_BIT7_0
 *         INT_OTGB0_BIT15_8
 *         INT_OTGB1_BIT7_0
 *         INT_OTGB1_BIT15_8
 * @ retval void
 */
KF_INLINE void Int_LL_SetOTBGCover(const Int_OTGBCoverType_t OTGBCover)
{
    KF_DRV_INT_ASSERT(CHECK_INT_OTGBCOVER(OTGBCover));
#ifdef SIMULATION
// TODO: Error: cannot findOIXTS the correct register name please correct
#else
    REG_WRITE(INT_PTR->OIXTS.bits.OBS, OTGBCover);
#endif
}

/**
 * @brief 获取INT 缺少中断触发的SRN索引号
 *
 *
 * @ param Int_TriggerType_t
 *         INT_IRQ0
 *         INT_IRQ1
 *         INT_IRQ2
 *         INT_IRQ3
 * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetMissedIntSRN(Int_TriggerType_t IntTrigger)
{
    KF_DRV_INT_ASSERT(CHECK_INT_TRIGGER(IntTrigger));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_BITS_READ(
      INT_PTR->OIXS[IntTrigger >> POS_1_SHIFT].reg, MASK_10_BIT << ((IntTrigger % POS_2_SHIFT) * POS_16_SHIFT),
      (IntTrigger % POS_2_SHIFT) * POS_16_SHIFT));
#endif
}

/**
 * @brief 设置INT OTGB输出使能
 *
 *
 * @ param Int_OTGBType_t
 *         INT_OTGB0
 *         INT_OTGB1
 * @ param Status
 *         true:使能OTGB输出
 *         false:禁止OTGB输出
 * @ retval void
 */
KF_INLINE void Int_LL_EnableOTGBOutput(Int_OTGBType_t OTGB, const bool Status)
{
    KF_DRV_INT_ASSERT(CHECK_INT_OTGB(OTGB));
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
// TODO: Error: cannot findOIT the correct register name please correct
#else
    REG_BITS_WRITE(INT_PTR->OIT.reg, MASK_1_BIT << (OTGB * POS_8_SHIFT + POS_7_OFFSET),
                   Status << (OTGB * POS_8_SHIFT + POS_7_OFFSET));
#endif
}

/**
 * @brief 设置INT OTGB观测服务类型
 *
 *
 * @ param Int_OTGBType_t
 *         INT_OTGB0
 *         INT_OTGB1
 * @ param Int_MonitorType_t
 *         MONITOR_CPU0
 *         MONITOR_DMA
 *         MONITOR_CPU1
 *         MONITOR_CPU2
 * @ retval void
 */
KF_INLINE void Int_LL_SetOTGBWatch(Int_OTGBType_t OTGB, Int_MonitorType_t WatchType)
{
    KF_DRV_INT_ASSERT(CHECK_INT_OTGB(OTGB));
    KF_DRV_INT_ASSERT(CHECK_INT_MONITOR(WatchType));
#ifdef SIMULATION
// TODO: Error: cannot findOIT the correct register name please correct
#else
    REG_BITS_WRITE(INT_PTR->OIT.reg, MASK_3_BIT << (OTGB * POS_8_SHIFT), WatchType << (OTGB * POS_8_SHIFT));
#endif
}

/**
 * @brief 设置INT OTGB上升沿敏感
 *
 *
 * @ param Int_OTGBType_t
 *         INT_OTGB0
 *         INT_OTGB1
 * @ param uint16_t
 * @ retval void
 */
KF_INLINE void Int_LL_SetOTGBRiseSensitivity(Int_OTGBType_t OTGB, const uint32_t RiseEdgeSensitivity)
{
    KF_DRV_INT_ASSERT(CHECK_INT_OTGB(OTGB));
    KF_DRV_INT_ASSERT((RiseEdgeSensitivity >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
// TODO: Error: cannot findOMISP the correct register name please correct
#else
    REG_BITS_WRITE(
      INT_PTR->OMISP.reg, MASK_16_BIT << (OTGB * POS_16_SHIFT), RiseEdgeSensitivity << (OTGB * POS_16_SHIFT));
#endif
}

/**
 * @brief 设置INT OTGB下降沿敏感
 *
 *
 * @ param Int_OTGBType_t
 *         INT_OTGB0
 *         INT_OTGB1
 * @ param uint16_t
 * @ retval void
 */
KF_INLINE void Int_LL_SetOTGBFallSensitivity(Int_OTGBType_t OTGB, const uint16_t FallEdgeSensitivity)
{
    KF_DRV_INT_ASSERT(CHECK_INT_OTGB(OTGB));
    KF_DRV_INT_ASSERT((FallEdgeSensitivity >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
// TODO: Error: cannot findOMISN the correct register name please correct
#else
    REG_BITS_WRITE(
      INT_PTR->OMISN.reg, MASK_16_BIT << (OTGB * POS_16_SHIFT), FallEdgeSensitivity << (OTGB * POS_16_SHIFT));
#endif
}

/**
 * @brief 设置INT 软件黏连位复位
 *
 *
 * @ param uint32_t:中断索引号
 * @ param Status
 *         true:复位软件黏连位
 *         false:无影响
 * @ retval void
 */
KF_INLINE void Int_LL_ResetSoftWareAdhesion(const Intr_IrqEnumType IntIndex, const bool Status)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2));
    regValue &= ~HWIO_INT_SRC0_INT_SRC0_SWSSTAIC_MASK;
    regValue |= Status << HWIO_INT_SRC0_INT_SRC0_SWSSTAIC_SHFT;
    REG_WRITE(HWIO_INT_SRC0_ADDR + (IntIndex << 2), regValue);
    // TODO: check if correct

#else
    REG_WRITE(INT_PTR->INT_SRC.SRC[IntIndex].bits.SWSSTAIC, Status);
#endif
}

/**
 * @brief 获取INT 软件黏连位状态
 *
 *
 * @ param uint32_t:中断索引号
 * @ retval bool
 *          true:SRIS初始化中断
 *          false:中断未通过SRIS初始化
 */
KF_INLINE bool Int_LL_GetSoftWareAdhesion(const Intr_IrqEnumType IntIndex)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(INT_PTR->INT_SRC.SRC[IntIndex].bits.SWSSTA));
#endif
}

/**
 * @brief 获取INT 触发溢出状态位
 *
 *
 * @ param uint32_t:中断索引号
 * @ retval bool
 *          true:检测到中断溢出
 *          false:未检测到中断触发溢出
 */
KF_INLINE bool Int_LL_GetIntTriggerOverflowState(const Intr_IrqEnumType IntIndex)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
#ifdef SIMULATION
    return ((REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2)) & HWIO_INT_SRC0_INT_SRC0_IOVSTA_MASK) >>
            HWIO_INT_SRC0_INT_SRC0_IOVSTA_SHFT);
// TODO:
#else
    return (REG_READ(INT_PTR->INT_SRC.SRC[IntIndex].bits.IOVSTA));
#endif
}

/**
 * @brief 清除INT 触发溢出状态
 *
 *
 * @ param uint32_t:中断索引号
 * @ param bool
 *          true:清除中断溢出
 *          false:无操作
 * @ retval void
 */
KF_INLINE void Int_LL_ClearIntTriggerOverflowState(const Intr_IrqEnumType IntIndex, const bool Status)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2));
    regValue &= ~HWIO_INT_SRC0_INT_SRC0_IOVSTAIC_MASK;
    regValue |= Status << HWIO_INT_SRC0_INT_SRC0_IOVSTAIC_SHFT;
    REG_WRITE(HWIO_INT_SRC0_ADDR + (IntIndex << 2), regValue);
    // TODO: check if correct

#else
    REG_WRITE(INT_PTR->INT_SRC.SRC[IntIndex].bits.IOVSTAIC, Status);
#endif
}

/**
 * @brief 设置INT 服务请求状态
 *
 *
 * @ param uint32_t:中断索引号
 * @ param bool
 *          true:置位SRIF和SWSSTA
 *          false:无操作
 * @ retval void
 */
KF_INLINE void Int_LL_SetIntRequestState(const Intr_IrqEnumType IntIndex, const bool Status)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2));
    regValue &= ~HWIO_INT_SRC0_INT_SRC0_SRIS_MASK;
    regValue |= Status << HWIO_INT_SRC0_INT_SRC0_SRIS_SHFT;
    REG_WRITE(HWIO_INT_SRC0_ADDR + (IntIndex << 2), regValue);
    // TODO: check if correct

#else
    REG_WRITE(INT_PTR->INT_SRC.SRC[IntIndex].bits.SRIS, Status);
#endif
}

/**
 * @brief 清除INT 服务请求状态
 *
 *
 * @ param uint32_t:中断索引号
 * @ param bool
 *          true:清除SRIF
 *          false:无操作
 * @ retval void
 */
KF_INLINE void Int_LL_ClearIntRequestState(const Intr_IrqEnumType IntIndex, const bool Status)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2));
    regValue &= ~HWIO_INT_SRC0_INT_SRC0_SRIC_MASK;
    regValue |= Status << HWIO_INT_SRC0_INT_SRC0_SRIC_SHFT;
    REG_WRITE(HWIO_INT_SRC0_ADDR + (IntIndex << 2), regValue);
    // TODO: check if correct

#else
    REG_WRITE(INT_PTR->INT_SRC.SRC[IntIndex].bits.SRIC, Status);
#endif
}

/**
 * @brief 获取INT 服务请求状态
 *
 *
 * @ param uint32_t:中断索引号
 * @ retval bool
 *          true:存在服务请求等待处理
 *          false:无服务请求等待处理
 */
KF_INLINE bool Int_LL_GetIntRequestState(const Intr_IrqEnumType IntIndex)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
#ifdef SIMULATION
    return ((REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2)) & HWIO_INT_SRC0_INT_SRC0_SRIF_MASK) >>
            HWIO_INT_SRC0_INT_SRC0_SRIF_SHFT);
// TODO:
#else
    return (REG_READ(INT_PTR->INT_SRC.SRC[IntIndex].bits.SRIF));
#endif
}

/**
 * @brief 获取INT 错误纠正编码
 *
 *
 * @ param uint32_t:中断索引号
 * @ retval uint32_t
 */
KF_INLINE bool Int_LL_GetErrorCorrectionCode(const Intr_IrqEnumType IntIndex)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
#ifdef SIMULATION
// TODO:
#else
    return (REG_READ(INT_PTR->INT_SRC.SRC[IntIndex].bits.EDC));
#endif
}

/**
 * @brief 设置INT 错误纠正编码
 *
 *
 * @ param uint32_t:中断索引号
 * @ param uint32_t:错误纠正编码
 * @ retval void
 */
KF_INLINE void Int_LL_SetErrorCorrectionCode(const Intr_IrqEnumType IntIndex, const uint32_t Code)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
    KF_DRV_INT_ASSERT((Code >> POS_5_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2));
    regValue &= ~HWIO_INT_SRC0_INT_SRC0_EDC_MASK;
    regValue |= Code << HWIO_INT_SRC0_INT_SRC0_EDC_SHFT;
    REG_WRITE(HWIO_INT_SRC0_ADDR + (IntIndex << 2), regValue);
    // TODO: check if correct

#else
    REG_WRITE(INT_PTR->INT_SRC.SRC[IntIndex].bits.EDC, Code);
#endif
}

/**
 * @brief 设置INT 服务控制类型
 *
 *
 * @ param uint32_t:中断索引号
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCEDMA
 *         INT_SOURCECPU1
 *         SERVICE_CPU2
 * @ retval void
 */
KF_INLINE void Int_LL_SetServiceType(const Intr_IrqEnumType IntIndex, const Int_SourceType_t ServiceType)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
    KF_DRV_INT_ASSERT(CHECK_INT_SERVICE(ServiceType));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2));
    regValue &= ~HWIO_INT_SRC0_INT_SRC0_TOS_MASK;
    regValue |= ServiceType << HWIO_INT_SRC0_INT_SRC0_TOS_SHFT;
    REG_WRITE(HWIO_INT_SRC0_ADDR + (IntIndex << 2), regValue);
    // TODO: check if correct

#else
    REG_WRITE(INT_PTR->INT_SRC.SRC[IntIndex].bits.TOS, ServiceType);
#endif
}

/**
 * @brief 设置INT 服务控制类型
 *
 *
 * @ param uint32_t:中断索引号
 * @ retval Int_SourceType_t
 *          INT_SOURCECPU0
 *          INT_SOURCEDMA
 *          INT_SOURCECPU1
 *          SERVICE_CPU2
 */
KF_INLINE Int_SourceType_t Int_LL_GetServiceType(const Intr_IrqEnumType IntIndex)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
    return ((Int_SourceType_t)INT_PTR->INT_SRC.SRC[IntIndex].bits.TOS);
}

/**
 * @brief 设置INT 服务控制类型
 *
 *
 * @ param uint32_t:中断索引号
 * @ retval bool
 *          true:使能服务请求
 *          false:禁用服务请求
 */
KF_INLINE void Int_LL_EnableServiceRequest(const Intr_IrqEnumType IntIndex, const bool Status)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2));
    regValue &= ~HWIO_INT_SRC0_INT_SRC0_SRIE_MASK;
    regValue |= Status << HWIO_INT_SRC0_INT_SRC0_SRIE_SHFT;
    REG_WRITE(HWIO_INT_SRC0_ADDR + (IntIndex << 2), regValue);
    // TODO: check if correct

#else
    REG_WRITE(INT_PTR->INT_SRC.SRC[IntIndex].bits.SRIE, Status);
#endif
}

/**
 * @brief 获取INT 中断请求状态
 *
 *
 * @ param uint32_t:中断索引号
 * @ retval bool
 *          true:使能服务请求
 *          false:禁用服务请求
 */
KF_INLINE bool Int_LL_GetServiceRequest(const Intr_IrqEnumType IntIndex)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
    return (bool)((REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2)) & HWIO_INT_SRC0_INT_SRC0_SRIE_MASK) >>
                  HWIO_INT_SRC0_INT_SRC0_SRIE_SHFT);
// TODO:
#else
    return (REG_READ(INT_PTR->INT_SRC.SRC[IntIndex].bits.SRIE));
#endif
}

/**
 * @brief 设置INT 服务请求优先级序号
 *
 *
 * @ param uint32_t:中断索引号
 * @ param uint32_t:中断优先级
 * @ retval void
 */
KF_INLINE void Int_LL_SetServiceRequestPriority(const Intr_IrqEnumType IntIndex, const uint32_t IntPriority)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
    KF_DRV_INT_ASSERT((IntPriority >> POS_9_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2));
    regValue &= ~HWIO_INT_SRC0_INT_SRC0_SRPN_MASK;
    regValue |= IntPriority << HWIO_INT_SRC0_INT_SRC0_SRPN_SHFT;
    REG_WRITE(HWIO_INT_SRC0_ADDR + (IntIndex << 2), regValue);
    // TODO: check if correct

#else
    REG_WRITE(INT_PTR->INT_SRC.SRC[IntIndex].bits.SRPN, IntPriority);
#endif
}

/**
 * @brief 获取INT 服务请求优先级序号
 *
 *
 * @ param uint32_t:中断索引号
 * @ retval uint32_t:中断优先级
 */
KF_INLINE uint32_t Int_LL_GetServiceRequestPriority(const Intr_IrqEnumType IntIndex)
{
    KF_DRV_INT_ASSERT((IntIndex >> POS_9_SHIFT) == 0U);
#ifdef SIMULATION
    return ((REG_READ(HWIO_INT_SRC0_ADDR + (IntIndex << 2)) & HWIO_INT_SRC0_INT_SRC0_SRPN_MASK) >>
            HWIO_INT_SRC0_INT_SRC0_SRPN_SHFT);
// TODO:
#else
    return (REG_READ(INT_PTR->INT_SRC.SRC[IntIndex].bits.SRPN));
#endif
}

/**
 * @brief 获取INT LWSR寄存器状态
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval bool
 *            true:LWSR相关位域有效
 *            false:LWSR相关位域无效
 */
KF_INLINE bool Int_LL_GetLWSRState(const Int_SourceType_t Source)
{
    // TODO:需要核对中断提供节点是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_LWSR[Source].bits.STAT));
#endif
}

/**
 * @brief 获取INT 最新的仲裁胜出索引号
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetLatestArbitrateWinID(const Int_SourceType_t Source)
{
    // TODO:需要核对中断提供节点是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_LWSR[Source].bits.ID));
#endif
}

/**
 * @brief 获取INT 最新的仲裁胜出中断请求节点的错误纠正编码
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetLatestArbitrateWinSRNEDC(const Int_SourceType_t Source)
{
    // TODO:需要核对中断提供节点是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_LWSR[Source].bits.EDC));
#endif
}

/**
 * @brief 获取INT 最新的仲裁胜出中断请求节点的优先级编号
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetLatestArbitrateWinSRNPriority(const Int_SourceType_t Source)
{
    // TODO:需要核对中断提供节点是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_LWSR[Source].bits.PN));
#endif
}
/**
 * @brief 获取INT 上一个确认过的中断请求节点索引号
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetLatestAckWinID(const Int_SourceType_t Source)
{
    // TODO:需要核对中断提供节点是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_LASR[Source].bits.ID));
#endif
}

/**
 * @brief 获取INT 上一个确认过的中断请求节点的错误纠正编码
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetLatstAckWinSRNEDC(const Int_SourceType_t Source)
{
    // TODO:需要核对中断提供节点是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_LASR[Source].bits.EDC));
#endif
}

/**
 * @brief 获取INT 上一个确认过的中断请求节点的优先级序号
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetLatestAckWinSRNPriority(const Int_SourceType_t Source)
{
    // TODO:需要核对中断提供节点是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_LASR[Source].bits.PN));
#endif
}

/**
 * @brief 获取INT EDC错误状态
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval bool
 *            true:检测到EDC错误
 *            false:未检测到EDC错误
 */
KF_INLINE bool Int_LL_GetEDCErrorState(const Int_SourceType_t Source)
{
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_ECR[Source].bits.ESTA));
#endif
}

/**
 * @brief 清除INT EDC错误状态
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * @ param bool
 *         true:清除EDC错误状态
 *         false:无操作
 * * @ retval void
 */
KF_INLINE void Int_LL_ClearEDCErrorState(const Int_SourceType_t Source, const bool Status)
{
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(INT_PTR->INT_ECR[Source].bits.EIC, Status);
#endif
}

/**
 * @brief 获取INT 错误溢出状态
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval bool
 *            true:检测到溢出错误
 *            false:未检测到溢出错误
 */
KF_INLINE bool Int_LL_GetOVErrorState(const Int_SourceType_t Source)
{
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_ECR[Source].bits.EOVSTA));
#endif
}

/**
 * @brief 清除INT 错误溢出状态
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * @ param bool
 *         true:清除错误溢出状态
 *         false:无操作
 * * @ retval void
 */
KF_INLINE void Int_LL_ClearOVErrorState(const Int_SourceType_t Source, const bool Status)
{
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(INT_PTR->INT_ECR[Source].bits.EOVIC, Status);
#endif
}

/**
 * @brief 获取INT 上一个检测到错误的中断请求节点索引号
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetPreviousErrorID(const Int_SourceType_t Source)
{
    // TODO:需要核对中断提供节点是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_ECR[Source].bits.ID));
#endif
}

/**
 * @brief 获取INT 上一个检测到错误中断请求节点的错误纠正代码
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetPreviousErrorEDC(const Int_SourceType_t Source)
{
    // TODO:需要核对中断提供节点是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_ECR[Source].bits.EDC));
#endif
}

/**
 * @brief 获取INT 上一个检测到错误中断请求节点的优先级序号
 *
 *
 * @ param Int_SourceType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetPreviousErrorPriority(const Int_SourceType_t Source)
{
    // TODO:需要核对中断提供节点是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_SOURCE(Source));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_ECR[Source].bits.PN));
#endif
}

/**
 * @brief 使能INT 通用服务请求触发
 *
 *
 * @ param Int_CpuSourceType_t
 *         INT_CPU0
 *         INT_CPU1
 * @ param Int_BoardcastTriggerType_t
 *         INT_TRIG0
 *         INT_TRIG1
 * @ param bool
 *         true:触发对应的服务请求
 *         false:无操作
 * @ retval void
 */
KF_INLINE void Int_LL_EnableBoardcastTrigger(
  const Int_CpuSourceType_t Cpu, const Int_BoardcastTriggerType_t Trigger, const bool Status)
{
    // TODO:需要核对索引值是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_CPUSOURCE(Cpu));
    KF_DRV_INT_ASSERT(CHECK_INT_BOARDCASTTRIGGER(Trigger));
    KF_DRV_INT_ASSERT(CHECK_INT_BOOL(Status));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_BITS_WRITE(INT_PTR->INT_SRB[Cpu].reg, MASK_1_BIT << Trigger, Status << Trigger);
#endif
}

/**
 * @brief 设置INT 监控中断源
 *
 *
 * @ param Int_MonitorType_t
 *         MONITOR_CPU0
 *         MONITOR_DMA
 *         MONITOR_CPU1
 *         MONITOR_CPU2
 * @ param uint32_t:监控中断源编号
 * @ retval void
 */
KF_INLINE void Int_LL_SetMonitorID(const Int_MonitorType_t Monitor, const uint32_t IntID)
{
    // TODO此处寄存器描述和数据手册描述不符
    KF_DRV_INT_ASSERT(CHECK_INT_MONITOR(Monitor));
    KF_DRV_INT_ASSERT((IntID >> POS_10_SHIFT) == 0U);
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(INT_PTR->INT_TIMSEL[Monitor].bits.ID, IntID);
#endif
}

/**
 * @brief 获取INT 监控中断源
 *
 *
 * @ param Int_MonitorType_t
 *         MONITOR_CPU0
 *         MONITOR_DMA
 *         MONITOR_CPU1
 *         MONITOR_CPU2
 * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetMonitorID(const Int_MonitorType_t Monitor)
{
    // TODO此处寄存器描述和数据手册描述不符
    KF_DRV_INT_ASSERT(CHECK_INT_MONITOR(Monitor));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_TIMSEL[Monitor].bits.ID));
#endif
}

/**
 * @brief 设置INT 监控超时时间
 *
 *
 * @ param Int_MonitorType_t
 *         MONITOR_CPU0
 *         MONITOR_DMA
 *         MONITOR_CPU1
 *         MONITOR_CPU2
 * @ param uint32_t:监控中断超时时间
 * @ retval void
 */
KF_INLINE void Int_LL_SetMonitorTimeout(const Int_MonitorType_t Monitor, const uint32_t Timeout)
{
    // TODO此处寄存器描述和数据手册描述不符
    KF_DRV_INT_ASSERT(CHECK_INT_MONITOR(Monitor));
    KF_DRV_INT_ASSERT((Timeout >> POS_24_SHIFT) == 0U);
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(INT_PTR->INT_TIMOUT[Monitor].bits.TIME, Timeout);
#endif
}

/**
 * @brief 获取INT 监控超时时间
 *
 *
 * @ param Int_MonitorType_t
 *         MONITOR_CPU0
 *         MONITOR_DMA
 *         MONITOR_CPU1
 *         MONITOR_CPU2
 * @ retval uint32_t
 */
KF_INLINE uint32_t Int_LL_GetMonitorTimeout(const Int_MonitorType_t Monitor)
{
    // TODO此处寄存器描述和数据手册描述不符
    KF_DRV_INT_ASSERT(CHECK_INT_MONITOR(Monitor));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    return (REG_READ(INT_PTR->INT_TIMOUT[Monitor].bits.TIME));
#endif
}

/**
 * @brief 设置INT 中断模式
 *
 *
 * @ param Int_MonitorType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * @ param Int_ModeType_t
 *         INT_SERIAL_MODE
 *         INT_CONTINUOUS_MODE
 * @ retval void
 */
KF_INLINE void Int_LL_SetMode(const Int_SourceType_t IntSource, const Int_ModeType_t Mode)
{
    // TODO:需要核对索引值是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_MONITOR(IntSource));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(INT_PTR->INT_MODE[IntSource].bits.MODE, Mode);
#endif
}

/**
 * @brief 获取INT 中断模式
 *
 *
 * @ param Int_MonitorType_t
 *         INT_SOURCECPU0
 *         INT_SOURCECPU1
 *         INT_SOURCEDMA
 * @ retval Int_ModeType_t
 *          INT_SERIAL_MODE
 *          INT_CONTINUOUS_MODE
 */
KF_INLINE Int_ModeType_t Int_LL_GetMode(const Int_SourceType_t IntSource, const Int_ModeType_t Mode)
{
    // TODO:需要核对索引值是否正确
    KF_DRV_INT_ASSERT(CHECK_INT_MONITOR(IntSource));
    return ((INT_PTR->INT_MODE[IntSource].bits.MODE != INT_SERIAL_MODE) ? INT_CONTINUOUS_MODE : INT_SERIAL_MODE);
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
