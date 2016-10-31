.global activate
 
activate:
	/* save kernel state */
	push {r4 - r12, r14}

	/* change the adress of the stack */
	mov r13, r0

	/* restore user state */
	pop {r4 - r11, r14}

	/* jump to the function*/
	bx lr
