/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_osc.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-11-28
 *  @Version         : V0.0.1.231128_alpha
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
 *  |2023-11-28    |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/
#ifndef KF32A13K_REG_CLK_H_
#define KF32A13K_REG_CLK_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :2; /*!< [1:0] 预留，读为0 */
            __O uint32_t  OSCWDRST  :1; /*!< [2:2] OSC看门狗复位 */
            __IO uint32_t GAINMOD   :2; /*!< [4:3] OSC 增益选择模式 */
            __IO uint32_t OSCMOD    :2; /*!< [6:5] OSC 模式选择位 */
            __IO uint32_t SHBYEN    :1; /*!< [7:7] 整形器绕过使能位 */
            __IO uint32_t RESERVED1 :1; /*!< [8:8] 预留，读为0 */
            __IO uint32_t HYSEN     :1; /*!< [9:9] 滞后使能位 */
            __IO uint32_t HYSMOD    :2; /*!< [11:10] 滞后控制模式位 */
            __IO uint32_t AMPMOD    :2; /*!< [13:12] 振幅控制模式位 */
            __IO uint32_t RESERVED2 :2; /*!< [15:14] 预留，读为0 */
            __IO uint32_t OSCVAL    :5; /*!< [20:16] OSC 频率数值 */
            __IO uint32_t RESERVED3 :2; /*!< [22:21] 预留，读为0 */
            __IO uint32_t APREN     :1; /*!< [23:23] 振幅调节使能位 */
            __IO uint32_t RESERVED4 :8; /*!< [31:24] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} OSC_CTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t HSXTALEXEN :1; /*!< [0:0] 外部高频外部输入时钟使能 */
            __IO uint32_t HSEMODESEL :1; /*!< [1:1] 外部高频的驱动模式选择 */
            __IO uint32_t GMBOOST    :4; /*!< [5:2] 外部高频晶振驱动调节档位选项 */
            __IO uint32_t RESERVED0  :3; /*!< [8:6] 预留，读为0 */
            __IO uint32_t XTHR2M     :1; /*!< [9:9] 外部高频晶振内部并联 2MΩ选择位 */
            __IO uint32_t XTHR470K   :1; /*!< [10:10] 外部高频晶振内部并联 470kΩ选择位 */
            __IO uint32_t XTHR200K   :1; /*!< [11:11] 外部高频晶振内部并联 200kΩ选择位 */
            __IO uint32_t RESERVED1  :1; /*!< [12:12] 预留，读为0 */
            __IO uint32_t XTHCOMPEN  :1; /*!< [13:13] 外部高频晶振的比较器时钟整形使能 */
            __IO uint32_t XTHCOMPI   :2; /*!< [15:14] 外部高频晶振的比较器电流调整位 */
            __IO uint32_t RESERVED2  :8; /*!< [23:16] 预留，读为0 */
            __IO uint32_t CAP0EN     :1; /*!< [24:24] 外部高频晶振内部负载电容 0 使能位 */
            __IO uint32_t CAP1EN     :1; /*!< [25:25] 电容 1 使能位 */
            __IO uint32_t CAP2EN     :1; /*!< [26:26] 电容 2 使能位 */
            __IO uint32_t CAP3EN     :1; /*!< [27:27] 电容 3 使能位 */
            __IO uint32_t RESERVED3  :4; /*!< [31:28] 预留，读为0 */

        } bits;
        __IO uint32_t reg;
    };
} OSC_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  PLLLSTA   :1;  /*!< [0:0] 对于 PLL 下限频率，OSC 频率有效状态标志位 */
            __IO uint32_t RESERVED0 :7;  /*!< [7:1] 预留，读为0 */
            __I uint32_t  PLLHSTA   :1;  /*!< [8:8] 对于 PLL 上限频率，OSC 频率有效状态标志位 */
            __IO uint32_t RESERVED1 :23; /*!< [31:9] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} OSC_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  EXTHFSWEN   :1;  /*!< [0:0] 外部高频振荡器软件使能位 */
            __O uint32_t  EXTLFSWEN   :1;  /*!< [1:1] 外部低频振荡器软件使能位 */
            __O uint32_t  SYSPLLSWEN  :1;  /*!< [2:2] 系统 PLL 软件使能位 */
            __O uint32_t  PERPLLSWEN  :1;  /*!< [3:3] 外设 PLL 软件使能位 */
            __O uint32_t  INTHF32SWEN :1;  /*!< [4:4] 内部高频振荡器 32MHz 软件使能位 */
            __O uint32_t  INTLFSWEN   :1;  /*!< [5:5] 内部低频振荡器软件使能位 */
            __IO uint32_t RESERVED0   :26; /*!< [31:26] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CLKSYS_CTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  EXTHFSWDIS   :1;  /*!< [0:0] 外部高频振荡器软件禁用位 */
            __O uint32_t  EXTLFSWDIS   :1;  /*!< [1:1] 外部低频振荡器软件禁用位 */
            __O uint32_t  SYSPLLSWDIS  :1;  /*!< [2:2] 系统 PLL 软件禁用位 */
            __O uint32_t  PERPLLSWDIS  :1;  /*!< [3:3] 外设 PLL 软件禁用位 */
            __O uint32_t  INTHF32SWDIS :1;  /*!< [4:4] 内部高频振荡器 32MHz 软件禁用位 */
            __O uint32_t  INTLFSWDIS   :1;  /*!< [5:5] 内部低频振荡器软件禁用位 */
            __IO uint32_t RESERVED0    :26; /*!< [31:6] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CLKSYS_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EXTHFDLY   :5; /*!< [0:4] 外部高频振荡器延时控制位 */
            __IO uint32_t EXTLFDLY   :5; /*!< [5:9] 外部低频振荡器延时控制位 */
            __IO uint32_t SYSPLLDLY  :5; /*!< [10:14] 系统 PLL 延时控制位 */
            __IO uint32_t PERPLLDLY  :5; /*!< [15:19] 外设 PLL 延时控制位 */
            __IO uint32_t INTHF32DLY :5; /*!< [20:24] 内部高频振荡器延时控制位 */
            __IO uint32_t INTLFDLY   :5; /*!< [29:25] 内部低频振荡器延时控制位 */
            __IO uint32_t RESERVED0  :2; /*!< [31:30] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CLKSYS_CTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EXTHFSW     :1;  /*!< [0:0] 外部高频振荡器软件控制位 */
            __IO uint32_t EXTLFSW     :1;  /*!< [1:1] 外部低频振荡器软件控制位 */
            __IO uint32_t SYSPLLSW    :1;  /*!< [2:2] 系统 PLL 软件控制位 */
            __IO uint32_t PERPLLSW    :1;  /*!< [3:3] 外设 PLL 软件控制位 */
            __IO uint32_t INTHF32SW   :1;  /*!< [4:4] 内部高频振荡器软件控制位 */
            __IO uint32_t INTLFSW     :1;  /*!< [5:5] 内部低频振荡器延时控制位 */
            __IO uint32_t RESERVED0   :10; /*!< [15:6] 预留，读为0 */
            __I uint32_t  EXTHFFLAG   :1;  /*!< [16:16] 外部高频振荡器稳定可用 */
            __I uint32_t  EXTLFFLAG   :1;  /*!< [17:17] 外部低频振荡器稳定可用 */
            __I uint32_t  SYSPLLFLAG  :1;  /*!< [18:18] 系统 PLL 稳定可用 */
            __I uint32_t  PERPLLFLAG  :1;  /*!< [19:19] 外设 PLL 稳定可用 */
            __I uint32_t  INTHF32FLAG :1;  /*!< [20:20] 内部高频振荡器稳定可用 */
            __I uint32_t  INTLFFLAG   :1;  /*!< [21:21] 内部低频振荡器稳定可用 */
            __IO uint32_t RESERVED1   :10; /*!< [31:22] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CLKSYS_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SYSPLLIE  :1;  /*!< [0:0]系统 PLL 中断使能位 */
            __IO uint32_t PERPLLIE  :1;  /*!< [1:1]外设 PLL 中断使能位 */
            __IO uint32_t EHFIE     :1;  /*!< [2:2]外部高频中断使能位 */
            __IO uint32_t ELFIE     :1;  /*!< [3:3]外部低频中断使能位 */
            __IO uint32_t IHFIE     :1;  /*!< [4:4]内部高频中断使能位 */
            __IO uint32_t ILFIE     :1;  /*!< [5:5]内部低频中断使能位 */
            __IO uint32_t RESERVED0 :26; /*!< [31:6]预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CLKSYS_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :1;  /*!< [0:0] 预留，读为0 */
            __I uint32_t  PSSTA     :1;  /*!< [1:1] 系统 PLL 节能模式标志位 */
            __I uint32_t  LOCKSTA   :1;  /*!< [2:2] 系统 PLL 锁定状态 */
            __IO uint32_t RESERVED1 :2;  /*!< [4:3] 预留，读为0 */
            __I uint32_t  K2RDYSTA  :1;  /*!< [5:5] K2 分频器就绪状态位 */
            __IO uint32_t RESERVED2 :1;  /*!< [6:6] 预留，读为0 */
            __I uint32_t  MODRUNSTA :1;  /*!< [7:7] 调制运行标志位 */
            __IO uint32_t RESERVED3 :24; /*!< [31:8] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} SYSPLL_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M         :14; /*!< [13:0] 系统 PLL 反馈驱动控制 */
            __IO uint32_t RESERVED0 :2;  /*!< [15:14] 预留，读为0 */
            __IO uint32_t N         :4;  /*!< [19:16] 系统 PLL 输入驱动控制 */
            __IO uint32_t PLLDIV    :1;  /*!< [20:20] 系统 PLL 输入时钟源2分频 */
            __IO uint32_t MODEN     :1;  /*!< [21:21] 系统 PLL 调制使能 */
            __IO uint32_t RESERVED1 :2;  /*!< [23:22] 预留，读为0 */
            __IO uint32_t PSMOD     :1;  /*!< [24:24] 系统 PLL 节能模式 */
            __IO uint32_t RESERVED2 :3;  /*!< [27:25] 预留，读为0 */
            __O uint32_t  DCOLDRST  :1;  /*!< [28:28] 重启锁相检测控制器(DCO)锁定监测 */
            __O uint32_t  PDRST     :1;  /*!< [29:29] 系统 PLL 复位控制 */
            __IO uint32_t INCLKSEL  :2;  /*!< [31:30] 输入时钟源选择 */
        } bits;
        __IO uint32_t reg;
    };
} SYSPLL_CTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t K2CLKDIV  :3;  /*!< [2:0] K2 分频器数值设置 */
            __IO uint32_t RESERVED0 :29; /*!< [31:3] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} SYSPLL_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t MODCFG    :16; /*!< [15:0] PLL 调制振幅 */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} SYSPLL_CTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :1;  /*!< [0:0] 预留，读为0 */
            __I uint32_t  PSSTA     :1;  /*!< [1:1] 外设 PLL 节能模式标志位 */
            __I uint32_t  LOCKSTA   :1;  /*!< [2:2] 外设 PLL 锁定状态 */
            __IO uint32_t RESERVED1 :1;  /*!< [3:3] 预留，读为0 */
            __I uint32_t  K3RDYSTA  :1;  /*!< [4:4] K3 分频器就绪状态 */
            __I uint32_t  K2RDYSTA  :1;  /*!< [5:5] K2 分频器就绪状态 */
            __IO uint32_t RESERVED2 :26; /*!< [31:6] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} PERPLL_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DIVBYEN   :1;  /*!< [0:0] 分频器绕过使能位 */
            __IO uint32_t RESERVED0 :1;  /*!< [1:1] 预留，读为0 */
            __IO uint32_t M         :14; /*!< [15:2] M分频器数值设置 */
            __IO uint32_t PSMOD     :1;  /*!< [16:16] 外设 PLL 节能模式 */
            __IO uint32_t PLLDIV    :1;  /*!< [17:17] 选择外设 PLL 输入时钟源不分频或 2 分频 */
            __O uint32_t  RESLD     :1;  /*!< [18:18] 重启 DCO 锁定监测 */
            __IO uint32_t RESERVED1 :5;  /*!< [23:19] 预留，读为0 */
            __IO uint32_t N         :4;  /*!< [27:24] N 分频器数值设置 */
            __O uint32_t  PDRST     :1;  /*!< [28:28] 外设 PLL 复位控制 */
            __IO uint32_t RESERVED2 :3;  /*!< [31:29] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} PERPLL_CTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t K2CLKDIV  :3;  /*!< [2:0] K2 分频器数值设置 */
            __IO uint32_t RESERVED0 :5;  /*!< [7:3] 预留，读为0 */
            __IO uint32_t K3CLKDIV  :3;  /*!< [10:8] K3 分频器数值设置 */
            __IO uint32_t RESERVED1 :21; /*!< [31:11] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} PERPLL_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CLKSEL0   :3;  /*!< [2:0] 时钟域 source0 时钟源选择 */
            __IO uint32_t RESERVED0 :5;  /*!< [7:3] 预留，读为0 */
            __IO uint32_t CLKSEL1   :3;  /*!< [10:8] 时钟域 source1 时钟源选择 */
            __IO uint32_t PLL1DIV   :1;  /*!< [11:11] PLL1 二分频器 */
            __IO uint32_t RESERVED1 :4;  /*!< [15:12] 预留，读为0 */
            __IO uint32_t CLKSEL2   :3;  /*!< [18:16] 时钟域 source2 时钟源选择 */
            __IO uint32_t RESERVED2 :12; /*!< [30:19] 预留，读为0 */
            __I uint32_t  LCKSTA    :1;  /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} DOMAIN_CTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PERICLKDIV :4;  /*!< [3:0] PERI 分频器重载值 */
            __IO uint32_t SYSCLKDIV  :4;  /*!< [7:4] SYS 分频器重载值 */
            __IO uint32_t TMRCLKDIV  :4;  /*!< [11:8] TMR 分频器重载值 */
            __IO uint32_t LPCLKDIV   :3;  /*!< [14:12] 低功耗分频器重载值 */
            __IO uint32_t RESERVED0  :15; /*!< [29:15] 预留，读为0 */
            __O uint32_t  UP         :1;  /*!< [30:30] 更新请求 */
            __I uint32_t  LCKSTA     :1;  /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} CDU_CTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STCLKDIV      :4; /*!< [3:0] Systick 分频器重载值 */
            __IO uint32_t CANHCLKDIV    :4; /*!< [7:4] CANH 分频器重载值 */
            __IO uint32_t REFCLK1CLKDIV :5; /*!< [12:8] REFCLK1 分频器重载值 */
            __IO uint32_t REFCLK2CLKDIV :5; /*!< [17:13] REFCLK2 分频器重载值 */
            __IO uint32_t REFCLK2SEL    :1; /*!< [18:18] SRCREFCLK2 时钟源选择 */
            __IO uint32_t MSCCLKDIV     :4; /*!< [22:19] MSC 分频器重载值 */
            __IO uint32_t MSCCLKSEL     :1; /*!< [23:23] MSC 时钟源选择 */
            __IO uint32_t RTCCLKDIV     :4; /*!< [27:24] RTC 分频器重载值 */
            __IO uint32_t RTCCLKSEL     :1; /*!< [28:28] RTC 时钟源选择 */
            __IO uint32_t RESERVED0     :2; /*!< [30:29] 预留，读为0 */
            __I uint32_t  LCKSTA        :1; /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} CDU_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SPICLKDIV    :4; /*!< [3:0] SPI 分频器重载值 */
            __IO uint32_t SPICLKSEL    :1; /*!< [4:4] SPI 时钟源选择 */
            __IO uint32_t ADCCLKDIV    :4; /*!< [8:5] ADC 分频器重载值 */
            __IO uint32_t ADCCLKSEL    :1; /*!< [9:9] ADC 时钟源选择 */
            __IO uint32_t I2CCLKDIV    :4; /*!< [13:10] I2C 分频器重载值 */
            __IO uint32_t I2CCLKSEL    :1; /*!< [14:14] I2C 时钟源选择 */
            __IO uint32_t CANCLKDIV    :4; /*!< [18:15] CAN 分频器重载值 */
            __IO uint32_t CANCLKSEL    :1; /*!< [19:19] CAN 时钟源选择 */
            __IO uint32_t UTLINFCLKDIV :4; /*!< [23:20] UTLINF 分频器重载值 */
            __IO uint32_t UTLINFCLKSEL :1; /*!< [24:24] UTLINF 时钟源选择 */
            __IO uint32_t UTLINSCLKDIV :4; /*!< [28:25] UTLINS 分频器重载值 */
            __IO uint32_t UTLINSCLKSEL :1; /*!< [29:29] UTLINS 时钟源选择 */
            __IO uint32_t RESERVED0    :1; /*!< [30:30] 预留，读为0 */
            __I uint32_t  LCKSTA       :1; /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} CDU_CTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CPU0CLKDIV :6;  /*!< [5:0] CPU0 分频器重载值 */
            __IO uint32_t RESERVED0  :26; /*!< [31:6] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CDU_CTL3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CPU1CLKDIV :6;  /*!< [5:0] CPU1 分频器重载值 */
            __IO uint32_t RESERVED0  :26; /*!< [31:6] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CDU_CTL4_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PERICLKMOD    :1;  /*!< [0:0] PERICLK整数分频器模式选择位 */
            __IO uint32_t SYSCLKMOD     :1;  /*!< [1:1] SYSCLK整数分频器模式选择位 */
            __IO uint32_t TMRCLKMOD     :1;  /*!< [2:2] TMRCLK整数分频器模式选择位 */
            __IO uint32_t STCLKMOD      :1;  /*!< [3:3] STCLK整数分频器模式选择位 */
            __IO uint32_t CANHCLKMOD    :1;  /*!< [4:4] CANHCLK整数分频器模式选择位 */
            __IO uint32_t REFCLK1CLKMOD :1;  /*!< [5:5] REFCLK1整数分频器模式选择位 */
            __IO uint32_t REFCLK2CLKMOD :1;  /*!< [6:6] REFCLK2整数分频器模式选择位 */
            __IO uint32_t MSCCLKMOD     :1;  /*!< [7:7] MSCCLK整数分频器模式选择位 */
            __IO uint32_t RTCCLKMOD     :1;  /*!< [8:8] RTCCLK整数分频器模式选择位 */
            __IO uint32_t SPICLKMOD     :1;  /*!< [9:9] SPICLK整数分频器模式选择位 */
            __IO uint32_t ADCCLKMOD     :1;  /*!< [10:10] ADCCLK整数分频器模式选择位 */
            __IO uint32_t I2CCLKMOD     :1;  /*!< [11:11] I2CCLK整数分频器模式选择位 */
            __IO uint32_t CANCLKMOD     :1;  /*!< [12:12] CANCLK整数分频器模式选择位 */
            __IO uint32_t UTLINFCLKMOD  :1;  /*!< [13:13] UTLINFCLK整数分频器模式选择位 */
            __IO uint32_t UTLINSCLKMOD  :1;  /*!< [14:14] UTLINSCLK整数分频器模式选择位 */
            __IO uint32_t RESERVED0     :17; /*!< [31:15] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CDU_CTL5_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PLL0MONEN      :1;  /*!< [0:0] PLL0 时钟监视器使能 */
            __IO uint32_t PLL1MONEN      :1;  /*!< [1:1] PLL1 时钟监视器使能 */
            __IO uint32_t PLL2MONEN      :1;  /*!< [2:2] PLL2 时钟监视器使能 */
            __IO uint32_t PERIMONEN      :1;  /*!< [3:3] PERICLK 时钟监视器使能 */
            __IO uint32_t INTHF100MONEN  :1;  /*!< [4:4] INTHF100 时钟监视器使能 */
            __IO uint32_t INTHF32MONEN   :1;  /*!< [5:5] INTHF32 时钟监视器使能 */
            __IO uint32_t RESERVED0      :2;  /*!< [7:6] 预留，读为0 */
            __IO uint32_t PLL0MONTST     :1;  /*!< [8:8] PLL0 时钟监视器测试 */
            __IO uint32_t PLL1MONTST     :1;  /*!< [9:9] PLL1 时钟监视器测试 */
            __IO uint32_t PLL2MONTST     :1;  /*!< [10:10] PLL2 时钟监视器测试 */
            __IO uint32_t PERIMONTST     :1;  /*!< [11:11] PERI 时钟监视器测试 */
            __IO uint32_t INTHF100MONTST :1;  /*!< [12:12] INTHF100 时钟监视器测试 */
            __IO uint32_t INTHF32MONTST  :1;  /*!< [13:13] INTHF32 时钟监视器测试 */
            __IO uint32_t RESERVED1      :17; /*!< [30:14] 预留，读为0 */
            __I uint32_t  LCKSTA         :1;  /*!< [31:31] 锁定状态位 */
        } bits;
        __IO uint32_t reg;
    };
} CLKM_CTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LOTHR     :12; /*!< [11:0] 内部高频 100MHz 监视器下限阈值 */
            __IO uint32_t UPTHR     :12; /*!< [23:12] 内部高频 100MHz 监视器上限阈值 */
            __IO uint32_t MONEN     :1;  /*!< [24:24] 内部高频 100MHz 监视器使能 */
            __IO uint32_t MONTST    :1;  /*!< [25:25] 内部高频 100MHz 监视器测试 */
            __IO uint32_t RESERVED0 :5;  /*!< [30:26] 预留，读为0 */
            __I uint32_t  LCKSTA    :1;  /*!< [31:31] 锁定状态位 */
        } bits;
        __IO uint32_t reg;
    };
} CLKM_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LOTHR     :12; /*!< [11:0] 测试时钟监视器下限阈值 */
            __IO uint32_t UPTHR     :12; /*!< [23:12] 测试时钟监视器上限阈值 */
            __IO uint32_t MONEN     :1;  /*!< [24:24] 测试时钟监视器使能 */
            __IO uint32_t MONTST    :1;  /*!< [25:25] 测试时钟监视器测试 */
            __IO uint32_t REFCLKSEL :3;  /*!< [28:26] REFCLK 时钟选择 */
            __IO uint32_t RESERVED0 :3;  /*!< [31:29] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CLKM_TEST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t MONCLKSEL :5;  /*!< [4:0] 测试时钟选择 */
            __IO uint32_t MONCLKEN  :1;  /*!< [5:5] MONCLK 时钟门控 */
            __IO uint32_t RESERVED0 :26; /*!< [31:6] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CLKM_TEST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN0       :1;  /*!< [0:0] 外部时钟输出 EXTCLK0 使能位 */
            __IO uint32_t NSEL0     :1;  /*!< [1:1] 外部时钟信号 EXTCLK0 反相选择 */
            __IO uint32_t SEL0      :4;  /*!< [5:2] 引脚 EXTCLK0 输出时钟信号选择 */
            __IO uint32_t RESERVED0 :10; /*!< [15:6] 预留，读为0 */
            __IO uint32_t EN1       :1;  /*!< [16:16] 外部时钟输出 EXTCLK1 使能位 */
            __IO uint32_t NSEL1     :1;  /*!< [17:17] 外部时钟信号 EXTCLK1 反相选择 */
            __IO uint32_t SEL1      :5;  /*!< [22:18] 引脚 EXTCLK1 输出时钟信号选择 */
            __IO uint32_t RESERVED1 :1;  /*!< [23:23] 预留，读为0 */
            __IO uint32_t DIV       :8;  /*!< [31:24] OUTCLK1 时钟整数分频器 */
        } bits;
        __IO uint32_t reg;
    };
} EXTCLK_CTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DIVSTEP0  :4;  /*!< [3:0] EXTCLK0 外部输出分频器 */
            __IO uint32_t RESERVED0 :12; /*!< [15:4] 预留，读为0 */
            __IO uint32_t DIVSTEP1  :4;  /*!< [19:16] EXTCLK1 外部输出分频器 */
            __IO uint32_t RESERVED1 :12; /*!< [31:20] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} EXTCLK_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STEPVAL   :10; /*!< [9:0] RESVAL 重载值 */
            __IO uint32_t RESERVED0 :4;  /*!< [13:10] 预留，读为0 */
            __IO uint32_t DMOD      :2;  /*!< [15:14] OUTCLK0 时钟信号分频模式 */
            __I uint32_t  RESVAL    :10; /*!<  [25:16] */
            __IO uint32_t RESERVED1 :5;  /*!< [30:26] 预留，读为0 */
            __IO uint32_t CLKDIS    :1;  /*!< [31:31] 禁用 OUTCLK0 时钟 */
        } bits;
        __IO uint32_t reg;
    };
} EXTCLKFD_CTL_T;

typedef volatile struct
{
    /* offset  : 0x0000.    OSC 振荡器控制寄存器 0. */
    OSC_CTL0_T OSC_CTL0;

    /* offset  : 0x0004.    振荡器控制寄存器 1. */
    OSC_CTL1_T OSC_CTL1;

    /* offset  : 0x0008.    振荡器状态寄存器. */
    OSC_STA_T OSC_STA;

    /* offset  : 0x000C.    时钟系统控制寄存器 0. */
    CLKSYS_CTL0_T CLKSYS_CTL0;

    /* offset  : 0x0010.    时钟系统控制寄存器 1. */
    CLKSYS_CTL1_T CLKSYS_CTL1;

    /* offset  : 0x0014.    时钟系统控制寄存器 2. */
    CLKSYS_CTL2_T CLKSYS_CTL2;

    /* offset  : 0x0018.    时钟系统状态寄存器. */
    CLKSYS_STA_T CLKSYS_STA;

    /* offset  : 0x001C.    时钟系统中断使能寄存器. */
    CLKSYS_IE_T CLKSYS_IE;

    /* offset  : 0x0020.    系统 PLL 状态寄存器. */
    SYSPLL_STA_T SYSPLL_STA;

    /* offset  : 0x0024.    系统 PLL 控制寄存器 0. */
    SYSPLL_CTL0_T SYSPLL_CTL0;

    /* offset  : 0x0028.    系统 PLL 控制寄存器 1. */
    SYSPLL_CTL1_T SYSPLL_CTL1;

    /* offset  : 0x002C.    系统 PLL 控制寄存器 2. */
    SYSPLL_CTL2_T SYSPLL_CTL2;

    /* offset  : 0x0030.    外设 PLL 状态寄存器. */
    PERPLL_STA_T PERPLL_STA;

    /* offset  : 0x0034.    外设 PLL 控制寄存器 0. */
    PERPLL_CTL0_T PERPLL_CTL0;

    /* offset  : 0x0038.    外设 PLL 控制寄存器 1. */
    PERPLL_CTL1_T PERPLL_CTL1;

    /* offset  : 0x003C.    时钟域控制寄存器. */
    DOMAIN_CTL_T DOMAIN_CTL;

    /* offset  : 0x0040.    CDU 时钟控制寄存器 0. */
    CDU_CTL0_T CDU_CTL0;

    /* offset  : 0x0044.    CDU 时钟控制寄存器 1. */
    CDU_CTL1_T CDU_CTL1;

    /* offset  : 0x0048.    CDU 时钟控制寄存器 2. */
    CDU_CTL2_T CDU_CTL2;

    /* offset  : 0x004C.    CDU 时钟控制寄存器 3. */
    CDU_CTL3_T CDU_CTL3;

    /* offset  : 0x0050.    CDU 时钟控制寄存器 4. */
    CDU_CTL4_T CDU_CTL4;

    /* offset  : 0x0054.    CDU 时钟控制寄存器 5. */
    CDU_CTL5_T CDU_CTL5;

    /* offset  : 0x0058.    时钟监控控制寄存器 0. */
    CLKM_CTL0_T CLKM_CTL0;

    /* offset  : 0x005C.    时钟监控控制寄存器 1. */
    CLKM_CTL1_T CLKM_CTL1;

    /* offset  : 0x0060.    时钟监控测试寄存器 0. */
    CLKM_TEST0_T CLKM_TEST0;

    /* offset  : 0x0064.    时钟监控测试寄存器 1. */
    CLKM_TEST1_T CLKM_TEST1;

    /* offset  : 0x0068.    外部输出时钟控制寄存器 0. */
    EXTCLK_CTL0_T EXTCLK_CTL0;

    /* offset  : 0x006C.    外部输出时钟控制寄存器 1. */
    EXTCLK_CTL1_T EXTCLK_CTL1;

    /* offset  : 0x0070.    外部输出时钟分数分频器控制寄存器. */
    EXTCLKFD_CTL_T EXTCLKFD_CTL;
} Clk_RegisterMap_t;

#define CLK_ADDR ((uint32_t)0xF000F400U)
#define CLK_PTR  ((Clk_RegisterMap_t *)CLK_ADDR)
#define CLK_RM   (*(Clk_RegisterMap_t *)CLK_ADDR)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
