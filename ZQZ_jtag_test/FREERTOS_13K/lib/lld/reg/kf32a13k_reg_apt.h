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
 *****************************************************************************/

#ifndef _KF32DA13K_REG_APT_H_
#define _KF32DA13K_REG_APT_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *         Include Files
 **************************************************************************/
#include <stdint.h>
#include "kf_types.h"

/**************************************************************************
 *         Macro ro typedef
 **************************************************************************/
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁止请求位  */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁止状态  */
            __IO uint32_t EDIS      :1;  /*!< [2:2] 休眠模式使能控制位  */
            __IO uint32_t RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] APT模块版本号  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] APT模块类型  */
            __I uint32_t MODNUM  :16; /*!< [31:16] APT模块编号  */
        } bits;
        __I uint32_t reg;
    };
} APT_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :24; /*!< [23:0] 预留读为0  */
            __IO uint32_t SUS       :4;  /*!< [27:24] 调试模式挂起控制  */
            __O uint32_t  SUSP      :1;  /*!< [28:28] SUS位写保护，读出为0  */
            __I uint32_t  SUSSTA    :1;  /*!< [29:29] 挂起状态位  */
            __IO uint32_t RESERVED1 :2;  /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位请求位，与RST1寄存器的RST位一起使用  */
            __I uint32_t  RSTSTA    :1;  /*!< [1:1] 复位状态  */
            __IO uint32_t RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位请求位，与RST0寄存器的RST位一起使用  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  CLR       :1;  /*!< [0:0] RSTSTA复位状态清除位，读出为0  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_RSTCLR_T;

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
} APT_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN32 :1; /*!< [32:32] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN33 :1; /*!< [33:33] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN34 :1; /*!< [34:34] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN35 :1; /*!< [35:35] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN36 :1; /*!< [36:36] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN37 :1; /*!< [37:37] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN38 :1; /*!< [38:38] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN39 :1; /*!< [39:39] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN40 :1; /*!< [40:40] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN41 :1; /*!< [41:41] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN42 :1; /*!< [42:42] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN43 :1; /*!< [43:43] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN44 :1; /*!< [44:44] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN45 :1; /*!< [45:45] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN46 :1; /*!< [46:46] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN47 :1; /*!< [47:47] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN48 :1; /*!< [48:48] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN49 :1; /*!< [49:49] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN50 :1; /*!< [50:50] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN51 :1; /*!< [51:51] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN52 :1; /*!< [52:52] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN53 :1; /*!< [53:53] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN54 :1; /*!< [54:54] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN55 :1; /*!< [55:55] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN56 :1; /*!< [56:56] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN57 :1; /*!< [57:57] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN58 :1; /*!< [58:58] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN59 :1; /*!< [59:59] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN60 :1; /*!< [60:60] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN61 :1; /*!< [61:61] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN62 :1; /*!< [62:62] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN63 :1; /*!< [63:63] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
        } bits;
        __IO uint32_t reg;
    };
} APT_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN        :1; /*!< [0:0] T1定时器启动控制位  */
            __IO uint32_t CMS       :3; /*!< [3:1] Tz定时器计数方式选择位  */
            __IO uint32_t CLKMUX    :3; /*!< [6:4] 定时器时钟源选择，选择的时钟会与fBPT同步  */
            __IO uint32_t RESERVED0 :5; /*!< [11:7] 预留读为0  */
            __IO uint32_t SMS       :3; /*!< [14:12] Tz定时器从模式选择位  */
            __IO uint32_t RESERVED1 :1; /*!< [15:15] 预留读为0  */
            __IO uint32_t TRGIS     :5; /*!< [20:16] Tz定时器TRGI触发输入选择位  */
            __IO uint32_t RESERVED2 :3; /*!< [23:21] 预留读为0  */
            __IO uint32_t TRGOS     :4; /*!< [27:24] Tz定时器TRGO触发输出选择位  */
            __IO uint32_t OFS       :2; /*!< [29:28] Tz溢出中断触发AD选择  */
            __IO uint32_t RESERVED3 :2; /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_T1CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CCTEN    :1; /*!< [0:0] 比较器清零定时器功能使能位  */
            __IO uint32_t CRSET    :1; /*!< [1:1] 清零信号上升沿/下降沿选择位  */
            __IO uint32_t CCTSEL   :2; /*!< [3:2] 用于清零定时器的比较器模块选择位  */
            __IO uint32_t TCKFEN   :1; /*!< [4:4] 外部时钟输入滤波使能位  */
            __IO uint32_t TCKDIV   :4; /*!< [8:5] 外部时钟输入滤波时钟分频，滤波时钟为计数时钟  */
            __IO uint32_t TCKDELAY :3; /*!< [11:9] 外部时钟输入信号滤波延时设置  */
            __IO uint32_t RESERVED0 :20; /*!< [31:12] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_T1CTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PHSEN   :1; /*!< [0:0] 相位重载使能位  */
            __IO uint32_t PHSMODE :1; /*!< [1:1] 相位重载模式选择  */
            __IO uint32_t PHSW    :1; /*!< [2:2] 相位重载软件触发位  */
            __IO uint32_t PHSSEL  :3; /*!< [5:3] 相位重载时机选择位  */
            __IO uint32_t
              PHSPRSC :4; /*!< [9:6]
                             相位重载事件预分频每有PHSZPRSC<3:0>+1次PHSSEL<2:0>所选事件发生时，才会产生一次有效的相位重载事件。
                           */
            __IO uint32_t
              PHSTIME :4;             /*!< [13:10]
                                         相位重载次数在连续相位重载连续模式下，进行PHSTIME<3:0>次相位重载操作后就停止重载。
                                       */
            __IO uint32_t PHSTIEN :1; /*!< [14:14] Tz相位重载次数控制位，该位只在连续模式下有效  */
            __IO uint32_t PHSDIR :1; /*!< [15:15] Tz相位重载发生后的计数方向(只在向上向下计数模式下有效)  */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_T1PHSCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              CNT :32; /*!< [31:0]
                          32位APT计数寄存器写该寄存器的值只会在向上/向上向下计数方式下的启动时作为初始值载入，读该寄存器的值为定时器当前值
                        */
        } bits;
        __IO uint32_t reg;
    };
} APT_T1CNT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              CKS :32; /*!< [31:0]
                          32位APT预分频值可以将计数器的时钟频率按1到(FFFFFFFFh+1)之间的任意值分频，它是一个基于32位寄存器控制的32位计数器。这个控制寄存器带有缓冲器，它能够在工作时被改变。新的预分频器参数在下一个计数周期开始时被采用。
                        */
        } bits;
        __IO uint32_t reg;
    };
} APT_T1PRSC1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CKBS      :4;  /*!< [3:0] 分频器2分频比选择位  */
            __IO uint32_t RESERVED0 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_T1PRSC2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PPX :32; /*!< [31:0] 32位APT定时器周期寄存器  */
        } bits;
        __IO uint32_t reg;
    };
} APT_T1PPX_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PHS :32; /*!< [31:0] 相位值在同步事件发生时，会将该值加载到计数器CNT中。  */
        } bits;
        __IO uint32_t reg;
    };
} APT_T1PHS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t T1CCR0 :32; /*!< [31:0] T1触发AD寄存器0，当T1计数值等于T1CCR0时，产生脉冲信号去触发AD。  */
        } bits;
        __IO uint32_t reg;
    };
} APT_T1CCR0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t T1CCR1 :32; /*!< [31:0] T1触发AD寄存器1，当T1计数值等于T1CCR1时，产生脉冲信号去触发AD。  */
        } bits;
        __IO uint32_t reg;
    };
} APT_T1CCR1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t T1UDEN    :1;  /*!< [0:0] T1更新使能  */
            __IO uint32_t RESERVED0 :1;  /*!< [1:1] 预留读为0  */
            __IO uint32_t T1UDEVT0  :1;  /*!< [2:2] T1更新事件控制0  */
            __IO uint32_t T1UDEVT1  :1;  /*!< [3:3] T1更新事件控制1  */
            __IO uint32_t RESERVED1 :3;  /*!< [6:4] 预留读为0  */
            __IO uint32_t T1UDR     :1;  /*!< [7:7] T1占空比和输出控制更新软件触发位  */
            __IO uint32_t T1OUDREN  :1;  /*!< [8:8] T1溢出脉冲更新占空比和输出控制功能使能位  */
            __IO uint32_t RESERVED2 :7;  /*!< [15:9] 预留读为0  */
            __IO uint32_t UDREN     :1;  /*!< [16:16]
                                            立即更新事件重载计数器使能位，该位使能只有在使用TzUDEVT1产生立即更新的时候有效      */
            __IO uint32_t TRGUDEN0   :1; /*!< [17:17] TRGI触发更新使能(在TzUDEN=1时有效)  */
            __IO uint32_t TRGUDEN1   :1; /*!< [18:18] TRGI触发更新使能(在TzUDEN=1时有效)  */
            __IO uint32_t TUDMODE0   :1; /*!< [19:19] TRGI触发更新模式选择位  */
            __IO uint32_t TUDMODE1   :1; /*!< [20:20] TRGI触发更新模式选择位  */
            __IO uint32_t RESERVED3  :4; /*!< [24:21] 预留读为0  */
            __IO uint32_t CAPFILTEN1 :1; /*!< [25:25] 通道y捕捉输入滤波使能位  */
            __IO uint32_t CAPFILTEN2 :1; /*!< [26:26] 通道y捕捉输入滤波使能位  */
            __IO uint32_t CAPFILTEN3 :1; /*!< [27:27] 通道y捕捉输入滤波使能位  */
            __IO uint32_t RESERVED4  :4; /*!< [31:28] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_UDCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              UDCNT :8;                  /*!< [7:0]
                                            更新计数值若UDCTL寄存器中的T0UDEVT1=0，则只有在UDTIM0的值向下计数到0时才会更新T0为时基的占空比、周期、预分频寄存器到缓冲器中。
                                          */
            __IO uint32_t RESERVED0 :24; /*!< [31:8] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_UDTIM1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CH1M      :4;  /*!< [3:0] 模块的模式选择位  */
            __IO uint32_t CH2M      :4;  /*!< [7:4] 通道y模式选择位  */
            __IO uint32_t CH3M      :4;  /*!< [11:8] 通道y模式选择位  */
            __IO uint32_t RESERVED0 :4;  /*!< [15:12] 预留读为0  */
            __IO uint32_t HMEN      :1;  /*!< [16:16] 霍尔模式使能  */
            __IO uint32_t HMPEN     :1;  /*!< [17:17] 霍尔模式模板比较使能  */
            __IO uint32_t SMPEN     :1;  /*!< [18:18] 输入信号采样使能  */
            __IO uint32_t SPMEN     :1;  /*!< [19:19] 单脉冲输出模式使能  */
            __IO uint32_t SPMS      :1;  /*!< [20:20] 单脉冲输出模式选择  */
            __IO uint32_t RESERVED1 :11; /*!< [31:21] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_CHCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :2;  /*!< [1:0] 预留读为0  */
            __IO uint32_t PXOC1H    :2;  /*!< [3:2] 通道y的CHyH端口输出控制  */
            __IO uint32_t RESERVED1 :2;  /*!< [5:4] 预留读为0  */
            __IO uint32_t PXOC2H    :2;  /*!< [7:6] 通道y的CHyH端口输出控制  */
            __IO uint32_t RESERVED2 :2;  /*!< [9:8] 预留读为0  */
            __IO uint32_t PXOC3H    :2;  /*!< [11:10] 通道y的CHyH端口输出控制  */
            __IO uint32_t RESERVED3 :20; /*!< [31:12] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_CHCTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :6;  /*!< [5:0] 预留读为0  */
            __IO uint32_t CAPTST    :1;  /*!< [6:6] 捕捉测试模式触发信号  */
            __IO uint32_t GTBEN     :1;  /*!< [7:7] GTB模式使能位  */
            __IO uint32_t GTBEOUT   :1;  /*!< [8:8] GTB模式输出位  */
            __IO uint32_t RESERVED1 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_CHCTL3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PXASS1    :3;  /*!< [2:0] 通道y自动关闭源选择位  */
            __IO uint32_t PXASS2    :3;  /*!< [5:3] 通道y自动关闭源选择位  */
            __IO uint32_t PXASS3    :3;  /*!< [8:6] 通道y自动关闭源选择位  */
            __IO uint32_t RSEN      :1;  /*!< [9:9] PWM通道自动重启使能位  */
            __IO uint32_t RESERVED0 :22; /*!< [31:10] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_ASCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0  :2;  /*!< [1:0] 预留读为0  */
            __IO uint32_t PXSS1H     :2;  /*!< [3:2] 引脚CHyH关闭状态控制位  */
            __IO uint32_t RESERVED1  :2;  /*!< [5:4] 预留读为0  */
            __IO uint32_t PXSS2H     :2;  /*!< [7:6] 引脚CHyH关闭状态控制位  */
            __IO uint32_t RESERVED2  :2;  /*!< [9:8] 预留读为0  */
            __IO uint32_t PXSS3H     :2;  /*!< [11:10] 引脚CHyH关闭状态控制位  */
            __IO uint32_t RESERVED3  :4;  /*!< [15:12] 预留读为0  */
            __O uint32_t  ASE1STACLR :1;  /*!< [16:16] ASEySTA位清零位  */
            __O uint32_t  ASE2STACLR :1;  /*!< [17:17] ASEySTA位清零位  */
            __O uint32_t  ASE3STACLR :1;  /*!< [18:18] ASEySTA位清零位  */
            __IO uint32_t RESERVED4  :13; /*!< [31:19] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_ASCTL2_T;

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
} APT_ASCTL3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ZPD1TWIN  :1;  /*!< [0:0] 通道y的零点检测时序控制  */
            __IO uint32_t ZPD2TWIN  :1;  /*!< [1:1] 通道y的零点检测时序控制  */
            __IO uint32_t ZPD3TWIN  :1;  /*!< [2:2] 通道y的零点检测时序控制  */
            __IO uint32_t RESERVED0 :1;  /*!< [3:3] 预留读为0  */
            __IO uint32_t ZCLK      :4;  /*!< [7:4] 零点检测时钟设置位  */
            __IO uint32_t RESERVED1 :24; /*!< [31:8] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_ZPDCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ZPD1S      :3;  /*!< [2:0] 通道y零点检测电压选择  */
            __IO uint32_t ZPD2S      :3;  /*!< [5:3] 通道y零点检测电压选择  */
            __IO uint32_t ZPD3S      :3;  /*!< [8:6] 通道y零点检测电压选择  */
            __IO uint32_t RESERVED0  :3;  /*!< [11:9] 预留读为0  */
            __IO uint32_t ZPD1EN     :1;  /*!< [12:12] 通道y零点检测比较器使能位  */
            __IO uint32_t ZPD2EN     :1;  /*!< [13:13] 通道y零点检测比较器使能位  */
            __IO uint32_t ZPD3EN     :1;  /*!< [14:14] 通道y零点检测比较器使能位  */
            __IO uint32_t RESERVED1  :1;  /*!< [15:15] 预留读为0  */
            __O uint32_t  ZPD1STACLR :1;  /*!< [16:16] 通道y零点检测状态清零位  */
            __O uint32_t  ZPD2STACLR :1;  /*!< [17:17] 通道y零点检测状态清零位  */
            __O uint32_t  ZPD3STACLR :1;  /*!< [18:18] 通道y零点检测状态清零位  */
            __IO uint32_t RESERVED2  :13; /*!< [31:19] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_ZPDCTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :1;  /*!< [2:0] 预留读为0  */
            __IO uint32_t ZPORT1    :1;  /*!< [1:1] CH1H引脚控制  */
            __IO uint32_t RESERVED1 :1;  /*!< [2:2] 预留读为0  */
            __IO uint32_t ZPORT3    :1;  /*!< [3:3] CH2H引脚控制  */
            __IO uint32_t RESERVED2 :1;  /*!< [4:4] 预留读为0  */
            __IO uint32_t ZPORT5    :1;  /*!< [5:5] CH3H引脚控制  */
            __IO uint32_t RESERVED3 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_ZPDPORT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              CURHP :3; /*!< [2:0]
                           当前霍尔模式输入模板定义了CH1H-3H的输入信号模板，如果输入信号与CURHP<2:0>相等，则不发出中断。如果既不等于CURHP<2:0>也不等于EXPHP<2:0>，则发出霍尔错误中断。低位为CH1H输入模板
                         */
            __IO uint32_t
              EXPHP :3;                  /*!< [5:3]
                                            期望霍尔模式输入模板定义了期望的CH1H-3H输入信号模板，如果输入信号与EXPHP<2:0>相等，则发出期望霍尔修改中断。低位为CH1H输入模板
                                          */
            __IO uint32_t RESERVED0 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_HPCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              FRCVAL :5;                 /*!< [4:0]
                                            抖动计数器增量值APT内部有一个5bit大小的抖动计数器，用于确定抖动发生的时机。以CNT计数周期为单位，抖动计数器从0开始在每个Tx计数周期增加FRCVAL<4:0>，直到计数值超过0x20会产生进位信号，该进位信号作为控制抖动产生的信号，溢出后的余量继续累加。
                                          */
            __IO uint32_t DEDEN     :1;  /*!< [5:5] 边沿抖动使能  */
            __IO uint32_t DPEEN     :1;  /*!< [6:6] 周期抖动使能  */
            __IO uint32_t RESERVED0 :25; /*!< [31:7] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_DITCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t T1CCR0SEN :1;  /*!< [0:0] T1CCR0触发AD计数方向选择使能位  */
            __IO uint32_t T1CCR1SEN :1;  /*!< [1:1] T1CCR1触发AD计数方向选择使能位  */
            __IO uint32_t RESERVED0 :1;  /*!< [2:2] 预留读为0  */
            __IO uint32_t T1CCR0SEL :1;  /*!< [3:3] T1CCR0触发AD计数方向选择位  */
            __IO uint32_t T1CCR1SEL :1;  /*!< [4:4] T1CCR1触发AD计数方向选择位  */
            __IO uint32_t RESERVED1 :27; /*!< [31:5] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_CCRCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CAP1EN    :1; /*!< [0:0] 通道y捕捉使能位  */
            __IO uint32_t CAP2EN    :1; /*!< [1:1] 通道y捕捉使能位  */
            __IO uint32_t CAP3EN    :1; /*!< [2:2] 通道y捕捉使能位  */
            __IO uint32_t RESERVED0 :1; /*!< [3:3] 预留读为0  */
            __IO uint32_t CH1CAPED  :1; /*!< [4:4] 通道y捕捉有效沿选择  */
            __IO uint32_t CH2CAPED  :1; /*!< [5:5] 通道y捕捉有效沿选择  */
            __IO uint32_t CH3CAPED  :1; /*!< [6:6] 通道y捕捉有效沿选择  */
            __IO uint32_t RESERVED1 :1; /*!< [7:7] 预留读为0  */
            __IO uint32_t CH1CMODE  :1; /*!< [8:8] 通道y捕捉模式  */
            __IO uint32_t CH2CMODE  :1; /*!< [9:9] 通道y捕捉模式  */
            __IO uint32_t CH3CMODE  :1; /*!< [10:10] 通道y捕捉模式  */
            __IO uint32_t RESERVED2 :1; /*!< [11:11] 预留读为0  */
            __IO uint32_t CH1TIEN :1; /*!< [12:12] 通道y捕捉次数控制位，该位只在连续模式下有效  */
            __IO uint32_t CH2TIEN :1; /*!< [13:13] 通道y捕捉次数控制位，该位只在连续模式下有效  */
            __IO uint32_t CH3TIEN :1; /*!< [14:14] 通道y捕捉次数控制位，该位只在连续模式下有效  */
            __IO uint32_t RESERVED3   :1;  /*!< [15:15] 预留读为0  */
            __IO uint32_t CH1CAPFLTEN :1;  /*!< [16:16] 通道y捕捉输入滤波使能位  */
            __IO uint32_t CH2CAPFLTEN :1;  /*!< [17:17] 通道y捕捉输入滤波使能位  */
            __IO uint32_t CH3CAPFLTEN :1;  /*!< [18:18] 通道y捕捉输入滤波使能位  */
            __IO uint32_t RESERVED4   :13; /*!< [31:19] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_CAPCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CH1CAPPIN :3;  /*!< [2:0] CH1捕捉输入引脚选择位  */
            __IO uint32_t CH2CAPPIN :3;  /*!< [5:3] CH2捕捉输入引脚选择位  */
            __IO uint32_t CH3CAPPIN :3;  /*!< [8:6] CH3捕捉输入引脚选择位  */
            __IO uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_CAPCTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              CH1CAPPR :3; /*!< [2:0]
                              通道y捕捉事件预分频每当通道y有CHyCAPPR<2:0>+1次有效沿发生时，才会进行一次真正的有效捕捉事件。
                            */
            __IO uint32_t
              CH2CAPPR :3; /*!< [5:3]
                              通道y捕捉事件预分频每当通道y有CHyCAPPR<2:0>+1次有效沿发生时，才会进行一次真正的有效捕捉事件。
                            */
            __IO uint32_t
              CH3CAPPR :3;               /*!< [8:6]
                                            通道y捕捉事件预分频每当通道y有CHyCAPPR<2:0>+1次有效沿发生时，才会进行一次真正的有效捕捉事件。
                                          */
            __IO uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_CAPPRSC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              CH1CAPTIME :4; /*!< [3:0]
                                通道捕捉次数设置。在连续捕捉模式下，通道y进行CHyCAPTIME<3:0>次有效捕捉事件就停止捕捉。
                              */
            __IO uint32_t
              CH2CAPTIME :4; /*!< [7:4]
                                通道捕捉次数设置。在连续捕捉模式下，通道y进行CHyCAPTIME<3:0>次有效捕捉事件就停止捕捉。
                              */
            __IO uint32_t
              CH3CAPTIME :4;             /*!< [11:8]
                                            通道捕捉次数设置。在连续捕捉模式下，通道y进行CHyCAPTIME<3:0>次有效捕捉事件就停止捕捉。
                                          */
            __IO uint32_t RESERVED0 :20; /*!< [31:12] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_CAPTIME_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              CH1FLCLKP :4; /*!< [3:0]
                               通道捕捉输入滤波时钟分频，在工作时钟基础上分频。滤波时钟为工作时钟的CHyFLCLKP<3:0>+1分频，即默认为1分频。
                             */
            __IO uint32_t
              CH2FLCLKP :4; /*!< [7:4]
                               通道捕捉输入滤波时钟分频，在工作时钟基础上分频。滤波时钟为工作时钟的CHyFLCLKP<3:0>+1分频，即默认为1分频。
                             */
            __IO uint32_t
              CH3FLCLKP :4;             /*!< [11:8]
                                           通道捕捉输入滤波时钟分频，在工作时钟基础上分频。滤波时钟为工作时钟的CHyFLCLKP<3:0>+1分频，即默认为1分频。
                                         */
            __IO uint32_t RESERVED0 :4; /*!< [15:12] 预留读为0  */
            __IO uint32_t
              CH1FLT :3; /*!< [18:16]
                            捕捉输入滤波次数。滤波长度为CHyFILTER<2:0>+1，即默认滤波长度为1个滤波时钟周期的长度。如果不需要滤波则需要将相应通道的捕捉输入滤波使能位CAPFILTENy关闭
                          */
            __IO uint32_t
              CH2FLT :3; /*!< [21:19]
                            捕捉输入滤波次数。滤波长度为CHyFILTER<2:0>+1，即默认滤波长度为1个滤波时钟周期的长度。如果不需要滤波则需要将相应通道的捕捉输入滤波使能位CAPFILTENy关闭
                          */
            __IO uint32_t
              CH3FLT :3;                /*!< [24:22]
                                           捕捉输入滤波次数。滤波长度为CHyFILTER<2:0>+1，即默认滤波长度为1个滤波时钟周期的长度。如果不需要滤波则需要将相应通道的捕捉输入滤波使能位CAPFILTENy关闭
                                         */
            __IO uint32_t RESERVED1 :7; /*!< [31:25] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_CAPFLT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  T1DIR     :1;  /*!< [0:0] T1定时器计数方向  */
            __IO uint32_t RESERVED0 :1;  /*!< [1:1] 预留读为0  */
            __I uint32_t  ASE1STA   :1;  /*!< [2:2] 通道y自动关闭事件状态位  */
            __I uint32_t  ASE2STA   :1;  /*!< [3:3] 通道y自动关闭事件状态位  */
            __I uint32_t  ASE3STA   :1;  /*!< [4:4] 通道y自动关闭事件状态位  */
            __IO uint32_t RESERVED1 :1;  /*!< [5:5] 预留读为0  */
            __I uint32_t  ZPD1STA   :1;  /*!< [6:6] 通道y零点检测的感应电压检测  */
            __I uint32_t  ZPD2STA   :1;  /*!< [7:7] 通道y零点检测的感应电压检测  */
            __I uint32_t  ZPD3STA   :1;  /*!< [8:8] 通道y零点检测的感应电压检测  */
            __IO uint32_t RESERVED2 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CY :32; /*!< [31:0] 在捕捉模式下时，当对应的CHy引脚发生事件时，Cy寄存器捕捉CNT寄存器的32位值。
                                  */
        } bits;
        __I uint32_t reg;
    };
} APT_C1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              BCY :32; /*!< [31:0]
                          备用捕捉寄存器值在捕捉模式下时，该寄存器捕捉的值与Cy寄存器相同。在PWM测量模式下，该寄存器捕捉下降沿。Cy捕捉寄存器捕捉上升沿。具体参考PWM测量模式章节的描述。
                        */
        } bits;
        __I uint32_t reg;
    };
} APT_BC1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CY :32; /*!< [31:0] 在捕捉模式下时，当对应的CHy引脚发生事件时，Cy寄存器捕捉CNT寄存器的32位值。
                                  */
        } bits;
        __I uint32_t reg;
    };
} APT_C2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              BCY :32; /*!< [31:0]
                          备用捕捉寄存器值在捕捉模式下时，该寄存器捕捉的值与Cy寄存器相同。在PWM测量模式下，该寄存器捕捉下降沿。Cy捕捉寄存器捕捉上升沿。具体参考PWM测量模式章节的描述。
                        */
        } bits;
        __I uint32_t reg;
    };
} APT_BC2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CY :32; /*!< [31:0] 在捕捉模式下时，当对应的CHy引脚发生事件时，Cy寄存器捕捉CNT寄存器的32位值。
                                  */
        } bits;
        __I uint32_t reg;
    };
} APT_C3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              BCY :32; /*!< [31:0]
                          备用捕捉寄存器值在捕捉模式下时，该寄存器捕捉的值与Cy寄存器相同。在PWM测量模式下，该寄存器捕捉下降沿。Cy捕捉寄存器捕捉上升沿。具体参考PWM测量模式章节的描述。
                        */
        } bits;
        __I uint32_t reg;
    };
} APT_BC3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              RY :32; /*!< [31:0]
                         在比较模式下，32位Ry寄存器的值将不断与CNT寄存器的值相比较。当两者匹配时，就会触发相应的事件。在PWM模式下，Ry寄存器作为PWMxy的占空比寄存器。
                       */
        } bits;
        __IO uint32_t reg;
    };
} APT_R1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              RY :32; /*!< [31:0]
                         在比较模式下，32位Ry寄存器的值将不断与CNT寄存器的值相比较。当两者匹配时，就会触发相应的事件。在PWM模式下，Ry寄存器作为PWMxy的占空比寄存器。
                       */
        } bits;
        __IO uint32_t reg;
    };
} APT_R2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              RY :32; /*!< [31:0]
                         在比较模式下，32位Ry寄存器的值将不断与CNT寄存器的值相比较。当两者匹配时，就会触发相应的事件。在PWM模式下，Ry寄存器作为PWMxy的占空比寄存器。
                       */
        } bits;
        __IO uint32_t reg;
    };
} APT_R3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  T1TOIF    :1;  /*!< [0:0] Tz溢出事件中断标志  */
            __IO uint32_t RESERVED0 :1;  /*!< [1:1] 预留读为0  */
            __I uint32_t  CC1IF     :1;  /*!< [2:2] 通道y捕捉/比较事件中断标志  */
            __I uint32_t  CC2IF     :1;  /*!< [3:3] 通道y捕捉/比较事件中断标志  */
            __I uint32_t  CC3IF     :1;  /*!< [4:4] 通道y捕捉/比较事件中断标志  */
            __IO uint32_t RESERVED1 :1;  /*!< [5:5] 预留读为0  */
            __I uint32_t  T1TRGIF   :1;  /*!< [6:6] Tz触发事件中断标志  */
            __IO uint32_t RESERVED2 :1;  /*!< [7:7] 预留读为0  */
            __I uint32_t  T1UEIF    :1;  /*!< [8:8] Tz更新事件中断标志  */
            __IO uint32_t RESERVED3 :1;  /*!< [9:9] 预留读为0  */
            __I uint32_t  HEIF      :1;  /*!< [10:10] 霍尔错误中断  */
            __I uint32_t  HCIF      :1;  /*!< [11:11] 霍尔修改中断  */
            __IO uint32_t RESERVED4 :20; /*!< [31:12] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t T1OIE     :1;  /*!< [0:0] APTTz溢出事件中断使能位  */
            __IO uint32_t RESERVED0 :1;  /*!< [1:1] 预留读为0  */
            __IO uint32_t CC1IE     :1;  /*!< [2:2] 通道y捕捉/比较事件中断使能位  */
            __IO uint32_t CC2IE     :1;  /*!< [3:3] 通道y捕捉/比较事件中断使能位  */
            __IO uint32_t CC3IE     :1;  /*!< [4:4] 通道y捕捉/比较事件中断使能位  */
            __IO uint32_t RESERVED1 :1;  /*!< [5:5] 预留读为0  */
            __IO uint32_t T1TRGIE   :1;  /*!< [6:6] Tz触发事件中断使能位  */
            __IO uint32_t RESERVED2 :1;  /*!< [7:7] 预留读为0  */
            __IO uint32_t T1UEIE    :1;  /*!< [8:8] Tz更新事件中断使能位  */
            __IO uint32_t RESERVED3 :1;  /*!< [9:9] 预留读为0  */
            __IO uint32_t HEIE      :1;  /*!< [10:10] 霍尔错误中断使能位  */
            __IO uint32_t HCIE      :1;  /*!< [11:11] 霍尔修改中断使能位  */
            __IO uint32_t RESERVED4 :20; /*!< [31:12] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  T1OIC     :1;  /*!< [0:0] 溢出事件中断标志清0位  */
            __IO uint32_t RESERVED0 :1;  /*!< [1:1] 预留读为0  */
            __O uint32_t  CC1IC     :1;  /*!< [2:2] 通道y捕捉/比较事件中断标志清0位  */
            __O uint32_t  CC2IC     :1;  /*!< [3:3] 通道y捕捉/比较事件中断标志清0位  */
            __O uint32_t  CC3IC     :1;  /*!< [4:4] 通道y捕捉/比较事件中断标志清0位  */
            __IO uint32_t RESERVED1 :1;  /*!< [5:5] 预留读为0  */
            __O uint32_t  T1TRGIC   :1;  /*!< [6:6] 触发事件中断标志清0位  */
            __IO uint32_t RESERVED2 :1;  /*!< [7:7] 预留读为0  */
            __O uint32_t  T1UEIC    :1;  /*!< [8:8] 更新事件中断标志清0位  */
            __IO uint32_t RESERVED3 :1;  /*!< [9:9] 预留读为0  */
            __O uint32_t  HEIC      :1;  /*!< [10:10] 霍尔错误中断标志清0位  */
            __O uint32_t  HCIC      :1;  /*!< [11:11] 霍尔修改中断标志清0位  */
            __IO uint32_t RESERVED4 :20; /*!< [31:12] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_IC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  T1OIS     :1;  /*!< [0:0] 溢出事件中断标志置1位  */
            __IO uint32_t RESERVED0 :1;  /*!< [1:1] 预留读为0  */
            __O uint32_t  CC1IS     :1;  /*!< [2:2] 通道y捕捉/比较事件中断标志置1位  */
            __O uint32_t  CC2IS     :1;  /*!< [3:3] 通道y捕捉/比较事件中断标志置1位  */
            __O uint32_t  CC3IS     :1;  /*!< [4:4] 通道y捕捉/比较事件中断标志置1位  */
            __IO uint32_t RESERVED1 :1;  /*!< [5:5] 预留读为0  */
            __O uint32_t  T1TRGIS   :1;  /*!< [6:6] 触发事件中断标志置1位  */
            __IO uint32_t RESERVED2 :1;  /*!< [7:7] 预留读为0  */
            __O uint32_t  T1UEIS    :1;  /*!< [8:8] 更新事件中断标志置1位  */
            __IO uint32_t RESERVED3 :1;  /*!< [9:9] 预留读为0  */
            __O uint32_t  HEIS      :1;  /*!< [10:10] 霍尔错误中断标志置1位  */
            __O uint32_t  HCIS      :1;  /*!< [11:11] 霍尔修改中断标志置1位  */
            __IO uint32_t RESERVED4 :20; /*!< [31:12] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_IS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t T10NP     :2; /*!< [1:0] 溢出事件的服务中断节点  */
            __IO uint32_t RESERVED0 :2; /*!< [3:2] 预留读为0  */
            __IO uint32_t CC1NP     :2; /*!< [5:4] 通道1捕捉/比较事件的服务中断节点  */
            __IO uint32_t CC2NP     :2; /*!< [7:6] 通道2捕捉/比较事件的服务中断节点指针  */
            __IO uint32_t CC3NP     :2; /*!< [9:8] 通道3捕捉/比较事件的服务中断节点  */
            __IO uint32_t RESERVED1 :2; /*!< [11:10] 预留读为0  */
            __IO uint32_t T1TRNP    :2; /*!< [13:12] 触发事件的服务中断节点  */
            __IO uint32_t RESERVED2 :2; /*!< [15:14] 预留读为0  */
            __IO uint32_t T1UENP    :2; /*!< [17:16] 更新事件的服务中断节点  */
            __IO uint32_t RESERVED3 :2; /*!< [19:18] 预留读为0  */
            __IO uint32_t HENP      :2; /*!< [21:20] 霍尔错误的服务中断节点  */
            __IO uint32_t HCNP      :2; /*!< [23:22] 霍尔修改的服务中断节点  */
            __IO uint32_t RESERVED4 :8; /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} APT_INP_T;

typedef volatile struct
{
    /* address: 0xF0021000 */
    APT_CLKC_T APT_CLKC;

    /* address: 0xF0021004 */
    APT_INFO_T APT_INFO;

    /* address: 0xF0021008 */
    APT_DBG_T APT_DBG;

    /* address: 0xF002100C */
    APT_RST0_T APT_RST0;

    /* address: 0xF0021010 */
    APT_RST1_T APT_RST1;

    /* address: 0xF0021014 */
    APT_RSTCLR_T APT_RSTCLR;

    /* address: 0xF0021018 */
    APT_ACES0_T APT_ACES0;

    /* address: 0xF002101C */
    APT_ACES1_T APT_ACES1;

    /* address: 0xF0021020 */
    APT_T1CTL1_T APT_T1CTL1;

    /* address: 0xF0021024 */
    APT_T1CTL2_T APT_T1CTL2;

    /* address: 0xF0021028 */
    APT_T1PHSCTL_T APT_T1PHSCTL;

    /* address: 0xF002102C */
    APT_T1CNT_T APT_T1CNT;

    /* address: 0xF0021030 */
    APT_T1PRSC1_T APT_T1PRSC1;

    /* address: 0xF0021034 */
    APT_T1PRSC2_T APT_T1PRSC2;

    /* address: 0xF0021038 */
    APT_T1PPX_T APT_T1PPX;

    /* address: 0xF002103C */
    APT_T1PHS_T APT_T1PHS;

    /* address: 0xF0021040 */
    APT_T1CCR0_T APT_T1CCR0;

    /* address: 0xF0021044 */
    APT_T1CCR1_T APT_T1CCR1;

    /* address: 0xF0021048 */
    APT_UDCTL_T APT_UDCTL;

    /* address: 0xF002104C */
    APT_UDTIM1_T APT_UDTIM1;

    /* address: 0xF0021050 */
    APT_CHCTL1_T APT_CHCTL1;

    /* address: 0xF0021054 */
    APT_CHCTL2_T APT_CHCTL2;

    /* address: 0xF0021058 */
    APT_CHCTL3_T APT_CHCTL3;

    /* address: 0xF002105C */
    APT_ASCTL1_T APT_ASCTL1;

    /* address: 0xF0021060 */
    APT_ASCTL2_T APT_ASCTL2;

    /* address: 0xF0021064 */
    APT_ASCTL3_T APT_ASCTL3;

    /* address: 0xF0021068 */
    APT_ZPDCTL1_T APT_ZPDCTL1;

    /* address: 0xF002106C */
    APT_ZPDCTL2_T APT_ZPDCTL2;

    /* address: 0xF0021070 */
    APT_ZPDPORT_T APT_ZPDPORT;

    /* address: 0xF0021074 */
    APT_HPCTL_T APT_HPCTL;

    /* address: 0xF0021078 */
    APT_DITCTL_T APT_DITCTL;

    /* address: 0xF002107C */
    APT_CCRCTL_T APT_CCRCTL;

    /* address: 0xF0021080 */
    APT_CAPCTL1_T APT_CAPCTL1;

    /* address: 0xF0021084 */
    APT_CAPCTL2_T APT_CAPCTL2;

    /* address: 0xF0021088 */
    APT_CAPPRSC_T APT_CAPPRSC;

    /* address: 0xF002108C */
    APT_CAPTIME_T APT_CAPTIME;

    /* address: 0xF0021090 */
    APT_CAPFLT_T APT_CAPFLT;

    /* address: 0xF0021094 */
    APT_STA_T APT_STA;

    /* address: 0xF0021098 */
    APT_C1_T APT_C1;

    /* address: 0xF002109C */
    APT_BC1_T APT_BC1;

    /* address: 0xF00210A0 */
    APT_C2_T APT_C2;

    /* address: 0xF00210A4 */
    APT_BC2_T APT_BC2;

    /* address: 0xF00210A8 */
    APT_C3_T APT_C3;

    /* address: 0xF00210AC */
    APT_BC3_T APT_BC3;

    /* address: 0xF00210B0 */
    APT_R1_T APT_R1;

    /* address: 0xF00210B4 */
    APT_R2_T APT_R2;

    /* address: 0xF00210B8 */
    APT_R3_T APT_R3;

    /* address: 0xF00210BC */
    APT_IF_T APT_IF;

    /* address: 0xF00210C0 */
    APT_IE_T APT_IE;

    /* address: 0xF00210C4 */
    APT_IC_T APT_IC;

    /* address: 0xF00210C8 */
    APT_IS_T APT_IS;

    /* address: 0xF00210CC */
    APT_INP_T APT_INP;
} Apt_RegisterMap_t;

#define APT0_ADDR ((uint32_t)0xF0021000)
#define APT0_PTR  ((Apt_RegisterMap_t *)APT0_ADDR)
#define APT0_RM   (*(Apt_RegisterMap_t *)APT0_ADDR)

#define APT1_ADDR ((uint32_t)0xF0021100)
#define APT1_PTR  ((Apt_RegisterMap_t *)APT1_ADDR)
#define APT1_RM   (*(Apt_RegisterMap_t *)APT1_ADDR)

#define APT2_ADDR ((uint32_t)0xF0021200)
#define APT2_PTR  ((Apt_RegisterMap_t *)APT2_ADDR)
#define APT2_RM   (*(Apt_RegisterMap_t *)APT2_ADDR)

#define APT3_ADDR ((uint32_t)0xF0021300)
#define APT3_PTR  ((Apt_RegisterMap_t *)APT3_ADDR)
#define APT3_RM   (*(Apt_RegisterMap_t *)APT3_ADDR)

#define APT4_ADDR ((uint32_t)0xF0021400)
#define APT4_PTR  ((Apt_RegisterMap_t *)APT4_ADDR)
#define APT4_RM   (*(Apt_RegisterMap_t *)APT4_ADDR)

#define APT5_ADDR ((uint32_t)0xF0021500)
#define APT5_PTR  ((Apt_RegisterMap_t *)APT5_ADDR)
#define APT5_RM   (*(Apt_RegisterMap_t *)APT5_ADDR)

#define APT6_ADDR ((uint32_t)0xF0021600)
#define APT6_PTR  ((Apt_RegisterMap_t *)APT6_ADDR)
#define APT6_RM   (*(Apt_RegisterMap_t *)APT6_ADDR)

#define APT7_ADDR ((uint32_t)0xF0021700)
#define APT7_PTR  ((Apt_RegisterMap_t *)APT7_ADDR)
#define APT7_RM   (*(Apt_RegisterMap_t *)APT7_ADDR)

#define APT8_ADDR ((uint32_t)0xF0021800)
#define APT8_PTR  ((Apt_RegisterMap_t *)APT8_ADDR)
#define APT8_RM   (*(Apt_RegisterMap_t *)APT8_ADDR)

#define APT9_ADDR ((uint32_t)0xF0021900)
#define APT9_PTR  ((Apt_RegisterMap_t *)APT9_ADDR)
#define APT9_RM   (*(Apt_RegisterMap_t *)APT9_ADDR)

#define APT10_ADDR ((uint32_t)0xF0021A00)
#define APT10_PTR  ((Apt_RegisterMap_t *)APT10_ADDR)
#define APT10_RM   (*(Apt_RegisterMap_t *)APT10_ADDR)

#define APT11_ADDR ((uint32_t)0xF0021B00)
#define APT11_PTR  ((Apt_RegisterMap_t *)APT11_ADDR)
#define APT11_RM   (*(Apt_RegisterMap_t *)APT11_ADDR)

#define APT12_ADDR ((uint32_t)0xF0021C00)
#define APT12_PTR  ((Apt_RegisterMap_t *)APT12_ADDR)
#define APT12_RM   (*(Apt_RegisterMap_t *)APT12_ADDR)

#define APT13_ADDR ((uint32_t)0xF0021D00)
#define APT13_PTR  ((Apt_RegisterMap_t *)APT13_ADDR)
#define APT13_RM   (*(Apt_RegisterMap_t *)APT13_ADDR)

#define APT14_ADDR ((uint32_t)0xF0021E00)
#define APT14_PTR  ((Apt_RegisterMap_t *)APT14_ADDR)
#define APT14_RM   (*(Apt_RegisterMap_t *)APT14_ADDR)

#define APT15_ADDR ((uint32_t)0xF0021F00)
#define APT15_PTR  ((Apt_RegisterMap_t *)APT15_ADDR)
#define APT15_RM   (*(Apt_RegisterMap_t *)APT15_ADDR)

#define APT16_ADDR ((uint32_t)0xF0022000)
#define APT16_PTR  ((Apt_RegisterMap_t *)APT16_ADDR)
#define APT16_RM   (*(Apt_RegisterMap_t *)APT16_ADDR)

#define APT17_ADDR ((uint32_t)0xF0022100)
#define APT17_PTR  ((Apt_RegisterMap_t *)APT17_ADDR)
#define APT17_RM   (*(Apt_RegisterMap_t *)APT17_ADDR)

#define APT18_ADDR ((uint32_t)0xF0022200)
#define APT18_PTR  ((Apt_RegisterMap_t *)APT18_ADDR)
#define APT18_RM   (*(Apt_RegisterMap_t *)APT18_ADDR)

/**
 * @brief 检查所有APT外设
 *
 */
#define CHECK_APT_ALL_PERIPH(MODULE)                                                                                   \
    ((MODULE == APT0_PTR) || (MODULE == APT1_PTR) || (MODULE == APT2_PTR) || (MODULE == APT3_PTR) ||                   \
     (MODULE == APT4_PTR) || (MODULE == APT5_PTR) || (MODULE == APT6_PTR) || (MODULE == APT7_PTR) ||                   \
     (MODULE == APT8_PTR) || (MODULE == APT9_PTR) || (MODULE == APT10_PTR) || (MODULE == APT11_PTR) ||                 \
     (MODULE == APT12_PTR) || (MODULE == APT13_PTR) || (MODULE == APT14_PTR) || (MODULE == APT15_PTR) ||               \
     (MODULE == APT16_PTR) || (MODULE == APT17_PTR) || (MODULE == APT18_PTR))

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
