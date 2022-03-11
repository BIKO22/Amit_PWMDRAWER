
#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include "../../STD_Types.h"
#include "../../bit_math.h"
#include"DIOTYPES.h"
#include <avr/io.h>
#include"DIO_config.h"
#include <util/delay.h>


void DIO_write(uint8 channel,uint8 state);
int DIO_read(uint8 channel);
void DIO_init(void);

#endif /* MCAL_DIO_DIO_H_ */
