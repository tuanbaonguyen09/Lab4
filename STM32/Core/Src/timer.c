/*
 * timer.c
 *
 *  Created on: Oct 29, 2022
 *      Author: tuanb
 */
#include "timer.h"
int count = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim){
	if(htim->Instance == TIM2){
		//timerRun();
		SCH_Update();
		if(count > 25){
			update7SEG();
			count = 0;
		}
		else
			count++;
	}
}
