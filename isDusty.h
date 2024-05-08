#include <ArduinoJson.h>

boolean isDusty(String rainJson) {

  //JSOn 파일 복사와 함께 디시리얼라이즈를 한다.
  JsonDocument doc;
  deserializeJson(doc, rainJson);

  float maxPm10 = doc["list"][0]["components"]["pm10"];
  float maxPm2_5 = doc["list"][0]["components"]["pm2_5"];

  //현 시간 공기 오염도를 측정한다.
  for (int i = 0; i <= 12; i++) {
    float pm10Rate = doc["list"][i]["components"]["pm10"];
    float pm2_5Rate = doc["list"][i]["components"]["pm2_5"];

    //가장 높은 수치를 판별
    if (maxPm10 < pm10Rate) maxPm10 = pm10Rate;
    if (maxPm2_5 < pm2_5Rate) maxPm2_5 = pm2_5Rate;
  }
  if (maxPm10 >= 81 || maxPm2_5 >= 36) return true;
  else return false;
}
/*
JSON pretty print
https://jsonviewer.stack.hu/

ArduinoJson Assistant
https://arduinojson.org/v7/assistant/#/step1
*/