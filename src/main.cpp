#include "Avatar.h"  // https://github.com/meganetaaan/m5stack-avatar

using namespace m5avatar;
Avatar avatar;

uint32_t mouth_wait = 2000;  // 通常時のセリフ入れ替え時間（msec）
uint32_t last_mouth_millis = 0;

void setup(void) {
    M5.begin();
    avatar.init();
    avatar.setScale(0.5);
}

void loop(void) {
    M5.update();
    if ((millis() - last_mouth_millis) > mouth_wait) {
        avatar.setMouthOpenRatio(0.7);
        delay(200);
        avatar.setMouthOpenRatio(0.0);
        last_mouth_millis = millis();
    }
}