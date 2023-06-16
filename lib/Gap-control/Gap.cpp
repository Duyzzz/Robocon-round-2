
#include <PS2X_lib.h>

#include "Gap.h"
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
Relay grab(2, 25); 
void defineGapVong(){
    grab.setUpPin();
}
void gapVong(){
    grab.relayUp();
    Serial.println("gapVong");
}
void nhaVong(){
    grab.relayDown();
    Serial.println("nhaVong");
}
void disableGrab(){
    grab.relayStop();
    Serial.println("disableGrab");
}