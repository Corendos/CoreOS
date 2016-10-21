#include "stddef.h"
#include "stdint.h"

static inline void mmio_write(uint32_t reg, uint32_t data)
{
	*(volatile uint32_t*)reg = data;
}

static inline uint32_t mmio_read(uint32_t reg)
{
	return *(volatile uint32_t*)reg;
}

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
	mmio_write(10, 0);
	while(1);
}