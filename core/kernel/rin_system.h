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


#ifndef RIN_SYSTEM_H
#define RIN_SYSTEM_H


#include "RinOS_kernel.h"
#include "rin_task.h"


// RinOS system manage by doublelist.
typedef struct _SYSTEM_PARAM {
    DNODE_T dhead_ready[RIN_TASK_PRIO_LOWEST + 2];
    DNODE_T dhead_delay;
    DNODE_T dhead_suspend;
    DNODE_T dhead_kill;

    U8 rout_use;
} SYSTEM_PARAM_T;

extern SYSTEM_PARAM_T system_param;

extern TCB_p ptcb_curr;
extern TCB_p prcb_next;

void  rin_init(void);
void  rin_run(void);
TCB_p rin_get_prio_highest(void);
void  rin_udpate_switch(void);

#endif /* RIN_SYSTEM_H */
