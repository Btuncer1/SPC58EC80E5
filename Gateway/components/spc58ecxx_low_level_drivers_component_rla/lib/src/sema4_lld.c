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
 * @file    sema4_lld.c
 * @brief   SPC5xx Semaphore control unit.
 *
 * @addtogroup Semaphore
 * @{
 */
#include "sema4_lld.h"

#if (LLD_USE_SEMA4 == TRUE) || defined(__DOXYGEN__)
#include "sema4_lld_cfg.h"

static volatile struct SEMA42_tag *SEMA4_Tag[SEMA4_MODULES];
static uint8_t sema4_sems[SEMA4_GATES];

/*******************************************************************************
* Local functions
*******************************************************************************/
/*lint -save -e* */
static inline uint8_t sema4_getpir(void) {
	volatile uint8_t pir = 0xFFU;

	mfspr(286, pir);
	if (pir >= 3U) {
		/* For the platform where the PIR has not been
		 * setup we use Core2 as default processor master. */
		pir = 2U;
	}
	return pir;
}

static inline void _sema4_lock(void) {
	vuint8_t pir = sema4_getpir() + 1U;
	SEMA4_Tag[0U]->GATE[0U].B.GTFSM = pir;
	while (SEMA4_Tag[0U]->GATE[0U].R != pir)
		{ /* waiting until it will be freed */
		SEMA4_Tag[0U]->GATE[0U].B.GTFSM = pir;
		}
	return;
}

static inline void _sema4_unlock(void) {
	while ((SEMA4_Tag[0U]->GATE[0U].R != 0U) &&
		(SEMA4_Tag[0U]->GATE[0U].R == (sema4_getpir() + 1U))) {
		SEMA4_Tag[0U]->GATE[0U].R = 0U;
	}
	return;
}

static inline uint8_t sema4_isvalid(uint8_t sem) {
	if (sem >= 64U) {
		return 1U;
	}
	if (((sem >= 1U) && (sem < SEMA4_GATES)) &&
		(sema4_sems[sem] == 1U)) {
		return 1U;
	}
	return 0U;
}
/*lint restore */

/*******************************************************************************
* Global functions
*******************************************************************************/
/**
 * @brief	Initialize semaphores interface to be usable.
 *
 * @api
 */
void sema4_init(void) {
	uint8_t sem;

	/* Semaphore reference tag initialization */
	SEMA4_Tag[0] = &SEMA4_0;

	_sema4_lock();
	if (sema4_sems[0] == 0U) {
		for (sem = 0U; sem < SEMA4_GATES; sem++) {
			sema4_sems[sem] = 0U;
		}

		/* First gate reserved as internal semaphore */
		sema4_sems[0U] = 1U;

		/* Unlock everything to start in a consistent way. */
		// TBD sema4_reset(64);
	}
	_sema4_unlock();
}

/**
 * @brief   			DeInitialize semaphore interface to be unusable.
 *
 * @api
 */
void sema4_deinit(void) {
	SEMA4_Tag[0] = NULL;
	sema4_sems[0] = 0U;
}

/**
 * @brief   			Reset all or a specific semaphore.
 *
 * @param[in] sem		The semaphore identifier to reset. With sem greater than 63
 *						everything is reset.
 *
 * @return				The semaphore sem, SEMA4_ERROR_ID error otherwise.
 *
 * @api
 */
sema4_result_t sema4_reset(uint8_t sem) {
	sema4_result_t res = SEMA4_ERROR_ID;
	uint16_t state, s;

	if ((sema4_isvalid(sem) == 1U) || (sem > 63U)) {
		/* the secure gate reset requires two consecutive
		 * writes with predefined data patterns 
		 */
		res = SEMA4_ERROR_INVALID;
		state = SEMA4_Tag[0]->RSTGTR.R >> 12;
		/* Is it in Idle state */
		if (state == 0U) {
			/* Send 1-st write */
			SEMA4_Tag[0]->RSTGTW.R = 0xE2U << 8U;
			state = SEMA4_Tag[0]->RSTGTR.R >> 12;
			if (state == 1U) {
				/* Waiting for the second data pattern write
				 * Send 2-nd write
				 */
				SEMA4_Tag[0]->RSTGTW.R = (0x1DU << 8U) | sem;
				state = SEMA4_Tag[0]->RSTGTR.R >> 12;
			}
			if (state == 0U) {
				/* sequence completed, gate returns to idle state*/
				res = SEMA4_NO_ERROR;
			}
		}
	}
	if (res == SEMA4_NO_ERROR) {
		if (sem > 63U) {
			/* Reset all semaphores */
			for (s = 0U; s < SEMA4_GATES; s++) {
				sema4_sems[s] = 0U;
			}
		} else {
			/* Reset a sigle semaphore */
			sema4_sems[sem] = 0U;
		}
	}
	return res;
}

/**
 * @brief   	Acquire and reserve a semaphore identifier.
 * 				It preserves multiple access on future lock/unlock gate requests
 *				via the lock, trylock and unlock routines.
 *
 * @param[in] sem		The semaphore identifier to ask for.
 *
 * @return		The semaphore sem, SEMA4_ERROR_ID error otherwise.
 *
 * @api
 */
sema4_result_t sema4_acquire(uint8_t *sem) {
	uint8_t i;
	sema4_result_t res = SEMA4_ERROR_ID;

	_sema4_lock();
	*sem = 0U;
	for (i = 1U; i < SEMA4_GATES; i++) {
		if (sema4_sems[i] == 0U) {
			sema4_sems[i] = 1U;
			*sem = i;
			res = SEMA4_NO_ERROR;
			break;
		}
	}
	_sema4_unlock();

	return res;
}

/**
 * @brief   	Release a semaphore identifier.
 *				It makes free the semaphore identifier only if the lock gate
 *				was unlocked via unlock routine.
 *				
 * @param[in] sem		The semaphore identifier to ask for.
 *
 * @return		No error if the semaphore was freed, error otherwise.
 *
 * @api
 */
sema4_result_t sema4_release(uint8_t sem) {
	sema4_result_t res = SEMA4_ERROR_ID;

	_sema4_lock();
	if (sema4_isvalid(sem) == 1U) {
		if (SEMA4_Tag[0]->GATE[sem].R == 0U) {
			sema4_sems[sem] = 0U;
			res = SEMA4_NO_ERROR;
		} else {
			res = SEMA4_ERROR_BUSY;
		}
	}
	_sema4_unlock();
	return res;
}

/**
 * @brief   			Get the semaphore status.
 *
 * @param[in] sem		The semaphore identifier to ask for.
 *
 * @return				True if the semaphore is locked, false otherwise.
 *
 * @api
 */
uint8_t sema4_islocked(uint8_t sem) {
	if (sema4_isvalid(sem) == 1U) {
		if (SEMA4_Tag[0]->GATE[sem].R != 0U) {
			return 1U;
		}
	}
	return 0U;
		
}

/**
 * @brief   		Lock the semaphore if it is currently not locked.
 *
 * @param[in] sem	The semaphore identifier to ask for.
 *
 * @return			No error if was locked, error otherwise.
 *
 * @api
 */
sema4_result_t sema4_trylock(uint8_t sem) {

	if (sema4_isvalid(sem) == 1U) {
		vuint8_t pir = sema4_getpir() + 1;
		SEMA4_Tag[0]->GATE[sem].B.GTFSM = pir;
		if (SEMA4_Tag[0]->GATE[sem].R == pir) {
			return SEMA4_NO_ERROR;
		} else {
			return SEMA4_ERROR_BUSY;
		}
	}
	return SEMA4_ERROR_ID;
}

/**
 * @brief   		Lock a semaphore waiting until it will be freed, unlocked.
 *
 * @param[in] sem	The semaphore identifier to ask for.
 *
 * @return			No error otherwise loop forever.
 *
 * @api
 */
sema4_result_t sema4_lock(uint8_t sem) {
	if (sema4_isvalid(sem) == 1U) {
		while (sema4_trylock(sem) != SEMA4_NO_ERROR)
			{ /* waiting until it will be freed */ }
		return SEMA4_NO_ERROR;
	}
	return SEMA4_ERROR_ID;		
}

/**
 * @brief   			Unlock the previuosly semaphore locked.
 *						A semaphore can (and must) be opened/unlocked by the locking processor core.
 *
 * @param[in] sem		The semaphore identifier to ask for.
 *
 * @return				No error if freed/unlocked, error otherwise.
 *
 * @api
 */
sema4_result_t sema4_unlock(uint8_t sem) {
	if (sema4_isvalid(sem) == 1U) {
		if ((SEMA4_Tag[0]->GATE[sem].R != 0U) && 
			(SEMA4_Tag[0]->GATE[sem].R == (sema4_getpir() + 1U))) {
			SEMA4_Tag[0]->GATE[sem].R = 0U;
			return SEMA4_NO_ERROR;
		} else {
			return SEMA4_ERROR_INVALID;
		}
	}
	return SEMA4_ERROR_ID;
}

/**
 * @brief   			Try to lock the semaphore before the timeout expires.
 *
 * @param[in] sem		The semaphore identifier to ask for.
 * @param[in] utimeout	The specified timeout in microseconds to wait.
 *
 * @return				No error if locked before time expirations, error otherwise.
 *
 * @api
 */
sema4_result_t sema4_locktimed(uint8_t sem, uint32_t utimeout) {
	sema4_result_t res = SEMA4_ERROR_ID;
	uint32_t curr_time = osalThreadGetMicroseconds();
	
	if (sema4_isvalid(sem) == 1U) {
		while ((res = sema4_trylock(sem)) != SEMA4_NO_ERROR) {
			if (utimeout < (osalThreadGetMicroseconds() - curr_time)) {
				res = SEMA4_ERROR_TIMEOUT;
				break;
			}
			
		}
	}
	return res;
}

/**
 * @brief   			Get the semaphore status.
 *
 * @param[in] sem		The semaphore identifier to ask for.
 * @param[in] status	The semaphore status and the core who locked it.
 *						Core number will be 0xFF if semaphore unlocked.
 * @return				No error if locked before time expirations, error otherwise.
 *
 * @api
 */
sema4_result_t sema4_get_status(uint8_t sem, sema4_status_t *status) {
	status->lock = 0x00U;
	status->core = 0xFFU;
	if (sema4_isvalid(sem) == 1U) {
		status->lock = sema4_islocked(sem);
		/* If not locked we cannot know who did it */
		if (status->lock == 1U)
			status->core = SEMA4_Tag[0]->GATE[sem].B.GTFSM - 1;
		return SEMA4_NO_ERROR;
	}
	return SEMA4_ERROR_ID;
}

#endif /* LLD_USE_SEMA4 */

/** @} */