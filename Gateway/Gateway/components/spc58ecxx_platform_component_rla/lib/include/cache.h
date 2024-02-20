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
#include "typedefs.h"
#include "spr.h"

#ifndef _CACHE_H_
#define _CACHE_H_

typedef enum {
	DC_TYPE = 0,
	IC_TYPE
} cache_type_t;

typedef enum {
	IC_ICSIZE = 0,
	DC_DCSIZE
} cache_cfg_t;

typedef enum {
	ICDC_NO_ERROR = 0,
	ICDC_ERROR_UNAVAILABLE,
	ICDC_ERROR_ABORTED
} cache_result_t;

#ifdef __cplusplus
extern "C" {
#endif
cache_result_t cache_enable(cache_type_t ctype);
cache_result_t cache_disable(cache_type_t ctype);
cache_result_t cache_set_control(cache_type_t ctype, uint32_t ccsr);
cache_result_t cache_invalidate(cache_type_t ctype);
cache_result_t cache_invalidate_range(uint32_t addr, uint16_t size);
cache_result_t cache_flush_range(uint32_t addr, uint16_t size);
unsigned int cache_get_cfg(cache_cfg_t ccfg);
unsigned int cache_get_status(cache_type_t ctype);
#ifdef __cplusplus
}
#endif

#define CACHE_ENABLE_ALL() { \
	cache_enable(IC_TYPE); \
	cache_enable(DC_TYPE); \
}

#define CACHE_DISABLE_ALL() { \
	cache_disable(IC_TYPE); \
	cache_disable(DC_TYPE); \
}

#endif /* _CACHE_H_ */
