	.file	"EApiValidateAPI.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%-30s : %s\n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"%-30s : EAPI_STATUS_UNSUPPORTED\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	EApiValidateStringApi
	.type	EApiValidateStringApi, @function
EApiValidateStringApi:
.LFB100:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	$100, %edi
	movl	$EApiStrings+8, %ebx
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movl	$100, 4(%rsp)
	call	malloc
	movl	$10, %edi
	movq	%rax, %rbp
	call	putchar
	jmp	.L4
	.p2align 4,,10
	.p2align 3
.L11:
	movq	(%rbx), %rdx
	movq	%rbp, %rcx
	movl	$.LC0, %esi
	movl	$1, %edi
	addq	$16, %rbx
	call	__printf_chk
	cmpq	$EApiStrings+136, %rbx
	je	.L10
.L4:
	movl	-8(%rbx), %edi
	leaq	4(%rsp), %rdx
	movq	%rbp, %rsi
	movl	$100, 4(%rsp)
	call	EApiBoardGetStringA
	testl	%eax, %eax
	je	.L11
	movq	(%rbx), %rdx
	xorl	%eax, %eax
	movl	$.LC1, %esi
	movl	$1, %edi
	addq	$16, %rbx
	call	__printf_chk
	cmpq	$EApiStrings+136, %rbx
	jne	.L4
.L10:
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L12
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%rbp, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	free
.L12:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE100:
	.size	EApiValidateStringApi, .-EApiValidateStringApi
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.text.unlikely
.LCOLDB3:
	.text
.LHOTB3:
	.p2align 4,,15
	.globl	EApiValidateValuesApi
	.type	EApiValidateValuesApi, @function
EApiValidateValuesApi:
.LFB101:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$10, %edi
	movl	$EApiValues+8, %ebx
	subq	$1056, %rsp
	.cfi_def_cfa_offset 1072
	movq	%fs:40, %rax
	movq	%rax, 1048(%rsp)
	xorl	%eax, %eax
	call	putchar
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L22:
	movl	$1024, %edx
	leaq	16(%rsp), %rsi
	movl	12(%rsp), %edi
	call	*8(%rbx)
.L20:
	movq	(%rbx), %rdx
	leaq	16(%rsp), %rcx
	xorl	%eax, %eax
	movl	$.LC0, %esi
	movl	$1, %edi
	addq	$24, %rbx
	call	__printf_chk
	cmpq	$EApiValues+416, %rbx
	je	.L21
.L16:
	movl	-8(%rbx), %edi
	leaq	12(%rsp), %rsi
	call	EApiBoardGetValue
	testl	%eax, %eax
	je	.L22
	leaq	16(%rsp), %rsi
	movl	$1024, %edx
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	jmp	.L20
	.p2align 4,,10
	.p2align 3
.L21:
	movq	1048(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L23
	addq	$1056, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L23:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE101:
	.size	EApiValidateValuesApi, .-EApiValidateValuesApi
	.section	.text.unlikely
.LCOLDE3:
	.text
.LHOTE3:
	.section	.rodata.str1.1
.LC4:
	.string	"%x  "
.LC5:
	.string	"Reyyyy in ke error e "
.LC6:
	.string	"Reyyyy that is wunderbar"
.LC7:
	.string	"Reyyyy that is an error"
	.section	.text.unlikely
.LCOLDB10:
	.text
.LHOTB10:
	.p2align 4,,15
	.globl	EApiValidateI2CApi
	.type	EApiValidateI2CApi, @function
EApiValidateI2CApi:
.LFB103:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	$64, %r9d
	movl	$64, %r8d
	movl	$-2147483648, %edx
	movl	$80, %esi
	subq	$152, %rsp
	.cfi_def_cfa_offset 176
	movl	$11, %edi
	leaq	64(%rsp), %rcx
	movq	%fs:40, %rax
	movq	%rax, 136(%rsp)
	xorl	%eax, %eax
	call	EApiI2CReadTransfer
	testl	%eax, %eax
	jne	.L25
	xorl	%ebx, %ebx
	jmp	.L28
	.p2align 4,,10
	.p2align 3
.L26:
	testb	$7, %bl
	je	.L45
.L27:
	movzbl	64(%rsp,%rbx), %edx
	xorl	%eax, %eax
	movl	$.LC4, %esi
	movl	$1, %edi
	addq	$1, %rbx
	call	__printf_chk
	cmpq	$64, %rbx
	je	.L46
.L28:
	testb	$15, %bl
	jne	.L26
	movl	$10, %edi
	call	putchar
	jmp	.L27
	.p2align 4,,10
	.p2align 3
.L45:
	movl	$32, %edi
	call	putchar
	jmp	.L27
	.p2align 4,,10
	.p2align 3
.L46:
	movl	$10, %edi
	call	putchar
.L29:
	xorl	%ebx, %ebx
	jmp	.L32
	.p2align 4,,10
	.p2align 3
.L48:
	movzbl	15(%rsp), %edx
	movl	$.LC4, %esi
	movl	$1, %edi
	addl	$1, %ebx
	call	__printf_chk
	movl	$10, %edi
	call	putchar
	cmpl	$8, %ebx
	je	.L47
.L32:
	leaq	15(%rsp), %rcx
	movl	$1, %r9d
	movl	$1, %r8d
	movl	%ebx, %edx
	movl	$39, %esi
	movl	$11, %edi
	call	EApiI2CReadTransfer
	testl	%eax, %eax
	je	.L48
	movl	$.LC5, %edi
	addl	$1, %ebx
	call	puts
	cmpl	$8, %ebx
	jne	.L32
.L47:
	leaq	16(%rsp), %rbx
	movb	$0, 16(%rsp)
	movb	$1, 17(%rsp)
	movb	$2, 18(%rsp)
	movb	$3, 19(%rsp)
	movb	$4, 20(%rsp)
	movb	$5, 21(%rsp)
	leaq	10(%rbx), %rbp
	movb	$6, 22(%rsp)
	movb	$7, 23(%rsp)
	movb	$8, 24(%rsp)
	movb	$9, 25(%rsp)
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L50:
	movl	$.LC6, %edi
	call	puts
.L34:
	movl	$5, %edi
	addq	$1, %rbx
	call	sleep
	cmpq	%rbx, %rbp
	je	.L49
.L35:
	movl	$1, %r8d
	movq	%rbx, %rcx
	movl	$2, %edx
	movl	$39, %esi
	movl	$11, %edi
	call	EApiI2CWriteTransfer
	testl	%eax, %eax
	je	.L50
	movl	$.LC7, %edi
	call	puts
	jmp	.L34
	.p2align 4,,10
	.p2align 3
.L49:
	movdqa	.LC8(%rip), %xmm0
	leaq	32(%rsp), %rbp
	xorl	%ebx, %ebx
	movaps	%xmm0, 32(%rsp)
	movdqa	.LC9(%rip), %xmm0
	movaps	%xmm0, 48(%rsp)
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L52:
	movl	$.LC6, %edi
	call	puts
.L37:
	movl	$1, %edi
	addl	$1, %ebx
	addq	$1, %rbp
	call	sleep
	cmpl	$32, %ebx
	je	.L51
.L38:
	movl	%ebx, %edx
	movl	$1, %r8d
	movq	%rbp, %rcx
	orl	$-2147483648, %edx
	movl	$80, %esi
	movl	$11, %edi
	call	EApiI2CWriteTransfer
	testl	%eax, %eax
	je	.L52
	movl	$.LC7, %edi
	call	puts
	jmp	.L37
	.p2align 4,,10
	.p2align 3
.L51:
	movq	136(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L53
	addq	$152, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L25:
	.cfi_restore_state
	movl	$.LC5, %edi
	call	puts
	jmp	.L29
.L53:
	call	__stack_chk_fail
	.cfi_endproc
.LFE103:
	.size	EApiValidateI2CApi, .-EApiValidateI2CApi
	.section	.text.unlikely
.LCOLDE10:
	.text
.LHOTE10:
	.section	.rodata.str1.1
.LC11:
	.string	"%c%04i %-30s | "
.LC12:
	.string	"               0x%08X | "
.LC13:
	.string	"%-25s | "
.LC14:
	.string	"   %2d    %2d    [%s]\n"
	.section	.text.unlikely
.LCOLDB15:
	.text
.LHOTB15:
	.p2align 4,,15
	.type	siFFormattedMessage_SC.constprop.0, @function
siFFormattedMessage_SC.constprop.0:
.LFB107:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rcx, %r12
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movl	%r9d, %ebp
	movq	%rdi, %rbx
	subq	$240, %rsp
	.cfi_def_cfa_offset 272
	testb	%al, %al
	je	.L55
	movaps	%xmm0, 112(%rsp)
	movaps	%xmm1, 128(%rsp)
	movaps	%xmm2, 144(%rsp)
	movaps	%xmm3, 160(%rsp)
	movaps	%xmm4, 176(%rsp)
	movaps	%xmm5, 192(%rsp)
	movaps	%xmm6, 208(%rsp)
	movaps	%xmm7, 224(%rsp)
.L55:
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	leaq	280(%rsp), %rax
	leaq	24(%rsp), %rdi
	movl	%ebp, %esi
	movq	%rax, 40(%rsp)
	leaq	64(%rsp), %rax
	movl	%r8d, 12(%rsp)
	movl	$48, 32(%rsp)
	movl	$48, 36(%rsp)
	movq	%rax, 48(%rsp)
	call	EApiGetErrorStringA
	movl	12(%rsp), %r8d
	movq	%r12, %r9
	movl	$76, %ecx
	xorl	%eax, %eax
	movl	$.LC11, %edx
	movl	$1, %esi
	movq	%rbx, %rdi
	call	__fprintf_chk
	movq	24(%rsp), %rcx
	movl	%eax, %r12d
	testq	%rcx, %rcx
	je	.L60
	movl	$.LC13, %edx
	movl	$1, %esi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	call	__fprintf_chk
.L57:
	leaq	32(%rsp), %rcx
	movl	$.LC14, %edx
	movl	$1, %esi
	movq	%rbx, %rdi
	call	__vfprintf_chk
	addl	%r12d, %eax
	movq	56(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L61
	addq	$240, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L60:
	.cfi_restore_state
	movl	%ebp, %ecx
	movl	$.LC12, %edx
	movl	$1, %esi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	call	__fprintf_chk
	jmp	.L57
.L61:
	call	__stack_chk_fail
	.cfi_endproc
.LFE107:
	.size	siFFormattedMessage_SC.constprop.0, .-siFFormattedMessage_SC.constprop.0
	.section	.text.unlikely
.LCOLDE15:
	.text
.LHOTE15:
	.section	.rodata.str1.1
.LC16:
	.string	"%-30s : "
.LC17:
	.string	"%02X"
.LC18:
	.string	"%-30s : %02X %s\n"
.LC19:
	.string	"EApiStorageAreaRead"
	.section	.rodata.str1.8
	.align 8
.LC20:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../EApiValidateAPI.c"
	.section	.rodata.str1.1
.LC21:
	.string	"EApiStorageAreaWrite"
.LC22:
	.string	"EApiStorageCap"
	.section	.text.unlikely
.LCOLDB23:
	.text
.LHOTB23:
	.p2align 4,,15
	.globl	EApiValidateStorageApi
	.type	EApiValidateStorageApi, @function
EApiValidateStorageApi:
.LFB104:
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
	movl	$EApiStorageDevices, %r12d
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$1064, %rsp
	.cfi_def_cfa_offset 1120
	movq	%fs:40, %rax
	movq	%rax, 1048(%rsp)
	xorl	%eax, %eax
	leaq	32(%rsp), %rbx
	movq	$I2CDevices, (%rsp)
.L68:
	movl	16(%r12), %r13d
	movl	(%r12), %r15d
	leaq	16(%rsp), %rdx
	xorl	%esi, %esi
	movl	$1024, %ecx
	movl	%r13d, %r8d
	movl	%r15d, %edi
	call	EApiStorageAreaRead
	testl	%eax, %eax
	jne	.L63
	movq	8(%r12), %rax
	movl	$.LC16, %esi
	movl	$1, %edi
	leaq	16(%rsp), %r14
	movq	%rax, 8(%rsp)
	movq	%rax, %rdx
	xorl	%eax, %eax
	call	__printf_chk
	movq	stdout(%rip), %rbp
	.p2align 4,,10
	.p2align 3
.L64:
	movzbl	(%r14), %ecx
	xorl	%eax, %eax
	movl	$.LC17, %edx
	movl	$1, %esi
	movq	%rbp, %rdi
	addq	$1, %r14
	call	__fprintf_chk
	cmpq	%rbx, %r14
	jne	.L64
	movl	$10, %edi
	call	putchar
	movl	$-858993459, %eax
	movl	$13, %esi
	movl	%r15d, %edi
	mull	%r13d
	movl	%edx, %ecx
	leaq	16(%rsp), %rdx
	shrl	$2, %ecx
	call	EApiAHWriteStorage
	testl	%eax, %eax
	jne	.L65
	movq	8(%rsp), %rdx
	movl	$.LC16, %esi
	movl	$1, %edi
	leaq	16(%rsp), %r13
	call	__printf_chk
	movq	stdout(%rip), %rbp
	.p2align 4,,10
	.p2align 3
.L66:
	movzbl	0(%r13), %ecx
	xorl	%eax, %eax
	movl	$.LC17, %edx
	movl	$1, %esi
	movq	%rbp, %rdi
	addq	$1, %r13
	call	__fprintf_chk
	cmpq	%rbx, %r13
	jne	.L66
	movl	$10, %edi
	call	putchar
.L67:
	addq	$24, %r12
	movl	$EApiStorageDevices+72, %eax
	addq	$12, (%rsp)
	cmpq	%r12, %rax
	jne	.L68
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L73:
	movl	$StorageValidate+28, %ebx
	xorl	%ebp, %ebp
	.p2align 4,,10
	.p2align 3
.L72:
	movl	-8(%rbx), %r15d
	movq	-20(%rbx), %r14
	movl	%r12d, %edi
	movl	-28(%rbx), %r13d
	movl	-12(%rbx), %ecx
	movq	%r14, %rdx
	movl	%r15d, %r8d
	movl	%r13d, %esi
	call	EApiStorageAreaRead
	movl	-4(%rbx), %r10d
	movl	%eax, %r9d
	movl	$1, %edx
	cmpl	%r10d, %eax
	je	.L70
	cmpl	(%rbx), %eax
	je	.L70
	xorl	%edx, %edx
	cmpl	%eax, 4(%rbx)
	sete	%dl
.L70:
	movq	LogStream(%rip), %rdi
	movl	%r10d, (%rsp)
	movl	$730, %r8d
	pushq	FailPass(,%rdx,8)
	.cfi_def_cfa_offset 1128
	pushq	%rbp
	.cfi_def_cfa_offset 1136
	movl	$.LC19, %ecx
	pushq	%r12
	.cfi_def_cfa_offset 1144
	pushq	$.LC14
	.cfi_def_cfa_offset 1152
	movl	$.LC20, %edx
	movl	$76, %esi
	xorl	%eax, %eax
	call	siFFormattedMessage_SC.constprop.0
	addq	$32, %rsp
	.cfi_def_cfa_offset 1120
	movq	%r14, %rdx
	movl	%r15d, %ecx
	movl	%r13d, %esi
	movl	%r12d, %edi
	call	EApiStorageAreaWrite
	movl	(%rsp), %r10d
	movl	%eax, %r9d
	movl	$1, %edx
	cmpl	%eax, %r10d
	je	.L71
	cmpl	(%rbx), %eax
	je	.L71
	xorl	%edx, %edx
	cmpl	%eax, 4(%rbx)
	sete	%dl
.L71:
	movq	LogStream(%rip), %rdi
	pushq	FailPass(,%rdx,8)
	.cfi_def_cfa_offset 1128
	xorl	%eax, %eax
	pushq	%rbp
	.cfi_def_cfa_offset 1136
	pushq	%r12
	.cfi_def_cfa_offset 1144
	movl	$738, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 1152
	movl	$.LC21, %ecx
	movl	$.LC20, %edx
	movl	$76, %esi
	addl	$1, %ebp
	addq	$40, %rbx
	call	siFFormattedMessage_SC.constprop.0
	addq	$32, %rsp
	.cfi_def_cfa_offset 1120
	cmpl	$6, %ebp
	jne	.L72
	addl	$1, %r12d
	cmpl	$10, %r12d
	jne	.L73
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L77:
	movl	$StorageCapValidate, %ebx
	xorl	%ebp, %ebp
.L76:
	movq	8(%rbx), %rdx
	movq	(%rbx), %rsi
	movl	%r12d, %edi
	call	EApiStorageCap
	cmpl	16(%rbx), %eax
	movl	%eax, %r9d
	movl	$1, %edx
	je	.L75
	cmpl	20(%rbx), %eax
	je	.L75
	xorl	%edx, %edx
	cmpl	%eax, 24(%rbx)
	sete	%dl
.L75:
	movq	LogStream(%rip), %rdi
	pushq	FailPass(,%rdx,8)
	.cfi_def_cfa_offset 1128
	xorl	%eax, %eax
	pushq	%rbp
	.cfi_def_cfa_offset 1136
	pushq	%r12
	.cfi_def_cfa_offset 1144
	movl	$751, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 1152
	movl	$.LC22, %ecx
	movl	$.LC20, %edx
	movl	$76, %esi
	addl	$1, %ebp
	addq	$32, %rbx
	call	siFFormattedMessage_SC.constprop.0
	addq	$32, %rsp
	.cfi_def_cfa_offset 1120
	cmpl	$4, %ebp
	jne	.L76
	addl	$1, %r12d
	cmpl	$10, %r12d
	jne	.L77
	movq	1048(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L95
	addq	$1064, %rsp
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
.L63:
	.cfi_restore_state
	leaq	16(%rsp), %rsi
	movl	$1024, %edx
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	movq	8(%r12), %rdx
	leaq	16(%rsp), %rcx
	movl	$.LC0, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	jmp	.L67
	.p2align 4,,10
	.p2align 3
.L65:
	leaq	16(%rsp), %rsi
	movl	$1024, %edx
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	movq	(%rsp), %rax
	movq	8(%rsp), %rdx
	leaq	16(%rsp), %r8
	movl	$.LC18, %esi
	movl	$1, %edi
	movzwl	(%rax), %ecx
	xorl	%eax, %eax
	call	__printf_chk
	jmp	.L67
.L95:
	call	__stack_chk_fail
	.cfi_endproc
.LFE104:
	.size	EApiValidateStorageApi, .-EApiValidateStorageApi
	.section	.text.unlikely
.LCOLDE23:
	.text
.LHOTE23:
	.section	.rodata.str1.1
.LC24:
	.string	"EApiGPIOGetDirectionCaps"
.LC25:
	.string	"%-15s %-25s : %s\n"
	.section	.rodata.str1.8
	.align 8
.LC26:
	.string	"%-15s %-25s : Inputs   =%08X Outputs=%08X\n"
	.section	.rodata.str1.1
.LC27:
	.string	"EApiGPIOGetDirection"
.LC28:
	.string	"%-15s %-25s : Direction=%08X\n"
.LC29:
	.string	"EApiGPIOGetLevel"
.LC30:
	.string	"%-15s %-25s : Level    =%08X\n"
.LC31:
	.string	"EApiGPIOSetDirection"
.LC32:
	.string	"EApiGPIOSetLevel"
	.section	.text.unlikely
.LCOLDB33:
	.text
.LHOTB33:
	.p2align 4,,15
	.globl	EApiValidateGPIOApi
	.type	EApiValidateGPIOApi, @function
EApiValidateGPIOApi:
.LFB105:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movl	$EApiGpioDevices+8, %ebx
	subq	$1056, %rsp
	.cfi_def_cfa_offset 1088
	movq	%fs:40, %rax
	movq	%rax, 1048(%rsp)
	xorl	%eax, %eax
	jmp	.L105
	.p2align 4,,10
	.p2align 3
.L122:
	leaq	16(%rsp), %rsi
	movl	$1024, %edx
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	movq	(%rbx), %rdx
	leaq	16(%rsp), %r8
	movl	$.LC24, %ecx
	movl	$.LC25, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
.L98:
	addq	$16, %rbx
	cmpq	$EApiGpioDevices+200, %rbx
	je	.L121
.L105:
	movl	-8(%rbx), %ebp
	leaq	12(%rsp), %rdx
	leaq	8(%rsp), %rsi
	movl	%ebp, %edi
	call	EApiGPIOGetDirectionCaps
	testl	%eax, %eax
	jne	.L122
	movq	(%rbx), %r12
	movl	12(%rsp), %r9d
	movl	$.LC24, %ecx
	movl	8(%rsp), %r8d
	movl	$.LC26, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	movq	%r12, %rdx
	call	__printf_chk
	movl	8(%rsp), %esi
	orl	12(%rsp), %esi
	movq	%rsp, %rdx
	movl	%ebp, %edi
	call	EApiGPIOGetDirection
	testl	%eax, %eax
	jne	.L120
	movl	(%rsp), %r8d
	movl	$.LC27, %ecx
	movq	%r12, %rdx
	movl	$.LC28, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	8(%rsp), %esi
	orl	12(%rsp), %esi
	leaq	4(%rsp), %rdx
	movl	%ebp, %edi
	call	EApiGPIOGetLevel
	testl	%eax, %eax
	je	.L100
	leaq	16(%rsp), %rsi
	movl	$1024, %edx
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	leaq	16(%rsp), %r8
	movl	$.LC29, %ecx
.L119:
	xorl	%eax, %eax
	movq	%r12, %rdx
	movl	$.LC25, %esi
	movl	$1, %edi
	addq	$16, %rbx
	call	__printf_chk
	cmpq	$EApiGpioDevices+200, %rbx
	jne	.L105
.L121:
	xorl	%r12d, %r12d
	.p2align 4,,10
	.p2align 3
.L109:
	movl	$EApiGpioterfaceValidate, %ebx
	xorl	%ebp, %ebp
.L108:
	movq	8(%rbx), %rdx
	movq	(%rbx), %rsi
	movl	%r12d, %edi
	call	EApiGPIOGetDirectionCaps
	cmpl	16(%rbx), %eax
	movl	%eax, %r9d
	movl	$1, %edx
	je	.L107
	cmpl	20(%rbx), %eax
	je	.L107
	xorl	%edx, %edx
	cmpl	%eax, 24(%rbx)
	sete	%dl
.L107:
	movq	LogStream(%rip), %rdi
	pushq	FailPass(,%rdx,8)
	.cfi_def_cfa_offset 1096
	xorl	%eax, %eax
	pushq	%rbp
	.cfi_def_cfa_offset 1104
	pushq	%r12
	.cfi_def_cfa_offset 1112
	movl	$938, %r8d
	pushq	$.LC14
	.cfi_def_cfa_offset 1120
	movl	$.LC24, %ecx
	movl	$.LC20, %edx
	movl	$76, %esi
	addl	$1, %ebp
	addq	$32, %rbx
	call	siFFormattedMessage_SC.constprop.0
	addq	$32, %rsp
	.cfi_def_cfa_offset 1088
	cmpl	$4, %ebp
	jne	.L108
	addl	$1, %r12d
	cmpl	$10, %r12d
	jne	.L109
	movq	1048(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L123
	addq	$1056, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L101:
	.cfi_restore_state
	movl	8(%rsp), %esi
	orl	12(%rsp), %esi
	movq	%rsp, %rdx
	movl	%ebp, %edi
	call	EApiGPIOGetDirection
	testl	%eax, %eax
	je	.L124
	.p2align 4,,10
	.p2align 3
.L120:
	leaq	16(%rsp), %rsi
	movl	$1024, %edx
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	leaq	16(%rsp), %r8
	movl	$.LC27, %ecx
	jmp	.L119
	.p2align 4,,10
	.p2align 3
.L100:
	movl	4(%rsp), %r8d
	movl	$.LC29, %ecx
	movq	%r12, %rdx
	movl	$.LC30, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	8(%rsp), %esi
	movl	%ebp, %edi
	movzwl	%si, %edx
	orl	12(%rsp), %esi
	call	EApiGPIOSetDirection
	testl	%eax, %eax
	je	.L101
	leaq	16(%rsp), %rsi
	movl	$1024, %edx
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	leaq	16(%rsp), %r8
	movl	$.LC31, %ecx
	jmp	.L119
.L124:
	movl	(%rsp), %r8d
	movl	$.LC27, %ecx
	movq	%r12, %rdx
	movl	$.LC28, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	12(%rsp), %esi
	movl	%ebp, %edi
	movl	%esi, %edx
	call	EApiGPIOSetLevel
	testl	%eax, %eax
	jne	.L125
	movl	8(%rsp), %esi
	orl	12(%rsp), %esi
	leaq	4(%rsp), %rdx
	movl	%ebp, %edi
	call	EApiGPIOGetLevel
	testl	%eax, %eax
	jne	.L120
	movl	4(%rsp), %r8d
	movl	$.LC32, %ecx
	movq	%r12, %rdx
	movl	$.LC30, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	jmp	.L98
.L125:
	leaq	16(%rsp), %rsi
	movl	$1024, %edx
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	leaq	16(%rsp), %r8
	movl	$.LC32, %ecx
	jmp	.L119
.L123:
	call	__stack_chk_fail
	.cfi_endproc
.LFE105:
	.size	EApiValidateGPIOApi, .-EApiValidateGPIOApi
	.section	.text.unlikely
.LCOLDE33:
	.text
.LHOTE33:
	.section	.text.unlikely
.LCOLDB34:
	.text
.LHOTB34:
	.p2align 4,,15
	.globl	siFFormattedMessage_SC
	.type	siFFormattedMessage_SC, @function
siFFormattedMessage_SC:
.LFB99:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movq	%rcx, %r14
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movl	%r9d, %r12d
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	%rdi, %rbp
	movl	%esi, %ebx
	subq	$240, %rsp
	.cfi_def_cfa_offset 288
	testb	%al, %al
	movq	288(%rsp), %r13
	je	.L127
	movaps	%xmm0, 112(%rsp)
	movaps	%xmm1, 128(%rsp)
	movaps	%xmm2, 144(%rsp)
	movaps	%xmm3, 160(%rsp)
	movaps	%xmm4, 176(%rsp)
	movaps	%xmm5, 192(%rsp)
	movaps	%xmm6, 208(%rsp)
	movaps	%xmm7, 224(%rsp)
.L127:
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	leaq	296(%rsp), %rax
	leaq	24(%rsp), %rdi
	movl	%r12d, %esi
	movq	%rax, 40(%rsp)
	leaq	64(%rsp), %rax
	movl	%r8d, 12(%rsp)
	movl	$48, 32(%rsp)
	movl	$48, 36(%rsp)
	movq	%rax, 48(%rsp)
	call	EApiGetErrorStringA
	movl	12(%rsp), %r8d
	movsbl	%bl, %ecx
	xorl	%eax, %eax
	movq	%r14, %r9
	movl	$.LC11, %edx
	movl	$1, %esi
	movq	%rbp, %rdi
	call	__fprintf_chk
	movq	24(%rsp), %rcx
	movl	%eax, %ebx
	testq	%rcx, %rcx
	je	.L132
	movl	$.LC13, %edx
	movl	$1, %esi
	movq	%rbp, %rdi
	xorl	%eax, %eax
	call	__fprintf_chk
.L129:
	leaq	32(%rsp), %rcx
	movq	%r13, %rdx
	movl	$1, %esi
	movq	%rbp, %rdi
	call	__vfprintf_chk
	addl	%ebx, %eax
	movq	56(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L133
	addq	$240, %rsp
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
.L132:
	.cfi_restore_state
	movl	%r12d, %ecx
	movl	$.LC12, %edx
	movl	$1, %esi
	movq	%rbp, %rdi
	xorl	%eax, %eax
	call	__fprintf_chk
	jmp	.L129
.L133:
	call	__stack_chk_fail
	.cfi_endproc
.LFE99:
	.size	siFFormattedMessage_SC, .-siFFormattedMessage_SC
	.section	.text.unlikely
.LCOLDE34:
	.text
.LHOTE34:
	.section	.text.unlikely
.LCOLDB35:
	.text
.LHOTB35:
	.p2align 4,,15
	.globl	printHex
	.type	printHex, @function
printHex:
.LFB102:
	.cfi_startproc
	testq	%rdx, %rdx
	je	.L142
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdx, %rbx
	.p2align 4,,10
	.p2align 3
.L138:
	movzbl	0(%rbp), %ecx
	xorl	%eax, %eax
	movl	$.LC17, %edx
	movl	$1, %esi
	movq	%r12, %rdi
	addq	$1, %rbp
	call	__fprintf_chk
	subq	$1, %rbx
	jne	.L138
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_restore 12
	.cfi_def_cfa_offset 8
.L142:
	rep ret
	.cfi_endproc
.LFE102:
	.size	printHex, .-printHex
	.section	.text.unlikely
.LCOLDE35:
	.text
.LHOTE35:
	.section	.rodata.str1.1
.LC36:
	.string	"w"
.LC37:
	.string	"EApiValidateAPI.log"
.LC38:
	.string	"Status Code"
.LC39:
	.string	"Function Name"
	.section	.rodata.str1.8
	.align 8
.LC40:
	.string	"L%04u %-30s | %-25s | %5s %5s    [%s]\n"
	.section	.rodata.str1.1
.LC41:
	.string	"Status"
.LC42:
	.string	"Test#"
.LC43:
	.string	"Id"
	.section	.rodata.str1.8
	.align 8
.LC44:
	.string	"EApi(Embedded Application Interface)\nEApi Verification Tool                            Version %u.%u.%u\n"
	.section	.text.unlikely
.LCOLDB45:
	.section	.text.startup,"ax",@progbits
.LHOTB45:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB106:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$.LC36, %esi
	movl	$.LC37, %edi
	call	fopen
	testq	%rax, %rax
	movq	%rax, LogStream(%rip)
	je	.L148
.L144:
	call	EApiLibInitialize
	testl	%eax, %eax
	je	.L145
	movl	$2, %edi
	call	exit
.L145:
	movq	LogStream(%rip), %rdi
	pushq	%rax
	.cfi_def_cfa_offset 24
	movl	$.LC38, %r9d
	pushq	$.LC41
	.cfi_def_cfa_offset 32
	pushq	$.LC42
	.cfi_def_cfa_offset 40
	movl	$.LC39, %r8d
	pushq	$.LC43
	.cfi_def_cfa_offset 48
	movl	$980, %ecx
	movl	$.LC40, %edx
	movl	$1, %esi
	xorl	%eax, %eax
	call	__fprintf_chk
	movq	stderr(%rip), %rdi
	addq	$32, %rsp
	.cfi_def_cfa_offset 16
	xorl	%ecx, %ecx
	movl	$766, %r9d
	movl	$5, %r8d
	movl	$.LC44, %edx
	movl	$1, %esi
	xorl	%eax, %eax
	call	__fprintf_chk
	call	EApiValidateValuesApi
	call	EApiValidateStringApi
	call	EApiValidateI2CApi
	call	EApiLibInitialize
	testl	%eax, %eax
	je	.L146
	movl	$3, %edi
	call	exit
.L146:
	xorl	%edi, %edi
	call	exit
.L148:
	movq	stdout(%rip), %rax
	movq	%rax, LogStream(%rip)
	jmp	.L144
	.cfi_endproc
.LFE106:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE45:
	.section	.text.startup
.LHOTE45:
	.globl	TestFunctions
	.section	.rodata.str1.1
.LC46:
	.string	"Values Function"
.LC47:
	.string	"Strings Function"
.LC48:
	.string	"I2C Function"
.LC49:
	.string	"Storage Function"
.LC50:
	.string	"Gpio Function"
	.section	.rodata
	.align 32
	.type	TestFunctions, @object
	.size	TestFunctions, 80
TestFunctions:
	.quad	EApiValidateValuesApi
	.quad	.LC46
	.quad	EApiValidateStringApi
	.quad	.LC47
	.quad	EApiValidateI2CApi
	.quad	.LC48
	.quad	EApiValidateStorageApi
	.quad	.LC49
	.quad	EApiValidateGPIOApi
	.quad	.LC50
	.globl	EApiGpioDevices
	.section	.rodata.str1.1
.LC51:
	.string	"GPIO Bank0"
.LC52:
	.string	"GPIO GPIO0"
.LC53:
	.string	"GPIO GPIO1"
.LC54:
	.string	"GPIO GPIO2"
.LC55:
	.string	"GPIO GPIO3"
.LC56:
	.string	"GPIO GPIO4"
.LC57:
	.string	"GPIO GPIO5"
.LC58:
	.string	"GPIO GPIO6"
.LC59:
	.string	"GPIO GPIO7"
.LC60:
	.string	"GPIO GPIO8"
.LC61:
	.string	"GPIO GPIO9"
.LC62:
	.string	"Unsupported"
	.section	.rodata
	.align 32
	.type	EApiGpioDevices, @object
	.size	EApiGpioDevices, 192
EApiGpioDevices:
	.long	65536
	.zero	4
	.quad	.LC51
	.long	0
	.zero	4
	.quad	.LC52
	.long	1
	.zero	4
	.quad	.LC53
	.long	2
	.zero	4
	.quad	.LC54
	.long	3
	.zero	4
	.quad	.LC55
	.long	4
	.zero	4
	.quad	.LC56
	.long	5
	.zero	4
	.quad	.LC57
	.long	6
	.zero	4
	.quad	.LC58
	.long	7
	.zero	4
	.quad	.LC59
	.long	8
	.zero	4
	.quad	.LC60
	.long	9
	.zero	4
	.quad	.LC61
	.long	3840
	.zero	4
	.quad	.LC62
	.globl	EApiGpioterfaceValidate
	.align 32
	.type	EApiGpioterfaceValidate, @object
	.size	EApiGpioterfaceValidate, 128
EApiGpioterfaceValidate:
	.quad	GpioInputs
	.quad	GpioOutputs
	.long	0
	.long	-769
	.long	-769
	.zero	4
	.quad	GpioInputs
	.quad	0
	.long	0
	.long	-769
	.long	-769
	.zero	4
	.quad	0
	.quad	GpioOutputs
	.long	0
	.long	-769
	.long	-769
	.zero	4
	.quad	0
	.quad	0
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.comm	GpioOutputs,4,4
	.comm	GpioInputs,4,4
	.globl	StorageCapValidate
	.align 32
	.type	StorageCapValidate, @object
	.size	StorageCapValidate, 128
StorageCapValidate:
	.quad	StorageSize
	.quad	BlockLength
	.long	0
	.long	-769
	.long	-769
	.zero	4
	.quad	StorageSize
	.quad	0
	.long	0
	.long	-769
	.long	-769
	.zero	4
	.quad	0
	.quad	BlockLength
	.long	0
	.long	-769
	.long	-769
	.zero	4
	.quad	0
	.quad	0
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.comm	BlockLength,4,4
	.comm	StorageSize,4,4
	.globl	StorageValidate
	.align 32
	.type	StorageValidate, @object
	.size	StorageValidate, 240
StorageValidate:
	.long	0
	.zero	4
	.quad	Buffer
	.long	1024
	.long	10
	.long	0
	.long	-769
	.long	-769
	.zero	4
	.long	0
	.zero	4
	.quad	0
	.long	1024
	.long	100
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.long	33
	.zero	4
	.quad	Buffer
	.long	0
	.long	20
	.long	-257
	.long	-259
	.long	-769
	.zero	4
	.long	33
	.zero	4
	.quad	Buffer
	.long	16
	.long	20
	.long	-259
	.long	0
	.long	-769
	.zero	4
	.long	33
	.zero	4
	.quad	Buffer
	.long	1024
	.long	0
	.long	-257
	.long	-257
	.long	-769
	.zero	4
	.long	1
	.zero	4
	.quad	Buffer
	.long	1024
	.long	10
	.long	0
	.long	-769
	.long	-769
	.zero	4
	.globl	EApiStorageDevices
	.section	.rodata.str1.1
.LC63:
	.string	"Standard Storage"
.LC64:
	.string	"Dummy PICMG Storage"
	.section	.rodata
	.align 32
	.type	EApiStorageDevices, @object
	.size	EApiStorageDevices, 72
EApiStorageDevices:
	.long	0
	.zero	4
	.quad	.LC63
	.long	32
	.zero	4
	.long	-93057024
	.zero	4
	.quad	.LC64
	.long	128
	.zero	4
	.long	3840
	.zero	4
	.quad	.LC62
	.long	32
	.zero	4
	.globl	EApiI2CBuses
	.section	.rodata.str1.1
.LC65:
	.string	"External I2C"
.LC66:
	.string	"LVDS 1 I2C/DDC"
.LC67:
	.string	"LVDS 2 I2C/DDC"
	.section	.rodata
	.align 32
	.type	EApiI2CBuses, @object
	.size	EApiI2CBuses, 64
EApiI2CBuses:
	.long	0
	.zero	4
	.quad	.LC65
	.long	1
	.zero	4
	.quad	.LC66
	.long	2
	.zero	4
	.quad	.LC67
	.long	3840
	.zero	4
	.quad	.LC62
	.globl	I2CDevices
	.align 32
	.type	I2CDevices, @object
	.size	I2CDevices, 60
I2CDevices:
	.value	160
	.value	16
	.value	2
	.value	5
	.long	256
	.value	162
	.value	256
	.value	2
	.value	5
	.long	256
	.value	166
	.value	16
	.value	1
	.value	5
	.long	256
	.value	174
	.value	16
	.value	2
	.value	5
	.long	256
	.value	-3499
	.value	256
	.value	2
	.value	5
	.long	256
	.globl	EApiI2CInterfaceValidate
	.align 32
	.type	EApiI2CInterfaceValidate, @object
	.size	EApiI2CInterfaceValidate, 48
EApiI2CInterfaceValidate:
	.quad	I2CMaxClk
	.long	0
	.long	-769
	.long	-769
	.zero	4
	.quad	0
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.globl	I2CMaxClk
	.bss
	.align 4
	.type	I2CMaxClk, @object
	.size	I2CMaxClk, 4
I2CMaxClk:
	.zero	4
	.globl	EApiI2CHLWriteValidate
	.section	.rodata
	.align 32
	.type	EApiI2CHLWriteValidate, @object
	.size	EApiI2CHLWriteValidate, 120
EApiI2CHLWriteValidate:
	.long	248
	.long	0
	.quad	Buffer
	.long	0
	.long	10
	.long	-1025
	.long	-769
	.long	-1025
	.zero	4
	.long	248
	.long	0
	.quad	0
	.long	0
	.long	10
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.long	248
	.long	0
	.quad	Buffer
	.long	0
	.long	0
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.globl	EApiI2CHLReadValidate
	.align 32
	.type	EApiI2CHLReadValidate, @object
	.size	EApiI2CHLReadValidate, 240
EApiI2CHLReadValidate:
	.long	248
	.long	0
	.quad	Buffer
	.long	1024
	.long	10
	.long	-1025
	.long	-769
	.long	-1025
	.zero	4
	.long	248
	.long	0
	.quad	0
	.long	1024
	.long	10
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.long	248
	.long	0
	.quad	Buffer
	.long	0
	.long	20
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.long	248
	.long	0
	.quad	Buffer
	.long	1024
	.long	0
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.long	248
	.long	0
	.quad	Buffer
	.long	16
	.long	20
	.long	-769
	.long	-1537
	.long	-1025
	.zero	4
	.long	248
	.long	0
	.quad	Buffer
	.long	1024
	.long	10
	.long	-1025
	.long	-769
	.long	-1025
	.zero	4
	.globl	EApiI2CLLValidate
	.align 32
	.type	EApiI2CLLValidate, @object
	.size	EApiI2CLLValidate, 560
EApiI2CLLValidate:
	.byte	-8
	.zero	7
	.quad	0
	.long	0
	.zero	4
	.quad	0
	.long	0
	.long	0
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.byte	-8
	.zero	7
	.quad	0
	.long	10
	.zero	4
	.quad	0
	.long	0
	.long	0
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.byte	-8
	.zero	7
	.quad	0
	.long	0
	.zero	4
	.quad	0
	.long	10
	.long	0
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.byte	-8
	.zero	7
	.quad	0
	.long	0
	.zero	4
	.quad	0
	.long	0
	.long	10
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.byte	-8
	.zero	7
	.quad	0
	.long	0
	.zero	4
	.quad	0
	.long	0
	.long	10
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.byte	-8
	.zero	7
	.quad	0
	.long	0
	.zero	4
	.quad	0
	.long	10
	.long	20
	.long	-257
	.long	-1537
	.long	-1537
	.zero	4
	.byte	-8
	.zero	7
	.quad	0
	.long	0
	.zero	4
	.quad	Buffer
	.long	10
	.long	20
	.long	-1025
	.long	-1537
	.long	-769
	.zero	4
	.byte	-8
	.zero	7
	.quad	Buffer
	.long	0
	.zero	4
	.quad	0
	.long	0
	.long	0
	.long	-257
	.long	-257
	.long	-257
	.zero	4
	.byte	-8
	.zero	7
	.quad	Buffer
	.long	10
	.zero	4
	.quad	0
	.long	0
	.long	0
	.long	-1025
	.long	-769
	.long	-769
	.zero	4
	.byte	-8
	.zero	7
	.quad	0
	.long	0
	.zero	4
	.quad	Buffer
	.long	1024
	.long	10
	.long	-1025
	.long	-769
	.long	-769
	.zero	4
	.globl	EApiValues
	.section	.rodata.str1.1
.LC68:
	.string	"EApi Spec Version"
.LC69:
	.string	"Boot Counter"
.LC70:
	.string	"Running Time Meter"
.LC71:
	.string	"Manufacturer PNP ID"
.LC72:
	.string	"Platform Revision"
.LC73:
	.string	"CPU Temperature"
.LC74:
	.string	"Chipset Temperature"
.LC75:
	.string	"System Temperature"
.LC76:
	.string	"Cpu Fan"
.LC77:
	.string	"System Fan"
.LC78:
	.string	"VCORE"
.LC79:
	.string	"2.5V"
.LC80:
	.string	"3.3V"
.LC81:
	.string	"VBAT"
.LC82:
	.string	"5V"
.LC83:
	.string	"5VSB"
.LC84:
	.string	"12V"
	.section	.rodata
	.align 32
	.type	EApiValues, @object
	.size	EApiValues, 408
EApiValues:
	.long	0
	.zero	4
	.quad	.LC68
	.quad	EApiAHCreateSVersionString
	.long	1
	.zero	4
	.quad	.LC69
	.quad	EApiAHCreateDecimalString
	.long	2
	.zero	4
	.quad	.LC70
	.quad	EApiAHCreateTimeString
	.long	3
	.zero	4
	.quad	.LC71
	.quad	EApiAHCreatePNPIDString
	.long	4
	.zero	4
	.quad	.LC72
	.quad	EApiAHCreateSVersionString
	.long	131072
	.zero	4
	.quad	.LC73
	.quad	EApiAHCreateTempString
	.long	131073
	.zero	4
	.quad	.LC74
	.quad	EApiAHCreateTempString
	.long	131074
	.zero	4
	.quad	.LC75
	.quad	EApiAHCreateTempString
	.long	139264
	.zero	4
	.quad	.LC76
	.quad	EApiAHCreateRotationsString
	.long	139265
	.zero	4
	.quad	.LC77
	.quad	EApiAHCreateRotationsString
	.long	135172
	.zero	4
	.quad	.LC78
	.quad	EApiAHCreateVoltageString
	.long	135176
	.zero	4
	.quad	.LC79
	.quad	EApiAHCreateVoltageString
	.long	135180
	.zero	4
	.quad	.LC80
	.quad	EApiAHCreateVoltageString
	.long	135184
	.zero	4
	.quad	.LC81
	.quad	EApiAHCreateVoltageString
	.long	135188
	.zero	4
	.quad	.LC82
	.quad	EApiAHCreateVoltageString
	.long	135192
	.zero	4
	.quad	.LC83
	.quad	EApiAHCreateVoltageString
	.long	135196
	.zero	4
	.quad	.LC84
	.quad	EApiAHCreateVoltageString
	.globl	EApiStrings
	.section	.rodata.str1.1
.LC85:
	.string	"Manufacturer"
.LC86:
	.string	"Board Name"
.LC87:
	.string	"Board Serial Number"
.LC88:
	.string	"Bios Revision"
.LC89:
	.string	"Platform Type"
.LC90:
	.string	"HW Revision"
.LC91:
	.string	"Board Revision"
.LC92:
	.string	"Manufacturing Date"
	.section	.rodata
	.align 32
	.type	EApiStrings, @object
	.size	EApiStrings, 128
EApiStrings:
	.long	0
	.zero	4
	.quad	.LC85
	.long	1
	.zero	4
	.quad	.LC86
	.long	3
	.zero	4
	.quad	.LC87
	.long	4
	.zero	4
	.quad	.LC88
	.long	6
	.zero	4
	.quad	.LC89
	.long	5
	.zero	4
	.quad	.LC90
	.long	2
	.zero	4
	.quad	.LC91
	.long	-84865024
	.zero	4
	.quad	.LC92
	.globl	FailPass
	.section	.rodata.str1.1
.LC93:
	.string	"FAIL"
.LC94:
	.string	"PASS"
	.data
	.align 16
	.type	FailPass, @object
	.size	FailPass, 16
FailPass:
	.quad	.LC93
	.quad	.LC94
	.globl	BufPtrLen
	.align 4
	.type	BufPtrLen, @object
	.size	BufPtrLen, 4
BufPtrLen:
	.long	1024
	.globl	Buffer
	.bss
	.align 32
	.type	Buffer, @object
	.size	Buffer, 1024
Buffer:
	.zero	1024
	.comm	LogStream,8,8
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC8:
	.byte	0
	.byte	51
	.byte	80
	.byte	16
	.byte	9
	.byte	116
	.byte	99
	.byte	111
	.byte	77
	.byte	48
	.byte	17
	.byte	-81
	.byte	0
	.byte	0
	.byte	0
	.byte	1
	.align 16
.LC9:
	.byte	6
	.byte	33
	.byte	-48
	.byte	0
	.byte	32
	.byte	2
	.byte	15
	.byte	-32
	.byte	0
	.byte	1
	.byte	2
	.byte	3
	.byte	4
	.byte	0
	.byte	8
	.byte	0
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
