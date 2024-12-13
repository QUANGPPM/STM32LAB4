/*
 * Scheduler.h
 *
 *  Created on: Nov 29, 2024
 *      Author: PC
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include <stdlib.h>
#include <stdint.h>
typedef struct TaskNode {
   void (*pTask)(void);
   uint32_t Delay;
   uint32_t Period;
	 uint32_t RunMe;
   struct TaskNode* next;
}TaskNode;

typedef struct {
	TaskNode* head;
	TaskNode* tail;
}TaskList;


#define TICK 10


// function
void SCH_Init(void);

void SCH_Add_Task(void (*pFunction)(),
				  uint32_t DELAY,
				  uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void SCH_Delete_Task(void);

#endif /* INC_SCHEDULER_H_ */
