/*
 * Adc.h
 *
 * Created: 15.07.2024 11:14:10
 *  Author: dspproject
 */ 

#include <stdint.h>

#ifndef ADC_H_
#define ADC_H_

void ADC_init();
void startConversion();
uint32_t getResult();

#endif /* ADC_H_ */