/*
 * Trap_vetor_default.c
 *
 *  Created on: 2024-4-5
 *      Author: chipon
 */
void debugROM();


__attribute__((weak)) void _Trap0_vector_0(void){
	debug_rom();

}
__attribute__((weak)) void _Trap0_vector_1(void){

}
__attribute__((weak)) void _Trap0_vector_2(void){

}
__attribute__((weak)) void _Trap0_vector_3(void){

}
__attribute__((weak)) void _Trap0_vector_4(void){


}__attribute__((weak)) void _Trap0_vector_5(void)
{

}
__attribute__((weak)) void _Trap0_vector_6(void){

}
__attribute__((weak)) void _Trap0_vector_7(void){

}
__attribute__((weak)) void _Trap0_vector_8(void){

}
__attribute__((weak)) void _Trap0_vector_9(void){

}
__attribute__((weak)) void _Trap0_vector_10(void){

}
__attribute__((weak)) void _Trap0_vector_11(void){

}
__attribute__((weak)) void _Trap0_vector_12(void){

}
__attribute__((weak)) void _Trap0_vector_13(void){


}__attribute__((weak)) void _Trap0_vector_14(void){

}
__attribute__((weak)) void _Trap0_vector_15(void){

}
__attribute__((weak)) void _Trap0_vector_16(void){

}
__attribute__((weak)) void _Trap0_vector_17(void){

}
__attribute__((weak)) void _Trap0_vector_18(void){

}
__attribute__((weak)) void _Trap0_vector_19(void){

}
// 2^5=32
#define KFX_WEAK_Trap0_Interrupt(name) 	__asm__(".align 2\n\t JMP  "#name);

__attribute__((section(".traptab_cpu0")))
void _cpu0_trap_table (void)
{
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);

	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);

	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);

	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
	KFX_WEAK_Trap0_Interrupt( debugROM);
}

