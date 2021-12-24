#include "Timer2.h"
#include <avr/interrupt.h>

Timer2::Timer2(){
    cli();
    sei();
}

Timer2::~Timer2(){}

void Timer2::runTimer2(){
    TCNT2 = 0;
    TCCR2A |= 1 << WGM21 | 0 << WGM20; //sets CTC mode 
    TCCR2B |= 0 << WGM22 | 1 << CS22 | 1 << CS21 | 1 << CS20; 
    //sets prescaler to 1024
    TIMSK2 |= 1 << TOIE2; //enables interrupt when there is an overflow
}

void Timer2::resetTimer2(){
    //resets all registers to 0
    TCCR2A = ZER0;
    TCCR2B = ZER0;  
    TCNT2 = ZER0;   
    OCR2A = ZER0; 
    TIMSK2 = ZER0;
}