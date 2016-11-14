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
	.global	undefined_instruction_handler
	.type	undefined_instruction_handler, %function
undefined_instruction_handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.L2:
	b	.L2
	.size	undefined_instruction_handler, .-undefined_instruction_handler
	.align	2
	.global	svc_handler
	.type	svc_handler, %function
svc_handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.L4:
	b	.L4
	.size	svc_handler, .-svc_handler
	.align	2
	.global	prefetch_abort_handler
	.type	prefetch_abort_handler, %function
prefetch_abort_handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.L6:
	b	.L6
	.size	prefetch_abort_handler, .-prefetch_abort_handler
	.align	2
	.global	data_abort_handler
	.type	data_abort_handler, %function
data_abort_handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.L8:
	b	.L8
	.size	data_abort_handler, .-data_abort_handler
	.align	2
	.global	irq_handler
	.type	irq_handler, %function
irq_handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.L10:
	b	.L10
	.size	irq_handler, .-irq_handler
	.align	2
	.global	fiq_handler
	.type	fiq_handler, %function
fiq_handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.L12:
	b	.L12
	.size	fiq_handler, .-fiq_handler
	.align	2
	.global	strlen
	.type	strlen, %function
strlen:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldrb	r3, [r0]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L16
	mov	r3, r0
	mov	r0, #0
.L15:
	ldrb	r2, [r3, #1]!	@ zero_extendqisi2
	add	r0, r0, #1
	cmp	r2, #0
	bne	.L15
	bx	lr
.L16:
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
	ldr	r1, .L24
.L23:
	ldr	r3, [r1, #24]
	ldr	r2, .L24
	tst	r3, #16
	bne	.L23
	ldr	r0, [r2]
	uxtb	r0, r0
	bx	lr
.L25:
	.align	2
.L24:
	.word	538972160
	.size	uart_getc, .-uart_getc
	.align	2
	.global	uart_putc
	.type	uart_putc, %function
uart_putc:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r2, .L29
.L28:
	ldr	r3, [r2, #24]
	ldr	r1, .L29
	tst	r3, #32
	bne	.L28
	str	r0, [r1]
	bx	lr
.L30:
	.align	2
.L29:
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
.L34:
	ldrb	r0, [r4], #1	@ zero_extendqisi2
	bl	uart_putc(PLT)
	cmp	r4, r5
	bne	.L34
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
	stmfd	sp!, {r3, lr}
	ldr	r0, .L37
.LPIC8:
	add	r0, pc, r0
	bl	uart_puts(PLT)
	ldmfd	sp!, {r3, lr}
	mov	r0, #0
	b	svc_call(PLT)
.L38:
	.align	2
.L37:
	.word	.LC0-(.LPIC8+8)
	.size	user_task, .-user_task
	.align	2
	.global	uart_init
	.type	uart_init, %function
uart_init:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L40
	ldr	r1, .L40+4
	mov	r2, #0
	stmfd	sp!, {r4, r5, r6, r7}
	str	r2, [r3, #48]
	mov	r3, #150
	str	r2, [r1, #148]
@ 91 "kernel.c" 1
	__delay__197: subs r3, r3, #1; bne __delay__197

@ 0 "" 2
	ldr	r3, .L40+4
	mov	r2, #49152
	str	r2, [r3, #152]
	mov	r3, #150
@ 91 "kernel.c" 1
	__delay__202: subs r3, r3, #1; bne __delay__202

@ 0 "" 2
	ldr	r3, .L40
	ldr	r6, .L40+4
	ldr	r5, .L40+8
	ldr	r1, .L40+12
	ldr	r2, .L40+16
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
.L41:
	.align	2
.L40:
	.word	538972160
	.word	538968064
	.word	2047
	.word	2034
	.word	769
	.size	uart_init, .-uart_init
	.align	2
	.global	setup_task_stack
	.type	setup_task_stack, %function
setup_task_stack:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	sub	r1, r1, #-268435447
	mov	r3, #0
	add	r0, r0, r1, asl #4
	mov	r1, r3
.L44:
	str	r1, [r0, r3]
	add	r3, r3, #4
	cmp	r3, #32
	bne	.L44
	str	r2, [r0, #32]
	bx	lr
	.size	setup_task_stack, .-setup_task_stack
	.align	2
	.global	add
	.type	add, %function
add:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	add	r0, r0, #1
	bx	lr
	.size	add, .-add
	.align	2
	.global	kernel_main
	.type	kernel_main, %function
kernel_main:
	@ args = 0, pretend = 0, frame = 1024
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, lr}
	sub	sp, sp, #1024
	sub	sp, sp, #4
	ldr	r5, .L49
	bl	uart_init(PLT)
	ldr	r3, .L49+4
.LPIC17:
	add	r5, pc, r5
	ldr	r2, [r5, r3]
	mov	r1, #256
	mov	r0, sp
	bl	setup_task_stack(PLT)
	ldr	r0, .L49+8
.LPIC18:
	add	r0, pc, r0
	bl	uart_puts(PLT)
	mov	r0, sp
	bl	activate(PLT)
	ldr	r0, .L49+12
.LPIC19:
	add	r0, pc, r0
	bl	uart_puts(PLT)
.L48:
	b	.L48
.L50:
	.align	2
.L49:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC17+8)
	.word	user_task(GOT)
	.word	.LC1-(.LPIC18+8)
	.word	.LC2-(.LPIC19+8)
	.size	kernel_main, .-kernel_main
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"Task 1\015\012\000"
	.space	3
.LC1:
	.ascii	"Hello, world !\015\012\000"
	.space	3
.LC2:
	.ascii	"Return from the Task1\015\012\000"
	.ident	"GCC: (4.8.2-14ubuntu1+6) 4.8.2"
