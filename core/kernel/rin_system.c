#include "rin_system.h"
#include "rin_idle.h"
#include "rin_io.h"
#include "rin_irq_handle.h"
#include "rin_resolver.h"
#include "rin_tick.h"
#include "rin_tick_handle.h"

TCB_p tcb_p_curr;
TCB_p tcb_p_next;

SYSTEM_PARAM_T system_param;

void rin_init(void)
{
    printf("RinOS init...\r\n"); // TASK "PRINT" is not available now.

    /**** Initialize the double node for system parameters ****/
    for (U8 task_idx; task_idx < RIN_TASK_PRIO_LOWEST + 1; task_idx++)
    {
        dnode_head_init(&system_param.dhead_ready[task_idx]);
    }
    dnode_head_init(&system_param.dhead_delay);
    dnode_head_init(&system_param.dhead_suspend);
    dnode_head_init(&system_param.dhead_kill);

    /**** Set NVIC priority group and rtos's tick ****/
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    tick_init(1);
    init_tick_callback();

    dnode_head_init(&dhead_print);

    /**** RinOS's kernel function task ****/
    task_create(task_PRINT, NULL, RIN_TASK_PRIO_LOWEST);
    system_param.use_io = 1;
    task_create(task_resolver, NULL, RIN_TASK_PRIO_LOWEST);
    task_create(task_idle, NULL, RIN_TASK_PRIO_LOWSET + 1);
    task_create(task_irq_handle, NULL, 0);

    printf("RinOS init succeed!\r\n");
}