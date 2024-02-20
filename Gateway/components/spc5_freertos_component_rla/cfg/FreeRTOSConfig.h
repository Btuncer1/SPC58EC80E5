/***********************************************************************************
*
* Copyright (c) 2015-2020 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
************************************************************************************/
/**
 * @file    FreeRTOSConfig.h
 * @brief   FreeRTOS configuration header.
 * @details FreeRTOS is customised using a configuration file called FreeRTOSConfig.h.
 *          Every FreeRTOS application must have a FreeRTOSConfig.h header file in its
 *          pre-processor include path.
 *          FreeRTOSConfig.h tailors the RTOS kernel to the application being built.
 * @addtogroup FREERTOS_CONFIG
 * @{
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H


/**
 * @name    FreeRTOS configuration
 */


/**
 * @brief   (Multicore) Set to 1 to define on which core FreeRTOS runs.
 */
#define configUSE_CORE_0                     0
#define configUSE_CORE_1                     0
#define configUSE_CORE_2                     1

/**
 * @brief   Set to 1 to use the preemptive RTOS scheduler, or 0 to use the cooperative RTOS scheduler.
 */
#define configUSE_PREEMPTION                 1

/**
 * @brief   Set to 1 to use prioritised preemptive scheduling with time slicing (configUSE_PREEMPTION must be set to 1).
 */
#define configUSE_TIME_SLICING               1

/**
 * @brief   Set the frequency in Hz at which the internal clock that drives the peripheral used to generate the tick interrupt.
 */
#define configCPU_CLOCK_HZ                   80000000

/**
 * @brief   Set the frequency of the RTOS tick interrupt.
 */
#define configTICK_RATE_HZ                   1000

/**
 * @brief   Set to 1 to cause TickType_t (tick counter type) to be defined ans an unsigned 16bit type.
 */
#define configUSE_16_BIT_TICKS               0

/**
 * @brief   The number of priorities available to the application tasks.
 */
#define configMAX_PRIORITIES                 4

/**
 * @brief   The maximum permissible length of the descriptive name given to a task when the task is created.
 */
#define configMAX_TASK_NAME_LEN              16

/**
 * @brief   This parameter controls the behaviour of tasks at the idle priority.
 */
#define configIDLE_SHOULD_YIELD              1

/**
 * @brief   The size (in words - 4 bytes each) of the stack used by the idle task.
 */
#define configMINIMAL_STACK_SIZE             256

/**
 * @brief   Enable/Disable FreeRTOS+CLI.
 */
#define configHAS_FREERTOS_CLI               0

/**
 * @brief   Enable/Disable Console prompt.
 */
#define configCLI_DISABLE_CONSOLE_PROMPT     FALSE

/**
 * @brief   Enable/Disable TCP commands.
 */
#define configCLI_USE_TCP_COMMANDS           FALSE

/**
 * @brief   Enable/Disable UDP commands.
 */
#define configCLI_USE_UDP_COMMANDS           FALSE

/**
 * @brief   Enable/Disable file commands.
 */
#define configCLI_USE_FILE_COMMANDS          FALSE

/**
 * @brief   Enable/Disable sample commands.
 */
#define configCLI_USE_SAMPLE_COMMANDS        FALSE

/*
 * Mutex and semaphores
 */
 
/**
 * @brief   Set to 1 to include mutex functionality.
 */
#define configUSE_MUTEXES                    1

/**
 * @brief   Set to 1 to include recursive mutex functionality.
 */
#define configUSE_RECURSIVE_MUTEXES          0

/**
 * @brief   Set to 1 to include counting semaphore functionality.
 */
#define configUSE_COUNTING_SEMAPHORES        0


/*
 * Co-routines
 */

/**
 * @brief   Set to 1 to include co-routine functionality.
 */
#define configUSE_CO_ROUTINES                0

/**
 * @brief   The number of priorities available to the application co-routines.
 */
#define configMAX_CO_ROUTINE_PRIORITIES      4


/*
 * Memory allocation
 */
 
/**
 * @brief   The total (in bytes) amount of RAM available in the FreeRTOS heap.
 */
#define configTOTAL_HEAP_SIZE                32768

/**
 * @brief   Set to 1 to get RTOS objects created using RAM provided by the application.
 */
#define configSUPPORT_STATIC_ALLOCATION      0

/**
 * @brief   Set to 1 to get RTOS objects created using RAM automatically allocated from the FreeRTOS heap.
 */
#define configSUPPORT_DYNAMIC_ALLOCATION     1

/**
 * @brief   Set to 1 to get the heap memory declared and allocated by the application.
 */
#define configAPPLICATION_ALLOCATED_HEAP     0

/**
 * @brief   Sets the number of indexes in each task's thread local storage array.
 */
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS	3


/*
 * Hook functions
 */

/**
 * @brief   Set to 1 to use an idle hook function [void vApplicationIdleHook(void)].
 */
#define configUSE_IDLE_HOOK                  0

/**
 * @brief   Set to 1 to use a tick hook function [void vApplicationTickHook(void)].
 */
#define configUSE_TICK_HOOK                  0

/**
 * @brief   Set to 1 to use stack check overflow functionality.
 */
#define configCHECK_FOR_STACK_OVERFLOW       0

/**
 * @brief   Set to 1 to use a malloc failed hook function [void vApplicationMallocFailedHook(void)].
 */
#define configUSE_MALLOC_FAILED_HOOK         0


/*
 * Tracing and stats
 */

#define configGENERATE_RUN_TIME_STATS        0

#define configUSE_TRACE_FACILITY             0

#define configUSE_STATS_FORMATTING_FUNCTIONS 0


/*
 * Software timers configuration
 */
#define configUSE_TIMERS                     0

#define configTIMER_TASK_PRIORITY            3
#define configTIMER_QUEUE_LENGTH             10
#define configTIMER_TASK_STACK_DEPTH         256


/*
 * Queue configuration
 */
#define configQUEUE_REGISTRY_SIZE            0

#define configUSE_QUEUE_SETS                 0


/*
 * API Configuration
 */

#define INCLUDE_vTaskPrioritySet             1

#define INCLUDE_uxTaskPriorityGet            1

#define INCLUDE_vTaskDelete                  0

#define INCLUDE_vTaskSuspend                 1

#define INCLUDE_vResumeFromISR               1

#define INCLUDE_vTaskDelayUntil              1

#define INCLUDE_vTaskDelay                   1

#define INCLUDE_xTaskGetSchedulerState       0

#define INCLUDE_xTaskGetCurrentTaskHandle    0

#define INCLUDE_uxTaskGetStackHighWaterMark  0

#define INCLUDE_xTaskGetIdleTaskHandle       0

#define INCLUDE_eTaskGetState                0

#define INCLUDE_xTaskGetHandle               0


#endif /* FREERTOS_CONFIG_H */

/** @} */
