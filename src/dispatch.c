#include "dispatch.h"


void dispatch(void)
{
	for(uint32_t i = 0;i < 3;++i)
	{	
		uint32_t mask = enabled_irqs[i];
		while(mask != 0)
		{
			uint32_t bit = first_set_bit(mask);
			mask ^= (1 << bit);
			check_irq_pending(bit + (i << 5));
		}
	}
}

void check_irq_pending(uint32_t irq_num)
{
	bool handled = FALSE;
	if(irq_num >= 64)
	{
		if(regs->irq_basic_pending & (1 << (irq_num - 64)))
		{
			handled = TRUE;
		}
	}
	else if(irq_num >= 32)
	{
		if(regs->irq_pending_2 & (1 << (irq_num - 32)))
		{
			handled = TRUE;
		}
	}
	else
	{
		if(regs->irq_pending_1 & (1 << irq_num))
		{
			handled = TRUE;
		}
	}

	if(handled)
	{
		handle_irq(irq_num);
	}
}

void handle_irq(uint32_t irq_num)
{
	interrupt_handler_t handler = handler_vector[irq_num];
	if(handler)
	{
		handler();
	}
	else
	{
		uart_puts_nl("Kernel Panic ! Can't handle this interrupt !");
		halt();
	}
}

void enable_irq(uint32_t irq_num)
{
	if(irq_num < 32)
	{
		regs->enable_irqs_1 = (1 << irq_num);
		enabled_irqs[0] |= (1 << irq_num);
	}
	else if(irq_num < 64)
	{
		regs->enable_irqs_2 = (1 << (irq_num - 32));
		enabled_irqs[1] |= (1 << (irq_num - 32));
	}
	else
	{
		regs->enable_basic_irqs = (1 << (irq_num - 64));
		enabled_irqs[2] |= (1 << (irq_num - 64));
	}
}

void disable_irq(uint32_t irq_num)
{
	if(irq_num < 32)
	{
		regs->disable_irqs_1 = (1 << irq_num);
		enabled_irqs[0] &= ~(1 << irq_num);
	}
	else if(irq_num < 64)
	{
		regs->disable_irqs_2 = (1 << (irq_num - 32));
		enabled_irqs[1] &= ~(1 << (irq_num - 32));
	}
	else
	{
		regs->disable_basic_irqs = (1 << (irq_num - 64));
		enabled_irqs[2] &= ~(1 << (irq_num - 64));
	}
}

void init_irq(void)
{
	enabled_irqs[0] = 0x00;
	enabled_irqs[1] = 0x00;
	enabled_irqs[2] = 0x00;
	for(int i = 0;i < IRQ_NUM;i++)
	{
		handler_vector[i] = NULL;
	}
	handler_vector[1] = &timer1_handler;

	uart_write_nl(timer_regs->timer_cs, Bin);
	timer_regs->timer_cs = 7;
	uart_write_nl(timer_regs->timer_cs, Bin);

}

void timer1_handler(void)
{
	timer_regs->timer_cs = (1 << 1);
	timer_regs->timer_c1 += 1000;
}