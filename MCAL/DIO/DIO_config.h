
#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_
#include"DIOTYPES.h"
#include<avr/io.h>
#include"../../bit_math.h"
#include"DIO.h"

typedef struct{
	PORT_Types PORT;
	PIN_Types PIN;
	DIO_DIR IO;
}pin_config_type;

#endif /* MCAL_DIO_DIO_CONFIG_H_ */
