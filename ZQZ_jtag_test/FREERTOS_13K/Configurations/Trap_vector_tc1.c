//****************************************************************************************
//*
//* File Name: Trap_vector_tc1.c 
//* Project Name: FreeRTOS_13K
//* Version: v1.0
//* Date: 2024-06-03 14:42:26
//* Author: chipon
//* 
//****************************************************************************************/
//#include <KF32DA2218SQVWS.h>

//asm(".include		\"KF32DA2218SQVWS.inc\"	");	 

/*
 * Trap_vetor_default.c
 *
 *  Created on: 2024-4-5
 *      Author: chipon
 */



__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_0(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_1(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_2(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_3(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_4(void){


}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_5(void)
{

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_6(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_7(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_8(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_9(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_10(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_11(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_12(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_13(void){


}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_14(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_15(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_16(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_17(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_18(void){

}
__attribute__((section(".text_cpu1"))) __attribute__((weak)) void _Trap1_vector_19(void){

}
// 2^5=32
#define KFX_WEAK_Trap0_Interrupt(name) 	__asm__(".align 5\n\tjmp "#name"");

__attribute__((section(".traptab_cpu1")))
void _cpu1_trap_table (void)
{
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_0);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_1);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_2);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_3);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_4);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_5);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_6);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_7);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_8);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_9);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_10);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_11);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_12);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_13);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_14);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_15);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_16);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_17);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_18);
	KFX_WEAK_Trap0_Interrupt( _Trap1_vector_19);
}

