/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_hw_systick.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2024-02-23
 *  @Version         : V0.0.1.240223_alpha
 *  @Description     : This document describes the C language document template
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyrght protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2024-2-23    |V1.0    |Wei Xing  | New
 *****************************************************************************/
#ifndef KF32A13K_HW_SYSTICK_H
#define KF32A13K_HW_SYSTICK_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                      MISRA-C Rules Violations
 ******************************************************************************/

/******************************************************************************
 **                      QAC Warnings
 ******************************************************************************/

/******************************************************************************
 **                      Include Files
 ******************************************************************************/
#include <dev_assert.h>
#include <kf32a13k_hw_scu.h>
#include <kf32a13k_drv_scu.h>
#include <kf32a13k_drv_int.h>
#include <kf32a13k_reg_systick.h>
#include <kf_types.h>
/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                      Typedef  Definitions
 ******************************************************************************/
typedef enum
{
    SYSTICK_HW_COMPARATOR_0,
    SYSTICK_HW_COMPARATOR_1,
} Systick_Hw_Comparator_t;

typedef enum
{
    SYSTICK_HW_INTERRUPT_STIR0,
    SYSTICK_HW_INTERRUPT_STIR1,
} Systick_Hw_ComparatorInterrupt_t;

typedef enum
{
    SYSTICK_HW_COMPARATOR_OFFSET0,
    SYSTICK_HW_COMPARATOR_OFFSET1,
    SYSTICK_HW_COMPARATOR_OFFSET2,
    SYSTICK_HW_COMPARATOR_OFFSET3,
    SYSTICK_HW_COMPARATOR_OFFSET4,
    SYSTICK_HW_COMPARATOR_OFFSET5,
    SYSTICK_HW_COMPARATOR_OFFSET6,
    SYSTICK_HW_COMPARATOR_OFFSET7,
    SYSTICK_HW_COMPARATOR_OFFSET8,
    SYSTICK_HW_COMPARATOR_OFFSET9,
    SYSTICK_HW_COMPARATOR_OFFSET10,
    SYSTICK_HW_COMPARATOR_OFFSET11,
    SYSTICK_HW_COMPARATOR_OFFSET12,
    SYSTICK_HW_COMPARATOR_OFFSET13,
    SYSTICK_HW_COMPARATOR_OFFSET14,
    SYSTICK_HW_COMPARATOR_OFFSET15,
    SYSTICK_HW_COMPARATOR_OFFSET16,
    SYSTICK_HW_COMPARATOR_OFFSET17,
    SYSTICK_HW_COMPARATOR_OFFSET18,
    SYSTICK_HW_COMPARATOR_OFFSET19,
    SYSTICK_HW_COMPARATOR_OFFSET20,
    SYSTICK_HW_COMPARATOR_OFFSET21,
    SYSTICK_HW_COMPARATOR_OFFSET22,
    SYSTICK_HW_COMPARATOR_OFFSET23,
    SYSTICK_HW_COMPARATOR_OFFSET24,
    SYSTICK_HW_COMPARATOR_OFFSET25,
    SYSTICK_HW_COMPARATOR_OFFSET26,
    SYSTICK_HW_COMPARATOR_OFFSET27,
    SYSTICK_HW_COMPARATOR_OFFSET28,
    SYSTICK_HW_COMPARATOR_OFFSET29,
    SYSTICK_HW_COMPARATOR_OFFSET30,
    SYSTICK_HW_COMPARATOR_OFFSET31,
} Systick_Hw_ComparatorOffset_t;

typedef enum
{
    SYSTICK_HW_COMPARATOR_SIZE_1BIT,
    SYSTICK_HW_COMPARATOR_SIZE_2BITS,
    SYSTICK_HW_COMPARATOR_SIZE_3BITS,
    SYSTICK_HW_COMPARATOR_SIZE_4BITS,
    SYSTICK_HW_COMPARATOR_SIZE_5BITS,
    SYSTICK_HW_COMPARATOR_SIZE_6BITS,
    SYSTICK_HW_COMPARATOR_SIZE_7BITS,
    SYSTICK_HW_COMPARATOR_SIZE_8BITS,
    SYSTICK_HW_COMPARATOR_SIZE_9BITS,
    SYSTICK_HW_COMPARATOR_SIZE_10BITS,
    SYSTICK_HW_COMPARATOR_SIZE_11BITS,
    SYSTICK_HW_COMPARATOR_SIZE_12BITS,
    SYSTICK_HW_COMPARATOR_SIZE_13BITS,
    SYSTICK_HW_COMPARATOR_SIZE_14BITS,
    SYSTICK_HW_COMPARATOR_SIZE_15BITS,
    SYSTICK_HW_COMPARATOR_SIZE_16BITS,
    SYSTICK_HW_COMPARATOR_SIZE_17BITS,
    SYSTICK_HW_COMPARATOR_SIZE_18BITS,
    SYSTICK_HW_COMPARATOR_SIZE_19BITS,
    SYSTICK_HW_COMPARATOR_SIZE_20BITS,
    SYSTICK_HW_COMPARATOR_SIZE_21BITS,
    SYSTICK_HW_COMPARATOR_SIZE_22BITS,
    SYSTICK_HW_COMPARATOR_SIZE_23BITS,
    SYSTICK_HW_COMPARATOR_SIZE_24BITS,
    SYSTICK_HW_COMPARATOR_SIZE_25BITS,
    SYSTICK_HW_COMPARATOR_SIZE_26BITS,
    SYSTICK_HW_COMPARATOR_SIZE_27BITS,
    SYSTICK_HW_COMPARATOR_SIZE_28BITS,
    SYSTICK_HW_COMPARATOR_SIZE_29BITS,
    SYSTICK_HW_COMPARATOR_SIZE_30BITS,
    SYSTICK_HW_COMPARATOR_SIZE_31BITS,
    SYSTICK_HW_COMPARATOR_SIZE_32BITS,
} Systick_Hw_ComparatorSize_t;

typedef struct
{
    Systick_Hw_Comparator_t          Comparator;
    Systick_Hw_ComparatorInterrupt_t ComparatorInterrupt;
    Systick_Hw_ComparatorOffset_t    ComparatorOffset;
    Systick_Hw_ComparatorSize_t      ComparatorSize;
    uint32_t                         Ticks;
    bool                             EnableInterrupt;
} Systick_CompareConfig_t;

typedef struct
{
    bool     OverflowEnable;
    bool     OverflowIntrEnable;
    uint32_t OVH;
    uint32_t OVL;
} Systick_OverflowConfig_t;

typedef enum
{
    SYSTICK_HW_INTERRUPT_LINE_0,
    SYSTICK_HW_INTERRUPT_LINE_1,
} Systick_Hw_ServiceInterruptLineType;

/******************************************************************************
 **                      Public Functions
 ******************************************************************************/
void Systick_Hw_DisableModule(Systick_RegisterMap_t *const Module);
void Systick_Hw_EnableModule(Systick_RegisterMap_t *const Module);
void Systick_Hw_DisableSleepMode(Systick_RegisterMap_t *const Module);
void Systick_Hw_EnableSleepMode(Systick_RegisterMap_t *const Module);
bool Systick_Hw_EnableSuspend(Systick_RegisterMap_t *const Module);
bool Systick_Hw_DisableSuspend(Systick_RegisterMap_t *const Module);
bool Systick_Hw_InitCompare(Systick_RegisterMap_t *const Module, const Systick_CompareConfig_t *Config);
void Systick_Hw_ResetModule(Systick_RegisterMap_t *const Module);
void Systick_Hw_Cmp0DelayUs(uint32_t UsTime);
void Systick_Hw_Cmp0DelayMs(uint32_t MsTime);
void Systick_Hw_Cmp1DelayUs(uint32_t UsTime);
void Systick_Hw_Cmp1DelayMs(uint32_t MsTime);
void Systick_Hw_InitOverflow(Systick_RegisterMap_t *const Module, const Systick_OverflowConfig_t *Config);
bool Systick_Hw_IntrRequestNodeInit(
  Systick_RegisterMap_t *const Module, const uint32_t Priority, const Int_SourceType_t TypeOfService,
  const Systick_Hw_ServiceInterruptLineType Line, const bool EnableState);
void Systick_Hw_UpdateCompare(Systick_RegisterMap_t *const Module, Systick_Hw_Comparator_t Comparator, uint32_t Ticks);

#ifdef __cplusplus
}
#endif

#endif

/* EOF */
