/*
travail fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial
* Classe PushButton:
*   checks the state of the pushButton by scrutation using the debounce method
*   Initializes the D2 pin to recieve external interrupts using the method initializeD2
*/

#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#define __DELAY_BACKWARD_COMPATIBLE__
#include <avr/io.h> 
#include <util/delay.h>
#include <avr/interrupt.h> 


class PushButton{ 
   public:
      PushButton();
      void initializePortD();

   private:
      const static uint8_t IN = 0x00;
};

#endif /* PUSHBUTTON_H */
