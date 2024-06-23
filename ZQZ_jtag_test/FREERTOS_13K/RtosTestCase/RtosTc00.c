#include "kf_types.h"
#include "app_task.h"

#define TC00_STACK_SIZE (512U)

static StackType_t  Tc00Stack[TC00_STACK_SIZE];
static StaticTask_t Tc00StaticTCB;

void TaskTc00(void *pvParameters)
{
    volatile uint32_t cnt = 0;
    while (1)
    {
        for (uint32_t i = 0; i < 1000; i++)
        {
            cnt += 1;
        }
        os_sleep(1U);
    }
}

/* 静态创建单一任务，主动挂起 */
void RtosTc00()
{
    xTaskCreateStatic(TaskTc00, "TaskTc00", TC00_STACK_SIZE, NULL, TASK_START_PRIO_3, Tc00Stack, &Tc00StaticTCB);
    vTaskStartScheduler();
}