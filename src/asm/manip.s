.global get32
.global set32
.global halt

get32:
	ldr r0, [r0]
	bx lr

set32:
	str r1, [r0]
	bx lr

halt:
	b halt
