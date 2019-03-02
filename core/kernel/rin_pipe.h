#ifndef RIN_PIPE_H
#define RIN_PIPE_H


#include "RinOS_kernel.h"


typedef struct _pipe_t {
    U16 size;
    U8* start;

    U8* write;
    U8* read;
    VU16 length;
} PIPE_t, *PIPE_p;


void pipe_init(PIPE_p, pp, U16 sz);
void pipe_write(PIPE_p pp, U8 data);
U8 pipe_read(PIPE_p pp);


#endif /* RIN_PIPE_H */
