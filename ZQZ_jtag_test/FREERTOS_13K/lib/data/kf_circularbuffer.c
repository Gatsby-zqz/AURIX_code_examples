/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf_circularbuffer.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2024-1-10
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
 *  |2024-1-15    |V1.0    |Zhang Quanzhen     | New
 *****************************************************************************/

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
#ifndef FREERTOS_TEST
#include "kf_circularbuffer.h"

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
uint32_t KF_CircularBuffer_Get32(KF_CircularBuffer *buffer)
{
    uint32_t data = ((uint32_t *)buffer->Base)[buffer->Index];
    buffer->Index += 4;
    if (buffer->Index >= buffer->Length)
    {
        buffer->Index = 0;
    }
    return data;
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
uint16_t KF_CircularBuffer_Get16(KF_CircularBuffer *buffer)
{
    uint16_t data = ((uint16_t *)buffer->Base)[buffer->Index];
    buffer->Index += 2;
    if (buffer->Index >= buffer->Length)
    {
        buffer->Index = 0;
    }
    return data;
}

/**
 * @brief Add a 32 bit value to the circular buffer, and post-increment the circular buffer pointer
 *
 *
 * @param uint32_t
 * @retval void
 */
void KF_CircularBuffer_AddDataIncr(KF_CircularBuffer *buffer, uint32_t data)
{
    ((uint32_t *)buffer->Base)[buffer->Index] = data;
    buffer->Index += 4;
    if (buffer->Index >= buffer->Length)
    {
        buffer->Index = 0;
    }
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
uint8_t *KF_CircularBuffer_Read8(KF_CircularBuffer *buffer, void *data, uint32_t count)
{
    uint8_t *Dest = (uint8_t *)data;
    do
    {
        count--;
        *Dest = ((uint8_t *)buffer->Base)[buffer->Index];
        Dest  = &Dest[1];
        buffer->Index++;
        if (buffer->Index >= buffer->Length)
        {
            buffer->Index = 0;
        }
    } while (count > 0);
    return Dest;
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
uint32_t *KF_CircularBuffer_Read32(KF_CircularBuffer *buffer, void *data, uint32_t count)
{
    uint32_t *Dest = (uint32_t *)data;
    uint8_t  *base = buffer->Base;
    do
    {
        *Dest         = *((uint32_t *)(&base[buffer->Index]));
        Dest          = &Dest[1];
        buffer->Index = buffer->Index + 4;
        if (buffer->Index >= buffer->Length)
        {
            buffer->Index = 0;
        }
        count--;
    } while (count > 0);
    return Dest;
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
const uint8_t *KF_CircularBuffer_Write8(KF_CircularBuffer *buffer, const void *data, uint32_t count)
{
    const uint8_t *source = (const uint8_t *)data;
    do
    {
        count--;
        ((uint8_t *)buffer->Base)[buffer->Index] = *source;
        source                                   = &source[1];
        buffer->Index++;
        if (buffer->Index >= buffer->Length)
        {
            buffer->Index = 0;
        }
    } while (count > 0);
    return source;
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
const uint32_t *KF_CircularBuffer_Write32(KF_CircularBuffer *buffer, const void *data, uint32_t count)
{
    const uint32_t *source = (const uint32_t *)data;
    uint8_t        *base   = buffer->Base;
    do
    {
        *((uint32_t *)(&base[buffer->Index])) = *source;
        source                                = &source[1];
        buffer->Index                         = buffer->Index + 4;
        if (buffer->Index >= buffer->Length)
        {
            buffer->Index = 0;
        }
        count--;
    } while (count > 0);
    return source;
}
#endif /* FREERTOS_TEST */
#ifdef __cplusplus
}
#endif

/* EOF */
