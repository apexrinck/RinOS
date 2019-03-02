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


/* RinckOS Kernel V0.1.1
 * Copyright by CSU Yangyang
 * https://github.com/RinckT/RinOS
 * 
 * Support 32Bits RSIC MPU
 * Follow MISRA C: 2012
 * 1 tab == 4 sapces
 * based on FreeRTOS
 */

/* Kernel includes */
#include "RinOS.h"
#include "usr.h"


/* application include */

/* Hardware and starter kit includes */

int main(void)
{
    usart3_init();
    LED_init();
    int a = 5;
    while (1)
    {
        // USART_SendData(USART3, 0x01);
        //rout("s: Hello world!\n");
        rout("d: %d\n", a);
        rin_clog_delay(1);
    }
    return 0;
}
