/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_sent.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-14
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
 *  |2023-12-14  |V1.0     |Zhang Quanzhen  | New Creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_SENT_H_
#define KF32A13K_DRV_SENT_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_sent.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_SENT_ASSERT
#include "dev_assert.h"
#define KF_DRV_SENT_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_SENT_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION
#include "kf32a13k_reg_simulation_sent.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    SENT_NOSUSPEND,
    SENT_HARDSUSPEND,
    SENT_SOFTSUSPEND
} Sent_SuspendMode_t;

#define CHECK_SENT_SUSPENDMODE(Mode)                                                                                   \
    ((Mode == SENT_NOSUSPEND) || (Mode == SENT_HARDSUSPEND) || (Mode == SENT_SOFTSUSPEND))

typedef enum
{
    SENT_CHANNEL_0,
    SENT_CHANNEL_1,
    SENT_CHANNEL_2,
    SENT_CHANNEL_3,
    SENT_CHANNEL_4,
    SENT_CHANNEL_5,
    SENT_CHANNEL_6,
    SENT_CHANNEL_7
} Sent_ChannelType_t;

#define CHECK_SENT_CHANNEL(Channel) ((Channel >> POS_3_SHIFT) == 0U)

typedef enum
{
    SENT_ACCESS_ENABLE_0,
    SENT_ACCESS_ENABLE_1,
    SENT_ACCESS_ENABLE_2,
    SENT_ACCESS_ENABLE_3,
    SENT_ACCESS_ENABLE_4,
    SENT_ACCESS_ENABLE_5,
    SENT_ACCESS_ENABLE_6,
    SENT_ACCESS_ENABLE_7,
    SENT_ACCESS_ENABLE_8,
    SENT_ACCESS_ENABLE_9,
    SENT_ACCESS_ENABLE_10,
    SENT_ACCESS_ENABLE_11,
    SENT_ACCESS_ENABLE_12,
    SENT_ACCESS_ENABLE_13,
    SENT_ACCESS_ENABLE_14,
    SENT_ACCESS_ENABLE_15,
    SENT_ACCESS_ENABLE_16,
    SENT_ACCESS_ENABLE_17,
    SENT_ACCESS_ENABLE_18,
    SENT_ACCESS_ENABLE_19,
    SENT_ACCESS_ENABLE_20,
    SENT_ACCESS_ENABLE_21,
    SENT_ACCESS_ENABLE_22,
    SENT_ACCESS_ENABLE_23,
    SENT_ACCESS_ENABLE_24,
    SENT_ACCESS_ENABLE_25,
    SENT_ACCESS_ENABLE_26,
    SENT_ACCESS_ENABLE_27,
    SENT_ACCESS_ENABLE_28,
    SENT_ACCESS_ENABLE_29,
    SENT_ACCESS_ENABLE_30,
    SENT_ACCESS_ENABLE_31
} Sent_AccessEnableType_t;

#define CHECK_SENT_ACCESSENABLE(AccessEnable) ((AccessEnable >> POS_5_SHIFT) == 0U)

typedef enum
{
    SENT_DIVISION_CLOSE_MODE,
    SENT_INTEGER_DIVISION_MODE,
    SENT_FRACTION_DIVISION_MODE
} Sent_DivisionType_t;

#define CHECK_SENT_DIVISION(Division)                                                                                  \
    ((Division == SENT_DIVISION_CLOSE_MODE) || (Division == SENT_INTEGER_DIVISION_MODE) ||                             \
     (Division == SENT_FRACTION_DIVISION_MODE))

typedef enum
{
    SENT_SHORTSERIAL_MODE,
    SENT_ENHANCEDSERIAL_MODE
} Sent_SerialFrameMode_t;

#define CHECK_SENT_SERIALFRAMEMODE(Mode) ((Mode == SENT_SHORTSERIAL_MODE) || (Mode == SENT_ENHANCEDSERIAL_MODE))

typedef enum
{
    SENT_CHANNEL_STOP,
    SENT_CHANNEL_INIT,
    SENT_CHANNEL_RUNNING,
    SENT_CHANNEL_SYN
} Sent_ChannelState_t;

#define CHECK_SENT_CHANNELSTATE(Status) ((Status >> POS_2_SHIFT) == 0U)

typedef enum
{
    SENT_HALFBYTEPOINTER_MASK0 = 0x00000007,
    SENT_HALFBYTEPOINTER_MASK1 = 0x00000070,
    SENT_HALFBYTEPOINTER_MASK2 = 0x00000700,
    SENT_HALFBYTEPOINTER_MASK3 = 0x00007000,
    SENT_HALFBYTEPOINTER_MASK4 = 0x00070000,
    SENT_HALFBYTEPOINTER_MASK5 = 0x00700000,
    SENT_HALFBYTEPOINTER_MASK6 = 0x07000000,
    SENT_HALFBYTEPOINTER_MASK7 = 0x70000000
} Sent_HalfBytePointerMask_t;

#define CHECK_SENT_HALFBYTEPOINTERMASK(PointerMask)                                                                    \
    ((PointerMask == SENT_HALFBYTEPOINTER_MASK0) || (PointerMask == SENT_HALFBYTEPOINTER_MASK1) ||                     \
     (PointerMask == SENT_HALFBYTEPOINTER_MASK2) || (PointerMask == SENT_HALFBYTEPOINTER_MASK3) ||                     \
     (PointerMask == SENT_HALFBYTEPOINTER_MASK4) || (PointerMask == SENT_HALFBYTEPOINTER_MASK5) ||                     \
     (PointerMask == SENT_HALFBYTEPOINTER_MASK6) || (PointerMask == SENT_HALFBYTEPOINTER_MASK7))

typedef enum
{
    SENT_HALFBYTEPOINTER_INDEX0,
    SENT_HALFBYTEPOINTER_INDEX1,
    SENT_HALFBYTEPOINTER_INDEX2,
    SENT_HALFBYTEPOINTER_INDEX3,
    SENT_HALFBYTEPOINTER_INDEX4,
    SENT_HALFBYTEPOINTER_INDEX5,
    SENT_HALFBYTEPOINTER_INDEX6,
    SENT_HALFBYTEPOINTER_INDEX7
} Sent_HalfBytePointerIndex_t;

#define CHECK_SENT_HALFBYTEINDEX(Index) ((Index >> POS_3_SHIFT) == 0U)

typedef enum
{
    SENT_HALFBYTE_MASK0 = 0x0000000F,
    SENT_HALFBYTE_MASK1 = 0x000000F0,
    SENT_HALFBYTE_MASK2 = 0x00000F00,
    SENT_HALFBYTE_MASK3 = 0x0000F000,
    SENT_HALFBYTE_MASK4 = 0x000F0000,
    SENT_HALFBYTE_MASK5 = 0x00F00000,
    SENT_HALFBYTE_MASK6 = 0x0F000000,
    SENT_HALFBYTE_MASK7 = 0xF0000000
} Sent_HalfByteMask_t;

#define CHECK_SENT_HALFBYTEMASK(Mask)                                                                                  \
    ((Mask == SENT_HALFBYTE_MASK0) || (Mask == SENT_HALFBYTE_MASK1) || (Mask == SENT_HALFBYTE_MASK2) ||                \
     (Mask == SENT_HALFBYTE_MASK3) || (Mask == SENT_HALFBYTE_MASK4) || (Mask == SENT_HALFBYTE_MASK5) ||                \
     (Mask == SENT_HALFBYTE_MASK6) || (Mask == SENT_HALFBYTE_MASK7))

typedef enum
{
    SENT_HALFBYTE_INDEX0,
    SENT_HALFBYTE_INDEX1,
    SENT_HALFBYTE_INDEX2,
    SENT_HALFBYTE_INDEX3,
    SENT_HALFBYTE_INDEX4,
    SENT_HALFBYTE_INDEX5,
    SENT_HALFBYTE_INDEX6,
    SENT_HALFBYTE_INDEX7
} Sent_HalfByteIndex_t;

#define CHECK_SENT_HALFBYTEINDEX(Index) ((Index >> POS_3_SHIFT) == 0U)

typedef enum
{
    GENERATE_NULL,
    GENERATE_IMMEDIATE,
    GENERATE_NEGEDGE,
    GENERATE_OUTTRIGGER
} Sent_TriggerMode_t;

#define CHECK_SENT_TRIGGERMODE(Mode)                                                                                   \
    ((Mode == GENERATE_NULL) || (Mode == GENERATE_IMMEDIATE) || (Mode == GENERATE_NEGEDGE) ||                          \
     (Mode == GENERATE_OUTTRIGGER))

typedef enum
{
    TIMEBASE_MEASUREFREQUENCY,
    TIMEBASE_NOMINALFREQUENCY
} Sent_TimeBase_t;

#define CHECK_TIMEBASE(TimeBase) ((TimeBase == TIMEBASE_MEASUREFREQUENCY) || (TimeBase == TIMEBASE_NOMINALFREQUENCY))

typedef enum
{
    DATA12_ID8,
    DATA16_ID4
} Sent_SerialConfig_t;

#define CHECK_SERIALCONFIG(Config) ((Config == DATA12_ID8) || (Config == DATA16_ID4))

typedef enum
{
    EXTERNAL_INPUT_0,
    EXTERNAL_INPUT_1,
    EXTERNAL_INPUT_2,
    EXTERNAL_INPUT_3
} Sent_ExternalInputChannel_t;

#define CHECK_EXTERNALINPUT(Channel)                                                                                   \
    ((Channel == EXTERNAL_INPUT_0) || (Channel == EXTERNAL_INPUT_1) || (Channel == EXTERNAL_INPUT_2) ||                \
     (Channel == EXTERNAL_INPUT_3))

typedef enum
{
    SENT_EXTERNAL_TRIGGER_0,
    SENT_EXTERNAL_TRIGGER_1,
    SENT_EXTERNAL_TRIGGER_2,
    SENT_EXTERNAL_TRIGGER_3,
    SENT_EXTERNAL_TRIGGER_4,
    SENT_EXTERNAL_TRIGGER_5,
    SENT_EXTERNAL_TRIGGER_6,
    SENT_EXTERNAL_TRIGGER_7,
    SENT_EXTERNAL_TRIGGER_8,
    SENT_EXTERNAL_TRIGGER_9,
    SENT_EXTERNAL_TRIGGER_10,
    SENT_EXTERNAL_TRIGGER_11,
    SENT_EXTERNAL_TRIGGER_12,
    SENT_EXTERNAL_TRIGGER_13,
    SENT_EXTERNAL_TRIGGER_14,
    SENT_EXTERNAL_TRIGGER_15
} Sent_ExternalTrigger_t;

#define CHECK_EXTERNALTRIGGER(Trigger) ((Trigger >> POS_4_SHIFT) == 0U)

typedef enum
{
    SENT_RSIF  = 0x00000001,
    SENT_RDIF  = 0x00000002,
    SENT_RBIF  = 0x00000004,
    SENT_TDIF  = 0x00000008,
    SENT_TBIF  = 0x00000010,
    SENT_FRIF  = 0x00000020,
    SENT_FDIF  = 0x00000040,
    SENT_NNIF  = 0x00000080,
    SENT_NVIF  = 0x00000100,
    SENT_CRCIF = 0x00000200,
    SENT_WSIF  = 0x00000400,
    SENT_SDIF  = 0x00000800,
    SENT_SCRIF = 0x00001000,
    SENT_WDIF  = 0x00002000,
    SENT_LWIF  = 0x00004000
} Sent_Flag_t;

#define CHECK_FLAG(Flag)                                                                                               \
    ((Flag == SENT_RSIF) || (Flag == SENT_RDIF) || (Flag == SENT_RBIF) || (Flag == SENT_TDIF) ||                       \
     (Flag == SENT_TBIF) || (Flag == SENT_FRIF) || (Flag == SENT_FDIF) || (Flag == SENT_NNIF) ||                       \
     (Flag == SENT_NVIF) || (Flag == SENT_CRCIF) || (Flag == SENT_WSIF) || (Flag == SENT_SDIF) ||                      \
     (Flag == SENT_SCRIF) || (Flag == SENT_WDIF) || (Flag == SENT_LWIF))

typedef enum
{
    SENT_RSIE  = 0x00000001,
    SENT_RDIE  = 0x00000002,
    SENT_RBIE  = 0x00000004,
    SENT_TDIE  = 0x00000008,
    SENT_TBIE  = 0x00000010,
    SENT_FRIE  = 0x00000020,
    SENT_FDIE  = 0x00000040,
    SENT_NNIE  = 0x00000080,
    SENT_NVIE  = 0x00000100,
    SENT_CRCIE = 0x00000200,
    SENT_WSIE  = 0x00000400,
    SENT_SDIE  = 0x00000800,
    SENT_SCRIE = 0x00001000,
    SENT_WDIE  = 0x00002000,
    SENT_LWIE  = 0x00004000
} Sent_Int_t;

#define CHECK_INT(Int)                                                                                                 \
    ((Int == SENT_RSIE) || (Int == SENT_RDIE) || (Int == SENT_RBIE) || (Int == SENT_TDIE) || (Int == SENT_TBIE) ||     \
     (Int == SENT_FRIE) || (Int == SENT_FDIE) || (Int == SENT_NNIE) || (Int == SENT_NVIE) || (Int == SENT_CRCIE) ||    \
     (Int == SENT_WSIE) || (Int == SENT_SDIE) || (Int == SENT_SCRIE) || (Int == SENT_WDIE) || (Int == SENT_LWIE))

typedef enum
{
    RSIFTRIGGER  = 0x0000000F,
    RDIFTRIGGER  = 0x000000F0,
    RBIFTRIGGER  = 0x00000F00,
    TDIFTRIGGER  = 0x0000F000,
    TBIFTRIGGER  = 0x000F0000,
    ERRIFTRIGGER = 0x00F00000,
    SDIFTRIGGER  = 0x0F000000,
    WDIFTRIGGER  = 0xF0000000
} Sent_FlagTrigger_t;

#define CHECK_FLAGTRIGGER(FlagTrigger)                                                                                 \
    ((FlagTrigger == RSIFTRIGGER) || (FlagTrigger == RDIFTRIGGER) || (FlagTrigger == RBIFTRIGGER) ||                   \
     (FlagTrigger == TDIFTRIGGER) || (FlagTrigger == TBIFTRIGGER) || (FlagTrigger == ERRIFTRIGGER) ||                  \
     (FlagTrigger == SDIFTRIGGER) || (FlagTrigger == WDIFTRIGGER))

#define CHECK_SENT_BOOL(Bool) ((Bool >> POS_1_SHIFT) == 0U)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief 禁止SENT模块
 *
 *
 * @param Status
 *        true:禁止模块
 *        false:无操作
 * @retval void
 */
KF_INLINE void Sent_LL_DisableSent(const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_CLKC_ADDR );
    regValue &= ~HWIO_SENT_CLKC_SENT_CLKC_DISR_MASK;
    regValue |=  Status<<HWIO_SENT_CLKC_SENT_CLKC_DISR_SHFT;
    REG_WRITE(HWIO_SENT_CLKC_ADDR , regValue);
#else
    REG_WRITE(SENT_GENERAL_PTR->SENT_CLKC.bits.DISR, Status);
#endif
}//DONE

/**
 * @brief 获取SENT模块状态
 *
 *
 * @param void
 * @retval bool
 *         true:模块已禁止
 *         false:模块已使能
 */
KF_INLINE bool Sent_LL_GetModuleState(void)
{
#ifdef SIMULATION
    uint32_t regValue   = REG_READ(HWIO_SENT_CLKC_ADDR);
    regValue &= HWIO_SENT_CLKC_SENT_CLKC_DISS_MASK;
    regValue = regValue >> HWIO_SENT_CLKC_SENT_CLKC_DISS_SHFT;
    return (bool)(regValue);
#else
    return (REG_READ(SENT_GENERAL_PTR->SENT_CLKC.bits.DISS));
#endif
}//DONE

/**
 * @brief 设置SENT模块进入休眠模式
 *
 *
 * @param Status
 *        true:使能休眠模式
 *        false:禁止休眠模式
 * @retval void
 */
KF_INLINE void Sent_LL_SetSentSleep(const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_CLKC_ADDR );
    regValue &= ~HWIO_SENT_CLKC_SENT_CLKC_EDIS_MASK;
    regValue |=  Status<<HWIO_SENT_CLKC_SENT_CLKC_EDIS_SHFT;
    REG_WRITE(HWIO_SENT_CLKC_ADDR , regValue);
#else
    REG_WRITE(SENT_GENERAL_PTR->SENT_CLKC.bits.EDIS, Status);
#endif
}//DONE


/**
 * @brief 获取SENT模块版本信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Sent_LL_GetModuleVersion(void)
{
#ifdef SIMULATION
    uint32_t regValue   = REG_READ(HWIO_SENT_INFO_ADDR);
    regValue &= HWIO_SENT_INFO_SENT_INFO_MODREV_MASK;
    regValue = regValue >> HWIO_SENT_INFO_SENT_INFO_MODREV_SHFT;
    return regValue;
#else
    return (REG_READ(SENT_GENERAL_PTR->SENT_INFO.bits.MODREV));
#endif
}//DONE

/**
 * @brief 获取SENT模块类型信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Sent_LL_GetModuleType(void)
{
#ifdef SIMULATION
    uint32_t regValue   = REG_READ(HWIO_SENT_INFO_ADDR);
    regValue &= HWIO_SENT_INFO_SENT_INFO_MODTYPE_MASK;
    regValue = regValue >> HWIO_SENT_INFO_SENT_INFO_MODTYPE_SHFT;
    return regValue;
#else
    return (REG_READ(SENT_GENERAL_PTR->SENT_INFO.bits.MODTYPE));
#endif
}//DONE

/**
 * @brief 获取SENT模块ID信息
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Sent_LL_GetModuleId(void)
{
#ifdef SIMULATION
    uint32_t regValue   = REG_READ(HWIO_SENT_INFO_ADDR);
    regValue &= HWIO_SENT_INFO_SENT_INFO_MODNUM_MASK;
    regValue = regValue >> HWIO_SENT_INFO_SENT_INFO_MODNUM_SHFT;
    return regValue;
#else
    return (REG_READ(SENT_GENERAL_PTR->SENT_INFO.bits.MODNUM));
#endif
}//DONE

/**
 * @brief 设置SENT调试挂起模式
 *
 *
 * @param Mode
 *        SENT_NOSUSPEND
 *        SENT_HARDSUSPEND
 *        SENT_NOSUSPEND
 * @retval  void
 */
KF_INLINE void Sent_LL_SetDebugSuspendMode(Sent_SuspendMode_t Mode)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_SUSPENDMODE(Mode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_DBG_ADDR );
    regValue &= ~HWIO_SENT_DBG_SENT_DBG_SUSP_MASK;
    regValue |=  true<<HWIO_SENT_DBG_SENT_DBG_SUSP_SHFT;
    REG_WRITE(HWIO_SENT_DBG_ADDR , regValue);

    regValue=REG_READ(HWIO_SENT_DBG_ADDR );
    regValue &= ~HWIO_SENT_DBG_SENT_DBG_SUS_MASK;
    regValue |=  Mode<<HWIO_SENT_DBG_SENT_DBG_SUS_SHFT;
    REG_WRITE(HWIO_SENT_DBG_ADDR , regValue);

    regValue=REG_READ(HWIO_SENT_DBG_ADDR );
    regValue &= ~HWIO_SENT_DBG_SENT_DBG_SUSP_MASK;
    regValue |=  false<<HWIO_SENT_DBG_SENT_DBG_SUSP_SHFT;
    REG_WRITE(HWIO_SENT_DBG_ADDR , regValue);
#else
    REG_WRITE(SENT_GENERAL_PTR->SENT_DBG.bits.SUSP, true);
    REG_WRITE(SENT_GENERAL_PTR->SENT_DBG.bits.SUS, Mode);
    REG_WRITE(SENT_GENERAL_PTR->SENT_DBG.bits.SUSP, false); 
#endif
}//DONE

/**
 * @brief 获取SENT调试挂起模式
 *
 *
 * @param void
 * @retval Sent_SuspendMode_t
 *         SENT_NOSUSPEND
 *         SENT_HARDSUSPEND
 *         SENT_NOSUSPEND
 */
KF_INLINE Sent_SuspendMode_t Sent_LL_GetDebugSuspendMode(void)
{
#ifdef SIMULATION
    uint32_t regValue   = REG_READ(HWIO_SENT_DBG_ADDR);
    regValue &= HWIO_SENT_DBG_SENT_DBG_SUS_MASK;
    regValue = regValue >> HWIO_SENT_DBG_SENT_DBG_SUS_SHFT;
    return (Sent_SuspendMode_t)regValue;
#else
    return ((Sent_SuspendMode_t)REG_READ(SENT_GENERAL_PTR->SENT_DBG.bits.SUS));
#endif
}//DONE

/**
 * @brief 获取SENT调试挂起状态
 *
 *
 * @param void
 * @retval bool
 *         true: 模块已挂起
 *         false: 模块未挂起
 */
KF_INLINE bool Sent_LL_GetDebugSuspend(void)
{
#ifdef SIMULATION
    uint32_t regValue   = REG_READ(HWIO_SENT_DBG_ADDR);
    regValue &= HWIO_SENT_DBG_SENT_DBG_SUSSTA_MASK;
    regValue = regValue >> HWIO_SENT_DBG_SENT_DBG_SUSSTA_SHFT;
    return (bool)regValue;
#else
    return (REG_READ(SENT_GENERAL_PTR->SENT_DBG.bits.SUSSTA));
#endif
}//DONE

/**
 * @brief 清零Sent 复位状态
 *
 *
 * @param  bool
 *         true: 清零复位状态
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Sent_LL_ClearRst(const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RSTCLR_ADDR );
    regValue &= ~HWIO_SENT_RSTCLR_SENT_RSTCLR_CLR_MASK;
    regValue |=  Status<<HWIO_SENT_RSTCLR_SENT_RSTCLR_CLR_SHFT;
    REG_WRITE(HWIO_SENT_RSTCLR_ADDR , regValue);
#else
    REG_WRITE(SENT_GENERAL_PTR->SENT_RSTCLR.bits.CLR, Status);
#endif
}//DONE

/**
 * @brief 请求Sent 复位
 *
 *
 * @param  bool
 *         true: 请求模块复位
 *         false: 无动作
 * @retval void
 */
KF_INLINE void Sent_LL_ResetModule(const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RST0_ADDR );
    regValue &= ~HWIO_SENT_RST0_SENT_RST0_RST_MASK;
    regValue |=  Status<<HWIO_SENT_RST0_SENT_RST0_RST_SHFT;
    REG_WRITE(HWIO_SENT_RST0_ADDR , regValue);

    regValue=REG_READ(HWIO_SENT_RST1_ADDR );
    regValue &= ~HWIO_SENT_RST1_SENT_RST1_RST_MASK;
    regValue |=  Status<<HWIO_SENT_RST1_SENT_RST1_RST_SHFT;
    REG_WRITE(HWIO_SENT_RST1_ADDR , regValue);
#else
    REG_WRITE(SENT_GENERAL_PTR->SENT_RST1.bits.RST, Status);
    REG_WRITE(SENT_GENERAL_PTR->SENT_RST0.bits.RST, Status);
#endif
}//DONE

/**
 * @brief 获取SENT复位状态
 *
 *
 * @ param void
 * @ retval bool
 *          true: 模块已经复位
 *          false: 模块没有复位
 */
KF_INLINE bool Sent_LL_GetResetState(void)
{
#ifdef SIMULATION
    uint32_t regValue   = REG_READ(HWIO_SENT_RST0_ADDR);
    regValue &= HWIO_SENT_RST0_SENT_RST0_RSTSTA_MASK;
    regValue = regValue >> HWIO_SENT_RST0_SENT_RST0_RSTSTA_SHFT;
    return (bool)regValue;
#else
    return (REG_READ(SENT_GENERAL_PTR->SENT_RST0.bits.RSTSTA));
#endif
}//DONE

/**
 * @brief 使能SENT访问控制
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval void
 */
KF_INLINE void Sent_LL_EnableAccess(Sent_AccessEnableType_t AccessEnable)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
    REG_BIT_SET(HWIO_SENT_ACES0_ADDR, MASK_1_BIT << AccessEnable);
#else
    REG_BIT_SET(SENT_GENERAL_PTR->SENT_ACES0.reg, MASK_1_BIT << AccessEnable);
#endif
}//DONE

/**
 * @brief 获取SENT访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE bool Sent_LL_GetAccess(Sent_AccessEnableType_t AccessEnable)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
    return (bool)(REG_BITS_READ(HWIO_SENT_ACES0_ADDR, MASK_1_BIT << AccessEnable, AccessEnable));
#else
    return (REG_BITS_READ(SENT_GENERAL_PTR->SENT_ACES0.reg, MASK_1_BIT << AccessEnable, AccessEnable));
#endif
}

/**
 * @brief 设置SENT分频值
 *
 *
 * @ param Division :预设值分频值
 * @ retval void
 */
KF_INLINE void Sent_LL_SetDivision(uint32_t Division)
{
    KF_DRV_SENT_ASSERT((Division >> POS_10_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_FDR_ADDR );
    regValue &= ~HWIO_SENT_FDR_SENT_FDR_STEP_MASK;
    regValue |=  Division<<HWIO_SENT_FDR_SENT_FDR_STEP_SHFT;
    REG_WRITE(HWIO_SENT_FDR_ADDR , regValue);
#else
    REG_WRITE(SENT_GENERAL_PTR->SENT_FDR.bits.STEP, Division);
#endif
}//DONE

/**
 * @brief 设置SENT分频模式
 *
 *
 * @ param DivisionMode
 *         SENT_DIVISION_CLOSE_MODE:关闭分频器
 *         SENT_INTEGER_DIVISION_MODE:整数分频模式
 *         SENT_FRACTION_DIVISION_MODE:分数分频模式
 * @ retval void
 */
KF_INLINE void Sent_LL_SetDivisionMode(Sent_DivisionType_t DivisionMode)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_DIVISION(DivisionMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_FDR_ADDR );
    regValue &= ~HWIO_SENT_FDR_SENT_FDR_DM_MASK;
    regValue |=  DivisionMode<<HWIO_SENT_FDR_SENT_FDR_DM_SHFT;
    REG_WRITE(HWIO_SENT_FDR_ADDR , regValue);
#else
    REG_WRITE(SENT_GENERAL_PTR->SENT_FDR.bits.DM, DivisionMode);
#endif
}//DONE

/**
 * @brief 读取SENT分频result
 *
 *
 * @ param void
 * @ retval uint32_t
 */
KF_INLINE uint32_t Sent_LL_GetDivisionResult(void)
{
#ifdef SIMULATION
    uint32_t regValue   = REG_READ(HWIO_SENT_FDR_ADDR);
    regValue &= HWIO_SENT_FDR_SENT_FDR_RESULT_MASK;
    regValue = regValue >> HWIO_SENT_FDR_SENT_FDR_RESULT_SHFT;
    return regValue;
#else
    return (REG_READ(SENT_GENERAL_PTR->SENT_FDR.bits.RESULT));
#endif
}//DONE

/**
 * @brief 读取SENT时间戳
 *
 *
 * @ param void
 * @ retval uint32_t
 */
KF_INLINE uint32_t Sent_LL_GetTimeStamp(void)
{
#ifdef SIMULATION
    return (REG_READ(HWIO_SENT_TSR_ADDR));
#else
    return (REG_READ(SENT_GENERAL_PTR->SENT_TSR.reg));
#endif
}//DONE

/**
 * @brief 设置SENT时间戳预分频值
 *
 *
 * @ param Pres
 * @ retval void
 */
KF_INLINE void Sent_LL_SetTimeStampPres(uint32_t Pres)
{
    KF_DRV_SENT_ASSERT((Pres >> POS_10_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_TPD_ADDR );
    regValue &= ~HWIO_SENT_TPD_SENT_TPD_TDIV_MASK;
    regValue |=  Pres<<HWIO_SENT_TPD_SENT_TPD_TDIV_SHFT;
    REG_WRITE(HWIO_SENT_TPD_ADDR , regValue);
#else
    REG_WRITE(SENT_GENERAL_PTR->SENT_TPD.bits.TDIV, Pres);
#endif
}//DONE

/**
 * @brief 获取SENT通道中断状态
 *
 *
 * @ param Channel
 * @ retval bool
 *          true:请求通道中断挂起
 *          false:请求通道中断未挂起
 */
KF_INLINE bool Sent_LL_GetChannelIntPend(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    return ((REG_READ(HWIO_SENT_INTOV_ADDR) & (true << Channel)) != false);
#else
    return ((REG_READ(SENT_GENERAL_PTR->SENT_INTOV.reg) & (true << Channel)) != false);
#endif
}//DONE

/**
 * @brief 设置SENT通道预分频系数
 *
 *
 * @ param Channel
 * @ param Pres
 * @ retval void
 */
KF_INLINE void Sent_LL_SetChannelPres(Sent_ChannelType_t Channel, uint32_t Pres)
{
    KF_DRV_SENT_ASSERT((Pres >> POS_12_SHIFT) == 0U);
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_CPDR0_ADDR + (0x4)*Channel);
    regValue &= ~HWIO_SENT_CPDR0_SENT_CPDR0_PDIV_MASK;
    regValue |=  Pres<<HWIO_SENT_CPDR0_SENT_CPDR0_PDIV_SHFT;
    REG_WRITE(HWIO_SENT_TPD_ADDR , regValue);
#else
    REG_WRITE(SENT_GENERAL_PTR->SENT_CPDR[Channel].bits.PDIV, Pres);
#endif
}//DONE

/**
 * @brief 设置SENT通道分数预分频系数
 *
 *
 * @ param Channel
 * @ param Pres
 * @ retval void
 */
KF_INLINE void Sent_LL_SetChannelDivide(Sent_ChannelType_t Channel, uint32_t Pres)
{
    KF_DRV_SENT_ASSERT((Pres >> POS_16_SHIFT) == 0U);
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_CFDR0_ADDR + (0x28)*Channel);
    regValue &= ~HWIO_SENT_CFDR0_SENT_CFDR0_DIV_MASK;
    regValue |=  Pres<<HWIO_SENT_CFDR0_SENT_CFDR0_DIV_SHFT;
    REG_WRITE(HWIO_SENT_CFDR0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_CFDR.bits.DIV, Pres);
#endif
}//DONE

/**
 * @brief 读取SENT通道分数预分频系数
 *
 *
 * @ param Channel
 * @ retval uint32_t
 */
KF_INLINE uint32_t Sent_LL_GetChannelPres(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_CFDR0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_CFDR0_SENT_CFDR0_DIVM_MASK;
    regValue = regValue >> HWIO_SENT_CFDR0_SENT_CFDR0_DIVM_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_CFDR.bits.DIVM));
#endif
}//TODO：function name error & description error

/**
 * @brief 设置SENT开门狗门限值
 *
 *
 * @ param Channel
 * @ param Threshold
 * @ retval void
 */
KF_INLINE void Sent_LL_SetChannelWdgThreshold(Sent_ChannelType_t Channel, uint32_t Threshold)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT((Threshold >> POS_16_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_WDT0_ADDR + (0x28)*Channel);
    regValue &= ~0xFFFF;
    regValue |=  Threshold<<0;
    REG_WRITE(HWIO_SENT_WDT0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_WDT.bits.WDL, Threshold);
#endif
}//DONE

/**
 * @brief 获取SENT开门狗门限值
 *
 *
 * @ param Channel
 * @ param Threshold
 * @ retval uint32_t :通道看门狗门限值
 */
KF_INLINE uint32_t Sent_LL_GetChannelWdgThreshold(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION    
    uint32_t regValue = REG_READ(HWIO_SENT_WDT0_ADDR + (0x28)*Channel);
    regValue &= 0xFFFF;
    regValue = regValue >> 0;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_WDT.bits.WDL));
#endif
}//DONE

/**
 * @brief 使能SENT通道
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:启用通道
 *         false:禁止通道
 * @ retval void
 */
KF_INLINE void Sent_LL_EnableChannel(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel);
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_CEN_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_CEN_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.CEN, Status);
#endif
}//DONE

/**
 * @brief 获取SENT通道
 *
 *
 * @ param Channel
 * @ retval bool:
 *         true:通道被启用
 *         false:通道被禁止
 */
KF_INLINE bool Sent_LL_GetChannelEnable(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_RCTL0_SENT_RCTL0_CEN_MASK;
    regValue = regValue >> HWIO_SENT_RCTL0_SENT_RCTL0_CEN_SHFT;
    return (bool)regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.CEN));
#endif
}//DONE

/**
 * @brief 设置SENT忽略结束脉冲
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:忽略脉冲
 *         false:不忽略脉冲
 * @ retval void:
 *
 */
KF_INLINE void Sent_LL_IgnoreEndPulse(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel);
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_IEP_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_IEP_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.IEP, Status);
#endif
}//DONE

/**
 * @brief 设置SENT替代CRC模式
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:使能替代CRC模式
 *         false:禁止替代CRC模式
 * @ retval void:
 *
 */
KF_INLINE void Sent_LL_ReplaceCRCMode(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_ACE_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_ACE_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.ACE, Status);
#endif
}//DONE

/**
 * @brief 设置SENT包含状态半字节
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:状态半字节包含在CRC
 *         false:状态半字节不包含在CRC
 * @ retval void:
 *
 */
KF_INLINE void Sent_LL_ContainStatusHalfByte(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_SNI_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_SNI_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.SNI, Status);
#endif
}//DONE

/**
 * @brief 设置SENT串行数据自动处理
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:使能串行数据自动处理
 *         false:禁止串行数据自动处理
 * @ retval void:
 *
 */
KF_INLINE void Sent_LL_EnableAutoProcessSerialData(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_SDP_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_SDP_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.SDP, Status);
#endif
}//DONE

/**
 * @brief 设置SENT串行数据CRC禁止模式
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:禁止串行数据CRC
 *         false:使能串行数据CRC
 * @ retval void:
 *
 */
KF_INLINE void Sent_LL_DisableSerialDataCRC(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_SCDIS_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_SCDIS_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.SCDIS, Status);
#endif
}//DONE

/**
 * @brief 设置SENTCRC模式
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:禁止CRC
 *         false:使能CRC
 * @ retval void:
 *
 */
KF_INLINE void Sent_LL_DisableCRC(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_SCDIS_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_SCDIS_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.CDIS, Status);
#endif
}//DONE

/**
 * @brief 设置SENT连续帧检查
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:使能连续帧检测
 *         false:禁止连续帧检查
 * @ retval void:
 *
 */
KF_INLINE void Sent_LL_EnableConsecutiveFrameCheck(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_CFC_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_CFC_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.CFC, Status);
#endif
}//DONE

/**
 * @brief 设置SENT帧长度
 *
 *
 * @ param Channel
 * @ param uint32_t:帧长度
 * @ retval void:
 *
 */
KF_INLINE void Sent_LL_SetFrameLength(Sent_ChannelType_t Channel, const uint32_t FrameLength)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT((FrameLength >> POS_8_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_FRL_MASK;
    regValue |=  FrameLength<<HWIO_SENT_RCTL0_SENT_RCTL0_FRL_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.FRL, FrameLength);
#endif
}//DONE

/**
 * @brief 获取SENT帧长度
 *
 *
 * @ param Channel
 * @ retval uint32_t:帧长度
 *
 */
KF_INLINE uint32_t Sent_LL_GetFrameLength(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_RCTL0_SENT_RCTL0_FRL_MASK;
    regValue = regValue >> HWIO_SENT_RCTL0_SENT_RCTL0_FRL_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.FRL));
#endif
}//DONE

/**
 * @brief 设置SENTCRC增加值
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:CRC选择增加值
 *         false:CRC不选择增加值
 * @ retval void:
 */
KF_INLINE void Sent_LL_EnableCRCAddedValue(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel);
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_CRZ_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_CRZ_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.CRZ, Status);
#endif
}//TODO:reg excel error,the one after FRL is CRZ, but in reg excel it is CDIS.

/**
 * @brief 设置SENT串行帧模式
 *
 *
 * @ param Channel
 * @ param Sent_SerialFrameMode_t:
 *         SENT_SHORTSERIAL_MODE
 *         SENT_ENHANCEDSERIAL_MODE
 * @ retval void:
 */
KF_INLINE void Sent_LL_SetSerialFrameMode(Sent_ChannelType_t Channel, const Sent_SerialFrameMode_t Mode)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT(CHECK_SENT_SERIALFRAMEMODE(Mode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_ESF_MASK;
    regValue |=  Mode<<HWIO_SENT_RCTL0_SENT_RCTL0_ESF_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.ESF, Mode);
#endif
}//DONE

/**
 * @brief 设置SENT忽略偏移错误
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:忽略偏移错误
 *         false:使能偏移错误
 * @ retval void:
 */
KF_INLINE void Sent_LL_IgnoreSegregationError(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_IDE_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_IDE_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.IDE, Status);
#endif
}//DONE

/**
 * @brief 设置SENTChannel 挂起
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:挂起模块
 *         false:不挂起模块
 * @ retval void:
 */
KF_INLINE void Sent_LL_EnableSuspend(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_SUSEN_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_SUSEN_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.SUSEN, Status);
#endif
}//DONE

/**
 * @brief 获取SENTChannel 挂起状态
 *
 *
 * @ param Channel
 * @ retval bool:
 *         true:模块处于挂起状态
 *         false:模块不处于挂起状态
 */
KF_INLINE bool Sent_LL_GetSuspend(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_RCTL0_SENT_RCTL0_SUSEN_MASK;
    regValue = regValue >> HWIO_SENT_RCTL0_SENT_RCTL0_SUSEN_SHFT;
    return (bool)regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.SUSEN));
#endif
}//DONE

/**
 * @brief 使能SENTChannel 挂起状态
 *
 *
 * @ param Channel
 * @ param bool:
 *         true:使能频率偏移检查
 *         false:禁止频率偏移检查
 * @ retval void
 */
KF_INLINE void Sent_LL_EnableFRQOffsetCheck(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_RCTL0_SENT_RCTL0_FDFL_MASK;
    regValue |=  Status<<HWIO_SENT_RCTL0_SENT_RCTL0_FDFL_SHFT;
    REG_WRITE(HWIO_SENT_RCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_RCTL.bits.FDFL, Status);
#endif
}//DONE

/**
 * @brief 获取SENT最近一次的CRC值
 *
 *
 * @ param Channel
 * @ retval uint32_t: CRC值
 */
KF_INLINE uint32_t Sent_LL_GetCurrentCRC(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_RSTA0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_RSTA0_SENT_RSTA0_CRC_MASK;
    regValue = regValue >> HWIO_SENT_RSTA0_SENT_RSTA0_CRC_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_RSTA.bits.CRC));
#endif
}//DONE

/**
 * @brief 获取SENT通道当前状态
 *
 *
 * @ param Channel
 * @ retval Sent_ChannelState_t: 通道状态
 */
KF_INLINE Sent_ChannelState_t Sent_LL_GetChannelState(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_RSTA0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_RSTA0_SENT_RSTA0_CST_MASK;
    regValue = regValue >> HWIO_SENT_RSTA0_SENT_RSTA0_CST_SHFT;
    return (Sent_ChannelState_t)regValue;
#else
    return ((Sent_ChannelState_t)REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_RSTA.bits.CST));
#endif
}//DONE

/**
 * @brief 获取SENT最近一帧状态和通信半字节
 *
 *
 * @ param Channel
 * @ retval uint32_t: 最近一帧的状态和通信半字节
 */
KF_INLINE uint32_t Sent_LL_GetCurrentStateHalfByte(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_RSTA0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_RSTA0_SENT_RSTA0_SCN_MASK;
    regValue = regValue >> HWIO_SENT_RSTA0_SENT_RSTA0_SCN_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_RSTA.bits.SCN));
#endif
}//DONE

/**
 * @brief 获取SENT包含暂停帧的最近一帧长度
 *
 *
 * @ param Channel
 * @ retval uint32_t: 包含暂停帧的最近一帧长度
 */
KF_INLINE uint32_t Sent_LL_GetCurrentFrameLength(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_RSTA0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_RSTA0_SENT_RSTA0_FRLEN_MASK;
    regValue = regValue >> HWIO_SENT_RSTA0_SENT_RSTA0_FRLEN_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_RSTA.bits.FRLEN));
#endif
}//DONE

/**
 * @brief 设置SENT接收数据的目标半字节指针
 *
 *
 * @ param Channel
 * @ param HalfByteMask
 * @ param HalfByteIndex
 * @ retval void
 */
KF_INLINE void Sent_LL_SetHalfBytePointer(Sent_ChannelType_t Channel, Sent_HalfBytePointerMask_t HalfBytePointerMask, uint32_t Pointer)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT(CHECK_SENT_HALFBYTEPOINTERMASK(HalfBytePointerMask));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_SENT_VIEW0_ADDR + (0x28)*Channel, HalfBytePointerMask, Pointer);
#else
    REG_BITS_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_VIEW.reg, HalfBytePointerMask, Pointer);
#endif
}//DONE

/**
 * @brief 获取SENT接收数据目标半字节指针
 *
 *
 * @ param Channel
 * @ param HalfByteMask
 * @ param HalfByteIndex
 * @ retval uint32_t: 接收数据目标半字节指针
 */
KF_INLINE uint32_t Sent_LL_GetHalfBytePointer(
  Sent_ChannelType_t Channel, Sent_HalfBytePointerMask_t HalfBytePointerMask,
  Sent_HalfBytePointerIndex_t HalfBytePointerIndex)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT(CHECK_SENT_HALFBYTEINDEX(HalfBytePointerIndex));
    KF_DRV_SENT_ASSERT(CHECK_SENT_HALFBYTEPOINTERMASK(HalfBytePointerMask));
#ifdef SIMULATION
    return REG_BITS_READ(HWIO_SENT_VIEW0_ADDR + (0x28)*Channel, HalfBytePointerMask, (4 * HalfBytePointerIndex));
#else
    return REG_BITS_READ((SENT_CHANNEL_PTR + Channel)->SENT_VIEW.reg, HalfBytePointerMask, (4 * HalfBytePointerIndex));
#endif
}//DONE

/**
 * @brief 获取SENT接收目标半字节数据
 *
 *
 * @ param Channel
 * @ param HalfByteMask
 * @ param HalfByteIndex
 * @ retval uint32_t: 接收数据目标半字节数据
 */
KF_INLINE uint32_t
Sent_LL_GetHalfByte(Sent_ChannelType_t Channel, Sent_HalfByteMask_t HalfByteMask, Sent_HalfByteIndex_t HalfByteIndex)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT(CHECK_SENT_HALFBYTEMASK(HalfByteMask));
    KF_DRV_SENT_ASSERT(CHECK_SENT_HALFBYTEINDEX(HalfByteIndex));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_SENT_RDAT0_ADDR, HalfByteMask, (POS_4_SHIFT * HalfByteIndex)));
#else
    return (REG_BITS_READ((SENT_CHANNEL_PTR + Channel)->SENT_RDAT.reg, HalfByteMask, (POS_4_SHIFT * HalfByteIndex)));
#endif
}//DONE

/**
 * @brief 设置SENT脉冲长度
 *
 *
 * @ param Channel
 * @ param Length: 脉冲长度
 * @ retval void
 */
KF_INLINE void Sent_LL_SetPulseLength(Sent_ChannelType_t Channel, uint32_t Length)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT((Length >> POS_6_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_SCTL0_ADDR + (0x28)*Channel);
    regValue &= ~HWIO_SENT_SCTL0_SENT_SCTL0_PLEN_MASK;
    regValue |=  Length<<HWIO_SENT_SCTL0_SENT_SCTL0_PLEN_SHFT;
    REG_WRITE(HWIO_SENT_SCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_SCTL.bits.PLEN, Length);
#endif
}//DONE

/**
 * @brief 获取SENT脉冲长度
 *
 *
 * @ param Channel
 * @ retval uint32_t: 脉冲长度
 */
KF_INLINE uint32_t Sent_LL_GetPulseLength(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_SCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_SCTL0_SENT_SCTL0_PLEN_MASK;
    regValue = regValue >> HWIO_SENT_SCTL0_SENT_SCTL0_PLEN_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_SCTL.bits.PLEN));
#endif
}//DONE

/**
 * @brief 设置SENT触发源和触发模式
 *
 *
 * @ param Channel
 * @ param TriggerMode
 * @ retval void
 */
KF_INLINE void Sent_LL_SetTriggerSourceAndMode(Sent_ChannelType_t Channel, Sent_TriggerMode_t TriggerMode)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT(CHECK_SENT_TRIGGERMODE(TriggerMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_SCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_SCTL0_SENT_SCTL0_TRIG_MASK;
    regValue |=  TriggerMode<<HWIO_SENT_SCTL0_SENT_SCTL0_TRIG_SHFT;
    REG_WRITE(HWIO_SENT_SCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_SCTL.bits.TRIG, TriggerMode);
#endif
}//DONE

/**
 * @brief 设置SENT延迟长度
 *
 *
 * @ param Channel
 * @ param DelayLength
 * @ retval void
 */
KF_INLINE void Sent_LL_SetDelayLength(Sent_ChannelType_t Channel, const uint32_t DelayLength)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT((DelayLength >> POS_6_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_SCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_SCTL0_SENT_SCTL0_DEL_MASK;
    regValue |=  DelayLength<<HWIO_SENT_SCTL0_SENT_SCTL0_DEL_SHFT;
    REG_WRITE(HWIO_SENT_SCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_SCTL.bits.DEL, DelayLength);
#endif
}//DONE

/**
 * @brief 设置SENT时基
 *
 *
 * @ param Channel
 * @ param TimeBase
 * @ retval void
 */
KF_INLINE void Sent_LL_SetPulseTimerBase(Sent_ChannelType_t Channel, const Sent_TimeBase_t TimeBase)
{
    KF_DRV_SENT_ASSERT(CHECK_TIMEBASE(TimeBase));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_SCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_SCTL0_SENT_SCTL0_BASE_MASK;
    regValue |=  TimeBase<<HWIO_SENT_SCTL0_SENT_SCTL0_BASE_SHFT;
    REG_WRITE(HWIO_SENT_SCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_SCTL.bits.BASE, TimeBase);
#endif
}//DONE

/**
 * @brief 获取SENT发送请求状态
 *
 *
 * @ param Channel
 * @ retval bool
 *          true:发送请求处理中
 *          false:发送请求未被处理
 */
KF_INLINE bool Sent_LL_GetSendState(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_SCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_SCTL0_SENT_SCTL0_TRQ_MASK;
    regValue = regValue >> HWIO_SENT_SCTL0_SENT_SCTL0_TRQ_SHFT;
    return (bool)regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_SCTL.bits.TRQ));
#endif
}//DONE

/**
 * @brief 获取SENT最近一组串行帧的信息数据
 *
 *
 * @ param Channel
 * @ retval uint32_t
 */
KF_INLINE uint32_t Sent_LL_GetCurrnetSerialData(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_SDAT0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_SDAT0_SENT_SDAT0_SD_MASK;
    regValue = regValue >> HWIO_SENT_SDAT0_SENT_SDAT0_SD_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_SDAT.bits.SD));
#endif
}//DONE

/**
 * @brief 获取SENT最近一组串行帧的信息ID
 *
 *
 * @ param Channel
 * @ retval uint32_t
 */
KF_INLINE uint32_t Sent_LL_GetCurrnetSerialID(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_SDAT0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_SDAT0_SENT_SDAT0_MID_MASK;
    regValue = regValue >> HWIO_SENT_SDAT0_SENT_SDAT0_MID_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_SDAT.bits.MID));
#endif
}//DONE

/**
 * @brief 获取SENT最近一组串行帧的CRC
 *
 *
 * @ param Channel
 * @ retval uint32_t
 */
KF_INLINE uint32_t Sent_LL_GetCurrnetSerialCRC(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_SDAT0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_SDAT0_SENT_SDAT0_SCRC_MASK;
    regValue = regValue >> HWIO_SENT_SDAT0_SENT_SDAT0_SCRC_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_SDAT.bits.SCRC));
#endif
}//DONE

/**
 * @brief 获取SENT最近一组串行帧的配置
 *
 *
 * @ param Channel
 * @ retval Sent_SerialConfig_t
 */
KF_INLINE Sent_SerialConfig_t Sent_LL_GetCurrnetSerialConfig(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_SDAT0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_SDAT0_SENT_SDAT0_CON_MASK;
    regValue = regValue >> HWIO_SENT_SDAT0_SENT_SDAT0_CON_SHFT;
    return (Sent_SerialConfig_t)regValue;
#else
    return ((Sent_SerialConfig_t)REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_SDAT.bits.CON));
#endif
}//DONE

/**
 * @brief 设置SENT外部输入通道
 *
 *
 * @ param Channel
 * @ param InputChannel
 * @ retval void
 */
KF_INLINE void Sent_LL_SetExternalInputChannel(Sent_ChannelType_t Channel, Sent_ExternalInputChannel_t InputChannel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT(CHECK_EXTERNALINPUT(InputChannel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel);
    regValue &= ~HWIO_SENT_IOCTL0_SENT_IOCTL0_ALTI_MASK;
    regValue |=  InputChannel<<HWIO_SENT_IOCTL0_SENT_IOCTL0_ALTI_SHFT;
    REG_WRITE(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.ALTI, InputChannel);
#endif
}//DONE

/**
 * @brief 设置SENT数字毛刺滤波器深度
 *
 *
 * @ param Channel
 * @ param Depth
 * @ retval void
 */
KF_INLINE void Sent_LL_SetDigitalBurrFilterDepth(Sent_ChannelType_t Channel, const uint32_t Depth)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT((Depth >> POS_4_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_IOCTL0_SENT_IOCTL0_DEPTH_MASK;
    regValue |=  Depth<<HWIO_SENT_IOCTL0_SENT_IOCTL0_DEPTH_SHFT;
    REG_WRITE(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.DEPTH, Depth);
#endif
}//DONE

/**
 * @brief 设置SENT输出反向使能
 *
 *
 * @ param Channel
 * @ param Status
 *         true:脉冲极性为高电平有效
 *         false:脉冲极性为低电平有效
 * @ retval void
 */
KF_INLINE void Sent_LL_EnableInvertedOutput(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_IOCTL0_SENT_IOCTL0_OIE_MASK;
    regValue |=  Status<<HWIO_SENT_IOCTL0_SENT_IOCTL0_OIE_SHFT;
    REG_WRITE(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.OIE, Status);
#endif
}//DONE

/**
 * @brief 设置SENT输入反向使能
 *
 *
 * @ param Channel
 * @ param Status
 *         true:脉冲极性为高电平有效
 *         false:脉冲极性为低电平有效
 * @ retval void
 */
KF_INLINE void Sent_LL_EnableInvertedInput(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_IOCTL0_SENT_IOCTL0_IIE_MASK;
    regValue |=  Status<<HWIO_SENT_IOCTL0_SENT_IOCTL0_IIE_SHFT;
    REG_WRITE(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.IIE, Status);
#endif
}//DONE

/**
 * @brief 设置SENT边沿计数器
 *
 *
 * @ param Channel
 * @ param Status
 *         true:清除边沿计数器
 *         false:无操作
 * @ retval void
 */
KF_INLINE void Sent_LL_ClearEdgeCounter(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_IOCTL0_SENT_IOCTL0_CEC_MASK;
    regValue |=  Status<<HWIO_SENT_IOCTL0_SENT_IOCTL0_CEC_SHFT;
    REG_WRITE(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.CEC, Status);
#endif
}//DONE

/**
 * @brief 获取SENT上升沿是否检测到毛刺状态
 *
 *
 * @ param Channel
 * @ retval Status
 *         true:上升沿检测到毛刺
 *         false:上升沿未检测到毛刺
 */
KF_INLINE bool Sent_LL_GetPosEdgeBurr(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_IOCTL0_SENT_IOCTL0_REG_MASK;
    regValue = regValue >> HWIO_SENT_IOCTL0_SENT_IOCTL0_REG_SHFT;
    return (bool)regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.REG));
#endif
}//DONE

/**
 * @brief 设置SENT下降沿是否检测到毛刺状态
 *
 *
 * @ param Channel
 * @ retval Status
 *         true:下降沿检测到毛刺
 *         false:下降沿未检测到毛刺
 */
KF_INLINE bool Sent_LL_GetNegEdgeBurr(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_IOCTL0_SENT_IOCTL0_FEG_MASK;
    regValue = regValue >> HWIO_SENT_IOCTL0_SENT_IOCTL0_FEG_SHFT;
    return (bool)regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.FEG));
#endif
}//DONE

/**
 * @brief 清除SENT上升沿毛刺标志
 *
 *
 * @ param Channel
 * @ retval Status
 *         true:清除上升沿毛刺
 *         false:不清除上升沿毛刺
 */
KF_INLINE void Sent_LL_ClearPosEdgeBurrState(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_IOCTL0_SENT_IOCTL0_CREG_MASK;
    regValue |=  Status<<HWIO_SENT_IOCTL0_SENT_IOCTL0_CREG_SHFT;
    REG_WRITE(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.CREG, Status);
#endif
}//DONE

/**
 * @brief 清除SENT下降沿毛刺标志
 *
 *
 * @ param Channel
 * @ retval Status
 *         true:清除下降沿毛刺
 *         false:不清除下降沿毛刺
 */
KF_INLINE void Sent_LL_ClearNegEdgeBurrState(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel );
    regValue &= ~HWIO_SENT_IOCTL0_SENT_IOCTL0_CFEG_MASK;
    regValue |=  Status<<HWIO_SENT_IOCTL0_SENT_IOCTL0_CFEG_SHFT;
    REG_WRITE(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel , regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.CFEG, Status);
#endif
}//DONE

/**
 * @brief 设置SENT外部触发选择
 *
 *
 * @ param Channel
 * @ param ExternalTrigger
 * @ retval void
 */
KF_INLINE void Sent_LL_SetExternalTrigger(Sent_ChannelType_t Channel, const Sent_ExternalTrigger_t ExternalTrigger)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_EXTERNALTRIGGER(ExternalTrigger));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel);
    regValue &= ~HWIO_SENT_IOCTL0_SENT_IOCTL0_ETS_MASK;
    regValue |=  ExternalTrigger<<HWIO_SENT_IOCTL0_SENT_IOCTL0_ETS_SHFT;
    REG_WRITE(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel, regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.ETS, ExternalTrigger);
#endif
}//TODO: CFEG 重复，应该是ETS。

/**
 * @brief 获取SENT边沿计数器值
 *
 *
 * @ param Channel
 * @ retval uint32_t:边沿计数器值
 */
KF_INLINE uint32_t Sent_LL_GetEdgeCount(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_IOCTL0_SENT_IOCTL0_ECNT_MASK;
    regValue = regValue >> HWIO_SENT_IOCTL0_SENT_IOCTL0_ECNT_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.ECNT));
#endif
}//DONE

/**
 * @brief 获取SENT触发信号状态
 *
 *
 * @ param Channel
 * @ retval uint32_t:
 */
KF_INLINE uint32_t Sent_LL_GetTriggerState(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_IOCTL0_SENT_IOCTL0_TRM_MASK;
    regValue = regValue >> HWIO_SENT_IOCTL0_SENT_IOCTL0_TRM_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.TRM));
#endif
}//DONE

/**
 * @brief 清除SENT触发信号状态
 *
 *
 * @ param Channel
 * @ param Status
 *         true:清除触发信号状态
 *         false:不清除触发信号状态
 * @ retval void
 */
KF_INLINE void Sent_LL_ClearTriggerState(Sent_ChannelType_t Channel, const bool Status)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_BOOL(Status));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel);
    regValue &= ~HWIO_SENT_IOCTL0_SENT_IOCTL0_CTR_MASK;
    regValue |=  Status<<HWIO_SENT_IOCTL0_SENT_IOCTL0_CTR_SHFT;
    REG_WRITE(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel, regValue);
#else
    REG_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.CTR, Status);
#endif
}//DONE

/**
 * @brief 获取SENT接收信号状态
 *
 *
 * @ param Channel
 * @ retval bool
 *          true:当前接收信号为高
 *          false:当前接收信号为底
 */
KF_INLINE bool Sent_LL_GetRecState(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_IOCTL0_SENT_IOCTL0_RXM_MASK;
    regValue = regValue >> HWIO_SENT_IOCTL0_SENT_IOCTL0_RXM_SHFT;
    return (bool)regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.RXM));
#endif
}//DONE

/**
 * @brief 获取SENT发送信号状态
 *
 *
 * @ param Channel
 * @ retval bool
 *          true:当前发送信号为高
 *          false:当前发送信号为底
 */
KF_INLINE bool Sent_LL_GetSenState(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_IOCTL0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_IOCTL0_SENT_IOCTL0_TXM_MASK;
    regValue = regValue >> HWIO_SENT_IOCTL0_SENT_IOCTL0_TXM_SHFT;
    return (bool)regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_IOCTL.bits.TXM));
#endif
}//DONE

/**
 * @brief 获取SENT中断标志位状态
 *
 *
 * @ param Channel
 * @ param Flag :标志位
 * @ retval bool
 *          true:当前标志位置一
 *          false:当前标志位清零
 */
KF_INLINE bool Sent_LL_GetFlag(Sent_ChannelType_t Channel, Sent_Flag_t Flag)
{
    KF_DRV_SENT_ASSERT(CHECK_FLAG(Flag));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    return ((REG_READ(HWIO_SENT_IF0_ADDR + (0x28)*Channel) & Flag) != false);
#else
    return ((REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_IF.reg) & Flag) != false);
#endif
}//DONE

/**
 * @brief 使能SENT中断
 *
 *
 * @ param Channel
 * @ param Int:中断类型
 * @ retval void
 */
KF_INLINE void Sent_LL_EnableInt(Sent_ChannelType_t Channel, Sent_Int_t Int)
{
    KF_DRV_SENT_ASSERT(CHECK_INT(Int));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    REG_BIT_SET(HWIO_SENT_IE0_ADDR + (0x28)*Channel, Int);
#else
    REG_BIT_SET((SENT_CHANNEL_PTR + Channel)->SENT_IE.reg, Int);
#endif
}//DONE

/**
 * @brief 置位SENTFLAG
 *
 *
 * @ param Channel
 * @ param Flag:标志位
 * @ retval void
 */
KF_INLINE void Sent_LL_SetFlag(Sent_ChannelType_t Channel, Sent_Flag_t Flag)
{
    KF_DRV_SENT_ASSERT(CHECK_FLAG(Flag));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    REG_BIT_SET(HWIO_SENT_IS0_ADDR + (0x28)*Channel, Flag);
#else
    REG_BIT_SET((SENT_CHANNEL_PTR + Channel)->SENT_IS.reg, Flag);
#endif
}//DONE

/**
 * @brief 清零SENTFLAG
 *
 *
 * @ param Channel
 * @ param Flag:标志位
 * @ retval void
 */
KF_INLINE void Sent_LL_ClearFlag(Sent_ChannelType_t Channel, Sent_Flag_t Flag)
{
    KF_DRV_SENT_ASSERT(CHECK_FLAG(Flag));
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    REG_BIT_SET(HWIO_SENT_IC0_ADDR + (0x28)*Channel, Flag);
#else
    REG_BIT_SET((SENT_CHANNEL_PTR + Channel)->SENT_IC.reg, Flag);
#endif
}//DONE

/**
 * @brief 设置SENT中断外部触发通道
 *
 *
 * @ param Channel
 * @ param FlagTrigger:触发标志位
 * @ param ExternalTrigger:外部触发源
 * @ retval void
 */
KF_INLINE void Sent_LL_SetFlagTrigger(
  Sent_ChannelType_t Channel, Sent_FlagTrigger_t FlagTrigger, Sent_ExternalTrigger_t ExternalTrigger)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
    KF_DRV_SENT_ASSERT(CHECK_FLAGTRIGGER(FlagTrigger));
    KF_DRV_SENT_ASSERT(CHECK_EXTERNALTRIGGER(ExternalTrigger));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_SENT_ITRG0_ADDR + (0x28)*Channel, FlagTrigger, ExternalTrigger);
#else
    REG_BITS_WRITE((SENT_CHANNEL_PTR + Channel)->SENT_ITRG.reg, FlagTrigger, ExternalTrigger);
#endif
}//DONE

/**
 * @brief 获取SENT范围检测微调值
 *
 *
 * @ param Channel
 * @ retval uint32_t:范围检测超过允许的+-25%之后的具体值
 */
KF_INLINE uint32_t Sent_LL_GetAdjust(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_SENT_DIVM0_ADDR + (0x28)*Channel);
    regValue &= HWIO_SENT_DIVM0_SENT_DIVM0_DIVM_ADJUST_MASK;
    regValue = regValue >> HWIO_SENT_DIVM0_SENT_DIVM0_DIVM_ADJUST_SHFT;
    return regValue;
#else
    return (REG_READ((SENT_CHANNEL_PTR + Channel)->SENT_DIVM.bits.DIVM_ADJUST));
#endif
}//DONE

/**
 * @brief 获取SENT接收时间戳值
 *
 *
 * @ param Channel
 * @ retval uint32_t:接收时间戳值
 */
KF_INLINE uint32_t Sent_LL_GetPreviousTimeStamp(Sent_ChannelType_t Channel)
{
    KF_DRV_SENT_ASSERT(CHECK_SENT_CHANNEL(Channel));
#ifdef SIMULATION
    return (REG_READ(HWIO_SENT_RTS0_ADDR + (0x4)*Channel));
#else
    return (REG_READ((SENT_RTS_PTR + Channel)->SENT_RTS.reg));
#endif
}//DONE

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
