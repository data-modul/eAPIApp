	.file	"DbgChk.c"
	.text
.Ltext0:
	.globl	ErrorLookupA
	.section	.rodata
.LC0:
	.string	"NOT_INITIALIZED"
.LC1:
	.string	"INITIALIZED"
.LC2:
	.string	"ALLOC_ERROR"
.LC3:
	.string	"DRIVER_TIMEOUT"
.LC4:
	.string	"INVALID_PARAMETER"
.LC5:
	.string	"INVALID_BLOCK_ALIGNMENT"
.LC6:
	.string	"INVALID_BLOCK_LENGTH"
.LC7:
	.string	"INVALID_DIRECTION"
.LC8:
	.string	"INVALID_BITMASK"
.LC9:
	.string	"RUNNING"
.LC10:
	.string	"UNSUPPORTED"
.LC11:
	.string	"NOT_FOUND"
.LC12:
	.string	"TIMEOUT"
.LC13:
	.string	"BUSY_COLLISION"
.LC14:
	.string	"READ_ERROR"
.LC15:
	.string	"WRITE_ERROR"
.LC16:
	.string	"MORE_DATA"
.LC17:
	.string	"ERROR"
.LC18:
	.string	"SUCCESS"
	.align 32
	.type	ErrorLookupA, @object
	.size	ErrorLookupA, 304
ErrorLookupA:
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
	.text
	.globl	EApiGetErrorStringA
	.type	EApiGetErrorStringA, @function
EApiGetErrorStringA:
.LFB2:
	.file 1 "/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/DbgChk.c"
	.loc 1 70 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	.loc 1 76 0
	movq	-24(%rbp), %rax
	movq	$0, (%rax)
	.loc 1 77 0
	movl	$19, -12(%rbp)
	.loc 1 78 0
	movq	$ErrorLookupA, -8(%rbp)
	.loc 1 77 0
	jmp	.L2
.L5:
	.loc 1 83 0
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	-28(%rbp), %eax
	jne	.L3
	.loc 1 84 0
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	.loc 1 85 0
	movl	$0, %eax
	jmp	.L4
.L3:
	.loc 1 79 0
	addq	$16, -8(%rbp)
.L2:
	.loc 1 79 0 is_stmt 0 discriminator 1
	movl	-12(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -12(%rbp)
	.loc 1 77 0 is_stmt 1 discriminator 1
	testl	%eax, %eax
	jne	.L5
	.loc 1 88 0
	movl	$-3841, %eax
.L4:
	.loc 1 89 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	EApiGetErrorStringA, .-EApiGetErrorStringA
	.globl	GetLastOccurance
	.type	GetLastOccurance, @function
GetLastOccurance:
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
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	.loc 1 96 0
	jmp	.L7
.L10:
	.loc 1 97 0
	movq	-24(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, -24(%rbp)
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	cmpl	$47, %eax
	je	.L9
	cmpl	$92, %eax
	jne	.L8
.L9:
	.loc 1 100 0
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
.L8:
	.loc 1 102 0
	nop
.L7:
	.loc 1 96 0
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L10
	.loc 1 105 0
	movq	-8(%rbp), %rax
	.loc 1 106 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	GetLastOccurance, .-GetLastOccurance
	.globl	cszLogFormat
	.section	.rodata
	.align 16
	.type	cszLogFormat, @object
	.size	cszLogFormat, 25
cszLogFormat:
	.string	"%c%04i %-15.15s %-30s | "
.LC19:
	.string	"%-25s | "
	.text
	.globl	siFormattedMessage_M2
	.type	siFormattedMessage_M2, @function
siFormattedMessage_M2:
.LFB4:
	.loc 1 120 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$272, %rsp
	movq	%rsi, -240(%rbp)
	movq	%rdx, -248(%rbp)
	movl	%ecx, -232(%rbp)
	movq	%r8, -256(%rbp)
	movq	%r9, -264(%rbp)
	testb	%al, %al
	je	.L13
	movaps	%xmm0, -128(%rbp)
	movaps	%xmm1, -112(%rbp)
	movaps	%xmm2, -96(%rbp)
	movaps	%xmm3, -80(%rbp)
	movaps	%xmm4, -64(%rbp)
	movaps	%xmm5, -48(%rbp)
	movaps	%xmm6, -32(%rbp)
	movaps	%xmm7, -16(%rbp)
.L13:
	movb	%dil, -228(%rbp)
	.loc 1 120 0
	movq	%fs:40, %rax
	movq	%rax, -184(%rbp)
	xorl	%eax, %eax
	.loc 1 124 0
	movl	$48, -208(%rbp)
	movl	$48, -204(%rbp)
	leaq	16(%rbp), %rax
	movq	%rax, -200(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, -192(%rbp)
	.loc 1 126 0
	movq	-240(%rbp), %rax
	movq	%rax, %rdi
	call	GetLastOccurance
	movq	%rax, %rsi
	movsbl	-228(%rbp), %eax
	movq	-248(%rbp), %rcx
	movl	-232(%rbp), %edx
	movq	%rcx, %r8
	movq	%rsi, %rcx
	movl	%eax, %esi
	movl	$cszLogFormat, %edi
	movl	$0, %eax
	call	printf
	movl	%eax, -212(%rbp)
	.loc 1 133 0
	movq	-256(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC19, %edi
	movl	$0, %eax
	call	printf
	.loc 1 134 0
	leaq	-208(%rbp), %rdx
	movq	-264(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	vprintf
	addl	%eax, -212(%rbp)
	.loc 1 136 0
	movl	-212(%rbp), %eax
	.loc 1 137 0
	movq	-184(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L15
	call	__stack_chk_fail
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	siFormattedMessage_M2, .-siFormattedMessage_M2
	.section	.rodata
.LC20:
	.string	"               0x%08X | "
	.text
	.globl	siFormattedMessage_SC
	.type	siFormattedMessage_SC, @function
siFormattedMessage_SC:
.LFB5:
	.loc 1 150 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$272, %rsp
	movq	%rsi, -240(%rbp)
	movq	%rdx, -248(%rbp)
	movl	%ecx, -232(%rbp)
	movl	%r8d, -252(%rbp)
	movq	%r9, -264(%rbp)
	testb	%al, %al
	je	.L17
	movaps	%xmm0, -128(%rbp)
	movaps	%xmm1, -112(%rbp)
	movaps	%xmm2, -96(%rbp)
	movaps	%xmm3, -80(%rbp)
	movaps	%xmm4, -64(%rbp)
	movaps	%xmm5, -48(%rbp)
	movaps	%xmm6, -32(%rbp)
	movaps	%xmm7, -16(%rbp)
.L17:
	movb	%dil, -228(%rbp)
	.loc 1 150 0
	movq	%fs:40, %rax
	movq	%rax, -184(%rbp)
	xorl	%eax, %eax
	.loc 1 154 0
	movl	$48, -208(%rbp)
	movl	$48, -204(%rbp)
	leaq	16(%rbp), %rax
	movq	%rax, -200(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, -192(%rbp)
	.loc 1 155 0
	movl	-252(%rbp), %edx
	leaq	-216(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	EApiGetErrorStringA
	.loc 1 156 0
	movq	-240(%rbp), %rax
	movq	%rax, %rdi
	call	GetLastOccurance
	movq	%rax, %rsi
	movsbl	-228(%rbp), %eax
	movq	-248(%rbp), %rcx
	movl	-232(%rbp), %edx
	movq	%rcx, %r8
	movq	%rsi, %rcx
	movl	%eax, %esi
	movl	$cszLogFormat, %edi
	movl	$0, %eax
	call	printf
	movl	%eax, -220(%rbp)
	.loc 1 163 0
	movq	-216(%rbp), %rax
	testq	%rax, %rax
	jne	.L18
	.loc 1 164 0
	movl	-252(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC20, %edi
	movl	$0, %eax
	call	printf
	jmp	.L19
.L18:
	.loc 1 166 0
	movq	-216(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC19, %edi
	movl	$0, %eax
	call	printf
.L19:
	.loc 1 168 0
	leaq	-208(%rbp), %rdx
	movq	-264(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	vprintf
	addl	%eax, -220(%rbp)
	.loc 1 170 0
	movl	-220(%rbp), %eax
	.loc 1 171 0
	movq	-184(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L21
	call	__stack_chk_fail
.L21:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	siFormattedMessage_SC, .-siFormattedMessage_SC
.Letext0:
	.file 2 "<built-in>"
	.file 3 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h"
	.file 4 "/usr/include/stdio.h"
	.file 5 "/usr/include/stdint.h"
	.file 6 "../../../include/EApi.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x383
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF42
	.byte	0xc
	.long	.LASF43
	.long	.LASF44
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF1
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF2
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x4
	.byte	0x8
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF8
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF9
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF10
	.uleb128 0x5
	.long	.LASF15
	.byte	0x3
	.byte	0x28
	.long	0x8e
	.uleb128 0x6
	.long	0x9e
	.long	0x9e
	.uleb128 0x7
	.long	0x65
	.byte	0
	.byte	0
	.uleb128 0x8
	.long	.LASF19
	.byte	0x18
	.byte	0x2
	.byte	0
	.long	0xdb
	.uleb128 0x9
	.long	.LASF11
	.byte	0x2
	.byte	0
	.long	0x3b
	.byte	0
	.uleb128 0x9
	.long	.LASF12
	.byte	0x2
	.byte	0
	.long	0x3b
	.byte	0x4
	.uleb128 0x9
	.long	.LASF13
	.byte	0x2
	.byte	0
	.long	0x6c
	.byte	0x8
	.uleb128 0x9
	.long	.LASF14
	.byte	0x2
	.byte	0
	.long	0x6c
	.byte	0x10
	.byte	0
	.uleb128 0xa
	.byte	0x8
	.long	0xe1
	.uleb128 0xb
	.long	0x6e
	.uleb128 0x5
	.long	.LASF16
	.byte	0x4
	.byte	0x4f
	.long	0x83
	.uleb128 0x5
	.long	.LASF17
	.byte	0x5
	.byte	0x33
	.long	0x3b
	.uleb128 0x5
	.long	.LASF18
	.byte	0x6
	.byte	0x93
	.long	0xf1
	.uleb128 0x8
	.long	.LASF20
	.byte	0x10
	.byte	0x1
	.byte	0x26
	.long	0x12c
	.uleb128 0x9
	.long	.LASF21
	.byte	0x1
	.byte	0x27
	.long	0x12c
	.byte	0
	.uleb128 0x9
	.long	.LASF22
	.byte	0x1
	.byte	0x28
	.long	0x131
	.byte	0x8
	.byte	0
	.uleb128 0xb
	.long	0xfc
	.uleb128 0xb
	.long	0xdb
	.uleb128 0x5
	.long	.LASF23
	.byte	0x1
	.byte	0x29
	.long	0x107
	.uleb128 0xc
	.long	.LASF26
	.byte	0x1
	.byte	0x42
	.long	0xfc
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x199
	.uleb128 0xd
	.long	.LASF24
	.byte	0x1
	.byte	0x43
	.long	0x19f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xd
	.long	.LASF21
	.byte	0x1
	.byte	0x44
	.long	0xfc
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0xe
	.string	"i"
	.byte	0x1
	.byte	0x47
	.long	0x3b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xf
	.long	.LASF25
	.byte	0x1
	.byte	0x48
	.long	0x1a4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xa
	.byte	0x8
	.long	0xdb
	.uleb128 0xb
	.long	0x199
	.uleb128 0xa
	.byte	0x8
	.long	0x1aa
	.uleb128 0xb
	.long	0x136
	.uleb128 0xc
	.long	.LASF27
	.byte	0x1
	.byte	0x5b
	.long	0xdb
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x1ed
	.uleb128 0xd
	.long	.LASF28
	.byte	0x1
	.byte	0x5c
	.long	0xdb
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xf
	.long	.LASF29
	.byte	0x1
	.byte	0x5f
	.long	0xdb
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x10
	.long	.LASF30
	.byte	0x1
	.byte	0x6f
	.long	0x34
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x288
	.uleb128 0xd
	.long	.LASF31
	.byte	0x1
	.byte	0x70
	.long	0x6e
	.uleb128 0x3
	.byte	0x91
	.sleb128 -244
	.uleb128 0xd
	.long	.LASF32
	.byte	0x1
	.byte	0x71
	.long	0xdb
	.uleb128 0x3
	.byte	0x91
	.sleb128 -256
	.uleb128 0xd
	.long	.LASF33
	.byte	0x1
	.byte	0x72
	.long	0xdb
	.uleb128 0x3
	.byte	0x91
	.sleb128 -264
	.uleb128 0xd
	.long	.LASF34
	.byte	0x1
	.byte	0x73
	.long	0x3b
	.uleb128 0x3
	.byte	0x91
	.sleb128 -248
	.uleb128 0xd
	.long	.LASF35
	.byte	0x1
	.byte	0x74
	.long	0xdb
	.uleb128 0x3
	.byte	0x91
	.sleb128 -272
	.uleb128 0xd
	.long	.LASF36
	.byte	0x1
	.byte	0x75
	.long	0xdb
	.uleb128 0x3
	.byte	0x91
	.sleb128 -280
	.uleb128 0x11
	.uleb128 0xe
	.string	"Ret"
	.byte	0x1
	.byte	0x79
	.long	0x34
	.uleb128 0x3
	.byte	0x91
	.sleb128 -228
	.uleb128 0xf
	.long	.LASF37
	.byte	0x1
	.byte	0x7a
	.long	0xe6
	.uleb128 0x3
	.byte	0x91
	.sleb128 -224
	.byte	0
	.uleb128 0x10
	.long	.LASF38
	.byte	0x1
	.byte	0x8d
	.long	0x34
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x332
	.uleb128 0xd
	.long	.LASF31
	.byte	0x1
	.byte	0x8e
	.long	0x6e
	.uleb128 0x3
	.byte	0x91
	.sleb128 -244
	.uleb128 0xd
	.long	.LASF32
	.byte	0x1
	.byte	0x8f
	.long	0xdb
	.uleb128 0x3
	.byte	0x91
	.sleb128 -256
	.uleb128 0xd
	.long	.LASF33
	.byte	0x1
	.byte	0x90
	.long	0xdb
	.uleb128 0x3
	.byte	0x91
	.sleb128 -264
	.uleb128 0xd
	.long	.LASF34
	.byte	0x1
	.byte	0x91
	.long	0x3b
	.uleb128 0x3
	.byte	0x91
	.sleb128 -248
	.uleb128 0xd
	.long	.LASF21
	.byte	0x1
	.byte	0x92
	.long	0xfc
	.uleb128 0x3
	.byte	0x91
	.sleb128 -268
	.uleb128 0xd
	.long	.LASF36
	.byte	0x1
	.byte	0x93
	.long	0xdb
	.uleb128 0x3
	.byte	0x91
	.sleb128 -280
	.uleb128 0x11
	.uleb128 0xe
	.string	"Ret"
	.byte	0x1
	.byte	0x97
	.long	0x34
	.uleb128 0x3
	.byte	0x91
	.sleb128 -236
	.uleb128 0xf
	.long	.LASF37
	.byte	0x1
	.byte	0x98
	.long	0xe6
	.uleb128 0x3
	.byte	0x91
	.sleb128 -224
	.uleb128 0xf
	.long	.LASF39
	.byte	0x1
	.byte	0x99
	.long	0xdb
	.uleb128 0x3
	.byte	0x91
	.sleb128 -232
	.byte	0
	.uleb128 0x6
	.long	0x136
	.long	0x342
	.uleb128 0x7
	.long	0x65
	.byte	0x12
	.byte	0
	.uleb128 0x12
	.long	.LASF40
	.byte	0x1
	.byte	0x2c
	.long	0x357
	.uleb128 0x9
	.byte	0x3
	.quad	ErrorLookupA
	.uleb128 0xb
	.long	0x332
	.uleb128 0x6
	.long	0x6e
	.long	0x36c
	.uleb128 0x7
	.long	0x65
	.byte	0x18
	.byte	0
	.uleb128 0x12
	.long	.LASF41
	.byte	0x1
	.byte	0x6b
	.long	0x381
	.uleb128 0x9
	.byte	0x3
	.quad	cszLogFormat
	.uleb128 0xb
	.long	0x35c
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
	.uleb128 0x3
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
	.uleb128 0x4
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x5
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
	.uleb128 0x6
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
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
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
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
	.uleb128 0x2117
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
	.uleb128 0xf
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
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x18
	.byte	0
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
	.uleb128 0xb
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
.LASF34:
	.string	"uiLineNum"
.LASF40:
	.string	"ErrorLookupA"
.LASF28:
	.string	"czFilename"
.LASF24:
	.string	"pszString"
.LASF3:
	.string	"short unsigned int"
.LASF26:
	.string	"EApiGetErrorStringA"
.LASF32:
	.string	"cszFileName"
.LASF42:
	.string	"GNU C11 5.2.1 20151010 -mtune=generic -march=x86-64 -g -O0 -fstack-protector-strong"
.LASF15:
	.string	"__gnuc_va_list"
.LASF2:
	.string	"unsigned char"
.LASF25:
	.string	"pErrorLookup"
.LASF0:
	.string	"long unsigned int"
.LASF22:
	.string	"ErrorString"
.LASF29:
	.string	"cszLPos"
.LASF41:
	.string	"cszLogFormat"
.LASF16:
	.string	"va_list"
.LASF36:
	.string	"cszFormat"
.LASF27:
	.string	"GetLastOccurance"
.LASF30:
	.string	"siFormattedMessage_M2"
.LASF23:
	.string	"ErrorLookupTbl_t"
.LASF18:
	.string	"EApiStatus_t"
.LASF11:
	.string	"gp_offset"
.LASF37:
	.string	"_ArgList"
.LASF1:
	.string	"unsigned int"
.LASF14:
	.string	"reg_save_area"
.LASF10:
	.string	"long long unsigned int"
.LASF13:
	.string	"overflow_arg_area"
.LASF31:
	.string	"cType"
.LASF7:
	.string	"sizetype"
.LASF9:
	.string	"long long int"
.LASF8:
	.string	"char"
.LASF38:
	.string	"siFormattedMessage_SC"
.LASF33:
	.string	"cszFuncName"
.LASF20:
	.string	"ErrorLookupTbl_S"
.LASF19:
	.string	"__va_list_tag"
.LASF12:
	.string	"fp_offset"
.LASF5:
	.string	"short int"
.LASF17:
	.string	"uint32_t"
.LASF6:
	.string	"long int"
.LASF39:
	.string	"szStatusDesc"
.LASF4:
	.string	"signed char"
.LASF21:
	.string	"StatusCode"
.LASF35:
	.string	"csz2ndValue"
.LASF43:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/DbgChk.c"
.LASF44:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux"
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
