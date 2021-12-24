/*
travail fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial

* Cet Classe permet d'initialiser le timer2 qu'on utilise pour generer 
un pwm qui alimente les roues du robot.
* On a un construteur, un destructeur, une méthode qui initialise les 
settings du timer2, ainsi qu'une methode qui permet de le reinitialiser.
*/

#ifndef TIMER2_H
#define TIMER2_H
#include <avr/io.h> 
#include <util/delay.h>


class Timer2{

    public:
        Timer2();
        ~Timer2();
        void runTimer2();
        void resetTimer2();

    private: 
        const uint8_t ZER0 = 0;
};

#endif