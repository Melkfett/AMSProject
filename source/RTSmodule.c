/*
 * RTSmodule.c
 *
 * Created: 14-Mar-19 8:53:36 AM
 *  Author: fenta
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../include/RTSmodule.h"
#include "../include/UARTDriver.h"

#define Success 0
#define Error  -1

static int32_t tick_countdown = 0;
static volatile task_states_t RTSTaskState = Idle;

static volatile task_t* task_queue[MAX_QUEUE_LENGTH];
static volatile int8_t crt_queue_size = 0;

ISR(TIMER1_COMPA_vect)
{
	
	/*check if the next task should be scheduled*/
	if (tick_countdown == 0)
	{
		RTSTaskState = Timeout;
		//UARTTransmitByte('I');
	}

	/*decrement the tick counter if still positive*/
	if(tick_countdown > 0)
		tick_countdown--;
		
}

//internal helper function.
static int8_t waitForTask(volatile task_t* task)
{
	//UARTTransmitByte('H');
	if(RTSTaskState == Timeout)
	{
		//Task has taken too long!
		UARTTransmitByte('E');
		
		return Error;	
	}
	
	//Avoid infinite loop lockup.
	int64_t cnt;
	for(cnt = 0; cnt < INT64_MAX; cnt++)
	{
		if(RTSTaskState == Timeout)
		{
			task->task_state = Finished;
			//UARTTransmitByte('T');	
			return Success;
		}
	}
	
	//We should never get to this point, unless the scheduler has failed.
	UARTTransmitByte('F');
	return Error;
}

static void RTSRunTask(volatile task_t* task)
{
	//Run for number of ticks corresponding to task.
	tick_countdown = task->ticks;
	task->task_state = Running;
	RTSTaskState = Running;
	
	task->task_cbf();
	
	waitForTask(task);
}

void RTSInit()
{
	TCCR1A = 0b00000000; //Put the timer in clear timer on compare match mode.
	TCCR1B = 0b00001010; //Prescale counting clock to 1/8.
	TIMSK1 |= (1<<OCIE1A);
	OCR1A = 2000;
	
	//Vi vil nu have 1000 ticks i sekundet da hz = 16MHz/8(OCRA) så ocra = ca 2000
	
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

void RTSRun()
{
	//Do next job.
	int8_t current_task = 0;

    /*run forever, current_task will be reset before exceeding task_queue_size*/
	for(current_task = 0; current_task<=crt_queue_size; current_task++)
	{
		/*if end of the queue go back to the beginning*/
		if(crt_queue_size == current_task)
		current_task = 0;

		RTSRunTask(task_queue[current_task]);
	}
}