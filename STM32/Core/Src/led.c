/*
 * led.c
 *
 *  Created on: Nov 21, 2022
 *      Author: tuanb
 */


#include "led.h"

int index_led = 0;

int tick_number[2] = {-1, -1};

void get_timer(void){
	uint32_t milisecond = HAL_GetTick();
	int tmp = (int)milisecond;
	tick_number[0] = (tmp%100)/10;
	tick_number[1] = tmp%10;
}
void update7SEG(void){
	switch (index_led){
		case 0:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			if(tick_number[0] != -1)
				display7SEG_ex(tick_number[0]);
			index_led = 1;
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			if(tick_number[1] != -1)
				display7SEG_ex(tick_number[1]);
			index_led = 0;
			break;
	}
}

void display7SEG(int num){
	HAL_GPIO_WritePin (GPIOA,a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin, GPIO_PIN_SET) ;
	switch(num){
	case 0:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin) ;
		break;
	case 1:
		HAL_GPIO_TogglePin (GPIOA,b_Pin|c_Pin) ;
		break;
	case 2:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|b_Pin|g_Pin|d_Pin|e_Pin) ;
		break;
	case 3:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|b_Pin|g_Pin|c_Pin|d_Pin) ;
		break;
	case 4:
		HAL_GPIO_TogglePin (GPIOA,f_Pin|g_Pin|b_Pin|c_Pin) ;
		break;
	case 5:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|f_Pin|g_Pin|c_Pin|d_Pin) ;
		break;
	case 6 :
		HAL_GPIO_TogglePin (GPIOA,a_Pin|f_Pin|g_Pin|e_Pin|c_Pin|d_Pin) ;
		break;
	case 7 :
		HAL_GPIO_TogglePin (GPIOA ,a_Pin|b_Pin|c_Pin ) ;
		break;
	case 8:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin) ;
		break;
	case 9:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|b_Pin|c_Pin|d_Pin|f_Pin|g_Pin) ;
		break;
	}
}

void display7SEG_ex(int num){

	HAL_GPIO_WritePin (GPIOB,a1_Pin|b1_Pin|c1_Pin|d1_Pin|e1_Pin|f1_Pin|g1_Pin, GPIO_PIN_SET) ;
	switch(num){
	case 0:
		HAL_GPIO_TogglePin (GPIOB,a1_Pin|b1_Pin|c1_Pin|d1_Pin|e1_Pin|f1_Pin) ;
		break;
	case 1:
		HAL_GPIO_TogglePin (GPIOB,b1_Pin|c1_Pin) ;
		break;
	case 2:
		HAL_GPIO_TogglePin (GPIOB,a1_Pin|b1_Pin|g1_Pin|d1_Pin|e1_Pin) ;
		break;
	case 3:
		HAL_GPIO_TogglePin (GPIOB,a1_Pin|b1_Pin|g1_Pin|c1_Pin|d1_Pin) ;
		break;
	case 4:
		HAL_GPIO_TogglePin (GPIOB,f1_Pin|g1_Pin|b1_Pin|c1_Pin) ;
		break;
	case 5:
		HAL_GPIO_TogglePin (GPIOB,a1_Pin|f1_Pin|g1_Pin|c1_Pin|d1_Pin) ;
		break;
	case 6 :
		HAL_GPIO_TogglePin (GPIOB,a1_Pin|f1_Pin|g1_Pin|e1_Pin|c1_Pin|d1_Pin) ;
		break;
	case 7 :
		HAL_GPIO_TogglePin (GPIOB ,a1_Pin|b1_Pin|c1_Pin ) ;
		break;
	case 8:
		HAL_GPIO_TogglePin (GPIOB,a1_Pin|b1_Pin|c1_Pin|d1_Pin|e1_Pin|f1_Pin|g1_Pin) ;
		break;
	case 9:
		HAL_GPIO_TogglePin (GPIOB,a1_Pin|b1_Pin|c1_Pin|d1_Pin|f1_Pin|g1_Pin) ;
		break;
	}
}
