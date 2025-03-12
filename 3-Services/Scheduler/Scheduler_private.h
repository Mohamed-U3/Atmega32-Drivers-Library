/**
* @file    Scheduler_private.h
* @brief   Brief description of the file
* @author  Eng. Mohamed Yousry
* @date    2024-03-08
* @copyright Copyright (c) 2025 Mohamed Yousry. See LICENSE for details.
* 
* Detailed description of the file (optional).
* Can include information about the project, overall purpose,
* or specific components contained in the file.
*/

#ifndef SCHEDULER_PRIVATE_H
#define SCHEDULER_PRIVATE_H

typedef struct
{	u16 FirstDelay;
	u16 Periodicity;
	void (*pf)(void);
}Scheduler_TCB;

static void Scheduler_voidStartScheduler(void);

#endif//SCHEDULER_PRIVATE_H
 
 