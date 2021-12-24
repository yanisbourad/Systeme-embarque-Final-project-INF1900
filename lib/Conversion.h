#ifndef CONVERSION_H
#define CONVERSION_H

#include <avr/io.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


class Conversion{
    public:
        Conversion();
        ~Conversion();
        float convertCMtoINCH(float number);
        float convertINCHtoCM(float number);
        uint16_t findDecimals(float decimaledNumber, uint8_t numberOfDecimals);
        float findx0(uint8_t inputValue);
        float funcPoteau(float x, uint8_t inputValue);
        float derivFuncPoteau(float x);
        uint8_t  findInchPoteau(uint8_t inputValue);
        float funcMur(float x, uint8_t inputValue);
        float derivFuncMur(float x);
        uint16_t findInchMur(uint8_t inputValue);

};

#endif