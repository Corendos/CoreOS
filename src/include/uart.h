#ifndef __UART_H__
#define __UART_H__

#include <stddef.h>
#include <stdint.h>

#include "util.h"
#include "register.h"
#include "define.h"

unsigned char uart_getc();
uint32_t uart_available();
void uart_putc(unsigned char c);
void uart_write_buffer(const unsigned char* buffer, size_t size);
void uart_write(const uint32_t value, uint32_t mode);
void uart_puts(const char* str);
void uart_init();
void _uart_write_hex(const uint32_t data);
void _uart_write_dec(const uint32_t data);
void _uart_write_bin(const uint32_t data);
void uart_newline();
void print_memory(uint32_t begin_address, uint32_t length);
void dump_register();

#endif