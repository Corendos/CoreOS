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

#endif