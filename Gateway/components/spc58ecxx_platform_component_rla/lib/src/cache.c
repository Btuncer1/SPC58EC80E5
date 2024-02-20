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
#include "cache.h"
#include "boot.h"
#include "spr.h"

/**
 * @file    cache.c
 * @brief   SPC5xx Cache control unit.
 *
 * @addtogroup Cache
 * @{
 */

/**
 * @name    L1CSR0 registers definitions
 * @{
 */
#define L1CSR0_DCE		0x00000001U /**< @brief Data Cache enable. */
#define L1CSR0_DCINV	0x00000002U /**< @brief Data Cache flash invalidate. */
#define L1CSR0_DCABT	0x00000004U /**< @brief Data Cache operation aborted. */
#define L1CSR0_DCLOINV	0x00000010U	/**< @brief Data Cache Lockout Indicator Invalidate. */
#define L1CSR0_DCEA		0x00000020U	/**< @brief Data Cache Error Action. */
#define L1CSR0_DCEI		0x00008000U	/**< @brief Data Cache Error Injection Enable. */
#define L1CSR0_DCECE	0x00010000U	/**< @brief Data Cache Error Checking Enable. */

/** @} */

/**
 * @name    L1CSR1 registers definitions
 * @{
 */
#define L1CSR1_ICE		0x00000001U	/**< @brief Instruction Cache Enable. */
#define L1CSR1_ICINV	0x00000002U	/**< @brief Instruction Cache Invalidate. */
#define L1CSR1_ICABT	0x00000004U	/**< @brief Instruction Cache Operation Aborted. */
#define L1CSR1_ICLOINV	0x00000010U	/**< @brief Instruction Cache Lockout Indicator Invalidate. */
#define L1CSR1_ICEA		0x00000020U	/**< @brief Instruction Cache Error Action. */
#define L1CSR1_ICEI		0x00008000U	/**< @brief Instruction Cache Error Injection Enable. */
#define L1CSR1_ICECE	0x00010000U	/**< @brief Instruction Cache Error Checking Enable. */
/** @} */

/**
 * @name    L1CFG0 registers definitions
 * @{
 */
#define	L1CFG0_CARCH	0xC0000000U	/**< @brief Data Cache architecture. */
#define	L1CFG0_CWPA		0x20000000U	/**< @brief Data Cache way partitioning APU available. */
#define	L1CFG0_CFAHA	0x10000000U	/**< @brief Data Cache flush all by hardware available. */
#define	L1CFG0_DCFISWA	0x08000000U	/**< @brief Data Cache flush by set and way available. */
#define	L1CFG0_DCBSIZE	0x01800000U	/**< @brief Data Cache line size. */
#define	L1CFG0_DCREPL	0x00600000U	/**< @brief Data Cache replacement policy. */
#define	L1CFG0_DCLA		0x00100000U	/**< @brief Data Cache line locking APU available. */
#define	L1CFG0_DCEA		0x00080000U	/**< @brief Data Cache Error Checking Available. */
#define	L1CFG0_DCNWAY	0x0007F800U	/**< @brief Data Cache number of ways minus 1. */
#define	L1CFG0_DCSIZE	0x000007FFU	/**< @brief Data Cache size in Kbytes. */
/** @} */

/**
 * @name    L1CFG1 registers definitions
 * @{
 */
#define	L1CFG1_ICFISWA	0x08000000U	/**< @brief Instruction Cache Flush/Invalidate by Set and Way Available. */
#define	L1CFG1_ICBSIZE	0x00C00000U	/**< @brief Instruction Cache Block Size. */
#define	L1CFG1_ICREPL	0x00600000U	/**< @brief Instruction Cache Replacement Policy. */
#define	L1CFG1_ICLA		0x00100000U	/**< @brief Instruction Cache Locking APU Available. */
#define	L1CFG1_ICECA	0x00080000U	/**< @brief Instruction Cache Error Checking Available. */
#define	L1CFG1_ICNWAY	0x0007F800U	/**< @brief Instruction Cache Number of Ways. */
#define	L1CFG1_ICSIZE	0x000007FFU	/**< @brief Instruction Cache Size. */
/** @} */

/*lint -save -e* */
/*******************************************************************************
* Specific Compiler functions and macros
*******************************************************************************/
/* Wrapper to stop unsupported relocation */
#define _mfspr(ctype, v) \
		if (ctype == IC_TYPE) { \
			mfspr(SPC5_SPR_L1CSR1, v); \
		} else { \
			mfspr(SPC5_SPR_L1CSR0, v); \
		}

#define _mtspr(ctype, v) \
		if (ctype == IC_TYPE) { \
			mtspr(SPC5_SPR_L1CSR1, v); \
		} else { \
			mtspr(SPC5_SPR_L1CSR0, v); \
		}

/* Full sync */
#define _fsync() { \
  isync();        \
  msync();        \
}

/*******************************************************************************
* Local functions
*******************************************************************************/
static cache_result_t idc_invalidate(cache_type_t ctype, uint8_t savectx) {
	unsigned char sets, s, w;
	unsigned int inv_val, abo_val;
	unsigned int spr = 0U, ccache = 0U;
	cache_result_t cres = ICDC_NO_ERROR;
	
	/* Reset does not invalidate the Cache automatically */
	if (ctype == IC_TYPE) {
		inv_val = L1CSR1_ICINV | L1CSR1_ICLOINV;
		abo_val = L1CSR1_ICABT;
		sets = 255U;
	} else {
		inv_val = L1CSR0_DCINV | L1CSR0_DCLOINV;
		abo_val = L1CSR0_DCABT;
		sets = 127U;
	}

	/* Save context */
	if (savectx == 1U) {
		_mfspr(ctype, ccache);
	}

	/* Cache Invalidate */
	_mtspr(ctype, inv_val);
	_mfspr(ctype, spr);
	/* At the end of hardware cache invalidation
	 * the invalidation bit must be go back to zero.
	*/
	while ((spr & inv_val) == inv_val) {
		_mfspr(ctype, spr);
	};
		
	/* Check if Instruction Cache Operation Aborted */
	_mfspr(ctype, spr);
	if ((spr & abo_val) == abo_val) {
		spr = spr & (~abo_val);
		_mtspr(ctype, spr);
		cres = ICDC_ERROR_ABORTED;
	}
	
	/* Try to invalidate by set and way by L1FINV[0,1]
	 * The z4256n3 caches are organized as two ways of 256 (I) 
	 * and 128 (D) sets with each line containing 32 bytes 
	 * DCACHE = 128 * 32 = 4KiB , ICACHE = 256 * 32 = 8KiB */
	 if (cres != ICDC_NO_ERROR) 
		for (w = 0U; w < 2U; w++) {
			for (s = 0U; s <= sets; s++) {
				spr = (w << 24U) | (s << 5U);
				if (ctype == IC_TYPE)
					mtspr(SPC5_SPR_L1FINV1, spr);
				else
					mtspr(SPC5_SPR_L1FINV0, spr);
			}
		}
	
	/* Restore context */
	if (savectx == 1U) {
		_mtspr(ctype, ccache);
	}
	
	return cres;
}

static void idc_enable(cache_type_t ctype, unsigned int def) {
	unsigned int spr = 0U;

	/* Cache enable */
	_mfspr(ctype, spr);
	spr = spr | def;
	_mtspr(ctype, spr);
}

static void idc_disable(cache_type_t ctype) {
	unsigned int spr = 0U;

	/* Cache disable.
	 * ICE and DCE bit have same bit-positioning
	 */
	_mfspr(ctype, spr);
	spr = spr & (~L1CSR1_ICE);
	_mtspr(ctype, spr);
}

static cache_result_t idc_exist(cache_type_t ctype) {
	if (ctype == IC_TYPE) {
		if (cache_get_cfg(IC_ICSIZE) == 0U)
			return ICDC_ERROR_UNAVAILABLE;
	} else {
		if (cache_get_cfg(DC_DCSIZE) == 0U)
			return ICDC_ERROR_UNAVAILABLE;
	}
	return ICDC_NO_ERROR;
}

/*******************************************************************************
* Global functions
*******************************************************************************/
/**
 * @brief   			Cache get status.
 *
 * @param[in] ctype	The type of the request, IC_TYPE or DC_TYPE.
 *
 * @return				True if the cache is enabled.
 *
 * @api
 */
unsigned int cache_get_status(cache_type_t ctype) {
	unsigned int spr = 0U;

	if (idc_exist(ctype) != ICDC_NO_ERROR)
		return spr;

	if (ctype == IC_TYPE) {
		mfspr(SPC5_SPR_L1CSR1, spr);
		return (spr & L1CSR1_ICE);
	}
	mfspr(SPC5_SPR_L1CSR0, spr);
	return (spr & L1CSR0_DCE);
}

/**
 * @brief   			Cache Enable.
 *
 * @param[in] ctype	The type of the request, IC_TYPE or DC_TYPE.
 *
 * @return				Operation result.
 * 
 * @api
 */
cache_result_t cache_enable(cache_type_t ctype) {
	cache_result_t cres = ICDC_NO_ERROR;

	if ((cres = idc_exist(ctype)) != ICDC_NO_ERROR)
		return cres;

	mtspr(SPC5_SPR_BUCSR, BUCSR_DEFAULT);

	/* Altering the ICE bit must be preceded by sync
	 * to prevent the cache from being in the middle of data access. */
	_fsync();

	/* Reset does not invalidate a cache or clear the cache line. */
	idc_invalidate(ctype, 1U);
	if (ctype == IC_TYPE) {
		idc_enable(ctype, L1CSR1_ICE);
	} else {
		idc_enable(ctype, L1CSR0_DCE);
	}

	return cres;
}

/**
 * @brief   			Cache set control.
 *
 * @param[in] ctype	The type of the request, IC_TYPE or DC_TYPE.
 * @param[in] l1csr	The cache control register value.
 *
 * @return				Operation result.
 *
 * @api
 */
cache_result_t cache_set_control(cache_type_t ctype, uint32_t ccsr) {
	cache_result_t cres = ICDC_NO_ERROR;

	if ((cres = idc_exist(ctype)) != ICDC_NO_ERROR)
		return cres;

	mtspr(SPC5_SPR_BUCSR, BUCSR_DEFAULT);

	/* Altering the ICE bit must be preceded by sync
	 * to prevent the cache from being in the middle of data access. */
	_fsync();

	cres = idc_invalidate(ctype, 1U);
	_mtspr(ctype, ccsr);

	return cres;
}

/**
 * @brief   			Cache Disable.
 *
 * @param[in] ctype	The type of the request, IC_TYPE or DC_TYPE.
 *
 * @return				Operation result.
 *
 * @api
 */
cache_result_t cache_disable(cache_type_t ctype) {
	cache_result_t cres = ICDC_NO_ERROR;

	if ((cres = idc_exist(ctype)) != ICDC_NO_ERROR)
		return cres;

	mtspr(SPC5_SPR_BUCSR, BUCSR_DEFAULT);

	/* Altering the ICE bit must be preceded by sync
	 * to prevent the cache from being in the middle of data access. */
	_fsync();

	cres = idc_invalidate(ctype, 1U);
	idc_disable(ctype);

	return cres;
}

/**
 * @brief   			Cache get specific informations.
 *
 * @param[in] ccfg		The type of the request available in cache_cfg_t type.
 *
 * @return				The Data value requested.
 *
 * @api
 */
unsigned int cache_get_cfg(cache_cfg_t ccfg) {
	unsigned int spr = 0U;

	mtspr(SPC5_SPR_BUCSR, BUCSR_DEFAULT);
	if (ccfg == IC_ICSIZE) {
		mfspr(SPC5_SPR_L1CFG1, spr);
	} else {
		mfspr(SPC5_SPR_L1CFG0, spr);
	}

	switch (ccfg){
	case IC_ICSIZE:
	case DC_DCSIZE:
		spr &= L1CFG1_ICSIZE;
		break;
	default:
		spr = 0;
	}
	return spr;
}

/**
 * @brief   			Cache invalidations.
 *
 * @param[in] ctype	The type of the request, IC_TYPE or DC_TYPE.
 *
 * @return				Operation result.
 *
 * @api
 */
cache_result_t cache_invalidate(cache_type_t ctype) {
	cache_result_t cres = ICDC_NO_ERROR;

	if ((cres = idc_exist(ctype)) != ICDC_NO_ERROR)
		return cres;

	mtspr(SPC5_SPR_BUCSR, BUCSR_DEFAULT);
	/* Altering the ICE bit must be preceded by sync
	 * to prevent the cache from being in the middle of data access. */
	_fsync();

	/* Invalidating by software control. */
	cres = idc_invalidate(ctype, 1U);

	return cres;
}

/**
 * @brief   			Data cache invalidate block.
 *
 * @param[in] addr		The start address of the block to invalidate.
 * @param[in] size		The block size to invalidate.
 *
 * @return				Operation result.
 *
 * @api
 */
cache_result_t cache_flush_range(uint32_t addr, uint16_t size) {
	uint32_t caddr;
	unsigned int spr = 0U;

	_mfspr(DC_TYPE, spr);
	if ((spr & L1CSR0_DCE) != L1CSR0_DCE)
		return ICDC_ERROR_UNAVAILABLE;

	for (caddr = addr; caddr < (addr + size); caddr += sizeof(uint32_t)) {
		asm volatile ("dcbf 0, %0" : : "r" (caddr));
	}
	return ICDC_NO_ERROR;
}

/**
 * @brief   			Data cache flush block.
 *
 * @param[in] addr		The start address of the block to flush.
 * @param[in] size		The block size to flush.
 *
 * @return				Operation result.
 *
 * @api
 */
cache_result_t cache_invalidate_range(uint32_t addr, uint16_t size) {
	uint32_t caddr;
	unsigned int spr = 0U;

	_mfspr(DC_TYPE, spr);
	if ((spr & L1CSR0_DCE) != L1CSR0_DCE)
		return ICDC_ERROR_UNAVAILABLE;

	mtspr(SPC5_SPR_BUCSR, BUCSR_DEFAULT);
	/* Altering the ICE bit must be preceded by sync
	 * to prevent the cache from being in the middle of data access. */
	_fsync();

	for (caddr = addr; caddr < (addr + size); caddr += sizeof(uint32_t)) {
		asm volatile ("dcbi 0, %0" : : "r" (caddr));
	}
	return ICDC_NO_ERROR;
}
/*lint -restore */
/** @} */
