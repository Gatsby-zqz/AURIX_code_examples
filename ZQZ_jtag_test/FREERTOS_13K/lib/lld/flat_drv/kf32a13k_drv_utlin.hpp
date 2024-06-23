/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_utlin.h
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
#ifndef KF32A13K_DRV_UTLIN_H_
#define KF32A13K_DRV_UTLIN_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_utlin.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>
#ifdef SIMULATION
#define UTLIN_MODULE_BASE_ADDR UTLIN0_ADDR
#include "kf32a13k_reg_simulation_utlin.h"
#endif
#ifdef KF_DRV_Utlin_ASSERT
#include "dev_assert.h"
#define KF_DRV_Utlin_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_Utlin_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
#define HWIO_UTLIN_OCDS_UTLIN_OCDS_SUS_SHIFT      (24U)
#define HWIO_UTLIN_OCDS_UTLIN_OCDS_SUS_MASK       (0x0f000000U)
#define HWIO_UTLIN_OCDS_UTLIN_OCDS_SUS_P_SHIFT    (28U)
#define HWIO_UTLIN_OCDS_UTLIN_OCDS_SUS_P_MASK     (0x10000000U)

typedef enum
{
    UTLIN_NOSUSPEND,
    UTLIN_HARDSUSPEND,
    UTLIN_SOFTSUSPEND,
} Utlin_OcdsSuspendMode_t;

#define CHECK_UTLIN_SUSPENDMODE(Mode)                                                                                  \
    ((Mode == UTLIN_NOSUSPEND) || (Mode == UTLIN_HARDSUSPEND) || (Mode == UTLIN_SOFTSUSPEND))

typedef enum
{
    INPUT_CHANNEL_A,
    INPUT_CHANNEL_B,
    INPUT_CHANNEL_C,
    INPUT_CHANNEL_D,
    INPUT_CHANNEL_E,
    INPUT_CHANNEL_F,
    INPUT_CHANNEL_G,
    INPUT_CHANNEL_H
} Utlin_InputChannel_t;

#define CHECK_UTLIN_INPUTCHANNEL(Channel) ((Channel >> POS_3_SHIFT) == 0U)

typedef enum
{
    CTSA,
    CTSB,
    CTSC,
    CTSD,
} Utlin_InputCTSChannel_t;

#define CHECK_UTLIN_INPUTCTSCHANNEL(Channel) ((Channel >> POS_2_SHIFT) == 0U)

typedef enum
{
    VALID_HIGH,
    VALID_LOW,
} Utlin_Polarity_t;

#define CHECK_UTLIN_POLARITY(Polarity) ((Polarity == VALID_HIGH) || (Polarity == VALID_LOW))

typedef enum
{
    COMBINED_TRANSMISSION,
    UTLIN_SINGLE_TRANSMISSION,
    BULK_TRANSMISSION,
} Utlin_FifoMode_t;

#define CHECK_UTLIN_FIFOMODE(Mode)                                                                                     \
    ((Mode == COMBINED_TRANSMISSION) || (Mode == UTLIN_SINGLE_TRANSMISSION) || (Mode == BULK_TRANSMISSION))

typedef enum
{
    ENABLE_SWITCH,
    DISABLE_SWITCH,
} Utlin_ModeSwitch_t;

#define CHECK_UTLIN_MODESWITCH(Switch) ((Switch == ENABLE_SWITCH) || (Switch == DISABLE_SWITCH))

#define CHECK_UTLIN_PARITYCHECKMODE(Mode) ((Mode == Utlin_EVEN_CHECK) || (Mode == Utlin_ODD_CHECK))

typedef enum
{
    HEAD_AND_RESPONSE,
    HEAD_ONLY,
} Utlin_LinSendFrameHeadFormat_t;

#define CHECK_UTLIN_SENDFRAMEHEAD(HeadFromat) ((HeadFromat == HEAD_AND_RESPONSE) || (HeadFromat == HEAD))

typedef enum
{
    UTLIN_FRAME_TIMEOUT,
    UTLIN_RESPONSE_TIMEOUT,
} Utlin_LinResPonseTimeoutMode_t;

#define CHECK_UTLIN_RESPONSEMODE(ResPonse) ((ResPonse == UTLIN_FRAME_TIMEOUT) || (ResPonse == UTLIN_RESPONSE_TIMEOUT))

typedef enum
{
    CLASSIC_CHECK,
    ENHANCED_CHECK,
} Utlin_LinCheckMode_t;

#define CHECK_UTLIN_CHECKMODE(CheckMode) ((CheckMode == CLASSIC_CHECK) || (CheckMode == ENHANCED_CHECK))

typedef enum
{
    LIN_SLAVE,
    LIN_MASTER,
} Utlin_LinMode_t;

#define CHECK_UTLIN_NODEMODE(NodeMode) ((NodeMode == LIN_MASTER) || (NodeMode == LIN_SLAVE))

typedef enum
{
    SEND_FRAMEHEAD_END_IF           = 0U,
    SEND_FRAMRESPONSE_END_IF        = 1U,
    RECEIVE_FRAMEHEAD_END_IF        = 2U,
    RECEIVE_FRAMERESPONSE_END_IF    = 3U,
    DETECT_FAILEDGE_IF              = 5U,
    DETECT_RISEEDGE_IF              = 6U,
    SEND_WAKEUP_RESQUEST_IF         = 13U,
    SEND_FRAMEHEAD_RESQUEST_IF      = 14U,
    SEND_FRAMERSPONSE_RESQUEST_IF   = 15U,
    VERIFICATION_ERROR_IF           = 16U,
    TRANSMISSION_END_IF             = 17U,
    FRAME_ERROR_IF                  = 18U,
    FRAME_HEAD_TIMEOUT_IF           = 19U,
    FRAME_RESPONSE_TIMEOUT_IF       = 20U,
    BREAK_FIELD_DETECTED_IF         = 21U,
    LIN_PARITY_ERROR_IF             = 22U,
    LIN_BAUDRATEAUTODETECT_ERROR_IF = 23U,
    LIN_CHECKSUM_ERROR_IF           = 24U,
    COLLISIONDETECT_ERROR_IF        = 25U,
    RXFIFO_OVERFLOW_IF              = 26U,
    RXFIFO_UNDERFLOW_IF             = 27U,
    RXFIFO_COUNT_IF                 = 28U,
    TXFIFO_OVERFLOW_IF              = 30U,
    TXFIFO_COUNT_IF                 = 31U,
} Utlin_FlagType_t;

#define CHECK_UTLIN_FLAG(Flag)                                                                                         \
    ((Flag == SEND_FRAMEHEAD_END_IF) || (Flag == SEND_FRAMRESPONSE_END_IF) || (Flag == RECEIVE_FRAMEHEAD_END_IF) ||    \
     (Flag == RECEIVE_FRAMERESPONSE_END_IF) || (Flag == DETECT_FAILEDGE_IF) || (Flag == DETECT_POSEDGE_IF) ||          \
     (Flag == SEND_WAKEUP_RESQUEST_IF) || (Flag == SEND_FRAMEHEAD_RESQUEST_IF) ||                                      \
     (Flag == SEND_FRAMERSPONSE_RESQUEST_IF) || (Flag == FRAME_HEAD_TIMEOUT_IF) ||                                     \
     (Flag == FRAME_RESPONSE_TIMEOUT_IF) || (Flag == BREAK_FIELD_DETECTED_IF) || (Flag == LIN_PARITY_ERROR_IF) ||      \
     (Flag == LIN_BAUDRATEAUTODETECT_ERROR_IF) || (Flag == LIN_CHECKSUM_ERROR_IF) ||                                   \
     (Flag == COLLISIONDETECT_ERROR_IF) || (Flag == RXFIFO_OVERFLOW_IF) || (Flag == RXFIFO_UNDERFLOW_IF) ||            \
     (Flag == RXFIFO_COUNT_IF) || (Flag == TXFIFO_OVERFLOW_IF) || (Flag == TXFIFO_COUNT_IF))

typedef enum
{
    SEND_FRAMEHEAD_END_INT           = 0U,
    SEND_FRAMRESPONSE_END_INT        = 1U,
    RECEIVE_FRAMEHEAD_END_INT        = 2U,
    RECEIVE_FRAMERESPONSE_END_INT    = 3U,
    DETECT_NEGEDGE_INT               = 5U,
    DETECT_POSEDGE_INT               = 6U,
    VERIFICATION_ERROR_INT           = 16U,
    TRANSMISSION_END_INT             = 17U,
    FRAME_ERROR_INT                  = 18U,
    FRAME_HEAD_TIMEOUT_INT           = 19U,
    FRAME_RESPONSE_TIMEOUT_INT       = 20U,
    BREAK_FIELD_DETECTED_INT         = 21U,
    LIN_PARITY_ERROR_INT             = 22U,
    LIN_BAUDRATEAUTODETECT_ERROR_INT = 23U,
    LIN_CHECKSUM_ERROR_INT           = 24U,
    COLLISIONDETECT_ERROR_INT        = 25U,
    RXFIFO_OVERFLOW_INT              = 26U,
    RXFIFO_UNDERFLOW_INT             = 27U,
    RXFIFO_COUNT_INT                 = 28U,
    TXFIFO_OVERFOLW_INT              = 30U,
    TXFIFO_COUNT_INT                 = 31U,
} Utlin_IntType_t;

#define CHECK_UTLIN_INT(Int)                                                                                           \
    ((Int == SEND_FRAMEHEAD_END_INT) || (Int == SEND_FRAMRESPONSE_END_INT) || (Int == RECEIVE_FRAMEHEAD_END_INT) ||    \
     (Int == RECEIVE_FRAMERESPONSE_END_INT) || (Int == DETECT_NEGEDGE_INT) || (Int == DETECT_POSEDGE_INT) ||           \
     (Int == VERIFICATION_ERROR_INT) || (Int == TRANSMISSION_END_INT) || (Int == FRAME_ERROR_INT) ||                   \
     (Int == FRAME_HEAD_TIMEOUT_INT) || (Int == FRAME_RESPONSE_TIMEOUT_INT) || (Int == BREAK_FIELD_DETECTED_INT) ||    \
     (Int == LIN_PARITY_ERROR_INT) || (Int == LIN_BAUDRATEAUTODETECT_ERROR_INT) || (Int == LIN_CHECKSUM_ERROR_INT) ||  \
     (Int == COLLISIONDETECT_ERROR_INT) || (Int == RXFIFO_OVERFLOW_INT) || (Int == RXFIFO_UNDERFLOW_INT) ||            \
     (Int == RXFIFO_COUNT_INT) || (Int == TXFIFO_OVERFOLW_INT) || (Int == TXFIFO_COUNT_INT))

typedef enum
{
    UTLIN_NO_CLOCK = 0U,
    UTLIN_F_CLOCK  = 2U,
    UTLIN_S_CLOCK  = 4U,
} Utlin_ClockSourceType_t;

#define CHECK_UTLIN_INPUTCLOCK(Clock)                                                                                  \
    ((Clock == UTLIN_NO_CLOCK) || (Clock == UTLIN_F_CLOCK) || (Clock == UTLIN_S_CLOCK))

typedef enum
{
    UTLIN_ACCESS_ENABLE_0,
    UTLIN_ACCESS_ENABLE_1,
    UTLIN_ACCESS_ENABLE_2,
    UTLIN_ACCESS_ENABLE_3,
    UTLIN_ACCESS_ENABLE_4,
    UTLIN_ACCESS_ENABLE_5,
    UTLIN_ACCESS_ENABLE_6,
    UTLIN_ACCESS_ENABLE_7,
    UTLIN_ACCESS_ENABLE_8,
    UTLIN_ACCESS_ENABLE_9,
    UTLIN_ACCESS_ENABLE_10,
    UTLIN_ACCESS_ENABLE_11,
    UTLIN_ACCESS_ENABLE_12,
    UTLIN_ACCESS_ENABLE_13,
    UTLIN_ACCESS_ENABLE_14,
    UTLIN_ACCESS_ENABLE_15,
    UTLIN_ACCESS_ENABLE_16,
    UTLIN_ACCESS_ENABLE_17,
    UTLIN_ACCESS_ENABLE_18,
    UTLIN_ACCESS_ENABLE_19,
    UTLIN_ACCESS_ENABLE_20,
    UTLIN_ACCESS_ENABLE_21,
    UTLIN_ACCESS_ENABLE_22,
    UTLIN_ACCESS_ENABLE_23,
    UTLIN_ACCESS_ENABLE_24,
    UTLIN_ACCESS_ENABLE_25,
    UTLIN_ACCESS_ENABLE_26,
    UTLIN_ACCESS_ENABLE_27,
    UTLIN_ACCESS_ENABLE_28,
    UTLIN_ACCESS_ENABLE_29,
    UTLIN_ACCESS_ENABLE_30,
    UTLIN_ACCESS_ENABLE_31,
} Utlin_AccessEnableType_t;

#define CHECK_UTLIN_ACCESSENABLE(AccessEnable) ((AccessEnable >> POS_5_SHIFT) == 0U)

/** \brief Defines the bit length in ticks in the range of 1 to 16. The lengths of 1 to 3 are not allowed\n
 * Definition in KF_ASCLIN.BITCON.B.OVERSAMPLING
 */
typedef enum
{
    UTLIN_OVERSAMPLINGFACTOR_4  = 3U,
    UTLIN_OVERSAMPLINGFACTOR_5  = 4U,
    UTLIN_OVERSAMPLINGFACTOR_6  = 5U,
    UTLIN_OVERSAMPLINGFACTOR_7  = 6U,
    UTLIN_OVERSAMPLINGFACTOR_8  = 7U,
    UTLIN_OVERSAMPLINGFACTOR_9  = 8U,
    UTLIN_OVERSAMPLINGFACTOR_10 = 9U,
    UTLIN_OVERSAMPLINGFACTOR_11 = 10U,
    UTLIN_OVERSAMPLINGFACTOR_12 = 11U,
    UTLIN_OVERSAMPLINGFACTOR_13 = 12U,
    UTLIN_OVERSAMPLINGFACTOR_14 = 13U,
    UTLIN_OVERSAMPLINGFACTOR_15 = 14U,
    UTLIN_OVERSAMPLINGFACTOR_16 = 15U,
} Utlin_OversamplingFactorType_t;

/** \brief Number of samples per bit, sample mode/medianfilter\n
 * Definition in KF_ASCLIN.BITCON.B.SM
 */
typedef enum
{
    UTLIN_SAMPLESPERBIT_ONE,
    UTLIN_SAMPLESPERBIT_THREE,
} Utlin_SampleMode_t;

/** \brief Sample point position\n
 * Definition in KF_ASCLIN.BITCON.B.SAMPLEPOINT
 */
typedef enum
{
    UTLIN_SAMPLEPOINTPOSITION_1 = 1U,
    UTLIN_SAMPLEPOINTPOSITION_2,
    UTLIN_SAMPLEPOINTPOSITION_3,
    UTLIN_SAMPLEPOINTPOSITION_4,
    UTLIN_SAMPLEPOINTPOSITION_5,
    UTLIN_SAMPLEPOINTPOSITION_6,
    UTLIN_SAMPLEPOINTPOSITION_7,
    UTLIN_SAMPLEPOINTPOSITION_8,
    UTLIN_SAMPLEPOINTPOSITION_9,
    UTLIN_SAMPLEPOINTPOSITION_10,
    UTLIN_SAMPLEPOINTPOSITION_11,
    UTLIN_SAMPLEPOINTPOSITION_12,
    UTLIN_SAMPLEPOINTPOSITION_13,
    UTLIN_SAMPLEPOINTPOSITION_14,
    UTLIN_SAMPLEPOINTPOSITION_15,
} Utlin_SamplePointPositionType_t;

/** \brief Defines the number of bytes written to the Tx FIFO with one FPI bus write\n
 * Definition in KF_ASCLIN.TXFIFOCON.B.INW
 */
typedef enum
{
    UTLIN_TXFIFOINPUTWIDTH_0,
    UTLIN_TXFIFOINPUTWIDTH_1,
    UTLIN_TXFIFOINPUTWIDTH_2,
    UTLIN_TXFIFOINPUTWIDTH_3,
} Utlin_TxFifoInputWidthType_t;

/** \brief Defines the number of bytes read from the Rx FIFO with one FPI bus read\n
 * Definition in KF_ASCLIN.RXFIFOCON.B.OUTW
 */
typedef enum
{
    UTLIN_RXFIFOOUTPUTWIDTH_0,
    UTLIN_RXFIFOOUTPUTWIDTH_1,
    UTLIN_RXFIFOOUTPUTWIDTH_2,
    UTLIN_RXFIFOOUTPUTWIDTH_3,
} Utlin_RxFifoOutputWidthType_t;

/** \brief Defines the filling level that triggers a refill (TX) interrupt or DMA access\n
 * Definition in KF_ASCLIN.TXFIFOCON.B.INTLEVEL
 */
typedef enum
{
    UTLIN_TXFIFOINTERRUPTLEVEL_0,
    UTLIN_TXFIFOINTERRUPTLEVEL_1,
    UTLIN_TXFIFOINTERRUPTLEVEL_2,
    UTLIN_TXFIFOINTERRUPTLEVEL_3,
    UTLIN_TXFIFOINTERRUPTLEVEL_4,
    UTLIN_TXFIFOINTERRUPTLEVEL_5,
    UTLIN_TXFIFOINTERRUPTLEVEL_6,
    UTLIN_TXFIFOINTERRUPTLEVEL_7,
    UTLIN_TXFIFOINTERRUPTLEVEL_8,
    UTLIN_TXFIFOINTERRUPTLEVEL_9,
    UTLIN_TXFIFOINTERRUPTLEVEL_10,
    UTLIN_TXFIFOINTERRUPTLEVEL_11,
    UTLIN_TXFIFOINTERRUPTLEVEL_12,
    UTLIN_TXFIFOINTERRUPTLEVEL_13,
    UTLIN_TXFIFOINTERRUPTLEVEL_14,
    UTLIN_TXFIFOINTERRUPTLEVEL_15,
} Utlin_TxFifoInterruptLevelType_t;

/** \brief Defines the filling level that triggers a drain (RX) interrupt or DMA access\n
 * Definition in KF_ASCLIN.RXFIFOCON.B.INTLEVEL
 */
typedef enum
{
    UTLIN_RXFIFOINTERRUPTLEVEL_1,
    UTLIN_RXFIFOINTERRUPTLEVEL_2,
    UTLIN_RXFIFOINTERRUPTLEVEL_3,
    UTLIN_RXFIFOINTERRUPTLEVEL_4,
    UTLIN_RXFIFOINTERRUPTLEVEL_5,
    UTLIN_RXFIFOINTERRUPTLEVEL_6,
    UTLIN_RXFIFOINTERRUPTLEVEL_7,
    UTLIN_RXFIFOINTERRUPTLEVEL_8,
    UTLIN_RXFIFOINTERRUPTLEVEL_9,
    UTLIN_RXFIFOINTERRUPTLEVEL_10,
    UTLIN_RXFIFOINTERRUPTLEVEL_11,
    UTLIN_RXFIFOINTERRUPTLEVEL_12,
    UTLIN_RXFIFOINTERRUPTLEVEL_13,
    UTLIN_RXFIFOINTERRUPTLEVEL_14,
    UTLIN_RXFIFOINTERRUPTLEVEL_15,
    UTLIN_RXFIFOINTERRUPTLEVEL_16,
} Utlin_RxFifoInterruptLevelType_t;

/** \brief Defines the duration of the IDLE delay in bit times.\n
 * SPI mode: this is the idle time between the Frames.\n
 * ASC and LIN mode: this is the pause inserted between transmission of bytes.\n
 * Definition in KF_ASCLIN.FRAMECON.B.IDLE
 */
typedef enum
{
    UTLIN_IDLEDELAY_0,
    UTLIN_IDLEDELAY_1,
    UTLIN_IDLEDELAY_2,
    UTLIN_IDLEDELAY_3,
    UTLIN_IDLEDELAY_4,
    UTLIN_IDLEDELAY_5,
    UTLIN_IDLEDELAY_6,
    UTLIN_IDLEDELAY_7,
} Utlin_IdleDelayType_t;

/** \brief Defines the leading delay in bit times in SPI mode. ASC mode: not applicable.\n
 * LIN mode: delay between the end of the break and the start of the sync character.\n
 * Definition in Ifx_ASCLIN.FRAMECON.B.LEAD
 */
typedef enum
{
    UTLIN_LEADDELAY_0,
    UTLIN_LEADDELAY_1,
    UTLIN_LEADDELAY_2,
    UTLIN_LEADDELAY_3,
    UTLIN_LEADDELAY_4,
    UTLIN_LEADDELAY_5,
    UTLIN_LEADDELAY_6,
    UTLIN_LEADDELAY_7,
} Utlin_LeadDelayType_t;

typedef enum
{
    STOP_0_BIT,
    STOP_1_BIT,
} Utlin_StopBitType_t;

#define CHECK_UTLIN_STOPBIT(StopBit) ((StopBit == STOP_0_BIT) || (StopBit == STOP_1_BIT))

/** \brief Defines the basic operating mode of the module. Changing the mode must be done by switching first to
 * initialize mode, and then to the other mode.\n Definition in KF_ASCLIN.FRAMECON.B.MODE
 */
typedef enum
{
    UTLIN_FRAMEMODE_INIT = 1U, /**< \BRIEF INITIALISE MODE */
    UTLIN_FRAMEMODE_UART = 3U, /**< \BRIEF UART MODE */
    UTLIN_FRAMEMODE_LIN  = 5U, /**< \brief lin mode */
} Utlin_FrameModeType_t;

/** \brief Type of parity bit attached to data bits\n
 * Definition in KF_ASCLIN.FRAMECON.B.ODD
 */
typedef enum
{
    UTLIN_PARITY_EVEN,
    UTLIN_PARITY_ODD,
} Utlin_ParityMode_t;

/** \brief Number of bits per transfer\n
 * Definition in KF_ASCLIN.FRAMECON.B.DATALEN
 */
typedef enum
{
    UTLIN_DATALENGTH_1  = 0U,  /**< \BRIEF NUMBER OF BITS PER TRANSFER 0  */
    UTLIN_DATALENGTH_2  = 1U,  /**< \BRIEF NUMBER OF BITS PER TRANSFER 1  */
    UTLIN_DATALENGTH_3  = 2U,  /**< \BRIEF NUMBER OF BITS PER TRANSFER 2  */
    UTLIN_DATALENGTH_4  = 3U,  /**< \BRIEF NUMBER OF BITS PER TRANSFER 3  */
    UTLIN_DATALENGTH_5  = 4U,  /**< \BRIEF NUMBER OF BITS PER TRANSFER 4  */
    UTLIN_DATALENGTH_6  = 5U,  /**< \BRIEF NUMBER OF BITS PER TRANSFER 5  */
    UTLIN_DATALENGTH_7  = 6U,  /**< \BRIEF NUMBER OF BITS PER TRANSFER 6  */
    UTLIN_DATALENGTH_8  = 7U,  /**< \BRIEF NUMBER OF BITS PER TRANSFER 7  */
    UTLIN_DATALENGTH_9  = 8U,  /**< \BRIEF NUMBER OF BITS PER TRANSFER 8  */
    UTLIN_DATALENGTH_10 = 9U,  /**< \BRIEF NUMBER OF BITS PER TRANSFER 9  */
    UTLIN_DATALENGTH_11 = 10U, /**< \BRIEF NUMBER OF BITS PER TRANSFER 10  */
    UTLIN_DATALENGTH_12 = 11U, /**< \BRIEF NUMBER OF BITS PER TRANSFER 11  */
    UTLIN_DATALENGTH_13 = 12U, /**< \BRIEF NUMBER OF BITS PER TRANSFER 12  */
    UTLIN_DATALENGTH_14 = 13U, /**< \BRIEF NUMBER OF BITS PER TRANSFER 13  */
    UTLIN_DATALENGTH_15 = 14U, /**< \BRIEF NUMBER OF BITS PER TRANSFER 14  */
    UTLIN_DATALENGTH_16 = 15U, /**< \brief number of bits per transfer 15  */
} Utlin_DataLengthType_t;

/** \brief Defines the type of Lin Master Frame. */
typedef enum
{
    UTLIN_TRANSMIT_HEADER,
    UTLIN_TRANSMIT_HEADER_AND_RESPONSE,
    UTLIN_TRANSMIT_HEADER_AND_RECEIVE_RESPONSE,
} Utlin_LinDirection;

typedef enum
{
    UTLIN_HEADERANDRESPONSE,
    UTLIN_HEADERONLY,
} Utlin_SendHeaderFormat_t;

/** \brief Defines if the received Checksum byte is written into the RXFifo or not.\n
 * Definition in Ifx_ASCLIN.LIN.CON.B.CSI
 */
typedef enum
{
    UTLIN_CHECKSUMINJECTION_NOTWRITTEN,
    UTLIN_CHECKSUMINJECTION_WRITTEN,
} Utlin_ChecksumInjectionType_t;

#define CHECK_UTLIN_BOOL(Bool) ((Bool >> POS_1_SHIFT) == 0U)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief 获取UTLIN模块版本信息
 *
 *
 * @param void
 * @retval uint32_t 模块版本
 */
KF_INLINE uint32_t Utlin_LL_GetModuleVersion(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_ID_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_ID_UTLIN0_ID_MODREV_MASK;
    regValue = regValue >> HWIO_UTLIN0_ID_UTLIN0_ID_MODREV_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_ID.bits.MODREV));
#endif
}

/**
 * @brief 获取UTLIN模块类型信息
 *
 *
 * @param void
 * @retval uint32_t 模块类型
 */
KF_INLINE uint32_t Utlin_LL_GetModuleType(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_ID_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_ID_UTLIN0_ID_MODETYPE_MASK;
    regValue = regValue >> HWIO_UTLIN0_ID_UTLIN0_ID_MODETYPE_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_ID.bits.MODETYPE));
#endif
}

/**
 * @brief 获取UTLIN模块ID信息
 *
 *
 * @param void
 * @retval uint32_t 模块ID
 */
KF_INLINE uint32_t Utlin_LL_GetModuleId(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_ID_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_ID_UTLIN0_ID_MODENUMBER_MASK;
    regValue = regValue >> HWIO_UTLIN0_ID_UTLIN0_ID_MODENUMBER_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_ID.bits.MODENUMBER));
#endif
}

/**
 * @brief UTLIN模块使能/禁止
 *
 *
 * @param Status:
 *        false   UTLIN使能
 *        true   UTLIN禁止
 * @retval void
 */
KF_INLINE void Utlin_LL_SetModuleDisStatus(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_CLTR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_CLTR_UTLIN0_CLTR_DISR_MASK;
    regValue |= Status << HWIO_UTLIN0_CLTR_UTLIN0_CLTR_DISR_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_CLTR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_CLTR.bits.DISR, Status);
#endif
}

/**
 * @brief UTLIN获取模块禁止状态
 *
 *
 * @param void
 * @retval bool
 *        false UTLIN模块已使能
 *        true UTLIN模块已禁止
 */
KF_INLINE bool Utlin_LL_GetModuleStatus(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_CLTR_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_CLTR_UTLIN0_CLTR_DISS_MASK;
    regValue = regValue >> HWIO_UTLIN0_CLTR_UTLIN0_CLTR_DISS_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_CLTR.bits.DISS));
#endif
}

/**
 * @brief UTLIN设置休眠模式
 *
 *
 * @param Status:
 *        false   UTLIN关闭休眠模式
 *        true   UTLIN进入休眠模式
 * @retval void
 */
KF_INLINE void Utlin_LL_SetSleepModeEnabled(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_CLTR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_CLTR_UTLIN0_CLTR_EDIS_MASK;
    regValue |= Status << HWIO_UTLIN0_CLTR_UTLIN0_CLTR_EDIS_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_CLTR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_CLTR.bits.EDIS, Status);
#endif
}

/**
 * @brief UTLIN设置OCDS暂停模式
 *
 *
 * @param OcdsSuspendMode
 *        Utlin_OCDS_SUS_NOSTOP
 *        Utlin_OCDS_SUS_HARDSTOP
 *        Utlin_OCDS_SUS_SOFTSTO
 * @retval void
 */
KF_INLINE void
Utlin_LL_SetOcdsSuspendMode(Utlin_RegisterMap_t *const Module, const Utlin_OcdsSuspendMode_t OcdsSuspendMode)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_SUSPENDMODE(OcdsSuspendMode));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_OCDS_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_OCDS_UTLIN0_OCDS_SUS_P_MASK;
    regValue |= true << HWIO_UTLIN0_OCDS_UTLIN0_OCDS_SUS_P_SHFT;
    regValue &= ~HWIO_UTLIN0_OCDS_UTLIN0_OCDS_SUS_MASK;
    regValue |= OcdsSuspendMode << HWIO_UTLIN0_OCDS_UTLIN0_OCDS_SUS_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_OCDS_ADDR, regValue);
    // TODO: check if correct

#else
    uint32_t regValue = REG_READ(Module->UTLIN_OCDS.reg);
    regValue &= ~HWIO_UTLIN_OCDS_UTLIN_OCDS_SUS_P_MASK;
    regValue |= true << HWIO_UTLIN_OCDS_UTLIN_OCDS_SUS_P_SHIFT;
    regValue &= ~HWIO_UTLIN_OCDS_UTLIN_OCDS_SUS_MASK;
    regValue |= OcdsSuspendMode << HWIO_UTLIN_OCDS_UTLIN_OCDS_SUS_SHIFT;
    REG_WRITE(Module->UTLIN_OCDS.reg, regValue);
#endif
}

/**
 * @brief UTLIN获取OCDS暂停模式
 *
 *
 * @param void
 * @retval OcdsSuspendMode
 *         Utlin_OCDS_SUS_NOSTOP
 *         Utlin_OCDS_SUS_HARDSTOP
 *         Utlin_OCDS_SUS_SOFTSTO
 */
KF_INLINE Utlin_OcdsSuspendMode_t Utlin_LL_GetOcdsSuspendMode(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_OCDS_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_OCDS_UTLIN0_OCDS_SUS_MASK;
    regValue = regValue >> HWIO_UTLIN0_OCDS_UTLIN0_OCDS_SUS_SHFT;
    return ((Utlin_OcdsSuspendMode_t)(regValue));
    // TODO: check if correct

#else
    return ((Utlin_OcdsSuspendMode_t)REG_READ(Module->UTLIN_OCDS.bits.SUS));
#endif
}

/**
 * @brief UTLIN获取OCDS暂停状态
 *
 *
 * @param void
 * @retval bool
 *         false  UTLINOCDS未暂停
 *         true   UTLINOCDS已暂停
 */
KF_INLINE bool Utlin_LL_GetOcdsSuspend(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_OCDS_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_OCDS_UTLIN0_OCDS_SUSSTA_MASK;
    regValue = regValue >> HWIO_UTLIN0_OCDS_UTLIN0_OCDS_SUSSTA_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_OCDS.bits.SUSSTA));
#endif
}

/**
 * @brief UTLIN设置输入通道
 *
 *
 * @param InputChannel
 *        INPUT_CHANNEL_A
 *        INPUT_CHANNEL_B
 *        INPUT_CHANNEL_C
 *        INPUT_CHANNEL_D
 *        INPUT_CHANNEL_E
 *        INPUT_CHANNEL_F
 *        INPUT_CHANNEL_G
 *        INPUT_CHANNEL_H
 * @retval void
 */
KF_INLINE void Utlin_LL_SetRxInput(Utlin_RegisterMap_t *const Module, Utlin_InputChannel_t InputChannel)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_INPUTCHANNEL(InputChannel));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_IOCR_UTLIN0_IOCR_ALTI_MASK;
    regValue |= InputChannel << HWIO_UTLIN0_IOCR_UTLIN0_IOCR_ALTI_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IOCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IOCR.bits.ALTI, InputChannel);
#endif
}

/**
 * @brief UTLIN设置数字滤波深度
 *
 *
 * @param Depth
 * @retval void
 */
KF_INLINE void Utlin_LL_SetDigitalBurrFilterDepth(Utlin_RegisterMap_t *const Module, const uint32_t Depth)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((Depth >> POS_6_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_IOCR_UTLIN0_IOCR_DEPTH_MASK;
    regValue |= Depth << HWIO_UTLIN0_IOCR_UTLIN0_IOCR_DEPTH_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IOCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IOCR.bits.DEPTH, Depth);
#endif
}

/**
 * @brief UTLIN设置CTS输入引脚
 *
 *
 * @param CTSChannel
 *        CTSA
 *        CTSB
 *        CTSC
 *        CTSD
 * @retval void
 */
KF_INLINE void Utlin_LL_SetCts(Utlin_RegisterMap_t *const Module, const Utlin_InputCTSChannel_t CTSChannel)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_INPUTCTSCHANNEL(CTSChannel));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_IOCR_UTLIN0_IOCR_CTS_MASK;
    regValue |= CTSChannel << HWIO_UTLIN0_IOCR_UTLIN0_IOCR_CTS_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IOCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IOCR.bits.CTS, CTSChannel);
#endif
}

/**
 * @brief UTLIN设置极性位
 *
 *
 * @param CTSChannel
 *        VALID_HIGH
 *        VALID_LOW
 * @retval void
 */
KF_INLINE void Utlin_LL_SetPolarity(Utlin_RegisterMap_t *const Module, const Utlin_Polarity_t Polarity)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_POLARITY(Polarity));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_IOCR_UTLIN0_IOCR_RCPOL_MASK;
    regValue |= Polarity << HWIO_UTLIN0_IOCR_UTLIN0_IOCR_RCPOL_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IOCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IOCR.bits.RCPOL, Polarity);
#endif
}

/**
 * @brief UTLIN设置回环模式
 *
 *
 * @param Status
 *         false  禁止回环模式
 *         true   使能回环模式
 * @retval void
 */
KF_INLINE void Utlin_LL_SetLoopMode(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_IOCR_UTLIN0_IOCR_LB_MASK;
    regValue |= Status << HWIO_UTLIN0_IOCR_UTLIN0_IOCR_LB_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IOCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IOCR.bits.LB, Status);
#endif
}

/**
 * @brief UTLIN使能输入CTS设置
 *
 *
 * @param Status
 *         false  禁止输入CTS
 *         true   使能输入CTS
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableInputCTS(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_IOCR_UTLIN0_IOCR_CTEN_MASK;
    regValue |= Status << HWIO_UTLIN0_IOCR_UTLIN0_IOCR_CTEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IOCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IOCR.bits.CTEN, Status);
#endif
}

/**
 * @brief UTLIN获取接收状态
 *
 *
 * @param void
 * @retval bool
 *         false:当前信号为底
 *         true:当前信号为高
 */
KF_INLINE bool Utlin_LL_GetReceiveState(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_IOCR_UTLIN0_IOCR_RXM_MASK;
    regValue = regValue >> HWIO_UTLIN0_IOCR_UTLIN0_IOCR_RXM_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_IOCR.bits.RXM));
#endif
}

/**
 * @brief UTLIN获取发送状态
 *
 *
 * @param void
 * @retval bool
 *         false:当前信号为底
 *         true:当前信号为高
 */
KF_INLINE bool Utlin_LL_GetSendState(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_IOCR_UTLIN0_IOCR_TXM_MASK;
    regValue = regValue >> HWIO_UTLIN0_IOCR_UTLIN0_IOCR_TXM_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_IOCR.bits.TXM));
#endif
}

/**
 * @brief UTLIN清空TXFIFO
 *
 *
 * @param Status
 *        true:清空TXFIFO
 *        false:无操作
 * @retval void
 */
KF_INLINE void Utlin_LL_ClearTxFifo(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_TXFIFO_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_TXFIFORST_MASK;
    regValue |= Status << HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_TXFIFORST_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_TXFIFO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_TXFIFO.bits.TXFIFORST, Status);
#endif
}

/**
 * @brief UTLIN使能TXFIFO
 *
 *
 * @param Status
 *        true:使能TXFIFO
 *        false:禁止TXFIFO
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableTxFifo(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_TXFIFO_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_TXFIFOEN_MASK;
    regValue |= Status << HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_TXFIFOEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_TXFIFO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_TXFIFO.bits.TXFIFOEN, Status);
#endif
}

/**
 * @brief UTLIN设置TXFIFO传输模式
 *
 *
 * @param Mode
 *        COMBINED_TRANSMISSION:组合传输
 *        UTLIN_SINGLE_TRANSMISSION:单次传输
 *        BULK_TRANSMISSION:批量传输
 * @retval void
 */
KF_INLINE void Utlin_LL_SetTxFifoMode(Utlin_RegisterMap_t *const Module, const Utlin_FifoMode_t Mode)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_FIFOMODE(Mode));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_TXFIFO_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_TXFIFOMOD_MASK;
    regValue |= Mode << HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_TXFIFOMOD_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_TXFIFO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_TXFIFO.bits.TXFIFOMOD, Mode);
#endif
}

/**
 * @brief UTLIN设置TXFIFO输入宽度
 *
 *
 * @param InPutWidth
 *        TXFIFO_INPUT_0BYTE
 *        TXFIFO_INPUT_1BYTE
 *        TXFIFO_INPUT_2BYTE
 *        TXFIFO_INPUT_4BYTE
 * @retval void
 */
KF_INLINE void
Utlin_LL_SetTxFifoInputWidth(Utlin_RegisterMap_t *const Module, const Utlin_TxFifoInputWidthType_t InPutWidth)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_FIFOINPUTWIDTH(InPutWidth));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_TXFIFO_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_TXFIFOINW_MASK;
    regValue |= InPutWidth << HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_TXFIFOINW_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_TXFIFO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_TXFIFO.bits.TXFIFOINW, InPutWidth);
#endif
}

/**
 * @brief UTLIN使能TXFIFO中断等级
 *
 *
 * @param IntLevel 中断等级
 * @retval void
 */
KF_INLINE void Utlin_LL_SetTxFifoIntLevel(Utlin_RegisterMap_t *const Module, const uint32_t IntLevel)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((IntLevel >> POS_4_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_TXFIFO_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_IFTHRES_MASK;
    regValue |= IntLevel << HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_IFTHRES_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_TXFIFO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_TXFIFO.bits.IFTHRES, IntLevel);
#endif
}

/**
 * @brief UTLIN获取TXFIFO值
 *
 *
 * @param void
 * @retval uint32_t TXFIFO值
 */
KF_INLINE uint32_t Utlin_LL_GetTxFifoCount(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_TXFIFO_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_FIFOCNT_MASK;
    regValue = regValue >> HWIO_UTLIN0_TXFIFO_UTLIN0_TXFIFO_FIFOCNT_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_TXFIFO.bits.FIFOCNT));
#endif
}

/**
 * @brief UTLIN清空RXFIFO
 *
 *
 * @param Status
 *        true:清空RXFIFO
 *        false:无操作
 * @retval void
 */
KF_INLINE void Utlin_LL_ClearRxFifo(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_RXFIFO_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_RXFIFORST_MASK;
    regValue |= Status << HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_RXFIFORST_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_RXFIFO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_RXFIFO.bits.RXFIFORST, Status);
#endif
}

/**
 * @brief UTLIN使能RXFIFO
 *
 *
 * @param Status
 *        true:使能RXFIFO
 *        false:禁止RXFIFO
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableRxFifo(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_RXFIFO_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_RXFIFOEN_MASK;
    regValue |= Status << HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_RXFIFOEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_RXFIFO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_RXFIFO.bits.RXFIFOEN, Status);
#endif
}

/**
 * @brief UTLIN设置RXFIFO传输模式
 *
 *
 * @param Mode
 *        COMBINED_TRANSMISSION:组合传输
 *        UTLIN_SINGLE_TRANSMISSION:单次传输
 *        BULK_TRANSMISSION:批量传输
 * @retval void
 */
KF_INLINE void Utlin_LL_SetRxFifoMode(Utlin_RegisterMap_t *const Module, const Utlin_FifoMode_t Mode)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_FIFOMODE(Mode));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_RXFIFO_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_RXFIFOMOD_MASK;
    regValue |= Mode << HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_RXFIFOMOD_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_RXFIFO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_RXFIFO.bits.RXFIFOMOD, Mode);
#endif
}

/**
 * @brief UTLIN设置RXFIFO输出宽度
 *
 *
 * @param OutPutWidth
 *        RXFIFO_OUTPUT_0BYTE
 *        RXFIFO_OUTPUT_1BYTE
 *        RXFIFO_OUTPUT_2BYTE
 *        RXFIFO_OUTPUT_4BYTE
 * @retval void
 */
KF_INLINE void
Utlin_LL_SetRxFifoOutputWidth(Utlin_RegisterMap_t *const Module, const Utlin_RxFifoOutputWidthType_t OutPutWidth)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_FIFOOUTPUTWIDTH(OutPutWidth));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_RXFIFO_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_RXFIFOOUTW_MASK;
    regValue |= OutPutWidth << HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_RXFIFOOUTW_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_RXFIFO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_RXFIFO.bits.RXFIFOOUTW, OutPutWidth);
#endif
}

/**
 * @brief UTLIN使能RXFIFO中断等级
 *
 *
 * @param IntLevel 中断等级
 * @retval void
 */
KF_INLINE void Utlin_LL_SetRxFifoIntLevel(Utlin_RegisterMap_t *const Module, const uint32_t IntLevel)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((IntLevel >> POS_4_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_RXFIFO_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_IFTHRES_MASK;
    regValue |= IntLevel << HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_IFTHRES_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_RXFIFO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_RXFIFO.bits.IFTHRES, IntLevel);
#endif
}

/**
 * @brief UTLIN获取RXFIFO值
 *
 *
 * @param void
 * @retval uint32_t RXFIFO值
 */
KF_INLINE uint32_t Utlin_LL_GetRxFifoCount(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_RXFIFO_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_FIFOCNT_MASK;
    regValue = regValue >> HWIO_UTLIN0_RXFIFO_UTLIN0_RXFIFO_FIFOCNT_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_RXFIFO.bits.FIFOCNT));
#endif
}

/**
 * @brief UTLIN预分频设置值
 *
 *
 * @param Prescale 预分频值
 * @retval void
 */
KF_INLINE void Utlin_LL_SetClockPres(Utlin_RegisterMap_t *const Module, const uint32_t Prescale)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((Prescale >> POS_12_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_BITCON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_BITCON_UTLIN0_BITCON_CLKPDIV_MASK;
    regValue |= Prescale << HWIO_UTLIN0_BITCON_UTLIN0_BITCON_CLKPDIV_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_BITCON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_BITCON.bits.CLKPDIV, Prescale);
#endif
}

/**
 * @brief 读取UTLIN预分频设置值
 *
 *
 * @param Prescale 预分频值
 * @retval uint32_t
 */
KF_INLINE uint32_t Utlin_LL_GetClockPres(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    return (REG_BITS_READ(offsetAddr + HWIO_UTLIN0_BITCON_ADDR, (MASK_12_BIT << POS_0_SHIFT), POS_0_SHIFT));
    // TODO: check if correct

#else
    return (REG_BITS_READ(Module->UTLIN_BITCON.reg, (MASK_12_BIT << POS_0_SHIFT), POS_0_SHIFT));
#endif
}

/**
 * @brief UTLIN过采样值
 *
 *
 * @param OverSample 过采样值
 * @retval void
 */
KF_INLINE void
Utlin_LL_SetOverSample(Utlin_RegisterMap_t *const Module, const Utlin_OversamplingFactorType_t OverSample)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_BITCON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_BITCON_UTLIN0_BITCON_OVERSAMPLE_MASK;
    regValue |= OverSample << HWIO_UTLIN0_BITCON_UTLIN0_BITCON_OVERSAMPLE_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_BITCON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_BITCON.bits.OVERSAMPLE, OverSample);
#endif
}

/**
 * @brief 读取UTLIN过采样值
 *
 *
 * @param OverSample 过采样值
 * @retval uint32_t
 */
KF_INLINE uint32_t Utlin_LL_GetOverSample(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_BITCON_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_BITCON_UTLIN0_BITCON_OVERSAMPLE_MASK;
    regValue = regValue >> HWIO_UTLIN0_BITCON_UTLIN0_BITCON_OVERSAMPLE_SHFT;
    return (regValue);
    // TODO: check if correct

#else
    return (REG_BITS_READ(Module->UTLIN_BITCON.bits.OVERSAMPLE, (MASK_5_BIT << POS_15_SHIFT), POS_15_SHIFT));
#endif
}

/**
 * @brief UTLIN采样点设置值
 *
 *
 * @param SamplePoint 采样值
 * @retval void
 */
KF_INLINE void
Utlin_LL_SetSamplePoint(Utlin_RegisterMap_t *const Module, const Utlin_SamplePointPositionType_t SamplePoint)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_BITCON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_BITCON_UTLIN0_BITCON_SAMPLEPOINT_MASK;
    regValue |= SamplePoint << HWIO_UTLIN0_BITCON_UTLIN0_BITCON_SAMPLEPOINT_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_BITCON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_BITCON.bits.SAMPLEPOINT, SamplePoint);
#endif
}

/**
 * @brief UTLIN采样模式设置
 *
 *
 * @param SampleMode
 *        Utlin_SAMPLESPERBIT_ONE：单次采样
 *        Utlin_SAMPLESPERBIT_THREE：三次采样
 * @retval void
 */
KF_INLINE void Utlin_LL_SetSamplePointMode(Utlin_RegisterMap_t *const Module, const Utlin_SampleMode_t SampleMode)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_BITCON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_BITCON_UTLIN0_BITCON_SAMPLEMOD_MASK;
    regValue |= SampleMode << HWIO_UTLIN0_BITCON_UTLIN0_BITCON_SAMPLEMOD_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_BITCON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_BITCON.bits.SAMPLEMOD, SampleMode);
#endif
}

/**
 * @brief UTLINIDLE TIME 设置
 *
 *
 * @param IdleTime 空闲时间值
 * @retval void
 */
KF_INLINE void Utlin_LL_SetIdleTime(Utlin_RegisterMap_t *const Module, const uint32_t IdleTime)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((IdleTime >> POS_3_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_FRAMECON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_IDLE_MASK;
    regValue |= IdleTime << HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_IDLE_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_FRAMECON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_FRAMECON.bits.IDLE, IdleTime);
#endif
}

/**
 * @brief UTLIN停止位位宽设置
 *
 *
 * @param StopBit 停止位位宽
 * @retval void
 */
KF_INLINE void Utlin_LL_SetStopBitWidth(Utlin_RegisterMap_t *const Module, const Utlin_StopBitType_t StopBit)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_STOPBIT(StopBit));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_FRAMECON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_STOP_MASK;
    regValue |= StopBit << HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_STOP_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_FRAMECON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_FRAMECON.bits.STOP, StopBit);
#endif
}

/**
 * @brief UTLIN设置LEAD延迟时间
 *
 *
 * @param DelayTime 延迟时间
 * @retval void
 */
KF_INLINE void Utlin_LL_SetLeadDelayTime(Utlin_RegisterMap_t *const Module, const uint32_t DelayTime)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((DelayTime >> POS_3_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_FRAMECON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_LEAD_MASK;
    regValue |= DelayTime << HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_LEAD_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_FRAMECON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_FRAMECON.bits.LEAD, DelayTime);
#endif
}

/**
 * @brief 设置UTLINMODE
 *
 *
 * @param Mode
 *        MODE_INIT
 *        MODE_UART
 *        MODE_LIN
 * @retval void
 */
KF_INLINE void Utlin_LL_SetFrameMode(Utlin_RegisterMap_t *const Module, const Utlin_FrameModeType_t Mode)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_MODE(Mode));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_FRAMECON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_UTLINMOD_MASK;
    regValue |= Mode << HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_UTLINMOD_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_FRAMECON_ADDR, regValue);
    // TODO: check if correct
#else
    REG_WRITE(Module->UTLIN_FRAMECON.bits.UTLINMOD, Mode);
#endif
}

/**
 * @brief 设置UTLIN冲突检测使能
 *
 *
 * @param Status
 *        true:使能冲突检测
 *        false:禁止冲突检测
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableConflictDetection(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_FRAMECON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_CEN_MASK;
    regValue |= Status << HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_CEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_FRAMECON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_FRAMECON.bits.CEN, Status);
#endif
}

/**
 * @brief 设置UTLIN奇偶校验使能
 *
 *
 * @param Status
 *        true:使能奇偶校验
 *        false:禁止奇偶校验
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableParityCheck(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_FRAMECON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_PEN_MASK;
    regValue |= Status << HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_PEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_FRAMECON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_FRAMECON.bits.PEN, Status);
#endif
}

/**
 * @brief 设置UTLIN奇偶校验使能
 *
 *
 * @param Mode
 *        true:使能奇偶校验
 *        false:禁止奇偶校验
 * @retval void
 */
KF_INLINE void Utlin_LL_SetParityType(Utlin_RegisterMap_t *const Module, const Utlin_ParityMode_t Mode)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_PARITYCHECKMODE(Mode));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_FRAMECON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_PARM_MASK;
    regValue |= Mode << HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_PARM_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_FRAMECON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_FRAMECON.bits.PARM, Mode);
#endif
}

/**
 * @brief 设置UTLIN数据长度
 *
 *
 * @param Length
 *        DATA_1_BIT
 *        DATA_2_BIT
 *        DATA_3_BIT
 *        DATA_4_BIT
 *        DATA_5_BIT
 *        DATA_6_BIT
 *        DATA_7_BIT
 *        DATA_8_BIT
 *        DATA_9_BIT
 *        DATA_10_BIT
 *        DATA_11_BIT
 *        DATA_12_BIT
 *        DATA_13_BIT
 *        DATA_14_BIT
 *        DATA_15_BIT
 * @retval void
 */
KF_INLINE void Utlin_LL_SetDataLength(Utlin_RegisterMap_t *const Module, const Utlin_DataLengthType_t Length)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_DATALENGTH(Length));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_DATCON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_DATCON_UTLIN0_DATCON_DATLEN_MASK;
    regValue |= Length << HWIO_UTLIN0_DATCON_UTLIN0_DATCON_DATLEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_DATCON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_DATCON.bits.DATLEN, Length);
#endif
}

/**
 * @brief 设置UTLINLIN帧头格式
 *
 *
 * @param Format
 *        HEAD_AND_RESPONSE
 *        HEAD
 * @retval void
 */
KF_INLINE void
Utlin_LL_SetFrameHederFormat(Utlin_RegisterMap_t *const Module, const Utlin_LinSendFrameHeadFormat_t Format)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_SENDFRAMEHEAD(Format));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_DATCON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_DATCON_UTLIN0_DATCON_HEADRESP_MASK;
    regValue |= Format << HWIO_UTLIN0_DATCON_UTLIN0_DATCON_HEADRESP_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_DATCON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_DATCON.bits.HEADRESP, Format);
#endif
}

/**
 * @brief 设置UTLINLIN帧头格式
 *
 *
 * @param Mode
 *        HEAD_AND_RESPONSE
 *        HEAD
 * @retval void
 */
KF_INLINE void
Utlin_LL_SetFrameResponseTimeoutMode(Utlin_RegisterMap_t *const Module, const Utlin_LinResPonseTimeoutMode_t Mode)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_RESPONSEMODE(Mode));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_DATCON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_DATCON_UTLIN0_DATCON_TOUTMOD_MASK;
    regValue |= Mode << HWIO_UTLIN0_DATCON_UTLIN0_DATCON_TOUTMOD_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_DATCON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_DATCON.bits.TOUTMOD, Mode);
#endif
}

/**
 * @brief 设置UTLINLIN校验格式
 *
 *
 * @param Mode
 *        CLASSIC_CHECK
 *        ENHANCED_CHECK
 * @retval void
 */
KF_INLINE void Utlin_LL_SetFrameCheckMode(Utlin_RegisterMap_t *const Module, const Utlin_LinCheckMode_t Mode)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_CHECKMODE(Mode));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_DATCON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_DATCON_UTLIN0_DATCON_CSMOD_MASK;
    regValue |= Mode << HWIO_UTLIN0_DATCON_UTLIN0_DATCON_CSMOD_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_DATCON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_DATCON.bits.CSMOD, Mode);
#endif
}

/**
 * @brief 设置UTLINLIN超时响应阈值
 *
 *
 * @param TimeoutValue 超时时间
 * @retval void
 */
KF_INLINE void Utlin_LL_SetResponseTimeOutValue(Utlin_RegisterMap_t *const Module, const uint32_t TimeoutValue)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((TimeoutValue >> POS_8_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_DATCON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_DATCON_UTLIN0_DATCON_TOUTMOD_MASK;
    regValue |= TimeoutValue << HWIO_UTLIN0_DATCON_UTLIN0_DATCON_TOUTMOD_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_DATCON_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_DATCON.bits.TOUT, TimeoutValue);
#endif
}

/**
 * @brief 设置UTLIN小数波特率分频
 *
 *
 * @param Denominator 小数波特率坟分母
 * @retval void
 */
KF_INLINE void Utlin_LL_SetDecimalBaudRateDenominator(Utlin_RegisterMap_t *const Module, const uint32_t Denominator)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((Denominator >> POS_12_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_BRGR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_BRGR_UTLIN0_BRGR_DENOMINATOR_MASK;
    regValue |= Denominator << HWIO_UTLIN0_BRGR_UTLIN0_BRGR_DENOMINATOR_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_BRGR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_BRGR.bits.DENOMINATOR, Denominator);
#endif
}

/**
 * @brief 设置UTLIN小数分频器分频
 *
 *
 * @param Numerator 小数分频器分频
 * @retval void
 */
KF_INLINE void Utlin_LL_SetDecimalDividerMolecule(Utlin_RegisterMap_t *const Module, const uint32_t Numerator)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((Numerator >> POS_12_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_BRGR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_BRGR_UTLIN0_BRGR_NUMERATOR_MASK;
    regValue |= Numerator << HWIO_UTLIN0_BRGR_UTLIN0_BRGR_NUMERATOR_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_BRGR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_BRGR.bits.NUMERATOR, Numerator);
#endif
}

/**
 * @brief 设置UTLIN波特率自检测下限值
 *
 *
 * @param LowLimit 波特率自检测下限值
 * @retval void
 */
KF_INLINE void Utlin_LL_SetBaudrateAutoDetectLowLimit(Utlin_RegisterMap_t *const Module, const uint32_t LowLimit)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((LowLimit >> POS_8_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_BRGRD_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_BRGRD_UTLIN0_BRGRD_LOWERLIMIT_MASK;
    regValue |= LowLimit << HWIO_UTLIN0_BRGRD_UTLIN0_BRGRD_LOWERLIMIT_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_BRGRD_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_BRGRD.bits.LOWERLIMIT, LowLimit);
#endif
}

/**
 * @brief 设置UTLIN波特率自检测上限值
 *
 *
 * @param UpperLimit 波特率自检测上限值
 * @retval void
 */
KF_INLINE void Utlin_LL_SetBaudrateAutoDetectHighLimit(Utlin_RegisterMap_t *const Module, const uint32_t UpperLimit)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((UpperLimit >> POS_8_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_BRGRD_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_BRGRD_UTLIN0_BRGRD_UPPERLIMIT_MASK;
    regValue |= UpperLimit << HWIO_UTLIN0_BRGRD_UTLIN0_BRGRD_UPPERLIMIT_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_BRGRD_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_BRGRD.bits.UPPERLIMIT, UpperLimit);
#endif
}

/**
 * @brief 读取UTLIN自动波特率检测同步场测量值
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Utlin_LL_GetBaudrateAutoDetect(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_BRGRD_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_BRGRD_UTLIN0_BRGRD_MEASURED_MASK;
    regValue = regValue >> HWIO_UTLIN0_BRGRD_UTLIN0_BRGRD_MEASURED_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_BRGRD.bits.MEASURED));
#endif
}

/**
 * @brief 设置UTLIN接收的校验和字节是否写入RXFIFO
 *
 *
 * @param Status
 *        true:写入RXFIFO
 *        false:不写入RXFIFO
 * @retval void
 */
KF_INLINE void Utlin_LL_SetCheckDataToRxFifo(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_CLTR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_LIN_UTLIN0_LIN_CSI_MASK;
    regValue |= Status << HWIO_UTLIN0_LIN_UTLIN0_LIN_CSI_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_CLTR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_LIN.bits.CSI, Status);
#endif
}

/**
 * @brief 设置UTLIN硬件校验使能
 *
 *
 * @param Status
 *        true:使能硬件校验
 *        false:不使能硬件校验
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableHardwareChecksum(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_CLTR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_LIN_UTLIN0_LIN_CSEN_MASK;
    regValue |= Status << HWIO_UTLIN0_LIN_UTLIN0_LIN_CSEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_CLTR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_LIN.bits.CSEN, Status);
#endif
}

/**
 * @brief 设置UTLIN主机或从机模式
 *
 *
 * @param NodeMode
 *        LIN_MASTER:LIN 主机模式
 *        LIN_SLAVE:LIN 从机模式
 * @retval void
 */
KF_INLINE void Utlin_LL_SetLinMode(Utlin_RegisterMap_t *const Module, const Utlin_LinMode_t NodeMode)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_NODEMODE(NodeMode));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_LIN_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_LIN_UTLIN0_LIN_MS_MASK;
    regValue |= NodeMode << HWIO_UTLIN0_LIN_UTLIN0_LIN_MS_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_LIN_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_LIN.bits.MS, NodeMode);
#endif
}

/**
 * @brief 设置波特率自动检测
 *
 *
 * @param Status
 *        true:使能波特率自动检测
 *        false:禁止波特率自动检测
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableAutoBuadrateDetect(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_CLTR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_LIN_UTLIN0_LIN_BAUDDET_MASK;
    regValue |= Status << HWIO_UTLIN0_LIN_UTLIN0_LIN_BAUDDET_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_CLTR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_LIN.bits.BAUDDET, Status);
#endif
}

/**
 * @brief 设置UTLINLIN检测场长度
 *
 *
 * @param BreakTime 检测场长度
 * @retval void
 */
KF_INLINE void Utlin_LL_SetBreakTime(Utlin_RegisterMap_t *const Module, const uint32_t BreakTime)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((BreakTime >> POS_6_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_LINBT_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_LINBT_UTLIN0_LINBT_BREAK_MASK;
    regValue |= BreakTime << HWIO_UTLIN0_LINBT_UTLIN0_LINBT_BREAK_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_LINBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_LINBT.bits.BREAK, BreakTime);
#endif
}

/**
 * @brief 设置UTLINLin帧帧头超时计数
 *
 *
 * @param TimeOut 超时计数时间
 * @retval void
 */
KF_INLINE void Utlin_LL_SetHeadTimeOutValue(Utlin_RegisterMap_t *const Module, const uint32_t TimeOut)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((TimeOut >> POS_8_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_LINHT_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_LINHT_UTLIN0_LINHT_HEADER_MASK;
    regValue |= TimeOut << HWIO_UTLIN0_LINHT_UTLIN0_LINHT_HEADER_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_LINHT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_LINHT.bits.HEADER, TimeOut);
#endif
}

/**
 * @brief 读取UTLIN标志位
 *
 *
 * @param Flag 标志位
 * @retval void
 */
KF_INLINE bool Utlin_LL_GetFlag(Utlin_RegisterMap_t *const Module, const Utlin_FlagType_t Flag)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_FLAG(Flag));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    return (REG_BITS_READ(offsetAddr + HWIO_UTLIN0_IF_ADDR, (MASK_1_BIT << Flag), Flag));
    // TODO: check if correct

#else
    return (REG_BITS_READ(Module->UTLIN_IF.reg, (MASK_1_BIT << Flag), Flag));
#endif
}

/**
 * @brief 使能UTLIN标志位
 *
 *
 * @param Flag 标志位
 * @retval void
 */
KF_INLINE void Utlin_LL_SetFlag(Utlin_RegisterMap_t *const Module, const Utlin_FlagType_t Flag)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_FLAG(Flag));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IFS_ADDR, (MASK_1_BIT << Flag));

    // TODO: check if correct
#else
    REG_BIT_SET(Module->UTLIN_IFS.reg, MASK_1_BIT << Flag);
#endif
}

/**
 * @brief 设置UTLIN中断寄存器
 *
 *
 * @param Int 中断类型
 * @retval void
 */
KF_INLINE void Utlin_LL_WriteSetFlagWord(Utlin_RegisterMap_t *const Module, const uint32_t Set)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IFS_ADDR, Set);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IFS.reg, Set);
#endif
}

/**
 * @brief 获取UTLIN中断寄存器
 *
 *
 * @param
 * @retval uint32_t
 */
KF_INLINE uint32_t Utlin_LL_ReadSetFlagWord(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_UTLIN0_IFS_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_IFS.reg));
#endif
}

/**
 * @brief 使能UTLIN中断
 *
 *
 * @param Int 中断类型
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableInt(Utlin_RegisterMap_t *const Module, const Utlin_IntType_t Int, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_INT(Int));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_IE_ADDR + offsetAddr);
    regValue &= ~MASK_1_BIT << Int;
    regValue |= Status << Int;

    REG_WRITE(offsetAddr + HWIO_UTLIN0_IE_ADDR, regValue);
    // TODO: check if correct

#else
    REG_BITS_WRITE(Module->UTLIN_IE.reg, MASK_1_BIT << Int, Status << Int);
#endif
}

/**
 * @brief 设置UTLIN中断寄存器
 *
 *
 * @param Int 中断类型
 * @retval void
 */
KF_INLINE void Utlin_LL_WriteIntWord(Utlin_RegisterMap_t *const Module, const uint32_t Int)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IE_ADDR, Int);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IE.reg, Int);
#endif
}

/**
 * @brief 获取UTLIN中断寄存器
 *
 *
 * @param
 * @retval uint32_t
 */
KF_INLINE uint32_t Utlin_LL_ReadIntWord(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_UTLIN0_IE_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_IE.reg));
#endif
}

/**
 * @brief 使能UTLIN中断
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Utlin_LL_DisableAllInt(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_INT(Int));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IE_ADDR, 0x00000000);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IE.reg, 0x00000000);
#endif
}

/**
 * @brief 清除UTLIN标志位
 *
 *
 * @retval void
 */
KF_INLINE void Utlin_LL_ClearFlag(Utlin_RegisterMap_t *const Module, const Utlin_FlagType_t Flag)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_FLAG(Flag));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IC_ADDR, (MASK_1_BIT << Flag));
    // TODO:
#else
    REG_BIT_SET(Module->UTLIN_IC.reg, MASK_1_BIT << Flag);
#endif
}

/**
 * @brief 清除UTLIN所有标志位
 *
 *
 * @param Flag 标志位
 * @retval void
 */
KF_INLINE void Utlin_LL_ClearAllFlag(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    // TODO:是否需要软件清零
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_FLAG(Flag));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_IC_ADDR, 0xffffffff);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IC.reg, 0xffffffff);
#endif
}

/**
 * @brief 写TXBUFFER
 *
 *
 * @param Data
 * @retval void
 */
KF_INLINE void Utlin_LL_WriteTxBuffer(Utlin_RegisterMap_t *const Module, const uint32_t Data)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_TBUFR_ADDR, Data);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_TBUFR.reg, Data);
#endif
}

/**
 * @brief 读RXBUFFER
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Utlin_LL_ReadRxBuffer(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_UTLIN0_RBUFR_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_RBUFR.reg));
#endif
}

/**
 * @brief 获取时钟状态
 *
 *
 * @param void
 * @retval bool
 *         true:关闭
 *         false:使能
 */
KF_INLINE bool Utlin_LL_GetClockStatus(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_CSEL_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_CSEL_UTLIN0_CSEL_CLKEN_MASK;
    regValue = regValue >> HWIO_UTLIN0_CSEL_UTLIN0_CSEL_CLKEN_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_CSEL.bits.CLKEN));
#endif
}

/**
 * @brief 设置波特率输入时钟源
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE void Utlin_LL_SetClockSource(Utlin_RegisterMap_t *const Module, Utlin_ClockSourceType_t InputClock)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_INPUTCLOCK(InputClock));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_CSEL_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_CSEL_UTLIN0_CSEL_CLKSEL_MASK;
    regValue |= InputClock << HWIO_UTLIN0_CSEL_UTLIN0_CSEL_CLKSEL_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_CSEL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_CSEL.bits.CLKSEL, InputClock);
#endif
    /* wait until clock changed */
    if (UTLIN_NO_CLOCK == InputClock)
    {
        while (false != Utlin_LL_GetClockStatus(Module))
            ;
    }
    else
    {
        while (true != Utlin_LL_GetClockStatus(Module))
            ;
    }
}

/**
 * @brief 获取波特率输入时钟源
 *
 *
 * @param void
 * @retval Utlin_ClockSourceType_t
 */
KF_INLINE Utlin_ClockSourceType_t Utlin_LL_GetBaudRateClock(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_CSEL_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_CSEL_UTLIN0_CSEL_CLKSEL_MASK;
    regValue = regValue >> HWIO_UTLIN0_CSEL_UTLIN0_CSEL_CLKSEL_SHFT;
    return ((Utlin_ClockSourceType_t)(regValue));
    // TODO: check if correct

#else
    return ((Utlin_ClockSourceType_t)REG_READ(Module->UTLIN_CSEL.bits.CLKSEL));
#endif
}

/**
 * @brief 获取波特率输入FastClock
 *
 *
 * @param Module
 * @retval float
 */
KF_INLINE float Utlin_LL_GetFFrequency(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    float frequency;
    // TODO:需要从CLOCK MODULE获取时钟
    frequency = 0;
    return frequency;
}

/**
 * @brief 获取波特率输入SlowClock
 *
 *
 * @param Module
 * @retval float
 */
KF_INLINE float Utlin_LL_GetSFrequency(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    float frequency;
    // TODO:需要从CLOCK MODULE获取时钟
    frequency = 0;
    return frequency;
}

/**
 * @brief 获取时钟状态
 *
 *
 * @param void
 * @retval bool
 *         true:关闭
 *         false:使能
 */
KF_INLINE bool Utlin_LL_GetPdFrequency(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_CSEL_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_CSEL_UTLIN0_CSEL_CLKEN_MASK;
    regValue = regValue >> HWIO_UTLIN0_CSEL_UTLIN0_CSEL_CLKEN_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_CSEL.bits.CLKEN));
#endif
}

/**
 * @brief 读RXBUFFER调试数据，不影响RXFIFO读指针
 *
 *
 * @param void
 * @retval uint32_t
 */
KF_INLINE uint32_t Utlin_LL_ReadRxBufferDebug(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_UTLIN0_RBUFD_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_RBUFD.reg));
#endif
}

/**
 * @brief 清零 UTLIN内核
 *
 *
 * @param void
 * @retval void
 */
KF_INLINE void Utlin_LL_ClearCoreStatus(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_KRSTCLR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_KRSTCLR_UTLIN0_KRSTCLR_CLR_MASK;
    regValue |= true << HWIO_UTLIN0_KRSTCLR_UTLIN0_KRSTCLR_CLR_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_KRSTCLR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_KRSTCLR.bits.CLR, true);
#endif
}

/**
 * @brief 复位 UTLIN内核1
 *
 *
 * @param Status
 *        true:请求内核复位
 *        false:未请求内核复位
 * @retval void
 */
KF_INLINE void Utlin_LL_Reset1(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_KRST1_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_KRST1_UTLIN0_KRST1_RST_MASK;
    regValue |= Status << HWIO_UTLIN0_KRST1_UTLIN0_KRST1_RST_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_KRST1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_KRST1.bits.RST, Status);
#endif
}

/**
 * @brief 复位 UTLIN内核0
 *
 *
 * @param Status
 *        true:请求内核复位
 *        false:未请求内核复位
 * @retval void
 */
KF_INLINE void Utlin_LL_Reset0(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_KRST0_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_KRST0_UTLIN0_KRST0_RST_MASK;
    regValue |= Status << HWIO_UTLIN0_KRST0_UTLIN0_KRST0_RST_SHFT;
    REG_WRITE(offsetAddr + HWIO_UTLIN0_KRST0_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_KRST0.bits.RST, Status);
#endif
}

/**
 * @brief  获取UTLIN内核0复位状态
 *
 *
 * @param  void
 * @retval Status
 *         true:执行内核复位
 *         false:未执行内核复位
 */
KF_INLINE bool Utlin_LL_GetResetStatus(Utlin_RegisterMap_t *const Module)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_UTLIN0_KRST0_ADDR + offsetAddr);
    regValue &= HWIO_UTLIN0_KRST0_UTLIN0_KRST0_RSTSTA_MASK;
    regValue = regValue >> HWIO_UTLIN0_KRST0_UTLIN0_KRST0_RSTSTA_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->UTLIN_KRST0.bits.RSTSTA));
#endif
}

/**
 * @brief  获取UTLIN内核0复位状态
 *
 *
 * @param  AccessEnable
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableAccess(Utlin_RegisterMap_t *const Module, Utlin_AccessEnableType_t AccessEnable)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
// TODO:
#else
    REG_BIT_SET(Module->UTLIN_ACCEN0.reg, MASK_1_BIT << AccessEnable);
#endif
}

/**
 * @brief 获取SENT访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE bool Utlin_LL_GetAccess(Utlin_RegisterMap_t *const Module, Utlin_AccessEnableType_t AccessEnable)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ACCESSENABLE(AccessEnable));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    return (REG_BITS_READ(offsetAddr + HWIO_UTLIN0_ACCEN0_ADDR, MASK_1_BIT << AccessEnable, AccessEnable));
    // TODO: check if correct

#else
    return (REG_BITS_READ(Module->UTLIN_ACCEN0.reg, MASK_1_BIT << AccessEnable, AccessEnable));
#endif
}

/**
 * @brief 获取SENT访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE uint32_t Utlin_LL_Read8(Utlin_RegisterMap_t *const Module, uint8_t *DataPtr, uint32_t Count)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    while (Count > 0)
    {
#ifdef SIMULATION
        uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
        *DataPtr++          = (uint8_t)REG_READ(offsetAddr + HWIO_UTLIN0_RBUFR_ADDR);
        // TODO: check if correct

#else
        *DataPtr++ = (uint8_t)REG_READ(Module->UTLIN_RBUFR.reg);
#endif
        Count--;
    }
    return Count;
}

/**
 * @brief 获取SENT访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE uint32_t Utlin_LL_Read16(Utlin_RegisterMap_t *const Module, uint16_t *DataPtr, uint32_t Count)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    while (Count > 0)
    {
#ifdef SIMULATION
        uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
        *DataPtr++          = (uint16_t)REG_READ(offsetAddr + HWIO_UTLIN0_RBUFR_ADDR);
        // TODO: check if correct

#else
        *DataPtr++ = (uint16_t)REG_READ(Module->UTLIN_RBUFR.reg);
#endif
        Count--;
    }
    return Count;
}

/**
 * @brief 获取SENT访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE uint32_t Utlin_LL_Read32(Utlin_RegisterMap_t *const Module, uint32_t *DataPtr, uint32_t Count)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    while (Count > 0)
    {
#ifdef SIMULATION
        uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
        *DataPtr++          = REG_READ(offsetAddr + HWIO_UTLIN0_RBUFR_ADDR);
        // TODO: check if correct

#else
        *DataPtr++ = REG_READ(Module->UTLIN_RBUFR.reg);
#endif
        Count--;
    }
    return Count;
}

/**
 * @brief 获取SENT访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE uint32_t Utlin_LL_Write8(Utlin_RegisterMap_t *const Module, uint8_t *DataPtr, uint32_t Count)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    while ((Count > 0))
    {
#ifdef SIMULATION
        uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
        REG_WRITE(offsetAddr + HWIO_UTLIN0_TBUFR_ADDR, *DataPtr++);
        // TODO: check if correct

#else
        REG_WRITE(Module->UTLIN_TBUFR.reg, *DataPtr++);
#endif
        Count--;
    }
    return Count;
}

/**
 * @brief 获取SENT访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE uint32_t Utlin_LL_Write16(Utlin_RegisterMap_t *const Module, uint16_t *DataPtr, uint32_t Count)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    while ((Count > 0))
    {
#ifdef SIMULATION
        uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
        REG_WRITE(offsetAddr + HWIO_UTLIN0_TBUFR_ADDR, *DataPtr++);
        // TODO: check if correct

#else
        REG_WRITE(Module->UTLIN_TBUFR.reg, *DataPtr++);
#endif
        Count--;
    }
    return Count;
}

/**
 * @brief 获取SENT访问状态
 *
 *
 * @ param AccessEnable :具体访问使能通道
 * @ retval bool
 */
KF_INLINE uint32_t Utlin_LL_Write32(Utlin_RegisterMap_t *const Module, uint32_t *DataPtr, uint32_t Count)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    while ((Count > 0))
    {
#ifdef SIMULATION
        uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
        REG_WRITE(offsetAddr + HWIO_UTLIN0_TBUFR_ADDR, *DataPtr++);
        // TODO: check if correct

#else
        REG_WRITE(Module->UTLIN_TBUFR.reg, *DataPtr++);
#endif
        Count--;
    }
    return Count;
}

/**
 * @brief 设置UTLIN奇偶校验使能
 *
 *
 * @param Mode
 *        true:使能奇偶校验
 *        false:禁止奇偶校验
 * @retval void
 */
KF_INLINE void Utlin_LL_SetParityCheckMode(Utlin_RegisterMap_t *const Module, const Utlin_ParityMode_t Mode)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_PARITYCHECKMODE(Mode));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_UTLIN0_FRAMECON_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_PARM_MASK;
    regValue |=  Mode<<HWIO_UTLIN0_FRAMECON_UTLIN0_FRAMECON_PARM_SHFT;
    REG_WRITE( offsetAddr + HWIO_UTLIN0_FRAMECON_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_FRAMECON.bits.PARM, Mode);
#endif
}
/**
 * @brief UTLIN设置CTS输入引脚
 *
 *
 * @param CTSChannel
 *        CTSA
 *        CTSB
 *        CTSC
 *        CTSD
 * @retval void
 */
KF_INLINE void Utlin_LL_SetCtsChannel(Utlin_RegisterMap_t *const Module, const Utlin_InputCTSChannel_t CTSChannel)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_INPUTCTSCHANNEL(CTSChannel));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_IOCR_UTLIN0_IOCR_CTS_MASK;
    regValue |=  CTSChannel<<HWIO_UTLIN0_IOCR_UTLIN0_IOCR_CTS_SHFT;
    REG_WRITE( offsetAddr + HWIO_UTLIN0_IOCR_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IOCR.bits.CTS, CTSChannel);
#endif
}

/**
 * @brief UTLIN设置极性位
 *
 *
 * @param CTSChannel
 *        VALID_HIGH
 *        VALID_LOW
 * @retval void
 */
KF_INLINE void Utlin_LL_SetCtsPolarity(Utlin_RegisterMap_t *const Module, const Utlin_Polarity_t Polarity)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_POLARITY(Polarity));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_IOCR_UTLIN0_IOCR_RCPOL_MASK;
    regValue |=  Polarity<<HWIO_UTLIN0_IOCR_UTLIN0_IOCR_RCPOL_SHFT;
    REG_WRITE( offsetAddr + HWIO_UTLIN0_IOCR_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IOCR.bits.RCPOL, Polarity);
#endif
}

/**
 * @brief UTLIN使能输入CTS设置
 *
 *
 * @param Status
 *         false  禁止输入CTS
 *         true   使能输入CTS
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableCts(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_IOCR_UTLIN0_IOCR_CTEN_MASK;
    regValue |=  Status<<HWIO_UTLIN0_IOCR_UTLIN0_IOCR_CTEN_SHFT;
    REG_WRITE( offsetAddr + HWIO_UTLIN0_IOCR_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IOCR.bits.CTEN, Status);
#endif
}

/**
 * @brief UTLIN模块使能/禁止
 *
 *
 * @param Status:
 *        false   UTLIN使能
 *        true   UTLIN禁止
 * @retval void
 */
KF_INLINE void Utlin_LL_EnableModuleStatus(Utlin_RegisterMap_t *const Module, const bool Status)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_BOOL(Status));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_UTLIN0_CLTR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_CLTR_UTLIN0_CLTR_DISR_MASK;
    regValue |=  ((Status == true)?false : true)<<HWIO_UTLIN0_CLTR_UTLIN0_CLTR_DISR_SHFT;
    REG_WRITE( offsetAddr + HWIO_UTLIN0_CLTR_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_CLTR.bits.DISR, (Status == true) ? false : true);
#endif
}

/**
 * @brief UTLIN设置数字滤波深度
 *
 *
 * @param Depth
 * @retval void
 */
KF_INLINE void Utlin_LL_SetFilterDepth(Utlin_RegisterMap_t *const Module, const uint32_t Depth)
{
    KF_DRV_Utlin_ASSERT(CHECK_UTLIN_ALL_PERIPH(Module));
    KF_DRV_Utlin_ASSERT((Depth >> POS_6_SHIFT) == 0U);
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~UTLIN_MODULE_BASE_ADDR;
    uint32_t regValue=REG_READ(HWIO_UTLIN0_IOCR_ADDR + offsetAddr);
    regValue &= ~HWIO_UTLIN0_IOCR_UTLIN0_IOCR_DEPTH_MASK;
    regValue |=  Depth<<HWIO_UTLIN0_IOCR_UTLIN0_IOCR_DEPTH_SHFT;
    REG_WRITE( offsetAddr + HWIO_UTLIN0_IOCR_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(Module->UTLIN_IOCR.bits.DEPTH, Depth);
#endif
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
