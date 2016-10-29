#include <stdint.h>

uint32_t var[10];

void test(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
	var[0] = a;
	var[1] = b;
	var[2] = c;
	var[3] = d;
	var[4] = e;
}