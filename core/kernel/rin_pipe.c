#include "rin_pipe.h"
#include "rin_memory.h"
#include "rin_io.h"


/** \brief  Initialize pipe(mainly for task PRINT)
    This function initialize the pipe as the fifo of the task PRINT.
    \param void
    \return [PIPE_p] pp, [U16] sz
 */
void pipe_init(PIPE_p pp, U16 sz)
{
    if(pp->start)
    {
        PRINT_ERROR("Pipe has already been init.\r\n");
        PRINT_ERROR("Or you define a pipe object instead of a pointer.\r\n");
    }

    pp->size    = sz;
    pp->start   = (U8*)MCB_get(sz);

    pp->write   = pp->start;
    pp->read    = pp->start;
    pp->length  = 0;
}

/** \brief  pipe write
    This function is write to the pipe.
    \param [PIPE_p] pp, [U8] data
    \return void
 */
void pipe_write(PIPE_p pp, U8 data)
{
     retry:
     if(pp->start == NULL)
     {
         task_delay_ms(0);
         goto retry;
     }

     pp->length++;
     *pp->write = data;
     pp->write++;

     if(pp->write == pp->start + pp ->size)
     {
         pp->write = pp->start;
     }
     if(pp->length > pp->size)
     {
         pp->length = pp->size;
         pp->read   = pp=>write;
     }
}

/** \brief  pipe read
     This function is read pipe.
     \param [pipe_p] pp
     \return [U8]
 */

U8 pipe_read(PIPE_p pp)
{
    U8 res;

    retry:
    if(pp->start == NULL)
    {
        task_delay_ms(0);
        goto retry;
    }

    if(!pp->length)
    {
        return 0;
    }
    pp->length--;
    res = *pp->read;
    pp->read++;
    if(pp->read == pp->start + pp->size)
    {
        pp->read = pp->start;
    }
    return res;
}
