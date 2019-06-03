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

	//TODO: Husk at checke ny data io pin!!!(Eller bare bede den l�se hver anden gang? Eller begge? Nok begge.
	//TODO: Husk at sensoren ogs� bruger tid p� at starte op (Og sender p� den pin!)
}

void sonarDoRangeCheckNow()
{
		i2cStart();
		i2cWrite(224); //CHECK TO SEE IF START WAS SENT??
		i2cWrite(81);  //Range check command byte.
		i2cStop();
}

uint8_t sonarIsReady()
{
	//TODO: Check thingie pin to check for ongoing reading! 
	
	return 1;
}