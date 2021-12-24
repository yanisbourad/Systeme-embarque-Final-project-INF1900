#include "Navigation.h"


Navigation::Navigation(){
    // On set les ports de direction de chaque roue 
    // PIN4 pour la gauche et PIN5 pour le droite
    PORTD |= 0 << PINFOUR | 0 << PINFIVE ; 
}

Navigation::~Navigation(){}

void Navigation::setDirection(bool direction){
   currentDirection = direction;
}

bool Navigation::getDirection(){
    return currentDirection;
}

void Navigation::advance(float percentage){
    setDirection(ZERO);
    currentSpeed = percentage ;
    // On met les direction sur les pins 4 et 5
    PORTD = currentDirection << PINFOUR | currentDirection << PINFIVE ;  
    motor.pwmGenerator(currentSpeed - ADVANCEPERCENT, currentSpeed); 
}

void Navigation::turnLeft(){
    setDirection(ZERO);
    // La roue gauche s'arrete et la roue droite avance pour que le robot
    //puisse tourner gauche
    PORTD = currentDirection << PINFOUR | currentDirection << PINFIVE ; 
    motor.pwmGenerator(ZEROPERCENT, TURNPOURCENT_ - LEFTPERCENT);
}

void Navigation::turnLeft90(){
    turnLeft();
    _delay_ms(DELAY_90degrees);
    stopMotor(); 
}

void Navigation::turnRight(){
    setDirection(ZERO);
    // La roue droite s'arrete et la roue gauche avance pour que le robot 
    //puisse tourner droit
    PORTD = !currentDirection << PINFOUR | currentDirection << PINFIVE ; 
    motor.pwmGenerator(TURNPOURCENT_ - RIGHTPERCENT , ZEROPERCENT);
}

void Navigation::turnRight90(){
    turnRight();
    _delay_ms(DELAY_90degrees);
    stopMotor();
}

void Navigation::turnLeft180(){
    setDirection(ZERO);
    // la roue droite, associée au port D4 recule tandis que 
    // la gauche associée au port D5 avance
    PORTD = currentDirection << PINFOUR | !currentDirection << PINFIVE ; 
    motor.pwmGenerator(TURNPOURCENT_- PERCENT_180Degrees, 
    TURNPOURCENT_- PERCENT_180Degrees);
}

void Navigation::turnLeftSlightly(){
    setDirection(ZERO);
    // la roue droite, associée au port D4 avance moins vite 
    // la gauche associée au port D5 avance
    PORTD = currentDirection << PINFOUR | currentDirection << PINFIVE ; 
    motor.pwmGenerator(TURNPOURCENT_ , TURNPOURCENT_ + SLIGHTLYPERCENT);
}

void Navigation::turnLeftMedium(){
    setDirection(ZERO);
    // la roue droite, associée au port D4 avance moins vite 
    // la gauche associée au port D5 avance
    PORTD = currentDirection << PINFOUR | currentDirection << PINFIVE ; 
    motor.pwmGenerator(TURNPOURCENT_ , TURNPOURCENT_ + LEFTMEDIUMPERCENT);
}

void Navigation::turnLeftVery(){
    setDirection(ZERO);
    // la roue droite, associée au port D4 avance moins vite 
    // la gauche associée au port D5 avance
    PORTD = currentDirection << PINFOUR | currentDirection << PINFIVE ; 
    motor.pwmGenerator(TURNPOURCENT_ , TURNPOURCENT_ + LEFT_VERY_PERCENT);
}

void Navigation::turnRightSlightly(){
    setDirection(ZERO);
    // la roue droite, associée au port D4 avance moins vite 
    // la gauche associée au port D5 avance
    PORTD = currentDirection << PINFOUR | currentDirection << PINFIVE ; 
    motor.pwmGenerator(TURNPOURCENT_ + SLIGHTLYPERCENT, TURNPOURCENT_);
}

void Navigation::turnRightMedium(){
    setDirection(ZERO);
    // la roue droite, associée au port D4 avance moins vite 
    // la gauche associée au port D5 avance
    PORTD = currentDirection << PINFOUR | currentDirection << PINFIVE ; 
    motor.pwmGenerator(TURNPOURCENT_ + RIGHTMEDIUMPERCENT, TURNPOURCENT_);
}

void Navigation::turnRightVery(){
    setDirection(ZERO);
    // la roue droite, associée au port D4 avance moins vite 
    // la gauche associée au port D5 avance
    PORTD = currentDirection << PINFOUR | currentDirection << PINFIVE ; 
    motor.pwmGenerator(TURNPOURCENT_ + RIGHT_VERY_PERCENT, TURNPOURCENT_);
}

void Navigation::stopMotor(){
    //on reset les ports de direction
    motor.pwmGenerator(ZERO, ZERO);
    PORTD = 0 << PINFOUR | 0 << PINFIVE; 
}

void Navigation::turnRightContourner(){
    setDirection(ZERO);
    // la roue droite, associée au port D4 avance moins vite 
    // la gauche associée au port D5 avance
    PORTD = currentDirection << PINFOUR | currentDirection << PINFIVE; 
    motor.pwmGenerator(TURNPOURCENT_ + CONTOURNERPERCENT, TURNPOURCENT_);
}
