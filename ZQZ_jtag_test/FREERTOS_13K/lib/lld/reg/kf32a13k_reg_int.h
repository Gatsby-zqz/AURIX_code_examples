/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_int.h
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
 *  |2023-12-25  |V1.0   |Zhang Quanzhen     | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_REG_INT_H_
#define _KF32DA13K_REG_INT_H_

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
            __IO uint32_t SRPN :9; /*!< [8:0] 中断源优先级配置，可以配置0-511，511最大，0最低  */
            __I uint32_t  RESERVED0 :1; /*!< [9:9] 预留，读取为0  */
            __IO uint32_t SRIE      :1; /*!< [10:10] 中断使能控制  */
            __IO uint32_t TOS       :3; /*!< [13:11] 中断路由配置  */
            __I uint32_t  RESERVED1 :2; /*!< [15:14] 预留，读取为0  */
            __IO uint32_t EDC       :5; /*!< [20:16] EDC编码值  */
            __I uint32_t  RESERVED2 :3; /*!< [23:21] 预留，读取为0  */
            __I uint32_t  SRIF      :1; /*!< [24:24] 挂起标志位  */
            __O uint32_t  SRIC      :1; /*!< [25:25] 软件清除SRIF  */
            __O uint32_t  SRIS      :1; /*!< [26:26] 软件置位SRIF  */
            __I uint32_t IOVSTA :1; /*!< [27:27] 中断触发溢出状态位，即挂起状态下又来了一个中断触发请求  */
            __O uint32_t IOVSTAIC  :1; /*!< [28:28] 中断触发溢出清除位  */
            __I uint32_t SWSSTA    :1; /*!< [29:29] 软件触发中断提示状态位  */
            __O uint32_t SWSSTAIC  :1; /*!< [30:30] 软件清除SWSSTA位域  */
            __I uint32_t RESERVED3 :1; /*!< [31:31] 预留，读取为0  */
        } bits;
        __IO uint32_t reg;
    };
} INT_SRC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] 中断模块版本信息  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] 中断模块类型信息  */
            __I uint32_t MODNUM  :16; /*!< [31:16] 中断模块的编号  */
        } bits;
        __IO uint32_t reg;
    };
} INT_ID_T;

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
} INT_CFG0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留，读取为0  */
        } bits;
        __IO uint32_t reg;
    };
} INT_CFG1_T;

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
} INT_ACES_SRB0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留，读取为0  */
        } bits;
        __IO uint32_t reg;
    };
} INT_ACES_SRB1_T;

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
} INT_ACES_TOS0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留，读取为0  */
        } bits;
        __IO uint32_t reg;
    };
} INT_ACES_TOS1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t PN        :9;  /*!< [8:0] 仲裁胜利者的优先级信息  */
            __I uint32_t RESERVED0 :1;  /*!< [9:9] 预留，读取为0  */
            __I uint32_t EDC       :5;  /*!< [14:10] 仲裁胜利者的EDC编码信息  */
            __I uint32_t RESERVED1 :1;  /*!< [15:15] 预留，读取为0  */
            __I uint32_t ID        :10; /*!< [25:16] 仲裁胜利者的ID信息  */
            __I uint32_t RESERVED2 :5;  /*!< [30:26] 预留，读取为0  */
            __I uint32_t STAT      :1;  /*!< [31:31] INT_LWSR寄存器对应的中断源是否有效  */
        } bits;
        __IO uint32_t reg;
    };
} INT_LWSR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t PN        :9;  /*!< [8:0] 服务请求反馈的中断源对应的优先级信息  */
            __I uint32_t RESERVED0 :1;  /*!< [9:9] 预留，读取为0  */
            __I uint32_t EDC       :5;  /*!< [14:10] 服务请求反馈的中断源对应的EDC编码信息  */
            __I uint32_t RESERVED1 :1;  /*!< [15:15] 预留，读取为0  */
            __I uint32_t ID        :10; /*!< [25:16] 服务请求反馈的中断源对应的ID信息  */
            __I uint32_t RESERVED2 :6;  /*!< [31:26] 预留，读取为0  */
        } bits;
        __IO uint32_t reg;
    };
} INT_LASR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t PN :9; /*!< [8:0] 服务请求反馈EDC检测错误的中断源对应的优先级信息  */
            __I uint32_t RESERVED0 :1; /*!< [9:9] 预留，读取为0  */
            __I uint32_t EDC :5; /*!< [14:10] 服务请求反馈EDC检测错误的中断源对应的EDC编码信息  */
            __I uint32_t RESERVED1 :1;  /*!< [15:15] 预留，读取为0  */
            __I uint32_t ID        :10; /*!< [25:16] 服务请求反馈EDC检测错误的中断源对应的ID信息  */
            __I uint32_t RESERVED2 :2;  /*!< [27:26] 预留，读取为0  */
            __O uint32_t EOVIC     :1;  /*!< [28:28] 清除EOVSTA位域  */
            __O uint32_t EIC       :1;  /*!< [29:29] 清除ESTA位域  */
            __I uint32_t EOVSTA    :1;  /*!< [30:30] 错误溢出状态位  */
            __I uint32_t ESTA      :1;  /*!< [31:31] 错误状态提示位域  */
        } bits;
        __IO uint32_t reg;
    };
} INT_ECR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t TRIG0     :1;  /*!< [0:0] 软件触发中断  */
            __O uint32_t TRIG1     :1;  /*!< [1:1] 软件触发中断  */
            __I uint32_t RESERVED0 :30; /*!< [31:2] 预留，读取为0  */
        } bits;
        __IO uint32_t reg;
    };
} INT_SRB_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              MODE :32; /*!< [31:0]
                           ICUx中断模式选择，当该位域配置为32’h5A5A5A5A时，中断切换位串行模式，此外是连续模式。
                         */
        } bits;
        __IO uint32_t reg;
    };
} INT_MODE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TIME      :24; /*!< [23:0] 中断源超时监控时间设置  */
            __I uint32_t  RESERVED0 :8;  /*!< [31:24] 预留，读取为0  */
        } bits;
        __IO uint32_t reg;
    };
} INT_TIMOUT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ID :10; /*!< [9:0] 监控中断源选择。ID选择1-512，写0或超过512是无效的。  */
            __I uint32_t  RESERVED0 :2;  /*!< [11:10] 预留，读取为0。  */
            __I uint32_t  RESERVED2 :22; /*!< [31:10] 预留，读取为0  */
            __IO uint32_t MONITEREN :1;  /*!< [12:12] 中断定时监控使能控制  */
            __I uint32_t  RESERVED3 :3;  /*!< [15:13] 预留，读取为0。  */
            __I uint32_t
              TIMOUTSTA :1; /*!< [16:16]
                               超时提示位，该位域通过向寄存器INT_TIMER.TIMEVAL写个小于INT_TIMOUT.TIMOUT的值清零。
                             */
        } bits;
        __IO uint32_t reg;
    };
} INT_TIMSEL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TIMOUT :24; /*!< [23:0] 监控器计时报警阈值配置，该位域设定不要超过0xFF_FFFD  */
            __I uint32_t RESERVED0 :8; /*!< [31:24] 预留，读取为0。  */
        } bits;
        __IO uint32_t reg;
    };
} INT_TIMER_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t OTGB0 :16; /*!< [15:0] OTGB0状态  */
            __I uint32_t OTGB1 :16; /*!< [31:16] OTGB1状态  */
        } bits;
        __IO uint32_t reg;
    };
} OOBS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TGS       :2;  /*!< [1:0] OTGB0/1触发设置  */
            __IO uint32_t TGB       :1;  /*!< [2:2] OTGB0/1总线设置  */
            __I uint32_t  RESERVED0 :29; /*!< [31:3] 预留，读取为0。  */
        } bits;
        __IO uint32_t reg;
    };
} OSSIC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TGS       :2;  /*!< [1:0] OTGB0/1触发设置  */
            __I uint32_t  RESERVED0 :6;  /*!< [7:2] 预留，读取为0。  */
            __IO uint32_t OBS       :2;  /*!< [9:8] 覆盖字节选择  */
            __I uint32_t  RESERVED1 :22; /*!< [31:10] 预留，读取为0。  */
        } bits;
        __IO uint32_t reg;
    };
} OIXTS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t MIRQ      :10; /*!< [9:0] 缺少中断触发的SRN索引号  */
            __I uint32_t  RESERVED0 :22; /*!< [31:10] 预留，读取为0。  */
        } bits;
        __IO uint32_t reg;
    };
} OIXMS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t IRQ0      :10; /*!< [9:0] 中断触发0的SRN索引号  */
            __I uint32_t  RESERVED0 :6;  /*!< [15:10] 预留，读取为0。  */
            __IO uint32_t IRQ1      :10; /*!< [25:16] 中断触发1的SRN索引号  */
            __I uint32_t  RESERVED1 :6;  /*!< [31:26] 预留，读取为0。  */
        } bits;
        __IO uint32_t reg;
    };
} OIXS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TOS0      :3; /*!< [2:0] OTGB0 观测的服务类型，与 SRC.TOS 适配  */
            __I uint32_t  RESERVED0 :4; /*!< [6:3] 预留，读取为0。  */
            __IO uint32_t OE0       :1; /*!< [7:7] OTGB0输出使能  */
            __IO uint32_t TOS1      :3; /*!< [2:0] OTGB1 观测的服务类型，与 SRC.TOS 适配  */
            __I uint32_t  RESERVED1 :4; /*!< [6:3] 预留，读取为0。  */
            __IO uint32_t OE1       :1; /*!< [15:15] OTGB1输出使能  */
            __I uint32_t  RESERVED2 :6; /*!< [31:16] 预留，读取为0。  */
        } bits;
        __IO uint32_t reg;
    };
} OIT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OTGB0 :16; /*!< [15:0] OTGB0 按位上升沿敏感 */
            __IO uint32_t OTGB1 :16; /*!< [31:16] OTGB1 按位上升沿敏感 */
        } bits;
        __IO uint32_t reg;
    };
} OMISP_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OTGB0 :16; /*!< [15:0] OTGB0 按位下降沿敏感 */
            __IO uint32_t OTGB1 :16; /*!< [31:16] OTGB1 按位下降沿敏感 */
        } bits;
        __IO uint32_t reg;
    };
} OMISN_T;

typedef volatile struct
{
    INT_SRC_T CPU[2];
} KF_SRC_GCPU_T;

typedef volatile struct
{
    INT_SRC_T TX;
    INT_SRC_T RX;
    INT_SRC_T ERROR;
} KF_SRC_UTLIN_T;

typedef volatile struct
{
    KF_SRC_UTLIN_T UTLIN[8];
} KF_SRC_GUTLIN_T;

typedef volatile struct
{
    INT_SRC_T MTU;
} KF_SRC_GMTU_T;

typedef volatile struct
{
    INT_SRC_T TX;
    INT_SRC_T RX;
    INT_SRC_T ERROR;
    INT_SRC_T PT;
    INT_SRC_T USER;
} KF_SRC_SPI_T;

typedef volatile struct
{
    KF_SRC_SPI_T SPI[4];
} KF_SRC_GSPI_T;

typedef volatile struct
{
    INT_SRC_T QSPI[4];
} KF_SRC_GQSPI_T;

typedef volatile struct
{
    INT_SRC_T CLK;
} KF_SRC_GCLK_T;

typedef volatile struct
{
    INT_SRC_T TX;
    INT_SRC_T RX;
    INT_SRC_T ERROR;
    INT_SRC_T PROTOCOL;
} KF_SRC_IIC_T;

typedef volatile struct
{
    KF_SRC_IIC_T IIC[4];
} KF_SRC_GIIC_T;

typedef volatile struct
{
    INT_SRC_T SENT[10];
} KF_SRC_GSENT_T;

typedef volatile struct
{
    INT_SRC_T MSC[2][5];
} KF_SRC_GMSC_T;

typedef volatile struct
{
    INT_SRC_T RTC;
} KF_SRC_GRTC_T;

typedef volatile struct
{
    INT_SRC_T BPT[4];
} KF_SRC_GBPT_T;

typedef volatile struct
{
    INT_SRC_T APT[19][4];
} KF_SRC_GAPT_T;

typedef volatile struct
{
    INT_SRC_T ERROR;
} KF_SRC_QEI_T;

typedef volatile struct
{
    KF_SRC_QEI_T QEI;
} KF_SRC_GQEI_T;

typedef volatile struct
{
    INT_SRC_T HRCAP[3];
} KF_SRC_GHRCAP_T;

typedef volatile struct
{
    INT_SRC_T SYSTICK[2][2];
} KF_SRC_GSYSTICK_T;

typedef volatile struct
{
    INT_SRC_T CRC;
} KF_SRC_GCRC_T;

typedef volatile struct
{
    INT_SRC_T ERROR[4];
} KF_SRC_ERROR_T;

typedef volatile struct
{
    INT_SRC_T CHANNEL[64];
} KF_SRC_CHANNEL_T;

typedef volatile struct
{
    KF_SRC_ERROR_T   ERROR;
    KF_SRC_CHANNEL_T CHANNEL;
} KF_SRC_GDMA_T;

typedef volatile struct
{
    INT_SRC_T CANFD[8];
} KF_SRC_GCANFD_T;

typedef volatile struct
{
    INT_SRC_T ADCGROUP[4][4];
} KF_SRC_ADCGROUP_T;

typedef volatile struct
{
    INT_SRC_T ADCFASTCOMPARE[4];
} KF_SRC_ADCFASTCOMPARE_T;

typedef volatile struct
{
    INT_SRC_T ADCCOMGROUP[2][4];
} KF_SRC_ADCCOMGROUP_T;

typedef volatile struct
{
    KF_SRC_ADCGROUP_T       GROUP;
    KF_SRC_ADCFASTCOMPARE_T FASTCOMPARE;
    KF_SRC_ADCCOMGROUP_T    COMGROUP;
} KF_SRC_GADC_T;

typedef volatile struct
{
    INT_SRC_T ERROR;
} KF_SRC_GFLASH_T;

typedef volatile struct
{
    INT_SRC_T HSM[4];
} KF_SRC_GHSM_T;

typedef volatile struct
{
    INT_SRC_T SCU[4];
} KF_SRC_GSCU_T;

typedef volatile struct
{
    INT_SRC_T PMCDTS;
} KF_SRC_GPMCDTS_T;

typedef volatile struct
{
    INT_SRC_T PMC[4];
} KF_SRC_GPMC_T;

typedef volatile struct
{
    INT_SRC_T SACU[3];
} KF_SRC_GSACU_T;

typedef volatile struct
{
    INT_SRC_T PSI5[8];
} KF_SRC_GPSI5_T;

typedef volatile struct
{
    INT_SRC_T PSI5S[8];
} KF_SRC_GPSI5S_T;

typedef volatile struct
{
    INT_SRC_T EPWM[12][4];
} KF_SRC_GEPWM_T;

typedef volatile struct
{
    INT_SRC_T GPSR[2][8];
} KF_SRC_GPSR_T;

/*中断向量号*/
typedef enum
{
    HW_CPU0_IRQn             = 0U,
    HW_CPU1_IRQn             = 1U,
    HW_UTLIN0_TX_IRQn        = 2U,
    HW_UTLIN1_TX_IRQn        = 3U,
    HW_UTLIN2_TX_IRQn        = 4U,
    HW_UTLIN3_TX_IRQn        = 5U,
    HW_UTLIN4_TX_IRQn        = 6U,
    HW_UTLIN5_TX_IRQn        = 7U,
    HW_UTLIN6_TX_IRQn        = 8U,
    HW_UTLIN7_TX_IRQn        = 9U,
    HW_UTLIN0_RX_IRQn        = 10U,
    HW_UTLIN1_RX_IRQn        = 11U,
    HW_UTLIN2_RX_IRQn        = 12U,
    HW_UTLIN3_RX_IRQn        = 13U,
    HW_UTLIN4_RX_IRQn        = 14U,
    HW_UTLIN5_RX_IRQn        = 15U,
    HW_UTLIN6_RX_IRQn        = 16U,
    HW_UTLIN7_RX_IRQn        = 17U,
    HW_UTLIN0_ERROR_IRQn     = 18U,
    HW_UTLIN1_ERROR_IRQn     = 19U,
    HW_UTLIN2_ERROR_IRQn     = 20U,
    HW_UTLIN3_ERROR_IRQn     = 21U,
    HW_UTLIN4_ERROR_IRQn     = 22U,
    HW_UTLIN5_ERROR_IRQn     = 23U,
    HW_UTLIN6_ERROR_IRQn     = 24U,
    HW_UTLIN7_ERROR_IRQn     = 25U,
    HW_MTU_ERROR_IRQn        = 26U,
    HW_SPI0_TX_IRQn          = 27U,
    HW_SPI1_TX_IRQn          = 28U,
    HW_SPI2_TX_IRQn          = 29U,
    HW_SPI3_TX_IRQn          = 30U,
    HW_SPI0_RX_IRQn          = 31U,
    HW_SPI1_RX_IRQn          = 32U,
    HW_SPI2_RX_IRQn          = 33U,
    HW_SPI3_RX_IRQn          = 34U,
    HW_SPI0_ERROR_IRQn       = 35U,
    HW_SPI1_ERROR_IRQn       = 36U,
    HW_SPI2_ERROR_IRQn       = 37U,
    HW_SPI3_ERROR_IRQn       = 38U,
    HW_SPI0_PT_IRQn          = 39U,
    HW_SPI1_PT_IRQn          = 40U,
    HW_SPI2_PT_IRQn          = 41U,
    HW_SPI3_PT_IRQn          = 42U,
    HW_SPI0_USER_IRQn        = 43U,
    HW_SPI1_USER_IRQn        = 44U,
    HW_SPI2_USER_IRQn        = 45U,
    HW_SPI3_USER_IRQn        = 46U,
    HW_QSPI0_SR_IRQn         = 47U,
    HW_QSPI1_SR_IRQn         = 48U,
    HW_QSPI2_SR_IRQn         = 49U,
    HW_QSPI3_SR_IRQn         = 50U,
    HW_QSPI4_SR_IRQn         = 51U,
    HW_QSPI5_SR_IRQn         = 52U,
    HW_CLK_IRQn              = 53U,
    HW_IIC0_TX_IRQn          = 54U,
    HW_IIC1_TX_IRQn          = 55U,
    HW_IIC2_TX_IRQn          = 56U,
    HW_IIC3_TX_IRQn          = 57U,
    HW_IIC0_RX_IRQn          = 58U,
    HW_IIC1_RX_IRQn          = 59U,
    HW_IIC2_RX_IRQn          = 60U,
    HW_IIC3_RX_IRQn          = 61U,
    HW_IIC0_ERROR_IRQn       = 62U,
    HW_IIC1_ERROR_IRQn       = 63U,
    HW_IIC2_ERROR_IRQn       = 64U,
    HW_IIC3_ERROR_IRQn       = 65U,
    HW_IIC0_PROTOCOL_IRQn    = 66U,
    HW_IIC1_PROTOCOL_IRQn    = 67U,
    HW_IIC2_PROTOCOL_IRQn    = 68U,
    HW_IIC3_PROTOCOL_IRQn    = 69U,
    HW_SENT0_IRQn            = 70U,
    HW_SENT1_IRQn            = 71U,
    HW_SENT2_IRQn            = 72U,
    HW_SENT3_IRQn            = 73U,
    HW_SENT4_IRQn            = 74U,
    HW_SENT5_IRQn            = 75U,
    HW_SENT6_IRQn            = 76U,
    HW_SENT7_IRQn            = 77U,
    HW_SENT8_IRQn            = 78U,
    HW_SENT9_IRQn            = 79U,
    HW_MSC0SR0_IRQn          = 80U,
    HW_MSC0SR1_IRQn          = 81U,
    HW_MSC0SR2_IRQn          = 82U,
    HW_MSC0SR3_IRQn          = 83U,
    HW_MSC0SR4_IRQn          = 84U,
    HW_MSC1SR0_IRQn          = 85U,
    HW_MSC1SR1_IRQn          = 86U,
    HW_MSC1SR2_IRQn          = 87U,
    HW_MSC1SR3_IRQn          = 88U,
    HW_MSC1SR4_IRQn          = 89U,
    HW_RTC_IRQn              = 90U,
    HW_BPT0_IRQn             = 91U,
    HW_BPT1_IRQn             = 92U,
    HW_BPT2_IRQn             = 93U,
    HW_BPT3_IRQn             = 94U,
    HW_APT0SR0_IRQn          = 95U,
    HW_APT0SR1_IRQn          = 96U,
    HW_APT0SR2_IRQn          = 97U,
    HW_APT0SR3_IRQn          = 98U,
    HW_APT1SR0_IRQn          = 99U,
    HW_APT1SR1_IRQn          = 100U,
    HW_APT1SR2_IRQn          = 101U,
    HW_APT1SR3_IRQn          = 102U,
    HW_APT2SR0_IRQn          = 103U,
    HW_APT2SR1_IRQn          = 104U,
    HW_APT2SR2_IRQn          = 105U,
    HW_APT2SR3_IRQn          = 106U,
    HW_APT3SR0_IRQn          = 107U,
    HW_APT3SR1_IRQn          = 108U,
    HW_APT3SR2_IRQn          = 109U,
    HW_APT3SR3_IRQn          = 110U,
    HW_APT4SR0_IRQn          = 111U,
    HW_APT4SR1_IRQn          = 112U,
    HW_APT4SR2_IRQn          = 113U,
    HW_APT4SR3_IRQn          = 114U,
    HW_APT5SR0_IRQn          = 115U,
    HW_APT5SR1_IRQn          = 116U,
    HW_APT5SR2_IRQn          = 117U,
    HW_APT5SR3_IRQn          = 118U,
    HW_APT6SR0_IRQn          = 119U,
    HW_APT6SR1_IRQn          = 120U,
    HW_APT6SR2_IRQn          = 121U,
    HW_APT6SR3_IRQn          = 122U,
    HW_APT7SR0_IRQn          = 123U,
    HW_APT7SR1_IRQn          = 124U,
    HW_APT7SR2_IRQn          = 125U,
    HW_APT7SR3_IRQn          = 126U,
    HW_APT8SR0_IRQn          = 127U,
    HW_APT8SR1_IRQn          = 128U,
    HW_APT8SR2_IRQn          = 129U,
    HW_APT8SR3_IRQn          = 130U,
    HW_APT9SR0_IRQn          = 131U,
    HW_APT9SR1_IRQn          = 132U,
    HW_APT9SR2_IRQn          = 133U,
    HW_APT9SR3_IRQn          = 134U,
    HW_APT10SR0_IRQn         = 135U,
    HW_APT10SR1_IRQn         = 136U,
    HW_APT10SR2_IRQn         = 137U,
    HW_APT10SR3_IRQn         = 138U,
    HW_APT11SR0_IRQn         = 139U,
    HW_APT11SR1_IRQn         = 140U,
    HW_APT11SR2_IRQn         = 141U,
    HW_APT11SR3_IRQn         = 142U,
    HW_APT12SR0_IRQn         = 143U,
    HW_APT12SR1_IRQn         = 144U,
    HW_APT12SR2_IRQn         = 145U,
    HW_APT12SR3_IRQn         = 146U,
    HW_APT13SR0_IRQn         = 147U,
    HW_APT13SR1_IRQn         = 148U,
    HW_APT13SR2_IRQn         = 149U,
    HW_APT13SR3_IRQn         = 150U,
    HW_APT14SR0_IRQn         = 151U,
    HW_APT14SR1_IRQn         = 152U,
    HW_APT14SR2_IRQn         = 153U,
    HW_APT14SR3_IRQn         = 154U,
    HW_APT15SR0_IRQn         = 155U,
    HW_APT15SR1_IRQn         = 156U,
    HW_APT15SR2_IRQn         = 157U,
    HW_APT15SR3_IRQn         = 158U,
    HW_APT16SR0_IRQn         = 159U,
    HW_APT16SR1_IRQn         = 160U,
    HW_APT16SR2_IRQn         = 161U,
    HW_APT16SR3_IRQn         = 162U,
    HW_APT17SR0_IRQn         = 163U,
    HW_APT17SR1_IRQn         = 164U,
    HW_APT17SR2_IRQn         = 165U,
    HW_APT17SR3_IRQn         = 166U,
    HW_APT18SR0_IRQn         = 167U,
    HW_APT18SR1_IRQn         = 168U,
    HW_APT18SR2_IRQn         = 169U,
    HW_APT18SR3_IRQn         = 170U,
    HW_QEI0_ERROR_IRQn       = 171U,
    HW_QEI1_ERROR_IRQn       = 172U,
    HW_QEI2_ERROR_IRQn       = 173U,
    HW_HRCAP0_ERROR_IRQn     = 174U,
    HW_HRCAP1_ERROR_IRQn     = 175U,
    HW_HRCAP2_ERROR_IRQn     = 176U,
    HW_SYSTICK0SR0_IRQn      = 177U,
    HW_SYSTICK0SR1_IRQn      = 178U,
    HW_SYSTICK0SR2_IRQn      = 179U,
    HW_SYSTICK1SR0_IRQn      = 180U,
    HW_SYSTICK1SR1_IRQn      = 181U,
    HW_SYSTICK1SR2_IRQn      = 182U,
    HW_CRC_IRQn              = 183U,
    HW_DMA_ERROR0_IRQn       = 184U,
    HW_DMA_ERROR1_IRQn       = 185U,
    HW_DMA_ERROR2_IRQn       = 186U,
    HW_DMA_ERROR3_IRQn       = 187U,
    HW_DMA_CHANNEL0_IRQn     = 188U,
    HW_DMA_CHANNEL1_IRQn     = 189U,
    HW_DMA_CHANNEL2_IRQn     = 190U,
    HW_DMA_CHANNEL3_IRQn     = 191U,
    HW_DMA_CHANNEL4_IRQn     = 192U,
    HW_DMA_CHANNEL5_IRQn     = 193U,
    HW_DMA_CHANNEL6_IRQn     = 194U,
    HW_DMA_CHANNEL7_IRQn     = 195U,
    HW_DMA_CHANNEL8_IRQn     = 196U,
    HW_DMA_CHANNEL9_IRQn     = 197U,
    HW_DMA_CHANNEL10_IRQn    = 198U,
    HW_DMA_CHANNEL11_IRQn    = 199U,
    HW_DMA_CHANNEL12_IRQn    = 200U,
    HW_DMA_CHANNEL13_IRQn    = 201U,
    HW_DMA_CHANNEL14_IRQn    = 202U,
    HW_DMA_CHANNEL15_IRQn    = 203U,
    HW_DMA_CHANNEL16_IRQn    = 204U,
    HW_DMA_CHANNEL17_IRQn    = 205U,
    HW_DMA_CHANNEL18_IRQn    = 206U,
    HW_DMA_CHANNEL19_IRQn    = 207U,
    HW_DMA_CHANNEL20_IRQn    = 208U,
    HW_DMA_CHANNEL21_IRQn    = 209U,
    HW_DMA_CHANNEL22_IRQn    = 210U,
    HW_DMA_CHANNEL23_IRQn    = 211U,
    HW_DMA_CHANNEL24_IRQn    = 212U,
    HW_DMA_CHANNEL25_IRQn    = 213U,
    HW_DMA_CHANNEL26_IRQn    = 214U,
    HW_DMA_CHANNEL27_IRQn    = 215U,
    HW_DMA_CHANNEL28_IRQn    = 216U,
    HW_DMA_CHANNEL29_IRQn    = 217U,
    HW_DMA_CHANNEL30_IRQn    = 218U,
    HW_DMA_CHANNEL31_IRQn    = 219U,
    HW_DMA_CHANNEL32_IRQn    = 220U,
    HW_DMA_CHANNEL33_IRQn    = 221U,
    HW_DMA_CHANNEL34_IRQn    = 222U,
    HW_DMA_CHANNEL35_IRQn    = 223U,
    HW_DMA_CHANNEL36_IRQn    = 224U,
    HW_DMA_CHANNEL37_IRQn    = 225U,
    HW_DMA_CHANNEL38_IRQn    = 226U,
    HW_DMA_CHANNEL39_IRQn    = 227U,
    HW_DMA_CHANNEL40_IRQn    = 228U,
    HW_DMA_CHANNEL41_IRQn    = 229U,
    HW_DMA_CHANNEL42_IRQn    = 230U,
    HW_DMA_CHANNEL43_IRQn    = 231U,
    HW_DMA_CHANNEL44_IRQn    = 232U,
    HW_DMA_CHANNEL45_IRQn    = 233U,
    HW_DMA_CHANNEL46_IRQn    = 234U,
    HW_DMA_CHANNEL47_IRQn    = 235U,
    HW_DMA_CHANNEL48_IRQn    = 236U,
    HW_DMA_CHANNEL49_IRQn    = 237U,
    HW_DMA_CHANNEL50_IRQn    = 238U,
    HW_DMA_CHANNEL51_IRQn    = 239U,
    HW_DMA_CHANNEL52_IRQn    = 240U,
    HW_DMA_CHANNEL53_IRQn    = 241U,
    HW_DMA_CHANNEL54_IRQn    = 242U,
    HW_DMA_CHANNEL55_IRQn    = 243U,
    HW_DMA_CHANNEL56_IRQn    = 244U,
    HW_DMA_CHANNEL57_IRQn    = 245U,
    HW_DMA_CHANNEL58_IRQn    = 246U,
    HW_DMA_CHANNEL59_IRQn    = 247U,
    HW_DMA_CHANNEL60_IRQn    = 248U,
    HW_DMA_CHANNEL61_IRQn    = 249U,
    HW_DMA_CHANNEL62_IRQn    = 250U,
    HW_DMA_CHANNEL63_IRQn    = 251U,
    HW_CANFD0_IRQn           = 252U,
    HW_CANFD1_IRQn           = 253U,
    HW_CANFD2_IRQn           = 254U,
    HW_CANFD3_IRQn           = 255U,
    HW_CANFD4_IRQn           = 256U,
    HW_CANFD5_IRQn           = 257U,
    HW_CANFD6_IRQn           = 258U,
    HW_CANFD7_IRQn           = 259U,
    HW_CANFD8_IRQn           = 260U,
    HW_CANFD9_IRQn           = 261U,
    HW_CANFD10_IRQn          = 262U,
    HW_CANFD11_IRQn          = 263U,
    HW_CANFD12_IRQn          = 264U,
    HW_CANFD13_IRQn          = 265U,
    HW_CANFD14_IRQn          = 266U,
    HW_CANFD15_IRQn          = 267U,
    HW_CAN_RESERVED0_IRQn    = 268U,
    HW_CAN_RESERVED1_IRQn    = 269U,
    HW_CAN_RESERVED2_IRQn    = 270U,
    HW_CAN_RESERVED3_IRQn    = 271U,
    HW_CAN_RESERVED4_IRQn    = 272U,
    HW_CAN_RESERVED5_IRQn    = 273U,
    HW_CAN_RESERVED6_IRQn    = 274U,
    HW_CAN_RESERVED7_IRQn    = 275U,
    HW_CAN_RESERVED8_IRQn    = 276U,
    HW_CAN_RESERVED9_IRQn    = 277U,
    HW_CAN_RESERVED10_IRQn   = 278U,
    HW_CAN_RESERVED11_IRQn   = 279U,
    HW_CAN_RESERVED12_IRQn   = 280U,
    HW_CAN_RESERVED13_IRQn   = 281U,
    HW_CAN_RESERVED14_IRQn   = 282U,
    HW_CAN_RESERVED15_IRQn   = 283U,
    HW_CAN_RESERVED16_IRQn   = 284U,
    HW_CAN_RESERVED17_IRQn   = 285U,
    HW_CAN_RESERVED18_IRQn   = 286U,
    HW_CAN_RESERVED19_IRQn   = 287U,
    HW_CAN_RESERVED20_IRQn   = 288U,
    HW_CAN_RESERVED21_IRQn   = 289U,
    HW_CAN_RESERVED22_IRQn   = 290U,
    HW_CAN_RESERVED23_IRQn   = 291U,
    HW_CAN_RESERVED24_IRQn   = 292U,
    HW_CAN_RESERVED25_IRQn   = 293U,
    HW_CAN_RESERVED26_IRQn   = 294U,
    HW_CAN_RESERVED27_IRQn   = 295U,
    HW_CAN_RESERVED28_IRQn   = 296U,
    HW_CAN_RESERVED29_IRQn   = 297U,
    HW_CAN_RESERVED30_IRQn   = 298U,
    HW_CAN_RESERVED31_IRQn   = 299U,
    HW_CAN_RESERVED32_IRQn   = 300U,
    HW_CAN_RESERVED33_IRQn   = 301U,
    HW_CAN_RESERVED34_IRQn   = 302U,
    HW_CAN_RESERVED35_IRQn   = 303U,
    HW_CAN_RESERVED36_IRQn   = 304U,
    HW_CAN_RESERVED37_IRQn   = 305U,
    HW_CAN_RESERVED38_IRQn   = 306U,
    HW_CAN_RESERVED39_IRQn   = 307U,
    HW_CAN_RESERVED40_IRQn   = 308U,
    HW_CAN_RESERVED41_IRQn   = 309U,
    HW_CAN_RESERVED42_IRQn   = 310U,
    HW_CAN_RESERVED43_IRQn   = 311U,
    HW_CAN_RESERVED44_IRQn   = 312U,
    HW_CAN_RESERVED45_IRQn   = 313U,
    HW_CAN_RESERVED46_IRQn   = 314U,
    HW_CAN_RESERVED47_IRQn   = 315U,
    HW_CAN_RESERVED48_IRQn   = 316U,
    HW_CAN_RESERVED49_IRQn   = 317U,
    HW_CAN_RESERVED50_IRQn   = 318U,
    HW_CAN_RESERVED51_IRQn   = 319U,
    HW_CAN_RESERVED52_IRQn   = 320U,
    HW_CAN_RESERVED53_IRQn   = 321U,
    HW_CAN_RESERVED54_IRQn   = 322U,
    HW_CAN_RESERVED55_IRQn   = 323U,
    HW_CAN_RESERVED56_IRQn   = 324U,
    HW_CAN_RESERVED57_IRQn   = 325U,
    HW_CAN_RESERVED58_IRQn   = 326U,
    HW_CAN_RESERVED59_IRQn   = 327U,
    HW_CAN_RESERVED60_IRQn   = 328U,
    HW_CAN_RESERVED61_IRQn   = 329U,
    HW_CAN_RESERVED62_IRQn   = 330U,
    HW_CAN_RESERVED63_IRQn   = 331U,
    HW_ADC_GROUP0SR0_IRQn    = 332U,
    HW_ADC_GROUP0SR1_IRQn    = 333U,
    HW_ADC_GROUP0SR2_IRQn    = 334U,
    HW_ADC_GROUP0SR3_IRQn    = 335U,
    HW_ADC_GROUP1SR0_IRQn    = 336U,
    HW_ADC_GROUP1SR1_IRQn    = 337U,
    HW_ADC_GROUP1SR2_IRQn    = 338U,
    HW_ADC_GROUP1SR3_IRQn    = 339U,
    HW_ADC_GROUP2SR0_IRQn    = 340U,
    HW_ADC_GROUP2SR1_IRQn    = 341U,
    HW_ADC_GROUP2SR2_IRQn    = 342U,
    HW_ADC_GROUP2SR3_IRQn    = 343U,
    HW_ADC_GROUP3SR0_IRQn    = 344U,
    HW_ADC_GROUP3SR1_IRQn    = 345U,
    HW_ADC_GROUP3SR2_IRQn    = 346U,
    HW_ADC_GROUP3SR3_IRQn    = 347U,
    HW_ADC_COMGROUP0SR0_IRQn = 348U,
    HW_ADC_COMGROUP0SR1_IRQn = 349U,
    HW_ADC_COMGROUP0SR2_IRQn = 350U,
    HW_ADC_COMGROUP0SR3_IRQn = 351U,
    HW_ADC_COMGROUP1SR0_IRQn = 352U,
    HW_ADC_COMGROUP1SR1_IRQn = 353U,
    HW_ADC_COMGROUP1SR2_IRQn = 354U,
    HW_ADC_COMGROUP1SR3_IRQn = 355U,
    HW_FLASH_ERROR0_IRQn     = 356U,
    HW_FLASH_ERROR1_IRQn     = 357U,
    HW_FLASH_ERROR2_IRQn     = 358U,
    HW_FLASH_ERROR3_IRQn     = 359U,
    HW_FLASH_ERROR4_IRQn     = 360U,
    HW_FLASH_HSM_IRQn        = 361U,
    HW_HSM0_IRQn             = 362U,
    HW_HSM1_IRQn             = 363U,
    HW_HSM2_IRQn             = 364U,
    HW_HSM3_IRQn             = 365U,
    HW_SCU0_ERROR_IRQn       = 366U,
    HW_SCU1_ERROR_IRQn       = 367U,
    HW_SCU2_ERROR_IRQn       = 368U,
    HW_SCU3_ERROR_IRQn       = 369U,
    HW_PMC_DTS_IRQn          = 370U,
    HW_PMC0_IRQn             = 371U,
    HW_PMC1_IRQn             = 372U,
    HW_PMC2_IRQn             = 373U,
    HW_PMC3_IRQn             = 374U,
    HW_SAUC0_IRQn            = 375U,
    HW_SAUC1_IRQn            = 376U,
    HW_SAUC2_IRQn            = 377U,
    HW_PSI50_IRQn            = 378U,
    HW_PSI51_IRQn            = 379U,
    HW_PSI52_IRQn            = 380U,
    HW_PSI53_IRQn            = 381U,
    HW_PSI54_IRQn            = 382U,
    HW_PSI55_IRQn            = 383U,
    HW_PSI56_IRQn            = 384U,
    HW_PSI57_IRQn            = 385U,
    HW_PSI5S0_IRQn           = 386U,
    HW_PSI5S1_IRQn           = 387U,
    HW_PSI5S2_IRQn           = 388U,
    HW_PSI5S3_IRQn           = 389U,
    HW_PSI5S4_IRQn           = 390U,
    HW_PSI5S5_IRQn           = 391U,
    HW_PSI5S6_IRQn           = 392U,
    HW_PSI5S7_IRQn           = 393U,
    HW_EPWM0SR0_IRQn         = 394U,
    HW_EPWM0SR1_IRQn         = 395U,
    HW_EPWM0SR2_IRQn         = 396U,
    HW_EPWM0SR3_IRQn         = 397U,
    HW_EPWM1SR0_IRQn         = 398U,
    HW_EPWM1SR1_IRQn         = 399U,
    HW_EPWM1SR2_IRQn         = 400U,
    HW_EPWM1SR3_IRQn         = 401U,
    HW_EPWM2SR0_IRQn         = 402U,
    HW_EPWM2SR1_IRQn         = 403U,
    HW_EPWM2SR2_IRQn         = 404U,
    HW_EPWM2SR3_IRQn         = 405U,
    HW_EPWM3SR0_IRQn         = 406U,
    HW_EPWM3SR1_IRQn         = 407U,
    HW_EPWM3SR2_IRQn         = 408U,
    HW_EPWM3SR3_IRQn         = 409U,
    HW_EPWM4SR0_IRQn         = 410U,
    HW_EPWM4SR1_IRQn         = 411U,
    HW_EPWM4SR2_IRQn         = 412U,
    HW_EPWM4SR3_IRQn         = 413U,
    HW_EPWM5SR0_IRQn         = 414U,
    HW_EPWM5SR1_IRQn         = 415U,
    HW_EPWM5SR2_IRQn         = 416U,
    HW_EPWM5SR3_IRQn         = 417U,
    HW_EPWM6SR0_IRQn         = 418U,
    HW_EPWM6SR1_IRQn         = 419U,
    HW_EPWM6SR2_IRQn         = 420U,
    HW_EPWM6SR3_IRQn         = 421U,
    HW_EPWM7SR0_IRQn         = 422U,
    HW_EPWM7SR1_IRQn         = 423U,
    HW_EPWM7SR2_IRQn         = 424U,
    HW_EPWM7SR3_IRQn         = 425U,
    HW_EPWM8SR0_IRQn         = 426U,
    HW_EPWM8SR1_IRQn         = 427U,
    HW_EPWM8SR2_IRQn         = 428U,
    HW_EPWM8SR3_IRQn         = 429U,
    HW_EPWM9SR0_IRQn         = 430U,
    HW_EPWM9SR1_IRQn         = 431U,
    HW_EPWM9SR2_IRQn         = 432U,
    HW_EPWM9SR3_IRQn         = 433U,
    HW_EPWM10SR0_IRQn        = 434U,
    HW_EPWM10SR1_IRQn        = 435U,
    HW_EPWM10SR2_IRQn        = 436U,
    HW_EPWM10SR3_IRQn        = 437U,
    HW_EPWM11SR0_IRQn        = 438U,
    HW_EPWM11SR1_IRQn        = 439U,
    HW_EPWM11SR2_IRQn        = 440U,
    HW_EPWM11SR3_IRQn        = 441U,
    HW_EIRU_IRQn             = 442U,
    HW_EWDT_IRQn             = 443U,
    HW_QSPI0_IRQn            = 444U,
    HW_QSPI1_IRQn            = 445U,
    HW_QSPI2_IRQn            = 446U,
    HW_QSPI3_IRQn            = 447U,
    HW_PBCU0_IRQn            = 448U,
    HW_PBCU1_IRQn            = 449U,
    HW_PBCU2_IRQn            = 450U,
    HW_GP0SR0_IRQn           = 496U,
    HW_GP0SR1_IRQn           = 497U,
    HW_GP0SR2_IRQn           = 498U,
    HW_GP0SR3_IRQn           = 499U,
    HW_GP0SR4_IRQn           = 500U,
    HW_GP0SR5_IRQn           = 501U,
    HW_GP0SR6_IRQn           = 502U,
    HW_GP0SR7_IRQn           = 503U,
    HW_GP1SR0_IRQn           = 504U,
    HW_GP1SR1_IRQn           = 505U,
    HW_GP1SR2_IRQn           = 506U,
    HW_GP1SR3_IRQn           = 507U,
    HW_GP1SR4_IRQn           = 508U,
    HW_GP1SR5_IRQn           = 509U,
    HW_GP1SR6_IRQn           = 510U,
    HW_GP1SR7_IRQn           = 511U,
} Intr_IrqEnumType;

typedef volatile struct
{
    /* offset  : 0x0000.  */
    KF_SRC_GCPU_T CPU;
    /* offset  : 0x0008.  */
    uint32_t RESERVED0[4];
    /* offset  : 0x0018.  */
    KF_SRC_GUTLIN_T UTLIN;
    /* offset  : 0x0078.  */
    KF_SRC_GMTU_T MTU;
    /* offset  : 0x007C.  */
    KF_SRC_GSPI_T SPI;
    /* offset  : 0x00CC.  */
    uint32_t RESERVED1[2];
    /* offset  : 0x00D4.  */
    KF_SRC_GQSPI_T QSPI;
    /* offset  : 0x00E4.  */
    KF_SRC_GCLK_T CLK;
    /* offset  : 0x00E8.  */
    KF_SRC_GIIC_T IIC;
    /* offset  : 0x0128.  */
    KF_SRC_GSENT_T SENT;
    /* offset  : 0x0150.  */
    KF_SRC_GMSC_T MSC;
    /* offset  : 0x0178.  */
    KF_SRC_GRTC_T RTC;
    /* offset  : 0x017C.  */
    KF_SRC_GBPT_T BPT;
    /* offset  : 0x018C.  */
    KF_SRC_GAPT_T APT;
    /* offset  : 0x02BC.  */
    KF_SRC_GQEI_T QEI;
    /* offset  : 0x02C8.  */
    KF_SRC_GHRCAP_T HECAP;
    /* offset  : 0x02D4.  */
    uint32_t RESERVED2[3];
    /* offset  : 0x02E0.  */
    KF_SRC_GSYSTICK_T SYSTICK;
    /* offset  : 0x02F0.  */
    uint32_t RESERVED3[2];
    /* offset  : 0x02F8.  */
    KF_SRC_GCRC_T CRC;
    /* offset  : 0x02FC.  */
    KF_SRC_GDMA_T DMA;
    /* offset  : 0x040C.  */
    KF_SRC_GCANFD_T CANFD;
    /* offset  : 0x042C.  */
    uint32_t RESERVED4[8];
    /* offset  : 0x044C.  */
    KF_SRC_GADC_T ADC;
    /* offset  : 0x04BC.  */
    KF_SRC_GFLASH_T FLASH;
    /* offset  : 0x04C0.  */
    uint32_t RESERVED5[4];
    /* offset  : 0x04D0.  */
    KF_SRC_GHSM_T HSM;
    /* offset  : 0x04E0.  */
    KF_SRC_GSCU_T SCU;
    /* offset  : 0x04F0.  */
    KF_SRC_GPMCDTS_T PMCDTS;
    /* offset  : 0x04F4.  */
    KF_SRC_GPMC_T PMC;
    /* offset  : 0x0504.  */
    KF_SRC_GSACU_T SACU;
    /* offset  : 0x0510.  */
    KF_SRC_GPSI5_T PSI5;
    /* offset  : 0x0530.  */
    KF_SRC_GPSI5S_T PSI5S;
    /* offset  : 0x0550.  */
    KF_SRC_GEPWM_T EPWM;
    /* offset  : 0x0610.  */
    KF_SRC_GPSR_T GPSR;
    /* offset  : 0x0650.  */
    uint32_t RESERVED6[108];
} INT_SRC_STRUCT_T;

typedef volatile union
{
    INT_SRC_T        SRC[512];
    INT_SRC_STRUCT_T INT_SRC_STRUCT;
} KF_SRC_T;

typedef volatile struct
{
    /* offset  : 0x0000.  */
    KF_SRC_T INT_SRC;

    /* offset  : 0x0800.  */
    uint32_t INT_RESERVED[512];

    /* offset  : 0x1000.  */
    INT_ID_T INT_ID;

    /* offset  : 0x1004.  */
    INT_CFG0_T INT_CFG0;

    /* offset  : 0x1008.  */
    INT_CFG1_T INT_CFG1;

    /* offset  : 0x100C.  */
    INT_ACES_SRB0_T INT_ACES_SRB0[2];

    /* offset  : 0x1014.  */
    INT_ACES_SRB1_T INT_ACES_SRB1[2];

    /* offset  : 0x101C.  */
    INT_ACES_TOS0_T INT_ACES_TOS0[3];

    /* offset  : 0x1028.  */
    INT_ACES_TOS1_T INT_ACES_TOS1[3];

    /* offset  : 0x1034.  */
    INT_LWSR_T INT_LWSR[3];

    /* offset  : 0x1040.  */
    INT_LASR_T INT_LASR[3];

    /* offset  : 0x104C.  */
    INT_ECR_T INT_ECR[3];

    /* offset  : 0x1058.  */
    INT_SRB_T INT_SRB[2];

    /* offset  : 0x1060.  */
    INT_MODE_T INT_MODE[3];

    /* offset  : 0x106C.  */
    INT_TIMOUT_T INT_TIMOUT[4];

    /* offset  : 0x107C.  */
    INT_TIMSEL_T INT_TIMSEL[4];

    /* offset  : 0x108C.  */
    OOBS_T OOBS;

    /* offset  : 0x1090.  */
    OSSIC_T OSSIC;

    /* offset  : 0x1094.  */
    OIXTS_T OIXTS;

    /* offset  : 0x1098.  */
    OIXMS_T OIXMS;

    /* offset  : 0x109C.  */
    OIXS_T OIXS[2];

    /* offset  : 0x10A4.  */
    OIT_T OIT;

    /* offset  : 0x10A8.  */
    OMISP_T OMISP;

    /* offset  : 0x10AC.  */
    OMISN_T OMISN;

} Int_RegisterMap_t;

#define INT_ADDR ((uint32_t)0xF0030000)
#define INT_PTR  ((Int_RegisterMap_t *)INT_ADDR)
#define INT_RM   (*(Int_RegisterMap_t *)INT_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
