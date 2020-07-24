	.file	"average.c"
	.text
	.globl	avg
	.type	avg, @function
avg:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	cmpl	$0, -28(%rbp)
	jle	.L2
	cmpl	$0, -32(%rbp)
	jne	.L3
.L2:
	pxor	%xmm0, %xmm0
	jmp	.L4
.L3:
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L5
.L8:
	cmpl	$1, -32(%rbp)
	jne	.L6
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cvtsi2sd	%eax, %xmm0
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	jmp	.L7
.L6:
	cmpl	$2, -32(%rbp)
	jne	.L7
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	cvtsi2sd	%eax, %xmm0
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
.L7:
	addl	$1, -12(%rbp)
.L5:
	movl	-12(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L8
	cvtsi2sd	-28(%rbp), %xmm1
	movsd	-8(%rbp), %xmm0
	divsd	%xmm1, %xmm0
.L4:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	avg, .-avg
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
