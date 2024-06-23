	.text
	.file	"kf_it.c"
	.section	.text._NMI_exception,"ax",@progbits
	.export	_NMI_exception
	.p2align	2
	.type	_NMI_exception,@function
	.func	_NMI_exception
_NMI_exception:
.Lfunc_begin0:
	.file	1 "/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM/Release/../kf_it.c"
	.loc	1 20 0
	.cfi_sections .debug_frame
	.cfi_startproc
	.loc	1 22 1 prologue_end
	MRET
.Ltmp0:
.Lendfunc0:
	.endfunc
.Lfunc_end0:
	.size	_NMI_exception, .Lfunc_end0-_NMI_exception
	.cfi_endproc

	.section	.text._HardFault_exception,"ax",@progbits
	.export	_HardFault_exception
	.p2align	2
	.type	_HardFault_exception,@function
	.func	_HardFault_exception
_HardFault_exception:
.Lfunc_begin1:
	.loc	1 29 0
	.cfi_startproc
	.loc	1 31 1 prologue_end
	MRET
.Ltmp1:
.Lendfunc1:
	.endfunc
.Lfunc_end1:
	.size	_HardFault_exception, .Lfunc_end1-_HardFault_exception
	.cfi_endproc

	.section	.text._StackFault_exception,"ax",@progbits
	.export	_StackFault_exception
	.p2align	2
	.type	_StackFault_exception,@function
	.func	_StackFault_exception
_StackFault_exception:
.Lfunc_begin2:
	.loc	1 38 0
	.cfi_startproc
	.loc	1 40 1 prologue_end
	MRET
.Ltmp2:
.Lendfunc2:
	.endfunc
.Lfunc_end2:
	.size	_StackFault_exception, .Lfunc_end2-_StackFault_exception
	.cfi_endproc

	.section	.text._AriFault_exception,"ax",@progbits
	.export	_AriFault_exception
	.p2align	2
	.type	_AriFault_exception,@function
	.func	_AriFault_exception
_AriFault_exception:
.Lfunc_begin3:
	.loc	1 47 0
	.cfi_startproc
	.loc	1 49 1 prologue_end
	MRET
.Ltmp3:
.Lendfunc3:
	.endfunc
.Lfunc_end3:
	.size	_AriFault_exception, .Lfunc_end3-_AriFault_exception
	.cfi_endproc

	.section	.text._SVC_exception,"ax",@progbits
	.export	_SVC_exception
	.p2align	2
	.type	_SVC_exception,@function
	.func	_SVC_exception
_SVC_exception:
.Lfunc_begin4:
	.loc	1 56 0
	.cfi_startproc
	.loc	1 58 1 prologue_end
	MRET
.Ltmp4:
.Lendfunc4:
	.endfunc
.Lfunc_end4:
	.size	_SVC_exception, .Lfunc_end4-_SVC_exception
	.cfi_endproc

	.section	.text._SoftSV_exception,"ax",@progbits
	.export	_SoftSV_exception
	.p2align	2
	.type	_SoftSV_exception,@function
	.func	_SoftSV_exception
_SoftSV_exception:
.Lfunc_begin5:
	.loc	1 65 0
	.cfi_startproc
	.loc	1 67 1 prologue_end
	MRET
.Ltmp5:
.Lendfunc5:
	.endfunc
.Lfunc_end5:
	.size	_SoftSV_exception, .Lfunc_end5-_SoftSV_exception
	.cfi_endproc

	.section	.text._SysTick_exception,"ax",@progbits
	.export	_SysTick_exception
	.p2align	2
	.type	_SysTick_exception,@function
	.func	_SysTick_exception
_SysTick_exception:
.Lfunc_begin6:
	.loc	1 74 0
	.cfi_startproc
	.loc	1 76 1 prologue_end
	MRET
.Ltmp6:
.Lendfunc6:
	.endfunc
.Lfunc_end6:
	.size	_SysTick_exception, .Lfunc_end6-_SysTick_exception
	.cfi_endproc

	.section	.text._ECC_exception,"ax",@progbits
	.export	_ECC_exception
	.p2align	2
	.type	_ECC_exception,@function
	.func	_ECC_exception
_ECC_exception:
.Lfunc_begin7:
	.loc	1 82 0
	.cfi_startproc
	.loc	1 84 1 prologue_end
	MRET
.Ltmp7:
.Lendfunc7:
	.endfunc
.Lfunc_end7:
	.size	_ECC_exception, .Lfunc_end7-_ECC_exception
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
	.byte	85
	.byte	6
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
	.byte	39
	.byte	12
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
	.long	0
	.long	.Ldebug_ranges0
	.byte	2
	.long	.Lfunc_begin0
	.long	.Lfunc_end0
	.byte	1
	.byte	94
	.long	.Linfo_string3
	.byte	1
	.byte	19
	.byte	1
	.byte	1
	.byte	2
	.long	.Lfunc_begin1
	.long	.Lfunc_end1
	.byte	1
	.byte	94
	.long	.Linfo_string4
	.byte	1
	.byte	28
	.byte	1
	.byte	1
	.byte	2
	.long	.Lfunc_begin2
	.long	.Lfunc_end2
	.byte	1
	.byte	94
	.long	.Linfo_string5
	.byte	1
	.byte	37
	.byte	1
	.byte	1
	.byte	2
	.long	.Lfunc_begin3
	.long	.Lfunc_end3
	.byte	1
	.byte	94
	.long	.Linfo_string6
	.byte	1
	.byte	46
	.byte	1
	.byte	1
	.byte	2
	.long	.Lfunc_begin4
	.long	.Lfunc_end4
	.byte	1
	.byte	94
	.long	.Linfo_string7
	.byte	1
	.byte	55
	.byte	1
	.byte	1
	.byte	2
	.long	.Lfunc_begin5
	.long	.Lfunc_end5
	.byte	1
	.byte	94
	.long	.Linfo_string8
	.byte	1
	.byte	64
	.byte	1
	.byte	1
	.byte	2
	.long	.Lfunc_begin6
	.long	.Lfunc_end6
	.byte	1
	.byte	94
	.long	.Linfo_string9
	.byte	1
	.byte	73
	.byte	1
	.byte	1
	.byte	2
	.long	.Lfunc_begin7
	.long	.Lfunc_end7
	.byte	1
	.byte	94
	.long	.Linfo_string10
	.byte	1
	.byte	81
	.byte	1
	.byte	1
	.byte	0
.Ldebug_info_end0:
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.long	.Lfunc_begin0
	.long	.Lfunc_end0
	.long	.Lfunc_begin1
	.long	.Lfunc_end1
	.long	.Lfunc_begin2
	.long	.Lfunc_end2
	.long	.Lfunc_begin3
	.long	.Lfunc_end3
	.long	.Lfunc_begin4
	.long	.Lfunc_end4
	.long	.Lfunc_begin5
	.long	.Lfunc_end5
	.long	.Lfunc_begin6
	.long	.Lfunc_end6
	.long	.Lfunc_begin7
	.long	.Lfunc_end7
	.long	0
	.long	0
	.section	.debug_str,"MS",@progbits,1
.Linfo_string0:
	.asciz	"ChipON (Compiler) clang version 14.0.6 (2024/05/11-09:43 90e9b34a96c875fecc03e39c9fcabc720632a80b)"
.Linfo_string1:
	.asciz	"kf_it.c"
.Linfo_string2:
	.asciz	"/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM/Release"
.Linfo_string3:
	.asciz	"_NMI_exception"
.Linfo_string4:
	.asciz	"_HardFault_exception"
.Linfo_string5:
	.asciz	"_StackFault_exception"
.Linfo_string6:
	.asciz	"_AriFault_exception"
.Linfo_string7:
	.asciz	"_SVC_exception"
.Linfo_string8:
	.asciz	"_SoftSV_exception"
.Linfo_string9:
	.asciz	"_SysTick_exception"
.Linfo_string10:
	.asciz	"_ECC_exception"
	.ident	"ChipON (Compiler) clang version 14.0.6 (2024/05/11-09:43 90e9b34a96c875fecc03e39c9fcabc720632a80b)"
	.section	".note.GNU-stack","",@progbits
	.section	.debug_line,"",@progbits
.Lline_table_start0:
