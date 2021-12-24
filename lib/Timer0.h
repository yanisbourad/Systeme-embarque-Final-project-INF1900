/*
travail fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial
* Cet Classe permet d'initialiser le timer0 qu'on va utiliser pour 
emettre du son. On a un construteur, un destructeur, une méthode 
qui initialise les settings du timer0, ainsi qu'une methode qui
 permet de le reinitialiser
*/
#ifndef TIMER0_H
#define TIMER0_H
#include <avr/io.h> 
#include <util/delay.h>

class Timer0{
    public:
        Timer0();
        ~Timer0();
        void runTimer0(uint8_t cycles);
        void resetTimer0();
    private:
        const uint8_t ZERO = 0;
};
#endif