#include "apiRequest.h"
#include "getWeatherAPIQuery.h"
#include "connectWifi.h"
#include "isWeather.h"
#include "weatherOutput.h"
#include "pir.h"
#include "enter.h"

boolean takeUmbrella = false;
boolean takeSunblock = false;
boolean takeMask = false;

int weatherInfoLimit = 0;  //30분 쿨타임
void setup() {
  Serial.begin(9600);
  // pir인풋센서 인풋
  connectWifi();
}

void loop() {
  if (pirSensor() == true) {
    if (enter() == true) {
      weatherOutput(takeUmbrella, takeSunblock, takeMask);
      delay(5000);
    }
  }

  if (weatherInfoLimit == 0) {
    takeUmbrella = isRain(apiRequest(getWeatherQuery()));
    takeSunblock = isBurn(apiRequest(getWeatherQuery()));
    takeMask = isDusty(apiRequest(getAirAPIQuery()));
    weatherInfoLimit = 9000;
  }
  weatherInfoLimit -= 1;
  Serial.println(weatherInfoLimit);
  delay(200);
}