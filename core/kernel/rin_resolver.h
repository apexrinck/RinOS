#ifndef RIN_RESOLVER_H
#define RIN_RESOLVER_H

#include "RinOS_kernel.h"

#include "rin_pipe.h"
#include "rin_schedule.h"
#include "rin_system.h"
#include "rin_task.h"

/*
 * Input format: func_name(U32_param)
 * For example: cpu(0)
 */
typedef void (*resolve_t)(U32 param);

typedef struct _RESOLVE_T {
  DNODE_t dnd;
  U8 *name;
  resolve_t *resolve_p;
} RESOLVE_t, *RESOLVE_t;

extern DNODE_t dhead_resolve;
extern PIPE_t pipe_resolve;

void USART1_IRQ_init(void);

#endif /* RIN_RESOLVER_H */