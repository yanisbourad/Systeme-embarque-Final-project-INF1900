#include "PushButton.h"

void PushButton::initializePortD(){
   DDRD |= IN; 
}

PushButton::PushButton(){
    /* Initializes pin D2 to allow the INT0 and INT1 interrupt */
    cli();                              //stop interrupts
    EIMSK |= (1 << INT0) | (1 << INT1); //Enables INT0 and INT1
    //reacts on rising edge (high )
    EICRA |= (1 << ISC01) | (1 << ISC00) | (1 << ISC11) | (0 << ISC10);
    sei(); //intercept interrupt
}
