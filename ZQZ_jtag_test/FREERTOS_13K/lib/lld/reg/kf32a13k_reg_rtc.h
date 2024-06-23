/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_rtc.h
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
 *                              REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2023-12-20  |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_REG_RTC_H_
#define _KF32DA13K_REG_RTC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *         Include Files
 **************************************************************************/
#include <kf_types.h>
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
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁止请求位  */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁止状态  */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] RTC模块版本号  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] RTC模块类型  */
            __I uint32_t MODNUM  :16; /*!< [31:16] RTC模块编号  */
        } bits;
        __I uint32_t reg;
    };
} RTC_INFO_T;

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
            __I uint32_t  RESERVED1 :2;  /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1; /*!< [0:0] 模块复位请求位，与RTC_RST1寄存器的RST位一起使用  */
            __I uint32_t  RSTSTA    :1; /*!< [1:1] 复位状态  */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1; /*!< [0:0] 模块复位请求位，与RTC_RST0寄存器的RST位一起使用  */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_RST1_T;

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
} RTC_RSTCLR_T;

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
} RTC_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN        :1; /*!< [0:0] RTC使能位  */
            __I uint32_t  RESERVED0 :1; /*!< [1:1] 保留位  */
            __I uint32_t  RTOFF     :1; /*!< [2:2] RTC操作关闭 */
            __IO uint32_t CNF       :1; /*!< [3:3]  配置标志 */
            __IO uint32_t HT        :1; /*!< [4:4] 选择小时显示的类型  */
            __I uint32_t  LIF       :1; /*!< [5:5] 闰年指示标志  */
            __IO uint32_t CKTP      :2; /*!< [7:6] RTCCLK时钟源分频选择  */
            __IO uint32_t TSCH      :6; /*!< [13:8] 时间戳通道使能位  */
            __IO uint32_t CLKSEL    :2; /*!< [15:14] RTC时钟源选择位  */
            __I uint32_t  RESERVED1 :3; /*!< [18:16] 保留位  */
            __IO uint32_t SUB1H     :1; /*!< [19:19] 减少1小时  */
            __IO uint32_t ADD1H     :1; /*!< [20:20] 增加1小时  */
            __IO uint32_t TSEN      :1; /*!< [21:21] 时间戳使能  */
            __IO uint32_t TSEDGE    :1; /*!< [22:22] 时间戳触发沿  */
            __I uint32_t  RESERVED2 :1; /*!< [23:23] 保留位  */
            __IO uint32_t CAL       :8; /*!< [31:24] RTC时钟校正位  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_CTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TTWKPEN   :1;  /*!< [0:0] RTC模块TT_OUT唤醒使能  */
            __IO uint32_t TTPRESEN  :1;  /*!< [1:1] RTC模块TT_OUT唤醒分频使能位  */
            __IO uint32_t TTSEL     :2;  /*!< [3:2] RTCTT_OUT唤醒分频选择  */
            __IO uint32_t TT        :3;  /*!< [6:4] 时间节拍设置位  */
            __I uint32_t  RESERVED0 :25; /*!< [31:7] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_TTCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ALRS :7; /*!< [6:0] 设置闹钟中断秒时间(闹钟分的数值为00～59)  */
            __IO uint32_t ASEN :1; /*!< [7:7] 闹钟A秒钟使能  */
            __IO uint32_t ALRM :7; /*!< [14:8] 设置闹钟中断分时间(闹钟分的数值为00～59)  */
            __IO uint32_t AMEN :1; /*!< [15:15] 闹钟A分钟使能  */
            __IO uint32_t ALRH :6; /*!< [21:16] 设置闹钟中断小时时间(闹钟时的数值为00～23)  */
            __IO uint32_t AMPM :1; /*!< [22:22] 12小时制时闹钟A的上午下午选择(24小时制时无效)  */
            __IO uint32_t AHEN :1; /*!< [23:23] 闹钟A时钟使能  */
            __IO uint32_t ALRW :3; /*!< [26:24] 设置闹钟中断星期时间(闹钟星期数值为1～7) */
            __IO uint32_t AWEN :1; /*!< [27:27] 闹钟A周使能  */
            __I uint32_t  RESERVED0 :3; /*!< [30:28] 保留位  */
            __IO uint32_t ALREN     :1; /*!< [31:31] 闹钟A使能位  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_ALR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SEC       :7; /*!< [6:0] RTC时钟秒钟  */
            __I uint32_t  RESERVED0 :1; /*!< [7:7] 保留位  */
            __IO uint32_t MIN       :7; /*!< [14:8] RTC时钟分钟  */
            __I uint32_t  RESERVED1 :1; /*!< [15:15] 保留位  */
            __IO uint32_t HOUR      :6; /*!< [21:16] RTC时钟时钟  */
            __IO uint32_t AMPM :1; /*!< [22:22] 当HT置0选择24小时制时，该位无效。当HT置1选择12小时制时，该位有效。  */
            __I uint32_t  RESERVED2 :1; /*!< [23:23] 保留位  */
            __IO uint32_t WEK       :3; /*!< [26:24] RTC时钟星期  */
            __I uint32_t  RESERVED3 :5; /*!< [31:27] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_TM_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DAY       :6; /*!< [5:0] RTC时钟日期  */
            __I uint32_t  RESERVED0 :2; /*!< [7:6] 保留位  */
            __IO uint32_t MTH       :5; /*!< [12:8] RTC时钟月份  */
            __I uint32_t  RESERVED1 :3; /*!< [15:13] 保留位  */
            __IO uint32_t YEAR      :8; /*!< [23:16] RTC时钟年份  */
            __I uint32_t  RESERVED2 :8; /*!< [31:24] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_DT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TMR0 :16; /*!< [15:0] 定时器0计数值  */
            __IO uint32_t TMR1 :16; /*!< [31:16] 定时器1计数值  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_TIM_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TMR0C     :4;  /*!< [3:0] 定时器0时钟选择位  */
            __IO uint32_t TMR1C     :4;  /*!< [7:4] 定时器1时钟源选择位  */
            __IO uint32_t TMR0EN    :1;  /*!< [8:8] 定时器0使能位  */
            __IO uint32_t TMR1EN    :1;  /*!< [9:9] 定时器1使能位  */
            __I uint32_t  RESERVED0 :22; /*!< [31:10] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_TIMCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SECIE     :1;  /*!< [0:0] 秒进程中断使能位  */
            __IO uint32_t MINIE     :1;  /*!< [1:1] 分进程中断使能位  */
            __IO uint32_t HOURIE    :1;  /*!< [2:2] 小时进程中断使能位  */
            __IO uint32_t DAYIE     :1;  /*!< [3:3] 日进程中断使能位  */
            __IO uint32_t ALRAIE    :1;  /*!< [4:4] 闹钟A中断使能位  */
            __IO uint32_t ALRBIE    :1;  /*!< [5:5] 闹钟B中断使能位  */
            __IO uint32_t TTIE      :1;  /*!< [6:6] 时间节拍中断使能位  */
            __I uint32_t  RESERVED0 :1;  /*!< [7:7] 预留读为0  */
            __IO uint32_t RTCT0IE   :1;  /*!< [8:8] RTC定时器0中断  */
            __IO uint32_t RTCT1IE   :1;  /*!< [9:9] RTC定时器1中断使能位  */
            __IO uint32_t TSOVFIE   :1;  /*!< [10:10] 时间戳溢出中断使能位  */
            __IO uint32_t TSIE      :1;  /*!< [11:11] 时间戳中断使能位  */
            __I uint32_t  RESERVED1 :1;  /*!< [12:12] 预留读为0  */
            __IO uint32_t WEEKIE    :1;  /*!< [13:13] 星期几中断使能位  */
            __IO uint32_t MONTHIE   :1;  /*!< [14:14] 月中断使能位  */
            __IO uint32_t YEARIE    :1;  /*!< [15:15] 年中断使能位  */
            __I uint32_t  RESERVED2 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SECIF     :1;  /*!< [0:0] 秒进程中断标志位  */
            __I uint32_t MINIF     :1;  /*!< [1:1] 分进程中断标志位  */
            __I uint32_t HOURIF    :1;  /*!< [2:2] 小时进程中断标志位  */
            __I uint32_t DAYIF     :1;  /*!< [3:3] 日进程中断标志位  */
            __I uint32_t ALRAIF    :1;  /*!< [4:4] 闹钟A中断标志位  */
            __I uint32_t ALRBIF    :1;  /*!< [5:5] 闹钟B中断标志位  */
            __I uint32_t TTIF      :1;  /*!< [6:6] 时间节拍中断标志位  */
            __I uint32_t RESERVED0 :1;  /*!< [7:7] 预留读为0  */
            __I uint32_t RTCT0IF   :1;  /*!< [8:8] RTC定时器0中断标志位  */
            __I uint32_t RTCT1IF   :1;  /*!< [9:9] RTC定时器1中断标志位  */
            __I uint32_t TSOVFIF   :1;  /*!< [10:10] 时间戳溢出中断标志位  */
            __I uint32_t TSIF      :1;  /*!< [11:11] 时间戳中断标志位  */
            __I uint32_t RESERVED1 :1;  /*!< [12:12] 预留读为0  */
            __I uint32_t WEEKIF    :1;  /*!< [13:13] 星期几中断标志位  */
            __I uint32_t MONTHIF   :1;  /*!< [14:14] 月中断标志位  */
            __I uint32_t YEARIF    :1;  /*!< [15:15] 年中断标志位  */
            __I uint32_t RESERVED2 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t SECIC     :1;  /*!< [0:0] 秒进程中断标志清零位  */
            __O uint32_t MINIC     :1;  /*!< [1:1] 分进程中断标志清零位  */
            __O uint32_t HOURIC    :1;  /*!< [2:2] 小时进程中断标志清零位  */
            __O uint32_t DAYIC     :1;  /*!< [3:3] 日进程中断标志清零位  */
            __O uint32_t ALRAIC    :1;  /*!< [4:4] 闹钟A中断标志清零位  */
            __O uint32_t ALRBIC    :1;  /*!< [5:5] 闹钟B中断标志清零位  */
            __O uint32_t TTIC      :1;  /*!< [6:6] 时间节拍中断标志清零位  */
            __I uint32_t RESERVED0 :1;  /*!< [7:7] 预留读为0  */
            __O uint32_t RTCT0IC   :1;  /*!< [8:8] RTC定时器0中断标志清零位  */
            __O uint32_t RTCT1IC   :1;  /*!< [9:9] RTC定时器1中断标志清零位  */
            __O uint32_t TSOVFIC   :1;  /*!< [10:10] 时间戳溢出中断标志清零位  */
            __O uint32_t TSIC      :1;  /*!< [11:11] 时间戳中断标志清零位  */
            __I uint32_t RESERVED1 :1;  /*!< [12:12] 预留读为0  */
            __O uint32_t WEEKIC    :1;  /*!< [13:13] 星期几中断标志清零位  */
            __O uint32_t MONTHIC   :1;  /*!< [14:14] 月中断标志清零位  */
            __O uint32_t YEARIC    :1;  /*!< [15:15] 年中断标志清零位  */
            __I uint32_t RESERVED2 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_IC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t SECIS     :1;  /*!< [0:0] 秒进程中断标志置1位  */
            __O uint32_t MINIS     :1;  /*!< [1:1] 分进程中断标志置1位  */
            __O uint32_t HOURIS    :1;  /*!< [2:2] 小时进程中断标志置1位  */
            __O uint32_t DAYIS     :1;  /*!< [3:3] 日进程中断标志置1位  */
            __O uint32_t ALRAIS    :1;  /*!< [4:4] 闹钟A中断标志置1位  */
            __O uint32_t ALRBIS    :1;  /*!< [5:5] 闹钟B中断标志置1位  */
            __O uint32_t TTIS      :1;  /*!< [6:6] 时间节拍中断标志置1位  */
            __I uint32_t RESERVED0 :1;  /*!< [7:7] 预留读为0  */
            __O uint32_t RTCT0IS   :1;  /*!< [8:8] RTC定时器0中断标志置1位  */
            __O uint32_t RTCT1IS   :1;  /*!< [9:9] RTC定时器1中断标志置1位  */
            __O uint32_t TSOVFIS   :1;  /*!< [10:10] 时间戳溢出中断标志置1位  */
            __O uint32_t TSIS      :1;  /*!< [11:11] 时间戳中断标志置1位  */
            __I uint32_t RESERVED1 :1;  /*!< [12:12] 预留读为0  */
            __O uint32_t WEEKIS    :1;  /*!< [13:13] 星期几中断标志置1位  */
            __O uint32_t MONTHIS   :1;  /*!< [14:14] 月中断标志置1位  */
            __O uint32_t YEARIS    :1;  /*!< [15:15] 年中断标志置1位  */
            __I uint32_t RESERVED2 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_IS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SECB      :7; /*!< [6:0] RTC时钟秒钟备份  */
            __I uint32_t RESERVED0 :1; /*!< [7:7] 预留读为0  */
            __I uint32_t MINB      :7; /*!< [14:8] RTC时钟分钟备份  */
            __I uint32_t RESERVED1 :1; /*!< [15:15] 预留读为0  */
            __I uint32_t HOURB     :6; /*!< [21:16] RTC时钟时钟备份  */
            __I uint32_t AMPMB     :1; /*!< [22:22] AM/PM备份  */
            __I uint32_t RESERVED2 :1; /*!< [23:23] 预留读为0  */
            __I uint32_t WEKB      :3; /*!< [26:24] RTC时钟星期备份  */
            __I uint32_t RESERVED3 :5; /*!< [31:27] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_TMB_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t DAYB      :6; /*!< [5:0] RTC时钟日期备份  */
            __I uint32_t RESERVED0 :2; /*!< [7:6] 预留读为0  */
            __I uint32_t MTHB      :5; /*!< [12:8] RTC时钟月份备份  */
            __I uint32_t RESERVED1 :3; /*!< [15:13] 预留读为0  */
            __I uint32_t YEARB     :8; /*!< [23:16] RTC时钟年份备份  */
            __I uint32_t RESERVED2 :8; /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_DTB_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0   :24; /*!< [23:0] 预留读为0  */
            __IO uint32_t FASTTESTEN  :1;  /*!< [24:24] 快速测试总使能位  */
            __I uint32_t  RESERVED1   :1;  /*!< [25:25] 预留读为0  */
            __IO uint32_t MINTESTEN   :1;  /*!< [26:26] 分快速测试使能位  */
            __IO uint32_t HOURTESTEN  :1;  /*!< [27:27] 小时快速测试使能位  */
            __IO uint32_t DAYTESTEN   :1;  /*!< [28:28] 天快速测试使能位  */
            __IO uint32_t WEEKTESTEN  :1;  /*!< [29:29] 星期几快速测试使能位  */
            __IO uint32_t MONTHTESTEN :1;  /*!< [30:30] 月快速测试使能位  */
            __IO uint32_t YEARTESTEN  :1;  /*!< [31:31] 年快速测试使能位  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_FASTEST_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DIV       :16; /*!< [15:0] 分频系数为DIV。若DIV为0，分频系数为1.  */
            __I uint32_t  RESERVED0 :16; /*!< [31:16] 预留读为0.  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_CLKDIV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CLKTESTEN :1;  /*!< [0:0] RTC工作时钟测试使能位  */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_CLKTEST_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TMEN      :1;  /*!< [0:0] 测试模式使能位  */
            __IO uint32_t TMSEL     :3;  /*!< [3:1] 测试模式输出选择位  */
            __I uint32_t  RESERVED0 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} RTC_TESTMODE_T;

typedef volatile struct
{
    /* offset  : 0x0000.  */
    RTC_CLKC_T RTC_CLKC;

    /* offset  : 0x0004.  */
    RTC_INFO_T RTC_INFO;

    /* offset  : 0x0008.  */
    RTC_DBG_T RTC_DBG;

    /* offset  : 0x000C.  */
    RTC_RST0_T RTC_RST0;

    /* offset  : 0x0010.  */
    RTC_RST1_T RTC_RST1;

    /* offset  : 0x0014.  */
    RTC_RSTCLR_T RTC_RSTCLR;

    /* offset  : 0x0018.  */
    RTC_ACES0_T RTC_ACES0;

    /* offset  : 0x001C.  */
    RTC_ACES1_T RTC_ACES1;

    /* offset  : 0x0020.  */
    RTC_CTL_T RTC_CTL;

    /* offset  : 0x0024.  */
    RTC_TTCTL_T RTC_TTCTL;

    /* offset  : 0x0028.  */
    RTC_ALR_T RTC_ALR[2];

    /* offset  : 0x0030.  */
    RTC_TM_T RTC_TM;

    /* offset  : 0x0034.  */
    RTC_DT_T RTC_DT;

    /* offset  : 0x0038.  */
    RTC_TIM_T RTC_TIM;

    /* offset  : 0x003C.  */
    RTC_TIMCTL_T RTC_TIMCTL;

    /* offset  : 0x0040.  */
    RTC_IE_T RTC_IE;

    /* offset  : 0x0044.  */
    RTC_IF_T RTC_IF;

    /* offset  : 0x0048.  */
    RTC_IC_T RTC_IC;

    /* offset  : 0x004C.  */
    RTC_IS_T RTC_IS;

    /* offset  : 0x0050.  */
    RTC_TMB_T RTC_TMB;

    /* offset  : 0x0054.  */
    RTC_DTB_T RTC_DTB;

    /* offset  : 0x0058.  */
    RTC_FASTEST_T RTC_FASTEST;

    /* offset  : 0x005C.  */
    RTC_CLKDIV_T RTC_CLKDIV;

    /* offset  : 0x0060.  */
    RTC_CLKTEST_T RTC_CLKTEST;

    /* offset  : 0x0064.  */
    RTC_TESTMODE_T RTC_TMODE;
} Rtc_RegisterMap_t;

#define RTC_ADDR ((uint32_t)0xF0023000)
#define RTC_PTR  ((Rtc_RegisterMap_t *)RTC_ADDR)
#define RTC_RM   (*(Rtc_RegisterMap_t *)RTC_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
