/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_epwm.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyright protected and proprietary to
 * Shanghai ChipON Micro-Electronic Co.,Ltd
 **************************************************************************/

#ifndef _KF32DA13K_REG_EPWM_H_
#define _KF32DA13K_REG_EPWM_H_

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
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁止请求位  */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁止状态  */
            __IO uint32_t EDIS      :1;  /*!< [2:2] 休眠模式使能控制位  */
            __IO uint32_t RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] EPWM模块版本号  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] EPWM模块类型  */
            __I uint32_t MODNUM  :16; /*!< [31:16] EPWM模块编号  */
        } bits;
        __I uint32_t reg;
    };
} EPWM_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :24; /*!< [23:0] 预留读为0  */
            __IO uint32_t SUS       :4;  /*!< [27:24] 调试模式挂起控制  */
            __O uint32_t  SUSP      :1;  /*!< [28:28] SUS位写保护，读出为0  */
            __I uint32_t  SUSEPWMA  :1;  /*!< [29:29] 挂起状态位  */
            __IO uint32_t RESERVED1 :2;  /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST    :1; /*!< [0:0] 模块复位请求位，与EPWM_RST1寄存器的RST位一起使用  */
            __I uint32_t  RSTSTA :1; /*!< [1:1] 复位状态  */
            __IO uint32_t RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST :1; /*!< [0:0] 模块复位请求位，与EPWM_RST0寄存器的RST位一起使用  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  CLR       :1;  /*!< [0:0] 复位状态清除位，读出为0  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_RSTCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN0  :1; /*!< [0:0] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN1  :1; /*!< [1:1] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN2  :1; /*!< [2:2] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN3  :1; /*!< [3:3] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN4  :1; /*!< [4:4] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN5  :1; /*!< [5:5] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN6  :1; /*!< [6:6] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN7  :1; /*!< [7:7] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN8  :1; /*!< [8:8] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN9  :1; /*!< [9:9] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN10 :1; /*!< [10:10] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN11 :1; /*!< [11:11] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN12 :1; /*!< [12:12] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN13 :1; /*!< [13:13] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN14 :1; /*!< [14:14] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN15 :1; /*!< [15:15] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN16 :1; /*!< [16:16] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN17 :1; /*!< [17:17] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN18 :1; /*!< [18:18] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN19 :1; /*!< [19:19] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN20 :1; /*!< [20:20] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN21 :1; /*!< [21:21] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN22 :1; /*!< [22:22] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN23 :1; /*!< [23:23] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN24 :1; /*!< [24:24] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN25 :1; /*!< [25:25] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN26 :1; /*!< [26:26] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN27 :1; /*!< [27:27] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN28 :1; /*!< [28:28] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN29 :1; /*!< [29:29] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN30 :1; /*!< [30:30] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
            __IO uint32_t EN31 :1; /*!< [31:31] 使能MasterTAGIDn的事务对模块内核地址的写访问  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :32; /*!< [31:0] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN        :1; /*!< [0:0] 定时器使能位  */
            __IO uint32_t CS        :1; /*!< [1:1] 定时/计数模式选择  */
            __IO uint32_t GATEEN    :1; /*!< [2:2] 门控模式使能位  */
            __IO uint32_t TXSY      :1; /*!< [3:3] 计数模式下外部触发脉冲输入同步控制位  */
            __IO uint32_t CLKSEL       :1; /*!< [4:4] 时钟选择信号  */
            __IO uint32_t RESERVED0 :2; /*!< [6:5] 预留读为0  */
            __IO uint32_t CMS       :3; /*!< [9:7] 定时器计数模式选择位  */
            __IO uint32_t RESERVED1 :4; /*!< [13:10] 预留读为0  */
            __IO uint32_t PHSEN     :1; /*!< [14:14] 相位寄存器载入使能位  */
            __IO uint32_t SYNCOSEL  :2; /*!< [16:15] 同步事件输出SYNCO选择位  */
            __IO uint32_t SWFSYNC   :1; /*!< [17:17] 软件产生触发同步事件  */
            __IO uint32_t PHSDIR :1; /*!< [18:18] 在向上或者向下计数模式下，该位无效。只有在向上向下计数模式下才起作用。
                                      */
            __IO uint32_t RESERVED2 :4; /*!< [22:19] 预留读为0  */
            __IO uint32_t AQLOCKA   :1; /*!< [23:23] 通道A输出AQ波形发生控制子模块寄存器锁  */
            __IO uint32_t AQLOCKB   :1; /*!< [24:24] 通道B输出AQ波形发生控制子模块寄存器锁  */
            __IO uint32_t DBLOCK    :1; /*!< [25:25] DB死区控制子模块寄存器锁  */
            __IO uint32_t PCLOCK    :1; /*!< [26:26] PC斩波控制子模块寄存器锁  */
            __IO uint32_t ETLOCK    :1; /*!< [27:27] ET事件管理子模块寄存器锁  */
            __IO uint32_t HRLOCK    :1; /*!< [28:28] HRPWM高精度PWM子模块寄存器锁  */
            __IO uint32_t UDSYNEN   :1; /*!< [29:29] 同步信号触发更新使能位  */
            __IO uint32_t RESERVED3 :1; /*!< [30:30] 预留读为0  */
            __IO uint32_t BLINKEN   :1; /*!< [31:31] 响应上一级EPWM发送的LINK请求  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_CTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t SWCLRPF  :1; /*!< [0:0] 软件清零CAPIF使能位，该位中在CAPIC<1:0>=11时有效。  */
            __IO uint32_t BWINDEN  :1; /*!< [1:1] 消隐窗口使能位  */
            __IO uint32_t BWINDPOL :1; /*!< [2:2] 消隐窗口有效电平选择位  */
            __IO uint32_t BWINDTSEL :1; /*!< [3:3] 消隐窗口偏置参考点选择  */
            __IO uint32_t DUDBEN    :1; /*!< [4:4] 双边死区模式  */
            __IO uint32_t DUDBSEL   :1; /*!< [5:5] 双边死区模式选择位  */
            __IO uint32_t SYNCIOS   :1; /*!< [6:6] 同步模式使能位  */
            __IO uint32_t TRGIOS    :1; /*!< [7:7] 触发信号模式选择位  */
            __IO uint32_t SYNCFEN   :1; /*!< [8:8] 同步输入信号滤波使能位  */
            __IO uint32_t SYFDIV    :4; /*!< [12:9] 同步输入信号滤波时钟分频，滤波时钟为fEPWM  */
            __IO uint32_t SYDELAY   :3; /*!< [15:13] 同步输入信号滤波延时设置  */
            __IO uint32_t CKFEN     :1; /*!< [16:16] 外部时钟输入滤波使能位  */
            __IO uint32_t CKFDIV    :4; /*!< [20:17] 外部时钟输入滤波时钟分频，滤波时钟为fEPWM  */
            __IO uint32_t CKDELAY   :3; /*!< [23:21] 外部时钟输入滤波延时设置  */
            __IO uint32_t RESERVED0 :1; /*!< [24:24] 预留读为0  */
            __IO uint32_t LPHSEN    :1; /*!< [25:25] 触发事件产生相位重载使能位  */
            __IO uint32_t RESERVED1 :6; /*!< [31:26] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t AZRO :2; /*!< [1:0] 当CNT等于0时的通道A输出配置  */
            __IO uint32_t
              APRD :2;             /*!< [3:2]
                                      当CNT等于PPX寄存器时的通道A输出配置,注:在向上-向下计数模式下，当CNT等于PPX值时，计数方向向下，DIR等于1；
                                    */
            __IO uint32_t ACAU :2; /*!< [5:4] 当CNT等于RA寄存器且计数方向向上时的通道A输出配置  */
            __IO uint32_t ACAD :2; /*!< [7:6] 当CNT等于RA寄存器且计数方向向下时的通道A输出配置  */
            __IO uint32_t ACBU :2; /*!< [9:8] 当CNT等于RB寄存器且计数方向向上时的通道A输出配置  */
            __IO uint32_t ACBD :2; /*!< [11:10] 当CNT等于RB寄存器且计数方向向下时的通道A输出配置  */
            __IO uint32_t CSFA   :2; /*!< [13:12] 通道A连续强制输出  */
            __IO uint32_t ACTSFA :2; /*!< [15:14] 通道A单次强制输出,该位不需要等待更新信号  */
            __IO uint32_t
              OTSFA :1;                  /*!< [16:16]
                                            通道A单次强制输出使能,写1后，产生一个计数周期的脉冲，然后该位硬件自动清零，且该位不需要等待更新信号
                                          */
            __IO uint32_t RESERVED0 :15; /*!< [31:17] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_ACTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BZRO :2; /*!< [1:0] 当CNT等于0时的通道A输出配置  */
            __IO uint32_t
              BPRD :2;             /*!< [3:2]
                                      当CNT等于PPX寄存器时的通道A输出配置,注:在向上-向下计数模式下，当CNT等于PPX值时，计数方向向下，DIR等于1；
                                    */
            __IO uint32_t BCAU :2; /*!< [5:4] 当CNT等于RB寄存器且计数方向向上时的通道A输出配置  */
            __IO uint32_t BCAD :2; /*!< [7:6] 当CNT等于RB寄存器且计数方向向下时的通道A输出配置  */
            __IO uint32_t BCBU :2; /*!< [9:8] 当CNT等于RB寄存器且计数方向向上时的通道A输出配置  */
            __IO uint32_t BCBD :2; /*!< [11:10] 当CNT等于RB寄存器且计数方向向下时的通道A输出配置  */
            __IO uint32_t CSFB   :2; /*!< [13:12] 通道B连续强制输出  */
            __IO uint32_t ACTSFB :2; /*!< [15:14] 通道B单次强制输出,该位不需要等待更新信号  */
            __IO uint32_t
              OTSFB :1;                  /*!< [16:16]
                                            通道B单次强制输出使能,写1后，产生一个计数周期的脉冲，然后该位硬件自动清零，且该位不需要等待更新信号
                                          */
            __IO uint32_t RESERVED0 :15; /*!< [31:17] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_BCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PPUDEN    :1; /*!< [0:0] PPX寄存器独立更新使能位  */
            __IO uint32_t PPUDSEL   :2; /*!< [2:1] PPX寄存器独立更新事件选择位  */
            __IO uint32_t PRUDEN    :1; /*!< [3:3] PRSC寄存器独立更新使能位  */
            __IO uint32_t PRUDSEL   :2; /*!< [5:4] PRSC寄存器独立更新事件选择位  */
            __IO uint32_t CMAUDEN   :1; /*!< [6:6] RA寄存器独立更新使能位  */
            __IO uint32_t CMAUDSEL  :2; /*!< [8:7] RA寄存器独立更新事件选择位  */
            __IO uint32_t CMBUDEN   :1; /*!< [9:9] RB寄存器独立更新使能位  */
            __IO uint32_t CMBUDSEL  :2; /*!< [11:10] RB寄存器独立更新事件选择位  */
            __IO uint32_t CMCUDEN   :1; /*!< [12:12] RC寄存器独立更新使能位  */
            __IO uint32_t CMCUDSEL  :2; /*!< [14:13] RC寄存器独立更新事件选择位  */
            __IO uint32_t CMDUDEN   :1; /*!< [15:15] RD寄存器独立更新使能位  */
            __IO uint32_t CMDUDSEL  :2; /*!< [17:16] RD寄存器独立更新事件选择位  */
            __IO uint32_t EAUDEN    :1; /*!< [18:18] ACTL寄存器独立更新使能位  */
            __IO uint32_t EAUDSEL   :2; /*!< [20:19] ACTL寄存器独立更新事件选择位  */
            __IO uint32_t EBUDEN    :1; /*!< [21:21] BCTL寄存器独立更新使能位  */
            __IO uint32_t EBUDSEL   :2; /*!< [23:22] BCTL寄存器独立更新事件选择位  */
            __IO uint32_t RESERVED0 :7; /*!< [30:24] 预留读为0  */
            __IO uint32_t GBUDEN    :1; /*!< [31:31] 全局加载使能位  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_UDCTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t UDEN      :1;  /*!< [0:0] 更新使能位  */
            __IO uint32_t UDEVT     :1;  /*!< [1:1] 更新事件控制位,在UDEN为1时有效  */
            __O uint32_t  UR        :1;  /*!< [2:2] 更新事件生成位,该位自动清零，不受UDEN控制  */
            __IO uint32_t RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_UDCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              CLDPRCS :8;                /*!< [7:0]
                                            全局加载事件预分频每有CLDPRCS<7:0>+1次更新触发事件发生时，才会进行一次真正的寄存器更新
                                          */
            __IO uint32_t HRPAUDEN   :1; /*!< [8:8] HRRA寄存器独立更新使能位  */
            __IO uint32_t HRPAUDSEL  :2; /*!< [10:9] HRRA寄存器独立更新事件选择位  */
            __IO uint32_t HRPBUDEN   :1; /*!< [11:11] HRRB寄存器独立更新使能位  */
            __IO uint32_t HRPBUDSEL  :2; /*!< [13:12] HRRB寄存器独立更新事件选择位  */
            __IO uint32_t DBUDEN     :1; /*!< [14:14] DB寄存器独立更新使能位  */
            __IO uint32_t DBUDSEL    :2; /*!< [16:15] DB寄存器独立更新事件选择位  */
            __IO uint32_t HRDBUDEN   :1; /*!< [17:17] HRDB寄存器独立更新使能位  */
            __IO uint32_t HRDBUDSEL  :2; /*!< [19:18] HRDB寄存器独立更新事件选择位  */
            __IO uint32_t HRPHSUDEN  :1; /*!< [20:20] HRPHS寄存器独立更新使能位  */
            __IO uint32_t HRPHSUDSEL :2; /*!< [22:21] HRPHS寄存器独立更新事件选择位  */
            __IO uint32_t HRCFGUDEN  :1; /*!< [23:23] HRCFG寄存器独立更新使能位  */
            __IO uint32_t HRCFGUDSEL :2; /*!< [25:24] HRCFG寄存器独立更新事件选择位  */
            __IO uint32_t RESERVED0  :6; /*!< [31:26] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_UDCTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CAPEN     :1;  /*!< [0:0] 捕捉功能使能位  */
            __IO uint32_t CAPSEL    :1;  /*!< [1:1] 捕捉事件选择位  */
            __IO uint32_t CAPMOD    :1;  /*!< [2:2] 捕捉模式选择位  */
            __IO uint32_t CAPFEN    :1;  /*!< [3:3] 捕捉引脚CAP输入滤波使能位  */
            __IO uint32_t CFDIV     :4;  /*!< [7:4] 捕捉引脚滤波时钟分频，滤波时钟为fEPWM  */
            __IO uint32_t CFDELAY   :3;  /*!< [10:8] 捕捉通道滤波延时设置  */
            __IO uint32_t RESERVED0 :21; /*!< [31:11] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_CAPCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OUTMODE   :2;  /*!< [1:0] 死区输出选择位  */
            __IO uint32_t POLSEL    :2;  /*!< [3:2] 死区输出极性选择位  */
            __IO uint32_t INMODE    :2;  /*!< [5:4] 死区输入选择位  */
            __IO uint32_t RESERVED0 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_DBCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FDBT :16; /*!< [15:0] 16位下降沿死区时间设置位  */
            __IO uint32_t RDBT :16; /*!< [31:16] 16位上升沿死区时间设置位  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_DBT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CHPEN     :1;  /*!< [0:0] 斩波模块使能位  */
            __IO uint32_t OSHTWTH   :4;  /*!< [4:1] 斩波第一个脉冲宽度选择位  */
            __IO uint32_t CHPDUTY   :3;  /*!< [7:5] 死区输出极性选择位  */
            __IO uint32_t CHPFREQ   :3;  /*!< [10:8] PCLK频率设置  */
            __IO uint32_t RESERVED0 :21; /*!< [31:11] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_PCCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PXAEN     :1;  /*!< [0:0] 关断控制使能位  */
            __IO uint32_t PXRSEN    :1;  /*!< [1:1] 自动重启使能位  */
            __IO uint32_t PXSSA     :2;  /*!< [3:2] 引脚A关闭状态控制位  */
            __IO uint32_t PXSSB     :2;  /*!< [5:4] 引脚B关闭状态控制位  */
            __IO uint32_t TZSEL     :4;  /*!< [9:6] 外部引脚信号与比较器CMP信号自动关闭源选择  */
            __IO uint32_t RESERVED0 :18; /*!< [27:10] 预留读为0  */
            __IO uint32_t PXQEIIFEN :1;  /*!< [28:28] QEI模块错误中断标志信号使能控制  */
            __IO uint32_t PXCLKIFEN :1;  /*!< [29:29] 振荡器模块错误中断信号使能控制  */
            __IO uint32_t PXTZEN    :2;  /*!< [31:30] TZy(y=0-7)关断信号使能控制  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_TZSCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t HRENA     :1;  /*!< [0:0] PWM通道A高精度功能使能位  */
            __IO uint32_t HRSELA    :1;  /*!< [1:1] HRPWM通道A输出控制位  */
            __IO uint32_t HRDENA    :1;  /*!< [2:2] HRPWM通道A占空比高精度使能位  */
            __IO uint32_t HRPENA    :1;  /*!< [3:3] HRPWM通道A周期高精度使能位  */
            __IO uint32_t HRRENA    :1;  /*!< [4:4] HRPWM通道A死区上升沿高精度使能位  */
            __IO uint32_t HRFENA    :1;  /*!< [5:5] HRPWM通道A死区下降沿高精度使能位  */
            __IO uint32_t HRPHSENA  :1;  /*!< [6:6] HRPWM通道A高精度相位使能位  */
            __IO uint32_t RESERVED0 :25; /*!< [31:7] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_HRACTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t HRENB     :1;  /*!< [0:0] PWM通道B高精度功能使能位  */
            __IO uint32_t HRSELB    :1;  /*!< [1:1] HRPWM通道B输出控制位  */
            __IO uint32_t HRDENB    :1;  /*!< [2:2] HRPWM通道B占空比高精度使能位  */
            __IO uint32_t HRPENB    :1;  /*!< [3:3] HRPWM通道B周期高精度使能位  */
            __IO uint32_t HRRENB    :1;  /*!< [4:4] HRPWM通道B死区上升沿高精度使能位  */
            __IO uint32_t HRFENB    :1;  /*!< [5:5] HRPWM通道B死区下降沿高精度使能位  */
            __IO uint32_t HRPHSENB  :1;  /*!< [6:6] HRPWM通道B高精度相位使能位  */
            __IO uint32_t RESERVED0 :25; /*!< [31:7] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_HRBCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t HRRA      :8;  /*!< [7:0] 8位高精度PWM占空比A  */
            __IO uint32_t RESERVED0 :24; /*!< [31:8] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_HRRA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t HRRB      :8;  /*!< [7:0] 8位高精度PWM占空比B  */
            __IO uint32_t RESERVED0 :24; /*!< [31:8] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_HRRB_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t HRF       :8;  /*!< [7:0] 死区下降沿高精度值  */
            __IO uint32_t HRR       :8;  /*!< [15:8] 死区上升沿高精度值  */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_HRDB_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t HRPHS     :8;  /*!< [7:0] 相位高精度值  */
            __IO uint32_t HRPRE     :8;  /*!< [15:8] 周期高精度值  */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_HRPHS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              TIMS :8;             /*!< [7:0]
                                      延时波形计数次数,由于PWM经过高精度的处理，会导致每次输出会在上一次输出的基础上有一定的相位后移，延时计数次数用来保证最大允许的相位后移，每处理TIMS<7:0>个PWM波形，就会重新将原始信号载入到HRPWM，同时延时次数的计数再次从0开始计数。
                                    */
            __IO uint32_t STEP :8; /*!< [15:8] 高精度步长数，表示每一个计数时钟中包含的细粒度步数  */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_HRCFG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FEDAHR    :8;  /*!< [7:0] 通道A下降沿当前使用的高精度MEP延长步数  */
            __IO uint32_t REDAHR    :8;  /*!< [15:8] 通道A上升沿当前使用的高精度MEP延长步数  */
            __IO uint32_t FEDBHR    :8;  /*!< [23:16] 通道B下降沿当前使用的高精度MEP延长步数  */
            __IO uint32_t REDBHR    :8;  /*!< [31:24] 通道B上升沿当前使用的高精度MEP延长步数  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_HRDELAY_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TOADENA   :1; /*!< [0:0] 触发AD事件0使能位  */
            __IO uint32_t RESERVED0 :2; /*!< [2:1] 预留读为0  */
            __IO uint32_t FRCA      :1; /*!< [3:3] 软件触发AD事件0  */
            __IO uint32_t RESERVED1 :4; /*!< [7:4] 预留读为0  */
            __IO uint32_t ATSEL     :2; /*!< [9:8] 触发AD事件0触发模式选择位  */
            __IO uint32_t RESERVED2 :6; /*!< [15:10] 预留读为0  */
            __IO uint32_t TOADENB   :1; /*!< [16:16] 触发AD事件1使能位  */
            __IO uint32_t RESERVED3 :2; /*!< [18:17] 预留读为0  */
            __IO uint32_t FRCB      :1; /*!< [19:19] 软件触发AD事件1  */
            __IO uint32_t RESERVED4 :4; /*!< [23:20] 预留读为0  */
            __IO uint32_t BTSEL     :2; /*!< [25:24] 触发AD事件1触发模式选择位  */
            __IO uint32_t RESERVED5 :6; /*!< [31:26] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_ETCTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SELA      :3; /*!< [2:0] 触发AD事件1选择位  */
            __IO uint32_t APP       :4; /*!< [6:3] 触发AD事件1周期选择位  */
            __I uint32_t  AT        :4; /*!< [10:7] 触发AD事件1触发信号计数位,包括软件触发  */
            __IO uint32_t RESERVED0 :5; /*!< [15:11] 预留读为0  */
            __IO uint32_t SELB      :3; /*!< [18:16] 触发AD事件1选择位  */
            __IO uint32_t BPP       :4; /*!< [22:19] 触发AD事件1周期选择位  */
            __I uint32_t  BT        :2; /*!< [25:24] 触发AD事件1触发信号计数位,包括软件触发  */
            __IO uint32_t RESERVED1 :5; /*!< [31:27] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_ETCTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BWOFFSET :16; /*!< [15:0] 消隐窗口偏置。用来配置消隐窗口生效时机与0/PPX的距离  */
            __IO uint32_t BWIDTH :16; /*!< [31:16] 消隐窗口宽度  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_BWCFG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              OFFCNT :16; /*!< [15:0]
                             消隐窗口偏置计数器,在每次偏置参考点将BWOFFSET<15:0>值加载到该16位计数器中并开始向下计数
                           */
            __I uint32_t
              WITCNT :16; /*!< [31:16]
                             消隐窗口宽度计数器,在每次偏置计数器计数到0时将BWIDTH<15:0>值加载到该计数器中并开始向下计数。
                           */
        } bits;
        __I uint32_t reg;
    };
} EPWM_BWCNT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  DIR       :1; /*!< [0:0] 计数方向位  */
            __IO uint32_t CNTMAX    :1; /*!< [1:1] 写1清零该位  */
            __IO uint32_t SYNCI     :1; /*!< [2:2] 写1清零该位  */
            __IO uint32_t PXASE     :1; /*!< [3:3] 自动关闭事件状态位  */
            __IO uint32_t RESERVED0 :4; /*!< [7:4] 预留读为0  */
            __I uint32_t  CMAFUF    :1; /*!< [8:8] RA的影子寄存器空满标志位  */
            __I uint32_t  CMBFUF    :1; /*!< [9:9] RB的影子寄存器空满标志位  */
            __I uint32_t  CMCFUF    :1; /*!< [10:10] RC的影子寄存器空满标志位  */
            __I uint32_t  CADFUF    :1; /*!< [11:11] RD的影子寄存器空满标志位  */
            __I uint32_t  PPFUF     :1; /*!< [12:12] PPX的影子寄存器空满标志位  */
            __I uint32_t  PRFUF     :1; /*!< [13:13] PRSC的影子寄存器空满标志位  */
            __I uint32_t  EAFUF     :1; /*!< [14:14] CTLA的影子寄存器空满标志位  */
            __I uint32_t  EBFUF     :1; /*!< [15:15] CTLB的影子寄存器空满标志位  */
            __I uint32_t  HRPAUF    :1; /*!< [16:16] HRRA的影子寄存器空满标志位  */
            __I uint32_t  HRPBUF    :1; /*!< [17:17] HRRB的影子寄存器空满标志位  */
            __I uint32_t  DBTUF     :1; /*!< [18:18] DBT的影子寄存器空满标志位  */
            __I uint32_t  HRDBUF    :1; /*!< [19:19] HRDB的影子寄存器空满标志位  */
            __I uint32_t  HRPHSUF   :1; /*!< [20:20] HRPHS的影子寄存器空满标志位  */
            __I uint32_t  HRCFGUF   :1; /*!< [21:21] HRCFG的影子寄存器空满标志位  */
            __I uint32_t  CAPUF     :1; /*!< [22:22] CAP的影子寄存器空满标志位  */
            __IO uint32_t RESERVED1 :9; /*!< [31:23] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CNT :32; /*!< [31:0] 32位EPWM计数器  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_CNT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PHS :32; /*!< [31:0] 相位值PHS  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_PHS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PPX :32; /*!< [31:0] 周期值PPX  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_PPX_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PRSC :32; /*!< [31:0] 预分频值  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_PRSC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RA :32; /*!< [31:0] 32位占空比A寄存器  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_RA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RB :32; /*!< [31:0] 32位占空比B寄存器  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_RB_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RC :32; /*!< [31:0] 32位占空比C寄存器  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_RC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RD :32; /*!< [31:0] 32位占空比D寄存器  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_RD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CAP :32; /*!< [31:0] 捕捉计数器的当前计数值，存入该寄存器中。  */
        } bits;
        __I uint32_t reg;
    };
} EPWM_CAP_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  TOIF      :1;  /*!< [0:0] 定时器计数溢出中断标志位  */
            __I uint32_t  UEIF      :1;  /*!< [1:1] 更新事件中断标志位  */
            __I uint32_t  GIF       :1;  /*!< [2:2] 关断事件中断标志位  */
            __I uint32_t  TAIF      :1;  /*!< [3:3] 定时器计数值等于RA触发中断标志位  */
            __I uint32_t  TBIF      :1;  /*!< [4:4] 定时器计数值等于RB触发中断标志位  */
            __I uint32_t  TCIF      :1;  /*!< [5:5] 定时器计数值等于RC触发中断标志位  */
            __I uint32_t  TDIF      :1;  /*!< [6:6] 定时器计数值等于RD触发中断标志位  */
            __I uint32_t  CAPIF     :1;  /*!< [7:7] 捕捉中断标志位  */
            __I uint32_t  TIF0      :1;  /*!< [8:8] 定时器触发AD事件0中断标志位  */
            __I uint32_t  TIF1      :1;  /*!< [9:9] 定时器触发AD事件1中断标志位  */
            __IO uint32_t RESERVED0 :22; /*!< [31:10] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TOIE      :1;  /*!< [0:0] 定时器计数溢出中断使能位  */
            __IO uint32_t UEIE      :1;  /*!< [1:1] 更新事件中断使能位  */
            __IO uint32_t GIE       :1;  /*!< [2:2] 关断事件中断使能位  */
            __IO uint32_t TAIE      :1;  /*!< [3:3] 定时器计数值等于RA触发中断使能位  */
            __IO uint32_t TBIE      :1;  /*!< [4:4] 定时器计数值等于RB触发中断使能位  */
            __IO uint32_t TCIE      :1;  /*!< [5:5] 定时器计数值等于RC触发中断使能位  */
            __IO uint32_t TDIE      :1;  /*!< [6:6] 定时器计数值等于RD触发中断使能位  */
            __IO uint32_t CAPIE     :1;  /*!< [7:7] 捕捉中断使能位  */
            __IO uint32_t TIE0      :1;  /*!< [8:8] 定时器触发AD事件0中断使能位  */
            __IO uint32_t TIE1      :1;  /*!< [9:9] 定时器触发AD事件1中断使能位  */
            __IO uint32_t RESERVED0 :22; /*!< [31:10] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  TOIC      :1;  /*!< [0:0] 定时器计数溢出中断清零位  */
            __O uint32_t  UEIC      :1;  /*!< [1:1] 更新事件中断清零位  */
            __O uint32_t  GIC       :1;  /*!< [2:2] 关断事件中断清零位  */
            __O uint32_t  TAIC      :1;  /*!< [3:3] 定时器计数值等于RA触发中断清零位  */
            __O uint32_t  TBIC      :1;  /*!< [4:4] 定时器计数值等于RB触发中断清零位  */
            __O uint32_t  TCIC      :1;  /*!< [5:5] 定时器计数值等于RC触发中断清零位  */
            __O uint32_t  TDIC      :1;  /*!< [6:6] 定时器计数值等于RD触发中断清零位  */
            __O uint32_t  CAPIC     :2;  /*!< [8:7] 捕捉中断清零位  */
            __O uint32_t  TIC0      :1;  /*!< [9:9] 定时器触发AD事件0中断清除位  */
            __O uint32_t  TIC1      :1;  /*!< [10:10] 定时器触发AD事件1中断清除位  */
            __IO uint32_t RESERVED0 :21; /*!< [31:11] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_IC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  TOIS      :1;  /*!< [0:0] 定时器计数溢出中断置一位  */
            __O uint32_t  UEIS      :1;  /*!< [1:1] 更新事件中断置一位  */
            __O uint32_t  GIS       :1;  /*!< [2:2] 关断事件中断置一位  */
            __O uint32_t  TAIS      :1;  /*!< [3:3] 定时器计数值等于RA触发中断置一位  */
            __O uint32_t  TBIS      :1;  /*!< [4:4] 定时器计数值等于RB触发中断置一位  */
            __O uint32_t  TCIS      :1;  /*!< [5:5] 定时器计数值等于RC触发中断置一位  */
            __O uint32_t  TDIS      :1;  /*!< [6:6] 定时器计数值等于RD触发中断置一位  */
            __O uint32_t  CAPIS     :1;  /*!< [7:7] 捕捉中断置一位  */
            __O uint32_t  TIS0      :1;  /*!< [8:8] 定时器触发AD事件0中断置一位  */
            __O uint32_t  TIS1      :1;  /*!< [9:9] 定时器触发AD事件1中断置一位  */
            __IO uint32_t RESERVED0 :22; /*!< [31:10] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_IS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TODE      :1;  /*!< [0:0] 定时器计数溢出触发DMA使能位  */
            __IO uint32_t UEDE      :1;  /*!< [1:1] 更新事件触发DMA使能位  */
            __IO uint32_t GDE       :1;  /*!< [2:2] 关断事件触发DMA使能位  */
            __IO uint32_t TADE      :1;  /*!< [3:3] 定时器计数值等于RA触发DMA使能位  */
            __IO uint32_t TBDE      :1;  /*!< [4:4] 定时器计数值等于RB触发DMA使能位  */
            __IO uint32_t TCDE      :1;  /*!< [5:5] 定时器计数值等于RC触发DMA使能位  */
            __IO uint32_t TDDE      :1;  /*!< [6:6] 定时器计数值等于RD触发DMA使能位  */
            __IO uint32_t CAPDE     :1;  /*!< [7:7] 捕捉中断使能位  */
            __IO uint32_t ADDE0     :1;  /*!< [8:8] 定时器触发AD事件0触发DMA使能位  */
            __IO uint32_t ADDE1     :1;  /*!< [9:9] 定时器触发AD事件1触发DMA使能位  */
            __IO uint32_t RESERVED0 :22; /*!< [31:10] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_DE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  TODF      :1;  /*!< [0:0] 定时器计数溢出触发DMA标志位  */
            __I uint32_t  UEDF      :1;  /*!< [1:1] 更新事件触发DMA标志位  */
            __I uint32_t  GDF       :1;  /*!< [2:2] 关断事件触发DMA标志位  */
            __I uint32_t  TADF      :1;  /*!< [3:3] 定时器计数值等于RA触发DMA标志位  */
            __I uint32_t  TBDF      :1;  /*!< [4:4] 定时器计数值等于RB触发DMA标志位  */
            __I uint32_t  TCDF      :1;  /*!< [5:5] 定时器计数值等于RC触发DMA标志位  */
            __I uint32_t  TDDF      :1;  /*!< [6:6] 定时器计数值等于RD触发DMA标志位  */
            __I uint32_t  CAPDF     :1;  /*!< [7:7] 捕捉中断标志位  */
            __I uint32_t  ADDF0     :1;  /*!< [8:8] 定时器触发AD事件0触发DMA标志位  */
            __I uint32_t  ADDF1     :1;  /*!< [9:9] 定时器触发AD事件1触发DMA标志位  */
            __IO uint32_t RESERVED0 :22; /*!< [31:10] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_DF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TONP  :2; /*!< [1:0] 定时器计数溢出的服务中断节点  */
            __IO uint32_t UENP  :2; /*!< [3:2] 更新事件的服务中断节点  */
            __IO uint32_t GNP   :2; /*!< [5:4] 关断事件的服务中断节点  */
            __IO uint32_t TANP  :2; /*!< [7:6] 定时器计数值等于RA的服务中断节点  */
            __IO uint32_t TBNP  :2; /*!< [9:8] 定时器计数值等于RB的服务中断节点指针  */
            __IO uint32_t TCNP  :2; /*!< [11:10] 定时器计数值等于RC的服务中断节点  */
            __IO uint32_t TDNP  :2; /*!< [13:12] 定时器计数值等于RD的服务中断节点  */
            __IO uint32_t CAPNP :2; /*!< [15:14] 捕捉的服务中断节点  */
            __IO uint32_t AD0NP :2; /*!< [17:16] 定时器触发AD事件0的服务中断节点  */
            __IO uint32_t AD1NP :2; /*!< [19:18] 定时器触发AD事件1的服务中断节点  */
        } bits;
        __IO uint32_t reg;
    };
} EPWM_INP_T;

typedef volatile struct
{
    /* address: 0xF0024000 */
    EPWM_CLKC_T EPWM_CLKC;

    /* address: 0xF0024004 */
    EPWM_INFO_T EPWM_INFO;

    /* address: 0xF0024008 */
    EPWM_DBG_T EPWM_DBG;

    /* address: 0xF002400C */
    EPWM_RST0_T EPWM_RST0;

    /* address: 0xF0024010 */
    EPWM_RST1_T EPWM_RST1;

    /* address: 0xF0024014 */
    EPWM_RSTCLR_T EPWM_RSTCLR;

    /* address: 0xF0024018 */
    EPWM_ACES0_T EPWM_ACES0;

    /* address: 0xF002401C */
    EPWM_ACES1_T EPWM_ACES1;

    /* address: 0xF0024020 */
    EPWM_CTL0_T EPWM_CTL0;

    /* address: 0xF0024024 */
    EPWM_CTL1_T EPWM_CTL1;

    /* address: 0xF0024028 */
    EPWM_ACTL_T EPWM_ACTL;

    /* address: 0xF002402C */
    EPWM_BCTL_T EPWM_BCTL;

    /* address: 0xF0024030 */
    EPWM_UDCTL0_T EPWM_UDCTL0;

    /* address: 0xF0024034 */
    EPWM_UDCTL1_T EPWM_UDCTL1;

    /* address: 0xF0024038 */
    EPWM_UDCTL2_T EPWM_UDCTL2;

    /* address: 0xF002403C */
    EPWM_CAPCTL_T EPWM_CAPCTL;

    /* address: 0xF0024040 */
    EPWM_DBCTL_T EPWM_DBCTL;

    /* address: 0xF0024044 */
    EPWM_DBT_T EPWM_DBT;

    /* address: 0xF0024048 */
    EPWM_PCCTL_T EPWM_PCCTL;

    /* address: 0xF002404C */
    EPWM_TZSCTL_T EPWM_TZSCTL;

    /* address: 0xF0024050 */
    EPWM_HRACTL_T EPWM_HRACTL;

    /* address: 0xF0024054 */
    EPWM_HRBCTL_T EPWM_HRBCTL;

    /* address: 0xF0024058 */
    EPWM_HRRA_T EPWM_HRRA;

    /* address: 0xF002405C */
    EPWM_HRRB_T EPWM_HRRB;

    /* address: 0xF0024060 */
    EPWM_HRDB_T EPWM_HRDB;

    /* address: 0xF0024064 */
    EPWM_HRPHS_T EPWM_HRPHS;

    /* address: 0xF0024068 */
    EPWM_HRCFG_T EPWM_HRCFG;

    /* address: 0xF002406C */
    EPWM_HRDELAY_T EPWM_HRDELAY;

    /* address: 0xF0024070 */
    EPWM_ETCTL0_T EPWM_ETCTL0;

    /* address: 0xF0024074 */
    EPWM_ETCTL1_T EPWM_ETCTL1;

    /* address: 0xF0024078 */
    EPWM_BWCFG_T EPWM_BWCFG;

    /* address: 0xF002407C */
    EPWM_BWCNT_T EPWM_BWCNT;

    /* address: 0xF0024080 */
    EPWM_STA_T EPWM_STA;

    /* address: 0xF0024084 */
    EPWM_CNT_T EPWM_CNT;

    /* address: 0xF0024088 */
    EPWM_PHS_T EPWM_PHS;

    /* address: 0xF002408C */
    EPWM_PPX_T EPWM_PPX;

    /* address: 0xF0024090 */
    EPWM_PRSC_T EPWM_PRSC;

    /* address: 0xF0024094 */
    EPWM_RA_T EPWM_RA;

    /* address: 0xF0024098 */
    EPWM_RB_T EPWM_RB;

    /* address: 0xF002409C */
    EPWM_RC_T EPWM_RC;

    /* address: 0xF00240A0 */
    EPWM_RD_T EPWM_RD;

    /* address: 0xF00240A4 */
    EPWM_CAP_T EPWM_CAP;

    /* address: 0xF00240A8 */
    EPWM_IF_T EPWM_IF;

    /* address: 0xF00240AC */
    EPWM_IE_T EPWM_IE;

    /* address: 0xF00240B0 */
    EPWM_IC_T EPWM_IC;

    /* address: 0xF00240B4 */
    EPWM_IS_T EPWM_IS;

    /* address: 0xF00240B8 */
    EPWM_DE_T EPWM_DE;

    /* address: 0xF00240BC */
    EPWM_DF_T EPWM_DF;

    /* address: 0xF00240C0 */
    EPWM_INP_T EPWM_INP;
} Epwm_RegisterMap_t;

#define EPWM11_ADDR ((uint32_t)0xF0024000)
#define EPWM11_PTR  ((Epwm_RegisterMap_t *)EPWM11_ADDR)
#define EPWM11_RM   (*(Epwm_RegisterMap_t *)EPWM11_ADDR)

#define EPWM12_ADDR ((uint32_t)0xF0024100)
#define EPWM12_PTR  ((Epwm_RegisterMap_t *)EPWM12_ADDR)
#define EPWM12_RM   (*(Epwm_RegisterMap_t *)EPWM12_ADDR)

#define EPWM13_ADDR ((uint32_t)0xF0024200)
#define EPWM13_PTR  ((Epwm_RegisterMap_t *)EPWM13_ADDR)
#define EPWM13_RM   (*(Epwm_RegisterMap_t *)EPWM13_ADDR)

#define EPWM14_ADDR ((uint32_t)0xF0024300)
#define EPWM14_PTR  ((Epwm_RegisterMap_t *)EPWM14_ADDR)
#define EPWM14_RM   (*(Epwm_RegisterMap_t *)EPWM14_ADDR)

#define EPWM21_ADDR ((uint32_t)0xF0024400)
#define EPWM21_PTR  ((Epwm_RegisterMap_t *)EPWM21_ADDR)
#define EPWM21_RM   (*(Epwm_RegisterMap_t *)EPWM21_ADDR)

#define EPWM22_ADDR ((uint32_t)0xF0024500)
#define EPWM22_PTR  ((Epwm_RegisterMap_t *)EPWM22_ADDR)
#define EPWM22_RM   (*(Epwm_RegisterMap_t *)EPWM22_ADDR)

#define EPWM23_ADDR ((uint32_t)0xF0024600)
#define EPWM23_PTR  ((Epwm_RegisterMap_t *)EPWM23_ADDR)
#define EPWM23_RM   (*(Epwm_RegisterMap_t *)EPWM23_ADDR)

#define EPWM24_ADDR ((uint32_t)0xF0024700)
#define EPWM24_PTR  ((Epwm_RegisterMap_t *)EPWM24_ADDR)
#define EPWM24_RM   (*(Epwm_RegisterMap_t *)EPWM24_ADDR)

#define EPWM31_ADDR ((uint32_t)0xF0024800)
#define EPWM31_PTR  ((Epwm_RegisterMap_t *)EPWM31_ADDR)
#define EPWM31_RM   (*(Epwm_RegisterMap_t *)EPWM31_ADDR)

#define EPWM32_ADDR ((uint32_t)0xF0024900)
#define EPWM32_PTR  ((Epwm_RegisterMap_t *)EPWM32_ADDR)
#define EPWM32_RM   (*(Epwm_RegisterMap_t *)EPWM32_ADDR)

#define EPWM33_ADDR ((uint32_t)0xF0024A00)
#define EPWM33_PTR  ((Epwm_RegisterMap_t *)EPWM33_ADDR)
#define EPWM33_RM   (*(Epwm_RegisterMap_t *)EPWM33_ADDR)

#define EPWM34_ADDR ((uint32_t)0xF0024B00)
#define EPWM34_PTR  ((Epwm_RegisterMap_t *)EPWM34_ADDR)
#define EPWM34_RM   (*(Epwm_RegisterMap_t *)EPWM34_ADDR)

/**
 * @brief 检查所有EPWM外设
 *
 */
#define CHECK_EPWM_ALL_PERIPH(MODULE)                                                                                  \
    ((MODULE == EPWM11_PTR) || (MODULE == EPWM12_PTR) || (MODULE == EPWM13_PTR) || (MODULE == EPWM14_PTR) ||           \
     (MODULE == EPWM21_PTR) || (MODULE == EPWM22_PTR) || (MODULE == EPWM23_PTR) || (MODULE == EPWM24_PTR) ||           \
     (MODULE == EPWM31_PTR) || (MODULE == EPWM32_PTR) || (MODULE == EPWM33_PTR) || (MODULE == EPWM34_PTR))

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
