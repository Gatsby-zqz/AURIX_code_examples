/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_i2c.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyright protected and proprietary to
 * Shanghai ChipON Micro-Electronic Co.,Ltd
 **************************************************************************/

#ifndef _KF32DA13K_REG_I2C_H_
#define _KF32DA13K_REG_I2C_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *         Include Files
 **************************************************************************/
#include <stdint.h>
#include "kf_types.h"

/**************************************************************************
 *         Macro typedef
 **************************************************************************/

typedef volatile struct
{
    /* offset: 0x0000 */
    union
    {
        struct
        {
            __IO uint32_t DISR      :1;  /*!< [0:0] 模块禁止控制位  */
            __I uint32_t  DISS      :1;  /*!< [1:1] 模块禁止状态  */
            __I uint32_t  RESERVED0 :1;  /*!< [2:2] 预留读为0  */
            __IO uint32_t EDIS      :1;  /*!< [3:3] 休眠模式禁止位  */
            __I uint32_t  RESERVED1 :28; /*!< [31:4] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } CLKC;
    /* offset: 0x0004 */
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] I2C模块版本信息位  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] I2C模块类型信息  */
            __I uint32_t MODNUM  :16; /*!< [31:16] I2C模块编号  */
        } bits;
        __IO uint32_t reg;
    } INFO;
    /* offset: 0x0008 */
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :24; /*!< [23:0] 预留读为0  */
            __IO uint32_t DBGCTL    :4;  /*!< [27:24] 调试模式挂起控制  */
            __O uint32_t  DBGP      :1;  /*!< [28:28] SUS位写保护，读出为0  */
            __I uint32_t  DBGSTA    :1;  /*!< [29:29] 挂起状态位  */
            __I uint32_t  RESERVED1 :2;  /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } DBG;
    /* offset: 0x000C */
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位请求位，与RST1寄存器的RST位一起使用  */
            __I uint32_t  RSTSTA    :1;  /*!< [1:1] 复位状态  */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } RST0;
    /* offset: 0x0010 */
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位请求位，与RST0寄存器的RST位一起使用  */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } RST1;
    /* offset: 0x0014 */
    union
    {
        struct
        {
            __O uint32_t CLR       :1;  /*!< [0:0] RSTSTA复位状态清除位，读出为0  */
            __I uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } RSTCLR;
    /* offset: 0x0018 */
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
    } ACES0;
    /* offset: 0x001C */
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :32; /*!< [31:0] 预留读为0  */
        } bits;
        __I uint32_t reg;
    } ACES1;
    /* offset: 0x0020 */
    uint32_t I2C_RESERVED_F4020020[3];
    /* offset: 0x002C */
    union
    {
        struct
        {
            __IO uint32_t PISEL     :3;  /*!< [2:0] 输入引脚选择位  */
            __I uint32_t  RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } GPCTL;
    /* offset: 0x0030 */
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :8; /*!< [7:0] 预留读为0  */
            __IO uint32_t RMC :8; /*!< [15:8] 标准运行模式时钟分频最大8位分频。若该位设为0，那么模块处于禁用状态。  */
            __I uint32_t RESERVED2 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } CLKC1;
    /* offset: 0x0034 */
    union
    {
        struct
        {
            __IO uint32_t EN        :1;  /*!< [0:0] I2C模块使能  */
            __I uint32_t  RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } ENCTL;
    /* offset: 0x0038 */
    union
    {
        struct
        {
            __IO uint32_t RESTART   :1;  /*!< [0:0] 设置重新启动条件  */
            __O uint32_t  END       :1;  /*!< [1:1] 结束传输  */
            __I uint32_t  RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } ENDCTL;
    /* offset: 0x003C */
    union
    {
        struct
        {
            __IO uint32_t DEC       :11; /*!< [10:0] 波特率DEC值  */
            __I uint32_t  RESERVED0 :5;  /*!< [15:11] 预留读为0  */
            __IO uint32_t INC       :8;  /*!< [23:16] 波特率INC值  */
            __I uint32_t  RESERVED1 :8;  /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } FDIVCFG;
    /* offset: 0x0040 */
    union
    {
        struct
        {
            __IO uint32_t HDEC      :11; /*!< [10:0] 高速模式波特率DEC值  */
            __I uint32_t  RESERVED0 :5;  /*!< [15:11] 预留读为0  */
            __IO uint32_t HINC      :8;  /*!< [23:16] 高速模式波特率INC值  */
            __I uint32_t  RESERVED1 :8;  /*!< [31:24] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } FDIVHCFG;
    /* offset: 0x0044 */
    union
    {
        struct
        {
            __IO uint32_t ADR :10; /*!< [9:0] I2C总线设备地址当设备作为从机被寻址时的地址，配置TBAM可决定7位或10位地址
                                    */
            __I uint32_t  RESERVED0 :6; /*!< [15:10] 预留读为0  */
            __IO uint32_t ADRMOD    :1; /*!< [16:16] 10位地址模式配置  */
            __IO uint32_t GCEN      :1; /*!< [17:17] 广播配置  */
            __IO uint32_t HS        :1; /*!< [18:18] 设备可以处理主机码，支持高速模式  */
            __IO uint32_t MOD       :1; /*!< [19:19] 主/从配置  */
            __IO uint32_t SNOACK    :1; /*!< [20:20] 未应答停止配置位  */
            __IO uint32_t SDEND     :1; /*!< [21:21] 数据包结束停止配置位  */
            __IO uint32_t SMBUS     :1; /*!< [22:22] SMBus模式使能  */
            __IO uint32_t SMBT      :1; /*!< [23:23] SMBus类型  */
            __IO uint32_t ARPEN     :1; /*!< [24:24] ARP使能位  */
            __IO uint32_t ALERT     :1; /*!< [25:25] SMBus提醒。软件可以设置或清除该位(仅SMBus从机)  */
            __IO uint32_t PECEN     :1; /*!< [26:26] PEC使能 */
            __IO uint32_t SENDPEC   :1; /*!< [27:27] 发送数据包错误校验字节 */
            __IO uint32_t RECEPEC   :1; /*!< [28:28] 接收数据包错误校验字节 */
            __IO uint32_t SLAVEBG   :1; /*!< [29:29] 从机控制波特率 */
            __I uint32_t  RESERVED1 :2; /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } CTL;
    /* offset: 0x0048 */
    union
    {
        struct
        {
            __I uint32_t BUSSTA    :2;  /*!< [1:0] I2C总线状态位  */
            __I uint32_t RW        :1;  /*!< [2:2] I2C传输方向状态位  */
            __I uint32_t RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __I uint32_t reg;
    } STA;
    /* offset: 0x004C */
    union
    {
        struct
        {
            __IO uint32_t RXBURST   :2;  /*!< [1:0] 接收突发大小  */
            __I uint32_t  RESERVED0 :2;  /*!< [3:2] 预留读为0  */
            __IO uint32_t TXBURST   :2;  /*!< [5:4] 发送突发大小  */
            __I uint32_t  RESERVED1 :2;  /*!< [7:6] 预留读为0  */
            __IO uint32_t RXBA      :2;  /*!< [9:8] 接收FIFO对齐  */
            __I uint32_t  RESERVED2 :2;  /*!< [11:10] 预留读为0  */
            __IO uint32_t TXBA      :2;  /*!< [13:12] 时间戳中断标志清零位  */
            __IO uint32_t RESERVED3 :2;  /*!< [15:14] 预留读为0  */
            __IO uint32_t RXFLOW    :1;  /*!< [16:16] 接收FIFO流控制配置  */
            __IO uint32_t TXFLOW    :1;  /*!< [17:17] 发送FIFO流控制配置  */
            __IO uint32_t CLRMOD    :1;  /*!< [18:18] 清除请求配置  */
            __IO uint32_t RESERVED4 :13; /*!< [31:19] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } FIFOCTL;
    /* offset: 0x0050 */
    union
    {
        struct
        {
            __IO uint32_t
              MRXB :14;                 /*!< [13:0]
                                           I2C最大接收字节大小写入值范围:0至16383只要前一个数据包RPS值已经加载到相关计数器中，该位域读出值返回为0，此时可以继续写入下一个接收数据包的MRPS值
                                         */
            __I uint32_t RESERVED0 :18; /*!< [31:14] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } MRPSCTL;
    /* offset: 0x0054 */
    union
    {
        struct
        {
            __I uint32_t RXB :14;       /*!< [13:0]
                                           I2C接收字节大小状态值读出值范围:0至16383I2CRXFIFO中已经接收到的数据包的数据字节数；
                                         */
            __I uint32_t RESERVED0 :18; /*!< [31:14] 预留读为0  */
        } bits;
        __I uint32_t reg;
    } RPSSTA;
    /* offset: 0x0058 */
    union
    {
        struct
        {
            __IO uint32_t
              TXB :14;                  /*!< [13:0]
                                           I2C发送字节大小写入值范围:0至16383只要前一个数据包TPS值已经加载到相关计数器中，该位域读出值返回为0，此时可以继续写入下一个发送数据包的TPS值
                                         */
            __I uint32_t RESERVED0 :18; /*!< [31:14] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } TPSCTL;
    /* offset: 0x005C */
    union
    {
        struct
        {
            __I uint32_t FCNT :6; /*!< [5:0] I2CFIFO填充计数I2C模块FIFO中保存有数据的阶段数状态；读出值范围:0至8  */
            __I uint32_t RESERVED0 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __I uint32_t reg;
    } FCNTSTA;
    /* offset: 0x0060 */
    union
    {
        struct
        {
            __IO uint32_t SDALEN  :6; /*!< [5:0] 标准和快速模式下SDA输出数据维持时间延迟阶段数  */
            __IO uint32_t HSDALEN :3; /*!< [8:6] 高速模式下SDA输出数据维持时间延迟阶段数  */
            __IO uint32_t SCLLEN  :3; /*!< [11:9] SCL输出启动(重新启动)条件维持时间延迟阶段数  */
            __I uint32_t  RESERVED0 :2; /*!< [13:12] 预留读为0  */
            __IO uint32_t SCLLOWLEN :1; /*!< [14:14] 快速模式下SCL输出低电平长度直接配置使能  */
            __IO uint32_t SCLLOWSEL :1; /*!< [15:15] 配置快速模式下SCL低电平时序  */
            __IO uint32_t HSPLEN    :5; /*!< [20:16] 高速模式下SDA输出开启/停止位持续时间长度  */
            __I uint32_t  RESERVED1 :3; /*!< [23:21] 预留读为0  */
            __IO uint32_t SCLLOW    :8; /*!< [31:24] 快速模式下SCL输出低电平长度  */
        } bits;
        __IO uint32_t reg;
    } TCTL;
    /* offset: 0x0064 */
    union
    {
        struct
        {
            __I uint32_t ADRMIF      :1; /*!< [0:0] 地址匹配中断标志位  */
            __I uint32_t GCIF        :1; /*!< [1:1] 广播呼叫中断标志位  */
            __I uint32_t MCIF        :1; /*!< [2:2] 主机码(高速模式)中断标志位  */
            __I uint32_t ALERRIF     :1; /*!< [3:3] 仲裁失败中断标志位  */
            __I uint32_t NACKIF      :1; /*!< [4:4] 接收到未应答信号中断标志位  */
            __I uint32_t TXENDIF     :1; /*!< [5:5] 传输结束中断标志位  */
            __I uint32_t RXIF        :1; /*!< [6:6] 接收模式中断标志位  */
            __I uint32_t STARTIF     :1; /*!< [7:7] 起始位中断标志位  */
            __I uint32_t STOPIF      :1; /*!< [8:8] 停止位中断标志位  */
            __I uint32_t BYTEIF      :1; /*!< [9:9] 字节传输中断标志位  */
            __I uint32_t SMBAIF      :1; /*!< [10:10] SMBus模式的提醒中断标志位  */
            __I uint32_t SMBHIF      :1; /*!< [11:11] SMBus模式的主机头地址中断标志位  */
            __I uint32_t SMBDIF      :1; /*!< [12:12] SMBus模式的设备默认地址中断标志位  */
            __I uint32_t ACKTOIF     :1; /*!< [13:13] ACK超时标志位  */
            __I uint32_t HSACKTOIF   :1; /*!< [14:14] 切换到高速模式时超时标志位  */
            __I uint32_t RSTOIF      :1; /*!< [15:15] 重启后超时标志位  */
            __I uint32_t RXUDFIF     :1; /*!< [16:16] RXFIFO下溢中断标志位  */
            __I uint32_t RXOVFIF     :1; /*!< [17:17] RXFIFO上溢中断标志位  */
            __I uint32_t TXUDFIF     :1; /*!< [18:18] TXFIFO下溢中断标志位  */
            __I uint32_t TXOVFIF     :1; /*!< [19:19] TXFIFO上溢中断标志位  */
            __I uint32_t RXLSINGLEIF :1; /*!< [20:20] 最后一次单次接收传输请求中断标志位 */
            __I uint32_t RXSINGLEIF  :1; /*!< [21:21] 单次接收传输请求中断标志位 */
            __I uint32_t RXLBURSTIF  :1; /*!< [22:22] 最后一次接收突发传输请求中断标志位 */
            __I uint32_t RXBURSTIF   :1; /*!< [23:23] 接收突发传输请求中断标志位 */
            __I uint32_t TXLSINGLEIF :1; /*!< [24:24] 最后一次发送单词传输请求中断标志位 */
            __I uint32_t TXSINGLEIF  :1; /*!< [25:25] 发送单次传输请求中断标志位 */
            __I uint32_t TXLBURSTIF  :1; /*!< [26:26] 最后一次发送突发传输请求中断标志位 */
            __I uint32_t TXBURSTIF   :1; /*!< [27:27] 发送突发传输请求中断标志位 */
            __I uint32_t PECIF       :1; /*!< [28:28] PEC错误中断标志位使能位 */
            __I uint32_t SMBTOIF     :1; /*!< [29:29] 超时中断标志位使能位 */
            __I uint32_t RESERVED0   :2; /*!< [31:30] 预留读为0  */
        } bits;
        __I uint32_t reg;
    } IF;
    /* offset: 0x0068 */
    union
    {
        struct
        {
            __IO uint32_t ADRMIE      :1; /*!< [0:0] 地址匹配中断使能位  */
            __IO uint32_t GCIE        :1; /*!< [1:1] 广播呼叫中断使能位  */
            __IO uint32_t MCIE        :1; /*!< [2:2] 主机码(高速模式)中断使能位  */
            __IO uint32_t ALERRIE     :1; /*!< [3:3] 仲裁失败中断使能位  */
            __IO uint32_t NACKIE      :1; /*!< [4:4] 接收到未应答信号中断使能位  */
            __IO uint32_t TXENDIE     :1; /*!< [5:5] 传输结束中断使能位  */
            __IO uint32_t RXIE        :1; /*!< [6:6] 接收模式中断使能位  */
            __IO uint32_t STARTIE     :1; /*!< [7:7] 起始位中断使能位  */
            __IO uint32_t STOPIE      :1; /*!< [8:8] 停止位中断使能位  */
            __IO uint32_t BYTEIE      :1; /*!< [9:9] 字节传输中断使能位  */
            __IO uint32_t SMBAIE      :1; /*!< [10:10] SMBus模式的提醒中断使能位  */
            __IO uint32_t SMBHIE      :1; /*!< [11:11] SMBus模式的主机头地址中断使能位  */
            __IO uint32_t SMBDIE      :1; /*!< [12:12] SMBus模式的设备默认地址中断使能位  */
            __IO uint32_t ACKTOIE     :1; /*!< [13:13] ACK超时标志使能位  */
            __IO uint32_t HSACKTOIE   :1; /*!< [14:14] 切换到高速模式时超时标志使能位  */
            __IO uint32_t RSTOIE      :1; /*!< [15:15] 重启后超时标志使能位  */
            __IO uint32_t RXUDFIE     :1; /*!< [16:16] RXFIEO下溢中断使能位  */
            __IO uint32_t RXOVFIE     :1; /*!< [17:17] RXFIEO上溢中断使能位  */
            __IO uint32_t TXUDFIE     :1; /*!< [18:18] TXFIEO下溢中断使能位  */
            __IO uint32_t TXOVFIE     :1; /*!< [19:19] TXFIEO上溢中断使能位  */
            __IO uint32_t RXLSINGLEIE :1; /*!< [20:20] 最后一次单次接收传输请求中断标志位使能位 */
            __IO uint32_t RXSINGLEIE  :1; /*!< [21:21] 单次接收传输请求中断标志位使能位 */
            __IO uint32_t RXLBURSTIE  :1; /*!< [22:22] 最后一次接收突发传输请求中断标志使能位 */
            __IO uint32_t RXBURSTIE   :1; /*!< [23:23] 接收突发传输请求中断标志位使能位 */
            __IO uint32_t TXLSINGLEIE :1; /*!< [24:24] 最后一次发送单词传输请求中断标志位使能位 */
            __IO uint32_t TXSINGLEIE  :1; /*!< [25:25] 发送单次传输请求中断标志位使能位 */
            __IO uint32_t TXLBURSTIE  :1; /*!< [26:26] 最后一次发送突发传输请求中断标志位使能位 */
            __IO uint32_t TXBURSTIE   :1; /*!< [27:27] 发送突发传输请求中断标志位使能位 */
            __IO uint32_t PECIE       :1; /*!< [28:28] PEC错误中断标志位使能位 */
            __IO uint32_t SMBTOIE     :1; /*!< [29:29] 超时中断标志位使能位 */
            __I uint32_t  RESERVED0   :2; /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } IE;
    /* offset: 0x006C */
    union
    {
        struct
        {
            __O uint32_t ADRMIC      :1; /*!< [0:0] 地址匹配中断标志清除位  */
            __O uint32_t GCIC        :1; /*!< [1:1] 广播呼叫中断标志清除位  */
            __O uint32_t MCIC        :1; /*!< [2:2] 主机码(高速模式)中断标志清除位  */
            __O uint32_t ALERRIC     :1; /*!< [3:3] 仲裁失败中断标志清除位  */
            __O uint32_t NACKIC      :1; /*!< [4:4] 接收到未应答信号中断标志清除位  */
            __O uint32_t TXENDIC     :1; /*!< [5:5] 传输结束中断标志清除位  */
            __O uint32_t RXIC        :1; /*!< [6:6] 接收模式中断标志清除位  */
            __O uint32_t STARTIC     :1; /*!< [7:7] 起始位中断标志清除位  */
            __O uint32_t STOPIC      :1; /*!< [8:8] 停止位中断标志清除位  */
            __O uint32_t BYTEIC      :1; /*!< [9:9] 字节传输中断标志清除位  */
            __O uint32_t SMBAIC      :1; /*!< [10:10] SMBus模式的提醒中断标志清除位  */
            __O uint32_t SMBHIC      :1; /*!< [11:11] SMBus模式的主机头地址中断标志清除位  */
            __O uint32_t SMBDIC      :1; /*!< [12:12] SMBus模式的设备默认地址中断标志清除位  */
            __O uint32_t ACKTOIC     :1; /*!< [13:13] ACK超时标志清除位  */
            __O uint32_t HSACKTOIC   :1; /*!< [14:14] 切换到高速模式时超时标志清除位  */
            __O uint32_t RSTOIC      :1; /*!< [15:15] 重启后超时标志清除位  */
            __O uint32_t RXUDFIC     :1; /*!< [16:16] RXFIFO下溢中断标志清除位  */
            __O uint32_t RXOVFIC     :1; /*!< [17:17] RXFIFO上溢中断标志清除位  */
            __O uint32_t TXUDFIC     :1; /*!< [18:18] TXFIFO下溢中断标志清除位  */
            __O uint32_t TXOVFIC     :1; /*!< [19:19] TXFIFO上溢中断标志清除位  */
            __O uint32_t RXLSINGLEIC :1; /*!< [20:20] 最后一次单次接收传输请求中断标志位清除位 */
            __O uint32_t RXSINGLEIC  :1; /*!< [21:21] 单次接收传输请求中断标志位清除位 */
            __O uint32_t RXLBURSTIC  :1; /*!< [22:22] 最后一次接收突发传输请求中断标志清除位 */
            __O uint32_t RXBURSTIC   :1; /*!< [23:23] 接收突发传输请求中断标志位清除位 */
            __O uint32_t TXLSINGLEIC :1; /*!< [24:24] 最后一次发送单词传输请求中断标志位清除位 */
            __O uint32_t TXSINGLEIC  :1; /*!< [25:25] 发送单次传输请求中断标志位清除位 */
            __O uint32_t TXLBURSTIC  :1; /*!< [26:26] 最后一次发送突发传输请求中断标志位清除位 */
            __O uint32_t TXBURSTIC   :1; /*!< [27:27] 发送突发传输请求中断标志位清除位 */
            __O uint32_t PECIC       :1; /*!< [28:28] PEC错误中断标志位清除位 */
            __O uint32_t SMBTOIC     :1; /*!< [29:29] 超时中断标志位清除位 */
            __I uint32_t RESERVED0   :2; /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } IC;
    /* offset: 0x0070 */
    union
    {
        struct
        {
            __O uint32_t ADRMIS      :1; /*!< [0:0] 地址匹配中断标志设置位  */
            __O uint32_t GCIS        :1; /*!< [1:1] 广播呼叫中断标志设置位  */
            __O uint32_t MCIS        :1; /*!< [2:2] 主机码(高速模式)中断标志设置位  */
            __O uint32_t ALERRIS     :1; /*!< [3:3] 仲裁失败中断标志设置位  */
            __O uint32_t NACKIS      :1; /*!< [4:4] 接收到未应答信号中断标志设置位  */
            __O uint32_t TXENDIS     :1; /*!< [5:5] 传输结束中断标志设置位  */
            __O uint32_t RXIS        :1; /*!< [6:6] 接收模式中断标志设置位  */
            __O uint32_t STARTIS     :1; /*!< [7:7] 起始位中断标志设置位  */
            __O uint32_t STOPIS      :1; /*!< [8:8] 停止位中断标志设置位  */
            __O uint32_t BYTEIS      :1; /*!< [9:9] 字节传输中断标志设置位  */
            __O uint32_t SMBAIS      :1; /*!< [10:10] SMBus模式的提醒中断标志设置位  */
            __O uint32_t SMBHIS      :1; /*!< [11:11] SMBus模式的主机头地址中断标志设置位  */
            __O uint32_t SMBDIS      :1; /*!< [12:12] SMBus模式的设备默认地址中断标志设置位  */
            __O uint32_t ACKTOIS     :1; /*!< [13:13] ACK超时标志设置位  */
            __O uint32_t HSACKTOIS   :1; /*!< [14:14] 切换到高速模式时超时标志设置位  */
            __O uint32_t RSTOIS      :1; /*!< [15:15] 重启后超时标志设置位  */
            __O uint32_t RXUDFIS     :1; /*!< [16:16] RXFIFO下溢中断标志设置位  */
            __O uint32_t RXOVFIS     :1; /*!< [17:17] RXFIFO上溢中断标志设置位  */
            __O uint32_t TXUDFIS     :1; /*!< [18:18] TXFIFO下溢中断标志设置位  */
            __O uint32_t TXOVFIS     :1; /*!< [19:19] TXFIFO上溢中断标志设置位  */
            __O uint32_t RXLSINGLEIS :1; /*!< [20:20] 最后一次单次接收传输请求中断标志位设置位 */
            __O uint32_t RXSINGLEIS  :1; /*!< [21:21] 单次接收传输请求中断标志位设置位 */
            __O uint32_t RXLBURSTIS  :1; /*!< [22:22] 最后一次接收突发传输请求中断标志设置位 */
            __O uint32_t RXBURSTIS   :1; /*!< [23:23] 接收突发传输请求中断标志位设置位 */
            __O uint32_t TXLSINGLEIS :1; /*!< [24:24] 最后一次发送单词传输请求中断标志位设置位 */
            __O uint32_t TXSINGLEIS  :1; /*!< [25:25] 发送单次传输请求中断标志位设置位 */
            __O uint32_t TXLBURSTIS  :1; /*!< [26:26] 最后一次发送突发传输请求中断标志位设置位 */
            __O uint32_t TXBURSTIS   :1; /*!< [27:27] 发送突发传输请求中断标志位设置位 */
            __O uint32_t PECIS       :1; /*!< [28:28] PEC错误中断标志位设置位 */
            __O uint32_t SMBTOIS     :1; /*!< [29:29] 超时中断标志位设置位 */
            __I uint32_t RESERVED0   :2; /*!< [31:30] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } IS;
    /* offset: 0x0074 */
    union
    {
        struct
        {
            __O uint32_t
              TXD :32; /*!< [31:0]
                          发送数据寄存器软件应将需要发送数据包的每一个数据按照相应数据对齐方式依次写入此寄存器，即视为将数据写入TXFIFO；偏移地址范围:8000至BFFC均作为TXD地址，为TXFIFO保留，访问该范围内任一地址将产生和第一个地址相同的效果，都能将数据写入TXFIFO；每次写入都会将该寄存器上的32位值全部同时写入TXFIFO，软件务必按照数据对齐方式写入。最终FIFO和I2C内核只会根据设置的发送数据包大小和数据对齐方式将有效字节数据发送至I2C总线上；
                        */
        } bits;
        __IO uint32_t reg;
    } TXD;
    /* offset: 0x0078 */
    union
    {
        struct
        {
            __I uint32_t
              RXD :32; /*!< [31:0]
                         接收数据寄存器软件可从此寄存器读出I2C模块从I2C总线上接收到的数据，即从RXFIFO读出数据；偏移地址范围:C000至FFFC均作为RXD地址，为RXFIFO保留，访问该范围内任一地址将产生和第一个地址相同的效果，都能从RXFIFO读出数据；每次读出都会将该寄存器上的32位值全部读出，遵循I2C模块接收到的字节数据按照配置的数据对齐方式排列而成的形式。
                       */
        } bits;
        __IO uint32_t reg;
    } RXD;
    /* offset: 0x007C */
    union
    {
        struct
        {
            __IO uint32_t PEC       :8;  /*!< [7:0] 软件写入PEC值 */
            __I uint32_t  RESERVED0 :24; /*!< [31:8] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } PECR;
    /* offset: 0x0080 */
    union
    {
        struct
        {
            __I uint32_t TOUT      :16; /*!< [15:0] 软件写入超时阶段数 */
            __I uint32_t RESERVED0 :16; /*!< [31:16] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } TOUT;
    /* offset: 0x0084 */
    union
    {
        struct
        {
            __IO uint32_t TMEN      :1;  /*!< [0:0] 测试模式使能 */
            __IO uint32_t TMSEL     :2;  /*!< [2:1] 测试引脚功能位 */
            __I uint32_t  RESERVED0 :29; /*!< [31:3] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    } TM;
} I2c_RegisterMap_t;

#define I2C0_ADDR ((uint32_t)0xF4010000)
#define I2C0_PTR  ((I2c_RegisterMap_t *)I2C0_ADDR)
#define I2C0_RM   (*(I2c_RegisterMap_t *)I2C0_ADDR)

#define I2C1_ADDR ((uint32_t)0xF4040000)
#define I2C1_PTR  ((I2c_RegisterMap_t *)I2C1_ADDR)
#define I2C1_RM   (*(I2c_RegisterMap_t *)I2C1_ADDR)

#define I2C2_ADDR ((uint32_t)0xF4060000)
#define I2C2_PTR  ((I2c_RegisterMap_t *)I2C2_ADDR)
#define I2C2_RM   (*(I2c_RegisterMap_t *)I2C2_ADDR)

#define I2C3_ADDR ((uint32_t)0xF4080000)
#define I2C3_PTR  ((I2c_RegisterMap_t *)I2C3_ADDR)
#define I2C3_RM   (*(I2c_RegisterMap_t *)I2C3_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
