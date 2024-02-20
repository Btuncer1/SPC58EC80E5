/****************************************************************************
*
* Copyright © 2018-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    sema4_lld.h
 * @brief   SPC5xx Semaphore control unit.
 *
 * @addtogroup Semaphore
 * @{
 */
#ifndef _SEMA4_LLD_H_
#define _SEMA4_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_SEMA4 == TRUE) || defined(__DOXYGEN__)

/**
 * @brief    Semaphore operation results
 */
typedef enum {
	SEMA4_NO_ERROR = 0x10,	/**< @brief   no errors. */
	SEMA4_ERROR_INVALID,	/**< @brief   invalid operation on a semaphore identifier */
	SEMA4_ERROR_TIMEOUT,	/**< @brief   timeout expired */
	SEMA4_ERROR_BUSY,		/**< @brief   semaphore already locked */
	SEMA4_ERROR_ID			/**< @brief   wrong semaphore identifier */
} sema4_result_t;

/**
 * @brief    Semaphore status
 */
typedef struct {
	uint8_t lock;
	uint8_t core;
} sema4_status_t;

#ifdef __cplusplus
extern "C" {
#endif
void sema4_init(void);
void sema4_deinit(void);
sema4_result_t sema4_reset(uint8_t sem);
sema4_result_t sema4_acquire(uint8_t *sem);
sema4_result_t sema4_release(uint8_t sem);
sema4_result_t sema4_lock(uint8_t sem);
sema4_result_t sema4_trylock(uint8_t sem);
sema4_result_t sema4_locktimed(uint8_t sem, uint32_t utimeout);
sema4_result_t sema4_unlock(uint8_t sem);
uint8_t sema4_islocked(uint8_t sem);
sema4_result_t sema4_get_status(uint8_t sem, sema4_status_t *status);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_SEMA4 */
#endif /* _SEMA4_LLD_H_ */
/** @} */

