/*
 * global.h
 *
 *  Created on: Nov 1, 2024
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "traffic_light.h"
#include "led7_segment.h"


extern uint8_t status;

#define INIT 0
#define GREEN_RED 1
#define YELLOW_RED 2
#define RED_GREEN 3
#define RED_YELLOW 4


#define MAN_GREEN_RED 21
#define MAN_MODE_2 22
#define MAN_MODE_3 23
#define MAN_MODE_4 24

#define FSM_MANUAL_TIMEOUT 10000

extern uint32_t green_time;
extern uint32_t yellow_time;
extern uint32_t red_time;


#endif /* INC_GLOBAL_H_ */
