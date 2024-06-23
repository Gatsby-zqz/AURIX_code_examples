/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_psi5.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-18
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
 *  |2023-12-18  |V1.0     |Zhang Quanzhen  | New Creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_PSI5_H_
#define KF32A13K_DRV_PSI5_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_psi5.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_PSI5_ASSERT
#include "dev_assert.h"
#define KF_DRV_PSI5_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_PSI5_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
extern "C" {
#endif
// TODO:
/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    PSI5_NOSUSPEND,
    PSI5_HARDSUSPEND,
    PSI5_SOFTSUSPEND
} Psi5_SuspendMode_t;

#define CHECK_PSI5_SUSPENDMODE(Mode)                                                                                   \
    ((Mode == PSI5_NOSUSPEND) || (Mode == PSI5_HARDSUSPEND) || (Mode == PSI5_SOFTSUSPEND))

typedef enum
{
    PSI5_CHANNEL_0,
    PSI5_CHANNEL_1,
    PSI5_CHANNEL_2
} Psi5_ChannelType_t;

#define CHECK_PSI5_CHANNEL(Channel)                                                                                    \
    ((Channel == PSI5_CHANNEL_0) || (Channel == PSI5_CHANNEL_1) || (Channel == PSI5_CHANNEL_2))

typedef enum
{
    PSI5_TRIGGERCHANNEL_0,
    PSI5_TRIGGERCHANNEL_1,
    PSI5_TRIGGERCHANNEL_2,
    PSI5_TRIGGERCHANNEL_3,
    PSI5_TRIGGERCHANNEL_4
} Psi5_TriggerChannelType_t;

#define CHECK_PSI5_TRIGGERCHANNEL(Channel)                                                                             \
    ((Channel == PSI5_TRIGGERCHANNEL_0) || (Channel == PSI5_TRIGGERCHANNEL_1) || (Channel == PSI5_TRIGGERCHANNEL_2) || \
     (Channel == PSI5_TRIGGERCHANNEL_3) || ((Channel == PSI5_TRIGGERCHANNEL_4)))

typedef enum
{
    PSI5_ACCESS_ENABLE_0,
    PSI5_ACCESS_ENABLE_1,
    PSI5_ACCESS_ENABLE_2,
    PSI5_ACCESS_ENABLE_3,
    PSI5_ACCESS_ENABLE_4,
    PSI5_ACCESS_ENABLE_5,
    PSI5_ACCESS_ENABLE_6,
    PSI5_ACCESS_ENABLE_7,
    PSI5_ACCESS_ENABLE_8,
    PSI5_ACCESS_ENABLE_9,
    PSI5_ACCESS_ENABLE_10,
    PSI5_ACCESS_ENABLE_11,
    PSI5_ACCESS_ENABLE_12,
    PSI5_ACCESS_ENABLE_13,
    PSI5_ACCESS_ENABLE_14,
    PSI5_ACCESS_ENABLE_15,
    PSI5_ACCESS_ENABLE_16,
    PSI5_ACCESS_ENABLE_17,
    PSI5_ACCESS_ENABLE_18,
    PSI5_ACCESS_ENABLE_19,
    PSI5_ACCESS_ENABLE_20,
    PSI5_ACCESS_ENABLE_21,
    PSI5_ACCESS_ENABLE_22,
    PSI5_ACCESS_ENABLE_23,
    PSI5_ACCESS_ENABLE_24,
    PSI5_ACCESS_ENABLE_25,
    PSI5_ACCESS_ENABLE_26,
    PSI5_ACCESS_ENABLE_27,
    PSI5_ACCESS_ENABLE_28,
    PSI5_ACCESS_ENABLE_29,
    PSI5_ACCESS_ENABLE_30,
    PSI5_ACCESS_ENABLE_31
} Psi5_AccessEnableType_t;

#define CHECK_PSI5_ACCESSENABLE(AccessEnable) ((AccessEnable >> POS_19_SHIFT) == 0U)

typedef enum
{
    PSI5_CLOSE_DIVISION,
    PSI5_INTEGER_DIVISION,
    PSI5_FRACTION_DIVISION,
} Psi5_DivisionModeType_t;

#define CHECK_PSI5_DIVISIONMODE(DivMode)                                                                               \
    ((DivMode == PSI5_CLOSE_DIVISION) || (DivModee == PSI5_INTEGER_DIVISION) || (DivMode == PSI5_FRACTION_DIVISION))

typedef enum
{
    PSI5_TIMESTAMP_A,
    PSI5_TIMESTAMP_B,
    PSI5_TIMESTAMP_C
} Psi5_TimeStampChannel_t;

#define CHECK_PSI5_TIMESTAMP(TimeStamp)                                                                                \
    ((TimeStamp == PSI5_TIMESTAMP_A) || (TimeStamp == PSI5_TIMESTAMP_B) || (TimeStamp == PSI5_TIMESTAMP_C))

typedef enum
{
    PSI5_TIMERBASE_TRIG0,
    PSI5_TIMERBASE_TRIG1,
    PSI5_TIMERBASE_TRIG2,
    PSI5_TIMERBASE_TRIG3,
    PSI5_TIMERBASE_TRIG4,
    PSI5_TIMERBASE_TRIG5
} Psi5_ExternalTimerBaseType_t;

#define CHECK_PSI5_EXTERNALTIMEBASE(TimeBase)                                                                          \
    ((TimeBase == PSI5_TIMERBASE_TRIG0) || (TimeBase == PSI5_TIMERBASE_TRIG1) || (TimeBase == PSI5_TIMERBASE_TRIG2) || \
     (TimeBase == PSI5_TIMERBASE_TRIG3) || (TimeBase == PSI5_TIMERBASE_TRIG4) || (TimeBase == PSI5_TIMERBASE_TRIG5))

typedef enum
{
    PSI5_TRIG0,
    PSI5_TRIG1,
    PSI5_TRIG2,
    PSI5_TRIG3,
    PSI5_TRIG4,
    PSI5_TRIG5
} Psi5_ExternalTriggerType_t;

#define CHECK_PSI5_EXTERNALTRIGGER(ExternalTrigger)                                                                    \
    ((ExternalTrigger == PSI5_TRIG0) || (ExternalTrigger == PSI5_TRIG1) || (ExternalTrigger == PSI5_TRIG2) ||          \
     (ExternalTrigger == PSI5_TRIG3) || (ExternalTrigger == PSI5_TRIG4) || (ExternalTrigger == PSI5_TRIG5))

typedef enum
{
    PSI5_TIMERBASE_INTERNAL,
    PSI5_TIMERBASE_EXTERNAL
} Psi5_TimerBaseType_t;

#define CHECK_PSI5_TIMERBASE(TimerBase)                                                                                \
    ((TimerBase == PSI5_TIMERBASE_INTERNAL) || (TimerBase == PSI5_TIMERBASE_EXTERNAL))

typedef enum
{
    PSI5_SOURCE_CRCIF = 0x00000001U,
    PSI5_SOURCE_NBIF  = 0x00000002U,
    PSI5_SOURCE_MEIF  = 0x00000004U,
    PSI5_SOURCE_NFIF  = 0x00000008U,
    PSI5_SOURCE_TEIF  = 0x00000010U
} Psi5_RSIFSourceType_t;

#define CHECK_PSI5_RSIFSOURCE(RsifSource)                                                                              \
    ((RsifSource == PSI5_SOURCE_CRCIF) || (RsifSource == PSI5_SOURCE_NBIF) || (RsifSource == PSI5_SOURCE_MEIF) ||      \
     (RsifSource == PSI5_SOURCE_NFIF) || (RsifSource == PSI5_SOURCE_TEIF))

typedef enum
{
    PSI5_TEIF,
    PSI5_NFIF,
    PSI5_NBIF,
    PSI5_MEIF,
    PSI5_CRCIF,
    PSI5_RUIF,
    PSI5_RMIF,
    PSI5_WSIF,
    PSI5_SOIF,
    PSI5_SCRIF
} Psi5_ErrorFlagType_t;

#define CHECK_PSI5_ERRORFLAG(ErrorFlag)                                                                                \
    ((ErrorFlag == PSI5_TEIF) || (ErrorFlag == PSI5_NFIF) || (ErrorFlag == PSI5_NBIF) || (ErrorFlag == PSI5_MEIF) ||   \
     (ErrorFlag == PSI5_CRCIF) || (ErrorFlag == PSI5_RUIF) || (ErrorFlag == PSI5_RMIF) || (ErrorFlag == PSI5_WSIF) ||  \
     (ErrorFlag == PSI5_SOIF) || (ErrorFlag == PSI5_SCRIF))

typedef enum
{
    PSI5_TEIE,
    PSI5_NFIE,
    PSI5_NBIE,
    PSI5_MEIE,
    PSI5_CRCIE,
    PSI5_RUIE,
    PSI5_RMIE,
    PSI5_WSIE,
    PSI5_SOIE,
    PSI5_SCRIE
} Psi5_ErrorIntType_t;

#define CHECK_PSI5_ERRORINT(ErrorInt)                                                                                  \
    ((ErrorInt == PSI5_TEIE) || (ErrorInt == PSI5_NFIE) || (ErrorInt == PSI5_NBIE) || (ErrorInt == PSI5_MEIE) ||       \
     (ErrorInt == PSI5_CRCIE) || (ErrorInt == PSI5_RUIE) || (ErrorInt == PSI5_RMIE) || (ErrorInt == PSI5_WSIE) ||      \
     (ErrorInt == PSI5_SOIE) || (ErrorInt == PSI5_SCRIE))

typedef enum
{
    PSI5_RSIF,
    PSI5_RDIF,
    PSI5_RBIF,
    PSI5_TDIF,
    PSI5_TBIF,
    PSI5_ERRIF,
    PSI5_SDIF,
    PSI5_FWIF
} Psi5_FlagType_t;

#define CHECK_PSI5_FLAG(Flag)                                                                                          \
    ((Flag == PSI5_RSIF) || (Flag == PSI5_RDIF) || (Flag == PSI5_RBIF) || (Flag == PSI5_TDIF) ||                       \
     (Flag == PSI5_TBIF) || (Flag == PSI5_ERRIF) || (Flag == PSI5_SDIF) || (Flag == PSI5_FWIF))

typedef enum
{
    PSI5_ERRIE,
    PSI5_RSIE,
    PSI5_RDIE,
    PSI5_RBIE,
    PSI5_SDIE,
    PSI5_FWIE,
    PSI5_TBIE,
    PSI5_TDIE
} Psi5_IntType_t;

#define CHECK_PSI5_INT(Int)                                                                                            \
    ((Int == PSI5_ERRIE) || (Int == PSI5_RSIE) || (Int == PSI5_RDIE) || (Int == PSI5_RBIE) || (Int == PSI5_SDIE) ||    \
     (Int == PSI5_FWIE) || (Int == PSI5_TBIE) || (Int == PSI5_TDIE))

typedef enum
{
    ALTERNATEINPUT_0,
    ALTERNATEINPUT_1,
    ALTERNATEINPUT_2,
    ALTERNATEINPUT_3
} Psi5_AlternateInputType_t;

#define CHECK_PSI5_ALTINPUT(AlterInput)                                                                                \
    ((AlterInput == ALTERNATEINPUT_0) || (AlterInput == ALTERNATEINPUT_1) || (AlterInput == ALTERNATEINPUT_2) ||       \
     (AlterInput == ALTERNATEINPUT_3))

typedef enum
{
    FRAME_INDEX_0,
    FRAME_INDEX_1,
    FRAME_INDEX_2,
    FRAME_INDEX_3,
    FRAME_INDEX_4,
    FRAME_INDEX_5
} Psi5_FrameIndexType_t;

#define CHECK_PSI5_FRAMEINDEX(Index)                                                                                   \
    ((Index == FRAME_INDEX_0) || (Index == FRAME_INDEX_1) || (Index == FRAME_INDEX_2) || (Index == FRAME_INDEX_3) ||   \
     (Index == FRAME_INDEX_4) || (Index == FRAME_INDEX_5))

typedef enum
{
    PARITY_CHECK_1_1BIT,
    CRC_CHECK_2_3BIT
} Psi5_ParityCheckModeType_t;

#define CHECK_PSI5_PARITYMODE(CheckMode) ((CheckMode == PARITY_CHECK_1_1BIT) || (CheckMode == CRC_CHECK_2_3BIT))

typedef enum
{
    BAUDRATE_F125,
    BAUDRATE_F189,
} Psi5_BaudRateType_t;

#define CHECK_PSI5_BAUDRATETYPE(BaudrateType) ((BaudrateType == BAUDRATE_F125) || (BaudrateType == BAUDRATE_F189))

typedef enum
{
    PULSE_TIMESTAMP,
    FRAMESTART_TIMESTAMP_C
} Psi5_TimeStampType_t;

#define CHECK_PSI5_TIMESTAMPTYPE(TimeStamp) ((TimeStamp == PULSE_TIMESTAMP) || (TimeStamp == FRAMESTART_TIMESTAMP_C))

typedef enum
{
    PSI5_WDT_0,
    PSI5_WDT_1,
    PSI5_WDT_2,
    PSI5_WDT_3,
    PSI5_WDT_4,
    PSI5_WDT_5,
    PSI5_WDT_6
} Psi5_WDTChannel_t;

#define CHECK_PSI5_WDTCHANNEL(WDTChannel) ((WDTChannel >> POS_3_SHIFT) == 0U)

typedef enum
{
    MSG12_ID8,
    MSG16_ID4
} Psi5_SerialFrameModeType_t;

#define CHECK_PSI5_SERIALFRAMEMODE(Mode) ((Mode == MSG12_ID8) || (Mode == MSG16_ID4))

typedef enum
{
    PULSE_TIMERBASE_INTERNAL,
    PULSE_TIMERBASE_EXTERNAL
} Psi5_PulseTimerBaseType_t;

#define CHECK_PSI5_PULSETIMERBASE(TimerBase)                                                                           \
    ((TimerBase == PULSE_TIMERBASE_INTERNAL) || (TimerBase == PULSE_TIMERBASE_EXTERNAL))

typedef enum
{
    PULSE_VERSION_1_3,
    PULSE_VERSION_2_0
} Psi5_VersionType_t;

#define CHECK_PSI5_VERSION(Version) ((Version == PULSE_VERSION_1_3) || (Version == PULSE_VERSION_2_0))

typedef enum
{
    TRIGO_0,
    TRIGO_1,
    TRIGO_2,
    TRIGO_3,
    TRIGO_4,
    TRIGO_5,
    TRIGO_6,
    TRIGO_7
} Psi5_IntNodeType_t;

#define CHECK_PSI5_INTNODE(Node)                                                                                       \
    ((Node == TRIGO_0) || (Node == TRIGO_1) || (Node == TRIGO_2) || (Node == TRIGO_3) || (Node == TRIGO_4) ||          \
     (Node == TRIGO_5) || (Node == TRIGO_6) || (Node == TRIGO_7))

typedef enum
{
    PSI5_STATE_RSIF,
    PSI5_STATE_RDIF,
    PSI5_STATE_RBIF,
    PSI5_STATE_TEIF,
    PSI5_STATE_NBIF,
    PSI5_STATE_MEIF,
    PSI5_STATE_CRCIF,
    PSI5_STATE_FWIF,
    PSI5_STATE_RUIF,
    PSI5_STATE_RMIF,
    PSI5_STATE_TPIF,
    PSI5_STATE_TPOIF,
    PSI5_STATE_TSIF,
    PSI5_STATE_TSOIF,
    PSI5_STATE_TOIF,
    PSI5_STATE_TOOIF,
    PSI5_STATE_NFIF
} Psi5_IntStateType_t;

#define CHECK_PSI5_INTSTATE(State)                                                                                     \
    ((State == PSI5_STATE_RSIF) || (State == PSI5_STATE_RDIF) || (State == PSI5_STATE_RBIF) ||                         \
     (State == PSI5_STATE_TEIF) || (State == PSI5_STATE_NBIF) || (State == PSI5_STATE_MEIF) ||                         \
     (State == PSI5_STATE_CRCIF) || (State == PSI5_STATE_FWIF) || (State == PSI5_STATE_RUIF) ||                        \
     (State == PSI5_STATE_RMIF) || (State == PSI5_STATE_TPIF) || (State == PSI5_STATE_TPOIF) ||                        \
     (State == PSI5_STATE_TSIF) || (State == PSI5_STATE_TSOIF) || (State == PSI5_STATE_TOIF) ||                        \
     (State == PSI5_STATE_TOOIF) || (State == PSI5_STATE_NFIF))

typedef enum
{
    PSI5_SERIALSTATE_WSIF,
    PSI5_SERIALSTATE_SDIF,
    PSI5_SERIALSTATE_SOIF,
    PSI5_SERIALSTATE_SCRIF
} Psi5_SerialIntStateType_t;

#define CHECK_PSI5_SERIALINTSTATE(State)                                                                               \
    ((State == PSI5_SERIALSTATE_WSIF) || (State == PSI5_SERIALSTATE_SDIF) || (State == PSI5_SERIALSTATE_SOIF) ||       \
     (State == PSI5_SERIALSTATE_SCRIF))

typedef enum
{
    PSI5_INDEX_0,
    PSI5_INDEX_1,
    PSI5_INDEX_2,
    PSI5_INDEX_3,
    PSI5_INDEX_4,
    PSI5_INDEX_5,
    PSI5_INDEX_6,
    PSI5_INDEX_7,
    PSI5_INDEX_8,
    PSI5_INDEX_9,
    PSI5_INDEX_10,
    PSI5_INDEX_11,
    PSI5_INDEX_12,
    PSI5_INDEX_13,
    PSI5_INDEX_14,
    PSI5_INDEX_15,
    PSI5_INDEX_16,
    PSI5_INDEX_17,
    PSI5_INDEX_18,
    PSI5_INDEX_19,
    PSI5_INDEX_20,
    PSI5_INDEX_21,
    PSI5_INDEX_22,
    PSI5_INDEX_23,
    PSI5_INDEX_24,
    PSI5_INDEX_25,
    PSI5_INDEX_26,
    PSI5_INDEX_27,
    PSI5_INDEX_28,
    PSI5_INDEX_29,
    PSI5_INDEX_30,
    PSI5_INDEX_31
} Psi5_FifoIndex_t;

#define CHECK_PSI5_FifoINDEX(FifoIndex) ((FifoIndex >> POS_5_SHIFT) == 0U)
#define CHECK_PSI5_BOOL(Bool)           ((Bool >> POS_1_SHIFT) == 0U)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief 禁止PSI5模块
 *
 *
 * @param Status
 *        true:禁止模块
 *        false:使能模块
 * @retval void
 */
KF_INLINE void Psi5_LL_DisableModule(const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_CLKC.bits.DISR, Status);
}

/**
 * @brief 获取PSI5模块状态
 *
 *
 * @param void
 * @retval bool
 *         true:模块已禁止
 *         false:模块已使能
 */
KF_INLINE bool Psi5_LL_GetModuleState(void)
{
    return (REG_READ(PSI5_GENERAL_PTR->PSI5_CLKC.bits.DISS));
}

/**
 * @brief 设置PSI5模块进入休眠模式
 *
 *
 * @param Status
 *        true:使能休眠模式
 *        false:禁止休眠模式
 * @retval void
 */
KF_INLINE void Psi5_LL_SetModuleSleep(const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_CLKC.bits.EDIS, Status);
}

/**
 * @brief 设置PSI5调试挂起模式
 *
 *
 * @param SuspendMode
 *        PSI5_NOSUSPEND
 *        PSI5_HARDSUSPEND
 *        PSI5_SOFTSUSPEND
 * @retval void
 */
KF_INLINE void Psi5_LL_SetDubugSuspendMode(Psi5_SuspendMode_t SuspendMode)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_SUSPENDMODE(SuspendMode));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_DBG.bits.DBGP, true);
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_DBG.bits.DBGCTL, SuspendMode);
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_DBG.bits.DBGP, false);
}

/**
 * @brief 获取PSI5调试挂起模式
 *
 *
 * @param  void
 * @retval Psi5_SuspendMode_t
 *         PSI5_NOSUSPEND
 *         PSI5_HARDSUSPEND
 *         PSI5_SOFTSUSPEND
 */
KF_INLINE Psi5_SuspendMode_t Psi5_LL_GetDubugSuspendMode(void)
{
    return ((Psi5_SuspendMode_t)REG_READ(PSI5_GENERAL_PTR->PSI5_DBG.bits.DBGCTL));
}

/**
 * @brief 获取PSI5调试挂起状态
 *
 *
 * @param void
 * @retval bool
 *         true:当前模块被挂起
 *         false:当前模块未被挂起
 */
KF_INLINE bool Psi5_LL_GetSuspendState(void)
{
    return (REG_READ(PSI5_GENERAL_PTR->PSI5_DBG.bits.DBGSTA));
}

/**
 * @brief 设置PSI5进入复位状态
 *
 *
 * @param Status
 *         true:发起模块复位请求
 *         false:不发起模块复位请求
 * @retval void
 */
KF_INLINE void Psi5_LL_ResetModule(const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_RST0.bits.RST, Status);
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_RST1.bits.RST, Status);
}

/**
 * @brief 获取PSI5复位状态
 *
 *
 * @param void
 * @retval Status
 *         true:模块已经被复位
 *         false:模块没有被复位
 */
KF_INLINE bool Psi5_LL_GetResetState(void)
{
    return (REG_READ(PSI5_GENERAL_PTR->PSI5_RST0.bits.RSTSTA));
}

/**
 * @brief 使能PSI5访问控制
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval void
 */
KF_INLINE void Psi5_LL_EnableAccess(Psi5_AccessEnableType_t AccessEnable)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_ACCESSENABLE(AccessEnable));
    REG_BIT_SET(PSI5_GENERAL_PTR->PSI5_ACES0.reg, MASK_1_BIT << AccessEnable);
}

/**
 * @brief 获取PSI5访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE bool Psi5_LL_GetAccess(Psi5_AccessEnableType_t AccessEnable)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_ACCESSENABLE(AccessEnable));
    return ((PSI5_GENERAL_PTR->PSI5_ACES0.reg, MASK_1_BIT << AccessEnable, AccessEnable));
}

/**
 * @brief 获取PSI5模块版本信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetModuleVersion(void)
{
    return (REG_READ(PSI5_GENERAL_PTR->PSI5_INFO.bits.MODREV));
}

/**
 * @brief 获取PSI5模块类型信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetModuleType(void)
{
    return (REG_READ(PSI5_GENERAL_PTR->PSI5_INFO.bits.MODTYPE));
}

/**
 * @brief 获取PSI5模块ID信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetModuleId(void)
{
    return (REG_READ(PSI5_GENERAL_PTR->PSI5_INFO.bits.MODNUM));
}

/**
 * @brief 设置PSI5分数时钟分频值
 *
 *
 * @param PreScale
 * @retval void
 */
KF_INLINE void Psi5_LL_SetClockPres(const uint32_t PreScale)
{
    KF_DRV_PSI5_ASSERT((PreScale >> POS_10_SHIFT) == 0U);
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_FDRT.bits.STEP, PreScale);
}

/**
 * @brief 设置PSI5分频模式
 *
 *
 * @param DivisionMode
 * @retval void
 */
KF_INLINE void Psi5_LL_SetClockPresMode(const Psi5_DivisionModeType_t DivisionMode)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_DIVISIONMODE(DivisionMode));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_FDRT.bits.DVIMOD, DivisionMode);
}

/**
 * @brief 设置PSI5额外结果值
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetClockResult(void)
{
    return (REG_READ(PSI5_GENERAL_PTR->PSI5_FDRT.bits.RESULT));
}

/**
 * @brief 设置PSI5时间戳外部清除源
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE void Psi5_LL_SetExternalTimeStampClearSource(Psi5_ExternalTriggerType_t ExternalTrigger)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_EXTERNALTRIGGER(ExternalTrigger));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_FDRT.bits.ECS, ExternalTrigger);
}

/**
 * @brief 设置PSI5时间戳A外部清除使能
 *
 *
 * @param Status
 *        true:使能时间戳A的外部清除使能
 *        false:禁止时间戳A的外部清除使能
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableExternalTimeStampAClear(const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_FDRT.bits.ECEA, Status);
}

/**
 * @brief 设置PSI5时间戳B外部清除使能
 *
 *
 * @param TimeStampChannel
 *        PSI5_TIMESTAMP_A
 *        PSI5_TIMESTAMP_B
 *        PSI5_TIMESTAMP_C
 * @param Status
 *        true:使能时间戳B的外部清除使能
 *        false:禁止时间戳B的外部清除使能
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableExternalTimeStampClear(Psi5_TimeStampChannel_t TimeStampChannel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TIMESTAMP(TimeStampChannel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    REG_BITS_WRITE(PSI5_GENERAL_PTR->PSI5_FDRT.reg, (true << (POS_29_SHIFT + TimeStampChannel)),
                   (Status << (POS_29_SHIFT + TimeStampChannel)));
}

/**
 * @brief 获取PSI5指定时间戳的当前计数值
 *
 *
 * @param TimeStampChannel
 *        PSI5_TIMESTAMP_A
 *        PSI5_TIMESTAMP_B
 *        PSI5_TIMESTAMP_C
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetCurrentTimeStamp(const Psi5_TimeStampChannel_t TimeStampChannel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TIMESTAMP(TimeStampChannel));
    return (REG_READ(PSI5_GENERAL_PTR->PSI5_TSR[TimeStampChannel].bits.CTS));
}

/**
 * @brief 设置PSI5指定时间戳的外部计数时基
 *
 *
 * @param TimeStampChannel
 *        PSI5_TIMESTAMP_A
 *        PSI5_TIMESTAMP_B
 *        PSI5_TIMESTAMP_C
 * @param ExternalTimerBase
 *        PSI5_TIMERBASE_TRIG0
 *        PSI5_TIMERBASE_TRIG1
 *        PSI5_TIMERBASE_TRIG2
 *        PSI5_TIMERBASE_TRIG3
 *        PSI5_TIMERBASE_TRIG4
 *        PSI5_TIMERBASE_TRIG5
 * @retval void
 */
KF_INLINE void Psi5_LL_SetExternalTimerBase(
  const Psi5_TimeStampChannel_t TimeStampChannel, Psi5_ExternalTimerBaseType_t ExternalTimerBase)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TIMESTAMP(TimeStampChannel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_EXTERNALTIMEBASE(ExternalTimerBase));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_TSR[TimeStampChannel].bits.ETBSEL, ExternalTimerBase);
}

/**
 * @brief 设置PSI5指定时间戳的计数时基
 *
 *
 * @param TimeStampChannel
 *        PSI5_TIMESTAMP_A
 *        PSI5_TIMESTAMP_B
 *        PSI5_TIMESTAMP_C
 * @param TimerBase
 *        PSI5_TIMERBASE_INTERNAL
 *        PSI5_TIMERBASE_EXTERNAL
 * @retval void
 */
KF_INLINE void Psi5_LL_SetCountTimerBase(const Psi5_TimeStampChannel_t TimeStampChannel, Psi5_TimerBaseType_t TimerBase)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TIMERBASE(TimerBase));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TIMESTAMP(TimeStampChannel));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_TSR[TimeStampChannel].bits.TBSEL, TimerBase);
}

/**
 * @brief 清除PSI5指定时间戳的计数值
 *
 *
 * @param TimeStampChannel
 *        PSI5_TIMESTAMP_A
 *        PSI5_TIMESTAMP_B
 *        PSI5_TIMESTAMP_C
 * @param bool
 *        true:清空指定通道的时间戳计数值
 *        false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearTimerCount(const Psi5_TimeStampChannel_t TimeStampChannel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TIMESTAMP(TimeStampChannel));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_TSR[TimeStampChannel].bits.TSCLR, Status);
}

/**
 * @brief 设置PSI5RSIF 源标志位
 *
 *
 * @param RSIFSource
 *        PSI5_SOURCE_CRCIF
 *        PSI5_SOURCE_NBIF
 *        PSI5_SOURCE_MEIF
 *        PSI5_SOURCE_NFIF
 *        PSI5_SOURCE_TEIF
 * @retval void
 */
KF_INLINE void Psi5_LL_SetRSIFSource(const Psi5_RSIFSourceType_t RSIFSource)
{
    // TODO:需确认手册描述内容是否正确,更倾向于选择ERRIF
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_RSIFSOURCE(RSIFSource));
    REG_WRITE(PSI5_GENERAL_PTR->PSI5_GCTL.bits.RSIFSOURCE, RSIFSource);
}

/**
 * @brief 使能PSI5RSIF 通道触发器
 *
 *
 * @param TriggerChannel
 *        PSI5_TRIGGERCHANNEL_0
 *        PSI5_TRIGGERCHANNEL_1
 *        PSI5_TRIGGERCHANNEL_2
 *        PSI5_TRIGGERCHANNEL_3
 *        PSI5_TRIGGERCHANNEL_4
 * @param Status
 *        true:使能触发器
 *        false:禁止触发器
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableTriggerChannelCount(const Psi5_TriggerChannelType_t TriggerChannel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TRIGGERCHANNEL(TriggerChannel));
    REG_BITS_WRITE(PSI5_GENERAL_PTR->PSI5_GCTL.reg, (MASK_5_BIT << POS_8_OFFSET),
                   ((uint32_t)Status << (TriggerChannel + POS_8_OFFSET)));
}

/**
 * @brief 设置PSI5RSIF 源标志位
 *
 *
 * @param TriggerChannel
 *        PSI5_TRIGGERCHANNEL_0
 *        PSI5_TRIGGERCHANNEL_1
 *        PSI5_TRIGGERCHANNEL_2
 *        PSI5_TRIGGERCHANNEL_3
 *        PSI5_TRIGGERCHANNEL_4
 * @param Status
 *        true:使能触发通道
 *        false:禁止触发通道
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableTriggerChannel(const Psi5_TriggerChannelType_t TriggerChannel, const bool Status)
{
    // TODO:使能触发通道还是通道
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TRIGGERCHANNEL(TriggerChannel));
    REG_BITS_WRITE(PSI5_GENERAL_PTR->PSI5_GCTL.reg, (MASK_5_BIT << POS_16_OFFSET),
                   ((uint32_t)Status << (TriggerChannel + POS_16_OFFSET)));
}

/**
 * @brief 获取PSI5中断标志位
 *
 *
 * @param Flag
 *        PSI5_RSIF
 *        PSI5_RDIF
 *        PSI5_RBIF
 *        PSI5_TDIF
 *        PSI5_TBIF
 *        PSI5_ERRIF
 *        PSI5_SDIF
 *        PSI5_FWIF
 * @retval Status
 *        true:相应标志位置位
 *        false:相应标志位未置位
 */
KF_INLINE bool Psi5_LL_GetFlag(const Psi5_FlagType_t Flag)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FLAG(Flag));
    return (REG_BITS_READ(PSI5_GENERAL_PTR->PSI5_GIF.reg, MASK_1_BIT << Flag, Flag));
}

/**
 * @brief 设置PSI5备用输入选择
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_AlternateInputType_t
 *        ALTERNATEINPUT_0
 *        ALTERNATEINPUT_1
 *        ALTERNATEINPUT_2
 *        ALTERNATEINPUT_3
 * @retval void
 */
KF_INLINE void Psi5_LL_SetAlterInput(Psi5_ChannelType_t Channel, const Psi5_AlternateInputType_t Input)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_ALTINPUT(Input));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_IOCTL.bits.INSEL, Input);
}

/**
 * @brief 设置PSI5数字滤波器深度
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Psi5_LL_SetDigitalFiltertDepth(Psi5_ChannelType_t Channel, const uint32_t Depth)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT((Depth >> POS_4_SHIFT) == 0U);
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_IOCTL.bits.DEPTH, Depth);
}

/**
 * @brief 设置PSI5通道输出反转使能
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:使能输出反转
 *        false:禁止输出反转
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableOutputInversion(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_IOCTL.bits.OPOLSEL, Status);
}

/**
 * @brief 设置PSI5通道输入反转使能
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:使能输入反转
 *        false:禁止输入反转
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableInputInversion(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_IOCTL.bits.IPOLSEL, Status);
}

/**
 * @brief 获取PSI5通道上升沿干扰状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:检测到上升沿干扰
 *        false:未检测到上升沿干扰
 * @retval void
 */
KF_INLINE bool Psi5_LL_GetRaiseEdgeInterference(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_IOCTL.bits.REGF));
}

/**
 * @brief 获取PSI5通道下降沿干扰状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:检测到下降沿干扰
 *        false:未检测到下降沿干扰
 * @retval void
 */
KF_INLINE bool Psi5_LL_GetFallEdgeInterference(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_IOCTL.bits.FEGF));
}

/**
 * @brief 清除PSI5通道上升沿干扰状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:清除上升沿干扰状态
 *        false:不清除上升沿干扰状态
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearRaiseEdgeInterference(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_IOCTL.bits.CREGF, Status);
}

/**
 * @brief 清除PSI5通道下降沿干扰状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:清除下降沿干扰状态
 *        false:不清除下降沿干扰状态
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearFallEdgeInterference(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_IOCTL.bits.CREGF, Status);
}

/**
 * @brief 获取PSI5通道接收状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 *         true:当前电流信号为高
 *         false:当前电流信号为底
 */
KF_INLINE bool Psi5_LL_GetReceiveState(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_IOCTL.bits.RXM));
}

/**
 * @brief 获取PSI5通道发送状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 *         true:当前电流信号为高
 *         false:当前电流信号为底
 */
KF_INLINE bool Psi5_LL_GetSendState(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_IOCTL.bits.TXM));
}

/**
 * @brief 设置PSI5负载数据长度
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *        FRAME_INDEX_0
 *        FRAME_INDEX_1
 *        FRAME_INDEX_2
 *        FRAME_INDEX_3
 *        FRAME_INDEX_4
 *        FRAME_INDEX_5
 * @param DataLength
 * @retval void
 */
KF_INLINE void Psi5_LL_SetReceivePayloadDataLength(
  Psi5_ChannelType_t Channel, const Psi5_FrameIndexType_t FrameIndex, const uint32_t DataLength)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    KF_DRV_PSI5_ASSERT((DataLength >> POS_5_SHIFT) == 0U);
    REG_BITS_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLA.reg, MASK_5_BIT << (FrameIndex * POS_5_SHIFT),
                   DataLength << (FrameIndex * POS_5_SHIFT));
}

/**
 * @brief 使能PSI5异步模式
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:使能异步模式
 *        false:关闭异步模式
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableAsynMode(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLA.bits.ASYNEN, Status);
}

/**
 * @brief 使能PSI5异步模式的冗余模式
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:使能异步模式的冗余模式
 *        false:关闭异步模式的冗余模式
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableAsynRedundanceMode(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLA.bits.AVBSEN, Status);
}

/**
 * @brief 使能PSI5的消息位
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *        FRAME_INDEX_0 
 *        FRAME_INDEX_1 
 *        FRAME_INDEX_2 
 *        FRAME_INDEX_3 
 *        FRAME_INDEX_4
 *        FRAME_INDEX_5
 * @param Status
 *        true:使能1~2bit消息位
 *        false:无消息位
 * @retval void
 */
KF_INLINE void
Psi5_LL_EnableMsgBit(Psi5_ChannelType_t Channel, const Psi5_FrameIndexType_t FrameIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    REG_BITS_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLB.reg, MASK_1_BIT << (FrameIndex * POS_4_SHIFT),
                   Status << (FrameIndex * POS_4_SHIFT));
}

/**
 * @brief 设置PSI5奇偶校验模式
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *        FRAME_INDEX_0 
 *        FRAME_INDEX_1 
 *        FRAME_INDEX_2 
 *        FRAME_INDEX_3 
 *        FRAME_INDEX_4
 *        FRAME_INDEX_5
 * @param Psi5_ParityCheckModeType_t
 *        PARITY_CHECK_1_1BIT
 *        CRC_CHECK_2_3BIT
 * @retval void
 */
KF_INLINE void Psi5_LL_SetParityCheckMode(
  Psi5_ChannelType_t Channel, const Psi5_FrameIndexType_t FrameIndex, const Psi5_ParityCheckModeType_t ParityCheckMode)
{
    // TODO:不确定置一清零和具体模式的匹配关系
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_PARITYMODE(ParityCheckMode));
    REG_BITS_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLB.reg, MASK_1_BIT << (FrameIndex * POS_4_SHIFT + POS_1_OFFSET),
                   ParityCheckMode << (FrameIndex * POS_4_SHIFT + POS_1_OFFSET));
}

/**
 * @brief 使能PSI5帧期待设置
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *        FRAME_INDEX_0 
 *        FRAME_INDEX_1 
 *        FRAME_INDEX_2 
 *        FRAME_INDEX_3 
 *        FRAME_INDEX_4
 *        FRAME_INDEX_5
 * @param Status
 *        ture:一个帧被期待
 *        false:无消息被期待
 * @retval void
 */
KF_INLINE void
Psi5_LL_SetFrameException(Psi5_ChannelType_t Channel, const Psi5_FrameIndexType_t FrameIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    REG_BITS_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLB.reg, MASK_1_BIT << (FrameIndex * POS_4_SHIFT + POS_2_OFFSET),
                   Status << (FrameIndex * POS_4_SHIFT + POS_2_OFFSET));
}

/**
 * @brief 使能PSI5冗余模式
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *        FRAME_INDEX_0 
 *        FRAME_INDEX_1 
 *        FRAME_INDEX_2 
 *        FRAME_INDEX_3 
 *        FRAME_INDEX_4
 *        FRAME_INDEX_5
 * @param Status
 *        ture:开启
 *        false:保留
 * @retval void
 */
KF_INLINE void
Psi5_LL_SetRedundanceMode(Psi5_ChannelType_t Channel, const Psi5_FrameIndexType_t FrameIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    REG_BITS_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLB.reg, MASK_1_BIT << (FrameIndex * POS_4_SHIFT + POS_3_OFFSET),
                   Status << (FrameIndex * POS_4_SHIFT + POS_3_OFFSET));
}

/**
 * @brief 选择PSI5比特速率
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_BaudRateType_t
 *        BAUDRATE_F125
 *        BAUDRATE_F189
 * @retval void
 */
KF_INLINE void Psi5_LL_SetBuadRateSource(Psi5_ChannelType_t Channel, const Psi5_BaudRateType_t BaudRateType)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BAUDRATETYPE(BaudRateType));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLC.bits.BRSEL, BaudRateType);
}

/**
 * @brief 选择PSI5脉冲时间戳
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_BaudRateType_t
 *        PSI5_TIMESTAMP_A
 *        PSI5_TIMESTAMP_B
 *        PSI5_TIMESTAMP_C
 * @retval void
 */
KF_INLINE void Psi5_LL_SetPulseTimeStamp(Psi5_ChannelType_t Channel, const Psi5_TimeStampChannel_t TimeStampChannel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TIMESTAMP(TimeStampChannel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLC.bits.TSPSEL, TimeStampChannel);
}

/**
 * @brief 选择PSI5帧起始时间戳
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_BaudRateType_t
 *        PSI5_TIMESTAMP_A
 *        PSI5_TIMESTAMP_B
 *        PSI5_TIMESTAMP_C
 * @retval void
 */
KF_INLINE void
Psi5_LL_SetFrameStartTimeStamp(Psi5_ChannelType_t Channel, const Psi5_TimeStampChannel_t TimeStampChannel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TIMESTAMP(TimeStampChannel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLC.bits.TSFSEL, TimeStampChannel);
}

/**
 * @brief 选择PSI5接收数据存储时间戳
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_TimeStampType_t
 *        PULSE_TIMESTAMP:脉冲时间戳存储在接收数据中
 *        FRAMESTART_TIMESTAMP_C:帧起始时间戳存储在接收数据中
 * @retval void
 */
KF_INLINE void Psi5_LL_SeStampStore(Psi5_ChannelType_t Channel, const Psi5_TimeStampType_t TimeStampType)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_TIMESTAMPTYPE(TimeStampType));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_RCTLC.bits.TSRSEL, TimeStampType);
}

/**
 * @brief 选择PSI5看门狗定时门限值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_WDTChannel_t
 *        PSI5_WDT_0
 *        PSI5_WDT_1
 *        PSI5_WDT_2
 *        PSI5_WDT_3
 *        PSI5_WDT_4
 *        PSI5_WDT_5
 *        PSI5_WDT_6
 * @param Threshold:通道看门狗定时器限制值
 * @retval void
 */
KF_INLINE void
Psi5_LL_SetWDTThreshold(Psi5_ChannelType_t Channel, Psi5_WDTChannel_t WDTChannel, const uint32_t Threshold)
{
    // TODO:不确定WDTChannel具体代表含义
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_WDTCHANNEL(WDTChannel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_WDT[WDTChannel].reg, Threshold);
}

/**
 * @brief 获取PSI5上一帧CRC值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t:上一帧CRC值
 */
KF_INLINE uint32_t Psi5_LL_GetPreviousFrameCRC(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_REVSTA.bits.CRC));
}

/**
 * @brief 获取PSI5上一帧MSG值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t:上一帧MSG值
 */
KF_INLINE uint32_t Psi5_LL_GetPreviousFrameMsg(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_REVSTA.bits.MSG));
}

/**
 * @brief 获取PSI5串行消息MSG DATA
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *        FRAME_INDEX_0
 *        FRAME_INDEX_1
 *        FRAME_INDEX_2
 *        FRAME_INDEX_3
 *        FRAME_INDEX_4
 *        FRAME_INDEX_5
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetPreviousSerialFrameMsgData(Psi5_ChannelType_t Channel, Psi5_FrameIndexType_t FrameIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    return ((Psi5_SerialFrameModeType_t)REG_READ((PSI5_IO_PTR + Channel)->PSI5_SDSTA[FrameIndex].bits.SD));
}

/**
 * @brief 获取PSI5串行消息MSG ID
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *        FRAME_INDEX_0
 *        FRAME_INDEX_1
 *        FRAME_INDEX_2
 *        FRAME_INDEX_3
 *        FRAME_INDEX_4
 *        FRAME_INDEX_5
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetPreviousSerialFrameMsgID(Psi5_ChannelType_t Channel, Psi5_FrameIndexType_t FrameIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    return ((Psi5_SerialFrameModeType_t)REG_READ((PSI5_IO_PTR + Channel)->PSI5_SDSTA[FrameIndex].bits.MSGID));
}

/**
 * @brief 获取PSI5串行消息CRC
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *        FRAME_INDEX_0
 *        FRAME_INDEX_1
 *        FRAME_INDEX_2
 *        FRAME_INDEX_3
 *        FRAME_INDEX_4
 *        FRAME_INDEX_5
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetPreviousSerialFrameCRC(Psi5_ChannelType_t Channel, Psi5_FrameIndexType_t FrameIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    return ((Psi5_SerialFrameModeType_t)REG_READ((PSI5_IO_PTR + Channel)->PSI5_SDSTA[FrameIndex].bits.SCRC));
}

/**
 * @brief 获取PSI5串行消息CRC校验失败中断标志
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *        FRAME_INDEX_0
 *        FRAME_INDEX_1
 *        FRAME_INDEX_2
 *        FRAME_INDEX_3
 *        FRAME_INDEX_4
 *        FRAME_INDEX_5
 * @retval bool
 *         true:串行数据CRC校验失败
 *         false:串行数据CRC校验成功
 */
KF_INLINE bool Psi5_LL_GetPreviousSerialFrameCRCFlag(Psi5_ChannelType_t Channel, Psi5_FrameIndexType_t FrameIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    return ((Psi5_SerialFrameModeType_t)REG_READ((PSI5_IO_PTR + Channel)->PSI5_SDSTA[FrameIndex].bits.SCRIF));
}

/**
 * @brief 获取PSI5上一帧串行帧配置模式
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *        FRAME_INDEX_0
 *        FRAME_INDEX_1
 *        FRAME_INDEX_2
 *        FRAME_INDEX_3
 *        FRAME_INDEX_4
 *        FRAME_INDEX_5
 * @retval Psi5_SerialFrameModeType_t
 *        MSG12_ID8:12bit数据和8bit消息ID
 *        MSG16_ID4:16bit数据和4bit消息ID
 */
KF_INLINE Psi5_SerialFrameModeType_t
Psi5_LL_GetPreviousSerialFrameType(Psi5_ChannelType_t Channel, Psi5_FrameIndexType_t FrameIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    return ((Psi5_SerialFrameModeType_t)REG_READ((PSI5_IO_PTR + Channel)->PSI5_SDSTA[FrameIndex].bits.CON));
}

/**
 * @brief 获取PSI5脉冲时间戳值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetPulseTimeStamp(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_SPTSC.bits.TS));
}

/**
 * @brief 获取PSI5帧起始时间戳值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetFrameStartTimeStamp(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_SFTSC.bits.TS));
}

/**
 * @brief 获取PSI5接收数据
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetReceiveData(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_RDATL.bits.RD));
}

/**
 * @brief 获取PSI5接收CRC
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetReceiveCRC(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_RDATL.bits.CRC));
}

/**
 * @brief 获取PSI5接收CRC校验标志
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetReceiveCRCFlag(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_RDATL.bits.CRCIF));
}

/**
 * @brief 获取PSI5接收消息时间戳
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetReceiveTimeStamp(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_RDATH.bits.TS));
}

/**
 * @brief 获取PSI5接收消息SLOT计数值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetReceiveSlotCount(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_RDATH.bits.SC));
}

/**
 * @brief 获取PSI5接收消息时间槽错误标志
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetReceiveTEIF(Psi5_ChannelType_t Channel)
{
    // TODO:此项和GIF标志位关系
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_RDATH.bits.TEIF));
}

/**
 * @brief 获取PSI5接收消息位错误标志
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetReceiveNBIF(Psi5_ChannelType_t Channel)
{
    // TODO:此项和GIF标志位关系
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_RDATH.bits.NBIF));
}

/**
 * @brief 获取PSI5接收消息位错误标志
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetReceiveMEIF(Psi5_ChannelType_t Channel)
{
    // TODO:此项和GIF标志位关系
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_RDATH.bits.MEIF));
}

/**
 * @brief 获取PSI5接收无帧接收标志
 *
 *
*  * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetReceiveNFIF(Psi5_ChannelType_t Channel)
{
    // TODO:此项和GIF标志位关系
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_RDATH.bits.NFIF));
}

/**
 * @brief 获取PSI5接收缓冲器溢出标志
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetReceiveRBIF(Psi5_ChannelType_t Channel)
{
    // TODO:此项和GIF标志位关系
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_RDATH.bits.RBIF));
}

/**
 * @brief 获取PSI5脉冲长度
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetPusleLength(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_PCTRL.bits.PLEN));
}

/**
 * @brief 获取PSI5脉冲延迟长度
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetPusleDelay(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_PCTRL.bits.DLY));
}

/**
 * @brief 获取PSI5脉冲时基
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval Psi5_PulseTimerBaseType_t
 *        PULSE_TIMERBASE_INTERNAL
 *        PULSE_TIMERBASE_EXTERNAL
 */
KF_INLINE Psi5_PulseTimerBaseType_t Psi5_LL_GetPusleTimerBase(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return ((Psi5_PulseTimerBaseType_t)REG_READ((PSI5_IO_PTR + Channel)->PSI5_PCTRL.bits.TBSEL));
}

/**
 * @brief 设置PSI5脉冲时基
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param TimerBase
 *        PULSE_TIMERBASE_INTERNAL
 *        PULSE_TIMERBASE_EXTERNAL
 * @retval void
 */
KF_INLINE void Psi5_LL_SetPusleTimerBase(Psi5_ChannelType_t Channel, const Psi5_PulseTimerBaseType_t TimerBase)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_PULSETIMERBASE(TimerBase));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_PCTRL.bits.TBSEL, TimerBase);
}

/**
 * @brief 设置PSI5脉冲外部时基
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param TimerBase
 *        PSI5_TIMERBASE_TRIG0
 *        PSI5_TIMERBASE_TRIG1
 *        PSI5_TIMERBASE_TRIG2
 *        PSI5_TIMERBASE_TRIG3
 *        PSI5_TIMERBASE_TRIG4
 *        PSI5_TIMERBASE_TRIG5
 * @retval void
 */
KF_INLINE void
Psi5_LL_SetPusleExternalTimerBase(Psi5_ChannelType_t Channel, const Psi5_ExternalTimerBaseType_t ExternalTimerBase)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_EXTERNALTIMEBASE(ExternalTimerBase));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_PCTRL.bits.ETBSEL, ExternalTimerBase);
}

/**
 * @brief 设置PSI5脉冲周期触发
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:使能周期触发
 *        false:禁止周期触发
 * @retval void
 */
KF_INLINE void Psi5_LL_EnablePuslePeriodTrigger(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_PCTRL.bits.PTEN, Status);
}

/**
 * @brief 设置PSI5脉冲外部触发源
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_ExternalTriggerType_t
 *        PSI5_TRIG0
 *        PSI5_TRIG1
 *        PSI5_TRIG2
 *        PSI5_TRIG3
 *        PSI5_TRIG4
 *        PSI5_TRIG5
 * @retval void
 */
KF_INLINE void Psi5_LL_SetExternalPulseTriggerSource(
  Psi5_ChannelType_t Channel, const Psi5_ExternalTriggerType_t ExternalTriggerSource)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_EXTERNALTRIGGER(ExternalTriggerSource));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_PCTRL.bits.ETSEL, ExternalTriggerSource);
}

/**
 * @brief 使能PSI5脉冲外部触发
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:使能外部触发
 *        false:禁止外部触发
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableExternalPulseTrigger(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_PCTRL.bits.ETEN, Status);
}

/**
 * @brief 使能PSI5外部信号
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:使能外部信号
 *        false:禁止外部信号
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableExternalSignal(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_PCTRL.bits.BYP, Status);
}

/**
 * @brief 设置PSI5空白时间
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param IdleTime:空白时间单位(TTS)
 * @retval void
 */
KF_INLINE void Psi5_LL_SetIdleTime(Psi5_ChannelType_t Channel, const uint32_t IdleTime)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT((IdleTime >> POS_7_SHIFT) == 0U);
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_PCTRL.bits.BOT, IdleTime);
}

/**
 * @brief 设置PSI5通道触发值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Count
 * @retval void
 */
KF_INLINE void Psi5_LL_SetTriggerValue(Psi5_ChannelType_t Channel, const uint32_t Count)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT((Count >> POS_16_SHIFT) == 0U);
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_CTV.bits.CTV, Count);
}

/**
 * @brief 获取PSI5通道触发值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetTriggerValue(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_CTV.bits.CTV));
}

/**
 * @brief 设置PSI5通道当前触发器计数值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Count
 * @retval void
 */
KF_INLINE void Psi5_LL_SetCurrentTriggerCount(Psi5_ChannelType_t Channel, const uint32_t Count)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT((Count >> POS_16_SHIFT) == 0U);
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_CTV.bits.CTCNT, Count);
}

/**
 * @brief 获取PSI5通道当前触发器计数值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetCurrentTriggerCount(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_CTV.bits.CTCNT));
}

/**
 * @brief 设置PSI5发送负载数据长度
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param DataLength
 * @retval void
 */
KF_INLINE void Psi5_LL_SetSendloadDataLength(Psi5_ChannelType_t Channel, const uint32_t DataLength)
{
    // TODO:PLLEN和SSLEN关系
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT((DataLength >> POS_6_SHIFT) == 0U);
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.PLLEN, DataLength);
}

/**
 * @brief 获取PSI5发送负载数据长度
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetSendloadDataLength(Psi5_ChannelType_t Channel)
{
    // TODO:PLLEN和SSLEN关系
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.PLLEN));
}

/**
 * @brief 设置PSI5发送帧协议类型
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_VersionType_t
 *        PULSE_VERSION_1_3
 *        PULSE_VERSION_2_0
 * @retval void
 */
KF_INLINE void Psi5_LL_SetSendFrameVersion(Psi5_ChannelType_t Channel, const Psi5_VersionType_t Version)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_VERSION(Version));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.EPSEL, Version);
}
/**
 * @brief 设置PSI5发送帧同步控制
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:使能自动同步位插入
 *        false:禁止自动同步位插入
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableSendFrameSynControl(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.BSCTL, Status);
}

/**
 * @brief 设置PSI5有效负载长度
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param DataLength
 * @retval void
 */
KF_INLINE void Psi5_LL_SetSendPayloadDataLength(Psi5_ChannelType_t Channel, const uint32_t DataLength)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT((DataLength >> POS_6_SHIFT) == 0U);
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.SSLEN, DataLength);
}

/**
 * @brief 获取PSI5有效负载长度
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetSendPayloadDataLength(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.SSLEN));
}

/**
 * @brief 刷新PSI5移位寄存器
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:刷新移位寄存器
 *        false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_RefreshShiftReg(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.FLUS, Status);
}

/**
 * @brief 刷新PSI5输出低位寄存器
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:刷新输出低位寄存器
 *        false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_RefreshOutPutLowReg(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.FLUO, Status);
}

/**
 * @brief 获取PSI5 SSO寄存器中有效负载长度
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetSendSOLength(Psi5_ChannelType_t Channel)
{
    // TODO:SSOL寄存器是哪个寄存器
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.SOLEN));
}

/**
 * @brief 设置PSI5 发送帧的CRC自动生成
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:硬件自动生成CRC值
 *        false:硬件不会自动生成CRC值
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableCRCAutoGen(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.CRCCTRL, Status);
}

/**
 * @brief 设置PSI5 发送帧的起始序列自动生成
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:硬件自动生成起始序列
 *        false:硬件不会自动生成起始序列
 * @retval void
 */
KF_INLINE void Psi5_LL_EnableStartSeqAutoGen(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.STACTRL, Status);
}

/**
 * @brief 设置PSI5 发送帧的禁止传输
 *
     *
     * @param Psi5_ChannelType_t
     *        PSI5_CHANNEL_0
    *        PSI5_CHANNEL_1
     *        PSI5_CHANNEL_2
 * @param Status
 *        true:使能自动传输
 *        false:禁止自动传输
 * @retval void
 */
KF_INLINE void Psi5_LL_ProhibitTransmit(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.INH, Status);
}

/**
 * @brief 设置PSI5 释放数据
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Status
 *        true:开始传输
 *        false:禁止传输
 * @retval void
 */
KF_INLINE void Psi5_LL_ReleaseData(Psi5_ChannelType_t Channel, const bool Status)
{
    // TODO:手册表意不明
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.GO, Status);
}

/**
 * @brief 获取PSI5 传输准备标志位
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetSendPreparationFlag(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.TPF));
}

/**
 * @brief 获取PSI5 传输移位标志位
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetSendShiftFlag(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.TSF));
}

/**
 * @brief 获取PSI5 传输移位标志位
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetSendOutPut(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.TOF));
}

/**
 * @brief 获取PSI5 传输移位标志位
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 *         true:传输正在进行中
 *         false:传输没有在进行中
 */
KF_INLINE bool Psi5_LL_AcceptSendRequest(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ((PSI5_IO_PTR + Channel)->PSI5_SCTL.bits.TRQ));
}

/**
 * @brief 写PSI5 发送数据低位寄存器
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Data
 * @retval void
 */
KF_INLINE void Psi5_LL_WriteSendDataLow(Psi5_ChannelType_t Channel, uint32_t Data)
{
    // MARK:需要根据实际数据传输格式确定函数书写形式
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SDRL.reg, Data);
}

/**
 * @brief 写PSI5 发送数据低位寄存器
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Data
 * @retval void
 */
KF_INLINE void Psi5_LL_WriteSendDataHigh(Psi5_ChannelType_t Channel, uint32_t Data)
{
    // MARK:需要根据实际数据传输格式确定函数书写形式
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SDRH.reg, Data);
}

/**
 * @brief 写PSI5 发送移位低位寄存器
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Data
 * @retval void
 */
KF_INLINE void Psi5_LL_WriteShiftDataLow(Psi5_ChannelType_t Channel, uint32_t Data)
{
    // MARK:需要根据实际数据传输格式确定函数书写形式
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SSRL.reg, Data);
}

/**
 * @brief 写PSI5 发送移位高位寄存器
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Data
 * @retval void
 */
KF_INLINE void Psi5_LL_WriteShiftDataHigh(Psi5_ChannelType_t Channel, uint32_t Data)
{
    // MARK:需要根据实际数据传输格式确定函数书写形式
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SSRH.reg, Data);
}

/**
 * @brief 写PSI5 发送输出低位寄存器
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Data
 * @retval void
 */
KF_INLINE void Psi5_LL_WriteOutputDataLow(Psi5_ChannelType_t Channel, uint32_t Data)
{
    // MARK:需要根据实际数据传输格式确定函数书写形式
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SORL.reg, Data);
}

/**
 * @brief 写PSI5 发送输出高位寄存器
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Data
 * @retval void
 */
KF_INLINE void Psi5_LL_WriteOutputDataHigh(Psi5_ChannelType_t Channel, uint32_t Data)
{
    // MARK:需要根据实际数据传输格式确定函数书写形式
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE((PSI5_IO_PTR + Channel)->PSI5_SORH.reg, Data);
}

/**
 * @brief 获取PSI5 中断节点
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FlagType_t
 *        PSI5_RSIF
 *        PSI5_RDIF
 *        PSI5_RBIF
 *        PSI5_TDIF
 *        PSI5_TBIF
 *        PSI5_ERRIF
 *        PSI5_SDIF
 *        PSI5_FWIF
 * @retval Psi5_IntNodeType_t
 *         TRIGO_0
 *         TRIGO_1
 *         TRIGO_2
 *         TRIGO_3
 *         TRIGO_4
 *         TRIGO_5
 *         TRIGO_6
 *         TRIGO_7
 */
KF_INLINE Psi5_IntNodeType_t Psi5_LL_GetIntNode(Psi5_ChannelType_t Channel, const Psi5_FlagType_t Flag)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FLAG(Flag));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return ((Psi5_IntNodeType_t)REG_BITS_READ(
      PSI5_CTL_PTR->PSI5_INP[Channel].reg, MASK_4_BIT << (POS_4_SHIFT * Flag), POS_4_SHIFT * Flag));
}

/**
 * @brief 获取PSI5 中断状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_IntStateType_t
 *        PSI5_STATE_RSIF
 *        PSI5_STATE_RDIF
 *        PSI5_STATE_RBIF
 *        PSI5_STATE_TEIF
 *        PSI5_STATE_NBIF
 *        PSI5_STATE_MEIF
 *        PSI5_STATE_CRCIF
 *        PSI5_STATE_FWIF
 *        PSI5_STATE_RUIF
 *        PSI5_STATE_RMIF
 *        PSI5_STATE_TPIF
 *        PSI5_STATE_TPOIF
 *        PSI5_STATE_TSIF
 *        PSI5_STATE_TSOIF
 *        PSI5_STATE_TOIF
 *        PSI5_STATE_TOOIF
 *        PSI5_STATE_NEIF
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetIntState(Psi5_ChannelType_t Channel, const Psi5_IntStateType_t IntState)
{
    // TODO:和中断的关系
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_INTSTATE(IntState));
    return (REG_BITS_READ(PSI5_CTL_PTR->PSI5_IF1[Channel].reg, MASK_1_BIT << IntState, IntState));
}

/**
 * @brief 获取PSI5 串行数据中断状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *       FRAME_INDEX_0
 *       FRAME_INDEX_1
 *       FRAME_INDEX_2
 *       FRAME_INDEX_3
 *       FRAME_INDEX_4
 *       FRAME_INDEX_5
 * @param Psi5_SerialIntStateType_t
 *       PSI5_SERIALSTATE_WSIF
 *       PSI5_SERIALSTATE_SDIF
 *       PSI5_SERIALSTATE_SOIF
 *       PSI5_SERIALSTATE_SCRIF
 * @retval bool
 */
KF_INLINE bool Psi5_LL_GetSerialIntState(
  Psi5_ChannelType_t Channel, const Psi5_FrameIndexType_t FrameIndex, const Psi5_SerialIntStateType_t SerialIntState)
{
    // TODO:和中断的关系
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_SERIALINTSTATE(SerialIntState));
    return (REG_BITS_READ(
      PSI5_CTL_PTR->PSI5_IF2[Channel].reg, MASK_1_BIT << (SerialIntState * POS_6_SHIFT + FrameIndex),
      (SerialIntState * POS_6_SHIFT + FrameIndex)));
}

/**
 * @brief 设置PSI5 中断状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_IntStateType_t
 *        PSI5_STATE_RSIF
 *        PSI5_STATE_RDIF
 *        PSI5_STATE_RBIF
 *        PSI5_STATE_TEIF
 *        PSI5_STATE_NBIF
 *        PSI5_STATE_MEIF
 *        PSI5_STATE_CRCIF
 *        PSI5_STATE_FWIF
 *        PSI5_STATE_RUIF
 *        PSI5_STATE_RMIF
 *        PSI5_STATE_TPIF
 *        PSI5_STATE_TPOIF
 *        PSI5_STATE_TSIF
 *        PSI5_STATE_TSOIF
 *        PSI5_STATE_TOIF
 *        PSI5_STATE_TOOIF
 *        PSI5_STATE_NEIF
 * @param bool
 *        true:相应标志位置一
 *        false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetIntState(Psi5_ChannelType_t Channel, const Psi5_IntStateType_t IntState, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_INTSTATE(IntState));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_IS1[Channel].reg, MASK_1_BIT << IntState, (uint32_t)Status << IntState);
}

/**
 * @brief 设置PSI5 串行数据中断状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *       FRAME_INDEX_0
 *       FRAME_INDEX_1
 *       FRAME_INDEX_2
 *       FRAME_INDEX_3
 *       FRAME_INDEX_4
 *       FRAME_INDEX_5
 * @param Psi5_SerialIntStateType_t
 *       PSI5_SERIALSTATE_WSIF
 *       PSI5_SERIALSTATE_SDIF
 *       PSI5_SERIALSTATE_SOIF
 *       PSI5_SERIALSTATE_SCRIF
 * @param bool
 *        true:相应标志位置一
 *        false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetSerialIntState(Psi5_ChannelType_t Channel, const Psi5_FrameIndexType_t FrameIndex,
                                         const Psi5_SerialIntStateType_t SerialIntState, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_SERIALINTSTATE(SerialIntState));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_IS2[Channel].reg, MASK_1_BIT << (SerialIntState * POS_6_SHIFT + FrameIndex),
                   Status << (SerialIntState * POS_6_SHIFT + FrameIndex));
}

/**
 * @brief 清除PSI5 中断状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_IntStateType_t
 *        PSI5_STATE_RSIF
 *        PSI5_STATE_RDIF
 *        PSI5_STATE_RBIF
 *        PSI5_STATE_TEIF
 *        PSI5_STATE_NBIF
 *        PSI5_STATE_MEIF
 *        PSI5_STATE_CRCIF
 *        PSI5_STATE_FWIF
 *        PSI5_STATE_RUIF
 *        PSI5_STATE_RMIF
 *        PSI5_STATE_TPIF
 *        PSI5_STATE_TPOIF
 *        PSI5_STATE_TSIF
 *        PSI5_STATE_TSOIF
 *        PSI5_STATE_TOIF
 *        PSI5_STATE_TOOIF
 *        PSI5_STATE_NEIF
 * @param bool
 *        true:清除相应标志位
 *        false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearIntState(Psi5_ChannelType_t Channel, const Psi5_IntStateType_t IntState, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_INTSTATE(IntState));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_IC1[Channel].reg, MASK_1_BIT << IntState, (uint32_t)Status << IntState);
}

/**
 * @brief 清除PSI5 串行数据中断状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *       FRAME_INDEX_0
 *       FRAME_INDEX_1
 *       FRAME_INDEX_2
 *       FRAME_INDEX_3
 *       FRAME_INDEX_4
 *       FRAME_INDEX_5
 * @param Psi5_SerialIntStateType_t
 *       PSI5_SERIALSTATE_WSIF
 *       PSI5_SERIALSTATE_SDIF
 *       PSI5_SERIALSTATE_SOIF
 *       PSI5_SERIALSTATE_SCRIF
 * @param bool
 *        true:清除相应标志位
 *        false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearSerialIntState(
  Psi5_ChannelType_t Channel, const Psi5_FrameIndexType_t FrameIndex, const Psi5_SerialIntStateType_t SerialIntState,
  const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_SERIALINTSTATE(SerialIntState));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_IC2[Channel].reg, MASK_1_BIT << (SerialIntState * POS_6_SHIFT + FrameIndex),
                   Status << (SerialIntState * POS_6_SHIFT + FrameIndex));
}

/**
 * @brief 设置PSI5 相应中断标志位中断
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_IntStateType_t
 *        PSI5_STATE_RSIF
 *        PSI5_STATE_RDIF
 *        PSI5_STATE_RBIF
 *        PSI5_STATE_TEIF
 *        PSI5_STATE_NBIF
 *        PSI5_STATE_MEIF
 *        PSI5_STATE_CRCIF
 *        PSI5_STATE_FWIF
 *        PSI5_STATE_RUIF
 *        PSI5_STATE_RMIF
 *        PSI5_STATE_TPIF
 *        PSI5_STATE_TPOIF
 *        PSI5_STATE_TSIF
 *        PSI5_STATE_TSOIF
 *        PSI5_STATE_TOIF
 *        PSI5_STATE_TOOIF
 *        PSI5_STATE_NEIF
 * @param bool
 *        true:使能相应标志位中断
 *        false:禁止相应标志位中断
 * @retval void
 */
KF_INLINE void Psi5_LL_SetIntRequest(Psi5_ChannelType_t Channel, const Psi5_IntStateType_t IntState, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_INTSTATE(IntState));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_IE1[Channel].reg, MASK_1_BIT << IntState, (uint32_t)Status << IntState);
}

/**
 * @brief 设置PSI5 串行数据中断状态
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FrameIndexType_t
 *       FRAME_INDEX_0
 *       FRAME_INDEX_1
 *       FRAME_INDEX_2
 *       FRAME_INDEX_3
 *       FRAME_INDEX_4
 *       FRAME_INDEX_5
 * @param Psi5_SerialIntStateType_t
 *       PSI5_SERIALSTATE_WSIF
 *       PSI5_SERIALSTATE_SDIF
 *       PSI5_SERIALSTATE_SOIF
 *       PSI5_SERIALSTATE_SCRIF
 * @param bool
 *        true:清除相应标志位
 *        false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetSerialIntRequest(
  Psi5_ChannelType_t Channel, const Psi5_FrameIndexType_t FrameIndex, const Psi5_SerialIntStateType_t SerialIntState,
  const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FRAMEINDEX(FrameIndex));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_SERIALINTSTATE(SerialIntState));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_IE2[Channel].reg, MASK_1_BIT << (SerialIntState * POS_6_SHIFT + FrameIndex),
                   Status << (SerialIntState * POS_6_SHIFT + FrameIndex));
}

/**
 * @brief 获取PSI5 接收Fifo读指针
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetRxFifoReadPointer(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ(PSI5_CTL_PTR->PSI5_RFCTL[Channel].bits.FRP));
}

/**
 * @brief 获取PSI5 接收Fifo写指针
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetRxFifoWritePointer(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ(PSI5_CTL_PTR->PSI5_RFCTL[Channel].bits.FWP));
}

/**
 * @brief 设置PSI5 接收Fifo警告等级
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param uint32_t
 * @retval void
 */
KF_INLINE void Psi5_LL_SetRxFifoWarnLevel(Psi5_ChannelType_t Channel, const uint32_t WarnLevel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT((WarnLevel >> POS_5_SHIFT) == 0U);
    REG_WRITE(PSI5_CTL_PTR->PSI5_RFCTL[Channel].bits.FWL, WarnLevel);
}

/**
 * @brief 获取PSI5 接收Fifo警告等级
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_GetRxFifoWarnLevel(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ(PSI5_CTL_PTR->PSI5_RFCTL[Channel].bits.FWL));
}

/**
 * @brief 获取PSI5 接收Fifo警告等级
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 *         true:写指针超前读指针一圈
 *         false:读指针超前写指针一圈
 */
KF_INLINE bool Psi5_LL_GetRxFifoCircle(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ(PSI5_CTL_PTR->PSI5_RFCTL[Channel].bits.WRAP));
}

/**
 * @brief 获取PSI5 多次溢出标志位
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval bool
 *         true:累积发生三次RMIF
 *         false:未累积发生三次RMIF
 */
KF_INLINE bool Psi5_LL_GetRxFifoFRQ(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ(PSI5_CTL_PTR->PSI5_RFCTL[Channel].bits.FRQ));
}

/**
 * @brief 清空PSI5 RXFifo读写指针及相应标志位
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param bool
 *         true:Fifo 读写指针清零，Fifo 清空且WRAP被清零
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearRxFifoState(Psi5_ChannelType_t Channel, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    REG_WRITE(PSI5_CTL_PTR->PSI5_RFCTL[Channel].bits.FLU, Status);
}

/**
 * @brief 读PSI5 RXFifo数据
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_ReadRxFifoData(Psi5_ChannelType_t Channel)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    return (REG_READ(PSI5_CTL_PTR->PSI5_RDATF[Channel].reg));
}

/**
 * @brief 获取PSI5 RXFifo指定索引RSIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @retval bool
 *         true:RXFifo相应索引位置处的RSIF标志位为1
 *         false:RXFifo相应索引位置处的RSIF标志位为0
 */
KF_INLINE bool Psi5_LL_GetRxFifoRSIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    return (REG_BITS_READ(PSI5_CTL_PTR->PSI5_RSIOV[Channel].reg, MASK_1_BIT << FifoIndex, FifoIndex));
}

/**
 * @brief 获取PSI5 RXFifo指定索引RMIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @retval bool
 *         true:RXFifo相应索引位置处的RMIF标志位为1
 *         false:RXFifo相应索引位置处的RMIF标志位为0
 */
KF_INLINE bool Psi5_LL_GetRxFifoRMIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    return (REG_BITS_READ(PSI5_CTL_PTR->PSI5_RMIOV[Channel].reg, MASK_1_BIT << FifoIndex, FifoIndex));
}

/**
 * @brief 获取PSI5 RXFifo指定索引NBIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @retval bool
 *         true:RXFifo相应索引位置处的NBIF标志位为1
 *         false:RXFifo相应索引位置处的NBIF标志位为0
 */
KF_INLINE bool Psi5_LL_GetRxFifoNBIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    return (REG_BITS_READ(PSI5_CTL_PTR->PSI5_NBIOV[Channel].reg, MASK_1_BIT << FifoIndex, FifoIndex));
}

/**
 * @brief 获取PSI5 RXFifo指定索引TEIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @retval bool
 *         true:RXFifo相应索引位置处的TEIF标志位为1
 *         false:RXFifo相应索引位置处的TEIF标志位为0
 */
KF_INLINE bool Psi5_LL_GetRxFifoTEIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    return (REG_BITS_READ(PSI5_CTL_PTR->PSI5_TEIOV[Channel].reg, MASK_1_BIT << FifoIndex, FifoIndex));
}

/**
 * @brief 获取PSI5 RXFifo指定索引CRCIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @retval bool
 *         true:RXFifo相应索引位置处的CRCIF标志位为1
 *         false:RXFifo相应索引位置处的CRCIF标志位为0
 */
KF_INLINE bool Psi5_LL_GetRxFifoCRCIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    return (REG_BITS_READ(PSI5_CTL_PTR->PSI5_CRCIOV[Channel].reg, MASK_1_BIT << FifoIndex, FifoIndex));
}

/**
 * @brief 获取PSI5 RXFifo指定索引RDIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @retval bool
 *         true:RXFifo相应索引位置处的RDIF标志位为1
 *         false:RXFifo相应索引位置处的RDIF标志位为0
 */
KF_INLINE bool Psi5_LL_GetRxFifoRDIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    return (REG_BITS_READ(PSI5_CTL_PTR->PSI5_RDIOV[Channel].reg, MASK_1_BIT << FifoIndex, FifoIndex));
}

/**
 * @brief 获取PSI5 RXFifo指定索引NFIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @retval bool
 *         true:RXFifo相应索引位置处的NFIF标志位为1
 *         false:RXFifo相应索引位置处的NFIF标志位为0
 */
KF_INLINE bool Psi5_LL_GetRxFifoNFIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    return (REG_BITS_READ(PSI5_CTL_PTR->PSI5_NFIOV[Channel].reg, MASK_1_BIT << FifoIndex, FifoIndex));
}

/**
 * @brief 获取PSI5 RXFifo指定索引MEIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @retval bool
 *         true:RXFifo相应索引位置处的MEIF标志位为1
 *         false:RXFifo相应索引位置处的MEIF标志位为0
 */
KF_INLINE bool Psi5_LL_GetRxFifoMEIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    return (REG_BITS_READ(PSI5_CTL_PTR->PSI5_MEIOV[Channel].reg, MASK_1_BIT << FifoIndex, FifoIndex));
}

/**
 * @brief 设置PSI5 RXFifo指定索引RSIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:设置相应索引处的RXFifo的RSIF标志位为1
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetRxFifoRSIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_RSISET[Channel].reg, MASK_1_BIT << FifoIndex, Status);
}

/**
 * @brief 设置PSI5 RXFifo指定索引RMIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:设置相应索引处的RXFifo的RMIF标志位为1
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetRxFifoRMIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_RMISET[Channel].reg, MASK_1_BIT << FifoIndex, Status);
}

/**
 * @brief 设置PSI5 RXFifo指定索引NBIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:设置相应索引处的RXFifo的NBIF标志位为1
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetRxFifoNBIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_NBISET[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 设置PSI5 RXFifo指定索引TEIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:设置相应索引处的RXFifo的TEIF标志位为1
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetRxFifoTEIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_TEISET[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 设置PSI5 RXFifo指定索引CRCIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:设置相应索引处的RXFifo的CRCIF标志位为1
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetRxFifoCRCIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_CRCISET[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 设置PSI5 RXFifo指定索引RDIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:设置相应索引处的RXFifo的RDIF标志位为1
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetRxFifoRDIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_RDISET[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 设置PSI5 RXFifo指定索引NFIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:设置相应索引处的RXFifo的NFIF标志位为1
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetRxFifoNFIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_NFISET[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 设置PSI5 RXFifo指定索引MEIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:设置相应索引处的RXFifo的MEIF标志位为1
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_SetRxFifoMEIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_MEISET[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 清除PSI5 RXFifo指定索引RSIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:清除相应索引处的RXFifo的RSIF标志位
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearRxFifoRSIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_RSICLR[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 清除PSI5 RXFifo指定索引RMIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:清除相应索引处的RXFifo的RMIF标志位
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearRxFifoRMIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_RMICLR[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 清除PSI5 RXFifo指定索引NBIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:清除相应索引处的RXFifo的NBIF标志位
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearRxFifoNBIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_NBICLR[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 清除PSI5 RXFifo指定索引TEIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:清除相应索引处的RXFifo的NBIF标志位
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearRxFifoTEIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_TEICLR[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 清除PSI5 RXFifo指定索引CRCIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:清除相应索引处的RXFifo的CRCIF标志位
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearRxFifoCRCIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_CRCICLR[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 清除PSI5 RXFifo指定索引RDIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:清除相应索引处的RXFifo的RDIF标志位
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearRxFifoRDIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_RDICLR[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 清除PSI5 RXFifo指定索引NFIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:清除相应索引处的RXFifo的NFIF标志位
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearRxFifoNFIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_NFICLR[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 清除PSI5 RXFifo指定索引MEIF值
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @param bool
 *         true:清除相应索引处的RXFifo的MEIF标志位
 *         false:无影响
 * @retval void
 */
KF_INLINE void Psi5_LL_ClearRxFifoMEIF(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex, const bool Status)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_BOOL(Status));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    REG_BITS_WRITE(PSI5_CTL_PTR->PSI5_MEICLR[Channel].reg, MASK_1_BIT << FifoIndex, (uint32_t)Status << FifoIndex);
}

/**
 * @brief 读取PSI5 RXFifo指定索引接收存储低位寄存器
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_ReadRxFifoDataLow(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    return (REG_READ(PSI5_CTL_PTR->PSI5_RXDATA[Channel][FifoIndex].PSI5_RDML.reg));
}

/**
 * @brief 读取PSI5 RXFifo指定索引接收存储高位寄存器
 *
 *
 * @param Psi5_ChannelType_t
 *        PSI5_CHANNEL_0
 *        PSI5_CHANNEL_1
 *        PSI5_CHANNEL_2
 * @param Psi5_FifoIndex_t
 *        PSI5_INDEX_0
 *        PSI5_INDEX_1
 *        PSI5_INDEX_2
 *        PSI5_INDEX_3
 *        PSI5_INDEX_4
 *        PSI5_INDEX_5
 *        PSI5_INDEX_6
 *        PSI5_INDEX_7
 *        PSI5_INDEX_8
 *        PSI5_INDEX_9
 *        PSI5_INDEX_10
 *        PSI5_INDEX_11
 *        PSI5_INDEX_12
 *        PSI5_INDEX_13
 *        PSI5_INDEX_14
 *        PSI5_INDEX_15
 *        PSI5_INDEX_16
 *        PSI5_INDEX_17
 *        PSI5_INDEX_18
 *        PSI5_INDEX_19
 *        PSI5_INDEX_20
 *        PSI5_INDEX_21
 *        PSI5_INDEX_22
 *        PSI5_INDEX_23
 *        PSI5_INDEX_24
 *        PSI5_INDEX_25
 *        PSI5_INDEX_26
 *        PSI5_INDEX_27
 *        PSI5_INDEX_28
 *        PSI5_INDEX_29
 *        PSI5_INDEX_30
 *        PSI5_INDEX_31
 * @retval uint32_t
 */
KF_INLINE uint32_t Psi5_LL_ReadRxFifoDataHigh(Psi5_ChannelType_t Channel, Psi5_FifoIndex_t FifoIndex)
{
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_CHANNEL(Channel));
    KF_DRV_PSI5_ASSERT(CHECK_PSI5_FifoINDEX(FifoIndex));
    return (REG_READ(PSI5_CTL_PTR->PSI5_RXDATA[Channel][FifoIndex].PSI5_RDMH.reg));
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
