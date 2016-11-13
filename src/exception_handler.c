#include "include/exception_handler.h"

void undefined_instruction_handler(void)
{
	while(1);
}

void svc_handler(void)
{
	uint32_t value;
	asm volatile("str r0, %[value]\n":[value]"+m"(value));
	uart_puts("SVC handler n: ");
	uart_write(value, Hex);
	uart_newline();
}

void prefetch_abort_handler(void)
{
	uart_puts("Prefetch Abort Handler\r\n");
}

void data_abort_handler(void)
{
	uart_puts("Data Abort Handler\r\n");
}

void irq_handler(void)
{
	uart_puts("IRQ Handler\r\n");
}

void fiq_handler(void)
{
	uart_puts("FIQ Handler\r\n");
}