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


#ifndef RIN_DOUBLELIST_H
#define RIN_DOUBLELIST_H


#include "rin_type.h"


// Support RinOS's doublelist func.
typedef struct _DNODE {
    struct _DNODE *next;
    struct _DNODE *prev;
} DNODE_T, *DNODE_P;

// The doublelist's head name.
#define DHEAD_DEFINE(name)      DNODE_t name = {&name, &name};

void dnode_head_init(DNODE_P hd);
void dnode_clear(DNODE_P nd);
void dnode_add_first(DNODE_P hd, DNODE_P nd);
void dnode_add_last(DNODE_P hd, DNODE_P nd);
void dnode_remove(DNODE_P nd);
U8   dnode_inlist(DNODE_P hd, DNODE_P nd);
U8   dnode_getcount(DNODE_P hd);

#endif /* RIN_DOUBLELIST_H */
