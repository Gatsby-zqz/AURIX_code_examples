/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_lbist.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyrght protected and proprietary to 
 * Shanghai ChipON Micro-Electronic Co.,Ltd 
 **************************************************************************/

#ifndef _KF32DA13K_REG_LBIST_H_
#define _KF32DA13K_REG_LBIST_H_

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
			__O uint32_t	REQ: 1; /*!< [0:0] LBIST请求  */
			__O uint32_t	RST: 1; /*!< [1:1] LBIST重置  */
			__IO uint32_t	BODY: 1; /*!< [2:2] 管脚状态值  */
			__I uint32_t	RESERVED0: 1; /*!< [3:3]   */
			__IO uint32_t	FREQ: 4; /*!< [7:4] 选择LBIST频率  */
			__I uint32_t	RESERVED1: 22; /*!< [29:8]   */
			__IO uint32_t	ERRINJ: 1; /*!< [30:30] LBIST/测试模式报警错误注入  */
			__IO uint32_t	REQRED: 1; /*!< [31:31] LBIST请求冗余  */
		}bits;
		__IO uint32_t reg;
	};
} SCU_LBISTCTL_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__I uint32_t	DONE: 1; /*!< [0:0] LBIST执行状态指示  */
			__I uint32_t	RESERVED0: 31; /*!< [31:1]   */
		}bits;
		__I uint32_t reg;
	};
} SCU_LBISTSTA_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	NUM: 18; /*!< [17:0] LBIST测试Pattern数量  */
			__I uint32_t	RESERVED0: 14; /*!< [31:18]   */
		}bits;
		__IO uint32_t reg;
	};
} SCU_LBISTPAT_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	SEED: 19; /*!< [18:0] LBIST种子  */
			__IO uint32_t	SPLITSH: 3; /*!< [21:19] LBIST分组移位选择此位域值将允许通过分组扫描移位操作方式运行LBIST  */
			__I uint32_t	RESERVED0: 10; /*!< [31:22]   */
		}bits;
		__IO uint32_t reg;
	};
} SCU_LBISTSEED_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__IO uint32_t	LENGTH: 16; /*!< [15:0] LBIST最大扫描链长度  */
			__I uint32_t	RESERVED0: 16; /*!< [31:16]   */
		}bits;
		__IO uint32_t reg;
	};
} SCU_LBISTSC_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__I uint32_t	SIGNATURE: 32; /*!< [31:0] 此位域指示最后次LBIST执行的MISR签名  */
		}bits;
		__I uint32_t reg;
	};
} SCU_LBISTSIG_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__I uint32_t	LBPORST: 1; /*!< [27:27] PORST而导致的LBIST终止  */
			__I uint32_t	LBTERM: 1; /*!< [28:28] LBIST已正确终止  */
		}bits;
		__I uint32_t reg;
	};
} RCU_STA_T;

typedef volatile struct
{
	union
	{
		struct
		{
			__O uint32_t	COLDCLR: 1; /*!< [1:1] 复位触发源状态寄存器RCU_STA中冷复位状态位清除设置  */
		}bits;
		__O uint32_t reg;
	};
} RCU_CTL1_T;

typedef volatile struct
{
	/*offset address: 0x0028, 逻辑BIST控制寄存器 */
	SCU_LBISTCTL_T SCU_LBISTCTL;

	/*offset address: 0x002C, 逻辑BIST状态寄存器 */
	SCU_LBISTSTA_T SCU_LBISTSTA;

	/*offset address: 0x0030, 逻辑BIST测试图形寄存器 */
	SCU_LBISTPAT_T SCU_LBISTPAT;

	/*offset address: 0x0034, 逻辑BIST种子寄存器 */
	SCU_LBISTSEED_T SCU_LBISTSEED;

	/*offset address: 0x0038, 逻辑BIST扫描链寄存器 */
	SCU_LBISTSC_T SCU_LBISTSC;

	/*offset address: 0x003C, 逻辑BIST签名寄存器 */
	SCU_LBISTSIG_T SCU_LBISTSIG;

	/*offset address: 0x0040, 复位状态寄存器 */
	uint8_t LBIST_RESERVED_0040[236];

	/*offset address: 0x012C, 复位状态寄存器 */
	RCU_STA_T RCU_STA;

	/*offset address: 0x0130, 复位配置寄存器1 */
	uint8_t LBIST_RESERVED_0130[12];

	/*offset address: 0x013C, 复位配置寄存器1 */
	RCU_CTL1_T RCU_CTL1;
} Lbist_RegisterMap_t;

#define LBIST_ADDR ((uint32_t)0xF0036000)
#define LBIST_PTR ((Lbist_RegisterMap_t *)LBIST_ADDR)
#define LBIST_RM (*(Lbist_RegisterMap_t *)LBIST_ADDR)


#ifdef __cplusplus
}
#endif

#endif
/* EOF */
