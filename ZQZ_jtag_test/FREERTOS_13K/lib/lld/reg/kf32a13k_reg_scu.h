/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_scu.h
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
 *  |2023-12-20  |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_REG_SCU_H_
#define _KF32DA13K_REG_SCU_H_

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
            __I uint32_t  RESERVED0 :7;  /*!< [6:0] 预留  */
            __IO uint32_t EDGMOD    :2;  /*!< [8:7] 信号边沿检测控制。  */
            __I uint32_t  RESERVED1 :23; /*!< [31:9] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_EDG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              APRSTA :1;                /*!< [0:0]
                                           应用程序复位指示。当应用程序复位发生时，该位被置1，并可以通过RCU_OUTCF.APRSTACLR进行清零。当该位被置1时，且ESR被设置为复位输出时，ESR不会作为复位触发来源，此时ESR复位触发信号将直接输出一个低电平信号。
                                         */
            __O uint32_t APRSTACLR :1;  /*!< [1:1] APRSTA位清零。  */
            __I uint32_t RESERVED0 :30; /*!< [31:2] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_OUTCF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ESR0DEPTH :4; /*!< [3:0] ESR0数字滤波器比较深度。  */
            __I uint32_t  RESERVED0 :4; /*!< [7:4] 预留  */
            __IO uint32_t ESR0CLK   :1; /*!< [8:8] ESR0输入信号处理模块的时钟选择设置。  */
            __I uint32_t  RESERVED1 :7; /*!< [15:9] 预留  */
            __IO uint32_t ESR1DEPTH :4; /*!< [19:16] ESR1数字滤波器比较深度。  */
            __I uint32_t  RESERVED2 :4; /*!< [23:20] 预留  */
            __IO uint32_t ESR1CLK   :1; /*!< [24:24] ESR1输入信号处理模块的时钟选择设置。  */
            __I uint32_t  RESERVED3 :7; /*!< [31:25] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_DEPTH_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ESR0PIN   :1; /*!< [0:0] ESR0复位请求触发状态。  */
            __I uint32_t ESR1PIN   :1; /*!< [1:1] ESR1复位请求触发状态。  */
            __I uint32_t SMUALL    :1; /*!< [2:2] 永久性应用程序复位请求触发状态。  */
            __I uint32_t SMU       :1; /*!< [3:3] SMU复位请求触发状态。  */
            __I uint32_t SW        :1; /*!< [4:4] 软件复位请求触发状态。  */
            __I uint32_t STM0      :1; /*!< [5:5] STM0复位请求触发状态。  */
            __I uint32_t STM1      :1; /*!< [6:6] STM1复位请求触发状态。  */
            __I uint32_t RESERVED0 :9; /*!< [15:7] 预留  */
            __I uint32_t PORST     :1; /*!< [16:16] PORST复位请求触发状态。  */
            __I uint32_t RESERVED1 :1; /*!< [17:17] 预留  */
            __I uint32_t CB0       :1; /*!< [18:18] cerberus系统复位请求触发状态。  */
            __I uint32_t CB1       :1; /*!< [19:19] cerberus调试复位请求触发状态。  */
            __I uint32_t CB3       :1; /*!< [20:20] cerberus应用程序复位请求触发状态。  */
            __I uint32_t DCDC11    :1; /*!< [21:21] 复位请求为DCDC11的触发器复位状态  */
            __I uint32_t LDO33     :1; /*!< [22:22] 复位请求为LDO33的触发器复位状态  */
            __I uint32_t PMON      :1; /*!< [23:23] 复位请求为供电监视器的触发器复位状态  */
            __I uint32_t HSMS      :1; /*!< [24:24] 复位请求为HSM系统复位的触发器复位状态  */
            __I uint32_t HSMA      :1; /*!< [25:25] 复位请求为HSM应用复位的触发器复位状态  */
            __I uint32_t STBYR     :1; /*!< [26:26] 复位请求为standby调节监视器的触发器复位状态  */
            __I uint32_t LBPORST   :1; /*!< [27:27] 由PORST而导致的LBIST终止  */
            __I uint32_t LBTERM :1; /*!< [28:28] LBIST已正确终止。此位可通过RCU_CTL1.COLDCLR被置1而清除。  */
            __I uint32_t RESERVED2 :3; /*!< [31:29] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ST0AREN   :1;  /*!< [0:0] Systick0复位使能。  */
            __IO uint32_t ST1AREN   :1;  /*!< [1:1] Systick1复位使能。  */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_APTE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ESR0RMOD  :2;  /*!< [1:0] ESR0复位请求触发配置。  */
            __IO uint32_t ESR1RMOD  :2;  /*!< [3:2] ESR1复位请求触发配置。  */
            __IO uint32_t SACURMOD  :2;  /*!< [7:6] SACU复位请求触发配置。  */
            __IO uint32_t SWRMOD    :2;  /*!< [9:8] 软件复位请求触发配置。  */
            __IO uint32_t ST0RMOD   :2;  /*!< [11:10] ST0复位请求触发配置。  */
            __IO uint32_t ST1RMOD   :2;  /*!< [13:12] ST1复位请求触发配置。  */
            __I uint32_t  RESERVED0 :18; /*!< [31:14] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_CTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :1;  /*!< [0:0] 预留  */
            __O uint32_t SWRQ      :1;  /*!< [1:1] 软件复位请求触发。  */
            __I uint32_t RESERVED1 :30; /*!< [31:2] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_SW_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FOCRST :1; /*!< [0:0] 超时强制复位。  */
            __O uint32_t COLDCLR :1; /*!< [1:1] 复位触发源状态寄存器RCU_STA中冷复位状态位清除设置。  */
            __I uint32_t  TOUT0     :1;  /*!< [2:2] CPU0开始执行WAIT指令提示信号。  */
            __I uint32_t  TOUT1     :1;  /*!< [3:3] CPU1开始执行WAIT指令提示信号。  */
            __I uint32_t  RESERVED0 :3;  /*!< [6:4] 预留  */
            __IO uint32_t CSS0      :1;  /*!< [7:7] CPU0进入空闲状态标志位。  */
            __IO uint32_t CSS1      :1;  /*!< [8:8] CPU1进入空闲状态标志位。  */
            __I uint32_t  RESERVED1 :7;  /*!< [15:9] 预留  */
            __IO uint32_t USINFOR   :16; /*!< [31:16] 用户信息，通过程序去存储信息。  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留  */
        } bits;
        __I uint32_t reg;
    };
} RCU_CTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              HWCFG :8;                 /*!< [7:0]
                                           硬件配置设置。在应用程序复位上升沿锁存HWCFG口的状态，并且当RCU_STST.LUDIS被清零时进行更新，当RCU_STST.LUDIS置1时，HWCFG不进行更新。
                                         */
            __IO uint32_t FTM       :7; /*!< [14:8] 在正常模式，该位域被更新为0000000。  */
            __IO uint32_t MODE      :1; /*!< [15:15] 测试模式是否被选择设置。  */
            __I uint32_t  FCBAE     :1; /*!< [16:16] Flash配置区域访问使能。  */
            __I uint32_t  LUDIS     :1; /*!< [17:17] HWCFG锁存更新使能。  */
            __I uint32_t  RESERVED0 :1; /*!< [18:18] 预留  */
            __I uint32_t  TRSTL     :1; /*!< [19:19] 指示TRST的状态  */
            __IO uint32_t SPDEN     :1; /*!< [20:20] 单pin口DAP模式使能。  */
            __I uint32_t  RESERVED1 :3; /*!< [23:21] 预留  */
            __I uint32_t  RAMINT    :1; /*!< [24:24] RAM内容安全完整性。  */
            __I uint32_t  RESERVED2 :7; /*!< [31:25] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_STST_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :13; /*!< [12:0] 预留  */
            __O uint32_t  SFCBAE    :1;  /*!< [13:13] 对RCU_STST.FCBAE进行置位。  */
            __O uint32_t  CFCBAE    :1;  /*!< [14:14] 对RCU_STST.FCBAE进行清零。  */
            __IO uint32_t STP       :1;  /*!< [15:15] 启动保护设置。  */
            __I uint32_t  RESERVED1 :16; /*!< [31:16] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_STCF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DFDEPTH   :4;  /*!< [3:0] PORST输入口数字滤波器比较深度设置。  */
            __I uint32_t  RESERVED0 :28; /*!< [31:4] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} RCU_PORSTDF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] PORST输入口数字滤波器比较深度设置。  */
            __I uint32_t  RSTSTAT   :1;  /*!< [1:1] 当前是否产生CPU0模块复位。  */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} CPU_KRST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] PORST输入口数字滤波器比较深度设置。  */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} CPU_KRST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CLR       :1;  /*!< [0:0] 置1清除CPU1_KRST0.RSTSTAT。  */
            __I uint32_t RESERVED0 :31; /*!< [31:1] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} CPU_KRSTCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t REVISION :8;  /*!< [7:0] SCU模块版本信息位  */
            __I uint32_t TYPE     :8;  /*!< [15:8] SCU模块类型信息  */
            __I uint32_t NUMBER   :16; /*!< [31:16] SCU模块编号  */
        } bits;
        __I uint32_t reg;
    };
} SCU_ID_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FSIZE     :4;  /*!< [3:0] 指示此芯片的PFlash大小  */
            __IO uint32_t CHPK      :4;  /*!< [7:4] 芯片封装  */
            __IO uint32_t CHID      :4;  /*!< [11:8] 芯片产品型号  */
            __I uint32_t  RESERVED0 :12; /*!< [23:12] 预留，读为0 */
            __IO uint32_t UCORE     :8;  /*!< [31:24] 指示Flash内程序版本信息  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_CHIPID_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t INFO :32; /*!< [31:0] 记录制造商信息  */
        } bits;
        __I uint32_t reg;
    };
} SCU_MANID_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              ACCEN0 :1; /*!< [0:0]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN1 :1; /*!< [1:1]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN2 :1; /*!< [2:2]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN3 :1; /*!< [3:3]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN4 :1; /*!< [4:4]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN5 :1; /*!< [5:5]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN6 :1; /*!< [6:6]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN7 :1; /*!< [7:7]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN8 :1; /*!< [8:8]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN9 :1; /*!< [9:9]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN10 :1; /*!< [10:10]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN11 :1; /*!< [11:11]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN12 :1; /*!< [12:12]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN13 :1; /*!< [13:13]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN14 :1; /*!< [14:14]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN15 :1; /*!< [15:15]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN16 :1; /*!< [16:16]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN17 :1; /*!< [17:17]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN18 :1; /*!< [18:18]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN19 :1; /*!< [19:19]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN20 :1; /*!< [20:20]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN21 :1; /*!< [21:21]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN22 :1; /*!< [22:22]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN23 :1; /*!< [23:23]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN24 :1; /*!< [24:24]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN25 :1; /*!< [25:25]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN26 :1; /*!< [26:26]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN27 :1; /*!< [27:27]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN28 :1; /*!< [28:28]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN29 :1; /*!< [29:29]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN30 :1; /*!< [30:30]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN31 :1; /*!< [31:31]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P0”的寄存器可以被对应的主机模块访问。
                           */
        } bits;
        __IO uint32_t reg;
    };
} SCU_ACCEN00_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留  */
        } bits;
        __I uint32_t reg;
    };
} SCU_ACCEN01_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              ACCEN0 :1; /*!< [0:0]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN1 :1; /*!< [1:1]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN2 :1; /*!< [2:2]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN3 :1; /*!< [3:3]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN4 :1; /*!< [4:4]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN5 :1; /*!< [5:5]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN6 :1; /*!< [6:6]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN7 :1; /*!< [7:7]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN8 :1; /*!< [8:8]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN9 :1; /*!< [9:9]
                            主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                          */
            __IO uint32_t
              ACCEN10 :1; /*!< [10:10]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN11 :1; /*!< [11:11]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN12 :1; /*!< [12:12]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN13 :1; /*!< [13:13]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN14 :1; /*!< [14:14]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN15 :1; /*!< [15:15]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN16 :1; /*!< [16:16]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN17 :1; /*!< [17:17]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN18 :1; /*!< [18:18]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN19 :1; /*!< [19:19]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN20 :1; /*!< [20:20]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN21 :1; /*!< [21:21]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN22 :1; /*!< [22:22]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN23 :1; /*!< [23:23]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN24 :1; /*!< [24:24]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN25 :1; /*!< [25:25]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN26 :1; /*!< [26:26]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN27 :1; /*!< [27:27]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN28 :1; /*!< [28:28]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN29 :1; /*!< [29:29]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN30 :1; /*!< [30:30]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
            __IO uint32_t
              ACCEN31 :1; /*!< [31:31]
                             主机访问使能。当对应的使能位置一时标志着SCU模块内标记为“P1”的寄存器可以被对应的主机模块访问。
                           */
        } bits;
        __IO uint32_t reg;
    };
} SCU_ACCEN10_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留  */
        } bits;
        __I uint32_t reg;
    };
} SCU_ACCEN11_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CPU0LSEN :1; /*!< [0:0] CPU0锁步使能。该寄存器只能在启动阶段由SSW写入。  */
            __I uint32_t RESERVED0 :31; /*!< [31:1] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_CPU0LCKCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CPU0LSSTA :1;  /*!< [0:0] CPU0锁步状态标志位。  */
            __I uint32_t RESERVED0 :31; /*!< [31:1] 预留  */
        } bits;
        __I uint32_t reg;
    };
} SCU_CPU0LCKSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CPU0LSTEST :1;  /*!< [0:0] CPU0锁步测试。为CPU0进行故障注入。  */
            __I uint32_t RESERVED0  :15; /*!< [15:1] 预留  */
            __O uint32_t PFTEST     :1;  /*!< [16:16] PFI0锁步测试。  */
            __I uint32_t RESERVED1  :15; /*!< [31:17] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_CPU0LCKTEST_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  REQ       :1;  /*!< [0:0] LBIST请求  */
            __O uint32_t  RST       :1;  /*!< [1:1] LBIST重置  */
            __IO uint32_t BODY      :1;  /*!< [2:2] 管脚状态值  */
            __I uint32_t  RESERVED0 :1;  /*!< [3:3] 预留  */
            __IO uint32_t FREQ      :4;  /*!< [7:4] 选择LBIST频率。  */
            __I uint32_t  RESERVED1 :22; /*!< [29:8] 预留  */
            __IO uint32_t ERRINJ    :1;  /*!< [30:30] LBIST/测试模式报警错误注入。  */
            __IO uint32_t REQRED    :1;  /*!< [31:31] LBIST请求冗余  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_LBISTCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t DONE      :1;  /*!< [0:0] LBIST执行状态指示表示实际的LBIST控制器执行状态  */
            __I uint32_t RESERVED0 :31; /*!< [31:1] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_LBISTSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              NUM :18;                  /*!< [17:0]
                                           LBIST测试Pattern数量此字段定义扫描patterns数量，这将在LBIST过程中执行扫描加载。注意此位域的值决定了扫描捕获阶段的数量，而不是扫描链加载/卸载阶段的数量。例如，值0x0001指结果中两个扫描链加载与1个捕获量；指0x0002指结果中3个扫描链加载与2个捕获量；以此类推。值0x0000为无效，此情况不会执行捕获。
                                         */
            __I uint32_t RESERVED0 :14; /*!< [31:18] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_LBISTPAT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SEED :19; /*!< [18:0]
                                       LBIST种子，此位域确定在LBIST执行期间将哪些pattern应用于1-19的EDT输入通道。  */
            __IO uint32_t
              SPLITSH :3;               /*!< [21:19]
                                           LBIST分组移位选择，此位域值将允许通过分组扫描移位操作方式运行LBIST，减少运行功耗。
                                         */
            __I uint32_t RESERVED0 :10; /*!< [31:22] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_LBISTSEED_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              LENGTH :12;               /*!< [11:0]
                                           LBIST最大扫描链长度此位域定义每个LBIST扫描负载的位移周期数。并且在BOOT启动阶段将存储在FlashUCB中参数信息自动加载进该寄存器内。*/
            __I uint32_t RESERVED0 :18; /*!< [31:12] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_LBISTSC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              SIGNATURE :32; /*!< [31:0]
                                此位域指示最后次LBIST执行的MISR签名。只有在LBISTCTL.DONE等于1时，它从TCU内的LBIST控制器镜像。在LBIST控制器的重新启动的情况下(通过LBISTCTL0.RES功能)，签名值将被同步重置为0。
                              */
        } bits;
        __IO uint32_t reg;
    };
} SCU_LBISTSIG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CPU0OVEN  :1;  /*!< [0:0] CPU0覆盖控制使能。  */
            __IO uint32_t CPU1OVEN  :1;  /*!< [1:1] CPU1覆盖控制使能。  */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_OVLAYCTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CPU0SEL   :1; /*!< [0:0] CPU0选择  */
            __O uint32_t CPU1SEL   :1; /*!< [1:1] CPU1选择  */
            __I uint32_t RESERVED0 :2; /*!< [3:2] 预留  */
            __O uint32_t OVSTART   :1; /*!< [4:4] OVERLAY启动  */
            __O uint32_t OVSTOP    :1; /*!< [5:5] OVERLAY停止  */
            __O uint32_t DCINVALID :1; /*!< [6:6] 数据缓存无效位，仅CPUxSEL选择的CPU对数据缓存有影响  */
            __IO uint32_t OVCFG     :1;  /*!< [8:8] OVERLAY配置状态位  */
            __O uint32_t  OVCFGWP   :1;  /*!< [9:9] OVCFG保护位  */
            __I uint32_t  RESERVED1 :22; /*!< [31:10] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_OVLAYCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CLK6TRG   :1;  /*!< [0:0] 用于触发CCU6的同步启动特性  */
            __O uint32_t  RAMINTCTL :2;  /*!< [2:1] 控制RAMINT标志位的置位和清零  */
            __O uint32_t  LUDISCTL  :1;  /*!< [3:3] 控制LUDIS标志位  */
            __IO uint32_t DXCPLCTL  :1;  /*!< [4:4] DXCPL功能控制  */
            __I uint32_t  RESERVED0 :27; /*!< [31:5] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_SYSCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ADDRCFG   :2;  /*!< [1:0] 配置当前选用的地址映射模式  */
            __IO uint32_t SPARE     :14; /*!< [15:2] 备用地址配置寄存器  */
            __I uint32_t  RESERVED0 :16; /*!< [31:16] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_SOTACTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t MEM :32; /*!< [31:0] 启动软件存储值  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_STMEM_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FLAG :32; /*!< [31:0] 启动错误标志位  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_CAERRFLAG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SEL       :8;  /*!< [7:0] 测试输出信号选择  */
            __IO uint32_t TESTEN    :1;  /*!< [8:8] 测试输出信号使能控制  */
            __I uint32_t  RESERVED0 :23; /*!< [31:9] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_TESTMOD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              ESR0T :1; /*!< [0:0]
                           ESR0陷阱请求标志位，该位可以通过ESR0触发事件置一，或者通过软件写入陷阱置位寄存器中ESR0T位域来置一。该位只能通过软件写入陷阱清零寄存器中ESR0T位域清零。
                         */
            __I uint32_t
              ESR1T :1; /*!< [1:1]
                           ESR1陷阱请求标志位，该位可以通过ESR1触发事件置一，或者通过软件写入陷阱置位寄存器中ESR1T位域来置一。该位只能通过软件写入陷阱清零寄存器中ESR1T位域清零。
                         */
            __I uint32_t
              TRAPSW :1; /*!< [2:2]
                            软件陷阱请求标志位，该位可以通过写入陷阱置位寄存器中TRAPSW位域来置一。该位可以通过软件写入陷阱清零寄存器中TRAPSW位域清零。
                          */
            __I uint32_t
              SMUT :1;                  /*!< [3:3]
                                           SACU告警陷阱请求标志位，该位可以通过SACU告警触发事件置一，或者通过软件写入陷阱置位寄存器中SMUT位域来置一。该位只能通过软件写入陷阱清零寄存器中SMUT位域清零。
                                         */
            __I uint32_t RESERVED0 :28; /*!< [31:4] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_TRAPSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t ESR0T     :1;  /*!< [0:0] 置位陷阱请求标志位ESR0T  */
            __O uint32_t ESR1T     :1;  /*!< [1:1] 置位陷阱请求标志位ESR1T  */
            __O uint32_t TRAPSW    :1;  /*!< [2:2] 置位陷阱请求标志位TRAPSW  */
            __O uint32_t SMUT      :1;  /*!< [3:3] 置位陷阱请求标志位SMUT  */
            __I uint32_t RESERVED0 :28; /*!< [31:4] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_TRAPSET_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t ESR0T     :1;  /*!< [0:0] 清零陷阱请求标志位ESR0T  */
            __O uint32_t ESR1T     :1;  /*!< [1:1] 清零陷阱请求标志位ESR1T  */
            __O uint32_t TRAPSW    :1;  /*!< [2:2] 清零陷阱请求标志位TRAPSW  */
            __O uint32_t SMUT      :1;  /*!< [3:3] 清零陷阱请求标志位SMUT  */
            __I uint32_t RESERVED0 :28; /*!< [31:4] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_TRAPCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CPU0ESR0T  :1;  /*!< [0:0] CPU0ESR0陷阱使能  */
            __IO uint32_t CPU0ESR1T  :1;  /*!< [1:1] CPU0ESR1陷阱使能  */
            __IO uint32_t CPU0TRAPSW :1;  /*!< [2:2] CPU0SW陷阱使能  */
            __IO uint32_t CPU0SMUT   :1;  /*!< [3:3] CPU0SMU陷阱使能  */
            __I uint32_t  RESERVED0  :4;  /*!< [7:4] 预留  */
            __IO uint32_t CPU1ESR0T  :1;  /*!< [8:8] CPU1ESR0陷阱使能  */
            __IO uint32_t CPU1ESR1T  :1;  /*!< [9:9] CPU1ESR1陷阱使能  */
            __IO uint32_t CPU1TRAPSW :1;  /*!< [10:10] CPU1SW陷阱使能  */
            __IO uint32_t CPU1SMUT   :1;  /*!< [11:11] CPU1SMU陷阱使能  */
            __I uint32_t  RESERVED1  :20; /*!< [31:12] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_TRAPEN_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              ENDINIT :1; /*!< [0:0]
                             ENDINIT控制位在密码访问和校验访问时该位必须写1，在修改访问期间,必须使用所需的ENDINIT更新值写入此位。这一位被用作保护所有带有SE属性的寄存器，但是更推荐使用安全超时定时器的ENDINIT位来实现解锁功能，这样不会影响到安全看门狗本身的监控功能。
                           */
            __IO uint32_t
              LCK :1;              /*!< [1:1]
                                      安全看门狗控制寄存器0锁定保护位，锁定保护位由硬件控制，仅在有效的密码访问后清零，清零后可以对控制寄存器0中的内容进行修改，每次有效的修改访问以后LCK位会自动置一。
                                    */
            __IO uint32_t PW  :14; /*!< [15:2] 访问CPUxWDTCTL0的用户自定义密码。  */
            __IO uint32_t REL :17; /*!< [31:15] 用户自定义定时器重载值。  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_SWDTCTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CLRIRF :1; /*!< [0:0] 清除内部复位标志位。该位用于清除双SMU复位事件标志位。  */
            __IO uint32_t IR0 :1; /*!< [1:1] IR0、IR1、IR2三个位域控制看门狗计数时钟分频选择位  */
            __IO uint32_t IR1 :1; /*!< [2:2] 16384分频。  */
            __IO uint32_t DR  :1; /*!< [3:3] DISABLE模式请求位  */
            __I uint32_t  RESERVED0 :1; /*!< [4:4] 预留  */
            __IO uint32_t IR2       :1; /*!< [5:5] 64分频。  */
            __IO uint32_t
              UR :1; /*!< [6:6] 解锁限制请求控制位。该位表示当SMU模块处于FAULT状态时，是否可以解锁看门狗控制寄存器0  */
            __IO uint32_t PAR :1; /*!< [7:7] 自动密码序列请求位。  */
            __IO uint32_t TCR :1; /*!< [8:8] 定时器校验请求位。  */
            __IO uint32_t
              TCTR :7;                   /*!< [15:9]
                                            定时器校验冗余度设置。只有在取消安全ENDINIT时，才能修改此位。当安全ENDINIT被重新启动，TCT才更新。安全ENDINIT禁止，TCT才开始控制计数器冗余检测。当安全ENDINIT重新启动时，TCT从TCTR中更新。
                                          */
            __IO uint32_t CSEL      :2;  /*!< [17:16] 看门狗定时器时钟选择位。  */
            __I uint32_t  RESERVED1 :14; /*!< [31:18] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_SWDTCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TIMELOW   :16; /*!< [15:0] 喂狗的下限时间  */
            __I uint32_t  PREFLAG   :1;  /*!< [16:16] 提前喂狗标志位。  */
            __I uint32_t  RESERVED0 :15; /*!< [31:17] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_SWDTCTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t AEF       :1;  /*!< [0:0] 看门狗访问错误状态标志位  */
            __I uint32_t OEF       :1;  /*!< [1:1] 看门狗溢出错误状态标志位  */
            __I uint32_t RESERVED0 :2;  /*!< [3:2] 预留  */
            __I uint32_t DSF       :1;  /*!< [4:4] 看门狗使能或禁用状态标志位。  */
            __I uint32_t TOF       :1;  /*!< [5:5] CPUx看门狗超时模式标志位  */
            __I uint32_t USF       :1;  /*!< [6:6] SACU解锁限制状态标志位  */
            __I uint32_t PASF      :1;  /*!< [7:7] 密码自动序列状态标志位  */
            __I uint32_t TCSF      :1;  /*!< [8:8] 计数器检查状态标志位  */
            __I uint32_t TCT       :7;  /*!< [15:9] 计数器检查公差  */
            __I uint32_t TIM       :16; /*!< [31:16] 超时计数器的值  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_SWDTSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              ENDINIT :1; /*!< [0:0]
                             寄存器读写权限控制，在密码访问和校验访问时该位必须写1，在修改访问期间该位可以根据需求配置。这一位被用作保护所有带有SE属性的寄存器，但是更推荐使用安全超时定时器的ENDINIT位来实现解锁功能，这样不会影响到安全看门狗本身的监控功能。
                           */
            __IO uint32_t
              LCK :1;              /*!< [1:1]
                                      安全看门狗控制寄存器0锁定保护位，锁定保护位由硬件控制，仅在有效的密码访问后清零，清零后可以对控制寄存器0中的内容进行修改，每次有效的修改访问以后LCK位会自动置一。
                                    */
            __IO uint32_t PW  :14; /*!< [15:2] 用户自定义密码。  */
            __IO uint32_t REL :17; /*!< [31:15] 用户自定义定时器重载值。  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_CPUWDTCTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :1; /*!< [0:0] 预留  */
            __IO uint32_t IR0       :1; /*!< [1:1] 看门狗计数时钟分频选择位  */
            __IO uint32_t IR1       :1; /*!< [2:2] 16384分频。  */
            __IO uint32_t DR        :1; /*!< [3:3] DISABLE模式请求位  */
            __I uint32_t  RESERVED1 :1; /*!< [4:4] 预留  */
            __IO uint32_t IR2       :1; /*!< [5:5] 64分频。  */
            __IO uint32_t
              UR :1; /*!< [6:6] 解锁限制请求控制位。该位表示当SMU模块处于FAULT状态时，是否可以解锁看门狗控制寄存器0  */
            __IO uint32_t PAR       :1;  /*!< [7:7] 自动密码序列请求位。  */
            __IO uint32_t TCR       :1;  /*!< [8:8] 定时器校验请求位。  */
            __IO uint32_t TCTR      :7;  /*!< [15:9] 定时器校验冗余度设置。  */
            __IO uint32_t CSEL      :2;  /*!< [17:16] 看门狗定时器时钟选择位。  */
            __I uint32_t  RESERVED2 :14; /*!< [31:18] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_CPUWDTCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TIMELOW   :16; /*!< [15:0] 喂狗的下限时间  */
            __I uint32_t  AHEADWD   :1;  /*!< [16:16] 提前喂狗标志位。  */
            __I uint32_t  RESERVED0 :15; /*!< [31:17] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_CPUWDTCTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t AEF       :1;  /*!< [0:0] 看门狗访问错误状态标志位  */
            __I uint32_t OEF       :1;  /*!< [1:1] 看门狗溢出错误状态标志位  */
            __I uint32_t RESERVED0 :2;  /*!< [3:2] 预留  */
            __I uint32_t DSF       :1;  /*!< [4:4] 看门狗使能或禁用状态标志位。  */
            __I uint32_t TOF       :1;  /*!< [5:5] CPU0看门狗超时模式标志位  */
            __I uint32_t USF       :1;  /*!< [6:6] SACU解锁限制状态标志位  */
            __I uint32_t PASF      :1;  /*!< [7:7] 密码自动序列状态标志位  */
            __I uint32_t TCSF      :1;  /*!< [8:8] 计数器检查状态标志位  */
            __I uint32_t TCT       :7;  /*!< [15:9] 计数器检查公差  */
            __I uint32_t TIM       :16; /*!< [31:16] 超时计数器的值  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_CPUWDTSTA_T;

typedef volatile struct
{
    SCU_CPUWDTCTL0_T SCU_CPUWDTCTL0;
    SCU_CPUWDTCTL1_T SCU_CPUWDTCTL1;
    SCU_CPUWDTSTA_T  SCU_CPUWDTSTA;
} SCU_CPUWDT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :1; /*!< [0:0] 预留  */
            __IO uint32_t
              ENDINIT :1;          /*!< [1:1]
                                      寄存器读写权限控制，在密码访问和校验访问时该位必须写1，在修改访问期间该位可以根据需求配置。这一位被用作保护所有带有SE属性的寄存器，但是更推荐使用安全超时定时器的ENDINIT位来实现解锁功能，这样不会影响到安全看门狗本身的监控功能。
                                    */
            __IO uint32_t EPW :14; /*!< [15:2] 用户自定义密码。  */
            __IO uint32_t  REL :16; /*!< [31:16] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_GECTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :1;  /*!< [0:0] 预留  */
            __IO uint32_t IR0       :1;  /*!< [1:1] 看门狗计数时钟分频选择位  */
            __IO uint32_t IR1       :1;  /*!< [2:2] 16384分频。  */
            __IO uint32_t DR        :1;  /*!< [3:3] DISABLE模式请求位  */
            __I uint32_t  RESERVED1 :1;  /*!< [4:4] 预留  */
            __IO uint32_t IR2       :1;  /*!< [5:5] 64分频。  */
            __I uint32_t  RESERVED2 :10; /*!< [15:6] 预留  */
            __IO uint32_t CSEL      :2;  /*!< [17:16] 看门狗定时器时钟选择位。  */
            __I uint32_t  RESERVED3 :14; /*!< [31:18] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_GECTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              AEF :1; /*!< [0:0]
                         GECTL0寄存器访问错误状态标志位。当非法的密码访问或权限访问寄存器GECTL0时，该标志位被置1。当有效修改访问GECTL0.ENDINT，可清除该标志位
                       */
            __I uint32_t
              OEF :1;            /*!< [1:1]
                                    安全访问超时溢出错误状态标志位当GESTA.TIM超时值在FFFFH到FFFCH之间，该标志位被置1。当有效修改访问GECTL0可清除此标志位。
                                  */
            __I uint32_t IS0 :1; /*!< [2:2] 无访问错误  */
            __I uint32_t IS1 :1; /*!< [3:3] 已发生了访问错误  */
            __I uint32_t
              IS2 :1;                   /*!< [4:4]
                                           访问超时输入时钟状态S0和IS1被同时应用。此位域指示当前安全访问超时计数器时钟周期，当有效的SCU_GECTL1寄存器修改访问后可更新SCU_GECTL1.IR0和SCU_GECTL1.IR1的状态。
                                         */
            __I uint32_t DSF       :1;  /*!< [5:5] 安全访问使能或禁用状态标志位  */
            __I uint32_t TOF       :1;  /*!< [6:6] 安全访问超时模式标志位  */
            __I uint32_t RESERVED0 :9;  /*!< [15:7] 预留  */
            __I uint32_t TIM       :16; /*!< [31:16] 超时计数器的值  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_GESTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :1; /*!< [0:0] 预留  */
            __IO uint32_t
              ENDINIT :1;          /*!< [1:1]
                                      寄存器读写权限控制，在密码访问和校验访问时该位必须写1，在修改访问期间该位可以根据需求配置。这一位被用作保护所有带有SE属性的寄存器，但是更推荐使用安全超时定时器的ENDINIT位来实现解锁功能，这样不会影响到安全看门狗本身的监控功能。
                                    */
            __IO uint32_t EPW :14; /*!< [15:2] 用户自定义密码。应用程序复位后的默认密码为00000000111100B  */
            __I uint32_t
              REL :16; /*!< [31:16]
                          安全访问超时计数器的重加载值此计数器的重加载值是固定的，此位域读取为FFFCH，不能更改。在密码访问期间必须加载当前内容。
                        */
        } bits;
        __IO uint32_t reg;
    };
} SCU_SGECTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :1;  /*!< [0:0] 预留  */
            __IO uint32_t IR0       :1;  /*!< [1:1] 看门狗计数时钟分频选择位  */
            __IO uint32_t IR1       :1;  /*!< [2:2] 16384分频。  */
            __IO uint32_t DR        :1;  /*!< [3:3] DISABLE模式请求位  */
            __I uint32_t  RESERVED1 :1;  /*!< [4:4] 预留  */
            __IO uint32_t IR2       :1;  /*!< [5:5] 64分频。  */
            __I uint32_t  RESERVED2 :10; /*!< [15:6] 预留  */
            __IO uint32_t CSEL      :2;  /*!< [17:16] 看门狗定时器时钟选择位。  */
            __I uint32_t  RESERVED3 :14; /*!< [31:18] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_SGECTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              AEF :1; /*!< [0:0]
                         SGECTL0寄存器访问错误状态标志位.当非法的密码访问或权限访问寄存器SGECTL0时，该标志位被置1。当有效修改访问SGECTL0.ENDINT，可清除该标志位。
                       */
            __I uint32_t
              OEF :1;            /*!< [1:1]
                                    安全访问超时溢出错误状态标志位。当SGESTA.TIM超时值在FFFFH到FFFCH之间，该标志位被置1。当有效修改访问SGECTL0可清除此标志位。
                                  */
            __I uint32_t IS0 :1; /*!< [2:2] 无访问超时溢出错误  */
            __I uint32_t IS1 :1; /*!< [3:3] 已发生了访问超时溢出错误  */
            __I uint32_t
              IS2 :1;                   /*!< [4:4]
                                           访问超时输入时钟状态。IS0和IS1被同时应用。此位域指示当前安全访问超时计数器时钟周期，当有效的SCU_SGECTL1寄存器修改访问后可更新SCU_SGECTL1.IR0和SCU_SGECTL1.IR1的状态。
                                         */
            __I uint32_t DSF       :1;  /*!< [5:5] 安全访问使能或禁用状态标志位  */
            __I uint32_t TOF       :1;  /*!< [6:6] 安全访问超时模式标志位  */
            __I uint32_t RESERVED0 :9;  /*!< [15:7] 预留  */
            __I uint32_t TIM       :16; /*!< [31:16] 超时计数器的值  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_SGESTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TIME      :16; /*!< [15:0] CPU唤醒时间设置。  */
            __I uint32_t  RESERVED0 :16; /*!< [31:16] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_WAKEUP_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t POL       :1;  /*!< [0:0] 输入极性选择。  */
            __IO uint32_t MODE      :1;  /*!< [1:1] 模式选择。  */
            __IO uint32_t ENON      :1;  /*!< [2:2] EMSF标志位使能。  */
            __IO uint32_t PSEL      :1;  /*!< [3:3] 引脚选择。  */
            __I uint32_t  RESERVED0 :12; /*!< [15:4] 预留  */
            __I uint32_t  EMSF      :1;  /*!< [16:16] 紧急停止标志位  */
            __I uint32_t  SEMSF     :1;  /*!< [17:17] SMU触发紧急停止标志位  */
            __I uint32_t  RESERVED1 :14; /*!< [31:18] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_ESCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t SEMSFM    :2;  /*!< [1:0] SMU紧急停止标志位修改。  */
            __O uint32_t EMSFM     :2;  /*!< [3:2] 紧急停止标志位修改。  */
            __I uint32_t RESERVED0 :28; /*!< [31:4] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_ESSWCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FILRQx    :17; /*!< [16:0] 引脚滤波器使能  */
            __I uint32_t  RESERVED0 :7;  /*!< [23:17] 预留  */
            __IO uint32_t FILTDIV   :4;  /*!< [27:24] 数字滤波器时钟分频选择  */
            __IO uint32_t DEPTH     :4;  /*!< [31:28] 滤波深度设置。该位域写0则禁用数字滤波器。  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_EIFCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :4; /*!< [3:0] 预留 */
            __IO uint32_t EXIS2I    :3; /*!< [6:4] 外部输入选择  */
            __I uint32_t  RESERVED1 :1; /*!< [7:7] 预留 */
            __IO uint32_t FEN2I     :1; /*!< [8:8] 下降沿使能  */
            __IO uint32_t REN2I     :1; /*!< [9:9] 上升沿使能  */
            __IO uint32_t LDEN2I :1; /*!< [10:10] 等级检测使能。该位用于使能是否在检测到相反的沿事件后自动清零状态标志位
                                      */
            __IO uint32_t EIEN2I :1; /*!< [11:11] 外部输入使能。该位用于使能是否生成触发事件给到输出门控单元。  */
            __IO uint32_t INP2I :3; /*!< [14:12] 输入节点指示。该位用于指示触发事件路由到哪一个输出门控单元。  */
            __I uint32_t  RESERVED2 :5; /*!< [19:15] 预留 */
            __IO uint32_t EXISI     :3; /*!< [22:20] 外部触发选择  */
            __I uint32_t  RESERVED3 :1; /*!< [23:23] 预留 */
            __IO uint32_t FENI      :1; /*!< [24:24] 下降沿使能  */
            __IO uint32_t RENI      :1; /*!< [25:25] 上升沿使能  */
            __IO uint32_t LDENI :1; /*!< [26:26] 等级检测使能。该位用于使能是否在检测到相反的沿事件后自动清零状态标志位
                                     */
            __IO uint32_t EIENI :1; /*!< [27:27] 外部输入使能。该位用于使能是否生成触发事件给到输出门控单元。  */
            __IO uint32_t INPI :3; /*!< [30:28] 输入节点指示。该位用于指示触发事件路由到哪一个输出门控单元。  */
            __I uint32_t  RESERVED4 :1; /*!< [31:31] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} SCU_EICCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t FSx       :8; /*!< [7:0] 为通道x置位标志位INTFx  */
            __I uint32_t RESERVED0 :8; /*!< [15:8] 预留  */
            __O uint32_t FCx       :8; /*!< [23:16] 为通道x清零标志位INTFx。  */
            __I uint32_t RESERVED1 :8; /*!< [31:24] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_INTFCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t IPEN2I    :8; /*!< [7:0] 标志位pattern检测使能  */
            __I uint32_t  RESERVED0 :5; /*!< [12:8] 预留  */
            __IO uint32_t GEEN2I :1; /*!< [13:13] 生成事件使能。该位用于启用pattern检测结果变化事件。  */
            __IO uint32_t IGP2I     :2; /*!< [15:14] 中断门控模式。  */
            __IO uint32_t IPENI     :8; /*!< [23:16] 标志位模式pattern使能  */
            __I uint32_t  RESERVED1 :5; /*!< [28:24] 预留  */
            __IO uint32_t GEENI :1; /*!< [29:29] 生成事件使能。该位用于启用pattern检测结果变化事件。  */
            __IO uint32_t IGPI :2; /*!< [31:30] 中断门控模式。  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_IGCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t INTFx     :8;  /*!< [7:0] 通道x外部事件标志位。  */
            __I uint32_t RESERVED0 :24; /*!< [31:8] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_EIFSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t PDRy :8; /*!< [7:0] 该位监视输出通道y的pattern检测结果。  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_PDRSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SEL0      :3; /*!< [2:0] 外扩通道选择。  */
            __I uint32_t  RESERVED0 :1; /*!< [3:3] 预留  */
            __IO uint32_t SEL1      :3; /*!< [6:4] 外扩通道选择。  */
            __I uint32_t  RESERVED1 :1; /*!< [7:7] 预留  */
            __IO uint32_t SEL2      :3; /*!< [10:8] 外扩通道选择。  */
            __I uint32_t  RESERVED2 :1; /*!< [11:11] 预留  */
            __IO uint32_t SEL3      :3; /*!< [14:12] 外扩通道选择。  */
            __I uint32_t  RESERVED3 :1; /*!< [15:15] 预留  */
            __IO uint32_t SEL4      :3; /*!< [18:16] 外扩通道选择。  */
            __I uint32_t  RESERVED4 :1; /*!< [19:19] 预留  */
            __IO uint32_t SEL5      :3; /*!< [22:20] 外扩通道选择。  */
            __I uint32_t  RESERVED5 :1; /*!< [23:23] 预留  */
            __IO uint32_t SEL6      :3; /*!< [26:24] 外扩通道选择。  */
            __I uint32_t  RESERVED6 :1; /*!< [27:27] 预留  */
            __IO uint32_t SEL7      :3; /*!< [30:28] 外扩通道选择。  */
            __I uint32_t  RESERVED7 :1; /*!< [31:31] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} SCU_ERUSEL_T;

typedef volatile struct
{
    /* address: 0xF000F000 */
    SCU_ID_T SCU_ID;

    /* address: 0xF000F004 */
    SCU_CHIPID_T SCU_CHIPID;

    /* address: 0xF000F008 */
    SCU_MANID_T SCU_MANID;

    /* address: 0xF000F00C */
    SCU_ACCEN00_T SCU_ACCEN00;

    /* address: 0xF000F010 */
    SCU_ACCEN01_T SCU_ACCEN01;

    /* address: 0xF000F014 */
    SCU_ACCEN10_T SCU_ACCEN10;

    /* address: 0xF000F018 */
    SCU_ACCEN11_T SCU_ACCEN11;

    /* address: 0xF000F01C */
    SCU_CPU0LCKCTL_T SCU_CPU0LCKCTL;

    /* address: 0xF000F020 */
    SCU_CPU0LCKSTA_T SCU_CPU0LCKSTA;

    /* address: 0xF000F024 */
    SCU_CPU0LCKTEST_T SCU_CPU0LCKTEST;

    /* address: 0xF000F028 */
    SCU_LBISTCTL_T SCU_LBISTCTL;

    /* address: 0xF000F02C */
    SCU_LBISTSTA_T SCU_LBISTSTA;

    /* address: 0xF000F030 */
    SCU_LBISTPAT_T SCU_LBISTPAT;

    /* address: 0xF000F034 */
    SCU_LBISTSEED_T SCU_LBISTSEED;

    /* address: 0xF000F038 */
    SCU_LBISTSC_T SCU_LBISTSC;

    /* address: 0xF000F03C */
    SCU_LBISTSIG_T SCU_LBISTSIG;

    /* address: 0xF000F040 */
    SCU_OVLAYCTL0_T SCU_OVLAYCTL0;

    /* address: 0xF000F044 */
    SCU_OVLAYCTL1_T SCU_OVLAYCTL1;

    /* address: 0xF000F048 */
    SCU_SYSCTL_T SCU_SYSCTL;

    /* address: 0xF000F04C */
    SCU_SOTACTL_T SCU_SOTACTL;

    /* address: 0xF000F050 */
    SCU_STMEM_T SCU_STMEM[7];

    /* address: 0xF000F06C */
    SCU_CAERRFLAG_T SCU_CAERRFLAG[2];

    /* address: 0xF000F074 */
    SCU_TESTMOD_T SCU_TESTMOD;

    /* address: 0xF000F078 */
    RCU_EDG_T RCU_EDG[2];

    /* address: 0xF000F080 */
    RCU_OUTCF_T RCU_OUTCF;

    /* address: 0xF000F084 */
    RCU_DEPTH_T RCU_DEPTH;

    /* address: 0xF000F088 */
    RCU_STA_T RCU_STA;

    /* address: 0xF000F08C */
    RCU_APTE_T RCU_APTE;

    /* address: 0xF000F090 */
    RCU_CTL0_T RCU_CTL0;

    /* address: 0xF000F094 */
    RCU_SW_T RCU_SW;

    /* address: 0xF000F098 */
    RCU_CTL1_T RCU_CTL1;

    /* address: 0xF000F09C */
    RCU_CTL2_T RCU_CTL2;

    /* address: 0xF000F0A0 */
    RCU_STST_T RCU_STST;

    /* address: 0xF000F0A4 */
    RCU_STCF_T RCU_STCF;

    /* address: 0xF000F0A8 */
    RCU_PORSTDF_T RCU_PORSTDF;

    /* address: 0xF000F0AC */
    SCU_TRAPSTA_T SCU_TRAPSTA;

    /* address: 0xF000F0B0 */
    SCU_TRAPSET_T SCU_TRAPSET;

    /* address: 0xF000F0B4 */
    SCU_TRAPCLR_T SCU_TRAPCLR;

    /* address: 0xF000F0B8 */
    SCU_TRAPEN_T SCU_TRAPEN;

    /* address: 0xF000F0BC */
    SCU_SWDTCTL0_T SCU_SWDTCTL0;

    /* address: 0xF000F0C0 */
    SCU_SWDTCTL1_T SCU_SWDTCTL1;

    /* address: 0xF000F0C4 */
    SCU_SWDTSTA_T SCU_SWDTSTA;

    /* address: 0xF000F0C8 */
    SCU_CPUWDT_T SCU_CPUWDT[2];

    /* address: 0xF000F0E0 */
    SCU_GECTL0_T SCU_GECTL0;

    /* address: 0xF000F0E4 */
    SCU_GECTL1_T SCU_GECTL1;

    /* address: 0xF000F0E8 */
    SCU_GESTA_T SCU_GESTA;

    /* address: 0xF000F0EC */
    SCU_SGECTL0_T SCU_SGECTL0;

    /* address: 0xF000F0F0 */
    SCU_SGECTL1_T SCU_SGECTL1;

    /* address: 0xF000F0F4 */
    SCU_SGESTA_T SCU_SGESTA;

    /* address: 0xF000F0F8 */
    SCU_WAKEUP_T SCU_WAKEUP[2];

    /* address: 0xF000F100 */
    SCU_EIFCTL_T SCU_EIFCTL;

    /* address: 0xF000F104 */
    SCU_EICCTL_T SCU_EICCTL[4];

    /* address: 0xF000F114 */
    SCU_INTFCTL_T SCU_INTFCTL;

    /* address: 0xF000F118 */
    SCU_IGCTL_T SCU_IGCTL[4];

    /* address: 0xF000F128 */
    SCU_EIFSTA_T SCU_EIFSTA;

    /* address: 0xF000F12C */
    SCU_PDRSTA_T SCU_PDRSTA;

    /* address: 0xF000F130 */
    SCU_ERUSEL_T SCU_ERUSEL;

    /* address: 0xF000F134 */
    SCU_ESCTL_T SCU_ESCTL;

    /* address: 0xF000F138 */
    SCU_ESSWCTL_T SCU_ESSWCTL;

    /* address: 0xF000F13C */
    // SCU_LBISTLFSR_T SCU_LBISTLFSR;
    uint8_t SCU_RESERVED_F000F13C[32];

    /* address: 0xF000F140 */
    // SCU_LBISTMISR_T SCU_LBISTMISR;
    uint8_t SCU_RESERVED_F000F140[32];

    /* address: 0xF000F144 */
    CPU_KRST0_T CPU0_KRST0;

    /* address: 0xF000F148 */
    CPU_KRST1_T CPU0_KRST1;

    /* address: 0xF000F14C */
    CPU_KRSTCLR_T CPU0_KRSTCLR;

    /* address: 0xF000F150 */
    CPU_KRST0_T CPU1_KRST0;

    /* address: 0xF000F154 */
    CPU_KRST1_T CPU1_KRST1;

    /* address: 0xF000F158*/
    CPU_KRSTCLR_T CPU1_KRSTCLR;

    /* address: 0xF000F15C */
    SCU_SWDTCTL2_T SCU_SWDTCTL2;

    /* address: 0xF000F160 */
    SCU_CPUWDTCTL2_T SCU_CPU0WDTCTL2;

    /* address: 0xF000F164 */
    SCU_CPUWDTCTL2_T SCU_CPU1WDTCTL2;
} Scu_RegisterMap_t;

#define SCU_ADDR ((uint32_t)0xF000F000)
#define SCU_PTR  ((Scu_RegisterMap_t *)SCU_ADDR)
#define SCU_RM   (*(Scu_RegisterMap_t *)SCU_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
