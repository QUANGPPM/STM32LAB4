/*
 * led7_segment.h
 *
 *  Created on: Oct 28, 2024
 *      Author: PC
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_
#include "main.h"
#define SEG_ON GPIO_PIN_RESET	//because GPIO pin connect to negative pin of LED
#define SEG_OFF GPIO_PIN_SET

typedef struct{
	GPIO_TypeDef *SEG_GPIOx;
	uint16_t SEG_Pin;
}com_t;

typedef enum{
	ZERO = 0u,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE
}SEG_state;
typedef struct{
	com_t A_seg;
	com_t B_seg;
	com_t C_seg;
	com_t D_seg;
	com_t E_seg;
	com_t F_seg;
	com_t G_seg;
	SEG_state state;
}sevenSEG_ANODE_t;

extern uint8_t led_buffer[]; // thay đổi giá trị 4 segment

void init_display(GPIO_TypeDef *A_GPIOx, uint16_t A_Pin,
					GPIO_TypeDef *B_GPIOx, uint16_t B_Pin,
					GPIO_TypeDef *C_GPIOx, uint16_t C_Pin,
					GPIO_TypeDef *D_GPIOx, uint16_t D_Pin,
					GPIO_TypeDef *E_GPIOx, uint16_t E_Pin,
					GPIO_TypeDef *F_GPIOx, uint16_t F_Pin,
					GPIO_TypeDef *G_GPIOx, uint16_t G_Pin);

void update_segment_buffer(uint32_t traffic1_time, uint32_t traffic2_time);
void scan_led7_segment(void);
#endif /* INC_LED7_SEGMENT_H_ */
