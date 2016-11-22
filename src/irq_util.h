#ifndef __IRQ_UTIL_H__
#define __IRQ_UTIL_H__

#define TIMER0_IRQ 0	/*Do not use this one*/
#define TIMER1_IRQ 1
#define TIMER2_IRQ 2	/*Do not use this one*/
#define TIMER3_IRQ 3

extern void enable_all_irq(void);
extern void disable_all_irq(void);

#endif