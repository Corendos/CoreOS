.global irq_handler
.global dmb
.global enable_all_irq
.global disable_all_irq	

irq_handler:
	sub lr, lr, #4
	srsdb 0x1F!

	cpsid if, 0x1F

	push {r0-r3, r12, lr}

	and r4, sp, #4
	sub sp, sp, r4

	bl dmb

	bl dispatch

	bl dmb

	add sp, sp, r4

	pop {r0-r3, r12, lr}
	rfeia sp!

dmb:
	mov r12, #0
	mcr p15, 0, r12, c7, c10, 5
	bx lr

enable_all_irq:
	cpsie i
	bx lr

disable_all_irq:
	cpsid i
	bx lr
