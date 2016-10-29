.section .text.boot /* Give a name to this section*/
.globl _start



_start:
	mov sp, #0x8000 /* We set the SP to 0x8000 */

	ldr r4, =__bss_start	// Setting bss_start
	ldr r9, =__bss_end		// Setting bss_end
	mov r5, #0
	mov r6, #0
	mov r7, #0
	mov r8, #0
	b 		2f

1:
	stmia r4!, {r5 - r8}

2:
	cmp r4, r9
	blo		1b				// Zeroing this segment

	ldr r3, =kernel_main	// Load the kernel main
	blx r3					// Jump to it

halt:
	wfe
	b halt
	