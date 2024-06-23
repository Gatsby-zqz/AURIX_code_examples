/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf_fifo.h
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
#ifndef KF_FIFO_H
#define KF_FIFO_H

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

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                      Typedef  Definitions
 ******************************************************************************/

/** Shared data of the FIFO
 *
 */
typedef struct
{
    int32_t Count;       /**< \brief number of bytes contained in the buffer */
    int32_t ReaderWaitx; /**< \brief Number of bytes that the reader is waiting for. When the writer modify it to 0
                               the  reader get signaled */
    int32_t WriterWaitx; /**< \brief Number of byte that the writer expect to be free. When the reader modify it to
                               0  the reader get signaled */
    uint32_t MaxCount;   /**< \brief Highest value seen in the count */
} FifoSharedType_t;

/** \addtogroup KFLld_lib_datahandling_fifo
 * \{ */
/** Fifo object
 *
 */
typedef struct _Fifo
{
    void            *Buffer;      /**< \brief aligned on 64 bit boundary */
    FifoSharedType_t Shared;      /**< \brief  data shared between reader / writer */
    uint32_t         StartIndex;  /**< \brief buffer valid data start index */
    uint32_t         EndIndex;    /**< \brief buffer valid data end index */
    uint32_t         Size;        /**< \brief multiple of 8 bit, max 0xFFF8 */
    uint32_t         ElementSize; /**< \brief minimum number of bytes (block) added / removed to / from the buffer */
    volatile bool    EventReader; /**< \brief event set by the writer to signal the reader that the required data are
                                      available in the buffer */
    volatile bool EventWriter;    /**< \brief event set by the reader to signal the writer that the required free space
                                       are available in the buffer */
} FifoType_t;

/** \brief Indicates if the required number of bytes are available in the buffer
 *
 * Should not be called from an interrupt as this function may wait forever
 * \param fifo Pointer on the Fifo object
 * \param count in bytes
 * \param Timeout in system timer ticks
 *
 * \return true if at least count bytes can be read from the buffer, else
 * the Event is armed to be set when the buffer count is bigger or equal to the requested count
 */
bool Kf_FifoCanReadCount(FifoType_t *FifoPtr, uint32_t Count, int64_t Timeout);
/** \brief  Indicates if there is enough free space to write the data in the buffer
 *
 * Should not be called from an interrupt as this function may wait forever
 *
 * \param fifo Pointer on the Fifo object
 * \param count in bytes
 * \param Timeout in system timer ticks
 *
 * \return true if at least count bytes can be written to the buffer,
 * if not the Event is armed to be set when the buffer free count is bigger or equal to the requested count
 */
bool Kf_FifoCanWriteCount(FifoType_t *FifoPtr, uint32_t Count, int64_t Timeout);

/** \brief Clear fifo contents.
 *
 * \param fifo Pointer on the Fifo object
 *
 * \return void
 */
void Kf_FifoClear(FifoType_t *FifoPtr);

/** \brief Create a Fifo object
 *
 * The memory required for the object is allocated dynamically.
 *
 * \param size Specifies the FIFO buffer size in bytes
 * \param elementSize Specifies data element size in bytes. size must be bigger or equal to elemenntSize.
 *
 * \return returns a pointer to the FIFO object
 *
 * \see Kf_FifoDestroy()
 */
FifoType_t *Kf_FifoCeate(int16_t Size, uint32_t ElementSize);

/** \brief Destroy the FIFO object
 *
 * This function must be called to destroy the fifo object when created with \ref Kf_FifoCeate()
 *
 * \param fifo Pointer on the Fifo object
 * \return void
 *
 * \see   Kf_FifoCeate()
 */
void Kf_FifoDestroy(FifoType_t *FifoPtr);

/** \brief Initialize the FIFO buffer object
 *
 * \param buffer Specifies the FIFO object address.
 * \param size Specifies the FIFO buffer size in bytes
 * \param elementSize Specifies data element size in bytes. size must be bigger or equal to elemenntSize.
 *
 * \return Returns a pointer on the FIFO object
 *
 * \note: The buffer parameter must point on a free memory location where the
 * buffer object will be initialised. The size of this area must be at least
 * equals to "size + sizeof(FifoType_t) + 8". Not taking this in account may result
 * in unpredictable behavior.
 */
FifoType_t *Kf_FifoInit(void *BufferPtr, int16_t Size, int16_t ElementSize);

/** \brief Read data from a fifo and remove them from the buffer.
 *
 * Only complete elements are returned, if count is not a multiple of
 * elementSize then the incomplete element is not read/removed from the buffer.
 *
 * \param fifo Pointer on the Fifo object
 * \param data Pointer to the data buffer for storing values
 * \param count in bytes
 * \param Timeout in system timer ticks
 *
 * \return return the number of byte that could not be read
 */
uint32_t Kf_FifoRead(FifoType_t *FifoPtr, void *DataPtr, uint32_t Count, int64_t Timeout);

/** \brief Write data into a fifo.
 *
 * Only complete elements are written to the buffer, if count is not a multiple of
 * elementSize then the incomplete element are not written to the buffer.
 *
 * \param fifo Pointer on the Fifo object
 * \param data Pointer to the data buffer to write into the Fifo
 * \param count in bytes
 * \param Timeout in system timer ticks
 */
uint32_t Kf_FifoWrite(FifoType_t *FifoPtr, const void *DataPtr, uint32_t Count, int64_t Timeout);

/** \brief Empty the fifo
 *
 * \param fifo Pointer on the Fifo object
 * \param Timeout in system timer ticks
 *
 * \return true if the buffer is emptied.
 */
KF_INLINE bool Kf_Fifoflush(FifoType_t *FifoPtr, int64_t Timeout)
{
    return Kf_FifoCanWriteCount(FifoPtr, FifoPtr->Size, Timeout);
}

/**
 * \brief Returns the size of the data in the buffer in bytes
 *
 * \param fifo Pointer on the Fifo object
 *
 * Note as the Kf_FifoWrite / Kf_FifoRead function does only write blocks which are
 * a multiple of fifo->ElementSize, the Kf_FifoReadCount / Kf_FifoWriteCount return
 * a multiple of fifo->ElementSize
 *
 * \return Returns the size of the data in the buffer in bytes
 */
KF_INLINE uint32_t Kf_FifoReadCount(FifoType_t *FifoPtr)
{
    return FifoPtr->Shared.Count;
}

/** \brief Returns the free size in bytes
 *
 * \param fifo Pointer on the Fifo object
 *
 * Note as the Kf_FifoWrite / Kf_FifoRead function does only write blocks which are
 * a multiple of fifo->ElementSize, the Kf_FifoReadCount / Kf_FifoWriteCount return
 * a multiple of fifo->ElementSize
 *
 * \return Returns the free size in bytes
 */
KF_INLINE uint32_t Kf_FifoWriteCount(FifoType_t *FifoPtr)
{
    return (uint32_t)(FifoPtr->Size - Kf_FifoReadCount(FifoPtr));
}

/** \brief Indicates if the fifo is empty
 *
 * \param fifo Pointer on the FifoType_t object
 *
 * \retval true is the buffer is empty
 * \retval false is the buffer is not empty
 */
KF_INLINE bool Kf_FifoisEmpty(FifoType_t *FifoPtr)
{
    return (Kf_FifoReadCount(FifoPtr) != false) ? false : true;
}

#endif /* FREERTOS_TEST */

#ifdef __cplusplus
}
#endif

#endif
