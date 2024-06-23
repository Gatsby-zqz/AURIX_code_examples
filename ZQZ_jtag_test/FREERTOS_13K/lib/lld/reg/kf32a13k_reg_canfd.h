/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_canfd.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyrght protected and proprietary to
 * Shanghai ChipON Micro-Electronic Co.,Ltd
 **************************************************************************/

#ifndef _KF32DA13K_REG_CANFD_H_
#define _KF32DA13K_REG_CANFD_H_

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
#define FEATURE_CAN_HAS_DMA_ENABLE         (0U)
#define FEATURE_CAN_HAS_SELF_WAKE_UP       (0U)
#define FEATURE_CAN_HAS_PE_CLKSRC_SELECT   (1U)
#define FEATURE_CAN_HAS_MEM_ERR_DET        (1U)
#define FEATURE_CAN_HAS_MBDSR1             (1U)
#define FEATURE_CAN_HAS_MBDSR2             (1U)
#define FEATURE_CAN_HAS_MBDSR3             (1U)
#define FEATURE_CAN_RXFIFO_FRAME_AVAILABLE (5U)
#define FEATURE_CAN_RXFIFO_WARNING         (6U)
#define FEATURE_CAN_RXFIFO_OVERFLOW        (7U)
#define CANFD_MAX_MBNUM                    (128U)
#define CANFD_MAX_RAMSIZE                  (2048U)
#define CANFD_MAX_RAMBLOCK                 (512U)
#define CANFD_ARBITRATION_RAMSIZE          (8U)

/**
 * @brief          CANFD_MASK_T
 * @details        Union to store controller mailbox Mask information
 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :18;
            __IO uint32_t MASK      :11;
            __I uint32_t  RESERVED1 :3;
        } SFF;
        struct
        {
            __IO uint32_t MASK      :29;
            __I uint32_t  RESERVED0 :3;
        } EFF;
        __IO uint32_t reg;
    };
} CANFD_MASK_T;

/**
 * @brief          CANFD_MASK_T
 * @details        Union to store controller mailbox Mask information
 */
typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :18;
            __IO uint32_t ID        :11;
            __IO uint32_t PRIO      :3;
        } SFF;
        struct
        {
            __IO uint32_t ID :29;
            __IO uint32_t PRIO :3;
        } EFF;
        __IO uint32_t reg;
    };
} CANFD_ID_T;

/**
 * @brief          CANFD_CS_T
 * @details        Union to store controller mailbox information
 */
typedef union
{
    __IO uint32_t CS_CODE;
    struct
    {
        __IO uint32_t TIMESTAMP :16;
        __IO uint32_t DLC       :4;
        __IO uint32_t RTR       :1;
        __IO uint32_t IDE       :1;
        __IO uint32_t SRR       :1;
        __I uint32_t  RESERVED0 :1;
        __IO uint32_t CODE      :4;
        __I uint32_t  RESERVED1 :1;
        __IO uint32_t ESI       :1;
        __IO uint32_t BRS       :1;
        __IO uint32_t EDL       :1;
    };
} CANFD_CS_T;

typedef struct
{
    CANFD_CS_T    CS;
    CANFD_ID_T    ID;
    __IO uint32_t DATA3210[2];
} CANFD_BUFFER8_T;

typedef struct
{
    CANFD_CS_T    CS;
    CANFD_ID_T    ID;
    __IO uint32_t DATA3210[4];
} CANFD_BUFFER16_T;

typedef struct
{
    CANFD_CS_T    CS;
    CANFD_ID_T    ID;
    __IO uint32_t DATA3210[8];
} CANFD_BUFFER32_T;

typedef struct
{
    CANFD_CS_T    CS;
    CANFD_ID_T    ID;
    __IO uint32_t DATA3210[16];
} CANFD_BUFFER64_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t MAXMB     :7; /*!< [6:0] 最后一个mb的序号  */
            __I uint32_t  RESERVED0 :1; /*!< [7:7]   */
            __IO uint32_t IDAM      :2; /*!< [9:8] id接收模式  */
            __I uint32_t  RESERVED1 :1; /*!< [10:10]   */
            __IO uint32_t FDEN      :1; /*!< [11:11] canfd使能  */
            __IO uint32_t AEN       :1; /*!< [12:12] 启用tx中止机制  */
            __IO uint32_t LPRIOEN   :1; /*!< [13:13] 本地优先级使能  */
            __IO uint32_t PNET_EN   :1; /*!< [14:14] 虚假网络使能  */
            __IO uint32_t DMA       :1; /*!< [15:15] dma使能  */
            __IO uint32_t IRQM      :1; /*!< [16:16] 启用单独的rx掩膜和队列  */
            __IO uint32_t SRXDIS    :1; /*!< [17:17] 自接收禁用  */
            __IO uint32_t DOZE      :1; /*!< [18:18] 睡眠模式使能  */
            __IO uint32_t WAKSRC    :1; /*!< [19:19] 唤醒源  */
            __I uint32_t  LPMACK    :1; /*!< [20:20] 低电压模式相应  */
            __IO uint32_t WRNEN     :1; /*!< [21:21] 警告中断  */
            __IO uint32_t SLFWAK    :1; /*!< [22:22] 自唤醒  */
            __IO uint32_t SUPV      :1; /*!< [23:23] sv模式  */
            __I uint32_t  FRZACK    :1; /*!< [24:24] 冻结模式响应，该位不会被软件复位  */
            __IO uint32_t SOFTRST   :1; /*!< [25:25] 软件复位，该位不会被软件复位  */
            __IO uint32_t WAKMSK    :1; /*!< [26:26] 唤醒中断掩码  */
            __I uint32_t  NOTRDT    :1; /*!< [27:27] canfd没有准备好，该位不会被软件复位  */
            __IO uint32_t HALT      :1; /*!< [28:28] 停止canfd  */
            __IO uint32_t RFEN      :1; /*!< [29:29] 传统rxfifo使能  */
            __IO uint32_t FRZ       :1; /*!< [30:30] 冻结使能  */
            __IO uint32_t MDIS      :1; /*!< [31:31] 禁用或使能canfd模块，该位不会被软件复位  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_MCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PROPSEG   :3; /*!< [2:0] 传播段  */
            __IO uint32_t LOM       :1; /*!< [3:3] 只接收模式  */
            __IO uint32_t LBUF      :1; /*!< [4:4] 最低缓冲区优先  */
            __IO uint32_t TSYN      :1; /*!< [5:5] 定时器同步  */
            __IO uint32_t BOFFREC   :1; /*!< [6:6] 总线唤醒  */
            __IO uint32_t SMP       :1; /*!< [7:7] can位抽样  */
            __I uint32_t  RESERVED0 :2; /*!< [9:8]   */
            __IO uint32_t RWRNMSK   :1; /*!< [10:10] rx警报中断掩码  */
            __IO uint32_t TWRNMSK   :1; /*!< [11:11] tx警报中断掩码  */
            __IO uint32_t LPB       :1; /*!< [12:12] 还回模式  */
            __IO uint32_t CLKSRC    :1; /*!< [13:13] can引擎时钟源  */
            __IO uint32_t ERRMSK    :1; /*!< [14:14] 错误中断掩码  */
            __IO uint32_t BOFFMSK   :1; /*!< [15:15] 总线中断掩码  */
            __IO uint32_t PSEG2     :3; /*!< [18:16] 相位段2  */
            __IO uint32_t PSEG1     :3; /*!< [21:19] 相位段1  */
            __IO uint32_t RJW       :2; /*!< [23:22] 同步跳宽  */
            __IO uint32_t PRESDIV   :8; /*!< [31:24] 比较器除法因子  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_CTRL1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TIMER     :16; /*!< [15:0] 时间值  */
            __I uint32_t  RESERVED0 :16; /*!< [31:16]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_TIMER_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TXERRCNT      :8; /*!< [7:0] bit发送错误计数器  */
            __IO uint32_t RXERRCNT      :8; /*!< [15:8] bit接收错误计数器  */
            __IO uint32_t TXERRCNT_FAST :8; /*!< [23:16] 快速bit发送错误计数器  */
            __IO uint32_t RXERRCNT_FAST :8; /*!< [31:24] 快速bit接收错误计数器  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ECR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t WAKINT  :1; /*!< [0:0] 唤醒中断  */
            __IO uint32_t ERRINT  :1; /*!< [1:1] 错误中断  */
            __IO uint32_t BOFFINT :1; /*!< [2:2] 总线关闭中断  */
            __I uint32_t  RX      :1; /*!< [3:3] canfd正在接收  */
            __I uint32_t  FLTCONF :2; /*!< [5:4] 故障约束状态  */
            __I uint32_t  TX      :1; /*!< [6:6] canfd正在传输  */
            __I uint32_t  IDLE    :1; /*!< [7:7] can总线处于idle状态  */
            __I uint32_t  RXWRN   :1; /*!< [8:8] rx错误警报  */
            __I uint32_t  TXWRN   :1; /*!< [9:9] tx错误警报  */
            __I uint32_t STFERR :1; /*!< [10:10] 在非canfd消息、canfd的仲裁或者数据阶段中检测到了填充错误  */
            __I uint32_t FRMERR :1; /*!< [11:11] 在非canfd消息、canfd的仲裁或者数据阶段中检测到了形式错误  */
            __I uint32_t CRCERR :1; /*!< [12:12] 在非canfd消息、canfd的仲裁或者数据阶段中检测到了crc错误  */
            __I uint32_t ACKERR :1; /*!< [13:13] 响应错误  */
            __I uint32_t BIT0ERR :1; /*!< [14:14] 在非canfd消息、canfd的仲裁或者数据阶段中检测到了错误  */
            __I uint32_t BIT1ERR :1; /*!< [15:15] 在非canfd消息、canfd的仲裁或者数据阶段中检测到了错误  */
            __IO uint32_t RWRNINT     :1; /*!< [16:16] rx警报中断信号  */
            __IO uint32_t TWRNINT     :1; /*!< [17:17] tx警报中断信号  */
            __I uint32_t  SYNCH       :1; /*!< [18:18] can同步状态  */
            __IO uint32_t BOFFDONEINT :1; /*!< [19:19] 总线关闭结束中断  */
            __IO uint32_t
              ERRINT_FAST :1;           /*!< [20:20]
                                           canfd帧brs置位检测到数据错误，即BIT1ERR_FAST,BIT0ERR_FAST,CRCERR_FAST,FRMERR_FAST,STFERR_FAST任一置位
                                         */
            __IO uint32_t ERROVR    :1; /*!< [21:21] 错误溢出，当已经存在错误标志时再次发生错误  */
            __I uint32_t  RESERVED0 :4; /*!< [25:22]   */
            __I uint32_t  STFERR_FAST  :1; /*!< [26:26] canfd帧brs置位检测到填充错误  */
            __I uint32_t  FRMERR_FAST  :1; /*!< [27:27] canfd帧brs置位检测到形式错误  */
            __I uint32_t  CRCERR_FAST  :1; /*!< [28:28] canfd帧brs置位检测到crc错误  */
            __I uint32_t  RESERVED1    :1; /*!< [29:29]   */
            __I uint32_t  BIT0ERR_FAST :1; /*!< [30:30] canfd帧brs置位情况下，检测到bit错误  */
            __I uint32_t  BIT1ERR_FAST :1; /*!< [31:31] canfd帧brs置位情况下，检测到bit错误  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ESR1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BUF63TO32M :32; /*!< [31:0] 第i个mb的掩码  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IMASK2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BUF31TO0M :32; /*!< [31:0] 第i个mb的掩码  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IMASK1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BUF63TO32I :32; /*!< [31:0] 第i个mb的中断  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IFLAG2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BUF0I     :1;  /*!< [0:0] 缓冲区mb0中断或者清除传统的rxfifo位  */
            __IO uint32_t BUF4ITO1I :4;  /*!< [4:1] 第i个mb的中断或者保留位  */
            __IO uint32_t BUF5I     :1;  /*!< [5:5] 缓冲区MB5中断或传统的RxFIFO中可用的帧  */
            __IO uint32_t BUF6I     :1;  /*!< [6:6] 缓冲区MB6中断或传统的RxFIFO警报  */
            __IO uint32_t BUF7I     :1;  /*!< [7:7] 缓冲区MB7中断或传统的RxFIFO溢出  */
            __IO uint32_t BUF31TO8I :24; /*!< [31:8] 第i个mb的中断  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IFLAG1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0   :6; /*!< [5:0]   */
            __IO uint32_t TSTAMPCAP   :2; /*!< [7:6] 时间戳捕获点  */
            __IO uint32_t MBTSBASE    :2; /*!< [9:8] MB时间戳基底  */
            __I uint32_t  RESERVED1   :1; /*!< [10:10]   */
            __IO uint32_t EDFLTDIS    :1; /*!< [11:11] 边缘过滤器禁用  */
            __IO uint32_t ISOCANFDEN  :1; /*!< [12:12] ISOCANFD启用  */
            __IO uint32_t BTE         :1; /*!< [13:13] 位定时扩展  */
            __IO uint32_t PREXCEN     :1; /*!< [14:14] 协议异常启用  */
            __IO uint32_t TIMER_SRC   :1; /*!< [15:15] 自由运行计数器时钟源  */
            __IO uint32_t EACEN       :1; /*!< [16:16] rx邮箱整个框架仲裁字段比较启用  */
            __IO uint32_t RRS         :1; /*!< [17:17] RemoteRequestStoring  */
            __IO uint32_t MRP         :1; /*!< [18:18] 邮箱接收优先级  */
            __IO uint32_t TASD        :5; /*!< [23:19] Tx仲裁开始延迟  */
            __IO uint32_t RFFN        :4; /*!< [27:24] RxFIFO滤波器数  */
            __IO uint32_t WRMFRZ      :1; /*!< [28:28] 冻结模式的内存访问  */
            __IO uint32_t ECRWRE      :1; /*!< [29:29] 错误矫正配置寄存器写入启用  */
            __IO uint32_t BOFFDONEMSK :1; /*!< [30:30] 总线关闭错误中断掩码  */
            __IO uint32_t ERRMSK_FAST :1; /*!< [31:31] 错误中断掩码  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_CTRL2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :13; /*!< [12:0]   */
            __I uint32_t  IMB       :1;  /*!< [13:13] 非活动邮箱  */
            __I uint32_t  VPS       :1;  /*!< [14:14] 有效优先地位  */
            __IO uint32_t TWAMSK    :1;  /*!< [15:15] 定时器回环中断掩码  */
            __I uint32_t  LPTM      :7;  /*!< [22:16] 最低优先级Tx邮箱  */
            __I uint32_t  RESERVED1 :8;  /*!< [30:23]   */
            __IO uint32_t TWAINT    :1;  /*!< [31:31] 定时器回环中断  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ESR2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t TXCRC     :15; /*!< [14:0] 传输CRC值  */
            __I uint32_t RESERVED0 :1;  /*!< [15:15]   */
            __I uint32_t MBCRC     :7;  /*!< [22:16] CRC邮箱  */
            __I uint32_t RESERVED1 :9;  /*!< [31:23]   */
        } bits;
        __I uint32_t reg;
    };
} CANFD_CRCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t IDHIT     :8;
            __I uint32_t RESERVED0 :24;
        } bits;
        __I uint32_t reg;
    };
} CANFD_RXFIR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t EPSEG2   :5;  /*!< [4:0] 扩展阶段2  */
            __IO uint32_t EPSEG1   :5;  /*!< [9:5] 扩展阶段1  */
            __IO uint32_t EPROPSEG :6;  /*!< [15:10] 扩展传播段  */
            __IO uint32_t ERJW     :5;  /*!< [20:16] 扩展同步跳宽  */
            __IO uint32_t EPRESDIV :10; /*!< [30:21] 扩展预列系数  */
            __IO uint32_t BTF      :1;  /*!< [31:31] 比特时序格式  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_CBT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BUF127TO96M :32; /*!< [31:0] MBi掩码  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IMASK4_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BUF95TO64M :32; /*!< [31:0] MBi掩码  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IMASK3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BUF127TO96 :32; /*!< [31:0] MBi中断  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IFLAG4_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t BUF95TO64 :32; /*!< [31:0] MBi中断  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IFLAG3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0  :7;  /*!< [6:0]   */
            __IO uint32_t NCEFAFRZ   :1;  /*!< [7:7] 在冻结模式下,Canfd接入安装设备的非可校正错误  */
            __IO uint32_t ECCDIS     :1;  /*!< [8:8] 错误校正无效  */
            __IO uint32_t RERRDIS    :1;  /*!< [9:9] 错误报告禁用  */
            __IO uint32_t RESERVED1  :3;  /*!< [12:10]   */
            __IO uint32_t EXTERRIE   :1;  /*!< [13:13] 扩展错误注入  */
            __IO uint32_t FAERRIE    :1;  /*!< [14:14] canfd访问错误注入  */
            __IO uint32_t HAERRIE    :1;  /*!< [15:15] 主机访问错误注入  */
            __IO uint32_t CEI_MSK    :1;  /*!< [16:16] 纠正错误中断掩码  */
            __I uint32_t  RESERVED2  :1;  /*!< [17:17]   */
            __IO uint32_t FANCEI_MSK :1;  /*!< [18:18] Canfd使用非校正的错误中断掩码访问  */
            __IO uint32_t HANCEI_MSK :1;  /*!< [19:19] 主机访问与非校正错误中断掩码  */
            __I uint32_t  RESERVED3  :11; /*!< [30:20]   */
            __IO uint32_t ECRWRDIS   :1;  /*!< [31:31] 错误配置寄存器写入禁用  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_MECR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  INJADDR_L :2;  /*!< [1:0] 错误注入低地址  */
            __IO uint32_t INJADDR_H :12; /*!< [13:2] 错误注入高地址  */
            __I uint32_t  RESERVED0 :18; /*!< [31:14]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ERRIAR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DFLIP :32; /*!< [31:0] 数据翻转模式  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ERRIDPR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t PFLIP0    :5; /*!< [4:0] 字节0(最不重要)的奇偶校验翻转模式  */
            __I uint32_t  RESERVED0 :3; /*!< [7:5]   */
            __IO uint32_t PFLIP1    :5; /*!< [12:8] 字节1的奇偶校验翻转模式  */
            __I uint32_t  RESERVED1 :3; /*!< [15:13]   */
            __IO uint32_t PFLIP2    :5; /*!< [20:16] 字节2的奇偶校验翻转模式  */
            __I uint32_t  RESERVED2 :3; /*!< [23:21]   */
            __IO uint32_t PFLIP3    :5; /*!< [28:24] 字节3的奇偶校验翻转模式(最重要的)  */
            __I uint32_t  RESERVED3 :3; /*!< [31:29]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ERRIPPR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ERRADDR   :14; /*!< [13:0] 检测错误的地址  */
            __I uint32_t RESERVED0 :2;  /*!< [15:14]   */
            __I uint32_t SAID      :3;  /*!< [18:16]   */
            __I uint32_t RESERVED1 :5;  /*!< [23:19]   */
            __I uint32_t NCE       :1;  /*!< [24:24] 不校正误差  */
            __I uint32_t RESERVED2 :7;  /*!< [31:25]   */
        } bits;
        __I uint32_t reg;
    };
} CANFD_RERRAR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RDATA :32; /*!< [31:0] 原始数据单词从内存中读取错误  */
        } bits;
        __I uint32_t reg;
    };
} CANFD_RERRDR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t SYND0     :5; /*!< [4:0] 字节0的错误综合症  */
            __I uint32_t RESERVED0 :2; /*!< [6:5]   */
            __I uint32_t BE0       :1; /*!< [7:7] 启用字节0的字节  */
            __I uint32_t SYND1     :5; /*!< [12:8] 字节1的错误综合症  */
            __I uint32_t RESERVED1 :2; /*!< [14:13]   */
            __I uint32_t BE1       :1; /*!< [15:15] 启用字节1的字节  */
            __I uint32_t SYND2     :5; /*!< [20:16] 字节2的错误综合症  */
            __I uint32_t RESERVED2 :2; /*!< [22:21]   */
            __I uint32_t BE2       :1; /*!< [23:23] 启用字节2的字节  */
            __I uint32_t SYND3     :5; /*!< [28:24] 字节3的错误综合症  */
            __I uint32_t RESERVED3 :2; /*!< [30:29]   */
            __I uint32_t BE3       :1; /*!< [31:31] 启用字节3的字节  */
        } bits;
        __I uint32_t reg;
    };
} CANFD_RERRSYNR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CEIOF     :1;  /*!< [0:0] 纠正错误中断溢出标志  */
            __I uint32_t  RESERVED0 :1;  /*!< [1:1]   */
            __IO uint32_t FANCEIOF  :1;  /*!< [2:2] Canfd访问不正确的错误中断溢出标志  */
            __IO uint32_t HANCEIOF  :1;  /*!< [3:3] 主机访问不正确的错误中断溢出的标志  */
            __I uint32_t  RESERVED1 :12; /*!< [15:4]   */
            __IO uint32_t CEIF      :1;  /*!< [16:16] 纠正错误中断标志  */
            __I uint32_t  RESERVED2 :1;  /*!< [17:17]   */
            __IO uint32_t FANCEIF   :1;  /*!< [18:18] Canfd访问不正确的错误中断标志  */
            __IO uint32_t HANCEIF   :1;  /*!< [19:19] 主机访问不正确的错误中断标志  */
            __I uint32_t  RESERVED3 :12; /*!< [31:20]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ERRSR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FCS  :2; /*!< [1:0] 滤波组合选择  */
            __IO uint32_t IDFS :2; /*!< [3:2] 选择在虚假网络模式下应用的ID筛选水平  */
            __IO uint32_t PLFS :2; /*!< [5:4] 当Canfd正处于伪装的网络模式下,选择使用有效负载筛选的级别  */
            __I uint32_t  RESERVED0 :2;  /*!< [7:6]   */
            __IO uint32_t NMATCH    :8;  /*!< [15:8] 匹配相同过滤标准的消息数量  */
            __IO uint32_t WUMF_MSK  :1;  /*!< [16:16] 通过匹配标记掩码位来唤醒  */
            __IO uint32_t WTOF_MSK  :1;  /*!< [17:17] 在过时的标志掩模位唤醒  */
            __I uint32_t  RESERVED1 :14; /*!< [31:18]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_CTRL1_PN_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t MATCHTO   :16; /*!< [15:0] 没有信息匹配过滤标准的超时  */
            __I uint32_t  RESERVED0 :16; /*!< [31:16]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_CTRL2_PN_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :8;  /*!< [7:0]   */
            __I uint32_t  MCOUNTER  :8;  /*!< [15:8] 在假装网络的时候有数量的比赛  */
            __IO uint32_t WUMF      :1;  /*!< [16:16] 在匹配的事件中醒来  */
            __IO uint32_t WTOF      :1;  /*!< [17:17] 在超时的标志端唤醒  */
            __I uint32_t  RESERVED1 :14; /*!< [31:18]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_WU_MTC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FLT_ID1   :29; /*!< [28:0] ID滤波器1用于假网络过滤  */
            __IO uint32_t FLT_RTR   :1;  /*!< [29:29] 远程传输请求过滤器  */
            __IO uint32_t FLT_IDE   :1;  /*!< [30:30] ID扩展滤波器  */
            __I uint32_t  RESERVED0 :1;  /*!< [31:31]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_FLT_ID1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FLT_DLC_HI :4;  /*!< [3:0] 数据字节滤波器长度的上限  */
            __I uint32_t  RESERVED0  :12; /*!< [15:4]   */
            __IO uint32_t FLT_DLC_LO :4;  /*!< [19:16] 数据字节滤波器长度的下限  */
            __I uint32_t  RESERVED1  :12; /*!< [31:20]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_FLT_DLC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DATA_BYTE_3 :8; /*!< [7:0] 有效负载过滤器1低订单位,用于假网络负载过滤与数据字节3对应  */
            __IO uint32_t DATA_BYTE_2 :8; /*!< [15:8] 有效负载过滤器1低订单位,用于假网络负载过滤与数据字节2对应  */
            __IO uint32_t DATA_BYTE_1 :8; /*!< [23:16] 有效负载过滤器1低订单位,用于假网络负载过滤与数据字节1对应  */
            __IO uint32_t DATA_BYTE_0 :8; /*!< [31:24] 有效负载过滤器1低订单位,用于假网络负载过滤与数据字节0对应  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_PL1_LO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DATA_BYTE_7 :8; /*!< [7:0] 有效负载过滤器1低订单位,用于假网络负载过滤与数据字节7对应  */
            __IO uint32_t DATA_BYTE_6 :8; /*!< [15:8] 有效负载过滤器1低订单位,用于假网络负载过滤与数据字节6对应  */
            __IO uint32_t DATA_BYTE_5 :8; /*!< [23:16] 有效负载过滤器1低订单位,用于假网络负载过滤与数据字节5对应  */
            __IO uint32_t DATA_BYTE_4 :8; /*!< [31:24] 有效负载过滤器1低订单位,用于假网络负载过滤与数据字节4对应  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_PL1_HI_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FLT_ID2_IDMASK :29; /*!< [28:0] IDFilter2用于假装网络过滤/ID掩码位用于假装网络ID筛选  */
            __IO uint32_t RTR_MSK   :1; /*!< [29:29] 远程传输请求掩模位  */
            __IO uint32_t IDE_MSK   :1; /*!< [30:30] ID扩展掩模位  */
            __I uint32_t  RESERVED0 :1; /*!< [31:31]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_FLT_ID2_IDMASK_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              DATA_BYTE_3 :8; /*!< [7:0] 有效负载过滤器2低阶位/有效负载屏蔽低阶位用于假网络负载滤波与数据字节3对应  */
            __IO uint32_t
              DATA_BYTE_2 :8; /*!< [15:8] 有效负载过滤器2低阶位/有效负载屏蔽低阶位用于假网络负载滤波与数据字节2对应  */
            __IO uint32_t
              DATA_BYTE_1 :8; /*!< [23:16] 有效负载过滤器2低阶位/有效负载屏蔽低阶位用于假网络负载滤波与数据字节1对应  */
            __IO uint32_t
              DATA_BYTE_0 :8; /*!< [31:24] 有效负载过滤器2低阶位/有效负载屏蔽低阶位用于假网络负载滤波与数据字节0对应  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_PL2_PLMASK_LO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t
              DATA_BYTE_7 :8; /*!< [7:0] 有效负载过滤器2低阶位/有效负载屏蔽低阶位用于假网络负载滤波与数据字节7对应  */
            __IO uint32_t
              DATA_BYTE_6 :8; /*!< [15:8] 有效负载过滤器2低阶位/有效负载屏蔽低阶位用于假网络负载滤波与数据字节6对应  */
            __IO uint32_t
              DATA_BYTE_5 :8; /*!< [23:16] 有效负载过滤器2低阶位/有效负载屏蔽低阶位用于假网络负载滤波与数据字节5对应  */
            __IO uint32_t
              DATA_BYTE_4 :8; /*!< [31:24] 有效负载过滤器2低阶位/有效负载屏蔽低阶位用于假网络负载滤波与数据字节4对应  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_PL2_PLMASK_HI_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t RESERVED0 :16; /*!< [15:0] Reserve  */
            __I uint32_t DLC       :4;  /*!< [19:16] 字节的数据长度  */
            __I uint32_t RTR       :1;  /*!< [20:20] 远程传输请求位  */
            __I uint32_t IDE       :1;  /*!< [21:21] ID扩展位  */
            __I uint32_t SRR       :1;  /*!< [22:22] 替代远程请求  */
            __I uint32_t RESERVED1 :9;  /*!< [31:23]   */
        } bits;
        __I uint32_t reg;
    };
} CANFD_WMB_CS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t ID        :29; /*!< [28:0] 在假装的网络模式下接收到ID  */
            __I uint32_t RESERVED0 :3;  /*!< [31:29]   */
        } bits;
        __I uint32_t reg;
    };
} CANFD_WMB_ID_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t DATA_BYTE_3 :8; /*!< [7:0] 在装假网络模式下,接收到对应于数据字节3的有效负载  */
            __I uint32_t DATA_BYTE_2 :8; /*!< [15:8] 在装假网络模式下,接收到对应于数据字节2的有效负载  */
            __I uint32_t DATA_BYTE_1 :8; /*!< [23:16] 在装假网络模式下,接收到对应于数据字节1的有效负载  */
            __I uint32_t DATA_BYTE_0 :8; /*!< [31:24] 在装假网络模式下,接收到对应于数据字节0的有效负载  */
        } bits;
        __I uint32_t reg;
    };
} CANFD_WMB_D03_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t DATA_BYTE_7 :8; /*!< [7:0] 在装假网络模式下,接收到对应于数据字节7的有效负载  */
            __I uint32_t DATA_BYTE_6 :8; /*!< [15:8] 在装假网络模式下,接收到对应于数据字节6的有效负载  */
            __I uint32_t DATA_BYTE_5 :8; /*!< [23:16] 在装假网络模式下,接收到对应于数据字节5的有效负载  */
            __I uint32_t DATA_BYTE_4 :8; /*!< [31:24] 在装假网络模式下,接收到对应于数据字节4的有效负载  */
        } bits;
        __I uint32_t reg;
    };
} CANFD_WMB_D47_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ENPRESDIV :10; /*!< [9:0] 扩展的名义相位比较器系数  */
            __I uint32_t  RESERVED0 :6;  /*!< [15:10]   */
            __IO uint32_t EDPRESDIV :10; /*!< [25:16] 扩展数据相位比较器  */
            __I uint32_t  RESERVED1 :6;  /*!< [31:26]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_EPRS_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t NTSEG1    :8; /*!< [7:0] 额定时间段1  */
            __I uint32_t  RESERVED0 :4; /*!< [11:8]   */
            __IO uint32_t NTSEG2    :7; /*!< [18:12] 额定时间段2  */
            __I uint32_t  RESERVED1 :3; /*!< [21:19]   */
            __IO uint32_t NRJW      :7; /*!< [28:22] 名义重同步跳宽  */
            __I uint32_t  RESERVED2 :3; /*!< [31:29]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ENCBT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DTSEG1    :8; /*!< [7:0] 数据相时段1  */
            __I uint32_t  RESERVED0 :4; /*!< [11:8]   */
            __IO uint32_t DTSEG2    :7; /*!< [18:12] 数据相时段2  */
            __I uint32_t  RESERVED1 :3; /*!< [21:19]   */
            __IO uint32_t DRJW      :4; /*!< [25:22] 数据相同步跳跃宽度  */
            __I uint32_t  RESERVED2 :6; /*!< [31:26]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_EDCBT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  ETDCVAL   :8; /*!< [7:0] 增强收发延迟补偿值  */
            __I uint32_t  RESERVED0 :7; /*!< [14:8]   */
            __IO uint32_t ETDCFAIL  :1; /*!< [15:15] 收发延迟补偿失效  */
            __IO uint32_t ETDCOFF   :7; /*!< [22:16] 增强收发延迟补偿偏移  */
            __I uint32_t  RESERVED1 :7; /*!< [29:23]   */
            __IO uint32_t TDMDIS    :1; /*!< [30:30] 收发延迟测量无效  */
            __IO uint32_t ETDCEN    :1; /*!< [31:31] 收发延迟补偿  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ETDC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  TDCVAL    :6; /*!< [5:0] 收发延迟补偿值  */
            __I uint32_t  RESERVED0 :2; /*!< [7:6]   */
            __IO uint32_t TDCOFF    :5; /*!< [12:8] 收发延迟补偿偏移  */
            __I uint32_t  RESERVED1 :1; /*!< [13:13]   */
            __IO uint32_t TDCFAIL   :1; /*!< [14:14] 收发延迟补偿失效  */
            __IO uint32_t TDCEN     :1; /*!< [15:15] 收发延迟补偿  */
            __IO uint32_t MBDSR0    :2; /*!< [17:16] 区域0的消息缓冲数据大小  */
            __I uint32_t  RESERVED2 :1; /*!< [18:18]   */
            __IO uint32_t MBDSR1    :2; /*!< [20:19] 区域1的消息缓冲数据大小  */
            __I uint32_t  RESERVED3 :1; /*!< [21:21]   */
            __IO uint32_t MBDSR2    :2; /*!< [23:22] 区域2的消息缓冲数据大小  */
            __I uint32_t  RESERVED4 :1; /*!< [24:24]   */
            __IO uint32_t MBDSR3    :2; /*!< [26:25] 区域3的消息缓冲数据大小  */
            __I uint32_t  RESERVED5 :4; /*!< [30:27]   */
            __IO uint32_t FDRATE    :1; /*!< [31:31] 位率开关  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_FDCTRL_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FPSEG2    :3;  /*!< [2:0] 快相段2  */
            __I uint32_t  RESERVED0 :2;  /*!< [4:3]   */
            __IO uint32_t FPSEG1    :3;  /*!< [7:5] 快相段1  */
            __I uint32_t  RESERVED1 :2;  /*!< [9:8]   */
            __IO uint32_t FPROPSEG  :5;  /*!< [14:10] 快速传播段  */
            __I uint32_t  RESERVED2 :1;  /*!< [15:15]   */
            __IO uint32_t FRJW      :3;  /*!< [18:16] 快速同步跳宽  */
            __I uint32_t  RESERVED3 :1;  /*!< [19:19]   */
            __IO uint32_t FPRESDIV  :10; /*!< [29:20] 快速预推系数  */
            __I uint32_t  RESERVED4 :2;  /*!< [31:30]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_FDCBT_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t FD_TXCRC  :21; /*!< [20:0] 扩展传输CRC值  */
            __I uint32_t RESERVED0 :3;  /*!< [23:21]   */
            __I uint32_t FD_MBCRC  :7;  /*!< [30:24] FD_TXCRC的CRC邮箱号码  */
            __I uint32_t RESERVED1 :1;  /*!< [31:31]   */
        } bits;
        __I uint32_t reg;
    };
} CANFD_FDCRC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ERFWM     :5; /*!< [4:0] 增强的RxFIFO水印  */
            __I uint32_t  RESERVED0 :3; /*!< [7:5]   */
            __IO uint32_t NFE       :6; /*!< [13:8] 增强RxFIFO滤波器元件的数量  */
            __I uint32_t  RESERVED1 :2; /*!< [15:14]   */
            __IO uint32_t NEXIF     :7; /*!< [22:16] 扩展ID筛选元素的数量  */
            __I uint32_t  RESERVED2 :3; /*!< [25:23]   */
            __IO uint32_t DMALW     :5; /*!< [30:26] DMA最后一个词  */
            __IO uint32_t ERFEN     :1; /*!< [31:31] 增强的RxFIFO  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ERFCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  RESERVED0 :28; /*!< [27:0]   */
            __IO uint32_t ERFDAIE   :1;  /*!< [28:28] 增强的RxFIFO数据可用的中断启用  */
            __IO uint32_t ERFWMIIE  :1;  /*!< [29:29] 增强RxFIFO水印信号中断  */
            __IO uint32_t ERFOVFIE  :1;  /*!< [30:30] 增强的RxFIFO溢出中断启用  */
            __IO uint32_t ERFUFWIE  :1;  /*!< [31:31] 增强RxFIFO下流中断启用  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ERFIER_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t  ERFEL     :6;  /*!< [5:0] 增强的RxFIFO元素  */
            __I uint32_t  RESERVED0 :10; /*!< [15:6]   */
            __I uint32_t  ERFF      :1;  /*!< [16:16] 增强的RxFIFO满  */
            __I uint32_t  ERFE      :1;  /*!< [17:17] 增强的RxFIFO空  */
            __I uint32_t  RESERVED1 :9;  /*!< [26:18]   */
            __O uint32_t  ERFCLR    :1;  /*!< [27:27] 增强的RxFIFOClear  */
            __IO uint32_t ERFDA     :1;  /*!< [28:28] 增强的RxFIFO数据  */
            __IO uint32_t ERFWMI    :1;  /*!< [29:29] 增强的RxFIFO水印指示  */
            __IO uint32_t ERFOVF    :1;  /*!< [30:30] 增强的RxFIFO过流  */
            __IO uint32_t ERFUFW    :1;  /*!< [31:31] 增强的RxFIFO低流  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ERFSR_T;

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
} CANFD_CLKC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DBGCTL    :4;  /*!< [3:0] OCDS挂起控制位  */
            __O uint32_t  DBGP      :1;  /*!< [4:4] DBGCTL写保护  */
            __I uint32_t  DBGSTA    :1;  /*!< [5:5] 挂起状态位  */
            __IO uint32_t RESERVED0 :26; /*!< [31:6] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_DBG_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位请求位，与RST1寄存器的RST位一起使用  */
            __I uint32_t  RSTSTA    :1;  /*!< [1:1] 复位状态  */
            __IO uint32_t RESERVED0 :30; /*!< [31:2] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_RST0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RST       :1;  /*!< [0:0] 模块复位请求位，与RST0寄存器的RST位一起使用  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_RST1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __O uint32_t  CLR       :1;  /*!< [0:0] RSTSTA复位状态清除，该位自动清零  */
            __IO uint32_t RESERVED0 :31; /*!< [31:1] 预留读为0  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_RSTCLR_T;

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
} CANFD_ACES0_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RESERVED0 :32; /*!< [31:0] 保留位  */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_ACES1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __I uint32_t MODREV  :8;  /*!< [7:0] CANFD模块版本号  */
            __I uint32_t MODTYPE :8;  /*!< [15:8] CANFD模块类型  */
            __I uint32_t MODNUM  :16; /*!< [31:16] CANFD模块编号  */
        } bits;
        __I uint32_t reg;
    };
} CANFD_INFO_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TMEN      :1;  /*!< [0:0]   */
            __IO uint32_t TMSEL     :2;  /*!< [2:1]   */
            __IO uint32_t RESERVED0 :29; /*!< [31:3]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_TM_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t SWR       :2; /*!< [1:0]   */
            __IO uint32_t SRD       :2; /*!< [3:2]   */
            __IO uint32_t RCEL_N    :1; /*!< [4:4]   */
            __IO uint32_t RCER_N    :1; /*!< [5:5]   */
            __IO uint32_t RESERVED0 :2; /*!< [7:6]   */
            __IO uint32_t RCAL      :8; /*!< [15:8]   */
            __IO uint32_t RCAR      :8; /*!< [23:16]   */
            __IO uint32_t VCSB      :1; /*!< [24:24]   */
            __IO uint32_t RESERVED1 :7; /*!< [31:25]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_RAMC_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t RXSEL     :3;  /*!< [2:0]   */
            __IO uint32_t RESERVED0 :29; /*!< [31:3]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_NPCR_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ERROVR      :4; /*!< [3:0] 选择中断输出  */
            __IO uint32_t ERRINT_FAST :4; /*!< [7:4]   */
            __IO uint32_t BOFFDONEINT :4; /*!< [11:8]   */
            __IO uint32_t TWRNINT     :4; /*!< [15:12]   */
            __IO uint32_t RWRNINT     :4; /*!< [19:16]   */
            __IO uint32_t BOFFINT     :4; /*!< [23:20]   */
            __IO uint32_t ERRINT      :4; /*!< [27:24]   */
            __IO uint32_t WAKINT      :4; /*!< [31:28]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IR1_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t TWAINT   :4; /*!< [3:0]   */
            __IO uint32_t HANCEIF  :4; /*!< [7:4]   */
            __IO uint32_t FANCEIF  :4; /*!< [11:8]   */
            __IO uint32_t CEIF     :4; /*!< [15:12]   */
            __IO uint32_t HANCEIOF :4; /*!< [19:16]   */
            __IO uint32_t FANCEIOF :4; /*!< [23:20]   */
            __IO uint32_t CEIOF    :4; /*!< [27:24]   */
            __IO uint32_t WTOF     :4; /*!< [31:28]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IR2_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t WUMF     :4; /*!< [3:0]   */
            __IO uint32_t EDTCFAIL :4; /*!< [7:4]   */
            __IO uint32_t TDCFAIL  :4; /*!< [11:8]   */
            __IO uint32_t ERFUFW   :4; /*!< [15:12]   */
            __IO uint32_t ERFOVF   :4; /*!< [19:16]   */
            __IO uint32_t ERFWMI   :4; /*!< [23:20]   */
            __IO uint32_t ERFDA    :4; /*!< [27:24]   */
            __IO uint32_t MBOR     :4; /*!< [31:28]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IR3_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t DMAREQ    :4;  /*!< [3:0]   */
            __IO uint32_t RESERVED0 :28; /*!< [31:4]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IR4_T;

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t ERROVR      :1; /*!< [0:0]   */
            __IO uint32_t ERRINT_FAST :1; /*!< [1:1]   */
            __IO uint32_t BOFFDONEINT :1; /*!< [2:2]   */
            __IO uint32_t TWRNINT     :1; /*!< [3:3]   */
            __IO uint32_t RWRNINT     :1; /*!< [4:4]   */
            __IO uint32_t BOFFINT     :1; /*!< [5:5]   */
            __IO uint32_t ERRINT      :1; /*!< [6:6]   */
            __IO uint32_t WAKINT      :1; /*!< [7:7]   */
            __IO uint32_t TWAINT      :1; /*!< [8:8]   */
            __IO uint32_t HANCEIF     :1; /*!< [9:9]   */
            __IO uint32_t FANCEIF     :1; /*!< [10:10]   */
            __IO uint32_t CEIF        :1; /*!< [11:11]   */
            __IO uint32_t HANCEIOF    :1; /*!< [12:12]   */
            __IO uint32_t FANCEIOF    :1; /*!< [13:13]   */
            __IO uint32_t CEIOF       :1; /*!< [14:14]   */
            __IO uint32_t WTOF        :1; /*!< [15:15]   */
            __IO uint32_t WUMF        :1; /*!< [16:16]   */
            __IO uint32_t EDTCFAIL    :1; /*!< [17:17]   */
            __IO uint32_t TDCFAIL     :1; /*!< [18:18]   */
            __IO uint32_t ERFUFW      :1; /*!< [19:19]   */
            __IO uint32_t ERFOVF      :1; /*!< [20:20]   */
            __IO uint32_t ERFWMI      :1; /*!< [21:21]   */
            __IO uint32_t ERFDA       :1; /*!< [22:22]   */
            __IO uint32_t MBOR        :1; /*!< [23:23]   */
            __IO uint32_t DMAREQ      :1; /*!< [24:24]   */
            __IO uint32_t RESERVED0   :7; /*!< [31:25]   */
        } bits;
        __IO uint32_t reg;
    };
} CANFD_IE_T;

typedef volatile struct
{
    /*offset address: 0x0000, 模块配置寄存器 */
    CANFD_MCR_T CANFD_MCR;

    /*offset address: 0x0004, 控制1寄存器 */
    CANFD_CTRL1_T CANFD_CTRL1;

    /*offset address: 0x0008, 自由运行计时器寄存器 */
    CANFD_TIMER_T CANFD_TIMER;

    /*offset address: 0x000C, 错误计数器寄存器 */
    uint8_t CANFD_RESERVED_000C[4];

    /*offset address: 0x0010, Rx global mask */
    CANFD_MASK_T RXMGMASK;

    /*offset address: 0x0014,  Rx reg 14 mask */
    CANFD_MASK_T RX14MASK;

    /*offset address: 0x0018,  Rx reg 15 mask */
    CANFD_MASK_T RX15MASK;

    /*offset address: 0x001C, 错误计数器寄存器 */
    CANFD_ECR_T CANFD_ECR;

    /*offset address: 0x0020, 错误和状态1寄存器 */
    CANFD_ESR1_T CANFD_ESR1;

    /*offset address: 0x0024, 中断掩模2寄存器 */
    CANFD_IMASK2_T CANFD_IMASK2;

    /*offset address: 0x0028, 中断掩模1寄存器 */
    CANFD_IMASK1_T CANFD_IMASK1;

    /*offset address: 0x002C, 中断标志2寄存器 */
    CANFD_IFLAG2_T CANFD_IFLAG2;

    /*offset address: 0x0030, 中断标志1寄存器 */
    CANFD_IFLAG1_T CANFD_IFLAG1;

    /*offset address: 0x0034, 控制2寄存器 */
    CANFD_CTRL2_T CANFD_CTRL2;

    /*offset address: 0x0038, 错误和状态2寄存器 */
    CANFD_ESR2_T CANFD_ESR2;

    /*offset address: 0x003C, Rx FIFO Global Mask寄存器*/
    uint32_t CANFD_RXFGMASK;

    /*offset address: 0x0040, Rx FIFO Information寄存器*/
    CANFD_RXFIR_T CANFD_RXFIR;

    /*offset address: 0x0044, CRC寄存器 */
    CANFD_CRCR_T CANFD_CRCR;

    /*offset address: 0x0048, 位定时寄存器 */
    uint8_t CANFD_RESERVED_0048[8];

    /*offset address: 0x0050, 位定时寄存器 */
    CANFD_CBT_T CANFD_CBT;

    /*offset address: 0x0054, 中断掩模4寄存器 */
    uint8_t CANFD_RESERVED_0054[20];

    /*offset address: 0x0068, 中断掩模4寄存器 */
    CANFD_IMASK4_T CANFD_IMASK4;

    /*offset address: 0x006C, 中断掩模3寄存器 */
    CANFD_IMASK3_T CANFD_IMASK3;

    /*offset address: 0x0070, 中断标志4寄存器 */
    CANFD_IFLAG4_T CANFD_IFLAG4;

    /*offset address: 0x0074, 中断标志3寄存器 */
    CANFD_IFLAG3_T CANFD_IFLAG3;

    /*offset address: 0x0880, 内存错误控制寄存器 */
    uint8_t CANFD_RESERVED_0078[24];

    /*offset address: 0x0898, Embedded RAM */
    uint32_t CANFD_RAM[CANFD_MAX_RAMBLOCK];

    /*offset address: 0x0078, 独立邮箱掩码 */
    CANFD_MASK_T CANFD_RXIMR[CANFD_MAX_MBNUM];

    /*offset address: 0x0A80,  */
    uint8_t CANFD_RESERVED_0A80[80];

    /*offset address: 0x0AE0, 内存错误控制寄存器 */
    CANFD_MECR_T CANFD_MECR;

    /*offset address: 0x0AE4, 错误注入地址寄存器 */
    CANFD_ERRIAR_T CANFD_ERRIAR;

    /*offset address: 0x0AE8, 错误注入数据模式寄存器 */
    CANFD_ERRIDPR_T CANFD_ERRIDPR;

    /*offset address: 0x0AEC, 错误注入奇偶校验模式寄存器 */
    CANFD_ERRIPPR_T CANFD_ERRIPPR;

    /*offset address: 0x0AF0, 错误报告地址寄存器 */
    CANFD_RERRAR_T CANFD_RERRAR;

    /*offset address: 0x0AF4, 错误报告数据寄存器 */
    CANFD_RERRDR_T CANFD_RERRDR;

    /*offset address: 0x0AF8, 错误报告综合症登记 */
    CANFD_RERRSYNR_T CANFD_RERRSYNR;

    /*offset address: 0x0AFC, 错误状态寄存器 */
    CANFD_ERRSR_T CANFD_ERRSR;

    /*offset address: 0x0B00, 假装网络控制1寄存器 */
    CANFD_CTRL1_PN_T CANFD_CTRL1_PN;

    /*offset address: 0x0B04, 假装网络控制2寄存器 */
    CANFD_CTRL2_PN_T CANFD_CTRL2_PN;

    /*offset address: 0x0B08, 假网络唤醒匹配寄存器 */
    CANFD_WU_MTC_T CANFD_WU_MTC;

    /*offset address: 0x0B0C, 假网ID滤波器1寄存器 */
    CANFD_FLT_ID1_T CANFD_FLT_ID1;

    /*offset address: 0x0B10, 假网络DLC滤波器寄存器 */
    CANFD_FLT_DLC_T CANFD_FLT_DLC;

    /*offset address: 0x0B14, 假网络有效负载低过滤器1寄存器 */
    CANFD_PL1_LO_T CANFD_PL1_LO;

    /*offset address: 0x0B18, 装假网络负载高过滤器1寄存器 */
    CANFD_PL1_HI_T CANFD_PL1_HI;

    /*offset address: 0x0B1C, 假网ID滤波器2寄存器/ID掩码寄存器 */
    CANFD_FLT_ID2_IDMASK_T CANFD_FLT_ID2_IDMASK;

    /*offset address: 0x0B20, 假网络有效负载低过滤器2寄存器/有效负载低掩码寄存器 */
    CANFD_PL2_PLMASK_LO_T CANFD_PL2_PLMASK_LO;

    /*offset address: 0x0B24, 假网络负载高过滤器2高阶位/有效负载高掩码寄存器 */
    CANFD_PL2_PLMASK_HI_T CANFD_PL2_PLMASK_HI;

    /*offset address: 0x0B28, 唤醒C/S的消息缓冲区寄存器 */
    uint8_t CANFD_RESERVED_0B28[24];

    /*offset address: 0x0B40, 唤醒 MSG的消息缓冲区寄存器 */
    struct
    {
        __I CANFD_WMB_CS_T  WMBn_CS;
        __I CANFD_WMB_ID_T  WMBn_ID;
        __I CANFD_WMB_D03_T WMBn_D03;
        __I CANFD_WMB_D47_T WMBn_D47;
    } WMB[4];

    /*offset address: 0x0B80, 增强CAN比特定时预置寄存器寄存器 */
    uint8_t CANFD_RESERVED_0B80[112];

    /*offset address: 0x0BF0, 增强CAN比特定时预置寄存器寄存器 */
    CANFD_EPRS_T CANFD_EPRS;

    /*offset address: 0x0BF4, 增强标称CAN比特计时寄存器 */
    CANFD_ENCBT_T CANFD_ENCBT;

    /*offset address: 0x0BF8, 增强的数据相位可以比特计时寄存器 */
    CANFD_EDCBT_T CANFD_EDCBT;

    /*offset address: 0x0BFC, 增强收发延迟补偿寄存器 */
    CANFD_ETDC_T CANFD_ETDC;

    /*offset address: 0x0C00, CANFD控制寄存器 */
    CANFD_FDCTRL_T CANFD_FDCTRL;

    /*offset address: 0x0C04, CANFD位定时寄存器 */
    CANFD_FDCBT_T CANFD_FDCBT;

    /*offset address: 0x0C08, CANFDCRC寄存器 */
    CANFD_FDCRC_T CANFD_FDCRC;

    /*offset address: 0x0C0C, 增强的RxFIFO控制寄存器 */
    CANFD_ERFCR_T CANFD_ERFCR;

    /*offset address: 0x0C10, 增强的RxFIFO中断启用寄存器 */
    CANFD_ERFIER_T CANFD_ERFIER;

    /*offset address: 0x0C14, 增强的RxFIFO状态寄存器 */
    CANFD_ERFSR_T CANFD_ERFSR;

    /*offset address: 0x0C18, CANFD时钟控制寄存器 */
    uint8_t CANFD_RESERVED_0C18[9704];

    /*offset address: 0x3200, CANFD时钟控制寄存器 */
    CANFD_CLKC_T CANFD_CLKC;

    /*offset address: 0x3204, CANFD调试寄存器 */
    CANFD_DBG_T CANFD_DBG;

    /*offset address: 0x3208, CANFD复位寄存器0 */
    CANFD_RST0_T CANFD_RST0;

    /*offset address: 0x320C, CANFD复位寄存器1 */
    CANFD_RST1_T CANFD_RST1;

    /*offset address: 0x3210, CANFD复位状态清零寄存器 */
    CANFD_RSTCLR_T CANFD_RSTCLR;

    /*offset address: 0x3214, CANFD访问控制使能寄存器0 */
    CANFD_ACES0_T CANFD_ACES0;

    /*offset address: 0x3218, CANFD访问控制使能寄存器1 */
    CANFD_ACES1_T CANFD_ACES1;

    /*offset address: 0x321C, CANFD基本信息寄存器 */
    CANFD_INFO_T CANFD_INFO;

    /*offset address: 0x3220, CANFD测试模式寄存器 */
    CANFD_TM_T CANFD_TM;

    /*offset address: 0x3224, CANFDRAM控制寄存器 */
    CANFD_RAMC_T CANFD_RAMC;

    /*offset address: 0x3228, CANFD节点引脚控制寄存器 */
    CANFD_NPCR_T CANFD_NPCR;

    /*offset address: 0x322C, 中断路由寄存器1 */
    CANFD_IR1_T CANFD_IR1;

    /*offset address: 0x3230, 中断路由寄存器2 */
    CANFD_IR2_T CANFD_IR2;

    /*offset address: 0x3234, 中断路由寄存器3 */
    CANFD_IR3_T CANFD_IR3;

    /*offset address: 0x3238, 中断路由寄存器4 */
    CANFD_IR4_T CANFD_IR4;

    /*offset address: 0x323C, 中断使能寄存器 */
    CANFD_IE_T CANFD_IE;
} Canfd_RegisterMap_t, *CanfdPtr;

#define CANFD0_ADDR ((uint32_t)0xF0040000)
#define CANFD0_PTR  ((CanfdPtr)CANFD0_ADDR)
#define CANFD0_RM   (*(CanfdPtr)CANFD0_ADDR)

#define CANFD1_ADDR ((uint32_t)0xF0044000)
#define CANFD1_PTR  ((CanfdPtr)CANFD1_ADDR)
#define CANFD1_RM   (*(CanfdPtr)CANFD1_ADDR)

#define CANFD2_ADDR ((uint32_t)0xF0048000)
#define CANFD2_PTR  ((CanfdPtr)CANFD2_ADDR)
#define CANFD2_RM   (*(CanfdPtr)CANFD2_ADDR)

#define CANFD3_ADDR ((uint32_t)0xF004C000)
#define CANFD3_PTR  ((CanfdPtr)CANFD3_ADDR)
#define CANFD3_RM   (*(CanfdPtr)CANFD3_ADDR)

#define CANFD4_ADDR ((uint32_t)0xF0050000)
#define CANFD4_PTR  ((CanfdPtr)CANFD4_ADDR)
#define CANFD4_RM   (*(CanfdPtr)CANFD4_ADDR)

#define CANFD5_ADDR ((uint32_t)0xF0054000)
#define CANFD5_PTR  ((CanfdPtr)CANFD5_ADDR)
#define CANFD5_RM   (*(CanfdPtr)CANFD5_ADDR)

#define CANFD6_ADDR ((uint32_t)0xF0058000)
#define CANFD6_PTR  ((CanfdPtr)CANFD6_ADDR)
#define CANFD6_RM   (*(CanfdPtr)CANFD6_ADDR)

#define CANFD7_ADDR ((uint32_t)0xF005C000)
#define CANFD7_PTR  ((CanfdPtr)CANFD7_ADDR)
#define CANFD7_RM   (*(CanfdPtr)CANFD7_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
