/*
 * button.c
 *
 *  Created on: Oct 28, 2024
 *      Author: PC
 */
#include "button.h"

#define INIT 0
#define READ_BUTTON 1
#define HANDLE_SHORT_PRESS 2
#define HANDLE_LONG_PRESS 3


uint8_t KeyReg0[NO_OF_BUTTON];
uint8_t KeyReg1[NO_OF_BUTTON];
uint8_t KeyReg2[NO_OF_BUTTON];
uint8_t KeyReg3[NO_OF_BUTTON];

uint32_t timeForKeyPress[NO_OF_BUTTON];

uint8_t PressedFlag[NO_OF_BUTTON];

void get_input_button(uint8_t index, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	KeyReg0[index] = KeyReg1[index];
	KeyReg1[index] = KeyReg2[index];
	KeyReg2[index] = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

uint8_t get_pressed_flag(uint8_t index){
	return PressedFlag[index];
}
void set_pressed_flag(uint8_t index){
	PressedFlag[index] = 0;
}

void getInputKey(){
	get_input_button(0, Button1_GPIO_Port, Button1_Pin);
	get_input_button(1, Button2_GPIO_Port, Button2_Pin);
	get_input_button(2, Button3_GPIO_Port, Button3_Pin);

	int no_of_used_button = 3;

	for(uint8_t i = 0; i < no_of_used_button; i++){
		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			// xử lý nhấn nhanh
			if(KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE){
					//todo
					PressedFlag[i] = 1;
					timeForKeyPress[i] = TIME_INTO_LONG_PRESS;
				}
			}
			// xử lý nhấn lâu
			else{
				if(KeyReg2[i] == PRESSED_STATE){
					timeForKeyPress[i]--;
					if(timeForKeyPress[i] <= 0){
						//todo
						PressedFlag[i] = 1;
						timeForKeyPress[i] = CYCLE_LONG_PRESS;
					}
				}
			}
		}
	}

}
