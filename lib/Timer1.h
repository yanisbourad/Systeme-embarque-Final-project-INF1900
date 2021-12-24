/*
travail fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial

* Cet Classe permet d'initialiser le timer1 
* On a un construteur, un destructeur, une méthode qui 
initialise les settings du timer1,
* ainsi qu'une methode qui permet de le reinitialiser.
*/

#ifndef TIMER1_H
#define TIMER1_H
#include <avr/io.h> 
#include <util/delay.h>


class Timer1{

    public:
        Timer1();
        ~Timer1();
        void runTimer1(uint16_t timeInCycles);
        void resetTimer1(); 

    private:
        const uint16_t ZER0 = 0;  
};

#endif