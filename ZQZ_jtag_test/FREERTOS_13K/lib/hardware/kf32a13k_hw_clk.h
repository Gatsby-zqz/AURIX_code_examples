/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_hw_clk.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2024-01-15
 *  @Version         : V0.0.1.240115_alpha
 *  @Description     : This document describes the C language document template
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2024-01-15    |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/
#ifndef KF32DA13K_HW_CLK_H_
#define KF32DA13K_HW_CLK_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_reg_clock.h"
#include "kf32a13k_clk_cfg.h"
/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef enum
{
    CLK_HW_CDU_COMMON_DIVISION_OFF,
    CLK_HW_CDU_COMMON_DIVISION_1,
    CLK_HW_CDU_COMMON_DIVISION_2,
    CLK_HW_CDU_COMMON_DIVISION_3,
    CLK_HW_CDU_COMMON_DIVISION_4,
    CLK_HW_CDU_COMMON_DIVISION_5,
    CLK_HW_CDU_COMMON_DIVISION_6,
    CLK_HW_CDU_COMMON_DIVISION_7,
    CLK_HW_CDU_COMMON_DIVISION_8,
    CLK_HW_CDU_COMMON_DIVISION_9,
    CLK_HW_CDU_COMMON_DIVISION_10,
    CLK_HW_CDU_COMMON_DIVISION_11,
    CLK_HW_CDU_COMMON_DIVISION_12,
    CLK_HW_CDU_COMMON_DIVISION_13,
    CLK_HW_CDU_COMMON_DIVISION_14,
    CLK_HW_CDU_COMMON_DIVISION_15,
} Clk_Hw_CDU_CommonDivisionType;

typedef enum
{
    CLK_HW_AMP_MODE_DEFAULT,
    CLK_HW_AMP_MODE_1,
    CLK_HW_AMP_MODE_2,
    CLK_HW_AMP_MODE_3,
} Clk_Hw_OscAmpModType;

typedef enum
{
    CLK_HW_HYSTERESIS_MODE_DEFAULT,
    CLK_HW_HYSTERESIS_MODE_1,
    CLK_HW_HYSTERESIS_MODE_2,
    CLK_HW_HYSTERESIS_MODE_3,
} Clk_Hw_OscHysteresisModType;

typedef enum
{
    CLK_HW_MODE_EXTCLK_LOWPOWEROFF,
    CLK_HW_MODE_CLKOFF_LOWPOWEROFF,
    CLK_HW_MODE_XHT_LOWPOWERON,
    CLK_HW_MODE_CLKOFF_LOWPOWERON,
} Clk_Hw_OscModType;

typedef enum
{
    CLK_HW_GAIN_MOD_1,
    CLK_HW_GAIN_MOD_2,
    CLK_HW_GAIN_MOD_3,
    CLK_HW_GAIN_MOD_MAX,
} Clk_Hw_OscGainModType;

typedef enum
{
    CLK_HW_XTH_COMPARATOR_CURRENT_12DOT5,
    CLK_HW_XTH_COMPARATOR_CURRENT_25,
    CLK_HW_XTH_COMPARATOR_CURRENT_37DOT5,
    CLK_HW_XTH_COMPARATOR_CURRENT_50,
} Clk_Hw_XTHCurrentType;

typedef enum
{
    CLK_HW_GM_BOOST_MODE_4,
    CLK_HW_GM_BOOST_MODE_2_4,
    CLK_HW_GM_BOOST_MODE_4_4,
    CLK_HW_GM_BOOST_MODE_6_4,
    CLK_HW_GM_BOOST_MODE_8_4,
    CLK_HW_GM_BOOST_MODE_10_4,
    CLK_HW_GM_BOOST_MODE_12_4,
    CLK_HW_GM_BOOST_MODE_14_4,
    CLK_HW_GM_BOOST_MODE_16_4,
    CLK_HW_GM_BOOST_MODE_18_4,
    CLK_HW_GM_BOOST_MODE_20_4,
    CLK_HW_GM_BOOST_MODE_22_4,
    CLK_HW_GM_BOOST_MODE_24_4,
    CLK_HW_GM_BOOST_MODE_26_4,
    CLK_HW_GM_BOOST_MODE_28_4,
    CLK_HW_GM_BOOST_MODE_30_4,
} Clk_Hw_GmModeType;

typedef enum
{
    CLK_HW_HSE_MODE_DEFAULT,
    CLK_HW_HSE_MODE_REVERSER,
} Clk_Hw_HseModeType;

typedef struct
{
    bool                        AmpRegulatorEnable;
    Clk_Hw_OscAmpModType        AmpMode;
    bool                        HysteresisEnable;
    Clk_Hw_OscHysteresisModType HysMode;
    bool                        ShaperBypassStatus;
    Clk_Hw_OscModType           OscMode;
    Clk_Hw_OscGainModType       GainMode;
    bool                        Capacitor0Enable;
    bool                        Capacitor1Enable;
    bool                        Capacitor2Enable;
    bool                        Capacitor3Enable;
    Clk_Hw_XTHCurrentType       Current;
    bool                        ComparatorShaperEnable;
    bool                        Parallel200OhmEnable;
    bool                        Parallel470KEnable;
    bool                        Parallel2MEnable;
    Clk_Hw_GmModeType           GmMode;
    Clk_Hw_HseModeType          HSEMode;
    bool                        ExternXTALEnable;
} Clk_XtalConfig_t;

typedef struct
{
    bool     FreqModulateEnable;
    uint32_t FreqModulateIntPart;
    uint32_t FreqModulateDecPart;
} Clk_ModulateConfig_t;

/**
 * @brief 系统PLL配置
 * @details 公式:
 * PLL0 = (M* fREF) / (N * K2)
 */
typedef struct
{
    uint32_t PLLdivide_N;
    uint32_t PLLmultiple_M;
    uint32_t PLLdivide_K2;
    bool     InputFreq2Divide;
} Clk_Hw_SysPLLConfigType;

/**
 * @brief 外设PLL配置
 * @details 公式:
 * PLL1= (M* fREF) / (N * K2)
 * PLL2 = (M* fREF) / (N * K3 * 1.6) 当 PERPLL_CTL0.DIVBYEN = 0
 * PLL2 = (M* fREF) / (N * K3 * 2) 当 PERPLL_CTL0.DIVBYEN = 1
 */
typedef struct
{
    uint32_t PLLdivide_N;
    uint32_t PLLmultiple_M;
    uint32_t PLLdivide_K2;
    uint32_t PLLdivide_K3;
    bool     InputFreq2Divide;
    bool     K3DivBypass;
} Clk_Hw_PeriPLLConfigType;

typedef enum
{
    CLK_HW_PLL_SOURCE_INTHF,
    CLK_HW_PLL_SOURCE_EXTHF,
    CLK_HW_PLL_SOURCE_EXTCK,
    CLK_HW_PLL_SOURCE_INTHF32,
} Clk_Hw_PLLClockSourceType;

typedef struct
{
    /* 晶振频率，晶振看门狗使用 */
    uint32_t                  XtalFrequency;
    Clk_Hw_PLLClockSourceType PLLInputSource;
    Clk_Hw_SysPLLConfigType   SysPLLConfigPtr;
    Clk_Hw_PeriPLLConfigType  PeriPLLConfigPtr;
} Clk_PLLConfig_t;

typedef enum
{
    CLK_HW_DOMAIN_SOURCE0_INTHF100,
    CLK_HW_DOMAIN_SOURCE0_SYSPLL,
    CLK_HW_DOMAIN_SOURCE0_INTHF32,
    CLK_HW_DOMAIN_SOURCE0_EXTHF,
    CLK_HW_DOMAIN_SOURCE0_ADPLL,
    CLK_HW_DOMAIN_SOURCE0_PERPLL1,
    CLK_HW_DOMAIN_SOURCE0_PERPLL2,
    CLK_HW_DOMAIN_SOURCE0_DEFAULT,
} Clk_Hw_DomainClockSource0Type;

typedef enum
{
    CLK_HW_DOMAIN_SOURCE1_INTHF100,
    CLK_HW_DOMAIN_SOURCE1_PERPLL1,
    CLK_HW_DOMAIN_SOURCE1_INTHF32,
    CLK_HW_DOMAIN_SOURCE1_EXTHF,
    CLK_HW_DOMAIN_SOURCE1_ADPLL,
    CLK_HW_DOMAIN_SOURCE1_SYSPLL,
    CLK_HW_DOMAIN_SOURCE1_PERPLL2,
    CLK_HW_DOMAIN_SOURCE1_DEFAULT,
} Clk_Hw_DomainClockSource1Type;

typedef enum
{
    CLK_HW_DOMAIN_SOURCE2_INTHF100,
    CLK_HW_DOMAIN_SOURCE2_PERPLL2,
    CLK_HW_DOMAIN_SOURCE2_INTHF32,
    CLK_HW_DOMAIN_SOURCE2_EXTHF,
    CLK_HW_DOMAIN_SOURCE2_ADPLL,
    CLK_HW_DOMAIN_SOURCE2_SYSPLL,
    CLK_HW_DOMAIN_SOURCE2_PERPLL1,
    CLK_HW_DOMAIN_SOURCE2_DEFAULT,
} Clk_Hw_DomainClockSource2Type;

typedef struct
{
    Clk_Hw_DomainClockSource0Type Source0ClockSource;
    Clk_Hw_DomainClockSource1Type Source1ClockSource;
    Clk_Hw_DomainClockSource2Type Source2ClockSource;
    bool                          Source1Freq2Divide;
} Clk_DomainClockConfig_t;

typedef enum
{
    CLK_HW_CDU_REFCLK2_SOURCE_FSOURCE1,
    CLK_HW_CDU_REFCLK2_SOURCE_FSOURCE2,
} Clk_Hw_CDU_RefClk2SourceType;

typedef enum
{
    CLK_HW_CDU_MSC_SOURCE_FSOURCE1,
    CLK_HW_CDU_MSC_SOURCE_FSOURCE2,
} Clk_Hw_CDU_MscClkSourceType;

typedef enum
{
    CLK_HW_CDU_RTC_SOURCE_INTHF,
    CLK_HW_CDU_RTC_SOURCE_EXTHF,
} Clk_Hw_CDU_RtcClkSourceType;

typedef enum
{
    CLK_HW_CDU_SPI_SOURCE_FSOURCE1,
    CLK_HW_CDU_SPI_SOURCE_FSOURCE2,
} Clk_Hw_CDU_SpiClkSourceType;

typedef enum
{
    CLK_HW_CDU_ADC_SOURCE_FSOURCE1,
    CLK_HW_CDU_ADC_SOURCE_FSOURCE2,
} Clk_Hw_CDU_AdcClkSourceType;

typedef enum
{
    CLK_HW_CDU_I2C_SOURCE_FSOURCE1,
    CLK_HW_CDU_I2C_SOURCE_FSOURCE2,
} Clk_Hw_CDU_I2CClkSourceType;

typedef enum
{
    CLK_HW_CDU_CAN_SOURCE_FSOURCE1,
    CLK_HW_CDU_CAN_SOURCE_FSOURCE2,
} Clk_Hw_CDU_CANClkSourceType;

typedef enum
{
    CLK_HW_CDU_UTLINF_SOURCE_FSOURCE1,
    CLK_HW_CDU_UTLINF_SOURCE_FSOURCE2,
} Clk_Hw_CDU_UTLINFClkSourceType;

typedef enum
{
    CLK_HW_CDU_UTLINS_SOURCE_FSOURCE1,
    CLK_HW_CDU_UTLINS_SOURCE_FSOURCE2,
} Clk_Hw_CDU_UTLINSClkSourceType;

typedef enum
{
    CLK_HW_CDU_REFCLK_DIVISION_OFF,
    CLK_HW_CDU_REFCLK_DIVISION_1,
    CLK_HW_CDU_REFCLK_DIVISION_2,
    CLK_HW_CDU_REFCLK_DIVISION_3,
    CLK_HW_CDU_REFCLK_DIVISION_4,
    CLK_HW_CDU_REFCLK_DIVISION_5,
    CLK_HW_CDU_REFCLK_DIVISION_6,
    CLK_HW_CDU_REFCLK_DIVISION_7,
    CLK_HW_CDU_REFCLK_DIVISION_8,
    CLK_HW_CDU_REFCLK_DIVISION_9,
    CLK_HW_CDU_REFCLK_DIVISION_10,
    CLK_HW_CDU_REFCLK_DIVISION_11,
    CLK_HW_CDU_REFCLK_DIVISION_12,
    CLK_HW_CDU_REFCLK_DIVISION_13,
    CLK_HW_CDU_REFCLK_DIVISION_14,
    CLK_HW_CDU_REFCLK_DIVISION_15,
    CLK_HW_CDU_REFCLK_DIVISION_16,
    CLK_HW_CDU_REFCLK_DIVISION_17,
    CLK_HW_CDU_REFCLK_DIVISION_18,
    CLK_HW_CDU_REFCLK_DIVISION_19,
    CLK_HW_CDU_REFCLK_DIVISION_20,
    CLK_HW_CDU_REFCLK_DIVISION_21,
    CLK_HW_CDU_REFCLK_DIVISION_22,
    CLK_HW_CDU_REFCLK_DIVISION_23,
    CLK_HW_CDU_REFCLK_DIVISION_24,
    CLK_HW_CDU_REFCLK_DIVISION_25,
    CLK_HW_CDU_REFCLK_DIVISION_26,
    CLK_HW_CDU_REFCLK_DIVISION_27,
    CLK_HW_CDU_REFCLK_DIVISION_28,
    CLK_HW_CDU_REFCLK_DIVISION_29,
    CLK_HW_CDU_REFCLK_DIVISION_30,
    CLK_HW_CDU_REFCLK_DIVISION_31,
} Clk_Hw_CDU_RefClkDivisionType;

typedef struct
{
    Clk_Hw_CDU_RtcClkSourceType   RTCClkSource;
    Clk_Hw_CDU_CommonDivisionType RTCClkDivision;
} Clk_RtcClockDistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_MscClkSourceType   MSCClkSource;
    Clk_Hw_CDU_CommonDivisionType MscClkDivision;
} Clk_MscClockDistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_RefClk2SourceType  RefClk2Source;
    Clk_Hw_CDU_RefClkDivisionType RefClk2Division;
} Clk_RefClk2DistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_RefClkDivisionType RefClk1Division;
} Clk_RefClk1DistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_CommonDivisionType CANHClkDivision;
} Clk_CANHClkDistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_CommonDivisionType SysticktClkDivision;
} Clk_SystickClkDistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_UTLINSClkSourceType UTLINSClkSource;
    Clk_Hw_CDU_CommonDivisionType  UTLINSClkDivision;
} Clk_UTLINClkDistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_UTLINFClkSourceType UTLINFClkSource;
    Clk_Hw_CDU_CommonDivisionType  UTLINFClkDivision;
} Clk_UTLINFClkDistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_CANClkSourceType   CANClkSource;
    Clk_Hw_CDU_CommonDivisionType CANClkDivision;
} Clk_CanClkDistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_I2CClkSourceType   I2CClkSource;
    Clk_Hw_CDU_CommonDivisionType I2CClkDivision;
} Clk_I2CClkDistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_AdcClkSourceType   AdcClkSource;
    Clk_Hw_CDU_CommonDivisionType AdcClkDivision;
} Clk_AdcClkDistributeConfig_t;

typedef struct
{
    Clk_Hw_CDU_SpiClkSourceType   SpiClkSource;
    Clk_Hw_CDU_CommonDivisionType SpiClkDivision;
} Clk_SpiClkDistributeConfig_t;

typedef enum
{
    CLK_HW_CDU_LPCLK_DIVISION_DEFAULT,
    CLK_HW_CDU_LPCLK_DIVISION_30,
    CLK_HW_CDU_LPCLK_DIVISION_60,
    CLK_HW_CDU_LPCLK_DIVISION_120,
    CLK_HW_CDU_LPCLK_DIVISION_240,
} Clk_Hw_CDU_LPClkDivisionType;

/* 时钟分配*/
typedef struct
{
    Clk_Hw_CDU_LPClkDivisionType     LPClkDivision;
    Clk_Hw_CDU_CommonDivisionType    TmrClkDivision;
    Clk_Hw_CDU_CommonDivisionType    SysClkDivision;
    Clk_Hw_CDU_CommonDivisionType    PeriClkDivision;
    Clk_RtcClockDistributeConfig_t   RtcClkConfig;
    Clk_MscClockDistributeConfig_t   MscClkConfig;
    Clk_RefClk2DistributeConfig_t    RefClk2Config;
    Clk_RefClk1DistributeConfig_t    RefClk1Config;
    Clk_CANHClkDistributeConfig_t    CANHClkConfig;
    Clk_SystickClkDistributeConfig_t SystickClkConfig;
    Clk_UTLINClkDistributeConfig_t   UTLINClkConfig;
    Clk_UTLINFClkDistributeConfig_t  UTLINFClkConfig;
    Clk_CanClkDistributeConfig_t     CanClkConfig;
    Clk_I2CClkDistributeConfig_t     I2CClkConfig;
    Clk_AdcClkDistributeConfig_t     AdcClkConfig;
    Clk_SpiClkDistributeConfig_t     SpiClkConfig;
    uint32_t                         Cpu0ClkDivision;
    uint32_t                         Cpu1ClkDivision;
} Clk_ClockDistributeConfig_t;

typedef struct
{
    /* 系统PLL+外设PLL配置参数 */
    Clk_PLLConfig_t PLLParameters;
    /* 等待时间，竞品使用单位为s的浮点数，通过Systick实现；
    简单处理使用__asm__ volatile("NOP");*/
    uint32_t WaitTime;
} Clk_PLLInitialStepConfig_t;

typedef struct
{
    /* 当前步K2分频值*/
    uint32_t K2Step;
    /* 当前步等待时间 */
    uint32_t WaitTime;
} Clk_PLLStepConfig_t;

typedef struct
{
    /* 时钟节流期间，PLL分频次数 */
    uint32_t NumOfSteps;
    /* 指向PLL分频步骤数组首个元素的指针 */
    const Clk_PLLStepConfig_t *PLLStep;
} Clk_PLLThrottleConfig_t;

typedef struct
{
#ifndef CLK_DISABLE_PLL_CONFIG
    /* 第一步配置，与内部高频时钟频率一致，100MHz*/
    Clk_PLLInitialStepConfig_t PLLInitialStepConfig;
    /* 系统PLL节流配置，阶梯升高频率至目标 */
    Clk_PLLThrottleConfig_t SysPLLThrottleConfig;
    /* 调制配置 */
    /* 竞品通过用户配置增益Amplitude计算写入MODCFG位域的振幅，目前简单处理为用户直接传入振幅*/
    const Clk_ModulateConfig_t *ModulateConfigPtr;
#endif
    /* 时钟分配，竞品在PLLInitialStepConfig配置完成后立刻进行时钟分配，随后再配置SysPLLThrottleConfig */
    /* 竞品指定了各个模块的工作时钟频率，驱动程序根据不同的晶振频率和PLL频率配置选择不同参数，使模块时钟频率不随晶振频率和PLL频率改变
     */
    /* 13K的fsource0、fsource1、fsource2可选择PLL以外的时钟源，因此无法固定模块时钟频率；需要手动配置 */
    const Clk_ClockDistributeConfig_t *ClockDistributionPtr;
    const Clk_DomainClockConfig_t     *DomainClockConfigPtr;
    /* TODO: flashFconWaitStateConfig*/
} Clk_ClockConfig_t;

typedef struct
{
    Clk_Hw_OscGainModType       OscGainMode;
    Clk_Hw_OscModType           OscMode;
    bool                        OscShaperBypass;
    bool                        OscHysteresis;
    Clk_Hw_OscHysteresisModType OscHysMode;
    Clk_Hw_OscAmpModType        OscAmpMode;
    bool                        OscAmpRegulator;
    uint32_t                    WdgRefFreq;
    Clk_Hw_HseModeType          HseMode;
    bool                        XTHEn;
    Clk_Hw_GmModeType           GmMode;
    bool                        XTH2MOhmEn;
    bool                        XTH470kOhmEn;
    bool                        XTH200kOhmEn;
    bool                        XTHCmpShaper;
    Clk_Hw_XTHCurrentType       CmpCurrent;
    bool                        XTHCap0En;
    bool                        XTHCap1En;
    bool                        XTHCap2En;
    bool                        XTHCap3En;
} Clk_ExthfConfig_t;

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/
extern const Clk_ClockConfig_t Clk_DefaultClockConfig;
/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
void  Delay_us(uint32_t DelayTime);
bool  Clk_Hw_InitClock(const Clk_ClockConfig_t *ClockConfigPtr);
bool  Clk_Hw_InitClockByDefaultConfig(void);
bool  Clk_ConfigDomainClockSource(const Clk_DomainClockConfig_t *DomainClockConfigPtr);
void  Clk_ModulationInit(const Clk_ModulateConfig_t *ModulateConfigPtr);
bool  Clk_ConfigPLLInitialStep(const Clk_PLLInitialStepConfig_t *PLLInitStepCfg);
bool  Clk_Hw_ExthfInit(uint32_t Timeout, const Clk_ExthfConfig_t *ConfigPtr);
float Clk_Hw_GetPLLClockSourceFrequency(void);
float Clk_Hw_GetSysPLLFrequency(void);
float Clk_Hw_GetPerPLL1Frequency(void);
float Clk_Hw_GetPerPLL2Frequency(void);
float Clk_Hw_GetFsource0Frequency(void);
float Clk_Hw_GetFsource1Frequency(void);
float Clk_Hw_GetFsource2Frequency(void);
float Clk_Hw_GetSysClkFrequency(void);
float Clk_Hw_GetPeriClkFrequency(void);
float Clk_Hw_GetSystickClkFrequency(void);
float Clk_Hw_GetCanHFrequency(void);
float Clk_Hw_GetRefClk1Frequency(void);
float Clk_Hw_GetRefClk2Frequency(void);
float Clk_Hw_GetMscClkFrequency(void);
float Clk_Hw_GetRtcClkFrequency(void);
float Clk_Hw_GetSpiClkFrequency(void);
float Clk_Hw_GetAdcClkFrequency(void);
float Clk_Hw_GetI2CClkFrequency(void);
float Clk_Hw_GetCanClkFrequency(void);
float Clk_Hw_GetUTLINFFrequency(void);
float Clk_Hw_GetUTLINSFrequency(void);
float Clk_Hw_GetCPU0Frequency(void);
float Clk_Hw_GetCPU1Frequency(void);
#ifdef __cplusplus
}
#endif
#endif
/* EOF */
