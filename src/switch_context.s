.global activate

.extern kernel_stack_pointer
 
activate:
	/* save kernel state */
	push {r4 - r12, r14}

	ldr r1, =kernel_stack_pointer
	str r13, [r1]
	/* change the adress of the stack */
	mov r13, r0

	/* restore user state */
	pop {r4 - r11, r14}

.global svc_call

svc_call:
	push {r4 - r11, r14}

	ldr r1, =kernel_stack_pointer
	ldr r13, [r1]

	pop {r4 - r12, r14}
