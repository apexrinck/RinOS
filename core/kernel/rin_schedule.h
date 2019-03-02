#ifndef RIN_SCHEDULE_H
#define RIN_SCHEDULE_H

#include "RinOS_kernel.h"

#include "rin_system.h"
#include "rin_task.h"

void task_delay_ms(U32 tick);

void task_period_set(U32 tick);
void task_period_delay(void);

void task_yield(void);

void task_suspend(TCB_p tcb_p);
void task_resume(TCB_p tcb_p);

void task_set_prio(TCB_p tcb_p, task_prio_t prio);

#endif /* RIN_SCHEDULE_H */