	.file	"EApiAHStr.c"
	.text
.Ltext0:
	.globl	ErrorLookup
	.section	.rodata
.LC0:
	.string	"EAPI_STATUS_NOT_INITIALIZED"
.LC1:
	.string	"EAPI_STATUS_INITIALIZED"
.LC2:
	.string	"EAPI_STATUS_ALLOC_ERROR"
.LC3:
	.string	"EAPI_STATUS_DRIVER_TIMEOUT"
.LC4:
	.string	"EAPI_STATUS_INVALID_PARAMETER"
	.align 8
.LC5:
	.string	"EAPI_STATUS_INVALID_BLOCK_ALIGNMENT"
	.align 8
.LC6:
	.string	"EAPI_STATUS_INVALID_BLOCK_LENGTH"
.LC7:
	.string	"EAPI_STATUS_INVALID_DIRECTION"
.LC8:
	.string	"EAPI_STATUS_INVALID_BITMASK"
.LC9:
	.string	"EAPI_STATUS_RUNNING"
.LC10:
	.string	"EAPI_STATUS_UNSUPPORTED"
.LC11:
	.string	"EAPI_STATUS_NOT_FOUND"
.LC12:
	.string	"EAPI_STATUS_TIMEOUT"
.LC13:
	.string	"EAPI_STATUS_BUSY_COLLISION"
.LC14:
	.string	"EAPI_STATUS_READ_ERROR"
.LC15:
	.string	"EAPI_STATUS_WRITE_ERROR"
.LC16:
	.string	"EAPI_STATUS_MORE_DATA"
.LC17:
	.string	"EAPI_STATUS_ERROR"
.LC18:
	.string	"EAPI_STATUS_SUCCESS"
	.align 32
	.type	ErrorLookup, @object
	.size	ErrorLookup, 304
ErrorLookup:
	.long	-1
	.zero	4
	.quad	.LC0
	.long	-2
	.zero	4
	.quad	.LC1
	.long	-3
	.zero	4
	.quad	.LC2
	.long	-4
	.zero	4
	.quad	.LC3
	.long	-257
	.zero	4
	.quad	.LC4
	.long	-258
	.zero	4
	.quad	.LC5
	.long	-259
	.zero	4
	.quad	.LC6
	.long	-260
	.zero	4
	.quad	.LC7
	.long	-261
	.zero	4
	.quad	.LC8
	.long	-262
	.zero	4
	.quad	.LC9
	.long	-769
	.zero	4
	.quad	.LC10
	.long	-1025
	.zero	4
	.quad	.LC11
	.long	-1026
	.zero	4
	.quad	.LC12
	.long	-1027
	.zero	4
	.quad	.LC13
	.long	-1281
	.zero	4
	.quad	.LC14
	.long	-1282
	.zero	4
	.quad	.LC15
	.long	-1537
	.zero	4
	.quad	.LC16
	.long	-3841
	.zero	4
	.quad	.LC17
	.long	0
	.zero	4
	.quad	.LC18
.LC19:
	.string	"%s\n"
.LC20:
	.string	"EApiAHCreateErrorString"
	.align 8
.LC21:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHStr.c"
.LC22:
	.string	"(pString==NULL)"
.LC23:
	.string	"(StrBufLen==0)"
.LC24:
	.string	"UNKNOWN ERROR(0x%08X)"
	.text
	.globl	EApiAHCreateErrorString
	.type	EApiAHCreateErrorString, @function
EApiAHCreateErrorString:
.LFB2:
	.file 1 "/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHStr.c"
	.loc 1 71 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	.loc 1 72 0
	movq	$-1, -8(%rbp)
	.loc 1 75 0
	cmpq	$0, -32(%rbp)
	jne	.L2
	.loc 1 75 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$79, %ecx
	movl	$.LC20, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movq	$-1, -8(%rbp)
	jmp	.L10
.L2:
	.loc 1 80 0 is_stmt 1
	cmpq	$0, -40(%rbp)
	jne	.L4
	.loc 1 80 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC23
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$84, %ecx
	movl	$.LC20, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movq	$-1, -8(%rbp)
	jmp	.L10
.L4:
	.loc 1 86 0 is_stmt 1
	movl	$0, -12(%rbp)
	jmp	.L5
.L8:
	.loc 1 88 0
	movl	-12(%rbp), %eax
	salq	$4, %rax
	addq	$ErrorLookup, %rax
	movl	(%rax), %eax
	cmpl	-20(%rbp), %eax
	jne	.L6
	.loc 1 90 0
	cmpq	$0, -32(%rbp)
	je	.L7
	.loc 1 91 0
	movl	-12(%rbp), %eax
	salq	$4, %rax
	addq	$ErrorLookup+8, %rax
	movq	(%rax), %rdx
	movq	-40(%rbp), %rcx
	movq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	EApiStrCpy
	.loc 1 92 0
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movq	%rax, -8(%rbp)
	.loc 1 93 0
	jmp	.L10
.L7:
	.loc 1 95 0
	movq	$-1, -8(%rbp)
	.loc 1 96 0
	jmp	.L10
.L6:
	.loc 1 86 0 discriminator 2
	addl	$1, -12(%rbp)
.L5:
	.loc 1 86 0 is_stmt 0 discriminator 1
	cmpl	$18, -12(%rbp)
	jbe	.L8
	.loc 1 99 0 is_stmt 1
	cmpq	$0, -32(%rbp)
	je	.L9
	.loc 1 100 0
	movl	-20(%rbp), %edx
	movq	-40(%rbp), %rsi
	movq	-32(%rbp), %rax
	movl	%edx, %ecx
	movl	$.LC24, %edx
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
	.loc 1 104 0
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movq	%rax, -8(%rbp)
	.loc 1 105 0
	jmp	.L10
.L9:
	.loc 1 107 0
	movq	$-1, -8(%rbp)
.L3:
.L10:
	.loc 1 110 0
	movq	-8(%rbp), %rax
	.loc 1 111 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	EApiAHCreateErrorString, .-EApiAHCreateErrorString
	.section	.rodata
.LC25:
	.string	"EApiAHCreateErrorStringAlloc"
	.text
	.globl	EApiAHCreateErrorStringAlloc
	.type	EApiAHCreateErrorStringAlloc, @function
EApiAHCreateErrorStringAlloc:
.LFB3:
	.loc 1 117 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	.loc 1 118 0
	movl	$0, -16(%rbp)
	.loc 1 122 0
	cmpq	$0, -32(%rbp)
	jne	.L13
	.loc 1 122 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-257, %r8d
	movl	$122, %ecx
	movl	$.LC25, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -16(%rbp)
	jmp	.L19
.L13:
	.loc 1 124 0 is_stmt 1
	movl	$0, -12(%rbp)
	jmp	.L15
.L18:
	.loc 1 126 0
	movl	-12(%rbp), %eax
	salq	$4, %rax
	addq	$ErrorLookup, %rax
	movl	(%rax), %eax
	cmpl	-20(%rbp), %eax
	jne	.L16
	.loc 1 127 0
	movl	-12(%rbp), %eax
	salq	$4, %rax
	addq	$ErrorLookup+8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	strlen
	addq	$1, %rax
	movq	%rax, -8(%rbp)
	.loc 1 128 0
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, (%rax)
	.loc 1 129 0
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L17
	.loc 1 130 0
	movl	-12(%rbp), %eax
	salq	$4, %rax
	addq	$ErrorLookup+8, %rax
	movq	(%rax), %rdx
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	EApiStrCpy
.L17:
	.loc 1 131 0
	movl	$0, -16(%rbp)
	.loc 1 132 0
	jmp	.L19
.L16:
	.loc 1 124 0 discriminator 2
	addl	$1, -12(%rbp)
.L15:
	.loc 1 124 0 is_stmt 0 discriminator 1
	cmpl	$18, -12(%rbp)
	jbe	.L18
	.loc 1 135 0 is_stmt 1
	movl	$26, %edi
	call	malloc
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, (%rax)
	.loc 1 136 0
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L19
	.loc 1 137 0
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	-20(%rbp), %edx
	movl	%edx, %ecx
	movl	$.LC24, %edx
	movl	$26, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
.L14:
.L19:
	.loc 1 144 0
	movl	-16(%rbp), %eax
	.loc 1 145 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	EApiAHCreateErrorStringAlloc, .-EApiAHCreateErrorStringAlloc
	.section	.rodata
.LC26:
	.string	"EApiAHGetString"
.LC27:
	.string	"EApiAHGetStringAlloc"
	.align 8
.LC28:
	.string	"Interface Returning Different String Lengths"
	.align 8
.LC29:
	.string	"Returned String Missing Terminating \\0 Character."
	.text
	.globl	EApiAHGetString
	.type	EApiAHGetString, @function
EApiAHGetString:
.LFB4:
	.loc 1 153 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	.loc 1 153 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 154 0
	movq	$-1, -24(%rbp)
	.loc 1 155 0
	movq	-56(%rbp), %rax
	movl	%eax, -28(%rbp)
	.loc 1 156 0
	movq	-56(%rbp), %rax
	movq	%rax, -16(%rbp)
	.loc 1 157 0
	cmpq	$0, -48(%rbp)
	jne	.L22
	.loc 1 157 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$157, %ecx
	movl	$.LC26, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movq	$-1, -24(%rbp)
	jmp	.L23
.L22:
	.loc 1 158 0 is_stmt 1
	cmpq	$0, -56(%rbp)
	jne	.L24
	.loc 1 158 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC23
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$158, %ecx
	movl	$.LC26, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movq	$-1, -24(%rbp)
	jmp	.L23
.L24:
	.loc 1 160 0 is_stmt 1
	leaq	-28(%rbp), %rdx
	movq	-48(%rbp), %rcx
	movl	-36(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiBoardGetStringA
	movl	%eax, %eax
	movq	%rax, -24(%rbp)
	.loc 1 161 0
	cmpq	$0, -24(%rbp)
	je	.L25
	.loc 1 162 0
	movq	-24(%rbp), %rax
	movl	%eax, %ecx
	movq	-16(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	%ecx, %edi
	call	EApiAHCreateErrorString
	movl	%eax, -28(%rbp)
.L25:
	.loc 1 164 0
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	cmpq	-16(%rbp), %rax
	jbe	.L26
	.loc 1 164 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC28
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$169, %ecx
	movl	$.LC27, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movq	$-1, -24(%rbp)
	jmp	.L23
.L26:
	.loc 1 170 0 is_stmt 1
	movq	-16(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	EApiStrLen
	cmpq	-16(%rbp), %rax
	jne	.L27
	.loc 1 172 0
	subq	$8, %rsp
	pushq	$.LC29
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$176, %ecx
	movl	$.LC26, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	.loc 1 177 0
	movq	-16(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
.L27:
	.loc 1 180 0
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	movq	%rax, -24(%rbp)
.L23:
	.loc 1 183 0
	movq	-24(%rbp), %rax
	.loc 1 184 0
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L29
	call	__stack_chk_fail
.L29:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	EApiAHGetString, .-EApiAHGetString
	.section	.rodata
.LC30:
	.string	"Memory Allocation Error"
	.text
	.globl	EApiAHGetStringAlloc
	.type	EApiAHGetStringAlloc, @function
EApiAHGetStringAlloc:
.LFB5:
	.loc 1 193 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	.loc 1 193 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 194 0
	movl	$0, -16(%rbp)
	.loc 1 195 0
	movl	$0, -20(%rbp)
	.loc 1 196 0
	movl	$0, -12(%rbp)
	.loc 1 197 0
	cmpq	$0, -48(%rbp)
	jne	.L31
	.loc 1 197 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-257, %r8d
	movl	$197, %ecx
	movl	$.LC26, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -16(%rbp)
	jmp	.L32
.L31:
	.loc 1 198 0 is_stmt 1
	movq	-48(%rbp), %rax
	movq	$0, (%rax)
	.loc 1 199 0
	movq	-48(%rbp), %rax
	movq	(%rax), %rcx
	leaq	-20(%rbp), %rdx
	movl	-36(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiBoardGetStringA
	movl	%eax, -16(%rbp)
	.loc 1 200 0
	movl	-16(%rbp), %eax
	cmpl	$-1537, %eax
	jne	.L40
	.loc 1 202 0
	movl	-20(%rbp), %eax
	movl	%eax, -12(%rbp)
	.loc 1 203 0
	movl	-20(%rbp), %eax
	movl	%eax, %eax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, (%rax)
	.loc 1 205 0
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L35
	.loc 1 205 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC30
	movl	$.LC19, %r9d
	movl	$-3, %r8d
	movl	$210, %ecx
	movl	$.LC27, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-3, -16(%rbp)
	jmp	.L32
.L35:
	.loc 1 212 0 is_stmt 1
	movq	-48(%rbp), %rax
	movq	(%rax), %rcx
	leaq	-20(%rbp), %rdx
	movl	-36(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiBoardGetStringA
	movl	%eax, -16(%rbp)
	.loc 1 214 0
	movl	-20(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jbe	.L36
	.loc 1 214 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC28
	movl	$.LC19, %r9d
	movl	$-3841, %r8d
	movl	$219, %ecx
	movl	$.LC27, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-3841, -16(%rbp)
	jmp	.L32
.L36:
	.loc 1 220 0 is_stmt 1
	movl	-12(%rbp), %edx
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	EApiStrLen
	movq	%rax, %rdx
	movl	-12(%rbp), %eax
	cmpq	%rax, %rdx
	jne	.L41
	.loc 1 222 0
	subq	$8, %rsp
	pushq	$.LC29
	movl	$.LC19, %r9d
	movl	$-3841, %r8d
	movl	$226, %ecx
	movl	$.LC27, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	.loc 1 227 0
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	movl	-12(%rbp), %edx
	subl	$1, %edx
	movl	%edx, %edx
	addq	%rdx, %rax
	movb	$0, (%rax)
	.loc 1 230 0
	jmp	.L41
.L40:
	.loc 1 232 0
	movq	-48(%rbp), %rdx
	movl	-16(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorStringAlloc
	.loc 1 233 0
	jmp	.L32
.L41:
	.loc 1 230 0
	nop
.L32:
	.loc 1 237 0
	movl	-16(%rbp), %eax
	.loc 1 238 0
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L39
	call	__stack_chk_fail
.L39:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	EApiAHGetStringAlloc, .-EApiAHGetStringAlloc
	.section	.rodata
.LC31:
	.string	"EApiAHCreateDecimalString"
.LC32:
	.string	"%u"
	.text
	.globl	EApiAHCreateDecimalString
	.type	EApiAHCreateDecimalString, @function
EApiAHCreateDecimalString:
.LFB6:
	.loc 1 245 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	.loc 1 246 0
	movl	$0, -4(%rbp)
	.loc 1 247 0
	cmpq	$0, -32(%rbp)
	jne	.L43
	.loc 1 247 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$247, %ecx
	movl	$.LC31, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L44
.L43:
	.loc 1 248 0 is_stmt 1
	cmpl	$0, -24(%rbp)
	jne	.L45
	.loc 1 248 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC23
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$248, %ecx
	movl	$.LC31, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L44
.L45:
	.loc 1 249 0 is_stmt 1
	movl	-24(%rbp), %esi
	movl	-20(%rbp), %edx
	movq	-32(%rbp), %rax
	movl	%edx, %ecx
	movl	$.LC32, %edx
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
	movl	%eax, -4(%rbp)
.L44:
	.loc 1 252 0
	movl	-4(%rbp), %eax
	.loc 1 253 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	EApiAHCreateDecimalString, .-EApiAHCreateDecimalString
	.section	.rodata
.LC33:
	.string	"0x%08X"
	.text
	.globl	EApiAHCreateHexString
	.type	EApiAHCreateHexString, @function
EApiAHCreateHexString:
.LFB7:
	.loc 1 260 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	.loc 1 261 0
	movl	$0, -4(%rbp)
	.loc 1 262 0
	cmpq	$0, -32(%rbp)
	jne	.L48
	.loc 1 262 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$262, %ecx
	movl	$.LC31, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L49
.L48:
	.loc 1 263 0 is_stmt 1
	cmpl	$0, -24(%rbp)
	jne	.L50
	.loc 1 263 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC23
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$263, %ecx
	movl	$.LC31, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L49
.L50:
	.loc 1 264 0 is_stmt 1
	movl	-24(%rbp), %esi
	movl	-20(%rbp), %edx
	movq	-32(%rbp), %rax
	movl	%edx, %ecx
	movl	$.LC33, %edx
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
	movl	%eax, -4(%rbp)
.L49:
	.loc 1 267 0
	movl	-4(%rbp), %eax
	.loc 1 268 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	EApiAHCreateHexString, .-EApiAHCreateHexString
	.section	.rodata
.LC34:
	.string	"%u.%02u Volts"
	.text
	.globl	EApiAHCreateVoltageString
	.type	EApiAHCreateVoltageString, @function
EApiAHCreateVoltageString:
.LFB8:
	.loc 1 275 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	.loc 1 276 0
	movl	$0, -4(%rbp)
	.loc 1 277 0
	cmpq	$0, -32(%rbp)
	jne	.L53
	.loc 1 277 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$277, %ecx
	movl	$.LC31, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L54
.L53:
	.loc 1 278 0 is_stmt 1
	cmpl	$0, -24(%rbp)
	jne	.L55
	.loc 1 278 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC23
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$278, %ecx
	movl	$.LC31, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L54
.L55:
	.loc 1 279 0 is_stmt 1
	movl	-20(%rbp), %eax
	movl	$-858993459, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$3, %eax
	movl	%eax, -20(%rbp)
	.loc 1 280 0
	movl	-20(%rbp), %esi
	movl	$1374389535, %edx
	movl	%esi, %eax
	mull	%edx
	movl	%edx, %ecx
	shrl	$5, %ecx
	imull	$100, %ecx, %eax
	subl	%eax, %esi
	movl	%esi, %ecx
	movl	-20(%rbp), %eax
	movl	$1374389535, %edx
	mull	%edx
	shrl	$5, %edx
	movl	-24(%rbp), %esi
	movq	-32(%rbp), %rax
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	$.LC34, %edx
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
	movl	%eax, -4(%rbp)
.L54:
	.loc 1 284 0
	movl	-4(%rbp), %eax
	.loc 1 285 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	EApiAHCreateVoltageString, .-EApiAHCreateVoltageString
	.section	.rodata
.LC35:
	.string	"%u RPM"
	.text
	.globl	EApiAHCreateRotationsString
	.type	EApiAHCreateRotationsString, @function
EApiAHCreateRotationsString:
.LFB9:
	.loc 1 292 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	.loc 1 294 0
	cmpq	$0, -32(%rbp)
	jne	.L58
	.loc 1 294 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$294, %ecx
	movl	$.LC31, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L59
.L58:
	.loc 1 295 0 is_stmt 1
	cmpl	$0, -24(%rbp)
	jne	.L60
	.loc 1 295 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC23
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$295, %ecx
	movl	$.LC31, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L59
.L60:
	.loc 1 296 0 is_stmt 1
	movl	-24(%rbp), %esi
	movl	-20(%rbp), %edx
	movq	-32(%rbp), %rax
	movl	%edx, %ecx
	movl	$.LC35, %edx
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
	movl	%eax, -4(%rbp)
.L59:
	.loc 1 300 0
	movl	-4(%rbp), %eax
	.loc 1 301 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	EApiAHCreateRotationsString, .-EApiAHCreateRotationsString
	.section	.rodata
.LC36:
	.string	"% i.%i Celcius"
	.text
	.globl	EApiAHCreateTempString
	.type	EApiAHCreateTempString, @function
EApiAHCreateTempString:
.LFB10:
	.loc 1 308 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	.loc 1 310 0
	cmpq	$0, -32(%rbp)
	jne	.L63
	.loc 1 310 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$310, %ecx
	movl	$.LC31, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L64
.L63:
	.loc 1 311 0 is_stmt 1
	cmpl	$0, -24(%rbp)
	jne	.L65
	.loc 1 311 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC23
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$311, %ecx
	movl	$.LC31, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L64
.L65:
	.loc 1 312 0 is_stmt 1
	subl	$2731, -20(%rbp)
	.loc 1 313 0
	movl	-20(%rbp), %esi
	movl	$-858993459, %edx
	movl	%esi, %eax
	mull	%edx
	movl	%edx, %ecx
	shrl	$3, %ecx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	addl	%eax, %eax
	movl	%esi, %ecx
	subl	%eax, %ecx
	movl	-20(%rbp), %esi
	movl	$1717986919, %edx
	movl	%esi, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%esi, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	-24(%rbp), %esi
	movq	-32(%rbp), %rax
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	$.LC36, %edx
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
	movl	%eax, -4(%rbp)
.L64:
	.loc 1 317 0
	movl	-4(%rbp), %eax
	.loc 1 318 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	EApiAHCreateTempString, .-EApiAHCreateTempString
	.section	.rodata
.LC37:
	.string	"EApiAHCreateTimeString"
.LC38:
	.string	"%u Years "
.LC39:
	.string	"%u Days "
.LC40:
	.string	"%u Hours "
.LC41:
	.string	"%u Mins"
	.text
	.globl	EApiAHCreateTimeString
	.type	EApiAHCreateTimeString, @function
EApiAHCreateTimeString:
.LFB11:
	.loc 1 325 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	.loc 1 327 0
	movl	$0, -4(%rbp)
	.loc 1 328 0
	cmpq	$0, -32(%rbp)
	jne	.L68
	.loc 1 328 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$328, %ecx
	movl	$.LC37, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -8(%rbp)
	jmp	.L69
.L68:
	.loc 1 329 0 is_stmt 1
	cmpl	$0, -24(%rbp)
	jne	.L70
	.loc 1 329 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC23
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$329, %ecx
	movl	$.LC37, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -8(%rbp)
	jmp	.L69
.L70:
	.loc 1 330 0 is_stmt 1
	cmpl	$525599, -20(%rbp)
	jbe	.L71
	.loc 1 331 0
	movl	-20(%rbp), %eax
	movl	$-10721075, %edx
	mull	%edx
	shrl	$19, %edx
	movl	-4(%rbp), %eax
	movl	-24(%rbp), %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, %esi
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movq	-32(%rbp), %rax
	addq	%rcx, %rax
	movl	%edx, %ecx
	movl	$.LC38, %edx
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
	addl	%eax, -4(%rbp)
.L71:
	.loc 1 332 0
	cmpl	$0, -4(%rbp)
	jne	.L72
	.loc 1 332 0 is_stmt 0 discriminator 1
	movl	-20(%rbp), %eax
	shrl	$5, %eax
	movl	$95443718, %edx
	mull	%edx
	movl	%edx, %ecx
	movl	$1729753953, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%ecx, %eax
	subl	%edx, %eax
	shrl	%eax
	addl	%edx, %eax
	shrl	$8, %eax
	imull	$365, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	testl	%eax, %eax
	je	.L73
.L72:
	.loc 1 333 0 is_stmt 1
	movl	-20(%rbp), %eax
	shrl	$5, %eax
	movl	$95443718, %edx
	mull	%edx
	movl	%edx, %ecx
	movl	$1729753953, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%ecx, %eax
	subl	%edx, %eax
	shrl	%eax
	addl	%edx, %eax
	shrl	$8, %eax
	imull	$365, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	-4(%rbp), %edx
	movl	-24(%rbp), %ecx
	subl	%edx, %ecx
	movl	%ecx, %edx
	movl	%edx, %esi
	movl	-4(%rbp), %edx
	movslq	%edx, %rcx
	movq	-32(%rbp), %rdx
	leaq	(%rcx,%rdx), %rdi
	movl	%eax, %ecx
	movl	$.LC39, %edx
	movl	$0, %eax
	call	EApiSprintf
	addl	%eax, -4(%rbp)
.L73:
	.loc 1 334 0
	cmpl	$0, -4(%rbp)
	jne	.L74
	.loc 1 334 0 is_stmt 0 discriminator 1
	movl	-20(%rbp), %eax
	movl	$-2004318071, %edx
	mull	%edx
	movl	%edx, %ecx
	shrl	$5, %ecx
	movl	$-1431655765, %edx
	movl	%ecx, %eax
	mull	%edx
	shrl	$4, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testl	%edx, %edx
	je	.L75
.L74:
	.loc 1 335 0 is_stmt 1
	movl	-20(%rbp), %eax
	movl	$-2004318071, %edx
	mull	%edx
	movl	%edx, %ecx
	shrl	$5, %ecx
	movl	$-1431655765, %edx
	movl	%ecx, %eax
	mull	%edx
	shrl	$4, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	-4(%rbp), %eax
	movl	-24(%rbp), %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, %esi
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movq	-32(%rbp), %rax
	addq	%rcx, %rax
	movl	%edx, %ecx
	movl	$.LC40, %edx
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
	addl	%eax, -4(%rbp)
.L75:
	.loc 1 336 0
	movl	-20(%rbp), %ecx
	movl	$-2004318071, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	movl	%eax, %edx
	leal	0(,%rdx,4), %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sall	$4, %eax
	subl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	-4(%rbp), %edx
	movl	-24(%rbp), %ecx
	subl	%edx, %ecx
	movl	%ecx, %edx
	movl	%edx, %esi
	movl	-4(%rbp), %edx
	movslq	%edx, %rcx
	movq	-32(%rbp), %rdx
	leaq	(%rcx,%rdx), %rdi
	movl	%eax, %ecx
	movl	$.LC41, %edx
	movl	$0, %eax
	call	EApiSprintf
	addl	%eax, -4(%rbp)
	.loc 1 337 0
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
.L69:
	.loc 1 341 0
	movl	-8(%rbp), %eax
	.loc 1 342 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	EApiAHCreateTimeString, .-EApiAHCreateTimeString
	.section	.rodata
.LC42:
	.string	"EApiAHCreateSVersionString"
.LC43:
	.string	"%u.%u"
	.text
	.globl	EApiAHCreateSVersionString
	.type	EApiAHCreateSVersionString, @function
EApiAHCreateSVersionString:
.LFB12:
	.loc 1 351 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	.loc 1 354 0
	cmpq	$0, -32(%rbp)
	jne	.L78
	.loc 1 354 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$354, %ecx
	movl	$.LC42, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L79
.L78:
	.loc 1 355 0 is_stmt 1
	cmpl	$0, -24(%rbp)
	jne	.L80
	.loc 1 355 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC23
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$355, %ecx
	movl	$.LC42, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L79
.L80:
	.loc 1 356 0 is_stmt 1
	movl	-20(%rbp), %eax
	shrl	$16, %eax
	movzbl	%al, %edx
	movl	-20(%rbp), %eax
	shrl	$24, %eax
	movl	%eax, %ecx
	movl	-24(%rbp), %esi
	movq	-32(%rbp), %rax
	movl	%edx, %r8d
	movl	$.LC43, %edx
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
	movl	%eax, -4(%rbp)
.L79:
	.loc 1 360 0
	movl	-4(%rbp), %eax
	.loc 1 361 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	EApiAHCreateSVersionString, .-EApiAHCreateSVersionString
	.section	.rodata
.LC44:
	.string	"EApiAHCreateVersionString"
.LC45:
	.string	"%u.%u.%u"
	.text
	.globl	EApiAHCreateVersionString
	.type	EApiAHCreateVersionString, @function
EApiAHCreateVersionString:
.LFB13:
	.loc 1 368 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	.loc 1 371 0
	cmpq	$0, -32(%rbp)
	jne	.L83
	.loc 1 371 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$371, %ecx
	movl	$.LC44, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L84
.L83:
	.loc 1 372 0 is_stmt 1
	cmpl	$0, -24(%rbp)
	jne	.L85
	.loc 1 372 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC23
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$372, %ecx
	movl	$.LC44, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -4(%rbp)
	jmp	.L84
.L85:
	.loc 1 373 0 is_stmt 1
	movl	-20(%rbp), %eax
	movzwl	%ax, %ecx
	movl	-20(%rbp), %eax
	shrl	$16, %eax
	movzbl	%al, %edx
	movl	-20(%rbp), %eax
	shrl	$24, %eax
	movl	%eax, %edi
	movl	-24(%rbp), %esi
	movq	-32(%rbp), %rax
	movl	%ecx, %r9d
	movl	%edx, %r8d
	movl	%edi, %ecx
	movl	$.LC45, %edx
	movq	%rax, %rdi
	movl	$0, %eax
	call	EApiSprintf
	movl	%eax, -4(%rbp)
.L84:
	.loc 1 377 0
	movl	-4(%rbp), %eax
	.loc 1 378 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	EApiAHCreateVersionString, .-EApiAHCreateVersionString
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
	.section	.rodata
.LC46:
	.string	"EApiAHCreatePNPIDString"
.LC47:
	.string	"pBuffer Too Short"
	.text
	.globl	EApiAHCreatePNPIDString
	.type	EApiAHCreatePNPIDString, @function
EApiAHCreatePNPIDString:
.LFB14:
	.loc 1 403 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	.loc 1 406 0
	movl	-20(%rbp), %eax
	sall	$8, %eax
	movl	%eax, %edx
	movl	-20(%rbp), %eax
	shrl	$8, %eax
	movzbl	%al, %eax
	orl	%edx, %eax
	movw	%ax, -10(%rbp)
	.loc 1 407 0
	cmpq	$0, -32(%rbp)
	jne	.L88
	.loc 1 407 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC22
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$407, %ecx
	movl	$.LC46, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -8(%rbp)
	jmp	.L94
.L88:
	.loc 1 408 0 is_stmt 1
	cmpl	$3, -24(%rbp)
	ja	.L90
	.loc 1 409 0
	subq	$8, %rsp
	pushq	$.LC47
	movl	$.LC19, %r9d
	movl	$-1, %r8d
	movl	$409, %ecx
	movl	$.LC46, %edx
	movl	$.LC21, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-1, -8(%rbp)
	jmp	.L94
.L90:
	.loc 1 411 0
	movzwl	-10(%rbp), %eax
	testw	%ax, %ax
	jns	.L91
	.loc 1 412 0
	movl	$-1, -8(%rbp)
	.loc 1 413 0
	jmp	.L94
.L91:
	.loc 1 415 0
	movl	$0, -4(%rbp)
	jmp	.L92
.L93:
	.loc 1 416 0 discriminator 3
	movl	$2, %eax
	subl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-32(%rbp), %rax
	leaq	(%rdx,%rax), %rsi
	movzwl	-10(%rbp), %edi
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	%eax, %ecx
	sarl	%cl, %edi
	movl	%edi, %eax
	andl	$31, %eax
	cltq
	movzbl	CompressedAsciiLookup(%rax), %eax
	movb	%al, (%rsi)
	.loc 1 415 0 discriminator 3
	addl	$1, -4(%rbp)
.L92:
	.loc 1 415 0 is_stmt 0 discriminator 1
	cmpl	$2, -4(%rbp)
	jle	.L93
	.loc 1 418 0 is_stmt 1
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	.loc 1 419 0
	movl	$3, -8(%rbp)
.L89:
.L94:
	.loc 1 424 0
	movl	-8(%rbp), %eax
	.loc 1 425 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	EApiAHCreatePNPIDString, .-EApiAHCreatePNPIDString
	.globl	EApiStrLenA
	.type	EApiStrLenA, @function
EApiStrLenA:
.LFB15:
	.loc 1 476 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	.loc 1 478 0
	cmpq	$0, -24(%rbp)
	jne	.L97
	.loc 1 478 0 is_stmt 0 discriminator 1
	movl	$0, %eax
	jmp	.L98
.L97:
	.loc 1 479 0 is_stmt 1
	cmpq	$0, -32(%rbp)
	jne	.L99
	.loc 1 479 0 is_stmt 0 discriminator 1
	movl	$0, %eax
	jmp	.L98
.L99:
	.loc 1 481 0 is_stmt 1
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L100
.L103:
	.loc 1 482 0
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L104
	.loc 1 481 0 discriminator 2
	addq	$1, -8(%rbp)
.L100:
	.loc 1 481 0 is_stmt 0 discriminator 1
	movq	-32(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	%rdx, -32(%rbp)
	testq	%rax, %rax
	jne	.L103
	jmp	.L102
.L104:
	.loc 1 483 0 is_stmt 1
	nop
.L102:
	.loc 1 484 0
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
.L98:
	.loc 1 485 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	EApiStrLenA, .-EApiStrLenA
	.globl	EApiStrCpyA
	.type	EApiStrCpyA, @function
EApiStrCpyA:
.LFB16:
	.loc 1 492 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	.loc 1 493 0
	cmpq	$0, -8(%rbp)
	jne	.L106
	.loc 1 493 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	jmp	.L107
.L106:
	.loc 1 494 0 is_stmt 1
	cmpq	$0, -24(%rbp)
	jne	.L108
	.loc 1 494 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	jmp	.L107
.L108:
	.loc 1 495 0 is_stmt 1
	cmpq	$0, -16(%rbp)
	jne	.L109
	.loc 1 495 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	jmp	.L107
.L109:
	.loc 1 497 0 is_stmt 1
	movq	-16(%rbp), %rdx
	movq	-24(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncpy
	.loc 1 498 0
	movq	-16(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	.loc 1 499 0
	movq	-8(%rbp), %rax
.L107:
	.loc 1 500 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	EApiStrCpyA, .-EApiStrCpyA
	.globl	EApiSprintfA
	.type	EApiSprintfA, @function
EApiSprintfA:
.LFB17:
	.loc 1 509 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$256, %rsp
	movq	%rdi, -232(%rbp)
	movq	%rsi, -240(%rbp)
	movq	%rdx, -248(%rbp)
	movq	%rcx, -152(%rbp)
	movq	%r8, -144(%rbp)
	movq	%r9, -136(%rbp)
	testb	%al, %al
	je	.L111
	movaps	%xmm0, -128(%rbp)
	movaps	%xmm1, -112(%rbp)
	movaps	%xmm2, -96(%rbp)
	movaps	%xmm3, -80(%rbp)
	movaps	%xmm4, -64(%rbp)
	movaps	%xmm5, -48(%rbp)
	movaps	%xmm6, -32(%rbp)
	movaps	%xmm7, -16(%rbp)
.L111:
	.loc 1 509 0
	movq	%fs:40, %rax
	movq	%rax, -184(%rbp)
	xorl	%eax, %eax
	.loc 1 512 0
	cmpq	$0, -232(%rbp)
	jne	.L112
	.loc 1 512 0 is_stmt 0 discriminator 1
	movl	$-1, %eax
	jmp	.L116
.L112:
	.loc 1 513 0 is_stmt 1
	cmpq	$0, -248(%rbp)
	jne	.L114
	.loc 1 513 0 is_stmt 0 discriminator 1
	movl	$-1, %eax
	jmp	.L116
.L114:
	.loc 1 514 0 is_stmt 1
	cmpq	$0, -240(%rbp)
	jne	.L115
	.loc 1 514 0 is_stmt 0 discriminator 1
	movl	$-1, %eax
	jmp	.L116
.L115:
	.loc 1 516 0 is_stmt 1
	movl	$24, -208(%rbp)
	movl	$48, -204(%rbp)
	leaq	16(%rbp), %rax
	movq	%rax, -200(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, -192(%rbp)
	.loc 1 517 0
	leaq	-208(%rbp), %rcx
	movq	-248(%rbp), %rdx
	movq	-240(%rbp), %rsi
	movq	-232(%rbp), %rax
	movq	%rax, %rdi
	call	vsnprintf
	movl	%eax, -212(%rbp)
	.loc 1 518 0
	movq	-240(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-232(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	.loc 1 520 0
	movl	-212(%rbp), %eax
.L116:
	.loc 1 521 0 discriminator 1
	movq	-184(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L117
	.loc 1 521 0 is_stmt 0
	call	__stack_chk_fail
.L117:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	EApiSprintfA, .-EApiSprintfA
	.globl	EApiStrLen
	.type	EApiStrLen, @function
EApiStrLen:
.LFB18:
	.loc 1 527 0 is_stmt 1
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	.loc 1 529 0
	cmpq	$0, -24(%rbp)
	jne	.L119
	.loc 1 529 0 is_stmt 0 discriminator 1
	movl	$0, %eax
	jmp	.L120
.L119:
	.loc 1 530 0 is_stmt 1
	cmpq	$0, -32(%rbp)
	jne	.L121
	.loc 1 530 0 is_stmt 0 discriminator 1
	movl	$0, %eax
	jmp	.L120
.L121:
	.loc 1 532 0 is_stmt 1
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L122
.L125:
	.loc 1 533 0
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L126
	.loc 1 532 0 discriminator 2
	addq	$1, -8(%rbp)
.L122:
	.loc 1 532 0 is_stmt 0 discriminator 1
	movq	-32(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	%rdx, -32(%rbp)
	testq	%rax, %rax
	jne	.L125
	jmp	.L124
.L126:
	.loc 1 534 0 is_stmt 1
	nop
.L124:
	.loc 1 535 0
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
.L120:
	.loc 1 536 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	EApiStrLen, .-EApiStrLen
	.globl	EApiStrCpy
	.type	EApiStrCpy, @function
EApiStrCpy:
.LFB19:
	.loc 1 544 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	.loc 1 545 0
	cmpq	$0, -8(%rbp)
	jne	.L128
	.loc 1 545 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	jmp	.L129
.L128:
	.loc 1 546 0 is_stmt 1
	cmpq	$0, -24(%rbp)
	jne	.L130
	.loc 1 546 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	jmp	.L129
.L130:
	.loc 1 547 0 is_stmt 1
	cmpq	$0, -16(%rbp)
	jne	.L131
	.loc 1 547 0 is_stmt 0 discriminator 1
	movq	-8(%rbp), %rax
	jmp	.L129
.L131:
	.loc 1 549 0 is_stmt 1
	movq	-16(%rbp), %rdx
	movq	-24(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncpy
	.loc 1 550 0
	movq	-16(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	.loc 1 551 0
	movq	-8(%rbp), %rax
.L129:
	.loc 1 552 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE19:
	.size	EApiStrCpy, .-EApiStrCpy
	.globl	EApiSprintf
	.type	EApiSprintf, @function
EApiSprintf:
.LFB20:
	.loc 1 561 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$256, %rsp
	movq	%rdi, -232(%rbp)
	movq	%rsi, -240(%rbp)
	movq	%rdx, -248(%rbp)
	movq	%rcx, -152(%rbp)
	movq	%r8, -144(%rbp)
	movq	%r9, -136(%rbp)
	testb	%al, %al
	je	.L133
	movaps	%xmm0, -128(%rbp)
	movaps	%xmm1, -112(%rbp)
	movaps	%xmm2, -96(%rbp)
	movaps	%xmm3, -80(%rbp)
	movaps	%xmm4, -64(%rbp)
	movaps	%xmm5, -48(%rbp)
	movaps	%xmm6, -32(%rbp)
	movaps	%xmm7, -16(%rbp)
.L133:
	.loc 1 561 0
	movq	%fs:40, %rax
	movq	%rax, -184(%rbp)
	xorl	%eax, %eax
	.loc 1 564 0
	cmpq	$0, -232(%rbp)
	jne	.L134
	.loc 1 564 0 is_stmt 0 discriminator 1
	movl	$-1, %eax
	jmp	.L138
.L134:
	.loc 1 565 0 is_stmt 1
	cmpq	$0, -248(%rbp)
	jne	.L136
	.loc 1 565 0 is_stmt 0 discriminator 1
	movl	$-1, %eax
	jmp	.L138
.L136:
	.loc 1 566 0 is_stmt 1
	cmpq	$0, -240(%rbp)
	jne	.L137
	.loc 1 566 0 is_stmt 0 discriminator 1
	movl	$-1, %eax
	jmp	.L138
.L137:
	.loc 1 568 0 is_stmt 1
	movl	$24, -208(%rbp)
	movl	$48, -204(%rbp)
	leaq	16(%rbp), %rax
	movq	%rax, -200(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, -192(%rbp)
	.loc 1 569 0
	leaq	-208(%rbp), %rcx
	movq	-248(%rbp), %rdx
	movq	-240(%rbp), %rsi
	movq	-232(%rbp), %rax
	movq	%rax, %rdi
	call	vsnprintf
	movl	%eax, -212(%rbp)
	.loc 1 570 0
	movq	-240(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-232(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	.loc 1 572 0
	movl	-212(%rbp), %eax
.L138:
	.loc 1 573 0 discriminator 1
	movq	-184(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L139
	.loc 1 573 0 is_stmt 0
	call	__stack_chk_fail
.L139:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE20:
	.size	EApiSprintf, .-EApiSprintf
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
	.file 3 "/usr/include/x86_64-linux-gnu/sys/types.h"
	.file 4 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h"
	.file 5 "<built-in>"
	.file 6 "/usr/include/stdio.h"
	.file 7 "/usr/include/stdint.h"
	.file 8 "../../../include/EApi.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0xa2f
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF71
	.byte	0xc
	.long	.LASF72
	.long	.LASF73
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF10
	.byte	0x2
	.byte	0xd8
	.long	0x38
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF1
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF2
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x5
	.byte	0x8
	.uleb128 0x6
	.byte	0x8
	.long	0x7f
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF8
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF9
	.uleb128 0x2
	.long	.LASF11
	.byte	0x3
	.byte	0xc4
	.long	0x3f
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF12
	.uleb128 0x7
	.long	0x7f
	.long	0xaf
	.uleb128 0x8
	.long	0x70
	.byte	0x1f
	.byte	0
	.uleb128 0x2
	.long	.LASF13
	.byte	0x4
	.byte	0x28
	.long	0xba
	.uleb128 0x7
	.long	0xca
	.long	0xca
	.uleb128 0x8
	.long	0x70
	.byte	0
	.byte	0
	.uleb128 0x9
	.long	.LASF24
	.byte	0x18
	.byte	0x5
	.byte	0
	.long	0x107
	.uleb128 0xa
	.long	.LASF14
	.byte	0x5
	.byte	0
	.long	0x46
	.byte	0
	.uleb128 0xa
	.long	.LASF15
	.byte	0x5
	.byte	0
	.long	0x46
	.byte	0x4
	.uleb128 0xa
	.long	.LASF16
	.byte	0x5
	.byte	0
	.long	0x77
	.byte	0x8
	.uleb128 0xa
	.long	.LASF17
	.byte	0x5
	.byte	0
	.long	0x77
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x10d
	.uleb128 0xb
	.long	0x7f
	.uleb128 0x2
	.long	.LASF18
	.byte	0x6
	.byte	0x4f
	.long	0xaf
	.uleb128 0x2
	.long	.LASF19
	.byte	0x7
	.byte	0x30
	.long	0x4d
	.uleb128 0x2
	.long	.LASF20
	.byte	0x7
	.byte	0x31
	.long	0x54
	.uleb128 0x2
	.long	.LASF21
	.byte	0x7
	.byte	0x33
	.long	0x46
	.uleb128 0x2
	.long	.LASF22
	.byte	0x7
	.byte	0x7a
	.long	0x38
	.uleb128 0x2
	.long	.LASF23
	.byte	0x8
	.byte	0x93
	.long	0x133
	.uleb128 0xb
	.long	0x79
	.uleb128 0xb
	.long	0x133
	.uleb128 0x9
	.long	.LASF25
	.byte	0x10
	.byte	0x1
	.byte	0x25
	.long	0x183
	.uleb128 0xa
	.long	.LASF26
	.byte	0x1
	.byte	0x26
	.long	0x183
	.byte	0
	.uleb128 0xa
	.long	.LASF27
	.byte	0x1
	.byte	0x27
	.long	0x188
	.byte	0x8
	.byte	0
	.uleb128 0xb
	.long	0x149
	.uleb128 0xb
	.long	0x107
	.uleb128 0x2
	.long	.LASF28
	.byte	0x1
	.byte	0x28
	.long	0x15e
	.uleb128 0xc
	.long	.LASF34
	.byte	0x1
	.byte	0x42
	.long	0x2d
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x21c
	.uleb128 0xd
	.long	.LASF29
	.byte	0x1
	.byte	0x43
	.long	0x149
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0xd
	.long	.LASF30
	.byte	0x1
	.byte	0x44
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0xd
	.long	.LASF31
	.byte	0x1
	.byte	0x45
	.long	0x21c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xe
	.long	.LASF26
	.byte	0x1
	.byte	0x48
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xf
	.string	"i"
	.byte	0x1
	.byte	0x49
	.long	0x46
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x10
	.long	.LASF32
	.byte	0x1
	.byte	0x6c
	.quad	.L3
	.uleb128 0x10
	.long	.LASF33
	.byte	0x1
	.byte	0x6d
	.quad	.L10
	.byte	0
	.uleb128 0xb
	.long	0x2d
	.uleb128 0xc
	.long	.LASF35
	.byte	0x1
	.byte	0x71
	.long	0x149
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x2a5
	.uleb128 0xd
	.long	.LASF29
	.byte	0x1
	.byte	0x72
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0xd
	.long	.LASF30
	.byte	0x1
	.byte	0x73
	.long	0x2ab
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0xe
	.long	.LASF26
	.byte	0x1
	.byte	0x76
	.long	0x149
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xf
	.string	"i"
	.byte	0x1
	.byte	0x77
	.long	0x46
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xe
	.long	.LASF36
	.byte	0x1
	.byte	0x78
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x10
	.long	.LASF32
	.byte	0x1
	.byte	0x8e
	.quad	.L14
	.uleb128 0x10
	.long	.LASF37
	.byte	0x1
	.byte	0x8f
	.quad	.L19
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x79
	.uleb128 0xb
	.long	0x2a5
	.uleb128 0xc
	.long	.LASF38
	.byte	0x1
	.byte	0x94
	.long	0x2d
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x336
	.uleb128 0xd
	.long	.LASF39
	.byte	0x1
	.byte	0x95
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0xd
	.long	.LASF30
	.byte	0x1
	.byte	0x96
	.long	0x79
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0xd
	.long	.LASF31
	.byte	0x1
	.byte	0x97
	.long	0x2d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0xe
	.long	.LASF26
	.byte	0x1
	.byte	0x9a
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xe
	.long	.LASF40
	.byte	0x1
	.byte	0x9b
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0xe
	.long	.LASF41
	.byte	0x1
	.byte	0x9c
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x10
	.long	.LASF32
	.byte	0x1
	.byte	0xb5
	.quad	.L23
	.byte	0
	.uleb128 0xc
	.long	.LASF42
	.byte	0x1
	.byte	0xbb
	.long	0x149
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x3ad
	.uleb128 0xd
	.long	.LASF39
	.byte	0x1
	.byte	0xbc
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0xd
	.long	.LASF30
	.byte	0x1
	.byte	0xbd
	.long	0x2ab
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0xe
	.long	.LASF26
	.byte	0x1
	.byte	0xc2
	.long	0x149
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xe
	.long	.LASF43
	.byte	0x1
	.byte	0xc3
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0xe
	.long	.LASF41
	.byte	0x1
	.byte	0xc4
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x10
	.long	.LASF32
	.byte	0x1
	.byte	0xeb
	.quad	.L32
	.byte	0
	.uleb128 0xc
	.long	.LASF44
	.byte	0x1
	.byte	0xf0
	.long	0x3f
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x416
	.uleb128 0xd
	.long	.LASF45
	.byte	0x1
	.byte	0xf1
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0xd
	.long	.LASF30
	.byte	0x1
	.byte	0xf2
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0xd
	.long	.LASF31
	.byte	0x1
	.byte	0xf3
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xe
	.long	.LASF26
	.byte	0x1
	.byte	0xf6
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x10
	.long	.LASF32
	.byte	0x1
	.byte	0xfa
	.quad	.L44
	.byte	0
	.uleb128 0xc
	.long	.LASF46
	.byte	0x1
	.byte	0xff
	.long	0x3f
	.quad	.LFB7
	.quad	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0x484
	.uleb128 0x11
	.long	.LASF45
	.byte	0x1
	.value	0x100
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x11
	.long	.LASF30
	.byte	0x1
	.value	0x101
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x11
	.long	.LASF31
	.byte	0x1
	.value	0x102
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x12
	.long	.LASF26
	.byte	0x1
	.value	0x105
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x13
	.long	.LASF32
	.byte	0x1
	.value	0x109
	.quad	.L49
	.byte	0
	.uleb128 0x14
	.long	.LASF47
	.byte	0x1
	.value	0x10e
	.long	0x3f
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0x4f3
	.uleb128 0x11
	.long	.LASF45
	.byte	0x1
	.value	0x10f
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x11
	.long	.LASF30
	.byte	0x1
	.value	0x110
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x11
	.long	.LASF31
	.byte	0x1
	.value	0x111
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x12
	.long	.LASF26
	.byte	0x1
	.value	0x114
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x13
	.long	.LASF32
	.byte	0x1
	.value	0x11a
	.quad	.L54
	.byte	0
	.uleb128 0x14
	.long	.LASF48
	.byte	0x1
	.value	0x11f
	.long	0x3f
	.quad	.LFB9
	.quad	.LFE9-.LFB9
	.uleb128 0x1
	.byte	0x9c
	.long	0x562
	.uleb128 0x11
	.long	.LASF45
	.byte	0x1
	.value	0x120
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x11
	.long	.LASF30
	.byte	0x1
	.value	0x121
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x11
	.long	.LASF31
	.byte	0x1
	.value	0x122
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x12
	.long	.LASF26
	.byte	0x1
	.value	0x125
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x13
	.long	.LASF32
	.byte	0x1
	.value	0x12a
	.quad	.L59
	.byte	0
	.uleb128 0x14
	.long	.LASF49
	.byte	0x1
	.value	0x12f
	.long	0x3f
	.quad	.LFB10
	.quad	.LFE10-.LFB10
	.uleb128 0x1
	.byte	0x9c
	.long	0x5d1
	.uleb128 0x11
	.long	.LASF45
	.byte	0x1
	.value	0x130
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x11
	.long	.LASF30
	.byte	0x1
	.value	0x131
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x11
	.long	.LASF31
	.byte	0x1
	.value	0x132
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x12
	.long	.LASF26
	.byte	0x1
	.value	0x135
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x13
	.long	.LASF32
	.byte	0x1
	.value	0x13b
	.quad	.L64
	.byte	0
	.uleb128 0x14
	.long	.LASF50
	.byte	0x1
	.value	0x140
	.long	0x3f
	.quad	.LFB11
	.quad	.LFE11-.LFB11
	.uleb128 0x1
	.byte	0x9c
	.long	0x64f
	.uleb128 0x11
	.long	.LASF45
	.byte	0x1
	.value	0x141
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x11
	.long	.LASF30
	.byte	0x1
	.value	0x142
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x11
	.long	.LASF31
	.byte	0x1
	.value	0x143
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x12
	.long	.LASF26
	.byte	0x1
	.value	0x146
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x12
	.long	.LASF51
	.byte	0x1
	.value	0x147
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x13
	.long	.LASF32
	.byte	0x1
	.value	0x153
	.quad	.L69
	.byte	0
	.uleb128 0x14
	.long	.LASF52
	.byte	0x1
	.value	0x15a
	.long	0x3f
	.quad	.LFB12
	.quad	.LFE12-.LFB12
	.uleb128 0x1
	.byte	0x9c
	.long	0x6be
	.uleb128 0x11
	.long	.LASF45
	.byte	0x1
	.value	0x15b
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x11
	.long	.LASF30
	.byte	0x1
	.value	0x15c
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x11
	.long	.LASF31
	.byte	0x1
	.value	0x15d
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x12
	.long	.LASF26
	.byte	0x1
	.value	0x160
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x13
	.long	.LASF32
	.byte	0x1
	.value	0x166
	.quad	.L79
	.byte	0
	.uleb128 0x14
	.long	.LASF53
	.byte	0x1
	.value	0x16b
	.long	0x3f
	.quad	.LFB13
	.quad	.LFE13-.LFB13
	.uleb128 0x1
	.byte	0x9c
	.long	0x72d
	.uleb128 0x11
	.long	.LASF45
	.byte	0x1
	.value	0x16c
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x11
	.long	.LASF30
	.byte	0x1
	.value	0x16d
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x11
	.long	.LASF31
	.byte	0x1
	.value	0x16e
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x12
	.long	.LASF26
	.byte	0x1
	.value	0x171
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x13
	.long	.LASF32
	.byte	0x1
	.value	0x177
	.quad	.L84
	.byte	0
	.uleb128 0x14
	.long	.LASF54
	.byte	0x1
	.value	0x18e
	.long	0x3f
	.quad	.LFB14
	.quad	.LFE14-.LFB14
	.uleb128 0x1
	.byte	0x9c
	.long	0x7ca
	.uleb128 0x11
	.long	.LASF45
	.byte	0x1
	.value	0x18f
	.long	0x133
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x11
	.long	.LASF30
	.byte	0x1
	.value	0x190
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x11
	.long	.LASF31
	.byte	0x1
	.value	0x191
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x12
	.long	.LASF26
	.byte	0x1
	.value	0x194
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x15
	.string	"cnt"
	.byte	0x1
	.value	0x195
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x12
	.long	.LASF55
	.byte	0x1
	.value	0x196
	.long	0x54
	.uleb128 0x2
	.byte	0x91
	.sleb128 -26
	.uleb128 0x13
	.long	.LASF32
	.byte	0x1
	.value	0x1a6
	.quad	.L94
	.uleb128 0x13
	.long	.LASF56
	.byte	0x1
	.value	0x1a5
	.quad	.L89
	.byte	0
	.uleb128 0x16
	.long	.LASF57
	.byte	0x1
	.value	0x1d8
	.long	0x2d
	.quad	.LFB15
	.quad	.LFE15-.LFB15
	.uleb128 0x1
	.byte	0x9c
	.long	0x81a
	.uleb128 0x11
	.long	.LASF58
	.byte	0x1
	.value	0x1d9
	.long	0x107
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x11
	.long	.LASF59
	.byte	0x1
	.value	0x1da
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x12
	.long	.LASF60
	.byte	0x1
	.value	0x1dd
	.long	0x107
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x14
	.long	.LASF61
	.byte	0x1
	.value	0x1e7
	.long	0x79
	.quad	.LFB16
	.quad	.LFE16-.LFB16
	.uleb128 0x1
	.byte	0x9c
	.long	0x86a
	.uleb128 0x11
	.long	.LASF62
	.byte	0x1
	.value	0x1e8
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x11
	.long	.LASF31
	.byte	0x1
	.value	0x1e9
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x11
	.long	.LASF63
	.byte	0x1
	.value	0x1ea
	.long	0x188
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.byte	0
	.uleb128 0x14
	.long	.LASF64
	.byte	0x1
	.value	0x1f7
	.long	0x3f
	.quad	.LFB17
	.quad	.LFE17-.LFB17
	.uleb128 0x1
	.byte	0x9c
	.long	0x8de
	.uleb128 0x11
	.long	.LASF58
	.byte	0x1
	.value	0x1f8
	.long	0x154
	.uleb128 0x3
	.byte	0x91
	.sleb128 -248
	.uleb128 0x11
	.long	.LASF59
	.byte	0x1
	.value	0x1f9
	.long	0x21c
	.uleb128 0x3
	.byte	0x91
	.sleb128 -256
	.uleb128 0x17
	.string	"fmt"
	.byte	0x1
	.value	0x1fa
	.long	0x188
	.uleb128 0x3
	.byte	0x91
	.sleb128 -264
	.uleb128 0x18
	.uleb128 0x12
	.long	.LASF65
	.byte	0x1
	.value	0x1fe
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -228
	.uleb128 0x15
	.string	"arg"
	.byte	0x1
	.value	0x1ff
	.long	0x112
	.uleb128 0x3
	.byte	0x91
	.sleb128 -224
	.byte	0
	.uleb128 0x16
	.long	.LASF66
	.byte	0x1
	.value	0x20b
	.long	0x2d
	.quad	.LFB18
	.quad	.LFE18-.LFB18
	.uleb128 0x1
	.byte	0x9c
	.long	0x92e
	.uleb128 0x11
	.long	.LASF58
	.byte	0x1
	.value	0x20c
	.long	0x107
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x11
	.long	.LASF59
	.byte	0x1
	.value	0x20d
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x12
	.long	.LASF60
	.byte	0x1
	.value	0x210
	.long	0x107
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x14
	.long	.LASF67
	.byte	0x1
	.value	0x21b
	.long	0x79
	.quad	.LFB19
	.quad	.LFE19-.LFB19
	.uleb128 0x1
	.byte	0x9c
	.long	0x97e
	.uleb128 0x11
	.long	.LASF62
	.byte	0x1
	.value	0x21c
	.long	0x154
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x11
	.long	.LASF31
	.byte	0x1
	.value	0x21d
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x11
	.long	.LASF63
	.byte	0x1
	.value	0x21e
	.long	0x188
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.byte	0
	.uleb128 0x14
	.long	.LASF68
	.byte	0x1
	.value	0x22b
	.long	0x3f
	.quad	.LFB20
	.quad	.LFE20-.LFB20
	.uleb128 0x1
	.byte	0x9c
	.long	0x9f2
	.uleb128 0x11
	.long	.LASF58
	.byte	0x1
	.value	0x22c
	.long	0x154
	.uleb128 0x3
	.byte	0x91
	.sleb128 -248
	.uleb128 0x11
	.long	.LASF59
	.byte	0x1
	.value	0x22d
	.long	0x21c
	.uleb128 0x3
	.byte	0x91
	.sleb128 -256
	.uleb128 0x17
	.string	"fmt"
	.byte	0x1
	.value	0x22e
	.long	0x188
	.uleb128 0x3
	.byte	0x91
	.sleb128 -264
	.uleb128 0x18
	.uleb128 0x12
	.long	.LASF65
	.byte	0x1
	.value	0x232
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -228
	.uleb128 0x15
	.string	"arg"
	.byte	0x1
	.value	0x233
	.long	0x112
	.uleb128 0x3
	.byte	0x91
	.sleb128 -224
	.byte	0
	.uleb128 0x7
	.long	0x18d
	.long	0xa02
	.uleb128 0x8
	.long	0x70
	.byte	0x12
	.byte	0
	.uleb128 0x19
	.long	.LASF69
	.byte	0x1
	.byte	0x2c
	.long	0xa17
	.uleb128 0x9
	.byte	0x3
	.quad	ErrorLookup
	.uleb128 0xb
	.long	0x9f2
	.uleb128 0x1a
	.long	.LASF70
	.byte	0x1
	.value	0x17d
	.long	0x9f
	.uleb128 0x9
	.byte	0x3
	.quad	CompressedAsciiLookup
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0xa
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0xa
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x11
	.uleb128 0x1
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF35:
	.string	"EApiAHCreateErrorStringAlloc"
.LASF67:
	.string	"EApiStrCpy"
.LASF64:
	.string	"EApiSprintfA"
.LASF37:
	.string	"SuccessExit"
.LASF41:
	.string	"StringBufferLenBck"
.LASF30:
	.string	"pString"
.LASF5:
	.string	"short int"
.LASF10:
	.string	"size_t"
.LASF42:
	.string	"EApiAHGetStringAlloc"
.LASF7:
	.string	"sizetype"
.LASF27:
	.string	"ErrorString"
.LASF51:
	.string	"StrLength"
.LASF18:
	.string	"va_list"
.LASF54:
	.string	"EApiAHCreatePNPIDString"
.LASF24:
	.string	"__va_list_tag"
.LASF72:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHStr.c"
.LASF19:
	.string	"uint8_t"
.LASF71:
	.string	"GNU C11 5.2.1 20151010 -mtune=generic -march=x86-64 -g -O0 -fstack-protector-strong"
.LASF57:
	.string	"EApiStrLenA"
.LASF44:
	.string	"EApiAHCreateDecimalString"
.LASF22:
	.string	"uintptr_t"
.LASF68:
	.string	"EApiSprintf"
.LASF9:
	.string	"long long int"
.LASF50:
	.string	"EApiAHCreateTimeString"
.LASF6:
	.string	"long int"
.LASF53:
	.string	"EApiAHCreateVersionString"
.LASF15:
	.string	"fp_offset"
.LASF33:
	.string	"ExitSuccess"
.LASF58:
	.string	"pBuffer"
.LASF59:
	.string	"BufferLen"
.LASF70:
	.string	"CompressedAsciiLookup"
.LASF14:
	.string	"gp_offset"
.LASF31:
	.string	"StrBufLen"
.LASF23:
	.string	"EApiStatus_t"
.LASF34:
	.string	"EApiAHCreateErrorString"
.LASF43:
	.string	"StringLen"
.LASF45:
	.string	"Value"
.LASF2:
	.string	"unsigned char"
.LASF60:
	.string	"pszCurChar"
.LASF32:
	.string	"ExitPoint"
.LASF4:
	.string	"signed char"
.LASF11:
	.string	"int32_t"
.LASF12:
	.string	"long long unsigned int"
.LASF21:
	.string	"uint32_t"
.LASF25:
	.string	"ErrorLookupTbl_S"
.LASF1:
	.string	"unsigned int"
.LASF20:
	.string	"uint16_t"
.LASF46:
	.string	"EApiAHCreateHexString"
.LASF36:
	.string	"StrLen"
.LASF3:
	.string	"short unsigned int"
.LASF17:
	.string	"reg_save_area"
.LASF8:
	.string	"char"
.LASF48:
	.string	"EApiAHCreateRotationsString"
.LASF26:
	.string	"StatusCode"
.LASF49:
	.string	"EApiAHCreateTempString"
.LASF40:
	.string	"StringLenLcl"
.LASF28:
	.string	"ErrorLookupTbl_t"
.LASF39:
	.string	"StringID"
.LASF52:
	.string	"EApiAHCreateSVersionString"
.LASF65:
	.string	"ReturnValue"
.LASF29:
	.string	"DispStatusCode"
.LASF0:
	.string	"long unsigned int"
.LASF47:
	.string	"EApiAHCreateVoltageString"
.LASF16:
	.string	"overflow_arg_area"
.LASF55:
	.string	"PNPID"
.LASF69:
	.string	"ErrorLookup"
.LASF56:
	.string	"ErrorExit"
.LASF62:
	.string	"StringDest"
.LASF13:
	.string	"__gnuc_va_list"
.LASF61:
	.string	"EApiStrCpyA"
.LASF73:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux"
.LASF38:
	.string	"EApiAHGetString"
.LASF63:
	.string	"StringSource"
.LASF66:
	.string	"EApiStrLen"
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
