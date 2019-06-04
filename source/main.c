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
#include <stdlib.h>
#include "../include/UARTDriver.h"
#include "../include/RTSmodule.h"
#include "../include/distanceSafetyModule.h"
#include "../include/i2cDriver.h"
#include "../include/sonarDriver.h"
#include "../include/tmp102drv.h"
#include "../include/temperatureModule.h"

int main(void)
{
    /* Replace with your application code */
	UARTSetup();
	i2cInit();
	RTSInit();
	
	task_t tempTask;
	tempTask.task_cbf = runTemperatureModule;
	tempTask.ticks = 500;
	RTSAddTask(&tempTask);

	task_t runSonar;
	runSonar.task_cbf = runDistanceModule;
	runSonar.ticks = 500;
	RTSAddTask(&runSonar);
	
	_delay_ms(1000);
	sei();
	RTSRun();
	
	while (1)
	{
    }
}

