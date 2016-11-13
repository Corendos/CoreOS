#include "include/svc.h"


void svc_call(uint32_t code)
{
	switch(code)
	{
		case 0:
			asm("push {lr}\nsvc 0x00\npop {lr}");
		break;
		case 1:
			asm("push {lr}\nsvc 0x01\npop {lr}");
		break;
		case 2:
			asm("push {lr}\nsvc 0x02\npop {lr}");
		break;
	}
}