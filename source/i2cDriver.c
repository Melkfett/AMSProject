/*
 * i2cDriver.c
 *
 * Created: 07-04-2019 15:42:51
 *  Author: frederik
 */ 

#include <avr/io.h>
#include <stdint.h>
#include "../include/i2cDriver.h"
#include "../include/UARTDriver.h"

//Clock hastighed???? Skal nok indstilles.
//Init function?

void i2cInit() {
    //PRR0 &= ~(1<<PRTWI);
    TWSR = 0b00000000;
    TWBR = 152; //38
}

void i2cStart() //TWSTA SKAL IFØLGE DATASHEET CLEARES AF OS???? DET GØR VI INGEN STEDER.
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); //Send start condition.
	
	while (!(TWCR & (1<<TWINT))); //Wait for TWINT to be set; indicating instruction completed.
	{}
		
}

void i2cWrite(uint8_t data)
{
	//while((TWSR & 0x08) != 0x08);
	//UARTTransmitByte('A');
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	//UARTTransmitByte('A');
	while ((TWCR & (1<<TWINT)) == 0) //Wait for TWINT to be set; indicating instruction completed.
	{}
		//UARTTransmitByte('B');
}

void i2cReceive(uint8_t* buf, uint8_t cnt)
{
	uint8_t* temp = buf;
	uint8_t cnt_temp = cnt;
	while(cnt_temp > 1)
	{
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA); //Start read and generate ack.
		while((TWCR & (1<<TWINT)) == 0); //Wait for TWINT to be set; indicating instruction completed.
		*temp = TWDR;
		temp++;
		cnt_temp--;
	}
	
	TWCR = (1<<TWINT) | (1<<TWEN); //Start read, do not generate ack.
	while((TWCR & (1<<TWINT)) == 0); //Wait for TWINT to be set; indicating instruction completed.
	{
	}
	*temp = TWDR;
	
}

void i2cStop()
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}
