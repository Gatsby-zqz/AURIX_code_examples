/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_btimer.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-22
 *  @Version         : V0.0.1.231222_alpha
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
 *  |2023-12-22    |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/

#ifndef KF32A13K_REG_BPT_H_
#define KF32A13K_REG_BPT_H_

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

            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁止请求位 */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁止状态 */
            __IO uint32_t EDIS      :1;  /*!< [2:2] 休眠模式使能控制位 */
            __I uint32_t  RESERVED0 :29; /*!< [31:3] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] 模块版本号 */
            __I uint32_t MODTYPE :8;  /*!< [15:8] 模块类型 */
            __I uint32_t MODNUM  :16; /*!< [31:16] 模块编号 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :24; /*!< [23:0] 预留，读为0 */
            __IO uint32_t SUS       :4;  /*!< [27:24] 调试模式挂起控制 */
            __O uint32_t  SUSP      :1;  /*!< [28:28] SUS 位写保护，读出为 0 */
            __I uint32_t  SUSSTA    :1;  /*!< [29:29] 挂起状态位 */
            __I uint32_t  RESERVED1 :2;  /*!< [31:30] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位请求位，与 RST1 寄存器的 RST 位一起使用 */
            __I uint32_t  RSTSTA    :1;  /*!< [1:1] 复位状态 */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位请求位，与 RST0 寄存器的 RST 位一起使用 */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CLR       :1;  /*!< [0:0] RSTSTA 复位状态清除位，读出为0 */
            __I uint32_t RESERVED0 :31; /*!< [31:1] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_RSTCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN0  :1; /*!< [0:0] 使能Master TAG ID 0 的事务对模块内核地址的写访问 */
            __IO uint32_t EN1  :1; /*!< [1:1] 使能Master TAG ID 1 的事务对模块内核地址的写访问 */
            __IO uint32_t EN2  :1; /*!< [2:2] 使能Master TAG ID 2 的事务对模块内核地址的写访问 */
            __IO uint32_t EN3  :1; /*!< [3:3] 使能Master TAG ID 3 的事务对模块内核地址的写访问 */
            __IO uint32_t EN4  :1; /*!< [4:4] 使能Master TAG ID 4 的事务对模块内核地址的写访问 */
            __IO uint32_t EN5  :1; /*!< [5:5] 使能Master TAG ID 5 的事务对模块内核地址的写访问 */
            __IO uint32_t EN6  :1; /*!< [6:6] 使能Master TAG ID 6 的事务对模块内核地址的写访问 */
            __IO uint32_t EN7  :1; /*!< [7:7] 使能Master TAG ID 7 的事务对模块内核地址的写访问 */
            __IO uint32_t EN8  :1; /*!< [8:8] 使能Master TAG ID 8 的事务对模块内核地址的写访问 */
            __IO uint32_t EN9  :1; /*!< [9:9] 使能Master TAG ID 9 的事务对模块内核地址的写访问 */
            __IO uint32_t EN10 :1; /*!< [10:10] 使能Master TAG ID 10 的事务对模块内核地址的写访问 */
            __IO uint32_t EN11 :1; /*!< [11:11] 使能Master TAG ID 11 的事务对模块内核地址的写访问 */
            __IO uint32_t EN12 :1; /*!< [12:12] 使能Master TAG ID 12 的事务对模块内核地址的写访问 */
            __IO uint32_t EN13 :1; /*!< [13:13] 使能Master TAG ID 13 的事务对模块内核地址的写访问 */
            __IO uint32_t EN14 :1; /*!< [14:14] 使能Master TAG ID 14 的事务对模块内核地址的写访问 */
            __IO uint32_t EN15 :1; /*!< [15:15] 使能Master TAG ID 15 的事务对模块内核地址的写访问 */
            __IO uint32_t EN16 :1; /*!< [16:16] 使能Master TAG ID 16 的事务对模块内核地址的写访问 */
            __IO uint32_t EN17 :1; /*!< [17:17] 使能Master TAG ID 17 的事务对模块内核地址的写访问 */
            __IO uint32_t EN18 :1; /*!< [18:18] 使能Master TAG ID 18 的事务对模块内核地址的写访问 */
            __IO uint32_t EN19 :1; /*!< [19:19] 使能Master TAG ID 19 的事务对模块内核地址的写访问 */
            __IO uint32_t EN20 :1; /*!< [20:20] 使能Master TAG ID 20 的事务对模块内核地址的写访问 */
            __IO uint32_t EN21 :1; /*!< [21:21] 使能Master TAG ID 21 的事务对模块内核地址的写访问 */
            __IO uint32_t EN22 :1; /*!< [22:22] 使能Master TAG ID 22 的事务对模块内核地址的写访问 */
            __IO uint32_t EN23 :1; /*!< [23:23] 使能Master TAG ID 23 的事务对模块内核地址的写访问 */
            __IO uint32_t EN24 :1; /*!< [24:24] 使能Master TAG ID 24 的事务对模块内核地址的写访问 */
            __IO uint32_t EN25 :1; /*!< [25:25] 使能Master TAG ID 25 的事务对模块内核地址的写访问 */
            __IO uint32_t EN26 :1; /*!< [26:26] 使能Master TAG ID 26 的事务对模块内核地址的写访问 */
            __IO uint32_t EN27 :1; /*!< [27:27] 使能Master TAG ID 27 的事务对模块内核地址的写访问 */
            __IO uint32_t EN28 :1; /*!< [28:28] 使能Master TAG ID 28 的事务对模块内核地址的写访问 */
            __IO uint32_t EN29 :1; /*!< [29:29] 使能Master TAG ID 29 的事务对模块内核地址的写访问 */
            __IO uint32_t EN30 :1; /*!< [30:30] 使能Master TAG ID 30 的事务对模块内核地址的写访问 */
            __IO uint32_t EN31 :1; /*!< [31:31] 使能Master TAG ID 31 的事务对模块内核地址的写访问 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN32 :1; /*!< [0:0] 使能Master TAG ID 32 的事务对模块内核地址的写访问 */
            __IO uint32_t EN33 :1; /*!< [1:1] 使能Master TAG ID 33 的事务对模块内核地址的写访问 */
            __IO uint32_t EN34 :1; /*!< [2:2] 使能Master TAG ID 34 的事务对模块内核地址的写访问 */
            __IO uint32_t EN35 :1; /*!< [3:3] 使能Master TAG ID 35 的事务对模块内核地址的写访问 */
            __IO uint32_t EN36 :1; /*!< [4:4] 使能Master TAG ID 36 的事务对模块内核地址的写访问 */
            __IO uint32_t EN37 :1; /*!< [5:5] 使能Master TAG ID 37 的事务对模块内核地址的写访问 */
            __IO uint32_t EN38 :1; /*!< [6:6] 使能Master TAG ID 38 的事务对模块内核地址的写访问 */
            __IO uint32_t EN39 :1; /*!< [7:7] 使能Master TAG ID 39 的事务对模块内核地址的写访问 */
            __IO uint32_t EN40 :1; /*!< [8:8] 使能Master TAG ID 40 的事务对模块内核地址的写访问 */
            __IO uint32_t EN41 :1; /*!< [9:9] 使能Master TAG ID 41 的事务对模块内核地址的写访问 */
            __IO uint32_t EN42 :1; /*!< [10:10] 使能Master TAG ID 42 的事务对模块内核地址的写访问 */
            __IO uint32_t EN43 :1; /*!< [11:11] 使能Master TAG ID 43 的事务对模块内核地址的写访问 */
            __IO uint32_t EN44 :1; /*!< [12:12] 使能Master TAG ID 44 的事务对模块内核地址的写访问 */
            __IO uint32_t EN45 :1; /*!< [13:13] 使能Master TAG ID 45 的事务对模块内核地址的写访问 */
            __IO uint32_t EN46 :1; /*!< [14:14] 使能Master TAG ID 46 的事务对模块内核地址的写访问 */
            __IO uint32_t EN47 :1; /*!< [15:15] 使能Master TAG ID 47 的事务对模块内核地址的写访问 */
            __IO uint32_t EN48 :1; /*!< [16:16] 使能Master TAG ID 48 的事务对模块内核地址的写访问 */
            __IO uint32_t EN49 :1; /*!< [17:17] 使能Master TAG ID 49 的事务对模块内核地址的写访问 */
            __IO uint32_t EN50 :1; /*!< [18:18] 使能Master TAG ID 50 的事务对模块内核地址的写访问 */
            __IO uint32_t EN51 :1; /*!< [19:19] 使能Master TAG ID 51 的事务对模块内核地址的写访问 */
            __IO uint32_t EN52 :1; /*!< [20:20] 使能Master TAG ID 52 的事务对模块内核地址的写访问 */
            __IO uint32_t EN53 :1; /*!< [21:21] 使能Master TAG ID 53 的事务对模块内核地址的写访问 */
            __IO uint32_t EN54 :1; /*!< [22:22] 使能Master TAG ID 54 的事务对模块内核地址的写访问 */
            __IO uint32_t EN55 :1; /*!< [23:23] 使能Master TAG ID 55 的事务对模块内核地址的写访问 */
            __IO uint32_t EN56 :1; /*!< [24:24] 使能Master TAG ID 56 的事务对模块内核地址的写访问 */
            __IO uint32_t EN57 :1; /*!< [25:25] 使能Master TAG ID 57 的事务对模块内核地址的写访问 */
            __IO uint32_t EN58 :1; /*!< [26:26] 使能Master TAG ID 58 的事务对模块内核地址的写访问 */
            __IO uint32_t EN59 :1; /*!< [27:27] 使能Master TAG ID 59 的事务对模块内核地址的写访问 */
            __IO uint32_t EN60 :1; /*!< [28:28] 使能Master TAG ID 60 的事务对模块内核地址的写访问 */
            __IO uint32_t EN61 :1; /*!< [29:29] 使能Master TAG ID 61 的事务对模块内核地址的写访问 */
            __IO uint32_t EN62 :1; /*!< [30:30] 使能Master TAG ID 62 的事务对模块内核地址的写访问 */
            __IO uint32_t EN63 :1; /*!< [31:31] 使能Master TAG ID 63 的事务对模块内核地址的写访问 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN        :1; /*!< [0:0] 定时器启动控制位 */
            __IO uint32_t CMS       :3; /*!< [3:1] 计数方式选择位 */
            __IO uint32_t CLKSMUX   :3; /*!< [6:4] 计数源选择，选择的计数源会与时钟源同步 */
            __IO uint32_t SPM       :1; /*!< [7:7] 单脉冲输出模式 */
            __IO uint32_t SPMST     :1; /*!< [8:8] 单脉冲输出模式选择 */
            __IO uint32_t MSSYNC    :1; /*!< [9:9] 主从模式同步位 */
            __IO uint32_t SY        :1; /*!< [10:10] 计数时钟同步位 */
            __I uint32_t  RESERVED0 :1;
            __IO uint32_t SMS       :3; /*!< [14:12] 从模式选择位 */
            __I uint32_t  RESERVED1 :1;
            __IO uint32_t TRGIS     :5; /*!< [20:16] TRGO TRGI 触发输入选择位 */
            __I uint32_t  RESERVED2 :3;
            __IO uint32_t TRGOS     :4; /*!< [27:24] TRGO 触发输出选择位 */
            __I uint32_t  RESERVED3 :4;
        } bits;
        __IO uint32_t reg;
    };
} BPT_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TXUDEN  :1; /*!< [0:0] 更新使能位 */
            __IO uint32_t TXUDEVT :1; /*!< [1:1] 更新事件控制位 */
            __O uint32_t TXUR :1; /*!< [2:2] 更新事件生成位（该位硬件自动清零，此位不受TXUDEN 控制） */
            __I uint32_t RESERVED0 :29;
        } bits;
        __IO uint32_t reg;
    };
} BPT_CTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CNT :32; /*!< [31:0] 32 位计数寄存器 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_CNT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CKS :32; /*!< [31:0] 32 位预分频值 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_PRSC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PPX :32; /*!< [31:0] 系统定时器[31:0]位 */
        } bits;
        __IO uint32_t reg;
    };
} BPT_PPX_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t UDCNT     :8; /*!< [7:0] 更新计数值 */
            __I uint32_t  RESERVED0 :24;
        } bits;
        __IO uint32_t reg;
    };
} BPT_UDTIM_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t DIR       :1; /*!< [0:0] 当前计数方向状态位 */
            __I uint32_t RESERVED0 :31;
        } bits;
        __I uint32_t reg;
    };
} BPT_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t TOIF      :1; /*!< [0:0] 溢出事件中断标志 */
            __I uint32_t RESERVED0 :4;
            __I uint32_t TRGIF     :1; /*!< [5:5] 触发事件中断标志 */
            __I uint32_t UEIF      :1; /*!< [6:6] 更新事件中断标志 */
            __I uint32_t RESERVED1 :25;
        } bits;
        __I uint32_t reg;
    };
} BPT_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TOIE      :1; /*!< [0:0] 溢出事件中断使能位 */
            __I uint32_t  RESERVED0 :4;
            __IO uint32_t TRGIE     :1; /*!< [5:5] 触发事件中断使能位 */
            __IO uint32_t UEIE      :1; /*!< [6:6] 更新事件中断使能位 */
            __I uint32_t  RESERVED1 :25;
        } bits;
        __IO uint32_t reg;
    };
} BPT_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t TOIC      :1; /*!< [0:0] 溢出事件中断标志清零位 */
            __I uint32_t RESERVED0 :4;
            __O uint32_t TRGIC     :1; /*!< [5:5] 触发事件中断标志清零位 */
            __O uint32_t UEIC      :1; /*!< [6:6] 更新事件中断标志清零位 */
            __I uint32_t RESERVED1 :25;
        } bits;
        __IO uint32_t reg;
    };
} BPT_IC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t TOIS      :1; /*!< [0:0] 溢出事件中断标志置1位 */
            __I uint32_t RESERVED0 :4;
            __O uint32_t TRGIS     :1; /*!< [5:5] 触发事件中断标志置1位 */
            __O uint32_t UEIS      :1; /*!< [6:6] 更新事件中断标志置1位 */
            __I uint32_t RESERVED1 :25;
        } bits;
        __IO uint32_t reg;
    };
} BPT_IS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TMEN      :1; /*!< [0:0] 测试模式使能 */
            __IO uint32_t TMSEL     :2; /*!< [2:1] testpin输出选择 */
            __I uint32_t  RESERVED1 :29;
        } bits;
        __IO uint32_t reg;
    };
} BPT_TM_T;

typedef volatile struct
{
    /* offset  : 0x0000.    BPT 时钟控制寄存器. */
    BPT_CLKC_T BPT_CLKC;

    /* offset  : 0x0004.    BPT 模块信息寄存器. */
    BPT_INFO_T BPT_INFO;

    /* offset  : 0x0008.    BPT 调试寄存器. */
    BPT_DBG_T BPT_DBG;

    /* offset  : 0x000C.    BPT 复位寄存器0. */
    BPT_RST0_T BPT_RST0;

    /* offset  : 0x0010.    BPT 复位寄存器1. */
    BPT_RST1_T BPT_RST1;

    /* offset  : 0x0014.    BPT 复位状态清零寄存器. */
    BPT_RSTCLR_T BPT_RSTCLR;

    /* offset  : 0x0018.    BPT 访问控制使能寄存器. */
    BPT_ACES0_T BPT_ACES0;

    /* offset  : 0x001C.    BPT 访问控制使能寄存器. */
    BPT_ACES1_T BPT_ACES1;

    /* offset  : 0x0020.    BPT 控制寄存器1. */
    BPT_CTL1_T BPT_CTL1;

    /* offset  : 0x0024.    BPT 控制寄存器2. */
    BPT_CTL2_T BPT_CTL2;

    /* offset  : 0x0028.    BPT 计数寄存器. */
    BPT_CNT_T BPT_CNT;

    /* offset  : 0x002C.    BPT 预分频寄存器. */
    BPT_PRSC_T BPT_PRSC;

    /* offset  : 0x0030.    BPT 周期寄存器. */
    BPT_PPX_T BPT_PPX;

    /* offset  : 0x0034.    BPT 更新计数寄存器. */
    BPT_UDTIM_T BPT_UDTIM;

    /* offset  : 0x0038.    BPT 状态寄存器. */
    BPT_STA_T BPT_STA;

    /* offset  : 0x003C.    BPT 中断标志寄存器. */
    BPT_IF_T BPT_IF;

    /* offset  : 0x0040.    BPT 中断使能寄存器. */
    BPT_IE_T BPT_IE;

    /* offset  : 0x0044.    BPT 中断清零寄存器. */
    BPT_IC_T BPT_IC;

    /* offset  : 0x0048.    BPT 中断置位寄存器. */
    BPT_IS_T BPT_IS;

    /* offset  : 0x004C.    BPT 测试模式寄存器. */
    BPT_TM_T BPT_TM;
} BPT_RegisterMap_t;

#define BPT0_ADDR ((uint32_t)0xF0020400U)
#define BPT1_ADDR ((uint32_t)0xF0020500U)
#define BPT2_ADDR ((uint32_t)0xF0020600U)
#define BPT3_ADDR ((uint32_t)0xF0020700U)
#define BPT0_PTR  ((BPT_RegisterMap_t *)BPT0_ADDR)
#define BPT1_PTR  ((BPT_RegisterMap_t *)BPT1_ADDR)
#define BPT2_PTR  ((BPT_RegisterMap_t *)BPT2_ADDR)
#define BPT3_PTR  ((BPT_RegisterMap_t *)BPT3_ADDR)
#define BPT0_RM   (*(BPT_RegisterMap_t *)BPT0_ADDR)
#define BPT1_RM   (*(BPT_RegisterMap_t *)BPT1_ADDR)
#define BPT2_RM   (*(BPT_RegisterMap_t *)BPT2_ADDR)
#define BPT3_RM   (*(BPT_RegisterMap_t *)BPT3_ADDR)

/**
 * @brief 检查所有BPT外设
 *
 */
#define CHECK_BPT_ALL_PERIPH(MODULE)                                                                                   \
    ((MODULE == BPT0_PTR) || (MODULE == BPT1_PTR) || (MODULE == BPT2_PTR) || (MODULE == BPT3_PTR))

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
