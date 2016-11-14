.globl dump_register_asm
.extern r0_reg
.extern r1_reg
.extern r2_reg
.extern r3_reg
.extern r4_reg
.extern r5_reg
.extern r6_reg
.extern r7_reg
.extern r8_reg
.extern r9_reg
.extern r10_reg
.extern r11_reg
.extern r12_reg
.extern r13_reg
.extern r14_reg
.extern r15_reg
.extern cpsr_reg

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
