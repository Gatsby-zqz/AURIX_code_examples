//****************************************************************************************
//*
//* File Name: Kfx_Ssw_Tc1.c 
//* Project Name: FreeRTOS_13K
//* Version: v1.0
//* Date: 2024-06-03 14:42:26
//* Author: chipon
//* 
//****************************************************************************************/
//#include <KF32DA2218SQVWS.h>

//asm(".include		\"KF32DA2218SQVWS.inc\"	");	 

/*
 * Kfx_Ssw_Tc1.c
 * Startup Software for Core0
 *  Created on: 2024-3-29
 *      Author: chipon
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Kfx_Ssw.h"

/*********************************************************************************
* - startup code
*********************************************************************************/

#if defined(__GNUC__)
#pragma GCC optimize "O2"
#endif

void __Core1_start(void)
{


	/*Initialize CPU Private Global Variables*/


	/*Call main function of Cpu1 */
	extern void core1_main(void);
    __jumpToFunctionWithLink(core1_main);  /* Jump to main function of CPU2 */

    /* Go into infinite loop, normally the code shall not reach here */
    __Loop();
}



