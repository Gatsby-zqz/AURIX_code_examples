/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_msc.h
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
 *  |2023-12-22  |V1.0     |Zhang Quanzhen  | New Creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_MSC_H_
#define KF32A13K_DRV_MSC_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_msc.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_MSC_ASSERT
#include "dev_assert.h"
#define KF_DRV_MSC_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_MSC_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION

#include "kf32a13k_reg_simulation_msc.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    MSC_NOSUSPEND,
    MSC_HARDSUSPEND,
    MSC_SOFTSUSPEND
} Msc_SuspendMode_t;

#define CHECK_MSC_SUSPENDMODE(Mode) ((Mode == MSC_NOSUSPEND) || (Mode == MSC_HARDSUSPEND) || (Mode == MSC_SOFTSUSPEND))

typedef enum
{
    MSC_ACCESS_ENABLE_0,
    MSC_ACCESS_ENABLE_1,
    MSC_ACCESS_ENABLE_2,
    MSC_ACCESS_ENABLE_3,
    MSC_ACCESS_ENABLE_4,
    MSC_ACCESS_ENABLE_5,
    MSC_ACCESS_ENABLE_6,
    MSC_ACCESS_ENABLE_7,
    MSC_ACCESS_ENABLE_8,
    MSC_ACCESS_ENABLE_9,
    MSC_ACCESS_ENABLE_10,
    MSC_ACCESS_ENABLE_11,
    MSC_ACCESS_ENABLE_12,
    MSC_ACCESS_ENABLE_13,
    MSC_ACCESS_ENABLE_14,
    MSC_ACCESS_ENABLE_15,
    MSC_ACCESS_ENABLE_16,
    MSC_ACCESS_ENABLE_17,
    MSC_ACCESS_ENABLE_18,
    MSC_ACCESS_ENABLE_19,
    MSC_ACCESS_ENABLE_20,
    MSC_ACCESS_ENABLE_21,
    MSC_ACCESS_ENABLE_22,
    MSC_ACCESS_ENABLE_23,
    MSC_ACCESS_ENABLE_24,
    MSC_ACCESS_ENABLE_25,
    MSC_ACCESS_ENABLE_26,
    MSC_ACCESS_ENABLE_27,
    MSC_ACCESS_ENABLE_28,
    MSC_ACCESS_ENABLE_29,
    MSC_ACCESS_ENABLE_30,
    MSC_ACCESS_ENABLE_31
} Msc_AccessEnableType_t;

#define CHECK_MSC_ACCESSENABLE(Enable) ((Enable >> POS_5_SHIFT) == 0U)

typedef enum
{
    FRACTIONDIVIDE_MODE,
    INTEGERDIVIDE_MODE
} Msc_DivideModeType_t;

#define CHECK_MSC_DIVIDEMODE(Mode) ((Mode == FRACTIONDIVIDE_MODE) || (Mode == INTEGERDIVIDE_MODE))

typedef enum
{
    UP_BIT_12,
    UP_BIT_16
} Msc_UpFrameMode_t;

#define CHECK_MSC_UPFRAMEMODE(Mode) ((Mode == UP_BIT_12) || (Mode == UP_BIT_16))

typedef enum
{
    UPCLOCK_PROHIBIT,
    UPCLOCK_DIVIDE_4,
    UPCLOCK_DIVIDE_8,
    UPCLOCK_DIVIDE_16,
    UPCLOCK_DIVIDE_32,
    UPCLOCK_DIVIDE_64,
    UPCLOCK_DIVIDE_128,
    UPCLOCK_DIVIDE_256
} Msc_UpClockDivideType_t;

#define CHECK_MSC_UPCLOCKDIVIDE(UpClockDivide) ((UpClockDivide >> POS_4_SHIFT) == 0U)

typedef enum
{
    MSC_EVEN_CHECK,
    MSC_ODD_CHECK
} Msc_ParityCheckModeType_t;

#define CHECK_MSC_PARITYCHECKMODE(Mode) ((Mode == MSC_EVEN_CHECK) || (Mode == MSC_ODD_CHECK))

typedef enum
{
    TRIGGER_MODE,
    REPEAT_MODE
} Msc_DownTransferModeType_t;

#define CHECK_MSC_DOWNTRANSFERMODE(Mode) ((Mode == TRIGGER_MODE) || (Mode == REPEAT_MODE))

typedef enum
{
    REG_DATA            = 0U,
    ALINXH_DATA         = 2U,
    REVERSE_ALINXH_DATA = 3U
} Msc_DataBitSourceType_t;

#define CHECK_MSC_DATABITSOURCE(Source)                                                                                \
    ((Source == REG_DATA) || (Source == ALINXH_DATA) || (Source == REVERSE_ALINXH_DATA))

typedef enum
{
    UP_CHANNEL_0,
    UP_CHANNEL_1,
    UP_CHANNEL_2,
    UP_CHANNEL_3
} Msc_UpChannelType_t;

#define CHECK_MSC_UPCHANNEL(Channel) ((Channel >> POS_2_SHIFT) == 0U)

typedef enum
{
    SERVICE_REQUEST_0,
    SERVICE_REQUEST_1,
    SERVICE_REQUEST_2,
    SERVICE_REQUEST_3
} Msc_INTServiceRequestType_t;

#define CHECK_MSC_INTSERVICEREQ(SevericeQequest) ((SevericeQequest >> POS_2_SHIFT) == 0U)

typedef enum
{
    INT_DATAFRAME,
    INT_CMDFRAME,
    INT_TIMEFRAME,
    INT_RECEIVEDATAFRAME
} Msc_INTType_t;

#define CHECK_MSC_INTTYPE(Interrupt) ((Interrupt >> POS_2_SHIFT) == 0U)

typedef enum
{
    DEDIF,
    DECIF,
    DTFIF,
    URDIF,
    USTIF,
    OVIF,
    UNIF
} Msc_FlagType_t;

#define CHECK_MSC_FLAGTYPE(Flag)                                                                                       \
    ((Flag == DEDIF) || (Flag == DECIF) || (Flag == DTFIF) || (Flag == URDIF) || (Flag == USTIF) || (Flag == OVIF) ||  \
     (Flag == UNIF))

typedef enum
{
    CS_EN0,
    CS_EN1,
    CS_EN2,
    CS_EN3
} Msc_CSEnableType_t;

#define CHECK_MSC_CSENABLETYPE(CSEnable) ((CSEnable >> POS_2_SHIFT) == 0U)

typedef enum
{
    SERIALDATA_INPUT0,
    SERIALDATA_INPUT1,
    SERIALDATA_INPUT2,
    SERIALDATA_INPUT3,
    SERIALDATA_INPUT4,
    SERIALDATA_INPUT5,
    SERIALDATA_INPUT6,
    SERIALDATA_INPUT7
} Msc_SerialDataSourceInputType_t;

#define CHECK_MSC_SDSOURCE(SerialDataSource) ((SerialDataSource >> POS_3_SHIFT) == 0U)

typedef enum
{
    INJECT_CHANNEL0,
    INJECT_CHANNEL1
} Msc_InjectChannelType_t;

#define CHECK_MSC_INJECTCHANNEL(InjectChannel) ((InjectChannel >> POS_1_SHIFT) == 0U)

typedef enum
{
    NONE_CLOCK,
    FPER_CLOCK
} Msc_ABRAClockSourceType_t;

#define CHECK_MSC_ABRACLOCKSOURCE(ClockSource) ((ClockSource >> POS_1_SHIFT) == 0U)
#define CHECK_MSC_BOOL(Bool)                   ((Bool >> POS_1_SHIFT) == 0U)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief 禁止MSC模块
 *
 *
 * @param Status
 *        true:禁止模块
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_DisableModule(bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_CLKC_ADDR );
    regValue &= ~HWIO_MSC0_CLKC_MSC0_CLKC_DISR_MASK;
    regValue |=  Status<<HWIO_MSC0_CLKC_MSC0_CLKC_DISR_SHFT;
    REG_WRITE(HWIO_MSC0_CLKC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_CLKC.bits.DISR, Status);
#endif
}

/**
 * @brief 获取MSC模块状态
 *
 *
 * @param void
 * @retval bool
 *         true:模块已禁止
 *         false:模块已使能
 */
KF_INLINE bool Msc_LL_GetModuleState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_CLKC.bits.DISS));
#endif
}

/**
 * @brief 设置MSC模块睡眠状态
 *
 *
 * @param Status
 *         true:模块未进入睡眠模式
 *         false:模块进入睡眠模式
 * @retval void
 */
KF_INLINE void Msc_LL_DisableSleepMode(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_CLKC_ADDR );
    regValue &= ~HWIO_MSC0_CLKC_MSC0_CLKC_EDIS_MASK;
    regValue |=  Status<<HWIO_MSC0_CLKC_MSC0_CLKC_EDIS_SHFT;
    REG_WRITE(HWIO_MSC0_CLKC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_CLKC.bits.EDIS, Status);
#endif
}

/**
 * @brief 设置MSC模块睡眠状态
 *
 * @param  void
 * @retval Status
 *         true:模块未进入睡眠模式
 *         false:模块进入睡眠模式
 */
KF_INLINE bool Msc_LL_GetSleepMode(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_CLKC.bits.EDIS));
#endif
}

/**
 * @brief 设置MSC调试挂起模式
 *
 *
 * @param Mode
 *        MSC_NOSUSPEND
 *        MSC_HARDSUSPEND
 *        MSC_SOFTSUSPEND
 * @retval  void
 */
KF_INLINE void Msc_LL_SetDebugSuspendMode(Msc_SuspendMode_t Mode)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_SUSPENDMODE(Mode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DBG_ADDR );
    regValue &= ~HWIO_MSC0_DBG_MSC0_DBG_DBGP_MASK;
    regValue |=  true<<HWIO_MSC0_DBG_MSC0_DBG_DBGP_SHFT;
    REG_WRITE(HWIO_MSC0_DBG_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DBG.bits.DBGP, true);
#endif
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DBG_ADDR );
    regValue &= ~HWIO_MSC0_DBG_MSC0_DBG_DBGCTL_MASK;
    regValue |=  Mode<<HWIO_MSC0_DBG_MSC0_DBG_DBGCTL_SHFT;
    REG_WRITE(HWIO_MSC0_DBG_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DBG.bits.DBGCTL, Mode);
#endif
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DBG_ADDR );
    regValue &= ~HWIO_MSC0_DBG_MSC0_DBG_DBGP_MASK;
    regValue |=  false<<HWIO_MSC0_DBG_MSC0_DBG_DBGP_SHFT;
    REG_WRITE(HWIO_MSC0_DBG_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DBG.bits.DBGP, false);
#endif
}

/**
 * @brief 获取MSC调试挂起模式
 *
 *
 * @param void
 * @retval Msc_SuspendMode_t
 *         MSC_NOSUSPEND
 *         MSC_STOPCOUNTER
 */
KF_INLINE Msc_SuspendMode_t Msc_LL_GetDebugSuspendMode(void)
{
#ifdef SIMULATION
//TODO:
#else
    return ((Msc_SuspendMode_t)REG_READ(MSC_PTR->MSC_DBG.bits.DBGCTL));
#endif
}

/**
 * @brief 获取MSC调试挂起状态
 *
 *
 * @param void
 * @retval bool
 *         true: 模块已挂起
 *         false: 模块未挂起
 */
KF_INLINE bool Msc_LL_GetDebugSuspend(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DBG.bits.DBGSTA));
#endif
}

/**
 * @brief 清零MSC 复位状态
 *
 *
 * @param  bool
 *         true: 清零复位状态
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Msc_LL_ClearRst(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_RSTCLR_ADDR );
    regValue &= ~HWIO_MSC0_RSTCLR_MSC0_RSTCLR_CLR_MASK;
    regValue |=  Status<<HWIO_MSC0_RSTCLR_MSC0_RSTCLR_CLR_SHFT;
    REG_WRITE(HWIO_MSC0_RSTCLR_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_RSTCLR.bits.CLR, Status);
#endif
}

/**
 * @brief 请求MSC 复位
 *
 *
 * @param  bool
 *         true: 请求模块复位
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Msc_LL_ResetModule(bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_RST0_ADDR );
    regValue &= ~HWIO_MSC0_RST0_MSC0_RST0_RST_MASK;
    regValue |=  Status<<HWIO_MSC0_RST0_MSC0_RST0_RST_SHFT;
    REG_WRITE(HWIO_MSC0_RST0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_RST0.bits.RST, Status);
#endif
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_RST1_ADDR );
    regValue &= ~HWIO_MSC0_RST1_MSC0_RST1_RST_MASK;
    regValue |=  Status<<HWIO_MSC0_RST1_MSC0_RST1_RST_SHFT;
    REG_WRITE(HWIO_MSC0_RST1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_RST1.bits.RST, Status);
#endif
}

/**
 * @brief 获取MSC复位状态
 *
 *
 * @ param void
 * @ retval bool
 *          true: 模块已经复位
 *          false: 模块没有复位
 */
KF_INLINE bool Msc_LL_GetResetState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_RST0.bits.RSTSTA));
#endif
}

/**
 * @brief 使能MSC访问控制
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval void
 */
KF_INLINE void Msc_LL_EnableAccess(Msc_AccessEnableType_t AccessEnable)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
//TODO:
#else
    REG_BIT_SET(MSC_PTR->MSC_ACES0.reg, MASK_1_BIT << AccessEnable);
#endif
}

/**
 * @brief 获取MSC访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE bool Msc_LL_GetAccess(Msc_AccessEnableType_t AccessEnable)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_MSC0_ACES0_ADDR, MASK_1_BIT << AccessEnable, AccessEnable));
//TODO: check if correct

#else
    return (REG_BITS_READ(MSC_PTR->MSC_ACES0.reg, MASK_1_BIT << AccessEnable, AccessEnable));
#endif
}

/**
 * @brief 获取MSC模块版本信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetModuleVersion(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_INFO.bits.MODREV));
#endif
}

/**
 * @brief 获取MSC模块类型信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetModuleType(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_INFO.bits.MODTYPE));
#endif
}

/**
 * @brief 获取MSC模块ID信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetModuleId(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_INFO.bits.MODNUM));
#endif
}

/**
 * @brief 设置MSC分数分频
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetFractionDivide(const uint32_t Divide)
{
    KF_DRV_MSC_ASSERT((Divide >> POS_10_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_FD_ADDR );
    regValue &= ~HWIO_MSC0_FD_MSC0_FD_FDVI_MASK;
    regValue |=  Divide<<HWIO_MSC0_FD_MSC0_FD_FDVI_SHFT;
    REG_WRITE(HWIO_MSC0_FD_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_FD.bits.FDVI, Divide);
#endif
}

/**
 * @brief 设置MSC分频模式
 *
 *
 * @param Msc_DivideModeType_t
 *        FRACTIONDIVIDE_MODE
 *        INTEGERDIVIDE_MODE
 * @retval void
 */
KF_INLINE void Msc_LL_SetDivideMode(const Msc_DivideModeType_t DivideMode)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_DIVIDEMODE(DivideMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_FD_ADDR );
    regValue &= ~HWIO_MSC0_FD_MSC0_FD_DVIMOD_MASK;
    regValue |=  DivideMode<<HWIO_MSC0_FD_MSC0_FD_DVIMOD_SHFT;
    REG_WRITE(HWIO_MSC0_FD_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_FD.bits.DVIMOD, DivideMode);
#endif
}

/**
 * @brief 获取MSC分频结果
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetDivideResult(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_FD.bits.RESULT));
#endif
}

/**
 * @brief 使能MSC硬件时钟工作
 *
 *
 * @param Status
 *        true:使能硬件时钟
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_EnableHwClock(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_FD_ADDR );
    regValue &= ~HWIO_MSC0_FD_MSC0_FD_ENHW_MASK;
    regValue |=  Status<<HWIO_MSC0_FD_MSC0_FD_ENHW_SHFT;
    REG_WRITE(HWIO_MSC0_FD_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_FD.bits.ENHW, Status);
#endif
}

/**
 * @brief 禁止MSC硬件时钟工作
 *
 *
 * @param Status
 *        true:禁用硬件时钟
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_DisableHwClock(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_FD_ADDR );
    regValue &= ~HWIO_MSC0_FD_MSC0_FD_DISCLK_MASK;
    regValue |=  Status<<HWIO_MSC0_FD_MSC0_FD_DISCLK_SHFT;
    REG_WRITE(HWIO_MSC0_FD_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_FD.bits.DISCLK, Status);
#endif
}

/**
 * @brief 设置MSC上行通道帧类型
 *
 *
 * @param Msc_UpFrameMode_t
 *        UP_BIT_12
 *        UP_BIT_16
 * @retval void
 */
KF_INLINE void Msc_LL_SetUpFrameMode(const Msc_UpFrameMode_t UpFrameMode)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_UPFRAMEMODE(UpFrameMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_USTA_ADDR );
    regValue &= ~HWIO_MSC0_USTA_MSC0_USTA_UFT_MASK;
    regValue |=  UpFrameMode<<HWIO_MSC0_USTA_MSC0_USTA_UFT_SHFT;
    REG_WRITE(HWIO_MSC0_USTA_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_USTA.bits.UFT, UpFrameMode);
#endif
}

/**
 * @brief 设置MSC上行时钟分频
 *
 *
 * @param Msc_UpClockDivideType_t
 *        UPCLOCK_PROHIBIT
 *        UPCLOCK_DIVIDE_4
 *        UPCLOCK_DIVIDE_8
 *        UPCLOCK_DIVIDE_16
 *        UPCLOCK_DIVIDE_32
 *        UPCLOCK_DIVIDE_64
 *        UPCLOCK_DIVIDE_128
 *        UPCLOCK_DIVIDE_256
 * @retval void
 */
KF_INLINE void Msc_LL_SetUpClockDivide(const Msc_UpClockDivideType_t UpClockDivide)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_UPCLOCKDIVIDE(UpClockDivide));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_USTA_ADDR );
    regValue &= ~HWIO_MSC0_USTA_MSC0_USTA_UDVI_MASK;
    regValue |=  UpClockDivide<<HWIO_MSC0_USTA_MSC0_USTA_UDVI_SHFT;
    REG_WRITE(HWIO_MSC0_USTA_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_USTA.bits.UDVI, UpClockDivide);
#endif
}

/**
 * @brief 设置MSC上行帧奇偶校验模式
 *
 *
 * @param Msc_ParityCheckModeType_t
 *        EVEN_CHECK
 *        ODD_CHECK
 * @retval void
 */
KF_INLINE void Msc_LL_SetUpParityCheckMode(const Msc_ParityCheckModeType_t ParityCheckMode)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_PARITYCHECKMODE(ParityCheckMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_USTA_ADDR );
    regValue &= ~HWIO_MSC0_USTA_MSC0_USTA_PCTR_MASK;
    regValue |=  ParityCheckMode<<HWIO_MSC0_USTA_MSC0_USTA_PCTR_SHFT;
    REG_WRITE(HWIO_MSC0_USTA_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_USTA.bits.PCTR, ParityCheckMode);
#endif
}

/**
 * @brief 使能MSC上行帧接收中断延迟
 *
 *
 * @param Status
 *        true:接收中断延迟一个周期
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_EnableUpRecDelay(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_USTA_ADDR );
    regValue &= ~HWIO_MSC0_USTA_MSC0_USTA_RDIDLY_MASK;
    regValue |=  Status<<HWIO_MSC0_USTA_MSC0_USTA_RDIDLY_SHFT;
    REG_WRITE(HWIO_MSC0_USTA_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_USTA.bits.RDIDLY, Status);
#endif
}

/**
 * @brief 获取MSC上行通道计数
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetUpCount(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_USTA.bits.UCNT));
#endif
}

/**
 * @brief 设置MSC下行通道传输模式
 *
 *
 * @param Msc_DownTransferModeType_t
 *        TRIGGER_MODE
 *        REPEAT_MODE
 * @retval void
 */
KF_INLINE void Msc_LL_SetDownTransferMode(const Msc_DownTransferModeType_t DownTransferMode)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_DOWNTRANSFERMODE(DownTransferMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTL_ADDR );
    regValue &= ~HWIO_MSC0_DCTL_MSC0_DCTL_TMOD_MASK;
    regValue |=  DownTransferMode<<HWIO_MSC0_DCTL_MSC0_DCTL_TMOD_SHFT;
    REG_WRITE(HWIO_MSC0_DCTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTL.bits.TMOD, DownTransferMode);
#endif
}

/**
 * @brief 获取MSC命令帧指示
 *
 *
 * @param void
 * @retval bool
 *         true:启动发送命令帧
 *         false:无操作
 */
KF_INLINE bool Msc_LL_GetCMDFrameState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DCTL.bits.CP));
#endif
}

/**
 * @brief 获取MSC数据帧指示
 *
 *
 * @param void
 * @retval bool
 *         true:启动发送数据帧
 *         false:无操作
 */
KF_INLINE bool Msc_LL_GetDataFrameState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DCTL.bits.DP));
#endif
}

/**
 * @brief 设置MSC移位寄存器低位中需要被发送的数据位数
 *
 *
 * @param BitLength
 * @retval void
 */
KF_INLINE void Msc_LL_SetDownFrameLowBitLength(const uint32_t BitLength)
{
    KF_DRV_MSC_ASSERT((BitLength >> POS_5_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTL_ADDR );
    regValue &= ~HWIO_MSC0_DCTL_MSC0_DCTL_NDBL_MASK;
    regValue |=  BitLength<<HWIO_MSC0_DCTL_MSC0_DCTL_NDBL_SHFT;
    REG_WRITE(HWIO_MSC0_DCTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTL.bits.NDBL, BitLength);
#endif
}

/**
 * @brief 设置MSC移位寄存器高位中需要被发送的数据位数
 *
 *
 * @param BitLength
 * @retval void
 */
KF_INLINE void Msc_LL_SetDownFrameHighBitLength(const uint32_t BitLength)
{
    KF_DRV_MSC_ASSERT((BitLength >> POS_5_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTL_ADDR );
    regValue &= ~HWIO_MSC0_DCTL_MSC0_DCTL_NDBH_MASK;
    regValue |=  BitLength<<HWIO_MSC0_DCTL_MSC0_DCTL_NDBH_SHFT;
    REG_WRITE(HWIO_MSC0_DCTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTL.bits.NDBH, BitLength);
#endif
}

/**
 * @brief 使能MSC SRL数据选择位
 *
 *
 * @param Status
 *        true:启用SRL数据选择位
 *        false:无SRL数据选择位
 * @retval BitLength
 */
KF_INLINE void Msc_LL_EnableSRLChooseBit(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTL_ADDR );
    regValue &= ~HWIO_MSC0_DCTL_MSC0_DCTL_ENSELL_MASK;
    regValue |=  Status<<HWIO_MSC0_DCTL_MSC0_DCTL_ENSELL_SHFT;
    REG_WRITE(HWIO_MSC0_DCTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTL.bits.ENSELL, Status);
#endif
}

/**
 * @brief 使能MSC SRH数据选择位
 *
 *
 * @param Status
 *        true:启用SRH数据选择位
 *        false:无SRH数据选择位
 * @retval BitLength
 */
KF_INLINE void Msc_LL_EnableSRHChooseBit(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTL_ADDR );
    regValue &= ~HWIO_MSC0_DCTL_MSC0_DCTL_ENSELH_MASK;
    regValue |=  Status<<HWIO_MSC0_DCTL_MSC0_DCTL_ENSELH_SHFT;
    REG_WRITE(HWIO_MSC0_DCTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTL.bits.ENSELH, Status);
#endif
}

/**
 * @brief 获取MSC 下行通道状态
 *
 *
 * @param Status
 *        true:禁用下行通道
 *        false:无操作
 * @retval BitLength
 */
KF_INLINE bool Msc_LL_GetDownChannelState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DCTL.bits.DOWNEN));
#endif
}

/**
 * @brief 设置MSC 命令传输位长度
 *
 *
 * @param BitLength
 * @retval void
 */
KF_INLINE void Msc_LL_SetCMDBitLength(const uint32_t BitLength)
{
    KF_DRV_MSC_ASSERT((BitLength >> POS_6_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTL_ADDR );
    regValue &= ~HWIO_MSC0_DCTL_MSC0_DCTL_NBC_MASK;
    regValue |=  BitLength<<HWIO_MSC0_DCTL_MSC0_DCTL_NBC_SHFT;
    REG_WRITE(HWIO_MSC0_DCTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTL.bits.NBC, BitLength);
#endif
}

/**
 * @brief 获取MSC 命令传输位长度
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetCMDBitLength(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DCTL.bits.NBC));
#endif
}

/**
 * @brief 设置MSC 命令传输位长度
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetDataInvaildBitLength(const uint32_t BitLength)
{
    KF_DRV_MSC_ASSERT((BitLength >> POS_5_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTL_ADDR );
    regValue &= ~HWIO_MSC0_DCTL_MSC0_DCTL_PDD_MASK;
    regValue |=  BitLength<<HWIO_MSC0_DCTL_MSC0_DCTL_PDD_SHFT;
    REG_WRITE(HWIO_MSC0_DCTL_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTL.bits.PDD, BitLength);
#endif
}

/**
 * @brief 获取MSC 命令传输位长度
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetDataInvaildBitLength(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DCTL.bits.PDD));
#endif
}

/**
 * @brief 获取MSC 无效时间帧计数器值
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetInvaildTimeFrameCount(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DSTA.bits.PFCNT));
#endif
}

/**
 * @brief 获取MSC 无效时间帧个数
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetInvaildTimeFrameNumber(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DSTA.bits.NPTF));
#endif
}

/**
 * @brief 设置MSC 无效时间帧个数
 *
 *
 * @param Number
 * @retval void
 */
KF_INLINE void Msc_LL_SetInvaildTimeFrameNumber(const uint32_t Number)
{
    KF_DRV_MSC_ASSERT((Number >> POS_4_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTA_ADDR );
    regValue &= ~HWIO_MSC0_DSTA_MSC0_DSTA_NPTF_MASK;
    regValue |=  Number<<HWIO_MSC0_DSTA_MSC0_DSTA_NPTF_SHFT;
    REG_WRITE(HWIO_MSC0_DSTA_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTA.bits.NPTF, Number);
#endif
}

/**
 * @brief 获取MSC 下行通道计数器
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetDownChannelCount(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DSTA.bits.DCNT));
#endif
}

/**
 * @brief 获取MSC 数据帧状态
 *
 *
 * @param void
 * @retval bool
 *         true:当前正在发送数据帧的有效位
 *         false:当前没有发送任何数据帧
 */
KF_INLINE bool Msc_LL_GetDataFrameValidState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DSTA.bits.DFA));
#endif
}

/**
 * @brief 获取MSC 命令帧状态
 *
 *
 * @param void
 * @retval bool
 *         true:当前正在发送命令帧的有效位
 *         false:当前没有发送任何命令帧
 */
KF_INLINE bool Msc_LL_GetCMDFrameValidState(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DSTA.bits.CFA));
#endif
}

/**
 * @brief 写MSC 下行数据寄存器低位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteDataFrameLow(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DDAT_ADDR );
    regValue &= ~HWIO_MSC0_DDAT_MSC0_DDAT_DDL_MASK;
    regValue |=  Data<<HWIO_MSC0_DDAT_MSC0_DDAT_DDL_SHFT;
    REG_WRITE(HWIO_MSC0_DDAT_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DDAT.bits.DDL, Data);
#endif
}

/**
 * @brief 写MSC 下行数据寄存器高位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteDataFrameHigh(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DDAT_ADDR );
    regValue &= ~HWIO_MSC0_DDAT_MSC0_DDAT_DDH_MASK;
    regValue |=  Data<<HWIO_MSC0_DDAT_MSC0_DDAT_DDH_SHFT;
    REG_WRITE(HWIO_MSC0_DDAT_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DDAT.bits.DDH, Data);
#endif
}

/**
 * @brief 读MSC 下行数据寄存器低位
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_ReadDataFrameLow(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DDAT.bits.DDL));
#endif
}

/**
 * @brief 读MSC 下行数据寄存器高位
 *
 *
 * @param uint32_t
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_ReadDataFrameHigh(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DDAT.bits.DDH));
#endif
}

/**
 * @brief 写MSC 下行命令寄存器低位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteCMDFrameLow(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_CMD_ADDR );
    regValue &= ~HWIO_MSC0_CMD_MSC0_CMD_DCL_MASK;
    regValue |=  Data<<HWIO_MSC0_CMD_MSC0_CMD_DCL_SHFT;
    REG_WRITE(HWIO_MSC0_CMD_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_CMD.bits.DCL, Data);
#endif
}

/**
 * @brief 写MSC 下行命令寄存器高位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteCMDFrameHigh(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_CMD_ADDR );
    regValue &= ~HWIO_MSC0_CMD_MSC0_CMD_DCH_MASK;
    regValue |=  Data<<HWIO_MSC0_CMD_MSC0_CMD_DCH_SHFT;
    REG_WRITE(HWIO_MSC0_CMD_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_CMD.bits.DCH, Data);
#endif
}

/**
 * @brief 读MSC 下行命令寄存器低位
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_ReadCMDFrameLow(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_CMD.bits.DCL));
#endif
}

/**
 * @brief 读MSC 下行命令寄存器高位
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_ReadCMDFrameHigh(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_CMD.bits.DCH));
#endif
}

/**
 * @brief 设置MSC 下行低位数据来源
 *
 *
 * @param uint32_t
 * @param Msc_DataBitSourceType_t
 *        REG_DATA
 *        ALINXH_DATA
 *        REVERSE_ALINXH_DATA
 * @retval void
 */
KF_INLINE void Msc_LL_SetDataFrameLowBitSource(const uint32_t BitPose, Msc_DataBitSourceType_t BitSource)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_DATABITSOURCE(BitSource));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_DDATSELL_ADDR ,  BitSource << (BitPose * POS_2_SHIFT));//TODO: check if correct

#else
    REG_BITS_WRITE(
      MSC_PTR->MSC_DDATSELL.reg, MASK_2_BIT << (BitPose * POS_2_SHIFT), BitSource << (BitPose * POS_2_SHIFT));
#endif
}

/**
 * @brief 获取MSC 下行低位数据来源
 *
 *
 * @param uint32_t
 * @param Msc_DataBitSourceType_t
 *        REG_DATA
 *        ALINXH_DATA
 *        REVERSE_ALINXH_DATA
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetDataFrameLowBitSource(const uint32_t BitPose, Msc_DataBitSourceType_t BitSource)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_DATABITSOURCE(BitSource));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_MSC0_DDATSELL_ADDR, MASK_2_BIT << (BitPose * POS_2_SHIFT), (BitPose * POS_2_SHIFT)));
//TODO: check if correct

#else
    return (REG_BITS_READ(MSC_PTR->MSC_DDATSELL.reg, MASK_2_BIT << (BitPose * POS_2_SHIFT), (BitPose * POS_2_SHIFT)));
#endif
}

/**
 * @brief 设置MSC 下行高位数据来源
 *
 *
 * @param uint32_t
 * @param Msc_DataBitSourceType_t
 *        REG_DATA
 *        ALINXH_DATA
 *        REVERSE_ALINXH_DATA
 * @retval void
 */
KF_INLINE void Msc_LL_SetDataFrameHighBitSource(const uint32_t BitPose, Msc_DataBitSourceType_t BitSource)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_DATABITSOURCE(BitSource));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_DDATSELH_ADDR ,  BitSource << (BitPose * POS_2_SHIFT));//TODO: check if correct

#else
    REG_BITS_WRITE(
      MSC_PTR->MSC_DDATSELH.reg, MASK_2_BIT << (BitPose * POS_2_SHIFT), BitSource << (BitPose * POS_2_SHIFT));
#endif
}

/**
 * @brief 获取MSC 下行高位数据来源
 *
 *
 * @param uint32_t
 * @param Msc_DataBitSourceType_t
 *        REG_DATA
 *        ALINXH_DATA
 *        REVERSE_ALINXH_DATA
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetDataFrameHighBitSource(const uint32_t BitPose, Msc_DataBitSourceType_t BitSource)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_DATABITSOURCE(BitSource));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_MSC0_DDATSELH_ADDR, MASK_2_BIT << (BitPose * POS_2_SHIFT), (BitPose * POS_2_SHIFT)));
//TODO: check if correct

#else
    return (REG_BITS_READ(MSC_PTR->MSC_DDATSELH.reg, MASK_2_BIT << (BitPose * POS_2_SHIFT), (BitPose * POS_2_SHIFT)));
#endif
}

/**
 * @brief 使能MSC 定位紧急停止功能
 *
 *
 * @param uint32_t
 * @param bool
 *        true:使能紧急停止功能
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_EnableDataFrameLowEmergencyStop(const uint32_t BitPose, const bool Status)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_CLKC_MSC0_CLKC_RESERVE0_MASK ,  Status << BitPose);
//TODO: check if correct

#else
    REG_BITS_WRITE(MSC_PTR->MSC_ES.reg, MASK_1_BIT << BitPose, Status << BitPose);
#endif
}

/**
 * @brief 使能MSC 高位紧急停止功能
 *
 *
 * @param uint32_t
 * @param bool
 *        true:使能紧急停止功能
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_EnableDataFrameHighEmergencyStop(const uint32_t BitPose, const bool Status)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_CLKC_MSC0_CLKC_RESERVE0_MASK ,  Status << (BitPose + POS_16_OFFSET));
//TODO: check if correct

#else
    REG_BITS_WRITE(MSC_PTR->MSC_ES.reg, MASK_1_BIT << (BitPose + POS_16_OFFSET), Status << (BitPose + POS_16_OFFSET));
#endif
}

/**
 * @brief 读取MSC 上行通道数据
 *
 *
 * @param Msc_UpChannelType_t
 *        UP_CHANNEL_0
 *        UP_CHANNEL_1
 *        UP_CHANNEL_2
 *        UP_CHANNEL_3
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_ReadUpChannelData(const Msc_UpChannelType_t Channel)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_UPCHANNEL(Channel));
#ifdef SIMULATION
//TODO: cannot process please check 
#else
    return (REG_READ(MSC_PTR->MSC_UDAT[Channel].bits.REVDAT));
#endif
}

/**
 * @brief 获取MSC 上行通道数据更新状态
 *
 *
 * @param Msc_UpChannelType_t
 *        UP_CHANNEL_0
 *        UP_CHANNEL_1
 *        UP_CHANNEL_2
 *        UP_CHANNEL_3
 * @retval bool
 *         true:指定上行通道接收到数据
 *         false:指定上行通道未接收到数据
 */
KF_INLINE bool Msc_LL_GetUpChannelDataState(const Msc_UpChannelType_t Channel)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_UPCHANNEL(Channel));
#ifdef SIMULATION
//TODO: cannot process please check 
#else
    return (REG_READ(MSC_PTR->MSC_UDAT[Channel].bits.V));
#endif
}

/**
 * @brief 清除MSC 上行通道数据更新状态
 *
 *
 * @param Msc_UpChannelType_t
 *        UP_CHANNEL_0
 *        UP_CHANNEL_1
 *        UP_CHANNEL_2
 *        UP_CHANNEL_3
 * @param bool
 *        true:清除上行通道数据更新状态
 *        false:无影响
 * @retval void
 */
KF_INLINE void Msc_LL_ClearUpChannelDataState(const Msc_UpChannelType_t Channel, const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_UPCHANNEL(Channel));
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
//TODO: cannot process please check 
#else
    REG_WRITE(MSC_PTR->MSC_UDAT[Channel].bits.VC, Status);
#endif
}

/**
 * @brief 获取MSC 上行通道低位地址
 *
 *
 * @param Msc_UpChannelType_t
 *        UP_CHANNEL_0
 *        UP_CHANNEL_1
 *        UP_CHANNEL_2
 *        UP_CHANNEL_3
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetUpChannelLowAddress(const Msc_UpChannelType_t Channel)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_UPCHANNEL(Channel));
#ifdef SIMULATION
//TODO: cannot process please check 
#else
    return (REG_READ(MSC_PTR->MSC_UDAT[Channel].bits.LADR));
#endif
}

/**
 * @brief 获取MSC 上行通道接收数据奇偶校验结果
 *
 *
 * @param Msc_UpChannelType_t
 *        UP_CHANNEL_0
 *        UP_CHANNEL_1
 *        UP_CHANNEL_2
 *        UP_CHANNEL_3
 * @retval bool //TODO:不确定bool值和奇偶校验结果的对应关系
 *         true:
 *         false:
 */
KF_INLINE bool Msc_LL_GetUpChannelParityCheckResult0(const Msc_UpChannelType_t Channel)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_UPCHANNEL(Channel));
#ifdef SIMULATION
//TODO: cannot process please check 
#else
    return (REG_READ(MSC_PTR->MSC_UDAT[Channel].bits.IPF));
#endif
}

/**
 * @brief 获取MSC 上行通道接收数据奇偶校验结果
 *
 *
 * @param Msc_UpChannelType_t
 *        UP_CHANNEL_0
 *        UP_CHANNEL_1
 *        UP_CHANNEL_2
 *        UP_CHANNEL_3
 * @retval bool //TODO:不确定和上一函数区别
 *         true:奇偶校验错误
 *         false:无奇偶校验错误
 */
KF_INLINE bool Msc_LL_GetUpChannelParityCheckResult1(const Msc_UpChannelType_t Channel)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_UPCHANNEL(Channel));
#ifdef SIMULATION
//TODO: cannot process please check 
#else
    return (REG_READ(MSC_PTR->MSC_UDAT[Channel].bits.PERR));
#endif
}

/**
 * @brief 设置MSC 中断选择
 *
 *
 * @param Msc_INTType_t
 *        INT_DATAFRAME
 *        INT_CMDFRAME
 *        INT_TIMEFRAME
 *        INT_RECEIVEDATAFRAME
 * @param Msc_INTServiceRequestType_t
 *        SERVICE_REQUEST_0
 *        SERVICE_REQUEST_1
 *        SERVICE_REQUEST_2
 *        SERVICE_REQUEST_3
 * @retval void
 */
KF_INLINE void Msc_LL_SetIntServiceRequest(const Msc_INTType_t INT, const Msc_INTServiceRequestType_t INTServiceRequest)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_INTTYPE(INT));
    KF_DRV_MSC_ASSERT(CHECK_MSC_INTSERVICEREQ(INTServiceRequest));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_ISEL_ADDR ,  INTServiceRequest << (INT * POS_4_SHIFT));
//TODO: check if correct

#else
    REG_BITS_WRITE(MSC_PTR->MSC_ISEL.reg, MASK_2_BIT << (INT * POS_4_SHIFT), INTServiceRequest << (INT * POS_4_SHIFT));
#endif
}

/**
 * @brief 获取MSC 中断选择
 *
 *
 * @param Msc_INTType_t
 *        INT_DATAFRAME
 *        INT_CMDFRAME
 *        INT_TIMEFRAME
 *        INT_RECEIVEDATAFRAME
 * @retval Msc_INTServiceRequestType_t
 *        SERVICE_REQUEST_0
 *        SERVICE_REQUEST_1
 *        SERVICE_REQUEST_2
 *        SERVICE_REQUEST_3
 */
KF_INLINE Msc_INTServiceRequestType_t Msc_LL_GetIntServiceRequest(const Msc_INTType_t INT)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_INTTYPE(INT));
#ifdef SIMULATION
    return ((Msc_INTServiceRequestType_t)REG_BITS_READ(HWIO_MSC0_ISEL_ADDR, MASK_2_BIT << (INT * POS_4_SHIFT), (INT * POS_4_SHIFT)));//TODO: check if correct

#else
    return ((Msc_INTServiceRequestType_t)REG_BITS_READ(
      MSC_PTR->MSC_ISEL.reg, MASK_2_BIT << (INT * POS_4_SHIFT), (INT * POS_4_SHIFT)));
#endif
}

/**
 * @brief 获取MSC 中断标志位
 *
 *
 * @param Msc_FlagType_t
 *        INT_DATAFRAME
 *        INT_CMDFRAME
 *        INT_TIMEFRAME
 *        INT_RECEIVEDATAFRAME
 * @retval bool
 *         true:相应标志位置位
 *         false:相应标志位未置位
 */
KF_INLINE bool Msc_LL_GetFlag(const Msc_FlagType_t Flag)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_FLAGTYPE(Flag));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_MSC0_IF_ADDR, MASK_1_BIT << Flag, Flag));
//TODO: check if correct

#else
    return (REG_BITS_READ(MSC_PTR->MSC_IF.reg, MASK_1_BIT << Flag, Flag));
#endif
}

/**
 * @brief 设置MSC 数据中断
 *
 *
 * @param Msc_FlagType_t
 *        DEDIF
 *        URDIF
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_EnableDataInt(const Msc_FlagType_t Flag, const uint32_t IntSet)
{
    // MARK:后续确定具体使用方式后完善此函数
    KF_DRV_MSC_ASSERT(CHECK_MSC_FLAGTYPE(Flag));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_IE_ADDR ,                    (IntSet << Flag * (POS_4_SHIFT / POS_3_SHIFT)));//TODO: check if correct

#else
    REG_BITS_WRITE(MSC_PTR->MSC_IE.reg, MASK_2_BIT << (Flag * (POS_4_SHIFT / POS_3_SHIFT)),
                   (IntSet << Flag * (POS_4_SHIFT / POS_3_SHIFT)));
#endif
}

/**
 * @brief 设置MSC 中断
 *
 *
 * @param Msc_FlagType_t
 *        DECIF
 *        DTFIF
 *        USTIF
 *        OVIF
 *        UNIF
 * @param Status
 *        ture:使能对应中断
 *        false:禁止对应中断
 * @retval void
 */
KF_INLINE void Msc_LL_EnableInt(const Msc_FlagType_t Flag, const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_FLAGTYPE(Flag));
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
    if (Flag < USTIF)
    {
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_IE_ADDR ,  Status << (Flag + POS_1_OFFSET));
//TODO: check if correct

#else
        REG_BITS_WRITE(MSC_PTR->MSC_IE.reg, MASK_1_BIT << (Flag + POS_1_OFFSET), Status << (Flag + POS_1_OFFSET));
#endif
    }
    else
    {
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_IE_ADDR ,  Status << (Flag + POS_2_OFFSET));
//TODO: check if correct

#else
        REG_BITS_WRITE(MSC_PTR->MSC_IE.reg, MASK_1_BIT << (Flag + POS_2_OFFSET), Status << (Flag + POS_2_OFFSET));
#endif
    }
}

/**
 * @brief 清除MSC 中断
 *
 *
 * @param Msc_FlagType_t
 *        DEDIF
 *        DECIF
 *        DTFIF
 *        URDIF
 *        USTIF
 *        OVIF
 *        UNIF
 * @param Status
 *        ture:清除对应中断
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_ClearInt(const Msc_FlagType_t Flag, const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_FLAGTYPE(Flag));
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
    if (Flag < OVIF)
    {
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_IC_ADDR ,  Status << Flag);
//TODO: check if correct

#else
        REG_BITS_WRITE(MSC_PTR->MSC_IC.reg, MASK_1_BIT << Flag, Status << Flag);
#endif
    }
    else
    {
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_IC_ADDR ,                        Status << (Flag * POS_2_SHIFT - POS_5_OFFSET));//TODO: check if correct

#else
        REG_BITS_WRITE(MSC_PTR->MSC_IC.reg, MASK_2_BIT << (Flag * POS_2_SHIFT - POS_5_OFFSET),
                       Status << (Flag * POS_2_SHIFT - POS_5_OFFSET));
#endif
    }
}

/**
 * @brief 置位MSC 中断
 *
 *
 * @param IntSet
 * @retval void
 */
KF_INLINE void Msc_LL_SetInt(const uint32_t IntSet)
{
    // TODO:后续根据实际要求更新该API操作
#ifdef SIMULATION
    REG_WRITE(HWIO_MSC0_SIF_ADDR , IntSet);
//TODO: check if correct

#else
   REG_WRITE(MSC_PTR->MSC_SIF.reg,IntSet);
#endif
}

/**
 * @brief 设置MSC FCL输出极性
 *
 *
 * @param Status
 *        true:FCLP和FCL信号极性相反，FCLN和FCL信号极性一致
 *        false:FCLP和FCL信号极性一致，FCLN和FCL信号极性相反
 * @retval void
 */
KF_INLINE void Msc_LL_SetFCLoutputPolarity(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
//TODO: Error: cannot findMSC_OCLT the correct register name please correct 
#else
    REG_WRITE(MSC_PTR->MSC_OCLT.bits.FCLPOL, Status);
#endif
}

/**
 * @brief 设置MSC SO输出极性
 *
 *
 * @param Status
 *        true:
 *        false:
 * @retval void
 */
KF_INLINE void Msc_LL_SetSOoutputPolarity(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
//TODO: Error: cannot findMSC_OCLT the correct register name please correct 
#else
    REG_WRITE(MSC_PTR->MSC_OCLT.bits.SOPOL, Status);
#endif
}

/**
 * @brief 设置MSC 片选输出极性
 *
 *
 * @param Status
 *        true:
 *        false:
 * @retval void
 */
KF_INLINE void Msc_LL_SetENoutputPolarity(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
//TODO: Error: cannot findMSC_OCLT the correct register name please correct 
#else
    REG_WRITE(MSC_PTR->MSC_OCLT.bits.ENPOL, Status);
#endif
}

/**
 * @brief 设置MSC SDI极性
 *
 *
 * @param Status
 *        true:
 *        false:
 * @retval void
 */
KF_INLINE void Msc_LL_SetSDIPolarity(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
//TODO: Error: cannot findMSC_OCLT the correct register name please correct 
#else
    REG_WRITE(MSC_PTR->MSC_OCLT.bits.SDIPOL, Status);
#endif
}

/**
 * @brief 设置MSC 输出时钟FCL是否被激活
 *
 *
 * @param Status
 *        true:
 *        false:
 * @retval void
 */
KF_INLINE void Msc_LL_EnableFCL(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
//TODO: Error: cannot findMSC_OCLT the correct register name please correct 
#else
    REG_WRITE(MSC_PTR->MSC_OCLT.bits.CLKCTRL, Status);
#endif
}

/**
 * @brief 设置MSC 片选信号
 *
 *
 * @param Msc_CSEnableType_t
 *        CS_EN0
 *        CS_EN1
 *        CS_EN2
 *        CS_EN3
 * @retval void
 */
KF_INLINE void Msc_LL_SetCSEnableL(const Msc_CSEnableType_t CSEnable)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_CSENABLETYPE(CSEnable));
#ifdef SIMULATION
//TODO: Error: cannot findMSC_OCLT the correct register name please correct 
#else
    REG_WRITE(MSC_PTR->MSC_OCLT.bits.ENLSEL, CSEnable);
#endif
}

/**
 * @brief 设置MSC 片选信号
 *
 *
 * @param Msc_CSEnableType_t
 *        CS_EN0
 *        CS_EN1
 *        CS_EN2
 *        CS_EN3
 * @retval void
 */
KF_INLINE void Msc_LL_SetCSEnableH(const Msc_CSEnableType_t CSEnable)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_CSENABLETYPE(CSEnable));
#ifdef SIMULATION
//TODO: Error: cannot findMSC_OCLT the correct register name please correct 
#else
    REG_WRITE(MSC_PTR->MSC_OCLT.bits.ENHSEL, CSEnable);
#endif
}

/**
 * @brief 设置MSC 片选信号
 *
 *
 * @param Msc_CSEnableType_t
 *        CS_EN0
 *        CS_EN1
 *        CS_EN2
 *        CS_EN3
 * @retval void
 */
KF_INLINE void Msc_LL_SetCSEnableC(const Msc_CSEnableType_t CSEnable)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_CSENABLETYPE(CSEnable));
#ifdef SIMULATION
//TODO: Error: cannot findMSC_OCLT the correct register name please correct 
#else
    REG_WRITE(MSC_PTR->MSC_OCLT.bits.ENCSEL, CSEnable);
#endif
}

/**
 * @brief 设置MSC 串行数据输入源
 *
 *
 * @param Msc_SerialDataSourceInputType_t
 *        SERIALDATA_INPUT0
 *        SERIALDATA_INPUT1
 *        SERIALDATA_INPUT2
 *        SERIALDATA_INPUT3
 *        SERIALDATA_INPUT4
 *        SERIALDATA_INPUT5
 *        SERIALDATA_INPUT6
 *        SERIALDATA_INPUT7
 * @retval void
 */
KF_INLINE void Msc_LL_SetSerialInputSourceData(const Msc_SerialDataSourceInputType_t SerialDataSource)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_SDSOURCE(SerialDataSource));
#ifdef SIMULATION
//TODO: Error: cannot findMSC_OCLT the correct register name please correct 
#else
    REG_WRITE(MSC_PTR->MSC_OCLT.bits.SDISEL, SerialDataSource);
#endif
}

/**
 * @brief 使能MSC 下行数据帧的高位扩展
 *
 *
 * @param Status
 *        true:使能高位扩展
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_SetDownChannelHighExtend(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTLE_ADDR );
    regValue &= ~HWIO_MSC0_DCTLE_MSC0_DCTLE_NDBHE_MASK;
    regValue |=  Status<<HWIO_MSC0_DCTLE_MSC0_DCTLE_NDBHE_SHFT;
    REG_WRITE(HWIO_MSC0_DCTLE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTLE.bits.NDBHE, Status);
#endif
}

/**
 * @brief 使能MSC 下行数据帧的低位扩展
 *
 *
 * @param Status
 *        true:使能低位扩展
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_SetDownChannelLowExtend(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTLE_ADDR );
    regValue &= ~HWIO_MSC0_DCTLE_MSC0_DCTLE_NDBLE_MASK;
    regValue |=  Status<<HWIO_MSC0_DCTLE_MSC0_DCTLE_NDBLE_SHFT;
    REG_WRITE(HWIO_MSC0_DCTLE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTLE.bits.NDBLE, Status);
#endif
}

/**
 * @brief 使能MSC 扩展模式
 *
 *
 * @param Status
 *        true:使能扩展模式
 *        false:禁用扩展模式
 * @retval void
 */
KF_INLINE void Msc_LL_EnableExtendMode(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTLE_ADDR );
    regValue &= ~HWIO_MSC0_DCTLE_MSC0_DCTLE_EXEN_MASK;
    regValue |=  Status<<HWIO_MSC0_DCTLE_MSC0_DCTLE_EXEN_SHFT;
    REG_WRITE(HWIO_MSC0_DCTLE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTLE.bits.EXEN, Status);
#endif
}

/**
 * @brief 获取MSC 命令-命令标志位
 *
 *
 * @param void
 * @retval bool
 *         ture:命令-命令标志位为1
 *         false:命令-命令标志位为0
 */
KF_INLINE bool Msc_LL_GetCMDStatus(void)
{
#ifdef SIMULATION
//TODO:
#else
    return (REG_READ(MSC_PTR->MSC_DCTLE.bits.CCF));
#endif
}

/**
 * @brief 使能MSC 外部输入
 *
 *
 * @param InjectChannel
 *        INJECT_CHANNEL0
 *        INJECT_CHANNEL1
 * @param bool
 *        true:使能MSC相应外部输入
 *        false:禁止MSC相应外部输入
 * @retval void
 */
KF_INLINE void Msc_LL_EnableExportInject(const Msc_InjectChannelType_t InjectChannel, const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_INJECTCHANNEL(InjectChannel));
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_DCTLE_ADDR ,                    Status << (InjectChannel * POS_8_SHIFT + POS_16_OFFSET));//TODO: check if correct

#else
    REG_BITS_WRITE(MSC_PTR->MSC_DCTLE.reg, MASK_1_BIT << (InjectChannel * POS_8_SHIFT + POS_16_OFFSET),
                   Status << (InjectChannel * POS_8_SHIFT + POS_16_OFFSET));
#endif
}

/**
 * @brief 设置MSC 外部引脚注入位置
 *
 *
 * @param InjectChannel
 *        INJECT_CHANNEL0
 *        INJECT_CHANNEL1
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetExportInject(const Msc_InjectChannelType_t InjectChannel, const uint32_t InjectPos)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_INJECTCHANNEL(InjectChannel));
    KF_DRV_MSC_ASSERT((InjectPos >> POS_6_SHIFT) == 0U);
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_DCTLE_ADDR ,                    InjectPos << (InjectChannel * POS_8_SHIFT + POS_17_OFFSET));//TODO: check if correct

#else
    REG_BITS_WRITE(MSC_PTR->MSC_DCTLE.reg, MASK_6_BIT << (InjectChannel * POS_8_SHIFT + POS_17_OFFSET),
                   InjectPos << (InjectChannel * POS_8_SHIFT + POS_17_OFFSET));
#endif
}

/**
 * @brief 使能MSC 两个连续命令帧之间是否插入数据帧
 *
 *
 * @param Status
 *        true:两个连续命令帧之间插入数据帧
 *        false:两个连续命令帧之间不插入数据帧
 * @retval void
 */
KF_INLINE void Msc_LL_EnableAutoInsertDataFrame(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCTLE_ADDR );
    regValue &= ~HWIO_MSC0_DCTLE_MSC0_DCTLE_CDCM_MASK;
    regValue |=  Status<<HWIO_MSC0_DCTLE_MSC0_DCTLE_CDCM_SHFT;
    REG_WRITE(HWIO_MSC0_DCTLE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCTLE.bits.CDCM, Status);
#endif
}

/**
 * @brief 设置MSC 上行通道看门狗预分频值
 *
 *
 * @param Count
 * @retval void
 */
KF_INLINE void Msc_LL_SetUpWDGPreScale(const uint32_t PreScale)
{
    KF_DRV_MSC_ASSERT((PreScale >> POS_4_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_UCTLE_ADDR );
    regValue &= ~HWIO_MSC0_UCTLE_MSC0_UCTLE_USTOPRE_MASK;
    regValue |=  PreScale<<HWIO_MSC0_UCTLE_MSC0_UCTLE_USTOPRE_SHFT;
    REG_WRITE(HWIO_MSC0_UCTLE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_UCTLE.bits.USTOPRE, PreScale);
#endif
}

/**
 * @brief 设置MSC 上行通道看门狗超时计数值
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetUpWDGTimeOut(const uint32_t TimeOutCount)
{
    KF_DRV_MSC_ASSERT((PreScale >> POS_4_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_UCTLE_ADDR );
    regValue &= ~HWIO_MSC0_UCTLE_MSC0_UCTLE_USTOVAL_MASK;
    regValue |=  TimeOutCount<<HWIO_MSC0_UCTLE_MSC0_UCTLE_USTOVAL_SHFT;
    REG_WRITE(HWIO_MSC0_UCTLE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_UCTLE.bits.USTOVAL, TimeOutCount);
#endif
}

/**
 * @brief 置位MSC 上行通道超时标志位
 *
 *
 * @param Status
 *        true:置位USTIF
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_SetUpWDGTimeOutState(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_UCTLE_ADDR );
    regValue &= ~HWIO_MSC0_UCTLE_MSC0_UCTLE_USTS_MASK;
    regValue |=  Status<<HWIO_MSC0_UCTLE_MSC0_UCTLE_USTS_SHFT;
    REG_WRITE(HWIO_MSC0_UCTLE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_UCTLE.bits.USTS, Status);
#endif
}

/**
 * @brief 设置MSC 上行通道超时中断服务请求
 *
 *
 * @param Msc_INTServiceRequestType_t
 *        SERVICE_REQUEST_0
 *        SERVICE_REQUEST_1
 *        SERVICE_REQUEST_2
 *        SERVICE_REQUEST_3
 * @retval void
 */
KF_INLINE void Msc_LL_SetUpTimeOutIntService(const Msc_INTServiceRequestType_t ServiceRequest)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_INTSERVICEREQ(ServiceRequest));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_UCTLE_ADDR );
    regValue &= ~HWIO_MSC0_UCTLE_MSC0_UCTLE_USTOIP_MASK;
    regValue |=  ServiceRequest<<HWIO_MSC0_UCTLE_MSC0_UCTLE_USTOIP_SHFT;
    REG_WRITE(HWIO_MSC0_UCTLE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_UCTLE.bits.USTOIP, ServiceRequest);
#endif
}

/**
 * @brief 设置MSC 下行低位扩展数据来源
 *
 *
 * @param uint32_t
 * @param Msc_DataBitSourceType_t
 *        REG_DATA
 *        ALINXH_DATA
 *        REVERSE_ALINXH_DATA
 * @retval void
 */
KF_INLINE void Msc_LL_SetExtendDataFrameLowBitSource(const uint32_t BitPose, Msc_DataBitSourceType_t BitSource)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_DATABITSOURCE(BitSource));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_DDATSELLE_ADDR ,  BitSource << (BitPose * POS_2_SHIFT));//TODO: check if correct

#else
    REG_BITS_WRITE(
      MSC_PTR->MSC_DDATSELLE.reg, MASK_2_BIT << (BitPose * POS_2_SHIFT), BitSource << (BitPose * POS_2_SHIFT));
#endif
}

/**
 * @brief 获取MSC 下行低位扩展数据来源
 *
 *
 * @param uint32_t
 * @param Msc_DataBitSourceType_t
 *        REG_DATA
 *        ALINXH_DATA
 *        REVERSE_ALINXH_DATA
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetExtendDataFrameLowBitSource(const uint32_t BitPose, Msc_DataBitSourceType_t BitSource)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_DATABITSOURCE(BitSource));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_MSC0_DDATSELLE_ADDR, MASK_2_BIT << (BitPose * POS_2_SHIFT), (BitPose * POS_2_SHIFT)));
//TODO: check if correct

#else
    return (REG_BITS_READ(MSC_PTR->MSC_DDATSELLE.reg, MASK_2_BIT << (BitPose * POS_2_SHIFT), (BitPose * POS_2_SHIFT)));
#endif
}

/**
 * @brief 设置MSC 下行高位扩展数据来源
 *
 *
 * @param uint32_t
 * @param Msc_DataBitSourceType_t
 *        REG_DATA
 *        ALINXH_DATA
 *        REVERSE_ALINXH_DATA
 * @retval void
 */
KF_INLINE void Msc_LL_SetExtendDataFrameHighBitSource(const uint32_t BitPose, Msc_DataBitSourceType_t BitSource)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_DATABITSOURCE(BitSource));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_DDATSELHE_ADDR ,  BitSource << (BitPose * POS_2_SHIFT));//TODO: check if correct

#else
    REG_BITS_WRITE(
      MSC_PTR->MSC_DDATSELHE.reg, MASK_2_BIT << (BitPose * POS_2_SHIFT), BitSource << (BitPose * POS_2_SHIFT));
#endif
}

/**
 * @brief 获取MSC 下行高位扩展数据来源
 *
 *
 * @param uint32_t
 * @param Msc_DataBitSourceType_t
 *        REG_DATA
 *        ALINXH_DATA
 *        REVERSE_ALINXH_DATA
 * @retval uint32_t
 */
KF_INLINE uint32_t Msc_LL_GetExtendDataFrameHighBitSource(const uint32_t BitPose, Msc_DataBitSourceType_t BitSource)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_DATABITSOURCE(BitSource));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_MSC0_DDATSELHE_ADDR, MASK_2_BIT << (BitPose * POS_2_SHIFT), (BitPose * POS_2_SHIFT)));
//TODO: check if correct

#else
    return (REG_BITS_READ(MSC_PTR->MSC_DDATSELHE.reg, MASK_2_BIT << (BitPose * POS_2_SHIFT), (BitPose * POS_2_SHIFT)));
#endif
}

/**
 * @brief 使能MSC 低位数据紧急停止功能
 *
 *
 * @param Status
 *        true:使能数据低位相应位域的紧急停止功能
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_StopExtendDataFrameLowBitEmergency(const uint32_t BitPose, const bool Status)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_CLKC_MSC0_CLKC_RESERVE0_MASK ,  Status << BitPose);
//TODO: check if correct

#else
    REG_BITS_WRITE(MSC_PTR->MSC_ESE.reg, MASK_1_BIT << BitPose, Status << BitPose);
#endif
}

/**
 * @brief 使能MSC 高位数据紧急停止功能
 *
 *
 * @param Status
 *        true:使能数据高位相应位域的紧急停止功能
 *        false:无操作
 * @retval void
 */
KF_INLINE void Msc_LL_StopExtendDataFrameHighBitEmergency(const uint32_t BitPose, const bool Status)
{
    KF_DRV_MSC_ASSERT((BitPose >> POS_5_SHIFT) == 0U);
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_MSC0_CLKC_MSC0_CLKC_RESERVE0_MASK ,  Status << (BitPose + POS_16_OFFSET));
//TODO: check if correct

#else
    REG_BITS_WRITE(MSC_PTR->MSC_ESE.reg, MASK_1_BIT << (BitPose + POS_16_OFFSET), Status << (BitPose + POS_16_OFFSET));
#endif
}

/**
 * @brief 设置MSC 下行数据扩展帧的无效位长度
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetDownDataExtendFrameInvalidBitLength(const uint32_t BitLength)
{
    KF_DRV_MSC_ASSERT((BitLength >> POS_2_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTE_ADDR );
    regValue &= ~HWIO_MSC0_DSTE_MSC0_DSTE_PPDE_MASK;
    regValue |=  BitLength<<HWIO_MSC0_DSTE_MSC0_DSTE_PPDE_SHFT;
    REG_WRITE(HWIO_MSC0_DSTE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTE.bits.PPDE, BitLength);
#endif
}

/**
 * @brief 设置MSC 下行命令扩展帧的无效位长度
 *
 *
 * @param uint32_t:实际无效位长度为设置值加2
 * @retval void
 */
KF_INLINE void Msc_LL_SetDownCMDExtendFrameInvalidBitLength(const uint32_t BitLength)
{
    KF_DRV_MSC_ASSERT((BitLength >> POS_6_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTE_ADDR );
    regValue &= ~HWIO_MSC0_DSTE_MSC0_DSTE_PPCE_MASK;
    regValue |=  BitLength<<HWIO_MSC0_DSTE_MSC0_DSTE_PPCE_SHFT;
    REG_WRITE(HWIO_MSC0_DSTE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTE.bits.PPCE, BitLength);
#endif
}

/**
 * @brief 设置MSC 下行通道分频器
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetDownChannelClockDivide(const uint32_t Divide)
{
    KF_DRV_MSC_ASSERT((Divide >> POS_4_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTE_ADDR );
    regValue &= ~HWIO_MSC0_DSTE_MSC0_DSTE_NDVI_MASK;
    regValue |=  Divide<<HWIO_MSC0_DSTE_MSC0_DSTE_NDVI_SHFT;
    REG_WRITE(HWIO_MSC0_DSTE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTE.bits.NDVI, Divide);
#endif
}

/**
 * @brief 设置MSC PPCE的高位扩展位
 *
 *
 * @param bool
 *        true:增添最高位为1
 *        false:增添最高位为0
 * @retval void
 */
KF_INLINE void Msc_LL_AddMSB(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTE_ADDR );
    regValue &= ~HWIO_MSC0_DSTE_MSC0_DSTE_PPCEM_MASK;
    regValue |=  Status<<HWIO_MSC0_DSTE_MSC0_DSTE_PPCEM_SHFT;
    REG_WRITE(HWIO_MSC0_DSTE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTE.bits.PPCEM, Status);
#endif
}

/**
 * @brief 使能MSC 快速模式
 *
 *
 * @param bool
 *        true:启用快速模式
 *        false:关闭快速模式
 * @retval void
 */
KF_INLINE void Msc_LL_EnableFastMode(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
    // TODO:不确定UL1的具体用法
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTE_ADDR );
    regValue &= ~HWIO_MSC0_DSTE_MSC0_DSTE_UL1_MASK;
    regValue |=  true<<HWIO_MSC0_DSTE_MSC0_DSTE_UL1_SHFT;
    REG_WRITE(HWIO_MSC0_DSTE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTE.bits.UL1, true);
#endif
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTE_ADDR );
    regValue &= ~HWIO_MSC0_DSTE_MSC0_DSTE_FASTMOD_MASK;
    regValue |=  Status<<HWIO_MSC0_DSTE_MSC0_DSTE_FASTMOD_SHFT;
    REG_WRITE(HWIO_MSC0_DSTE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTE.bits.FASTMOD, Status);
#endif
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTE_ADDR );
    regValue &= ~HWIO_MSC0_DSTE_MSC0_DSTE_UL1_MASK;
    regValue |=  false<<HWIO_MSC0_DSTE_MSC0_DSTE_UL1_SHFT;
    REG_WRITE(HWIO_MSC0_DSTE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTE.bits.UL1, false);
#endif
}

/**
 * @brief 使能MSC 命令扩展模式
 *
 *
 * @param bool
 *        true:启用命令扩展模式
 *        false:关闭命令扩展模式
 * @retval void
 */
KF_INLINE void Msc_LL_EnableExtendCMDMode(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
    // TODO:不确定UL1的具体用法
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTE_ADDR );
    regValue &= ~HWIO_MSC0_DSTE_MSC0_DSTE_UL1_MASK;
    regValue |=  true<<HWIO_MSC0_DSTE_MSC0_DSTE_UL1_SHFT;
    REG_WRITE(HWIO_MSC0_DSTE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTE.bits.UL1, true);
#endif
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTE_ADDR );
    regValue &= ~HWIO_MSC0_DSTE_MSC0_DSTE_CXMOD_MASK;
    regValue |=  Status<<HWIO_MSC0_DSTE_MSC0_DSTE_CXMOD_SHFT;
    REG_WRITE(HWIO_MSC0_DSTE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTE.bits.CXMOD, Status);
#endif
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DSTE_ADDR );
    regValue &= ~HWIO_MSC0_DSTE_MSC0_DSTE_UL1_MASK;
    regValue |=  false<<HWIO_MSC0_DSTE_MSC0_DSTE_UL1_SHFT;
    REG_WRITE(HWIO_MSC0_DSTE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DSTE.bits.UL1, false);
#endif
}

/**
 * @brief 写MSC 镜像下行数据寄存器低位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteImageDataFrameLow(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DDATM_ADDR );
    regValue &= ~HWIO_MSC0_DDATM_MSC0_DDATM_DDLM_MASK;
    regValue |=  Data<<HWIO_MSC0_DDATM_MSC0_DDATM_DDLM_SHFT;
    REG_WRITE(HWIO_MSC0_DDATM_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DDATM.bits.DDLM, Data);
#endif
}

/**
 * @brief 写MSC 镜像下行数据寄存器高位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteImageDataFrameHigh(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DDATM_ADDR );
    regValue &= ~HWIO_MSC0_DDATM_MSC0_DDATM_DDHM_MASK;
    regValue |=  Data<<HWIO_MSC0_DDATM_MSC0_DDATM_DDHM_SHFT;
    REG_WRITE(HWIO_MSC0_DDATM_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DDATM.bits.DDHM, Data);
#endif
}

/**
 * @brief 写MSC 下行数据扩展寄存器低位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteExtendDataFrameLow(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DDATE_ADDR );
    regValue &= ~HWIO_MSC0_DDATE_MSC0_DDATE_DDLE_MASK;
    regValue |=  Data<<HWIO_MSC0_DDATE_MSC0_DDATE_DDLE_SHFT;
    REG_WRITE(HWIO_MSC0_DDATE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DDATE.bits.DDLE, Data);
#endif
}

/**
 * @brief 写MSC 下行数据扩展寄存器高位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteExtendDataFrameHigh(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DDATE_ADDR );
    regValue &= ~HWIO_MSC0_DDATE_MSC0_DDATE_DDHE_MASK;
    regValue |=  Data<<HWIO_MSC0_DDATE_MSC0_DDATE_DDHE_SHFT;
    REG_WRITE(HWIO_MSC0_DDATE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DDATE.bits.DDHE, Data);
#endif
}

/**
 * @brief 写MSC 镜像下行命令寄存器低位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteImageCMDFrameLow(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCMDM_ADDR );
    regValue &= ~HWIO_MSC0_DCMDM_MSC0_DCMDM_DCLM_MASK;
    regValue |=  Data<<HWIO_MSC0_DCMDM_MSC0_DCMDM_DCLM_SHFT;
    REG_WRITE(HWIO_MSC0_DCMDM_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCMDM.bits.DCLM, Data);
#endif
}

/**
 * @brief 写MSC 镜像下行命令寄存器高位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteImageCMDFrameHigh(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCMDM_ADDR );
    regValue &= ~HWIO_MSC0_DCMDM_MSC0_DCMDM_DCHM_MASK;
    regValue |=  Data<<HWIO_MSC0_DCMDM_MSC0_DCMDM_DCHM_SHFT;
    REG_WRITE(HWIO_MSC0_DCMDM_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCMDM.bits.DCHM, Data);
#endif
}

/**
 * @brief 写MSC 下行命令扩展寄存器低位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteExtendCMDFrameLow(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCMDE_ADDR );
    regValue &= ~HWIO_MSC0_DCMDE_MSC0_DCMDE_DCLE_MASK;
    regValue |=  Data<<HWIO_MSC0_DCMDE_MSC0_DCMDE_DCLE_SHFT;
    REG_WRITE(HWIO_MSC0_DCMDE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCMDE.bits.DCLE, Data);
#endif
}

/**
 * @brief 写MSC 下行命令扩展寄存器高位
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_WriteExtendCMDFrameHigh(const uint32_t Data)
{
    KF_DRV_MSC_ASSERT((Data >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_DCMDE_ADDR );
    regValue &= ~HWIO_MSC0_DCMDE_MSC0_DCMDE_DCHE_MASK;
    regValue |=  Data<<HWIO_MSC0_DCMDE_MSC0_DCMDE_DCHE_SHFT;
    REG_WRITE(HWIO_MSC0_DCMDE_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_DCMDE.bits.DCHE, Data);
#endif
}

/**
 * @brief 设置MSC 移位时钟低电平持续时间
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetShiftClockLowPeriod(const uint32_t Period)
{
    KF_DRV_MSC_ASSERT((Period >> POS_4_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_ABC_ADDR );
    regValue &= ~HWIO_MSC0_ABC_MSC0_ABC_LOW_MASK;
    regValue |=  Period<<HWIO_MSC0_ABC_MSC0_ABC_LOW_SHFT;
    REG_WRITE(HWIO_MSC0_ABC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_ABC.bits.LOW, Period);
#endif
}

/**
 * @brief 设置MSC 移位时钟高电平持续时间
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetShiftClockHighPeriod(const uint32_t Period)
{
    KF_DRV_MSC_ASSERT((Period >> POS_4_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_ABC_ADDR );
    regValue &= ~HWIO_MSC0_ABC_MSC0_ABC_HIGH_MASK;
    regValue |=  Period<<HWIO_MSC0_ABC_MSC0_ABC_HIGH_SHFT;
    REG_WRITE(HWIO_MSC0_ABC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_ABC.bits.HIGH, Period);
#endif
}

/**
 * @brief 设置MSC 上溢中断节点指针
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetUpOverFlowIntServeceRequest(const Msc_INTServiceRequestType_t ServiceRequest)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_INTSERVICEREQ(ServiceRequest));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_ABC_ADDR );
    regValue &= ~HWIO_MSC0_ABC_MSC0_ABC_OIP_MASK;
    regValue |=  ServiceRequest<<HWIO_MSC0_ABC_MSC0_ABC_OIP_SHFT;
    REG_WRITE(HWIO_MSC0_ABC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_ABC.bits.OIP, ServiceRequest);
#endif
}

/**
 * @brief 设置MSC 上溢中断替代服务请求
 *
 *
 * @param Status
 *        true:SR被选择
 *        false:SR4选择器被选择
 * @retval void
 */
KF_INLINE void Msc_LL_SetUpOverFlowIntSubstitution(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_ABC_ADDR );
    regValue &= ~HWIO_MSC0_ABC_MSC0_ABC_OASR_MASK;
    regValue |=  Status<<HWIO_MSC0_ABC_MSC0_ABC_OASR_SHFT;
    REG_WRITE(HWIO_MSC0_ABC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_ABC.bits.OASR, Status);
#endif
}

/**
 * @brief 设置MSC 异步波特率调节时钟分频
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetABRAClockDivide(const uint32_t Divide)
{
    KF_DRV_MSC_ASSERT((Period >> POS_3_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_ABC_ADDR );
    regValue &= ~HWIO_MSC0_ABC_MSC0_ABC_ABNDVI_MASK;
    regValue |=  Divide<<HWIO_MSC0_ABC_MSC0_ABC_ABNDVI_SHFT;
    REG_WRITE(HWIO_MSC0_ABC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_ABC.bits.ABNDVI, Divide);
#endif
}

/**
 * @brief 设置MSC 下溢中断节点指针
 *
 *
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Msc_LL_SetDowntOverFlowIntServeceRequest(const Msc_INTServiceRequestType_t ServiceRequest)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_INTSERVICEREQ(ServiceRequest));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_ABC_ADDR );
    regValue &= ~HWIO_MSC0_ABC_MSC0_ABC_UIP_MASK;
    regValue |=  ServiceRequest<<HWIO_MSC0_ABC_MSC0_ABC_UIP_SHFT;
    REG_WRITE(HWIO_MSC0_ABC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_ABC.bits.UIP, ServiceRequest);
#endif
}

/**
 * @brief 设置MSC 下溢中断替代服务请求
 *
 *
 * @param Status
 *        true:SR被选择
 *        false:SR4选择器被选择
 * @retval void
 */
KF_INLINE void Msc_LL_SetDownOverFlowIntSubstitution(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_ABC_ADDR );
    regValue &= ~HWIO_MSC0_ABC_MSC0_ABC_UASR_MASK;
    regValue |=  Status<<HWIO_MSC0_ABC_MSC0_ABC_UASR_SHFT;
    REG_WRITE(HWIO_MSC0_ABC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_ABC.bits.UASR, Status);
#endif
}

/**
 * @brief 设置MSC 异步波特率调节时钟源
 *
 *
 * @param Msc_ABRAClockSourceType_t
 *        NONE_CLOCK
 *        FPER_CLOCK
 * @retval void
 */
KF_INLINE void Msc_LL_SetABRAClockSource(const Msc_ABRAClockSourceType_t ClockSource)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_ABRACLOCKSOURCE(ClockSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_ABC_ADDR );
    regValue &= ~HWIO_MSC0_ABC_MSC0_ABC_CLKSEL_MASK;
    regValue |=  ClockSource<<HWIO_MSC0_ABC_MSC0_ABC_CLKSEL_SHFT;
    REG_WRITE(HWIO_MSC0_ABC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_ABC.bits.CLKSEL, ClockSource);
#endif
}

/**
 * @brief 使能MSC 异步波特率调节模块
 *
 *
 * @param bool
 *        true:使能异步波特率条件模块
 *        false:禁止异步波特率条件模块
 * @retval void
 */
KF_INLINE void Msc_LL_EnableABRA(const bool Status)
{
    KF_DRV_MSC_ASSERT(CHECK_MSC_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_MSC0_ABC_ADDR );
    regValue &= ~HWIO_MSC0_ABC_MSC0_ABC_ABEN_MASK;
    regValue |=  Status<<HWIO_MSC0_ABC_MSC0_ABC_ABEN_SHFT;
    REG_WRITE(HWIO_MSC0_ABC_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(MSC_PTR->MSC_ABC.bits.ABEN, Status);
#endif
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
