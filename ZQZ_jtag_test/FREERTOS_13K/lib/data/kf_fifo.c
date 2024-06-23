/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf_fifo.C
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
#include "kf_fifo.h"
#include "kf32a13k_drv_int.h"
#include "kf_circularbuffer.h"
#include "malloc.h"

/******************************************************************************
 *                      Static Function Declarations                         *
 ******************************************************************************/
static uint32_t Kf_FifoBeginRead(FifoType_t *FifoPtr, uint32_t Count);
static uint32_t Kf_FifoBeginWrite(FifoType_t *FifoPtr, uint32_t Count);
static uint32_t Kf_FifoReadEnd(FifoType_t *FifoPtr, uint32_t Count, uint32_t blockSize);
static uint32_t Kf_FifoEndWrite(FifoType_t *FifoPtr, uint32_t Count, uint32_t blockSize);

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
static uint32_t Kf_FifoBeginRead(FifoType_t *FifoPtr, uint32_t Count)
{
    bool     interruptState;
    uint32_t blockSize;
    interruptState = Intr_LL_EnterCritical();
    blockSize      = KF_MIN(Count, Kf_FifoReadCount(FifoPtr));
    blockSize -= blockSize % FifoPtr->ElementSize;
    FifoPtr->EventReader        = false;
    FifoPtr->Shared.ReaderWaitx = KF_MIN(Count - blockSize, FifoPtr->Size);
    Intr_LL_ExitCritical(interruptState);
    return blockSize;
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
static uint32_t Kf_FifoBeginWrite(FifoType_t *FifoPtr, uint32_t Count)
{
    uint32_t blockSize;
    bool     interruptState;
    interruptState = Intr_LL_EnterCritical();
    blockSize      = KF_MIN(Count, FifoPtr->Size - Kf_FifoReadCount(FifoPtr));
    blockSize -= blockSize % FifoPtr->ElementSize;
    FifoPtr->EventWriter        = false;
    FifoPtr->Shared.WriterWaitx = KF_MIN(Count - blockSize, FifoPtr->Size);
    Intr_LL_ExitCritical(interruptState);
    return blockSize;
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
static uint32_t Kf_FifoReadEnd(FifoType_t *FifoPtr, uint32_t Count, uint32_t blockSize)
{
    bool interruptState;
    /* Set the shared values */
    interruptState = Intr_LL_EnterCritical();
    FifoPtr->Shared.Count -= blockSize;
    if (FifoPtr->Shared.WriterWaitx != 0)
    {
        FifoPtr->Shared.WriterWaitx -= blockSize;
        if (FifoPtr->Shared.WriterWaitx <= 0)
        {
            FifoPtr->Shared.WriterWaitx = 0;
            FifoPtr->EventWriter        = true; /* Signal the writer */
        }
    }
    Intr_LL_ExitCritical(interruptState);
    return (Count - blockSize);
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
static uint32_t Kf_FifoEndWrite(FifoType_t *FifoPtr, uint32_t Count, uint32_t blockSize)
{
    bool interruptState;
    /* Set the shared values */
    interruptState = Intr_LL_EnterCritical();
    FifoPtr->Shared.Count += blockSize;
    FifoPtr->Shared.MaxCount = KF_MAX(FifoPtr->Shared.MaxCount, FifoPtr->Shared.Count); /* Update maximum value */
    if (FifoPtr->Shared.ReaderWaitx != 0)
    {
        FifoPtr->Shared.ReaderWaitx -= blockSize;
        if (FifoPtr->Shared.ReaderWaitx <= 0)
        {
            FifoPtr->Shared.ReaderWaitx = 0;
            FifoPtr->EventReader        = true; /* Signal the reader - a re-scheduling may occur at this point! */
        }
    }
    Intr_LL_ExitCritical(interruptState);
    return (Count - blockSize);
}

/******************************************************************************
 *                      Global Function Declarations                           *
 ******************************************************************************/

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
FifoType_t *Kf_FifoCeate(int16_t Size, uint32_t ElementSize)
{
    FifoType_t *fifo = NULL_PTR;
    Size             = KF_ALIGN_ON32(Size);       /* data transfer is optimised for 32 bit access */
    fifo = malloc(Size + sizeof(FifoType_t) + 8); /* +8 because of padding in case the pointer is not aligned on 64 */
    if (fifo != NULL_PTR)
    {
        fifo = Kf_FifoInit(fifo, Size, ElementSize);
    }

    return fifo;
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
void Kf_FifoDestroy(FifoType_t *FifoPtr)
{
    free(FifoPtr);
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
FifoType_t *Kf_FifoInit(void *BufferPtr, int16_t Size, int16_t ElementSize)
{
    FifoType_t *fifo = NULL_PTR;
    Size             = KF_ALIGN_ON32(Size); /* data transfer is optimised for 32 bit access */
    /* Check size over maximum FIFO size */
    {
        fifo              = (FifoType_t *)BufferPtr;
        fifo->EventReader = false;
        fifo->EventWriter = true;
#ifdef SIMULATION
        fifo->Buffer = (uint8_t *)KF_ALIGN_ON64(((uint64_t)fifo) + sizeof(FifoType_t));
#else
        fifo->Buffer = (uint8_t *)KF_ALIGN_ON64(((uint32_t)fifo) + sizeof(FifoType_t));
#endif
        fifo->Shared.Count       = 0;
        fifo->Shared.MaxCount    = 0;
        fifo->Shared.ReaderWaitx = fifo->Shared.WriterWaitx = 0;
        fifo->StartIndex = fifo->EndIndex = 0;
        fifo->Size                        = Size;
        fifo->ElementSize                 = ElementSize;
    }
    return fifo;
}

// TODO:增加获取当前时钟API,增加硬件计时机制
/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
bool Kf_FifoCanReadCount(FifoType_t *FifoPtr, uint32_t Count, int64_t Timeout)
{
    bool result;
    if ((Count < FifoPtr->ElementSize) || (Count > FifoPtr->Size))
    { /* Only complete elements can be read from the buffer */
        result = false;
    }
    else
    {
        bool    interruptState;
        int32_t waitCount;
        interruptState = Intr_LL_EnterCritical();
        waitCount      = Count - Kf_FifoReadCount(FifoPtr);
        if (waitCount <= 0)
        {
            FifoPtr->Shared.ReaderWaitx = 0;
            FifoPtr->EventReader        = true;
            Intr_LL_ExitCritical(interruptState);
            result = true;
        }
        else
        {
            // TODO:add timeout count api
            int64_t DeadLine            = Kf_GetDeadLine(Timeout);
            FifoPtr->EventReader        = false;
            FifoPtr->Shared.ReaderWaitx = waitCount;
            Intr_LL_ExitCritical(interruptState);
            while ((FifoPtr->EventReader == false) && (Kf_IsDeadLine(DeadLine) == false))
                ;
            /* After the timeout, the reader is not waiting for any data */
            FifoPtr->Shared.ReaderWaitx = 0;
            result                      = FifoPtr->EventReader == true;
        }
    }

    return result;
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
uint32_t Kf_FifoRead(FifoType_t *FifoPtr, void *DataPtr, uint32_t Count, int64_t Timeout)
{
    int64_t           DeadLine;
    uint32_t          blockSize;
    KF_CircularBuffer buffer;
    bool              Stop = false;
    if (Count != 0)
    {
        buffer.Base   = FifoPtr->Buffer;
        buffer.Length = (uint16_t)FifoPtr->Size;       /* size always fit into 16 bit */
        buffer.Index  = (uint16_t)FifoPtr->StartIndex; /* startIndex always fit into size */
        // TODO:add timeout count api
        DeadLine = Kf_GetDeadLine(Timeout);
        do
        {
            blockSize = Kf_FifoBeginRead(FifoPtr, Count);
            if (blockSize != 0)
            {
                /* read element from the buffer */
                DataPtr = KF_CircularBuffer_Read8(&buffer, DataPtr, blockSize);
                Count   = Kf_FifoReadEnd(FifoPtr, Count, blockSize);
            }
            if ((Stop != false) || (Kf_IsDeadLine(DeadLine) != false))
            {
                /*When exiting, the reader is not waiting for any data */
                FifoPtr->Shared.ReaderWaitx = 0;
                break;
            }
            if (Count != 0)
            {
                while ((FifoPtr->EventReader == false) && (Kf_IsDeadLine(DeadLine) == false))
                    ;
                /* If the function timeout, the maximum number of characters are read before returning */
                Stop = (FifoPtr->EventReader == false);
            }
        } while (Count != 0);
        FifoPtr->StartIndex = buffer.Index;
    }
    return Count;
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
void Kf_FifoClear(FifoType_t *FifoPtr)
{
    bool interruptState;
    interruptState = Intr_LL_EnterCritical();
    if (FifoPtr->Shared.WriterWaitx != 0)
    {
        FifoPtr->Shared.WriterWaitx = 0;
        FifoPtr->EventWriter        = true; /* Signal the writer */
    }
    FifoPtr->EventReader        = false;
    FifoPtr->Shared.ReaderWaitx = 0;
    FifoPtr->Shared.Count       = 0;
    FifoPtr->Shared.MaxCount    = 0;
    FifoPtr->StartIndex         = FifoPtr->EndIndex;
    Intr_LL_ExitCritical(interruptState);
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval void
 */
bool Kf_FifoCanWriteCount(FifoType_t *FifoPtr, uint32_t Count, int64_t Timeout)
{
    bool result;
    if ((Count < FifoPtr->ElementSize) || (Count > FifoPtr->Size))
    { /* Only complete elements can be written to the buffer */
        result = false;
    }
    else
    {
        bool interruptState;
        interruptState = Intr_LL_EnterCritical();
        if ((FifoPtr->Size - Kf_FifoReadCount(FifoPtr)) >= Count)
        {
            FifoPtr->Shared.WriterWaitx = 0;
            FifoPtr->EventWriter        = true;
            Intr_LL_ExitCritical(interruptState);
            result = true;
        }
        else
        {
            // TODO:add timeout count api
            int64_t DeadLine            = Kf_GetDeadLine(Timeout);
            FifoPtr->EventWriter        = false;
            FifoPtr->Shared.WriterWaitx = KF_MAX(0, Count - (FifoPtr->Size - Kf_FifoReadCount(FifoPtr)));
            Intr_LL_ExitCritical(interruptState);
            while ((FifoPtr->EventWriter == false) && (Kf_IsDeadLine(DeadLine) == false))
                ;
            /* After the timeout, the writer is not waiting for any space */
            FifoPtr->Shared.WriterWaitx = 0;
            result                      = FifoPtr->EventWriter == true;
        }
    }
    return result;
}

/**
 * @brief
 *
 *
 * @param uint32_t
 * @retval uint32_t
 */
uint32_t Kf_FifoWrite(FifoType_t *FifoPtr, const void *DataPtr, uint32_t Count, int64_t Timeout)
{
    int64_t           DeadLine;
    uint32_t          blockSize;
    KF_CircularBuffer buffer;
    bool              Stop = false;
    if (Count != 0)
    {
        buffer.Base   = FifoPtr->Buffer;
        buffer.Length = (uint16_t)FifoPtr->Size;     /* size always fit into 16 bit */
        buffer.Index  = (uint16_t)FifoPtr->EndIndex; /* startIndex always fit into size */
        // TODO:add timeout count api
        DeadLine = Kf_GetDeadLine(Timeout);
        do
        {
            blockSize = Kf_FifoBeginWrite(FifoPtr, Count);
            if (blockSize != 0)
            {
                /* write element to the buffer */
                DataPtr = KF_CircularBuffer_Write8(&buffer, DataPtr, blockSize);
                Count   = Kf_FifoEndWrite(FifoPtr, Count, blockSize);
            }
            if ((Stop != false) || (Kf_IsDeadLine(DeadLine) != false))
            {
                /*When exiting, the writer is not waiting for any space */
                FifoPtr->Shared.WriterWaitx = 0;
                break;
            }
            if (Count != 0)
            {
                while ((FifoPtr->EventWriter == false) && (Kf_IsDeadLine(DeadLine) == false))
                    ;
                /* If the function timeout, the maximum number of characters are written before returning */
                Stop = (FifoPtr->EventWriter == false);
            }
        } while (Count != 0);
        FifoPtr->EndIndex = buffer.Index;
    }
    return Count;
}
#endif /* FREERTOS_TEST */
#ifdef __cplusplus
}
#endif

/* EOF */
