/*
 * ADC.c
 *
 *  Created on: Feb 28, 2022
 *      Author: Mark Nady
 */
#include"ADC.h"

void ADC_init(){

#if(ADC_START == ENABLE)
	SET_BIT(ADCSRA,ADEN);
#else
	CLR_BIT(ADCSRA,ADEN);
#endif

#if ADSC_START == ENABLE
	SET_BIT(ADCSRA,ADSC);
#else
	CLR_BIT(ADCSRA,ADSC);
#endif


#if(ADC_INTERRUPT_ENABLE == ENABLE)
	SET_BIT(ADCSRA,ADIE);
#else
	CLR_BIT(ADCSRA,ADIE);
#endif

#if(ADC_LeftAdjust == ENABLE)
	SET_BIT(ADMUX,ADLAR);
#else
	CLR_BIT(ADMUX,ADLAR);
#endif

#if(ADC_MODE == ADC_AREF_VOLTAGE)
	{
    CLR_BIT(ADMUX,REFS0);
    CLR_BIT(ADMUX,REFS1);
	}

#elif(ADC_MODE == ADC_AVCC_VOLTAGE)
	{
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
	}

#elif(ADC_MODE == ADC_VREF_VOLTAGE)
	{
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
	}
#endif

#if(FREQ_PRESCALE == PRESCALE_2)
	{
		CLR_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
	}

#elif(FREQ_PRESCALE == PRESCALE_4)
	{
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
	}

#elif(FREQ_PRESCALE == PRESCALE_8)
	{
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
	}

#elif(FREQ_PRESCALE == PRESCALE_16)
	{
		CLR_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
	}

#elif(FREQ_PRESCALE == PRESCALE_32)
	{
		SET_BIT(ADCSRA,ADPS0);
        CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
	}

#elif(FREQ_PRESCALE == PRESCALE_64)
	{
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
	}

#elif(FREQ_PRESCALE == PRESCALE_128)
	{
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
	}
#endif
}

uint16 ADC_read(uint8 Channel){

	ADMUX = (ADMUX & 0b11100000) | Channel;

	SET_BIT(ADCSRA,ADSC); //Start Conversion
	while(GET_BIT(ADCSRA,ADIF)==0); //Wait for Finishing Conversion
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}

