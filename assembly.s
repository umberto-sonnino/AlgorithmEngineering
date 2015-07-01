	.file	"assembly.c"
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	movl	$7, -4(%rbp)	//a = 7
	movl	$5, -8(%rbp)	//b = 5
	addl	$1, -4(%rbp)	//a++
	movl	-8(%rbp), %eax	//temp = b
	subl	$5, %eax	//b-5->eax
	movl	%eax, -4(%rbp)	//a = b
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
