/*
Code fait par: 
-Arthur Panoyan
-Yanis Bourad
-Abdel Madjid Sant’anna
-Lina Khial
*/
#include "fonctionRobot.h"

enum EtatRobot
{
    BEGIN,
    AB,
    BC,
    WALL_1,
    STOP,
    TURN180,
    TRIANGLE,
    BG,
    YELLOW,
    TRIANGLE_2,
    TRIANGLE_3,
    BF,
    POTEAU,
    POTEAU_2,
    STOP_POTEAU,
    CONTOURNE_POTEAU,
    ED,
    WALL_2,
    LITTLE_ADVANCE_WALL_2,
    STOP_WALL_2,
    END,
    END_2,
    END_3,
    END_4,
    END_5,
};

volatile uint8_t interruptButton = 0;
volatile uint8_t gExpiredTimer = 0;
volatile uint8_t whiteButton = 0;
volatile uint8_t gCount = 0;

ISR(TIMER1_COMPA_vect)
{
    gExpiredTimer = 1;
    gCount++;
}
ISR(INT0_vect) { interruptButton = 1; }
ISR(INT1_vect) { whiteButton = !whiteButton; }

int main()
{
    EtatRobot currentState = BEGIN;
    Del del;
    LSS05 suiveurLigne;
    Navigation navigation;
    Timer1 timer1;
    Note note;
    LCM disp(&DEMO_DDR, &DEMO_PORT);
    fonctionRobot robot;

    const uint8_t             DS1 = 0x01;
    const uint8_t             DS2 = 0x02;
    const uint8_t             DS3 = 0x04;
    const uint8_t             DS4 = 0x08;
    const uint8_t             DS5 = 0x10;
    const int        INCH12_EN_CM = 31;
    const float      COEF_CM_INCH = 2.54;
    const int      FREQUENCY_2000 = 2000;
    const int          TWO_SECOND = 2000;
    const int          ONE_SECOND = 1000;
    const int      TIME_ONE_CYCLE = 7812;
    const int         HALF_SECOND = 500;
    const int        FIFTH_SECOND = 200;
    const int               BC_CM = 36;
    const float          BC_DELAY = 3.20;
    const int         ROBOT_SPEED = BC_CM/BC_DELAY; 
    const int  TimerLittleAdvance = TIME_ONE_CYCLE * 1.5; 
    const uint8_t     INCH12_WALL = 50; 
    const uint8_t   INCH12_POTEAU = 70; 
    const uint8_t   ADVANCE_SPEED = 0.70;
    uint8_t        randomCompteur = 0;

    while (true){
        switch (currentState){
        case BEGIN:
            if (interruptButton == 1){ 
                disp.clear();
                robot.toGo();
                currentState = AB;
            }
            else{
                del.lightRed();
                disp.write("State BEGIN");
                currentState = BEGIN;
            }
            break;

        case AB:
            suiveurLigne.moveRobot();
            if (((PINA & DS3) && (PINA & DS4) && (PINA & DS5))){
                _delay_ms(FIFTH_SECOND);
                currentState = BC;
            }
            break;

        case BC:
            robot.getBC();
            currentState = WALL_1;
            break;

        case WALL_1:
            uint8_t numericValue;
            numericValue = robot.getDistance();
            if (numericValue == INCH12_WALL){
                robot.prepareToWait();
                interruptButton = 0;
                randomCompteur = gCount / 2;
                currentState = STOP;
            }
        
        break;

    case STOP: 
        if (interruptButton == 1){
            timer1.resetTimer1();
            gCount = 0;
            randomCompteur = 0;
            disp.clear();
            robot.toGo();
            robot.makeTurn180();
            currentState = TURN180;
        }
        else{
            del.lightRed();
            if (whiteButton == 0){
                disp.clear();
                disp.write("DISTANCE IN INCH");
                _delay_ms(HALF_SECOND);
                disp << (int)(((randomCompteur * ROBOT_SPEED) + INCH12_EN_CM + BC_CM) / COEF_CM_INCH);
                _delay_ms(HALF_SECOND);
            }

            else{
                disp.clear();
                disp.write("DISTANCE IN CM: ");
                _delay_ms(HALF_SECOND);
                disp << (randomCompteur * ROBOT_SPEED) + INCH12_EN_CM + BC_CM;
                _delay_ms(HALF_SECOND);
            }
        }
        break;

    case TURN180:
        suiveurLigne.moveRobot();
        if (((PINA & DS1) && (PINA & DS2) && (PINA & DS3)) ||
            ((PINA & DS1) && (PINA & DS2) && (PINA & DS3) && (PINA & DS4))){
            suiveurLigne.moveRobot();
            _delay_ms(HALF_SECOND);
            currentState = TRIANGLE;
        }
        break;
        
    case TRIANGLE:
        robot.triangle();
        currentState = BG;
        break;

    case BG:
        robot.BG();
        currentState = YELLOW;
        break;

    case YELLOW:
        navigation.advance(ADVANCE_SPEED);
        if ((PINA & DS1) || (PINA & DS2) || (PINA & DS3) ||
            (PINA & DS4) || (PINA & DS5)){
            navigation.stopMotor();
            _delay_ms(ONE_SECOND);
            currentState = TRIANGLE_2;
        }
        break;

    case TRIANGLE_2:
        suiveurLigne.moveRobot();
        if ((PINA & DS1) && (PINA && DS2) && (PINA & DS3)){
            suiveurLigne.moveRobotLeft();
            currentState = TRIANGLE_3;
        }
        break;

    case TRIANGLE_3:
        suiveurLigne.moveRobot();
        if ((PINA & DS1) && (PINA && DS2) && (PINA & DS3)){
            suiveurLigne.moveRobotLeft();
            currentState = BF;
        }
        break;

    case BF:
        suiveurLigne.moveRobot();
        if ((PINA & DS1) && (PINA & DS2) && (PINA & DS3)){
            robot.turnLeftUntilLine();
            timer1.runTimer1(TIME_ONE_CYCLE);
            currentState = POTEAU;
        }
        break;

    case POTEAU:
        numericValue = robot.getDistance();
        if (numericValue == INCH12_POTEAU){
            robot.prepareToWait();
            randomCompteur = gCount / 2;
            interruptButton = 0;
            currentState = STOP_POTEAU;
        }
        break;

    case STOP_POTEAU:
        if (interruptButton == 1){
            disp.clear();
            timer1.resetTimer1();
            robot.toGo();
            currentState = CONTOURNE_POTEAU;
        }
        else{
            del.lightRed();
            if (whiteButton == 0){
                disp.clear();
                disp.write("DISTANCE IN INCH: ");
                _delay_ms(HALF_SECOND);
                disp << (int)(((randomCompteur * ROBOT_SPEED) + INCH12_EN_CM + BC_CM) / COEF_CM_INCH);
                _delay_ms(HALF_SECOND);
            }
            else{
                disp.clear();
                disp.write("DISTANCE IN CM: ");
                _delay_ms(HALF_SECOND);
                disp << (randomCompteur * ROBOT_SPEED) + INCH12_EN_CM + BC_CM;
                _delay_ms(HALF_SECOND);
            }
        }
        break;
    case CONTOURNE_POTEAU:
        robot.goAround();
        currentState = POTEAU_2;
        break;

    case POTEAU_2:
        suiveurLigne.moveRobot();
        if ((PINA & DS1) && (PINA & DS2) && (PINA & DS3)){
            robot.turnLeftUntilLine();
            currentState = ED;
        }
        break;

    case ED:
        suiveurLigne.moveRobot();
        if ((PINA & DS1) && (PINA & DS2) && (PINA & DS3)){
           robot.turnLeftUntilLine();
            currentState = WALL_2;
        }
        break;

    case WALL_2:
        numericValue = robot.getDistance();
        if (numericValue >= INCH12_POTEAU){
            navigation.stopMotor();
            timer1.resetTimer1();
            gExpiredTimer = 0;
            _delay_ms(TWO_SECOND);
            currentState = LITTLE_ADVANCE_WALL_2;
        }
        break;

    case LITTLE_ADVANCE_WALL_2:
        timer1.runTimer1(TimerLittleAdvance);
        note.playNote(FREQUENCY_2000);
        do{
            suiveurLigne.moveRobot();
        } while (gExpiredTimer == 0);
        interruptButton = 0;
        timer1.resetTimer1();
        gExpiredTimer = 0;
        robot.prepareToWait();
        currentState = STOP_WALL_2;
        break;

    case STOP_WALL_2:
        disp.clear();
        navigation.stopMotor();
        if (interruptButton == 1){
            del.lightGreen();
            disp.clear();
            _delay_ms(TWO_SECOND);
            currentState = END;
        }
        else{
            del.lightRed();
            if (whiteButton == 0){
                disp.clear();
                disp.write("DISTANCE EN POUCE: ");
                disp << 0;
                _delay_ms(HALF_SECOND);
                disp << numericValue;
                _delay_ms(HALF_SECOND);
            }
            else{
                disp.clear();
                disp.write("DISTANCE EN CM: ");
                disp << 0;
                _delay_ms(HALF_SECOND);
                disp << 30;
                _delay_ms(HALF_SECOND);
            }
        }
        break;

    case END:
        robot.end();
        currentState = END_2;
        break;

    case END_2:
        disp.write("STATE END 2");
        robot.end2();
        currentState = END_3;
        break;

    case END_3:

        suiveurLigne.moveRobot();
        if ((PINA & DS5) && (PINA & DS4) && (PINA & DS3)){
            robot.turnRightUntilLine();
            currentState = END_4;
        }
        break;

    case END_4:
        robot.goLevelWall();
        robot.prepareToWait();
        currentState = END_5;
        break;

    case END_5:
        robot.prepareToWait();
        del.lightRed();
        break;
    }
}
}
