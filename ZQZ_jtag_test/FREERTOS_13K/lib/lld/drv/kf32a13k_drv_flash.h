/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_osc.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2024-01-10
 *  @Version         : V0.0.1.240110_alpha
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
 *  |2024-01-10    |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/
#ifndef KF32DA13K_DRV_FLASH_H_
#define KF32DA13K_DRV_FLASH_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a13k_reg_flash.h"

#ifdef KF_DRV_FLASH_ASSERT
#include "dev_assert.h"
#define KF_DRV_FLASH_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_FLASH_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
#ifndef INNER_INDATA
#define INNER_INDATA __attribute__((section(".indata")))
#endif

/* Flash LLD使用强制内联，由上层函数选择链接段(Flash0/Flash1/Ram等)，
(static inline建议编译器内联，若编译器忽视了static
inline，可能导致Flash编程/擦除代码链接段处于编程/擦除区域导致程序跑飞)*/
#ifndef KF_FORCE_INLINE
#define KF_FORCE_INLINE __attribute__((always_inline)) static inline
#endif

#define FLASH_PEUNLOCK_KEY1  (0x87654321U)
#define FLASH_PEUNLOCK_KEY2  (0x87654321U)
#define FLASH_REDUNLOCK_KEY1 (0x87654321U)
#define FLASH_REDUNLOCK_KEY2 (0x87654321U)
typedef enum
{
    /* DFlash0 忙状态标志位 */
    FLASH_STATUS_DATA_FLS_0_BUSY = 0,
    /* DFlash1 忙状态标志位 */
    FLASH_STATUS_DATA_FLS_1_BUSY = 1,
    /* PFlash0 忙状态标志位 */
    FLASH_STATUS_PROG_FLS_0_BUSY = 2,
    /* PFlash1 忙状态标志位 */
    FLASH_STATUS_PROG_FLS_1_BUSY = 3,
    /* 编程擦除控制器进入 DFlash 操作模式的状态标志位 */
    FLASH_STATUS_MODE_DFLASH = 6,
    /* 编程擦除控制器进入 PFlash 操作模式的状态标志位 */
    FLASH_STATUS_MODE_PFLASH = 7,
    /* 编程擦除控制器进入解保护模式的状态标志位 */
    FLASH_STATUS_MODE_PWMODE = 8,
    /* 校验和计算完成状态位 */
    FLASH_STATUS_MODE_CHECKSUM_CALC_DONE = 9,
    /* 冗余替换解锁状态位 */
    FLASH_STATUS_REDUNDACY_REPLACE_UNLOCK = 30,
    /* 编程擦除控制器解锁状态位 */
    FLASH_STATUS_PROG_ERASE_UNLOCK = 31,
} Flash_StatusIndex_t;
#define CHECK_FLASH_STATUS_INDEX(INDEX)                                                                                \
    ((INDEX <= FLASH_STATUS_PROG_FLS_1_BUSY) ||                                                                        \
     ((INDEX >= FLASH_STATUS_MODE_DFLASH) && (INDEX <= FLASH_STATUS_MODE_CHECKSUM_CALC_DONE)) ||                       \
     (INDEX == FLASH_STATUS_REDUNDACY_REPLACE_UNLOCK) || (INDEX == FLASH_STATUS_PROG_ERASE_UNLOCK))

typedef enum
{
    /* DFlash0 忙状态标志位 */
    FLASH_DATA_FLS_0_BUSY_CLR = 0,
    /* DFlash1 忙状态标志位 */
    FLASH_DATA_FLS_1_BUSY_CLR = 1,
    /* PFlash0 忙状态标志位 */
    FLASH_PROG_FLS_0_BUSY_CLR = 2,
    /* PFlash1 忙状态标志位 */
    FLASH_PROG_FLS_1_BUSY_CLR = 3,
    /* 校验和计算完成状态位 */
    FLASH_MODE_CHECKSUM_CALC_DONE_CLR = 8,
    /* 清除编程状态 */
    FLASH_PROG_CLR = 9,
    /* 清除擦除状态 */
    FLASH_ERASE_CLR = 10,
    /* 清除擦除状态 */
    FLASH_XPROG_CLR = 11,
    /* 冗余替换解锁状态位 */
    FLASH_REDUNDACY_REPLACE_UNLOCK_CLR = 30,
    /* 编程擦除控制器解锁状态位 */
    FLASH_PROG_ERASE_UNLOCK_CLR = 31,
} Flash_ClearStatusIndex_t;
#define CHECK_FLASH_CLEAR_STATUS_INDEX(INDEX)                                                                          \
    ((INDEX <= FLASH_PROG_FLS_1_BUSY_CLR) ||                                                                           \
     ((INDEX >= FLASH_MODE_CHECKSUM_CALC_DONE_CLR) && (INDEX <= FLASH_XPROG_CLR)) ||                                   \
     (INDEX == FLASH_REDUNDACY_REPLACE_UNLOCK_CLR) || (INDEX == FLASH_PROG_ERASE_UNLOCK_CLR))

typedef enum
{
    /* 未进入任何模式 */
    FLASH_MODE_NONE,
    /* 进入 PFlash 操作模式，允许编程或擦除 PFlash 区 */
    FLASH_MODE_PFLASH,
    /* 进入 DFlash 操作模式，允许编程或擦除 DFlash 区 */
    FLASH_MODE_DFLASH,
    /* 进入解保护模式 */
    FLASH_MODE_DEPROTECT,
} Flash_OperationMode_t;
#define CHECK_FLASH_OPERATION_MODE(MODE) (!(MODE >> 2))

typedef enum
{
    FLASH_ERASE_MODE_SECTOR,
    FLASH_ERASE_MODE_BLOCK,
    FLASH_ERASE_MODE_PFLASH_CHIP,
} Flash_EraseMode_t;
#define CHECK_FLASH_ERASE_MODE(MODE) ((uint32_t)MODE <= FLASH_ERASE_MODE_PFLASH_CHIP)

typedef enum
{
    FLASH_OPERATION_PROGRAM       = 0,
    FLASH_OPERATION_ERASE         = 1,
    FLASH_OPERATION_XPROGRAM      = 2,
    FLASH_OPERATION_PROGRAM_DONE  = 8,
    FLASH_OPERATION_ERASE_DONE    = 9,
    FLASH_OPERATION_XPROGRAM_DONE = 10,
} Flash_OperationIndex_t;
#define CHECK_FLASH_OPERATION_INDEX(INDEX)                                                                             \
    ((((uint32_t)INDEX <= FLASH_OPERATION_XPROGRAM_DONE) && ((uint32_t)INDEX >= FLASH_OPERATION_PROGRAM_DONE)) ||      \
     ((uint32_t)INDEX <= FLASH_OPERATION_XPROGRAM))

typedef enum
{
    /* PFlash保护 */
    FLAG_PFLASH_PROTECT = 0,
    /* DFlash保护 */
    FLAG_DFLASH_PROTECT = 1,
    /* 调试接口密码保护 */
    FLAG_DEBUG_INTERFACE_PROTECT = 2,
    /* 解除擦除计数器优先级保护 */
    FLAG_ERASE_CNT_PRIORITY_PROTECT = 3,
    /* BMHD保护 */
    FLAG_BMHD_PROTECT = 4,
    /* UCB_SWAP保护 */
    FLAG_UCB_SWAP_PROTECT = 5,
    /* 安全重测密码保护 */
    FLAG_SECURE_RETEST_PROTECT = 24,
} Flag_ProtectDisableIndex_t;
#define CHECK_FLASH_PROTECT_DISABLE_INDEX(INDEX)                                                                       \
    (((uint32_t)INDEX <= FLAG_UCB_SWAP_PROTECT) || (INDEX == FLAG_SECURE_RESET_PROTECT))

typedef enum
{
    /* UCB_BMHD0_ORIG 确认状态 */
    FLASH_BMHD0O_CONFIRM_STATUS = 0,
    /* UCB_BMHD1_ORIG 确认状态 */
    FLASH_BMHD1O_CONFIRM_STATUS = 2,
    /* UCB_SSW 确认状态 */
    FLASH_SSW_CONFIRM_STATUS = 8,
    /* UCB_USER 确认状态 */
    FLASH_USR_CONFIRM_STATUS = 10,
    /* UCB_TEST 确认状态 */
    FLASH_TEST_CONFIRM_STATUS = 12,
    /* UCB_HSMCFG 确认状态 */
    FLASH_HSMCFG_CONFIRM_STATUS = 14,
    /* UCB_BMHD0_COPY 确认状态 */
    FLASH_BMHD0C_CONFIRM_STATUS = 16,
    /* UCB_BMHD0_COPY 确认状态 */
    FLASH_BMHD1C_CONFIRM_STATUS = 18,
    /* UCB_REDSEC 确认状态 */
    FLASH_REDSEC_CONFIRM_STATUS = 24,
    /* UCB_RETEST 确认状态 */
    FLASH_RETEST_CONFIRM_STATUS = 30,
    /* UCB_PFLASH_ORIG 确认状态 */
    FLASH_PO_CONFIRM_STATUS = 32,
    /* UCB_DFLASH_ORIG 确认状态 */
    FLASH_DO_CONFIRM_STATUS = 34,
    /* UCB_DBG_ORIG 确认状态 */
    FLASH_DBGO_CONFIRM_STATUS = 36,
    /* UCB_HSM_ORIG 确认状态 */
    FLASH_HSMO_CONFIRM_STATUS = 38,
    /* UCB_HSMCONTP_ORIG 确认状态 */
    FLASH_HSMCONTP_CONFIRM_STATUS = 40,
    /* UCB_ECPRIO_ORIG 确认状态 */
    FLASH_ECO_CONFIRM_STATUS = 44,
    /* UCB_SWAP_ORIG 确认状态 */
    FLASH_SWAPO_CONFIRM_STATUS = 46,
    /* UCB_PFLASH_COPY 确认状态 */
    FLASH_PC_CONFIRM_STATUS = 48,
    /* UCB_DFLASH_COPY 确认状态 */
    FLASH_DC_CONFIRM_STATUS = 50,
    /* UCB_DBG_COPY 确认状态 */
    FLASH_DBGC_CONFIRM_STATUS = 52,
    /* UCB_HSM_COPY 确认状态 */
    FLASH_HSMC_CONFIRM_STATUS = 54,
    /* UCB_HSMCOTP_COPY 确认状态 */
    FLASH_HSMCOTPC_CONFIRM_STATUS = 56,
    /* UCB_ECPRIO_COPY 确认状态 */
    FLASH_ECPC_CONFIRM_STATUS = 60,
    /* UCB_SWAP_COPY 确认状态 */
    FLASH_SWAPC_CONFIRM_STATUS = 62,
    /* UCB_OTP_ORIG 确认状态 */
    FLASH_OTPO_CONFIRM_STATUS = 64,
    /* UCB_OTP_COPY 确认状态 */
    FLASH_OTPC_CONFIRM_STATUS = 66,
} Flash_ConfirmStatusIndex_t;
#define CHECK_FLASH_CONFIRM_INDEX(INDEX)                                                                               \
    ((INDEX == FLASH_BMHD0O_CONFIRM_STATUS) || (INDEX == FLASH_BMHD1O_CONFIRM_STATUS) ||                               \
     (INDEX == FLASH_SSW_CONFIRM_STATUS) || (INDEX == FLASH_USR_CONFIRM_STATUS) ||                                     \
     (INDEX == FLASH_SSW_CONFIRM_STATUS) || (INDEX == FLASH_TEST_CONFIRM_STATUS) ||                                    \
     (INDEX == FLASH_HSMCFG_CONFIRM_STATUS) || (INDEX == FLASH_HSMCFG_CONFIRM_STATUS) ||                               \
     (INDEX == FLASH_BMHD0C_CONFIRM_STATUS) || (INDEX == FLASH_BMHD1C_CONFIRM_STATUS) ||                               \
     (INDEX == FLASH_REDSEC_CONFIRM_STATUS) || (INDEX == FLASH_RETEST_CONFIRM_STATUS) ||                               \
     (INDEX == FLASH_PO_CONFIRM_STATUS) || (INDEX == FLASH_DO_CONFIRM_STATUS) ||                                       \
     (INDEX == FLASH_DBGO_CONFIRM_STATUS) || (INDEX == FLASH_HSMO_CONFIRM_STATUS) ||                                   \
     (INDEX == FLASH_HSMCONTP_CONFIRM_STATUS) || (INDEX == FLASH_ECO_CONFIRM_STATUS) ||                                \
     (INDEX == FLASH_SWAPO_CONFIRM_STATUS) || (INDEX == FLASH_PC_CONFIRM_STATUS) ||                                    \
     (INDEX == FLASH_DC_CONFIRM_STATUS) || (INDEX == FLASH_DBGC_CONFIRM_STATUS) ||                                     \
     (INDEX == FLASH_HSMC_CONFIRM_STATUS) || (INDEX == FLASH_HSMCOTPC_CONFIRM_STATUS) ||                               \
     (INDEX == FLASH_ECPC_CONFIRM_STATUS) || (INDEX == FLASH_SWAPC_CONFIRM_STATUS) ||                                  \
     (INDEX == FLASH_OTPO_CONFIRM_STATUS) || (INDEX == FLASH_OTPC_CONFIRM_STATUS))

typedef enum
{
    /* 操作错误 */
    FLASH_OPERATION_ERROR_INTR = 0,
    /* HCI指令错误 */
    FLASH_CMD_SEQUENCE_ERROR_INTR = 1,
    /* 保护错误 */
    FLASH_PROTECTION_ERROR_INTR = 2,
    /* 编程校验错误 */
    FLASH_PROGRAM_VERIFY_ERROR_INTR = 3,
    /* 擦除校验错误 */
    FLASH_ERASE_VERIFY_ERROR_INTR = 4,
    /* 擦除看门狗超时 */
    FLASH_WATCHDOG_ERROR_INTR = 5,
    /* 忙信号结果 */
    FLASH_END_OF_BUSY_ERROR_INTR = 31,
} Flash_ErrIntrEnableIndex_t;
#define CHECK_FLASH_ERROR_INTERRUPT_INDEX(INDEX)                                                                       \
    (((uint32_t)INDEX <= FLASH_WATCHDOG_ERROR_INTR) || ((uint32_t)INDEX == FLASH_END_OF_BUSY_ERROR_INTR))

typedef enum
{
    /* 操作错误 */
    FLASH_OPERATION_ERROR_STATUS = 0,
    /* HCI指令错误 */
    FLASH_CMD_SEQUENCE_ERROR_STATUS = 1,
    /* 保护错误 */
    FLASH_PROTECTION_ERROR_STATUS = 2,
    /* 编程校验错误 */
    FLASH_PROGRAM_VERIFY_ERROR_STATUS = 3,
    /* 擦除校验错误 */
    FLASH_ERASE_VERIFY_ERROR_STATUS = 4,
    /* SRI总线地址ECC错误 */
    FLASH_SRI_BUS_ADDR_ERROR_STATUS = 5,
    /* ORIG错误 */
    FLASH_ORIG_ERROR_STATUS = 6,
    /* 看门狗定时器超时错误 */
    FLASH_WATCHDOG_ERROR_STATUS = 7,
} Flash_ErrIntrStatusIndex_t;
#define CHECK_FLASH_ERROR_STATUS_INDEX(INDEX) (!(INDEX >> 3))

typedef enum
{
    FLASH_ECC_ONE_BIT_ERROR              = 0,
    FLASH_ECC_TWO_BIT_ERROR              = 1,
    FLASH_ECC_MULTI_BIT_ERROR            = 2,
    FLASH_ECC_ANY_RD_ERROR               = 7,
    FLASH_ECC_ACCUMULATE_ONE_BIT_ERROR   = 16,
    FLASH_ECC_ACCUMULATE_TWO_BIT_ERROR   = 17,
    FLASH_ECC_ACCUMULATE_MULTI_BIT_ERROR = 19,
    FLASH_ECC_ACCUMULATE_ANY_RD_ERROR    = 23,
} Flash_EccStatusIndex_t;
#define CHECK_FLASH_ECC_STATUS_INDEX(INDEX)                                                                            \
    ((INDEX == FLASH_ECC_ONE_BIT_ERROR) || (INDEX == FLASH_ECC_TWO_BIT_ERROR) ||                                       \
     (INDEX == FLASH_ECC_MULTI_BIT_ERROR)(INDEX == FLASH_ECC_ANY_RD_ERROR) ||                                          \
     (INDEX == FLASH_ECC_ACCUMULATE_ONE_BIT_ERROR) ||                                                                  \
     (INDEX == FLASH_ECC_ACCUMULATE_TWO_BIT_ERROR)(INDEX == FLASH_ECC_ACCUMULATE_MULTI_BIT_ERROR) ||                   \
     (INDEX == FLASH_ECC_ACCUMULATE_ANY_RD_ERROR))

typedef enum
{
    FLASH_ECC_CORRECTION_ENABLED  = 0U,
    FLASH_ECC_CORRECTION_DISABLED = 3U,
} Flash_EccCorrectionDis_t;
#define CHECK_FLASH_ECC_CORRECTION_DIS(STATUS)                                                                         \
    ((STATUS == FLASH_ECC_CORRECTION_ENABLED) || (STATUS == FLASH_ECC_CORRECTION_DISABLED))

typedef enum
{
    FLASH_ECC_TRAP_ENABLED  = 0U,
    FLASH_ECC_TRAP_DISABLED = 3U,
} Flash_EccTrapDis_t;
#define CHECK_FLASH_ECC_TRAP_DIS(STATUS) ((STATUS == FLASH_ECC_TRAP_ENABLED) || (STATUS == FLASH_ECC_TRAP_DISABLED))

/* 待写入数据32位对齐 */
#define CHECK_FLASH_PROGRAM_DATA_PTR(BUFFER) (!((uint32_t)BUFFER & 0x3U))

/* 常规编程2字(8字节)、快速编程PFlash32字(128字节)、快速编程DFlash8字(32字节) */
#define CHECK_FLASH_PROGRAM_DATA_LENGTH(LENGTH) ((LENGTH == 2U) || (LENGTH == 32) || (LENGTH == 8))

/* 目标地址64位对齐 */
#define CHECK_FLASH_PROGRAM_ADDRESS(ADDRESS) (!(ADDRESS & 0x7U))

/* 扇区地址2K对齐 */
#define CHECK_FLASH_SECTOR_ADDRESS(ADDRESS) (!(ADDRESS & 0x7FFU))

/* 校验和地址128位对齐 */
#define CHECK_FLASH_CHECKSUM_ADDRESS(ADDRESS) (!(ADDRESS & 0xFU))

/* 校验和结果缓冲区32位对齐 */
#define CHECK_FLASH_CHECKSUM_RESULT_BUFF(BUFF) (!((uint32_t)BUFF & 0x3U) && ((uint32_t)BUFF != NULL_PTR))

/* ECC纠错码 */
#define CHECK_FLASH_ECC_CORRECTION_CODE(CODE) (!((uint32_t)CODE >> 22U))

/* FPLASH等待周期数*/
#define CHECK_PFLASH_READ_CLOCK_CYCLE(CYCLE) (!((uint32_t)CYCLE >> 6U))

/* FPLASH ECC纠正周期数*/
#define CHECK_PFLASH_ECC_CORRECTION_CLOCK_CYCLE(CYCLE) (!((uint32_t)CYCLE >> 3U))

/* DPLASH等待周期数*/
#define CHECK_DFLASH_READ_CLOCK_CYCLE(CYCLE) (!((uint32_t)CYCLE >> 8U))

/* DPLASH ECC纠正周期数*/
#define CHECK_DFLASH_ECC_CORRECTION_CLOCK_CYCLE(CYCLE) (!((uint32_t)CYCLE >> 3U))
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/* FLASH_ID_T */

/**
 * @brief Flash获取模块版本号
 *
 *
 * @param void
 * @retval uint32_t 模块版本号
 */
KF_FORCE_INLINE uint32_t Flash_LL_GetModuleVersion(void)
{
    return (FLASH_PTR->FLASH_ID.bits.MOD_REV);
}

/**
 * @brief Flash获取模块类型
 *
 *
 * @param void
 * @retval uint32_t 模块类型
 */
KF_FORCE_INLINE uint32_t Flash_LL_GetModuleType(void)
{
    return (FLASH_PTR->FLASH_ID.bits.MOD_TYPE);
}

/**
 * @brief Flash获取模块编号
 *
 *
 * @param void
 * @retval uint32_t 模块编号
 */
KF_FORCE_INLINE uint32_t Flash_LL_GetModuleNumber(void)
{
    return (FLASH_PTR->FLASH_ID.bits.MOD_NUMBER);
}

/*  FLASH_STA_T */

/**
 * @brief Flash获取状态标志
 *
 *
 * @param Index
 *        FLASH_DATA_FLS_0_BUSY DFlash0 忙状态标志位
 *        FLASH_DATA_FLS_1_BUSY DFlash1 忙状态标志位
 *        FLASH_PROG_FLS_0_BUSY PFlash0 忙状态标志位
 *        FLASH_PROG_FLS_1_BUSY PFlash1 忙状态标志位
 *        FLASH_MODE_DFLASH 编程擦除控制器进入 DFlash 操作模式的状态标志位
 *        FLASH_MODE_PFLASH 编程擦除控制器进入 PFlash 操作模式的状态标志位
 *        FLASH_MODE_PWMODE 编程擦除控制器进入解保护模式的状态标志位
 *        FLASH_MODE_CHECKSUM_CALC_DONE 校验和计算完成状态位
 *        FLASH_REDUNDACY_REPLACE_UNLOCK 冗余替换解锁状态位
 *        FLASH_PROG_ERASE_UNLOCK 编程擦除控制器解锁状态位
 * @retval bool
 *        false 状态标志未置位
 *        true 状态标志置位
 */
KF_FORCE_INLINE bool Flash_LL_GetFlagStatus(Flash_StatusIndex_t Index)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_STATUS_INDEX(Index));
    return (bool)(REG_BITS_READ(FLASH_PTR->FLASH_STA.reg, (1U << (uint32_t)Index), Index));
}

/*  FLASH_CRL_T */
/**
 * @brief Flash清除状态标志
 *
 *
 * @param Index
 *        FLASH_DATA_FLS_0_BUSY DFlash0 忙状态标志位
 *        FLASH_DATA_FLS_1_BUSY DFlash1 忙状态标志位
 *        FLASH_PROG_FLS_0_BUSY PFlash0 忙状态标志位
 *        FLASH_PROG_FLS_1_BUSY PFlash1 忙状态标志位
 *        FLASH_MODE_CHECKSUM_CALC_DONE 校验和计算完成状态位
 *        FLASH_REDUNDACY_REPLACE_UNLOCK 冗余替换解锁状态位
 *        FLASH_PROG_ERASE_UNLOCK 编程擦除控制器解锁状态位
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_ClearFlagStatus(Flash_ClearStatusIndex_t Index)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_CLEAR_STATUS_INDEX(Index));
    REG_BITS_WRITE(FLASH_PTR->FLASH_CRL.reg, (1U << (uint32_t)Index), (1U << (uint32_t)Index));
}

/*  FLASH_CTL_T */
/**
 * @brief Flash使能编程与擦除
 *
 *
 * @param Status
 *        false 关闭，编程擦除控制器禁止擦除与编程
 *        true 使能，编程擦除控制器允许擦除与编程
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetFlashEraseEnabled(bool Status)
{
    FLASH_PTR->FLASH_CTL.bits.ENPE = (uint32_t)Status;
}

/**
 * @brief PFlash等待状态 ECC错误注入
 *
 *
 * @param Status
 *        false 没有请求错误注入
 *        true 在ECC保护PFlash等待状态时注入一个错误
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_WaitStateECCErrInjection(bool Status)
{
    FLASH_PTR->FLASH_CTL.bits.WSERRINJ = (uint32_t)Status;
}

/**
 * @brief 禁止读访问 PFlash
 *
 *
 * @param Status
 *        false 读访问PFlash被允许
 *        true  读访问PFlash被禁止
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_DisableReadPFLASH(bool Status)
{
    FLASH_PTR->FLASH_CTL.bits.DDFP = (uint32_t)Status;
}

/**
 * @brief 在 DF0_EEPROM 端禁止取数据
 *
 *
 * @param Status
 *        false 读访问 DF0_EEPROM 被允许
 *        true  读访问 DF0_EEPROM 被禁止
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_DisableReadDFLASH(bool Status)
{
    FLASH_PTR->FLASH_CTL.bits.DDFD = (uint32_t)Status;
}

/*  FLASH_OPE_T */
/**
 * @brief 控制编程擦除控制器进入PFlash操作模式或DFlash操作模式
 *
 *
 * @param Mode
 *        FLASH_MODE_NONE 未进入任何模式
 *        FLASH_MODE_PFLASH 进入 PFlash 操作模式，允许编程或擦除 PFlash 区
 *        FLASH_MODE_DFLASH 进入 DFlash 操作模式，允许编程或擦除 DFlash 区
 *        FLASH_MODE_DEPROTECT 进入解保护模式
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SelectOperationMode(Flash_OperationMode_t Mode)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_OPERATION_MODE(Mode));
    FLASH_PTR->FLASH_OPE.bits.PEMOD = (uint32_t)Mode;
}

/**
 * @brief 触发编程命令，令编程擦除控制器执行编程序列
 *
 *
 * @param Status
 *        false 编程擦除控制器不执行编程序列
 *        true 编程擦除控制器执行编程序列
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_TriggerProgramCmd(bool Status)
{
    FLASH_PTR->FLASH_OPE.bits.PGM = (uint32_t)Status;
}

/**
 * @brief 触发编程命令，令编程擦除控制器执行单次编程序列
 *
 *
 * @param Status
 *        false 编程擦除控制器不执行编程序列
 *        true 编程擦除控制器执行编程序列
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_TriggerProgramOnceCmd(bool Status)
{
    FLASH_PTR->FLASH_OPE.bits.OPGM = (uint32_t)Status;
}

/**
 * @brief 触发擦除命令，令编程擦除控制器执行擦除序列
 *
 *
 * @param Status
 *        false 编程擦除控制器不执行擦除序列
 *        true 编程擦除控制器执行擦除序列
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_TriggerEraseCmd(bool Status)
{
    FLASH_PTR->FLASH_OPE.bits.ERS = (uint32_t)Status;
}

/**
 * @brief 触发快速编程命令，令编程擦除控制器执行快速编程序列
 *
 *
 * @param Status
 *        false 编程擦除控制器不执行快速编程序列
 *        true 编程擦除控制器执行快速编程序列
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_TriggerXProgramCmd(bool Status)
{
    FLASH_PTR->FLASH_OPE.bits.XPGM = (uint32_t)Status;
}

KF_FORCE_INLINE void Flash_LL_TriggerXProgramOnceCmd(bool Status)
{
    FLASH_PTR->FLASH_OPE.bits.OXPGM = (uint32_t)Status;
}

/**
 * @brief 触发冗余替换命令
 *
 *
 * @param Status
 *        false 无效
 *        true 编程擦除控制器执行冗余替换
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_TriggerRedundantReplaceCmd(bool Status)
{
    FLASH_PTR->FLASH_OPE.bits.REDM = (uint32_t)Status;
}

/**
 * @brief 启动 SIG 计算
 *
 *
 * @param Status
 *        false 无效
 *        true 启动SIG计算
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_TriggerSigCalcCmd(bool Status)
{
    FLASH_PTR->FLASH_OPE.bits.SIGGO = (uint32_t)Status;
}

/**
 * @brief 选择FLASH擦除模式
 *
 *
 * @param Mode
 *        FLASH_ERASE_MODE_SECTOR 扇擦
 *        FLASH_ERASE_MODE_BLOCK 块擦
 *        FLASH_ERASE_MODE_PFLASH_CHIP 片擦，DFLASH 不支持片擦
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SelectEraseMode(Flash_EraseMode_t Mode)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_ERASE_MODE(Mode));
    FLASH_PTR->FLASH_OPE.bits.ERMOD = (uint32_t)Mode;
}

/*  FLASH_OPESTA_T */
/**
 * @brief 获取Flash操作状态
 *
 *
 * @param Index
 *        FLASH_OPERATION_PROGRAM 正在编程状态标志位
 *        FLASH_OPERATION_ERASE 擦除状态
 *        FLASH_OPERATION_XPROGRAM 正在快速编程状态标志位
 * @retval void
 */
KF_FORCE_INLINE bool Flash_LL_GetOperationStatus(Flash_OperationIndex_t Index)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_OPERATION_INDEX(Index));
    return (bool)(REG_BITS_READ(FLASH_PTR->FLASH_OPESTA.reg, (1U << (uint32_t)Index), (uint32_t)Index));
}

/*  FLASH_PEKEYR_T */
/**
 * @brief 编程擦除解锁
 * @details 连续写入特定的 KEY1 和 KEY2 值，可将FLASH_STA.PEUNLOCK 状态标志位置 1。
 *
 *
 * @param void
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_ProgEraseUnlock()
{
    REG_WRITE(FLASH_PTR->FLASH_PEKEYR.bits.KEY , FLASH_PEUNLOCK_KEY1);
    REG_WRITE(FLASH_PTR->FLASH_PEKEYR.bits.KEY , FLASH_PEUNLOCK_KEY2);
}

/*  FLASH_PEKEYR_T */
/**
 * @brief 冗余替换功能解锁
 * @details 连续写入特定的 KEY1 和 KEY2 值，可将FLASH_STA.REDUNLOCK 状态标志位置 1。
 *
 *
 * @param void
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_RedundantSwapUnlock()
{
    REG_WRITE(FLASH_PTR->FLASH_REDKEYR.bits.KEY , FLASH_REDUNLOCK_KEY1);
    REG_WRITE(FLASH_PTR->FLASH_REDKEYR.bits.KEY , FLASH_REDUNLOCK_KEY2);
}

/* FLASH_PEDATAx_T */
/**
 * @brief 设置Flash待编程数据
 * @details 为编程或快速编程提供数据。最小单位编程中使用PEDATA0 和 PEDATA1 进行 64bit 编程，批量编程中需要用 32 个
 * PEDATAx 进行 1024 位的快速编程
 *
 *
 * @param Buffer 字地址指针, 必须4字节对齐
 * @param Length 编程长度，单位：32位字
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetProgramData(uint32_t *Buffer, uint32_t Length)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_PROGRAM_DATA_PTR(Buffer));
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_PROGRAM_DATA_LENGTH(Length));
    for (uint32_t i = 0; i < Length; i++)
    {
        FLASH_PTR->FLASH_PEDATAx[i].bits.PDATA = Buffer[i];
    }
}

/* FLASH_PELADR_T */
/**
 * @brief 设置Flash编程擦除逻辑地址
 * @details 向编程擦除控制器提供编程逻辑地址或擦除的扇/块逻辑地址
 *
 *
 * @param Addr 向编程擦除控制器提供编程逻辑地址或擦除的扇/块逻辑地址
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetProgEraseLogicAddress(uint32_t Addr)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_PROGRAM_ADDRESS(Addr));
    REG_WRITE(FLASH_PTR->FLASH_PELADR.bits.ADR , Addr);
}

/* FLASH_PEPADR_T */

/**
 * @brief 获取Flash编程擦除物理地址
 * @details 显示编程擦除控制器操作逻辑地址对应的物理地址，支持 PFlash 与 DFlash。
 *
 *
 * @param void
 * @retval uint32_t 编程擦除控制器操作逻辑地址对应的物理地址
 */
KF_FORCE_INLINE uint32_t Flash_LL_GetProgErasePhysicalAddress(void)
{
    return (FLASH_PTR->FLASH_PEPADR.bits.ADR);
}

/* FLASH_XPEPADR_T */

/**
 * @brief 为冗余替换指令提供故障扇区逻辑地址
 * @attention 地址必须每扇区(2K)对齐
 *
 *
 * @param Addr 扇区地址
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetRedundantSectorLogicAddress(uint32_t Addr)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_PROGRAM_ADDRESS(Addr));
    REG_WRITE(FLASH_PTR->FLASH_REDLADR.bits.ADR , Addr);
}

/* FLASH_XPEPADR_T */

/**
 * @brief 获取Flash快速编程物理地址
 * @details 显示编程擦除控制器快速编程操作逻辑地址对应的物理地址，支持 PFlash 与 DFlash。
 *
 *
 * @param void
 * @retval uint32_t 快速编程控制器操作逻辑地址对应的物理地址
 */
KF_FORCE_INLINE uint32_t Flash_LL_GetXProgPhysicalAddress(void)
{
    return (FLASH_PTR->FLASH_XPEPADR.bits.ADR);
}

/* FLASH_REDLADR_T */

/**
 * @brief 设置Flash快速编程逻辑地址
 * @details 为冗余替换指令提供故障扇区的逻辑地址，地址必须每扇区对齐。
 *
 *
 * @param Addr 扇区逻辑地址
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetXProgLogicAddress(uint32_t Addr)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_SECTOR_ADDRESS(Addr));
    REG_WRITE(FLASH_PTR->FLASH_XPELADR.bits.ADR , Addr);
}

/* FLASH_PETIMECTL_T */

/**
 * @brief 配置编程擦除看门狗定时器的周期时间。
 * @details 周期时间为T=TIMSET*1us。
 *          看门狗周期范围Tmin=100us，Tmax=50ms。
 *          若TIMSET小于100，则TIMSET等于100。
 *
 *
 * @param Time 看门狗定时器周期
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetProgEraseWdgTime(uint16_t Time)
{
    REG_WRITE(FLASH_PTR->FLASH_PETIMECTL.bits.TIMSET , Time);
}

/* FLASH_CSSTART_T */

/**
 * @brief 设置Flash校验和起始地址
 * @attention 计算Checksum的首地址必须128位对齐
 *
 *
 * @param Addr 计算Checksum的首地址
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetChecksumStartAddr(uint32_t Addr)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_CHECKSUM_ADDRESS(Addr));
    REG_WRITE(FLASH_PTR->FLASH_CSSTART.bits.CKSTADDR , Addr);
}

/* FLASH_CSSTOP_T */

/**
 * @brief 设置Flash校验和结束地址
 * @attention 计算Checksum的结束地址必须128位对齐
 *
 *
 * @param Addr 计算Checksum的尾地址
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetChecksumStopAddr(uint32_t Addr)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_CHECKSUM_ADDRESS(Addr));
    REG_WRITE(FLASH_PTR->FLASH_CSSTOP.bits.CKSPADDR , Addr);
}

/* FLASH_CSRES0_T */
/* FLASH_CSRES1_T */
/* FLASH_CSRES2_T */
/* FLASH_CSRES3_T */

/**
 * @brief 获取校验和计算结果
 * @details 计算结果长度128bit，ResultBuffPtr需要指向至少128bit的内存；
 * @attention ResultBuffPtr应按字对齐
 *
 * @param ResultBuffPtr 存储计算Checksum结果的指针
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_GetChecksumResult(uint32_t *ResultBuffPtr)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_CHECKSUM_RESULT_BUFF(ResultBuffPtr));
    ResultBuffPtr[0] = FLASH_PTR->FLASH_CSRES0.reg;
    ResultBuffPtr[1] = FLASH_PTR->FLASH_CSRES1.reg;
    ResultBuffPtr[2] = FLASH_PTR->FLASH_CSRES2.reg;
    ResultBuffPtr[3] = FLASH_PTR->FLASH_CSRES3.reg;
}

/* FLASH_PROSTA_T */

/**
 * @brief 获取Flash保护解锁状态
 *
 * @param Index
 *        FLAG_PFLASH_PROTECT PFlash保护
 *        PFlash保护通过UCB_PFLASH_ORIG和UCB_PFLASH_COPY配置，通过“解保护指令”输入正确密钥解除PFlash保护，该位域被置1。
 *
 *        FLAG_DFLASH_PROTECT DFlash保护
 *        DFlash保护通过UCB_DFLASH_ORIG和UCB_DFLASH_COPY配置，通过“解保护指令”输入正确密钥解除DFlash保护，该位域被置1。
 *
 *        FLAG_DEBUG_INTERFACE_PROTECT 调试接口密码保护
 *        由 UCB_DBG_ORIG 和 UCB_DBG_COPY 配置调试接口保护，通过“解保护指令”输入正确密钥解除调试密码接口，该位域被置1。
 *
 *        FLAG_ERASE_CNT_PRIORITY_PROTECT 解除擦除计数器优先级保护
 *        由 UCB_ECPRIO_ORIG 和 UCB_ECPRIO_COPY
 * 配置擦除计数器优先级保护，通过“解保护指令”输入正确密钥解除该保护，位域被置1。
 *
 *        FLAG_BMHD_PROTECT BMHD保护
 *        由UCB_BMHD0_ORIG和UCB_BMHD0_COPY配置BMHD 保护，通过“解保护指令”输入正确密钥解除该保护，位域被置 1。
 *
 *        FLAG_UCB_SWAP_PROTECT UCB_SWAP保护
 *        由 UCB_SWAP_ORIG 和 UCB_SWAP_COPY 配置UCB_SWAP保护，通过“解保护指令”输入正确密钥解除该保护，位域被置 1。
 *
 *        FLAG_SECURE_RESET_PROTECT 安全重测密码保护
 * @retval void
 */
KF_FORCE_INLINE bool Flash_LL_GetProtectDisableStatus(Flag_ProtectDisableIndex_t Index)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_PROTECT_DISABLE_INDEX(Index));
    return (bool)REG_BITS_READ(FLASH_PTR->FLASH_PROSTA.reg, (1U << (uint32_t)Index), Index);
}

/* FLASH_CFMSTA0_T */
/* FLASH_CFMSTA1_T */
/* FLASH_CFMSTA2_T */

/**
 * @brief 获取Flash确认状态
 *
 * @param Index 状态索引
 *        FLASH_BMHD0O_CONFIRM_STATUS UCB_BMHD0_ORIG 确认状态
 *        FLASH_BMHD1O_CONFIRM_STATUS UCB_BMHD1_ORIG 确认状态
 *        FLASH_SSW_CONFIRM_STATUS UCB_SSW 确认状态
 *        FLASH_USR_CONFIRM_STATUS UCB_USER 确认状态
 *        FLASH_TEST_CONFIRM_STATUS UCB_TEST 确认状态
 *        FLASH_HSMCFG_CONFIRM_STATUS UCB_HSMCFG 确认状态
 *        FLASH_BMHD0C_CONFIRM_STATUS UCB_BMHD0_COPY 确认状态
 *        FLASH_BMHD1C_CONFIRM_STATUS UCB_BMHD1_COPY 确认状态
 *        FLASH_REDSEC_CONFIRM_STATUS UCB_REDSEC 确认状态
 *        FLASH_RETEST_CONFIRM_STATUS UCB_RETEST 确认状态
 *        FLASH_PO_CONFIRM_STATUS UCB_PFLASH_ORIG 确认状态
 *        FLASH_DO_CONFIRM_STATUS UCB_DFLASH_ORIG 确认状态
 *        FLASH_DBGO_CONFIRM_STATUS UCB_DBG_ORIG 确认状态
 *        FLASH_HSMO_CONFIRM_STATUS UCB_HSM_ORIG 确认状态
 *        FLASH_HSMCONTP_CONFIRM_STATUS UCB_HSMCONTP_ORIG 确认状态
 *        FLASH_ECO_CONFIRM_STATUS UCB_ECPRIO_ORIG 确认状态
 *        FLASH_SWAPO_CONFIRM_STATUS UCB_SWAP_ORIG 确认状态
 *        FLASH_PC_CONFIRM_STATUS UCB_PFLASH_COPY 确认状态
 *        FLASH_DC_CONFIRM_STATUS UCB_DFLASH_COPY 确认状态
 *        FLASH_DBGC_CONFIRM_STATUS UCB_DBG_COPY 确认状态
 *        FLASH_HSMC_CONFIRM_STATUS UCB_HSM_COPY 确认状态
 *        FLASH_HSMCOTPC_CONFIRM_STATUS UCB_HSMCOTP_COPY 确认状态
 *        FLASH_ECPC_CONFIRM_STATUS UCB_ECPRIO_COPY 确认状态
 *        FLASH_SWAPC_CONFIRM_STATUS UCB_SWAP_COPY 确认状态
 *        FLASH_OTPO_CONFIRM_STATUS UCB_OTP_ORIG 确认状态
 *        FLASH_OTPC_CONFIRM_STATUS UCB_OTP_COPY 确认状态
 * @retval uint32_t
 *         0b00 状态未读
 *         0b01 状态解锁
 *         0b10 状态已确认
 *         0b11 状态发出错误
 */
KF_FORCE_INLINE uint32_t Flash_LL_GetUcbConfirmStatus(Flash_ConfirmStatusIndex_t Index)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_CONFIRM_INDEX(Index));
    uint32_t regIndex = (uint32_t)Index >> 5;
    uint32_t pos      = (uint32_t)Index - 32U * regIndex;
    return (REG_BITS_READ((&FLASH_PTR->FLASH_CFMSTA0.reg)[regIndex], (0x3U << pos), pos));
}

/**
 * @brief 设置Flash错误中断使能状态
 *
 *
 * @param Index 错误中断索引
 *                FLASH_OPERATION_ERROR_INTR 操作错误
 *                FLASH_CMD_SEQUENCE_ERROR_INTR  HCI 指令错误
 *                FLASH_PROTECTION_ERROR_INTR 保护错误
 *                FLASH_PROGRAM_VERIFY_ERROR_INTR 编程校验错误
 *                FLASH_ERASE_VERIFY_ERROR_INTR 擦除校验错误
 *                FLASH_WATCHDOG_ERROR_INTR  擦除看门狗超时
 *                FLASH_END_OF_BUSY_ERROR_INTR 忙信号结果
 * @param Status 使能状态
 *                false 错误中断禁用
 *                true 错误中断使能
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetErrorInterruptEnabled(Flash_ErrIntrEnableIndex_t Index, bool Status)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_ERROR_INTERRUPT_INDEX(Index));
    REG_BITS_WRITE(FLASH_PTR->FLASH_EERIE.reg, (1U << (uint32_t)Index), ((uint32_t)Status << (uint32_t)Index));
}

/**
 * @brief 获取Flash错误状态
 *
 *
 *
 * @param Index
 *                FLASH_OPERATION_ERROR_STATUS 操作错误
 *                FLASH_CMD_SEQUENCE_ERROR_STATUS  HCI 指令错误
 *                FLASH_PROTECTION_ERROR_STATUS 保护错误
 *                FLASH_PROGRAM_VERIFY_ERROR_STATUS 编程校验错误
 *                FLASH_ERASE_VERIFY_ERROR_STATUS 擦除校验错误
 *                FLASH_SRI_BUS_ADDR_ERROR_STATUS SRI总线地址ECC错误
 *                FLASH_ORIG_ERROR_STATUS ORIG 错误
 *                FLASH_WATCHDOG_ERROR_STATUS  看门狗超时错误
 * @retval bool
 *               false 没有错误
 *               true 检测到错误
 */
KF_FORCE_INLINE bool Flash_LL_GetErrorStatus(Flash_ErrIntrStatusIndex_t Index)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_ERROR_STATUS_INDEX(Index));
    return (bool)REG_BITS_READ(FLASH_PTR->FLASH_ERRSTA.reg, (1U << (uint32_t)Index), (uint32_t)Index);
}

KF_FORCE_INLINE uint32_t Flash_LL_GetErrorStatusReg()
{
    return (REG_BITS_READ(FLASH_PTR->FLASH_ERRSTA.reg, 0xFFU, 0U));
}

/**
 * @brief 清除Flash错误状态标志
 *
 *
 * @param Index 错误状态索引
 *                FLASH_OPERATION_ERROR_STATUS 操作错误
 *                FLASH_CMD_SEQUENCE_ERROR_STATUS  HCI 指令错误
 *                FLASH_PROTECTION_ERROR_STATUS 保护错误
 *                FLASH_PROGRAM_VERIFY_ERROR_STATUS 编程校验错误
 *                FLASH_ERASE_VERIFY_ERROR_STATUS 擦除校验错误
 *                FLASH_SRI_BUS_ADDR_ERROR_STATUS SRI总线地址ECC错误
 *                FLASH_ORIG_ERROR_STATUS ORIG 错误
 *                FLASH_WATCHDOG_ERROR_STATUS  看门狗超时错误
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_ClearErrorInterruptStatus(Flash_ErrIntrStatusIndex_t Index)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_ERROR_STATUS_INDEX(Index));
    REG_BITS_WRITE(FLASH_PTR->FLASH_ERRCLR.reg, (1U << (uint32_t)Index), (1U << (uint32_t)Index));
}

/**
 * @brief 获取ECC状态
 *
 *
 * @param Index ECC状态索引
 *                FLASH_ECC_RD_ONE_BIT_ERROR 读访问单bit ECC错误
 *                FLASH_ECC_RD_TWO_BIT_ERROR 读访问双bit ECC错误
 *                FLASH_ECC_RD_MULTI_BIT_ERROR 读访问多bit ECC错误
 *                FLASH_ECC_RD_ANY_ERROR 任何读访问ECC错误
 *                FLASH_ECC_RD_ACCUMULATE_ONE_BIT_ERROR 累计单bit ECC错误
 *                FLASH_ECC_RD_ACCUMULATE_TWO_BIT_ERROR 累计双bit ECC错误
 *                FLASH_ECC_RD_ACCUMULATE_MULTI_BIT_ERROR 累计多bit ECC错误
 *                FLASH_ECC_RD_ACCUMULATE_ANY_ERROR 累计任何读访问 ECC错误
 * @retval void
 */
KF_FORCE_INLINE bool Flash_LL_GetEccStatus(Flash_EccStatusIndex_t Index)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_ECC_STATUS_INDEX(Index));
    return (bool)(REG_BITS_READ(FLASH_PTR->DF_ECCSTA.reg, (1U << (uint32_t)Index), (uint32_t)Index));
}

/**
 * @brief 获取ECC纠错码，在 NVM 读访问时最后一次的 ECC 校验和
 * @details 当读取通过 SRI 从接口启动时，该位域存储最后一次读访问 DF0（包含 UCB）和 DF1（非专业 HSM）的校验后
 *
 * @retval ECC纠错码
 */
KF_FORCE_INLINE uint32_t Flash_LL_ReadEccCorrectionCode()
{
    return (FLASH_PTR->DF_ECCR.bits.RCODE);
}

/**
 * @brief 清除ECC状态
 * @details 清除 DF_ECCSTA 状态标志位
 *
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_ClearEccStatus()
{
    REG_WRITE(FLASH_PTR->DF_ECCCTL.bits.CLR , 3U);
}

/**
 * @brief 禁止ECC纠正
 *
 * @param Status
 *               FLASH_ECC_CORRECTION_ENABLED 使能，允许 ECC 纠正
 *               FLASH_ECC_CORRECTION_DISABLED 禁止 DF0 与 DF1（非 HSM 专用）读路径上的ECC纠正
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetEccCorrectionDisabled(const Flash_EccCorrectionDis_t Status)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_ECC_CORRECTION_DIS(Status));
    FLASH_PTR->DF_ECCCTL.bits.ECCCORDIS = (uint32_t)Status;
}

/**
 * @brief 禁止生成ECC错误陷阱
 *
 * @param Status
 *               FLASH_ECC_TRAP_ENABLED 允许生成错误陷阱
 *               FLASH_ECC_TRAP_DISABLED 禁止生成错误陷阱
 */
KF_FORCE_INLINE void Flash_LL_SetEccTrapDisabled(const Flash_EccTrapDis_t Status)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_ECC_TRAP_DIS(Status));
    FLASH_PTR->DF_ECCCTL.bits.TRAPDIS = (uint32_t)Status;
}

/**
 * @brief 写入ECC纠错码
 * @details 替换数据集中 DFlash 128-bit 或 DPFlash 128-bit 的ECC 纠错码
 *
 * @param EccCorrectionCode ECC纠错码，22位长度
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_WriteEccCorrectionCode(const uint32_t EccCorrectionCode)
{
    KF_DRV_FLASH_ASSERT(CHECK_FLASH_ECC_CORRECTION_CODE(EccCorrectionCode));
    REG_WRITE(FLASH_PTR->FLASH_ECCW.bits.WCODE , EccCorrectionCode);
}

/**
 * @brief Flash进入休眠模式
 *
 *
 * @param Status
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetSleepMode(const bool Status)
{
    if (Status)
    {
        REG_WRITE(FLASH_PTR->FLASH_PWRCTL.bits.SLEEP , 3U);
    }
    else
    {
        REG_WRITE(FLASH_PTR->FLASH_PWRCTL.bits.SLEEP , 0U);
    }
}

/**
 * @brief Flash进入动态空闲模式
 * @note DFlash不执行读访问时，硬件自动进入空闲模式
 * @note PFlash 空闲模式通过软件启动，通过写 11B 到寄存器 FLASH_PWRCTL.IDLE
 *
 * @param Status
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetDynamicIdleMode(const bool Status)
{
    if (Status)
    {
        REG_WRITE(FLASH_PTR->FLASH_PWRCTL.bits.IDLE , 3U);
    }
    else
    {
        REG_WRITE(FLASH_PTR->FLASH_PWRCTL.bits.IDLE , 0U);
    }
}

/**
 * @brief 设置PFlash读访问的SRI时钟周期数
 *
 * @param ColckCycle 周期数-1，范围1~63；例：64个时钟周期，应传入ColckCycle = 63
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetPFlashReadClockCycle(const uint32_t ColckCycle)
{
    KF_DRV_FLASH_ASSERT(CHECK_PFLASH_READ_CLOCK_CYCLE(ColckCycle));
    REG_WRITE(FLASH_PTR->FLASH_PWAIT.bits.RPF , ColckCycle);
}

/**
 * @brief 设置PFlashECC纠正SRI时钟周期数
 *
 *
 * @param ColckCycle 周期数 - 1，范围0~7；例：8个时钟周期，应传入ColckCycle = 7
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetPFlashEccCorrectionClockCycle(const uint8_t ColckCycle)
{
    KF_DRV_FLASH_ASSERT(CHECK_PFLASH_ECC_CORRECTION_CLOCK_CYCLE(ColckCycle));
    REG_WRITE(FLASH_PTR->FLASH_PWAIT.bits.RPECC , ColckCycle);
}

/**
 * @brief 设置DFlash读访问的SRI时钟周期数
 *
 * @param ColckCycle 周期数-1，范围1~256；例：256个时钟周期，应传入ColckCycle = 255
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetDFlashReadClockCycle(const uint8_t ColckCycle)
{
    KF_DRV_FLASH_ASSERT(CHECK_DFLASH_READ_CLOCK_CYCLE(ColckCycle));
    REG_WRITE(FLASH_PTR->FLASH_PWAIT.bits.RDF , ColckCycle);
}

/**
 * @brief 设置DFlashECC纠正SRI时钟周期数
 *
 *
 * @param ColckCycle 周期数 - 1，范围0~7；例：8个时钟周期，应传入ColckCycle = 7
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_SetDFlashEccCorrectionClockCycle(const uint32_t ColckCycle)
{
    KF_DRV_FLASH_ASSERT(CHECK_DFLASH_ECC_CORRECTION_CLOCK_CYCLE(ColckCycle));
    REG_WRITE(FLASH_PTR->FLASH_PWAIT.bits.RDECC , ColckCycle);
}

/**
 * @brief 写入UCB解锁秘钥
 * @details 解锁 UCB 保护的密钥 x（x=0~7），当 PW0~PW7与所选的 UCB 配置值相匹配时，禁用 UCB 保护
 *
 * @param KeyPtr 秘钥序列0~7
 * @retval void
 */
KF_FORCE_INLINE void Flash_LL_WriteUCBSequenceKey(const uint32_t *KeyPtr)
{
    FLASH_PTR->FLASH_PWx[0].reg = KeyPtr[0];
    FLASH_PTR->FLASH_PWx[1].reg = KeyPtr[1];
    FLASH_PTR->FLASH_PWx[2].reg = KeyPtr[2];
    FLASH_PTR->FLASH_PWx[3].reg = KeyPtr[3];
    FLASH_PTR->FLASH_PWx[4].reg = KeyPtr[4];
    FLASH_PTR->FLASH_PWx[5].reg = KeyPtr[5];
    FLASH_PTR->FLASH_PWx[6].reg = KeyPtr[6];
    FLASH_PTR->FLASH_PWx[7].reg = KeyPtr[7];
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
