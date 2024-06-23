/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_canfd.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-5-14
 *  @Version         : V0.0.1.231212_alpha
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
 *  |2023-5-14    |V1.0     |Zhang Quanzhen | New Creat
 *****************************************************************************/

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_drv_canfd.h"
/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
#define SwapBytesInWordIndex(index) (((index) & ~3U) + (3U - ((index) & 3U)))
#define RxFifoFilterElementNum(x)   (((x) + 1U) * 8U)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Local Variables
 ******************************************************************************/
/* maximum threshold values for DLC*/
static const uint8_t kvFd_MaxDataLength[8] = {
  CANFD_MAX_DLC8_U8,  CANFD_MAX_DLC9_U8,  CANFD_MAX_DLC10_U8, CANFD_MAX_DLC11_U8,
  CANFD_MAX_DLC12_U8, CANFD_MAX_DLC13_U8, CANFD_MAX_DLC14_U8, CANFD_MAX_DLC15_U8};

/* PRQA S 3211 7 # The global identifier '%1s' is defined here but is not used in this translation unit. */
/* PRQA S 1533 6 # The object '%1s' is only referenced by function '%2s'. */
/*minimum threshold values for DLC*/
static const uint8_t kvFd_MinDataLength[8] = {
  CANFD_MIN_DLC8_U8,  CANFD_MIN_DLC9_U8,  CANFD_MIN_DLC10_U8, CANFD_MIN_DLC11_U8,
  CANFD_MIN_DLC12_U8, CANFD_MIN_DLC13_U8, CANFD_MIN_DLC14_U8, CANFD_MIN_DLC15_U8};

/*maximum threshold values for Payload*/
static const uint8_t kvCanfd_MaxPayLoad[4] = {
  CANFD_MAX_PAYLOAD8_U8, CANFD_MAX_PAYLOAD16_U8, CANFD_MAX_PAYLOAD32_U8, CANFD_MAX_PAYLOAD64_U8};

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
static void Canfd_LL_ClearRam(CanfdPtr Module);
static void Canfd_LL_FormatPaddingValue(const uint32_t MsgId, bool FdEnable, uint8_t *SduDataPtr, uint8_t *SduLenPtr,
                                        uint8_t *RealDlc, const uint8_t PaddingValue);
static inline void Canfd_LL_SetPNFilter(
  CanfdPtr Module, bool WakeUpTimeout, bool WakeUpMatch, uint16_t NumMatches, Canfd_PnCombinationFilter_t FilterComb,
  Canfd_PnFilterSeletion_t IdFilterType, Canfd_PnFilterSeletion_t PayloadFilterType);

/**
 * @brief clear canfd corresponding ram areas
 * @param Module
 * @retval void
 */
static void Canfd_LL_ClearRam(CanfdPtr Module){};

/**
 * @brief 按照邮箱格式调整输入参数
 * @param MsgId
 * @param FdEnable
 * @param SduDataPtr
 * @param SduLenPtr
 * @param RealDlc
 * @param PaddingValue
 * @retval void
 */
static void Canfd_LL_FormatPaddingValue(const uint32_t MsgId, bool FdEnable, uint8_t *SduDataPtr, uint8_t *SduLenPtr,
                                        uint8_t *RealDlc, const uint8_t PaddingValue)
{
    uint8_t dataLengthCount        = 0U;
    uint8_t paddingDataLengthCount = 0U;
    if (true == FdEnable)
    {
        /* FD Frame */
        if ((*SduLenPtr) <= (uint8_t)kvFd_MaxDataLength[0])
        {
            (*RealDlc) = (*SduLenPtr);
        }
        else
        {
            for (dataLengthCount = 1U; dataLengthCount < 8U; dataLengthCount++)
            {
                if (((*SduLenPtr) <= (uint8_t)kvFd_MaxDataLength[dataLengthCount]) &&
                    ((*SduLenPtr) >= (uint8_t)kvFd_MinDataLength[dataLengthCount]))
                {
                    (*RealDlc) = dataLengthCount + 8U;
                    for (paddingDataLengthCount = (*SduLenPtr);
                         paddingDataLengthCount < kvFd_MaxDataLength[dataLengthCount]; paddingDataLengthCount++)
                    {
                        if (NULL_PTR != SduDataPtr)
                        {
                            SduDataPtr[paddingDataLengthCount] = PaddingValue;
                        }
                    }
                    (*SduLenPtr) = kvFd_MaxDataLength[dataLengthCount];
                    break;
                }
                else
                {
                    /* deliberately left blank to avoid QAC violation * (Rule 2000 ) */
                }
            }
        }
    }
    else
    {
        (*SduLenPtr) = (*SduLenPtr > 8U) ? (8U) : (*SduLenPtr);
        (*RealDlc)   = (*SduLenPtr);
    }
}

/**
 * @brief 设置Pretended Networking滤波器
 * @param Module
 * @param WakeUpTimeout
 * @param WakeUpMatch
 * @param NumMatches
 * @param filterComb
 * @param idFilterType
 * @param payloadFilterType
 * @retval void
 */
static inline void Canfd_LL_SetPNFilter(
  CanfdPtr Module, bool WakeUpTimeout, bool WakeUpMatch, uint16_t NumMatches, Canfd_PnCombinationFilter_t FilterComb,
  Canfd_PnFilterSeletion_t IdFilterType, Canfd_PnFilterSeletion_t PayloadFilterType)
{
    Canfd_LL_SetWkupTimeoutMask(Module, WakeUpTimeout);
    Canfd_LL_SetWkupMatchMask(Module, WakeUpMatch);
    Canfd_LL_SetWkupMatchNumber(Module, NumMatches);
    Canfd_LL_SetFilterComb(Module, FilterComb);
    Canfd_LL_SetIdFilterSelection(Module, IdFilterType);
    Canfd_LL_SetPayloadFilterSelection(Module, PayloadFilterType);
}

/**
 * @brief get max mailbox number from payload configuration
 * @param PayloadSize
 * @retval void
 */
uint8_t Canfd_LL_GetMaliboxNumber(const Canfd_PayloadSize_t PayloadSize)
{
    return (kvCanfd_MaxPayLoad[(uint8_t)PayloadSize]);
}

/**
 * @brief 获取执行DLC负载长度
 * @param Dlc
 * @param PayLoadLength
 * @retval void
 */
uint8_t Canfd_LL_GetDataLength(const uint8_t Dlc)
{
    return ((uint8_t)(Dlc > 8U ? kvFd_MaxDataLength[(uint8_t)Dlc - 8U] : Dlc));
}

/**
 *
 * @brief 按字节取反字
 * @param DesPtr
 * @param SouPtr
 * @retval void
 */
void Canfd_LL_SwapBytesInWord(volatile void *DesPtr, volatile void *SouPtr)
{
    volatile uint8_t *sou8Ptr = (uint8_t *)(SouPtr);
    volatile uint8_t *des8Ptr = (uint8_t *)(DesPtr);
    CANFD_WRITE8(des8Ptr, *(sou8Ptr + 3U));
    CANFD_WRITE8(des8Ptr + 1U, *(sou8Ptr + 2U));
    CANFD_WRITE8(des8Ptr + 2U, *(sou8Ptr + 1U));
    CANFD_WRITE8(des8Ptr + 3U, *(sou8Ptr));
}

/**
 * @brief 进入Freeze 模式
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
void Canfd_LL_EnterFreezeMode(CanfdPtr Module)
{
    KF_CANFD_ASSERT(CHECK_CANFD_ALL_PERIPH_ADDR(Module));
    bool enabled = false;
    Canfd_LL_SetHaltEnabled(Module, true);
    Canfd_LL_SetFreezeEnabled(Module, true);
    if (false == Canfd_LL_IsDisEnabled(Module))
    {
        enabled = true;
    }
    else
    {
        Canfd_LL_SetModuleDisabled(Module, false);
    }
    while (false == Canfd_LL_GetFreezeAck(Module))
        ;
    if (false == enabled)
    {
        Canfd_LL_SetModuleDisabled(Module, true);
        while (false == Canfd_LL_GetLowPowerModeAck(Module))
            ;
    }
}

/**
 * @brief 退出Freeze 模式
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
void Canfd_LL_ExitFreezeMode(CanfdPtr Module)
{
    Canfd_LL_SetFreezeEnabled(Module, false);
    Canfd_LL_SetHaltEnabled(Module, false);
    /* Wait till exit freeze mode */
    while (true == Canfd_LL_GetFreezeAck(Module))
        ;
}

/**
 * @brief 禁止模块
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
void Canfd_LL_Disable(CanfdPtr Module)
{
    if (false == Canfd_LL_IsDisEnabled(Module))
    {
        /* Clock disable (module) */
        Canfd_LL_SetModuleDisabled(Module, true);
        /* Wait until disable mode acknowledged */
        while (false == Canfd_LL_GetLowPowerModeAck(Module))
            ;
    }
}

/**
 * @brief 使能模块
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
void Canfd_LL_Enable(CanfdPtr Module)
{
    if (true == Canfd_LL_GetLowPowerModeAck(Module))
    {
        Canfd_LL_SetModuleDisabled(Module, false);
        Canfd_LL_SetFreezeEnabled(Module, false);
        Canfd_LL_SetHaltEnabled(Module, false);
    }
}

/*!
 * @brief 设置 邮箱负载尺寸
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] PayloadSize
 *            CANFD_PAYLOAD_SIZE_8
 *            CANFD_PAYLOAD_SIZE_16
 *            CANFD_PAYLOAD_SIZE_32
 *            CANFD_PAYLOAD_SIZE_64
 * @return void
 */
void Canfd_LL_SetPayloadSize(CanfdPtr Module, const Canfd_PayloadSize_t PayloadSize)
{
    if (true == Canfd_LL_IsFDEnabled(Module))
    {
        Canfd_LL_SetR0PayLoadSize(Module, PayloadSize);
        Canfd_LL_SetR1PayLoadSize(Module, PayloadSize);
        Canfd_LL_SetR2PayLoadSize(Module, PayloadSize);
        Canfd_LL_SetR3PayLoadSize(Module, PayloadSize);
    }
}

/*!
 * @brief 获取 邮箱负载尺寸
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint32_t
 */
uint32_t Canfd_LL_GetPayloadSize(CanfdPtr Module)
{
    uint32_t payloadSize;
    if (false == Canfd_LL_IsFDEnabled(Module))
    {
        payloadSize = 8U;
    }
    else
    {
        payloadSize = (1U << (Canfd_LL_GetR0PayLoadSize(Module) + 3U));
    }
    return (payloadSize);
}

/*!
 * @brief 设置 波特率配置参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] TimeSegPtr 波特率配置参数指针
 * @return void
 */
void Canfd_LL_SetTimeSegments(CanfdPtr Module, const Canfd_TimeSegment_t *TimeSegPtr)
{
    Canfd_LL_SetPropSeg(Module, TimeSegPtr->propSeg);
    Canfd_LL_SetPSeg1(Module, TimeSegPtr->phaseSeg1);
    Canfd_LL_SetPSeg2(Module, TimeSegPtr->phaseSeg2);
    Canfd_LL_SetPDivide(Module, TimeSegPtr->preDivider);
    Canfd_LL_SetPRJW(Module, TimeSegPtr->rJumpwidth);
}

/*!
 * @brief 设置 扩展波特率配置参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] TimeSegPtr 波特率配置参数指针
 * @return void
 */
void Canfd_LL_SetExtendedTimeSegments(CanfdPtr Module, const Canfd_TimeSegment_t *TimeSegPtr)
{
    Canfd_LL_SetEPropSeg(Module, TimeSegPtr->propSeg);
    Canfd_LL_SetEPSeg1(Module, TimeSegPtr->phaseSeg1);
    Canfd_LL_SetEPSeg2(Module, TimeSegPtr->phaseSeg2);
    Canfd_LL_SetEPDivide(Module, TimeSegPtr->preDivider);
    Canfd_LL_SetEPRJW(Module, TimeSegPtr->rJumpwidth);
}

/*!
 * @brief 设置 CANFD波特率配置参数
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] TimeSegPtr 波特率配置参数指针
 * @return void
 */
void Canfd_LL_SetFDTimeSegments(CanfdPtr Module, const Canfd_TimeSegment_t *TimeSegPtr)
{
    Canfd_LL_SetFDPropSeg(Module, TimeSegPtr->propSeg);
    Canfd_LL_SetFDPSeg1(Module, TimeSegPtr->phaseSeg1);
    Canfd_LL_SetFDPSeg2(Module, TimeSegPtr->phaseSeg2);
    Canfd_LL_SetFDPDivide(Module, TimeSegPtr->preDivider);
    Canfd_LL_SetFDPRJW(Module, TimeSegPtr->rJumpwidth);
}

/**
 * @brief 获取仲裁段波特率设置参数
 * @param Module
 * @param BitRatePtr
 * @retval void
 */
void Canfd_LL_GetTimeSegments(CanfdPtr Module, Canfd_TimeSegment_t *BitRatePtr)
{
    BitRatePtr->propSeg    = Canfd_LL_GetPropSeg(Module);
    BitRatePtr->phaseSeg1  = Canfd_LL_GetPSeg1(Module);
    BitRatePtr->phaseSeg2  = Canfd_LL_GetPSeg2(Module);
    BitRatePtr->preDivider = Canfd_LL_GetPDivide(Module);
    BitRatePtr->rJumpwidth = Canfd_LL_GetPDivide(Module);
}

/**
 * @brief 获取数据段波特率设置参数
 * @param Module
 * @param BitRatePtr
 * @retval void
 */
void Canfd_LL_GetFDTimeSegments(CanfdPtr Module, Canfd_TimeSegment_t *BitRatePtr)
{
    BitRatePtr->propSeg    = Canfd_LL_GetFDPropSeg(Module);
    BitRatePtr->phaseSeg1  = Canfd_LL_GetFDSeg1(Module);
    BitRatePtr->phaseSeg2  = Canfd_LL_GetFDPSeg2(Module);
    BitRatePtr->preDivider = Canfd_LL_GetFDPDivide(Module);
    BitRatePtr->rJumpwidth = Canfd_LL_GetFDPRJW(Module);
}

/*!
 * @brief 获取 接收独立邮箱数量
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return uint8_t
 */
uint8_t Canfd_LL_GetNoOfIndividualMB(CanfdPtr Module)
{
    /* Get the number of RX FIFO Filters*/
    uint8_t count = Canfd_LL_GetLegacyFifoFilterNum(Module);
    /* Max filters configured by individual mask are (7 + RFFN * 2) depends on the FIFO size,
     * max allowed value is 31 RXIMR */
    count = (uint8_t)(7u + ((uint32_t)count << 1u));
    if (count >= CANFD_MAX_MBNUM)
    {
        count = (uint8_t)(CANFD_MAX_MBNUM - 1u);
    }
    return count;
}

/*!
 * @brief 清除 错误状态标志
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
void Canfd_LL_ClearErrIntStatusFlag(CanfdPtr Module)
{
    if (0U != (Module->CANFD_ESR1.reg & CANFD_ALL_INT))
    {
        Module->CANFD_ESR1.reg = CANFD_ALL_INT;
    }
}

/*!
 * @brief 设置 Pretended Networking 滤波器1ID
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] IdFilter 滤波器1 ID参数
 * @return void
 */
void Canfd_LL_SetPNIdFilter1(CanfdPtr Module, Canfd_PnIdFilter_t IdFilter)
{
    Canfd_LL_SetPNExtendEnabled(Module, IdFilter.extendedId);
    Canfd_LL_SetPNRemoteEnabled(Module, IdFilter.remoteFrame);
    if (IdFilter.extendedId)
    {
        Canfd_LL_SetPNExtendId(Module, IdFilter.id);
    }
    else
    {
        Canfd_LL_SetPNStandId(Module, IdFilter.id);
    }
}

/*!
 * @brief 设置 Pretended Networking 滤波器 IDE和RTR
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @return void
 */
void Canfd_LL_SetPNIdFilter2Check(CanfdPtr Module)
{
    uint32_t temp = 0U;
    temp          = CAN_FLT_ID2_IDMASK_IDE_MSK_MASK | CAN_FLT_ID2_IDMASK_RTR_MSK_MASK;
    temp          = Canfd_LL_GetPNMask(Module) | temp;
    Canfd_LL_SetPNMask(Module, temp);
}

/*!
 * @brief 设置 Pretended Networking 滤波器2ID
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] IdFilter 滤波器2 ID参数
 * @return void
 */
void Canfd_LL_SetPNIdFilter2(CanfdPtr Module, Canfd_PnIdFilter_t IdFilter)
{
    Canfd_LL_SetPNExtendMask(Module, IdFilter.extendedId);
    Canfd_LL_SetPNRemoteMask(Module, IdFilter.remoteFrame);
    if (IdFilter.extendedId)
    {
        Canfd_LL_SetPNExtendIdMask(Module, IdFilter.id);
    }
    else
    {
        Canfd_LL_SetPNStandIdMask(Module, IdFilter.id);
    }
}

/*!
 * @brief 设置 Pretended Networking DLC范围
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] DlcLow DLC下限
 * @param[in] DlcHigh DLC上限
 * @return void
 */
void Canfd_LL_SetPNDlcFilter(CanfdPtr Module, uint8_t DlcLow, uint8_t DlcHigh)
{
    Canfd_LL_SetPNLowDLC(Module, DlcLow);
    Canfd_LL_SetPNHighDLC(Module, DlcHigh);
}

/*!
 * @brief 设置 Pretended Networking 滤波器1 payload上限
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] PayloadPtr Payload数据指针
 * @return void
 */
void Canfd_LL_SetPNPayloadHighFilter1(CanfdPtr Module, const uint8_t *PayloadPtr)
{
    // TODO:后续优化数据结构
    Canfd_LL_SetPNHighPayLoadByte4(Module, PayloadPtr[4]);
    Canfd_LL_SetPNHighPayLoadByte5(Module, PayloadPtr[5]);
    Canfd_LL_SetPNHighPayLoadByte6(Module, PayloadPtr[6]);
    Canfd_LL_SetPNHighPayLoadByte7(Module, PayloadPtr[7]);
}

/*!
 * @brief 设置 Pretended Networking 滤波器1 payload下限
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] PayloadPtr Payload数据指针
 * @return void
 */
void Canfd_LL_SetPNPayloadLowFilter1(CanfdPtr Module, const uint8_t *PayloadPtr)
{
    // TODO:后续优化数据结构
    Canfd_LL_SetPNLowPayLoadByte0(Module, PayloadPtr[0]);
    Canfd_LL_SetPNLowPayLoadByte1(Module, PayloadPtr[1]);
    Canfd_LL_SetPNLowPayLoadByte2(Module, PayloadPtr[2]);
    Canfd_LL_SetPNLowPayLoadByte3(Module, PayloadPtr[3]);
}

/*!
 * @brief 设置 Pretended Networking 滤波器2 payload上限
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] PayloadPtr Payload数据指针
 * @return void
 */
void Canfd_LL_SetPNPayloadHighFilter2(CanfdPtr Module, const uint8_t *PayloadPtr)
{
    // TODO:后续优化数据结构
    Canfd_LL_SetPNHighPayLoadByte4Mask(Module, PayloadPtr[4]);
    Canfd_LL_SetPNHighPayLoadByte5Mask(Module, PayloadPtr[5]);
    Canfd_LL_SetPNHighPayLoadByte6Mask(Module, PayloadPtr[6]);
    Canfd_LL_SetPNHighPayLoadByte7Mask(Module, PayloadPtr[7]);
}

/*!
 * @brief 设置 Pretended Networking 滤波器2 payload下限
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] PayloadPtr Payload下限
 * @return void
 */
void Canfd_LL_SetPNPayloadLowFilter2(CanfdPtr Module, const uint8_t *PayloadPtr)
{
    // TODO:后续优化数据结构
    Canfd_LL_SetPNLowPayLoadByte0Mask(Module, PayloadPtr[0]);
    Canfd_LL_SetPNLowPayLoadByte1Mask(Module, PayloadPtr[1]);
    Canfd_LL_SetPNLowPayLoadByte2Mask(Module, PayloadPtr[2]);
    Canfd_LL_SetPNLowPayLoadByte3Mask(Module, PayloadPtr[3]);
}

/*!
 * @brief 设置发送器延时补偿值
 * @param[in] Module 指向CANFD内存结构的指针，取值为CANFD0-CANFD7
 * @param[in] Status 发送器延时补偿使能控制
 * @param[in] Offset 发送器延时补偿偏移值
 * @return void
 */
void Canfd_LL_SetTDCOffset(CanfdPtr Module, const bool Status, uint8_t Offset)
{
    Canfd_LL_SetTDCStatus(Module, Status);
    Canfd_LL_SetTDCOffsetValue(Module, Offset);
}

/**
 * @brief 预初始化模块
 * @param Module
 * @retval void
 */
void Canfd_LL_Init(CanfdPtr Module)
{
    /* Reset the CANFD */
    Canfd_LL_SetSoftReset(Module, true);
    /* Wait for reset cycle to complete */
    while (true == Canfd_LL_IsSoftReset(Module))
        ;
    /* Clear CANFD memory */
    Canfd_LL_ClearRam(Module);
    /* Rx global mask*/
    Canfd_LL_SetRxMbGlobalMask(Module, (uint32_t)0xFFFFFFFFU);
    /* Rx reg 14 mask*/
    Canfd_LL_SetRxMb14Mask(Module, (uint32_t)0xFFFFFFFFU);
    /* Rx reg 15 mask*/
    Canfd_LL_SetRxMb15Mask(Module, (uint32_t)0xFFFFFFFFU);
    /* Disable all MB interrupts */
    Canfd_LL_SetInt1Mask(Module, 0x0U);
    /* Clear all MB interrupt flags */
    Canfd_LL_ClearInt1Flag(Module, CAN_IMASK1_BUF31TO0M_MASK);
#if CANFD_MAX_MBNUM > 32U
    {
        /* Disable all MB interrupts */
        Canfd_LL_SetInt2Mask(Module, 0x0U);
        /* Clear all MB interrupt flags */
        Canfd_LL_ClearInt2Flag(Module, CAN_IMASK2_BUF63TO32M_MASK);
    }
#endif
#if CANFD_MAX_MBNUM > 64U
    {
        /* Disable all MB interrupts */
        Canfd_LL_SetInt3Mask(Module, 0x0U);
        /* Clear all MB interrupt flags */
        Canfd_LL_ClearInt3Flag(Module, CAN_IMASK3_BUF95TO64M_MASK);
    }
#endif
#if CANFD_MAX_MBNUM > 96U
    {
        /* Disable all MB interrupts */
        Canfd_LL_SetInt4Mask(Module, 0x0U);
        /* Clear all MB interrupt flags */
        Canfd_LL_ClearInt4Flag(Module, CAN_IMASK4_BUF127TO96M_MASK);
    }
#endif
    /* Clear all error interrupt flags */
    Canfd_LL_ClearErrorStatus(Module, CANFD_ALL_INT);
}

/**
 * @brief 使能接收FIFO
 * @param Module
 * @param NumberOfFilters
 * @retval void
 */
kf_status_t Canfd_LL_EnableRxFifo(CanfdPtr Module, uint32_t NumberOfFilters)
{
    kf_status_t retStatus    = STATUS_OK;
    uint32_t    mailboxIndex = 0U;
    if (true == Canfd_LL_IsFDEnabled(Module))
    {
        retStatus = STATUS_ERROR;
    }
    if (STATUS_OK == retStatus)
    {
        Canfd_LL_SetRxFifoEnable(Module, true);
        Canfd_LL_SetLegacyFifoFilterNum(Module, NumberOfFilters);
        Canfd_LL_SetRxMbGlobalMask(Module, (uint32_t)0xFFFFFFFFU);
        for (mailboxIndex = 0; mailboxIndex < CANFD_MAX_MBNUM; mailboxIndex++)
        {
            Canfd_LL_SetRxIndividualExtMask(Module, mailboxIndex, 0x1FFFFFFFU);
        }
    }
    return (retStatus);
}

/**
 * @brief 等待信号量释放
 * @param SemaphorePtr
 * @param Timeout
 * @retval kf_status_t
 */
kf_status_t Canfd_LL_WaitSemaphorephore(Semaphore_t *const SemaphorePtr, const uint32_t Timeout)
{
    kf_status_t retStatus = STATUS_OK;
    if (0U == Timeout)
    {
        if (0U == *SemaphorePtr)
        {
            retStatus = STATUS_TIMEOUT;
        }
    }
    else
    {
        /* timeout is not 0 */
        uint32_t deadLine = Kf_GetDeadLine(Timeout);
        while (0U == *SemaphorePtr)
        {
            if (Kf_IsDeadLine(deadLine))
            {
                /* Timeout occured, stop waiting and return fail code */
                retStatus = STATUS_TIMEOUT;
                break;
            }
        }
    }
    if (STATUS_OK == retStatus)
    {
        DISABLE_INTERRUPT();
        --(*SemaphorePtr);
        ENABLE_INTERRUPT();
    }
    return retStatus;
}

/**
 * @brief 获取邮箱地址
 * @param Module
 * @param MbIndex
 * @retval uint32_t*
 */
volatile uint32_t *Canfd_LL_GetMailboxAddr(CanfdPtr Module, uint32_t MbIndex)
{
    uint8_t  payloadSize          = Canfd_LL_GetPayloadSize(Module);
    uint8_t  arbitrationFieldSize = CANFD_ARBITRATION_RAMSIZE;
    uint32_t ramBlockSize         = CANFD_MAX_RAMSIZE;
    uint32_t ramBlockOffset;
    uint8_t  mbSize   = (uint8_t)(payloadSize + arbitrationFieldSize);
    uint8_t  maxMbNum = (uint8_t)(ramBlockSize / mbSize);
    ramBlockOffset    = CANFD_MAX_RAMSIZE * (MbIndex / (uint32_t)maxMbNum);
    /*TODO: Multiply the MB index by the MB size (in words) */
    uint32_t mbIndex = ramBlockOffset + ((MbIndex % (uint32_t)maxMbNum) * ((uint32_t)mbSize >> 2U));
    return &(Module->CANFD_RAM[mbIndex]);
}

/**
 * @brief 设置最大邮箱数量
 * @param Module
 * @param MaxMbNum
 * @retval kf_status_t
 */
kf_status_t Canfd_LL_SetMaxMbNum(CanfdPtr Module, uint32_t MaxMbNum)
{
    uint8_t            MbIndex;
    uint32_t           dataByte;
    kf_status_t        retStatus    = STATUS_OK;
    uint32_t           payloadSize  = Canfd_LL_GetPayloadSize(Module);
    volatile uint32_t *endMbPointer = Canfd_LL_GetMailboxAddr(Module, (MaxMbNum - 1U));
    uint32_t           endMb        = (uint32_t)endMbPointer + payloadSize + CANFD_ARBITRATION_RAMSIZE;
    if ((endMb > (uint32_t)(&Module->CANFD_RAM[CANFD_MAX_MBNUM])) || (MaxMbNum > CANFD_MAX_MBNUM))
    {
        retStatus = STATUS_CANFD_BUFF_OUT_OF_RANGE;
    }
    if (STATUS_OK == retStatus)
    {
        /* Set the maximum number of MBs*/
        Canfd_LL_SetMaxMbCount(Module, (MaxMbNum - 1U));
        if (false == Canfd_LL_IsRxFifoEnabled(Module))
        {
            /* Initialize all message buffers as inactive */
            for (MbIndex = 0; MbIndex < CANFD_MAX_MBNUM; MbIndex++)
            {
                volatile uint32_t *mailboxPtr     = Canfd_LL_GetMailboxAddr(Module, MbIndex);
                volatile uint32_t *mailboxIdPtr   = &mailboxPtr[1];
                volatile uint8_t  *mailboxDataPtr = (volatile uint8_t *)(&mailboxPtr[2]);
                CANFD_WRITE32(mailboxPtr, 0U);
                CANFD_WRITE32(mailboxIdPtr, 0U);
                for (dataByte = 0; dataByte < payloadSize; dataByte++)
                {
                    CANFD_WRITE8(mailboxDataPtr + dataByte, 0U);
                }
            }
        }
    }
    return (retStatus);
}

/**
 * @brief 设置操作模式
 * @param Module
 * @param Mode
 * @retval void
 */
void Canfd_LL_SetOperationMode(CanfdPtr Module, Canfd_OpMode_t Mode)
{
    switch (Mode)
    {
    case CANFD_FREEZE_MODE:
        /* Debug mode, Halt and Freeze*/
        Canfd_LL_EnterFreezeMode(Module);
        break;
    case CANFD_DISABLE_MODE:
        /* Debug mode, Halt and Freeze */
        Canfd_LL_SetModuleDisabled(Module, true);
        break;
    case CANFD_NORMAL_MODE:
        Canfd_LL_SetSuperVisorMode(Module, false);
        Canfd_LL_SetListenOnlyMode(Module, false);
        Canfd_LL_SetLoopBackMode(Module, false);
        break;
    case CANFD_LISTEN_ONLY_MODE:
        Canfd_LL_SetListenOnlyMode(Module, true);
        break;
    case CANFD_LOOPBACK_MODE:
        Canfd_LL_SetListenOnlyMode(Module, false);
        Canfd_LL_SetLoopBackMode(Module, true);
        /* Enable Self Reception */
        Canfd_LL_SetSelfReception(Module, true);
        break;
    default:
        /* Should not get here */
        break;
    }
}

/**
 * @brief 清除邮箱标志位
 * @param Module
 * @param MbIndex
 * @retval void
 */
void Canfd_LL_ClearMbIntrFlag(CanfdPtr Module, const uint32_t MbIndex)
{
    uint32_t flag = ((uint32_t)1U << (MbIndex % 32U));
    /* Clear the corresponding message buffer interrupt flag*/
    if (MbIndex < 32U)
    {
        Canfd_LL_ClearInt1Flag(Module, flag);
    }
#if CANFD_MAX_MBNUM > 32U
    if ((MbIndex >= 32U) && (MbIndex < 64U))
    {
        Canfd_LL_ClearInt2Flag(Module, flag);
    }
#endif
#if CANFD_MAX_MBNUM > 64U
    if ((MbIndex >= 64U) && (MbIndex < 96U))
    {
        Canfd_LL_ClearInt3Flag(Module, flag);
    }
#endif
#if CANFD_MAX_MBNUM > 96U
    if ((MbIndex >= 96U) & (MbIndex < 128U))
    {
        Canfd_LL_ClearInt4Flag(Module, flag);
    }
#endif
}

/**
 * @brief 获取邮箱标志位
 * @param Module
 * @param MbIndex
 * @retval bool
 */
bool Canfd_LL_GetMbIntrFlag(CanfdPtr Module, const uint32_t MbIndex)
{
    bool flag = false;
    if (MbIndex < 32U)
    {
        flag = ((Canfd_LL_GetInt1Flag(Module) & ((uint32_t)1U << (MbIndex % 32U))) != 0U ? true : false);
    }
#if CANFD_MAX_MBNUM > 32U
    if ((MbIndex >= 32U) && (MbIndex < 64U))
    {
        flag = ((Canfd_LL_GetInt2Flag(Module) & ((uint32_t)1U << (MbIndex % 32U))) != 0U ? true : false);
    }
#endif
#if CANFD_MAX_MBNUM > 64U
    if ((MbIndex >= 64U) && (MbIndex < 96U))
    {
        flag = ((Canfd_LL_GetInt3Flag(Module) & ((uint32_t)1U << (MbIndex % 32U))) != 0U ? true : false);
    }
#endif
#if CANFD_MAX_MBNUM > 96U
    if (MbIndex >= 96U)
    {
        flag = ((Canfd_LL_GetInt4Flag(Module) & ((uint32_t)1U << (MbIndex % 32U))) != 0U ? true : false);
    }
#endif
    return flag;
}

/**
 * @brief 设置邮箱中断
 * @param Module
 * @param MbIndex
 * @param Status
 * @retval kf_status_t
 */
kf_status_t Canfd_LL_SetMbIntr(CanfdPtr Module, const uint32_t MbIndex, const bool Status)
{
    kf_status_t retStatus = STATUS_OK;
    uint32_t    intBefore = 0U;
    uint32_t    intCmd    = 0U;
    uint32_t    intClear  = 0U;
    if (MbIndex > Canfd_LL_GetMaxMbNum(Module))
    {
        retStatus = STATUS_CANFD_BUFF_OUT_OF_RANGE;
    }
    else
    {
        intClear = ~(true << (MbIndex));
        intCmd   = (intCmd << (MbIndex));
        /* Enable the corresponding message buffer Interrupt */
        if (MbIndex < 32U)
        {
            intBefore = Canfd_LL_GetInt1Mask(Module);
            intBefore &= intClear;
            intBefore |= intCmd;
            Canfd_LL_SetInt1Mask(Module, intBefore);
        }
#if CANFD_MAX_MBNUM > 32U
        if ((MbIndex >= 32U) && (MbIndex < 64U))
        {
            intBefore = Canfd_LL_GetInt2Mask(Module);
            intBefore &= intClear;
            intBefore |= intCmd;
            Canfd_LL_SetInt2Mask(Module, intBefore);
        }
#endif
#if CANFD_MAX_MBNUM > 64U
        if ((MbIndex >= 64U) && (MbIndex < 96))
        {
            intBefore = Canfd_LL_GetInt3Mask(Module);
            intBefore &= intClear;
            intBefore |= intCmd;
            Canfd_LL_SetInt3Mask(Module, intBefore);
        }
#endif
#if CANFD_MAX_MBNUM > 96U
        if (MbIndex >= 96U)
        {
            intBefore = Canfd_LL_GetInt4Mask(Module);
            intBefore &= intClear;
            intBefore |= intCmd;
            Canfd_LL_SetInt4Mask(Module, intBefore);
        }
#endif
    }
    retStatus = STATUS_OK;
    return (retStatus);
}

/**
 * @brief 设置错误中断
 * @param Module
 * @param ErrType
 * @param Status
 * @retval kf_status_t
 */
void Canfd_LL_SetErrIntCmd(CanfdPtr Module, Canfd_Inttype_t ErrType, const bool Status)
{
    uint32_t intBefore = 0U;
    if ((ErrType == CANFD_INT_RX_WARNING) || (ErrType == CANFD_INT_TX_WARNING))
    {
        Canfd_LL_EnableWarnIntr(Module, Status);
    }
    if (ErrType == CANFD_INT_ERR)
    {
        Canfd_LL_EnableErrorFastIntr(Module, Status);
    }
    intBefore = Canfd_LL_GetErrorIntMask(Module);
    intBefore |= ErrType;
    Canfd_LL_SetErrorIntMask(Module, intBefore);
}

/**
 * @brief 取消发送邮箱
 * @param Module
 * @param MbIndex
 * @retval void
 */
void Canfd_LL_AbortTxMb(CanfdPtr Module, uint32_t MbIndex)
{
    uint32_t           csInfor    = 0;
    volatile uint32_t *mailboxPtr = Canfd_LL_GetMailboxAddr(Module, MbIndex);
    csInfor                       = *mailboxPtr;
    /* reset the code */
    csInfor &= (~CAN_CS_CODE_MASK);
    /* set abort code */
    csInfor |= (CANFD_TX_ABORT << CAN_CS_CODE_SHIFT) & CAN_CS_CODE_MASK;
    /* reload the code */
    *mailboxPtr = csInfor;
}

/**
 * @brief 设置发送邮箱
 * @param Module
 * @param MbIndex
 * @param PduInfoPtr
 * @param DataPtr
 * @retval kf_status_t
 */
kf_status_t
Canfd_LL_SetTxMb(CanfdPtr Module, uint32_t MbIndex, uint32_t Code, Canfd_PduInfo_t *PduInfoPtr, uint8_t *DataPtr)
{
    kf_status_t retStatus       = STATUS_OK;
    uint8_t     rxfifoFilterNum = 0U;
    uint32_t    databyte        = 0U;
    uint8_t     realDlc         = 0U;
    uint8_t     payloadLength   = 0U;
    uint8_t     maxMailboxIndex = Canfd_LL_GetMaxMbNum(Module);
    if (MbIndex > maxMailboxIndex)
    {
        retStatus = STATUS_CANFD_BUFF_OUT_OF_RANGE;
    }
    else if (true == Canfd_LL_IsRxFifoEnabled(Module))
    {
        rxfifoFilterNum = Canfd_LL_GetLegacyFifoFilterNum(Module);
        if (MbIndex <= Canfd_LL_RxFifoOcuppiedLastMsgBuff(rxfifoFilterNum))
        {
            retStatus = STATUS_CANFD_BUFF_OUT_OF_RANGE;
        }
    }
    else
    {
        /* Clean up the arbitration field area */
        volatile CANFD_CS_T  csInfor          = {0U};
        volatile CANFD_ID_T  mailboxId        = {0U};
        volatile CANFD_CS_T *csInforPtr       = (CANFD_CS_T *)Canfd_LL_GetMailboxAddr(Module, MbIndex);
        volatile CANFD_ID_T *mailboxIdPtr     = (CANFD_ID_T *)&csInforPtr[1];
        volatile uint8_t    *mailboxDataPtr   = (volatile uint8_t *)(&csInforPtr[2]);
        volatile uint32_t   *mailboxData32Ptr = (volatile uint32_t *)(&csInforPtr[2]);
        volatile uint32_t   *msgData32pPtr    = (volatile uint32_t *)DataPtr;
        if ((true == Canfd_LL_IsFDEnabled(Module)) && (PduInfoPtr->brsEnable))
        {
            Canfd_LL_SetFdRateSwitch(Module, true);
        }
        Canfd_LL_FormatPaddingValue(
          PduInfoPtr->msgId, PduInfoPtr->fdEnable, DataPtr, &PduInfoPtr->dataLength, &realDlc, PduInfoPtr->fdPadding);
        if (NULL_PTR != DataPtr)
        {
            payloadLength = Canfd_LL_GetDataLength(realDlc);
            for (databyte = 0; databyte < (PduInfoPtr->dataLength & ~3U); databyte += 4U)
            {
                Canfd_LL_SwapBytesInWord(&msgData32pPtr[databyte >> 2U], &mailboxData32Ptr[databyte >> 2U]);
            }
            for (; databyte < PduInfoPtr->dataLength; databyte++)
            {
                CANFD_WRITE32(mailboxDataPtr + SwapBytesInWordIndex(databyte), DataPtr[databyte]);
            }
            /* Add padding, if needed */
            for (databyte = PduInfoPtr->dataLength; databyte < payloadLength; databyte++)
            {
                CANFD_WRITE32(mailboxDataPtr + SwapBytesInWordIndex(databyte), PduInfoPtr->fdPadding);
            }
        }
        /* Set the length of data in bytes */
        csInfor.DLC = realDlc;
        if (CANFD_MSG_ID_EXT == PduInfoPtr->msgIdType)
        {
            /* ID [28-0] */
            mailboxId.EFF.ID = PduInfoPtr->msgId;
            /* Set IDE */
            csInfor.IDE = true;
            /* Clear SRR bit */
            csInfor.SRR = false;
        }
        else if (CANFD_MSG_ID_STD == PduInfoPtr->msgIdType)
        {
            /* ID[28-18] */
            mailboxId.SFF.ID = PduInfoPtr->msgId;
            /* make sure IDE and SRR are not set */
            csInfor.IDE = false;
            csInfor.SRR = false;
        }
        CANFD_WRITE32(&mailboxIdPtr->reg, mailboxId.reg);
        if ((uint32_t)CANFD_TX_NOTUSED != Code)
        {
            if ((uint32_t)CANFD_TX_REMOTE == Code)
            {
                csInfor.RTR = true;
            }
            /* Set the code */
            if (PduInfoPtr->fdEnable)
            {
                csInfor.EDL = true;
            }
            if (PduInfoPtr->brsEnable)
            {
                csInfor.BRS = true;
            }
            csInfor.CODE = Code;
            CANFD_WRITE32(&csInforPtr->CS_CODE, csInfor.CS_CODE);
        }
    }
    return (retStatus);
}

/**
 * @brief 设置接收邮箱
 * @param Module
 * @param MbIndex
 * @param PduInfoPtr
 * @retval kf_status_t
 */
kf_status_t Canfd_LL_SetRxMb(CanfdPtr Module, uint32_t MbIndex, uint32_t Code, const Canfd_PduInfo_t *PduInfoPtr)
{
    kf_status_t retStatus          = STATUS_OK;
    uint8_t     rxfifoFilterNum    = 0U;
    uint32_t    databyte           = 0U;
    uint32_t    canfdMailboxConfig = 0U;
    uint8_t     maxMailboxIndex    = Canfd_LL_GetMaxMbNum(Module);
    if (MbIndex > maxMailboxIndex)
    {
        retStatus = STATUS_CANFD_BUFF_OUT_OF_RANGE;
    }
    else if (true == Canfd_LL_IsRxFifoEnabled(Module))
    {
        rxfifoFilterNum = Canfd_LL_GetLegacyFifoFilterNum(Module);
        if (MbIndex <= Canfd_LL_RxFifoOcuppiedLastMsgBuff(rxfifoFilterNum))
        {
            retStatus = STATUS_CANFD_BUFF_OUT_OF_RANGE;
        }
    }
    else
    {
        /* Clean up the arbitration field area */
        volatile CANFD_CS_T  csInfor      = {0U};
        volatile CANFD_ID_T  mailboxId    = {0U};
        volatile CANFD_CS_T *csInforPtr   = (CANFD_CS_T *)Canfd_LL_GetMailboxAddr(Module, MbIndex);
        volatile CANFD_ID_T *mailboxIdPtr = (CANFD_ID_T *)&csInforPtr[1];
        if (CANFD_MSG_ID_EXT == PduInfoPtr->msgIdType)
        {
            /* ID [28-0] */
            mailboxId.EFF.ID = PduInfoPtr->msgId;
            /* Set IDE */
            csInfor.IDE = true;
        }
        else if (CANFD_MSG_ID_STD == PduInfoPtr->msgIdType)
        {
            /* ID[28-18] */
            mailboxId.SFF.ID = PduInfoPtr->msgId;
            /* make sure IDE and SRR are not set */
        }
        CANFD_WRITE32(&mailboxIdPtr->reg, mailboxId.reg);
        if ((uint32_t)CANFD_TX_NOTUSED != Code)
        {
            /* Set the code */
            csInfor.CODE = Code;
        }
        CANFD_WRITE32(&csInforPtr->CS_CODE, csInfor.CS_CODE);
    }
    return (retStatus);
}

/**
 * @brief 获取接收FIFO数据
 * @param Module
 * @param RxMsgPtr
 * @retval void
 */
void Canfd_LL_ReadRxFifo(CanfdPtr Module, Canfd_MsgBuff_t *RxMsgPtr)
{
    uint8_t                  payloadLength;
    uint32_t                 databyte;
    uint32_t                 mbWord;
    volatile const uint32_t *mailboxPtr     = Module->CANFD_RAM;
    volatile const uint32_t *mailboxIdPtr   = &Module->CANFD_RAM[1];
    volatile const uint32_t *mailboxDataPtr = &mailboxPtr[2];
    uint32_t                *msgData32Ptr   = (uint32_t *)(RxMsgPtr->data);

    uint8_t realDlc   = (uint8_t)(((*mailboxPtr) & CAN_CS_DLC_MASK) >> 16);
    payloadLength     = Canfd_LL_GetDataLength(realDlc);
    RxMsgPtr->dataLen = payloadLength;
    RxMsgPtr->cs      = CANFD_READ32(mailboxPtr);
    if ((RxMsgPtr->cs & CAN_CS_IDE_MASK) != 0U)
    {
        RxMsgPtr->msgId = CANFD_READ32(mailboxIdPtr);
    }
    else
    {
        RxMsgPtr->msgId = (CANFD_READ32(mailboxIdPtr)) >> CAN_ID_STD_SHIFT;
    }
    /* Copy MB[0] data field into user's buffer */
    for (databyte = 0U; databyte < payloadLength; databyte += 4U)
    {
        mbWord = (CANFD_READ32(&mailboxDataPtr[databyte >> 2U]));
        Canfd_LL_SwapBytesInWord(&mbWord, &msgData32Ptr[databyte >> 2U]);
    }
}

/**
 * @brief 获取接收FIFO掩码
 * @param IdType
 * @param FormatType
 * @param Mask
 * @retval uint32_t
 */
uint32_t Canfd_LL_GetRxFifoMask(Canfd_IdType_t IdType, Canfd_RxFifoIdFormat_t FormatType, uint32_t Mask)
{
    uint32_t val = 0;
    switch (FormatType)
    {
    case CANFD_RX_FIFO_ID_FORMAT_A: {
        /* Set RTR bit encoded as bit 31 and IDE bit encoded as bit 30 in mask */
        val = Mask & ((1UL << CANFD_FORMATAB_RTR_SHIFT) | (1UL << CANFD_FORMATAB_IDE_SHIFT));
        if (IdType == CANFD_MSG_ID_STD)
        {
            /* Set standard global mask for RX FIFO and IDE will be 1 and check the FIFO filter ide */
            val |= ((Mask << CANFD_FORMATA_STD_SHIFT) & CANFD_FORMATA_STD_MASK);
        }
        else if (IdType == CANFD_MSG_ID_EXT)
        {
            /* Set extended global mask for RX FIFO and IDE will be 0 and don't check the FIFO filter ide */
            val |= ((Mask << CANFD_FORMATA_EXT_SHIFT) & CANFD_FORMATA_EXT_MASK);
        }
        else
        {
            /* Should not get here */
        }
    }
    break;
    case CANFD_RX_FIFO_ID_FORMAT_B: {
        /* Set RTR bit encoded as bit 31 and IDE bit encoded as bit 30 in mask */
        val = Mask & ((1UL << CANFD_FORMATAB_RTR_SHIFT) | (1UL << CANFD_FORMATAB_IDE_SHIFT));
        if (IdType == CANFD_MSG_ID_STD)
        {
            /* Set standard global mask for RX FIFO  */
            val |= ((Mask & CANFD_FORMATB_STD_MASK) << CANFD_FORMATB_STD_SHIFT1);
        }
        else if (IdType == CANFD_MSG_ID_EXT)
        {
            /* Set extended global mask for RX FIFO  */
            val |= ((Mask & CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK1) << CANFD_FORMATB_EXT_SHIFT1);
        }
        else
        {
            /* Should not get here */
        }
    }
    break;
    case CANFD_RX_FIFO_ID_FORMAT_C: {
        if ((IdType == CANFD_MSG_ID_EXT) || (IdType == CANFD_MSG_ID_STD))
        {
            val |= ((Mask & CANFD_FORMATC_MASK) << CANFD_FORMATC_SHIFT1);
        }
        else
        {
            /* Should not get here */
        }
    }
    break;
    case CANFD_RX_FIFO_ID_FORMAT_D:
        break;
    default:
        break;
    }
    return val;
}

/**
 * @brief 获取接收FIFO滤波器
 * @param Module
 * @param IdFormat
 * @param IdFilterTablePtr
 * @retval void
 */
void Canfd_LL_SetRxFifoFilter(CanfdPtr Module, Canfd_RxFifoIdFormat_t IdFormat, const Canfd_IdTable_t *IdFilterTablePtr)
{
    uint32_t           val1 = 0U, val2 = 0U, val = 0U;
    uint32_t           filterNumber, filterIndex, filterTableIndex;
    volatile uint32_t *filterTablePtr = &Module->CANFD_RAM[RXFIFO_FILTER_TABLE_OFFSET];
    filterNumber                      = Canfd_LL_GetLegacyFifoFilterNum(Module);
    Canfd_LL_SetRxFifoIdFormat(Module, IdFormat);
    switch (IdFormat)
    {
    case CANFD_RX_FIFO_ID_FORMAT_A: {
        for (filterIndex = 0; filterIndex < RxFifoFilterElementNum(filterNumber); filterIndex++)
        {
            val = 0;
            if (IdFilterTablePtr[filterNumber].isRemoteFrame)
            {
                val = CAFND_RX_FIFO_ACCEPT_REMOTE_FRAME << CANFD_FORMATAB_RTR_SHIFT;
            }
            if (IdFilterTablePtr[filterNumber].isExtendedFrame)
            {
                val |= CAFND_RX_FIFO_ACCEPT_EXT_FRAME << CANFD_FORMATAB_IDE_SHIFT;
                filterTablePtr[filterNumber] =
                  val + ((IdFilterTablePtr[filterNumber].id << CANFD_FORMATA_EXT_SHIFT) & CANFD_FORMATA_EXT_MASK);
            }
            else
            {
                filterTablePtr[filterNumber] =
                  val + ((IdFilterTablePtr[filterNumber].id << CANFD_FORMATA_STD_SHIFT) & CANFD_FORMATA_STD_MASK);
            }
        }
    }
    break;
    case CANFD_RX_FIFO_ID_FORMAT_B: {
        filterTableIndex = 0;
        for (filterIndex = 0; filterIndex < RxFifoFilterElementNum(filterNumber); filterIndex++)
        {
            val1 = 0;
            val2 = 0;
            if (IdFilterTablePtr[filterTableIndex].isRemoteFrame)
            {
                val1 = CAFND_RX_FIFO_ACCEPT_REMOTE_FRAME << CANFD_FORMATAB_RTR_SHIFT;
            }
            if (IdFilterTablePtr[filterTableIndex + 1U].isRemoteFrame)
            {
                val2 = CAFND_RX_FIFO_ACCEPT_REMOTE_FRAME << CANFD_RX_FIFO_ID_FILTER_FORMATB_RTR_SHIFT;
            }
            if (IdFilterTablePtr[filterTableIndex].isExtendedFrame)
            {
                val1 |= CAFND_RX_FIFO_ACCEPT_EXT_FRAME << CANFD_FORMATAB_IDE_SHIFT;
                filterTablePtr[filterNumber] =
                  val1 + (((IdFilterTablePtr[filterTableIndex].id & CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK) >>
                           CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT)
                          << CANFD_FORMATB_EXT_SHIFT1);
            }
            else
            {
                filterTablePtr[filterNumber] =
                  val1 + ((IdFilterTablePtr[filterTableIndex].id & CANFD_FORMATB_STD_MASK) << CANFD_FORMATB_STD_SHIFT1);
            }
            if (IdFilterTablePtr[filterTableIndex + 1U].isExtendedFrame)
            {
                val2 |= CAFND_RX_FIFO_ACCEPT_EXT_FRAME << CANFD_RX_FIFO_ID_FILTER_FORMATB_IDE_SHIFT;
                filterTablePtr[filterNumber] |=
                  val2 + (((IdFilterTablePtr[filterTableIndex + 1U].id & CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK) >>
                           CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT)
                          << CANFD_RX_FIFO_ID_FILTER_FORMATB_EXT_SHIFT2);
            }
            else
            {
                filterTablePtr[filterNumber] |=
                  val2 + ((IdFilterTablePtr[filterTableIndex + 1U].id & CANFD_FORMATB_STD_MASK)
                          << CANFD_RX_FIFO_ID_FILTER_FORMATB_STD_SHIFT2);
            }
            filterTableIndex = filterTableIndex + 2U;
        }
    }
    break;
    case CANFD_RX_FIFO_ID_FORMAT_C: {
        filterTableIndex = 0;
        for (filterIndex = 0; filterIndex < RxFifoFilterElementNum(filterNumber); filterIndex++)
        {
            if (IdFilterTablePtr[filterTableIndex].isExtendedFrame)
            {
                filterTablePtr[filterNumber] |=
                  val1 + (((IdFilterTablePtr[filterTableIndex].id & CANFD_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>
                           CANFD_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT)
                          << CANFD_FORMATC_SHIFT1);
            }
            else
            {
                filterTablePtr[filterNumber] |=
                  val1 + (((IdFilterTablePtr[filterTableIndex].id & CANFD_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>
                           CANFD_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT)
                          << CANFD_FORMATC_SHIFT1);
            }
            if (IdFilterTablePtr[filterTableIndex + 1U].isExtendedFrame)
            {
                filterTablePtr[filterNumber] |=
                  val1 + (((IdFilterTablePtr[filterTableIndex + 1U].id & CANFD_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>
                           CANFD_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT)
                          << CANFD_RX_FIFO_ID_FILTER_FORMATC_SHIFT2);
            }
            else
            {
                filterTablePtr[filterNumber] |=
                  val1 + (((IdFilterTablePtr[filterTableIndex + 1U].id & CANFD_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>
                           CANFD_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT)
                          << CANFD_RX_FIFO_ID_FILTER_FORMATC_SHIFT2);
            }
            if (IdFilterTablePtr[filterTableIndex + 2U].isExtendedFrame)
            {
                filterTablePtr[filterNumber] |=
                  val1 + (((IdFilterTablePtr[filterTableIndex + 2U].id & CANFD_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>
                           CANFD_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT)
                          << CANFD_RX_FIFO_ID_FILTER_FORMATC_SHIFT3);
            }
            else
            {
                filterTablePtr[filterNumber] |=
                  val1 + (((IdFilterTablePtr[filterTableIndex + 2U].id & CANFD_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>
                           CANFD_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT)
                          << CANFD_RX_FIFO_ID_FILTER_FORMATC_SHIFT3);
            }
            if (IdFilterTablePtr[filterTableIndex + 3U].isExtendedFrame)
            {
                filterTablePtr[filterNumber] |=
                  val1 + (((IdFilterTablePtr[filterTableIndex + 3U].id & CANFD_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>
                           CANFD_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT)
                          << CANFD_RX_FIFO_ID_FILTER_FORMATC_SHIFT4);
            }
            else
            {
                filterTablePtr[filterNumber] |=
                  val1 + (((IdFilterTablePtr[filterTableIndex + 3U].id & CANFD_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>
                           CANFD_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT)
                          << CANFD_RX_FIFO_ID_FILTER_FORMATC_SHIFT4);
            }
            filterTableIndex = filterTableIndex + 4U;
        }
    }
    break;
    case CANFD_RX_FIFO_ID_FORMAT_D:
        break;
    default:
        break;
    }
}

/**
 * @brief 获取接收邮箱数据
 * @param Module
 * @param MbIndex
 * @param RxMsgPtr
 * @retval kf_status_t
 */
kf_status_t Canfd_LL_GetMbData(CanfdPtr Module, const uint32_t MbIndex, Canfd_MsgBuff_t *RxMsgPtr)
{
    uint8_t                  i, payloadLength;
    uint32_t                 val1, val2 = 1;
    kf_status_t              retStatus          = STATUS_OK;
    volatile const uint32_t *mailboxPtr         = Canfd_LL_GetMailboxAddr(Module, MbIndex);
    volatile const uint32_t *mailboxIdPtr       = &mailboxPtr[1];
    volatile const uint8_t  *mailboxDataPtr     = (volatile const uint8_t *)(&mailboxPtr[2]);
    volatile const uint32_t *mailBoxPtr_data_32 = &mailboxPtr[2];
    uint32_t                *mailboxData32Ptr   = (uint32_t *)(RxMsgPtr->data);
    uint32_t                 mbWord;

    uint8_t realDlc   = (uint8_t)(((*mailboxPtr) & CAN_CS_DLC_MASK) >> 16);
    payloadLength     = Canfd_LL_GetDataLength(realDlc);
    RxMsgPtr->dataLen = payloadLength;
    /* Check if RX FIFO is enabled */
    if (true == Canfd_LL_IsRxFifoEnabled(Module))
    {
        /* Get the number of RX FIFO Filters*/
        val1 = Canfd_LL_GetLegacyFifoFilterNum(Module);
        /* Get the number if MBs occupied by RX FIFO and ID filter table*/
        /* the Rx FIFO occupies the memory space originally reserved for MB0-5*/
        /* Every number of RFFN means 8 number of RX FIFO filters*/
        /* and every 4 number of RX FIFO filters occupied one MB*/
        val2 = Canfd_LL_RxFifoOcuppiedLastMsgBuff(val1);
        if (MbIndex <= val2)
        {
            retStatus = STATUS_CANFD_BUFF_OUT_OF_RANGE;
        }
    }
    if (STATUS_OK == retStatus)
    {
        /* Get a MB field values */
        RxMsgPtr->cs = *mailboxPtr;
        if ((RxMsgPtr->cs & CAN_CS_IDE_MASK) != 0U)
        {
            RxMsgPtr->msgId = CANFD_READ32(mailboxIdPtr);
        }
        else
        {
            RxMsgPtr->msgId = CANFD_READ32(mailboxIdPtr) >> CAN_ID_STD_SHIFT;
        }
        for (i = 0U; i < (payloadLength & ~3U); i += 4U)
        {
            mbWord = CANFD_READ32(mailBoxPtr_data_32[i >> 2U]);
            Canfd_LL_SwapBytesInWord(&mbWord, &mailboxData32Ptr[i >> 2U]);
        }
        for (; i < payloadLength; i++)
        { /* Max allowed value for index is 63 */
            RxMsgPtr->data[i] = mailboxDataPtr[SwapBytesInWordIndex(i)];
        }
    }
    return retStatus;
}

/**
 * @brief 锁定接收邮箱
 * @param Module
 * @param MbIndex
 * @retval void
 */
void Canfd_LL_LockRxMailBox(CanfdPtr Module, uint32_t MbIndex)
{
    volatile uint32_t *mailboxPtr = Canfd_LL_GetMailboxAddr(Module, MbIndex);
    /* Lock the mailbox by reading it */
    (void)mailboxPtr;
}

/**
 * @brief 复位接收邮箱
 * @param Module
 * @param MbIndex
 * @retval void
 */
void Canfd_LL_ResetRxMalibox(CanfdPtr Module, uint32_t MbIndex)
{
    uint32_t csInfo = 0;
    uint32_t code   = CANFD_RX_INACTIVE;

    volatile uint32_t *mailBoxPtr = Canfd_LL_GetMailboxAddr(Module, MbIndex);
    csInfo                        = *mailBoxPtr;
    /* Reset the code and unlock the MB */
    csInfo &= (~CAN_CS_CODE_MASK);
    csInfo |= (code << CAN_CS_CODE_SHIFT) & CAN_CS_CODE_MASK;
    *mailBoxPtr = csInfo;

    /* Reconfigure The MB as left by RxMBconfig */
    code = CANFD_RX_EMPTY;
    csInfo &= (~CAN_CS_CODE_MASK);
    csInfo |= (code << CAN_CS_CODE_SHIFT) & CAN_CS_CODE_MASK;
    *mailBoxPtr = csInfo;
}

/**
 * @brief 配置 Pretended Networking 功能
 * @param Module
 * @param PnConfigPtr
 * @retval void
 */
void Canfd_LL_ConfigPN(CanfdPtr Module, const Canfd_PNConfig_t *PnConfigPtr)
{
    /* Configure specific pretended networking settings */
    Canfd_LL_SetPNFilter(Module, PnConfigPtr->wakeUpTimeout, PnConfigPtr->wakeUpMatch, PnConfigPtr->numMatches,
                         PnConfigPtr->filterComb, PnConfigPtr->idFilterType, PnConfigPtr->payloadFilterType);
    Canfd_LL_SetPNTimeoutValue(Module, PnConfigPtr->matchTimeout);
    /* Configure ID filtering */
    Canfd_LL_SetPNIdFilter1(Module, PnConfigPtr->idFilter1);
    /* Configure the second ID, if needed (as mask for exact matching or higher limit for range matching) */
    if ((PnConfigPtr->idFilterType == CANFD_FILTER_MATCH_EXACT) ||
        (PnConfigPtr->idFilterType == CANFD_FILTER_MATCH_RANGE))
    {
        Canfd_LL_SetPNIdFilter2(Module, PnConfigPtr->idFilter2);
    }
    else
    {
        /* In other case need only to check the IDE and RTR match the ID_MASK is not considered */
        Canfd_LL_SetPNIdFilter2Check(Module);
    }
    /* Configure payload filtering, if requested */
    if ((PnConfigPtr->filterComb == CANFD_FILTER_ID_PAYLOAD) ||
        (PnConfigPtr->filterComb == CANFD_FILTER_ID_PAYLOAD_NTIMES))
    {
        Canfd_LL_SetPNDlcFilter(Module, PnConfigPtr->payloadFilter.dlcLow, PnConfigPtr->payloadFilter.dlcHigh);
        Canfd_LL_SetPNPayloadHighFilter1(Module, PnConfigPtr->payloadFilter.payload1);
        Canfd_LL_SetPNPayloadLowFilter1(Module, PnConfigPtr->payloadFilter.payload1);
        /* Configure the second payload, if needed (as mask for exact matching or higher limit for range matching) */
        if ((PnConfigPtr->payloadFilterType == CANFD_FILTER_MATCH_EXACT) ||
            (PnConfigPtr->payloadFilterType == CANFD_FILTER_MATCH_RANGE))
        {
            Canfd_LL_SetPNPayloadHighFilter2(Module, PnConfigPtr->payloadFilter.payload2);
            Canfd_LL_SetPNPayloadLowFilter2(Module, PnConfigPtr->payloadFilter.payload2);
        }
    }
}

#if FEATURE_CAN_HAS_MEM_ERR_DET
/**
 * @brief 禁止 错误内存更正功能
 * @param Module
 * @retval void
 */
void Canfd_LL_DisableMemErrorDetection(CanfdPtr Module)
{
    Canfd_LL_ErrorCorrectConfigurateEnable(Module, true);
    Canfd_LL_ErrorCorrectConfigurateWriteDisable(Module, false);
    Canfd_LL_ErrorCorrectInFreeze(Module, false);
    Canfd_LL_ErrorCorrectConfigurateEnable(Module, false);
}
#endif
