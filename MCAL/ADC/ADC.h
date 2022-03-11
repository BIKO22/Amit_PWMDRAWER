
#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
#include"../../STD_Types.h"
#include"../../Bit_Math.h"
#include<avr/io.h>
#include"ADC_Config.h"

void ADC_init();
uint16 ADC_read(uint8 Channel);

#endif /* MCAL_ADC_ADC_H_ */
