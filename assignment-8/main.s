	.file	"main.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Please enter the sequence lenght: "
.LC1:
	.string	"%d"
	.align 8
.LC2:
	.string	"Please enter the first element: "
.LC3:
	.string	"Sequence: "
.LC4:
	.string	"\nLoop: "
.LC5:
	.string	"\nNo loop found."
.LC6:
	.string	"\nHistogram of the sequence: "
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$4, %esi
	movl	$9, %edi
	call	calloc@PLT
	movq	%rax, -32(%rbp)
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %eax
	cltq
	movl	$4, %esi
	movq	%rax, %rdi
	call	calloc@PLT
	movq	%rax, -24(%rbp)
	movl	-40(%rbp), %edx
	movl	-44(%rbp), %eax
	movq	-24(%rbp), %rcx
	movl	$0, %esi
	movl	%eax, %edi
	call	generate_sequence@PLT
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-40(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	print_arr@PLT
	movl	-40(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	cltq
	movl	$4, %esi
	movq	%rax, %rdi
	call	calloc@PLT
	movq	%rax, -16(%rbp)
	movl	-40(%rbp), %edx
	movl	-44(%rbp), %eax
	leaq	-36(%rbp), %rsi
	movq	-16(%rbp), %rcx
	movq	%rsi, %r8
	movl	%eax, %esi
	movq	generate_sequence@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	check_loop_iterative@PLT
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	je	.L2
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-36(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	print_arr@PLT
	jmp	.L3
.L2:
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
.L3:
	movl	-40(%rbp), %edx
	movl	-44(%rbp), %eax
	movq	-32(%rbp), %rcx
	movl	$0, %r8d
	movl	%eax, %esi
	movq	generate_sequence@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	hist_of_firstdigits@PLT
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	movl	$9, %esi
	movq	%rax, %rdi
	call	print_arr@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
