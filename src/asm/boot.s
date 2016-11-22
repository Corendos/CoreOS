.global reset


.section .text.low_kernel
reset:
	mov sp, #0x10000
	bl kernel_low
	