#ifndef RIN_TICK_HANDLE_H
#define RIN_TICK_HANDLE_H


#include "RinOS_kernel.h"
#include "rin_system.h"
#include "rin_tick.h"

typedef VU32 system_tick_t;

extern system_tick_t system_clock;

kernel_err init_tick_callback(void);

void tick_handle(void);

#endif /* RIN_TICK_HANDLE_H */
