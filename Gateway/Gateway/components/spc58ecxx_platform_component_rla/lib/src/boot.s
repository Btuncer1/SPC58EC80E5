/****************************************************************************
*
* Copyright © 2016-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/**
 * @file    boot.s
 * @brief   SPC58ECxx boot-related code.
 *
 * @addtogroup PPC_BOOT
 * @{
 */

#include "boot.h"
#include "toolchain.h"

#if !defined(__DOXYGEN__)

        /*
         * BAM record, only processor 2 is started but the table is entirely
         * populated.
         * TODO: Handle autostart for cores 0 and 1.
         */
        .section    .boot, "axv"

        .long       0x00A50001
        .long       _reset_address2 /* Core 2 reset address. */
        .long       _reset_address0 /* Core 0 reset address. */

        /*
         * Reset entry point for core0.
         */
        .align      2
        .globl      _reset_address0
        .type       _reset_address0, @function
_VLE
_reset_address0:
        e_li        %r0, 0
        mtspr       286, %r0        /* PIR register.*/

        e_bl        _regclear
        e_bl        _ram0init
        e_bl        _iv0init

        e_lis       %r3, HI(_boot_address0)
        e_or2i      %r3, LO(_boot_address0)
        mtctr       %r3
        se_bctrl

        /*
         * Reset entry point for core2.
         */
        .align      3               /* _reset_address2 must be aligned to 64 bits */ 
        .globl      _reset_address2
        .type       _reset_address2, @function
_VLE
_reset_address2:
        e_li        %r0, 2
        mtspr       286, %r0        /* PIR register.*/
		
#if BOOT_DISABLE_WATCHDOG
		e_bl		_disablewatchdog
#endif
        e_bl        _regclear
#if !BOOT_LOAD_IN_RAM
        e_bl        _sysraminit
#endif
        e_bl        _ram2init
        e_bl        _iv2init

#if BOOT_RELOCATE_IN_RAM
        /*
         * Image relocation in RAM.
         */
        e_lis       %r4, HI(__ram_reloc_start__)
        e_or2i      %r4, LO(__ram_reloc_start__)
        e_lis       %r5, HI(__ram_reloc_dest__)
        e_or2i      %r5, LO(__ram_reloc_dest__)
        e_lis       %r6, HI(__ram_reloc_end__)
        e_or2i      %r6, LO(__ram_reloc_end__)
.relloop:
_NOVLE
        cmpl        cr0, %r4, %r6
_VLE
        se_bge      .relend
        se_lwz      %r7, 0(%r4)
        se_addi     %r4, 4
        se_stw      %r7, 0(%r5)
        se_addi     %r5, 4
        se_b        .relloop
.relend:
#endif
        e_lis       %r3, HI(_boot_address)
        e_or2i      %r3, LO(_boot_address)
        mtctr       %r3
        se_bctrl
        
        /*
         * Default boot addresses, are overriden by the startup code.
         */
        .align      2
        .weak       _boot_address0
_boot_address0:
        .weak       _boot_address
_boot_address:
.noboot:
        se_b        .noboot

		/*
         * Disable Software Watchdogs.
         */
_disablewatchdog:
		/* Disable SWT_0 */
        e_lis       r4, 0xF405
        e_or2i      r4, 0x0000
        e_li        r3, 0xC520
        e_stw       r3, 0x10(r4)
        e_li        r3, 0xD928
        e_stw       r3, 0x10(r4)
        e_lis       r3, 0xFF00
        e_or2i      r3, 0x000A
        e_stw       r3, 0(r4)

		/* SWT_1 not present */
		
		/* Disable SWT_2 */
		e_lis       r4, 0xF405
        e_or2i      r4, 0x8000
        e_li        r3, 0xC520
        e_stw       r3, 0x10(r4)
        e_li        r3, 0xD928
        e_stw       r3, 0x10(r4)
        e_lis       r3, 0xFF00
        e_or2i      r3, 0x000A
        e_stw       r3, 0(r4)
		
		/* Disable SWT_3 */
		e_lis       r4, 0xF405
        e_or2i      r4, 0xC000
        e_li        r3, 0xC520
        e_stw       r3, 0x10(r4)
        e_li        r3, 0xD928
        e_stw       r3, 0x10(r4)
        e_lis       r3, 0xFF00
        e_or2i      r3, 0x000A
        e_stw       r3, 0(r4)
		
        se_blr
		
        /*
         * Clears the internal registers of the calling core.
         */
_regclear:
        xor         %r0, %r0, %r0
        xor         %r1, %r1, %r1
        xor         %r2, %r2, %r2
        xor         %r3, %r3, %r3
        xor         %r4, %r4, %r4
        xor         %r5, %r5, %r5
        xor         %r6, %r6, %r6
        xor         %r7, %r7, %r7
        xor         %r8, %r8, %r8
        xor         %r9, %r9, %r9
        xor         %r10, %r10, %r10
        xor         %r11, %r11, %r11
        xor         %r12, %r12, %r12
        xor         %r13, %r13, %r13
        xor         %r14, %r14, %r14
        xor         %r15, %r15, %r15
        xor         %r16, %r16, %r16
        xor         %r17, %r17, %r17
        xor         %r18, %r18, %r18
        xor         %r19, %r19, %r19
        xor         %r20, %r20, %r20
        xor         %r21, %r21, %r21
        xor         %r22, %r22, %r22
        xor         %r23, %r23, %r23
        xor         %r24, %r24, %r24
        xor         %r25, %r25, %r25
        xor         %r26, %r26, %r26
        xor         %r27, %r27, %r27
        xor         %r28, %r28, %r28
        xor         %r29, %r29, %r29
        xor         %r30, %r30, %r30
        xor         %r31, %r31, %r31

        se_blr

        /*
         * System RAM clearing.
         */
        .align      2
_sysraminit:
        /* Shared RAM.*/
        e_lis       %r4, HI(__ram_start__)
        e_or2i      %r4, LO(__ram_start__)
        e_lis       %r5, HI(__ram_end__)
        e_or2i      %r5, LO(__ram_end__)
.sramclrloop:
_NOVLE
        cmpl        cr0, %r4, %r5
_VLE
        se_bge      .sramclrend
        e_stmw      %r16, 0(%r4)
        e_addi      %r4, %r4, 64
        se_b        .sramclrloop
.sramclrend:
        se_blr

        /*
         * Core 0 RAM clearing.
         */
        .align      2
_ram0init:
        /* Core 0 DRAM.*/
        e_lis       %r4, HI(__dram0_start__)
        e_or2i      %r4, LO(__dram0_start__)
        e_lis       %r5, HI(__dram0_end__)
        e_or2i      %r5, LO(__dram0_end__)
.dram0clrloop:
_NOVLE
        cmpl        cr0, %r4, %r5
_VLE
        se_bge      .dram0clrend
        e_stmw      %r16, 0(%r4)
        e_addi      %r4, %r4, 64
        se_b        .dram0clrloop
.dram0clrend:

        se_blr

        /*
         * Core 2 RAM clearing.
         */
        .align      2
_ram2init:
        /* Core 2 DRAM.*/
        e_lis       %r4, HI(__dram2_start__)
        e_or2i      %r4, LO(__dram2_start__)
        e_lis       %r5, HI(__dram2_end__)
        e_or2i      %r5, LO(__dram2_end__)
.dram2clrloop:
_NOVLE
        cmpl        cr0, %r4, %r5
_VLE
        se_bge      .dram2clrend
        e_stmw      %r16, 0(%r4)
        e_addi      %r4, %r4, 64
        se_b        .dram2clrloop
.dram2clrend:

        se_blr

        /*
         * Core 0 exception vectors initialization.
         */
        .align      2
_iv0init:
        /* IVPR initialization.*/
        e_lis       %r3, HI(__ivpr0_base__)
        e_or2i      %r3, LO(__ivpr0_base__)
        mtIVPR      %r3

        /* MSR initialization.*/
        e_lis       %r3, HI(MSR_DEFAULT)
        e_or2i      %r3, LO(MSR_DEFAULT)
        mtMSR       %r3

        se_blr

        /*
         * Core 2 exception vectors initialization.
         */
        .align      2
_iv2init:
        /* IVPR initialization.*/
        e_lis       %r3, HI(__ivpr2_base__)
        e_or2i      %r3, LO(__ivpr2_base__)
        mtIVPR      %r3

        /* MSR initialization.*/
        e_lis       %r3, HI(MSR_DEFAULT)
        e_or2i      %r3, LO(MSR_DEFAULT)
        mtMSR       %r3

        se_blr

        /*
         * Core 0 exceptions vectors.
         */
        .section    .core0_ivors, "axv"
        .globl      C0_IVORS
C0_IVORS:
        e_b         _C0_IVOR0
        .align      4
        e_b         _C0_IVOR1
        .align      4
        e_b        _C0_IVOR2
        .align      4
        e_b        _C0_IVOR3
        .align      4
        e_b        _C0_IVOR4
        .align      4
        e_b        _C0_IVOR5
        .align      4
        e_b        _C0_IVOR6
        .align      4
        e_b        _C0_IVOR7
        .align      4
        e_b        _C0_IVOR8
        .align      4
        e_b        _C0_IVOR9
        .align      4
        e_b         _C0_IVOR10
        .align      4
        e_b         _C0_IVOR11
        .align      4
        e_b         _C0_IVOR12
        .align      4
        e_b         _C0_IVOR13
        .align      4
        e_b         _C0_IVOR14
        .align      4
        e_b         _C0_IVOR15

        /*
         * Core 2 exceptions vectors.
         * Note: Names are not prefixed with C2_ in order to maintain name
         *       compatibility with single code devices.
         */
        .section    .core2_ivors, "axv"
        .globl      IVORS
IVORS:
        e_b         _IVOR0
        .align      4
        e_b         _IVOR1
        .align      4
        e_b         _IVOR2
        .align      4
        e_b         _IVOR3
        .align      4
        e_b         _IVOR4
        .align      4
        e_b         _IVOR5
        .align      4
        e_b         _IVOR6
        .align      4
        e_b         _IVOR7
        .align      4
        e_b         _IVOR8
        .align      4
        e_b         _IVOR9
        .align      4
        e_b         _IVOR10
        .align      4
        e_b         _IVOR11
        .align      4
        e_b         _IVOR12
        .align      4
        e_b         _IVOR13
        .align      4
        e_b         _IVOR14
        .align      4
        e_b         _IVOR15

        .section    .handlers, "axv"

        /*
         * Unhandled exceptions handler for core 0.
         */
        .align      2
        .weak       _C0_IVOR0,  _C0_IVOR1,  _C0_IVOR2,  _C0_IVOR3,
        .weak       _C0_IVOR4,  _C0_IVOR5,  _C0_IVOR6,  _C0_IVOR7,
        .weak       _C0_IVOR8,  _C0_IVOR9,  _C0_IVOR10, _C0_IVOR11
        .weak       _C0_IVOR12, _C0_IVOR13, _C0_IVOR14, _C0_IVOR15
        .weak       _unhandled_exception0
        .type       _unhandled_exception0, @function
_C0_IVOR0:
_C0_IVOR1:
_C0_IVOR2:
_C0_IVOR3:
_C0_IVOR5:
_C0_IVOR6:
_C0_IVOR7:
_C0_IVOR8:
_C0_IVOR9:
_C0_IVOR11:
_C0_IVOR12:
_C0_IVOR13:
_C0_IVOR14:
_C0_IVOR15:
_unhandled_exception0:
.unhandled_exception0:
        se_b        .unhandled_exception0

        /*
         * Unhandled exceptions handler for core 2.
         * Note: Names are not prefixed with C2_ in order to maintain name
         *       compatibility with single code devices.
         */
        .align      2
        .weak       _IVOR0,  _IVOR1,  _IVOR2,  _IVOR3,
        .weak       _IVOR4,  _IVOR5,  _IVOR6,  _IVOR7,
        .weak       _IVOR8,  _IVOR9,  _IVOR10, _IVOR11
        .weak       _IVOR12, _IVOR13, _IVOR14, _IVOR15
        .weak       _unhandled_exception2
        .type       _unhandled_exception2, @function
_IVOR0:
_IVOR1:
_IVOR2:
_IVOR3:
_IVOR5:
_IVOR6:
_IVOR7:
_IVOR8:
_IVOR9:
_IVOR11:
_IVOR12:
_IVOR13:
_IVOR14:
_IVOR15:
_unhandled_exception2:
.unhandled_exception2:
        se_b        .unhandled_exception2

#endif /* !defined(__DOXYGEN__) */

/** @} */
