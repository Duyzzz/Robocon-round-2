#ifndef Moving_h
#define Moving_h
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>




void moveForward(short speed);
void moveBackward(short speed);
void moveRight(short speed);
void moveLeft(short speed);
void rotaLeft(short speed);
void rotaRight(short speed);





#endif