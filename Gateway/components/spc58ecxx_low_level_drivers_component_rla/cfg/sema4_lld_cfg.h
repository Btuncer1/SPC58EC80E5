/****************************************************************************
*
* Copyright © 2019-2022 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    sema4_lld_cfg.h
 * @brief   SPC5xx Semaphore control unit.
 *
 * @addtogroup Semaphore
 * @{
 */
#ifndef _SEMA4_LLD_CFG_H_
#define _SEMA4_LLD_CFG_H_

#include <sema4_lld.h>

#if (LLD_USE_SEMA4 == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
/* Depending on the platform the reset gate registers may be 1 or 2 to use for
 * sending reset commands sequence and monitor state machine.
 */
#define RSTGTW 	RSTGT_W
#define RSTGTR 	RSTGT_R
#define SEMA4_MODULES	 	1U
#define SEMA4_GATES			16U

#endif /* LLD_USE_SEMA4 */
#endif /* _SEMA4_LLD_CFG_H_ */

/** @} */
