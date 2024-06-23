/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_gpio.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-15
 *  @Version         : V0.0.1.231207_alpha
 *  @Description     : This document describes the C language document template
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights .
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2023-12-15  |V1.0     |Sun Wanyu       | New Creat
 *****************************************************************************/

#ifndef KF32A13K_REG_GPIO_H_
#define KF32A13K_REG_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV    :8;  /*!< [7:0] 使能或禁止该模块的使能控制位  */
            __I uint32_t MODTYPE   :8;  /*!< [15:8] 模块类型  */
            __I uint32_t MODNUMBER :16; /*!< [31:16] 模块编号  */
        } bits;
        __I uint32_t reg;
    };
} GPIO_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN0  :1; /*!< [0:0] 主机TAGID0使能控制  */
            __IO uint32_t EN1  :1; /*!< [1:1] 主机TAGID1使能控制  */
            __IO uint32_t EN2  :1; /*!< [2:2] 主机TAGID2使能控制  */
            __IO uint32_t EN3  :1; /*!< [3:3] 主机TAGID3使能控制  */
            __IO uint32_t EN4  :1; /*!< [4:4] 主机TAGID4使能控制  */
            __IO uint32_t EN5  :1; /*!< [5:5] 主机TAGID5使能控制  */
            __IO uint32_t EN6  :1; /*!< [6:6] 主机TAGID6使能控制  */
            __IO uint32_t EN7  :1; /*!< [7:7] 主机TAGID7使能控制  */
            __IO uint32_t EN8  :1; /*!< [8:8] 主机TAGID8使能控制  */
            __IO uint32_t EN9  :1; /*!< [9:9] 主机TAGID9使能控制  */
            __IO uint32_t EN10 :1; /*!< [10:10] 主机TAGID10使能控制  */
            __IO uint32_t EN11 :1; /*!< [11:11] 主机TAGID11使能控制  */
            __IO uint32_t EN12 :1; /*!< [12:12] 主机TAGID12使能控制  */
            __IO uint32_t EN13 :1; /*!< [13:13] 主机TAGID13使能控制  */
            __IO uint32_t EN14 :1; /*!< [14:14] 主机TAGID14使能控制  */
            __IO uint32_t EN15 :1; /*!< [15:15] 主机TAGID15使能控制  */
            __IO uint32_t EN16 :1; /*!< [16:16] 主机TAGID16使能控制  */
            __IO uint32_t EN17 :1; /*!< [17:17] 主机TAGID17使能控制  */
            __IO uint32_t EN18 :1; /*!< [18:18] 主机TAGID18使能控制  */
            __IO uint32_t EN19 :1; /*!< [19:19] 主机TAGID19使能控制  */
            __IO uint32_t EN20 :1; /*!< [20:20] 主机TAGID20使能控制  */
            __IO uint32_t EN21 :1; /*!< [21:21] 主机TAGID21使能控制  */
            __IO uint32_t EN22 :1; /*!< [22:22] 主机TAGID22使能控制  */
            __IO uint32_t EN23 :1; /*!< [23:23] 主机TAGID23使能控制  */
            __IO uint32_t EN24 :1; /*!< [24:24] 主机TAGID24使能控制  */
            __IO uint32_t EN25 :1; /*!< [25:25] 主机TAGID25使能控制  */
            __IO uint32_t EN26 :1; /*!< [26:26] 主机TAGID26使能控制  */
            __IO uint32_t EN27 :1; /*!< [27:27] 主机TAGID27使能控制  */
            __IO uint32_t EN28 :1; /*!< [28:28] 主机TAGID28使能控制  */
            __IO uint32_t EN29 :1; /*!< [29:29] 主机TAGID29使能控制  */
            __IO uint32_t EN30 :1; /*!< [30:30] 主机TAGID30使能控制  */
            __IO uint32_t EN31 :1; /*!< [31:31] 主机TAGID31使能控制  */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED :32; /*!< [31:0] 预留，读取为0 */
        } bits;
        __I uint32_t reg;
    };
} GPIO_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t PXPIR0   :1;  /*!< [0:0] PIN口0输入电平提示  */
            __I uint32_t PXPIR1   :1;  /*!< [1:1] PIN口1输入电平提示  */
            __I uint32_t PXPIR2   :1;  /*!< [2:2] PIN口2输入电平提示  */
            __I uint32_t PXPIR3   :1;  /*!< [3:3] PIN口3输入电平提示  */
            __I uint32_t PXPIR4   :1;  /*!< [4:4] PIN口4输入电平提示  */
            __I uint32_t PXPIR5   :1;  /*!< [5:5] PIN口5输入电平提示  */
            __I uint32_t PXPIR6   :1;  /*!< [6:6] PIN口6输入电平提示  */
            __I uint32_t PXPIR7   :1;  /*!< [7:7] PIN口7输入电平提示  */
            __I uint32_t PXPIR8   :1;  /*!< [8:8] PIN口8输入电平提示  */
            __I uint32_t PXPIR9   :1;  /*!< [9:9] PIN口9输入电平提示  */
            __I uint32_t PXPIR10  :1;  /*!< [10:10] PIN口10输入电平提示  */
            __I uint32_t PXPIR11  :1;  /*!< [11:11] PIN口11输入电平提示  */
            __I uint32_t PXPIR12  :1;  /*!< [12:12] PIN口12输入电平提示  */
            __I uint32_t PXPIR13  :1;  /*!< [13:13] PIN口13输入电平提示  */
            __I uint32_t PXPIR14  :1;  /*!< [14:14] PIN口14输入电平提示  */
            __I uint32_t PXPIR15  :1;  /*!< [15:15] PIN口15输入电平提示  */
            __I uint32_t RESERVED :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_PIR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PXPOR0   :1;  /*!< [0:0] PIN0口输出电平配置  */
            __IO uint32_t PXPOR1   :1;  /*!< [1:1] PIN1口输出电平配置  */
            __IO uint32_t PXPOR2   :1;  /*!< [2:2] PIN2口输出电平配置  */
            __IO uint32_t PXPOR3   :1;  /*!< [3:3] PIN3口输出电平配置  */
            __IO uint32_t PXPOR4   :1;  /*!< [4:4] PIN4口输出电平配置  */
            __IO uint32_t PXPOR5   :1;  /*!< [5:5] PIN5口输出电平配置  */
            __IO uint32_t PXPOR6   :1;  /*!< [6:6] PIN6口输出电平配置  */
            __IO uint32_t PXPOR7   :1;  /*!< [7:7] PIN7口输出电平配置  */
            __IO uint32_t PXPOR8   :1;  /*!< [8:8] PIN8口输出电平配置  */
            __IO uint32_t PXPOR9   :1;  /*!< [9:9] PIN9口输出电平配置  */
            __IO uint32_t PXPOR10  :1;  /*!< [10:10] PIN10口输出电平配置  */
            __IO uint32_t PXPOR11  :1;  /*!< [11:11] PIN11口输出电平配置  */
            __IO uint32_t PXPOR12  :1;  /*!< [12:12] PIN12口输出电平配置  */
            __IO uint32_t PXPOR13  :1;  /*!< [13:13] PIN13口输出电平配置  */
            __IO uint32_t PXPOR14  :1;  /*!< [14:14] PIN14口输出电平配置  */
            __IO uint32_t PXPOR15  :1;  /*!< [15:15] PIN15口输出电平配置  */
            __I uint32_t  RESERVED :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t PS0  :1; /*!< [0:0] PXPOR0置位  */
            __O uint32_t PS1  :1; /*!< [1:1] PXPOR1置位  */
            __O uint32_t PS2  :1; /*!< [2:2] PXPOR2置位  */
            __O uint32_t PS3  :1; /*!< [3:3] PXPOR3置位  */
            __O uint32_t PS4  :1; /*!< [4:4] PXPOR4置位  */
            __O uint32_t PS5  :1; /*!< [5:5] PXPOR5置位  */
            __O uint32_t PS6  :1; /*!< [6:6] PXPOR6置位  */
            __O uint32_t PS7  :1; /*!< [7:7] PXPOR7置位  */
            __O uint32_t PS8  :1; /*!< [8:8] PXPOR8置位  */
            __O uint32_t PS9  :1; /*!< [9:9] PXPOR9置位  */
            __O uint32_t PS10 :1; /*!< [10:10] PXPOR10置位  */
            __O uint32_t PS11 :1; /*!< [11:11] PXPOR11置位  */
            __O uint32_t PS12 :1; /*!< [12:12] PXPOR12置位  */
            __O uint32_t PS13 :1; /*!< [13:13] PXPOR13置位  */
            __O uint32_t PS14 :1; /*!< [14:14] PXPOR14置位  */
            __O uint32_t PS15 :1; /*!< [15:15] PXPOR15置位  */
            __O uint32_t PC0  :1; /*!< [16:16] PXPOR0清零  */
            __O uint32_t PC1  :1; /*!< [17:17] PXPOR1清零  */
            __O uint32_t PC2  :1; /*!< [18:18] PXPOR2清零  */
            __O uint32_t PC3  :1; /*!< [19:19] PXPOR3清零  */
            __O uint32_t PC4  :1; /*!< [20:20] PXPOR4清零  */
            __O uint32_t PC5  :1; /*!< [21:21] PXPOR5清零  */
            __O uint32_t PC6  :1; /*!< [22:22] PXPOR6清零  */
            __O uint32_t PC7  :1; /*!< [23:23] PXPOR7清零  */
            __O uint32_t PC8  :1; /*!< [24:24] PXPOR8清零  */
            __O uint32_t PC9  :1; /*!< [25:25] PXPOR9清零  */
            __O uint32_t PC10 :1; /*!< [26:26] PXPOR10清零  */
            __O uint32_t PC11 :1; /*!< [27:27] PXPOR11清零  */
            __O uint32_t PC12 :1; /*!< [28:28] PXPOR12清零  */
            __O uint32_t PC13 :1; /*!< [29:29] PXPOR13清零  */
            __O uint32_t PC14 :1; /*!< [30:30] PXPOR14清零  */
            __O uint32_t PC15 :1; /*!< [31:31] PXPOR15清零  */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POSCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t PS0      :1;  /*!< [0:0] PXPOR0置位  */
            __O uint32_t PS1      :1;  /*!< [1:1] PXPOR1置位  */
            __O uint32_t PS2      :1;  /*!< [2:2] PXPOR2置位  */
            __O uint32_t PS3      :1;  /*!< [3:3] PXPOR3置位  */
            __O uint32_t PS4      :1;  /*!< [4:4] PXPOR4置位  */
            __O uint32_t PS5      :1;  /*!< [5:5] PXPOR5置位  */
            __O uint32_t PS6      :1;  /*!< [6:6] PXPOR6置位  */
            __O uint32_t PS7      :1;  /*!< [7:7] PXPOR7置位  */
            __O uint32_t PS8      :1;  /*!< [8:8] PXPOR8置位  */
            __O uint32_t PS9      :1;  /*!< [9:9] PXPOR9置位  */
            __O uint32_t PS10     :1;  /*!< [10:10] PXPOR10置位  */
            __O uint32_t PS11     :1;  /*!< [11:11] PXPOR11置位  */
            __O uint32_t PS12     :1;  /*!< [12:12] PXPOR12置位  */
            __O uint32_t PS13     :1;  /*!< [13:13] PXPOR13置位  */
            __O uint32_t PS14     :1;  /*!< [14:14] PXPOR14置位  */
            __O uint32_t PS15     :1;  /*!< [15:15] PXPOR15置位  */
            __I uint32_t RESERVED :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POSR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t PS0      :1;  /*!< [0:0] PXPOR0置位  */
            __O uint32_t PS1      :1;  /*!< [1:1] PXPOR1置位  */
            __O uint32_t PS2      :1;  /*!< [2:2] PXPOR2置位  */
            __O uint32_t PS3      :1;  /*!< [3:3] PXPOR3置位  */
            __I uint32_t RESERVED :28; /*!< [31:4] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POSR0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :4;  /*!< [3:0] 预留，读取为0 */
            __O uint32_t PS4       :1;  /*!< [4:4] PXPOR4置位  */
            __O uint32_t PS5       :1;  /*!< [5:5] PXPOR5置位  */
            __O uint32_t PS6       :1;  /*!< [6:6] PXPOR6置位  */
            __O uint32_t PS7       :1;  /*!< [7:7] PXPOR7置位  */
            __I uint32_t RESERVED1 :24; /*!< [31:8] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POSR4_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :8;  /*!< [7:0] 预留，读取为0 */
            __O uint32_t PS8       :1;  /*!< [8:8] PXPOR8置位  */
            __O uint32_t PS9       :1;  /*!< [9:9] PXPOR9置位  */
            __O uint32_t PS10      :1;  /*!< [10:10] PXPOR10置位  */
            __O uint32_t PS11      :1;  /*!< [11:11] PXPOR11置位  */
            __I uint32_t RESERVED1 :20; /*!< [31:12] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POSR8_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :12; /*!< [11:0] 预留，读取为0 */
            __O uint32_t PS12      :1;  /*!< [12:12] PXPOR12置位  */
            __O uint32_t PS13      :1;  /*!< [13:13] PXPOR13置位  */
            __O uint32_t PS14      :1;  /*!< [14:14] PXPOR14置位  */
            __O uint32_t PS15      :1;  /*!< [15:15] PXPOR15置位  */
            __I uint32_t RESERVED1 :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POSR12_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED :16; /*!< [15:0] 预留，读取为0 */
            __O uint32_t PC0      :1;  /*!< [16:16] PXPOR0清零  */
            __O uint32_t PC1      :1;  /*!< [17:17] PXPOR1清零  */
            __O uint32_t PC2      :1;  /*!< [18:18] PXPOR2清零  */
            __O uint32_t PC3      :1;  /*!< [19:19] PXPOR3清零  */
            __O uint32_t PC4      :1;  /*!< [20:20] PXPOR4清零  */
            __O uint32_t PC5      :1;  /*!< [21:21] PXPOR5清零  */
            __O uint32_t PC6      :1;  /*!< [22:22] PXPOR6清零  */
            __O uint32_t PC7      :1;  /*!< [23:23] PXPOR7清零  */
            __O uint32_t PC8      :1;  /*!< [24:24] PXPOR8清零  */
            __O uint32_t PC9      :1;  /*!< [25:25] PXPOR9清零  */
            __O uint32_t PC10     :1;  /*!< [26:26] PXPOR10清零  */
            __O uint32_t PC11     :1;  /*!< [27:27] PXPOR11清零  */
            __O uint32_t PC12     :1;  /*!< [28:28] PXPOR12清零  */
            __O uint32_t PC13     :1;  /*!< [29:29] PXPOR13清零  */
            __O uint32_t PC14     :1;  /*!< [30:30] PXPOR14清零  */
            __O uint32_t PC15     :1;  /*!< [31:31] PXPOR15清零  */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :16; /*!< [15:0] 预留，读取为0 */
            __O uint32_t PC0       :1;  /*!< [16:16] PXPOR0清零  */
            __O uint32_t PC1       :1;  /*!< [17:17] PXPOR1清零  */
            __O uint32_t PC2       :1;  /*!< [18:18] PXPOR2清零  */
            __O uint32_t PC3       :1;  /*!< [19:19] PXPOR3清零  */
            __I uint32_t RESERVED1 :12; /*!< [31:20] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POCR0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :20; /*!< [19:0] 预留，读取为0 */
            __O uint32_t PC4       :1;  /*!< [20:20] PXPOR4清零  */
            __O uint32_t PC5       :1;  /*!< [21:21] PXPOR5清零  */
            __O uint32_t PC6       :1;  /*!< [22:22] PXPOR6清零  */
            __O uint32_t PC7       :1;  /*!< [23:23] PXPOR7清零  */
            __I uint32_t RESERVED1 :8;  /*!< [31:24] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POCR4_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :24; /*!< [23:0] 预留，读取为0 */
            __O uint32_t PC8       :1;  /*!< [24:24] PXPOR8清零  */
            __O uint32_t PC9       :1;  /*!< [25:25] PXPOR9清零  */
            __O uint32_t PC10      :1;  /*!< [26:26] PXPOR10清零  */
            __O uint32_t PC11      :1;  /*!< [27:27] PXPOR11清零  */
            __I uint32_t RESERVED1 :4;  /*!< [31:28] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POCR8_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED :28; /*!< [27:0] 预留，读取为0 */
            __O uint32_t PC12     :1;  /*!< [28:28] PXPOR12清零  */
            __O uint32_t PC13     :1;  /*!< [29:29] PXPOR13清零  */
            __O uint32_t PC14     :1;  /*!< [30:30] PXPOR14清零  */
            __O uint32_t PC15     :1;  /*!< [31:31] PXPOR15清零  */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_POCR12_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PXPUDEN0  :2; /*!< [1:0] PIN0口上下拉使能  */
            __IO uint32_t PXPUDEN1  :2; /*!< [3:2] PIN1口上下拉使能  */
            __IO uint32_t PXPUDEN2  :2; /*!< [5:4] PIN2口上下拉使能  */
            __IO uint32_t PXPUDEN3  :2; /*!< [7:6] PIN3口上下拉使能  */
            __IO uint32_t PXPUDEN4  :2; /*!< [9:8] PIN4口上下拉使能  */
            __IO uint32_t PXPUDEN5  :2; /*!< [11:10] PIN5口上下拉使能  */
            __IO uint32_t PXPUDEN6  :2; /*!< [13:12] PIN6口上下拉使能  */
            __IO uint32_t PXPUDEN7  :2; /*!< [15:14] PIN7口上下拉使能  */
            __IO uint32_t PXPUDEN8  :2; /*!< [17:16] PIN8口上下拉使能  */
            __IO uint32_t PXPUDEN9  :2; /*!< [19:18] PIN9口上下拉使能  */
            __IO uint32_t PXPUDEN10 :2; /*!< [21:20] PIN10口上下拉使能  */
            __IO uint32_t PXPUDEN11 :2; /*!< [23:22] PIN11口上下拉使能  */
            __IO uint32_t PXPUDEN12 :2; /*!< [25:24] PIN12口上下拉使能  */
            __IO uint32_t PXPUDEN13 :2; /*!< [27:26] PIN13口上下拉使能  */
            __IO uint32_t PXPUDEN14 :2; /*!< [29:28] PIN14口上下拉使能  */
            __IO uint32_t PXPUDEN15 :2; /*!< [31:30] PIN15口上下拉使能  */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_PUDEN_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PXPODR0  :1;  /*!< [0:0] pin0口输出模式选择  */
            __IO uint32_t PXPODR1  :1;  /*!< [1:1] pin1口输出模式选择  */
            __IO uint32_t PXPODR2  :1;  /*!< [2:2] pin2口输出模式选择  */
            __IO uint32_t PXPODR3  :1;  /*!< [3:3] pin3口输出模式选择  */
            __IO uint32_t PXPODR4  :1;  /*!< [4:4] pin4口输出模式选择  */
            __IO uint32_t PXPODR5  :1;  /*!< [5:5] pin5口输出模式选择  */
            __IO uint32_t PXPODR6  :1;  /*!< [6:6] pin6口输出模式选择  */
            __IO uint32_t PXPODR7  :1;  /*!< [7:7] pin7口输出模式选择  */
            __IO uint32_t PXPODR8  :1;  /*!< [8:8] pin8口输出模式选择  */
            __IO uint32_t PXPODR9  :1;  /*!< [9:9] pin9口输出模式选择  */
            __IO uint32_t PXPODR10 :1;  /*!< [10:10] pin10口输出模式选择  */
            __IO uint32_t PXPODR11 :1;  /*!< [11:11] pin11口输出模式选择  */
            __IO uint32_t PXPODR12 :1;  /*!< [12:12] pin12口输出模式选择  */
            __IO uint32_t PXPODR13 :1;  /*!< [13:13] pin13口输出模式选择  */
            __IO uint32_t PXPODR14 :1;  /*!< [14:14] pin14口输出模式选择  */
            __IO uint32_t PXPODR15 :1;  /*!< [15:15] pin15口输出模式选择  */
            __I uint32_t  RESERVED :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_PODR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PXMOD0  :2; /*!< [1:0] PIN0口输出使能控制  */
            __IO uint32_t PXMOD1  :2; /*!< [3:2] PIN1口输出使能控制  */
            __IO uint32_t PXMOD2  :2; /*!< [5:4] PIN2口输出使能控制  */
            __IO uint32_t PXMOD3  :2; /*!< [7:6] PIN3口输出使能控制  */
            __IO uint32_t PXMOD4  :2; /*!< [9:8] PIN4口输出使能控制  */
            __IO uint32_t PXMOD5  :2; /*!< [11:10] PIN5口输出使能控制  */
            __IO uint32_t PXMOD6  :2; /*!< [13:12] PIN6口输出使能控制  */
            __IO uint32_t PXMOD7  :2; /*!< [15:14] PIN7口输出使能控制  */
            __IO uint32_t PXMOD8  :2; /*!< [17:16] PIN8口输出使能控制  */
            __IO uint32_t PXMOD9  :2; /*!< [19:18] PIN9口输出使能控制  */
            __IO uint32_t PXMOD10 :2; /*!< [21:20] PIN10口输出使能控制  */
            __IO uint32_t PXMOD11 :2; /*!< [23:22] PIN11口输出使能控制  */
            __IO uint32_t PXMOD12 :2; /*!< [25:24] PIN12口输出使能控制  */
            __IO uint32_t PXMOD13 :2; /*!< [27:26] PIN13口输出使能控制  */
            __IO uint32_t PXMOD14 :2; /*!< [29:28] PIN14口输出使能控制  */
            __IO uint32_t PXMOD15 :2; /*!< [31:30] PIN15口输出使能控制  */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_PMOD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OUTSEL0 :4; /*!< [3:0] PIN0口输出重映射选择  */
            __IO uint32_t OUTSEL1 :4; /*!< [7:4] PIN1口输出重映射选择  */
            __IO uint32_t OUTSEL2 :4; /*!< [11:8] PIN2口输出重映射选择  */
            __IO uint32_t OUTSEL3 :4; /*!< [15:12] PIN3口输出重映射选择  */
            __IO uint32_t OUTSEL4 :4; /*!< [19:16] PIN4口输出重映射选择  */
            __IO uint32_t OUTSEL5 :4; /*!< [23:20] PIN5口输出重映射选择  */
            __IO uint32_t OUTSEL6 :4; /*!< [27:24] PIN6口输出重映射选择  */
            __IO uint32_t OUTSEL7 :4; /*!< [31:28] PIN7口输出重映射选择  */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_PEROUT0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OUTSEL8  :4; /*!< [3:0] PIN8口输出重映射选择  */
            __IO uint32_t OUTSEL9  :4; /*!< [7:4] PIN9口输出重映射选择  */
            __IO uint32_t OUTSEL10 :4; /*!< [11:8] PIN10口输出重映射选择  */
            __IO uint32_t OUTSEL11 :4; /*!< [15:12] PIN11口输出重映射选择  */
            __IO uint32_t OUTSEL12 :4; /*!< [19:16] PIN12口输出重映射选择  */
            __IO uint32_t OUTSEL13 :4; /*!< [23:20] PIN13口输出重映射选择  */
            __IO uint32_t OUTSEL14 :4; /*!< [27:24] PIN14口输出重映射选择  */
            __IO uint32_t OUTSEL15 :4; /*!< [31:28] PIN15口输出重映射选择  */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_PEROUT1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PXPD0     :2; /*!< [1:0] pin0口驱动模式选择  */
            __I uint32_t  RESERVED  :2; /*!< [3:2] 预留，读取为0   */
            __IO uint32_t PXPD1     :2; /*!< [5:4] pin1口驱动模式选择  */
            __I uint32_t  RESERVED1 :2; /*!< [7:6] 预留，读取为0   */
            __IO uint32_t PXPD2     :2; /*!< [9:8] pin2口驱动模式选择  */
            __I uint32_t  RESERVED2 :2; /*!< [11:10] 预留，读取为0   */
            __IO uint32_t PXPD3     :2; /*!< [13:12] pin3口驱动模式选择  */
            __I uint32_t  RESERVED3 :2; /*!< [15:14] 预留，读取为0   */
            __IO uint32_t PXPD4     :2; /*!< [17:16] pin4口驱动模式选择  */
            __I uint32_t  RESERVED4 :2; /*!< [19:18] 预留，读取为0   */
            __IO uint32_t PXPD5     :2; /*!< [21:20] pin5口驱动模式选择  */
            __I uint32_t  RESERVED5 :2; /*!< [23:22] 预留，读取为0   */
            __IO uint32_t PXPD6     :2; /*!< [25:24] pin6口驱动模式选择  */
            __I uint32_t  RESERVED6 :2; /*!< [27:26] 预留，读取为0   */
            __IO uint32_t PXPD7     :2; /*!< [29:28] pin7口驱动模式选择  */
            __I uint32_t  RESERVED7 :2; /*!< [31:30] 预留，读取为0   */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_PDR0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PXPD8     :2; /*!< [1:0] pin8口驱动模式选择  */
            __I uint32_t  RESERVED  :2; /*!< [3:2] 预留，读取为0  */
            __IO uint32_t PXPD9     :2; /*!< [5:4] pin9口驱动模式选择  */
            __I uint32_t  RESERVED1 :2; /*!< [7:6] 预留，读取为0  */
            __IO uint32_t PXPD10    :2; /*!< [9:8] pin10口驱动模式选择  */
            __I uint32_t  RESERVED2 :2; /*!< [11:10] 预留，读取为0  */
            __IO uint32_t PXPD11    :2; /*!< [13:12] pin11口驱动模式选择  */
            __I uint32_t  RESERVED3 :2; /*!< [15:14] 预留，读取为0  */
            __IO uint32_t PXPD12    :2; /*!< [17:16] pin12口驱动模式选择  */
            __I uint32_t  RESERVED4 :2; /*!< [19:18] 预留，读取为0  */
            __IO uint32_t PXPD13    :2; /*!< [21:20] pin13口驱动模式选择  */
            __I uint32_t  RESERVED5 :2; /*!< [23:22] 预留，读取为0  */
            __IO uint32_t PXPD14    :2; /*!< [25:24] pin14口驱动模式选择  */
            __I uint32_t  RESERVED6 :2; /*!< [27:26] 预留，读取为0  */
            __IO uint32_t PXPD15    :2; /*!< [29:28] pin15口驱动模式选择  */
            __I uint32_t  RESERVED7 :2; /*!< [31:30] 预留，读取为0  */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_PDR1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SDEN0  :1; /*!< [0:0] PIN0自检功能使能位  */
            __IO uint32_t SDEN1  :1; /*!< [1:1] PIN1自检功能使能位  */
            __IO uint32_t SDEN2  :1; /*!< [2:2] PIN2自检功能使能位  */
            __IO uint32_t SDEN3  :1; /*!< [3:3] PIN3自检功能使能位  */
            __IO uint32_t SDEN4  :1; /*!< [4:4] PIN4自检功能使能位  */
            __IO uint32_t SDEN5  :1; /*!< [5:5] PIN5自检功能使能位  */
            __IO uint32_t SDEN6  :1; /*!< [6:6] PIN6自检功能使能位  */
            __IO uint32_t SDEN7  :1; /*!< [7:7] PIN7自检功能使能位  */
            __IO uint32_t SDEN8  :1; /*!< [8:8] PIN8自检功能使能位  */
            __IO uint32_t SDEN9  :1; /*!< [9:9] PIN9自检功能使能位  */
            __IO uint32_t SDEN10 :1; /*!< [10:10] PIN10自检功能使能位  */
            __IO uint32_t SDEN11 :1; /*!< [11:11] PIN11自检功能使能位  */
            __IO uint32_t SDEN12 :1; /*!< [12:12] PIN12自检功能使能位  */
            __IO uint32_t SDEN13 :1; /*!< [13:13] PIN13自检功能使能位  */
            __IO uint32_t SDEN14 :1; /*!< [14:14] PIN14自检功能使能位  */
            __IO uint32_t SDEN15 :1; /*!< [15:15] PIN15自检功能使能位  */
            __I uint32_t  SDEF0  :1; /*!< [16:16] PIN0自检标志位  */
            __I uint32_t  SDEF1  :1; /*!< [17:17] PIN1自检标志位  */
            __I uint32_t  SDEF2  :1; /*!< [18:18] PIN2自检标志位  */
            __I uint32_t  SDEF3  :1; /*!< [19:19] PIN3自检标志位  */
            __I uint32_t  SDEF4  :1; /*!< [20:20] PIN4自检标志位  */
            __I uint32_t  SDEF5  :1; /*!< [21:21] PIN5自检标志位  */
            __I uint32_t  SDEF6  :1; /*!< [22:22] PIN6自检标志位  */
            __I uint32_t  SDEF7  :1; /*!< [23:23] PIN7自检标志位  */
            __I uint32_t  SDEF8  :1; /*!< [24:24] PIN8自检标志位  */
            __I uint32_t  SDEF9  :1; /*!< [25:25] PIN9自检标志位  */
            __I uint32_t  SDEF10 :1; /*!< [26:26] PIN10自检标志位  */
            __I uint32_t  SDEF11 :1; /*!< [27:27] PIN11自检标志位  */
            __I uint32_t  SDEF12 :1; /*!< [28:28] PIN12自检标志位  */
            __I uint32_t  SDEF13 :1; /*!< [29:29] PIN13自检标志位  */
            __I uint32_t  SDEF14 :1; /*!< [30:30] PIN14自检标志位  */
            __I uint32_t  SDEF15 :1; /*!< [31:31] PIN15自检标志位  */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_SDE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  SWTRIG   :1;  /*!< [0:0] 软件采样触发位，硬件自动清零  */
            __IO uint32_t LINKEN   :1;  /*!< [1:1] LINK功能使能位  */
            __IO uint32_t PSDEF    :1;  /*!< [2:2] 整个PORST自检总标志位  */
            __I uint32_t  RESERVED :29; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_SDCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN0      :1;  /*!< [0:0] PIN0口紧急停止功能使能控制  */
            __IO uint32_t EN1      :1;  /*!< [1:1] PIN1口紧急停止功能使能控制  */
            __IO uint32_t EN2      :1;  /*!< [2:2] PIN2口紧急停止功能使能控制  */
            __IO uint32_t EN3      :1;  /*!< [3:3] PIN3口紧急停止功能使能控制  */
            __IO uint32_t EN4      :1;  /*!< [4:4] PIN4口紧急停止功能使能控制  */
            __IO uint32_t EN5      :1;  /*!< [5:5] PIN5口紧急停止功能使能控制  */
            __IO uint32_t EN6      :1;  /*!< [6:6] PIN6口紧急停止功能使能控制  */
            __IO uint32_t EN7      :1;  /*!< [7:7] PIN7口紧急停止功能使能控制  */
            __IO uint32_t EN8      :1;  /*!< [8:8] PIN8口紧急停止功能使能控制  */
            __IO uint32_t EN9      :1;  /*!< [9:9] PIN9口紧急停止功能使能控制  */
            __IO uint32_t EN10     :1;  /*!< [10:10] PIN10口紧急停止功能使能控制  */
            __IO uint32_t EN11     :1;  /*!< [11:11] PIN11口紧急停止功能使能控制  */
            __IO uint32_t EN12     :1;  /*!< [12:12] PIN12口紧急停止功能使能控制  */
            __IO uint32_t EN13     :1;  /*!< [13:13] PIN13口紧急停止功能使能控制  */
            __IO uint32_t EN14     :1;  /*!< [14:14] PIN14口紧急停止功能使能控制  */
            __IO uint32_t EN15     :1;  /*!< [15:15] PIN15口紧急停止功能使能控制  */
            __I uint32_t  RESERVED :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_ESR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t P0LCK    :1;  /*!< [0:0] PIN0口锁定控制  */
            __IO uint32_t P1LCK    :1;  /*!< [1:1] PIN1口锁定控制  */
            __IO uint32_t P2LCK    :1;  /*!< [2:2] PIN2口锁定控制  */
            __IO uint32_t P3LCK    :1;  /*!< [3:3] PIN3口锁定控制  */
            __IO uint32_t P4LCK    :1;  /*!< [4:4] PIN4口锁定控制  */
            __IO uint32_t P5LCK    :1;  /*!< [5:5] PIN5口锁定控制  */
            __IO uint32_t P6LCK    :1;  /*!< [6:6] PIN6口锁定控制  */
            __IO uint32_t P7LCK    :1;  /*!< [7:7] PIN7口锁定控制  */
            __IO uint32_t P8LCK    :1;  /*!< [8:8] PIN8口锁定控制  */
            __IO uint32_t P9LCK    :1;  /*!< [9:9] PIN9口锁定控制  */
            __IO uint32_t P10LCK   :1;  /*!< [10:10] PIN10口锁定控制  */
            __IO uint32_t P11LCK   :1;  /*!< [11:11] PIN11口锁定控制  */
            __IO uint32_t P12LCK   :1;  /*!< [12:12] PIN12口锁定控制  */
            __IO uint32_t P13LCK   :1;  /*!< [13:13] PIN13口锁定控制  */
            __IO uint32_t P14LCK   :1;  /*!< [14:14] PIN14口锁定控制  */
            __IO uint32_t P15LCK   :1;  /*!< [15:15] PIN15口锁定控制  */
            __O uint32_t  PXLCKKEY :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_LOCK_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TGSEL0   :1;  /*!< [0:0] PIN0自检触发模式选择  */
            __IO uint32_t TGSEL1   :1;  /*!< [1:1] PIN1自检触发模式选择  */
            __IO uint32_t TGSEL2   :1;  /*!< [2:2] PIN2自检触发模式选择  */
            __IO uint32_t TGSEL3   :1;  /*!< [3:3] PIN3自检触发模式选择  */
            __IO uint32_t TGSEL4   :1;  /*!< [4:4] PIN4自检触发模式选择  */
            __IO uint32_t TGSEL5   :1;  /*!< [5:5] PIN5自检触发模式选择  */
            __IO uint32_t TGSEL6   :1;  /*!< [6:6] PIN6自检触发模式选择  */
            __IO uint32_t TGSEL7   :1;  /*!< [7:7] PIN7自检触发模式选择  */
            __IO uint32_t TGSEL8   :1;  /*!< [8:8] PIN8自检触发模式选择  */
            __IO uint32_t TGSEL9   :1;  /*!< [9:9] PIN9自检触发模式选择  */
            __IO uint32_t TGSEL10  :1;  /*!< [10:10] PIN10自检触发模式选择  */
            __IO uint32_t TGSEL11  :1;  /*!< [11:11] PIN11自检触发模式选择  */
            __IO uint32_t TGSEL12  :1;  /*!< [12:12] PIN12自检触发模式选择  */
            __IO uint32_t TGSEL13  :1;  /*!< [13:13] PIN13自检触发模式选择  */
            __IO uint32_t TGSEL14  :1;  /*!< [14:14] PIN14自检触发模式选择  */
            __IO uint32_t TGSEL15  :1;  /*!< [15:15] PIN15自检触发模式选择  */
            __I uint32_t  RESERVED :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_SDETRMOD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SEL0     :1;  /*!< [0:0] PIN0口硬件控制使能  */
            __IO uint32_t SEL1     :1;  /*!< [1:1] PIN1口硬件控制使能  */
            __IO uint32_t SEL2     :1;  /*!< [2:2] PIN2口硬件控制使能  */
            __IO uint32_t SEL3     :1;  /*!< [3:3] PIN3口硬件控制使能  */
            __IO uint32_t SEL4     :1;  /*!< [4:4] PIN4口硬件控制使能  */
            __IO uint32_t SEL5     :1;  /*!< [5:5] PIN5口硬件控制使能  */
            __IO uint32_t SEL6     :1;  /*!< [6:6] PIN6口硬件控制使能  */
            __IO uint32_t SEL7     :1;  /*!< [7:7] PIN7口硬件控制使能  */
            __IO uint32_t SEL8     :1;  /*!< [8:8] PIN8口硬件控制使能  */
            __IO uint32_t SEL9     :1;  /*!< [9:9] PIN9口硬件控制使能  */
            __IO uint32_t SEL10    :1;  /*!< [10:10] PIN10口硬件控制使能  */
            __IO uint32_t SEL11    :1;  /*!< [11:11] PIN11口硬件控制使能  */
            __IO uint32_t SEL12    :1;  /*!< [12:12] PIN12口硬件控制使能  */
            __IO uint32_t SEL13    :1;  /*!< [13:13] PIN13口硬件控制使能  */
            __IO uint32_t SEL14    :1;  /*!< [14:14] PIN14口硬件控制使能  */
            __IO uint32_t SEL15    :1;  /*!< [15:15] PIN15口硬件控制使能  */
            __I uint32_t  RESERVED :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_PCSR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t INEN0    :1;  /*!< [0:0] PIN0口输入使能  */
            __IO uint32_t INEN1    :1;  /*!< [1:1] PIN1口输入使能  */
            __IO uint32_t INEN2    :1;  /*!< [2:2] PIN2口输入使能  */
            __IO uint32_t INEN3    :1;  /*!< [3:3] PIN3口输入使能  */
            __IO uint32_t INEN4    :1;  /*!< [4:4] PIN4口输入使能  */
            __IO uint32_t INEN5    :1;  /*!< [5:5] PIN5口输入使能  */
            __IO uint32_t INEN6    :1;  /*!< [6:6] PIN6口输入使能  */
            __IO uint32_t INEN7    :1;  /*!< [7:7] PIN7口输入使能  */
            __IO uint32_t INEN8    :1;  /*!< [8:8] PIN8口输入使能  */
            __IO uint32_t INEN9    :1;  /*!< [9:9] PIN9口输入使能  */
            __IO uint32_t INEN10   :1;  /*!< [10:10] PIN10口输入使能  */
            __IO uint32_t INEN11   :1;  /*!< [11:11] PIN11口输入使能  */
            __IO uint32_t INEN12   :1;  /*!< [12:12] PIN12口输入使能  */
            __IO uint32_t INEN13   :1;  /*!< [13:13] PIN13口输入使能  */
            __IO uint32_t INEN14   :1;  /*!< [14:14] PIN14口输入使能  */
            __IO uint32_t INEN15   :1;  /*!< [15:15] PIN15口输入使能  */
            __I uint32_t  RESERVED :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_INEN_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PDSEL0   :1;  /*!< [0:0] 特定GPIO口对应的寄存器GPIO_PUDEN0复位值控制  */
            __IO uint32_t PDSEL1   :1;  /*!< [1:1] 特定GPIO口对应的寄存器GPIO_PUDEN1复位值控制  */
            __IO uint32_t PDSEL2   :1;  /*!< [2:2] 特定GPIO口对应的寄存器GPIO_PUDEN2复位值控制  */
            __IO uint32_t PDSEL3   :1;  /*!< [3:3] 特定GPIO口对应的寄存器GPIO_PUDEN3复位值控制  */
            __IO uint32_t PDSEL4   :1;  /*!< [4:4] 特定GPIO口对应的寄存器GPIO_PUDEN4复位值控制  */
            __IO uint32_t PDSEL5   :1;  /*!< [5:5] 特定GPIO口对应的寄存器GPIO_PUDEN5复位值控制  */
            __IO uint32_t PDSEL6   :1;  /*!< [6:6] 特定GPIO口对应的寄存器GPIO_PUDEN6复位值控制  */
            __IO uint32_t PDSEL7   :1;  /*!< [7:7] 特定GPIO口对应的寄存器GPIO_PUDEN7复位值控制  */
            __IO uint32_t PDSEL8   :1;  /*!< [8:8] 特定GPIO口对应的寄存器GPIO_PUDEN8复位值控制  */
            __IO uint32_t PDSEL9   :1;  /*!< [9:9] 特定GPIO口对应的寄存器GPIO_PUDEN9复位值控制  */
            __IO uint32_t PDSEL10  :1;  /*!< [10:10] 特定GPIO口对应的寄存器GPIO_PUDEN10复位值控制  */
            __IO uint32_t PDSEL11  :1;  /*!< [11:11] 特定GPIO口对应的寄存器GPIO_PUDEN11复位值控制  */
            __IO uint32_t PDSEL12  :1;  /*!< [12:12] 特定GPIO口对应的寄存器GPIO_PUDEN12复位值控制  */
            __IO uint32_t PDSEL13  :1;  /*!< [13:13] 特定GPIO口对应的寄存器GPIO_PUDEN13复位值控制  */
            __IO uint32_t PDSEL14  :1;  /*!< [14:14] 特定GPIO口对应的寄存器GPIO_PUDEN14复位值控制  */
            __IO uint32_t PDSEL15  :1;  /*!< [15:15] 特定GPIO口对应的寄存器GPIO_PUDEN15复位值控制  */
            __I uint32_t  RESERVED :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_PUDRST_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CTLEN0   :1;  /*!< [0:0] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN1   :1;  /*!< [1:1] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN2   :1;  /*!< [2:2] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN3   :1;  /*!< [3:3] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN4   :1;  /*!< [4:4] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN5   :1;  /*!< [5:5] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN6   :1;  /*!< [6:6] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN7   :1;  /*!< [7:7] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN8   :1;  /*!< [8:8] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN9   :1;  /*!< [9:9] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN10  :1;  /*!< [10:10] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN11  :1;  /*!< [11:11] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN12  :1;  /*!< [12:12] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN13  :1;  /*!< [13:13] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN14  :1;  /*!< [14:14] 硬件外设IP控制GPIO上下拉控制  */
            __IO uint32_t CTLEN15  :1;  /*!< [15:15] 硬件外设IP控制GPIO上下拉控制  */
            __I uint32_t  RESERVED :16; /*!< [31:16] 预留，读取为0 */
        } bits;
        __IO uint32_t reg;
    };
} GPIO_HWPUDEN_T;

typedef volatile struct
{
    /* address offset  : 0x0000.  */
    GPIO_INFO_T GPIO_INFO;
    /* address offset  : 0x0004.  */
    GPIO_ACES0_T GPIO_ACES0;
    /* address offset  : 0x0008.  */
    GPIO_ACES1_T GPIO_ACES1;
    /* address offset  : 0x000C.  */
    GPIO_PIR_T GPIO_PIR;
    /* address offset  : 0x0010.  */
    GPIO_POR_T GPIO_POR;
    /* address offset  : 0x0014.  */
    GPIO_POSCR_T GPIO_POSCR;
    /* address offset  : 0x0018.  */
    GPIO_POSR_T GPIO_POSR;
    /* address offset  : 0x001C.  */
    GPIO_POSR0_T GPIO_POSR0;
    /* address offset  : 0x0020.  */
    GPIO_POSR4_T GPIO_POSR4;
    /* address offset  : 0x0024.  */
    GPIO_POSR8_T GPIO_POSR8;
    /* address offset  : 0x0028.  */
    GPIO_POSR12_T GPIO_POSR12;
    /* address offset  : 0x002C.  */
    GPIO_POCR_T GPIO_POCR;
    /* address offset  : 0x0030.  */
    GPIO_POCR0_T GPIO_POCR0;
    /* address offset  : 0x0034.  */
    GPIO_POCR4_T GPIO_POCR4;
    /* address offset  : 0x0038.  */
    GPIO_POCR8_T GPIO_POCR8;
    /* address offset  : 0x003C.  */
    GPIO_POCR12_T GPIO_POCR12;
    /* address offset  : 0x0040.  */
    GPIO_PUDEN_T GPIO_PUDEN;
    /* address offset  : 0x0044.  */
    GPIO_PODR_T GPIO_PODR;
    /* address offset  : 0x0048.  */
    GPIO_PMOD_T GPIO_PMOD;
    /* address offset  : 0x004C.  */
    GPIO_PEROUT0_T GPIO_PEROUT0;
    /* address offset  : 0x0050.  */
    GPIO_PEROUT1_T GPIO_PEROUT1;
    /* address offset  : 0x0054.  */
    GPIO_PDR0_T GPIO_PDR0;
    /* address offset  : 0x0058.  */
    GPIO_PDR1_T GPIO_PDR1;
    /* address offset  : 0x005C.  */
    uint32_t RESERVED0;
    /* address offset  : 0x0060.  */
    uint32_t RESERVED1;
    /* address offset  : 0x0064.  */
    GPIO_ESR_T GPIO_ESR;
    /* address offset  : 0x0068.  */
    GPIO_LOCK_T GPIO_LOCK;
    /* address offset  : 0x006C.  */
    GPIO_LOCK_T GPIO_SDETRMOD;
    /* address offset  : 0x0070.  */
    GPIO_PCSR_T GPIO_PCSR;
    /* address offset  : 0x0074.  */
    GPIO_INEN_T GPIO_INEN;
    /* address offset  : 0x0078.  */
    GPIO_PUDRST_T GPIO_PUDRST;
    /* address offset  : 0x007C.  */
    GPIO_HWPUDEN_T GPIO_HWPUDEN;
} Gpio_RegisterMap_t;

#define GPIO0_ADDR  ((uint32_t)0xF0010000)
#define GPIO1_ADDR  ((uint32_t)0xF00100FF)
#define GPIO2_ADDR  ((uint32_t)0xF00101FE)
#define GPIO3_ADDR  ((uint32_t)0xF00102FD)
#define GPIO4_ADDR  ((uint32_t)0xF00103FC)
#define GPIO5_ADDR  ((uint32_t)0xF00104FB)
#define GPIO6_ADDR  ((uint32_t)0xF00105FA)
#define GPIO7_ADDR  ((uint32_t)0xF00106F9)
#define GPIO8_ADDR  ((uint32_t)0xF00107F8)
#define GPIO9_ADDR  ((uint32_t)0xF00108F7)
#define GPIO10_ADDR ((uint32_t)0xF00109F6)
#define GPIO11_ADDR ((uint32_t)0xF0010AF5)
#define GPIO12_ADDR ((uint32_t)0xF0010BF4)
#define GPIO13_ADDR ((uint32_t)0xF0010CF3)
#define GPIO14_ADDR ((uint32_t)0xF0010DF2)
#define GPIO15_ADDR ((uint32_t)0xF0010EF1)
#define GPIO16_ADDR ((uint32_t)0xF0010FF0)
#define GPIO17_ADDR ((uint32_t)0xF00110EF)
#define GPIO18_ADDR ((uint32_t)0xF00111EE)
#define GPIO19_ADDR ((uint32_t)0xF00112ED)
#define GPIO20_ADDR ((uint32_t)0xF00113EC)
#define GPIO21_ADDR ((uint32_t)0xF00114EB)
#define GPIO22_ADDR ((uint32_t)0xF00115EA)
#define GPIO23_ADDR ((uint32_t)0xF00116E9)
#define GPIO24_ADDR ((uint32_t)0xF00117E8)
#define GPIO25_ADDR ((uint32_t)0xF00118E7)
#define GPIO26_ADDR ((uint32_t)0xF00119E6)
#define GPIO27_ADDR ((uint32_t)0xF0011AE5)
#define GPIO28_ADDR ((uint32_t)0xF0011BE4)
#define GPIO29_ADDR ((uint32_t)0xF0011CE3)
#define GPIO30_ADDR ((uint32_t)0xF0011DE2)
#define GPIO31_ADDR ((uint32_t)0xF0011EE1)
#define GPIO32_ADDR ((uint32_t)0xF0011FE0)
#define GPIO33_ADDR ((uint32_t)0xF00120DF)
#define GPIO34_ADDR ((uint32_t)0xF00121DE)
#define GPIO35_ADDR ((uint32_t)0xF00122DD)
#define GPIO36_ADDR ((uint32_t)0xF00123DC)
#define GPIO37_ADDR ((uint32_t)0xF00124DB)
#define GPIO38_ADDR ((uint32_t)0xF00125DA)
#define GPIO39_ADDR ((uint32_t)0xF00126D9)
#define GPIO40_ADDR ((uint32_t)0xF00127D8)
#define GPIO41_ADDR ((uint32_t)0xF00128D7)
#define GPIO0_PTR   ((Gpio_RegisterMap_t *)GPIO0_ADDR)
#define GPIO1_PTR   ((Gpio_RegisterMap_t *)GPIO1_ADDR)
#define GPIO2_PTR   ((Gpio_RegisterMap_t *)GPIO2_ADDR)
#define GPIO3_PTR   ((Gpio_RegisterMap_t *)GPIO3_ADDR)
#define GPIO4_PTR   ((Gpio_RegisterMap_t *)GPIO4_ADDR)
#define GPIO5_PTR   ((Gpio_RegisterMap_t *)GPIO5_ADDR)
#define GPIO6_PTR   ((Gpio_RegisterMap_t *)GPIO6_ADDR)
#define GPIO7_PTR   ((Gpio_RegisterMap_t *)GPIO7_ADDR)
#define GPIO8_PTR   ((Gpio_RegisterMap_t *)GPIO8_ADDR)
#define GPIO9_PTR   ((Gpio_RegisterMap_t *)GPIO9_ADDR)
#define GPIO10_PTR  ((Gpio_RegisterMap_t *)GPIO10_ADDR)
#define GPIO11_PTR  ((Gpio_RegisterMap_t *)GPIO11_ADDR)
#define GPIO12_PTR  ((Gpio_RegisterMap_t *)GPIO12_ADDR)
#define GPIO13_PTR  ((Gpio_RegisterMap_t *)GPIO13_ADDR)
#define GPIO14_PTR  ((Gpio_RegisterMap_t *)GPIO14_ADDR)
#define GPIO15_PTR  ((Gpio_RegisterMap_t *)GPIO15_ADDR)
#define GPIO16_PTR  ((Gpio_RegisterMap_t *)GPIO16_ADDR)
#define GPIO17_PTR  ((Gpio_RegisterMap_t *)GPIO17_ADDR)
#define GPIO18_PTR  ((Gpio_RegisterMap_t *)GPIO18_ADDR)
#define GPIO19_PTR  ((Gpio_RegisterMap_t *)GPIO19_ADDR)
#define GPIO20_PTR  ((Gpio_RegisterMap_t *)GPIO20_ADDR)
#define GPIO21_PTR  ((Gpio_RegisterMap_t *)GPIO21_ADDR)
#define GPIO22_PTR  ((Gpio_RegisterMap_t *)GPIO22_ADDR)
#define GPIO23_PTR  ((Gpio_RegisterMap_t *)GPIO23_ADDR)
#define GPIO24_PTR  ((Gpio_RegisterMap_t *)GPIO24_ADDR)
#define GPIO25_PTR  ((Gpio_RegisterMap_t *)GPIO25_ADDR)
#define GPIO26_PTR  ((Gpio_RegisterMap_t *)GPIO26_ADDR)
#define GPIO27_PTR  ((Gpio_RegisterMap_t *)GPIO27_ADDR)
#define GPIO28_PTR  ((Gpio_RegisterMap_t *)GPIO28_ADDR)
#define GPIO29_PTR  ((Gpio_RegisterMap_t *)GPIO29_ADDR)
#define GPIO30_PTR  ((Gpio_RegisterMap_t *)GPIO30_ADDR)
#define GPIO31_PTR  ((Gpio_RegisterMap_t *)GPIO31_ADDR)
#define GPIO32_PTR  ((Gpio_RegisterMap_t *)GPIO32_ADDR)
#define GPIO33_PTR  ((Gpio_RegisterMap_t *)GPIO33_ADDR)
#define GPIO34_PTR  ((Gpio_RegisterMap_t *)GPIO34_ADDR)
#define GPIO35_PTR  ((Gpio_RegisterMap_t *)GPIO35_ADDR)
#define GPIO36_PTR  ((Gpio_RegisterMap_t *)GPIO36_ADDR)
#define GPIO37_PTR  ((Gpio_RegisterMap_t *)GPIO37_ADDR)
#define GPIO38_PTR  ((Gpio_RegisterMap_t *)GPIO38_ADDR)
#define GPIO39_PTR  ((Gpio_RegisterMap_t *)GPIO39_ADDR)
#define GPIO40_PTR  ((Gpio_RegisterMap_t *)GPIO40_ADDR)
#define GPIO41_PTR  ((Gpio_RegisterMap_t *)GPIO41_ADDR)
#define GPIO0_RM    (*(Gpio_RegisterMap_t *)GPIO0_ADDR)
#define GPIO1_RM    (*(Gpio_RegisterMap_t *)GPIO1_ADDR)
#define GPIO2_RM    (*(Gpio_RegisterMap_t *)GPIO2_ADDR)
#define GPIO3_RM    (*(Gpio_RegisterMap_t *)GPIO3_ADDR)
#define GPIO4_RM    (*(Gpio_RegisterMap_t *)GPIO4_ADDR)
#define GPIO5_RM    (*(Gpio_RegisterMap_t *)GPIO5_ADDR)
#define GPIO6_RM    (*(Gpio_RegisterMap_t *)GPIO6_ADDR)
#define GPIO7_RM    (*(Gpio_RegisterMap_t *)GPIO7_ADDR)
#define GPIO8_RM    (*(Gpio_RegisterMap_t *)GPIO8_ADDR)
#define GPIO9_RM    (*(Gpio_RegisterMap_t *)GPIO9_ADDR)
#define GPIO10_RM   (*(Gpio_RegisterMap_t *)GPIO10_ADDR)
#define GPIO11_RM   (*(Gpio_RegisterMap_t *)GPIO11_ADDR)
#define GPIO12_RM   (*(Gpio_RegisterMap_t *)GPIO12_ADDR)
#define GPIO13_RM   (*(Gpio_RegisterMap_t *)GPIO13_ADDR)
#define GPIO14_RM   (*(Gpio_RegisterMap_t *)GPIO14_ADDR)
#define GPIO15_RM   (*(Gpio_RegisterMap_t *)GPIO15_ADDR)
#define GPIO16_RM   (*(Gpio_RegisterMap_t *)GPIO16_ADDR)
#define GPIO17_RM   (*(Gpio_RegisterMap_t *)GPIO17_ADDR)
#define GPIO18_RM   (*(Gpio_RegisterMap_t *)GPIO18_ADDR)
#define GPIO19_RM   (*(Gpio_RegisterMap_t *)GPIO19_ADDR)
#define GPIO20_RM   (*(Gpio_RegisterMap_t *)GPIO20_ADDR)
#define GPIO21_RM   (*(Gpio_RegisterMap_t *)GPIO21_ADDR)
#define GPIO22_RM   (*(Gpio_RegisterMap_t *)GPIO22_ADDR)
#define GPIO23_RM   (*(Gpio_RegisterMap_t *)GPIO23_ADDR)
#define GPIO24_RM   (*(Gpio_RegisterMap_t *)GPIO24_ADDR)
#define GPIO25_RM   (*(Gpio_RegisterMap_t *)GPIO25_ADDR)
#define GPIO26_RM   (*(Gpio_RegisterMap_t *)GPIO26_ADDR)
#define GPIO27_RM   (*(Gpio_RegisterMap_t *)GPIO27_ADDR)
#define GPIO28_RM   (*(Gpio_RegisterMap_t *)GPIO28_ADDR)
#define GPIO29_RM   (*(Gpio_RegisterMap_t *)GPIO29_ADDR)
#define GPIO30_RM   (*(Gpio_RegisterMap_t *)GPIO30_ADDR)
#define GPIO31_RM   (*(Gpio_RegisterMap_t *)GPIO31_ADDR)
#define GPIO32_RM   (*(Gpio_RegisterMap_t *)GPIO32_ADDR)
#define GPIO33_RM   (*(Gpio_RegisterMap_t *)GPIO33_ADDR)
#define GPIO34_RM   (*(Gpio_RegisterMap_t *)GPIO34_ADDR)
#define GPIO35_RM   (*(Gpio_RegisterMap_t *)GPIO35_ADDR)
#define GPIO36_RM   (*(Gpio_RegisterMap_t *)GPIO36_ADDR)
#define GPIO37_RM   (*(Gpio_RegisterMap_t *)GPIO37_ADDR)
#define GPIO38_RM   (*(Gpio_RegisterMap_t *)GPIO38_ADDR)
#define GPIO39_RM   (*(Gpio_RegisterMap_t *)GPIO39_ADDR)
#define GPIO40_RM   (*(Gpio_RegisterMap_t *)GPIO40_ADDR)
#define GPIO41_RM   (*(Gpio_RegisterMap_t *)GPIO41_ADDR)
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
