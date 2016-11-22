#ifndef __REGISTER_H__
#define __REGISTER_H__

#define DR_OE (1 << 11)
#define DR_BE (1 << 10)
#define DR_PE (1 << 9)
#define DR_FE (1 << 8)
#define DR_DATA7 (1 << 7)
#define DR_DATA6 (1 << 6)
#define DR_DATA5 (1 << 5)
#define DR_DATA4 (1 << 4)
#define DR_DATA3 (1 << 3)
#define DR_DATA2 (1 << 2)
#define DR_DATA1 (1 << 1)
#define DR_DATA0 (1 << 0)

#define RSRECR_OE (1 << 3)
#define RSRECR_BE (1 << 2)
#define RSRECR_PE (1 << 1)
#define RSRECR_FE (1 << 0)

#define FR_RI (1 << 8)
#define FR_TXFE (1 << 7)
#define FR_RXFF (1 << 6)
#define FR_TXFF (1 << 5)
#define FR_RXFE (1 << 4)
#define FR_BUSY (1 << 3)
#define FR_DCD (1 << 2)
#define FR_DSR (1 << 1)
#define FR_CTS (1 << 0)

#define LCRH_SPS (1 << 7)
#define LCRH_WLEN1 (1 << 6)
#define LCRH_WLEN0 (1 << 5)
#define LCRH_FEN (1 << 4)
#define LCRH_STP2 (1 << 3
#define LCRH_EPS (1 << 2)
#define LCRH_PEN (1 << 1)
#define LCRH_BRK (1 << 0)

#define CR_CTSEN (1 << 15)
#define CR_RTSEN (1 << 14)
#define CR_RTS (1 << 11)
#define CR_DTR (1 << 10)
#define CR_RXE (1 << 9)
#define CR_TXE (1 << 8)
#define CR_LBE (1 << 7)
#define CR_UARTEN (1 << 0)

#define IMSC_OEIM (1 << 10)
#define IMSC_BEIM (1 << 9)
#define IMSC_PEIM (1 << 8)
#define IMSC_FEIM (1 << 7)
#define IMSC_RTIM (1 << 6)
#define IMSC_TXIM (1 << 5)
#define IMSC_RXIM (1 << 4)
#define IMSC_DSRMIM (1 << 3)
#define IMSC_DCDMIM (1 << 2)
#define IMSC_CTSMIM (1 << 1)
#define IMSC_RIMIM (1 << 0)

#define ICR_OEIC (1 << 10)
#define ICR_BEIC (1 << 9)
#define ICR_PEIC (1 << 8)
#define ICR_FEIC (1 << 7)
#define ICR_RTIC (1 << 6)
#define ICR_TXIC (1 << 5)
#define ICR_RXIC (1 << 4)
#define ICR_DSRMIC (1 << 3)
#define ICR_DCDMIC (1 << 2)
#define ICR_CTSMIC (1 << 1)

#define PERIPHERAL_BASE 0x20000000
#define GPIO_BASE PERIPHERAL_BASE + 0x200000
#define GPFSEL0 GPIO_BASE + 0x00
#define GPFSEL1 GPIO_BASE + 0x04
#define GPFSEL2 GPIO_BASE + 0x08
#define GPFSEL3 GPIO_BASE + 0x0C
#define GPFSEL4 GPIO_BASE + 0x10
#define GPFSEL5 GPIO_BASE + 0x14
#define GPSET0 GPIO_BASE + 0x1C
#define GPSET1 GPIO_BASE + 0x20
#define GPCLR0 GPIO_BASE + 0x28
#define GPCLR1 GPIO_BASE + 0x2C
#define GPPUD GPIO_BASE + 0x94
#define GPPUDCLK0 GPIO_BASE + 0x98
#define GPPUDCLK1 GPIO_BASE + 0x9C

#define UART0_BASE PERIPHERAL_BASE + 0x201000
#define UART0_DR UART0_BASE + 0x00
#define UART0_RSRECR UART0_BASE + 0x04
#define UART0_FR UART0_BASE + 0x18
#define UART0_ILPR UART0_BASE + 0x20
#define UART0_IBRD UART0_BASE + 0x24
#define UART0_FBRD UART0_BASE + 0x28
#define UART0_LCRH UART0_BASE + 0x2C
#define UART0_CR UART0_BASE + 0x30
#define UART0_IFLS UART0_BASE + 0x34
#define UART0_IMSC UART0_BASE + 0x38
#define UART0_RIS UART0_BASE + 0x3C
#define UART0_MIS UART0_BASE + 0x40
#define UART0_ICR UART0_BASE + 0x44
#define UART0_DMACR UART0_BASE + 0x48
#define UART0_ITCR UART0_BASE + 0x80
#define UART0_ITIP UART0_BASE + 0x84
#define UART0_ITOP UART0_BASE + 0x88
#define UART0_TDR UART0_BASE + 0x8C

#define IRQ_BASE PERIPHERAL_BASE + 0xB200

#define TIMER_BASE PERIPHERAL_BASE + 0x3000
#define TIMER_CS TIMER_BASE + 0x00
#define TIMER_CLO TIMER_BASE + 0x04
#define TIMER_CHI TIMER_BASE + 0x08
#define TIMER_C0 TIMER_BASE + 0x0C
#define TIMER_C1 TIMER_BASE + 0x10
#define TIMER_C2 TIMER_BASE + 0x14
#define TIMER_C3 TIMER_BASE + 0x18

#endif