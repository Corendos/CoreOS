#ifndef __STACK_H__
#define __STACK_H__

#include <stdint.h>

typedef struct process
{
	uint32_t user_stack[256];
	uint32_t stack_pointer;
}process;

#endif