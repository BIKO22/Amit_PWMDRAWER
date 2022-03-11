/*
 * TIMER.c
 *
 *  Created on: Feb 28, 2022
 *      Author: Mark Nady
 */
#include"TIMER0.h"

void (*CallBackPtr_TMR0_OV)(void);
void (*CallBackPtr_TMR0_COMP)(void);

void TMR0_Set_OCR(unsigned char DutyCycle)
{
	OCR0  = DutyCycle; //PB3
}

void TMR0_init(){
	TCNT0 = T0_INIT_Value;
	OCR0 =0;

#if T0_MODE == Normal_Mode
	{
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	}

#elif T0_MODE == PWM_Mode
	{
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	}

#elif T0_MODE == CTC_Mode
	{
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		OCR0  = T0_OCR_Value;
	}

#elif T0_MODE == FastPWM_Mode
	{
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	}

#endif



#if(T0_MODE == Normal_Mode && CompareOUTPUTMode == NO_OC0)
		{
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}

#elif(T0_MODE == CTC_Mode && CompareOUTPUTMode == NO_OC0)
		{
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}
#elif(T0_MODE == Normal_Mode && CompareOUTPUTMode == ToggleOC0_OnComp)
	{
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}

#elif(T0_MODE == CTC_Mode && CompareOUTPUTMode == ToggleOC0_OnComp)
	{
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}
#elif(T0_MODE == Normal_Mode && CompareOUTPUTMode == ClearOC0_OnComp)
	{
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#elif(T0_MODE == CTC_Mode && CompareOUTPUTMode == ClearOC0_OnComp)
	{
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#elif(T0_MODE == Normal_Mode && CompareOUTPUTMode == SetOC0_OnComp)
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#elif(T0_MODE == CTC_Mode && CompareOUTPUTMode == SetOC0_OnComp)
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#endif


#if  T0_MODE == PWM_Mode && CompOutputModePWM == No_OC0
	{
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}
#elif  T0_MODE == FastPWM_Mode && CompOutputModePWM == No_OC0
	{
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}

#elif  T0_MODE == PWM_Mode && CompOutputModePWM == Non_InvertedPWM
	{
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#elif  T0_MODE == FastPWM_Mode && CompOutputModePWM == Non_InvertedPWM
	{
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#elif T0_MODE == PWM_Mode && CompOutputModePWM == InvertedPWM
	{
	    SET_BIT(TCCR0,COM00);
	    SET_BIT(TCCR0,COM01);
	}
#elif T0_MODE == FastPWM_Mode && CompOutputModePWM == InvertedPWM
	{
	    SET_BIT(TCCR0,COM00);
	    SET_BIT(TCCR0,COM01);
	}

#endif


#if CLK_Pre == NoCLK
	{
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == NoPre
	{
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == Pre8
	{
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == Pre64
	{
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == Pre256
	{
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == Pre1024
	{
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == ExtSourceT0_FallingE
	{
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

#elif CLK_Pre ExtSourceT0_RaisingE
	{
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

#endif

#if TMR0_IntEnable == ENABLE
	 SET_BIT(TIMSK,TOIE0);

#else
	 CLR_BIT(TIMSK,TOIE0);

#endif

#if TMR0_IntEnableCTC == ENABLE
	 SET_BIT(TIMSK,OCIE0);

#else
	 CLR_BIT(TIMSK,OCIE0);

#endif
}

ISR(TIMER0_OVF_vect)
{
	CallBackPtr_TMR0_OV();
}

ISR(TIMER0_COMP_vect)
{
	CallBackPtr_TMR0_COMP();
}

void SetCallBack_TMR0_OV(void(*p2fOV)(void))
{
	CallBackPtr_TMR0_OV=p2fOV;
}

void SetCallBack_TMR0_COMP(void(*p2fCOMP)(void))
{
	CallBackPtr_TMR0_COMP=p2fCOMP;
}



