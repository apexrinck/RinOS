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


#include "rin_portable.h"
#include "stdarg.h"
#include "stdlib.h"


#ifdef STM32F405RGT6

    /**** Serial IO ****/
    USART_TypeDef* serial_p;

    
#endif /* STM32F405RGT6 */


// Using when RinOS initializing not finished.
void rin_clog_delay(U32 time)
{
    for(U32 i = 0; i <= time; i++)
    {
        for(U32 j = 30000000; j; j--);  // Depend on main frequence.
    }
}

// Support by hardware.
U8 _write(U8* ptr, U8 len)
{
    U8 data_idx;
    for(data_idx = 0; data_idx < len; data_idx++)
    {
        USART_SendData(USART3, (U8)(*(ptr + data_idx)));
        while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
    }
    return data_idx;
}

void _write_U8(U8 data)
{
    USART_SendData(USART3, (U8)(data));
    while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
}