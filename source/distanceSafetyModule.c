/*
 * distanceSafetyModule.c
 *
 * Created: 07-04-2019 18:10:57
 *  Author: frederik
 */ 

#include <stdint.h>
#include "../include/sonarDriver.h"

static uint8_t alternator = 0;
static uint16_t lastReading = 0;

void runDistanceModule()
{
	
	//if(sonarIsReady()) //check for ongoing reading. (The thingie pin)
	{
		switch(alternator)
		{
			case 0 :
				sonarDoRangeCheckNow();
				break;
			case 1 :
				sonarRead(&lastReading);
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

//This function is used to export the last reading. Useful for testing.
uint16_t exportReading()
{
	return lastReading;
}