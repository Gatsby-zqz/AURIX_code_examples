/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf_circularbuffer.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-06-25
 *  @Version         : V0.0.1.230625_alpha
 *  @Description     : This document describes the C language document template
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyrght protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2024-1-15    |V1.0    |Zhang Quanzhen  | New
 *****************************************************************************/
#ifndef KF_CIRCULARBUFFER_H
#define KF_CIRCULARBUFFER_H

#ifdef __cplusplus
extern "C" {
#endif
#ifndef FREERTOS_TEST
/******************************************************************************
 **                      MISRA-C Rules Violations
 ******************************************************************************/

/******************************************************************************
 **                      QAC Warnings
 ******************************************************************************/

/******************************************************************************
 **                      Include Files
 ******************************************************************************/
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>
//---------------------------------------------------------------------------
/** Circular buffer definition. */
typedef struct
{
    void    *Base;
    uint16_t Index;
    uint16_t Length;
} KF_CircularBuffer;

uint16_t KF_CircularBuffer_Get16(KF_CircularBuffer *buffer);

uint32_t KF_CircularBuffer_Get32(KF_CircularBuffer *buffer);

uint8_t *KF_CircularBuffer_Read8(KF_CircularBuffer *buffer, void *data, uint32_t count);

uint32_t *KF_CircularBuffer_Read32(KF_CircularBuffer *buffer, void *data, uint32_t count);

const uint8_t *KF_CircularBuffer_Write8(KF_CircularBuffer *buffer, const void *data, uint32_t count);

const uint32_t *KF_CircularBuffer_Write32(KF_CircularBuffer *buffer, const void *data, uint32_t count);

#endif /* FREERTOS_TEST */

#ifdef __cplusplus
}
#endif

#endif
