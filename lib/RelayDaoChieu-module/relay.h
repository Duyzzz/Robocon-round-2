#ifndef relay_h
#define relay_h
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


class Relay{
    private:
        int8_t UpPin;
        int8_t DownPin;
    public:
        Relay(int8_t upPin, int8_t downPin);
        void setUpPin();
        void relayUp();
        void relayDown();
        void relayStop();
};

#endif