#include "kf_types.h"
#include "app_task.h"

#define TC01_STACK_SIZE (512U)

static StackType_t  Tc01_1_Stack[TC01_STACK_SIZE];
static StaticTask_t Tc01_1_StaticTCB;
static StackType_t  Tc01_2_Stack[TC01_STACK_SIZE];
static StaticTask_t Tc01_2_StaticTCB;

static void TaskTc01_1(void *pvParameters)
{
    volatile uint32_t cnt = 0;
    while (1)
    {
        cnt += 1;
    }
}
static void TaskTc01_2(void *pvParameters)
{
    volatile uint32_t cnt = 0xFFFFFFFF;
    while (1)
    {
        cnt -= 1;
    }
}

/* 静态创建相同优先级任务，时间片轮转 */
void RtosTc01()
{
    xTaskCreateStatic(
      TaskTc01_1, "TaskTc01_1", TC01_STACK_SIZE, NULL, TASK_START_PRIO_5, Tc01_1_Stack, &Tc01_1_StaticTCB);
    xTaskCreateStatic(
      TaskTc01_2, "TaskTc01_2", TC01_STACK_SIZE, NULL, TASK_START_PRIO_5, Tc01_2_Stack, &Tc01_2_StaticTCB);
    vTaskStartScheduler();
}