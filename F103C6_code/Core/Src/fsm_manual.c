/*
 * fsm_manual.c
 *
 *  Created on: Nov 1, 2024
 *      Author: PC
 */

#include "fsm_manual.h"

#define CYCLE_TIME 200

void fsm_manual(){
	switch(status){
		case MAN_GREEN_RED:
			setTimer(1, CYCLE_TIME);
			toggle_led_red();
			status = MAN_MODE_2;
			update_segment_buffer(red_time, MAN_MODE_2-20);
			break;
		case MAN_MODE_2:
			// blink led
			if(getTimerFlag(1)){
				toggle_led_red();
				setTimer(1, CYCLE_TIME);
			}

			// if button1 or button2 is pressed -> refresh timeout
			if(get_pressed_flag(0) || get_pressed_flag(1)){ // button 1 is pressed
				setTimer(2, FSM_MANUAL_TIMEOUT); // reset timeout for man_fsm
			}

			//handle:
					//button 1: change mode
			if(get_pressed_flag(0)){
				status = MAN_MODE_3;
				toggle_led_yellow();
				set_pressed_flag(0);
			}
					//button 2: increase value LED RED
			if(get_pressed_flag(1)){
//				red_time = (red_time >= 1 && red_time <= 99) ? red_time++ : 1;
				red_time++;
				if(red_time >= 100)
					red_time = 1;
				set_pressed_flag(1);
			}
			//change segment buffer
			update_segment_buffer(red_time, MAN_MODE_2-20);
			break;
		case MAN_MODE_3:
			//blink led
			if(getTimerFlag(1)){
				toggle_led_yellow();
				setTimer(1, CYCLE_TIME);
			}
			// if button1 or button2 is pressed -> refresh timeout
			if(get_pressed_flag(0) || get_pressed_flag(1)){ // button 1 is pressed
				setTimer(2, FSM_MANUAL_TIMEOUT); // reset timeout for man_fsm
			}

			//handle:
					//button 1: change mode
			if(get_pressed_flag(0)){
				status = MAN_MODE_4;
				toggle_led_green();
				set_pressed_flag(0);
			}
					//button 2: increase value LED RED
			if(get_pressed_flag(1)){
				yellow_time++;
				if(yellow_time >= 100)
					yellow_time = 1;
				set_pressed_flag(1);
			}
			//change segment buffer
			update_segment_buffer(yellow_time, MAN_MODE_3-20);
			break;
		case MAN_MODE_4:
			//blink led
			if(getTimerFlag(1)){
				toggle_led_green();
				setTimer(1, CYCLE_TIME);
			}
			// if button1 or button2 is pressed -> refresh timeout
			if(get_pressed_flag(0) || get_pressed_flag(1)){ // button 1 is pressed
				setTimer(2, FSM_MANUAL_TIMEOUT); // reset timeout for man_fsm
			}

			//handle:
					//button 1: change mode
							/* fsm_setting() handle this task*/

					//button 2: increase value LED RED
			if(get_pressed_flag(1)){
				green_time++;
				if(green_time >= 100)
					green_time = 1;
				set_pressed_flag(1);
			}
			//change segment buffer
			update_segment_buffer(green_time, MAN_MODE_4-20);
			break;
		default:
			break;
	}


}
