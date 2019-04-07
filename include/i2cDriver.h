/*
 * i2cDriver.h
 *
 * Created: 07-04-2019 15:31:33
 *  Author: frederik
 */ 

#ifndef I2CDRIVER_H_
#define I2CDRIVER_H_

#include <stdint.h>

void i2cStart();
void i2cStop();
void i2cSend(uint8_t buf);
void i2cReceive(uint8_t* buf, uint8_t cnt);


#endif /* I2CDRIVER_H_ */