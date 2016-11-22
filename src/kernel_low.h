#ifndef __KERNEL_LOW_H__
#define __KERNEL_LOW_H__

#include <stdint.h>

void kernel_low(uint32_t r0, uint32_t r1, uint32_t atags);

void low_kernel_init_desc(void);
#endif