/*
 * fsm_setting.c
 *
 *  Created on: Nov 1, 2024
 *      Author: PC
 */


#include "fsm_setting.h"



void fsm_setting(){

	switch(status){
		case GREEN_RED:
		case YELLOW_RED:
		case RED_GREEN:
		case RED_YELLOW:
			if(get_pressed_flag(0)){ // button 1 is pressed
					setTimer(2, FSM_MANUAL_TIMEOUT); // set timeout for man_fsm
					status = MAN_GREEN_RED;
					set_pressed_flag(0);
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
				}
			break;
		case MAN_MODE_2:
		case MAN_MODE_3:
		case MAN_MODE_4:
			// button 3 is pressed or timeout
			if(get_pressed_flag(2) || getTimerFlag(2)){
					status = INIT;
					setTimerFlag(0, 1);
					//check valid value time:
					if(red_time != green_time + yellow_time){
						red_time = green_time + yellow_time;
					}
					set_pressed_flag(2);
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
					break;
				}

			// if status == MODE4 -> Button1 -> INIT
			if(status == MAN_MODE_4 && get_pressed_flag(0)){
				status = INIT;
				setTimerFlag(0, 1);
				set_pressed_flag(0);
				break;
			}
		default:
			break;
	}

}
