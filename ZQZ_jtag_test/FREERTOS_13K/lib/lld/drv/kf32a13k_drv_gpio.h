/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_gpio.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-15
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
 *  |2023-12-15  |V1.0     |Sun Wanyu  | New Creat
 *****************************************************************************/
#ifndef KF32A13K_DRV_GPIO_H_
#define KF32A13K_DRV_GPIO_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_gpio.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_GPIO_ASSERT
#include "dev_assert.h"
#define KF_DRV_GPIO_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DRV_GPIO_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    GPIO_PIN_INDEX_0  = 0x00000000,
    GPIO_PIN_INDEX_1  = 0x00000001,
    GPIO_PIN_INDEX_2  = 0x00000002,
    GPIO_PIN_INDEX_3  = 0x00000003,
    GPIO_PIN_INDEX_4  = 0x00000004,
    GPIO_PIN_INDEX_5  = 0x00000005,
    GPIO_PIN_INDEX_6  = 0x00000006,
    GPIO_PIN_INDEX_7  = 0x00000007,
    GPIO_PIN_INDEX_8  = 0x00000008,
    GPIO_PIN_INDEX_9  = 0x00000009,
    GPIO_PIN_INDEX_10 = 0x0000000A,
    GPIO_PIN_INDEX_11 = 0x0000000B,
    GPIO_PIN_INDEX_12 = 0x0000000C,
    GPIO_PIN_INDEX_13 = 0x0000000D,
    GPIO_PIN_INDEX_14 = 0x0000000E,
    GPIO_PIN_INDEX_15 = 0x0000000F
} Gpio_PinIndex_t;

typedef enum
{
    GPIO_TAG_ID_0  = 0x00000000,
    GPIO_TAG_ID_1  = 0x00000001,
    GPIO_TAG_ID_2  = 0x00000002,
    GPIO_TAG_ID_3  = 0x00000003,
    GPIO_TAG_ID_4  = 0x00000004,
    GPIO_TAG_ID_5  = 0x00000005,
    GPIO_TAG_ID_6  = 0x00000006,
    GPIO_TAG_ID_7  = 0x00000007,
    GPIO_TAG_ID_8  = 0x00000008,
    GPIO_TAG_ID_9  = 0x00000009,
    GPIO_TAG_ID_10 = 0x0000000A,
    GPIO_TAG_ID_11 = 0x0000000B,
    GPIO_TAG_ID_12 = 0x0000000C,
    GPIO_TAG_ID_13 = 0x0000000D,
    GPIO_TAG_ID_14 = 0x0000000E,
    GPIO_TAG_ID_15 = 0x0000000F,
    GPIO_TAG_ID_16 = 0x00000010,
    GPIO_TAG_ID_17 = 0x00000011,
    GPIO_TAG_ID_18 = 0x00000012,
    GPIO_TAG_ID_19 = 0x00000013,
    GPIO_TAG_ID_20 = 0x00000014,
    GPIO_TAG_ID_21 = 0x00000015,
    GPIO_TAG_ID_22 = 0x00000016,
    GPIO_TAG_ID_23 = 0x00000017,
    GPIO_TAG_ID_24 = 0x00000018,
    GPIO_TAG_ID_25 = 0x00000019,
    GPIO_TAG_ID_26 = 0x0000001A,
    GPIO_TAG_ID_27 = 0x0000001B,
    GPIO_TAG_ID_28 = 0x0000001C,
    GPIO_TAG_ID_29 = 0x0000001D,
    GPIO_TAG_ID_30 = 0x0000001E,
    GPIO_TAG_ID_31 = 0x0000001F
} Gpio_TagId_t;

typedef enum
{
    GPIO_PAD_DRIVER_MODE_0 = 0x00000000,
    GPIO_PAD_DRIVER_MODE_1 = 0x00000001,
    GPIO_PAD_DRIVER_MODE_2 = 0x00000002,
    GPIO_PAD_DRIVER_MODE_3 = 0x00000003
} Gpio_PadDriverMode_t;

typedef enum
{
    GPIO_PAD_LEVELSEL_0 = 0x00000000,
    GPIO_PAD_LEVELSEL_1 = 0x00000001,
    GPIO_PAD_LEVELSEL_2 = 0x00000002,
    GPIO_PAD_LEVELSEL_3 = 0x00000003
} Gpio_PadLevelSel_t;

typedef enum
{
    GPIO_PIN_HIGH,
    GPIO_PIN_LOW
} Gpio_PinState_t;

typedef enum
{
    GPIO_PIN_PUPD_NONE0,
    GPIO_PIN_PU,
    GPIO_PIN_PD,
    GPIO_PIN_PUPD_NONE1
} Gpio_PinPuPdState_t;

typedef enum
{
    GPIO_PIN_OUTPUTNOEN_INPUTEN,
    GPIO_PIN_OUTPUTNOEN_INPUTNOEN,
    GPIO_PIN_OUTPUTEN_INPUTEN,
    GPIO_PIN_OUTPUTEN_INPUTNOEN
} Gpio_PinOutputEn_t;

typedef enum
{
    GPIO_PIN_RMP_PAGE_AF0  = 0x0000U,
    GPIO_PIN_RMP_PAGE_AF1  = 0x0001U,
    GPIO_PIN_RMP_PAGE_AF2  = 0x0002U,
    GPIO_PIN_RMP_PAGE_AF3  = 0x0003U,
    GPIO_PIN_RMP_PAGE_AF4  = 0x0004U,
    GPIO_PIN_RMP_PAGE_AF5  = 0x0005U,
    GPIO_PIN_RMP_PAGE_AF6  = 0x0006U,
    GPIO_PIN_RMP_PAGE_AF7  = 0x0007U,
    GPIO_PIN_RMP_PAGE_AF8  = 0x0008U,
    GPIO_PIN_RMP_PAGE_AF9  = 0x0009U,
    GPIO_PIN_RMP_PAGE_AF10 = 0x000AU,
    GPIO_PIN_RMP_PAGE_AF11 = 0x000BU,
    GPIO_PIN_RMP_PAGE_AF12 = 0x000CU,
    GPIO_PIN_RMP_PAGE_AF13 = 0x000DU,
    GPIO_PIN_RMP_PAGE_AF14 = 0x000EU,
    GPIO_PIN_RMP_PAGE_AF15 = 0x000FU
} Gpio_PinRemap_t;

#define CHECK_GPIO_POSR0(GPIO)  ((GPIO <= GPIO_PIN_INDEX_3) && (GPIO >= GPIO_PIN_INDEX_0))
#define CHECK_GPIO_POSR4(GPIO)  ((GPIO <= GPIO_PIN_INDEX_7) && (GPIO >= GPIO_PIN_INDEX_4))
#define CHECK_GPIO_POSR8(GPIO)  ((GPIO <= GPIO_PIN_INDEX_11) && (GPIO >= GPIO_PIN_INDEX_8))
#define CHECK_GPIO_POSR12(GPIO) ((GPIO <= GPIO_PIN_INDEX_15) && (GPIO >= GPIO_PIN_INDEX_12))
#define CHECK_GPIO_POCR0(GPIO)  ((GPIO <= GPIO_PIN_INDEX_3) && (GPIO >= GPIO_PIN_INDEX_0))
#define CHECK_GPIO_POCR4(GPIO)  ((GPIO <= GPIO_PIN_INDEX_7) && (GPIO >= GPIO_PIN_INDEX_4))
#define CHECK_GPIO_POCR8(GPIO)  ((GPIO <= GPIO_PIN_INDEX_11) && (GPIO >= GPIO_PIN_INDEX_8))
#define CHECK_GPIO_POCR12(GPIO) ((GPIO <= GPIO_PIN_INDEX_15) && (GPIO >= GPIO_PIN_INDEX_12))
#define GPIO_PIN_LOCK_KEY       (uint32_t)0X5C5A
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief 获取GPIO模块版本信息
 *
 *
 * @param Module
 * @retval uint32_t 模块版本
 */
KF_INLINE uint32_t Gpio_LL_ReadModuleVersion(Gpio_RegisterMap_t *const Module)
{
    return (REG_READ(Module->GPIO_INFO.bits.MODREV));
}

/**
 * @brief 获取GPIO模块类型信息
 *
 *
 * @param Module
 * @retval uint32_t 模块类型
 */
KF_INLINE uint32_t Gpio_LL_ReadModuleType(Gpio_RegisterMap_t *const Module)
{
    return (REG_READ(Module->GPIO_INFO.bits.MODTYPE));
}

/**
 * @brief 获取GPIO模块编号信息
 *
 *
 * @param Module
 * @retval uint32_t 模块编号
 */
KF_INLINE uint32_t Gpio_LL_ReadModuleNumber(Gpio_RegisterMap_t *const Module)
{
    return (REG_READ(Module->GPIO_INFO.bits.MODNUMBER));
}

/**
 * @brief 获取指定主机TAG ID的权限使能
 *
 *
 * @param Module
 * @param TagId 主机TAG ID 取值为0~31
 * @retval bool
 *         false  不执行写访问
 *         true   执行写访问
 */
KF_INLINE bool Gpio_LL_ReadCtrlEnableStatus(Gpio_RegisterMap_t *const Module, const Gpio_TagId_t TagId)
{
    return (REG_BITS_READ(Module->GPIO_ACES0.reg, MASK_1_BIT << TagId, TagId));
}

/**
 * @brief 配置指定主机TAG ID的权限使能
 *
 *
 * @param Module
 * @param TagId 主机TAG ID 取值为0~31
 * @param Status bool 指定主机TAG的权限使能
 *         false  不执行写访问
 *         true   执行写访问
 * @retval void
 */
KF_INLINE void
Gpio_LL_WriteCtrlEnableStatus(Gpio_RegisterMap_t *const Module, const Gpio_TagId_t TagId, const bool Status)
{
    REG_BITS_WRITE(Module->GPIO_ACES0.reg, MASK_1_BIT << TagId, Status << TagId);
}

/**
 * @brief 获取输入状态寄存器中GPIO端口指定引脚的输入状态
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号 取值0~15
 * @retval bool 对应引脚的状态
 *         false 指定引脚为逻辑低电平
 *         true  指定引脚为逻辑高电平
 */
KF_INLINE bool Gpio_LL_ReadInputStatus(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex)
{
    return (REG_BITS_READ(Module->GPIO_PIR.reg, MASK_1_BIT << PinIndex, PinIndex));
}

/**
 * @brief 获取输出状态寄存器中GPIO端口指定引脚的输出状态
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号 取值0~15
 * @retval bool 对应引脚的状态
 *         false 低电平
 *         true  高电平
 */

KF_INLINE bool Gpio_LL_ReadOutputStatus(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex)
{
    return (REG_BITS_READ(Module->GPIO_POR.reg, MASK_1_BIT << PinIndex, PinIndex));
}

/**
 * @brief 配置输出状态寄存器中GPIO端口指定引脚的输出状态
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号 取值0~15
 * @param  bool 对应引脚的输出状态
 *         false 对应引脚为逻辑低电平
 *         true  对应引脚为逻辑高电平
 * @retval void
 */
KF_INLINE void
Gpio_LL_WriteOutputStatus(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool Status)
{
    REG_BITS_WRITE(Module->GPIO_POR.reg, MASK_1_BIT << PinIndex, Status << PinIndex);
}

/**
 * @brief 配置GPIO端口指定引脚的输出数据取反
 *
 * @param[in] Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param[in] PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @retval 无
 */
KF_INLINE void Gpio_LL_ToggleOutputStatus(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex)
{
    uint32_t PinMask;
    uint32_t Reg;
    PinMask = (uint32_t)((uint32_t)0x01U << (uint32_t)PinIndex);
    Reg     = REG_READ(Module->GPIO_POR.reg) ^ PinMask;
    REG_WRITE(Module->GPIO_POR.reg, Reg);
}

/**
 * @brief 配置GPIO端口指定引脚的输出状态
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号
 * @param StatusPc GPIO端口指定引脚PC状态
 *        PC
 *        0 无操作
 *        1 清零或翻转指定引脚
 * @param StatusPs GPIO端口指定引脚PS状态
 *        PS
 *        0 无操作
 *        1 置位或翻转指定引脚
 * @retval void
 */
KF_INLINE void Gpio_LL_WriteOutputConfiguration(
  Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPc, const bool StatusPs)
{
    REG_BITS_WRITE(
      Module->GPIO_POSCR.reg, MASK_1_BIT << (PinIndex + POS_16_OFFSET), StatusPc << (PinIndex + POS_16_OFFSET));
    REG_BITS_WRITE(Module->GPIO_POSCR.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
}

/**
 * @brief 置位GPIO端口指定引脚输出
 *
 * @param Module
 * @param PinIndex 端口引脚编号(0-15)
 * @param StatusPs 是否置位GPIO端口指定引脚PS状态
 *        false 无操作
 *        true 置位
 * @retval void
 */
KF_INLINE void Gpio_LL_SetOutput(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPs)
{
    if (StatusPs)
    {
        REG_BITS_WRITE(Module->GPIO_POSR.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
    }
    else
    {
        ;
    }
}

/**
 * @brief 置位GPIO端口指定引脚输出
 *
 * @param Module
 * @param PinIndex 端口引脚编号(0-3)
 * @param StatusPs 是否置位GPIO端口指定引脚PS状态
 *        false 无操作
 *        true 置位
 * @retval void
 */
KF_INLINE void
Gpio_LL_SetOutputReg0(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPs)
{
    KF_DRV_GPIO_ASSERT(CHECK_GPIO_POSR0(PinIndex));

    if (StatusPs)
    {
        REG_BITS_WRITE(Module->GPIO_POSR0.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
    }
    else
    {
        ;
    }
}

/**
 * @brief 置位GPIO端口指定引脚输出
 *
 * @param Module
 * @param PinIndex 端口引脚编号(4-7)
 * @param StatusPs 是否置位GPIO端口指定引脚PS状态
 *        false 无操作
 *        true 置位
 * @retval void
 */
KF_INLINE void
Gpio_LL_SetOutputReg4(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPs)
{
    KF_DRV_GPIO_ASSERT(CHECK_GPIO_POSR4(PinIndex));

    if (StatusPs)
    {
        REG_BITS_WRITE(Module->GPIO_POSR4.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
    }
    else
    {
        ;
    }
}

/**
 * @brief 置位GPIO端口指定引脚输出
 *
 * @param Module
 * @param PinIndex 端口引脚编号(8-12)
 * @param StatusPs 是否置位GPIO端口指定引脚PS状态
 *        false 无操作
 *        true 置位
 * @retval void
 */
KF_INLINE void
Gpio_LL_SetOutputReg8(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPs)
{
    KF_DRV_GPIO_ASSERT(CHECK_GPIO_POSR8(PinIndex));

    if (StatusPs)
    {
        REG_BITS_WRITE(Module->GPIO_POSR8.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
    }
    else
    {
        ;
    }
}

/**
 * @brief 置位GPIO端口指定引脚输出
 *
 * @param Module
 * @param PinIndex 端口引脚编号(12-15)
 * @param StatusPs 是否置位GPIO端口指定引脚PS状态
 *        false 无操作
 *        true 置位
 * @retval void
 */
KF_INLINE void
Gpio_LL_SetOutputReg12(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPs)
{
    KF_DRV_GPIO_ASSERT(CHECK_GPIO_POSR12(PinIndex));

    if (StatusPs)
    {
        REG_BITS_WRITE(Module->GPIO_POSR12.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
    }
    else
    {
        ;
    }
}

/**
 * @brief 清零GPIO端口指定引脚输出
 *
 * @param Module
 * @param PinIndex 端口引脚编号(0-15)
 * @param StatusPs 是否清零GPIO端口指定引脚PS状态
 *        false 无操作
 *        true 清零
 * @retval void
 */
KF_INLINE void
Gpio_LL_ClearOutput(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPs)
{
    if (StatusPs)
    {
        REG_BITS_WRITE(Module->GPIO_POCR.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
    }
    else
    {
        ;
    }
}

/**
 * @brief 清零GPIO端口指定引脚输出
 *
 * @param Module
 * @param PinIndex 端口引脚编号(0-3)
 * @param StatusPs 是否清零GPIO端口指定引脚PS状态
 *        false 无操作
 *        true 置位
 * @retval void
 */
KF_INLINE void
Gpio_LL_ClearOutputReg0(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPs)
{
    KF_DRV_GPIO_ASSERT(CHECK_GPIO_POCR0(PinIndex));

    if (StatusPs)
    {
        REG_BITS_WRITE(Module->GPIO_POCR0.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
    }
    else
    {
        ;
    }
}

/**
 * @brief 清零GPIO端口指定引脚输出
 *
 * @param Module
 * @param PinIndex 端口引脚编号(4-7)
 * @param StatusPs 是否清零GPIO端口指定引脚PS状态
 *        false 无操作
 *        true 置位
 * @retval void
 */
KF_INLINE void
Gpio_LL_ClearOutputReg4(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPs)
{
    KF_DRV_GPIO_ASSERT(CHECK_GPIO_POCR4(PinIndex));

    if (StatusPs)
    {
        REG_BITS_WRITE(Module->GPIO_POCR4.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
    }
    else
    {
        ;
    }
}

/**
 * @brief 清零GPIO端口指定引脚输出
 *
 * @param Module
 * @param PinIndex 端口引脚编号(8-12)
 * @param StatusPs 是否清零GPIO端口指定引脚PS状态
 *        false 无操作
 *        true 置位
 * @retval void
 */
KF_INLINE void
Gpio_LL_ClearOutputReg8(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPs)
{
    KF_DRV_GPIO_ASSERT(CHECK_GPIO_POCR8(PinIndex));

    if (StatusPs)
    {
        REG_BITS_WRITE(Module->GPIO_POCR8.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
    }
    else
    {
        ;
    }
}

/**
 * @brief 清零GPIO端口指定引脚输出
 *
 * @param Module
 * @param PinIndex 端口引脚编号(12-15)
 * @param StatusPs 是否清零GPIO端口指定引脚PS状态
 *        false 无操作
 *        true 置位
 * @retval void
 */
KF_INLINE void
Gpio_LL_ClearOutputReg12(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool StatusPs)
{
    KF_DRV_GPIO_ASSERT(CHECK_GPIO_POCR12(PinIndex));

    if (StatusPs)
    {
        REG_BITS_WRITE(Module->GPIO_POCR12.reg, MASK_1_BIT << PinIndex, StatusPs << PinIndex);
    }
    else
    {
        ;
    }
}

/**
 * @brief 配置GPIO端口指定引脚的上下拉使能
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号
 * @param PinPuPdState 上拉/下拉使能控制
 *        GPIO_PIN_PUPD_NONE0 对应引脚上下拉功能禁止
 *        GPIO_PIN_PU     对应引脚上拉功能使能
 *        GPIO_PIN_PU,    对应引脚下拉功能使能
 *        GPIO_PIN_PUPD_NONE1 对应引脚上下拉功能禁止
 * @retval void
 */
KF_INLINE void Gpio_LL_WritePullUpDownStatus(
  Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const Gpio_PinPuPdState_t PinPuPdState)
{
    REG_BITS_WRITE(
      Module->GPIO_PUDEN.reg, MASK_2_BIT << (PinIndex * POS_2_SHIFT), PinPuPdState << (PinIndex * POS_2_SHIFT));
}

/**
 * @brief 获取GPIO端口指定引脚的上下拉使能状态
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号
 * @retval Gpio_PinPuPdState_t 上拉/下拉使能控制状态
 *         GPIO_PIN_PUPD_NONE0 对应引脚上下拉功能禁止
 *         GPIO_PIN_PU      对应引脚上拉功能使能
 *         GPIO_PIN_PD,     对应引脚下拉功能使能
 *         GPIO_PIN_PUPD_NONE1 对应引脚上下拉功能禁止
 */
KF_INLINE Gpio_PinPuPdState_t
Gpio_LL_ReadPullUpDownStatus(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex)
{
    return ((Gpio_PinPuPdState_t)REG_BITS_READ(
      Module->GPIO_PUDEN.reg, MASK_2_BIT << (PinIndex * POS_2_SHIFT), PinIndex * POS_2_SHIFT));
}

/**
 * @brief 获取GPIO端口指定引脚在开漏输出控制寄存器的状态
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号
 * @retval bool 对应引脚的状态
 *         false 对应引脚为推挽输出
 *         true  对应引脚为开漏输出
 */
KF_INLINE
bool Gpio_LL_ReadOpenDrainStatus(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex)
{
    return (REG_BITS_READ(Module->GPIO_PODR.reg, MASK_1_BIT << PinIndex, PinIndex));
}

/**
 * @brief 配置GPIO端口指定引脚在开漏输出控制寄存器的状态
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号
 * @param Status bool 对应引脚的状态
 *         false 对应引脚为推挽输出
 *         true  对应引脚为开漏输出
 * @retval void
 */
KF_INLINE
void Gpio_LL_WriteOpenDrainStatus(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool Status)
{
    REG_BITS_WRITE(Module->GPIO_PODR.reg, MASK_1_BIT << PinIndex, Status << PinIndex);
}

/**
 * @brief 配置GPIO端口指定引脚在端口输出使能控制寄存器的状态
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号
 * @param PinOutputEn 对应引脚的状态
 *        GPIO_PIN_OUTPUT_ENNO 输出使能关闭
 *        GPIO_PIN_OUTPUT_EN   输出使能打开
 *        其他                 保留
 * @retval void
 */
KF_INLINE void Gpio_LL_WriteOutputEnStatus(
  Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const Gpio_PinOutputEn_t PinOutputEn)
{
    REG_BITS_WRITE(
      Module->GPIO_PMOD.reg, MASK_2_BIT << (PinIndex * POS_2_SHIFT), PinOutputEn << (PinIndex * POS_2_SHIFT));
}

/**
 * @brief 配置输出多路选择器寄存器
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号
 * @param PinRemap 指定引脚选择的重映射通道
 * @retval void
 */
KF_INLINE void Gpio_LL_WriteOutputMultiSelStatus(
  Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const Gpio_PinRemap_t PinRemap)
{
    if (GPIO_PIN_INDEX_8 > PinIndex)
    {
        REG_BITS_WRITE(
          Module->GPIO_PEROUT0.reg, MASK_4_BIT << (PinIndex * POS_4_SHIFT), PinRemap << (PinIndex * POS_4_SHIFT));
    }
    else
    {
        REG_BITS_WRITE(
          Module->GPIO_PEROUT1.reg, MASK_4_BIT << (PinIndex * POS_4_SHIFT), PinRemap << (PinIndex * POS_4_SHIFT));
    }
}

/**
 * @brief 配置GPIO端口指定引脚的Pad驱动模式
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号
 * @param PadDriverMode Px的Pad驱动模式 取值0~3
 * @retval void
 */
KF_INLINE void Gpio_LL_WritePadDriverModeStatus(
  Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const Gpio_PadDriverMode_t PadDriverMode)
{
    if (GPIO_PIN_INDEX_8 > PinIndex)
    {
        REG_BITS_WRITE(
          Module->GPIO_PDR0.reg, MASK_2_BIT << (PinIndex * POS_4_SHIFT), PadDriverMode << (PinIndex * POS_4_SHIFT));
    }
    else
    {
        REG_BITS_WRITE(
          Module->GPIO_PDR1.reg, MASK_2_BIT << (PinIndex * POS_4_SHIFT), PadDriverMode << (PinIndex * POS_4_SHIFT));
    }
}

/**
 * @brief 配置紧急停止寄存器的紧急停止使能功能
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号 取值0~15
 * @param Status bool 紧急停止使能
 *        false  禁止紧急停止功能
 *        true   使能紧急停止功能
 * @retval void
 */
KF_INLINE void
Gpio_LL_WriteEsEnStatus(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool Status)
{
    REG_BITS_WRITE(Module->GPIO_ESR.reg, MASK_1_BIT << PinIndex, Status << PinIndex);
}

/**
 * @brief 配置端口配置锁定寄存器
 *
 *
 * @param Module
 * @param LockValue 锁定值，上层已做过处理
 * @retval void
 */
KF_INLINE void
Gpio_LL_WriteLockStatus(Gpio_RegisterMap_t *const Module, const uint32_t LockValue)
{
    REG_WRITE(Module->GPIO_LOCK.reg, LockValue);
}

/**
 * @brief 配置端口配置锁定寄存器
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号 取值0~15
 * @param Status bool 紧急停止使能
 *          false 对应引脚为未锁定
 *          true 对应引脚为锁定配置
 * @retval void
 */
KF_INLINE void
Gpio_LL_WriteLockPin(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool Status)
{
    REG_BITS_WRITE(Module->GPIO_LOCK.reg, (uint32_t)(MASK_1_BIT << PinIndex),
                   (uint32_t)((Status << PinIndex) | (GPIO_PIN_LOCK_KEY << 16U)));
}

/**
 * @brief 自检触发模式选择
 *
 * @param Module
 * @param PinIndex 端口引脚编号 取值0~15
 * @param Status bool 紧急停止使能
 *          false 对应引脚为未锁定
 *          true 对应引脚为锁定配置
 * @retval void
 */
KF_INLINE void
Gpio_LL_SetPinSelfDetectTrigger(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool Status)
{
    REG_BITS_WRITE(Module->GPIO_LOCK.reg, (uint32_t)(MASK_1_BIT << PinIndex), (uint32_t)(Status << PinIndex));
}

/**
 * @brief 配置引脚的硬件控制使能状态
 *
 * @param Module
 * @param PinIndex 端口引脚编号 取值0~15
 * @param Status bool 引脚的硬件控制使能状态
 *        false  禁用引脚的ADCs PDD/MD功能，禁用SACU覆盖FSP pin y的Pad配置
 *        true   使能引脚的ADCs PDD/MD功能，使能SACU覆盖FSP pin y的Pad配置
 * @retval void
 */
KF_INLINE void
Gpio_LL_WritePinHwCtrlEnStatus(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool Status)
{
    REG_BITS_WRITE(Module->GPIO_PCSR.reg, MASK_1_BIT << PinIndex, Status << PinIndex);
}

/**
 * @brief 配置GPIO端口的输入使能控制
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号 取值0~15
 * @param Status bool GPIO端口的输入控制使能
 *        false  输入禁止
 *        true   输入使能
 * @retval void
 */
KF_INLINE void
Gpio_LL_WriteInputEnCtrlStatus(Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool Status)
{
    REG_BITS_WRITE(Module->GPIO_INEN.reg, MASK_1_BIT << PinIndex, Status << PinIndex);
}

/**
 * @brief 配置GPIO端口指定引脚的紧急停止上下拉控制寄存器
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号 取值0~15
 * @param Status bool 上下拉控制
 *        false  紧急停止时IO口进入三态模式
 *        true   紧急停止时IO口进入上拉模式
 * @retval void
 */
KF_INLINE void Gpio_LL_WriteEmergencyStopPullUpDownStatus(
  Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool Status)
{
    REG_BITS_WRITE(Module->GPIO_PUDRST.reg, MASK_1_BIT << PinIndex, Status << PinIndex);
}

/**
 * @brief 配置外设硬件控制上下拉使能
 *
 *
 * @param Module
 * @param PinIndex 端口引脚编号 取值0~15
 * @param Status bool GPIO端口的输入控制使能
 *        false  禁止外设控制GPIO上下拉
 *        true   使能外设控制GPIO上下拉
 * @retval void
 */
KF_INLINE void Gpio_LL_WritePeripheralHwPullUpDownEnabled(
  Gpio_RegisterMap_t *const Module, const Gpio_PinIndex_t PinIndex, const bool Status)
{
    REG_BITS_WRITE(Module->GPIO_HWPUDEN.reg, MASK_1_BIT << PinIndex, Status << PinIndex);
}

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
