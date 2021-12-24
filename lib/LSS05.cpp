#include "LSS05.h"

LSS05::LSS05(){
    DDRA = SENSORPORT;
}

LSS05::~LSS05() {}

void LSS05::moveRobot()
{
    // Permet de diriger le robot d'une facon droite, 
    //et repositionner les roues s'ils deraille
    
    uint8_t lecture[5] = {(uint8_t)(PINA & DS1), (uint8_t)(PINA & DS2), 
    (uint8_t)(PINA & DS3), (uint8_t)(PINA & DS4), (uint8_t)(PINA & DS5)};

    //cas ou on avance
    if (lecture[INDEX2] && !lecture[INDEX3] && !lecture[INDEX1])
    {
        navigation.advance(ADVANCEPWM_2);
    }
    //cas ou on turn right slightly
    else if (lecture[INDEX3] && !lecture[INDEX4])
    {
        navigation.turnRightSlightly();
    }
    //cas ou on turn left slightly
    else if (lecture[INDEX1] && !lecture[INDEX0])
    {
        navigation.turnLeftSlightly();
    }
    //cas ou on turn left medium
    else if (lecture[INDEX0] && lecture[INDEX1])
    {
        navigation.turnLeftMedium();
    }
    // cas ou on turn right medium
    else if (lecture[INDEX4] && lecture[INDEX3])
    {
        navigation.turnRightMedium();
    }

    //cas ou on turn left very
    else if (lecture[INDEX0])
    {
        navigation.turnLeftVery();
    }
    // cas ou on turn right very
    else if (lecture[INDEX4])
    {
        navigation.turnRightVery();
    }
}

void LSS05::moveRobotLeft()
{
    // Permet de tourner les roues vers la droite
    navigation.stopMotor();
    _delay_ms(SECOND);
    navigation.advance(ADVANCEPWM);
    _delay_ms(HALFSECOND);
    navigation.turnLeft();
    _delay_ms(HALFSECOND);
}

void LSS05::moveRobotRight()
{
    // Permet de tourner les roues vers la droite
    navigation.stopMotor();
    _delay_ms(SECOND);
    navigation.advance(ADVANCEPWM);
    _delay_ms(HALFSECOND);
    navigation.turnRight();
    _delay_ms(HALFSECOND);
}
