/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_msc.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-22
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
 *  |2023-12-22  |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_REG_MSC_H_
#define _KF32DA13K_REG_MSC_H_

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
            __IO uint32_t DISR :1; /*!< [0:0] 模块禁用请求。0-使能当前模块。1-禁用当前模块。  */
            __I uint32_t DISS :1; /*!< [1:1] 模块禁用状态位。0-当前模块未被禁用。1=当前模块已被禁用。  */
            __IO uint32_t EDIS :1; /*!< [2:2] 休眠模式请求。0-禁用休眠模式1-启用休眠模式。  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DBGCTL :4; /*!< [3:0] OCDS挂起控制位。 */
            __O uint32_t DBGP :1; /*!< [4:4] DBGCTL写保护。0-DBGCTL不可写入，读为0。1-DBGCTL可被写入。  */
            __I uint32_t DBGSTA :1; /*!< [5:5] 模块挂起状态。0-当前模块未被挂起。1-当前模块被挂起。  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST    :1; /*!< [0:0] 模块复位请求，与RST1_RST一起使用。 */
            __I uint32_t  RSTSTA :1; /*!< [1:1] 复位状态。0-模块没有被复位。1-模块已经被复位。  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST :1; /*!< [0:0] 模块复位请求，与RST0_RST一起使用。 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CLR :1; /*!< [0:0] RSTSTA复位状态清除，该位自动清零。 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_RSTCLR_T;

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
} MSC_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留位  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] 模块版本01H  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] 模块类型07H  */
            __I uint32_t MODNUM  :16; /*!< [31:16] 模块ID0015H  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FDVI      :10; /*!< [9:0] 分频值:0-1023；向RESULT位域重加载或增加值  */
            __I uint32_t  RESERVED0  :5;  /*!< [10:14] 预留位  */
            __IO uint32_t DVIMOD    :1;  /*!< [15:15] 分频模式选择0-整数模式1-分数模式  */
            __I uint32_t  RESULT    :10; /*!< [25:16] 分频结果位  */
            __I uint32_t  RESERVED1 :4;  /*!< [29:26] 预留位  */
            __IO uint32_t ENHW :1; /*!< [30:30] 硬件时钟控制使能位0-无操作1-运行控制操作ECNE输入和DISCLK位  */
            __IO uint32_t DISCLK :1; /*!< [31:31] 禁用时钟fMSC0-无操作1-硬件控制禁用时钟fMSC  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_FD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t UFT       :1;  /*!< [0:0]上行通道帧类型 */
            __IO uint32_t UDVI      :3;  /*!< [3:1] 上行通道接收波特率 */
            __IO uint32_t PCTR      :1;  /*!< [4:4] 奇偶校验选择0-偶校验1-奇校验 */
            __IO uint32_t RDIDLY    :1;  /*!< [5:5] 接收中断延迟控制 */
            __I uint32_t  RESERVED0  :10; /*!< [15:6] 预留位  */
            __IO uint32_t UCNT      :5;  /*!< [20:16] 上行通道计数器 */
            __I uint32_t  RESERVED1 :11; /*!< [31:21] 预留位  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_USTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TMOD     :1; /*!< [0:0] 发送模式；此位选择下行通道的传输模式 */
            __I uint32_t  CP       :1; /*!< [1:1] 命令帧指示 */
            __I uint32_t  DP       :1; /*!< [2:2]  数据帧指示 */
            __IO uint32_t NDBL     :5; /*!< [7:3] SRL中需要被发送的数据位数 */
            __IO uint32_t NDBH     :5; /*!< [12:8] SRH中需要被发送的数据位数 */
            __IO uint32_t ENSELL   :1; /*!< [13:13] SRL数据选择位 */
            __IO uint32_t ENSELH   :1; /*!< [14:14] SRH数据选择位 */
            __I uint32_t  DOWNEN   :1; /*!< [15:15]  禁用下行通道  */
            __IO uint32_t NBC      :6; /*!< [21:16]  命令帧传输bit数 */
            __I uint32_t  RESERVED0 :2; /*!< [23:22] 预留位  */
            __IO uint32_t PDD      :5; /*!< [28:24] 定义数据帧中无效位长度 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_DCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  PFCNT     :4; /*!< [3:0] 无效时间帧计数器  */
            __I uint32_t  RESERVED0  :4; /*!< [7:4] 预留位  */
            __IO uint32_t NPTF      :4; /*!< [11:8] 无效时间帧(PTF)个数  */
            __I uint32_t  RESERVED1 :4; /*!< [15:12] 预留位  */
            __I uint32_t  DCNT      :8; /*!< [23:16] 下行通道计数器  */
            __I uint32_t  DFA       :1; /*!< [24:24] 数据帧有效 */
            __I uint32_t  CFA       :1; /*!< [25:25] 命令帧有效 */
            __I uint32_t  RESERVED2 :6; /*!< [31:26] 预留位  */

        } bits;
        __IO uint32_t reg;
    };
} MSC_DSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DDL :16; /*!< [15:0] 发送数据帧时移位寄存器SRL下行数据  */
            __IO uint32_t DDH :16; /*!< [31:16] 发送数据帧时移位寄存器SRH下行数据  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_DDAT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DCL :16; /*!< [15:0] 发送数据帧时移位寄存器SRL下行数据  */
            __IO uint32_t DCH :16; /*!< [31:16] 发送数据帧时移位寄存器SRH下行数据  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_CMD_T;

typedef volatile struct
{
    __IO uint32_t reg; /*!< [31:0] 决定SRL数据来源 */
} MSC_DDATSELL_T;

typedef volatile struct
{
    __IO uint32_t reg; /*!< [31:0] 决定SRL数据来源 */
} MSC_DDATSELH_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ENL0  :1; /*!< [0:0] 紧急停止使能位 */
            __IO uint32_t ENL1  :1; /*!< [1:1] 紧急停止使能位 */
            __IO uint32_t ENL2  :1; /*!< [2:2] 紧急停止使能位 */
            __IO uint32_t ENL3  :1; /*!< [3:3] 紧急停止使能位 */
            __IO uint32_t ENL4  :1; /*!< [4:4] 紧急停止使能位 */
            __IO uint32_t ENL5  :1; /*!< [5:5] 紧急停止使能位 */
            __IO uint32_t ENL6  :1; /*!< [6:6] 紧急停止使能位 */
            __IO uint32_t ENL7  :1; /*!< [7:7] 紧急停止使能位 */
            __IO uint32_t ENL8  :1; /*!< [8:8] 紧急停止使能位 */
            __IO uint32_t ENL9  :1; /*!< [9:9] 紧急停止使能位 */
            __IO uint32_t ENL10 :1; /*!< [10:10] 紧急停止使能位 */
            __IO uint32_t ENL11 :1; /*!< [11:11] 紧急停止使能位 */
            __IO uint32_t ENL12 :1; /*!< [12:12] 紧急停止使能位 */
            __IO uint32_t ENL13 :1; /*!< [13:13] 紧急停止使能位 */
            __IO uint32_t ENL14 :1; /*!< [14:14] 紧急停止使能位 */
            __IO uint32_t ENL15 :1; /*!< [15:15] 紧急停止使能位 */
            __IO uint32_t ENH0  :1; /*!< [16:16] 紧急停止使能位 */
            __IO uint32_t ENH1  :1; /*!< [17:17] 紧急停止使能位 */
            __IO uint32_t ENH2  :1; /*!< [18:18] 紧急停止使能位 */
            __IO uint32_t ENH3  :1; /*!< [19:19] 紧急停止使能位 */
            __IO uint32_t ENH4  :1; /*!< [20:20] 紧急停止使能位 */
            __IO uint32_t ENH5  :1; /*!< [21:21] 紧急停止使能位 */
            __IO uint32_t ENH6  :1; /*!< [22:22] 紧急停止使能位 */
            __IO uint32_t ENH7  :1; /*!< [23:23] 紧急停止使能位 */
            __IO uint32_t ENH8  :1; /*!< [24:24] 紧急停止使能位 */
            __IO uint32_t ENH9  :1; /*!< [25:25] 紧急停止使能位 */
            __IO uint32_t ENH10 :1; /*!< [26:26] 紧急停止使能位 */
            __IO uint32_t ENH11 :1; /*!< [27:27] 紧急停止使能位 */
            __IO uint32_t ENH12 :1; /*!< [28:28] 紧急停止使能位 */
            __IO uint32_t ENH13 :1; /*!< [29:29] 紧急停止使能位 */
            __IO uint32_t ENH14 :1; /*!< [30:30] 紧急停止使能位 */
            __IO uint32_t ENH15 :1; /*!< [31:31] 紧急停止使能位 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_ES_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t REVDAT    :8; /*!< [7:0] 上行通道接收数据  */
            __I uint32_t RESERVED0  :8; /*!< [15:8] 预留   */
            __I uint32_t V         :1; /*!< [16:16] 当接收数据被写入UDx时，硬件将该位置1 */
            __I uint32_t P         :1; /*!< [17:17] 预留   */
            __O uint32_t VC        :1; /*!< [18:18] 用于清零V0-无操作1-清零V  */
            __I uint32_t LADR      :2; /*!< [20:19]  低地址位；当上行接收帧为16bit时 */
            __I uint32_t IPF       :1; /*!< [21:21] 该位为模块计算接收数据奇偶校验结果位  */
            __I uint32_t PERR      :1; /*!< [22:22] 奇偶校验错误0-无奇偶校验错误1-奇偶校验错误  */
            __I uint32_t RESERVED1 :9; /*!< [31:23] 预留   */
        } bits;
        __IO uint32_t reg;
    };
} MSC_UDAT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EDIP      :2;  /*!< [1:0] 数据帧中断选择 */
            __I uint32_t  RESERVED0  :2;  /*!< [3:2] 预留  */
            __IO uint32_t ECIP      :2;  /*!< [5:4] 命令帧中断选择 */
            __I uint32_t  RESERVED1 :2;  /*!< [7:6] 预留  */
            __IO uint32_t TFIP      :2;  /*!< [9:8] 时间帧中断选择 */
            __I uint32_t  RESERVED2 :2;  /*!< [11:10] 预留  */
            __IO uint32_t RDIP      :2;  /*!< [13:12] 接收数据帧中断选择 */
            __I uint32_t  RESERVED3 :18; /*!< [31:14] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_ISEL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t DEDIF    :1;  /*!< [0:0] 描述数据帧中断标志  */
            __I uint32_t DECIF    :1;  /*!< [1:1] 命令帧中断标志 */
            __I uint32_t DTFIF    :1;  /*!< [2:2] 时间帧中断标志 */
            __I uint32_t URDIF    :1;  /*!< [3:3] 接收数据中断标志 */
            __I uint32_t USTIF    :1;  /*!< [4:4] 上行通道超时中断标志  */
            __I uint32_t OVIF     :1;  /*!< [5:5] 异步FIFO上溢中断标志  */
            __I uint32_t UNIF     :1;  /*!< [6:6] 异步FIFO下溢中断标志  */
            __I uint32_t RESERVED0 :25; /*!< [31:7] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EDIE     :2;  /*!< [1:0] 数据帧中断使能  */
            __IO uint32_t ECIE     :1;  /*!< [2:2] 命令帧中断使能  */
            __IO uint32_t TFIE     :1;  /*!< [3:3] 被动时间帧中断使能  */
            __IO uint32_t RDIE     :2;  /*!< [5:4] 数据帧接收中断使能  */
            __IO uint32_t USTIE    :1;  /*!< [6:6] 上行通道超时中断使能  */
            __IO uint32_t OIE      :1;  /*!< [7:7] 上溢中断使能  */
            __IO uint32_t UIE      :1;  /*!< [8:8] 下溢中断使能  */
            __I uint32_t  RESERVED0 :25; /*!< [31:9] 预留 */

        } bits;
        __IO uint32_t reg;
    };
} MSC_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t DEDIC    :1;  /*!< [0:0] 清零DEDIF  */
            __O uint32_t DECIC    :1;  /*!< [1:1] 清零DECIF  */
            __O uint32_t DTFIC    :1;  /*!< [2:2] 清零DTFIF  */
            __O uint32_t URDIC    :1;  /*!< [3:3] 清零URDIF  */
            __O uint32_t USTIC    :1;  /*!< [4:4] 清零USTIF  */
            __O uint32_t OFIC     :2;  /*!< [6:5] 上溢标志OVIF修改 */
            __O uint32_t UFIC     :2;  /*!< [8:7] 下溢标志UNIF修改 */
            __I uint32_t RESERVED0 :25; /*!< [31:9] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_IC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CDP      :1; /*!< [4:4] 清零DP  */
            __O uint32_t CCP      :1; /*!< [5:5] 清零CP  */
            __O uint32_t CDOWNEN  :1; /*!< [6:6] 清零DOWNEN  */
            __O uint32_t SDEDI    :1; /*!< [16:16] 置位DEDIF  */
            __O uint32_t SDCDI    :1; /*!< [17:17] 置位DECIF  */
            __O uint32_t SDTFI    :1; /*!< [18:18] 置位DTFIF  */
            __O uint32_t SURDI    :1; /*!< [19:19] 置位URDIF  */
            __O uint32_t SDP      :1; /*!< [20:20] 置位DP  */
            __O uint32_t SCP      :1; /*!< [21:21] 置位CP  */
            __O uint32_t SDOWNEN  :1; /*!< [22:22] 置位DOWNEN  */
            __I uint32_t RESERVED0 :9; /*!< [31:23] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_SIF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FCLPOL    :1;  /*!< [0:0]  FCL输出极性选择 */
            __IO uint32_t SOPOL     :1;  /*!< [1:1] SO输出极性选择 */
            __IO uint32_t ENPOL     :1;  /*!< [2:2] 片选输出极性选择 */
            __IO uint32_t SDIPOL    :1;  /*!< [3:3] SDI极性选择 */
            __I uint32_t  RESERVED0  :4;  /*!< [7:4] 预留 */
            __IO uint32_t CLKCTRL   :1;  /*!< [8:8] 该位决定输出时钟FCL是否被激活 */
            __IO uint32_t ENLSEL    :2;  /*!< [10:9] ENL片选使能 */
            __IO uint32_t ENHSEL    :2;  /*!< [12:11] ENH片选使能 */
            __IO uint32_t ENCSEL    :2;  /*!< [14:13] ENC片选使能 */
            __I uint32_t  RESERVED1 :1;  /*!< [15:15] 预留 */
            __IO uint32_t SDISEL    :3;  /*!< [18:16] 串行数据输入选择 */
            __I uint32_t  RESERVED2 :13; /*!< [31:19] 预留 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_OCLT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t NDBHE     :1;  /*!< [0:0] 数据帧NDBH的高位扩展  */
            __IO uint32_t NDBLE     :1;  /*!< [1:1] 数据帧NDBL的高位扩展  */
            __I uint32_t  RESERVED0  :12; /*!< [13:2] 预留 */
            __IO uint32_t EXEN      :1;  /*!< [14:14] 数据扩展模式使能  */
            __IO uint32_t CCF       :1;  /*!< [15:15] 命令-命令标志位 */
            __IO uint32_t INJENP0   :1;  /*!< [16:16] 外部输入引脚0注入使能 */
            __IO uint32_t INJPOSP0  :6;  /*!< [22:17] 外部引脚0的信号注入的位置选择 */
            __I uint32_t  RESERVED1 :1;  /*!< [23:23] 预留 */
            __IO uint32_t INJENP1   :1;  /*!< [24:24] 外部输入引脚1注入使能 */
            __IO uint32_t INJPOSP1  :6;  /*!< [30:25] 外部引脚0的信号注入的位置选择 */
            __IO uint32_t CDCM      :1;  /*!< [31:31] 在数据重复模式下支持命令帧-数据帧-命令帧 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_DCTLE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t USTOPRE :4; /*!< [3:0] 上行通道超时2n预分频器。*/
            __IO uint32_t USTOVAL :4; /*!< [7:4] 上行通道超时值。*/
            __O uint32_t  USTS    :1; /*!< [11:11] 上行通道超时标志置位 */
            __IO uint32_t UTASR   :1; /*!< [13:13] 上行通道超时替代服务请求。*/
            __IO uint32_t USTOIP  :2; /*!< [15:14] 上行通道超时中断服务请求选择 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_UCTLE_T;

typedef volatile struct
{
    __IO uint32_t reg; /*!< [31:1] 决定 SRL 数据来源 */
} MSC_DDATSELLE_T;

typedef volatile struct
{
    __IO uint32_t reg; /*!< [31:1] 决定 SRH 数据来源 */
} MSC_DDATSELHE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ENL; /*!< [15:1]   紧急停止使能位*/
            __IO uint32_t ENH; /*!< [31:16]  紧急停止使能位*/
        } bits;
        __IO uint32_t reg;
    };
} MSC_ESE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PPDE      :2;  /*!< [1:0] 数据扩展帧的无效位长度  */
            __IO uint32_t PPCE      :6;  /*!< [7:2] 命令扩展帧的无效位长度  */
            __IO uint32_t NDVI      :4;  /*!< [11:8] 下行通道N分频器 */
            __IO uint32_t PPCEM     :1;  /*!< [12:12] PPCE的高位扩展位 */
            __I uint32_t  RESERVED0  :3;  /*!< [15:13] 预留 */
            __IO uint32_t FASTMOD   :1;  /*!< [16:16] 快速模式 */
            __I uint32_t  RESERVED1 :11; /*!< [27:17] 预留 */
            __IO uint32_t CXMOD     :1;  /*!< [28:28] 命令扩展模式 */
            __I uint32_t  RESERVED2 :2;  /*!< [30:29] 预留 */
            __O uint32_t  UL1       :1; /*!< [31:31] 解锁CXMOD和FASTMOD来获取一次写权限，读该位返回0 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_DSTE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t DDLM :16; /*!< [15:0] 此位域表示用于SRL移位寄存器的下行数据镜像 */
            __O uint32_t DDHM :16; /*!< [31:16] 此位域表示用于SRH移位寄存器的下行数据镜像 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_DDATM_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DDLE :16; /*!< [15:0] 扩展模式下发送数据帧时移位寄存器SRL下行数据  */
            __IO uint32_t DDHE :16; /*!< [31:16] 扩展模式下发送数据帧时移位寄存器SRH下行数据  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_DDATE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t DCLM :16; /*!< [15:0] 发送命令帧时移位寄存器SRL下行数据  */
            __O uint32_t DCHM :16; /*!< [31:16] 发送命令帧时移位寄存器SRH下行数据  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_DCMDM_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DCLE :16; /*!< [15:0] 命令扩展模式发送命令帧时移位寄存器SRL下行数据  */
            __IO uint32_t DCHE :16; /*!< [15:0] 命令扩展模式发送命令帧时移位寄存器SRH下行数据  */
        } bits;
        __IO uint32_t reg;
    };
} MSC_DCMDE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LOW  :4; /*!< [3:0] 定以挡位，移位时钟fA低电平持续时间0-1....F-16  */
            __IO uint32_t HIGH :4; /*!< [7:4] 定义挡位，移位时钟fA周期高电平持续时间。0-1....F-16  */
            __IO uint32_t OIP  :2; /*!< [9:8]上溢中断节点指针00-选择服务请求输出SR */
            __IO uint32_t OASR :1; /*!< [10:10] 上溢中断替代服务请求 */
            __IO uint32_t ABNDVI :3; /*!< [18:16] ABRA的N分频器；定义分频系数从1到8  */
            __IO uint32_t UIP    :2; /*!< [20:19] 下溢中断节点指针 */
            __IO uint32_t UASR   :1; /*!< [21:21] 下溢中断替代服务请求 */
            __IO uint32_t CLKSEL :3; /*!< [29:27] 时钟选择，选择ABRA模块的时钟源 */
            __IO uint32_t ABEN   :1; /*!< [31:31] 异步模块使能 */
        } bits;
        __IO uint32_t reg;
    };
} MSC_ABC_T;

typedef volatile struct
{
    /* offset  : 0x0000.  */
    MSC_CLKC_T MSC_CLKC;

    /* offset  : 0x0004.  */
    MSC_DBG_T MSC_DBG;

    /* offset  : 0x0008.  */
    MSC_RST0_T MSC_RST0;

    /* offset  : 0x000C.  */
    MSC_RST1_T MSC_RST1;

    /* offset  : 0x0010.  */
    MSC_RSTCLR_T MSC_RSTCLR;

    /* offset  : 0x0014.  */
    MSC_ACES0_T MSC_ACES0;

    /* offset  : 0x0018.  */
    MSC_ACES1_T MSC_ACES1;

    /* offset  : 0x001C.  */
    MSC_INFO_T MSC_INFO;

    /* offset  : 0x0020.  */
    MSC_FD_T MSC_FD;

    /* offset  : 0x0024.  */
    MSC_USTA_T MSC_USTA;

    /* offset  : 0x0028.  */
    MSC_DCTL_T MSC_DCTL;

    /* offset  : 0x002C.  */
    MSC_DSTA_T MSC_DSTA;

    /* offset  : 0x0030.  */
    MSC_DDAT_T MSC_DDAT;

    /* offset  : 0x0034.  */
    MSC_CMD_T MSC_CMD;

    /* offset  : 0x0038.  */
    MSC_DDATSELL_T MSC_DDATSELL;

    /* offset  : 0x003C.  */
    MSC_DDATSELH_T MSC_DDATSELH;

    /* offset  : 0x0040.  */
    MSC_ES_T MSC_ES;

    /* offset  : 0x0044.  */
    MSC_UDAT_T MSC_UDAT[4];

    /* offset  : 0x0054.  */
    MSC_ISEL_T MSC_ISEL;

    /* offset  : 0x0058.  */
    MSC_IF_T MSC_IF;

    /* offset  : 0x005C.  */
    MSC_IE_T MSC_IE;

    /* offset  : 0x0060.  */
    MSC_IC_T MSC_IC;

    /* offset  : 0x0064.  */
    MSC_SIF_T MSC_SIF;

    /* offset  : 0x0068.  */
    MSC_OCLT_T MSC_OCLT;

    /* offset  : 0x006C.  */
    MSC_DCTLE_T MSC_DCTLE;

    /* offset  : 0x0070.  */
    MSC_UCTLE_T MSC_UCTLE;

    /* offset  : 0x0074.  */
    MSC_DDATSELLE_T MSC_DDATSELLE;

    /* offset  : 0x0078.  */
    MSC_DDATSELHE_T MSC_DDATSELHE;

    /* offset  : 0x007C.  */
    MSC_ESE_T MSC_ESE;

    /* offset  : 0x0080.  */
    MSC_DSTE_T MSC_DSTE;

    /* offset  : 0x0084.  */
    MSC_DDATM_T MSC_DDATM;

    /* offset  : 0x0088.  */
    MSC_DDATE_T MSC_DDATE;

    /* offset  : 0x008C.  */
    MSC_DCMDM_T MSC_DCMDM;

    /* offset  : 0x0090.  */
    MSC_DCMDE_T MSC_DCMDE;

    /* offset  : 0x0094.  */
    MSC_ABC_T MSC_ABC;
} Msc_RegisterMap_t;

#define MSC_ADDR ((uint32_t)0xF0007000)
#define MSC_PTR  ((Msc_RegisterMap_t *)MSC_ADDR)
#define MSC_RM   (*(Msc_RegisterMap_t *)MSC_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
