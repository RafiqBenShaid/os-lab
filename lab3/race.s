	.file	"race.c"
	.text
	.globl	counter
	.bss
	.align 4
	.type	counter, @object
	.size	counter, 4
counter:
	.zero	4
	.text
	.globl	increment
	.type	increment, @function
increment:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	counter(%rip), %eax
	addl	$1, %eax
	movl	%eax, counter(%rip)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$999999, -4(%rbp)
	jle	.L3
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	increment, .-increment
	.section	.rodata
.LC0:
	.string	"Final counter = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	increment(%rip), %rdx
	leaq	-8(%rbp), %rax
	movl	$0, %ecx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
	leaq	increment(%rip), %rdx
	leaq	-16(%rbp), %rax
	movl	$0, %ecx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
	movq	-8(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join@PLT
	movq	-16(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join@PLT
	movl	counter(%rip), %eax
	leaq	.LC0(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Debian 15.2.0-17) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
