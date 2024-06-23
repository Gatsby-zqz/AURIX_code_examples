//****************************************************************************************
//*
//* File Name: Cpu0_Main.asm 
//* Project Name: 13k_debug
//* Version: v1.0
//* Date: 2024-01-11 20:25:41
//* Author: linfengtai
//* 
//****************************************************************************************/
 .file  1 "../debug_rom.asm"
 		.section .debugROM.text
		.align	1
		.export	debugROM
		.type	debugROM, @function
debugROM:	
	.cfi_startproc	
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	.loc 1 18
_entry:
	NOP
	NOP 
	.loc 1 22
entry_loop:
	MOV R2, #0xF9008100	//	0x F900  8100  = 0   // send mess to mode , cpu halted
	// CSRR R1, #CSR_HARTID0
	// CSRR R1, #CSR_HARTID1
	MOV R1, #0			// now sigle core
	ST.W [R2], R1
//+++++++++++++++++++++++++++++++++++
	.loc 1 30
	MOV R2, #0xF9008400	//	if  0x F900  8400    1 probuffer    2    resume
	LD.B R1, [R2]

	.loc 1 34	
	CMP R1, #1			// probuffer, now not set and not will set to1 
	JZ going
	NOP
//+++++++++++++++++++++++++++++++++++
	.loc 1 39
	CMP R1, #2			// 
	JZ _resume
//+++++++++++++++++++++++++++++++++++
	.loc 1 43
	//CSRR R2,#xx
	//CMP  R2,#XX
	//JZ   _Exception	
	JMP entry_loop
	NOP
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
	.loc 1 50
going:
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    
	NOP
 	MOV R1, #0
	MOV R2, #0xf9008108		//	0x F900  8108  = 0
	ST.W [R2], R1
	.loc 1 57
	// Do probuffer enter point
	// MOV R0,
	// JMP R0
	JMP entry_loop    // now temp goto next
	NOP
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	.loc 1 64
_resume:	
	NOP
	NOP
	// CSRR R1, #CSR_HARTID0
	// CSRR R1, #CSR_HARTID1
	MOV R1, #0				// now cpu 0
	MOV R2, #0xf9008110
	ST.W [R2], R1			//	0x F900  8110  = 0
	
	.loc 1 74
	NOP
	NOP
	.short 0x0C	// MRET
	NOP	
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
_exception:
	.loc 1 81
	JMP entry_loop    // now temp goto next
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
	.cfi_endproc
	.loc 1 85
	.size	debugROM, .-debugROM	
//****************************************************************************************function end
	
.end
