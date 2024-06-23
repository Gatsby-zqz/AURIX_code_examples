/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a13k_drv_adcs.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2023-12-12
 *  @Version         : V0.0.1.231212_alpha
 *  @Description     : This document describes the C language document template
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                              REVISON HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author          |Description
 ******************************************************************************
 *  |2023-12-12    |V1.0     |Wei Xing     | New Creat
 *****************************************************************************/

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a13k_drv_adcs.h"

/******************************************************************************
 *                      Macro or Typedef
 ******************************************************************************/
#define ADCS_MODULE_NUM (4U)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Local Variables
 ******************************************************************************/
Adcs_SyncMasterIndex_t Adcs_SyncConvertMasterIndex[ADCS_MODULE_NUM][ADCS_MODULE_NUM] = {
  /* Adc0 */
  {
    ADCS_SYNC_MASTER_SELF,
    ADCS_SYNC_MASTER_CI1,
    ADCS_SYNC_MASTER_CI2,
    ADCS_SYNC_MASTER_CI3,
  },
  /* Adc1 */
  {
    ADCS_SYNC_MASTER_CI1,
    ADCS_SYNC_MASTER_SELF,
    ADCS_SYNC_MASTER_CI2,
    ADCS_SYNC_MASTER_CI3,
  },
  /* Adc2 */
  {
    ADCS_SYNC_MASTER_CI1,
    ADCS_SYNC_MASTER_CI2,
    ADCS_SYNC_MASTER_SELF,
    ADCS_SYNC_MASTER_CI3,
  },
  /* Adc3 */
  {
    ADCS_SYNC_MASTER_CI1,
    ADCS_SYNC_MASTER_CI2,
    ADCS_SYNC_MASTER_CI3,
    ADCS_SYNC_MASTER_SELF,
  },
};

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief Adcs模块设置同步平行转换的主机模块
 * @note CurrentModule与MasterModule相同时，本Adcs模块为主控方
 *
 *
 * @param CurrentModule
 * @param MasterModule
 */
void Adcs_LL_SetSyncConvertMaster(const Adcs_Module_t CurrentModule, const Adcs_Module_t MasterModule)
{
    Adcs_LL_SetSyncConvertMasterIndex(
      CurrentModule, Adcs_SyncConvertMasterIndex[(uint32_t)CurrentModule][(uint32_t)MasterModule]);
}
