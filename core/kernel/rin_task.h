/*
 * MIT License
 * 
 * Copyright (c) [2018] [CSU Yangyang]
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef RIN_TASK_H
#define RIN_TASK_H


#include "RinOS_kernel.h"
#include "rin_pipe.h"


typedef void (*task_f)(void *);

typedef U32     task_stack_t;
typedef U32     task_tick_t;
typedef U8      task_prio_t;


typedef enum {
    state_run,
    state_ready,
    state_delay,
    state_suspend,
    state_kill,
} task_state_t;


typedef struct _TCB {
    task_stack_t *stack_p;
    task_tick_t delay_tick;
    task_prio_t prio;

    task_state_t state;
    usage_t period_usage;

    DNODE_t dnd_state;
    DNODE_t dnd_sus;

    PIPE_t pipe_o; // Pipe's output(rinos out).
    DNODE_t dnd_o; // Dnode's output(rinos out).
} TCB_T, *TCB_P;

#define task_create(func, param, prio)  \
  task_create_full(func, param, prio, PIPE_PRINT_SIZE)

#endif /* RIN_TASK_H */
