/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_clk_cfg.h
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
 *                              REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2024-01-15    |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/
#ifndef KF32DA13K_CLK_CFG_H_
#define KF32DA13K_CLK_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Include Files
 ******************************************************************************/

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/

/******************************************************************************
 *                      用户配置信息
 ******************************************************************************/

/* TODO: 该配置应放在顶层用户配置内，由Osc模块获取使用*/

#define CLK_DISABLE_PLL_CONFIG (1U)

/* 外部晶振频率，单位Hz */
#define CLK_XTAL_FREQUENCY (40000000U) /* 允许值: 40000000, 25000000, 20000000, 16000000 */
/* 系统PLL频率，单位Hz */
#define CLK_SYS_PLL_FREQUENCY (300000000U) /* 允许值: 300000000, 200000000, 160000000, 133000000 or 80000000 */
/* 外设PLL1频率，单位Hz */
#define CLK_PER_PLL1_FREQUENCY (320000000U) /* 允许值: 320000000, 160000000 */
/* 外设PLL2频率，单位Hz */
#define CLK_PER_PLL2_FREQUENCY (200000000U) /* 允许值: 200000000 */

/******************************************************************************
 *                      基本定义
 ******************************************************************************/
#define CLK_PLL_CLK_SOURCE_INTHF100 (0U)
#define CLK_PLL_CLK_SOURCE_EXTHF    (1U)
#define CLK_PLL_CLK_SOURCE_EXTCK    (2U)
#define CLK_PLL_CLK_SOURCE_INTHF32  (3U)

#define CLK_PLL_CLOCK_SOURCE_SELECT CLK_PLL_CLK_SOURCE_EXTHF

/* 内部备份时钟频率，单位Hz */
#define CLK_INTHF100_FREQUENCY (100000000U)
/* 内部高频时钟频率，单位Hz */
#define CLK_INTHF32_FREQUENCY (32000000U)

#ifndef CLK_XTAL_FREQUENCY
#define CLK_XTAL_FREQUENCY 20000000 /* 默认外部晶振频率 */
#warning "CLK_XTAL_FREQUENCY not specified in your config file."
#warning "Please double check the external XTAL frequency with the default setting of 20 MHz!"
#endif

#ifndef CLK_SYS_PLL_FREQUENCY
#define CLK_SYS_PLL_FREQUENCY 300000000 /* 默认系统PLL频率 */
#endif

#ifndef CLK_PER_PLL1_FREQUENCY
#define CLK_PER_PLL1_FREQUENCY 320000000 /* 默认外设PLL频率 */
#endif

/* 默认选择外部晶振作为输入 */
/*
 该宏置1可选择外部输入时钟
 外部输入时钟信号 EXTCK 可以由 XTH_IN 引脚输入时钟或其他 IO 引脚直接输入，参考手册《外部输入时钟模式》
 */
#ifndef CLK_EXT_CLOCK
#define CLK_EXT_CLOCK 0 /* 默认外部晶振作为输入 */
#endif

/* TODO: 支持的晶振频率和PLL频率需要由IC提供 */

/*配置结构使用的工具宏 */
#if ((CLK_PLL_CLOCK_SOURCE_SELECT == CLK_PLL_CLK_SOURCE_EXTHF) ||                                                      \
     (CLK_PLL_CLOCK_SOURCE_SELECT == CLK_PLL_CLK_SOURCE_EXTCK))
#if (CLK_XTAL_FREQUENCY == (20000000))
#define CLK_CFG_XTAL_FREQ 20MHZ
#elif (CLK_XTAL_FREQUENCY == (25000000))
#define CLK_CFG_XTAL_FREQ 25MHZ
#elif (CLK_XTAL_FREQUENCY == (40000000))
#define CLK_CFG_XTAL_FREQ 40MHZ
#elif (CLK_XTAL_FREQUENCY == (16000000))
#define CLK_CFG_XTAL_FREQ 16MHZ
#else
#error "Wrong XTAL frequency configuration! check CLK_XTAL_FREQUENCY configuration in Cfg.h."
#error "Supported crystal frequencies are  16MHz, 20MHz, 25MHz and 40MHz"
#endif
#elif (CLK_PLL_CLOCK_SOURCE_SELECT == CLK_PLL_CLK_SOURCE_INTHF100)
#define CLK_CFG_XTAL_FREQ 100MHZ
#elif (CLK_PLL_CLOCK_SOURCE_SELECT == CLK_PLL_CLK_SOURCE_INTHF32)
#define CLK_CFG_XTAL_FREQ 32MHZ
#else
#error "Wrong PLL clock source selection"
#error                                                                                                                 \
  "Supported PLL clock source: CLK_PLL_CLK_SOURCE_INTHF100, CLK_PLL_CLK_SOURCE_EXTHF, CLK_PLL_CLK_SOURCE_INTHF32, CLK_PLL_CLK_SOURCE_EXTCK"
#endif
/******************************************************************************
 *                      系统PLL工具宏
 ******************************************************************************/
#if (CLK_SYS_PLL_FREQUENCY == (80000000))
#define CLK_CFG_SYS_PLL_FREQ 80MHZ
#elif (CLK_SYS_PLL_FREQUENCY == (133000000)) && (CLK_XTAL_FREQUENCY != (8000000))
#define CLK_CFG_SYS_PLL_FREQ 133MHZ
#elif (CLK_SYS_PLL_FREQUENCY == (160000000))
#define CLK_CFG_SYS_PLL_FREQ 160MHZ
#elif (CLK_SYS_PLL_FREQUENCY == (200000000))
#define CLK_CFG_SYS_PLL_FREQ 200MHZ
#elif (CLK_SYS_PLL_FREQUENCY == (240000000))
#define CLK_CFG_SYS_PLL_FREQ 240MHZ
#elif (CLK_SYS_PLL_FREQUENCY == (300000000))
#define CLK_CFG_SYS_PLL_FREQ 300MHZ
#else
#error "Wrong PLL frequency configuration!, check CLK_SYS_PLL_FREQUENCY configuration in Cfg.h."
#error "Supported PLL frequencies are 80MHz, 133MHz (8MHz XTAL doesn't support), 160Mhz, 200MHz, 240Mhz, and 300MHz."
#endif

/******************************************************************************
 *                      外设PLL工具宏
 ******************************************************************************/
#if (CLK_PER_PLL1_FREQUENCY == (320000000))
#define CLK_CFG_PER_PLL1_FREQ 320MHZ
#elif (CLK_PER_PLL1_FREQUENCY == (160000000))
#define CLK_CFG_PER_PLL1_FREQ 160MHZ
#else
#error "Wrong PLL1 frequency configuration!, check CLK_PER_PLL1_FREQUENCY configuration in Cfg.h."
#error "Supported PLL1 frequencies are 160MHz and 320MHz."
#endif

#if (CLK_PER_PLL2_FREQUENCY == (200000000))
#define CLK_CFG_PER_PLL2_FREQ 200MHZ
#else
#error "Wrong PLL2 frequency configuration!, check CLK_PER_PLL2_FREQUENCY configuration in Cfg.h."
#error "Supported PLL2 frequency is 200MHz."
#endif

/******************************************************************************
 *                      系统PLL配置
 ******************************************************************************/

#ifndef CLK_CFG_SYS_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ
#define CLK_CFG_SYS_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ                                                             \
    {                                                                                                                  \
      /*Step 1 Config: 150MHz*/                                                                                        \
      (4 - 1), /*uint32_t k2Step;*/                                                                                    \
      100,     /*uint32_t waitTime;*/                                                                                  \
    },                                                                                                                 \
    {                                                                                                                  \
        /*Step 2 Config: 200MHz*/                                                                                      \
        (3 - 1), /*uint32_t k2Step;*/                                                                                  \
          100,   /*uint32_t waitTime;*/                                                                                \
    }
#endif /*#ifndef CLK_CFG_SYS_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ */

#ifndef CLK_CFG_SYS_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ
#define CLK_CFG_SYS_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ                                                             \
    {                                                                                                                  \
      /*Step 1 Config: 150MHz*/                                                                                        \
      (4 - 1), /*uint32_t k2Step;*/                                                                                    \
      100,     /*uint32_t waitTime;*/                                                                                  \
    },                                                                                                                 \
      {                                                                                                                \
        /*Step 2 Config: 200MHz*/                                                                                      \
        (3 - 1), /*uint32_t k2Step;*/                                                                                  \
        100,     /*uint32_t waitTime;*/                                                                                \
      },                                                                                                               \
    {            /*Step 3 Config: 300MHz*/                                                                             \
        (2 - 1), /*uint32_t k2Step;*/                                                                                  \
          100,   /*uint32_t waitTime;*/                                                                                \
    }
#endif /*#ifndef CLK_CFG_SYS_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ */

#ifndef CLK_CFG_SYS_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ
#define CLK_CFG_SYS_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ                                                             \
    {                                                                                                                  \
      /*Step 1 Config: 120MHz*/                                                                                        \
      (6 - 1), /*uint32_t k2Step;*/                                                                                    \
      100,     /*uint32_t waitTime;*/                                                                                  \
    },                                                                                                                 \
      {                                                                                                                \
        /*Step 2 Config: 180MHz*/                                                                                      \
        (4 - 1), /*uint32_t k2Step;*/                                                                                  \
        100,     /*uint32_t waitTime;*/                                                                                \
      },                                                                                                               \
    {            /*Step 3 Config: 240MHz*/                                                                             \
        (3 - 1), /*uint32_t k2Step;*/                                                                                  \
          100,   /*uint32_t waitTime;*/                                                                                \
    }
#endif /*#ifndef CLK_CFG_SYS_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ */

/***********************晶振频率 = 20MHz ***********************************/

/***********************系统PLL目标 = 200MHz*******************************/
#ifndef CLK_CFG_SYS_PLL_20MHZ_200MHZ
/* PLL第一步配置：20MHz晶振+100MHz 系统PLL, fDCO = 600MHz*/
#define CLK_CFG_SYS_PLL_20MHZ_200MHZ                                                                                   \
    /*{ uint32_t PLLdivide_N, uint32_t PLLmultiple_M, uint32_t PLLdivide_K2, bool InputFreq2Divide }*/                 \
    {                                                                                                                  \
        (1 - 1), (30 - 1), (6 - 1), false                                                                              \
    }
#endif /*#ifndef CLK_CFG_SYS_PLL_20MHZ_200MHZ */

#ifndef CLK_CFG_WAIT_INITIAL_STEP_20MHZ_200MHZ
/* TODO:竞品200us，根据实际延时修改*/
#define CLK_CFG_WAIT_INITIAL_STEP_20MHZ_200MHZ ((uint32_t)200)
#endif /*#ifndef CLK_CFG_WAIT_INITIAL_STEP_20MHZ_200MHZ */

#ifndef CLK_CFG_SYS_PLL_STEPS_20MHZ_200MHZ
/* PLL阶梯配置：20MHz晶振+200MHz 系统PLL, fDCO = 600MHz*/
#define CLK_CFG_SYS_PLL_STEPS_20MHZ_200MHZ CLK_CFG_SYS_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ
#endif /*#ifndef CLK_CFG_SYS_PLL_STEPS_20MHZ_200MHZ */

/***********************系统PLL目标 = 240MHz*******************************/
#ifndef CLK_CFG_SYS_PLL_20MHZ_240MHZ
/* PLL第一步配置：20MHz晶振+100MHz 系统PLL, fDCO = 720MHz*/
#define CLK_CFG_SYS_PLL_20MHZ_240MHZ                                                                                   \
    /*{ uint32_t PLLdivide_N, uint32_t PLLmultiple_M, uint32_t PLLdivide_K2, bool InputFreq2Divide }*/                 \
    {                                                                                                                  \
        (1 - 1), (36 - 1), (8 - 1), false                                                                              \
    }
#endif /*#ifndef CLK_CFG_SYS_PLL_20MHZ_240MHZ */

#ifndef CLK_CFG_WAIT_INITIAL_STEP_20MHZ_240MHZ
/* TODO:竞品200us，根据实际延时修改*/
#define CLK_CFG_WAIT_INITIAL_STEP_20MHZ_240MHZ ((uint32_t)200)
#endif /*#ifndef CLK_CFG_WAIT_INITIAL_STEP_20MHZ_240MHZ */

#ifndef CLK_CFG_SYS_PLL_STEPS_20MHZ_240MHZ
/* PLL阶梯配置：20MHz晶振+240MHz 系统PLL, fDCO = 600MHz*/
#define CLK_CFG_SYS_PLL_STEPS_20MHZ_240MHZ CLK_CFG_SYS_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ
#endif /*#ifndef CLK_CFG_SYS_PLL_STEPS_20MHZ_240MHZ */

/***********************系统PLL目标 = 300MHz*******************************/
#ifndef CLK_CFG_SYS_PLL_20MHZ_300MHZ
/* PLL第一步配置：20MHz晶振+100MHz 系统PLL, fDCO = 600MHz*/
#define CLK_CFG_SYS_PLL_20MHZ_300MHZ                                                                                   \
    /*{ uint32_t PLLdivide_N, uint32_t PLLmultiple_M, uint32_t PLLdivide_K2, bool InputFreq2Divide }*/                 \
    {                                                                                                                  \
        (1 - 1), (30 - 1), (6 - 1), false                                                                              \
    }
#endif /*#ifndef CLK_CFG_SYS_PLL_20MHZ_300MHZ */

#ifndef CLK_CFG_WAIT_INITIAL_STEP_20MHZ_300MHZ
/* TODO:竞品200us，根据实际延时修改*/
#define CLK_CFG_WAIT_INITIAL_STEP_20MHZ_300MHZ ((uint32_t)200)
#endif /*#ifndef CLK_CFG_WAIT_INITIAL_STEP_20MHZ_300MHZ */

#ifndef CLK_CFG_SYS_PLL_STEPS_20MHZ_300MHZ
/* PLL阶梯配置：20MHz晶振+300MHz 系统PLL, fDCO = 600MHz*/
#define CLK_CFG_SYS_PLL_STEPS_20MHZ_300MHZ CLK_CFG_SYS_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ
#endif /*#ifndef CLK_CFG_SYS_PLL_STEPS_20MHZ_300MHZ */

/***********************晶振频率 = 40MHz ***********************************/

/***********************系统PLL目标 = 200MHz*******************************/
#ifndef CLK_CFG_SYS_PLL_40MHZ_200MHZ
/* PLL第一步配置：40MHz晶振+100MHz 系统PLL, fDCO = 600MHz*/
#define CLK_CFG_SYS_PLL_40MHZ_200MHZ                                                                                   \
    /*{ uint32_t PLLdivide_N, uint32_t PLLmultiple_M, uint32_t PLLdivide_K2, bool InputFreq2Divide }*/                 \
    {                                                                                                                  \
        (1 - 1), (15 - 1), (6 - 1), false                                                                              \
    }
#endif /*#ifndef CLK_CFG_SYS_PLL_40MHZ_200MHZ */

#ifndef CLK_CFG_WAIT_INITIAL_STEP_40MHZ_200MHZ
/* TODO:竞品200us，根据实际延时修改*/
#define CLK_CFG_WAIT_INITIAL_STEP_40MHZ_200MHZ ((uint32_t)200)
#endif /*#ifndef CLK_CFG_WAIT_INITIAL_STEP_40MHZ_200MHZ */

#ifndef CLK_CFG_SYS_PLL_STEPS_40MHZ_200MHZ
/* PLL阶梯配置：40MHz晶振+200MHz 系统PLL, fDCO = 600MHz*/
#define CLK_CFG_SYS_PLL_STEPS_40MHZ_200MHZ CLK_CFG_SYS_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ
#endif /*#ifndef CLK_CFG_SYS_PLL_STEPS_40MHZ_200MHZ */

/***********************系统PLL目标 = 240MHz*******************************/
#ifndef CLK_CFG_SYS_PLL_40MHZ_240MHZ
/* PLL第一步配置：40MHz晶振+100MHz 系统PLL, fDCO = 720MHz*/
#define CLK_CFG_SYS_PLL_40MHZ_240MHZ                                                                                   \
    /*{ uint32_t PLLdivide_N, uint32_t PLLmultiple_M, uint32_t PLLdivide_K2, bool InputFreq2Divide }*/                 \
    {                                                                                                                  \
        (2 - 1), (36 - 1), (8 - 1), false                                                                              \
    }
#endif /*#ifndef CLK_CFG_SYS_PLL_40MHZ_240MHZ */

#ifndef CLK_CFG_WAIT_INITIAL_STEP_40MHZ_240MHZ
/* TODO:竞品200us，根据实际延时修改*/
#define CLK_CFG_WAIT_INITIAL_STEP_40MHZ_240MHZ ((uint32_t)200)
#endif /*#ifndef CLK_CFG_WAIT_INITIAL_STEP_40MHZ_240MHZ */

#ifndef CLK_CFG_SYS_PLL_STEPS_40MHZ_240MHZ
/* PLL阶梯配置：40MHz晶振+240MHz 系统PLL, fDCO = 600MHz*/
#define CLK_CFG_SYS_PLL_STEPS_40MHZ_240MHZ CLK_CFG_SYS_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ
#endif /*#ifndef CLK_CFG_SYS_PLL_STEPS_40MHZ_240MHZ */

/***********************系统PLL目标 = 300MHz*******************************/
#ifndef CLK_CFG_SYS_PLL_40MHZ_300MHZ
/* PLL第一步配置：40MHz晶振+100MHz 系统PLL, fDCO = 600MHz*/
#define CLK_CFG_SYS_PLL_40MHZ_300MHZ                                                                                   \
    /*{ uint32_t PLLdivide_N, uint32_t PLLmultiple_M, uint32_t PLLdivide_K2, bool InputFreq2Divide }*/                 \
    {                                                                                                                  \
        (1 - 1), (15 - 1), (6 - 1), false                                                                              \
    }
#endif /*#ifndef CLK_CFG_SYS_PLL_40MHZ_300MHZ */

#ifndef CLK_CFG_WAIT_INITIAL_STEP_40MHZ_300MHZ
/* TODO:竞品200us，根据实际延时修改*/
#define CLK_CFG_WAIT_INITIAL_STEP_40MHZ_300MHZ ((uint32_t)200)
#endif /*#ifndef CLK_CFG_WAIT_INITIAL_STEP_40MHZ_300MHZ */

#ifndef CLK_CFG_SYS_PLL_STEPS_40MHZ_300MHZ
/* PLL阶梯配置：40MHz晶振+300MHz 系统PLL, fDCO = 600MHz*/
#define CLK_CFG_SYS_PLL_STEPS_40MHZ_300MHZ CLK_CFG_SYS_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ
#endif /*#ifndef CLK_CFG_SYS_PLL_STEPS_40MHZ_300MHZ */

/******************************************************************************
 *                      外设PLL配置
 ******************************************************************************/
/***********************晶振频率 = 20MHz ***********************************/
/***********************外设PLL目标 PLL1 = 320MHz, PLL2 = 200MHz*******************************/
#ifndef CLK_CFG_PER_PLL_20MHZ_320MHZ_200MHZ
/* 20MHz晶振+320MHz外设PLL1+200MHz外设PLL2, fDCO = 640MHz*/
#define CLK_CFG_PER_PLL_20MHZ_320MHZ_200MHZ                                                                            \
    /*{ uint32_t PLLdivide_N, uint32_t PLLmultiple_M, uint32_t k2Initial, uint32_t k3Initial, bool InputFreq2Divide,   \
     * bool K3DivBypass }*/                                                                                            \
    {                                                                                                                  \
        (1 - 1), (32 - 1), (2 - 1), (2 - 1), false, false                                                              \
    }
#endif /*#ifndef CLK_CFG_PER_PLL_20MHZ_320MHZ_200MHZ */

/***********************外设PLL目标 PLL1 = 160MHz, PLL2 = 200MHz*******************************/
#ifndef CLK_CFG_PER_PLL_20MHZ_160MHZ_200MHZ
/* 20MHz晶振+160MHz外设PLL1+200MHz外设PLL2, fDCO = 640MHz*/
#define CLK_CFG_PER_PLL_20MHZ_160MHZ_200MHZ                                                                            \
    /*{ uint32_t PLLdivide_N, uint32_t PLLmultiple_M, uint32_t k2Initial, uint32_t k3Initial, bool InputFreq2Divide,   \
     * bool K3DivBypass }*/                                                                                            \
    {                                                                                                                  \
        (1 - 1), (32 - 1), (4 - 1), (2 - 1), false, false                                                              \
    }
#endif /*#ifndef CLK_CFG_PER_PLL_20MHZ_160MHZ_200MHZ */

/***********************晶振频率 = 40MHz ***********************************/
/***********************外设PLL目标 PLL1 = 320MHz, PLL2 = 200MHz*******************************/
#ifndef CLK_CFG_PER_PLL_40MHZ_320MHZ_200MHZ
/* 40MHz晶振+320MHz外设PLL1+200MHz外设PLL2, fDCO = 640MHz*/
#define CLK_CFG_PER_PLL_40MHZ_320MHZ_200MHZ                                                                            \
    /*{ uint32_t PLLdivide_N, uint32_t PLLmultiple_M, uint32_t k2Initial, uint32_t k3Initial, bool InputFreq2Divide,   \
     * bool K3DivBypass }*/                                                                                            \
    {                                                                                                                  \
        (1 - 1), (32 - 1), (2 - 1), (2 - 1), false, false                                                              \
    }
#endif /*#ifndef CLK_CFG_PER_PLL_40MHZ_320MHZ_200MHZ */

/***********************外设PLL目标 PLL1 = 160MHz, PLL2 = 200MHz*******************************/
#ifndef CLK_CFG_PER_PLL_40MHZ_160MHZ_200MHZ
/* 40MHz晶振+160MHz外设PLL1+200MHz外设PLL2, fDCO = 640MHz*/
#define CLK_CFG_PER_PLL_40MHZ_160MHZ_200MHZ                                                                            \
    /*{ uint32_t PLLdivide_N, uint32_t PLLmultiple_M, uint32_t k2Initial, uint32_t k3Initial, bool InputFreq2Divide,   \
     * bool K3DivBypass }*/                                                                                            \
    {                                                                                                                  \
        (1 - 1), (32 - 1), (4 - 1), (2 - 1), false, false                                                              \
    }
#endif /*#ifndef CLK_CFG_PER_PLL_40MHZ_160MHZ_200MHZ */
/******************************************************************************
 *                      PLL配置定义
 ******************************************************************************/

/* 系统PLL阶梯配置宏 */
#define CLK_CFG_SYS_PLL_STEPS_BASIC_(xtalFreq, pll0Freq) CLK_CFG_SYS_PLL_STEPS_##xtalFreq##_##pll0Freq
#define CLK_CFG_SYS_PLL_STEPS_BASIC(xtalFreq, pll0Freq)  CLK_CFG_SYS_PLL_STEPS_BASIC_(xtalFreq, pll0Freq)
#define CLK_CFG_SYS_PLL_STEPS                            CLK_CFG_SYS_PLL_STEPS_BASIC(CLK_CFG_XTAL_FREQ, CLK_CFG_SYS_PLL_FREQ)

/*系统PLL第一步配置宏 */
#define CLK_CFG_SYS_PLL_INITIAL_STEP_BASIC_(xtalFreq, pll0Freq) CLK_CFG_SYS_PLL_##xtalFreq##_##pll0Freq
#define CLK_CFG_SYS_PLL_INITIAL_STEP_BASIC(xtalFreq, pll0Freq)  CLK_CFG_SYS_PLL_INITIAL_STEP_BASIC_(xtalFreq, pll0Freq)
#define CLK_CFG_SYS_PLL_INITIAL_STEP                            CLK_CFG_SYS_PLL_INITIAL_STEP_BASIC(CLK_CFG_XTAL_FREQ, CLK_CFG_SYS_PLL_FREQ)

/*外设PLL第一步配置宏 */
#define CLK_CFG_PER_PLL_INITIAL_STEP_BASIC_(xtalFreq, pll1Freq, pll2Freq)                                              \
    CLK_CFG_PER_PLL_##xtalFreq##_##pll1Freq##_##pll2Freq
#define CLK_CFG_PER_PLL_INITIAL_STEP_BASIC(xtalFreq, pll1Freq, pll2Freq)                                               \
    CLK_CFG_PER_PLL_INITIAL_STEP_BASIC_(xtalFreq, pll1Freq, pll2Freq)
#define CLK_CFG_PER_PLL_INITIAL_STEP                                                                                   \
    CLK_CFG_PER_PLL_INITIAL_STEP_BASIC(CLK_CFG_XTAL_FREQ, CLK_CFG_PER_PLL1_FREQ, CLK_CFG_PER_PLL2_FREQ)

/*等待时间第一步配置宏 */
#define CLK_CFG_WAIT_INITIAL_STEP_BASIC_(xtalFreq, pll0Freq) CLK_CFG_WAIT_INITIAL_STEP_##xtalFreq##_##pll0Freq
#define CLK_CFG_WAIT_INITIAL_STEP_BASIC(xtalFreq, pll0Freq)  CLK_CFG_WAIT_INITIAL_STEP_BASIC_(xtalFreq, pll0Freq)
#define CLK_CFG_WAIT_INITIAL_STEP                            CLK_CFG_WAIT_INITIAL_STEP_BASIC(CLK_CFG_XTAL_FREQ, CLK_CFG_SYS_PLL_FREQ)

#define CLK_CFG_PLL_INITIAL_STEP                                                                                       \
    {                                                                                                                  \
        {                                                                                                              \
          CLK_XTAL_FREQUENCY,                                                                                          \
          CLK_PLL_CLOCK_SOURCE_SELECT,                                                                                 \
          CLK_CFG_SYS_PLL_INITIAL_STEP,                                                                                \
          CLK_CFG_PER_PLL_INITIAL_STEP,                                                                                \
        },                                                                                                             \
          CLK_CFG_WAIT_INITIAL_STEP                                                                                    \
    }

/* 等待时间 */
/* TODO:手册要求1ms以上等待时间，具体参数待定 */
#define CLK_SYSPLLSTAT_PWDSTAT_TIMEOUT_COUNT (0x1F000U)
/* TODO:手册未要求等待时间，使用竞品值144us，具体参数待定 */
#define CLK_PLL_KRDY_TIMEOUT_COUNT (0x6000U)
/* TODO: 手册未要求等待时间，使用竞品值3ms，具体参数待定*/
#define CLK_PLL_LOW_OR_HIGH_TIMEOUT_COUNT (0x493E0U)
/* TODO: 手册未要求等待时间，使用竞品值122us，具体参数待定*/
#define CLK_PLL_LOCK_TIMEOUT_COUNT (0x3000U)
/* TODO: 手册未要求等待时间，使用竞品值40us，具体参数待定*/
#define CLK_DOMAIN_LCK_BIT_TIMEOUT_COUNT (0x1000U)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif
#endif
/* EOF */