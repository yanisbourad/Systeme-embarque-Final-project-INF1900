#include "Conversion.h"

Conversion::Conversion(){}

Conversion::~Conversion(){}

float Conversion::convertCMtoINCH(float number){
    // Method servant a convertir les mesures en cm à des mesures en pouce
    //diviser "number" en cm par 2.54 pour avoir en pouce
    return number /= 2.54;
}

float Conversion::convertINCHtoCM(float number){
    // Method servnt a convertir les mesures en pouce à des mesures en cm
    // multiplier "number" qui est en pouce par 2.54 pour avoir la valeur en cm
    return number *= 2.54;
}

uint16_t Conversion::findDecimals(float decimaledNumber, uint8_t numberOfDecimals){
    // Method pour faire afficher les décimals d'un nombre à virgule sur le lcd
	uint16_t DECIMALS = fmod(decimaledNumber, 1) * pow(10, numberOfDecimals);
	return DECIMALS;
}

float Conversion::findx0(uint8_t inputValue){
    float x0Poteau = 0.0f;
    while(funcPoteau(x0Poteau, inputValue)>0){
        x0Poteau++;
    }
    return (x0Poteau + (x0Poteau -1))/2;
}

float Conversion::funcPoteau(float x, uint8_t inputValue)
{
    return (-0.0006*pow(x, 5))+ (0.0272*pow(x, 4)) - (0.6236*pow(x, 3))
    + (8.2525*pow(x, 2)) - (62.711*x) + (256.86-inputValue);
}

float Conversion::derivFuncPoteau(float x)
{
    return (-0.003*pow(x, 4)) + (0.1088*pow(x, 3))
    - (1.8708*pow(x, 2)) + (16.505*x) - 62.711;
}

uint8_t Conversion::findInchPoteau(uint8_t inputValue){
    float x1 = findx0(inputValue) - (funcPoteau(findx0(inputValue), inputValue))/derivFuncPoteau(findx0(inputValue));
    float x2 = x1 - funcPoteau(x1, inputValue)/derivFuncPoteau(x1);
    uint8_t x3 = x2 - funcPoteau(x2, inputValue)/derivFuncPoteau(x2);
    return x3;
}

float Conversion::funcMur(float x, uint8_t inputValue){
    return (-0.0006*pow(x, 5))+ (0.0271*pow(x, 4)) - (0.6445*pow(x, 3))
    + (8.6027*pow(x, 2)) - (65.048*x) + (261.25-inputValue);
}

float Conversion::derivFuncMur(float x){
    return (-0.003*pow(x, 4)) + (0.1084*pow(x, 3))
    - (1.9335*pow(x, 2)) + (17.2054*x) - 65.048;
}

uint16_t Conversion::findInchMur(uint8_t inputValue){
    float x1 = findx0(inputValue) - (funcMur(findx0(inputValue), inputValue))/derivFuncMur(findx0(inputValue));
    float x2 = x1 - funcMur(x1, inputValue)/derivFuncMur(x1);
    uint16_t x3 = x2 - funcMur(x2, inputValue)/derivFuncMur(x2);
    return x3;
}