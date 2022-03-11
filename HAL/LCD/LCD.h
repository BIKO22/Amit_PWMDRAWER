
#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include"../../MCAL/DIO/DIO.h"
#include"../../bit_math.h"
#include<util/delay.h>

void lcd_init(void);
void lcd_sendchar(unsigned char data);
void lcd_sendcmd(unsigned char cmd);
void lcd_sendstring(unsigned char* string);
#endif /* HAL_LCD_LCD_H_ */
