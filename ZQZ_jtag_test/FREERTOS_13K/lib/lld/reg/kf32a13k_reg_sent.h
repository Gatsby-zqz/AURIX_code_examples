/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_sent.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-15
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
 *  |2023-12-15  |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef KF32A13K_REG_SENT_H_
#define KF32A13K_REG_SENT_H_

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
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁止控制位  */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁止状态  */
            __IO uint32_t RESERVED0 :1;  /*!< [2:2] 预留读为0  */
            __IO uint32_t EDIS      :1;  /*!< [3:3] 休眠模式禁止位  */
            __IO uint32_t RESERVED1 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] SENT模块版本信息位  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] SENT模块类型信息  */
            __I uint32_t MODNUM  :16; /*!< [31:16] SENT模块编号  */
        } bits;
        __I uint32_t reg;
    };
} SENT_INFO_T;

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
} SENT_DBG_T;

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
} SENT_RSTCLR_T;

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
} SENT_RST1_T;

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
} SENT_RST0_T;

typedef volatile struct
{
    __IO uint32_t reg; /*!< [31:0] 预留读为0  */
} SENT_ACES1_T;

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
} SENT_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STEP      :10; /*!< [9:0] 分频值  */
            __IO uint32_t RESERVED0 :4;  /*!< [13:10] 预留读为0  */
            __IO uint32_t DM        :2;  /*!< [15:14] 分频模式  */
            __I uint32_t  RESULT    :10; /*!< [25:16] 结果值，用于表示增加的值  */
            __IO uint32_t RESERVED1 :6;  /*!< [31:26] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_FDR_T;

typedef volatile struct
{
    __I uint32_t reg; /*!< [31:0] SENT模块当前的时间戳  */
} SENT_TSR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TDIV      :20; /*!< [19:0] TSR的预分频因子将ffracdiv/(TDIV+1)驱动TSR  */
            __I uint32_t  RESERVED0 :12; /*!< [31:20] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_TPD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t IPC0 :1; /*!< [0:0] 通道y上的中断挂起如果在寄存器SENT_IFy中通道y产生了任意中断请求  */
            __I uint32_t IPC1 :1; /*!< [1:1] 通道y上的中断挂起如果在寄存器SENT_IFy中通道y产生了任意中断请求  */
            __I uint32_t IPC2 :1; /*!< [2:2] 通道y上的中断挂起如果在寄存器SENT_IFy中通道y产生了任意中断请求  */
            __I uint32_t IPC3 :1; /*!< [3:3] 通道y上的中断挂起如果在寄存器SENT_IFy中通道y产生了任意中断请求  */
            __I uint32_t IPC4 :1; /*!< [4:4] 通道y上的中断挂起如果在寄存器SENT_IFy中通道y产生了任意中断请求  */
            __I uint32_t IPC5 :1; /*!< [5:5] 通道y上的中断挂起如果在寄存器SENT_IFy中通道y产生了任意中断请求  */
            __I uint32_t IPC6 :1; /*!< [6:6] 通道y上的中断挂起如果在寄存器SENT_IFy中通道y产生了任意中断请求  */
            __I uint32_t IPC7 :1; /*!< [7:7] 通道y上的中断挂起如果在寄存器SENT_IFy中通道y产生了任意中断请求  */
            __I uint32_t RESERVED0 :24;
        } bits;
        __I uint32_t reg;
    };
} SENT_INTOV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PDIV      :12; /*!< [11:0] 通道x的预分频因子 */
            __I uint32_t  RESERVED0 :20; /*!< [31:12] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_CPDR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DIV  :16; /*!< [15:0] 分频值CFDR的初始和参考分频值 */
            __I uint32_t  DIVM :16; /*!< [31:16] 测量分频值测量分频值 */
        } bits;
        __IO uint32_t reg;
    };
} SENT_CFDR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t WDL       :16; /*!< [15:0] 通道x的看门狗门限  */
            __I uint32_t  RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_WDT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CEN   :1; /*!< [0:0] 通道启用设置 */
            __IO uint32_t IEP   :1; /*!< [0:0] 忽略结束脉冲 */
            __IO uint32_t ACE   :1; /*!< [2:2] 替代CRC模式使能 */
            __IO uint32_t SNI   :1; /*!< [3:3] CRC包含状态半字节 */
            __IO uint32_t SDP   :1; /*!< [4:4] 串行数据处理模式该位开启自动串行数据处理 */
            __IO uint32_t SCDIS :1; /*!< [5:5] 串行数据CRC禁用模式该位选择CRC禁用模式  */
            __IO uint32_t CDIS  :1; /*!< [6:6] CRC禁用模式该位选择CRC禁用模式  */
            __IO uint32_t CFC   :1; /*!< [7:7] 连续帧检查 */
            __IO uint32_t FRL   :8; /*!< [8:8] 通道x设置的每帧半字节数据的数量 */
            __IO uint32_t CRZ   :1; /*!< [16:16] 串行数据CRC的零半字节 */
            __IO uint32_t ESF   :1; /*!< [17:17] 增强串行帧模式该位用来选择串行帧结构  */
            __IO uint32_t IDE   :1; /*!< [18:18] 忽略偏移错误模式 */
            __IO uint32_t SUSEN :1; /*!< [19:19] 挂起使能该位可通过OCDS(片上调试支持)可将SENT通道设置为暂停模式 */
            __IO uint32_t FDFL      :1;  /*!< [20:20] 基于帧长的频率偏移检查 */
            __I uint32_t  RESERVED0 :11; /*!< [31:21] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_RCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  CRC       :4;  /*!< [3:0] 最近一帧的CRC  */
            __I uint32_t  CST       :2;  /*!< [5:4] 通道状态  */
            __IO uint32_t RESERVED0 :2;  /*!< [7:6] 预留读为0  */
            __I uint32_t  SCN       :4;  /*!< [11:8] 最近一帧的状态和通信半字节  */
            __IO uint32_t RESERVED1 :4;  /*!< [15:12] 预留读为0  */
            __I uint32_t  FRLEN     :16; /*!< [31:16] 包括暂停帧的最近一帧长度 */
        } bits;
        __I uint32_t reg;
    };
} SENT_RSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RDNP0     :3;
            __I uint32_t  RESERVED0 :1;
            __IO uint32_t RDNP1     :3;
            __I uint32_t  RESERVED1 :1;
            __IO uint32_t RDNP2     :3;
            __I uint32_t  RESERVED2 :1;
            __IO uint32_t RDNP3     :3;
            __I uint32_t  RESERVED3 :1;
            __IO uint32_t RDNP4     :3;
            __I uint32_t  RESERVED4 :1;
            __IO uint32_t RDNP5     :3;
            __I uint32_t  RESERVED5 :1;
            __IO uint32_t RDNP6     :3;
            __I uint32_t  RESERVED6 :1;
            __IO uint32_t RDNP7     :3;
            __I uint32_t  RESERVED7 :1;
        } bits;
        __IO uint32_t reg;
    };
} SENT_VIEW_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RD0 :4;
            __IO uint32_t RD1 :4;
            __IO uint32_t RD2 :4;
            __IO uint32_t RD3 :4;
            __IO uint32_t RD4 :4;
            __IO uint32_t RD5 :4;
            __IO uint32_t RD6 :4;
            __IO uint32_t RD7 :4;
        } bits;
        __IO uint32_t reg;
    };
} SENT_RDAT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PLEN :6; /*!< [5:0] 脉冲长度定义脉冲的长度 */
            __IO uint32_t TRIG :2; /*!< [7:6] 触发源和模式选择选择触发源和模式 */
            __IO uint32_t DEL  :6; /*!< [13:8] 延迟长度选择SPC脉冲在触发条件后延迟的时间。*/
            __IO uint32_t BASE :1; /*!< [14:14] 时基选择脉冲时基  */
            __I uint32_t TRQ :1; /*!< [15:15] 发送请求处理中当一个SPC脉冲被发送时，这个位被设置。写访问被忽略  */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_SCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SD        :16;
            __I uint32_t MID       :8;
            __I uint32_t SCRC      :6;
            __I uint32_t RESERVED0 :1;
            __I uint32_t CON       :1;
        } bits;
        __I uint32_t reg;
    };
} SENT_SDAT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ALTI      :2; /*!< [1:0] 外部输入选择选择通道y的外部输入  */
            __IO uint32_t RESERVED0 :2; /*!< [3:2] 预留读为0  */
            __IO uint32_t DEPTH     :4; /*!< [7:4] 选择数字毛刺滤波器深度  */
            __IO uint32_t OIE       :1; /*!< [8:8] 通道x输出反向使能  */
            __IO uint32_t IIE       :1; /*!< [9:9] 通道x输入反向使能  */
            __O uint32_t  CEC       :1; /*!< [10:10] 清除边沿计数器 */
            __IO uint32_t RESERVED1 :1; /*!< [11:11] 预留读为0  */
            __IO uint32_t REG :1; /*!< [12:12] 通道x的上升沿毛刺标志显示通道x的毛刺检测状态  */
            __IO uint32_t FEG :1; /*!< [13:13] 通道x的下降沿毛刺标志显示通道x的毛刺检测状态  */
            __IO uint32_t CREG :1; /*!< [14:14] 清除通道x的上升沿毛刺标志清除状态标志REG，CREG始终读为零  */
            __IO uint32_t CFEG :1; /*!< [15:15] 清除通道x的下降沿毛刺标志清除状态标志FEG，CFEG始终读为零  */
            __IO uint32_t ETS :4; /*!< [19:16] 外部触发选择如果SCTLx.TRIG被编程为11B，则选择外部触发线  */
            __I uint32_t  ECNT :8; /*!< [27:20]边沿计数器?个饱和计数器(停止在0xFF)。  */
            __IO uint32_t CTR  :1; /*!< [28:28] 清除状态标志TRM，CTR总是读为零。  */
            __I uint32_t  TRM  :1; /*!< [29:29] 通道x的触发信号监视器显示通道x触发检测的状态 */
            __I uint32_t  RXM :1; /*!< [30:30] 接收信号在根据IIE指定的毛刺滤波和反相后的状态。  */
            __I uint32_t TXM :1; /*!< [31:31] 通道x的传输监视器显示OIE指定的通道x反向传输信号的状态  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_IOCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RSIF      :1;  /*!< [0:0] 接收成功中断请求标志位 */
            __I uint32_t  RDIF      :1;  /*!< [0:0] 接收数据中断请求标志位 */
            __I uint32_t  RBIF      :1;  /*!< [0:0] 接收缓冲区溢出中断请求标志位 */
            __I uint32_t  TDIF      :1;  /*!< [0:0] 发送数据中断请求标志位 */
            __I uint32_t  TBIF      :1;  /*!< [0:0] 发送缓冲区下溢中断请求标志位 */
            __I uint32_t  FRIF      :1;  /*!< [0:0] 频率范围中断请求标志位 */
            __I uint32_t  FDIF      :1;  /*!< [0:0] 频率偏移中断请求标志位 */
            __I uint32_t  NNIF      :1;  /*!< [0:0] Nibble数量错误请求标志位 */
            __I uint32_t  NVIF      :1;  /*!< [0:0] Nibble值超出范围请求标志位 */
            __I uint32_t  CRCIF     :1;  /*!< [0:0] CRC错误请求标志位 */
            __I uint32_t  WSIF      :1;  /*!< [0:0] 错误状态和通信半字节错误请求标志位 */
            __I uint32_t  SDIF      :1;  /*!< [0:0] 串行数据接收中断请求标志位 */
            __I uint32_t  SCRIF     :1;  /*!< [0:0] 串行数据CRC错误请求标志位 */
            __I uint32_t  WDIF      :1;  /*!< [0:0] 看门狗错误请求标志位 */
            __I uint32_t  LWIF      :1;  /*!< [0:0] 半字节低电平警告请求标志位 */
            __IO uint32_t RESERVED0 :17; /*!< [31:15] 预留读为0  */
        } bits;
        __I uint32_t reg;
    };
} SENT_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RSIE      :1;  /*!< [0:0] 启用中断请求RSIF  */
            __IO uint32_t RDIE      :1;  /*!< [1:1] 启用中断请求RDIF  */
            __IO uint32_t RBIE      :1;  /*!< [2:2] 启用中断请求RBIF  */
            __IO uint32_t TDIE      :1;  /*!< [3:3] 启用中断请求TDIF  */
            __IO uint32_t TBIE      :1;  /*!< [4:4] 启用中断请求TBIF  */
            __IO uint32_t FRIE      :1;  /*!< [5:5] 启用中断请求FRIF  */
            __IO uint32_t FDIE      :1;  /*!< [6:6] 启用中断请求FDIF  */
            __IO uint32_t NNIE      :1;  /*!< [7:7] 启用中断请求NNIF  */
            __IO uint32_t NVIE      :1;  /*!< [8:8] 启用中断请求NVIF  */
            __IO uint32_t CRCIE     :1;  /*!< [9:9] 启用中断请求CRCIF  */
            __IO uint32_t WSIE      :1;  /*!< [10:10] 启用中断请求WSIF  */
            __IO uint32_t SDIE      :1;  /*!< [11:11] 启用中断请求SDIF  */
            __IO uint32_t SCRIE     :1;  /*!< [12:12] 启用中断请求SCRIF  */
            __IO uint32_t WDIE      :1;  /*!< [13:13] 启用中断请求WDIF  */
            __IO uint32_t LWIE      :1;  /*!< [14:14] 启用中断请求LWIF  */
            __IO uint32_t RESERVED0 :17; /*!< [31:15] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  RSIS      :1;  /*!< [0:0] 置1中断请求标志位IFx.RSIF置起该位置1IFx.RSIF */
            __O uint32_t  RDIS      :1;  /*!< [1:1] 置1中断请求标志位IFx.RDIF置起该位置1IFx.RDIF */
            __O uint32_t  RBIS      :1;  /*!< [2:2] 置1中断请求标志位IFx.RBIF置起该位置1IFx.RBIF */
            __O uint32_t  TDIS      :1;  /*!< [3:3] 置1中断请求标志位IFx.TDIF置起该位置1IFx.TDIF */
            __O uint32_t  TBIS      :1;  /*!< [4:4] 置1中断请求标志位IFx.TBIF置起该位置1IFx.TBIF */
            __O uint32_t  FRIS      :1;  /*!< [5:5] 置1中断请求标志位IFx.FRIF置起该位置1IFx.FRIF */
            __O uint32_t  FDIS      :1;  /*!< [6:6] 置1中断请求标志位IFx.FDIF置起该位置1IFx.FDIF */
            __O uint32_t  NNIS      :1;  /*!< [7:7] 置1中断请求标志位IFx.NNIF置起该位置1IFx.NNIF */
            __O uint32_t  NVIS      :1;  /*!< [8:8] 置1中断请求标志位IFx.NVIF置起该位置1IFx.NVIF */
            __O uint32_t  CRCIS     :1;  /*!< [9:9] 置1中断请求标志位IFx.CRCIF置起该位置1IFx.CRCIF */
            __O uint32_t  WSIS      :1;  /*!< [10:10] 置1中断请求标志位IFx.WSIF置起该位置1IFx.WSIF */
            __O uint32_t  SDIS      :1;  /*!< [11:11] 置1中断请求标志位IFx.SDIF置起该位置1IFx.SDIF */
            __O uint32_t  SCRIS     :1;  /*!< [12:12] 置1中断请求标志位IFx.SCRIF置起该位置1IFx.SCRIF  */
            __O uint32_t  WDIS      :1;  /*!< [13:13] 置1中断请求标志位IFx.WDIF置起该位置1IFx.WDIF */
            __O uint32_t  LWIS      :1;  /*!< [14:14] 置1中断请求标志位IFx.LWIF置起该位置1IFx.LWIF */
            __IO uint32_t RESERVED0 :17; /*!< [31:15] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_IS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  RSIC      :1;  /*!< [0:0] 清零中断请求标志位IFx.RSIF置起该位清零IFx.RSIF */
            __O uint32_t  RDIC      :1;  /*!< [1:1] 清零中断请求标志位IFx.RDIF置起该位清零IFx.RDIF */
            __O uint32_t  RBIC      :1;  /*!< [2:2] 清零中断请求标志位IFx.RBIF置起该位清零IFx.RBIF */
            __O uint32_t  TDIC      :1;  /*!< [3:3] 清零中断请求标志位IFx.TDIF置起该位清零IFx.TDIF */
            __O uint32_t  TBIC      :1;  /*!< [4:4] 清零中断请求标志位IFx.TBIF置起该位清零IFx.TBIF */
            __O uint32_t  FRIC      :1;  /*!< [5:5] 清零中断请求标志位IFx.FRIF置起该位清零IFx.FRIF */
            __O uint32_t  FDIC      :1;  /*!< [6:6] 清零中断请求标志位IFx.FDIF置起该位清零IFx.FDIF */
            __O uint32_t  NNIC      :1;  /*!< [7:7] 清零中断请求标志位IFx.NNIF置起该位清零IFx.NNIF */
            __O uint32_t  NVIC      :1;  /*!< [8:8] 清零中断请求标志位IFx.NVIF置起该位清零IFx.NVIF */
            __O uint32_t  CRCIC     :1;  /*!< [9:9]  清零中断请求标志位IFx.CRCIF置起该位清零IFx.CRCIF */
            __O uint32_t  WSIC      :1;  /*!< [10:10] 清零中断请求标志位IFx.WSIF置起该位清零IFx.WSIF */
            __O uint32_t  SDIC      :1;  /*!< [11:11]清零中断请求标志位IFx.SDIF置起该位清零IFx.SDIF */
            __O uint32_t  SCRIC     :1;  /*!< [12:12] 清零中断请求标志位IFx.SCRIF置起该位清零IFx.SCRIF */
            __O uint32_t  WDIC      :1;  /*!< [13:13] 清零中断请求标志位IFx.WDIF置起该位清零IFx.WDIF */
            __O uint32_t  LWIC      :1;  /*!< [14:14] 清零中断请求标志位IFx.LWIF置起该位清零IFx.LWIF */
            __IO uint32_t RESERVED0 :17; /*!< [31:15] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} SENT_IC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RSIF  :4; /*!< [3:0] RSIF的中断节点指针该字段定义了中断节点 */
            __IO uint32_t RDIF  :4; /*!< [7:4] RDIF的中断节点指针该字段定义了中断节点 */
            __IO uint32_t RBIF  :4; /*!< [11:8] RBIF的中断节点指针该字段定义了中断节点 */
            __IO uint32_t TDIF  :4; /*!< [15:12] TDIF的中断节点指针该字段定义了中断节点 */
            __IO uint32_t TBIF  :4; /*!< [19:16] TBIF的中断节点指针该字段定义了中断节点 */
            __IO uint32_t ERRIF :4; /*!< [23:20] ERRORIF的中断节点指针该字段定义了中断节点 */
            __IO uint32_t SDIF  :4; /*!< [27:24] SDIF的中断节点指针该字段定义了中断节点 */
            __IO uint32_t WDIF  :4; /*!< [31:28] WDIF的中断节点指针该字段定义了中断节点 */
        } bits;
        __IO uint32_t reg;
    };
} SENT_ITRG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DIVM_ADJUST :16; /*!< [15:0] 频率范围检测微调配置值 */
            __I uint32_t  RESERVED0   :16; /*!< [31:16] 预留读为0 */
        } bits;
        __IO uint32_t reg;
    };
} SENT_DIVM_T;

typedef volatile struct
{
    __I uint32_t reg; /*!< [31:0] 通道x的最近接收时间戳该位字段显示了通道x上的最近一帧的时间戳。*/
} SENT_RTS_T;

typedef volatile struct
{
    SENT_CFDR_T SENT_CFDR;
    SENT_WDT_T  SENT_WDT;
    SENT_RCTL_T SENT_RCTL;
    SENT_RSTA_T SENT_RSTA;

    SENT_VIEW_T SENT_VIEW;
    SENT_RDAT_T SENT_RDAT;
    SENT_SCTL_T SENT_SCTL;
    SENT_SDAT_T SENT_SDAT;

    SENT_IOCTL_T SENT_IOCTL;
    SENT_IF_T    SENT_IF;
    SENT_IE_T    SENT_IE;
    SENT_IS_T    SENT_IS;

    SENT_IC_T   SENT_IC;
    SENT_ITRG_T SENT_ITRG;
    SENT_DIVM_T SENT_DIVM;
    uint32_t    RESERVED0;
} Sent_ChannelMap_T;

typedef volatile struct
{
    /* offset  : 0x0000.  */
    SENT_CLKC_T SENT_CLKC;
    /* offset  : 0x0004.  */
    uint32_t RESERVED0;
    /* offset  : 0x0008.  */
    SENT_INFO_T SENT_INFO;
    /* offset  : 0x000C.  */
    SENT_FDR_T SENT_FDR;
    /* offset  : 0x0010.  */
    uint32_t RESERVED1;
    /* offset  : 0x0014.  */
    SENT_TSR_T SENT_TSR;
    /* offset  : 0x0018.  */
    SENT_TPD_T SENT_TPD;
    /* offset  : 0x001C.  */
    SENT_INTOV_T SENT_INTOV;
    /* offset  : 0x0020.  */
    uint32_t RESERVED2[24];
    /* offset  : 0x0080.  */
    SENT_CPDR_T SENT_CPDR[8];
    /* offset  : 0x00A0.  */
    uint32_t RESERVED3[18];
    /* offset  : 0x00E8.  */
    SENT_DBG_T SENT_DBG;
    /* offset  : 0x00EC.  */
    SENT_RSTCLR_T SENT_RSTCLR;
    /* offset  : 0x00F0.  */
    SENT_RST1_T SENT_RST1;
    /* offset  : 0x00F4.  */
    SENT_RST0_T SENT_RST0;
    /* offset  : 0x00F8.  */
    SENT_ACES1_T SENT_ACES1;
    /* offset  : 0x00FC.  */
    SENT_ACES0_T SENT_ACES0;
} Sent_GeneralMap_t;

typedef volatile struct
{
    SENT_RTS_T SENT_RTS;
    /* offset  : 0x0004.  */
    uint32_t RESERVED0[15];
} Sent_ResetMap_t;

#define SENT_GENERAL_ADDR ((uint32_t)0xF0008000)
#define SENT_GENERAL_PTR  ((Sent_GeneralMap_t *)SENT_GENERAL_ADDR)
#define SENT_GENERAL_RM   (*(Sent_GeneralMap_t *)SENT_GENERAL_ADDR)

#define SENT_CHANNEL_ADDR ((uint32_t)0xF0008100)
#define SENT_CHANNEL_PTR  ((Sent_ChannelMap_T *)SENT_CHANNEL_ADDR)
#define SENT_CHANNEL_RM   (*(Sent_ChannelMap_T *)SENT_CHANNEL_ADDR)

#define SENT_RTS_ADDR ((uint32_t)0xF0008A80)
#define SENT_RTS_PTR  ((Sent_ResetMap_t *)SENT_RTS_ADDR)
#define SENT_RTS_RM   (*(Sent_ResetMap_t *)SENT_RTS_ADDR)

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
