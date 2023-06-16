

#ifndef LED_h
#define LED_h
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

void hienthiso(int number);
void setupLedPin();
#endif