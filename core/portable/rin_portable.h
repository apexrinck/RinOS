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


#ifndef RIN_PORTABLE_H
#define RIN_PORTABLE_H


/**** hardware support ****/
/** Support hardware:
 * 1. STM32F405RGT6
 */
#define STM32F405RGT6
   
#ifdef STM32F405RGT6

/**** RinOS situation definations ****/
#define RIN_HARDWARE_CLOCK_FREQ         168000000U

#define RIN_HARDWARE_NVIC_INT_CTRL      0xE000ED04
#define RIN_HARDWARE_NVIC_PENDSVSET     0x10000000
#define RIN_HARDWARE_NVIC_SYSPRI2       0xE000ED22
#define RIN_HARDWARE_PENDSV_PRI         0x000000FF

/**** Include ST lib and STM32 SDK ****/
#include "stm32f4xx.h"
#include "misc.h"
#include "core_cm4.h"

/**** Needed structs and variables ****/
extern USART_TypeDef    *serial_p;

#endif /* STM32F405RGT6 */


/* Only serve for RinOS */
#include "rin_type.h"


void rin_clog_delay(U32 time);
U8   _write(U8* ptr, U8 len);
void _write_U8(U8 data);


#endif /* RIN_PORTABLE_H */
