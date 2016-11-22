#include <stddef.h>
#include <stdint.h>

#include "register.h"
#include "uart.h"
#include "util.h"
#include "exception_handler.h"
#include "irq_util.h"
#include "dispatch.h"


void kernel_main(void)
{
	uart_init();
	uart_puts_nl("======== Raspberry Pi Zero - CoreOS ========");
	uart_puts_nl("Enabling Timer 1");
	
	init_irq();


	while(1)
	{
		while(uart_available())
		{
			uart_putc(uart_getc());
		}
	}
}