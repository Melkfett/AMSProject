/*
 * AMSproject.c
 *
 * Created: 14-Mar-19 8:50:37 AM
 * Author : fenta
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../include/UARTDriver.h"
#include "../include/RTSmodule.h"

void testfunc()
{
	UARTTransmitByte('S');
}

int main(void)
{
    /* Replace with your application code */
	sei();
	UARTSetup();
	RTSInit();
	
	task_t test_task;
	test_task.task_cbf = testfunc;
	test_task.ticks = 10000;
	
	RTSAddTask(&test_task);
	_delay_ms(10000);
	RTSRun();
	
	while (1)
	{

	_delay_ms(10000);

	uint8_t msg1 = 'S';

	UARTTransmitByte(msg1);

	uint8_t msg2 = '\n';

	UARTTransmitByte(msg2);

	UARTTransmitByte(msg1);

    }
}

