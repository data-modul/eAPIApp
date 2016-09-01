	.file	"EApiAHStorage.c"
	.text
.Ltext0:
	.section	.rodata
.LC0:
	.string	"%s\n"
.LC1:
	.string	"EApiAHWriteStorage"
	.align 8
.LC2:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHStorage.c"
.LC3:
	.string	"(pBuffer==NULL)"
.LC4:
	.string	"(ByteCnt==0)"
.LC5:
	.string	"((ByteOffset+ByteCnt)>MaxLen)"
	.align 8
.LC6:
	.string	"((AdjOffset+AdjLength)>MaxLen)"
.LC7:
	.string	"Allocating Page Buffer"
	.text
	.globl	EApiAHWriteStorage
	.type	EApiAHWriteStorage, @function
EApiAHWriteStorage:
.LFB2:
	.file 1 "/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHStorage.c"
	.loc 1 46 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -52(%rbp)
	movl	%esi, -56(%rbp)
	movq	%rdx, -64(%rbp)
	movl	%ecx, -68(%rbp)
	.loc 1 46 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 47 0
	movl	$0, -32(%rbp)
	.loc 1 49 0
	movl	-56(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	-68(%rbp), %eax
	movl	%eax, -24(%rbp)
	.loc 1 50 0
	movq	$0, -16(%rbp)
	.loc 1 51 0
	movl	$0, -20(%rbp)
	.loc 1 53 0
	cmpq	$0, -64(%rbp)
	jne	.L2
	.loc 1 53 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC3
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$57, %ecx
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -32(%rbp)
	jmp	.L13
.L2:
	.loc 1 58 0 is_stmt 1
	cmpl	$0, -68(%rbp)
	jne	.L4
	.loc 1 58 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC4
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$62, %ecx
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -32(%rbp)
	jmp	.L13
.L4:
	.loc 1 64 0 is_stmt 1
	leaq	-36(%rbp), %rdx
	leaq	-40(%rbp), %rcx
	movl	-52(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	EApiStorageCap
	movl	%eax, -32(%rbp)
	.loc 1 65 0
	cmpl	$0, -32(%rbp)
	jne	.L17
	.loc 1 69 0
	movl	-56(%rbp), %edx
	movl	-68(%rbp), %eax
	addl	%eax, %edx
	movl	-40(%rbp), %eax
	cmpl	%eax, %edx
	jbe	.L6
	.loc 1 69 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC5
	movl	$.LC0, %r9d
	movl	$-257, %r8d
	movl	$73, %ecx
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-257, -32(%rbp)
	jmp	.L13
.L6:
	.loc 1 75 0 is_stmt 1
	movl	-36(%rbp), %ecx
	movl	-56(%rbp), %eax
	movl	$0, %edx
	divl	%ecx
	movl	%edx, %eax
	testl	%eax, %eax
	je	.L7
	.loc 1 76 0
	movl	-36(%rbp), %ecx
	movl	-56(%rbp), %eax
	movl	$0, %edx
	divl	%ecx
	movl	%edx, -20(%rbp)
	.loc 1 77 0
	movl	-56(%rbp), %eax
	subl	-20(%rbp), %eax
	movl	%eax, -28(%rbp)
	.loc 1 78 0
	movl	-68(%rbp), %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -24(%rbp)
.L7:
	.loc 1 80 0
	movl	-36(%rbp), %ecx
	movl	-24(%rbp), %eax
	movl	$0, %edx
	divl	%ecx
	movl	%edx, %eax
	testl	%eax, %eax
	je	.L8
	.loc 1 82 0
	movl	-36(%rbp), %ecx
	movl	-24(%rbp), %eax
	movl	$0, %edx
	divl	%ecx
	movl	-24(%rbp), %eax
	subl	%edx, %eax
	movl	%eax, %edx
	movl	-36(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -24(%rbp)
.L8:
	.loc 1 84 0
	movl	-24(%rbp), %eax
	cmpl	-68(%rbp), %eax
	je	.L9
	.loc 1 88 0
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%eax, %edx
	movl	-40(%rbp), %eax
	cmpl	%eax, %edx
	jbe	.L10
	.loc 1 88 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC6
	movl	$.LC0, %r9d
	movl	$-3841, %r8d
	movl	$92, %ecx
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-3841, -32(%rbp)
	jmp	.L13
.L10:
	.loc 1 93 0 is_stmt 1
	movl	-24(%rbp), %eax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -16(%rbp)
	.loc 1 94 0
	cmpq	$0, -16(%rbp)
	jne	.L11
	.loc 1 94 0 is_stmt 0 discriminator 1
	subq	$8, %rsp
	pushq	$.LC7
	movl	$.LC0, %r9d
	movl	$-3, %r8d
	movl	$99, %ecx
	movl	$.LC1, %edx
	movl	$.LC2, %esi
	movl	$69, %edi
	movl	$0, %eax
	call	siFormattedMessage_SC
	addq	$16, %rsp
	movl	$-3, -32(%rbp)
	jmp	.L13
.L11:
	.loc 1 100 0 is_stmt 1
	movl	-24(%rbp), %edi
	movl	-24(%rbp), %ecx
	movq	-16(%rbp), %rdx
	movl	-28(%rbp), %esi
	movl	-52(%rbp), %eax
	movl	%edi, %r8d
	movl	%eax, %edi
	call	EApiStorageAreaRead
	movl	%eax, -32(%rbp)
	.loc 1 101 0
	cmpl	$0, -32(%rbp)
	jne	.L18
	.loc 1 103 0
	movl	-68(%rbp), %edx
	movl	-20(%rbp), %ecx
	movq	-16(%rbp), %rax
	addq	%rax, %rcx
	movq	-64(%rbp), %rax
	movq	%rax, %rsi
	movq	%rcx, %rdi
	call	memcpy
	.loc 1 104 0
	movl	-24(%rbp), %ecx
	movq	-16(%rbp), %rdx
	movl	-28(%rbp), %esi
	movl	-52(%rbp), %eax
	movl	%eax, %edi
	call	EApiStorageAreaWrite
	movl	%eax, -32(%rbp)
	jmp	.L13
.L9:
	.loc 1 106 0
	movl	-68(%rbp), %ecx
	movq	-64(%rbp), %rdx
	movl	-56(%rbp), %esi
	movl	-52(%rbp), %eax
	movl	%eax, %edi
	call	EApiStorageAreaWrite
	movl	%eax, -32(%rbp)
	jmp	.L13
.L3:
.L17:
	.loc 1 66 0
	nop
	jmp	.L13
.L18:
	.loc 1 102 0
	nop
.L13:
	.loc 1 110 0
	cmpq	$0, -16(%rbp)
	je	.L14
	.loc 1 110 0 is_stmt 0 discriminator 1
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free
.L14:
	.loc 1 112 0 is_stmt 1
	movl	-32(%rbp), %eax
	.loc 1 113 0
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L16
	call	__stack_chk_fail
.L16:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	EApiAHWriteStorage, .-EApiAHWriteStorage
.Letext0:
	.file 2 "/usr/include/stdint.h"
	.file 3 "../../../include/EApi.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x19f
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF28
	.byte	0xc
	.long	.LASF29
	.long	.LASF30
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
	.long	.LASF11
	.byte	0x2
	.byte	0x33
	.long	0x3b
	.uleb128 0x5
	.long	.LASF12
	.byte	0x2
	.byte	0x41
	.long	0x50
	.uleb128 0x5
	.long	.LASF13
	.byte	0x2
	.byte	0x7a
	.long	0x2d
	.uleb128 0x5
	.long	.LASF14
	.byte	0x3
	.byte	0x93
	.long	0x83
	.uleb128 0x5
	.long	.LASF15
	.byte	0x3
	.byte	0x94
	.long	0x83
	.uleb128 0x6
	.long	0x83
	.uleb128 0x7
	.long	.LASF31
	.byte	0x1
	.byte	0x28
	.long	0xa4
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x19c
	.uleb128 0x8
	.string	"Id"
	.byte	0x1
	.byte	0x29
	.long	0xaf
	.uleb128 0x3
	.byte	0x91
	.sleb128 -68
	.uleb128 0x9
	.long	.LASF16
	.byte	0x1
	.byte	0x2a
	.long	0xba
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x9
	.long	.LASF17
	.byte	0x1
	.byte	0x2b
	.long	0x6c
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x9
	.long	.LASF18
	.byte	0x1
	.byte	0x2c
	.long	0xba
	.uleb128 0x3
	.byte	0x91
	.sleb128 -84
	.uleb128 0xa
	.long	.LASF19
	.byte	0x1
	.byte	0x2f
	.long	0xa4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0xa
	.long	.LASF20
	.byte	0x1
	.byte	0x30
	.long	0x83
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xa
	.long	.LASF21
	.byte	0x1
	.byte	0x30
	.long	0x83
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0xa
	.long	.LASF22
	.byte	0x1
	.byte	0x31
	.long	0x83
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0xa
	.long	.LASF23
	.byte	0x1
	.byte	0x31
	.long	0x83
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xa
	.long	.LASF24
	.byte	0x1
	.byte	0x32
	.long	0x19c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xa
	.long	.LASF25
	.byte	0x1
	.byte	0x33
	.long	0x83
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0xb
	.long	.LASF26
	.byte	0x1
	.byte	0x6d
	.quad	.L13
	.uleb128 0xb
	.long	.LASF27
	.byte	0x1
	.byte	0x6c
	.quad	.L3
	.byte	0
	.uleb128 0xc
	.byte	0x8
	.long	0x8e
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
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
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
	.uleb128 0x8
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
	.uleb128 0x9
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
	.uleb128 0xa
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
	.uleb128 0xb
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
	.uleb128 0xc
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
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
.LASF22:
	.string	"AdjOffset"
.LASF14:
	.string	"EApiStatus_t"
.LASF13:
	.string	"uintptr_t"
.LASF23:
	.string	"AdjLength"
.LASF20:
	.string	"MaxLen"
.LASF26:
	.string	"ExitPoint"
.LASF18:
	.string	"ByteCnt"
.LASF28:
	.string	"GNU C11 5.2.1 20151010 -mtune=generic -march=x86-64 -g -O0 -fstack-protector-strong"
.LASF2:
	.string	"unsigned char"
.LASF25:
	.string	"BufferOffset"
.LASF0:
	.string	"long unsigned int"
.LASF3:
	.string	"short unsigned int"
.LASF31:
	.string	"EApiAHWriteStorage"
.LASF15:
	.string	"EApiId_t"
.LASF27:
	.string	"ErrorExit"
.LASF29:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux/../../common/EApiAHStorage.c"
.LASF1:
	.string	"unsigned int"
.LASF10:
	.string	"long long unsigned int"
.LASF17:
	.string	"pBuffer"
.LASF7:
	.string	"sizetype"
.LASF9:
	.string	"long long int"
.LASF21:
	.string	"alignment"
.LASF8:
	.string	"char"
.LASF16:
	.string	"ByteOffset"
.LASF12:
	.string	"int_least8_t"
.LASF5:
	.string	"short int"
.LASF24:
	.string	"pLclBuffer"
.LASF11:
	.string	"uint32_t"
.LASF6:
	.string	"long int"
.LASF4:
	.string	"signed char"
.LASF19:
	.string	"StatusCode"
.LASF30:
	.string	"/development/eAPI/eapidk-code/apps/EApiValidateAPI/linux"
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
