#include <stddef.h>
#include <stdint.h>

#include "register.h"

void activate(uint32_t* stack);
void svc_call(uint32_t code);

void undefined_instruction_handler(void)
{
	while(1);
}

void svc_handler(void)
{
	while(1);
}

void prefetch_abort_handler(void)
{
	while(1);
}

void data_abort_handler(void)
{
	while(1);
}

void irq_handler(void)
{
	while(1);
}

void fiq_handler(void)
{
	while(1);
}

extern void PUT32(uint32_t addr, uint32_t data);
extern uint32_t GET32(uint32_t addr);

static inline void delay(uint32_t count)
{
	asm volatile("__delay__%=: subs %[count], %[count], #1; bne __delay__%=\n" : "=r"(count) : [count]"0"(count) : "cc");
}

size_t strlen(const char* str)
{
	uint32_t count = 0;
	while(*(str + count) != 0)
	{
		count++;
	}
	return count;
}

unsigned char uart_getc()
{
	while(GET32(UART0_FR) & (1 << 4));
	return GET32(UART0_DR);
}

void uart_putc(unsigned char c)
{
	while(GET32(UART0_FR) & (1 << 5));
	PUT32(UART0_DR, (uint32_t)c);
}

void uart_write(const unsigned char* buffer, size_t size)
{
	for(size_t i = 0;i < size;++i)
	{
		uart_putc(*(buffer + i));
	}
}

void uart_puts(const char* str)
{
	uart_write((const unsigned char*)str, strlen(str));
}

void uart_init()
{


	PUT32(GPPUD, 0x00);
	delay(150);

	PUT32(GPPUDCLK0, (1 << 14) | (1 << 15));
	delay(150);

	PUT32(GPPUDCLK0, 0x00);

	PUT32(GPFSEL1, (4 << 12) | (4 << 15));

	PUT32(UART0_CR, 0x00);

	PUT32(UART0_ICR, 0x7FF);

	PUT32(UART0_IBRD, 19);
	PUT32(UART0_FBRD, 34);

	PUT32(UART0_LCRH, (1 << 4)|(1 << 5)|(1 << 6));

	PUT32(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
	                       (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));

	PUT32(UART0_CR, (1 << 0)|(1 << 8)|(1 << 9));
}

void user_task(void)
{
	uart_puts("Task 1\r\n");
	svc_call(0);
}

void setup_task_stack(uint32_t *stack_start, uint32_t stack_size, uint32_t task_adress)
{
	uint32_t* stack_current = stack_start + stack_size * sizeof(uint32_t) - 9 * sizeof(uint32_t);

	for(int i = 0;i < 8;++i)
	{
		stack_current[i] = 0;
	}
	stack_current[8] = (uint32_t)task_adress;
}

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
	(void) r0;
	(void) r1;
	(void) atags;

	uart_init();

	PUT32(GPFSEL0, 1 << 15);

	while(1)
	{
		PUT32(GPSET0, 1 << 5);
		delay(5000000);
		PUT32(GPCLR0, 1 << 5);
		delay(5000000);
		uart_puts("Hello, world!\r\n");
	}
	

	//uart_init();

	//uint32_t user_stack[256];
	//setup_task_stack(user_stack, 256, (uint32_t)user_task);

	//uart_puts("Hello, world !\r\n");

	//activate(user_stack);

	//uart_puts("Return from the Task1\r\n");	
	while(1);
}