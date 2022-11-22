/*
 * scheduler.h
 *
 *  Created on: Nov 8, 2022
 *      Author: tuanb
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "global.h"

typedef struct{
	// Pointer to the task (must be a ’void(void) ’function )
	void (*pTask)(void);
	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent runs .
	uint32_t Period;
	// Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;
	//This i s a hint to solve the question below .
	uint32_t TaskID;
} sTask;
// MUST BE ADJUSTED FOR EACH NEW PROJECT

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

extern int myindex;
uint8_t current_index_task;
sTask SCH_tasks_G[SCH_MAX_TASKS];

uint8_t SCH_Delete_Task(uint32_t taskID);

void SCH_Init(void);

uint32_t SCH_Add_Task (void (*pFunction)() ,
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void Task1(void);
void Task2(void);
void Task3(void);
void Task4(void);
void Task5(void);

#endif /* INC_SCHEDULER_H_ */
