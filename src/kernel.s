	.cpu arm1176jzf-s
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"kernel.c"
	.text
	.align	2
	.global	strlen
	.type	strlen, %function
strlen:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldrb	r3, [r0]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L4
	mov	r3, r0
	mov	r0, #0
.L3:
	ldrb	r2, [r3, #1]!	@ zero_extendqisi2
	add	r0, r0, #1
	cmp	r2, #0
	bne	.L3
	bx	lr
.L4:
	mov	r0, r3
	bx	lr
	.size	strlen, .-strlen
	.align	2
	.global	uart_getc
	.type	uart_getc, %function
uart_getc:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r1, .L12
.L11:
	ldr	r3, [r1, #24]
	ldr	r2, .L12
	tst	r3, #16
	bne	.L11
	ldr	r0, [r2]
	uxtb	r0, r0
	bx	lr
.L13:
	.align	2
.L12:
	.word	538972160
	.size	uart_getc, .-uart_getc
	.align	2
	.global	uart_putc
	.type	uart_putc, %function
uart_putc:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r2, .L17
.L16:
	ldr	r3, [r2, #24]
	ldr	r1, .L17
	tst	r3, #32
	bne	.L16
	str	r0, [r1]
	bx	lr
.L18:
	.align	2
.L17:
	.word	538972160
	.size	uart_putc, .-uart_putc
	.align	2
	.global	uart_write
	.type	uart_write, %function
uart_write:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	cmp	r1, #0
	stmfd	sp!, {r3, r4, r5, lr}
	ldmeqfd	sp!, {r3, r4, r5, pc}
	mov	r4, r0
	add	r5, r0, r1
.L22:
	ldrb	r0, [r4], #1	@ zero_extendqisi2
	bl	uart_putc(PLT)
	cmp	r4, r5
	bne	.L22
	ldmfd	sp!, {r3, r4, r5, pc}
	.size	uart_write, .-uart_write
	.align	2
	.global	uart_puts
	.type	uart_puts, %function
uart_puts:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	mov	r4, r0
	bl	strlen(PLT)
	mov	r1, r0
	mov	r0, r4
	ldmfd	sp!, {r4, lr}
	b	uart_write(PLT)
	.size	uart_puts, .-uart_puts
	.align	2
	.global	user_task
	.type	user_task, %function
user_task:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r0, .L25
.LPIC8:
	add	r0, pc, r0
	b	uart_puts(PLT)
.L26:
	.align	2
.L25:
	.word	.LC0-(.LPIC8+8)
	.size	user_task, .-user_task
	.align	2
	.global	uart_init
	.type	uart_init, %function
uart_init:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L28
	ldr	r1, .L28+4
	mov	r2, #0
	stmfd	sp!, {r4, r5, r6, r7}
	str	r2, [r3, #48]
	mov	r3, #150
	str	r2, [r1, #148]
@ 56 "/home/corendos/Documents/Programmation/Projets/CoreOS/src/kernel.c" 1
	__delay__144: subs r3, r3, #1; bne __delay__144

@ 0 "" 2
	ldr	r3, .L28+4
	mov	r2, #49152
	str	r2, [r3, #152]
	mov	r3, #150
@ 56 "/home/corendos/Documents/Programmation/Projets/CoreOS/src/kernel.c" 1
	__delay__149: subs r3, r3, #1; bne __delay__149

@ 0 "" 2
	ldr	r3, .L28
	ldr	r6, .L28+4
	ldr	r5, .L28+8
	ldr	r1, .L28+12
	ldr	r2, .L28+16
	mov	r7, #0
	mov	r4, #1
	mov	ip, #40
	mov	r0, #112
	str	r7, [r6, #152]
	str	r5, [r3, #68]
	str	r4, [r3, #36]
	str	ip, [r3, #40]
	ldmfd	sp!, {r4, r5, r6, r7}
	str	r0, [r3, #44]
	str	r1, [r3, #56]
	str	r2, [r3, #48]
	bx	lr
.L29:
	.align	2
.L28:
	.word	538972160
	.word	538968064
	.word	2047
	.word	2034
	.word	769
	.size	uart_init, .-uart_init
	.align	2
	.global	kernel_main
	.type	kernel_main, %function
kernel_main:
	@ args = 0, pretend = 0, frame = 1024
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	ldr	r3, .L32
	ldr	r2, .L32+4
.LPIC9:
	add	r3, pc, r3
	sub	sp, sp, #1024
	sub	sp, sp, #4
	ldr	r2, [r3, r2]
	add	r0, sp, #1024
	str	r2, [r0, #-1024]!
	mov	r0, sp
	bl	activate(PLT)
	bl	uart_init(PLT)
	ldr	r0, .L32+8
.LPIC10:
	add	r0, pc, r0
	bl	uart_puts(PLT)
.L31:
	b	.L31
.L33:
	.align	2
.L32:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC9+8)
	.word	user_task(GOT)
	.word	.LC1-(.LPIC10+8)
	.size	kernel_main, .-kernel_main
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"Task 1\015\012\000"
	.space	3
.LC1:
	.ascii	"Hello, world !\015\012\000"
	.ident	"GCC: (4.8.2-14ubuntu1+6) 4.8.2"
