/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_flash.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyright protected and proprietary to
 * Shanghai ChipON Micro-Electronic Co.,Ltd
 **************************************************************************/

#ifndef _KF32DA13K_REG_FLASH_H_
#define _KF32DA13K_REG_FLASH_H_

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
            __I uint32_t MOD_REV  :8;  /*!< [7:0] 模块修订号此位字段表示平台模块的修订号  */
            __I uint32_t MOD_TYPE :12; /*!< [15:4] 模块类型此位域是01H，它定义了一个32位模块  */
            __I uint32_t MOD_NUMBER :16; /*!< [31:16] 模块编号此位域定义了模块标识号。此端口模块值为0001H  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_ID_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              D0BUSY :1; /*!< [0:0]
                            DFlash0忙状态标志位指示DFlash0忙状态，忙态也显示在DFlash0启动过程中或休眠状态下。在忙态下不允许对DF1读访问。
                          */
            __I uint32_t
              D1BUSY :1; /*!< [1:1]
                            DFlash1忙状态标志位指示DFlash1忙状态，忙态也显示在DFlash1启动过程中或休眠状态下。在忙态下不允许对DF1读访问。
                          */
            __I uint32_t
              P0BUSY :1; /*!< [2:2]
                            PFlash0忙状态标志位指示PFlash1忙状态，忙态也显示在PFlash1启动过程中或休眠状态下。在忙态下不允许对PF1读访问。
                          */
            __I uint32_t
              P1BUSY :1; /*!< [3:3]
                            PFlash1忙状态标志位指示PFlash1忙状态，忙态也显示在PFlash1启动过程中或休眠状态下。在忙态下不允许对PF1读访问。
                          */
            __I uint32_t RESERVED0 :2;
            __I uint32_t DMOD      :1; /*!< [6:6] 编程擦除控制器进入DFlash操作模式的状态标志位  */
            __I uint32_t PMOD      :1; /*!< [7:7] 编程擦除控制器进入PFlash操作模式的状态标志位  */
            __I uint32_t PWMOD     :1; /*!< [8:8] 编程擦除控制器进入解保护模式的状态标志位  */
            __I uint32_t SIGDONE   :1; /*!< [9:9] 校验和计算完成状态位  */
            __I uint32_t RESERVED1 :20;
            __I uint32_t REDUNLOCK :1; /*!< [30:30] 冗余替换解锁状态位  */
            __I uint32_t PEUNLOCK :1; /*!< [31:31] 编程擦除控制器解锁状态位。解锁需要向FLASH_EPKEYR寄存器写入特定KEY序列
                                       */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t CD0       :1; /*!< [0:0] 清除DFlash0忙状态标志位  */
            __O uint32_t CD1       :1; /*!< [1:1] 清除DFlash1忙状态标志位  */
            __O uint32_t CP0       :1; /*!< [2:2] 清除PFlash0忙状态标志位  */
            __O uint32_t CP1       :1; /*!< [3:3] 清除PFlash1忙状态标志位  */
            __I uint32_t RESERVED0 :4;
            __O uint32_t CSIG      :1; /*!< [8:8] 清除SIG完成计算状态  */
            __O uint32_t CPROG     :1; /*!< [9:9] 清除正在编程状态  */
            __O uint32_t CERASE    :1; /*!< [10:10] 清除擦除状态  */
            __O uint32_t CXPROG    :1; /*!< [11:11] 清除擦除状态  */
            __I uint32_t RESERVED1 :18;
            __O uint32_t REDLOCK :1; /*!< [30:30] 上锁冗余替换功能，同时清除状态标志位FLASH_STA.REDUNLOCK  */
            __O uint32_t PELOCK :1; /*!< [31:31] 上锁Flash编程擦除控制器，同时清除状态标志位FLASH_STA.PEUNLOCK  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CRL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :4;
            __IO uint32_t ENPE      :2; /*!< [5:4] 使能编程与擦除  */
            __I uint32_t  RESERVED1 :1;
            __IO uint32_t WSERRINJ :1; /*!< [7:7] PFlash等待状态ECC错误注入错误注入ECC逻辑保护PFlash等待状态  */
            __IO uint32_t
              DDFP :1; /*!< [8:8]
                          禁止读访问PFlash该位域可自动复位设置，在启动过程中UCB_PF_RPROCFG的配置信息可设置该位域。被清零PFlash读保护:当FLASH_PROSTA.PRODISP=1或PF_RPROCFG.RPRO=0时，可自动清零该位域。软件直接设置PFlash读保护:该位域置1。
                        */
            __IO uint32_t
              DDFD :1; /*!< [9:9]
                          在DF0_EEPROM端禁止取数据此位域使能或禁止从DF0_EEPROM取数据。在启动过程中DF_PROCTL.RPRO的配置信息可设置该位域。被清零PFlash读保护:当FLASH_PROSTA.PRODISD=1或DF_PROCTL.RPRO=0时会清除DDFD的值。软件直接写1设置DFlash0读保护:用户可直接设置DF0_EEPROM存储区域读保护
                        */
            __I uint32_t RESERVED2 :22;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PEMOD :2; /*!< [1:0] 控制编程擦除控制器进入PFlash操作模式或DFlash操作模式。  */
            __O uint32_t PGM  :1; /*!< [2:2] 触发编程命令，令编程擦除控制器执行编程序列  */
            __O uint32_t OPGM :1;
            __O uint32_t ERS  :1; /*!< [4:4] 触发擦除命令，令编程擦除控制器执行擦除序列  */
            __O uint32_t XPGM :1; /*!< [5:5] 触发快速编程命令，令快速编程擦除控制器执行编程序列  */
            __O uint32_t  OXPGM     :1; /*!< [6:6] */
            __O uint32_t  REDM      :1; /*!< [7:7] 触发冗余替换命令  */
            __O uint32_t  SIGGO     :1; /*!< [8:8] 启动SIG计算  */
            __I uint32_t  RESERVED0 :7;
            __IO uint32_t ERMOD     :2; /*!< [17:16] 在触发擦除命令同时选择擦除模式  */
            __I uint32_t  RESERVED1 :14;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_OPE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              PROG :1; /*!< [0:0] 正在编程状态标志位，主指令接口HCI的状态标志。通过写1到FLASH_CRL.CPROG来清除该标志位 */
            __I uint32_t ERASE :1; /*!< [1:1] 擦除状态，主指令接口HCI的状态标志。通过写1到FLASH_CRL.CERAS来清除该标志位
                                    */
            __I uint32_t XPROG     :1; /*!< [2:2] 正在快速编程状态标志位  */
            __I uint32_t RESERVED0 :5;
            __I uint32_t PRODONE   :1;
            __I uint32_t ERASDONE  :1;
            __I uint32_t XPROGDONE :1;
            __I uint32_t RESERVED1 :21; /*!< [31:11] 保留  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_OPESTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t KEY :32; /*!< [31:0]
                                     向该寄存器连续写入特定的KEY1和KEY2值，可将FLASH_STA.PEUNLOCK状态标志位置1。  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_PEKEYR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t KEY :32; /*!< [31:0]
                                     向该寄存器连续写入特定的KEY1和KEY2值，可将FLASH_STA.REDUNLOCK状态标志位置1。  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_REDKEYR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              PDATA :32; /*!< [31:0]
                            为编程或快速编程提供数据。最小单位编程中使用PEDATA0和PEDATA1进行64bit编程，批量编程中需要用32个PEDATAx进行1024位的快速编程
                          */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_PEDATAx_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ADR :32; /*!< [31:0] 向编程擦除控制器提供编程逻辑地址或擦除的扇/块逻辑地址。  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_PELADR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ADR :32; /*!< [31:0] 显示编程擦除控制器操作逻辑地址对应的物理地址，支持PFlash与DFlash。  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_PEPADR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ADR :32; /*!< [31:0] 向编程擦除控制器提供快速编程逻辑地址。  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_XPELADR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ADR :32; /*!< [31:0] 显示编程擦除控制器快速编程操作逻辑地址对应的物理地址，支持PFlash与DFlash。
                                   */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_XPEPADR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ADR :32; /*!< [31:0] 为冗余替换指令提供故障扇区的逻辑地址，地址必须每扇区对齐。  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_REDLADR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint16_t TIMSET :16; /*!< [15:0] 配置编程擦除看门狗定时器的周期时间。周期时间为T=TIMSET*0.1us  */
            __I uint32_t RESERVED0 :16;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_PETIMECTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CKSTADDR :32; /*!< [31:0] 计算CheckSum的首地址  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CSSTART_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CKSPADDR :32; /*!< [31:0] 计算CheckSum的尾地址  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CSSTOP_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CKSPRES0 :32; /*!< [31:0] CheckSum结果寄存器0  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CSRES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CKSPRES1 :32; /*!< [31:0] CheckSum结果寄存器1  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CSRES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CKSPRES2 :32; /*!< [31:0] CheckSum结果寄存器2  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CSRES2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t CKSPRES3 :32; /*!< [31:0] CheckSum结果寄存器3  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CSRES3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              RRODISP :1; /*!< [0:0]
                             解除PFlash保护PFlash保护通过UCB_PFLASH_ORIG和UCB_PFLASH_COPY配置的，通过“解保护指令”输入正确密钥解除PFlash保护，该位域被置1。
                           */
            __I uint32_t
              PRODISD :1; /*!< [1:1]
                             解除DFlash保护DFlash保护通过UCB_DFLASH_ORIG和UCB_DFLASH_COPY配置的，通过“解保护指令”输入正确密钥解除DFlash保护，该位域被置1。
                           */
            __I uint32_t
              PRODISDBG :1; /*!< [2:2]
                               解除调试接口密码保护由UCB_DBG_ORIG和UCB_DBG_COPY配置调试接口保护，通过“解保护指令”输入正确密钥解除调试密码接口，该位域被置1。
                             */
            __I uint32_t
              PRODISEC :1; /*!< [3:3]
                              解除擦除计数器优先级保护由UCB_ECPRIO_ORIG和UCB_ECPRIO_COPY配置擦除计数器优先级保护，通过“解保护指令”输入正确密钥解除该保护，位域被置1。
                            */
            __I uint32_t
              PRODISBMHD :1; /*!< [4:4]
                                解除BMHD保护由UCB_BMHD0_ORIG和UCB_BMHD0_COPY配置BMHD保护，通过“解保护指令”输入正确密钥解除该保护，位域被置1。
                              */
            __I uint32_t
              PRODISSWAP :1; /*!< [5:5]
                                解除UCB_SWAP保护由UCB_SWAP_ORIG和UCB_SWAP_COPY配置UCB_SWAP保护，通过“解保护指令”输入正确密钥解除该保护，位域被置1。
                              */
            __I uint32_t RESERVED0 :10;
            __I uint32_t SRT       :1; /*!< [16:16] 解除安全重测密码保护  */
            __I uint32_t RESERVED1 :15;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_PROSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t BMHD0O :2; /*!< [1:0] UCB_BMHD0_ORIG确认状态此位域反映UCB_BMHD0_ORIG已确认的状态  */
            __I uint32_t BMHD1O :2; /*!< [3:2] UCB_BMHD1_ORIG确认状态此位域反映UCB_BMHD1_ORIG已确认的状态  */
            __I uint32_t RESERVED0 :4;
            __I uint32_t SSW       :2; /*!< [9:8] UCB_SSW确认状态此位域反映UCB_SSW已确认的状态  */
            __I uint32_t USER      :2; /*!< [11:10] UCB_USER确认状态此位域反映UCB_USER已确认的状态  */
            __I uint32_t TEST      :2; /*!< [13:12] UCB_TEST确认状态此位域反映UCB_TEST已确认的状态  */
            __I uint32_t HSMCFG :2; /*!< [15:14] UCB_HSMCFG确认状态此位域反映UCB_HSMCFG已确认的状态  */
            __I uint32_t BMHD0C :2; /*!< [17:16] UCB_BMHD0_COPY确认状态此位域反映UCB_BMHD0_COPY已确认的状态  */
            __I uint32_t BMHD1C :2; /*!< [19:18] UCB_BMHD0_COPY确认状态此位域反映UCB_BMHD1_COPY已确认的状态  */
            __I uint32_t RESERVED1 :4;
            __I uint32_t REDSEC :2; /*!< [25:24] UCB_REDSEC确认状态此位域反映UCB_REDSEC已确认的状态  */
            __I uint32_t RESERVED2 :4; /*!< [29:26] 预留  */
            __I uint32_t RETEST :2; /*!< [31:30] UCB_RETEST确认状态此位域反映UCB_RETEST已确认的状态  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CFMSTA0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t PO :2; /*!< [1:0] UCB_PFLASH_ORIG确认状态此位域反映UCB_PFLASH_ORIG已确认的状态  */
            __I uint32_t DO :2; /*!< [3:2] UCB_DFLASH_ORIG确认状态此位域反映UCB_DFLASH_ORIG已确认的状态  */
            __I uint32_t DBGO :2; /*!< [5:4] UCB_DBG_ORIG确认状态此位域反映UCB_DBG_ORIG已确认的状态  */
            __I uint32_t HSMO :2; /*!< [7:6] UCB_HSM_ORIG确认状态此位域反映UCB_HSM_ORIG已确认的状态  */
            __I uint32_t HSMCOTPO :2; /*!< [9:8] UCB_HSMCONTP_ORIG确认状态此位域反映UCB_HSMCONTP_ORIG已确认的状态  */
            __I uint32_t RESERVED0 :2;
            __I uint32_t ECO :2; /*!< [13:12] UCB_ECPRIO_ORIG确认状态此位域反映UCB_ECPRIO_ORIG已确认的状态  */
            __I uint32_t SWAPO :2; /*!< [15:14] UCB_SWAP_ORIG确认状态此位域反映UCB_SWAP_ORIG已确认的状态  */
            __I uint32_t PC :2; /*!< [17:16] UCB_PFLASH_COPY确认状态此位域反映UCB_PFLASH_COPY已确认的状态  */
            __I uint32_t DC :2; /*!< [19:18] UCB_DFLASH_COPY确认状态此位域反映UCB_DFLASH_COPY已确认的状态  */
            __I uint32_t DBGC :2; /*!< [21:20] UCB_DBG_COPY确认状态此位域反映UCB_DBG_COPY已确认的状态  */
            __I uint32_t HSMC :2; /*!< [23:22] UCB_HSM_COPY确认状态此位域反映UCB_HSM_COPY已确认的状态  */
            __I uint32_t HSMCOTPC :2; /*!< [25:24] UCB_HSMCOTP_COPY确认状态此位域反映UCB_HSMCOTP_COPY已确认的状态  */
            __I uint32_t RESERVED1 :2;
            __I uint32_t ECPC :2; /*!< [29:28] UCB_ECPRIO_COPY确认状态此位域反映UCB_ECPRIO_COPY已确认的状态  */
            __I uint32_t SWAPC :2; /*!< [31:30] UCB_SWAP_COPY确认状态此位域反映UCB_SWAP_COPY已确认的状态  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CFMSTA1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t OTPO :2; /*!< [1:0] UCB_OTP_ORIG确认状态此位域反映UCB_OTP_ORIG已确认的状态  */
            __I uint32_t OTPC :2; /*!< [3:2] UCB_OTP_COPY确认状态此位域反映UCB_OTP_COPY已确认的状态  */
            __I uint32_t RESERVED0 :28;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_CFMSTA2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OPERM     :1;  /*!< [0:0] 操作错误中断掩码  */
            __IO uint32_t SQERM     :1;  /*!< [1:1] 编程擦除控制器HCI接口指令错误中断掩码  */
            __IO uint32_t PROERM    :1;  /*!< [2:2] 保护错误中断掩码  */
            __IO uint32_t PVERM     :1;  /*!< [3:3] 编程校验错误中断掩码  */
            __IO uint32_t EVERM     :1;  /*!< [4:4] 擦除校验错误中断掩码  */
            __IO uint32_t WDERM     :1;  /*!< [5:5] 编程擦除看门狗超时中断掩码  */
            __I uint32_t  RESERVED0 :25; /*!< [30:6] 预留  */
            __IO uint32_t EOBM      :1;  /*!< [31:31] 忙信号结束中断掩码  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_EERIE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t OPER  :1; /*!< [0:0] Flash操作错误  */
            __I uint32_t SQER  :1; /*!< [1:1] 指令序列错误  */
            __I uint32_t PROER :1; /*!< [2:2] 保护错误，例如编程与擦除的地址扇区已上锁。  */
            __I uint32_t PVER  :1; /*!< [3:3] 编程校验错误，报告编程操作结束后的错误。  */
            __I uint32_t EVER  :1; /*!< [4:4] 擦除校验错误  */
            __I uint32_t ADER :1; /*!< [5:5] SRI总线地址ECC错误，Flash控制器FMC检测到ECC错误在SRI总线地址传输期间  */
            __I uint32_t ORIER :1; /*!< [6:6] ORIG错误在UCB的ORIG确认状态期间检测到ORIG状态错误或未纠正ECC错误。  */
            __I uint32_t WDER      :1;  /*!< [7:7] 编程擦除操作中看门狗定时器超时错误  */
            __I uint32_t RESERVED0 :24; /*!< [31:8] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_ERRSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t COPER     :1; /*!< [0:0] 清除操作错误标志  */
            __O uint32_t CSQER     :1; /*!< [1:1] 清除指令错误标志  */
            __O uint32_t CPPOER    :1; /*!< [2:2] 清除保护错误标志  */
            __O uint32_t CPVER     :1; /*!< [3:3] 清除编程校验错误标志  */
            __O uint32_t CEVER     :1; /*!< [4:4] 清除擦除校验错误标志  */
            __O uint32_t CADER     :1; /*!< [5:5] 清除SRI总线地址ECC错误  */
            __O uint32_t CWDER     :1; /*!< [6:6] 清除看门狗超时错误状态标志位  */
            __I uint32_t RESERVED0 :25;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_ERRCLR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              RCODE :22;                /*!< [21:0]
                                           ECC纠错码，在NVM读访问最后时ECC校验和当读取通过SRI从接口启动时，该位域存储最后一次读访问DF0(包含UCB)和DF1(非专业HSM)的校验后。
                                         */
            __I uint32_t RESERVED0 :10; /*!< [31:22] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} DF_ECCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ERR1 :1; /*!< [0:0]
                                     读访问单bitECC错误此标志位报告单bitECC故障在最后一次读访问DF0或非HSM专用的DF1时  */
            __I uint32_t ERR2 :1; /*!< [1:1]
                                     读访问双bitECC错误此标志位报告双bitECC故障在最后一次读访问DF0或非HSM专用的DF1时  */
            __I uint32_t ERRM :1; /*!< [2:2]
                                     读访问多bitECC错误此标志位报告多bitECC故障在最后一次读访问DF0或非HSM专用的DF1时  */
            __I uint32_t RESERVED0 :4;
            __I uint32_t
              ERRANY :1; /*!< [7:7] 任何读访问ECC错误此标志位报告至少一个ECC故障在最后一次读访问DF0或非HSM专用的DF1时 */
            __I uint32_t RESERVED1 :8;
            __I uint32_t AER1 :1; /*!< [16:16] 累计单bitECC错误此状态标志位累计单bit故障在DF0或非HSM专用的DF1读操作期间
                                   */
            __I uint32_t AER2 :1; /*!< [17:17] 累计双bitECC错误此状态标志位累计双bit故障在DF0或非HSM专用的DF1读操作期间
                                   */
            __I uint32_t RESERVED2 :1;
            __I uint32_t AERM :1; /*!< [19:19] 累计多bitECC错误此状态标志位累计多bit故障在DF0或非HSM专用的DF1读操作期间
                                   */
            __I uint32_t RESERVED3 :3;
            __I uint32_t AERANY    :1; /*!< [23:23]
                                          累计任何读访问ECC错误此状态标志位累计ECC故障在DF0或非HSM专用的DF1读操作期间  */
            __I uint32_t RESERVED4 :8;
        } bits;
        __IO uint32_t reg;
    };
} DF_ECCSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  CLR       :2;  /*!< [1:0] 清除ECC状态  */
            __I uint32_t  RESERVED0 :26; /*!< [27:2] 预留  */
            __IO uint32_t ECCCORDIS :2;  /*!< [29:28] 禁止DF0与DF1(非HSM专用)读路径上的ECC纠正  */
            __IO uint32_t
              TRAPDIS :2; /*!< [31:30]
                             对于DF0和非HSM专用的DF1，如果读路径上无法纠正的ECC错误，通过TRAPDIS位域禁止生成总线错误陷阱。
                           */
        } bits;
        __IO uint32_t reg;
    };
} DF_ECCCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t WCODE :22; /*!< [21:0] 写入ECC纠错码替换数据集中DFlash128-bit或DPFlash128-bit的ECC纠错码  */
            __I uint32_t  RESERVED0 :6; /*!< [27:22] 预留  */
            __IO uint32_t PECENCDIS :2; /*!< [29:28] PFlashECC编码禁用  */
            __IO uint32_t DECENCDIS :2; /*!< [31:30] DFlashECC编码禁用  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_ECCW_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODE      :2;  /*!< [1:0] DF0用户模式控制  */
            __I uint32_t RESERVED0 :30; /*!< [31:2] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} DF_UMOD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SLEEP     :1; /*!< [0:0] 休眠模式  */
            __I uint32_t IDLE      :1; /*!< [1:1] 空闲模式  */
            __I uint32_t RESERVED0 :30;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_PWRSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SLEEP :2; /*!< [1:0] 休眠模块控制，FLASH_PWRSTA.SLEEP确定是否进入休眠模式  */
            __I uint32_t  RESERVED0 :6;
            __O uint32_t  IDLE      :2; /*!< [9:8] 动态进入空闲模式使能  */
            __O uint32_t  DEMAND    :2; /*!< [11:10] PFlash直取模式使能  */
            __I uint32_t  RESERVED1 :4;
            __IO uint32_t ESLDIS    :2; /*!< [17:16] 禁用请求休眠模式  */
            __I uint32_t  RESERVED2 :12;
            __IO uint32_t PR5V      :2; /*!< [31:30] 编程时供电5V，选择编程电压  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_PWRCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RPF :6; /*!< [5:0] 操作模式下PFlash等待周期数此位域定义一个PFlash读访问的SRI时钟周期数  */
            __I uint32_t RESERVED0 :2;
            __IO uint32_t RPECC :3; /*!< [10:8] 操作模式下PFlash错误纠正周期数。此位域定义PFlashECC校正的SRI时钟周期数
                                     */
            __I uint32_t RESERVED1 :5;
            __IO uint32_t RDF :5; /*!< [20:16] 操作模式下DFlash等待周期数此位域定义一个DFlash读访问的SRI时钟周期数  */
            __I uint32_t RESERVED2 :3;
            __IO uint32_t RDECC :3; /*!< [26:24] 操作模式下DFlash错误纠正周期数。此位域定义DFlashECC校正的SRI时钟周期数
                                     */
            __I uint32_t RESERVED3 :5;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_PWAIT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :31; /*!< [30:0] 预留  */
            __I uint32_t RPRO :1; /*!< [31:31] 读保护配置此位域指示是否为PFlash扇区配置了读保护  */
        } bits;
        __IO uint32_t reg;
    };
} PF_RPROCFG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t TP        :1; /*!< [0:0] Tuning保护此位域指示是否安装了Tuning保护。  */
            __I uint32_t RESERVED0 :7;
            __I uint32_t BML       :2; /*!< [9:8] Boot模式锁定通过SSW延迟Boot模式的选择  */
            __I uint32_t RESERVED1 :6;
            __I uint32_t SWAPEN    :2; /*!< [17:16]
                                          使能SOTA模式，此位域使能进入SOTA模式，在这模式下，PFlash映射方式选择备用地址映射
                                        */
            __I uint32_t CPU0DDIS  :1; /*!< [18:18] 禁止直接访问CPU0到本地的PFlash0  */
            __I uint32_t CPU1DDIS  :1; /*!< [19:19] 禁止直接访问CPU1到本地的PFlash1  */
            __I uint32_t RESERVED2 :12;
        } bits;
        __IO uint32_t reg;
    };
} PF_TPROCFG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t WPRO :1; /*!< [0:0] DF0_EEPROM为写保护锁此位域指示DFlashEEPROM扇区是否有写保护  */
            __I uint32_t RESERVED0 :30;
            __I uint32_t RPRO :1; /*!< [31:31] 读保护配置此位域指示DFlash扇区是否配置为读保护  */
        } bits;
        __IO uint32_t reg;
    };
} DF_PROCFG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t HYSEN :1; /*!< [0:0] 滞后使能当OSCCFG使能后，则这个位域的值将被复制到OSC_CTL0.HYSEN  */
            __I uint32_t HYSCTL :2; /*!< [2:1] 滞后控制当OSCCFG使能后，则这个位域的值将被复制到OSC_CTL0.HYSMOD  */
            __I uint32_t AMPMOD :2; /*!< [4:3] 振幅控制当OSCCFG使能后，则这个位域的值将被复制到OSC_CTL0.AMPMOD  */
            __I uint32_t
              OSCCFG :1; /*!< [5:5]
                            通过SSW配置OSC此位域指示振荡器的配置信息(HYSEN、HYSCTL、AMPMOD、OSCMOD、APREN、CAPxENx=0-3)可以通过SSW安装到OSC控制寄存器中
                          */
            __I uint32_t OSCMOD :2; /*!< [7:6] OSC模式当OSCCFG使能后，则这个位域的值将被复制到OSC_CTL0.OSCMOD  */
            __I uint32_t APREN :1; /*!< [8:8] OSC振幅调节使能当OSCCFG使能后，则这个位域的值将被复制到OSC_CTL0.APREN  */
            __I uint32_t CAP0EN :1; /*!< [9:9] OSC内部电容0使能当OSCCFG使能后，则这个位域的值将被复制到OSC_CTL1.CAP0EN
                                     */
            __I uint32_t CAP1EN :1; /*!< [10:10] OSC内部电容1使能当OSCCFG使能后，则这个位域的值将被复制到OSC_CTL1.CAP1EN
                                     */
            __I uint32_t CAP2EN :1; /*!< [11:11] OSC内部电容2使能当OSCCFG使能后，则这个位域的值将被复制到OSC_CTL1.CAP2EN
                                     */
            __I uint32_t CAP3EN :1; /*!< [12:12] OSC内部电容3使能当OSCCFG使能后，则这个位域的值将被复制到OSC_CTL1.CAP3EN
                                     */
            __I uint32_t RESERVED0 :3;
            __I uint32_t ESR0CNT   :12; /*!< [27:16] ESR0延长计数器用于配置ESR0的延时，通过SSW导入  */
            __I uint32_t RESERVED1 :4;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_OSCCFG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              RAMIN :2; /*!< [1:0]
                           通过SSW控制RAM初始化，这位域定义RAMINSELx与LRAMINSELx选择的RAM是否被初始化。该位域确定是否在授予MBIST访问权限之前初始化RAM。在所有“Init_”的情况下，RAM在启用MBIST访问之前被初始化，在“NoInit”的情况下，RAM不被擦除。
                         */
            __I uint32_t RESERVED0  :14;
            __I uint32_t RAMINSEL0  :1; /*!< [16:16] 选择初始化CPU0内PRAM、DRAM、ICache、DCache  */
            __I uint32_t RAMINSEL1  :1; /*!< [17:17] 选择初始化CPU1内PRAM、DRAM、ICache、DCache  */
            __I uint32_t RAMINSEL2  :1; /*!< [18:18] 选择初始化CPU2内PRAM、DRAM、ICache、DCache  */
            __I uint32_t RESERVED1  :5;
            __I uint32_t LRAMINSEL0 :1; /*!< [24:24] 选择初始化CPU0内LRAM0  */
            __I uint32_t LRAMINSEL1 :1; /*!< [24:24] 选择初始化CPU1内LRAM1  */
            __I uint32_t LRAMINSEL2 :1; /*!< [24:24] 选择初始化CPU2内LRAM2  */
            __I uint32_t LRAMINSEL3 :1; /*!< [24:24] 选择初始化全局的GRAM和DAM  */
            __I uint32_t RESERVED2  :4;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_RAMINITCFG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t OCDSDIS  :1; /*!< [0:0] 禁用OCDS此位域指示OCDS是否配置为锁定  */
            __I uint32_t DBGIFLCK :1; /*!< [1:1] 调试接口锁定此位域指示调试接口是否配置为锁定  */
            __I uint32_t EDM :2; /*!< [3:2] 进入调试模式此位域指示是否已通过“DestructiveDebugEntry”将打开调试接口  */
            __I uint32_t TIC :4; /*!< [11:8] 工具接口控制CAN物理层上的DAP接口(DXCPL)。  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_DBGCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SELD0     :2; /*!< [1:0] DF0Margin_Read选择  */
            __I uint32_t  RESERVED0 :6;
            __IO uint32_t HMARGIN   :1; /*!< [8:8] 硬件margin选择  */
            __I uint32_t  RESERVED1 :23;
        } bits;
        __IO uint32_t reg;
    };
} FLASH_MARGIN_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EN0  :1; /*!< [0:0] 权限使能用于主机TAGID0  */
            __IO uint32_t EN1  :1; /*!< [1:1] 权限使能用于主机TAGID1  */
            __IO uint32_t EN2  :1; /*!< [2:2] 权限使能用于主机TAGID2  */
            __IO uint32_t EN3  :1; /*!< [3:3] 权限使能用于主机TAGID3  */
            __IO uint32_t EN4  :1; /*!< [4:4] 权限使能用于主机TAGID4  */
            __IO uint32_t EN5  :1; /*!< [5:5] 权限使能用于主机TAGID5  */
            __IO uint32_t EN6  :1; /*!< [6:6] 权限使能用于主机TAGID6  */
            __IO uint32_t EN7  :1; /*!< [7:7] 权限使能用于主机TAGID7  */
            __IO uint32_t EN8  :1; /*!< [8:8] 权限使能用于主机TAGID8  */
            __IO uint32_t EN9  :1; /*!< [9:9] 权限使能用于主机TAGID9  */
            __IO uint32_t EN10 :1; /*!< [10:10] 权限使能用于主机TAGID10  */
            __IO uint32_t EN11 :1; /*!< [11:11] 权限使能用于主机TAGID11  */
            __IO uint32_t EN12 :1; /*!< [12:12] 权限使能用于主机TAGID12  */
            __IO uint32_t EN13 :1; /*!< [13:13] 权限使能用于主机TAGID13  */
            __IO uint32_t EN14 :1; /*!< [14:14] 权限使能用于主机TAGID14  */
            __IO uint32_t EN15 :1; /*!< [15:15] 权限使能用于主机TAGID15  */
            __IO uint32_t EN16 :1; /*!< [16:16] 权限使能用于主机TAGID16  */
            __IO uint32_t EN17 :1; /*!< [17:17] 权限使能用于主机TAGID17  */
            __IO uint32_t EN18 :1; /*!< [18:18] 权限使能用于主机TAGID18  */
            __IO uint32_t EN19 :1; /*!< [19:19] 权限使能用于主机TAGID19  */
            __IO uint32_t EN20 :1; /*!< [20:20] 权限使能用于主机TAGID20  */
            __IO uint32_t EN21 :1; /*!< [21:21] 权限使能用于主机TAGID21  */
            __IO uint32_t EN22 :1; /*!< [22:22] 权限使能用于主机TAGID22  */
            __IO uint32_t EN23 :1; /*!< [23:23] 权限使能用于主机TAGID23  */
            __IO uint32_t EN24 :1; /*!< [24:24] 权限使能用于主机TAGID24  */
            __IO uint32_t EN25 :1; /*!< [25:25] 权限使能用于主机TAGID25  */
            __IO uint32_t EN26 :1; /*!< [26:26] 权限使能用于主机TAGID26  */
            __IO uint32_t EN27 :1; /*!< [27:27] 权限使能用于主机TAGID27  */
            __IO uint32_t EN28 :1; /*!< [28:28] 权限使能用于主机TAGID28  */
            __IO uint32_t EN29 :1; /*!< [29:29] 权限使能用于主机TAGID29  */
            __IO uint32_t EN30 :1; /*!< [30:30] 权限使能用于主机TAGID30  */
            __IO uint32_t EN31 :1; /*!< [31:31] 权限使能用于主机TAGID31  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_ACCEN0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} FLASH_ACCEN1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              SxL :32; /*!< [31:0]
                          选择PFlash扇区写保护锁定每个bit位指对应PFlash内某个扇区是否被设写保护。n=0-3表示哪个PFlash块，每个PFlash块有32个写保护配置寄存器，共1024个扇区，其中x指PFn块中第i*32+x扇区编号。
                        */
        } bits;
        __IO uint32_t reg;
    };
} PFn_WPCFGi_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              SxROM :32; /*!< [31:0]
                             选择PFlash扇区OTP保护锁定每个bit位指对应PFlash内某个扇区是否被设OTP保护。n=0-3表示哪个PFlash块，每个PFlash有32个写保护配置寄存器，共1024个扇区，其中x指PFn中第i*32+x扇区编号。
                           */
        } bits;
        __I uint32_t reg;
    };
} PFn_OTPCFGi_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              SxL :32; /*!< [31:0]
                           选择PFlash扇区WOP保护锁定每个bit位指对应PFlash内某个扇区是否被设WOP保护。n=0-1表示哪个PFlash块，每个PFlash有32个写保护配置寄存器，共1024个扇区，其中x指PFn中第i*32+x扇区编号。
                         */
        } bits;
        __I uint32_t reg;
    };
} PFn_WOPCFGi_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              SxSEL :32; /*!< [31:0]
                            选择PFlash扇区为擦除计数器高优先级每个bit位指对应PFlash块内某个扇区是否被设擦除计数器高优先级。n=0-3表示哪个PFlash，每个PFlash有32个擦除计数器优先级配置寄存器，共1024个扇区，其中x指PFn块中第i*32+x扇区编号。
                          */
        } bits;
        __I uint32_t reg;
    };
} PFn_ECPCFGi_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t KEY :32; /*!< [31:0]
                                     解锁UCB保护的密钥x(x=0-7)，当PW0-PW7与所选的UCB配置值相匹配时，禁用UCB保护。  */
        } bits;
        __O uint32_t reg;
    };
} FLASH_PWx_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :1;
            __I uint32_t D1BUSY    :1; /*!< [1:1] DFlash1忙状态标志位专用命名接口状态标志位  */
            __I uint32_t RESERVED1 :4;
            __I uint32_t DMOD      :1; /*!< [6:6] 编程擦除控制器进入DFlash操作模式的状态标志位  */
            __I uint32_t RESERVED2 :25;
        } bits;
        __IO uint32_t reg;
    };
} HF_STA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t LCKHSMUCB :2; /*!< [1:0] 锁定对UCB_HSMCFG的访问此位域只能写入“锁”状态，其他写入操作被忽略  */
            __I uint32_t RESERVED0 :14;
            __O uint32_t CPROG     :1; /*!< [16:16] 清除编程状态  */
            __O uint32_t CERASE    :1; /*!< [17:17] 清除编程状态  */
            __I uint32_t RESERVED1 :14;
        } bits;
        __IO uint32_t reg;
    };
} HF_CFG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SPPEMOD :2; /*!< [1:0] 控制编程擦除控制器的SPCI接口进入PFlash操作模式或DFlash1操作模式。  */
            __O uint32_t SPPGM :1; /*!< [2:2] 触发专用编程命令，令编程擦除控制器执行专用编程序列  */
            __O uint32_t SPERS :1; /*!< [3:3] 触发专用擦除命令，令编程擦除控制器执行专用擦除序列  */
            __I uint32_t  RESERVED0 :12;
            __IO uint32_t SPERMOD   :2; /*!< [17:16] 在触发专用擦除命令同时选择擦除模式  */
            __I uint32_t  RESERVED1 :14;
        } bits;
        __IO uint32_t reg;
    };
} HF_OPE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              PROG :1; /*!< [0:0]
                          正在编程状态设置在编程命令或快速编程命令的最后一个周期。如果一个BUSY标志被偶然地设置，PROG指示一个BUSY状态的类型。如果OPER恰好被设置，PROG指示错误操作的类型。否则，PROG表示该操作仍被请求或已完成。
                        */
            __I uint32_t
              ERASE :1; /*!< [1:1]
                           擦除状态设置在擦除命令序列的最后一个周期。类似于PROG标志。可通过HF_CTL.CERASE清除该标志位
                         */
            __I uint32_t RESERVED0 :30;
        } bits;
        __IO uint32_t reg;
    };
} HF_OPSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PDATA :32; /*!< [31:0] 为HSM专用编程提供数据。最小单位编程中使用PEDATA0和PEDATA1进行64bit编程
                                      */
        } bits;
        __IO uint32_t reg;
    };
} HF_PEDATAx_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              ADR :32; /*!< [31:0]
                          向编程擦除控制器提供专用接口的编程/擦除逻辑地址。该地址指向HSM专用的PFlash0或DFlash1。
                        */
        } bits;
        __IO uint32_t reg;
    };
} HF_PELADR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              ADR :32; /*!< [31:0]
                          显示编程擦除控制器专用接口的编程/擦除逻辑地址，支持HSM专用PFlash0与HSM专用的DFlash1。
                        */
        } bits;
        __IO uint32_t reg;
    };
} HF_PEPADR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t OPERM     :1;  /*!< [0:0] 操作错误中断掩码  */
            __IO uint32_t SQERM     :1;  /*!< [1:1] 编程擦除控制器专用接口指令错误中断掩码  */
            __IO uint32_t PROERM    :1;  /*!< [2:2] 保护错误中断掩码  */
            __IO uint32_t PVERM     :1;  /*!< [3:3] 编程校验错误中断掩码  */
            __IO uint32_t EVERM     :1;  /*!< [4:4] 擦除校验错误中断掩码  */
            __IO uint32_t WDERM     :1;  /*!< [5:5] 编程擦除看门狗超时中断掩码  */
            __I uint32_t  RESERVED0 :25; /*!< [30:6] 预留  */
            __IO uint32_t EOBM      :1;  /*!< [31:31] 忙信号结束中断掩码  */
        } bits;
        __IO uint32_t reg;
    };
} HF_EERIE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t OPER      :1; /*!< [0:0] Flash操作错误  */
            __I uint32_t SQER      :1; /*!< [1:1] 指令错误  */
            __I uint32_t RESERVED0 :1;
            __I uint32_t PVER      :1; /*!< [3:3] 编程校验错误，报告编程操作结束后的错误。  */
            __I uint32_t EVER      :1; /*!< [4:4] 擦除校验错误  */
            __I uint32_t RESERVED1 :2;
            __I uint32_t WDER      :1; /*!< [7:7] 编程擦除操作中看门狗定时器超时错误  */
            __I uint32_t RESERVED2 :24;

        } bits;
        __IO uint32_t reg;
    };
} HF_EERSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :1;
            __O uint32_t CSQER     :1; /*!< [1:1] 清除指令错误标志  */
            __I uint32_t RESERVED1 :1;
            __O uint32_t CPVER     :1; /*!< [3:3] 清除编程校验错误标志  */
            __O uint32_t CEVER     :1; /*!< [4:4] 清除擦除校验错误标志  */
            __O uint32_t CWDER     :1; /*!< [5:5] 清除编程擦除操作中看门狗定时器超时错误  */
            __I uint32_t RESERVED2 :26;
        } bits;
        __IO uint32_t reg;
    };
} HF_CLRE_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RCODE     :22; /*!< [21:0] ECC纠错码在最后一次读访问DFlash1时读取ECC校验和  */
            __I uint32_t RESERVED0 :10; /*!< [31:22] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} HF_ECCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ERR1 :1; /*!< [0:0]
                                     读访问单bitECC错误此标志位报告单bitECC故障在最后一次读访问DF0或非HSM专用的DF1时  */
            __I uint32_t ERR2 :1; /*!< [1:1]
                                     读访问双bitECC错误此标志位报告双bitECC故障在最后一次读访问DF0或非HSM专用的DF1时  */
            __I uint32_t ERRM :1; /*!< [2:2]
                                     读访问多bitECC错误此标志位报告多bitECC故障在最后一次读访问DF0或非HSM专用的DF1时  */
            __I uint32_t RESERVED0 :4;
            __I uint32_t ERRANY    :1; /*!< [7:7]
                                          任何读访问ECC错误此标志位报告多bitECC故障在最后一次读访问DF0或非HSM专用的DF1时 */
            __I uint32_t RESERVED1 :8;
            __I uint32_t AER1 :1; /*!< [16:16] 累计单bitECC错误此状态标志位累计单bit故障在DFlash1读操作期间  */
            __I uint32_t AER2 :1; /*!< [16:16] 累计双bitECC错误此状态标志位累计双bit故障在DFlash1读操作期间  */
            __I uint32_t RESERVED2 :1;
            __I uint32_t AERM :1; /*!< [19:19] 累计多bitECC错误此状态标志位累计多bit故障在DFlash1读操作期间  */
            __I uint32_t RESERVED3 :3;
            __I uint32_t AERANY :1; /*!< [23:23] 累计任何读访问ECC错误此状态标志位累计ECC故障在DFlash1读操作期间  */
            __I uint32_t RESERVED4 :8;
        } bits;
        __IO uint32_t reg;
    };
} HF_ECCSTA_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  CLR       :2;  /*!< [1:0] 清除ECC状态  */
            __I uint32_t  RESERVED0 :26; /*!< [27:2] 预留  */
            __IO uint32_t ECCCORDIS :2;  /*!< [29:28] 禁止读访问DF1时ECC纠正  */
            __IO uint32_t TRAPDIS   :2;  /*!< [31:30]
                                            对于DF1，如果出行无法纠正的ECC错误，通过TRAPDIS位域禁止生成总线错误陷阱。  */
        } bits;
        __IO uint32_t reg;
    };
} HF_ECCCTL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t WCODE :22; /*!< [21:0] 写入ECC纠错码替换数据集中DFlash128-bit或DPFlash128-bit的ECC纠错码  */
            __I uint32_t  RESERVED0 :6; /*!< [27:22] 预留  */
            __IO uint32_t ECCENCDIS :2; /*!< [31:30] DFlash1ECC编码禁用  */
        } bits;
        __IO uint32_t reg;
    };
} HF_ECCW_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODE :2; /*!< [1:0] DF1用户模式控制当用户有控制DF1控制权限时，配置DF1模式  */
            __I uint32_t RESERVED0 :30;
        } bits;
        __IO uint32_t reg;
    };
} HF_UMOD_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SELD1     :2; /*!< [1:0] DF1Margin_Read选择  */
            __I uint32_t  RESERVED0 :6;
            __IO uint32_t HMARGIN   :1; /*!< [8:8] 硬件margin选择  */
            __I uint32_t  RESERVED1 :23;
        } bits;
        __IO uint32_t reg;
    };
} HF_MARGIN_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t HSMBOOTEN :1; /*!< [0:0] HSMBoot使能  */
            __I uint32_t SSWWAIT :1; /*!< [1:1] SSW等待定义SSW是否等待HSM释放CPU0到用户代码的跳转  */
            __I uint32_t HSMDX :1; /*!< [2:2] HSM数据扇区专用此位域定义DFlash1逻辑扇区EEPROMx是否被配置成HSM专用  */
            __I uint32_t RESERVED0  :1;
            __I uint32_t HSMRAMKEEP :2; /*!< [5:4] HSMRAM清除  */
            __I uint32_t RESERVED1  :1;
            __I uint32_t
              HSMENPINS :2; /*!< [8:7]
                               使能引脚HSM1/2的HSM强控制性此位域指示HSM是否可以强控制引脚HSM1/2的值，例如覆盖应用程序驱动的引脚值
                             */
            __I uint32_t HSMENRES :2; /*!< [10:9] 使能HSM触发复位此位指示HSM是否可触发应用程序或系统复位  */
            __I uint32_t DESTDBG   :2; /*!< [12:11] 破坏调试入口此位域配置破坏性调试入口  */
            __I uint32_t BLKFLAN   :1; /*!< [13:13] 阻止Flash分析擦除命令在HSM程序范围内被阻止的  */
            __I uint32_t RESERVED2 :18;
        } bits;
        __IO uint32_t reg;
    };
} HF_PROCFG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t BOOTSEL0  :6;  /*!< [5:0] 选择PFlash0中的哪个块为HSM程序区中为Boot代码块区  */
            __I uint32_t BOOTSEL1  :6;  /*!< [11:6] 选择PFlash0中的块为Boot代码块区  */
            __I uint32_t RESERVED0 :20; /*!< [31:12] 预留  */
        } bits;
        __IO uint32_t reg;
    };
} HF_CBSCFG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              HSM0X :1; /*!< [0:0]
                           选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                         */
            __I uint32_t
              HSM1X :1; /*!< [1:1]
                           选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                         */
            __I uint32_t
              HSM2X :1; /*!< [2:2]
                           选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                         */
            __I uint32_t
              HSM3X :1; /*!< [3:3]
                           选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                         */
            __I uint32_t
              HSM4X :1; /*!< [4:4]
                           选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                         */
            __I uint32_t
              HSM5X :1; /*!< [5:5]
                           选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                         */
            __I uint32_t
              HSM6X :1; /*!< [6:6]
                           选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                         */
            __I uint32_t
              HSM7X :1; /*!< [7:7]
                           选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                         */
            __I uint32_t
              HSM8X :1; /*!< [8:8]
                           选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                         */
            __I uint32_t
              HSM9X :1; /*!< [9:9]
                           选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                         */
            __I uint32_t
              HSM10X :1; /*!< [10:10]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM11X :1; /*!< [11:11]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM12X :1; /*!< [12:12]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM13X :1; /*!< [13:13]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM14X :1; /*!< [14:14]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM15X :1; /*!< [15:15]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM16X :1; /*!< [16:16]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM17X :1; /*!< [17:17]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM18X :1; /*!< [18:18]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM19X :1; /*!< [19:19]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM20X :1; /*!< [20:20]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM21X :1; /*!< [21:21]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM22X :1; /*!< [22:22]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM23X :1; /*!< [23:23]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM24X :1; /*!< [24:24]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM25X :1; /*!< [25:25]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM26X :1; /*!< [26:26]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM27X :1; /*!< [27:27]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM28X :1; /*!< [28:28]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM29X :1; /*!< [29:29]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM30X :1; /*!< [30:30]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
            __I uint32_t
              HSM31X :1; /*!< [31:31]
                            选择PFlash0中S0到S319扇区中设置为HSM专用扇区。每个bit位指对应PFlash内某个扇区是否被设HSM专用，其中x指PF0块中第i*32+x扇区编号。
                          */
        } bits;
        __IO uint32_t reg;
    };
} HF_EXPCFGi_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t
              HSM0ROM :1; /*!< [0:0]
                             选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                           */
            __I uint32_t
              HSM1ROM :1; /*!< [1:1]
                             选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                           */
            __I uint32_t
              HSM2ROM :1; /*!< [2:2]
                             选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                           */
            __I uint32_t
              HSM3ROM :1; /*!< [3:3]
                             选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                           */
            __I uint32_t
              HSM4ROM :1; /*!< [4:4]
                             选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                           */
            __I uint32_t
              HSM5ROM :1; /*!< [5:5]
                             选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                           */
            __I uint32_t
              HSM6ROM :1; /*!< [6:6]
                             选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                           */
            __I uint32_t
              HSM7ROM :1; /*!< [7:7]
                             选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                           */
            __I uint32_t
              HSM8ROM :1; /*!< [8:8]
                             选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                           */
            __I uint32_t
              HSM9ROM :1; /*!< [9:9]
                             选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                           */
            __I uint32_t
              HSM10ROM :1; /*!< [10:10]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM11ROM :1; /*!< [11:11]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM12ROM :1; /*!< [12:12]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM13ROM :1; /*!< [13:13]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM14ROM :1; /*!< [14:14]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM15ROM :1; /*!< [15:15]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM16ROM :1; /*!< [16:16]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM17ROM :1; /*!< [17:17]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM18ROM :1; /*!< [18:18]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM19ROM :1; /*!< [19:19]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM20ROM :1; /*!< [20:20]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM21ROM :1; /*!< [21:21]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM22ROM :1; /*!< [22:22]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM23ROM :1; /*!< [23:23]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM24ROM :1; /*!< [24:24]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM25ROM :1; /*!< [25:25]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM26ROM :1; /*!< [26:26]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM27ROM :1; /*!< [27:27]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM28ROM :1; /*!< [28:28]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM29ROM :1; /*!< [29:29]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM30ROM :1; /*!< [30:30]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
            __I uint32_t
              HSM31ROM :1; /*!< [31:31]
                              选择PFlash0中S0到S319扇区中设置为HSMOTP保护扇区。每个bit位指对应PFlash内某个扇区是否被设OTP保护扇区，其中x指PF0块中第i*32+x扇区编号。
                            */
        } bits;
        __IO uint32_t reg;
    };
} HF_OTPCFGi_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t HSMDBGDIS :1; /*!< [0:0] 禁用HSM调试此位域指示HSM调试是否被配置成禁用状态。  */
            __I uint32_t DBGIFLCK :1; /*!< [1:1] 锁定调试接口此位域指示芯片的调试接口是否被配置成锁定。  */
            __I uint32_t TSTIFLCK :1; /*!< [2:2] 锁定测试接口此位域指示芯片的测试接口是否被配置成锁定。  */
            __I uint32_t HSMTSTDIS :1; /*!< [3:3] HSM测试禁用此位域指示HSM测试是否被配置为禁用  */
            __I uint32_t
              HSMTRDIS :2; /*!< [5:4]
                              HSM跟踪禁用此位域指示通过总线控制单元调试传输情况下HSM跟踪和捕获是否被配置为禁用
                            */
            __I uint32_t HSMTRTYPE :1; /*!< [6:6] HSM跟踪类型此位域指示总线控制单元的HSM传输可捕获哪些信息。  */
            __I uint32_t RESERVED0 :25;
        } bits;
        __IO uint32_t reg;
    };
} HF_IPROCFG_T;

typedef volatile struct
{
    /* address: 0xF9000000 */
    FLASH_ID_T FLASH_ID;

    /* address: 0xF9000004 */
    FLASH_STA_T FLASH_STA;

    /* address: 0xF9000008 */
    FLASH_CRL_T FLASH_CRL;

    /* address: 0xF900000C */
    FLASH_CTL_T FLASH_CTL;

    /* address: 0xF9000010 */
    FLASH_OPE_T FLASH_OPE;

    /* address: 0xF9000014 */
    FLASH_OPESTA_T FLASH_OPESTA;

    /* address: 0xF9000018 */
    FLASH_PEKEYR_T FLASH_PEKEYR;

    /* address: 0xF900001C */
    FLASH_REDKEYR_T FLASH_REDKEYR;

    /* address: 0xF9000020 */
    FLASH_PEDATAx_T FLASH_PEDATAx[32];

    /* address: 0xF90000A0 */
    FLASH_PELADR_T FLASH_PELADR;

    /* address: 0xF90000A4 */
    FLASH_PEPADR_T FLASH_PEPADR;

    /* address: 0xF90000A8 */
    FLASH_XPELADR_T FLASH_XPELADR;

    /* address: 0xF90000AC */
    FLASH_XPEPADR_T FLASH_XPEPADR;

    /* address: 0xF90000B0 */
    FLASH_REDLADR_T FLASH_REDLADR;

    /* address: 0xF90000B4 */
    FLASH_PETIMECTL_T FLASH_PETIMECTL;

    /* address: 0xF90000B8 */
    FLASH_CSSTART_T FLASH_CSSTART;

    /* address: 0xF90000BC */
    FLASH_CSSTOP_T FLASH_CSSTOP;

    /* address: 0xF90000C0 */
    FLASH_CSRES0_T FLASH_CSRES0;

    /* address: 0xF90000C4 */
    FLASH_CSRES1_T FLASH_CSRES1;

    /* address: 0xF90000C8 */
    FLASH_CSRES2_T FLASH_CSRES2;

    /* address: 0xF90000CC */
    FLASH_CSRES3_T FLASH_CSRES3;

    /* address: 0xF90000D0 */
    FLASH_PROSTA_T FLASH_PROSTA;

    /* address: 0xF90000D4 */
    FLASH_CFMSTA0_T FLASH_CFMSTA0;

    /* address: 0xF90000D8 */
    FLASH_CFMSTA1_T FLASH_CFMSTA1;

    /* address: 0xF90000DC */
    FLASH_CFMSTA2_T FLASH_CFMSTA2;

    /* address: 0xF90000E0 */
    FLASH_EERIE_T FLASH_EERIE;

    /* address: 0xF90000E4 */
    FLASH_ERRSTA_T FLASH_ERRSTA;

    /* address: 0xF90000E8 */
    FLASH_ERRCLR_T FLASH_ERRCLR;

    /* address: 0xF90000EC */
    DF_ECCR_T DF_ECCR;

    /* address: 0xF90000F0 */
    DF_ECCSTA_T DF_ECCSTA;

    /* address: 0xF90000F4 */
    DF_ECCCTL_T DF_ECCCTL;

    /* address: 0xF90000F8 */
    FLASH_ECCW_T FLASH_ECCW;

    /* address: 0xF90000FC */
    DF_UMOD_T DF_UMOD;

    /* address: 0xF9000100 */
    FLASH_PWRSTA_T FLASH_PWRSTA;

    /* address: 0xF9000104 */
    FLASH_PWRCTL_T FLASH_PWRCTL;

    /* address: 0xF9000108 */
    FLASH_PWAIT_T FLASH_PWAIT;

    /* address: 0xF900010C */
    PF_RPROCFG_T PF_RPROCFG;

    /* address: 0xF9000110 */
    PF_TPROCFG_T PF_TPROCFG;

    /* address: 0xF9000114 */
    DF_PROCFG_T DF_PROCFG;

    /* address: 0xF9000118 */
    FLASH_OSCCFG_T FLASH_OSCCFG;

    /* address: 0xF900011C */
    FLASH_RAMINITCFG_T FLASH_RAMINITCFG;

    /* address: 0xF9000120 */
    FLASH_DBGCTL_T FLASH_DBGCTL;

    /* address: 0xF9000124 */
    FLASH_MARGIN_T FLASH_MARGIN;

    /* address: 0xF9000128 */
    FLASH_ACCEN0_T FLASH_ACCEN0;

    /* address: 0xF900012C */
    FLASH_ACCEN1_T FLASH_ACCEN1;

    /* address: 0xF9000130 */
    PFn_WPCFGi_T PFn_WPCFGi[6][32];

    /* address: 0xF9000430 */
    PFn_OTPCFGi_T PFn_OTPCFGi[6][32];

    /* address: 0xF9000730 */
    PFn_WOPCFGi_T PFn_WOPCFGi[6][32];

    /* address: 0xF9000A30 */
    PFn_ECPCFGi_T PFn_ECPCFGi[6][32];

    /* address: 0xF9000D30 */
    FLASH_PWx_T FLASH_PWx[8];

    /* address: 0xF9000D50 */
    uint8_t FLASH_RESERVED_F9000D50[288];

    /* address: 0xF9000E70 */
    HF_STA_T HF_STA;

    /* address: 0xF9000E74 */
    HF_CFG_T HF_CFG;

    /* address: 0xF9000E78 */
    HF_OPE_T HF_OPE;

    /* address: 0xF9000E7C */
    HF_OPSTA_T HF_OPSTA;

    /* address: 0xF9000E80 */
    HF_PEDATAx_T HF_PEDATAx[2];

    /* address: 0xF9000E88 */
    HF_PELADR_T HF_PELADR;

    /* address: 0xF9000E8C */
    HF_PEPADR_T HF_PEPADR;

    /* address: 0xF9000E90 */
    HF_EERIE_T HF_EERIE;

    /* address: 0xF9000E94 */
    HF_EERSTA_T HF_EERSTA;

    /* address: 0xF9000E98 */
    HF_CLRE_T HF_CLRE;

    /* address: 0xF9000E9C */
    HF_ECCR_T HF_ECCR;

    /* address: 0xF9000EA0 */
    HF_ECCSTA_T HF_ECCSTA;

    /* address: 0xF9000EA4 */
    HF_ECCCTL_T HF_ECCCTL;

    /* address: 0xF9000EA8 */
    HF_ECCW_T HF_ECCW;

    /* address: 0xF9000EAC */
    HF_UMOD_T HF_UMOD;

    /* address: 0xF9000EB0 */
    HF_MARGIN_T HF_MARGIN;

    /* address: 0xF9000EB4 */
    HF_PROCFG_T HF_PROCFG;

    /* address: 0xF9000EB8 */
    HF_CBSCFG_T HF_CBSCFG;

    /* address: 0xF9000EBC */
    HF_EXPCFGi_T HF_EXPCFGi[10];

    /* address: 0xF9000EE4 */
    HF_OTPCFGi_T HF_OTPCFGi[10];

    /* address: 0xF9000F0C */
    HF_IPROCFG_T HF_IPROCFG;
} Flash_RegisterMap_t;

#define FLASH_ADDR ((uint32_t)0xF9000000)
#define FLASH_PTR  ((Flash_RegisterMap_t *)FLASH_ADDR)
#define FLASH_RM   (*(Flash_RegisterMap_t *)FLASH_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
