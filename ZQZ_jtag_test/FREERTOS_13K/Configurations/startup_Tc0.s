//****************************************************************************************
//*
//* File Name: startup_Tc0.s 
//* Project Name: FreeRTOS_13K
//* Version: v1.0
//* Date: 2024-06-03 14:42:26
//* Author: chipon
//* 
//****************************************************************************************/
//#include <KF32DA2218SQVWS.h>

//asm(".include		\"KF32DA2218SQVWS.inc\"	");	 

	.text
	.import __Core0_start

	
	.export	_start
	.section .start_cpu0,"ax",@progbits
	.align	2
	.type	_start, @function
_start:
//++++++++++++++++++++++++++++sp
	MOV 	R0,	#__initial_sp
	MOV 	SP,	R0
//++++++++++++++++++++++++++++one isr size
	MOV 	R0,	#0x20
	
//++++++++++++++++++++++++++++isr table enter
	MOV 	R0,	#LCF_INTVEC0_START
	
//++++++++++++++++++++++++++++
	MOV 	R0, # __Core0_start
	LJMP 	R0
//++++++++++++++++++++++++++++
	SJMP $
	