#include "include/uart.h"

unsigned char uart_getc()
{
	while(GET32(UART0_FR) & (1 << 4));
	return GET32(UART0_DR);
}

uint32_t uart_available()
{
	return (GET32(UART0_FR) | ~(1 << 4));
}

void uart_putc(unsigned char c)
{
	while(GET32(UART0_FR) & (1 << 5));
	PUT32(UART0_DR, (uint32_t)c);
}

void uart_write_buffer(const unsigned char* buffer, size_t size)
{
	for(size_t i = 0;i < size;++i)
	{
		uart_putc(*(buffer + i));
	}
}

void uart_write_nl(const uint32_t value, uint32_t mode)
{
	uart_write(value, mode);
	uart_newline();
}

void uart_write(const uint32_t value, uint32_t mode)
{
	if(mode == Hex)
	{
		_uart_write_hex(value);
	}
	else if(mode == Dec)
	{
		_uart_write_dec(value);
	}
	else if(mode == Bin)
	{
		_uart_write_bin(value);
	}
	else
		return;
}

void _uart_write_hex(const uint32_t data)
{
	char buffer[11];
	char symbol[] = "0123456789ABCDEF";
	uint32_t a;
	uint32_t number;

	number = data;
	buffer[10] = 0;
	buffer[0] = '0';
	buffer[1] = 'x';

	for(uint32_t i = 0;i < 8;++i)
	{
		a = number & 0xF;
		buffer[9 - i] = symbol[a];
		number = (number >> 4);
	}

	uart_write_buffer((const unsigned char*)buffer, strlen(buffer));

	return;
}

void _uart_write_dec(const uint32_t data)
{
	char buffer[11];
	char symbol[] = "0123456789";
	uint32_t a;
	uint32_t number;

	number = data;
	buffer[10] = 0;

	for(uint32_t i = 0;i < 10;++i)
	{
		a = (number % 10);
		buffer[9 - i] = symbol[a];
		number = (number / 10);
	}

	uart_write_buffer((const unsigned char*)buffer, strlen(buffer));

	return;
}

void _uart_write_bin(const uint32_t data)
{
	char buffer[35];
	char symbol[] = "01";
	uint32_t a;
	uint32_t number;

	number = data;
	buffer[34] = 0;
	buffer[0] = '0';
	buffer[1] = 'b';

	for(uint32_t i = 0;i < 32;++i)
	{
		a = (number & 0x1);
		buffer[33 - i] = symbol[a];
		number = (number >> 1);
	}

	uart_write_buffer((const unsigned char*)buffer, strlen(buffer));

	return;
}

void uart_newline()
{
	uart_puts("\r\n");
}

void uart_puts(const char* str)
{
	uart_write_buffer((const unsigned char*)str, strlen(str));
}

void uart_init()
{
	PUT32(GPPUD, 0x00);													/* Set no pull-up/down */
	delay(150);

	PUT32(GPPUDCLK0, (1 << 14) | (1 << 15));							/* For pins 14 and 15 */
	delay(150);

	PUT32(GPPUDCLK0, 0x00);												/* Make it takes effect */

	PUT32(GPFSEL1, (4 << 12) | (4 << 15));								/* Use alternate function 0 */

	PUT32(UART0_CR, 0x00);												/* Disable UART */

	PUT32(UART0_ICR, 0x7FF);

	PUT32(UART0_IBRD, 1);												/* Set baud rate d = UART_CLOCK / (16 * BAUD_RATE) */
	PUT32(UART0_FBRD, 40);

	PUT32(UART0_LCRH, (1 << 4)|(1 << 5)|(1 << 6));

	PUT32(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
	                       (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));	/* Disable all interrupts */

	PUT32(UART0_CR, (1 << 0)|(1 << 8)|(1 << 9));						/* Enable TX/RX*/
}

void print_memory(uint32_t begin_address, uint32_t length)
{
	if(begin_address + length > 0x20000000)
		return;

	for(uint32_t i = 0;i < length;++i)
	{
		uint32_t* p_current_value = (uint32_t*)(begin_address + i * 4);
		uart_puts("Address ");
		uart_write(begin_address + i * 4, Hex);
		uart_puts(": ");
		uart_write(*p_current_value, Hex);
		uart_newline();
	}
}

void dump_register()
{
	uart_puts("Etat des registres:\r\n");
	dump_register_asm();
	uart_puts("Register r0: ");
	uart_write_nl(*r0_reg, Hex);
	uart_puts("Register r1: ");
	uart_write_nl(*r1_reg, Hex);
	uart_puts("Register r2: ");
	uart_write_nl(*r2_reg, Hex);
	uart_puts("Register r3: ");
	uart_write_nl(*r3_reg, Hex);
	uart_puts("Register r4: ");
	uart_write_nl(*r4_reg, Hex);
	uart_puts("Register r5: ");
	uart_write_nl(*r5_reg, Hex);
	uart_puts("Register r6: ");
	uart_write_nl(*r6_reg, Hex);
	uart_puts("Register r7: ");
	uart_write_nl(*r7_reg, Hex);
	uart_puts("Register r8: ");
	uart_write_nl(*r8_reg, Hex);
	uart_puts("Register r9: ");
	uart_write_nl(*r9_reg, Hex);
	uart_puts("Register r10: ");
	uart_write_nl(*r10_reg, Hex);
	uart_puts("Register r11: ");
	uart_write_nl(*r11_reg, Hex);
	uart_puts("Register r12: ");
	uart_write_nl(*r12_reg, Hex);
	uart_puts("Register r13: ");
	uart_write_nl(*r13_reg, Hex);
	uart_puts("Register r14: ");
	uart_write_nl(*r14_reg, Hex);
	uart_puts("Register r15: ");
	uart_write_nl(*r15_reg, Hex);
	uart_puts("Register CPSR: ");
	uart_write_nl(*cpsr_reg, Bin);
}