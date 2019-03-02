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


#ifndef RIN_PENDSV_H
#define RIN_PENDSV_H


// RinOS memory adress.
#define MEM32(addr)         (*(volatile unsigned long *)(addr))
#define MME8(addr)          (*(volatile unsigned long *)(addr))

// RinOS pendsv set define.
#define RIN_NVIC_INT_CTRL   (RIN_HARDWARE_NVIC_INT_CTRL)
#define RIN_NVIC_PENDSVSET  (RIN_HARDWARE_NVIC_PENDSVSET)
#define RIN_NVIC_SYSPRI2    (RIN_HARDWARE_NVIC_SYSPRI2)
#define RIN_PENDSV_PRI      (RIN_HARDWARE_PENDSV_PRI)
#define RIN_PENDSV_SET()    MEM32(RIN_NVIC_INT_CTRL) = RIN_NVIC_PENDSVSET


#endif /* RIN_PENDSV_H */