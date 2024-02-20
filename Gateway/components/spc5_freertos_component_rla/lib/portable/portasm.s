/*
;
;    FreeRTOS V7.3.0 - Copyright (C) 2012 Real Time Engineers Ltd.
;
;    FEATURES AND PORTS ARE ADDED TO FREERTOS ALL THE TIME.  PLEASE VISIT
;    http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.
;
;    ***************************************************************************
;     *                                                                       *
;     *    FreeRTOS tutorial books are available in pdf and paperback.        *
;     *    Complete, revised, and edited pdf reference manuals are also       *
;     *    available.                                                         *
;     *                                                                       *
;     *    Purchasing FreeRTOS documentation will not only help you, by       *
;     *    ensuring you get running as quickly as possible and with an        *
;     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
;     *    the FreeRTOS project to continue with its mission of providing     *
;     *    professional grade, cross platform, de facto standard solutions    *
;     *    for microcontrollers - completely free of charge!                  *
;     *                                                                       *
;     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
;     *                                                                       *
;     *    Thank you for using FreeRTOS, and thank you for your support!      *
;     *                                                                       *
;    ***************************************************************************
;
;
;    This file is part of the FreeRTOS distribution.
;
;    FreeRTOS is free software; you can redistribute it and/or modify it under
;    the terms of the GNU General Public License (version 2) as published by the
;    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
;    >>>NOTE<<< The modification to the GPL is included to allow you to
;    distribute a combined work that includes FreeRTOS without being obliged to
;    provide the source code for proprietary components outside of the FreeRTOS
;    kernel.  FreeRTOS is distributed in the hope that it will be useful, but
;    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
;    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
;    more details. You should have received a copy of the GNU General Public
;    License and the FreeRTOS license exception along with FreeRTOS; if not it
;    can be viewed here: http://www.freertos.org/a00114.html and also obtained
;    by writing to Richard Barry, contact details for whom are available on the
;    FreeRTOS WEB site.
;
;    1 tab == 4 spaces!
;
;    ***************************************************************************
;     *                                                                       *
;     *    Having a problem?  Start by reading the FAQ "My application does   *
;     *    not run, what could be wrong?"                                     *
;     *                                                                       *
;     *    http://www.FreeRTOS.org/FAQHelp.html                               *
;     *                                                                       *
;    ***************************************************************************
;
;
;    http://www.FreeRTOS.org - Documentation, training, latest versions, license
;    and contact details.
;
;    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
;    including FreeRTOS+Trace - an indispensable productivity tool.
;
;    Real Time Engineers ltd license FreeRTOS to High Integrity Systems, who sell
;    the code with commercial support, indemnification, and middleware, under
;    the OpenRTOS brand: http://www.OpenRTOS.com.  High Integrity Systems also
;    provide a safety engineered and independently SIL3 certified version under
;    the SafeRTOS brand: http://www.SafeRTOS.com.
;
;
; (C) Copyright 2013
; Promwad Innovation Company <www.promwad.com>
*/
/*
 *
 THIS PORTING IS WORKING FOR VLE ONLY !!!!!
 *
 */
#define _FROM_ASM_
#include "FreeRTOSConfig.h"
#include "platform.h"
#include "boot.h"
#include "osal_cfg.h"

/*
 * This is a temporary work around to fix core definition on siongle core devices.
 * On single core devices the boot core is CORE_0 but in boot.s the IVOR definition
 * used are without "C0_" prefix. This causes an isse.
 * To avoid to modify also boot.c a simple workaround is to redifine, just for this
 * file. the configUSE_CORE_x defines.
 *
 * TODO: fix this issue by redifining appropriately CORE IVORs defines.
 */
#if (configUSE_CORE_0 == 1) && (configUSE_CORE_1 == 0) && (configUSE_CORE_2 == 0)
#undef configUSE_CORE_0
#define configUSE_CORE_0                     0

#undef configUSE_CORE_1
#define configUSE_CORE_1                     0

#undef configUSE_CORE_2
#define configUSE_CORE_2                     1
#endif


/*
    .vle

    .extern vTaskSwitchContext
    .extern vTaskIncrementTick
    .extern vPortISRHandler
    .extern timer
*/
    .global pxCurrentTCB
/*
    .global vPortYield
    .global vPortTickISR
    .global vPortISRHandler
    .global vPortStartFirstTask
*/

/*
--- Stack frame layout ---------------------------
  32 bytes  | Reserved area (may used by compiler)
--------------------------------------------------
   4 bytes  | MSR
    ...     | SRR0
            | SRR1
 128 bytes  | R0 - R31
   4 bytes  | CR
            | LR
            | CTR
            | XER
--- Total: 32 + 156 ------------------------------
*/
    .equ CONTEXT_SIZE, 156

/* context switch macro */
.macro portSAVE_CONTEXT
    e_addi    r1, r1, -CONTEXT_SIZE

    /* saving R0-R31 */
    e_stmw    r0, 12(r1)

    /* saving MSR */
    mfmsr     r0
    e_stw     r0, 0(r1)

    /* saving SRR0, SRR1 */
    mfspr     r0,  SRR0
    e_stw     r0, 4(r1)
    mfspr     r0,  SRR1
    e_stw     r0, 8(r1)

    e_addi    r1, r1, 12 + 128

    /* saving CR, LR, CTR, XER */
    e_stmvsprw 0(r1)

    e_addi    r1, r1, 16
    e_addi    r1, r1, -CONTEXT_SIZE - 32

    /* get the address of the TCB */
    e_lis     r11, pxCurrentTCB@h
    e_or2i    r11, pxCurrentTCB@l
    /* get pxTopOfStack address */
    e_lwz     r11, 0(r11)
    /* store the stack pointer into the TCB */
    e_stw     r1,  0(r11)
.endm

/* context switch macro */
.macro portRESTORE_CONTEXT
    /* get the address of the TCB */
    e_lis     r11, pxCurrentTCB@h
    e_or2i    r11, pxCurrentTCB@l

    /* get the task stack pointer from the TCB */
    e_lwz     r11, 0(r11)
    /* get pxTopOfStack address */
    e_lwz     r1,  0(r11)
    /* reserved stack area offset */
    e_addi    r1,  r1, 32

    /* correct pxTopOfStack value. It allows nested context switchings */
    e_lwz     r2,  0(r11)
    e_addi    r2,  r2, CONTEXT_SIZE + 32
    e_stw     r2,  0(r11)

    /* MSR restoring */
    e_lwz     r0,  0(r1)
    mtmsr     r0

    /* SRR0, SRR1 restoring */
    e_lwz     r0,  4(r1)
    mtspr     SRR0,r0
    e_lwz     r0,  8(r1)
    mtspr     SRR1,r0

    e_addi    r1,  r1, 12

    /* restoring R2-R31, R0 */
    e_lmw     r2,  8(r1)
    e_lwz     r0,  0(r1)
    e_addi    r1,  r1, 128

    /* restoring CR, LR, CTR, XER */
    e_lmvsprw 0(r1)

    /* restoring R1 */
    e_addi    r1,  r1, 16
.endm

 /* Context save.*/
.macro SAVE_CONTEXT
    e_stwu      sp, -80(sp)             /* Size of the extctx structure.*/
    e_stmvsrrw  8(sp)                   /* Saves PC, MSR (SRR0, SRR1).  */
    e_stmvsprw  16(sp)                  /* Saves CR, LR, CTR, XER.      */
    e_stmvgprw  32(sp)                  /* Saves GPR0, GPR3...GPR12.    */
.endm

/* Context restore.*/
.macro RESTORE_CONTEXT
    e_lmvgprw   32(sp)                  /* Restores GPR0, GPR3...GPR12.  */
    e_lmvsprw   16(sp)                  /* Restores CR, LR, CTR, XER.    */
    e_lmvsrrw   8(sp)                   /* Restores PC, MSR (SRR0, SRR1).*/
    e_addi      sp, sp, 80              /* Back to the previous frame.   */
.endm

    .section  .handlers, "axv"

_VLE


#if (CORE_SUPPORTS_DECREMENTER == 1)
/*****************************************************************************/
/* Function: _IVOR10                                                         */
/* Core:      CORE_2                                                         */
/*****************************************************************************/
    .align    4
    .globl    _IVOR10
    .type     _IVOR10, @function
_IVOR10:
    portSAVE_CONTEXT

    /* Reset DIE bit in TSR register */
    e_lis     %r3, 0x0800          /* DIS bit mask */
    mtspr     336, %r3             /* TSR register */

#ifndef _SPC570Sxx_
    /* Restoring pre-IRQ MSR register value */
    mfSRR1    %r0

    /* No preemption, keeping EE disabled */
    se_bclri  %r0, 16              /* EE = bit 16 */
    mtMSR     %r0
#endif

    portRESTORE_CONTEXT

    se_rfi

#if (BOOT_CORE0 == 1)
/*****************************************************************************/
/* Function: _IVOR10                                                         */
/* Core:      CORE_0                                                         */
/*****************************************************************************/
    .align    4
    .globl    _C0_IVOR10
    .type     _C0_IVOR10, @function
_C0_IVOR10:
    portSAVE_CONTEXT

    /* Reset DIE bit in TSR register */
    e_lis     %r3, 0x0800          /* DIS bit mask */
    mtspr     336, %r3             /* TSR register */

#ifndef _SPC570Sxx_
    /* Restoring pre-IRQ MSR register value */
    mfSRR1    %r0

    /* No preemption, keeping EE disabled */
    se_bclri  %r0, 16              /* EE = bit 16 */
    mtMSR     %r0
#endif

    portRESTORE_CONTEXT

    se_rfi
#endif /* BOOT_CORE0 */
#endif /* CORE_SUPPORTS_DECREMENTER */


/*****************************************************************************/
/* Function: _IVOR8                                                          */
/* Core:      CORE_2                                                         */
/*****************************************************************************/
    .align    4
    .globl    _IVOR8
    .type     _IVOR8, @function
_IVOR8:
/* vPortYield: */

#if (configUSE_CORE_2 == 1)
    portSAVE_CONTEXT

    e_bl      vTaskSwitchContext

    portRESTORE_CONTEXT
#else
    SAVE_CONTEXT
    RESTORE_CONTEXT
#endif /* configUSE_CORE_2 */

    se_rfi

#if (BOOT_CORE0 == 1)
/*****************************************************************************/
/* Function: _IVOR8                                                          */
/* Core:      CORE_0                                                         */
/*****************************************************************************/
    .align    4
    .globl    _C0_IVOR8
    .type     _C0_IVOR8, @function
_C0_IVOR8:

#if (configUSE_CORE_0 == 1)
    portSAVE_CONTEXT

    e_bl      vTaskSwitchContext

    portRESTORE_CONTEXT
#else
    SAVE_CONTEXT
    RESTORE_CONTEXT
#endif /* configUSE_CORE_0 */

    se_rfi
#endif /* BOOT_CORE0 */

/*****************************************************************************/
/* Function: _IVOR4                                                          */
/* Core:      CORE_2                                                         */
/*****************************************************************************/
    .align    4
    .globl    _IVOR4
    .type     _IVOR4, @function
_IVOR4:
/* vPortISRHandler: */

#if (configUSE_CORE_2 == 1)
    portSAVE_CONTEXT

    e_lis     r3,  INTC_IACKR_BASE@h
    e_or2i    r3,  INTC_IACKR_BASE@l
    e_lwz     r3,  0(r3)           /* load the base adress of Vector Table */
    e_lwz     r3,  0(r3)
    mtctr     r3                   /* load ISR handler in CTR */

    /* Restoring pre-IRQ MSR register value.*/
    mfSRR1    %r0
    /* No preemption, keeping EE disabled.*/
    se_bclri  %r0, 16              /* EE = bit 16 */
    mtMSR     %r0

#if (OSAL_ENABLE_IRQ_PREEMPTION == 1)
    wrteei    1
#endif /* OSAL_ENABLE_IRQ_PREEMPTION */

    se_bctrl                       /* branch to handler */

#if (OSAL_ENABLE_IRQ_PREEMPTION == 1)
    wrteei    0
#endif /* OSAL_ENABLE_IRQ_PREEMPTION */

    mbar      0                    /* complete all pending operations */
    e_lis     r3,  INTC_EOIR_BASE@h
    e_or2i    r3,  INTC_EOIR_BASE@l
    e_stw     r3,  0(r3)           /* write 0 to INTC_EOIR_BASE */

    portRESTORE_CONTEXT
#else
    SAVE_CONTEXT

    /* Software vector address from the INTC register.*/
    e_lis       %r3, HI(INTC_IACKR_BASE_0) /*IACKR register address.    */
    e_or2i      %r3, LO(INTC_IACKR_BASE_0)
    se_lwz      %r3, 0(%r3)             /* IACKR register value.        */
    se_lwz      %r3, 0(%r3)
    se_mtCTR    %r3                     /* Software handler address.    */

    /* Restoring pre-IRQ MSR register value.*/
    mfSRR1      %r0
    /* No preemption, keeping EE disabled.*/
    se_bclri    %r0, 16                 /* EE = bit 16.                 */
    mtMSR       %r0

#if (OSAL_ENABLE_IRQ_PREEMPTION == TRUE)
    /* Allows preemption while executing the software handler.*/
    wrteei      1
#endif /* OSAL_ENABLE_IRQ_PREEMPTION */

    /* Executes the software handler.*/
    se_bctrl

#if (OSAL_ENABLE_IRQ_PREEMPTION == TRUE)
    /* Prevents preemption again.*/
    wrteei      0
#endif /* OSAL_ENABLE_IRQ_PREEMPTION */

    /* Informs the INTC that the interrupt has been served.*/
    mbar        0
    e_lis       %r3, HI(INTC_EOIR_BASE_0)
    e_or2i      %r3, LO(INTC_EOIR_BASE_0)
    se_stw      %r3, 0(%r3)             /* Writing any value should do. */

    RESTORE_CONTEXT
#endif /* configUSE_CORE_2 */

    se_rfi


#if (BOOT_CORE0 == 1)
/*****************************************************************************/
/* Function: _IVOR4                                                          */
/* Core:      CORE_0                                                         */
/*****************************************************************************/
    .align      4
    .globl      _C0_IVOR4
    .type       _C0_IVOR4, @function
_C0_IVOR4:

#if (configUSE_CORE_0 == 1)
/* vPortISRHandler: */

    portSAVE_CONTEXT

    e_lis     r3,  INTC_IACKR_BASE@h
    e_or2i    r3,  INTC_IACKR_BASE@l
    e_lwz     r3,  0(r3)           /* load the base adress of Vector Table */
    e_lwz     r3,  0(r3)
    mtctr     r3                   /* load ISR handler in CTR */

    /* Restoring pre-IRQ MSR register value.*/
    mfSRR1    %r0
    /* No preemption, keeping EE disabled.*/
    se_bclri  %r0, 16              /* EE = bit 16 */
    mtMSR     %r0

#if (OSAL_ENABLE_IRQ_PREEMPTION == 1)
    wrteei    1
#endif /* OSAL_ENABLE_IRQ_PREEMPTION */

    se_bctrl                       /* branch to handler */

#if (OSAL_ENABLE_IRQ_PREEMPTION == 1)
    wrteei    0
#endif /* OSAL_ENABLE_IRQ_PREEMPTION */

    mbar      0                    /* complete all pending operations */
    e_lis     r3,  INTC_EOIR_BASE@h
    e_or2i    r3,  INTC_EOIR_BASE@l
    e_stw     r3,  0(r3)           /* write 0 to INTC_EOIR_BASE */

    portRESTORE_CONTEXT
#else
    SAVE_CONTEXT

    /* Software vector address from the INTC register.*/
    e_lis       %r3, HI(INTC_IACKR_BASE_0) /*IACKR register address.    */
    e_or2i      %r3, LO(INTC_IACKR_BASE_0)
    se_lwz      %r3, 0(%r3)             /* IACKR register value.        */
    se_lwz      %r3, 0(%r3)
    se_mtCTR    %r3                     /* Software handler address.    */

    /* Restoring pre-IRQ MSR register value.*/
    mfSRR1      %r0
    /* No preemption, keeping EE disabled.*/
    se_bclri    %r0, 16                 /* EE = bit 16.                 */
    mtMSR       %r0

#if (OSAL_ENABLE_IRQ_PREEMPTION == TRUE)
    /* Allows preemption while executing the software handler.*/
    wrteei      1
#endif /* OSAL_ENABLE_IRQ_PREEMPTION */

    /* Executes the software handler.*/
    se_bctrl

#if (OSAL_ENABLE_IRQ_PREEMPTION == TRUE)
    /* Prevents preemption again.*/
    wrteei      0
#endif /* OSAL_ENABLE_IRQ_PREEMPTION */

    /* Informs the INTC that the interrupt has been served.*/
    mbar        0
    e_lis       %r3, HI(INTC_EOIR_BASE_0)
    e_or2i      %r3, LO(INTC_EOIR_BASE_0)
    se_stw      %r3, 0(%r3)             /* Writing any value should do. */

    RESTORE_CONTEXT
#endif /* configUSE_CORE_0 */

        se_rfi
#endif /* BOOT_CORE0 */

/*****************************************************************************/
/* Function: vPortStartFirstTask                                             */
/* Core:     The core running FreeRTOS                                       */
/*****************************************************************************/
    .align    4
    .globl    vPortStartFirstTask
    .type     vPortStartFirstTask, @function
vPortStartFirstTask: 

    portRESTORE_CONTEXT

    /* Return into the first task */
    se_rfi

/*****************************************************************************/
/* Function: _spr_init                                                       */
/* Core:     The core booting FreeRTOS                                       */
/*****************************************************************************/
#if CORE_SUPPORTS_IVORS
    .align    4
    .globl    _spr_init
    .type     _spr_init, @function
_spr_init:

    e_lis     %r3, HI(_IVOR4)
    e_or2i    %r3, LO(_IVOR4)
    mtIVOR4   %r3
    e_lis     %r3, HI(_IVOR8)
    e_or2i    %r3, LO(_IVOR8)
    mtIVOR8   %r3
#if (CORE_SUPPORTS_DECREMENTER == 1)
    e_lis     %r3, HI(_IVOR10)
    e_or2i    %r3, LO(_IVOR10)
    mtIVOR10  %r3
#endif /* CORE_SUPPORTS_DECREMENTER */

    se_blr
#endif /* CORE_SUPPORTS_IVORS */

    /* end of assembler code */
    .end
