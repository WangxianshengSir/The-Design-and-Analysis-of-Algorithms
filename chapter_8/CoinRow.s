	.file	"CoinRow.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	_Z7CoinRowPii
	.type	_Z7CoinRowPii, @function
_Z7CoinRowPii:
.LFB1212:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movl	%esi, -60(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	-60(%rbp), %eax
	cltq
	subq	$1, %rax
	movq	%rax, -40(%rbp)
	movq	%rax, %rdx
	addq	$1, %rdx
	movq	%rdx, %r10
	movl	$0, %r11d
	movq	%rax, %rdx
	addq	$1, %rdx
	movq	%rdx, %r8
	movl	$0, %r9d
	addq	$1, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %edi
	movl	$0, %edx
	divq	%rdi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movl	$0, (%rax)
	movq	-56(%rbp), %rax
	movl	4(%rax), %edx
	movq	-32(%rbp), %rax
	movl	%edx, 4(%rax)
	movl	$2, -44(%rbp)
.L3:
	movl	-44(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jge	.L2
	movl	-44(%rbp), %eax
	subl	$1, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %esi
	movl	-44(%rbp), %eax
	leal	-2(%rax), %edx
	movq	-32(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	addl	%esi, %eax
	movl	%eax, -48(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt3maxIiERKT_S2_S2_
	movl	(%rax), %ecx
	movq	-32(%rbp), %rax
	movl	-44(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -44(%rbp)
	jmp	.L3
.L2:
	movl	-60(%rbp), %eax
	leal	-1(%rax), %edx
	movq	-32(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movq	%rbx, %rsp
	movq	-24(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L5
	call	__stack_chk_fail
.L5:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1212:
	.size	_Z7CoinRowPii, .-_Z7CoinRowPii
	.globl	main
	.type	main, @function
main:
.LFB1213:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	$7, -44(%rbp)
	movl	-44(%rbp), %eax
	cltq
	leaq	-1(%rax), %rcx
	movq	%rcx, -40(%rbp)
	movq	%rcx, %rax
	addq	$1, %rax
	movq	%rax, %r8
	movl	$0, %r9d
	movq	%rcx, %rax
	addq	$1, %rax
	movq	%rax, %rsi
	movl	$0, %edi
	movq	%rcx, %rax
	addq	$1, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %edi
	movl	$0, %edx
	divq	%rdi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rcx, %rdx
	movl	$0, (%rax)
	addq	$4, %rax
	subq	$1, %rdx
	movl	$5, (%rax)
	addq	$4, %rax
	subq	$1, %rdx
	movl	$1, (%rax)
	addq	$4, %rax
	subq	$1, %rdx
	movl	$2, (%rax)
	addq	$4, %rax
	subq	$1, %rdx
	movl	$10, (%rax)
	addq	$4, %rax
	subq	$1, %rdx
	movl	$6, (%rax)
	addq	$4, %rax
	subq	$1, %rdx
	movl	$2, (%rax)
	addq	$4, %rax
	subq	$1, %rdx
.L8:
	cmpq	$-1, %rdx
	je	.L7
	movl	$0, (%rax)
	addq	$4, %rax
	subq	$1, %rdx
	jmp	.L8
.L7:
	movq	-32(%rbp), %rax
	movl	-44(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_Z7CoinRowPii
	movl	%eax, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movl	$0, %eax
	movq	%rbx, %rsp
	movq	-24(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L10
	call	__stack_chk_fail
.L10:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1213:
	.size	main, .-main
	.section	.text._ZSt3maxIiERKT_S2_S2_,"axG",@progbits,_ZSt3maxIiERKT_S2_S2_,comdat
	.weak	_ZSt3maxIiERKT_S2_S2_
	.type	_ZSt3maxIiERKT_S2_S2_, @function
_ZSt3maxIiERKT_S2_S2_:
.LFB1214:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L12
	movq	-16(%rbp), %rax
	jmp	.L13
.L12:
	movq	-8(%rbp), %rax
.L13:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1214:
	.size	_ZSt3maxIiERKT_S2_S2_, .-_ZSt3maxIiERKT_S2_S2_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1215:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L16
	cmpl	$65535, -8(%rbp)
	jne	.L16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L16:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1215:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z7CoinRowPii, @function
_GLOBAL__sub_I__Z7CoinRowPii:
.LFB1216:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1216:
	.size	_GLOBAL__sub_I__Z7CoinRowPii, .-_GLOBAL__sub_I__Z7CoinRowPii
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z7CoinRowPii
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
