
#ifndef TMP102DRV_H_
#define TMP102DRV_H_

void writePointerRegister(uint8_t pointerReg);
void readPointerRegister(uint8_t* registerByte);
float readTemp();


#endif /* TMP102DRV_H_ */