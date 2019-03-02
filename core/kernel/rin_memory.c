#include "rin_memory.h"
#include "rin_cfg.h"
#include "rin_critical.h"
#include "rin_io.h"

struct _MCB
{
    VU32 count;
    VU32 pool[MEMORY_POOL_SIZE];
} MCB;

/** \brief  Initialize MCB
    This function initialize the memory pool of the divice.
    \param void
    \return void
 */
void MCB_init(void)
{
    for (U32 i = 0; i < MEMORY_POOL_SIZE; i++)
    {
        MCB.pool[i] = 0;
    }
    MCB.count = 0;
}

/** \brief  MCB get
    This function is armed to get memory.
    \param [U32] size
    \return void*
 */
void *MCB_get(U32 size)
{
    U32 temp;
    void *res;

    irq_close();

    res = (void *)&MCB.pool[MCB.count];
    temp = size;
    temp = temp >> 2;
    //    temp = temp << 2;
    MCB.count += (temp + 1);

    if (MCB.count > MEMORY_POOL_SIZE)
    {
        PRINT_ERR("Memory pool size is out of use.");
    }

    irq_restore();

    return res;
}
