#include "rin_critical.h"


U32 irq_stat[IRQ_STAT_STACK_SIZE];
U8  irq_pos;

/** \brief  Close Irq
    This function close all currrnt Irqs.
    \param void
    \return void
 */
void irq_close(void)
{
    irq_stat[irq_pos] = __get_PRIMASK();
    __disable_irq();
    irq_pos++;
    if(irq_pos > IRQ_STAT_STACK_SIZE)
    {
        printf("Error: Irq closed too many.\r\n");      // Output with standard way.
    }
}

/** \brief  Restore Irq
    This function restore all currrnt Irqs.
    \param void
    \return void
 */
vodi irq_restore(void)
{
    if(irq_pos == 0)
    {
        printf("Error: Irq restored too many.\r\n");    // Output with standard way.
    }
    __set_PRIMASK(irq_stat[irq_pos]);
}
