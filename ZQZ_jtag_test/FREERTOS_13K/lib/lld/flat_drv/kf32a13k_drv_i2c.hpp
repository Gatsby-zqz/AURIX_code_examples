/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_i2c.h
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
 *  |2023-12-25  |V1.0     |Roger Lou     |New creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_I2C_H_
#define KF32A13K_DRV_I2C_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                                             MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 * MISRA DIR 4.9 - A function should be used in preference to a function-like
 * macro where they are interchangeable
 * MISRA RULE 2.1 - A project shall not contain unreachable code
 * MISRA RULE 11.4 - A conversion should not be performed between a pointer to
 * object and an integer type
 * MISRA RULE 8.13 - A pointer should point to a const-qualified type whenever
 * possible
 * MISRA RULE 2.3 - A project should not contain unused type declarations
 */

/******************************************************************************
 **                         QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 0303 EOF #Suppress MISRA RULE 11.4 violation */ /* Cast between a
                                                             pointer to volatile
                                                             object and an
                                                             integral type. */
/* PRQA S 3469 EOF # Inline Function */
/* PRQA S 3205 EOF # Suppress MISRA RULE 2.3 violation */
/* PRQA S 3673 EOF # Suppress MISRA RULE 8.13 */          /* The object addressed by the
                                                             pointer parameter is not
                                                             modified and so the pointer
                                                             could be of type 'pointer to
                                                             const'. */
/* PRQA S 2814 EOF */                                     /* Possible: Dereference of NULL pointer. */
/* PRQA S 3219 EOF # Suppress MISRA RULE 2.1 violation */ /* Static function is
                         not used within this translation unit. */
/* PRQA S 3442 EOF */                                     /* Operator other than & (address-of) or = (assignment)
                                                             applied to a volatile object. */
/* PRQA S 3227 EOF */                                     /* The parameter is never modified and so it could be
                                                             declared with the 'const' qualifier. */
/* PRQA S 3472 EOF #Suppress MISRA RULE 4.9 */            /* All toplevel uses of this
                                                             function-like macro look like
                                                             they could be replaced by
                                                             equivalent function calls. */

/******************************************************************************
 **                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_i2c.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_I2C_ASSERT
#include "dev_assert.h"
#define KF_I2C_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_I2C_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION
#define i2c_MODULE_BASE_ADDR I2C0_ADDR
#include "kf32a13k_reg_simulation_i2c.h"
#endif
/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/

/* I2C所有中断类型掩码 */
typedef enum
{
    I2C_INTR_INDEX_ADRM      = (1U << 0U),  /*!< 地址匹配中断掩码> */
    I2C_INTR_INDEX_GC        = (1U << 1U),  /*!< 广播呼叫中断掩码> */
    I2C_INTR_INDEX_MC        = (1U << 2U),  /*!< 主机码（高速模式）中断掩码> */
    I2C_INTR_INDEX_ALERR     = (1U << 3U),  /*!< 仲裁失败中断掩码> */
    I2C_INTR_INDEX_NACK      = (1U << 4U),  /*!< 接收到未应答信号中断掩码> */
    I2C_INTR_INDEX_TXEND     = (1U << 5U),  /*!< 传输结束中断掩码> */
    I2C_INTR_INDEX_RX        = (1U << 6U),  /*!< 接收模式中断掩码> */
    I2C_INTR_INDEX_START     = (1U << 7U),  /*!< 起始位中断掩码> */
    I2C_INTR_INDEX_STOP      = (1U << 8U),  /*!< 停止位中断掩码> */
    I2C_INTR_INDEX_BYTE      = (1U << 9U),  /*!< 字节传输中断掩码> */
    I2C_INTR_INDEX_SMBA      = (1U << 10U), /*!< SMBus模式的提醒中断掩码> */
    I2C_INTR_INDEX_SMBH      = (1U << 11U), /*!< SMBus模式的主机头地址中断掩码> */
    I2C_INTR_INDEX_SMBD      = (1U << 12U), /*!< SMBus模式的设备默认地址> */
    I2C_INTR_INDEX_ACKTO     = (1U << 13U), /*!< ACK超时中断掩码> */
    I2C_INTR_INDEX_HSACKTO   = (1U << 14U), /*!< 切换到高速模式时超时中断掩码> */
    I2C_INTR_INDEX_RSTO      = (1U << 15U), /*!< 重启后超时中断掩码> */
    I2C_INTR_INDEX_RXUDF     = (1U << 16U), /*!< RXFIFO下溢中断掩码> */
    I2C_INTR_INDEX_RXOVF     = (1U << 17U), /*!< RXFIFO上溢中断掩码> */
    I2C_INTR_INDEX_TXUDF     = (1U << 18U), /*!< TXFIFO下溢中断掩码> */
    I2C_INTR_INDEX_TXOVF     = (1U << 19U), /*!< TXFIFO上溢中断掩码> */
    I2C_INTR_INDEX_RXLSINGLE = (1U << 20U), /*!< 最后一次接收单次传输请求中断> */
    I2C_INTR_INDEX_RXSINGLE  = (1U << 21U), /*!< 接收单次传输请求中断> */
    I2C_INTR_INDEX_RXLBURST  = (1U << 22U), /*!< 最后一次接收突发传输请求中断> */
    I2C_INTR_INDEX_RXBURST   = (1U << 23U), /*!< 接收突发传输请求中断> */
    I2C_INTR_INDEX_TXLSINGLE = (1U << 24U), /*!< 最后一次发送单次传输请求中断> */
    I2C_INTR_INDEX_TXSINGLE  = (1U << 25U), /*!< 发送单次传输请求中断> */
    I2C_INTR_INDEX_TXLBURST  = (1U << 26U), /*!< 最后一次发送突发传输请求中断> */
    I2C_INTR_INDEX_TXBURST   = (1U << 27U), /*!< 发送突发传输请求中断> */
    I2C_INTR_INDEX_PEC       = (1U << 28U), /*!< 接收期间的PEC错误> */
    I2C_INTR_INDEX_SMBTO     = (1U << 29U), /*!< 超时错误> */
} I2c_IntrMask_t;

typedef enum
{
    I2C_NO_HALT_0H, /*!<没有挂起*/
    I2C_HW_HALT_1H, /*!<硬件挂起，时钟关闭*/
    I2C_SW_HALT_2H  /*!软件挂起*/
} I2c_DBGCTLMask_t;
#define CHECK_I2C_DBGCTL_MODE(DBGCTLMODE)                                                                              \
    (((DBGCTLMODE) == I2C_NO_HALT_0H) || ((DBGCTLMODE) == I2C_HW_HALT_1H) || ((DBGCTLMODE) == I2C_SW_HALT_2H))

typedef enum
{
    I2C_ACCESS0_EN_ID_0,
    I2C_ACCESS0_EN_ID_1,
    I2C_ACCESS0_EN_ID_2,
    I2C_ACCESS0_EN_ID_3,
    I2C_ACCESS0_EN_ID_4,
    I2C_ACCESS0_EN_ID_5,
    I2C_ACCESS0_EN_ID_6,
    I2C_ACCESS0_EN_ID_7,
    I2C_ACCESS0_EN_ID_8,
    I2C_ACCESS0_EN_ID_9,
    I2C_ACCESS0_EN_ID_10,
    I2C_ACCESS0_EN_ID_11,
    I2C_ACCESS0_EN_ID_12,
    I2C_ACCESS0_EN_ID_13,
    I2C_ACCESS0_EN_ID_14,
    I2C_ACCESS0_EN_ID_15,
    I2C_ACCESS0_EN_ID_16,
    I2C_ACCESS0_EN_ID_17,
    I2C_ACCESS0_EN_ID_18,
    I2C_ACCESS0_EN_ID_19,
    I2C_ACCESS0_EN_ID_20,
    I2C_ACCESS0_EN_ID_21,
    I2C_ACCESS0_EN_ID_22,
    I2C_ACCESS0_EN_ID_23,
    I2C_ACCESS0_EN_ID_24,
    I2C_ACCESS0_EN_ID_25,
    I2C_ACCESS0_EN_ID_26,
    I2C_ACCESS0_EN_ID_27,
    I2C_ACCESS0_EN_ID_28,
    I2C_ACCESS0_EN_ID_29,
    I2C_ACCESS0_EN_ID_30,
    I2C_ACCESS0_EN_ID_31
} I2C_Access0_En_Id_t;
#define CHECK_I2C_ACCESS0_EN_ID(x) ((uint32_t)(x) <= (uint32_t)I2C_ACCESS0_EN_ID_31)

/* 标准和快速模式下SDA输出数据维持时间延迟阶段数 */
typedef enum
{
    I2C_SDALEN_3,
    I2C_SDALEN_4,
    I2C_SDALEN_5,
    I2C_SDALEN_6,
    I2C_SDALEN_7,
    I2C_SDALEN_8,
    I2C_SDALEN_9,
    I2C_SDALEN_10,
    I2C_SDALEN_11,
    I2C_SDALEN_12,
    I2C_SDALEN_13,
    I2C_SDALEN_14,
    I2C_SDALEN_15,
    I2C_SDALEN_16,
    I2C_SDALEN_17,
    I2C_SDALEN_18,
    I2C_SDALEN_19,
    I2C_SDALEN_20,
    I2C_SDALEN_21,
    I2C_SDALEN_22,
    I2C_SDALEN_23,
    I2C_SDALEN_24,
    I2C_SDALEN_25,
    I2C_SDALEN_26,
    I2C_SDALEN_27,
    I2C_SDALEN_28,
    I2C_SDALEN_29,
    I2C_SDALEN_30,
    I2C_SDALEN_31,
    I2C_SDALEN_32,
    I2C_SDALEN_33,
    I2C_SDALEN_34,
    I2C_SDALEN_35,
    I2C_SDALEN_36,
    I2C_SDALEN_37,
    I2C_SDALEN_38,
    I2C_SDALEN_39,
    I2C_SDALEN_40,
    I2C_SDALEN_41,
    I2C_SDALEN_42,
    I2C_SDALEN_43,
    I2C_SDALEN_44,
    I2C_SDALEN_45,
    I2C_SDALEN_46,
    I2C_SDALEN_47,
    I2C_SDALEN_48,
    I2C_SDALEN_49,
    I2C_SDALEN_50,
    I2C_SDALEN_51,
    I2C_SDALEN_52,
    I2C_SDALEN_53,
    I2C_SDALEN_54,
    I2C_SDALEN_55,
    I2C_SDALEN_56,
    I2C_SDALEN_57,
    I2C_SDALEN_58,
    I2C_SDALEN_59,
    I2C_SDALEN_60,
    I2C_SDALEN_61,
    I2C_SDALEN_62,
    I2C_SDALEN_63,
    I2C_SDALEN_64,
    I2C_SDALEN_65,
    I2C_SDALEN_66,
} I2C_Sdalen_t;
#define CHECK_I2C_SDALEN(x) ((x) <= I2C_SDALEN_66)

/* 高速模式下SDA输出数据维持时间延迟阶段数 */
typedef enum
{
    I2C_HSDALEN_3,
    I2C_HSDALEN_4,
    I2C_HSDALEN_5,
    I2C_HSDALEN_6,
    I2C_HSDALEN_7,
    I2C_HSDALEN_8,
    I2C_HSDALEN_9,
    I2C_HSDALEN_10,
} I2C_Hsdalen_t;
#define CHECK_I2C_HSDALEN(x) ((x) <= I2C_HSDALEN_10)

/* SCL输出启动(重新启动)条件维持时间延迟阶段数 */
typedef enum
{
    I2C_SCLLEN_2,
    I2C_SCLLEN_3,
    I2C_SCLLEN_4,
    I2C_SCLLEN_5,
    I2C_SCLLEN_6,
    I2C_SCLLEN_7,
    I2C_SCLLEN_8,
    I2C_SCLLEN_9,
} I2C_SclLen_t;
#define CHECK_I2C_SCLLEN(x) ((x) <= I2C_SCLLEN_9)

/* 高速模式下SDA输出开启/停止位持续时间长度 */
typedef enum
{
    I2C_HSPLEN_0,
    I2C_HSPLEN_1,
    I2C_HSPLEN_2,
    I2C_HSPLEN_3,
    I2C_HSPLEN_4,
    I2C_HSPLEN_5,
    I2C_HSPLEN_6,
    I2C_HSPLEN_7,
} I2C_Hsplen_t;
#define CHECK_I2C_HSPLEN(x) ((x) <= I2C_HSPLEN_7)

typedef enum
{
    I2C_FIFOCTL_TXBA_FULL_BYTE_ALAIN_00B, //	字节对齐
    I2C_FIFOCTL_TXBA_HALF_BYTE_ALAIN_01B, // 半字对齐
    I2C_FIFOCTL_TXBA_WORD_ALAIN_10B,      // 字对齐
    I2C_FIFOCTL_TXBA_RESERVE              /*保留，不建议使用*/
} I2c_Fifo_TxBa_t;
#define CHECK_I2C_FIFOCTL_TXBA_ID(x) ((uint32_t)(x) <= (uint32_t)I2C_FIFOCTL_TXBA_RESERVE)

typedef enum
{
    I2C_FIFOCTL_RXBA_FULL_BYTE_ALAIN_00B, //	字节对齐
    I2C_FIFOCTL_RXBA_HALF_BYTE_ALAIN_01B, // 半字对齐
    I2C_FIFOCTL_RXBA_WORD_ALAIN_10B,      // 字对齐
    I2C_FIFOCTL_RXBA_RESERVE              /*保留，不建议使用*/
} I2c_Fifo_RxBa_t;
#define CHECK_I2C_FIFOCTL_RXBA_ID(x) ((uint32_t)(x) <= (uint32_t)I2C_FIFOCTL_RXBA_RESERVE)

typedef enum
{
    I2C_FIFOCTL_TXBURST_1WORD_00B,
    I2C_FIFOCTL_TXBURST_2WORD_01B,
    I2C_FIFOCTL_TXBURST_4WORD_10B,
    I2C_FIFOCTL_TXBURST_RESEVE
} I2c_Fifo_TxBurst_t;
#define CHECK_I2C_FIFOCTL_TXBURST_ID(x) ((uint32_t)(x) <= (uint32_t)I2C_FIFOCTL_TXBURST_RESEVE)

typedef enum
{
    I2C_FIFOCTL_RXBURST_1WORD_00B,
    I2C_FIFOCTL_RXBURST_2WORD_01B,
    I2C_FIFOCTL_RXBURST_4WORD_10B,
    I2C_FIFOCTL_RXBURST_RESEVE
} I2c_Fifo_RxBurst_t;
#define CHECK_I2C_FIFOCTL_RXBURST_ID(x) ((uint32_t)(x) <= (uint32_t)I2C_FIFOCTL_RXBURST_RESEVE)

/* i2c addr check */
/* PRQA S 3456 1 */
#define CHECK_I2C_ALL_PERIPH_ADDR(PERIPH)                                                                              \
    (((PERIPH) == I2C0_PTR) || ((PERIPH) == I2C1_PTR) || ((PERIPH) == I2C2_PTR) || ((PERIPH) == I2C3_PTR))
/******************************************************************************
 **                      Typedef  Definitions
 ******************************************************************************/

/* bit mode */
typedef enum
{
    I2C_ADDR_7BITS,
    I2C_ADDR_10BITS
} I2c_Addr_t;
#define CHECK_I2C_ADDRMODE_TYPE(TYPE) (((TYPE) == I2C_ADDR_7BITS) || ((TYPE) == I2C_ADDR_10BITS))

/* bit mode */
typedef enum
{
    I2C_MODE_I2C,
    I2C_MODE_SMBUS
} I2c_Mode_t;
#define CHECK_I2C_MODE_TYPE(TYPE) (((TYPE) == I2C_MODE_I2C) || ((TYPE) == I2C_MODE_SMBUS))

typedef enum
{
    I2C_BUS_IDLE,
    I2C_BUS_BUSY,
    I2C_MASTER_BUSY,
    I2C_SLAVE_BUSY
} I2c_BusState_t;
#define CHECK_I2C_BUS_STATE(STATE)                                                                                     \
    (((STATE) == I2C_BUS_IDLE) || ((STATE) == I2C_BUS_BUSY) || ((STATE) == I2C_MASTER_BUSY) ||                         \
     ((STATE) == I2C_SLAVE_BUSY))

/******************************************************************************
 **                      Export Variables
 ******************************************************************************/

/******************************************************************************
 **                      Export Functions
 ******************************************************************************/

/* I2C_CLKC_T */

/**
 * @brief I2C 时钟休眠模式
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 使能状态
 *      true -- 禁止休眠模式
 *      false -- 使能休眠模式
 * @retval void
 */
KF_INLINE void I2c_LL_SetClockSleepMode(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CLKC_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CLKC_I2C0_CLKC_EDIS_MASK;
    regValue |= State << HWIO_I2C0_CLKC_I2C0_CLKC_EDIS_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CLKC_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CLKC.bits.EDIS, State);
#endif
}

/**
 * @brief I2C 时钟禁止模式
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval 标志位
 *      true -- 模块已禁止
 *      false -- 模块已使能
 */
KF_INLINE bool I2c_LL_GetClockDisableMode(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CLKC_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_CLKC_I2C0_CLKC_DISS_MASK;
    regValue = regValue >> HWIO_I2C0_CLKC_I2C0_CLKC_DISS_SHFT;
    return ((bool)((regValue)));
    // TODO: check if correct

#else
    return ((bool)(REG_READ(Module->CLKC.bits.DISS)));
#endif
}

/**
 * @brief I2C 时钟禁止模式控制
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 使能状态
 *      true -- 禁止模块
 *      false -- 无
 * @retval uint8_t
 */
KF_INLINE void I2c_LL_SetClockDisableMode(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CLKC_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CLKC_I2C0_CLKC_DISR_MASK;
    regValue |= State << HWIO_I2C0_CLKC_I2C0_CLKC_DISR_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CLKC_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CLKC.bits.DISR, State);
#endif
}

/*  I2C_INFO_T */

/**
 * @brief I2c获取模块版本号
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 *
 *
 * @retval uint32_t 模块版本号
 */
KF_INLINE uint32_t I2c_LL_GetModuleVersion(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_INFO_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_INFO_I2C0_INFO_MODREV_MASK;
    regValue = regValue >> HWIO_I2C0_INFO_I2C0_INFO_MODREV_SHFT;
    return ((uint32_t)((regValue)));
    // TODO: check if correct

#else
    return ((uint32_t)(REG_READ(Module->INFO.bits.MODREV)));
#endif
}

/**
 * @brief I2c获取模块类型
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 *
 *
 * @retval uint32_t 模块类型
 */
KF_INLINE uint32_t I2c_LL_GetModuleType(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_INFO_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_INFO_I2C0_INFO_MODTYPE_MASK;
    regValue = regValue >> HWIO_I2C0_INFO_I2C0_INFO_MODTYPE_SHFT;
    return ((uint32_t)((regValue)));
    // TODO: check if correct

#else
    return ((uint32_t)(REG_READ(Module->INFO.bits.MODTYPE)));
#endif
}

/**
 * @brief I2c获取模块编号
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 *
 *
 * @retval uint32_t 模块编号
 */
KF_INLINE uint32_t I2c_LL_GetModuleNumber(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_INFO_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_INFO_I2C0_INFO_MODNUM_MASK;
    regValue = regValue >> HWIO_I2C0_INFO_I2C0_INFO_MODNUM_SHFT;
    return ((uint32_t)((regValue)));
    // TODO: check if correct

#else
    return ((uint32_t)(REG_READ(Module->INFO.bits.MODNUM)));
#endif
}

/*  I2C_DBG_T */

/**
 * @brief I2c获取挂起状态位
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 *
 *
 * @retval bool 挂起状态位
 */
KF_INLINE bool I2c_LL_GetHaltState(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_DBG_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_DBG_I2C0_DBG_DBGSTA_MASK;
    regValue = regValue >> HWIO_I2C0_DBG_I2C0_DBG_DBGSTA_SHFT;
    return ((bool)((regValue)));
    // TODO: check if correct

#else
    return ((bool)(REG_READ(Module->DBG.bits.DBGSTA)));
#endif
}

/**
 * @brief I2c设置SUS位写保护
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State
 *      true -- SUS位可被写
 *      false -- SUS位不可写
 *
 * @retval void
 */
KF_INLINE void I2c_LL_SetWriteSusPort(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_DBG_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_DBG_I2C0_DBG_DBGP_MASK;
    regValue |= State << HWIO_I2C0_DBG_I2C0_DBG_DBGP_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_DBG_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->DBG.bits.DBGP, State);
#endif
}

/**
 * @brief I2c设置调试模式挂起控制
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] DbgCtrlMode
 *      0H 没有挂起
 *      1H 硬件挂起，时钟关闭
 *      2H 软件挂起
 *
 * @retval void
 */
KF_INLINE void I2c_LL_SetDgbHaltMode(I2c_RegisterMap_t *const Module, I2c_DBGCTLMask_t DbgCtrlMode)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_DBGCTL_MODE(DbgCtrlMode));

    uint32_t regValue = 0U;

    regValue |= true << 28U;
    regValue |= DbgCtrlMode << 24U;
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_I2C0_DBG_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->DBG.reg, regValue);
#endif
}

/* I2C_RST0_T */

/**
 * @brief I2c读取复位状态
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 *
 * @retval 复位状态
 */
KF_INLINE bool I2c_LL_GetRstState(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_RST0_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_RST0_I2C0_RST0_RSTSTA_MASK;
    regValue = regValue >> HWIO_I2C0_RST0_I2C0_RST0_RSTSTA_SHFT;
    return ((bool)((regValue)));
    // TODO: check if correct

#else
    return ((bool)(REG_READ(Module->RST0.bits.RSTSTA)));
#endif
}

/**
 * @brief I2c设置模块复位请求
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State
 *      true -- 使能模块复位
 *      false -- 无动作
 *
 * @retval void
 */
KF_INLINE void I2c_LL_SetRstRequest(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_RST0_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_RST0_I2C0_RST0_RST_MASK;
    regValue |= State << HWIO_I2C0_RST0_I2C0_RST0_RST_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_RST0_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->RST0.bits.RST, State);
#endif
#ifdef SIMULATION
    offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    regValue   = REG_READ(HWIO_I2C0_RST1_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_RST1_I2C0_RST1_RST_MASK;
    regValue |= State << HWIO_I2C0_RST1_I2C0_RST1_RST_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_RST1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->RST1.bits.RST, State);
#endif
}

/*  I2C_RSTCLR */

/**
 * @brief I2c设置RSTSTA复位状态清除位
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State
 *      true -- 清零RSTSTA位
 *      false -- 无动作
 *
 * @retval void
 */
KF_INLINE void I2c_LL_ClrRstStat(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_RSTCLR_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_RSTCLR_I2C0_RSTCLR_CLR_MASK;
    regValue |= State << HWIO_I2C0_RSTCLR_I2C0_RSTCLR_CLR_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_RSTCLR_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->RSTCLR.bits.CLR, State);
#endif
}

/* I2C_ACES0_T */

/**
 * @brief 设置Master TAG ID n的事务对模块内核地址的写访问
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] I2cAces0EnId EN偏移索引
 * @param[in] State
 *      true 写访问执行
 *      false 写访问没有执行
 * @retval None
 */
KF_INLINE void
I2c_LL_SetTagIDAccessEnabled(I2c_RegisterMap_t *const Module, I2C_Access0_En_Id_t I2cAces0EnId, bool State)
{

    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_ACCESS0_EN_ID(I2cAces0EnId));

    uint32_t Mask;
    uint32_t Value;

    Mask  = (uint32_t)0x1U << ((uint32_t)I2cAces0EnId);
    Value = (uint32_t)State << ((uint32_t)I2cAces0EnId);

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_ACES0_ADDR + offsetAddr);
    regValue &= ~Mask;
    regValue |= Value;

    REG_WRITE(offsetAddr + HWIO_I2C0_ACES0_ADDR, regValue);
    // TODO: check if correct

#else
    REG_BITS_WRITE(Module->ACES0.reg, Mask, Value);
#endif
}

/* I2C_ACES1_T */

/* I2C_CLKC1_T */

/**
 * @brief I2C 工作时钟分频比选择
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] ClockDivision 分频比
 *      0x00 --  I2C 关闭
 *      0x01 --  I2C 工作时钟分频比为 1:1
 *      0x02 --  I2C 工作时钟分频比为 1:4
 *      ...
 *      0xff --  I2C 工作时钟分频比为 1:2^255 TODO: 需要确认
 * @retval void
 */
KF_INLINE void I2c_LL_SetClockDivision(I2c_RegisterMap_t *const Module, uint8_t ClockDivision)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CLKC1_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CLKC1_I2C0_CLKC1_RMC_MASK;
    regValue |= ClockDivision << HWIO_I2C0_CLKC1_I2C0_CLKC1_RMC_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CLKC1_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CLKC1.bits.RMC, ClockDivision);
#endif
}

/**
 * @brief 获取I2C工作时钟分频比选择
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval uint8_t
 */
KF_INLINE uint8_t I2c_LL_GetClockDivision(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CLKC1_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_CLKC1_I2C0_CLKC1_RMC_MASK;
    regValue = regValue >> HWIO_I2C0_CLKC1_I2C0_CLKC1_RMC_SHFT;
    return ((uint8_t)((regValue)));
    // TODO: check if correct

#else
    return ((uint8_t)(REG_READ(Module->CLKC1.bits.RMC)));
#endif
}

/* I2C_ENCTL_T */

/**
 * @brief 设置I2C使能位
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 使能状态
 *      true -- 使能I2C
 *      false -- 不使能I2C
 * @retval void
 */
KF_INLINE void I2c_LL_SetEnableOrDisable(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_ENCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_ENCTL_I2C0_ENCTL_EN_MASK;
    regValue |= State << HWIO_I2C0_ENCTL_I2C0_ENCTL_EN_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_ENCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->ENCTL.bits.EN, State);
#endif
}

/* I2C_ENDCTL */

/**
 * @brief 设置结束传输
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 使能状态
 *      true -- 结束数据传输，具体由当前状态决定：
 *          主机接收状态：收到当前字节后，主机应答信号置低，产生停止信号。转向监听状态；
 *          主机发送状态：发送完当前字节并且接收到应答或不应答信号之后，主机放置停止条件。转向监听状态。
 *          主机重启状态：主机放置停止条件。转向监听状态。
 *          从机接收状态：接收到当前字节之后，从机放置不应答信号。转向传输结束状态。"
 *      false -- 无作用

 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cEndCtlEnd(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_ENDCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_ENDCTL_I2C0_ENDCTL_RESTART_MASK;
    regValue |= State << HWIO_I2C0_ENDCTL_I2C0_ENDCTL_RESTART_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_ENDCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->ENDCTL.bits.END, State);
#endif
}

/**
 * @brief 设置重新启动条件
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 使能状态
 *      true -- 主机想要重启数据传输（改变从机/传输方向）效果由当前状态决定：
 *          主机接收状态：主机放置不应答信号并转为主机重启状态。
 *          主机发送状态：当前正发送数据被发送之后，主机转为重启状态.
 *      false -- 无作用
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cRestartCondition(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_ENDCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_ENDCTL_I2C0_ENDCTL_RESTART_MASK;
    regValue |= State << HWIO_I2C0_ENDCTL_I2C0_ENDCTL_RESTART_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_ENDCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->ENDCTL.bits.RESTART, State);
#endif
}

/* I2C_FDIVCFG_T */

/**
 * @brief 设置I2C波特率INC值
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] IncValue 波特率INC值
 *
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cFdivCfgInc(I2c_RegisterMap_t *const Module, uint32_t IncValue)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FDIVCFG_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FDIVCFG_I2C0_FDIVCFG_INC_MASK;
    regValue |= IncValue << HWIO_I2C0_FDIVCFG_I2C0_FDIVCFG_INC_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FDIVCFG_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FDIVCFG.bits.INC, IncValue);
#endif
}

/**
 * @brief 设置I2C波特率DEC值
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] DecValue 波特率DEC值
 *
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cFdivCfgDec(I2c_RegisterMap_t *const Module, uint32_t DecValue)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FDIVCFG_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FDIVCFG_I2C0_FDIVCFG_DEC_MASK;
    regValue |= DecValue << HWIO_I2C0_FDIVCFG_I2C0_FDIVCFG_DEC_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FDIVCFG_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FDIVCFG.bits.DEC, DecValue);
#endif
}

/* I2C_FDIVHCFG_T */

/**
 * @brief 设置I2C高速模式波特率INC值
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] IncValue 波特率INC值
 *
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cHighSpeedFdivCfgInc(I2c_RegisterMap_t *const Module, uint32_t IncValue)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FDIVHCFG_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FDIVHCFG_I2C0_FDIVHCFG_HINC_MASK;
    regValue |= IncValue << HWIO_I2C0_FDIVHCFG_I2C0_FDIVHCFG_HINC_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FDIVHCFG_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FDIVHCFG.bits.HINC, IncValue);
#endif
}

/**
 * @brief 设置I2C高速模式波特率值
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] DecValue 波特率DEC值
 *
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cHighSpeedFdivCfgDec(I2c_RegisterMap_t *const Module, uint32_t DecValue)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FDIVHCFG_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FDIVHCFG_I2C0_FDIVHCFG_HDEC_MASK;
    regValue |= DecValue << HWIO_I2C0_FDIVHCFG_I2C0_FDIVHCFG_HDEC_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FDIVHCFG_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FDIVHCFG.bits.HDEC, DecValue);
#endif
}

/* I2C_CTL_T */

/**
 * @brief 从机控制波特率
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 引脚状态
 *      false -- 从机不能控制波特率
 *      true -- 从机可以控制波特率
 * @retval void
 */
KF_INLINE void I2c_LL_SetSlaveCtlBaudrate(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_SLAVEBG_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_SLAVEBG_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
#else
    REG_WRITE(Module->CTL.bits.SLAVEBG, State);
#endif
}

/**
 * @brief 接收数据包错误校验字节
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 引脚状态
 *      false -- 不传输PEC
 *      true -- 请求PEC接收
 * @retval void
 */
KF_INLINE void I2c_LL_SetPecRecv(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_RECEPEC_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_RECEPEC_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
#else
    REG_WRITE(Module->CTL.bits.RECEPEC, State);
#endif
}

/**
 * @brief 发送数据包错误校验字节
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 引脚状态
 *      false -- 不传输PEC
 *      true -- 请求PEC发送
 * @retval void
 */
KF_INLINE void I2c_LL_SetPecSend(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_SENDPEC_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_SENDPEC_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
#else
    REG_WRITE(Module->CTL.bits.SENDPEC, State);
#endif
}

/**
 * @brief PEC 使能
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 引脚状态
 *      false -- 禁止PEC计算
 *      true -- 使能PEC计算
 * @retval void
 */
KF_INLINE void I2c_LL_SetPecEnable(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_PECEN_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_PECEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
#else
    REG_WRITE(Module->CTL.bits.PECEN, State);
#endif
}

/**
 * @brief 设置SMBus 提醒。软件可以设置或清除该位(仅 SMBus 从机)
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 引脚状态
 *      false -- 释放 SMBALT 引脚使其变高
 *      true -- 驱动 SMBALT 引脚使其变低
 * @retval void
 */
KF_INLINE void I2c_LL_SetSMBusAlert(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_ALERT_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_ALERT_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.ALERT, State);
#endif
}

/**
 * @brief 设置ARP使能状态
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 状态位
 *      false -- 禁止 ARP
 *      true -- 使能 ARP
 *          如果 SMBT=0，使用 SMBus 设备的默认地址
 *          如果 SMBT=1，使用 SMBus 的主地址
 * @retval void
 */
KF_INLINE void I2c_LL_SetArpEnable(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_ARPEN_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_ARPEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.ARPEN, State);
#endif
}

/**
 * @brief 设置I2C SMBUS 类型
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State SMBUS类型
 *      false -- SMBus 设备
 *      true -- SMBus 主机
 * @retval void
 */
KF_INLINE void I2c_LL_SetSMBusType(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_SMBT_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_SMBT_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.SMBT, State);
#endif
}

/**
 * @brief 设置SMBus 模式使能信号
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 模式选择
 *      false -- I2C 模式
 *      true --  SMBus 模式
 * @retval void
 */
KF_INLINE void I2c_LL_SetSMBusOrI2cMode(I2c_RegisterMap_t *const Module, I2c_Mode_t Mode)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_MODE_TYPE(Mode));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_SMBUS_MASK;
    regValue |= Mode << HWIO_I2C0_CTL_I2C0_CTL_SMBUS_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.SMBUS, (uint32_t)Mode);
#endif
}

/**
 * @brief  设置数据包结束停止配置位
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 模式选择
 *      false -- 当数据包结束后设备进入重启状态
 *      true --  当数据包结束后设备发送停止条件，进入监听状态
 * @retval void
 */
KF_INLINE void I2c_LL_SetSDENDMode(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_SDEND_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_SDEND_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.SDEND, State);
#endif
}

/**
 * @brief 设置I2C应答数据位
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 应答状态
 *      false -- 设备进入重启状态
 *      true --  设备发送停止条件，进入监听状态
 * @retval void
 */
KF_INLINE void I2c_LL_SetAckDataState(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_SNOACK_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_SNOACK_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.SNOACK, State);
#endif
}

/**
 * @brief 设置I2C主/从配置
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 应答状态
 *      false -- 配置为从机
 *      true --  配置位主机
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cCtlMode(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_ADRMOD_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_ADRMOD_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.MOD, State);
#endif
}

/**
 * @brief 设置I2C设备可以处理主机码，支持高速模式
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 应答状态
 *      false -- 设备不能以高速模式运行
 *      true --  设备可以处理主码
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cHsMode(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_HS_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_HS_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.HS, State);
#endif
}

/**
 * @brief 设置I2C广播呼叫使能位(仅限 I2C 从动模式)
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 广播状态
 *      false -- 禁止广播呼叫地址
 *      true --  允许在 I2C
 * 移位寄存器中接收到广播呼叫地址（0000h）时产生中断   注：需要注意的是，当
 * I2Cx_ADDRy 寄存器未被设置时，它们的复位值为   0x0000，也会使 I2C
 * 模块对广播呼叫地址产生响应
 * @retval void
 */
KF_INLINE void I2c_LL_SetBroadCastCallState(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_GCEN_MASK;
    regValue |= State << HWIO_I2C0_CTL_I2C0_CTL_GCEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.GCEN, State);
#endif
}

/**
 * @brief 设置I2C地址类型
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] BitsMode 选择位
 *   I2C_ADDR_7BITS,
 *   I2C_ADDR_10BITS
 * @retval void
 */
KF_INLINE void I2c_LL_SetBandAddrMode(I2c_RegisterMap_t *const Module, I2c_Addr_t BitsMode)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_ADDRMODE_TYPE(BitsMode));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_ADRMOD_MASK;
    regValue |= BitsMode << HWIO_I2C0_CTL_I2C0_CTL_ADRMOD_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.ADRMOD, (uint32_t)BitsMode);
#endif
}

/**
 * @brief 获取I2C地址类型
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] BitsMode 选择位
 *   I2C_ADDR_7BITS,
 *   I2C_ADDR_10BITS
 * @retval void
 */
KF_INLINE I2c_Addr_t I2c_LL_GetAddrMode(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_CTL_I2C0_CTL_ADRMOD_MASK;
    regValue = regValue >> HWIO_I2C0_CTL_I2C0_CTL_ADRMOD_SHFT;
    return ((I2c_Addr_t)((regValue)));
    // TODO: check if correct

#else
    return ((I2c_Addr_t)(REG_READ(Module->CTL.bits.ADRMOD)));
#endif
}

/**
 * @brief 设置I2C总线设备地址
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] Addr  I2C总线设备地址
 *
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cAddr(I2c_RegisterMap_t *const Module, uint32_t Addr)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_CTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_CTL_I2C0_CTL_ADR_MASK;
    regValue |= Addr << HWIO_I2C0_CTL_I2C0_CTL_ADR_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_CTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->CTL.bits.ADR, Addr);
#endif
}

/* I2C_I2CSTA_T */

/**
 * @brief 获取I2C传输方向状态位
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] RWbit I2C传输方向状态位
 *
 * @retval bool
 */
KF_INLINE bool I2c_LL_GetI2cStaRw(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_BUSSTA_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_BUSSTA_I2C0_BUSSTA_RW_MASK;
    regValue = regValue >> HWIO_I2C0_BUSSTA_I2C0_BUSSTA_RW_SHFT;
    return ((bool)((regValue)));
    // TODO: check if correct

#else
    return ((bool)(REG_READ(Module->STA.bits.RW)));
#endif
}

/**
 * @brief 获取I2C总线状态位
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval I2c_BusState_t
 *   I2C_BUS_IDLE 总线空闲
 *   I2C_BUS_BUSY 总线忙
 *   I2C_MASTER_BUSY 主机忙
 *   I2C_SLAVE_BUSY 从机忙
 */
KF_INLINE I2c_BusState_t I2c_LL_GetI2cBusState(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_BUSSTA_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_BUSSTA_I2C0_BUSSTA_BUSSTA_MASK;
    regValue = regValue >> HWIO_I2C0_BUSSTA_I2C0_BUSSTA_BUSSTA_SHFT;
    return ((I2c_BusState_t)((regValue)));
    // TODO: check if correct

#else
    return ((I2c_BusState_t)(REG_READ(Module->STA.bits.BUSSTA)));
#endif
}

/* I2C_FIFOCTL_T */
/**
 * @brief 设置I2C清除请求配置
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] ClearMode I2C传输方向状态位
 *      false -- 软件清除数据请求
 *      true -- 当读/写FIFO时，自动清除数据请求
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cClearRequstMode(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FIFOCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_CLRMOD_MASK;
    regValue |= State << HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_CLRMOD_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FIFOCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FIFOCTL.bits.CLRMOD, State);
#endif
}

/**
 * @brief 设置I2C发送FIFO流控制配置
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] ClearMode I2C传输方向状态位
 *      false -- 发送FIFO不作为流控制器
 *      true -- 发送FIFO作为流控制器
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cTxFlowMode(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FIFOCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_TXFLOW_MASK;
    regValue |= State << HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_TXFLOW_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FIFOCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FIFOCTL.bits.TXFLOW, State);
#endif
}

/**
 * @brief 设置I2C接收FIFO流控制配置
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] ClearMode I2C传输方向状态位
 *      false -- 接收FIFO不作为流控制器
 *      true -- 接收FIFO作为流控制器
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cRxFlowMode(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FIFOCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_RXFLOW_MASK;
    regValue |= State << HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_RXFLOW_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FIFOCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FIFOCTL.bits.RXFLOW, State);
#endif
}

/**
 * @brief 设置I2C发送时间戳中断标志清零位
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in]  State 发收FIFO对齐
 *      00B	字节对齐
 *      01B	半字对齐
 *      10B	字对齐
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cTxBaMode(I2c_RegisterMap_t *const Module, I2c_Fifo_TxBa_t State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_FIFOCTL_TXBA_ID(State));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FIFOCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_TXBA_MASK;
    regValue |= State << HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_TXBA_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FIFOCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FIFOCTL.bits.TXBA, (uint32_t)State);
#endif
}

/**
 * @brief 获取I2C发送FIFO对齐
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval I2c_Fifo_TxBa_t 接收FIFO对齐
 *      00B	字节对齐
 *      01B	半字对齐
 *      10B	字对齐
 */
KF_INLINE I2c_Fifo_TxBa_t I2c_LL_GetI2cTxBaMode(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_FIFOCTL_RXBA_ID(State));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FIFOCTL_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_TXBA_MASK;
    regValue = regValue >> HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_TXBA_SHFT;
    return ((I2c_Fifo_TxBa_t)((regValue)));
    // TODO: check if correct

#else
    return ((I2c_Fifo_TxBa_t)(REG_READ(Module->FIFOCTL.bits.TXBA)));
#endif
}

/**
 * @brief 设置I2C接收FIFO对齐
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in]  State 接收FIFO对齐
 *      00B	字节对齐
 *      01B	半字对齐
 *      10B	字对齐
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cRxBaMode(I2c_RegisterMap_t *const Module, I2c_Fifo_RxBa_t State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_FIFOCTL_RXBA_ID(State));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FIFOCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_RXBA_MASK;
    regValue |= State << HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_RXBA_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FIFOCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FIFOCTL.bits.RXBA, (uint32_t)State);
#endif
}

/**
 * @brief 获取I2C接收FIFO对齐
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval I2c_Fifo_RxBa_t 接收FIFO对齐
 *      00B	字节对齐
 *      01B	半字对齐
 *      10B	字对齐
 */
KF_INLINE I2c_Fifo_RxBa_t I2c_LL_GetI2cRxBaMode(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_FIFOCTL_RXBA_ID(State));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FIFOCTL_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_RXBA_MASK;
    regValue = regValue >> HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_RXBA_SHFT;
    return ((I2c_Fifo_RxBa_t)((regValue)));
    // TODO: check if correct

#else
    return ((I2c_Fifo_RxBa_t)(REG_READ(Module->FIFOCTL.bits.RXBA)));
#endif
}

/**
 * @brief 设置I2C发送突发大小
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in]  State 发送突发大小
 *      00B	1 word
 *      01B	2 word
 *      10B	3 word
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cTxBurstMode(I2c_RegisterMap_t *const Module, I2c_Fifo_TxBurst_t State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_FIFOCTL_TXBURST_ID(State));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FIFOCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_TXBURST_MASK;
    regValue |= State << HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_TXBURST_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FIFOCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FIFOCTL.bits.TXBURST, (uint32_t)State);
#endif
}

/**
 * @brief 设置I2C接收突发大小
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in]  State 接收突发大小
 *      00B	1 word
 *      01B	2 word
 *      10B	3 word
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cRxBurstMode(I2c_RegisterMap_t *const Module, I2c_Fifo_RxBurst_t State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_FIFOCTL_RXBURST_ID(State));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FIFOCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_RXBURST_MASK;
    regValue |= State << HWIO_I2C0_FIFOCTL_I2C0_FIFOCTL_RXBURST_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_FIFOCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->FIFOCTL.bits.RXBURST, (uint32_t)State);
#endif
}

/* I2C_MRPSCTL_T */

/**
 * @brief 设置I2C 最大接收字节大小
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] RxByte I2C 最大接收字节大小
 *                  写入值范围：0至16383
 *                  只要前一个数据包RPS值已经加载到相关计数器中，
 *                  该位域读出值返回为0，此时可以继续写入下一个接收数据包的MRPS值
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cMrpsctlMaxRxByte(I2c_RegisterMap_t *const Module, uint32_t RxByte)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_MRPSCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_MRPSCTL_I2C0_MRPSCTL_MRXB_MASK;
    regValue |= RxByte << HWIO_I2C0_MRPSCTL_I2C0_MRPSCTL_MRXB_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_MRPSCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->MRPSCTL.bits.MRXB, RxByte);
#endif
}

/* I2C_RPSSTA_T */
/**
 * @brief 读出I2C接收字节大小状态值
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 *
 * @retval uint32_t 读出值范围：0至16383
 *                  I2C RXFIFO中已经接收到的数据包的数据字节数；"
 */
KF_INLINE uint32_t I2c_LL_GetI2cRpsSTARxByte(I2c_RegisterMap_t *const Module, uint32_t RxByte)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_RPSSTA_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_RPSSTA_I2C0_RPSSTA_RXB_MASK;
    regValue = regValue >> HWIO_I2C0_RPSSTA_I2C0_RPSSTA_RXB_SHFT;
    return ((uint32_t)((regValue)));
    // TODO: check if correct

#else
    return ((uint32_t)(REG_READ(Module->RPSSTA.bits.RXB)));
#endif
}

/* I2C_TPSCTL_T */
/**
 * @brief 设置I2C发送字节大小
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] TxBit I2C发送字节大小
 *                  写入值范围：0至16383
 *                  只要前一个数据包TPS值已经加载到相关计数器中，该位域读出值返回为0，此时可以继续写入下一个发送数据包的TPS值
 * @retval void
 */
KF_INLINE void I2c_LL_SetI2cTpsctlTxb(I2c_RegisterMap_t *const Module, uint32_t TxBit)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_TPSCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_TPSCTL_I2C0_TPSCTL_TXB_MASK;
    regValue |= TxBit << HWIO_I2C0_TPSCTL_I2C0_TPSCTL_TXB_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_TPSCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->TPSCTL.bits.TXB, TxBit);
#endif
}

/* I2C_FCNTSTA_T */

/**
 * @brief  I2C FIFO填充计数
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 *
 * @retval uint32_t  I2C模块FIFO中保存有数据的阶段数状态；读出值范围：0至8
 */
KF_INLINE uint32_t I2c_LL_GetI2cFcntstaCnt(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_FCNTSTA_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_FCNTSTA_I2C0_FCNTSTA_FCNT_MASK;
    regValue = regValue >> HWIO_I2C0_FCNTSTA_I2C0_FCNTSTA_FCNT_SHFT;
    return ((uint32_t)((regValue)));
    // TODO: check if correct

#else
    return ((uint32_t)(REG_READ(Module->FCNTSTA.bits.FCNT)));
#endif
}

/* I2C_TCTL_T */
/**
 * @brief I2C快速模式下SCL输出低电平长度
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] Length 长度
 *
 * @return void
 */
KF_INLINE void I2c_LL_SetSCLLowLength(I2c_RegisterMap_t *const Module, uint8_t Length)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_TCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_TCTL_I2C0_TCTL_SCLLOWLEN_MASK;
    regValue |= Length << HWIO_I2C0_TCTL_I2C0_TCTL_SCLLOWLEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_TCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->TCTL.bits.SCLLOW, Length);
#endif
}

/**
 * @brief I2C高速模式下SDA输出开启/停止位持续时间长度
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] Delay 延迟阶段数
 *
 * @return void
 */
KF_INLINE void I2c_LL_SetHighSpeedModeSDABitTime(I2c_RegisterMap_t *const Module, I2C_Hsplen_t Delay)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_HSPLEN(Delay));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_TCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_TCTL_I2C0_TCTL_HSPLEN_MASK;
    regValue |= Delay << HWIO_I2C0_TCTL_I2C0_TCTL_HSPLEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_TCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->TCTL.bits.HSPLEN, Delay);
#endif
}

/**
 * @brief I2C配置快速模式下SCL低电平时序
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] bool
 *      false 标准模式SCL低电平持续时间
 *      true 快速模式SCL低电平持续时间
 * @return void
 */
KF_INLINE void I2c_LL_SetSCLLowSeq(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_TCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_TCTL_I2C0_TCTL_SCLLOWSEL_MASK;
    regValue |= State << HWIO_I2C0_TCTL_I2C0_TCTL_SCLLOWSEL_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_TCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->TCTL.bits.SCLLOWSEL, State);
#endif
}

/**
 * @brief I2C快速模式下SCL输出低电平长度直接配置使能
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] State 是否使能
 *
 * @return void
 */
KF_INLINE void I2c_LL_SetSCLDelayEnabled(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_TCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_TCTL_I2C0_TCTL_SCLLOWLEN_MASK;
    regValue |= State << HWIO_I2C0_TCTL_I2C0_TCTL_SCLLOWLEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_TCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->TCTL.bits.SCLLOWLEN, State);
#endif
}

/**
 * @brief 设置高速模式下SDA输出数据维持时间延迟阶段数
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] Delay 延迟阶段数

 * @return void
 */
KF_INLINE void I2c_LL_SetSCLDelay(I2c_RegisterMap_t *const Module, I2C_SclLen_t Delay)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_SCLLEN(Delay));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_TCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_TCTL_I2C0_TCTL_SCLLEN_MASK;
    regValue |= Delay << HWIO_I2C0_TCTL_I2C0_TCTL_SCLLEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_TCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->TCTL.bits.SCLLEN, Delay);
#endif
}

/**
 * @brief 设置高速模式下SDA输出数据维持时间延迟阶段数
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] Delay 延迟阶段数
 *
 * @return void
 */
KF_INLINE void I2c_LL_SetHighSpeedModeSDADelay(I2c_RegisterMap_t *const Module, I2C_Hsdalen_t Delay)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_TCTL_HSDALEN(Delay));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_TCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_TCTL_I2C0_TCTL_HSDALEN_MASK;
    regValue |= Delay << HWIO_I2C0_TCTL_I2C0_TCTL_HSDALEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_TCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->TCTL.bits.HSDALEN, Delay);
#endif
}

/**
 * @brief 设置I2C标准和快速模式下SDA输出数据维持时间延迟阶段数
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] Delay 延迟阶段数
 *
 * @return void
 */
KF_INLINE void I2c_LL_SetSDADelay(I2c_RegisterMap_t *const Module, I2C_Sdalen_t Delay)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_TCTL_SDALEN(Delay));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_TCTL_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_TCTL_I2C0_TCTL_SDALEN_MASK;
    regValue |= Delay << HWIO_I2C0_TCTL_I2C0_TCTL_SDALEN_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_TCTL_ADDR, regValue);
    // TODO: check if correct

#else
    REG_WRITE(Module->TCTL.bits.SDALEN, Delay);
#endif
}

/* I2C_IF_T */

/**
 * @brief 获取I2C中断标志
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] IntrIndex I2C中断类型索引
 *               I2C_INTR_INDEX_ADRM 地址匹配中断掩码
 *               I2C_INTR_INDEX_GC 广播呼叫中断掩码
 *               I2C_INTR_INDEX_MC 主机码（高速模式）中断掩码
 *               I2C_INTR_INDEX_ALERR 仲裁失败中断掩码
 *               I2C_INTR_INDEX_NACK 接收到未应答信号中断掩码
 *               I2C_INTR_INDEX_TXEND 传输结束中断掩码
 *               I2C_INTR_INDEX_RX 接收模式中断掩码
 *               I2C_INTR_INDEX_START 起始位中断掩码
 *               I2C_INTR_INDEX_STOP 停止位中断掩码
 *               I2C_INTR_INDEX_BYTE 字节传输中断掩码
 *               I2C_INTR_INDEX_SMBA SMBus模式的提醒中断掩码
 *               I2C_INTR_INDEX_SMBH SMBus模式的主机头地址中断掩码
 *               I2C_INTR_INDEX_SMBD SMBus模式的设备默认地址掩码
 *               I2C_INTR_INDEX_RXUDF RXFIFO下溢中断掩码
 *               I2C_INTR_INDEX_RXOVF RXFIFO上溢中断掩码
 *               I2C_INTR_INDEX_TXUDF TXFIFO下溢中断掩码
 *               I2C_INTR_INDEX_TXOVF TXFIFO上溢中断掩码
 *               I2C_INTR_INDEX_RXLSINGLE 最后一次接收单次传输请求中断
 *               I2C_INTR_INDEX_RXSINGLE  接收单次传输请求中断
 *               I2C_INTR_INDEX_RXLBURST  最后一次接收突发传输请求中断
 *               I2C_INTR_INDEX_RXBURST   接收突发传输请求中断
 *               I2C_INTR_INDEX_TXLSINGLE 最后一次发送单次传输请求中断
 *               I2C_INTR_INDEX_TXSINGLE  发送单次传输请求中断
 *               I2C_INTR_INDEX_TXLBURST  最后一次发送突发传输请求中断
 *               I2C_INTR_INDEX_TXBURST  发送突发传输请求中断
 *               I2C_INTR_INDEX_PEC        接收期间的PEC错误
 *               I2C_INTR_INDEX_SMBTO  超时错误
 *
 * @return bool
 * @retval false 该类型中断未置位
 *         true 该类型中断已置位
 */
KF_INLINE bool I2c_LL_GetIntrFlag(I2c_RegisterMap_t *const Module, I2c_IntrMask_t IntrMask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    return (bool)REG_BITS_READ(offsetAddr + HWIO_I2C0_IF_ADDR, 1U << (uint32_t)IntrMask, (uint32_t)IntrMask);
#else
    return (bool)REG_BITS_READ(Module->IF.reg, 1U << (uint32_t)IntrMask, (uint32_t)IntrMask);
#endif
}

/* I2C_IE_T */

/**
 * @brief 获取I2C中断使能
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] IntrIndex I2C中断类型索引
 *               I2C_INTR_INDEX_ADRM 地址匹配中断掩码
 *               I2C_INTR_INDEX_GC 广播呼叫中断掩码
 *               I2C_INTR_INDEX_MC 主机码（高速模式）中断掩码
 *               I2C_INTR_INDEX_ALERR 仲裁失败中断掩码
 *               I2C_INTR_INDEX_NACK 接收到未应答信号中断掩码
 *               I2C_INTR_INDEX_TXEND 传输结束中断掩码
 *               I2C_INTR_INDEX_RX 接收模式中断掩码
 *               I2C_INTR_INDEX_START 起始位中断掩码
 *               I2C_INTR_INDEX_STOP 停止位中断掩码
 *               I2C_INTR_INDEX_BYTE 字节传输中断掩码
 *               I2C_INTR_INDEX_SMBA SMBus模式的提醒中断掩码
 *               I2C_INTR_INDEX_SMBH SMBus模式的主机头地址中断掩码
 *               I2C_INTR_INDEX_SMBD SMBus模式的设备默认地址掩码
 *               I2C_INTR_INDEX_RXUDF RXFIFO下溢中断掩码
 *               I2C_INTR_INDEX_RXOVF RXFIFO上溢中断掩码
 *               I2C_INTR_INDEX_TXUDF TXFIFO下溢中断掩码
 *               I2C_INTR_INDEX_TXOVF TXFIFO上溢中断掩码
 *               I2C_INTR_INDEX_RXLSINGLE 最后一次接收单次传输请求中断
 *               I2C_INTR_INDEX_RXSINGLE  接收单次传输请求中断
 *               I2C_INTR_INDEX_RXLBURST  最后一次接收突发传输请求中断
 *               I2C_INTR_INDEX_RXBURST   接收突发传输请求中断
 *               I2C_INTR_INDEX_TXLSINGLE 最后一次发送单次传输请求中断
 *               I2C_INTR_INDEX_TXSINGLE  发送单次传输请求中断
 *               I2C_INTR_INDEX_TXLBURST  最后一次发送突发传输请求中断
 *               I2C_INTR_INDEX_TXBURST  发送突发传输请求中断
 *               I2C_INTR_INDEX_PEC        接收期间的PEC错误
 *               I2C_INTR_INDEX_SMBTO  超时错误
 *
 * @return bool
 * @retval false 未设置该类型中断使能
 *         true 已设置该类型中断使能
 */
KF_INLINE bool I2c_LL_GetIntrEnabled(I2c_RegisterMap_t *const Module, I2c_IntrMask_t IntrMask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    return (bool)REG_BITS_READ(offsetAddr + HWIO_I2C0_IE_ADDR, 1U << (uint32_t)IntrMask, (uint32_t)IntrMask);
#else
    return (bool)REG_BITS_READ(Module->IE.reg, 1U << (uint32_t)IntrMask, (uint32_t)IntrMask);
#endif
}

/**
 * @brief 设置I2C中断使能
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] IntrIndex I2C中断类型索引
 *               I2C_INTR_INDEX_ADRM 地址匹配中断掩码
 *               I2C_INTR_INDEX_GC 广播呼叫中断掩码
 *               I2C_INTR_INDEX_MC 主机码（高速模式）中断掩码
 *               I2C_INTR_INDEX_ALERR 仲裁失败中断掩码
 *               I2C_INTR_INDEX_NACK 接收到未应答信号中断掩码
 *               I2C_INTR_INDEX_TXEND 传输结束中断掩码
 *               I2C_INTR_INDEX_RX 接收模式中断掩码
 *               I2C_INTR_INDEX_START 起始位中断掩码
 *               I2C_INTR_INDEX_STOP 停止位中断掩码
 *               I2C_INTR_INDEX_BYTE 字节传输中断掩码
 *               I2C_INTR_INDEX_SMBA SMBus模式的提醒中断掩码
 *               I2C_INTR_INDEX_SMBH SMBus模式的主机头地址中断掩码
 *               I2C_INTR_INDEX_SMBD SMBus模式的设备默认地址掩码
 *               I2C_INTR_INDEX_RXUDF RXFIFO下溢中断掩码
 *               I2C_INTR_INDEX_RXOVF RXFIFO上溢中断掩码
 *               I2C_INTR_INDEX_TXUDF TXFIFO下溢中断掩码
 *               I2C_INTR_INDEX_TXOVF TXFIFO上溢中断掩码
 *               I2C_INTR_INDEX_RXLSINGLE 最后一次接收单次传输请求中断
 *               I2C_INTR_INDEX_RXSINGLE  接收单次传输请求中断
 *               I2C_INTR_INDEX_RXLBURST  最后一次接收突发传输请求中断
 *               I2C_INTR_INDEX_RXBURST   接收突发传输请求中断
 *               I2C_INTR_INDEX_TXLSINGLE 最后一次发送单次传输请求中断
 *               I2C_INTR_INDEX_TXSINGLE  发送单次传输请求中断
 *               I2C_INTR_INDEX_TXLBURST  最后一次发送突发传输请求中断
 *               I2C_INTR_INDEX_TXBURST  发送突发传输请求中断
 *               I2C_INTR_INDEX_PEC        接收期间的PEC错误
 *               I2C_INTR_INDEX_SMBTO  超时错误
 *
 * @return void
 */
KF_INLINE void I2c_LL_SetIntrEnabled(I2c_RegisterMap_t *const Module, I2c_IntrMask_t IntrMask, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_IE_ADDR + offsetAddr);
    regValue &= ~(uint32_t)0x1U << (uint32_t)IntrMask;
    regValue |= (uint32_t)State << (uint32_t)IntrMask;
    REG_WRITE(offsetAddr + HWIO_I2C0_IE_ADDR, regValue);
#else
    REG_BITS_WRITE(Module->IE.reg, (uint32_t)IntrMask, (uint32_t)State << (uint32_t)IntrMask);
#endif
}

/* I2C_IC_T */

/**
 * @brief 清除I2C中断标志
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] IntrIndex I2C中断类型索引
 *               I2C_INTR_INDEX_ADRM 地址匹配中断掩码
 *               I2C_INTR_INDEX_GC 广播呼叫中断掩码
 *               I2C_INTR_INDEX_MC 主机码（高速模式）中断掩码
 *               I2C_INTR_INDEX_ALERR 仲裁失败中断掩码
 *               I2C_INTR_INDEX_NACK 接收到未应答信号中断掩码
 *               I2C_INTR_INDEX_TXEND 传输结束中断掩码
 *               I2C_INTR_INDEX_RX 接收模式中断掩码
 *               I2C_INTR_INDEX_START 起始位中断掩码
 *               I2C_INTR_INDEX_STOP 停止位中断掩码
 *               I2C_INTR_INDEX_BYTE 字节传输中断掩码
 *               I2C_INTR_INDEX_SMBA SMBus模式的提醒中断掩码
 *               I2C_INTR_INDEX_SMBH SMBus模式的主机头地址中断掩码
 *               I2C_INTR_INDEX_SMBD SMBus模式的设备默认地址掩码
 *               I2C_INTR_INDEX_RXUDF RXFIFO下溢中断掩码
 *               I2C_INTR_INDEX_RXOVF RXFIFO上溢中断掩码
 *               I2C_INTR_INDEX_TXUDF TXFIFO下溢中断掩码
 *               I2C_INTR_INDEX_TXOVF TXFIFO上溢中断掩码
 *               I2C_INTR_INDEX_RXLSINGLE 最后一次接收单次传输请求中断
 *               I2C_INTR_INDEX_RXSINGLE  接收单次传输请求中断
 *               I2C_INTR_INDEX_RXLBURST  最后一次接收突发传输请求中断
 *               I2C_INTR_INDEX_RXBURST   接收突发传输请求中断
 *               I2C_INTR_INDEX_TXLSINGLE 最后一次发送单次传输请求中断
 *               I2C_INTR_INDEX_TXSINGLE  发送单次传输请求中断
 *               I2C_INTR_INDEX_TXLBURST  最后一次发送突发传输请求中断
 *               I2C_INTR_INDEX_TXBURST  发送突发传输请求中断
 *               I2C_INTR_INDEX_PEC        接收期间的PEC错误
 *               I2C_INTR_INDEX_SMBTO  超时错误
 *
 * @return void
 */
KF_INLINE void I2c_LL_ClearIntrFlag(I2c_RegisterMap_t *const Module, I2c_IntrMask_t IntrMask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_IC_ADDR + offsetAddr);
    regValue &= ~(uint32_t)0x1U << (uint32_t)IntrMask;
    regValue |= (uint32_t)0x1U << (uint32_t)IntrMask;
    REG_WRITE(offsetAddr + HWIO_I2C0_IC_ADDR, regValue);
#else
    REG_BIT_SET(Module->IC.reg, (uint32_t)0x1U << (uint32_t)IntrMask);
#endif
}

/* I2C_IS_T */

/**
 * @brief 置位I2C中断标志
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] IntrMask I2C中断类型掩码
 *               I2C_INTR_INDEX_ADRM 地址匹配中断掩码
 *               I2C_INTR_INDEX_GC 广播呼叫中断掩码
 *               I2C_INTR_INDEX_MC 主机码（高速模式）中断掩码
 *               I2C_INTR_INDEX_ALERR 仲裁失败中断掩码
 *               I2C_INTR_INDEX_NACK 接收到未应答信号中断掩码
 *               I2C_INTR_INDEX_TXEND 传输结束中断掩码
 *               I2C_INTR_INDEX_RX 接收模式中断掩码
 *               I2C_INTR_INDEX_START 起始位中断掩码
 *               I2C_INTR_INDEX_STOP 停止位中断掩码
 *               I2C_INTR_INDEX_BYTE 字节传输中断掩码
 *               I2C_INTR_INDEX_SMBA SMBus模式的提醒中断掩码
 *               I2C_INTR_INDEX_SMBH SMBus模式的主机头地址中断掩码
 *               I2C_INTR_INDEX_SMBD SMBus模式的设备默认地址掩码
 *               I2C_INTR_INDEX_RXUDF RXFIFO下溢中断掩码
 *               I2C_INTR_INDEX_RXOVF RXFIFO上溢中断掩码
 *               I2C_INTR_INDEX_TXUDF TXFIFO下溢中断掩码
 *               I2C_INTR_INDEX_TXOVF TXFIFO上溢中断掩码
 *               I2C_INTR_INDEX_RXLSINGLE 最后一次接收单次传输请求中断
 *               I2C_INTR_INDEX_RXSINGLE  接收单次传输请求中断
 *               I2C_INTR_INDEX_RXLBURST  最后一次接收突发传输请求中断
 *               I2C_INTR_INDEX_RXBURST   接收突发传输请求中断
 *               I2C_INTR_INDEX_TXLSINGLE 最后一次发送单次传输请求中断
 *               I2C_INTR_INDEX_TXSINGLE  发送单次传输请求中断
 *               I2C_INTR_INDEX_TXLBURST  最后一次发送突发传输请求中断
 *               I2C_INTR_INDEX_TXBURST  发送突发传输请求中断
 *               I2C_INTR_INDEX_PEC        接收期间的PEC错误
 *               I2C_INTR_INDEX_SMBTO  超时错误
 *
 * @return void
 */
KF_INLINE void I2c_LL_SetIntrFlag(I2c_RegisterMap_t *const Module, I2c_IntrMask_t IntrMask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_IS_ADDR + offsetAddr);
    regValue &= ~(uint32_t)0x1U << (uint32_t)IntrMask;
    regValue |= (uint32_t)0x1U << (uint32_t)IntrMask;
    REG_WRITE(offsetAddr + HWIO_I2C0_IS_ADDR, regValue);
#else
    REG_BIT_SET(Module->IS.reg, (uint32_t)0x1U << (uint32_t)IntrMask);
#endif
}

/* I2C_TXD_T */
/**
 * @brief 设置I2C发送数据TXFIFO
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] Data 发送数据
 *
 * @return void
 */
KF_INLINE void I2c_LL_SetTxBufferRegValue(I2c_RegisterMap_t *const Module, uint32_t Data)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    REG_WRITE(offsetAddr + HWIO_I2C0_TXD_ADDR, Data);
    // TODO: check if correct

#else
    REG_WRITE(Module->TXD.reg, Data);
#endif
}

/**
 * @brief 获取I2C接收数据
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 *
 * @return uint32_t 接收数据
 */
KF_INLINE uint32_t I2c_LL_GetRxBufferRegValue(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_RXD_ADDR + offsetAddr);
    regValue &= HWIO_I2C0_RXD_I2C0_RXD_RXD_MASK;
    regValue = regValue >> HWIO_I2C0_RXD_I2C0_RXD_RXD_SHFT;
    return (regValue);
    // TODO: check if correct

#else
    return REG_READ(Module->RXD.bits.RXD);
#endif
}

/**
 * @brief 软件写入PEC值
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] PecValue 要软件写入的Pec值
 *
 * @return void
 */
KF_INLINE void I2c_LL_SetPecrRegValue(I2c_RegisterMap_t *const Module, uint8_t PecValue)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_PECR_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_PECR_I2C0_PECR_PEC_MASK;
    regValue |= PecValue << HWIO_I2C0_PECR_I2C0_PECR_PEC_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_PECR_ADDR, regValue);
#else
    REG_WRITE(Module->PECR.bits.PEC, PecValue);
#endif
}

/**
 * @brief 软件写入超时阶段数
 *
 * @param[in] Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param[in] TimeoutValue 要软件写入的超时阶段数
 *
 * @return void
 */
KF_INLINE void I2c_LL_SetTimeoutValue(I2c_RegisterMap_t *const Module, uint16_t TimeoutValue)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

#ifdef SIMULATION
    uint32_t offsetAddr = ((uint32_t)((uintptr_t)Module)) & ~i2c_MODULE_BASE_ADDR;
    uint32_t regValue   = REG_READ(HWIO_I2C0_TOUT_ADDR + offsetAddr);
    regValue &= ~HWIO_I2C0_TOUT_I2C0_TOUT_TOUT_MASK;
    regValue |= TimeoutValue << HWIO_I2C0_TOUT_I2C0_TOUT_TOUT_SHFT;
    REG_WRITE(offsetAddr + HWIO_I2C0_TOUT_ADDR, regValue);
#else
    REG_WRITE(Module->TOUT.reg, TimeoutValue);
#endif
}
#ifdef __cplusplus
}
#endif

#endif
/* EOF */
