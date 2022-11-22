/*
 * led.h
 *
 *  Created on: Nov 21, 2022
 *      Author: tuanb
 */

#ifndef SRC_LED_H_
#define SRC_LED_H_

#include "global.h"

extern int index_led;

void get_timer(void);

void update7SEG(void);
void display7SEG(int num);
void display7SEG_ex(int num);

#endif /* SRC_LED_H_ */
