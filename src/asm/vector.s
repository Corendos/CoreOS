.globl isr_vector
.section .text.isr


.extern reset
.extern undefined_instruction_handler
.extern svc_handler
.extern prefetch_abort_handler
.extern data_abort_handler
.extern asm_irq_handler
.extern fiq_handler

isr_vector:
	b reset
	b undefined_instruction_handler
	b svc_handler
	b prefetch_abort_handler
	b data_abort_handler
	.word 0
	b irq_handler
	b fiq_handler
