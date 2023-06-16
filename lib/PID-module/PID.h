

#ifndef PID_h
#define PID_h
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


const char UP = 1;
const char DOWN = 0;
class PID {
    public: 
        int8_t Address;
        PID(int8_t address);
        void sendDirectionAndSpeed(int8_t direction, int8_t speed);
};




#endif