/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_mtu.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyright protected and proprietary to
 * Shanghai ChipON Micro-Electronic Co.,Ltd
 **************************************************************************/

#ifndef _KF32DA13K_REG_MTU_H_
#define _KF32DA13K_REG_MTU_H_

#ifdef __cplusplus
extern "C"
{
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
				__IO uint32_t DISR : 1; /*!< [0:0] 模块禁止控制位  */
				__I uint32_t DISS : 1;	/*!< [1:1] 模块禁止状态  */
				__IO uint32_t : 1;		/*!< [2:2] 预留读为0  */
				__IO uint32_t EDIS : 1; /*!< [3:3] 休眠模式禁止位  */
				__IO uint32_t : 28;		/*!< [31:4] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_CLC_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MODREV : 8;  /*!< [7:0] SCU模块版本信息位  */
				__I uint32_t MODTYPE : 8; /*!< [15:8] SCU模块类型信息  */
				__I uint32_t MODNUM : 16; /*!< [31:16] SCU模块编号  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_ID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t MEMyEN : 32; /*!< [31:0] 内存yMBIST使能  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMTEST0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t MEMyEN : 32; /*!< [31:0] 内存yMBIST使能  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMTEST1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t MEMyEN : 32; /*!< [31:0] 内存yMBIST使能  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMTEST2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMxEN : 32; /*!< [31:0] 内存xMBIST使能  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMTEST_STS0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMxEN : 32; /*!< [31:0] 内存xMBIST使能  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMTEST_STS1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMxEN : 32; /*!< [31:0] 内存xMBIST使能  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMTEST_STS2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t MEMyMAP : 32; /*!< [31:0] 内存y映射使能  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMMAP_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMyMAP : 32; /*!< [31:0] 内存y映射使能  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMMAP_STS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMyAIU : 32; /*!< [31:0] 内存yMBIST自动初始化进行  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMSTAT0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMyAIU : 32; /*!< [31:0] 内存yMBIST自动初始化进行  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMSTAT1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMyAIU : 32; /*!< [31:0] 内存yMBIST自动初始化进行  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMSTAT2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMyDONE : 32; /*!< [31:0] 内存SSHMSTATUS.DONE  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMDONE0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMyDONE : 32; /*!< [31:0] 内存SSHMSTATUS.DONE  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMDONE1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMyDONE : 32; /*!< [31:0] 内存SSHMSTATUS.DONE  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMDONE2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMyFDA : 32; /*!< [31:0] 内存SSHMSTATUS.FDA  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMFDA0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMyFDA : 32; /*!< [31:0] 内存SSHMSTATUS.FDA  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMFDA1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MEMyFDA : 32; /*!< [31:0] 内存SSHMSTATUS.FDA  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MEMFDA2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EN0 : 1;	/*!< [0:0] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN1 : 1;	/*!< [1:1] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN2 : 1;	/*!< [2:2] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN3 : 1;	/*!< [3:3] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN4 : 1;	/*!< [4:4] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN5 : 1;	/*!< [5:5] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN6 : 1;	/*!< [6:6] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN7 : 1;	/*!< [7:7] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN8 : 1;	/*!< [8:8] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN9 : 1;	/*!< [9:9] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN10 : 1; /*!< [10:10] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN11 : 1; /*!< [11:11] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN12 : 1; /*!< [12:12] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN13 : 1; /*!< [13:13] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN14 : 1; /*!< [14:14] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN15 : 1; /*!< [15:15] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN16 : 1; /*!< [16:16] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN17 : 1; /*!< [17:17] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN18 : 1; /*!< [18:18] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN19 : 1; /*!< [19:19] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN20 : 1; /*!< [20:20] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN21 : 1; /*!< [21:21] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN22 : 1; /*!< [22:22] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN23 : 1; /*!< [23:23] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN24 : 1; /*!< [24:24] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN25 : 1; /*!< [25:25] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN26 : 1; /*!< [26:26] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN27 : 1; /*!< [27:27] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN28 : 1; /*!< [28:28] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN29 : 1; /*!< [29:29] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN30 : 1; /*!< [30:30] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
				__IO uint32_t EN31 : 1; /*!< [31:31] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_ACEN0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t : 32; /*!< [31:0] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_ACEN1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t ACCSPAT : 8;	/*!< [7:0] 访问图样配置；当AG_MOD选择了其他测试，这个字段直接指定位模式(即0或1)用于访问当前March元素中的每个单个地址。当AG_MOD选择了非破坏性检测，且为对应ACCSTYPE写入时，对应的ACCSPAT表示是否翻转后写回  */
				__IO uint32_t SELFASTB : 4; /*!< [11:8] 选择快速位  */
				__IO uint32_t AG_MOD : 4;	/*!< [15:12] MBIST地址生成模式  */
				__IO uint32_t ACCSTYPE : 8; /*!< [23:16] 访问类型，每个bit对应一次访问，最多8次  */
				__IO uint32_t : 4;			/*!< [27:24] 预留；读为0  */
				__IO uint32_t NUMACCS : 4;	/*!< [31:28] 每个地址访问次数；该字段指定当前March中对每个单个地址执行的访问总数。允许值:0-8(由MCFG.ACCSTYPE和MCFG.ACCSPAT字段的大小限制)。如果NUMACCS=0将不会访问内存(不进行操作，DONE保持为1)；如果NUMACCS>8，将执行8次访问。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15MCFG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t START : 1;	   /*!< [0:0] MBIST测试开始控制位；如果该位被软件置“1”，内存测试将开始；如果该位被软件复位，并且测试已经完成，MSTATUS.DONE将被置“1”。如果MCTRL.FAILDMP被置“1”，一个失败将停止当前执行。RESUME将继续暂停的测试。  */
				__IO uint32_t RESUME : 1;	   /*!< [1:1] 恢复失败的测试；当测试中的MBIST故障转储后，通过软件查询相关信息，MSTS.FDA被硬件复位后，使能该位可以继续测试，并且当测试恢复时，该位会被硬件复位  */
				__IO uint32_t ESTF : 1;		   /*!< [2:2] 使能粘滞MBIST故障位；该位使能粘滞MBIST故障状态标志位MSTS.SFAIL。如果置“1”任何MBIST故障将被收集在MSTS.SFAIL。复位该位到0也会复位MSTS.SFAIL。  */
				__IO uint32_t DIR_NC : 1;	   /*!< [3:3] 方向选择(该字段指定了内存测试操作的方向)  */
				__IO uint32_t DINIT : 1;	   /*!< [4:4] 数据初始化使能；这个位允许使用INITD数据初始化SRAM，这个初始化数据可以是存在ECC错误的数据，执行由MCTRL.START开始。对于这个预定义的操作，MCFG寄存器中包含的任何信息以及BITTOG，ROWTOG和DIR位都被忽略。  */
				__IO uint32_t RCADR : 1;	   /*!< [5:5] 快速行/快速列寻址方案选择；这个位在快速行和快速列寻址中选择。“快速行”先沿字行移动，然后按位行方向移动，“快速列”先按位行移动。  */
				__IO uint32_t ROWTOG : 1;	   /*!< [6:6] 行切换；此字段指定在行切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t BITTOG : 1;	   /*!< [7:7] 位切换；此字段指定在位切换时是否切换访问图样(0/1)，用于实现棋盘类扫描。  */
				__IO uint32_t : 1;			   /*!< [8:8] 预留；读为0  */
				__IO uint32_t FAILDMP : 1;	   /*!< [9:9] 故障位图转储；该字段使能在检测到MBIST故障后转储失败地址和失败位图。并且检测到MBIST故障发生后，内存测试随后被暂停，MSTS.FDA显示可以使用失败转储，暂停的MBIST测试由MCTRL.RESUME恢复。  */
				__IO uint32_t EN_DESCR_NC : 1; /*!< [10:10] 使能地址转换；此位仅在启用SSH本身时生效。如果这个位被设置，SSH中的地址转换将被使能。复位值为0,，因此默认情况下不使能地址转换。  */
				__IO uint32_t : 2;			   /*!< [12:11] 预留；读为0  */
				__IO uint32_t STA_POT : 2;	   /*!< [14:13] 配置扫描起始位置，同时指定了扫描方向，从起点到对角  */
				__IO uint32_t SRAM_CLR : 1;	   /*!< [15:15] 清除SRAM使能位；该位使能满足ECC的全0数据初始化SRAM，并由MCTRL.START启动。对于这个预定义的动作，MCFG，RANGE寄存器和BITTOG，ROWTOG和DIR位中包含的任何信息都被忽略。此位不能与其他初始化或测试配置一起设置。在SRAM清理完成后，软件必须在禁用SSH之前将该位复位为“0”。  */
				__IO uint32_t : 16;			   /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15MCTRL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DONE : 1;	/*!< [0:0] 完成状态标志位；该位在测试开始时被复位，并且当一个测试完成和MCTRL.START被软件复位时该位被置“1”。由于MBIST故障转储导致测试中断不会被置“1”。  */
				__I uint32_t FAIL : 1;	/*!< [1:1] MBIST故障状态标志位；该位在测试开始时被复位，并且当测试中检测到MBIST故障时会置高。  */
				__I uint32_t FDA : 1;	/*!< [2:2] MBIST故障转储状态标志位；如果使能了MCTRL.FAILDMP，则该位表示发生了故障，测试暂停，MBIST故障转储信息可用。MBIST故障位图位于ERRD(0)中，相关地址位于ETRR(0)中。如果没有发生MBIST故障，ETRR和ERRD中没有有效数据；发生MBIST故障时，由硬件自动转储，并将FDA置高。在MSTS.FDA=1时，读取MSTS和ETRR以及ERRD后，硬件重置FDA(硬件仅检查ERRD(0)的读取作为完整转储信息读取的指示)。当FDA重置后，暂停的MBIST测试可以由MCTRL.RESUME恢复，这形成了某种握手，以确保只有在实际收集到最后的MBIST故障信息时才能恢复暂停的测试(比如广播MCTRL.RESUME来恢复测试时不会恢复尚未收集MBIST故障信息的MBIST测试)。  */
				__I uint32_t SFAIL : 1; /*!< [3:3] 粘滞MBIST故障状态标志位；当MCTRL.ESTF被置“1”时，MBIST故障发生时，该位会和MSTS.FAIL一起置高，但当新的MBIST测试开始时，该位不会自动复位，实现在多次MBIST测试中收集MBIST故障信息的功能。该位会在MCTRL.ESTF复位或者禁用MBIST时自动复位。  */
				__IO uint32_t : 28;		/*!< [31:4] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15MSTS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EADDR : 16;  /*!< [15:0] 访问地址配置；当RAEN=0，该字段指定内存单次访问地址，可以对该位置进行读写操作；当RAEN=1，该字段被解释为2个不同的字段。ADDR[15:8]被解释为范围上限，ADDR[7:0]解释为范围下限。对于较少地址位的较小SRAM，保留MSB位。对这些位的写入被忽略。并读取返回“0”  */
				__IO uint32_t INJERR : 1;  /*!< [16:16] MBIST故障注入使能  */
				__IO uint32_t RAEN_NC : 1; /*!< [17:17] 范围使能  */
				__IO uint32_t : 14;		   /*!< [31:18] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RANGE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t REVID : 16; /*!< [15:0] 只读寄存器，保存ID信息  */
				__IO uint32_t : 16;		 /*!< [31:16] 预留；读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15REVID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CENE : 1;			 /*!< [0:0] ECC更正事件告警通知使能；该位允许将CE告警从SSH转发到SACU。  */
				__IO uint32_t UCENE : 1;		 /*!< [1:1] 不可更正的错误影响SRAM/SSH操作告警通知使能；该位允许将UCE告警从SSH转发到SACU。  */
				__IO uint32_t MENE : 1;			 /*!< [2:2] 杂项告警通知使能；此位允许将ME告警从SSH转发到SACU。  */
				__IO uint32_t ECE : 1;			 /*!< [3:3] 错误更正使能；通过ECC使能可以进行单个位错误的更正。如果该位为1，则通过CE告警标记错误。如果该位为0，则通过UE告警来标记单位错误。  */
				__IO uint32_t TRE : 1;			 /*!< [4:4] 错误跟踪总使能；所有错误将被跟踪，该位默认使能。  */
				__IO uint32_t BFLE_NC : 1;		 /*!< [5:5] 位翻转使能  */
				__IO uint32_t SFLE : 1;			 /*!< [6:6] 地址信号位翻转使能；如果使能了地址错误检测(ALMSRCS.ADDRE=1)并且如果这个位被置“1”并读取SRAM，则会通知地址错误，并在ETRR和ERRINFO寄存器中跟踪，如果使能的话，还会产生告警。注意，对于带有Address-ECC的SRAM，这个位被忽略，不会产生错误。  */
				__IO uint32_t : 1;				 /*!< [7:7] 预留；读为0  */
				__IO uint32_t ECCMAP_NC : 2;	 /*!< [9:8] ECC位映射模式；ECCMAP设置了三种不同的测试模型，允许分别独立地访问数据或ECC位  */
				__IO uint32_t TC_TWR_SEL_NC : 1; /*!< [10:10] TriCore塔选择，仅适用于TriCorePMEM:这个位选择一种缓存方式来进行非破坏性反转测试。这个位代表塔号。  */
				__IO uint32_t SFFD : 1;			 /*!< [11:11] 安全触发器诊断；安全触发器诊断位。使能这个位触发一个安全触发器自身测试,测试结果(例如，安全触发器的任何错误状态)可以从FAULT寄存器中的OPERR或MISCERR位获取。  */
				__IO uint32_t : 4;				 /*!< [15:12] 预留；读为0  */
				__IO uint32_t SBE : 1;			 /*!< [16:16] 单bit错误跟踪和告警使能；该位使能单bit错误的跟踪和告警功能；如果ECCS.ECE位是“1”，则单bit错误产生CE告警；否则产生UCE告警。错误状态可以从ERRINFO寄存器ERRINFO.SBERR中读取。  */
				__IO uint32_t DBE : 1;			 /*!< [17:17] 两bit错误跟踪和告警使能；该位使能两bit错误的跟踪和告警功能。如果该位为“1”，则两bit错误产生UCE告警，并且错误状态可以从ERRINFO.DBERR中读取。  */
				__IO uint32_t ADDRE : 1;		 /*!< [18:18] 地址错误跟踪和告警使能；该位使能地址错误的跟踪和告警功能。如果该位为“1”，则地址错误产生UCE告警，并且错误状态可以从ERRINFO.ADDRERR中读取。  */
				__IO uint32_t OVFE : 1;			 /*!< [19:19] ETRR溢出告警使能；该位使能可以转发ETRR溢出事件作为一个UCE告警源，错误信息可以从ECCD.VALID位和EOV位获取。  */
				__IO uint32_t OPENE : 1;		 /*!< [20:20] SSH关键错误告警使能；该位使能转发许多对SRAM或SSH操作至关重要的错误，这些错误被转发为UCE告警，错误状态可以从FAULSTS.OPERR位读取。该位默认使能  */
				__IO uint32_t MISCE : 1;		 /*!< [21:21] SSH混杂错误告警使能；该位使能转发许多可能对SRAM或SSH未来的操作至关重要的错误，这些错误被转发为ME告警，错误状态可以从FAULT.MISCERR中读取。  */
				__IO uint32_t : 10;				 /*!< [31:22] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ECCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SERR : 1;	   /*!< [0:0] 粘滞SSH错误告警；写入“0”清除粘滞状态；写入“1”无效果。在同时写入“0”和错误检测的情况下，硬件将优先设置该位，该位通过应用程序复位来复位。  */
				__IO uint32_t CERR : 1;	   /*!< [1:1] CE告警状态标志位；写入“0”清除该位，并将使能新的CE告警转发；写入“1”无效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t UCERR : 1;   /*!< [2:2] UCE告警状态标志位；写“0”将清除该位，并将使能新的UCE告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__IO uint32_t MERR : 1;	   /*!< [3:3] ME告警状态标志位；写“0”将清除该位，并将使能新的ME告警；写“1”没有效果。当该位被置“1”后，软件可以根据ETRR/ERRINFO和ECCS寄存器中的信息执行额外的诊断。该位通过应用程序复位来复位。  */
				__O uint32_t TRC : 1;	   /*!< [4:4] 跟踪寄存器清除使能；在该位处写入“1”清除ECCD.EOV&VAL、ETRR和ERRINFO寄存器，取决于PERMERR设置。该位总是读0。  */
				__I uint32_t VAL : 5;	   /*!< [9:5] 有效位；每个跟踪寄存器(ETRRx)都有一个有效的关联位。由ECCD.TRC复位。5个错误跟踪寄存器可用并且有5个有效位。这些位将一直保存到电源复位。  */
				__IO uint32_t PERMERR : 5; /*!< [14:10] 在ETRR中永久性错误标志位；表示对应的ETRR中的错误是否为永久性错误。当对应位设置为“1”时，ETRR不会被TRC清除，直到电源复位。  */
				__I uint32_t EOV : 1;	   /*!< [15:15] 错误追踪溢出状态标志位；错误跟踪寄存器有一个溢出情况，这部分保存直到热启动。  */
				__IO uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ECCD_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ETRR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ETRR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ETRR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ETRR3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EADDR : 16; /*!< [15:0] 错误(i)的地址；上次清除操作后检测到的错误地址。如果一些MSB位不需要寻址更小的内存，它们被保留并读“0”。  */
				__I uint32_t MBI : 4;	 /*!< [19:16] 内存模块错误(i)的索引；如果多个内存并行实现，这三个位包含错误内存模块的索引，以识别错误内存，并且跟踪属于该内存的地址。否则，这些位总是置“0”  */
				__IO uint32_t : 12;		 /*!< [31:20] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ETRR4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t EDATA : 32; /*!< [31:0] 错误(i)的掩码；上次清除操作后检测到的错误的掩码。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRD4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL0_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL1_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL2_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL3_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL4_A_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL0_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL1_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL2_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL3_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL4_B_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL0_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL1_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL2_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL3_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WDATA : 32; /*!< [31:0] 字数据；这个域包含了上一次内存读取操作的数据。  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15RDBFL4_C_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OPERR : 6;   /*!< [5:0] SSH关键错误状态标志位；造成UCE(Un-correctableerror)告警的每个错误源对应的位状态。由ECCS.OPENE使能。如果发生多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 2;		   /*!< [7:6] 预留读为0  */
				__IO uint32_t MISCERR : 6; /*!< [13:8] SSH混杂错误状态标志位；造成ME(Miscellaneouserror)告警的每个错误源对应的位状态。由ECCS.MISCE使能。如果发生了多个错误，对应位将被同时置“1”。写入“0”清除指定位；写“1”没有效果。  */
				__IO uint32_t : 18;		   /*!< [31:14] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15FAULT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRINFO0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRINFO1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRINFO2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRINFO3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SBERR : 1;	  /*!< [0:0] 检测到单bit错误  */
				__I uint32_t DBERR : 1;	  /*!< [1:1] 检测到两bit错误；注意带有地址ECC的SRAM，如果在地址位检测中发生错误，此位也置位  */
				__I uint32_t ADDRERR : 1; /*!< [2:2] 检测到地址错误；注意带有地址ECC的SRAM，此位不被使用。对于这样的SRAM，地址和数据位经过DBERR通知。  */
				__IO uint32_t : 29;		  /*!< [31:3] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15ERRINFO4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15IND0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15IND1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DATA : 32; /*!< [31:0] 配置用来初始化的数据  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15IND2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC0INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC1INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC2INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC3INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC4INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC5INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC6INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC7INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC8INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC9INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC10INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC11INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC12INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC13INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC14INJERR2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15INJERR0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15INJERR1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t BMASK : 32; /*!< [31:0] 配置错误注入的位掩码  */
			} bits;
			__IO uint32_t reg;
		};
	} MTU_MC15INJERR2_T;

	typedef volatile struct
	{
		/* address: 0xF0050000 */
		MTU_CLC_T MTU_CLC;

		/* address: 0xF0050004 */
		uint8_t MTU_RESERVED_F0050004[4];

		/* address: 0xF0050008 */
		MTU_ID_T MTU_ID;

		/* address: 0xF005000C */
		uint8_t MTU_RESERVED_F005000C[32];

		/* address: 0xF005002C */
		MTU_MEMTEST0_T MTU_MEMTEST0;

		/* address: 0xF0050030 */
		MTU_MEMTEST1_T MTU_MEMTEST1;

		/* address: 0xF0050034 */
		MTU_MEMTEST2_T MTU_MEMTEST2;

		/* address: 0xF0050038 */
		MTU_MEMTEST_STS0_T MTU_MEMTEST_STS0;

		/* address: 0xF005003C */
		MTU_MEMTEST_STS1_T MTU_MEMTEST_STS1;

		/* address: 0xF0050040 */
		MTU_MEMTEST_STS2_T MTU_MEMTEST_STS2;

		/* address: 0xF0050044 */
		MTU_MEMMAP_T MTU_MEMMAP;

		/* address: 0xF0050048 */
		MTU_MEMMAP_STS_T MTU_MEMMAP_STS;

		/* address: 0xF005004C */
		MTU_MEMSTAT0_T MTU_MEMSTAT0;

		/* address: 0xF0050050 */
		MTU_MEMSTAT1_T MTU_MEMSTAT1;

		/* address: 0xF0050054 */
		MTU_MEMSTAT2_T MTU_MEMSTAT2;

		/* address: 0xF0050058 */
		MTU_MEMDONE0_T MTU_MEMDONE0;

		/* address: 0xF005005C */
		MTU_MEMDONE1_T MTU_MEMDONE1;

		/* address: 0xF0050060 */
		MTU_MEMDONE2_T MTU_MEMDONE2;

		/* address: 0xF0050064 */
		MTU_MEMFDA0_T MTU_MEMFDA0;

		/* address: 0xF0050068 */
		MTU_MEMFDA1_T MTU_MEMFDA1;

		/* address: 0xF005006C */
		MTU_MEMFDA2_T MTU_MEMFDA2;

		/* address: 0xF0050070 */
		uint8_t MTU_RESERVED_F0050070[140];

		/* address: 0xF00500FC */
		MTU_ACEN0_T MTU_ACEN0;

		/* address: 0xF00500F0 */
		MTU_ACEN1_T MTU_ACEN1;

		/* address: 0xF00500F4 */
		uint8_t MTU_RESERVED_F00500F4[3852];

		/* address: 0xF0051000 */
		MTU_MC0MCFG_T MTU_MC0MCFG;

		/* address: 0xF0051004 */
		uint8_t MTU_RESERVED_F0051004[252];

		/* address: 0xF0051100 */
		MTU_MC1MCFG_T MTU_MC1MCFG;

		/* address: 0xF0051104 */
		uint8_t MTU_RESERVED_F0051104[252];

		/* address: 0xF0051200 */
		MTU_MC2MCFG_T MTU_MC2MCFG;

		/* address: 0xF0051204 */
		uint8_t MTU_RESERVED_F0051204[252];

		/* address: 0xF0051300 */
		MTU_MC3MCFG_T MTU_MC3MCFG;

		/* address: 0xF0051304 */
		uint8_t MTU_RESERVED_F0051304[252];

		/* address: 0xF0051400 */
		MTU_MC4MCFG_T MTU_MC4MCFG;

		/* address: 0xF0051404 */
		uint8_t MTU_RESERVED_F0051404[252];

		/* address: 0xF0051500 */
		MTU_MC5MCFG_T MTU_MC5MCFG;

		/* address: 0xF0051504 */
		uint8_t MTU_RESERVED_F0051504[252];

		/* address: 0xF0051600 */
		MTU_MC6MCFG_T MTU_MC6MCFG;

		/* address: 0xF0051604 */
		uint8_t MTU_RESERVED_F0051604[252];

		/* address: 0xF0051700 */
		MTU_MC7MCFG_T MTU_MC7MCFG;

		/* address: 0xF0051704 */
		uint8_t MTU_RESERVED_F0051704[252];

		/* address: 0xF0051800 */
		MTU_MC8MCFG_T MTU_MC8MCFG;

		/* address: 0xF0051804 */
		uint8_t MTU_RESERVED_F0051804[252];

		/* address: 0xF0051900 */
		MTU_MC9MCFG_T MTU_MC9MCFG;

		/* address: 0xF0051904 */
		uint8_t MTU_RESERVED_F0051904[252];

		/* address: 0xF0051A00 */
		MTU_MC10MCFG_T MTU_MC10MCFG;

		/* address: 0xF0051A04 */
		uint8_t MTU_RESERVED_F0051A04[252];

		/* address: 0xF0051B00 */
		MTU_MC11MCFG_T MTU_MC11MCFG;

		/* address: 0xF0051B04 */
		uint8_t MTU_RESERVED_F0051B04[252];

		/* address: 0xF0051C00 */
		MTU_MC12MCFG_T MTU_MC12MCFG;

		/* address: 0xF0051C04 */
		uint8_t MTU_RESERVED_F0051C04[252];

		/* address: 0xF0051D00 */
		MTU_MC13MCFG_T MTU_MC13MCFG;

		/* address: 0xF0051D04 */
		uint8_t MTU_RESERVED_F0051D04[252];

		/* address: 0xF0051E00 */
		MTU_MC14MCFG_T MTU_MC14MCFG;

		/* address: 0xF0051E04 */
		uint8_t MTU_RESERVED_F0051E04[252];

		/* address: 0xF0051F00 */
		MTU_MC15MCFG_T MTU_MC15MCFG;

		/* address: 0xF0051004 */
		MTU_MC0MCTRL_T MTU_MC0MCTRL;

		/* address: 0xF0051008 */
		uint8_t MTU_RESERVED_F0051008[252];

		/* address: 0xF0051104 */
		MTU_MC1MCTRL_T MTU_MC1MCTRL;

		/* address: 0xF0051108 */
		uint8_t MTU_RESERVED_F0051108[252];

		/* address: 0xF0051204 */
		MTU_MC2MCTRL_T MTU_MC2MCTRL;

		/* address: 0xF0051208 */
		uint8_t MTU_RESERVED_F0051208[252];

		/* address: 0xF0051304 */
		MTU_MC3MCTRL_T MTU_MC3MCTRL;

		/* address: 0xF0051308 */
		uint8_t MTU_RESERVED_F0051308[252];

		/* address: 0xF0051404 */
		MTU_MC4MCTRL_T MTU_MC4MCTRL;

		/* address: 0xF0051408 */
		uint8_t MTU_RESERVED_F0051408[252];

		/* address: 0xF0051504 */
		MTU_MC5MCTRL_T MTU_MC5MCTRL;

		/* address: 0xF0051508 */
		uint8_t MTU_RESERVED_F0051508[252];

		/* address: 0xF0051604 */
		MTU_MC6MCTRL_T MTU_MC6MCTRL;

		/* address: 0xF0051608 */
		uint8_t MTU_RESERVED_F0051608[252];

		/* address: 0xF0051704 */
		MTU_MC7MCTRL_T MTU_MC7MCTRL;

		/* address: 0xF0051708 */
		uint8_t MTU_RESERVED_F0051708[252];

		/* address: 0xF0051804 */
		MTU_MC8MCTRL_T MTU_MC8MCTRL;

		/* address: 0xF0051808 */
		uint8_t MTU_RESERVED_F0051808[252];

		/* address: 0xF0051904 */
		MTU_MC9MCTRL_T MTU_MC9MCTRL;

		/* address: 0xF0051908 */
		uint8_t MTU_RESERVED_F0051908[252];

		/* address: 0xF0051A04 */
		MTU_MC10MCTRL_T MTU_MC10MCTRL;

		/* address: 0xF0051A08 */
		uint8_t MTU_RESERVED_F0051A08[252];

		/* address: 0xF0051B04 */
		MTU_MC11MCTRL_T MTU_MC11MCTRL;

		/* address: 0xF0051B08 */
		uint8_t MTU_RESERVED_F0051B08[252];

		/* address: 0xF0051C04 */
		MTU_MC12MCTRL_T MTU_MC12MCTRL;

		/* address: 0xF0051C08 */
		uint8_t MTU_RESERVED_F0051C08[252];

		/* address: 0xF0051D04 */
		MTU_MC13MCTRL_T MTU_MC13MCTRL;

		/* address: 0xF0051D08 */
		uint8_t MTU_RESERVED_F0051D08[252];

		/* address: 0xF0051E04 */
		MTU_MC14MCTRL_T MTU_MC14MCTRL;

		/* address: 0xF0051E08 */
		uint8_t MTU_RESERVED_F0051E08[252];

		/* address: 0xF0051F04 */
		MTU_MC15MCTRL_T MTU_MC15MCTRL;

		/* address: 0xF0051008 */
		MTU_MC0MSTS_T MTU_MC0MSTS;

		/* address: 0xF005100C */
		uint8_t MTU_RESERVED_F005100C[252];

		/* address: 0xF0051108 */
		MTU_MC1MSTS_T MTU_MC1MSTS;

		/* address: 0xF005110C */
		uint8_t MTU_RESERVED_F005110C[252];

		/* address: 0xF0051208 */
		MTU_MC2MSTS_T MTU_MC2MSTS;

		/* address: 0xF005120C */
		uint8_t MTU_RESERVED_F005120C[252];

		/* address: 0xF0051308 */
		MTU_MC3MSTS_T MTU_MC3MSTS;

		/* address: 0xF005130C */
		uint8_t MTU_RESERVED_F005130C[252];

		/* address: 0xF0051408 */
		MTU_MC4MSTS_T MTU_MC4MSTS;

		/* address: 0xF005140C */
		uint8_t MTU_RESERVED_F005140C[252];

		/* address: 0xF0051508 */
		MTU_MC5MSTS_T MTU_MC5MSTS;

		/* address: 0xF005150C */
		uint8_t MTU_RESERVED_F005150C[252];

		/* address: 0xF0051608 */
		MTU_MC6MSTS_T MTU_MC6MSTS;

		/* address: 0xF005160C */
		uint8_t MTU_RESERVED_F005160C[252];

		/* address: 0xF0051708 */
		MTU_MC7MSTS_T MTU_MC7MSTS;

		/* address: 0xF005170C */
		uint8_t MTU_RESERVED_F005170C[252];

		/* address: 0xF0051808 */
		MTU_MC8MSTS_T MTU_MC8MSTS;

		/* address: 0xF005180C */
		uint8_t MTU_RESERVED_F005180C[252];

		/* address: 0xF0051908 */
		MTU_MC9MSTS_T MTU_MC9MSTS;

		/* address: 0xF005190C */
		uint8_t MTU_RESERVED_F005190C[252];

		/* address: 0xF0051A08 */
		MTU_MC10MSTS_T MTU_MC10MSTS;

		/* address: 0xF0051A0C */
		uint8_t MTU_RESERVED_F0051A0C[252];

		/* address: 0xF0051B08 */
		MTU_MC11MSTS_T MTU_MC11MSTS;

		/* address: 0xF0051B0C */
		uint8_t MTU_RESERVED_F0051B0C[252];

		/* address: 0xF0051C08 */
		MTU_MC12MSTS_T MTU_MC12MSTS;

		/* address: 0xF0051C0C */
		uint8_t MTU_RESERVED_F0051C0C[252];

		/* address: 0xF0051D08 */
		MTU_MC13MSTS_T MTU_MC13MSTS;

		/* address: 0xF0051D0C */
		uint8_t MTU_RESERVED_F0051D0C[252];

		/* address: 0xF0051E08 */
		MTU_MC14MSTS_T MTU_MC14MSTS;

		/* address: 0xF0051E0C */
		uint8_t MTU_RESERVED_F0051E0C[252];

		/* address: 0xF0051F08 */
		MTU_MC15MSTS_T MTU_MC15MSTS;

		/* address: 0xF005100C */
		MTU_MC0RANGE_T MTU_MC0RANGE;

		/* address: 0xF0051010 */
		uint8_t MTU_RESERVED_F0051010[252];

		/* address: 0xF005110C */
		MTU_MC1RANGE_T MTU_MC1RANGE;

		/* address: 0xF0051110 */
		uint8_t MTU_RESERVED_F0051110[252];

		/* address: 0xF005120C */
		MTU_MC2RANGE_T MTU_MC2RANGE;

		/* address: 0xF0051210 */
		uint8_t MTU_RESERVED_F0051210[252];

		/* address: 0xF005130C */
		MTU_MC3RANGE_T MTU_MC3RANGE;

		/* address: 0xF0051310 */
		uint8_t MTU_RESERVED_F0051310[252];

		/* address: 0xF005140C */
		MTU_MC4RANGE_T MTU_MC4RANGE;

		/* address: 0xF0051410 */
		uint8_t MTU_RESERVED_F0051410[252];

		/* address: 0xF005150C */
		MTU_MC5RANGE_T MTU_MC5RANGE;

		/* address: 0xF0051510 */
		uint8_t MTU_RESERVED_F0051510[252];

		/* address: 0xF005160C */
		MTU_MC6RANGE_T MTU_MC6RANGE;

		/* address: 0xF0051610 */
		uint8_t MTU_RESERVED_F0051610[252];

		/* address: 0xF005170C */
		MTU_MC7RANGE_T MTU_MC7RANGE;

		/* address: 0xF0051710 */
		uint8_t MTU_RESERVED_F0051710[252];

		/* address: 0xF005180C */
		MTU_MC8RANGE_T MTU_MC8RANGE;

		/* address: 0xF0051810 */
		uint8_t MTU_RESERVED_F0051810[252];

		/* address: 0xF005190C */
		MTU_MC9RANGE_T MTU_MC9RANGE;

		/* address: 0xF0051910 */
		uint8_t MTU_RESERVED_F0051910[252];

		/* address: 0xF0051A0C */
		MTU_MC10RANGE_T MTU_MC10RANGE;

		/* address: 0xF0051A10 */
		uint8_t MTU_RESERVED_F0051A10[252];

		/* address: 0xF0051B0C */
		MTU_MC11RANGE_T MTU_MC11RANGE;

		/* address: 0xF0051B10 */
		uint8_t MTU_RESERVED_F0051B10[252];

		/* address: 0xF0051C0C */
		MTU_MC12RANGE_T MTU_MC12RANGE;

		/* address: 0xF0051C10 */
		uint8_t MTU_RESERVED_F0051C10[252];

		/* address: 0xF0051D0C */
		MTU_MC13RANGE_T MTU_MC13RANGE;

		/* address: 0xF0051D10 */
		uint8_t MTU_RESERVED_F0051D10[252];

		/* address: 0xF0051E0C */
		MTU_MC14RANGE_T MTU_MC14RANGE;

		/* address: 0xF0051E10 */
		uint8_t MTU_RESERVED_F0051E10[252];

		/* address: 0xF0051F0C */
		MTU_MC15RANGE_T MTU_MC15RANGE;

		/* address: 0xF0051010 */
		MTU_MC0REVID_T MTU_MC0REVID;

		/* address: 0xF0051014 */
		uint8_t MTU_RESERVED_F0051014[252];

		/* address: 0xF0051110 */
		MTU_MC1REVID_T MTU_MC1REVID;

		/* address: 0xF0051114 */
		uint8_t MTU_RESERVED_F0051114[252];

		/* address: 0xF0051210 */
		MTU_MC2REVID_T MTU_MC2REVID;

		/* address: 0xF0051214 */
		uint8_t MTU_RESERVED_F0051214[252];

		/* address: 0xF0051310 */
		MTU_MC3REVID_T MTU_MC3REVID;

		/* address: 0xF0051314 */
		uint8_t MTU_RESERVED_F0051314[252];

		/* address: 0xF0051410 */
		MTU_MC4REVID_T MTU_MC4REVID;

		/* address: 0xF0051414 */
		uint8_t MTU_RESERVED_F0051414[252];

		/* address: 0xF0051510 */
		MTU_MC5REVID_T MTU_MC5REVID;

		/* address: 0xF0051514 */
		uint8_t MTU_RESERVED_F0051514[252];

		/* address: 0xF0051610 */
		MTU_MC6REVID_T MTU_MC6REVID;

		/* address: 0xF0051614 */
		uint8_t MTU_RESERVED_F0051614[252];

		/* address: 0xF0051710 */
		MTU_MC7REVID_T MTU_MC7REVID;

		/* address: 0xF0051714 */
		uint8_t MTU_RESERVED_F0051714[252];

		/* address: 0xF0051810 */
		MTU_MC8REVID_T MTU_MC8REVID;

		/* address: 0xF0051814 */
		uint8_t MTU_RESERVED_F0051814[252];

		/* address: 0xF0051910 */
		MTU_MC9REVID_T MTU_MC9REVID;

		/* address: 0xF0051914 */
		uint8_t MTU_RESERVED_F0051914[252];

		/* address: 0xF0051A10 */
		MTU_MC10REVID_T MTU_MC10REVID;

		/* address: 0xF0051A14 */
		uint8_t MTU_RESERVED_F0051A14[252];

		/* address: 0xF0051B10 */
		MTU_MC11REVID_T MTU_MC11REVID;

		/* address: 0xF0051B14 */
		uint8_t MTU_RESERVED_F0051B14[252];

		/* address: 0xF0051C10 */
		MTU_MC12REVID_T MTU_MC12REVID;

		/* address: 0xF0051C14 */
		uint8_t MTU_RESERVED_F0051C14[252];

		/* address: 0xF0051D10 */
		MTU_MC13REVID_T MTU_MC13REVID;

		/* address: 0xF0051D14 */
		uint8_t MTU_RESERVED_F0051D14[252];

		/* address: 0xF0051E10 */
		MTU_MC14REVID_T MTU_MC14REVID;

		/* address: 0xF0051E14 */
		uint8_t MTU_RESERVED_F0051E14[252];

		/* address: 0xF0051F10 */
		MTU_MC15REVID_T MTU_MC15REVID;

		/* address: 0xF0051014 */
		MTU_MC0ECCS_T MTU_MC0ECCS;

		/* address: 0xF0051018 */
		uint8_t MTU_RESERVED_F0051018[252];

		/* address: 0xF0051114 */
		MTU_MC1ECCS_T MTU_MC1ECCS;

		/* address: 0xF0051118 */
		uint8_t MTU_RESERVED_F0051118[252];

		/* address: 0xF0051214 */
		MTU_MC2ECCS_T MTU_MC2ECCS;

		/* address: 0xF0051218 */
		uint8_t MTU_RESERVED_F0051218[252];

		/* address: 0xF0051314 */
		MTU_MC3ECCS_T MTU_MC3ECCS;

		/* address: 0xF0051318 */
		uint8_t MTU_RESERVED_F0051318[252];

		/* address: 0xF0051414 */
		MTU_MC4ECCS_T MTU_MC4ECCS;

		/* address: 0xF0051418 */
		uint8_t MTU_RESERVED_F0051418[252];

		/* address: 0xF0051514 */
		MTU_MC5ECCS_T MTU_MC5ECCS;

		/* address: 0xF0051518 */
		uint8_t MTU_RESERVED_F0051518[252];

		/* address: 0xF0051614 */
		MTU_MC6ECCS_T MTU_MC6ECCS;

		/* address: 0xF0051618 */
		uint8_t MTU_RESERVED_F0051618[252];

		/* address: 0xF0051714 */
		MTU_MC7ECCS_T MTU_MC7ECCS;

		/* address: 0xF0051718 */
		uint8_t MTU_RESERVED_F0051718[252];

		/* address: 0xF0051814 */
		MTU_MC8ECCS_T MTU_MC8ECCS;

		/* address: 0xF0051818 */
		uint8_t MTU_RESERVED_F0051818[252];

		/* address: 0xF0051914 */
		MTU_MC9ECCS_T MTU_MC9ECCS;

		/* address: 0xF0051918 */
		uint8_t MTU_RESERVED_F0051918[252];

		/* address: 0xF0051A14 */
		MTU_MC10ECCS_T MTU_MC10ECCS;

		/* address: 0xF0051A18 */
		uint8_t MTU_RESERVED_F0051A18[252];

		/* address: 0xF0051B14 */
		MTU_MC11ECCS_T MTU_MC11ECCS;

		/* address: 0xF0051B18 */
		uint8_t MTU_RESERVED_F0051B18[252];

		/* address: 0xF0051C14 */
		MTU_MC12ECCS_T MTU_MC12ECCS;

		/* address: 0xF0051C18 */
		uint8_t MTU_RESERVED_F0051C18[252];

		/* address: 0xF0051D14 */
		MTU_MC13ECCS_T MTU_MC13ECCS;

		/* address: 0xF0051D18 */
		uint8_t MTU_RESERVED_F0051D18[252];

		/* address: 0xF0051E14 */
		MTU_MC14ECCS_T MTU_MC14ECCS;

		/* address: 0xF0051E18 */
		uint8_t MTU_RESERVED_F0051E18[252];

		/* address: 0xF0051F14 */
		MTU_MC15ECCS_T MTU_MC15ECCS;

		/* address: 0xF0051018 */
		MTU_MC0ECCD_T MTU_MC0ECCD;

		/* address: 0xF005101C */
		uint8_t MTU_RESERVED_F005101C[252];

		/* address: 0xF0051118 */
		MTU_MC1ECCD_T MTU_MC1ECCD;

		/* address: 0xF005111C */
		uint8_t MTU_RESERVED_F005111C[252];

		/* address: 0xF0051218 */
		MTU_MC2ECCD_T MTU_MC2ECCD;

		/* address: 0xF005121C */
		uint8_t MTU_RESERVED_F005121C[252];

		/* address: 0xF0051318 */
		MTU_MC3ECCD_T MTU_MC3ECCD;

		/* address: 0xF005131C */
		uint8_t MTU_RESERVED_F005131C[252];

		/* address: 0xF0051418 */
		MTU_MC4ECCD_T MTU_MC4ECCD;

		/* address: 0xF005141C */
		uint8_t MTU_RESERVED_F005141C[252];

		/* address: 0xF0051518 */
		MTU_MC5ECCD_T MTU_MC5ECCD;

		/* address: 0xF005151C */
		uint8_t MTU_RESERVED_F005151C[252];

		/* address: 0xF0051618 */
		MTU_MC6ECCD_T MTU_MC6ECCD;

		/* address: 0xF005161C */
		uint8_t MTU_RESERVED_F005161C[252];

		/* address: 0xF0051718 */
		MTU_MC7ECCD_T MTU_MC7ECCD;

		/* address: 0xF005171C */
		uint8_t MTU_RESERVED_F005171C[252];

		/* address: 0xF0051818 */
		MTU_MC8ECCD_T MTU_MC8ECCD;

		/* address: 0xF005181C */
		uint8_t MTU_RESERVED_F005181C[252];

		/* address: 0xF0051918 */
		MTU_MC9ECCD_T MTU_MC9ECCD;

		/* address: 0xF005191C */
		uint8_t MTU_RESERVED_F005191C[252];

		/* address: 0xF0051A18 */
		MTU_MC10ECCD_T MTU_MC10ECCD;

		/* address: 0xF0051A1C */
		uint8_t MTU_RESERVED_F0051A1C[252];

		/* address: 0xF0051B18 */
		MTU_MC11ECCD_T MTU_MC11ECCD;

		/* address: 0xF0051B1C */
		uint8_t MTU_RESERVED_F0051B1C[252];

		/* address: 0xF0051C18 */
		MTU_MC12ECCD_T MTU_MC12ECCD;

		/* address: 0xF0051C1C */
		uint8_t MTU_RESERVED_F0051C1C[252];

		/* address: 0xF0051D18 */
		MTU_MC13ECCD_T MTU_MC13ECCD;

		/* address: 0xF0051D1C */
		uint8_t MTU_RESERVED_F0051D1C[252];

		/* address: 0xF0051E18 */
		MTU_MC14ECCD_T MTU_MC14ECCD;

		/* address: 0xF0051E1C */
		uint8_t MTU_RESERVED_F0051E1C[252];

		/* address: 0xF0051F18 */
		MTU_MC15ECCD_T MTU_MC15ECCD;

		/* address: 0xF005101C */
		MTU_MC0ETRR0_T MTU_MC0ETRR0;

		/* address: 0xF0051020 */
		MTU_MC0ETRR1_T MTU_MC0ETRR1;

		/* address: 0xF0051024 */
		MTU_MC0ETRR2_T MTU_MC0ETRR2;

		/* address: 0xF0051028 */
		MTU_MC0ETRR3_T MTU_MC0ETRR3;

		/* address: 0xF005102C */
		MTU_MC0ETRR4_T MTU_MC0ETRR4;

		/* address: 0xF0051030 */
		uint8_t MTU_RESERVED_F0051030[80];

		/* address: 0xF0051080 */
		MTU_MC1ETRR0_T MTU_MC1ETRR0;

		/* address: 0xF0051084 */
		MTU_MC1ETRR1_T MTU_MC1ETRR1;

		/* address: 0xF0051088 */
		MTU_MC1ETRR2_T MTU_MC1ETRR2;

		/* address: 0xF005108C */
		MTU_MC1ETRR3_T MTU_MC1ETRR3;

		/* address: 0xF0051090 */
		MTU_MC1ETRR4_T MTU_MC1ETRR4;

		/* address: 0xF0051094 */
		uint8_t MTU_RESERVED_F0051094[80];

		/* address: 0xF00510E4 */
		MTU_MC2ETRR0_T MTU_MC2ETRR0;

		/* address: 0xF00510E8 */
		MTU_MC2ETRR1_T MTU_MC2ETRR1;

		/* address: 0xF00510EC */
		MTU_MC2ETRR2_T MTU_MC2ETRR2;

		/* address: 0xF00510F0 */
		MTU_MC2ETRR3_T MTU_MC2ETRR3;

		/* address: 0xF00510F4 */
		MTU_MC2ETRR4_T MTU_MC2ETRR4;

		/* address: 0xF00510F8 */
		uint8_t MTU_RESERVED_F00510F8[80];

		/* address: 0xF0051148 */
		MTU_MC3ETRR0_T MTU_MC3ETRR0;

		/* address: 0xF005114C */
		MTU_MC3ETRR1_T MTU_MC3ETRR1;

		/* address: 0xF0051150 */
		MTU_MC3ETRR2_T MTU_MC3ETRR2;

		/* address: 0xF0051154 */
		MTU_MC3ETRR3_T MTU_MC3ETRR3;

		/* address: 0xF0051158 */
		MTU_MC3ETRR4_T MTU_MC3ETRR4;

		/* address: 0xF005115C */
		uint8_t MTU_RESERVED_F005115C[80];

		/* address: 0xF00511AC */
		MTU_MC4ETRR0_T MTU_MC4ETRR0;

		/* address: 0xF00511B0 */
		MTU_MC4ETRR1_T MTU_MC4ETRR1;

		/* address: 0xF00511B4 */
		MTU_MC4ETRR2_T MTU_MC4ETRR2;

		/* address: 0xF00511B8 */
		MTU_MC4ETRR3_T MTU_MC4ETRR3;

		/* address: 0xF00511BC */
		MTU_MC4ETRR4_T MTU_MC4ETRR4;

		/* address: 0xF00511C0 */
		uint8_t MTU_RESERVED_F00511C0[80];

		/* address: 0xF0051210 */
		MTU_MC5ETRR0_T MTU_MC5ETRR0;

		/* address: 0xF0051214 */
		MTU_MC5ETRR1_T MTU_MC5ETRR1;

		/* address: 0xF0051218 */
		MTU_MC5ETRR2_T MTU_MC5ETRR2;

		/* address: 0xF005121C */
		MTU_MC5ETRR3_T MTU_MC5ETRR3;

		/* address: 0xF0051220 */
		MTU_MC5ETRR4_T MTU_MC5ETRR4;

		/* address: 0xF0051224 */
		uint8_t MTU_RESERVED_F0051224[80];

		/* address: 0xF0051274 */
		MTU_MC6ETRR0_T MTU_MC6ETRR0;

		/* address: 0xF0051278 */
		MTU_MC6ETRR1_T MTU_MC6ETRR1;

		/* address: 0xF005127C */
		MTU_MC6ETRR2_T MTU_MC6ETRR2;

		/* address: 0xF0051280 */
		MTU_MC6ETRR3_T MTU_MC6ETRR3;

		/* address: 0xF0051284 */
		MTU_MC6ETRR4_T MTU_MC6ETRR4;

		/* address: 0xF0051288 */
		uint8_t MTU_RESERVED_F0051288[80];

		/* address: 0xF00512D8 */
		MTU_MC7ETRR0_T MTU_MC7ETRR0;

		/* address: 0xF00512DC */
		MTU_MC7ETRR1_T MTU_MC7ETRR1;

		/* address: 0xF00512E0 */
		MTU_MC7ETRR2_T MTU_MC7ETRR2;

		/* address: 0xF00512E4 */
		MTU_MC7ETRR3_T MTU_MC7ETRR3;

		/* address: 0xF00512E8 */
		MTU_MC7ETRR4_T MTU_MC7ETRR4;

		/* address: 0xF00512EC */
		uint8_t MTU_RESERVED_F00512EC[80];

		/* address: 0xF005133C */
		MTU_MC8ETRR0_T MTU_MC8ETRR0;

		/* address: 0xF0051340 */
		MTU_MC8ETRR1_T MTU_MC8ETRR1;

		/* address: 0xF0051344 */
		MTU_MC8ETRR2_T MTU_MC8ETRR2;

		/* address: 0xF0051348 */
		MTU_MC8ETRR3_T MTU_MC8ETRR3;

		/* address: 0xF005134C */
		MTU_MC8ETRR4_T MTU_MC8ETRR4;

		/* address: 0xF0051350 */
		uint8_t MTU_RESERVED_F0051350[80];

		/* address: 0xF00513A0 */
		MTU_MC9ETRR0_T MTU_MC9ETRR0;

		/* address: 0xF00513A4 */
		MTU_MC9ETRR1_T MTU_MC9ETRR1;

		/* address: 0xF00513A8 */
		MTU_MC9ETRR2_T MTU_MC9ETRR2;

		/* address: 0xF00513AC */
		MTU_MC9ETRR3_T MTU_MC9ETRR3;

		/* address: 0xF00513B0 */
		MTU_MC9ETRR4_T MTU_MC9ETRR4;

		/* address: 0xF00513B4 */
		uint8_t MTU_RESERVED_F00513B4[80];

		/* address: 0xF0051404 */
		MTU_MC10ETRR0_T MTU_MC10ETRR0;

		/* address: 0xF0051408 */
		MTU_MC10ETRR1_T MTU_MC10ETRR1;

		/* address: 0xF005140C */
		MTU_MC10ETRR2_T MTU_MC10ETRR2;

		/* address: 0xF0051410 */
		MTU_MC10ETRR3_T MTU_MC10ETRR3;

		/* address: 0xF0051414 */
		MTU_MC10ETRR4_T MTU_MC10ETRR4;

		/* address: 0xF0051418 */
		uint8_t MTU_RESERVED_F0051418[80];

		/* address: 0xF0051468 */
		MTU_MC11ETRR0_T MTU_MC11ETRR0;

		/* address: 0xF005146C */
		MTU_MC11ETRR1_T MTU_MC11ETRR1;

		/* address: 0xF0051470 */
		MTU_MC11ETRR2_T MTU_MC11ETRR2;

		/* address: 0xF0051474 */
		MTU_MC11ETRR3_T MTU_MC11ETRR3;

		/* address: 0xF0051478 */
		MTU_MC11ETRR4_T MTU_MC11ETRR4;

		/* address: 0xF005147C */
		uint8_t MTU_RESERVED_F005147C[80];

		/* address: 0xF00514CC */
		MTU_MC12ETRR0_T MTU_MC12ETRR0;

		/* address: 0xF00514D0 */
		MTU_MC12ETRR1_T MTU_MC12ETRR1;

		/* address: 0xF00514D4 */
		MTU_MC12ETRR2_T MTU_MC12ETRR2;

		/* address: 0xF00514D8 */
		MTU_MC12ETRR3_T MTU_MC12ETRR3;

		/* address: 0xF00514DC */
		MTU_MC12ETRR4_T MTU_MC12ETRR4;

		/* address: 0xF00514E0 */
		uint8_t MTU_RESERVED_F00514E0[80];

		/* address: 0xF0051530 */
		MTU_MC13ETRR0_T MTU_MC13ETRR0;

		/* address: 0xF0051534 */
		MTU_MC13ETRR1_T MTU_MC13ETRR1;

		/* address: 0xF0051538 */
		MTU_MC13ETRR2_T MTU_MC13ETRR2;

		/* address: 0xF005153C */
		MTU_MC13ETRR3_T MTU_MC13ETRR3;

		/* address: 0xF0051540 */
		MTU_MC13ETRR4_T MTU_MC13ETRR4;

		/* address: 0xF0051544 */
		uint8_t MTU_RESERVED_F0051544[80];

		/* address: 0xF0051594 */
		MTU_MC14ETRR0_T MTU_MC14ETRR0;

		/* address: 0xF0051598 */
		MTU_MC14ETRR1_T MTU_MC14ETRR1;

		/* address: 0xF005159C */
		MTU_MC14ETRR2_T MTU_MC14ETRR2;

		/* address: 0xF00515A0 */
		MTU_MC14ETRR3_T MTU_MC14ETRR3;

		/* address: 0xF00515A4 */
		MTU_MC14ETRR4_T MTU_MC14ETRR4;

		/* address: 0xF00515A8 */
		uint8_t MTU_RESERVED_F00515A8[80];

		/* address: 0xF00515F8 */
		MTU_MC15ETRR0_T MTU_MC15ETRR0;

		/* address: 0xF00515FC */
		MTU_MC15ETRR1_T MTU_MC15ETRR1;

		/* address: 0xF0051600 */
		MTU_MC15ETRR2_T MTU_MC15ETRR2;

		/* address: 0xF0051604 */
		MTU_MC15ETRR3_T MTU_MC15ETRR3;

		/* address: 0xF0051608 */
		MTU_MC15ETRR4_T MTU_MC15ETRR4;

		/* address: 0xF0051030 */
		MTU_MC0ERRD0_A_T MTU_MC0ERRD0_A;

		/* address: 0xF0051034 */
		MTU_MC0ERRD1_A_T MTU_MC0ERRD1_A;

		/* address: 0xF0051038 */
		MTU_MC0ERRD2_A_T MTU_MC0ERRD2_A;

		/* address: 0xF005103C */
		MTU_MC0ERRD3_A_T MTU_MC0ERRD3_A;

		/* address: 0xF0051040 */
		MTU_MC0ERRD4_A_T MTU_MC0ERRD4_A;

		/* address: 0xF0051044 */
		uint8_t MTU_RESERVED_F0051044[80];

		/* address: 0xF0051094 */
		MTU_MC1ERRD0_A_T MTU_MC1ERRD0_A;

		/* address: 0xF0051098 */
		MTU_MC1ERRD1_A_T MTU_MC1ERRD1_A;

		/* address: 0xF005109C */
		MTU_MC1ERRD2_A_T MTU_MC1ERRD2_A;

		/* address: 0xF00510A0 */
		MTU_MC1ERRD3_A_T MTU_MC1ERRD3_A;

		/* address: 0xF00510A4 */
		MTU_MC1ERRD4_A_T MTU_MC1ERRD4_A;

		/* address: 0xF00510A8 */
		uint8_t MTU_RESERVED_F00510A8[80];

		/* address: 0xF00510F8 */
		MTU_MC2ERRD0_A_T MTU_MC2ERRD0_A;

		/* address: 0xF00510FC */
		MTU_MC2ERRD1_A_T MTU_MC2ERRD1_A;

		/* address: 0xF0051100 */
		MTU_MC2ERRD2_A_T MTU_MC2ERRD2_A;

		/* address: 0xF0051104 */
		MTU_MC2ERRD3_A_T MTU_MC2ERRD3_A;

		/* address: 0xF0051108 */
		MTU_MC2ERRD4_A_T MTU_MC2ERRD4_A;

		/* address: 0xF005110C */
		uint8_t MTU_RESERVED_F005110C[80];

		/* address: 0xF005115C */
		MTU_MC3ERRD0_A_T MTU_MC3ERRD0_A;

		/* address: 0xF0051160 */
		MTU_MC3ERRD1_A_T MTU_MC3ERRD1_A;

		/* address: 0xF0051164 */
		MTU_MC3ERRD2_A_T MTU_MC3ERRD2_A;

		/* address: 0xF0051168 */
		MTU_MC3ERRD3_A_T MTU_MC3ERRD3_A;

		/* address: 0xF005116C */
		MTU_MC3ERRD4_A_T MTU_MC3ERRD4_A;

		/* address: 0xF0051170 */
		uint8_t MTU_RESERVED_F0051170[80];

		/* address: 0xF00511C0 */
		MTU_MC4ERRD0_A_T MTU_MC4ERRD0_A;

		/* address: 0xF00511C4 */
		MTU_MC4ERRD1_A_T MTU_MC4ERRD1_A;

		/* address: 0xF00511C8 */
		MTU_MC4ERRD2_A_T MTU_MC4ERRD2_A;

		/* address: 0xF00511CC */
		MTU_MC4ERRD3_A_T MTU_MC4ERRD3_A;

		/* address: 0xF00511D0 */
		MTU_MC4ERRD4_A_T MTU_MC4ERRD4_A;

		/* address: 0xF00511D4 */
		uint8_t MTU_RESERVED_F00511D4[80];

		/* address: 0xF0051224 */
		MTU_MC5ERRD0_A_T MTU_MC5ERRD0_A;

		/* address: 0xF0051228 */
		MTU_MC5ERRD1_A_T MTU_MC5ERRD1_A;

		/* address: 0xF005122C */
		MTU_MC5ERRD2_A_T MTU_MC5ERRD2_A;

		/* address: 0xF0051230 */
		MTU_MC5ERRD3_A_T MTU_MC5ERRD3_A;

		/* address: 0xF0051234 */
		MTU_MC5ERRD4_A_T MTU_MC5ERRD4_A;

		/* address: 0xF0051238 */
		uint8_t MTU_RESERVED_F0051238[80];

		/* address: 0xF0051288 */
		MTU_MC6ERRD0_A_T MTU_MC6ERRD0_A;

		/* address: 0xF005128C */
		MTU_MC6ERRD1_A_T MTU_MC6ERRD1_A;

		/* address: 0xF0051290 */
		MTU_MC6ERRD2_A_T MTU_MC6ERRD2_A;

		/* address: 0xF0051294 */
		MTU_MC6ERRD3_A_T MTU_MC6ERRD3_A;

		/* address: 0xF0051298 */
		MTU_MC6ERRD4_A_T MTU_MC6ERRD4_A;

		/* address: 0xF005129C */
		uint8_t MTU_RESERVED_F005129C[80];

		/* address: 0xF00512EC */
		MTU_MC7ERRD0_A_T MTU_MC7ERRD0_A;

		/* address: 0xF00512F0 */
		MTU_MC7ERRD1_A_T MTU_MC7ERRD1_A;

		/* address: 0xF00512F4 */
		MTU_MC7ERRD2_A_T MTU_MC7ERRD2_A;

		/* address: 0xF00512F8 */
		MTU_MC7ERRD3_A_T MTU_MC7ERRD3_A;

		/* address: 0xF00512FC */
		MTU_MC7ERRD4_A_T MTU_MC7ERRD4_A;

		/* address: 0xF0051300 */
		uint8_t MTU_RESERVED_F0051300[80];

		/* address: 0xF0051350 */
		MTU_MC8ERRD0_A_T MTU_MC8ERRD0_A;

		/* address: 0xF0051354 */
		MTU_MC8ERRD1_A_T MTU_MC8ERRD1_A;

		/* address: 0xF0051358 */
		MTU_MC8ERRD2_A_T MTU_MC8ERRD2_A;

		/* address: 0xF005135C */
		MTU_MC8ERRD3_A_T MTU_MC8ERRD3_A;

		/* address: 0xF0051360 */
		MTU_MC8ERRD4_A_T MTU_MC8ERRD4_A;

		/* address: 0xF0051364 */
		uint8_t MTU_RESERVED_F0051364[80];

		/* address: 0xF00513B4 */
		MTU_MC9ERRD0_A_T MTU_MC9ERRD0_A;

		/* address: 0xF00513B8 */
		MTU_MC9ERRD1_A_T MTU_MC9ERRD1_A;

		/* address: 0xF00513BC */
		MTU_MC9ERRD2_A_T MTU_MC9ERRD2_A;

		/* address: 0xF00513C0 */
		MTU_MC9ERRD3_A_T MTU_MC9ERRD3_A;

		/* address: 0xF00513C4 */
		MTU_MC9ERRD4_A_T MTU_MC9ERRD4_A;

		/* address: 0xF00513C8 */
		uint8_t MTU_RESERVED_F00513C8[80];

		/* address: 0xF0051418 */
		MTU_MC10ERRD0_A_T MTU_MC10ERRD0_A;

		/* address: 0xF005141C */
		MTU_MC10ERRD1_A_T MTU_MC10ERRD1_A;

		/* address: 0xF0051420 */
		MTU_MC10ERRD2_A_T MTU_MC10ERRD2_A;

		/* address: 0xF0051424 */
		MTU_MC10ERRD3_A_T MTU_MC10ERRD3_A;

		/* address: 0xF0051428 */
		MTU_MC10ERRD4_A_T MTU_MC10ERRD4_A;

		/* address: 0xF005142C */
		uint8_t MTU_RESERVED_F005142C[80];

		/* address: 0xF005147C */
		MTU_MC11ERRD0_A_T MTU_MC11ERRD0_A;

		/* address: 0xF0051480 */
		MTU_MC11ERRD1_A_T MTU_MC11ERRD1_A;

		/* address: 0xF0051484 */
		MTU_MC11ERRD2_A_T MTU_MC11ERRD2_A;

		/* address: 0xF0051488 */
		MTU_MC11ERRD3_A_T MTU_MC11ERRD3_A;

		/* address: 0xF005148C */
		MTU_MC11ERRD4_A_T MTU_MC11ERRD4_A;

		/* address: 0xF0051490 */
		uint8_t MTU_RESERVED_F0051490[80];

		/* address: 0xF00514E0 */
		MTU_MC12ERRD0_A_T MTU_MC12ERRD0_A;

		/* address: 0xF00514E4 */
		MTU_MC12ERRD1_A_T MTU_MC12ERRD1_A;

		/* address: 0xF00514E8 */
		MTU_MC12ERRD2_A_T MTU_MC12ERRD2_A;

		/* address: 0xF00514EC */
		MTU_MC12ERRD3_A_T MTU_MC12ERRD3_A;

		/* address: 0xF00514F0 */
		MTU_MC12ERRD4_A_T MTU_MC12ERRD4_A;

		/* address: 0xF00514F4 */
		uint8_t MTU_RESERVED_F00514F4[80];

		/* address: 0xF0051544 */
		MTU_MC13ERRD0_A_T MTU_MC13ERRD0_A;

		/* address: 0xF0051548 */
		MTU_MC13ERRD1_A_T MTU_MC13ERRD1_A;

		/* address: 0xF005154C */
		MTU_MC13ERRD2_A_T MTU_MC13ERRD2_A;

		/* address: 0xF0051550 */
		MTU_MC13ERRD3_A_T MTU_MC13ERRD3_A;

		/* address: 0xF0051554 */
		MTU_MC13ERRD4_A_T MTU_MC13ERRD4_A;

		/* address: 0xF0051558 */
		uint8_t MTU_RESERVED_F0051558[80];

		/* address: 0xF00515A8 */
		MTU_MC14ERRD0_A_T MTU_MC14ERRD0_A;

		/* address: 0xF00515AC */
		MTU_MC14ERRD1_A_T MTU_MC14ERRD1_A;

		/* address: 0xF00515B0 */
		MTU_MC14ERRD2_A_T MTU_MC14ERRD2_A;

		/* address: 0xF00515B4 */
		MTU_MC14ERRD3_A_T MTU_MC14ERRD3_A;

		/* address: 0xF00515B8 */
		MTU_MC14ERRD4_A_T MTU_MC14ERRD4_A;

		/* address: 0xF00515BC */
		uint8_t MTU_RESERVED_F00515BC[80];

		/* address: 0xF005160C */
		MTU_MC15ERRD0_A_T MTU_MC15ERRD0_A;

		/* address: 0xF0051610 */
		MTU_MC15ERRD1_A_T MTU_MC15ERRD1_A;

		/* address: 0xF0051614 */
		MTU_MC15ERRD2_A_T MTU_MC15ERRD2_A;

		/* address: 0xF0051618 */
		MTU_MC15ERRD3_A_T MTU_MC15ERRD3_A;

		/* address: 0xF005161C */
		MTU_MC15ERRD4_A_T MTU_MC15ERRD4_A;

		/* address: 0xF0051044 */
		MTU_MC0ERRD0_B_T MTU_MC0ERRD0_B;

		/* address: 0xF0051048 */
		MTU_MC0ERRD1_B_T MTU_MC0ERRD1_B;

		/* address: 0xF005104C */
		MTU_MC0ERRD2_B_T MTU_MC0ERRD2_B;

		/* address: 0xF0051050 */
		MTU_MC0ERRD3_B_T MTU_MC0ERRD3_B;

		/* address: 0xF0051054 */
		MTU_MC0ERRD4_B_T MTU_MC0ERRD4_B;

		/* address: 0xF0051058 */
		uint8_t MTU_RESERVED_F0051058[80];

		/* address: 0xF00510A8 */
		MTU_MC1ERRD0_B_T MTU_MC1ERRD0_B;

		/* address: 0xF00510AC */
		MTU_MC1ERRD1_B_T MTU_MC1ERRD1_B;

		/* address: 0xF00510B0 */
		MTU_MC1ERRD2_B_T MTU_MC1ERRD2_B;

		/* address: 0xF00510B4 */
		MTU_MC1ERRD3_B_T MTU_MC1ERRD3_B;

		/* address: 0xF00510B8 */
		MTU_MC1ERRD4_B_T MTU_MC1ERRD4_B;

		/* address: 0xF00510BC */
		uint8_t MTU_RESERVED_F00510BC[80];

		/* address: 0xF005110C */
		MTU_MC2ERRD0_B_T MTU_MC2ERRD0_B;

		/* address: 0xF0051110 */
		MTU_MC2ERRD1_B_T MTU_MC2ERRD1_B;

		/* address: 0xF0051114 */
		MTU_MC2ERRD2_B_T MTU_MC2ERRD2_B;

		/* address: 0xF0051118 */
		MTU_MC2ERRD3_B_T MTU_MC2ERRD3_B;

		/* address: 0xF005111C */
		MTU_MC2ERRD4_B_T MTU_MC2ERRD4_B;

		/* address: 0xF0051120 */
		uint8_t MTU_RESERVED_F0051120[80];

		/* address: 0xF0051170 */
		MTU_MC3ERRD0_B_T MTU_MC3ERRD0_B;

		/* address: 0xF0051174 */
		MTU_MC3ERRD1_B_T MTU_MC3ERRD1_B;

		/* address: 0xF0051178 */
		MTU_MC3ERRD2_B_T MTU_MC3ERRD2_B;

		/* address: 0xF005117C */
		MTU_MC3ERRD3_B_T MTU_MC3ERRD3_B;

		/* address: 0xF0051180 */
		MTU_MC3ERRD4_B_T MTU_MC3ERRD4_B;

		/* address: 0xF0051184 */
		uint8_t MTU_RESERVED_F0051184[80];

		/* address: 0xF00511D4 */
		MTU_MC4ERRD0_B_T MTU_MC4ERRD0_B;

		/* address: 0xF00511D8 */
		MTU_MC4ERRD1_B_T MTU_MC4ERRD1_B;

		/* address: 0xF00511DC */
		MTU_MC4ERRD2_B_T MTU_MC4ERRD2_B;

		/* address: 0xF00511E0 */
		MTU_MC4ERRD3_B_T MTU_MC4ERRD3_B;

		/* address: 0xF00511E4 */
		MTU_MC4ERRD4_B_T MTU_MC4ERRD4_B;

		/* address: 0xF00511E8 */
		uint8_t MTU_RESERVED_F00511E8[80];

		/* address: 0xF0051238 */
		MTU_MC5ERRD0_B_T MTU_MC5ERRD0_B;

		/* address: 0xF005123C */
		MTU_MC5ERRD1_B_T MTU_MC5ERRD1_B;

		/* address: 0xF0051240 */
		MTU_MC5ERRD2_B_T MTU_MC5ERRD2_B;

		/* address: 0xF0051244 */
		MTU_MC5ERRD3_B_T MTU_MC5ERRD3_B;

		/* address: 0xF0051248 */
		MTU_MC5ERRD4_B_T MTU_MC5ERRD4_B;

		/* address: 0xF005124C */
		uint8_t MTU_RESERVED_F005124C[80];

		/* address: 0xF005129C */
		MTU_MC6ERRD0_B_T MTU_MC6ERRD0_B;

		/* address: 0xF00512A0 */
		MTU_MC6ERRD1_B_T MTU_MC6ERRD1_B;

		/* address: 0xF00512A4 */
		MTU_MC6ERRD2_B_T MTU_MC6ERRD2_B;

		/* address: 0xF00512A8 */
		MTU_MC6ERRD3_B_T MTU_MC6ERRD3_B;

		/* address: 0xF00512AC */
		MTU_MC6ERRD4_B_T MTU_MC6ERRD4_B;

		/* address: 0xF00512B0 */
		uint8_t MTU_RESERVED_F00512B0[80];

		/* address: 0xF0051300 */
		MTU_MC7ERRD0_B_T MTU_MC7ERRD0_B;

		/* address: 0xF0051304 */
		MTU_MC7ERRD1_B_T MTU_MC7ERRD1_B;

		/* address: 0xF0051308 */
		MTU_MC7ERRD2_B_T MTU_MC7ERRD2_B;

		/* address: 0xF005130C */
		MTU_MC7ERRD3_B_T MTU_MC7ERRD3_B;

		/* address: 0xF0051310 */
		MTU_MC7ERRD4_B_T MTU_MC7ERRD4_B;

		/* address: 0xF0051314 */
		uint8_t MTU_RESERVED_F0051314[80];

		/* address: 0xF0051364 */
		MTU_MC8ERRD0_B_T MTU_MC8ERRD0_B;

		/* address: 0xF0051368 */
		MTU_MC8ERRD1_B_T MTU_MC8ERRD1_B;

		/* address: 0xF005136C */
		MTU_MC8ERRD2_B_T MTU_MC8ERRD2_B;

		/* address: 0xF0051370 */
		MTU_MC8ERRD3_B_T MTU_MC8ERRD3_B;

		/* address: 0xF0051374 */
		MTU_MC8ERRD4_B_T MTU_MC8ERRD4_B;

		/* address: 0xF0051378 */
		uint8_t MTU_RESERVED_F0051378[80];

		/* address: 0xF00513C8 */
		MTU_MC9ERRD0_B_T MTU_MC9ERRD0_B;

		/* address: 0xF00513CC */
		MTU_MC9ERRD1_B_T MTU_MC9ERRD1_B;

		/* address: 0xF00513D0 */
		MTU_MC9ERRD2_B_T MTU_MC9ERRD2_B;

		/* address: 0xF00513D4 */
		MTU_MC9ERRD3_B_T MTU_MC9ERRD3_B;

		/* address: 0xF00513D8 */
		MTU_MC9ERRD4_B_T MTU_MC9ERRD4_B;

		/* address: 0xF00513DC */
		uint8_t MTU_RESERVED_F00513DC[80];

		/* address: 0xF005142C */
		MTU_MC10ERRD0_B_T MTU_MC10ERRD0_B;

		/* address: 0xF0051430 */
		MTU_MC10ERRD1_B_T MTU_MC10ERRD1_B;

		/* address: 0xF0051434 */
		MTU_MC10ERRD2_B_T MTU_MC10ERRD2_B;

		/* address: 0xF0051438 */
		MTU_MC10ERRD3_B_T MTU_MC10ERRD3_B;

		/* address: 0xF005143C */
		MTU_MC10ERRD4_B_T MTU_MC10ERRD4_B;

		/* address: 0xF0051440 */
		uint8_t MTU_RESERVED_F0051440[80];

		/* address: 0xF0051490 */
		MTU_MC11ERRD0_B_T MTU_MC11ERRD0_B;

		/* address: 0xF0051494 */
		MTU_MC11ERRD1_B_T MTU_MC11ERRD1_B;

		/* address: 0xF0051498 */
		MTU_MC11ERRD2_B_T MTU_MC11ERRD2_B;

		/* address: 0xF005149C */
		MTU_MC11ERRD3_B_T MTU_MC11ERRD3_B;

		/* address: 0xF00514A0 */
		MTU_MC11ERRD4_B_T MTU_MC11ERRD4_B;

		/* address: 0xF00514A4 */
		uint8_t MTU_RESERVED_F00514A4[80];

		/* address: 0xF00514F4 */
		MTU_MC12ERRD0_B_T MTU_MC12ERRD0_B;

		/* address: 0xF00514F8 */
		MTU_MC12ERRD1_B_T MTU_MC12ERRD1_B;

		/* address: 0xF00514FC */
		MTU_MC12ERRD2_B_T MTU_MC12ERRD2_B;

		/* address: 0xF0051500 */
		MTU_MC12ERRD3_B_T MTU_MC12ERRD3_B;

		/* address: 0xF0051504 */
		MTU_MC12ERRD4_B_T MTU_MC12ERRD4_B;

		/* address: 0xF0051508 */
		uint8_t MTU_RESERVED_F0051508[80];

		/* address: 0xF0051558 */
		MTU_MC13ERRD0_B_T MTU_MC13ERRD0_B;

		/* address: 0xF005155C */
		MTU_MC13ERRD1_B_T MTU_MC13ERRD1_B;

		/* address: 0xF0051560 */
		MTU_MC13ERRD2_B_T MTU_MC13ERRD2_B;

		/* address: 0xF0051564 */
		MTU_MC13ERRD3_B_T MTU_MC13ERRD3_B;

		/* address: 0xF0051568 */
		MTU_MC13ERRD4_B_T MTU_MC13ERRD4_B;

		/* address: 0xF005156C */
		uint8_t MTU_RESERVED_F005156C[80];

		/* address: 0xF00515BC */
		MTU_MC14ERRD0_B_T MTU_MC14ERRD0_B;

		/* address: 0xF00515C0 */
		MTU_MC14ERRD1_B_T MTU_MC14ERRD1_B;

		/* address: 0xF00515C4 */
		MTU_MC14ERRD2_B_T MTU_MC14ERRD2_B;

		/* address: 0xF00515C8 */
		MTU_MC14ERRD3_B_T MTU_MC14ERRD3_B;

		/* address: 0xF00515CC */
		MTU_MC14ERRD4_B_T MTU_MC14ERRD4_B;

		/* address: 0xF00515D0 */
		uint8_t MTU_RESERVED_F00515D0[80];

		/* address: 0xF0051620 */
		MTU_MC15ERRD0_B_T MTU_MC15ERRD0_B;

		/* address: 0xF0051624 */
		MTU_MC15ERRD1_B_T MTU_MC15ERRD1_B;

		/* address: 0xF0051628 */
		MTU_MC15ERRD2_B_T MTU_MC15ERRD2_B;

		/* address: 0xF005162C */
		MTU_MC15ERRD3_B_T MTU_MC15ERRD3_B;

		/* address: 0xF0051630 */
		MTU_MC15ERRD4_B_T MTU_MC15ERRD4_B;

		/* address: 0xF0051058 */
		MTU_MC0ERRD0_C_T MTU_MC0ERRD0_C;

		/* address: 0xF005105C */
		MTU_MC0ERRD1_C_T MTU_MC0ERRD1_C;

		/* address: 0xF0051060 */
		MTU_MC0ERRD2_C_T MTU_MC0ERRD2_C;

		/* address: 0xF0051064 */
		MTU_MC0ERRD3_C_T MTU_MC0ERRD3_C;

		/* address: 0xF0051068 */
		MTU_MC0ERRD4_C_T MTU_MC0ERRD4_C;

		/* address: 0xF005106C */
		uint8_t MTU_RESERVED_F005106C[80];

		/* address: 0xF00510BC */
		MTU_MC1ERRD0_C_T MTU_MC1ERRD0_C;

		/* address: 0xF00510C0 */
		MTU_MC1ERRD1_C_T MTU_MC1ERRD1_C;

		/* address: 0xF00510C4 */
		MTU_MC1ERRD2_C_T MTU_MC1ERRD2_C;

		/* address: 0xF00510C8 */
		MTU_MC1ERRD3_C_T MTU_MC1ERRD3_C;

		/* address: 0xF00510CC */
		MTU_MC1ERRD4_C_T MTU_MC1ERRD4_C;

		/* address: 0xF00510D0 */
		uint8_t MTU_RESERVED_F00510D0[80];

		/* address: 0xF0051120 */
		MTU_MC2ERRD0_C_T MTU_MC2ERRD0_C;

		/* address: 0xF0051124 */
		MTU_MC2ERRD1_C_T MTU_MC2ERRD1_C;

		/* address: 0xF0051128 */
		MTU_MC2ERRD2_C_T MTU_MC2ERRD2_C;

		/* address: 0xF005112C */
		MTU_MC2ERRD3_C_T MTU_MC2ERRD3_C;

		/* address: 0xF0051130 */
		MTU_MC2ERRD4_C_T MTU_MC2ERRD4_C;

		/* address: 0xF0051134 */
		uint8_t MTU_RESERVED_F0051134[80];

		/* address: 0xF0051184 */
		MTU_MC3ERRD0_C_T MTU_MC3ERRD0_C;

		/* address: 0xF0051188 */
		MTU_MC3ERRD1_C_T MTU_MC3ERRD1_C;

		/* address: 0xF005118C */
		MTU_MC3ERRD2_C_T MTU_MC3ERRD2_C;

		/* address: 0xF0051190 */
		MTU_MC3ERRD3_C_T MTU_MC3ERRD3_C;

		/* address: 0xF0051194 */
		MTU_MC3ERRD4_C_T MTU_MC3ERRD4_C;

		/* address: 0xF0051198 */
		uint8_t MTU_RESERVED_F0051198[80];

		/* address: 0xF00511E8 */
		MTU_MC4ERRD0_C_T MTU_MC4ERRD0_C;

		/* address: 0xF00511EC */
		MTU_MC4ERRD1_C_T MTU_MC4ERRD1_C;

		/* address: 0xF00511F0 */
		MTU_MC4ERRD2_C_T MTU_MC4ERRD2_C;

		/* address: 0xF00511F4 */
		MTU_MC4ERRD3_C_T MTU_MC4ERRD3_C;

		/* address: 0xF00511F8 */
		MTU_MC4ERRD4_C_T MTU_MC4ERRD4_C;

		/* address: 0xF00511FC */
		uint8_t MTU_RESERVED_F00511FC[80];

		/* address: 0xF005124C */
		MTU_MC5ERRD0_C_T MTU_MC5ERRD0_C;

		/* address: 0xF0051250 */
		MTU_MC5ERRD1_C_T MTU_MC5ERRD1_C;

		/* address: 0xF0051254 */
		MTU_MC5ERRD2_C_T MTU_MC5ERRD2_C;

		/* address: 0xF0051258 */
		MTU_MC5ERRD3_C_T MTU_MC5ERRD3_C;

		/* address: 0xF005125C */
		MTU_MC5ERRD4_C_T MTU_MC5ERRD4_C;

		/* address: 0xF0051260 */
		uint8_t MTU_RESERVED_F0051260[80];

		/* address: 0xF00512B0 */
		MTU_MC6ERRD0_C_T MTU_MC6ERRD0_C;

		/* address: 0xF00512B4 */
		MTU_MC6ERRD1_C_T MTU_MC6ERRD1_C;

		/* address: 0xF00512B8 */
		MTU_MC6ERRD2_C_T MTU_MC6ERRD2_C;

		/* address: 0xF00512BC */
		MTU_MC6ERRD3_C_T MTU_MC6ERRD3_C;

		/* address: 0xF00512C0 */
		MTU_MC6ERRD4_C_T MTU_MC6ERRD4_C;

		/* address: 0xF00512C4 */
		uint8_t MTU_RESERVED_F00512C4[80];

		/* address: 0xF0051314 */
		MTU_MC7ERRD0_C_T MTU_MC7ERRD0_C;

		/* address: 0xF0051318 */
		MTU_MC7ERRD1_C_T MTU_MC7ERRD1_C;

		/* address: 0xF005131C */
		MTU_MC7ERRD2_C_T MTU_MC7ERRD2_C;

		/* address: 0xF0051320 */
		MTU_MC7ERRD3_C_T MTU_MC7ERRD3_C;

		/* address: 0xF0051324 */
		MTU_MC7ERRD4_C_T MTU_MC7ERRD4_C;

		/* address: 0xF0051328 */
		uint8_t MTU_RESERVED_F0051328[80];

		/* address: 0xF0051378 */
		MTU_MC8ERRD0_C_T MTU_MC8ERRD0_C;

		/* address: 0xF005137C */
		MTU_MC8ERRD1_C_T MTU_MC8ERRD1_C;

		/* address: 0xF0051380 */
		MTU_MC8ERRD2_C_T MTU_MC8ERRD2_C;

		/* address: 0xF0051384 */
		MTU_MC8ERRD3_C_T MTU_MC8ERRD3_C;

		/* address: 0xF0051388 */
		MTU_MC8ERRD4_C_T MTU_MC8ERRD4_C;

		/* address: 0xF005138C */
		uint8_t MTU_RESERVED_F005138C[80];

		/* address: 0xF00513DC */
		MTU_MC9ERRD0_C_T MTU_MC9ERRD0_C;

		/* address: 0xF00513E0 */
		MTU_MC9ERRD1_C_T MTU_MC9ERRD1_C;

		/* address: 0xF00513E4 */
		MTU_MC9ERRD2_C_T MTU_MC9ERRD2_C;

		/* address: 0xF00513E8 */
		MTU_MC9ERRD3_C_T MTU_MC9ERRD3_C;

		/* address: 0xF00513EC */
		MTU_MC9ERRD4_C_T MTU_MC9ERRD4_C;

		/* address: 0xF00513F0 */
		uint8_t MTU_RESERVED_F00513F0[80];

		/* address: 0xF0051440 */
		MTU_MC10ERRD0_C_T MTU_MC10ERRD0_C;

		/* address: 0xF0051444 */
		MTU_MC10ERRD1_C_T MTU_MC10ERRD1_C;

		/* address: 0xF0051448 */
		MTU_MC10ERRD2_C_T MTU_MC10ERRD2_C;

		/* address: 0xF005144C */
		MTU_MC10ERRD3_C_T MTU_MC10ERRD3_C;

		/* address: 0xF0051450 */
		MTU_MC10ERRD4_C_T MTU_MC10ERRD4_C;

		/* address: 0xF0051454 */
		uint8_t MTU_RESERVED_F0051454[80];

		/* address: 0xF00514A4 */
		MTU_MC11ERRD0_C_T MTU_MC11ERRD0_C;

		/* address: 0xF00514A8 */
		MTU_MC11ERRD1_C_T MTU_MC11ERRD1_C;

		/* address: 0xF00514AC */
		MTU_MC11ERRD2_C_T MTU_MC11ERRD2_C;

		/* address: 0xF00514B0 */
		MTU_MC11ERRD3_C_T MTU_MC11ERRD3_C;

		/* address: 0xF00514B4 */
		MTU_MC11ERRD4_C_T MTU_MC11ERRD4_C;

		/* address: 0xF00514B8 */
		uint8_t MTU_RESERVED_F00514B8[80];

		/* address: 0xF0051508 */
		MTU_MC12ERRD0_C_T MTU_MC12ERRD0_C;

		/* address: 0xF005150C */
		MTU_MC12ERRD1_C_T MTU_MC12ERRD1_C;

		/* address: 0xF0051510 */
		MTU_MC12ERRD2_C_T MTU_MC12ERRD2_C;

		/* address: 0xF0051514 */
		MTU_MC12ERRD3_C_T MTU_MC12ERRD3_C;

		/* address: 0xF0051518 */
		MTU_MC12ERRD4_C_T MTU_MC12ERRD4_C;

		/* address: 0xF005151C */
		uint8_t MTU_RESERVED_F005151C[80];

		/* address: 0xF005156C */
		MTU_MC13ERRD0_C_T MTU_MC13ERRD0_C;

		/* address: 0xF0051570 */
		MTU_MC13ERRD1_C_T MTU_MC13ERRD1_C;

		/* address: 0xF0051574 */
		MTU_MC13ERRD2_C_T MTU_MC13ERRD2_C;

		/* address: 0xF0051578 */
		MTU_MC13ERRD3_C_T MTU_MC13ERRD3_C;

		/* address: 0xF005157C */
		MTU_MC13ERRD4_C_T MTU_MC13ERRD4_C;

		/* address: 0xF0051580 */
		uint8_t MTU_RESERVED_F0051580[80];

		/* address: 0xF00515D0 */
		MTU_MC14ERRD0_C_T MTU_MC14ERRD0_C;

		/* address: 0xF00515D4 */
		MTU_MC14ERRD1_C_T MTU_MC14ERRD1_C;

		/* address: 0xF00515D8 */
		MTU_MC14ERRD2_C_T MTU_MC14ERRD2_C;

		/* address: 0xF00515DC */
		MTU_MC14ERRD3_C_T MTU_MC14ERRD3_C;

		/* address: 0xF00515E0 */
		MTU_MC14ERRD4_C_T MTU_MC14ERRD4_C;

		/* address: 0xF00515E4 */
		uint8_t MTU_RESERVED_F00515E4[80];

		/* address: 0xF0051634 */
		MTU_MC15ERRD0_C_T MTU_MC15ERRD0_C;

		/* address: 0xF0051638 */
		MTU_MC15ERRD1_C_T MTU_MC15ERRD1_C;

		/* address: 0xF005163C */
		MTU_MC15ERRD2_C_T MTU_MC15ERRD2_C;

		/* address: 0xF0051640 */
		MTU_MC15ERRD3_C_T MTU_MC15ERRD3_C;

		/* address: 0xF0051644 */
		MTU_MC15ERRD4_C_T MTU_MC15ERRD4_C;

		/* address: 0xF005106C */
		MTU_MC0RDBFL0_A_T MTU_MC0RDBFL0_A;

		/* address: 0xF0051070 */
		MTU_MC0RDBFL1_A_T MTU_MC0RDBFL1_A;

		/* address: 0xF0051074 */
		MTU_MC0RDBFL2_A_T MTU_MC0RDBFL2_A;

		/* address: 0xF0051078 */
		MTU_MC0RDBFL3_A_T MTU_MC0RDBFL3_A;

		/* address: 0xF005107C */
		MTU_MC0RDBFL4_A_T MTU_MC0RDBFL4_A;

		/* address: 0xF0051080 */
		uint8_t MTU_RESERVED_F0051080[80];

		/* address: 0xF00510D0 */
		MTU_MC1RDBFL0_A_T MTU_MC1RDBFL0_A;

		/* address: 0xF00510D4 */
		MTU_MC1RDBFL1_A_T MTU_MC1RDBFL1_A;

		/* address: 0xF00510D8 */
		MTU_MC1RDBFL2_A_T MTU_MC1RDBFL2_A;

		/* address: 0xF00510DC */
		MTU_MC1RDBFL3_A_T MTU_MC1RDBFL3_A;

		/* address: 0xF00510E0 */
		MTU_MC1RDBFL4_A_T MTU_MC1RDBFL4_A;

		/* address: 0xF00510E4 */
		uint8_t MTU_RESERVED_F00510E4[80];

		/* address: 0xF0051134 */
		MTU_MC2RDBFL0_A_T MTU_MC2RDBFL0_A;

		/* address: 0xF0051138 */
		MTU_MC2RDBFL1_A_T MTU_MC2RDBFL1_A;

		/* address: 0xF005113C */
		MTU_MC2RDBFL2_A_T MTU_MC2RDBFL2_A;

		/* address: 0xF0051140 */
		MTU_MC2RDBFL3_A_T MTU_MC2RDBFL3_A;

		/* address: 0xF0051144 */
		MTU_MC2RDBFL4_A_T MTU_MC2RDBFL4_A;

		/* address: 0xF0051148 */
		uint8_t MTU_RESERVED_F0051148[80];

		/* address: 0xF0051198 */
		MTU_MC3RDBFL0_A_T MTU_MC3RDBFL0_A;

		/* address: 0xF005119C */
		MTU_MC3RDBFL1_A_T MTU_MC3RDBFL1_A;

		/* address: 0xF00511A0 */
		MTU_MC3RDBFL2_A_T MTU_MC3RDBFL2_A;

		/* address: 0xF00511A4 */
		MTU_MC3RDBFL3_A_T MTU_MC3RDBFL3_A;

		/* address: 0xF00511A8 */
		MTU_MC3RDBFL4_A_T MTU_MC3RDBFL4_A;

		/* address: 0xF00511AC */
		uint8_t MTU_RESERVED_F00511AC[80];

		/* address: 0xF00511FC */
		MTU_MC4RDBFL0_A_T MTU_MC4RDBFL0_A;

		/* address: 0xF0051200 */
		MTU_MC4RDBFL1_A_T MTU_MC4RDBFL1_A;

		/* address: 0xF0051204 */
		MTU_MC4RDBFL2_A_T MTU_MC4RDBFL2_A;

		/* address: 0xF0051208 */
		MTU_MC4RDBFL3_A_T MTU_MC4RDBFL3_A;

		/* address: 0xF005120C */
		MTU_MC4RDBFL4_A_T MTU_MC4RDBFL4_A;

		/* address: 0xF0051210 */
		uint8_t MTU_RESERVED_F0051210[80];

		/* address: 0xF0051260 */
		MTU_MC5RDBFL0_A_T MTU_MC5RDBFL0_A;

		/* address: 0xF0051264 */
		MTU_MC5RDBFL1_A_T MTU_MC5RDBFL1_A;

		/* address: 0xF0051268 */
		MTU_MC5RDBFL2_A_T MTU_MC5RDBFL2_A;

		/* address: 0xF005126C */
		MTU_MC5RDBFL3_A_T MTU_MC5RDBFL3_A;

		/* address: 0xF0051270 */
		MTU_MC5RDBFL4_A_T MTU_MC5RDBFL4_A;

		/* address: 0xF0051274 */
		uint8_t MTU_RESERVED_F0051274[80];

		/* address: 0xF00512C4 */
		MTU_MC6RDBFL0_A_T MTU_MC6RDBFL0_A;

		/* address: 0xF00512C8 */
		MTU_MC6RDBFL1_A_T MTU_MC6RDBFL1_A;

		/* address: 0xF00512CC */
		MTU_MC6RDBFL2_A_T MTU_MC6RDBFL2_A;

		/* address: 0xF00512D0 */
		MTU_MC6RDBFL3_A_T MTU_MC6RDBFL3_A;

		/* address: 0xF00512D4 */
		MTU_MC6RDBFL4_A_T MTU_MC6RDBFL4_A;

		/* address: 0xF00512D8 */
		uint8_t MTU_RESERVED_F00512D8[80];

		/* address: 0xF0051328 */
		MTU_MC7RDBFL0_A_T MTU_MC7RDBFL0_A;

		/* address: 0xF005132C */
		MTU_MC7RDBFL1_A_T MTU_MC7RDBFL1_A;

		/* address: 0xF0051330 */
		MTU_MC7RDBFL2_A_T MTU_MC7RDBFL2_A;

		/* address: 0xF0051334 */
		MTU_MC7RDBFL3_A_T MTU_MC7RDBFL3_A;

		/* address: 0xF0051338 */
		MTU_MC7RDBFL4_A_T MTU_MC7RDBFL4_A;

		/* address: 0xF005133C */
		uint8_t MTU_RESERVED_F005133C[80];

		/* address: 0xF005138C */
		MTU_MC8RDBFL0_A_T MTU_MC8RDBFL0_A;

		/* address: 0xF0051390 */
		MTU_MC8RDBFL1_A_T MTU_MC8RDBFL1_A;

		/* address: 0xF0051394 */
		MTU_MC8RDBFL2_A_T MTU_MC8RDBFL2_A;

		/* address: 0xF0051398 */
		MTU_MC8RDBFL3_A_T MTU_MC8RDBFL3_A;

		/* address: 0xF005139C */
		MTU_MC8RDBFL4_A_T MTU_MC8RDBFL4_A;

		/* address: 0xF00513A0 */
		uint8_t MTU_RESERVED_F00513A0[80];

		/* address: 0xF00513F0 */
		MTU_MC9RDBFL0_A_T MTU_MC9RDBFL0_A;

		/* address: 0xF00513F4 */
		MTU_MC9RDBFL1_A_T MTU_MC9RDBFL1_A;

		/* address: 0xF00513F8 */
		MTU_MC9RDBFL2_A_T MTU_MC9RDBFL2_A;

		/* address: 0xF00513FC */
		MTU_MC9RDBFL3_A_T MTU_MC9RDBFL3_A;

		/* address: 0xF0051400 */
		MTU_MC9RDBFL4_A_T MTU_MC9RDBFL4_A;

		/* address: 0xF0051404 */
		uint8_t MTU_RESERVED_F0051404[80];

		/* address: 0xF0051454 */
		MTU_MC10RDBFL0_A_T MTU_MC10RDBFL0_A;

		/* address: 0xF0051458 */
		MTU_MC10RDBFL1_A_T MTU_MC10RDBFL1_A;

		/* address: 0xF005145C */
		MTU_MC10RDBFL2_A_T MTU_MC10RDBFL2_A;

		/* address: 0xF0051460 */
		MTU_MC10RDBFL3_A_T MTU_MC10RDBFL3_A;

		/* address: 0xF0051464 */
		MTU_MC10RDBFL4_A_T MTU_MC10RDBFL4_A;

		/* address: 0xF0051468 */
		uint8_t MTU_RESERVED_F0051468[80];

		/* address: 0xF00514B8 */
		MTU_MC11RDBFL0_A_T MTU_MC11RDBFL0_A;

		/* address: 0xF00514BC */
		MTU_MC11RDBFL1_A_T MTU_MC11RDBFL1_A;

		/* address: 0xF00514C0 */
		MTU_MC11RDBFL2_A_T MTU_MC11RDBFL2_A;

		/* address: 0xF00514C4 */
		MTU_MC11RDBFL3_A_T MTU_MC11RDBFL3_A;

		/* address: 0xF00514C8 */
		MTU_MC11RDBFL4_A_T MTU_MC11RDBFL4_A;

		/* address: 0xF00514CC */
		uint8_t MTU_RESERVED_F00514CC[80];

		/* address: 0xF005151C */
		MTU_MC12RDBFL0_A_T MTU_MC12RDBFL0_A;

		/* address: 0xF0051520 */
		MTU_MC12RDBFL1_A_T MTU_MC12RDBFL1_A;

		/* address: 0xF0051524 */
		MTU_MC12RDBFL2_A_T MTU_MC12RDBFL2_A;

		/* address: 0xF0051528 */
		MTU_MC12RDBFL3_A_T MTU_MC12RDBFL3_A;

		/* address: 0xF005152C */
		MTU_MC12RDBFL4_A_T MTU_MC12RDBFL4_A;

		/* address: 0xF0051530 */
		uint8_t MTU_RESERVED_F0051530[80];

		/* address: 0xF0051580 */
		MTU_MC13RDBFL0_A_T MTU_MC13RDBFL0_A;

		/* address: 0xF0051584 */
		MTU_MC13RDBFL1_A_T MTU_MC13RDBFL1_A;

		/* address: 0xF0051588 */
		MTU_MC13RDBFL2_A_T MTU_MC13RDBFL2_A;

		/* address: 0xF005158C */
		MTU_MC13RDBFL3_A_T MTU_MC13RDBFL3_A;

		/* address: 0xF0051590 */
		MTU_MC13RDBFL4_A_T MTU_MC13RDBFL4_A;

		/* address: 0xF0051594 */
		uint8_t MTU_RESERVED_F0051594[80];

		/* address: 0xF00515E4 */
		MTU_MC14RDBFL0_A_T MTU_MC14RDBFL0_A;

		/* address: 0xF00515E8 */
		MTU_MC14RDBFL1_A_T MTU_MC14RDBFL1_A;

		/* address: 0xF00515EC */
		MTU_MC14RDBFL2_A_T MTU_MC14RDBFL2_A;

		/* address: 0xF00515F0 */
		MTU_MC14RDBFL3_A_T MTU_MC14RDBFL3_A;

		/* address: 0xF00515F4 */
		MTU_MC14RDBFL4_A_T MTU_MC14RDBFL4_A;

		/* address: 0xF00515F8 */
		uint8_t MTU_RESERVED_F00515F8[80];

		/* address: 0xF0051648 */
		MTU_MC15RDBFL0_A_T MTU_MC15RDBFL0_A;

		/* address: 0xF005164C */
		MTU_MC15RDBFL1_A_T MTU_MC15RDBFL1_A;

		/* address: 0xF0051650 */
		MTU_MC15RDBFL2_A_T MTU_MC15RDBFL2_A;

		/* address: 0xF0051654 */
		MTU_MC15RDBFL3_A_T MTU_MC15RDBFL3_A;

		/* address: 0xF0051658 */
		MTU_MC15RDBFL4_A_T MTU_MC15RDBFL4_A;

		/* address: 0xF0051080 */
		MTU_MC0RDBFL0_B_T MTU_MC0RDBFL0_B;

		/* address: 0xF0051084 */
		MTU_MC0RDBFL1_B_T MTU_MC0RDBFL1_B;

		/* address: 0xF0051088 */
		MTU_MC0RDBFL2_B_T MTU_MC0RDBFL2_B;

		/* address: 0xF005108C */
		MTU_MC0RDBFL3_B_T MTU_MC0RDBFL3_B;

		/* address: 0xF0051090 */
		MTU_MC0RDBFL4_B_T MTU_MC0RDBFL4_B;

		/* address: 0xF0051094 */
		uint8_t MTU_RESERVED_F0051094[80];

		/* address: 0xF00510E4 */
		MTU_MC1RDBFL0_B_T MTU_MC1RDBFL0_B;

		/* address: 0xF00510E8 */
		MTU_MC1RDBFL1_B_T MTU_MC1RDBFL1_B;

		/* address: 0xF00510EC */
		MTU_MC1RDBFL2_B_T MTU_MC1RDBFL2_B;

		/* address: 0xF00510F0 */
		MTU_MC1RDBFL3_B_T MTU_MC1RDBFL3_B;

		/* address: 0xF00510F4 */
		MTU_MC1RDBFL4_B_T MTU_MC1RDBFL4_B;

		/* address: 0xF00510F8 */
		uint8_t MTU_RESERVED_F00510F8[80];

		/* address: 0xF0051148 */
		MTU_MC2RDBFL0_B_T MTU_MC2RDBFL0_B;

		/* address: 0xF005114C */
		MTU_MC2RDBFL1_B_T MTU_MC2RDBFL1_B;

		/* address: 0xF0051150 */
		MTU_MC2RDBFL2_B_T MTU_MC2RDBFL2_B;

		/* address: 0xF0051154 */
		MTU_MC2RDBFL3_B_T MTU_MC2RDBFL3_B;

		/* address: 0xF0051158 */
		MTU_MC2RDBFL4_B_T MTU_MC2RDBFL4_B;

		/* address: 0xF005115C */
		uint8_t MTU_RESERVED_F005115C[80];

		/* address: 0xF00511AC */
		MTU_MC3RDBFL0_B_T MTU_MC3RDBFL0_B;

		/* address: 0xF00511B0 */
		MTU_MC3RDBFL1_B_T MTU_MC3RDBFL1_B;

		/* address: 0xF00511B4 */
		MTU_MC3RDBFL2_B_T MTU_MC3RDBFL2_B;

		/* address: 0xF00511B8 */
		MTU_MC3RDBFL3_B_T MTU_MC3RDBFL3_B;

		/* address: 0xF00511BC */
		MTU_MC3RDBFL4_B_T MTU_MC3RDBFL4_B;

		/* address: 0xF00511C0 */
		uint8_t MTU_RESERVED_F00511C0[80];

		/* address: 0xF0051210 */
		MTU_MC4RDBFL0_B_T MTU_MC4RDBFL0_B;

		/* address: 0xF0051214 */
		MTU_MC4RDBFL1_B_T MTU_MC4RDBFL1_B;

		/* address: 0xF0051218 */
		MTU_MC4RDBFL2_B_T MTU_MC4RDBFL2_B;

		/* address: 0xF005121C */
		MTU_MC4RDBFL3_B_T MTU_MC4RDBFL3_B;

		/* address: 0xF0051220 */
		MTU_MC4RDBFL4_B_T MTU_MC4RDBFL4_B;

		/* address: 0xF0051224 */
		uint8_t MTU_RESERVED_F0051224[80];

		/* address: 0xF0051274 */
		MTU_MC5RDBFL0_B_T MTU_MC5RDBFL0_B;

		/* address: 0xF0051278 */
		MTU_MC5RDBFL1_B_T MTU_MC5RDBFL1_B;

		/* address: 0xF005127C */
		MTU_MC5RDBFL2_B_T MTU_MC5RDBFL2_B;

		/* address: 0xF0051280 */
		MTU_MC5RDBFL3_B_T MTU_MC5RDBFL3_B;

		/* address: 0xF0051284 */
		MTU_MC5RDBFL4_B_T MTU_MC5RDBFL4_B;

		/* address: 0xF0051288 */
		uint8_t MTU_RESERVED_F0051288[80];

		/* address: 0xF00512D8 */
		MTU_MC6RDBFL0_B_T MTU_MC6RDBFL0_B;

		/* address: 0xF00512DC */
		MTU_MC6RDBFL1_B_T MTU_MC6RDBFL1_B;

		/* address: 0xF00512E0 */
		MTU_MC6RDBFL2_B_T MTU_MC6RDBFL2_B;

		/* address: 0xF00512E4 */
		MTU_MC6RDBFL3_B_T MTU_MC6RDBFL3_B;

		/* address: 0xF00512E8 */
		MTU_MC6RDBFL4_B_T MTU_MC6RDBFL4_B;

		/* address: 0xF00512EC */
		uint8_t MTU_RESERVED_F00512EC[80];

		/* address: 0xF005133C */
		MTU_MC7RDBFL0_B_T MTU_MC7RDBFL0_B;

		/* address: 0xF0051340 */
		MTU_MC7RDBFL1_B_T MTU_MC7RDBFL1_B;

		/* address: 0xF0051344 */
		MTU_MC7RDBFL2_B_T MTU_MC7RDBFL2_B;

		/* address: 0xF0051348 */
		MTU_MC7RDBFL3_B_T MTU_MC7RDBFL3_B;

		/* address: 0xF005134C */
		MTU_MC7RDBFL4_B_T MTU_MC7RDBFL4_B;

		/* address: 0xF0051350 */
		uint8_t MTU_RESERVED_F0051350[80];

		/* address: 0xF00513A0 */
		MTU_MC8RDBFL0_B_T MTU_MC8RDBFL0_B;

		/* address: 0xF00513A4 */
		MTU_MC8RDBFL1_B_T MTU_MC8RDBFL1_B;

		/* address: 0xF00513A8 */
		MTU_MC8RDBFL2_B_T MTU_MC8RDBFL2_B;

		/* address: 0xF00513AC */
		MTU_MC8RDBFL3_B_T MTU_MC8RDBFL3_B;

		/* address: 0xF00513B0 */
		MTU_MC8RDBFL4_B_T MTU_MC8RDBFL4_B;

		/* address: 0xF00513B4 */
		uint8_t MTU_RESERVED_F00513B4[80];

		/* address: 0xF0051404 */
		MTU_MC9RDBFL0_B_T MTU_MC9RDBFL0_B;

		/* address: 0xF0051408 */
		MTU_MC9RDBFL1_B_T MTU_MC9RDBFL1_B;

		/* address: 0xF005140C */
		MTU_MC9RDBFL2_B_T MTU_MC9RDBFL2_B;

		/* address: 0xF0051410 */
		MTU_MC9RDBFL3_B_T MTU_MC9RDBFL3_B;

		/* address: 0xF0051414 */
		MTU_MC9RDBFL4_B_T MTU_MC9RDBFL4_B;

		/* address: 0xF0051418 */
		uint8_t MTU_RESERVED_F0051418[80];

		/* address: 0xF0051468 */
		MTU_MC10RDBFL0_B_T MTU_MC10RDBFL0_B;

		/* address: 0xF005146C */
		MTU_MC10RDBFL1_B_T MTU_MC10RDBFL1_B;

		/* address: 0xF0051470 */
		MTU_MC10RDBFL2_B_T MTU_MC10RDBFL2_B;

		/* address: 0xF0051474 */
		MTU_MC10RDBFL3_B_T MTU_MC10RDBFL3_B;

		/* address: 0xF0051478 */
		MTU_MC10RDBFL4_B_T MTU_MC10RDBFL4_B;

		/* address: 0xF005147C */
		uint8_t MTU_RESERVED_F005147C[80];

		/* address: 0xF00514CC */
		MTU_MC11RDBFL0_B_T MTU_MC11RDBFL0_B;

		/* address: 0xF00514D0 */
		MTU_MC11RDBFL1_B_T MTU_MC11RDBFL1_B;

		/* address: 0xF00514D4 */
		MTU_MC11RDBFL2_B_T MTU_MC11RDBFL2_B;

		/* address: 0xF00514D8 */
		MTU_MC11RDBFL3_B_T MTU_MC11RDBFL3_B;

		/* address: 0xF00514DC */
		MTU_MC11RDBFL4_B_T MTU_MC11RDBFL4_B;

		/* address: 0xF00514E0 */
		uint8_t MTU_RESERVED_F00514E0[80];

		/* address: 0xF0051530 */
		MTU_MC12RDBFL0_B_T MTU_MC12RDBFL0_B;

		/* address: 0xF0051534 */
		MTU_MC12RDBFL1_B_T MTU_MC12RDBFL1_B;

		/* address: 0xF0051538 */
		MTU_MC12RDBFL2_B_T MTU_MC12RDBFL2_B;

		/* address: 0xF005153C */
		MTU_MC12RDBFL3_B_T MTU_MC12RDBFL3_B;

		/* address: 0xF0051540 */
		MTU_MC12RDBFL4_B_T MTU_MC12RDBFL4_B;

		/* address: 0xF0051544 */
		uint8_t MTU_RESERVED_F0051544[80];

		/* address: 0xF0051594 */
		MTU_MC13RDBFL0_B_T MTU_MC13RDBFL0_B;

		/* address: 0xF0051598 */
		MTU_MC13RDBFL1_B_T MTU_MC13RDBFL1_B;

		/* address: 0xF005159C */
		MTU_MC13RDBFL2_B_T MTU_MC13RDBFL2_B;

		/* address: 0xF00515A0 */
		MTU_MC13RDBFL3_B_T MTU_MC13RDBFL3_B;

		/* address: 0xF00515A4 */
		MTU_MC13RDBFL4_B_T MTU_MC13RDBFL4_B;

		/* address: 0xF00515A8 */
		uint8_t MTU_RESERVED_F00515A8[80];

		/* address: 0xF00515F8 */
		MTU_MC14RDBFL0_B_T MTU_MC14RDBFL0_B;

		/* address: 0xF00515FC */
		MTU_MC14RDBFL1_B_T MTU_MC14RDBFL1_B;

		/* address: 0xF0051600 */
		MTU_MC14RDBFL2_B_T MTU_MC14RDBFL2_B;

		/* address: 0xF0051604 */
		MTU_MC14RDBFL3_B_T MTU_MC14RDBFL3_B;

		/* address: 0xF0051608 */
		MTU_MC14RDBFL4_B_T MTU_MC14RDBFL4_B;

		/* address: 0xF005160C */
		uint8_t MTU_RESERVED_F005160C[80];

		/* address: 0xF005165C */
		MTU_MC15RDBFL0_B_T MTU_MC15RDBFL0_B;

		/* address: 0xF0051660 */
		MTU_MC15RDBFL1_B_T MTU_MC15RDBFL1_B;

		/* address: 0xF0051664 */
		MTU_MC15RDBFL2_B_T MTU_MC15RDBFL2_B;

		/* address: 0xF0051668 */
		MTU_MC15RDBFL3_B_T MTU_MC15RDBFL3_B;

		/* address: 0xF005166C */
		MTU_MC15RDBFL4_B_T MTU_MC15RDBFL4_B;

		/* address: 0xF0051094 */
		MTU_MC0RDBFL0_C_T MTU_MC0RDBFL0_C;

		/* address: 0xF0051098 */
		MTU_MC0RDBFL1_C_T MTU_MC0RDBFL1_C;

		/* address: 0xF005109C */
		MTU_MC0RDBFL2_C_T MTU_MC0RDBFL2_C;

		/* address: 0xF00510A0 */
		MTU_MC0RDBFL3_C_T MTU_MC0RDBFL3_C;

		/* address: 0xF00510A4 */
		MTU_MC0RDBFL4_C_T MTU_MC0RDBFL4_C;

		/* address: 0xF00510A8 */
		uint8_t MTU_RESERVED_F00510A8[80];

		/* address: 0xF00510F8 */
		MTU_MC1RDBFL0_C_T MTU_MC1RDBFL0_C;

		/* address: 0xF00510FC */
		MTU_MC1RDBFL1_C_T MTU_MC1RDBFL1_C;

		/* address: 0xF0051100 */
		MTU_MC1RDBFL2_C_T MTU_MC1RDBFL2_C;

		/* address: 0xF0051104 */
		MTU_MC1RDBFL3_C_T MTU_MC1RDBFL3_C;

		/* address: 0xF0051108 */
		MTU_MC1RDBFL4_C_T MTU_MC1RDBFL4_C;

		/* address: 0xF005110C */
		uint8_t MTU_RESERVED_F005110C[80];

		/* address: 0xF005115C */
		MTU_MC2RDBFL0_C_T MTU_MC2RDBFL0_C;

		/* address: 0xF0051160 */
		MTU_MC2RDBFL1_C_T MTU_MC2RDBFL1_C;

		/* address: 0xF0051164 */
		MTU_MC2RDBFL2_C_T MTU_MC2RDBFL2_C;

		/* address: 0xF0051168 */
		MTU_MC2RDBFL3_C_T MTU_MC2RDBFL3_C;

		/* address: 0xF005116C */
		MTU_MC2RDBFL4_C_T MTU_MC2RDBFL4_C;

		/* address: 0xF0051170 */
		uint8_t MTU_RESERVED_F0051170[80];

		/* address: 0xF00511C0 */
		MTU_MC3RDBFL0_C_T MTU_MC3RDBFL0_C;

		/* address: 0xF00511C4 */
		MTU_MC3RDBFL1_C_T MTU_MC3RDBFL1_C;

		/* address: 0xF00511C8 */
		MTU_MC3RDBFL2_C_T MTU_MC3RDBFL2_C;

		/* address: 0xF00511CC */
		MTU_MC3RDBFL3_C_T MTU_MC3RDBFL3_C;

		/* address: 0xF00511D0 */
		MTU_MC3RDBFL4_C_T MTU_MC3RDBFL4_C;

		/* address: 0xF00511D4 */
		uint8_t MTU_RESERVED_F00511D4[80];

		/* address: 0xF0051224 */
		MTU_MC4RDBFL0_C_T MTU_MC4RDBFL0_C;

		/* address: 0xF0051228 */
		MTU_MC4RDBFL1_C_T MTU_MC4RDBFL1_C;

		/* address: 0xF005122C */
		MTU_MC4RDBFL2_C_T MTU_MC4RDBFL2_C;

		/* address: 0xF0051230 */
		MTU_MC4RDBFL3_C_T MTU_MC4RDBFL3_C;

		/* address: 0xF0051234 */
		MTU_MC4RDBFL4_C_T MTU_MC4RDBFL4_C;

		/* address: 0xF0051238 */
		uint8_t MTU_RESERVED_F0051238[80];

		/* address: 0xF0051288 */
		MTU_MC5RDBFL0_C_T MTU_MC5RDBFL0_C;

		/* address: 0xF005128C */
		MTU_MC5RDBFL1_C_T MTU_MC5RDBFL1_C;

		/* address: 0xF0051290 */
		MTU_MC5RDBFL2_C_T MTU_MC5RDBFL2_C;

		/* address: 0xF0051294 */
		MTU_MC5RDBFL3_C_T MTU_MC5RDBFL3_C;

		/* address: 0xF0051298 */
		MTU_MC5RDBFL4_C_T MTU_MC5RDBFL4_C;

		/* address: 0xF005129C */
		uint8_t MTU_RESERVED_F005129C[80];

		/* address: 0xF00512EC */
		MTU_MC6RDBFL0_C_T MTU_MC6RDBFL0_C;

		/* address: 0xF00512F0 */
		MTU_MC6RDBFL1_C_T MTU_MC6RDBFL1_C;

		/* address: 0xF00512F4 */
		MTU_MC6RDBFL2_C_T MTU_MC6RDBFL2_C;

		/* address: 0xF00512F8 */
		MTU_MC6RDBFL3_C_T MTU_MC6RDBFL3_C;

		/* address: 0xF00512FC */
		MTU_MC6RDBFL4_C_T MTU_MC6RDBFL4_C;

		/* address: 0xF0051300 */
		uint8_t MTU_RESERVED_F0051300[80];

		/* address: 0xF0051350 */
		MTU_MC7RDBFL0_C_T MTU_MC7RDBFL0_C;

		/* address: 0xF0051354 */
		MTU_MC7RDBFL1_C_T MTU_MC7RDBFL1_C;

		/* address: 0xF0051358 */
		MTU_MC7RDBFL2_C_T MTU_MC7RDBFL2_C;

		/* address: 0xF005135C */
		MTU_MC7RDBFL3_C_T MTU_MC7RDBFL3_C;

		/* address: 0xF0051360 */
		MTU_MC7RDBFL4_C_T MTU_MC7RDBFL4_C;

		/* address: 0xF0051364 */
		uint8_t MTU_RESERVED_F0051364[80];

		/* address: 0xF00513B4 */
		MTU_MC8RDBFL0_C_T MTU_MC8RDBFL0_C;

		/* address: 0xF00513B8 */
		MTU_MC8RDBFL1_C_T MTU_MC8RDBFL1_C;

		/* address: 0xF00513BC */
		MTU_MC8RDBFL2_C_T MTU_MC8RDBFL2_C;

		/* address: 0xF00513C0 */
		MTU_MC8RDBFL3_C_T MTU_MC8RDBFL3_C;

		/* address: 0xF00513C4 */
		MTU_MC8RDBFL4_C_T MTU_MC8RDBFL4_C;

		/* address: 0xF00513C8 */
		uint8_t MTU_RESERVED_F00513C8[80];

		/* address: 0xF0051418 */
		MTU_MC9RDBFL0_C_T MTU_MC9RDBFL0_C;

		/* address: 0xF005141C */
		MTU_MC9RDBFL1_C_T MTU_MC9RDBFL1_C;

		/* address: 0xF0051420 */
		MTU_MC9RDBFL2_C_T MTU_MC9RDBFL2_C;

		/* address: 0xF0051424 */
		MTU_MC9RDBFL3_C_T MTU_MC9RDBFL3_C;

		/* address: 0xF0051428 */
		MTU_MC9RDBFL4_C_T MTU_MC9RDBFL4_C;

		/* address: 0xF005142C */
		uint8_t MTU_RESERVED_F005142C[80];

		/* address: 0xF005147C */
		MTU_MC10RDBFL0_C_T MTU_MC10RDBFL0_C;

		/* address: 0xF0051480 */
		MTU_MC10RDBFL1_C_T MTU_MC10RDBFL1_C;

		/* address: 0xF0051484 */
		MTU_MC10RDBFL2_C_T MTU_MC10RDBFL2_C;

		/* address: 0xF0051488 */
		MTU_MC10RDBFL3_C_T MTU_MC10RDBFL3_C;

		/* address: 0xF005148C */
		MTU_MC10RDBFL4_C_T MTU_MC10RDBFL4_C;

		/* address: 0xF0051490 */
		uint8_t MTU_RESERVED_F0051490[80];

		/* address: 0xF00514E0 */
		MTU_MC11RDBFL0_C_T MTU_MC11RDBFL0_C;

		/* address: 0xF00514E4 */
		MTU_MC11RDBFL1_C_T MTU_MC11RDBFL1_C;

		/* address: 0xF00514E8 */
		MTU_MC11RDBFL2_C_T MTU_MC11RDBFL2_C;

		/* address: 0xF00514EC */
		MTU_MC11RDBFL3_C_T MTU_MC11RDBFL3_C;

		/* address: 0xF00514F0 */
		MTU_MC11RDBFL4_C_T MTU_MC11RDBFL4_C;

		/* address: 0xF00514F4 */
		uint8_t MTU_RESERVED_F00514F4[80];

		/* address: 0xF0051544 */
		MTU_MC12RDBFL0_C_T MTU_MC12RDBFL0_C;

		/* address: 0xF0051548 */
		MTU_MC12RDBFL1_C_T MTU_MC12RDBFL1_C;

		/* address: 0xF005154C */
		MTU_MC12RDBFL2_C_T MTU_MC12RDBFL2_C;

		/* address: 0xF0051550 */
		MTU_MC12RDBFL3_C_T MTU_MC12RDBFL3_C;

		/* address: 0xF0051554 */
		MTU_MC12RDBFL4_C_T MTU_MC12RDBFL4_C;

		/* address: 0xF0051558 */
		uint8_t MTU_RESERVED_F0051558[80];

		/* address: 0xF00515A8 */
		MTU_MC13RDBFL0_C_T MTU_MC13RDBFL0_C;

		/* address: 0xF00515AC */
		MTU_MC13RDBFL1_C_T MTU_MC13RDBFL1_C;

		/* address: 0xF00515B0 */
		MTU_MC13RDBFL2_C_T MTU_MC13RDBFL2_C;

		/* address: 0xF00515B4 */
		MTU_MC13RDBFL3_C_T MTU_MC13RDBFL3_C;

		/* address: 0xF00515B8 */
		MTU_MC13RDBFL4_C_T MTU_MC13RDBFL4_C;

		/* address: 0xF00515BC */
		uint8_t MTU_RESERVED_F00515BC[80];

		/* address: 0xF005160C */
		MTU_MC14RDBFL0_C_T MTU_MC14RDBFL0_C;

		/* address: 0xF0051610 */
		MTU_MC14RDBFL1_C_T MTU_MC14RDBFL1_C;

		/* address: 0xF0051614 */
		MTU_MC14RDBFL2_C_T MTU_MC14RDBFL2_C;

		/* address: 0xF0051618 */
		MTU_MC14RDBFL3_C_T MTU_MC14RDBFL3_C;

		/* address: 0xF005161C */
		MTU_MC14RDBFL4_C_T MTU_MC14RDBFL4_C;

		/* address: 0xF0051620 */
		uint8_t MTU_RESERVED_F0051620[80];

		/* address: 0xF0051670 */
		MTU_MC15RDBFL0_C_T MTU_MC15RDBFL0_C;

		/* address: 0xF0051674 */
		MTU_MC15RDBFL1_C_T MTU_MC15RDBFL1_C;

		/* address: 0xF0051678 */
		MTU_MC15RDBFL2_C_T MTU_MC15RDBFL2_C;

		/* address: 0xF005167C */
		MTU_MC15RDBFL3_C_T MTU_MC15RDBFL3_C;

		/* address: 0xF0051680 */
		MTU_MC15RDBFL4_C_T MTU_MC15RDBFL4_C;

		/* address: 0xF00510A8 */
		MTU_MC0FAULT_T MTU_MC0FAULT;

		/* address: 0xF00510AC */
		uint8_t MTU_RESERVED_F00510AC[252];

		/* address: 0xF00511A8 */
		MTU_MC1FAULT_T MTU_MC1FAULT;

		/* address: 0xF00511AC */
		uint8_t MTU_RESERVED_F00511AC[252];

		/* address: 0xF00512A8 */
		MTU_MC2FAULT_T MTU_MC2FAULT;

		/* address: 0xF00512AC */
		uint8_t MTU_RESERVED_F00512AC[252];

		/* address: 0xF00513A8 */
		MTU_MC3FAULT_T MTU_MC3FAULT;

		/* address: 0xF00513AC */
		uint8_t MTU_RESERVED_F00513AC[252];

		/* address: 0xF00514A8 */
		MTU_MC4FAULT_T MTU_MC4FAULT;

		/* address: 0xF00514AC */
		uint8_t MTU_RESERVED_F00514AC[252];

		/* address: 0xF00515A8 */
		MTU_MC5FAULT_T MTU_MC5FAULT;

		/* address: 0xF00515AC */
		uint8_t MTU_RESERVED_F00515AC[252];

		/* address: 0xF00516A8 */
		MTU_MC6FAULT_T MTU_MC6FAULT;

		/* address: 0xF00516AC */
		uint8_t MTU_RESERVED_F00516AC[252];

		/* address: 0xF00517A8 */
		MTU_MC7FAULT_T MTU_MC7FAULT;

		/* address: 0xF00517AC */
		uint8_t MTU_RESERVED_F00517AC[252];

		/* address: 0xF00518A8 */
		MTU_MC8FAULT_T MTU_MC8FAULT;

		/* address: 0xF00518AC */
		uint8_t MTU_RESERVED_F00518AC[252];

		/* address: 0xF00519A8 */
		MTU_MC9FAULT_T MTU_MC9FAULT;

		/* address: 0xF00519AC */
		uint8_t MTU_RESERVED_F00519AC[252];

		/* address: 0xF0051AA8 */
		MTU_MC10FAULT_T MTU_MC10FAULT;

		/* address: 0xF0051AAC */
		uint8_t MTU_RESERVED_F0051AAC[252];

		/* address: 0xF0051BA8 */
		MTU_MC11FAULT_T MTU_MC11FAULT;

		/* address: 0xF0051BAC */
		uint8_t MTU_RESERVED_F0051BAC[252];

		/* address: 0xF0051CA8 */
		MTU_MC12FAULT_T MTU_MC12FAULT;

		/* address: 0xF0051CAC */
		uint8_t MTU_RESERVED_F0051CAC[252];

		/* address: 0xF0051DA8 */
		MTU_MC13FAULT_T MTU_MC13FAULT;

		/* address: 0xF0051DAC */
		uint8_t MTU_RESERVED_F0051DAC[252];

		/* address: 0xF0051EA8 */
		MTU_MC14FAULT_T MTU_MC14FAULT;

		/* address: 0xF0051EAC */
		uint8_t MTU_RESERVED_F0051EAC[252];

		/* address: 0xF0051FA8 */
		MTU_MC15FAULT_T MTU_MC15FAULT;

		/* address: 0xF00510AC */
		MTU_MC0ERRINFO0_T MTU_MC0ERRINFO0;

		/* address: 0xF00510B0 */
		MTU_MC0ERRINFO1_T MTU_MC0ERRINFO1;

		/* address: 0xF00510B4 */
		MTU_MC0ERRINFO2_T MTU_MC0ERRINFO2;

		/* address: 0xF00510B8 */
		MTU_MC0ERRINFO3_T MTU_MC0ERRINFO3;

		/* address: 0xF00510BC */
		MTU_MC0ERRINFO4_T MTU_MC0ERRINFO4;

		/* address: 0xF00510C0 */
		uint8_t MTU_RESERVED_F00510C0[80];

		/* address: 0xF0051110 */
		MTU_MC1ERRINFO0_T MTU_MC1ERRINFO0;

		/* address: 0xF0051114 */
		MTU_MC1ERRINFO1_T MTU_MC1ERRINFO1;

		/* address: 0xF0051118 */
		MTU_MC1ERRINFO2_T MTU_MC1ERRINFO2;

		/* address: 0xF005111C */
		MTU_MC1ERRINFO3_T MTU_MC1ERRINFO3;

		/* address: 0xF0051120 */
		MTU_MC1ERRINFO4_T MTU_MC1ERRINFO4;

		/* address: 0xF0051124 */
		uint8_t MTU_RESERVED_F0051124[80];

		/* address: 0xF0051174 */
		MTU_MC2ERRINFO0_T MTU_MC2ERRINFO0;

		/* address: 0xF0051178 */
		MTU_MC2ERRINFO1_T MTU_MC2ERRINFO1;

		/* address: 0xF005117C */
		MTU_MC2ERRINFO2_T MTU_MC2ERRINFO2;

		/* address: 0xF0051180 */
		MTU_MC2ERRINFO3_T MTU_MC2ERRINFO3;

		/* address: 0xF0051184 */
		MTU_MC2ERRINFO4_T MTU_MC2ERRINFO4;

		/* address: 0xF0051188 */
		uint8_t MTU_RESERVED_F0051188[80];

		/* address: 0xF00511D8 */
		MTU_MC3ERRINFO0_T MTU_MC3ERRINFO0;

		/* address: 0xF00511DC */
		MTU_MC3ERRINFO1_T MTU_MC3ERRINFO1;

		/* address: 0xF00511E0 */
		MTU_MC3ERRINFO2_T MTU_MC3ERRINFO2;

		/* address: 0xF00511E4 */
		MTU_MC3ERRINFO3_T MTU_MC3ERRINFO3;

		/* address: 0xF00511E8 */
		MTU_MC3ERRINFO4_T MTU_MC3ERRINFO4;

		/* address: 0xF00511EC */
		uint8_t MTU_RESERVED_F00511EC[80];

		/* address: 0xF005123C */
		MTU_MC4ERRINFO0_T MTU_MC4ERRINFO0;

		/* address: 0xF0051240 */
		MTU_MC4ERRINFO1_T MTU_MC4ERRINFO1;

		/* address: 0xF0051244 */
		MTU_MC4ERRINFO2_T MTU_MC4ERRINFO2;

		/* address: 0xF0051248 */
		MTU_MC4ERRINFO3_T MTU_MC4ERRINFO3;

		/* address: 0xF005124C */
		MTU_MC4ERRINFO4_T MTU_MC4ERRINFO4;

		/* address: 0xF0051250 */
		uint8_t MTU_RESERVED_F0051250[80];

		/* address: 0xF00512A0 */
		MTU_MC5ERRINFO0_T MTU_MC5ERRINFO0;

		/* address: 0xF00512A4 */
		MTU_MC5ERRINFO1_T MTU_MC5ERRINFO1;

		/* address: 0xF00512A8 */
		MTU_MC5ERRINFO2_T MTU_MC5ERRINFO2;

		/* address: 0xF00512AC */
		MTU_MC5ERRINFO3_T MTU_MC5ERRINFO3;

		/* address: 0xF00512B0 */
		MTU_MC5ERRINFO4_T MTU_MC5ERRINFO4;

		/* address: 0xF00512B4 */
		uint8_t MTU_RESERVED_F00512B4[80];

		/* address: 0xF0051304 */
		MTU_MC6ERRINFO0_T MTU_MC6ERRINFO0;

		/* address: 0xF0051308 */
		MTU_MC6ERRINFO1_T MTU_MC6ERRINFO1;

		/* address: 0xF005130C */
		MTU_MC6ERRINFO2_T MTU_MC6ERRINFO2;

		/* address: 0xF0051310 */
		MTU_MC6ERRINFO3_T MTU_MC6ERRINFO3;

		/* address: 0xF0051314 */
		MTU_MC6ERRINFO4_T MTU_MC6ERRINFO4;

		/* address: 0xF0051318 */
		uint8_t MTU_RESERVED_F0051318[80];

		/* address: 0xF0051368 */
		MTU_MC7ERRINFO0_T MTU_MC7ERRINFO0;

		/* address: 0xF005136C */
		MTU_MC7ERRINFO1_T MTU_MC7ERRINFO1;

		/* address: 0xF0051370 */
		MTU_MC7ERRINFO2_T MTU_MC7ERRINFO2;

		/* address: 0xF0051374 */
		MTU_MC7ERRINFO3_T MTU_MC7ERRINFO3;

		/* address: 0xF0051378 */
		MTU_MC7ERRINFO4_T MTU_MC7ERRINFO4;

		/* address: 0xF005137C */
		uint8_t MTU_RESERVED_F005137C[80];

		/* address: 0xF00513CC */
		MTU_MC8ERRINFO0_T MTU_MC8ERRINFO0;

		/* address: 0xF00513D0 */
		MTU_MC8ERRINFO1_T MTU_MC8ERRINFO1;

		/* address: 0xF00513D4 */
		MTU_MC8ERRINFO2_T MTU_MC8ERRINFO2;

		/* address: 0xF00513D8 */
		MTU_MC8ERRINFO3_T MTU_MC8ERRINFO3;

		/* address: 0xF00513DC */
		MTU_MC8ERRINFO4_T MTU_MC8ERRINFO4;

		/* address: 0xF00513E0 */
		uint8_t MTU_RESERVED_F00513E0[80];

		/* address: 0xF0051430 */
		MTU_MC9ERRINFO0_T MTU_MC9ERRINFO0;

		/* address: 0xF0051434 */
		MTU_MC9ERRINFO1_T MTU_MC9ERRINFO1;

		/* address: 0xF0051438 */
		MTU_MC9ERRINFO2_T MTU_MC9ERRINFO2;

		/* address: 0xF005143C */
		MTU_MC9ERRINFO3_T MTU_MC9ERRINFO3;

		/* address: 0xF0051440 */
		MTU_MC9ERRINFO4_T MTU_MC9ERRINFO4;

		/* address: 0xF0051444 */
		uint8_t MTU_RESERVED_F0051444[80];

		/* address: 0xF0051494 */
		MTU_MC10ERRINFO0_T MTU_MC10ERRINFO0;

		/* address: 0xF0051498 */
		MTU_MC10ERRINFO1_T MTU_MC10ERRINFO1;

		/* address: 0xF005149C */
		MTU_MC10ERRINFO2_T MTU_MC10ERRINFO2;

		/* address: 0xF00514A0 */
		MTU_MC10ERRINFO3_T MTU_MC10ERRINFO3;

		/* address: 0xF00514A4 */
		MTU_MC10ERRINFO4_T MTU_MC10ERRINFO4;

		/* address: 0xF00514A8 */
		uint8_t MTU_RESERVED_F00514A8[80];

		/* address: 0xF00514F8 */
		MTU_MC11ERRINFO0_T MTU_MC11ERRINFO0;

		/* address: 0xF00514FC */
		MTU_MC11ERRINFO1_T MTU_MC11ERRINFO1;

		/* address: 0xF0051500 */
		MTU_MC11ERRINFO2_T MTU_MC11ERRINFO2;

		/* address: 0xF0051504 */
		MTU_MC11ERRINFO3_T MTU_MC11ERRINFO3;

		/* address: 0xF0051508 */
		MTU_MC11ERRINFO4_T MTU_MC11ERRINFO4;

		/* address: 0xF005150C */
		uint8_t MTU_RESERVED_F005150C[80];

		/* address: 0xF005155C */
		MTU_MC12ERRINFO0_T MTU_MC12ERRINFO0;

		/* address: 0xF0051560 */
		MTU_MC12ERRINFO1_T MTU_MC12ERRINFO1;

		/* address: 0xF0051564 */
		MTU_MC12ERRINFO2_T MTU_MC12ERRINFO2;

		/* address: 0xF0051568 */
		MTU_MC12ERRINFO3_T MTU_MC12ERRINFO3;

		/* address: 0xF005156C */
		MTU_MC12ERRINFO4_T MTU_MC12ERRINFO4;

		/* address: 0xF0051570 */
		uint8_t MTU_RESERVED_F0051570[80];

		/* address: 0xF00515C0 */
		MTU_MC13ERRINFO0_T MTU_MC13ERRINFO0;

		/* address: 0xF00515C4 */
		MTU_MC13ERRINFO1_T MTU_MC13ERRINFO1;

		/* address: 0xF00515C8 */
		MTU_MC13ERRINFO2_T MTU_MC13ERRINFO2;

		/* address: 0xF00515CC */
		MTU_MC13ERRINFO3_T MTU_MC13ERRINFO3;

		/* address: 0xF00515D0 */
		MTU_MC13ERRINFO4_T MTU_MC13ERRINFO4;

		/* address: 0xF00515D4 */
		uint8_t MTU_RESERVED_F00515D4[80];

		/* address: 0xF0051624 */
		MTU_MC14ERRINFO0_T MTU_MC14ERRINFO0;

		/* address: 0xF0051628 */
		MTU_MC14ERRINFO1_T MTU_MC14ERRINFO1;

		/* address: 0xF005162C */
		MTU_MC14ERRINFO2_T MTU_MC14ERRINFO2;

		/* address: 0xF0051630 */
		MTU_MC14ERRINFO3_T MTU_MC14ERRINFO3;

		/* address: 0xF0051634 */
		MTU_MC14ERRINFO4_T MTU_MC14ERRINFO4;

		/* address: 0xF0051638 */
		uint8_t MTU_RESERVED_F0051638[80];

		/* address: 0xF0051688 */
		MTU_MC15ERRINFO0_T MTU_MC15ERRINFO0;

		/* address: 0xF005168C */
		MTU_MC15ERRINFO1_T MTU_MC15ERRINFO1;

		/* address: 0xF0051690 */
		MTU_MC15ERRINFO2_T MTU_MC15ERRINFO2;

		/* address: 0xF0051694 */
		MTU_MC15ERRINFO3_T MTU_MC15ERRINFO3;

		/* address: 0xF0051698 */
		MTU_MC15ERRINFO4_T MTU_MC15ERRINFO4;

		/* address: 0xF00510C0 */
		MTU_MC0IND0_T MTU_MC0IND0;

		/* address: 0xF00510C4 */
		MTU_MC0IND1_T MTU_MC0IND1;

		/* address: 0xF00510C8 */
		MTU_MC0IND2_T MTU_MC0IND2;

		/* address: 0xF00510CC */
		uint8_t MTU_RESERVED_F00510CC[88];

		/* address: 0xF0051124 */
		MTU_MC1IND0_T MTU_MC1IND0;

		/* address: 0xF0051128 */
		MTU_MC1IND1_T MTU_MC1IND1;

		/* address: 0xF005112C */
		MTU_MC1IND2_T MTU_MC1IND2;

		/* address: 0xF0051130 */
		uint8_t MTU_RESERVED_F0051130[88];

		/* address: 0xF0051188 */
		MTU_MC2IND0_T MTU_MC2IND0;

		/* address: 0xF005118C */
		MTU_MC2IND1_T MTU_MC2IND1;

		/* address: 0xF0051190 */
		MTU_MC2IND2_T MTU_MC2IND2;

		/* address: 0xF0051194 */
		uint8_t MTU_RESERVED_F0051194[88];

		/* address: 0xF00511EC */
		MTU_MC3IND0_T MTU_MC3IND0;

		/* address: 0xF00511F0 */
		MTU_MC3IND1_T MTU_MC3IND1;

		/* address: 0xF00511F4 */
		MTU_MC3IND2_T MTU_MC3IND2;

		/* address: 0xF00511F8 */
		uint8_t MTU_RESERVED_F00511F8[88];

		/* address: 0xF0051250 */
		MTU_MC4IND0_T MTU_MC4IND0;

		/* address: 0xF0051254 */
		MTU_MC4IND1_T MTU_MC4IND1;

		/* address: 0xF0051258 */
		MTU_MC4IND2_T MTU_MC4IND2;

		/* address: 0xF005125C */
		uint8_t MTU_RESERVED_F005125C[88];

		/* address: 0xF00512B4 */
		MTU_MC5IND0_T MTU_MC5IND0;

		/* address: 0xF00512B8 */
		MTU_MC5IND1_T MTU_MC5IND1;

		/* address: 0xF00512BC */
		MTU_MC5IND2_T MTU_MC5IND2;

		/* address: 0xF00512C0 */
		uint8_t MTU_RESERVED_F00512C0[88];

		/* address: 0xF0051318 */
		MTU_MC6IND0_T MTU_MC6IND0;

		/* address: 0xF005131C */
		MTU_MC6IND1_T MTU_MC6IND1;

		/* address: 0xF0051320 */
		MTU_MC6IND2_T MTU_MC6IND2;

		/* address: 0xF0051324 */
		uint8_t MTU_RESERVED_F0051324[88];

		/* address: 0xF005137C */
		MTU_MC7IND0_T MTU_MC7IND0;

		/* address: 0xF0051380 */
		MTU_MC7IND1_T MTU_MC7IND1;

		/* address: 0xF0051384 */
		MTU_MC7IND2_T MTU_MC7IND2;

		/* address: 0xF0051388 */
		uint8_t MTU_RESERVED_F0051388[88];

		/* address: 0xF00513E0 */
		MTU_MC8IND0_T MTU_MC8IND0;

		/* address: 0xF00513E4 */
		MTU_MC8IND1_T MTU_MC8IND1;

		/* address: 0xF00513E8 */
		MTU_MC8IND2_T MTU_MC8IND2;

		/* address: 0xF00513EC */
		uint8_t MTU_RESERVED_F00513EC[88];

		/* address: 0xF0051444 */
		MTU_MC9IND0_T MTU_MC9IND0;

		/* address: 0xF0051448 */
		MTU_MC9IND1_T MTU_MC9IND1;

		/* address: 0xF005144C */
		MTU_MC9IND2_T MTU_MC9IND2;

		/* address: 0xF0051450 */
		uint8_t MTU_RESERVED_F0051450[88];

		/* address: 0xF00514A8 */
		MTU_MC10IND0_T MTU_MC10IND0;

		/* address: 0xF00514AC */
		MTU_MC10IND1_T MTU_MC10IND1;

		/* address: 0xF00514B0 */
		MTU_MC10IND2_T MTU_MC10IND2;

		/* address: 0xF00514B4 */
		uint8_t MTU_RESERVED_F00514B4[88];

		/* address: 0xF005150C */
		MTU_MC11IND0_T MTU_MC11IND0;

		/* address: 0xF0051510 */
		MTU_MC11IND1_T MTU_MC11IND1;

		/* address: 0xF0051514 */
		MTU_MC11IND2_T MTU_MC11IND2;

		/* address: 0xF0051518 */
		uint8_t MTU_RESERVED_F0051518[88];

		/* address: 0xF0051570 */
		MTU_MC12IND0_T MTU_MC12IND0;

		/* address: 0xF0051574 */
		MTU_MC12IND1_T MTU_MC12IND1;

		/* address: 0xF0051578 */
		MTU_MC12IND2_T MTU_MC12IND2;

		/* address: 0xF005157C */
		uint8_t MTU_RESERVED_F005157C[88];

		/* address: 0xF00515D4 */
		MTU_MC13IND0_T MTU_MC13IND0;

		/* address: 0xF00515D8 */
		MTU_MC13IND1_T MTU_MC13IND1;

		/* address: 0xF00515DC */
		MTU_MC13IND2_T MTU_MC13IND2;

		/* address: 0xF00515E0 */
		uint8_t MTU_RESERVED_F00515E0[88];

		/* address: 0xF0051638 */
		MTU_MC14IND0_T MTU_MC14IND0;

		/* address: 0xF005163C */
		MTU_MC14IND1_T MTU_MC14IND1;

		/* address: 0xF0051640 */
		MTU_MC14IND2_T MTU_MC14IND2;

		/* address: 0xF0051644 */
		uint8_t MTU_RESERVED_F0051644[88];

		/* address: 0xF005169C */
		MTU_MC15IND0_T MTU_MC15IND0;

		/* address: 0xF00516A0 */
		MTU_MC15IND1_T MTU_MC15IND1;

		/* address: 0xF00516A4 */
		MTU_MC15IND2_T MTU_MC15IND2;

		/* address: 0xF00510D0 */
		MTU_MC0INJERR0_T MTU_MC0INJERR0;

		/* address: 0xF00510D4 */
		MTU_MC0INJERR1_T MTU_MC0INJERR1;

		/* address: 0xF00510D8 */
		MTU_MC0INJERR2_T MTU_MC0INJERR2;

		/* address: 0xF00510DC */
		uint8_t MTU_RESERVED_F00510DC[88];

		/* address: 0xF0051134 */
		MTU_MC1INJERR0_T MTU_MC1INJERR0;

		/* address: 0xF0051138 */
		MTU_MC1INJERR1_T MTU_MC1INJERR1;

		/* address: 0xF005113C */
		MTU_MC1INJERR2_T MTU_MC1INJERR2;

		/* address: 0xF0051140 */
		uint8_t MTU_RESERVED_F0051140[88];

		/* address: 0xF0051198 */
		MTU_MC2INJERR0_T MTU_MC2INJERR0;

		/* address: 0xF005119C */
		MTU_MC2INJERR1_T MTU_MC2INJERR1;

		/* address: 0xF00511A0 */
		MTU_MC2INJERR2_T MTU_MC2INJERR2;

		/* address: 0xF00511A4 */
		uint8_t MTU_RESERVED_F00511A4[88];

		/* address: 0xF00511FC */
		MTU_MC3INJERR0_T MTU_MC3INJERR0;

		/* address: 0xF0051200 */
		MTU_MC3INJERR1_T MTU_MC3INJERR1;

		/* address: 0xF0051204 */
		MTU_MC3INJERR2_T MTU_MC3INJERR2;

		/* address: 0xF0051208 */
		uint8_t MTU_RESERVED_F0051208[88];

		/* address: 0xF0051260 */
		MTU_MC4INJERR0_T MTU_MC4INJERR0;

		/* address: 0xF0051264 */
		MTU_MC4INJERR1_T MTU_MC4INJERR1;

		/* address: 0xF0051268 */
		MTU_MC4INJERR2_T MTU_MC4INJERR2;

		/* address: 0xF005126C */
		uint8_t MTU_RESERVED_F005126C[88];

		/* address: 0xF00512C4 */
		MTU_MC5INJERR0_T MTU_MC5INJERR0;

		/* address: 0xF00512C8 */
		MTU_MC5INJERR1_T MTU_MC5INJERR1;

		/* address: 0xF00512CC */
		MTU_MC5INJERR2_T MTU_MC5INJERR2;

		/* address: 0xF00512D0 */
		uint8_t MTU_RESERVED_F00512D0[88];

		/* address: 0xF0051328 */
		MTU_MC6INJERR0_T MTU_MC6INJERR0;

		/* address: 0xF005132C */
		MTU_MC6INJERR1_T MTU_MC6INJERR1;

		/* address: 0xF0051330 */
		MTU_MC6INJERR2_T MTU_MC6INJERR2;

		/* address: 0xF0051334 */
		uint8_t MTU_RESERVED_F0051334[88];

		/* address: 0xF005138C */
		MTU_MC7INJERR0_T MTU_MC7INJERR0;

		/* address: 0xF0051390 */
		MTU_MC7INJERR1_T MTU_MC7INJERR1;

		/* address: 0xF0051394 */
		MTU_MC7INJERR2_T MTU_MC7INJERR2;

		/* address: 0xF0051398 */
		uint8_t MTU_RESERVED_F0051398[88];

		/* address: 0xF00513F0 */
		MTU_MC8INJERR0_T MTU_MC8INJERR0;

		/* address: 0xF00513F4 */
		MTU_MC8INJERR1_T MTU_MC8INJERR1;

		/* address: 0xF00513F8 */
		MTU_MC8INJERR2_T MTU_MC8INJERR2;

		/* address: 0xF00513FC */
		uint8_t MTU_RESERVED_F00513FC[88];

		/* address: 0xF0051454 */
		MTU_MC9INJERR0_T MTU_MC9INJERR0;

		/* address: 0xF0051458 */
		MTU_MC9INJERR1_T MTU_MC9INJERR1;

		/* address: 0xF005145C */
		MTU_MC9INJERR2_T MTU_MC9INJERR2;

		/* address: 0xF0051460 */
		uint8_t MTU_RESERVED_F0051460[88];

		/* address: 0xF00514B8 */
		MTU_MC10INJERR0_T MTU_MC10INJERR0;

		/* address: 0xF00514BC */
		MTU_MC10INJERR1_T MTU_MC10INJERR1;

		/* address: 0xF00514C0 */
		MTU_MC10INJERR2_T MTU_MC10INJERR2;

		/* address: 0xF00514C4 */
		uint8_t MTU_RESERVED_F00514C4[88];

		/* address: 0xF005151C */
		MTU_MC11INJERR0_T MTU_MC11INJERR0;

		/* address: 0xF0051520 */
		MTU_MC11INJERR1_T MTU_MC11INJERR1;

		/* address: 0xF0051524 */
		MTU_MC11INJERR2_T MTU_MC11INJERR2;

		/* address: 0xF0051528 */
		uint8_t MTU_RESERVED_F0051528[88];

		/* address: 0xF0051580 */
		MTU_MC12INJERR0_T MTU_MC12INJERR0;

		/* address: 0xF0051584 */
		MTU_MC12INJERR1_T MTU_MC12INJERR1;

		/* address: 0xF0051588 */
		MTU_MC12INJERR2_T MTU_MC12INJERR2;

		/* address: 0xF005158C */
		uint8_t MTU_RESERVED_F005158C[88];

		/* address: 0xF00515E4 */
		MTU_MC13INJERR0_T MTU_MC13INJERR0;

		/* address: 0xF00515E8 */
		MTU_MC13INJERR1_T MTU_MC13INJERR1;

		/* address: 0xF00515EC */
		MTU_MC13INJERR2_T MTU_MC13INJERR2;

		/* address: 0xF00515F0 */
		uint8_t MTU_RESERVED_F00515F0[88];

		/* address: 0xF0051648 */
		MTU_MC14INJERR0_T MTU_MC14INJERR0;

		/* address: 0xF005164C */
		MTU_MC14INJERR1_T MTU_MC14INJERR1;

		/* address: 0xF0051650 */
		MTU_MC14INJERR2_T MTU_MC14INJERR2;

		/* address: 0xF0051654 */
		uint8_t MTU_RESERVED_F0051654[88];

		/* address: 0xF00516AC */
		MTU_MC15INJERR0_T MTU_MC15INJERR0;

		/* address: 0xF00516B0 */
		MTU_MC15INJERR1_T MTU_MC15INJERR1;

		/* address: 0xF00516B4 */
		MTU_MC15INJERR2_T MTU_MC15INJERR2;
	} Mtu_RegisterMap_t;

#define MTU_ADDR ((uint32_t)0xF0050000)
#define MTU_PTR ((Mtu_RegisterMap_t *)MTU_ADDR)
#define MTU_RM (*(Mtu_RegisterMap_t *)MTU_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
