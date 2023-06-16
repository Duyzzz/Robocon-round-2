


#include <PS2X_lib.h>

#include "GocBan.h"
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

Relay motorGocBan(3, 23); // TODO: modify
void defineGocBan(){
    motorGocBan.setUpPin();
}
void increaseAngle(){
    motorGocBan.relayUp();
}
void decreaseAngle(){
    motorGocBan.relayDown();
}
void stopAdjustingAngle(){
    motorGocBan.relayStop();
}
