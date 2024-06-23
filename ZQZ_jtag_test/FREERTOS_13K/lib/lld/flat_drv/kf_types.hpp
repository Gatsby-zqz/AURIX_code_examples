/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf_types.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-06-25
 *  @Version         : V0.0.1.230625_alpha
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyrght protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2021-12-23  |V1.0     |Zhai yu     |New creat
 *  |2022-11-18  |V1.1     |Zhai Yu     | QAC compliance check
 *****************************************************************************/

#ifndef KFTYPES_H_
#define KFTYPES_H_

/******************************************************************************
 **                                             MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 * MISRA RULE 2.3 - A project should not contain unused type declarations
 * MISRA RULE 4.9 - A function should be used in preference to a function-like
 * macro where they are interchangeable
 * MISRA RULE 20.10 - The # and ## preprocessor operators should not be used
 */

/******************************************************************************
 **                                                  QAC Warnings Suppression
 ******************************************************************************/
/**
 * @page QAC Warnings Suppression
 *
 */
/* PRQA S 0342 EOF # Suppress MISRA RULE 20.10 */
/* PRQA S 3205 EOF # Keep unused macro */
/* PRQA S 3410 EOF # Macro parameter not enclosed in (). */
/* PRQA S 1271 EOF */                          /* Using a non-int expression to define an enum constant.
                                                */
/* PRQA S 3461 EOF */                          /* Macro defines a storage-class specifier/type qualifier
                                                  sequence */
/* PRQA S 3428 EOF */                          /* Macro defines a type qualifier keyword. */
/* PRQA S 3453 EOF */                          /* A function could probably be used instead of this
                                                  function-like macro. */
/* PRQA S 3472 EOF #Suppress MISRA RULE 4.9 */ /* All toplevel uses of this
                                                  function-like macro look like
                                                  they could be replaced by
                                                  equivalent function calls. */
/* PRQA S 3456 EOF */                          /* Parameter  will be evaluated more than once when this
                                                macro is used. */
/* PRQA S 3345 EOF */                          /* Statement contains more than one access to objects
                                that are volatile. */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
    /* Generic error codes */
    /** @brief Generic operation success status */
    STATUS_OK = 0x000U,
    /** @brief Generic operation failure status */
    STATUS_ERROR = 0x001U,
    /** @brief Generic operation busy status */
    STATUS_BUSY = 0x002U,
    /** @brief Generic operation timeout status */
    STATUS_TIMEOUT = 0x003U,
    /** @brief Generic operation unsupported status */
    STATUS_UNSUPPORTED = 0x004U,

    /* MCU specific error codes */
    /** @brief Module is gated off */
    STATUS_MCU_GATED_OFF = 0x100U,
    /** @brief Error oclkrs during transition. */
    STATUS_MCU_TRANSITION_FAILED = 0x101U,
    /** @brief Unsupported in current state. */
    STATUS_MCU_INVALID_STATE = 0x102U,
    /** @brief Error oclkrs during send "BEFORE" notification. */
    STATUS_MCU_NOTIFY_BEFORE_ERROR = 0x103U,
    /** @brief Error oclkrs during send "AFTER" notification. */
    STATUS_MCU_NOTIFY_AFTER_ERROR = 0x104U,

    /* I2C specific error codes */
    /** @brief NACK signal received  */
    STATUS_I2C_RECEIVED_NACK = 0x200U,
    /** @brief TX underrun error */
    STATUS_I2C_TX_UNDERRUN = 0x201U,
    /** @brief RX overrun error */
    STATUS_I2C_RX_OVERRUN = 0x202U,
    /** @brief Arbitration lost */
    STATUS_I2C_ARBITRATION_LOST = 0x203U,
    /** @brief A transfer was aborted */
    STATUS_I2C_ABORTED = 0x204U,
    /** @brief I2C bus is busy, cannot start transfer */
    STATUS_I2C_BUS_BUSY = 0x205U,

    /* CANFD specific error codes */
    /** @brief The specified MB index is out of the configurable range */
    STATUS_CANFD_BUFF_OUT_OF_RANGE = 0x380U,
    /** @brief There is no transmission or reception in progress */
    STATUS_CANFD_NO_TRANSFER_IN_PROGRESS = 0x381U,
    /** @brief There is no buffer for mailbox */
    STATUS_CANFD_BUFF_FULL = 0x382U,
    /** @brief There is error oclkred */
    STATUS_CANFD_ERROR = 0x383U,
    /** @brief CAN is not synchronized to bus */
    STATUS_CANFD_OFFLINE = 0x384U,

    /* SPI specific error codes */
    /** @brief TX underrun error */
    STATUS_SPI_TX_UNDERRUN = 0x500U,
    /** @brief RX overrun error */
    STATUS_SPI_RX_OVERRUN = 0x501U,
    /** @brief A transfer was aborted */
    STATUS_SPI_ABORTED = 0x502U,

    /* UART specific error codes */
    /** @brief TX underrun error */
    STATUS_UART_TX_UNDERRUN = 0x600U,
    /** @brief RX overrun error */
    STATUS_UART_RX_OVERRUN = 0x601U,
    /** @brief A transfer was aborted */
    STATUS_UART_ABORTED = 0x602U,
    /** @brief Framing error */
    STATUS_UART_FRAMING_ERROR = 0x603U,
    /** @brief Parity error */
    STATUS_UART_PARITY_ERROR = 0x604U,
    /** @brief Noise error */
    STATUS_UART_NOISE_ERROR = 0x605U,

    /* I2S specific error codes */
    /** @brief TX underrun error */
    STATUS_I2S_TX_UNDERRUN = 0x700U,
    /** @brief RX overrun error */
    STATUS_I2S_RX_OVERRUN = 0x701U,
    /** @brief A transfer was aborted */
    STATUS_I2S_ABORTED = 0x702U,

    /* FLASH specific error codes */
    /** @brief It's impossible to enable an operation */
    STATUS_FLASH_ERROR_ENABLE = 0x901U,
    /** @brief No blocks have been enabled for Array Integrity check */
    STATUS_FLASH_ERROR_NO_BLOCK = 0x902U,
    /** @brief InProgress status */
    STATUS_FLASH_INPROGRESS = 0x903U,

    /* CCP specific error codes */
    /** @brief CCP triggers TimeOut when try to enter in Config State */
    STATUS_CCP_ERROR_CONFIG_TIMEOUT = 0xB01U,
    /** @brief CCP Initializing CCP Module */
    STATUS_CCP_ERROR_INIT_CCP = 0xB02U,
    /** @brief CCP Fail to Enter in Config Mode  */
    STATUS_CCP_ERROR_SET_CONFIG = 0xB03U,
    /** @brief CCP Fail to Enter in Normal Mode  */
    STATUS_CCP_ERROR_SET_NORMAL = 0xB04U,
    /** @brief CCP Fail to set NoCritical Faults  */
    STATUS_CCP_ERROR_APPLY_NCF_CONFIG = 0xB05U,
    /** @brief CCP Fail to update Freez Status registers */
    STATUS_CCP_ERROR_UPDATE_FREEZE = 0xB06U,
    /** @brief CCP Fail to Clear Freez Status registers */
    STATUS_CCP_ERROR_CLEAR_FREEZE = 0xB07U,
    /** @brief CCP Fail to Set Eout Configuration */
    STATUS_CCP_ERROR_SET_EOUT = 0xB08U,
    /** @brief CCP Faults Detected */
    STATUS_CCP_ERROR_FAULT_DETECTED = 0xB09U,
    /** @brief CCP other Error */
    STATUS_CCP_ERROR_OTHER = 0xB0AU,

    /* EEE specific error codes */
    /** @brief The data is too big to fit in any of the block */
    STATUS_EEE_ERROR_NO_ENOUGH_SPACE = 0xD00U,
    /** @brief The block numbers is not enough for round robin */
    STATUS_EEE_ERROR_NO_ENOUGH_BLOCK = 0xD01U,
    /** @brief The required data is not found in the EEPROM emulation */
    STATUS_EEE_ERROR_DATA_NOT_FOUND = 0xD02U,
    /** @brief The required data is not in the cache table */
    STATUS_EEE_ERROR_NOT_IN_CACHE = 0xD03U,
    /** @brief Failed to make block indicator to non-blank for several times */
    STATUS_EEE_ERROR_PROGRAM_INDICATOR = 0xD04U,
    /** @brief The high voltage operation is in progress */
    STATUS_EEE_HVOP_INPROGRESS = 0xD05U,

} kf_status_t;

#define TIME_INFINITE ((int64_t)0x7FFFFFFFFFFFFFFFLL)
#define TIME_NULL     ((int64_t)0x0000000000000000LL)

#define POS_0_OFFSET  (0U)
#define POS_1_OFFSET  (1U)
#define POS_2_OFFSET  (2U)
#define POS_3_OFFSET  (3U)
#define POS_4_OFFSET  (4U)
#define POS_5_OFFSET  (5U)
#define POS_6_OFFSET  (6U)
#define POS_7_OFFSET  (7U)
#define POS_8_OFFSET  (8U)
#define POS_9_OFFSET  (9U)
#define POS_10_OFFSET (10U)
#define POS_11_OFFSET (11U)
#define POS_12_OFFSET (12U)
#define POS_13_OFFSET (13U)
#define POS_14_OFFSET (14U)
#define POS_15_OFFSET (15U)
#define POS_16_OFFSET (16U)
#define POS_17_OFFSET (17U)
#define POS_18_OFFSET (18U)
#define POS_19_OFFSET (19U)
#define POS_20_OFFSET (20U)
#define POS_21_OFFSET (21U)
#define POS_22_OFFSET (22U)
#define POS_23_OFFSET (23U)
#define POS_24_OFFSET (24U)
#define POS_25_OFFSET (25U)
#define POS_26_OFFSET (26U)
#define POS_27_OFFSET (27U)
#define POS_28_OFFSET (28U)
#define POS_29_OFFSET (29U)
#define POS_30_OFFSET (30U)
#define POS_31_OFFSET (31U)

#define POS_0_SHIFT  (0U)
#define POS_1_SHIFT  (1U)
#define POS_2_SHIFT  (2U)
#define POS_3_SHIFT  (3U)
#define POS_4_SHIFT  (4U)
#define POS_5_SHIFT  (5U)
#define POS_6_SHIFT  (6U)
#define POS_7_SHIFT  (7U)
#define POS_8_SHIFT  (8U)
#define POS_9_SHIFT  (9U)
#define POS_10_SHIFT (10U)
#define POS_11_SHIFT (11U)
#define POS_12_SHIFT (12U)
#define POS_13_SHIFT (13U)
#define POS_14_SHIFT (14U)
#define POS_15_SHIFT (15U)
#define POS_16_SHIFT (16U)
#define POS_17_SHIFT (17U)
#define POS_18_SHIFT (18U)
#define POS_19_SHIFT (19U)
#define POS_20_SHIFT (20U)
#define POS_21_SHIFT (21U)
#define POS_22_SHIFT (22U)
#define POS_23_SHIFT (23U)
#define POS_24_SHIFT (24U)
#define POS_25_SHIFT (25U)
#define POS_26_SHIFT (26U)
#define POS_27_SHIFT (27U)
#define POS_28_SHIFT (28U)
#define POS_29_SHIFT (29U)
#define POS_30_SHIFT (30U)
#define POS_31_SHIFT (31U)

#define MASK_0_BIT  ((uint32_t)0x0U)
#define MASK_1_BIT  ((uint32_t)0x1U)
#define MASK_2_BIT  ((uint32_t)0x3U)
#define MASK_3_BIT  ((uint32_t)0x7U)
#define MASK_4_BIT  ((uint32_t)0xFU)
#define MASK_5_BIT  ((uint32_t)0x1FU)
#define MASK_6_BIT  ((uint32_t)0x3FU)
#define MASK_7_BIT  ((uint32_t)0x7FU)
#define MASK_8_BIT  ((uint32_t)0xFFU)
#define MASK_9_BIT  ((uint32_t)0x1FFU)
#define MASK_10_BIT ((uint32_t)0x3FFU)
#define MASK_11_BIT ((uint32_t)0x7FFU)
#define MASK_12_BIT ((uint32_t)0xFFFU)
#define MASK_13_BIT ((uint32_t)0x1FFFU)
#define MASK_14_BIT ((uint32_t)0x3FFFU)
#define MASK_15_BIT ((uint32_t)0x7FFFU)
#define MASK_16_BIT ((uint32_t)0xFFFFU)
#define MASK_17_BIT ((uint32_t)0x1FFFFU)
#define MASK_18_BIT ((uint32_t)0x3FFFFU)
#define MASK_19_BIT ((uint32_t)0x7FFFFU)
#define MASK_20_BIT ((uint32_t)0xFFFFFU)
#define MASK_21_BIT ((uint32_t)0x1FFFFFU)
#define MASK_22_BIT ((uint32_t)0x3FFFFFU)
#define MASK_23_BIT ((uint32_t)0x7FFFFFU)
#define MASK_24_BIT ((uint32_t)0xFFFFFFFU)
#define MASK_25_BIT ((uint32_t)0x1FFFFFFU)
#define MASK_26_BIT ((uint32_t)0x3FFFFFFU)
#define MASK_27_BIT ((uint32_t)0x7FFFFFFU)
#define MASK_28_BIT ((uint32_t)0xFFFFFFFU)
#define MASK_29_BIT ((uint32_t)0x1FFFFFFFU)
#define MASK_30_BIT ((uint32_t)0x3FFFFFFFU)
#define MASK_31_BIT ((uint32_t)0x7FFFFFFFU)
#ifdef SIMULATION // TODO: WAR for SIMULATION, just only support the drv have below function, we can change below
                  // function to connect JTAG support IP test
extern uint32_t _regRead8(uint32_t regAddr);
extern void     _regwrite8(uint32_t regAddr, uint32_t regValue);
extern uint32_t _regRead32(uint32_t regAddr);
extern void     _regwrite32(uint32_t regAddr, uint32_t regValue);

#define CANFD_WRITE8(addr, value)        (_regwrite8(addr, value))
#define CANFD_READ8(addr)                (_regRead8(addr))
#define CANFD_WRITE32(addr, value)       (_regwrite32(addr, value))
#define CANFD_READ32(addr)               (_regRead32(addr))
#define REG_BIT_SET(reg, mask)           (mask)
#define REG_BIT_CLR(reg, mask)           (mask)
#define REG_BITS_WRITE(reg, mask, value) (_regwrite32(reg, (_regRead32(reg) & ~(mask)) | (value)))
#define REG_BITS_READ(reg, mask, pos)    (((_regRead32(reg)) & (mask)) >> (pos))
#define REG_BIT_BOOLED(reg, mask)        (mask)
#define REG_WRITE(reg, value)            (_regwrite32(reg, value))
#define REG_READ(reg)                    (_regRead32(reg))
#else
#define CANFD_WRITE8(addr, value)        (*(((uint8_t *)addr)) = (value))
#define CANFD_READ8(addr)                (*((uint8_t *)addr))
#define CANFD_WRITE32(addr, value)       (*(((uint32_t *)addr)) = (value))
#define CANFD_READ32(addr)               (*((uint32_t *)addr))
#define REG_BIT_SET(reg, mask)           ((reg) |= (mask))
#define REG_BIT_CLR(reg, mask)           ((reg) &= ~(mask))
#define REG_BITS_WRITE(reg, mask, value) ((reg) = ((reg) & ~(mask)) | (value))
#define REG_BITS_READ(reg, mask, pos)    (((reg) & (mask)) >> (pos))
#define REG_BIT_BOOLED(reg, mask)        (((reg) & (mask)) > 0U)
#define REG_WRITE(reg, value)            ((reg) = (value))
#define REG_READ(reg)                    (reg)
#endif
#define KF_CLR_BIT(reg, offset) __asm volatile("CLR [%0], #%1" ::"r"(&(reg)), "i"(offset) : "memory")
#define KF_SET_BIT(reg, offset) __asm volatile("SET [%0], #%1" ::"r"(&(reg)), "i"(offset) : "memory")

#ifndef STD_ON
#define STD_ON (1U)
#endif
#ifndef STD_OFF
#define STD_OFF (0U)
#endif

#ifndef BIT_SET
#define BIT_SET (1)
#endif
#ifndef BIT_CLR
#define BIT_CLR (0U)
#endif

#ifndef NULL
#define NULL (0U)
#endif
#ifndef NULL_PTR
#define NULL_PTR ((void *)0U)
#endif

/**
 * @brief Enum for Bit Level status
 *
 */
typedef enum
{
    /** @brief IO Bit Logic Low  */
    BIT_LEVEL_LOW,
    /** @brief IO Bit Logic High  */
    BIT_LEVEL_HIGH
} kfBitLevel_t;

/**
 * @brief Enum for Ability
 *
 */
typedef enum
{
    /** @brief Functionality Disable State  */
    KF_DISABLE,
    /** @brief Functionality Enable State  */
    KF_ENABLE
} kfOption_t;

#ifndef __I
/** @brief Defines 'read only' permissions */
#define __I volatile const
#endif
#ifndef __O
/** @brief Defines 'write only' permissions */
#define __O volatile
#endif
#ifndef __IO
/** @brief Defines 'read / write' permissions */
#define __IO volatile
#endif

#ifndef KF_INLINE
#define KF_INLINE static inline
#endif

#ifndef KF_FORCE_INLINE
#define KF_FORCE_INLINE __attribute__((always_inline)) static inline
#endif

#ifndef KF_INTERRUPT
#define KF_INTERRUPT(isrName) void __attribute__((interrupt)) _##isrName##_exception(void)
#endif
/* PRQA S 4640 2 */
#ifndef SIMULATION
#define ENABLE_INTERRUPT()                                                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        __asm volatile(                                                                                                \
          "PUSH R0\n\t"                                                                                                \
          "MOV R0,#0x00008000 \n\t"                                                                                    \
          "SYNC \n\t"                                                                                                  \
          "CSROR R0, R0, #0x187 \n\t"                                                                                  \
          "SYNC\n\t"                                                                                                   \
          "POP R0\n\t");                                                                                               \
    } while (0)
#define DISABLE_INTERRUPT()                                                                                            \
    do                                                                                                                 \
    {                                                                                                                  \
        __asm volatile(                                                                                                \
          "PUSH R0\n\t"                                                                                                \
          "MOV R0,#0x00008000 \n\t"                                                                                    \
          "SYNC \n\t"                                                                                                  \
          "CSRANL R0,R0, #0x187 \n\t"                                                                                  \
          "SYNC\n\t"                                                                                                   \
          "POP R0\n\t");                                                                                               \
    } while (0)
#define NOP()   __asm volatile("NOP")
#define RESET() __asm volatile("RESET")
#else
#define ENABLE_INTERRUPT()
#define DISABLE_INTERRUPT()
#define NOP()
#define RESET()
#endif

#define KF_ALIGN_8   (1)  // Align on 8 bit Boundary
#define KF_ALIGN_16  (2)  // Align on 16 bit Boundary
#define KF_ALIGN_32  (4)  // Align on 32 bit Boundary
#define KF_ALIGN_64  (8)  // Align on 64 bit Boundary
#define KF_ALIGN_128 (16) // Align on 128 bit Boundary
#define KF_ALIGN_256 (32) // Align on 256 bit Boundary

#define KF_ALIGN_ON256(Size) ((((Size) + (KF_ALIGN_256 - 1)) & (~(KF_ALIGN_256 - 1))))
#define KF_ALIGN_ON128(Size) ((((Size) + (KF_ALIGN_128 - 1)) & (~(KF_ALIGN_128 - 1))))
#define KF_ALIGN_ON64(Size)  ((((Size) + (KF_ALIGN_64 - 1)) & (~(KF_ALIGN_64 - 1))))
#define KF_ALIGN_ON32(Size)  ((((Size) + (KF_ALIGN_32 - 1)) & (~(KF_ALIGN_32 - 1))))
#define KF_ALIGN_ON16(Size)  ((((Size) + (KF_ALIGN_16 - 1)) & (~(KF_ALIGN_16 - 1))))
#define KF_ALIGN_ON8(Size)   ((((Size) + (KF_ALIGN_8 - 1)) & (~(KF_ALIGN_8 - 1))))

#define KF_MIN(A, B) ((A < B) ? A : B)
#define KF_MAX(A, B) ((A > B) ? A : B)

#if 0
/* It should be noted that macro parameters that contain '#' or '##' in macro definitions will not be expanded. so we
 * need additional intermediate  macro */

#define KF_STATIC_ASSERT(x, msg)    typedef char KF_STATIC_COMBO(msg, __LINE__)[(x) ? 1 : -1]
#define KF_STATIC_COMBO(msg, line)  KF_STATIC_COMBO_(msg, line)
#define KF_STATIC_COMBO_(msg, line) ASSERT_##msg##_##line##_Failed
#define KF_STATIC_ASSERT(x, msg)    typedef char ASSERT_##msg##_Failed[(x) ? 1 : -1]
#else
/* static assert is build-in kf32-gcc */
#define KF_STATIC_ASSERT(cond, msg) _Static_assert((cond), msg)
#endif

// TODO:need to add this api use timer
#define Kf_GetDeadLine(Timeout) Timeout
#define Kf_IsDeadLine(Deadline) true

#ifdef __cplusplus
}
#endif

/******************************************************************************
 **                      Inner Functions
 ******************************************************************************/
#ifndef InnerLibrary
#define InnerLibrary
#endif

#endif
/* EOF */
