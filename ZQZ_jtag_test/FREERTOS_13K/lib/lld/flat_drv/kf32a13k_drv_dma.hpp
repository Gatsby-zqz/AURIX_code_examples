/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_dma.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-25
 *  @Version         : V0.0.1.230625_alpha
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2024-03-19  |V1.0     |Hong Xu      |New creat
 *  |2024-03-20  |V1.1     |GaoBohua      |Add New API
 *****************************************************************************/
#ifndef KF32A13K_DRV_DMA_H_
#define KF32A13K_DRV_DMA_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                                             MISRA-C Rules Violations
 ******************************************************************************/

/******************************************************************************
 **                         QAC Warnings
 ******************************************************************************/

/******************************************************************************
 **                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_dma.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_DMA_ASSERT
#include "dev_assert.h"
#define KF_DMA_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DMA_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION
#define DMA_MODULE_BASE_ADDR DMA_ADDR
#include "kf32a13k_reg_simulation_dma.h"
#endif
/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/

/* dma addr check */
/* PRQA S 3456 1 */
#define CHECK_DMA_ALL_PERIPH_ADDR(PERIPH) (((PERIPH) == DMA_PTR))
/******************************************************************************
 **                      Typedef  Definitions
 ******************************************************************************/
/* 调试触发设置 */
typedef enum
{
    DMA_DEBUG_TRIGGER_NONE = 0U,
    DMA_DEBUG_TRIGGER_1    = 1U,
    DMA_DEBUG_TRIGGER_2    = 2U,
    DMA_DEBUG_TRIGGER_8    = 8U,
    DMA_DEBUG_TRIGGER_9    = 9U,
    DMA_DEBUG_TRIGGER_10   = 10U,
    DMA_DEBUG_TRIGGER_11   = 11U,
    DMA_DEBUG_TRIGGER_12   = 12U,
    DMA_DEBUG_TRIGGER_13   = 13U,
    DMA_DEBUG_TRIGGER_14   = 14U,
    DMA_DEBUG_TRIGGER_15   = 15U,
} Dma_DebugTrigger_t;
#define CHECK_DMA_DEBUG_TRIGGER(TRIGGER)                                                                               \
    ((TRIGGER == DMA_DEBUG_TRIGGER_NONE) || (TRIGGER == DMA_DEBUG_TRIGGER_1) || (TRIGGER == DMA_DEBUG_TRIGGER_2) ||    \
     (TRIGGER == DMA_DEBUG_TRIGGER_8) || (TRIGGER == DMA_DEBUG_TRIGGER_9) || (TRIGGER == DMA_DEBUG_TRIGGER_10) ||      \
     (TRIGGER == DMA_DEBUG_TRIGGER_11) || (TRIGGER == DMA_DEBUG_TRIGGER_12) || (TRIGGER == DMA_DEBUG_TRIGGER_13) ||    \
     (TRIGGER == DMA_DEBUG_TRIGGER_14) || (TRIGGER == DMA_DEBUG_TRIGGER_15))

/* 调试OTGB总线选择 */
typedef enum
{
    DMA_DEBUG_OUTPUT_OTGB0,
    DMA_DEBUG_OUTPUT_OTGB1,
} Dma_DebugOutput_t;
#define CHECK_DMA_DEBUG_OUTPUT(SELECT) ((SELECT == DMA_DEBUG_OUTPUT_OTGB0) || (SELECT == DMA_DEBUG_OUTPUT_OTGB1))

/* 数据对照寄存器索引 */
typedef enum
{
    DMA_PRR_0,
    DMA_PRR_1,
} Dma_PatternRegIndex_t;
#define CHECK_DMA_PATTERN_REG_INDEX(INDEX) ((INDEX == DMA_PRR_0) || (INDEX == DMA_PRR_1))

/* 数据对照字节索引 */
typedef enum
{
    DMA_PATTERN_BYTE_0,
    DMA_PATTERN_BYTE_1,
    DMA_PATTERN_BYTE_2,
    DMA_PATTERN_BYTE_3,
} Dma_PatternByte_t;
#define CHECK_DMA_PATTERN_Byte(Byte)                                                                                   \
    ((Byte == DMA_PATTERN_BYTE_0) || (Byte == DMA_PATTERN_BYTE_1) || (Byte == DMA_PATTERN_BYTE_2) ||                   \
     (Byte == DMA_PATTERN_BYTE_3))

/* 访问组索引 */
typedef enum
{
    DMA_ACCESS_GROUP_INDEX_0,
    DMA_ACCESS_GROUP_INDEX_1,
    DMA_ACCESS_GROUP_INDEX_2,
    DMA_ACCESS_GROUP_INDEX_3,
} Dma_AccessGroupIndex_t;
#define CHECK_DMA_ACCESS_GROUP_INDEX(INDEX)                                                                            \
    ((INDEX == DMA_ACCESS_GROUP_INDEX_0) || (INDEX == DMA_ACCESS_GROUP_INDEX_1) ||                                     \
     (INDEX == DMA_ACCESS_GROUP_INDEX_2) || (INDEX == DMA_ACCESS_GROUP_INDEX_3))

/* 主机标签号索引 */
typedef enum
{
    DMA_MASTER_TAG_INDEX_0,
    DMA_MASTER_TAG_INDEX_1,
    DMA_MASTER_TAG_INDEX_2,
    DMA_MASTER_TAG_INDEX_3,
    DMA_MASTER_TAG_INDEX_4,
    DMA_MASTER_TAG_INDEX_5,
    DMA_MASTER_TAG_INDEX_6,
    DMA_MASTER_TAG_INDEX_7,
    DMA_MASTER_TAG_INDEX_8,
    DMA_MASTER_TAG_INDEX_9,
    DMA_MASTER_TAG_INDEX_10,
    DMA_MASTER_TAG_INDEX_11,
    DMA_MASTER_TAG_INDEX_12,
    DMA_MASTER_TAG_INDEX_13,
    DMA_MASTER_TAG_INDEX_14,
    DMA_MASTER_TAG_INDEX_15,
    DMA_MASTER_TAG_INDEX_16,
    DMA_MASTER_TAG_INDEX_17,
    DMA_MASTER_TAG_INDEX_18,
    DMA_MASTER_TAG_INDEX_19,
    DMA_MASTER_TAG_INDEX_20,
    DMA_MASTER_TAG_INDEX_21,
    DMA_MASTER_TAG_INDEX_22,
    DMA_MASTER_TAG_INDEX_23,
    DMA_MASTER_TAG_INDEX_24,
    DMA_MASTER_TAG_INDEX_25,
    DMA_MASTER_TAG_INDEX_26,
    DMA_MASTER_TAG_INDEX_27,
    DMA_MASTER_TAG_INDEX_28,
    DMA_MASTER_TAG_INDEX_29,
    DMA_MASTER_TAG_INDEX_30,
    DMA_MASTER_TAG_INDEX_31,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_MASTER_TAG_INDEX_MAX,
} Dma_MasterTagIndex_t;
#define CHECK_DMA_MASTER_TAG_INDEX(INDEX) (INDEX < DMA_MASTER_TAG_INDEX_MAX)

/* 搬运引擎索引 */
typedef enum
{
    DMA_MOVE_ENGINE_INDEX_0,
    DMA_MOVE_ENGINE_INDEX_1,
} Dma_MoveEngineIndex_t;
#define CHECK_DMA_MOVE_ENGINE_INDEX(INDEX) ((INDEX == DMA_MOVE_ENGINE_INDEX_0) || (INDEX == DMA_MOVE_ENGINE_INDEX_1))

/* 搬运引擎搬运数据读取寄存器索引 */
typedef enum
{
    DMA_DATA_READ_REG_INDEX_0,
    DMA_DATA_READ_REG_INDEX_1,
    DMA_DATA_READ_REG_INDEX_2,
    DMA_DATA_READ_REG_INDEX_3,
    DMA_DATA_READ_REG_INDEX_4,
    DMA_DATA_READ_REG_INDEX_5,
    DMA_DATA_READ_REG_INDEX_6,
    DMA_DATA_READ_REG_INDEX_7,
    DMA_DATA_READ_REG_INDEX_8,
    DMA_DATA_READ_REG_INDEX_9,
    DMA_DATA_READ_REG_INDEX_10,
    DMA_DATA_READ_REG_INDEX_11,
    DMA_DATA_READ_REG_INDEX_12,
    DMA_DATA_READ_REG_INDEX_13,
    DMA_DATA_READ_REG_INDEX_14,
    DMA_DATA_READ_REG_INDEX_15,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_DATA_READ_REG_INDEX_MAX,
} Dma_DataReadRegIndex_t;
#define CHECK_DMA_DATA_READ_REG_INDEX(INDEX) (INDEX < DMA_DATA_READ_REG_INDEX_MAX)

/* 搬运引擎搬运读取字节索引 */
typedef enum
{
    DMA_DATA_READ_BYTE_INDEX_0,
    DMA_DATA_READ_BYTE_INDEX_1,
    DMA_DATA_READ_BYTE_INDEX_2,
    DMA_DATA_READ_BYTE_INDEX_3,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_DATA_READ_BYTE_INDEX_MAX,
} Dma_DataReadByteIndex_t;
#define CHECK_DMA_DATA_READ_BYTE_INDEX(INDEX) (INDEX < DMA_DATA_READ_BYTE_INDEX_MAX)

/* DMA通道索引 */
typedef enum
{
    DMA_CHANNEL_0,
    DMA_CHANNEL_1,
    DMA_CHANNEL_2,
    DMA_CHANNEL_3,
    DMA_CHANNEL_4,
    DMA_CHANNEL_5,
    DMA_CHANNEL_6,
    DMA_CHANNEL_7,
    DMA_CHANNEL_8,
    DMA_CHANNEL_9,
    DMA_CHANNEL_10,
    DMA_CHANNEL_11,
    DMA_CHANNEL_12,
    DMA_CHANNEL_13,
    DMA_CHANNEL_14,
    DMA_CHANNEL_15,
    DMA_CHANNEL_16,
    DMA_CHANNEL_17,
    DMA_CHANNEL_18,
    DMA_CHANNEL_19,
    DMA_CHANNEL_20,
    DMA_CHANNEL_21,
    DMA_CHANNEL_22,
    DMA_CHANNEL_23,
    DMA_CHANNEL_24,
    DMA_CHANNEL_25,
    DMA_CHANNEL_26,
    DMA_CHANNEL_27,
    DMA_CHANNEL_28,
    DMA_CHANNEL_29,
    DMA_CHANNEL_30,
    DMA_CHANNEL_31,
    DMA_CHANNEL_32,
    DMA_CHANNEL_33,
    DMA_CHANNEL_34,
    DMA_CHANNEL_35,
    DMA_CHANNEL_36,
    DMA_CHANNEL_37,
    DMA_CHANNEL_38,
    DMA_CHANNEL_39,
    DMA_CHANNEL_40,
    DMA_CHANNEL_41,
    DMA_CHANNEL_42,
    DMA_CHANNEL_43,
    DMA_CHANNEL_44,
    DMA_CHANNEL_45,
    DMA_CHANNEL_46,
    DMA_CHANNEL_47,
    DMA_CHANNEL_48,
    DMA_CHANNEL_49,
    DMA_CHANNEL_50,
    DMA_CHANNEL_51,
    DMA_CHANNEL_52,
    DMA_CHANNEL_53,
    DMA_CHANNEL_54,
    DMA_CHANNEL_55,
    DMA_CHANNEL_56,
    DMA_CHANNEL_57,
    DMA_CHANNEL_58,
    DMA_CHANNEL_59,
    DMA_CHANNEL_60,
    DMA_CHANNEL_61,
    DMA_CHANNEL_62,
    DMA_CHANNEL_63,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_CHANNEL_MAX,
} Dma_ChannelIndex_t;
#define CHECK_DMA_CHANNEL_INDEX(x) ((x) < DMA_CHANNEL_MAX)

/** 数据块传输模式，每次transfer包含n次move */
typedef enum
{
    DMA_BLOCK_MODE_MOVE_1,
    DMA_BLOCK_MODE_MOVE_2,
    DMA_BLOCK_MODE_MOVE_4,
    DMA_BLOCK_MODE_MOVE_8,
    DMA_BLOCK_MODE_MOVE_16,
    DMA_BLOCK_MODE_MOVE_3,
    DMA_BLOCK_MODE_MOVE_5,
    DMA_BLOCK_MODE_MOVE_9,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_BLOCK_MODE_MOVE_MAX,
} Dma_BlockMode_t;
#define CHECK_DMA_BLOCK_MODE(x) ((x) < DMA_BLOCK_MODE_MOVE_MAX)

/** 数据宽度,单次搬运数据量 */
typedef enum
{
    DMA_CHANNEL_DATA_WIDTH_8,
    DMA_CHANNEL_DATA_WIDTH_16,
    DMA_CHANNEL_DATA_WIDTH_32,
    DMA_CHANNEL_DATA_WIDTH_64,
    DMA_CHANNEL_DATA_WIDTH_128,
    DMA_CHANNEL_DATA_WIDTH_256,
    DMA_CHANNEL_DATA_WIDTH_512,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_CHANNEL_DATA_WIDTH_MAX,
} Dma_ChannelDataWidth_t;
#define CHECK_DMA_CHANNEL_DATA_WIDTH(x) ((x) < DMA_CHANNEL_DATA_WIDTH_MAX)

/** 数据对照模式 */
typedef enum
{
    DMA_PATTERN_NONE,
    DMA_PATTERN_WITH_PRR0_PAT00,
    DMA_PATTERN_WITH_PRR0_PAT01,
    DMA_PATTERN_WITH_PRR0_BOTH,
    DMA_PATTERN_WITH_NONE,
    DMA_PATTERN_WITH_PRR1_PAT00,
    DMA_PATTERN_WITH_PRR1_PAT01,
    DMA_PATTERN_WITH_PRR1_BOTH,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_PATTERN_WITH_MAX,
} Dma_PatternMode_t;
#define CHECK_DMA_PATTERN_MODE(x) ((x) < DMA_PATTERN_WITH_MAX)

/** 数据CRC字节序交换 */
typedef enum
{
    DMA_REVERSE_CTRL_NONE,
    DMA_REVERSE_CTRL_BYTE,
} Dma_ReverseCtrl_t;
#define CHECK_DMA_REVERSE_CTRL(x) (((x) == DMA_REVERSE_CTRL_NONE) || ((x) == DMA_REVERSE_CTRL_BYTE))

/** 外设请求选择 */
typedef enum
{
    DMA_REQUEST_SRC_HARDWARE,
    DMA_REQUEST_SRC_DAISY_CHAIN,
} Dma_ReqSrc_t;
#define CHECK_DMA_REQUEST_SRC(x) (((x) == DMA_REQUEST_SRC_HARDWARE) || ((x) == DMA_REQUEST_SRC_DAISY_CHAIN))

/** 通道操作模式选择 */
typedef enum
{
    DMA_CHANNEL_OPERATION_MODE_ONCE,
    DMA_CHANNEL_OPERATION_MODE_CONTINUOUS,
} Dma_ChannelOperationMode_t;
#define CHECK_DMA_CHANNEL_OPERATION_MODE(x)                                                                            \
    (((x) == DMA_CHANNEL_OPERATION_MODE_ONCE) || ((x) == DMA_CHANNEL_OPERATION_MODE_CONTINUOUS))

/** 中断控制 */
typedef enum
{
    DMA_INTR_CTRL_NO_INTR_BUT_EQUAL,
    DMA_INTR_CTRL_NO_INTR_BUT_DECREASE,
    DMA_INTR_CTRL_THRESHOLD_MATCH,
    DMA_INTR_CTRL_EVERY_DECREMENT,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_INTR_CTRL_MAX,
} Dma_IntrCtrl_t;
#define CHECK_DMA_INTR_CTRL(x) ((x) < DMA_INTR_CTRL_MAX)

/** 影子控制 */
typedef enum
{
    DMA_SHADOW_CTRL_MOVE_OPERATION = 0U,
    /* 源地址只读模式的影子操作 */
    DMA_SHADOW_CTRL_READ_ONLY_SRC_ADDR = 1U,
    /* 目标地址只读模式的影子操作 */
    DMA_SHADOW_CTRL_READ_ONLY_DEST_ADDR = 2U,
    /* 源地址直写模式的影子操作 */
    DMA_SHADOW_CTRL_DIRECT_WRITE_SRC_ADDR = 5U,
    /* 目标地址直写模式的影子操作 */
    DMA_SHADOW_CTRL_DIRECT_WRITE_DEST_ADDR = 6U,
    /* 仅软件切换的 DMA 双源缓冲区 */
    DMA_SHADOW_CTRL_DOUBLE_SRC_WITH_SOFTWARE_SWITCH = 8U,
    /* 软件可切换与自动硬件切换的 DMA 双源缓冲区 */
    DMA_SHADOW_CTRL_DOUBLE_SRC_WITH_SOFTWARE_HARDWARE = 9U,
    /* 仅软件切换的 DMA 双目标缓冲区 */
    DMA_SHADOW_CTRL_DOUBLE_DEST_WITH_SOFTWARE_SWITCH = 10U,
    /* 软件可切换与自动硬件切换的 DMA 双目标缓冲区 */
    DMA_SHADOW_CTRL_DOUBLE_DEST_WITH_SOFTWARE_HARDWARE = 11U,
    /* DMA 链表 */
    DMA_SHADOW_CTRL_DMA_LINKED_LIST = 12U,
    /* 累加链表 */
    DMA_SHADOW_CTRL_ACCUMULATED_LINKED_LIST = 13U,
    /* 安全链表 */
    DMA_SHADOW_CTRL_SAFE_LINKED_LIST = 14U,
    /* 条件链表 */
    DMA_SHADOW_CTRL_CONDITIONAL_LINKED_LIST = 15U,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_SHADOW_CTRL_MAX,
} Dma_ShadowCtrl_t;
#define CHECK_DMA_SHADOW_CTRL(x) (((x) < DMA_SHADOW_CTRL_MAX) && ((x) != 3U) && ((x) != 4U) && ((x) != 7U))

/** 循环Buffer长度 */
typedef enum
{
    /* 地址固定 */
    DMA_CIRCULAR_BUFFER_NONE,
    /* 地址高[32:1]位固定 */
    DMA_CIRCULAR_BUFFER_2,
    /* 地址高[32:2]位固定 */
    DMA_CIRCULAR_BUFFER_4,
    /* 地址高[32:3]位固定 */
    DMA_CIRCULAR_BUFFER_8,
    /* 地址高[32:4]位固定 */
    DMA_CIRCULAR_BUFFER_16,
    /* 地址高[32:5]位固定 */
    DMA_CIRCULAR_BUFFER_32,
    /* 地址高[32:6]位固定 */
    DMA_CIRCULAR_BUFFER_64,
    /* 地址高[32:7]位固定 */
    DMA_CIRCULAR_BUFFER_128,
    /* 地址高[32:8]位固定 */
    DMA_CIRCULAR_BUFFER_256,
    /* 地址高[32:9]位固定 */
    DMA_CIRCULAR_BUFFER_512,
    /* 地址高[32:10]位固定 */
    DMA_CIRCULAR_BUFFER_1024,
    /* 地址高[32:11]位固定 */
    DMA_CIRCULAR_BUFFER_2048,
    /* 地址高[32:12]位固定 */
    DMA_CIRCULAR_BUFFER_4096,
    /* 地址高[32:13]位固定 */
    DMA_CIRCULAR_BUFFER_8192,
    /* 地址高[32:14]位固定 */
    DMA_CIRCULAR_BUFFER_16384,
    /* 地址高[32:15]位固定 */
    DMA_CIRCULAR_BUFFER_32768,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_CIRCULAR_BUFFER_MAX,
} Dma_CircularBuffer_t;
#define CHECK_DMA_CIRCULAR_BUFFER(x) ((x) < DMA_CIRCULAR_BUFFER_MAX)

/** 地址偏移方向 */
typedef enum
{
    /* 地址逐渐减小 */
    DMA_ADDR_OFFSET_DIR_SUBTRACT,
    /* 地址逐渐增大 */
    DMA_ADDR_OFFSET_DIR_ADD,
} Dma_AddrOffsetDir_t;
#define CHECK_DMA_ADDR_OFFSET_DIR(x) (((x) == DMA_ADDR_OFFSET_DIR_SUBTRACT) || ((x) == DMA_ADDR_OFFSET_DIR_ADD))

/** 地址偏移量，1次偏移增加\减小n个数据宽度 */
typedef enum
{
    /* 地址偏移1倍的数据宽度 */
    DMA_ADDR_OFFSET_STEP_1,
    /* 地址偏移2倍的数据宽度 */
    DMA_ADDR_OFFSET_STEP_2,
    /* 地址偏移4倍的数据宽度 */
    DMA_ADDR_OFFSET_STEP_4,
    /* 地址偏移8倍的数据宽度 */
    DMA_ADDR_OFFSET_STEP_8,
    /* 地址偏移16倍的数据宽度 */
    DMA_ADDR_OFFSET_STEP_16,
    /* 地址偏移32倍的数据宽度 */
    DMA_ADDR_OFFSET_STEP_32,
    /* 地址偏移64倍的数据宽度 */
    DMA_ADDR_OFFSET_STEP_64,
    /* 地址偏移128倍的数据宽度 */
    DMA_ADDR_OFFSET_STEP_128,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_ADDR_OFFSET_STEP_MAX,
} Dma_AddrOffsetStep_t;
#define CHECK_DMA_ADDR_OFFSET_STEP(x) ((x) < DMA_ADDR_OFFSET_STEP_MAX)

/** 访问组管理模式 */
typedef enum
{
    DMA_GROUP_SUPERVISOR_MODE_USER,
    DMA_GROUP_SUPERVISOR_MODE_SUPERVISOR,
    /* No practical meaning, used as an input parameter for detection. */
    DMA_GROUP_SUPERVISOR_MODE_MAX,
} Dma_GroupSupervisorMode_t;
#define CHECK_DMA_GROUP_SUPERVISOR_MODE(x) ((x) < DMA_GROUP_SUPERVISOR_MODE_MAX)

/** 搬运引擎错误中断使能索引 */
typedef enum
{
    DMA_ERROR_INTR_SEIE   = (1U << 16U),
    DMA_ERROR_INTR_DEIE   = (1U << 17U),
    DMA_ERROR_INTR_DLLEIE = (1U << 26U),
} Dma_ErrorIntrEnableMask_t;

/** 搬运引擎错误中断标志、清除索引 */
typedef enum
{
    DMA_STATE_SE    = (1U << 16U),
    DMA_STATE_DE    = (1U << 17U),
    DMA_STATE_PERIE = (1U << 20U),
    DMA_STATE_SYSE  = (1U << 21U),
    DMA_STATE_RAME  = (1U << 24U),
    DMA_STATE_SLLE  = (1U << 25U),
    DMA_STATE_DLLE  = (1U << 26U),
} Dma_ErrorIntrMask_t;

/* 传输重载值 */
#define CHECK_DMA_TRANSFER_RELOAD_VALUE(x) (!((uint32_t)x >> 14U))

/*  CHSR.TCOUNT上升阈值 */
#define CHECK_DMA_INTR_RAISE_DETECT_VALUE(x) (!((uint8_t)x >> 4U))

/******************************************************************************
 *                       Export Functions
 ******************************************************************************/

/**
 * @brief Dma模块使能/禁止
 *
 * @param State 使能/禁止状态
 *          false   申请使能Dma
 *          true   申请禁用Dma
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetModuleEnabled(bool State)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_DMA_CLKC_ADDR);
    regValue &= ~HWIO_DMA_CLKC_DMA_CLKC_DISR_MASK;
    regValue |= State << HWIO_DMA_CLKC_DMA_CLKC_DISR_SHFT;
    REG_WRITE(HWIO_DMA_CLKC_ADDR, regValue);
#else
    REG_WRITE(DMA_PTR->CLKC.bits.DISR, State);
#endif
}

/**
 * @brief 获取Dma模块使能/禁止
 *
 * @param void
 *
 * @return bool
 * @retval false Dma已使能
 *         true Dma已禁用
 */
KF_INLINE bool DMA_LL_GetModuleState(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_DMA_CLKC_ADDR);
    regValue &= HWIO_DMA_CLKC_DMA_CLKC_DISS_MASK;
    regValue = regValue >> HWIO_DMA_CLKC_DMA_CLKC_DISS_SHFT;

    return ((regValue));
#else
    return ((bool)(REG_READ(DMA_PTR->CLKC.bits.DISS)));
#endif
}

/**
 * @brief Dma设置休眠模式
 *
 * @param State
 *          false   Dma使能休眠模式
 *          true   Dma禁用休眠模式
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetSleepModeEnabled(bool State)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_DMA_CLKC_ADDR);
    regValue &= ~HWIO_DMA_CLKC_DMA_CLKC_EDIS_MASK;
    regValue |= State << HWIO_DMA_CLKC_DMA_CLKC_EDIS_SHFT;
    REG_WRITE(HWIO_DMA_CLKC_ADDR, regValue);
#else
    REG_WRITE(DMA_PTR->CLKC.bits.EDIS, State);
#endif
}

/**
 * @brief Dma获取模块版本号
 *
 * @param void
 *
 * @return uint32_t 模块版本号
 */
KF_INLINE uint32_t DMA_LL_GetModuleVersion(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_DMA_INFO_ADDR);
    regValue &= HWIO_DMA_INFO_DMA_INFO_MODREV_MASK;
    regValue = regValue >> HWIO_DMA_INFO_DMA_INFO_MODREV_SHFT;

    return ((regValue));
#else
    return ((uint32_t)(REG_READ(DMA_PTR->INFO.bits.MODREV)));
#endif
}

/**
 * @brief Dma获取模块类型
 *
 * @param void
 *
 * @return uint32_t 模块类型
 */
KF_INLINE uint32_t DMA_LL_GetModuleType(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_DMA_INFO_ADDR);
    regValue &= HWIO_DMA_INFO_DMA_INFO_MODTYPE_MASK;
    regValue = regValue >> HWIO_DMA_INFO_DMA_INFO_MODTYPE_SHFT;

    return ((regValue));
#else
    return ((uint32_t)(REG_READ(DMA_PTR->INFO.bits.MODTYPE)));
#endif
}

/**
 * @brief Dma获取模块编号
 *
 * @param void
 *
 * @return uint32_t 模块编号
 */
KF_INLINE uint32_t DMA_LL_GetModuleNumber(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_DMA_INFO_ADDR);
    regValue &= HWIO_DMA_INFO_DMA_INFO_HSEMODESEL_MASK;
    regValue = regValue >> HWIO_DMA_INFO_DMA_INFO_HSEMODESEL_SHFT;

    return ((regValue));
#else
    return ((uint32_t)(REG_READ(DMA_PTR->INFO.bits.MODNUM)));
#endif
}

/**
 * @brief Debug触发设置
 *
 * @param Trigger 选择触发设置
 *          DMA_DEBUG_TRIGGER_NONE 未选择触发设置
 *          DMA_DEBUG_TRIGGER_1
 *          DMA_DEBUG_TRIGGER_2
 *          DMA_DEBUG_TRIGGER_8
 *          DMA_DEBUG_TRIGGER_9
 *          DMA_DEBUG_TRIGGER_10
 *          DMA_DEBUG_TRIGGER_11
 *          DMA_DEBUG_TRIGGER_12
 *          DMA_DEBUG_TRIGGER_13
 *          DMA_DEBUG_TRIGGER_14
 *          DMA_DEBUG_TRIGGER_15
 *
 * @return void
 */
KF_INLINE void DMA_LL_SelectDebugTriggerSrc(Dma_DebugTrigger_t Trigger)
{
    KF_DMA_ASSERT(CHECK_DMA_DEBUG_TRIGGER(Trigger));

#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_DMA_DBG_ADDR);
    regValue &= ~HWIO_DMA_DBG_DMA_DBG_TGS_MASK;
    regValue |= Trigger << HWIO_DMA_DBG_DMA_DBG_TGS_SHFT;
    REG_WRITE(HWIO_DMA_DBG_ADDR, regValue);
#else
    REG_WRITE(DMA_PTR->DBG.bits.TGS, Trigger);
#endif
}

/**
 * @brief OTGB0/1总线选择
 *
 * @param Select OTGB总线选择
 *          DMA_DEBUG_OUTPUT_OTGB0 触发设置输出到OTGB0
 *          DMA_DEBUG_OUTPUT_OTGB1 触发设置输出到OTGB1
 *
 * @return void
 */
KF_INLINE void DMA_LL_SelectDebugOutput(Dma_DebugOutput_t Select)
{
    KF_DMA_ASSERT(CHECK_DMA_DEBUG_OUTPUT(Select));

#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_DMA_DBG_ADDR);
    regValue &= ~HWIO_DMA_DBG_DMA_DBG_BS_MASK;
    regValue |= Select << HWIO_DMA_DBG_DMA_DBG_BS_SHFT;
    REG_WRITE(HWIO_DMA_DBG_ADDR, regValue);
#else
    REG_WRITE(DMA_PTR->DBG.bits.BS, Select);
#endif
}

/**
 * @brief 单字节方式设置DMA对照数据
 *
 * @param RegIndex 选择数据对照寄存器
 *          DMA_PRR_0 数据对照寄存器0
 *          DMA_PRR_1 数据对照寄存器1
 * @param Byte 数据对照字节索引
 *          DMA_PATTERN_BYTE_0 数据对照字节索引0
 *          DMA_PATTERN_BYTE_1 数据对照字节索引1
 *          DMA_PATTERN_BYTE_2 数据对照字节索引2
 *          DMA_PATTERN_BYTE_3 数据对照字节索引3
 * @param Data 对照数据
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetDataPatternByte(Dma_PatternRegIndex_t RegIndex, Dma_PatternByte_t Byte, uint8_t Data)
{
    KF_DMA_ASSERT(CHECK_DMA_PATTERN_REG_INDEX(RegIndex));
    KF_DMA_ASSERT(CHECK_DMA_PATTERN_Byte(Byte));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_PRR_0 == RegIndex)
    {
        regValue = REG_READ(HWIO_DMA_PRR0_ADDR);
        if (DMA_PATTERN_BYTE_0 == Byte)
        {
            regValue &= ~HWIO_DMA_PRR0_DMA_PRR0_PRT00_MASK;
            regValue |= Data << HWIO_DMA_PRR0_DMA_PRR0_PRT00_SHFT;
        }
        else if (DMA_PATTERN_BYTE_1 == Byte)
        {
            regValue &= ~HWIO_DMA_PRR0_DMA_PRR0_PRT01_MASK;
            regValue |= Data << HWIO_DMA_PRR0_DMA_PRR0_PRT01_SHFT;
        }
        else if (DMA_PATTERN_BYTE_2 == Byte)
        {
            regValue &= ~HWIO_DMA_PRR0_DMA_PRR0_PRT02_MASK;
            regValue |= Data << HWIO_DMA_PRR0_DMA_PRR0_PRT02_SHFT;
        }
        else
        {
            regValue &= ~HWIO_DMA_PRR0_DMA_PRR0_PRT03_MASK;
            regValue |= Data << HWIO_DMA_PRR0_DMA_PRR0_PRT03_SHFT;
        }
        REG_WRITE(HWIO_DMA_PRR0_ADDR, regValue);
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_PRR1_ADDR);
        if (DMA_PATTERN_BYTE_0 == Byte)
        {
            regValue &= ~HWIO_DMA_PRR1_DMA_PRR1_PRT11_MASK;
            regValue |= Data << HWIO_DMA_PRR1_DMA_PRR1_PRT11_SHFT;
        }
        else if (DMA_PATTERN_BYTE_1 == Byte)
        {
            regValue &= ~HWIO_DMA_PRR1_DMA_PRR1_PRT12_MASK;
            regValue |= Data << HWIO_DMA_PRR1_DMA_PRR1_PRT12_SHFT;
        }
        else if (DMA_PATTERN_BYTE_2 == Byte)
        {
            regValue &= ~HWIO_DMA_PRR1_DMA_PRR1_PRT12_MASK;
            regValue |= Data << HWIO_DMA_PRR1_DMA_PRR1_PRT12_SHFT;
        }
        else
        {
            regValue &= ~HWIO_DMA_PRR1_DMA_PRR1_PRT13_MASK;
            regValue |= Data << HWIO_DMA_PRR1_DMA_PRR1_PRT13_SHFT;
        }
        REG_WRITE(HWIO_DMA_PRR1_ADDR, regValue);
    }
#else
    uint32_t Mask;
    uint32_t Value;

    Mask  = (uint32_t)0xFFU << (8U * Byte);
    Value = (uint32_t)Data << (8U * Byte);

    if (DMA_PRR_0 == RegIndex)
    {
        REG_BITS_WRITE(DMA_PTR->PRR[0].reg, Mask, Value);
    }
    else
    {
        REG_BITS_WRITE(DMA_PTR->PRR[1].reg, Mask, Value);
    }
#endif
}

/**
 * @brief 整字方式设置DMA对照数据
 *
 * @param RegIndex 选择数据对照寄存器
 *          DMA_PRR_0 数据对照寄存器0
 *          DMA_PRR_1 数据对照寄存器1
 * @param Data 对照数据(整字)
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetDataPatternWord(Dma_PatternRegIndex_t RegIndex, uint32_t Data)
{
    KF_DMA_ASSERT(CHECK_DMA_PATTERN_REG_INDEX(RegIndex));

#ifdef SIMULATION
    if (DMA_PRR_0 == RegIndex)
    {
        REG_WRITE(HWIO_DMA_PRR0_ADDR, Data);
    }
    else
    {
        REG_WRITE(HWIO_DMA_PRR1_ADDR, Data);
    }
#else
    if (DMA_PRR_0 == RegIndex)
    {
        REG_WRITE(DMA_PTR->PRR[0].reg, Data);
    }
    else
    {
        REG_WRITE(DMA_PTR->PRR[1].reg, Data);
    }
#endif
}

/**
 * @brief 获取DMA时间戳计数
 *
 * @param void
 *
 * @return uint32_t 时间戳计数值
 */
KF_INLINE uint32_t DMA_LL_GetTimeStampCounter(void)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_DMA_TIME_ADDR);
    regValue &= HWIO_DMA_TIME_DMA_TIME_CNT_MASK;
    regValue = regValue >> HWIO_DMA_TIME_DMA_TIME_CNT_SHFT;

    return ((regValue));
#else
    return ((uint32_t)(REG_READ(DMA_PTR->TIME.bits.CNT)));
#endif
}

/**
 * @brief 设置访问组的管理模式.
 *
 * @param Group 访问组索引
 * @param Mode 访问组管理模式
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetGroupSupervisorMode(Dma_AccessGroupIndex_t Group, Dma_GroupSupervisorMode_t Mode)
{
    KF_DMA_ASSERT(CHECK_DMA_ACCESS_GROUP_INDEX(Group));
    KF_DMA_ASSERT(CHECK_DMA_GROUP_SUPERVISOR_MODE(Mode));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_ACCESS_GROUP_INDEX_0 == Group)
    {
        regValue = REG_READ(HWIO_DMA_MOD0_ADDR);
        regValue &= ~HWIO_DMA_MOD0_DMA_MOD0_MOD_MASK;
        regValue |= Mode << HWIO_DMA_MOD0_DMA_MOD0_MOD_SHFT;
        REG_WRITE(HWIO_DMA_MOD0_ADDR, regValue);
    }
    else if (DMA_ACCESS_GROUP_INDEX_1 == Group)
    {
        regValue = REG_READ(HWIO_DMA_MOD1_ADDR);
        regValue &= ~HWIO_DMA_MOD1_DMA_MOD1_MOD_MASK;
        regValue |= Mode << HWIO_DMA_MOD1_DMA_MOD1_MOD_SHFT;
        REG_WRITE(HWIO_DMA_MOD1_ADDR, regValue);
    }
    else if (DMA_ACCESS_GROUP_INDEX_2 == Group)
    {
        regValue = REG_READ(HWIO_DMA_MOD2_ADDR);
        regValue &= ~HWIO_DMA_MOD2_DMA_MOD2_MOD_MASK;
        regValue |= Mode << HWIO_DMA_MOD2_DMA_MOD2_MOD_SHFT;
        REG_WRITE(HWIO_DMA_MOD2_ADDR, regValue);
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_MOD3_ADDR);
        regValue &= ~HWIO_DMA_MOD3_DMA_MOD3_MOD_MASK;
        regValue |= Mode << HWIO_DMA_MOD3_DMA_MOD3_MOD_SHFT;
        REG_WRITE(HWIO_DMA_MOD3_ADDR, regValue);
    }
#else
    REG_WRITE(DMA_PTR->MOD[Group].bits.MOD, Mode);
#endif
}

/**
 * @brief 设置访问组错误中断服务请求.
 *
 * @param Group 访问组索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetGroupErrorIntrServiceRequest(Dma_AccessGroupIndex_t Group)
{
    KF_DMA_ASSERT(CHECK_DMA_ACCESS_GROUP_INDEX(Group));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_ACCESS_GROUP_INDEX_0 == Group)
    {
        regValue = REG_READ(HWIO_DMA_EIS0_ADDR);
        regValue &= ~HWIO_DMA_EIS0_DMA_EIS0_SIT_MASK;
        regValue |= true << HWIO_DMA_EIS0_DMA_EIS0_SIT_SHFT;
        REG_WRITE(HWIO_DMA_EIS0_ADDR, regValue);
    }
    else if (DMA_ACCESS_GROUP_INDEX_1 == Group)
    {
        regValue = REG_READ(HWIO_DMA_EIS1_ADDR);
        regValue &= ~HWIO_DMA_EIS1_DMA_EIS1_SIT_MASK;
        regValue |= true << HWIO_DMA_EIS1_DMA_EIS1_SIT_SHFT;
        REG_WRITE(HWIO_DMA_EIS1_ADDR, regValue);
    }
    else if (DMA_ACCESS_GROUP_INDEX_2 == Group)
    {
        regValue = REG_READ(HWIO_DMA_EIS2_ADDR);
        regValue &= ~HWIO_DMA_EIS2_DMA_EIS2_SIT_MASK;
        regValue |= true << HWIO_DMA_EIS2_DMA_EIS2_SIT_SHFT;
        REG_WRITE(HWIO_DMA_EIS2_ADDR, regValue);
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_EIS3_ADDR);
        regValue &= ~HWIO_DMA_EIS3_DMA_EIS3_SIT_MASK;
        regValue |= true << HWIO_DMA_EIS3_DMA_EIS3_SIT_SHFT;
        REG_WRITE(HWIO_DMA_EIS3_ADDR, regValue);
    }
#else
    REG_WRITE(DMA_PTR->EIS[Group].bits.SIT, true);
#endif
}

/**
 * @brief 使能/禁止主机标签号的访问
 *
 * @param GroupIndex 访问组索引
 *          DMA_ACCESS_GROUP_INDEX_0 访问组索引0
 *          DMA_ACCESS_GROUP_INDEX_1 访问组索引1
 *          DMA_ACCESS_GROUP_INDEX_2 访问组索引2
 *          DMA_ACCESS_GROUP_INDEX_3 访问组索引3
 * @param MasterIndex 主机标签号索引
 *          DMA_MASTER_TAG_INDEX_0
 *          DMA_MASTER_TAG_INDEX_1
 *          DMA_MASTER_TAG_INDEX_2
 *          DMA_MASTER_TAG_INDEX_3
 *          DMA_MASTER_TAG_INDEX_4
 *          DMA_MASTER_TAG_INDEX_5
 *          DMA_MASTER_TAG_INDEX_6
 *          DMA_MASTER_TAG_INDEX_7
 *          DMA_MASTER_TAG_INDEX_8
 *          DMA_MASTER_TAG_INDEX_9
 *          DMA_MASTER_TAG_INDEX_10
 *          DMA_MASTER_TAG_INDEX_11
 *          DMA_MASTER_TAG_INDEX_12
 *          DMA_MASTER_TAG_INDEX_13
 *          DMA_MASTER_TAG_INDEX_14
 *          DMA_MASTER_TAG_INDEX_15
 *          DMA_MASTER_TAG_INDEX_16
 *          DMA_MASTER_TAG_INDEX_17
 *          DMA_MASTER_TAG_INDEX_18
 *          DMA_MASTER_TAG_INDEX_19
 *          DMA_MASTER_TAG_INDEX_20
 *          DMA_MASTER_TAG_INDEX_21
 *          DMA_MASTER_TAG_INDEX_22
 *          DMA_MASTER_TAG_INDEX_23
 *          DMA_MASTER_TAG_INDEX_24
 *          DMA_MASTER_TAG_INDEX_25
 *          DMA_MASTER_TAG_INDEX_26
 *          DMA_MASTER_TAG_INDEX_27
 *          DMA_MASTER_TAG_INDEX_28
 *          DMA_MASTER_TAG_INDEX_29
 *          DMA_MASTER_TAG_INDEX_30
 *          DMA_MASTER_TAG_INDEX_31
 * @param State 访问使能/禁止
 *          false 不执行写访问操作
 *          true 执行写访问操作
 *
 * @return void
 */
KF_INLINE void
DMA_LL_SetAccessGroupEnable(Dma_AccessGroupIndex_t GroupIndex, Dma_MasterTagIndex_t MasterIndex, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ACCESS_GROUP_INDEX(GroupIndex));
    KF_DMA_ASSERT(CHECK_DMA_MASTER_TAG_INDEX(MasterIndex));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_ACCESS_GROUP_INDEX_0 == GroupIndex)
    {
        regValue = REG_READ(HWIO_DMA_ACES0_ADDR);
        regValue &= ~(1U << MasterIndex);
        regValue |= State << MasterIndex;
        REG_WRITE(HWIO_DMA_ACES0_ADDR, regValue);
    }
    else if (DMA_ACCESS_GROUP_INDEX_1 == GroupIndex)
    {
        regValue = REG_READ(HWIO_DMA_ACES1_ADDR);
        regValue &= ~(1U << MasterIndex);
        regValue |= State << MasterIndex;
        REG_WRITE(HWIO_DMA_ACES1_ADDR, regValue);
    }
    else if (DMA_ACCESS_GROUP_INDEX_2 == GroupIndex)
    {
        regValue = REG_READ(HWIO_DMA_ACES2_ADDR);
        regValue &= ~(1U << MasterIndex);
        regValue |= State << MasterIndex;
        REG_WRITE(HWIO_DMA_ACES2_ADDR, regValue);
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ACES3_ADDR);
        regValue &= ~(1U << MasterIndex);
        regValue |= State << MasterIndex;
        REG_WRITE(HWIO_DMA_ACES3_ADDR, regValue);
    }
#else
    uint32_t Mask;
    uint32_t Value;

    Mask  = (uint32_t)0x1U << ((uint32_t)MasterIndex);
    Value = (uint32_t)State << ((uint32_t)MasterIndex);

    REG_BITS_WRITE(DMA_PTR->ACES[GroupIndex].reg, Mask, Value);
#endif
}

/**
 * @brief 设置DMA通道访问组.
 *
 * @param Channel DMA通道索引
 * @param Group 访问组索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelAccessGroup(Dma_ChannelIndex_t Channel, Dma_AccessGroupIndex_t Group)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_ACCESS_GROUP_INDEX(Group));

#ifdef SIMULATION
    REG_WRITE(HWIO_DMA_HRR0_ADDR + (Channel << 2U), Group);
#else
    REG_WRITE(DMA_PTR->HRR[Channel].bits.HRP, Group);
#endif
}

/**
 * @brief 设置DMA通道的挂起使能.
 *
 * @param Channel DMA通道索引
 * @param State 是否使能通道挂起
 *          false 禁用DMA通道挂起
 *          true 使能DMA通道挂起,如果挂起请求信号有效,在当前DMA传输完成后,DMA通道停止
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelSuspendEnabled(Dma_ChannelIndex_t Channel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    REG_WRITE(HWIO_DMA_SUSENR0_ADDR + (Channel << 2U), State);
#else
    REG_WRITE(DMA_PTR->SUSENR[Channel].bits.SUSEN, State);
#endif
}

/**
 * @brief DMA通道的挂起或冻结状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool 通道状态
 *          false DMA通道不处于挂起或冻结状态,且也没有挂起或冻结状态导致的内部未完成操作
 *          true DMA通道处于挂起或冻结状态
 */
KF_INLINE bool DMA_LL_GetChannelSuspendOrFrozenState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_SUSACR0_ADDR + (Channel << 2U));

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->SUSACR[Channel].bits.SUSAC)));
#endif
}

/**
 * @brief 使能\禁用错误中断
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 * @param State 使能偏移位
 *          DMA_ERROR_INTR_SEIE  使能搬运引擎源报错
 *          DMA_ERROR_INTR_DEIE  使能搬运引擎目标报错
 *          DMA_ERROR_INTR_DLLEIE 使能搬运引擎DMA链表报错
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetErrorIntrEnabled(Dma_MoveEngineIndex_t Index, Dma_ErrorIntrEnableMask_t Mask, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_EIE0_ADDR);

        if (DMA_ERROR_INTR_SEIE == Mask)
        {
            regValue &= ~HWIO_DMA_EIE0_DMA_EIE0_SEIE_MASK;
            regValue |= State << HWIO_DMA_EIE0_DMA_EIE0_SEIE_SHFT;
        }
        else if (DMA_ERROR_INTR_DEIE == Mask)
        {
            regValue &= ~HWIO_DMA_EIE0_DMA_EIE0_DEIE_MASK;
            regValue |= State << HWIO_DMA_EIE0_DMA_EIE0_DEIE_SHFT;
        }
        else
        {
            regValue &= ~HWIO_DMA_EIE0_DMA_EIE0_DLLEIE_MASK;
            regValue |= State << HWIO_DMA_EIE0_DMA_EIE0_DLLEIE_SHFT;
        }

        REG_WRITE(HWIO_DMA_EIE0_ADDR, regValue);
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_EIE1_ADDR);

        if (DMA_ERROR_INTR_SEIE == Mask)
        {
            regValue &= ~HWIO_DMA_EIE1_DMA_EIE1_SEIE_MASK;
            regValue |= State << HWIO_DMA_EIE1_DMA_EIE1_DEIE_SHFT;
        }
        else if (DMA_ERROR_INTR_DEIE == Mask)
        {
            regValue &= ~HWIO_DMA_EIE1_DMA_EIE1_DEIE_MASK;
            regValue |= State << HWIO_DMA_EIE1_DMA_EIE1_DEIE_SHFT;
        }
        else
        {
            regValue &= ~HWIO_DMA_EIE1_DMA_EIE1_DLLEIE_MASK;
            regValue |= State << HWIO_DMA_EIE1_DMA_EIE1_DLLEIE_SHFT;
        }

        REG_WRITE(HWIO_DMA_EIE1_ADDR, regValue);
    }
#else
    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        REG_BITS_WRITE(DMA_PTR->EIE0.reg, Mask, State);
    }
    else
    {
        REG_BITS_WRITE(DMA_PTR->EIE1.reg, Mask, State);
    }
#endif
}

/**
 * @brief 获取搬运引擎上一个错误通道
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return uint32_t 上一个错误通道
 */
KF_INLINE uint32_t DMA_LL_GetLastErrorChannel(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;
    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_EIF0_ADDR);
        regValue &= HWIO_DMA_EIF0_DMA_EIF0_LEC_MASK;
        regValue = regValue >> HWIO_DMA_EIF0_DMA_EIF0_LEC_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_EIF1_ADDR);
        regValue &= HWIO_DMA_EIF1_DMA_EIF1_LEC_MASK;
        regValue = regValue >> HWIO_DMA_EIF1_DMA_EIF1_LEC_SHFT;
    }

    return regValue;
#else
    uint32_t retval = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->EIF0.bits.LEC)));
    }
    else
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->EIF1.bits.LEC)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎错误中断标志
 *
 * @param MEIndex 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 * @param IntrMask 错误中断掩码
 *          DMA_STATE_SE 搬运引擎源错误掩码
 *          DMA_STATE_DE 搬运引擎目标错误掩码
 *          DMA_STATE_PERIE 搬运引擎Peri_BUS错误掩码
 *          DMA_STATE_SYSE 搬运引擎System_BUS错误掩码
 *          DMA_STATE_RAME 搬运引擎RMA错误掩码
 *          DMA_STATE_SLLE 搬运引擎安全链表错误掩码
 *          DMA_STATE_DLLE 搬运引擎DMA链表错误掩码
 *
 * @return bool
 * @retval false 无报错
 *         true 有报错
 */
KF_INLINE bool DMA_LL_GetErrorIntrFlag(Dma_MoveEngineIndex_t MEIndex, Dma_ErrorIntrMask_t IntrMask)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(MEIndex));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == MEIndex)
    {
        regValue = REG_READ(HWIO_DMA_EIF0_ADDR);

        if (DMA_STATE_SE == IntrMask)
        {
            regValue &= HWIO_DMA_EIF0_DMA_EIF0_SEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF0_DMA_EIF0_SEIF_SHFT;
        }
        else if (DMA_STATE_DE == IntrMask)
        {
            regValue &= HWIO_DMA_EIF0_DMA_EIF0_DEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF0_DMA_EIF0_DEIF_SHFT;
        }
        else if (DMA_STATE_PERIE == IntrMask)
        {
            regValue &= HWIO_DMA_EIF0_DMA_EIF0_PERIEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF0_DMA_EIF0_PERIEIF_SHFT;
        }
        else if (DMA_STATE_SYSE == IntrMask)
        {
            regValue &= HWIO_DMA_EIF0_DMA_EIF0_SYSEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF0_DMA_EIF0_SYSEIF_SHFT;
        }
        else if (DMA_STATE_RAME == IntrMask)
        {
            regValue &= HWIO_DMA_EIF0_DMA_EIF0_RAMEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF0_DMA_EIF0_RAMEIF_SHFT;
        }
        else if (DMA_STATE_SLLE == IntrMask)
        {
            regValue &= HWIO_DMA_EIF0_DMA_EIF0_SLLEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF0_DMA_EIF0_SLLEIF_SHFT;
        }
        else
        {
            regValue &= HWIO_DMA_EIF0_DMA_EIF0_DLLEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF0_DMA_EIF0_DLLEIF_SHFT;
        }
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_EIF1_ADDR);

        if (DMA_STATE_SE == IntrMask)
        {
            regValue &= HWIO_DMA_EIF1_DMA_EIF1_SEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF1_DMA_EIF1_SEIF_SHFT;
        }
        else if (DMA_STATE_DE == IntrMask)
        {
            regValue &= HWIO_DMA_EIF1_DMA_EIF1_DEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF1_DMA_EIF1_DEIF_SHFT;
        }
        else if (DMA_STATE_PERIE == IntrMask)
        {
            regValue &= HWIO_DMA_EIF1_DMA_EIF1_PERIEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF1_DMA_EIF1_PERIEIF_SHFT;
        }
        else if (DMA_STATE_SYSE == IntrMask)
        {
            regValue &= HWIO_DMA_EIF1_DMA_EIF1_SYSEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF1_DMA_EIF1_SYSEIF_SHFT;
        }
        else if (DMA_STATE_RAME == IntrMask)
        {
            regValue &= HWIO_DMA_EIF1_DMA_EIF1_RAMEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF1_DMA_EIF1_RAMEIF_SHFT;
        }
        else if (DMA_STATE_SLLE == IntrMask)
        {
            regValue &= HWIO_DMA_EIF1_DMA_EIF1_SLLEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF1_DMA_EIF1_SLLEIF_SHFT;
        }
        else
        {
            regValue &= HWIO_DMA_EIF1_DMA_EIF1_DLLEIF_MASK;
            regValue = regValue >> HWIO_DMA_EIF1_DMA_EIF1_DLLEIF_SHFT;
        }
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == MEIndex)
    {
        retval = ((bool)(REG_BIT_BOOLED(DMA_PTR->EIF0.reg, IntrMask)));
    }
    else
    {
        retval = ((bool)(REG_BIT_BOOLED(DMA_PTR->EIF1.reg, IntrMask)));
    }

    return retval;
#endif
}

/**
 * @brief 清除错误状态位
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 * @param IntrMask 错误中断掩码
 *          DMA_STATE_SE 搬运引擎源错误掩码
 *          DMA_STATE_DE 搬运引擎目标错误掩码
 *          DMA_STATE_PERIE 搬运引擎Peri_BUS错误掩码
 *          DMA_STATE_SYSE 搬运引擎System_BUS错误掩码
 *          DMA_STATE_RAME 搬运引擎RMA错误掩码
 *          DMA_STATE_SLLE 搬运引擎安全链表错误掩码
 *          DMA_STATE_DLLE 搬运引擎DMA链表错误掩码
 *
 * @return void
 */
KF_INLINE void DMA_LL_ClearErrorState(Dma_MoveEngineIndex_t MEIndex, Dma_ErrorIntrMask_t IntrMask)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(MEIndex));

#ifdef SIMULATION
    if (DMA_MOVE_ENGINE_INDEX_0 == MEIndex)
    {
        if (DMA_STATE_SE == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC0_ADDR, HWIO_DMA_EIC0_DMA_EIC0_SEIC_MASK);
        }
        else if (DMA_STATE_DE == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC0_ADDR, HWIO_DMA_EIC0_DMA_EIC0_DEIC_MASK);
        }
        else if (DMA_STATE_PERIE == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC0_ADDR, HWIO_DMA_EIC0_DMA_EIC0_PERIEIC_MASK);
        }
        else if (DMA_STATE_SYSE == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC0_ADDR, HWIO_DMA_EIC0_DMA_EIC0_SYSEIC_MASK);
        }
        else if (DMA_STATE_RAME == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC0_ADDR, HWIO_DMA_EIC0_DMA_EIC0_RAMEIC_MASK);
        }
        else if (DMA_STATE_SLLE == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC0_ADDR, HWIO_DMA_EIC0_DMA_EIC0_SLLEIC_MASK);
        }
        else
        {
            REG_WRITE(HWIO_DMA_EIC0_ADDR, HWIO_DMA_EIC0_DMA_EIC0_DLLEIC_MASK);
        }
    }
    else
    {
        if (DMA_STATE_SE == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC1_ADDR, HWIO_DMA_EIC1_DMA_EIC1_SEIC_MASK);
        }
        else if (DMA_STATE_DE == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC1_ADDR, HWIO_DMA_EIC1_DMA_EIC1_DEIC_MASK);
        }
        else if (DMA_STATE_PERIE == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC1_ADDR, HWIO_DMA_EIC1_DMA_EIC1_PERIEIC_MASK);
        }
        else if (DMA_STATE_SYSE == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC1_ADDR, HWIO_DMA_EIC1_DMA_EIC1_SYSEIC_MASK);
        }
        else if (DMA_STATE_RAME == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC1_ADDR, HWIO_DMA_EIC1_DMA_EIC1_RAMEIC_MASK);
        }
        else if (DMA_STATE_SLLE == IntrMask)
        {
            REG_WRITE(HWIO_DMA_EIC1_ADDR, HWIO_DMA_EIC1_DMA_EIC1_SLLEIC_MASK);
        }
        else
        {
            REG_WRITE(HWIO_DMA_EIC1_ADDR, HWIO_DMA_EIC1_DMA_EIC1_DLLEIC_MASK);
        }
    }
#else
    if (DMA_MOVE_ENGINE_INDEX_0 == MEIndex)
    {
        REG_BIT_SET(DMA_PTR->EIC0.reg, IntrMask);
    }
    else
    {
        REG_BIT_SET(DMA_PTR->EIC1.reg, IntrMask);
    }
#endif
}

/**
 * @brief 获取搬运引擎读状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 搬运引擎没有在执行读操作
 *         true 搬运引擎在执行读操作
 */
KF_INLINE bool DMA_LL_GetMEReadState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0STA_ADDR);
        regValue &= HWIO_DMA_ME0STA_DMA_ME0STA_RSTA_MASK;
        regValue = regValue >> HWIO_DMA_ME0STA_DMA_ME0STA_RSTA_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1STA_ADDR);
        regValue &= HWIO_DMA_ME1STA_DMA_ME1STA_RSTA_MASK;
        regValue = regValue >> HWIO_DMA_ME1STA_DMA_ME1STA_RSTA_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0STA.bits.RSTA)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1STA.bits.RSTA)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎读状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 搬运引擎没有在执行写操作
 *         true 搬运引擎在执行写操作
 */
KF_INLINE bool DMA_LL_GetMEWriteState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0STA_ADDR);
        regValue &= HWIO_DMA_ME0STA_DMA_ME0STA_WSTA_MASK;
        regValue = regValue >> HWIO_DMA_ME0STA_DMA_ME0STA_WSTA_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1STA_ADDR);
        regValue &= HWIO_DMA_ME0STA_DMA_ME0STA_CH_MASK;
        regValue = regValue >> HWIO_DMA_ME0STA_DMA_ME0STA_CH_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0STA.bits.WSTA)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1STA.bits.WSTA)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前传输的通道
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return uint32_t 搬运引擎激活的通道
 */
KF_INLINE uint32_t DMA_LL_GetMECurrentActiveChannel(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0STA_ADDR);
        regValue &= HWIO_DMA_ME0STA_DMA_ME0STA_CH_MASK;
        regValue = regValue >> HWIO_DMA_ME0STA_DMA_ME0STA_CH_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1STA_ADDR);
        regValue &= HWIO_DMA_ME1STA_DMA_ME1STA_CH_MASK;
        regValue = regValue >> HWIO_DMA_ME1STA_DMA_ME1STA_CH_SHFT;
    }

    return regValue;
#else
    uint32_t retval = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME0STA.bits.CH)));
    }
    else
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME1STA.bits.CH)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎读取寄存器值
 *
 * @param MEIndex 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 * @param RegIndex 搬运引擎搬运数据读取寄存器索引(最大数据宽度为16Bytes)
 *          DMA_DATA_READ_REG_INDEX_0 读取寄存器索引0
 *          DMA_DATA_READ_REG_INDEX_1 读取寄存器索引1
 *          DMA_DATA_READ_REG_INDEX_2 读取寄存器索引2
 *          DMA_DATA_READ_REG_INDEX_3 读取寄存器索引3
 *          DMA_DATA_READ_REG_INDEX_4 读取寄存器索引4
 *          DMA_DATA_READ_REG_INDEX_5 读取寄存器索引5
 *          DMA_DATA_READ_REG_INDEX_6 读取寄存器索引6
 *          DMA_DATA_READ_REG_INDEX_7 读取寄存器索引7
 *          DMA_DATA_READ_REG_INDEX_8 读取寄存器索引8
 *          DMA_DATA_READ_REG_INDEX_9 读取寄存器索引9
 *          DMA_DATA_READ_REG_INDEX_10 读取寄存器索引10
 *          DMA_DATA_READ_REG_INDEX_11 读取寄存器索引11
 *          DMA_DATA_READ_REG_INDEX_12 读取寄存器索引12
 *          DMA_DATA_READ_REG_INDEX_13 读取寄存器索引13
 *          DMA_DATA_READ_REG_INDEX_14 读取寄存器索引14
 *          DMA_DATA_READ_REG_INDEX_15 读取寄存器索引15
 * @param ByteIndex 搬运引擎正在搬运数据的字节索引
 *          DMA_DATA_READ_BYTE_INDEX_0 读取数据字节0
 *          DMA_DATA_READ_BYTE_INDEX_1 读取数据字节1
 *          DMA_DATA_READ_BYTE_INDEX_2 读取数据字节2
 *          DMA_DATA_READ_BYTE_INDEX_3 读取数据字节3
 *
 * @return uint32_t 正在搬运的数据
 */
KF_INLINE uint32_t DMA_LL_GetMEReadRegValue(
  Dma_MoveEngineIndex_t MEIndex, Dma_DataReadRegIndex_t RegIndex, Dma_DataReadByteIndex_t ByteIndex)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(MEIndex));
    KF_DMA_ASSERT(CHECK_DMA_DATA_READ_REG_INDEX(RegIndex));
    KF_DMA_ASSERT(CHECK_DMA_DATA_READ_BYTE_INDEX(ByteIndex));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == MEIndex)
    {
        regValue = REG_READ(HWIO_DMA_ME00R_ADDR + (RegIndex << 2U));

        if (DMA_DATA_READ_BYTE_INDEX_0 == ByteIndex)
        {
            regValue &= HWIO_DMA_ME00R_DMA_ME00R_RD00_MASK;
            regValue = regValue >> HWIO_DMA_ME00R_DMA_ME00R_RD00_SHFT;
        }
        else if (DMA_DATA_READ_BYTE_INDEX_1 == ByteIndex)
        {
            regValue &= HWIO_DMA_ME00R_DMA_ME00R_RD01_MASK;
            regValue = regValue >> HWIO_DMA_ME00R_DMA_ME00R_RD01_SHFT;
        }
        else if (DMA_DATA_READ_BYTE_INDEX_2 == ByteIndex)
        {
            regValue &= HWIO_DMA_ME00R_DMA_ME00R_RD02_MASK;
            regValue = regValue >> HWIO_DMA_ME00R_DMA_ME00R_RD02_SHFT;
        }
        else
        {
            regValue &= HWIO_DMA_ME00R_DMA_ME00R_RD03_MASK;
            regValue = regValue >> HWIO_DMA_ME00R_DMA_ME00R_RD03_SHFT;
        }
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME10R_ADDR + (RegIndex << 2U));

        if (DMA_DATA_READ_BYTE_INDEX_0 == ByteIndex)
        {
            regValue &= HWIO_DMA_ME10R_DMA_ME10R_RD00_MASK;
            regValue = regValue >> HWIO_DMA_ME10R_DMA_ME10R_RD00_SHFT;
        }
        else if (DMA_DATA_READ_BYTE_INDEX_1 == ByteIndex)
        {
            regValue &= HWIO_DMA_ME10R_DMA_ME10R_RD01_MASK;
            regValue = regValue >> HWIO_DMA_ME10R_DMA_ME10R_RD01_SHFT;
        }
        else if (DMA_DATA_READ_BYTE_INDEX_2 == ByteIndex)
        {
            regValue &= HWIO_DMA_ME10R_DMA_ME10R_RD02_MASK;
            regValue = regValue >> HWIO_DMA_ME10R_DMA_ME10R_RD02_SHFT;
        }
        else
        {
            regValue &= HWIO_DMA_ME10R_DMA_ME10R_RD03_MASK;
            regValue = regValue >> HWIO_DMA_ME10R_DMA_ME10R_RD03_SHFT;
        }
    }

    return regValue;
#else
    uint32_t retval = 0U;
    uint32_t Mask   = 0U;
    uint32_t Pos    = 0U;

    Mask = (uint32_t)0xFFU << (ByteIndex * 8U);
    Pos  = (ByteIndex * 8U);

    if (DMA_MOVE_ENGINE_INDEX_0 == MEIndex)
    {
        retval = ((uint32_t)(REG_BITS_READ(DMA_PTR->MER0R[RegIndex].reg, Mask, Pos)));
    }
    else
    {
        retval = ((uint32_t)(REG_BITS_READ(DMA_PTR->MER1R[RegIndex].reg, Mask, Pos)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎读取数据的CRC值
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return uint32_t 搬运引擎读取数据的CRC值
 */
KF_INLINE uint32_t DMA_LL_GetMEReadDataCrc(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0RDCRC_ADDR);
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1RDCRC_ADDR);
    }

    return regValue;
#else
    uint32_t retval = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME0RDCRC.bits.RDCRC)));
    }
    else
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME1RDCRC.bits.RDCRC)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道的源及目标地址CRC值
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return uint32_t 搬运引擎当前激活通道的源及目标地址CRC值
 */
KF_INLINE uint32_t DMA_LL_GetMESrcAndDestAddrCrc(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

    uint32_t retval = 0U;

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0SDCRC_ADDR);
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1SDCRC_ADDR);
    }

    return regValue;
#else
    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME0SDCRC.bits.SDCRC)));
    }
    else
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME1SDCRC.bits.SDCRC)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道的源地址
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return uint32_t 搬运引擎当前激活通道的源地址
 */
KF_INLINE uint32_t DMA_LL_GetMESrcAddr(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0SADR_ADDR);
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1SADR_ADDR);
    }

    return regValue;
#else
    uint32_t retval = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME0SADR.bits.SADR)));
    }
    else
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME1SADR.bits.SADR)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道的目标地址
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return uint32_t 搬运引擎当前激活通道的目标地址
 */
KF_INLINE uint32_t DMA_LL_GetMEDestAddr(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0DADR_ADDR);
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1DADR_ADDR);
    }

    return regValue;
#else
    uint32_t retval = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME0DADR.bits.DADR)));
    }
    else
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME1DADR.bits.DADR)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道的源地址偏移量
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_AddrOffsetStep_t 地址偏移量
 * @retval DMA_ADDR_OFFSET_STEP_1 地址偏移1倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_2 地址偏移2倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_4 地址偏移4倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_8 地址偏移8倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_16 地址偏移16倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_32 地址偏移32倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_64 地址偏移64倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_128 地址偏移128倍的CHDW
 */
KF_INLINE Dma_AddrOffsetStep_t DMA_LL_GetMESrcAddrOffsetStep(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_SMF_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_SMF_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_SMF_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_SMF_SHFT;
    }

    return (Dma_AddrOffsetStep_t)regValue;
#else
    Dma_AddrOffsetStep_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_AddrOffsetStep_t)(REG_READ(DMA_PTR->ME0ADICR.bits.SMF)));
    }
    else
    {
        retval = ((Dma_AddrOffsetStep_t)(REG_READ(DMA_PTR->ME1ADICR.bits.SMF)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道的源地址偏移方向
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_AddrOffsetDir_t
 *          DMA_ADDR_OFFSET_DIR_SUBTRACT 地址逐渐减小
 *          DMA_ADDR_OFFSET_DIR_ADD 地址逐渐增大
 */
KF_INLINE Dma_AddrOffsetDir_t DMA_LL_GetMESrcAddrOffsetDir(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_INCS_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_INCS_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_INCS_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_INCS_SHFT;
    }

    return (Dma_AddrOffsetDir_t)regValue;
#else
    Dma_AddrOffsetDir_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_AddrOffsetDir_t)(REG_READ(DMA_PTR->ME0ADICR.bits.INCS)));
    }
    else
    {
        retval = ((Dma_AddrOffsetDir_t)(REG_READ(DMA_PTR->ME1ADICR.bits.INCS)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道的目标地址的偏移量
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_AddrOffsetStep_t 地址偏移量
 * @retval DMA_ADDR_OFFSET_STEP_1 地址偏移1倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_2 地址偏移2倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_4 地址偏移4倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_8 地址偏移8倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_16 地址偏移16倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_32 地址偏移32倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_64 地址偏移64倍的CHDW
 *         DMA_ADDR_OFFSET_STEP_128 地址偏移128倍的CHDW
 */
KF_INLINE Dma_AddrOffsetStep_t DMA_LL_GetMEDestAddrOffsetStep(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_DMF_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_DMF_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_DMF_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_DMF_SHFT;
    }

    return (Dma_AddrOffsetStep_t)regValue;
#else
    Dma_AddrOffsetStep_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_AddrOffsetStep_t)(REG_READ(DMA_PTR->ME0ADICR.bits.DMF)));
    }
    else
    {
        retval = ((Dma_AddrOffsetStep_t)(REG_READ(DMA_PTR->ME1ADICR.bits.DMF)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道的目标地址偏移方向
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_AddrOffsetDir_t
 *          DMA_ADDR_OFFSET_DIR_SUBTRACT 地址逐渐减小
 *          DMA_ADDR_OFFSET_DIR_ADD 地址逐渐增大
 */
KF_INLINE Dma_AddrOffsetDir_t DMA_LL_GetMEDestAddrOffsetDir(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_INCD_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_INCD_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_INCD_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_INCD_SHFT;
    }

    return (Dma_AddrOffsetDir_t)regValue;
#else
    Dma_AddrOffsetDir_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_AddrOffsetDir_t)(REG_READ(DMA_PTR->ME0ADICR.bits.INCD)));
    }
    else
    {
        retval = ((Dma_AddrOffsetDir_t)(REG_READ(DMA_PTR->ME1ADICR.bits.INCD)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道源循环缓冲区大小
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_CircularBuffer_t
 */
KF_INLINE Dma_CircularBuffer_t DMA_LL_GetMESrcCircularBufferSize(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_CBLS_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_CBLS_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_CBLS_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_CBLS_SHFT;
    }

    return (Dma_CircularBuffer_t)regValue;
#else
    Dma_CircularBuffer_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_CircularBuffer_t)(REG_READ(DMA_PTR->ME0ADICR.bits.CBLS)));
    }
    else
    {
        retval = ((Dma_CircularBuffer_t)(REG_READ(DMA_PTR->ME1ADICR.bits.CBLS)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道目标循环缓冲区大小
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_CircularBuffer_t
 */
KF_INLINE Dma_CircularBuffer_t DMA_LL_GetMEDestCircularBufferSize(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_CBLD_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_CBLD_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_CBLD_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_CBLD_SHFT;
    }

    return (Dma_CircularBuffer_t)regValue;
#else
    Dma_CircularBuffer_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_CircularBuffer_t)(REG_READ(DMA_PTR->ME0ADICR.bits.CBLD)));
    }
    else
    {
        retval = ((Dma_CircularBuffer_t)(REG_READ(DMA_PTR->ME1ADICR.bits.CBLD)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道影子控制模式
 *
 * @param Index 搬运引擎索引
 * DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 * DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_ShadowCtrl_t
 * @retval DMA_SHADOW_CTRL_MOVE_OPERATION 搬运操作
 *         DMA_SHADOW_CTRL_READ_ONLY_SRC_ADDR 源地址只读模式的影子操作
 *         DMA_SHADOW_CTRL_READ_ONLY_DEST_ADDR 目标地址只读模式的影子操作
 *         DMA_SHADOW_CTRL_DIRECT_WRITE_SRC_ADDR 源地址直写模式的影子操作
 *         DMA_SHADOW_CTRL_DIRECT_WRITE_DEST_ADDR 目标地址直写模式的影子操作
 *         DMA_SHADOW_CTRL_DOUBLE_SRC_WITH_SOFTWARE_SWITCH 仅软件切换的DMA双源缓冲区
 *         DMA_SHADOW_CTRL_DOUBLE_SRC_WITH_SOFTWARE_HARDWARE 软件可切换与自动硬件切换的DMA双源缓冲区
 *         DMA_SHADOW_CTRL_DOUBLE_DEST_WITH_SOFTWARE_SWITCH 仅软件切换的DMA双目标缓冲区
 *         DMA_SHADOW_CTRL_DOUBLE_DEST_WITH_SOFTWARE_HARDWARE 软件可切换与自动硬件切换的DMA双目标缓冲区
 *         DMA_SHADOW_CTRL_DMA_LINKED_LIST DMA链表
 *         DMA_SHADOW_CTRL_ACCUMULATED_LINKED_LIST 累加链表
 *         DMA_SHADOW_CTRL_SAFE_LINKED_LIST 安全链表
 *         DMA_SHADOW_CTRL_CONDITIONAL_LINKED_LIST 条件链表
 *
 */
KF_INLINE Dma_ShadowCtrl_t DMA_LL_GetMEShadowCtrl(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

    Dma_ShadowCtrl_t retval;

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_SHCT_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_SHCT_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_SHCT_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_SHCT_SHFT;
    }

    return (Dma_ShadowCtrl_t)regValue;
#else
    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_ShadowCtrl_t)(REG_READ(DMA_PTR->ME0ADICR.bits.SHCT)));
    }
    else
    {
        retval = ((Dma_ShadowCtrl_t)(REG_READ(DMA_PTR->ME1ADICR.bits.SHCT)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道源循环缓冲区使能状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 源循环缓冲区已禁止
 *         true 源循环缓冲区已使能
 */
KF_INLINE bool DMA_LL_GetMESrcCircularBufferEnabledStatus(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_SCBE_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_SCBE_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_SCBE_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_SCBE_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = (bool)(REG_READ(DMA_PTR->ME0ADICR.bits.SCBE));
    }
    else
    {
        retval = (bool)(REG_READ(DMA_PTR->ME1ADICR.bits.SCBE));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道目标循环缓冲区使能状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 目标循环缓冲区已禁止
 *         true 目标循环缓冲区已使能
 */
KF_INLINE bool DMA_LL_GetMEDestCircularBufferEnabledStatus(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_DCBE_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_DCBE_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_DCBE_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_DCBE_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {

        retval = (bool)(REG_READ(DMA_PTR->ME0ADICR.bits.DCBE));
    }
    else
    {
        retval = (bool)(REG_READ(DMA_PTR->ME1ADICR.bits.DCBE));
    }

    return retval;
#endif
}

/**
 * @brief 获取DMA通道的时间戳状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 无操作
 *         true 附件DMA时间戳
 */
KF_INLINE bool DMA_LL_GetMETimeStampState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_STAMP_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_STAMP_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_STAMP_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_STAMP_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0ADICR.bits.STAMP)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1ADICR.bits.STAMP)));
    }

    return retval;
#endif
}

/**
 * @brief 获取源缓冲区回环使能状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 已禁用回环源缓冲区中断触发
 *         true 已使能回环源缓冲区中断触发
 */
KF_INLINE bool DMA_LL_GetMEWrapSrcBufferEnabledState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_WRPSE_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_WRPSE_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_WRPSE_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_WRPSE_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0ADICR.bits.WRPSE)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1ADICR.bits.WRPSE)));
    }

    return retval;
#endif
}

/**
 * @brief 获取目标缓冲区回环使能状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 已禁用回环源缓冲区中断触发
 *         true 已使能回环源缓冲区中断触发
 */
KF_INLINE bool DMA_LL_GetMEWrapDestBufferEnabledState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_WRPDE_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_WRPDE_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_WRPDE_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_WRPDE_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0ADICR.bits.WRPDE)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1ADICR.bits.WRPDE)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道中断控制状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_IntrCtrl_t
 * @retval DMA_INTR_CTRL_NO_INTR_BUT_EQUAL TCNT值改变不会生成中断触发。TCNT与IRDV相等，CHSTA.ICH置1
 *         DMA_INTR_CTRL_NO_INTR_BUT_DECREASE TCNT值改变不会生成中断触发。TCNT减小，CHSTA.ICH置1
 *         DMA_INTR_CTRL_THRESHOLD_MATCH TCNT改变且等于IRDV时，生成中断触发并且CHSTA.ICH置1
 *         DMA_INTR_CTRL_EVERY_DECREMENT TCNT值每次减少时，生成中断触发并且CHSTA.ICH置1
 */
KF_INLINE Dma_IntrCtrl_t DMA_LL_GetMEIntrCtrlState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_INTCT_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_INTCT_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_INTCT_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_INTCT_SHFT;
    }

    return (Dma_IntrCtrl_t)regValue;
#else
    Dma_IntrCtrl_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_IntrCtrl_t)(REG_READ(DMA_PTR->ME0ADICR.bits.INTCT)));
    }
    else
    {
        retval = ((Dma_IntrCtrl_t)(REG_READ(DMA_PTR->ME1ADICR.bits.INTCT)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道中断上升阈值
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return uint8_t
 */
KF_INLINE uint8_t DMA_LL_GetMEIntrRaiseDetectValue(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0ADICR_ADDR);
        regValue &= HWIO_DMA_ME0ADICR_DMA_ME0ADICR_IRDV_MASK;
        regValue = regValue >> HWIO_DMA_ME0ADICR_DMA_ME0ADICR_IRDV_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1ADICR_ADDR);
        regValue &= HWIO_DMA_ME1ADICR_DMA_ME1ADICR_IRDV_MASK;
        regValue = regValue >> HWIO_DMA_ME1ADICR_DMA_ME1ADICR_IRDV_SHFT;
    }

    return (Dma_IntrCtrl_t)regValue;
#else
    uint8_t retval = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((uint8_t)(REG_READ(DMA_PTR->ME0ADICR.bits.IRDV)));
    }
    else
    {
        retval = ((uint8_t)(REG_READ(DMA_PTR->ME1ADICR.bits.IRDV)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道传输重载值
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return uint32_t
 */
KF_INLINE uint32_t DMA_LL_GetMETransferReloadValue(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHCTL_ADDR);
        regValue &= HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_TREL_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_TREL_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHCTL_ADDR);
        regValue &= HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_TREL_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_TREL_SHFT;
    }

    return regValue;
#else
    uint32_t retval = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME0CHCTL.bits.TREL)));
    }
    else
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME1CHCTL.bits.TREL)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道块模式
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_BlockMode_t
 * @retval DMA_BLOCK_MODE_MOVE_1 1次DMA传输具有1次DMA搬运
 *         DMA_BLOCK_MODE_MOVE_2 1次DMA传输具有2次DMA搬运
 *         DMA_BLOCK_MODE_MOVE_4 1次DMA传输具有4次DMA搬运
 *         DMA_BLOCK_MODE_MOVE_8 1次DMA传输具有8次DMA搬运
 *         DMA_BLOCK_MODE_MOVE_16 1次DMA传输具有16次DMA搬运
 *         DMA_BLOCK_MODE_MOVE_3 1次DMA传输具有3次DMA搬运
 *         DMA_BLOCK_MODE_MOVE_5 1次DMA传输具有5次DMA搬运
 *         DMA_BLOCK_MODE_MOVE_9 1次DMA传输具有9次DMA搬运
 */
KF_INLINE Dma_BlockMode_t DMA_LL_GetMEBlockMode(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHCTL_ADDR);
        regValue &= HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_BLKM_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_BLKM_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHCTL_ADDR);
        regValue &= HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_BLKM_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_BLKM_SHFT;
    }

    return (Dma_BlockMode_t)regValue;
#else
    Dma_BlockMode_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_BlockMode_t)(REG_READ(DMA_PTR->ME0CHCTL.bits.BLKM)));
    }
    else
    {
        retval = ((Dma_BlockMode_t)(REG_READ(DMA_PTR->ME1CHCTL.bits.BLKM)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道设置DMA处理结束后的重置请求状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *
 * @return bool
 * @retval false 每次DMA传输都要DMA请求
 *         true 1个DMA请求开启一次完整的DMA处理
 */
KF_INLINE bool DMA_LL_GetMEResetRequestStatus(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHCTL_ADDR);
        regValue &= HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_RROAT_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_RROAT_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHCTL_ADDR);
        regValue &= HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_RROAT_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_RROAT_SHFT;
    }

    return ((regValue) > 0U ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0CHCTL.bits.RROAT)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1CHCTL.bits.RROAT)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道操作模式
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_ChannelOperationMode_t
 * @retval DMA_CHANNEL_OPERATION_MODE_ONCE 单次传输模式
 *         DMA_CHANNEL_OPERATION_MODE_CONTINUOUS 连续模式
 */
KF_INLINE Dma_ChannelOperationMode_t DMA_LL_GetMEOperationMode(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHCTL_ADDR);
        regValue &= HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_CHMODE_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_CHMODE_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHCTL_ADDR);
        regValue &= HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_CHMODE_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_CHMODE_SHFT;
    }

    return (Dma_ChannelOperationMode_t)regValue;
#else
    Dma_ChannelOperationMode_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_ChannelOperationMode_t)(REG_READ(DMA_PTR->ME0CHCTL.bits.CHMODE)));
    }
    else
    {
        retval = ((Dma_ChannelOperationMode_t)(REG_READ(DMA_PTR->ME1CHCTL.bits.CHMODE)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道数据宽度
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @retval Dma_ChannelDataWidth_t
 *          DMA_CHANNEL_DATA_WIDTH_8 选择8位数据宽度搬运
 *          DMA_CHANNEL_DATA_WIDTH_16 选择16位数据宽度搬运
 *          DMA_CHANNEL_DATA_WIDTH_32 选择32位数据宽度搬运
 *          DMA_CHANNEL_DATA_WIDTH_64 选择64位数据宽度搬运
 *          DMA_CHANNEL_DATA_WIDTH_128 选择128位数据宽度搬运
 *          DMA_CHANNEL_DATA_WIDTH_256 选择256位数据宽度搬运：
 *          DMA_CHANNEL_DATA_WIDTH_512 选择512位数据宽度搬运：
 */
KF_INLINE Dma_ChannelDataWidth_t DMA_LL_GetMEDataWidth(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHCTL_ADDR);
        regValue &= HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_CHDW_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_CHDW_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHCTL_ADDR);
        regValue &= HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_CHDW_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_CHDW_SHFT;
    }

    return (Dma_ChannelDataWidth_t)regValue;
#else
    Dma_ChannelDataWidth_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_ChannelDataWidth_t)(REG_READ(DMA_PTR->ME0CHCTL.bits.CHDW)));
    }
    else
    {
        retval = ((Dma_ChannelDataWidth_t)(REG_READ(DMA_PTR->ME1CHCTL.bits.CHDW)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道搬运数据对照模式
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return Dma_PatternMode_t
 * @retval DMA_PATTERN_NONE 不选择数据对照操作
 *         DMA_PATTERN_WITH_PRR0_PAT00 DMA读搬运数据与PRR0.PAT0比较
 *         DMA_PATTERN_WITH_PRR0_PAT01 DMA读搬运数据与PRR0.PAT1比较
 *         DMA_PATTERN_WITH_PRR0_BOTH DMA读搬运数据与PRR0.PAT0和PAT.1比较
 *         DMA_PATTERN_WITH_NONE 不选择数据对照操作
 *         DMA_PATTERN_WITH_PRR1_PAT00 DMA读搬运数据与PRR1.PAT0比较
 *         DMA_PATTERN_WITH_PRR1_PAT01 DMA读搬运数据与PRR1.PAT1比较
 *         DMA_PATTERN_WITH_PRR1_BOTH DMA读搬运数据与PRR1.PAT0和PAT.1比较
 */
KF_INLINE Dma_PatternMode_t DMA_LL_GetMEPatternMode(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHCTL_ADDR);
        regValue &= HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_PRTSEL_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_PRTSEL_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHCTL_ADDR);
        regValue &= HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_PRTSEL_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_PRTSEL_SHFT;
    }

    return (Dma_PatternMode_t)regValue;
#else
    Dma_PatternMode_t retval;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((Dma_PatternMode_t)(REG_READ(DMA_PTR->ME0CHCTL.bits.PRTSEL)));
    }
    else
    {
        retval = ((Dma_PatternMode_t)(REG_READ(DMA_PTR->ME1CHCTL.bits.PRTSEL)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道交换数据CRC字节序
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 不交换字节序
 *         true 交换字节序
 */
KF_INLINE bool DMA_LL_GetMECRCReverseCtrl(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHCTL_ADDR);
        regValue &= HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_SWAP_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_SWAP_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHCTL_ADDR);
        regValue &= HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_SWAP_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_SWAP_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0CHCTL.bits.SWAP)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1CHCTL.bits.SWAP)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道外设请求选择
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 选择DMA硬件请求
 *         true 选择DMA菊花链请求
 */
KF_INLINE bool DMA_LL_GetMEReqSrc(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHCTL_ADDR);
        regValue &= HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_PRSEL_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHCTL_DMA_ME0CHCTL_PRSEL_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHCTL_ADDR);
        regValue &= HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_PRSEL_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHCTL_DMA_ME1CHCTL_PRSEL_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0CHCTL.bits.PRSEL)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1CHCTL.bits.PRSEL)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前激活通道影子地址
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return uint32_t
 */
KF_INLINE uint32_t DMA_LL_GetMEShadowAddr(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0SHADR_ADDR);
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1SHADR_ADDR);
    }

    return regValue;
#else
    uint32_t retval = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME0SHADR.bits.SHADR)));
    }
    else
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME1SHADR.bits.SHADR)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎当前传输计数值
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @retval uint32_t
 */
KF_INLINE uint32_t DMA_LL_GetTransferCount(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHSTA_ADDR);
        regValue &= HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_TCNT_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_TCNT_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHSTA_ADDR);
        regValue &= HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_TCNT_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_TCNT_SHFT;
    }

    return regValue;
#else
    uint32_t retval = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME0CHSTA.bits.TCNT)));
    }
    else
    {
        retval = ((uint32_t)(REG_READ(DMA_PTR->ME1CHSTA.bits.TCNT)));
    }

    return retval;
#endif
}

/**
 * @brief 获取搬运引擎上一次数据对照状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 上一个DMA读搬运未探测到数据对照
 *         true 上一个DMA读搬运探测到数据对照
 */
KF_INLINE bool DMA_LL_GetMELastPatternDetectionState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHSTA_ADDR);
        regValue &= HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_LXO_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_LXO_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHSTA_ADDR);
        regValue &= HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_LXO_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_LXO_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0CHSTA.bits.LXO)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1CHSTA.bits.LXO)));
    }

    return retval;
#endif
}

/**
 * @brief 获取源缓冲区回环状态
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 源缓冲区未发生回环
 *         true 源缓冲区发生回环
 */
KF_INLINE bool DMA_LL_GetMEWrapSrcBufferState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHSTA_ADDR);
        regValue &= HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_WRPS_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_WRPS_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHSTA_ADDR);
        regValue &= HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_WRPS_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_WRPS_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0CHSTA.bits.WRPS)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1CHSTA.bits.WRPS)));
    }

    return retval;
#endif
}

/**
 * @brief 获取目标缓冲区回环状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 目标缓冲区未发生回环
 *         true 目标缓冲区发生回环
 */
KF_INLINE bool DMA_LL_GetMEWrapDestBufferState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHSTA_ADDR);
        regValue &= HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_WRPD_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_WRPD_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHSTA_ADDR);
        regValue &= HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_WRPD_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_WRPD_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0CHSTA.bits.WRPD)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1CHSTA.bits.WRPD)));
    }

    return retval;
#endif
}

/**
 * @brief 获取通道中断状态
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 该通道未发现中断
 *         true 该通道发现中断
 */
KF_INLINE bool DMA_LL_GetMEIntrState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHSTA_ADDR);
        regValue &= HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_ICH_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_ICH_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHSTA_ADDR);
        regValue &= HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_ICH_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_ICH_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0CHSTA.bits.ICH)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1CHSTA.bits.ICH)));
    }

    return retval;
#endif
}

/**
 * @brief 获取通道数据对照
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 未探测到数据对照
 *         true 探测到数据对照
 */
KF_INLINE bool DMA_LL_GetMEPatternDetectionState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHSTA_ADDR);
        regValue &= HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_IPM_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_IPM_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHSTA_ADDR);
        regValue &= HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_IPM_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_IPM_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0CHSTA.bits.IPM)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1CHSTA.bits.IPM)));
    }

    return retval;
#endif
}

/**
 * @brief 获取DMA双缓冲区激活缓冲区
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false DMA正在读取/填充缓冲区0
 *         true DMA正在读取/填充缓冲区1
 */
KF_INLINE bool DMA_LL_GetMEDoubleBufferActiveState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHSTA_ADDR);
        regValue &= HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_BUFFER_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_BUFFER_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHSTA_ADDR);
        regValue &= HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_BUFFER_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_BUFFER_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0CHSTA.bits.BUFFER)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1CHSTA.bits.BUFFER)));
    }

    return retval;
#endif
}

/**
 * @brief 获取DMA双缓冲区冻结缓冲区
 *
 * @param Index 搬运引擎索引
 *          DMA_MOVE_ENGINE_INDEX_0 搬运引擎0
 *          DMA_MOVE_ENGINE_INDEX_1 搬运引擎1
 *
 * @return bool
 * @retval false 缓冲区未冻结
 *         true 缓冲区已冻结
 */
KF_INLINE bool DMA_LL_GetMEDoubleBufferFrozenState(Dma_MoveEngineIndex_t Index)
{
    KF_DMA_ASSERT(CHECK_DMA_MOVE_ENGINE_INDEX(Index));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        regValue = REG_READ(HWIO_DMA_ME0CHSTA_ADDR);
        regValue &= HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_FROZEN_MASK;
        regValue = regValue >> HWIO_DMA_ME0CHSTA_DMA_ME0CHSTA_FROZEN_SHFT;
    }
    else
    {
        regValue = REG_READ(HWIO_DMA_ME1CHSTA_ADDR);
        regValue &= HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_FROZEN_MASK;
        regValue = regValue >> HWIO_DMA_ME1CHSTA_DMA_ME1CHSTA_FROZEN_SHFT;
    }

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    if (DMA_MOVE_ENGINE_INDEX_0 == Index)
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME0CHSTA.bits.FROZEN)));
    }
    else
    {
        retval = ((bool)(REG_READ(DMA_PTR->ME1CHSTA.bits.FROZEN)));
    }

    return retval;
#endif
}

/**
 * @brief 清除DMA通道中止请求和中止告知.
 *
 * @param Channel DMA通道索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_ClearChannelHaltRequestAndAcknowledge(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_TSR0_DMA_TSR0_HLTIC_MASK;
    regValue |= true << HWIO_DMA_TSR0_DMA_TSR0_HLTIC_SHFT;
    REG_WRITE(HWIO_DMA_TSR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->TSR[Channel].bits.HLTIC, true);
#endif
}

/**
 * @brief 清除DMA通道处理/传输请求丢失.
 *
 * @param Channel DMA通道索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_ClearChannelTransferRequestLostState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_TSR0_DMA_TSR0_CTL_MASK;
    regValue |= true << HWIO_DMA_TSR0_DMA_TSR0_CTL_SHFT;
    REG_WRITE(HWIO_DMA_TSR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->TSR[Channel].bits.CTL, true);
#endif
}

/**
 * @brief 设置DMA通道硬件处理请求.
 *
 * @param Channel DMA通道索引
 * @param State 是否使能
 *          false 禁用DMA通道硬件处理请求
 *          true 使能DMA通道硬件处理请求
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelHardwareTransactionRequestEnabled(Dma_ChannelIndex_t Channel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    if (State)
    {
        regValue &= ~HWIO_DMA_TSR0_DMA_TSR0_ECH_MASK;
        regValue |= true << HWIO_DMA_TSR0_DMA_TSR0_ECH_SHFT;
    }
    else
    {
        regValue &= ~HWIO_DMA_TSR0_DMA_TSR0_DCH_MASK;
        regValue |= true << HWIO_DMA_TSR0_DMA_TSR0_DCH_SHFT;
    }
    REG_WRITE(HWIO_DMA_TSR0_ADDR + (Channel << 2U), regValue);
#else
    if (State)
    {
        REG_WRITE(DMA_PTR->TSR[Channel].bits.ECH, true);
    }
    else
    {
        REG_WRITE(DMA_PTR->TSR[Channel].bits.DCH, true);
    }
#endif
}

/**
 * @brief 获取DMA通道中止告知.
 *
 * @param Channel DMA通道索引
 *
 * @return bool 中止状态
 *          false DMA通道未中止
 *          true DMA通道已中止
 */
KF_INLINE bool DMA_LL_GetChannelHaltState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_TSR0_DMA_TSR0_HLTACK_MASK;
    regValue = regValue >> HWIO_DMA_TSR0_DMA_TSR0_HLTACK_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->TSR[Channel].bits.HLTACK)));
#endif
}

/**
 * @brief 设置DMA通道中止请求.
 *
 * @param Channel DMA通道索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelHaltRequest(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_TSR0_DMA_TSR0_HLTREQ_MASK;
    regValue |= true << HWIO_DMA_TSR0_DMA_TSR0_HLTREQ_SHFT;
    REG_WRITE(HWIO_DMA_TSR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->TSR[Channel].bits.HLTREQ, true);
#endif
}

/**
 * @brief 设置DMA通道处理/传输请求丢失中断.
 *
 * @param Channel DMA通道索引
 * @param bool 中断使能状态
 *          false 禁用中断
 *          true 使能中断
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelTransferRequestLostIntrEnabled(Dma_ChannelIndex_t Channel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_TSR0_DMA_TSR0_ETRL_MASK;
    regValue |= State << HWIO_DMA_TSR0_DMA_TSR0_ETRL_SHFT;
    REG_WRITE(HWIO_DMA_TSR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->TSR[Channel].bits.ETRL, State);
#endif
}

/**
 * @brief 获取DMA通道处理请求状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool 是否有请求
 *          false DMA通道无DMA请求等待响应
 *          true DMA通道的DMA请求正在等待响应
 */
KF_INLINE bool DMA_LL_GetChannelTransactionRequestState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_TSR0_DMA_TSR0_CH_MASK;
    regValue = regValue >> HWIO_DMA_TSR0_DMA_TSR0_CH_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->TSR[Channel].bits.CH)));
#endif
}

/**
 * @brief 获取DMA通道处理/传输请求丢失状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool 是否有丢包事件
 *          false DMA通道无DMA传输丢包事件
 *          true DMA通道探测到DMA传输丢包事件
 */
KF_INLINE bool DMA_LL_GetChannelTransferRequestLostState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_TSR0_DMA_TSR0_TRL_MASK;
    regValue = regValue >> HWIO_DMA_TSR0_DMA_TSR0_TRL_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->TSR[Channel].bits.TRL)));
#endif
}

/**
 * @brief 获取DMA通道硬件请求使能位状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool
 *          false 通道硬件请求禁用
 *          true 通道硬件请求使能
 */
KF_INLINE bool DMA_LL_GetChannelHardwareRequestEnabledState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_TSR0_DMA_TSR0_HTRE_MASK;
    regValue = regValue >> HWIO_DMA_TSR0_DMA_TSR0_HTRE_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->TSR[Channel].bits.HTRE)));
#endif
}

/**
 * @brief 获取通道状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool
 */
KF_INLINE bool DMA_LL_GetChannelResetStatus(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_TSR0_DMA_TSR0_RST_MASK;
    regValue = regValue >> HWIO_DMA_TSR0_DMA_TSR0_RST_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->TSR[Channel].bits.RST)));
#endif
}

/**
 * @brief 复位通道.
 *
 * @param Channel DMA通道索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_ResetChannel(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_TSR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_TSR0_DMA_TSR0_RST_MASK;
    regValue |= true << HWIO_DMA_TSR0_DMA_TSR0_RST_SHFT;

    REG_WRITE(HWIO_DMA_TSR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->TSR[Channel].bits.RST, true);
#endif
}

/**
 * @brief 获取DMA读搬运数据的计算校验和.
 *
 * @param Channel DMA通道索引
 *
 * @return uint32_t DMA读搬运数据的计算校验和
 */
KF_INLINE uint32_t DMA_LL_GetChannelReadDataCrc(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_RDCRC0_ADDR + (Channel << 2U));

    return regValue;
#else
    return ((uint32_t)(REG_READ(DMA_PTR->CHAINFO[Channel].RDCRC.reg)));
#endif
}

/**
 * @brief 设置DMA读搬运数据的计算校验和初始值.
 *
 * @param Channel DMA通道索引
 * @param Value 初始值
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelReadDataCrcInitValue(Dma_ChannelIndex_t Channel, uint32_t Value)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    REG_WRITE(HWIO_DMA_RDCRC0_ADDR + (Channel << 2U), Value);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].RDCRC.reg, Value);
#endif
}

/**
 * @brief 获取源地址和目标地址计算校验和.
 *
 * @param Channel DMA通道索引
 *
 * @return uint32_t DMA搬运地址的计算校验和
 */
KF_INLINE uint32_t DMA_LL_GetChannelSrcAndDestAddrCrc(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_SDCRC0_ADDR + (Channel << 2U));

    return regValue;
#else
    return ((uint32_t)(REG_READ(DMA_PTR->CHAINFO[Channel].SDCRC.reg)));
#endif
}

/**
 * @brief 设置源地址和目标地址的计算校验和初始值.
 *
 * @param Channel DMA通道索引
 * @param Value 初始值
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelSrcAndDestAddrCrcInitValuie(Dma_ChannelIndex_t Channel, uint32_t Value)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    REG_WRITE(HWIO_DMA_SDCRC0_ADDR + (Channel << 2U), Value);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].SDCRC.reg, Value);
#endif
}

/**
 * @brief 获取源地址.
 *
 * @param Channel DMA通道索引
 *
 * @return uint32_t 目标地址
 */
KF_INLINE uint32_t DMA_LL_GetChannelSrcAddr(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_SADR0_ADDR + (Channel << 2U));

    return regValue;
#else
    return ((uint32_t)(REG_READ(DMA_PTR->CHAINFO[Channel].SADR.reg)));
#endif
}

/**
 * @brief 设置源地址.
 *
 * @param Channel DMA通道索引
 * @param Addr 源地址
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelSrcAddr(Dma_ChannelIndex_t Channel, uint32_t Addr)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    REG_WRITE(HWIO_DMA_SADR0_ADDR + (Channel << 2U), Addr);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].SADR.reg, Addr);
#endif
}

/**
 * @brief 获取目标地址.
 *
 * @param Channel DMA通道索引
 *
 * @return uint32_t 目标地址
 */
KF_INLINE uint32_t DMA_LL_GetChannelDestAddr(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_DADR0_ADDR + (Channel << 2U));

    return regValue;
#else
    return ((uint32_t)(REG_READ(DMA_PTR->CHAINFO[Channel].DADR.reg)));
#endif
}

/**
 * @brief 设置目标地址.
 *
 * @param Channel DMA通道索引
 * @param Addr 目标地址
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelDestAddr(Dma_ChannelIndex_t Channel, uint32_t Addr)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    REG_WRITE(HWIO_DMA_DADR0_ADDR + (Channel << 2U), Addr);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].DADR.reg, Addr);
#endif
}

/**
 * @brief 设置源地址偏移系数.
 *
 * @param Channel DMA通道索引
 * @param Select 偏移量
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelSrcAddrOffsetStep(Dma_ChannelIndex_t Channel, Dma_AddrOffsetStep_t Select)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_ADDR_OFFSET_STEP(Select));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_SMF_MASK;
    regValue |= Select << HWIO_DMA_ADICR0_DMA_ADICR0_SMF_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.SMF, Select);
#endif
}

/**
 * @brief 设置源地址偏移方向.
 *
 * @param Channel DMA通道索引
 * @param Dir 偏移方向
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelSrcAddrOffsetDir(Dma_ChannelIndex_t Channel, Dma_AddrOffsetDir_t Dir)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_ADDR_OFFSET_DIR(Dir));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_INCS_MASK;
    regValue |= Dir << HWIO_DMA_ADICR0_DMA_ADICR0_INCS_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.INCS, Dir);
#endif
}

/**
 * @brief 设置目标地址偏移系数.
 *
 * @param Channel DMA通道索引
 * @param Select 偏移量
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelDestAddrOffsetStep(Dma_ChannelIndex_t Channel, Dma_AddrOffsetStep_t Select)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_ADDR_OFFSET_STEP(Select));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_DMF_MASK;
    regValue |= Select << HWIO_DMA_ADICR0_DMA_ADICR0_DMF_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.DMF, Select);
#endif
}

/**
 * @brief 设置目标地址偏移方向.
 *
 * @param Channel DMA通道索引
 * @param Dir 偏移方向
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelDestAddrOffsetDir(Dma_ChannelIndex_t Channel, Dma_AddrOffsetDir_t Dir)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_ADDR_OFFSET_DIR(Dir));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_INCD_MASK;
    regValue |= Dir << HWIO_DMA_ADICR0_DMA_ADICR0_INCD_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.INCD, Dir);
#endif
}

/**
 * @brief 设置循环缓冲区源地址长度.
 *
 * @param Channel DMA通道索引
 * @param Bit 不更新源地址的DADR[31:Bit]的起始位
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelSrcCircularBufferSize(Dma_ChannelIndex_t Channel, Dma_CircularBuffer_t Bit)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_CIRCULAR_BUFFER(Bit));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_CBLS_MASK;
    regValue |= Bit << HWIO_DMA_ADICR0_DMA_ADICR0_CBLS_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.CBLS, Bit);
#endif
}

/**
 * @brief 设置循环缓冲区目标地址长度.
 *
 * @param Channel DMA通道索引
 * @param Bit 不更新目标地址的DADR[31:Bit]的起始位
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelDestCircularBufferSize(Dma_ChannelIndex_t Channel, Dma_CircularBuffer_t Bit)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_CIRCULAR_BUFFER(Bit));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_CBLD_MASK;
    regValue |= Bit << HWIO_DMA_ADICR0_DMA_ADICR0_CBLD_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.CBLD, Bit);
#endif
}

/**
 * @brief 设置影子控制模式.
 *
 * @param Channel DMA通道索引
 * @param Select 控制模式
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelShadowCtrl(Dma_ChannelIndex_t Channel, Dma_ShadowCtrl_t Select)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_SHADOW_CTRL(Select));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_SHCT_MASK;
    regValue |= Select << HWIO_DMA_ADICR0_DMA_ADICR0_SHCT_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.SHCT, Select);
#endif
}

/**
 * @brief 设置源缓存循环使能.
 *
 * @param Channel DMA通道索引
 * @param State 是否使能
 *          false 禁用
 *          true 使能
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelSrcCircularBufferEnabled(Dma_ChannelIndex_t Channel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_SCBE_MASK;
    regValue |= State << HWIO_DMA_ADICR0_DMA_ADICR0_SCBE_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.SCBE, State);
#endif
}

/**
 * @brief 设置目标缓存循环使能.
 *
 * @param Channel DMA通道索引
 * @param State 是否使能
 *          false 禁用
 *          true 使能
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelDestCircularBufferEnabled(Dma_ChannelIndex_t Channel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_DCBE_MASK;
    regValue |= State << HWIO_DMA_ADICR0_DMA_ADICR0_DCBE_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.DCBE, State);
#endif
}

/**
 * @brief 设置时间戳使能.
 *
 * @param Channel DMA通道索引
 * @param State 是否使能
 *          false 禁用
 *          true 使能
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelTimeStampEnabled(Dma_ChannelIndex_t Channel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_STAMP_MASK;
    regValue |= State << HWIO_DMA_ADICR0_DMA_ADICR0_STAMP_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.STAMP, State);
#endif
}

/**
 * @brief 设置源缓存区回环使能.
 *
 * @param Channel DMA通道索引
 * @param State 是否使能
 *          false 禁用
 *          true 使能
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelWrapSrcBufferEnabled(Dma_ChannelIndex_t Channel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_WRPSE_MASK;
    regValue |= State << HWIO_DMA_ADICR0_DMA_ADICR0_WRPSE_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.WRPSE, State);
#endif
}

/**
 * @brief 设置目标缓存区回环使能.
 *
 * @param Channel DMA通道索引
 * @param State 是否使能
 *          false 禁用
 *          true 使能
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelWrapDestBufferEnabled(Dma_ChannelIndex_t Channel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_WRPDE_MASK;
    regValue |= State << HWIO_DMA_ADICR0_DMA_ADICR0_WRPDE_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.WRPDE, State);
#endif
}

/**
 * @brief 中断控制.
 *
 * @param Channel DMA通道索引
 * @param Select 控制模式
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelIntrCtrl(Dma_ChannelIndex_t Channel, Dma_IntrCtrl_t Select)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_INTR_CTRL(Select));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_INTCT_MASK;
    regValue |= Select << HWIO_DMA_ADICR0_DMA_ADICR0_INTCT_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.INTCT, Select);
#endif
}

/**
 * @brief 中断上升阈值.
 *
 * @param Channel DMA通道索引
 * @param Value 阈值
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelIntrRaiseDetectValue(Dma_ChannelIndex_t Channel, uint8_t Value)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_INTR_RAISE_DETECT_VALUE(Value));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_ADICR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_ADICR0_DMA_ADICR0_IRDV_MASK;
    regValue |= Value << HWIO_DMA_ADICR0_DMA_ADICR0_IRDV_SHFT;
    REG_WRITE(HWIO_DMA_ADICR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].ADICR.bits.IRDV, Value);
#endif
}

/**
 * @brief 外设请求选择.
 *
 * @param Channel DMA通道索引
 * @param Select 外设请求选择
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelReqSrc(Dma_ChannelIndex_t Channel, Dma_ReqSrc_t Select)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_PERIPHERAL_REQUEST(Select));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CHCFGR0_DMA_CHCFGR0_PRSEL_MASK;
    regValue |= Select << HWIO_DMA_CHCFGR0_DMA_CHCFGR0_PRSEL_SHFT;
    REG_WRITE(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CHCFGR.bits.PRSEL, Select);
#endif
}

/**
 * @brief CRC数据交换模式.
 *
 * @param Channel DMA通道索引
 * @param Select CRC数据交换模式
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelCRCReverseCtrl(Dma_ChannelIndex_t Channel, Dma_ReverseCtrl_t Select)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_REVERSE_CTRL(Select));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CHCFGR0_DMA_CHCFGR0_SWAP_MASK;
    regValue |= Select << HWIO_DMA_CHCFGR0_DMA_CHCFGR0_SWAP_SHFT;
    REG_WRITE(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CHCFGR.bits.SWAP, Select);
#endif
}

/**
 * @brief 数据对照模式选择.
 *
 * @param Channel DMA通道索引
 * @param Pattern 模式
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelPatternMode(Dma_ChannelIndex_t Channel, Dma_PatternMode_t Pattern)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_PATTERN_MODE(Pattern));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CHCFGR0_DMA_CHCFGR0_PRTSEL_MASK;
    regValue |= Pattern << HWIO_DMA_CHCFGR0_DMA_CHCFGR0_PRTSEL_SHFT;
    REG_WRITE(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CHCFGR.bits.PRTSEL, Pattern);
#endif
}

/**
 * @brief 设置DMA传输数据宽度.
 *
 * @param Channel DMA通道索引
 * @param Width 传输数据宽度
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelDataWidth(Dma_ChannelIndex_t Channel, Dma_ChannelDataWidth_t Width)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_DATA_WIDTH(Width));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CHCFGR0_DMA_CHCFGR0_CHDW_MASK;
    regValue |= Width << HWIO_DMA_CHCFGR0_DMA_CHCFGR0_CHDW_SHFT;
    REG_WRITE(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CHCFGR.bits.CHDW, Width);
#endif
}

/**
 * @brief 设置通道操作模式.
 *
 * @param Channel DMA通道索引
 * @param Mode 连续或单次传输模式
 *          true 连续模式,1个DMA处理完成后,TSR.HTRE仍然保持为1
 *          false 单次传输模式,1个DMA处理完成后,DMA通道会禁用后面的硬件请求
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelOperationMode(Dma_ChannelIndex_t Channel, Dma_ChannelOperationMode_t Mode)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_OPERATION_MODE(Mode));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CHCFGR0_DMA_CHCFGR0_CHMODE_MASK;
    regValue |= Mode << HWIO_DMA_CHCFGR0_DMA_CHCFGR0_CHMODE_SHFT;
    REG_WRITE(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CHCFGR.bits.CHMODE, Mode);
#endif
}

/**
 * @brief 设置DMA通道重置请求控制.
 *
 * @param Channel DMA通道索引
 * @param State 重置请求控制
 *          true CHSTA.TCNT为零并且单次transaction的所有数据传输完成时TSR.CH才重置. 1个DMA请求开启一次完整的transaction
 *          false transfer后将TSR.CH重置. 每次transfer都要DMA请求
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelResetRequestEnabled(Dma_ChannelIndex_t Channel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CHCFGR0_DMA_CHCFGR0_RROAT_MASK;
    regValue |= State << HWIO_DMA_CHCFGR0_DMA_CHCFGR0_RROAT_SHFT;
    REG_WRITE(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CHCFGR.bits.RROAT, State);
#endif
}

/**
 * @brief 设置块传输模式.
 *
 * @param Channel DMA通道索引
 * @param Mode 块传输模式
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelBlockMode(Dma_ChannelIndex_t Channel, Dma_BlockMode_t Mode)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_BLOCK_MODE(Mode));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CHCFGR0_DMA_CHCFGR0_BLKM_MASK;
    regValue |= Mode << HWIO_DMA_CHCFGR0_DMA_CHCFGR0_BLKM_SHFT;
    REG_WRITE(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CHCFGR.bits.BLKM, Mode);
#endif
}

/**
 * @brief 设置传输重载值.
 *
 * @param Channel DMA通道索引
 * @param Value 重载值
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelTransferReloadValue(Dma_ChannelIndex_t Channel, uint16_t Value)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));
    KF_DMA_ASSERT(CHECK_DMA_TRANSFER_RELOAD_VALUE(Value));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CHCFGR0_DMA_CHCFGR0_TREL_MASK;
    regValue |= Value << HWIO_DMA_CHCFGR0_DMA_CHCFGR0_TREL_SHFT;
    REG_WRITE(HWIO_DMA_CHCFGR0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CHCFGR.bits.TREL, Value);
#endif
}

/**
 * @brief 设置影子地址.
 *
 * @param Channel DMA通道索引
 * @param Addr 地址数据
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetShadowAddr(Dma_ChannelIndex_t Channel, uint32_t Addr)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    REG_WRITE(HWIO_DMA_SHADR0_ADDR + (Channel << 2U), Addr);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].SHADR.reg, Addr);
#endif
}

/**
 * @brief DMA传输发起软件请求.
 *
 * @param Channel DMA通道索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetTransactionRequestEnabled(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CTLSTA0_DMA_CTLSTA0_SCH_MASK;
    regValue |= true << HWIO_DMA_CTLSTA0_DMA_CTLSTA0_SCH_SHFT;
    REG_WRITE(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.SCH, true);
#endif
}

/**
 * @brief DMA通道设置中断触发.
 *
 * @param Channel DMA通道索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelIntrTriggerEnabled(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CTLSTA0_DMA_CTLSTA0_SIT_MASK;
    regValue |= true << HWIO_DMA_CTLSTA0_DMA_CTLSTA0_SIT_SHFT;
    REG_WRITE(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.SIT, true);
#endif
}

/**
 * @brief 清除DMA中断.
 *
 * @param Channel DMA通道索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_ClearChannelIntrFlag(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CTLSTA0_DMA_CTLSTA0_CICH_MASK;
    regValue |= true << HWIO_DMA_CTLSTA0_DMA_CTLSTA0_CICH_SHFT;
    REG_WRITE(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.CICH, true);
#endif
}

/**
 * @brief 清除回环缓存区中断.
 *
 * @param Channel DMA通道索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_ClearWrapBufferIntrFlag(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CTLSTA0_DMA_CTLSTA0_CWRP_MASK;
    regValue |= true << HWIO_DMA_CTLSTA0_DMA_CTLSTA0_CWRP_SHFT;
    REG_WRITE(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.CWRP, true);
#endif
}

/**
 * @brief 设置DMA双缓冲区切换.
 *
 * @param Channel DMA通道索引
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetSwitchDoubleBuffer(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CTLSTA0_DMA_CTLSTA0_SWB_MASK;
    regValue |= true << HWIO_DMA_CTLSTA0_DMA_CTLSTA0_SWB_SHFT;
    REG_WRITE(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.SWB, true);
#endif
}

/**
 * @brief 设置DMA双缓冲区冻结状态.
 *
 * @param Channel DMA通道索引
 * @param State 是否冻结双缓存区
 *          true 冻结双缓存区
 *          false 不冻结双缓存区
 *
 * @return void
 */
KF_INLINE void DMA_LL_SetChannelDoubleBufferFrozenEnabled(Dma_ChannelIndex_t Channel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= ~HWIO_DMA_CTLSTA0_DMA_CTLSTA0_FROZEN_MASK;
    regValue |= State << HWIO_DMA_CTLSTA0_DMA_CTLSTA0_FROZEN_SHFT;
    REG_WRITE(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U), regValue);
#else
    REG_WRITE(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.FROZEN, State);
#endif
}

/**
 * @brief 获取通道DMA双缓冲区冻结缓冲区
 *
 * @return bool
 * @retval false 缓冲区未冻结
 *         true 缓冲区已冻结
 */
KF_INLINE bool DMA_LL_GetChannelDoubleBufferFrozenState(Dma_ChannelIndex_t Channel)
{
#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_CTLSTA0_DMA_CTLSTA0_FROZEN_MASK;
    regValue = regValue >> HWIO_DMA_CTLSTA0_DMA_CTLSTA0_FROZEN_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    bool retval = false;

    retval = ((bool)(REG_READ(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.FROZEN)));

    return retval;
#endif
}

/**
 * @brief 获取DMA双缓冲区激活状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool
 * @retval true DMA正在读取/填充缓冲区1
 *         false DMA正在读取/填充缓冲区0
 */
KF_INLINE bool DMA_LL_GetChannelDoubleBufferActiveState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_CTLSTA0_DMA_CTLSTA0_BUFFER_MASK;
    regValue = regValue >> HWIO_DMA_CTLSTA0_DMA_CTLSTA0_BUFFER_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.BUFFER)));
#endif
}

/**
 * @brief 获取通道数据对照状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool
 * @retval true 探测到数据对照
 *         false 未探测到数据对照
 */
KF_INLINE bool DMA_LL_GetChannelPatternDetectionState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_CTLSTA0_DMA_CTLSTA0_IPM_MASK;
    regValue = regValue >> HWIO_DMA_CTLSTA0_DMA_CTLSTA0_IPM_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.IPM)));
#endif
}

/**
 * @brief 获取通道的中断状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool
 * @retval true 该通道发现中断
 *         false 该通道未发现中断
 */
KF_INLINE bool DMA_LL_GetChannelIntrState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_CTLSTA0_DMA_CTLSTA0_ICH_MASK;
    regValue = regValue >> HWIO_DMA_CTLSTA0_DMA_CTLSTA0_ICH_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.ICH)));
#endif
}

/**
 * @brief 获取通道目标缓冲区回环状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool
 * @retval true 目标缓冲区发生回环
 *         false 目标缓冲区未发生回环
 */
KF_INLINE bool DMA_LL_GetChannelWrapDestBufferState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_CTLSTA0_DMA_CTLSTA0_WRPD_MASK;
    regValue = regValue >> HWIO_DMA_CTLSTA0_DMA_CTLSTA0_WRPD_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.WRPD)));
#endif
}

/**
 * @brief 获取通道源缓冲区回环状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool
 * @retval true 源缓冲区发生回环
 *         false 源缓冲区未发生回环
 */
KF_INLINE bool DMA_LL_GetChannelWrapSrcBufferState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_CTLSTA0_DMA_CTLSTA0_WRPS_MASK;
    regValue = regValue >> HWIO_DMA_CTLSTA0_DMA_CTLSTA0_WRPS_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.WRPS)));
#endif
}

/**
 * @brief 获取上一次数据对照状态.
 *
 * @param Channel DMA通道索引
 *
 * @return bool
 * @retval true 上一次DMA读搬运已探测到数据对照
 *         false 上一次DMA读搬运未探测到数据对照
 */
KF_INLINE bool DMA_LL_GetChannelLastPatternDetectionState(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_CTLSTA0_DMA_CTLSTA0_LXO_MASK;
    regValue = regValue >> HWIO_DMA_CTLSTA0_DMA_CTLSTA0_LXO_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.LXO)));
#endif
}

/**
 * @brief 获取DMA通道传输计数值.
 *
 * @param Channel DMA通道索引
 *
 * @return uint32_t
 */
KF_INLINE uint32_t DMA_LL_GetChannelTransferCounter(Dma_ChannelIndex_t Channel)
{
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL_INDEX(Channel));

#ifdef SIMULATION
    uint32_t regValue = 0U;

    regValue = REG_READ(HWIO_DMA_CTLSTA0_ADDR + (Channel << 2U));
    regValue &= HWIO_DMA_CTLSTA0_DMA_CTLSTA0_TCNT_MASK;
    regValue = regValue >> HWIO_DMA_CTLSTA0_DMA_CTLSTA0_TCNT_SHFT;

    return regValue;
#else
    return ((uint32_t)(REG_READ(DMA_PTR->CHAINFO[Channel].CTLSTA.bits.TCNT)));
#endif
}

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
