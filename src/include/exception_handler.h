#ifndef __EXCEPTION_HANDLER_H__
#define __EXCEPTION_HANDLER_H__

#include "uart.h"

void undefined_instruction_handler(void);
void svc_handler(void);
void prefetch_abort_handler(void);
void data_abort_handler(void);
void irq_handler(void);
void fiq_handler(void);

#endif