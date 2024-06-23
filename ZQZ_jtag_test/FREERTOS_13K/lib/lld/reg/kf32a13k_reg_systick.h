/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_systick.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-07
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
 *  |2023-12-07    |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/
#ifndef KF32A13K_REG_SYSTICK_H_
#define KF32A13K_REG_SYSTICK_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf_types.h"
#include <stdint.h>

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
} SYSTICK_CLKC_T;

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
        __I uint32_t reg;
    };
} SYSTICK_INFO_T;

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
} SYSTICK_DBG_T;

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
} SYSTICK_RST0_T;

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
} SYSTICK_RST1_T;

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
} SYSTICK_RSTCLR_T;

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
} SYSTICK_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留，读为0 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t STB31B0 :32; /*!< [31:0] 系统定时器[31:0]位 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_TIM0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t STB35B4 :32; /*!< [31:0] 系统定时器[35:4]位 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_TIM1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t STB39B8 :32; /*!< [31:0] 系统定时器[39:8]位 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_TIM2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t STB43B12 :32; /*!< [31:0] 系统定时器[43:12]位 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_TIM3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t STB47B16 :32; /*!< [31:0] 系统定时器[47:16]位 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_TIM4_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t STB51B20 :32; /*!< [31:0] 系统定时器[51:20]位 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_TIM5_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t STB63B32 :32; /*!< [31:0] 系统定时器[63:32]位 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_TIM6_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t STCAPB63B32 :32; /*!< [31:0] 捕获系统定时器[63:32]位 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_CAP_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CMPVAL :32; /*!< [31:0] 比较寄存器的比较值 */
        } bits;
        __IO uint32_t reg;
    };
} SYSTICK_CMP_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t MSIZE0    :5; /*!< [4:0] ST_CMP0 的比较范围 */
            __I uint32_t  RESERVED0 :3; /*!< [7:5] 预留，读为0 */
            __IO uint32_t MSTART0   :5; /*!< [12:8] ST_CMP0 的起始比较位 */
            __I uint32_t  RESERVED1 :3; /*!< [15:13] 预留，读为0 */
            __IO uint32_t MSIZE1    :5; /*!< [20:16] ST_CMP1 的比较范围 */
            __I uint32_t  RESERVED2 :3; /*!< [23:21] 预留，读为0 */
            __IO uint32_t MSTART1   :5; /*!< [28:24] ST_CMP1 的起始比较位 */
            __I uint32_t  RESERVED3 :3; /*!< [31:29] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} SYSTICK_CMPCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CMP0IE      :1;  /*!< [0:0] 比较寄存器 ST_CMP0 中断使能控制 */
            __I uint32_t  CMP0IF      :1;  /*!< [1:1] 比较寄存器 ST_CMP0 中断请求标志位 */
            __IO uint32_t CMP0IFSEL   :1;  /*!< [2:2] 比较寄存器 ST_CMP0 中断输出选择 */
            __I uint32_t  RESERVED0   :1;  /*!< [3:3] 预留，读为0 */
            __IO uint32_t CMP1IE      :1;  /*!< [4:4] 比较寄存器 ST_CMP1 中断使能控制 */
            __I uint32_t  CMP1IF      :1;  /*!< [5:5] 比较寄存器 ST_CMP1 中断请求标志位 */
            __IO uint32_t CMP1IFSEL   :1;  /*!< [6:6] 比较寄存器 ST_CMP1 中断输出选择 */
            __I uint32_t  RESERVED1   :1;  /*!< [7:7] 预留，读为0 */
            __IO uint32_t OVERFLOWEN  :1;  /*!< [8:8] 溢出中断使能位 */
            __I uint32_t  OVERFLOWIF  :1;  /*!< [9:9] 定时器计数到重载值时溢出标志位 */
            __I uint32_t  RESERVED2   :1;  /*!< [10:10] 预留，读为0 */
            __IO uint32_t ERROREN     :1;  /*!< [11:11] 错误中断使能位 */
            __I uint32_t  CAPERROR    :1;  /*!< [12:12] 比较CAP与CAPSV捕获是否错误 */
            __I uint32_t  TIM0ERROR   :1;  /*!< [13:13] 比较TIM0与TIM0SV读取是否错误 */
            __I uint32_t  RESERVED3   :16; /*!< [29:14] 预留，读为0 */
            __IO uint32_t ERRORMOD    :1;  /*!< [30:30] 读错误判断功能使能位 */
            __IO uint32_t OVERFLOWMOD :1;  /*!< [31:31] 使能定时器是否计数到重载值时重载 */
        } bits;
        __IO uint32_t reg;
    };
} SYSTICK_ICR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CMP0IC     :1;  /*!< [0:0] 清零比较寄存器 ST_CMP0 中断标志位 */
            __O uint32_t CMP0IS     :1;  /*!< [1:1] 置位比较寄存器 ST_CMP0 中断标志位 */
            __O uint32_t CMP1IC     :1;  /*!< [2:2] 清零比较寄存器 ST_CMP1 中断标志位 */
            __O uint32_t CMP1IS     :1;  /*!< [3:3] 置位比较寄存器 ST_CMP1 中断标志位 */
            __O uint32_t OVERFLOWIC :1;  /*!< [4:4] 置位比较寄存器 ST_CMP1 中断标志位 */
            __O uint32_t OVERFLOWIS :1;  /*!< [5:5] 置位比较寄存器 ST_CMP1 中断标志位 */
            __O uint32_t CAPERRIC   :1;  /*!< [6:6] 置位比较寄存器 ST_CMP1 中断标志位 */
            __O uint32_t CAPERRIS   :1;  /*!< [7:7] 置位比较寄存器 ST_CMP1 中断标志位 */
            __O uint32_t TIM0ERRIC  :1;  /*!< [8:8] 置位比较寄存器 ST_CMP1 中断标志位 */
            __O uint32_t TIM0ERRIS  :1;  /*!< [9:9] 置位比较寄存器 ST_CMP1 中断标志位 */
            __I uint32_t RESERVED0  :22; /*!< [31:10] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} SYSTICK_ISCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t STB31B0 :32; /*!< [31:0] 系统定时器[31:0]位 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_TIM0SV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t STCAPB63B32 :32; /*!< [31:0] 捕获定时器[63:32]位 */
        } bits;
        __I uint32_t reg;
    };
} SYSTICK_CAPSV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OVERFLOWVAL_H :32; /*!< [31:0] 定时器高位溢出重载值 */
        } bits;
        __IO uint32_t reg;
    };
} SYSTICK_OVH_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OVERFLOWVAL_L :32; /*!< [31:0] 定时器低位溢出重载值 */
        } bits;
        __IO uint32_t reg;
    };
} SYSTICK_OVL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TESTEN    :1;  /*!< [0:0] 备份寄存器测试模式使能位 */
            __O uint32_t  TESTC     :1;  /*!< [1:1] 测试标志清除位 */
            __I uint32_t  RESERVED0 :14; /*!< [15:2] 预留，读为0 */
            __I uint32_t  TESTOK    :1;  /*!< [16:16] 测试成功标志位 */
            __I uint32_t  TESTNG    :1;  /*!< [17:17] 测试失败标志位 */
            __I uint32_t  RESERVED1 :14; /*!< [ 18:31] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} SYSTICK_TEST_T;

typedef volatile struct
{
    /* offset  : 0x0000.    SYSTICK 时钟控制寄存器. */
    SYSTICK_CLKC_T SYSTICK_CLKC;

    /* offset  : 0x0004.    SYSTICK 模块信息寄存器. */
    SYSTICK_INFO_T SYSTICK_INFO;

    /* offset  : 0x0008.    SYSTICK 调试寄存器. */
    SYSTICK_DBG_T SYSTICK_DBG;

    /* offset  : 0x000C.    SYSTICK 复位寄存器0. */
    SYSTICK_RST0_T SYSTICK_RST0;

    /* offset  : 0x0010.    SYSTICK 复位寄存器1. */
    SYSTICK_RST1_T SYSTICK_RST1;

    /* offset  : 0x0014.    SYSTICK 复位状态清零寄存器. */
    SYSTICK_RSTCLR_T SYSTICK_RSTCLR;

    /* offset  : 0x0018.    SYSTICK 访问控制使能寄存器. */
    SYSTICK_ACES0_T SYSTICK_ACES0;

    /* offset  : 0x001C.    SYSTICK 访问控制使能寄存器. */
    SYSTICK_ACES1_T SYSTICK_ACES1;

    /* offset  : 0x0020.    SYSTICK 定时器寄存器0. */
    SYSTICK_TIM0_T SYSTICK_TIM0;

    /* offset  : 0x0024.    SYSTICK 定时器寄存器1. */
    SYSTICK_TIM1_T SYSTICK_TIM1;

    /* offset  : 0x0028.    SYSTICK 定时器寄存器2. */
    SYSTICK_TIM2_T SYSTICK_TIM2;

    /* offset  : 0x002C.    SYSTICK 定时器寄存器3. */
    SYSTICK_TIM3_T SYSTICK_TIM3;

    /* offset  : 0x0030.    SYSTICK 定时器寄存器4. */
    SYSTICK_TIM4_T SYSTICK_TIM4;

    /* offset  : 0x0034.    SYSTICK 定时器寄存器5. */
    SYSTICK_TIM5_T SYSTICK_TIM5;

    /* offset  : 0x0038.    SYSTICK 定时器寄存器6. */
    SYSTICK_TIM6_T SYSTICK_TIM6;

    /* offset  : 0x003C.    SYSTICK 捕捉寄存器. */
    SYSTICK_CAP_T SYSTICK_CAP;

    /* offset  : 0x0040.    SYSTICK 比较寄存器. */
    SYSTICK_CMP_T SYSTICK_CMP[2];

    /* offset  : 0x0048.    SYSTICK 比较匹配控制寄存器. */
    SYSTICK_CMPCTL_T SYSTICK_CMPCTL;

    /* offset  : 0x004C.    SYSTICK 中断控制寄存器. */
    SYSTICK_ICR_T SYSTICK_ICR;

    /* offset  : 0x0050.    SYSTICK 中断置位/清零寄存器. */
    SYSTICK_ISCR_T SYSTICK_ISCR;

    /* offset  : 0x0054.    SYSTICK 定时器寄存器 0 备份. */
    SYSTICK_TIM0SV_T SYSTICK_TIM0SV;

    /* offset  : 0x0058.    SYSTICK 捕获寄存器备份. */
    SYSTICK_CAPSV_T SYSTICK_CAPSV;

    /* offset  : 0x005C.    SYSTICK 定时器高位溢出寄存器. */
    SYSTICK_OVH_T SYSTICK_OVH;

    /* offset  : 0x0060.    SYSTICK 定时器低位溢出寄存器. */
    SYSTICK_OVL_T SYSTICK_OVL;

    /* offset  : 0x0064.    SYSTICK 测试寄存. */
    SYSTICK_TEST_T SYSTICK_TEST;
} Systick_RegisterMap_t;

#define SYSTICK0_ADDR ((uint32_t)0xF0000100U)
#define SYSTICK0_PTR  ((Systick_RegisterMap_t *)SYSTICK0_ADDR)
#define SYSTICK0_RM   (*(Systick_RegisterMap_t *)SYSTICK0_ADDR)
#define SYSTICK1_ADDR ((uint32_t)0xF0000200U)
#define SYSTICK1_PTR  ((Systick_RegisterMap_t *)SYSTICK1_ADDR)
#define SYSTICK1_RM   (*(Systick_RegisterMap_t *)SYSTICK1_ADDR)
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
