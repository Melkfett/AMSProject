/*
 * sonarModule.c
 *
 * Created: 07-04-2019 14:41:33
 *  Author: frederik
 */ 

//Adressen er 224!!! (hex?)

#include "../include/i2cDriver.h"
#include "../include/sonarDriver.h"
#include "../include/UARTDriver.h"

void sonarRead(uint16_t* buf)
{
	uint8_t temp[2] = {0};
	
		
	i2cStart();
	i2cWrite(225);
	i2cReceive(temp, 2);
	i2cStop();

	*buf = (temp[0]<<8) | temp[1];

	

}

void sonarDoRangeCheckNow()
{
		i2cStart();
		i2cWrite(224);
		i2cWrite(81);  //Range check command byte.
		i2cStop();
}

uint8_t sonarIsReady()
{
	//TODO: Check thingie pin to check for ongoing reading! 
	
	return 1;
}