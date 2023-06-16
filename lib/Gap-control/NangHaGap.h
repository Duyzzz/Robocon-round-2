#ifndef NangHaGap_h
#define NangHaGap_h
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

void setNangHa();
void nangGap();
void haGap();
void disableGrabMove();

#endif