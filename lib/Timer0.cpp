#include "Timer0.h"
#include <avr/interrupt.h>
Timer0::Timer0(){
}
Timer0::~Timer0(){}
void Timer0::runTimer0(uint8_t cycles) {
    /* Runs Timer0 using CTC mode and counts from 0 until timeInCycles */
    TCNT0 = 0 ; 
    //max time 
    OCR0A = cycles; 
    // sets OC0A as pwm output
    TCCR0A = 0 << COM0A1 | 1 << COM0A0 | 1 << WGM01 | 0 << WGM00 ;
    // prescaler a 256 
    TCCR0B = 1 << CS02  | 0 << CS01 | 0 << CS00;       
    // we need 0b10 for the compare A match flag
    //TIMSK0 = 1 << OCIE0A | 0 << TOIE0 ;
} 
void Timer0::resetTimer0() {
    // reset les parametres du timer
    TCCR0A = ZERO;
    TCCR0B = ZERO;  
    TCNT0  = ZERO;   // reset du Timer0 en le fixant a 0
    OCR0A  = ZERO; // reset registre de comparaison OCR0A
    TIMSK0 = ZERO; // Reset TIMSK0 pour désactiver le compare A match flag
}
