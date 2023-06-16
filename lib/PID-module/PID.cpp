
#include <PS2X_lib.h>

#include "PID.h"
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


PID :: PID(int8_t address){
    Address = address;
}
void PID :: sendDirectionAndSpeed(int8_t direction, int8_t speed){
    Serial3.write(direction<<7 | Address);
    Serial3.write(speed);
    Serial3.write(0xff);
}