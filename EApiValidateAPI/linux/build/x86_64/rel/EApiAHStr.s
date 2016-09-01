	.file	"EApiAHStr.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%s\n"
.LC1:
	.string	"EApiAHCreatePNPIDString"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHStr.c"
	.section	.rodata.str1.1
.LC3:
	.string	"(pString==NULL)"
.LC4:
	.string	"pBuffer Too Short"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB5:
	.text
.LHOTB5:
	.p2align 4,,15
	.globl	EApiAHCreatePNPIDString
	.type	EApiAHCreatePNPIDString, @function
EApiAHCreatePNPIDString:
.LFB111:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	rolw	$8, %di
	testq	%rsi, %rsi
	je	.L10
	cmpl	$3, %edx
	jbe	.L11
	testw	%di, %di
	js	.L6
	movzwl	%di, %eax
	andl	$31, %edi
	movzbl	CompressedAsciiLookup(%rdi), %edx
	movb	%dl, 2(%rsi)
	movl	%eax, %edx
	sarl	$10, %eax
	sarl	$5, %edx
	cltq
	andl	$31, %edx
	movzbl	CompressedAsciiLookup(%rdx), %edx
	movb	%dl, 1(%rsi)
	movzbl	CompressedAsciiLookup(%rax), %eax
	movb	$0, 3(%rsi)
	movb	%al, (%rsi)
	movl	$3, %eax
.L3:
.L5:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L11:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC4
	.cfi_def_cfa_offset 32
	movl	$409, %ecx
.L8:
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 24
	movl	$-1, %eax
	popq	%rdx
	.cfi_def_cfa_offset 16
	jmp	.L5
.L6:
	movl	$-1, %eax
	jmp	.L5
.L10:
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 32
	movl	$407, %ecx
	jmp	.L8
	.cfi_endproc
.LFE111:
	.size	EApiAHCreatePNPIDString, .-EApiAHCreatePNPIDString
	.section	.text.unlikely
.LCOLDE5:
	.text
.LHOTE5:
	.section	.text.unlikely
.LCOLDB6:
	.text
.LHOTB6:
	.p2align 4,,15
	.globl	EApiStrLenA
	.type	EApiStrLenA, @function
EApiStrLenA:
.LFB112:
	.cfi_startproc
	testq	%rsi, %rsi
	je	.L18
	testq	%rdi, %rdi
	je	.L18
	cmpb	$0, (%rdi)
	leaq	1(%rdi), %rdx
	leaq	(%rdi,%rsi), %rax
	jne	.L16
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L17:
	leaq	1(%rdx), %rcx
	cmpb	$0, -1(%rcx)
	je	.L22
	movq	%rcx, %rdx
.L16:
	cmpq	%rdx, %rax
	jne	.L17
	subq	%rdi, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L18:
	xorl	%eax, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L22:
	movq	%rdx, %rax
	subq	%rdi, %rax
	ret
	.cfi_endproc
.LFE112:
	.size	EApiStrLenA, .-EApiStrLenA
	.section	.text.unlikely
.LCOLDE6:
	.text
.LHOTE6:
	.section	.text.unlikely
.LCOLDB7:
	.text
.LHOTB7:
	.p2align 4,,15
	.globl	EApiStrCpyA
	.type	EApiStrCpyA, @function
EApiStrCpyA:
.LFB113:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rsi, %rbp
	movq	%rdx, %rsi
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	testq	%rdx, %rdx
	sete	%dl
	testq	%rbp, %rbp
	sete	%al
	orb	%al, %dl
	jne	.L24
	testq	%rdi, %rdi
	je	.L24
	movq	%rbp, %rdx
	call	strncpy
	movb	$0, -1(%rbx,%rbp)
.L24:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE113:
	.size	EApiStrCpyA, .-EApiStrCpyA
	.section	.text.unlikely
.LCOLDE7:
	.text
.LHOTE7:
	.section	.text.unlikely
.LCOLDB8:
	.text
.LHOTB8:
	.p2align 4,,15
	.globl	EApiSprintfA
	.type	EApiSprintfA, @function
EApiSprintfA:
.LFB114:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	movq	%rsi, %rbx
	subq	$216, %rsp
	.cfi_def_cfa_offset 240
	testb	%al, %al
	movq	%rcx, 56(%rsp)
	movq	%r8, 64(%rsp)
	movq	%r9, 72(%rsp)
	je	.L27
	movaps	%xmm0, 80(%rsp)
	movaps	%xmm1, 96(%rsp)
	movaps	%xmm2, 112(%rsp)
	movaps	%xmm3, 128(%rsp)
	movaps	%xmm4, 144(%rsp)
	movaps	%xmm5, 160(%rsp)
	movaps	%xmm6, 176(%rsp)
	movaps	%xmm7, 192(%rsp)
.L27:
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	testq	%rdx, %rdx
	sete	%cl
	testq	%rbx, %rbx
	sete	%al
	orb	%al, %cl
	jne	.L30
	testq	%rbp, %rbp
	je	.L30
	leaq	240(%rsp), %rax
	movq	%rdx, %r8
	movq	%rsp, %r9
	movq	$-1, %rcx
	movl	$1, %edx
	movq	%rbx, %rsi
	movq	%rax, 8(%rsp)
	leaq	32(%rsp), %rax
	movq	%rbp, %rdi
	movl	$24, (%rsp)
	movl	$48, 4(%rsp)
	movq	%rax, 16(%rsp)
	call	__vsnprintf_chk
	movb	$0, -1(%rbp,%rbx)
.L28:
	movq	24(%rsp), %rsi
	xorq	%fs:40, %rsi
	jne	.L32
	addq	$216, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L30:
	.cfi_restore_state
	movl	$-1, %eax
	jmp	.L28
.L32:
	call	__stack_chk_fail
	.cfi_endproc
.LFE114:
	.size	EApiSprintfA, .-EApiSprintfA
	.section	.text.unlikely
.LCOLDE8:
	.text
.LHOTE8:
	.section	.text.unlikely
.LCOLDB9:
	.text
.LHOTB9:
	.p2align 4,,15
	.globl	EApiStrLen
	.type	EApiStrLen, @function
EApiStrLen:
.LFB115:
	.cfi_startproc
	testq	%rsi, %rsi
	je	.L39
	testq	%rdi, %rdi
	je	.L39
	cmpb	$0, (%rdi)
	leaq	1(%rdi), %rdx
	leaq	(%rdi,%rsi), %rax
	jne	.L37
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L38:
	leaq	1(%rdx), %rcx
	cmpb	$0, -1(%rcx)
	je	.L43
	movq	%rcx, %rdx
.L37:
	cmpq	%rdx, %rax
	jne	.L38
	subq	%rdi, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L39:
	xorl	%eax, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L43:
	movq	%rdx, %rax
	subq	%rdi, %rax
	ret
	.cfi_endproc
.LFE115:
	.size	EApiStrLen, .-EApiStrLen
	.section	.text.unlikely
.LCOLDE9:
	.text
.LHOTE9:
	.section	.text.unlikely
.LCOLDB10:
	.text
.LHOTB10:
	.p2align 4,,15
	.globl	EApiStrCpy
	.type	EApiStrCpy, @function
EApiStrCpy:
.LFB116:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rsi, %rbp
	movq	%rdx, %rsi
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	testq	%rdx, %rdx
	sete	%dl
	testq	%rbp, %rbp
	sete	%al
	orb	%al, %dl
	jne	.L45
	testq	%rdi, %rdi
	je	.L45
	movq	%rbp, %rdx
	call	strncpy
	movb	$0, -1(%rbx,%rbp)
.L45:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE116:
	.size	EApiStrCpy, .-EApiStrCpy
	.section	.text.unlikely
.LCOLDE10:
	.text
.LHOTE10:
	.section	.text.unlikely
.LCOLDB11:
	.text
.LHOTB11:
	.p2align 4,,15
	.globl	EApiSprintf
	.type	EApiSprintf, @function
EApiSprintf:
.LFB117:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	movq	%rsi, %rbx
	subq	$216, %rsp
	.cfi_def_cfa_offset 240
	testb	%al, %al
	movq	%rcx, 56(%rsp)
	movq	%r8, 64(%rsp)
	movq	%r9, 72(%rsp)
	je	.L48
	movaps	%xmm0, 80(%rsp)
	movaps	%xmm1, 96(%rsp)
	movaps	%xmm2, 112(%rsp)
	movaps	%xmm3, 128(%rsp)
	movaps	%xmm4, 144(%rsp)
	movaps	%xmm5, 160(%rsp)
	movaps	%xmm6, 176(%rsp)
	movaps	%xmm7, 192(%rsp)
.L48:
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	testq	%rdx, %rdx
	sete	%cl
	testq	%rbx, %rbx
	sete	%al
	orb	%al, %cl
	jne	.L51
	testq	%rbp, %rbp
	je	.L51
	leaq	240(%rsp), %rax
	movq	%rdx, %r8
	movq	%rsp, %r9
	movq	$-1, %rcx
	movl	$1, %edx
	movq	%rbx, %rsi
	movq	%rax, 8(%rsp)
	leaq	32(%rsp), %rax
	movq	%rbp, %rdi
	movl	$24, (%rsp)
	movl	$48, 4(%rsp)
	movq	%rax, 16(%rsp)
	call	__vsnprintf_chk
	movb	$0, -1(%rbp,%rbx)
.L49:
	movq	24(%rsp), %rsi
	xorq	%fs:40, %rsi
	jne	.L53
	addq	$216, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L51:
	.cfi_restore_state
	movl	$-1, %eax
	jmp	.L49
.L53:
	call	__stack_chk_fail
	.cfi_endproc
.LFE117:
	.size	EApiSprintf, .-EApiSprintf
	.section	.text.unlikely
.LCOLDE11:
	.text
.LHOTE11:
	.section	.rodata.str1.1
.LC12:
	.string	"EApiAHCreateErrorString"
.LC13:
	.string	"UNKNOWN ERROR(0x%08X)"
.LC14:
	.string	"(StrBufLen==0)"
	.section	.text.unlikely
.LCOLDB15:
	.text
.LHOTB15:
	.p2align 4,,15
	.globl	EApiAHCreateErrorString
	.type	EApiAHCreateErrorString, @function
EApiAHCreateErrorString:
.LFB99:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	testq	%rsi, %rsi
	je	.L69
	testq	%rdx, %rdx
	movq	%rdx, %rbp
	je	.L57
	movq	%rsi, %rbx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L60:
	movq	%rax, %rdx
	movl	%eax, %ecx
	salq	$4, %rdx
	cmpl	ErrorLookup(%rdx), %edi
	je	.L70
	addq	$1, %rax
	cmpq	$19, %rax
	jne	.L60
	movl	%edi, %ecx
	movl	$.LC13, %edx
	movq	%rbp, %rsi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	call	EApiSprintf
.L68:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%rbx, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	strlen
	.p2align 4,,10
	.p2align 3
.L57:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 40
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 48
	movl	$84, %ecx
.L67:
.L56:
.L61:
	movl	$.LC12, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 40
	popq	%rdx
	.cfi_def_cfa_offset 32
	movq	$-1, %rax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L70:
	.cfi_restore_state
	salq	$4, %rcx
	movq	ErrorLookup+8(%rcx), %rsi
	testq	%rsi, %rsi
	je	.L68
	movq	%rbp, %rdx
	movq	%rbx, %rdi
	call	strncpy
	movb	$0, -1(%rbx,%rbp)
	jmp	.L68
	.p2align 4,,10
	.p2align 3
.L69:
	subq	$8, %rsp
	.cfi_def_cfa_offset 40
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 48
	movl	$79, %ecx
	jmp	.L67
	.cfi_endproc
.LFE99:
	.size	EApiAHCreateErrorString, .-EApiAHCreateErrorString
	.section	.text.unlikely
.LCOLDE15:
	.text
.LHOTE15:
	.section	.rodata.str1.1
.LC16:
	.string	"EApiAHGetString"
.LC17:
	.string	"EApiAHGetStringAlloc"
	.section	.rodata.str1.8
	.align 8
.LC18:
	.string	"Interface Returning Different String Lengths"
	.align 8
.LC19:
	.string	"Returned String Missing Terminating \\0 Character."
	.section	.text.unlikely
.LCOLDB20:
	.text
.LHOTB20:
	.p2align 4,,15
	.globl	EApiAHGetString
	.type	EApiAHGetString, @function
EApiAHGetString:
.LFB101:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	testq	%rsi, %rsi
	movl	%edx, 4(%rsp)
	je	.L97
	testq	%rdx, %rdx
	movq	%rdx, %rbx
	jne	.L74
	subq	$8, %rsp
	.cfi_def_cfa_offset 56
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 64
	movl	$158, %ecx
	movl	$.LC16, %edx
.L94:
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rcx
	.cfi_def_cfa_offset 56
	popq	%rsi
	.cfi_def_cfa_offset 48
	movq	$-1, %rax
.L73:
	movq	8(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L98
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L74:
	.cfi_restore_state
	leaq	4(%rsp), %rdx
	movq	%rsi, %rbp
	call	EApiBoardGetStringA
	testl	%eax, %eax
	movl	4(%rsp), %edx
	jne	.L99
.L76:
	movl	%edx, %eax
	cmpq	%rax, %rbx
	jb	.L100
	cmpb	$0, 0(%rbp)
	leaq	1(%rbp), %rdx
	leaq	0(%rbp,%rbx), %rsi
	je	.L73
	cmpq	%rsi, %rdx
	je	.L93
.L79:
	leaq	1(%rdx), %rcx
	cmpb	$0, -1(%rcx)
	je	.L93
	movq	%rcx, %rdx
	cmpq	%rsi, %rdx
	jne	.L79
.L93:
	subq	%rbp, %rdx
	cmpq	%rdx, %rbx
	jne	.L73
	subq	$8, %rsp
	.cfi_def_cfa_offset 56
	movl	$.LC16, %edx
	movl	$.LC0, %r9d
	pushq	$.LC19
	.cfi_def_cfa_offset 64
	movl	$-1, %r8d
	movl	$176, %ecx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	movb	$0, -1(%rbp,%rbx)
	popq	%rax
	.cfi_def_cfa_offset 56
	popq	%rdx
	.cfi_def_cfa_offset 48
	movl	4(%rsp), %eax
	jmp	.L73
	.p2align 4,,10
	.p2align 3
.L100:
	subq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC18
	.cfi_def_cfa_offset 64
	movl	$169, %ecx
	movl	$.LC17, %edx
	jmp	.L94
	.p2align 4,,10
	.p2align 3
.L97:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 56
	movl	$-1, %r8d
	movl	$69, %edi
	pushq	$.LC3
	.cfi_def_cfa_offset 64
	movl	$.LC0, %r9d
	movl	$157, %ecx
	movl	$.LC16, %edx
	movl	$.LC2, %esi
	call	siFormattedMessage_SC
	popq	%rdi
	.cfi_def_cfa_offset 56
	movq	$-1, %rax
	popq	%r8
	.cfi_def_cfa_offset 48
	jmp	.L73
	.p2align 4,,10
	.p2align 3
.L99:
	movq	%rbx, %rdx
	movq	%rbp, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	movl	%eax, %edx
	movl	%eax, 4(%rsp)
	jmp	.L76
.L98:
	call	__stack_chk_fail
	.cfi_endproc
.LFE101:
	.size	EApiAHGetString, .-EApiAHGetString
	.section	.text.unlikely
.LCOLDE20:
	.text
.LHOTE20:
	.section	.rodata.str1.1
.LC21:
	.string	"EApiAHCreateErrorStringAlloc"
	.section	.text.unlikely
.LCOLDB22:
	.text
.LHOTB22:
	.p2align 4,,15
	.globl	EApiAHCreateErrorStringAlloc
	.type	EApiAHCreateErrorStringAlloc, @function
EApiAHCreateErrorStringAlloc:
.LFB100:
	.cfi_startproc
	xorl	%eax, %eax
	testq	%rsi, %rsi
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movl	%edi, %ebx
	je	.L118
	.p2align 4,,10
	.p2align 3
.L112:
	movq	%rax, %rdx
	movl	%eax, %edi
	salq	$4, %rdx
	cmpl	%ebx, ErrorLookup(%rdx)
	je	.L119
	addq	$1, %rax
	cmpq	$19, %rax
	jne	.L112
	movl	$26, %edi
	call	malloc
	testq	%rax, %rax
	movq	%rax, 0(%rbp)
	je	.L117
	movq	%rax, %rdi
	movl	%ebx, %ecx
	movl	$.LC13, %edx
	movl	$26, %esi
	xorl	%eax, %eax
	call	EApiSprintf
.L117:
.L109:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L103:
	.p2align 4,,10
	.p2align 3
.L119:
	.cfi_restore_state
	salq	$4, %rdi
	movq	ErrorLookup+8(%rdi), %r14
	movq	%r14, %rdi
	call	strlen
	leaq	1(%rax), %r12
	movq	%rax, %r13
	movq	%r12, %rdi
	call	malloc
	testq	%rax, %rax
	movq	%rax, %rbx
	movq	%rax, 0(%rbp)
	je	.L117
	testq	%r12, %r12
	je	.L117
	movq	%r12, %rdx
	movq	%r14, %rsi
	movq	%rax, %rdi
	call	strncpy
	movb	$0, (%rbx,%r13)
	xorl	%eax, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L118:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 56
	movl	$.LC21, %edx
	movl	$.LC0, %r9d
	pushq	$.LC3
	.cfi_def_cfa_offset 64
	movl	$-257, %r8d
	movl	$122, %ecx
	movl	$.LC2, %esi
	movl	$69, %edi
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 56
	movl	$-257, %eax
	popq	%rdx
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE100:
	.size	EApiAHCreateErrorStringAlloc, .-EApiAHCreateErrorStringAlloc
	.section	.text.unlikely
.LCOLDE22:
	.text
.LHOTE22:
	.section	.rodata.str1.1
.LC23:
	.string	"Memory Allocation Error"
	.section	.text.unlikely
.LCOLDB24:
	.text
.LHOTB24:
	.p2align 4,,15
	.globl	EApiAHGetStringAlloc
	.type	EApiAHGetStringAlloc, @function
EApiAHGetStringAlloc:
.LFB102:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	subq	$16, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	testq	%rsi, %rsi
	movl	$0, 4(%rsp)
	je	.L143
	leaq	4(%rsp), %rdx
	movq	$0, (%rsi)
	movq	%rsi, %rbx
	xorl	%esi, %esi
	movl	%edi, %r12d
	call	EApiBoardGetStringA
	cmpl	$-1537, %eax
	movl	%eax, %ebp
	je	.L144
	movq	%rbx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorStringAlloc
.L122:
	movq	8(%rsp), %rcx
	xorq	%fs:40, %rcx
	movl	%ebp, %eax
	jne	.L145
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L144:
	.cfi_restore_state
	movl	4(%rsp), %r14d
	movq	%r14, %rdi
	movq	%r14, %r13
	call	malloc
	testq	%rax, %rax
	movq	%rax, (%rbx)
	je	.L146
	leaq	4(%rsp), %rdx
	movq	%rax, %rsi
	movl	%r12d, %edi
	call	EApiBoardGetStringA
	cmpl	4(%rsp), %r14d
	movl	%eax, %ebp
	jb	.L147
	movq	(%rbx), %rsi
	testq	%rsi, %rsi
	je	.L134
	testq	%r14, %r14
	jne	.L148
.L128:
	subq	$8, %rsp
	.cfi_def_cfa_offset 72
	movl	$.LC17, %edx
	movl	$.LC0, %r9d
	pushq	$.LC19
	.cfi_def_cfa_offset 80
	movl	$-3841, %r8d
	movl	$226, %ecx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	movq	(%rbx), %rdx
	leal	-1(%r13), %eax
	movb	$0, (%rdx,%rax)
	popq	%rax
	.cfi_def_cfa_offset 72
	popq	%rdx
	.cfi_def_cfa_offset 64
	jmp	.L122
	.p2align 4,,10
	.p2align 3
.L143:
	subq	$8, %rsp
	.cfi_def_cfa_offset 72
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 80
	movl	$197, %ecx
	movl	$.LC16, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$-257, %ebp
	call	siFormattedMessage_SC
	popq	%r9
	.cfi_def_cfa_offset 72
	popq	%r10
	.cfi_def_cfa_offset 64
	jmp	.L122
	.p2align 4,,10
	.p2align 3
.L147:
	subq	$8, %rsp
	.cfi_def_cfa_offset 72
	movl	$219, %ecx
	movl	$.LC2, %esi
	pushq	$.LC18
	.cfi_def_cfa_offset 80
	movl	$.LC0, %r9d
	movl	$-3841, %r8d
	movl	$.LC17, %edx
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	movl	$-3841, %ebp
	popq	%rcx
	.cfi_def_cfa_offset 72
	popq	%rsi
	.cfi_def_cfa_offset 64
	jmp	.L122
	.p2align 4,,10
	.p2align 3
.L146:
	subq	$8, %rsp
	.cfi_def_cfa_offset 72
	movl	$-3, %r8d
	movl	$69, %edi
	pushq	$.LC23
	.cfi_def_cfa_offset 80
	movl	$.LC0, %r9d
	movl	$210, %ecx
	movl	$.LC17, %edx
	movl	$.LC2, %esi
	movl	$-3, %ebp
	call	siFormattedMessage_SC
	popq	%rdi
	.cfi_def_cfa_offset 72
	popq	%r8
	.cfi_def_cfa_offset 64
	jmp	.L122
	.p2align 4,,10
	.p2align 3
.L148:
	cmpb	$0, (%rsi)
	leaq	1(%rsi), %rax
	leaq	(%rsi,%r14), %rcx
	jne	.L130
	jmp	.L122
	.p2align 4,,10
	.p2align 3
.L132:
	leaq	1(%rax), %rdx
	cmpb	$0, -1(%rdx)
	je	.L142
	movq	%rdx, %rax
.L130:
	cmpq	%rax, %rcx
	jne	.L132
	movq	%rcx, %rax
.L142:
	subq	%rsi, %rax
.L127:
	cmpq	%rax, %r14
	jne	.L122
	jmp	.L128
	.p2align 4,,10
	.p2align 3
.L134:
	xorl	%eax, %eax
	jmp	.L127
.L145:
	call	__stack_chk_fail
	.cfi_endproc
.LFE102:
	.size	EApiAHGetStringAlloc, .-EApiAHGetStringAlloc
	.section	.text.unlikely
.LCOLDE24:
	.text
.LHOTE24:
	.section	.rodata.str1.1
.LC25:
	.string	"EApiAHCreateDecimalString"
.LC26:
	.string	"%u"
	.section	.text.unlikely
.LCOLDB27:
	.text
.LHOTB27:
	.p2align 4,,15
	.globl	EApiAHCreateDecimalString
	.type	EApiAHCreateDecimalString, @function
EApiAHCreateDecimalString:
.LFB103:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testq	%rsi, %rsi
	je	.L155
	testl	%edx, %edx
	je	.L156
	movl	%edi, %ecx
	xorl	%eax, %eax
	movq	%rsi, %rdi
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	%edx, %esi
	movl	$.LC26, %edx
	jmp	EApiSprintf
	.p2align 4,,10
	.p2align 3
.L156:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 32
	movl	$248, %ecx
.L154:
.L151:
	movl	$.LC25, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 24
	popq	%rdx
	.cfi_def_cfa_offset 16
	movl	$-1, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L155:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 32
	movl	$247, %ecx
	jmp	.L154
	.cfi_endproc
.LFE103:
	.size	EApiAHCreateDecimalString, .-EApiAHCreateDecimalString
	.section	.text.unlikely
.LCOLDE27:
	.text
.LHOTE27:
	.section	.rodata.str1.1
.LC28:
	.string	"0x%08X"
	.section	.text.unlikely
.LCOLDB29:
	.text
.LHOTB29:
	.p2align 4,,15
	.globl	EApiAHCreateHexString
	.type	EApiAHCreateHexString, @function
EApiAHCreateHexString:
.LFB104:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testq	%rsi, %rsi
	je	.L163
	testl	%edx, %edx
	je	.L164
	movl	%edi, %ecx
	xorl	%eax, %eax
	movq	%rsi, %rdi
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	%edx, %esi
	movl	$.LC28, %edx
	jmp	EApiSprintf
	.p2align 4,,10
	.p2align 3
.L164:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 32
	movl	$263, %ecx
.L162:
.L159:
	movl	$.LC25, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 24
	popq	%rdx
	.cfi_def_cfa_offset 16
	movl	$-1, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L163:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 32
	movl	$262, %ecx
	jmp	.L162
	.cfi_endproc
.LFE104:
	.size	EApiAHCreateHexString, .-EApiAHCreateHexString
	.section	.text.unlikely
.LCOLDE29:
	.text
.LHOTE29:
	.section	.rodata.str1.1
.LC30:
	.string	"%u.%02u Volts"
	.section	.text.unlikely
.LCOLDB31:
	.text
.LHOTB31:
	.p2align 4,,15
	.globl	EApiAHCreateVoltageString
	.type	EApiAHCreateVoltageString, @function
EApiAHCreateVoltageString:
.LFB105:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testq	%rsi, %rsi
	movq	%rsi, %r10
	je	.L171
	movl	%edx, %esi
	testl	%esi, %esi
	je	.L172
	movl	%edi, %eax
	movl	$-858993459, %r8d
	movl	$1374389535, %r9d
	mull	%r8d
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	shrl	$3, %edx
	movl	%edx, %eax
	movl	%edx, %r8d
	mull	%r9d
	movl	%edi, %eax
	movq	%r10, %rdi
	shrl	$5, %edx
	imull	$100, %edx, %r9d
	movl	$274877907, %edx
	mull	%edx
	xorl	%eax, %eax
	subl	%r9d, %r8d
	movl	%edx, %ecx
	movl	$.LC30, %edx
	shrl	$6, %ecx
	jmp	EApiSprintf
	.p2align 4,,10
	.p2align 3
.L172:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 32
	movl	$278, %ecx
.L170:
.L167:
	movl	$.LC25, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 24
	popq	%rdx
	.cfi_def_cfa_offset 16
	movl	$-1, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L171:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 32
	movl	$277, %ecx
	jmp	.L170
	.cfi_endproc
.LFE105:
	.size	EApiAHCreateVoltageString, .-EApiAHCreateVoltageString
	.section	.text.unlikely
.LCOLDE31:
	.text
.LHOTE31:
	.section	.rodata.str1.1
.LC32:
	.string	"%u RPM"
	.section	.text.unlikely
.LCOLDB33:
	.text
.LHOTB33:
	.p2align 4,,15
	.globl	EApiAHCreateRotationsString
	.type	EApiAHCreateRotationsString, @function
EApiAHCreateRotationsString:
.LFB106:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testq	%rsi, %rsi
	je	.L179
	testl	%edx, %edx
	je	.L180
	movl	%edi, %ecx
	xorl	%eax, %eax
	movq	%rsi, %rdi
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	%edx, %esi
	movl	$.LC32, %edx
	jmp	EApiSprintf
	.p2align 4,,10
	.p2align 3
.L180:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 32
	movl	$295, %ecx
.L178:
.L175:
	movl	$.LC25, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 24
	popq	%rdx
	.cfi_def_cfa_offset 16
	movl	$-1, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L179:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 32
	movl	$294, %ecx
	jmp	.L178
	.cfi_endproc
.LFE106:
	.size	EApiAHCreateRotationsString, .-EApiAHCreateRotationsString
	.section	.text.unlikely
.LCOLDE33:
	.text
.LHOTE33:
	.section	.rodata.str1.1
.LC34:
	.string	"% i.%i Celcius"
	.section	.text.unlikely
.LCOLDB35:
	.text
.LHOTB35:
	.p2align 4,,15
	.globl	EApiAHCreateTempString
	.type	EApiAHCreateTempString, @function
EApiAHCreateTempString:
.LFB107:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testq	%rsi, %rsi
	movq	%rsi, %r9
	je	.L187
	movl	%edx, %esi
	testl	%esi, %esi
	je	.L188
	leal	-2731(%rdi), %r8d
	movl	$-858993459, %edx
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	%r8d, %eax
	mull	%edx
	movl	%r8d, %eax
	shrl	$3, %edx
	leal	(%rdx,%rdx,4), %edi
	movl	$1717986919, %edx
	imull	%edx
	movl	%r8d, %eax
	addl	%edi, %edi
	sarl	$31, %eax
	subl	%edi, %r8d
	movq	%r9, %rdi
	movl	%edx, %ecx
	movl	$.LC34, %edx
	sarl	$2, %ecx
	subl	%eax, %ecx
	xorl	%eax, %eax
	jmp	EApiSprintf
	.p2align 4,,10
	.p2align 3
.L188:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 32
	movl	$311, %ecx
.L186:
.L183:
	movl	$.LC25, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 24
	popq	%rdx
	.cfi_def_cfa_offset 16
	movl	$-1, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L187:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 32
	movl	$310, %ecx
	jmp	.L186
	.cfi_endproc
.LFE107:
	.size	EApiAHCreateTempString, .-EApiAHCreateTempString
	.section	.text.unlikely
.LCOLDE35:
	.text
.LHOTE35:
	.section	.rodata.str1.1
.LC36:
	.string	"EApiAHCreateTimeString"
.LC37:
	.string	"%u Years "
.LC38:
	.string	"%u Days "
.LC39:
	.string	"%u Hours "
.LC40:
	.string	"%u Mins"
	.section	.text.unlikely
.LCOLDB41:
	.text
.LHOTB41:
	.p2align 4,,15
	.globl	EApiAHCreateTimeString
	.type	EApiAHCreateTimeString, @function
EApiAHCreateTimeString:
.LFB108:
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
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	testq	%rsi, %rsi
	je	.L209
	testl	%edx, %edx
	movl	%edx, %ebp
	je	.L210
	cmpl	$525599, %edi
	movl	%edi, %ebx
	movq	%rsi, %r12
	ja	.L193
.L196:
	movl	%ebx, %esi
	movl	$95443718, %edx
	movl	$1729753953, %ecx
	shrl	$5, %esi
	movl	%esi, %eax
	mull	%edx
	movl	%edx, %eax
	movl	%edx, %esi
	mull	%ecx
	movl	%esi, %ecx
	subl	%edx, %ecx
	shrl	%ecx
	leal	(%rdx,%rcx), %ecx
	shrl	$8, %ecx
	imull	$365, %ecx, %edx
	movl	%esi, %ecx
	subl	%edx, %ecx
	je	.L195
	xorl	%edi, %edi
	xorl	%eax, %eax
	xorl	%r13d, %r13d
.L194:
	movl	%ebp, %esi
	addq	%r12, %rdi
	movl	$.LC38, %edx
	subl	%eax, %esi
	xorl	%eax, %eax
	call	EApiSprintf
	addl	%eax, %r13d
	je	.L195
	movl	%ebx, %eax
	movl	$-2004318071, %edx
	movslq	%r13d, %rdi
	mull	%edx
	shrl	$5, %edx
	movl	%edx, %esi
	movl	$-1431655765, %edx
	movl	%esi, %eax
	mull	%edx
	shrl	$4, %edx
	leal	(%rdx,%rdx,2), %eax
	sall	$3, %eax
	subl	%eax, %esi
	movl	%r13d, %eax
	movl	%esi, %r8d
	jmp	.L197
	.p2align 4,,10
	.p2align 3
.L195:
	movl	%ebx, %eax
	movl	$-2004318071, %edx
	xorl	%edi, %edi
	mull	%edx
	movl	%edx, %esi
	movl	$-1431655765, %edx
	shrl	$5, %esi
	movl	%esi, %eax
	mull	%edx
	shrl	$4, %edx
	leal	(%rdx,%rdx,2), %eax
	sall	$3, %eax
	subl	%eax, %esi
	movl	%esi, %r8d
	jne	.L200
	xorl	%r13d, %r13d
.L198:
	movl	%ebx, %eax
	movl	$-2004318071, %edx
	movl	%ebp, %esi
	mull	%edx
	subl	%r8d, %esi
	addq	%r12, %rdi
	xorl	%eax, %eax
	shrl	$5, %edx
	imull	$60, %edx, %edx
	subl	%edx, %ebx
	movl	$.LC40, %edx
	movl	%ebx, %ecx
	call	EApiSprintf
	addl	%r13d, %eax
.L191:
	addq	$8, %rsp
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
.L200:
	.cfi_restore_state
	xorl	%eax, %eax
	xorl	%r13d, %r13d
.L197:
	movl	%ebp, %esi
	addq	%r12, %rdi
	movl	%r8d, %ecx
	subl	%eax, %esi
	movl	$.LC39, %edx
	xorl	%eax, %eax
	call	EApiSprintf
	addl	%eax, %r13d
	movslq	%r13d, %rdi
	movq	%rdi, %r8
	jmp	.L198
	.p2align 4,,10
	.p2align 3
.L193:
	movl	%edi, %eax
	movl	$-10721075, %edx
	movl	%ebp, %esi
	mull	%edx
	movq	%r12, %rdi
	xorl	%eax, %eax
	movl	%edx, %ecx
	movl	$.LC37, %edx
	shrl	$19, %ecx
	call	EApiSprintf
	testl	%eax, %eax
	movl	%eax, %r13d
	je	.L196
	movl	%ebx, %esi
	movl	$95443718, %edx
	movslq	%r13d, %rdi
	shrl	$5, %esi
	movl	%esi, %eax
	mull	%edx
	movl	%edx, %esi
	movl	$1729753953, %edx
	movl	%esi, %eax
	movl	%esi, %ecx
	mull	%edx
	movl	%r13d, %eax
	subl	%edx, %ecx
	shrl	%ecx
	addl	%ecx, %edx
	movl	%edx, %ecx
	shrl	$8, %ecx
	imull	$365, %ecx, %edx
	movl	%esi, %ecx
	subl	%edx, %ecx
	jmp	.L194
	.p2align 4,,10
	.p2align 3
.L210:
	subq	$8, %rsp
	.cfi_def_cfa_offset 56
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 64
	movl	$329, %ecx
.L208:
	movl	$.LC36, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 56
	movl	$-1, %eax
	popq	%rdx
	.cfi_def_cfa_offset 48
	jmp	.L191
.L209:
	subq	$8, %rsp
	.cfi_def_cfa_offset 56
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 64
	movl	$328, %ecx
	jmp	.L208
	.cfi_endproc
.LFE108:
	.size	EApiAHCreateTimeString, .-EApiAHCreateTimeString
	.section	.text.unlikely
.LCOLDE41:
	.text
.LHOTE41:
	.section	.rodata.str1.1
.LC42:
	.string	"EApiAHCreateSVersionString"
.LC43:
	.string	"%u.%u"
	.section	.text.unlikely
.LCOLDB44:
	.text
.LHOTB44:
	.p2align 4,,15
	.globl	EApiAHCreateSVersionString
	.type	EApiAHCreateSVersionString, @function
EApiAHCreateSVersionString:
.LFB109:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testq	%rsi, %rsi
	movq	%rsi, %rax
	je	.L216
	testl	%edx, %edx
	je	.L217
	movl	%edi, %r8d
	movl	%edi, %ecx
	movl	%edx, %esi
	shrl	$16, %r8d
	movq	%rax, %rdi
	shrl	$24, %ecx
	movzbl	%r8b, %r8d
	movl	$.LC43, %edx
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	jmp	EApiSprintf
	.p2align 4,,10
	.p2align 3
.L217:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC42, %edx
	movl	$.LC0, %r9d
	pushq	$.LC14
	.cfi_def_cfa_offset 32
	movl	$-1, %r8d
	movl	$355, %ecx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 24
	popq	%rdx
	.cfi_def_cfa_offset 16
.L213:
	movl	$-1, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L216:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$354, %ecx
	movl	$.LC2, %esi
	pushq	$.LC3
	.cfi_def_cfa_offset 32
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	movl	$.LC42, %edx
	movl	$69, %edi
	call	siFormattedMessage_SC
	popq	%rcx
	.cfi_def_cfa_offset 24
	popq	%rsi
	.cfi_def_cfa_offset 16
	jmp	.L213
	.cfi_endproc
.LFE109:
	.size	EApiAHCreateSVersionString, .-EApiAHCreateSVersionString
	.section	.text.unlikely
.LCOLDE44:
	.text
.LHOTE44:
	.section	.rodata.str1.1
.LC45:
	.string	"EApiAHCreateVersionString"
.LC46:
	.string	"%u.%u.%u"
	.section	.text.unlikely
.LCOLDB47:
	.text
.LHOTB47:
	.p2align 4,,15
	.globl	EApiAHCreateVersionString
	.type	EApiAHCreateVersionString, @function
EApiAHCreateVersionString:
.LFB110:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testq	%rsi, %rsi
	movq	%rsi, %rax
	je	.L223
	testl	%edx, %edx
	je	.L224
	movl	%edi, %r8d
	movl	%edi, %ecx
	movl	%edx, %esi
	shrl	$16, %r8d
	movzwl	%di, %r9d
	shrl	$24, %ecx
	movq	%rax, %rdi
	movzbl	%r8b, %r8d
	movl	$.LC46, %edx
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	jmp	EApiSprintf
	.p2align 4,,10
	.p2align 3
.L224:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC45, %edx
	movl	$.LC0, %r9d
	pushq	$.LC14
	.cfi_def_cfa_offset 32
	movl	$-1, %r8d
	movl	$372, %ecx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 24
	popq	%rdx
	.cfi_def_cfa_offset 16
.L220:
	movl	$-1, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L223:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$371, %ecx
	movl	$.LC2, %esi
	pushq	$.LC3
	.cfi_def_cfa_offset 32
	movl	$.LC0, %r9d
	movl	$-1, %r8d
	movl	$.LC45, %edx
	movl	$69, %edi
	call	siFormattedMessage_SC
	popq	%rcx
	.cfi_def_cfa_offset 24
	popq	%rsi
	.cfi_def_cfa_offset 16
	jmp	.L220
	.cfi_endproc
.LFE110:
	.size	EApiAHCreateVersionString, .-EApiAHCreateVersionString
	.section	.text.unlikely
.LCOLDE47:
	.text
.LHOTE47:
	.globl	CompressedAsciiLookup
	.data
	.align 32
	.type	CompressedAsciiLookup, @object
	.size	CompressedAsciiLookup, 32
CompressedAsciiLookup:
	.byte	32
	.byte	65
	.byte	66
	.byte	67
	.byte	68
	.byte	69
	.byte	70
	.byte	71
	.byte	72
	.byte	73
	.byte	74
	.byte	75
	.byte	76
	.byte	77
	.byte	78
	.byte	79
	.byte	80
	.byte	81
	.byte	82
	.byte	83
	.byte	84
	.byte	85
	.byte	86
	.byte	87
	.byte	88
	.byte	89
	.byte	90
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.byte	42
	.globl	ErrorLookup
	.section	.rodata.str1.1
.LC48:
	.string	"EAPI_STATUS_NOT_INITIALIZED"
.LC49:
	.string	"EAPI_STATUS_INITIALIZED"
.LC50:
	.string	"EAPI_STATUS_ALLOC_ERROR"
.LC51:
	.string	"EAPI_STATUS_DRIVER_TIMEOUT"
.LC52:
	.string	"EAPI_STATUS_INVALID_PARAMETER"
	.section	.rodata.str1.8
	.align 8
.LC53:
	.string	"EAPI_STATUS_INVALID_BLOCK_ALIGNMENT"
	.align 8
.LC54:
	.string	"EAPI_STATUS_INVALID_BLOCK_LENGTH"
	.section	.rodata.str1.1
.LC55:
	.string	"EAPI_STATUS_INVALID_DIRECTION"
.LC56:
	.string	"EAPI_STATUS_INVALID_BITMASK"
.LC57:
	.string	"EAPI_STATUS_RUNNING"
.LC58:
	.string	"EAPI_STATUS_UNSUPPORTED"
.LC59:
	.string	"EAPI_STATUS_NOT_FOUND"
.LC60:
	.string	"EAPI_STATUS_TIMEOUT"
.LC61:
	.string	"EAPI_STATUS_BUSY_COLLISION"
.LC62:
	.string	"EAPI_STATUS_READ_ERROR"
.LC63:
	.string	"EAPI_STATUS_WRITE_ERROR"
.LC64:
	.string	"EAPI_STATUS_MORE_DATA"
.LC65:
	.string	"EAPI_STATUS_ERROR"
.LC66:
	.string	"EAPI_STATUS_SUCCESS"
	.section	.rodata
	.align 32
	.type	ErrorLookup, @object
	.size	ErrorLookup, 304
ErrorLookup:
	.long	-1
	.zero	4
	.quad	.LC48
	.long	-2
	.zero	4
	.quad	.LC49
	.long	-3
	.zero	4
	.quad	.LC50
	.long	-4
	.zero	4
	.quad	.LC51
	.long	-257
	.zero	4
	.quad	.LC52
	.long	-258
	.zero	4
	.quad	.LC53
	.long	-259
	.zero	4
	.quad	.LC54
	.long	-260
	.zero	4
	.quad	.LC55
	.long	-261
	.zero	4
	.quad	.LC56
	.long	-262
	.zero	4
	.quad	.LC57
	.long	-769
	.zero	4
	.quad	.LC58
	.long	-1025
	.zero	4
	.quad	.LC59
	.long	-1026
	.zero	4
	.quad	.LC60
	.long	-1027
	.zero	4
	.quad	.LC61
	.long	-1281
	.zero	4
	.quad	.LC62
	.long	-1282
	.zero	4
	.quad	.LC63
	.long	-1537
	.zero	4
	.quad	.LC64
	.long	-3841
	.zero	4
	.quad	.LC65
	.long	0
	.zero	4
	.quad	.LC66
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
