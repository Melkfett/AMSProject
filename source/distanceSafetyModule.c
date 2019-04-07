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
	if(1) //TODO: Implement check for ongoing reading. (The thingie pin)
	{
		switch(alternator)
		{
			case 0 :
				sonarDoRangeCheckNow();
			case 1 :
				sonarRead(&lastReading);
		}		
	}	
}