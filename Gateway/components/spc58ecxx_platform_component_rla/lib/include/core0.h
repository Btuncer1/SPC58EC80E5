/****************************************************************************
*
* Copyright © 2017-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/**
 * @file    core0.h
 * @brief   core0 boot module header.
 *
 * @addtogroup PPC_BOOT
 * @{
 */

#ifndef _CORE0_H_
#define _CORE0_H_

#include "boot.h"

#if (BOOT_CORE0 == 1)
/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
#ifdef __cplusplus
extern "C" {
#endif
  void runCore0(void);
#ifdef __cplusplus
}
#endif

#endif /* BOOT_CORE0 == 1 */

#endif /* _CORE0_H_ */

/** @} */
