/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : app_task.h
 *  @Author           : ChipON AE/FAE Group
 *  @Data             : 2023-10-16
 *  @HW Version       : KF32A158-MINI-EVB_V1.0
 *  @Version          : V1.0.0.1_alpha
 *  @Description      : This file provides hli for spi
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef APP_TASK_H
#define APP_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief:任务优先级
 */
typedef enum
{
    TASK_START_PRIO_1 = 1,
    TASK_START_PRIO_2,
    TASK_START_PRIO_3,
    TASK_START_PRIO_4,
    TASK_START_PRIO_5,
    TASK_START_PRIO_6,
    TASK_START_PRIO_7,
    TASK_START_PRIO_8,
    TASK_START_PRIO_9,
    TASK_START_PRIO_10,
    TASK_START_PRIO_11,
    TASK_START_PRIO_12,
    TASK_START_PRIO_13,
    TASK_START_PRIO_14,
    TASK_START_PRIO_15,
    TASK_START_PRIO_16,
    TASK_START_PRIO_17,
    TASK_START_PRIO_18,
    TASK_START_PRIO_19,
    TASK_START_PRIO_20,
    TASK_START_PRIO_21,
    TASK_START_PRIO_22,
    TASK_START_PRIO_23,
    TASK_START_PRIO_24,
    TASK_START_PRIO_25,
    TASK_START_PRIO_26,
    TASK_START_PRIO_27,
    TASK_START_PRIO_28,
    TASK_START_PRIO_29,
    TASK_START_PRIO_30
} TASK_START_PRIO;

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/**
 * @brief 系统延时
 *
 * @param  msec-延时时间，单位毫秒
 */
void os_sleep(int msec);

/**
 * @brief 启动任务
 *
 * @param pvParameters-函数入参
 *
 * @return None
 */
void main_task(void *pvParameters);

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
