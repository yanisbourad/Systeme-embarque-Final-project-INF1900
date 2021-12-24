/*
travail fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial

* Cet classe nous permet de controler les signaux pwm qui alimentent les roues des robots,
* et les manipuler en fonction des navigations qu'on veux faire (avancer, reculer, tourner etc..)
*/
#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "Motor.h"
#include <util/delay.h>
#include <avr/io.h> 


class Navigation{
    public:
        Navigation();
        ~Navigation();
        void setDirection(bool direction);
        bool getDirection();
        void advance(float percentage);
        void reverse(float percentage);
        void turnLeft();
        void turnLeftSlightly();
        void turnLeftMedium();
        void turnLeftVery();

        void turnLeft90();
        void turnLeft180();
        void turnRight();
        void turnRightSlightly();
        void turnRightMedium();
        void turnRightVery();
        void turnRight90();
        void turnRightContourner();
        void stopMotor();
        
    private:
        Motor motor;
        bool currentDirection ; // valeur initiale
        float currentSpeed ; 
        const float TURNPOURCENT_ = 0.75; // valeur initiale
        const uint8_t PINFOUR = 4;
        const uint8_t PINFIVE = 5;
        const uint8_t ZERO = 0;
        const uint8_t ONE = 1;
        const float CONTOURNERPERCENT = 0.12; 

        const float RIGHTMEDIUMPERCENT = 0.11; 
        const float RIGHT_VERY_PERCENT = 0.15;

        const float LEFTMEDIUMPERCENT = 0.10;
        const float LEFT_VERY_PERCENT = 0.18;
        const float SLIGHTLYPERCENT = 0.05;
        const float PERCENT_180Degrees = 0.13;
        const float RIGHTPERCENT = 0.20;
        const float LEFTPERCENT = 0.15;
        const float ADVANCEPERCENT = 0.099;
        const float ZEROPERCENT = 0.0;
        const static int DELAY_90degrees = 1400;
};

#endif
