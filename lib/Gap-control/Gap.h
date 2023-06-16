#ifndef DongMoGap_h
#define DongMoGap_h
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <relay.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void gapVong();
void nhaVong();
void disableGrab();
void defineGapVong();
#endif