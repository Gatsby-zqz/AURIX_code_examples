/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_spi_enum.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-04-10
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
 *  |2023-04-10  |V1.0     |Wang Jianzhong  | New Creat
 *****************************************************************************/
#ifndef _KF32DA13K_DRV_SPIENUM_H_
#define _KF32DA13K_DRV_SPIENUM_H_

#ifdef __cplusplus
extern "C" {
#endif

/** \brief Debug Mode Hangs Control
 */
typedef enum
{
	SPI_DBG_DBGCTL_0B=0,			/**<\brief Not Hung Up >*/
	SPI_DBG_DBGCTL_1B=1,			/**<\brief Hardware Hanged Clock Closed>*/
	SPI_DBG_DBGCTL_10B=2			/**<\brief Software Hanged>*/
}Spi_Dbg_Dbgctl_Id_t;
#define CHECK_SPI_DBG_DBGCTL_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_DBG_DBGCTL_10B)

/** \brief Enable Access For Master Tag Id N
 */
typedef enum
{
	SPI_ACES0_EN_ID_0,				/**<\brief Master Tag Id Is 0>*/
	SPI_ACES0_EN_ID_1,				/**<\brief Master Tag Id Is 1>*/
	SPI_ACES0_EN_ID_2,				/**<\brief Master Tag Id Is 2>*/
	SPI_ACES0_EN_ID_3,				/**<\brief Master Tag Id Is 3>*/
	SPI_ACES0_EN_ID_4,				/**<\brief Master Tag Id Is 4>*/
	SPI_ACES0_EN_ID_5,				/**<\brief Master Tag Id Is 5>*/
	SPI_ACES0_EN_ID_6,				/**<\brief Master Tag Id Is 6>*/
	SPI_ACES0_EN_ID_7,				/**<\brief Master Tag Id Is 7>*/
	SPI_ACES0_EN_ID_8,				/**<\brief Master Tag Id Is 8>*/
	SPI_ACES0_EN_ID_9,				/**<\brief Master Tag Id Is 9>*/
	SPI_ACES0_EN_ID_10,				/**<\brief Master Tag Id Is 10>*/
	SPI_ACES0_EN_ID_11,				/**<\brief Master Tag Id Is 11>*/
	SPI_ACES0_EN_ID_12,				/**<\brief Master Tag Id Is 12>*/
	SPI_ACES0_EN_ID_13,				/**<\brief Master Tag Id Is 13>*/
	SPI_ACES0_EN_ID_14,				/**<\brief Master Tag Id Is 14>*/
	SPI_ACES0_EN_ID_15,				/**<\brief Master Tag Id Is 15>*/
	SPI_ACES0_EN_ID_16,				/**<\brief Master Tag Id Is 16>*/
	SPI_ACES0_EN_ID_17,				/**<\brief Master Tag Id Is 17>*/
	SPI_ACES0_EN_ID_18,				/**<\brief Master Tag Id Is 18>*/
	SPI_ACES0_EN_ID_19,				/**<\brief Master Tag Id Is 19>*/
	SPI_ACES0_EN_ID_20,				/**<\brief Master Tag Id Is 20>*/
	SPI_ACES0_EN_ID_21,				/**<\brief Master Tag Id Is 21>*/
	SPI_ACES0_EN_ID_22,				/**<\brief Master Tag Id Is 22>*/
	SPI_ACES0_EN_ID_23,				/**<\brief Master Tag Id Is 23>*/
	SPI_ACES0_EN_ID_24,				/**<\brief Master Tag Id Is 24>*/
	SPI_ACES0_EN_ID_25,				/**<\brief Master Tag Id Is 25>*/
	SPI_ACES0_EN_ID_26,				/**<\brief Master Tag Id Is 26>*/
	SPI_ACES0_EN_ID_27,				/**<\brief Master Tag Id Is 27>*/
	SPI_ACES0_EN_ID_28,				/**<\brief Master Tag Id Is 28>*/
	SPI_ACES0_EN_ID_29,				/**<\brief Master Tag Id Is 29>*/
	SPI_ACES0_EN_ID_30,				/**<\brief Master Tag Id Is 30>*/
	SPI_ACES0_EN_ID_31				/**<\brief Master Tag Id Is 31>*/
}Spi_Aces0_En_Id_t;
#define CHECK_SPI_ACES0_EN_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_ACES0_EN_ID_31)

/** \brief Overtime Length Setting 
 */
typedef enum
{
	SPI_CTL0_EXPECT_0B=0,			/**<\brief Overtime Length Is 2^6>*/
	SPI_CTL0_EXPECT_1B=1,			/**<\brief Overtime Length Is 2^7>*/
	SPI_CTL0_EXPECT_10B=2,			/**<\brief Overtime Length Is 2^8>*/
	SPI_CTL0_EXPECT_11B=3,			/**<\brief Overtime Length Is 2^9>*/
	SPI_CTL0_EXPECT_100B=4,			/**<\brief Overtime Length Is 2^10>*/
	SPI_CTL0_EXPECT_101B=5,			/**<\brief Overtime Length Is 2^11>*/
	SPI_CTL0_EXPECT_110B=6,			/**<\brief Overtime Length Is 2^12>*/
	SPI_CTL0_EXPECT_111B=7,			/**<\brief Overtime Length Is 2^13>*/
	SPI_CTL0_EXPECT_1000B=8,		/**<\brief Overtime Length Is 2^14>*/
	SPI_CTL0_EXPECT_1001B=9,		/**<\brief Overtime Length Is 2^15>*/
	SPI_CTL0_EXPECT_1010B=10,		/**<\brief Overtime Length Is 2^16>*/
	SPI_CTL0_EXPECT_1011B=11,		/**<\brief Overtime Length Is 2^17>*/
	SPI_CTL0_EXPECT_1100B=12,		/**<\brief Overtime Length Is 2^18>*/
	SPI_CTL0_EXPECT_1101B=13,		/**<\brief Overtime Length Is 2^19>*/
	SPI_CTL0_EXPECT_1110B=14,		/**<\brief Overtime Length Is 2^20>*/
	SPI_CTL0_EXPECT_1111B=15		/**<\brief Overtime Length Is 2^21>*/
}Spi_Ctl0_Expect_Id_t;
#define CHECK_SPI_CTL0_EXPECT_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CTL0_EXPECT_1111B)

/** \brief Ss0 Delay Mode Selection Delay
 */
typedef enum
{
	SPI_CTL0_STROBE_0B=0,		/**<\brief Ss0 Delay Mode Selection Delay Is 1>*/
	SPI_CTL0_STROBE_1B=1,		/**<\brief Ss0 Delay Mode Selection Delay Is 2>*/
	SPI_CTL0_STROBE_10B=2,		/**<\brief Ss0 Delay Mode Selection Delay Is 3>*/
	SPI_CTL0_STROBE_11B=3,		/**<\brief Ss0 Delay Mode Selection Delay Is 4>*/
	SPI_CTL0_STROBE_100B=4,		/**<\brief Ss0 Delay Mode Selection Delay Is 5>*/
	SPI_CTL0_STROBE_101B=5,		/**<\brief Ss0 Delay Mode Selection Delay Is 6>*/
	SPI_CTL0_STROBE_110B=6,		/**<\brief Ss0 Delay Mode Selection Delay Is 7>*/
	SPI_CTL0_STROBE_111B=7,		/**<\brief Ss0 Delay Mode Selection Delay Is 8>*/
	SPI_CTL0_STROBE_1000B=8,	/**<\brief Ss0 Delay Mode Selection Delay Is 9>*/
	SPI_CTL0_STROBE_1001B=9,	/**<\brief Ss0 Delay Mode Selection Delay Is 10>*/
	SPI_CTL0_STROBE_1010B=10,	/**<\brief Ss0 Delay Mode Selection Delay Is 11>*/
	SPI_CTL0_STROBE_1011B=11,	/**<\brief Ss0 Delay Mode Selection Delay Is 12>*/
	SPI_CTL0_STROBE_1100B=12,	/**<\brief Ss0 Delay Mode Selection Delay Is 13>*/
	SPI_CTL0_STROBE_1101B=13,	/**<\brief Ss0 Delay Mode Selection Delay Is 14>*/
	SPI_CTL0_STROBE_1110B=14,	/**<\brief Ss0 Delay Mode Selection Delay Is 15>*/
	SPI_CTL0_STROBE_1111B=15,	/**<\brief Ss0 Delay Mode Selection Delay Is 16>*/
	SPI_CTL0_STROBE_10000B=16,	/**<\brief Ss0 Delay Mode Selection Delay Is 17>*/
	SPI_CTL0_STROBE_10001B=17,	/**<\brief Ss0 Delay Mode Selection Delay Is 18>*/
	SPI_CTL0_STROBE_10010B=18,	/**<\brief Ss0 Delay Mode Selection Delay Is 19>*/
	SPI_CTL0_STROBE_10011B=19,	/**<\brief Ss0 Delay Mode Selection Delay Is 20>*/
	SPI_CTL0_STROBE_10100B=20,	/**<\brief Ss0 Delay Mode Selection Delay Is 21>*/
	SPI_CTL0_STROBE_10101B=21,	/**<\brief Ss0 Delay Mode Selection Delay Is 22>*/
	SPI_CTL0_STROBE_10110B=22,	/**<\brief Ss0 Delay Mode Selection Delay Is 23>*/
	SPI_CTL0_STROBE_10111B=23,	/**<\brief Ss0 Delay Mode Selection Delay Is 24>*/
	SPI_CTL0_STROBE_11000B=24,	/**<\brief Ss0 Delay Mode Selection Delay Is 25>*/
	SPI_CTL0_STROBE_11001B=25,	/**<\brief Ss0 Delay Mode Selection Delay Is 26>*/
	SPI_CTL0_STROBE_11010B=26,	/**<\brief Ss0 Delay Mode Selection Delay Is 27>*/
	SPI_CTL0_STROBE_11011B=27,	/**<\brief Ss0 Delay Mode Selection Delay Is 28>*/
	SPI_CTL0_STROBE_11100B=28,	/**<\brief Ss0 Delay Mode Selection Delay Is 29>*/
	SPI_CTL0_STROBE_11101B=29,	/**<\brief Ss0 Delay Mode Selection Delay Is 30>*/
	SPI_CTL0_STROBE_11110B=30,	/**<\brief Ss0 Delay Mode Selection Delay Is 31>*/
	SPI_CTL0_STROBE_11111B=31	/**<\brief Ss0 Delay Mode Selection Delay Is 32>*/
}Spi_Ctl0_Strobe_Id_t;
#define CHECK_SPI_CTL0_STROBE_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CTL0_STROBE_11111B)

/** \brief Host Selection From The Machine Mode
 */
typedef enum
{
	SPI_CTL0_MOD_00B=0,			/**<\brief Master:Send And Receive>*/
	SPI_CTL0_MOD_01B=1,			/**<\brief Reserved>*/
	SPI_CTL0_MOD_10B=2,			/**<\brief Slave:Send And Receive>*/
	SPI_CTL0_MOD_11B=3			/**<\brief Slave:Send And Receive>*/
}Spi_Ctl0_Mod_Id_t;
#define CHECK_SPI_CTL0_MOD_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CTL0_MOD_11B)

/** \brief Reset Module
 */
typedef enum
{
	SPI_CTL0_CLR_00B=0,			/**<\brief No Action>*/
	SPI_CTL0_CLR_01B=1,			/**<\brief Only Reset The Internal Logic Of Spi>*/
	SPI_CTL0_CLR_10B=2,			/**<\brief Only Reset The Spi Register>*/
	SPI_CTL0_CLR_11B=3			/**<\brief Spi Internal Logic And Register Are Restored>*/
}Spi_Ctl0_Clr_Id_t;
#define CHECK_SPI_CTL0_CLR_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CTL0_CLR_11B)

/** \brief Transmit Fifo Threshold Setting 
 */
typedef enum
{
	SPI_CTL1_TXTHRES_00B=0,		/**<\brief Transmit Fifo Threshold Is 1>*/
	SPI_CTL1_TXTHRES_01B=1,		/**<\brief Transmit Fifo Threshold Is 2>*/
	SPI_CTL1_TXTHRES_10B=2,		/**<\brief Transmit Fifo Threshold Is 3>*/
	SPI_CTL1_TXTHRES_11B=3		/**<\brief Transmit Fifo Threshold Is 4>*/
}Spi_Ctl1_Txthres_Id_t;
#define CHECK_SPI_CTL1_TXTHRES_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CTL1_TXTHRES_11B)

/** \brief Receive Fifo Threshold Setting 
 */
typedef enum
{
	SPI_CTL1_RXTHRES_00B=0,		/**<\brief Receive Fifo Threshold Is 0>*/
	SPI_CTL1_RXTHRES_01B=1,		/**<\brief Receive Fifo Threshold Is 1>*/
	SPI_CTL1_RXTHRES_10B=2,		/**<\brief Receive Fifo Threshold Is 2>*/
	SPI_CTL1_RXTHRES_11B=3		/**<\brief Receive Fifo Threshold Is 3>*/
}Spi_Ctl1_Rxthres_Id_t;
#define CHECK_SPI_CTL1_RXTHRES_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CTL1_RXTHRES_11B)

/** \brief Receive Fifo Mode Setting 
 */
typedef enum
{
	SPI_CTL1_TXMOD_00B=0,		/**<\brief Combined Move Mode>*/
	SPI_CTL1_TXMOD_01B=1,		/**<\brief Single Move Mode>*/
	SPI_CTL1_TXMOD_10B=2,		/**<\brief Batch Move Mode>*/
	SPI_CTL1_TXMOD_11B=3		/**<\brief Reserved>*/
}Spi_Ctl1_Txmod_Id_t;
#define CHECK_SPI_CTL1_TXMOD_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CTL1_TXMOD_11B)

/** \brief Receive Fifo Mode Setting 
 */
typedef enum
{
	SPI_CTL1_RXMOD_00B=0,		/**<\brief Combined Move Mode>*/
	SPI_CTL1_RXMOD_01B=1,		/**<\brief Single Move Mode>*/
	SPI_CTL1_RXMOD_10B=2,		/**<\brief Batch Move Mode>*/
	SPI_CTL1_RXMOD_11B=3		/**<\brief Reserved>*/
}Spi_Ctl1_Rxmod_Id_t;
#define CHECK_SPI_CTL1_RXMOD_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CTL1_RXMOD_11B)

/** \brief Triggering_Pt1_Interrupt_Event_Selection_Bit
 */
typedef enum
{
	SPI_CTL1_PT1SEL_000B=0,		/**<\brief Master：Ending&Waiting Stage Slave: waiting For Shifting Clock While Sending Data>*/
	SPI_CTL1_PT1SEL_001B=1,		/**<\brief Master: Change Of Polar>*/
	SPI_CTL1_PT1SEL_010B=2,		/**<\brief Master: Starting Frame Slave: Start Of First Bit Transfering>*/
	SPI_CTL1_PT1SEL_011B=3,		/**<\brief Master: Empty Of Tx Buffer Slave: SPI Shift Data From TXFIFO>*/
	SPI_CTL1_PT1SEL_100B=4,		/**<\brief Master: Fill Rx Buffer Slave: Received Data Written To Rx FIFO>*/
	SPI_CTL1_PT1SEL_101B=5,		/**<\brief Master: Ending Frame Slave: Last Data Has Been Received>*/
	SPI_CTL1_PT1SEL_110B=6,		/**<\brief Master: Data Unavailable Starting Of Excepted Stage>*/
	SPI_CTL1_PT1SEL_111B=7		/**<\brief Master: Ending Of Excepted Stage>*/
}Spi_Ctl1_Pt1sel_Id_t;
#define CHECK_SPI_CTL1_PT1SEL_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CTL1_PT1SEL_111B)

/** \brief Triggering_Pt2_Interrupt_Event_Selection_Bit
 */
typedef enum
{
	SPI_CTL1_PT2SEL_001B=0,		/**<\brief Master：Ending&Waiting Stage>*/
	SPI_CTL1_PT2SEL_010B=1,		/**<\brief Master：Change Of Polar>*/
	SPI_CTL1_PT2SEL_011B=2,		/**<\brief Master：Starting Frame*/
	SPI_CTL1_PT2SEL_100B=3,		/**<\brief Master：Empty Of Tx Buffer>*/
	SPI_CTL1_PT2SEL_101B=4,		/**<\brief Master：Fill Rx Buffer>*/
	SPI_CTL1_PT2SEL_110B=5,		/**<\brief Master：Ending Frame>*/
	SPI_CTL1_PT2SEL_111B=6,		/**<\brief Master：Data Unavailable Starting Of Excepted Stage>*/
	SPI_CTL1_PT2SEL_000B=7		/**<\brief Master：Ending Of Excepted Stage>*/

}Spi_Ctl1_Pt2sel_Id_t;
#define CHECK_SPI_CTL1_PT2SEL_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CTL1_PT2SEL_111B)

/** \brief Length Of Section A
 */
typedef enum
{
	SPI_CHCTL_ACNT_00B=0,		/**<\brief Length Of Section A Is 0>*/
	SPI_CHCTL_ACNT_01B=1,		/**<\brief Length Of Section A Is 1>*/
	SPI_CHCTL_ACNT_10B=2,		/**<\brief Length Of Section A Is 2>*/
	SPI_CHCTL_ACNT_11B=3		/**<\brief Length Of Section A Is 3>*/
}Spi_Chctl_Acnt_Id_t;
#define CHECK_SPI_CHCTL_ACNT_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CHCTL_ACNT_11B)

/** \brief Length Of Section B
 */
typedef enum
{
	SPI_CHCTL_BCNT_00B=0,		/**<\brief Length Of Section B Is 0>*/
	SPI_CHCTL_BCNT_01B=1,		/**<\brief Length Of Section B Is 1>*/
	SPI_CHCTL_BCNT_10B=2,		/**<\brief Length Of Section B Is 2>*/
	SPI_CHCTL_BCNT_11B=3		/**<\brief Length Of Section B Is 3>*/
}Spi_Chctl_Bcnt_Id_t;
#define CHECK_SPI_CHCTL_BCNT_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CHCTL_BCNT_11B)

/** \brief Length Of Section C
 */
typedef enum
{
	SPI_CHCTL_CCNT_00B=0,		/**<\brief Length Of Section C Is 0>*/
	SPI_CHCTL_CCNT_01B=1,		/**<\brief Length Of Section C Is 1>*/
	SPI_CHCTL_CCNT_10B=2,		/**<\brief Length Of Section C Is 2>*/
	SPI_CHCTL_CCNT_11B=3		/**<\brief Length Of Section C Is 3>*/
}Spi_Chctl_Ccnt_Id_t;
#define CHECK_SPI_CHCTL_CCNT_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CHCTL_CCNT_11B)

/** \brief Conversion Mode Of Large End Byte
 */
typedef enum
{
	SPI_CHCTL_BIGEND_00B=0,		/**<\brief Disable>*/
	SPI_CHCTL_BIGEND_01B=1,		/**<\brief 16 Large Sections>*/
	SPI_CHCTL_BIGEND_10B=2,		/**<\brief 21St Large Sections>*/
	SPI_CHCTL_BIGEND_11B=3,		/**<\brief Disable>*/
}Spi_Chctl_Bigend_Id_t;
#define CHECK_SPI_CHCTL_BIGEND_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_CHCTL_BIGEND_1B)

/** \brief Pdiv Of Ending Stage 2
 */
typedef enum
{
	SPI_MCTL_TPREDIV2_000B=0,	/**<\brief Pdiv Of Ending Stage 2 Is 1>*/
	SPI_MCTL_TPREDIV2_001B=1,	/**<\brief Pdiv Of Ending Stage 2 Is 4>*/
	SPI_MCTL_TPREDIV2_10B=2,	/**<\brief Pdiv Of Ending Stage 2 Is 16>*/
	SPI_MCTL_TPREDIV2_11B=3,	/**<\brief Pdiv Of Ending Stage 2 Is 64/
	SPI_MCTL_TPREDIV2_100B=4,	/**<\brief Pdiv Of Ending Stage 2 Is 256>*/
	SPI_MCTL_TPREDIV2_101B=5,	/**<\brief Pdiv Of Ending Stage 2 Is 1024>*/
	SPI_MCTL_TPREDIV2_110B=6,	/**<\brief Pdiv Of Ending Stage 2 Is 4096>*/
	SPI_MCTL_TPREDIV2_111B=7	/**<\brief Pdiv Of Ending Stage 2 Is 16384>*/
}Spi_Mctl_Tprediv2_Id_t;
#define CHECK_SPI_MCTL_TPREDIV2_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_MCTL_TPREDIV2_111B)

/** \brief The Length Of Ending Stage 2
 */
typedef enum
{
	SPI_MCTL_TCNT2_000B=0,		/**<\brief The Length Is 1Tper>*/
	SPI_MCTL_TCNT2_001B=1,		/**<\brief The Length Is 2Tper>*/
	SPI_MCTL_TCNT2_10B=2,		/**<\brief The Length Is 3Tper>*/
	SPI_MCTL_TCNT2_11B=3,		/**<\brief The Length Is 4Tper>*/
	SPI_MCTL_TCNT2_100B=4,		/**<\brief The Length Is 5Tper>*/
	SPI_MCTL_TCNT2_101B=5,		/**<\brief The Length Is 6Tper>*/
	SPI_MCTL_TCNT2_110B=6,		/**<\brief The Length Is 7Tper>*/
	SPI_MCTL_TCNT2_111B=7		/**<\brief The Length Is 8Tper>*/
}Spi_Mctl_Tcnt2_Id_t;
#define CHECK_SPI_MCTL_TCNT2_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_MCTL_TCNT2_111B)

/** \brief RX Pin In Master Mode
 */
typedef enum
{
	SPI_PORTSEL_MRIS_000B=0,	/**<\brief Select Port A As Rx Pin>*/
	SPI_PORTSEL_MRIS_001B=1,	/**<\brief Select Port B As Rx Pin>*/
	SPI_PORTSEL_MRIS_010B=2,	/**<\brief Select Port C As Rx Pin>*/
	SPI_PORTSEL_MRIS_011B=3,	/**<\brief Select Port D As Rx Pin>*/
	SPI_PORTSEL_MRIS_100B=4,	/**<\brief Select Port E As Rx Pin>*/
	SPI_PORTSEL_MRIS_101B=5,	/**<\brief Select Port F As Rx Pin>*/
	SPI_PORTSEL_MRIS_110B=6,	/**<\brief Select Port G As Rx Pin>*/
	SPI_PORTSEL_MRIS_111B=7		/**<\brief Select Port H As Rx Pin>*/
}Spi_Portsel_Mris_Id_t;
#define CHECK_SPI_PORTSEL_MRIS_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_PORTSEL_MRIS_111B)

/** \brief Rx Pin In Slave Mode
 */
typedef enum
{
	SPI_PORTSEL_SRIS_000B=0,	/**<\brief Select Port A As Rx Pin>*/
	SPI_PORTSEL_SRIS_001B=1,	/**<\brief Select Port B As Rx Pin>*/
	SPI_PORTSEL_SRIS_010B=2,	/**<\brief Select Port C As Rx Pin>*/
	SPI_PORTSEL_SRIS_011B=3,	/**<\brief Select Port D As Rx Pin>*/
	SPI_PORTSEL_SRIS_100B=4,	/**<\brief Select Port E As Rx Pin>*/
	SPI_PORTSEL_SRIS_101B=5,	/**<\brief Select Port F As Rx Pin>*/
	SPI_PORTSEL_SRIS_110B=6,	/**<\brief Select Port G As Rx Pin>*/
	SPI_PORTSEL_SRIS_111B=7		/**<\brief Select Port H As Rx Pin>*/
}Spi_Portsel_Sris_Id_t;
#define CHECK_SPI_PORTSEL_SRIS_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_PORTSEL_SRIS_111B)

/** \brief Clock Input Pin In Slave Mode
 */
typedef enum
{
	SPI_PORTSEL_SCIS_000B=0,	/**<\brief Select Port A As Clock Input Pin>*/
	SPI_PORTSEL_SCIS_001B=1,	/**<\brief Select Port B As Clock Input Pin>*/
	SPI_PORTSEL_SCIS_010B=2,	/**<\brief Select Port C As Clock Input Pin>*/
	SPI_PORTSEL_SCIS_011B=3,	/**<\brief Select Port D As Clock Input Pin>*/
	SPI_PORTSEL_SCIS_100B=4,	/**<\brief Select Port E As Clock Input Pin>*/
	SPI_PORTSEL_SCIS_101B=5,	/**<\brief Select Port F As Clock Input Pin>*/
	SPI_PORTSEL_SCIS_110B=6,	/**<\brief Select Port G As Clock Input Pin>*/
	SPI_PORTSEL_SCIS_111B=7		/**<\brief Select Port H As Clock Input Pin>*/
}Spi_Portsel_Scis_Id_t;
#define CHECK_SPI_PORTSEL_SCIS_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_PORTSEL_SCIS_111B)

/** \brief Input Pin Select In Slave Mode
 */
typedef enum
{
	SPI_PORTSEL_SLSIS_000B=0,	/**<\brief No_Input>*/
	SPI_PORTSEL_SLSIS_001B=1,	/**<\brief Select Port A As SS Input Pin>*/
	SPI_PORTSEL_SLSIS_010B=2,	/**<\brief Select Port B As SS Input Pin>*/
	SPI_PORTSEL_SLSIS_011B=3,	/**<\brief Select Port C As SS Input Pin>*/
	SPI_PORTSEL_SLSIS_100B=4,	/**<\brief Select Port D As SS Input Pin>*/
	SPI_PORTSEL_SLSIS_101B=5,	/**<\brief Select Port E As SS Input Pin>*/
	SPI_PORTSEL_SLSIS_110B=6,	/**<\brief Select Port F As SS Input Pin>*/
	SPI_PORTSEL_SLSIS_111B=7	/**<\brief Select Port G As SS Input Pin>*/
}Spi_Portsel_Slsis_Id_t;
#define CHECK_SPI_PORTSEL_SLSIS_ID(x) ((uint32_t)(x) <= (uint32_t)SPI_PORTSEL_SLSIS_111B)

#define CHECK_SPI_ALL_PERIPH_ADDR(PERIPH)   \ 
(((PERIPH)==SPI0PTR) || \ 
((PERIPH)==SPI1PTR) || \ 
((PERIPH)==SPI2PTR) || \ 
((PERIPH)==SPI3PTR))

#ifdef __cplusplus
}
#endif
#endif
/* EOF */
