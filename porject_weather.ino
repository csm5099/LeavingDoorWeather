#include "getRainAPIUrl.h"
#include "apiRequest.h"
#include "getRainData.h"
#include "isRain.h"

String RainAPIUrl = getRainAPIUrl();

void setup() {
  Serial.begin(9600);
  setup_apiRequest();
}

void loop() {
  String rainAPIUrl = getRainAPIUrl();
  String rainJSON = apiRequest(rainAPIUrl);
  String rainCheck = getRainData(rainJSON);
  boolean takeUmbrella = isRain(rainCheck);
  if(takeUmbrella == true) Serial.println("우산을 챙기세요");
  else Serial.println("비소식이 없어요");
  delay(5000);
}