/*
 * Scheduler.c
 *
 *  Created on: Nov 29, 2024
 *      Author: PC
 */
#include "Scheduler.h"


// declare variable:
TaskList list;

// define functions:
void SCH_Init(){
	//add code here:
		list.head = NULL;
    list.tail = NULL;
}

void SCH_Add_Task(void (*pFunction)(),
				  uint32_t DELAY,
				  uint32_t PERIOD){
	DELAY = DELAY / TICK;
	PERIOD = PERIOD / TICK;
	// create a task
	TaskNode* newTask = (TaskNode*)malloc(sizeof(TaskNode));

	newTask->pTask = pFunction;
	newTask->Delay = DELAY;
	newTask->Period = PERIOD;
	newTask->next = NULL;

	//if there is no task -> assign new task to head
    if (list.head == NULL) {
        list.head = newTask;
        list.tail = newTask;
        return;
    }

	// if delay < head->delay -> assign new task to head and subtract delay
    if (DELAY < list.head->Delay) {
        newTask->next = list.head;
        list.head->Delay -= DELAY;
        list.head = newTask;
        return;
    }

	// so sánh thoi gian delay voi cac node
    TaskNode* current = list.head;
		DELAY -= current->Delay;
    while (current->next != NULL && DELAY >= current->next->Delay) {
        DELAY -= current->next->Delay;
        current = current->next;
    }

    newTask->next = current->next;
    if (current->next != NULL) {
        current->next->Delay -= DELAY;
    } else {
        list.tail = newTask;
    }
    current->next = newTask;
    newTask->Delay = DELAY;
}

void SCH_Update(){
	if (list.head == NULL) return;

		// neu delay > 0 => tru
	if(list.head->Delay > 0){
		list.head->Delay--;
	}
	else{
		list.head->RunMe++;
		if(list.head->Period){
				list.head->Delay = list.head->Period;
		}
	}

}

void SCH_Dispatch_Tasks(){
	// kiem tra task dau da xong chua
	if(list.head->RunMe > 0)
	{
		// do the task
		(*list.head->pTask)();
		list.head->RunMe--;

		// if one-shot task --> delete
		if(list.head->Period == 0){
			SCH_Delete_Task();
			return;
		}


		if(list.head->RunMe == 0){
			//create a new note:
			TaskNode newtask;
			newtask = (*list.head);
			// delete task at the head of list
			SCH_Delete_Task();

			// add task to List again if it has period > 0
				SCH_Add_Task(newtask.pTask, newtask.Period*TICK, newtask.Period*TICK);
		}


	}

}

void SCH_Delete_Task(){
	if(list.head == NULL)
		return;

	TaskNode* temp = list.head;
	list.head = list.head->next;
  free(temp);
	if (list.head == NULL){
		list.tail = NULL;
	}
}









