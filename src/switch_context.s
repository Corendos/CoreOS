.global activate
 
activate:
	/* save kernel state */
	push {r4 - r12, r15}

	/* change the adress of the stack */
	mov r13, r0

	/* restore user state */
	pop {r4 - r12, r15}

	/* jump to the function*/
	b r15
