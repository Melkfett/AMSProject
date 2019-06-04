/*
 * distanceSafetyModule.c
 *
 * Created: 07-04-2019 18:10:57
 *  Author: frederik
 */ 

#include <stdlib.h>
#include <stdint.h>
#include "../include/sonarDriver.h"
#include "../include/UARTDriver.h"


static uint8_t alternator = 0;
static uint16_t lastReading = 0;

void runDistanceModule()
{
	{
		switch(alternator)
		{
			case 0 :
				sonarDoRangeCheckNow();
				break;
			case 1 :
				sonarRead(&lastReading);
				
				int16_t temp = (int16_t)lastReading;
					
				char buffer[13] = "Distance: ";
				uint8_t i = 0;
				
				itoa((int)temp, buffer+10, 10);
				buffer[13] = 0;
				if(temp < 100)
					buffer[13] = 0;				
				
				for(i = 0; i<13; i++)
				{
					UARTTransmitByte(buffer[i]);
				}
					UARTTransmitByte('\n');
				
				break;
			default :
				break;
		}
		if(alternator == 1)
			alternator = 0;
		else
			alternator = 1;
	}
}

//This function is used to export the last reading. Useful for testing or future modules.
uint16_t exportReading()
{
	return lastReading;
}