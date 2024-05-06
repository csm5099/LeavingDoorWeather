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
  rainFunc();
  delay(5000);
}

void rainFunc(){
  // api url 생성
  String rainAPIUrl = getRainAPIUrl();

  // api 요청
  String rainJSON = apiRequest(rainAPIUrl);
  
  // api 데이터 수집
  String rainCheck = getRainData(rainJSON);
  
  // 장치 출력
  boolean takeUmbrella = isRain(rainCheck);
  
  // 
  if(takeUmbrella == true) Serial.println("우산을 챙기세요");
  else Serial.println("비소식이 없어요");
}