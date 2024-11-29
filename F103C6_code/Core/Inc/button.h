/*
 * button.h
 *
 *  Created on: Oct 28, 2024
 *      Author: PC
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"



#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#define NO_OF_BUTTON 10
#define TIME_INTO_LONG_PRESS 200		//3 second
#define CYCLE_LONG_PRESS 50				// 500 ms


void getInputKey();
uint8_t get_pressed_flag(uint8_t index);
void set_pressed_flag(uint8_t index);

#endif /* INC_BUTTON_H_ */
