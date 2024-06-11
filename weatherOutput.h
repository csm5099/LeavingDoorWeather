#include "sound.h"

boolean takeUmbrella = false;
boolean takeSunblock = false;
boolean takeMask = false;

void weatherFunc() {
  boolean takeUmbrella = isRain(apiRequest(getWeatherQuery()));
  boolean takeSunblock = isBurn(apiRequest(getWeatherQuery()));
  boolean takeMask = isDusty(apiRequest(getAirAPIQuery()));

  //출력 장치 출력
  if (takeUmbrella == true) {
    Serial.println("우산");
    weatherSound(1);
  } else {
    Serial.println("X");
  }

  if (takeSunblock == true) {
    Serial.println("자외선 차단제.");
    weatherSound(2);
  } else {
    Serial.println("X");
  }

  if (takeMask == true) {
    Serial.println("마스크");
    weatherSound(3);
  } else {
    Serial.println("X");
  }
}