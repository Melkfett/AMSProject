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
#include "../include/distanceSafetyModule.h"
#include "../include/lm75.h"
#include "../include/i2cDriver.h"
#include "../include/sonarDriver.h"

void testfunc1()
{
	UARTTransmitByte('B');
}

void testfunc2()
{
	UARTTransmitByte('A');
}

void printReading()
{
	//uint8_t temp = (exportReading()>>8);
	//UARTTransmitByte(temp);
	UARTTransmitByte('A');
}

int main(void)
{
    /* Replace with your application code */
	UARTSetup();
	i2cInit();
	RTSInit();

	task_t runSonar;
	runSonar.task_cbf = runDistanceModule;
	runSonar.ticks = 500;
	RTSAddTask(&runSonar);
	
	task_t printReadingTask;
	printReadingTask.task_cbf = printReading;
	printReadingTask.ticks = 500;
	RTSAddTask(&printReadingTask);
	
	/*
	
	while(1)
	{
		_delay_ms(2100);
		sonarDoRangeCheckNow();
		
	}
	*/
	
	_delay_ms(1000);
	sei();
	RTSRun();
	
	while (1)
	{
    }
}

