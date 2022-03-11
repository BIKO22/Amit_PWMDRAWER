/*
 * TIMER_1.h
 *
 *  Created on: Feb 28, 2022
 *      Author: Mark Nady
 */

#ifndef MCAL_TIMER_1_TIMER_1_H_
#define MCAL_TIMER_1_TIMER_1_H_
#include<avr/io.h>
#include<stdlib.h>
#include<util/delay.h>
#include"../DIO/DIO.h"
#include"../../bit_math.h"
#include"../external_interrupt/extint.h"
#include"../../STD_Types.h"

void timer1_init(unsigned short b,unsigned short c,unsigned short a,unsigned long long *high,unsigned long long *period);
void __vector_9(void)__attribute__((signal));

#endif /* MCAL_TIMER_1_TIMER_1_H_ */
