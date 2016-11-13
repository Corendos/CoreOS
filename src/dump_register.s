.globl dump_register_asm
.extern uart_write
.extern uart_newline

dump_register_asm:
	push {r0, r1, lr}
	mov r1, #0
	bl uart_write
	bl uart_newline

	pop {r1}
	mov r0, r1
	push {r1}
	mov r1, #0
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r2
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r3
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r4
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r5
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r6
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r7
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r8
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r9
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r10
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r11
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r12
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r13
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r14
	bl uart_write
	bl uart_newline

	mov r1, #0
	mov r0, r15
	bl uart_write
	bl uart_newline

	pop {r0, r1, lr}
	bx lr
