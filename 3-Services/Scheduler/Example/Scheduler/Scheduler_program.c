/**
* @file    Scheduler_program.c
* @brief   Brief description of the file
* @author  Eng. Mohamed Yousry
* @date    2024-03-08
* @copyright Copyright (c) 2025 Mohamed Yousry. See LICENSE for details.
* 
* Detailed description of the file (optional).
* Can include information about the project, overall purpose,
* or specific components contained in the file.
*/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

/* MCAL */
#include "../TIMER/Timer_interface.h"

/* Services */
#include "Scheduler_interface.h"
#include "Scheduler_private.h"
#include "Scheduler_config.h"

/* Array of TCBs for each task has one struct*/
Scheduler_TCB Scheduler_ArrayStrTasks[SCHEDULER_MAX_NUMBER_TASKS]; //Array of Struct("Scheduler_TCB" created in private file) of size of maxuimim number of tasks
 
void Scheduler_voidInit(void)
{
	/*Set Call Back Function for Timer0 to call the Scheduler */
	TIMER0_u8SetCallBack(&Scheduler_voidStartScheduler);
	TIMER0_voidSetCompMatchValue(199);
	/*Start Timer*/
	TIMER0_voidInit();
}

u8 	 Scheduler_u8CreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay,void (*Copy_pf)(void))
{
	u8 Local_u8ErrorState = NOK;
	if((Copy_u8Priority < SCHEDULER_MAX_NUMBER_TASKS) && (Copy_pf != NULL))
	{
		Scheduler_ArrayStrTasks[Copy_u8Priority].FirstDelay 	= Copy_u16FirstDelay;
		Scheduler_ArrayStrTasks[Copy_u8Priority].Periodicity 	= Copy_u16Periodicity;
		Scheduler_ArrayStrTasks[Copy_u8Priority].pf			 	= Copy_pf;
		Local_u8ErrorState = OK;
	}
	return Local_u8ErrorState;
}

static void Scheduler_voidStartScheduler(void)
{
	/* For loop to loop on the Ready Tasks */
	u8 u8Counter;
	for(u8Counter = 0; u8Counter < SCHEDULER_MAX_NUMBER_TASKS; u8Counter++)
	{
		if(Scheduler_ArrayStrTasks[u8Counter].FirstDelay == 0)
		{
			/* It's time to call this Task cause it's ready*/
			Scheduler_ArrayStrTasks[u8Counter].pf();
			/* Update for the first delay value with the periodicity so next time it would run it the proper tick*/
			Scheduler_ArrayStrTasks[u8Counter].FirstDelay = Scheduler_ArrayStrTasks[u8Counter].Periodicity - 1;
		}
		else
		{
			/* It's not time to call this Task as it's not ready*/
			Scheduler_ArrayStrTasks[u8Counter].FirstDelay--;
		}
	}
}