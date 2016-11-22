.globl dump_register_asm

.section .data.var
.global r0_reg
.global r1_reg
.global r2_reg
.global r3_reg
.global r4_reg
.global r5_reg
.global r6_reg
.global r7_reg
.global r8_reg
.global r9_reg
.global r10_reg
.global r11_reg
.global r12_reg
.global r13_reg
.global r14_reg
.global r15_reg
.global cpsr_reg

r0_reg: .word 0
r1_reg: .word 0
r2_reg: .word 0
r3_reg: .word 0
r4_reg: .word 0
r5_reg: .word 0
r6_reg: .word 0
r7_reg: .word 0
r8_reg: .word 0
r9_reg: .word 0
r10_reg: .word 0
r11_reg: .word 0
r12_reg: .word 0
r13_reg: .word 0
r14_reg: .word 0
r15_reg: .word 0
cpsr_reg: .word 0


.section .text
dump_register_asm:
	push {r0}
	push {r1}
	ldr r1,=r0_reg
	str r0,[r1]
	pop {r1}

	ldr r0,=r1_reg
	str r1,[r0]

	ldr r0,=r2_reg
	str r2,[r0]

	ldr r0,=r3_reg
	str r3,[r0]

	ldr r0,=r4_reg
	str r4,[r0]

	ldr r0,=r5_reg
	str r5,[r0]

	ldr r0,=r6_reg
	str r6,[r0]

	ldr r0,=r7_reg
	str r7,[r0]

	ldr r0,=r8_reg
	str r8,[r0]

	ldr r0,=r9_reg
	str r9,[r0]

	ldr r0,=r10_reg
	str r10,[r0]

	ldr r0,=r11_reg
	str r11,[r0]

	ldr r0,=r12_reg
	str r12,[r0]

	ldr r0,=r13_reg
	str r13,[r0]

	ldr r0,=r14_reg
	str r14,[r0]

	ldr r0,=r15_reg
	str r15,[r0]

	push {r1}
	mrs r1, cpsr
	ldr r0,=cpsr_reg
	str r1,[r0]
	pop {r1}
	
	pop {r0}
	bx lr
