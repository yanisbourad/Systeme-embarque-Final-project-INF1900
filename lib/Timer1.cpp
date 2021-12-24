#include "Timer1.h"
#include <avr/interrupt.h>

Timer1::Timer1(){
    cli();
    sei();
}

Timer1::~Timer1(){}

void Timer1::runTimer1(uint16_t timeInCycles) {
    /* Runs Timer1 using CTC mode and counts from 0 until timeInCycles */
    TCNT1 = 0 ; 
    //max time 
    OCR1A = timeInCycles; 
    // 00 for CTC mode
    TCCR1A |= 0 << WGM11 | 0 << WGM10 ; 
    //1 for CTC mode and 101 for counter/1024 prescaler.
    TCCR1B |= 1 << WGM12 | 1 << CS12 | 1 << CS10; 
    TCCR1C |= 0;
    // we need 0b10 for the compare A match flag
    TIMSK1 |= 1 << OCIE1A | 0 << TOIE1 ; 
} 

void Timer1::resetTimer1() {
    
    // reset les parametres du timer
    TCCR1C = ZER0;
    TCCR1A = ZER0;
    TCCR1B = ZER0;  
    TCNT1 = ZER0;  // reset du Timer1 en le fixant a 0
    OCR1A = ZER0;  // reset registre de comparaison OCR1A
    TIMSK1 = ZER0; // Reset TIMSK1 pour désactiver le compare A match flag
}