#include "Note.h"

Note::Note(){
    // PIN3 represente la sortie du son
    DDRB |= 1 << PINTWO | 1 << PINTHREE;
    PORTB &= ~(1 << PINTWO);  
}

Note::~Note(){}

void Note::playNote(uint32_t frequency){
    uint8_t cycles = F_CPU/(frequency * 2 * PRESCALER) - 1; //formule de la documentation
    timer.runTimer0(cycles);
}

void Note::stopNote(){
    timer.resetTimer0();
}

void Note::playSong(uint8_t valueADC){
   if(valueADC >= TWELVE) playNote(2000);
   if(valueADC == TWENTY_FOUR) playNote(200);
   if(valueADC > TWENTY_FOUR && valueADC < TWELVE) {
       playNote(-150*c.findInchMur(valueADC)+3800);
   }
   else stopNote();
}
