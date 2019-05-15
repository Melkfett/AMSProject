
#ifndef TMP102DRV_H_
#define TMP102DRV_H_

void tmp102Init();
void writePointerRegister();
uint8_t readPointerRegister(int registerByte_);
float readTemp();


#endif /* TMP102DRV_H_ */