#include <ArduinoJson.h>

boolean isBurn(String rainJson) {

  //JSOn 파일 복사와 함께 디시리얼라이즈를 한다.
  JsonDocument doc;
  deserializeJson(doc, rainJson);

  float maxUvRate = doc["hourly"][0]["uvi"];

  //현 시간부터 12시간 까지 날씨 중 비와 눈 소식을 찾는다.
  for (int i = 0; i <= 12; i++) {
    float uvRate = doc["hourly"][i]["uvi"];

    //자외선이 없으면 컨티뉴
    if (uvRate == 0) continue;

    //가장 높은 자외선 수치 계산
    if (maxUvRate < uvRate) {
      maxUvRate = uvRate;
    }
  }
  Serial.print(maxUvRate);

  //자외선이 강하면 true, 아니면 false
  if (maxUvRate >= 6) return true;
  else return false;
}
/*
JSON pretty print
https://jsonviewer.stack.hu/

ArduinoJson Assistant
https://arduinojson.org/v7/assistant/#/step1
*/