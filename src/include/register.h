#ifndef __REGISTER_H__
#define __REGISTER_H__

enum{
	DR_OE = (1 << 11),
	DR_BE = (1 << 10),
	DR_PE = (1 << 9),
	DR_FE = (1 << 8),
	DR_DATA7 = (1 << 7),
	DR_DATA6 = (1 << 6),
	DR_DATA5 = (1 << 5),
	DR_DATA4 = (1 << 4),
	DR_DATA3 = (1 << 3),
	DR_DATA2 = (1 << 2),
	DR_DATA1 = (1 << 1),
	DR_DATA0 = (1 << 0)
};

enum{
	RSRECR_OE = (1 << 3),
	RSRECR_BE = (1 << 2),
	RSRECR_PE = (1 << 1),
	RSRECR_FE = (1 << 0)
};

enum{
	FR_RI = (1 << 8),
	FR_TXFE = (1 << 7),
	FR_RXFF = (1 << 6),
	FR_TXFF = (1 << 5),
	FR_RXFE = (1 << 4),
	FR_BUSY = (1 << 3),
	FR_DCD = (1 << 2),
	FR_DSR = (1 << 1),
	FR_CTS = (1 << 0)
};

enum{
	LCRH_SPS = (1 << 7),
	LCRH_WLEN1 = (1 << 6),
	LCRH_WLEN0 = (1 << 5),
	LCRH_FEN = (1 << 4),
	LCRH_STP2 = (1 << 3),
	LCRH_EPS = (1 << 2),
	LCRH_PEN = (1 << 1),
	LCRH_BRK = (1 << 0)
};

enum{
	CR_CTSEN = (1 << 15),
	CR_RTSEN = (1 << 14),
	CR_RTS = (1 << 11),
	CR_DTR = (1 << 10),
	CR_RXE = (1 << 9),
	CR_TXE = (1 << 8),
	CR_LBE = (1 << 7),
	CR_UARTEN = (1 << 0)
};

enum{
	IMSC_OEIM = (1 << 10),
	IMSC_BEIM = (1 << 9),
	IMSC_PEIM = (1 << 8),
	IMSC_FEIM = (1 << 7),
	IMSC_RTIM = (1 << 6),
	IMSC_TXIM = (1 << 5),
	IMSC_RXIM = (1 << 4),
	IMSC_DSRMIM = (1 << 3),
	IMSC_DCDMIM = (1 << 2),
	IMSC_CTSMIM = (1 << 1),
	IMSC_RIMIM = (1 << 0)
};

enum{
	ICR_OEIC = (1 << 10),
	ICR_BEIC = (1 << 9),
	ICR_PEIC = (1 << 8),
	ICR_FEIC = (1 << 7),
	ICR_RTIC = (1 << 6),
	ICR_TXIC = (1 << 5),
	ICR_RXIC = (1 << 4),
	ICR_DSRMIC = (1 << 3),
	ICR_DCDMIC = (1 << 2),
	ICR_CTSMIC = (1 << 1)
};

enum{	
		PERIPHERAL_BASE = 0x20000000,
		GPIO_BASE = PERIPHERAL_BASE + 0x200000,
		GPFSEL0 = GPIO_BASE + 0x00,
		GPFSEL1 = GPIO_BASE + 0x04,
		GPFSEL2 = GPIO_BASE + 0x08,
		GPFSEL3 = GPIO_BASE + 0x0C,
		GPFSEL4 = GPIO_BASE + 0x10,
		GPFSEL5 = GPIO_BASE + 0x14,
		GPSET0 = GPIO_BASE + 0x1C,
		GPSET1 = GPIO_BASE + 0x20,
		GPCLR0 = GPIO_BASE + 0x28,
		GPCLR1 = GPIO_BASE + 0x2C,
		GPPUD = GPIO_BASE + 0x94,
		GPPUDCLK0 = GPIO_BASE + 0x98,
		GPPUDCLK1 = GPIO_BASE + 0x9C,

		UART0_BASE = PERIPHERAL_BASE + 0x201000,
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
};

#endif