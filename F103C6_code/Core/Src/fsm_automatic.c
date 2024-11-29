/*
 * fsm_automatic.c
 *
 *  Created on: Nov 1, 2024
 *      Author: PC
 */


#include "fsm_automatic.h"

#define DELAY 1000
uint32_t time_counter = 0;
uint32_t red_counter;

void fsm_automatic(){
	if(getTimerFlag(0)){
		switch(status){
			case INIT:
				time_counter = green_time;
				red_counter = red_time;
				update_segment_buffer(time_counter, red_counter);
				led_green_and_red();
				status = GREEN_RED;
				break;
			case GREEN_RED:
				if(1){
					led_green_and_red();
					update_segment_buffer(--time_counter, --red_counter);
				}
				if(time_counter <= 0){
					led_yellow_and_red();
					time_counter = yellow_time;
					update_segment_buffer(time_counter, red_counter);
					status = YELLOW_RED;
				}
				break;
			case YELLOW_RED:
				if(1){
					led_yellow_and_red();
					update_segment_buffer(--time_counter, --red_counter);
				}
				if(time_counter <= 0){
					led_red_and_green();
					time_counter = green_time;
					red_counter = red_time;
					update_segment_buffer(time_counter, red_counter);
					status = RED_GREEN;
				}
				break;
			case RED_GREEN:
				if(1){
					led_red_and_green();
					update_segment_buffer(--time_counter, --red_counter);
				}
				if(time_counter <= 0){
					led_red_and_yellow();
					time_counter = yellow_time;
					update_segment_buffer(time_counter, red_counter);
					status = RED_YELLOW;
				}
				break;
			case RED_YELLOW:
				if(1){
					led_red_and_yellow();
					update_segment_buffer(--time_counter, --red_counter);
				}
				if(time_counter <= 0){
					led_green_and_red();
					time_counter = green_time;
					red_counter = red_time;
					update_segment_buffer(time_counter, red_counter);
					status = GREEN_RED;
				}
				break;
			default:
				break;
		}
		setTimer(0,DELAY);
	}

}
