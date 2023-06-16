#include "led.h"
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

//--------------------------------------------cac bien
const int so[]={0xc0,0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90,
                0x40,0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
const char chan[]={A9,A10,A11,A12,A13,A14, 26, 9};

//--------------------------------------------hàm chính
void hienthiso(int number)
{
  for(int i=0; i < 8; i++) 
  {
    int Bit;
    Bit = bitRead(so[number], i);
    digitalWrite(chan[i], Bit);
  }

}
void setupLedPin() 
{
  for(int i=0;i<8;i++)
  {
    pinMode(chan[i],OUTPUT);
  }
}
