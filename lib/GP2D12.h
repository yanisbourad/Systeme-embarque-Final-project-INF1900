/*
travail fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial

 * Classe GP2D12:
 * utilise la classe Can pour lire les signals lu par le capteur de distance et les 
 * convertir en valurs numeriques sur 8 bits
 */
#ifndef GP2D12_H
#define GP2D12_H

#include "can.h"
#include <avr/io.h> 

class GP2D12{
    public:
        GP2D12();
        ~GP2D12();
        uint8_t getNumericValue();
        void readNumericValue();

    private:
        Can can ;
        const uint8_t PIN = 0x07;
        uint8_t numValue ;
};

#endif