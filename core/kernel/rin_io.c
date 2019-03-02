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


#include "stdarg.h"
#include "stdlib.h"
#include "rin_io.h"
// #include "rin_dnode_queue.h"
#include "usart.h"


// U8 flag_o;
// dnode_t dhead_o;

// RinOS's itoa function.
void r_itoa(S32 n, U8* str, U32 radix)
{
    S32 i, j, remain;
    U8 tmp;

    i = 0;
    do
    {
        remain = n % radix;
        if(remain > 9)
        {
            *(str + i) = remain - 10 + 'A';
        }
        else
        {
            *(str + i) = remain + '0';
        }
        i++;
    } while(n /= radix);

    str[i] = '\0';

    for(i--, j = 0; j <= i; j++, i--)
    {
        tmp = *(str + j);
        *(str + j) = *(str + i);
        *(str + i) = tmp;
    }
}

// Output without time manage.
U32 rout(const U8 *fmt, ...)
{
    U8 c, ch, *str;
    va_list ap;

    va_start(ap, fmt);
    while(c = *fmt)
    {
        switch(c)
        {
            case '%':
            {
                ch = *(++fmt);
                switch(ch)
                {
                    case 'd':
                    {
                        S32 n = va_arg(ap, S32);
                        itoa(n, str, 10);
                        _write_U8(str[0]);
                        _write(str, 1);
                        break;
                    }
                    case 'x':
                    {
                        U32 n = va_arg(ap, U32);
                        r_itoa(n, str, 16);
                        _write(str, sizeof(str));
                        break;
                    }
                    case 'f':
                    {
                        double f = va_arg(ap, double);
                        U32 n;
                        n = f;
                        r_itoa(n ,str, 10);
                        _write(str, sizeof(str));
                        _write_U8('.');
                        n = (f - n) * 1000000;
                        r_itoa(n, str, 10);
                        _write(str, sizeof(str));
                        break;
                    }
                    case 'c':
                    {
                        _write_U8(va_arg(ap, U32));
                        break;
                    }
                    case 's':
                    {
                        U8 *p = va_arg(ap, char *);
                        _write(p, sizeof(p));
                        break;
                    }
                    case '%':
                    {
                        _write_U8('%');
                        break;
                    }
                    default:
                    {
                        _write("[IO error]: format invalid!", sizeof("[IO error]: format invalid!"));
                        break;
                    }
                }
                break;
            }
            default:
            {
                _write_U8(c);
                break;
            }
        }
        fmt++;
    }
    va_end(ap);
}

// // Output with rtos time manage.
// U32 rtout(const U8 *fmt, ...)
// {

// }


// void task_PRINT(void* param)
// {
//     DNODE_p curr;
//     TCB_p   tcb_p;
//     PIPE_p  pipe_p;

//     curr = dhead_o.next;

//     while(1)
//     {
//         if(curr != &dhead_o)
//         {
//             tcb_p  = CONTAINER_OF(curr, TCB_t, dnd_o);
//             pipe_p = &tcb_p->pipe_o;

//             //if(pipe_P->length)
//             //{
//                    //UART1->DR = '#';
//             //}
//             send_not_over:
//             if(pipe->length)
//             {
//                 retry:
//                 if((serial_p->SR & 0x40) == 0)
//                 {

//                 }
//             }
//         }
//     }
// }