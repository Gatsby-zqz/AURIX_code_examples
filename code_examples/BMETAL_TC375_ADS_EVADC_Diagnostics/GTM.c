/**********************************************************************************************************************
 * \file .c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "GTM.h"
#include "Ifx_Types.h"
#include "IfxGtm_reg.h"
#include "IfxGtm_PinMap.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

#define PERIOD 500000         /* PWM period value in 100MHz ticks (10ns)  */
#define DUTY   250000         /* PWM duty cycle value in ticks 100MHz (10ns) */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-----------------------------------------------Function Prototypes-------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*--------------------------------------------Function Implementations-----------------------------------------------*/
/*********************************************************************************************************************/
/* This function initializes the GTM:
 * - Enable clock for GTM module
 * - Disable cluster protections
 * - Set GTM-CLS0 clock without divider (100MHz)
 * - Enable CMU_CLK0
 * - Enable PWM on ATOM0_4, with the clock source CMU_CLK0
 * - Configure the PWM duty cycle and period
 * - Route trigger signal from EDSADC to ATOM0_4
 * - Configure ATOM0 outputs are mapped to pins
 * */
void enable_GTM_trigger(void)
{
    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    MODULE_GTM.CLC.B.DISR = 0x0;                            /* Enable clock for GTM module */
    IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());

    GTM_CTRL.B.RF_PROT = 0x0;                               /* SW RST, FORCEINT and SW RAM enabled */
    GTM_CCM0_PROT.B.CLS_PROT = 0x0;                         /* Disable write protection for GTM */
    GTM_OCS.U = 0x12000000;                                 /* Write protection for SUS disabled */

    GTM_CLS_CLK_CFG.B.CLS0_CLK_DIV = 0x2;                   /* 100MHz, cluster 0 is enabled without clock divider --> CLS0 = 100MHz */
    GTM_CMU_CLK_EN.U = 0x2;                                 /* Enable CMU_CLK0 */
    MODULE_GTM.TBU.CHEN.B.ENDIS_CH0 = 0x2;

    /* Enable PWM on Atom_0 channel_4, with the clock source CMU_CLK0, set Period/Duty */
    MODULE_GTM.ATOM[0].CH4.CTRL.B.MODE = 0x2;               /* SOMP mode */
    MODULE_GTM.ATOM[0].CH4.CTRL.B.CLK_SRC_SR = 0x0;         /* Use CMU_CLK0 as clock for ATOM0_CH0_CN0 */
    MODULE_GTM.ATOM[0].CH4.SR0.U = PERIOD;                  /* Select PWM period */
    MODULE_GTM.ATOM[0].CH4.SR1.U = DUTY;                    /* Select PWM duty cycle */

    /* Force an update from shadow registers, enables channel and outputs of PWM */
    MODULE_GTM.ATOM[0].AGC.FUPD_CTRL.U = 0x0000AAAA;        /* Enable force update mechanism */
    MODULE_GTM.ATOM[0].AGC.GLB_CTRL.B.HOST_TRIG = 0x1;      /* Send SW trigger to update CMx and SRCx */
    MODULE_GTM.ATOM[0].AGC.OUTEN_STAT.U = 0xAAAA;           /* Enable outputs of ATOM */
    MODULE_GTM.ATOM[0].AGC.ENDIS_STAT.U = 0xAAAA;           /* Enable channels of ATOM */

    /* Routing internally the trigger signal from EVADC to ATOM */
    MODULE_GTM.ADCTRIG[0].OUT0.B.SEL0 = 0x5;               /* EVADC_TRIG0[0] --> ATOM0_4 */

    MODULE_GTM.TIM[0].CH4.CTRL.B.TIM_EN = 0x1;              /* Enable TIM 0 Channel 4 */

    /* Enabling GPIOs mapping for debug purposes */
    /* ATOM0_CH4 --> P00_5 */
    IfxGtm_PinMap_setAtomTout(&IfxGtm_ATOM0_4_TOUT14_P00_5_OUT,
                                IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);

}
