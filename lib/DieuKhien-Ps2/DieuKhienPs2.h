
#ifndef DieuKhienPs2_h
#define DieuKhienPs2_h
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <Gap.h>
#include <GocBan.h>
#include <Moving.h>
#include <PS2X_lib.h>
#include <TVB.h>
#include <NangHaGap.h>
#include <led.h>

//setup
void setupPs2();
void ps2ReadRepeat();
void delayForPS2();

// for moving
void enableMoving();
// for adjusting angle
void ps2ToAdjustAngle();
// for lifting up and down
void changingGrab();
// for grab rings
void enableGrabRings();
// for toi va ban vong
void enableIncreaseAndDecreaseRSpeed();
void enableToi();
void enableFire();
void turningLevelSpeed();
void enableChangeDimmer(int *servoVal);
void dimmer();
void enableSlowSpeed();
#endif