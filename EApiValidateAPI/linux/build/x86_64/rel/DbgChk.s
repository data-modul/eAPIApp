	.file	"DbgChk.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"NOT_INITIALIZED"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	EApiGetErrorStringA
	.type	EApiGetErrorStringA, @function
EApiGetErrorStringA:
.LFB99:
	.cfi_startproc
	cmpl	$-1, %esi
	movq	$0, (%rdi)
	je	.L6
	movl	$ErrorLookupA+16, %eax
	.p2align 4,,10
	.p2align 3
.L5:
	cmpl	%esi, (%rax)
	je	.L9
	addq	$16, %rax
	cmpq	$ErrorLookupA+304, %rax
	jne	.L5
	movl	$-3841, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L9:
	movq	8(%rax), %rax
.L2:
	movq	%rax, (%rdi)
	xorl	%eax, %eax
	ret
.L6:
	movl	$.LC0, %eax
	jmp	.L2
	.cfi_endproc
.LFE99:
	.size	EApiGetErrorStringA, .-EApiGetErrorStringA
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	GetLastOccurance
	.type	GetLastOccurance, @function
GetLastOccurance:
.LFB100:
	.cfi_startproc
	.p2align 4,,10
	.p2align 3
.L13:
	movzbl	(%rdi), %edx
	movq	%rdi, %rax
	testb	%dl, %dl
	je	.L22
.L14:
	addq	$1, %rdi
	cmpb	$47, %dl
	je	.L13
	cmpb	$92, %dl
	je	.L13
	movzbl	(%rdi), %edx
	testb	%dl, %dl
	jne	.L14
.L22:
	rep ret
	.cfi_endproc
.LFE100:
	.size	GetLastOccurance, .-GetLastOccurance
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.rodata.str1.1
.LC3:
	.string	"%-25s | "
	.section	.text.unlikely
.LCOLDB4:
	.text
.LHOTB4:
	.p2align 4,,15
	.globl	siFormattedMessage_M2
	.type	siFormattedMessage_M2, @function
siFormattedMessage_M2:
.LFB101:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%r8, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%r9, %rbx
	subq	$208, %rsp
	.cfi_def_cfa_offset 240
	testb	%al, %al
	je	.L24
	movaps	%xmm0, 80(%rsp)
	movaps	%xmm1, 96(%rsp)
	movaps	%xmm2, 112(%rsp)
	movaps	%xmm3, 128(%rsp)
	movaps	%xmm4, 144(%rsp)
	movaps	%xmm5, 160(%rsp)
	movaps	%xmm6, 176(%rsp)
	movaps	%xmm7, 192(%rsp)
.L24:
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	leaq	240(%rsp), %rax
	movq	%rsi, %r8
	movq	%rax, 8(%rsp)
	leaq	32(%rsp), %rax
	movl	$48, (%rsp)
	movl	$48, 4(%rsp)
	movq	%rax, 16(%rsp)
	.p2align 4,,10
	.p2align 3
.L25:
	movzbl	(%rsi), %eax
	testb	%al, %al
	je	.L37
.L28:
	addq	$1, %rsi
	cmpb	$47, %al
	je	.L27
	cmpb	$92, %al
	jne	.L25
.L27:
	movzbl	(%rsi), %eax
	movq	%rsi, %r8
	testb	%al, %al
	jne	.L28
.L37:
	movsbl	%dil, %edi
	movq	%rdx, %r9
	movl	$cszLogFormat, %esi
	movl	%edi, %edx
	movl	$1, %edi
	call	__printf_chk
	movq	%rbp, %rdx
	movl	%eax, %r12d
	movl	$.LC3, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movq	stdout(%rip), %rdi
	movq	%rbx, %rdx
	movq	%rsp, %rcx
	movl	$1, %esi
	call	__vfprintf_chk
	addl	%r12d, %eax
	movq	24(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L38
	addq	$208, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L38:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE101:
	.size	siFormattedMessage_M2, .-siFormattedMessage_M2
	.section	.text.unlikely
.LCOLDE4:
	.text
.LHOTE4:
	.section	.rodata.str1.1
.LC5:
	.string	"               0x%08X | "
	.section	.text.unlikely
.LCOLDB6:
	.text
.LHOTB6:
	.p2align 4,,15
	.globl	siFormattedMessage_SC
	.type	siFormattedMessage_SC, @function
siFormattedMessage_SC:
.LFB102:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%r9, %rbp
	movl	%r8d, %ebx
	subq	$216, %rsp
	.cfi_def_cfa_offset 256
	testb	%al, %al
	je	.L40
	movaps	%xmm0, 80(%rsp)
	movaps	%xmm1, 96(%rsp)
	movaps	%xmm2, 112(%rsp)
	movaps	%xmm3, 128(%rsp)
	movaps	%xmm4, 144(%rsp)
	movaps	%xmm5, 160(%rsp)
	movaps	%xmm6, 176(%rsp)
	movaps	%xmm7, 192(%rsp)
.L40:
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	leaq	256(%rsp), %rax
	cmpl	$-1, %ebx
	movq	%rax, 8(%rsp)
	leaq	32(%rsp), %rax
	movl	$48, (%rsp)
	movl	$48, 4(%rsp)
	movq	%rax, 16(%rsp)
	je	.L52
	movl	$ErrorLookupA+16, %eax
	.p2align 4,,10
	.p2align 3
.L44:
	cmpl	(%rax), %ebx
	je	.L63
	addq	$16, %rax
	cmpq	$ErrorLookupA+304, %rax
	jne	.L44
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L53:
	movzbl	(%rsi), %eax
	movq	%rsi, %r8
	testb	%al, %al
	je	.L64
.L48:
	addq	$1, %rsi
	cmpb	$47, %al
	je	.L53
	cmpb	$92, %al
	je	.L53
	movzbl	(%rsi), %eax
	testb	%al, %al
	jne	.L48
.L64:
	movsbl	%dil, %edi
	movq	%rdx, %r9
	movl	$cszLogFormat, %esi
	movl	%edi, %edx
	movl	$1, %edi
	call	__printf_chk
	testq	%r12, %r12
	movl	%eax, %r13d
	je	.L65
	movq	%r12, %rdx
	movl	$.LC3, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
.L50:
	movq	stdout(%rip), %rdi
	movq	%rsp, %rcx
	movq	%rbp, %rdx
	movl	$1, %esi
	call	__vfprintf_chk
	addl	%r13d, %eax
	movq	24(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L66
	addq	$216, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L63:
	.cfi_restore_state
	movq	8(%rax), %r12
	jmp	.L53
.L65:
	movl	%ebx, %edx
	movl	$.LC5, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	jmp	.L50
.L52:
	movl	$.LC0, %r12d
	jmp	.L53
.L66:
	call	__stack_chk_fail
	.cfi_endproc
.LFE102:
	.size	siFormattedMessage_SC, .-siFormattedMessage_SC
	.section	.text.unlikely
.LCOLDE6:
	.text
.LHOTE6:
	.globl	cszLogFormat
	.section	.rodata
	.align 16
	.type	cszLogFormat, @object
	.size	cszLogFormat, 25
cszLogFormat:
	.string	"%c%04i %-15.15s %-30s | "
	.globl	ErrorLookupA
	.section	.rodata.str1.1
.LC7:
	.string	"INITIALIZED"
.LC8:
	.string	"ALLOC_ERROR"
.LC9:
	.string	"DRIVER_TIMEOUT"
.LC10:
	.string	"INVALID_PARAMETER"
.LC11:
	.string	"INVALID_BLOCK_ALIGNMENT"
.LC12:
	.string	"INVALID_BLOCK_LENGTH"
.LC13:
	.string	"INVALID_DIRECTION"
.LC14:
	.string	"INVALID_BITMASK"
.LC15:
	.string	"RUNNING"
.LC16:
	.string	"UNSUPPORTED"
.LC17:
	.string	"NOT_FOUND"
.LC18:
	.string	"TIMEOUT"
.LC19:
	.string	"BUSY_COLLISION"
.LC20:
	.string	"READ_ERROR"
.LC21:
	.string	"WRITE_ERROR"
.LC22:
	.string	"MORE_DATA"
.LC23:
	.string	"ERROR"
.LC24:
	.string	"SUCCESS"
	.section	.rodata
	.align 32
	.type	ErrorLookupA, @object
	.size	ErrorLookupA, 304
ErrorLookupA:
	.long	-1
	.zero	4
	.quad	.LC0
	.long	-2
	.zero	4
	.quad	.LC7
	.long	-3
	.zero	4
	.quad	.LC8
	.long	-4
	.zero	4
	.quad	.LC9
	.long	-257
	.zero	4
	.quad	.LC10
	.long	-258
	.zero	4
	.quad	.LC11
	.long	-259
	.zero	4
	.quad	.LC12
	.long	-260
	.zero	4
	.quad	.LC13
	.long	-261
	.zero	4
	.quad	.LC14
	.long	-262
	.zero	4
	.quad	.LC15
	.long	-769
	.zero	4
	.quad	.LC16
	.long	-1025
	.zero	4
	.quad	.LC17
	.long	-1026
	.zero	4
	.quad	.LC18
	.long	-1027
	.zero	4
	.quad	.LC19
	.long	-1281
	.zero	4
	.quad	.LC20
	.long	-1282
	.zero	4
	.quad	.LC21
	.long	-1537
	.zero	4
	.quad	.LC22
	.long	-3841
	.zero	4
	.quad	.LC23
	.long	0
	.zero	4
	.quad	.LC24
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
