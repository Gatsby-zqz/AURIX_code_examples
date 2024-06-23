/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_ram.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyrght protected and proprietary to 
 * Shanghai ChipON Micro-Electronic Co.,Ltd 
 **************************************************************************/

#ifndef _KF32DA13K_REG_RAM_H_
#define _KF32DA13K_REG_RAM_H_

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
			__IO uint32_t	LADDR: 32; /*!< [31:0] RAM权限控制范围寄存器0下限  */
		}bits;
		__IO uint32_t reg;
	};
} RAM_RGNLA_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	UADDR: 32; /*!< [31:0] RAM权限控制范围寄存器0上限  */
		}bits;
		__IO uint32_t reg;
	};
} RAM_RGNUA_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	WEN: 32; /*!< [31:0] RAM权限控制写使能寄存器A  */
		}bits;
		__IO uint32_t reg;
	};
} RAM_RGNACCENA_W_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	WEN: 32; /*!< [31:0] RAM权限控制写使能寄存器B  */
		}bits;
		__IO uint32_t reg;
	};
} RAM_RGNACCENB_W_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	REN: 32; /*!< [31:0] RAM权限控制读使能寄存器A  */
		}bits;
		__IO uint32_t reg;
	};
} RAM_RGNACCENA_R_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	REN: 32; /*!< [31:0] RAM权限控制读使能寄存器B  */
		}bits;
		__IO uint32_t reg;
	};
} RAM_RGNACCENB_R_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	VCSB: 1; /*!< [0:0] vcsb  */
			__IO uint32_t	SWR: 2; /*!< [2:1] SWR  */
			__IO uint32_t	SRD: 2; /*!< [4:3] SRD  */
			__IO uint32_t	RCEL_N: 1; /*!< [5:5] RCEL_N  */
			__IO uint32_t	RCER_N: 1; /*!< [6:6] RCER_N  */
			__IO uint32_t	RCAL: 8; /*!< [14:7] RCAL  */
			__IO uint32_t	RCAR: 8; /*!< [22:15] RCAR  */
			__IO uint32_t	RESERVED0: 9; /*!< [31:23] 预留读为0  */
		}bits;
		__IO uint32_t reg;
	};
} RAM_CFG_T;

typedef volatile struct
{
	/*offset address: 0x0000, RAM权限控制地址范围寄存器0 */
	RAM_RGNLA_T RAM_RGNLA[8];

	/*offset address: 0x0020, RAM权限控制地址范围寄存器1 */
	RAM_RGNUA_T RAM_RGNUA[8];

	/*offset address: 0x0040, RAM权限控制写使能寄存器A */
	RAM_RGNACCENA_W_T RAM_RGNACCENA_W[8];

	/*offset address: 0x0060, RAM权限控制写使能寄存器B */
	RAM_RGNACCENB_W_T RAM_RGNACCENB_W[8];

	/*offset address: 0x0080, RAM权限控制读使能寄存器A */
	RAM_RGNACCENA_R_T RAM_RGNACCENA_R[8];

	/*offset address: 0x00A0, RAM权限控制读使能寄存器B */
	RAM_RGNACCENB_R_T RAM_RGNACCENB_R[8];

	/*offset address: 0x00C0, RAM配置寄存器 */
	RAM_CFG_T RAM_CFG[8];
} Ram_RegisterMap_t;

#define RAM_ADDR ((uint32_t)0xF9003000)
#define RAM_PTR ((Ram_RegisterMap_t *)RAM_ADDR)
#define RAM_RM (*(Ram_RegisterMap_t *)RAM_ADDR)


#ifdef __cplusplus
}
#endif

#endif
/* EOF */
