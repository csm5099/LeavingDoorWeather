#include <ArduinoJson.h>

String getRainData(String rainJson){
  JsonDocument doc;
  deserializeJson(doc, rainJson);

  String rain = doc["response"]["body"]["items"]["item"][6]["fcstValue"];
  return rain;
}
/*
https://jsonviewer.stack.hu/
*/