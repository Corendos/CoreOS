#include "stddef.h"
#include "stdint.h"

enum{	GPIO_BASE = 0x20200000,
		GPFSEL0 = GPIO_BASE + 0x00,
		GPFSEL1 = GPIO_BASE + 0x04,
		GPFSEL2 = GPIO_BASE + 0x08,
		GPFSEL3 = GPIO_BASE + 0x0C,
		GPFSEL4 = GPIO_BASE + 0x10,
		GPFSEL5 = GPIO_BASE + 0x14,
		GPSET0 = GPIO_BASE + 0x1C,
		GPSET1 = GPIO_BASE + 0x20,
		GPCLR0 = GPIO_BASE + 0x28,
		GPCLR0 = GPIO_BASE + 0x2C;
		GPPUD = GPIO_BASE + 0x94,
		GPPUDCLK0 = GPIO_BASE + 0x98,
		GPPUDCLK1 = GPIO_BASE + 0x9C,

		UART0_BASE = 0x20201000,
		UART0_DR = UART0_BASE + 0x00,
		UART0_RSRECR = UART0_BASE + 0x04,
		UART0_FR = UART0_BASE + 0x18,
		UART0_ILPR = UART0_BASE + 0x20,
		UART0_IBRD = UART0_BASE + 0x24,
		UART0_FBRD = UART0_BASE + 0x28,
		UART0_LCRH = UART0_BASE + 0x2C,
		UART0_CR = UART0_BASE + 0x30,
		UART0_IFLS = UART0_BASE + 0x34,
		UART0_IMSC = UART0_BASE + 0x38,
		UART0_RIS = UART0_BASE + 0x3C,
		UART0_MIS = UART0_BASE + 0x40,
		UART0_ICR = UART0_BASE + 0x44,
		UART0_DMACR = UART0_BASE + 0x48,
		UART0_ITCR = UART0_BASE + 0x80,
		UART0_ITIP = UART0_BASE + 0x84,
		UART0_ITOP = UART0_BASE + 0x88,
		UART0_TDR = UART0_BASE + 0x8C

}


static inline void mmio_write(uint32_t reg, uint32_t data)
{
	*(volatile uint32_t*)reg = data;
}

static inline uint32_t mmio_read(uint32_t reg)
{
	return *(volatile uint32_t*)reg;
}

static inline void delay(uint32_t count)
{
	asm volatile("__delay__%=: subs %[count], %[count], #1; bne __delay__%=\n" : "=r"(count) : [count]"0"(count) : "cc");
}

void uart_init()
{
	mmio_write(UART0_CR, 0x00);


	mmio_write(GPPUD, 0x00);
	delay(150);
	mmio_write(GPPUDCLK0, (1 << 14) | (1 << 15));
	delay(150);
	mmio_write(GPPUDCLK0, 0x00);

	mmio_write(UART0_ICR, 0x7FF);

	mmio_write(UART0_IBRD, 1);
	mmio_write(UART0_FBRD, 40);

	mmio_write(UART0_LCRH, (1 << 4)|(1 << 5)|(1 << 6));

	mmio_write(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
	                       (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));

	mmio_write(UART0_CR, (1 << 0)|(1 << 8)|(1 << 9));
}

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
	uart_init();
	
	while(1);
}