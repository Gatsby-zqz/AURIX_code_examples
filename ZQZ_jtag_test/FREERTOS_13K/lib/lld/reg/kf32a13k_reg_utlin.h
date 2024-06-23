/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_utlin.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-14
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
 *  |2023-12-14    |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef KF32A13K_REG_UTLIN_H_
#define KF32A13K_REG_UTLIN_H_

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

            __I uint32_t MODREV     :8;  /*!< [7:0] 定义版本号 */
            __I uint32_t MODETYPE   :8;  /*!< [15:8] 定义模块 */
            __I uint32_t MODENUMBER :16; /*!< [31:16] 定义模块 ID_NUMBER */
        } bits;
        __I uint32_t reg;
    };
} UTLIN_ID_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁用位:用于使能或禁止模块 */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁用状态位：指示模块当前状态 */
            __I uint32_t  RESERVED0 :1;  /*!< [2:2] 预留 */
            __IO uint32_t EDIS      :1;  /*!< [3:3] 休眠模式控制位：用于控制模块处于休眠模式 */
            __I uint32_t  RESERVED1 :28; /*!< [31:4] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_CLTR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :24; /*!< [23:0] 预留 */
            __IO uint32_t SUS    :4; /*!< [27:24] OCDS 暂停控制：控制来自对 OCDS 暂停信号的灵敏度 */
            __O uint32_t  SUS_P  :1; /*!< [28:28] SUS 位写保护，读出为 0 */
            __I uint32_t  SUSSTA :1; /*!< [29:29] 暂停状态 */
            __I uint32_t  RESERVED1 :2; /*!< [31:30] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_OCDS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ALTI      :3; /*!< [2:0] 输入选择切换位：用于切换接收信号输入 */
            __I uint32_t  RESERVED0 :1; /*!< [3:3] 预留 */
            __IO uint32_t DEPTH     :6; /*!< [9:4] 数字毛刺滤波器深度位 */
            __I uint32_t  RESERVED1 :6; /*!< [15:10] 预留 */
            __IO uint32_t CTS       :2; /*!< [17:16] CTS 选择位：选择 CTS 输入引脚 */
            __I uint32_t  RESERVED2 :7; /*!< [24:18] 预留 */
            __IO uint32_t RCPOL     :1; /*!< [25:25] RTS CTS 极性位：定义 RTS 和 CTS 信号 */
            __I uint32_t  RESERVED3 :2; /*!< [27:26] 预留 */
            __IO uint32_t LB        :1; /*!< [28:28] 回环模式位 */
            __IO uint32_t CTEN      :1; /*!< [29:29] 输入信号 CTS 使能位 */
            __I uint32_t  RXM       :1; /*!< [30:30] 接收监视器位：显示接收信号的状态 */
            __I uint32_t  TXM       :1; /*!< [31:31] 发送监视器位：显示发送信号的状态 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_IOCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  TXFIFORST :1;  /*!< [0:0] 该位置 1 时，清空 TXFIFO */
            __IO uint32_t TXFIFOEN  :1;  /*!< [1:1] 发送 FIFO 使能位 */
            __I uint32_t  RESERVED0 :2;  /*!< [3:2] 预留 */
            __IO uint32_t TXFIFOMOD :2;  /*!< [5:4] 发送 FIFO 模式选择 */
            __IO uint32_t TXFIFOINW :2;  /*!< [7:6] 发送 FIFO 入口宽度 */
            __IO uint32_t IFTHRES   :4;  /*!< [11:8] FIFO 中断等级 */
            __I uint32_t  RESERVED1 :4;  /*!< [15:12] 预留 */
            __IO uint32_t FIFOCNT   :5;  /*!< [20:16] FIFO 内字节数量 */
            __I uint32_t  RESERVED2 :11; /*!< [31:21] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_TXFIFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  RXFIFORST  :1;  /*!< [0:0] 该位置 1 时，清空 RXFIFO */
            __IO uint32_t RXFIFOEN   :1;  /*!< [1:1] 接收 FIFO 使能位 */
            __I uint32_t  RESERVED0  :2;  /*!< [3:2] 预留 */
            __IO uint32_t RXFIFOMOD  :2;  /*!< [5:4] 接收 FIFO 模式选择 */
            __IO uint32_t RXFIFOOUTW :2;  /*!< [7:6] 接收 FIFO 出口宽度 */
            __IO uint32_t IFTHRES    :4;  /*!< [11:8] FIFO 中断等级 */
            __I uint32_t  RESERVED1  :4;  /*!< [15:12] 预留 */
            __I uint32_t  FIFOCNT    :5;  /*!< [20:16] FIFO 内字节数量 */
            __I uint32_t  RESERVED2  :11; /*!< [31:21] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_RXFIFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CLKPDIV   :12; /*!< [11:0] 预分频设置位 */
            __I uint32_t  RESERVED0 :2;  /*!< [14:12] 预留 */
            __IO uint32_t OVERSAMPLE :4; /*!< [19:16] 过采样值设置位：定义过采样值 1-16，其中 1-3 是不允许的 */
            __I uint32_t  RESERVED1   :4; /*!< [23:20] 预留 */
            __IO uint32_t SAMPLEPOINT :4; /*!< [27:24] 采样点位置位 */
            __I uint32_t  RESERVED2   :3; /*!< [30:28] 预留 */
            __IO uint32_t SAMPLEMOD   :1; /*!< [31:31] 采样模式设置位：定义每 bit 数据采样数量 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_BITCON_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :6;  /*!< [5:0] 预留 */
            __IO uint32_t IDLE      :3;  /*!< [8:6] 初始化延迟持续时间设置位 */
            __IO uint32_t STOP      :1;  /*!< [9:9] 停止位设置位 */
            __I uint32_t  RESERVED1 :2;  /*!< [11:10] 预留 */
            __IO uint32_t LEAD      :3;  /*!< [14:12] LEAD 延迟的持续时间设置位 */
            __IO uint32_t UTLINMOD  :3;  /*!< [17:15] LIN 工作模式选择位 */
            __I uint32_t  RESERVED2 :11; /*!< [28:18] 预留 */
            __IO uint32_t CEN       :1;  /*!< [29:29] 冲突探测使能位 */
            __IO uint32_t PEN       :1;  /*!< [30:30] 奇偶校验使能位 */
            __IO uint32_t PARM      :1;  /*!< [31:31] 奇偶校验选择能位 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_FRAMECON_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DATLEN    :4; /*!< [3:0] 数据长度设置位 */
            __I uint32_t  RESERVED0 :9; /*!< [12:4] 预留 */
            __IO uint32_t HEADRESP  :1; /*!< [13:13] 仅发送报头设置位 */
            __IO uint32_t TOUTMOD   :1; /*!< [14:14] 数据长度设置位 */
            __IO uint32_t CSMOD     :1; /*!< [15:15] 数据长度设置位 */
            __IO uint32_t TOUT      :8; /*!< [23:16] 数据长度设置位 */
            __I uint32_t  RESERVED1 :8; /*!< [31:24] 数据长度设置位 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_DATCON_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DENOMINATOR :12; /*!< [11:0] 小数波特率分母 */
            __I uint32_t  RESERVED0   :4;  /*!< [15:12] 预留 */
            __IO uint32_t NUMERATOR   :12; /*!< [27:16] 小数分频器分子 */
            __I uint32_t  RESERVED1   :4;  /*!< [31:28] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_BRGR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LOWERLIMIT :8;  /*!< [7:0] 下限 */
            __IO uint32_t UPPERLIMIT :8;  /*!< [15:8] 上限 */
            __I uint32_t  MEASURED   :12; /*!< [27:16] 同步场测量值 */
            __I uint32_t  RESERVED0  :4;  /*!< [31:28] 预留 */

        } bits;
        __IO uint32_t reg;
    };
} UTLIN_BRGRD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :23; /*!< [22:0] 预留 */
            __IO uint32_t CSI       :1;  /*!< [23:23] 校验和注入位 */
            __I uint32_t  RESERVED1 :1;  /*!< [24:24] 预留 */
            __IO uint32_t CSEN      :1;  /*!< [25:25] 硬件校验使能位 */
            __IO uint32_t MS        :1;  /*!< [26:26] LIN 主从模式设置位 */
            __IO uint32_t BAUDDET   :1;  /*!< [27:27] 波特率自检测使能位 */
            __I uint32_t  RESERVED2 :4;  /*!< [31:28] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_LIN_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BREAK     :6;  /*!< [5:0] 间隔场检测和生成位*/
            __I uint32_t  RESERVED0 :26; /*!< [31:6] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_LINBT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t HEADER    :8;  /*!< [7:0] 报头超时阈值位 */
            __I uint32_t  RESERVED0 :24; /*!< [31:7] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_LINHT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t THEADIF    :1; /*!< [0:0] 发送报头结束标志位 */
            __I uint32_t TRESPIF    :1; /*!< [1:1] 发送响应结束标志位 */
            __I uint32_t RHEADIF    :1; /*!< [2:2] 接收报头结束标志位： */
            __I uint32_t RRESPIF    :1; /*!< [3:3] 接收响应结束标志位 */
            __I uint32_t RESERVED0  :1; /*!< [4:4] 预留 */
            __I uint32_t FALLIF     :1; /*!< [5:5] 检测下降沿位 */
            __I uint32_t RISEIF     :1; /*!< [6:6] 检测上升沿位 */
            __I uint32_t RESERVED1  :6; /*!< [12:7] 预留 */
            __I uint32_t WAKERQIF   :1; /*!< [13:13] 发送唤醒请求标志位 */
            __I uint32_t THEADRQIF  :1; /*!< [14:14] 发送报头请求标志位 */
            __I uint32_t TRESPRQIF  :1; /*!< [15:15] 发送响应请求标志位 */
            __I uint32_t PERRIF     :1; /*!< [16:16] 校验错误标志位 */
            __I uint32_t TCIF       :1; /*!< [17:17] 传输完成标志位 */
            __I uint32_t FERRIF     :1; /*!< [18:18] 帧错误标志位 */
            __I uint32_t HEADTIF    :1; /*!< [19:19] 报头超时标志位 */
            __I uint32_t RESPTIF    :1; /*!< [20:20] 响应超时标志位 */
            __I uint32_t BDETIF     :1; /*!< [21:21] 间隔场检测位 */
            __I uint32_t LPERRIF    :1; /*!< [22:22] LIN 奇偶校验错误标志位 */
            __I uint32_t LBERRIF    :1; /*!< [23:23] LIN 波 特 率 自 检 测 错 误 标 志 位 */
            __I uint32_t LCSERRIF   :1; /*!< [24:24] 间隔场检测位 */
            __I uint32_t CERRIF     :1; /*!< [25:25] 碰撞检测错误标志位 */
            __I uint32_t RFIFOOVIF  :1; /*!< [26:26] 接收 FIFO 溢出标志位 */
            __I uint32_t RFIFOUDIF  :1; /*!< [27:27] 接收 FIFO 下溢标志位 */
            __I uint32_t RFIFOCNTIF :1; /*!< [28:28] 接收 FIFO 计数标志位 */
            __I uint32_t RESERVED2  :1; /*!< [29:29] 预留 */
            __I uint32_t TFIFOOVIF  :1; /*!< [30:30] 发送 FIFO 溢出标志位 */
            __I uint32_t TFIFOCNTIF :1; /*!< [31:31] 发送 FIFO 计数标志位 */
        } bits;
        __I uint32_t reg;
    };
} UTLIN_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t THIFS     :1; /*!< [0:0] 标志位置位位 */
            __IO uint32_t TRIFS     :1; /*!< [1:1] 标志位置位位 */
            __IO uint32_t RHS       :1; /*!< [2:2] 标志位置位位 */
            __IO uint32_t RRS       :1; /*!< [3:3] 标志位置位位 */
            __I uint32_t  RESERVED0 :1; /*!< [4:4] 预留 */
            __IO uint32_t FEDIFS    :1; /*!< [5:5] 标志位置位位 */
            __IO uint32_t REDIFS    :1; /*!< [6:6] 标志位置位位 */
            __I uint32_t  RESERVED1 :6; /*!< [12:7] 预留 */
            __IO uint32_t TWRQIFS   :1; /*!< [13:13] 标志位置位位 */
            __IO uint32_t THRQIFS   :1; /*!< [14:14] 标志位置位位 */
            __IO uint32_t TRRQIFS   :1; /*!< [15:15] 标志位置位位 */
            __IO uint32_t PEIFS     :1; /*!< [16:16] 标志位置位位 */
            __IO uint32_t TCIFS     :1; /*!< [17:17] 标志位置位位 */
            __IO uint32_t FEIFS     :1; /*!< [18:18] 标志位置位位 */
            __IO uint32_t HTIFS     :1; /*!< [19:19] 标志位置位位 */
            __IO uint32_t RTIFS     :1; /*!< [20:20] 标志位置位位 */
            __IO uint32_t BDIFS     :1; /*!< [21:21] 标志位置位位 */
            __IO uint32_t LPIFS     :1; /*!< [22:22] 标志位置位位 */
            __IO uint32_t LAIFS     :1; /*!< [23:23] 标志位置位位 */
            __IO uint32_t LCIFS     :1; /*!< [24:24] 标志位置位位 */
            __IO uint32_t CEIFS     :1; /*!< [25:25] 标志位置位位 */
            __IO uint32_t RFOIFS    :1; /*!< [26:26] 标志位置位位 */
            __IO uint32_t RFUIFS    :1; /*!< [27:27] 标志位置位位 */
            __IO uint32_t RFCNTFS   :1; /*!< [28:28] 标志位置位位 */
            __I uint32_t  RESERVED2 :1; /*!< [29:29] 预留 */
            __IO uint32_t TFOIFS    :1; /*!< [30:30] 标志位置位位 */
            __IO uint32_t TFLIFS    :1; /*!< [31:31] 标志位置位位 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_IFS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t THIE      :1; /*!< [0:0] 标志位使能位 */
            __IO uint32_t TRIE      :1; /*!< [1:1] 标志位使能位 */
            __IO uint32_t RHIE      :1; /*!< [2:2] 标志位使能位 */
            __IO uint32_t RRIE      :1; /*!< [3:3] 标志位使能位 */
            __I uint32_t  RESERVED0 :1; /*!< [4:4] 预留 */
            __IO uint32_t FEDIE     :1; /*!< [5:5] 标志位使能位 */
            __IO uint32_t REDIE     :1; /*!< [6:6] 标志位使能位 */
            __I uint32_t  RESERVED1 :9; /*!< [15:7] 预留 */
            __IO uint32_t PEIE      :1; /*!< [16:16] 标志位使能位 */
            __IO uint32_t TCIE      :1; /*!< [17:17] 标志位使能位 */
            __IO uint32_t FEIE      :1; /*!< [18:18] 标志位使能位 */
            __IO uint32_t HTIE      :1; /*!< [19:19] 标志位使能位 */
            __IO uint32_t RTIE      :1; /*!< [20:20] 标志位使能位 */
            __IO uint32_t BDIE      :1; /*!< [21:21] 标志位使能位 */
            __IO uint32_t LPIE      :1; /*!< [22:22] 标志位使能位 */
            __IO uint32_t LAIE      :1; /*!< [23:23] 标志位使能位 */
            __IO uint32_t LCIE      :1; /*!< [24:24] 标志位使能位 */
            __IO uint32_t CEIE      :1; /*!< [25:25] 标志位使能位 */
            __IO uint32_t RFOIE     :1; /*!< [26:26] 标志位使能位 */
            __IO uint32_t RFUIE     :1; /*!< [27:27] 标志位使能位 */
            __IO uint32_t RELIE     :1; /*!< [28:28] 标志位使能位 */
            __I uint32_t  RESERVED2 :1; /*!< [29:29] 预留 */
            __IO uint32_t TFOIE     :1; /*!< [30:30] 标志位使能位 */
            __IO uint32_t TFLIE     :1; /*!< [26:26] 标志位使能位 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  THIC      :1; /*!< [0:0] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  TRIC      :1; /*!< [1:1] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  RHIC      :1; /*!< [2:2] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  RRIC      :1; /*!< [3:3] 标志位清除位:向该位写1清除响应的标志位  */
            __IO uint32_t RESERVED0 :1; /*!< [4:4] 预留读为0  */
            __O uint32_t  FEDIC     :1; /*!< [5:5] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  REDIC     :1; /*!< [6:6] 标志位清除位:向该位写1清除响应的标志位  */
            __IO uint32_t RESERVED1 :6; /*!< [12:7] 预留读为0  */
            __O uint32_t  TWRQIC    :1; /*!< [13:13] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  THRQIC    :1; /*!< [14:14] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  TRRQIC    :1; /*!< [15:15] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  PEIC      :1; /*!< [16:16] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  TCIC      :1; /*!< [17:17] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  FEIC      :1; /*!< [18:18] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  HTIC      :1; /*!< [19:19] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  RTIC      :1; /*!< [20:20] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  BDIC      :1; /*!< [21:21] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  LPIC      :1; /*!< [22:22] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  LAIC      :1; /*!< [23:23] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  LCIC      :1; /*!< [24:24] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  CEIC      :1; /*!< [25:25] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  RFOIC     :1; /*!< [26:26] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  RFUIC     :1; /*!< [27:27] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  RFLIC     :1; /*!< [28:28] 标志位清除位:向该位写1清除响应的标志位  */
            __IO uint32_t RESERVED2 :1; /*!< [29:29] 预留读为0  */
            __O uint32_t  TFOIC     :1; /*!< [30:30] 标志位清除位:向该位写1清除响应的标志位  */
            __O uint32_t  TFLIC     :1; /*!< [31:31] 标志位清除位:向该位写1清除响应的标志位  */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_IC_T;

typedef volatile struct
{
    __IO uint32_t reg; /*!< [31:0] 发送数据寄存器  */
} UTLIN_TBUFR_T;

typedef volatile struct
{
    __I uint32_t reg; /*!< [31:0] 接收数据寄存器  */
} UTLIN_RBUFR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CLKSEL    :5;  /*!< [4:0] 时钟选择位:选择波特率输入时钟  */
            __I uint32_t  RESERVED0 :26; /*!< [30:5] 预留读为0  */
            __I uint32_t  CLKEN     :1;  /*!< [31:31] 时钟使能位 */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_CSEL_T;

typedef volatile struct
{
    __I uint32_t reg; /*!< [31:0] 接收数据调试寄存器  */
} UTLIN_RBUFD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  CLR       :1;  /*!< [0:0] 复位状态清除位，读出为0  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_KRSTCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST :1; /*!< [0:0] 模块复位请求位，与UTLINx_RST0寄存器的RST位一起使用  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_KRST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST    :1; /*!< [0:0] 模块复位请求位，与UTLINx_RST1寄存器的RST位一起使用  */
            __I uint32_t  RSTSTA :1; /*!< [1:1] 复位状态  */
            __IO uint32_t RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} UTLIN_KRST0_T;

typedef volatile struct
{
    __I uint32_t reg; /*!< [31:0] 预留读为0  */
} UTLIN_ACCEN1_T;

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
} UTLIN_ACCEN0_T;

typedef volatile struct
{
    /* offset  : 0x0000.  */
    UTLIN_CLTR_T UTLIN_CLTR;
    /* offset  : 0x0004.  */
    UTLIN_IOCR_T UTLIN_IOCR;
    /* offset  : 0x0008.  */
    UTLIN_ID_T UTLIN_ID;
    /* offset  : 0x000C.  */
    UTLIN_TXFIFO_T UTLIN_TXFIFO;
    /* offset  : 0x0010.  */
    UTLIN_RXFIFO_T UTLIN_RXFIFO;
    /* offset  : 0x0014.  */
    UTLIN_BITCON_T UTLIN_BITCON;
    /* offset  : 0x0018.  */
    UTLIN_FRAMECON_T UTLIN_FRAMECON;
    /* offset  : 0x001C.  */
    UTLIN_DATCON_T UTLIN_DATCON;
    /* offset  : 0x0020.  */
    UTLIN_BRGR_T UTLIN_BRGR;
    /* offset  : 0x0024.  */
    UTLIN_BRGRD_T UTLIN_BRGRD;
    /* offset  : 0x0028.  */
    UTLIN_LIN_T UTLIN_LIN;
    /* offset  : 0x002C.  */
    UTLIN_LINBT_T UTLIN_LINBT;
    /* offset  : 0x0030.  */
    UTLIN_LINHT_T UTLIN_LINHT;
    /* offset  : 0x0034.  */
    UTLIN_IF_T UTLIN_IF;
    /* offset  : 0x0038.  */
    UTLIN_IFS_T UTLIN_IFS;
    /* offset  : 0x003C.  */
    UTLIN_IC_T UTLIN_IC;
    /* offset  : 0x0040.  */
    UTLIN_IE_T UTLIN_IE;
    /* offset  : 0x0044.  */
    UTLIN_TBUFR_T UTLIN_TBUFR;
    /* offset  : 0x0048.  */
    UTLIN_RBUFR_T UTLIN_RBUFR;
    /* offset  : 0x004C.  */
    UTLIN_CSEL_T UTLIN_CSEL;
    /* offset  : 0x0050.  */
    UTLIN_RBUFD_T UTLIN_RBUFD;
    /* offset  : 0x0054.  */
    uint32_t RESERVED0[37];
    /* offset  : 0x00E8.  */
    UTLIN_OCDS_T UTLIN_OCDS;
    /* offset  : 0x00EC.  */
    UTLIN_KRSTCLR_T UTLIN_KRSTCLR;
    /* offset  : 0x00F0.  */
    UTLIN_KRST1_T UTLIN_KRST1;
    /* offset  : 0x00F4.  */
    UTLIN_KRST0_T UTLIN_KRST0;
    /* offset  : 0x00F8.  */
    UTLIN_ACCEN1_T UTLIN_ACCEN1;
    /* offset  : 0x00FC.  */
    UTLIN_ACCEN0_T UTLIN_ACCEN0;
} Utlin_RegisterMap_t;

#define UTLIN0_ADDR ((uint32_t)0xF4001000)
#define UTLIN0_PTR  ((Utlin_RegisterMap_t *)UTLIN0_ADDR)
#define UTLIN0_RM   (*(Utlin_RegisterMap_t *)UTLIN0_ADDR)

#define UTLIN1_ADDR ((uint32_t)0xF4001100)
#define UTLIN1_PTR  ((Utlin_RegisterMap_t *)UTLIN1_ADDR)
#define UTLIN1_RM   (*(Utlin_RegisterMap_t *)UTLIN1_ADDR)

#define UTLIN2_ADDR ((uint32_t)0xF4001200)
#define UTLIN2_PTR  ((Utlin_RegisterMap_t *)UTLIN2_ADDR)
#define UTLIN2_RM   (*(Utlin_RegisterMap_t *)UTLIN2_ADDR)

#define UTLIN3_ADDR ((uint32_t)0xF4001300)
#define UTLIN3_PTR  ((Utlin_RegisterMap_t *)UTLIN3_ADDR)
#define UTLIN3_RM   (*(Utlin_RegisterMap_t *)UTLIN3_ADDR)

#define UTLIN4_ADDR ((uint32_t)0xF4001400)
#define UTLIN4_PTR  ((Utlin_RegisterMap_t *)UTLIN4_ADDR)
#define UTLIN4_RM   (*(Utlin_RegisterMap_t *)UTLIN4_ADDR)

#define UTLIN5_ADDR ((uint32_t)0xF4001500)
#define UTLIN5_PTR  ((Utlin_RegisterMap_t *)UTLIN5_ADDR)
#define UTLIN5_RM   (*(Utlin_RegisterMap_t *)UTLIN5_ADDR)

#define UTLIN6_ADDR ((uint32_t)0xF4001600)
#define UTLIN6_PTR  ((Utlin_RegisterMap_t *)UTLIN6_ADDR)
#define UTLIN6_RM   (*(Utlin_RegisterMap_t *)UTLIN6_ADDR)

#define UTLIN7_ADDR ((uint32_t)0xF4001700)
#define UTLIN7_PTR  ((Utlin_RegisterMap_t *)UTLIN7_ADDR)
#define UTLIN7_RM   (*(Utlin_RegisterMap_t *)UTLIN7_ADDR)

/**
 * @brief 检查所有UTLin外设
 *
 */
#define CHECK_UTLIN_ALL_PERIPH(MODULE)                                                                           \
        ((MODULE == UTLIN0_PTR) || (MODULE == UTLIN1_PTR) || (MODULE == UTLIN2_PTR) || (MODULE == UTLIN3_PTR) || \
         (MODULE == UTLIN4_PTR) || (MODULE == UTLIN5_PTR) || (MODULE == UTLIN6_PTR) || (MODULE == UTLIN7_PTR))   \

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
