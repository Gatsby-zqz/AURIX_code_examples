/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_cscb.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyright protected and proprietary to
 * Shanghai ChipON Micro-Electronic Co.,Ltd
 **************************************************************************/

#ifndef _KF32DA13K_REG_CSCB_H_
#define _KF32DA13K_REG_CSCB_H_

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
				__IO uint32_t MDEN : 1;	  /*!< [0:0] 模块使能控制位用于使能或禁止该模块的控制，模拟部分通过清除ANONS位域进行禁止操作  */
				__I uint32_t MDENSTA : 1; /*!< [1:1] 模块状态指示位  */
				__I uint32_t : 1;		  /*!< [2:2] 预留读为0  */
				__IO uint32_t SMEN : 1;	  /*!< [3:3] 睡眠模式使能控制用于控制模块对睡眠信号的反应情况  */
				__I uint32_t : 28;		  /*!< [31:4] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} CSCB_CLKC_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MDREV : 8;		/*!< [7:0] 模块的版本号  */
				__I uint32_t MOTYPE : 8;	/*!< [15:8] 模块的类型  */
				__I uint32_t MDNUMBER : 16; /*!< [31:16] 模块的数量  */
			} bits;
			__IO uint32_t reg;
		};
	} CSCB_ID_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t : 24;		 /*!< [23:0] 预留读为0  */
				__IO uint32_t SPCTL : 4; /*!< [27:24] 当OCDS触发器开关产生的挂起信号到来时，挂起状态模式选择控制  */
				__O uint32_t SPCTLP : 1; /*!< [28:28] SPCTL位域的写保护权限，只有当SPCTLP置1时，SPCTL才能被写入配置信息，否则该位域无法写入配置信息，读为0。  */
				__I uint32_t SPSTA : 1;	 /*!< [29:29] 该模块是否进入挂起状态  */
				__I uint32_t : 2;		 /*!< [31:30] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} CSCB_OCS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__O uint32_t RSTACLR : 1; /*!< [0:0] 对复位状态标志位CCB_RST0.RSTSTAT进行清零  */
				__I uint32_t : 31;		  /*!< [31:1] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} CSCB_RSTCLR_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t RST : 1; /*!< [0:0] 模块复位控制，只有当与CCB_RST0.RST都同时配置为1时，才能产生一个模块复位。  */
				__I uint32_t : 31;	   /*!< [31:1] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} CSCB_RST1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t RST : 1;	  /*!< [0:0] 模块复位控制，只有当与CCB_RST1.RST都同时配置为1时，才能产生一个模块复位。  */
				__I uint32_t RSTSTAT : 1; /*!< [1:1] 模块复位状态指示位，该位域可以通过CONOVER_RSTCLR.CLR置1进行清除  */
				__I uint32_t : 30;		  /*!< [31:2] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} CSCB_RST0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EN0 : 1;	/*!< [0:0] 权限使能用于主控制方TAGID0  */
				__IO uint32_t EN1 : 1;	/*!< [1:1] 权限使能用于主控制方TAGID1  */
				__IO uint32_t EN2 : 1;	/*!< [2:2] 权限使能用于主控制方TAGID2  */
				__IO uint32_t EN3 : 1;	/*!< [3:3] 权限使能用于主控制方TAGID3  */
				__IO uint32_t EN4 : 1;	/*!< [4:4] 权限使能用于主控制方TAGID4  */
				__IO uint32_t EN5 : 1;	/*!< [5:5] 权限使能用于主控制方TAGID5  */
				__IO uint32_t EN6 : 1;	/*!< [6:6] 权限使能用于主控制方TAGID6  */
				__IO uint32_t EN7 : 1;	/*!< [7:7] 权限使能用于主控制方TAGID7  */
				__IO uint32_t EN8 : 1;	/*!< [8:8] 权限使能用于主控制方TAGID8  */
				__IO uint32_t EN9 : 1;	/*!< [9:9] 权限使能用于主控制方TAGID9  */
				__IO uint32_t EN10 : 1; /*!< [10:10] 权限使能用于主控制方TAGID10  */
				__IO uint32_t EN11 : 1; /*!< [11:11] 权限使能用于主控制方TAGID11  */
				__IO uint32_t EN12 : 1; /*!< [12:12] 权限使能用于主控制方TAGID12  */
				__IO uint32_t EN13 : 1; /*!< [13:13] 权限使能用于主控制方TAGID13  */
				__IO uint32_t EN14 : 1; /*!< [14:14] 权限使能用于主控制方TAGID14  */
				__IO uint32_t EN15 : 1; /*!< [15:15] 权限使能用于主控制方TAGID15  */
				__IO uint32_t EN16 : 1; /*!< [16:16] 权限使能用于主控制方TAGID16  */
				__IO uint32_t EN17 : 1; /*!< [17:17] 权限使能用于主控制方TAGID17  */
				__IO uint32_t EN18 : 1; /*!< [18:18] 权限使能用于主控制方TAGID18  */
				__IO uint32_t EN19 : 1; /*!< [19:19] 权限使能用于主控制方TAGID19  */
				__IO uint32_t EN20 : 1; /*!< [20:20] 权限使能用于主控制方TAGID20  */
				__IO uint32_t EN21 : 1; /*!< [21:21] 权限使能用于主控制方TAGID21  */
				__IO uint32_t EN22 : 1; /*!< [22:22] 权限使能用于主控制方TAGID22  */
				__IO uint32_t EN23 : 1; /*!< [23:23] 权限使能用于主控制方TAGID23  */
				__IO uint32_t EN24 : 1; /*!< [24:24] 权限使能用于主控制方TAGID24  */
				__IO uint32_t EN25 : 1; /*!< [25:25] 权限使能用于主控制方TAGID25  */
				__IO uint32_t EN26 : 1; /*!< [26:26] 权限使能用于主控制方TAGID26  */
				__IO uint32_t EN27 : 1; /*!< [27:27] 权限使能用于主控制方TAGID27  */
				__IO uint32_t EN28 : 1; /*!< [28:28] 权限使能用于主控制方TAGID28  */
				__IO uint32_t EN29 : 1; /*!< [29:29] 权限使能用于主控制方TAGID29  */
				__IO uint32_t EN30 : 1; /*!< [30:30] 权限使能用于主控制方TAGID30  */
				__IO uint32_t EN31 : 1; /*!< [31:31] 权限使能用于主控制方TAGID31  */
			} bits;
			__IO uint32_t reg;
		};
	} CSCB_ACCEN0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t : 28;		/*!< [27:0] 预留读为0  */
				__IO uint32_t WTPO : 4; /*!< [31:28] 该模块内的寄存器写权限保护控制位，当该位域配置为BH时，该模块内的寄存器的写权限被打开。  */
			} bits;
			__IO uint32_t reg;
		};
	} CSCB_WITPOT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t PHSPDIV : 4; /*!< [3:0] 相位同步器计数器计数值/分频值  */
				__I uint32_t : 11;		   /*!< [14:4] 预留读为0  */
				__O uint32_t PDWC : 1;	   /*!< [15:15] PHSPDIV位域写权限控制  */
				__I uint32_t : 16;		   /*!< [31:16] 预留读为0  */
			} bits;
			__IO uint32_t reg;
		};
	} CSCB_PHSYCTL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t ALF : 1;	 /*!< [0:0] 警告标志位，当安全机制触发了告警信号时，就会将该标志位置1。  */
				__I uint32_t : 3;		 /*!< [3:1] 预留读为0  */
				__O uint32_t SWPD0 : 1;	 /*!< [4:4] 软件写入奇偶校验错误  */
				__O uint32_t SWC0 : 1;	 /*!< [5:5] 软件写入计数错误  */
				__I uint32_t : 10;		 /*!< [15:6] 预留读为0  */
				__O uint32_t ALFCLR : 1; /*!< [16:16] 对CCB_SAFETY.ALF位域进行清零  */
				__I uint32_t : 3;		 /*!< [19:17] 预留读为0  */
				__O uint32_t SWPD1 : 1;	 /*!< [20:20] 软件写入奇偶校验错误  */
				__O uint32_t SWC1 : 1;	 /*!< [21:21] 软件写入计数错误  */
			} bits;
			__IO uint32_t reg;
		};
	} CSCB_SAFETY_T;

	typedef volatile struct
	{
		/* address: 0xF0000000 */
		CSCB_CLKC_T CSCB_CLKC;

		/* address: 0xF0000004 */
		CSCB_ID_T CSCB_ID;

		/* address: 0xF0000008 */
		CSCB_OCS_T CSCB_OCS;

		/* address: 0xF000000C */
		CSCB_RSTCLR_T CSCB_RSTCLR;

		/* address: 0xF0000010 */
		CSCB_RST1_T CSCB_RST1;

		/* address: 0xF0000014 */
		CSCB_RST0_T CSCB_RST0;

		/* address: 0xF0000018 */
		CSCB_ACCEN0_T CSCB_ACCEN0;

		/* address: 0xF000001C */
		CSCB_WITPOT_T CSCB_WITPOT;

		/* address: 0xF0000020 */
		CSCB_PHSYCTL_T CSCB_PHSYCTL;

		/* address: 0xF0000024 */
		CSCB_SAFETY_T CSCB_SAFETY;
	} Cscb_RegisterMap_t;

#define CSCB_ADDR ((uint32_t)0xF0000000)
#define CSCB_PTR ((Cscb_RegisterMap_t *)CSCB_ADDR)
#define CSCB_RM (*(Cscb_RegisterMap_t *)CSCB_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
