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

#ifndef _BOARD_H_
#define _BOARD_H_

#include "pal.h"

/*
 * Setup for a generic SPC58ECxx board.
 */

/*
 * Board identifiers.
 */
#define BOARD_GENERIC_SPC58ECXX
#define BOARD_NAME                  "Generic SPC58ECxx"

/*
 * Support macros.
 */
#define MSCR_IO_INDEX(port, pin)    (((port) * 16U) + (pin))

/*
 * I/O definitions.
 */
#define PIN_TX_1_0                  10U
#define PIN_RX_1_0                  11U
#define PIN_RX_4_1                  6U
#define PIN_TX_4_1                  7U

/*
 * PORT definitions.
 */
#define PORT_PIN_TX_1_0             PORT_A
#define PORT_PIN_RX_1_0             PORT_A
#define PORT_PIN_RX_4_1             PORT_F
#define PORT_PIN_TX_4_1             PORT_F

/*
 * MSCR_IO definitions.
 */
#define MSCR_IO_PIN_TX_1_0          MSCR_IO_INDEX(PORT_PIN_TX_1_0, PIN_TX_1_0)
#define MSCR_IO_PIN_RX_1_0          MSCR_IO_INDEX(PORT_PIN_RX_1_0, PIN_RX_1_0)
#define MSCR_IO_PIN_RX_4_1          MSCR_IO_INDEX(PORT_PIN_RX_4_1, PIN_RX_4_1)
#define MSCR_IO_PIN_TX_4_1          MSCR_IO_INDEX(PORT_PIN_TX_4_1, PIN_TX_4_1)

/*
 * MSCR_MUX definitions.
 */
#define MSCR_MUX_PIN_RX_1_0         246U
#define MSCR_MUX_PIN_RX_4_1         252U

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
