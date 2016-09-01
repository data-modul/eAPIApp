	.file	"EApiAHStorage.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%s\n"
.LC1:
	.string	"EApiAHWriteStorage"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHStorage.c"
	.section	.rodata.str1.1
.LC3:
	.string	"(pBuffer==NULL)"
.LC4:
	.string	"(ByteCnt==0)"
.LC5:
	.string	"((ByteOffset+ByteCnt)>MaxLen)"
	.section	.rodata.str1.8
	.align 8
.LC6:
	.string	"((AdjOffset+AdjLength)>MaxLen)"
	.section	.rodata.str1.1
.LC7:
	.string	"Allocating Page Buffer"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB8:
	.text
.LHOTB8:
	.p2align 4,,15
	.globl	EApiAHWriteStorage
	.type	EApiAHWriteStorage, @function
EApiAHWriteStorage:
.LFB99:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	testq	%rdx, %rdx
	je	.L24
	testl	%ecx, %ecx
	movl	%ecx, %ebp
	jne	.L4
	subq	$8, %rsp
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC4
	.cfi_def_cfa_offset 112
	movl	$62, %ecx
.L21:
	movl	$69, %edi
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	xorl	%eax, %eax
	movl	$-257, %ebx
	call	siFormattedMessage_SC
	popq	%rdi
	.cfi_def_cfa_offset 104
	popq	%r8
	.cfi_def_cfa_offset 96
.L13:
	movq	24(%rsp), %rcx
	xorq	%fs:40, %rcx
	movl	%ebx, %eax
	jne	.L25
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L4:
	.cfi_restore_state
	movl	%esi, %r13d
	movq	%rdx, %r12
	leaq	16(%rsp), %rsi
	leaq	20(%rsp), %rdx
	movl	%edi, %r14d
	call	EApiStorageCap
	testl	%eax, %eax
	movl	%eax, %ebx
	jne	.L13
	movl	16(%rsp), %esi
	leal	0(%r13,%rbp), %eax
	cmpl	%esi, %eax
	ja	.L26
	movl	20(%rsp), %ecx
	xorl	%edx, %edx
	movl	%r13d, %eax
	divl	%ecx
	testl	%edx, %edx
	movl	%edx, %r9d
	jne	.L27
	xorl	%edx, %edx
	movl	%ebp, %eax
	movl	%ebp, %r15d
	divl	%ecx
	movl	%r13d, %r10d
	testl	%edx, %edx
	je	.L8
.L12:
	addl	%ecx, %r15d
	subl	%edx, %r15d
.L7:
	cmpl	%ebp, %r15d
	je	.L8
	leal	(%r15,%r10), %eax
	cmpl	%eax, %esi
	jnb	.L9
	subq	$8, %rsp
	.cfi_def_cfa_offset 104
	movl	$92, %ecx
	movl	$.LC2, %esi
	pushq	$.LC6
	.cfi_def_cfa_offset 112
	movl	$.LC0, %r9d
	movl	$-3841, %r8d
	movl	$.LC1, %edx
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	movl	$-3841, %ebx
	popq	%rcx
	.cfi_def_cfa_offset 104
	popq	%rsi
	.cfi_def_cfa_offset 96
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L24:
	subq	$8, %rsp
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 112
	movl	$57, %ecx
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$-257, %ebx
	call	siFormattedMessage_SC
	popq	%r9
	.cfi_def_cfa_offset 104
	popq	%r10
	.cfi_def_cfa_offset 96
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L26:
	subq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC5
	.cfi_def_cfa_offset 112
	movl	$73, %ecx
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L27:
	.cfi_restore_state
	leal	0(%rbp,%rdx), %r15d
	movl	%r13d, %r10d
	subl	%edx, %r10d
	xorl	%edx, %edx
	movl	%r15d, %eax
	divl	%ecx
	testl	%edx, %edx
	je	.L7
	jmp	.L12
	.p2align 4,,10
	.p2align 3
.L9:
	movl	%r15d, %edi
	movl	%r9d, 12(%rsp)
	movl	%r10d, 8(%rsp)
	call	malloc
	testq	%rax, %rax
	movq	%rax, %r13
	movl	8(%rsp), %r10d
	movl	12(%rsp), %r9d
	je	.L28
	movl	%r15d, %r8d
	movl	%r15d, %ecx
	movq	%rax, %rdx
	movl	%r10d, %esi
	movl	%r14d, %edi
	movl	%r9d, 12(%rsp)
	movl	%r10d, 8(%rsp)
	call	EApiStorageAreaRead
	testl	%eax, %eax
	movl	%eax, %ebx
	movl	12(%rsp), %r9d
	je	.L29
.L11:
	movq	%r13, %rdi
	call	free
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L8:
	movl	%ebp, %ecx
	movq	%r12, %rdx
	movl	%r13d, %esi
	movl	%r14d, %edi
	call	EApiStorageAreaWrite
	movl	%eax, %ebx
	jmp	.L13
.L28:
	subq	$8, %rsp
	.cfi_def_cfa_offset 104
	movl	$.LC1, %edx
	movl	$.LC0, %r9d
	pushq	$.LC7
	.cfi_def_cfa_offset 112
	movl	$-3, %r8d
	movl	$99, %ecx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	movl	$-3, %ebx
	popq	%rax
	.cfi_def_cfa_offset 104
	popq	%rdx
	.cfi_def_cfa_offset 96
	jmp	.L13
.L29:
	movl	%r9d, %edi
	movl	%ebp, %edx
	movq	%r12, %rsi
	addq	%r13, %rdi
	call	memcpy
	movl	8(%rsp), %r10d
	movl	%r15d, %ecx
	movq	%r13, %rdx
	movl	%r14d, %edi
	movl	%r10d, %esi
	call	EApiStorageAreaWrite
	movl	%eax, %ebx
	jmp	.L11
.L25:
	call	__stack_chk_fail
	.cfi_endproc
.LFE99:
	.size	EApiAHWriteStorage, .-EApiAHWriteStorage
	.section	.text.unlikely
.LCOLDE8:
	.text
.LHOTE8:
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
