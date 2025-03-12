/**
* @file    Scheduler_interface.h
* @brief   Brief description of the file
* @author  Eng. Mohamed Yousry
* @date    2024-03-08
* @copyright Copyright (c) 2025 Mohamed Yousry. See LICENSE for details.
* 
* Detailed description of the file (optional).
* Can include information about the project, overall purpose,
* or specific components contained in the file.
*/
 
#ifndef SCHEDULER_INTERFACE_H
#define SCHEDULER_INTERFACE_H

void Scheduler_voidInit(void);

u8   Scheduler_u8CreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay,void (*Copy_pf)(void));

#endif//SCHEDULER_INTERFACE_H
 