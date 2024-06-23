	.text
	.file	"main.c"
	.file	1 "/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM/Release/../main.c"
	.section	.text.main,"ax",@progbits
	.export	main
	.p2align	2
	.type	main,@function
	.func	main
main:
.Lfunc_begin0:
	.loc	1 13 0
	.cfi_sections .debug_frame
	.cfi_startproc
	.loc	1 15 3 prologue_end
	LD r5, #a
	MOV r4, #4
	ST.w [r5], r4
	MOV r4, #5
	MOV r3, #10
.LBB0_1:
.Ltmp0:
	.loc	1 19 4
	ST.w [r5], r4
	.loc	1 20 4
	LD.w r2, [r5]
	ADD r2, r2, #6
	ST.w [r5], r2
	.loc	1 22 4
	ST.w [r5], r3
.Ltmp1:
	.loc	1 17 2
	SJMP .LBB0_1
.Ltmp2:
.Lendfunc0:
	.endfunc
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	a,@object
	.section	.data.a,"aw",@progbits
	.export	a
	.p2align	2
a:
	.long	3
	.size	a, 4

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
	.byte	2
	.byte	10
	.byte	0
	.byte	0
	.byte	3
	.byte	53
	.byte	0
	.byte	73
	.byte	19
	.byte	0
	.byte	0
	.byte	4
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
	.byte	5
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
	.byte	39
	.byte	12
	.byte	73
	.byte	19
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
	.long	.Linfo_string3
	.long	56
	.byte	1
	.byte	1
	.byte	10
	.byte	5
	.byte	3
	.long	a
	.byte	3
	.long	61
	.byte	4
	.long	.Linfo_string4
	.byte	7
	.byte	4
	.byte	5
	.long	.Lfunc_begin0
	.long	.Lfunc_end0
	.byte	1
	.byte	94
	.long	.Linfo_string5
	.byte	1
	.byte	12
	.byte	1
	.long	91
	.byte	1
	.byte	4
	.long	.Linfo_string6
	.byte	5
	.byte	4
	.byte	0
.Ldebug_info_end0:
	.section	.debug_str,"MS",@progbits,1
.Linfo_string0:
	.asciz	"ChipON (Compiler) clang version 14.0.6 (2024/05/11-09:43 90e9b34a96c875fecc03e39c9fcabc720632a80b)"
.Linfo_string1:
	.asciz	"main.c"
.Linfo_string2:
	.asciz	"/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM/Release"
.Linfo_string3:
	.asciz	"a"
.Linfo_string4:
	.asciz	"unsigned int"
.Linfo_string5:
	.asciz	"main"
.Linfo_string6:
	.asciz	"int"
	.ident	"ChipON (Compiler) clang version 14.0.6 (2024/05/11-09:43 90e9b34a96c875fecc03e39c9fcabc720632a80b)"
	.section	".note.GNU-stack","",@progbits
	.section	.debug_line,"",@progbits
.Lline_table_start0:
