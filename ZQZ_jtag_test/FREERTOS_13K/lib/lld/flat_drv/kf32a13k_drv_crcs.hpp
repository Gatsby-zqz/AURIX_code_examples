/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_crcs.h
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
 *                              REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2023-12-20  |V1.0     |Sun Wanyu  | New Creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_CRCS_H_
#define KF32A13K_DRV_CRCS_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_crcs.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_CRCS_ASSERT
#include "dev_assert.h"
#define KF_DRV_CRCS_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_CRCS_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION
#define CRC_MODULE_BASE_ADDR CRCS_ADDR
#include "kf32a13k_reg_simulation_crcs.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    CRCS_TAG_ID_0  = 0x00000000,
    CRCS_TAG_ID_1  = 0x00000001,
    CRCS_TAG_ID_2  = 0x00000002,
    CRCS_TAG_ID_3  = 0x00000003,
    CRCS_TAG_ID_4  = 0x00000004,
    CRCS_TAG_ID_5  = 0x00000005,
    CRCS_TAG_ID_6  = 0x00000006,
    CRCS_TAG_ID_7  = 0x00000007,
    CRCS_TAG_ID_8  = 0x00000008,
    CRCS_TAG_ID_9  = 0x00000009,
    CRCS_TAG_ID_10 = 0x0000000A,
    CRCS_TAG_ID_11 = 0x0000000B,
    CRCS_TAG_ID_12 = 0x0000000C,
    CRCS_TAG_ID_13 = 0x0000000D,
    CRCS_TAG_ID_14 = 0x0000000E,
    CRCS_TAG_ID_15 = 0x0000000F,
    CRCS_TAG_ID_16 = 0x00000010,
    CRCS_TAG_ID_17 = 0x00000011,
    CRCS_TAG_ID_18 = 0x00000012,
    CRCS_TAG_ID_19 = 0x00000013,
    CRCS_TAG_ID_20 = 0x00000014,
    CRCS_TAG_ID_21 = 0x00000015,
    CRCS_TAG_ID_22 = 0x00000016,
    CRCS_TAG_ID_23 = 0x00000017,
    CRCS_TAG_ID_24 = 0x00000018,
    CRCS_TAG_ID_25 = 0x00000019,
    CRCS_TAG_ID_26 = 0x0000001A,
    CRCS_TAG_ID_27 = 0x0000001B,
    CRCS_TAG_ID_28 = 0x0000001C,
    CRCS_TAG_ID_29 = 0x0000001D,
    CRCS_TAG_ID_30 = 0x0000001E,
    CRCS_TAG_ID_31 = 0x0000001F
} Crcs_TagId_t;

typedef enum
{
    CRCS_CHANNEL_INDEX_0 = 0x00000000,
    CRCS_CHANNEL_INDEX_1 = 0x00000001,
    CRCS_CHANNEL_INDEX_2 = 0x00000002,
    CRCS_CHANNEL_INDEX_3 = 0x00000003,
    CRCS_CHANNEL_INDEX_4 = 0x00000004,
    CRCS_CHANNEL_INDEX_5 = 0x00000005,
    CRCS_CHANNEL_INDEX_6 = 0x00000006,
    CRCS_CHANNEL_INDEX_7 = 0x00000007
} Crcs_ChannelIndex_t;

typedef enum
{
    CRCS_MODULE_SEL_0 = 0x00000000,
    CRCS_MODULE_SEL_1 = 0x00000001,
    CRCS_MODULE_SEL_2 = 0x00000002,
    CRCS_MODULE_SEL_3 = 0x00000003,
    CRCS_MODULE_SEL_4 = 0x00000004,
    CRCS_MODULE_SEL_5 = 0x00000005,
    CRCS_MODULE_SEL_6 = 0x00000006
} Crcs_ModuleSel_t;

typedef enum
{
    CRCS_REVERSE_CTRL_NONE                  = 0x00000000,
    CRCS_REVERSE_CTRL_RESULT_WORD_DATA_BYTE = 0x00000002,
} Crcs_ReverseControl_t;

typedef enum
{
    CRCS_FORMAT_CONTROL_BIT8,
    CRCS_FORMAT_CONTROL_BIT16,
    CRCS_FORMAT_CONTROL_BIT24,
    CRCS_FORMAT_CONTROL_BIT32,
} Crcs_FormatControl_t;

typedef enum
{
    CRCS_CONFIG_REG_ERRORMATCH_INTEN     = 0x00000001,
    CRCS_CHECK_REG_ERRORMATCH_INTEN      = 0x00000002,
    CRCS_POLYNOMIAL_REG_ERRORMATCH_INTEN = 0x00000003,
    CRCS_INITIALVAL_REG_ERRORMATCH_INTEN = 0x00000004,
    CRCS_RESULTXOR_REG_ERRORMATCH_INTEN  = 0x00000005,
    CRCS_DATA_REG_ERRORMATCH_INTEN       = 0x00000006,
    CRCS_IDATA_REG_ERRORMATCH_INTEN      = 0x00000007
} Crcs_ErrorMatchIntEn_t;

typedef enum
{
    CRCS_COMPARE_ERRORFLAG        = 0x00000000,
    CRCS_CHECK_REG_ERRORFLAG      = 0x00000001,
    CRCS_LENGTH_ERRORFLAG         = 0x00000002,
    CRC_CONFIG_REG_ERRORFLAG      = 0x00000003,
    CRCS_POLYNOMIAL_REG_ERRORFLAG = 0x00000004,
    CRCS_INITIALVAL_REG_ERRORFLAG = 0x00000005,
    CRCS_RESULTXOR_REG_ERRORFLAG  = 0x00000006,
    CRCS_DATA_REG_ERRORFLAG       = 0x00000007,
    CRCS_IDATA_REG_ERRORFLAG      = 0x00000008
} Crcs_ErrorFlag_t;

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief 获取CRCs模块禁止状态
 *
 *
 * @param Module
 * @retval bool  模块禁止状态
 *         false 模块已使能
 *         true  模块已禁止
 */
KF_INLINE bool Crcs_LL_GetModuleDisableStatus(Crcs_RegisterMap_t *const Module)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_CLC_ADDR);
    regValue &= HWIO_CRC_CLC_CRC_CLC_DISS_MASK;
    regValue = regValue >> HWIO_CRC_CLC_CRC_CLC_DISS_SHFT;

    return ((regValue > 0U) ? true : false);
#else
    return ((bool)(REG_READ(Module->CRC_CLC.bits.DISS)));
#endif
}

/**
 * @brief 配置CRCs模块禁止控制位
 *
 *
 * @param Module
 * @param Status bool 模块禁止控制位状态
 *        false  无操作
 *        true   禁止模块
 * @retval void
 */
KF_INLINE void Crcs_LL_SetModuleDisableStatus(Crcs_RegisterMap_t *const Module, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_CLC_ADDR);
    regValue &= ~HWIO_CRC_CLC_CRC_CLC_DISR_MASK;
    regValue |= Status << HWIO_CRC_CLC_CRC_CLC_DISR_SHFT;
    REG_WRITE(HWIO_CRC_CLC_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CRC_CLC.bits.DISR, Status);
#endif
}

/**
 * @brief 获取CRCs模块编号
 *
 *
 * @param Module
 * @retval uint32_t 模块编号
 */
KF_INLINE uint32_t Crcs_LL_GetModuleNumber(Crcs_RegisterMap_t *const Module)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_ID_ADDR);
    regValue &= HWIO_CRC_ID_CRC_ID_MOD_NUM_MASK;
    regValue = regValue >> HWIO_CRC_ID_CRC_ID_MOD_NUM_SHFT;

    return regValue;
#else
    return (Module->CRC_INFO.bits.MOD_NUMBER);
#endif
}

/**
 * @brief 获取CRCs模块类型
 *
 *
 * @param Module
 * @retval uint32_t 模块类型
 */
KF_INLINE uint32_t Crcs_LL_GetModuleType(Crcs_RegisterMap_t *const Module)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_ID_ADDR);
    regValue &= HWIO_CRC_ID_CRC_ID_MOD_TYPE_MASK;
    regValue = regValue >> HWIO_CRC_ID_CRC_ID_MOD_TYPE_SHFT;

    return regValue;
#else
    return (Module->CRC_INFO.bits.MOD_TYPE);
#endif
}

/**
 * @brief 获取CRCs模块版本
 *
 *
 * @param Module
 * @retval uint32_t 模块版本
 */
KF_INLINE uint32_t Crcs_LL_GetModuleVersion(Crcs_RegisterMap_t *const Module)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_ID_ADDR);
    regValue &= HWIO_CRC_ID_CRC_ID_MOD_REV_MASK;
    regValue = regValue >> HWIO_CRC_ID_CRC_ID_MOD_REV_SHFT;

    return regValue;
#else
    return (Module->CRC_INFO.bits.MOD_REV);
#endif
}

/**
 * @brief 配置CRCs模块复位状态清除位
 *
 *
 * @param Module
 * @param Status bool 模块复位状态清除位状态
 *        false  无操作
 *        true   清零
 * @retval void
 */
KF_INLINE void Crcs_LL_SetResetClearStatus(Crcs_RegisterMap_t *const Module, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_RSTCLR_ADDR);
    regValue &= ~HWIO_CRC_RSTCLR_CRC_RSTCLR_CLR_MASK;
    regValue |= Status << HWIO_CRC_RSTCLR_CRC_RSTCLR_CLR_SHFT;

    REG_WRITE(HWIO_CRC_RSTCLR_ADDR, regValue);
#else
    REG_WRITE(Module->CRC_RSTCLR.bits.CLR, Status);
#endif
}

/**
 * @brief 配置CRCs模块复位请求位
 *
 *
 * @param Module
 * @param Status bool 模块复位请求位状态
 *        false  无操作
 *        true   使能模块复位
 * @retval void
 */
KF_INLINE void Crcs_LL_SetResetStatus(Crcs_RegisterMap_t *const Module, const bool Status)
{
    // TODO: 模块复位需要将两个寄存器的RST都置位吗？
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_RST0_ADDR);
    regValue &= ~HWIO_CRC_RST0_CRC_RST0_RST_MASK;
    regValue |= Status << HWIO_CRC_RST0_CRC_RST0_RST_SHFT;
    REG_WRITE(HWIO_CRC_RST0_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CRC_RST0.bits.RST, Status);
#endif
#ifdef SIMULATION
    regValue = REG_READ(HWIO_CRC_RST1_ADDR);
    regValue &= ~HWIO_CRC_RST1_CRC_RST1_RST_MASK;
    regValue |= Status << HWIO_CRC_RST1_CRC_RST1_RST_SHFT;
    REG_WRITE(HWIO_CRC_RST1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CRC_RST1.bits.RST, Status);
#endif
}

/**
 * @brief 获取CRCs模块复位状态
 *
 *
 * @param Module
 * @retval bool   CRCs模块复位状态
 *         false  无操作
 *         true   使能模块复位
 */
KF_INLINE bool Crcs_LL_GetResetStatus(Crcs_RegisterMap_t *const Module)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_RST0_ADDR);
    regValue &= HWIO_CRC_RST0_CRC_RST0_RSTSTA_MASK;
    regValue = regValue >> HWIO_CRC_RST0_CRC_RST0_RSTSTA_SHFT;
    return ((regValue > 0U) ? true : false);
    // TODO: check if correct

#else
    return (REG_READ(Module->CRC_RST0.bits.RSTSTA));
#endif
}

/**
 * @brief 配置对CRCs模块内核地址的写访问使能状态(针对Master TAG ID n的事务)
 *
 *
 * @param Module
 * @param Status 对CRCs模块内核地址的写访问使能状态(针对Master TAG ID n的事务)
 *        false  写访问没有执行
 *        true   写访问执行
 * @retval void
 */
KF_INLINE void
Crcs_LL_SetAccessCtrlStatus(Crcs_RegisterMap_t *const Module, const Crcs_TagId_t TagId, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_ACES0_ADDR);
    regValue &= ~MASK_1_BIT << TagId;
    regValue |= Status << TagId;

    REG_WRITE(HWIO_CRC_ACES0_ADDR, regValue);
    // TODO: check if correct

#else
    REG_BITS_WRITE(Module->CRC_ACES0.reg, MASK_1_BIT << TagId, Status << TagId);
#endif
}

/**
 * @brief 获取CRCs模块通道状态
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @retval bool   CRCs模块通道不同状态位或操作的结果
 *         false  无错误
 *         true   有错误
 */
KF_INLINE bool Crcs_LL_GetChannelStatus(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex)
{
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_CRC_CHSTS_ADDR, MASK_1_BIT << ChannelIndex, ChannelIndex));
    // TODO: check if correct

#else
    return (REG_BITS_READ(Module->CRC_CHSTS.reg, MASK_1_BIT << ChannelIndex, ChannelIndex));
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的自动长度加载使能
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param Status 自动长度加载使能状态
 *        false  自动长度加载未使能
 *        true   自动长度加载使能
 * @retval void
 */
KF_INLINE void Crcs_LL_SetAutoLengthLoadStatus(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex));
    regValue &= ~HWIO_CRC_CTL0_CRC_CTL0_ALR_MASK;
    regValue |= Status << HWIO_CRC_CTL0_CRC_CTL0_ALR_SHFT;

    REG_WRITE(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex), regValue);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_CTL.bits.ALR, Status);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的CRC检测比较使能
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param Status CRC检测比较使能状态
 *        false  在信息末尾CRC检测比较使能未使能
 *        true   在信息末尾CRC检测比较使能使能
 * @retval void
 */
KF_INLINE void Crcs_LL_SetCrcDetectCompStatus(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex));
    regValue &= ~HWIO_CRC_CTL0_CRC_CTL0_CCE_MASK;
    regValue |= Status << HWIO_CRC_CTL0_CRC_CTL0_CCE_SHFT;

    REG_WRITE(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex), regValue);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_CTL.bits.CCE, Status);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的模式选择
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param ModuleSel CRC模式选择
 *        CRCS_MODULE_SEL_0  使能可编程多项式功能并配置多项式
 *        CRCS_MODULE_SEL_1  CRC-8-H2F AUTOSAR
 *        CRCS_MODULE_SEL_2  CRC-8-SAE-J1850
 *        CRCS_MODULE_SEL_3  CRC-16-CCITT
 *        CRCS_MODULE_SEL_4  CRC-32-Ethernet-IEEE802.3
 *        CRCS_MODULE_SEL_5  CRC-32-AUTOSAR-CRC32P4
 *        CRCS_MODULE_SEL_6  CRC-32-Castagnoli
 * @retval void
 */
KF_INLINE void Crcs_LL_SetModuleSelStatus(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const Crcs_ModuleSel_t ModuleSel)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex));
    regValue &= ~HWIO_CRC_CTL0_CRC_CTL0_MOD_MASK;
    regValue |= ModuleSel << HWIO_CRC_CTL0_CRC_CTL0_MOD_SHFT;

    REG_WRITE(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex), regValue);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_CTL.bits.MOD, ModuleSel);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的CRC结果位反序操作
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param ReverseControl 反序控制
 *        CRC_REVERSE_CTRL_NONE 不反序
 *        CRC_REVERSE_CTRL_WORD  按照字为单位进行反序
 *        CRC_REVERSE_CTRL_BYTE  按照字节为单位进行反序
 * @retval void
 */
KF_INLINE void Crcs_LL_SetResultReverseCtrl(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const Crcs_ReverseControl_t ReverseControl)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex));

    regValue &= ~HWIO_CRC_CTL0_CRC_CTL0_RSLTREV_MASK;
    regValue |= ReverseControl << HWIO_CRC_CTL0_CRC_CTL0_RSLTREV_SHFT;

    REG_WRITE(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex), regValue);
#else
    REG_BITS_WRITE(
      Module->CRC[ChannelIndex].CRC_CTL.reg, MASK_2_BIT << (POS_6_OFFSET), ReverseControl << (POS_6_OFFSET));
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的输入数据进行反序操作
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param ReverseControl 反序控制
 *        CRC_REVERSE_CTRL_NONE 不反序
 *        CRC_REVERSE_CTRL_WORD  按照字为单位进行反序
 *        CRC_REVERSE_CTRL_BYTE  按照字节为单位进行反序
 * @retval void
 */
KF_INLINE void Crcs_LL_SetInputDataReverseCtrl(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const Crcs_ReverseControl_t ReverseControl)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex));

    regValue &= ~HWIO_CRC_CTL0_CRC_CTL0_DATAREV_MASK;
    regValue |= ReverseControl << HWIO_CRC_CTL0_CRC_CTL0_DATAREV_SHFT;

    REG_WRITE(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex), regValue);
#else
    REG_BITS_WRITE(
      Module->CRC[ChannelIndex].CRC_CTL.reg, MASK_2_BIT << (POS_4_OFFSET), ReverseControl << (POS_4_OFFSET));
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的输入数据格式控制位
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param FormatControl 输入数据格式控制位状态
 *        false  无影响
 *        true   输入数据按指定单位进行位反序操作
 * @retval void
 */
KF_INLINE void Crcs_LL_SetDataFormat(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const Crcs_FormatControl_t FormatControl)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex));

    regValue &= ~HWIO_CRC_CTL0_CRC_CTL0_DATASIZE_MASK;
    regValue |= FormatControl << HWIO_CRC_CTL0_CRC_CTL0_DATASIZE_SHFT;

    REG_WRITE(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex), regValue);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_CTL.bits.DATASIZE, FormatControl);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的CRC计算单元复位控制位
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param Status CRC计算单元复位控制状态
 *        false  无作用
 *        true   复位状态
 * @retval void
 */
KF_INLINE void
Crcs_LL_SetResetState(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex));

    regValue &= ~HWIO_CRC_CTL0_CRC_CTL0_RSET_MASK;
    regValue |= Status << HWIO_CRC_CTL0_CRC_CTL0_RSET_SHFT;

    REG_WRITE(HWIO_CRC_CTL0_ADDR + (0x40U * ChannelIndex), regValue);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_CTL.bits.RSET, Status);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的CRC数据寄存器
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param Data CRC数据寄存器写入的数据
 * @retval void
 */
KF_INLINE void
Crcs_LL_SetData(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const uint32_t Data)
{
#ifdef SIMULATION
    REG_WRITE(HWIO_CRC_DATA0_ADDR + (0x40U * ChannelIndex), Data);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_DATA.bits.CRCDATA, Data);
#endif
}

/**
 * @brief 获取对CRCs模块指定通道的CRC计算结果
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @retval uint32_t CRC计算结果
 */
KF_INLINE uint32_t Crcs_LL_GetResult(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_RSLT0_ADDR + (0x40U * ChannelIndex));

    return regValue;
#else
    return (Module->CRC[ChannelIndex].CRC_RSLT.bits.CRCRSLT);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的CRC初始值寄存器
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param InitialVal CRC计算的初始值
 * @retval void
 */
KF_INLINE void Crcs_LL_SetInitialVal(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const uint32_t InitialVal)
{
#ifdef SIMULATION
    REG_WRITE(HWIO_CRC_INIT0_ADDR + 0x40U * ChannelIndex, InitialVal);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_INIT.bits.CRCINTI, InitialVal);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的CRC多项式寄存器
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param Polynomial CRC多项式
 * @retval void
 */
KF_INLINE void Crcs_LL_SetPolynomial(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const uint32_t Polynomial)
{
#ifdef SIMULATION
    REG_WRITE(HWIO_CRC_PLN0_ADDR + 0x40U * ChannelIndex, Polynomial);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_PLN.bits.CRCPLN, Polynomial);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的CRC结果异或值寄存器
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param XorVal CRC异或值
 * @retval void
 */
KF_INLINE void
Crcs_LL_SetResultXorVal(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const uint32_t XorVal)
{
#ifdef SIMULATION
    REG_WRITE(HWIO_CRC_RXOR0_ADDR + 0x40U * ChannelIndex, XorVal);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_RXOR.bits.CRCRXOR, XorVal);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的CRC独立数据寄存器
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param IndependentData 独立数据
 * @retval void
 */
KF_INLINE void Crcs_LL_SetIndependentData(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const uint32_t IndependentData)
{
#ifdef SIMULATION
    REG_WRITE(HWIO_CRC_IDATA0_ADDR + 0x40U * ChannelIndex, IndependentData);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_IDATA.bits.CRCIDATA, IndependentData);
#endif
}

/**
 * @brief 获取CRCs模块指定通道下CRC独立数据寄存器的数据
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @retval uint32_t  独立数据
 */
KF_INLINE uint32_t Crcs_LL_GetIndependentData(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_IDATA0_ADDR + 0x40U * ChannelIndex);

    return regValue;
#else
    return (Module->CRC[ChannelIndex].CRC_IDATA.bits.CRCIDATA);
#endif
}

/**
 * @brief 获取对CRCs模块指定通道的CRC缓存寄存器
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @retval uint32_t CRC计算的中间临时结果缓存
 */
KF_INLINE uint32_t Crcs_LL_GetTempData(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_TEMP0_ADDR + 0x40U * ChannelIndex);

    return regValue;
#else
    return (Module->CRC[ChannelIndex].CRC_TEMP.bits.CRCTEMP);
#endif
}

/**
 * @brief 获取对CRCs模块指定通道数据已计算的个数
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @retval uint32_t 目前已计算的个数
 */
KF_INLINE uint32_t Crcs_LL_GetCalcuDataLength(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_LENGTH0_ADDR + 0x40U * ChannelIndex);
    regValue &= HWIO_CRC_LENGTH0_CRC_LENGTH0_CNT_MASK;
    regValue = regValue >> HWIO_CRC_LENGTH0_CRC_LENGTH0_CNT_SHFT;

    return regValue;
#else
    return (Module->CRC[ChannelIndex].CRC_LENGTH.bits.CNT);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道计算结果的数量或长度
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param AllCalcuDataNum 计算结果的数量或长度
 * @retval void
 */
KF_INLINE void Crcs_LL_SetAllCalcuDataLength(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const uint16_t AllCalcuDataLength)
{
    // TODO: CNT是已计算的数据个数，LENGTH是整个过程计算的数据总数？
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_LENGTH0_ADDR + 0x40U * ChannelIndex);
    regValue &= ~HWIO_CRC_LENGTH0_CRC_LENGTH0_LENGTH_MASK;
    regValue |= AllCalcuDataLength << HWIO_CRC_LENGTH0_CRC_LENGTH0_LENGTH_SHFT;
    REG_WRITE(HWIO_CRC_LENGTH0_ADDR + 0x40U * ChannelIndex, 0xFACECAFE);
    REG_WRITE(HWIO_CRC_LENGTH0_ADDR + 0x40U * ChannelIndex, regValue);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_LENGTH.bits.LENGTH, 0xFACECAFE);
    REG_WRITE(Module->CRC[ChannelIndex].CRC_LENGTH.bits.LENGTH, AllCalcuDataLength);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的CRC校验值
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param CrcCheckVal CRC校验值
 * @retval void
 */
KF_INLINE void Crcs_LL_SetCrcCheckVal(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const uint32_t CrcCheckVal)
{
#ifdef SIMULATION
    REG_WRITE(HWIO_CRC_CHECK0_ADDR + 0x40U * ChannelIndex, CrcCheckVal);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_CHECK.bits.CHECK, CrcCheckVal);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的测试寄存器
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param ErrorIntEn 控制错误注入机制错误匹配中断使能位
 * @param Status bool
 *        false  未使能指定寄存器的错误匹配中断
 *        true   使能控制错误注入机制指定寄存器的错误匹配中断
 * @retval void
 */
KF_INLINE void Crcs_LL_SetErrorMatchInt(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex,
                                        const Crcs_ErrorMatchIntEn_t ErrorIntEn, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_TEST0_ADDR + 0x40U * ChannelIndex);
    regValue &= ~(MASK_1_BIT << ErrorIntEn);
    regValue |= Status << ErrorIntEn;

    REG_WRITE(HWIO_CRC_TEST0_ADDR + 0x40U * ChannelIndex, regValue);
#else
    REG_BITS_WRITE(Module->CRC[ChannelIndex].CRC_TEST.reg, MASK_1_BIT << ErrorIntEn, Status << ErrorIntEn);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的CRC状态寄存器
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param Status bool
 *        false  清除计数结束标志位
 *        true   无作用
 * @retval void
 */
KF_INLINE void
Crcs_LL_SetCountEndStatus(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_STATE0_ADDR + 0x40U * ChannelIndex);
    regValue &= ~HWIO_CRC_STATE0_CRC_STATE0_CNTEND_MASK;
    regValue |= Status << HWIO_CRC_STATE0_CRC_STATE0_CNTEND_SHFT;

    REG_WRITE(HWIO_CRC_STATE0_ADDR + 0x40U * ChannelIndex, regValue);
#else
    REG_WRITE(Module->CRC[ChannelIndex].CRC_STATE.bits.CNTEND, Status);
#endif
}

/**
 * @brief 获取对CRCs模块指定通道的错误中断标志位
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param ErrorFlag 中断请求标志位
 * @retval bool
 *        false  没有中断请求
 *        true   产生中断请求
 */
KF_INLINE bool Crcs_LL_GetIntFlag(
  Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex, const Crcs_ErrorFlag_t ErrorFlag)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_IF0_ADDR + 0x40U * ChannelIndex);
    regValue &= (MASK_1_BIT << ErrorFlag);
    regValue = regValue >> ErrorFlag;

    return ((regValue > 0U) ? true : false);
#else
    return (REG_BITS_READ(Module->CRC[ChannelIndex].CRC_IF.reg, MASK_1_BIT << ErrorFlag, ErrorFlag));
#endif
}

/**
 * @brief 清零CRCs模块指定通道下的中断请求标志位
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param ErrorFlag 中断请求标志位
 * @param Status
 *        false  无影响
 *        true   清零中断请求标志位
 * @retval void
 */
KF_INLINE void Crcs_LL_ClearIntFlag(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex,
                                    const Crcs_ErrorFlag_t ErrorFlag, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = Status << ErrorFlag;

    REG_WRITE(HWIO_CRC_IC0_ADDR + 0x40U * ChannelIndex, regValue);
#else
    REG_BITS_WRITE(Module->CRC[ChannelIndex].CRC_IC.reg, MASK_1_BIT << ErrorFlag, Status << ErrorFlag);
#endif
}

/**
 * @brief 置位CRCs模块指定通道下的中断请求标志位
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param ErrorFlag 中断请求标志位
 * @param Status
 *        false  无影响
 *        true   置位中断请求标志位
 * @retval void
 */
KF_INLINE void Crcs_LL_SetIntFlag(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex,
                                  const Crcs_ErrorFlag_t ErrorFlag, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = Status << ErrorFlag;

    REG_WRITE(HWIO_CRC_IS0_ADDR + 0x40U * ChannelIndex, regValue);
#else
    REG_BITS_WRITE(Module->CRC[ChannelIndex].CRC_IS.reg, MASK_1_BIT << ErrorFlag, Status << ErrorFlag);
#endif
}

/**
 * @brief 配置对CRCs模块指定通道的中断请求使能位
 *
 *
 * @param Module
 * @param ChannelIndex CRCs模块通道索引,取值为CRCS_CHANNEL_INDEX_0~CRCS_CHANNEL_INDEX_7
 * @param ErrorFlagEn 中断请求使能位
 * @param Status
 *        false  禁止生成中断请求
 *        true   允许生成中断请求
 * @retval void
 */
KF_INLINE void Crcs_LL_EnableInt(Crcs_RegisterMap_t *const Module, const Crcs_ChannelIndex_t ChannelIndex,
                                 const Crcs_ErrorFlag_t ErrorFlagEn, const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue = REG_READ(HWIO_CRC_IE0_ADDR + 0x40U * ChannelIndex);
    regValue &= ~(MASK_1_BIT << ErrorFlagEn);
    regValue |= (Status << ErrorFlagEn);

    REG_WRITE(HWIO_CRC_IE0_ADDR + 0x40U * ChannelIndex, regValue);
#else
    REG_BITS_WRITE(Module->CRC[ChannelIndex].CRC_IE.reg, MASK_1_BIT << ErrorFlagEn, Status << ErrorFlagEn);
#endif
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
