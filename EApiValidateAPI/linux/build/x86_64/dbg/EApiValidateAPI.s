	.file	"EApiValidateAPI.c"
	.text
.Ltext0:
	.comm	LogStream,8,8
	.section	.rodata
.LC0:
	.string	"%c%04i %-30s | "
.LC1:
	.string	"               0x%08X | "
.LC2:
	.string	"%-25s | "
	.text
	.globl	siFFormattedMessage_SC
	.type	siFFormattedMessage_SC, @function
siFFormattedMessage_SC:
.LFB2:
	.file 1 "/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../EApiValidateAPI.c"
	.loc 1 80 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$272, %rsp
	movq	%rdi, -232(%rbp)
	movq	%rdx, -248(%rbp)
	movq	%rcx, -256(%rbp)
	movl	%r8d, -240(%rbp)
	movl	%r9d, -260(%rbp)
	testb	%al, %al
	je	.L2
	movaps	%xmm0, -128(%rbp)
	movaps	%xmm1, -112(%rbp)
	movaps	%xmm2, -96(%rbp)
	movaps	%xmm3, -80(%rbp)
	movaps	%xmm4, -64(%rbp)
	movaps	%xmm5, -48(%rbp)
	movaps	%xmm6, -32(%rbp)
	movaps	%xmm7, -16(%rbp)
.L2:
	movb	%sil, -236(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, -272(%rbp)
	.loc 1 80 0
	movq	%fs:40, %rax
	movq	%rax, -184(%rbp)
	xorl	%eax, %eax
	.loc 1 85 0
	movl	$48, -208(%rbp)
	movl	$48, -204(%rbp)
	leaq	24(%rbp), %rax
	movq	%rax, -200(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, -192(%rbp)
	.loc 1 86 0
	movl	-260(%rbp), %edx
	leaq	-216(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	EApiGetErrorStringA
	.loc 1 87 0
	movsbl	-236(%rbp), %edx
	movq	-256(%rbp), %rsi
	movl	-240(%rbp), %ecx
	movq	-232(%rbp), %rax
	movq	%rsi, %r8
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	%eax, -220(%rbp)
	.loc 1 94 0
	movq	-216(%rbp), %rax
	testq	%rax, %rax
	jne	.L3
	.loc 1 95 0
	movl	-260(%rbp), %edx
	movq	-232(%rbp), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	jmp	.L4
.L3:
	.loc 1 97 0
	movq	-216(%rbp), %rdx
	movq	-232(%rbp), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L4:
	.loc 1 99 0
	leaq	-208(%rbp), %rdx
	movq	-272(%rbp), %rcx
	movq	-232(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	vfprintf
	addl	%eax, -220(%rbp)
	.loc 1 101 0
	movl	-220(%rbp), %eax
	.loc 1 102 0
	movq	-184(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L6
	call	__stack_chk_fail
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	siFFormattedMessage_SC, .-siFFormattedMessage_SC
	.globl	Buffer
	.bss
	.align 32
	.type	Buffer, @object
	.size	Buffer, 1024
Buffer:
	.zero	1024
	.globl	BufPtrLen
	.data
	.align 4
	.type	BufPtrLen, @object
	.size	BufPtrLen, 4
BufPtrLen:
	.long	1024
	.globl	FailPass
	.section	.rodata
.LC3:
	.string	"FAIL"
.LC4:
	.string	"PASS"
	.data
	.align 16
	.type	FailPass, @object
	.size	FailPass, 16
FailPass:
	.quad	.LC3
	.quad	.LC4
	.globl	EApiStrings
	.section	.rodata
.LC5:
	.string	"Manufacturer"
.LC6:
	.string	"Board Name"
.LC7:
	.string	"Board Serial Number"
.LC8:
	.string	"Bios Revision"
.LC9:
	.string	"Platform Type"
.LC10:
	.string	"HW Revision"
.LC11:
	.string	"Board Revision"
.LC12:
	.string	"Manufacturing Date"
	.align 32
	.type	EApiStrings, @object
	.size	EApiStrings, 128
EApiStrings:
	.long	0
	.zero	4
	.quad	.LC5
	.long	1
	.zero	4
	.quad	.LC6
	.long	3
	.zero	4
	.quad	.LC7
	.long	4
	.zero	4
	.quad	.LC8
	.long	6
	.zero	4
	.quad	.LC9
	.long	5
	.zero	4
	.quad	.LC10
	.long	2
	.zero	4
	.quad	.LC11
	.long	-84865024
	.zero	4
	.quad	.LC12
.LC13:
	.string	"%-30s : %s\n"
	.align 8
.LC14:
	.string	"%-30s : EAPI_STATUS_UNSUPPORTED\n"
	.text
	.globl	EApiValidateStringApi
	.type	EApiValidateStringApi, @function
EApiValidateStringApi:
.LFB3:
	.loc 1 169 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	.loc 1 169 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 174 0
	movl	$100, -28(%rbp)
	.loc 1 175 0
	movl	-28(%rbp), %eax
	movl	%eax, %eax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -16(%rbp)
	.loc 1 177 0
	movl	$10, %edi
	call	putchar
.LBB2:
	.loc 1 178 0
	movl	$0, -24(%rbp)
	jmp	.L8
.L11:
	.loc 1 179 0
	movl	$100, -28(%rbp)
	.loc 1 180 0
	movl	-24(%rbp), %eax
	salq	$4, %rax
	addq	$EApiStrings, %rax
	movl	(%rax), %eax
	leaq	-28(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiBoardGetStringA
	movl	%eax, -20(%rbp)
	.loc 1 181 0
	cmpl	$0, -20(%rbp)
	jne	.L9
	.loc 1 183 0
	movl	-24(%rbp), %eax
	salq	$4, %rax
	addq	$EApiStrings+8, %rax
	movq	(%rax), %rax
	movq	-16(%rbp), %rdx
	movq	%rax, %rsi
	movl	$.LC13, %edi
	movl	$0, %eax
	call	printf
	jmp	.L10
.L9:
	.loc 1 190 0
	movl	-24(%rbp), %eax
	salq	$4, %rax
	addq	$EApiStrings+8, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	printf
.L10:
	.loc 1 178 0 discriminator 2
	addl	$1, -24(%rbp)
.L8:
	.loc 1 178 0 is_stmt 0 discriminator 1
	cmpl	$7, -24(%rbp)
	jbe	.L11
.LBE2:
	.loc 1 195 0 is_stmt 1
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free
	.loc 1 196 0
	nop
	.loc 1 197 0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L13
	call	__stack_chk_fail
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	EApiValidateStringApi, .-EApiValidateStringApi
	.globl	EApiValues
	.section	.rodata
.LC15:
	.string	"EApi Spec Version"
.LC16:
	.string	"Boot Counter"
.LC17:
	.string	"Running Time Meter"
.LC18:
	.string	"Manufacturer PNP ID"
.LC19:
	.string	"Platform Revision"
.LC20:
	.string	"CPU Temperature"
.LC21:
	.string	"Chipset Temperature"
.LC22:
	.string	"System Temperature"
.LC23:
	.string	"Cpu Fan"
.LC24:
	.string	"System Fan"
.LC25:
	.string	"VCORE"
.LC26:
	.string	"2.5V"
.LC27:
	.string	"3.3V"
.LC28:
	.string	"VBAT"
.LC29:
	.string	"5V"
.LC30:
	.string	"5VSB"
.LC31:
	.string	"12V"
	.align 32
	.type	EApiValues, @object
	.size	EApiValues, 408
EApiValues:
	.long	0
	.zero	4
	.quad	.LC15
	.quad	EApiAHCreateSVersionString
	.long	1
	.zero	4
	.quad	.LC16
	.quad	EApiAHCreateDecimalString
	.long	2
	.zero	4
	.quad	.LC17
	.quad	EApiAHCreateTimeString
	.long	3
	.zero	4
	.quad	.LC18
	.quad	EApiAHCreatePNPIDString
	.long	4
	.zero	4
	.quad	.LC19
	.quad	EApiAHCreateSVersionString
	.long	131072
	.zero	4
	.quad	.LC20
	.quad	EApiAHCreateTempString
	.long	131073
	.zero	4
	.quad	.LC21
	.quad	EApiAHCreateTempString
	.long	131074
	.zero	4
	.quad	.LC22
	.quad	EApiAHCreateTempString
	.long	139264
	.zero	4
	.quad	.LC23
	.quad	EApiAHCreateRotationsString
	.long	139265
	.zero	4
	.quad	.LC24
	.quad	EApiAHCreateRotationsString
	.long	135172
	.zero	4
	.quad	.LC25
	.quad	EApiAHCreateVoltageString
	.long	135176
	.zero	4
	.quad	.LC26
	.quad	EApiAHCreateVoltageString
	.long	135180
	.zero	4
	.quad	.LC27
	.quad	EApiAHCreateVoltageString
	.long	135184
	.zero	4
	.quad	.LC28
	.quad	EApiAHCreateVoltageString
	.long	135188
	.zero	4
	.quad	.LC29
	.quad	EApiAHCreateVoltageString
	.long	135192
	.zero	4
	.quad	.LC30
	.quad	EApiAHCreateVoltageString
	.long	135196
	.zero	4
	.quad	.LC31
	.quad	EApiAHCreateVoltageString
	.text
	.globl	EApiValidateValuesApi
	.type	EApiValidateValuesApi, @function
EApiValidateValuesApi:
.LFB4:
	.loc 1 274 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1056, %rsp
	.loc 1 274 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 282 0
	movl	$10, %edi
	call	putchar
	.loc 1 284 0
	movl	$0, -1048(%rbp)
	jmp	.L15
.L18:
	.loc 1 285 0
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiValues, %rax
	movl	(%rax), %eax
	leaq	-1052(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	EApiBoardGetValue
	movl	%eax, -1044(%rbp)
	cmpl	$0, -1044(%rbp)
	jne	.L16
	.loc 1 287 0
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiValues+16, %rax
	movq	(%rax), %rax
	movl	-1052(%rbp), %ecx
	leaq	-1040(%rbp), %rsi
	movl	$1024, %edx
	movl	%ecx, %edi
	call	*%rax
	.loc 1 288 0
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiValues+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rax, %rsi
	movl	$.LC13, %edi
	movl	$0, %eax
	call	printf
	jmp	.L17
.L16:
	.loc 1 290 0
	leaq	-1040(%rbp), %rcx
	movl	-1044(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	.loc 1 291 0
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiValues+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rax, %rsi
	movl	$.LC13, %edi
	movl	$0, %eax
	call	printf
.L17:
	.loc 1 284 0 discriminator 2
	addl	$1, -1048(%rbp)
.L15:
	.loc 1 284 0 is_stmt 0 discriminator 1
	cmpl	$16, -1048(%rbp)
	jbe	.L18
	.loc 1 305 0 is_stmt 1
	nop
	.loc 1 306 0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L20
	call	__stack_chk_fail
.L20:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	EApiValidateValuesApi, .-EApiValidateValuesApi
	.globl	EApiI2CLLValidate
	.section	.rodata
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
	.globl	EApiI2CHLWriteValidate
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
	.globl	I2CMaxClk
	.bss
	.align 4
	.type	I2CMaxClk, @object
	.size	I2CMaxClk, 4
I2CMaxClk:
	.zero	4
	.globl	EApiI2CInterfaceValidate
	.section	.rodata
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
	.globl	EApiI2CBuses
.LC32:
	.string	"External I2C"
.LC33:
	.string	"LVDS 1 I2C/DDC"
.LC34:
	.string	"LVDS 2 I2C/DDC"
.LC35:
	.string	"Unsupported"
	.align 32
	.type	EApiI2CBuses, @object
	.size	EApiI2CBuses, 64
EApiI2CBuses:
	.long	0
	.zero	4
	.quad	.LC32
	.long	1
	.zero	4
	.quad	.LC33
	.long	2
	.zero	4
	.quad	.LC34
	.long	3840
	.zero	4
	.quad	.LC35
.LC36:
	.string	"%02X"
	.text
	.globl	printHex
	.type	printHex, @function
printHex:
.LFB5:
	.loc 1 398 0
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
	.loc 1 399 0
	jmp	.L22
.L23:
	.loc 1 400 0
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movq	-8(%rbp), %rax
	movl	$.LC36, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	.loc 1 401 0
	addq	$1, -16(%rbp)
.L22:
	.loc 1 399 0
	movq	-24(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	%rdx, -24(%rbp)
	testq	%rax, %rax
	jne	.L23
	.loc 1 403 0
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	printHex, .-printHex
	.section	.rodata
.LC37:
	.string	"%x  "
.LC38:
	.string	"Reyyyy in ke error e "
.LC39:
	.string	"Reyyyy that is wunderbar"
.LC40:
	.string	"Reyyyy that is an error"
	.text
	.globl	EApiValidateI2CApi
	.type	EApiValidateI2CApi, @function
EApiValidateI2CApi:
.LFB6:
	.loc 1 405 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$176, %rsp
	.loc 1 405 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 415 0
	leaq	-80(%rbp), %rax
	movl	$64, %r9d
	movl	$64, %r8d
	movq	%rax, %rcx
	movl	$-2147483648, %edx
	movl	$80, %esi
	movl	$11, %edi
	call	EApiI2CReadTransfer
	movl	%eax, -136(%rbp)
	.loc 1 423 0
	cmpl	$0, -136(%rbp)
	jne	.L25
.LBB3:
	.loc 1 425 0
	movl	$0, -164(%rbp)
.LBB4:
	.loc 1 426 0
	movl	$0, -160(%rbp)
	jmp	.L26
.L29:
	.loc 1 427 0
	movl	-164(%rbp), %eax
	andl	$15, %eax
	testl	%eax, %eax
	jne	.L27
	.loc 1 428 0
	movl	$10, %edi
	call	putchar
	jmp	.L28
.L27:
	.loc 1 429 0
	movl	-164(%rbp), %eax
	andl	$7, %eax
	testl	%eax, %eax
	jne	.L28
	.loc 1 430 0
	movl	$32, %edi
	call	putchar
.L28:
	.loc 1 431 0 discriminator 2
	addl	$1, -164(%rbp)
	.loc 1 433 0 discriminator 2
	movl	-160(%rbp), %eax
	cltq
	movzbl	-80(%rbp,%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$.LC37, %edi
	movl	$0, %eax
	call	printf
	.loc 1 426 0 discriminator 2
	addl	$1, -160(%rbp)
.L26:
	.loc 1 426 0 is_stmt 0 discriminator 1
	cmpl	$63, -160(%rbp)
	jle	.L29
.LBE4:
	.loc 1 436 0 is_stmt 1
	movl	$10, %edi
	call	putchar
.LBE3:
	jmp	.L30
.L25:
	.loc 1 439 0
	movl	$.LC38, %edi
	call	puts
.L30:
.LBB5:
	.loc 1 445 0
	movl	$0, -156(%rbp)
	jmp	.L31
.L36:
	.loc 1 446 0
	movl	-156(%rbp), %eax
	movzbl	%al, %eax
	leaq	-129(%rbp), %rdx
	movl	$1, %r9d
	movl	$1, %r8d
	movq	%rdx, %rcx
	movl	%eax, %edx
	movl	$39, %esi
	movl	$11, %edi
	call	EApiI2CReadTransfer
	movl	%eax, -136(%rbp)
	.loc 1 454 0
	cmpl	$0, -136(%rbp)
	jne	.L32
.LBB6:
	.loc 1 456 0
	movl	$0, -152(%rbp)
	jmp	.L33
.L34:
	.loc 1 457 0 discriminator 3
	movl	-152(%rbp), %eax
	cltq
	movzbl	-129(%rbp,%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$.LC37, %edi
	movl	$0, %eax
	call	printf
	.loc 1 456 0 discriminator 3
	addl	$1, -152(%rbp)
.L33:
	.loc 1 456 0 is_stmt 0 discriminator 1
	cmpl	$0, -152(%rbp)
	jle	.L34
.LBE6:
	.loc 1 459 0 is_stmt 1
	movl	$10, %edi
	call	putchar
	jmp	.L35
.L32:
	.loc 1 462 0
	movl	$.LC38, %edi
	call	puts
.L35:
	.loc 1 445 0 discriminator 2
	addl	$1, -156(%rbp)
.L31:
	.loc 1 445 0 is_stmt 0 discriminator 1
	cmpl	$7, -156(%rbp)
	jle	.L36
.LBE5:
.LBB7:
	.loc 1 468 0 is_stmt 1
	movl	$0, -148(%rbp)
	jmp	.L37
.L38:
	.loc 1 469 0 discriminator 3
	movl	-148(%rbp), %eax
	movl	%eax, %edx
	movl	-148(%rbp), %eax
	cltq
	movb	%dl, -128(%rbp,%rax)
	.loc 1 468 0 discriminator 3
	addl	$1, -148(%rbp)
.L37:
	.loc 1 468 0 is_stmt 0 discriminator 1
	cmpl	$9, -148(%rbp)
	jle	.L38
.LBE7:
.LBB8:
	.loc 1 471 0 is_stmt 1
	movl	$0, -144(%rbp)
	jmp	.L39
.L42:
	.loc 1 477 0
	leaq	-128(%rbp), %rdx
	movl	-144(%rbp), %eax
	cltq
	addq	%rdx, %rax
	.loc 1 473 0
	movl	$1, %r8d
	movq	%rax, %rcx
	movl	$2, %edx
	movl	$39, %esi
	movl	$11, %edi
	call	EApiI2CWriteTransfer
	movl	%eax, -136(%rbp)
	.loc 1 480 0
	cmpl	$0, -136(%rbp)
	jne	.L40
	.loc 1 481 0
	movl	$.LC39, %edi
	call	puts
	jmp	.L41
.L40:
	.loc 1 483 0
	movl	$.LC40, %edi
	call	puts
.L41:
	.loc 1 485 0 discriminator 2
	movl	$5, %edi
	call	sleep
	.loc 1 471 0 discriminator 2
	addl	$1, -144(%rbp)
.L39:
	.loc 1 471 0 is_stmt 0 discriminator 1
	cmpl	$9, -144(%rbp)
	jle	.L42
.LBE8:
	.loc 1 493 0 is_stmt 1
	movb	$0, -112(%rbp)
	.loc 1 494 0
	movb	$51, -111(%rbp)
	.loc 1 495 0
	movb	$80, -110(%rbp)
	.loc 1 496 0
	movb	$16, -109(%rbp)
	.loc 1 497 0
	movb	$9, -108(%rbp)
	.loc 1 498 0
	movb	$116, -107(%rbp)
	.loc 1 499 0
	movb	$99, -106(%rbp)
	.loc 1 500 0
	movb	$111, -105(%rbp)
	.loc 1 501 0
	movb	$77, -104(%rbp)
	.loc 1 502 0
	movb	$48, -103(%rbp)
	.loc 1 503 0
	movb	$17, -102(%rbp)
	.loc 1 504 0
	movb	$-81, -101(%rbp)
	.loc 1 505 0
	movb	$0, -100(%rbp)
	.loc 1 506 0
	movb	$0, -99(%rbp)
	.loc 1 507 0
	movb	$0, -98(%rbp)
	.loc 1 509 0
	movb	$1, -97(%rbp)
	.loc 1 510 0
	movb	$6, -96(%rbp)
	.loc 1 511 0
	movb	$33, -95(%rbp)
	.loc 1 512 0
	movb	$-48, -94(%rbp)
	.loc 1 513 0
	movb	$0, -93(%rbp)
	.loc 1 514 0
	movb	$32, -92(%rbp)
	.loc 1 515 0
	movb	$2, -91(%rbp)
	.loc 1 516 0
	movb	$15, -90(%rbp)
	.loc 1 517 0
	movb	$-32, -89(%rbp)
	.loc 1 518 0
	movb	$0, -88(%rbp)
	.loc 1 519 0
	movb	$1, -87(%rbp)
	.loc 1 520 0
	movb	$2, -86(%rbp)
	.loc 1 521 0
	movb	$3, -85(%rbp)
	.loc 1 522 0
	movb	$4, -84(%rbp)
	.loc 1 523 0
	movb	$0, -83(%rbp)
	.loc 1 524 0
	movb	$8, -82(%rbp)
	.loc 1 525 0
	movb	$0, -81(%rbp)
.LBB9:
	.loc 1 530 0
	movl	$0, -140(%rbp)
	jmp	.L43
.L46:
	.loc 1 536 0
	leaq	-112(%rbp), %rdx
	movl	-140(%rbp), %eax
	cltq
	addq	%rax, %rdx
	.loc 1 532 0
	movl	-140(%rbp), %eax
	movzwl	%ax, %eax
	orl	$-2147483648, %eax
	movl	$1, %r8d
	movq	%rdx, %rcx
	movl	%eax, %edx
	movl	$80, %esi
	movl	$11, %edi
	call	EApiI2CWriteTransfer
	movl	%eax, -136(%rbp)
	.loc 1 539 0
	cmpl	$0, -136(%rbp)
	jne	.L44
	.loc 1 540 0
	movl	$.LC39, %edi
	call	puts
	jmp	.L45
.L44:
	.loc 1 542 0
	movl	$.LC40, %edi
	call	puts
.L45:
	.loc 1 543 0 discriminator 2
	movl	$1, %edi
	call	sleep
	.loc 1 530 0 discriminator 2
	addl	$1, -140(%rbp)
.L43:
	.loc 1 530 0 is_stmt 0 discriminator 1
	cmpl	$31, -140(%rbp)
	jle	.L46
.LBE9:
	.loc 1 546 0 is_stmt 1
	nop
	.loc 1 610 0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L48
	call	__stack_chk_fail
.L48:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	EApiValidateI2CApi, .-EApiValidateI2CApi
	.globl	EApiStorageDevices
	.section	.rodata
.LC41:
	.string	"Standard Storage"
.LC42:
	.string	"Dummy PICMG Storage"
	.align 32
	.type	EApiStorageDevices, @object
	.size	EApiStorageDevices, 72
EApiStorageDevices:
	.long	0
	.zero	4
	.quad	.LC41
	.long	32
	.zero	4
	.long	-93057024
	.zero	4
	.quad	.LC42
	.long	128
	.zero	4
	.long	3840
	.zero	4
	.quad	.LC35
	.long	32
	.zero	4
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
	.comm	StorageSize,4,4
	.comm	BlockLength,4,4
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
.LC43:
	.string	"%-30s : "
.LC44:
	.string	"%-30s : %02X %s\n"
.LC45:
	.string	"EApiStorageAreaRead"
	.align 8
.LC46:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../EApiValidateAPI.c"
.LC47:
	.string	"   %2d    %2d    [%s]\n"
.LC48:
	.string	"EApiStorageAreaWrite"
.LC49:
	.string	"EApiStorageCap"
	.text
	.globl	EApiValidateStorageApi
	.type	EApiValidateStorageApi, @function
EApiValidateStorageApi:
.LFB7:
	.loc 1 661 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1056, %rsp
	.loc 1 661 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 666 0
	movl	$0, -1052(%rbp)
	jmp	.L50
.L55:
	.loc 1 667 0
	movl	-1052(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiStorageDevices+16, %rax
	movl	(%rax), %ecx
	movl	-1052(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiStorageDevices, %rax
	movl	(%rax), %eax
	leaq	-1040(%rbp), %rdx
	movl	%ecx, %r8d
	movl	$1024, %ecx
	movl	$0, %esi
	movl	%eax, %edi
	call	EApiStorageAreaRead
	movl	%eax, -1044(%rbp)
	.loc 1 674 0
	cmpl	$0, -1044(%rbp)
	jne	.L51
	.loc 1 676 0
	movl	-1052(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiStorageDevices+8, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC43, %edi
	movl	$0, %eax
	call	printf
	.loc 1 680 0
	movq	stdout(%rip), %rax
	leaq	-1040(%rbp), %rcx
	movl	$16, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	printHex
	.loc 1 681 0
	movl	$10, %edi
	call	putchar
	.loc 1 687 0
	movl	-1052(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiStorageDevices+16, %rax
	movl	(%rax), %eax
	.loc 1 683 0
	movl	$-858993459, %edx
	mull	%edx
	movl	%edx, %ecx
	shrl	$2, %ecx
	movl	-1052(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiStorageDevices, %rax
	movl	(%rax), %eax
	leaq	-1040(%rbp), %rdx
	movl	$13, %esi
	movl	%eax, %edi
	call	EApiAHWriteStorage
	movl	%eax, -1044(%rbp)
	.loc 1 689 0
	cmpl	$0, -1044(%rbp)
	jne	.L52
	.loc 1 691 0
	movl	-1052(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiStorageDevices+8, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC43, %edi
	movl	$0, %eax
	call	printf
	.loc 1 695 0
	movq	stdout(%rip), %rax
	leaq	-1040(%rbp), %rcx
	movl	$16, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	printHex
	.loc 1 696 0
	movl	$10, %edi
	call	putchar
	jmp	.L54
.L52:
	.loc 1 700 0
	leaq	-1040(%rbp), %rcx
	movl	-1044(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	.loc 1 704 0
	movl	-1052(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	$I2CDevices, %rax
	movzwl	(%rax), %eax
	.loc 1 701 0
	movzwl	%ax, %esi
	movl	-1052(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiStorageDevices+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rdx, %rcx
	movl	%esi, %edx
	movq	%rax, %rsi
	movl	$.LC44, %edi
	movl	$0, %eax
	call	printf
	jmp	.L54
.L51:
	.loc 1 712 0
	leaq	-1040(%rbp), %rcx
	movl	-1044(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	.loc 1 713 0
	movl	-1052(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$EApiStorageDevices+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rax, %rsi
	movl	$.LC13, %edi
	movl	$0, %eax
	call	printf
.L54:
	.loc 1 666 0 discriminator 2
	addl	$1, -1052(%rbp)
.L50:
	.loc 1 666 0 is_stmt 0 discriminator 1
	cmpl	$2, -1052(%rbp)
	jbe	.L55
	.loc 1 719 0 is_stmt 1
	movl	$0, -1052(%rbp)
	jmp	.L56
.L65:
	.loc 1 721 0
	movl	$0, -1048(%rbp)
	jmp	.L57
.L64:
	.loc 1 723 0
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+20, %rax
	movl	(%rax), %r8d
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+16, %rax
	movl	(%rax), %ecx
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+8, %rax
	movq	(%rax), %rdi
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate, %rax
	movl	(%rax), %esi
	movl	-1052(%rbp), %eax
	movq	%rdi, %rdx
	movl	%eax, %edi
	call	EApiStorageAreaRead
	movl	%eax, -1044(%rbp)
	.loc 1 730 0
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+24, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	je	.L58
	.loc 1 730 0 is_stmt 0 discriminator 2
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+28, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	je	.L58
	.loc 1 730 0 discriminator 4
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+32, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	jne	.L59
.L58:
	.loc 1 730 0 discriminator 5
	movl	$1, %eax
	jmp	.L60
.L59:
	.loc 1 730 0 discriminator 6
	movl	$0, %eax
.L60:
	.loc 1 730 0 discriminator 8
	cltq
	movq	FailPass(,%rax,8), %rdx
	movq	LogStream(%rip), %rax
	movl	-1044(%rbp), %ecx
	pushq	%rdx
	movl	-1048(%rbp), %edx
	pushq	%rdx
	movl	-1052(%rbp), %edx
	pushq	%rdx
	pushq	$.LC47
	movl	%ecx, %r9d
	movl	$730, %r8d
	movl	$.LC45, %ecx
	movl	$.LC46, %edx
	movl	$76, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	siFFormattedMessage_SC
	addq	$32, %rsp
	.loc 1 732 0 is_stmt 1 discriminator 8
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+20, %rax
	movl	(%rax), %ecx
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+8, %rax
	movq	(%rax), %rdi
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate, %rax
	movl	(%rax), %esi
	movl	-1052(%rbp), %eax
	movq	%rdi, %rdx
	movl	%eax, %edi
	call	EApiStorageAreaWrite
	movl	%eax, -1044(%rbp)
	.loc 1 738 0 discriminator 8
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+24, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	je	.L61
	.loc 1 738 0 is_stmt 0 discriminator 2
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+28, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	je	.L61
	.loc 1 738 0 discriminator 4
	movl	-1048(%rbp), %edx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$StorageValidate+32, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	jne	.L62
.L61:
	.loc 1 738 0 discriminator 5
	movl	$1, %eax
	jmp	.L63
.L62:
	.loc 1 738 0 discriminator 6
	movl	$0, %eax
.L63:
	.loc 1 738 0 discriminator 8
	cltq
	movq	FailPass(,%rax,8), %rdx
	movq	LogStream(%rip), %rax
	movl	-1044(%rbp), %ecx
	pushq	%rdx
	movl	-1048(%rbp), %edx
	pushq	%rdx
	movl	-1052(%rbp), %edx
	pushq	%rdx
	pushq	$.LC47
	movl	%ecx, %r9d
	movl	$738, %r8d
	movl	$.LC48, %ecx
	movl	$.LC46, %edx
	movl	$76, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	siFFormattedMessage_SC
	addq	$32, %rsp
	.loc 1 721 0 is_stmt 1 discriminator 8
	addl	$1, -1048(%rbp)
.L57:
	.loc 1 721 0 is_stmt 0 discriminator 2
	cmpl	$5, -1048(%rbp)
	jbe	.L64
	.loc 1 719 0 is_stmt 1 discriminator 2
	addl	$1, -1052(%rbp)
.L56:
	.loc 1 719 0 is_stmt 0 discriminator 1
	cmpl	$9, -1052(%rbp)
	jbe	.L65
	.loc 1 742 0 is_stmt 1
	movl	$0, -1052(%rbp)
	jmp	.L66
.L72:
	.loc 1 744 0
	movl	$0, -1048(%rbp)
	jmp	.L67
.L71:
	.loc 1 746 0
	movl	-1048(%rbp), %eax
	salq	$5, %rax
	addq	$StorageCapValidate+8, %rax
	movq	(%rax), %rdx
	movl	-1048(%rbp), %eax
	salq	$5, %rax
	addq	$StorageCapValidate, %rax
	movq	(%rax), %rcx
	movl	-1052(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiStorageCap
	movl	%eax, -1044(%rbp)
	.loc 1 751 0
	movl	-1048(%rbp), %eax
	salq	$5, %rax
	addq	$StorageCapValidate+16, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	je	.L68
	.loc 1 751 0 is_stmt 0 discriminator 2
	movl	-1048(%rbp), %eax
	salq	$5, %rax
	addq	$StorageCapValidate+20, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	je	.L68
	.loc 1 751 0 discriminator 4
	movl	-1048(%rbp), %eax
	salq	$5, %rax
	addq	$StorageCapValidate+24, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	jne	.L69
.L68:
	.loc 1 751 0 discriminator 5
	movl	$1, %eax
	jmp	.L70
.L69:
	.loc 1 751 0 discriminator 6
	movl	$0, %eax
.L70:
	.loc 1 751 0 discriminator 8
	cltq
	movq	FailPass(,%rax,8), %rdx
	movq	LogStream(%rip), %rax
	movl	-1044(%rbp), %ecx
	pushq	%rdx
	movl	-1048(%rbp), %edx
	pushq	%rdx
	movl	-1052(%rbp), %edx
	pushq	%rdx
	pushq	$.LC47
	movl	%ecx, %r9d
	movl	$751, %r8d
	movl	$.LC49, %ecx
	movl	$.LC46, %edx
	movl	$76, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	siFFormattedMessage_SC
	addq	$32, %rsp
	.loc 1 744 0 is_stmt 1 discriminator 8
	addl	$1, -1048(%rbp)
.L67:
	.loc 1 744 0 is_stmt 0 discriminator 2
	cmpl	$3, -1048(%rbp)
	jbe	.L71
	.loc 1 742 0 is_stmt 1 discriminator 2
	addl	$1, -1052(%rbp)
.L66:
	.loc 1 742 0 is_stmt 0 discriminator 1
	cmpl	$9, -1052(%rbp)
	jbe	.L72
	.loc 1 754 0 is_stmt 1
	nop
	.loc 1 755 0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L74
	call	__stack_chk_fail
.L74:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	EApiValidateStorageApi, .-EApiValidateStorageApi
	.comm	GpioInputs,4,4
	.comm	GpioOutputs,4,4
	.globl	EApiGpioterfaceValidate
	.section	.rodata
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
	.globl	EApiGpioDevices
.LC50:
	.string	"GPIO Bank0"
.LC51:
	.string	"GPIO GPIO0"
.LC52:
	.string	"GPIO GPIO1"
.LC53:
	.string	"GPIO GPIO2"
.LC54:
	.string	"GPIO GPIO3"
.LC55:
	.string	"GPIO GPIO4"
.LC56:
	.string	"GPIO GPIO5"
.LC57:
	.string	"GPIO GPIO6"
.LC58:
	.string	"GPIO GPIO7"
.LC59:
	.string	"GPIO GPIO8"
.LC60:
	.string	"GPIO GPIO9"
	.align 32
	.type	EApiGpioDevices, @object
	.size	EApiGpioDevices, 192
EApiGpioDevices:
	.long	65536
	.zero	4
	.quad	.LC50
	.long	0
	.zero	4
	.quad	.LC51
	.long	1
	.zero	4
	.quad	.LC52
	.long	2
	.zero	4
	.quad	.LC53
	.long	3
	.zero	4
	.quad	.LC54
	.long	4
	.zero	4
	.quad	.LC55
	.long	5
	.zero	4
	.quad	.LC56
	.long	6
	.zero	4
	.quad	.LC57
	.long	7
	.zero	4
	.quad	.LC58
	.long	8
	.zero	4
	.quad	.LC59
	.long	9
	.zero	4
	.quad	.LC60
	.long	3840
	.zero	4
	.quad	.LC35
.LC61:
	.string	"EApiGPIOGetDirectionCaps"
.LC62:
	.string	"%-15s %-25s : %s\n"
	.align 8
.LC63:
	.string	"%-15s %-25s : Inputs   =%08X Outputs=%08X\n"
.LC64:
	.string	"EApiGPIOGetDirection"
.LC65:
	.string	"%-15s %-25s : Direction=%08X\n"
.LC66:
	.string	"EApiGPIOGetLevel"
.LC67:
	.string	"%-15s %-25s : Level    =%08X\n"
.LC68:
	.string	"EApiGPIOSetDirection"
.LC69:
	.string	"EApiGPIOSetLevel"
	.text
	.globl	EApiValidateGPIOApi
	.type	EApiValidateGPIOApi, @function
EApiValidateGPIOApi:
.LFB8:
	.loc 1 800 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1072, %rsp
	.loc 1 800 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 808 0
	movl	$0, -1052(%rbp)
	jmp	.L76
.L85:
	.loc 1 810 0
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices, %rax
	movl	(%rax), %eax
	leaq	-1056(%rbp), %rdx
	leaq	-1060(%rbp), %rcx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiGPIOGetDirectionCaps
	movl	%eax, -1044(%rbp)
	.loc 1 811 0
	cmpl	$0, -1044(%rbp)
	je	.L77
	.loc 1 813 0
	leaq	-1040(%rbp), %rcx
	movl	-1044(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	.loc 1 814 0
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rdx, %rcx
	movl	$.LC61, %edx
	movq	%rax, %rsi
	movl	$.LC62, %edi
	movl	$0, %eax
	call	printf
	.loc 1 820 0
	jmp	.L78
.L77:
	.loc 1 822 0
	movl	-1056(%rbp), %ecx
	movl	-1060(%rbp), %edx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	$.LC61, %edx
	movq	%rax, %rsi
	movl	$.LC63, %edi
	movl	$0, %eax
	call	printf
	.loc 1 829 0
	movl	-1060(%rbp), %edx
	movl	-1056(%rbp), %eax
	movl	%edx, %ecx
	orl	%eax, %ecx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices, %rax
	movl	(%rax), %eax
	leaq	-1068(%rbp), %rdx
	movl	%ecx, %esi
	movl	%eax, %edi
	call	EApiGPIOGetDirection
	movl	%eax, -1044(%rbp)
	.loc 1 830 0
	cmpl	$0, -1044(%rbp)
	je	.L79
	.loc 1 832 0
	leaq	-1040(%rbp), %rcx
	movl	-1044(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	.loc 1 833 0
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rdx, %rcx
	movl	$.LC64, %edx
	movq	%rax, %rsi
	movl	$.LC62, %edi
	movl	$0, %eax
	call	printf
	.loc 1 839 0
	jmp	.L78
.L79:
	.loc 1 841 0
	movl	-1068(%rbp), %edx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	movl	%edx, %ecx
	movl	$.LC64, %edx
	movq	%rax, %rsi
	movl	$.LC65, %edi
	movl	$0, %eax
	call	printf
	.loc 1 847 0
	movl	-1060(%rbp), %edx
	movl	-1056(%rbp), %eax
	movl	%edx, %ecx
	orl	%eax, %ecx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices, %rax
	movl	(%rax), %eax
	leaq	-1064(%rbp), %rdx
	movl	%ecx, %esi
	movl	%eax, %edi
	call	EApiGPIOGetLevel
	movl	%eax, -1044(%rbp)
	.loc 1 848 0
	cmpl	$0, -1044(%rbp)
	je	.L80
	.loc 1 850 0
	leaq	-1040(%rbp), %rcx
	movl	-1044(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	.loc 1 851 0
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rdx, %rcx
	movl	$.LC66, %edx
	movq	%rax, %rsi
	movl	$.LC62, %edi
	movl	$0, %eax
	call	printf
	.loc 1 857 0
	jmp	.L78
.L80:
	.loc 1 859 0
	movl	-1064(%rbp), %edx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	movl	%edx, %ecx
	movl	$.LC66, %edx
	movq	%rax, %rsi
	movl	$.LC67, %edi
	movl	$0, %eax
	call	printf
	.loc 1 865 0
	movl	-1060(%rbp), %eax
	movzwl	%ax, %edx
	movl	-1060(%rbp), %ecx
	movl	-1056(%rbp), %eax
	orl	%eax, %ecx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices, %rax
	movl	(%rax), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	EApiGPIOSetDirection
	movl	%eax, -1044(%rbp)
	.loc 1 870 0
	cmpl	$0, -1044(%rbp)
	je	.L81
	.loc 1 872 0
	leaq	-1040(%rbp), %rcx
	movl	-1044(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	.loc 1 873 0
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rdx, %rcx
	movl	$.LC68, %edx
	movq	%rax, %rsi
	movl	$.LC62, %edi
	movl	$0, %eax
	call	printf
	.loc 1 879 0
	jmp	.L78
.L81:
	.loc 1 881 0
	movl	-1060(%rbp), %edx
	movl	-1056(%rbp), %eax
	movl	%edx, %ecx
	orl	%eax, %ecx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices, %rax
	movl	(%rax), %eax
	leaq	-1068(%rbp), %rdx
	movl	%ecx, %esi
	movl	%eax, %edi
	call	EApiGPIOGetDirection
	movl	%eax, -1044(%rbp)
	.loc 1 882 0
	cmpl	$0, -1044(%rbp)
	je	.L82
	.loc 1 884 0
	leaq	-1040(%rbp), %rcx
	movl	-1044(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	.loc 1 885 0
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rdx, %rcx
	movl	$.LC64, %edx
	movq	%rax, %rsi
	movl	$.LC62, %edi
	movl	$0, %eax
	call	printf
	.loc 1 891 0
	jmp	.L78
.L82:
	.loc 1 893 0
	movl	-1068(%rbp), %edx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	movl	%edx, %ecx
	movl	$.LC64, %edx
	movq	%rax, %rsi
	movl	$.LC65, %edi
	movl	$0, %eax
	call	printf
	.loc 1 899 0
	movl	-1056(%rbp), %edx
	movl	-1056(%rbp), %ecx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices, %rax
	movl	(%rax), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	EApiGPIOSetLevel
	movl	%eax, -1044(%rbp)
	.loc 1 900 0
	cmpl	$0, -1044(%rbp)
	je	.L83
	.loc 1 902 0
	leaq	-1040(%rbp), %rcx
	movl	-1044(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	.loc 1 903 0
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rdx, %rcx
	movl	$.LC69, %edx
	movq	%rax, %rsi
	movl	$.LC62, %edi
	movl	$0, %eax
	call	printf
	.loc 1 909 0
	jmp	.L78
.L83:
	.loc 1 911 0
	movl	-1060(%rbp), %edx
	movl	-1056(%rbp), %eax
	movl	%edx, %ecx
	orl	%eax, %ecx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices, %rax
	movl	(%rax), %eax
	leaq	-1064(%rbp), %rdx
	movl	%ecx, %esi
	movl	%eax, %edi
	call	EApiGPIOGetLevel
	movl	%eax, -1044(%rbp)
	.loc 1 912 0
	cmpl	$0, -1044(%rbp)
	je	.L84
	.loc 1 914 0
	leaq	-1040(%rbp), %rcx
	movl	-1044(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiAHCreateErrorString
	.loc 1 915 0
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	leaq	-1040(%rbp), %rdx
	movq	%rdx, %rcx
	movl	$.LC64, %edx
	movq	%rax, %rsi
	movl	$.LC62, %edi
	movl	$0, %eax
	call	printf
	.loc 1 921 0
	jmp	.L78
.L84:
	.loc 1 923 0
	movl	-1064(%rbp), %edx
	movl	-1052(%rbp), %eax
	salq	$4, %rax
	addq	$EApiGpioDevices+8, %rax
	movq	(%rax), %rax
	movl	%edx, %ecx
	movl	$.LC69, %edx
	movq	%rax, %rsi
	movl	$.LC67, %edi
	movl	$0, %eax
	call	printf
.L78:
	.loc 1 808 0 discriminator 2
	addl	$1, -1052(%rbp)
.L76:
	.loc 1 808 0 is_stmt 0 discriminator 1
	cmpl	$11, -1052(%rbp)
	jbe	.L85
	.loc 1 929 0 is_stmt 1
	movl	$0, -1052(%rbp)
	jmp	.L86
.L92:
	.loc 1 931 0
	movl	$0, -1048(%rbp)
	jmp	.L87
.L91:
	.loc 1 933 0
	movl	-1048(%rbp), %eax
	salq	$5, %rax
	addq	$EApiGpioterfaceValidate+8, %rax
	movq	(%rax), %rdx
	movl	-1048(%rbp), %eax
	salq	$5, %rax
	addq	$EApiGpioterfaceValidate, %rax
	movq	(%rax), %rcx
	movl	-1052(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiGPIOGetDirectionCaps
	movl	%eax, -1044(%rbp)
	.loc 1 938 0
	movl	-1048(%rbp), %eax
	salq	$5, %rax
	addq	$EApiGpioterfaceValidate+16, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	je	.L88
	.loc 1 938 0 is_stmt 0 discriminator 2
	movl	-1048(%rbp), %eax
	salq	$5, %rax
	addq	$EApiGpioterfaceValidate+20, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	je	.L88
	.loc 1 938 0 discriminator 4
	movl	-1048(%rbp), %eax
	salq	$5, %rax
	addq	$EApiGpioterfaceValidate+24, %rax
	movl	(%rax), %eax
	cmpl	-1044(%rbp), %eax
	jne	.L89
.L88:
	.loc 1 938 0 discriminator 5
	movl	$1, %eax
	jmp	.L90
.L89:
	.loc 1 938 0 discriminator 6
	movl	$0, %eax
.L90:
	.loc 1 938 0 discriminator 8
	cltq
	movq	FailPass(,%rax,8), %rdx
	movq	LogStream(%rip), %rax
	movl	-1044(%rbp), %ecx
	pushq	%rdx
	movl	-1048(%rbp), %edx
	pushq	%rdx
	movl	-1052(%rbp), %edx
	pushq	%rdx
	pushq	$.LC47
	movl	%ecx, %r9d
	movl	$938, %r8d
	movl	$.LC61, %ecx
	movl	$.LC46, %edx
	movl	$76, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	siFFormattedMessage_SC
	addq	$32, %rsp
	.loc 1 931 0 is_stmt 1 discriminator 8
	addl	$1, -1048(%rbp)
.L87:
	.loc 1 931 0 is_stmt 0 discriminator 2
	cmpl	$3, -1048(%rbp)
	jbe	.L91
	.loc 1 929 0 is_stmt 1 discriminator 2
	addl	$1, -1052(%rbp)
.L86:
	.loc 1 929 0 is_stmt 0 discriminator 1
	cmpl	$9, -1052(%rbp)
	jbe	.L92
	.loc 1 941 0 is_stmt 1
	nop
	.loc 1 942 0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L94
	call	__stack_chk_fail
.L94:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	EApiValidateGPIOApi, .-EApiValidateGPIOApi
	.globl	TestFunctions
	.section	.rodata
.LC70:
	.string	"Values Function"
.LC71:
	.string	"Strings Function"
.LC72:
	.string	"I2C Function"
.LC73:
	.string	"Storage Function"
.LC74:
	.string	"Gpio Function"
	.align 32
	.type	TestFunctions, @object
	.size	TestFunctions, 80
TestFunctions:
	.quad	EApiValidateValuesApi
	.quad	.LC70
	.quad	EApiValidateStringApi
	.quad	.LC71
	.quad	EApiValidateI2CApi
	.quad	.LC72
	.quad	EApiValidateStorageApi
	.quad	.LC73
	.quad	EApiValidateGPIOApi
	.quad	.LC74
.LC75:
	.string	"w"
.LC76:
	.string	"EApiValidateAPI.log"
.LC77:
	.string	"Id"
.LC78:
	.string	"Status Code"
.LC79:
	.string	"Function Name"
	.align 8
.LC80:
	.string	"L%04u %-30s | %-25s | %5s %5s    [%s]\n"
.LC81:
	.string	"Status"
.LC82:
	.string	"Test#"
	.align 8
.LC83:
	.string	"EApi(Embedded Application Interface)\nEApi Verification Tool                            Version %u.%u.%u\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB9:
	.loc 1 968 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	.loc 1 970 0
	movl	$.LC75, %esi
	movl	$.LC76, %edi
	call	fopen
	movq	%rax, LogStream(%rip)
	.loc 1 971 0
	movq	LogStream(%rip), %rax
	testq	%rax, %rax
	jne	.L96
	.loc 1 972 0
	movq	stdout(%rip), %rax
	movq	%rax, LogStream(%rip)
.L96:
	.loc 1 973 0
	call	EApiLibInitialize
	testl	%eax, %eax
	je	.L97
	.loc 1 975 0
	movl	$2, %edi
	call	exit
.L97:
	.loc 1 977 0
	movq	LogStream(%rip), %rax
	pushq	$.LC81
	pushq	$.LC82
	movl	$.LC77, %r9d
	movl	$.LC78, %r8d
	movl	$.LC79, %ecx
	movl	$980, %edx
	movl	$.LC80, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	addq	$16, %rsp
	.loc 1 988 0
	movq	stderr(%rip), %rax
	movl	$766, %r8d
	movl	$5, %ecx
	movl	$0, %edx
	movl	$.LC83, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	.loc 1 1017 0
	movl	$EApiValidateValuesApi, %eax
	call	*%rax
	.loc 1 1018 0
	movl	$EApiValidateStringApi, %eax
	call	*%rax
	.loc 1 1019 0
	movl	$EApiValidateI2CApi, %eax
	call	*%rax
	.loc 1 1021 0
	call	EApiLibInitialize
	testl	%eax, %eax
	je	.L98
	.loc 1 1023 0
	movl	$3, %edi
	call	exit
.L98:
	.loc 1 1025 0
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE9:
	.size	main, .-main
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
	.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
	.file 4 "/usr/include/stdio.h"
	.file 5 "/usr/include/libio.h"
	.file 6 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h"
	.file 7 "<built-in>"
	.file 8 "/usr/include/stdint.h"
	.file 9 "../../../include/EApi.h"
	.file 10 "../../include/EApiAHStr.h"
	.file 11 "../../include/EApiAHI2C.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x1003
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF178
	.byte	0xc
	.long	.LASF179
	.long	.LASF180
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF7
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
	.uleb128 0x2
	.long	.LASF8
	.byte	0x3
	.byte	0x83
	.long	0x69
	.uleb128 0x2
	.long	.LASF9
	.byte	0x3
	.byte	0x84
	.long	0x69
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF10
	.uleb128 0x5
	.byte	0x8
	.uleb128 0x6
	.byte	0x8
	.long	0x95
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF11
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF12
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF13
	.uleb128 0x2
	.long	.LASF14
	.byte	0x4
	.byte	0x30
	.long	0xb5
	.uleb128 0x7
	.long	.LASF45
	.byte	0xd8
	.byte	0x5
	.byte	0xf5
	.long	0x235
	.uleb128 0x8
	.long	.LASF15
	.byte	0x5
	.byte	0xf6
	.long	0x3f
	.byte	0
	.uleb128 0x8
	.long	.LASF16
	.byte	0x5
	.byte	0xfb
	.long	0x8f
	.byte	0x8
	.uleb128 0x8
	.long	.LASF17
	.byte	0x5
	.byte	0xfc
	.long	0x8f
	.byte	0x10
	.uleb128 0x8
	.long	.LASF18
	.byte	0x5
	.byte	0xfd
	.long	0x8f
	.byte	0x18
	.uleb128 0x8
	.long	.LASF19
	.byte	0x5
	.byte	0xfe
	.long	0x8f
	.byte	0x20
	.uleb128 0x8
	.long	.LASF20
	.byte	0x5
	.byte	0xff
	.long	0x8f
	.byte	0x28
	.uleb128 0x9
	.long	.LASF21
	.byte	0x5
	.value	0x100
	.long	0x8f
	.byte	0x30
	.uleb128 0x9
	.long	.LASF22
	.byte	0x5
	.value	0x101
	.long	0x8f
	.byte	0x38
	.uleb128 0x9
	.long	.LASF23
	.byte	0x5
	.value	0x102
	.long	0x8f
	.byte	0x40
	.uleb128 0x9
	.long	.LASF24
	.byte	0x5
	.value	0x104
	.long	0x8f
	.byte	0x48
	.uleb128 0x9
	.long	.LASF25
	.byte	0x5
	.value	0x105
	.long	0x8f
	.byte	0x50
	.uleb128 0x9
	.long	.LASF26
	.byte	0x5
	.value	0x106
	.long	0x8f
	.byte	0x58
	.uleb128 0x9
	.long	.LASF27
	.byte	0x5
	.value	0x108
	.long	0x2c5
	.byte	0x60
	.uleb128 0x9
	.long	.LASF28
	.byte	0x5
	.value	0x10a
	.long	0x2cb
	.byte	0x68
	.uleb128 0x9
	.long	.LASF29
	.byte	0x5
	.value	0x10c
	.long	0x3f
	.byte	0x70
	.uleb128 0x9
	.long	.LASF30
	.byte	0x5
	.value	0x110
	.long	0x3f
	.byte	0x74
	.uleb128 0x9
	.long	.LASF31
	.byte	0x5
	.value	0x112
	.long	0x70
	.byte	0x78
	.uleb128 0x9
	.long	.LASF32
	.byte	0x5
	.value	0x116
	.long	0x54
	.byte	0x80
	.uleb128 0x9
	.long	.LASF33
	.byte	0x5
	.value	0x117
	.long	0x5b
	.byte	0x82
	.uleb128 0x9
	.long	.LASF34
	.byte	0x5
	.value	0x118
	.long	0x2d1
	.byte	0x83
	.uleb128 0x9
	.long	.LASF35
	.byte	0x5
	.value	0x11c
	.long	0x2e1
	.byte	0x88
	.uleb128 0x9
	.long	.LASF36
	.byte	0x5
	.value	0x125
	.long	0x7b
	.byte	0x90
	.uleb128 0x9
	.long	.LASF37
	.byte	0x5
	.value	0x12e
	.long	0x8d
	.byte	0x98
	.uleb128 0x9
	.long	.LASF38
	.byte	0x5
	.value	0x12f
	.long	0x8d
	.byte	0xa0
	.uleb128 0x9
	.long	.LASF39
	.byte	0x5
	.value	0x130
	.long	0x8d
	.byte	0xa8
	.uleb128 0x9
	.long	.LASF40
	.byte	0x5
	.value	0x131
	.long	0x8d
	.byte	0xb0
	.uleb128 0x9
	.long	.LASF41
	.byte	0x5
	.value	0x132
	.long	0x2d
	.byte	0xb8
	.uleb128 0x9
	.long	.LASF42
	.byte	0x5
	.value	0x134
	.long	0x3f
	.byte	0xc0
	.uleb128 0x9
	.long	.LASF43
	.byte	0x5
	.value	0x136
	.long	0x2e7
	.byte	0xc4
	.byte	0
	.uleb128 0x2
	.long	.LASF44
	.byte	0x6
	.byte	0x28
	.long	0x240
	.uleb128 0xa
	.long	0x250
	.long	0x250
	.uleb128 0xb
	.long	0x86
	.byte	0
	.byte	0
	.uleb128 0x7
	.long	.LASF46
	.byte	0x18
	.byte	0x7
	.byte	0
	.long	0x28d
	.uleb128 0x8
	.long	.LASF47
	.byte	0x7
	.byte	0
	.long	0x46
	.byte	0
	.uleb128 0x8
	.long	.LASF48
	.byte	0x7
	.byte	0
	.long	0x46
	.byte	0x4
	.uleb128 0x8
	.long	.LASF49
	.byte	0x7
	.byte	0
	.long	0x8d
	.byte	0x8
	.uleb128 0x8
	.long	.LASF50
	.byte	0x7
	.byte	0
	.long	0x8d
	.byte	0x10
	.byte	0
	.uleb128 0xc
	.long	.LASF181
	.byte	0x5
	.byte	0x9a
	.uleb128 0x7
	.long	.LASF51
	.byte	0x18
	.byte	0x5
	.byte	0xa0
	.long	0x2c5
	.uleb128 0x8
	.long	.LASF52
	.byte	0x5
	.byte	0xa1
	.long	0x2c5
	.byte	0
	.uleb128 0x8
	.long	.LASF53
	.byte	0x5
	.byte	0xa2
	.long	0x2cb
	.byte	0x8
	.uleb128 0x8
	.long	.LASF54
	.byte	0x5
	.byte	0xa6
	.long	0x3f
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x294
	.uleb128 0x6
	.byte	0x8
	.long	0xb5
	.uleb128 0xa
	.long	0x95
	.long	0x2e1
	.uleb128 0xb
	.long	0x86
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x28d
	.uleb128 0xa
	.long	0x95
	.long	0x2f7
	.uleb128 0xb
	.long	0x86
	.byte	0x13
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x2fd
	.uleb128 0xd
	.long	0x95
	.uleb128 0x2
	.long	.LASF55
	.byte	0x4
	.byte	0x4f
	.long	0x235
	.uleb128 0x2
	.long	.LASF56
	.byte	0x8
	.byte	0x30
	.long	0x4d
	.uleb128 0x2
	.long	.LASF57
	.byte	0x8
	.byte	0x31
	.long	0x54
	.uleb128 0x2
	.long	.LASF58
	.byte	0x8
	.byte	0x33
	.long	0x46
	.uleb128 0x2
	.long	.LASF59
	.byte	0x9
	.byte	0x93
	.long	0x323
	.uleb128 0x2
	.long	.LASF60
	.byte	0x9
	.byte	0x94
	.long	0x323
	.uleb128 0x2
	.long	.LASF61
	.byte	0xa
	.byte	0x79
	.long	0x34f
	.uleb128 0xe
	.long	0x3f
	.long	0x368
	.uleb128 0xf
	.long	0x323
	.uleb128 0xf
	.long	0x368
	.uleb128 0xf
	.long	0x36d
	.byte	0
	.uleb128 0xd
	.long	0x8f
	.uleb128 0xd
	.long	0x323
	.uleb128 0x10
	.long	.LASF120
	.byte	0x4
	.long	0x46
	.byte	0xb
	.byte	0x2d
	.long	0x38f
	.uleb128 0x11
	.long	.LASF62
	.byte	0x1
	.uleb128 0x11
	.long	.LASF63
	.byte	0x2
	.byte	0
	.uleb128 0x2
	.long	.LASF64
	.byte	0xb
	.byte	0x31
	.long	0x318
	.uleb128 0x7
	.long	.LASF65
	.byte	0xc
	.byte	0xb
	.byte	0x33
	.long	0x3e3
	.uleb128 0x8
	.long	.LASF66
	.byte	0xb
	.byte	0x34
	.long	0x318
	.byte	0
	.uleb128 0x8
	.long	.LASF67
	.byte	0xb
	.byte	0x35
	.long	0x318
	.byte	0x2
	.uleb128 0x8
	.long	.LASF68
	.byte	0xb
	.byte	0x36
	.long	0x38f
	.byte	0x4
	.uleb128 0x8
	.long	.LASF69
	.byte	0xb
	.byte	0x37
	.long	0x318
	.byte	0x6
	.uleb128 0x8
	.long	.LASF70
	.byte	0xb
	.byte	0x38
	.long	0x323
	.byte	0x8
	.byte	0
	.uleb128 0x2
	.long	.LASF71
	.byte	0xb
	.byte	0x39
	.long	0x39a
	.uleb128 0x2
	.long	.LASF72
	.byte	0x1
	.byte	0x28
	.long	0x3f9
	.uleb128 0x12
	.uleb128 0x7
	.long	.LASF73
	.byte	0x10
	.byte	0x1
	.byte	0x9a
	.long	0x41e
	.uleb128 0x13
	.string	"Id"
	.byte	0x1
	.byte	0x9b
	.long	0x41e
	.byte	0
	.uleb128 0x8
	.long	.LASF74
	.byte	0x1
	.byte	0x9c
	.long	0x423
	.byte	0x8
	.byte	0
	.uleb128 0xd
	.long	0x339
	.uleb128 0xd
	.long	0x2f7
	.uleb128 0x2
	.long	.LASF75
	.byte	0x1
	.byte	0x9d
	.long	0x3fa
	.uleb128 0x7
	.long	.LASF76
	.byte	0x18
	.byte	0x1
	.byte	0xd8
	.long	0x463
	.uleb128 0x13
	.string	"Id"
	.byte	0x1
	.byte	0xd9
	.long	0x41e
	.byte	0
	.uleb128 0x8
	.long	.LASF74
	.byte	0x1
	.byte	0xda
	.long	0x423
	.byte	0x8
	.uleb128 0x8
	.long	.LASF77
	.byte	0x1
	.byte	0xdb
	.long	0x469
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x344
	.uleb128 0xd
	.long	0x463
	.uleb128 0x2
	.long	.LASF78
	.byte	0x1
	.byte	0xdc
	.long	0x433
	.uleb128 0x14
	.long	.LASF79
	.byte	0x38
	.byte	0x1
	.value	0x139
	.long	0x4fc
	.uleb128 0x9
	.long	.LASF80
	.byte	0x1
	.value	0x13a
	.long	0x4fc
	.byte	0
	.uleb128 0x9
	.long	.LASF81
	.byte	0x1
	.value	0x13b
	.long	0x8d
	.byte	0x8
	.uleb128 0x9
	.long	.LASF82
	.byte	0x1
	.value	0x13c
	.long	0x36d
	.byte	0x10
	.uleb128 0x9
	.long	.LASF83
	.byte	0x1
	.value	0x13d
	.long	0x8d
	.byte	0x18
	.uleb128 0x9
	.long	.LASF84
	.byte	0x1
	.value	0x13e
	.long	0x36d
	.byte	0x20
	.uleb128 0x9
	.long	.LASF85
	.byte	0x1
	.value	0x13f
	.long	0x36d
	.byte	0x24
	.uleb128 0x9
	.long	.LASF86
	.byte	0x1
	.value	0x140
	.long	0x501
	.byte	0x28
	.uleb128 0x9
	.long	.LASF87
	.byte	0x1
	.value	0x141
	.long	0x501
	.byte	0x2c
	.uleb128 0x9
	.long	.LASF88
	.byte	0x1
	.value	0x142
	.long	0x501
	.byte	0x30
	.byte	0
	.uleb128 0xd
	.long	0x30d
	.uleb128 0xd
	.long	0x32e
	.uleb128 0x15
	.long	.LASF89
	.byte	0x1
	.value	0x143
	.long	0x479
	.uleb128 0x14
	.long	.LASF90
	.byte	0x28
	.byte	0x1
	.value	0x151
	.long	0x588
	.uleb128 0x9
	.long	.LASF80
	.byte	0x1
	.value	0x152
	.long	0x36d
	.byte	0
	.uleb128 0x9
	.long	.LASF91
	.byte	0x1
	.value	0x153
	.long	0x36d
	.byte	0x4
	.uleb128 0x9
	.long	.LASF92
	.byte	0x1
	.value	0x154
	.long	0x8d
	.byte	0x8
	.uleb128 0x9
	.long	.LASF93
	.byte	0x1
	.value	0x155
	.long	0x36d
	.byte	0x10
	.uleb128 0x9
	.long	.LASF94
	.byte	0x1
	.value	0x156
	.long	0x36d
	.byte	0x14
	.uleb128 0x9
	.long	.LASF86
	.byte	0x1
	.value	0x157
	.long	0x501
	.byte	0x18
	.uleb128 0x9
	.long	.LASF87
	.byte	0x1
	.value	0x158
	.long	0x501
	.byte	0x1c
	.uleb128 0x9
	.long	.LASF88
	.byte	0x1
	.value	0x159
	.long	0x501
	.byte	0x20
	.byte	0
	.uleb128 0x15
	.long	.LASF95
	.byte	0x1
	.value	0x15a
	.long	0x512
	.uleb128 0x14
	.long	.LASF96
	.byte	0x18
	.byte	0x1
	.value	0x169
	.long	0x5d6
	.uleb128 0x9
	.long	.LASF97
	.byte	0x1
	.value	0x16a
	.long	0x5d6
	.byte	0
	.uleb128 0x9
	.long	.LASF86
	.byte	0x1
	.value	0x16b
	.long	0x501
	.byte	0x8
	.uleb128 0x9
	.long	.LASF87
	.byte	0x1
	.value	0x16c
	.long	0x501
	.byte	0xc
	.uleb128 0x9
	.long	.LASF88
	.byte	0x1
	.value	0x16d
	.long	0x501
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x323
	.uleb128 0x15
	.long	.LASF98
	.byte	0x1
	.value	0x16e
	.long	0x594
	.uleb128 0x14
	.long	.LASF99
	.byte	0x10
	.byte	0x1
	.value	0x174
	.long	0x60f
	.uleb128 0x16
	.string	"Id"
	.byte	0x1
	.value	0x175
	.long	0x41e
	.byte	0
	.uleb128 0x9
	.long	.LASF74
	.byte	0x1
	.value	0x176
	.long	0x423
	.byte	0x8
	.byte	0
	.uleb128 0x15
	.long	.LASF100
	.byte	0x1
	.value	0x177
	.long	0x5e8
	.uleb128 0x14
	.long	.LASF101
	.byte	0x18
	.byte	0x1
	.value	0x268
	.long	0x64f
	.uleb128 0x16
	.string	"Id"
	.byte	0x1
	.value	0x269
	.long	0x41e
	.byte	0
	.uleb128 0x9
	.long	.LASF74
	.byte	0x1
	.value	0x26a
	.long	0x423
	.byte	0x8
	.uleb128 0x9
	.long	.LASF102
	.byte	0x1
	.value	0x26b
	.long	0x36d
	.byte	0x10
	.byte	0
	.uleb128 0x15
	.long	.LASF103
	.byte	0x1
	.value	0x26c
	.long	0x61b
	.uleb128 0x14
	.long	.LASF104
	.byte	0x28
	.byte	0x1
	.value	0x274
	.long	0x6c4
	.uleb128 0x9
	.long	.LASF91
	.byte	0x1
	.value	0x275
	.long	0x36d
	.byte	0
	.uleb128 0x9
	.long	.LASF92
	.byte	0x1
	.value	0x276
	.long	0x8d
	.byte	0x8
	.uleb128 0x9
	.long	.LASF93
	.byte	0x1
	.value	0x277
	.long	0x36d
	.byte	0x10
	.uleb128 0x9
	.long	.LASF94
	.byte	0x1
	.value	0x278
	.long	0x36d
	.byte	0x14
	.uleb128 0x9
	.long	.LASF86
	.byte	0x1
	.value	0x279
	.long	0x501
	.byte	0x18
	.uleb128 0x9
	.long	.LASF87
	.byte	0x1
	.value	0x27a
	.long	0x501
	.byte	0x1c
	.uleb128 0x9
	.long	.LASF88
	.byte	0x1
	.value	0x27b
	.long	0x501
	.byte	0x20
	.byte	0
	.uleb128 0x15
	.long	.LASF105
	.byte	0x1
	.value	0x27c
	.long	0x65b
	.uleb128 0x14
	.long	.LASF106
	.byte	0x20
	.byte	0x1
	.value	0x285
	.long	0x71f
	.uleb128 0x9
	.long	.LASF107
	.byte	0x1
	.value	0x286
	.long	0x5d6
	.byte	0
	.uleb128 0x9
	.long	.LASF108
	.byte	0x1
	.value	0x287
	.long	0x5d6
	.byte	0x8
	.uleb128 0x9
	.long	.LASF86
	.byte	0x1
	.value	0x288
	.long	0x501
	.byte	0x10
	.uleb128 0x9
	.long	.LASF87
	.byte	0x1
	.value	0x289
	.long	0x501
	.byte	0x14
	.uleb128 0x9
	.long	.LASF88
	.byte	0x1
	.value	0x28a
	.long	0x501
	.byte	0x18
	.byte	0
	.uleb128 0x15
	.long	.LASF109
	.byte	0x1
	.value	0x28b
	.long	0x6d0
	.uleb128 0x14
	.long	.LASF110
	.byte	0x20
	.byte	0x1
	.value	0x2fa
	.long	0x77a
	.uleb128 0x9
	.long	.LASF111
	.byte	0x1
	.value	0x2fb
	.long	0x5d6
	.byte	0
	.uleb128 0x9
	.long	.LASF112
	.byte	0x1
	.value	0x2fc
	.long	0x5d6
	.byte	0x8
	.uleb128 0x9
	.long	.LASF86
	.byte	0x1
	.value	0x2fd
	.long	0x501
	.byte	0x10
	.uleb128 0x9
	.long	.LASF87
	.byte	0x1
	.value	0x2fe
	.long	0x501
	.byte	0x14
	.uleb128 0x9
	.long	.LASF88
	.byte	0x1
	.value	0x2ff
	.long	0x501
	.byte	0x18
	.byte	0
	.uleb128 0x15
	.long	.LASF113
	.byte	0x1
	.value	0x300
	.long	0x72b
	.uleb128 0x14
	.long	.LASF114
	.byte	0x10
	.byte	0x1
	.value	0x30a
	.long	0x7ad
	.uleb128 0x16
	.string	"Id"
	.byte	0x1
	.value	0x30b
	.long	0x41e
	.byte	0
	.uleb128 0x9
	.long	.LASF74
	.byte	0x1
	.value	0x30c
	.long	0x423
	.byte	0x8
	.byte	0
	.uleb128 0x15
	.long	.LASF115
	.byte	0x1
	.value	0x30d
	.long	0x786
	.uleb128 0x14
	.long	.LASF116
	.byte	0x10
	.byte	0x1
	.value	0x3b3
	.long	0x7e1
	.uleb128 0x9
	.long	.LASF117
	.byte	0x1
	.value	0x3b4
	.long	0x7e1
	.byte	0
	.uleb128 0x9
	.long	.LASF118
	.byte	0x1
	.value	0x3b5
	.long	0x423
	.byte	0x8
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x3ee
	.uleb128 0x15
	.long	.LASF119
	.byte	0x1
	.value	0x3b6
	.long	0x7b9
	.uleb128 0x17
	.long	.LASF121
	.byte	0x4
	.long	0x46
	.byte	0x1
	.value	0x3bf
	.long	0x81d
	.uleb128 0x11
	.long	.LASF122
	.byte	0
	.uleb128 0x11
	.long	.LASF123
	.byte	0x1
	.uleb128 0x11
	.long	.LASF124
	.byte	0x2
	.uleb128 0x11
	.long	.LASF125
	.byte	0x3
	.byte	0
	.uleb128 0x18
	.long	.LASF182
	.byte	0x1
	.byte	0x46
	.long	0x3f
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x8d6
	.uleb128 0x19
	.long	.LASF126
	.byte	0x1
	.byte	0x47
	.long	0x8d6
	.uleb128 0x3
	.byte	0x91
	.sleb128 -248
	.uleb128 0x19
	.long	.LASF127
	.byte	0x1
	.byte	0x48
	.long	0x95
	.uleb128 0x3
	.byte	0x91
	.sleb128 -252
	.uleb128 0x19
	.long	.LASF128
	.byte	0x1
	.byte	0x49
	.long	0x2f7
	.uleb128 0x3
	.byte	0x91
	.sleb128 -264
	.uleb128 0x19
	.long	.LASF129
	.byte	0x1
	.byte	0x4a
	.long	0x2f7
	.uleb128 0x3
	.byte	0x91
	.sleb128 -272
	.uleb128 0x19
	.long	.LASF130
	.byte	0x1
	.byte	0x4b
	.long	0x46
	.uleb128 0x3
	.byte	0x91
	.sleb128 -256
	.uleb128 0x19
	.long	.LASF131
	.byte	0x1
	.byte	0x4c
	.long	0x32e
	.uleb128 0x3
	.byte	0x91
	.sleb128 -276
	.uleb128 0x19
	.long	.LASF132
	.byte	0x1
	.byte	0x4d
	.long	0x2f7
	.uleb128 0x3
	.byte	0x91
	.sleb128 -288
	.uleb128 0x1a
	.uleb128 0x1b
	.string	"Ret"
	.byte	0x1
	.byte	0x51
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -236
	.uleb128 0x1c
	.long	.LASF133
	.byte	0x1
	.byte	0x52
	.long	0x302
	.uleb128 0x3
	.byte	0x91
	.sleb128 -224
	.uleb128 0x1c
	.long	.LASF134
	.byte	0x1
	.byte	0x53
	.long	0x2f7
	.uleb128 0x3
	.byte	0x91
	.sleb128 -232
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0xaa
	.uleb128 0x1d
	.long	.LASF137
	.byte	0x1
	.byte	0xa8
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x942
	.uleb128 0x1c
	.long	.LASF131
	.byte	0x1
	.byte	0xaa
	.long	0x32e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x1c
	.long	.LASF135
	.byte	0x1
	.byte	0xab
	.long	0x8f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x1c
	.long	.LASF136
	.byte	0x1
	.byte	0xac
	.long	0x323
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0x1e
	.quad	.LBB2
	.quad	.LBE2-.LBB2
	.uleb128 0x1b
	.string	"i"
	.byte	0x1
	.byte	0xb2
	.long	0x46
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.byte	0
	.byte	0
	.uleb128 0x1f
	.long	.LASF138
	.byte	0x1
	.value	0x111
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x99f
	.uleb128 0x20
	.long	.LASF131
	.byte	0x1
	.value	0x114
	.long	0x32e
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1060
	.uleb128 0x20
	.long	.LASF139
	.byte	0x1
	.value	0x115
	.long	0x323
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1068
	.uleb128 0x21
	.string	"i"
	.byte	0x1
	.value	0x116
	.long	0x46
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1064
	.uleb128 0x20
	.long	.LASF140
	.byte	0x1
	.value	0x119
	.long	0x99f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1056
	.byte	0
	.uleb128 0xa
	.long	0x95
	.long	0x9b0
	.uleb128 0x22
	.long	0x86
	.value	0x3ff
	.byte	0
	.uleb128 0x1f
	.long	.LASF141
	.byte	0x1
	.value	0x189
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x9fc
	.uleb128 0x23
	.long	.LASF126
	.byte	0x1
	.value	0x18a
	.long	0x8d6
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x23
	.long	.LASF135
	.byte	0x1
	.value	0x18b
	.long	0x8d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x23
	.long	.LASF142
	.byte	0x1
	.value	0x18c
	.long	0x2d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.byte	0
	.uleb128 0x1f
	.long	.LASF143
	.byte	0x1
	.value	0x194
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0xb70
	.uleb128 0x20
	.long	.LASF131
	.byte	0x1
	.value	0x197
	.long	0x32e
	.uleb128 0x3
	.byte	0x91
	.sleb128 -152
	.uleb128 0x24
	.string	"i"
	.byte	0x1
	.value	0x198
	.long	0x46
	.uleb128 0x24
	.string	"i2"
	.byte	0x1
	.value	0x198
	.long	0x46
	.uleb128 0x20
	.long	.LASF144
	.byte	0x1
	.value	0x19e
	.long	0xb70
	.uleb128 0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0x20
	.long	.LASF145
	.byte	0x1
	.value	0x1bc
	.long	0xb80
	.uleb128 0x3
	.byte	0x91
	.sleb128 -145
	.uleb128 0x20
	.long	.LASF146
	.byte	0x1
	.value	0x1d3
	.long	0xb90
	.uleb128 0x3
	.byte	0x91
	.sleb128 -144
	.uleb128 0x20
	.long	.LASF147
	.byte	0x1
	.value	0x1ea
	.long	0xba0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -128
	.uleb128 0x25
	.quad	.LBB3
	.quad	.LBE3-.LBB3
	.long	0xac3
	.uleb128 0x21
	.string	"k"
	.byte	0x1
	.value	0x1a9
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -180
	.uleb128 0x1e
	.quad	.LBB4
	.quad	.LBE4-.LBB4
	.uleb128 0x21
	.string	"i"
	.byte	0x1
	.value	0x1aa
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -176
	.byte	0
	.byte	0
	.uleb128 0x25
	.quad	.LBB5
	.quad	.LBE5-.LBB5
	.long	0xb07
	.uleb128 0x21
	.string	"j"
	.byte	0x1
	.value	0x1bd
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -172
	.uleb128 0x1e
	.quad	.LBB6
	.quad	.LBE6-.LBB6
	.uleb128 0x21
	.string	"i"
	.byte	0x1
	.value	0x1c8
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -168
	.byte	0
	.byte	0
	.uleb128 0x25
	.quad	.LBB7
	.quad	.LBE7-.LBB7
	.long	0xb2b
	.uleb128 0x21
	.string	"j"
	.byte	0x1
	.value	0x1d4
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -164
	.byte	0
	.uleb128 0x25
	.quad	.LBB8
	.quad	.LBE8-.LBB8
	.long	0xb4f
	.uleb128 0x21
	.string	"j"
	.byte	0x1
	.value	0x1d7
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -160
	.byte	0
	.uleb128 0x1e
	.quad	.LBB9
	.quad	.LBE9-.LBB9
	.uleb128 0x21
	.string	"j"
	.byte	0x1
	.value	0x212
	.long	0x3f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -156
	.byte	0
	.byte	0
	.uleb128 0xa
	.long	0x30d
	.long	0xb80
	.uleb128 0xb
	.long	0x86
	.byte	0x3f
	.byte	0
	.uleb128 0xa
	.long	0x30d
	.long	0xb90
	.uleb128 0xb
	.long	0x86
	.byte	0
	.byte	0
	.uleb128 0xa
	.long	0x30d
	.long	0xba0
	.uleb128 0xb
	.long	0x86
	.byte	0x9
	.byte	0
	.uleb128 0xa
	.long	0x30d
	.long	0xbb0
	.uleb128 0xb
	.long	0x86
	.byte	0x1f
	.byte	0
	.uleb128 0x1f
	.long	.LASF148
	.byte	0x1
	.value	0x294
	.quad	.LFB7
	.quad	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0xc0c
	.uleb128 0x20
	.long	.LASF140
	.byte	0x1
	.value	0x296
	.long	0x99f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1056
	.uleb128 0x21
	.string	"i"
	.byte	0x1
	.value	0x297
	.long	0x46
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1068
	.uleb128 0x21
	.string	"i2"
	.byte	0x1
	.value	0x297
	.long	0x46
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1064
	.uleb128 0x20
	.long	.LASF131
	.byte	0x1
	.value	0x298
	.long	0x32e
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1060
	.byte	0
	.uleb128 0x1f
	.long	.LASF149
	.byte	0x1
	.value	0x31f
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0xca8
	.uleb128 0x20
	.long	.LASF140
	.byte	0x1
	.value	0x321
	.long	0x99f
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1056
	.uleb128 0x21
	.string	"i"
	.byte	0x1
	.value	0x322
	.long	0x46
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1068
	.uleb128 0x21
	.string	"i2"
	.byte	0x1
	.value	0x322
	.long	0x46
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1064
	.uleb128 0x20
	.long	.LASF150
	.byte	0x1
	.value	0x323
	.long	0x323
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1084
	.uleb128 0x20
	.long	.LASF151
	.byte	0x1
	.value	0x324
	.long	0x323
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1080
	.uleb128 0x20
	.long	.LASF152
	.byte	0x1
	.value	0x325
	.long	0x323
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1076
	.uleb128 0x20
	.long	.LASF153
	.byte	0x1
	.value	0x326
	.long	0x323
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1072
	.uleb128 0x20
	.long	.LASF131
	.byte	0x1
	.value	0x327
	.long	0x32e
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1060
	.byte	0
	.uleb128 0x26
	.long	.LASF183
	.byte	0x1
	.value	0x3c7
	.long	0x3f
	.quad	.LFB9
	.quad	.LFE9-.LFB9
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x27
	.long	.LASF154
	.byte	0x4
	.byte	0xa9
	.long	0x2cb
	.uleb128 0x27
	.long	.LASF155
	.byte	0x4
	.byte	0xaa
	.long	0x2cb
	.uleb128 0x28
	.long	.LASF156
	.byte	0x1
	.byte	0x2e
	.long	0x8d6
	.uleb128 0x9
	.byte	0x3
	.quad	LogStream
	.uleb128 0x28
	.long	.LASF157
	.byte	0x1
	.byte	0x78
	.long	0x99f
	.uleb128 0x9
	.byte	0x3
	.quad	Buffer
	.uleb128 0x28
	.long	.LASF93
	.byte	0x1
	.byte	0x79
	.long	0x323
	.uleb128 0x9
	.byte	0x3
	.quad	BufPtrLen
	.uleb128 0xa
	.long	0x2f7
	.long	0xd2b
	.uleb128 0xb
	.long	0x86
	.byte	0x1
	.byte	0
	.uleb128 0x28
	.long	.LASF158
	.byte	0x1
	.byte	0x7b
	.long	0xd1b
	.uleb128 0x9
	.byte	0x3
	.quad	FailPass
	.uleb128 0xa
	.long	0x428
	.long	0xd50
	.uleb128 0xb
	.long	0x86
	.byte	0x7
	.byte	0
	.uleb128 0x28
	.long	.LASF159
	.byte	0x1
	.byte	0x9e
	.long	0xd65
	.uleb128 0x9
	.byte	0x3
	.quad	EApiStrings
	.uleb128 0xd
	.long	0xd40
	.uleb128 0xa
	.long	0x46e
	.long	0xd7a
	.uleb128 0xb
	.long	0x86
	.byte	0x10
	.byte	0
	.uleb128 0x28
	.long	.LASF160
	.byte	0x1
	.byte	0xfa
	.long	0xd8f
	.uleb128 0x9
	.byte	0x3
	.quad	EApiValues
	.uleb128 0xd
	.long	0xd6a
	.uleb128 0xa
	.long	0x506
	.long	0xda4
	.uleb128 0xb
	.long	0x86
	.byte	0x9
	.byte	0
	.uleb128 0x29
	.long	.LASF161
	.byte	0x1
	.value	0x144
	.long	0xdba
	.uleb128 0x9
	.byte	0x3
	.quad	EApiI2CLLValidate
	.uleb128 0xd
	.long	0xd94
	.uleb128 0xa
	.long	0x588
	.long	0xdcf
	.uleb128 0xb
	.long	0x86
	.byte	0x5
	.byte	0
	.uleb128 0x29
	.long	.LASF162
	.byte	0x1
	.value	0x15b
	.long	0xde5
	.uleb128 0x9
	.byte	0x3
	.quad	EApiI2CHLReadValidate
	.uleb128 0xd
	.long	0xdbf
	.uleb128 0xa
	.long	0x588
	.long	0xdfa
	.uleb128 0xb
	.long	0x86
	.byte	0x2
	.byte	0
	.uleb128 0x29
	.long	.LASF163
	.byte	0x1
	.value	0x163
	.long	0xe10
	.uleb128 0x9
	.byte	0x3
	.quad	EApiI2CHLWriteValidate
	.uleb128 0xd
	.long	0xdea
	.uleb128 0x29
	.long	.LASF164
	.byte	0x1
	.value	0x16f
	.long	0x323
	.uleb128 0x9
	.byte	0x3
	.quad	I2CMaxClk
	.uleb128 0xa
	.long	0x5dc
	.long	0xe3b
	.uleb128 0xb
	.long	0x86
	.byte	0x1
	.byte	0
	.uleb128 0x29
	.long	.LASF165
	.byte	0x1
	.value	0x170
	.long	0xe51
	.uleb128 0x9
	.byte	0x3
	.quad	EApiI2CInterfaceValidate
	.uleb128 0xd
	.long	0xe2b
	.uleb128 0xa
	.long	0x3e3
	.long	0xe66
	.uleb128 0xb
	.long	0x86
	.byte	0x4
	.byte	0
	.uleb128 0x29
	.long	.LASF166
	.byte	0x1
	.value	0x179
	.long	0xe7c
	.uleb128 0x9
	.byte	0x3
	.quad	I2CDevices
	.uleb128 0xd
	.long	0xe56
	.uleb128 0xa
	.long	0x60f
	.long	0xe91
	.uleb128 0xb
	.long	0x86
	.byte	0x3
	.byte	0
	.uleb128 0x29
	.long	.LASF167
	.byte	0x1
	.value	0x183
	.long	0xea7
	.uleb128 0x9
	.byte	0x3
	.quad	EApiI2CBuses
	.uleb128 0xd
	.long	0xe81
	.uleb128 0xa
	.long	0x64f
	.long	0xebc
	.uleb128 0xb
	.long	0x86
	.byte	0x2
	.byte	0
	.uleb128 0x29
	.long	.LASF168
	.byte	0x1
	.value	0x26e
	.long	0xed2
	.uleb128 0x9
	.byte	0x3
	.quad	EApiStorageDevices
	.uleb128 0xd
	.long	0xeac
	.uleb128 0xa
	.long	0x6c4
	.long	0xee7
	.uleb128 0xb
	.long	0x86
	.byte	0x5
	.byte	0
	.uleb128 0x29
	.long	.LASF169
	.byte	0x1
	.value	0x27d
	.long	0xefd
	.uleb128 0x9
	.byte	0x3
	.quad	StorageValidate
	.uleb128 0xd
	.long	0xed7
	.uleb128 0x29
	.long	.LASF170
	.byte	0x1
	.value	0x28c
	.long	0x323
	.uleb128 0x9
	.byte	0x3
	.quad	StorageSize
	.uleb128 0x29
	.long	.LASF171
	.byte	0x1
	.value	0x28d
	.long	0x323
	.uleb128 0x9
	.byte	0x3
	.quad	BlockLength
	.uleb128 0xa
	.long	0x71f
	.long	0xf3e
	.uleb128 0xb
	.long	0x86
	.byte	0x3
	.byte	0
	.uleb128 0x29
	.long	.LASF172
	.byte	0x1
	.value	0x28e
	.long	0xf54
	.uleb128 0x9
	.byte	0x3
	.quad	StorageCapValidate
	.uleb128 0xd
	.long	0xf2e
	.uleb128 0x29
	.long	.LASF173
	.byte	0x1
	.value	0x301
	.long	0x323
	.uleb128 0x9
	.byte	0x3
	.quad	GpioInputs
	.uleb128 0x29
	.long	.LASF174
	.byte	0x1
	.value	0x302
	.long	0x323
	.uleb128 0x9
	.byte	0x3
	.quad	GpioOutputs
	.uleb128 0xa
	.long	0x77a
	.long	0xf95
	.uleb128 0xb
	.long	0x86
	.byte	0x3
	.byte	0
	.uleb128 0x29
	.long	.LASF175
	.byte	0x1
	.value	0x303
	.long	0xfab
	.uleb128 0x9
	.byte	0x3
	.quad	EApiGpioterfaceValidate
	.uleb128 0xd
	.long	0xf85
	.uleb128 0xa
	.long	0x7ad
	.long	0xfc0
	.uleb128 0xb
	.long	0x86
	.byte	0xb
	.byte	0
	.uleb128 0x29
	.long	.LASF176
	.byte	0x1
	.value	0x30f
	.long	0xfd6
	.uleb128 0x9
	.byte	0x3
	.quad	EApiGpioDevices
	.uleb128 0xd
	.long	0xfb0
	.uleb128 0xa
	.long	0x7e7
	.long	0xfeb
	.uleb128 0xb
	.long	0x86
	.byte	0x4
	.byte	0
	.uleb128 0x29
	.long	.LASF177
	.byte	0x1
	.value	0x3b7
	.long	0x1001
	.uleb128 0x9
	.byte	0x3
	.quad	TestFunctions
	.uleb128 0xd
	.long	0xfdb
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
	.uleb128 0x8
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
	.uleb128 0x9
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
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
	.uleb128 0x11
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x15
	.byte	0
	.uleb128 0x27
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
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
	.uleb128 0x14
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x17
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
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
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
	.uleb128 0x19
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
	.uleb128 0x1a
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x1b
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
	.uleb128 0x1c
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
	.uleb128 0x1d
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
	.uleb128 0x1e
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.byte	0
	.byte	0
	.uleb128 0x1f
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
	.uleb128 0x20
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
	.uleb128 0x21
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
	.uleb128 0x22
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x23
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
	.uleb128 0x24
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
	.byte	0
	.byte	0
	.uleb128 0x25
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x26
	.uleb128 0x2e
	.byte	0
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
	.uleb128 0x27
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
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x28
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
	.uleb128 0x29
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
.LASF138:
	.string	"EApiValidateValuesApi"
.LASF114:
	.string	"EApiGpioType_s"
.LASF115:
	.string	"EApiGpioType_t"
.LASF34:
	.string	"_shortbuf"
.LASF132:
	.string	"cszFormat"
.LASF181:
	.string	"_IO_lock_t"
.LASF47:
	.string	"gp_offset"
.LASF155:
	.string	"stderr"
.LASF23:
	.string	"_IO_buf_end"
.LASF70:
	.string	"DevSize"
.LASF137:
	.string	"EApiValidateStringApi"
.LASF103:
	.string	"EApiStorageType_t"
.LASF170:
	.string	"StorageSize"
.LASF127:
	.string	"cType"
.LASF145:
	.string	"prBuffer2"
.LASF21:
	.string	"_IO_write_end"
.LASF1:
	.string	"unsigned int"
.LASF58:
	.string	"uint32_t"
.LASF85:
	.string	"RByteCnt"
.LASF152:
	.string	"Inputs"
.LASF162:
	.string	"EApiI2CHLReadValidate"
.LASF178:
	.string	"GNU C11 5.2.1 20151010 -mtune=generic -march=x86-64 -g -O0 -fstack-protector-strong"
.LASF60:
	.string	"EApiId_t"
.LASF27:
	.string	"_markers"
.LASF135:
	.string	"pBuffer"
.LASF141:
	.string	"printHex"
.LASF142:
	.string	"ByteCount"
.LASF83:
	.string	"RBufPtr"
.LASF120:
	.string	"EApiCmdTypes_e"
.LASF64:
	.string	"EApiCmdTypes_t"
.LASF165:
	.string	"EApiI2CInterfaceValidate"
.LASF15:
	.string	"_flags"
.LASF158:
	.string	"FailPass"
.LASF117:
	.string	"TestHandler"
.LASF131:
	.string	"StatusCode"
.LASF54:
	.string	"_pos"
.LASF122:
	.string	"PRG_RETURN_OK"
.LASF26:
	.string	"_IO_save_end"
.LASF160:
	.string	"EApiValues"
.LASF177:
	.string	"TestFunctions"
.LASF49:
	.string	"overflow_arg_area"
.LASF79:
	.string	"EApiI2CLLInterfaceValidate_s"
.LASF89:
	.string	"EApiI2CLLInterfaceValidate_t"
.LASF13:
	.string	"long long unsigned int"
.LASF112:
	.string	"pOutputs"
.LASF136:
	.string	"pBufferLen"
.LASF25:
	.string	"_IO_backup_base"
.LASF151:
	.string	"Level"
.LASF36:
	.string	"_offset"
.LASF94:
	.string	"ByteCnt"
.LASF171:
	.string	"BlockLength"
.LASF164:
	.string	"I2CMaxClk"
.LASF29:
	.string	"_fileno"
.LASF130:
	.string	"uiLineNum"
.LASF63:
	.string	"EApiAPI2CExtIndex"
.LASF44:
	.string	"__gnuc_va_list"
.LASF102:
	.string	"Length"
.LASF96:
	.string	"EApiI2CCapValidate_s"
.LASF98:
	.string	"EApiI2CCapValidate_t"
.LASF7:
	.string	"size_t"
.LASF18:
	.string	"_IO_read_base"
.LASF66:
	.string	"DeviceAddr"
.LASF121:
	.string	"ProgramStatusCodes_e"
.LASF52:
	.string	"_next"
.LASF76:
	.string	"EApiValueType_s"
.LASF78:
	.string	"EApiValueType_t"
.LASF125:
	.string	"PRG_RETURN_LIB_UNINIT_ERROR"
.LASF62:
	.string	"EApiAPI2CStdIndex"
.LASF169:
	.string	"StorageValidate"
.LASF118:
	.string	"TestDesc"
.LASF134:
	.string	"szStatusDesc"
.LASF11:
	.string	"char"
.LASF148:
	.string	"EApiValidateStorageApi"
.LASF42:
	.string	"_mode"
.LASF51:
	.string	"_IO_marker"
.LASF16:
	.string	"_IO_read_ptr"
.LASF65:
	.string	"I2CDeviceDesc_s"
.LASF71:
	.string	"I2CDeviceDesc_t"
.LASF133:
	.string	"_ArgList"
.LASF67:
	.string	"PageSize"
.LASF59:
	.string	"EApiStatus_t"
.LASF56:
	.string	"uint8_t"
.LASF129:
	.string	"cszFuncName"
.LASF144:
	.string	"prBuffer1"
.LASF159:
	.string	"EApiStrings"
.LASF163:
	.string	"EApiI2CHLWriteValidate"
.LASF81:
	.string	"WBufPtr"
.LASF55:
	.string	"va_list"
.LASF19:
	.string	"_IO_write_base"
.LASF12:
	.string	"long long int"
.LASF74:
	.string	"Desc"
.LASF24:
	.string	"_IO_save_base"
.LASF104:
	.string	"EApiStorageValidate_s"
.LASF105:
	.string	"EApiStorageValidate_t"
.LASF73:
	.string	"EApiStringType_s"
.LASF75:
	.string	"EApiStringType_t"
.LASF111:
	.string	"pInputs"
.LASF182:
	.string	"siFFormattedMessage_SC"
.LASF139:
	.string	"Value"
.LASF172:
	.string	"StorageCapValidate"
.LASF106:
	.string	"EApiStorageCapValidate_s"
.LASF109:
	.string	"EApiStorageCapValidate_t"
.LASF37:
	.string	"__pad1"
.LASF38:
	.string	"__pad2"
.LASF39:
	.string	"__pad3"
.LASF40:
	.string	"__pad4"
.LASF41:
	.string	"__pad5"
.LASF68:
	.string	"ExtIndx"
.LASF90:
	.string	"EApiI2CHLInterfaceValidate_s"
.LASF95:
	.string	"EApiI2CHLInterfaceValidate_t"
.LASF84:
	.string	"RBufPtrLen"
.LASF101:
	.string	"EApiStorageType_s"
.LASF33:
	.string	"_vtable_offset"
.LASF146:
	.string	"pBuffer3"
.LASF147:
	.string	"pBuffer4"
.LASF61:
	.string	"CreateStringFunction"
.LASF57:
	.string	"uint16_t"
.LASF161:
	.string	"EApiI2CLLValidate"
.LASF153:
	.string	"Outputs"
.LASF116:
	.string	"TestFunctionsTbl_s"
.LASF119:
	.string	"TestFunctionsTbl_t"
.LASF140:
	.string	"TmpStrBuf"
.LASF179:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../EApiValidateAPI.c"
.LASF17:
	.string	"_IO_read_end"
.LASF174:
	.string	"GpioOutputs"
.LASF5:
	.string	"short int"
.LASF108:
	.string	"pBlockLen"
.LASF157:
	.string	"Buffer"
.LASF6:
	.string	"long int"
.LASF180:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux"
.LASF156:
	.string	"LogStream"
.LASF167:
	.string	"EApiI2CBuses"
.LASF46:
	.string	"__va_list_tag"
.LASF107:
	.string	"pStorgeSize"
.LASF124:
	.string	"PRG_RETURN_LIB_INIT_ERROR"
.LASF48:
	.string	"fp_offset"
.LASF77:
	.string	"CreateString"
.LASF72:
	.string	"EApiValidateTestFunction"
.LASF35:
	.string	"_lock"
.LASF166:
	.string	"I2CDevices"
.LASF10:
	.string	"sizetype"
.LASF0:
	.string	"long unsigned int"
.LASF31:
	.string	"_old_offset"
.LASF45:
	.string	"_IO_FILE"
.LASF69:
	.string	"WRecTimems"
.LASF50:
	.string	"reg_save_area"
.LASF86:
	.string	"StatusCode1"
.LASF87:
	.string	"StatusCode2"
.LASF88:
	.string	"StatusCode3"
.LASF128:
	.string	"cszFileName"
.LASF175:
	.string	"EApiGpioterfaceValidate"
.LASF150:
	.string	"Direction"
.LASF2:
	.string	"unsigned char"
.LASF53:
	.string	"_sbuf"
.LASF20:
	.string	"_IO_write_ptr"
.LASF82:
	.string	"WByteCnt"
.LASF110:
	.string	"EApiGpioValidate_s"
.LASF113:
	.string	"EApiGpioValidate_t"
.LASF154:
	.string	"stdout"
.LASF8:
	.string	"__off_t"
.LASF168:
	.string	"EApiStorageDevices"
.LASF4:
	.string	"signed char"
.LASF173:
	.string	"GpioInputs"
.LASF3:
	.string	"short unsigned int"
.LASF97:
	.string	"pValue"
.LASF183:
	.string	"main"
.LASF143:
	.string	"EApiValidateI2CApi"
.LASF92:
	.string	"BufPtr"
.LASF176:
	.string	"EApiGpioDevices"
.LASF126:
	.string	"OutStream"
.LASF80:
	.string	"Address"
.LASF91:
	.string	"Offset"
.LASF28:
	.string	"_chain"
.LASF93:
	.string	"BufPtrLen"
.LASF14:
	.string	"FILE"
.LASF30:
	.string	"_flags2"
.LASF99:
	.string	"EApiI2CType_s"
.LASF100:
	.string	"EApiI2CType_t"
.LASF149:
	.string	"EApiValidateGPIOApi"
.LASF123:
	.string	"PRG_RETURN_ERROR"
.LASF32:
	.string	"_cur_column"
.LASF9:
	.string	"__off64_t"
.LASF43:
	.string	"_unused2"
.LASF22:
	.string	"_IO_buf_base"
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
