#include<avr/io.h>
#include<stdlib.h>
#include<util/delay.h>
#include"MCAL/DIO/DIO.h"
#include"bit_math.h"
#include"MCAL/ADC/ADC.h"
#include"MCAL/external_interrupt/extint.h"
#include "MCAL/TIMER0/TIMER0.h"
#include"HAL/LCD/LCD.h"
#include"STD_Types.h"
#include "MCAL/TIMER_1/TIMER_1.h"
#define f_cpu 16000000UL


int main()
{
	unsigned short b,c,a;
	unsigned long long high,period;
	uint8_t frequency[14],duty_cy[7];
	DIO_init();   /*initiating the dio*/
	TMR0_init();   /*initiating the timer 0*/
	lcd_init();   /*initiating the lcd*/
	PORTD = 0xFF;      /* Turn ON pull-up resistor */
	TMR0_Set_OCR(150);   /*setting a value for ocr in timer 0*/
	TIMSK|=(1<<2);    /* Overflow Interrupt Enable*/
	TCCR1A=0;        /*clear register TCCR1A*/
	asm("SEI");    /*embed assembler instructions*/
	while(1)
	{


		timer1_init(a,b,c,&high,&period); /* initiate timer 1 and send these parameters*/
		long freq= f_cpu/period;/* Calculate frequency */
		float duty_cycle =((float)high /(float)period)*100; /* Calculate duty cycle */
		ltoa(freq,frequency,10);   /*convert the freq from uint8 to string */

		itoa((int)duty_cycle,duty_cy,10); /*convert the duty cycle from uint8 to string */
		lcd_sendcmd(0x80);  /*setting the cursor to first row*/
		lcd_sendstring("Freq: ");
		lcd_sendstring(frequency);
		lcd_sendstring(" Hz    ");

		lcd_sendcmd(0xC0);  /*setting the cursor to second row*/
		lcd_sendstring("Duty: ");
		lcd_sendstring(duty_cy);
		lcd_sendstring(" %      ");


	}

	return 0;
}




