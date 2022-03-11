

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_

#include"TIMER0.h"


#define ENABLE 1
#define DISABLE 0

#define Normal_Mode   0
#define PWM_Mode      1
#define CTC_Mode      2
#define FastPWM_Mode  3

#define T0_MODE PWM_Mode

#define No_OC0           0
#define ToggleOC0_OnComp 1
#define ClearOC0_OnComp  2
#define SetOC0_OnComp    3

#define CompareOUTPUTMode ToggleOC0_OnComp

#define No_OC0_PWM         0
#define NotUsed            1
#define Non_InvertedPWM    2
#define InvertedPWM        3

#define CompOutputModePWM Non_InvertedPWM

#define NoCLK                 0
#define NoPre                 1
#define Pre8                  2
#define Pre64                 3
#define Pre256                4
#define Pre1024               5
#define ExtSourceT0_FallingE  6
#define ExtSourceT0_RaisingE  7

#define CLK_Pre Pre64


#define T0_OCR_Value 95
#define T0_INIT_Value 0


#define TMR0_IntEnable    DISABLE
#define TMR0_IntEnableCTC DISABLE



#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
