/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_dma.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyright protected and proprietary to
 * Shanghai ChipON Micro-Electronic Co.,Ltd
 **************************************************************************/
/**************************************************************************
 *                              REVISION HISTORY
 **************************************************************************
 *  |Date        |Version  |Author       |Description
 **************************************************************************
 *  |2024-03-19  |V1.0     |Hong Xu      |New creat
 *************************************************************************/

#ifndef _KF32DA13K_REG_DMA_H_
#define _KF32DA13K_REG_DMA_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *         Include Files
 **************************************************************************/
#include <stdint.h>
#include "kf_types.h"

/**************************************************************************
 *         Mcro ro typedef
 **************************************************************************/

/* DMA时钟控制寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁用控制位，用于控制DMA的使能/禁用  */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁用状态，DMA当前状态位  */
            __IO uint32_t RESERVED0 :1;  /*!< [2:2] 预留读为0  */
            __IO uint32_t EDIS      :1;  /*!< [3:3] 休眠模式使能控制，用于DMA休眠模式控制  */
            __IO uint32_t RESERVED1 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_CLKC_T;

/* DMA信息寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] DMA模块版本信息位  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] DMA模块类型信息  */
            __I uint32_t MODNUM  :16; /*!< [31:16] DMA模块编号  */
        } bits;
        __I uint32_t reg;
    };
} DMA_INFO_T;

/* DMA调试寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TGS       :4;  /*!< [3:0] 触发设置  */
            __IO uint32_t RESERVED0 :3;  /*!< [6:4] 预留读为0  */
            __IO uint32_t BS        :1;  /*!< [7:7] OTGB0/1总线选择  */
            __IO uint32_t RESERVED1 :24; /*!< [31:8] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_DBG_T;

/* DMA数据对照寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PRT0 :8; /*!< [7:0] 数据对照字节  */
            __IO uint32_t PRT1 :8; /*!< [15:8] 数据对照字节  */
            __IO uint32_t PRT2 :8; /*!< [23:16] 数据对照字节  */
            __IO uint32_t PRT3 :8; /*!< [31:24] 数据对照字节  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_PRR_T;

/* DMA定时寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CNT :32; /*!< [31:0] 时间戳计数，DMA附加时间戳期间使用的计数值  */
        } bits;
        __I uint32_t reg;
    };
} DMA_TIME_T;

/* DMA访问组x访问使能寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              EN0 :1; /*!< [0:0] 主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理  */
            __IO uint32_t
              EN1 :1; /*!< [1:1] 主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理  */
            __IO uint32_t
              EN2 :1; /*!< [2:2] 主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理  */
            __IO uint32_t
              EN3 :1; /*!< [3:3] 主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理  */
            __IO uint32_t
              EN4 :1; /*!< [4:4] 主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理  */
            __IO uint32_t
              EN5 :1; /*!< [5:5] 主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理  */
            __IO uint32_t
              EN6 :1; /*!< [6:6] 主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理  */
            __IO uint32_t
              EN7 :1; /*!< [7:7] 主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理  */
            __IO uint32_t
              EN8 :1; /*!< [8:8] 主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理  */
            __IO uint32_t
              EN9 :1; /*!< [9:9] 主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理  */
            __IO uint32_t EN10 :1; /*!< [10:10]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN11 :1; /*!< [11:11]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN12 :1; /*!< [12:12]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN13 :1; /*!< [13:13]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN14 :1; /*!< [14:14]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN15 :1; /*!< [15:15]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN16 :1; /*!< [16:16]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN17 :1; /*!< [17:17]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN18 :1; /*!< [18:18]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN19 :1; /*!< [19:19]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN20 :1; /*!< [20:20]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN21 :1; /*!< [21:21]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN22 :1; /*!< [22:22]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN23 :1; /*!< [23:23]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN24 :1; /*!< [24:24]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN25 :1; /*!< [25:25]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN26 :1; /*!< [26:26]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN27 :1; /*!< [27:27]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN28 :1; /*!< [28:28]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN29 :1; /*!< [29:29]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN30 :1; /*!< [30:30]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
            __IO uint32_t EN31 :1; /*!< [31:31]
                                      主机标签号q的访问使能，此位允许对模块内核地址进行写访问，以便与主机标签q的事务处理
                                    */
        } bits;
        __IO uint32_t reg;
    };
    __IO uint32_t RESERVED;
} DMA_ACES_T;

/* 搬运引擎x错误中断使能寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :16; /*!< [15:0] 预留读为0  */
            __IO uint32_t SEIE      :1;  /*!< [16:16] 使能搬运引擎源报错  */
            __IO uint32_t DEIE      :1;  /*!< [17:17] 使能搬运引擎目标报错  */
            __IO uint32_t RESERVED1 :8;  /*!< [25:18] 预留读为0  */
            __IO uint32_t DLLEIE    :1;  /*!< [26:26] 使能搬运引擎DMA链表报错  */
            __IO uint32_t RESERVED2 :5;  /*!< [31:27] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_EIE_T;

/* 搬运引擎x错误状态寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  LEC       :6;  /*!< [5:0] 搬运引擎上一个错误通道  */
            __IO uint32_t RESERVED0 :10; /*!< [15:6] 预留读为0  */
            __I uint32_t  SEIF      :1;  /*!< [16:16] 搬运引擎源错误状态  */
            __I uint32_t  DEIF      :1;  /*!< [17:17] 搬运引擎目标错误状态  */
            __IO uint32_t RESERVED1 :2;  /*!< [19:18] 预留读为0  */
            __I uint32_t  PERIEIF   :1;  /*!< [20:20] 搬运引擎Peri_BUS总线错误状态  */
            __I uint32_t  SYSEIF    :1;  /*!< [21:21] 搬运引擎System_BUS总线错误状态  */
            __IO uint32_t RESERVED2 :2;  /*!< [23:22] 预留读为0  */
            __I uint32_t  RAMEIF    :1;  /*!< [24:24] 搬运引擎RMA错误状态  */
            __I uint32_t  SLLEIF    :1;  /*!< [25:25] 搬运引擎安全链表错误状态  */
            __I uint32_t  DLLEIF    :1;  /*!< [26:26] 搬运引擎DMA链表错误状态  */
            __IO uint32_t RESERVED3 :5;  /*!< [31:27] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_EIF_T;

/* 搬运引擎x错误状态寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :16; /*!< [15:0] 预留读为0  */
            __O uint32_t  SEIC      :1;  /*!< [16:16] 清除SEIF  */
            __O uint32_t  DEIC      :1;  /*!< [17:17] 清除DEIF  */
            __IO uint32_t RESERVED1 :2;  /*!< [19:18] 预留读为0  */
            __O uint32_t  PERIEIC   :1;  /*!< [20:20] 清除PERIEIF  */
            __O uint32_t  SYSEIC    :1;  /*!< [21:21] 清除SYSEIF  */
            __IO uint32_t RESERVED2 :2;  /*!< [23:22] 预留读为0  */
            __O uint32_t  RAMEIC    :1;  /*!< [24:24] 清除RAMEIF  */
            __O uint32_t  SLLEIC    :1;  /*!< [25:25] 清除SLLEIF  */
            __O uint32_t  DLLEIC    :1;  /*!< [26:26] 清除DLLEIF  */
            __IO uint32_t RESERVED3 :5;  /*!< [31:27] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_EIC_T;

/* 搬运引擎x状态寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RSTA      :1;  /*!< [0:0] 搬运引擎读状态  */
            __IO uint32_t RESERVED0 :3;  /*!< [3:1] 预留读为0  */
            __I uint32_t  WSTA      :1;  /*!< [4:4] 搬运引擎写状态  */
            __IO uint32_t RESERVED1 :11; /*!< [15:5] 预留读为0  */
            __I uint32_t  CH        :6;  /*!< [21:16] 搬运引擎激活的通道  */
            __IO uint32_t RESERVED2 :10; /*!< [31:22] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_MESTA_T;

/* 搬运引擎x读取寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RD0 :8; /*!< [7:0] DMA读搬运数据  */
            __I uint32_t RD1 :8; /*!< [15:8] DMA读搬运数据  */
            __I uint32_t RD2 :8; /*!< [23:16] DMA读搬运数据  */
            __I uint32_t RD3 :8; /*!< [31:24] DMA读搬运数据  */
        } bits;
        __I uint32_t reg;
    };
} DMA_MERR_T;

/* 搬运引擎x读取数据CRC寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RDCRC :32; /*!< [31:0] DMA读取数据CRC  */
        } bits;
        __I uint32_t reg;
    };
} DMA_MERDCRC_T;

/* 搬运引擎x地址CRC寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SDCRC :32; /*!< [31:0] 源及目标地址CRC  */
        } bits;
        __I uint32_t reg;
    };
} DMA_MESDCRC_T;

/* 搬运引擎x源地址寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SADR :32; /*!< [31:0] 源地址  */
        } bits;
        __I uint32_t reg;
    };
} DMA_MESADR_T;

/* 搬运引擎x目标地址寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t DADR :32; /*!< [31:0] 目标地址  */
        } bits;
        __I uint32_t reg;
    };
} DMA_MEDADR_T;

/* 搬运引擎x地址及中断控制寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SMF  :3; /*!< [2:0] 源地址修改系数  */
            __I uint32_t INCS :1; /*!< [3:3] 源地址递增  */
            __I uint32_t DMF  :3; /*!< [6:4] 目标地址修改系数  */
            __I uint32_t INCD :1; /*!< [7:7] 目标地址递增  */
            __I uint32_t CBLS :4; /*!< [11:8] 循环缓冲区源地址长度  */
            __I uint32_t CBLD :4; /*!< [15:12] 循环缓冲区目标地址长度  */
            __I uint32_t SHCT :4; /*!< [19:16] 影子控制  */
            __I uint32_t SCBE :1; /*!< [20:20] 使能DMA通道源循环缓冲区  */
            __I uint32_t DCBE :1; /*!< [21:21] 使能DMA通道目标循环缓冲区  */
            __I uint32_t STAMP :1; /*!< [22:22] 时间戳。DMA处理中的上一次DMA搬运结束后，启用附件的时间戳  */
            __IO uint32_t RESERVED0 :1; /*!< [23:23] 预留读为0  */
            __I uint32_t WRPSE :1; /*!< [24:24] 使能源缓冲区回环。使能/禁用DMA通道通道配置源缓冲区中断触发  */
            __I uint32_t WRPDE :1; /*!< [25:25] 使能目标缓冲区回环。使能/禁用DMA通道通道配置目标缓冲区中断触发  */
            __I uint32_t INTCT :2; /*!< [27:26] 中断控制  */
            __I uint32_t IRDV  :4; /*!< [31:28]
                                      中断检测值提升。DMA通道通道配置中断阈值定义了通道中断触发时的TCNT的阈值限制  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_MEADICR_T;

/* 搬运引擎x通道控制寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  TREL :14;     /*!< [13:0] 传输重载值。控制1个DMA处理中的DMA传输任务数量  */
            __IO uint32_t RESERVED0 :2; /*!< [15:14] 预留读为0  */
            __I uint32_t  BLKM      :3; /*!< [18:16] 块模式  */
            __I uint32_t  RROAT     :1; /*!< [19:19] 仅当DMA处理结束后重置请求  */
            __I uint32_t  CHMODE    :1; /*!< [20:20] 通道操作模式  */
            __I uint32_t  CHDW      :3; /*!< [23:21] 通道数据宽度  */
            __I uint32_t  PRTSEL    :3; /*!< [26:24] 模式选择  */
            __I uint32_t  SWAP      :1; /*!< [27:27] 交换数据CRC字节序  */
            __I uint32_t  PRSEL     :1; /*!< [28:28] 外设请求选择  */
            __IO uint32_t RESERVED1 :3; /*!< [31:29] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_MECHCTL_T;

/* 搬运引擎x通道状态寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SHADR :32; /*!< [31:0] 影子地址  */
        } bits;
        __I uint32_t reg;
    };
} DMA_MESHADR_T;

/* 搬运引擎x通道状态寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t TCNT :14; /*!< [13:0] 传输计数值。DMA通道状态传输计数值在DMARAM写回之后更新  */
            __IO uint32_t RESERVED0 :1; /*!< [14:14] 预留读为0  */
            __I uint32_t  LXO       :1; /*!< [15:15] 数据对照的上一个值  */
            __I uint32_t  WRPS      :1; /*!< [16:16] 源缓冲区回环状态  */
            __I uint32_t  WRPD      :1; /*!< [17:17] 目标缓冲区回环状态  */
            __I uint32_t  ICH       :1; /*!< [18:18] 通道的中断状态  */
            __I uint32_t  IPM       :1; /*!< [19:19] 通道数据对照  */
            __IO uint32_t RESERVED1 :2; /*!< [21:20] 预留读为0  */
            __I uint32_t  BUFFER    :1; /*!< [22:22] DMA双缓冲区激活缓冲  */
            __I uint32_t  FROZEN    :1; /*!< [23:23] DMA双缓冲区冻结缓冲  */
            __IO uint32_t RESERVED2 :8; /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_MECHSTA_T;

/* DMA访问组x模式寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t MOD       :1;  /*!< [0:0] 访问组的管理模式  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_MOD_T;

/* DMA访问组x错误中断置位寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  SIT       :1;  /*!< [0:0] 设置错误中断服务请求  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_EIS_T;

/* DMA通道y访问组寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t HRP       :2;  /*!< [1:0] DMA通道访问组  */
            __IO uint32_t RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_HRR_T;

/* DMA通道y挂起使能寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SUSEN     :1;  /*!< [0:0] DMA通道挂起使能  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_SUSENR_T;

/* DMA通道y挂起应答寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  SUSAC     :1;  /*!< [0:0] DMA通道的挂起或冻结状态  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_SUSACR_T;

/* DMA通道y处理状态寄存器 */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST  :1; /*!< [0:0] DMA通道重置  */
            __I uint32_t  HTRE :1; /*!< [1:1] DMA通道硬件请求使能位  */
            __I uint32_t
              TRL :1;                   /*!< [2:2]
                                           DMA通道处理/传输请求丢失。软件通过TSR.CTL写1清除DMA传输丢包或者通过TSR.RST写1重置DMA通道来重置该位
                                         */
            __I uint32_t  CH        :1; /*!< [3:3] DMA通道处理请求状态  */
            __IO uint32_t ETRL      :1; /*!< [4:4] 使能DMA通道处理/传输请求丢失中断  */
            __IO uint32_t RESERVED0 :3; /*!< [7:5] 预留读为0  */
            __IO uint32_t
              HLTREQ :1; /*!< [8:8] DMA通道中止请求。软件通过TSR.HLTREQ写1设置中止请求，TSR.HLTCLR写1清除中止请求。  */
            __I uint32_t  HLTACK    :1; /*!< [9:9] DMA通道中止告知  */
            __IO uint32_t RESERVED1 :6; /*!< [15:10] 预留读为0  */
            __O uint32_t  ECH       :1; /*!< [16:16] 使能DMA通道硬件处理请求  */
            __O uint32_t  DCH       :1; /*!< [17:17] 禁用DMA通道硬件处理请求  */
            __O uint32_t  CTL       :1; /*!< [18:18] 清除DMA通道处理/传输请求丢失  */
            __IO uint32_t RESERVED2 :5; /*!< [23:19] 预留读为0  */
            __O uint32_t  HLTIC     :1; /*!< [24:24] 清除DMA通道中止请求和告知  */
            __IO uint32_t RESERVED3 :7; /*!< [31:25] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} DMA_TSR_T;

/* DMA RAM通道 读取数据CRC寄存器\地址CRC寄存器\源地址寄存器\目标地址寄存器\
 * 地址及中断控制寄存器\配置寄存器\影子地址寄存器\控制及状态寄存器 联合 */
typedef volatile struct
{
    /* DMA RAM通道读取数据CRC寄存器 */
    union
    {
        struct
        {
            __IO uint32_t RDCRC :32; /*!< [31:0] 读取数据CRC，DMA读搬运数据的计算校验和  */
        } bits;
        __IO uint32_t reg;
    } RDCRC;

    /* DMA RAM通道地址CRC寄存器 */
    union
    {
        struct
        {
            __IO uint32_t SDCRC :32; /*!< [31:0] 源地址和目标地址CRC，DMA搬运地址的计算校验和  */
        } bits;
        __IO uint32_t reg;
    } SDCRC;

    /* DMA RAM通道源地址寄存器 */
    union
    {
        struct
        {
            __IO uint32_t SADR :32; /*!< [31:0] 源地址  */
        } bits;
        __IO uint32_t reg;
    } SADR;

    /* DMA RAM通道目标地址寄存器 */
    union
    {
        struct
        {
            __IO uint32_t DADR :32; /*!< [31:0] 目标地址  */
        } bits;
        __IO uint32_t reg;
    } DADR;

    /* DMA RAM通道地址及中断控制寄存器 */
    union
    {
        struct
        {
            __IO uint32_t SMF  :3; /*!< [2:0] 源地址修改系数  */
            __IO uint32_t INCS :1; /*!< [3:3] 源地址递增  */
            __IO uint32_t DMF  :3; /*!< [6:4] 目标地址修改系数  */
            __IO uint32_t INCD :1; /*!< [7:7] 目标地址递增  */
            __IO uint32_t CBLS :4; /*!< [11:8] 循环缓冲区源地址长度  */
            __IO uint32_t CBLD :4; /*!< [15:12] 循环缓冲区目标地址长度  */
            __IO uint32_t SHCT :4; /*!< [19:16] 影子控制  */
            __IO uint32_t SCBE :1; /*!< [20:20] 使能DMA通道源循环缓冲区  */
            __IO uint32_t DCBE :1; /*!< [21:21] 使能DMA通道目标循环缓冲区  */
            __IO uint32_t STAMP :1; /*!< [22:22] 时间戳。DMA处理中的上一次DMA搬运结束后，启用附件的时间戳  */
            __IO uint32_t RESERVED0 :1; /*!< [23:23] 预留读为0  */
            __IO uint32_t WRPSE :1; /*!< [24:24] 使能源缓冲区回环。使能/禁用DMA通道通道配置源缓冲区中断触发  */
            __IO uint32_t WRPDE :1; /*!< [25:25] 使能目标缓冲区回环。使能/禁用DMA通道通道配置目标缓冲区中断触发  */
            __IO uint32_t INTCT :2; /*!< [27:26] 中断控制  */
            __IO uint32_t IRDV  :4; /*!< [31:28]
                                       中断检测值提升。DMA通道通道配置中断阈值定义了通道中断触发时的TCNT的阈值限制  */
        } bits;
        __IO uint32_t reg;
    } ADICR;

    /* DMARAM通道配置寄存器 */
    union
    {
        struct
        {
            __IO uint32_t TREL :14;     /*!< [13:0] 传输重载值。控制1个DMA处理中的DMA传输任务数量  */
            __IO uint32_t RESERVED0 :2; /*!< [15:14] 预留读为0  */
            __IO uint32_t BLKM      :3; /*!< [18:16] 块模式  */
            __IO uint32_t RROAT     :1; /*!< [19:19] 仅当DMA处理结束后重置请求  */
            __IO uint32_t CHMODE    :1; /*!< [20:20] 通道操作模式  */
            __IO uint32_t CHDW      :3; /*!< [23:21] 通道数据宽度  */
            __IO uint32_t PRTSEL    :3; /*!< [26:24] 模式选择  */
            __IO uint32_t SWAP      :1; /*!< [27:27] 交换数据CRC字节序  */
            __IO uint32_t PRSEL     :1; /*!< [28:28] 外设请求选择  */
            __IO uint32_t RESERVED1 :3; /*!< [31:29] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } CHCFGR;

    /* DMARAM通道影子地址寄存器 */
    union
    {
        struct
        {
            __IO uint32_t SHADR :32; /*!< [31:0] 影子地址  */
        } bits;
        __IO uint32_t reg;
    } SHADR;

    /* DMARAM通道控制及状态寄存器 */
    union
    {
        struct
        {
            __I uint32_t TCNT :14; /*!< [13:0] 传输计数值。DMA通道状态传输计数值在DMARAM写回之后更新  */
            __IO uint32_t RESERVED0 :1; /*!< [14:14] 预留读为0  */
            __I uint32_t  LXO       :1; /*!< [15:15] 数据对照的上一个值  */
            __I uint32_t  WRPS      :1; /*!< [16:16] 源缓冲区回环状态  */
            __I uint32_t  WRPD      :1; /*!< [17:17] 目标缓冲区回环状态  */
            __I uint32_t  ICH       :1; /*!< [18:18] 通道的中断状态  */
            __I uint32_t  IPM       :1; /*!< [19:19] 通道数据对照  */
            __IO uint32_t RESERVED1 :2; /*!< [21:20] 预留读为0  */
            __I uint32_t  BUFFER    :1; /*!< [22:22] DMA双缓冲区激活缓冲  */
            __IO uint32_t FROZEN    :1; /*!< [23:23] DMA双缓冲区冻结缓冲  */
            __O uint32_t  SWB       :1; /*!< [24:24] DMA双缓冲区缓冲切换  */
            __O uint32_t
              CWRP :1; /*!< [25:25]
                          回环缓冲区中断清除。如果DMA通道处于激活状态，那么该位也可清除ME中的位域CHSTA.WRPS和CHSTA.WRPD
                        */
            __O uint32_t
              CICH :1;                  /*!< [26:26]
                                           DMA中断清除。如果DMA通道处于激活状态，那么该位也可清除ME中的位域CHSTA.ICH和CHSTA.IPM
                                         */
            __O uint32_t  SIT       :1; /*!< [27:27] DMA通道设置中断触发  */
            __IO uint32_t RESERVED2 :3; /*!< [30:28] 预留读为0  */
            __O uint32_t  SCH       :1; /*!< [31:31] 设置处理请求  */
        } bits;
        __IO uint32_t reg;
    } CTLSTA;
} DMA_RAMCHAINFO_T;

typedef volatile struct
{
    /*offset address: 0x0000, DMA时钟控制寄存器 */
    DMA_CLKC_T CLKC;

    /*offset address: 0x0004, DMA基本信息寄存器 */
    DMA_INFO_T INFO;

    /*offset address: 0x0008, DMA调试寄存器 */
    DMA_DBG_T DBG;

    /*offset address: 0x000C, 预留 */
    uint32_t RESERVED_000C;

    /*offset address: 0x0010, DMA数据对照寄存器0-1 */
    DMA_PRR_T PRR[2];

    /*offset address: 0x0018, DMA定时寄存器 */
    DMA_TIME_T TIME;

    /*offset address: 0x001C, 预留 */
    uint32_t RESERVED_001C[9];

    /*offset address: 0x0040, DMA访问组x访问使能寄存器 */
    DMA_ACES_T ACES[4];

    /*offset address: 0x0060, 预留 */
    uint32_t RESERVED_005C[48];

    /*offset address: 0x0120, 搬运引擎0错误中断使能寄存器 */
    DMA_EIE_T EIE0;

    /*offset address: 0x0124, 搬运引擎0错误状态寄存器 */
    DMA_EIF_T EIF0;

    /*offset address: 0x0128, 搬运引擎0错误状态清零寄存器 */
    DMA_EIC_T EIC0;

    /*offset address: 0x012C, 预留 */
    uint32_t RESERVED_012C;

    /*offset address: 0x0130, 搬运引擎0状态寄存器 */
    DMA_MESTA_T ME0STA;

    /*offset address: 0x0134, 预留 */
    uint32_t RESERVED_0134[3];

    /*offset address: 0x0140, 搬运引擎0读取寄存器0 */
    DMA_MERR_T MER0R[16];

    /*offset address: 0x0180, 搬运引擎0读取数据CRC寄存器 */
    DMA_MERDCRC_T ME0RDCRC;

    /*offset address: 0x0184, 搬运引擎0地址CRC寄存器 */
    DMA_MESDCRC_T ME0SDCRC;

    /*offset address: 0x0188, 搬运引擎0源地址寄存器 */
    DMA_MESADR_T ME0SADR;

    /*offset address: 0x018C, 搬运引擎0目标地址寄存器 */
    DMA_MEDADR_T ME0DADR;

    /*offset address: 0x0190, 搬运引擎0地址及中断控制寄存器 */
    DMA_MEADICR_T ME0ADICR;

    /*offset address: 0x0194, 搬运引擎0通道控制寄存器 */
    DMA_MECHCTL_T ME0CHCTL;

    /*offset address: 0x0198, 搬运引擎0影子地址寄存器 */
    DMA_MESHADR_T ME0SHADR;

    /*offset address: 0x019C, 搬运引擎0通道状态寄存器 */
    DMA_MECHSTA_T ME0CHSTA;

    /*offset address: 0x01A0, 预留 */
    uint32_t RESERVED_01A0[992];

    /*offset address: 0x1120, 搬运引擎1错误中断使能寄存器 */
    DMA_EIE_T EIE1;

    /*offset address: 0x1124, 搬运引擎1错误状态寄存器 */
    DMA_EIF_T EIF1;

    /*offset address: 0x1128, 搬运引擎1错误状态清零寄存器 */
    DMA_EIC_T EIC1;

    /*offset address: 0x112C, 搬运引擎1状态寄存器 */
    uint32_t RESERVED_112C;

    /*offset address: 0x1130, 搬运引擎1状态寄存器 */
    DMA_MESTA_T ME1STA;

    /*offset address: 0x1134, 预留 */
    uint32_t RESERVED_1134[3];

    /*offset address: 0x1140, 搬运引擎1读取寄存器0 */
    DMA_MERR_T MER1R[16];

    /*offset address: 0x1180, 搬运引擎1读取数据CRC寄存器 */
    DMA_MERDCRC_T ME1RDCRC;

    /*offset address: 0x1184, 搬运引擎1地址CRC寄存器 */
    DMA_MESDCRC_T ME1SDCRC;

    /*offset address: 0x1188, 搬运引擎1源地址寄存器 */
    DMA_MESADR_T ME1SADR;

    /*offset address: 0x118C, 搬运引擎1目标地址寄存器 */
    DMA_MEDADR_T ME1DADR;

    /*offset address: 0x1190, 搬运引擎1地址及中断控制寄存器 */
    DMA_MEADICR_T ME1ADICR;

    /*offset address: 0x1194, 搬运引擎1通道控制寄存器 */
    DMA_MECHCTL_T ME1CHCTL;

    /*offset address: 0x1198, 搬运引擎1影子地址寄存器 */
    DMA_MESHADR_T ME1SHADR;

    /*offset address: 0x119C, 搬运引擎1通道状态寄存器 */
    DMA_MECHSTA_T ME1CHSTA;

    /*offset address: 0x11A0, 预留 */
    uint32_t RESERVED_11A0[88];

    /*offset address: 0x1300, DMA访问组x模式寄存器 */
    DMA_MOD_T MOD[4];

    /*offset address: 0x1310, 预留 */
    uint32_t RESERVED_1310[4];

    /*offset address: 0x1320, DMA访问组x错误中断置位寄存器 */
    DMA_EIS_T EIS[4];

    /*offset address: 0x1330, 预留 */
    uint32_t RESERVED_1330[308];

    /*offset address: 0x1800, DMA通道y访问组寄存器 */
    DMA_HRR_T HRR[64];

    /*offset address: 0x1900, 预留 */
    uint32_t RESERVED_1900[64];

    /*offset address: 0x1A00, DMA通道y挂起使能寄存器 */
    DMA_SUSENR_T SUSENR[64];

    /*offset address: 0x1B00, DMA通道y挂起应答寄存器 */
    uint8_t RESERVED_1B00[256];

    /*offset address: 0x1C00, DMA通道y挂起应答寄存器 */
    DMA_SUSACR_T SUSACR[64];

    /*offset address: 0x1D00, 预留 */
    uint32_t RESERVED_1D00[64];

    /*offset address: 0x1E00, DMA通道y处理状态寄存器 */
    DMA_TSR_T TSR[64];

    /*offset address: 0x1F00, 预留 */
    uint32_t RESERVED_1F00[64];

    /*offset address: 0x2000,
     * DMARAM通道y读取数据CRC寄存器\地址CRC寄存器\源地址寄存器\目标地址寄存器\
     * 地址及中断控制寄存器\配置寄存器\影子地址寄存器\控制及状态寄存器 等联合
     */
    DMA_RAMCHAINFO_T CHAINFO[64];

} Dma_RegisterMap_t;

#define DMA_ADDR ((uint32_t)0xF00A0000)
#define DMA_PTR  ((Dma_RegisterMap_t *)DMA_ADDR)
#define DMA_RM   (*(Dma_RegisterMap_t *)DMA_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
