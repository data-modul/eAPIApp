	.file	"EApiAHI2C.c"
	.text
.Ltext0:
	.section	.rodata
.LC0:
	.string	"%s\n"
.LC1:
	.string	"EApiAHI2CCCreateAddrOffset"
	.align 8
.LC2:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHI2C.c"
.LC3:
	.string	"(pDDesc==NULL)"
.LC4:
	.string	"(pEncAddr==NULL)"
.LC5:
	.string	"(pEncOffset==NULL)"
	.text
	.globl	EApiAHI2CCCreateAddrOffset
	.type	EApiAHI2CCCreateAddrOffset, @function
EApiAHI2CCCreateAddrOffset:
.LFB2:
	.file 1 "/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHI2C.c"
	.loc 1 45 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	.loc 1 46 0
	movl	$0, -4(%rbp)
	.loc 1 47 0
	cmpq	$0, -24(%rbp)
	jne	.L2
	.loc 1 47 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC3
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$51, %ecx
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -4(%rbp)
	jmp	.L3
.L2:
	.loc 1 52 0 is_stmt 1
	cmpq	$0, -40(%rbp)
	jne	.L4
	.loc 1 52 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC4
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$56, %ecx
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -4(%rbp)
	jmp	.L3
.L4:
	.loc 1 57 0 is_stmt 1
	cmpq	$0, -48(%rbp)
	jne	.L5
	.loc 1 57 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC5
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$61, %ecx
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -4(%rbp)
	jmp	.L3
.L5:
	.loc 1 62 0 is_stmt 1
	movq	-24(%rbp), %rax
	movzwl	4(%rax), %eax
	cmpw	$2, %ax
	jne	.L6
	.loc 1 64 0
	movq	-32(%rbp), %rax
	movzwl	%ax, %eax
	orl	$-2147483648, %eax
	movl	%eax, %edx
	movq	-48(%rbp), %rax
	movq	%rdx, (%rax)
	.loc 1 65 0
	shrq	$16, -32(%rbp)
	.loc 1 66 0
	andq	$3, -32(%rbp)
	.loc 1 67 0
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$63488, %eax
	cmpl	$61440, %eax
	jne	.L7
	.loc 1 68 0
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	movzbl	%al, %edx
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	shrw	%ax
	movzwl	%ax, %eax
	andl	$768, %eax
	orl	%edx, %eax
	movl	%eax, %edx
	movq	-32(%rbp), %rax
	addl	%edx, %eax
	movzbl	%al, %edx
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	movzbl	%al, %ecx
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	shrw	%ax
	movzwl	%ax, %eax
	andl	$768, %eax
	orl	%ecx, %eax
	movl	%eax, %ecx
	movq	-32(%rbp), %rax
	addl	%ecx, %eax
	andl	$768, %eax
	addl	%eax, %eax
	orl	%edx, %eax
	orb	$240, %ah
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
	jmp	.L3
.L7:
	.loc 1 71 0
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	shrw	%ax
	movl	%eax, %edx
	movq	-32(%rbp), %rax
	addl	%edx, %eax
	addl	%eax, %eax
	movzbl	%al, %edx
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
	jmp	.L3
.L6:
	.loc 1 76 0
	movq	-32(%rbp), %rax
	movzbl	%al, %edx
	movq	-48(%rbp), %rax
	movq	%rdx, (%rax)
	.loc 1 77 0
	shrq	$8, -32(%rbp)
	.loc 1 78 0
	andq	$3, -32(%rbp)
	.loc 1 79 0
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$63488, %eax
	cmpl	$61440, %eax
	jne	.L9
	.loc 1 80 0
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	movzbl	%al, %edx
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	shrw	%ax
	movzwl	%ax, %eax
	andl	$768, %eax
	orl	%edx, %eax
	movl	%eax, %edx
	movq	-32(%rbp), %rax
	addl	%edx, %eax
	movzbl	%al, %edx
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	movzbl	%al, %ecx
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	shrw	%ax
	movzwl	%ax, %eax
	andl	$768, %eax
	orl	%ecx, %eax
	movl	%eax, %ecx
	movq	-32(%rbp), %rax
	addl	%ecx, %eax
	andl	$768, %eax
	addl	%eax, %eax
	orl	%edx, %eax
	orb	$240, %ah
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
	jmp	.L3
.L9:
	.loc 1 83 0
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	shrw	%ax
	movl	%eax, %edx
	movq	-32(%rbp), %rax
	addl	%edx, %eax
	addl	%eax, %eax
	movzbl	%al, %edx
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
.L3:
	.loc 1 88 0
	movl	-4(%rbp), %eax
	.loc 1 89 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	EApiAHI2CCCreateAddrOffset, .-EApiAHI2CCCreateAddrOffset
	.globl	ValidEEPDevDesc
	.type	ValidEEPDevDesc, @function
ValidEEPDevDesc:
.LFB3:
	.loc 1 94 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	.loc 1 95 0
	movl	$0, -8(%rbp)
	.loc 1 97 0
	movq	-24(%rbp), %rax
	movzwl	4(%rax), %eax
	cmpw	$2, %ax
	jne	.L12
	.loc 1 99 0
	movq	-24(%rbp), %rax
	movl	8(%rax), %eax
	shrl	$16, %eax
	addl	%eax, %eax
	movl	%eax, -4(%rbp)
	jmp	.L13
.L12:
	.loc 1 107 0
	movq	-24(%rbp), %rax
	movl	8(%rax), %eax
	shrl	$8, %eax
	addl	%eax, %eax
	movl	%eax, -4(%rbp)
	.loc 1 108 0
	cmpl	$0, -4(%rbp)
	je	.L13
	.loc 1 110 0
	movq	-24(%rbp), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	cmpl	$175, %eax
	jle	.L13
	.loc 1 112 0
	movl	$-257, %eax
	jmp	.L14
.L13:
	.loc 1 116 0
	movl	-8(%rbp), %eax
.L14:
	.loc 1 117 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	ValidEEPDevDesc, .-ValidEEPDevDesc
	.section	.rodata
.LC6:
	.string	"EApiAHI2CWriteEeprom"
.LC7:
	.string	"(pBuffer==NULL)"
.LC8:
	.string	"(ByteCnt==0)"
	.align 8
.LC9:
	.string	"Invalid EEPROM Device Descriptor"
	.align 8
.LC10:
	.string	"Prevented Write beyond Device Boundary"
	.text
	.globl	EApiAHI2CWriteEeprom
	.type	EApiAHI2CWriteEeprom, @function
EApiAHI2CWriteEeprom:
.LFB4:
	.loc 1 126 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	%rcx, -96(%rbp)
	movq	%r8, -104(%rbp)
	.loc 1 126 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 127 0
	movl	$0, -60(%rbp)
	.loc 1 136 0
	cmpq	$0, -80(%rbp)
	jne	.L16
	.loc 1 136 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC3
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$140, %ecx
	movl	$.LC6, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -60(%rbp)
	jmp	.L34
.L16:
	.loc 1 141 0 is_stmt 1
	cmpq	$0, -96(%rbp)
	jne	.L18
	.loc 1 141 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC7
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$145, %ecx
	movl	$.LC6, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -60(%rbp)
	jmp	.L34
.L18:
	.loc 1 146 0 is_stmt 1
	cmpq	$0, -104(%rbp)
	jne	.L19
	.loc 1 146 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC8
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$150, %ecx
	movl	$.LC6, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -60(%rbp)
	jmp	.L34
.L19:
	.loc 1 151 0 is_stmt 1
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	ValidEEPDevDesc
	testl	%eax, %eax
	je	.L20
	.loc 1 151 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC9
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$156, %ecx
	movl	$.LC6, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -60(%rbp)
	jmp	.L34
.L20:
	.loc 1 157 0 is_stmt 1
	movq	-88(%rbp), %rdx
	movq	-104(%rbp), %rax
	addq	%rax, %rdx
	movq	-80(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %eax
	cmpq	%rax, %rdx
	jbe	.L21
	.loc 1 157 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC10
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$162, %ecx
	movl	$.LC6, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -60(%rbp)
	jmp	.L34
.L21:
	.loc 1 164 0 is_stmt 1
	movq	-88(%rbp), %rdx
	movq	-104(%rbp), %rax
	addq	%rax, %rdx
	movq	-80(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %eax
	cmpq	%rax, %rdx
	jbe	.L22
	.loc 1 166 0
	movq	-80(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %eax
	subq	-88(%rbp), %rax
	movq	%rax, -104(%rbp)
.L22:
	.loc 1 189 0
	leaq	-64(%rbp), %rdx
	movl	-68(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	EApiI2CGetBusCap
	movl	%eax, -60(%rbp)
	.loc 1 190 0
	cmpl	$0, -60(%rbp)
	jne	.L37
	.loc 1 193 0
	movq	-88(%rbp), %rdx
	movq	-104(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -24(%rbp)
	.loc 1 200 0
	movq	-80(%rbp), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	movzbl	%al, %edx
	movq	-80(%rbp), %rax
	movzwl	(%rax), %eax
	shrw	%ax
	movzwl	%ax, %eax
	andl	$768, %eax
	orl	%edx, %eax
	testl	%eax, %eax
	setne	%al
	movzbl	%al, %edx
	movq	-80(%rbp), %rax
	movzwl	4(%rax), %eax
	movzwl	%ax, %eax
	addl	%edx, %eax
	cltq
	movq	%rax, -40(%rbp)
	.loc 1 205 0
	movl	-64(%rbp), %eax
	movl	%eax, %ecx
	movq	-80(%rbp), %rax
	movzwl	2(%rax), %eax
	movzwl	%ax, %edx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	cmpq	%rax, %rcx
	jnb	.L24
	.loc 1 205 0 is_stmt 0 discriminator 1
	movl	-64(%rbp), %eax
	movl	%eax, %eax
	subq	-40(%rbp), %rax
	jmp	.L25
.L24:
	.loc 1 205 0 discriminator 2
	movq	-80(%rbp), %rax
	movzwl	2(%rax), %eax
	movzwl	%ax, %eax
.L25:
	.loc 1 205 0 discriminator 4
	movq	%rax, -40(%rbp)
	.loc 1 207 0 is_stmt 1 discriminator 4
	movq	-80(%rbp), %rax
	movzwl	4(%rax), %eax
	cmpw	$2, %ax
	jne	.L26
	.loc 1 209 0
	movl	$65536, %eax
	cmpq	$65536, -40(%rbp)
	cmovbe	-40(%rbp), %rax
	movq	%rax, -40(%rbp)
	jmp	.L27
.L26:
	.loc 1 212 0
	movl	$256, %eax
	cmpq	$256, -40(%rbp)
	cmovbe	-40(%rbp), %rax
	movq	%rax, -40(%rbp)
.L27:
	.loc 1 213 0
	movq	-88(%rbp), %rax
	movq	%rax, -32(%rbp)
	.loc 1 214 0
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	.loc 1 215 0
	jmp	.L28
.L33:
	.loc 1 219 0
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	cmpq	-24(%rbp), %rax
	jbe	.L29
	.loc 1 220 0
	movq	-24(%rbp), %rax
	subq	-32(%rbp), %rax
	movq	%rax, -40(%rbp)
.L29:
	.loc 1 269 0
	movq	-80(%rbp), %rax
	movzwl	2(%rax), %eax
	movzwl	%ax, %ecx
	movq	-32(%rbp), %rax
	movl	$0, %edx
	divq	%rcx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movq	-80(%rbp), %rax
	movzwl	2(%rax), %eax
	movzwl	%ax, %eax
	cmpq	%rax, %rdx
	jbe	.L30
	.loc 1 270 0
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movq	-80(%rbp), %rax
	movzwl	2(%rax), %eax
	movzwl	%ax, %ecx
	movq	%rdx, %rax
	movl	$0, %edx
	divq	%rcx
	movq	%rdx, %rax
	subq	%rax, -40(%rbp)
.L30:
	.loc 1 273 0
	leaq	-48(%rbp), %rcx
	leaq	-56(%rbp), %rdx
	movq	-32(%rbp), %rsi
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	EApiAHI2CCCreateAddrOffset
	movl	%eax, -60(%rbp)
	.loc 1 274 0
	cmpl	$0, -60(%rbp)
	jne	.L38
	.loc 1 277 0
	movq	-40(%rbp), %rax
	movl	%eax, %ecx
	.loc 1 281 0
	movq	-32(%rbp), %rax
	subq	-88(%rbp), %rax
	movq	%rax, %rdx
	.loc 1 277 0
	movq	-96(%rbp), %rax
	addq	%rax, %rdx
	movq	-48(%rbp), %rax
	movl	%eax, %edi
	movq	-56(%rbp), %rax
	movl	%eax, %esi
	movl	-68(%rbp), %eax
	movl	%ecx, %r8d
	movq	%rdx, %rcx
	movl	%edi, %edx
	movl	%eax, %edi
	call	EApiI2CWriteTransfer
	movl	%eax, -60(%rbp)
	.loc 1 284 0
	cmpl	$0, -60(%rbp)
	jne	.L39
	.loc 1 286 0
	movq	-40(%rbp), %rax
	addq	%rax, -32(%rbp)
	.loc 1 287 0
	movq	-16(%rbp), %rax
	movq	%rax, -40(%rbp)
	.loc 1 288 0
	movq	-80(%rbp), %rax
	movzwl	6(%rax), %eax
	testw	%ax, %ax
	je	.L28
	.loc 1 289 0
	movq	-80(%rbp), %rax
	movzwl	6(%rax), %eax
	movzwl	%ax, %eax
	imull	$1000, %eax, %eax
	movl	%eax, %edi
	call	usleep
.L28:
	.loc 1 215 0
	movq	-32(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jb	.L33
	jmp	.L34
.L17:
.L37:
	.loc 1 191 0
	nop
	jmp	.L34
.L38:
	.loc 1 275 0
	nop
	jmp	.L34
.L39:
	.loc 1 285 0
	nop
.L34:
	.loc 1 293 0
	movl	-60(%rbp), %eax
	.loc 1 294 0
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L36
	call	__stack_chk_fail
.L36:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	EApiAHI2CWriteEeprom, .-EApiAHI2CWriteEeprom
	.section	.rodata
.LC11:
	.string	"EApiAHI2CReadEeprom"
.LC12:
	.string	"(BufLength==0)"
	.align 8
.LC13:
	.string	" pBuffer Overflow PreventedByteCnt>BufLength"
	.text
	.globl	EApiAHI2CReadEeprom
	.type	EApiAHI2CReadEeprom, @function
EApiAHI2CReadEeprom:
.LFB5:
	.loc 1 304 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	%rcx, -96(%rbp)
	movq	%r8, -104(%rbp)
	movq	%r9, -112(%rbp)
	.loc 1 304 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 305 0
	movl	$0, -52(%rbp)
	.loc 1 313 0
	cmpq	$0, -80(%rbp)
	jne	.L41
	.loc 1 313 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC3
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$317, %ecx
	movl	$.LC11, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -52(%rbp)
	jmp	.L58
.L41:
	.loc 1 318 0 is_stmt 1
	cmpq	$0, -96(%rbp)
	jne	.L43
	.loc 1 318 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC7
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$322, %ecx
	movl	$.LC11, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -52(%rbp)
	jmp	.L58
.L43:
	.loc 1 323 0 is_stmt 1
	cmpq	$0, -104(%rbp)
	jne	.L44
	.loc 1 323 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC12
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$327, %ecx
	movl	$.LC11, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -52(%rbp)
	jmp	.L58
.L44:
	.loc 1 328 0 is_stmt 1
	cmpq	$0, -112(%rbp)
	jne	.L45
	.loc 1 328 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC8
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$332, %ecx
	movl	$.LC11, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -52(%rbp)
	jmp	.L58
.L45:
	.loc 1 333 0 is_stmt 1
	movq	-112(%rbp), %rax
	cmpq	-104(%rbp), %rax
	jbe	.L46
	.loc 1 333 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC13
	movl	$.LC0, %r9d
	movl	$-1537, %r8d
	movl	$337, %ecx
	movl	$.LC11, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movq	-104(%rbp), %rax
	movq	%rax, -112(%rbp)
.L46:
	.loc 1 338 0 is_stmt 1
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	ValidEEPDevDesc
	testl	%eax, %eax
	je	.L47
	.loc 1 338 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC9
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$343, %ecx
	movl	$.LC11, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -52(%rbp)
	jmp	.L58
.L47:
	.loc 1 344 0 is_stmt 1
	movq	-88(%rbp), %rdx
	movq	-112(%rbp), %rax
	addq	%rax, %rdx
	movq	-80(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %eax
	cmpq	%rax, %rdx
	jbe	.L48
	.loc 1 344 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC10
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$349, %ecx
	movl	$.LC11, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -52(%rbp)
	jmp	.L58
.L48:
	.loc 1 351 0 is_stmt 1
	movq	-88(%rbp), %rdx
	movq	-112(%rbp), %rax
	addq	%rax, %rdx
	movq	-80(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %eax
	cmpq	%rax, %rdx
	jbe	.L49
	.loc 1 353 0
	movq	-80(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %eax
	subq	-88(%rbp), %rax
	movq	%rax, -112(%rbp)
.L49:
	.loc 1 358 0
	leaq	-56(%rbp), %rdx
	movl	-68(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	EApiI2CGetBusCap
	movl	%eax, -52(%rbp)
	.loc 1 359 0
	cmpl	$0, -52(%rbp)
	jne	.L61
	.loc 1 362 0
	movq	-88(%rbp), %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -16(%rbp)
	.loc 1 364 0
	movq	-80(%rbp), %rax
	movzwl	4(%rax), %eax
	cmpw	$2, %ax
	jne	.L51
	.loc 1 366 0
	movl	-56(%rbp), %eax
	movl	$65536, %edx
	cmpl	$65536, %eax
	cmova	%edx, %eax
	movl	%eax, %eax
	movq	%rax, -32(%rbp)
	jmp	.L52
.L51:
	.loc 1 369 0
	movl	-56(%rbp), %eax
	movl	$256, %edx
	cmpl	$256, %eax
	cmova	%edx, %eax
	movl	%eax, %eax
	movq	%rax, -32(%rbp)
.L52:
	.loc 1 370 0
	movq	-88(%rbp), %rax
	movq	%rax, -24(%rbp)
	.loc 1 371 0
	jmp	.L53
.L57:
	.loc 1 374 0
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	cmpq	-16(%rbp), %rax
	jbe	.L54
	.loc 1 375 0
	movq	-16(%rbp), %rax
	subq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)
.L54:
	.loc 1 378 0
	leaq	-40(%rbp), %rcx
	leaq	-48(%rbp), %rdx
	movq	-24(%rbp), %rsi
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	EApiAHI2CCCreateAddrOffset
	movl	%eax, -52(%rbp)
	.loc 1 379 0
	cmpl	$0, -52(%rbp)
	jne	.L62
	.loc 1 382 0
	movq	-32(%rbp), %rax
	movl	%eax, %r8d
	movq	-32(%rbp), %rax
	movl	%eax, %ecx
	.loc 1 386 0
	movq	-24(%rbp), %rax
	subq	-88(%rbp), %rax
	movq	%rax, %rdx
	.loc 1 382 0
	movq	-96(%rbp), %rax
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movl	%eax, %edi
	movq	-48(%rbp), %rax
	movl	%eax, %esi
	movl	-68(%rbp), %eax
	movl	%r8d, %r9d
	movl	%ecx, %r8d
	movq	%rdx, %rcx
	movl	%edi, %edx
	movl	%eax, %edi
	call	EApiI2CReadTransfer
	movl	%eax, -52(%rbp)
	.loc 1 390 0
	cmpl	$0, -52(%rbp)
	jne	.L63
	.loc 1 392 0
	movq	-32(%rbp), %rax
	addq	%rax, -24(%rbp)
.L53:
	.loc 1 371 0
	movq	-24(%rbp), %rax
	cmpq	-16(%rbp), %rax
	jb	.L57
	jmp	.L58
.L42:
.L61:
	.loc 1 360 0
	nop
	jmp	.L58
.L62:
	.loc 1 380 0
	nop
	jmp	.L58
.L63:
	.loc 1 391 0
	nop
.L58:
	.loc 1 398 0
	movl	-52(%rbp), %eax
	.loc 1 399 0
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L60
	call	__stack_chk_fail
.L60:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	EApiAHI2CReadEeprom, .-EApiAHI2CReadEeprom
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
	.file 3 "/usr/include/x86_64-linux-gnu/sys/types.h"
	.file 4 "/usr/include/stdint.h"
	.file 5 "../../../include/EApi.h"
	.file 6 "../../include/EApiAHI2C.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x43a
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF50
	.byte	0xc
	.long	.LASF51
	.long	.LASF52
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
	.byte	0xc2
	.long	0x5b
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF12
	.uleb128 0x2
	.long	.LASF13
	.byte	0x4
	.byte	0x30
	.long	0x4d
	.uleb128 0x2
	.long	.LASF14
	.byte	0x4
	.byte	0x31
	.long	0x54
	.uleb128 0x2
	.long	.LASF15
	.byte	0x4
	.byte	0x33
	.long	0x46
	.uleb128 0x2
	.long	.LASF16
	.byte	0x4
	.byte	0x7a
	.long	0x38
	.uleb128 0x2
	.long	.LASF17
	.byte	0x5
	.byte	0x93
	.long	0xaf
	.uleb128 0x2
	.long	.LASF18
	.byte	0x5
	.byte	0x94
	.long	0xaf
	.uleb128 0x6
	.long	.LASF53
	.byte	0x4
	.long	0x46
	.byte	0x6
	.byte	0x2d
	.long	0xf8
	.uleb128 0x7
	.long	.LASF19
	.byte	0x1
	.uleb128 0x7
	.long	.LASF20
	.byte	0x2
	.byte	0
	.uleb128 0x2
	.long	.LASF21
	.byte	0x6
	.byte	0x31
	.long	0xa4
	.uleb128 0x8
	.long	.LASF54
	.byte	0xc
	.byte	0x6
	.byte	0x33
	.long	0x14c
	.uleb128 0x9
	.long	.LASF22
	.byte	0x6
	.byte	0x34
	.long	0xa4
	.byte	0
	.uleb128 0x9
	.long	.LASF23
	.byte	0x6
	.byte	0x35
	.long	0xa4
	.byte	0x2
	.uleb128 0x9
	.long	.LASF24
	.byte	0x6
	.byte	0x36
	.long	0xf8
	.byte	0x4
	.uleb128 0x9
	.long	.LASF25
	.byte	0x6
	.byte	0x37
	.long	0xa4
	.byte	0x6
	.uleb128 0x9
	.long	.LASF26
	.byte	0x6
	.byte	0x38
	.long	0xaf
	.byte	0x8
	.byte	0
	.uleb128 0x2
	.long	.LASF27
	.byte	0x6
	.byte	0x39
	.long	0x103
	.uleb128 0xa
	.long	.LASF32
	.byte	0x1
	.byte	0x27
	.long	0xc5
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x1ce
	.uleb128 0xb
	.long	.LASF28
	.byte	0x1
	.byte	0x28
	.long	0x1d9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xb
	.long	.LASF29
	.byte	0x1
	.byte	0x29
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0xb
	.long	.LASF30
	.byte	0x1
	.byte	0x2a
	.long	0x1de
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xb
	.long	.LASF31
	.byte	0x1
	.byte	0x2b
	.long	0x1de
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0xc
	.long	.LASF34
	.byte	0x1
	.byte	0x2e
	.long	0xc5
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xd
	.long	.LASF47
	.byte	0x1
	.byte	0x57
	.quad	.L3
	.byte	0
	.uleb128 0xe
	.byte	0x8
	.long	0x1d4
	.uleb128 0xf
	.long	0x14c
	.uleb128 0xf
	.long	0x1ce
	.uleb128 0xe
	.byte	0x8
	.long	0x2d
	.uleb128 0x10
	.long	.LASF33
	.byte	0x1
	.byte	0x5b
	.long	0xc5
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x230
	.uleb128 0xb
	.long	.LASF28
	.byte	0x1
	.byte	0x5c
	.long	0x1d9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xc
	.long	.LASF34
	.byte	0x1
	.byte	0x5f
	.long	0xc5
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xc
	.long	.LASF35
	.byte	0x1
	.byte	0x60
	.long	0x3f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xa
	.long	.LASF36
	.byte	0x1
	.byte	0x77
	.long	0xc5
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x32f
	.uleb128 0x11
	.string	"Id"
	.byte	0x1
	.byte	0x78
	.long	0xd0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -84
	.uleb128 0xb
	.long	.LASF28
	.byte	0x1
	.byte	0x79
	.long	0x1d9
	.uleb128 0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0xb
	.long	.LASF37
	.byte	0x1
	.byte	0x7a
	.long	0x32f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -104
	.uleb128 0xb
	.long	.LASF38
	.byte	0x1
	.byte	0x7b
	.long	0x77
	.uleb128 0x3
	.byte	0x91
	.sleb128 -112
	.uleb128 0xb
	.long	.LASF39
	.byte	0x1
	.byte	0x7c
	.long	0x2d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -120
	.uleb128 0xc
	.long	.LASF34
	.byte	0x1
	.byte	0x7f
	.long	0xc5
	.uleb128 0x3
	.byte	0x91
	.sleb128 -76
	.uleb128 0xc
	.long	.LASF40
	.byte	0x1
	.byte	0x80
	.long	0xaf
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0xc
	.long	.LASF41
	.byte	0x1
	.byte	0x81
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xc
	.long	.LASF42
	.byte	0x1
	.byte	0x82
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xc
	.long	.LASF43
	.byte	0x1
	.byte	0x83
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xc
	.long	.LASF44
	.byte	0x1
	.byte	0x84
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0xc
	.long	.LASF45
	.byte	0x1
	.byte	0x85
	.long	0x2d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0xc
	.long	.LASF46
	.byte	0x1
	.byte	0x86
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x12
	.long	.LASF47
	.byte	0x1
	.value	0x124
	.quad	.L34
	.uleb128 0x12
	.long	.LASF48
	.byte	0x1
	.value	0x123
	.quad	.L17
	.byte	0
	.uleb128 0xf
	.long	0x2d
	.uleb128 0x13
	.long	.LASF55
	.byte	0x1
	.value	0x128
	.long	0xc5
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x14
	.string	"Id"
	.byte	0x1
	.value	0x129
	.long	0xd0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -84
	.uleb128 0x15
	.long	.LASF28
	.byte	0x1
	.value	0x12a
	.long	0x1d9
	.uleb128 0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0x15
	.long	.LASF37
	.byte	0x1
	.value	0x12b
	.long	0x32f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -104
	.uleb128 0x15
	.long	.LASF38
	.byte	0x1
	.value	0x12c
	.long	0x77
	.uleb128 0x3
	.byte	0x91
	.sleb128 -112
	.uleb128 0x15
	.long	.LASF49
	.byte	0x1
	.value	0x12d
	.long	0x32f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -120
	.uleb128 0x15
	.long	.LASF39
	.byte	0x1
	.value	0x12e
	.long	0x2d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -128
	.uleb128 0x16
	.long	.LASF34
	.byte	0x1
	.value	0x131
	.long	0xc5
	.uleb128 0x3
	.byte	0x91
	.sleb128 -68
	.uleb128 0x16
	.long	.LASF40
	.byte	0x1
	.value	0x132
	.long	0xaf
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x16
	.long	.LASF41
	.byte	0x1
	.value	0x133
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x16
	.long	.LASF42
	.byte	0x1
	.value	0x134
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x16
	.long	.LASF44
	.byte	0x1
	.value	0x135
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x16
	.long	.LASF45
	.byte	0x1
	.value	0x136
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x16
	.long	.LASF46
	.byte	0x1
	.value	0x137
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x12
	.long	.LASF47
	.byte	0x1
	.value	0x18d
	.quad	.L58
	.uleb128 0x12
	.long	.LASF48
	.byte	0x1
	.value	0x18c
	.quad	.L42
	.byte	0
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
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x8
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
	.uleb128 0x9
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
	.uleb128 0xa
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
	.uleb128 0xb
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
	.uleb128 0xc
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
	.uleb128 0xd
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
	.uleb128 0xe
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
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
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x5
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
	.uleb128 0x12
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
	.uleb128 0x13
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
	.byte	0
	.byte	0
	.uleb128 0x14
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
	.uleb128 0x15
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
	.uleb128 0x16
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
.LASF9:
	.string	"long long int"
.LASF28:
	.string	"pDDesc"
.LASF49:
	.string	"BufLength"
.LASF19:
	.string	"EApiAPI2CStdIndex"
.LASF10:
	.string	"size_t"
.LASF46:
	.string	"EncOffset"
.LASF17:
	.string	"EApiStatus_t"
.LASF26:
	.string	"DevSize"
.LASF55:
	.string	"EApiAHI2CReadEeprom"
.LASF20:
	.string	"EApiAPI2CExtIndex"
.LASF43:
	.string	"BlockLengthStd"
.LASF3:
	.string	"short unsigned int"
.LASF22:
	.string	"DeviceAddr"
.LASF32:
	.string	"EApiAHI2CCCreateAddrOffset"
.LASF31:
	.string	"pEncOffset"
.LASF39:
	.string	"ByteCnt"
.LASF11:
	.string	"int8_t"
.LASF50:
	.string	"GNU C11 5.2.1 20151010 -mtune=generic -march=x86-64 -g -O0 -fstack-protector-strong"
.LASF2:
	.string	"unsigned char"
.LASF42:
	.string	"BlockLength"
.LASF0:
	.string	"long unsigned int"
.LASF53:
	.string	"EApiCmdTypes_e"
.LASF27:
	.string	"I2CDeviceDesc_t"
.LASF16:
	.string	"uintptr_t"
.LASF45:
	.string	"EncAddr"
.LASF35:
	.string	"AddrCnt"
.LASF18:
	.string	"EApiId_t"
.LASF54:
	.string	"I2CDeviceDesc_s"
.LASF30:
	.string	"pEncAddr"
.LASF33:
	.string	"ValidEEPDevDesc"
.LASF21:
	.string	"EApiCmdTypes_t"
.LASF1:
	.string	"unsigned int"
.LASF51:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHI2C.c"
.LASF12:
	.string	"long long unsigned int"
.LASF13:
	.string	"uint8_t"
.LASF25:
	.string	"WRecTimems"
.LASF48:
	.string	"ErrorExit"
.LASF38:
	.string	"pBuffer"
.LASF40:
	.string	"IntMaxBlckLen"
.LASF7:
	.string	"sizetype"
.LASF29:
	.string	"Offset"
.LASF47:
	.string	"ExitPoint"
.LASF8:
	.string	"char"
.LASF23:
	.string	"PageSize"
.LASF44:
	.string	"CurOffset"
.LASF37:
	.string	"ByteOffset"
.LASF5:
	.string	"short int"
.LASF14:
	.string	"uint16_t"
.LASF24:
	.string	"ExtIndx"
.LASF15:
	.string	"uint32_t"
.LASF6:
	.string	"long int"
.LASF41:
	.string	"BlockEndAddress"
.LASF36:
	.string	"EApiAHI2CWriteEeprom"
.LASF4:
	.string	"signed char"
.LASF34:
	.string	"StatusCode"
.LASF52:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux"
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
