#ifndef __DISPATCH_H__
#define __DISPATCH_H__

#include "uart.h"
#include "util.h"

#define IRQ_NUM 96

void dispatch(void);
void check_irq_pending(uint32_t irq_num);
void handle_irq(uint32_t irq_num);
void init_irq(void);
void enable_irq(uint32_t irq_num);
void disable_irq(uint32_t irq_num);
void timer1_handler(void);

extern void halt(void);

struct interrupt_register
{
	uint32_t irq_basic_pending;
	uint32_t irq_pending_1;
	uint32_t irq_pending_2;
	uint32_t fiq_control;
	uint32_t enable_irqs_1;
	uint32_t enable_irqs_2;
	uint32_t enable_basic_irqs;
	uint32_t disable_irqs_1;
	uint32_t disable_irqs_2;
	uint32_t disable_basic_irqs;
};

struct timer_register
{
	uint32_t timer_cs;
	uint32_t timer_clo;
	uint32_t timer_chi;
	uint32_t timer_c0;
	uint32_t timer_c1;
	uint32_t timer_c2;
	uint32_t timer_c3;
};

uint32_t enabled_irqs[3]; 						/*Store the enabled irqs*/
interrupt_handler_t handler_vector[IRQ_NUM];	/*Store handling functions*/

static volatile struct interrupt_register* const regs = (volatile struct interrupt_register*)IRQ_BASE;
static volatile struct timer_register* const timer_regs = (volatile struct timer_register*)TIMER_BASE;

#endif