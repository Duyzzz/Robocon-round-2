
#ifndef GocBan_h
#define GocBan_h
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "relay.h"

void increaseAngle();
void decreaseAngle();
void stopAdjustingAngle();
void defineGocBan();
#endif