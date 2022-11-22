/*
 * scheduler.c
 *
 *  Created on: Nov 8, 2022
 *      Author: tuanb
 */


#include "scheduler.h"

int myindex = 0;
uint8_t SCH_Delete_Task(uint32_t taskID) {
	if (taskID < 0 || taskID >= 5) return 0;
	SCH_tasks_G[current_index_task].pTask = 0x0000;
	SCH_tasks_G[current_index_task].Delay = 0;
	SCH_tasks_G[current_index_task].Period =  0;
	SCH_tasks_G[current_index_task].RunMe = 0;
	return 1;
}

void SCH_Init(void){
	current_index_task = 0;
}

uint32_t SCH_Add_Task( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	uint32_t index = 0;
	while(SCH_tasks_G[index].pTask != 0x0000 && index < SCH_MAX_TASKS){
		index++;
	}
	if(index == SCH_MAX_TASKS) return -1;

	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = DELAY;
	SCH_tasks_G[index].Period = PERIOD;
	SCH_tasks_G[index].RunMe = 0;
	return index;
}

void SCH_Update(void){
	for(int i=0; i<SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].pTask != 0x0000){
			if(SCH_tasks_G[i].Delay == 0){
				SCH_tasks_G[i].RunMe += 1;
				if(SCH_tasks_G[i].Period > 0){
					SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				}
				myindex = i+1;
			} else {
				SCH_tasks_G[i].Delay--;
			}
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			if (SCH_tasks_G[i].Period == 0) {
				SCH_Delete_Task(i);
			}
		}
	}

}

void Task1 (void){
	get_timer();
	//HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin|LED5_Pin, SET);
	//HAL_GPIO_WritePin(GPIOA, LED1_Pin, RESET);
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);

}
void Task2 (void){
	get_timer();
	//HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin|LED5_Pin, SET);
	//HAL_GPIO_WritePin(GPIOA, LED2_Pin, RESET);
	//HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED3_Pin|LED4_Pin|LED5_Pin, SET);
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
}

void Task3 (void){
	get_timer();
	//HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin|LED5_Pin, SET);
	//HAL_GPIO_WritePin(GPIOA, LED3_Pin, RESET);
	//HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED4_Pin|LED5_Pin, SET);
	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);

}
void Task4 (void){
	get_timer();
	//HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin|LED5_Pin, SET);
	//HAL_GPIO_WritePin(GPIOA, LED4_Pin, RESET);
	//HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED5_Pin, SET);
	HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
}
void Task5 (void){
	get_timer();
	//HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin|LED5_Pin, SET);
	//HAL_GPIO_WritePin(GPIOA, LED5_Pin, RESET);
	//HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin, SET);
	HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
}

