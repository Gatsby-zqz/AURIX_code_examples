/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_adcs.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-04
 *  @Version         : V0.0.1.231128_alpha
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
 *  |2023-12-04    |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/

#ifndef _KF32DA13K_REG_ADCS_H_
#define _KF32DA13K_REG_ADCS_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include "kf_types.h"

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
#define ADCS_LLD_MODULE_NUM     (4U)
#define ADCS_LLD_CHANNEL_NUM    (16U)
#define ADCS_LLD_RESULT_REG_NUM (16U)
#define ADCS_LLD_QUEUE_NUM      (3U)
#define ADCS_LLD_QUEUE_STEP_NUM (16U)

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] 模块修订号 */
            __I uint32_t MODTYPE :8;  /*!< [15:8] 模块类型 */
            __I uint32_t GAINMOD :16; /*!< [31:16] 模块编号 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_ID_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CLKEN     :1;  /*!< [0:0] 模块使能控制位 */
            __I uint32_t  STA       :1;  /*!< [1:1] 模块状态指示位 */
            __I uint32_t  RESERVED0 :1;  /*!< [2:2] 预留，读为0 */
            __IO uint32_t SLPEN     :1;  /*!< [3:3] 睡眠模式使能控制 */
            __I uint32_t  RESERVED1 :28; /*!< [31:4] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ADCREV    :8;  /*!< [7:0] ADC 修订号 */
            __I uint32_t ADCTYPE   :8;  /*!< [15:8] ADC 类型 */
            __I uint32_t RESERVED0 :16; /*!< [31:16] 预留，读为0 */
        } bits;
        __I uint32_t reg;
    };
} ADCS_SUBID_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TGS       :2;  /*!< [1:0] 触发置位用于 OTGB0/1 */
            __IO uint32_t TG_B      :1;  /*!< [2:2] OTGB0/1 总线选择 */
            __O uint32_t  TG_P      :1;  /*!< [3:3] TGS、TGB 位域写权限保护 */
            __I uint32_t  RESERVED0 :20; /*!< [23:4] 预留，读为0 */
            __IO uint32_t SUS   :4; /*!< [27:24] DEBUG 挂起控制 控制模块对来自 DEBUG 挂起信号的反应 */
            __O uint32_t  SUS_P :1; /*!< [28:28] SUS 位域写保护 */
            __I uint32_t  SUSSTA    :1; /*!< [29:29] 挂起状态指示位 */
            __I uint32_t  RESERVED1 :2; /*!< [31:30] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CLR       :1;  /*!< [0:0] 复位状态清零位 */
            __I uint32_t RESERVED0 :31; /*!< [31:1] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_RSTCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位设置 */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位设置 */
            __I uint32_t  RSTSTAT   :1;  /*!< [1:1] 模块复位指示位 */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN0  :1; /*!< [0:0] 权限使能用于主机 TAG ID0 */
            __IO uint32_t EN1  :1; /*!< [1:1] 权限使能用于主机 TAG ID1 */
            __IO uint32_t EN2  :1; /*!< [2:2] 权限使能用于主机 TAG ID2 */
            __IO uint32_t EN3  :1; /*!< [3:3] 权限使能用于主机 TAG ID3 */
            __IO uint32_t EN4  :1; /*!< [4:4] 权限使能用于主机 TAG ID4 */
            __IO uint32_t EN5  :1; /*!< [5:5] 权限使能用于主机 TAG ID5 */
            __IO uint32_t EN6  :1; /*!< [6:6] 权限使能用于主机 TAG ID6 */
            __IO uint32_t EN7  :1; /*!< [7:7] 权限使能用于主机 TAG ID7 */
            __IO uint32_t EN8  :1; /*!< [8:8] 权限使能用于主机 TAG ID8 */
            __IO uint32_t EN9  :1; /*!< [9:9] 权限使能用于主机 TAG ID9 */
            __IO uint32_t EN10 :1; /*!< [10:10] 权限使能用于主机 TAG ID10 */
            __IO uint32_t EN11 :1; /*!< [11:11] 权限使能用于主机 TAG ID11 */
            __IO uint32_t EN12 :1; /*!< [12:12] 权限使能用于主机 TAG ID12 */
            __IO uint32_t EN13 :1; /*!< [13:13] 权限使能用于主机 TAG ID13 */
            __IO uint32_t EN14 :1; /*!< [14:14] 权限使能用于主机 TAG ID14 */
            __IO uint32_t EN15 :1; /*!< [15:15] 权限使能用于主机 TAG ID15 */
            __IO uint32_t EN16 :1; /*!< [16:16] 权限使能用于主机 TAG ID16 */
            __IO uint32_t EN17 :1; /*!< [17:17] 权限使能用于主机 TAG ID17 */
            __IO uint32_t EN18 :1; /*!< [18:18] 权限使能用于主机 TAG ID18 */
            __IO uint32_t EN19 :1; /*!< [19:19] 权限使能用于主机 TAG ID19 */
            __IO uint32_t EN20 :1; /*!< [20:20] 权限使能用于主机 TAG ID20 */
            __IO uint32_t EN21 :1; /*!< [21:21] 权限使能用于主机 TAG ID21 */
            __IO uint32_t EN22 :1; /*!< [22:22] 权限使能用于主机 TAG ID22 */
            __IO uint32_t EN23 :1; /*!< [23:23] 权限使能用于主机 TAG ID23 */
            __IO uint32_t EN24 :1; /*!< [24:24] 权限使能用于主机 TAG ID24 */
            __IO uint32_t EN25 :1; /*!< [25:25] 权限使能用于主机 TAG ID25 */
            __IO uint32_t EN26 :1; /*!< [26:26] 权限使能用于主机 TAG ID26 */
            __IO uint32_t EN27 :1; /*!< [27:27] 权限使能用于主机 TAG ID27 */
            __IO uint32_t EN28 :1; /*!< [28:28] 权限使能用于主机 TAG ID28 */
            __IO uint32_t EN29 :1; /*!< [29:29] 权限使能用于主机 TAG ID29 */
            __IO uint32_t EN30 :1; /*!< [30:30] 权限使能用于主机 TAG ID30 */
            __IO uint32_t EN31 :1; /*!< [31:31] 权限使能用于主机 TAG ID31 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_ACCEN0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :16; /*!< [15:0] 预留，读为0 */
            __IO uint32_t USC       :1;  /*!< [16:16] 同步模式控制 */
            __IO uint32_t SUPVSEL   :2;  /*!< [18:17] 供电电压电平选择 */
            __O uint32_t  CPWC      :1;  /*!< [19:19] 对 USC、SUPVSEL 位域的写权限设置 */
            __O uint32_t  QJZ       :1;  /*!< [20:20] 初始校准使能 */
            __I uint32_t  RESERVED1 :11; /*!< [31:21] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_GCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t APC       :1;  /*!< [0:0] ADC 通道控制寄存器权限保护 */
            __I uint32_t  RESERVED0 :15; /*!< [15:1] 预留，读为0 */
            __IO uint32_t API       :1;  /*!< [16:16] ADC 初始化寄存器权限保护 */
            __I uint32_t  RESERVED1 :15; /*!< [31:17] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_ACESP0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t APS       :1;  /*!< [0:0] ADC 服务中断寄存器权限保护 */
            __I uint32_t  RESERVED0 :15; /*!< [15:1] 预留，读为0 */
            __IO uint32_t APR       :1;  /*!< [16:16] ADC 结果寄存器权限保护 */
            __I uint32_t  RESERVED1 :15; /*!< [31:17] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_ACESP1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t APF       :1;  /*!< [0:0] ADC 比较通道寄存器权限保护 */
            __I uint32_t  RESERVED0 :15; /*!< [15:1] 预留，读为0 */
            __IO uint32_t APGC      :1;  /*!< [16:16] ADC 全局配置寄存器权限保护 */
            __IO uint32_t APEM      :1;  /*!< [17:17] ADC 外部多路复用器权限保护 */
            __IO uint32_t APTF      :1;  /*!< [18:18] ADC 测试寄存器权限保护 */
            __I uint32_t  RESERVED1 :13; /*!< [31:19] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_ACESP2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BOUND0    :12; /*!< [11:0] 用于边界值检测的边界值 0 */
            __I uint32_t  RESERVED0 :4;  /*!< [15:12] 预留，读为0 */
            __IO uint32_t BOUND1    :12; /*!< [27:16] 用于边界值检测的边界值 1 */
            __I uint32_t  RESERVED1 :4;  /*!< [31:28] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_GBOUNDSEL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :8;  /*!< [7:0] 预留，读为0 */
            __IO uint32_t REGF      :1;  /*!< [8:8] 全局结果事件标志位 */
            __I uint32_t  RESERVED1 :15; /*!< [23:9] 预留，读为0 */
            __O uint32_t  REGC      :1;  /*!< [24:24] 清除全局结果事件 */
            __I uint32_t  RESERVED2 :7;  /*!< [31:25] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_GEF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :16; /*!< [15:0] 预留，读为0 */
            __IO uint32_t REV0NP    :1;  /*!< [19:16] 全局结果服务中断线 */
            __I uint32_t  RESERVED1 :12; /*!< [31:20] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_GENP_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CDCH      :4; /*!< [3:0] 诊断的通道号 */
            __IO uint32_t CDGR      :4; /*!< [7:4] 诊断的 ADC 转换器号 */
            __IO uint32_t CDEN      :1; /*!< [8:8] 转换器诊断使能 */
            __IO uint32_t CDSEL     :2; /*!< [10:9] 转换器诊断拉动设备选择 */
            __I uint32_t  RESERVED0 :4; /*!< [14:11] 预留，读为0 */
            __O uint32_t  CDWC      :1; /*!< [15:15] 位域 CDCH、CDGR、CDSEL、CDEN 写权限控制 */
            __IO uint32_t PDD       :1; /*!< [16:16] 下拉诊断使能 */
            __IO uint32_t MDPD      :1; /*!< [17:17] 多路复用器下拉设备使能 */
            __IO uint32_t MDPU      :1; /*!< [18:18] 多路复用器上拉设备使能 */
            __I uint32_t  RESERVED1 :4; /*!< [22:19] 预留，读为0 */
            __O uint32_t  MDWC      :1; /*!< [23:23] 位域 MDPD、MDPU、PDD 写权限控制 */
            __I uint32_t  RESERVED2 :8; /*!< [31:24] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_GTESTCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TFEP      :1;  /*!< [0:0] ADC 的测试队列（队列 2）使能位 */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_GTESTE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :8; /*!< [7:0] 预留，读为0 */
            __IO uint32_t RINTCNT   :8; /*!< [15:8] 转换结果被覆盖次数设置 */
            __IO uint32_t DRCTL     :4; /*!< [19:16] 数据压缩控制 */
            __I uint32_t  RESERVED1 :3; /*!< [22:20] 预留，读为0 */
            __IO uint32_t CFCLR     :1; /*!< [23:23] 覆盖标志位 CF 清除 */
            __IO uint32_t WFR       :1; /*!< [24:24] 全局结果寄存器的读取模式 */
            __I uint32_t  RESERVED2 :5; /*!< [29:25] 预留,读为0  */
            __I uint32_t  CF        :1; /*!< [30:30] 结果值被覆盖标志位  */
            __IO uint32_t SRGEN     :1; /*!< [31:31] 服务中断使能位 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_GRESCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESULT   :16; /*!< [15:0] 转换结果存储位域 */
            __I           uint32_t :4;  /*!< [19:16] 预留，读为0 */
            __I uint32_t  CH       :5;  /*!< [24:20] 通道号 */
            __I uint32_t  EMUX     :3;  /*!< [27:25] 外部多路复用器的选择控制 */
            __I uint32_t  CRS      :2;  /*!< [29:28] 该转换结果来自的队列号 */
            __I uint32_t  CF       :1;  /*!< [30:30] 结果值被覆盖标志位 */
            __IO uint32_t VF       :1;  /*!< [31:31] 有效标志位 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_GRES_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESULT    :16; /*!< [15:0] 转换结果存储位域 */
            __I uint32_t GNR       :4;  /*!< [19:16] ADC 转换器，该结果来源的 ADC 转换器 */
            __I uint32_t CH        :5;  /*!< [24:20] 通道号 */
            __I uint32_t EMUX      :3;  /*!< [27:25] 外部多路复用器的选择控制 */
            __I uint32_t CRS       :2;  /*!< [29:28] 该转换结果来自的队列号 */
            __I uint32_t RESERVED0 :1;  /*!< [30:30] 预留，读为0 */
            __I uint32_t VF        :1;  /*!< [31:31] 有效标志位 */
        } bits;
        __I uint32_t reg;
    };
} ADCS_GRESDBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EMUXITF0 :4;  /*!< [3:0] 外部多路复用器接口 0 选择控制信号 */
            __IO uint32_t EMUXITF1 :4;  /*!< [7:4] 外部多路复用器接口 1 选择控制信号 */
            __I           uint32_t :24; /*!< [31:8] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_EMUXISEL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  TSC       :6; /*!< [5:0] 触发器序号计数器 */
            __I uint32_t  RESERVED0 :8; /*!< [13:6] 预留，读为0 */
            __I uint32_t  QACT      :1; /*!< [14:14] 队列 2 激活指示位 */
            __I uint32_t  OV        :1; /*!< [15:15] 非法触发检测指示位 */
            __IO uint32_t TSCSET    :6; /*!< [21:16] 用来定义 TSC 的初始值 */
            __I uint32_t  RESERVED1 :2; /*!< [23:22] 预留，读为0 */
            __IO uint32_t ITSEL     :2; /*!< [25:24] 内部触发信号选择 */
            __I uint32_t  RESERVED2 :2; /*!< [27:26] 预留，读为0 */
            __IO uint32_t SIE       :1; /*!< [28:28] 服务中断信号使能位 */
            __I uint32_t  RESERVED3 :2; /*!< [30:29] 预留，读为0 */
            __O uint32_t  COV :1; /*!< [31:31] 清除非法触发信号指示位 OV 和队列 2 激活指示位QACT */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_TRGCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ANONC     :2;  /*!< [1:0] 模拟转换控制位 */
            __I uint32_t  RESERVED0 :14; /*!< [15:2] 预留，读为0 */
            __I uint32_t  ANONS     :2;  /*!< [17:16] 模拟转换控制状态 */
            __I uint32_t  CSRC      :2;  /*!< [19:18] 当前正在运行的转换信息来源指示位 */
            __I uint32_t  CHNR      :5;  /*!< [24:20] 当前或上一个转换所对应的通道指示位 */
            __I uint32_t  SYNRUN    :1;  /*!< [25:25] 指示当前转换是否是同步平行转换 */
            __I uint32_t  RESERVED1 :2;  /*!< [27:26] 预留，读为0 */
            __I uint32_t  CAL       :1;  /*!< [28:28] 启动校准指示位 */
            __I uint32_t  RESERVED2 :1;  /*!< [29:29] 预留，读为0 */
            __I uint32_t  BUSY      :1;  /*!< [30:30] 转换运行指示位 */
            __I uint32_t  SAMPLE    :1;  /*!< [31:31] 采样结果指示位 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_ARBCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PTY0      :2;  /*!< [1:0] 队列 0 进行优先级配置， */
            __I uint32_t  RESERVED0 :1;  /*!< [2:2] 预留，读为0 */
            __IO uint32_t CSM0      :1;  /*!< [3:3] 队列 0转换仲裁切换模式 */
            __IO uint32_t PTY1      :2;  /*!< [5:4] 队列 1 进行优先级配置， */
            __I uint32_t  RESERVED1 :1;  /*!< [6:6] 预留，读为0 */
            __IO uint32_t CSM1      :1;  /*!< [7:7] 队列 1转换仲裁切换模式 */
            __IO uint32_t PTY2      :2;  /*!< [9:8] 队列 2 进行优先级配置 */
            __I uint32_t  RESERVED2 :1;  /*!< [10:10] 预留，读为0 */
            __IO uint32_t CSM2      :1;  /*!< [11:11] 队列 2转换仲裁切换模式 */
            __I uint32_t  RESERVED3 :12; /*!< [23:12] 预留，读为0 */
            __IO uint32_t ASEN0     :1;  /*!< [24:24] 队列 0 的仲裁源输入使能 */
            __IO uint32_t ASEN1     :1;  /*!< [25:25] 队列 1 的仲裁源输入使能 */
            __IO uint32_t ASEN2     :1;  /*!< [26:26] 队列 2 的仲裁源输入使能 */
            __I uint32_t  RESERVED4 :5;  /*!< [31:27] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_ARBPTY_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t IPE       :1; /*!< [0:0] 空闲状态预充电使能 */
            __IO uint32_t BE        :1; /*!< [1:1] 输入缓冲预充电使能  */
            __IO uint32_t RPE       :1; /*!< [2:2] 参考电压预充电使能  */
            __IO uint32_t RPC       :1; /*!< [3:3] 参考预充电时间控制  */
            __IO uint32_t CALSTC    :2; /*!< [5:4] 前校准采样时间控制  */
            __IO uint32_t DPCAL     :1; /*!< [6:6] 后校准使能位  */
            __I uint32_t  RESERVED0 :9; /*!< [15:7] 预留读为0  */
            __IO uint32_t ACSD      :3; /*!< [18:16] 模拟时钟同步延迟 */
            __IO uint32_t SSE       :1; /*!< [19:19] 采样同步控制 */
            __IO uint32_t CLKPDIV   :5; /*!< [24:20] 外设时钟分频预分频参数设置 */
            __I uint32_t  RESERVED1 :7; /*!< [31:25] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_ANCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ALIAS0    :5;  /*!< [4:0] 将用于通道 0 的转换切换到其他通道中 */
            __I uint32_t  RESERVED0 :3;  /*!< [7:5] 预留，读为0 */
            __IO uint32_t ALIAS1    :5;  /*!< [12:8] 将用于通道 1 的转换切换到其他通道中 */
            __I uint32_t  RESERVED1 :19; /*!< [31:13] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_ALIAS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BOUND0    :12; /*!< [11:0] 用于边界值检测的边界值 0 */
            __I uint32_t  RESERVED0 :4;  /*!< [15:12] 预留，读为0 */
            __IO uint32_t BOUND1    :12; /*!< [27:16] 用于边界值检测的边界值 1 */
            __I uint32_t  RESERVED1 :4;  /*!< [31:28] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_BOUNDSEL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STSEL     :2;  /*!< [1:0] 同步转换主从方选择 */
            __I uint32_t  RESERVED0 :2;  /*!< [3:2] 预留，读为0 */
            __IO uint32_t EVALR1    :1;  /*!< [4:4] 准备采样信号 R1 输入使能 */
            __IO uint32_t EVALR2    :1;  /*!< [5:5] 准备采样信号 R2 输入使能 */
            __IO uint32_t EVALR3    :1;  /*!< [6:6] 准备采样信号 R3 输入使能 */
            __I uint32_t  RESERVED1 :25; /*!< [31:7] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_SYNCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESSEL :4; /*!< [3:0] 结果寄存器选择 */
            __IO uint32_t TRSEL  :2; /*!< [5:4] 触发源选择 */
            __IO uint32_t XTSEL :7; /*!< [12:6] 外部触发输入信号选择(XTSEL=7FH 时，使用门信号作为触发信号) */
            __I uint32_t  XTLVL :1; /*!< [13:13] 外部触发信号电平指示位 */
            __IO uint32_t XTMOD :2; /*!< [15:14] 触发信号操作模式 */
            __O uint32_t  XTWC  :1; /*!< [16:16] 位域 XTMOD、XTSEL、TRSEL 写权限控制 */
            __IO uint32_t GTSEL :7; /*!< [23:17] 门输入信号选择(GTSEL=7FH 时，使用内部触发信号用于队列2) */
            __I uint32_t RESERVED0 :3; /*!< [26:24] 预留，读为0 */
            __IO uint32_t INMOD :1; /*!< [27:27] 队列模式选择,队列 0 可以选择多通道同时采样模式，队列 1 可以选择差分模式
                                     */
            __I uint32_t  GTLVL :1; /*!< [28:28] 门信号电平指示位 */
            __O uint32_t  GTWC  :1; /*!< [29:29] 位域 GTSEL 写权限控制 */
            __IO uint32_t TMEN  :1; /*!< [30:30] 定时器触发边沿选择 */
            __O uint32_t  TMWC  :1; /*!< [31:31] 位域 TMEN 写权限控制 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_QCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t GTEN      :2;  /*!< [1:0] 门信号使能控制 */
            __IO uint32_t EXTRGEN   :1;  /*!< [2:2] 外部触发信号使能 */
            __I uint32_t  RESERVED0 :5;  /*!< [7:3] 预留，读为0 */
            __O uint32_t  CLRF      :1;  /*!< [8:8] 清除有效标志位 */
            __O uint32_t  TREV      :1;  /*!< [9:9] 触发器事件 */
            __O uint32_t  FLUSH     :1;  /*!< [10:10] 刷新队列 */
            __O uint32_t  CEF       :1;  /*!< [11:11] 清除事件标志位 */
            __I uint32_t  RESERVED1 :4;  /*!< [15:12] 预留，读为0 */
            __IO uint32_t RPTDIS    :1;  /*!< [16:16] 被取消的转换信息处理设置 */
            __I uint32_t  RESERVED2 :15; /*!< [31:17] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_QMOD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t FILL      :4;  /*!< [3:0] 队列有效转换信息数量 */
            __I uint32_t RESERVED0 :1;  /*!< [4:4] 预留，读为0 */
            __I uint32_t EMPTY     :1;  /*!< [5:5] 队列空指示位 */
            __I uint32_t RESERVED1 :1;  /*!< [6:6] 预留，读为0 */
            __I uint32_t REQGT     :1;  /*!< [7:7] 门信号电平指示位 */
            __I uint32_t EF        :1;  /*!< [8:8] 触发事件检测 */
            __I uint32_t RESERVED2 :23; /*!< [31:9] 预留，读为0 */
        } bits;
        __I uint32_t reg;
    };
} ADCS_QSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t REQCH     :5;  /*!< [4:0] 转换的通道 */
            __I uint32_t RF        :1;  /*!< [5:5] 自动填充控制 */
            __I uint32_t ENSI      :1;  /*!< [6:6] 中断信号产生控制 */
            __I uint32_t EXTR      :1;  /*!< [7:7] 触发信号等待控制 */
            __I uint32_t V         :1;  /*!< [8:8] 该条转换信息是否有效 */
            __I uint32_t PDD       :1;  /*!< [9:9] 下拉诊断配置 */
            __I uint32_t MDPD      :1;  /*!< [10:10] 多路复用器下拉设备使能 */
            __I uint32_t MDPU      :1;  /*!< [11:11] 多路复用器上拉设备使能 */
            __I uint32_t CDEN      :1;  /*!< [12:12] 转换器诊断使能 */
            __I uint32_t CDSEL     :2;  /*!< [14:13] 转换器诊断拉动设备选择 */
            __I uint32_t RESERVED0 :17; /*!< [31:15] 预留，读为0 */
        } bits;
        __I uint32_t reg;
    };
} ADCS_Q0R_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t REQCH     :5;  /*!< [4:0] 转换的通道 */
            __O uint32_t RF        :1;  /*!< [5:5] 自动填充控制 */
            __O uint32_t ENSI      :1;  /*!< [6:6] 中断信号产生控制 */
            __O uint32_t EXTR      :1;  /*!< [7:7] 触发信号等待控制 */
            __I uint32_t RESERVED0 :1;  /*!< [8:8] 预留，读为0 */
            __O uint32_t PDD       :1;  /*!< [9:9] 下拉诊断配置 */
            __O uint32_t MDPD      :1;  /*!< [10:10] 多路复用器下拉设备使能 */
            __O uint32_t MDPU      :1;  /*!< [11:11] 多路复用器上拉设备使能 */
            __O uint32_t CDEN      :1;  /*!< [12:12] 转换器诊断使能 */
            __O uint32_t CDSEL     :2;  /*!< [14:13] 转换器诊断拉动设备选择 */
            __I uint32_t RESERVED1 :17; /*!< [31:15] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_QIN_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t REQCH     :5;  /*!< [4:0] 转换的通道 */
            __I uint32_t RF        :1;  /*!< [5:5] 自动填充控制 */
            __I uint32_t ENSI      :1;  /*!< [6:6] 中断信号产生控制 */
            __I uint32_t EXTR      :1;  /*!< [7:7] 触发信号等待控制 */
            __I uint32_t V         :1;  /*!< [8:8] 该条转换信息是否有效 */
            __I uint32_t PDD       :1;  /*!< [9:9] 下拉诊断配置 */
            __I uint32_t MDPD      :1;  /*!< [10:10] 多路复用器下拉设备使能 */
            __I uint32_t MDPU      :1;  /*!< [11:11] 多路复用器上拉设备使能 */
            __I uint32_t CDEN      :1;  /*!< [12:12] 转换器诊断使能 */
            __I uint32_t CDSEL     :2;  /*!< [14:13] 转换器诊断拉动设备选择 */
            __I uint32_t RESERVED0 :17; /*!< [31:15] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_QBKU_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SEQMOD    :2;  /*!< [1:0] 转换的通道 */
            __I uint32_t  RESERVED0 :4;  /*!< [5:2] 预留，读为0 */
            __IO uint32_t SEQTIMSET :10; /*!< [15:6] 定时触发器的开启值 */
            __O uint32_t  REQTS     :1;  /*!< [16:16] 触发定时器软件开启设置 */
            __IO uint32_t ENTR      :1;  /*!< [17:17] 触发信号开启触发定时器 */
            __I uint32_t  RESERVED1 :4;  /*!< [21:18] 预留，读为0 */
            __IO uint32_t SEQTIMOFF :10; /*!< [31:22] 触发定时器产生信号电平变化设置 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_REQTCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :6;  /*!< [5:0] 预留，读为0 */
            __I uint32_t SEQTIMER  :10; /*!< [15:6] 显示计数器当前的计数值 */
            __I uint32_t RESERVED1 :16; /*!< [31:16] 预留，读为0 */
        } bits;
        __I uint32_t reg;
    };
} ADCS_REQTST_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CEF0       :1; /*!< [0:0] 通道0的通道事件标志位 */
            __I uint32_t CEF1       :1; /*!< [1:1] 通道1的通道事件标志位 */
            __I uint32_t CEF2       :1; /*!< [2:2] 通道2的通道事件标志位 */
            __I uint32_t CEF3       :1; /*!< [3:3] 通道3的通道事件标志位 */
            __I uint32_t CEF4       :1; /*!< [4:4] 通道4的通道事件标志位 */
            __I uint32_t CEF5       :1; /*!< [5:5] 通道5的通道事件标志位 */
            __I uint32_t CEF6       :1; /*!< [6:6] 通道6的通道事件标志位 */
            __I uint32_t CEF7       :1; /*!< [7:7] 通道7的通道事件标志位 */
            __I uint32_t CEF8       :1; /*!< [8:8] 通道8的通道事件标志位 */
            __I uint32_t CEF9       :1; /*!< [9:9] 通道9的通道事件标志位 */
            __I uint32_t CEF10      :1; /*!< [10:10] 通道10的通道事件标志位 */
            __I uint32_t CEF11      :1; /*!< [11:11] 通道11的通道事件标志位 */
            __I uint32_t CEF12      :1; /*!< [12:12] 通道12的通道事件标志位 */
            __I uint32_t CEF13      :1; /*!< [13:13] 通道13的通道事件标志位 */
            __I uint32_t CEF14      :1; /*!< [14:14] 通道14的通道事件标志位 */
            __I uint32_t CEF15      :1; /*!< [15:15] 通道15的通道事件标志位 */
            __O uint32_t SOFT_CEF0  :1; /*!< [16:16] 软件触发通道0的通道事件 */
            __O uint32_t SOFT_CEF1  :1; /*!< [17:17] 软件触发通道1的通道事件 */
            __O uint32_t SOFT_CEF2  :1; /*!< [18:18] 软件触发通道2的通道事件 */
            __O uint32_t SOFT_CEF3  :1; /*!< [19:19] 软件触发通道3的通道事件 */
            __O uint32_t SOFT_CEF4  :1; /*!< [20:20] 软件触发通道4的通道事件 */
            __O uint32_t SOFT_CEF5  :1; /*!< [21:21] 软件触发通道5的通道事件 */
            __O uint32_t SOFT_CEF6  :1; /*!< [22:22] 软件触发通道6的通道事件 */
            __O uint32_t SOFT_CEF7  :1; /*!< [23:23] 软件触发通道7的通道事件 */
            __O uint32_t SOFT_CEF8  :1; /*!< [24:24] 软件触发通道8的通道事件 */
            __O uint32_t SOFT_CEF9  :1; /*!< [25:25] 软件触发通道9的通道事件 */
            __O uint32_t SOFT_CEF10 :1; /*!< [26:26] 软件触发通道10的通道事件 */
            __O uint32_t SOFT_CEF11 :1; /*!< [27:27] 软件触发通道11的通道事件 */
            __O uint32_t SOFT_CEF12 :1; /*!< [28:28] 软件触发通道12的通道事件 */
            __O uint32_t SOFT_CEF13 :1; /*!< [29:29] 软件触发通道13的通道事件 */
            __O uint32_t SOFT_CEF14 :1; /*!< [30:30] 软件触发通道14的通道事件 */
            __O uint32_t SOFT_CEF15 :1; /*!< [31:31] 软件触发通道15的通道事件 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_CEF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t REF0       :1; /*!< [0:0] 通道0结果事件标志位*/
            __I uint32_t REF1       :1; /*!< [1:1] 通道1结果事件标志位*/
            __I uint32_t REF2       :1; /*!< [2:2] 通道2结果事件标志位*/
            __I uint32_t REF3       :1; /*!< [3:3] 通道3结果事件标志位*/
            __I uint32_t REF4       :1; /*!< [4:4] 通道4结果事件标志位*/
            __I uint32_t REF5       :1; /*!< [5:5] 通道5结果事件标志位*/
            __I uint32_t REF6       :1; /*!< [6:6] 通道6结果事件标志位*/
            __I uint32_t REF7       :1; /*!< [7:7] 通道7结果事件标志位*/
            __I uint32_t REF8       :1; /*!< [8:8] 通道8结果事件标志位*/
            __I uint32_t REF9       :1; /*!< [9:9] 通道9结果事件标志位*/
            __I uint32_t REF10      :1; /*!< [10:10] 通道10结果事件标志位 */
            __I uint32_t REF11      :1; /*!< [11:11] 通道11结果事件标志位 */
            __I uint32_t REF12      :1; /*!< [12:12] 通道12结果事件标志位 */
            __I uint32_t REF13      :1; /*!< [13:13] 通道13结果事件标志位 */
            __I uint32_t REF14      :1; /*!< [14:14] 通道14结果事件标志位 */
            __I uint32_t REF15      :1; /*!< [15:15] 通道15结果事件标志位 */
            __O uint32_t SOFT_REF0  :1; /*!< [16:16] 通道0软件触发结果事件 */
            __O uint32_t SOFT_REF1  :1; /*!< [17:17] 通道1软件触发结果事件 */
            __O uint32_t SOFT_REF2  :1; /*!< [18:18] 通道2软件触发结果事件 */
            __O uint32_t SOFT_REF3  :1; /*!< [19:19] 通道3软件触发结果事件 */
            __O uint32_t SOFT_REF4  :1; /*!< [20:20] 通道4软件触发结果事件 */
            __O uint32_t SOFT_REF5  :1; /*!< [21:21] 通道5软件触发结果事件 */
            __O uint32_t SOFT_REF6  :1; /*!< [22:22] 通道6软件触发结果事件 */
            __O uint32_t SOFT_REF7  :1; /*!< [23:23] 通道7软件触发结果事件 */
            __O uint32_t SOFT_REF8  :1; /*!< [24:24] 通道8软件触发结果事件 */
            __O uint32_t SOFT_REF9  :1; /*!< [25:25] 通道9软件触发结果事件 */
            __O uint32_t SOFT_REF10 :1; /*!< [26:26] 通道10软件触发结果事件 */
            __O uint32_t SOFT_REF11 :1; /*!< [27:27] 通道11软件触发结果事件 */
            __O uint32_t SOFT_REF12 :1; /*!< [28:28] 通道12软件触发结果事件 */
            __O uint32_t SOFT_REF13 :1; /*!< [29:29] 通道13软件触发结果事件 */
            __O uint32_t SOFT_REF14 :1; /*!< [30:30] 通道14软件触发结果事件 */
            __O uint32_t SOFT_REF15 :1; /*!< [31:31] 通道15软件触发结果事件 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_REF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SEF0      :1;  /*!< [0:0] 队列0源事件标志位*/
            __I uint32_t SEF1      :1;  /*!< [1:1] 队列1源事件标志位*/
            __I uint32_t SEF2      :1;  /*!< [2:2] 队列2源事件标志位*/
            __I uint32_t RESERVED0 :1;  /*!< [3:3] 预留，读为0 */
            __O uint32_t SOFT_SEF0 :1;  /*!< [4:4] 软件触发队列0源事件*/
            __O uint32_t SOFT_SEF1 :1;  /*!< [5:5] 软件触发队列1源事件*/
            __O uint32_t SOFT_SEF2 :1;  /*!< [6:6] 软件触发队列2源事件*/
            __I uint32_t RESERVED1 :25; /*!< [31:7] 预留，读为0 */

        } bits;
        __IO uint32_t reg;
    };
} ADCS_SEF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CEV0NP :4; /*!< [3:0] 通道0事件的服务中断指针节点*/
            __IO uint32_t CEV1NP :4; /*!< [7:4] 通道1事件的服务中断指针节点*/
            __IO uint32_t CEV2NP :4; /*!< [11:8] 通道2事件的服务中断指针节点*/
            __IO uint32_t CEV3NP :4; /*!< [15:12] 通道3事件的服务中断指针节点*/
            __IO uint32_t CEV4NP :4; /*!< [19:16] 通道4事件的服务中断指针节点*/
            __IO uint32_t CEV5NP :4; /*!< [23:20] 通道5事件的服务中断指针节点*/
            __IO uint32_t CEV6NP :4; /*!< [27:24] 通道6事件的服务中断指针节点*/
            __IO uint32_t CEV7NP :4; /*!< [31:28] 通道7事件的服务中断指针节点*/

        } bits;
        __IO uint32_t reg;
    };
} ADCS_CENP0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CEV8NP  :4; /*!< [3:0] 通道8事件的服务中断指针节点*/
            __IO uint32_t CEV9NP  :4; /*!< [7:4] 通道9事件的服务中断指针节点*/
            __IO uint32_t CEV10NP :4; /*!< [11:8] 通道10事件的服务中断指针节点*/
            __IO uint32_t CEV11NP :4; /*!< [15:12] 通道11事件的服务中断指针节点*/
            __IO uint32_t CEV12NP :4; /*!< [19:16] 通道12事件的服务中断指针节点*/
            __IO uint32_t CEV13NP :4; /*!< [23:20] 通道13事件的服务中断指针节点*/
            __IO uint32_t CEV14NP :4; /*!< [27:24] 通道14事件的服务中断指针节点*/
            __IO uint32_t CEV15NP :4; /*!< [31:28] 通道15事件的服务中断指针节点*/

        } bits;
        __IO uint32_t reg;
    };
} ADCS_CENP1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t REV0NP :4; /*!< [3:0] 结果事件0的服务中断指针节点*/
            __IO uint32_t REV1NP :4; /*!< [7:4] 结果事件1的服务中断指针节点*/
            __IO uint32_t REV2NP :4; /*!< [11:8] 结果事件2的服务中断指针节点*/
            __IO uint32_t REV3NP :4; /*!< [15:12] 结果事件3的服务中断指针节点*/
            __IO uint32_t REV4NP :4; /*!< [19:16] 结果事件4的服务中断指针节点*/
            __IO uint32_t REV5NP :4; /*!< [23:20] 结果事件5的服务中断指针节点*/
            __IO uint32_t REV6NP :4; /*!< [27:24] 结果事件6的服务中断指针节点*/
            __IO uint32_t REV7NP :4; /*!< [31:28] 结果事件7的服务中断指针节点*/

        } bits;
        __IO uint32_t reg;
    };
} ADCS_RENP0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t REV8NP  :4; /*!< [3:0] 结果事件8的服务中断指针节点*/
            __IO uint32_t REV9NP  :4; /*!< [7:4] 结果事件9的服务中断指针节点*/
            __IO uint32_t REV10NP :4; /*!< [11:8] 结果事件10的服务中断指针节点*/
            __IO uint32_t REV11NP :4; /*!< [15:12] 结果事件11的服务中断指针节点*/
            __IO uint32_t REV12NP :4; /*!< [19:16] 结果事件12的服务中断指针节点*/
            __IO uint32_t REV13NP :4; /*!< [23:20] 结果事件13的服务中断指针节点*/
            __IO uint32_t REV14NP :4; /*!< [27:24] 结果事件14的服务中断指针节点*/
            __IO uint32_t REV15NP :4; /*!< [31:28] 结果事件15的服务中断指针节点*/

        } bits;
        __IO uint32_t reg;
    };
} ADCS_RENP1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SEV0NP    :4;  /*!< [3:0] 队列0源事件服务中断指针节点*/
            __IO uint32_t SEV1NP    :4;  /*!< [7:4] 队列1源事件服务中断指针节点*/
            __IO uint32_t SEV2NP    :4;  /*!< [11:8] 队列2源事件服务中断指针节点*/
            __I uint32_t  RESERVED0 :20; /*!< [31:12] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_SENP_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t AGSR0     :1;  /*!< [0:0] 软件激活转换器x的服务中断线0*/
            __O uint32_t AGSR1     :1;  /*!< [1:1] 软件激活转换器x的服务中断线1*/
            __O uint32_t AGSR2     :1;  /*!< [2:2] 软件激活转换器x的服务中断线2*/
            __O uint32_t AGSR3     :1;  /*!< [3:3] 软件激活转换器x的服务中断线3*/
            __I uint32_t RESERVED0 :4;  /*!< [7:4] 预留，读为0 */
            __O uint32_t ASSR0     :1;  /*!< [8:8] 软件激活转换x对应的公共服务中断线0*/
            __O uint32_t ASSR1     :1;  /*!< [9:9] 软件激活转换x对应的公共服务中断线1*/
            __O uint32_t ASSR2     :1;  /*!< [10:10] 软件激活转换x对应的公共服务中断线2*/
            __O uint32_t ASSR3     :1;  /*!< [11:11] 软件激活转换x对应的公共服务中断线3*/
            __I uint32_t RESERVED1 :20; /*!< [31:12] 预留，读为0 */

        } bits;
        __IO uint32_t reg;
    };
} ADCS_STRGACT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EMUXSEL   :3; /*!< [2:0] 外部多路复用器开始选择的通道*/
            __I uint32_t  RESERVED0 :1; /*!< [3:3] 预留，读为0 */
            __IO uint32_t EMUXMOD   :3; /*!< [6:4] 外部多路复用器通道变化模式*/
            __I uint32_t  RESERVED1 :5; /*!< [11:7] 预留，读为0 */
            __IO uint32_t EMXCOD    :1; /*!< [12:12]  外部多路复用器控制接口的编码格式*/
            __IO uint32_t EMXST     :1; /*!< [13:13] 外部通道的采样时间控制*/
            __I uint32_t  RESERVED2 :1; /*!< [14:14] 预留，读为0 */
            __IO uint32_t EMXWC     :1; /*!< [15:15] 位域 EMXMOD, EMXCOD, EMXST 写权限控制*/
            __I uint32_t  EMUXACT   :3; /*!< [18:16] 显示当前多路复用器选择的通道号*/
            __I uint32_t  RESERVED3 :1; /*!< [19:19] 预留，读为0 */
            __O uint32_t  EMUXCCB   :5; /*!< [24:20] 块模式下外部多路复用器通道选择的最后值*/
            __I uint32_t  RESERVED4 :7; /*!< [31:25] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_EMUXCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EMUXCH    :16; /*!< [15:0] 外部多路复用器输出口连接控制*/
            __I uint32_t  RESERVED0 :16; /*!< [31:16] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_EMUXCSEL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t VF0       :1;  /*!< [0:0] 结果寄存器ADCx_RES0有效标志位*/
            __IO uint32_t VF1       :1;  /*!< [1:1] 结果寄存器ADCx_RES1有效标志位*/
            __IO uint32_t VF2       :1;  /*!< [2:2] 结果寄存器ADCx_RES2有效标志位*/
            __IO uint32_t VF3       :1;  /*!< [3:3] 结果寄存器ADCx_RES3有效标志位*/
            __IO uint32_t VF4       :1;  /*!< [4:4] 结果寄存器ADCx_RES4有效标志位*/
            __IO uint32_t VF5       :1;  /*!< [5:5] 结果寄存器ADCx_RES5有效标志位*/
            __IO uint32_t VF6       :1;  /*!< [6:6] 结果寄存器ADCx_RES6有效标志位*/
            __IO uint32_t VF7       :1;  /*!< [7:7] 结果寄存器ADCx_RES7有效标志位*/
            __IO uint32_t VF8       :1;  /*!< [8:8] 结果寄存器ADCx_RES8有效标志位*/
            __IO uint32_t VF9       :1;  /*!< [9:9] 结果寄存器ADCx_RES9有效标志位*/
            __IO uint32_t VF10      :1;  /*!< [10:10] 结果寄存器ADCx_RES10有效标志位*/
            __IO uint32_t VF11      :1;  /*!< [11:11] 结果寄存器ADCx_RES11有效标志位*/
            __IO uint32_t VF12      :1;  /*!< [12:12] 结果寄存器ADCx_RES12有效标志位*/
            __IO uint32_t VF13      :1;  /*!< [13:13] 结果寄存器ADCx_RES13有效标志位*/
            __IO uint32_t VF14      :1;  /*!< [14:14] 结果寄存器ADCx_RES14有效标志位*/
            __IO uint32_t VF15      :1;  /*!< [15:15] 结果寄存器ADCx_RES15有效标志位*/
            __I uint32_t  RESERVED0 :16; /*!< [31:16] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_VF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :2; /*!< [1:0] 预留，读为0 */
            __IO uint32_t BNDSELL   :2; /*!< [3:2] 通道比较中下边界值选择*/
            __IO uint32_t BNDSELU   :2; /*!< [5:4] 通道比较中上边界值选择*/
            __IO uint32_t CHEVMOD   :2; /*!< [7:6] 通道事件产生条件选择*/
            __IO uint32_t SYNC      :1; /*!< [8:8] 同步平行转换请求*/
            __IO uint32_t REFSEL    :1; /*!< [9:9] ADC转换参考电压选择*/
            __IO uint32_t BNDSELX   :4; /*!< [13:10] 上边界值选择*/
            __IO uint32_t RESREG    :4; /*!< [17:14] 结果寄存器选择*/
            __IO uint32_t RESTGT    :1; /*!< [18:18] 目标结果寄存器类型选择*/
            __IO uint32_t RESPOS    :1; /*!< [19:19] 结果寄存器对齐格式选择*/
            __IO uint32_t SAMPTIME  :4; /*!< [23:20] 通道采样时间配置*/
            __IO uint32_t ESAMPTIME :4; /*!< [27:24] 外部扩展通道的采样时间配置*/
            __IO uint32_t PERCCH    :2; /*!< [29:28] 断路诊断/输入缓冲预充电选择*/
            __IO uint32_t PERCEN    :1; /*!< [30:30] 断路诊断检测使能/输入缓冲使能信号*/
            __I uint32_t  RESERVED1 :1; /*!< [31:31] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADCS_CHCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :8; /*!< [7:0] 预留，读为0 */
            __IO uint32_t RINTCNT   :8; /*!< [15:8] 转换结果被覆盖次数设置*/
            __IO uint32_t DRCTR     :4; /*!< [19:16] 数据压缩控制*/
            __IO uint32_t DMM       :2; /*!< [21:20] 数据修改模式*/
            __I uint32_t  RESERVED1 :1; /*!< [22:22] 预留，读为0 */
            __IO uint32_t CFCLR     :1; /*!< [23:23] 覆盖标志位CF清除*/
            __IO uint32_t WFR       :1; /*!< [24:24] 结果寄存器读取模式配置*/
            __IO uint32_t FEN       :2; /*!< [25:26] FIFO模式使能*/
            __I uint32_t  RESERVED2 :4; /*!< [30:27] 预留，读为0 */
            __IO uint32_t SRGEN     :1; /*!< [26:25] 服务中断产生使能*/
        } bits;
        __IO uint32_t reg;
    };
} ADCS_RCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESULT :16; /*!< [15:0] 转换结果保持到该位域*/
            __I uint32_t  DRC    :4;  /*!< [19:16] 数据压缩次数统计，采用的减一方式*/
            __I uint32_t  CHNR   :5;  /*!< [24:20] 转换结果对应的通道*/
            __I uint32_t  EMUX   :3;  /*!< [27:25] 外部多路复用器的通道*/
            __I uint32_t  CRS    :2;  /*!< [29:28] 转换队列来源*/
            __I uint32_t  CF     :1;  /*!< [30:30] 结果值被覆盖标志位*/
            __I uint32_t  VF     :1;  /*!< [31:31] 有效标志位*/
        } bits;
        __IO uint32_t reg;
    };
} ADCS_RES_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESULT :16; /*!< [15:0] 转换结果保持到该位域*/
            __I uint32_t DRC    :4;  /*!< [19:16] 数据压缩次数统计，采用的减一方式*/
            __I uint32_t CHNR   :5;  /*!< [24:20] 转换结果对应的通道*/
            __I uint32_t EMUX   :3;  /*!< [27:25] 外部多路复用器的通道*/
            __I uint32_t CRS    :2;  /*!< [29:28] 转换队列来源*/
            __I uint32_t CF     :1;  /*!< [30:30] 结果值被覆盖标志位*/
            __I uint32_t VF     :1;  /*!< [31:31] 有效标志位*/
        } bits;
        __I uint32_t reg;
    };
} ADCS_RESDBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STCF    :4; /*!< [3:0] 比较通道的采样时间*/
            __IO uint32_t PERCCH  :2; /*!< [5:4] 预充电电压选择*/
            __IO uint32_t INT_EN  :1; /*!< [6:6] 服务中断请求信号使能*/
            __O uint32_t  QJZ     :1; /*!< [7:7] 前校准使能信号*/
            __IO uint32_t CHEVMOD :2; /*!< [9:8] 通道事件产生模式*/
            __IO uint32_t CLKPDIV :5; /*!< [14:10] 模拟时钟分频设置*/
            __O uint32_t  CPWC    :1; /*!< [15:15] 位域 CLKPDIV、CHEVMOD、AIPF、RPC、STCF写权限控制*/
            __IO uint32_t XTSEL   :4; /*!< [19:16] 外部触发输入选择*/
            __I uint32_t  XTLVL   :1; /*!< [20:20] 触发输入信号的电平显示*/
            __IO uint32_t XTMOD   :2; /*!< [22:21] 触发器操作模式*/
            __IO uint32_t XTPOL   :1; /*!< [23:23] 外部触发输入信号翻转使能*/
            __IO uint32_t GTMOD   :2; /*!< [25:24] 门操作模式*/
            __IO uint32_t FCCHNR  :5; /*!< [30:26] 比较通道选择*/
            __O uint32_t  XTWC    :1; /*!< [31:31] 位域 FCCHNR、GTMOD、XTPOL、XTMOD、XTSEL写权限控制*/
        } bits;
        __IO uint32_t reg;
    };
} CMP_CCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RUNCOMP :2; /*!< [1:0] 比较通道运行控制*/
            __IO uint32_t RUNRAMP :2; /*!< [3:2] 梯度工作模式控制*/
            __IO uint32_t FCRDIR  :1; /*!< [4:4] 比较通道梯度变化方向*/
            __IO uint32_t ANON    :1; /*!< [5:5] 模拟转换控制*/
            __IO uint32_t ACSD    :2; /*!< [7:6] 模拟时钟同步延迟*/
            __IO uint32_t FCRTRIV :8; /*!< [15:8] 比较通道触发时间间隔*/
            __IO uint32_t SRG     :2; /*!< [17:16] 比较通道服务中断信号产生*/
            __IO uint32_t AUE     :2; /*!< [19:18] 比较通道中比较值设定*/
            __IO uint32_t SSE     :1; /*!< [20:20] 同步采样控制，采样启动时间同步于相位同步信号*/
            __O uint32_t  FCMWC   :1; /*!< [21:21] 位域 SSE, AUE, SRG, FCRTRIV, ACSD, ANON, FCRDIR, RUNRAMP, RUNCOMP
                                          写权限控制*/
            __IO uint32_t FCREF :10;  /*!< [31:22] 比较通道比较值设定*/
        } bits;
        __IO uint32_t reg;
    };
} CMP_MOD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FCRCOMPA  :10; /*!< [9:0] 比较通道中梯度值 A*/
            __I uint32_t  RESERVED0 :2;  /*!< [11:10] 预留，读为0 */
            __IO uint32_t AIPF      :4;  /*!< [15:12] 预充电采样时间配置*/
            __IO uint32_t FCRSTEP   :8;  /*!< [23:16] 梯度值变化时间间隔设置*/
            __I uint32_t  RESERVED1 :7;  /*!< [30:24] 预留，读为0 */
            __O uint32_t  FSWC      :1;  /*!< [31:31] 位域 FCRSTEP、FCRCOMPA、AIPF 写权限控制*/

        } bits;
        __IO uint32_t reg;
    };
} CMP_RAMPCTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FCRCOMPB  :10; /*!< [9:0] 比较通道中梯度值 A*/
            __I uint32_t  RESERVED0 :22; /*!< [31:10] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CMP_RAMPCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  BFL       :1; /*!< [0:0] 边界标志位*/
            __IO uint32_t BF_INT_EN :1; /*!< [1:1]  边界标志位触发中断产生使能控制*/
            __I uint32_t  RESERVED0 :2; /*!< [3:2] 预留，读为0 */
            __IO uint32_t BFA       :1; /*!< [4:4]  BFL位域激活选择*/
            __I uint32_t  RESERVED1 :3; /*!< [7:5] 预留，读为0 */
            __IO uint32_t BFI       :1; /*!< [8:8]  BFL值翻转设置*/
            __I uint32_t  RESERVED2 :3; /*!< [11:9] 预留，读为0 */
            __O uint32_t  BFS       :2; /*!< [13:12]  BFL值软件设置*/
            __I uint32_t  RESERVED3 :2; /*!< [15:14] 预留，读为0 */
            __IO uint32_t BFM       :1; /*!< [16:16]  边界标志位模式控制*/
            __IO uint32_t BFV :1; /*!< [17:17]  在 GTMOD=10b，且门输入信号为电平时，该位域的值可以代替 FCR 的值*/
            __I uint32_t  RESERVED4 :2; /*!< [19:18] 预留，读为0 */
            __IO uint32_t TIMOUT    :1; /*!< [20:20]  通道 x 转换超时标志位,软件写 1 清零*/
            __IO uint32_t TIMOUTEN  :1; /*!< [21:21]  使能当通道 x 转换超时时触发中断信号*/
            __I uint32_t  RESERVED5 :2; /*!< [23:22] 预留，读为0 */
            __IO uint32_t BFLNP     :4; /*!< [27:24]  边界标志指针节点设置*/
            __I uint32_t  FCR       :1; /*!< [28:28]  比较结果指示位*/
            __I uint32_t  RESERVED6 :2; /*!< [30:29] 预留，读为0 */
            __I uint32_t  VF        :1; /*!< [31:31]  有效标志位*/
        } bits;
        __IO uint32_t reg;
    };
} CMP_BOUNDF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :2;  /*!< [1:0] 预留，读为0 */
            __IO uint32_t DELTALOW  :10; /*!< [11:2]  低Delta值设定*/
            __O uint32_t  CMPV_CLR  :1;  /*!< [12:12]  CMPVALUE位域清零位*/
            __O uint32_t  RAMP_CLR  :1;  /*!< [13:13]  RAMP_END位域清零位*/
            __O uint32_t  FCR_CLR   :1;  /*!< [14:14]  FCR_EDGE位域清零位*/
            __I uint32_t  RESERVED1 :3;  /*!< [17:15] 预留，读为0 */
            __IO uint32_t DELTAUP   :10; /*!< [27:18]  高Delta值设定*/
            __I uint32_t  CMPVALUE  :1;  /*!< [28:28]  比较值变化触发中断标志位*/
            __I uint32_t  RAMP_END  :1;  /*!< [29:29]  梯度值变化到最后值时触发中断标志位*/
            __I uint32_t  FCR_EDGE  :1;  /*!< [30:30]  比较结边沿变化触发中断标志位*/
            __I uint32_t  RESERVED2 :1;  /*!< [31:31] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} CMP_HYST_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CEIC0     :1;  /*!< [0:0]  清除ADCx通道0对应的通道事件*/
            __O uint32_t CEIC1     :1;  /*!< [1:1]  清除ADCx通道1对应的通道事件*/
            __O uint32_t CEIC2     :1;  /*!< [2:2]  清除ADCx通道2对应的通道事件*/
            __O uint32_t CEIC3     :1;  /*!< [3:3]  清除ADCx通道3对应的通道事件*/
            __O uint32_t CEIC4     :1;  /*!< [4:4]  清除ADCx通道4对应的通道事件*/
            __O uint32_t CEIC5     :1;  /*!< [5:5]  清除ADCx通道5对应的通道事件*/
            __O uint32_t CEIC6     :1;  /*!< [6:6]  清除ADCx通道6对应的通道事件*/
            __O uint32_t CEIC7     :1;  /*!< [7:7]  清除ADCx通道7对应的通道事件*/
            __O uint32_t CEIC8     :1;  /*!< [8:8]  清除ADCx通道8对应的通道事件*/
            __O uint32_t CEIC9     :1;  /*!< [9:9]  清除ADCx通道9对应的通道事件*/
            __O uint32_t CEIC10    :1;  /*!< [10:10]  清除ADCx通道10对应的通道事件*/
            __O uint32_t CEIC11    :1;  /*!< [11:11]  清除ADCx通道11对应的通道事件*/
            __O uint32_t CEIC12    :1;  /*!< [12:12]  清除ADCx通道12对应的通道事件*/
            __O uint32_t CEIC13    :1;  /*!< [13:13]  清除ADCx通道13对应的通道事件*/
            __O uint32_t CEIC14    :1;  /*!< [14:14]  清除ADCx通道14对应的通道事件*/
            __O uint32_t CEIC15    :1;  /*!< [15:15]  清除ADCx通道15对应的通道事件*/
            __I uint32_t RESERVED0 :16; /*!< [31:16] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADC_CEFCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t REIC0     :1;  /*!< [0:0]  清除ADCx结果寄存器0对应的结果事件*/
            __O uint32_t REIC1     :1;  /*!< [1:1]  清除ADCx结果寄存器1对应的结果事件*/
            __O uint32_t REIC2     :1;  /*!< [2:2]  清除ADCx结果寄存器2对应的结果事件*/
            __O uint32_t REIC3     :1;  /*!< [3:3]  清除ADCx结果寄存器3对应的结果事件*/
            __O uint32_t REIC4     :1;  /*!< [4:4]  清除ADCx结果寄存器4对应的结果事件*/
            __O uint32_t REIC5     :1;  /*!< [5:5]  清除ADCx结果寄存器5对应的结果事件*/
            __O uint32_t REIC6     :1;  /*!< [6:6]  清除ADCx结果寄存器6对应的结果事件*/
            __O uint32_t REIC7     :1;  /*!< [7:7]  清除ADCx结果寄存器7对应的结果事件*/
            __O uint32_t REIC8     :1;  /*!< [8:8]  清除ADCx结果寄存器8对应的结果事件*/
            __O uint32_t REIC9     :1;  /*!< [9:9]  清除ADCx结果寄存器9对应的结果事件*/
            __O uint32_t REIC10    :1;  /*!< [10:10]  清除ADCx结果寄存器10对应的结果事件*/
            __O uint32_t REIC11    :1;  /*!< [11:11]  清除ADCx结果寄存器11对应的结果事件*/
            __O uint32_t REIC12    :1;  /*!< [12:12]  清除ADCx结果寄存器12对应的结果事件*/
            __O uint32_t REIC13    :1;  /*!< [13:13]  清除ADCx结果寄存器13对应的结果事件*/
            __O uint32_t REIC14    :1;  /*!< [14:14]  清除ADCx结果寄存器14对应的结果事件*/
            __O uint32_t REIC15    :1;  /*!< [15:15]  清除ADCx结果寄存器15对应的结果事件*/
            __I uint32_t RESERVED0 :16; /*!< [31:16] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADC_REFCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t SEIC0     :1;  /*!< [0:0]  清除ADCx队列0对应的源事件*/
            __O uint32_t SEIC1     :1;  /*!< [1:1]  清除ADCx队列1对应的源事件*/
            __O uint32_t SEIC2     :1;  /*!< [2:2]  清除ADCx队列2对应的源事件*/
            __I uint32_t RESERVED0 :29; /*!< [31:3] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADC_SEFCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESULT :16; /*!< [15:0]  当相应的目标结果寄存器配置为累加时，该位域为每次累加后除以2后的结果*/
            __I uint32_t RESERVED0 :15; /*!< [30:16] 预留，读为0 */
            __I uint32_t VF        :1;  /*!< [31:31]  有效标志位*/
        } bits;
        __I uint32_t reg;
    };
} ADC_AVERSULT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESULT :16; /*!< [15:0]  当相应的目标结果寄存器配置为累加时，该位域为每次累加后除以2后的结果*/
            __I uint32_t RESERVED0 :15; /*!< [30:16] 预留，读为0 */
            __I uint32_t VF        :1;  /*!< [31:31]  有效标志位*/
        } bits;
        __I uint32_t reg;
    };
} ADC_GAVERSULT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :4; /*!< [3:0] 预留，读为0 */
            __IO uint32_t AIPS      :4; /*!< [7:4]  模拟输入缓冲预充电*/
            __I uint32_t  RESERVED1 :2; /*!< [9:8] 预留，读为0 */
            __IO uint32_t SESPS     :1; /*!< [10:10]  伪随机采样使能*/
            __I uint32_t  RESERVED2 :4; /*!< [14:11] 预留，读为0 */
            __IO uint32_t TIMOUT    :1; /*!< [15:15]  通道 y 转换超时标志位,软件写 1 清零*/
            __I uint32_t  RESERVED3 :3; /*!< [18:16] 预留，读为0 */
            __IO uint32_t TIMOUTEN  :1; /*!< [19:19]  使能当通道 y 转换超时时触发中断信号*/
            __IO uint32_t AIPE      :4; /*!< [23:20]  外部模拟输入时的预充电时间配置*/
            __I uint32_t  RESERVED4 :2; /*!< [25:24] 预留，读为0 */
            __IO uint32_t SESPE     :1; /*!< [26:26]  伪随机采样使能*/
            __IO uint32_t CHEVENT_EN :1; /*!< [27:27]  该通道转换完成后，通道事件触发中断线使能信号*/
            __I uint32_t :4;             /*!< [31:28] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADC_CHINF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EMUX_SEL0 :4;  /*!< [3:0]  外扩通道控制接口 VADCEMUX0 控制选择来源*/
            __I uint32_t  RESERVED0 :12; /*!< [15:4] 预留，读为0 */
            __IO uint32_t EMUX_SEL1 :4;  /*!< [19:16]  外扩通道控制接口 VADCEMUX1 控制选择来源*/
            __I uint32_t  RESERVED1 :12; /*!< [31:20] 预留，读为0 */
        } bits;
        __IO uint32_t reg;
    };
} ADC_EMUXITFCSEL_T;

typedef volatile struct
{
    /* offset  : 0x0000.    ADC 时钟控制寄存器. */
    ADCS_CLKC_T ADCS_CLKC[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0010. */
    uint8_t ADCS_RESERVED_0010[32];

    /* offset  : 0x0030.    ADC 时钟控制寄存器. */
    ADCS_SUBID_T ADCS_SUBID[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0040. */
    uint8_t ADCS_RESERVED_0040[32];

    /* offset  : 0x0060.    ADC Debug 控制状态寄存器. */
    ADCS_DBG_T ADCS_DBG[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0070. */
    uint8_t ADCS_RESERVED_0070[32];

    /* offset  : 0x0090.    ADC 复位状态标志位清除寄存器. */
    ADCS_RSTCLR_T ADCS_RSTCLR[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x00A0. */
    uint8_t ADCS_RESERVED_00A0[32];
    /* offset  : 0x00C0.    复位控制寄存器 1. */
    ADCS_RST1_T ADCS_RST1[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x00D0. */
    uint8_t ADCS_RESERVED_00D0[32];

    /* offset  : 0x00F0.    ADC 复位控制寄存器 0. */
    ADCS_RST0_T ADCS_RST0[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0100. */
    uint8_t ADCS_RESERVED_0100[32];

    /* offset  : 0x0120.    ADC 访问权限控制寄存器 0. */
    ADCS_ACCEN0_T ADCS_ACCEN0[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0130. */
    uint8_t ADCS_RESERVED_0130[32];

    /* offset  : 0x0150.    ADC 全局配置寄存器. */
    ADCS_GCTL_T ADCS_GCTL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0160. */
    uint8_t ADCS_RESERVED_0160[32];

    /* offset  : 0x0180.    ADC 写保护权限控制寄存器0. */
    ADCS_ACESP0_T ADCS_ACESP0[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0190. */
    uint8_t ADCS_RESERVED_0190[32];

    /* offset  : 0x01B0.    ADC 写保护权限控制寄存器1. */
    ADCS_ACESP1_T ADCS_ACESP1[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x01C0. */
    uint8_t ADCS_RESERVED_01C0[32];

    /* offset  : 0x01E0.    ADC 写保护权限控制寄存器2. */
    ADCS_ACESP2_T ADCS_ACESP2[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x01F0. */
    uint8_t ADCS_RESERVED_01F0[32];

    /* offset  : 0x0210.    ADC 全局边界选择寄存器. */
    ADCS_GBOUNDSEL_T ADCS_GBOUNDSEL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0220. */
    uint8_t ADCS_RESERVED_0220[32];

    /* offset  : 0x0240.    ADC 全局结果事件标志位寄存器. */
    ADCS_GEF_T ADCS_GEF[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0250. */
    uint8_t ADCS_RESERVED_0250[32];

    /* offset  : 0x0270.    ADC 全局结果事件指针节点寄存器. */
    ADCS_GENP_T ADCS_GENP[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0280. */
    uint8_t ADCS_RESERVED_0280[32];

    /* offset  : 0x02A0.    ADC 全局诊断配置寄存器. */
    ADCS_GTESTCTL_T ADCS_GTESTCTL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x02B0. */
    uint8_t ADCS_RESERVED_02B0[32];

    /* offset  : 0x02D0.    ADC 全局测试使能寄存器. */
    ADCS_GTESTE_T ADCS_GTESTE[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x02E0. */
    uint8_t ADCS_RESERVED_02E0[32];

    /* offset  : 0x0300.    ADC 全局结果控制寄存器. */
    ADCS_GRESCTL_T ADCS_GRESCTL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0310. */
    uint8_t ADCS_RESERVED_0310[32];

    /* offset  : 0x0330.    ADC 全局结果寄存器. */
    ADCS_GRES_T ADCS_GRES[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0340. */
    uint8_t ADCS_RESERVED_0340[32];

    /* offset  : 0x0360.    ADC 全局调试结果寄存器. */
    ADCS_GRESDBG_T ADCS_GRESDBG[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0370. */
    uint8_t ADCS_RESERVED_0370[32];

    /* offset  : 0x0390.    ADC 全局调试结果寄存器. */
    ADCS_EMUXISEL_T ADCS_EMUXISEL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x03A0. */
    uint8_t ADCS_RESERVED_03A0[32];

    /* offset  : 0x03C0.    ADC 触发控制寄存器. */
    ADCS_TRGCTL_T ADCS_TRGCTL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x03D0. */
    uint8_t ADCS_RESERVED_03D0[32];

    /* offset  : 0x03F0.    ADC 仲裁配置寄存器. */
    ADCS_ARBCTL_T ADCS_ARBCTL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0400. */
    uint8_t ADCS_RESERVED_0400[32];

    /* offset  : 0x0420.    ADC 仲裁优先级配置寄存器. */
    ADCS_ARBPTY_T ADCS_ARBPTY[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0430. */
    uint8_t ADCS_RESERVED_0430[32];

    /* offset  : 0x0450.    ADC 仲裁优先级配置寄存器. */
    ADCS_ANCTL_T ADCS_ANCTL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0460. */
    uint8_t ADCS_RESERVED_0460[32];

    /* offset  : 0x0480.    ADC 仲裁优先级配置寄存器. */
    ADCS_ALIAS_T ADCS_ALIAS[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0490. */
    uint8_t ADCS_RESERVED_0490[32];

    /* offset  : 0x04B0.    ADC 边界选择寄存器. */
    ADCS_BOUNDSEL_T ADCS_BOUNDSEL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x04C0. */
    uint8_t ADCS_RESERVED_04C0[32];

    /* offset  : 0x04E0.    ADC 同步控制寄存器. */
    ADCS_SYNCTL_T ADCS_SYNCTL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x04F0. */
    uint8_t ADCS_RESERVED_04F0[32];

    /* offset  : 0x0510.    ADC 队列 n 控制寄存器. */
    ADCS_QCTL_T ADCS_QCTL[ADCS_LLD_MODULE_NUM][ADCS_LLD_QUEUE_NUM];

    /* offset  : 0x0540. */
    uint8_t ADCS_RESERVED_0540[96];

    /* offset  : 0x05A0.    ADC 队列 n 模式寄存器. */
    ADCS_QMOD_T ADCS_QMOD[ADCS_LLD_MODULE_NUM][ADCS_LLD_QUEUE_NUM];

    /* offset  : 0x05D0. */
    uint8_t ADCS_RESERVED_05D0[96];

    /* offset  : 0x0630.    ADC 队列 n 模式寄存器. */
    ADCS_QSTA_T ADCS_QSTA[ADCS_LLD_MODULE_NUM][ADCS_LLD_QUEUE_NUM];

    /* offset  : 0x0660. */
    uint8_t ADCS_RESERVED_0660[96];

    /* offset  : 0x06C0.    ADC 队列 n 第 0 阶寄存器. */
    ADCS_Q0R_T ADCS_Q0R[ADCS_LLD_MODULE_NUM][ADCS_LLD_QUEUE_NUM];

    /* offset  : 0x06F0. */
    uint8_t ADCS_RESERVED_06F0[96];

    /* offset  : 0x0750.    ADC 队列 n 输入阶寄存器. */
    ADCS_QIN_T ADCS_QIN[ADCS_LLD_MODULE_NUM][ADCS_LLD_QUEUE_NUM];

    /* offset  : 0x0780. */
    uint8_t ADCS_RESERVED_0780[96];

    /* offset  : 0x07E0.    ADC 队列 n 备份阶寄存器. */
    ADCS_QBKU_T ADCS_QBKU[ADCS_LLD_MODULE_NUM][ADCS_LLD_QUEUE_NUM];

    /* offset  : 0x0810. */
    uint8_t ADCS_RESERVED_0810[96];

    /* offset  : 0x0870.    ADC 队列 n 请求定时器模式配置寄存器. */
    ADCS_REQTCTL_T ADCS_REQTCTL[ADCS_LLD_MODULE_NUM][ADCS_LLD_QUEUE_NUM];

    /* offset  : 0x08A0. */
    uint8_t ADCS_RESERVED_08A0[96];

    /* offset  : 0x0900.    ADC 队列 n 请求定时状态寄存器. */
    ADCS_REQTST_T ADCS_REQTST[ADCS_LLD_MODULE_NUM][ADCS_LLD_QUEUE_NUM];

    /* offset  : 0x0930. */
    uint8_t ADCS_RESERVED_0930[96];

    /* offset  : 0x0990.    ADC 通道事件标志位寄存器. */
    ADCS_CEF_T ADCS_CEF[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x09A0. */
    uint8_t ADCS_RESERVED_09A0[32];

    /* offset  : 0x09C0.    ADC 结果事件标志位寄存器. */
    ADCS_REF_T ADCS_REF[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x09D0. */
    uint8_t ADCS_RESERVED_09D0[32];

    /* offset  : 0x09F0.    ADC 源事件标志位寄存器. */
    ADCS_SEF_T ADCS_SEF[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0A00. */
    uint8_t ADCS_RESERVED_0A00[32];

    /* offset  : 0x0A20.    ADC 通道事件指针节点寄存器0. */
    ADCS_CENP0_T ADCS_CENP0[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0A30. */
    uint8_t ADCS_RESERVED_0A30[32];

    /* offset  : 0x0A50.    ADC 通道事件指针节点寄存器1. */
    ADCS_CENP1_T ADCS_CENP1[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0A60. */
    uint8_t ADCS_RESERVED_0A60[32];

    /* offset  : 0x0A80.    ADC 结果事件指针节点寄存器0. */
    ADCS_RENP0_T ADCS_RENP0[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0A90. */
    uint8_t ADCS_RESERVED_0A90[32];

    /* offset  : 0x0AB0.    ADC 结果事件指针节点寄存器0. */
    ADCS_RENP1_T ADCS_RENP1[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0AC0. */
    uint8_t ADCS_RESERVED_0AC0[32];

    /* offset  : 0x0AE0.    ADC 源事件指针节点寄存器. */
    ADCS_SENP_T ADCS_SENP[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0AF0. */
    uint8_t ADCS_RESERVED_0AF0[32];

    /* offset  : 0x0B10.    ADC 软件激活服务中断线寄存器. */
    ADCS_STRGACT_T ADCS_STRGACT[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0B20. */
    uint8_t ADCS_RESERVED_0B20[32];

    /* offset  : 0x0B40.    ADC 外部多路复用器通道控制寄存器. */
    ADCS_EMUXCTL_T ADCS_EMUXCTL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0B50. */
    uint8_t ADCS_RESERVED_0B250[32];

    /* offset  : 0x0B70.    ADC 外部多路复用器通道选择寄存器. */
    ADCS_EMUXCSEL_T ADCS_EMUXCSEL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0B80. */
    uint8_t ADCS_RESERVED_0B80[32];

    /* offset  : 0x0BA0.    ADC 结果有效标志位寄存器. */
    ADCS_VF_T ADCS_VF[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x0BB0. */
    uint8_t ADCS_RESERVED_0BB0[32];

    /* offset  : 0x0BD0.    ADC 通道控制寄存器. */
    ADCS_CHCTL_T ADCS_CHCTL[ADCS_LLD_MODULE_NUM][ADCS_LLD_CHANNEL_NUM];

    /* offset  : 0x0CD0. */
    uint8_t ADCS_RESERVED_0CD0[256];

    /* offset  : 0x0ED0.    ADC 结果控制寄存器. */
    ADCS_RCTL_T ADCS_RCTL[ADCS_LLD_MODULE_NUM][ADCS_LLD_RESULT_REG_NUM];

    /* offset  : 0x0FD0. */
    uint8_t ADCS_RESERVED_0FD0[512];

    /* offset  : 0x11D0.    ADC 结果寄存器. */
    ADCS_RES_T ADCS_RES[ADCS_LLD_MODULE_NUM][ADCS_LLD_RESULT_REG_NUM];

    /* offset  : 0x12D0. */
    uint8_t ADCS_RESERVED_12D0[512];

    /* offset  : 0x14D0.    ADC 调试结果寄存器. */
    ADCS_RESDBG_T ADCS_RESDBG[ADCS_LLD_MODULE_NUM][ADCS_LLD_RESULT_REG_NUM];

    /* offset  : 0x15D0. */
    uint8_t ADCS_RESERVED_15D0[512];

    /* offset  : 0x17D0.    CMP比较通道控制寄存器. */
    CMP_CCTL_T CMP_CCTL[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x17E0. */
    uint8_t ADCS_RESERVED_17E0[32];

    /* offset  : 0x1800.    CMP比较通道模式寄存器. */
    CMP_MOD_T CMP_MOD[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x1810. */
    uint8_t ADCS_RESERVED_1810[32];

    /* offset  : 0x1830.    比较通道梯度值配置寄存器 0. */
    CMP_RAMPCTL0_T CMP_RAMPCTL0[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x1840. */
    uint8_t ADCS_RESERVED_1840[32];

    /* offset  : 0x1860.    比较通道梯度值配置寄存器 1. */
    CMP_RAMPCTL1_T CMP_RAMPCTL1[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x1870. */
    uint8_t ADCS_RESERVED_1870[32];

    /* offset  : 0x1890.    比较通道边界标志位寄存器. */
    CMP_BOUNDF_T CMP_BOUNDF[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x18A0. */
    uint8_t ADCS_RESERVED_18A0[32];

    /* offset  : 0x18C0.    比较通道迟滞配置寄存器. */
    CMP_HYST_T CMP_HYST[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x18D0. */
    uint8_t ADCS_RESERVED_18D0[32];

    /* offset  : 0x18F0.    ADC 通道事件标志位清除寄存器. */
    ADC_CEFCLR_T ADC_CEFCLR[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x1900. */
    uint8_t ADCS_RESERVED_1900[32];

    /* offset  : 0x1920.    ADC 结果事件标志位清除寄存器. */
    ADC_REFCLR_T ADC_REFCLR[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x1930. */
    uint8_t ADCS_RESERVED_1930[32];

    /* offset  : 0x1950.    ADC 源事件标志位清除寄存器. */
    ADC_SEFCLR_T ADC_SEFCLR[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x1960. */
    uint8_t ADCS_RESERVED_1960[32];

    /* offset  : 0x1980.    ADC 转换结果累加平均寄存器. */
    ADC_AVERSULT_T ADC_AVERSULT[ADCS_LLD_MODULE_NUM][ADCS_LLD_RESULT_REG_NUM];

    /* offset  : 0x1A80. */
    uint8_t ADCS_RESERVED_1A80[512];

    /* offset  : 0x1C80.    ADC 全局平均结果寄存器. */
    ADC_GAVERSULT_T ADC_GAVERSULT[ADCS_LLD_MODULE_NUM];

    /* offset  : 0x1C90. */
    uint8_t ADCS_RESERVED_1C90[32];

    /* offset  : 0x1CB0.    ADC 通道信息配置. */
    ADC_CHINF_T ADC_CHINF[ADCS_LLD_MODULE_NUM][ADCS_LLD_CHANNEL_NUM];

    /* offset  : 0x1DB0. */
    uint8_t ADCS_RESERVED_1DB0[4];

    /* offset  : 0x1DB4.    ADC 外扩通道接口选择控制寄存器. */
    ADC_EMUXITFCSEL_T ADC_EMUXITFCSEL;

    /* offset  : 0x1DB8.    ADCS 模块 ID 信息寄存器. */
    ADCS_ID_T ADCS_ID;

} Adcs_RegisterMap_t;

#define ADCS_ADDR ((uint32_t)0xF0003000U)
#define ADCS_PTR  ((Adcs_RegisterMap_t *)ADCS_ADDR)
#define ADCS_RM   (*(Adcs_RegisterMap_t *)ADCS_ADDR)

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
