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


#ifndef RIN_HEARTBEAT_H
#define RIN_HEARTBEAT_H


#include "rin_portable.h"


/*
 * @ brief: Arm to show the heartbeat of OS by the blink of leds.
 */


#define LED_HEARTBEAT_HIGH_PIN      GPIO_Pin_1
#define LED_HEARTBEAT_HIGH_PORT     GPIOC
#define LED_HEARTBEAT_LOW_PIN       GPIO_Pin_2
#define LED_HEARTBEAT_LOW_PORT      GPIOC

#define LED_PORT_OUT_HIGH(p, i)     (p->BSRRL = i)
#define LED_PORT_OUT_LOW(p, i)      (p->BSRRH = i)


void LED_init(void);


#endif /* RIN_HEARTBEAT_H */