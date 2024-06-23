/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_reg_crcs.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-20
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
 *  |2023-12-20  |V1.0     |Sun Wanyu       | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_REG_CRCS_H_
#define _KF32DA13K_REG_CRCS_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf_types.h"
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
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁止请求位  */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁止状态  */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_CLC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MOD_REV    :8;  /*!< [7:0] CRC模块版本号  */
            __I uint32_t MOD_TYPE   :8;  /*!< [15:8] CRC模块类型  */
            __I uint32_t MOD_NUMBER :16; /*!< [31:16] CRC模块编号  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CLR       :1;  /*!< [0:0] 复位状态清除位(读出为0)  */
            __I uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_RSTCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位请求位(与CRC_RST0寄存器的RST位一起使用) */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST    :1; /*!< [0:0] 模块复位请求位（与CRC_RST1寄存器的RST位一起使用） */
            __I uint32_t  RSTSTA :1; /*!< [1:1] 复位状态  */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_ACES1_T;

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
} CRC_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CH0       :1;  /*!< [0:0] 该位是通道0不同状态或操作的结果  */
            __I uint32_t CH1       :1;  /*!< [1:1] 该位是通道1不同状态或操作的结果  */
            __I uint32_t CH2       :1;  /*!< [2:2] 该位是通道2不同状态或操作的结果  */
            __I uint32_t CH3       :1;  /*!< [3:3] 该位是通道3不同状态或操作的结果  */
            __I uint32_t CH4       :1;  /*!< [4:4] 该位是通道4不同状态或操作的结果  */
            __I uint32_t CH5       :1;  /*!< [5:5] 该位是通道5不同状态或操作的结果  */
            __I uint32_t CH6       :1;  /*!< [6:6] 该位是通道6不同状态或操作的结果  */
            __I uint32_t CH7       :1;  /*!< [7:7] 该位是通道7不同状态或操作的结果  */
            __I uint32_t RESERVED0 :24; /*!< [31:8] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_CHSTS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RSET      :1;  /*!< [0:0] CRC计算单元复位控制位。  */
            __I uint32_t  RESERVED0 :1;  /*!< [1:1] 预留读为0  */
            __IO uint32_t DATASIZE  :2;  /*!< [3:2] 输入数据格式控制位  */
            __IO uint32_t DATAREV1  :1;  /*!< [4:4] 输入数据位反序控制位1。  */
            __IO uint32_t DATAREV   :1;  /*!< [5:5] 输入数据位反序控制位。  */
            __IO uint32_t RSLTREV1  :1;  /*!< [6:6] CRC结果位反序控制位1。  */
            __IO uint32_t RSLTREV   :1;  /*!< [7:7] CRC结果位反序控制位。  */
            __IO uint32_t MOD       :3;  /*!< [10:8] CRC模式选择  */
            __I uint32_t  RESERVED1 :5;  /*!< [15:11] 预留读为0  */
            __IO uint32_t CCE       :1;  /*!< [16:16] CRC检测比较  */
            __IO uint32_t ALR       :1;  /*!< [17:17] 自动长度加载  */
            __I uint32_t  RESERVED2 :14; /*!< [31:18] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_CTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CRCDATA :32; /*!< [31:0] CRCs输入数据寄存器。  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_DATA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CRCRSLT :32; /*!< [31:0] CRCs结果寄存器  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_RSLT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CRCINTI :32; /*!< [31:0] CRCs初始值寄存器。  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_INIT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CRCPLN :32; /*!< [31:0] CRCs多项式寄存器。  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_PLN_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CRCRXOR :32; /*!< [31:0] CRCs结果异或值寄存器。  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_RXOR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CRCIDATA :32; /*!< [31:0] CRCs独立数据寄存器。  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_IDATA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CRCTEMP :32; /*!< [31:0] CRCs缓存寄存器。  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_TEMP_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LENGTH :16; /*!< [15:0] 表示计算数据的数量或长度。  */
            __I uint32_t  CNT    :16; /*!< [31:16] 表示目前数据已计算的个数  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_LENGTH_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CHECK :32; /*!< [31:0] 当长度寄存器计数值等于长度值时硬件将期望的CRC值与结果值进行比较  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_CHECK_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :1;  /*!< [0:0] 预留读为0  */
            __IO uint32_t FRAMCFG   :1;  /*!< [1:1] 配置寄存器匹配错误  */
            __IO uint32_t FRAMCHECK :1;  /*!< [2:2] 校验寄存器错误匹配  */
            __IO uint32_t FRAMPLN   :1;  /*!< [3:3] 多项式寄存器错误匹配  */
            __IO uint32_t FRAMINIT  :1;  /*!< [4:4] 初始值寄存器错误匹配  */
            __IO uint32_t FRAMRXOR  :1;  /*!< [5:5] 结果异或值寄存器错误匹配  */
            __IO uint32_t FRAMDATA  :1;  /*!< [6:6] 输入数据寄存器错误匹配  */
            __IO uint32_t FRAMIDATA :1;  /*!< [7:7] 独立寄存器错误匹配。  */
            __I uint32_t  RESERVED1 :24; /*!< [31:8] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_TEST_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CNTEND    :1;  /*!< [0:0] 计数结束标志位  */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_STATE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CMIF      :1;  /*!< [0:0] 比较错误标志位  */
            __I uint32_t CHECKIF   :1;  /*!< [1:1] 检测寄存器错误标志位  */
            __I uint32_t LEIF      :1;  /*!< [2:2] 长度错误标志位  */
            __I uint32_t CFGIF     :1;  /*!< [3:3] 描述寄存器错误标志位  */
            __I uint32_t PLNIF     :1;  /*!< [4:4] 多项式寄存器错误标志位  */
            __I uint32_t INITIF    :1;  /*!< [5:5] 初始值寄存器错误标志位  */
            __I uint32_t RXORIF    :1;  /*!< [6:6] 结果异或值寄存器错误标志位  */
            __I uint32_t DATAIF    :1;  /*!< [7:7] 数据寄存器错误标志位  */
            __I uint32_t IDATAIF   :1;  /*!< [8:8] 独立数据寄存器错误标志位 */
            __I uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_IF_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CMIC      :1;  /*!< [0:0] 清零中断请求标志位IFi.CMIF  */
            __O uint32_t CHECKIC   :1;  /*!< [1:1] 清零中断请求标志位IFi.CHECKIF*/
            __O uint32_t LEIC      :1;  /*!< [2:2] 清零中断请求标志位IFi.LEIF  */
            __O uint32_t CFGIC     :1;  /*!< [3:3] 清零中断请求标志位IFi.CFGIF*/
            __O uint32_t PLNIC     :1;  /*!< [4:4] 清零中断请求标志位IFi.PLNIF*/
            __O uint32_t INITIC    :1;  /*!< [5:5] 清零中断请求标志位IFi.INITIF*/
            __O uint32_t RXORIC    :1;  /*!< [6:6] 清零中断请求标志位IFi.RXORAIF*/
            __O uint32_t DATAIC    :1;  /*!< [7:7] 清零中断请求标志位IFi.DATAIF*/
            __O uint32_t IDATAIC   :1;  /*!< [8:8] 清零中断请求标志位IFi.IDATAIF*/
            __I uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_IC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CMIS      :1;  /*!< [0:0] 置位中断请求标志位IFi.CMIF  */
            __O uint32_t CHECKIS   :1;  /*!< [1:1] 置位中断请求标志位IFi.CHECKIF */
            __O uint32_t LEIS      :1;  /*!< [2:2] 置位中断请求标志位IFi.LEIF  */
            __O uint32_t CFGIS     :1;  /*!< [3:3] 置位中断请求标志位IFi.CFGIF */
            __O uint32_t PLNIS     :1;  /*!< [4:4] 置位中断请求标志位IFi.PLNIF */
            __O uint32_t INITIS    :1;  /*!< [5:5] 置位中断请求标志位IFi.INITIF */
            __O uint32_t RXORIS    :1;  /*!< [6:6] 置位中断请求标志位IFi.RXORAIF */
            __O uint32_t DATAIS    :1;  /*!< [7:7] 置位中断请求标志位IFi.DATAIF */
            __O uint32_t IDATAIS   :1;  /*!< [8:8] 置位中断请求标志位IFi.IDATAIF */
            __I uint32_t RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_IS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CMIE      :1;  /*!< [0:0] 启用中断请求CMIF。  */
            __IO uint32_t CHECKIE   :1;  /*!< [1:1] 启用中断请求CHECKIF。  */
            __IO uint32_t LEIE      :1;  /*!< [2:2] 启用中断请求LEIF。  */
            __IO uint32_t CFGIE     :1;  /*!< [3:3] 启用中断请求CFGIF。  */
            __IO uint32_t PLNIE     :1;  /*!< [4:4] 启用中断请求PLNIF。  */
            __IO uint32_t INITIE    :1;  /*!< [5:5] 启用中断请求INITIF。  */
            __IO uint32_t RXORIE    :1;  /*!< [6:6] 启用中断请求RXORIF。  */
            __IO uint32_t DATAIE    :1;  /*!< [7:7] 启用中断请求DATAIF。  */
            __IO uint32_t IDATAIE   :1;  /*!< [8:8] 启用中断请求IDATAIF。  */
            __I uint32_t  RESERVED0 :23; /*!< [31:9] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_IE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TMEN      :1;  /*!< [0:0] 测试模式使能  */
            __IO uint32_t TMSEL     :2;  /*!< [1:2] 测试引脚功能位  */
            __I uint32_t  RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CRC_TM_T;

typedef volatile struct
{
    CRC_CTL_T    CRC_CTL;
    CRC_DATA_T   CRC_DATA;
    CRC_RSLT_T   CRC_RSLT;
    CRC_INIT_T   CRC_INIT;
    CRC_PLN_T    CRC_PLN;
    CRC_RXOR_T   CRC_RXOR;
    CRC_IDATA_T  CRC_IDATA;
    CRC_TEMP_T   CRC_TEMP;
    CRC_LENGTH_T CRC_LENGTH;
    CRC_CHECK_T  CRC_CHECK;
    CRC_TEST_T   CRC_TEST;
    CRC_STATE_T  CRC_STATE;
    CRC_IF_T     CRC_IF;
    CRC_IC_T     CRC_IC;
    CRC_IS_T     CRC_IS;
    CRC_IE_T     CRC_IE;
} CRC_T;

typedef volatile struct
{
    /* offset: 0x0000 */
    CRC_CLC_T CRC_CLC;
    /* offset: 0x0004 */
    CRC_INFO_T CRC_INFO;
    /* offset:  0x0008*/
    uint32_t RESERVED0;
    /* offset:  0x000C*/
    CRC_RSTCLR_T CRC_RSTCLR;
    /* offset:  0x0010*/
    CRC_RST1_T CRC_RST1;
    /* offset:  0x0014*/
    CRC_RST0_T CRC_RST0;
    /* offset:  0x0018*/
    CRC_ACES1_T CRC_ACES1;
    /* offset: 0x001C */
    CRC_ACES0_T CRC_ACES0;
    /* offset: 0x0020 */
    CRC_CHSTS_T CRC_CHSTS;
    /* offset: 0x0024 */
    CRC_T    CRC[7];
    /* offset: 0x0028 */
    CRC_TM_T CRC_TM;
} Crcs_RegisterMap_t;

#define CRCS_ADDR ((uint32_t)0xF4098000)
#define CRCS_PTR  ((Crcs_RegisterMap_t *)CRCS_ADDR)
#define CRCS_RM   (*(Crcs_RegisterMap_t *)CRCS_ADDR)
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
