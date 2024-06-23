/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_canfd.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-5-14
 *  @Version         : V0.0.1.231212_alpha
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
 *  |2023-5-14    |V1.0     |Zhang Quanzhen | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_DRV_CANFD_H_
#define _KF32DA13K_DRV_CANFD_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *         Include Files
 **************************************************************************/
#include "kf32a13k_reg_canfd.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_CANFD_ASSERT
#include "dev_assert.h"
#define KF_CANFD_ASSERT(x) KF_DRV_ASSERT(x)
#else
#define KF_CANFD_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION
#include "kf32a13k_reg_simulation_canfd.h"
#define CANFD_MODULE_BASE_ADDR 0xF0040000
#endif

/**************************************************************************
 *         Mcro Functions
 **************************************************************************/

/**************************************************************************
 *         Mcro ro typedef
 **************************************************************************/
#define CAN_CS_DLC_SHIFT                              (16U)
#define CAN_CS_CODE_SHIFT                             (24U)
#define CAN_CS_CODE_DEFAULT                           (0U)
#define CAN_RXIMR_MI_MASK                             (0xFFFFFFFFU)
#define CAN_CS_CODE_MASK                              (0x0F000000U)
#define CAN_CS_RTR_MASK                               (0x00100000U)
#define CAN_CS_IDE_MASK                               (0x00200000U)
#define CAN_CS_DLC_MASK                               (0x000F0000U)
#define CAN_CS_SRR_MASK                               (0x00400000U)
#define CAN_MB_BRS_MASK                               (0x40000000U)
#define CAN_MB_EDL_MASK                               (0x80000000U)
#define CAN_IMASK1_BUF31TO0M_MASK                     (0xFFFFFFFFU)
#define CAN_IMASK2_BUF63TO32M_MASK                    (0xFFFFFFFFU)
#define CAN_IMASK3_BUF95TO64M_MASK                    (0xFFFFFFFFU)
#define CAN_IMASK4_BUF127TO96M_MASK                   (0xFFFFFFFFU)
#define CAN_CTRL1_RWRNMSK_MASK                        (0x00000400U)
#define CAN_CTRL1_TWRNMSK_MASK                        (0x00000800U)
#define CAN_CTRL1_ERRMSK_MASK                         (0x00004000U)
#define CAN_CTRL1_BOFFMSK_MASK                        (0x00008000U)
#define CANFD_FORMATA_EXT_MASK                        (0x3FFFFFFFU)
#define CANFD_FORMATA_STD_MASK                        (0x3FF80000U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK      (0x1FFF8000U)
#define CANFD_FORMATB_STD_MASK                        (0x7FFU)
#define CANFD_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK      (0x1FE00000U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATC_STD_MASK      (0x7F8U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK1     (0x3FFFU)
#define CANFD_FORMATC_MASK                            (0xFFU)
#define CAN_FLT_ID2_IDMASK_IDE_MSK_MASK               (0x40000000U)
#define CAN_FLT_ID2_IDMASK_RTR_MSK_MASK               (0x20000000U)
#define CANFD_FORMATA_EXT_SHIFT                       (1U)
#define CAN_ID_STD_SHIFT                              (18U)
#define CANFD_FORMATA_STD_SHIFT                       (19U)
#define CANFD_FORMATAB_IDE_SHIFT                      (30U)
#define CANFD_FORMATAB_RTR_SHIFT                      (31U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATB_RTR_SHIFT     (15U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATB_IDE_SHIFT     (14U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT (15U)
#define CANFD_FORMATB_EXT_SHIFT1                      (16U)
#define CANFD_FORMATB_STD_SHIFT1                      (19U)
#define CANFD_FORMATB_EXT_SHIFT1                      (16U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_SHIFT2    (0U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATB_STD_SHIFT2    (3U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT (15U)
#define CANFD_FORMATC_SHIFT1                          (24U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATC_SHIFT2        (16U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATC_SHIFT3        (8U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATC_SHIFT4        (0U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT (21U)
#define CANFD_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT (3U)
#define CANFD_ALL_INT                                 (0x003B0007U)
#define RXFIFO_FILTER_TABLE_OFFSET                    (0x00000018U)
#define CAFND_RX_FIFO_ACCEPT_REMOTE_FRAME             (0x00000001U)
#define CAFND_RX_FIFO_ACCEPT_EXT_FRAME                (0x00000001U)

/**
 * @maximum threshold values for DLC
 */
#define CANFD_MAX_DLC8_U8  ((uint8_t)8U)
#define CANFD_MAX_DLC9_U8  ((uint8_t)12U)
#define CANFD_MAX_DLC10_U8 ((uint8_t)16U)
#define CANFD_MAX_DLC11_U8 ((uint8_t)20U)
#define CANFD_MAX_DLC12_U8 ((uint8_t)24U)
#define CANFD_MAX_DLC13_U8 ((uint8_t)32U)
#define CANFD_MAX_DLC14_U8 ((uint8_t)48U)
#define CANFD_MAX_DLC15_U8 ((uint8_t)64U)

/**
 * @minimum threshold values for DLC
 */
#define CANFD_MIN_DLC8_U8  ((uint8_t)0U)
#define CANFD_MIN_DLC9_U8  ((uint8_t)9U)
#define CANFD_MIN_DLC10_U8 ((uint8_t)13U)
#define CANFD_MIN_DLC11_U8 ((uint8_t)17U)
#define CANFD_MIN_DLC12_U8 ((uint8_t)21U)
#define CANFD_MIN_DLC13_U8 ((uint8_t)25U)
#define CANFD_MIN_DLC14_U8 ((uint8_t)33U)
#define CANFD_MIN_DLC15_U8 ((uint8_t)49U)

/*maximum threshold values for Payload*/
#define CANFD_MAX_PAYLOAD8_U8  ((uint8_t)8U)
#define CANFD_MAX_PAYLOAD16_U8 ((uint8_t)16U)
#define CANFD_MAX_PAYLOAD32_U8 ((uint8_t)32U)
#define CANFD_MAX_PAYLOAD64_U8 ((uint8_t)64U)

typedef uint8_t Semaphore_t;

typedef enum
{
    CANFD_IFLAG1_BUF4ITO1I_0B = 0,
    CANFD_IFLAG1_BUF4ITO1I_1B = 1
} Canfd_Iflag1_Buf4ito1i_Id_t;
#define CHECK_CANFD_IFLAG1_BUF4ITO1I_ID(x) ((uint32_t)(x) <= (uint32_t)CANFD_IFLAG1_BUF4ITO1I_1B)

typedef enum
{
    CANFD_DBG_DBGCTL_0B  = 0,
    CANFD_DBG_DBGCTL_1B  = 1,
    CANFD_DBG_DBGCTL_10B = 2
} Canfd_Dbg_Dbgctl_Id_t;
#define CHECK_CANFD_DBG_DBGCTL_ID(x) ((uint32_t)(x) <= (uint32_t)CANFD_DBG_DBGCTL_10B)

typedef enum
{
    CANFD_ACES0_EN_ID_0,
    CANFD_ACES0_EN_ID_1,
    CANFD_ACES0_EN_ID_2,
    CANFD_ACES0_EN_ID_3,
    CANFD_ACES0_EN_ID_4,
    CANFD_ACES0_EN_ID_5,
    CANFD_ACES0_EN_ID_6,
    CANFD_ACES0_EN_ID_7,
    CANFD_ACES0_EN_ID_8,
    CANFD_ACES0_EN_ID_9,
    CANFD_ACES0_EN_ID_10,
    CANFD_ACES0_EN_ID_11,
    CANFD_ACES0_EN_ID_12,
    CANFD_ACES0_EN_ID_13,
    CANFD_ACES0_EN_ID_14,
    CANFD_ACES0_EN_ID_15,
    CANFD_ACES0_EN_ID_16,
    CANFD_ACES0_EN_ID_17,
    CANFD_ACES0_EN_ID_18,
    CANFD_ACES0_EN_ID_19,
    CANFD_ACES0_EN_ID_20,
    CANFD_ACES0_EN_ID_21,
    CANFD_ACES0_EN_ID_22,
    CANFD_ACES0_EN_ID_23,
    CANFD_ACES0_EN_ID_24,
    CANFD_ACES0_EN_ID_25,
    CANFD_ACES0_EN_ID_26,
    CANFD_ACES0_EN_ID_27,
    CANFD_ACES0_EN_ID_28,
    CANFD_ACES0_EN_ID_29,
    CANFD_ACES0_EN_ID_30,
    CANFD_ACES0_EN_ID_31
} Canfd_Aces0_En_Id_t;
#define CHECK_CANFD_ACES0_EN_ID(x) ((uint32_t)(x) <= (uint32_t)CANFD_ACES0_EN_ID_31)

#if FEATURE_CAN_HAS_PE_CLKSRC_SELECT
/*! @brief Canfd PE clock sources
 * Implements : Canfd_ClkSource_t_Class
 */
typedef enum
{
    CANFD_CLK_SOURCE_OSC    = 0U, /*!< The CAN engine clock source is the oscillator clock. */
    CANFD_CLK_SOURCE_PERIPH = 1U  /*!< The CAN engine clock source is the peripheral clock. */
} Canfd_ClkSource_t;
#endif

/*! @brief The state of a given MB (idle/Rx busy/Tx busy).
 * Implements : Canfd_MbState_t_Class
 */
typedef enum
{
    CANFD_MB_IDLE,    /*!< The MB is not used by any transfer. */
    CANFD_MB_RX_BUSY, /*!< The MB is used for a reception. */
    CANFD_MB_TX_BUSY, /*!< The MB is used for a transmission. */
#if FEATURE_CAN_HAS_DMA_ENABLE
    CANFD_MB_DMA_ERROR /*!< The MB is used as DMA source and fail to transfer */
#endif
} Canfd_MbState_t;

/*! @brief Canfd Message Buffer ID type
 * Implements : Canfd_msgbuff_id_type_t_Class
 */
typedef enum
{
    CANFD_MSG_ID_STD, /*!< Standard ID*/
    CANFD_MSG_ID_EXT  /*!< Extended ID*/
} Canfd_IdType_t;

/*! @brief Canfd message buffer CODE for Rx buffers*/
typedef enum
{
    CANFD_RX_INACTIVE = 0x00, /*!< MB is not active.*/
    CANFD_RX_FULL     = 0x02, /*!< MB is full.*/
    CANFD_RX_EMPTY    = 0x04, /*!< MB is active and empty.*/
    CANFD_RX_OVERRUN  = 0x06, /*!< MB is overwritten into a full buffer.*/
    CANFD_RX_BUSY     = 0x08, /*!< CANFD is updating the contents of the MB.*/
                              /*!  The CPU must not access the MB.*/
    CANFD_RX_RANSWER = 0x0A,  /*!< A frame was configured to recognize a Remote Request Frame*/
                              /*!  and transmit a Response Frame in return.*/
                              /*!  an incoming Remote Request Frame.*/
    CANFD_RX_NOTUSED = 0x0F   /*!< Not used*/
} Canfd_RxCodetype_t;

/*! @brief Canfd message buffer CODE for Tx buffers*/
typedef enum
{
    CANFD_TX_INACTIVE = 0x08, /*!< MB is not active.*/
    CANFD_TX_ABORT    = 0x09, /*!< MB is aborted.*/
    CANFD_TX_DATA     = 0x0C, /*!< MB is a TX Data Frame(MB RTR must be 0).*/
    CANFD_TX_REMOTE   = 0x1C, /*!< MB is a TX Remote Request Frame (MB RTR must be 1).*/
    CANFD_TX_TANSWER  = 0x0E, /*!< MB is a TX Response Request Frame from.*/
    CANFD_TX_NOTUSED  = 0x0F  /*!< Not used*/
} Canfd_TxCodetype_t;

/*! @brief CANFD error interrupt types
 */
typedef enum
{
    CANFD_INT_RX_WARNING = CAN_CTRL1_RWRNMSK_MASK, /*!< RX warning interrupt*/
    CANFD_INT_TX_WARNING = CAN_CTRL1_TWRNMSK_MASK, /*!< TX warning interrupt*/
    CANFD_INT_ERR        = CAN_CTRL1_ERRMSK_MASK,  /*!< Error interrupt*/
    CANFD_INT_BUSOFF     = CAN_CTRL1_BOFFMSK_MASK, /*!< Bus off interrupt*/
} Canfd_Inttype_t;

/*! @brief Canfd Rx FIFO filters number
 * Implements : Canfd_RxFifofilter_IdNum_t_Class
 */
typedef enum
{
    CANFD_RX_FIFO_ID_FILTERS_8   = 0x0, /*!<   8 Rx FIFO Filters. @internal gui name="8 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_16  = 0x1, /*!<  16 Rx FIFO Filters. @internal gui name="16 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_24  = 0x2, /*!<  24 Rx FIFO Filters. @internal gui name="24 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_32  = 0x3, /*!<  32 Rx FIFO Filters. @internal gui name="32 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_40  = 0x4, /*!<  40 Rx FIFO Filters. @internal gui name="40 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_48  = 0x5, /*!<  48 Rx FIFO Filters. @internal gui name="48 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_56  = 0x6, /*!<  56 Rx FIFO Filters. @internal gui name="56 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_64  = 0x7, /*!<  64 Rx FIFO Filters. @internal gui name="64 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_72  = 0x8, /*!<  72 Rx FIFO Filters. @internal gui name="72 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_80  = 0x9, /*!<  80 Rx FIFO Filters. @internal gui name="80 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_88  = 0xA, /*!<  88 Rx FIFO Filters. @internal gui name="88 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_96  = 0xB, /*!<  96 Rx FIFO Filters. @internal gui name="96 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_104 = 0xC, /*!< 104 Rx FIFO Filters. @internal gui name="104 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_112 = 0xD, /*!< 112 Rx FIFO Filters. @internal gui name="112 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_120 = 0xE, /*!< 120 Rx FIFO Filters. @internal gui name="120 Rx FIFO Filters" */
    CANFD_RX_FIFO_ID_FILTERS_128 = 0xF  /*!< 128 Rx FIFO Filters. @internal gui name="128 Rx FIFO Filters" */
} Canfd_RxFifofilterIdNum_t;

/*! @brief Canfd Rx mask type.
 * Implements : Canfd_rx_mask_type_t_Class
 */
typedef enum
{
    CANFD_RX_MASK_GLOBAL,    /*!< Rx global mask*/
    CANFD_RX_MASK_INDIVIDUAL /*!< Rx individual mask*/
} Canfd_RxMaskType_t;

/*! @brief ID formats for Rx FIFO
 * Implements : Canfd_RxFifoIdFormat_t_Class
 */
typedef enum
{
    CANFD_RX_FIFO_ID_FORMAT_A, /*!< One full ID (standard and extended) per ID Filter Table element.*/
    CANFD_RX_FIFO_ID_FORMAT_B, /*!< Two full standard IDs or two partial 14-bit (standard and
                                      extended) IDs per ID Filter Table element.*/
    CANFD_RX_FIFO_ID_FORMAT_C, /*!< Four partial 8-bit Standard IDs per ID Filter Table element.*/
    CANFD_RX_FIFO_ID_FORMAT_D  /*!< All frames rejected.*/
} Canfd_RxFifoIdFormat_t;

/*! @brief Canfd operation modes
 * Implements : Canfd_OpMode_t_Class
 */
typedef enum
{
    CANFD_NORMAL_MODE,      /*!< Normal mode or user mode @internal gui name="Normal" */
    CANFD_LISTEN_ONLY_MODE, /*!< Listen-only mode @internal gui name="Listen-only" */
    CANFD_LOOPBACK_MODE,    /*!< Loop-back mode @internal gui name="Loop back" */
    CANFD_FREEZE_MODE,      /*!< Freeze mode @internal gui name="Freeze" */
    CANFD_DISABLE_MODE      /*!< Module disable mode @internal gui name="Disabled" */
} Canfd_OpMode_t;

/*! @brief Canfd payload sizes
 * Implements : Canfd_PayloadSize_t_Class
 */
typedef enum
{
    CANFD_PAYLOAD_SIZE_8 = 0, /*!< Canfd message buffer payload size in bytes*/
    CANFD_PAYLOAD_SIZE_16,    /*!< Canfd message buffer payload size in bytes*/
    CANFD_PAYLOAD_SIZE_32,    /*!< Canfd message buffer payload size in bytes*/
    CANFD_PAYLOAD_SIZE_64     /*!< Canfd message buffer payload size in bytes*/
} Canfd_PayloadSize_t;

/*! @brief Pretended Networking filtering combinations */
typedef enum
{
    CANFD_FILTER_ID,               /*!< Message ID filtering only */
    CANFD_FILTER_ID_PAYLOAD,       /*!< Message ID and payload filtering */
    CANFD_FILTER_ID_NTIMES,        /*!< Message ID filtering occurring a specified number of times */
    CANFD_FILTER_ID_PAYLOAD_NTIMES /*!< Message ID and payload filtering  occurring a specified number of times */
} Canfd_PnCombinationFilter_t;

/*! @brief Pretended Networking ID filter */
typedef struct
{
    bool     extendedId;  /*!< Specifies if the ID is standard or extended. */
    bool     remoteFrame; /*!< Specifies if the frame is standard or remote. */
    uint32_t id;          /*!< Specifies the ID value. */
} Canfd_PnIdFilter_t;

/*! @brief Pretended Networking matching schemes */
typedef enum
{
    CANFD_FILTER_MATCH_EXACT, /*!< Match an exact target value. */
    CANFD_FILTER_MATCH_GEQ,   /*!< Match greater than or equal to a specified target value. */
    CANFD_FILTER_MATCH_LEQ,   /*!< Match less than or equal to a specified target value. */
    CANFD_FILTER_MATCH_RANGE  /*!< Match inside a range, greater than or equal to a specified lower limit and smaller
                                   than or  equal to a specified upper limit. */
} Canfd_PnFilterSeletion_t;

/*! @brief Pretended Networking payload filter */
typedef struct
{
    uint8_t dlcLow;       /*!< Specifies the lower limit of the payload size. */
    uint8_t dlcHigh;      /*!< Specifies the upper limit of the payload size. */
    uint8_t payload1[8U]; /*!< Specifies the payload to be matched (for MATCH_EXACT), the lower limit
                              (for MATCH_GEQ and MATCH_RANGE) or the upper limit (for MATCH_LEQ). */
    uint8_t payload2[8U]; /*!< Specifies the mask (for MATCH_EXACT) or the upper limit (for MATCH_RANGE). */
} Canfd_PnPayloadFilter_t;

typedef enum
{
    CANFD_EVENT_WAKEUP_TIMEOUT, /*!< An wake up event occurred due to timeout. */
    CANFD_EVENT_WAKEUP_MATCH,   /*!< An wake up event occurred due to matching. */
    CANFD_EVENT_SELF_WAKEUP,    /*!< A self wake up event occurred. */
#if FEATURE_CAN_HAS_DMA_ENABLE
    CANFD_EVENT_DMA_COMPLETE, /*!< A complete transfer occurred on DMA */
    CANFD_EVENT_DMA_ERROR,    /*!< A DMA transfer fail, because of a DMA channel error */
#endif                        /* FEATURE_CAN_HAS_DMA_ENABLE */
} Canfd_NotifyEventType_t;

typedef enum
{
    CANFD_RX_COMPLETE, /*!< A frame was received in the configured Rx MB. */
} Canfd_RxMailboxEventType_t;

typedef enum
{
    CANFD_TX_COMPLETE, /*!< A frame was transmited in the configured Tx MB. */
} Canfd_TxMailboxEventType_t;

typedef enum
{
    CANFD_RXFIFO_COMPLETE, /*!< A frame was received in the Rx FIFO. */
    CANFD_RXFIFO_WARNING,  /*!< Rx FIFO is almost full (5 frames). */
    CANFD_RXFIFO_OVERFLOW, /*!< Rx FIFO is full (incoming message was lost). */
} Canfd_RxFifoEventType_t;

typedef enum
{
    CANFD_EVENT_ERROR,
    CANFD_EVENT_RXWARNING,
    CANFD_EVENT_TXWARNING,
    CANFD_EVENT_OFF,
} Canfd_ErrorEventType_t;

/**
 * @brief          CAN Controller State Modes of operation.
 * @details        States that are used by the several ControllerMode functions
 * @implements     Can_Can_ControllerStateType_enumeration
 */
typedef enum
{
    CANFD_UNINITED, /**< @brief CAN controller state UNINIT */
    CANFD_STARTED,  /**< @brief CAN controller state STARTED */
    CANFD_STOPPED,  /**< @brief CAN controller state STOPPED */
    CANFD_SLEEPED   /**< @brief CAN controller state SLEEP */
} Canfd_ControllerStateType;

/*! @brief Canfd Rx FIFO ID filter table structure
 * Implements : Canfd_IdTable_t_Class
 */
typedef struct
{
    bool     isRemoteFrame;   /*!< Remote frame*/
    bool     isExtendedFrame; /*!< Extended frame*/
    uint32_t id;              /*!< Rx FIFO ID filter element*/
} Canfd_IdTable_t;

/*! @brief Canfd bitrate related structures
 * Implements : Canfd_time_segment_t_Class
 */
typedef struct
{
    uint32_t propSeg;    /*!< Propagation segment*/
    uint32_t phaseSeg1;  /*!< Phase segment 1*/
    uint32_t phaseSeg2;  /*!< Phase segment 2*/
    uint32_t preDivider; /*!< Clock prescaler division factor*/
    uint32_t rJumpwidth; /*!< Resync jump width*/
} Canfd_TimeSegment_t;

/*! @brief Canfd message buffer structure
 * Implements : flexcan_msgbuff_t_Class
 */
typedef struct
{
    uint32_t cs;       /*!< Code and Status*/
    uint32_t msgId;    /*!< Message Buffer ID*/
    uint8_t  data[64]; /*!< Data bytes of the FlexCAN message*/
    uint8_t  dataLen;  /*!< Length of data in bytes */
} Canfd_MsgBuff_t;

/*! @brief Canfd data info from user
 * Implements : Canfd_PduInfo_t_Class
 */
typedef struct
{
    Canfd_IdType_t msgIdType;  /*!< Type of message ID (standard or extended)*/
    uint32_t       msgId;      /*!< message ID */
    uint8_t        dataLength; /*!< Length of Data in Bytes*/
    bool           fdEnable;   /*!< Enable or disable FD*/
    uint8_t        fdPadding;  /*!< Set a value for padding. It will be used when the data length code (DLC)
                                     specifies a bigger payload size than dataLength to fill the MB */
    bool brsEnable;            /*!< Enable bit rate switch inside a CAN FD format frame*/
    bool isRemote;             /*!< Specifies if the frame is standard or remote */
} Canfd_PduInfo_t;

/*! @brief Pretended Networking configuration structure
 * Implements : Canfd_PNConfig_t _Class
 */
typedef struct
{
    bool     wakeUpTimeout; /*!< Specifies if an wake up event is triggered on timeout. */
    bool     wakeUpMatch;   /*!< Specifies if an wake up event is triggered on match. */
    uint16_t numMatches;    /*!< The number of matches needed before generating an wake up event. */
    uint16_t matchTimeout;  /*!< Defines a timeout value that generates an wake up event if wakeUpTimeout is true. */
    Canfd_PnCombinationFilter_t filterComb; /*!< Defines the filtering scheme used. */
    Canfd_PnIdFilter_t idFilter1;       /*!< The configuration of the first ID filter (match exact / lower limit / upper
                                               limit). */
    Canfd_PnIdFilter_t       idFilter2; /*!< The configuration of the second ID filter (mask / upper limit). */
    Canfd_PnFilterSeletion_t idFilterType;      /*!< Defines the ID filtering scheme. */
    Canfd_PnFilterSeletion_t payloadFilterType; /*!< Defines the payload filtering scheme. */
    Canfd_PnPayloadFilter_t  payloadFilter;     /*!< The configuration of the payload filter. */
} Canfd_PNConfig_t;

#define CHECK_CANFD_ALL_PERIPH_ADDR(PERIPH)                                                                            \
    (((PERIPH) == CANFD0PTR) || ((PERIPH) == CANFD1PTR) || ((PERIPH) == CANFD2PTR) || ((PERIPH) == CANFD3PTR) ||       \
     ((PERIPH) == CANFD4PTR) || ((PERIPH) == CANFD5PTR) || ((PERIPH) == CANFD6PTR) || ((PERIPH) == CANFD7PTR))

/**************************************************************************
 *         Export Functions
 **************************************************************************/
/**
 * @brief 获取canfd feature 是否使能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 *         false:canfd feature 未使能
 *         true:canfd feeature 已经使能
 */
KF_INLINE bool Canfd_LL_IsFDEnabled(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_FDEN_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_FDEN_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_MCR.bits.FDEN));
#endif
}

/**
 * @brief 设置canfd feature 使能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 *            true:使能canfd feature
 *            false:禁止canfd feature
 * @return void
 */

KF_INLINE void Canfd_LL_SetFDEnabled(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_FDEN_MASK;
    regValue |= Status << HWIO_CANFD0_MCR_CANFD0_MCR_FDEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.FDEN, Status);
#endif
}

/**
 * @brief 获取canfd 软件复位状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 *         true:Module 执行了软件复位
 *         false:Module 未执行软件复位
 */
KF_INLINE bool Canfd_LL_IsSoftReset(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_SOFTRST_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_SOFTRST_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_MCR.bits.SOFTRST));
#endif
}

/**
 * @brief 获取canfd 软件复位状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 *         true:Module 执行软件复位
 *         false:Module 取消软件复位
 */
KF_INLINE void Canfd_LL_SetSoftReset(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_SOFTRST_MASK;
    regValue |= Status << HWIO_CANFD0_MCR_CANFD0_MCR_SOFTRST_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.SOFTRST, Status);
#endif
}

/**
 * @brief 设置canfd feature 使能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 *            true:module 处于非ready状态
 *            false:module 处于ready状态
 */

KF_INLINE bool Canfd_LL_GetReadyState(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_NOTRDT_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_NOTRDT_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_MCR.bits.NOTRDT));
#endif
}

/**
 * @brief 获取canfd  是否处于freeze状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 *         false:canfd 处于 freeze 模式
 *         true:canfd 未处于 freeze 模式
 */
KF_INLINE bool Canfd_LL_IsFreezeEnabled(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_FRZACK_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_FRZACK_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_MCR.bits.FRZ));
#endif
}

/**
 * @brief 设置canfd freeze 使能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 *            true:使能freeze 模式
 *            false:禁止freeze 模式
 * @return void
 */

KF_INLINE void Canfd_LL_SetFreezeEnabled(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_FRZACK_MASK;
    regValue |= Status << HWIO_CANFD0_MCR_CANFD0_MCR_FRZACK_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.FRZ, Status);
#endif
}

/**
 * @brief 获取canfd freeze 应答
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 */

KF_INLINE bool Canfd_LL_GetFreezeAck(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_FRZACK_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_FRZACK_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_MCR.bits.FRZACK));
#endif
}

/**
 * @brief 获取canfd 低功耗模式 应答
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 */

KF_INLINE bool Canfd_LL_GetLowPowerModeAck(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_LPMACK_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_LPMACK_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_MCR.bits.LPMACK));
#endif
}

/**
 * @brief 设置
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 *            true:
 *            false:
 * @return void
 */

KF_INLINE void Canfd_LL_SetHaltEnabled(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_HALT_MASK;
    regValue |= Status << HWIO_CANFD0_MCR_CANFD0_MCR_HALT_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.HALT, Status);
#endif
}

/**
 * @brief 设置 模块禁止状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 *            true:
 *            false:
 * @return void
 */

KF_INLINE void Canfd_LL_SetModuleDisabled(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_MDIS_MASK;
    regValue |= Status << HWIO_CANFD0_MCR_CANFD0_MCR_MDIS_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.MDIS, Status);
#endif
}

/**
 * @brief 获取模块使能状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 *         true：模块已使能
 *         false:模块未使能
 */
KF_INLINE bool Canfd_LL_IsDisEnabled(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_MDIS_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_MDIS_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_MCR.bits.MDIS));
#endif
}

/**
 * @brief 设置 监控管理模式
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 *            true:使能监控管理模式
 *            false:禁止监控管理模式
 * @return void
 */

KF_INLINE void Canfd_LL_SetSuperVisorMode(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_SUPV_MASK;
    regValue |= Status << HWIO_CANFD0_MCR_CANFD0_MCR_SUPV_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.SUPV, Status);
#endif
}

/**
 * @brief 设置 监听管理模式
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 *            true:
 *            false:
 * @return void
 */

KF_INLINE void Canfd_LL_SetListenOnlyMode(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_CANFD0_CTRL1_LOM_MASK;
    regValue |= Status << HWIO_CANFD0_CTRL1_CANFD0_CTRL1_LOM_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1.bits.LOM, Status);
#endif
}

/**
 * @brief 设置 回环模式
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 *            true:
 *            false:
 * @return void
 */

KF_INLINE void Canfd_LL_SetLoopBackMode(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_CANFD0_CTRL1_LPB_MASK;
    regValue |= Status << HWIO_CANFD0_CTRL1_CANFD0_CTRL1_LPB_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1.bits.LPB, Status);
#endif
}

/**
 * @brief 设置 错误警告中断使能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 *            true:使能错误警告中断
 *            false:禁止错误警告中断
 * @return void
 */

KF_INLINE void Canfd_LL_EnableWarnIntr(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_WRNEN_MASK;
    regValue |= Status << HWIO_CANFD0_MCR_CANFD0_MCR_WRNEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.WRNEN, Status);
#endif
}

/**
 * @brief 设置 总线错误中断使能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 *            true:使能错误中断
 *            false:禁止错误中断
 * @return void
 */

KF_INLINE void Canfd_LL_EnableErrorFastIntr(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL2_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL2_CANFD0_CTRL2_ERRMSK_FAST_MASK;
    regValue |= Status << HWIO_CANFD0_CTRL2_CANFD0_CTRL2_ERRMSK_FAST_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL2_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL2.bits.ERRMSK_FAST, Status);
#endif
}

/**
 * @brief 获取 总线错误中断
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */

KF_INLINE uint32_t Canfd_LL_GetErrorIntMask(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_CTRL1_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_CTRL1.reg));
#endif
}

/**
 * @brief 设置 总线错误中断使能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 *            true:使能错误中断
 *            false:禁止错误中断
 * @return void
 */

KF_INLINE void Canfd_LL_SetErrorIntMask(CanfdPtr Module, const uint32_t IntMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, IntMask);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1.reg, IntMask);
#endif
}

/**
 * @brief 获取模块R0负载尺寸
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return Canfd_PayloadSize_t
 */
KF_INLINE Canfd_PayloadSize_t Canfd_LL_GetR0PayLoadSize(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR0_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR0_SHFT;
    return ((Canfd_PayloadSize_t)(regValue));
    // TODO: check if correct

#else
    return ((Canfd_PayloadSize_t)REG_READ(Module->CANFD_FDCTRL.bits.MBDSR0));
#endif
}

/**
 * @brief 获取模块R1负载尺寸
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE Canfd_PayloadSize_t Canfd_LL_GetR1PayLoadSize(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR1_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR1_SHFT;
    return ((Canfd_PayloadSize_t)(regValue));
    // TODO: check if correct

#else
    return ((Canfd_PayloadSize_t)REG_READ(Module->CANFD_FDCTRL.bits.MBDSR1));
#endif
}

/**
 * @brief 获取模块R2负载尺寸
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE Canfd_PayloadSize_t Canfd_LL_GetR2PayLoadSize(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR2_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR2_SHFT;
    return ((Canfd_PayloadSize_t)(regValue));
    // TODO: check if correct

#else
    return ((Canfd_PayloadSize_t)REG_READ(Module->CANFD_FDCTRL.bits.MBDSR2));
#endif
}

/**
 * @brief 获取模块R3负载尺寸
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE Canfd_PayloadSize_t Canfd_LL_GetR3PayLoadSize(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR3_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR3_SHFT;
    return ((Canfd_PayloadSize_t)(regValue));
    // TODO: check if correct

#else
    return ((Canfd_PayloadSize_t)REG_READ(Module->CANFD_FDCTRL.bits.MBDSR3));
#endif
}

/**
 * @brief 设置模块R0负载尺寸
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Canfd_PayloadSize_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetR0PayLoadSize(CanfdPtr Module, const Canfd_PayloadSize_t PayloadSize)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR0_MASK;
    regValue |= PayloadSize << HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR0_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCTRL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCTRL.bits.MBDSR0, PayloadSize);
#endif
}

/**
 * @brief 设置模块R1负载尺寸
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Canfd_PayloadSize_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetR1PayLoadSize(CanfdPtr Module, const Canfd_PayloadSize_t PayloadSize)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR1_MASK;
    regValue |= PayloadSize << HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR1_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCTRL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCTRL.bits.MBDSR1, PayloadSize);
#endif
}

/**
 * @brief 设置模块R2负载尺寸
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Canfd_PayloadSize_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetR2PayLoadSize(CanfdPtr Module, const Canfd_PayloadSize_t PayloadSize)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR2_MASK;
    regValue |= PayloadSize << HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR2_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCTRL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCTRL.bits.MBDSR2, PayloadSize);
#endif
}

/**
 * @brief 设置模块R3负载尺寸
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Canfd_PayloadSize_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetR3PayLoadSize(CanfdPtr Module, const Canfd_PayloadSize_t PayloadSize)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR3_MASK;
    regValue |= PayloadSize << HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_MBDSR3_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCTRL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCTRL.bits.MBDSR3, PayloadSize);
#endif
}

/**
 * @brief 获取当前配置下最大邮箱编号
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE uint8_t Canfd_LL_GetMaxMbNum(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_MAXMB_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_MAXMB_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_MCR.bits.MAXMB));
#endif
}

/**
 * @brief 设置当前配置下最大邮箱编号
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t 最大邮箱编号
 * @return void
 */
KF_INLINE void Canfd_LL_SetMaxMbCount(CanfdPtr Module, uint32_t MaxMailboxNumber)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_MAXMB_MASK;
    regValue |= MaxMailboxNumber << HWIO_CANFD0_MCR_CANFD0_MCR_MAXMB_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.MAXMB, MaxMailboxNumber);
#endif
}

#if FEATURE_CAN_HAS_PE_CLKSRC_SELECT
/*!
 * @brief 设置 CAN Engine 时钟源
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] ClkSource
 *            CANFD_CLK_SOURCE_OSC
 *            CANFD_CLK_SOURCE_PERIPH
 * @return void
 */
KF_INLINE void Canfd_LL_SelectClock(CanfdPtr Module, Canfd_ClkSource_t ClkSource)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_CANFD0_CTRL1_CLKSRC_MASK;
    regValue |= ClkSource << HWIO_CANFD0_CTRL1_CANFD0_CTRL1_CLKSRC_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1.bits.CLKSRC, ClkSource);
#endif
}
#endif

/*!
 * @brief 设置 CANFD ISO Frame Format
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] bool
 * @return void
 */
KF_INLINE void Canfd_LL_SetISOfdMode(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL2_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL2_CANFD0_CTRL2_ISOANFDEN_MASK;
    regValue |= Status << HWIO_CANFD0_CTRL2_CANFD0_CTRL2_ISOANFDEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL2_ADDR, regValue);
    // TODO: check if correct
#else
    REG_WRITE(Module->CANFD_CTRL2.bits.ISOCANFDEN, Status);
#endif
}

/*!
 * @brief 禁止 接收自身节点发送的报文
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] bool
 * @return void
 */
KF_INLINE void Canfd_LL_SetSelfReception(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_SRXDIS_MASK;
    regValue |= Status ? false : true << HWIO_CANFD0_MCR_CANFD0_MCR_SRXDIS_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.SRXDIS, Status ? false : true);
#endif
}

/*!
 * @brief 获取 最后一个被Rxfifo 占据的数据缓冲区
 * @param[in] Module
 * @return bool
 */
KF_INLINE uint32_t Canfd_LL_RxFifoOcuppiedLastMsgBuff(uint32_t FilterNumber)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    return (5U + ((((FilterNumber) + 1U) * 8U) / 4U));
}

/*!
 * @brief 设置 RXFIFO使能状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxFifoEnable(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_RFEN_MASK;
    regValue |= Status << HWIO_CANFD0_MCR_CANFD0_MCR_RFEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.RFEN, Status);
#endif
}

/*!
 * @brief 获取 RXFIFO使能状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 */
KF_INLINE bool Canfd_LL_IsRxFifoEnabled(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_RFEN_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_RFEN_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_MCR.bits.RFEN));
#endif
}

/*!
 * @brief 获取 RXFIFO使能状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] bool
 *            true:使能DMA 功能
 *            false:禁止DMA 功能
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxFifoDMA(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_DMA_MASK;
    regValue |= Status << HWIO_CANFD0_MCR_CANFD0_MCR_DMA_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.DMA, Status);
#endif
}

/*!
 * @brief 设置 canfd 帧波特率切换功能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] bool
 *            true:使能CANFD 帧波特率切换
 *            false:禁止CANFD 帧波特率功能
 * @return void
 */
KF_INLINE void Canfd_LL_SetFdRateSwitch(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_FDRATE_MASK;
    regValue |= Status << HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_FDRATE_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCTRL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCTRL.bits.FDRATE, Status);
#endif
}

/*!
 * @brief 设置 canfd 波特率传输段参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetPropSeg(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PROPSEG_MASK;
    regValue |= Value << HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PROPSEG_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1.bits.PROPSEG, Value);
#endif
}

/*!
 * @brief 获取 canfd 波特率传输段参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetPropSeg(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PROPSEG_MASK;
    regValue = regValue >> HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PROPSEG_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_CTRL1.bits.PROPSEG));
#endif
}

/*!
 * @brief 设置 canfd 波特率T1参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetPSeg1(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PSEG1_MASK;
    regValue |= Value << HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PSEG1_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1.bits.PSEG1, Value);
#endif
}

/*!
 * @brief 获取 canfd 波特率T1参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetPSeg1(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PSEG1_MASK;
    regValue = regValue >> HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PSEG1_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_CTRL1.bits.PSEG1));
#endif
}

/*!
 * @brief 设置 canfd 波特率T2参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetPSeg2(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PSEG2_MASK;
    regValue |= Value << HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PSEG2_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1.bits.PSEG2, Value);
#endif
}

/*!
 * @brief 获取 canfd 波特率T2参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetPSeg2(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PSEG2_MASK;
    regValue = regValue >> HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PSEG2_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_CTRL1.bits.PSEG2));
#endif
}

/*!
 * @brief 设置 canfd 波特率预分频系数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetPDivide(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PRESDIV_MASK;
    regValue |= Value << HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PRESDIV_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1.bits.PRESDIV, Value);
#endif
}

/*!
 * @brief 获取 canfd 波特率预分频系数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetPDivide(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PRESDIV_MASK;
    regValue = regValue >> HWIO_CANFD0_CTRL1_CANFD0_CTRL1_PRESDIV_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_CTRL1.bits.PRESDIV));
#endif
}

/*!
 * @brief 设置 canfd 波特率同步跳转宽度
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetPRJW(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_CANFD0_CTRL1_RJW_MASK;
    regValue |= Value << HWIO_CANFD0_CTRL1_CANFD0_CTRL1_RJW_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1.bits.RJW, Value);
#endif
}

/*!
 * @brief 获取 canfd 波特率同步跳转宽度
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetPRJW(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_CTRL1_CANFD0_CTRL1_RJW_MASK;
    regValue = regValue >> HWIO_CANFD0_CTRL1_CANFD0_CTRL1_RJW_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_CTRL1.bits.RJW));
#endif
}

/*!
 * @brief 设置 canfd 波特率传输段扩展参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetEPropSeg(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CBT_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CBT_CANFD0_CBT_EPROPSEG_MASK;
    regValue |= Value << HWIO_CANFD0_CBT_CANFD0_CBT_EPROPSEG_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CBT.bits.EPROPSEG, Value);
#endif
}

/*!
 * @brief 设置 canfd 波特率T1扩展参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetEPSeg1(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CBT_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CBT_CANFD0_CBT_EPSEG1_MASK;
    regValue |= Value << HWIO_CANFD0_CBT_CANFD0_CBT_EPSEG1_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CBT.bits.EPSEG1, Value);
#endif
}

/*!
 * @brief 设置 canfd 波特率T2扩展参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetEPSeg2(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CBT_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CBT_CANFD0_CBT_EPSEG2_MASK;
    regValue |= Value << HWIO_CANFD0_CBT_CANFD0_CBT_EPSEG2_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CBT.bits.EPSEG2, Value);
#endif
}

/*!
 * @brief 设置 canfd 波特率预分频扩展系数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetEPDivide(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CBT_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CBT_CANFD0_CBT_EPRESDIV_MASK;
    regValue |= Value << HWIO_CANFD0_CBT_CANFD0_CBT_EPRESDIV_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CBT.bits.EPRESDIV, Value);
#endif
}

/*!
 * @brief 设置 canfd 波特率同步跳转宽度扩展系数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetEPRJW(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CBT_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CBT_CANFD0_CBT_ERJW_MASK;
    regValue |= Value << HWIO_CANFD0_CBT_CANFD0_CBT_ERJW_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CBT.bits.ERJW, Value);
#endif
}

/*!
 * @brief 设置 canfd FD波特率传输段扩展参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetFDPropSeg(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCBT_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPROPSEG_MASK;
    regValue |= Value << HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPROPSEG_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCBT.bits.FPROPSEG, Value);
#endif
}

/*!
 * @brief 获取 canfd FD波特率传输段扩展参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetFDPropSeg(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCBT_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPROPSEG_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPROPSEG_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_FDCBT.bits.FPROPSEG));
#endif
}

/*!
 * @brief 设置 canfd FD波特率T1参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetFDPSeg1(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCBT_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPSEG1_MASK;
    regValue |= Value << HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPSEG1_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCBT.bits.FPSEG1, Value);
#endif
}

/*!
 * @brief 获取 canfd FD波特率T1参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetFDSeg1(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCBT_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPSEG1_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPSEG1_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_FDCBT.bits.FPSEG1));
#endif
}

/*!
 * @brief 设置 canfd FD波特率T2参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetFDPSeg2(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCBT_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPSEG2_MASK;
    regValue |= Value << HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPSEG2_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCBT.bits.FPSEG2, Value);
#endif
}

/*!
 * @brief 获取 canfd FD波特率T2参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetFDPSeg2(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCBT_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPSEG2_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPSEG2_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_FDCBT.bits.FPSEG2));
#endif
}

/*!
 * @brief 设置 canfd FD波特率预分频系数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetFDPDivide(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCBT_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPRESDIV_MASK;
    regValue |= Value << HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPRESDIV_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCBT.bits.FPRESDIV, Value);
#endif
}

/*!
 * @brief 获取 canfd FD波特率预分频系数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetFDPDivide(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCBT_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPRESDIV_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FPRESDIV_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_FDCBT.bits.FPRESDIV));
#endif
}

/*!
 * @brief 设置 canfd FD波特率同步跳转宽度参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetFDPRJW(CanfdPtr Module, const uint32_t Value)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCBT_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FRJW_MASK;
    regValue |= Value << HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FRJW_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCBT_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCBT.bits.FRJW, Value);
#endif
}

/*!
 * @brief 获取 canfd FD波特率同步跳转宽度参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetFDPRJW(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCBT_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FRJW_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCBT_CANFD0_FDCBT_FRJW_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_FDCBT.bits.FRJW));
#endif
}

/*!
 * @brief 设置 CANFD波特率配置参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Type 掩码类型
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMaskType(CanfdPtr Module, Canfd_RxMaskType_t Type)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    /* Set RX masking type (RX global mask or RX individual mask)*/
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_IRQM_MASK;
    regValue |= Type << HWIO_CANFD0_MCR_CANFD0_MCR_IRQM_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.IRQM, Type);
#endif
}

/*!
 * @brief 设置 接收FIFO滤波器数量
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uin32_t 接收FIFO滤波器数量值
 * @return void
 */
KF_INLINE void Canfd_LL_SetLegacyFifoFilterNum(CanfdPtr Module, uint32_t FilterNumber)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL2_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL2_CANFD0_CTRL2_RFFN_MASK;
    regValue |= FilterNumber << HWIO_CANFD0_CTRL2_CANFD0_CTRL2_RFFN_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL2_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL2.bits.RFFN, FilterNumber);
#endif
}

/*!
 * @brief 获取 接收FIFO滤波器数量
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetLegacyFifoFilterNum(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL2_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_CTRL2_CANFD0_CTRL2_RFFN_MASK;
    regValue = regValue >> HWIO_CANFD0_CTRL2_CANFD0_CTRL2_RFFN_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_CTRL2.bits.RFFN));
#endif
}

/*!
 * @brief 设置 接收FIFO ID格式
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Mode 接收FIFO滤波器格式
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxFifoIdFormat(CanfdPtr Module, Canfd_RxFifoIdFormat_t Mode)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_IDAM_MASK;
    regValue |= Mode << HWIO_CANFD0_MCR_CANFD0_MCR_IDAM_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.IDAM, Mode);
#endif
}

/*!
 * @brief 获取 接收FIFO ID格式
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return Canfd_RxFifoIdFormat_t
 */
KF_INLINE Canfd_RxFifoIdFormat_t Canfd_LL_GetRxFifoIdFormat(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_IDAM_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_IDAM_SHFT;
    return ((Canfd_RxFifoIdFormat_t)(regValue));
    // TODO: check if correct

#else
    return ((Canfd_RxFifoIdFormat_t)REG_READ(Module->CANFD_MCR.bits.IDAM));
#endif
}

/*!
 * @brief 设置 接收FIFO 全局掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Mask 全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxFifoGlobalMask(CanfdPtr Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RXFGMASK_ADDR, Mask);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_RXFGMASK, Mask);
#endif
}

/*!
 * @brief 设置 接收邮箱 全局掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Mask 全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMbGlobalMask(CanfdPtr Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RXMGMASK_ADDR, Mask);
    // TODO: check if correct
#else
    REG_WRITE(Module->RXMGMASK.reg, Mask);
#endif
}

/*!
 * @brief 设置 接收邮箱 标准帧全局掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] StdMask 标准帧全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMbGlobalStdMask(CanfdPtr Module, uint32_t StdMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_RXMGMASK_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_RXMGMASK_STD_MASK;
    regValue |= StdMask << HWIO_CANFD0_RXMGMASK_STD_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RXMGMASK_ADDR, regValue);
    // TODO: check if correct
#else
    REG_WRITE(Module->RXMGMASK.SFF.MASK, StdMask);
#endif
}

/*!
 * @brief 设置 接收邮箱 扩展帧全局掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] ExtMask 扩展帧全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMbGlobalExtMask(CanfdPtr Module, uint32_t ExtMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_RXMGMASK_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_RXMGMASK_ETD_MASK;
    regValue |= ExtMask << HWIO_CANFD0_RXMGMASK_ETD_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RXMGMASK_ADDR, regValue);
    // TODO: check if correct
#else
    REG_WRITE(Module->RXMGMASK.EFF.MASK, ExtMask);
#endif
}

/*!
 * @brief 设置 接收邮箱14掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] StdMask 全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMb14Mask(CanfdPtr Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RX14MASK_ADDR, Mask);
    // TODO: check if correct
#else
    REG_WRITE((Module->RX14MASK.reg), Mask);
#endif
}

/*!
 * @brief 设置 接收邮箱14标准帧掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] StdMask 标准帧全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMb14StdMask(CanfdPtr Module, uint32_t StdMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_RX14MASK_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_RX14MASK_STD_MASK;
    regValue |= StdMask << HWIO_CANFD0_RX14MASK_STD_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RX14MASK_ADDR, regValue);
    // TODO: check if correct
#else
    REG_WRITE((Module->RX14MASK.SFF.MASK), StdMask);
#endif
}

/*!
 * @brief 设置 接收邮箱14扩展帧掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] ExtMask 扩展帧全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMb14ExtMask(CanfdPtr Module, uint32_t ExtMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_RX14MASK_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_RX14MASK_ETD_MASK;
    regValue |= ExtMask << HWIO_CANFD0_RX14MASK_ETD_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RX14MASK_ADDR, regValue);
    // TODO: check if correct
#else
    REG_WRITE((Module->RX14MASK.EFF.MASK), ExtMask);
#endif
}

/*!
 * @brief 设置 接收邮箱15掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] StdMask 全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMb15Mask(CanfdPtr Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RX15MASK_ADDR, Mask);
    // TODO: check if correct
#else
    REG_WRITE((Module->RX15MASK.reg), Mask);
#endif
}

/*!
 * @brief 设置 接收邮箱15标准帧掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] StdMask 标准帧全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMb15StdMask(CanfdPtr Module, uint32_t StdMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_RX15MASK_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_RX15MASK_STD_MASK;
    regValue |= StdMask << HWIO_CANFD0_RX15MASK_STD_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RX15MASK_ADDR, regValue);
    // TODO: check if correct
#else
    REG_WRITE((Module->RX15MASK.SFF.MASK), StdMask);
#endif
}

/*!
 * @brief 设置 接收邮箱15扩展帧掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] ExtMask 标准帧全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxMb15ExtMask(CanfdPtr Module, uint32_t ExtMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_RX15MASK_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_RX15MASK_ETD_MASK;
    regValue |= ExtMask << HWIO_CANFD0_RX15MASK_ETD_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RX15MASK_ADDR, regValue);
    // TODO: check if correct
#else
    REG_WRITE((Module->RX15MASK.EFF.MASK), ExtMask);
#endif
}

/*!
 * @brief 设置 接收独立邮箱掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] MbIndex 邮箱编号
 * @param[in] Mask 独立邮箱掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxIndividualMask(CanfdPtr Module, uint32_t MbIndex, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(Module->CANFD_RXIMR[MbIndex].reg, Mask);
#endif
}

/*!
 * @brief 设置 接收独立邮箱标准掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] MbIndex 邮箱编号
 * @param[in] StdMask 独立邮箱掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxIndividualStdMask(CanfdPtr Module, uint32_t MbIndex, uint32_t StdMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(Module->CANFD_RXIMR[MbIndex].SFF.MASK, StdMask);
#endif
}

/*!
 * @brief 设置 接收独立邮箱扩展掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] MbIndex 邮箱编号
 * @param[in] ExtMask 独立邮箱掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetRxIndividualExtMask(CanfdPtr Module, uint32_t MbIndex, uint32_t ExtMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
// TODO: cannot process please check
#else
    REG_WRITE(Module->CANFD_RXIMR[MbIndex].EFF.MASK, ExtMask);
#endif
}

/*!
 * @brief 设置 Region0 中断掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Mask 中断全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetInt1Mask(CanfdPtr Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_IMASK1_ADDR, Mask);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_IMASK1.reg, Mask);
#endif
}

/*!
 * @brief 获取 Region0 中断掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetInt1Mask(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_IMASK1_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_IMASK1.reg));
#endif
}

/*!
 * @brief 清除 Region0 中断标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Flag 中断标志位
 * @return void
 */
KF_INLINE void Canfd_LL_ClearInt1Flag(CanfdPtr Module, uint32_t Flag)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_IFLAG1_ADDR, Flag);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_IFLAG1.reg, Flag);
#endif
}

/*!
 * @brief 获取 Region0 中断标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetInt1Flag(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_IFLAG1_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_IFLAG1.reg));
#endif
}

/*!
 * @brief 设置 Region1 中断掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Mask 中断全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetInt2Mask(CanfdPtr Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_IMASK2_ADDR, Mask);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_IMASK2.reg, Mask);
#endif
}

/*!
 * @brief 获取 Region1 中断掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetInt2Mask(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_IMASK2_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_IMASK2.reg));
#endif
}

/*!
 * @brief 清除 Region1 中断标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Flag 中断标志位
 * @return void
 */
KF_INLINE void Canfd_LL_ClearInt2Flag(CanfdPtr Module, uint32_t Flag)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_IFLAG2_ADDR, Flag);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_IFLAG2.reg, Flag);
#endif
}

/*!
 * @brief 获取 Region1 中断标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetInt2Flag(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_IFLAG2_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_IFLAG2.reg));
#endif
}

/*!
 * @brief 设置 Region2 中断掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Mask 中断全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetInt3Mask(CanfdPtr Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_IMASK3_ADDR, Mask);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_IMASK3.reg, Mask);
#endif
}

/*!
 * @brief 获取 Region2 中断掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetInt3Mask(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_IMASK3_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_IMASK3.reg));
#endif
}

/*!
 * @brief 清除 Region2 中断标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Flag 中断标志位
 * @return void
 */
KF_INLINE void Canfd_LL_ClearInt3Flag(CanfdPtr Module, uint32_t Flag)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_IFLAG3_ADDR, Flag);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_IFLAG3.reg, Flag);
#endif
}

/*!
 * @brief 获取 Region2 中断标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetInt3Flag(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_IFLAG3_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_IFLAG3.reg));
#endif
}

/*!
 * @brief 设置 Region3 中断掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Mask 中断全局掩码值
 * @return void
 */
KF_INLINE void Canfd_LL_SetInt4Mask(CanfdPtr Module, uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_IMASK4_ADDR, Mask);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_IMASK4.reg, Mask);
#endif
}

/*!
 * @brief 获取 Region3 中断掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetInt4Mask(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_IMASK4_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_IMASK4.reg));
#endif
}

/*!
 * @brief 清除 Region3 中断标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Flag 中断标志位
 * @return void
 */
KF_INLINE void Canfd_LL_ClearInt4Flag(CanfdPtr Module, uint32_t Flag)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_IFLAG4_ADDR, Flag);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_IFLAG4.reg, Flag);
#endif
}

/*!
 * @brief 获取 Region3 中断标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetInt4Flag(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_IFLAG4_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_IFLAG4.reg));
#endif
}

/*!
 * @brief 清除 错误状态位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status 错误状态
 * @return void
 */
KF_INLINE void Canfd_LL_ClearErrorStatus(CanfdPtr Module, uint32_t Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_ADDR, Status);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_ESR1.reg, Status);
#endif
}

/*
 * @brief 获取发送器延时补偿值
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint8_t
 */
KF_INLINE uint8_t Canfd_LL_GetTDCValue(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_TDCVAL_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_TDCVAL_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_FDCTRL.bits.TDCVAL));
#endif
}

/*!
 * @brief 获取发送器延时补偿失败标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 */
KF_INLINE bool Canfd_LL_GetTDCFail(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_TDCFAIL_MASK;
    regValue = regValue >> HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_TDCFAIL_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_FDCTRL.bits.TDCFAIL));
#endif
}

/*!
 * @brief 清除发送器延时补偿失败标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_ClearTDCFail(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_TDCFAIL_MASK;
    regValue |= true << HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_TDCFAIL_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCTRL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCTRL.bits.TDCFAIL, true);
#endif
}

/*!
 * @brief 解锁接收邮箱
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_UnlockRxMb(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    /* Unlock the mailbox by reading the free running timer */
    (void)Module->CANFD_TIMER.reg;
}

/*!
 * @brief 获取 唤醒超时标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 */
KF_INLINE bool Canfd_LL_GetWTOF(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_MASK + offsetAddr);
    regValue &= HWIO_CANFD0_WU_MTC_CANFD0_WU_MTC_WTOF_MASK;
    regValue = regValue >> HWIO_CANFD0_WU_MTC_CANFD0_WU_MTC_WTOF_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_WU_MTC.bits.WTOF));
#endif
}

/*!
 * @brief 设置 超时唤醒掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] bool
 * @return void
 */
KF_INLINE void Canfd_LL_SetWkupTimeoutMask(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WTOF_MSK_MASK;
    regValue |= Status << HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WTOF_MSK_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1_PN.bits.WTOF_MSK, Status);
#endif
}

/*!
 * @brief 设置 匹配唤醒掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] bool
 * @return void
 */
KF_INLINE void Canfd_LL_SetWkupMatchMask(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_MASK;
    regValue |= Status << HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1_PN.bits.WUMF_MSK, Status);
#endif
}

/*!
 * @brief 设置 匹配唤醒次数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] uint32_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetWkupMatchNumber(CanfdPtr Module, const uint32_t MatchNumber)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_NMATCH_MASK;
    regValue |= MatchNumber << HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_NMATCH_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1_PN.bits.NMATCH, MatchNumber);
#endif
}

/*!
 * @brief 设置 组合滤波模式
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Canfd_PnCombinationFilter_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetFilterComb(CanfdPtr Module, const Canfd_PnCombinationFilter_t FilterComb)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_FCS_MASK;
    regValue |= FilterComb << HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_FCS_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1_PN.bits.FCS, FilterComb);
#endif
}

/*!
 * @brief 设置 ID滤波模式
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Canfd_PnFilterSeletion_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetIdFilterSelection(CanfdPtr Module, const Canfd_PnFilterSeletion_t IdFilterType)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_IDFS_MASK;
    regValue |= IdFilterType << HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_IDFS_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1_PN.bits.IDFS, IdFilterType);
#endif
}

/*!
 * @brief 设置 负载滤波模式
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Canfd_PnFilterSeletion_t
 * @return void
 */
KF_INLINE void Canfd_LL_SetPayloadFilterSelection(CanfdPtr Module, const Canfd_PnFilterSeletion_t PayloadFilterType)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_PLFS_MASK;
    regValue |= PayloadFilterType << HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_PLFS_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL1_PN.bits.PLFS, PayloadFilterType);
#endif
}

/*!
 * @brief 获取 唤醒匹配标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return bool
 */
KF_INLINE uint8_t Canfd_LL_GetWUMF(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_MASK + offsetAddr);
    regValue &= HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_MASK;
    regValue = regValue >> HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_WU_MTC.bits.WUMF));
#endif
}

/*!
 * @brief 清除 唤醒超时标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_ClearWTOF(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_WU_MTC_CANFD0_WU_MTC_WTOF_MASK;
    regValue |= true << HWIO_CANFD0_WU_MTC_CANFD0_WU_MTC_WTOF_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_WU_MTC.bits.WTOF, true);
#endif
}

/*!
 * @brief 清除 唤醒匹配标志位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_ClearWUMF(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_MASK;
    regValue |= true << HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL1_PN_CANFD0_CTRL1_PN_WUMF_MSK_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_WU_MTC.bits.WUMF, true);
#endif
}

/*!
 * @brief 获取 硬件错误计数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE uint32_t Canfd_LL_GetErrorCounters(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_ECR_ADDR));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_ECR.reg));
#endif
}

/*!
 * @brief 清除 接收FIFO
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_ClearFIFO(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_IFLAG1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_IFLAG1_CANFD0_IFLAG1_BUF0I_MASK;
    regValue |= true << HWIO_CANFD0_IFLAG1_CANFD0_IFLAG1_BUF0I_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_IFLAG1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_IFLAG1.bits.BUF0I, true);
#endif
}

/*!
 * @brief 设置 Pretended Networking 超时计数值
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Timeout 超时时间
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNTimeoutValue(CanfdPtr Module, uint16_t Timeout)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL2_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL2_PN_CANFD0_CTRL2_PN_MATCHTO_MASK;
    regValue |= Timeout << HWIO_CANFD0_CTRL2_PN_CANFD0_CTRL2_PN_MATCHTO_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL2_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL2_PN.bits.MATCHTO, Timeout);
#endif
}

/*!
 * @brief 设置 Pretended Networking 工作状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status
 * @return void
 */
KF_INLINE void Canfd_LL_SetPN(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MCR_CANFD0_MCR_PNET_EN_MASK;
    regValue |= Status << HWIO_CANFD0_MCR_CANFD0_MCR_PNET_EN_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MCR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MCR.bits.PNET_EN, Status);
#endif
}

/*!
 * @brief 获取 Pretended Networking 工作状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE bool Canfd_LL_IsPNEnabled(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MCR_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_MCR_CANFD0_MCR_PNET_EN_MASK;
    regValue = regValue >> HWIO_CANFD0_MCR_CANFD0_MCR_PNET_EN_SHFT;
    return ((regValue));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_MCR.bits.PNET_EN));
#endif
}

/*!
 * @brief 设置 Pretended Networking 帧类型滤波
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNExtendEnabled(CanfdPtr Module, const bool IsExtended)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_FLT_ID1_CANFD0_FLT_ID1_FLT_IDE_MASK;
    regValue |= IsExtended << HWIO_CANFD0_FLT_ID1_CANFD0_FLT_ID1_FLT_IDE_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_ID1.bits.FLT_IDE, IsExtended);
#endif
}

/*!
 * @brief 设置 Pretended Networking 帧类型滤波
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNRemoteEnabled(CanfdPtr Module, const bool IsRemote)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_FLT_ID1_CANFD0_FLT_ID1_FLT_RTR_MASK;
    regValue |= IsRemote << HWIO_CANFD0_FLT_ID1_CANFD0_FLT_ID1_FLT_RTR_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_ID1.bits.FLT_RTR, IsRemote);
#endif
}

/*!
 * @brief 设置 Pretended Networking 标准帧ID
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNStandId(CanfdPtr Module, const uint32_t StandID)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_FLT_ID1_CANFD0_FLT_ID1_FLT_ID1_MASK;
    regValue |= StandID << CAN_ID_STD_SHIFT << HWIO_CANFD0_FLT_ID1_CANFD0_FLT_ID1_FLT_ID1_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_ID1.bits.FLT_ID1, StandID << CAN_ID_STD_SHIFT);
#endif
}

/*!
 * @brief 设置 Pretended Networking 扩展帧ID
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNExtendId(CanfdPtr Module, const uint32_t ExtendID)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_FLT_ID1_CANFD0_FLT_ID1_FLT_ID1_MASK;
    regValue |= ExtendID << HWIO_CANFD0_FLT_ID1_CANFD0_FLT_ID1_FLT_ID1_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_ID1.bits.FLT_ID1, ExtendID);
#endif
}

/*!
 * @brief 设置 Pretended Networking 帧类型滤波掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNExtendMask(CanfdPtr Module, const bool ExtendedMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_FLT_ID2_IDMASK_CANFD0_FLT_ID2_IDMASK_IDE_MSK_SHFT;
    regValue |= ExtendedMask << 30U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_ID2_IDMASK.bits.IDE_MSK, ExtendedMask);
#endif
}

/*!
 * @brief 设置 Pretended Networking 帧类型滤波掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNRemoteMask(CanfdPtr Module, const bool RemoteMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_FLT_ID2_IDMASK_CANFD0_FLT_ID2_IDMASK_RTR_MSK_SHFT;
    regValue |= RemoteMask << 29U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_ID2_IDMASK.bits.RTR_MSK, RemoteMask);
#endif
}

/*!
 * @brief 设置 Pretended Networking 标准帧ID掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNStandIdMask(CanfdPtr Module, const uint32_t StandIMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_FLT_ID2_IDMASK_ADDR;
    regValue |= StandIMask << CAN_ID_STD_SHIFT << 0U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_ID2_IDMASK.bits.FLT_ID2_IDMASK, StandIMask << CAN_ID_STD_SHIFT);
#endif
}

/*!
 * @brief 设置 Pretended Networking 扩展帧ID掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNExtendIdMask(CanfdPtr Module, const uint32_t ExtendIDMask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_FLT_ID2_IDMASK_ADDR;
    regValue |= ExtendIDMask << 0U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_ID2_IDMASK.bits.FLT_ID2_IDMASK, ExtendIDMask);
#endif
}

/*!
 * @brief 获取 Pretended Networking 掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */
KF_INLINE uint32_t Canfd_LL_GetPNMask(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    return (REG_READ(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK));
    // TODO: check if correct

#else
    return (REG_READ(Module->CANFD_FLT_ID2_IDMASK.reg));
#endif
}

/*!
 * @brief 设置 Pretended Networking 掩码
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNMask(CanfdPtr Module, const uint32_t Mask)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, Mask);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_ID2_IDMASK.reg, Mask);
#endif
}

/*!
 * @brief 设置 Pretended Networking DLC下限
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNLowDLC(CanfdPtr Module, const uint32_t LowDLC)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_FLT_DLC_CANFD0_FLT_DLC_FLT_DLC_LO_MASK;
    regValue |= LowDLC << HWIO_CANFD0_FLT_DLC_CANFD0_FLT_DLC_FLT_DLC_LO_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_DLC.bits.FLT_DLC_LO, LowDLC);
#endif
}

/*!
 * @brief 设置 Pretended Networking DLC上限
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNHighDLC(CanfdPtr Module, const uint32_t HighDLC)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK + offsetAddr);
    regValue &= ~HWIO_CANFD0_FLT_DLC_CANFD0_FLT_DLC_FLT_DLC_HI_MASK;
    regValue |= HighDLC << HWIO_CANFD0_FLT_DLC_CANFD0_FLT_DLC_FLT_DLC_HI_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_ESR1_CANFD0_ESR1_FLTCONF_MASK, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FLT_DLC.bits.FLT_DLC_HI, HighDLC);
#endif
}

/*!
 * @brief 设置 Pretended Networking 滤波byte0
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNLowPayLoadByte0(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL1_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL1_LO_CANFD0_PL1_LO_DATA_BYTE_0_MASK;
    regValue |= Data << HWIO_CANFD0_PL1_LO_CANFD0_PL1_LO_DATA_BYTE_0_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL1_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL1_LO.bits.DATA_BYTE_0, Data);
#endif
}

/*!
 * @brief 设置 Pretended Networking 滤波byte1
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNLowPayLoadByte1(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL1_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL1_LO_CANFD0_PL1_LO_DATA_BYTE_1_MASK;
    regValue |= Data << HWIO_CANFD0_PL1_LO_CANFD0_PL1_LO_DATA_BYTE_1_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL1_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL1_LO.bits.DATA_BYTE_1, Data);
#endif
}

/*!
 * @brief 设置 Pretended Networking 滤波byte2
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNLowPayLoadByte2(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL1_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL1_LO_CANFD0_PL1_LO_DATA_BYTE_2_MASK;
    regValue |= Data << HWIO_CANFD0_PL1_LO_CANFD0_PL1_LO_DATA_BYTE_2_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL1_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL1_LO.bits.DATA_BYTE_2, Data);
#endif
}

/*!
 * @brief 设置 Pretended Networking 滤波byte3
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNLowPayLoadByte3(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL1_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL1_LO_CANFD0_PL1_LO_DATA_BYTE_3_MASK;
    regValue |= Data << HWIO_CANFD0_PL1_LO_CANFD0_PL1_LO_DATA_BYTE_3_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL1_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL1_LO.bits.DATA_BYTE_3, Data);
#endif
}

/*!
 * @brief 获取 Pretended Networking 滤波byte4
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNHighPayLoadByte4(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL1_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL1_HI_CANFD0_PL1_HI_DATA_BYTE_4_MASK;
    regValue |= Data << HWIO_CANFD0_PL1_HI_CANFD0_PL1_HI_DATA_BYTE_4_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL1_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL1_HI.bits.DATA_BYTE_4, Data);
#endif
}

/*!
 * @brief 获取 Pretended Networking 滤波byte5
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNHighPayLoadByte5(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL1_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL1_HI_CANFD0_PL1_HI_DATA_BYTE_5_MASK;
    regValue |= Data << HWIO_CANFD0_PL1_HI_CANFD0_PL1_HI_DATA_BYTE_5_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL1_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL1_HI.bits.DATA_BYTE_5, Data);
#endif
}

/*!
 * @brief 获取 Pretended Networking 滤波byte6
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNHighPayLoadByte6(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL1_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL1_HI_CANFD0_PL1_HI_DATA_BYTE_6_MASK;
    regValue |= Data << HWIO_CANFD0_PL1_HI_CANFD0_PL1_HI_DATA_BYTE_6_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL1_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL1_HI.bits.DATA_BYTE_6, Data);
#endif
}

/*!
 * @brief 获取 Pretended Networking 滤波byte7
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNHighPayLoadByte7(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL1_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL1_HI_CANFD0_PL1_HI_DATA_BYTE_7_MASK;
    regValue |= Data << HWIO_CANFD0_PL1_HI_CANFD0_PL1_HI_DATA_BYTE_7_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL1_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL1_HI.bits.DATA_BYTE_7, Data);
#endif
}

/*!
 * @brief 设置 Pretended Networking 滤波掩码byte0
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNLowPayLoadByte0Mask(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL2_PLMASK_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL2_PLMASK_LO_CANFD0_PL2_PLMASK_LO_DATA_BYTE_0_SHFT;
    regValue |= Data << 24U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL2_PLMASK_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL2_PLMASK_LO.bits.DATA_BYTE_0, Data);
#endif
}

/*!
 * @brief 设置 Pretended Networking 滤波掩码byte1
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNLowPayLoadByte1Mask(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL2_PLMASK_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL2_PLMASK_LO_CANFD0_PL2_PLMASK_LO_DATA_BYTE_1_SHFT;
    regValue |= Data << 16U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL2_PLMASK_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL2_PLMASK_LO.bits.DATA_BYTE_1, Data);
#endif
}

/*!
 * @brief 设置 Pretended Networking 滤波掩码byte2
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNLowPayLoadByte2Mask(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL2_PLMASK_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL2_PLMASK_LO_CANFD0_PL2_PLMASK_LO_DATA_BYTE_2_SHFT;
    regValue |= Data << 8U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL2_PLMASK_LO_ADDR, regValue);
    // TODO: check if correct
#else
    REG_WRITE(Module->CANFD_PL2_PLMASK_LO.bits.DATA_BYTE_2, Data);
#endif
}

/*!
 * @brief 设置 Pretended Networking 滤波掩码byte3
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNLowPayLoadByte3Mask(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL2_PLMASK_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL2_PLMASK_LO_CANFD0_PL2_PLMASK_LO_DATA_BYTE_3_SHFT;
    regValue |= Data << 0U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL2_PLMASK_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL2_PLMASK_LO.bits.DATA_BYTE_3, Data);
#endif
}

/*!
 * @brief 获取 Pretended Networking 滤波掩码byte4
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNHighPayLoadByte4Mask(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL2_PLMASK_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL2_PLMASK_HI_CANFD0_PL2_PLMASK_HI_DATA_BYTE_4_SHFT;
    regValue |= Data << 24U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL2_PLMASK_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL2_PLMASK_HI.bits.DATA_BYTE_4, Data);
#endif
}

/*!
 * @brief 获取 Pretended Networking 滤波掩码byte5
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNHighPayLoadByte5Mask(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL2_PLMASK_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL2_PLMASK_HI_CANFD0_PL2_PLMASK_HI_DATA_BYTE_5_SHFT;
    regValue |= Data << 16U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL2_PLMASK_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL2_PLMASK_HI.bits.DATA_BYTE_5, Data);
#endif
}

/*!
 * @brief 获取 Pretended Networking 滤波掩码byte6
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNHighPayLoadByte6Mask(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL2_PLMASK_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL2_PLMASK_HI_CANFD0_PL2_PLMASK_HI_DATA_BYTE_6_SHFT;
    regValue |= Data << 8U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL2_PLMASK_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL2_PLMASK_HI.bits.DATA_BYTE_6, Data);
#endif
}

/*!
 * @brief 获取 Pretended Networking 滤波掩码byte7
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
KF_INLINE void Canfd_LL_SetPNHighPayLoadByte7Mask(CanfdPtr Module, const uint8_t Data)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_PL2_PLMASK_LO_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_PL2_PLMASK_HI_CANFD0_PL2_PLMASK_HI_DATA_BYTE_7_SHFT;
    regValue |= Data << 0U;
    REG_WRITE(offsetAddr + HWIO_CANFD0_PL2_PLMASK_LO_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_PL2_PLMASK_HI.bits.DATA_BYTE_7, Data);
#endif
}

/*!
 * @brief 设置 TDC 生效状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] bool
 *            true:使能TDC功能
 *            false:禁止TDC功能
 * @return void
 */
KF_INLINE void Canfd_LL_SetTDCStatus(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_TDCEN_MASK;
    regValue |= Status << HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_TDCEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCTRL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCTRL.bits.TDCEN, Status);
#endif
}

/*!
 * @brief 设置 TDC 补偿值
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Offset 补偿偏移值
 * @return void
 */
KF_INLINE void Canfd_LL_SetTDCOffsetValue(CanfdPtr Module, const uint8_t Offset)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_FDCTRL_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_TDCOFF_MASK;
    regValue |= Offset << HWIO_CANFD0_FDCTRL_CANFD0_FDCTRL_TDCOFF_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_FDCTRL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_FDCTRL.bits.TDCOFF, Offset);
#endif
}

/**
 * @brief 设置CANFD错误纠正配置使能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param  bool
 *         true:使能错误纠正
 *         false:禁止错误纠正
 * @retval void
 */
KF_INLINE void Canfd_LL_ErrorCorrectConfigurateEnable(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CTRL2_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CTRL2_CANFD0_CTRL2_ECRWRE_MASK;
    regValue |= Status << HWIO_CANFD0_CTRL2_CANFD0_CTRL2_ECRWRE_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CTRL2_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CTRL2.bits.ECRWRE, Status);
#endif
}

/**
 * @brief 设置CANFD错误纠正配置使能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param  bool
 *         true:使能错误纠正
 *         false:禁止错误纠正
 * @retval void
 */
KF_INLINE void Canfd_LL_ErrorCorrectConfigurateWriteDisable(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MECR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MECR_CANFD0_MECR_ECRWRDIS_MASK;
    regValue |= Status << HWIO_CANFD0_MECR_CANFD0_MECR_ECRWRDIS_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MECR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MECR.bits.ECRWRDIS, Status);
#endif
}

/**
 * @brief 设置CANFD错误纠正配置使能
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param  bool
 *         true:使能错误纠正
 *         false:禁止错误纠正
 * @retval void
 */
KF_INLINE void Canfd_LL_ErrorCorrectInFreeze(CanfdPtr Module, const bool Status)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_MECR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_MECR_CANFD0_MECR_NCEFAFRZ_MASK;
    regValue |= Status << HWIO_CANFD0_MECR_CANFD0_MECR_NCEFAFRZ_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_MECR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_MECR.bits.NCEFAFRZ, Status);
#endif
}

/**
 * @brief 设置CANFD模块禁止请求位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] State 模块禁止请求位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Canfd_LL_DISR(CanfdPtr Module, const bool State)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CLKC_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CLKC_CANFD0_CLKC_DISR_MASK;
    regValue |= State << HWIO_CANFD0_CLKC_CANFD0_CLKC_DISR_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CLKC_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CLKC.bits.DISR, State);
#endif
}

/**
 * @brief 读取CANFD模块禁止状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return 模块禁止状态
 */
KF_INLINE uint32_t Canfd_LL_DISS(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CLKC_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_CLKC_CANFD0_CLKC_DISS_MASK;
    regValue = regValue >> HWIO_CANFD0_CLKC_CANFD0_CLKC_DISS_SHFT;
    return (regValue);
    // TODO: check if correct

#else
    return REG_READ(Module->CANFD_CLKC.bits.DISS);
#endif
}

/**
 * @brief 设置CANFD休眠模式使能控制位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] State 休眠模式使能控制位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Canfd_LL_EDIS(CanfdPtr Module, const bool State)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_CLKC_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_CLKC_CANFD0_CLKC_EDIS_MASK;
    regValue |= State << HWIO_CANFD0_CLKC_CANFD0_CLKC_EDIS_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_CLKC_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_CLKC.bits.EDIS, State);
#endif
}

/**
 * @brief 设置CANFDOCDS挂起控制位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] DBGCTLValue OCDS挂起控制位
 *            0H 不会被挂起
 *            1H 硬件挂起:时钟立即关闭，在该模式下，无法读取或写入寄存器，GTM控制寄存器不受影响。
 *            2H 软件挂起:在该模式下，可以读取或写入寄存器
 *            其他 预留位
 * @return void
 */
KF_INLINE void Canfd_LL_DBGCTL(CanfdPtr Module, Canfd_Dbg_Dbgctl_Id_t DBGCTLValue)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    KF_CANFD_ASSERT(CHECK_CANFD_DBG_DBGCTL_ID(DBGCTLValue));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_DBG_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_DBG_CANFD0_DBG_DBGCTL_MASK;
    regValue |= DBGCTLValue << HWIO_CANFD0_DBG_CANFD0_DBG_DBGCTL_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_DBG_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_DBG.bits.DBGCTL, DBGCTLValue);
#endif
}

/**
 * @brief 设置CANFDDBGCTL写保护
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] State DBGCTL写保护
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Canfd_LL_DBGP(CanfdPtr Module, const bool State)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_DBG_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_DBG_CANFD0_DBG_DBGP_MASK;
    regValue |= State << HWIO_CANFD0_DBG_CANFD0_DBG_DBGP_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_DBG_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_DBG.bits.DBGP, State);
#endif
}

/**
 * @brief 读取CANFD挂起状态位
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return 挂起状态位
 */
KF_INLINE uint32_t Canfd_LL_DBGSTA(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_DBG_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_DBG_CANFD0_DBG_DBGSTA_MASK;
    regValue = regValue >> HWIO_CANFD0_DBG_CANFD0_DBG_DBGSTA_SHFT;
    return (regValue);
    // TODO: check if correct

#else
    return REG_READ(Module->CANFD_DBG.bits.DBGSTA);
#endif
}

/**
 * @brief 设置CANFD模块复位请求位，与RST1寄存器的RST位一起使用
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] State 模块复位请求位，与RST1寄存器的RST位一起使用
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Canfd_LL_RST0(CanfdPtr Module, const bool State)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_RST0_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_RST0_CANFD0_RST0_RST_MASK;
    regValue |= State << HWIO_CANFD0_RST0_CANFD0_RST0_RST_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RST0_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_RST0.bits.RST, State);
#endif
}

/**
 * @brief 读取CANFD复位状态
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return 复位状态
 */
KF_INLINE uint32_t Canfd_LL_RSTSTA(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_RST0_ADDR + offsetAddr);
    regValue &= HWIO_CANFD0_RST0_CANFD0_RST0_RSTSTA_MASK;
    regValue = regValue >> HWIO_CANFD0_RST0_CANFD0_RST0_RSTSTA_SHFT;
    return (regValue);
    // TODO: check if correct

#else
    return REG_READ(Module->CANFD_RST0.bits.RSTSTA);
#endif
}

/**
 * @brief 设置CANFD模块复位请求位，与RST0寄存器的RST位一起使用
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] State 模块复位请求位，与RST0寄存器的RST位一起使用
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Canfd_LL_RST1(CanfdPtr Module, const bool State)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_RST1_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_RST1_CANFD0_RST1_RST_MASK;
    regValue |= State << HWIO_CANFD0_RST1_CANFD0_RST1_RST_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RST1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_RST1.bits.RST, State);
#endif
}

/**
 * @brief 设置CANFDRSTSTA复位状态清除，该位自动清零
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] State RSTSTA复位状态清除，该位自动清零
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Canfd_LL_CLR(CanfdPtr Module, const bool State)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~CANFD_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_CANFD0_RSTCLR_ADDR + offsetAddr);
    regValue &= ~HWIO_CANFD0_RSTCLR_CANFD0_RSTCLR_CLR_MASK;
    regValue |= State << HWIO_CANFD0_RSTCLR_CANFD0_RSTCLR_CLR_SHFT;
    REG_WRITE(offsetAddr + HWIO_CANFD0_RSTCLR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CANFD_RSTCLR.bits.CLR, State);
#endif
}

/**
 * @brief 设置CANFD使能MasterTAGIDn的事务对模块内核地址的写访问
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param  AccessEnable
 * @retval void
 */
KF_INLINE void Canfd_LL_EN0(CanfdPtr Module, Canfd_Aces0_En_Id_t AccessEnable)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ACES0_EN_ID(AccessEnable));
#ifdef SIMULATION
// TODO:
#else
    REG_BIT_SET(Module->CANFD_ACES0.reg, MASK_1_BIT << AccessEnable);
#endif
}

uint8_t            Canfd_LL_GetMaliboxNumber(const Canfd_PayloadSize_t PayloadSize);
uint8_t            Canfd_LL_GetDataLength(const uint8_t Dlc);
void               Canfd_LL_SwapBytesInWord(volatile void *DesPtr, volatile void *SouPtr);
void               Canfd_LL_EnterFreezeMode(CanfdPtr Module);
void               Canfd_LL_ExitFreezeMode(CanfdPtr Module);
void               Canfd_LL_Disable(CanfdPtr Module);
void               Canfd_LL_Enable(CanfdPtr Module);
void               Canfd_LL_SetPayloadSize(CanfdPtr Module, const Canfd_PayloadSize_t PayloadSize);
uint32_t           Canfd_LL_GetPayloadSize(CanfdPtr Module);
void               Canfd_LL_SetTimeSegments(CanfdPtr Module, const Canfd_TimeSegment_t *TimeSegPtr);
void               Canfd_LL_SetExtendedTimeSegments(CanfdPtr Module, const Canfd_TimeSegment_t *TimeSegPtr);
void               Canfd_LL_SetFDTimeSegments(CanfdPtr Module, const Canfd_TimeSegment_t *TimeSegPtr);
void               Canfd_LL_GetTimeSegments(CanfdPtr Module, Canfd_TimeSegment_t *BitRatePtr);
void               Canfd_LL_GetFDTimeSegments(CanfdPtr Module, Canfd_TimeSegment_t *BitRatePtr);
uint8_t            Canfd_LL_GetNoOfIndividualMB(CanfdPtr Module);
void               Canfd_LL_ClearErrIntStatusFlag(CanfdPtr Module);
void               Canfd_LL_SetPNIdFilter1(CanfdPtr Module, Canfd_PnIdFilter_t IdFilter);
void               Canfd_LL_SetPNIdFilter2Check(CanfdPtr Module);
void               Canfd_LL_SetPNIdFilter2(CanfdPtr Module, Canfd_PnIdFilter_t IdFilter);
void               Canfd_LL_SetPNDlcFilter(CanfdPtr Module, uint8_t DlcLow, uint8_t DlcHigh);
void               Canfd_LL_SetPNPayloadHighFilter1(CanfdPtr Module, const uint8_t *PayloadPtr);
void               Canfd_LL_SetPNPayloadLowFilter1(CanfdPtr Module, const uint8_t *PayloadPtr);
void               Canfd_LL_SetPNPayloadHighFilter2(CanfdPtr Module, const uint8_t *PayloadPtr);
void               Canfd_LL_SetPNPayloadLowFilter2(CanfdPtr Module, const uint8_t *PayloadPtr);
void               Canfd_LL_SetTDCOffset(CanfdPtr Module, const bool Status, uint8_t Offset);
void               Canfd_LL_Init(CanfdPtr Module);
kf_status_t        Canfd_LL_EnableRxFifo(CanfdPtr Module, uint32_t NumberOfFilters);
kf_status_t        Canfd_LL_WaitSemaphorephore(Semaphore_t *const SemaphorePtr, const uint32_t Timeout);
volatile uint32_t *Canfd_LL_GetMailboxAddr(CanfdPtr Module, uint32_t MbIndex);
kf_status_t        Canfd_LL_SetMaxMbNum(CanfdPtr Module, uint32_t MaxMbNum);
void               Canfd_LL_SetOperationMode(CanfdPtr Module, Canfd_OpMode_t Mode);
void               Canfd_LL_ClearMbIntrFlag(CanfdPtr Module, const uint32_t MbIndex);
bool               Canfd_LL_GetMbIntrFlag(CanfdPtr Module, const uint32_t MbIndex);
kf_status_t        Canfd_LL_SetMbIntr(CanfdPtr Module, const uint32_t MbIndex, const bool Status);
void               Canfd_LL_SetErrIntCmd(CanfdPtr Module, Canfd_Inttype_t ErrType, const bool Status);
void               Canfd_LL_AbortTxMb(CanfdPtr Module, uint32_t MbIndex);
kf_status_t
Canfd_LL_SetTxMb(CanfdPtr Module, uint32_t MbIndex, uint32_t Code, Canfd_PduInfo_t *PduInfoPtr, uint8_t *DataPtr);
kf_status_t Canfd_LL_SetRxMb(CanfdPtr Module, uint32_t MbIndex, uint32_t Code, const Canfd_PduInfo_t *PduInfoPtr);
void        Canfd_LL_ReadRxFifo(CanfdPtr Module, Canfd_MsgBuff_t *RxMsgPtr);
uint32_t    Canfd_LL_GetRxFifoMask(Canfd_IdType_t IdType, Canfd_RxFifoIdFormat_t FormatType, uint32_t Mask);
void        Canfd_LL_SetRxFifoFilter(
         CanfdPtr Module, Canfd_RxFifoIdFormat_t IdFormat, const Canfd_IdTable_t *IdFilterTablePtr);
kf_status_t Canfd_LL_GetMbData(CanfdPtr Module, const uint32_t MbIndex, Canfd_MsgBuff_t *RxMsgPtr);
void        Canfd_LL_LockRxMailBox(CanfdPtr Module, uint32_t MbIndex);
void        Canfd_LL_ResetRxMalibox(CanfdPtr Module, uint32_t MbIndex);
void        Canfd_LL_ConfigPN(CanfdPtr Module, const Canfd_PNConfig_t *PnConfigPtr);
#if FEATURE_CAN_HAS_MEM_ERR_DET
void Canfd_LL_DisableMemErrorDetection(CanfdPtr Module);
#endif

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
