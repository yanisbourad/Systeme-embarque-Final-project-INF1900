/*
travail fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial

 * Classe LSS05:
 * permet de lire les signaux recus par le capteur suiveur de 
 * ligne et diriger le robot, a marcher droit
 * tourner gauche ou droit, en ajustant le pwm de ces roues.
 */
#ifndef LSS05_H
#define LSS05_H
#include <avr/io.h> 
#include <Navigation.h>


class LSS05{
    public:

        LSS05();
        ~LSS05();
        void moveRobot();
        void moveRobotLeft();
        void moveRobotRight();
        void moveRobot_boucle();

    protected:
        const uint8_t DS1= 0x01; //PIN A0
        const uint8_t DS2= 0x02; //PIN A1
        const uint8_t DS3= 0x04; //PIN A2
        const uint8_t DS4= 0x08; //PIN A3
        const uint8_t DS5= 0x10; //PIN A4
        const uint8_t INDEX0 = 0;
        const uint8_t INDEX1 = 1;
        const uint8_t INDEX2 = 2;
        const uint8_t INDEX3 = 3;
        const uint8_t INDEX4 = 4;
        const static int SECOND = 1000;
        const static int HALFSECOND = 500;

    private:
        Navigation navigation;
        const uint8_t SENSORPORT = 0x00;
        //used in moveRobotLeft and moveRobotRight
        const float ADVANCEPWM = 0.70; 
        //used in moveRobot
        const float ADVANCEPWM_2 = 0.70; 
};
#endif