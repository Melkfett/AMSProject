/*
 * RTSmodule.h
 *
 * Created: 14-Mar-19 8:57:47 AM
 *  Author: fenta
 */ 

#ifndef RTSMODULE_H_
#define RTSMODULE_H_

#include <stdint.h>

typedef enum task_states_t
{
	Idle,
	Running,
	Finished,
	Timeout
} task_states_t;

#define MAX_QUEUE_LENGTH 100

typedef struct task
{
	int8_t task_id;
	int32_t ticks;
	void (*task_cbf)(void);
	int8_t task_state;
} task_t;

void RTSInit();
int8_t RTSAddTask(task_t* task_pointer);
void RTSRun();

#endif /* RTSMODULE_H_ */