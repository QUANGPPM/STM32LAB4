/*
 * traffic_light.c
 *
 *  Created on: Oct 28, 2024
 *      Author: PC
 */
#include "traffic_light.h"
#define ON	GPIO_PIN_SET
#define OFF GPIO_PIN_RESET


void display_led_traffic(uint8_t green_al, uint8_t yellow_al, uint8_t red_al,
		 	 	 	 	 uint8_t green_lf, uint8_t yellow_lf, uint8_t red_lf){
	//above and low
	HAL_GPIO_WritePin(LED_GREEN_AL_GPIO_Port, LED_GREEN_AL_Pin, green_al);
	HAL_GPIO_WritePin(LED_YELLOW_AL_GPIO_Port, LED_YELLOW_AL_Pin, yellow_al);
	HAL_GPIO_WritePin(LED_RED_AL_GPIO_Port, LED_RED_AL_Pin, red_al);
	// left and right
	HAL_GPIO_WritePin(LED_GREEN_LR_GPIO_Port, LED_GREEN_LR_Pin, green_lf);
	HAL_GPIO_WritePin(LED_YELLOW_LR_GPIO_Port, LED_YELLOW_LR_Pin, yellow_lf);
	HAL_GPIO_WritePin(LED_RED_LR_GPIO_Port, LED_RED_LR_Pin, red_lf);
}


void led_red_and_green(){

	display_led_traffic(OFF, OFF, ON,
						ON, OFF, OFF);
}

void led_red_and_yellow(){
	display_led_traffic(OFF, OFF, ON,
						OFF, ON, OFF);
}

void led_green_and_red(){
	display_led_traffic(ON, OFF, OFF,
						OFF, OFF, ON);
}

void led_yellow_and_red(){
	display_led_traffic(OFF, ON, OFF,
						OFF, OFF, ON);
}



#define HIGH 1
#define LOW 0

uint8_t toggle = HIGH;
void toggle_led_red(){
	if(toggle == HIGH){
		display_led_traffic(OFF, OFF, ON,
							OFF, OFF, ON);
		// toggle state
		toggle = LOW;
	}else{
		display_led_traffic(OFF, OFF, OFF,
							OFF, OFF, OFF);
		// toggle state
		toggle = HIGH;
	}

}
void toggle_led_yellow(){
	if(toggle == HIGH){
		display_led_traffic(OFF, ON, OFF,
							OFF, ON, OFF);
		// toggle state
		toggle = LOW;
	}else{
		display_led_traffic(OFF, OFF, OFF,
							OFF, OFF, OFF);
		// toggle state
		toggle = HIGH;
	}
}
void toggle_led_green(){
	if(toggle == HIGH){
		display_led_traffic(ON, OFF, OFF,
							ON, OFF, OFF);
		// toggle state
		toggle = LOW;
	}else{
		display_led_traffic(OFF, OFF, OFF,
							OFF, OFF, OFF);
		// toggle state
		toggle = HIGH;
	}
}



















