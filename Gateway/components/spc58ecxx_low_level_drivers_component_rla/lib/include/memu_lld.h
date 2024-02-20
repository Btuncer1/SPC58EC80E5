/****************************************************************************
*
* Copyright © 2020 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    memu_lld.h
 * @brief   SPC5xx MEMU control unit.
 *
 * @addtogroup MEMU
 * @{
 */

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_MEMU == TRUE) || defined(__DOXYGEN__)

/**
 * @brief    MEMU collecting system type.
 */
typedef enum
{
	MEMU_SYSTEM_RAM,
	MENU_PERIPHERAL_RAM,
	MEMU_FLASH_MEMORY
} memu_type_t;

/**
 * @brief    MEMU collecting error type.
 */
typedef enum
{
	MEMU_NO_ERROR,
	MEMU_ERROR_DETECTED,
	MEMU_OVERFLOW_ERROR,
	MEMU_BUFFER_OVERFLOW_ERROR
} memu_errors_t;

/**
 * @brief    MEMU type of error.
 */
typedef enum
{
	MEMU_CORRECTABLE_ENTRY,
	MEMU_UNCORRECTABLE_ENTRY
} memu_entry_t;

/**
 * @brief    MEMU error block report.
 */
typedef struct {
	uint32_t addresses[20U];
	uint8_t  badbits[20U];
	uint8_t  debug;
	memu_type_t type;
	memu_errors_t error;
	memu_entry_t correctable;
} memu_error_block_t;

void memu_init(void);
void memu_get_error(memu_error_block_t *err_block);
void memu_clear_error(memu_error_block_t *err_block);
void memu_invalidate_table(memu_type_t type);
void memu_set_entry(memu_type_t type, uint32_t address, uint8_t bad_bit);
uint8_t memu_get_table_entries(memu_type_t type, memu_entry_t correctable);
void memu_check_connection(void);
void memu_clear_connection(void);
void memu_reset(void);

#endif /* LLD_USE_MEMU */
/** @} */
