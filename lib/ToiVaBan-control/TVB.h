#ifndef TVB_h
#define TVB_h
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "relay.h"
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "PID.h"

void defineDimmer();
void pullBack();
void keepDimmer(int *dimVal);
void stopPull();
void keepFire(short fireSpeed);
void increaseFireSpeed(short *fireSpeed);
void decreaseFireSpeed(short *fireSpeed);
void keepRange(short *fireSpeed);
void toiXanhWork(short fireSpeed);
void toiTrangVaXanhDefine();
void toiTrangPullUp();
void increaseDimmer(int *val);
void decreaseDimmer(int *val);
#endif