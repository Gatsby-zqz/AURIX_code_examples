/**************************************************************************
 *      ShangHai ChipON Micro-Electronic Technology Co.,Ltd
 **************************************************************************
 * @File Name: kf32a13k_reg_pmc.h
 * @Version  : V1.0.0
 **************************************************************************
 * Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd\n
 * This software is copyright protected and proprietary to
 * Shanghai ChipON Micro-Electronic Co.,Ltd
 **************************************************************************/

#ifndef _KF32DA13K_REG_PMC_H_
#define _KF32DA13K_REG_PMC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**************************************************************************
 *         Include Files
 **************************************************************************/
#include <stdint.h>
#include "kf_types.h"

	/**************************************************************************
	 *         Mcro ro typedef
	 **************************************************************************/
	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t MODREV : 8;	 /*!< [7:0] 该位显示PMS模块的版本号  */
				__I uint32_t MODTYPE : 8;	 /*!< [15:8] 该位显示PMS模块类型  */
				__I uint32_t MODNUMBER : 16; /*!< [31:16] 该位显示PMS模块ID  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_INFO_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t EN0 : 1;	/*!< [0:0] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN1 : 1;	/*!< [1:1] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN2 : 1;	/*!< [2:2] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN3 : 1;	/*!< [3:3] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN4 : 1;	/*!< [4:4] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN5 : 1;	/*!< [5:5] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN6 : 1;	/*!< [6:6] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN7 : 1;	/*!< [7:7] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN8 : 1;	/*!< [8:8] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN8 : 1;	/*!< [9:9] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN10 : 1; /*!< [10:10] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN11 : 1; /*!< [11:11] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN12 : 1; /*!< [12:12] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN13 : 1; /*!< [13:13] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN14 : 1; /*!< [14:14] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN15 : 1; /*!< [15:15] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN16 : 1; /*!< [16:16] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN17 : 1; /*!< [17:17] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN18 : 1; /*!< [18:18] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN19 : 1; /*!< [19:19] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN20 : 1; /*!< [20:20] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN21 : 1; /*!< [21:21] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN22 : 1; /*!< [22:22] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN23 : 1; /*!< [23:23] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN24 : 1; /*!< [24:24] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN25 : 1; /*!< [25:25] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN26 : 1; /*!< [26:26] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN27 : 1; /*!< [27:27] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN28 : 1; /*!< [28:28] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN29 : 1; /*!< [29:29] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN30 : 1; /*!< [30:30] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
				__IO uint32_t EN31 : 1; /*!< [31:31] 主标签??ID??n??的访问启用:该位启用对主标签??ID??n??事务的??PMS??内核地址的写访问  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_ACES0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t RESERVE : 32; /*!< [31:0] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_ACES1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t DCDC11 : 1;	 /*!< [0:0] DCDC11稳压器状态位:当内部DCDC11稳压器被激活时该位被置1；在启动阶段，当HWCFG[2]引脚被锁存的值为高时，DCDC11稳压器被开启  */
				__I uint32_t OV11 : 1;		 /*!< [1:1] VDD11电压溢出标志:当VDD11次级监控器识别到VDD11溢出电压事件时，该位被置1；一个报警将会被发送至SACU直到该溢出事件消失  */
				__I uint32_t LDO33 : 1;		 /*!< [2:2] LDO33稳压器状态位:当内部LDO33稳压器被激活时该位被置1；在启动阶段，当HWCFG[1]引脚被锁存的值为高时，LDO33稳压器被开启  */
				__I uint32_t OV33 : 1;		 /*!< [3:3] VDD33电压溢出标志:当VDD33次级监控器识别到电压溢出事件时，该位被置1；一个报警将会被发送至SACU直到该溢出事件消失  */
				__I uint32_t OVPWR : 1;		 /*!< [4:4] VCC电压溢出标志:当VCC次级监控器识别到电压溢出事件时，该位被置1；一个报警将会被发送至SACU直到该溢出事件消失  */
				__I uint32_t UV11 : 1;		 /*!< [5:5] VDD11电压下溢标志:当VDD11次级监控器识别到电压下溢事件时，该位被置1；一个报警将会被发送至SACU直到该溢出事件消失  */
				__I uint32_t UV33 : 1;		 /*!< [6:6] VDD33电压下溢标志:当VDD33次级监控器识别到电压下溢事件时，该位被置1；一个报警将会被发送至SACU直到该溢出事件消失  */
				__I uint32_t UVPWR : 1;		 /*!< [7:7] VCC电压下溢标志:当VCC次级监控器识别到电压下溢事件时，该位被置1；一个报警将会被发送至SACU直到该溢出事件消失  */
				__I uint32_t RESERVE : 1;	 /*!< [8:8] 保留位  */
				__I uint32_t LDO33VOK : 1;	 /*!< [9:9] LDO33稳压器电压OK状态位:该位在?LDO33?电压OK?斜坡检测器的软斜坡上升时间结束后设置，并且?基于斜坡阶段结束时测得的?VDD33?电压。  */
				__I uint32_t RESERVE : 3;	 /*!< [12:10] 保留位  */
				__I uint32_t RST11 : 1;		 /*!< [13:13] DCDC11??复位触发器  */
				__I uint32_t RST33 : 1;		 /*!< [14:14] LDO33??复位触发器  */
				__I uint32_t RSTPWR : 1;	 /*!< [15:15] PWR??复位触发器  */
				__I uint32_t DCDC11SHLV : 1; /*!< [16:16] 对地短??:如果检测到对地短?，则设置该位。测得的??DCDC11??输出低于工作电源范围并且达到了控制器上限。该功能仅在闭环操作或??DCDC11MOD??=??00b??期间被支持  */
				__I uint32_t DCDC11SHHV : 1; /*!< [17:17] 电源短??:如果检测到电源短?情况，则设置该位。测得的DCDC11输出超出允许的电源范围，并且达到控制器下限。该功能仅在闭环操作或DCDC11MOD??=??00b??期间被支持  */
				__I uint32_t LDO33SHLV : 1;	 /*!< [18:18] 对地短???如果检测到对地短?，则设置该位。测得的??LDO33??输出低于工作电源范围和驱动??PMOSFET??的栅极驱动达到阈值电压上限  */
				__I uint32_t LDO33SHHV : 1;	 /*!< [19:19] 电源短???如果检测到电源短?情况，则设置该位。测得的??LDO33??输出超过了允许的电源范围和驱动??PMOSFET??的栅极驱动达到阈值电压上限  */
				__I uint32_t PWRLVL : 1;	 /*!< [20:20] VCC??外部电源电平状态该位指示VCC电压已降至??-4??V??以下，以指示?DCDC11??参数切换以区分?5V?或?3.3V?外部电源。该检测器实现了??-120??mV??的滞后  */
				__I uint32_t SDVOK : 1;		 /*!< [21:21] DCDC11?稳压器电压正常状态??该位由?DCDC11?电压正常检测器设置，以指示已达到新的稳压器输出值。该位在?PMC_CAL寄存器的DCDC11VOUT或DCDC11VCAL??值适用于缩放核心电压，并在达到新的输出设定点时设置。如果在负载跳变事件之前请求压降补偿，该位也会被重置。轮询??SDVOK??位时应等待??x??us??的超时时间  */
				__I uint32_t DCDC11MOD : 2;	 /*!< [23:22] 该位指示?LC?????PWM、LPM、STRT??的当前操作模式  */
				__I uint32_t OV11BKP : 1;	 /*!< [24:24] 预稳压器??VDD11BKP??过压事件标志?:如果??VDD11BKP??电源次级电压监控器识别出过压事件，则设置该位,向??SACU??发出警报  */
				__I uint32_t OVDDBKP : 1;	 /*!< [25:25] 备用电源或??VDDBKP??过压事件标志??如果??VDDBKP??电源次级电压监控器识别出过压事件，则此位被设置。向??SACU??发出警报  */
				__I uint32_t OVDDA : 1;		 /*!< [26:26] ADC??VDDA??电源过压事件标志??如果??VDDA??ADC??电源次级电压监控器识别到过压事件，则设置该位。向??SACU??发出警报  */
				__I uint32_t UV11BKP : 1;	 /*!< [27:27] 预稳压器??VDD11BKP??欠压事件标志??如果??VDD11BKP??电源次级电压监控器识别出欠压事件，则此位被设置。向??SACU??发出警报  */
				__I uint32_t UVDDBKP : 1;	 /*!< [28:28] 备用电源或??VDDBKP??欠压事件标志??如果??VDDBKP??电源次级电压监控器识别出欠压事件，则设置该位。向??SACU??发出警报  */
				__I uint32_t UVDDA : 1;		 /*!< [29:29] ADC??VDDA??电源欠压事件标志??如果??VDDA??ADC??电源次级电压监控器识别到欠压事件，则设置该位。向??SACU??发出警报  */
				__I uint32_t RESERVE : 2;	 /*!< [31:30] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_STA_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t ADCP11V : 8;  /*!< [7:0] ADC??VDD11??内核电压转换结果??该位字段包含主监视器对?VDD11/DCDC11电源ADC测?的最后过滤转换结果,VIN??=??[0.7125??+??(ADCCV??*??LSB)]V?,LSB??=??5??mV??例如。??1.25??V??=??6C  */
				__I uint32_t ADCP33V : 8;  /*!< [15:8] ADC??VDD33?电压转换结果:该位字段包含主监视器对?VDD33?/?LDO33?电源ADC测?的最后过滤转换结果,VIN??=??[0.9375??+??(ADC33V??*??LSB)]?V?,?LSB??=??15??mV例如3.3V=9E  */
				__I uint32_t ADCPPWRV : 8; /*!< [23:16] ADC??VCC??电源转换结果??该位字段包含主监视器对外部??VCC??(3.3V?/??5V)??电源的??ADC??测?的最后过滤转换结果VIN??=??[1.050??+??(ADCSWDV??*??LSB)]??V?,?LSB?=??20??mV??例如。??5??V??=??C6  */
				__I uint32_t OV11 : 1;	   /*!< [24:24] 主监控器识别出过压事件，则设置该位。向??HSM??和??SACU??发出警报  */
				__I uint32_t OV33 : 1;	   /*!< [25:25] LDO33??稳压器或??VDD33??过压事件标志??如果??VDD33??主电压监控器识别出过压事件，则设置该位。向??HSM??和??SACU??发出警报  */
				__I uint32_t OVPWR : 1;	   /*!< [26:26] 电源看门狗??或??VCC??过压事件标志??如果??VCC??主电压监控器识别出过压事件，则此位被设置。向??HSM??和??SACU??发出警报  */
				__I uint32_t UV11 : 1;	   /*!< [27:27] DCDC11??稳压器或??VDD11??欠压事件标志??如果??VDD11??主电压监控器识别出欠压事件，则设置该位。向??HSM??和??SACU??发出警报  */
				__I uint32_t UV33 : 1;	   /*!< [28:28] LDO33??稳压器或??VDD33??欠压事件标志??如果??VDD33??主电压监控器识别出欠压事件，则设置该位。向??HSM??和??SACU??发出警报  */
				__I uint32_t UVPWR : 1;	   /*!< [29:29] 电源看门狗??(SWD)??或??VCC??欠压事件标志??如果??VCC??主电压监视器识别到欠压事件，则该位被设置。向??HSM??和??SACU??发出警报  */
				__I uint32_t RESERVE : 2;  /*!< [31:30] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_PMONSTA_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t RST11CAL : 8;	 /*!< [7:0] VDD11电源复位调整值；该位字段选择?VDD11?电源轨的硬复位生成级别，该位字段由固件修整；RST11CAL??=[(VDDx?????712.5??mV)?/??LSB]，VDD11PRIUV??=??712.5??mV??+??LSB?*RST11CAL(有符号值)，LSB??=??5??mV  */
				__IO uint32_t RST33CAL : 8;	 /*!< [15:8] VDD33电源复位调整值:该位字段选择?VDD33??电源轨的硬复位生成级别，该位字段由固件修整；RST33CAL??=??[(VDDx?????937.5??mV)?/??LSB]，VDD33PRIUV??=??937.5??mV??+??LSB*RST33CAL??+??LSB*RST33PCAL，LSB=15mv  */
				__IO uint32_t RSTPWRCAL : 8; /*!< [23:16] VCC电源复位调整值?:该位字段选择外部?VCC??电源轨的硬复位生成级别。该位域由固件修整RSTPWRCAL??=??[(VDDx?????1050??mV)?/??LSB]VCCPRIUV??=??1050??mV+??LSB?*RSTPWRCAL，LSB=20MV  */
				__IO uint32_t RST11DIS : 1;	 /*!< [24:24] VDD11??复位使能:如果位??BPRSTCOFF??被并?设置，则只能?改此位.RST11DIS??值在仅用于内部测试目的，并且?会在客户应用程序中禁用主要复位生成  */
				__O uint32_t WRST11DIS : 1;	 /*!< [25:25] 该位保护RST11DIS:设置该位使?RST11DIS:?位可以在此写操作中?改。该位读为零  */
				__IO uint32_t RST33DIS : 1;	 /*!< [26:26] VDD33??复位使能:仅当并?设置位??RST33DIS??时才能?改此位。??VDD33??复位被应用程序禁用，以支持启动期间高达标称??3.0??V??的电压降。??RST33DIS?仅用于内部测试目的，并且?会在客户应用中禁用主复位生成  */
				__O uint32_t WRST33DIS : 1;	 /*!< [27:27] 此位保护??RST33DIS:设置该位使RST33DIS位可以在此写操作中?改。该位也读为零  */
				__IO uint32_t RSTPWRDIS : 1; /*!< [28:28] VCC复位使能:仅当并?设置位??RSTPWRDIS??时才能?改此位，RSTPWRDIS??指在仅用于内部测试目的，并且?会在客户应用程序中禁用主复位生成  */
				__O uint32_t WRSTPWRDIS : 1; /*!< [29:29] 位保护??RSTPWRDIS:设置该位使RSTPWRDIS位可以在此写操作中?改,该位读为零  */
				__IO uint32_t SLCK : 1;		 /*!< [30:30] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位,当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
				__I uint32_t RESERVE : 1;	 /*!< [31:31] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_RSTCTL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t RST11 : 8;		/*!< [7:0] VDD11??电源复位值状态??该位字段指示主监视器使用的核心电压电源轨的实际冷PORST??复位微调设定点。该值通过PMC_RSTCTL.RST11CAL?寄存器?新。RST11??=??RSTCTRIM??+??RSTCPTRIM(有符号值)，RSTC??范围??=??0??到??255VDDPRIUV??=??712.5??mV??+??LSB*RSTC，?LSB=5mV  */
				__I uint32_t RST33 : 8;		/*!< [15:8] VDD33??电源复位值状态??该位字段指示主监视器使用的??3.3??V??电源轨的实际冷PORST??复位微调设定点。该值通过PMC_RSTCTL.RST33CAL寄存器?新。RST33??=??RST33CAL??+??RST33PCAL(有符号值),RST33??范围??=??0??至??255VDD33PRIUV??=??937.5??mV??+??LSB*RST33,LSB=15mV  */
				__I uint32_t RSTPWR : 8;	/*!< [23:16] VCC?电源复位值状态:该位字段指示主监视器使用的?5?V电源轨的实际PORST??复位微调设定点。该值通过PMC_RSTCTL.RSTPWRCAL??寄存器?新。RSTPWR??=??RSTPWRCAL+??RSTPWRPCAL(有符号值),RSTPWR范围=0到255VCCPRIUV??=??1050??mV+??LSB*RSTPWR,LSB=20mv  */
				__I uint32_t RST11DIS : 1;	/*!< [24:24] DCDC11??复位使能状态:该值通过PMC_RSTCTL.RSTCDIS寄存器位?新  */
				__I uint32_t RESERVE : 1;	/*!< [25:25] 保留位  */
				__I uint32_t RST33DIS : 1;	/*!< [26:26] LDO33?复位启用状态?:该值通过PMC_RSTCTL.RST33DIS??寄存器位?新,  */
				__I uint32_t RESERVE : 1;	/*!< [27:27] 保留位  */
				__I uint32_t RSTPWRDIS : 1; /*!< [28:28] PWR??复位使能:该值通过PMC_RSTCTL.RSTSWDOFF??寄存器位?新  */
				__I uint32_t RESERVE : 3;	/*!< [31:29] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_RSTSTA_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t LDO33VOUT : 8;  /*!< [7:0] 电压目标值??LDO33??LDO??稳压器的??VDD33??输出电平。新目标值的上升完成通过??PMC_PSTA.LDO33VOK??位指示。??(LDO33VOUTSEL??+??LDO33VCAL)??设定点值应在??0x24??和??0xDA??之间编程，以实现有效的闭环??PID??调节器功能；eg:3.3??V?????9EH?????158D?LDO33VOUTSEL??=??[(VDD33?????937.5??mV)?/??LSB]VDD33??=??937.5??mV??+??LSB*LDO33VOUTSEL，LSB=15mV  */
				__IO uint32_t DCDC11VOUT : 8; /*!< [15:8] DCDC11??稳压器输出电压目标值??降压稳压器的??VDD11??输出电平。eg:1.25??V?????6C?????108D?SDVOUTSEL??=??[(VDD?????712.5??mV)?/??LSB]；VDD??=?712.5??mV??+??LSB?*SDVOUTSEL，LSB=5mV；该寄存器位域需要通过?PMC_SDCTL0.UP??进?参数?新，以传输到DCDC11??SMPS??影子寄存器。新目标值的达到通过??PMC_PSTA.SDVOK??位指示  */
				__IO uint32_t LDO33VCAL : 6;  /*!< [21:16] LDO33??稳压器输出电压微调值??6??位??ADC??BIST??微调值偏移添加到固件从闪存安装的??LDO33??输出电平值,VDD33??设定点??=??LDO33VOUTSEL??+??LDO33VCAL(有符号值),LDO33VCAL??范围??=???32??至??31,LSB=15mV  */
				__I uint32_t RESERVE : 2;	  /*!< [23:22] 保留位  */
				__IO uint32_t DCDC11VCAL : 6; /*!< [29:24] DCDC11??稳压器输出电压调整值??(vtrim_trim_i),6??位??ADC??BIST??微调值偏移添加到固件从闪存安装的??DCDC11??输出电平值。新设置点的达到通过??PMC_PSTA.SDVOK??位指示??VDD??设置点??=??DCDC11VOUT??+??DCDC11VCAL(有符号值)DCDC11VCAL?RANGE??=???32??至??31??LSB?,LSB??=5mV该寄存器位域需要通过?PMC_SDCTL0.UP??新参数以传输到??SMPS??影子寄存器  */
				__IO uint32_t SLCK : 1;		  /*!< [30:30] HSM??安全锁?:如果设置了该位，则无法再写入该寄存器中的所有其他位.当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。??SLCK?位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
				__IO uint32_t LCK : 1;		  /*!< [31:31] 锁定状态??该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线端的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_CALCTL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t LDO33VOUT : 8;	 /*!< [7:0] 电压目标值??该位字段指示在??PMC_CAL.LDO33VOUT??中配置的??LDO33??输出目标值  */
				__I uint32_t DCDC11VOUT : 8; /*!< [15:8] DCDC11??稳压器输出电压目标值??该位字段指示在??PMC_CAL.DCDC11VOUT中配置的降压稳压器的??DCDC11??输出电平  */
				__I uint32_t LDO33VCAL : 6;	 /*!< [21:16] LDO33??稳压器输出电压微调值??该位字段指示??6??位??ADC??BIST??微调值偏移，如果需要生产微调，则添加到固件从闪存配置扇区安装的??LDO33??输出电平值  */
				__I uint32_t RESERVE : 2;	 /*!< [23:22] 保留位  */
				__I uint32_t DCDC11VCAL : 6; /*!< [29:24] DCDC11??稳压器输出电压调整值:该位字段表示??5??位??ADC??BIST??微调值偏移添加到由固件从闪存配置扇区安装的??DCDC11??输出电平值，如PMC_CAL.DCDC11VCAL??中配置  */
				__I uint32_t RESERVE : 2;	 /*!< [31:30] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_CALSTA_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t ADCS11 : 8;  /*!< [7:0] ADC??转换结果；?该位字段包含次级监视器对??VDD11/DCDC11??电源的??ADC??测?的最后转换结果。如果通过??PMC_MONCTL.DCDC11xxMOD??激活次级过压或欠压监控，则会?新此位字段,VIN??=??[LSB??*??(ADCx?1)]?,LSB??=??5.7692??mV??全?程:1465mV如:?1.25??V??=??DA  */
				__I uint32_t ADCS33 : 8;  /*!< [15:8] VDD33??电源次级??ADC??转换结果该位字段包含次级监视器对??VDD33/LDO33??电源的??ADC??测?的最后转换结果。如果通过PMC_MONCTL.LDO33xxMOD方式激活二次过压或欠压监控，则?新此位域,VIN=[LSB*(ADCx-1)],IdealLSB=15.00mVFullRange:3810mVE.g.3.30V=DD  */
				__I uint32_t ADCSPWR : 8; /*!< [23:16] VCC次级ADC转换结果:该位字段包含外部??VCC??(3.3V?/??5V)??电源的??ADC??测?的最后转换结果次级监视器。如果通过??PMC_MONCTL.SWDxxMOD??激活次级过压或欠压监控，则会?新此位域；VIN??=??[LSB??*??(ADCx?1)]?,??LSB??=??23.077??mV全?程:5861??mV??例如5.01??V??=??DA??3.3??V??=??90  */
				__I uint32_t ACTCNT : 6;  /*!< [29:24] 次级监视器活动计数器??该位字段对所有通道和相应过滤器配置的单个次级监视器背景扫描中的转换信号结束进?累积计数,转换总数??ConvTot??=??∑??[ChX*??ChXFIL]计数器在??ConvTot??溢出时重置为??0  */
				__I uint32_t RESERVE : 2; /*!< [31:30] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SMONSTA1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t ADC11BKP : 8;	/*!< [7:0] VDD11BKP??电源次级ADC??转换结果??该位字段包含次级监视器对??VDD11BKP??电源的ADC??测?的最后转换结果。如果通过PMC_MONCTL.PRExxMOD激活二次过压或欠压监控，则?新此位域；VIN=[LSB*(ADCx-1)],IdealLSB=5.7692mVFullRange:1465mVE.g.1.25V=DA  */
				__I uint32_t ADCVDDBKP : 8; /*!< [15:8] VDDBKP?电源次级?ADC?转换结果??该位字段包含次级监视器对外部VDDBKP??(3.3V?/??5V)??备用电源的?ADC??测?的最后转换结果。如果通过PMC_MONCTL.SBxxMOD??激活次级过压或欠压监控，则会?新此位域,VIN=[LSB*(ADCx-1)],IdealLSB=23.077mVFullRange:5861mVE.g.5.01V=DA3.0V=90  */
				__I uint32_t ADCVDDA : 8;	/*!< [23:16] VDDA??电源次级??ADC??转换结果??该位字段包含次级监视器对??VDDA??ADC??电源的??ADC??测?的最后转换结果。如果通过PMC_MONCTL.VDDAxxMOD激活二次过压或欠压监控，则?新此位域,VIN=[LSB*(ADCx-1)],IdealLSB=23.077mVFullRange:5861mVE.g.5.01V=DAD3.0V=90D  */
				__I uint32_t RESERVE : 8;	/*!< [31:24] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SMONSTAT2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DCDC11OMOD : 2;	/*!< [1:0] VDD11??过压监控模式?:如果??DCDC11OMOD??=??00B和??DCDC11UMOD??=??00B?，则相应电源轨的??ADC??转换?会发生  */
				__IO uint32_t LDO11BKPOMOD : 2; /*!< [3:2] LDO11BKP?或?VDD11BKP?过压监控模式:?如果LDO11BKPOVMOD?=?00B和LDO11BKPUVMOD?=?00B?，则相应电源轨的??ADC??转换?会发生  */
				__IO uint32_t DCDC11UMOD : 2;	/*!< [5:4] VDD11??欠压监控模式??如果??DCDC11OMOD??=??00B和??DCDC11UMOD??=??00B?，则相应电源轨的??ADC??转换?会发生  */
				__IO uint32_t LDO11BKPUMOD : 2; /*!< [7:6] LDO11BKP或VDD11BKP欠压监控模式?:如果??LDO11BKPOMOD?=?00B和?LDO11BKPUMOD?=?00B?，则相应电源轨的??ADC??转换?会发生  */
				__IO uint32_t LDO33OMOD : 2;	/*!< [9:8] VDD33电源过压监控模式:如果?LDO33OMOD?=?00B和?LDO33UMOD?=?00B?，则相应电源轨的??ADC??转换?会发生  */
				__IO uint32_t VDDAOMOD : 2;		/*!< [11:10] VDDA?ADC电源过压监控模式??如果VDDAOMOD=00B和??VDDAUMOD?=?00B?，则??VDDA??电源轨的??ADC??转换继续运?，用于ADC功能  */
				__IO uint32_t LDO33UMOD : 2;	/*!< [13:12] VDD33电源欠压监控模式??如果?LDO33OMOD?=?00B和?LDO33UMOD?=?00B?，则相应电源轨的??ADC??转换?会发生  */
				__IO uint32_t VDDAUVMOD : 2;	/*!< [15:14] VDDA??ADC??电源欠压监控模式??如果??VDDAOMOD??=??00B和??VDDAUMOD??=??00B?，则??VDDA??电源轨的??ADC??转换继续运?，用于ADC功能  */
				__IO uint32_t PWROMOD : 2;		/*!< [17:16] VCC过压监测模式??如果PWROMOD?=?00B和??PWRUMOD=00B?，则相应电源轨的??ADC??转换?会发生  */
				__IO uint32_t VDDBKPOMOD : 2;	/*!< [19:18] EVR??备用电源或??VDDBKP??过压监控模式??如果??VDDBKPOMOD??=??00B和VDDBKPUMOD??=??00B?，则相应电源轨的??ADC??转换?会发生  */
				__IO uint32_t PWRUMOD : 2;		/*!< [21:20] VCC??欠压监测模式??如果??PWROMOD??=??00B和?PWRUMOD??=??00B?，则相应电源轨的??ADC??转换?会发生  */
				__IO uint32_t VDDBKPUMOD : 2;	/*!< [23:22] EVR??备用电源或??VDDBKP??欠压监控模式??如果??VDDBKPOMOD??=??00B和VDDBKPUMOD??=??00B?，则相应电源轨的??ADC??转换?会发生  */
				__I uint32_t RESERVE : 6;		/*!< [29:24] 保留位  */
				__IO uint32_t SLCK : 1;			/*!< [30:30] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位。当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。??SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
				__I uint32_t RESERVE : 1;		/*!< [31:31] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SMONCTL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DCDC11FIL : 4;   /*!< [3:0] VDD11??次级??ADC??电源滤波器  */
				__IO uint32_t VDD11BKPFIL : 4; /*!< [7:4] VDD11BKP??次级??ADC??电源滤波器  */
				__IO uint32_t LDO33FIL : 4;	   /*!< [11:8] VDD33??次级??ADC??电源滤波器  */
				__IO uint32_t VDDAFIL : 4;	   /*!< [15:12] VDDA??次级??ADC??电源滤波器  */
				__IO uint32_t PWRFIL : 4;	   /*!< [19:16] VCC??次级??ADC??电源滤波器  */
				__IO uint32_t VDDBKPFIL : 4;   /*!< [23:20] VDDBKP??次级??ADC??电源滤波器  */
				__I uint32_t RESERVE : 5;	   /*!< [28:24] 保留位  */
				__IO uint32_t CLRFIL : 1;	   /*!< [29:29] 清除所有尖峰滤波器??为避免在?改配置或启动期间出现虚假警报，应设置CLRFIL，然后重新配置警报，然后通过清除??CLRFIL??寄存器位激活滤波器逻辑  */
				__IO uint32_t SLCK : 1;		   /*!< [30:30] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位。当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。??SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
				__I uint32_t RESERVE : 1;	   /*!< [31:31] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SMONFIL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OVPWR : 1;	 /*!< [0:0] OVPWD中断在??PMC_MONCTL??寄存器中配置的事件触发  */
				__IO uint32_t UVPWR : 1;	 /*!< [1:1] UVPWD??中断启用中断触发事件,如??PMC_MONCTL??寄存器中配置  */
				__IO uint32_t OV33 : 1;		 /*!< [2:2] OV33中断启用中断触发事件,如??PMC_MONCTL??寄存器中配置  */
				__IO uint32_t UV33 : 1;		 /*!< [3:3] UV33中断启用中断触发事件,如??PMC_MONCTL??寄存器中配置  */
				__IO uint32_t OV11 : 1;		 /*!< [4:4] OV11中断启用中断触发事件,如??PMC_MONCTL??寄存器中配置  */
				__IO uint32_t UV11 : 1;		 /*!< [5:5] UV11中断启用中断触发事件,如??PMC_MONCTL??寄存器中配置  */
				__IO uint32_t OLDO11BKP : 1; /*!< [6:6] OLDO11BKP中断启用中断触发事件,如??PMC_MONCTL??寄存器中配置  */
				__IO uint32_t ULDO11BKP : 1; /*!< [7:7] ULDO11BKP中断启用中断触发事件,如??PMC_MONCTL??寄存器中配置  */
				__IO uint32_t OVDDA : 1;	 /*!< [8:8] OVDDA中断启用中断触发事件如,?PMC_MONCTL??寄存器中配置  */
				__IO uint32_t UVDDA : 1;	 /*!< [9:9] UVDDA中断启用中断触发事件,如?PMC_MONCTL??寄存器中配置  */
				__IO uint32_t OVDDBKP : 1;	 /*!< [10:10] OVDDBKP中断启用中断触发事件,如?PMC_MONCTL??寄存器中配置  */
				__IO uint32_t UVDDBKP : 1;	 /*!< [11:11] UVDDBKP中断启用中断触发事件,如PMC_MONCTL??寄存器中配置  */
				__I uint32_t RESERVE : 4;	 /*!< [15:12] 保留位  */
				__IO uint32_t DCDC11MOD : 1; /*!< [16:16] DCDC11MOD中断启用?:在??PMC_PSTA.DCDC11MOD[0]??位字段的状态?改时触发的中断  */
				__IO uint32_t SDVOK : 1;	 /*!< [17:17] SDVOK中断启用?:在PMC_PSTA.SDVOK??上升沿事件上触发中断  */
				__IO uint32_t SYNCLCK : 1;	 /*!< [18:18] SD??SYNCLCK中断启用?:在PMC_PSTA.SYNCLCK??位字段的状态?改时触发中断  */
				__IO uint32_t PWRLVL : 1;	 /*!< [19:19] PWRLVL中断启用?:在PMC_PSTA.SWDLVL??位字段的状态?改时触发中断  */
				__I uint32_t RESERVE : 1;	 /*!< [20:20] 保留位  */
				__IO uint32_t WUTWKP : 1;	 /*!< [21:21] WUTWKP中断启用?:在??WUTCNT??下溢事件上触发的中断  */
				__IO uint32_t ESR0WKP : 1;	 /*!< [22:22] ESR0WKP中断使能:中断在??ESR0WKP?事件上触发  */
				__IO uint32_t ESR1WKP : 1;	 /*!< [23:23] ESR1WKP中断启用??:在??ESR1WKP??事件上触发中断  */
				__IO uint32_t PINAWKP : 1;	 /*!< [24:24] PINAWKP中断启用?:在??PINAWKP??事件上触发的中断  */
				__IO uint32_t PINBWKP : 1;	 /*!< [25:25] PINBWKP中断启用?:在??PINBWKP??事件上触发的中断  */
				__I uint32_t RESERVE : 6;	 /*!< [31:26] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_IE_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DCDC11UVAL : 8; /*!< [7:0] VDD11??电源次级监视器欠压阈值??该字段定义??DCDC11??稳压器输出或??VDD??电源的欠压监视阈值水平,IdealThreshold=[(VIN/LSB)+1]IdealLSB=5.7692mV  */
				__IO uint32_t LDO33UVAL : 8;  /*!< [15:8] VDD33?电源次级监视器欠压阈值??该字段定义??LDO33??稳压器输出或??VDD33??电源的欠压监视阈值水平,IdealThreshold=[(VIN/LSB)+1].IdealLSB=15.00mV  */
				__IO uint32_t PWRUVAL : 8;	  /*!< [23:16] VCC??电源次级监控器欠压阈值该字段定义外部??VCC??电源监控器的欠压阈值水平IdealThreshold=[(VIN/LSB)+1]IdealLSB=23.077mV.  */
				__I uint32_t RESERVE : 6;	  /*!< [29:24] 保留位  */
				__IO uint32_t SLCK : 1;		  /*!< [30:30] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位。当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。??SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_UVMON0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DCDC11OVAL : 8; /*!< [7:0] VDD11电源次级监视器上溢电压阈值:此字段定义??DCDC11??稳压器输出或VDD11??电源的过压监控阈值水平IdealThreshold=[(VIN/LSB)+1]IdealLSB=5.7692mV  */
				__IO uint32_t LDO33OVAL : 8;  /*!< [15:8] VDD33电源次级监视器上溢电压阈值:此字段定义??LDO33??稳压器输出或VDD33??电源的过压监控阈值水平IdealThreshold=[(VIN/LSB)+1]IdealLSB=15.00mV  */
				__IO uint32_t PWROVAL : 8;	  /*!< [23:16] VCC电源次级监视器上溢电压阈值:?该字段定义外部??VCC??电源监视器的过电压阈值水平IdealThreshold=[(VIN/LSB)+1]IdealLSB=23.077mV.  */
				__I uint32_t RESERVE : 6;	  /*!< [29:24] 保留位  */
				__IO uint32_t SLCK : 1;		  /*!< [30:30] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位。当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。??SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
				__I uint32_t RESERVE : 1;	  /*!< [31:31] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_OVMON0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t VDD11BKPUVAL : 8; /*!< [7:0] VDD11BKP??电源次级监控欠压阈值??该字段定义??VDD11BKP??电源或??LDO11BKP??输出的欠压监控阈值水平IdealThreshold=[(VIN/LSB)+1]IdealLSB=5.7692mV  */
				__IO uint32_t VDDAUVAL : 8;		/*!< [15:8] VDDA电源次级监控欠压阈值?该字段定义了??VDDA??ADC??电源的欠压监控阈值水平。IdealThreshold=[(VIN/LSB)+1]IdealLSB=23.077mV  */
				__IO uint32_t VDDBKPUVAL : 8;	/*!< [23:16] VDDBKP??电源次级监视器欠压阈值??该字段定义外部??VDDBKP??(3.3V?/??5V)??备用电源监视器的欠压阈值水平IdealThreshold=[(VIN/LSB)+1]IdealLSB=23.077mV.  */
				__IO uint32_t VDDAVSEL : 6;		/*!< [29:24] VDDA??电平选择:该字段定义了ADCs模块区分?5V?或??3.3??V??VDDA??电源电平以将模拟?为调整为实际电压电平所需的欠压监控阈值电平。??ADC??结果的??6??MSB??位与具有??4??LSB??滞后的??VDDALVLSEL??进?比较IdealThreshold=[(VIN/LSB)+1]IdealLSB=92.308mV  */
				__IO uint32_t SLCK : 1;			/*!< [30:30] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位。当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
				__I uint32_t RESERVE : 1;		/*!< [31:31] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_UVMON1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t VDD11BKPOVAL : 8; /*!< [7:0] VDD11BKP??电源次级监控器过压阈值??该字段定义??VDD11BKP??电源或??LDO11BKP??输出的过压监控阈值水平,IdealThreshold=[(VIN/LSB)+1]IdealLSB=5.7692mV  */
				__IO uint32_t VDDAOVAL : 8;		/*!< [15:8] VDDA??电源次级监控器过压阈值??该字段定义了??VDDA??ADC??电源的过压监控阈值水平,IdealThreshold=[(VIN/LSB)+1]IdealLSB=23.077mV  */
				__IO uint32_t VDDBKPOVAL : 8;	/*!< [23:16] VDDBKP??电源次级监视器过压阈值??该字段定义外部??VDDBKP??(3.3V?/??5V)??备用电源监视器的过压阈值水平,IdealThreshold=[(VIN/LSB)+1]IdealLSB=23.077mV  */
				__I uint32_t RESERVE : 6;		/*!< [29:24] 保留位  */
				__IO uint32_t SLCK : 1;			/*!< [30:30] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位。当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
				__I uint32_t RESERVE : 1;		/*!< [31:31] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_OVMON1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DCDC11UVAL : 8; /*!< [7:0] VDD11??电源主监视器警报欠压阈值??该字段定义??DCDC11??稳压器输出或??VDD??电源的欠压监视阈值水平,DCDC11UVVAL=[(VDDx-712.5mV)/LSB]LSB=5mV  */
				__IO uint32_t LDO33UVAL : 8;  /*!< [15:8] VDD33???电源主监视器警报欠压阈值??此字段定义??LDO33??稳压器输出或VDD33??电源的欠压监控阈值水平,LDO33UVVAL=[(VDDx-937.5mV)/LSB]LSB=15mV  */
				__IO uint32_t PWRUVAL : 8;	  /*!< [23:16] VCC??电源主监视器警报欠压阈值??该字段定义外部??VCC??电源监视器的欠压阈值水平,SWDUVVAL=[(VDDx-1050mV)/LSB]LSB=20mV  */
				__IO uint32_t DCDC11DIS : 1;  /*!< [24:24] VDD主监控器UV警报警用  */
				__IO uint32_t LDO33DIS : 1;	  /*!< [25:25] VDD33主监控器UV警报警用  */
				__IO uint32_t PWRDIS : 1;	  /*!< [26:26] VCC??主监视器??UV??警报禁用  */
				__IO uint32_t HSMFIL : 4;	  /*!< [30:27] HSM电压滤波器  */
				__IO uint32_t SLCK : 1;		  /*!< [31:31] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位。当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
			} bits;
			__IO uint32_t reg;
		};
	} HSM_UVMON_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DCDC11OVAL : 8; /*!< [7:0] VDD11电源主监控器上溢警报电压阈值:此字段定义??DCDC11??稳压器输出或??VDD11??电源的过压监控阈值水平；DCDC11OVVAL=[(VDDx-712.5mV)/LSB]LSB=5mV  */
				__IO uint32_t LDO33OVAL : 8;  /*!< [15:8] VDD33电源主监控器上溢警报电压阈值:此字段定义??LDO33??稳压器输出或VDD33??电源的过压监控阈值水平；LDO33OVVAL=[(VDDx-937.5mV)/LSB]LSB=15mV  */
				__IO uint32_t PWROVAL : 8;	  /*!< [23:16] VCC电源主监控器上溢警报电压阈值:此字段定义外部??VCC??电源监视器的过压阈值水平；SWDOVVAL=[(VDDx-1050mV)/LSB]LSB=20mV  */
				__IO uint32_t DCDC11DIS : 1;  /*!< [24:24] VDD主监视器??UV??警报禁用  */
				__IO uint32_t LDO33DIS : 1;	  /*!< [25:25] VDD33主监视器??UV??警报禁用  */
				__IO uint32_t PWRDIS : 1;	  /*!< [26:26] VCC??主监视器??OV??警报禁用  */
				__IO uint32_t RESERVE : 4;	  /*!< [30:27] 保留位  */
				__IO uint32_t SLCK : 1;		  /*!< [31:31] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位。当??SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。??SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
			} bits;
			__IO uint32_t reg;
		};
	} HSM_OVMON_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SHVH33 : 8; /*!< [7:0] 短?至电源电压阈值:该字段定义了??VDD33??电源的上限阈值电平。??LDO33??电源短?警报的标称值为?SHVH33=4.5Vandt33SHHV=3ms.?要?改复位值SHVH33=[(VDDx-937.5mV)/LSB]LSB=15mV  */
				__IO uint32_t RES : 4;	  /*!< [11:8] 保留位，必须被写入原始值  */
				__IO uint32_t SHHVEN : 1; /*!< [12:12] 对高短?检测启用  */
				__IO uint32_t SHLVEN : 1; /*!< [13:13] 对低短?检测启用  */
				__IO uint32_t RES : 2;	  /*!< [15:14] 保留位，必须被写入原始值  */
				__IO uint32_t SHVL33 : 8; /*!< [23:16] 对地短?电压阈值:该字段定义了??VDD33??电源的下限阈值。??LDO33??接地短?警报的标称值为??SHVL33??=??1V??和??t33SHLV??=??3ms?要?改复位值SHVL33=[(VDDx-937.5mV)/LSB]LSB=15mV  */
				__IO uint32_t RES : 5;	  /*!< [28:24] 保留位，必须被写入原始值  */
				__O uint32_t RES : 1;	  /*!< [29:29] 读该位为0，该位必须写0  */
				__IO uint32_t SLCK : 1;	  /*!< [30:30] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位。当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。??SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
				__I uint32_t RESERVE : 1; /*!< [31:31] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_LDO33CTL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OSCFCAL : 6;	   /*!< [5:0] 备用时钟微调值:该位字段包含有关??100MHz??OSC??微调的信息。fBACKftrim=[(OSCFCAL+(OSCFPCAL))*LSBFT]MHz,LSBFT=110kHzdatatsheet中记录了??LSBFT??=??110kHz??备用时钟精度。建议在每个微调步骤后等待1??us，以?时钟源稳定在新频率。fBACK??ftrim??值饱和到??64??的范围  */
				__I uint32_t RESERVE : 10;	   /*!< [15:6] 保留位  */
				__IO uint32_t OSCFPCAL : 6;	   /*!< [21:16] OSC??微调带符号值:??该位字段允许器件在应用期间单独微调振荡器微调值。?新trim??值后，需要??1??us??的等待时间才能使?改生效  */
				__I uint32_t RESERVE : 7;	   /*!< [28:22] 保留位  */
				__IO uint32_t OSCTEMPOFFS : 1; /*!< [29:29] 振荡器温度偏移系数??该位域启用??HPOSC??温度系数的居中功能以补偿技术差异  */
				__I uint32_t RESERVE : 1;	   /*!< [30:30] 保留位  */
				__IO uint32_t OSCCALEN : 1;	   /*!< [31:31] 动态振荡器微调启用??根据温度，可以微调振荡器  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_OSCCTL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t ADCFBCV : 8;  /*!< [7:0] 降压转换器内核电压反馈??ADC??转换结果??该位字段指示降压转换器反馈??ADC??测???VDD??内核电压的最后一次??ADC??转换结果,VIN=[LSB*(ADCFBCV-PMC_CAL.DCDC11VCAL)+0.7125]V,LSB=5mVE.g.1.20V-62-98  */
				__I uint32_t RESERVE : 8;  /*!< [15:8] 保留位  */
				__I uint32_t DPWMOUT : 12; /*!< [27:16] DPWM??控制输出状态??该位字段反映控制器提供给外部??MOSFET??开关的实际PWM??输出  */
				__I uint32_t RESERVE : 4;  /*!< [31:28] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDSTA0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SDFREQSPRD : 16; /*!< [15:0] 频率扩展阈值:该位域定义了运?期间对标称??DCDC11??稳压器开关频率的附加频率扩展??  */
				__IO uint32_t SDFREQ : 12;	   /*!< [27:16] 稳压器开关频率或过采样因子:该位字段在闭环操作期间配置??DCDC11??稳压器开关频率。开关频率等于??(100??MHz?/??(SDFREQ+1))??值。??SDFREQ??表示一个周期内相应的过采样因子或时钟周期037H:1.82MHz(100MHz/(54+1))SMPSswitchingfrequency07DH:0.8MHz(100MHz/(124+1))SMPSswitchingfrequency  */
				__IO uint32_t NGOFF : 1;	   /*!< [28:28] SMPS??开关频率??NMOS??关断状态期间的电平:该位字段配置??N?沟道?MOSFET??驱动器启动和关闭阶段的状态。  */
				__IO uint32_t PGOFF : 1;	   /*!< [29:29] OFF??状态下的PMOS??电平:该位字段配置??P沟道?MOSFET??驱动器启动和关闭阶段的状态  */
				__IO uint32_t UP : 1;		   /*!< [30:30] SMPS??寄存器值的?新请求??该位域触发将当前寄存器值从??PMS??FPI??DCDC11??寄存器?新到本地??SMPS??模块寄存器,在发出?新请求之前，应确保所有PMC_SDCTLx??和??PMC_SDFCTx??寄存器在各种寄存器中具有正确且一致的值。在单个寄存器?新的情况下，其他寄存器值应该匹配并保持一致。在冷??PORST?之后，UP??位被设置为默认复位值，以确保将完整的??SMPS??稳压器参数集设置回其复位状态。因此，UP??位被复位，读取结果为??0。在启动和低功耗模式下?允许通过??UP??位?新参数  */
				__I uint32_t LCK : 1;		   /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t M0TDIS : 8;	/*!< [7:0] 最小关断时间:该位域配置在闭环操作期间在??100MHz??时钟周期周期内一个周期内的最小关闭时间  */
				__IO uint32_t M0TON : 8;	/*!< [15:8] 最小开启时间:该位域配置在闭环操作期间在??100MHz??时钟周期周期内一个周期内的最小导通时间  */
				__IO uint32_t M0S0FCT : 4;	/*!< [19:16] S0系数:该位域指示闭环操作期间的??S0??系数  */
				__IO uint32_t M0DEADBD : 2; /*!< [21:20] 死区?:该位域指定死区以在闭环操作期间阻止??ADC??纹波  */
				__IO uint32_t M0ADCZB : 2;	/*!< [23:22] ADCZeroBin:该位域指定闭环操作期间的ZeroBin  */
				__IO uint32_t M0SKIP : 4;	/*!< [27:24] 跳跃脉冲阈值:该位域指定在闭环操作期间检测跳跃脉冲条件的阈值(N沟道MOSFET)  */
				__I uint32_t RESERVE : 3;	/*!< [30:28] 保留位  */
				__I uint32_t LCK : 1;		/*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t LPBNDOFFSET : 2; /*!< [3:2] 低功耗模式迟滞??OFFSET:该位域定义了??LP??模式下的开启阈值  */
				__IO uint32_t LPBNDWIDTH : 4;  /*!< [7:4] 低功耗模式迟滞带宽:该位域定义了??LP??模式下的开启阈值  */
				__IO uint32_t LPLPFFCT : 4;	   /*!< [11:8] 低通滤波器系数:该位字段配置低通滤波器系数，用于设置滑动功能的开启阈值  */
				__I uint32_t RESSERVE : 4;	   /*!< [15:12] 保留位  */
				__IO uint32_t SDFREQLP : 12;   /*!< [27:16] 稳压器过采样因子:该位域配置低功耗模式期间的??DCDC11??稳压器??FB??ADC??采样周期。开关频率?是恒定的。037H:1.82MHz(100MHz/55)07DH:0.8MHz(100MHz/125)0C8H:0.5MHz(100MHz/200)  */
				__I uint32_t RESSERVE : 2;	   /*!< [29:28] 保留位  */
				__IO uint32_t DCDC11MOD : 1;   /*!< [30:30] LPM??或??PWM??DCDC11??模式激活?:该位在?PWM?和?LPM?模式之间切换操作模式  */
				__I uint32_t LCK : 1;		   /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t M1TOFF : 8;	/*!< [7:0] 最小关断时间:该位域配置在闭环操作期间在??100MHz??时钟周期周期内一个周期内的最小关闭时间  */
				__IO uint32_t M1TON : 8;	/*!< [15:8] 最小时间:该位域配置??LP??模式期间??100MHz??时钟周期周期内一个周期内的最小导通时间  */
				__IO uint32_t M1S0FCT : 4;	/*!< [19:16] S0系数:该位域指示??LP??模式期间的??S0??系数  */
				__IO uint32_t M1DEADBD : 2; /*!< [21:20] 死区:该位字段指定死区以阻止??LP??模式期间的??ADC??纹波  */
				__IO uint32_t M1ADCZB : 2;	/*!< [23:22] ADCZeroBin:该位字段指定??LP??模式期间的ADCZeroBin  */
				__IO uint32_t M1SKIP : 4;	/*!< [27:24] 跃脉冲阈值:该位字段在??LPM??模式下被禁用，因为??PFM??由控件本身应用  */
				__I uint32_t RESERVE : 4;	/*!< [31:28] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t VOKCFG : 6;	 /*!< [5:0] 电压正常电?配置:待定  */
				__I uint32_t RESERVE : 10;	 /*!< [15:6] 保留位  */
				__IO uint32_t SDFREQST : 12; /*!< [27:16] 稳压器开关频率或过采样因子:该位字段在闭环启动期间配置??DCDC11??稳压器开关频率。开关频率等于??(100??MHz?/??SDFREQ)??值。SDFREQ代表对应的过采样因子,037H:1.82MHz(100MHz/55)SMPS开关频率07DH:0.8MHz(100MHz/125)SMPS开关频率0C8H:0.5MHz(100MHz/200)SMPS开关频率  */
				__I uint32_t RESERVE : 4;	 /*!< [31:28] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t M2TOFF : 8;	/*!< [7:0] 最小关断时间:该位域配置在闭环操作期间在??100MHz??时钟周期周期内一个周期内的最小关闭时间  */
				__IO uint32_t M2TON : 8;	/*!< [15:8] 最小时间:该位域配置在闭环操作期间在??100MHz??时钟周期周期内一个周期内的最小导通时间  */
				__IO uint32_t M2S0FCT : 4;	/*!< [19:16] S0系数:该位域指示闭环操作期间的??S0??系数  */
				__IO uint32_t M2DEADBD : 2; /*!< [21:20] 死区?:该位域指定死区以在闭环操作期间阻止??ADC??纹波  */
				__IO uint32_t M2ADCZB : 2;	/*!< [23:22] ADCZeroBin:该位域指定闭环操作期间的ZeroBin  */
				__IO uint32_t M2SKIP : 4;	/*!< [27:24] 跳跃脉冲阈值:该位域指定在闭环操作期间检测跳跃脉冲条件的阈值(N沟道MOSFET)  */
				__I uint32_t RESERVE : 4;	/*!< [31:28] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL5_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SVINTH : 8; /*!< [7:0] 在??SINCLO??或??SINCHI??之间切换的??Vin??阈值:该位字段指定阈值以决定启动期间的斜坡上升增?。如果??Vin??低于阈值，SINCLO??被视为斜升增?，否则如果Vin??等于或高于阈值，SINCHI??被视为斜升增?。阈值与??FF?ADC??计数器值进?比较，没有偏移  */
				__IO uint32_t SVOTH : 8;  /*!< [15:8] 从开环启动切换到闭环模式的??Vout??阈值:该位字段指定阈值以决定在启动期间何时从开环模式切换到闭环模式。如果??Vout??低于阈值，则执?开环斜升。如果Vout??等于或高于阈值，则执?启动配置中的闭环??PWM。将阈值与低通滤波后的FB?ADC?计数器值进?比较，无偏移。切换仅在启动期间发生在一个方向，即使在另一个方向超过阈值，系统也?会切换回启动模式  */
				__IO uint32_t SINCLO : 3; /*!< [18:16] 低输入电压的增?:该位域指定启动期间开环斜坡上升期间的导通时间增?。如果Vin??低于阈值??(SVINTH)，则??SINCLO?被视为斜升增?。如果??Vin??等于或高于阈值(SVINTH)，则??SINCHI??被视为高输入电压的斜升增?增?  */
				__I uint32_t RESERVE : 1; /*!< [19:19] 保留位  */
				__IO uint32_t SINCHI : 3; /*!< [22:20] 该位域指定启动期间开环斜坡上升期间的导通时间增?。如果??Vin??低于阈值(SVINTH)，则??SINCLO?被视为斜升增?。如果??Vin??等于或高于阈值??(SVINTH)，则SINCHI??被视为斜升增?  */
				__I uint32_t RESERVE : 8; /*!< [30:23] 保留位  */
				__I uint32_t LCK : 1;	  /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL6_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DRVNI : 2;	  /*!< [1:0] N驱动电流的选择:N驱动电流的可调驱动强度  */
				__IO uint32_t DRVPCBF : 2;	  /*!< [3:2] P??驱动器电流升压因子:P??驱动器电流的可调升压系数  */
				__IO uint32_t DRVP : 4;		  /*!< [7:4] P??驱动器电流:以??3.3V?/??5V??驱动时??P??沟道??MOSFET??的基极驱动电流0H:5,3mA/7,8mA1H:6,3mA/9,4mA2H:7,4mA/11mA3H:8,4mA/12,5mA4H10,5mA/15,6mA5H:12,6mA/18,7mA6H:14,7mA/21,8mA7H17,8mA/26,4mA8H:20,9mA/31mA9H:25mA/37,1mAAH29,1mA/43,2mABH:35,3mA/52,3mACH:41,4mA/61,4mADH:49,6mA/73,4mAEH:58,8mA/87mAFH:69,9mA/103,5mA  */
				__IO uint32_t DRVSLOMODE : 2; /*!< [9:8] 开关配置:该位域配置开关类型  */
				__I uint32_t RESERVE : 6;	  /*!< [15:10] 保留位  */
				__IO uint32_t DRVSPR : 8;	  /*!< [23:16] 备用位  */
				__IO uint32_t SYNCDIVFAC : 3; /*!< [26:24] 外同步开关分频系数:该位字段定义??SMPS??开关输出的分频器因子，以生成DDCCSYNCO??输出，从而使外部稳压器与内部??DCDC11??稳压器同步。如果通过PMSWCR5.DDCCSYNCO??位启用，则信号?由到引脚.保留所有其他组合000BfDCDCSYNCO=fDCDC.实际占空比已被选择.001BfDCDCSYNCO=fDCDC/2.实际占空比恒定在50%.010BfDCDCSYNCO=fDCDC/4.实际占空比恒定在50%.011BfDCDCSYNCO=fDCDC/8.实际占空比恒定在50%.100BfDCDCSYNCO=fDCDC/16.实际占空比恒定在50%101BfDCDCSYNCO=fDCDC/32.实际占空比恒定在50%.  */
				__I uint32_t RESERVE : 4;	  /*!< [30:27] 保留位  */
				__I uint32_t LCK : 1;		  /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL7_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t FBADCOFFS : 8; /*!< [7:0] 反馈转换计数器值偏移?(fbadc2_offset_i):该位域配置测?核心电压的反馈ADC??的转换计数器值的偏移?  */
				__IO uint32_t FBADCSMP : 6;	 /*!< [13:8] FB??ADC??采样周期(fbadc1_smpthr_i):该位域以??100??MHz??时钟周期为单位配置采样周期，用于测?核心电压的反馈??ADC  */
				__I uint32_t RESERVE : 2;	 /*!< [15:14] 保留位  */
				__IO uint32_t FBADCBLNK : 2; /*!< [17:16] FB??ADC??消隐样本数??(fbadc0_blank_i):该位域配置在??PWM??驱动输出转换时消隐的反馈??ADC??样本数，以最大限度地减少开关噪声影响  */
				__I uint32_t RESERVE : 2;	 /*!< [19:18] 保留位  */
				__IO uint32_t FBADCLPF : 2;	 /*!< [21:20] FB??ADC??计数器??LPF??系数??(fbadc0_lpfcnt_i):该位字段配置测?核心电压的反馈ADC??计数器值的低通滤波器的系数。y??[k]??=??{?y??[k?1]??*??(1?a)?}??+??{?x??[k]??*??a}?,??y??[k]??是滤波器输出；??x??[k]??是?ADC??输出??a??=??{1?/??(2??^??LPF)}。如果??LPF??=??0，则滤波器输出与??ADC??输出相同  */
				__I uint32_t RESERVE : 2;	 /*!< [23:22] 保留位  */
				__IO uint32_t FBADCERR : 2;	 /*!< [25:24] FB??ADC??误差??LPF??系数??(fbadc3_lpferr_i):该位域配置反馈??ADC??输出电压误差信号的低通滤波器系数  */
				__I uint32_t RESERVE : 2;	 /*!< [27:26] 保留位  */
				__IO uint32_t FBADCLSB : 1;	 /*!< [28:28] 用于误差计算的??FB??ADC??LSB??(fbadc3_lsb_i):该位域配置用于错误计算的反馈ADC??计数器值的??LSB  */
				__I uint32_t RESERVE : 2;	 /*!< [30:29] 保留位  */
				__I uint32_t LCK : 1;		 /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL8_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t FFADCOFFS : 8; /*!< [7:0] 前馈转换计数器值偏移?(ffadc1_offset_i):该位字段配置测?输入??VCC??电压的前馈ADC??的转换计数器值的偏移?  */
				__IO uint32_t FFADCLPF : 3;	 /*!< [10:8] FF??ADC??计数器??LPF??系数??(ffadc0_lpfcnt_i):该位字段配置测?输入??VCC??电压的前馈??ADC??计数器值的低通滤波器系数。y??[k]??=??{?y??[k?1]??*??(1?a)?}??+??{?x??[k]??*??a}?,??y??[k]??是滤波器输出；??x??[k]??是ADC??输出??a??=??{1?/??(2??^??LPF)}。如果??LPF??=??0，则滤波器输出与??ADC??输出相同  */
				__I uint32_t RESERVE : 20;	 /*!< [30:11] 保留位  */
				__I uint32_t LCK : 1;		 /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL9_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t SHVH : 8;	   /*!< [7:0] 短?到高压阈值(shrth1_shvh_i):高电压阈=??(SDVOUTSEL??+??SHVH??x??5??mV)。DCDC11??电源短?警报具有??1.9V??的??SHVH??标称值和??3ms??的??tCSHHV??标称值  */
				__IO uint32_t SHVL : 8;	   /*!< [15:8] 短?至低压阈值??(shrtl1_shvl_i):低电压阈值??=??(SDVOUTSEL?????SHVL??x??5??mV)。DCDC11??对地短?报警具有??0.8V??的??SHVL??和??3ms??的??tCSHLV??标称值  */
				__I uint32_t RESERVE : 12; /*!< [27:16] 保留位  */
				__IO uint32_t SHHVEN : 1;  /*!< [28:28] 短?到高检测启用(shrth0_shhven_i)  */
				__IO uint32_t SHLVEN : 1;  /*!< [29:29] 低电平短?检测启用??(shrtl0_shlven_i)  */
				__I uint32_t RESERVE : 2;  /*!< [31:30] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL10_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t DROOPVH : 5;	  /*!< [4:0] Droop??请求的高??VDD??限制?(droopvh_thres_i):该位字段定义了??VDD??高压限制，高于该限制时应忽略对??VDD??电压的正压降请求,VDD压降上限=712.5??mV??+??LSB??*??(SDVOUTSEL+??DCDC11VCAL+??DROOPVH)；LSB??=??5??mV?  */
				__I uint32_t RESERVE : 3;	  /*!< [7:5] 保留位  */
				__IO uint32_t DROOPVL : 5;	  /*!< [12:8] Droop?请求的低??VDD??限制??(droopvl_thres_i):该位字段定义??VDD??低电压限制，低于该限制时应忽略对??VDD??电压的负压降请求；VDD压降下限?=??712.5??mV??+??LSB??*??(SDVOUTSEL+??DCDC11VCAL??DROOPVL)LSB=5mV  */
				__I uint32_t RESERVE : 3;	  /*!< [15:13] 保留位  */
				__IO uint32_t SYNCMAXDEV : 5; /*!< [20:16] 同步输入频率的最大偏差(synci1_maxdev_i):该位域定义了同步输入信号频率与编程标称??DCDC??开关频率??(PMC_SDCTL0.SDFREQ)??的最大允许频率偏差。对于锁定,PMC_SDCTL11.SYNCMAXDEV必须选择为大于或等于PMC_SDCTL11.SYNCHYST??的值，并且?等于零。违反限制导致同步丢失。频率窗口定义如下dfMAXDEV=100MHz*(2*SYNCMAXDEV)/(SDFREQ^2+SYNCMAXDEV^2)SYNCMAXDEV=round[(100MHz/dfMAXDEV)-sqrt{(100MHz/dfMAXDEV)^2-SDFREQ^2}]  */
				__I uint32_t RESERVE : 3;	  /*!< [23:21] 保留位  */
				__IO uint32_t SYNCHYST : 3;	  /*!< [26:24] 锁定解锁迟滞窗口(synci0_hyst_i):该位域定义同步锁定和解锁的滞后窗口。对于锁定，PMC_SDCTL11.SYNCHYST??必须选择为小于或等于PMC_SDCTL11.SYNCMAXDEV??的值，并且?等于零。该限制适用于以??100兆赫兹?运?的周期计数器；上解锁条件=??SDFREQ??+??SYNCMAXDEV??上锁定条件=??SDFREQ??+??SYNCMAXDEV?????SYNCHYST?下解锁条件=??SDFREQ?????SYNCMAXDEV下锁定条件=??SDFREQ?????SYNCMAXDEV??+??SYNCHYSTSYNCHYST=round[dfHYST*(SDFREQ±SYNCMAXDEV)^2]/[dfHYST*(SDFREQ±SYNCMAXDEV)+100MHz]  */
				__I uint32_t RESERVE : 1;	  /*!< [27:27] 保留位  */
				__IO uint32_t SYNCMUXSEL : 2; /*!< [29:28] 同步输入多?复用器??该位域选择来自??CCU6??或??GTM??输入的同步输入，以转发到??DCDC11??SMPS??稳压器  */
				__I uint32_t RESERVE : 1;	  /*!< [30:30] 保留位  */
				__I uint32_t LCK : 1;		  /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDCTL11_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t M0S0EN : 1;		 /*!< [0:0] S0??启用:该位域启用快进错误项  */
				__IO uint32_t M0S2EN : 1;		 /*!< [1:1] S2??启用:该位域支持电感电流的数字重构  */
				__IO uint32_t M0S3EN : 1;		 /*!< [2:2] S3??启用:该位域启用积分器  */
				__IO uint32_t M0S3CLIP : 1;		 /*!< [3:3] 该位域指定将积分器状态裁剪为负值  */
				__IO uint32_t M0S4EN : 1;		 /*!< [4:4] S4??启用:该位域启用双积分器分支  */
				__IO uint32_t M0RAMPEN : 1;		 /*!< [5:5] 斜坡启用:该位域启用人工斜坡以避免高占空比时的?稳定  */
				__IO uint32_t M0SFRGET : 1;		 /*!< [6:6] SFRGET:该位域可以在电感电流重构时启用补偿寄生效应  */
				__IO uint32_t M0SKIPEN : 1;		 /*!< [7:7] 跳跃启用:该位域启用跳跃脉冲逻辑  */
				__IO uint32_t M0S3FCT : 4;		 /*!< [11:8] S3??系数:S3?的配置寄存器-积分器系数  */
				__IO uint32_t M0S4FCT : 4;		 /*!< [15:12] S4??系数:S4??的配置寄存器-双积分器系数  */
				__IO uint32_t M0SRMPFCT : 4;	 /*!< [19:16] S??斜坡系数:S??Ramp??的配置寄存器-人工斜坡系数  */
				__IO uint32_t M0FGETFCT : 4;	 /*!< [23:20] S2??遗忘因子:该位域指定用于补偿寄生效应的遗忘因子  */
				__IO uint32_t M0S2FCT : 4;		 /*!< [27:24] S2??系数:电感电流重构系数  */
				__IO uint32_t M0S2VINSRC : 1;	 /*!< [28:28] S2??输入电压源:该位域指定用于电感电流重构的输入电压源  */
				__IO uint32_t M0S2VOSRC : 1;	 /*!< [29:29] S2??VoutSource:该位域指定用于电感电流重构的输出电压源  */
				__IO uint32_t M0SRMPFCTFRAC : 1; /*!< [30:30] S??斜坡小数系数:该位字段指定??S??斜坡小数系数  */
				__I uint32_t LCK : 1;			 /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDFCT0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t M0VOCFLPF : 4;   /*!< [3:0] LPF系数:该位域反映了应用于??FB?ADC??计数器值或编程寄存器值的??LPF??中使用的LPF??系数。??y??[k]??=??{?y[k?1]??*??(1?a)?}??+??{?x[k]??*??a}?,??y??[k]??是滤波器输出；??x??[k]??是??ADC??输出??a??=??{1?/??(2??^??LPF)}。如果??LPF??=??0，则滤波器输出与??ADC??输出相同  */
				__IO uint32_t M0VOCFINC : 4;   /*!< [7:4] 输出电压斜坡系数:该位域反映了电感电流重建中使用的输出电压斜坡的增?,应用于斜坡的阶跃??=??2??^??M0VOCFINC  */
				__IO uint32_t M0VOUT : 8;	   /*!< [15:8] 目标电压的数字表示:该位域可用于电感器电流重建，而?是??FBADC??值  */
				__IO uint32_t M0VIN : 11;	   /*!< [26:16] 输入电压的数字表示:该位域用于电感电流重构而?是??FFADC??值。绝对值，包括ADC??偏移?  */
				__IO uint32_t M0S3FCTFRAC : 2; /*!< [28:27] S3??小数系数?:该位域指定??S3??小数积分器系数  */
				__IO uint32_t M0S2FCTFRAC : 2; /*!< [30:29] S2??小数系数?:该位域指定??S2??小数积分器系数  */
				__I uint32_t LCK : 1;		   /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDFCT1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t M1S0EN : 1;	  /*!< [0:0] S0??启用:该位域启用快进错误项  */
				__IO uint32_t M1S2EN : 1;	  /*!< [1:1] S2??启用:该位域支持电感电流的数字重构  */
				__IO uint32_t M1S3EN : 1;	  /*!< [2:2] S3??启用:该位域启用积分器  */
				__IO uint32_t M1S3CLIP : 1;	  /*!< [3:3] S3:该位域指定将积分器状态裁剪为负值  */
				__IO uint32_t M1S4EN : 1;	  /*!< [4:4] S4??启用:该位域启用双积分器分支  */
				__IO uint32_t M1RAMPEN : 1;	  /*!< [5:5] 斜坡启用:该位域启用人工斜坡以避免高占空比时的?稳定  */
				__IO uint32_t M1SFRGET : 1;	  /*!< [6:6] SFRGET:该位域可以补偿电感器电流重构中的寄生效应  */
				__IO uint32_t M1SKIPEN : 1;	  /*!< [7:7] 跳跃启用:该位域启用跳跃脉冲逻辑  */
				__IO uint32_t M1S3FCT : 4;	  /*!< [11:8] S3??系数:S3?的配置寄存器-积分器系数  */
				__IO uint32_t M1S4FCT : 4;	  /*!< [15:12] S4??系数:S4??的配置寄存器-双积分器系数  */
				__IO uint32_t M1SRMPFCT : 4;  /*!< [19:16] S??斜坡系数:S??Ramp??的配置寄存器-人工斜坡系数  */
				__IO uint32_t M1FGETFCT : 3;  /*!< [22:20] S2??遗忘因子:该位域指定用于补偿寄生效应的遗忘因子  */
				__IO uint32_t M1S2FCT : 4;	  /*!< [27:24] S2??系数:电感电流重构系数  */
				__IO uint32_t M1S2VINSRC : 1; /*!< [28:28] S2??输入信号源  */
				__IO uint32_t M1S2VOSRC : 1;  /*!< [29:29] S2??Vout??Source:该位域指定用于电感电流重构的输出电压源  */
				__I uint32_t RESERVE : 2;	  /*!< [31:30] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDFCT2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t M1VOCFLPF : 4;	 /*!< [3:0] LPF系数:该位域反映了应用于??FB?ADC??计数器值或编程寄存器值的??LPF??中使用的LPF??系数。??y??[k]??=??{?y[k?1]??*??(1?a)?}??+??{?x[k]??*??a}?,??y??[k]??是滤波器输出；??x??[k]??是??ADC??输出??a??=??{1?/??(2??^??LPF)}。如果??LPF??=??0，则滤波器输出与??ADC??输出相同  */
				__IO uint32_t M1VOCFINC : 4;	 /*!< [7:4] 输出电压斜坡系数:该位域反映了电感电流重建中使用的输出电压斜坡的增?,应用于斜坡的阶跃??=??2??^??M1VOCFINC  */
				__IO uint32_t M1VOUT : 8;		 /*!< [15:8] 目标电压的数字表示:该位域可用于电感器电流重建，而?是??FBADC??值  */
				__IO uint32_t M1VIN : 11;		 /*!< [26:16] 输入电压的数字表示:该位域用于电感电流重构而?是??FFADC??值。绝对值，包括ADC??偏移?  */
				__IO uint32_t M1S3FCTFRAC : 2;	 /*!< [28:27] S3??小数系数?:该位域指定??S3??小数积分器系数  */
				__IO uint32_t M1S2FCTFRAC : 2;	 /*!< [30:29] S2?小数系数?:该位域指定??S2小数积分器系数  */
				__IO uint32_t M1SRMPFCTFRAC : 1; /*!< [31:31] S??斜坡小数系数:该位字段指定??S??斜坡小数系数  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDFCT3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t M2S0EN : 1;	  /*!< [0:0] S0??启用?:该位域启用快进错误项  */
				__IO uint32_t M2S2EN : 1;	  /*!< [1:1] S2??启用:该位域支持电感电流的数字重构  */
				__IO uint32_t M2S3EN : 1;	  /*!< [2:2] S3??启用:该位域启用积分器  */
				__IO uint32_t M2S3CLIP : 1;	  /*!< [3:3] S3:该位域指定将积分器状态裁剪为负值  */
				__IO uint32_t M2S4EN : 1;	  /*!< [4:4] S4??启用:该位域启用双积分器分支  */
				__IO uint32_t M2RAMPEN : 1;	  /*!< [5:5] 斜坡启用:该位域启用人工斜坡以避免高占空比时的?稳定  */
				__IO uint32_t M2SFRGET : 1;	  /*!< [6:6] SFRGET:该位域可以补偿电感器电流重构中的寄生效应  */
				__IO uint32_t M2SKIPEN : 1;	  /*!< [7:7] 跳跃启用:该位域启用跳跃脉冲逻辑  */
				__IO uint32_t M2S3FCT : 4;	  /*!< [11:8] S3??系数:S3?的配置寄存器-积分器系数  */
				__IO uint32_t M2S4FCT : 4;	  /*!< [15:12] S4??系数:S4??的配置寄存器-双积分器系数  */
				__IO uint32_t M2SRMPFCT : 4;  /*!< [19:16] S??斜坡系数:S??Ramp??的配置寄存器-人工斜坡系数  */
				__IO uint32_t M2FGETFCT : 4;  /*!< [23:20] S2??遗忘因子:该位域指定用于补偿寄生效应的遗忘因子  */
				__IO uint32_t M2S2FCT : 4;	  /*!< [27:24] S2??系数:电感电流重构系数  */
				__IO uint32_t M2S2VINSRC : 1; /*!< [28:28] S2??输入信号源  */
				__IO uint32_t M2S2VOSRC : 1;  /*!< [29:29] S2??VoutSource:该位域指定用于电感电流重构的输出电压源  */
				__I uint32_t RESERVE : 2;	  /*!< [31:30] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDFCT4_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t M2VOCFLPF : 4;	 /*!< [3:0] LPF系数:该位域反映了应用于??FB?ADC??计数器值或编程寄存器值的??LPF??中使用的LPF??系数。??y??[k]??=??{?y[k?1]??*??(1?a)?}??+??{?x[k]??*??a}?,??y??[k]??是滤波器输出；??x??[k]??是??ADC??输出??a??=??{1?/??(2??^??LPF)}。如果??LPF??=??0，则滤波器输出与??ADC??输出相同  */
				__IO uint32_t M2VOCFINC : 4;	 /*!< [7:4] 输出电压斜坡系数:该位域反映了电感电流重建中使用的输出电压斜坡的增?,应用于斜坡的阶跃??=??2??^??M0VOCFINC  */
				__IO uint32_t M2VOUT : 8;		 /*!< [15:8] 目标电压的数字表示:该位域可用于电感器电流重建，而?是??FBADC??值  */
				__IO uint32_t M2VIN : 11;		 /*!< [26:16] 输入电压的数字表示:该位域用于电感电流重构而?是??FFADC??值。绝对值，包括ADC??偏移?  */
				__IO uint32_t M2S3FCTFRAC : 2;	 /*!< [28:27] S3??小数系数?:该位域指定??S3??小数积分器系数  */
				__IO uint32_t M2S2FCTFRAC : 2;	 /*!< [30:29] S2??小数系数?:该位域指定??S2??小数积分器系数  */
				__IO uint32_t M2SRMPFCTFRAC : 1; /*!< [31:31] S??斜坡小数系数:该位字段指定??S??斜坡小数系数  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDFCT5_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CT5REG0 : 8; /*!< [7:0] 换向微调和斜率控制?(drv5v0_trim_i):调整外部驱动器??(5V)??的换向参数  */
				__IO uint32_t CT5REG1 : 8; /*!< [15:8] 换向微调??(drv5v1_trim_i):调整外部驱动器??(5V)??的换向参数  */
				__IO uint32_t CT5REG2 : 8; /*!< [23:16] 换向微调??(drv5v2_trim_i):调整外部驱动器??(5V)??的换向参数  */
				__I uint32_t RESERVE : 7;  /*!< [30:24] 保留位  */
				__I uint32_t LCK : 1;	   /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDFCT6_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CT5REG3 : 8; /*!< [7:0] 换向微调??(drv5v3_trim_i):调整外部驱动器??(5V)??的换向参数  */
				__IO uint32_t CT5REG4 : 8; /*!< [15:8] 换向微调??(drv5v4_trim_i):调整外部驱动器??(5V)??的换向参数  */
				__I uint32_t RESERVE : 15; /*!< [30:16] 保留位  */
				__I uint32_t LCK : 1;	   /*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDFCT7_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CT33REG0 : 8; /*!< [7:0] 换向微调??(drv3v0_trim_i):调整外部驱动器??(3.3V)??的换向参数  */
				__IO uint32_t CT33REG1 : 8; /*!< [15:8] 换向微调??(drv3v1_trim_i):调整外部驱动器??(3.3V)??的换向参数  */
				__IO uint32_t CT33REG2 : 8; /*!< [23:16] 换向微调??(drv3v2_trim_i):调整外部驱动器??(3.3V)??的换向参数  */
				__I uint32_t RESERVE : 7;	/*!< [30:24] 保留位  */
				__I uint32_t LCK : 1;		/*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDFCT8_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t CT33REG3 : 8; /*!< [7:0] 换向微调??(drv3v3_trim_i):调整外部驱动器??(3.3V)??的换向参数  */
				__IO uint32_t CT33REG4 : 8; /*!< [15:8] 换向微调??(drv3v4_trim_i):调整外部驱动器??(3.3V)??的换向参数  */
				__I uint32_t RESERVE : 15;	/*!< [30:16] 保留位  */
				__I uint32_t LCK : 1;		/*!< [31:31] 锁定状态:该位指示寄存器是否可以用新值?新，或者寄存器是否被锁定并且来自总线侧的写操作无效  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SDFCT9_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t RESERVE : 2;	  /*!< [1:0] 保留位  */
				__IO uint32_t VCCSTBYEN : 1;  /*!< [2:2] VCC??电源下降时的待机进入??该位字段启用??VCC??电源下降时的待机进入。这仅在待机域通过??VDDBKP??电源引脚单独供电且??VCC??轨在待机期间关闭的情况下才受支持。进入电压阈值在??PMC_UVMON0??寄存器中配置。当前配置反映在PMC_SWSTA1.VCCSTBYEN??寄存器位中  */
				__IO uint32_t VDDSTBYEN : 1;  /*!< [3:3] VDD??电源斜坡下降时进入待机状态??该位字段使能??VDD??电源斜坡下降时进入待机状态。这仅在待机域通过??VDDBKP??电源引脚单独供电且??VDD??轨在待机期间关闭的情况下才受支持。进入电压阈值在??PMC_UVMON0??寄存器中配置。当前配置反映在??PMC_SWSTA1.VDDSTBYEN??寄存器位中  */
				__IO uint32_t ESR0DFEN : 1;	  /*!< [4:4] ESR0??数字滤波器使能??该位激活数字尖峰滤波器。如果在正常运?模式下启用数字滤波器(3??个连续值的多数滤波器)，则小于??30ns??的脉冲将被抑制，而长于??100ns??的脉冲将始终导致触发。如果备用时钟在待机模式下被禁用并且滤波器在??70??KHz??待机时钟上运?，则小于??5??us??的脉冲将被抑制，而长于50??us??的脉冲将始终导致触发  */
				__IO uint32_t ESR0EDCON : 2;  /*!< [6:5] ESR0??边沿检测控制:该位字段定义??ESR0??唤醒触发的边沿??  */
				__IO uint32_t ESR1DFEN : 1;	  /*!< [7:7] ESR1??数字滤波器启用:该位激活数字尖峰滤波器。如果在正常运?模式下启用数字滤波器(3??个连续值的多数滤波器)，则小于??30ns??的脉冲将被抑制，而长于??100ns??的脉冲将始终导致触发。如果备用时钟在待机模式下被禁用并且滤波器在??70??KHz??待机时钟上运?，则小于??5??us??的脉冲将被抑制，而长于50??us??的脉冲将始终导致触发  */
				__IO uint32_t ESR1EDCON : 2;  /*!< [9:8] 边沿检测控制?:该位字段定义?ESR1??唤醒触发的边沿  */
				__IO uint32_t PINADFEN : 1;	  /*!< [10:10] PINA??数字滤波器启用??该位激活数字尖峰滤波器。如果在正常运?模式下启用数字滤波器(3??个连续值的多数滤波器)，则小于??40ns??的脉冲将被抑制，而长于??100ns??的脉冲将始终导致触发。如果备用时钟在待机模式下被禁用并且滤波器在??70??KHz??待机时钟上运?，则小于??5??us??的脉冲将被抑制，而长于50??us??的脉冲将始终导致触发  */
				__IO uint32_t PINAEDCON : 2;  /*!< [12:11] PINA??边沿检测控制?:该位字段定义引脚??A??唤醒触发的边沿  */
				__IO uint32_t PINBDFEN : 1;	  /*!< [13:13] PINB?数字滤波器启用??该位激活数字尖峰滤波器。如果在正常运?模式下启用数字滤波器(3??个连续值的多数滤波器)，则小于??40ns??的脉冲将被抑制，而长100ns?的脉冲将始终导致触发。如果备用时钟在待机模式下被禁用并且滤波器在70??KHz??待机时钟上运?，则小于??5??us??的脉冲将被抑制，而长于??50??us??的脉冲将始终导致触发  */
				__IO uint32_t PINBEDCON : 2;  /*!< [15:14] PINB??边沿检测控制:该位字段定义引脚?B?唤醒触发的边沿  */
				__IO uint32_t STBYRAMSEL : 3; /*!< [18:16] 待机模式下的待机??RAM??电源??该位字段配置待机?RAM?块，使其在待机模式期间保持由??VDD11BKP??电源轨供电。当前配置反映在??PMC_SWSTA1.STBYRAM??位域中；  */
				__I uint32_t RESERVE : 1;	  /*!< [19:19] 保留位  */
				__IO uint32_t BLINKFIL : 4;	  /*!< [23:20] 唤醒的消隐滤波器延迟??该位字段仅在待机进入后立即启用标称消隐滤波器延迟时间，之后才识别有效的唤醒事件并做出反应。实际延迟可能与此标称值相差正负30%。当前配置反映在??PMC_SWSTA1.BLNKFIL??位域中；注意:保留其他组合，如果??WUT??用作唤醒源，消隐滤波器应配置为大于3*70kHz??时钟周期的周期.  */
				__IO uint32_t ESR0WKEN : 1;	  /*!< [24:24] ESR0??唤醒使能待机??该位配置通过??ESR0??引脚从待机模式唤醒，当前配置反映在??PMC_SWSTA1.ESR0WKEN??寄存器位中  */
				__IO uint32_t ESR1WKEN : 1;	  /*!< [25:25] ESR1??待机唤醒启用??该位配置通过??ESR1??引脚从待机模式唤醒，当前配置反映在PMC_SWSTA1.ESR1WKEN??寄存器位中  */
				__IO uint32_t PINAWKEN : 1;	  /*!< [26:26] 引脚??A??从待机唤醒启用??该位配置通过??PINA??引脚从待机模式唤醒，当前配置反映在??PMC_SWSTA1.PINAWKEN??寄存器位中  */
				__IO uint32_t PINBWKEN : 1;	  /*!< [27:27] 引脚??B??从待机唤醒启用??该位配置通过??PINB??引脚从待机模式唤醒，当前配置反映在??PMC_SWSTA1.PINBWKEN??寄存器位中  */
				__IO uint32_t PWRWKEN : 1;	  /*!< [28:28] 在VCC电源上升时启用待机唤醒??该位字段使能在消隐滤波时间到期后在VCC??电源上升时唤醒。这仅在待机域通过VDDBKP电源引脚单独供电且VCC轨在待机期间关闭的情况下才受支持。当前配置反映在PMC_SWSTA1.PWRWKEN??寄存器位中  */
				__IO uint32_t PORSTWKEN : 1;  /*!< [30:30] PORST??引脚从待机模式唤醒启用??该位配置通过??PORST??引脚从待机模式唤醒，当前配置反映在??PMC_SWSTA1.PORSTWKEN??寄存器位中  */
				__IO uint32_t WUTWKEN : 1;	  /*!< [31:31] WUT??从待机模式唤醒启用??该位配置通过??WUT??从待机模式唤醒，当前配置反映在??PMC_SWSTA1.WUTWKEN??寄存器位中  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SWCTL0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t RESERVE : 8;	 /*!< [7:0] 保留位  */
				__IO uint32_t CPUIDLSEL : 3; /*!< [10:8] 空闲模式的??CPU??选择??该位字段允许?CPUx??向除自身之外的其他??CPU??发出空闲请求。?CPUx??通过??PMCSRx.REQSLP=01??请求空闲也将触发对所有其他CPU??的空闲请求  */
				__I uint32_t RESERVE : 1;	 /*!< [11:11] 保留位  */
				__IO uint32_t IRADIS : 1;	 /*!< [12:12] 禁用??该位使能SCU空闲请求确认序列到待机进入的所有模块。在通过PWRWKEN??寄存器位触发待机进入的情况下，IRADIS??位无效,该位应在待机进入之前设置以禁用空闲请求确认序列，以?待机请求?会被挂起的重置空闲请求确认序列阻塞  */
				__I uint32_t RESERVE : 11;	 /*!< [23:13] 保留位  */
				__IO uint32_t CPUSEL : 3;	 /*!< [26:24] 睡眠和待机模式的??CPU??选择  */
				__IO uint32_t STBYEVEN : 1;	 /*!< [27:27] 待机进入事件配置启用  */
				__IO uint32_t STBYEV : 3;	 /*!< [30:28] 待机进入事件配置  */
				__I uint32_t RESERVE : 1;	 /*!< [31:31] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SWCTL1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t SACURST : 1; /*!< [25:25] SACU??复位指示标志  */
				__I uint32_t RST : 1;	  /*!< [26:26] 应用程序或系统复位指示标志  */
				__I uint32_t RESERVE : 5; /*!< [31:27] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SWCTL2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t WUTREL : 24; /*!< [23:0] WUT??重载值:计数器从??WUTREL??值开始递减计数。计数器的当前值在?WUTCNT??中指示。在??WUTCNT??下溢时，重新负载??WUTCNT??=??WUTREL??在自动重新负载模式下发生  */
				__I uint32_t RESERVE : 3;  /*!< [26:24] 保留位  */
				__IO uint32_t WUTEN : 1;   /*!< [27:27] WUT使能:该位使能唤醒定时器。一旦启用唤醒定时器，状态位PMC_SWSTA0.WUTEN??就会被置位  */
				__I uint32_t BUSY : 1;	   /*!< [28:28] 锁定状态?????LCK:该位表示寄存器正忙于正在进?的总线访问,当??BUSY??位清零时，寄存器可以?新为新值,寄存器?新时需要与??70kHz??时钟域同步  */
				__IO uint32_t WUTDIV : 1;  /*!< [29:29] WUT??时钟分频器:无论?BUSY??位的状态如何，写入该寄存器位域都可能触发立即?新  */
				__IO uint32_t WUTMODE : 1; /*!< [30:30] WUT??模式选择??该位配置唤醒定时器模式。状态位??PMC_SWSTA0.WUTMODE??分别?新。无论??BUSY??位的状态如何，写入该寄存器位域都可能触发立即?新  */
				__I uint32_t RESERVE : 1;  /*!< [31:31] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SWCTL3_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__O uint32_t BPTRISTREQ : 1; /*!< [0:0] 三态请求位??(TRISTREQ)??的位保护:设置该位使??TRISTREQ??位可以通过写操作?改  */
				__IO uint32_t TRISTREQ : 1;	 /*!< [1:1] 三态启用?:该位决定Pad是作为弱上拉输入还是复位断言/解除断言或待机唤醒转换时的三态,在电源上升或??LVD??复位后，TRISTREQ??=?!??HWCFG6  */
				__IO uint32_t ESR0TRIST : 1; /*!< [2:2] ESR0??三态启用??如果提供??VCC，该位将??ESR0??引脚?为配置为复位输出或待机模式下的三态  */
				__I uint32_t RESERVE : 1;	 /*!< [3:3] 保留位  */
				__IO uint32_t PORSTDF : 1;	 /*!< [4:4] PORST数字滤波器启用:该位字段启用额外的PORST数字滤波器(tPORSTDF参数)以增强对杂散尖峰的抵抗能力  */
				__I uint32_t RESERVE : 1;	 /*!< [5:5] 保留位  */
				__IO uint32_t DCDCSYNCO : 1; /*!< [6:6] DC?DC??同步输出??该位域使同步输出能够使外部??SMPS??稳压器与内部??DCDC11??稳压器同步  */
				__I uint32_t RESERVE : 25;	 /*!< [31:7] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SWCTL5_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t WUTCNT : 24; /*!< [23:0] WUT??计数器值:当前??WUT??计数器值在此寄存器位域中指示。由于同步开销，WUTCNT??值可能与预期计数器值有??3??个额外时钟周期的偏差。??WUT??时钟基于备用??70??kHz??时钟，具有??-??正负?30%??的变化。取决于模式的计数器可以在?中断的情况下运?从??RUN??到??STANDBY??到??RUN??模式转换  */
				__I uint32_t RESERVE : 8; /*!< [31:24] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SWUTCNT_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t RESERVE : 1;	/*!< [0:0] 保留位  */
				__I uint32_t HWCFGEVR : 2;	/*!< [2:1] EVR??硬件配置状态??该位字段指示??EVR??在冷启动期间从??HWCFG[2:1]??锁存的电源配置，随后??EVRx??稳压器将根据这些配置启动。锁存配置STANDBY?RUN??转换期间用于重新选择??EVR??模式  */
				__I uint32_t RESERVE : 1;	/*!< [3:3] 保留位  */
				__I uint32_t HWCFG4 : 1;	/*!< [4:4] 硬件配置引脚??4??状态??该位字段指示冷启动期间HWCFG[4]??的锁存电平  */
				__I uint32_t HWCFG5 : 1;	/*!< [5:5] 硬件配置引脚??5??状态??该位字段指示冷启动期间HWCFG[5]??的锁存电平  */
				__I uint32_t TRIST : 1;		/*!< [6:6] Pad三态/上拉状态??该位指示Pad是配置为带弱上拉的输入还是在复位期间/之后或唤醒之后配置为三态。启动时，从??HWCFG[6]??引脚锁存的值决定默认状态并反映在??TRIST??状态位中。当??PMSWCR5.TRISTREQ??被设置为覆盖来自HWCFG[6]??的初始锁存状态时，该位可能会在稍后?新  */
				__I uint32_t TESTMODE : 1;	/*!< [7:7] TESTMODE引脚状态:该位字段指示冷启动期间??TESTMODE??引脚的锁存电平  */
				__I uint32_t ESR0TRIST : 1; /*!< [8:8] 待机期间的??ESR0??引脚状态??该位指示在待机模式期间??ESR0??引脚是否配置为复位输出或三态,以及是否提供VCC时的转换。该位在PMSWCR5??时?新。ESR0TRIST??已设置  */
				__I uint32_t RESERVE : 2;	/*!< [10:9] 保留位  */
				__I uint32_t PORSTDF : 1;	/*!< [11:11] PORST??数字滤波器状态??该位字段指示附加??PORST??数字滤波器是否已激活。当PMSWCR5.PORSTDF??被置位时，该位被?新  */
				__I uint32_t RESERVE : 9;	/*!< [23:15] 保留位  */
				__I uint32_t WUTEN : 1;		/*!< [24:24] WUT??启用状态:该位指示?WUT??是否启用。该位在??PMSWCR3.WUTEN??位?新时?新  */
				__I uint32_t WUTRUN : 1;	/*!< [25:25] WUT运?状态:该位指示??WUT??当前是否正在运?。由于70??KHz??(?fSB?)??WUT??时钟同步，启用后设置标志可能需要长达??55??us  */
				__I uint32_t WUTMODE : 1;	/*!< [26:26] WUT??模式状态??该位指示当前的??WUT??模式。该位在??PMSWCR3.WUTMODE??位?新时?新  */
				__I uint32_t RESERVE : 1;	/*!< [27:27] 保留位  */
				__I uint32_t ESR0INT : 1;	/*!< [28:28] ESR0??中断标志:如果在运?模式期间??ESR0??引脚事件触发中断，则设置此标志。该位应在中断服务后通过PMC_SWCLR.ESR0INTCLR??位明确清除  */
				__I uint32_t ESR1INT : 1;	/*!< [29:29] ESR1??中断标志??如果在运?模式期间??ESR1??引脚事件触发中断，则设置此标志。该位应在中断服务后通过PMC_SWCLR.ESR1INTCLR??位明确清除  */
				__I uint32_t PINAINT : 1;	/*!< [30:30] 引脚??A??中断标志:如果在运?模式期间由??PINA??引脚事件触发中断，则设置此标志。该位应在中断服务后通过?PMC_SWCLR.PINAINTCLR??位明确清除  */
				__I uint32_t PINBINT : 1;	/*!< [31:31] 引脚??B??中断标志:如果在运?模式期间由??PINB??引脚事件触发中断，则设置此标志。该位应在中断服务后通过?PMC_SWCLR.PINBINTCLR??位明确清除  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SWSTA0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t ESR0WKP : 1;	 /*!< [0:0] ESR0??唤醒标志:如果在待机期间由??ESR0??引脚触发唤醒，则设置此标志。该位应在唤醒后通过?PMC_SWCLR.ESR0WKPCLR??位明确清除，然后再进入下一个STANDBY  */
				__I uint32_t ESR1WKP : 1;	 /*!< [1:1] ESR1??唤醒标志:如果唤醒在待机期间由??ESR1??引脚触发，则设置此标志。该位应在唤醒后通过PMC_SWCLR.ESR1WKPCLR??位明确清除，然后再进入下一个STANDBY  */
				__I uint32_t PINAWKP : 1;	 /*!< [2:2] 引脚唤醒标志:如果唤醒在待机期间由??PINA??引脚触发，则设置此标志。该位应在唤醒后在下一次进入待机之前通过??PMC_SWCLR.PINAWKPCLR??位明确清除  */
				__I uint32_t PINBWKP : 1;	 /*!< [3:3] 引脚??B??唤醒标志:如果唤醒在待机期间由??PINB??引脚触发，则设置此标志。该位应在唤醒后通过PMC_SWCLR.PINBWKPCLR??位明确清除，然后再进入下一个STANDBY  */
				__I uint32_t PWRWKP : 1;	 /*!< [4:4] VCC??电源上升时的唤醒事件?:如果唤醒是在待机期间由??VCC??上升引脚触发的，则设置此标志。该位应在唤醒后通过??PMC_SWCLR.PWRWKPCLR??位明确清除，然后再进入下一个??STANDBY  */
				__I uint32_t PORSTWKP : 1;	 /*!< [6:6] PORST??唤醒标志:如果唤醒在待机期间由??PORST??引脚触发，则设置此标志。该位应在唤醒后通过?PMC_SWCLR.PORSTWKPCLR??位明确清除，然后再进入下一个STANDBY  */
				__I uint32_t WUTWKP : 1;	 /*!< [7:7] WUT??唤醒标志??如果唤醒在待机期间由唤醒定时器触发，则设置此标志。该位应在唤醒后在下一次进入待机之前通过PMC_SWCLR.WUTWKPCLR??位明确清除  */
				__I uint32_t ESR0OVRUN : 1;	 /*!< [8:8] ESR0??溢出状态标志??该标志表示在待机期间??ESR0WKP??标志已设置时发生了连续的??ESR0??唤醒事件。该位应在唤醒后通过PMC_SWCLR.ESR0OVRUNCLR??位明确清除，然后再进入下一个??STANDBY  */
				__I uint32_t ESR1OVRUN : 1;	 /*!< [9:9] ESR1??溢出状态标志??该标志表示在待机期间??ESR1WKP??标志已设置时发生了连续的??ESR1??唤醒事件。该位应在唤醒后通过?PMC_SWCLR.ESR1OVRUNCLR??位明确清除，然后再进入下一个??STANDBY  */
				__I uint32_t PINAOVRUN : 1;	 /*!< [10:10] Pin??A??Overrun状态标志?:该标志表示在STANDBY期间已设置PINAWKP标志时发生了连续的PINA唤醒事件。该位应在唤醒后通PMC_SWCLR.PINAOVRUNCLR??位明确清除，然后再进入下一个??STANDBY  */
				__I uint32_t PINBOVRUN : 1;	 /*!< [11:11] Pin??B??溢出状态标志:该标志表示在STANDBY??期间已设置??PINBWKP??标志时发生了连续的PINB唤醒事件。该位应在唤醒后通PMC_SWCLR.PINBOVRUNCLR??位明确清除，然后再进入下一个??STANDBY  */
				__I uint32_t VDDSTBYEN : 1;	 /*!< [12:12] VDD??电源斜坡下降时的待机进入启用状态?????VDDSTBYWKEN??该位表示待机进入可能在??VDD??电源欠压事件??(VDDUV)??上触发。仅当待机域由??VDDBKP??待机电源引脚单独供电时才支持此功能。该位在??PMSWCR0.VDDSTBYWKEN??位?新时?新  */
				__I uint32_t PORSTOVRUN : 1; /*!< [14:14] PORST溢出状态标志:该标志表示在STANDBY期间PORSTWKP标志已设置时发生了连续的??PORST??唤醒事件。该位应在唤醒后通过?PMC_SWCLR.PORSTOVRUNCLR??位明确清除，然后再进入下一个??STANDBY  */
				__I uint32_t WUTOVRUN : 1;	 /*!< [15:15] WUT溢出状态标志:该标志表示在待机期间WUTWKP标志已设置时发生了连续的WUT唤醒事件。该位应在唤醒后通过??PMC_SWCLR.WUTOVRUNCLR??位明确清除，然后再进入下一个??STANDBY。WUTREL在待机模式下需要大于??10??才能锁存连续的??WUT??下溢事件并?新??WUTOVRRUN??寄存器位域  */
				__I uint32_t STBYRAM : 3;	 /*!< [18:16] 备用??RAM??供应状态??该位字段指示备用??RAM??是否在待机模式期间提供并推断唤醒事件后的状态。该位在??PMSWCR0.STBYRAMSEL??置位时?新,注意:保留所有其他位组合。如果??VDD11BKP??备用电源故障或??VDDBKP??电源故障导致??LVD??重置(也在??RSTSTAT.STBYR??中指示)，STBYRAM状态位将重置为000b，以指示备用??RAM??内容可能已损坏  */
				__I uint32_t VCCSTBYEN : 1;	 /*!< [19:19] VCC??电源斜降时的待机进入启用状态-VCCSTBYWKEN:该位表示待机进入可能会在??VCC??电源欠压事件??(SWDUV)??上触发。仅当待机域由??VDDBKP??待机电源引脚单独供电时才支持此功能。该位在??PMSWCR0.VCCSTBYWKEN??位?新时?新  */
				__I uint32_t BLNKFIL : 4;	 /*!< [23:20] VCC??电源唤醒的消隐滤波器延迟??该位字段指示消隐滤波器配置。该位字段使用PMSWCR0.BLNKFIL??位字段中配置的值?新  */
				__I uint32_t ESR0WKEN : 1;	 /*!< [24:24] ESR0??唤醒启用状态:该位表示启用?ESR0??以触发从待机模式唤醒.该位在PMSWCR0.ESR0WKEN??位?新时?新  */
				__I uint32_t ESR1WKEN : 1;	 /*!< [25:25] ESR1??唤醒启用状态:该位表示启用?ESR1??以触发从待机模式唤醒.该位在PMSWCR0.ESR1WKEN??位?新时?新  */
				__I uint32_t PINAWKEN : 1;	 /*!< [26:26] Pin??A??唤醒启用状态??该位表示??PINA已启用以触发从待机状态唤醒,该位在PMSWCR0.PINAWKEN??位?新时?新  */
				__I uint32_t PINBWKEN : 1;	 /*!< [27:27] Pin??B??唤醒启用状态??该位表示??PINB??已启用以触发从待机模式唤醒,该位在PMSWCR0.PINBWKEN??位?新时?新  */
				__I uint32_t PWRWKEN : 1;	 /*!< [28:28] VCC??电源上升时的待机唤醒启用状态??该位表示??VCC??检测器已启用，可在消隐滤波器时间到期后的??VCC??电源上升期间触发待机唤醒。仅当待机域由VDDBKP??待机电源引脚单独供电时才支持此功能。该位PMSWCR0.PWRWKEN??位?新时?新  */
				__I uint32_t PORSTWKEN : 1;	 /*!< [30:30] PORST??引脚从待机唤醒启用状态??该位表示在待机模式下启用通过??PORST??引脚唤醒。该位在??PMSWCR0.??PORSTWKEN??位已?新  */
				__I uint32_t WUTWKEN : 1;	 /*!< [31:31] WUT??唤醒启用状态:该位指示??WUT??已启用以触发从待机模式唤醒,该位在PMSWCR0.WUTWKEN??位?新时?新  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SWSTA1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__O uint32_t ESR0WKPCLR : 1;	/*!< [0:0] ESR0??唤醒指示标志清除  */
				__O uint32_t ESR1WKPCLR : 1;	/*!< [1:1] ESR1??唤醒指示标志清除  */
				__O uint32_t PINAWKPCLR : 1;	/*!< [2:2] PINA??唤醒指示标志清除  */
				__O uint32_t PINBWKPCLR : 1;	/*!< [3:3] PINB??唤醒指示标志清除  */
				__O uint32_t PWRWKPCLR : 1;		/*!< [4:4] PWRWKP??唤醒指示标志清除  */
				__O uint32_t PORSTWKPCLR : 1;	/*!< [6:6] PORST??唤醒指示标志清除  */
				__O uint32_t WUTWKPCLR : 1;		/*!< [7:7] WUT??唤醒指示标志清除  */
				__O uint32_t ESR0OVRUNCLR : 1;	/*!< [8:8] ESR0??溢出状态指示标志清除  */
				__O uint32_t ESR1OVRUNCLR : 1;	/*!< [9:9] ESR1??溢出状态指示标志清除  */
				__O uint32_t PINAOVRUNCLR : 1;	/*!< [10:10] PINA??溢出状态指示标志清除  */
				__O uint32_t PINBOVRUNCLR : 1;	/*!< [11:11] PINB??溢出状态指示标志清除  */
				__I uint32_t RESERVE : 2;		/*!< [13:12] 保留位  */
				__O uint32_t PORSTOVRUNCLR : 1; /*!< [14:14] PORST??溢出状态指示标志清除  */
				__O uint32_t WUTOVRUNCLR : 1;	/*!< [15:15] WUT??溢出状态指示标志清除  */
				__O uint32_t SCRSTCLR : 1;		/*!< [16:16] 用控制器??SCRST??指示标志清除  */
				__I uint32_t RESERVE : 11;		/*!< [27:17] 保留位  */
				__O uint32_t ESR0INTCLR : 1;	/*!< [28:28] ESR0??中断指示标志清除  */
				__O uint32_t ESR1INTCLR : 1;	/*!< [29:29] ESR1??中断指示标志清除  */
				__O uint32_t PINAINTCLR : 1;	/*!< [30:30] PINA??中断指示标志清除  */
				__O uint32_t PINBINTCLR : 1;	/*!< [31:31] PINB??中断指示标志清除  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_SWCLR_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t OTGB0 : 4;   /*!< [3:0] OTGB0??的触发设置  */
				__I uint32_t RESERVE : 4;  /*!< [7:4] 保留位  */
				__IO uint32_t OTGB1 : 4;   /*!< [11:8] OTGB1??触发设置  */
				__I uint32_t RESERVE : 16; /*!< [31:16] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_OTSS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t B0LAM : 4;  /*!< [3:0] OTGB0??TS16_ADCMON??低字节  */
				__I uint32_t RESERVE : 4; /*!< [7:4] 保留位  */
				__IO uint32_t B0HAM : 4;  /*!< [11:8] OTGB0??TS16_ADCMON??高字节  */
				__I uint32_t RESERVE : 4; /*!< [15:12] 保留位  */
				__IO uint32_t B1LAM : 4;  /*!< [19:16] OTGB1??TS16_ADCMON??低字节  */
				__I uint32_t RESERVE : 4; /*!< [23:20] 保留位  */
				__IO uint32_t B1HAM : 4;  /*!< [27:24] OTGB1??TS16_ADCMON??高字节  */
				__I uint32_t RESERVE : 4; /*!< [31:28] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_OTSC0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t B0EC : 4;	  /*!< [3:0] OTGB0??TS16_DCDC11ON  */
				__I uint32_t RESERVE : 4; /*!< [7:4] 保留位  */
				__IO uint32_t B1EC : 4;	  /*!< [11:8] OTGB0??TS16_DCDC11ON  */
				__I uint32_t RESERVE : 4; /*!< [15:12] 保留位  */
				__IO uint32_t DMONAD : 8; /*!< [23:16] OTGB0??TS16_DCDC11ON??DMONAD??DMONAD:编码表中记录的多?复用器信号选择  */
				__IO uint32_t SMCDBG : 8; /*!< [31:24] OTGB0??TS16_DCDC11ON??SMCDBG?:为将来的扩展保留  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_OTSC1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t CPU0 : 1;	   /*!< [0:0] CPU0??状态:该位域反映了??CPU0??的当前状态  */
				__I uint32_t CPU1 : 1;	   /*!< [1:1] CPU1?状态:该位域反映了??CPU1??的当前状态  */
				__I uint32_t RESERVE : 14; /*!< [15:2] 保留位  */
				__I uint32_t CPU0LS : 1;   /*!< [16:16] 该位字段反映了??CPU0??锁步检查器内核的当前状态。锁步的激活在UCB??BMI??配置中配置并确定默认复位值。默认复位值??0??适用于UCB??BMI??配置中禁用??CPU0LS??的情况  */
				__I uint32_t CPU1LS : 1;   /*!< [17:17] 该位字段反映了??CPU1??锁步检查器内核的当前状态。锁步的激活在UCB??BMI??配置中配置并确定默认复位值。默认复位值??0??适用于??UCB??BMI??配置中禁用??CPU0LS??的情况  */
				__I uint32_t RESERVE : 14; /*!< [31:18] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_CPUSTA_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t REQSLP : 2;  /*!< [1:0] 空闲模式和睡眠模式请求??在空闲模式或睡眠模式下，这些位被清除以响应CPU??的中断,或者当相应CPU看门狗定时器寄存器的位15(位?WDTCPUxSR.TIM[15])从0??变为1.??在待机模式下，这些位在唤醒时被清除。??REQSLP??可能仅在??CPU??或安全ENDINIT??位设置为??0??时写入。CPU??ENDINIT??位必须在写入REQSLP??后重新设置，以?模式转换发生。在??Safety??ENDINIT??的情况下，模式转换将立即发出，而?会等到??Safety??ENDINIT??再次设置回??1  */
				__I uint32_t RESERVE : 6;  /*!< [7:2] 保留位  */
				__I uint32_t PMST : 3;	   /*!< [10:8] 电源管?状态?:该位字段反映了??CPU??的当前状态  */
				__I uint32_t RESERVE : 21; /*!< [31:11] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_CPU0CS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t REQSLP : 2;  /*!< [1:0] 空闲模式和睡眠模式请求??在空闲模式或睡眠模式下，这些位被清除以响应CPU??的中断，或者当相应CPU看门狗定时器寄存器的位15位WDTCPUxSR.TIM[15])从?0??变为1.??在待机模式下，这些位在唤醒时被清除。REQSLP??可能仅在??CPU??或安全ENDINIT??位设置为??0??时写入。CPU??ENDINIT??位必须在写入??REQSLP??后重新设置，以?模式转换发生。在??Safety??ENDINIT??的情况下，模式转换将立即发出，而?会等到??Safety??ENDINIT??再次设置回??1  */
				__I uint32_t RESERVE : 6;  /*!< [7:2] 保留位  */
				__I uint32_t PMST : 3;	   /*!< [10:8] 电源管?状态?:该位字段反映了??CPU??的当前状态  */
				__I uint32_t RESERVE : 21; /*!< [31:11] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_CPU1CS_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t RESULT : 12;  /*!< [11:0] DTS??测?的结果?:该位字段显示??DTS??测?的结果。给出的值与管芯温度直接相关，可以使用以下公式进?评估T(°C)=[RESULT/Gnom]-273.15T(°K)=[RESULT]/G_nomRESULT=G_nom*{T(°C)+273.15}=G_nom*T(°K)G_nom=7.505  */
				__I uint32_t RESERVE : 20; /*!< [31:12] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} DTSP_RES_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t LOWER : 12; /*!< [11:0] 下限?:该位字段定义??DTS??温度检查的下限。??DTS??测?结果与该值进?比较，如果测?结果小于或等于配置的??LOWER?位域值；标志??LLU??被设置  */
				__I uint32_t RESERVE : 4; /*!< [15:12] 保留位  */
				__IO uint32_t UPPER : 12; /*!< [27:16] 上限?:该位字段定义??DTS?温度检查的上限。??DTS??测?结果与该值进?比较，如果测?结果大于或等于配置的??UPPER??位域值；设置标志??UOF  */
				__I uint32_t RESERVE : 4; /*!< [31:28] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} DTSP_RANG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t RESERVE : 15; /*!< [14:0] 保留位  */
				__IO uint32_t LLU : 1;	   /*!< [15:15] 下溢下限:设置此位时，会生成??HSM??温度下溢触发器,设置此位时，会生成相关的??SACU??DTS??警报触发器。该位必须写入零才能清除它。写一个没有效果。当??DTS??测?完成并且结果低于下限(即??DTSLIM.LOWER)时，该位被设置  */
				__I uint32_t RESERVE : 14; /*!< [29:16] 保留位  */
				__IO uint32_t SLCK : 1;	   /*!< [30:30] HSM??安全锁??如果设置了该位，则无法再写入该寄存器中的所有其他位。当SLCK??置位时对其他位的写请求将触发??SLCK??访问错误警报。该位?能由软件清除。??SLCK??位只能通过来自??HSM??主设备??(TAG??=??000011B?)??的访问来设置。忽略任何其他主机或软件执?的设置操作，并且该位保持清零状态  */
				__IO uint32_t UOF : 1;	   /*!< [31:31] 溢出上限:设置此位时，会生成?HSM??温度溢出触发器。设置此位时，会生成相关的??SACU??DTS??警报触发器,该位必须写入零才能清除它。写一个没有效果,当DTS??测?完成并且结果超过上限(即??DTSLIM.UPPER)时，该位被设置  */
			} bits;
			__IO uint32_t reg;
		};
	} DTSP_STA_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__I uint32_t RESULT : 12;  /*!< [11:0] DTSC??测?的结果??该位字段显示??DTSC??测?的结果。给出的值与管芯温度直接相关，可以使用以下公式进?评估T(°C)=[RESULT/Gnom]-273.15T(°K)=[RESULT]/G_nomRESULT=G_nom*{T(°C)+273.15}=G_nom*T(°K)G_nom=7.505  */
				__I uint32_t RESERVE : 20; /*!< [31:12] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} DTSC_RES_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t LOWER : 12; /*!< [11:0] DTSC??下限??该位字段定义:DTSC??温度检查的下限。??DTSC??测?结果与该值进?比较，如果测?结果小于或等于配置的??LOWER??位域值；标志??LLU??被设置  */
				__I uint32_t RESERVE : 4; /*!< [15:12] 保留位  */
				__IO uint32_t UPPER : 12; /*!< [27:16] DTSC??上限??该位字段定义??DTSC??温度检查的上限。??DTSC??测?结果与该值进?比较，如果测?结果大于或等于配置的??UPPER??位域值；设置标志??UOF  */
				__I uint32_t RESERVE : 4; /*!< [31:28] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} DTSC_RANG_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t INTEN : 1;   /*!< [0:0] DTSC??中断启用??该位字段启用核心芯片温度传感器??(DTSC)??中断,该位域在应用程序重置时重置  */
				__I uint32_t RESERVE : 1;  /*!< [1:1] 保留位  */
				__IO uint32_t EN : 1;	   /*!< [2:2] 启用??DTSC:此位字段启用核心芯片温度传感器??(DTSC)。位域在应用程序重置时重置  */
				__I uint32_t RESERVE : 29; /*!< [31:3] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} DTSC_CTL_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t LLU : 1;	   /*!< [0:0] DTSC??下限下溢??当设置此位时，将生成相关的??SACU??DTSC??警报触发器。该位必须写入零才能清除它。写一个没有效果。当??DTSC??测?完成并且结果低于下限(即??DTSCLIM.LOWER)时，该位被设置  */
				__IO uint32_t DTSCIF : 1;  /*!< [1:1] 生成SACU??DTSC??中断时，该位被设置。该位通过写入零来清除。写一个没有效果  */
				__IO uint32_t UOF : 1;	   /*!< [2:2] DTSC??上限溢出??当该位置位时，产生相关的??SACU??DTSC??告警触发。该位必须写入零才能清除它。写一个没有效果。当??DTSC??测?完成并且结果超过上限(即DTSCLIM.UPPER)时，该位被设置  */
				__I uint32_t BGPOK : 1;	   /*!< [3:3] DTSC??Bandgap??OK:此位字段指示核心芯片温度传感器??(DTSC)??的带隙参考可用且正常  */
				__I uint32_t RESERVE : 28; /*!< [31:4] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} DTSC_STA_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t LJTEN : 1;	/*!< [0:0] 负载跳转定时器使能:该位字段启用负载跳转定时器的使用  */
				__IO uint32_t LJTOVEN : 1;	/*!< [1:1] 负载跳转定时器溢出启用:该位字段使能在定时器溢出或超时时?新??LJTOV??状态位  */
				__IO uint32_t LJTOVIEN : 1; /*!< [2:2] 负载跳变计时器上溢中断使能:该位域允许在定时器溢出或超时时激活中断  */
				__IO uint32_t LJTSTRT : 1;	/*!< [3:3] 负载跳变定时器启动:该位字段启动负载跳转定时器。这是为了测试目的,LJTSTRT??在写入时保持设置，如果启用??LJTOVEN??位，则在设置??LJTOV??位时清除  */
				__IO uint32_t LJTSTP : 1;	/*!< [4:4] 负载跳变定时器停止:该位字段停止负载跳转定时器。这是为了测试目的。LJTSTP??在写入时保持设置，并由软件明确清除。当??LJTSTP??清零且??LJTSTRT??置位时，LJTSTP??将计数器停止在当前值，定时器从该值重新启动  */
				__O uint32_t LJTCLR : 1;	/*!< [5:5] 负载跳变定时器清零:该位字段清除负载跳转定时器计数。这是为了测试目的。如果??LJTEN??位置位，该位复位??LJT??并清除??LJTRUN  */
				__I uint32_t RESERVE : 6;	/*!< [11:6] 保留位  */
				__IO uint32_t SDSTEP : 4;	/*!< [15:12] 压降阶跃??(vdroop_step_i):该位字段定义负载跳变到??DCDC11??设定点值时压降补偿的电压偏移。该请求是通过PMC_TCS3.VDROOPREQ??在预期负载跳跃时发出的，电压偏移等于??SDSTEP*5??mV。如果??VDROOPREQ??=??01b，则下降阶跃是正偏移；如果?VDROOPREQ?=?10b，则下降阶跃是负偏移；如果VDROOPREQ=00b，则不应用偏移  */
				__IO uint32_t VDTEN : 1;	/*!< [16:16] 电压下降定时器使能:该位域允许使用??Voltage??Droop??定时器  */
				__IO uint32_t VDTOVEN : 1;	/*!< [17:17] 电压下降定时器溢出使能??该位字段使能在定时器溢出或超时时?新??VDTOV??状态位  */
				__IO uint32_t VDTOVIEN : 1; /*!< [18:18] 电压下降定时器溢出中断使能:该位域允许在定时器溢出或超时时激活中断  */
				__IO uint32_t VDTSTRT : 1;	/*!< [19:19] 电压下降定时器启动??该位域启动电压下降定时器。这是为了测试目的VDTSTRT??在写入时保持设置，如果启用??VDTOVEN??位，则在设置??VDTOV??位时清除  */
				__IO uint32_t VDTSTP : 1;	/*!< [20:20] 电压下降定时器停止??该位字段停止电压下降定时器。??SCU??通过信号sd_droop_cntr_i??=??00??取消下降请求。这是为了测试目的。?VDTSTP??在写入时保持设置，并由软件明确清除,当??VDTSTP??清零且??VDTSTRT??置位时，VDTSTP??在当前值停止计数器，定时器从该值重新启动  */
				__O uint32_t VDTCLR : 1;	/*!< [21:21] 电压下降定时器清除??该位字段清除电压下降定时器计数。这是为了测试目的。如果设置了??VDTEN??位，该位会重置??VDT??并清除??VDTRUN  */
				__I uint32_t RESERVE : 7;	/*!< [28:22] 保留位  */
				__IO uint32_t LPSLPEN : 1;	/*!< [29:29] 休眠请求??PMS??上的??DCDC11??低功耗模式激活:该位字段启用休眠请求上的??LPM??DCDC11??模式激活。??PMSLE:保留，无功能(SC?DCDC??DCDC11??无??LPM)  */
				__I uint32_t RESERVE : 2;	/*!< [31:30] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_TCS0_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t LJTCV : 16; /*!< [15:0] 负载跳转定时器比较设置点值??该位字段定义负载跳转定时器的比较设置点值。比较事件将导致??LJTOV??位被置位并引发??LJT??中断。??LJTRUN??状态位、LDJMPREQ??位和??LJTCNT??值在发生比较事件时复位为??0,X??us??是比较值。LSB=1us.Totalrange=65.5ms  */
				__IO uint32_t VDTCV : 10; /*!< [25:16] 电压下降定时器比较设定点值??该位字段定义电压下降定时器的比较设定点值.比较事件将导致设置VDTOV位并引发?VDT??中断。VDTRUN?状态位、VDROOPREQ??位和??VDTCNT??值在发生比较事件时重置为??0X??us??是比较值,LSB=1us.Totalrange=1023us  */
				__I uint32_t RESERVE : 6; /*!< [31:26] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_TCS1_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t LDJMPREQ : 2; /*!< [1:0] 负载跳转请求:该位请求负载跳转，从而导致负载跳转定时器启动，如果LJTEN=1，则??LJTRUN??位被设置。如果??LJTRUN??位已处于设置状态且??LJT??当前正在运?，则?会执?该请求。如果??VDTRUN??位已处于设置状态且??VDT??当前正在运?，则?会执?该请求。如果(LJTOV??位已设置且??LJTOVEN??位已启用)，也?会执?该请求。如果(VDTOV??位已设置且??VDTOVEN??位已启用)，也?会执?该请求。??LDJMPREQ??位在比较溢出时被清除  */
				__I uint32_t RESERVE : 2;	/*!< [3:2] 保留位  */
				__I uint32_t LJTRUN : 2;	/*!< [5:4] 负载跳转定时器运?状态??该状态位表示负载跳转定时器当前正在运?并且当前正在发生负载跳转。??LJTRUN??位在比较溢出时被清除  */
				__I uint32_t RESERVE : 2;	/*!< [7:6] 保留位  */
				__I uint32_t LJTOV : 1;		/*!< [8:8] 负载跳转定时器溢出状态??该状态位表示负载跳转定时器比较匹配已经发生。如果启用??LJTOVEN??位，则??LJTOV??只能通过??LJTOVCLR??位明确清除。如果LJTOVEN??位被禁用，则??LJTOV??在接受负载跳转请求时被清除(仅当??LJT??和VDT??当前未运?并且没有正在处?的活动负载跳转请求时才会接受新的负载跳转请求)。如果启用??LJTOVIEN，则设置??LJTOV??将导致中断  */
				__I uint32_t RESERVE : 3;	/*!< [11:9] 保留位  */
				__O uint32_t LJTOVCLR : 1;	/*!< [12:12] 负载跳转定时器溢出状态清除??该位清除LJTOV状态位，如果启用LJTOVEN位，则将??VDROOPREQ??和??LDJMPREQ??设置为??0。该位始终读为??0  */
				__I uint32_t RESERVE : 3;	/*!< [15:13] 保留位  */
				__I uint32_t LJTCNT : 16;	/*!< [31:16] 负载跳变定时器值:该位字段反映了当前的??Load??Jump??定时器值。??LJTCNT??值在定时器溢出时被清除，并且在接受加载跳转请求时,?X??us??是比较值。LSB??=??1??毫秒。总范围??=??65.5??毫秒  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_TCS2_T;

	typedef volatile struct
	{
		union
		{
			struct
			{
				__IO uint32_t VDROOPREQ : 2; /*!< [1:0] 电压下降请求:如果??VDTEN=1，该位请求电压下降，从而导致电压下降定时器启动和设置??VDTRUN??位。如果??VDTRUN??位已处于设置状态且??VDT??当前正在运?，则?会执?该请求。如果(VDTOV??位已设置且??VDTOVEN??位已启用)，也?会执?该请求。如果??sd_droop_cntr_i??=??01，则下垂步骤是正偏移；如果??sd_droop_cntr_i??=??10，则下垂步骤是负偏移；如果??sd_droop_cntr_i??=??00，则?应用任何偏移并立即应用  */
				__I uint32_t RESERVE : 2;	 /*!< [3:2] 保留位  */
				__I uint32_t VDTRUN : 2;	 /*!< [5:4] 电压下降定时器运?状态??该状态位指示电压下降定时器当前正在运?并且当前正在发生电压下降。?VDTRUN??位在比较溢出时被清除  */
				__I uint32_t RESERVE : 2;	 /*!< [7:6] 保留位  */
				__I uint32_t VDTOV : 1;		 /*!< [8:8] 电压下降定时器溢出状态??该状态位表示电压下降定时器比较匹配已经发生。如果启用VDTOVEN位，则只能通过VDTOVCLR位显式清除??VDTOV。如果??VDTOVEN??位被禁用，VDTOV??会在接受电压下降请求时被清除(只有当??LJT??和??VDT??当前都没有运?并且没有正在处?的活动电压下降请求时才会采取新的电压下降请求)。如果启用??VDTOVIEN，设置??VDTOV??将导致中断。如果??SDVOK??在??VDT??比较匹配之前由??DCDC11??设置，则?会设置??VDTOV??位  */
				__I uint32_t RESERVE : 3;	 /*!< [11:9] 保留位  */
				__O uint32_t VDTOVCLR : 1;	 /*!< [12:12] 保留位  */
				__I uint32_t RESERVE : 3;	 /*!< [15:13] 保留位  */
				__I uint32_t VDTCNT : 10;	 /*!< [25:16] 电压下降定时器值??该位字段反映当前的电压下降定时器值。??VDTCNT??值在定时器溢出和接受电压下降请求时被清除,X??us??是比较值,LSB=1us.Totalrange=65.5ms  */
				__I uint32_t RESERVE : 6;	 /*!< [31:26] 保留位  */
			} bits;
			__IO uint32_t reg;
		};
	} PMC_TCS3_T;

	typedef volatile struct
	{
		/* address: 0xF000B800 */
		PMC_INFO_T PMC_INFO;

		/* address: 0xF000B804 */
		PMC_ACES0_T PMC_ACES0;

		/* address: 0xF000B808 */
		PMC_ACES1_T PMC_ACES1;

		/* address: 0xF000B80C */
		PMC_STA_T PMC_STA;

		/* address: 0xF000B810 */
		PMC_PMONSTA_T PMC_PMONSTA;

		/* address: 0xF000B814 */
		PMC_RSTCTL_T PMC_RSTCTL;

		/* address: 0xF000B818 */
		PMC_RSTSTA_T PMC_RSTSTA;

		/* address: 0xF000B81C */
		PMC_CALCTL_T PMC_CALCTL;

		/* address: 0xF000B820 */
		PMC_CALSTA_T PMC_CALSTA;

		/* address: 0xF000B824 */
		PMC_SMONSTA1_T PMC_SMONSTA1;

		/* address: 0xF000B828 */
		PMC_SMONSTAT2_T PMC_SMONSTAT2;

		/* address: 0xF000B82C */
		PMC_SMONCTL_T PMC_SMONCTL;

		/* address: 0xF000B830 */
		PMC_SMONFIL_T PMC_SMONFIL;

		/* address: 0xF000B834 */
		PMC_IE_T PMC_IE;

		/* address: 0xF000B838 */
		PMC_UVMON0_T PMC_UVMON0;

		/* address: 0xF000B83C */
		PMC_OVMON0_T PMC_OVMON0;

		/* address: 0xF000B840 */
		PMC_UVMON1_T PMC_UVMON1;

		/* address: 0xF000B844 */
		PMC_OVMON1_T PMC_OVMON1;

		/* address: 0xF000B848 */
		HSM_UVMON_T HSM_UVMON;

		/* address: 0xF000B84C */
		HSM_OVMON_T HSM_OVMON;

		/* address: 0xF000B850 */
		PMC_LDO33CTL_T PMC_LDO33CTL;

		/* address: 0xF000B854 */
		PMC_OSCCTL_T PMC_OSCCTL;

		/* address: 0xF000B858 */
		PMC_SDSTA0_T PMC_SDSTA0;

		/* address: 0xF000B85C */
		PMC_SDCTL0_T PMC_SDCTL0;

		/* address: 0xF000B860 */
		PMC_SDCTL1_T PMC_SDCTL1;

		/* address: 0xF000B864 */
		PMC_SDCTL2_T PMC_SDCTL2;

		/* address: 0xF000B868 */
		PMC_SDCTL3_T PMC_SDCTL3;

		/* address: 0xF000B86C */
		PMC_SDCTL4_T PMC_SDCTL4;

		/* address: 0xF000B870 */
		PMC_SDCTL5_T PMC_SDCTL5;

		/* address: 0xF000B874 */
		PMC_SDCTL6_T PMC_SDCTL6;

		/* address: 0xF000B878 */
		PMC_SDCTL7_T PMC_SDCTL7;

		/* address: 0xF000B87C */
		PMC_SDCTL8_T PMC_SDCTL8;

		/* address: 0xF000B880 */
		PMC_SDCTL9_T PMC_SDCTL9;

		/* address: 0xF000B884 */
		PMC_SDCTL10_T PMC_SDCTL10;

		/* address: 0xF000B888 */
		PMC_SDCTL11_T PMC_SDCTL11;

		/* address: 0xF000B88C */
		PMC_SDFCT0_T PMC_SDFCT0;

		/* address: 0xF000B890 */
		PMC_SDFCT1_T PMC_SDFCT1;

		/* address: 0xF000B894 */
		PMC_SDFCT2_T PMC_SDFCT2;

		/* address: 0xF000B898 */
		PMC_SDFCT3_T PMC_SDFCT3;

		/* address: 0xF000B89C */
		PMC_SDFCT4_T PMC_SDFCT4;

		/* address: 0xF000B8A0 */
		PMC_SDFCT5_T PMC_SDFCT5;

		/* address: 0xF000B8A4 */
		PMC_SDFCT6_T PMC_SDFCT6;

		/* address: 0xF000B8A8 */
		PMC_SDFCT7_T PMC_SDFCT7;

		/* address: 0xF000B8AC */
		PMC_SDFCT8_T PMC_SDFCT8;

		/* address: 0xF000B8B0 */
		PMC_SDFCT9_T PMC_SDFCT9;

		/* address: 0xF000B8B4 */
		PMC_SWCTL0_T PMC_SWCTL0;

		/* address: 0xF000B8B8 */
		PMC_SWCTL1_T PMC_SWCTL1;

		/* address: 0xF000B8BC */
		PMC_SWCTL2_T PMC_SWCTL2;

		/* address: 0xF000B8C0 */
		PMC_SWCTL3_T PMC_SWCTL3;

		/* address: 0xF000B8C4 */
		PMC_SWCTL5_T PMC_SWCTL5;

		/* address: 0xF000B8C8 */
		PMC_SWUTCNT_T PMC_SWUTCNT;

		/* address: 0xF000B8CC */
		PMC_SWSTA0_T PMC_SWSTA0;

		/* address: 0xF000B8D0 */
		PMC_SWSTA1_T PMC_SWSTA1;

		/* address: 0xF000B8D4 */
		PMC_SWCLR_T PMC_SWCLR;

		/* address: 0xF000B8D8 */
		PMC_OTSS_T PMC_OTSS;

		/* address: 0xF000B8DC */
		PMC_OTSC0_T PMC_OTSC0;

		/* address: 0xF000B8E0 */
		PMC_OTSC1_T PMC_OTSC1;

		/* address: 0xF000B8E4 */
		PMC_CPUSTA_T PMC_CPUSTA;

		/* address: 0xF000B8E8 */
		PMC_CPU0CS_T PMC_CPU0CS;

		/* address: 0xF000B8EC */
		PMC_CPU1CS_T PMC_CPU1CS;

		/* address: 0xF000B8F0 */
		DTSP_RES_T DTSP_RES;

		/* address: 0xF000B8F4 */
		DTSP_RANG_T DTSP_RANG;

		/* address: 0xF000B8F8 */
		DTSP_STA_T DTSP_STA;

		/* address: 0xF000B8FC */
		DTSC_RES_T DTSC_RES;

		/* address: 0xF000B900 */
		DTSC_RANG_T DTSC_RANG;

		/* address: 0xF000B904 */
		DTSC_CTL_T DTSC_CTL;

		/* address: 0xF000B908 */
		DTSC_STA_T DTSC_STA;

		/* address: 0xF000B90C */
		PMC_TCS0_T PMC_TCS0;

		/* address: 0xF000B910 */
		PMC_TCS1_T PMC_TCS1;

		/* address: 0xF000B914 */
		PMC_TCS2_T PMC_TCS2;

		/* address: 0xF000B918 */
		PMC_TCS3_T PMC_TCS3;
	} Pmc_RegisterMap_t;

#define PMC_ADDR ((uint32_t)0xF000B800)
#define PMC_PTR ((Pmc_RegisterMap_t *)PMC_ADDR)
#define PMC_RM (*(Pmc_RegisterMap_t *)PMC_ADDR)

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
