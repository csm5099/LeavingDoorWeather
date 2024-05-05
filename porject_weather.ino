#include "getRainAPIUrl.h"
#include "apiRequest.h"

String RainAPIUrl = getRainAPIUrl();

void setup() {
  Serial.begin(9600);
  setup_apiRequest();
}

void loop() {
  String RainAPIUrl = getRainAPIUrl();
  apiRequest(RainAPIUrl);
  
  delay(5000);
}