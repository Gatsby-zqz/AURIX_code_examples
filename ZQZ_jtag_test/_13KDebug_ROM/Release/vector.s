	.text
	.file	"vector.c"
	.export	_start
	.p2align	2
	.type	_start,@function
	.func	_start
_start:
.Lfunc_begin0:
	.file	1 "/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM/Release/../vector.c"
	.loc	1 6 0
	.cfi_sections .debug_frame
	.cfi_startproc
	.loc	1 8 3 prologue_end
	//S_INLINE
	mov R0,#0xD0010000
	//E_INLINE
	.loc	1 9 3
	//S_INLINE
	mov sp,r0
	//E_INLINE
	.loc	1 11 3
	//S_INLINE
	mov R4,r0
	//E_INLINE
	.loc	1 12 3
	//S_INLINE
	mov R5,r0
	//E_INLINE
	.loc	1 13 3
	//S_INLINE
	mov R11,r0
	//E_INLINE
	.loc	1 14 3
	//S_INLINE
	mov R12,r0
	//E_INLINE
	.loc	1 16 3
	//S_INLINE
	ljmp startup
	//E_INLINE
	.loc	1 17 1
	JMP lr
.Ltmp0:
.Lendfunc0:
	.endfunc
.Lfunc_end0:
	.size	_start, .Lfunc_end0-_start
	.cfi_endproc

	.section	.debug_abbrev,"",@progbits
	.byte	1
	.byte	17
	.byte	1
	.byte	37
	.byte	14
	.byte	19
	.byte	5
	.byte	3
	.byte	14
	.byte	16
	.byte	6
	.byte	27
	.byte	14
	.byte	17
	.byte	1
	.byte	18
	.byte	1
	.byte	0
	.byte	0
	.byte	2
	.byte	46
	.byte	0
	.byte	17
	.byte	1
	.byte	18
	.byte	1
	.byte	64
	.byte	10
	.byte	3
	.byte	14
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	63
	.byte	12
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_info,"",@progbits
.Lcu_begin0:
	.long	.Ldebug_info_end0-.Ldebug_info_start0
.Ldebug_info_start0:
	.short	3
	.long	.debug_abbrev
	.byte	4
	.byte	1
	.long	.Linfo_string0
	.short	12
	.long	.Linfo_string1
	.long	.Lline_table_start0
	.long	.Linfo_string2
	.long	.Lfunc_begin0
	.long	.Lfunc_end0
	.byte	2
	.long	.Lfunc_begin0
	.long	.Lfunc_end0
	.byte	1
	.byte	94
	.long	.Linfo_string3
	.byte	1
	.byte	5
	.byte	1
	.byte	0
.Ldebug_info_end0:
	.section	.debug_str,"MS",@progbits,1
.Linfo_string0:
	.asciz	"ChipON (Compiler) clang version 14.0.6 (2024/05/11-09:43 90e9b34a96c875fecc03e39c9fcabc720632a80b)"
.Linfo_string1:
	.asciz	"vector.c"
.Linfo_string2:
	.asciz	"/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM/Release"
.Linfo_string3:
	.asciz	"_start"
	.ident	"ChipON (Compiler) clang version 14.0.6 (2024/05/11-09:43 90e9b34a96c875fecc03e39c9fcabc720632a80b)"
	.section	".note.GNU-stack","",@progbits
	.section	.debug_line,"",@progbits
.Lline_table_start0:
