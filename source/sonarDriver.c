/*
 * sonarModule.c
 *
 * Created: 07-04-2019 14:41:33
 *  Author: frederik
 */ 

//Adressen er 224!!! (hex?)

#include "../include/i2cDriver.h"
#include "../include/sonarDriver.h"

void sonarRead(uint16_t* buf)
{
	uint8_t temp[2] = {0};

	i2cStart();
	i2cSend(225); //CHECK TO SEE IF START WAS SENT??
	i2cReceive(temp, 2);
	i2cStop();
		
	*buf = (temp[0]<<8) | temp[1];

	//TODO: Husk at checke ny data io pin!!!(Eller bare bede den l�se hver anden gang? Eller begge? Nok begge.
	//TODO: Husk at sensoren ogs� bruger tid p� at starte op (Og sender p� den pin!)
}

void sonarDoRangeCheckNow()
{
	if(1 == 1)//S�RG FOR AT CHECKE IGANGV�RENDE L�SNING PIN!!!
	{
		i2cStart();
		i2cSend(224); //CHECK TO SEE IF START WAS SENT??
		i2cSend(81);  //Range check command byte.
		i2cStop();
	}
}

uint8_t sonarIsReady()
{
	//TODO: Check thingie pin to check for ongoing reading! 
	
	return 1;
}