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
 * @file    memu_lld.c
 * @brief   SPC5xx MEMU control unit.
 *
 * @addtogroup MEMU
 * @{
 */
#include "memu_lld.h"

#if (LLD_USE_MEMU == TRUE) || defined(__DOXYGEN__)

#define MEMU_SYSTEM_RAM_ENTRIES		10U
#define MENU_PERIPHERAL_RAM_ENTRIES	 2U
#define MEMU_FLASH_MEMORY_ENTRIES	20U

/*******************************************************************************
* Local functions
*******************************************************************************/
/*******************************************************************************
* Global functions
*******************************************************************************/
/**
 * @brief	Initialize MEMU interface to be usable.
 *
 * @return	No error if MEMU is initialized, error otherwise.
 *
 * @api
 */
 void memu_init(void) {
	// clear status flags and overflow register but not the reporting table
	MEMU.CTRL.B.SWR = 0x1;
	// reset the corresponding error indication to FCCU
	MEMU.ERR_FLAG.R = 0x1F1F1F;
}

 uint8_t memu_get_table_entries(memu_type_t type, memu_entry_t correctable) {
	 if (correctable == MEMU_UNCORRECTABLE_ENTRY)
		 return 0x1U;
	 if (type == MEMU_SYSTEM_RAM)
		 return MEMU_SYSTEM_RAM_ENTRIES;
	 if (type == MENU_PERIPHERAL_RAM)
		 return MENU_PERIPHERAL_RAM_ENTRIES;
	 if (type == MEMU_FLASH_MEMORY)
		 return MEMU_FLASH_MEMORY_ENTRIES;
	 return 0U;
 }

/**
 * @brief   			Invalidate all error addresses.
 *
 * @param[in] type		The error source table: System RAM, Peripheral SRAM
 *                      or Flash memory type.
 *
 * @api
 */
 void memu_invalidate_table(memu_type_t type) {
	uint8_t i;

	switch (type) {
	case MEMU_SYSTEM_RAM:
		for (i = 0U; i < MEMU_SYSTEM_RAM_ENTRIES; i++) {
			MEMU.SYS_RAM[i].CERR_STS.B.VLD = 0x0;
		}
		// Only one System RAM uncorrectable entry
		MEMU.SYS_RAM_UNCERR_STS.B.VLD = 0x0;
		break;
	case MENU_PERIPHERAL_RAM:
		for (i = 0U; i < MENU_PERIPHERAL_RAM_ENTRIES; i++) {
			MEMU.PERIPH_RAM[i].CERR_STS.B.VLD = 0x0;
		}
		// Only one Peripheral RAM uncorrectable entry
		MEMU.PERIPH_RAM_UNCERR_STS.B.VLD = 0x0;
		break;
	case MEMU_FLASH_MEMORY:
		for (i = 0U; i < MEMU_FLASH_MEMORY_ENTRIES; i++) {
			MEMU.FLASH[i].CERR_STS.B.VLD = 0x0;
		}
		// Only one Flash uncorrectable entry
		MEMU.FLASH_UNCERR_STS.B.VLD = 0x0;
		break;
	}
}

/**
 * @brief   			Validate a specific error address.
 *
 * @param[in] type		The error source table: System RAM, Peripheral SRAM
 *                      or Flash memory type.
 *
 * @api
 */
void memu_set_entry(memu_type_t type, uint32_t address, uint8_t bad_bit) {
	uint8_t exist = 0U, i;
	uint8_t entry = 0U;

	switch (type) {
	case MEMU_SYSTEM_RAM:
		for (i = 0; i < MEMU_SYSTEM_RAM_ENTRIES; i++) {
			if (MEMU.SYS_RAM[i].CERR_ADDR.R == address) {
				// Entry with address present
				exist = 1U;
				if (MEMU.SYS_RAM[i].CERR_STS.B.VLD == 0x0)
					entry = i;
				else {
					// Found valid entry with the address
					exist = 0U;
					break;
				}
			} else {
				// Entry with address not present
				if (MEMU.SYS_RAM[i].CERR_STS.B.VLD == 0x0)
					entry = i;
			}		
		}
		if (exist == 0U) {
			MEMU.SYS_RAM[entry].CERR_STS.B.BAD_BIT = bad_bit;
			MEMU.SYS_RAM[entry].CERR_ADDR.R = address;
			MEMU.SYS_RAM[entry].CERR_STS.B.VLD = 0x1;
		}
		break;
	case MENU_PERIPHERAL_RAM:
		break;
	case MEMU_FLASH_MEMORY:
		break;
	}
}

/**
 * @brief   			Get error block.
 *
 * @param[in] err_block	The error block containing the fault catched.
 *                      Not all ECC units provide a syndrome. If an ECC unit does not 
 *                      provide the syndrome, 0xFFis stored in the MEMU error table instead of the syndrome.
 *
 * @api
 */
void memu_get_error(memu_error_block_t *err_block) {
	uint8_t i;
	
	err_block->error = MEMU_NO_ERROR;
	err_block->type = MEMU_SYSTEM_RAM;
	err_block->correctable = MEMU_UNCORRECTABLE_ENTRY;
	err_block->debug = 0x0U;

	if (MEMU.DEBUG.R != 0x0U) {
		err_block->debug = 0x1U;
		err_block->error = MEMU_ERROR_DETECTED;
	}

	// Check for un/correctable System RAM, Peripheral or Flash fault
	if (MEMU.ERR_FLAG.R & 0x181818UL) {
		err_block->error = MEMU_ERROR_DETECTED;
		if (MEMU.ERR_FLAG.R & 0x180000UL) {
			// Peripheral fault
			err_block->type = MENU_PERIPHERAL_RAM;
			if (MEMU.ERR_FLAG.R & 0x100000UL) {
				err_block->correctable = MEMU_CORRECTABLE_ENTRY;
				for (i = 0; i < MENU_PERIPHERAL_RAM_ENTRIES; i++)
					if (MEMU.PERIPH_RAM[i].CERR_STS.B.VLD == 0) {
						err_block->addresses[i] = MEMU.PERIPH_RAM[i].CERR_ADDR.R;
						err_block->badbits[i] = MEMU.PERIPH_RAM[i].CERR_STS.B.BAD_BIT;
					}
			} else {
				err_block->addresses[0U] = MEMU.PERIPH_RAM[0U].CERR_ADDR.R;
				err_block->badbits[0U] = MEMU.PERIPH_RAM[0U].CERR_STS.B.BAD_BIT;
			}
		}
		if (MEMU.ERR_FLAG.R & 0x001800UL) {
			// Flash fault
			err_block->type = MEMU_FLASH_MEMORY;
			if (MEMU.ERR_FLAG.R & 0x001000UL) {
				err_block->correctable = MEMU_CORRECTABLE_ENTRY;
				for (i = 0; i < MEMU_FLASH_MEMORY_ENTRIES; i++)
					if (MEMU.FLASH[i].CERR_STS.B.VLD == 0) {
						err_block->addresses[i] = MEMU.FLASH[i].CERR_ADDR.R;
						err_block->badbits[i] = MEMU.FLASH[i].CERR_STS.B.BAD_BIT;
					}
			} else {
				err_block->addresses[0U] = MEMU.FLASH[0U].CERR_ADDR.R;
				err_block->badbits[0U] = MEMU.FLASH[0U].CERR_STS.B.BAD_BIT;
			}
		}
		if (MEMU.ERR_FLAG.R & 0x000018UL) {
			// System RAM fault
			if (MEMU.ERR_FLAG.R & 0x000010UL) {
				err_block->correctable = MEMU_CORRECTABLE_ENTRY;
				for (i = 0; i < MEMU_SYSTEM_RAM_ENTRIES; i++)
					if (MEMU.FLASH[i].CERR_STS.B.VLD == 0) {
						err_block->addresses[i] = MEMU.SYS_RAM[i].CERR_ADDR.R;
						err_block->badbits[i] = MEMU.SYS_RAM[i].CERR_STS.B.BAD_BIT;
					}
			} else {
				err_block->addresses[0U] = MEMU.SYS_RAM[0U].CERR_ADDR.R;
				err_block->badbits[0U] = MEMU.SYS_RAM[0U].CERR_STS.B.BAD_BIT;
			}
		}
	}
	// Check for overflow faults
	if (MEMU.ERR_FLAG.R & 0x060606UL) {
		err_block->error = MEMU_OVERFLOW_ERROR;
		if (MEMU.ERR_FLAG.R & 0x060000UL) {
			err_block->type = MENU_PERIPHERAL_RAM;
			if (MEMU.ERR_FLAG.R & 0x040000UL)
				err_block->correctable = MEMU_CORRECTABLE_ENTRY;
		}
		if (MEMU.ERR_FLAG.R & 0x000600UL) {
			err_block->type = MEMU_FLASH_MEMORY;
			if (MEMU.ERR_FLAG.R & 0x000400UL)
				err_block->correctable = MEMU_CORRECTABLE_ENTRY;
		}
		if (MEMU.ERR_FLAG.R & 0x000006UL) {
			if (MEMU.ERR_FLAG.R & 0x000004UL)
				err_block->correctable = MEMU_CORRECTABLE_ENTRY;
		}
	}
	// Check for buffer overflow
	if (MEMU.ERR_FLAG.R & 0x010101UL) {
		err_block->error = MEMU_BUFFER_OVERFLOW_ERROR;
		if (MEMU.ERR_FLAG.R & 0x010000UL) {
			err_block->type = MENU_PERIPHERAL_RAM;
		}
		if (MEMU.ERR_FLAG.R & 0x000100UL) {
			err_block->type = MEMU_FLASH_MEMORY;
		}
	}
}

/**
 * @brief   			Clear error status flag.
 *
 * @param[in] err_block	The error block containing the fault catched to be clear.
 *
 * @api
 */
void memu_clear_error(memu_error_block_t *err_block) {
	switch (err_block->type) {
	case MEMU_SYSTEM_RAM:
		switch (err_block->error) {
		case MEMU_ERROR_DETECTED:
			if (err_block->correctable == MEMU_CORRECTABLE_ENTRY)
				MEMU.ERR_FLAG.B.SR_CE = 0x1;
			else
				MEMU.ERR_FLAG.B.SR_UCE = 0x1;
			break;
		case MEMU_OVERFLOW_ERROR:
			if (err_block->correctable == MEMU_CORRECTABLE_ENTRY)
				MEMU.ERR_FLAG.B.SR_CEO = 0x1;
			else
				MEMU.ERR_FLAG.B.SR_UCO = 0x1;
			memu_invalidate_table(MEMU_SYSTEM_RAM);
			break;
		case MEMU_BUFFER_OVERFLOW_ERROR:
			MEMU.ERR_FLAG.B.SR_EBO = 0x1;
			break;
		case MEMU_NO_ERROR:
			return;
		}
		break;
	case MENU_PERIPHERAL_RAM:
		break;
	case MEMU_FLASH_MEMORY:
		break;
	}
}

/**
 * @brief	Debug connection between MEMU & FCCU.
 *
 * @param[in] todo True if you want to test the connection and False
 *                 to stop fault propagation.
 *
 * @note 	This is only for debugging and it's a risk to use it if
 *          FCCU and MENU aren't properly programmed.
 *          
 * @api
 */
void memu_check_connection(void) {
	uint8_t i, j;

	// Only System RAM Correctable fault is tested for now.
	for (i = MEMU_SYSTEM_RAM; i <= MEMU_SYSTEM_RAM; i++) {
		for (j = 2U; j < 5U; j++) {
			while(MEMU.DEBUG.R != 0x0U) {}
			MEMU.DEBUG.R = 1U << ((i * 8U) + j);
		}
	}
}

void memu_clear_connection(void) {
	MEMU.DEBUG.R = 0x0U;
	return;
}
/**
 * @brief	Reset MEMU modules at all.
 *
 * @api
 */
void memu_reset(void) {
	uint8_t i;

	/* The reporting tables must be cleared specifically */
	memu_invalidate_table(MEMU_SYSTEM_RAM);
	memu_invalidate_table(MENU_PERIPHERAL_RAM);
	memu_invalidate_table(MEMU_FLASH_MEMORY);
	// Clear overflow flags
	for (i = 0U; i < sizeof(MEMU.SYS_RAM_OFLW)/sizeof(uint32_t); i++) {
		MEMU.SYS_RAM_OFLW[i].R = 0xffffffffU;
	}
	MEMU.PERIPH_RAM_OFLW[0].R = 0xffffffffU;
	MEMU.FLASH_OFLW[0].R  = 0xffffffffU;
	// Clear status flags
	MEMU.CTRL.B.SWR = 0x1U;
}

#endif /* LLD_USE_MEMU */
/** @} */
