#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <avr/io.h>
#include "DieuKhienPs2.h"
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif
char Mode = 1;
PS2X ps2x;
int error = 0;
byte vibrate = 0;
bool trashStatus;
short fireSpeed = 0;
unsigned long timeEnableSend = micros();
char speedLevel = 1;
int speedLevelValue[3] = {30, 80};
short eSpeed = speedLevelValue[1];
const char congTacNangGoc = 6;
bool slowSpeed = false;
const char congTacMang = 5;
char soHienThi = 0;
int dimmerVal = 0;
void setupPs2(){
    error = ps2x.config_gamepad(53, 49, 51, 47, true, true);
    eSpeed = speedLevelValue[speedLevel]; // normal Speed
    pinMode(congTacMang, INPUT_PULLUP);
    pinMode(congTacNangGoc, INPUT_PULLUP);
    setupLedPin();
    defineDimmer();
}

void ps2ReadRepeat(){
    ps2x.read_gamepad(false, vibrate);
    eSpeed = speedLevelValue[speedLevel];
}

void delayForPS2(){
    delay(20);
}
void enableSlowSpeed(){
    if(ps2x.ButtonPressed(PSB_SELECT)){
        slowSpeed = !slowSpeed;
    }
    if(slowSpeed){
        eSpeed = 30;
    }
}

void enableMoving(){
        if(ps2x.Analog(PSS_RX) < 103 && (micros() - timeEnableSend > 500)){
            Serial.println("Left");
            moveLeft(eSpeed);
            timeEnableSend = micros();
            trashStatus = true;
            if(ps2x.Button(PSB_R3)){
                moveLeft(200);
            }
        }
        else if(ps2x.Analog(PSS_LY) <103 && (micros() - timeEnableSend > 500)){
            moveForward(eSpeed);
            Serial.println("up");
            timeEnableSend = micros();
            trashStatus = true;
            if(ps2x.Button(PSB_L3)){
                moveForward(200);
            }
        }
        else if(ps2x.Analog(PSS_LY) > 153  && (micros() - timeEnableSend > 500)){
            Serial.println("down");
            moveBackward(eSpeed);
            timeEnableSend = micros();
            trashStatus = true;
            if(ps2x.Button(PSB_L3)){
                moveBackward(200);
            }
        }
        else if(ps2x.Analog(PSS_RX) > 153 && (micros() - timeEnableSend > 500)){
            Serial.println("right");
            moveRight(eSpeed);
            timeEnableSend = micros();
            trashStatus = true;
            if(ps2x.Button(PSB_R3)){
                moveRight(200);
            }
        }
        else if(ps2x.Button(PSB_L1) && (micros() - timeEnableSend > 500)){
            Serial.println("rotaLeft");
            rotaLeft(eSpeed);
            timeEnableSend = micros();
            trashStatus = true;
        }
        else if (ps2x.Button(PSB_R1) && (micros() - timeEnableSend > 500)){
            Serial.println("rotaRight");
            rotaRight(eSpeed);
            timeEnableSend = micros();
            trashStatus = true;
        }
        else if(trashStatus){
            Serial.println("stop Moving");
            rotaRight(0);
            timeEnableSend = micros();
            trashStatus = false;
        }

}
// dieu khien nang ha goc ban
void ps2ToAdjustAngle(){
    if(1){
        if(ps2x.Button(PSB_PAD_RIGHT) && digitalRead(congTacNangGoc)){
            increaseAngle();
            Serial.println("increasing fire angle");
        } else if(ps2x.Button(PSB_PAD_LEFT)){
            Serial.println("decreasing fire angle");
            decreaseAngle();
        } else {
            stopAdjustingAngle();
        }
    }
}

void changingGrab(){
    if(ps2x.Button(PSB_GREEN) && digitalRead(5)){
        nangGap();
        Serial.println("Nang gap");
    } else if(ps2x.Button(PSB_BLUE)){
        Serial.println("Ha gap");
        haGap();
    }else {
        disableGrabMove();
    }
}
void enableGrabRings(){
    if(Mode == 1 && ps2x.Button(PSB_PINK)){
        gapVong();
        Serial.println("Gap Vong");
    }
    else if(Mode == 1 && ps2x.Button(PSB_RED)){
        Serial.println("Mo vong");
        nhaVong();
    } else {
        disableGrab();
    }
}

void enableIncreaseAndDecreaseRSpeed(){
    if(Mode == 2 && ps2x.ButtonPressed(PSB_L2)){
        eSpeed = eSpeed + 10;
    } else if(Mode == 2 && ps2x.ButtonPressed(PSB_R2)){
        eSpeed = eSpeed - 10;
    }
    if(eSpeed > 253) eSpeed = 250;
    if(eSpeed <= 0) eSpeed = 0;
}
void enableChangeDimmer(int *dimmer){
    if(ps2x.ButtonPressed(PSB_L2)){
        increaseDimmer(dimmerVal);
    } else if(ps2x.ButtonPressed(PSB_R2)){
        decreaseDimmer(dimmerVal);
    }
}
void holdingDimmer(){
    keepDimmer();
}
void enableToi(){
    if(ps2x.Button(PSB_PAD_UP)){
        toiTrangPullUp();
    } else if(ps2x.Button(PSB_PAD_DOWN)){
        pullBack();
    } else {
        stopPull();
    }
    toiXanhWork(fireSpeed);
}

void enableFire(){
    keepFire(fireSpeed);
}