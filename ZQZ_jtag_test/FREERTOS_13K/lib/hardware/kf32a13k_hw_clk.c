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

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Include Files
 ******************************************************************************/

#include "kf32a13k_hw_clk.h"
#include "kf32a13k_hw_scu.h"
#include "kf32a13k_drv_clk.h"

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/

#define CLK_LOOP_TIMEOUT_CHECK(tVar, tErr)                                                                             \
    {                                                                                                                  \
        if (((int32_t)--tVar) <= 0)                                                                                    \
        {                                                                                                              \
            tErr = true;                                                                                               \
            break;                                                                                                     \
        }                                                                                                              \
        else                                                                                                           \
        {                                                                                                              \
        }                                                                                                              \
    }

/******************************************************************************
 *                      Static Variables
 ******************************************************************************/
static const Clk_PLLStepConfig_t         Clk_DefaultPLLConfigSteps[]  = {CLK_CFG_SYS_PLL_STEPS};
static const Clk_ClockDistributeConfig_t Clk_DefaultClockDistribution = {
  .AdcClkConfig =
    {
      .AdcClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
      .AdcClkSource   = CLK_HW_CDU_ADC_SOURCE_FSOURCE1,
    },
  .CanClkConfig =
    {
      .CANClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
      .CANClkSource   = CLK_HW_CDU_CAN_SOURCE_FSOURCE1,
    },
  .CANHClkConfig =
    {
      .CANHClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
    },
  .Cpu0ClkDivision = 0U,
  .Cpu1ClkDivision = 0U,
  .I2CClkConfig =
    {
      .I2CClkSource   = CLK_HW_CDU_I2C_SOURCE_FSOURCE1,
      .I2CClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
    },
  .LPClkDivision = CLK_HW_CDU_LPCLK_DIVISION_DEFAULT,
  .MscClkConfig =
    {
      .MSCClkSource   = CLK_HW_CDU_MSC_SOURCE_FSOURCE1,
      .MscClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
    },
  .PeriClkDivision = CLK_HW_CDU_COMMON_DIVISION_2,
  .RefClk1Config =
    {
      .RefClk1Division = CLK_HW_CDU_REFCLK_DIVISION_1,
    },
  .RefClk2Config =
    {
      .RefClk2Source   = CLK_HW_CDU_REFCLK2_SOURCE_FSOURCE1,
      .RefClk2Division = CLK_HW_CDU_REFCLK_DIVISION_1,
    },
  .RtcClkConfig =
    {
      .RTCClkSource   = CLK_HW_CDU_RTC_SOURCE_INTHF,
      .RTCClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
    },
  .SpiClkConfig =
    {
      .SpiClkSource   = CLK_HW_CDU_SPI_SOURCE_FSOURCE1,
      .SpiClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
    },
  .SysClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
  .SystickClkConfig =
    {
      .SysticktClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
    },
  .TmrClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
  .UTLINClkConfig =
    {
      .UTLINSClkSource   = CLK_HW_CDU_UTLINS_SOURCE_FSOURCE1,
      .UTLINSClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
    },
  .UTLINFClkConfig =
    {
      .UTLINFClkSource   = CLK_HW_CDU_UTLINF_SOURCE_FSOURCE1,
      .UTLINFClkDivision = CLK_HW_CDU_COMMON_DIVISION_1,
    },
};

static const Clk_DomainClockConfig_t Clk_DefaultDomainClockConfig = {
  .Source0ClockSource = CLK_HW_DOMAIN_SOURCE0_SYSPLL,
  .Source1ClockSource = CLK_HW_DOMAIN_SOURCE1_PERPLL1,
  .Source2ClockSource = CLK_HW_DOMAIN_SOURCE2_PERPLL2,
  .Source1Freq2Divide = false,
};
static const Clk_ModulateConfig_t Clk_DefaultModulateConfig = {
  .FreqModulateEnable  = false,
  .FreqModulateIntPart = 0,
  .FreqModulateDecPart = 0,
};
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

const Clk_ClockConfig_t Clk_DefaultClockConfig = {
#ifndef CLK_DISABLE_PLL_CONFIG
  /* PLL第一步配置，目标频率与内部高频频率一致 */
  .PLLInitialStepConfig = CLK_CFG_PLL_INITIAL_STEP,
  .SysPLLThrottleConfig =
    {
      sizeof(Clk_DefaultPLLConfigSteps) / sizeof(Clk_PLLStepConfig_t),
      (Clk_PLLStepConfig_t *)Clk_DefaultPLLConfigSteps,
    },
  .ModulateConfigPtr = &Clk_DefaultModulateConfig,
#endif
  .ClockDistributionPtr = &Clk_DefaultClockDistribution,
  .DomainClockConfigPtr = &Clk_DefaultDomainClockConfig,
};

/******************************************************************************
 *                      Static Functions
 ******************************************************************************/

/**
 * @brief NOP延时.
 *
 * @param DelayCount 乘以系统时钟频率后的延时时间 (单位us)
 * 举例:
 *      系统时钟频率300MHz，要延时10us，则应当设置输入300 * 10 = 3000
 * @attention 低频时延时时间不准确
 * @retval void
 */
#ifndef SIMULATION
__attribute__((noinline, section(".indata"), optnone)) static void Clk_NopDelay(uint32_t DelayCount)
{
    asm volatile("MOV R0, %0" ::"r"(DelayCount));
    asm volatile("LSR R0, #3");
    asm volatile("SUB R0, R0, #1");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("CMP R0, #0");
    asm volatile("JNZ $-5");
}
#else
void Clk_NopDelay(uint32_t DelayCount) {}
#endif

/**
 * @brief 初始化PLL，将系统/外设时钟源由INTHF100切换为SYSPLL/PERPLL
 *
 * @details PLL阶梯配置的第一步，采用默认数据时，会将系统PLL频率设置为INTHF100频率；
 * 外设PLL频率设置为最终目标频率（默认数据320MHz）
 *
 * @note 此阶段：
 * PLL输入时钟源改变
 * fsource0/1/2时钟源为INTHF100
 * CDU各模块时钟配置(时钟源/分频)不改变
 * PLL0钟频率保持100MHz（默认配置SYSPLL配置为100MHz）
 * PLL1、PLL2时钟频率设定至目标值（默认配置PERPLL配置为320MHz、200MHz）
 * 系统时钟频率保持100MHz(CDU未分配)
 * 各外设时钟保持默认(默认或时钟关闭)
 *
 * @param PLLInitStepCfg
 * @return
 */
bool Clk_ConfigPLLInitialStep(const Clk_PLLInitialStepConfig_t *PLLInitStepCfg)
{
    bool initError = false;
    /* 超时时间，防止编译器优化*/
    volatile uint32_t timeoutCycleCount = CLK_DOMAIN_LCK_BIT_TIMEOUT_COUNT;

    /* 时钟域设置*/
    {
        timeoutCycleCount = CLK_DOMAIN_LCK_BIT_TIMEOUT_COUNT;
        while (Clk_LL_GetDomainCtlRegLockStatus())
        {
            CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }
        /* PLL配置期间设置fsource0/1/2时钟源为INTHF100*/
        Clk_LL_SelectSource0ClockSource(CLK_DOMAIN_SOURCE0_INTHF100);
        Clk_LL_SelectSource1ClockSource(CLK_DOMAIN_SOURCE1_INTHF100);
        Clk_LL_SelectSource2ClockSource(CLK_DOMAIN_SOURCE2_INTHF100);
        /* 等待LKSTA清零*/
        timeoutCycleCount = CLK_DOMAIN_LCK_BIT_TIMEOUT_COUNT;
        while (Clk_LL_GetDomainCtlRegLockStatus())
        {
            CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }
    }
    /* TODO: 禁止SMU报警*/

    /* 配置PLL寄存器前设置PLL模块掉电，以保证异步PLL寄存器更新不会造成毛刺*/
    Clk_LL_SetSysPLLLowPowerStatus(false);
    Clk_LL_SetPerPLLLowPowerStatus(false);

    /* 等待PLL模块进入节能模式*/
    timeoutCycleCount = CLK_SYSPLLSTAT_PWDSTAT_TIMEOUT_COUNT;
    while (!Clk_LL_GetSysPLLLowPowerStatus() || !Clk_LL_GetPerPLLLowPowerStatus())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    /* 时钟源为外部晶振时配置晶振 */
    if ((PLLInitStepCfg->PLLParameters.PLLInputSource == CLK_PLL_SOURCE_EXTHF) ||
        (PLLInitStepCfg->PLLParameters.PLLInputSource == CLK_PLL_SOURCE_EXTCK))
    {
        /* 外部输入时钟模式，OSC 进入节能模式 */
        if (PLLInitStepCfg->PLLParameters.PLLInputSource == CLK_PLL_SOURCE_EXTCK)
        {
            Clk_LL_SelectOscMode(CLK_MODE_XHT_LOWPOWERON);
        }
        /* 外部晶振模式，OSC 未进入节能模式 */
        else
        {
            Clk_LL_SelectOscMode(CLK_MODE_EXTCLK_LOWPOWEROFF);
            /* 配置晶振 */
            {}
        }
    }
    else
    {
    }

    /* 选择PLL时钟源 */
    Clk_LL_SelectPLLClockSource((Clk_PLLClockSource_t)PLLInitStepCfg->PLLParameters.PLLInputSource);

    /* 使能PLL输入时钟 */
    {
        switch (PLLInitStepCfg->PLLParameters.PLLInputSource)
        {
            Clk_ClkSysSetIndex_t ClkSource;
        case CLK_PLL_SOURCE_EXTHF:
        case CLK_PLL_SOURCE_EXTCK:
            ClkSource = CLK_CLKSYS_SET_EXTHF;
            Clk_LL_SetClkSysEnabled(ClkSource);
            /* 等待时钟稳定 */
            while (!Clk_LL_GetClkSysSteadyStatus(ClkSource))
                ;
            break;
        case CLK_PLL_SOURCE_INTHF32:
            ClkSource = CLK_CLKSYS_SET_INTHF32;
            Clk_LL_SetClkSysEnabled(ClkSource);
            /* 等待时钟稳定 */
            while (!Clk_LL_GetClkSysSteadyStatus(ClkSource))
                ;
            break;
        case CLK_PLL_SOURCE_INTHF:
            /* INTHF默认使能 */
            break;
        default:
            initError = true;
            break;
        }
    }
    /*XTAL 范围16MHz - 40MHz*/
    /* 看门狗监测的参考时钟频率值 */
    Clk_LL_SetOscWDGRefFrequency(PLLInitStepCfg->PLLParameters.XtalFrequency / 1000000U - 15U);

    /* PLL断电状态下不需要重启看门狗（竞品注释） */
    // Clk_LL_SetOscWatachDogResetStatus(true);

    /* 设置系统PLL输入时钟2分频*/
    Clk_LL_SetSysPLLFreq2DivStatus(PLLInitStepCfg->PLLParameters.SysPLLConfigPtr.InputFreq2Divide);
    /* 设置系统PLL初始值 */
    {
        Clk_LL_SetSysPLLMultipleValue(
          PLLInitStepCfg->PLLParameters.SysPLLConfigPtr.PLLmultiple_M,
          PLLInitStepCfg->PLLParameters.SysPLLConfigPtr.PLLdivide_N);
        Clk_LL_SetSysPLLReset();
    }
    /* 设置外设PLL输入时钟2分频 */
    Clk_LL_SetPerPLLFreq2DivStatus(PLLInitStepCfg->PLLParameters.PeriPLLConfigPtr.InputFreq2Divide);
    /* 设置K3旁路 */
    Clk_LL_SetPerPLLDivBypassStatus(PLLInitStepCfg->PLLParameters.PeriPLLConfigPtr.K3DivBypass);
    /* 设置外设PLL初始值 */
    {
        Clk_LL_SetPerPLLMultipleValue(
          PLLInitStepCfg->PLLParameters.PeriPLLConfigPtr.PLLmultiple_M,
          PLLInitStepCfg->PLLParameters.PeriPLLConfigPtr.PLLdivide_N);
        Clk_LL_SetPerPLLReset();
    }
    /* 设置系统PLL+外设PLL模块上电 */
    Clk_LL_SetSysPLLLowPowerStatus(true);
    Clk_LL_SetPerPLLLowPowerStatus(true);

    timeoutCycleCount = CLK_SYSPLLSTAT_PWDSTAT_TIMEOUT_COUNT;
    /* 等待PLL模块退出节能模式*/
    while (Clk_LL_GetSysPLLLowPowerStatus() || Clk_LL_GetPerPLLLowPowerStatus())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    /* 等待K2、K3分频器就绪*/
    timeoutCycleCount = CLK_PLL_KRDY_TIMEOUT_COUNT;
    while (!Clk_LL_GetSysPLLK2Status() || !Clk_LL_GetPerPLLK2Status() || !Clk_LL_GetPerPLLK3Status())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }
    Clk_LL_SetSysPLLK2Value(PLLInitStepCfg->PLLParameters.SysPLLConfigPtr.PLLdivide_K2);
    Clk_LL_SetPerPLL1K2Value(PLLInitStepCfg->PLLParameters.PeriPLLConfigPtr.PLLdivide_K2);
    Clk_LL_SetPerPLL2K3Value(PLLInitStepCfg->PLLParameters.PeriPLLConfigPtr.PLLdivide_K3);
    while (!Clk_LL_GetSysPLLK2Status() || !Clk_LL_GetPerPLLK2Status() || !Clk_LL_GetPerPLLK3Status())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    /* 使能系统PLL*/
    Clk_LL_SetClkSysEnabled(CLK_CLKSYS_SET_SYSPLL);
    /* 等待时钟稳定 */
    while (!Clk_LL_GetClkSysSteadyStatus(CLK_CLKSYS_SET_SYSPLL))
        ;
    /* 使能外设PLL*/
    Clk_LL_SetClkSysEnabled(CLK_CLKSYS_SET_PERPLL);
    /* 等待时钟稳定 */
    while (!Clk_LL_GetClkSysSteadyStatus(CLK_CLKSYS_SET_PERPLL))
        ;

    /* 检查EXTHF频率是否处于上下限范围内，由看门狗使用 INTHF100 进行检查*/
    timeoutCycleCount = CLK_PLL_LOW_OR_HIGH_TIMEOUT_COUNT;
    /* fLV = foscnom * 0.75 - 0.31 MHz */
    /* fHV = foscnom * 1.86 + 0.21 MHz */
    /* 竞品逻辑：只要有一个处于范围内，就认为检查通过*/
    while (!Clk_LL_GetXTHFlag(CLK_XTH_GET_PLLLSTA) && !Clk_LL_GetXTHFlag(CLK_XTH_GET_PLLLSTA))
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }
    /* 开启PLL锁定*/
    {
        Clk_LL_ResetSysPLLDCO(true);
        Clk_LL_ResetPerPLLDCO(true);
        timeoutCycleCount = CLK_PLL_LOCK_TIMEOUT_COUNT;
        while (!Clk_LL_GetSysPLLLockStatus() || !Clk_LL_GetPerPLLLockStatus())
        {
            CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }
    }
    /* TODO: 使能SMU报警*/
    return (bool)initError;
}

/**
 * @brief 时钟域设置，配置fsource0/1/2时钟源
 * @attention 竞品该步骤在Clk_ConfigPLLInitialStep内，且使用的寄存器不同(竞品使用CCUCON0)
 *
 * @note 此阶段：
 * PLL0/1/2已锁定
 * PLL0/1/2频率为100MHz,320MHz,200MHz
 * fsource0/1/2时钟源改变
 * 使用默认配置时：
 * 系统时钟由INTHF100切换至PLL0(原因为fsource0时钟源改变)
 * fsource1由INTHF100切换至PLL1
 * fsource2由INTHF100切换至PLL2
 *
 * @param DomainClockConfigPtr
 * @return KF_INLINE
 */
bool Clk_ConfigDomainClockSource(const Clk_DomainClockConfig_t *DomainClockConfigPtr)
{
    bool initError = false;
    /* 超时时间，防止编译器优化*/
    volatile uint32_t timeoutCycleCount = CLK_DOMAIN_LCK_BIT_TIMEOUT_COUNT;
    Clk_LL_SelectSource0ClockSource((Clk_DomainClockSource0_t)DomainClockConfigPtr->Source0ClockSource);
    Clk_LL_SelectSource1ClockSource((Clk_DomainClockSource1_t)DomainClockConfigPtr->Source1ClockSource);
    Clk_LL_SelectSource2ClockSource((Clk_DomainClockSource2_t)DomainClockConfigPtr->Source2ClockSource);
    Clk_LL_SetFsource1Freq2DivStatus(DomainClockConfigPtr->Source1Freq2Divide);
    /* 等待LKSTA清零 */
    while (Clk_LL_GetDomainCtlRegLockStatus())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }
    return (bool)initError;
}

/**
 * @brief PLL频率调制初始化
 *
 *
 * @param ModulateConfigPtr
 */
void Clk_ModulationInit(const Clk_ModulateConfig_t *ModulateConfigPtr)
{
    Clk_LL_SetSysPLLFreqModulationStatus(ModulateConfigPtr->FreqModulateEnable);
    Clk_LL_SetSysPLLModulationValue(ModulateConfigPtr->FreqModulateIntPart, ModulateConfigPtr->FreqModulateDecPart);
}

/**
 * @brief 时钟分配
 *
 *
 * @param ClockDistributionPtr
 * @return
 */
bool Clk_DistributeClock(const Clk_ClockDistributeConfig_t *ClockDistributionPtr)
{
    bool       initError = false;
    CDU_CTL0_T tempReg0;
    CDU_CTL1_T tempReg1;
    CDU_CTL2_T tempReg2;
    /* 超时时间，防止编译器优化*/
    volatile uint32_t timeoutCycleCount = CLK_DOMAIN_LCK_BIT_TIMEOUT_COUNT;

    /* CDU_CTL0 */
    /* 等待，直至寄存器可被更新 */
    while (Clk_LL_GetCDUCTL0LockStatus())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }
    /*TODO: 是否需要整字写入?*/

    tempReg0.bits.LPCLKDIV   = ClockDistributionPtr->LPClkDivision;
    tempReg0.bits.TMRCLKDIV  = ClockDistributionPtr->TmrClkDivision;
    tempReg0.bits.SYSCLKDIV  = ClockDistributionPtr->SysClkDivision;
    tempReg0.bits.PERICLKDIV = ClockDistributionPtr->PeriClkDivision;
    CLK_PTR->CDU_CTL0.reg    = tempReg0.reg;
    Clk_LL_SetCDUCTLUpdate();
    /* 等待更新完成 */
    while (Clk_LL_GetCDUCTL0LockStatus())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    /* CDU_CTL1 */
    /* 等待，直至寄存器可被更新 */
    while (Clk_LL_GetCDUCTL1LockStatus())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }
    /*TODO: 是否需要整字写入?*/
    tempReg1.bits.STCLKDIV      = ClockDistributionPtr->SystickClkConfig.SysticktClkDivision;
    tempReg1.bits.CANHCLKDIV    = ClockDistributionPtr->CANHClkConfig.CANHClkDivision;
    tempReg1.bits.REFCLK1CLKDIV = ClockDistributionPtr->RefClk1Config.RefClk1Division;
    tempReg1.bits.REFCLK2CLKDIV = ClockDistributionPtr->RefClk2Config.RefClk2Division;
    tempReg1.bits.MSCCLKDIV     = ClockDistributionPtr->MscClkConfig.MscClkDivision;
    tempReg1.bits.RTCCLKDIV     = ClockDistributionPtr->RtcClkConfig.RTCClkDivision;
    /*TODO: 需确认，先设置分频，再选择时钟源?*/
    /*TODO: 需确认，竞品时钟源切换时，需要先关闭时钟，再选择新的时钟源*/
    tempReg1.bits.REFCLK2SEL = ClockDistributionPtr->RefClk2Config.RefClk2Source;
    tempReg1.bits.MSCCLKSEL  = ClockDistributionPtr->MscClkConfig.MSCClkSource;
    tempReg1.bits.RTCCLKSEL  = ClockDistributionPtr->RtcClkConfig.RTCClkSource;
    CLK_PTR->CDU_CTL1.reg    = tempReg1.reg;
    /* 等待更新完成 */
    while (Clk_LL_GetCDUCTL1LockStatus())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    /* CDU_CTL2 */
    /* 等待，直至寄存器可被更新 */
    while (Clk_LL_GetCDUCTL2LockStatus())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }
    /*TODO: 是否需要整字写入?*/
    tempReg2.bits.SPICLKDIV    = ClockDistributionPtr->SpiClkConfig.SpiClkDivision;
    tempReg2.bits.ADCCLKDIV    = ClockDistributionPtr->AdcClkConfig.AdcClkDivision;
    tempReg2.bits.I2CCLKDIV    = ClockDistributionPtr->I2CClkConfig.I2CClkDivision;
    tempReg2.bits.CANCLKDIV    = ClockDistributionPtr->CanClkConfig.CANClkDivision;
    tempReg2.bits.UTLINFCLKDIV = ClockDistributionPtr->UTLINFClkConfig.UTLINFClkDivision;
    tempReg2.bits.UTLINSCLKDIV = ClockDistributionPtr->UTLINClkConfig.UTLINSClkDivision;
    /*TODO: 需确认，先设置分频，再选择时钟源?*/
    /*TODO: 需确认，竞品时钟源切换时，需要先关闭时钟，再选择新的时钟源*/
    tempReg2.bits.SPICLKSEL    = ClockDistributionPtr->SpiClkConfig.SpiClkSource;
    tempReg2.bits.ADCCLKSEL    = ClockDistributionPtr->AdcClkConfig.AdcClkSource;
    tempReg2.bits.I2CCLKSEL    = ClockDistributionPtr->I2CClkConfig.I2CClkSource;
    tempReg2.bits.CANCLKSEL    = ClockDistributionPtr->CanClkConfig.CANClkSource;
    tempReg2.bits.UTLINFCLKSEL = ClockDistributionPtr->UTLINFClkConfig.UTLINFClkSource;
    tempReg2.bits.UTLINSCLKSEL = ClockDistributionPtr->UTLINClkConfig.UTLINSClkSource;
    CLK_PTR->CDU_CTL2.reg      = tempReg2.reg;
    /* 等待更新完成 */
    while (Clk_LL_GetCDUCTL2LockStatus())
    {
        CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
    }

    /* CDU_CTL3 */
    Clk_LL_SetCpu0ClkDivision(ClockDistributionPtr->Cpu0ClkDivision);
    /* CDU_CTL4 */
    Clk_LL_SetCpu1ClkDivision(ClockDistributionPtr->Cpu1ClkDivision);

    return (bool)initError;
}

/**
 * @brief 阶梯改变SYSPLL频率至目标值
 *
 * @attention 此步骤前已完成PLL锁定, 时钟域配置, 时钟分配(系统时钟已更改为SYSPLL)
 * @param PLLThrottleConfigPtr
 * @retval bool
 */
static bool Clk_ThrottleSysPLLClock(const Clk_PLLThrottleConfig_t *PLLThrottleConfigPtr)
{
    bool     initError     = false;
    uint32_t pllStepsCount = 0;
    /* 超时时间，防止编译器优化*/
    volatile uint32_t timeoutCycleCount = CLK_PLL_KRDY_TIMEOUT_COUNT;
    /* 开启PLL阶梯频率提升序列 */
    for (pllStepsCount = 0; pllStepsCount < PLLThrottleConfigPtr->NumOfSteps; pllStepsCount++)
    {
        timeoutCycleCount = CLK_PLL_KRDY_TIMEOUT_COUNT;
        while (!Clk_LL_GetSysPLLK2Status())
        {
            /**
             * @attention 此时延时不准确，因为系统时钟在每个step都在变化，固定延时Count产生的实际延时时间在变化
             *
             */
            CLK_LOOP_TIMEOUT_CHECK(timeoutCycleCount, initError);
        }
        Clk_LL_SetSysPLLK2Value(PLLThrottleConfigPtr->PLLStep[pllStepsCount].K2Step);
        /**
         * @attention
         * Delay_us延时函数基于最终SYSPLL频率CLK_SYS_PLL_FREQUENCY，使用asm volatile("NOP")实现，
         * 在SYSPLL未达到最终频率时，实际延时时间比设定值长
         *
         */
        Delay_us(PLLThrottleConfigPtr->PLLStep[pllStepsCount].WaitTime);
    }
    return (bool)initError;
}

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief 延时函数
 * @attention 最大延时时间为 0xFFFFFFFFU / SCLK, 单位us.
 *  300MHz -- 14,316,557us (14.32s)
 *  120MHz -- 35,791,394us (35.79s)
 *  72MHz -- 59,652,323us (59.65s)
 *  48MHz -- 89,478,485us (89.47s)
 * @attention 实际延时时间在DelayTime较小时不准确, 尤其是小于10us时.
 *
 * @param DelayTime 延时时间，单位us.
 * @retval void
 */
void Delay_us(const uint32_t DelayTime)
{
    uint32_t sysPLLFreq = CLK_SYS_PLL_FREQUENCY / 1000000;
    if (DelayTime > 0)
    {
        if (DelayTime > (0xFFFFFFFFU / sysPLLFreq))
        {
            (void)Clk_NopDelay(sysPLLFreq * (0xFFFFFFFFU / sysPLLFreq));
        }
        else
        {
            (void)Clk_NopDelay(sysPLLFreq * DelayTime);
        }
    }
    else
    {
    }
}

/**
 * @brief 时钟初始化
 *
 *
 * @param ClockConfigPtr
 * @retval bool
 *              false 初始化成功
 *              true 初始化失败
 */
bool Clk_Hw_InitClock(const Clk_ClockConfig_t *ClockConfigPtr)
{
    bool     status   = false;
    uint32_t password = Scu_Hw_WdtGetSafetyPassword();
    Scu_Hw_WdtClearSafetyEndinit(password);
#ifndef CLK_DISABLE_PLL_CONFIG
    /* TODO: 解除寄存器保护*/
    /* PLL初始配置 */
    status = Clk_ConfigPLLInitialStep(&ClockConfigPtr->PLLInitialStepConfig);
    if (!status)
    {
        /* CDU输入时钟选择 */
        status = Clk_ConfigDomainClockSource(ClockConfigPtr->DomainClockConfigPtr);
    }
    else
    {
    }
    if (!status)
    {
        /* 频率调制 */
        Clk_ModulationInit(ClockConfigPtr->ModulateConfigPtr);
        /* 时钟分配 */
        status = Clk_DistributeClock(ClockConfigPtr->ClockDistributionPtr);
    }
    else
    {
    }
    if (!status)
    {
        /* PLL阶梯配置 */
        status = Clk_ThrottleSysPLLClock(&ClockConfigPtr->SysPLLThrottleConfig);
    }
    else
    {
    }
#else
    /* CDU输入时钟选择 */
    status = Clk_ConfigDomainClockSource(ClockConfigPtr->DomainClockConfigPtr);
    if (!status)
    {
        /* 时钟分配 */
        status = Clk_DistributeClock(ClockConfigPtr->ClockDistributionPtr);
    }
    else
    {
    }
#endif
    Scu_Hw_WdtSetSafetyEndinit(password);
    /* TODO: 设置寄存器保护*/
    return status;
}
/**
 * @brief 时钟默认参数初始化时钟
 *
 * @retval bool
 *              false 初始化成功
 *              true 初始化失败
 */
bool Clk_Hw_InitClockByDefaultConfig()
{
    return (Clk_Hw_InitClock(&Clk_DefaultClockConfig));
}

/**
 * @brief EXTHF初始化
 *
 * @param Timeout
 * @param ConfigPtr
 * @return true
 * @return false
 */
bool Clk_Hw_ExthfInit(uint32_t Timeout, const Clk_ExthfConfig_t *ConfigPtr)
{
    bool              ret            = false;
    volatile uint32_t TimeOutCounter = 0;
    uint32_t          password       = Scu_Hw_WdtGetSafetyPassword();
    Scu_Hw_WdtClearSafetyEndinit(password);
    if (Clk_LL_GetClkSysStatus(CLK_CLKSYS_SET_EXTHF))
    {
        ret = true;
    }
    else
    {
        Clk_LL_SelectOscGainMode((Clk_OscGainMod_t)ConfigPtr->OscGainMode);
        Clk_LL_SelectOscMode((Clk_OscMod_t)ConfigPtr->OscMode);
        Clk_LL_SetOscShaperBypassStatus(ConfigPtr->OscShaperBypass);
        Clk_LL_SetOscHysteresisStatus(ConfigPtr->OscHysteresis);
        Clk_LL_SelectOscHysteresisMode((Clk_OscHysteresisMod_t)ConfigPtr->OscHysMode);
        Clk_LL_SelectOscAmpMode((Clk_OscAmpMod_t)ConfigPtr->OscAmpMode);
        Clk_LL_SetOscAmpRegulatorStatus(ConfigPtr->OscAmpRegulator);
        Clk_LL_SetOscWDGRefFrequency(ConfigPtr->WdgRefFreq);
        Clk_LL_SelectHSEMode((Clk_HseMode_t)ConfigPtr->HseMode);
        Clk_LL_SetXTHStatus(ConfigPtr->XTHEn);
        Clk_LL_SelectGmMode((Clk_GmMode_t)ConfigPtr->GmMode);
        Clk_LL_SetXTH2MOhmStatus(ConfigPtr->XTH2MOhmEn);
        Clk_LL_SetXTH470kOhmStatus(ConfigPtr->XTH470kOhmEn);
        Clk_LL_SetXTH200kOhmStatus(ConfigPtr->XTH200kOhmEn);
        Clk_LL_SetXTHComparatorShaperStatus(ConfigPtr->XTHCmpShaper);
        Clk_LL_SelectXTHComparatorCurrent((Clk_XTHCurrent_t)ConfigPtr->CmpCurrent);
        Clk_LL_SetXTHCapacitor0Status(ConfigPtr->XTHCap0En);
        Clk_LL_SetXTHCapacitor0Status(ConfigPtr->XTHCap1En);
        Clk_LL_SetXTHCapacitor0Status(ConfigPtr->XTHCap2En);
        Clk_LL_SetXTHCapacitor0Status(ConfigPtr->XTHCap3En);
        Clk_LL_SetClkSysEnabled(CLK_CLKSYS_SET_EXTHF);
        while (!Clk_LL_GetClkSysStatus(CLK_CLKSYS_SET_EXTHF))
        {
            /** Timeout为0则不执行超时 **/
            if (Timeout == 0)
            {
                continue;
            }
            TimeOutCounter++;
            if (TimeOutCounter >= Timeout)
            {
                ret = false;
                break;
            }
        }
    }
    Scu_Hw_WdtSetSafetyEndinit(password);
    return ret;
}

/**
 * @brief 获取PLL输入时钟频率
 *
 *
 * @retval 时钟频率，单位Hz
 */
float Clk_Hw_GetPLLClockSourceFrequency(void)
{
    float freq;
    switch ((Clk_PLLClockSource_t)CLK_PTR->SYSPLL_CTL0.bits.INCLKSEL)
    {
    case CLK_PLL_SOURCE_INTHF:
        freq = (float)CLK_INTHF100_FREQUENCY;
        break;
    case CLK_PLL_SOURCE_EXTCK:
    case CLK_PLL_SOURCE_EXTHF:
        freq = (float)CLK_XTAL_FREQUENCY;
        break;
    case CLK_PLL_SOURCE_INTHF32:
        freq = (float)CLK_INTHF32_FREQUENCY;
        break;
    default:
        /* Reserved values, this */
        freq = 0.0;
        break;
    }
    return freq;
}

/**
 * @brief 获取系统PLL(即PLL0)输出频率
 *
 * @return float 系统PLL频率，单位Hz
 */
float Clk_Hw_GetSysPLLFrequency(void)
{
    float freq;
    float inputFreq = Clk_Hw_GetPLLClockSourceFrequency();
    if (CLK_PTR->SYSPLL_CTL0.bits.N > 0)
    {
        /*TODO: 确认系统PLL的M和N参数是否需要+1操作*/
        freq = inputFreq / (float)(CLK_PTR->SYSPLL_CTL0.bits.PLLDIV + 1) * (float)(CLK_PTR->SYSPLL_CTL0.bits.M) /
               (float)(CLK_PTR->SYSPLL_CTL0.bits.N) / (float)(CLK_PTR->SYSPLL_CTL1.bits.K2CLKDIV + 1);
    }
    else
    {
    }
    return freq;
}

/**
 * @brief 获取PLL1输出频率
 *
 * @return float PLL1频率，单位Hz
 */
float Clk_Hw_GetPerPLL1Frequency(void)
{
    float freq;
    float inputFreq = Clk_Hw_GetPLLClockSourceFrequency();
    freq            = inputFreq * (float)(CLK_PTR->PERPLL_CTL0.bits.M + 1) /
           ((float)(CLK_PTR->PERPLL_CTL0.bits.PLLDIV + 1) * (float)(CLK_PTR->PERPLL_CTL0.bits.N) *
            (float)(CLK_PTR->PERPLL_CTL1.bits.K2CLKDIV + 1));
    return freq;
}

/**
 * @brief 获取PLL2输出频率
 *
 * @return float PLL2频率，单位Hz
 */
float Clk_Hw_GetPerPLL2Frequency(void)
{
    float freq;
    float inputFreq = Clk_Hw_GetPLLClockSourceFrequency();
    float k3divider = (CLK_PTR->PERPLL_CTL0.bits.DIVBYEN ? 2.0 : 1.6);
    freq            = inputFreq * (float)(CLK_PTR->PERPLL_CTL0.bits.M + 1) /
           ((float)(CLK_PTR->PERPLL_CTL0.bits.PLLDIV + 1) * (float)(CLK_PTR->PERPLL_CTL0.bits.N) *
            (float)(CLK_PTR->PERPLL_CTL1.bits.K3CLKDIV + 1) * k3divider);
    return freq;
}

/**
 * @brief 获取Fsource0频率
 *
 *
 * @param
 * @return
 */
float Clk_Hw_GetFsource0Frequency(void)
{
    float freq;
    switch ((Clk_DomainClockSource0_t)CLK_PTR->DOMAIN_CTL.bits.CLKSEL0)
    {
    case CLK_DOMAIN_SOURCE0_INTHF100:
        freq = (float)CLK_INTHF100_FREQUENCY;
        break;
    case CLK_DOMAIN_SOURCE0_INTHF32:
        freq = (float)CLK_INTHF32_FREQUENCY;
        break;
    case CLK_DOMAIN_SOURCE0_EXTHF:
        freq = (float)CLK_XTAL_FREQUENCY;
        break;
    case CLK_DOMAIN_SOURCE0_SYSPLL:
        freq = Clk_Hw_GetSysPLLFrequency();
        break;
    case CLK_DOMAIN_SOURCE0_PERPLL1:
        freq = Clk_Hw_GetPerPLL1Frequency();
        break;
    case CLK_DOMAIN_SOURCE0_PERPLL2:
        freq = Clk_Hw_GetPerPLL2Frequency();
        break;
    default:
        /* Reserved values, this */
        freq = 0.0;
        break;
    }
    return freq;
}

/**
 * @brief 获取Fsource1频率
 *
 *
 * @param
 * @return
 */
float Clk_Hw_GetFsource1Frequency(void)
{
    float freq;
    float div = CLK_PTR->DOMAIN_CTL.bits.PLL1DIV ? 2.0 : 1.0;
    switch ((Clk_DomainClockSource1_t)CLK_PTR->DOMAIN_CTL.bits.CLKSEL1)
    {
    case CLK_DOMAIN_SOURCE1_INTHF100:
        freq = (float)CLK_INTHF100_FREQUENCY / div;
        break;
    case CLK_DOMAIN_SOURCE1_INTHF32:
        freq = (float)CLK_INTHF32_FREQUENCY / div;
        break;
    case CLK_DOMAIN_SOURCE1_EXTHF:
        freq = (float)CLK_XTAL_FREQUENCY / div;
        break;
    case CLK_DOMAIN_SOURCE1_SYSPLL:
        freq = Clk_Hw_GetSysPLLFrequency() / div;
        break;
    case CLK_DOMAIN_SOURCE1_PERPLL1:
        freq = Clk_Hw_GetPerPLL1Frequency() / div;
        break;
    case CLK_DOMAIN_SOURCE1_PERPLL2:
        freq = Clk_Hw_GetPerPLL2Frequency() / div;
        break;
    default:
        /* Reserved values, this */
        freq = 0.0;
        break;
    }
    return freq;
}

/**
 * @brief 获取Fsource2频率
 *
 *
 * @param
 * @return
 */
float Clk_Hw_GetFsource2Frequency(void)
{
    float freq;
    switch ((Clk_DomainClockSource0_t)CLK_PTR->DOMAIN_CTL.bits.CLKSEL2)
    {
    case CLK_DOMAIN_SOURCE2_INTHF100:
        freq = (float)CLK_INTHF100_FREQUENCY;
        break;
    case CLK_DOMAIN_SOURCE2_INTHF32:
        freq = (float)CLK_INTHF32_FREQUENCY;
        break;
    case CLK_DOMAIN_SOURCE2_EXTHF:
        freq = (float)CLK_XTAL_FREQUENCY;
        break;
    case CLK_DOMAIN_SOURCE2_SYSPLL:
        freq = Clk_Hw_GetSysPLLFrequency();
        break;
    case CLK_DOMAIN_SOURCE2_PERPLL1:
        freq = Clk_Hw_GetPerPLL1Frequency();
        break;
    case CLK_DOMAIN_SOURCE2_PERPLL2:
        freq = Clk_Hw_GetPerPLL2Frequency();
        break;
    default:
        /* Reserved values, this */
        freq = 0.0;
        break;
    }
    return freq;
}

/**
 * @brief 获取系统时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetSysClkFrequency(void)
{
    return (CLK_PTR->CDU_CTL0.bits.SYSCLKDIV > 0
              ? Clk_Hw_GetFsource0Frequency() / (float)CLK_PTR->CDU_CTL0.bits.SYSCLKDIV
              : 0);
}

/**
 * @brief 获取外设时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetPeriClkFrequency(void)
{
    return (CLK_PTR->CDU_CTL0.bits.PERICLKDIV > 1
              ? Clk_Hw_GetFsource0Frequency() / (float)CLK_PTR->CDU_CTL0.bits.PERICLKDIV
              : 0);
}

/**
 * @brief 获取Systick时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetSystickClkFrequency(void)
{
    return (
      CLK_PTR->CDU_CTL1.bits.STCLKDIV > 0 ? Clk_Hw_GetFsource0Frequency() / (float)CLK_PTR->CDU_CTL1.bits.STCLKDIV : 0);
}

/**
 * @brief 获取CANH时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetCanHFrequency(void)
{
    return (CLK_PTR->CDU_CTL1.bits.CANHCLKDIV > 0
              ? Clk_Hw_GetFsource0Frequency() / (float)CLK_PTR->CDU_CTL1.bits.CANHCLKDIV
              : 0);
}

/**
 * @brief 获取REFCLK1时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetRefClk1Frequency(void)
{
    return (CLK_PTR->CDU_CTL1.bits.REFCLK1CLKDIV > 0
              ? Clk_Hw_GetFsource0Frequency() / (float)CLK_PTR->CDU_CTL1.bits.REFCLK1CLKDIV
              : 0);
}

/**
 * @brief 获取REFCLK2时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetRefClk2Frequency(void)
{
    float ret = 0;
    if (CLK_PTR->CDU_CTL1.bits.REFCLK2SEL)
    {
        ret = (CLK_PTR->CDU_CTL1.bits.REFCLK2CLKDIV > 0
                 ? Clk_Hw_GetFsource1Frequency() / (float)CLK_PTR->CDU_CTL1.bits.REFCLK2CLKDIV
                 : 0);
    }
    else
    {
        ret = (CLK_PTR->CDU_CTL1.bits.REFCLK2CLKDIV > 0
                 ? Clk_Hw_GetFsource2Frequency() / (float)CLK_PTR->CDU_CTL1.bits.REFCLK2CLKDIV
                 : 0);
    }
    return ret;
}

/**
 * @brief 获取MSC时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetMscClkFrequency(void)
{
    float ret = 0;
    if (CLK_PTR->CDU_CTL1.bits.MSCCLKSEL)
    {
        ret = (CLK_PTR->CDU_CTL1.bits.MSCCLKDIV > 0
                 ? Clk_Hw_GetFsource1Frequency() / (float)CLK_PTR->CDU_CTL1.bits.MSCCLKDIV
                 : 0);
    }
    else
    {
        ret = (CLK_PTR->CDU_CTL1.bits.MSCCLKDIV > 0
                 ? Clk_Hw_GetFsource2Frequency() / (float)CLK_PTR->CDU_CTL1.bits.MSCCLKDIV
                 : 0);
    }
    return ret;
}

/**
 * @brief 获取RTC时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetRtcClkFrequency(void)
{
    float ret = 0;
    if (CLK_PTR->CDU_CTL1.bits.RTCCLKSEL)
    {
        ret = (CLK_PTR->CDU_CTL1.bits.RTCCLKDIV > 0
                 ? (float)CLK_INTHF100_FREQUENCY / (float)CLK_PTR->CDU_CTL1.bits.RTCCLKDIV
                 : 0);
    }
    else
    {
        ret = (CLK_PTR->CDU_CTL1.bits.RTCCLKDIV > 0
                 ? (float)CLK_XTAL_FREQUENCY / (float)CLK_PTR->CDU_CTL1.bits.RTCCLKDIV
                 : 0);
    }
    return ret;
}

/**
 * @brief 获取SPI时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetSpiClkFrequency(void)
{
    float ret = 0;
    if (CLK_PTR->CDU_CTL2.bits.SPICLKSEL)
    {
        ret = (CLK_PTR->CDU_CTL2.bits.SPICLKDIV > 0
                 ? Clk_Hw_GetFsource1Frequency() / (float)CLK_PTR->CDU_CTL2.bits.SPICLKDIV
                 : 0);
    }
    else
    {
        ret = (CLK_PTR->CDU_CTL2.bits.SPICLKDIV > 0
                 ? Clk_Hw_GetFsource2Frequency() / (float)CLK_PTR->CDU_CTL2.bits.SPICLKDIV
                 : 0);
    }
    return ret;
}

/**
 * @brief 获取ADC时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetAdcClkFrequency(void)
{
    float ret = 0;
    if (CLK_PTR->CDU_CTL2.bits.ADCCLKSEL)
    {
        ret = (CLK_PTR->CDU_CTL2.bits.ADCCLKDIV > 0
                 ? Clk_Hw_GetFsource1Frequency() / (float)CLK_PTR->CDU_CTL2.bits.ADCCLKDIV
                 : 0);
    }
    else
    {
        ret = (CLK_PTR->CDU_CTL2.bits.ADCCLKDIV > 0
                 ? Clk_Hw_GetFsource2Frequency() / (float)CLK_PTR->CDU_CTL2.bits.ADCCLKDIV
                 : 0);
    }
    return ret;
}

/**
 * @brief 获取I2C时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetI2CClkFrequency(void)
{
    float ret = 0;
    if (CLK_PTR->CDU_CTL2.bits.ADCCLKSEL)
    {
        ret = (CLK_PTR->CDU_CTL2.bits.I2CCLKDIV > 0
                 ? Clk_Hw_GetFsource1Frequency() / (float)CLK_PTR->CDU_CTL2.bits.I2CCLKDIV
                 : 0);
    }
    else
    {
        ret = (CLK_PTR->CDU_CTL2.bits.I2CCLKDIV > 0
                 ? Clk_Hw_GetFsource2Frequency() / (float)CLK_PTR->CDU_CTL2.bits.I2CCLKDIV
                 : 0);
    }
    return ret;
}

/**
 * @brief 获取CAN时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetCanClkFrequency(void)
{
    float ret = 0;
    if (CLK_PTR->CDU_CTL2.bits.CANCLKSEL)
    {
        ret = (CLK_PTR->CDU_CTL2.bits.CANCLKDIV > 0
                 ? Clk_Hw_GetFsource1Frequency() / (float)CLK_PTR->CDU_CTL2.bits.CANCLKDIV
                 : 0);
    }
    else
    {
        ret = (CLK_PTR->CDU_CTL2.bits.CANCLKDIV > 0
                 ? Clk_Hw_GetFsource2Frequency() / (float)CLK_PTR->CDU_CTL2.bits.CANCLKDIV
                 : 0);
    }
    return ret;
}

/**
 * @brief 获取UTLINF时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetUTLINFFrequency(void)
{
    float ret = 0;
    if (CLK_PTR->CDU_CTL2.bits.UTLINFCLKSEL)
    {
        ret = (CLK_PTR->CDU_CTL2.bits.UTLINFCLKDIV > 0
                 ? Clk_Hw_GetFsource1Frequency() / (float)CLK_PTR->CDU_CTL2.bits.UTLINFCLKDIV
                 : 0);
    }
    else
    {
        ret = (CLK_PTR->CDU_CTL2.bits.UTLINFCLKDIV > 0
                 ? Clk_Hw_GetFsource2Frequency() / (float)CLK_PTR->CDU_CTL2.bits.UTLINFCLKDIV
                 : 0);
    }
    return ret;
}

/**
 * @brief 获取UTLINS时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetUTLINSFrequency(void)
{
    float ret = 0;
    if (CLK_PTR->CDU_CTL2.bits.UTLINSCLKSEL)
    {
        ret = (CLK_PTR->CDU_CTL2.bits.UTLINSCLKDIV > 0
                 ? Clk_Hw_GetFsource1Frequency() / (float)CLK_PTR->CDU_CTL2.bits.UTLINSCLKDIV
                 : 0);
    }
    else
    {
        ret = (CLK_PTR->CDU_CTL2.bits.UTLINSCLKDIV > 0
                 ? Clk_Hw_GetFsource2Frequency() / (float)CLK_PTR->CDU_CTL2.bits.UTLINSCLKDIV
                 : 0);
    }
    return ret;
}

/**
 * @brief 获取CPU0时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetCPU0Frequency(void)
{
    return (Clk_Hw_GetSysClkFrequency() * (64.F - (float)CLK_PTR->CDU_CTL3.bits.CPU0CLKDIV) / 64.F);
}

/**
 * @brief 获取CPU1时钟频率， 单位: 1.Hz
 *
 *
 * @param
 * @retval
 */
float Clk_Hw_GetCPU1Frequency(void)
{
    return (Clk_Hw_GetSysClkFrequency() * (64.F - (float)CLK_PTR->CDU_CTL4.bits.CPU1CLKDIV) / 64.F);
}
/******************************************************************************
 *                      Static Assert
 ******************************************************************************/
KF_STATIC_ASSERT(CLK_PLL_CLK_SOURCE_INTHF100 == CLK_PLL_SOURCE_INTHF, "Assert Failed: PLL时钟源定义不一致");
KF_STATIC_ASSERT(CLK_PLL_CLK_SOURCE_INTHF32 == CLK_PLL_SOURCE_INTHF32, "Assert Failed: PLL时钟源定义不一致");
KF_STATIC_ASSERT(CLK_PLL_CLK_SOURCE_EXTHF == CLK_PLL_SOURCE_EXTHF, "Assert Failed: PLL时钟源定义不一致");
KF_STATIC_ASSERT(CLK_PLL_CLK_SOURCE_EXTCK == CLK_PLL_SOURCE_EXTCK, "Assert Failed: PLL时钟源定义不一致");
#ifdef __cplusplus
}
#endif
/* EOF */
