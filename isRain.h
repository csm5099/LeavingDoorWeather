#include <ArduinoJson.h>

boolean isRain(String rainJson){

  //JSOn 파일 복사와 함께 디시리얼라이즈를 한다.
  JsonDocument doc;
  deserializeJson(doc, rainJson);

  //현 시간부터 12시간 까지 날씨 중 비와 눈 소식을 찾는다.
  for(int i = 0; i++; i <= 12){
    String weather = doc["hourly"][i]["weather"][0]["main"];
    //비,눈 소식이 있으면 1, 아니면 0
    if(weather == "Rain" || weather == "Snow") return true;
  }
  return false;
}
/*
JSON pretty print
https://jsonviewer.stack.hu/

ArduinoJson Assistant
https://arduinojson.org/v7/assistant/#/step1
*/