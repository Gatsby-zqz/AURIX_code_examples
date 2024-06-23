//****************************************************************************************
//*
//* File Name: startup_Tc1.s 
//* Project Name: FreeRTOS_13K
//* Version: v1.0
//* Date: 2024-06-03 14:42:26
//* Author: chipon
//* 
//****************************************************************************************/
//#include <KF32DA2218SQVWS.h>

//asm(".include		\"KF32DA2218SQVWS.inc\"	");	 


	.import __Core1_start


	.export	_start1
	.section .start_cpu1
	.align	2
	.type	_start1, @function
_start1:
//++++++++++++++++++++++++++++sp
	// MOV 	R0,	#__initial_sp_core1
	MOV 	R0,	#__initial_sp
	MOV 	SP,	R0
//++++++++++++++++++++++++++++one isr size
	MOV 	R0,	#0x20
	
//++++++++++++++++++++++++++++isr table enter
	MOV 	R0,	#LCF_INTVEC1_START
	
//++++++++++++++++++++++++++++
	// MOV 	R0, # __Core1_start
	MOV 	R0, #__Core0_start
	LJMP 	R0
//++++++++++++++++++++++++++++
	SJMP $
	