#include <stddef.h>
#include <stdint.h>

#include "include/register.h"
#include "include/define.h"
#include "include/uart.h"
#include "include/util.h"
#include "include/exception_handler.h"
#include "include/svc.h"

void activate(uint32_t* stack);

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
	(void)r0;
	(void)r1;
	(void)atags;

	uart_init();
	uart_puts("Test a 115000 bauds - 2\r\n");
	//print_memory(0x7000, 0x400);
	dump_register();

	while(1)
	{
		while(uart_available())
		{
			uart_putc(uart_getc());
		}
	}
}