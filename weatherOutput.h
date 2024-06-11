#include "sound.h"
#include "led.h"

void weatherOutput(boolean takeUmbrella, boolean takeSunblock, boolean takeMask) {
  //출력 장치 출력
  if (takeUmbrella == true) {
    Serial.println("우산");
    ledRain();
    weatherSound(1);
    ledClearDisplay();
  } else {
    Serial.println("X");
  }

  if (takeSunblock == true) {
    Serial.println("자외선 차단제.");
    ledSun();
    weatherSound(2);
    ledClearDisplay();
  } else {
    Serial.println("X");
  }

  if (takeMask == true) {
    Serial.println("마스크");
    ledDust();
    weatherSound(3);
    ledClearDisplay();
  } else {
    Serial.println("X");
  }
}