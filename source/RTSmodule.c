/*
 * RTSmodule.c
 *
 * Created: 14-Mar-19 8:53:36 AM
 *  Author: fenta
 */ 

#include "../include/RTSmodule.h"

#define Success 0
#define Error  -1

static int16_t tick_countdown;

static task_t* task_queue[MAX_QUEUE_LENGTH];
static int8_t crt_queue_size = 0;

void RTSinit()
{
	//PRR0 &= 0b11110111; //Enable Timer1.
	//TCCR1A |= 0b00000011; //Put the timer in clear timer on compare match mode.
	//TCCR1B |= 0b00000100; //Prescale counting clock to 1/256.
	
	
	//PRR0 &= 0b11110111; //Enable Timer1.
	
	//Da clocken er 16 Mhz ønskes en tick til tick tid på 100 us. (1600 operationer pr. tick)

}

int8_t RTSAddTask(task_t* task_pointer)
{
	if (MAX_QUEUE_LENGTH == crt_queue_size)
		return Error;
	
	task_queue[crt_queue_size] = task_pointer;
	task_pointer->task_id = crt_queue_size;
	task_pointer->task_state = Idle;
	crt_queue_size++;
	
	
	return Success;
}

void RTSrun()
{
	//Do next job.
}

