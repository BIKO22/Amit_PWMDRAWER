
#include"DIO_config.h"
pin_config_type pin_config[]={
		{PORT_D, PIN_0,OUTPUT},
		{PORT_D, PIN_1,OUTPUT},
		{PORT_D, PIN_2,OUTPUT},
		{PORT_D, PIN_3,OUTPUT},
		{PORT_D, PIN_4,OUTPUT},
		{PORT_D, PIN_5,OUTPUT},
		{PORT_D, PIN_6,INPUT},
		{PORT_D, PIN_7,OUTPUT},


		{PORT_A, PIN_1,INPUT},
		{PORT_A, PIN_2,INPUT},
		{PORT_A, PIN_7,OUTPUT},
		{PORT_A, PIN_6,OUTPUT},
		{PORT_A, PIN_5,OUTPUT},
		{PORT_A, PIN_4,OUTPUT},

		{PORT_B, PIN_3,OUTPUT},
		{PORT_B, PIN_2,OUTPUT},
		{PORT_B, PIN_1,OUTPUT},
		{PORT_B, PIN_4,INPUT},
		{PORT_B, PIN_5,INPUT},
		{PORT_B, PIN_6,OUTPUT},
		{PORT_B, PIN_7,INPUT},

		{PORT_C, PIN_0,OUTPUT},
		{PORT_C, PIN_1,OUTPUT},
		{PORT_C, PIN_2,OUTPUT},
		{PORT_C, PIN_3,OUTPUT},
		{PORT_C, PIN_4,OUTPUT},
		{PORT_C, PIN_5,OUTPUT},
		{PORT_C, PIN_6,OUTPUT},
		{PORT_C, PIN_7,OUTPUT}
};

void DIO_init(void)
{
	int i=0;
	for(i=0;i<sizeof(pin_config)/sizeof(pin_config[0]);i++)
	{
		switch (pin_config[i].PORT){
		case PORT_A:
			if(pin_config[i].IO==OUTPUT)
			{
				SET_BIT(DDRA,pin_config[i].PIN);
			}
			else
			{
				CLR_BIT(DDRA,pin_config[i].PIN);
			}
			break;
		case PORT_B:
					if(pin_config[i].IO==OUTPUT)
					{
						SET_BIT(DDRB,pin_config[i].PIN);
					}
					else
					{
						CLR_BIT(DDRB,pin_config[i].PIN);
					}
			break;

		case PORT_C:
					if(pin_config[i].IO==OUTPUT)
					{
						SET_BIT(DDRC,pin_config[i].PIN);
					}
					else
					{
						CLR_BIT(DDRC,pin_config[i].PIN);
					}
			break;
		case PORT_D:
					if(pin_config[i].IO==OUTPUT)
					{
						SET_BIT(DDRD,pin_config[i].PIN);
					}
					else
					{
						CLR_BIT(DDRD,pin_config[i].PIN);
					}
			break;
		default:
			break;





		}
	}
}
