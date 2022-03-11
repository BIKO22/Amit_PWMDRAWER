/*
 * LCD.c
 *
 *  Created on: Feb 28, 2022
 *      Author: Mark Nady
 */
#include "LCD.h"

void lcd_init(void)
{
	_delay_ms(200);
	lcd_sendcmd(0x33);
	lcd_sendcmd(0x32);
	lcd_sendcmd(0x28);
	lcd_sendcmd(0x0f);
	lcd_sendcmd(0x06);
	lcd_sendcmd(0x01);


}

void lcd_sendchar(unsigned char data)
{
	SET_BIT(PORTB,1);
	CLR_BIT(PORTB,2);
	if(GET_BIT(data,4)){DIO_write(LCD_D4,HIGH);}else {DIO_write(LCD_D4,LOW);}
	if(GET_BIT(data,5)){DIO_write(LCD_D5,HIGH);}else {DIO_write(LCD_D5,LOW);}
	if(GET_BIT(data,6)){DIO_write(LCD_D6,HIGH);}else {DIO_write(LCD_D6,LOW);}
	if(GET_BIT(data,7)){DIO_write(LCD_D7,HIGH);}else {DIO_write(LCD_D7,LOW);}

	SET_BIT(PORTB,6);
	_delay_us(10);
	CLR_BIT(PORTB,6);
	_delay_us(200);

	if(GET_BIT(data,0)){DIO_write(LCD_D4,HIGH);}else {DIO_write(LCD_D4,LOW);}
	if(GET_BIT(data,1)){DIO_write(LCD_D5,HIGH);}else {DIO_write(LCD_D5,LOW);}
	if(GET_BIT(data,2)){DIO_write(LCD_D6,HIGH);}else {DIO_write(LCD_D6,LOW);}
	if(GET_BIT(data,3)){DIO_write(LCD_D7,HIGH);}else {DIO_write(LCD_D7,LOW);}

	SET_BIT(PORTB,6);
	_delay_us(10);
	CLR_BIT(PORTB,6);
	_delay_us(200);
}

void lcd_sendcmd(unsigned char cmd)
{
	CLR_BIT(PORTB,1);
	CLR_BIT(PORTB,2);
		if(GET_BIT(cmd,4)){DIO_write(LCD_D4,HIGH);}else {DIO_write(LCD_D4,LOW);}
		if(GET_BIT(cmd,5)){DIO_write(LCD_D5,HIGH);}else {DIO_write(LCD_D5,LOW);}
		if(GET_BIT(cmd,6)){DIO_write(LCD_D6,HIGH);}else {DIO_write(LCD_D6,LOW);}
		if(GET_BIT(cmd,7)){DIO_write(LCD_D7,HIGH);}else {DIO_write(LCD_D7,LOW);}

		SET_BIT(PORTB,6);
		_delay_us(10);
		CLR_BIT(PORTB,6);
		_delay_us(2000);

		if(GET_BIT(cmd,0)){DIO_write(LCD_D4,HIGH);}else {DIO_write(LCD_D4,LOW);}
		if(GET_BIT(cmd,1)){DIO_write(LCD_D5,HIGH);}else {DIO_write(LCD_D5,LOW);}
		if(GET_BIT(cmd,2)){DIO_write(LCD_D6,HIGH);}else {DIO_write(LCD_D6,LOW);}
		if(GET_BIT(cmd,3)){DIO_write(LCD_D7,HIGH);}else {DIO_write(LCD_D7,LOW);}

		SET_BIT(PORTB,6);
		_delay_us(10);
		CLR_BIT(PORTB,6);
		_delay_us(2000);

}

void lcd_sendstring(unsigned char * string)
{
   int i=0;
   for(i=0;string[i]!=0;i++)
   {
	lcd_sendchar(string[i]);
   }

}
