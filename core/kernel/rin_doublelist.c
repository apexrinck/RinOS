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


#include "rin_doublelist.h"
#include "stdio.h"


// doublelist head init.
void dnode_head_init(DNODE_P hd)
{
    hd->next = hd;
    hd->prev = hd;
}

// doublelist point clear.
void dnode_clear(DNODE_P nd)
{
    nd->next = NULL;
    nd->prev = NULL;
}

// Add int the head of doublelist.
void dnode_add_first(DNODE_P hd, DNODE_P nd)
{
    hd->next->prev = nd;
    nd->next       = hd->next;
    nd->prev       = hd;
    hd->next       = nd;
}

// Add int the last of doublelist.
void dnode_add_last(DNODE_P hd, DNODE_P nd)
{
    hd->prev->next = nd;
    nd->prev       = hd->prev;
    nd->next       = hd;
    nd->prev       = nd;
}

// Remove doublelist.
void dnode_remove(DNODE_P nd)
{
    nd->next->prev = nd->prev;
    nd->prev->next = nd->next;
    nd->prev       = NULL;
    nd->next       = NULL;
}

// find out is the node in list or not.
U8 dnode_inlist(DNODE_P hd, DNODE_P nd)
{
    DNODE_P curr = hd->next;
    while(curr != hd)
    {
        if(curr == nd)
        {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

// Count doublelist's pool size.
U8 dnode_getcount(DNODE_P hd)
{
    U8 res = 0;
    DNODE_P curr = hd->next;
    while(curr != hd)
    {
        res++;
        curr = curr->next;
    }
    return res;
}
