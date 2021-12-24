#include "Motor.h"

Motor::Motor() {
    // On met PIN7 et PIN6 a des pins de sortie
    DDRD |= 0xC0; //0xC0 = 0b1100 0000 
}

Motor::~Motor(){}

void Motor::pwmGenerator(float pourcentageA, float pourcentageB){ 
/* timer1 Generates 2 PWM signals using Correct Phase mode and a 
prescaler of clock/8 and a TOP value of 255 (8 bits) the PWM signals
are both equal in frequency and pourcentage (a/b) the pourcentage 
takes values from [0.0 - 1.0] the pourcentage entered MUST be a float
one comes out in D4 the other in D5
*/
    // we generate the same signal for both of the pins
    OCR2A = pourcentageA * TOP;
    OCR2B = pourcentageB * TOP;

    TCCR2A |= 1 << COM2A1 | 0 << COM2A0 | 1 << COM2B1 | 0 << COM2B0 | 
    0 << WGM21 | 1 << WGM20; //set to Correct-Phase 8 bits

    TCCR2B |= 1 << CS21;  // sets prescaler to clock / 8
}
