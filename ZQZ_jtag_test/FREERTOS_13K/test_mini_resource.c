//****************************************************************************************
//*
//* File Name: test_mini_resource.c 
//* Project Name: FreeRTOS_13K
//* Version: v1.0
//* Date: 2024-06-03 14:42:26
//* Author: chipon
//* 
//****************************************************************************************/
//#include <KF32DA2218SQVWS.h>

//asm(".include		\"KF32DA2218SQVWS.inc\"	");	 


#include "Kfx_Ssw.h"

KFX_INTERRUPT_INTERNAL(MytestISRFun, 0, 8)
{
	while (1)
		;
}

KFX_INTERRUPT_INTERNAL(MytestISRFun1, 0, 10)
{
	while (1)
		;
}

KFX_INTERRUPT_INTERNAL(MytestISRFun2, 1, 8)
{
	while (1)
		;
}

KFX_INTERRUPT_INTERNAL(MytestISRFun3, 1, 10)
{
	while (1)
		;
}
// ##############################################################

__attribute__((section(".gmudata"))) unsigned int test_demoa = 3;

__attribute__((section(".gmubss"))) unsigned int test_demob = 3;

// ##############################################################
__attribute__((section(".cpu0_psram.core0"))) void core1_ram_function()
{
	__asm("MOV R0,R9");
}

__attribute__((section(".cpu1_psram.core1"))) void core0_ram_function()
{
	__asm("MOV R0,R9");
}

// ##############################################################
__attribute__((section(".lmudata_cpu0.core0"))) void core1_localmcu_function()
{
	__asm("MOV R0,R9");
}

__attribute__((section(".lmudata_cpu1.core1"))) void core0_localmcu_function()
{
	__asm("MOV R0,R9");
}
// ##############################################################
