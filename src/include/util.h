#ifndef __UTIL_H__
#define __UTIL_H__

#include <stddef.h>
#include <stdint.h>

enum{
		Hex, Dec, Bin
};

size_t strlen(const char* str);

static inline void delay(uint32_t count)
{
	asm volatile("__delay__%=: subs %[count], %[count], #1; bne __delay__%=\n" : "=r"(count) : [count]"0"(count) : "cc");
}

extern void PUT32(uint32_t addr, uint32_t data);
extern uint32_t GET32(uint32_t addr);
extern void dump_register_asm();
extern void svc_return();

extern uint32_t*  r0_reg;
extern uint32_t*  r1_reg;
extern uint32_t*  r2_reg;
extern uint32_t*  r3_reg;
extern uint32_t*  r4_reg;
extern uint32_t*  r5_reg;
extern uint32_t*  r6_reg;
extern uint32_t*  r7_reg;
extern uint32_t*  r8_reg;
extern uint32_t*  r9_reg;
extern uint32_t*  r10_reg;
extern uint32_t*  r11_reg;
extern uint32_t*  r12_reg;
extern uint32_t*  r13_reg;
extern uint32_t*  r14_reg;
extern uint32_t*  r15_reg;
extern uint32_t*  cpsr_reg;
#endif