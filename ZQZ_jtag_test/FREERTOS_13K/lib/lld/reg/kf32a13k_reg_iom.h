/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_iom.h
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
 *  |2023-12-21  |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_REG_IOM_H_
#define _KF32DA13K_REG_IOM_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *         Include Files
 **************************************************************************/
#include "kf_types.h"
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
            __IO uint32_t CMP       :16; /*!< [15:0] CMP是一个16位阈值，与16位定时器值进行比较  */
            __IO uint32_t MOD       :3;  /*!< [18:16] 滤波器与预分频通道操作模式选择  */
            __IO uint32_t ISM       :2;  /*!< [20:19] 滤波器和预分频通道的监控输入信号选择  */
            __IO uint32_t RESERVED0  :1;  /*!< [21:21] 预留  */
            __IO uint32_t RTG       :1;  /*!< [22:22] 滤波器和预分频通道遇故障时定时器行为  */
            __IO uint32_t RESERVED1 :1;  /*!< [23:23] 预留  */
            __IO uint32_t ISR       :3;  /*!< [26:24] 滤波器与预分频通道的参考输入信号选择  */
            __IO uint32_t RESERVED2 :5;  /*!< [31:27] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_CTL0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t IVR       :1; /*!< [0:0] 反向参考位，FLT的参考信号是否取反  */
            __IO uint32_t IVM       :1; /*!< [1:1] 反向监控位，FLT的监控信号是否取反  */
            __IO uint32_t MOS       :1; /*!< [2:2]  监控资源选择位 */
            __IO uint32_t RMS       :1; /*!< [3:3] 可获取选择位  */
            __IO uint32_t EWS       :1; /*!< [4:4] 事件窗口选择位  */
            __IO uint32_t DISEV     :1; /*!< [5:5]  禁止事件产生传输位 */
            __IO uint32_t RESERVED0  :2; /*!< [7:6] 预留  */
            __IO uint32_t EDS       :4; /*!< [11:8] 事件窗口激活沿选择位  */
            __IO uint32_t IVE       :1; /*!< [12:12] 事件窗口取反位  */
            __IO uint32_t RESERVED1 :3; /*!< [15:13] 预留  */
            __IO uint32_t MCS       :4; /*!< [19:16] 监控输入信号选择位  */
            __IO uint32_t RCS       :4; /*!< [23:20] 参考输入信号选择位  */
            __IO uint32_t RESERVED2 :8; /*!< [31:24] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_CTL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SELC0 :4; /*!< [3:0] 事件通道选择，这一位确定哪个通道事件输出到计数器C0  */
            __IO uint32_t THRC0 :4; /*!< [7:4] 这个位域决定了阈值计数值  */
            __IO uint32_t SELC1 :4; /*!< [11:8] 事件通道选择，这一位确定哪个通道事件输出到计数器C1  */
            __IO uint32_t THRC1 :4; /*!< [15:12] 这个位域决定了阈值计数值 */
            __IO uint32_t SELC2 :4; /*!< [19:16] 事件通道选择，这一位确定哪个通道事件输出到计数器C2  */
            __IO uint32_t THRC2 :4; /*!< [23:20] 这个位域决定了阈值计数值 */
            __IO uint32_t SELC3 :4; /*!< [27:24] 事件通道选择，这一位确定哪个通道事件输出到计数器C3  */
            __IO uint32_t THRC3 :4; /*!< [31:28]  这个位域决定了阈值计数值*/
        } bits;
        __IO uint32_t reg;
    };
} IOM_CTL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t REG0  :1; /*!< [0:0] RPCk下降沿故障标志位  */
            __IO uint32_t REG1  :1; /*!< [1:1] RPCk下降沿故障标志位  */
            __IO uint32_t REG2  :1; /*!< [2:2] RPCk下降沿故障标志位  */
            __IO uint32_t REG3  :1; /*!< [3:3] RPCk下降沿故障标志位  */
            __IO uint32_t REG4  :1; /*!< [4:4] RPCk下降沿故障标志位  */
            __IO uint32_t REG5  :1; /*!< [5:5] RPCk下降沿故障标志位  */
            __IO uint32_t REG6  :1; /*!< [6:6] RPCk下降沿故障标志位  */
            __IO uint32_t REG7  :1; /*!< [7:7] RPCk下降沿故障标志位  */
            __IO uint32_t REG8  :1; /*!< [8:8] RPCk下降沿故障标志位  */
            __IO uint32_t REG9  :1; /*!< [9:9] RPCk下降沿故障标志位  */
            __IO uint32_t REG10 :1; /*!< [10:10] RPCk下降沿故障标志位  */
            __IO uint32_t REG11 :1; /*!< [11:11] RPCk下降沿故障标志位  */
            __IO uint32_t REG12 :1; /*!< [12:12] RPCk下降沿故障标志位  */
            __IO uint32_t REG13 :1; /*!< [13:13] RPCk下降沿故障标志位  */
            __IO uint32_t REG14 :1; /*!< [14:14] RPCk下降沿故障标志位  */
            __IO uint32_t REG15 :1; /*!< [15:15] RPCk下降沿故障标志位  */
            __IO uint32_t FEG0  :1; /*!< [16:16] FLTk下降沿故障标志位  */
            __IO uint32_t FEG1  :1; /*!< [17:17] FLTk下降沿故障标志位  */
            __IO uint32_t FEG2  :1; /*!< [18:18] FLTk下降沿故障标志位  */
            __IO uint32_t FEG3  :1; /*!< [19:19] FLTk下降沿故障标志位  */
            __IO uint32_t FEG4  :1; /*!< [20:20] FLTk下降沿故障标志位  */
            __IO uint32_t FEG5  :1; /*!< [21:21] FLTk下降沿故障标志位  */
            __IO uint32_t FEG6  :1; /*!< [22:22] FLTk下降沿故障标志位  */
            __IO uint32_t FEG7  :1; /*!< [23:23] FLTk下降沿故障标志位  */
            __IO uint32_t FEG8  :1; /*!< [24:24] FLTk下降沿故障标志位  */
            __IO uint32_t FEG9  :1; /*!< [25:25] FLTk下降沿故障标志位  */
            __IO uint32_t FEG10 :1; /*!< [26:26] FLTk下降沿故障标志位  */
            __IO uint32_t FEG11 :1; /*!< [27:27] FLTk下降沿故障标志位  */
            __IO uint32_t FEG12 :1; /*!< [28:28] FLTk下降沿故障标志位  */
            __IO uint32_t FEG13 :1; /*!< [29:29] FLTk下降沿故障标志位  */
            __IO uint32_t FEG14 :1; /*!< [30:30] FLTk下降沿故障标志位  */
            __IO uint32_t FEG15 :1; /*!< [31:31] FLTk下降沿故障标志位  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_STATE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TIM :16; /*!< [15:0] FLT定时器的值，写入TIM将寄存器的内容进变为复位值  */
            __IO uint32_t RESERVED0 :16; /*!< [31:16] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_TIM_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CNT      :24; /*!< [23:0] 到达符合事件窗口发生的计数值  */
            __IO uint32_t RESERVED0 :7;  /*!< [30:24] 预留  */
            __IO uint32_t CNTO     :1;  /*!< [31:31] CMP计数溢出标志位  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_EWC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t THR :24; /*!< [23:0] 事件窗口计数阈值，当计数器大于阈值时，事件开始激活  */
            __IO uint32_t RESERVED0 :8; /*!< [31:24] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_EWS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN0      :1;  /*!< [0:0] EXOR组合器选择通用定时器模块输入  */
            __IO uint32_t EN1      :1;  /*!< [1:1] EXOR组合器选择通用定时器模块输入  */
            __IO uint32_t EN2      :1;  /*!< [2:2] EXOR组合器选择通用定时器模块输入  */
            __IO uint32_t EN3      :1;  /*!< [3:3] EXOR组合器选择通用定时器模块输入  */
            __IO uint32_t EN4      :1;  /*!< [4:4] EXOR组合器选择通用定时器模块输入  */
            __IO uint32_t EN5      :1;  /*!< [5:5] EXOR组合器选择通用定时器模块输入  */
            __IO uint32_t EN6      :1;  /*!< [6:6] EXOR组合器选择通用定时器模块输入  */
            __IO uint32_t EN7      :1;  /*!< [7:7] EXOR组合器选择通用定时器模块输入  */
            __IO uint32_t RESERVED0 :24; /*!< [31:8] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_EXOR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CES0 :1; /*!< [0:0] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES1 :1; /*!< [1:1] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES2 :1; /*!< [2:2] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES3 :1; /*!< [3:3] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES4 :1; /*!< [4:4] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES5 :1; /*!< [5:5] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES6 :1; /*!< [6:6] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES7 :1; /*!< [7:7] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES8 :1; /*!< [8:8] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES9 :1; /*!< [9:9] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES10 :1; /*!< [10:10] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES11 :1; /*!< [11:11] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES12 :1; /*!< [12:12] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES13 :1; /*!< [13:13] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES14 :1; /*!< [14:14] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CES15 :1; /*!< [15:15] 单个事件设置确定在全局事件生成中是否包含相应的通道事件  */
            __IO uint32_t CTS0 :1; /*!< [16:16] 计数警告触发选择，单个位字段的设置确定在生成全局事件时是否包含  */
            __IO uint32_t CTS1 :1; /*!< [17:17] 计数警告触发选择，单个位字段的设置确定在生成全局事件时是否包含  */
            __IO uint32_t CTS2 :1; /*!< [18:18] 计数警告触发选择，单个位字段的设置确定在生成全局事件时是否包含  */
            __IO uint32_t CTS3 :1; /*!< [19:19] 计数警告触发选择，单个位字段的设置确定在生成全局事件时是否包含  */
            __IO uint32_t RESERVED0 :12; /*!< [31:20] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_ECR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ETA0 :1; /*!< [0:0] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态  */
            __IO uint32_t ETA1 :1; /*!< [1:1] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态  */
            __IO uint32_t ETA2 :1; /*!< [2:2] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态  */
            __IO uint32_t ETA3 :1; /*!< [3:3] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态  */
            __IO uint32_t ETA4 :1; /*!< [4:4] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态  */
            __IO uint32_t ETA5 :1; /*!< [5:5] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态  */
            __IO uint32_t ETA6 :1; /*!< [6:6] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态  */
            __IO uint32_t ETA7 :1; /*!< [7:7] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态  */
            __IO uint32_t ETA8 :1; /*!< [8:8] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态  */
            __IO uint32_t ETA9 :1; /*!< [9:9] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态  */
            __IO uint32_t ETA10 :1; /*!< [10:10] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态 */
            __IO uint32_t ETA11 :1; /*!< [11:11] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态 */
            __IO uint32_t ETA12 :1; /*!< [12:12] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态 */
            __IO uint32_t ETA13 :1; /*!< [13:13] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态 */
            __IO uint32_t ETA14 :1; /*!< [14:14] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态 */
            __IO uint32_t ETA15 :1; /*!< [15:15] CMP0-15事件触发激活，在上一次事件产生后，包含每个CMP事件触发输出状态 */
            __IO uint32_t ETB0  :1; /*!< [16:16] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB1  :1; /*!< [17:17] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB2  :1; /*!< [18:18] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB3  :1; /*!< [19:19] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB4  :1; /*!< [20:20] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB5  :1; /*!< [21:21] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB6  :1; /*!< [22:22] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB7  :1; /*!< [23:23] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB8  :1; /*!< [24:24] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB9  :1; /*!< [25:25] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB10 :1; /*!< [26:26] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB11 :1; /*!< [27:27] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB12 :1; /*!< [28:28] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB13 :1; /*!< [29:29] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB14 :1; /*!< [30:30] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
            __IO uint32_t ETB15 :1; /*!< [31:31] CMP0-15事件触发激活，包含ETA0-15的未更新前的内容  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_ETM0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ETC0  :1; /*!< [0:0] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC1  :1; /*!< [1:1] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC2  :1; /*!< [2:2] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC3  :1; /*!< [3:3] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC4  :1; /*!< [4:4] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC5  :1; /*!< [5:5] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC6  :1; /*!< [6:6] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC7  :1; /*!< [7:7] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC8  :1; /*!< [8:8] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC9  :1; /*!< [9:9] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC10 :1; /*!< [10:10] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC11 :1; /*!< [11:11] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC12 :1; /*!< [12:12] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC13 :1; /*!< [13:13] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC14 :1; /*!< [14:14] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETC15 :1; /*!< [15:15] CMP0-15事件触发激活，包含ETB0-15的未更新前的内容  */
            __IO uint32_t ETD0  :1; /*!< [16:16] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD1  :1; /*!< [17:17] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD2  :1; /*!< [18:18] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD3  :1; /*!< [19:19] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD4  :1; /*!< [20:20] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD5  :1; /*!< [21:21] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD6  :1; /*!< [22:22] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD7  :1; /*!< [23:23] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD8  :1; /*!< [24:24] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD9  :1; /*!< [25:25] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD10 :1; /*!< [26:26] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD11 :1; /*!< [27:27] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD12 :1; /*!< [28:28] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD13 :1; /*!< [29:29] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD14 :1; /*!< [30:30] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
            __IO uint32_t ETD15 :1; /*!< [31:31] CMP0-15事件触发激活，包含ETC0-15的未更新前的内容  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_ETM1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁止控制位  */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁止状态  */
            __IO uint32_t RESERVED0  :1;  /*!< [2:2] 预留  */
            __IO uint32_t EDIS      :1;  /*!< [3:3] 睡眠模式使能控制  */
            __IO uint32_t RESERVED1 :4;  /*!< [7:4] 预留  */
            __IO uint32_t RMC       :8;  /*!< [15:8] 8位分频  */
            __IO uint32_t RESERVED2 :16; /*!< [31:16] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_CLKC_T;

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
        __IO uint32_t reg;
    };
} IOM_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0  :24; /*!< [23:0] 预留  */
            __IO uint32_t SUS       :4;  /*!< [27:24] 调试模式挂起控制  */
            __O uint32_t  SUSP      :1;  /*!< [28:28] SUS位写保护，读出为0  */
            __I uint32_t  SUSSTA    :1;  /*!< [29:29] 挂起状态位  */
            __IO uint32_t RESERVED1 :2;  /*!< [31:30] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST      :1;  /*!< [0:0] 模块复位请求位，与IOM_RST1寄存器的RST一起使用  */
            __I uint32_t  RSTSTA   :1;  /*!< [1:1] 复位状态  */
            __IO uint32_t RESERVED0 :30; /*!< [31:2] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST      :1;  /*!< [0:0] 模块复位请求位，与IOM_RST1寄存器的RST位一起使用  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  CLR      :1;  /*!< [0:0] 复位状态清除位，读出为0  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_RSTCLR_T;

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
} IOM_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :32; /*!< [31:0] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} IOM_ACES1_T;

typedef volatile struct
{
    /* offset  : 0x0000.  */
    IOM_CTL0_T IOM_CTL0;

    /* offset  : 0x0004.  */
    IOM_CTL1_T IOM_CTL1;

    /* offset  : 0x0008.  */
    IOM_CTL2_T IOM_CTL2;

    /* offset  : 0x000C.  */
    IOM_STATE_T IOM_STATE;

    /* offset  : 0x0010.  */
    IOM_TIM_T IOM_TIM;

    /* offset  : 0x0014.  */
    IOM_EWC_T IOM_EWC;

    /* offset  : 0x0018.  */
    IOM_EWS_T IOM_EWS;

    /* offset  : 0x001C.  */
    IOM_EXOR_T IOM_EXOR;

    /* offset  : 0x0020.  */
    IOM_ECR_T IOM_ECR;

    /* offset  : 0x0024.  */
    IOM_ETM0_T IOM_ETM0;

    /* offset  : 0x0028.  */
    IOM_ETM1_T IOM_ETM1;

    /* offset  : 0x002C.  */
    IOM_CLKC_T IOM_CLKC;

    /* offset  : 0x0030.  */
    IOM_INFO_T IOM_INFO;

    /* offset  : 0x0034.  */
    IOM_DBG_T IOM_DBG;

    /* offset  : 0x0038.  */
    IOM_RST0_T IOM_RST0;

    /* offset  : 0x003C.  */
    IOM_RST1_T IOM_RST1;

    /* offset  : 0x0040.  */
    IOM_RSTCLR_T IOM_RSTCLR;

    /* offset  : 0x0044.  */
    IOM_ACES0_T IOM_ACES0;

    /* offset  : 0x0048.  */
    IOM_ACES1_T IOM_ACES1;
} Iom_RegisterMap_t;

#define IOM_ADDR ((uint32_t)0xF0007A00)
#define IOM_PTR  ((Iom_RegisterMap_t *)IOM_ADDR)
#define IOM_RM   (*(Iom_RegisterMap_t *)IOM_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
