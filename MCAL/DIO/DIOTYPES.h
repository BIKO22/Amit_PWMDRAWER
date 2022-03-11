

#ifndef MCAL_DIO_DIOTYPES_H_
#define MCAL_DIO_DIOTYPES_H_

typedef enum{
LOW,
HIGH
}State_Type;

typedef enum{
//PORTA

PINA_0,
PINA_1,
Relay,
Buzzer,
LCD_D4,
LCD_D5,
LCD_D6,
LCD_D7,

//PORTB

Button_0,
LCD_Rs,
LCD_Rw,
SS,
LCD_E,
MOSI,
MISO,
SCK,

//PORTC

SCL,
SDA,
LED_0,
H_A1,
H_A2,
H_A3,
H_A4,
LED_1,

//PORTD

Rx,       row0=24,
Tx,       row1=25,
BUTTON_2, row2=26,
LED_2,    row3=27,
H_EN1,    col0=28,
H_EN2,    col1=29,
BUTTON_1, col2=30,
SERVO,    col3=31

}Channel_Type;

typedef enum{
PORT_A,
PORT_B,
PORT_C,
PORT_D
}PORT_Types;

typedef enum{
PIN_0,
PIN_1,
PIN_2,
PIN_3,
PIN_4,
PIN_5,
PIN_6,
PIN_7
}PIN_Types;

typedef enum{
	INPUT,
	OUTPUT
}DIO_DIR;



#endif /* MCAL_DIO_DIOTYPES_H_ */
