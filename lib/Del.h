/*
travail fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial

 * Classe del:
 * Allume la DEL d'une certaine couleur et durant un certain intervalle 
 de temps via les methodes lightOff, lightAmbre, lightGreen et lightRed
 Initialise le port B comme port de sortie via le constructeur
 nous avons 4 attributs privée (GREEN, RED, OFF, OUT)
 */

#ifndef DEL_H
#define DEL_H
#define __DELAY_BACKWARD_COMPATIBLE__ 
#include <avr/io.h> 
#include <util/delay.h>

class Del {
    public:
        Del();
        ~Del();
        void lightOff() ;
        void lightGreen(const uint16_t delay = ZERO)  ;
        void lightRed(const uint16_t delay = ZERO)    ;
        
    private:
        const static uint8_t GREEN = 0x01;
        const static uint8_t   RED = 0x02;
        const static uint8_t   OFF = 0x00; 
        const static uint8_t   OUT = 0x03; 
        const static uint16_t SECONDS = 10;
        const static uint16_t ZERO = 0;
};

#endif /* DEL_H */
