	.file	"EApiAHI2C.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%s\n"
.LC1:
	.string	"EApiAHI2CCCreateAddrOffset"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHI2C.c"
	.section	.rodata.str1.1
.LC3:
	.string	"(pDDesc==NULL)"
.LC4:
	.string	"(pEncAddr==NULL)"
.LC5:
	.string	"(pEncOffset==NULL)"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB6:
	.text
.LHOTB6:
	.p2align 4,,15
	.globl	EApiAHI2CCCreateAddrOffset
	.type	EApiAHI2CCCreateAddrOffset, @function
EApiAHI2CCCreateAddrOffset:
.LFB99:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testq	%rdi, %rdi
	je	.L15
	testq	%rdx, %rdx
	je	.L16
	testq	%rcx, %rcx
	je	.L17
	cmpw	$2, 4(%rdi)
	je	.L18
	movzbl	%sil, %eax
	shrq	$8, %rsi
	movq	%rax, (%rcx)
.L13:
	movzwl	(%rdi), %eax
	andl	$3, %esi
	movl	%eax, %ecx
	andw	$-2048, %cx
	cmpw	$-4096, %cx
	je	.L19
.L3:
	shrw	%ax
	addl	%eax, %esi
	xorl	%eax, %eax
	addl	%esi, %esi
	movzbl	%sil, %esi
	movq	%rsi, (%rdx)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L18:
	.cfi_restore_state
	movzwl	%si, %eax
	shrq	$16, %rsi
	orl	$-2147483648, %eax
	movq	%rax, (%rcx)
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L19:
	movl	%eax, %edi
	movzbl	%al, %ecx
	shrw	%di
	andw	$768, %di
	movl	%edi, %eax
	orl	%ecx, %eax
	movzwl	%ax, %eax
	addl	%eax, %esi
	movl	%esi, %eax
	movzbl	%sil, %esi
	andl	$768, %eax
	orl	$61440, %esi
	addl	%eax, %eax
	orl	%eax, %esi
	movl	%esi, %eax
	movq	%rax, (%rdx)
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L15:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC3
	.cfi_def_cfa_offset 32
	movl	$51, %ecx
.L10:
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 24
	popq	%rdx
	.cfi_def_cfa_offset 16
	movl	$-257, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L16:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC4
	.cfi_def_cfa_offset 32
	movl	$56, %ecx
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L17:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC5
	.cfi_def_cfa_offset 32
	movl	$61, %ecx
	jmp	.L10
	.cfi_endproc
.LFE99:
	.size	EApiAHI2CCCreateAddrOffset, .-EApiAHI2CCCreateAddrOffset
	.section	.text.unlikely
.LCOLDE6:
	.text
.LHOTE6:
	.section	.text.unlikely
.LCOLDB7:
	.text
.LHOTB7:
	.p2align 4,,15
	.globl	ValidEEPDevDesc
	.type	ValidEEPDevDesc, @function
ValidEEPDevDesc:
.LFB100:
	.cfi_startproc
	xorl	%eax, %eax
	cmpw	$2, 4(%rdi)
	je	.L21
	movl	8(%rdi), %eax
	shrl	$8, %eax
	addl	%eax, %eax
	je	.L21
	movzwl	(%rdi), %edx
	addl	%edx, %eax
	movl	$-257, %edx
	cmpl	$176, %eax
	movl	$0, %eax
	cmovge	%edx, %eax
.L21:
	rep ret
	.cfi_endproc
.LFE100:
	.size	ValidEEPDevDesc, .-ValidEEPDevDesc
	.section	.text.unlikely
.LCOLDE7:
	.text
.LHOTE7:
	.section	.rodata.str1.1
.LC8:
	.string	"EApiAHI2CWriteEeprom"
.LC9:
	.string	"(pBuffer==NULL)"
.LC10:
	.string	"(ByteCnt==0)"
	.section	.rodata.str1.8
	.align 8
.LC11:
	.string	"Prevented Write beyond Device Boundary"
	.align 8
.LC12:
	.string	"Invalid EEPROM Device Descriptor"
	.section	.text.unlikely
.LCOLDB13:
	.text
.LHOTB13:
	.p2align 4,,15
	.globl	EApiAHI2CWriteEeprom
	.type	EApiAHI2CWriteEeprom, @function
EApiAHI2CWriteEeprom:
.LFB101:
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
	testq	%rsi, %rsi
	movl	%edi, 4(%rsp)
	je	.L64
	testq	%rcx, %rcx
	movq	%rcx, %r14
	je	.L65
	testq	%r8, %r8
	je	.L66
	cmpw	$2, 4(%rsi)
	movq	%rsi, %rbp
	movq	%rdx, %r15
	je	.L32
	movl	8(%rsi), %edx
	movl	%edx, %eax
	shrl	$8, %eax
	addl	%eax, %eax
	je	.L33
	movzwl	(%rsi), %ecx
	addl	%ecx, %eax
	cmpl	$175, %eax
	jle	.L33
	subq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC12
	.cfi_def_cfa_offset 112
	movl	$156, %ecx
	jmp	.L62
	.p2align 4,,10
	.p2align 3
.L66:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC10
	.cfi_def_cfa_offset 112
	movl	$150, %ecx
.L62:
	movl	$.LC8, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 104
	popq	%rdx
	.cfi_def_cfa_offset 96
	movl	$-257, (%rsp)
.L29:
.L46:
	movq	24(%rsp), %rbx
	xorq	%fs:40, %rbx
	movl	(%rsp), %eax
	jne	.L67
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
.L33:
	.cfi_restore_state
	leaq	(%r8,%r15), %r13
	cmpq	%rdx, %r13
	ja	.L47
.L48:
	movl	4(%rsp), %edi
	leaq	20(%rsp), %rsi
	call	EApiI2CGetBusCap
	testl	%eax, %eax
	movl	%eax, (%rsp)
	jne	.L46
	movzwl	0(%rbp), %ecx
	movzwl	4(%rbp), %edi
	movl	20(%rsp), %r8d
	movl	%ecx, %eax
	movzbl	%cl, %edx
	shrw	%ax
	movq	%r8, %r10
	andw	$768, %ax
	orw	%dx, %ax
	movzwl	%di, %eax
	setne	%dl
	movzbl	%dl, %edx
	addl	%edx, %eax
	movzwl	2(%rbp), %edx
	cltq
	subq	%rax, %r10
	leaq	(%rax,%rdx), %rbx
	movq	%rdx, %rsi
	cmpq	%rbx, %r8
	cmovb	%r10, %rdx
	cmpw	$2, %di
	je	.L68
	cmpq	$256, %rdx
	movl	$256, %eax
	cmovbe	%rdx, %rax
	movq	%rax, 8(%rsp)
.L37:
	cmpq	%r13, %r15
	jnb	.L46
	movq	%r15, %rbx
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L45:
	cmpq	%rbx, %r13
	jbe	.L46
	movzwl	4(%rbp), %edi
	movzwl	0(%rbp), %ecx
	movzwl	2(%rbp), %esi
.L39:
	movq	8(%rsp), %rdx
	movq	%r13, %r12
	subq	%rbx, %r12
	movq	%rdx, %rax
	addq	%rbx, %rax
	cmpq	%rax, %r13
	movq	%rbx, %rax
	cmovnb	%rdx, %r12
	xorl	%edx, %edx
	divq	%rsi
	addq	%r12, %rdx
	cmpq	%rsi, %rdx
	jbe	.L50
	leaq	(%rbx,%r12), %rax
	xorl	%edx, %edx
	divq	%rsi
	subq	%rdx, %r12
.L50:
	cmpw	$2, %di
	je	.L69
	movq	%rbx, %rax
	movl	%ecx, %esi
	movzbl	%bl, %edx
	shrq	$8, %rax
	andw	$-2048, %si
	andl	$3, %eax
	cmpw	$-4096, %si
	je	.L70
.L44:
	shrw	%cx
	leal	(%rcx,%rax), %esi
	addl	%esi, %esi
	movzbl	%sil, %esi
.L43:
	movq	%rbx, %rcx
	movl	4(%rsp), %edi
	movl	%r12d, %r8d
	subq	%r15, %rcx
	addq	%r14, %rcx
	call	EApiI2CWriteTransfer
	testl	%eax, %eax
	jne	.L53
	movzwl	6(%rbp), %edi
	addq	%r12, %rbx
	testw	%di, %di
	je	.L45
	imull	$1000, %edi, %edi
	call	usleep
	jmp	.L45
	.p2align 4,,10
	.p2align 3
.L32:
	movl	8(%rsi), %eax
	leaq	(%r8,%rdx), %r13
	cmpq	%rax, %r13
	jbe	.L48
.L47:
	subq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC11
	.cfi_def_cfa_offset 112
	movl	$162, %ecx
	jmp	.L62
	.p2align 4,,10
	.p2align 3
.L69:
	.cfi_restore_state
	movq	%rbx, %rax
	movl	%ecx, %esi
	movzwl	%bx, %edx
	shrq	$16, %rax
	andw	$-2048, %si
	orl	$-2147483648, %edx
	andl	$3, %eax
	cmpw	$-4096, %si
	jne	.L44
	movl	%ecx, %edi
	movzbl	%cl, %esi
	shrw	%di
	andw	$768, %di
	orl	%esi, %edi
	movzwl	%di, %ecx
	addl	%ecx, %eax
	movl	%eax, %esi
	movzbl	%al, %eax
	andl	$768, %esi
	orb	$240, %ah
	addl	%esi, %esi
	orl	%eax, %esi
	jmp	.L43
	.p2align 4,,10
	.p2align 3
.L64:
	subq	$8, %rsp
	.cfi_def_cfa_offset 104
	movl	$140, %ecx
	movl	$.LC2, %esi
	pushq	$.LC3
	.cfi_def_cfa_offset 112
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$.LC8, %edx
	movl	$69, %edi
	call	siFormattedMessage_SC
	popq	%rcx
	.cfi_def_cfa_offset 104
	popq	%rsi
	.cfi_def_cfa_offset 96
	movl	$-257, (%rsp)
	jmp	.L46
	.p2align 4,,10
	.p2align 3
.L65:
	subq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC9
	.cfi_def_cfa_offset 112
	movl	$145, %ecx
	jmp	.L62
	.p2align 4,,10
	.p2align 3
.L70:
	.cfi_restore_state
	movl	%ecx, %edi
	movzbl	%cl, %esi
	shrw	%di
	andw	$768, %di
	orl	%esi, %edi
	movzwl	%di, %ecx
	addl	%ecx, %eax
	movzbl	%al, %esi
	andl	$768, %eax
	orl	$61440, %esi
	addl	%eax, %eax
	orl	%eax, %esi
	jmp	.L43
	.p2align 4,,10
	.p2align 3
.L53:
	movl	%eax, (%rsp)
	jmp	.L46
	.p2align 4,,10
	.p2align 3
.L68:
	cmpq	$65536, %rdx
	movl	$65536, %eax
	cmovbe	%rdx, %rax
	movq	%rax, 8(%rsp)
	jmp	.L37
.L67:
	call	__stack_chk_fail
	.cfi_endproc
.LFE101:
	.size	EApiAHI2CWriteEeprom, .-EApiAHI2CWriteEeprom
	.section	.text.unlikely
.LCOLDE13:
	.text
.LHOTE13:
	.section	.rodata.str1.1
.LC14:
	.string	"EApiAHI2CReadEeprom"
.LC15:
	.string	"(BufLength==0)"
	.section	.rodata.str1.8
	.align 8
.LC16:
	.string	" pBuffer Overflow PreventedByteCnt>BufLength"
	.section	.text.unlikely
.LCOLDB17:
	.text
.LHOTB17:
	.p2align 4,,15
	.globl	EApiAHI2CReadEeprom
	.type	EApiAHI2CReadEeprom, @function
EApiAHI2CReadEeprom:
.LFB102:
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
	testq	%rsi, %rsi
	je	.L102
	testq	%rcx, %rcx
	movq	%rcx, %r14
	je	.L103
	testq	%r8, %r8
	movq	%r8, %rbp
	je	.L104
	testq	%r9, %r9
	je	.L105
	cmpq	%r9, %r8
	movl	%edi, %r11d
	movq	%rsi, %r12
	movq	%rdx, %r10
	jb	.L106
.L77:
	cmpw	$2, 4(%r12)
	je	.L78
	movl	8(%r12), %edx
	movl	%edx, %eax
	shrl	$8, %eax
	addl	%eax, %eax
	je	.L79
	movzwl	(%r12), %ecx
	addl	%ecx, %eax
	cmpl	$175, %eax
	jg	.L80
.L79:
	leaq	(%r9,%r10), %rbx
	cmpq	%rdx, %rbx
	ja	.L91
.L92:
	leaq	20(%rsp), %rsi
	movl	%r11d, %edi
	movq	%r10, 8(%rsp)
	movl	%r11d, 4(%rsp)
	call	EApiI2CGetBusCap
	testl	%eax, %eax
	movl	%eax, %r15d
	jne	.L90
	movzwl	4(%r12), %eax
	movl	4(%rsp), %r11d
	movq	8(%rsp), %r10
	cmpw	$2, %ax
	je	.L107
	cmpl	$256, 20(%rsp)
	movl	$256, %r13d
	cmovbe	20(%rsp), %r13d
	movl	%r13d, %r13d
.L82:
	cmpq	%rbx, %r10
	jnb	.L90
	movq	%r10, %rbp
	jmp	.L84
	.p2align 4,,10
	.p2align 3
.L86:
	movzwl	(%r12), %esi
	movq	%rbp, %rax
	movzbl	%bpl, %edx
	shrq	$8, %rax
	andl	$3, %eax
	movq	%rax, %r8
	movl	%esi, %eax
	andw	$-2048, %ax
	cmpw	$-4096, %ax
	je	.L108
.L89:
	shrw	%si
	addl	%r8d, %esi
	addl	%esi, %esi
	movzbl	%sil, %esi
.L88:
	movq	%rbp, %rcx
	movl	%r13d, %r9d
	movl	%r13d, %r8d
	subq	%r10, %rcx
	movl	%r11d, %edi
	movq	%r10, 8(%rsp)
	addq	%r14, %rcx
	movl	%r11d, 4(%rsp)
	call	EApiI2CReadTransfer
	testl	%eax, %eax
	jne	.L94
	addq	%r13, %rbp
	cmpq	%rbx, %rbp
	jnb	.L90
	movzwl	4(%r12), %eax
	movl	4(%rsp), %r11d
	movq	8(%rsp), %r10
.L84:
	leaq	0(%r13,%rbp), %rcx
	movq	%rbx, %rdx
	subq	%rbp, %rdx
	cmpq	%rbx, %rcx
	cmova	%rdx, %r13
	cmpw	$2, %ax
	jne	.L86
	movzwl	(%r12), %esi
	movq	%rbp, %rax
	movzwl	%bp, %edx
	shrq	$16, %rax
	orl	$-2147483648, %edx
	andl	$3, %eax
	movq	%rax, %r8
	movl	%esi, %eax
	andw	$-2048, %ax
	cmpw	$-4096, %ax
	jne	.L89
	movl	%esi, %ecx
	movzbl	%sil, %edi
	shrw	%cx
	andw	$768, %cx
	orl	%edi, %ecx
	movzwl	%cx, %ecx
	leal	(%rcx,%r8), %eax
	movl	%eax, %esi
	movzbl	%al, %eax
	andl	$768, %esi
	orb	$240, %ah
	addl	%esi, %esi
	orl	%eax, %esi
	jmp	.L88
	.p2align 4,,10
	.p2align 3
.L104:
	subq	$8, %rsp
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC15
	.cfi_def_cfa_offset 112
	movl	$327, %ecx
.L100:
	movl	$.LC2, %esi
	movl	$.LC14, %edx
	movl	$69, %edi
	xorl	%eax, %eax
	movl	$-257, %r15d
	call	siFormattedMessage_SC
	popq	%rcx
	.cfi_def_cfa_offset 104
	popq	%rsi
	.cfi_def_cfa_offset 96
.L73:
.L90:
	movq	24(%rsp), %rbx
	xorq	%fs:40, %rbx
	movl	%r15d, %eax
	jne	.L109
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
.L106:
	.cfi_restore_state
	movq	%rdx, 8(%rsp)
	movl	%edi, 4(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 104
	pushq	$.LC16
	.cfi_def_cfa_offset 112
	movl	$.LC0, %r9d
	movl	$.LC14, %edx
	movl	$-1537, %r8d
	movl	$337, %ecx
	movl	$.LC2, %esi
	movl	$69, %edi
	xorl	%eax, %eax
	call	siFormattedMessage_SC
	popq	%rax
	.cfi_def_cfa_offset 104
	popq	%rdx
	.cfi_def_cfa_offset 96
	movq	%rbp, %r9
	movq	8(%rsp), %r10
	movl	4(%rsp), %r11d
	jmp	.L77
	.p2align 4,,10
	.p2align 3
.L78:
	movl	8(%r12), %eax
	leaq	(%r9,%r10), %rbx
	cmpq	%rbx, %rax
	jnb	.L92
.L91:
	subq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC11
	.cfi_def_cfa_offset 112
	movl	$349, %ecx
	jmp	.L100
	.p2align 4,,10
	.p2align 3
.L80:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC12
	.cfi_def_cfa_offset 112
	movl	$343, %ecx
	jmp	.L100
	.p2align 4,,10
	.p2align 3
.L105:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC10
	.cfi_def_cfa_offset 112
	movl	$332, %ecx
	jmp	.L100
	.p2align 4,,10
	.p2align 3
.L102:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 104
	movl	$-257, %r8d
	movl	$69, %edi
	pushq	$.LC3
	.cfi_def_cfa_offset 112
	movl	$.LC0, %r9d
	movl	$317, %ecx
	movl	$.LC14, %edx
	movl	$.LC2, %esi
	movl	$-257, %r15d
	call	siFormattedMessage_SC
	popq	%rdi
	.cfi_def_cfa_offset 104
	popq	%r8
	.cfi_def_cfa_offset 96
	jmp	.L90
	.p2align 4,,10
	.p2align 3
.L103:
	subq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 104
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	pushq	$.LC9
	.cfi_def_cfa_offset 112
	movl	$322, %ecx
	jmp	.L100
	.p2align 4,,10
	.p2align 3
.L108:
	.cfi_restore_state
	movl	%esi, %ecx
	movzbl	%sil, %edi
	shrw	%cx
	andw	$768, %cx
	orl	%edi, %ecx
	movzwl	%cx, %ecx
	leal	(%rcx,%r8), %eax
	movzbl	%al, %esi
	andl	$768, %eax
	orl	$61440, %esi
	addl	%eax, %eax
	orl	%eax, %esi
	jmp	.L88
	.p2align 4,,10
	.p2align 3
.L94:
	movl	%eax, %r15d
	jmp	.L90
	.p2align 4,,10
	.p2align 3
.L107:
	cmpl	$65536, 20(%rsp)
	movl	$65536, %r13d
	cmovbe	20(%rsp), %r13d
	movl	%r13d, %r13d
	jmp	.L82
.L109:
	call	__stack_chk_fail
	.cfi_endproc
.LFE102:
	.size	EApiAHI2CReadEeprom, .-EApiAHI2CReadEeprom
	.section	.text.unlikely
.LCOLDE17:
	.text
.LHOTE17:
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
