	.file	"util.c"
	.text
	.globl	generate_sequence
	.type	generate_sequence, @function
generate_sequence:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movq	%rcx, -24(%rbp)
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	je	.L5
	movl	-8(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -8(%rbp)
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)
	movl	-4(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L3
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	.L4
.L3:
	sarl	-4(%rbp)
.L4:
	movq	-24(%rbp), %rcx
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	generate_sequence
.L5:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	generate_sequence, .-generate_sequence
	.globl	has_loop
	.type	has_loop, @function
has_loop:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movq	%r8, -48(%rbp)
	movl	$1, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L7
.L9:
	movl	-28(%rbp), %eax
	subl	$1, %eax
	subl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-28(%rbp), %eax
	subl	$1, %eax
	subl	-32(%rbp), %eax
	subl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	je	.L8
	movl	$0, -8(%rbp)
.L8:
	addl	$1, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L9
	cmpl	$1, -8(%rbp)
	jne	.L10
	movl	-32(%rbp), %eax
	leal	(%rax,%rax), %edx
	movl	-28(%rbp), %eax
	subl	%edx, %eax
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movl	%edx, (%rax)
	movl	-28(%rbp), %eax
	subl	$1, %eax
	subl	-32(%rbp), %eax
	movl	%eax, %edx
	movq	-48(%rbp), %rax
	movl	%edx, (%rax)
.L10:
	movl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	has_loop, .-has_loop
	.section	.rodata
	.align 8
.LC0:
	.string	"\nChecking if there is a loop of length %d..."
	.align 8
.LC1:
	.string	"\n\nLoop detected with a length of %d."
	.align 8
.LC2:
	.string	"\nThe indexes of the loop's first occurance: %d (first digit), %d (last digit)"
	.text
	.globl	check_loop_iterative
	.type	check_loop_iterative, @function
check_loop_iterative:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	%edx, -48(%rbp)
	movq	%rcx, -56(%rbp)
	movq	%r8, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	-48(%rbp), %eax
	cltq
	movl	$4, %esi
	movq	%rax, %rdi
	call	calloc@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rcx
	movl	-48(%rbp), %edx
	movl	-44(%rbp), %eax
	movq	-40(%rbp), %r8
	movl	$0, %esi
	movl	%eax, %edi
	call	*%r8
	movq	-64(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-64(%rbp), %rax
	movl	(%rax), %edx
	leaq	-28(%rbp), %rdi
	leaq	-32(%rbp), %rcx
	movl	-48(%rbp), %esi
	movq	-16(%rbp), %rax
	movq	%rdi, %r8
	movq	%rax, %rdi
	call	has_loop
	testl	%eax, %eax
	je	.L13
	movq	-64(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-28(%rbp), %edx
	movl	-32(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-32(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L14
.L15:
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-56(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -24(%rbp)
	addl	$1, -20(%rbp)
.L14:
	movq	-64(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	jl	.L15
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	jmp	.L12
.L13:
	movq	-64(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$2, %eax
	jle	.L17
	movq	-64(%rbp), %rax
	movl	(%rax), %eax
	leal	-1(%rax), %edx
	movq	-64(%rbp), %rax
	movl	%edx, (%rax)
	movq	-64(%rbp), %rdi
	movq	-56(%rbp), %rcx
	movl	-48(%rbp), %edx
	movl	-44(%rbp), %esi
	movq	-40(%rbp), %rax
	movq	%rdi, %r8
	movq	%rax, %rdi
	call	check_loop_iterative
.L17:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
.L12:
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L18
	call	__stack_chk_fail@PLT
.L18:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	check_loop_iterative, .-check_loop_iterative
	.globl	hist_of_firstdigits
	.type	hist_of_firstdigits, @function
hist_of_firstdigits:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movl	%r8d, -44(%rbp)
	movl	-32(%rbp), %eax
	cltq
	movl	$4, %esi
	movq	%rax, %rdi
	call	calloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rcx
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %eax
	movq	-24(%rbp), %r8
	movl	$0, %esi
	movl	%eax, %edi
	call	*%r8
	movl	-32(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	convert_ints_to_digits
	movl	$0, -12(%rbp)
	jmp	.L20
.L22:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -44(%rbp)
	jne	.L21
	movl	-44(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	addl	$1, %edx
	movl	%edx, (%rax)
.L21:
	addl	$1, -12(%rbp)
.L20:
	movl	-12(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L22
	cmpl	$9, -44(%rbp)
	je	.L23
	movl	-44(%rbp), %eax
	leal	1(%rax), %edi
	movq	-40(%rbp), %rcx
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %esi
	movq	-24(%rbp), %rax
	movl	%edi, %r8d
	movq	%rax, %rdi
	call	hist_of_firstdigits
.L23:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	hist_of_firstdigits, .-hist_of_firstdigits
	.globl	convert_ints_to_digits
	.type	convert_ints_to_digits, @function
convert_ints_to_digits:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L25
.L27:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	$9, %eax
	jle	.L26
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movslq	%eax, %rcx
	imulq	$1717986919, %rcx, %rcx
	shrq	$32, %rcx
	sarl	$2, %ecx
	sarl	$31, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, (%rdx)
	movl	-28(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	convert_ints_to_digits
.L26:
	addl	$1, -4(%rbp)
.L25:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L27
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	convert_ints_to_digits, .-convert_ints_to_digits
	.section	.rodata
.LC3:
	.string	"%d, "
.LC4:
	.string	"\b\b}"
	.text
	.globl	print_arr
	.type	print_arr, @function
print_arr:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$123, %edi
	call	putchar@PLT
	movl	$0, -4(%rbp)
	jmp	.L29
.L30:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L29:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L30
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	print_arr, .-print_arr
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
