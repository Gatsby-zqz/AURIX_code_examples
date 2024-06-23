#include "kf_types.h"
#include "app_task.h"

#define TC02_STACK_SIZE (512U)

static StackType_t  Tc02_1_Stack[TC02_STACK_SIZE];
static StaticTask_t Tc02_1_StaticTCB;
static StackType_t  Tc02_2_Stack[TC02_STACK_SIZE];
static StaticTask_t Tc02_2_StaticTCB;

static void TaskTc02_1(void *pvParameters)
{
    volatile uint32_t cnt = 0;
    while (1)
    {
        cnt += 1;
    }
}
static void TaskTc02_2(void *pvParameters)
{
    volatile uint32_t cnt = 0xFFFFFFFF;
    while (1)
    {
        cnt -= 1;
    }
}

/* 高优先级任务始终调度 */
void RtosTc02()
{
    xTaskCreateStatic(
      TaskTc02_1, "TaskTc02_1", TC02_STACK_SIZE, NULL, TASK_START_PRIO_5, Tc02_1_Stack, &Tc02_1_StaticTCB);
    xTaskCreateStatic(
      TaskTc02_2, "TaskTc02_2", TC02_STACK_SIZE, NULL, TASK_START_PRIO_4, Tc02_2_Stack, &Tc02_2_StaticTCB);
    vTaskStartScheduler();
}