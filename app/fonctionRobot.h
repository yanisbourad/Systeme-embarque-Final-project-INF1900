#ifndef F_CPU
#define F_CPU 8000000
#endif
#define __DELAY_BACKWARD_COMPATIBLE__
#define DEMO_DDR DDRC
#define DEMO_PORT PORTC
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include <Navigation.h>
#include "Del.h"
#include "can.h"
#include <PushButton.h>
#include <Motor.h>
#include <Timer0.h>
#include <Timer1.h>
#include <Note.h>
#include "LSS05.h"
#include "GP2D12.h"
#include "customprocs.h"
#include "lcm_so1602dtr_m_fw.h"

class fonctionRobot
{
public:
    fonctionRobot();
    ~fonctionRobot();
    void toGo();
    void getBC();
    uint8_t getDistance();
    void prepareToWait();
    void makeTurn180();
    void triangle();
    void BG();
    void turnLeftUntilLine();
    void goAround();
    void end();
    void end2();
    void turnRightUntilLine();
    void goLevelWall();
    
private:
    PushButton button();
    Del del; 
    LSS05 suiveurLigne;
    Navigation navigation;
    GP2D12 capteurDistance;
    Timer1 timer1;
    Note note;
    const uint8_t             DS1 = 0x01;
    const uint8_t             DS2 = 0x02;
    const uint8_t             DS3 = 0x04;
    const uint8_t             DS4 = 0x08;
    const uint8_t             DS5 = 0x10;
    const int          TWO_SECOND = 2000;
    const int          ONE_SECOND = 1000;
    const int      TIME_ONE_CYCLE = 7812;
    const int         HALF_SECOND = 500;
    const int        FIFTH_SECOND = 200;
    int                  compteur = 0;
    int                 compteur2 = 0;
    int           counterTriangle = 0;
    uint8_t              numValue = 0;

};
