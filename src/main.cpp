#include "DieuKhienPs2.h"
// for change Mode
int servoVal = 0;

void setup() {
    Serial.begin(115200);
    Serial3.begin(230400);
    setupPs2();
    setNangHa();
    toiTrangVaXanhDefine();
    defineGocBan();
    defineGapVong();
    defineDimmer();
}
void loop() {
    // turningLevelSpeed();
    Serial.println("thishhhhh");
    ps2ReadRepeat();
    enableToi();
    enableFire();
    // // Mode 1
    changingGrab();
    enableMoving();
    enableChangeDimmer(&servoVal);
    enableGrabRings();
    // // Mode 2
    enableIncreaseAndDecreaseRSpeed();
    ps2ToAdjustAngle();
    enableSlowSpeed();
    // // anyMode
    // enableChangingMode();
    delayForPS2();

}
