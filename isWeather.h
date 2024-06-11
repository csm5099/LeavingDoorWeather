#include <ArduinoJson.h>

boolean isRain(String textJson) {

  //JSOn 파일 복사와 함께 디시리얼라이즈를 한다.
  JsonDocument doc;
  deserializeJson(doc, textJson);

  //현 시간부터 12시간 까지 날씨 중 비와 눈 소식을 찾는다.
  for (int i = 0; i <= 12; i++) {
    String weather = doc["hourly"][i]["weather"][0]["main"];
    // Serial.print(weather);
    // Serial.print(",");
    //비,눈 소식이 있으면 1, 아니면 0
    Serial.print(weather);

    if (weather == "Rain" || weather == "Snow") return true;
  }
  return false;
}

boolean isBurn(String textJson) {

  //JSOn 파일 복사와 함께 디시리얼라이즈를 한다.
  JsonDocument doc;
  deserializeJson(doc, textJson);

  float maxUvRate = doc["hourly"][0]["uvi"];

  //현 시간부터 12시간 까지 날씨 중 비와 눈 소식을 찾는다.
  for (int i = 0; i <= 12; i++) {
    float uvRate = doc["hourly"][i]["uvi"];
    // Serial.println(uvRate);
    //가장 높은 자외선 수치 계산
    if (maxUvRate < uvRate) {
      maxUvRate = uvRate;
    }
  }
  Serial.println("");
  Serial.print("maxUvRate : ");
  Serial.println(maxUvRate);
  //자외선이 강하면 true, 아니면 false
  if (maxUvRate >= 6) return true;
  else return false;
}

boolean isDusty(String textJson) {

  //JSOn 파일 복사와 함께 디시리얼라이즈를 한다.
  JsonDocument doc;
  deserializeJson(doc, textJson);

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
  Serial.print("maxPm10 : ");
  Serial.print(maxPm10);
  Serial.print(" / maxPm2_5 : ");
  Serial.println(maxPm2_5);
  if (maxPm10 >= 81 || maxPm2_5 >= 36) return true;
  else return false;
}

/*
JSON pretty print
https://jsonviewer.stack.hu/

ArduinoJson Assistant
https://arduinojson.org/v7/assistant/#/step1
*/