/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_spi.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyright protected and proprietary to 
 * Shanghai ChipON Micro-Electronic Co.,Ltd 
 **************************************************************************/

#ifndef _KF32DA13K_REG_SPI_H_
#define _KF32DA13K_REG_SPI_H_

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
typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	DISR: 1; /*!< [0:0] 模块禁止控制位  */
			__I uint32_t	DISS: 1; /*!< [1:1] 模块禁止状态  */
			__IO uint32_t	RESERVED0: 1; /*!< [2:2] 预留读为0  */
			__IO uint32_t	EDIS: 1; /*!< [3:3] 休眠模式禁止位  */
			__IO uint32_t	RESERVED1: 28; /*!< [31:4] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_CLKC_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	DBGCTL: 4; /*!< [3:0] 调试模式挂起控制  */
			__O uint32_t	DBGP: 1; /*!< [4:4] DBGCTL位写保护，读出为0  */
			__I uint32_t	DBGSTA: 1; /*!< [5:5] DEBUG状态位  */
			__IO uint32_t	RESERVED0: 26; /*!< [31:6] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_DBG_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	RST: 1; /*!< [0:0] 模块复位请求位，与RST1寄存器的RST位一起使用  */
			__I uint32_t	RSTSTA: 1; /*!< [1:1] 复位状态  */
			__IO uint32_t	RESERVED0: 30; /*!< [31:2] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_RST0_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	RST: 1; /*!< [0:0] 模块复位请求位，与RST0寄存器的RST位一起使用  */
			__IO uint32_t	RESERVED0: 31; /*!< [31:1] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_RST1_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__O uint32_t	CLR: 1; /*!< [0:0] RSTSTA复位状态清除位，读出为0  */
			__IO uint32_t	RESERVED0: 31; /*!< [31:1] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_RSTCLR_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	EN0: 1; /*!< [0:0] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN1: 1; /*!< [1:1] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN2: 1; /*!< [2:2] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN3: 1; /*!< [3:3] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN4: 1; /*!< [4:4] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN5: 1; /*!< [5:5] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN6: 1; /*!< [6:6] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN7: 1; /*!< [7:7] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN8: 1; /*!< [8:8] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN9: 1; /*!< [9:9] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN10: 1; /*!< [10:10] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN11: 1; /*!< [11:11] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN12: 1; /*!< [12:12] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN13: 1; /*!< [13:13] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN14: 1; /*!< [14:14] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN15: 1; /*!< [15:15] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN16: 1; /*!< [16:16] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN17: 1; /*!< [17:17] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN18: 1; /*!< [18:18] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN19: 1; /*!< [19:19] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN20: 1; /*!< [20:20] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN21: 1; /*!< [21:21] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN22: 1; /*!< [22:22] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN23: 1; /*!< [23:23] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN24: 1; /*!< [24:24] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN25: 1; /*!< [25:25] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN26: 1; /*!< [26:26] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN27: 1; /*!< [27:27] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN28: 1; /*!< [28:28] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN29: 1; /*!< [29:29] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN30: 1; /*!< [30:30] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			__IO uint32_t	EN31: 1; /*!< [31:31] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_ACES0_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	RESERVED0: 32; /*!< [31:0] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_ACES1_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__I uint32_t	MODREV: 8; /*!< [7:0] SPI模块版本信息位  */
			__I uint32_t	MODTYPE: 8; /*!< [15:8] SPI模块类型信息  */
			__I uint32_t	MODNUM: 16; /*!< [31:16] SPI模块编号  */
		}bits;
		__I uint32_t reg;
	};
} SPI_INFO_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	RESERVED0: 32; /*!< [31:0] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_RESV0_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	RESERVED0: 32; /*!< [31:0] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_RESV1_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	RESERVED0: 32; /*!< [31:0] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_RESV2_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	RESERVED0: 32; /*!< [31:0] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_RESV3_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	PDIV: 8; /*!< [7:0] SPI模块时钟预分频  */
			__IO uint32_t	RESERVED0: 1; /*!< [8:8] 预留读为0  */
			__IO uint32_t	STAINJ: 1; /*!< [9:9] 每个数据块后是否将状态寄存器存入接收FIFO  */
			__IO uint32_t	EXPECT: 4; /*!< [13:10] 超时时间长度设置  */
			__IO uint32_t	LOOPBACK: 1; /*!< [14:14] 回环模式选择位  */
			__IO uint32_t	DLY: 1; /*!< [15:15] SS0是否使能延迟模式  */
			__IO uint32_t	STROBE: 5; /*!< [20:16] SS0延迟模式下的选通延时  */
			__IO uint32_t	SRXFULL: 1; /*!< [21:21] 主机模式下，接收FIFO满时是否停止发送  */
			__IO uint32_t	SDOPOL: 1; /*!< [22:22] 从机模式下，空闲态下输出数据极性选择  */
			__IO uint32_t	RESERVED1: 1; /*!< [23:23] 预留读为0  */
			__IO uint32_t	EN: 1; /*!< [24:24] 使能位  */
			__IO uint32_t	MOD: 2; /*!< [26:25] 主机从机模式选择  */
			__IO uint32_t	AUTORST: 1; /*!< [27:27] 从机模式下发生波特率错误/尖峰错误时自动复位模块使能位:CTL0_EN  */
			__IO uint32_t	RESERVED2: 1; /*!< [28:28] 预留读为0  */
			__IO uint32_t	CLKSEL: 1; /*!< [29:29] 时钟源选择  */
			__O uint32_t	CLR: 2; /*!< [31:30] 复位子模块  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_CTL0_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	TXTHRES: 2; /*!< [1:0] 接收FIFO阈值设置  */
			__IO uint32_t	RXTHRES: 2; /*!< [3:2] 接收FIFO阈值设置  */
			__IO uint32_t	PT1SEL: 3; /*!< [6:4] 触发PT1中断事件选择位  */
			__IO uint32_t	PT2SEL: 3; /*!< [9:7] 触发PT2中断事件选择位  */
			__IO uint32_t	TXMOD: 2; /*!< [11:10] 发送FIFO模式选择位  */
			__IO uint32_t	RXMOD: 2; /*!< [13:12] 接收FIFO模式选择位  */
			__IO uint32_t	RESERVED0: 20; /*!< [31:12] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_CTL1_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__I uint32_t	ERRIF: 9; /*!< [8:0] 错误信号标志位  */
			__I uint32_t	TXIF: 1; /*!< [9:9] 发送中断标志位  */
			__I uint32_t	RXIF: 1; /*!< [10:10] 接收中断标志位  */
			__I uint32_t	PT1IF: 1; /*!< [11:11] PT1中断标志位  */
			__I uint32_t	PT2IF: 1; /*!< [12:12] PT2中断标志位  */
			__I uint32_t	USRIF: 1; /*!< [13:13] 用户中断标志位  */
			__IO uint32_t	RESERVED0: 18; /*!< [31:14] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_IF_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	ERRIE: 9; /*!< [8:0] 错误信号使能位  */
			__IO uint32_t	TXIE: 1; /*!< [9:9] 发送中断使能位  */
			__IO uint32_t	RXIE: 1; /*!< [10:10] 接收中断使能位  */
			__IO uint32_t	PT1IE: 1; /*!< [11:11] PT1中断使能位  */
			__IO uint32_t	PT2IE: 1; /*!< [12:12] PT2中断使能位  */
			__IO uint32_t	USRIE: 1; /*!< [13:13] 用户中断使能位  */
			__IO uint32_t	RESERVED0: 18; /*!< [31:14] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_IE_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__O uint32_t	ERRIC: 9; /*!< [8:0] 错误信号清除位  */
			__O uint32_t	TXIC: 1; /*!< [9:9] 发送中断清除位  */
			__O uint32_t	RXIC: 1; /*!< [10:10] 接收中断清除位  */
			__O uint32_t	PT1IC: 1; /*!< [11:11] PT1中断清除位  */
			__O uint32_t	PT2IC: 1; /*!< [12:12] PT2中断清除位  */
			__O uint32_t	USRIC: 1; /*!< [13:13] 用户中断清除位  */
			__IO uint32_t	RESERVED0: 18; /*!< [31:14] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_IC_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__I uint32_t	LAST: 1; /*!< [0:0] 当前发送的字是否为当前帧的最后一个字  */
			__I uint32_t	IPREDIV: 3; /*!< [3:1] idle阶段预分频设置，1个TPER的长度  */
			__I uint32_t	ICNT: 3; /*!< [6:4] idle阶段持续时间长度设置，单位为TPER  */
			__I uint32_t	LPREDIV: 3; /*!< [9:7] lead阶段预分频设置，1个TPER的长度  */
			__I uint32_t	LCNT: 3; /*!< [12:10] lead阶段持续时间长度设置，单位为TPER  */
			__I uint32_t	TPREDIV: 3; /*!< [15:13] trail阶段预分频设置，1个TPER的长度  */
			__I uint32_t	TCNT: 3; /*!< [18:16] trail阶段持续时间长度设置，单位为TPER  */
			__I uint32_t	PARSEL: 1; /*!< [19:19] 奇偶校验位选择  */
			__I uint32_t	USRIE: 1; /*!< [20:20] 后续帧中的PT1事件用户中断使能  */
			__I uint32_t	MSB: 1; /*!< [21:21] 端序选择  */
			__I uint32_t	BYTE: 1; /*!< [22:22] 字节选择  */
			__I uint32_t	DATCNT: 5; /*!< [27:23] 数据长度设置  */
			__I uint32_t	SS: 4; /*!< [31:28] 从机选择信号设置  */
		}bits;
		__I uint32_t reg;
	};
} SPI_SCONF_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	BAUDPREDIV: 6; /*!< [5:0] 波特率预分频设置  */
			__IO uint32_t	ACNT: 2; /*!< [7:6] 在一个数据时钟周期内，A段的持续时间长度设置  */
			__IO uint32_t	BCNT: 2; /*!< [9:8] 在一个数据时钟周期内，B段的持续时间长度设置  */
			__IO uint32_t	CCNT: 2; /*!< [11:10] 在一个数据时钟周期内，C段的持续时间长度设置  */
			__IO uint32_t	SCKPHASE: 1; /*!< [12:12] SCK相位选择  */
			__IO uint32_t	SCKPOL: 1; /*!< [13:13] 空闲态下SCK极性选择  */
			__IO uint32_t	PARCHECK: 1; /*!< [14:14] 奇偶校验检查使能位  */
			__IO uint32_t	RESERVED0: 15; /*!< [29:15] 预留读为0  */
			__IO uint32_t	BIGEND: 2; /*!< [31:30] 大段字节序的转化配置  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_CHCTL_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__I uint32_t	BITCNT: 8; /*!< [7:0] 已经传输的bit数量  */
			__I uint32_t	TXLEVEL: 3; /*!< [10:8] 传输FIFO中的数据数量  */
			__I uint32_t	RXLEVEL: 3; /*!< [13:11] 接收FIFO中的数据数量  */
			__IO uint32_t	RESERVED0: 8; /*!< [21:14] 预留读为0  */
			__I uint32_t	SS: 4; /*!< [25:22] 指示当前活跃的从机  */
			__I uint32_t	RPAR: 1; /*!< [26:26] 接收到的奇偶校验位  */
			__I uint32_t	TPAR: 1; /*!< [27:27] 发送的奇偶校验位  */
			__I uint32_t	TRANSPHA: 4; /*!< [31:28] 当前所处的传输阶段  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_STA0_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	BDDETECTEN: 1; /*!< [0:0] 波特率检测使能  */
			__IO uint32_t	BDDETECT: 1; /*!< [1:1] 波特率检测  */
			__IO uint32_t	SPDETECTEN: 1; /*!< [2:2] 尖峰检测使能  */
			__IO uint32_t	SPDETECT: 1; /*!< [3:3] 尖峰检测  */
			__IO uint32_t	RESERVED0: 28; /*!< [31:4] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_STA1_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	SSLEVEL: 16; /*!< [15:0] 对应的从机选择不使能时的电平值  */
			__IO uint32_t	SSEN: 16; /*!< [31:16] 对应的从机选择信号是否使能  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_SSCFG_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	DATCNT: 16; /*!< [15:0] 超大数据模式下，当前剩余的待传输字节数量  */
			__I uint32_t	CURRCNT: 16; /*!< [31:16] 超大数据模式下，当前剩余的待传输字节数量  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_EXLCNT_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	MOVECNT: 13; /*!< [12:0] 超大数据模式下，当前剩余的待传输字节数量  */
			__IO uint32_t	RESERVED0: 3; /*!< [15:13] 预留读为0  */
			__I uint32_t	CURRCNT: 13; /*!< [28:16] 移动计数模式下，当前剩余的待传输字节数量  */
			__IO uint32_t	RESERVED1: 3; /*!< [31:29] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_MCNT_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	TPREDIV2: 3; /*!< [2:0] 尾阶段2预分频设置，TPER的长度  */
			__IO uint32_t	TCNT2: 3; /*!< [5:3] 尾阶段2时间长度设置，单位为TPER  */
			__IO uint32_t	RESERVED0: 10; /*!< [15:6] 预留读为0  */
			__IO uint32_t	INTBLIE: 1; /*!< [16:16] 在最后一个之前的中断状态使能  */
			__I uint32_t	INTBLIF: 1; /*!< [17:17] 在最后一个之前的中断状态标志位  */
			__O uint32_t	INTBLIC: 1; /*!< [18:18] 复位INTBLIF  */
			__O uint32_t	INTBLIS: 1; /*!< [19:19] 置位INTBLIF  */
			__IO uint32_t	INTALIE: 1; /*!< [20:20] 在最后一个之后的中断状态使能  */
			__I uint32_t	INTALIF: 1; /*!< [21:21] 在最后一个之后的中断状态标志位  */
			__O uint32_t	INTALIC: 1; /*!< [22:22] 复位INTALIF  */
			__O uint32_t	INTALIS: 1; /*!< [23:23] 置位INTALIF  */
			__IO uint32_t	RESERVED1: 6; /*!< [29:24] 预留读为0  */
			__IO uint32_t	TRAIL2EN: 1; /*!< [30:30] 插入尾阶段2使能位  */
			__IO uint32_t	MOVEN: 1; /*!< [31:31] 移动计数模式使能位  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_MCTL_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__O uint32_t	DAT: 32; /*!< [31:0] TXFIFO输入数据  */
		}bits;
		__O uint32_t reg;
	};
} SPI_MIXPUSH_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__O uint32_t	DAT: 32; /*!< [31:0] TXFIFO输入数据  */
		}bits;
		__O uint32_t reg;
	};
} SPI_SCTLPUSH_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__O uint32_t	DAT: 32; /*!< [31:0] TXFIFO输入数据  */
		}bits;
		__O uint32_t reg;
	};
} SPI_DATPUSH_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__I uint32_t	DAT: 32; /*!< [31:0] RXFIFO读出数据  */
		}bits;
		__I uint32_t reg;
	};
} SPI_RXPOP_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__I uint32_t	DAT: 32; /*!< [31:0] RXFIFO读出数据输入数据  */
		}bits;
		__I uint32_t reg;
	};
} SPI_DBGRXPOP_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	MRIS: 3; /*!< [2:0] 主机接收端口选择  */
			__IO uint32_t	RESERVED0: 1; /*!< [3:3] 预留读为0  */
			__IO uint32_t	SRIS: 3; /*!< [6:4] 从机模式下，从机接收端口选择  */
			__IO uint32_t	RESERVED1: 1; /*!< [7:7] 预留读为0  */
			__IO uint32_t	SCIS: 3; /*!< [10:8] 从机模式下，时钟输入端口选择  */
			__IO uint32_t	RESERVED2: 1; /*!< [11:11] 预留读为0  */
			__IO uint32_t	SLSIS: 3; /*!< [14:12] 从机模式下，从机选择输入端口  */
			__IO uint32_t	RESERVED3: 17; /*!< [31:15] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} SPI_PORTSEL_T;

typedef volatile struct
{
	/*offset address: 0x0000, SPI时钟控制寄存器 */
	SPI_CLKC_T SPI_CLKC;

	/*offset address: 0x0004, SPI调试寄存器 */
	SPI_DBG_T SPI_DBG;

	/*offset address: 0x0008, SPI复位寄存器0 */
	SPI_RST0_T SPI_RST0;

	/*offset address: 0x000C, SPI复位寄存器1 */
	SPI_RST1_T SPI_RST1;

	/*offset address: 0x0010, SPI复位状态清零寄存器0 */
	SPI_RSTCLR_T SPI_RSTCLR;

	/*offset address: 0x0014, SPI访问使能寄存器0 */
	SPI_ACES0_T SPI_ACES0;

	/*offset address: 0x0018, SPI访问控制寄存器1 */
	SPI_ACES1_T SPI_ACES1;

	/*offset address: 0x001C, SPI信息寄存器 */
	SPI_INFO_T SPI_INFO;

	/*offset address: 0x0020, SPI预留寄存器0 */
	SPI_RESV0_T SPI_RESV0;

	/*offset address: 0x0024, SPI预留寄存器1 */
	SPI_RESV1_T SPI_RESV1;

	/*offset address: 0x0028, SPI预留寄存器2 */
	SPI_RESV2_T SPI_RESV2;

	/*offset address: 0x002C, SPI预留寄存器3 */
	SPI_RESV3_T SPI_RESV3;

	/*offset address: 0x0030, SPI控制寄存器0 */
	SPI_CTL0_T SPI_CTL0;

	/*offset address: 0x0034, SPI控制寄存器1 */
	SPI_CTL1_T SPI_CTL1;

	/*offset address: 0x0038, SPI中断标志位寄存器 */
	SPI_IF_T SPI_IF;

	/*offset address: 0x003C, SPI中断使能寄存器 */
	SPI_IE_T SPI_IE;

	/*offset address: 0x0040, SPI中断清除寄存器 */
	SPI_IC_T SPI_IC;

	/*offset address: 0x0044, SPI从机控制寄存器 */
	SPI_SCONF_T SPI_SCONF;

	/*offset address: 0x0048, SPI通道控制寄存器x(x=0-7) */
	SPI_CHCTL_T SPI_CHCTL[8];

	/*offset address: 0x0068, SPI状态寄存器0 */
	SPI_STA0_T SPI_STA0;

	/*offset address: 0x006C, SPI状态寄存器1 */
	SPI_STA1_T SPI_STA1;

	/*offset address: 0x0070, SPI从机选择信号配置寄存器 */
	SPI_SSCFG_T SPI_SSCFG;

	/*offset address: 0x0074, SPI超长数据模式计数寄存器 */
	SPI_EXLCNT_T SPI_EXLCNT;

	/*offset address: 0x0078, SPI移动计数寄存器 */
	SPI_MCNT_T SPI_MCNT;

	/*offset address: 0x007C, SPI移动计数模式控制寄存器 */
	SPI_MCTL_T SPI_MCTL;

	/*offset address: 0x0080, SPI混合数据输入寄存器 */
	SPI_MIXPUSH_T SPI_MIXPUSH;

	/*offset address: 0x0084, SPI从机控制输入寄存器 */
	SPI_SCTLPUSH_T SPI_SCTLPUSH;

	/*offset address: 0x0088, SPI数据输入寄存器x(x=0-7) */
	SPI_DATPUSH_T SPI_DATPUSH[8];

	/*offset address: 0x00A8, SPI数据输出寄存器 */
	SPI_RXPOP_T SPI_RXPOP;

	/*offset address: 0x00AC, SPI在Debug模式下数据输出寄存器 */
	SPI_DBGRXPOP_T SPI_DBGRXPOP;

	/*offset address: 0x00B0, SPI端口选择寄存器 */
	SPI_PORTSEL_T SPI_PORTSEL;
} Spi_RegisterMap_t;

#define SPI0_ADDR ((uint32_t)0xF4000000)
#define SPI0_PTR ((Spi_RegisterMap_t *)SPI0_ADDR)
#define SPI0_RM (*(Spi_RegisterMap_t *)SPI0_ADDR)

#define SPI1_ADDR ((uint32_t)0xF4000100)
#define SPI1_PTR ((Spi_RegisterMap_t *)SPI1_ADDR)
#define SPI1_RM (*(Spi_RegisterMap_t *)SPI1_ADDR)

#define SPI2_ADDR ((uint32_t)0xF4000200)
#define SPI2_PTR ((Spi_RegisterMap_t *)SPI2_ADDR)
#define SPI2_RM (*(Spi_RegisterMap_t *)SPI2_ADDR)

#define SPI3_ADDR ((uint32_t)0xF4000300)
#define SPI3_PTR ((Spi_RegisterMap_t *)SPI3_ADDR)
#define SPI3_RM (*(Spi_RegisterMap_t *)SPI3_ADDR)


#ifdef __cplusplus
}
#endif

#endif
/* EOF */
