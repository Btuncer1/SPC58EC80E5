/****************************************************************************
*
* Copyright © 2016-2021 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/**
 * @file    boot.h
 * @brief   Boot parameters for the SPC58ECxx.
 * @{
 */

#ifndef _BOOT_H_
#define _BOOT_H_

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/
/*MISRA exception: this file is included from an asm file so it is not possible
  to use the U suffix*/
/*lint -e9048 */
/**
 * @name    BUCSR registers definitions
 * @{
 */
#define BUCSR_BPEN              0x00000001
#define BUCSR_BPRED_MASK        0x00000006
#define BUCSR_BPRED_0           0x00000000
#define BUCSR_BPRED_1           0x00000002
#define BUCSR_BPRED_2           0x00000004
#define BUCSR_BPRED_3           0x00000006
#define BUCSR_BALLOC_MASK       0x00000030
#define BUCSR_BALLOC_0          0x00000000
#define BUCSR_BALLOC_1          0x00000010
#define BUCSR_BALLOC_2          0x00000020
#define BUCSR_BALLOC_3          0x00000030
#define BUCSR_BALLOC_BFI        0x00000200
/** @} */

/**
 * @name   MSR register definitions
 * @{
 */
#define MSR_UCLE                0x04000000
#define MSR_SPE                 0x02000000
#define MSR_WE                  0x00040000
#define MSR_CE                  0x00020000
#define MSR_EE                  0x00008000
#define MSR_PR                  0x00004000
#define MSR_FP                  0x00002000
#define MSR_ME                  0x00001000
#define MSR_FE0                 0x00000800
#define MSR_DE                  0x00000200
#define MSR_FE1                 0x00000100
#define MSR_IS                  0x00000020
#define MSR_DS                  0x00000010
#define MSR_RI                  0x00000002
/** @} */

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*
 * BUCSR default settings.
 */
#if !defined(BUCSR_DEFAULT) || defined(__DOXYGEN__)
#define BUCSR_DEFAULT           (BUCSR_BPEN | BUCSR_BPRED_0 |               \
                                 BUCSR_BALLOC_0 | BUCSR_BALLOC_BFI)
#endif

/*
 * MSR default settings.
 */
#if !defined(MSR_DEFAULT) || defined(__DOXYGEN__)
#define MSR_DEFAULT             (MSR_SPE | MSR_WE | MSR_CE | MSR_ME)
#endif

/*
 * Boot default settings.
 */
#define BOOT_PERFORM_CORE_INIT  0

/*
 * VLE mode default settings.
 */
#define BOOT_USE_VLE            1

/*
 * Disable Watchdog at power-on.
 */
#define BOOT_DISABLE_WATCHDOG   		1

/*
 * RAM relocation flag.
 */
#define BOOT_RELOCATE_IN_RAM    0

#define BOOT_LOAD_IN_RAM        1

/*
 * Boot Core_0
 *
 * Note:
 * - Core_2 is the main core (IOP = I/O Processor).
 * - Core_0 is the secondary core
 *
 */
#define BOOT_CORE0              0

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/
/*lint +e9048 */
#endif /* _BOOT_H_ */

/** @} */
