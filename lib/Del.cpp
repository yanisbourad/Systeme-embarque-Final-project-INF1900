#include "Del.h"

Del::Del() {
    //Sets PINB0 and PINB1 as out pins
    DDRB |= OUT; 
}

Del::~Del() {}

void Del::lightOff() { 
    /* turns off the DEL */
	PORTB ^= OFF;
}


void Del::lightGreen(const uint16_t delay) { 
    /* Lights the DEL green */
	PORTB = GREEN;
    _delay_ms(delay);
    if (delay)
        lightOff();
}

void Del::lightRed(const uint16_t delay) { 
    /* Lights the DEL red */
	PORTB = RED;
    _delay_ms(delay);
    if (delay)
       lightOff();
}
