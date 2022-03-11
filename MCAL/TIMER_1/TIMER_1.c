/*
 * TIMER_1.c
 *
 *  Created on: Feb 28, 2022
 *      Author: Mark Nady
 */
#include "TIMER_1.h"
uint8_t count = 0;
void timer1_init(unsigned short b,unsigned short c,unsigned short a,unsigned long long *high,unsigned long long *period)
{

		        TCCR1B = 0x41;  	/* Rising edge, no prescaler */
			    SET_BIT(TIFR,ICF1);  	/* Clear ICF (Input Capture flag) flag */
				while (GET_BIT(TIFR,ICF1)== 0);
				a = ICR1;
				TCCR1B = 0x01;  	/* Falling edge, no prescaler */
				TCNT1=0;
				count=0;             /*clear the counter*/
				TIFR = (1<<ICF1);  	/* Clear ICF flag */
				while (GET_BIT(TIFR,ICF1) == 0);
				b = ICR1;  		/* Take value of capture register */
				TCCR1B = 0x41;  	/* Rising edge, no prescaler */
				SET_BIT(TIFR,ICF1); ;  	/* Clear ICF flag */
				while (GET_BIT(TIFR,ICF1) == 0);
				c = ICR1;  		/* Take value of capture register */
				TWDR=ICR1L;
				SET_BIT(TIFR,ICF1);   	/* Clear ICF flag */
				TCCR1B = 0;  		/* Stop the timer */

				if(1)  	/* Check for valid condition,
							to avoid timer overflow reading */
				{
					*high=b+(65536ul * count);
					*period=c+(65536ul * count);
					_delay_ms(1000);
					//high=b-a;
					//period=c-a;
				}

}






void __vector_9(void)
{
	count++; // to calculate the no of overflows
}
