#include "relay.h"
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


Relay :: Relay(int8_t upPin, int8_t downPin){
    UpPin = upPin;
    DownPin = downPin;
}
void Relay:: setUpPin(){
    pinMode(UpPin, OUTPUT);
    pinMode(DownPin, OUTPUT);
    digitalWrite(UpPin, HIGH);
    digitalWrite(DownPin, HIGH);
}
void Relay :: relayUp(){
    digitalWrite(UpPin, LOW);
    digitalWrite(DownPin, HIGH);
}
void Relay :: relayDown(){
    digitalWrite(DownPin, LOW);
    digitalWrite(UpPin, HIGH);
}
void Relay :: relayStop(){
    digitalWrite(UpPin, HIGH);
    digitalWrite(DownPin, HIGH);
}
