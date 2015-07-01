	.file	"call.c"
	.text
	.p2align 4,,15
.globl f
	.type	f, @function
f:
.LFB0:
	.cfi_startproc
	leaq	(%rsi,%rdi), %rdi
	leaq	(%rdi,%rdx), %rdx
	addq	%rcx, %rdx
	addq	%r8, %rdx
	leaq	(%rdx,%r9), %rax
	addq	8(%rsp), %rax
	addq	16(%rsp), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.p2align 4,,15
.globl main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	movl	$36, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
