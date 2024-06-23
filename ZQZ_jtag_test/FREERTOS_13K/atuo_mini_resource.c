//****************************************************************************************
//*
//* File Name: atuo_mini_resource.c
//* Project Name: FreeRTOS_13K
//* Version: v1.0
//* Date: 2024-06-03 14:42:26
//* Author: chipon
//*
//****************************************************************************************/
// #include <KF32DA2218SQVWS.h>

// asm(".include		\"KF32DA2218SQVWS.inc\"	");

#include "Kfx_Ssw.h"

KFX_INTERRUPT_INTERNAL(AMytestISRFun0, 0, 2)
{
    while (1)
        ;
}

KFX_INTERRUPT_INTERNAL(AMytestISRFun1, 0, 110)
{
    while (1)
        ;
}

KFX_INTERRUPT_INTERNAL(AMytestISRFun2, 1, 18)
{
    while (1)
        ;
}

KFX_INTERRUPT_INTERNAL(AMytestISRFun3, 1, 110)
{
    __asm__ volatile("MOV R0, #0");
    __asm__ volatile("MOV R1, #1");
    __asm__ volatile("MOV R2, #2");
    __asm__ volatile("MOV R3, #3");
    __asm__ volatile("MOV R4, #4");
}
// ##############################################################

__attribute__((section(".gmudata"))) unsigned int auto_demoa = 3;

__attribute__((section(".gmubss"))) unsigned int auto_demob = 3;

// ##############################################################
__attribute__((section(".cpu0_psram.core0"))) void auto_core1_ram_function()
{
    __asm("MOV R0,R9");
}

__attribute__((section(".cpu1_psram.core1"))) void auto_core0_ram_function()
{
    __asm("MOV R0,R9");
}

// ##############################################################
__attribute__((section(".lmudata_cpu0.core0"))) void auto_core1_localmcu_function()
{
    __asm("MOV R0,R9");
}

__attribute__((section(".lmudata_cpu1.core1"))) void auto_core0_localmcu_function()
{
    __asm("MOV R0,R9");
}
// ##############################################################
__attribute__((section(".data_cpu1."))) void auto_core1_dsram_function()
{
    __asm("MOV R0,R9");
}
