/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_spi.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-04-10
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
 *  |2023-04-10  |V1.0     |Wang Jianzhong  | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_DRV_SPI_H_
#define _KF32DA13K_DRV_SPI_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *         Include Files 
 **************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a13k_reg_spi.h"
#include "kf32a13k_drv_spi_enum.h"

#ifdef KF_DRV_SPI_ASSERT
#include "dev_assert.h"
#define KF_SPI_ASSERT(x) KF_DRV_ASSERT(x)
#else
#define KF_SPI_ASSERT(x) ((void)0U)
#endif
/**************************************************************************
 *         Export Functions 
 **************************************************************************/
/* SPI_CLKC_T */

/**
 * @brief 设置SPI模块禁止控制位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 模块禁止控制位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetModuleDisabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CLKC.bits.DISR, State);
}

/**
 * @brief 读取SPI模块禁止状态
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 模块禁止状态
 */
KF_INLINE uint32_t Spi_LL_GetModuleStatus(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_CLKC.bits.DISS);
}

/**
 * @brief 设置SPI休眠模式禁止位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 休眠模式禁止位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetSleepModeForbidden(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CLKC.bits.EDIS, State);
}

/* SPI_DBG_T */

/**
 * @brief 设置SPI调试模式挂起控制
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] DBGCTLValue 调试模式挂起控制
 *            0H 没有挂起
 *            1H 硬件挂起，时钟关闭
 *            2H 软件挂起
 * @return void
 */
KF_INLINE void Spi_LL_SetDebugModeHangsControl(Spi_RegisterMap_t *const Module, Spi_Dbg_Dbgctl_Id_t DBGCTLValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_DBG_DBGCTL_ID(DBGCTLValue));

	REG_WRITE(Module->SPI_DBG.bits.DBGCTL, DBGCTLValue);
}

/**
 * @brief 设置SPIDBGCTL位写保护，读出为0
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State DBGCTL位写保护，读出为0
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetDBGCTLWriteProtectEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_DBG.bits.DBGP, State);
}

/**
 * @brief 读取SPIDEBUG状态位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return DEBUG状态位
 */
KF_INLINE uint32_t Spi_LL_GetDebugStatus(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_DBG.bits.DBGSTA);
}

/* SPI_RST0_T */

/**
 * @brief 设置SPI模块复位请求位，与RST1寄存器的RST位一起使用
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 模块复位请求位，与RST1寄存器的RST位一起使用
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetModuleReset0Enabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_RST0.bits.RST, State);
}

/**
 * @brief 读取SPI复位状态
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 复位状态
 */
KF_INLINE uint32_t Spi_LL_GetResetState(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_RST0.bits.RSTSTA);
}

/* SPI_RST1_T */

/**
 * @brief 设置SPI模块复位请求位，与RST0寄存器的RST位一起使用
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 模块复位请求位，与RST0寄存器的RST位一起使用
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetModuleReset1Enabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_RST1.bits.RST, State);
}

/* SPI_RSTCLR_T */

/**
 * @brief 设置SPIRSTSTA复位状态清除位，读出为0
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State RSTSTA复位状态清除位，读出为0
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_ClearRstsstaFlag(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_RSTCLR.bits.CLR, State);
}

/* SPI_ACES0_T */

/**
 * @brief 设置SPI使能MasterTAGIDn的事务对模块内核地址的写访问
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] IOx IO编号，取值为 0-31
 * @param[in] State 使能MasterTAGIDn的事务对模块内核地址的写访问
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetAcessEnabledForMasterTagIdN(Spi_RegisterMap_t *const Module, const Spi_Aces0_En_Id_t AcessEnabledForMasterTagIdN, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_ACES0_EN_ID(AcessEnabledForMasterTagIdN));

	switch(AcessEnabledForMasterTagIdN)
	{
	case SPI_ACES0_EN_ID_0:
		REG_WRITE(Module->SPI_ACES0.bits.EN0, State);
		break;
	case SPI_ACES0_EN_ID_1:
		REG_WRITE(Module->SPI_ACES0.bits.EN1, State);
		break;
	case SPI_ACES0_EN_ID_2:
		REG_WRITE(Module->SPI_ACES0.bits.EN2, State);
		break;
	case SPI_ACES0_EN_ID_3:
		REG_WRITE(Module->SPI_ACES0.bits.EN3, State);
		break;
	case SPI_ACES0_EN_ID_4:
		REG_WRITE(Module->SPI_ACES0.bits.EN4, State);
		break;
	case SPI_ACES0_EN_ID_5:
		REG_WRITE(Module->SPI_ACES0.bits.EN5, State);
		break;
	case SPI_ACES0_EN_ID_6:
		REG_WRITE(Module->SPI_ACES0.bits.EN6, State);
		break;
	case SPI_ACES0_EN_ID_7:
		REG_WRITE(Module->SPI_ACES0.bits.EN7, State);
		break;
	case SPI_ACES0_EN_ID_8:
		REG_WRITE(Module->SPI_ACES0.bits.EN8, State);
		break;
	case SPI_ACES0_EN_ID_9:
		REG_WRITE(Module->SPI_ACES0.bits.EN9, State);
		break;
	case SPI_ACES0_EN_ID_10:
		REG_WRITE(Module->SPI_ACES0.bits.EN10, State);
		break;
	case SPI_ACES0_EN_ID_11:
		REG_WRITE(Module->SPI_ACES0.bits.EN11, State);
		break;
	case SPI_ACES0_EN_ID_12:
		REG_WRITE(Module->SPI_ACES0.bits.EN12, State);
		break;
	case SPI_ACES0_EN_ID_13:
		REG_WRITE(Module->SPI_ACES0.bits.EN13, State);
		break;
	case SPI_ACES0_EN_ID_14:
		REG_WRITE(Module->SPI_ACES0.bits.EN14, State);
		break;
	case SPI_ACES0_EN_ID_15:
		REG_WRITE(Module->SPI_ACES0.bits.EN15, State);
		break;
	case SPI_ACES0_EN_ID_16:
		REG_WRITE(Module->SPI_ACES0.bits.EN16, State);
		break;
	case SPI_ACES0_EN_ID_17:
		REG_WRITE(Module->SPI_ACES0.bits.EN17, State);
		break;
	case SPI_ACES0_EN_ID_18:
		REG_WRITE(Module->SPI_ACES0.bits.EN18, State);
		break;
	case SPI_ACES0_EN_ID_19:
		REG_WRITE(Module->SPI_ACES0.bits.EN19, State);
		break;
	case SPI_ACES0_EN_ID_20:
		REG_WRITE(Module->SPI_ACES0.bits.EN20, State);
		break;
	case SPI_ACES0_EN_ID_21:
		REG_WRITE(Module->SPI_ACES0.bits.EN21, State);
		break;
	case SPI_ACES0_EN_ID_22:
		REG_WRITE(Module->SPI_ACES0.bits.EN22, State);
		break;
	case SPI_ACES0_EN_ID_23:
		REG_WRITE(Module->SPI_ACES0.bits.EN23, State);
		break;
	case SPI_ACES0_EN_ID_24:
		REG_WRITE(Module->SPI_ACES0.bits.EN24, State);
		break;
	case SPI_ACES0_EN_ID_25:
		REG_WRITE(Module->SPI_ACES0.bits.EN25, State);
		break;
	case SPI_ACES0_EN_ID_26:
		REG_WRITE(Module->SPI_ACES0.bits.EN26, State);
		break;
	case SPI_ACES0_EN_ID_27:
		REG_WRITE(Module->SPI_ACES0.bits.EN27, State);
		break;
	case SPI_ACES0_EN_ID_28:
		REG_WRITE(Module->SPI_ACES0.bits.EN28, State);
		break;
	case SPI_ACES0_EN_ID_29:
		REG_WRITE(Module->SPI_ACES0.bits.EN29, State);
		break;
	case SPI_ACES0_EN_ID_30:
		REG_WRITE(Module->SPI_ACES0.bits.EN30, State);
		break;
	case SPI_ACES0_EN_ID_31:
		REG_WRITE(Module->SPI_ACES0.bits.EN31, State);
		break;
	default:
		break;
	}
}

/* SPI_ACES1_T */

/* SPI_INFO_T */

/**
 * @brief 读取SPISPI模块版本信息位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return SPI模块版本信息位
 */
KF_INLINE uint32_t Spi_LL_GetSpiModuleVersionInfo(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_INFO.bits.MODREV);
}

/**
 * @brief 读取SPISPI模块类型信息
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return SPI模块类型信息
 */
KF_INLINE uint32_t Spi_LL_GetSpiModuleTypeInfo(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_INFO.bits.MODTYPE);
}

/**
 * @brief 读取SPISPI模块编号
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return SPI模块编号
 */
KF_INLINE uint32_t Spi_LL_GetSpiModuleNumber(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_INFO.bits.MODNUM);
}

/* SPI_RESV0_T */

/* SPI_RESV1_T */

/* SPI_RESV2_T */

/* SPI_RESV3_T */

/* SPI_CTL0_T */

/**
 * @brief 设置SPISPI模块时钟预分频
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] PDIVValue SPI模块时钟预分频
 * @return void
 */
KF_INLINE void Spi_LL_SetSpiModuleClockPdiv(Spi_RegisterMap_t *const Module, uint32_t PDIVValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CTL0.bits.PDIV, PDIVValue);
}

/**
 * @brief 设置SPI每个数据块后是否将状态寄存器存入接收FIFO
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 每个数据块后是否将状态寄存器存入接收FIFO
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetStatusRegStoredEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CTL0.bits.STAINJ, State);
}

/**
 * @brief 设置SPI超时时间长度设置
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] EXPECTValue 超时时间长度设置
 *            0H 2^6
 *            1H 2^7
 *            ... ...
 *            FH 2^21
 * @return void
 */
KF_INLINE void Spi_LL_SetLengthOfOvertime(Spi_RegisterMap_t *const Module, Spi_Ctl0_Expect_Id_t EXPECTValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CTL0_EXPECT_ID(EXPECTValue));

	REG_WRITE(Module->SPI_CTL0.bits.EXPECT, EXPECTValue);
}

/**
 * @brief 设置SPI回环模式选择位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 回环模式选择位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetBackLoopModeEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CTL0.bits.LOOPBACK, State);
}

/**
 * @brief 设置SPISS0是否使能延迟模式
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State SS0是否使能延迟模式
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetSs0DelayModeEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CTL0.bits.DLY, State);
}

/**
 * @brief 设置SPISS0延迟模式下的选通延时
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] STROBEValue SS0延迟模式下的选通延时
 *            00H 1
 *            01H 2
 *            ... ...
 *            1FH 32
 * @return void
 */
KF_INLINE void Spi_LL_SetSs0DelayLength(Spi_RegisterMap_t *const Module, Spi_Ctl0_Strobe_Id_t STROBEValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CTL0_STROBE_ID(STROBEValue));

	REG_WRITE(Module->SPI_CTL0.bits.STROBE, STROBEValue);
}

/**
 * @brief 设置SPI主机模式下，接收FIFO满时是否停止发送
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 主机模式下，接收FIFO满时是否停止发送
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetRxfifoFullStoppedWhenMaster(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CTL0.bits.SRXFULL, State);
}

/**
 * @brief 设置SPI从机模式下，空闲态下输出数据极性选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 从机模式下，空闲态下输出数据极性选择
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetDataPolarWhenSlave(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CTL0.bits.SDOPOL, State);
}

/**
 * @brief 设置SPI使能位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 使能位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetModuleEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CTL0.bits.EN, State);
}

/**
 * @brief 设置SPI主机从机模式选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] MODValue 主机从机模式选择
 *            00B 主机发送接收
 *            01B 保留
 *            10B 从机发送接收
 *            11B 从机发送接收
 * @return void
 */
KF_INLINE void Spi_LL_SelectMasterOrSlaveMode(Spi_RegisterMap_t *const Module, Spi_Ctl0_Mod_Id_t MODValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CTL0_MOD_ID(MODValue));

	REG_WRITE(Module->SPI_CTL0.bits.MOD, MODValue);
}

/**
 * @brief 设置SPI从机模式下发生波特率错误/尖峰错误时自动复位模块使能位:CTL0_EN
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 从机模式下发生波特率错误/尖峰错误时自动复位模块使能位:CTL0_EN
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetAutoResetCtl0enEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CTL0.bits.AUTORST, State);
}

/**
 * @brief 设置SPI时钟源选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 时钟源选择
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SelectClockSource(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CTL0.bits.CLKSEL, State);
}

/**
 * @brief 设置SPI复位子模块
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] CLRValue 复位子模块
 *            00B 无动作
 *            01B 只复位SPI内部逻辑//noclk
 *            10B 只复位SPI寄存器
 *            11B SPI内部逻辑和寄存器都复位
 * @return void
 */
KF_INLINE void Spi_LL_SetResetEnabled(Spi_RegisterMap_t *const Module, Spi_Ctl0_Clr_Id_t CLRValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CTL0_CLR_ID(CLRValue));

	REG_WRITE(Module->SPI_CTL0.bits.CLR, CLRValue);
}

/* SPI_CTL1_T */

/**
 * @brief 设置SPI接收FIFO阈值设置
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] TXTHRESValue 接收FIFO阈值设置
 *            00B 1
 *            01B 2
 *            10B 3
 *            11B 4
 * @return void
 */
KF_INLINE void Spi_LL_SetTxFifoThreshold(Spi_RegisterMap_t *const Module, Spi_Ctl1_Txthres_Id_t TXTHRESValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CTL1_TXTHRES_ID(TXTHRESValue));

	REG_WRITE(Module->SPI_CTL1.bits.TXTHRES, TXTHRESValue);
}

/**
 * @brief 设置SPI接收FIFO阈值设置
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] RXTHRESValue 接收FIFO阈值设置
 *            00B 0
 *            01B 1
 *            10B 2
 *            11B 3
 * @return void
 */
KF_INLINE void Spi_LL_SetRxFifoThreshold(Spi_RegisterMap_t *const Module, Spi_Ctl1_Rxthres_Id_t RXTHRESValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CTL1_RXTHRES_ID(RXTHRESValue));

	REG_WRITE(Module->SPI_CTL1.bits.RXTHRES, RXTHRESValue);
}

/**
 * @brief 设置SPI触发PT1中断事件选择位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] PT1SELValue 触发PT1中断事件选择位
 *            000B 主机模式:结束等待阶段,从机模式:发送数据正在等待移位时钟
 *            001B 主机模式:串行时钟极性改变
 *            010B 主机模式:启动帧,从机模式:启动第一个数据位的传输
 *            011B 主机模式:发送缓冲区清空,从机模式:数据从TXFIFO通过SPI移位引擎拿出
 *            100B 主机模式:填充接收缓冲区从机模式:接收到的数据写入RXFIFO
 *            101B 主机模式:结束帧从机模式:已收到最后一个数据
 *            110B 主机模式:数据不可用，即开始期望阶段
 *            111B 主机模式:结束期望阶段
 * @return void
 */
KF_INLINE void Spi_LL_SetTriggerOfPt1Int(Spi_RegisterMap_t *const Module, Spi_Ctl1_Pt1sel_Id_t PT1SELValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CTL1_PT1SEL_ID(PT1SELValue));

	REG_WRITE(Module->SPI_CTL1.bits.PT1SEL, PT1SELValue);
}

/**
 * @brief 设置SPI触发PT2中断事件选择位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] PT2SELValue 触发PT2中断事件选择位
 *            000B 主机模式:结束等待阶段,
 *            001B 主机模式:串行时钟极性改变
 *            010B 主机模式:启动帧,
 *            011B 主机模式:发送缓冲区清空,
 *            100B 主机模式:填充接收缓冲区
 *            101B 主机模式:结束帧从机模式:SLSI停用
 *            110B 主机模式:数据不可用，即开始期望阶段
 *            111B 主机模式:结束期望阶段
 * @return void
 */
KF_INLINE void Spi_LL_SetTriggerOfPt2Int(Spi_RegisterMap_t *const Module, Spi_Ctl1_Pt2sel_Id_t PT2SELValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CTL1_PT2SEL_ID(PT2SELValue));

	REG_WRITE(Module->SPI_CTL1.bits.PT2SEL, PT2SELValue);
}

/**
 * @brief 设置SPI发送FIFO模式选择位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] TXMODValue 发送FIFO模式选择位
 *            00B 混合搬运模式
 *            01B 单次搬运模式
 *            10B 批量搬运模式
 *            11B 保留
 * @return void
 */
KF_INLINE void Spi_LL_SetTxFifoMode(Spi_RegisterMap_t *const Module, Spi_Ctl1_Txmod_Id_t TXMODValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CTL1_TXMOD_ID(TXMODValue));

	REG_WRITE(Module->SPI_CTL1.bits.TXMOD, TXMODValue);
}

/**
 * @brief 设置SPI接收FIFO模式选择位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] RXMODValue 接收FIFO模式选择位
 *            00B 混合搬运模式
 *            01B 单次搬运模式
 *            10B 批量搬运模式
 *            11B 保留
 * @return void
 */
KF_INLINE void Spi_LL_SetRxFifoMode(Spi_RegisterMap_t *const Module, Spi_Ctl1_Rxmod_Id_t RXMODValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CTL1_RXMOD_ID(RXMODValue));

	REG_WRITE(Module->SPI_CTL1.bits.RXMOD, RXMODValue);
}

/* SPI_IF_T */

/**
 * @brief 读取SPI错误信号标志位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 错误信号标志位
 
 */
KF_INLINE uint32_t Spi_LL_GetErrorSignalFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_IF.bits.ERRIF);
}

/**
 * @brief 读取SPI发送中断标志位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 发送中断标志位
 */
KF_INLINE uint32_t Spi_LL_GetTxInterruptFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_IF.bits.TXIF);
}

/**
 * @brief 读取SPI接收中断标志位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 接收中断标志位
 */
KF_INLINE uint32_t Spi_LL_GetRxInterruptFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_IF.bits.RXIF);
}

/**
 * @brief 读取SPIPT1中断标志位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return PT1中断标志位
 */
KF_INLINE uint32_t Spi_LL_GetPt1InterruptFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_IF.bits.PT1IF);
}

/**
 * @brief 读取SPIPT2中断标志位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return PT2中断标志位
 */
KF_INLINE uint32_t Spi_LL_GetPt2InterruptFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_IF.bits.PT2IF);
}

/**
 * @brief 读取SPI用户中断标志位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 用户中断标志位
 */
KF_INLINE uint32_t Spi_LL_GetUserInterruptFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_IF.bits.USRIF);
}

/* SPI_IE_T */

/**
 * @brief 设置SPI错误信号使能位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] ERRIEValue 错误信号使能位
 * @return void
 */
KF_INLINE void Spi_LL_SetErrorSignalEnabled(Spi_RegisterMap_t *const Module, uint32_t ERRIEValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IE.bits.ERRIE, ERRIEValue);
}

/**
 * @brief 设置SPI发送中断使能位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 发送中断使能位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetTxInterruptEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IE.bits.TXIE, State);
}

/**
 * @brief 设置SPI接收中断使能位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 接收中断使能位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetRxInterruptEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IE.bits.RXIE, State);
}

/**
 * @brief 设置SPIPT1中断使能位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State PT1中断使能位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetPt1InterruptEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IE.bits.PT1IE, State);
}

/**
 * @brief 设置SPIPT2中断使能位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State PT2中断使能位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetPt2InterruptEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IE.bits.PT2IE, State);
}

/**
 * @brief 设置SPI用户中断使能位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 用户中断使能位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetUserInterruptEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IE.bits.USRIE, State);
}

/* SPI_IC_T */

/**
 * @brief 设置SPI错误信号清除位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] ERRICValue 错误信号清除位
 * @return void
 */
KF_INLINE void Spi_LL_ClearErrorSignal(Spi_RegisterMap_t *const Module, uint32_t ERRICValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IC.bits.ERRIC, ERRICValue);
}

/**
 * @brief 设置SPI发送中断清除位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 发送中断清除位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_ClearTxInterrupt(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IC.bits.TXIC, State);
}

/**
 * @brief 设置SPI接收中断清除位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 接收中断清除位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_ClearRxInterrupt(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IC.bits.RXIC, State);
}

/**
 * @brief 设置SPIPT1中断清除位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State PT1中断清除位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_ClearPt1Interrupt(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IC.bits.PT1IC, State);
}

/**
 * @brief 设置SPIPT2中断清除位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State PT2中断清除位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_ClearPt2Interrupt(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IC.bits.PT2IC, State);
}

/**
 * @brief 设置SPI用户中断清除位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 用户中断清除位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_ClearUserInterrupt(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_IC.bits.USRIC, State);
}

/* SPI_SCONF_T */

/**
 * @brief 读取SPI当前发送的字是否为当前帧的最后一个字
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 当前发送的字是否为当前帧的最后一个字
 */
KF_INLINE uint32_t Spi_LL_GetLastWordFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.LAST);
}

/**
 * @brief 读取SPIidle阶段预分频设置，1个TPER的长度
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return idle阶段预分频设置，1个TPER的长度
 */
KF_INLINE uint32_t Spi_LL_GetIdlePdiv(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.IPREDIV);
}

/**
 * @brief 读取SPIidle阶段持续时间长度设置，单位为TPER
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return idle阶段持续时间长度设置，单位为TPER
 */
KF_INLINE uint32_t Spi_LL_GetIdleLength(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.ICNT);
}

/**
 * @brief 读取SPIlead阶段预分频设置，1个TPER的长度
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return lead阶段预分频设置，1个TPER的长度
 */
KF_INLINE uint32_t Spi_LL_GetLeadPdiv(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.LPREDIV);
}

/**
 * @brief 读取SPIlead阶段持续时间长度设置，单位为TPER
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return lead阶段持续时间长度设置，单位为TPER
 */
KF_INLINE uint32_t Spi_LL_GetLeadLength(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.LCNT);
}

/**
 * @brief 读取SPItrail阶段预分频设置，1个TPER的长度
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return trail阶段预分频设置，1个TPER的长度
 */
KF_INLINE uint32_t Spi_LL_GetTrailPdiv(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.TPREDIV);
}

/**
 * @brief 读取SPItrail阶段持续时间长度设置，单位为TPER
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return trail阶段持续时间长度设置，单位为TPER
 */
KF_INLINE uint32_t Spi_LL_GetTrailLength(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.TCNT);
}

/**
 * @brief 读取SPI奇偶校验位选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 奇偶校验位选择
 */
KF_INLINE uint32_t Spi_LL_GetParityWorkingStatus(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.PARSEL);
}

/**
 * @brief 读取SPI后续帧中的PT1事件用户中断使能
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 后续帧中的PT1事件用户中断使能
 */
KF_INLINE uint32_t Spi_LL_GetPt1UserIntWorkingStatus(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.USRIE);
}

/**
 * @brief 读取SPI端序选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 端序选择
 */
KF_INLINE uint32_t Spi_LL_GetDataDirection(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.MSB);
}

/**
 * @brief 读取SPI字节选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 字节选择
 */
KF_INLINE uint32_t Spi_LL_GetByteBitChoice(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.BYTE);
}

/**
 * @brief 读取SPI数据长度设置
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 数据长度设置
 */
KF_INLINE uint32_t Spi_LL_GetDataLength(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.DATCNT);
}

/**
 * @brief 读取SPI从机选择信号设置
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 从机选择信号设置
 */
KF_INLINE uint32_t Spi_LL_GetSelectSignal(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_SCONF.bits.SS);
}

/* SPI_CHCTL_T */

/**
 * @brief 设置SPI波特率预分频设置
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] BAUDPREDIVValue 波特率预分频设置
 * @return void
 */
KF_INLINE void Spi_LL_SetBaudRatePdiv(Spi_RegisterMap_t *const Module, uint32_t BAUDPREDIVValue, uint32_t SpiCHCTLRowIndex)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CHCTL[SpiCHCTLRowIndex].bits.BAUDPREDIV, BAUDPREDIVValue);
}

/**
 * @brief 设置SPI在一个数据时钟周期内，A段的持续时间长度设置
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] ACNTValue 在一个数据时钟周期内，A段的持续时间长度设置
 *            00B 0
 *            01B 1
 *            10B 2
 *            11B 3
 * @return void
 */
KF_INLINE void Spi_LL_SetLengthOfSectionA(Spi_RegisterMap_t *const Module, Spi_Chctl_Acnt_Id_t ACNTValue, uint32_t SpiCHCTLRowIndex)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CHCTL_ACNT_ID(ACNTValue));

	REG_WRITE(Module->SPI_CHCTL[SpiCHCTLRowIndex].bits.ACNT, ACNTValue);
}

/**
 * @brief 设置SPI在一个数据时钟周期内，B段的持续时间长度设置
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] BCNTValue 在一个数据时钟周期内，B段的持续时间长度设置
 *            00B 0
 *            01B 1
 *            10B 2
 *            11B 3
 * @return void
 */
KF_INLINE void Spi_LL_SetLengthOfSectionB(Spi_RegisterMap_t *const Module, Spi_Chctl_Bcnt_Id_t BCNTValue, uint32_t SpiCHCTLRowIndex)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CHCTL_BCNT_ID(BCNTValue));

	REG_WRITE(Module->SPI_CHCTL[SpiCHCTLRowIndex].bits.BCNT, BCNTValue);
}

/**
 * @brief 设置SPI在一个数据时钟周期内，C段的持续时间长度设置
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] CCNTValue 在一个数据时钟周期内，C段的持续时间长度设置
 *            00B 0(若BCNT为0，CCNT至少为1)
 *            01B 1
 *            10B 2
 *            11B 3
 * @return void
 */
KF_INLINE void Spi_LL_SetLengthOfSectionC(Spi_RegisterMap_t *const Module, Spi_Chctl_Ccnt_Id_t CCNTValue, uint32_t SpiCHCTLRowIndex)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CHCTL_CCNT_ID(CCNTValue));

	REG_WRITE(Module->SPI_CHCTL[SpiCHCTLRowIndex].bits.CCNT, CCNTValue);
}

/**
 * @brief 设置SPISCK相位选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State SCK相位选择
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetSckPhase(Spi_RegisterMap_t *const Module, const bool State, uint32_t SpiCHCTLRowIndex)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CHCTL[SpiCHCTLRowIndex].bits.SCKPHASE, State);
}

/**
 * @brief 设置SPI空闲态下SCK极性选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 空闲态下SCK极性选择
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetSckPolarWhenFree(Spi_RegisterMap_t *const Module, const bool State, uint32_t SpiCHCTLRowIndex)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CHCTL[SpiCHCTLRowIndex].bits.SCKPOL, State);
}

/**
 * @brief 设置SPI奇偶校验检查使能位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 奇偶校验检查使能位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetParityCheckEnabled(Spi_RegisterMap_t *const Module, const bool State, uint32_t SpiCHCTLRowIndex)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_CHCTL[SpiCHCTLRowIndex].bits.PARCHECK, State);
}

/**
 * @brief 设置SPI大段字节序的转化配置
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] BIGENDValue 大段字节序的转化配置
 *            00B 禁用
 *            01B 16位大段
 *            10B 21位大段
 *            11B 禁用
 * @return void
 */
KF_INLINE void Spi_LL_SetConversionModeOfLargeEndByteEnabled(Spi_RegisterMap_t *const Module, Spi_Chctl_Bigend_Id_t BIGENDValue, uint32_t SpiCHCTLRowIndex)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_CHCTL_BIGEND_ID(BIGENDValue));

	REG_WRITE(Module->SPI_CHCTL[SpiCHCTLRowIndex].bits.BIGEND, BIGENDValue);
}

/* SPI_STA0_T */

/**
 * @brief 读取SPI已经传输的bit数量
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 已经传输的bit数量
 */
KF_INLINE uint32_t Spi_LL_GetBitcntTransmitted(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_STA0.bits.BITCNT);
}

/**
 * @brief 读取SPI传输FIFO中的数据数量
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 传输FIFO中的数据数量
 */
KF_INLINE uint32_t Spi_LL_GetDatacntInTxFifo(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_STA0.bits.TXLEVEL);
}

/**
 * @brief 读取SPI接收FIFO中的数据数量
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 接收FIFO中的数据数量
 */
KF_INLINE uint32_t Spi_LL_GetDatacntInRxFifo(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_STA0.bits.RXLEVEL);
}

/**
 * @brief 读取SPI指示当前活跃的从机
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 指示当前活跃的从机
 */
KF_INLINE uint32_t Spi_LL_GetCurrentlyActiveSlave(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_STA0.bits.SS);
}

/**
 * @brief 读取SPI接收到的奇偶校验位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 接收到的奇偶校验位
 */
KF_INLINE uint32_t Spi_LL_GetParityReceived(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_STA0.bits.RPAR);
}

/**
 * @brief 读取SPI发送的奇偶校验位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 发送的奇偶校验位
 */
KF_INLINE uint32_t Spi_LL_GetParitySent(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_STA0.bits.TPAR);
}

/**
 * @brief 读取SPI当前所处的传输阶段
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 当前所处的传输阶段
 */
KF_INLINE uint32_t Spi_LL_GetCurrentTxStage(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_STA0.bits.TRANSPHA);
}

/* SPI_STA1_T */

/**
 * @brief 设置SPI波特率检测使能
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 波特率检测使能
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetBaudRateDetectionEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_STA1.bits.BDDETECTEN, State);
}

/**
 * @brief 读取SPI波特率检测
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 波特率检测
 */
KF_INLINE uint32_t Spi_LL_GetBaudRateDetectionFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_STA1.bits.BDDETECT);
}

/**
 * @brief 设置SPI波特率检测
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 波特率检测
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetBaudRateDetectionFlag(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_STA1.bits.BDDETECT, State);
}

/**
 * @brief 设置SPI尖峰检测使能
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 尖峰检测使能
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetPeakDetectionEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_STA1.bits.SPDETECTEN, State);
}

/**
 * @brief 读取SPI尖峰检测
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 尖峰检测
 */
KF_INLINE uint32_t Spi_LL_GetPeakDetectionFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_STA1.bits.SPDETECT);
}

/**
 * @brief 设置SPI尖峰检测
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 尖峰检测
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetPeakDetectionFlag(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_STA1.bits.SPDETECT, State);
}

/* SPI_SSCFG_T */

/**
 * @brief 设置SPI对应的从机选择不使能时的电平值
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] SSLEVELValue 对应的从机选择不使能时的电平值
 * @return void
 */
KF_INLINE void Spi_LL_SetSsLevelWhenDisabled(Spi_RegisterMap_t *const Module, uint32_t SSLEVELValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_SSCFG.bits.SSLEVEL, SSLEVELValue);
}

/**
 * @brief 设置SPI对应的从机选择信号是否使能
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] SSENValue 对应的从机选择信号是否使能
 * @return void
 */
KF_INLINE void Spi_LL_SetSsEnabled(Spi_RegisterMap_t *const Module, uint32_t SSENValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_SSCFG.bits.SSEN, SSENValue);
}

/* SPI_EXLCNT_T */

/**
 * @brief 设置SPI超大数据模式下，当前剩余的待传输字节数量
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] DATCNTValue 超大数据模式下，当前剩余的待传输字节数量
 * @return void
 */
KF_INLINE void Spi_LL_SetEXLDatcnt(Spi_RegisterMap_t *const Module, uint32_t DATCNTValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_EXLCNT.bits.DATCNT, DATCNTValue);
}

/**
 * @brief 读取SPI超大数据模式下，当前剩余的待传输字节数量
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 超大数据模式下，当前剩余的待传输字节数量
 */
KF_INLINE uint32_t Spi_LL_GetEXLDatacntUnderTrans(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_EXLCNT.bits.CURRCNT);
}

/* SPI_MCNT_T */

/**
 * @brief 设置SPI超大数据模式下，当前剩余的待传输字节数量
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] MOVECNTValue 超大数据模式下，当前剩余的待传输字节数量
 * @return void
 */
KF_INLINE void Spi_LL_SetMCDatacnt(Spi_RegisterMap_t *const Module, uint32_t MOVECNTValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_MCNT.bits.MOVECNT, MOVECNTValue);
}

/**
 * @brief 读取SPI移动计数模式下，当前剩余的待传输字节数量
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 移动计数模式下，当前剩余的待传输字节数量
 */
KF_INLINE uint32_t Spi_LL_GetMCDatacntUnderTrans(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_MCNT.bits.CURRCNT);
}

/* SPI_MCTL_T */

/**
 * @brief 设置SPI尾阶段2预分频设置，TPER的长度
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] TPREDIV2Value 尾阶段2预分频设置，TPER的长度
 *            000B 1
 *            001B 4
 *            ... ...
 *            111B 16384
 * @return void
 */
KF_INLINE void Spi_LL_SetEndingStage2Pdiv(Spi_RegisterMap_t *const Module, Spi_Mctl_Tprediv2_Id_t TPREDIV2Value)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_MCTL_TPREDIV2_ID(TPREDIV2Value));

	REG_WRITE(Module->SPI_MCTL.bits.TPREDIV2, TPREDIV2Value);
}

/**
 * @brief 设置SPI尾阶段2时间长度设置，单位为TPER
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] TCNT2Value 尾阶段2时间长度设置，单位为TPER
 *            000B 1
 *            001B 2
 *            ... ...
 *            111B 8
 * @return void
 */
KF_INLINE void Spi_LL_SetEndingStage2Length(Spi_RegisterMap_t *const Module, Spi_Mctl_Tcnt2_Id_t TCNT2Value)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_MCTL_TCNT2_ID(TCNT2Value));

	REG_WRITE(Module->SPI_MCTL.bits.TCNT2, TCNT2Value);
}

/**
 * @brief 设置SPI在最后一个之前的中断状态使能
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 在最后一个之前的中断状态使能
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetIntBeforeLastEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_MCTL.bits.INTBLIE, State);
}

/**
 * @brief 读取SPI在最后一个之前的中断状态标志位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 在最后一个之前的中断状态标志位
 */
KF_INLINE uint32_t Spi_LL_GetIntBeforeLastFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_MCTL.bits.INTBLIF);
}

/**
 * @brief 设置SPI复位INTBLIF
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 复位INTBLIF
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_ClearIntBeforeLastFlag(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_MCTL.bits.INTBLIC, State);
}

/**
 * @brief 设置SPI置位INTBLIF
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 置位INTBLIF
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetIntBeforeLastFlag(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_MCTL.bits.INTBLIS, State);
}

/**
 * @brief 设置SPI在最后一个之后的中断状态使能
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 在最后一个之后的中断状态使能
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetIntAfterLastEnable(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_MCTL.bits.INTALIE, State);
}

/**
 * @brief 读取SPI在最后一个之后的中断状态标志位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return 在最后一个之后的中断状态标志位
 */
KF_INLINE uint32_t Spi_LL_GetIntAfterLastFlag(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_MCTL.bits.INTALIF);
}

/**
 * @brief 设置SPI复位INTALIF
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 复位INTALIF
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_ClearIntAfterLastFlag(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_MCTL.bits.INTALIC, State);
}

/**
 * @brief 设置SPI置位INTALIF
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 置位INTALIF
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetIntAfterLastFlag(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_MCTL.bits.INTALIS, State);
}

/**
 * @brief 设置SPI插入尾阶段2使能位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 插入尾阶段2使能位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetTrail2InjectionEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_MCTL.bits.TRAIL2EN, State);
}

/**
 * @brief 设置SPI移动计数模式使能位
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] State 移动计数模式使能位
 *                  true
 *                  false
 * @return void
 */
KF_INLINE void Spi_LL_SetMoveCounterEnabled(Spi_RegisterMap_t *const Module, const bool State)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_MCTL.bits.MOVEN, State);
}

/* SPI_MIXPUSH_T */

/**
 * @brief 设置SPITXFIFO输入数据
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] DATValue TXFIFO输入数据
 * @return void
 */
KF_INLINE void Spi_LL_SetTxfifoMixpush(Spi_RegisterMap_t *const Module, uint32_t DATValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_MIXPUSH.bits.DAT, DATValue);
}

/* SPI_SCTLPUSH_T */

/**
 * @brief 设置SPITXFIFO输入数据
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] DATValue TXFIFO输入数据
 * @return void
 */
KF_INLINE void Spi_LL_SetTxfifoSctl(Spi_RegisterMap_t *const Module, uint32_t DATValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_SCTLPUSH.bits.DAT, DATValue);
}

/* SPI_DATPUSH_T */

/**
 * @brief 设置SPITXFIFO输入数据
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] DATValue TXFIFO输入数据
 * @return void
 */
KF_INLINE void Spi_LL_SetTxfifoData(Spi_RegisterMap_t *const Module, uint32_t DATValue, uint32_t SpiDATPUSHRowIndex)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	REG_WRITE(Module->SPI_DATPUSH[SpiDATPUSHRowIndex].bits.DAT, DATValue);
}

/* SPI_RXPOP_T */

/**
 * @brief 读取SPIRXFIFO读出数据
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return RXFIFO读出数据
 */
KF_INLINE uint32_t Spi_LL_GetRxfifoData(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_RXPOP.bits.DAT);
}

/* SPI_DBGRXPOP_T */

/**
 * @brief 读取SPIRXFIFO读出数据输入数据
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @return RXFIFO读出数据输入数据
 */
KF_INLINE uint32_t Spi_LL_GetDebugModeRxfifoData(Spi_RegisterMap_t *const Module)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	return REG_READ(Module->SPI_DBGRXPOP.bits.DAT);
}

/* SPI_PORTSEL_T */

/**
 * @brief 设置SPI主机接收端口选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] MRISValue 主机接收端口选择
 *            000B 选择端口A
 *            001B 选择端口B
 *            010B 选择端口C
 *            011B 选择端口D
 *            100B 选择端口E
 *            101B 选择端口F
 *            110B 选择端口G
 *            111B 选择端口H
 * @return void
 */
KF_INLINE void Spi_LL_SelectMasterModeRxPin(Spi_RegisterMap_t *const Module, Spi_Portsel_Mris_Id_t MRISValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_PORTSEL_MRIS_ID(MRISValue));

	REG_WRITE(Module->SPI_PORTSEL.bits.MRIS, MRISValue);
}

/**
 * @brief 设置SPI从机模式下，从机接收端口选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] SRISValue 从机模式下，从机接收端口选择
 *            000B 选择端口A
 *            001B 选择端口B
 *            010B 选择端口C
 *            011B 选择端口D
 *            100B 选择端口E
 *            101B 选择端口F
 *            110B 选择端口G
 *            111B 选择端口H
 * @return void
 */
KF_INLINE void Spi_LL_SelectSlaveModeRxPin(Spi_RegisterMap_t *const Module, Spi_Portsel_Sris_Id_t SRISValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_PORTSEL_SRIS_ID(SRISValue));

	REG_WRITE(Module->SPI_PORTSEL.bits.SRIS, SRISValue);
}

/**
 * @brief 设置SPI从机模式下，时钟输入端口选择
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] SCISValue 从机模式下，时钟输入端口选择
 *            000B 选择端口A
 *            001B 选择端口B
 *            010B 选择端口C
 *            011B 选择端口D
 *            100B 选择端口E
 *            101B 选择端口F
 *            110B 选择端口G
 *            111B 选择端口H
 * @return void
 */
KF_INLINE void Spi_LL_SelectSlaveModeClkInputPin(Spi_RegisterMap_t *const Module, Spi_Portsel_Scis_Id_t SCISValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_PORTSEL_SCIS_ID(SCISValue));

	REG_WRITE(Module->SPI_PORTSEL.bits.SCIS, SCISValue);
}

/**
 * @brief 设置SPI从机模式下，从机选择输入端口
 * @param[in] Module 指向SPI内存结构的指针，取值为SPI0-SPI3
 * @param[in] SLSISValue 从机模式下，从机选择输入端口
 *            000B 无输入
 *            001B 选择端口A
 *            010B 选择端口B
 *            011B 选择端口C
 *            100B 选择端口D
 *            101B 选择端口E
 *            110B 选择端口F
 *            111B 选择端口G
 * @return void
 */
KF_INLINE void Spi_LL_SelectSlaveModeSsInputPin(Spi_RegisterMap_t *const Module, Spi_Portsel_Slsis_Id_t SLSISValue)
{
	KF_SPI_ASSERT(CHECK_SPI_ALL_PERIPH_ADDR(Module));
	KF_SPI_ASSERT(CHECK_SPI_PORTSEL_SLSIS_ID(SLSISValue));

	REG_WRITE(Module->SPI_PORTSEL.bits.SLSIS, SLSISValue);
}

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
