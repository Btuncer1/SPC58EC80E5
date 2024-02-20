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
 * @file    cmpu_lld.h
 * @brief   SPC5xx CMPU low level driver header.
 *
 * @addtogroup CMPU
 * @{
 */

#ifndef _CMPU_LLD_H_
#define _CMPU_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_CMPU == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    MPU0 Control and Status Register 0 bits definitions
 * @{
 */
#define SPC5_CMPU_MPU0CSR0_BYPSR_NO_BYPASS  (0UL << 15) /* No Bypass of MPU protections for Supervisor Read accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPSR_BYPASS_MPU (1UL << 15) /* Bypass MPU protections for Supervisor Read accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPSW_NO_BYPASS  (0UL << 14) /* No Bypass of MPU protections for Supervisor Write accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPSW_BYPASS_MPU (1UL << 14) /* Bypass MPU protections for Supervisor Write accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPSX_NO_BYPASS  (0UL << 13) /* No Bypass of MPU protections for Supervisor Instruction accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPSX_BYPASS_MPU (1UL << 13) /* Bypass MPU protections for Supervisor Instruction accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPUR_NO_BYPASS  (0UL << 12) /* No Bypass of MPU protections for User Read accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPUR_BYPASS_MPU (1UL << 12) /* Bypass MPU protections for User Read accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPUW_NO_BYPASS  (0UL << 11) /* No Bypass of MPU protections for User Write accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPUW_BYPASS_MPU (1UL << 11) /* Bypass MPU protections for User Write accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPUX_NO_BYPASS  (0UL << 10) /* No Bypass of MPU protections for User Instruction accesses. */
#define SPC5_CMPU_MPU0CSR0_BYPUX_BYPASS_MPU (1UL << 10) /* Bypass MPU protections for User Instruction accesses. */
/** @} */

/**
 * @name    MPU Assist Registers bits definitions
 * @{
 */
#define SPC5_CMPU_MAS0_G_NOT_GUARDED        (0UL << 1)  /* Accesses to the region are not guarded. */
#define SPC5_CMPU_MAS0_G_GUARDED            (1UL << 1)  /* All loads and stores to the region are performed without speculation. */
#define SPC5_CMPU_MAS0_I_CACHEABLE          (0UL << 3)  /* The region is considered cacheable*/
#define SPC5_CMPU_MAS0_I_CACHE_INHIBITED    (1UL << 3)  /* The region is considered cache-inhibited*/
#define SPC5_CMPU_MAS0_GOVR_NO_OVERRIDE     (0UL << 6)  /* No override of G attribute by entry. */
#define SPC5_CMPU_MAS0_GOVR_OVERRIDE        (1UL << 6)  /* Entry G bit overrides G attribute. */
#define SPC5_CMPU_MAS0_IOVR_NO_OVERRIDE     (0UL << 7)  /* No override of I attribute by entry. */
#define SPC5_CMPU_MAS0_IOVR_OVERRIDE        (1UL << 7)  /* Entry I bit overrides I attribute. */
#define SPC5_CMPU_MAS0_SXSR_NO_ERP          (0UL << 8)  /* No Supervisor mode Execute/Read permission. */
#define SPC5_CMPU_MAS0_SXSR_ERP             (1UL << 8)  /* Supervisor mode has Execute/Read permission. */
#define SPC5_CMPU_MAS0_UXUR_NO_ERP          (0UL << 9)  /* No User mode Execute/Read permission. */
#define SPC5_CMPU_MAS0_UXUR_ERP             (1UL << 9)  /* User mode has Execute/Read permission. */
#define SPC5_CMPU_MAS0_SW_NO_WP             (0UL << 10) /* No Supervisor mode Write permission. */
#define SPC5_CMPU_MAS0_SW_WP                (1UL << 10) /* Supervisor mode Write permission. */
#define SPC5_CMPU_MAS0_UW_NO_WP             (0UL << 11) /* No User mode Write permission. */
#define SPC5_CMPU_MAS0_UW_WP                (1UL << 11) /* User mode Write permission. */
#define SPC5_CMPU_MAS0_UAMSK_NO_MASKED      (0UL << 12) /* No upper address bits are masked. */
#define SPC5_CMPU_MAS0_UAMSK_UPPER_BIT      (1UL << 12) /* The most significant access address bit is forced to zero before matching. */
#define SPC5_CMPU_MAS0_UAMSK_UPPER_2_BITS   (2UL << 12) /* The 2 most significant access address bits are forced to zero before matching. */
#define SPC5_CMPU_MAS0_UAMSK_UPPER_5_BITS   (5UL << 12) /* The upper 5 access address bits are forced to zero before matching. */
#define SPC5_CMPU_MAS0_SHD_NOT_ACCESSED     (0UL << 23) /* The shared portion of the region descriptor table is not accessed on a mpure or mpuwe operation. */
#define SPC5_CMPU_MAS0_SHD_ACCESSED         (1UL << 23) /* The shared portion of the region descriptor table is accessed on a mpure or mpuwe operation. */
#define SPC5_CMPU_MAS0_INST_DATA            (0UL << 24) /* MPU entry is used for matching data accesses only. */
#define SPC5_CMPU_MAS0_INST_INSTRUCTION     (1UL << 24) /* MPU entry is used for matching instruction accesses only. */
#define SPC5_CMPU_MAS0_DEBUG_NORMAL         (0UL << 25) /* MPU entry is used for access protections. */
#define SPC5_CMPU_MAS0_DEBUG_DEBUG          (1UL << 25) /* MPU entry is used for generating a debug event. */
#define SPC5_CMPU_MAS0_RO_WRITABLE          (0UL << 26) /* MPU entry is writable. */
#define SPC5_CMPU_MAS0_RO_READ_ONLY         (1UL << 26) /* MPU entry is Read-only. */
#define SPC5_CMPU_MAS0_SEL_NO_ACCESS        (0UL << 28) /* No access. */
#define SPC5_CMPU_MAS0_SEL_SELECT_MPU       (2UL << 28) /* Select MPU. */
#define SPC5_CMPU_MAS0_IPROT_NOT_PROTECTED  (0UL << 30) /* Entry is not protected from invalidation. */
#define SPC5_CMPU_MAS0_IPROT_PROTECTED      (1UL << 30) /* Entry is protected from invalidation. */
#define SPC5_CMPU_MAS0_VALID_INVALID        (0UL << 31) /* MPU entry is invalid. */
#define SPC5_CMPU_MAS0_VALID_VALID          (1UL << 31) /* MPU entry is valid. */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a structure representing a CMPU driver.
 */
typedef struct CMPUDriver CMPUDriver;

/**
 * @brief   CMPU entry configuration structure.
 */
typedef struct {
  /**
   * @brief   MPU Assist Registers 0 value.
   */
  uint32_t                  mas0;
  /**
   * @brief   MPU Assist Registers 1 value.
   */
  uint32_t                  mas1;
  /**
   * @brief   MPU Assist Registers 2 value.
   */
  uint32_t                  mas2;
  /**
   * @brief   MPU Assist Registers 3 value.
   */
  uint32_t                  mas3;
} CMPUEntryConfig;

/**
 * @brief   CMPU driver configuration structure.
 */
typedef struct {
  /**
   * @brief   MPU Control and Status Register value.
   */
  uint32_t                  mpu0csr0;
  /**
   * @brief   CMPU entries configurations.
   */
  CMPUEntryConfig     *entry[SPC5_CMPU_NUM_OF_ENTRIES];
} CMPUConfig;

/**
 * @brief   Structure representing an CMPU driver.
 */
struct CMPUDriver {
  /**
   * @brief   Current configuration data.
   */
  CMPUConfig          *config;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Return the value of the ESEL field in the MAS0 register.
 *
 * @param[in] esel      Entry select value.
 * @return              The value of the ESEL field in the MAS0 register.
 *
 * @api
 */
#define SPC5_CMPU_MAS0_ESEL_VALUE(esel)          ((uint32_t)(esel) << 16U)

/**
 * @brief   Return the value of the MAS1 register.
 *
 * @param[in] tid       Region ID bits
 * @param[in] tidmsk    Region ID mask
 * @return              The value of the MAS1 register.
 *
 * @api
 */
#define SPC5_CMPU_MAS1_REG_VALUE(tid, tidmsk)    (uint32_t)(((uint32_t)(tid) << 16U) | ((uint32_t)(tidmsk) << 0U))

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

extern CMPUDriver CMPUD1;

#ifdef __cplusplus
extern "C" {
#endif
  void cmpu_lld_init(void);
  void cmpu_lld_start(CMPUDriver *cmpudp, CMPUConfig *config);
  void cmpu_lld_stop(void);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_CMPU */

#endif /* _CMPU_LLD_H_ */

/** @} */
