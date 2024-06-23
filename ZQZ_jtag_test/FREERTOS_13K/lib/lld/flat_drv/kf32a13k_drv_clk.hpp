/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_osc.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-11-28
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
 *  |2023-11-29    |V1.0     |Wei Xing     | New Creat
 *  |2024-04-22    |V1.1     |Wei Xing     | Change api name
 *****************************************************************************/
#ifndef KF32DA13K_DRV_CLK_H_
#define KF32DA13K_DRV_CLK_H_

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a13k_reg_clock.h"

#ifdef KF_DRV_CLK_ASSERT
#include "dev_assert.h"
#define KF_CLK_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_CLK_ASSERT(x) ((void)0U)
#endif
#ifdef SIMULATION

#include "kf32a13k_reg_simulation_clock.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    CLK_GAIN_MOD_1,
    CLK_GAIN_MOD_2,
    CLK_GAIN_MOD_3,
    CLK_GAIN_MOD_MAX,
} Clk_OscGainMod_t;
#define CHECK_CLK_GAIN_MOD(MODE) (((MOD) >> 2) == 0)

typedef enum
{
    CLK_MODE_EXTCLK_LOWPOWEROFF,
    CLK_MODE_OSCOFF_LOWPOWEROFF,
    CLK_MODE_XHT_LOWPOWERON,
    CLK_MODE_OSCOFF_LOWPOWERON,
} Clk_OscMod_t;
#define CHECK_CLK_MOD(MODE) (((MODE) >> 2) == 0)

typedef enum
{
    CLK_HYSTERESIS_MODE_DEFAULT,
    CLK_HYSTERESIS_MODE_1,
    CLK_HYSTERESIS_MODE_2,
    CLK_HYSTERESIS_MODE_3,
} Clk_OscHysteresisMod_t;
#define CHECK_CLK_HYSMOD(MODE) (((MODE) >> 2) == 0)

typedef enum
{
    CLK_AMP_MODE_DEFAULT,
    CLK_AMP_MODE_1,
    CLK_AMP_MODE_2,
    CLK_AMP_MODE_3,
} Clk_OscAmpMod_t;
#define CHECK_CLK_AMPMOD(MODE) (((MODE) >> 2) == 0)

typedef enum
{
    CLK_HSE_MODE_DEFAULT,
    CLK_HSE_MODE_REVERSER,
} Clk_HseMode_t;
#define CHECK_CLK_HSEMOD(MODE) (((MODE) >> 1) == 0)

typedef enum
{
    CLK_GM_BOOST_MODE_4,
    CLK_GM_BOOST_MODE_2_4,
    CLK_GM_BOOST_MODE_4_4,
    CLK_GM_BOOST_MODE_6_4,
    CLK_GM_BOOST_MODE_8_4,
    CLK_GM_BOOST_MODE_10_4,
    CLK_GM_BOOST_MODE_12_4,
    CLK_GM_BOOST_MODE_14_4,
    CLK_GM_BOOST_MODE_16_4,
    CLK_GM_BOOST_MODE_18_4,
    CLK_GM_BOOST_MODE_20_4,
    CLK_GM_BOOST_MODE_22_4,
    CLK_GM_BOOST_MODE_24_4,
    CLK_GM_BOOST_MODE_26_4,
    CLK_GM_BOOST_MODE_28_4,
    CLK_GM_BOOST_MODE_30_4,
} Clk_GmMode_t;
#define CHECK_CLK_GMMOD(MODE) (((MODE) >> 4) == 0)

typedef enum
{
    CLK_XTH_COMPARATOR_CURRENT_12DOT5,
    CLK_XTH_COMPARATOR_CURRENT_25,
    CLK_XTH_COMPARATOR_CURRENT_37DOT5,
    CLK_XTH_COMPARATOR_CURRENT_50,
} Clk_XTHCurrent_t;
#define CHECK_CLK_XTHCURRENT(CURRENT) (((MODE) >> 2) == 0)

typedef enum
{
    CLK_XTH_GET_PLLLSTA = 0,
    CLK_XTH_GET_PLLHSTA = 8,
} Clk_XTHFlagGetIndex_t;
#define CHECK_CLK_XTHFLAG_GET(x) ((x == CLK_XTH_GET_PLLLSTA) || (x == CLK_XTH_GET_PLLHSTA))

typedef enum
{
    CLK_CLKSYS_SET_EXTHF,
    CLK_CLKSYS_SET_EXTLF,
    CLK_CLKSYS_SET_SYSPLL,
    CLK_CLKSYS_SET_PERPLL,
    CLK_CLKSYS_SET_INTHF32,
    CLK_CLKSYS_SET_INTLF,
} Clk_ClkSysSetIndex_t;
#define CHECK_CLK_CLKSYS_SETINDEX(x) (x <= CLK_CLKSYS_SET_INTLF)

typedef enum
{
    CLK_CLKSYS_INTR_SET_SYSPLLIE,
    CLK_CLKSYS_INTR_SET_PERPLLIE,
    CLK_CLKSYS_INTR_SET_EHFIE,
    CLK_CLKSYS_INTR_SET_ELFIE,
    CLK_CLKSYS_INTR_SET_IHFIE,
    CLK_CLKSYS_INTR_SET_ILFIE,
} Clk_ClkSysIntrSetIndex_t;
#define CHECK_CLK_CLKSYS_INTRSETINDEX(x) (x <= CLK_CLKSYS_INTR_SET_ILFIE)

typedef enum
{
    CLK_PLL_SOURCE_INTHF,
    CLK_PLL_SOURCE_EXTHF,
    CLK_PLL_SOURCE_EXTCK,
    CLK_PLL_SOURCE_INTHF32,
} Clk_PLLClockSource_t;
#define CHECK_CLK_PLL_CLOCKSOURCE(CLOCK) ((CLOCK >> 2) == 0)

typedef enum
{
    CLK_DOMAIN_SOURCE0_INTHF100,
    CLK_DOMAIN_SOURCE0_SYSPLL,
    CLK_DOMAIN_SOURCE0_INTHF32,
    CLK_DOMAIN_SOURCE0_EXTHF,
    CLK_DOMAIN_SOURCE0_ADPLL,
    CLK_DOMAIN_SOURCE0_PERPLL1,
    CLK_DOMAIN_SOURCE0_PERPLL2,
    CLK_DOMAIN_SOURCE0_DEFAULT,
} Clk_DomainClockSource0_t;
#define CHECK_CLK_DOMAIN_CLOCKSOURCE0(CLOCK) ((CLOCK >> 3) == 0)

typedef enum
{
    CLK_DOMAIN_SOURCE1_INTHF100,
    CLK_DOMAIN_SOURCE1_PERPLL1,
    CLK_DOMAIN_SOURCE1_INTHF32,
    CLK_DOMAIN_SOURCE1_EXTHF,
    CLK_DOMAIN_SOURCE1_ADPLL,
    CLK_DOMAIN_SOURCE1_SYSPLL,
    CLK_DOMAIN_SOURCE1_PERPLL2,
    CLK_DOMAIN_SOURCE1_DEFAULT,
} Clk_DomainClockSource1_t;
#define CHECK_CLK_DOMAIN_CLOCKSOURCE1(CLOCK) ((CLOCK >> 3) == 0)

typedef enum
{
    CLK_DOMAIN_SOURCE2_INTHF100,
    CLK_DOMAIN_SOURCE2_PERPLL2,
    CLK_DOMAIN_SOURCE2_INTHF32,
    CLK_DOMAIN_SOURCE2_EXTHF,
    CLK_DOMAIN_SOURCE2_ADPLL,
    CLK_DOMAIN_SOURCE2_SYSPLL,
    CLK_DOMAIN_SOURCE2_PERPLL1,
    CLK_DOMAIN_SOURCE2_DEFAULT,
} Clk_DomainClockSource2_t;
#define CHECK_CLK_DOMAIN_CLOCKSOURCE2(CLOCK) ((CLOCK >> 3) == 0)

/**
 * PLL输入参数的校验
 */
#define CHECK_PLL_MULTIPLE_MValue(MUL)  (((uint32_t)(MUL) <= 0x3FFF) && ((uint32_t)(MUL) >= 0x4))
#define CHECK_PLL_MULTIPLE_NValue(MUL)  (((uint32_t)(MUL) <= 0xF) && ((uint32_t)(MUL) >= 0x1))
#define CHECK_PLL_MULTIPLE_K2Value(MUL) ((uint32_t)(MUL) <= 0x7)
#define CHECK_PLL_MULTIPLE_K3Value(MUL) ((uint32_t)(MUL) <= 0x7)

#define CHECK_SYSPLL_MODULATIONVALUE_INT(x) ((x >> 5) == 0)
#define CHECK_SYSPLL_MODULATIONVALUE_DEC(x) ((x >> 5) == 0)

typedef enum
{
    CLK_CDU_COMMON_DIVISION_OFF,
    CLK_CDU_COMMON_DIVISION_1,
    CLK_CDU_COMMON_DIVISION_2,
    CLK_CDU_COMMON_DIVISION_3,
    CLK_CDU_COMMON_DIVISION_4,
    CLK_CDU_COMMON_DIVISION_5,
    CLK_CDU_COMMON_DIVISION_6,
    CLK_CDU_COMMON_DIVISION_7,
    CLK_CDU_COMMON_DIVISION_8,
    CLK_CDU_COMMON_DIVISION_9,
    CLK_CDU_COMMON_DIVISION_10,
    CLK_CDU_COMMON_DIVISION_11,
    CLK_CDU_COMMON_DIVISION_12,
    CLK_CDU_COMMON_DIVISION_13,
    CLK_CDU_COMMON_DIVISION_14,
    CLK_CDU_COMMON_DIVISION_15,
} Clk_CDU_CommonDivision_t;
#define CHECK_CDU_COMMON_DIVISION(DIVISION)  ((DIVISION >> 4) == 0)
#define CHECK_CDU_SYSCLK_DIVISION(DIVISION)  (((DIVISION >> 4) == 0) && ((uint32_t)DIVISION > 0))
#define CHECK_CDU_PERICLK_DIVISION(DIVISION) (((DIVISION >> 4) == 0) && ((uint32_t)DIVISION > 1))

typedef enum
{
    CLK_CDU_LPCLK_DIVISION_DEFAULT,
    CLK_CDU_LPCLK_DIVISION_30,
    CLK_CDU_LPCLK_DIVISION_60,
    CLK_CDU_LPCLK_DIVISION_120,
    CLK_CDU_LPCLK_DIVISION_240,
} Clk_CDU_LPClkDivision_t;
#define CHECK_CDU_LPCLK_DIVISION(DIVISION) ((uint32_t)DIVISION <= CLK_CDU_LPCLK_DIVISION_240)

typedef enum
{
    CLK_CDU_REFCLK_DIVISION_OFF,
    CLK_CDU_REFCLK_DIVISION_1,
    CLK_CDU_REFCLK_DIVISION_2,
    CLK_CDU_REFCLK_DIVISION_3,
    CLK_CDU_REFCLK_DIVISION_4,
    CLK_CDU_REFCLK_DIVISION_5,
    CLK_CDU_REFCLK_DIVISION_6,
    CLK_CDU_REFCLK_DIVISION_7,
    CLK_CDU_REFCLK_DIVISION_8,
    CLK_CDU_REFCLK_DIVISION_9,
    CLK_CDU_REFCLK_DIVISION_10,
    CLK_CDU_REFCLK_DIVISION_11,
    CLK_CDU_REFCLK_DIVISION_12,
    CLK_CDU_REFCLK_DIVISION_13,
    CLK_CDU_REFCLK_DIVISION_14,
    CLK_CDU_REFCLK_DIVISION_15,
    CLK_CDU_REFCLK_DIVISION_16,
    CLK_CDU_REFCLK_DIVISION_17,
    CLK_CDU_REFCLK_DIVISION_18,
    CLK_CDU_REFCLK_DIVISION_19,
    CLK_CDU_REFCLK_DIVISION_20,
    CLK_CDU_REFCLK_DIVISION_21,
    CLK_CDU_REFCLK_DIVISION_22,
    CLK_CDU_REFCLK_DIVISION_23,
    CLK_CDU_REFCLK_DIVISION_24,
    CLK_CDU_REFCLK_DIVISION_25,
    CLK_CDU_REFCLK_DIVISION_26,
    CLK_CDU_REFCLK_DIVISION_27,
    CLK_CDU_REFCLK_DIVISION_28,
    CLK_CDU_REFCLK_DIVISION_29,
    CLK_CDU_REFCLK_DIVISION_30,
    CLK_CDU_REFCLK_DIVISION_31,
} Clk_CDU_RefClkDivision_t;
#define CHECK_CDU_REFCLK_DIVISION(DIVISION) ((DIVISION >> 5) == 0)

typedef enum
{
    CLK_CDU_REFCLK2_SOURCE_FSOURCE1,
    CLK_CDU_REFCLK2_SOURCE_FSOURCE2,
} Clk_CDU_RefClk2Source_t;
#define CHECK_CDU_REFCLK2_SOURCE(SOURCE) ((SOURCE >> 1) == 0)

typedef enum
{
    CLK_CDU_MSC_SOURCE_FSOURCE1,
    CLK_CDU_MSC_SOURCE_FSOURCE2,
} Clk_CDU_MscClkSource_t;
#define CHECK_CDU_MSC_SOURCE(SOURCE) ((SOURCE >> 1) == 0)

typedef enum
{
    CLK_CDU_RTC_SOURCE_INTHF,
    CLK_CDU_RTC_SOURCE_EXTHF,
} Clk_CDU_RtcClkSource_t;
#define CHECK_CDU_RTC_SOURCE(SOURCE) ((SOURCE >> 1) == 0)

typedef enum
{
    CLK_CDU_SPI_SOURCE_FSOURCE1,
    CLK_CDU_SPI_SOURCE_FSOURCE2,
} Clk_CDU_SpiClkSource_t;
#define CHECK_CDU_SPICLK_SOURCE(SOURCE) ((SOURCE >> 1) == 0)

typedef enum
{
    CLK_CDU_ADC_SOURCE_FSOURCE1,
    CLK_CDU_ADC_SOURCE_FSOURCE2,
} Clk_CDU_AdcClkSource_t;
#define CHECK_CDU_ADCCLK_SOURCE(SOURCE) ((SOURCE >> 1) == 0)

typedef enum
{
    CLK_CDU_I2C_SOURCE_FSOURCE1,
    CLK_CDU_I2C_SOURCE_FSOURCE2,
} Clk_CDU_I2CClkSource_t;
#define CHECK_CDU_I2CCLK_SOURCE(SOURCE) ((SOURCE >> 1) == 0)

typedef enum
{
    CLK_CDU_CAN_SOURCE_FSOURCE1,
    CLK_CDU_CAN_SOURCE_FSOURCE2,
} Clk_CDU_CANClkSource_t;
#define CHECK_CDU_CANCLK_SOURCE(SOURCE) ((SOURCE >> 1) == 0)

typedef enum
{
    CLK_CDU_UTLINF_SOURCE_FSOURCE1,
    CLK_CDU_UTLINF_SOURCE_FSOURCE2,
} Clk_CDU_UTLINFClkSource_t;
#define CHECK_CDU_UTLINFCLK_SOURCE(SOURCE) ((SOURCE >> 1) == 0)

typedef enum
{
    CLK_CDU_UTLINS_SOURCE_FSOURCE1,
    CLK_CDU_UTLINS_SOURCE_FSOURCE2,
} Clk_CDU_UTLINSClkSource_t;
#define CHECK_CDU_UTLINSCLK_SOURCE(SOURCE) ((SOURCE >> 1) == 0)

#define CHECK_CDU_CUP0CLK_DIVISION(DIVISION) ((DIVISION >> 6) == 0)

#define CHECK_CDU_CUP1CLK_DIVISION(DIVISION) ((DIVISION >> 6) == 0)

typedef enum
{
    CLK_CDU_INTFREQDIVMODE_PERICLK,
    CLK_CDU_INTFREQDIVMODE_SYSCLK,
    CLK_CDU_INTFREQDIVMODE_TMRCLK,
    CLK_CDU_INTFREQDIVMODE_STCLK,
    CLK_CDU_INTFREQDIVMODE_CANHCLK,
    CLK_CDU_INTFREQDIVMODE_REFCLK1CLK,
    CLK_CDU_INTFREQDIVMODE_REFCLK2CLK,
    CLK_CDU_INTFREQDIVMODE_MSCCLK,
    CLK_CDU_INTFREQDIVMODE_RTCCLK,
    CLK_CDU_INTFREQDIVMODE_SPICLK,
    CLK_CDU_INTFREQDIVMODE_ADCCLK,
    CLK_CDU_INTFREQDIVMODE_I2CCLK,
    CLK_CDU_INTFREQDIVMODE_CANCLK,
    CLK_CDU_INTFREQDIVMODE_UTLINFCLK,
    CLK_CDU_INTFREQDIVMODE_UTLINSCLK,
} Clk_IntFreqDividerIndex_t;
#define CHECK_CDU_INTFREQDIVIDER_INDEX(INDEX) ((uint32_t)INDEX <= CLK_CDU_INTFREQDIVMODE_UTLINSCLK)

typedef enum
{
    CLK_CDU_INTFREQDIV_PULSEMODE,
    CLK_CDU_INTFREQDIV_BALANCEMODE,
} Clk_IntFreqDividerMode_t;
#define CHECK_CDU_INTFREQDIVIDER_MODE(MODE) ((MODE >> 1) == 0)

typedef enum
{
    CLK_CLKM_MONITOR_INDEX_PLL0,
    CLK_CLKM_MONITOR_INDEX_PLL1,
    CLK_CLKM_MONITOR_INDEX_PLL2,
    CLK_CLKM_MONITOR_INDEX_PERI,
    CLK_CLKM_MONITOR_INDEX_INTHF100,
    CLK_CLKM_MONITOR_INDEX_INTHF32,
} Clk_SckMonitorEnabledIndex_t;
#define CHECK_CLKM_MONITOR_INDEX(INDEX) ((uint32_t)INDEX <= CLK_CLKM_MONITOR_INDEX_INTHF32)

#define CHECK_CLKM_LOW_THRESHOLD(x) ((x >> 12) == 0)
#define CHECK_CLKM_UP_THRESHOLD(x)  ((x >> 12) == 0)

typedef enum
{
    CLK_CLKM_MONITOR_REFCLK_INTHF100,
    CLK_CLKM_MONITOR_REFCLK_SYSPLL0,
    CLK_CLKM_MONITOR_REFCLK_INTHF32,
    CLK_CLKM_MONITOR_REFCLK_EXTHF,
    CLK_CLKM_MONITOR_REFCLK_ADPLL,
    CLK_CLKM_MONITOR_REFCLK_PERPLL1,
    CLK_CLKM_MONITOR_REFCLK_PERPLL2,
    CLK_CLKM_MONITOR_REFCLK_XHTCK,
} Clk_SckMonitorRefclkIndex_t;
#define CHECK_CLKM_REFCLK_INDEX(INDEX) ((INDEX >> 3) == 0)

typedef enum
{
    CLK_CLKM_MONITOR_CLK_INTHF100,
    CLK_CLKM_MONITOR_CLK_INTHF32,
    CLK_CLKM_MONITOR_CLK_EXTHF,
    CLK_CLKM_MONITOR_CLK_SYSPLL0,
    CLK_CLKM_MONITOR_CLK_PERPLL1,
    CLK_CLKM_MONITOR_CLK_PERPLL2,
    CLK_CLKM_MONITOR_CLK_ADPLL,
    CLK_CLKM_MONITOR_CLK_PERI,
    CLK_CLKM_MONITOR_CLK_CPU0,
    CLK_CLKM_MONITOR_CLK_CPU1,
    CLK_CLKM_MONITOR_CLK_SYS,
    CLK_CLKM_MONITOR_CLK_ST,
    CLK_CLKM_MONITOR_CLK_PERI2,
    CLK_CLKM_MONITOR_CLK_CANH,
    CLK_CLKM_MONITOR_CLK_SPI,
    CLK_CLKM_MONITOR_CLK_ADC,
    CLK_CLKM_MONITOR_CLK_I2C,
    CLK_CLKM_MONITOR_CLK_CAN,
    CLK_CLKM_MONITOR_CLK_UTLINF,
    CLK_CLKM_MONITOR_CLK_UTLINS,
    CLK_CLKM_MONITOR_CLK_MSC,
    CLK_CLKM_MONITOR_CLK_EXTLF,
    CLK_CLKM_MONITOR_CLK_INTLF,
    CLK_CLKM_MONITOR_CLK_REFCLK1,
    CLK_CLKM_MONITOR_CLK_REFCLK2,
    CLK_CLKM_MONITOR_CLK_TMR,
    CLK_CLKM_MONITOR_CLK_RTC,
} Clk_MonitorClockSourceIndex_t;
#define CHECK_CLKM_MONCLK_INDEX(INDEX) ((uint32_t)INDEX <= CLK_CLKM_MONITOR_CLK_RTC)

typedef enum
{
    CLK_EXTCLK0_OUTCLK0  = 0,
    CLK_EXTCLK0_SYSPLL0  = 1,
    CLK_EXTCLK0_PERPLL1  = 2,
    CLK_EXTCLK0_EXTHF    = 3,
    CLK_EXTCLK0_INTHF100 = 4,
    CLK_EXTCLK0_PERPLL2  = 5,
    CLK_EXTCLK0_CPU0CLK  = 7,
    CLK_EXTCLK0_SYSCLK   = 8,
    CLK_EXTCLK0_PERICLK  = 9,
    CLK_EXTCLK0_STCLK    = 11,
} Clk_ExternalClock0Index_t;
#define CHECK_EXTCLK0_CLK_INDEX(INDEX)                                                                                 \
    ((INDEX == CLK_EXTCLK0_OUTCLK0) || (INDEX == CLK_EXTCLK0_SYSPLL0) || (INDEX == CLK_EXTCLK0_PERPLL1) ||             \
     (INDEX == CLK_EXTCLK0_EXTHF) || (INDEX == CLK_EXTCLK0_INTHF100) || (INDEX == CLK_EXTCLK0_PERPLL2) ||              \
     (INDEX == CLK_EXTCLK0_CPU0CLK) || (INDEX == CLK_EXTCLK0_SYSCLK) || (INDEX == CLK_EXTCLK0_PERICLK) ||              \
     (INDEX == CLK_EXTCLK0_STCLK))

typedef enum
{
    CLK_EXTCLK1_OUTCLK1  = 0,
    CLK_EXTCLK1_SYSPLL0  = 1,
    CLK_EXTCLK1_PERPLL1  = 2,
    CLK_EXTCLK1_EXTHF    = 3,
    CLK_EXTCLK1_INTHF100 = 4,
    CLK_EXTCLK1_PERPLL2  = 5,
    CLK_EXTCLK1_ADCCLK   = 6,
    CLK_EXTCLK1_CPU1CLK  = 7,
    CLK_EXTCLK1_SYSCLK   = 8,
    CLK_EXTCLK1_PERICLK  = 9,
    CLK_EXTCLK1_I2CCLK   = 10,
    CLK_EXTCLK1_MSCCLK   = 11,
    CLK_EXTCLK1_ULINFCLK = 13,
    CLK_EXTCLK1_ULINSCLK = 14,
    CLK_EXTCLK1_CANCLK   = 16,
    CLK_EXTCLK1_SPICLK   = 17,
    CLK_EXTCLK1_PERICLK2 = 18,
    CLK_EXTCLK1_CANHCLK  = 20,
    CLK_EXTCLK1_REFCLK1  = 21,
    CLK_EXTCLK1_REFCLK2  = 22,
    CLK_EXTCLK1_EXTLF    = 23,
    CLK_EXTCLK1_INTLF    = 24,
} Clk_ExternalClock1Index_t;
#define CHECK_EXTCLK1_CLK_INDEX(INDEX)                                                                                 \
    ((INDEX <= CLK_EXTCLK1_INTLF) && ((uint32_t)INDEX != 12) && ((uint32_t)INDEX != 19))

#define CHECK_OUTCLK_DIVISION(DIVISION)  ((DIVISION >> 8) == 0)
#define CHECK_EXTCLK0_DIVISION(DIVISION) ((DIVISION >> 4) == 0)
#define CHECK_EXTCLK1_DIVISION(DIVISION) ((DIVISION >> 4) == 0)

typedef enum
{
    CLK_OUTCLK0_DIVIDER_RST,
    CLK_OUTCLK0_DIVIDER_NORMAL,
    CLK_OUTCLK0_DIVIDER_FRACTIONAL,
    CLK_OUTCLK0_DIVIDER_OFF,
} Clk_OUTCLK0DivMode_t;
#define CHECK_EOUTCLK0_DIVIDERMODE(MODE) ((MODE >> 4) == 0)

#define CHECK_EOUTCLK0_STEPVALUE(STEPVAL) ((STEPVAL >> 10) == 0)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/*  OSC_CTL0 */

/**
 * @brief OSC看门狗复位控制
 * @param Status:
 *          false   OSC 看门狗不被清零保持活跃
 *          true   OSC 看门狗被清零和重启
 * @retval void
 */
KF_INLINE void Clk_LL_SetOscWatachDogResetStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_OSCWDRST_MASK;
    regValue |=  Status<<HWIO_OSC_CTL0_OSC_CTL0_OSCWDRST_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL0.bits.OSCWDRST, Status);
#endif
}

/**
 * @brief OSC增益模式选择
 * @param OscGainMode: OSC 增益选择模式
 *                0b00 低增益模式 1；保留为将来使用
 *                0b01 低增益模式 2；保留为将来使用
 *                0b02 低增益模式 3；保留为将来使用
 *                0b11 最大增益模式
 * @retval void
 */
KF_INLINE void Clk_LL_SelectOscGainMode(const Clk_OscGainMod_t OscGainMode)
{
    KF_CLK_ASSERT(CHECK_CLK_GAIN_MODE(OscGainMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_GAINMOD_MASK;
    regValue |=  OscGainMode<<HWIO_OSC_CTL0_OSC_CTL0_GAINMOD_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL0.bits.GAINMOD, OscGainMode);
#endif
}

/**
 * @brief OSC模式选择
 * @param OscMode: OSC 增益选择模式
 *                0b00 外部晶振模式，OSC 未进入节能模式
 *                0b01 OSC 未使能，OSC 未进入节能模式
 *                0b02 外部输入时钟模式，OSC 进入节能模式
 *                0b11 OSC 未使能，OSC 进入节能模式
 * @retval void
 */
KF_INLINE void Clk_LL_SelectOscMode(const Clk_OscMod_t OscMode)
{
    KF_CLK_ASSERT(CHECK_CLK_MODE(OscMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_OSCMOD_MASK;
    regValue |=  OscMode<<HWIO_OSC_CTL0_OSC_CTL0_OSCMOD_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL0.bits.OSCMOD, OscMode);
#endif
}

/**
 * @brief OSC整形器绕过控制
 * @param Status:
 *          false   整形器不被绕过
 *          true   整形器被绕过
 * @retval void
 */
KF_INLINE void Clk_LL_SetOscShaperBypassStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_SHBYEN_MASK;
    regValue |=  Status<<HWIO_OSC_CTL0_OSC_CTL0_SHBYEN_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL0.bits.SHBYEN, Status);
#endif
}

/**
 * @brief OSC之后使能控制
 * @param Status:
 *          false   滞后未使能
 *          true   滞后使能
 * @retval void
 */
KF_INLINE void Clk_LL_SetOscHysteresisStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_HYSEN_MASK;
    regValue |=  Status<<HWIO_OSC_CTL0_OSC_CTL0_HYSEN_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL0.bits.HYSEN, Status);
#endif
}

/**
 * @brief OSC滞后控制模式选择
 * @param OscHysMode: OSC 增益选择模式
 *                0b00: 滞后控制模式 0（最高滞后，默认值）
 *                0b01: 滞后控制模式 1；保留为将来使用
 *                0b10: 滞后控制模式 2；保留为将来使用
 *                0b11: 滞后控制模式 3；保留为将来使用
 * @retval void
 */
KF_INLINE void Clk_LL_SelectOscHysteresisMode(const Clk_OscHysteresisMod_t OscHysMode)
{
    KF_CLK_ASSERT(CHECK_CLK_HYSMOD(OscHysMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_HYSMOD_MASK;
    regValue |=  OscHysMode<<HWIO_OSC_CTL0_OSC_CTL0_HYSMOD_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL0.bits.HYSMOD, OscHysMode);
#endif
}

/**
 * @brief OSC滞后控制模式选择
 * @param OscHysMode: OSC 增益选择模式
 *                0b00: 振幅控制模式 0（默认值）
 *                0b01: 振幅控制模式 1；保留为将来使用
 *                0b10: 振幅控制模式 2；保留为将来使用
 *                0b11: 振幅控制模式 3；保留为将来使用
 * @retval void
 */
KF_INLINE void Clk_LL_SelectOscAmpMode(const Clk_OscAmpMod_t OscAmpMode)
{
    KF_CLK_ASSERT(CHECK_CLK_AMPMOD(OscAmpMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_AMPMOD_MASK;
    regValue |=  OscAmpMode<<HWIO_OSC_CTL0_OSC_CTL0_AMPMOD_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL0.bits.AMPMOD, OscAmpMode);
#endif
}

/**
 * @brief 设置OSC看门狗参考时钟频率
 * @param RefFreq: OSC 看门狗参考时钟频率
 * @retval void
 */
KF_INLINE void Clk_LL_SetOscWDGRefFrequency(const uint32_t RefFreq)
{
    /* EXTHF= (OSCCTL.OSCVAL - 1 + 16) MHz */
    /* EXTHF范围16MHz~40MHz */
    KF_CLK_ASSERT(((uint32_t)RefFreq >= 1U) && ((uint32_t)RefFreq <= 25U));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_OSCVAL_MASK;
    regValue |=  RefFreq<<HWIO_OSC_CTL0_OSC_CTL0_OSCVAL_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL0.bits.OSCVAL, RefFreq);
#endif
}

/**
 * @brief OSC振幅调节使能控制
 * @param Status:
 *          false   OSC 振幅调节未使能
 *          true   OSC 振幅调节使能
 * @retval void
 */
KF_INLINE void Clk_LL_SetOscAmpRegulatorStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_APREN_MASK;
    regValue |=  Status<<HWIO_OSC_CTL0_OSC_CTL0_APREN_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL0.bits.APREN, Status);
#endif
}

/*  OSC_CTL1 */

/**
 * @brief 外部高频外部输入时钟使能控制
 * @param Status:
 *          false   外部高频晶振可以从 XTH_IN 输入外部时钟源
 *          true   外部高频晶振不可以从 XTH_IN 输入外部时钟源
 * @retval void
 */
KF_INLINE void Clk_LL_SetXTHStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_HSXTALEXEN_MASK;
    regValue |=  Status<<HWIO_OSC_CTL1_OSC_CTL1_HSXTALEXEN_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.HSXTALEXEN, Status);
#endif
}

/**
 * @brief 外部高频的驱动模式选择
 * @param Status:
 *          0   保留
 *          1   外部高频晶振使用反相器驱动模式
 * @retval void
 */
KF_INLINE void Clk_LL_SelectHSEMode(const Clk_HseMode_t HseMode)
{
    KF_CLK_ASSERT(CHECK_CLK_HSEMOD(HseMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_HSEMODESEL_MASK;
    regValue |=  HseMode<<HWIO_OSC_CTL1_OSC_CTL1_HSEMODESEL_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.HSEMODESEL, HseMode);
#endif
}

/**
 * @brief 外部高频晶振驱动调节档
 * @param Status:
 *          0b0000:   Gm=4mA/V
 *          0b0001:   Gm=2mA/V+4mA/V
 *          0b0010:   Gm=4mA/V+4mA/V
 *          0b0011:   Gm=6mA/V+4mA/V
 *          0b0100:   Gm=8mA/V+4mA/V
 *          0b0101:   Gm=10mA/V+4mA/V
 *          0b0110:   Gm=12mA/V+4mA/V
 *          0b0111:   Gm=14mA/V+4mA/V
 *          0b1000:   Gm=16mA/V+4mA/V
 *          0b1001:   Gm=18mA/V+4mA/V
 *          0b1010:   Gm=20mA/V+4mA/V
 *          0b1011:   Gm=22mA/V+4mA/V
 *          0b1100:   Gm=24mA/V+4mA/V
 *          0b1101:   Gm=26mA/V+4mA/V
 *          0b1110:   Gm=28mA/V+4mA/V
 *          0b1111:   Gm=30mA/V+4mA/V
 * @retval void
 */
KF_INLINE void Clk_LL_SelectGmMode(const Clk_GmMode_t GmMode)
{
    KF_CLK_ASSERT(CHECK_CLK_GMMOD(GmMode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_GMBOOST_MASK;
    regValue |=  GmMode<<HWIO_OSC_CTL1_OSC_CTL1_GMBOOST_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.GMBOOST, GmMode);
#endif
}

/**
 * @brief 外部高频晶振内部并联 2MΩ选择
 * @param Status:
 *          false   外部高频晶振内部并联 2MΩ关闭
 *          true   外部高频晶振内部并联 2MΩ开启
 * @retval void
 */
KF_INLINE void Clk_LL_SetXTH2MOhmStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_XTHR2M_MASK;
    regValue |=  Status<<HWIO_OSC_CTL1_OSC_CTL1_XTHR2M_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.XTHR2M, Status);
#endif
}

/**
 * @brief 外部高频晶振内部并联 470kΩ选择
 * @param Status:
 *          false   外部高频晶振内部并联 470kΩ关闭
 *          true   外部高频晶振内部并联 470kΩ开启
 * @retval void
 */
KF_INLINE void Clk_LL_SetXTH470kOhmStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_XTHR470K_MASK;
    regValue |=  Status<<HWIO_OSC_CTL1_OSC_CTL1_XTHR470K_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.XTHR470K, Status);
#endif
}

/**
 * @brief 外部高频晶振内部并联 200kΩ选择
 * @param Status:
 *          false   外部高频晶振内部并联 200kΩ关闭
 *          true   外部高频晶振内部并联 200kΩ开启
 * @retval void
 */
KF_INLINE void Clk_LL_SetXTH200kOhmStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_XTHR200K_MASK;
    regValue |=  Status<<HWIO_OSC_CTL1_OSC_CTL1_XTHR200K_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.XTHR200K, Status);
#endif
}

/**
 * @brief 外部高频晶振的比较器时钟整形使能
 * @param Status:
 *          false   外部高频晶振的比较器时钟整形关闭
 *          true   外部高频晶振的比较器时钟整形开启
 * @retval void
 */
KF_INLINE void Clk_LL_SetXTHComparatorShaperStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_XTHCOMPEN_MASK;
    regValue |=  Status<<HWIO_OSC_CTL1_OSC_CTL1_XTHCOMPEN_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.XTHCOMPEN, Status);
#endif
}

/**
 * @brief 外部高频的驱动模式选择
 * @param Status:
 *          0   保留
 *          1   外部高频晶振使用反相器驱动模式
 * @retval void
 */
KF_INLINE void Clk_LL_SelectXTHComparatorCurrent(const Clk_XTHCurrent_t Current)
{
    KF_CLK_ASSERT(CHECK_CLK_XTHCURRENT(Current));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_XTHCOMPI_MASK;
    regValue |=  Current<<HWIO_OSC_CTL1_OSC_CTL1_XTHCOMPI_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.XTHCOMPI, Current);
#endif
}

/**
 * @brief 外部高频晶振内部负载电容 0 使能
 * @param Status:
 *          false   电容 0 未使能
 *          true   电容 0 使能
 * @retval void
 */
KF_INLINE void Clk_LL_SetXTHCapacitor0Status(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_CAP0EN_MASK;
    regValue |=  Status<<HWIO_OSC_CTL1_OSC_CTL1_CAP0EN_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.CAP0EN, Status);
#endif
}

/**
 * @brief 外部高频晶振内部负载电容 1 使能
 * @param Status:
 *          false   电容 1 未使能
 *          true   电容 1 使能
 * @retval void
 */
KF_INLINE void Clk_LL_SetXTHCapacitor1Status(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_CAP1EN_MASK;
    regValue |=  Status<<HWIO_OSC_CTL1_OSC_CTL1_CAP1EN_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.CAP1EN, Status);
#endif
}

/**
 * @brief 外部高频晶振内部负载电容 2 使能
 * @param Status:
 *          false   电容 2 未使能
 *          true   电容 2 使能
 * @retval void
 */
KF_INLINE void Clk_LL_SetXTHCapacitor2Status(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_CAP2EN_MASK;
    regValue |=  Status<<HWIO_OSC_CTL1_OSC_CTL1_CAP2EN_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.CAP2EN, Status);
#endif
}

/**
 * @brief 外部高频晶振内部负载电容 3 使能
 * @param Status:
 *          false   电容 3 未使能
 *          true   电容 3 使能
 * @retval void
 */
KF_INLINE void Clk_LL_SetXTHCapacitor3Status(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_OSC_CTL1_OSC_CTL1_CAP3EN_MASK;
    regValue |=  Status<<HWIO_OSC_CTL1_OSC_CTL1_CAP3EN_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->OSC_CTL1.bits.CAP3EN, Status);
#endif
}

/*  OSC_STA */

/**
 * @brief 获取OSC频率可用状态
 * @param Index:
 *          CLK_XTH_GET_PLLHSTA: PLL 上限频率，OSC 频率有效状态标志
 *          CLK_XTH_GET_PLLLSTA: PLL 下限频率，OSC 频率有效状态标志
 * @retval bool OSC频率可用状态
 */
KF_INLINE bool Clk_LL_GetXTHFlag(const Clk_XTHFlagGetIndex_t Index)
{
    KF_CLK_ASSERT(CHECK_CLK_XTHFLAG_GET(Index));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_OSC_STA_ADDR, (1U << (uint32_t)Index), (uint32_t)Index) != 0U);
//TODO: check if correct

#else
    return (REG_BITS_READ(CLK_PTR->OSC_STA.reg, (1U << (uint32_t)Index), (uint32_t)Index) != 0U);
#endif
}

/*  CLKSYS_CTL0 */

/**
 * @brief 设置时钟软件使能状态
 * @param Index:
            CLK_CLKSYS_SET_EXTHF: 外部高频振荡器软件使能
            CLK_CLKSYS_SET_EXTLF: 外部低频振荡器软件使能
            CLK_CLKSYS_SET_SYSPLL: 系统 PLL 软件使能
            CLK_CLKSYS_SET_PERPLL: 外设 PLL 软件使能
            CLK_CLKSYS_SET_INTHF32: 内部高频振荡器 32MHz 软件使能
            CLK_CLKSYS_SET_INTLF: 内部低频振荡器软件使能
 * @retval void
 */
KF_INLINE void Clk_LL_SetClkSysEnabled(const Clk_ClkSysSetIndex_t Index)
{
    KF_CLK_ASSERT(CHECK_CLK_CLKSYS_SETINDEX(Index));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_OSC_CTL0_ADDR ,  (1U << (uint32_t)Index) ,  (1U << (uint32_t)Index));
//TODO: check if correct

#else
    REG_BITS_WRITE(CLK_PTR->CLKSYS_CTL0.reg, (1U << (uint32_t)Index), (1U << (uint32_t)Index));
#endif
}

/*  CLKSYS_CTL1 */

/**
 * @brief 设置时钟软件禁用状态
 * @param Index:
            CLK_CLKSYS_SET_EXTHF: 外部高频振荡器软件禁用
            CLK_CLKSYS_SET_EXTLF: 外部低频振荡器软件禁用
            CLK_CLKSYS_SET_SYSPLL: 系统 PLL 软件禁用
            CLK_CLKSYS_SET_PERPLL: 外设 PLL 软件禁用
            CLK_CLKSYS_SET_INTHF32: 内部高频振荡器 32MHz 软件禁用
            CLK_CLKSYS_SET_INTLF: 内部低频振荡器软件禁用
 * @retval void
 */
KF_INLINE void Clk_LL_SetClkSysDisabled(const Clk_ClkSysSetIndex_t Index)
{
    KF_CLK_ASSERT(CHECK_CLK_CLKSYS_SETINDEX(Index));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_OSC_CTL1_ADDR ,  (1U << (uint32_t)Index) ,  (1U << (uint32_t)Index));
//TODO: check if correct

#else
    REG_BITS_WRITE(CLK_PTR->CLKSYS_CTL1.reg, (1U << (uint32_t)Index), (1U << (uint32_t)Index));
#endif
}

/*  CLKSYS_CTL2 */

/**
 * @brief 设置时钟延时等级
 * @param Index:
            CLK_CLKSYS_SET_EXTHF: 外部高频振荡器延时等级
            CLK_CLKSYS_SET_EXTLF: 外部低频振荡器延时等级
            CLK_CLKSYS_SET_SYSPLL: 系统 PLL延时等级
            CLK_CLKSYS_SET_PERPLL: 外设 PLL延时等级
            CLK_CLKSYS_SET_INTHF32: 内部高频振荡器 32MHz延时等级
            CLK_CLKSYS_SET_INTLF: 内部低频振荡器延时等级
 * @retval void
 */
KF_INLINE void Clk_LL_SetClkSysDelayLvl(const Clk_ClkSysSetIndex_t Index, uint32_t DelayLvl)
{
    KF_CLK_ASSERT(CHECK_CLK_CLKSYS_SETINDEX(Index));
    KF_CLK_ASSERT((DelayLvl >> 5) == 0);

#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_CLKSYS_CTL2_ADDR ,  (MASK_5_BIT << (uint32_t)(Index * POS_5_SHIFT)) ,                    (DelayLvl << (uint32_t)(Index * POS_5_SHIFT)));//TODO: check if correct

#else
    REG_BITS_WRITE(CLK_PTR->CLKSYS_CTL2.reg, (MASK_5_BIT << (uint32_t)(Index * POS_5_SHIFT)),
                   (DelayLvl << (uint32_t)(Index * POS_5_SHIFT)));
#endif
}

/*  CLKSYS_STA */

/**
 * @brief 设置时钟使能/禁用状态
 * @param Index:
 *          CLK_CLKSYS_SET_EXTHF: 外部高频振荡器使能/禁用状态
 *          CLK_CLKSYS_SET_EXTLF: 外部低频振荡器使能/禁用状态
 *          CLK_CLKSYS_SET_SYSPLL: 系统 PLL 使能/禁用状态
 *          CLK_CLKSYS_SET_PERPLL: 外设 PLL 使能/禁用状态
 *          CLK_CLKSYS_SET_INTHF32: 内部高频振荡器 32MHz 使能/禁用状态
 *          CLK_CLKSYS_SET_INTLF: 内部低频振荡器使能/禁用状态
 * @retval void
 */
KF_INLINE void __attribute__((deprecated("Use Clk_LL_SetClkSysEnabled/Clk_LL_SetClkSysDisabled Instead")))
Clk_LL_SetClkSysStatus(const Clk_ClkSysSetIndex_t Index, const bool Status)
{
    KF_CLK_ASSERT(CHECK_CLK_CLKSYS_SETINDEX(Index));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_OSC_STA_ADDR ,  (1U << (uint32_t)Index) ,  (Status << (uint32_t)Index));
//TODO: check if correct

#else
    REG_BITS_WRITE(CLK_PTR->CLKSYS_STA.reg, (1U << (uint32_t)Index), (Status << (uint32_t)Index));
#endif
}

/**
 * @brief 获取时钟使能/禁用状态
 * @param Index:
            CLK_CLKSYS_SET_EXTHF: 外部高频振荡器使能/禁用状态
            CLK_CLKSYS_SET_EXTLF: 外部低频振荡器使能/禁用状态
            CLK_CLKSYS_SET_SYSPLL: 系统 PLL 使能/禁用状态
            CLK_CLKSYS_SET_PERPLL: 外设 PLL 使能/禁用状态
            CLK_CLKSYS_SET_INTHF32: 内部高频振荡器 32MHz 使能/禁用状态
            CLK_CLKSYS_SET_INTLF: 内部低频振荡器使能/禁用状态
 * @retval bool
 */
KF_INLINE bool Clk_LL_GetClkSysStatus(const Clk_ClkSysSetIndex_t Index)
{
    KF_CLK_ASSERT(CHECK_CLK_CLKSYS_SETINDEX(Index));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_OSC_STA_ADDR, (1U << (uint32_t)Index), (uint32_t)Index) != 0U);
//TODO: check if correct

#else
    return (REG_BITS_READ(CLK_PTR->CLKSYS_STA.reg, (1U << (uint32_t)Index), (uint32_t)Index) != 0U);
#endif
}

/**
 * @brief 获取时钟稳定状态
 * @param Index:
            CLK_CLKSYS_SET_EXTHF: 外部高频振荡器稳定状态
            CLK_CLKSYS_SET_EXTLF: 外部低频振荡器稳定状态
            CLK_CLKSYS_SET_SYSPLL: 系统 PLL 稳定状态
            CLK_CLKSYS_SET_PERPLL: 外设 PLL 稳定状态
            CLK_CLKSYS_SET_INTHF32: 内部高频振荡器 32MHz 稳定状态
            CLK_CLKSYS_SET_INTLF: 内部低频振荡器稳定状态
 * @retval bool true: 时钟稳定; false: 时钟未稳定
 */
KF_INLINE bool Clk_LL_GetClkSysSteadyStatus(const Clk_ClkSysSetIndex_t Index)
{
    KF_CLK_ASSERT(CHECK_CLK_CLKSYS_SETINDEX(Index));
#ifdef SIMULATION
    return (REG_BITS_READ(HWIO_OSC_STA_ADDR, (1U << ((uint32_t)Index + 16)), ((uint32_t)Index + 16)) != 0U);
//TODO: check if correct

#else
    return (REG_BITS_READ(CLK_PTR->CLKSYS_STA.reg, (1U << ((uint32_t)Index + 16)), ((uint32_t)Index + 16)) != 0U);
#endif
}

/*  CLKSYS_IE */

/**
 * @brief 设置时钟系统中断使能状态
 * @param Index:
 *          CLK_CLKSYS_INTR_SET_SYSPLLIE: 系统 PLL 中断使能
 *          CLK_CLKSYS_INTR_SET_PERPLLIE: 外设 PLL 中断使能
 *          CLK_CLKSYS_INTR_SET_EHFIE: 外部高频中断使能
 *          CLK_CLKSYS_INTR_SET_ELFIE: 外部低频中断使能
 *          CLK_CLKSYS_INTR_SET_IHFIE: 内部高频中断使能
 *          CLK_CLKSYS_INTR_SET_ILFIE: 内部低频中断使能
 * @retval void
 */
KF_INLINE void Clk_LL_SetClkSysIntrEnabled(const Clk_ClkSysIntrSetIndex_t Index, const bool Status)
{
    KF_CLK_ASSERT(CHECK_CLK_CLKSYS_INTRSETINDEX(Index));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_CLKSYS_IE_ADDR ,  (1U << (uint32_t)Index) ,  ((uint32_t)Status << (uint32_t)Index));
//TODO: check if correct

#else
    REG_BITS_WRITE(CLK_PTR->CLKSYS_IE.reg, (1U << (uint32_t)Index), ((uint32_t)Status << (uint32_t)Index));
#endif
}

/*  SYSPLL_STA */

/**
 * @brief 获取系统PLL节能模式状态
 * @retval bool
 *        false: 系统 PLL 没有进入节能模式
 *        true: 系统 PLL 进入节能模式
 */
KF_INLINE bool Clk_LL_GetSysPLLLowPowerStatus()
{
    return (bool)(CLK_PTR->SYSPLL_STA.bits.PSSTA);
}

/**
 * @brief 获取系统PLL锁定状态
 * @retval bool
 *        false: 系统 PLL 频率不稳定
 *        true: 系统 PLL 频率稳定
 */
KF_INLINE bool Clk_LL_GetSysPLLLockStatus()
{
    return (bool)(CLK_PTR->SYSPLL_STA.bits.LOCKSTA);
}

/**
 * @brief 获取系统PLL K2分频器就绪状态
 * @retval bool
 *        false: K2 分频器没有以一个新的值工作
 *        true: K2 分频器以一个新的值工作
 */
KF_INLINE bool Clk_LL_GetSysPLLK2Status()
{
    return (bool)(CLK_PTR->SYSPLL_STA.bits.K2RDYSTA);
}

/**
 * @brief 获取系统PLL 调制运行状态
 * @retval bool
 *        false: 频率调制没有被激活
 *        true: 频率调制被激活
 */
KF_INLINE bool Clk_LL_GetSysPLLFreqModulationStatus()
{
    return (bool)(CLK_PTR->SYSPLL_STA.bits.MODRUNSTA);
}

/*  SYSPLL_CTL0 */

/**
 * @brief 配置系统PLL倍频选择
 *         放大倍数=PLLmultiple_M/(PLLdivide_N*PLLdivide_K2)
 * @param
 *        PLLmultiple_M:  0X04-0X3FFF(M要大于等于4,并且满足200MHZ<=(M*输入参考频率/N) <= 600MHZ)
 *        PLLdivide_N:  0X01-0XF(满足1MHZ<(输入参考频率/N)<50MHZ)
 * @retval void
 */
KF_INLINE void Clk_LL_SetSysPLLMultipleValue(const uint32_t PLLmultiple_M, const uint32_t PLLdivide_N)
{
    KF_CLK_ASSERT(CHECK_PLL_MULTIPLE_MValue(PLLmultiple_M));
    KF_CLK_ASSERT(CHECK_PLL_MULTIPLE_NValue(PLLdivide_N));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_OSCWDRST_MASK;
    regValue |=  PLLmultiple_M<<HWIO_OSC_CTL0_OSC_CTL0_OSCWDRST_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->SYSPLL_CTL0.bits.M, PLLmultiple_M);
#endif
#ifdef SIMULATION
     regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_GAINMOD_MASK;
    regValue |=  PLLdivide_N<<HWIO_OSC_CTL0_OSC_CTL0_GAINMOD_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->SYSPLL_CTL0.bits.N, PLLdivide_N);
#endif
}

/**
 * @brief 设置系统PLL输入时钟2分频
 *
 *
 * @param Status
 *       false: 输入时钟源不分频
 *       treu: 输入时钟源2分频
 * @return
 */
KF_INLINE void Clk_LL_SetSysPLLFreq2DivStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PLLDIV_MASK;
    regValue |=  Status<<HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PLLDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->SYSPLL_CTL0.bits.PLLDIV, Status);
#endif
}

/**
 * @brief 设置系统 PLL 的频率调制
 *
 *
 * @param Status
 *       false: 频率调制未使能
 *       treu: 频率调制使能
 * @return
 */
KF_INLINE void Clk_LL_SetSysPLLFreqModulationStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL0_SYSPLL_CTL0_MODEN_MASK;
    regValue |=  Status<<HWIO_SYSPLL_CTL0_SYSPLL_CTL0_MODEN_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->SYSPLL_CTL0.bits.MODEN, Status);
#endif
}

/**
 * @brief 设置系统PLL节能模式
 * @param Status
 *        false: 系统 PLL 模块进入节能模式，不再被使用
 *        true: 正常工作模式
 * @retval void
 */
KF_INLINE void Clk_LL_SetSysPLLLowPowerStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PSMOD_MASK;
    regValue |=  Status<<HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PSMOD_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->SYSPLL_CTL0.bits.PSMOD, Status);
#endif
}

/**
 * @brief 重启锁相检测控制器(DCO)锁定监测
 * @details 将会清除 SYSPLL_STA.LOCKSTA 位并且 DCO 锁定监测
 *        false:
 *        true:
 */
KF_INLINE void Clk_LL_ResetSysPLLDCO(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL0_SYSPLL_CTL0_DCOLDRST_MASK;
    regValue |=  Status<<HWIO_SYSPLL_CTL0_SYSPLL_CTL0_DCOLDRST_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->SYSPLL_CTL0.bits.DCOLDRST, Status);
#endif
}

/**
 * @brief 重启锁相检测控制器(DCO)锁定监测
 * @details 将会清除 PERLL_STA.LOCKSTA 位并且 DCO 锁定监测
 *        false:
 *        true:
 */
KF_INLINE void Clk_LL_ResetPerPLLDCO(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_PERPLL_CTL0_PERPLL_CTL0_RESLD_MASK;
    regValue |=  Status<<HWIO_PERPLL_CTL0_PERPLL_CTL0_RESLD_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->PERPLL_CTL0.bits.RESLD, Status);
#endif
}

/**
 * @brief 系统 PLL 复位控制
 * @attention 当 PLL 的参考频率 N<3:0>、M<13:0>、PLLDIV变化后都需要初始化PLL，PDRST位自动清零
 * @return
 */
KF_INLINE void Clk_LL_SetSysPLLReset()
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PDRST_MASK;
    regValue |=  true<<HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PDRST_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->SYSPLL_CTL0.bits.PDRST, true);
#endif
}

/**
 * @brief 系统PLL及外设PLL输入时钟源选择
 *
 *
 * @param PLLSource
 *        CLK_PLL_SOURCE_INTHF: INTHF100 作为时钟源
 *        CLK_PLL_SOURCE_EXTHF: EXTHF 作为时钟源（晶体振荡器）
 *        CLK_PLL_SOURCE_EXTCK: EXTCK 外部输入时钟作为时钟源
 *        CLK_PLL_SOURCE_INTHF32: INTHF32 作为时钟源
 * @return
 */
KF_INLINE void Clk_LL_SelectPLLClockSource(const Clk_PLLClockSource_t PLLSource)
{
    KF_CLK_ASSERT(CHECK_CLK_PLL_CLOCKSOURCE(PLLSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL0_SYSPLL_CTL0_INCLKSEL_MASK;
    regValue |=  PLLSource<<HWIO_SYSPLL_CTL0_SYSPLL_CTL0_INCLKSEL_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->SYSPLL_CTL0.bits.INCLKSEL, PLLSource);
#endif
}

/*  SYSPLL_CTL1 */

/**
 * @brief 系统PLL K2 分频器数值设置
 *
 *
 * @param PLLdivide_K2
 * @return
 */
KF_INLINE void Clk_LL_SetSysPLLK2Value(const uint32_t PLLdivide_K2)
{
    KF_CLK_ASSERT(CHECK_PLL_MULTIPLE_K2Value(PLLdivide_K2));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL1_SYSPLL_CTL1_K2CLKDIV_MASK;
    regValue |=  PLLdivide_K2<<HWIO_SYSPLL_CTL1_SYSPLL_CTL1_K2CLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->SYSPLL_CTL1.bits.K2CLKDIV, PLLdivide_K2);
#endif
}

/*  SYSPLL_CTL2 */
/**
 * @brief 设置系统PLL调制振幅
 *
 * @param IntegerPart 整数部分
 * @param DecimalPart 小数部分
 * @return
 */
KF_INLINE void Clk_LL_SetSysPLLModulationValue(const uint32_t IntegerPart, const uint32_t DecimalPart)
{
    KF_CLK_ASSERT(CHECK_SYSPLL_MODULATIONVALUE_INT(IntegerPart));
    KF_CLK_ASSERT(CHECK_SYSPLL_MODULATIONVALUE_DEC(DecimalPart));
    CLK_PTR->SYSPLL_CTL2.bits.MODCFG = (((uint32_t)0x3D << 10) | (IntegerPart << 5) | (DecimalPart));
}

/*  PERPLL_STA */

/**
 * @brief 获取外设PLL节能模式状态
 * @retval bool
 *        false: 外设 PLL 没有进入节能模式
 *        true: 外设 PLL 进入节能模式
 */
KF_INLINE bool Clk_LL_GetPerPLLLowPowerStatus()
{
    return (bool)(CLK_PTR->PERPLL_STA.bits.PSSTA);
}

/**
 * @brief 获取外设PLL锁定状态
 * @retval bool
 *        false: 外设 PLL 频率不稳定
 *        true: 外设 PLL 频率稳定
 */
KF_INLINE bool Clk_LL_GetPerPLLLockStatus()
{
    return (bool)(CLK_PTR->SYSPLL_STA.bits.LOCKSTA);
}

/**
 * @brief 获取外设PLL K2分频器就绪状态
 * @retval bool
 *        false: K2 分频器没有以一个新的值工作
 *        true: K2 分频器以一个新的值工作
 */
KF_INLINE bool Clk_LL_GetPerPLLK2Status()
{
    return (bool)(CLK_PTR->PERPLL_STA.bits.K2RDYSTA);
}

/**
 * @brief 获取外设PLL K3分频器就绪状态
 * @retval bool
 *        false: K3 分频器没有以一个新的值工作
 *        true: K3 分频器以一个新的值工作
 */
KF_INLINE bool Clk_LL_GetPerPLLK3Status()
{
    return (bool)(CLK_PTR->PERPLL_STA.bits.K3RDYSTA);
}

/*  PERPLL_CTL0 */

/**
 * @brief 分频器绕过使能
 *
 *
 * @param Status
 *        false: K3 分频器之前的 1.6 分频器不被绕过, K3 分频器之前的频率为 fDCO/1.6
 *        true: K3 分频器之前的 1.6 分频器被绕过, 经过含有 2 分频器的另一条支路, 进入 K3 分频器之前的频率为 fDCO/2
 * @return
 */
KF_INLINE void Clk_LL_SetPerPLLDivBypassStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_PERPLL_CTL0_PERPLL_CTL0_DIVBYEN_MASK;
    regValue |=  Status<<HWIO_PERPLL_CTL0_PERPLL_CTL0_DIVBYEN_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->PERPLL_CTL0.bits.DIVBYEN, Status);
#endif
}

/**
 * @brief 设置外设PLL节能模式
 * @param Status
 *        false: 外设 PLL 模块进入节能模式，不再被使用
 *        true: 正常工作模式
 * @retval void
 */
KF_INLINE void Clk_LL_SetPerPLLLowPowerStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PSMOD_MASK;
    regValue |=  Status<<HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PSMOD_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->PERPLL_CTL0.bits.PSMOD, Status);
#endif
}

/**
 * @brief 设置外设PLL输入时钟2分频
 *
 *
 * @param Status
 *       false: 输入时钟源不分频
 *       true: 输入时钟源2分频
 * @return
 */
KF_INLINE void Clk_LL_SetPerPLLFreq2DivStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PLLDIV_MASK;
    regValue |=  Status<<HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PLLDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->PERPLL_CTL0.bits.PLLDIV, Status);
#endif
}

/**
 * @brief 设置外设 PLL 复位控制
 * @attention 当 PLL 的参考频率 N<3:0>、M<13:0>、PLLDIV变化后都需要初始化PLL，PDRST位自动清零
 * @return
 */
KF_INLINE void Clk_LL_SetPerPLLReset()
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PDRST_MASK;
    regValue |=  true<<HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PDRST_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->PERPLL_CTL0.bits.PDRST, true);
#endif
}

/**
 * @brief 配置系统PLL倍频选择
 *         PLL1放大倍数=PLLmultiple_M/(PLLdivide_N*PLLdivide_K2)
 *         PLL2放大倍数=PLLmultiple_M/(PLLdivide_N*PLLmultiple_K3)
 * @param
 *        PLLmultiple_M:  0X04-0X3FFF(M要大于等于4,并且满足200MHZ<=(M*输入参考频率/N) <= 600MHZ)
 *        PLLdivide_N:  0X01-0XF(满足1MHZ<(输入参考频率/N)<50MHZ)
 * @retval void
 */
KF_INLINE void Clk_LL_SetPerPLLMultipleValue(const uint32_t PLLmultiple_M, const uint32_t PLLdivide_N)
{
    /*TODO: 外设PLL是否与系统PLL要求一致？*/
    KF_CLK_ASSERT(CHECK_PLL_MULTIPLE_MValue(PLLmultiple_M));
    KF_CLK_ASSERT(CHECK_PLL_MULTIPLE_NValue(PLLdivide_N));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_OSCWDRST_MASK;
    regValue |=  PLLmultiple_M<<HWIO_OSC_CTL0_OSC_CTL0_OSCWDRST_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->PERPLL_CTL0.bits.M, PLLmultiple_M);
#endif
#ifdef SIMULATION
     regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_OSC_CTL0_OSC_CTL0_GAINMOD_MASK;
    regValue |=  PLLdivide_N<<HWIO_OSC_CTL0_OSC_CTL0_GAINMOD_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->PERPLL_CTL0.bits.N, PLLdivide_N);
#endif
}

/*  PERPLL_CTL1 */

/**
 * @brief 外设PLL1 K2 分频器数值设置
 *
 *
 * @param PLLdivide_K2
 * @return
 */
KF_INLINE void Clk_LL_SetPerPLL1K2Value(const uint32_t PLLdivide_K2)
{
    KF_CLK_ASSERT(CHECK_PLL_MULTIPLE_K2Value(PLLdivide_K2));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL1_SYSPLL_CTL1_K2CLKDIV_MASK;
    regValue |=  PLLdivide_K2<<HWIO_SYSPLL_CTL1_SYSPLL_CTL1_K2CLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->PERPLL_CTL1.bits.K2CLKDIV, PLLdivide_K2);
#endif
}

/**
 * @brief 外设PLL2 K3 分频器数值设置
 *
 *
 * @param PLLdivide_K2
 * @return
 */
KF_INLINE void Clk_LL_SetPerPLL2K3Value(const uint32_t PLLmultiple_K3)
{
    KF_CLK_ASSERT(CHECK_PLL_MULTIPLE_K3Value(PLLmultiple_K3));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_PERPLL_CTL1_PERPLL_CTL1_K3CLKDIV_MASK;
    regValue |=  PLLmultiple_K3<<HWIO_PERPLL_CTL1_PERPLL_CTL1_K3CLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->PERPLL_CTL1.bits.K3CLKDIV, PLLmultiple_K3);
#endif
}

/*  DOMAIN_CTL */

/**
 * @brief 时钟域 source0 时钟源选择
 *
 *
 * @param Source0Source
 *        CLK_DOMAIN_SOURCE_INTHF100: INTHF100 被用作 fsource0 的时钟源
 *        CLK_DOMAIN_SOURCE_SYSPLL: SYSPLL0 被用作 fsource0 的时钟源
 *        CLK_DOMAIN_SOURCE_INTHF32: INTHF32 被用作 fsource0 的时钟源
 *        CLK_DOMAIN_SOURCE_EXTHF: EXTHF 被用作 fsource0 的时钟源
 *        CLK_DOMAIN_SOURCE_ADPLL: ADPLL 被用作 fsource0 的时钟源
 *        CLK_DOMAIN_SOURCE_PERPLL1: PERPLL1 被用作 fsource0 的时钟源
 *        CLK_DOMAIN_SOURCE_PERPLL2: PERPLL2 被用作 fsource0 的时钟源
 *        CLK_DOMAIN_SOURCE_DEFAULT: 此位保留，设置此位等于复位值
 * @return
 */
KF_INLINE void Clk_LL_SelectSource0ClockSource(const Clk_DomainClockSource0_t Source0Source)
{
    KF_CLK_ASSERT(CHECK_CLK_DOMAIN_CLOCKSOURCE(Source0Source));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_DOMAIN_CTL_DOMAIN_CTL_CLKSEL0_MASK;
    regValue |=  Source0Source<<HWIO_DOMAIN_CTL_DOMAIN_CTL_CLKSEL0_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->DOMAIN_CTL.bits.CLKSEL0, Source0Source);
#endif
}

/**
 * @brief 时钟域 source1 时钟源选择
 *
 *
 * @param Source1Source
 *        CLK_DOMAIN_SOURCE_INTHF100: INTHF100 被用作 fsource1 的时钟源
 *        CLK_DOMAIN_SOURCE_SYSPLL: SYSPLL0 被用作 fsource1 的时钟源
 *        CLK_DOMAIN_SOURCE_INTHF32: INTHF32 被用作 fsource1 的时钟源
 *        CLK_DOMAIN_SOURCE_EXTHF: EXTHF 被用作 fsource1 的时钟源
 *        CLK_DOMAIN_SOURCE_ADPLL: ADPLL 被用作 fsource1 的时钟源
 *        CLK_DOMAIN_SOURCE_PERPLL1: PERPLL1 被用作 fsource1 的时钟源
 *        CLK_DOMAIN_SOURCE_PERPLL2: PERPLL2 被用作 fsource1 的时钟源
 *        CLK_DOMAIN_SOURCE_DEFAULT: 此位保留，设置此位等于复位值
 * @return
 */
KF_INLINE void Clk_LL_SelectSource1ClockSource(const Clk_DomainClockSource1_t Source1Source)
{
    KF_CLK_ASSERT(CHECK_CLK_DOMAIN_CLOCKSOURCE(Source1Source));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_DOMAIN_CTL_DOMAIN_CTL_CLKSEL1_MASK;
    regValue |=  Source1Source<<HWIO_DOMAIN_CTL_DOMAIN_CTL_CLKSEL1_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->DOMAIN_CTL.bits.CLKSEL1, Source1Source);
#endif
}

/**
 * @brief 设置fsource1输入时钟2分频
 *
 *
 * @param Status
 *       false: fsource1输入时钟源不分频
 *       true:  fsource1输入时钟源2分频
 * @return
 */
KF_INLINE void Clk_LL_SetFsource1Freq2DivStatus(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_DOMAIN_CTL_DOMAIN_CTL_PLL1DIV_MASK;
    regValue |=  Status<<HWIO_DOMAIN_CTL_DOMAIN_CTL_PLL1DIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->DOMAIN_CTL.bits.PLL1DIV, Status);
#endif
}

/**
 * @brief 时钟域 source2 时钟源选择
 *
 *
 * @param Source0Source
 *        CLK_DOMAIN_SOURCE_INTHF100: INTHF100 被用作 fsource2 的时钟源
 *        CLK_DOMAIN_SOURCE_SYSPLL: SYSPLL0 被用作 fsource2 的时钟源
 *        CLK_DOMAIN_SOURCE_INTHF32: INTHF32 被用作 fsource2 的时钟源
 *        CLK_DOMAIN_SOURCE_EXTHF: EXTHF 被用作 fsource2 的时钟源
 *        CLK_DOMAIN_SOURCE_ADPLL: ADPLL 被用作 fsource2 的时钟源
 *        CLK_DOMAIN_SOURCE_PERPLL1: PERPLL1 被用作 fsource2 的时钟源
 *        CLK_DOMAIN_SOURCE_PERPLL2: PERPLL2 被用作 fsource2 的时钟源
 *        CLK_DOMAIN_SOURCE_DEFAULT: 此位保留，设置此位等于复位值
 * @return
 */
KF_INLINE void Clk_LL_SelectSource2ClockSource(const Clk_DomainClockSource2_t Source2Source)
{
    KF_CLK_ASSERT(CHECK_CLK_DOMAIN_CLOCKSOURCE(Source2Source));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_DOMAIN_CTL_DOMAIN_CTL_CLKSEL2_MASK;
    regValue |=  Source2Source<<HWIO_DOMAIN_CTL_DOMAIN_CTL_CLKSEL2_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->DOMAIN_CTL.bits.CLKSEL2, Source2Source);
#endif
}

/**
 * @brief 寄存器是否可以被一个新值更新，或者寄存器被锁定总线端的写操作不起作用
 * @attention 当 DOMAIN_CTL 被请求更新时，锁定状态位被设置，当更新完成时被释放
 * @retval bool
 *        false: 寄存器未被锁定可以更新
 *        true: 寄存器锁定不可以被更新
 */
KF_INLINE bool Clk_LL_GetDomainCtlRegLockStatus()
{
    return (bool)(CLK_PTR->DOMAIN_CTL.bits.LCKSTA);
}

/*  CDU_CTL0 */

/**
 * @brief 设置PERI时钟分频
 *
 *
 * @param PeriClkDiv
 *        CLK_CDU_COMMON_DIVISION_2: PERICLK = fsource0/2
 *        CLK_CDU_COMMON_DIVISION_3: PERICLK = fsource0/3
 *        CLK_CDU_COMMON_DIVISION_4: PERICLK = fsource0/4
 *        CLK_CDU_COMMON_DIVISION_5: PERICLK = fsource0/5
 *        CLK_CDU_COMMON_DIVISION_6: PERICLK = fsource0/6
 *        CLK_CDU_COMMON_DIVISION_7: PERICLK = fsource0/7
 *        CLK_CDU_COMMON_DIVISION_8: PERICLK = fsource0/8
 *        CLK_CDU_COMMON_DIVISION_9: PERICLK = fsource0/9
 *        CLK_CDU_COMMON_DIVISION_10: PERICLK = fsource0/10
 *        CLK_CDU_COMMON_DIVISION_11: PERICLK = fsource0/11
 *        CLK_CDU_COMMON_DIVISION_12: PERICLK = fsource0/12
 *        CLK_CDU_COMMON_DIVISION_13: PERICLK = fsource0/13
 *        CLK_CDU_COMMON_DIVISION_14: PERICLK = fsource0/14
 *        CLK_CDU_COMMON_DIVISION_15: PERICLK = fsource0/15
 * @return
 */
KF_INLINE void Clk_LL_SetPeriClkDivision(const Clk_CDU_CommonDivision_t PeriClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_PERICLK_DIVISION(PeriClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_CDU_CTL0_CDU_CTL0_PERICLKDIV_MASK;
    regValue |=  PeriClkDiv<<HWIO_CDU_CTL0_CDU_CTL0_PERICLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL0.bits.PERICLKDIV, PeriClkDiv);
#endif
}

/**
 * @brief 设置系统时钟分频
 *
 *
 * @param SysClkDiv
 *        CLK_CDU_COMMON_DIVISION_1: SYSCLK = fsource0
 *        CLK_CDU_COMMON_DIVISION_2: SYSCLK = fsource0/2
 *        CLK_CDU_COMMON_DIVISION_3: SYSCLK = fsource0/3
 *        CLK_CDU_COMMON_DIVISION_4: SYSCLK = fsource0/4
 *        CLK_CDU_COMMON_DIVISION_5: SYSCLK = fsource0/5
 *        CLK_CDU_COMMON_DIVISION_6: SYSCLK = fsource0/6
 *        CLK_CDU_COMMON_DIVISION_7: SYSCLK = fsource0/7
 *        CLK_CDU_COMMON_DIVISION_8: SYSCLK = fsource0/8
 *        CLK_CDU_COMMON_DIVISION_9: SYSCLK = fsource0/9
 *        CLK_CDU_COMMON_DIVISION_10: SYSCLK = fsource0/10
 *        CLK_CDU_COMMON_DIVISION_11: SYSCLK = fsource0/11
 *        CLK_CDU_COMMON_DIVISION_12: SYSCLK = fsource0/12
 *        CLK_CDU_COMMON_DIVISION_13: SYSCLK = fsource0/13
 *        CLK_CDU_COMMON_DIVISION_14: SYSCLK = fsource0/14
 *        CLK_CDU_COMMON_DIVISION_15: SYSCLK = fsource0/15
 * @return
 */
KF_INLINE void Clk_LL_SetSysClkDivision(const Clk_CDU_CommonDivision_t SysClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_SYSCLK_DIVISION(SysClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_CDU_CTL0_CDU_CTL0_SYSCLKDIV_MASK;
    regValue |=  SysClkDiv<<HWIO_CDU_CTL0_CDU_CTL0_SYSCLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL0.bits.SYSCLKDIV, SysClkDiv);
#endif
}

/**
 * @brief 设置TMR时钟分频
 *
 *
 * @param TmrClkDiv
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: TMRCLK = fsource0
 *        CLK_CDU_COMMON_DIVISION_2: TMRCLK = fsource0/2
 *        CLK_CDU_COMMON_DIVISION_3: TMRCLK = fsource0/3
 *        CLK_CDU_COMMON_DIVISION_4: TMRCLK = fsource0/4
 *        CLK_CDU_COMMON_DIVISION_5: TMRCLK = fsource0/5
 *        CLK_CDU_COMMON_DIVISION_6: TMRCLK = fsource0/6
 *        CLK_CDU_COMMON_DIVISION_7: TMRCLK = fsource0/7
 *        CLK_CDU_COMMON_DIVISION_8: TMRCLK = fsource0/8
 *        CLK_CDU_COMMON_DIVISION_9: TMRCLK = fsource0/9
 *        CLK_CDU_COMMON_DIVISION_10: TMRCLK = fsource0/10
 *        CLK_CDU_COMMON_DIVISION_11: TMRCLK = fsource0/11
 *        CLK_CDU_COMMON_DIVISION_12: TMRCLK = fsource0/12
 *        CLK_CDU_COMMON_DIVISION_13: TMRCLK = fsource0/13
 *        CLK_CDU_COMMON_DIVISION_14: TMRCLK = fsource0/14
 *        CLK_CDU_COMMON_DIVISION_15: TMRCLK = fsource0/15
 * @return
 */
KF_INLINE void Clk_LL_SetTmrClkDivision(const Clk_CDU_CommonDivision_t TmrClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(TmrClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_CDU_CTL0_CDU_CTL0_TMRCLKDIV_MASK;
    regValue |=  TmrClkDiv<<HWIO_CDU_CTL0_CDU_CTL0_TMRCLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL0.bits.TMRCLKDIV, TmrClkDiv);
#endif
}

/**
 * @brief 设置LP时钟分频
 *
 *
 * @param LPClkDiv
 *        CLK_CDU_LPCLK_DIVISION_DEFAULT:
 *        CLK_CDU_LPCLK_DIVISION_30: LPCLK= fsource0/30
 *        CLK_CDU_LPCLK_DIVISION_60: LPCLK= fsource0/60
 *        CLK_CDU_LPCLK_DIVISION_120: LPCLK= fsource0/120
 *        CLK_CDU_LPCLK_DIVISION_240: LPCLK= fsource0/240
 * @return
 */
KF_INLINE void Clk_LL_SetLPClkDivision(const Clk_CDU_LPClkDivision_t LPClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_LPCLK_DIVISION(LPClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_CDU_CTL0_CDU_CTL0_LPCLKDIV_MASK;
    regValue |=  LPClkDiv<<HWIO_CDU_CTL0_CDU_CTL0_LPCLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL0.bits.LPCLKDIV, LPClkDiv);
#endif
}

/**
 * @brief 更新请求
 * @details 新的寄存器参数传输到硬件
 *
 *
 * @return
 */
KF_INLINE void Clk_LL_SetCDUCTLUpdate()
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_CDU_CTL0_CDU_CTL0_UP_MASK;
    regValue |=  1U<<HWIO_CDU_CTL0_CDU_CTL0_UP_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL0.bits.UP, 1U);
#endif
}

/**
 * @brief 寄存器是否可以被一个新值更新，或者寄存器被锁定总线端的写操作不起作用
 * @attention 当 CDU_CTL0 被请求更新时，锁定状态位被设置，当更新完成时被释放
 * @retval bool
 *        false: 寄存器未被锁定可以更新
 *        true: 寄存器锁定不可以被更新
 */
KF_INLINE bool Clk_LL_GetCDUCTL0LockStatus()
{
    return (bool)(CLK_PTR->CDU_CTL0.bits.LCKSTA);
}

/*  CDU_CTL1 */

/**
 * @brief 设置Systickt时钟分频
 *
 *
 * @param SysticktClkDiv
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: STCLK = fsource0
 *        CLK_CDU_COMMON_DIVISION_2: STCLK = fsource0/2
 *        CLK_CDU_COMMON_DIVISION_3: STCLK = fsource0/3
 *        CLK_CDU_COMMON_DIVISION_4: STCLK = fsource0/4
 *        CLK_CDU_COMMON_DIVISION_5: STCLK = fsource0/5
 *        CLK_CDU_COMMON_DIVISION_6: STCLK = fsource0/6
 *        CLK_CDU_COMMON_DIVISION_7: STCLK = fsource0/7
 *        CLK_CDU_COMMON_DIVISION_8: STCLK = fsource0/8
 *        CLK_CDU_COMMON_DIVISION_9: STCLK = fsource0/9
 *        CLK_CDU_COMMON_DIVISION_10: STCLK = fsource0/10
 *        CLK_CDU_COMMON_DIVISION_11: STCLK = fsource0/11
 *        CLK_CDU_COMMON_DIVISION_12: STCLK = fsource0/12
 *        CLK_CDU_COMMON_DIVISION_13: STCLK = fsource0/13
 *        CLK_CDU_COMMON_DIVISION_14: STCLK = fsource0/14
 *        CLK_CDU_COMMON_DIVISION_15: STCLK = fsource0/15
 * @return
 */
KF_INLINE void Clk_LL_SetSystickClkDivision(const Clk_CDU_CommonDivision_t SysticktClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(SysticktClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_CDU_CTL1_CDU_CTL1_STCLKDIV_MASK;
    regValue |=  SysticktClkDiv<<HWIO_CDU_CTL1_CDU_CTL1_STCLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL1.bits.STCLKDIV, SysticktClkDiv);
#endif
}

/**
 * @brief 设置CANH时钟分频
 *
 *
 * @param CANHClkDiv
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: CANHCLK = fsource0
 *        CLK_CDU_COMMON_DIVISION_2: CANHCLK = fsource0/2
 *        CLK_CDU_COMMON_DIVISION_3: CANHCLK = fsource0/3
 *        CLK_CDU_COMMON_DIVISION_4: CANHCLK = fsource0/4
 *        CLK_CDU_COMMON_DIVISION_5: CANHCLK = fsource0/5
 *        CLK_CDU_COMMON_DIVISION_6: CANHCLK = fsource0/6
 *        CLK_CDU_COMMON_DIVISION_7: CANHCLK = fsource0/7
 *        CLK_CDU_COMMON_DIVISION_8: CANHCLK = fsource0/8
 *        CLK_CDU_COMMON_DIVISION_9: CANHCLK = fsource0/9
 *        CLK_CDU_COMMON_DIVISION_10: CANHCLK = fsource0/10
 *        CLK_CDU_COMMON_DIVISION_11: CANHCLK = fsource0/11
 *        CLK_CDU_COMMON_DIVISION_12: CANHCLK = fsource0/12
 *        CLK_CDU_COMMON_DIVISION_13: CANHCLK = fsource0/13
 *        CLK_CDU_COMMON_DIVISION_14: CANHCLK = fsource0/14
 *        CLK_CDU_COMMON_DIVISION_15: CANHCLK = fsource0/15
 * @return
 */
KF_INLINE void Clk_LL_SetCANHClkDivision(const Clk_CDU_CommonDivision_t CANHClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(CANHClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_CDU_CTL1_CDU_CTL1_CANHCLKDIV_MASK;
    regValue |=  CANHClkDiv<<HWIO_CDU_CTL1_CDU_CTL1_CANHCLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL1.bits.CANHCLKDIV, CANHClkDiv);
#endif
}

/**
 * @brief 设置REFCLK1时钟分频
 *
 *
 * @param RefClk1Div
 *        CLK_CDU_REFCLK1_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_REFCLK1_DIVISION_1: REFCLK1 = fsource0
 *        CLK_CDU_REFCLK1_DIVISION_2: REFCLK1 = fsource0/2
 *        CLK_CDU_REFCLK1_DIVISION_3: REFCLK1 = fsource0/3
 *        CLK_CDU_REFCLK1_DIVISION_4: REFCLK1 = fsource0/4
 *        CLK_CDU_REFCLK1_DIVISION_5: REFCLK1 = fsource0/5
 *        CLK_CDU_REFCLK1_DIVISION_6: REFCLK1 = fsource0/6
 *        CLK_CDU_REFCLK1_DIVISION_7: REFCLK1 = fsource0/7
 *        CLK_CDU_REFCLK1_DIVISION_8: REFCLK1 = fsource0/8
 *        CLK_CDU_REFCLK1_DIVISION_9: REFCLK1 = fsource0/9
 *        CLK_CDU_REFCLK1_DIVISION_10: REFCLK1 = fsource0/10
 *        CLK_CDU_REFCLK1_DIVISION_11: REFCLK1 = fsource0/11
 *        CLK_CDU_REFCLK1_DIVISION_12: REFCLK1 = fsource0/12
 *        CLK_CDU_REFCLK1_DIVISION_13: REFCLK1 = fsource0/13
 *        CLK_CDU_REFCLK1_DIVISION_14: REFCLK1 = fsource0/14
 *        CLK_CDU_REFCLK1_DIVISION_15: REFCLK1 = fsource0/15
 *        CLK_CDU_REFCLK1_DIVISION_16: REFCLK1 = fsource0/16
 *        CLK_CDU_REFCLK1_DIVISION_17: REFCLK1 = fsource0/17
 *        CLK_CDU_REFCLK1_DIVISION_18: REFCLK1 = fsource0/18
 *        CLK_CDU_REFCLK1_DIVISION_19: REFCLK1 = fsource0/19
 *        CLK_CDU_REFCLK1_DIVISION_20: REFCLK1 = fsource0/20
 *        CLK_CDU_REFCLK1_DIVISION_21: REFCLK1 = fsource0/21
 *        CLK_CDU_REFCLK1_DIVISION_22: REFCLK1 = fsource0/22
 *        CLK_CDU_REFCLK1_DIVISION_23: REFCLK1 = fsource0/23
 *        CLK_CDU_REFCLK1_DIVISION_24: REFCLK1 = fsource0/24
 *        CLK_CDU_REFCLK1_DIVISION_25: REFCLK1 = fsource0/25
 *        CLK_CDU_REFCLK1_DIVISION_26: REFCLK1 = fsource0/26
 *        CLK_CDU_REFCLK1_DIVISION_27: REFCLK1 = fsource0/27
 *        CLK_CDU_REFCLK1_DIVISION_28: REFCLK1 = fsource0/28
 *        CLK_CDU_REFCLK1_DIVISION_29: REFCLK1 = fsource0/29
 *        CLK_CDU_REFCLK1_DIVISION_30: REFCLK1 = fsource0/30
 *        CLK_CDU_REFCLK1_DIVISION_31: REFCLK1 = fsource0/31
 * @return
 */
KF_INLINE void Clk_LL_SetRefClk1Division(const Clk_CDU_RefClkDivision_t RefClk1Div)
{
    KF_CLK_ASSERT(CHECK_CDU_REFCLK_DIVISION(RefClk1Div));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_CDU_CTL1_CDU_CTL1_REFCLK1CLKDIV_MASK;
    regValue |=  RefClk1Div<<HWIO_CDU_CTL1_CDU_CTL1_REFCLK1CLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL1.bits.REFCLK1CLKDIV, RefClk1Div);
#endif
}

/**
 * @brief 设置REFCLK1时钟分频
 *
 *
 * @param RefClk2Div
 *        CLK_CDU_REFCLK2_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_REFCLK2_DIVISION_1: REFCLK2 = fSRCREFCLK2
 *        CLK_CDU_REFCLK2_DIVISION_2: REFCLK2 = fSRCREFCLK2/2
 *        CLK_CDU_REFCLK2_DIVISION_3: REFCLK2 = fSRCREFCLK2/3
 *        CLK_CDU_REFCLK2_DIVISION_4: REFCLK2 = fSRCREFCLK2/4
 *        CLK_CDU_REFCLK2_DIVISION_5: REFCLK2 = fSRCREFCLK2/5
 *        CLK_CDU_REFCLK2_DIVISION_6: REFCLK2 = fSRCREFCLK2/6
 *        CLK_CDU_REFCLK2_DIVISION_7: REFCLK2 = fSRCREFCLK2/7
 *        CLK_CDU_REFCLK2_DIVISION_8: REFCLK2 = fSRCREFCLK2/8
 *        CLK_CDU_REFCLK2_DIVISION_9: REFCLK2 = fSRCREFCLK2/9
 *        CLK_CDU_REFCLK2_DIVISION_10: REFCLK2 = fSRCREFCLK2/10
 *        CLK_CDU_REFCLK2_DIVISION_11: REFCLK2 = fSRCREFCLK2/11
 *        CLK_CDU_REFCLK2_DIVISION_12: REFCLK2 = fSRCREFCLK2/12
 *        CLK_CDU_REFCLK2_DIVISION_13: REFCLK2 = fSRCREFCLK2/13
 *        CLK_CDU_REFCLK2_DIVISION_14: REFCLK2 = fSRCREFCLK2/14
 *        CLK_CDU_REFCLK2_DIVISION_15: REFCLK2 = fSRCREFCLK2/15
 *        CLK_CDU_REFCLK2_DIVISION_16: REFCLK2 = fSRCREFCLK2/16
 *        CLK_CDU_REFCLK2_DIVISION_17: REFCLK2 = fSRCREFCLK2/17
 *        CLK_CDU_REFCLK2_DIVISION_18: REFCLK2 = fSRCREFCLK2/18
 *        CLK_CDU_REFCLK2_DIVISION_19: REFCLK2 = fSRCREFCLK2/19
 *        CLK_CDU_REFCLK2_DIVISION_20: REFCLK2 = fSRCREFCLK2/20
 *        CLK_CDU_REFCLK2_DIVISION_21: REFCLK2 = fSRCREFCLK2/21
 *        CLK_CDU_REFCLK2_DIVISION_22: REFCLK2 = fSRCREFCLK2/22
 *        CLK_CDU_REFCLK2_DIVISION_23: REFCLK2 = fSRCREFCLK2/23
 *        CLK_CDU_REFCLK2_DIVISION_24: REFCLK2 = fSRCREFCLK2/24
 *        CLK_CDU_REFCLK2_DIVISION_25: REFCLK2 = fSRCREFCLK2/25
 *        CLK_CDU_REFCLK2_DIVISION_26: REFCLK2 = fSRCREFCLK2/26
 *        CLK_CDU_REFCLK2_DIVISION_27: REFCLK2 = fSRCREFCLK2/27
 *        CLK_CDU_REFCLK2_DIVISION_28: REFCLK2 = fSRCREFCLK2/28
 *        CLK_CDU_REFCLK2_DIVISION_29: REFCLK2 = fSRCREFCLK2/29
 *        CLK_CDU_REFCLK2_DIVISION_30: REFCLK2 = fSRCREFCLK2/30
 *        CLK_CDU_REFCLK2_DIVISION_31: REFCLK2 = fSRCREFCLK2/31
 * @return
 */
KF_INLINE void Clk_LL_SetRefClk2Division(const Clk_CDU_RefClkDivision_t RefClk2Div)
{
    KF_CLK_ASSERT(CHECK_CDU_REFCLK_DIVISION(RefClk2Div));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_CDU_CTL1_CDU_CTL1_REFCLK2CLKDIV_MASK;
    regValue |=  RefClk2Div<<HWIO_CDU_CTL1_CDU_CTL1_REFCLK2CLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL1.bits.REFCLK2CLKDIV, RefClk2Div);
#endif
}

/**
 * @brief SRCREFCLK2 时钟源选择
 *
 * @param RefClk2Source
 *        CLK_CDU_REFCLK2_SOURCE_FSOURCE1: fsource1 被用作 fSRCREFCLK2 的时钟源
 *        CLK_CDU_REFCLK2_SOURCE_FSOURCE2: fsource2 被用作 fSRCREFCLK2 的时钟源
 * @return
 */
KF_INLINE void Clk_LL_SelectRefClk2Source(const Clk_CDU_RefClk2Source_t RefClk2Source)
{
    KF_CLK_ASSERT(CHECK_CDU_REFCLK2_SOURCE(RefClk2Source));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_CDU_CTL1_CDU_CTL1_REFCLK2SEL_MASK;
    regValue |=  RefClk2Source<<HWIO_CDU_CTL1_CDU_CTL1_REFCLK2SEL_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL1.bits.REFCLK2SEL, RefClk2Source);
#endif
}

/**
 * @brief MSC 时钟分频选择
 *
 * @param MscClkSource
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: MSCCLK = fSRCMSC
 *        CLK_CDU_COMMON_DIVISION_2: MSCCLK = fSRCMSC/2
 *        CLK_CDU_COMMON_DIVISION_3: MSCCLK = fSRCMSC/3
 *        CLK_CDU_COMMON_DIVISION_4: MSCCLK = fSRCMSC/4
 *        CLK_CDU_COMMON_DIVISION_5: MSCCLK = fSRCMSC/5
 *        CLK_CDU_COMMON_DIVISION_6: MSCCLK = fSRCMSC/6
 *        CLK_CDU_COMMON_DIVISION_7: MSCCLK = fSRCMSC/7
 *        CLK_CDU_COMMON_DIVISION_8: MSCCLK = fSRCMSC/8
 *        CLK_CDU_COMMON_DIVISION_9: MSCCLK = fSRCMSC/9
 *        CLK_CDU_COMMON_DIVISION_10: MSCCLK = fSRCMSC/10
 *        CLK_CDU_COMMON_DIVISION_11: MSCCLK = fSRCMSC/11
 *        CLK_CDU_COMMON_DIVISION_12: MSCCLK = fSRCMSC/12
 *        CLK_CDU_COMMON_DIVISION_13: MSCCLK = fSRCMSC/13
 *        CLK_CDU_COMMON_DIVISION_14: MSCCLK = fSRCMSC/14
 *        CLK_CDU_COMMON_DIVISION_15: MSCCLK = fSRCMSC/15
 * @return
 */
KF_INLINE void Clk_LL_SetMSCClkDivision(const Clk_CDU_CommonDivision_t MscClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(MscClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_CDU_CTL1_CDU_CTL1_MSCCLKDIV_MASK;
    regValue |=  MscClkDiv<<HWIO_CDU_CTL1_CDU_CTL1_MSCCLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL1.bits.MSCCLKDIV, MscClkDiv);
#endif
}

/**
 * @brief MSCCLKSEL 时钟源选择
 *
 * @param MSCClkSource
 *        CLK_CDU_MSC_SOURCE_FSOURCE1: fsource1 被用作 fSRCMSC 的时钟源
 *        CLK_CDU_MSC_SOURCE_FSOURCE2: fsource2 被用作 fSRCMSC 的时钟源
 * @return
 */
KF_INLINE void Clk_LL_SelectMSCClk2Source(const Clk_CDU_MscClkSource_t MSCClkSource)
{
    KF_CLK_ASSERT(CHECK_CDU_REFCLK2_SOURCE(MSCClkSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_CDU_CTL1_CDU_CTL1_MSCCLKSEL_MASK;
    regValue |=  MSCClkSource<<HWIO_CDU_CTL1_CDU_CTL1_MSCCLKSEL_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL1.bits.MSCCLKSEL, MSCClkSource);
#endif
}

/**
 * @brief RTC 时钟分频选择
 *
 * @param RTCClkSource
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: RTCCLK = fSRCRTC
 *        CLK_CDU_COMMON_DIVISION_2: RTCCLK = fSRCRTC/2
 *        CLK_CDU_COMMON_DIVISION_3: RTCCLK = fSRCRTC/3
 *        CLK_CDU_COMMON_DIVISION_4: RTCCLK = fSRCRTC/4
 *        CLK_CDU_COMMON_DIVISION_5: RTCCLK = fSRCRTC/5
 *        CLK_CDU_COMMON_DIVISION_6: RTCCLK = fSRCRTC/6
 *        CLK_CDU_COMMON_DIVISION_7: RTCCLK = fSRCRTC/7
 *        CLK_CDU_COMMON_DIVISION_8: RTCCLK = fSRCRTC/8
 *        CLK_CDU_COMMON_DIVISION_9: RTCCLK = fSRCRTC/9
 *        CLK_CDU_COMMON_DIVISION_10: RTCCLK = fSRCRTC/10
 *        CLK_CDU_COMMON_DIVISION_11: RTCCLK = fSRCRTC/11
 *        CLK_CDU_COMMON_DIVISION_12: RTCCLK = fSRCRTC/12
 *        CLK_CDU_COMMON_DIVISION_13: RTCCLK = fSRCRTC/13
 *        CLK_CDU_COMMON_DIVISION_14: RTCCLK = fSRCRTC/14
 *        CLK_CDU_COMMON_DIVISION_15: RTCCLK = fSRCRTC/15
 * @return
 */
KF_INLINE void Clk_LL_SetRTCClkDivision(const Clk_CDU_CommonDivision_t RTCClkDivision)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(RTCClkDivision));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_CDU_CTL1_CDU_CTL1_RTCCLKDIV_MASK;
    regValue |=  RTCClkDivision<<HWIO_CDU_CTL1_CDU_CTL1_RTCCLKDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL1.bits.RTCCLKDIV, RTCClkDivision);
#endif
}

/**
 * @brief RTCCLKSEL 时钟源选择
 *
 * @param RTCClkSource
 *        CLK_CDU_RTC_SOURCE_INTHF: INTHF100 被用作 fSRCRTC 的时钟源
 *        CLK_CDU_RTC_SOURCE_EXTHF: EXTHF 被用作 fSRCRTC 的时钟源
 * @return
 */
KF_INLINE void Clk_LL_SelecRTCClkSource(const Clk_CDU_RtcClkSource_t RTCClkSource)
{
    KF_CLK_ASSERT(CHECK_CDU_RTC_SOURCE(RTCClkSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_CDU_CTL1_CDU_CTL1_RTCCLKSEL_MASK;
    regValue |=  RTCClkSource<<HWIO_CDU_CTL1_CDU_CTL1_RTCCLKSEL_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL1.bits.RTCCLKSEL, RTCClkSource);
#endif
}

/**
 * @brief 寄存器是否可以被一个新值更新，或者寄存器被锁定总线端的写操作不起作用
 * @attention 当 CDU_CTL1 被请求更新时，锁定状态位被设置，当更新完成时被释放
 * @retval bool
 *        false: 寄存器未被锁定可以更新
 *        true: 寄存器锁定不可以被更新
 */
KF_INLINE bool Clk_LL_GetCDUCTL1LockStatus()
{
    return (bool)(CLK_PTR->CDU_CTL1.bits.LCKSTA);
}

/*  CDU_CTL2 */

/**
 * @brief SPI 时钟分频选择
 *
 * @param SpiClkDiv
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: SPICLK = fSRCSPI
 *        CLK_CDU_COMMON_DIVISION_2: SPICLK = fSRCSPI/2
 *        CLK_CDU_COMMON_DIVISION_3: SPICLK = fSRCSPI/3
 *        CLK_CDU_COMMON_DIVISION_4: SPICLK = fSRCSPI/4
 *        CLK_CDU_COMMON_DIVISION_5: SPICLK = fSRCSPI/5
 *        CLK_CDU_COMMON_DIVISION_6: SPICLK = fSRCSPI/6
 *        CLK_CDU_COMMON_DIVISION_7: SPICLK = fSRCSPI/7
 *        CLK_CDU_COMMON_DIVISION_8: SPICLK = fSRCSPI/8
 *        CLK_CDU_COMMON_DIVISION_9: SPICLK = fSRCSPI/9
 *        CLK_CDU_COMMON_DIVISION_10: SPICLK = fSRCSPI/10
 *        CLK_CDU_COMMON_DIVISION_11: SPICLK = fSRCSPI/11
 *        CLK_CDU_COMMON_DIVISION_12: SPICLK = fSRCSPI/12
 *        CLK_CDU_COMMON_DIVISION_13: SPICLK = fSRCSPI/13
 *        CLK_CDU_COMMON_DIVISION_14: SPICLK = fSRCSPI/14
 *        CLK_CDU_COMMON_DIVISION_15: SPICLK = fSRCSPI/15
 * @return
 */
KF_INLINE void Clk_LL_SetSpiClkDivision(const Clk_CDU_CommonDivision_t SpiClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(SpiClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_SPICLKDIV_MASK;
    regValue |=  SpiClkDiv<<HWIO_CDU_CTL2_CDU_CTL2_SPICLKDIV_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.SPICLKDIV, SpiClkDiv);
#endif
}

/**
 * @brief SPICLKSEL 时钟源选择
 *
 * @param SpiClkSource
 *        CLK_CDU_SPI_SOURCE_FSOURCE1: fsource1 被用作 fSRCSPI 的时钟源
 *        CLK_CDU_SPI_SOURCE_FSOURCE2: fsource2 被用作 fSRCSPI 的时钟源
 * @return
 */
KF_INLINE void Clk_LL_SelectSpiClkSource(const Clk_CDU_SpiClkSource_t SpiClkSource)
{
    KF_CLK_ASSERT(CHECK_CDU_SPICLK_SOURCE(SpiClkSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_SPICLKSEL_MASK;
    regValue |=  SpiClkSource<<HWIO_CDU_CTL2_CDU_CTL2_SPICLKSEL_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.SPICLKSEL, SpiClkSource);
#endif
}

/**
 * @brief ADC 时钟分频选择
 *
 * @param AdcClkDiv
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: ADCCLK = fSRCADC
 *        CLK_CDU_COMMON_DIVISION_2: ADCCLK = fSRCADC/2
 *        CLK_CDU_COMMON_DIVISION_3: ADCCLK = fSRCADC/3
 *        CLK_CDU_COMMON_DIVISION_4: ADCCLK = fSRCADC/4
 *        CLK_CDU_COMMON_DIVISION_5: ADCCLK = fSRCADC/5
 *        CLK_CDU_COMMON_DIVISION_6: ADCCLK = fSRCADC/6
 *        CLK_CDU_COMMON_DIVISION_7: ADCCLK = fSRCADC/7
 *        CLK_CDU_COMMON_DIVISION_8: ADCCLK = fSRCADC/8
 *        CLK_CDU_COMMON_DIVISION_9: ADCCLK = fSRCADC/9
 *        CLK_CDU_COMMON_DIVISION_10: ADCCLK = fSRCADC/10
 *        CLK_CDU_COMMON_DIVISION_11: ADCCLK = fSRCADC/11
 *        CLK_CDU_COMMON_DIVISION_12: ADCCLK = fSRCADC/12
 *        CLK_CDU_COMMON_DIVISION_13: ADCCLK = fSRCADC/13
 *        CLK_CDU_COMMON_DIVISION_14: ADCCLK = fSRCADC/14
 *        CLK_CDU_COMMON_DIVISION_15: ADCCLK = fSRCADC/15
 * @return
 */
KF_INLINE void Clk_LL_SetAdcClkDivision(const Clk_CDU_CommonDivision_t AdcClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(AdcClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_ADCCLKDIV_MASK;
    regValue |=  AdcClkDiv<<HWIO_CDU_CTL2_CDU_CTL2_ADCCLKDIV_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.ADCCLKDIV, AdcClkDiv);
#endif
}

/**
 * @brief ADCCLKSEL 时钟源选择
 *
 * @param AdcClkSource
 *        CLK_CDU_ADC_SOURCE_FSOURCE1: fsource1 被用作 fSRCADC 的时钟源
 *        CLK_CDU_ADC_SOURCE_FSOURCE2: fsource2 被用作 fSRCADC 的时钟源
 * @return
 */
KF_INLINE void Clk_LL_SelectAdcClkSource(const Clk_CDU_AdcClkSource_t AdcClkSource)
{
    KF_CLK_ASSERT(CHECK_CDU_ADCCLK_SOURCE(AdcClkSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_ADCCLKSEL_MASK;
    regValue |=  AdcClkSource<<HWIO_CDU_CTL2_CDU_CTL2_ADCCLKSEL_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.ADCCLKSEL, AdcClkSource);
#endif
}

/**
 * @brief I2C 时钟分频选择
 *
 * @param I2CClkDiv
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: I2CCLK = fSRCI2C
 *        CLK_CDU_COMMON_DIVISION_2: I2CCLK = fSRCI2C/2
 *        CLK_CDU_COMMON_DIVISION_3: I2CCLK = fSRCI2C/3
 *        CLK_CDU_COMMON_DIVISION_4: I2CCLK = fSRCI2C/4
 *        CLK_CDU_COMMON_DIVISION_5: I2CCLK = fSRCI2C/5
 *        CLK_CDU_COMMON_DIVISION_6: I2CCLK = fSRCI2C/6
 *        CLK_CDU_COMMON_DIVISION_7: I2CCLK = fSRCI2C/7
 *        CLK_CDU_COMMON_DIVISION_8: I2CCLK = fSRCI2C/8
 *        CLK_CDU_COMMON_DIVISION_9: I2CCLK = fSRCI2C/9
 *        CLK_CDU_COMMON_DIVISION_10: I2CCLK = fSRCI2C/10
 *        CLK_CDU_COMMON_DIVISION_11: I2CCLK = fSRCI2C/11
 *        CLK_CDU_COMMON_DIVISION_12: I2CCLK = fSRCI2C/12
 *        CLK_CDU_COMMON_DIVISION_13: I2CCLK = fSRCI2C/13
 *        CLK_CDU_COMMON_DIVISION_14: I2CCLK = fSRCI2C/14
 *        CLK_CDU_COMMON_DIVISION_15: I2CCLK = fSRCI2C/15
 * @return
 */
KF_INLINE void Clk_LL_SetI2CClkDivision(const Clk_CDU_CommonDivision_t I2CClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(I2CClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_I2CCLKDIV_MASK;
    regValue |=  I2CClkDiv<<HWIO_CDU_CTL2_CDU_CTL2_I2CCLKDIV_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.I2CCLKDIV, I2CClkDiv);
#endif
}

/**
 * @brief I2CCLKSEL 时钟源选择
 *
 * @param I2CClkSource
 *        CLK_CDU_I2C_SOURCE_FSOURCE1: fsource1 被用作 fSRCI2C 的时钟源
 *        CLK_CDU_I2C_SOURCE_FSOURCE2: fsource2 被用作 fSRCI2C 的时钟源
 * @return
 */
KF_INLINE void Clk_LL_SelectI2CClkSource(const Clk_CDU_I2CClkSource_t I2CClkSource)
{
    KF_CLK_ASSERT(CHECK_CDU_I2CCLK_SOURCE(I2CClkSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_I2CCLKSEL_MASK;
    regValue |=  I2CClkSource<<HWIO_CDU_CTL2_CDU_CTL2_I2CCLKSEL_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.I2CCLKSEL, I2CClkSource);
#endif
}

/**
 * @brief CAN 时钟分频选择
 *
 * @param CANClkDiv
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: CANCLK = fSRCCAN
 *        CLK_CDU_COMMON_DIVISION_2: CANCLK = fSRCCAN/2
 *        CLK_CDU_COMMON_DIVISION_3: CANCLK = fSRCCAN/3
 *        CLK_CDU_COMMON_DIVISION_4: CANCLK = fSRCCAN/4
 *        CLK_CDU_COMMON_DIVISION_5: CANCLK = fSRCCAN/5
 *        CLK_CDU_COMMON_DIVISION_6: CANCLK = fSRCCAN/6
 *        CLK_CDU_COMMON_DIVISION_7: CANCLK = fSRCCAN/7
 *        CLK_CDU_COMMON_DIVISION_8: CANCLK = fSRCCAN/8
 *        CLK_CDU_COMMON_DIVISION_9: CANCLK = fSRCCAN/9
 *        CLK_CDU_COMMON_DIVISION_10: CANCLK = fSRCCAN/10
 *        CLK_CDU_COMMON_DIVISION_11: CANCLK = fSRCCAN/11
 *        CLK_CDU_COMMON_DIVISION_12: CANCLK = fSRCCAN/12
 *        CLK_CDU_COMMON_DIVISION_13: CANCLK = fSRCCAN/13
 *        CLK_CDU_COMMON_DIVISION_14: CANCLK = fSRCCAN/14
 *        CLK_CDU_COMMON_DIVISION_15: CANCLK = fSRCCAN/15
 * @return
 */
KF_INLINE void Clk_LL_SetCANClkDivision(const Clk_CDU_CommonDivision_t CANClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(CANClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_CANCLKDIV_MASK;
    regValue |=  CANClkDiv<<HWIO_CDU_CTL2_CDU_CTL2_CANCLKDIV_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.CANCLKDIV, CANClkDiv);
#endif
}

/**
 * @brief CAN 时钟源选择
 *
 * @param CANClkSource
 *        CLK_CDU_CAN_SOURCE_FSOURCE1: fsource1 被用作 fSRCCAN 的时钟源
 *        CLK_CDU_CAN_SOURCE_FSOURCE2: fsource2 被用作 fSRCCAN 的时钟源
 * @return
 */
KF_INLINE void Clk_LL_SelectCANClkSource(const Clk_CDU_CANClkSource_t CANClkSource)
{
    KF_CLK_ASSERT(CHECK_CDU_ADCCLK_SOURCE(CANClkSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_CANCLKSEL_MASK;
    regValue |=  CANClkSource<<HWIO_CDU_CTL2_CDU_CTL2_CANCLKSEL_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.CANCLKSEL, CANClkSource);
#endif
}

/**
 * @brief UTLINF 时钟分频选择
 *
 * @param UTLINFClkDiv
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: UTLINFCLK = fSRCUTLINF
 *        CLK_CDU_COMMON_DIVISION_2: UTLINFCLK = fSRCUTLINF/2
 *        CLK_CDU_COMMON_DIVISION_3: UTLINFCLK = fSRCUTLINF/3
 *        CLK_CDU_COMMON_DIVISION_4: UTLINFCLK = fSRCUTLINF/4
 *        CLK_CDU_COMMON_DIVISION_5: UTLINFCLK = fSRCUTLINF/5
 *        CLK_CDU_COMMON_DIVISION_6: UTLINFCLK = fSRCUTLINF/6
 *        CLK_CDU_COMMON_DIVISION_7: UTLINFCLK = fSRCUTLINF/7
 *        CLK_CDU_COMMON_DIVISION_8: UTLINFCLK = fSRCUTLINF/8
 *        CLK_CDU_COMMON_DIVISION_9: UTLINFCLK = fSRCUTLINF/9
 *        CLK_CDU_COMMON_DIVISION_10: UTLINFCLK = fSRCUTLINF/10
 *        CLK_CDU_COMMON_DIVISION_11: UTLINFCLK = fSRCUTLINF/11
 *        CLK_CDU_COMMON_DIVISION_12: UTLINFCLK = fSRCUTLINF/12
 *        CLK_CDU_COMMON_DIVISION_13: UTLINFCLK = fSRCUTLINF/13
 *        CLK_CDU_COMMON_DIVISION_14: UTLINFCLK = fSRCUTLINF/14
 *        CLK_CDU_COMMON_DIVISION_15: UTLINFCLK = fSRCUTLINF/15
 * @return
 */
KF_INLINE void Clk_LL_SetUTLINFClkDivision(const Clk_CDU_CommonDivision_t UTLINFClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(UTLINFClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_UTLINFCLKDIV_MASK;
    regValue |=  UTLINFClkDiv<<HWIO_CDU_CTL2_CDU_CTL2_UTLINFCLKDIV_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.UTLINFCLKDIV, UTLINFClkDiv);
#endif
}

/**
 * @brief UTLINF 时钟源选择
 *
 * @param UTLINFClkSource
 *        CLK_CDU_UTLINF_SOURCE_FSOURCE1: fsource1 被用作 fSRCUTLINF 的时钟源
 *        CLK_CDU_UTLINF_SOURCE_FSOURCE2: fsource2 被用作 fSRCUTLINF 的时钟源
 * @return
 */
KF_INLINE void Clk_LL_SelectUTLINFClkSource(const Clk_CDU_UTLINFClkSource_t UTLINFClkSource)
{
    KF_CLK_ASSERT(CHECK_CDU_UTLINFCLK_SOURCE(UTLINFClkSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_UTLINFCLKSEL_MASK;
    regValue |=  UTLINFClkSource<<HWIO_CDU_CTL2_CDU_CTL2_UTLINFCLKSEL_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.UTLINFCLKSEL, UTLINFClkSource);
#endif
}

/**
 * @brief UTLINS 时钟分频选择
 *
 * @param UTLINSClkDiv
 *        CLK_CDU_COMMON_DIVISION_OFF: 关闭时钟
 *        CLK_CDU_COMMON_DIVISION_1: UTLINSCLK = fSRCUTLINS
 *        CLK_CDU_COMMON_DIVISION_2: UTLINSCLK = fSRCUTLINS/2
 *        CLK_CDU_COMMON_DIVISION_3: UTLINSCLK = fSRCUTLINS/3
 *        CLK_CDU_COMMON_DIVISION_4: UTLINSCLK = fSRCUTLINS/4
 *        CLK_CDU_COMMON_DIVISION_5: UTLINSCLK = fSRCUTLINS/5
 *        CLK_CDU_COMMON_DIVISION_6: UTLINSCLK = fSRCUTLINS/6
 *        CLK_CDU_COMMON_DIVISION_7: UTLINSCLK = fSRCUTLINS/7
 *        CLK_CDU_COMMON_DIVISION_8: UTLINSCLK = fSRCUTLINS/8
 *        CLK_CDU_COMMON_DIVISION_9: UTLINSCLK = fSRCUTLINS/9
 *        CLK_CDU_COMMON_DIVISION_10: UTLINSCLK = fSRCUTLINS/10
 *        CLK_CDU_COMMON_DIVISION_11: UTLINSCLK = fSRCUTLINS/11
 *        CLK_CDU_COMMON_DIVISION_12: UTLINSCLK = fSRCUTLINS/12
 *        CLK_CDU_COMMON_DIVISION_13: UTLINSCLK = fSRCUTLINS/13
 *        CLK_CDU_COMMON_DIVISION_14: UTLINSCLK = fSRCUTLINS/14
 *        CLK_CDU_COMMON_DIVISION_15: UTLINSCLK = fSRCUTLINS/15
 * @return
 */
KF_INLINE void Clk_LL_SetUTLINSClkDivision(const Clk_CDU_CommonDivision_t UTLINSClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_COMMON_DIVISION(UTLINSClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_UTLINSCLKDIV_MASK;
    regValue |=  UTLINSClkDiv<<HWIO_CDU_CTL2_CDU_CTL2_UTLINSCLKDIV_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.UTLINSCLKDIV, UTLINSClkDiv);
#endif
}

/**
 * @brief UTLINS 时钟源选择
 *
 * @param UTLINSClkSource
 *        CLK_CDU_UTLINF_SOURCE_FSOURCE1: fsource1 被用作 fSRCUTLINF 的时钟源
 *        CLK_CDU_UTLINF_SOURCE_FSOURCE2: fsource2 被用作 fSRCUTLINF 的时钟源
 * @return
 */
KF_INLINE void Clk_LL_SelectUTLINSClkSource(const Clk_CDU_UTLINSClkSource_t UTLINSClkSource)
{
    KF_CLK_ASSERT(CHECK_CDU_UTLINSCLK_SOURCE(UTLINSClkSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKSYS_CTL2_ADDR );
    regValue &= ~HWIO_CDU_CTL2_CDU_CTL2_UTLINSCLKSEL_MASK;
    regValue |=  UTLINSClkSource<<HWIO_CDU_CTL2_CDU_CTL2_UTLINSCLKSEL_SHFT;
    REG_WRITE(HWIO_CLKSYS_CTL2_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL2.bits.UTLINSCLKSEL, UTLINSClkSource);
#endif
}

/**
 * @brief 寄存器是否可以被一个新值更新，或者寄存器被锁定总线端的写操作不起作用
 * @attention 当 CDU_CTL2 被请求更新时，锁定状态位被设置，当更新完成时被释放
 * @retval bool
 *        false: 寄存器未被锁定可以更新
 *        true: 寄存器锁定不可以被更新
 */
KF_INLINE bool Clk_LL_GetCDUCTL2LockStatus()
{
    return (bool)(CLK_PTR->CDU_CTL2.bits.LCKSTA);
}

/*  CDU_CTL3 */

/**
 * @brief 设置 CPU0 分频器重载值
 * @details 生成的 CUP0 频率（性能）被配置成CPU0CLK=SYSCLK*(64-CPU0CLKDIV)/64;
 *        当 CPU0CLKDIV=00H 时，CPU0CLK=SRICLK
 *
 *
 * @param Cpu0ClkDiv CPU0 分频器重载值
 * @return
 */
KF_INLINE void Clk_LL_SetCpu0ClkDivision(const uint32_t Cpu0ClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_CUP0CLK_DIVISION(Cpu0ClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CDU_CTL3_ADDR );
    regValue &= ~HWIO_CDU_CTL3_CDU_CTL3_CPU0CLKDIV_MASK;
    regValue |=  Cpu0ClkDiv<<HWIO_CDU_CTL3_CDU_CTL3_CPU0CLKDIV_SHFT;
    REG_WRITE(HWIO_CDU_CTL3_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL3.bits.CPU0CLKDIV, Cpu0ClkDiv);
#endif
}

/*  CDU_CTL4 */

/**
 * @brief 设置 CPU1 分频器重载值
 * @details 生成的 CUP1 频率（性能）被配置成CPU1CLK=SYSCLK*(64-CPU1CLKDIV)/64;
 *        当 CPU1CLKDIV=00H 时，CPU1CLK=SRICLK
 *
 *
 * @param Cpu1ClkDiv CPU1 分频器重载值
 * @return
 */
KF_INLINE void Clk_LL_SetCpu1ClkDivision(const uint32_t Cpu1ClkDiv)
{
    KF_CLK_ASSERT(CHECK_CDU_CUP1CLK_DIVISION(Cpu1ClkDiv));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CDU_CTL4_ADDR );
    regValue &= ~HWIO_CDU_CTL4_CDU_CTL4_CPU1CLKDIV_MASK;
    regValue |=  Cpu1ClkDiv<<HWIO_CDU_CTL4_CDU_CTL4_CPU1CLKDIV_SHFT;
    REG_WRITE(HWIO_CDU_CTL4_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CDU_CTL4.bits.CPU1CLKDIV, Cpu1ClkDiv);
#endif
}

/*  CDU_CTL5 */

/**
 * @brief 整数分频器模式选择
 *
 * @param Index 时钟索引
 *        CLK_CDU_INTFREQDIVMODE_PERICLK: PERICLKMOD
 *        CLK_CDU_INTFREQDIVMODE_SYSCLK: SYSCLKMOD
 *        CLK_CDU_INTFREQDIVMODE_TMRCLK: TMRCLKMOD
 *        CLK_CDU_INTFREQDIVMODE_STCLK: STCLKMOD
 *        CLK_CDU_INTFREQDIVMODE_CANHCLK: CANHCLKMOD
 *        CLK_CDU_INTFREQDIVMODE_REFCLK1CLK: REFCLK1CLKMOD
 *        CLK_CDU_INTFREQDIVMODE_REFCLK2CLK: REFCLK2CLKMOD
 *        CLK_CDU_INTFREQDIVMODE_MSCCLK: MSCCLKMOD
 *        CLK_CDU_INTFREQDIVMODE_RTCCLK: RTCCLKMOD
 *        CLK_CDU_INTFREQDIVMODE_SPICLK: SPICLKMOD
 *        CLK_CDU_INTFREQDIVMODE_ADCCLK: ADCCLKMOD
 *        CLK_CDU_INTFREQDIVMODE_I2CCLK: I2CCLKMOD
 *        CLK_CDU_INTFREQDIVMODE_CANCLK: CANCLKMOD
 *        CLK_CDU_INTFREQDIVMODE_UTLINFCLK: UTLINFCLKMOD
 *        CLK_CDU_INTFREQDIVMODE_UTLINSCLK: UTLINSCLKMOD
 *
 * @param Mode
 *        CLK_CDU_INTFREQDIV_PULSEMODE: pluse mode
 *        CLK_CDU_INTFREQDIV_BALANCEMODE: balance mode
 * @return
 */
KF_INLINE void
Clk_LL_SetIntegerFreqDividerMode(const Clk_IntFreqDividerIndex_t Index, const Clk_IntFreqDividerMode_t Mode)
{
    KF_CLK_ASSERT(CHECK_CDU_INTFREQDIVIDER_INDEX(Index));
    KF_CLK_ASSERT(CHECK_CDU_INTFREQDIVIDER_MODE(Mode));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_CDU_CTL5_ADDR ,  (1 << (uint32_t)Index) ,  (Mode << (uint32_t)Index));
//TODO: check if correct

#else
    REG_BITS_WRITE(CLK_PTR->CDU_CTL5.reg, (1 << (uint32_t)Index), (Mode << (uint32_t)Index));
#endif
}

/*  CLKM_CTL0 */

/**
 * @brief 监视器使能控制
 *
 *
 * @param Index 时钟索引
 *  CLK_CLKM_MONITOR_INDEX_PLL0: PLL0
 *  CLK_CLKM_MONITOR_INDEX_PLL1: PLL1
 *  CLK_CLKM_MONITOR_INDEX_PLL2: PLL2
 *  CLK_CLKM_MONITOR_INDEX_PERI: PERI
 *  CLK_CLKM_MONITOR_INDEX_INTHF100: INTHF100
 *  CLK_CLKM_MONITOR_INDEX_INTHF32: INTHF32
 *
 * @param Status
 *        bool false: 监视器禁用; true: 监视器使能
 * @return
 */
KF_INLINE void Clk_LL_SetCLKMonitorEnabled(const Clk_SckMonitorEnabledIndex_t Index, const bool Status)
{
    KF_CLK_ASSERT(CHECK_CLKM_MONITOR_INDEX(Index));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_OSC_CTL0_ADDR ,  (1 << (uint32_t)Index) ,  ((uint32_t)Status << (uint32_t)Index));
//TODO: check if correct

#else
    REG_BITS_WRITE(CLK_PTR->CLKM_CTL0.reg, (1 << (uint32_t)Index), ((uint32_t)Status << (uint32_t)Index));
#endif
}

/**
 * @brief 设置时钟监视器测试
 * @details ，测试位不是直接触发警报，而是抑制时钟进行监控，这也是为了测试监视逻辑本身
 *
 * @param Index 时钟索引
 *        CLK_CLKM_MONITOR_INDEX_PLL0: PLL0
 *        CLK_CLKM_MONITOR_INDEX_PLL1: PLL1
 *        CLK_CLKM_MONITOR_INDEX_PLL2: PLL2
 *        CLK_CLKM_MONITOR_INDEX_PERI: PERI
 *        CLK_CLKM_MONITOR_INDEX_INTHF100: INTHF100
 *        CLK_CLKM_MONITOR_INDEX_INTHF32: INTHF32
 * @param Status
 *        bool false: 正常工作; true: 在监视器输入端抑制时钟
 * @return
 */
KF_INLINE void Clk_LL_SetCLKMonitorTestEnabled(const Clk_SckMonitorEnabledIndex_t Index, const bool Status)
{
    KF_CLK_ASSERT(CHECK_CLKM_MONITOR_INDEX(Index));
#ifdef SIMULATION
    REG_BITS_WRITE(HWIO_OSC_CTL0_ADDR ,  (1 << ((uint32_t)Index + 8)) ,  ((uint32_t)Status << ((uint32_t)Index + 8)));
//TODO: check if correct

#else
    REG_BITS_WRITE(CLK_PTR->CLKM_CTL0.reg, (1 << ((uint32_t)Index + 8)), ((uint32_t)Status << ((uint32_t)Index + 8)));
#endif
}

/*  CLKM_CTL1 */
/* 该寄存器内INTHF100功能描述与CLKM_CTL0和CLKM_TEST0重复*/

/* CLKM_TEST0 */

/**
 * @brief 设置测试时钟监视器上限阈值
 *
 *
 * @param UpThreshold
 * @return
 */
KF_INLINE void Clk_LL_SetCLKMTestUpThreshold(const uint32_t UpThreshold)
{
    KF_CLK_ASSERT(CHECK_CLKM_UP_THRESHOLD(UpThreshold));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKM_TEST0_ADDR );
    regValue &= ~HWIO_CLKM_TEST0_CLKM_TEST0_UPTHR_MASK;
    regValue |=  UpThreshold<<HWIO_CLKM_TEST0_CLKM_TEST0_UPTHR_SHFT;
    REG_WRITE(HWIO_CLKM_TEST0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CLKM_TEST0.bits.UPTHR, UpThreshold);
#endif
}

/**
 * @brief 设置测试时钟监视器下限阈值
 *
 *
 * @param UpThreshold
 * @return
 */
KF_INLINE void Clk_LL_SetCLKMTestLowThreshold(const uint32_t LowThreshold)
{
    KF_CLK_ASSERT(CHECK_CLKM_LOW_THRESHOLD(LowThreshold));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKM_TEST0_ADDR );
    regValue &= ~HWIO_CLKM_TEST0_CLKM_TEST0_LOTHR_MASK;
    regValue |=  LowThreshold<<HWIO_CLKM_TEST0_CLKM_TEST0_LOTHR_SHFT;
    REG_WRITE(HWIO_CLKM_TEST0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CLKM_TEST0.bits.LOTHR, LowThreshold);
#endif
}

/**
 * @brief 测试时钟监视器使能
 *
 *
 * @param Status
 *        false: 监视器不使能
 *        true: 监视器使能
 * @return
 */
KF_INLINE void Clk_LL_SetCLKMTestMonitorEnabled(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKM_TEST0_ADDR );
    regValue &= ~HWIO_CLKM_TEST0_CLKM_TEST0_MONEN_MASK;
    regValue |=  Status<<HWIO_CLKM_TEST0_CLKM_TEST0_MONEN_SHFT;
    REG_WRITE(HWIO_CLKM_TEST0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CLKM_TEST0.bits.MONEN, Status);
#endif
}

/**
 * @brief 测试时钟监视器测试
 * @attention 使能MONTST直接触发警报
 *
 * @param Status
 *        false: 正常工作
 *        true: 测试警报生成
 * @return
 */
KF_INLINE void Clk_LL_SetCLKMTestMonitorDirectEnabled(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKM_TEST0_ADDR );
    regValue &= ~HWIO_CLKM_TEST0_CLKM_TEST0_MONTST_MASK;
    regValue |=  Status<<HWIO_CLKM_TEST0_CLKM_TEST0_MONTST_SHFT;
    REG_WRITE(HWIO_CLKM_TEST0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CLKM_TEST0.bits.MONTST, Status);
#endif
}

/**
 * @brief REFCLK 时钟选择
 *
 *
 * @param RefclkSource
 * @return
 */
KF_INLINE void Clk_LL_SelectCLKMREFCLK(const Clk_SckMonitorRefclkIndex_t RefclkSource)
{
    KF_CLK_ASSERT(CHECK_CLKM_REFCLK_INDEX(RefclkSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKM_TEST0_ADDR );
    regValue &= ~HWIO_CLKM_TEST0_CLKM_TEST0_REFCLKSEL_MASK;
    regValue |=  RefclkSource<<HWIO_CLKM_TEST0_CLKM_TEST0_REFCLKSEL_SHFT;
    REG_WRITE(HWIO_CLKM_TEST0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CLKM_TEST0.bits.REFCLKSEL, RefclkSource);
#endif
}

/* CLKM_TEST1 */

/**
 * @brief 是 MONCLK 时钟门控使能
 * @attention MONCLK 切换之前，需要先关闭时钟门控，切换完成之后再打开
 *
 *
 * @param Status
 * @return
 */
KF_INLINE void Clk_LL_SetCLKMMonitorEnabled(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKM_TEST1_ADDR );
    regValue &= ~HWIO_CLKM_TEST1_CLKM_TEST1_MONCLKEN_MASK;
    regValue |=  Status<<HWIO_CLKM_TEST1_CLKM_TEST1_MONCLKEN_SHFT;
    REG_WRITE(HWIO_CLKM_TEST1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CLKM_TEST1.bits.MONCLKEN, Status);
#endif
}

/**
 * @brief 选择用于测试的时钟
 *
 *
 * @param ClockSource
 *        CLK_CLKM_MONITOR_CLK_INTHF100: INTHF100 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_INTHF32: INTHF32 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_EXTHF: EXTHF 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_SYSPLL0: SYSPLL0 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_PERPLL1: PERPLL1 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_PERPLL2: PERPLL2 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_ADPLL: ADPLL 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_PERI: PERI 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_CPU0: CPU0 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_CPU1: CPU1 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_SYS: SYS 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_ST: ST 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_PERI2: PERI2 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_CANH: CANH 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_SPI: SPI 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_ADC: ADC 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_I2C: I2C 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_CAN: CAN 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_UTLINF: UTLINF 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_UTLINS: UTLINS 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_MSC: MSC 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_EXTLF: EXTLF 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_INTLF: INTLF 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_REFCLK1: REFCLK1 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_REFCLK2: REFCLK2 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_TMR: TMR 被用作 MONCLK 时钟
 *        CLK_CLKM_MONITOR_CLK_RTC: RTC 被用作 MONCLK 时钟
 * @return
 */
KF_INLINE void Clk_LL_SelectCLKMMonitorClock(const Clk_MonitorClockSourceIndex_t ClockSource)
{
    KF_CLK_ASSERT(CHECK_CLKM_MONCLK_INDEX(ClockSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_CLKM_TEST1_ADDR );
    regValue &= ~HWIO_CLKM_TEST1_CLKM_TEST1_MONCLKSEL_MASK;
    regValue |=  ClockSource<<HWIO_CLKM_TEST1_CLKM_TEST1_MONCLKSEL_SHFT;
    REG_WRITE(HWIO_CLKM_TEST1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->CLKM_TEST1.bits.MONCLKSEL, ClockSource);
#endif
}

/* EXTCLK_CTL0 */

/**
 * @brief 外部时钟输出 EXTCLK0 使能
 *
 *
 * @param Status
 *        false: 外部时钟信号 EXTCLK0 禁止输出
 *        true: 外部时钟信号 EXTCLK0 使能输出
 * @return
 */
KF_INLINE void Clk_LL_SetExternalClock0Enabled(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_EXTCLK_CTL0_EXTCLK_CTL0_EN0_MASK;
    regValue |=  Status<<HWIO_EXTCLK_CTL0_EXTCLK_CTL0_EN0_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLK_CTL0.bits.EN0, Status);
#endif
}

/**
 * @brief 外部时钟输出 EXTCLK0 反相选择
 *
 *
 * @param Status
 *        false: 外部时钟信号 EXTCLK0 反相
 *        true: 外部时钟信号 EXTCLK0 不反相
 * @return
 */
KF_INLINE void Clk_LL_SetExternalClock0InvertDisable(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_EXTCLK_CTL0_EXTCLK_CTL0_NSEL0_MASK;
    regValue |=  Status<<HWIO_EXTCLK_CTL0_EXTCLK_CTL0_NSEL0_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLK_CTL0.bits.NSEL0, Status);
#endif
}

/**
 * @brief
 *
 *
 * @param ClockSource
 *   CLK_EXTCLK0_OUTCLK0: OUTCLK0 被选作外部时钟信号
 *   CLK_EXTCLK0_SYSPLL0: SYSPLL0 被选作外部时钟信号
 *   CLK_EXTCLK0_PERPLL1: PERPLL1 被选作外部时钟信号
 *   CLK_EXTCLK0_EXTHF: EXTHF 被选作外部时钟信号
 *   CLK_EXTCLK0_INTHF100: INTHF100 被选作外部时钟信号
 *   CLK_EXTCLK0_PERPLL2: PERPLL2 被选作外部时钟信号
 *   CLK_EXTCLK0_CPU0CLK: CPU0CLK 被选作外部时钟信号
 *   CLK_EXTCLK0_SYSCLK: SYSCLK 被选作外部时钟信号
 *   CLK_EXTCLK0_PERICLK: PERICLK 被选作外部时钟信号
 *   CLK_EXTCLK0_STCLK: STCLK 被选作外部时钟信号
 * @return
 */
KF_INLINE void Clk_LL_SelectExternalClock0Source(const Clk_ExternalClock0Index_t ClockSource)
{
    KF_CLK_ASSERT(CHECK_EXTCLK0_CLK_INDEX(ClockSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_EXTCLK_CTL0_EXTCLK_CTL0_NSEL0_MASK;
    regValue |=  ClockSource<<HWIO_EXTCLK_CTL0_EXTCLK_CTL0_NSEL0_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLK_CTL0.bits.SEL0, ClockSource);
#endif
}

/**
 * @brief 外部时钟输出 EXTCLK1 使能
 *
 *
 * @param Status
 *        false: 外部时钟信号 EXTCLK1 禁止输出
 *        true: 外部时钟信号 EXTCLK1 使能输出
 * @return
 */
KF_INLINE void Clk_LL_SetExternalClock1Enabled(const bool Status)
{
    KF_CLK_ASSERT(CHECK_EXTCLK1_CLK_INDEX(ClockSource));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_EXTCLK_CTL0_EXTCLK_CTL0_EN1_MASK;
    regValue |=  Status<<HWIO_EXTCLK_CTL0_EXTCLK_CTL0_EN1_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLK_CTL0.bits.EN1, Status);
#endif
}

/**
 * @brief 外部时钟输出 EXTCLK1 反相选择
 *
 *
 * @param Status
 *        false: 外部时钟信号 EXTCLK1 反相
 *        true: 外部时钟信号 EXTCLK1 不反相
 * @return
 */
KF_INLINE void Clk_LL_SetExternalClock1InvertDisabled(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_EXTCLK_CTL0_EXTCLK_CTL0_NSEL1_MASK;
    regValue |=  Status<<HWIO_EXTCLK_CTL0_EXTCLK_CTL0_NSEL1_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLK_CTL0.bits.NSEL1, Status);
#endif
}

/**
 * @brief
 *
 *
 * @param ClockSource
 *   CLK_EXTCLK0_OUTCLK0: OUTCLK0 被选作外部时钟信号
 *   CLK_EXTCLK0_SYSPLL0: SYSPLL0 被选作外部时钟信号
 *   CLK_EXTCLK0_PERPLL1: PERPLL1 被选作外部时钟信号
 *   CLK_EXTCLK0_EXTHF: EXTHF 被选作外部时钟信号
 *   CLK_EXTCLK0_INTHF100: INTHF100 被选作外部时钟信号
 *   CLK_EXTCLK0_PERPLL2: PERPLL2 被选作外部时钟信号
 *   CLK_EXTCLK0_CPU0CLK: CPU0CLK 被选作外部时钟信号
 *   CLK_EXTCLK0_SYSCLK: SYSCLK 被选作外部时钟信号
 *   CLK_EXTCLK0_PERICLK: PERICLK 被选作外部时钟信号
 *   CLK_EXTCLK0_STCLK: STCLK 被选作外部时钟信号
 * @return
 */
KF_INLINE void Clk_LL_SelectExternalClock1Source(const Clk_ExternalClock1Index_t ClockSource)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_EXTCLK_CTL0_EXTCLK_CTL0_NSEL1_MASK;
    regValue |=  ClockSource<<HWIO_EXTCLK_CTL0_EXTCLK_CTL0_NSEL1_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLK_CTL0.bits.SEL1, ClockSource);
#endif
}

/**
 * @brief OUTCLK1 时钟的整数分频器设置
 * @details PERICLK 的整数分频器产生 OUTCLK1 时钟，DIV定义了整数分频器的分频值 。
 * OUTCLK1频率计算公式 ：OUTCLK1=PERIBCLK/(DIV+1)
 * EN1位每次清零，DIV也被清零。
 *
 * @param Division
 * @return
 */
KF_INLINE void Clk_LL_SetOUTCLK1Division(const uint32_t Division)
{
    KF_CLK_ASSERT(CHECK_OUTCLK_DIVISION(Division));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PLLDIV_MASK;
    regValue |=  Division<<HWIO_SYSPLL_CTL0_SYSPLL_CTL0_PLLDIV_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLK_CTL0.bits.DIV, Division);
#endif
}

/**
 * @brief EXTCLK0外部输出分频器设置
 * @details EXTCLK_CTL0.EN0 清零时，DIVSTEP0 也被清零，
 * 当 DIVSTEP0=00H，EXTCLK0=xxxCLK0。
 * EXTCLK0 输出频率公式：EXTCLK0=xxxCLK0/2^DIVSTEP0
 *
 *
 * @param Division
 * @return
 */
KF_INLINE void Clk_LL_SetEXTCLK0Division(const uint32_t Division)
{
    KF_CLK_ASSERT(CHECK_EXTCLK0_DIVISION(Division));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_EXTCLK_CTL1_EXTCLK_CTL1_DIVSTEP0_MASK;
    regValue |=  Division<<HWIO_EXTCLK_CTL1_EXTCLK_CTL1_DIVSTEP0_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLK_CTL1.bits.DIVSTEP0, Division);
#endif
}

/**
 * @brief EXTCLK1外部输出分频器设置
 * @details EXTCLK_CTL0.EN1 清零时，DIVSTEP1 也被清零，
 * 当 DIVSTEP1=00H，EXTCLK0=xxxCLK1。
 * EXTCLK1 输出频率公式：EXTCLK1=xxxCLK1/2^DIVSTEP1
 *
 *
 * @param Division
 * @return
 */
KF_INLINE void Clk_LL_SetEXTCLK1Division(const uint32_t Division)
{
    KF_CLK_ASSERT(CHECK_EXTCLK1_DIVISION(Division));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL1_ADDR );
    regValue &= ~HWIO_EXTCLK_CTL1_EXTCLK_CTL1_DIVSTEP1_MASK;
    regValue |=  Division<<HWIO_EXTCLK_CTL1_EXTCLK_CTL1_DIVSTEP1_SHFT;
    REG_WRITE(HWIO_OSC_CTL1_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLK_CTL1.bits.DIVSTEP1, Division);
#endif
}

/* EXTCLKFD_CTL */

/**
 * @brief 禁用 OUTCLK0 时钟
 *
 * @param Status
 *        false: 根据 DMOD 位的模式设置，使能 OUTCLK0 的时钟产生
 *        true: 分数分频器被停止，禁止生成 OUTCLK0 信号
 * @return
 */
KF_INLINE void Clk_LL_SetOUTCLK0Disabled(const bool Status)
{
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_EXTCLKFD_CTL_EXTCLKFD_CTL_CLKDIS_MASK;
    regValue |=  Status<<HWIO_EXTCLKFD_CTL_EXTCLKFD_CTL_CLKDIS_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLKFD_CTL.bits.CLKDIS, Status);
#endif
}

/**
 * @brief 返回EXTCLK0分频器重载值
 *
 * @return
 */
KF_INLINE uint32_t Clk_LL_GetEXTCLK0DividerReloadValue()
{
    return (CLK_PTR->EXTCLKFD_CTL.bits.RESVAL);
}

/**
 * @brief OUTCLK0 时钟信号的分频模式设置
 *
 *
 * @param Mode
 *        CLK_OUTCLK0_DIVIDER_RST: 分数分频器被关闭，不生成 OUTCLK0 信号，复位外部分频信号为 1，RESVAL 的值不更新
 *        CLK_OUTCLK0_DIVIDER_NORMAL:  正常分频模式被选用
 *        CLK_OUTCLK0_DIVIDER_FRACTIONAL: 分数分频模式被选用
 *        CLK_OUTCLK0_DIVIDER_OFF: 分数分频器被关闭，不生成 OUTCLK0 信号，RESVAL的值不更新
 * @return
 */
KF_INLINE void Clk_LL_SetOUTCLK0DividerMode(const Clk_OUTCLK0DivMode_t Mode)
{
    KF_CLK_ASSERT(CHECK_EOUTCLK0_DIVIDERMODE(Mode));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_EXTCLKFD_CTL_EXTCLKFD_CTL_DMOD_MASK;
    regValue |=  Mode<<HWIO_EXTCLKFD_CTL_EXTCLKFD_CTL_DMOD_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLKFD_CTL.bits.DMOD, Mode);
#endif
}

/**
 * @brief OUTCLK0分数分频模式重载值设置
 * @details 在分数分频模式中, STEPVAL 容纳RESVAL 重载值。STEPVAL决定了每个时钟周期被加入 RESVAL 的10 比特值
 *
 * @param StepValue
 * @return
 */
KF_INLINE void Clk_LL_SetOUTCLK0StepValue(const uint32_t StepValue)
{
    KF_CLK_ASSERT(CHECK_EOUTCLK0_STEPVALUE(StepValue));
#ifdef SIMULATION
    uint32_t regValue=REG_READ(HWIO_OSC_CTL0_ADDR );
    regValue &= ~HWIO_EXTCLKFD_CTL_EXTCLKFD_CTL_STEPVAL_MASK;
    regValue |=  StepValue<<HWIO_EXTCLKFD_CTL_EXTCLKFD_CTL_STEPVAL_SHFT;
    REG_WRITE(HWIO_OSC_CTL0_ADDR , regValue);
//TODO: check if correct

#else
    REG_WRITE(CLK_PTR->EXTCLKFD_CTL.bits.STEPVAL, StepValue);
#endif
}

/*TODO: 缺少ADPLL寄存器配置*/
/*TODO: 缺少PLL稳定中断*/
#ifdef __cplusplus
}
#endif
#endif
/* EOF */
