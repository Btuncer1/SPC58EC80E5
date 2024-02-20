/****************************************************************************
*
* Copyright © 2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    cmpu_lld.c
 * @brief   SPC5xx CMPU low level driver code.
 *
 * @addtogroup CMPU
 * @{
 */

#include "cmpu_lld.h"

#if (LLD_USE_CMPU == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   CMPU driver identifier.
 */
CMPUDriver CMPUD1;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   CMPU entries invalidation.
 * @details This function invalidates all the CMPU entries.
 *
 * @notapi
 */
static void cmpu_lld_invalidate_all_entries(void) {

  uint32_t value = 0UL;

  /* Invalidate all entries.*/
  mtspr(SPC5_SPR_MPU0CSR0, 0x00000002UL);

  /* Wait until the invalidate operation is completed.*/
  do {

    mfspr(SPC5_SPR_MPU0CSR0, value);

  } while ((value & 0x00000002UL) != 0UL);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level CMPU driver initialization.
 *
 * @init
 */
void cmpu_lld_init(void) {

  /* Invalidate all entries.*/
  cmpu_lld_invalidate_all_entries();
}

/**
 * @brief   Low level CMPU driver configuration and start.
 *
 * @param[in] cmpudp    pointer to a @p CMPUDriver object
 * @param[in] config    the architecture-dependent CMPU driver configuration.
 *
 * @api
 */
/* Variables used only as parameters of macros based on asm instructions are
   considered by MISRA unused. So, MISRA Rules 2.2 is skipped.*/
/*lint -e438 -e550 */
void cmpu_lld_start(CMPUDriver *cmpudp, CMPUConfig *config) {

  uint8_t i;
  uint32_t mpu0csr0;

  cmpudp->config = config;

  for (i = 0; i < SPC5_CMPU_NUM_OF_ENTRIES; i++) {
    if (cmpudp->config->entry[i] != NULL) {
      /* Set MPU Assist Registers 0 (MAS0).*/
      mtspr(SPC5_SPR_MAS0, cmpudp->config->entry[i]->mas0);

      /* Set MPU Assist Registers 1 (MAS1) - TID and TIDMSK.*/
      mtspr(SPC5_SPR_MAS1, cmpudp->config->entry[i]->mas1);

      /* Set MPU Assist Registers 2 (MAS2) - Upper bound.*/
      mtspr(SPC5_SPR_MAS2, cmpudp->config->entry[i]->mas2);

      /* Set MPU Assist Registers 3 (MAS3) - Lower bound.*/
      mtspr(SPC5_SPR_MAS3, cmpudp->config->entry[i]->mas3);

      mpuwe();
    }
  }

  /* Enable MPU.*/
  mpu0csr0 = cmpudp->config->mpu0csr0 | 0x00000001UL;
  mtspr(SPC5_SPR_MPU0CSR0, mpu0csr0);

  mpusync();
}
/*lint +e438 +e550 */

/**
 * @brief   Low level CMPU driver stop.
 *
 * @api
 */
void cmpu_lld_stop(void) {

  /* Invalidate all entries.*/
  cmpu_lld_invalidate_all_entries();
}

#endif /* LLD_USE_CMPU */

/** @} */
