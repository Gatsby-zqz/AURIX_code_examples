/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_psi5s.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-28
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
#ifndef _KF32DA13K_REG_PSI5S_H_
#define _KF32DA13K_REG_PSI5S_H_

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
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁止请求位  */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁止状态  */
            __IO uint32_t RESERVED0  :1;  /*!< [2:2] 预留读为0  */
            __IO uint32_t EDIS      :1;  /*!< [3:3] 休眠模式使能控制位  */
            __IO uint32_t RESERVED1 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] PSI5S模块版本号  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] PSI5S模块类型  */
            __I uint32_t MODNUM  :16; /*!< [31:16] PSI5S模块编号  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STEP      :10; /*!< [9:0] 分频值  */
            __IO uint32_t RESERVED0  :4;  /*!< [13:10] 预留读为0  */
            __IO uint32_t DM        :2;  /*!< [15:14] 分频模式  */
            __I uint32_t  RESULT    :10; /*!< [25:16] 结果值，用于表示增加的值  */
            __IO uint32_t RESERVED1 :6;  /*!< [31:26] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_FDR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STEP      :10; /*!< [9:0] 分频值  */
            __IO uint32_t RESERVED0  :4;  /*!< [13:10] 预留读为0  */
            __IO uint32_t DM        :2;  /*!< [15:14] 分频模式  */
            __I uint32_t  RESULT    :10; /*!< [25:16] 结果值，用于表示增加的值  */
            __IO uint32_t ECS       :3;  /*!< [28:26] 外部时间戳清零源选择  */
            __IO uint32_t ECEA      :1;  /*!< [29:29] 外部时间戳A清零使能 */
            __IO uint32_t ECEB      :1;  /*!< [30:30] 外部时间戳B清零使能 */
            __IO uint32_t RESERVED1 :1;  /*!< [31:31] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_FDRT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  CTS  :24; /*!< [23:0] 模块当前时间戳  */
            __IO uint32_t ETB  :3;  /*!< [26:24] 外部时基选择  */
            __IO uint32_t TBS  :1;  /*!< [27:27] CTS时基选择  */
            __IO uint32_t TBEA :1;  /*!< [28:28] 使能时基TSCNTA，启动或停止TSCNA寄存器的CTS计数  */
            __IO uint32_t TBEB :1;  /*!< [29:29] 使能时基TSCNTB，启动或停止TSCNB寄存器的CTS计数  */
            __O uint32_t  CLRA :1;  /*!< [30:30] 清零时间戳计数A  */
            __O uint32_t  CLRB :1;  /*!< [31:31] 清零时间戳计数B  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_TSCNT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CRCI     :1; /*!< [0:0] 如果该位置1，CRCI被选择  */
            __IO uint32_t XCRCI    :1; /*!< [1:1] 如果该位置1，XCRCI被选择  */
            __IO uint32_t TEI      :1; /*!< [2:2] 如果该位置1，TEI被选择  */
            __IO uint32_t PE       :1; /*!< [3:3] 如果该位置1，PE被选择  */
            __IO uint32_t FE       :1; /*!< [4:4] 如果该位置1，FE被选择  */
            __IO uint32_t OE       :1; /*!< [5:5] 如果该位置1，OEI被选择  */
            __IO uint32_t RBI      :1; /*!< [6:6] 如果该位置1，RBI被选择  */
            __IO uint32_t HDI      :1; /*!< [7:7] 如果该位置1，HDI被选择  */
            __IO uint32_t ETC0     :1; /*!< [8:8] 使能通道触发计数。 */
            __IO uint32_t ETC1     :1; /*!< [9:9] 使能通道触发计数。 */
            __IO uint32_t ETC2     :1; /*!< [10:10] 使能通道触发计数。 */
            __IO uint32_t ETC3     :1; /*!< [11:11] 使能通道触发计数。 */
            __IO uint32_t ETC4     :1; /*!< [12:12] 使能通道触发计数。 */
            __IO uint32_t ETC5     :1; /*!< [13:13] 使能通道触发计数。 */
            __IO uint32_t ETC6     :1; /*!< [14:14] 使能通道触发计数。 */
            __IO uint32_t ETC7     :1; /*!< [15:15] 使能通道触发计数。 */
            __IO uint32_t CEN0     :1; /*!< [16:16] 通道x使能  */
            __IO uint32_t CEN1     :1; /*!< [17:17] 通道x使能  */
            __IO uint32_t CEN2     :1; /*!< [18:18] 通道x使能  */
            __IO uint32_t CEN3     :1; /*!< [19:19] 通道x使能  */
            __IO uint32_t CEN4     :1; /*!< [20:20] 通道x使能  */
            __IO uint32_t CEN5     :1; /*!< [21:21] 通道x使能  */
            __IO uint32_t CEN6     :1; /*!< [22:22] 通道x使能  */
            __IO uint32_t CEN7     :1; /*!< [23:23] 通道x使能  */
            __IO uint32_t IDT      :4; /*!< [27:24] 两个组合帧的空闲时间定义  */
            __IO uint32_t RESERVED0 :2; /*!< [29:28] 预留读为0  */
            __IO uint32_t GEN      :1; /*!< [30:30] 使能位  */
            __IO uint32_t ASC      :1; /*!< [31:31] ASC模式选择  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_GCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t NF0      :3; /*!< [2:0] 通道x期望接收的帧数量  */
            __IO uint32_t NF1      :3; /*!< [5:3] 通道x期望接收的帧数量  */
            __IO uint32_t NF2      :3; /*!< [8:6] 通道x期望接收的帧数量  */
            __IO uint32_t NF3      :3; /*!< [11:9] 通道x期望接收的帧数量  */
            __IO uint32_t NF4      :3; /*!< [14:12] 通道x期望接收的帧数量  */
            __IO uint32_t NF5      :3; /*!< [17:15] 通道x期望接收的帧数量  */
            __IO uint32_t NF6      :3; /*!< [20:18] 通道x期望接收的帧数量  */
            __IO uint32_t NF7      :3; /*!< [23:21] 通道x期望接收的帧数量  */
            __IO uint32_t RESERVED0 :8; /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_NFC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t FC0    :3; /*!< [2:0] 通道x的帧计数器  */
            __I uint32_t FC1    :3; /*!< [5:3] 通道x的帧计数器  */
            __I uint32_t FC2    :3; /*!< [8:6] 通道x的帧计数器  */
            __I uint32_t FC3    :3; /*!< [11:9] 通道x的帧计数器  */
            __I uint32_t FC4    :3; /*!< [14:12] 通道x的帧计数器  */
            __I uint32_t FC5    :3; /*!< [17:15] 通道x的帧计数器  */
            __I uint32_t FC6    :3; /*!< [20:18] 通道x的帧计数器  */
            __I uint32_t FC7    :3; /*!< [23:21] 通道x的帧计数器  */
            __O uint32_t NFCLR0 :1; /*!< [24:24] 清除通道x的计数用于从TEI恢复期间。 */
            __O uint32_t NFCLR1 :1; /*!< [25:25] 清除通道x的计数用于从TEI恢复期间。 */
            __O uint32_t NFCLR2 :1; /*!< [26:26] 清除通道x的计数用于从TEI恢复期间。*/
            __O uint32_t NFCLR3 :1; /*!< [27:27] 清除通道x的计数用于从TEI恢复期间。 */
            __O uint32_t NFCLR4 :1; /*!< [28:28] 清除通道x的计数用于从TEI恢复期间。 */
            __O uint32_t NFCLR5 :1; /*!< [29:29] 清除通道x的计数用于从TEI恢复期间。 */
            __O uint32_t NFCLR6 :1; /*!< [30:30] 清除通道x的计数用于从TEI恢复期间。*/
            __O uint32_t NFCLR7 :1; /*!< [31:31] 清除通道x的计数用于从TEI恢复期间。  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_FCNT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ALTI     :2;  /*!< [1:0] 选择UART接收输入信号  */
            __IO uint32_t RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_IOCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CRC0      :1; /*!< [0:0] CRC或者奇偶校验选择  */
            __IO uint32_t CRC1      :1; /*!< [1:1] CRC或者奇偶校验选择  */
            __IO uint32_t CRC2      :1; /*!< [2:2] CRC或者奇偶校验选择  */
            __IO uint32_t CRC3      :1; /*!< [3:3] CRC或者奇偶校验选择  */
            __IO uint32_t CRC4      :1; /*!< [4:4] CRC或者奇偶校验选择  */
            __IO uint32_t CRC5      :1; /*!< [5:5] CRC或者奇偶校验选择  */
            __IO uint32_t TSEN      :1; /*!< [6:6] 时间戳使能  */
            __IO uint32_t TSP       :1; /*!< [7:7] 时间戳选择  */
            __IO uint32_t TSTS      :1; /*!< [8:8] 时间戳触发器选择  */
            __IO uint32_t FIDS      :1; /*!< [9:9] 帧ID选择  */
            __IO uint32_t WDMS      :1; /*!< [10:10] 看门狗定时器模式选择  */
            __IO uint32_t RESERVED0  :5; /*!< [15:11] 预留读为0  */
            __IO uint32_t UFC0      :2; /*!< [17:16] 节点y需要的UART帧数量  */
            __IO uint32_t UFC1      :2; /*!< [19:18] 节点y需要的UART帧数量  */
            __IO uint32_t UFC2      :2; /*!< [21:20] 节点y需要的UART帧数量  */
            __IO uint32_t UFC3      :2; /*!< [23:22] 节点y需要的UART帧数量  */
            __IO uint32_t UFC4      :2; /*!< [25:24] 节点y需要的UART帧数量  */
            __IO uint32_t UFC5      :2; /*!< [27:26] 节点y需要的UART帧数量  */
            __IO uint32_t RESERVED1 :4; /*!< [31:28] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_RCRA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PDL0     :5; /*!< [4:0] 负载数据长度 */
            __IO uint32_t PDL1     :5; /*!< [9:5] 负载数据长度*/
            __IO uint32_t PDL2     :5; /*!< [14:10] 负载数据长度*/
            __IO uint32_t PDL3     :5; /*!< [19:15] 负载数据长度*/
            __IO uint32_t PDL4     :5; /*!< [24:20] 负载数据长度*/
            __IO uint32_t PDL5     :5; /*!< [29:25] 负载数据长度*/
            __IO uint32_t RESERVED0 :2; /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_RCRB_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t WDL      :24; /*!< [23:0] 看门狗定时器上限值 */
            __IO uint32_t RESERVED0 :8;  /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_WDT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  TS       :24; /*!< [23:0] 通道x上次同步脉冲发送的时间戳  */
            __IO uint32_t RESERVED0 :8;  /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_TSCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t XCRC0 :1; /*!< [0:0] XCRC值  */
            __I uint32_t XCRC1 :1; /*!< [1:1] XCRC值  */
            __I uint32_t XCRC2 :1; /*!< [2:2] XCRC值  */
            __I uint32_t XCRC3 :1; /*!< [3:3] XCRC值  */
            __I uint32_t XCRC4 :1; /*!< [4:4] XCRC值  */
            __I uint32_t XCRC5 :1; /*!< [5:5] XCRC值  */
            __I uint32_t XCRCI :1; /*!< [6:6] XCRC校验标志组合帧的CRC校验失败，包括无法执行XCRC的情况(不可恢复帧)  */
            __I uint32_t CRC0 :1; /*!< [7:7] 最后一帧的CRC值当选择CRC奇偶校验时，CRC1和CRC2为0，CRC0为奇偶校验位  */
            __I uint32_t CRC1 :1; /*!< [8:8] 最后一帧的CRC值当选择CRC奇偶校验时，CRC1和CRC2为0，CRC0为奇偶校验位  */
            __I uint32_t CRC2 :1; /*!< [9:9] 最后一帧的CRC值当选择CRC奇偶校验时，CRC1和CRC2为0，CRC0为奇偶校验位  */
            __I uint32_t CRCI :1; /*!< [10:10] CRC错误标志  */
            __I uint32_t ERR0 :1; /*!< [11:11] 错误指示标志0  */
            __I uint32_t ERR1 :1; /*!< [12:12] 错误指示标志1  */
            __I uint32_t HDI  :1; /*!< [13:13] 错误指示标志  */
            __I uint32_t PE   :1; /*!< [14:14] ASC奇偶校验错误标志  */
            __I uint32_t FE   :1; /*!< [15:15] ASC帧错误标志  */
            __I uint32_t OE   :1; /*!< [16:16] ASC溢出错误标志  */
            __I uint32_t TEI  :1; /*!< [17:17] 定时器错误标志  */
            __I uint32_t RBI  :1; /*!< [18:18] 接收缓冲溢出标志  */
            __I uint32_t FID  :3; /*!< [21:19] 帧ID  */
            __I uint32_t CID  :3; /*!< [24:22] 通道ID  */
            __I uint32_t AFC  :3; /*!< [27:25] 实际UART帧计数用于软件或者debug时分析不可恢复帧  */
            __I uint32_t PFC  :4; /*!< [31:28] 组合帧计数 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_RDS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RD0  :1; /*!< [0:0] PSI5接收数据  */
            __I uint32_t RD1  :1; /*!< [1:1] PSI5接收数据  */
            __I uint32_t RD2  :1; /*!< [2:2] PSI5接收数据  */
            __I uint32_t RD3  :1; /*!< [3:3] PSI5接收数据  */
            __I uint32_t RD4  :1; /*!< [4:4] PSI5接收数据  */
            __I uint32_t RD5  :1; /*!< [5:5] PSI5接收数据  */
            __I uint32_t RD6  :1; /*!< [6:6] PSI5接收数据  */
            __I uint32_t RD7  :1; /*!< [7:7] PSI5接收数据  */
            __I uint32_t RD8  :1; /*!< [8:8] PSI5接收数据  */
            __I uint32_t RD9  :1; /*!< [9:9] PSI5接收数据  */
            __I uint32_t RD10 :1; /*!< [10:10] PSI5接收数据  */
            __I uint32_t RD11 :1; /*!< [11:11] PSI5接收数据  */
            __I uint32_t RD12 :1; /*!< [12:12] PSI5接收数据  */
            __I uint32_t RD13 :1; /*!< [13:13] PSI5接收数据  */
            __I uint32_t RD14 :1; /*!< [14:14] PSI5接收数据  */
            __I uint32_t RD15 :1; /*!< [15:15] PSI5接收数据  */
            __I uint32_t RD16 :1; /*!< [16:16] PSI5接收数据  */
            __I uint32_t RD17 :1; /*!< [17:17] PSI5接收数据  */
            __I uint32_t RD18 :1; /*!< [18:18] PSI5接收数据  */
            __I uint32_t RD19 :1; /*!< [19:19] PSI5接收数据  */
            __I uint32_t RD20 :1; /*!< [20:20] PSI5接收数据  */
            __I uint32_t RD21 :1; /*!< [21:21] PSI5接收数据  */
            __I uint32_t RD22 :1; /*!< [22:22] PSI5接收数据  */
            __I uint32_t RD23 :1; /*!< [23:23] PSI5接收数据  */
            __I uint32_t RD24 :1; /*!< [24:24] PSI5接收数据  */
            __I uint32_t RD25 :1; /*!< [25:25] PSI5接收数据  */
            __I uint32_t RD26 :1; /*!< [26:26] PSI5接收数据  */
            __I uint32_t RD27 :1; /*!< [27:27] PSI5接收数据  */
            __I uint32_t PFC  :4; /*!< [31:28] 组合帧计数  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_RDR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  TS       :24; /*!< [23:0] 通道x最后一次同步脉冲的时间戳值  */
            __IO uint32_t RESERVED0 :4;  /*!< [27:24] 预留读为0  */
            __I uint32_t  PFC      :4;  /*!< [31:28] 组合帧计数  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_TSM_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :2;  /*!< [1:0] 预留读为0  */
            __I uint32_t  TA       :30; /*!< [31:2] 目标地址高30位的下一个DMA传输的目标地址  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_TADR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :2;  /*!< [1:0] 预留读为0  */
            __IO uint32_t BA       :30; /*!< [31:2] 基地址高30位的下一个DMA传输的基地址 */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_BADR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TXCMD     :5; /*!< [4:0] TX命令在编码为"0"时，复制到ASCFIFO的值  */
            __IO uint32_t RESERVED0  :3; /*!< [7:5] 预留读为0  */
            __IO uint32_t ATXCMD    :5; /*!< [12:8] 复用TX命令在编码为"1"时，复制到ASCFIFO的值  */
            __IO uint32_t RESERVED1 :2; /*!< [14:13] 预留读为0  */
            __IO uint32_t TBS       :1; /*!< [15:15] 时基选择  */
            __IO uint32_t ETB       :3; /*!< [18:16] 外部时基选择  */
            __IO uint32_t PTE       :1; /*!< [19:19] 周期触发使能位 */
            __IO uint32_t ETS       :3; /*!< [22:20] 外部触发源选择 */
            __IO uint32_t ETE       :1; /*!< [23:23] 外部触发使能位 */
            __IO uint32_t RESERVED2 :8; /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_PGC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CTV :16; /*!< [15:0] 通道触发值CTV */
            __IO uint32_t CTC :16; /*!< [31:16] 通道触发计数值当GCTL寄存器的ETCx被清零时，CTC可写  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_CTV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PLL       :5; /*!< [4:0] SDRx的负载长度  */
            __IO uint32_t RESERVED0  :1; /*!< [5:5] 预留读为0  */
            __IO uint32_t EPS       :2; /*!< [7:6] 增强协议选择  */
            __IO uint32_t BSC       :1; /*!< [8:8] 位填充控制  */
            __IO uint32_t RESERVED1 :5; /*!< [13:9] 预留读为0  */
            __O uint32_t  FLUS      :1; /*!< [14:14] 重置SDRx该位置1将停止从SDRx寄存器中移出数据   */
            __IO uint32_t RESERVED2 :7; /*!< [21:15] 预留读为0  */
            __IO uint32_t CRC       :1; /*!< [22:22] CRC生成控制  */
            __IO uint32_t STA       :1; /*!< [23:23] 起始序列生成控制  */
            __IO uint32_t RESERVED3 :2; /*!< [25:24] 预留读为0  */
            __I uint32_t  TPF       :1; /*!< [26:26]    正在发送标志  */
            __IO uint32_t RESERVED4 :5; /*!< [31:27] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_SCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SD0      :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD1      :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD2      :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD3      :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD4      :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD5      :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD6      :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD7      :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD8      :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD9      :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD10     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD11     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD12     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD13     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD14     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD15     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD16     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD17     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD18     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD19     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD20     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD21     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD22     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t SD23     :1; /*!< [0:0] 发送数据位y每次一个bit被移出  。*/
            __IO uint32_t RESERVED0 :8; /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_SDR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SD0      :1;  /*!< [0:0] 发送数据  */
            __IO uint32_t SD1      :1;  /*!< [1:1] 发送数据  */
            __IO uint32_t SD2      :1;  /*!< [2:2] 发送数据  */
            __IO uint32_t SD3      :1;  /*!< [3:3] 发送数据  */
            __IO uint32_t SD4      :1;  /*!< [4:4] 发送数据  */
            __IO uint32_t SD5      :1;  /*!< [5:5] 发送数据  */
            __IO uint32_t SD6      :1;  /*!< [6:6] 发送数据  */
            __IO uint32_t SD7      :1;  /*!< [7:7] 发送数据  */
            __IO uint32_t TSI      :1;  /*!< [8:8] 触发脉冲指示  */
            __IO uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_CDW_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M   :3; /*!< [2:0] 模式选择  */
            __IO uint32_t STP :1; /*!< [3:3] 停止位数量选择  */
            __IO uint32_t REN :1; /*!< [4:4] 同步模式接收器使能  */
            __IO uint32_t PEN :1; /*!< [5:5] ASC奇偶校验使能  */
            __IO uint32_t FEN :1; /*!< [6:6] ASC帧校验使能(仅异步模式)  */
            __IO uint32_t OEN :1; /*!< [7:7] ASC溢出校验使能  */
            __I uint32_t  PE  :1; /*!< [8:8] ASC奇偶校验错误标志，必须软件复位  */
            __I uint32_t  FE  :1; /*!< [9:9] ASC帧错误标志，必须软件复位  */
            __I uint32_t  OE  :1; /*!< [10:10] ASC溢出错误标志，必须软件复位  */
            __IO uint32_t FDE :1; /*!< [11:11] 分数分频器使能在同步模式下FDE无效，假定为0  */
            __IO uint32_t ODD :1; /*!< [12:12] 奇偶校验配置  */
            __IO uint32_t BRS :1; /*!< [13:13] 波特率选择当FDE=1时，BRS无效(分数分频使能)FDE在同步模式下无效，默认为0 */
            __IO uint32_t LB        :1; /*!< [14:14] 回环模式使能  */
            __IO uint32_t R         :1; /*!< [15:15] 波特率发生器运行控制  */
            __IO uint32_t MTX       :3; /*!< [18:16] TX模式选择  */
            __IO uint32_t RESERVED0  :9; /*!< [27:19] 预留读为0  */
            __IO uint32_t ODDTX     :1; /*!< [28:28] TX奇偶校验配置  */
            __IO uint32_t RESERVED1 :3; /*!< [31:29] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_UCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BRVALUE :13; /*!< [12:0] 波特率定时/重载寄存器值UCTL寄存的R位为0时写BG寄存器。  */
            __IO uint32_t RESERVED0 :19; /*!< [31:13] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_BG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FDVALUE  :11; /*!< [10:0] 分数分频器寄存器值 */
            __IO uint32_t RESERVED0 :21; /*!< [31:11] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_FDV_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t STEP      :11; /*!< [10:0] 步值用于内部累加器的重载或额外的值  */
            __IO uint32_t RESERVED0  :3;  /*!< [13:11] 预留读为0  */
            __IO uint32_t DM        :2;  /*!< [15:14] 分频模式  */
            __IO uint32_t RESERVED1 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_FDO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TDVALUE  :9;  /*!< [8:0] 发送数据寄存器  */
            __IO uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_TBUF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RDVALUE  :9;  /*!< [8:0] 接收数据寄存器 */
            __IO uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_RBUF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0  :4;  /*!< [3:0] 预留读为0  */
            __O uint32_t  CLRREN    :1;  /*!< [4:4] 接收使能位清0  */
            __O uint32_t  SETREN    :1;  /*!< [5:5] 接收使能位置1  */
            __IO uint32_t RESERVED1 :2;  /*!< [7:6] 预留读为0  */
            __O uint32_t  CLRPE     :1;  /*!< [8:8] 奇偶校验错误标志清0  */
            __O uint32_t  CLRFE     :1;  /*!< [9:9] 帧错误标志清0  */
            __O uint32_t  CLROE     :1;  /*!< [10:10] 溢出错误标志清0  */
            __O uint32_t  SETPE     :1;  /*!< [11:11] 奇偶校验错误标志置1  */
            __O uint32_t  SETFE     :1;  /*!< [12:12] 帧错误标志置1  */
            __O uint32_t  SETOE     :1;  /*!< [13:13] 溢出错误标志置1  */
            __IO uint32_t RESERVED2 :18; /*!< [31:14] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_WHBCON_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RSI  :1; /*!< [0:0] 成功接收标志成功 */
            __I uint32_t RDI  :1; /*!< [1:1] 接收数据标志 */
            __I uint32_t RBI  :1; /*!< [2:2] 接收缓冲器溢出标志 */
            __I uint32_t TEI  :1; /*!< [3:3]   定时错误标志看门狗溢出 */
            __I uint32_t CHCI :1; /*!< [4:4] 通道完成中断标志 */
            __I uint32_t CRCI :1; /*!< [5:5] CRC错误标志CRC校验失败  */
            __I uint32_t TPI  :1; /*!< [6:6] 传输完成中断标志  */
            __I uint32_t TPOI :1; /*!< [7:7] 传输准备溢出中断标志 */
            __I uint32_t HDI :1; /*!< [8:8] 组合帧头错误信号标志当组合帧的Err0和Err1位置1时，该位置1  */
            __IO uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_CIF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  RSI      :1;  /*!< [0:0] RSI位置1  */
            __O uint32_t  RDI      :1;  /*!< [1:1] RDI位置1  */
            __O uint32_t  RBI      :1;  /*!< [2:2] RBI位置1  */
            __O uint32_t  TEI      :1;  /*!< [3:3] TEI位置1  */
            __O uint32_t  CHCI     :1;  /*!< [4:4] CHCI位置1  */
            __O uint32_t  CRCI     :1;  /*!< [5:5] CRCI位置1  */
            __O uint32_t  TPI      :1;  /*!< [6:6] TPI位置1  */
            __O uint32_t  TPOI     :1;  /*!< [7:7] TPOI位置1  */
            __O uint32_t  HDI      :1;  /*!< [8:8] HDI位置1  */
            __IO uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_CIS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  RSI      :1;  /*!< [0:0] RSI位清0  */
            __O uint32_t  RDI      :1;  /*!< [1:1] RDI位清0  */
            __O uint32_t  RBI      :1;  /*!< [2:2] RBI位清0  */
            __O uint32_t  TEI      :1;  /*!< [3:3] TEI位清0  */
            __O uint32_t  CHCI     :1;  /*!< [4:4] CHCI位清0  */
            __O uint32_t  CRCI     :1;  /*!< [5:5] CRCI位清0  */
            __O uint32_t  TPI      :1;  /*!< [6:6] TPI位清0  */
            __O uint32_t  TPOI     :1;  /*!< [7:7] TPOI位清0  */
            __O uint32_t  HDI      :1;  /*!< [8:8] HDI位清0  */
            __IO uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_CIC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RSI      :1;  /*!< [0:0] RSI中断使能  */
            __IO uint32_t RDI      :1;  /*!< [1:1] RDI中断使能  */
            __IO uint32_t RBI      :1;  /*!< [2:2] RBI中断使能  */
            __IO uint32_t TEI      :1;  /*!< [3:3] TEI中断使能  */
            __IO uint32_t CHCI     :1;  /*!< [4:4] CHCI中断使能  */
            __IO uint32_t CRCI     :1;  /*!< [5:5] CRCI中断使能  */
            __IO uint32_t TPI      :1;  /*!< [6:6] TPI中断使能  */
            __IO uint32_t TPOI     :1;  /*!< [7:7] TPOI中断使能  */
            __IO uint32_t HDI      :1;  /*!< [8:8] HDI中断使能  */
            __IO uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_CIE0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RSI      :1;  /*!< [0:0] RSI中断使能  */
            __IO uint32_t RDI      :1;  /*!< [1:1] RDI中断使能  */
            __IO uint32_t RBI      :1;  /*!< [2:2] RBI中断使能  */
            __IO uint32_t TEI      :1;  /*!< [3:3] TEI中断使能  */
            __IO uint32_t CHCI     :1;  /*!< [4:4] CHCI中断使能  */
            __IO uint32_t CRCI     :1;  /*!< [5:5] CRCI中断使能  */
            __IO uint32_t TPI      :1;  /*!< [6:6] TPI中断使能  */
            __IO uint32_t TPOI     :1;  /*!< [7:7] TPOI中断使能  */
            __IO uint32_t HDI      :1;  /*!< [8:8] HDI中断使能  */
            __IO uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_CIE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RSI      :3; /*!< [2:0] RSI中断节点指针  */
            __IO uint32_t RDI      :3; /*!< [5:3] RDI中断节点指针  */
            __IO uint32_t RBI      :3; /*!< [8:6] RBI中断节点指针  */
            __IO uint32_t TEI      :3; /*!< [11:9] TEI中断节点指针  */
            __IO uint32_t CHCI     :3; /*!< [14:12] CHCI中断节点指针  */
            __IO uint32_t CRCI     :3; /*!< [17:15] CRCI中断节点指针  */
            __IO uint32_t TPI      :3; /*!< [20:18] TPI中断节点指针  */
            __IO uint32_t TPOI     :3; /*!< [23:21] TPOI中断节点指针  */
            __IO uint32_t HDI      :3; /*!< [26:24] HDI中断节点指针  */
            __IO uint32_t RESERVED0 :5; /*!< [31:27] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_CITRG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RSI      :1;  /*!< [0:0] RSI中断使能  */
            __I uint32_t  RDI      :1;  /*!< [1:1] RDI中断使能 */
            __I uint32_t  RBI      :1;  /*!< [2:2] RBI中断使能 */
            __I uint32_t  TEI      :1;  /*!< [3:3] TEI中断使能 */
            __I uint32_t  CHCI     :1;  /*!< [4:4] CHCI中断使能 */
            __I uint32_t  CRCI     :1;  /*!< [5:5] CRCI中断使能 */
            __I uint32_t  TPI      :1;  /*!< [6:6] TPI中断使能 */
            __I uint32_t  TPOI     :1;  /*!< [7:7] TPOI中断使能  */
            __I uint32_t  HDI      :1;  /*!< [8:8] HDI中断使能  */
            __I uint32_t  TIR      :1;  /*!< [9:9] TIR节点指针中断  */
            __I uint32_t  RIR      :1;  /*!< [10:10] RIR节点指针中断挂起  */
            __I uint32_t  EIR      :1;  /*!< [11:11] EIR节点指针中断挂起  */
            __I uint32_t  TBIR     :1;  /*!< [12:12] TBIR节点指针中断挂起 */
            __I uint32_t  XCRCI    :1;  /*!< [13:13] XCRCI节点指针中断挂起 */
            __I uint32_t  FOI      :1;  /*!< [14:14] FOI节点指针中断挂起  */
            __IO uint32_t RESERVED0 :17; /*!< [31:15] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  TIR      :1;  /*!< [0:0] 发送中断标志位  */
            __I uint32_t  RIR      :1;  /*!< [1:1] 接收中断标志位 */
            __I uint32_t  EIR      :1;  /*!< [2:2] 错误中断标志位 */
            __I uint32_t  TBIR     :1;  /*!< [3:3] 发送缓冲中断标志位 */
            __I uint32_t  XCRCI    :1;  /*!< [4:4] XCRC错误中断标志位  */
            __I uint32_t  FOI      :1;  /*!< [5:5] FIFO错误中断标志位  */
            __IO uint32_t RESERVED0 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_GIF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  TIR      :1;  /*!< [0:0] TIR位置1  */
            __O uint32_t  RIR      :1;  /*!< [1:1] RIR位置1  */
            __O uint32_t  EIR      :1;  /*!< [2:2] EIR位置1  */
            __O uint32_t  TBIR     :1;  /*!< [3:3] TBIR位置1  */
            __O uint32_t  XCRCI    :1;  /*!< [4:4] XCRCI位置1  */
            __O uint32_t  FOI      :1;  /*!< [5:5] FOI位置1  */
            __IO uint32_t RESERVED0 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_GIS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  TIR      :1;  /*!< [0:0] TIR位清0  */
            __O uint32_t  RIR      :1;  /*!< [1:1] RIR位清0  */
            __O uint32_t  EIR      :1;  /*!< [2:2] EIR位清0  */
            __O uint32_t  TBIR     :1;  /*!< [3:3] TBIR位清0  */
            __O uint32_t  XCRCI    :1;  /*!< [4:4] XCRCI位清0  */
            __O uint32_t  FOI      :1;  /*!< [5:5] FOI位清0  */
            __IO uint32_t RESERVED0 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_GIC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TIR      :1;  /*!< [0:0] TIR中断使能  */
            __IO uint32_t RIR      :1;  /*!< [1:1] RIR中断使能  */
            __IO uint32_t EIR      :1;  /*!< [2:2] EIR中断使能  */
            __IO uint32_t TBIR     :1;  /*!< [3:3] TBIR中断使能  */
            __IO uint32_t XCRCI    :1;  /*!< [4:4] XCRCI中断使能  */
            __IO uint32_t FOI      :1;  /*!< [5:5] FOI中断使能  */
            __IO uint32_t RESERVED0 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_GIE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TIR      :3;  /*!< [2:0] TIR中断节点指针  */
            __IO uint32_t RIR      :3;  /*!< [5:3] RIR中断节点指针  */
            __IO uint32_t EIR      :3;  /*!< [8:6] EIR中断节点指针  */
            __IO uint32_t TBIR     :3;  /*!< [11:9] TBIR中断节点指针  */
            __IO uint32_t XCRCI    :3;  /*!< [14:12] XCRCI中断节点指针  */
            __IO uint32_t FOI      :3;  /*!< [17:15] FOI中断节点指针  */
            __IO uint32_t RESERVED0 :14; /*!< [31:18] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_GITRG_T;

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
} PSI5S_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST    :1; /*!< [0:0] 模块复位请求位，与PSI5S_RST1寄存器的RST位一起使用  */
            __I uint32_t  RSTSTA :1; /*!< [1:1] 复位状态  */
            __IO uint32_t RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST :1; /*!< [0:0] 模块复位请求位，与PSI5S_RST0寄存器的RST位一起使用  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} PSI5S_RST1_T;

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
} PSI5S_RSTCLR_T;

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
} PSI5S_ACES0_T;

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
} PSI5S_ACES1_T;

typedef volatile struct
{
    /* offset  : 0x0000.  */
    PSI5S_CLKC_T PSI5S_CLKC;

    /* offset  : 0x0004.  */
    PSI5S_INFO_T PSI5S_INFO;

    /* offset  : 0x0008.  */
    uint8_t PSI5S_RESERVED_F000A008[4];

    /* offset  : 0x000C.  */
    PSI5S_FDR_T PSI5S_FDR;

    /* offset  : 0x0010.  */
    PSI5S_FDRT_T PSI5S_FDRT;

    /* offset  : 0x0014.  */
    PSI5S_TSCNT_T PSI5S_TSCNT[2];

    /* offset  : 0x001C.  */
    PSI5S_GCTL_T PSI5S_GCTL;

    /* offset  : 0x0020.  */
    PSI5S_NFC_T PSI5S_NFC;

    /* offset  : 0x0024.  */
    PSI5S_FCNT_T PSI5S_FCNT;

    /* offset  : 0x0028.  */
    PSI5S_IOCR_T PSI5S_IOCR;

    /* offset  : 0x002C.  */
    uint8_t PSI5S_RESERVED_F000A02C[4];

    /* offset  : 0x0030.  */
    PSI5S_RCRA_T PSI5S_RCRA[8];

    /* offset  : 0x0050.  */
    PSI5S_RCRB_T PSI5S_RCRB[8];

    /* offset  : 0x0070.  */
    PSI5S_WDT_T PSI5S_WDT[8];

    /* offset  : 0x0090.  */
    PSI5S_TSCR_T PSI5S_TSCR[8];

    /* offset  : 0x00B0.  */
    PSI5S_RDS_T PSI5S_RDS;

    /* offset  : 0x00B4.  */
    PSI5S_RDR_T PSI5S_RDR;

    /* offset  : 0x00B8.  */
    PSI5S_TSM_T PSI5S_TSM;

    /* offset  : 0x00BC.  */
    uint8_t PSI5S_RESERVED_F000A0BC[20];

    /* offset  : 0x00D0.  */
    PSI5S_TADR_T PSI5S_TADR;

    /* offset  : 0x00D4.  */
    PSI5S_BADR_T PSI5S_BADR;

    /* offset  : 0x00D8.  */
    uint8_t PSI5S_RESERVED_F000A0D8[24];

    /* offset  : 0x00F0.  */
    PSI5S_PGC_T PSI5S_PGC[8];

    /* offset  : 0x0110.  */
    PSI5S_CTV_T PSI5S_CTV[8];

    /* offset  : 0x0130.  */
    PSI5S_SCR_T PSI5S_SCR[8];

    /* offset  : 0x0150.  */
    PSI5S_SDR_T PSI5S_SDR[8];

    /* offset  : 0x0170.  */
    PSI5S_CDW_T PSI5S_CDW;

    /* offset  : 0x0174.  */
    uint8_t PSI5S_RESERVED_F000A174[156];

    /* offset  : 0x0210.  */
    PSI5S_UCTL_T PSI5S_UCTL;

    /* offset  : 0x0214.  */
    PSI5S_BG_T PSI5S_BG;

    /* offset  : 0x0218.  */
    PSI5S_FDV_T PSI5S_FDV;

    /* offset  : 0x021C.  */
    PSI5S_FDO_T PSI5S_FDO;

    /* offset  : 0x0220.  */
    PSI5S_TBUF_T PSI5S_TBUF;

    /* offset  : 0x0224.  */
    PSI5S_RBUF_T PSI5S_RBUF;

    /* offset  : 0x0228.  */
    uint8_t PSI5S_RESERVED_F000A228[40];

    /* offset  : 0x0250.  */
    PSI5S_WHBCON_T PSI5S_WHBCON;

    /* offset  : 0x0254.  */
    uint8_t PSI5S_RESERVED_F000A254[12];

    /* offset  : 0x0260.  */
    PSI5S_CIF_T PSI5S_CIF[8];

    /* offset  : 0x0280.  */
    PSI5S_CIS_T PSI5S_CIS[8];

    /* offset  : 0x02A0.  */
    PSI5S_CIC_T PSI5S_CIC[8];

    /* offset  : 0x02C0.  */
    PSI5S_CIE_T PSI5S_CIE[8];

    /* offset  : 0x02E0.  */
    PSI5S_CITRG_T PSI5S_CITRG[8];

    /* offset  : 0x0300.  */
    PSI5S_IF_T PSI5S_IF;

    /* offset  : 0x0304.  */
    PSI5S_GIF_T PSI5S_GIF;

    /* offset  : 0x0308.  */
    PSI5S_GIS_T PSI5S_GIS;

    /* offset  : 0x030C.  */
    PSI5S_GIC_T PSI5S_GIC;

    /* offset  : 0x0310.  */
    PSI5S_GIE_T PSI5S_GIE;

    /* offset  : 0x0314.  */
    PSI5S_GITRG_T PSI5S_GITRG;

    /* offset  : 0x0318.  */
    uint8_t PSI5S_RESERVED_F000A318[180];

    /* offset  : 0x03CC.  */
    PSI5S_DBG_T PSI5S_DBG;

    /* offset  : 0x03D0.  */
    PSI5S_RST0_T PSI5S_RST0;

    /* offset  : 0x03D4.  */
    PSI5S_RST1_T PSI5S_RST1;

    /* offset  : 0x03D8.  */
    PSI5S_RSTCLR_T PSI5S_RSTCLR;

    /* offset  : 0x03DC.  */
    PSI5S_ACES0_T PSI5S_ACES0;

    /* offset  : 0x03E0.  */
    PSI5S_ACES1_T PSI5S_ACES1;
} Psi5s_RegisterMap_t;

#define PSI5S_ADDR ((uint32_t)0xF000A000)
#define PSI5S_PTR  ((Psi5s_RegisterMap_t *)PSI5S_ADDR)
#define PSI5S_RM   (*(Psi5s_RegisterMap_t *)PSI5S_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
