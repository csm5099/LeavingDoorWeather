#include "apiRequest.h"
#include "getWeatherAPIQuery.h"
#include "connectWifi.h"
#include "isWeather.h"
#include "weatherOutput.h"

void setup() {
  Serial.begin(9600);
  connectWifi();
}

void loop() {
  weatherFunc();
  delay(5000);
}