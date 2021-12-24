/*
travail fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial
* Cet classe permet de jouer des sons sur le PIN4 du PORTB
*/
#ifndef NOTE_H
//#define F_CPU 8000000 
#define PRESCALER 256
#define NOTE_H
#include "Conversion.h"
#include "Timer0.h"
#include <avr/io.h>

class Note{
    public:
        Note();
        ~Note();
        void stopNote();
        void playNote(uint32_t frequency);
        void playSong(uint8_t InchValue);
    private:
        Timer0 timer;
        Conversion c;
        const uint8_t PINTHREE = 3;
        const uint8_t PINTWO = 2;
        const int FREQUENCY12_INCH = 2000;
        const uint8_t FREQUENCY24_INCH = 200;
        const uint8_t TWELVE = 42;
        const uint8_t TWENTY_FOUR = 25;
};
#endif
