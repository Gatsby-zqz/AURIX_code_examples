/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_qei.h
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
 *  |2023-12-27  |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_REG_QEI_H_
#define _KF32DA13K_REG_QEI_H_

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
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁止状态  */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁止请求位  */
            __IO uint32_t EDIS      :1;  /*!< [2:2] 休眠模式使能控制位  */
            __I uint32_t  RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] QEI模块版本号  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] QEI模块类型  */
            __I uint32_t MODNUM  :16; /*!< [31:16] QEI模块编号  */
        } bits;
        __I uint32_t reg;
    };
} QEI_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :24; /*!< [23:0] 预留读为0  */
            __IO uint32_t SUS       :4;  /*!< [27:24] 调试模式挂起控制  */
            __O uint32_t  SUSP      :1;  /*!< [28:28] SUS位写保护，读出为0  */
            __I uint32_t  SUSSTA    :1;  /*!< [29:29] 挂起状态位  */
            __I uint32_t  RESERVED1 :2;  /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1; /*!< [0:0] 模块复位请求位，与QEI_RST1寄存器的RST位一起使用  */
            __I uint32_t  RSTSTA    :1; /*!< [1:1] 复位状态  */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1; /*!< [0:0] 模块复位请求位，与QEI_RST0寄存器的RST位一起使用  */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CLR       :1;  /*!< [0:0] 复位状态清除位，读出为0  */
            __I uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_RSTCLR_T;

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
} QEI_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留读为0  */
        } bits;
        __I uint32_t reg;
    };
} QEI_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN        :1; /*!< [0:0] QEI模块使能位  */
            __IO uint32_t DIROUT    :1; /*!< [1:1] 计数方向DIR输出使能位  */
            __IO uint32_t INDRES    :1; /*!< [2:2] 位置计数器复位使能位  */
            __I uint32_t  RESERVED0 :1; /*!< [3:3] 预留读为0  */
            __IO uint32_t QEIMOD    :3; /*!< [6:4] QEI模式选择位  */
            __IO uint32_t QEICLK    :2; /*!< [8:7] QEI工作时钟选择位  */
            __IO uint32_t LPCLK :1; /*!< [9:9] 低功耗QEI工作时钟选择位(仅限于QEI0当QEICLK<1:0>=11时使用)  */
            __I uint32_t RESERVED1 :22; /*!< [31:10] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_CTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SWPAB     :1;  /*!< [0:0] A相和B相输入交换选择位  */
            __IO uint32_t FLTEN     :1;  /*!< [1:1] A/B/INDEX的数字滤波器使能位  */
            __I uint32_t  RESERVED0 :2;  /*!< [3:2] 预留读为0  */
            __IO uint32_t FLTCK     :3;  /*!< [6:4] A/B/INDEX的数字滤波器时钟分频选择位  */
            __IO uint32_t PHDFEN    :1;  /*!< [7:7] 相位检测滤波使能位  */
            __IO uint32_t PHFSEL    :10; /*!< [17:8] 相位检测滤波选择位  */
            __I uint32_t  RESERVED1 :14; /*!< [31:18] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_FLTCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CNT :16; /*!< [15:0] 16位QEI计数器写入该寄存器的值会作为初值在开始计数时载入计数器中  */
            __I uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_CNT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PPX       :16; /*!< [15:0] 16位QEI周期值  */
            __I uint32_t  RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_PPX_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PRSC      :16; /*!< [15:0] 16位QEI预分频值  */
            __I uint32_t  RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_PRSC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t DIR       :1;  /*!< [0:0] 位置计数器方向状态位  */
            __I uint32_t INDEX     :1;  /*!< [1:1] 索引引脚INDEX状态位  */
            __I uint32_t RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __I uint32_t reg;
    };
} QEI_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t TOIF  :1; /*!< [0:0] 计数器溢出中断标志位  */
            __I uint32_t PHEIF :1; /*!< [1:1] 相位错误中断标志位  */
            __I uint32_t CNTERRIF :1; /*!< [2:2] 计数错误中断标志位仅当QEIMOD<2:0>选择110b或者100b时，才能使用该位。  */
            __I uint32_t RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __I uint32_t reg;
    };
} QEI_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TOIE      :1;  /*!< [0:0] 计数器溢出中断使能位  */
            __IO uint32_t PHEIE     :1;  /*!< [1:1] 相位错误中断使能位  */
            __IO uint32_t CNTERRIE  :1;  /*!< [2:2] 计数错误中断使能位  */
            __I uint32_t  RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t TOIC      :1;  /*!< [0:0] 计数器溢出中断清零位  */
            __O uint32_t PHEIC     :1;  /*!< [1:1] 相位错误中断清零位  */
            __O uint32_t CNTERRIC  :1;  /*!< [2:2] 计数错误中断清零位  */
            __I uint32_t RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_IC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t TOIS      :1;  /*!< [0:0] 计数器溢出中断置一位  */
            __O uint32_t PHEIS     :1;  /*!< [1:1] 相位错误中断置一位  */
            __O uint32_t CNTERRIS  :1;  /*!< [2:2] 计数错误中断置一位  */
            __I uint32_t RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} QEI_IS_T;

typedef volatile struct
{
    /* offset: 0x0000 */
    QEI_CLKC_T QEI_CLKC;

    /* offset: 0x0004 */
    QEI_INFO_T QEI_INFO;

    /* offset: 0x0008 */
    QEI_DBG_T QEI_DBG;

    /* offset: 0x000C */
    QEI_RST0_T QEI_RST0;

    /* offset: 0x0010 */
    QEI_RST1_T QEI_RST1;

    /* offset: 0x0014 */
    QEI_RSTCLR_T QEI_RSTCLR;

    /* offset: 0x0018 */
    QEI_ACES0_T QEI_ACES0;

    /* offset: 0x001C */
    QEI_ACES1_T QEI_ACES1;

    /* offset: 0x0020 */
    QEI_CTL_T QEI_CTL;

    /* offset: 0x0024 */
    QEI_FLTCTL_T QEI_FLTCTL;

    /* offset: 0x0028 */
    QEI_CNT_T QEI_CNT;

    /* offset: 0x002C */
    QEI_PPX_T QEI_PPX;

    /* offset: 0x0030 */
    QEI_PRSC_T QEI_PRSC;

    /* offset: 0x0034 */
    QEI_STA_T QEI_STA;

    /* offset: 0x0038 */
    QEI_IF_T QEI_IF;

    /* offset: 0x003C */
    QEI_IE_T QEI_IE;

    /* offset: 0x0040 */
    QEI_IC_T QEI_IC;

    /* offset: 0x0044 */
    QEI_IS_T QEI_IS;
} Qei_RegisterMap_t;

#define QEI0_ADDR ((uint32_t)0xF0023100)
#define QEI0_PTR  ((Qei_RegisterMap_t *)QEI0_ADDR)
#define QEI0_RM   (*(Qei_RegisterMap_t *)QEI0_ADDR)

#define QEI1_ADDR ((uint32_t)0xF0023200)
#define QEI1_PTR  ((Qei_RegisterMap_t *)QEI1_ADDR)
#define QEI1_RM   (*(Qei_RegisterMap_t *)QEI1_ADDR)

#define QEI2_ADDR ((uint32_t)0xF0023300)
#define QEI2_PTR  ((Qei_RegisterMap_t *)QEI2_ADDR)
#define QEI2_RM   (*(Qei_RegisterMap_t *)QEI2_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
