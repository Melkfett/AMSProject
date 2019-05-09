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

void testfunc1()
{
	UARTTransmitByte('B');
}

void testfunc2()
{
	UARTTransmitByte('A');
}

int main(void)
{
    /* Replace with your application code */
	UARTSetup();
	RTSInit();
	
	task_t test_task1;
	test_task1.task_cbf = testfunc1;
	test_task1.ticks = 1000;
	RTSAddTask(&test_task1);
	
	task_t test_task2;
	test_task2.task_cbf = testfunc2;
	test_task2.ticks = 1000;
	RTSAddTask(&test_task2);
	
	_delay_ms(1000);
	sei();
	RTSRun();
	
	while (1)
	{

	_delay_ms(10000);

	uint8_t msg1 = 'A';

	UARTTransmitByte(msg1);

	uint8_t msg2 = '\n';

	UARTTransmitByte(msg2);

	UARTTransmitByte(msg1);

    }
}

