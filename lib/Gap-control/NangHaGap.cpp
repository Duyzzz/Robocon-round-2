#include <PS2X_lib.h>

#include "NangHaGap.h"
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <avr/io.h>
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

Relay motorNangHaGap(17, 16); // TODO: Modify this
void setNangHa(){
    motorNangHaGap.setUpPin();
}
void nangGap(){
    motorNangHaGap.relayUp();
}
void haGap(){
    motorNangHaGap.relayDown();
}
void disableGrabMove(){
    motorNangHaGap.relayStop();
}