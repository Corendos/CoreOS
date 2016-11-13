#include "include/util.h"

size_t strlen(const char* str)
{
	uint32_t count = 0;
	while(*(str + count) != 0)
	{
		count++;
	}
	return count;
}