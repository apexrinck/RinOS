#ifndef RIN_TICK_H
#define RIN_TICK_H

#include "RinOS_kernel.h"


typedef void (*tick_callback_t)(void);
extern tick_callback_t tick_callback;


void tick_init(int ms);
void tick_start(void);


#endif /* RIN_TICK_H */
