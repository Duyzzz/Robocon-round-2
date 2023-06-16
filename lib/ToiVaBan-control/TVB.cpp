
#include "Servo.h"
#include "TVB.h"
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
Relay toiTrang(21, 31); //TODO: modify
Relay toiXanh(33, 20);
PID fireRateLeft(5);
PID fireRateRight(6); 
bool fireWork = true;
unsigned char dimmerValue = 0;
unsigned long timeHold = micros();
Servo myServo;
void defineDimmer(){
    myServo.attach(12);
    myServo.write(0);
}
void increaseDimmer(int * dimmerValue){
    *dimmerValue = *dimmerValue + 5;
    if(*dimmerValue <= 0) *dimmerValue = 0;
    if(*dimmerValue >= 180) *dimmerValue = 180;
}
void keepDimmer(int *dimVal) {
    myServo.write(*dimVal);
}
void decreaseDimmer(int *dimmerValue) {
    *dimmerValue = *dimmerValue - 5;
    if(*dimmerValue <= 0) *dimmerValue = 0;
    if(*dimmerValue >= 180) *dimmerValue = 180;
}
void toiTrangPullUp(){
    toiTrang.relayDown();
}
void toiTrangVaXanhDefine(){
    toiTrang.setUpPin();
    toiXanh.setUpPin();
}
void pullBack(){
    toiTrang.relayUp(); // TODO: modify
}
void stopPull(){
    toiTrang.relayStop();
}
void toiXanhWork(short fireSpeed){
    if(fireSpeed > 0){
        toiXanh.relayDown();
    }else {
        toiXanh.relayStop();
    }
}

void keepFire(short fireSpeed){
    if(micros() - timeHold > 500){
        fireRateLeft.sendDirectionAndSpeed(1, fireSpeed);
        fireRateRight.sendDirectionAndSpeed(1, fireSpeed);
        timeHold = micros();
    }
}
void increaseFireSpeed(short *fireSpeed){
    *fireSpeed = *fireSpeed + 5;
}
void decreaseFireSpeed(short *fireSpeed){
    *fireSpeed = *fireSpeed - 5;
}
void keepRange(short *fireSpeed){
    if(*fireSpeed > 250) *fireSpeed = 250;
    if(*fireSpeed <= 0) *fireSpeed = 0;
}
