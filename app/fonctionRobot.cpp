#include <fonctionRobot.h>

fonctionRobot::fonctionRobot() {}

void fonctionRobot::toGo()
{
    del.lightGreen();
    _delay_ms(TWO_SECOND);
}

void fonctionRobot::getBC()
{
    do
    {
        suiveurLigne.moveRobot();
    } while (!((PINA & DS3) && (PINA && DS4) && (PINA & DS5)));
    _delay_ms(FIFTH_SECOND);
    timer1.runTimer1(TIME_ONE_CYCLE / 2);
}

uint8_t fonctionRobot::getDistance()
{
    suiveurLigne.moveRobot();
    capteurDistance.readNumericValue();
    numValue = capteurDistance.getNumericValue();
    note.playSong(numValue);
    return numValue;
}

void fonctionRobot::prepareToWait()
{
    navigation.stopMotor();
    note.stopNote();
}

void fonctionRobot::makeTurn180()
{
    while (!(PINA & DS1))
    {
        navigation.turnLeft180();
    }
    navigation.stopMotor();
    _delay_ms(ONE_SECOND);
}

void fonctionRobot::triangle()
{
    do
    {
        suiveurLigne.moveRobot();
        counterTriangle++;
    } while (!((PINA & DS1) && (PINA && DS2) && (PINA & DS3)));
    suiveurLigne.moveRobotLeft();
    while (true)
    {
        if ((PINA & DS2) || (PINA & DS3))
        {
            navigation.stopMotor();
            break;
        }
    }
}

void fonctionRobot::BG()
{
    _delay_ms(FIFTH_SECOND);
    do
    {
        suiveurLigne.moveRobot();
        counterTriangle--;
    } while (counterTriangle != 0);
    navigation.turnLeft180();
    _delay_ms(1200);
}

void fonctionRobot::turnLeftUntilLine()
{
    suiveurLigne.moveRobotLeft();
    while (true)
    {
        if ((PINA & DS2) || (PINA & DS3))
        {
            navigation.stopMotor();
            _delay_ms(ONE_SECOND);
            break;
        }
    }
}

void fonctionRobot::goAround()
{
    navigation.stopMotor();
    _delay_ms(2000);
    navigation.turnLeft();
    _delay_ms(1100);

    while (!((PINA & DS1) || (PINA & DS2) || (PINA & DS3) || (PINA & DS4) || (PINA & DS5)))
    {
        navigation.turnRightContourner();
    }
    navigation.stopMotor();
    _delay_ms(ONE_SECOND);
}

void fonctionRobot::end()
{
    navigation.stopMotor();
    _delay_ms(ONE_SECOND);
    while (!((PINA & DS1) && (PINA & DS2)))
    {
        navigation.turnLeft180();
        compteur2++;
    }
    navigation.stopMotor();
    _delay_ms(ONE_SECOND);
}

void fonctionRobot::end2()
{
    do
    {
        suiveurLigne.moveRobot();
        compteur++;
    } while (!((PINA & DS5) && (PINA & DS4) && (PINA & DS3)));
    suiveurLigne.moveRobotRight();
}

void fonctionRobot::turnRightUntilLine(){
    suiveurLigne.moveRobotRight();
            while (true)
            {
                if ((PINA & DS4) || (PINA & DS3))
                {
                    navigation.stopMotor();
                    _delay_ms(ONE_SECOND);
                    break;
                }
            }
}

void fonctionRobot::goLevelWall(){
    do
        {
            suiveurLigne.moveRobot();
            compteur--;
        } while (compteur != 0);
        do
        {
            suiveurLigne.moveRobot(); 
            compteur2--;
        } while (compteur2 != 0);

}