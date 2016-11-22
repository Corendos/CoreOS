.global activate_mmu

.extern first_level_entries
.extern kernel_main

.section .text.low_kernel
activate_mmu:
	ldr r0, =first_level_entries
	sub r0, r0, #0x80000000
	mcr p15, 0, r0, c2, c0, 1
	mov r0, #3
	mcr p15, 0, r0, c3, c3, 0
	mrc p15, 0, r0, c1, c0, 0
	orr r0, r0, #1
	mcr p15, 0, r0, c1, c0, 0
	ldr pc, =kernel_main
