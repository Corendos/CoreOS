.section .data
kernel_stack_pointer: .word 1
.global kernel_stack_pointer

.section .text.boot /* Give a name to this section*/
.globl _start



_start:
	mov sp, #0x8000 /* We set the SP to 0x8000 */
	bl kernel_main

.globl GET32

GET32:
	ldr r0, [r0]
	bx lr

.globl PUT32

PUT32:
	str r1, [r0]
	bx lr

halt:
	b halt
	