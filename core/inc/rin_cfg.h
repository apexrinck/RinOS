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


#ifndef RIN_CFG_H
#define RIN_CFG_H


#include "rin_portable.h"

// Onboard RinOS clock frequency.
#define RIN_CLOCK_FREQ              (RIN_HARDWARE_CLOCK_FREQ)

// RinOS task's lowest proirity.
#define RIN_TASK_PRIO_LOWEST        5

// The size of RinOS's task pool.
#define RIN_TASK_STASK_SIZE         384  // U32
// The size of RinOS's excepting stack.
#define RIN_EXCEPTION_STACK_SIZE // Unused.

// The size of RinOS's IRQ stack.
#define RIN_IRQ_STAT_STACK_SIZE     10  // U32
// The size of RinOS's memory pool.
#define RIN_MEMORY_POOL_SIZE        (100 * 1024 / 4) // U32

// The size of RinOS's kernel task PRINT's pipe.
#define RIN_PIPE_PRINT_SIZE 150 // U32


#endif /* RIN_CFG_H */
