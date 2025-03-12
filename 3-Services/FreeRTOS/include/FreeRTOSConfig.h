#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

// Core settings
#define configUSE_16_BIT_TICKS          		1   // ATmega32 uses 16-bit ticks.
#define configUSE_PREEMPTION            		1
#define configCPU_CLOCK_HZ              		( ( unsigned long ) 16000000 ) // Match your clock (e.g., 16MHz).
#define configTICK_RATE_HZ              		( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES            		( 3 )
#define configMINIMAL_STACK_SIZE        		( ( unsigned short ) 85 )
#define configTOTAL_HEAP_SIZE           		( ( size_t ) ( 1024 ) ) // Adjust based on available RAM.
#define configUSE_IDLE_HOOK             		0
#define configUSE_TICK_HOOK             		0
#define configUSE_MALLOC_FAILED_HOOK    		0
#define configUSE_DAEMON_TASK_STARTUP_HOOK    	0

/* Set the following INCLUDE_* constants to 1 to incldue the named API function,
 * or 0 to exclude the named API function.  Most linkers will remove unused
 * functions even when the constant is 1. */
#define INCLUDE_vTaskPrioritySet               1
#define INCLUDE_uxTaskPriorityGet              1
#define INCLUDE_vTaskDelete                    1
#define INCLUDE_vTaskSuspend                   1
#define INCLUDE_xResumeFromISR                 1
#define INCLUDE_vTaskDelayUntil                1
#define INCLUDE_vTaskDelay                     1
#define INCLUDE_xTaskGetSchedulerState         1
#define INCLUDE_xTaskGetCurrentTaskHandle      1
#define INCLUDE_uxTaskGetStackHighWaterMark    0
#define INCLUDE_xTaskGetIdleTaskHandle         0
#define INCLUDE_eTaskGetState                  0
#define INCLUDE_xEventGroupSetBitFromISR       1
#define INCLUDE_xTimerPendFunctionCall         0
#define INCLUDE_xTaskAbortDelay                0
#define INCLUDE_xTaskGetHandle                 0
#define INCLUDE_xTaskResumeFromISR             1

// Include AVR-specific settings
#include <avr/io.h>
#include <avr/interrupt.h>

#endif // FREERTOS_CONFIG_H