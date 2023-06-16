#include <PS2X_lib.h>
#include "Moving.h"
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <avr/io.h>
#include <PID.h>

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif
unsigned long testTime; // FIXME define a new test 


PID topLeft(1);
PID topRight(2);
PID bottomLeft(3);
PID bottomRight(4);
// 2 động cơ phải bị ngược
void moveForward(short speed){
    topLeft.sendDirectionAndSpeed(UP, speed + 10);
    topRight.sendDirectionAndSpeed(UP, speed - 15);
    bottomLeft.sendDirectionAndSpeed(UP, speed);
    bottomRight.sendDirectionAndSpeed(DOWN, speed);
}

void moveBackward(short speed){
    topLeft.sendDirectionAndSpeed(DOWN, speed + 10);
    topRight.sendDirectionAndSpeed(DOWN, speed - 10);
    bottomLeft.sendDirectionAndSpeed(DOWN, speed);
    bottomRight.sendDirectionAndSpeed(UP, speed);
}

void moveLeft(short speed){
    topLeft.sendDirectionAndSpeed(DOWN, speed + 10);
    topRight.sendDirectionAndSpeed(UP, speed - 10);
    bottomLeft.sendDirectionAndSpeed(UP, speed);
    bottomRight.sendDirectionAndSpeed(UP, speed);
}

void moveRight(short speed){
    topLeft.sendDirectionAndSpeed(UP, speed + 10);
    topRight.sendDirectionAndSpeed(DOWN, speed - 10);
    bottomLeft.sendDirectionAndSpeed(DOWN, speed);
    bottomRight.sendDirectionAndSpeed(DOWN, speed);
}

void rotaLeft(short speed){
    topLeft.sendDirectionAndSpeed(DOWN, speed);
    topRight.sendDirectionAndSpeed(UP, speed);
    bottomLeft.sendDirectionAndSpeed(DOWN, speed);
    bottomRight.sendDirectionAndSpeed(DOWN, speed);
}

void rotaRight(short speed){
    topLeft.sendDirectionAndSpeed(UP, speed);
    topRight.sendDirectionAndSpeed(DOWN, speed);
    bottomLeft.sendDirectionAndSpeed(UP, speed);
    bottomRight.sendDirectionAndSpeed(UP, speed);
}
