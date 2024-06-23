/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_pmc.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-20
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
 *  |2023-12-27  |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_REG_PMC_H_
#define _KF32DA13K_REG_PMC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *         Include Files
 **************************************************************************/
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

/**************************************************************************
 *         Mcro ro typedef
 **************************************************************************/
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV    :8;  /*!< [7:0] 该位显示PMS模块的版本号  */
            __I uint32_t MODTYPE   :8;  /*!< [15:8] 该位显示PMS模块类型  */
            __I uint32_t MODNUMBER :16; /*!< [31:16] 该位显示PMS模块ID  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN0  :1; /*!< [0:0] 主机TAGID0访问使能  */
            __IO uint32_t EN1  :1; /*!< [1:1] 主机TAGID1访问使能  */
            __IO uint32_t EN2  :1; /*!< [2:2] 主机TAGID2访问使能  */
            __IO uint32_t EN3  :1; /*!< [3:3] 主机TAGID3访问使能  */
            __IO uint32_t EN4  :1; /*!< [4:4] 主机TAGID4访问使能  */
            __IO uint32_t EN5  :1; /*!< [5:5] 主机TAGID5访问使能  */
            __IO uint32_t EN6  :1; /*!< [6:6] 主机TAGID6访问使能  */
            __IO uint32_t EN7  :1; /*!< [7:7] 主机TAGID7访问使能  */
            __IO uint32_t EN8  :1; /*!< [8:8] 主机TAGID8访问使能  */
            __IO uint32_t EN9  :1; /*!< [9:9] 主机TAGID9访问使能  */
            __IO uint32_t EN10 :1; /*!< [10:10] 主机TAGID10访问使能  */
            __IO uint32_t EN11 :1; /*!< [11:11] 主机TAGID11访问使能  */
            __IO uint32_t EN12 :1; /*!< [12:12] 主机TAGID12访问使能  */
            __IO uint32_t EN13 :1; /*!< [13:13] 主机TAGID13访问使能  */
            __IO uint32_t EN14 :1; /*!< [14:14] 主机TAGID14访问使能  */
            __IO uint32_t EN15 :1; /*!< [15:15] 主机TAGID15访问使能  */
            __IO uint32_t EN16 :1; /*!< [16:16] 主机TAGID16访问使能  */
            __IO uint32_t EN17 :1; /*!< [17:17] 主机TAGID17访问使能  */
            __IO uint32_t EN18 :1; /*!< [18:18] 主机TAGID18访问使能  */
            __IO uint32_t EN19 :1; /*!< [19:19] 主机TAGID19访问使能  */
            __IO uint32_t EN20 :1; /*!< [20:20] 主机TAGID20访问使能  */
            __IO uint32_t EN21 :1; /*!< [21:21] 主机TAGID21访问使能  */
            __IO uint32_t EN22 :1; /*!< [22:22] 主机TAGID22访问使能  */
            __IO uint32_t EN23 :1; /*!< [23:23] 主机TAGID23访问使能  */
            __IO uint32_t EN24 :1; /*!< [24:24] 主机TAGID24访问使能  */
            __IO uint32_t EN25 :1; /*!< [25:25] 主机TAGID25访问使能  */
            __IO uint32_t EN26 :1; /*!< [26:26] 主机TAGID26访问使能  */
            __IO uint32_t EN27 :1; /*!< [27:27] 主机TAGID27访问使能  */
            __IO uint32_t EN28 :1; /*!< [28:28] 主机TAGID28访问使能  */
            __IO uint32_t EN29 :1; /*!< [29:29] 主机TAGID29访问使能  */
            __IO uint32_t EN30 :1; /*!< [30:30] 主机TAGID30访问使能  */
            __IO uint32_t EN31 :1; /*!< [31:31] 主机TAGID31访问使能  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0:32; /*!< [31:0] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t DCDC11     :1; /*!< [0:0] DCDC11稳压器状态位 */
            __I uint32_t OV11       :1; /*!< [1:1]  VDD11电压溢出标志 */
            __I uint32_t LDO33      :1; /*!< [2:2] LDO33稳压器状态位  */
            __I uint32_t OV33       :1; /*!< [3:3] VDD33电压溢出标志 */
            __I uint32_t OVPWR      :1; /*!< [4:4] VCC电压溢出标志 */
            __I uint32_t UV11       :1; /*!< [5:5] VDD11电压下溢标志 */
            __I uint32_t UV33       :1; /*!< [6:6] VDD33电压下溢标志 */
            __I uint32_t UVPWR      :1; /*!< [7:7] VCC电压下溢标志 */
            __I          uint32_t   RESERVED0:1; /*!< [8:8] 保留位  */
            __I uint32_t LDO33VOK   :1; /*!< [9:9] LDO33稳压器电压OK状态位 */
            __I          uint32_t   RESERVED1:3; /*!< [12:10] 保留位  */
            __I uint32_t RST11      :1; /*!< [13:13] DCDC11复位触发器  */
            __I uint32_t RST33      :1; /*!< [14:14] LDO33复位触发器  */
            __I uint32_t RSTPWR     :1; /*!< [15:15] PWR复位触发器  */
            __I uint32_t DCDC11SHLV :1; /*!< [16:16] 对地短:如果检测到对地短，则设置该位 */
            __I uint32_t DCDC11SHHV :1; /*!< [17:17] 电源短:如果检测到电源短情况，则设置该位 */
            __I uint32_t LDO33SHLV  :1; /*!< [18:18] 对地短如果检测到对地短，则设置该位 */
            __I uint32_t LDO33SHHV  :1; /*!< [19:19] 电源短如果检测到电源短情况，则设置该位 */
            __I uint32_t PWRLVL     :1; /*!< [20:20] VCC外部电源电平状态 */
            __I uint32_t SDVOK      :1; /*!< [21:21] DCDC11稳压器电压正常状态该位 */
            __I uint32_t DCDC11MOD  :2; /*!< [23:22] 该位指示LCPWM、LPM、STRT的当前操作模式  */
            __I uint32_t OV11BKP    :1; /*!< [24:24] 预稳压器VDD11BKP过压事件标志 */
            __I uint32_t OVDDBKP    :1; /*!< [25:25] 备用电源或VDDBKP过压事件标志 */
            __I uint32_t OVDDA      :1; /*!< [26:26] ADCVDDA电源过压事件标志 */
            __I uint32_t UV11BKP    :1; /*!< [27:27] 预稳压器VDD11BKP欠压事件标志 */
            __I uint32_t UVDDBKP    :1; /*!< [28:28] 备用电源或VDDBKP欠压事件标志 */
            __I uint32_t UVDDA      :1; /*!< [29:29] ADCVDDA电源欠压事件标志 */
            __I          uint32_t   RESERVED2:2; /*!< [31:30] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ADCP11V  :8; /*!< [7:0] ADCVDD11内核电压转换结果 */
            __I uint32_t ADCP33V  :8; /*!< [15:8] ADCVDD33电压转换结果 */
            __I uint32_t ADCPPWRV :8; /*!< [23:16] ADCVCC电源转换结果 */
            __I uint32_t OV11     :1; /*!< [24:24] 主监控器识别出过压事件，则设置该位 */
            __I uint32_t OV33     :1; /*!< [25:25] LDO33稳压器或VDD33过压事件标志 */
            __I uint32_t OVPWR    :1; /*!< [26:26] 电源看门狗或VCC过压事件标志 */
            __I uint32_t UV11     :1; /*!< [27:27] DCDC11稳压器或VDD11欠压事件标志 */
            __I uint32_t UV33     :1; /*!< [28:28] LDO33稳压器或VDD33欠压事件标志 */
            __I uint32_t UVPWR    :1; /*!< [29:29] 电源看门狗(SWD)或VCC欠压事件标志 */
            __I          uint32_t RESERVED0:2; /*!< [31:30] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_PMONSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST11CAL   :8; /*!< [7:0] VDD11电源复位调整值 */
            __IO uint32_t RST33CAL   :8; /*!< [15:8] VDD33电源复位调整值 */
            __IO uint32_t RSTPWRCAL  :8; /*!< [23:16] VCC电源复位调整值 */
            __IO uint32_t RST11DIS   :1; /*!< [24:24] VDD11复位使能  */
            __O uint32_t  WRST11DIS  :1; /*!< [25:25] 该位保护RST11DIS */
            __IO uint32_t RST33DIS   :1; /*!< [26:26] VDD33复位使能 */
            __O uint32_t  WRST33DIS  :1; /*!< [27:27] 此位保护RST33DIS: */
            __IO uint32_t RSTPWRDIS  :1; /*!< [28:28] VCC复位使能 */
            __O uint32_t  WRSTPWRDIS :1; /*!< [29:29] 该位保护RSTPWRDIS */
            __IO uint32_t SLCK       :1; /*!< [30:30] HSM安全锁 */
            __I           uint32_t   RESERVED0:1; /*!< [31:31] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_RSTCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RST11     :8; /*!< [7:0] VDD11电源复位值状态 */
            __I uint32_t RST33     :8; /*!< [15:8] VDD33电源复位值状态 */
            __I uint32_t RSTPWR    :8; /*!< [23:16] VCC电源复位值状态 */
            __I uint32_t RST11DIS  :1; /*!< [24:24] DCDC11复位使能状态 */
            __I          uint32_t  RESERVED0:1; /*!< [25:25] 保留位  */
            __I uint32_t RST33DIS  :1; /*!< [26:26] LDO33复位启用状态 */
            __I          uint32_t  RESERVED1:1; /*!< [27:27] 保留位  */
            __I uint32_t RSTPWRDIS :1; /*!< [28:28] PWR复位使能:该值通过PMC_RSTCTL.RSTSWDOFF寄存器位新  */
            __I          uint32_t  RESERVED2:3; /*!< [31:29] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_RSTSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LDO33VOUT :8; /*!< [7:0] 电压目标值LDO33LDO稳压器的VDD33输出电平 */
            __IO uint32_t DCDC11VOUT :8; /*!< [15:8] DCDC11稳压器输出电压目标值降压稳压器的VDD11输出电平 */
            __IO uint32_t LDO33VCAL  :6; /*!< [21:16] LDO33稳压器输出电压微调值  */
            __I           uint32_t   RESERVED0:2; /*!< [23:22] 保留位  */
            __IO uint32_t DCDC11VCAL :6; /*!< [29:24] DCDC11稳压器输出电压调整值(vtrim_trim_i) */
            __IO uint32_t SLCK       :1; /*!< [30:30] HSM安全锁 */
            __IO uint32_t LCK        :1; /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_CALCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t LDO33VOUT  :8; /*!< [7:0] 电压目标值 */
            __I uint32_t DCDC11VOUT :8; /*!< [15:8] DCDC11稳压器输出电压目标值 */
            __I uint32_t LDO33VCAL  :6; /*!< [21:16] LDO33稳压器输出电压微调值  */
            __I          uint32_t   RESERVED0:2; /*!< [23:22] 保留位  */
            __I uint32_t DCDC11VCAL :6; /*!< [29:24] DCDC11稳压器输出电压调整值 */
            __I          uint32_t   RESERVED1:2; /*!< [31:30] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_CALSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ADCS11   :8; /*!< [7:0] ADC转换结果 */
            __I uint32_t ADCS33   :8; /*!< [15:8] VDD33电源次级ADC转换结果  */
            __I uint32_t ADCSPWR  :8; /*!< [23:16] VCC次级ADC转换结果 */
            __I uint32_t ACTCNT   :6; /*!< [29:24] 次级监视器活动计数器 */
            __I          uint32_t RESERVED0:2; /*!< [31:30] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SMONSTA1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ADC11BKP  :8; /*!< [7:0] VDD11BKP电源次级ADC转换结果 */
            __I uint32_t ADCVDDBKP :8; /*!< [15:8] VDDBKP电源次级ADC转换结果 */
            __I uint32_t ADCVDDA   :8; /*!< [23:16] VDDA电源次级ADC转换结果 */
            __I          uint32_t  RESERVED0:8; /*!< [31:24] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SMONSTAT2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DCDC11OMOD   :2; /*!< [1:0]VDD11过压监控模式  */
            __IO uint32_t LDO11BKPOMOD :2; /*!< [3:2] LDO11BKP或VDD11BKP过压监控模式 */
            __IO uint32_t DCDC11UMOD   :2; /*!< [5:4] VDD11欠压监控模式  */
            __IO uint32_t LDO11BKPUMOD :2; /*!< [7:6] LDO11BKP或VDD11BKP欠压监控模式  */
            __IO uint32_t LDO33OMOD    :2; /*!< [9:8] VDD33电源过压监控模式  */
            __IO uint32_t VDDAOMOD     :2; /*!< [11:10] VDDAADC电源过压监控模式 */
            __IO uint32_t LDO33UMOD    :2; /*!< [13:12] VDD33电源欠压监控模式 */
            __IO uint32_t VDDAUVMOD    :2; /*!< [15:14] VDDAADC电源欠压监控模式 */
            __IO uint32_t PWROMOD      :2; /*!< [17:16] VCC过压监测模式*/
            __IO uint32_t VDDBKPOMOD   :2; /*!< [19:18] EVR备用电源或VDDBKP过压监控模式  */
            __IO uint32_t PWRUMOD      :2; /*!< [21:20] VCC欠压监测模式 */
            __IO uint32_t VDDBKPUMOD   :2; /*!< [23:22] EVR备用电源或VDDBKP欠压监控模式 */
            __I           uint32_t     RESERVED0:6; /*!< [29:24] 保留位  */
            __IO uint32_t SLCK         :1; /*!< [30:30] HSM安全锁  */
            __I           uint32_t     RESERVED1:1; /*!< [31:31] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SMONCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DCDC11FIL   :4; /*!< [3:0] VDD11次级ADC电源滤波器  */
            __IO uint32_t VDD11BKPFIL :4; /*!< [7:4] VDD11BKP次级ADC电源滤波器  */
            __IO uint32_t LDO33FIL    :4; /*!< [11:8] VDD33次级ADC电源滤波器  */
            __IO uint32_t VDDAFIL     :4; /*!< [15:12] VDDA次级ADC电源滤波器  */
            __IO uint32_t PWRFIL      :4; /*!< [19:16] VCC次级ADC电源滤波器  */
            __IO uint32_t VDDBKPFIL   :4; /*!< [23:20] VDDBKP次级ADC电源滤波器  */
            __I           uint32_t    RESERVED0:5; /*!< [28:24] 保留位  */
            __IO uint32_t CLRFIL      :1; /*!< [29:29] 清除所有尖峰滤波器     */
            __IO uint32_t SLCK        :1; /*!< [30:30] HSM安全锁  */
            __I           uint32_t    RESERVED1:1; /*!< [31:31] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SMONFIL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OVPWR :1; /*!< [0:0] OVPWD中断在PMC_MONCTL寄存器中配置的事件触发  */
            __IO uint32_t UVPWR :1; /*!< [1:1] UVPWD中断启用中断触发事件,如PMC_MONCTL寄存器中配置  */
            __IO uint32_t OV33  :1; /*!< [2:2] OV33中断启用中断触发事件,如PMC_MONCTL寄存器中配置  */
            __IO uint32_t UV33  :1; /*!< [3:3] UV33中断启用中断触发事件,如PMC_MONCTL寄存器中配置  */
            __IO uint32_t OV11  :1; /*!< [4:4] OV11中断启用中断触发事件,如PMC_MONCTL寄存器中配置  */
            __IO uint32_t UV11  :1; /*!< [5:5] UV11中断启用中断触发事件,如PMC_MONCTL寄存器中配置  */
            __IO uint32_t OLDO11BKP :1; /*!< [6:6] OLDO11BKP中断启用中断触发事件,如PMC_MONCTL寄存器中配置  */
            __IO uint32_t ULDO11BKP :1; /*!< [7:7] ULDO11BKP中断启用中断触发事件,如PMC_MONCTL寄存器中配置  */
            __IO uint32_t OVDDA :1; /*!< [8:8] OVDDA中断启用中断触发事件如,PMC_MONCTL寄存器中配置  */
            __IO uint32_t UVDDA :1; /*!< [9:9] UVDDA中断启用中断触发事件,如PMC_MONCTL寄存器中配置  */
            __IO uint32_t OVDDBKP :1; /*!< [10:10] OVDDBKP中断启用中断触发事件,如PMC_MONCTL寄存器中配置  */
            __IO uint32_t UVDDBKP :1; /*!< [11:11] UVDDBKP中断启用中断触发事件,如PMC_MONCTL寄存器中配置  */
            __I           uint32_t  RESERVED0:4; /*!< [15:12] 保留位  */
            __IO uint32_t DCDC11MOD :1; /*!< [16:16] DCDC11MOD中断启用  */
            __IO uint32_t SDVOK   :1; /*!< [17:17] SDVOK中断启用:在PMC_PSTA.SDVOK上升沿事件上触发中断  */
            __IO uint32_t SYNCLCK :1; /*!< [18:18] SDSYNCLCK中断启用 */
            __IO uint32_t PWRLVL  :1; /*!< [19:19] PWRLVL中断启用  */
            __I           uint32_t RESERVED1:1; /*!< [20:20] 保留位  */
            __IO uint32_t WUTWKP   :1; /*!< [21:21] WUTWKP中断启用:在WUTCNT下溢事件上触发的中断  */
            __IO uint32_t ESR0WKP  :1; /*!< [22:22] ESR0WKP中断使能:中断在ESR0WKP事件上触发  */
            __IO uint32_t ESR1WKP  :1; /*!< [23:23] ESR1WKP中断启用:在ESR1WKP事件上触发中断  */
            __IO uint32_t PINAWKP  :1; /*!< [24:24] PINAWKP中断启用:在PINAWKP事件上触发的中断  */
            __IO uint32_t PINBWKP  :1; /*!< [25:25] PINBWKP中断启用:在PINBWKP事件上触发的中断  */
            __I           uint32_t RESERVED2:6; /*!< [31:26] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DCDC11UVAL :8; /*!< [7:0] VDD11电源次级监视器欠压阈值 */
            __IO uint32_t LDO33UVAL  :8; /*!< [15:8] VDD33电源次级监视器欠压阈值 */
            __IO uint32_t PWRUVAL    :8; /*!< [23:16] VCC电源次级监控器欠压阈值 */
            __I           uint32_t   RESERVED0:6; /*!< [29:24] 保留位  */
            __IO uint32_t SLCK       :1; /*!< [30:30]  HSM安全锁 */
            __I           uint32_t   RESERVED1:1; /*!< [31:31]  保留位 */

        } bits;
        __IO uint32_t reg;
    };
} PMC_UVMON0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DCDC11OVAL :8; /*!< [7:0] VDD11电源次级监视器上溢电压阈值  */
            __IO uint32_t LDO33OVAL  :8; /*!< [15:8] VDD33电源次级监视器上溢电压阈值 */
            __IO uint32_t PWROVAL    :8; /*!< [23:16] VCC电源次级监视器上溢电压阈值 */
            __I           uint32_t   RESERVED0:6; /*!< [29:24] 保留位  */
            __IO uint32_t SLCK       :1; /*!< [30:30] HSM安全锁  */
            __I           uint32_t   RESERVED1:1; /*!< [31:31] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_OVMON0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t VDD11BKPUVAL :8; /*!< [7:0] VDD11BKP电源次级监控欠压阈值 */
            __IO uint32_t VDDAUVAL     :8; /*!< [15:8] VDDA电源次级监控欠压阈值 */
            __IO uint32_t VDDBKPUVAL   :8; /*!< [23:16] VDDBKP电源次级监视器欠压阈值 */
            __IO uint32_t VDDAVSEL     :6; /*!< [29:24] VDDA电平选择 */
            __IO uint32_t SLCK         :1; /*!< [30:30] HSM安全锁 */
            __I           uint32_t     RESERVED0:1; /*!< [31:31] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_UVMON1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t VDD11BKPOVAL :8; /*!< [7:0] VDD11BKP电源次级监控器过压阈值 */
            __IO uint32_t VDDAOVAL     :8; /*!< [15:8] VDDA电源次级监控器过压阈值 */
            __IO uint32_t VDDBKPOVAL   :8; /*!< [23:16] VDDBKP电源次级监视器过压阈值 */
            __I           uint32_t     RESERVED0:6; /*!< [29:24] 保留位  */
            __IO uint32_t SLCK         :1; /*!< [30:30] HSM安全锁 */
            __I           uint32_t     RESERVED1:1; /*!< [31:31] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_OVMON1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DCDC11UVAL :8; /*!< [7:0] VDD11电源主监视器警报欠压阈值 */
            __IO uint32_t LDO33UVAL  :8; /*!< [15:8] VDD33电源主监视器警报欠压阈值 */
            __IO uint32_t PWRUVAL    :8; /*!< [23:16] VCC电源主监视器警报欠压阈值 */
            __IO uint32_t DCDC11DIS  :1; /*!< [24:24] VDD主监控器UV警报警用  */
            __IO uint32_t LDO33DIS   :1; /*!< [25:25] VDD33主监控器UV警报警用  */
            __IO uint32_t PWRDIS     :1; /*!< [26:26] VCC主监视器UV警报禁用  */
            __IO uint32_t HSMFIL     :4; /*!< [30:27] HSM电压滤波器  */
            __IO uint32_t SLCK       :1; /*!< [31:31] HSM安全锁  */
        } bits;
        __IO uint32_t reg;
    };
} HSM_UVMON_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DCDC11OVAL :8; /*!< [7:0] VDD11电源主监控器上溢警报电压阈值 */
            __IO uint32_t LDO33OVAL  :8; /*!< [15:8] VDD33电源主监控器上溢警报电压阈值 */
            __IO uint32_t PWROVAL    :8; /*!< [23:16] VCC电源主监控器上溢警报电压阈值  */
            __IO uint32_t DCDC11DIS  :1; /*!< [24:24] VDD主监视器UV警报禁用  */
            __IO uint32_t LDO33DIS   :1; /*!< [25:25] VDD33主监视器UV警报禁用  */
            __IO uint32_t PWRDIS     :1; /*!< [26:26] VCC主监视器OV警报禁用  */
            __IO          uint32_t   RESERVED0:4; /*!< [30:27] 保留位  */
            __IO uint32_t SLCK       :1; /*!< [31:31] HSM安全锁 */
        } bits;
        __IO uint32_t reg;
    };
} HSM_OVMON_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SHVH33   :8; /*!< [7:0]  短至电源电压阈值*/
            __IO          uint32_t RESERVED0:4; /*!< [11:8] 保留位，必须被写入原始值  */
            __IO uint32_t SHHVEN   :1; /*!< [12:12] 对高短检测启用  */
            __IO uint32_t SHLVEN   :1; /*!< [13:13] 对低短检测启用  */
            __IO          uint32_t RESERVED1:2; /*!< [15:14] 保留位，必须被写入原始值  */
            __IO uint32_t SHVL33   :8; /*!< [23:16] 对地短电压阈值 */
            __IO          uint32_t RESERVED2:5; /*!< [28:24] 保留位，必须被写入原始值  */
            __O uint32_t  RES      :1; /*!< [29:29] 读该位为0，该位必须写0  */
            __IO uint32_t SLCK     :1; /*!< [30:30] HSM安全锁 */
            __I           uint32_t RESERVED3:1; /*!< [31:31] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_LDO33CTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OSCFCAL     :6;  /*!< [5:0] 备用时钟微调值 */
            __I           uint32_t    RESERVED0:10; /*!< [15:6] 保留位  */
            __IO uint32_t OSCFPCAL    :6;  /*!< [21:16] OSC微调带符号值 */
            __I           uint32_t    RESERVED1:7;  /*!< [28:22] 保留位  */
            __IO uint32_t OSCTEMPOFFS :1;  /*!< [29:29] 荡器温度偏移系数 */
            __I           uint32_t    RESERVED2:1;  /*!< [30:30] 保留位  */
            __IO uint32_t OSCCALEN    :1;  /*!< [31:31] 动态振荡器微调启用 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_OSCCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ADCFBCV  :8;  /*!< [7:0] 降压转换器内核电压反馈ADC转换结果 */
            __I          uint32_t RESERVED0:8;  /*!< [15:8] 保留位  */
            __I uint32_t DPWMOUT  :12; /*!< [27:16] DPWM控制输出状态 */
            __I          uint32_t RESERVED1:4;  /*!< [31:28] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDSTA0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SDFREQSPRD :16; /*!< [15:0] 频率扩展阈值 */
            __IO uint32_t SDFREQ     :12; /*!< [27:16] 稳压器开关频率或过采样因子 */
            __IO uint32_t NGOFF      :1;  /*!< [28:28] SMPS开关频率NMOS关断状态期间的电平 */
            __IO uint32_t PGOFF      :1;  /*!< [29:29] OFF状态下的PMOS电平 */
            __IO uint32_t UP         :1;  /*!< [30:30] SMPS寄存器值 */
            __I uint32_t  LCK        :1;  /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M0TDIS   :8; /*!< [7:0] 最小关断时间 */
            __IO uint32_t M0TON    :8; /*!< [15:8] 最小开启时间 */
            __IO uint32_t M0S0FCT  :4; /*!< [19:16] S0系数  */
            __IO uint32_t M0DEADBD :2; /*!< [21:20] 死区  */
            __IO uint32_t M0ADCZB  :2; /*!< [23:22] ADCZeroBin  */
            __IO uint32_t M0SKIP   :4; /*!< [27:24] 跳跃脉冲阈值 */
            __I           uint32_t RESERVED0:3; /*!< [30:28] 保留位 */
            __I uint32_t  LCK      :1; /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I           uint32_t    RESERVED0:2;  /*!< [1:0] 保留位  */
            __IO uint32_t LPBNDOFFSET :2;  /*!< [3:2] 低功耗模式迟滞OFFSET  */
            __IO uint32_t LPBNDWIDTH  :4;  /*!< [7:4] 低功耗模式迟滞带宽  */
            __IO uint32_t LPLPFFCT    :4;  /*!< [11:8] 低通滤波器系数 */
            __I           uint32_t    RESERVED1:4;  /*!< [15:12] 保留位  */
            __IO uint32_t SDFREQLP    :12; /*!< [27:16] 稳压器过采样因子 */
            __I           uint32_t    RESERVED2:2;  /*!< [29:28] 保留位 */
            __IO uint32_t DCDC11MOD   :1;  /*!< [30:30] LPM或PWMDCDC11模式激活 */
            __I uint32_t  LCK         :1;  /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M1TOFF   :8; /*!< [7:0] 最小关断时间 */
            __IO uint32_t M1TON    :8; /*!< [15:8] 最小时间 */
            __IO uint32_t M1S0FCT  :4; /*!< [19:16] S0系数  */
            __IO uint32_t M1DEADBD :2; /*!< [21:20] 死区  */
            __IO uint32_t M1ADCZB  :2; /*!< [23:22] ADCZeroBin  */
            __IO uint32_t M1SKIP   :4; /*!< [27:24] 跃脉冲阈值 */
            __I           uint32_t RESERVED0:4; /*!< [31:28] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t VOKCFG   :6;  /*!< [5:0] 电压正常电配置  */
            __I           uint32_t RESERVED0:10; /*!< [15:6] 保留位  */
            __IO uint32_t SDFREQST :12; /*!< [27:16] 稳压器开关频率或过采样因子 */
            __I           uint32_t RESERVED1:4;  /*!< [31:28] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL4_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M2TOFF   :8; /*!< [7:0] 最小关断时间 */
            __IO uint32_t M2TON    :8; /*!< [15:8] 最小时间 */
            __IO uint32_t M2S0FCT  :4; /*!< [19:16] S0系数  */
            __IO uint32_t M2DEADBD :2; /*!< [21:20] 死区  */
            __IO uint32_t M2ADCZB  :2; /*!< [23:22] ADCZeroBin  */
            __IO uint32_t M2SKIP   :4; /*!< [27:24] 跳跃脉冲阈值  */
            __I           uint32_t RESERVED0:4; /*!< [31:28] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL5_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SVINTH   :8; /*!< [7:0] 在SINCLO或SINCHI之间切换的Vin阈值 */
            __IO uint32_t SVOTH    :8; /*!< [15:8] 从开环启动切换到闭环模式的Vout阈值 */
            __IO uint32_t SINCLO   :3; /*!< [18:16] 低输入电压的增 */
            __I           uint32_t RESERVED0:1; /*!< [19:19] 保留位  */
            __IO uint32_t SINCHI :3; /*!< [22:20] 该位域指定启动期间开环斜坡上升期间的导通时间  */
            __I           uint32_t RESERVED1:8; /*!< [30:23] 保留位  */
            __I uint32_t  LCK      :1; /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL6_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DRVNI      :2; /*!< [1:0] N驱动电流的选择  */
            __IO uint32_t DRVPCBF    :2; /*!< [3:2] P驱动器电流升压因子  */
            __IO uint32_t DRVP       :4; /*!< [7:4]  P驱动器电流 */
            __IO uint32_t DRVSLOMODE :2; /*!< [9:8] 开关配置:该位域配置开关类型  */
            __I           uint32_t   RESERVED0:6; /*!< [15:10] 保留位  */
            __IO uint32_t DRVSPR     :8; /*!< [23:16] 备用位  */
            __IO uint32_t SYNCDIVFAC :3; /*!< [26:24] 外同步开关分频系数 */
            __I           uint32_t   RESERVED1:4; /*!< [30:27] 保留位  */
            __I uint32_t  LCK        :1; /*!< [31:31] 锁定状态  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL7_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FBADCOFFS :8; /*!< [7:0] 反馈转换计数器值偏移 */
            __IO uint32_t FBADCSMP  :6; /*!< [13:8] FBADC采样周期 */
            __I           uint32_t  RESERVED0:2; /*!< [15:14] 保留位  */
            __IO uint32_t FBADCBLNK :2; /*!< [17:16] FBADC消隐样本数 */
            __I           uint32_t  RESERVED1:2; /*!< [19:18] 保留位  */
            __IO uint32_t FBADCLPF  :2; /*!< [21:20] FBADC计数器LPF系数    */
            __I           uint32_t  RESERVED2:2; /*!< [23:22] 保留位  */
            __IO uint32_t FBADCERR  :2; /*!< [25:24] FBADC误差LPF系数 */
            __I           uint32_t  RESERVED3:2; /*!< [27:26] 保留位  */
            __IO uint32_t FBADCLSB  :1; /*!< [28:28] 用于误差计算的FBADCLSB */
            __I           uint32_t  RESERVED4:2; /*!< [30:29] 保留位  */
            __I uint32_t  LCK       :1; /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL8_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FFADCOFFS :8;  /*!< [7:0] 前馈转换计数器值偏移 */
            __IO uint32_t FFADCLPF  :3;  /*!< [10:8] FFADC计数器LPF系数  */
            __I           uint32_t  RESERVED0:20; /*!< [30:11] 保留位  */
            __I uint32_t  LCK       :1;  /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL9_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SHVH     :8;  /*!< [7:0] 短到高压阈值 */
            __IO uint32_t SHVL     :8;  /*!< [15:8] 短至低压阈值 */
            __I           uint32_t RESERVED0:12; /*!< [27:16] 保留位  */
            __IO uint32_t SHHVEN   :1;  /*!< [28:28] 短到高检测启用(shrth0_shhven_i)  */
            __IO uint32_t SHLVEN   :1;  /*!< [29:29] 低电平短检测启用(shrtl0_shlven_i)  */
            __I           uint32_t RESERVED1:2;  /*!< [31:30] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL10_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DROOPVH    :5; /*!< [4:0] Droop请求的高VDD限制 */
            __I           uint32_t   RESERVED0:3; /*!< [7:5] 保留位  */
            __IO uint32_t DROOPVL    :5; /*!< [12:8] Droop请求的低VDD限制(droopvl_thres_i) */
            __I           uint32_t   RESERVED1:3; /*!< [15:13] 保留位  */
            __IO uint32_t SYNCMAXDEV :5; /*!< [20:16] 同步输入频率的最大偏差(synci1_maxdev_i) */
            __I           uint32_t   RESERVED2:3; /*!< [23:21] 保留位  */
            __IO uint32_t SYNCHYST   :3; /*!< [26:24] 锁定解锁迟滞窗口(synci0_hyst_i */
            __I           uint32_t   RESERVED3:1; /*!< [27:27] 保留位  */
            __IO uint32_t SYNCMUXSEL :2; /*!< [29:28] 同步输入多复用器 */
            __I           uint32_t   RESERVED4:1; /*!< [30:30] 保留位  */
            __I uint32_t  LCK        :1; /*!< [31:31] 锁定状态
                                          */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDCTL11_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M0S0EN   :1; /*!< [0:0] S0启用:该位域启用快进错误项  */
            __IO uint32_t M0S2EN   :1; /*!< [1:1] S2启用:该位域支持电感电流的数字重构  */
            __IO uint32_t M0S3EN   :1; /*!< [2:2] S3启用:该位域启用积分器  */
            __IO uint32_t M0S3CLIP :1; /*!< [3:3] 该位域指定将积分器状态裁剪为负值  */
            __IO uint32_t M0S4EN   :1; /*!< [4:4] S4启用:该位域启用双积分器分支  */
            __IO uint32_t M0RAMPEN :1; /*!< [5:5] 斜坡启用:该位域启用人工斜坡以避免高占空比时的稳定  */
            __IO uint32_t M0SFRGET :1; /*!< [6:6] SFRGET:该位域可以在电感电流重构时启用补偿寄生效应  */
            __IO uint32_t M0SKIPEN  :1; /*!< [7:7] 跳跃启用:该位域启用跳跃脉冲逻辑  */
            __IO uint32_t M0S3FCT   :4; /*!< [11:8] S3系数:S3的配置寄存器-积分器系数  */
            __IO uint32_t M0S4FCT   :4; /*!< [15:12] S4系数:S4的配置寄存器-双积分器系数  */
            __IO uint32_t M0SRMPFCT :4; /*!< [19:16] S斜坡系数:SRamp的配置寄存器-人工斜坡系数  */
            __IO uint32_t M0FGETFCT :4; /*!< [23:20] S2遗忘因子:该位域指定用于补偿寄生效应的遗忘因子  */
            __IO uint32_t M0S2FCT :4; /*!< [27:24] S2系数:电感电流重构系数  */
            __IO uint32_t M0S2VINSRC :1; /*!< [28:28] S2输入电压源:该位域指定用于电感电流重构的输入电压源  */
            __IO uint32_t M0S2VOSRC :1; /*!< [29:29] S2VoutSource:该位域指定用于电感电流重构的输出电压源  */
            __IO uint32_t M0SRMPFCTFRAC :1; /*!< [30:30] S斜坡小数系数:该位字段指定S斜坡小数系数  */
            __I uint32_t  LCK           :1; /*!< [31:31] 锁定状态  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDFCT0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M0VOCFLPF   :4;  /*!< [3:0] LPF系数 */
            __IO uint32_t M0VOCFINC   :4;  /*!< [7:4]  输出电压斜坡系数 */
            __IO uint32_t M0VOUT      :8;  /*!< [15:8] 目标电压的数字表示  */
            __IO uint32_t M0VIN       :11; /*!< [26:16] 输入电压的数字表示 */
            __IO uint32_t M0S3FCTFRAC :2;  /*!< [28:27] S3小数系数  */
            __IO uint32_t M0S2FCTFRAC :2;  /*!< [30:29] S2小数系数  */
            __I uint32_t  LCK         :1;  /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDFCT1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M1S0EN   :1; /*!< [0:0] S0启用:该位域启用快进错误项  */
            __IO uint32_t M1S2EN   :1; /*!< [1:1] S2启用:该位域支持电感电流的数字重构  */
            __IO uint32_t M1S3EN   :1; /*!< [2:2] S3启用:该位域启用积分器  */
            __IO uint32_t M1S3CLIP :1; /*!< [3:3] S3:该位域指定将积分器状态裁剪为负值  */
            __IO uint32_t M1S4EN   :1; /*!< [4:4] S4启用:该位域启用双积分器分支  */
            __IO uint32_t M1RAMPEN :1; /*!< [5:5] 斜坡启用:该位域启用人工斜坡以避免高占空比时的稳定  */
            __IO uint32_t M1SFRGET :1; /*!< [6:6] SFRGET:该位域可以补偿电感器电流重构中的寄生效应  */
            __IO uint32_t M1SKIPEN  :1; /*!< [7:7] 跳跃启用:该位域启用跳跃脉冲逻辑  */
            __IO uint32_t M1S3FCT   :4; /*!< [11:8] S3系数:S3的配置寄存器-积分器系数  */
            __IO uint32_t M1S4FCT   :4; /*!< [15:12] S4系数:S4的配置寄存器-双积分器系数  */
            __IO uint32_t M1SRMPFCT :4; /*!< [19:16] S斜坡系数:SRamp的配置寄存器-人工斜坡系数  */
            __IO uint32_t M1FGETFCT :3; /*!< [22:20] S2遗忘因子:该位域指定用于补偿寄生效应的遗忘因子  */
            __IO uint32_t M1S2FCT    :4; /*!< [27:24] S2系数:电感电流重构系数  */
            __IO uint32_t M1S2VINSRC :1; /*!< [28:28] S2输入信号源  */
            __IO uint32_t M1S2VOSRC  :1; /*!< [29:29] 该位域指定用于电感电流重构的输出电压源  */
            __I           uint32_t   RESERVED0:2; /*!< [31:30] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDFCT2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M1VOCFLPF     :4;  /*!< [3:0] LPF系数 */
            __IO uint32_t M1VOCFINC     :4;  /*!< [7:4] 输出电压斜坡系数 */
            __IO uint32_t M1VOUT        :8;  /*!< [15:8] 目标电压的数字表示 */
            __IO uint32_t M1VIN         :11; /*!< [26:16] 输入电压的数字表示  */
            __IO uint32_t M1S3FCTFRAC   :2;  /*!< [28:27] S3小数系数:该位域指定S3小数积分器系数  */
            __IO uint32_t M1S2FCTFRAC   :2;  /*!< [30:29] S2小数系数:该位域指定S2小数积分器系数  */
            __IO uint32_t M1SRMPFCTFRAC :1;  /*!< [31:31] S斜坡小数系数:该位字段指定S斜坡小数系数  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDFCT3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M2S0EN   :1; /*!< [0:0] S0启用:该位域启用快进错误项  */
            __IO uint32_t M2S2EN   :1; /*!< [1:1] S2启用:该位域支持电感电流的数字重构  */
            __IO uint32_t M2S3EN   :1; /*!< [2:2] S3启用:该位域启用积分器  */
            __IO uint32_t M2S3CLIP :1; /*!< [3:3] S3:该位域指定将积分器状态裁剪为负值  */
            __IO uint32_t M2S4EN   :1; /*!< [4:4] S4启用:该位域启用双积分器分支  */
            __IO uint32_t M2RAMPEN :1; /*!< [5:5] 斜坡启用:该位域启用人工斜坡以避免高占空比时的稳定  */
            __IO uint32_t M2SFRGET :1; /*!< [6:6] SFRGET:该位域可以补偿电感器电流重构中的寄生效应  */
            __IO uint32_t M2SKIPEN  :1; /*!< [7:7] 跳跃启用:该位域启用跳跃脉冲逻辑  */
            __IO uint32_t M2S3FCT   :4; /*!< [11:8] S3系数:S3的配置寄存器-积分器系数  */
            __IO uint32_t M2S4FCT   :4; /*!< [15:12] S4系数:S4的配置寄存器-双积分器系数  */
            __IO uint32_t M2SRMPFCT :4; /*!< [19:16] S斜坡系数:SRamp的配置寄存器-人工斜坡系数  */
            __IO uint32_t M2FGETFCT :4; /*!< [23:20] S2遗忘因子:该位域指定用于补偿寄生效应的遗忘因子  */
            __IO uint32_t M2S2FCT    :4; /*!< [27:24] S2系数:电感电流重构系数  */
            __IO uint32_t M2S2VINSRC :1; /*!< [28:28] S2输入信号源  */
            __IO uint32_t M2S2VOSRC :1; /*!< [29:29] S2VoutSource:该位域指定用于电感电流重构的输出电压源  */
            __I uint32_t RESERVED0:2;            /*!< [31:30] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDFCT4_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t M2VOCFLPF     :4;  /*!< [3:0] LPF系数 */
            __IO uint32_t M2VOCFINC     :4;  /*!< [7:4] 输出电压斜坡系数 */
            __IO uint32_t M2VOUT        :8;  /*!< [15:8] 目标电压的数字表示  */
            __IO uint32_t M2VIN         :11; /*!< [26:16] 输入电压的数字表示 */
            __IO uint32_t M2S3FCTFRAC   :2;  /*!< [28:27] S3小数系数  */
            __IO uint32_t M2S2FCTFRAC   :2;  /*!< [30:29] S2小数系数  */
            __IO uint32_t M2SRMPFCTFRAC :1;  /*!< [31:31] S斜坡小数系数  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDFCT5_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CT5REG0 :8; /*!< [7:0] 换向微调和斜率控制(drv5v0_trim_i):调整外部驱动器(5V)的换向参数  */
            __IO uint32_t CT5REG1 :8; /*!< [15:8] 换向微调(drv5v1_trim_i):调整外部驱动器(5V)的换向参数  */
            __IO uint32_t CT5REG2 :8; /*!< [23:16] 换向微调(drv5v2_trim_i):调整外部驱动器(5V)的换向参数  */
            __I          uint32_t RESERVED0:7; /*!< [30:24] 保留位  */
            __I uint32_t LCK      :1; /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDFCT6_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CT5REG3 :8; /*!< [7:0] 换向微调(drv5v3_trim_i):调整外部驱动器(5V)的换向参数  */
            __IO uint32_t CT5REG4 :8; /*!< [15:8] 换向微调(drv5v4_trim_i):调整外部驱动器(5V)的换向参数  */
            __I          uint32_t RESERVED0:15; /*!< [30:16] 保留位  */
            __I uint32_t LCK      :1;  /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDFCT7_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CT33REG0 :8; /*!< [7:0] 换向微调(drv3v0_trim_i):调整外部驱动器(3.3V)的换向参数  */
            __IO uint32_t CT33REG1 :8; /*!< [15:8] 换向微调(drv3v1_trim_i):调整外部驱动器(3.3V)的换向参数  */
            __IO uint32_t CT33REG2 :8; /*!< [23:16] 换向微调(drv3v2_trim_i):调整外部驱动器(3.3V)的换向参数  */
            __I          uint32_t RESERVED0:7; /*!< [30:24] 保留位  */
            __I uint32_t LCK      :1; /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDFCT8_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CT33REG3 :8; /*!< [7:0] 换向微调(drv3v3_trim_i):调整外部驱动器(3.3V)的换向参数  */
            __IO uint32_t CT33REG4 :8; /*!< [15:8] 换向微调(drv3v4_trim_i):调整外部驱动器(3.3V)的换向参数  */
            __I          uint32_t RESERVED0:15; /*!< [30:16] 保留位  */
            __I uint32_t LCK      :1;  /*!< [31:31] 锁定状态 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SDFCT9_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I           uint32_t  RESERVED0:2; /*!< [1:0] 保留位  */
            __IO uint32_t VCCSTBYEN :1;
            __IO uint32_t VDDSTBYEN :1;
            __IO uint32_t ESR0DFEN  :1;
            __IO uint32_t ESR0EDCON :2; /*!< [6:5] ESR0边沿检测控制  */
            __IO uint32_t ESR1DFEN  :1; /*!< [7:7]  ESR1数字滤波器启用  */
            __IO uint32_t ESR1EDCON :2; /*!< [9:8] 边沿检测控制 */
            __IO uint32_t PINADFEN  :1; /*!< [10:10]  PINA数字滤波器启用该位激活数字尖峰滤波器。 */
            __IO uint32_t PINAEDCON :2; /*!< [12:11] PINA边沿检测控制:该位字段定义引脚A唤醒触发的边沿 */
            __IO uint32_t PINBDFEN :1; /*!< [13:13] PINB数字滤波器启用该位激活数字尖峰滤波器。 */
            __IO uint32_t PINBEDCON :2; /*!< [15:14] PINB边沿检测控制:该位字段定义引脚B唤醒触发的边沿  */
            __IO uint32_t STBYRAMSEL :3; /*!< [18:16] 待机模式下的待机RAM电源该位字段配置待机RAM块 */
            __I           uint32_t   RESERVED1:1; /*!< [19:19] 保留位  */
            __IO uint32_t BLINKFIL   :4;
            __IO uint32_t ESR0WKEN   :1;
            __IO uint32_t ESR1WKEN   :1;
            __IO uint32_t PINAWKEN   :1;
            __IO uint32_t PINBWKEN   :1;
            __IO uint32_t PWRWKEN    :1;
            __IO uint32_t PORSTWKEN  :1;
            __IO uint32_t WUTWKEN    :1;
        } bits;
        __IO uint32_t reg;
    };
} PMC_SWCTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I           uint32_t  RESERVED0:8;  /*!< [7:0] 保留位  */
            __IO uint32_t CPUIDLSEL :3;  /*!< [10:8] 空闲模式的CPU选择该位字段  */
            __I           uint32_t  RESERVED1:1;  /*!< [11:11] 保留位  */
            __IO uint32_t IRADIS    :1;  /*!< [12:12] 禁用该位使能SCU空闲请求确认序列 */
            __I           uint32_t  RESERVED2:11; /*!< [23:13] 保留位  */
            __IO uint32_t CPUSEL    :3;  /*!< [26:24] 睡眠和待机模式的CPU选择  */
            __IO uint32_t STBYEVEN  :1;  /*!< [27:27] 待机进入事件配置启用  */
            __IO uint32_t STBYEV    :3;  /*!< [30:28] 待机进入事件配置  */
            __I           uint32_t  RESERVED3:1;  /*!< [31:31] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SWCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I          uint32_t RESERVED0:25; /*!< [24:0] 保留位  */
            __I uint32_t SACURST  :1;  /*!< [25:25] SACU复位指示标志  */
            __I uint32_t RST      :1;  /*!< [26:26] 应用程序或系统复位指示标志 */
            __I          uint32_t RESERVED1:5;  /*!< [31:27] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SWCTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t WUTREL   :24; /*!< [23:0] WUT重载值 */
            __I           uint32_t RESERVED0:3;  /*!< [26:24] 保留位  */
            __IO uint32_t WUTEN    :1;  /*!< [27:27] WUT使能 */
            __I uint32_t  BUSY     :1;  /*!< [28:28] 锁定状态LCK */
            __IO uint32_t WUTDIV   :1;  /*!< [29:29] WUT时钟分频器  */
            __IO uint32_t WUTMODE  :1;  /*!< [30:30] WUT模式选择 */
            __I           uint32_t RESERVED1:1;  /*!< [31:31] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SWCTL3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  BPTRISTREQ :1;  /*!< [0:0] 三态请求位(TRISTREQ)的位保护 */
            __IO uint32_t TRISTREQ   :1;  /*!< [1:1] 三态启用 */
            __IO uint32_t ESR0TRIST  :1;  /*!< [2:2] 将ESR0引脚为配置为复位输出或待机模式下的三态 */
            __I           uint32_t   RESERVED0:1;  /*!< [3:3] 保留位  */
            __IO uint32_t PORSTDF    :1;  /*!< [4:4] PORST数字滤波器启用 */
            __I           uint32_t   RESERVED1:1;  /*!< [5:5] 保留位  */
            __IO uint32_t DCDCSYNCO  :1;  /*!< [6:6] DCDC同步输出 */
            __I           uint32_t   RESERVED2:25; /*!< [31:7] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SWCTL5_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t WUTCNT   :24; /*!< [23:0] WUT计数器值 */
            __I          uint32_t RESERVED0:8;  /*!< [31:24] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SWUTCNT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I          uint32_t  RESERVED0:1; /*!< [0:0] 保留位  */
            __I uint32_t HWCFGEVR  :2; /*!< [2:1] EVR硬件配置状态 */
            __I          uint32_t  RESERVED1:1; /*!< [3:3] 保留位  */
            __I uint32_t HWCFG4    :1; /*!< [4:4] 硬件配置引脚4状态  */
            __I uint32_t HWCFG5    :1; /*!< [5:5] 硬件配置引脚5状态  */
            __I uint32_t TRIST     :1; /*!< [6:6]   Pad三态/上拉状态 */
            __I uint32_t TESTMODE  :1; /*!< [7:7] TESTMODE引脚状态  */
            __I uint32_t ESR0TRIST :1; /*!< [8:8] 待机期间的ESR0引脚状态 */
            __I          uint32_t  RESERVED2:2; /*!< [10:9] 保留位  */
            __I uint32_t PORSTDF   :1; /*!< [11:11] PORST数字滤波器状态  */
            __I          uint32_t  RESERVED3:9; /*!< [23:15] 保留位  */
            __I uint32_t WUTEN     :1; /*!< [24:24] WUT启用状态  */
            __I uint32_t WUTRUN    :1; /*!< [25:25] WUT运状态  */
            __I uint32_t WUTMODE   :1; /*!< [26:26] WUT模式状态该位指示当前的WUT模式 */
            __I          uint32_t  RESERVED4:1; /*!< [27:27] 保留位  */
            __I uint32_t ESR0INT   :1; /*!< [28:28] ESR0中断标志 */
            __I uint32_t ESR1INT   :1; /*!< [29:29] ESR1中断标志  */
            __I uint32_t PINAINT   :1; /*!< [30:30] 引脚A中断标志  */
            __I uint32_t PINBINT   :1; /*!< [31:31] 引脚B中断标志  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SWSTA0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ESR0WKP    :1; /*!< [0:0] ESR0唤醒标志  */
            __I uint32_t ESR1WKP    :1; /*!< [1:1] ESR1唤醒标志  */
            __I uint32_t PINAWKP    :1; /*!< [2:2] 引脚唤醒标志 */
            __I uint32_t PINBWKP    :1; /*!< [3:3] 引脚B唤醒标志 */
            __I uint32_t PWRWKP     :1; /*!< [4:4] VCC电源上升时的唤醒事件  */
            __I uint32_t PORSTWKP   :1; /*!< [6:6] PORST唤醒标志 */
            __I uint32_t WUTWKP     :1; /*!< [7:7] WUT唤醒标志 */
            __I uint32_t ESR0OVRUN  :1; /*!< [8:8] ESR0溢出状态标志 */
            __I uint32_t ESR1OVRUN  :1; /*!< [9:9] ESR1溢出状态标志 */
            __I uint32_t PINAOVRUN  :1; /*!< [10:10] PinAOverrun状态标志 */
            __I uint32_t PINBOVRUN  :1; /*!< [11:11] PinB溢出状态标志 */
            __I uint32_t VDDSTBYEN  :1; /*!< [12:12] VDD电源斜坡下降 */
            __I uint32_t PORSTOVRUN :1; /*!< [14:14] PORST溢出状态标志 */
            __I uint32_t WUTOVRUN   :1; /*!< [15:15] WUT溢出状态标志 */
            __I uint32_t STBYRAM    :3; /*!< [18:16] 备用RAM供应状态 */
            __I uint32_t VCCSTBYEN  :1; /*!< [19:19] VCC电源斜降时的待机进入启用状态 */
            __I uint32_t BLNKFIL    :4; /*!< [23:20] VCC电源唤醒的消隐滤波器延迟  */
            __I uint32_t ESR0WKEN   :1; /*!< [24:24] ESR0唤醒启用状态 */
            __I uint32_t ESR1WKEN   :1; /*!< [25:25] ESR1唤醒启用状态 */
            __I uint32_t PINAWKEN   :1; /*!< [26:26] PinA唤醒启用状态 */
            __I uint32_t PINBWKEN   :1; /*!< [27:27] PinB唤醒启用状态 */
            __I uint32_t PWRWKEN    :1; /*!< [28:28] VCC电源上升时的待机唤醒启用状态 */
            __I uint32_t PORSTWKEN  :1; /*!< [30:30] PORST引脚从待机唤醒启用状态 */
            __I uint32_t WUTWKEN    :1; /*!< [31:31] WUT唤醒启用状态  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SWSTA1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t ESR0WKPCLR    :1;  /*!< [0:0] ESR0唤醒指示标志清除  */
            __O uint32_t ESR1WKPCLR    :1;  /*!< [1:1] ESR1唤醒指示标志清除  */
            __O uint32_t PINAWKPCLR    :1;  /*!< [2:2] PINA唤醒指示标志清除  */
            __O uint32_t PINBWKPCLR    :1;  /*!< [3:3] PINB唤醒指示标志清除  */
            __O uint32_t PWRWKPCLR     :1;  /*!< [4:4] PWRWKP唤醒指示标志清除  */
            __O uint32_t PORSTWKPCLR   :1;  /*!< [6:6] PORST唤醒指示标志清除  */
            __O uint32_t WUTWKPCLR     :1;  /*!< [7:7] WUT唤醒指示标志清除  */
            __O uint32_t ESR0OVRUNCLR  :1;  /*!< [8:8] ESR0溢出状态指示标志清除  */
            __O uint32_t ESR1OVRUNCLR  :1;  /*!< [9:9] ESR1溢出状态指示标志清除  */
            __O uint32_t PINAOVRUNCLR  :1;  /*!< [10:10] PINA溢出状态指示标志清除  */
            __O uint32_t PINBOVRUNCLR  :1;  /*!< [11:11] PINB溢出状态指示标志清除  */
            __I          uint32_t      RESERVED0:2;  /*!< [13:12] 保留位  */
            __O uint32_t PORSTOVRUNCLR :1;  /*!< [14:14] PORST溢出状态指示标志清除  */
            __O uint32_t WUTOVRUNCLR   :1;  /*!< [15:15] WUT溢出状态指示标志清除  */
            __O uint32_t SCRSTCLR      :1;  /*!< [16:16] 用控制器SCRST指示标志清除  */
            __I          uint32_t      RESERVED1:11; /*!< [27:17] 保留位  */
            __O uint32_t ESR0INTCLR    :1;  /*!< [28:28] ESR0中断指示标志清除  */
            __O uint32_t ESR1INTCLR    :1;  /*!< [29:29] ESR1中断指示标志清除  */
            __O uint32_t PINAINTCLR    :1;  /*!< [30:30] PINA中断指示标志清除  */
            __O uint32_t PINBINTCLR    :1;  /*!< [31:31] PINB中断指示标志清除  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_SWCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OTGB0    :4;  /*!< [3:0] OTGB0的触发设置  */
            __I           uint32_t RESERVED0:4;  /*!< [7:4] 保留位  */
            __IO uint32_t OTGB1    :4;  /*!< [11:8] OTGB1触发设置  */
            __I           uint32_t RESERVED1:16; /*!< [31:16] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_OTSS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t B0LAM    :4; /*!< [3:0] OTGB0TS16_ADCMON低字节  */
            __I           uint32_t RESERVED0:4; /*!< [7:4] 保留位  */
            __IO uint32_t B0HAM    :4; /*!< [11:8] OTGB0TS16_ADCMON高字节  */
            __I           uint32_t RESERVED1:4; /*!< [15:12] 保留位  */
            __IO uint32_t B1LAM    :4; /*!< [19:16] OTGB1TS16_ADCMON低字节  */
            __I           uint32_t RESERVED2:4; /*!< [23:20] 保留位  */
            __IO uint32_t B1HAM    :4; /*!< [27:24] OTGB1TS16_ADCMON高字节  */
            __I           uint32_t RESERVED3:4; /*!< [31:28] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_OTSC0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t B0EC     :4; /*!< [3:0] OTGB0TS16_DCDC11ON  */
            __I           uint32_t RESERVED0:4; /*!< [7:4] 保留位  */
            __IO uint32_t B1EC     :4; /*!< [11:8] OTGB0TS16_DCDC11ON  */
            __I           uint32_t RESERVED1:4; /*!< [15:12] 保留位  */
            __IO uint32_t DMONAD   :8; /*!< [23:16] 编码表中记录的多复用器信号选择 */
            __IO uint32_t SMCDBG   :8; /*!< [31:24] OTGB0TS16_DCDC11ONSMCDBG:为将来的扩展保留  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_OTSC1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CPU0     :1;  /*!< [0:0] CPU0状态:该位域反映了CPU0的当前状态  */
            __I uint32_t CPU1     :1;  /*!< [1:1] CPU1状态:该位域反映了CPU1的当前状态  */
            __I          uint32_t RESERVED0:14; /*!< [15:2] 保留位  */
            __I uint32_t CPU0LS   :1;  /*!< [16:16] 该位字段反映了CPU0锁步检查器内核的当前状态 */
            __I uint32_t CPU1LS   :1;  /*!< [17:17] 该位字段反映了CPU1锁步检查器内核的当前状态 */
            __I          uint32_t RESERVED1:14; /*!< [31:18] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_CPUSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t REQSLP   :2;  /*!< [1:0]  空闲模式和睡眠模式请求 */
            __I           uint32_t RESERVED0:6;  /*!< [7:2] 保留位  */
            __I uint32_t  PMST     :3;  /*!< [10:8] 电源管状态:该位字段反映了CPU的当前状态  */
            __I           uint32_t RESERVED1:21; /*!< [31:11] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_CPUCS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESULT   :12; /*!< [11:0] DTS测的结果 */
            __I          uint32_t RESERVED0:20; /*!< [31:12] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} DTSP_RES_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LOWER    :12; /*!< [11:0]  下限 */
            __I           uint32_t RESERVED0:4;  /*!< [15:12] 保留位  */
            __IO uint32_t UPPER    :12; /*!< [27:16] 上限 */
            __I           uint32_t RESERVED1:4;  /*!< [31:28] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} DTSP_RANG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I           uint32_t RESERVED0:15; /*!< [14:0] 保留位  */
            __IO uint32_t LLU      :1;  /*!< [15:15] 下溢下限 */
            __I           uint32_t RESERVED1:14; /*!< [29:16] 保留位  */
            __IO uint32_t SLCK     :1;  /*!< [30:30] HSM安全锁 */
            __IO uint32_t UOF      :1;  /*!< [31:31] 溢出上限
                                         */
        } bits;
        __IO uint32_t reg;
    };
} DTSP_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESULT   :12; /*!< [11:0] DTSC测的结果 */
            __I          uint32_t RESERVED0:20; /*!< [31:12] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} DTSC_RES_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LOWER    :12; /*!< [11:0] DTSC下限 */
            __I           uint32_t RESERVED0:4;  /*!< [15:12] 保留位  */
            __IO uint32_t UPPER    :12; /*!< [27:16] DTSC上限 */
            __I           uint32_t RESERVED1:4;  /*!< [31:28] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} DTSC_RANG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t INTEN    :1;  /*!< [0:0] DTSC中断启用 */
            __I           uint32_t RESERVED0:1;  /*!< [1:1] 保留位  */
            __IO uint32_t EN       :1;  /*!< [2:2] 启用DTSC   */
            __I           uint32_t RESERVED1:29; /*!< [31:3] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} DTSC_CTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LLU    :1; /*!< [0:0]  DTSC下限下溢 */
            __IO uint32_t DTSCIF :1; /*!< [1:1] 生成SACUDTSC中断时，该位被设置   */
            __IO uint32_t UOF    :1; /*!< [2:2]  DTSC上限溢出  */
            __I uint32_t BGPOK :1; /*!< [3:3] 此位字段指示核心芯片温度传感器(DTSC)的带隙参考可用且正常  */
            __I uint32_t RESERVED0:28; /*!< [31:4] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} DTSC_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LJTEN    :1; /*!< [0:0] 负载跳转定时器使能  */
            __IO uint32_t LJTOVEN  :1; /*!< [1:1] 负载跳转定时器溢出启用  */
            __IO uint32_t LJTOVIEN :1; /*!< [2:2] 负载跳变计时器上溢中断使能 */
            __IO uint32_t LJTSTRT  :1; /*!< [3:3] 负载跳变定时器启动 */
            __IO uint32_t LJTSTP   :1; /*!< [4:4] 负载跳变定时器停止 */
            __O uint32_t  LJTCLR   :1; /*!< [5:5] 负载跳变定时器清零 */
            __I           uint32_t RESERVED0:6; /*!< [11:6] 保留位  */
            __IO uint32_t SDSTEP   :4; /*!< [15:12]  压降阶跃(vdroop_step_i) */
            __IO uint32_t VDTEN    :1; /*!< [16:16] 电压下降定时器使能 */
            __IO uint32_t VDTOVEN  :1; /*!< [17:17] 电压下降定时器溢出使能 */
            __IO uint32_t VDTOVIEN :1; /*!< [18:18] 电压下降定时器溢出中断使能 */
            __IO uint32_t VDTSTRT  :1; /*!< [19:19] 电压下降定时器启动 */
            __IO uint32_t VDTSTP   :1; /*!< [20:20] 电压下降定时器停止 */
            __O uint32_t  VDTCLR   :1; /*!< [21:21] 电压下降定时器清除 */
            __I           uint32_t RESERVED1:7; /*!< [28:22] 保留位 */
            __IO uint32_t LPSLPEN  :1; /*!< [29:29] 休眠请求PMS上的DCDC11低功耗模式激活 */
            __I           uint32_t RESERVED2:2; /*!< [31:30] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_TCS0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LJTCV    :16; /*!< [15:0] 负载跳转定时器比较设置点值 */
            __IO uint32_t VDTCV    :10; /*!< [25:16] 电压下降定时器比较设定点值 */
            __I           uint32_t RESERVED0:6;  /*!< [31:26] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_TCS1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LDJMPREQ :2;  /*!< [1:0] 负载跳转请求 */
            __I           uint32_t RESERVED0:2;  /*!< [3:2] 保留位  */
            __I uint32_t  LJTRUN   :2;  /*!< [5:4] 负载跳转定时器运状态  */
            __I           uint32_t RESERVED1:2;  /*!< [7:6] 保留位  */
            __I uint32_t  LJTOV    :1;  /*!< [8:8] 负载跳转定时器溢出状态 */
            __I           uint32_t RESERVED2:3;  /*!< [11:9] 保留位  */
            __O uint32_t  LJTOVCLR :1;  /*!< [12:12] 负载跳转定时器溢出状态清除 */
            __I           uint32_t RESERVED3:3;  /*!< [15:13] 保留位  */
            __I uint32_t  LJTCNT   :16; /*!< [31:16] 负载跳变定时器值 */
        } bits;
        __IO uint32_t reg;
    };
} PMC_TCS2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t VDROOPREQ :2;  /*!< [1:0] 电压下降请求   */
            __I           uint32_t  RESERVED0:2;  /*!< [3:2] 保留位  */
            __I uint32_t  VDTRUN    :2;  /*!< [5:4]  电压下降定时器运状态该状态位 */
            __I           uint32_t  RESERVED1:2;  /*!< [7:6] 保留位  */
            __I uint32_t  VDTOV     :1;  /*!< [8:8] 电压下降定时器溢出状态  */
            __I           uint32_t  RESERVED2:3;  /*!< [11:9] 保留位  */
            __O uint32_t  VDTOVCLR  :1;  /*!< [12:12] 保留位  */
            __I           uint32_t  RESERVED3:3;  /*!< [15:13] 保留位  */
            __I uint32_t  VDTCNT    :10; /*!< [25:16] 电压下降定时器值 */
            __I           uint32_t  RESERVED4:6;  /*!< [31:26] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} PMC_TCS3_T;

typedef volatile struct
{
    /* address: 0xF000B800 */
    PMC_INFO_T PMC_INFO;

    /* address: 0xF000B804 */
    PMC_ACES0_T PMC_ACES0;

    /* address: 0xF000B808 */
    PMC_ACES1_T PMC_ACES1;

    /* address: 0xF000B80C */
    PMC_STA_T PMC_STA;

    /* address: 0xF000B810 */
    PMC_PMONSTA_T PMC_PMONSTA;

    /* address: 0xF000B814 */
    PMC_RSTCTL_T PMC_RSTCTL;

    /* address: 0xF000B818 */
    PMC_RSTSTA_T PMC_RSTSTA;

    /* address: 0xF000B81C */
    PMC_CALCTL_T PMC_CALCTL;

    /* address: 0xF000B820 */
    PMC_CALSTA_T PMC_CALSTA;

    /* address: 0xF000B824 */
    PMC_SMONSTA1_T PMC_SMONSTA1;

    /* address: 0xF000B828 */
    PMC_SMONSTAT2_T PMC_SMONSTAT2;

    /* address: 0xF000B82C */
    PMC_SMONCTL_T PMC_SMONCTL;

    /* address: 0xF000B830 */
    PMC_SMONFIL_T PMC_SMONFIL;

    /* address: 0xF000B834 */
    PMC_IE_T PMC_IE;

    /* address: 0xF000B838 */
    PMC_UVMON0_T PMC_UVMON0;

    /* address: 0xF000B83C */
    PMC_OVMON0_T PMC_OVMON0;

    /* address: 0xF000B840 */
    PMC_UVMON1_T PMC_UVMON1;

    /* address: 0xF000B844 */
    PMC_OVMON1_T PMC_OVMON1;

    /* address: 0xF000B848 */
    HSM_UVMON_T HSM_UVMON;

    /* address: 0xF000B84C */
    HSM_OVMON_T HSM_OVMON;

    /* address: 0xF000B850 */
    PMC_LDO33CTL_T PMC_LDO33CTL;

    /* address: 0xF000B854 */
    PMC_OSCCTL_T PMC_OSCCTL;

    /* address: 0xF000B858 */
    PMC_SDSTA0_T PMC_SDSTA0;

    /* address: 0xF000B85C */
    PMC_SDCTL0_T PMC_SDCTL0;

    /* address: 0xF000B860 */
    PMC_SDCTL1_T PMC_SDCTL1;

    /* address: 0xF000B864 */
    PMC_SDCTL2_T PMC_SDCTL2;

    /* address: 0xF000B868 */
    PMC_SDCTL3_T PMC_SDCTL3;

    /* address: 0xF000B86C */
    PMC_SDCTL4_T PMC_SDCTL4;

    /* address: 0xF000B870 */
    PMC_SDCTL5_T PMC_SDCTL5;

    /* address: 0xF000B874 */
    PMC_SDCTL6_T PMC_SDCTL6;

    /* address: 0xF000B878 */
    PMC_SDCTL7_T PMC_SDCTL7;

    /* address: 0xF000B87C */
    PMC_SDCTL8_T PMC_SDCTL8;

    /* address: 0xF000B880 */
    PMC_SDCTL9_T PMC_SDCTL9;

    /* address: 0xF000B884 */
    PMC_SDCTL10_T PMC_SDCTL10;

    /* address: 0xF000B888 */
    PMC_SDCTL11_T PMC_SDCTL11;

    /* address: 0xF000B88C */
    PMC_SDFCT0_T PMC_SDFCT0;

    /* address: 0xF000B890 */
    PMC_SDFCT1_T PMC_SDFCT1;

    /* address: 0xF000B894 */
    PMC_SDFCT2_T PMC_SDFCT2;

    /* address: 0xF000B898 */
    PMC_SDFCT3_T PMC_SDFCT3;

    /* address: 0xF000B89C */
    PMC_SDFCT4_T PMC_SDFCT4;

    /* address: 0xF000B8A0 */
    PMC_SDFCT5_T PMC_SDFCT5;

    /* address: 0xF000B8A4 */
    PMC_SDFCT6_T PMC_SDFCT6;

    /* address: 0xF000B8A8 */
    PMC_SDFCT7_T PMC_SDFCT7;

    /* address: 0xF000B8AC */
    PMC_SDFCT8_T PMC_SDFCT8;

    /* address: 0xF000B8B0 */
    PMC_SDFCT9_T PMC_SDFCT9;

    /* address: 0xF000B8B4 */
    PMC_SWCTL0_T PMC_SWCTL0;

    /* address: 0xF000B8B8 */
    PMC_SWCTL1_T PMC_SWCTL1;

    /* address: 0xF000B8BC */
    PMC_SWCTL2_T PMC_SWCTL2;

    /* address: 0xF000B8C0 */
    PMC_SWCTL3_T PMC_SWCTL3;

    /* address: 0xF000B8C4 */
    PMC_SWCTL5_T PMC_SWCTL5;

    /* address: 0xF000B8C8 */
    PMC_SWUTCNT_T PMC_SWUTCNT;

    /* address: 0xF000B8CC */
    PMC_SWSTA0_T PMC_SWSTA0;

    /* address: 0xF000B8D0 */
    PMC_SWSTA1_T PMC_SWSTA1;

    /* address: 0xF000B8D4 */
    PMC_SWCLR_T PMC_SWCLR;

    /* address: 0xF000B8D8 */
    PMC_OTSS_T PMC_OTSS;

    /* address: 0xF000B8DC */
    PMC_OTSC0_T PMC_OTSC0;

    /* address: 0xF000B8E0 */
    PMC_OTSC1_T PMC_OTSC1;

    /* address: 0xF000B8E4 */
    PMC_CPUSTA_T PMC_CPUSTA;

    /* address: 0xF000B8E8 */
    PMC_CPUCS_T PMC_CPUCS[2];

    /* address: 0xF000B8F0 */
    DTSP_RES_T DTSP_RES;

    /* address: 0xF000B8F4 */
    DTSP_RANG_T DTSP_RANG;

    /* address: 0xF000B8F8 */
    DTSP_STA_T DTSP_STA;

    /* address: 0xF000B8FC */
    DTSC_RES_T DTSC_RES;

    /* address: 0xF000B900 */
    DTSC_RANG_T DTSC_RANG;

    /* address: 0xF000B904 */
    DTSC_CTL_T DTSC_CTL;

    /* address: 0xF000B908 */
    DTSC_STA_T DTSC_STA;

    /* address: 0xF000B90C */
    PMC_TCS0_T PMC_TCS0;

    /* address: 0xF000B910 */
    PMC_TCS1_T PMC_TCS1;

    /* address: 0xF000B914 */
    PMC_TCS2_T PMC_TCS2;

    /* address: 0xF000B918 */
    PMC_TCS3_T PMC_TCS3;
} Pmc_RegisterMap_t;

#define PMC_ADDR ((uint32_t)0xF000B800)
#define PMC_PTR  ((Pmc_RegisterMap_t *)PMC_ADDR)
#define PMC_RM   (*(Pmc_RegisterMap_t *)PMC_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
