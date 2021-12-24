/*
travail fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial

C'est la classe qui contrôle les roues des robots, et a 2 attributs OUT et TOP.

void PwmGenerator(float pourcentageA, float pourcentage B) permet d'activer le 
PORTD en sortie à l'aide de l'attribut OUT et génère 2 signaux PWM à l'aide de 
timer1,l'un sort de la broche D4 et l'autre de la broche D5. Le timer1 compte 
jusqu'àun maximum de TOP = 28-1= 255, "pourcentageA" et "pourcentageB" 
contrôlent le signal pwm de chaque roue.
*/

#ifndef MOTOR_H
#define MOTOR_H
#include <avr/io.h> 

class Motor{ 
   public:
      Motor();
      ~Motor();
      void pwmGenerator(float pourcentageA, float pourcentageB);

   private:
      const static uint8_t OUT = 0xff;
      const static uint8_t TOP = 254; 
};

#endif /* MOTOR_H */
