#include "kf_types.h"
#include "app_task.h"

#define TC03_STACK_SIZE (512U)

static StackType_t  Tc03_1_Stack[TC03_STACK_SIZE];
static StaticTask_t Tc03_1_StaticTCB;
static StackType_t  Tc03_2_Stack[TC03_STACK_SIZE];
static StaticTask_t Tc03_2_StaticTCB;

static void TaskTc03_1(void *pvParameters)
{
    while (1)
    {
        volatile uint32_t cnt = 0;
        for (cnt = 0; cnt < 1000; cnt++)
        {
            __asm__ volatile("NOP");
        }
        os_sleep(1);
    }
}
static void TaskTc03_2(void *pvParameters)
{
    while (1)
    {
        volatile uint32_t cnt = 0;
        for (cnt = 1000; cnt > 0; cnt--)
        {
            __asm__ volatile("NOP");
        }
        os_sleep(1);
    }
}

/* 同优先级任务主动挂起 */
void RtosTc03()
{
    xTaskCreateStatic(
      TaskTc03_1, "TaskTc03_1", TC03_STACK_SIZE, NULL, TASK_START_PRIO_5, Tc03_1_Stack, &Tc03_1_StaticTCB);
    xTaskCreateStatic(
      TaskTc03_2, "TaskTc03_2", TC03_STACK_SIZE, NULL, TASK_START_PRIO_4, Tc03_2_Stack, &Tc03_2_StaticTCB);
    vTaskStartScheduler();
}