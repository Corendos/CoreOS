#include "util.h"

size_t strlen(const char* str)
{
	uint32_t count = 0;
	while(*(str + count) != 0)
	{
		count++;
	}
	return count;
}

uint32_t first_set_bit(uint32_t word)
{
	uint32_t i = 31;
	while(!(word & (1 << i)))
	{
		i--;
	}
	return i;
}