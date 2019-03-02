#include "rin_tick_handle.h"


volatile system_tick_t system_clock;

kernel_err init_tick_callback(void)
{
    tick_callback = tick_handle;

    return kernel_noerr;
}

void keep_clock_awake(U32 clock)
{
    clock = clock;
}

void tick_handle(void)
{
    volatile dnode_p curr, pdnd;
    p_TCB ptcb;

    irq_close();

    //keep kernel clock acwake
    //keep_clock_awake(system_clock);
    system_clock++;

    #ifndef DEBUG_TICK
        if(!(system_clock % 1000))
        {
            printf("%d: tick\r\n", system_clock);
        }
    #endif

}
