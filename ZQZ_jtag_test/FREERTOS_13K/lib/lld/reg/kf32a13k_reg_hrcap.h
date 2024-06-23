/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_hrcap.h
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
 *                              REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2023-12-28  |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_REG_HRCAP_H_
#define _KF32DA13K_REG_HRCAP_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *         Include Files
 **************************************************************************/
#include "kf_types.h"
#include <stdint.h>

/**************************************************************************
 *         Mcro ro typedef
 **************************************************************************/
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DISR     :1;  /*!< [0:0] 模块禁止状态  */
            __I uint32_t  DISS     :1;  /*!< [1:1] 模块禁止请求位  */
            __IO uint32_t EDIS     :1;  /*!< [2:2] 休眠模式使能控制位  */
            __IO uint32_t RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] HRCAP模块版本号  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] HRCAP模块类型  */
            __I uint32_t MODNUM  :16; /*!< [31:16] HRCAP模块编号  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0  :24; /*!< [23:0] 预留读为0  */
            __IO uint32_t SUS       :4;  /*!< [27:24] 调试模式挂起控制  */
            __O uint32_t  SUSP      :1;  /*!< [28:28] SUS位写保护，读出为0  */
            __I uint32_t  SUSSTA    :1;  /*!< [29:29] 挂起状态位  */
            __IO uint32_t RESERVED1 :2;  /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST    :1; /*!< [0:0] 模块复位请求位，与HRCAP_RST1寄存器的RST位一起使用  */
            __I uint32_t  RSTSTA :1; /*!< [1:1] 复位状态  */
            __IO uint32_t RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST :1; /*!< [0:0] 模块复位请求位，与HRCAP_RST0寄存器的RST位一起使用  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  CLR      :1;  /*!< [0:0] 复位状态清除位，读出为0  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_RSTCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN0  :1; /*!< [0:0] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN1  :1; /*!< [1:1] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN2  :1; /*!< [2:2] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN3  :1; /*!< [3:3] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN4  :1; /*!< [4:4] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN5  :1; /*!< [5:5] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN6  :1; /*!< [6:6] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN7  :1; /*!< [7:7] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN8  :1; /*!< [8:8] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN9  :1; /*!< [9:9] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN10 :1; /*!< [10:10] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN11 :1; /*!< [11:11] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN12 :1; /*!< [12:12] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN13 :1; /*!< [13:13] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN14 :1; /*!< [14:14] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN15 :1; /*!< [15:15] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN16 :1; /*!< [16:16] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN17 :1; /*!< [17:17] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN18 :1; /*!< [18:18] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN19 :1; /*!< [19:19] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN20 :1; /*!< [20:20] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN21 :1; /*!< [21:21] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN22 :1; /*!< [22:22] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN23 :1; /*!< [23:23] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN24 :1; /*!< [24:24] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN25 :1; /*!< [25:25] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN26 :1; /*!< [26:26] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN27 :1; /*!< [27:27] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN28 :1; /*!< [28:28] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN29 :1; /*!< [29:29] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN30 :1; /*!< [30:30] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN31 :1; /*!< [31:31] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :32; /*!< [31:0] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN       :1;  /*!< [0:0] 模块使能位  */
            __IO uint32_t CAPINSEL :1;  /*!< [1:1] 捕捉输入选择位  */
            __IO uint32_t SWRST    :1;  /*!< [2:2] 模块软件复位使能位  */
            __IO uint32_t CLKSEL   :1;  /*!< [3:3] HRCAP时钟源选择  */
            __IO uint32_t RESERVED0 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_CTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t COUNTER   :16; /*!< [15:0] 16位HRCAP计数器 */
            __I uint32_t COUNTERSR :16; /*!< [31:16] 16位经过锁存后的HRCAP计数器  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_CNT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RISE     :16; /*!< [15:0] 16位上升沿整数捕捉寄存器 */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_RISE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  FALL     :16; /*!< [15:0] 16位下降沿整数捕捉寄存器  */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_FALL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  HRRISE   :16; /*!< [15:0] 16位上升沿小数捕捉寄存器  */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_HRRISE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  HRFALL   :16; /*!< [15:0]  16位下降沿小数捕捉寄存器 */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_HRFALL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RISEIF   :1;  /*!< [0:0] 上升沿捕捉溢出中断标志位  */
            __I uint32_t  FALLIF   :1;  /*!< [1:1] 上升沿捕捉溢出中断标志位  */
            __I uint32_t  TOIF     :1;  /*!< [2:2] 上升沿捕捉溢出中断标志位  */
            __I uint32_t  RISEOIF  :1;  /*!< [3:3] 上升沿捕捉溢出中断标志位  */
            __IO uint32_t RESERVED0 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RISEIE   :1;  /*!< [0:0] 上升沿捕捉中断使能  */
            __IO uint32_t FALLIE   :1;  /*!< [1:1] 下降沿捕捉中断使能位  */
            __IO uint32_t TOIE     :1;  /*!< [2:2] 计数溢出中断使能位  */
            __IO uint32_t RISEOIE  :1;  /*!< [3:3] 上升沿捕捉溢出中断使能位  */
            __IO uint32_t RESERVED0 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  RISEIC   :1;  /*!< [0:0] 上升沿捕捉中断标志清零位  */
            __O uint32_t  FALLIC   :1;  /*!< [1:1] 下降沿捕捉中断标志清零位  */
            __O uint32_t  TOIC     :1;  /*!< [2:2] 计数溢出中断标志清零位  */
            __O uint32_t  RISEOIC  :1;  /*!< [3:3] 上升沿捕捉溢出中断标志清零位  */
            __IO uint32_t RESERVED0 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_IC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  RISEIS   :1;  /*!< [0:0] 上升沿捕捉中断标志位置一位  */
            __O uint32_t  FALLIS   :1;  /*!< [1:1] 下降沿捕捉中断标志位置一位  */
            __O uint32_t  TOIS     :1;  /*!< [2:2] 计数溢出中断标志位置一位  */
            __O uint32_t  RISEOIS  :1;  /*!< [3:3] 上升沿捕捉溢出中断标志置一位  */
            __IO uint32_t RESERVED0 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} HRCAP_IS_T;

typedef volatile struct
{
    /* offset: 0x0000 */
    HRCAP_CLKC_T HRCAP_CLKC;

    /* offset: 0x0004 */
    HRCAP_INFO_T HRCAP_INFO;

    /* offset: 0x0008 */
    HRCAP_DBG_T HRCAP_DBG;

    /* offset: 0x000C */
    HRCAP_RST0_T HRCAP_RST0;

    /* offset: 0x0010 */
    HRCAP_RST1_T HRCAP_RST1;

    /* offset: 0x0014 */
    HRCAP_RSTCLR_T HRCAP_RSTCLR;

    /* offset: 0x0018 */
    HRCAP_ACES0_T HRCAP_ACES0;

    /* offset: 0x001C */
    HRCAP_ACES1_T HRCAP_ACES1;

    /* offset: 0x0020 */
    HRCAP_CTL_T HRCAP_CTL;

    /* offset: 0x0024 */
    HRCAP_CNT_T HRCAP_CNT;

    /* offset: 0x0028 */
    HRCAP_RISE_T HRCAP_RISE[2];

    /* offset: 0x0030 */
    HRCAP_FALL_T HRCAP_FALL[2];

    /* offset: 0x0038 */
    HRCAP_HRRISE_T HRCAP_HRRISE[2];

    /* offset: 0x0040 */
    HRCAP_HRFALL_T HRCAP_HRFALL[2];

    /* offset: 0x0048 */
    HRCAP_IF_T HRCAP_IF;

    /* offset: 0x004C */
    HRCAP_IE_T HRCAP_IE;

    /* offset: 0x0050 */
    HRCAP_IC_T HRCAP_IC;

    /* offset: 0x0054 */
    HRCAP_IS_T HRCAP_IS;
} Hrcap_RegisterMap_t;

#define HRCAP0_ADDR ((uint32_t)0xF0023400)
#define HRCAP0_PTR  ((Hrcap_RegisterMap_t *)HRCAP0_ADDR)
#define HRCAP0_RM   (*(Hrcap_RegisterMap_t *)HRCAP0_ADDR)

#define HRCAP1_ADDR ((uint32_t)0xF0023500)
#define HRCAP1_PTR  ((Hrcap_RegisterMap_t *)HRCAP1_ADDR)
#define HRCAP1_RM   (*(Hrcap_RegisterMap_t *)HRCAP1_ADDR)

#define HRCAP2_ADDR ((uint32_t)0xF0023600)
#define HRCAP2_PTR  ((Hrcap_RegisterMap_t *)HRCAP2_ADDR)
#define HRCAP2_RM   (*(Hrcap_RegisterMap_t *)HRCAP2_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
