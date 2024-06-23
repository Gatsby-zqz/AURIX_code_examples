/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_psi5.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-18
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
 *  |2023-12-18  |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef KF32A13K_REG_PSI5_H_
#define KF32A13K_REG_PSI5_H_

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
            __IO uint32_t DISR     :1;  /*!< [0:0] 模块禁用请求。  */
            __I uint32_t  DISS     :1;  /*!< [1:1] 模块禁用状态位。  */
            __IO uint32_t EDIS     :1;  /*!< [2:2] 休眠模式请求。  */
            __IO uint32_t RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DBGCTL   :4;  /*!< [3:0] OCDS挂起控制位。  */
            __O uint32_t  DBGP     :1;  /*!< [4:4] DBGCTL写保护。  */
            __I uint32_t  DBGSTA   :1;  /*!< [5:5] 模块挂起状态。  */
            __IO uint32_t RESERVED0 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST      :1;  /*!< [0:0] 模块复位请求，与RST1_RST一起使用  */
            __I uint32_t  RSTSTA   :1;  /*!< [1:1] 复位状态。  */
            __IO uint32_t RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST      :1;  /*!< [0:0] 模块复位请求  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  CLR      :1;  /*!< [0:0] RSTSTA复位状态清除，该位自动清零。  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_RSTCLR_T;

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
} PSI5_ACES0_T;

typedef volatile struct
{
    __IO uint32_t reg; /*!< [31:0] 预留读为0  */
} PSI5_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] 模块版本01H  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] 模块类型07H  */
            __I uint32_t MODNUM  :16; /*!< [31:16] 模块ID0012H  */
        } bits;
        __I uint32_t reg;
    };
} PSI5_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STEP      :10; /*!< [9:0] 用于计算时钟分频值  */
            __IO uint32_t RESERVED0  :4;  /*!< [13:10] 预留读为0  */
            __IO uint32_t DVIMOD    :2;  /*!< [15:14] 分频模式选择  */
            __I uint32_t  RESULT    :10; /*!< [25:16] 额外结果位  */
            __IO uint32_t RESERVED1 :6;  /*!< [31:26] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_FDR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STEP      :10; /*!< [9:0] 用于计算时钟分频值  */
            __IO uint32_t RESERVED0  :4;  /*!< [13:10] 预留读为0  */
            __IO uint32_t DVIMOD    :2;  /*!< [15:14] 分频模式选择  */
            __I uint32_t  RESULT    :10; /*!< [25:16] 额外结果位  */
            __IO uint32_t RESERVED1 :6;  /*!< [31:26] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_FDRL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STEP      :10; /*!< [9:0] 用于计算时钟分频值  */
            __IO uint32_t RESERVED0  :4;  /*!< [13:10] 预留读为0  */
            __IO uint32_t DVIMOD    :2;  /*!< [15:14] 分频模式选择  */
            __I uint32_t  RESULT    :10; /*!< [25:16] 额外结果位  */
            __IO uint32_t RESERVED1 :6;  /*!< [31:26] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_FDRH_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STEP     :10; /*!< [9:0] 用于计算时钟分频值  */
            __IO uint32_t RESERVED0 :4;  /*!< [13:10] 预留读为0  */
            __IO uint32_t DVIMOD   :2;  /*!< [15:14] 分频模式选择  */
            __I uint32_t  RESULT   :10; /*!< [25:16] 额外结果位  */
            __IO uint32_t ECS      :3;  /*!< [28:26]  */
            __IO uint32_t ECEA     :1;  /*!< [29:29]  */
            __IO uint32_t ECEB     :1;  /*!< [30:30]  */
            __IO uint32_t ECEC     :1;  /*!< [31:31]  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_FDRT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  CTS      :24; /*!< [23:0] 该位显示实时时间戳；  */
            __IO uint32_t ETBSEL   :3;  /*!< [26:24] 外部时基选择；  */
            __IO uint32_t TBSEL    :1;  /*!< [27:27] 时基选择； */
            __IO uint32_t RESERVED0 :2;  /*!< [29:28] 预留读为0  */
            __O uint32_t  TSCLR    :1;  /*!< [30:30] 清零所有实时时间戳计数器； */
            __O uint32_t  CTCNTCLR :1;  /*!< [31:31] 如果被配置，该位将会清零CTS；*/
        } bits;
        __IO uint32_t reg;
    };
} PSI5_TSR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RSIFSOURCE :5;  /*!< [4:4] 设置RSIF源标志位  */
            __IO uint32_t RESERVED0   :3;  /*!< [7:5] 预留读为0  */
            __IO uint32_t CTCNTEN0   :1;  /*!< [8:8] 使能通道触发计数器CTVx.CTCNT  */
            __IO uint32_t CTCNTEN1   :1;  /*!< [9:9] 使能通道触发计数器CTVx.CTCNT  */
            __IO uint32_t CTCNTEN2   :1;  /*!< [10:10] 使能通道触发计数器CTVx.CTCNT  */
            __IO uint32_t CTCNTEN3   :1;  /*!< [11:11] 使能通道触发计数器CTVx.CTCNT  */
            __IO uint32_t CTCNTEN4   :1;  /*!< [12:12] 使能通道触发计数器CTVx.CTCNT  */
            __IO uint32_t RESERVED1  :3;  /*!< [15:13] 预留读为0  */
            __IO uint32_t CEN0       :1;  /*!< [16:16] 通道使能；该位使能PSI5通道0 */
            __IO uint32_t CEN1       :1;  /*!< [17:17] 通道使能；该位使能PSI5通道0 */
            __IO uint32_t CEN2       :1;  /*!< [18:18] 通道使能；该位使能PSI5通道0 */
            __IO uint32_t CEN3       :1;  /*!< [19:19] 通道使能；该位使能PSI5通道0 */
            __IO uint32_t CEN4       :1;  /*!< [20:20] 通道使能；该位使能PSI5通道0 */
            __IO uint32_t RESERVED2  :11; /*!< [31:21] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_GCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RSIF     :1;  /*!< [0:0] RSIF中断标志 */
            __I uint32_t RDIF     :1;  /*!< [1:1] RDIF中断标志 */
            __I uint32_t RBIF     :1;  /*!< [2:2] RBIF中断标志*/
            __I uint32_t TDIF     :1;  /*!< [3:3] TDIF中断标志 */
            __I uint32_t TBIF     :1;  /*!< [4:4] TBIF中断标志 */
            __I uint32_t ERRIF    :1;  /*!< [5:5] ERRIF中断标志 */
            __I uint32_t SDIF     :1;  /*!< [6:6] SDIF中断标志 */
            __I uint32_t FWIF     :1;  /*!< [7:7] FWIF中断标志 */
            __I uint32_t RESERVED0 :24; /*!< [31:8] 预留读为0  */
        } bits;
        __I uint32_t reg;
    };
} PSI5_GIF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t INSEL     :2;  /*!< [1:0] 备用输入选择  */
            __IO uint32_t RESERVED0  :2;  /*!< [3:2] 预留读为0  */
            __IO uint32_t DEPTH     :4;  /*!< [7:4] 数字滤波器深度  */
            __IO uint32_t OPOLSEL   :1;  /*!< [8:8] 通道x输出翻转使能  */
            __IO uint32_t IPOLSEL   :1;  /*!< [8:8] 通道x输入翻转使能  */
            __IO uint32_t RESERVED1 :2;  /*!< [11:10] 预留读为0  */
            __I uint32_t  REGF      :1;  /*!< [12:12] 通道x上升沿干扰标志  */
            __I uint32_t  FEGF      :1;  /*!< [13:13] 通道x下降沿干扰标志  */
            __O uint32_t  CREGF     :1;  /*!< [14:14] 清零通道x上升沿干扰标志  */
            __O uint32_t  CFEGF     :1;  /*!< [15:15] 清零通道x下降沿干扰标志  */
            __IO uint32_t RESERVED2 :14; /*!< [29:16] 预留读为0  */
            __I uint32_t  RXM       :1;  /*!< [30:30] 通道x接收监控  */
            __I uint32_t  TXM       :1;  /*!< [31:31] 通道x发送监控  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_IOCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PDL0   :5; /*!< [4:0] 负载数据长度  */
            __IO uint32_t PDL1   :5; /*!< [9:5] 负载数据长度  */
            __IO uint32_t PDL2   :5; /*!< [14:10] 负载数据长度  */
            __IO uint32_t PDL3   :5; /*!< [19:15] 负载数据长度  */
            __IO uint32_t PDL4   :5; /*!< [24:20] 负载数据长度  */
            __IO uint32_t PDL5   :5; /*!< [29:25] 负载数据长度  */
            __IO uint32_t ASYNEN :1; /*!< [30:30] 异步模式 */
            __IO uint32_t AVBSEN :1; /*!< [30:30] 异步模式的冗余模式  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_RCTLA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t MSGEN0   :1; /*!< [0:0] 消息位 */
            __IO uint32_t CRCSEL0  :1; /*!< [1:1] CRC或者奇偶校验选择 */
            __IO uint32_t FECEN0   :1; /*!< [2:2] 帧期待控制 */
            __IO uint32_t VBSEN0   :1; /*!< [3:3] 冗余模式 */
            __IO uint32_t MSGEN1   :1; /*!< [4:4] 消息位 */
            __IO uint32_t CRCSEL1  :1; /*!< [5:5] CRC或者奇偶校验选择 */
            __IO uint32_t FECEN1   :1; /*!< [6:6] 帧期待控制 */
            __IO uint32_t VBSEN1   :1; /*!< [7:7] 冗余模式 */
            __IO uint32_t MSGEN2   :1; /*!< [8:8] 消息位 */
            __IO uint32_t CRCSEL2  :1; /*!< [9:9] CRC或者奇偶校验选择 */
            __IO uint32_t FECEN2   :1; /*!< [10:10] 帧期待控制 */
            __IO uint32_t VBSEN2   :1; /*!< [11:11] 冗余模式 */
            __IO uint32_t MSGEN3   :1; /*!< [12:12] 消息位 */
            __IO uint32_t CRCSEL3  :1; /*!< [13:13] CRC或者奇偶校验选择 */
            __IO uint32_t FECEN3   :1; /*!< [14:14] 帧期待控制 */
            __IO uint32_t VBSEN3   :1; /*!< [15:15] 冗余模式 */
            __IO uint32_t MSGEN4   :1; /*!< [16:16] 消息位 */
            __IO uint32_t CRCSEL4  :1; /*!< [17:17] CRC或者奇偶校验选择 */
            __IO uint32_t FECEN4   :1; /*!< [18:18] 帧期待控制 */
            __IO uint32_t VBSEN4   :1; /*!< [19:19] 冗余模式 */
            __IO uint32_t MSGEN5   :1; /*!< [20:20] 消息位 */
            __IO uint32_t CRCSEL5  :1; /*!< [21:21] CRC或者奇偶校验选择 */
            __IO uint32_t FECEN5   :1; /*!< [22:22] 帧期待控制 */
            __IO uint32_t VBSEN5   :1; /*!< [23:23] 冗余模式 */
            __I uint32_t  RESERVED0 :8; /*!< [31:24]  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_RCTLB_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BRSEL    :1;  /*!< [0:0] 比特速率选择 */
            __IO uint32_t TSPSEL   :2;  /*!< [2:1] 脉冲时间戳选择 */
            __IO uint32_t TSFSEL   :2;  /*!< [4:3] 帧起始时间戳选择 */
            __IO uint32_t TSRSEL   :1;  /*!< [5:5] 接收数据寄存器中存储时间戳选择 */
            __I uint32_t  RESERVED0 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_RCTLC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t WDL      :16; /*!< [15:0] 看门狗定时器限制 */
            __I uint32_t  RESERVED0 :16; /*!< [31:16] 预留读为0 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_WDT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CRC       :3;  /*!< [2:0] 上一帧CRC，CRC0位于bit0 */
            __I uint32_t RESERVED0  :5;  /*!< [7:3] 预留读为0 */
            __I uint32_t MSG       :2;  /*!< [9:8] 上一帧MSG，MSG0位于bit8 */
            __I uint32_t RESERVED1 :22; /*!< [31:10] 预留读为0 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_REVSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SD    :16; /*!< [15:0] 串行数据 */
            __I uint32_t MSGID :8;  /*!< [23:16] 消息ID */
            __I uint32_t SCRC  :6;  /*!< [29:24] 上一帧串行数据的CRC */
            __I uint32_t SCRIF :1;  /*!< [30:30] 串行消息CRC校验失败中断标志 */
            __I uint32_t CON   :1;  /*!< [31:31] 配置位，上一帧串行帧 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_SDSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t TS       :24; /*!< [23:0] 时间戳 */
            __I uint32_t RESERVED0 :8;  /*!< [31:24] 预留读为0 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_SPTSC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t TS       :24; /*!< [23:0] 时间戳 */
            __I uint32_t RESERVED0 :8;  /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_SFTSC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CRCIF :1;  /*!< [0:0] CRC校验错误标志 */
            __I uint32_t CRC   :3;  /*!< [3:1] 上一帧CRC/奇偶校验 */
            __I uint32_t RD    :28; /*!< [31:4] 上一个PSI5帧中的接收数据 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_RDATL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t TS   :24; /*!< [23:0] 时间戳 */
            __I uint32_t SC   :3;  /*!< [26:24] Slot计数器 */
            __I uint32_t TEIF :1;  /*!< [27:27] 时间槽错误标志 */
            __I uint32_t NBIF :1;  /*!< [28:28] 比特数目错误标志 */
            __I uint32_t MEIF :1;  /*!< [29:29] 消息位错误标志 */
            __I uint32_t NFIF :1;  /*!< [30:30] 无帧接收标志 */
            __I uint32_t RBIF :1;  /*!< [31:31] 接收缓冲器溢出标志 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_RDATH_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PLEN      :6; /*!< [5:0] 脉冲长度 */
            __I uint32_t  RESERVED0  :2; /*!< [7:6] 预留读为0 */
            __IO uint32_t DLY       :6; /*!< [13:8] 延时长度 */
            __I uint32_t  RESERVED1 :1; /*!< [14:14] 预留读为0 */
            __IO uint32_t TBSEL     :1; /*!< [15:15] 时基选择 */
            __IO uint32_t ETBSEL    :3; /*!< [18:16] 外部时基选择 */
            __IO uint32_t PTEN      :1; /*!< [19:19] 周期触发使能 */
            __IO uint32_t ETSEL     :3; /*!< [22:20] 外部触发源选择 */
            __IO uint32_t ETEN      :1; /*!< [23:23] 外部触发使能 */
            __IO uint32_t BYP       :1; /*!< [24:24] 外部信号 */
            __IO uint32_t BOT       :7; /*!< [31:25] 空白时间 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_PCTRL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CTV   :16; /*!< [15:0] 通道触发值CTV */
            __IO uint32_t CTCNT :16; /*!< [31:16] 通道触发计数器 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_CTV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PLLEN    :6; /*!< [5:0] SDRL/H中有效负载长度 */
            __IO uint32_t EPSEL    :1; /*!< [6:6] 协议选择 */
            __IO uint32_t BSCTL    :1; /*!< [7:7] 同步位控制 */
            __IO uint32_t SSLEN    :6; /*!< [13:8] 寄存器SSRL/H中有效负载长度 */
            __O uint32_t  FLUS     :1; /*!< [14:14] 刷新SSRH/L寄存器 */
            __O uint32_t  FLUO     :1; /*!< [15:15] 刷新SSOH/L寄存器 */
            __IO uint32_t SOLEN    :6; /*!< [21:16] SSOL/H中有效负载长度 */
            __IO uint32_t CRCCTRL  :1; /*!< [22:22] CRC生成控制 */
            __IO uint32_t STACTRL  :1; /*!< [23:23] 起始序列生成控制 */
            __IO uint32_t INH      :1; /*!< [24:24] 禁止传输 */
            __O uint32_t  GO       :1; /*!< [25:25] 释放准备好的数据 */
            __I uint32_t  TPF      :1; /*!< [26:26] 传输准备标志位 */
            __I uint32_t  TSF      :1; /*!< [27:27] 传输移位标志位 */
            __I uint32_t  TOF      :1; /*!< [28:28] 传输输出标志 */
            __I uint32_t  RESERVED0 :2; /*!< [30:29] 预留读为0 */
            __I uint32_t  TRQ      :1; /*!< [31:31] 传输请求正在进行中 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_SCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SD :32; /*!< [31:0] 下一个ECUtoSensor帧 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_SDRL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SD :32; /*!< [31:0] 下一个ECUtoSensor帧 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_SDRH_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SD :32; /*!< [31:0] 下一个发送数据ECUtoSensor帧 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_SSRL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SD :32; /*!< [31:0] 下一个发送数据ECUtoSensor帧 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_SSRH_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SD :32; /*!< [31:0] 下一个发送数据ECUtoSensor帧 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_SORL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SD :32; /*!< [31:0] 下一个发送数据ECUtoSensor帧 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_SORH_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RSIF  :4; /*!< [3:0] RSIF中断节点选择 */
            __IO uint32_t RDIF  :4; /*!< [7:4] RDIF中断节点选择 */
            __IO uint32_t RBIF  :4; /*!< [11:8] RBIF中断节点选择 */
            __IO uint32_t TDIF  :4; /*!< [15:12] TDIF中断节点选择 */
            __IO uint32_t TBIF  :4; /*!< [19:16] TBIF中断节点选择 */
            __IO uint32_t ERRIF :4; /*!< [23:20] ERRIF中断节点选择 */
            __IO uint32_t SDIF  :4; /*!< [27:24] SDIF中断节点选择 */
            __IO uint32_t FWIF  :4; /*!< [31:28] FWIF中断节点选择 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_INP_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RSIF     :1;  /*!< [0:0] 接收成功中断请求标志 */
            __I uint32_t RDIF     :1;  /*!< [1:1] 接收数据中断请求标志 */
            __I uint32_t RBIF     :1;  /*!< [2:2] 接收缓冲器溢出中断请求标志 */
            __I uint32_t TEIF     :1;  /*!< [3:3] 时间槽错误中断请求标志 */
            __I uint32_t NBIF     :1;  /*!< [4:4] 比特数目错误中断请求标志 */
            __I uint32_t MEIF     :1;  /*!< [5:5] 消息位错误标志 */
            __I uint32_t CRCIF    :1;  /*!< [6:6] CRC错误请求标志 */
            __I uint32_t FWIF     :1;  /*!< [7:7] FIFO警告等级请求标志 */
            __I uint32_t RUIF     :1;  /*!< [8:8] 接收存储器下溢中断请求标志 */
            __I uint32_t RMIF     :1;  /*!< [9:9] 接收存储器上溢标志 */
            __I uint32_t TPIF     :1;  /*!< [10:10] 传输准备中断请求标志 */
            __I uint32_t TPOIF    :1;  /*!< [11:11] 传输准备溢出中断请求标志 */
            __I uint32_t TSIF     :1;  /*!< [12:12] 传输移位中断请求标志 */
            __I uint32_t TSOIF    :1;  /*!< [13:13] 传输移位溢出中断请求标志 */
            __I uint32_t TOIF     :1;  /*!< [14:14] 传输输出中断请求标志 */
            __I uint32_t TOOIF    :1;  /*!< [15:15] 传输输出溢出中断请求标志 */
            __I uint32_t NFIF     :1;  /*!< [16:16] 无帧接收中断标志 */
            __I uint32_t RESERVED0 :15; /*!< [31:17] 预留读为0 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_IF1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t WSIF0    :1; /*!< [0:0] 错误串行协议请求标志 */
            __I uint32_t WSIF1    :1; /*!< [1:1] 错误串行协议请求标志 */
            __I uint32_t WSIF2    :1; /*!< [2:2] 错误串行协议请求标志 */
            __I uint32_t WSIF3    :1; /*!< [3:3] 错误串行协议请求标志 */
            __I uint32_t WSIF4    :1; /*!< [4:4] 错误串行协议请求标志  */
            __I uint32_t WSIF5    :1; /*!< [5:5] 错误串行协议请求标志 */
            __I uint32_t SDIF0    :1; /*!< [6:6] 串行数据接收中断请求标志 */
            __I uint32_t SDIF1    :1; /*!< [7:7] 串行数据接收中断请求标志 */
            __I uint32_t SDIF2    :1; /*!< [8:8] 串行数据接收中断请求标志 */
            __I uint32_t SDIF3    :1; /*!< [9:9] 串行数据接收中断请求标志 */
            __I uint32_t SDIF4    :1; /*!< [10:10] 串行数据接收中断请求标志 */
            __I uint32_t SDIF5    :1; /*!< [11:11] 串行数据接收中断请求标志 */
            __I uint32_t SOIF0    :1; /*!< [12:12] 串行数据缓冲器溢出中断请求标志 */
            __I uint32_t SOIF1    :1; /*!< [13:13] 串行数据缓冲器溢出中断请求标志 */
            __I uint32_t SOIF2    :1; /*!< [14:14] 串行数据缓冲器溢出中断请求标志 */
            __I uint32_t SOIF3    :1; /*!< [15:15] 串行数据缓冲器溢出中断请求标志 */
            __I uint32_t SOIF4    :1; /*!< [16:16] 串行数据缓冲器溢出中断请求标志 */
            __I uint32_t SOIF5    :1; /*!< [17:17] 串行数据缓冲器溢出中断请求标志 */
            __I uint32_t SCRIF0   :1; /*!< [18:18] 串行数据CRC错误请求标志 */
            __I uint32_t SCRIF1   :1; /*!< [19:19] 串行数据CRC错误请求标志 */
            __I uint32_t SCRIF2   :1; /*!< [20:20] 串行数据CRC错误请求标志 */
            __I uint32_t SCRIF3   :1; /*!< [21:21] 串行数据CRC错误请求标志 */
            __I uint32_t SCRIF4   :1; /*!< [22:22] 串行数据CRC错误请求标志 */
            __I uint32_t SCRIF5   :1; /*!< [23:23] 串行数据CRC错误请求标志 */
            __I uint32_t RESERVED0 :8; /*!< [31:24] 预留读为0 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_IF2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t SRSIF :1; /*!< [0:0] 该位置位将置位IF1.RSIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SRDIF :1; /*!< [1:1] 该位置位将置位IF1.RDIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SRBIF :1; /*!< [2:2] 该位置位将置位IF1.RBIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STEIF :1; /*!< [3:3] 该位置位将置位IF1.TEIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SNBIF :1; /*!< [4:4] 该位置位将置位IF1.NBIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SMEIF :1; /*!< [5:5] 该位置位将置位IF1.MEIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SCRCIF :1; /*!< [6:6] 该位置位将置位IF1.CRCIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SFWIF :1; /*!< [7:7] 该位置位将置位IF1.FWIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SRUIF :1; /*!< [8:8] 该位置位将置位IF1.RUIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SRMIF :1; /*!< [9:9] 该位置位将置位IF1.RMIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STPIF :1; /*!< [10:10] 该位置位将置位IF1.TPIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STPOIF :1; /*!< [11:11] 该位置位将置位IF1.TPOIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STSIF :1; /*!< [12:12] 该位置位将置位IF1.TSIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STSOIF :1; /*!< [13:13] 该位置位将置位IF1.TSOIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STOIF :1; /*!< [14:14] 该位置位将置位IF1.TOIF；该位清零没有影响；读该位为0  */
            __O uint32_t STOOIF :1; /*!< [15:15] 该位置位将置位IF1.TOOIF；该位清零没有影响；读该位为0  */
            __O uint32_t SNFIF :1; /*!< [16:16] 该位置位将置位IF1.NFIF；该位清零没有影响；读该位为0；  */
            __I uint32_t RESERVED0 :15; /*!< [31:17] 预留读为0 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_IS1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t SRSIF :1; /*!< [0:0] 该位置位将置位IF1.RSIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SRDIF :1; /*!< [1:1] 该位置位将置位IF1.RDIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SRBIF :1; /*!< [2:2] 该位置位将置位IF1.RBIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STEIF :1; /*!< [3:3] 该位置位将置位IF1.TEIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SNBIF :1; /*!< [4:4] 该位置位将置位IF1.NBIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SMEIF :1; /*!< [5:5] 该位置位将置位IF1.MEIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SCRCIF :1; /*!< [6:6] 该位置位将置位IF1.CRCIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SFWIF :1; /*!< [7:7] 该位置位将置位IF1.FWIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SRUIF :1; /*!< [8:8] 该位置位将置位IF1.RUIF；该位清零没有影响；读该位为0；  */
            __O uint32_t SRMIF :1; /*!< [9:9] 该位置位将置位IF1.RMIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STPIF :1; /*!< [10:10] 该位置位将置位IF1.TPIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STPOIF :1; /*!< [11:11] 该位置位将置位IF1.TPOIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STSIF :1; /*!< [12:12] 该位置位将置位IF1.TSIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STSOIF :1; /*!< [13:13] 该位置位将置位IF1.TSOIF；该位清零没有影响；读该位为0；  */
            __O uint32_t STOIF :1; /*!< [14:14] 该位置位将置位IF1.TOIF；该位清零没有影响；读该位为0  */
            __O uint32_t STOOIF :1; /*!< [15:15] 该位置位将置位IF1.TOOIF；该位清零没有影响；读该位为0  */
            __O uint32_t SNFIF :1; /*!< [16:16] 该位置位将置位IF1.NFIF；该位清零没有影响；读该位为0；  */
            __IO uint32_t RESERVED0 :15; /*!< [31:17] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_IS2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t RSIC :1; /*!< [0:0] 该位置位将清零IF1.RSIF；该位清零没有影响；读该位为0；  */
            __O uint32_t RDIC :1; /*!< [1:1] 该位置位将清零IF1.RDIF；该位清零没有影响；读该位为0；  */
            __O uint32_t RBIC :1; /*!< [2:2] 该位置位将清零IF1.RBIF；该位清零没有影响；读该位为0；  */
            __O uint32_t TEIC :1; /*!< [3:3] 该位置位将清零IF1.TEIF；该位清零没有影响；读该位为0；  */
            __O uint32_t NBIC :1; /*!< [4:4] 该位置位将清零IF1.NBIF；该位清零没有影响；读该位为0；  */
            __O uint32_t MEIC :1; /*!< [5:5] 该位置位将清零IF1.MEIF；该位清零没有影响；读该位为0；  */
            __O uint32_t CRCIC :1; /*!< [6:6] 该位置位将清零IF1.CRCIF；该位清零没有影响；读该位为0；  */
            __O uint32_t FWIC :1; /*!< [7:7] 该位置位将清零IF1.FWIF；该位清零没有影响；读该位为0；  */
            __O uint32_t RUIC :1; /*!< [8:8] 该位置位将清零IF1.RUIF；该位清零没有影响；读该位为0；  */
            __O uint32_t RMIC :1; /*!< [9:9] 该位置位将清零IF1.RMIF；该位清零没有影响；读该位为0；  */
            __O uint32_t TPIC :1; /*!< [10:10] 该位置位将清零IF1.TPIF；该位清零没有影响；读该位为0；  */
            __O uint32_t TPOIC :1; /*!< [11:11] 该位置位将清零IF1.TPOIF；该位清零没有影响；读该位为0；  */
            __O uint32_t TSIC :1; /*!< [12:12] 该位置位将清零IF1.TSIF；该位清零没有影响；读该位为0；  */
            __O uint32_t TSOIC :1; /*!< [13:13] 该位置位将清零IF1.TSOIF；该位清零没有影响；读该位为0；  */
            __O uint32_t TOIC :1; /*!< [14:14] 该位置位将清零IF1.TOIF；该位清零没有影响；读该位为0；  */
            __O uint32_t TOOIC :1; /*!< [15:15] 该位置位将清零IF1.TOOIF；该位清零没有影响；读该位为0；  */
            __O uint32_t NFIC :1; /*!< [16:16] 该位置位将清零IF1.NFIF；该位清零没有影响；读该位为0；  */
            __IO uint32_t RESERVED0 :15; /*!< [31:17] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_IC1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  WSIC0    :1; /*!< [0:0] 该位被置位之后，IF3.WSIFy将会被清零；  */
            __O uint32_t  WSIC1    :1; /*!< [1:1] 该位被置位之后，IF3.WSIFy将会被清零；  */
            __O uint32_t  WSIC2    :1; /*!< [2:2] 该位被置位之后，IF3.WSIFy将会被清零；  */
            __O uint32_t  WSIC3    :1; /*!< [3:3] 该位被置位之后，IF3.WSIFy将会被清零；  */
            __O uint32_t  WSIC4    :1; /*!< [4:4] 该位被置位之后，IF3.WSIFy将会被清零；  */
            __O uint32_t  WSIC5    :1; /*!< [5:5] 该位被置位之后，IF3.WSIFy将会被清零；  */
            __O uint32_t  SDIC0    :1; /*!< [6:6] 该位被置位之后，IF3.SDIFy将会被清零；  */
            __O uint32_t  SDIC1    :1; /*!< [7:7] 该位被置位之后，IF3.SDIFy将会被清零；  */
            __O uint32_t  SDIC2    :1; /*!< [8:8] 该位被置位之后，IF3.SDIFy将会被清零；  */
            __O uint32_t  SDIC3    :1; /*!< [9:9] 该位被置位之后，IF3.SDIFy将会被清零；  */
            __O uint32_t  SDIC4    :1; /*!< [10:10] 该位被置位之后，IF3.SDIFy将会被清零；  */
            __O uint32_t  SDIC5    :1; /*!< [11:11] 该位被置位之后，IF3.SDIFy将会被清零；  */
            __O uint32_t  SOIC0    :1; /*!< [12:12] 该位被置位之后，IF3.SOIFy将会被清零；  */
            __O uint32_t  SOIC1    :1; /*!< [13:13] 该位被置位之后，IF3.SOIFy将会被清零；  */
            __O uint32_t  SOIC2    :1; /*!< [14:14] 该位被置位之后，IF3.SOIFy将会被清零；  */
            __O uint32_t  SOIC3    :1; /*!< [15:15] 该位被置位之后，IF3.SOIFy将会被清零；  */
            __O uint32_t  SOIC4    :1; /*!< [16:16] 该位被置位之后，IF3.SOIFy将会被清零；  */
            __O uint32_t  SOIC5    :1; /*!< [17:17] 该位被置位之后，IF3.SOIFy将会被清零；  */
            __O uint32_t  SCRIC0   :1; /*!< [18:18] 该位被置位之后，IF3.SCRIFy将会被清零；  */
            __O uint32_t  SCRIC1   :1; /*!< [19:19] 该位被置位之后，IF3.SCRIFy将会被清零；  */
            __O uint32_t  SCRIC2   :1; /*!< [20:20] 该位被置位之后，IF3.SCRIFy将会被清零；  */
            __O uint32_t  SCRIC3   :1; /*!< [21:21] 该位被置位之后，IF3.SCRIFy将会被清零；  */
            __O uint32_t  SCRIC4   :1; /*!< [22:22] 该位被置位之后，IF3.SCRIFy将会被清零；  */
            __O uint32_t  SCRIC5   :1; /*!< [23:23] 该位被置位之后，IF3.SCRIFy将会被清零；  */
            __IO uint32_t RESERVED0 :8; /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_IC2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RSIE :1; /*!< [0:0] 使能RSIF中断请求:0:RSIF不可产生中断请求。1:RSIF可以产生中断请求。  */
            __IO uint32_t RDIE :1; /*!< [1:1] 使能RDIF中断请求:0:RDIF不可产生中断请求。1:RDIF可以产生中断请求。  */
            __IO uint32_t RBIE :1; /*!< [2:2] 使能RBIF中断请求:0:RBIF不可产生中断请求。1:RBIF可以产生中断请求。  */
            __IO uint32_t TEIE :1; /*!< [3:3] 使能TEIF中断请求:0:TEIF不可产生中断请求。1:TEIF可以产生中断请求。  */
            __IO uint32_t NBIE :1; /*!< [4:4] 使能NBIF中断请求:0:NBIF不可产生中断请求。1:NBIF可以产生中断请求。  */
            __IO uint32_t MEIE :1; /*!< [5:5] 使能MEIF中断请求:0:MEIF不可产生中断请求。1:MEIF可以产生中断请求。  */
            __IO uint32_t CRCIE :1; /*!< [6:6] 使能CRCIF中断请求:0:CRCIF不可产生中断请求。1:CRCIF可以产生中断请求。  */
            __IO uint32_t FWIE :1; /*!< [7:7] 使能FWIF中断请求:0:FWIF不可产生中断请求。1:FWIF可以产生中断请求。  */
            __IO uint32_t RUIE :1; /*!< [8:8] 使能RUIF中断请求:0:RUIF不可产生中断请求。1:RUIF可以产生中断请求。  */
            __IO uint32_t RMIE :1; /*!< [9:9] 使能RMIF中断请求:0:RMIF不可产生中断请求。1:RMIF可以产生中断请求。  */
            __IO uint32_t TPIE :1; /*!< [10:10] 使能TPIF中断请求:0:TPIF不可产生中断请求。1:TPIF可以产生中断请求。  */
            __IO uint32_t TPOIE :1; /*!< [11:11] 使能TPOIF中断请求:0:TPOIF不可产生中断请求。1:TPOIF可以产生中断请求。 */
            __IO uint32_t TSIE :1; /*!< [12:12] 使能TSIF中断请求:0:TSIF不可产生中断请求。1:TSIF可以产生中断请求。  */
            __IO uint32_t TSOIE :1; /*!< [13:13] 使能TSOIF中断请求:0:TSOIF不可产生中断请求。1:TSOIF可以产生中断请求。 */
            __IO uint32_t TOIE :1; /*!< [14:14] 使能TOIF中断请求:0:TOIF不可产生中断请求。1:TOIF可以产生中断请求。  */
            __IO uint32_t TOOIE :1; /*!< [15:15] 使能TOOIF中断请求:0:TOOIF不可产生中断请求。1:TOOIF可以产生中断请求。 */
            __IO uint32_t NFIE :1; /*!< [16:16] 使能NFIF中断请求:0:NFIF不可产生中断请求。1:NFIF可以产生中断请求。  */
            __IO uint32_t RESERVED0 :15; /*!< [31:17] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_IE1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  WSIE0    :1; /*!< [0:0] 使能WSIFy中断请求  */
            __O uint32_t  WSIE1    :1; /*!< [1:1] 使能WSIFy中断请求  */
            __O uint32_t  WSIE2    :1; /*!< [2:2] 使能WSIFy中断请求  */
            __O uint32_t  WSIE3    :1; /*!< [3:3] 使能WSIFy中断请求  */
            __O uint32_t  WSIE4    :1; /*!< [4:4] 使能WSIFy中断请求  */
            __O uint32_t  WSIE5    :1; /*!< [5:5] 使能WSIFy中断请求  */
            __O uint32_t  SDIE0    :1; /*!< [6:6] 使能SDIFy中断请求  */
            __O uint32_t  SDIE1    :1; /*!< [7:7] 使能SDIFy中断请求  */
            __O uint32_t  SDIE2    :1; /*!< [8:8] 使能SDIFy中断请求  */
            __O uint32_t  SDIE3    :1; /*!< [9:9] 使能SDIFy中断请求  */
            __O uint32_t  SDIE4    :1; /*!< [10:10] 使能SDIFy中断请求  */
            __O uint32_t  SDIE5    :1; /*!< [11:11] 使能SDIFy中断请求  */
            __O uint32_t  SOIE0    :1; /*!< [12:12] 使能SOIFy中断请求  */
            __O uint32_t  SOIE1    :1; /*!< [13:13] 使能SOIFy中断请求  */
            __O uint32_t  SOIE2    :1; /*!< [14:14] 使能SOIFy中断请求  */
            __O uint32_t  SOIE3    :1; /*!< [15:15] 使能SOIFy中断请求  */
            __O uint32_t  SOIE4    :1; /*!< [16:16] 使能SOIFy中断请求  */
            __O uint32_t  SOIE5    :1; /*!< [17:17] 使能SOIFy中断请求  */
            __O uint32_t  SCRIE0   :1; /*!< [18:18] 使能SCRIFy中断请求  */
            __O uint32_t  SCRIE1   :1; /*!< [19:19] 使能SCRIFy中断请求  */
            __O uint32_t  SCRIE2   :1; /*!< [20:20] 使能SCRIFy中断请求  */
            __O uint32_t  SCRIE3   :1; /*!< [21:21] 使能SCRIFy中断请求  */
            __O uint32_t  SCRIE4   :1; /*!< [22:22] 使能SCRIFy中断请求  */
            __O uint32_t  SCRIE5   :1; /*!< [23:23] 使能SCRIFy中断请求  */
            __IO uint32_t RESERVED0 :8; /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_IE2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  FRP       :6; /*!< [5:0] FIFO读指针  */
            __I uint32_t  RESERVED0  :2; /*!< [7:6]  预留读为0 */
            __I uint32_t  FWP       :6; /*!< [13:8] FIFO/环形缓冲器写指针 */
            __I uint32_t  RESERVED1 :2; /*!< [15:14] 预留读为0 */
            __IO uint32_t FWL       :5; /*!< [20:16] FIFO警告等级 */
            __I uint32_t  RESERVED2 :8; /*!< [28:21] 预留读为0 */
            __I uint32_t  WRAP      :1; /*!< [29:29] 写指针超前读指针一圈时，WRAP置起 */
            __I uint32_t  FRQ :1; /*!< [30:30] 当累积发生三次RMIF(多次数据溢出)时，该位被硬件置1 */
            __O uint32_t  FLU :1; /*!< [31:31] 刷新位 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5_RFCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SD :32; /*!< [31:0] 接收数据:该寄存器显示RDATL/Hy中的值*/
        } bits;
        __IO uint32_t reg;
    };
} PSI5_RDATF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RSI0  :1; /*!< [0:0] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI1  :1; /*!< [1:1] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI2  :1; /*!< [2:2] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI3  :1; /*!< [3:3] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI4  :1; /*!< [4:4] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI5  :1; /*!< [5:5] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI6  :1; /*!< [6:6] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI7  :1; /*!< [7:7] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI8  :1; /*!< [8:8] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI9  :1; /*!< [9:9] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI10 :1; /*!< [10:10] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI11 :1; /*!< [11:11] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI12 :1; /*!< [12:12] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI13 :1; /*!< [13:13] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI14 :1; /*!< [14:14] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI15 :1; /*!< [15:15] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI16 :1; /*!< [16:16] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI17 :1; /*!< [17:17] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI18 :1; /*!< [18:18] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI19 :1; /*!< [19:19] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI20 :1; /*!< [20:20] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI21 :1; /*!< [21:21] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI22 :1; /*!< [22:22] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI23 :1; /*!< [23:23] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI24 :1; /*!< [24:24] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI25 :1; /*!< [25:25] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI26 :1; /*!< [26:26] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI27 :1; /*!< [27:27] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI28 :1; /*!< [28:28] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI29 :1; /*!< [29:29] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI30 :1; /*!< [30:30] 缓冲区y发生RSIF标志 */
            __I uint32_t RSI31 :1; /*!< [31:31] 缓冲区y发生RSIF标志 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_RSIOV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RMI0  :1; /*!< [0:0] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI1  :1; /*!< [1:1] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI2  :1; /*!< [2:2] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI3  :1; /*!< [3:3] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI4  :1; /*!< [4:4] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI5  :1; /*!< [5:5] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI6  :1; /*!< [6:6] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI7  :1; /*!< [7:7] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI8  :1; /*!< [8:8] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI9  :1; /*!< [9:9] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI10 :1; /*!< [10:10] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI11 :1; /*!< [11:11] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI12 :1; /*!< [12:12] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI13 :1; /*!< [13:13] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI14 :1; /*!< [14:14] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI15 :1; /*!< [15:15] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI16 :1; /*!< [16:16] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI17 :1; /*!< [17:17] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI18 :1; /*!< [18:18] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI19 :1; /*!< [19:19] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI20 :1; /*!< [20:20] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI21 :1; /*!< [21:21] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI22 :1; /*!< [22:22] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI23 :1; /*!< [23:23] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI24 :1; /*!< [24:24] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI25 :1; /*!< [25:25] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI26 :1; /*!< [26:26] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI27 :1; /*!< [27:27] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI28 :1; /*!< [28:28] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI29 :1; /*!< [29:29] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI30 :1; /*!< [30:30] 缓冲区y发生RMIF标志 */
            __I uint32_t RMI31 :1; /*!< [31:31] 缓冲区y发生RMIF标志 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_RMIOV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t NBI0  :1; /*!< [0:0] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI1  :1; /*!< [1:1] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI2  :1; /*!< [2:2] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI3  :1; /*!< [3:3] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI4  :1; /*!< [4:4] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI5  :1; /*!< [5:5] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI6  :1; /*!< [6:6] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI7  :1; /*!< [7:7] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI8  :1; /*!< [8:8] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI9  :1; /*!< [9:9] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI10 :1; /*!< [10:10] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI11 :1; /*!< [11:11] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI12 :1; /*!< [12:12] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI13 :1; /*!< [13:13] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI14 :1; /*!< [14:14] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI15 :1; /*!< [15:15] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI16 :1; /*!< [16:16] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI17 :1; /*!< [17:17] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI18 :1; /*!< [18:18] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI19 :1; /*!< [19:19] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI20 :1; /*!< [20:20] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI21 :1; /*!< [21:21] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI22 :1; /*!< [22:22] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI23 :1; /*!< [23:23] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI24 :1; /*!< [24:24] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI25 :1; /*!< [25:25] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI26 :1; /*!< [26:26] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI27 :1; /*!< [27:27] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI28 :1; /*!< [28:28] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI29 :1; /*!< [29:29] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI30 :1; /*!< [30:30] 缓冲区y发生NBIF标志 */
            __I uint32_t NBI31 :1; /*!< [31:31] 缓冲区y发生NBIF标志 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_NBIOV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t TEI0  :1; /*!< [0:0] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI1  :1; /*!< [1:1] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI2  :1; /*!< [2:2] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI3  :1; /*!< [3:3] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI4  :1; /*!< [4:4] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI5  :1; /*!< [5:5] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI6  :1; /*!< [6:6] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI7  :1; /*!< [7:7] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI8  :1; /*!< [8:8] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI9  :1; /*!< [9:9] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI10 :1; /*!< [10:10] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI11 :1; /*!< [11:11] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI12 :1; /*!< [12:12] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI13 :1; /*!< [13:13] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI14 :1; /*!< [14:14] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI15 :1; /*!< [15:15] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI16 :1; /*!< [16:16] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI17 :1; /*!< [17:17] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI18 :1; /*!< [18:18] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI19 :1; /*!< [19:19] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI20 :1; /*!< [20:20] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI21 :1; /*!< [21:21] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI22 :1; /*!< [22:22] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI23 :1; /*!< [23:23] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI24 :1; /*!< [24:24] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI25 :1; /*!< [25:25] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI26 :1; /*!< [26:26] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI27 :1; /*!< [27:27] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI28 :1; /*!< [28:28] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI29 :1; /*!< [29:29] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI30 :1; /*!< [30:30] 缓冲区y发生TEIF标志 */
            __I uint32_t TEI31 :1; /*!< [31:31] 缓冲区y发生TEIF标志 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_TEIOV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CRCI0  :1; /*!< [0:0] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI1  :1; /*!< [1:1] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI2  :1; /*!< [2:2] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI3  :1; /*!< [3:3] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI4  :1; /*!< [4:4] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI5  :1; /*!< [5:5] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI6  :1; /*!< [6:6] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI7  :1; /*!< [7:7] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI8  :1; /*!< [8:8] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI9  :1; /*!< [9:9] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI10 :1; /*!< [10:10] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI11 :1; /*!< [11:11] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI12 :1; /*!< [12:12] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI13 :1; /*!< [13:13] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI14 :1; /*!< [14:14] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI15 :1; /*!< [15:15] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI16 :1; /*!< [16:16] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI17 :1; /*!< [17:17] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI18 :1; /*!< [18:18] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI19 :1; /*!< [19:19] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI20 :1; /*!< [20:20] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI21 :1; /*!< [21:21] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI22 :1; /*!< [22:22] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI23 :1; /*!< [23:23] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI24 :1; /*!< [24:24] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI25 :1; /*!< [25:25] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI26 :1; /*!< [26:26] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI27 :1; /*!< [27:27] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI28 :1; /*!< [28:28] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI29 :1; /*!< [29:29] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI30 :1; /*!< [30:30] 缓冲区y发生CRCIF标志 */
            __I uint32_t CRCI31 :1; /*!< [31:31] 缓冲区y发生CRCIF标志 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_CRCIOV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RDI0  :1; /*!< [0:0] 缓冲区y发生RDIF标志 */
            __I uint32_t RDI1  :1; /*!< [1:1] 缓冲区y发生RDIF标志 */
            __I uint32_t RDI2  :1; /*!< [2:2] 缓冲区y发生RDIF标志 */
            __I uint32_t RDI3  :1; /*!< [3:3] 缓冲区y发生RDIF标志 */
            __I uint32_t RDI4  :1; /*!< [4:4] 缓冲区y发生RDIF标志 */
            __I uint32_t RDI5  :1; /*!< [5:5] 缓冲区y发生RDIF标志 */
            __I uint32_t RDI6  :1; /*!< [6:6] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI7  :1; /*!< [7:7] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI8  :1; /*!< [8:8] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI9  :1; /*!< [9:9] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI10 :1; /*!< [10:10] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI11 :1; /*!< [11:11] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI12 :1; /*!< [12:12] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI13 :1; /*!< [13:13] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI14 :1; /*!< [14:14] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI15 :1; /*!< [15:15] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI16 :1; /*!< [16:16] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI17 :1; /*!< [17:17] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI18 :1; /*!< [18:18] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI19 :1; /*!< [19:19] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI20 :1; /*!< [20:20] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI21 :1; /*!< [21:21] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI22 :1; /*!< [22:22] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI23 :1; /*!< [23:23] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI24 :1; /*!< [24:24] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI25 :1; /*!< [25:25] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI26 :1; /*!< [26:26] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI27 :1; /*!< [27:27] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI28 :1; /*!< [28:28] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI29 :1; /*!< [29:29] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI30 :1; /*!< [30:30] 缓冲区y发生RDIF标志*/
            __I uint32_t RDI31 :1; /*!< [31:31] 缓冲区y发生RDIF标志*/
        } bits;
        __I uint32_t reg;
    };
} PSI5_RDIOV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t NFI0  :1; /*!< [0:0] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI1  :1; /*!< [1:1] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI2  :1; /*!< [2:2] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI3  :1; /*!< [3:3] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI4  :1; /*!< [4:4] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI5  :1; /*!< [5:5] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI6  :1; /*!< [6:6] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI7  :1; /*!< [7:7] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI8  :1; /*!< [8:8] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI9  :1; /*!< [9:9] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI10 :1; /*!< [10:10] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI11 :1; /*!< [11:11] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI12 :1; /*!< [12:12] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI13 :1; /*!< [13:13] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI14 :1; /*!< [14:14] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI15 :1; /*!< [15:15] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI16 :1; /*!< [16:16] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI17 :1; /*!< [17:17] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI18 :1; /*!< [18:18] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI19 :1; /*!< [19:19] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI20 :1; /*!< [20:20] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI21 :1; /*!< [21:21] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI22 :1; /*!< [22:22] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI23 :1; /*!< [23:23] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI24 :1; /*!< [24:24] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI25 :1; /*!< [25:25] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI26 :1; /*!< [26:26] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI27 :1; /*!< [27:27] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI28 :1; /*!< [28:28] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI29 :1; /*!< [29:29] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI30 :1; /*!< [30:30] 缓冲区y发生NFIF标志*/
            __I uint32_t NFI31 :1; /*!< [31:31] 缓冲区y发生NFIF标志*/
        } bits;
        __I uint32_t reg;
    };
} PSI5_NFIOV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MEI0  :1; /*!< [0:0] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI1  :1; /*!< [1:1] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI2  :1; /*!< [2:2] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI3  :1; /*!< [3:3] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI4  :1; /*!< [4:4] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI5  :1; /*!< [5:5] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI6  :1; /*!< [6:6] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI7  :1; /*!< [7:7] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI8  :1; /*!< [8:8] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI9  :1; /*!< [9:9] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI10 :1; /*!< [10:10] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI11 :1; /*!< [11:11] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI12 :1; /*!< [12:12] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI13 :1; /*!< [13:13] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI14 :1; /*!< [14:14] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI15 :1; /*!< [15:15] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI16 :1; /*!< [16:16] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI17 :1; /*!< [17:17] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI18 :1; /*!< [18:18] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI19 :1; /*!< [19:19] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI20 :1; /*!< [20:20] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI21 :1; /*!< [21:21] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI22 :1; /*!< [22:22] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI23 :1; /*!< [23:23] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI24 :1; /*!< [24:24] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI25 :1; /*!< [25:25] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI26 :1; /*!< [26:26] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI27 :1; /*!< [27:27] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI28 :1; /*!< [28:28] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI29 :1; /*!< [29:29] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI30 :1; /*!< [30:30] 缓冲区y发生MEIF标志*/
            __I uint32_t MEI31 :1; /*!< [31:31] 缓冲区y发生MEIF标志*/
        } bits;
        __I uint32_t reg;
    };
} PSI5_MEIOV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t RSI0  :1; /*!< [0:0] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI1  :1; /*!< [1:1] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI2  :1; /*!< [2:2] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI3  :1; /*!< [3:3] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI4  :1; /*!< [4:4] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI5  :1; /*!< [5:5] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI6  :1; /*!< [6:6] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI7  :1; /*!< [7:7] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI8  :1; /*!< [8:8] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI9  :1; /*!< [9:9] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI10 :1; /*!< [10:10] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI11 :1; /*!< [11:11] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI12 :1; /*!< [12:12] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI13 :1; /*!< [13:13] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI14 :1; /*!< [14:14] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI15 :1; /*!< [15:15] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI16 :1; /*!< [16:16] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI17 :1; /*!< [17:17] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI18 :1; /*!< [18:18] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI19 :1; /*!< [19:19] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI20 :1; /*!< [20:20] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI21 :1; /*!< [21:21] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI22 :1; /*!< [22:22] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI23 :1; /*!< [23:23] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI24 :1; /*!< [24:24] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI25 :1; /*!< [25:25] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI26 :1; /*!< [26:26] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI27 :1; /*!< [27:27] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI28 :1; /*!< [28:28] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI29 :1; /*!< [29:29] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI30 :1; /*!< [30:30] 置位该位将会导致RSIOV.RSIy置位*/
            __O uint32_t RSI31 :1; /*!< [31:31] 置位该位将会导致RSIOV.RSIy置位*/
        } bits;
        __O uint32_t reg;
    };
} PSI5_RSISET_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t RMI0  :1; /*!< [0:0] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI1  :1; /*!< [1:1] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI2  :1; /*!< [2:2] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI3  :1; /*!< [3:3] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI4  :1; /*!< [4:4] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI5  :1; /*!< [5:5] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI6  :1; /*!< [6:6] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI7  :1; /*!< [7:7] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI8  :1; /*!< [8:8] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI9  :1; /*!< [9:9] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI10 :1; /*!< [10:10] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI11 :1; /*!< [11:11] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI12 :1; /*!< [12:12] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI13 :1; /*!< [13:13] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI14 :1; /*!< [14:14] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI15 :1; /*!< [15:15] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI16 :1; /*!< [16:16] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI17 :1; /*!< [17:17] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI18 :1; /*!< [18:18] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI19 :1; /*!< [19:19] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI20 :1; /*!< [20:20] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI21 :1; /*!< [21:21] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI22 :1; /*!< [22:22] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI23 :1; /*!< [23:23] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI24 :1; /*!< [24:24] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI25 :1; /*!< [25:25] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI26 :1; /*!< [26:26] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI27 :1; /*!< [27:27] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI28 :1; /*!< [28:28] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI29 :1; /*!< [29:29] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI30 :1; /*!< [30:30] 置位该位将会导致RMIOV.RMIy置位*/
            __O uint32_t RMI31 :1; /*!< [31:31] 置位该位将会导致RMIOV.RMIy置位*/
        } bits;
        __O uint32_t reg;
    };
} PSI5_RMISET_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t NBI0  :1; /*!< [0:0] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI1  :1; /*!< [1:1] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI2  :1; /*!< [2:2] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI3  :1; /*!< [3:3] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI4  :1; /*!< [4:4] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI5  :1; /*!< [5:5] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI6  :1; /*!< [6:6] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI7  :1; /*!< [7:7] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI8  :1; /*!< [8:8] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI9  :1; /*!< [9:9] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI10 :1; /*!< [10:10] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI11 :1; /*!< [11:11] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI12 :1; /*!< [12:12] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI13 :1; /*!< [13:13] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI14 :1; /*!< [14:14] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI15 :1; /*!< [15:15] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI16 :1; /*!< [16:16] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI17 :1; /*!< [17:17] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI18 :1; /*!< [18:18] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI19 :1; /*!< [19:19] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI20 :1; /*!< [20:20] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI21 :1; /*!< [21:21] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI22 :1; /*!< [22:22] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI23 :1; /*!< [23:23] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI24 :1; /*!< [24:24] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI25 :1; /*!< [25:25] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI26 :1; /*!< [26:26] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI27 :1; /*!< [27:27] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI28 :1; /*!< [28:28] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI29 :1; /*!< [29:29] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI30 :1; /*!< [30:30] 置位该位将会导致RMIOV.NBIy置位*/
            __O uint32_t NBI31 :1; /*!< [31:31] 置位该位将会导致RMIOV.NBIy置位*/
        } bits;
        __O uint32_t reg;
    };
} PSI5_NBISET_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t TEI0  :1; /*!< [0:0] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI1  :1; /*!< [1:1] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI2  :1; /*!< [2:2] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI3  :1; /*!< [3:3] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI4  :1; /*!< [4:4] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI5  :1; /*!< [5:5] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI6  :1; /*!< [6:6] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI7  :1; /*!< [7:7] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI8  :1; /*!< [8:8] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI9  :1; /*!< [9:9] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI10 :1; /*!< [10:10] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI11 :1; /*!< [11:11] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI12 :1; /*!< [12:12] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI13 :1; /*!< [13:13] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI14 :1; /*!< [14:14] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI15 :1; /*!< [15:15] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI16 :1; /*!< [16:16] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI17 :1; /*!< [17:17] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI18 :1; /*!< [18:18] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI19 :1; /*!< [19:19] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI20 :1; /*!< [20:20] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI21 :1; /*!< [21:21] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI22 :1; /*!< [22:22] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI23 :1; /*!< [23:23] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI24 :1; /*!< [24:24] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI25 :1; /*!< [25:25] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI26 :1; /*!< [26:26] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI27 :1; /*!< [27:27] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI28 :1; /*!< [28:28] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI29 :1; /*!< [29:29] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI30 :1; /*!< [30:30] 置位该位将会导致RMIOV.TEIy置位*/
            __O uint32_t TEI31 :1; /*!< [31:31] 置位该位将会导致RMIOV.TEIy置位*/
        } bits;
        __O uint32_t reg;
    };
} PSI5_TEISET_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CRCI0  :1; /*!< [0:0] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI1  :1; /*!< [1:1] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI2  :1; /*!< [2:2] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI3  :1; /*!< [3:3] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI4  :1; /*!< [4:4] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI5  :1; /*!< [5:5] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI6  :1; /*!< [6:6] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI7  :1; /*!< [7:7] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI8  :1; /*!< [8:8] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI9  :1; /*!< [9:9] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI10 :1; /*!< [10:10] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI11 :1; /*!< [11:11] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI12 :1; /*!< [12:12] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI13 :1; /*!< [13:13] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI14 :1; /*!< [14:14] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI15 :1; /*!< [15:15] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI16 :1; /*!< [16:16] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI17 :1; /*!< [17:17] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI18 :1; /*!< [18:18] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI19 :1; /*!< [19:19] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI20 :1; /*!< [20:20] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI21 :1; /*!< [21:21] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI22 :1; /*!< [22:22] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI23 :1; /*!< [23:23] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI24 :1; /*!< [24:24] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI25 :1; /*!< [25:25] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI26 :1; /*!< [26:26] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI27 :1; /*!< [27:27] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI28 :1; /*!< [28:28] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI29 :1; /*!< [29:29] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI30 :1; /*!< [30:30] 置位该位将会导致RMIOV.CRCIy置位*/
            __O uint32_t CRCI31 :1; /*!< [31:31] 置位该位将会导致RMIOV.CRCIy置位*/
        } bits;
        __O uint32_t reg;
    };
} PSI5_CRCISET_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t RDI0  :1; /*!< [0:0] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI1  :1; /*!< [1:1] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI2  :1; /*!< [2:2] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI3  :1; /*!< [3:3] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI4  :1; /*!< [4:4] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI5  :1; /*!< [5:5] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI6  :1; /*!< [6:6] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI7  :1; /*!< [7:7] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI8  :1; /*!< [8:8] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI9  :1; /*!< [9:9] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI10 :1; /*!< [10:10] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI11 :1; /*!< [11:11] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI12 :1; /*!< [12:12] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI13 :1; /*!< [13:13] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI14 :1; /*!< [14:14] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI15 :1; /*!< [15:15] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI16 :1; /*!< [16:16] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI17 :1; /*!< [17:17] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI18 :1; /*!< [18:18] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI19 :1; /*!< [19:19] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI20 :1; /*!< [20:20] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI21 :1; /*!< [21:21] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI22 :1; /*!< [22:22] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI23 :1; /*!< [23:23] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI24 :1; /*!< [24:24] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI25 :1; /*!< [25:25] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI26 :1; /*!< [26:26] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI27 :1; /*!< [27:27] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI28 :1; /*!< [28:28] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI29 :1; /*!< [29:29] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI30 :1; /*!< [30:30] 置位该位将会导致RMIOV.RDIy置位*/
            __O uint32_t RDI31 :1; /*!< [31:31] 置位该位将会导致RMIOV.RDIy置位*/
        } bits;
        __O uint32_t reg;
    };
} PSI5_RDISET_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t NFI0  :1; /*!< [0:0] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI1  :1; /*!< [1:1] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI2  :1; /*!< [2:2] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI3  :1; /*!< [3:3] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI4  :1; /*!< [4:4] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI5  :1; /*!< [5:5] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI6  :1; /*!< [6:6] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI7  :1; /*!< [7:7] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI8  :1; /*!< [8:8] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI9  :1; /*!< [9:9] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI10 :1; /*!< [10:10] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI11 :1; /*!< [11:11] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI12 :1; /*!< [12:12] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI13 :1; /*!< [13:13] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI14 :1; /*!< [14:14] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI15 :1; /*!< [15:15] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI16 :1; /*!< [16:16] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI17 :1; /*!< [17:17] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI18 :1; /*!< [18:18] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI19 :1; /*!< [19:19] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI20 :1; /*!< [20:20] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI21 :1; /*!< [21:21] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI22 :1; /*!< [22:22] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI23 :1; /*!< [23:23] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI24 :1; /*!< [24:24] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI25 :1; /*!< [25:25] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI26 :1; /*!< [26:26] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI27 :1; /*!< [27:27] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI28 :1; /*!< [28:28] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI29 :1; /*!< [29:29] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI30 :1; /*!< [30:30] 置位该位将会导致RMIOV.NFIy置位*/
            __O uint32_t NFI31 :1; /*!< [31:31] 置位该位将会导致RMIOV.NFIy置位*/
        } bits;
        __O uint32_t reg;
    };
} PSI5_NFISET_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t MEI0  :1; /*!< [0:0] 置位该位将会导致MEIOV.MEIy置位*/
            __O uint32_t MEI1  :1; /*!< [1:1] 置位该位将会导致MEIOV.MEIy置位*/
            __O uint32_t MEI2  :1; /*!< [2:2] 置位该位将会导致MEIOV.MEIy置位*/
            __O uint32_t MEI3  :1; /*!< [3:3] 置位该位将会导致MEIOV.MEIy置位*/
            __O uint32_t MEI4  :1; /*!< [4:4] 置位该位将会导致MEIOV.MEIy置位*/
            __O uint32_t MEI5  :1; /*!< [5:5] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI6  :1; /*!< [6:6] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI7  :1; /*!< [7:7] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI8  :1; /*!< [8:8] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI9  :1; /*!< [9:9] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI10 :1; /*!< [10:10] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI11 :1; /*!< [11:11] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI12 :1; /*!< [12:12] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI13 :1; /*!< [13:13] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI14 :1; /*!< [14:14] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI15 :1; /*!< [15:15] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI16 :1; /*!< [16:16] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI17 :1; /*!< [17:17] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI18 :1; /*!< [18:18] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI19 :1; /*!< [19:19] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI20 :1; /*!< [20:20] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI21 :1; /*!< [21:21] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI22 :1; /*!< [22:22] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI23 :1; /*!< [23:23] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI24 :1; /*!< [24:24] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI25 :1; /*!< [25:25] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI26 :1; /*!< [26:26] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI27 :1; /*!< [27:27] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI28 :1; /*!< [28:28] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI29 :1; /*!< [29:29] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI30 :1; /*!< [30:30] 置位该位将会导致MEIOV.MEIy置位  */
            __O uint32_t MEI31 :1; /*!< [31:31] 置位该位将会导致MEIOV.MEIy置位  */
        } bits;
        __O uint32_t reg;
    };
} PSI5_MEISET_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t RSI0  :1; /*!< [0:0] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI1  :1; /*!< [1:1] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI2  :1; /*!< [2:2] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI3  :1; /*!< [3:3] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI4  :1; /*!< [4:4] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI5  :1; /*!< [5:5] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI6  :1; /*!< [6:6] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI7  :1; /*!< [7:7] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI8  :1; /*!< [8:8] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI9  :1; /*!< [9:9] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI10 :1; /*!< [10:10] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI11 :1; /*!< [11:11] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI12 :1; /*!< [12:12] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI13 :1; /*!< [13:13] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI14 :1; /*!< [14:14] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI15 :1; /*!< [15:15] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI16 :1; /*!< [16:16] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI17 :1; /*!< [17:17] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI18 :1; /*!< [18:18] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI19 :1; /*!< [19:19] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI20 :1; /*!< [20:20] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI21 :1; /*!< [21:21] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI22 :1; /*!< [22:22] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI23 :1; /*!< [23:23] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI24 :1; /*!< [24:24] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI25 :1; /*!< [25:25] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI26 :1; /*!< [26:26] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI27 :1; /*!< [27:27] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI28 :1; /*!< [28:28] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI29 :1; /*!< [29:29] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI30 :1; /*!< [30:30] 置位该位将会导致MEIOV.RSIy清零  */
            __O uint32_t RSI31 :1; /*!< [31:31] 置位该位将会导致MEIOV.RSIy清零  */
        } bits;
        __O uint32_t reg;
    };
} PSI5_RSICLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t RMI0  :1; /*!< [0:0] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI1  :1; /*!< [1:1] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI2  :1; /*!< [2:2] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI3  :1; /*!< [3:3] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI4  :1; /*!< [4:4] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI5  :1; /*!< [5:5] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI6  :1; /*!< [6:6] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI7  :1; /*!< [7:7] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI8  :1; /*!< [8:8] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI9  :1; /*!< [9:9] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI10 :1; /*!< [10:10] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI11 :1; /*!< [11:11] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI12 :1; /*!< [12:12] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI13 :1; /*!< [13:13] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI14 :1; /*!< [14:14] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI15 :1; /*!< [15:15] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI16 :1; /*!< [16:16] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI17 :1; /*!< [17:17] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI18 :1; /*!< [18:18] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI19 :1; /*!< [19:19] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI20 :1; /*!< [20:20] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI21 :1; /*!< [21:21] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI22 :1; /*!< [22:22] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI23 :1; /*!< [23:23] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI24 :1; /*!< [24:24] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI25 :1; /*!< [25:25] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI26 :1; /*!< [26:26] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI27 :1; /*!< [27:27] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI28 :1; /*!< [28:28] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI29 :1; /*!< [29:29] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI30 :1; /*!< [30:30] 置位该位将会导致MEIOV.RMIy清零  */
            __O uint32_t RMI31 :1; /*!< [31:31] 置位该位将会导致MEIOV.RMIy清零  */
        } bits;
        __O uint32_t reg;
    };
} PSI5_RMICLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t NBI0  :1; /*!< [0:0] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI1  :1; /*!< [1:1] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI2  :1; /*!< [2:2] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI3  :1; /*!< [3:3] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI4  :1; /*!< [4:4] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI5  :1; /*!< [5:5] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI6  :1; /*!< [6:6] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI7  :1; /*!< [7:7] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI8  :1; /*!< [8:8] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI9  :1; /*!< [9:9] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI10 :1; /*!< [10:10] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI11 :1; /*!< [11:11] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI12 :1; /*!< [12:12] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI13 :1; /*!< [13:13] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI14 :1; /*!< [14:14] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI15 :1; /*!< [15:15] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI16 :1; /*!< [16:16] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI17 :1; /*!< [17:17] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI18 :1; /*!< [18:18] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI19 :1; /*!< [19:19] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI20 :1; /*!< [20:20] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI21 :1; /*!< [21:21] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI22 :1; /*!< [22:22] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI23 :1; /*!< [23:23] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI24 :1; /*!< [24:24] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI25 :1; /*!< [25:25] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI26 :1; /*!< [26:26] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI27 :1; /*!< [27:27] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI28 :1; /*!< [28:28] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI29 :1; /*!< [29:29] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI30 :1; /*!< [30:30] 置位该位将会导致MEIOV.NBIy清零  */
            __O uint32_t NBI31 :1; /*!< [31:31] 置位该位将会导致MEIOV.NBIy清零  */
        } bits;
        __O uint32_t reg;
    };
} PSI5_NBICLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t TEI0  :1; /*!< [0:0] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI1  :1; /*!< [1:1] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI2  :1; /*!< [2:2] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI3  :1; /*!< [3:3] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI4  :1; /*!< [4:4] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI5  :1; /*!< [5:5] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI6  :1; /*!< [6:6] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI7  :1; /*!< [7:7] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI8  :1; /*!< [8:8] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI9  :1; /*!< [9:9] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI10 :1; /*!< [10:10] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI11 :1; /*!< [11:11] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI12 :1; /*!< [12:12] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI13 :1; /*!< [13:13] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI14 :1; /*!< [14:14] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI15 :1; /*!< [15:15] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI16 :1; /*!< [16:16] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI17 :1; /*!< [17:17] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI18 :1; /*!< [18:18] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI19 :1; /*!< [19:19] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI20 :1; /*!< [20:20] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI21 :1; /*!< [21:21] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI22 :1; /*!< [22:22] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI23 :1; /*!< [23:23] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI24 :1; /*!< [24:24] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI25 :1; /*!< [25:25] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI26 :1; /*!< [26:26] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI27 :1; /*!< [27:27] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI28 :1; /*!< [28:28] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI29 :1; /*!< [29:29] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI30 :1; /*!< [30:30] 置位该位将会导致MEIOV.TEIy清零  */
            __O uint32_t TEI31 :1; /*!< [31:31] 置位该位将会导致MEIOV.TEIy清零  */
        } bits;
        __O uint32_t reg;
    };
} PSI5_TEICLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CRCI0  :1; /*!< [0:0] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI1  :1; /*!< [1:1] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI2  :1; /*!< [2:2] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI3  :1; /*!< [3:3] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI4  :1; /*!< [4:4] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI5  :1; /*!< [5:5] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI6  :1; /*!< [6:6] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI7  :1; /*!< [7:7] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI8  :1; /*!< [8:8] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI9  :1; /*!< [9:9] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI10 :1; /*!< [10:10] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI11 :1; /*!< [11:11] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI12 :1; /*!< [12:12] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI13 :1; /*!< [13:13] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI14 :1; /*!< [14:14] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI15 :1; /*!< [15:15] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI16 :1; /*!< [16:16] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI17 :1; /*!< [17:17] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI18 :1; /*!< [18:18] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI19 :1; /*!< [19:19] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI20 :1; /*!< [20:20] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI21 :1; /*!< [21:21] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI22 :1; /*!< [22:22] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI23 :1; /*!< [23:23] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI24 :1; /*!< [24:24] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI25 :1; /*!< [25:25] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI26 :1; /*!< [26:26] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI27 :1; /*!< [27:27] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI28 :1; /*!< [28:28] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI29 :1; /*!< [29:29] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI30 :1; /*!< [30:30] 置位该位将会导致MEIOV.CRCIy清零  */
            __O uint32_t CRCI31 :1; /*!< [31:31] 置位该位将会导致MEIOV.CRCIy清零  */
        } bits;
        __O uint32_t reg;
    };
} PSI5_CRCICLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t RDI0  :1; /*!< [0:0] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI1  :1; /*!< [1:1] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI2  :1; /*!< [2:2] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI3  :1; /*!< [3:3] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI4  :1; /*!< [4:4] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI5  :1; /*!< [5:5] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI6  :1; /*!< [6:6] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI7  :1; /*!< [7:7] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI8  :1; /*!< [8:8] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI9  :1; /*!< [9:9] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI10 :1; /*!< [10:10] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI11 :1; /*!< [11:11] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI12 :1; /*!< [12:12] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI13 :1; /*!< [13:13] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI14 :1; /*!< [14:14] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI15 :1; /*!< [15:15] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI16 :1; /*!< [16:16] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI17 :1; /*!< [17:17] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI18 :1; /*!< [18:18] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI19 :1; /*!< [19:19] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI20 :1; /*!< [20:20] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI21 :1; /*!< [21:21] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI22 :1; /*!< [22:22] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI23 :1; /*!< [23:23] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI24 :1; /*!< [24:24] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI25 :1; /*!< [25:25] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI26 :1; /*!< [26:26] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI27 :1; /*!< [27:27] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI28 :1; /*!< [28:28] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI29 :1; /*!< [29:29] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI30 :1; /*!< [30:30] 置位该位将会导致MEIOV.RDIy清零  */
            __O uint32_t RDI31 :1; /*!< [31:31] 置位该位将会导致MEIOV.RDIy清零  */
        } bits;
        __O uint32_t reg;
    };
} PSI5_RDICLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t NFI0  :1; /*!< [0:0] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI1  :1; /*!< [1:1] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI2  :1; /*!< [2:2] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI3  :1; /*!< [3:3] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI4  :1; /*!< [4:4] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI5  :1; /*!< [5:5] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI6  :1; /*!< [6:6] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI7  :1; /*!< [7:7] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI8  :1; /*!< [8:8] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI9  :1; /*!< [9:9] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI10 :1; /*!< [10:10] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI11 :1; /*!< [11:11] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI12 :1; /*!< [12:12] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI13 :1; /*!< [13:13] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI14 :1; /*!< [14:14] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI15 :1; /*!< [15:15] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI16 :1; /*!< [16:16] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI17 :1; /*!< [17:17] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI18 :1; /*!< [18:18] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI19 :1; /*!< [19:19] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI20 :1; /*!< [20:20] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI21 :1; /*!< [21:21] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI22 :1; /*!< [22:22] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI23 :1; /*!< [23:23] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI24 :1; /*!< [24:24] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI25 :1; /*!< [25:25] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI26 :1; /*!< [26:26] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI27 :1; /*!< [27:27] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI28 :1; /*!< [28:28] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI29 :1; /*!< [29:29] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI30 :1; /*!< [30:30] 置位该位将会导致MEIOV.NFIy清零  */
            __O uint32_t NFI31 :1; /*!< [31:31] 置位该位将会导致MEIOV.NFIy清零  */
        } bits;
        __O uint32_t reg;
    };
} PSI5_NFICLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t MEI0  :1; /*!< [0:0] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI1  :1; /*!< [1:1] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI2  :1; /*!< [2:2] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI3  :1; /*!< [3:3] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI4  :1; /*!< [4:4] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI5  :1; /*!< [5:5] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI6  :1; /*!< [6:6] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI7  :1; /*!< [7:7] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI8  :1; /*!< [8:8] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI9  :1; /*!< [9:9] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI10 :1; /*!< [10:10] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI11 :1; /*!< [11:11] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI12 :1; /*!< [12:12] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI13 :1; /*!< [13:13] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI14 :1; /*!< [14:14] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI15 :1; /*!< [15:15] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI16 :1; /*!< [16:16] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI17 :1; /*!< [17:17] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI18 :1; /*!< [18:18] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI19 :1; /*!< [19:19] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI20 :1; /*!< [20:20] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI21 :1; /*!< [21:21] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI22 :1; /*!< [22:22] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI23 :1; /*!< [23:23] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI24 :1; /*!< [24:24] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI25 :1; /*!< [25:25] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI26 :1; /*!< [26:26] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI27 :1; /*!< [27:27] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI28 :1; /*!< [28:28] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI29 :1; /*!< [29:29] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI30 :1; /*!< [30:30] 置位该位将会导致MEIOV.MEIy清零  */
            __O uint32_t MEI31 :1; /*!< [31:31] 置位该位将会导致MEIOV.MEIy清零  */
        } bits;
        __O uint32_t reg;
    };
} PSI5_MEICLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CRCIF :1;  /*!< [0:0] CRC错误标志  */
            __I uint32_t CRC   :3;  /*!< [3:1] CRC校验位 */
            __I uint32_t SD    :28; /*!< [31:4] 接收数据  */
        } bits;
        __I uint32_t reg;
    };
} PSI5_RDML_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t TS   :24; /*!< [23:0] 时间戳 */
            __I uint32_t SC   :3;  /*!< [26:24] Slot计数器 */
            __I uint32_t TEIF :1;  /*!< [27:27] 时间槽错误标志 */
            __I uint32_t NBIF :1;  /*!< [28:28] 比特数目错误标志 */
            __I uint32_t MEIF :1;  /*!< [29:29] 消息位错误标志 */
            __I uint32_t NFIF :1;  /*!< [30:30] 无帧接收标志 */
            __I uint32_t RMIF :1;  /*!< [31:31] 接收内存溢出标志 */
        } bits;
        __I uint32_t reg;
    };
} PSI5_RDMH_T;

typedef volatile struct
{
    PSI5_RDML_T PSI5_RDML;
    PSI5_RDMH_T PSI5_RDMH;
} Psi5_RxDataMap_t;

typedef volatile struct
{
    /* offset  : 0x0000.  */
    PSI5_CLKC_T PSI5_CLKC;
    /* offset  : 0x0004.  */
    PSI5_DBG_T PSI5_DBG;
    /* offset  : 0x0008.  */
    PSI5_RST0_T PSI5_RST0;
    /* offset  : 0x000C.  */
    PSI5_RST1_T PSI5_RST1;
    /* offset  : 0x0010.  */
    PSI5_RSTCLR_T PSI5_RSTCLR;
    /* offset  : 0x0014.  */
    PSI5_ACES0_T PSI5_ACES0;
    /* offset  : 0x0018.  */
    PSI5_ACES1_T PSI5_ACES1;
    /* offset  : 0x001C.  */
    PSI5_INFO_T PSI5_INFO;
    /* offset  : 0x0020.  */
    PSI5_FDR_T PSI5_FDR;
    /* offset  : 0x0024.  */
    PSI5_FDRL_T PSI5_FDRL;
    /* offset  : 0x0028.  */
    PSI5_FDRH_T PSI5_FDRH;
    /* offset  : 0x002C.  */
    PSI5_FDRT_T PSI5_FDRT;
    /* offset  : 0x0030.  */
    PSI5_TSR_T PSI5_TSR[3];
    /* offset  : 0x003C.  */
    PSI5_GCTL_T PSI5_GCTL;
    /* offset  : 0x0040.  */
    PSI5_GIF_T PSI5_GIF;
} Psi5_GeneralRegisterMap_t;

typedef volatile struct
{
    /* offset  : 0x0044.  */
    PSI5_IOCTL_T PSI5_IOCTL;
    /* offset  : 0x0048.  */
    PSI5_RCTLA_T PSI5_RCTLA;
    /* offset  : 0x004C.  */
    PSI5_RCTLB_T PSI5_RCTLB;
    /* offset  : 0x0050.  */
    PSI5_RCTLC_T PSI5_RCTLC;
    /* offset  : 0x0054.  */
    PSI5_WDT_T PSI5_WDT[7];
    /* offset  : 0x0070.  */
    PSI5_REVSTA_T PSI5_REVSTA;
    /* offset  : 0x0074.  */
    PSI5_SDSTA_T PSI5_SDSTA[6];
    /* offset  : 0x00BC.  */
    PSI5_SPTSC_T PSI5_SPTSC;
    /* offset  : 0x0090.  */
    PSI5_SFTSC_T PSI5_SFTSC;
    /* offset  : 0x0094.  */
    PSI5_RDATL_T PSI5_RDATL;
    /* offset  : 0x0098.  */
    PSI5_RDATH_T PSI5_RDATH;
    /* offset  : 0x009C.  */
    PSI5_PCTRL_T PSI5_PCTRL;
    /* offset  : 0x00A0.  */
    PSI5_CTV_T PSI5_CTV;
    /* offset  : 0x00A4.  */
    PSI5_SCTL_T PSI5_SCTL;
    /* offset  : 0x00A8.  */
    PSI5_SDRL_T PSI5_SDRL;
    /* offset  : 0x00AC.  */
    PSI5_SDRH_T PSI5_SDRH;
    /* offset  : 0x00B0.  */
    PSI5_SSRL_T PSI5_SSRL;
    /* offset  : 0x00B4.  */
    PSI5_SSRH_T PSI5_SSRH;
    /* offset  : 0x00B8.  */
    PSI5_SORL_T PSI5_SORL;
    /* offset  : 0x00BC.  */
    PSI5_SORH_T PSI5_SORH;
    /* offset  : 0x00C0.  */
    uint32_t RESERVED0[4];
} Psi5_IORegisterMap_t;

typedef volatile struct
{
    /* offset  : 0x0310.  */
    PSI5_INP_T PSI5_INP[3];
    /* offset  : 0x031C.  */
    uint32_t RESERVED0[2];
    /* offset  : 0x0324.  */
    PSI5_IF1_T PSI5_IF1[3];
    /* offset  : 0x0330.  */
    uint32_t RESERVED1[2];
    /* offset  : 0x0338.  */
    PSI5_IF2_T PSI5_IF2[3];
    /* offset  : 0x0344.  */
    uint32_t RESERVED2[2];
    /* offset  : 0x034C.  */
    PSI5_IS1_T PSI5_IS1[3];
    /* offset  : 0x0358.  */
    uint32_t RESERVED3[2];
    /* offset  : 0x0360.  */
    PSI5_IS2_T PSI5_IS2[3];
    /* offset  : 0x036C.  */
    uint32_t RESERVED4[2];
    /* offset  : 0x0374.  */
    PSI5_IC1_T PSI5_IC1[3];
    /* offset  : 0x0380.  */
    uint32_t RESERVED5[2];
    /* offset  : 0x0388.  */
    PSI5_IC2_T PSI5_IC2[3];
    /* offset  : 0x0394.  */
    uint32_t RESERVED6[2];
    /* offset  : 0x039C.  */
    PSI5_IE1_T PSI5_IE1[3];
    /* offset  : 0x03A8.  */
    uint32_t RESERVED7[2];
    /* offset  : 0x03B0.  */
    PSI5_IE1_T PSI5_IE2[3];
    /* offset  : 0x03BC.  */
    uint32_t RESERVED8[10];
    /* offset  : 0x03E4.  */
    PSI5_RFCTL_T PSI5_RFCTL[3];
    /* offset  : 0x03F0.  */
    uint32_t RESERVED9[2];
    /* offset  : 0x03F8.  */
    PSI5_RDATF_T PSI5_RDATF[3];
    /* offset  : 0x0404.  */
    uint32_t RESERVED10[2];
    /* offset  : 0x040C.  */
    PSI5_RSIOV_T PSI5_RSIOV[3];
    /* offset  : 0x0418.  */
    uint32_t RESERVED11[2];
    /* offset  : 0x0420.  */
    PSI5_RMIOV_T PSI5_RMIOV[3];
    /* offset  : 0x042C.  */
    uint32_t RESERVED12[2];
    /* offset  : 0x0434.  */
    PSI5_NBIOV_T PSI5_NBIOV[3];
    /* offset  : 0x0440.  */
    uint32_t RESERVED13[2];
    /* offset  : 0x0448.  */
    PSI5_TEIOV_T PSI5_TEIOV[3];
    /* offset  : 0x0454.  */
    uint32_t RESERVED14[2];
    /* offset  : 0x045C.  */
    PSI5_CRCIOV_T PSI5_CRCIOV[3];
    /* offset  : 0x0468.  */
    uint32_t RESERVED15[2];
    /* offset  : 0x0470.  */
    PSI5_RDIOV_T PSI5_RDIOV[3];
    /* offset  : 0x047C.  */
    uint32_t RESERVED16[2];
    /* offset  : 0x0484.  */
    PSI5_NFIOV_T PSI5_NFIOV[3];
    /* offset  : 0x0490.  */
    uint32_t RESERVED17[2];
    /* offset  : 0x0498.  */
    PSI5_MEIOV_T PSI5_MEIOV[3];
    /* offset  : 0x04A4.  */
    uint32_t RESERVED18[2];
    /* offset  : 0x04AC.  */
    PSI5_RSISET_T PSI5_RSISET[3];
    /* offset  : 0x04B8.  */
    uint32_t RESERVED19[2];
    /* offset  : 0x04C0.  */
    PSI5_RMISET_T PSI5_RMISET[3];
    /* offset  : 0x04CC.  */
    uint32_t RESERVED20[2];
    /* offset  : 0x04D4.  */
    PSI5_NBISET_T PSI5_NBISET[3];
    /* offset  : 0x04E0.  */
    uint32_t RESERVED21[2];
    /* offset  : 0x04E8.  */
    PSI5_TEISET_T PSI5_TEISET[3];
    /* offset  : 0x04F4.  */
    uint32_t RESERVED22[2];
    /* offset  : 0x04FC.  */
    PSI5_CRCISET_T PSI5_CRCISET[3];
    /* offset  : 0x0508.  */
    uint32_t RESERVED23[2];
    /* offset  : 0x0510.  */
    PSI5_RDISET_T PSI5_RDISET[3];
    /* offset  : 0x051C.  */
    uint32_t RESERVED24[2];
    /* offset  : 0x0524.  */
    PSI5_NFISET_T PSI5_NFISET[3];
    /* offset  : 0x0530.  */
    uint32_t RESERVED25[2];
    /* offset  : 0x0538.  */
    PSI5_MEISET_T PSI5_MEISET[3];
    /* offset  : 0x0544.  */
    uint32_t RESERVED26[2];
    /* offset  : 0x054C.  */
    PSI5_RSICLR_T PSI5_RSICLR[3];
    /* offset  : 0x0558.  */
    uint32_t RESERVED27[2];
    /* offset  : 0x0560.  */
    PSI5_RMICLR_T PSI5_RMICLR[3];
    /* offset  : 0x056C.  */
    uint32_t RESERVED28[2];
    /* offset  : 0x0574.  */
    PSI5_NBICLR_T PSI5_NBICLR[3];
    /* offset  : 0x0580.  */
    uint32_t RESERVED29[2];
    /* offset  : 0x0588.  */
    PSI5_TEICLR_T PSI5_TEICLR[3];
    /* offset  : 0x0594.  */
    uint32_t RESERVED30[2];
    /* offset  : 0x059C.  */
    PSI5_CRCICLR_T PSI5_CRCICLR[3];
    /* offset  : 0x05A8.  */
    uint32_t RESERVED31[2];
    /* offset  : 0x05B0.  */
    PSI5_RDICLR_T PSI5_RDICLR[3];
    /* offset  : 0x05BC.  */
    uint32_t RESERVED32[2];
    /* offset  : 0x05C4.  */
    PSI5_NFICLR_T PSI5_NFICLR[3];
    /* offset  : 0x05D0.  */
    uint32_t RESERVED33[2];
    /* offset  : 0x05D8.  */
    PSI5_MEICLR_T PSI5_MEICLR[3];
    /* offset  : 0x05E4.  */
    uint32_t RESERVED34[7];
    /* offset  : 0x0600.  */
    Psi5_RxDataMap_t PSI5_RXDATA[3][32];
} Psi5_CtlRegisterMap_t;

#define PSI5_GENERAL_ADDR ((uint32_t)0xF0009000)
#define PSI5_GENERAL_PTR  ((Psi5_GeneralRegisterMap_t *)PSI5_GENERAL_ADDR)
#define PSI5_GENERAL_RM   (*(Psi5_GeneralRegisterMap_t *)PSI5_GENERAL_ADDR)

#define PSI5_IO_ADDR ((uint32_t)0xF0009044)
#define PSI5_IO_PTR  ((Psi5_IORegisterMap_t *)PSI5_IO_ADDR)
#define PSI5_IO_RM   (*(Psi5_IORegisterMap_t *)PSI5_IO_ADDR)

#define PSI5_CTL_ADDR ((uint32_t)0xF0009310)
#define PSI5_CTL_PTR  ((Psi5_CtlRegisterMap_t *)PSI5_CTL_ADDR)
#define PSI5_CTL_RM   (*(Psi5_CtlRegisterMap_t *)PSI5_CTL_ADDR)

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
