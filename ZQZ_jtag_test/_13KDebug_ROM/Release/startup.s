	.text
	.file	"startup.c"
	.file	1 "/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM/Release/../startup.c"
	.section	.text.startup,"ax",@progbits
	.export	startup
	.p2align	2
	.type	startup,@function
	.func	startup
startup:
.Lfunc_begin0:
	.loc	1 24 0
	.cfi_sections .debug_frame
	.cfi_startproc
	PUSH lr
	.cfi_def_cfa_offset 4
	SUB sp, #4
	.loc	1 32 2 prologue_end
	LD r5, #__data_end__
.Ltmp0:
	LD r0, #__data_start__
.Ltmp1:
	CMP r0, r5
.Ltmp2:
	JC .LBB0_4
.Ltmp3:
	ADD r4, r0, #4
	CMP r5, r4
	JHI .LBB0_3
.Ltmp4:
	.loc	1 0 2 is_stmt 0
	MOV r5, r4
.Ltmp5:
.LBB0_3:
	.loc	1 32 2
	NOT r4, r0
	ADD r5, r4, r5
	ADD r2, r5, #4
	LD r5, #-4
	ANL r2, r5
.Ltmp6:
	.loc	1 33 10 is_stmt 1
	LD r1, #__text_end__
	LD r5, #memcpy
	LJMP r5
.Ltmp7:
.LBB0_4:
	.loc	1 40 2
	LD r5, #__bss_end__
	LD r0, #__bss_start__
.Ltmp8:
	CMP r0, r5
	JC .LBB0_8
.Ltmp9:
	ADD r4, r0, #4
	CMP r5, r4
	JHI .LBB0_7
.Ltmp10:
	.loc	1 0 2 is_stmt 0
	MOV r5, r4
.Ltmp11:
.LBB0_7:
	.loc	1 40 2
	NOT r4, r0
	ADD r5, r4, r5
	ADD r2, r5, #4
	LD r5, #-4
	ANL r2, r5
	MOV r1, #0
.Ltmp12:
	.loc	1 41 10 is_stmt 1
	LD r5, #memset
	LJMP r5
.Ltmp13:
.LBB0_8:
	.loc	1 45 2
	LD r5, #main
	LJMP r5
.LBB0_9:
	.loc	1 46 2
	SJMP .LBB0_9
.Ltmp14:
.Lendfunc0:
	.endfunc
.Lfunc_end0:
	.size	startup, .Lfunc_end0-startup
	.cfi_endproc

	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
	.long	.Ltmp0-.Lfunc_begin0
	.long	.Ltmp5-.Lfunc_begin0
	.short	1
	.byte	85
	.long	0
	.long	0
.Ldebug_loc1:
	.long	.Ltmp1-.Lfunc_begin0
	.long	.Ltmp7-.Lfunc_begin0
	.short	1
	.byte	80
	.long	.Ltmp8-.Lfunc_begin0
	.long	.Ltmp13-.Lfunc_begin0
	.short	1
	.byte	80
	.long	0
	.long	0
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
	.byte	52
	.byte	0
	.byte	3
	.byte	14
	.byte	73
	.byte	19
	.byte	63
	.byte	12
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	60
	.byte	12
	.byte	2
	.byte	10
	.byte	0
	.byte	0
	.byte	3
	.byte	36
	.byte	0
	.byte	3
	.byte	14
	.byte	62
	.byte	11
	.byte	11
	.byte	11
	.byte	0
	.byte	0
	.byte	4
	.byte	15
	.byte	0
	.byte	73
	.byte	19
	.byte	0
	.byte	0
	.byte	5
	.byte	46
	.byte	1
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
	.byte	39
	.byte	12
	.byte	73
	.byte	19
	.byte	63
	.byte	12
	.byte	0
	.byte	0
	.byte	6
	.byte	52
	.byte	0
	.byte	2
	.byte	6
	.byte	3
	.byte	14
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	73
	.byte	19
	.byte	0
	.byte	0
	.byte	7
	.byte	52
	.byte	0
	.byte	3
	.byte	14
	.byte	58
	.byte	11
	.byte	59
	.byte	11
	.byte	73
	.byte	19
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
	.long	.Linfo_string3
	.long	57
	.byte	1
	.byte	1
	.byte	12
	.byte	1
	.byte	5
	.byte	3
	.long	__text_end__
	.byte	3
	.long	.Linfo_string4
	.byte	7
	.byte	4
	.byte	2
	.long	.Linfo_string5
	.long	57
	.byte	1
	.byte	1
	.byte	13
	.byte	1
	.byte	5
	.byte	3
	.long	__bss_start__
	.byte	2
	.long	.Linfo_string6
	.long	57
	.byte	1
	.byte	1
	.byte	14
	.byte	1
	.byte	5
	.byte	3
	.long	__bss_end__
	.byte	2
	.long	.Linfo_string7
	.long	57
	.byte	1
	.byte	1
	.byte	15
	.byte	1
	.byte	5
	.byte	3
	.long	__data_start__
	.byte	2
	.long	.Linfo_string8
	.long	57
	.byte	1
	.byte	1
	.byte	16
	.byte	1
	.byte	5
	.byte	3
	.long	__data_end__
	.byte	4
	.long	57
	.byte	5
	.long	.Lfunc_begin0
	.long	.Lfunc_end0
	.byte	1
	.byte	94
	.long	.Linfo_string9
	.byte	1
	.byte	23
	.byte	1
	.long	210
	.byte	1
	.byte	6
	.long	.Ldebug_loc0
	.long	.Linfo_string11
	.byte	1
	.byte	27
	.long	140
	.byte	6
	.long	.Ldebug_loc1
	.long	.Linfo_string12
	.byte	1
	.byte	26
	.long	140
	.byte	7
	.long	.Linfo_string13
	.byte	1
	.byte	25
	.long	140
	.byte	0
	.byte	3
	.long	.Linfo_string10
	.byte	5
	.byte	4
	.byte	0
.Ldebug_info_end0:
	.section	.debug_str,"MS",@progbits,1
.Linfo_string0:
	.asciz	"ChipON (Compiler) clang version 14.0.6 (2024/05/11-09:43 90e9b34a96c875fecc03e39c9fcabc720632a80b)"
.Linfo_string1:
	.asciz	"startup.c"
.Linfo_string2:
	.asciz	"/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM/Release"
.Linfo_string3:
	.asciz	"__text_end__"
.Linfo_string4:
	.asciz	"unsigned int"
.Linfo_string5:
	.asciz	"__bss_start__"
.Linfo_string6:
	.asciz	"__bss_end__"
.Linfo_string7:
	.asciz	"__data_start__"
.Linfo_string8:
	.asciz	"__data_end__"
.Linfo_string9:
	.asciz	"startup"
.Linfo_string10:
	.asciz	"int"
.Linfo_string11:
	.asciz	"end"
.Linfo_string12:
	.asciz	"begin"
.Linfo_string13:
	.asciz	"s"
	.ident	"ChipON (Compiler) clang version 14.0.6 (2024/05/11-09:43 90e9b34a96c875fecc03e39c9fcabc720632a80b)"
	.section	".note.GNU-stack","",@progbits
	.section	.debug_line,"",@progbits
.Lline_table_start0:
