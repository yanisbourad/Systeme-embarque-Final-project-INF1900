#include "GP2D12.h"

GP2D12::GP2D12(){}

GP2D12::~GP2D12() {}

void GP2D12::readNumericValue(){
    //reads analogue value from PIN7 of portA and converts it to decimal value using can
    numValue = can.get8Bits(can.read(PIN));
}

uint8_t GP2D12::getNumericValue(){
    //returns the attribute numValue of the class
    return numValue;
}