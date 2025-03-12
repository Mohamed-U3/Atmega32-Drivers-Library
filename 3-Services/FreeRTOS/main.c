#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "include/FreeRTOS.h"
#include "include/task.h"

// Define LED pins (adjust based on your hardware)
#define LED1 PD0
#define LED2 PD1
#define LED3 PD2

void TaskBlink1(void *pvParameters)
{
    DDRD |= (1 << LED1);
    while (1)
	{
        PORTD ^= (1 << LED1);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Blink every 1 second
    }
}

void TaskBlink2(void *pvParameters)
{
    DDRD |= (1 << LED2);
    while (1)
	{
        PORTD ^= (1 << LED2);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Blink every 0.5 seconds
    }
}

void TaskBlink3(void *pvParameters)
{
    DDRD |= (1 << LED3);
    while (1)
	{
        PORTD ^= (1 << LED3);
        vTaskDelay(100 / portTICK_PERIOD_MS); // Blink every 0.5 seconds
    }
}

int main(void)
{
    // Create tasks
    xTaskCreate(TaskBlink1, "Blink1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(TaskBlink2, "Blink2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(TaskBlink3, "Blink3", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Start the scheduler
    vTaskStartScheduler();

    while (1) {} // Should never reach here
}