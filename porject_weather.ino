#include "getRainAPIUrl.h"
#include "apiRequest.h"
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

  // api 요청 후 데이터 수집
  String rainJSON = apiRequest(rainAPIUrl);
  Serial.println(rainAPIUrl);
  
  //데이터 가공, 비와 눈 소식 필터링
  boolean takeUmbrella = isRain(rainJSON);
  
  // 출력 장치 출력
  if(takeUmbrella == true) Serial.println("우산을 챙기세요");
  else Serial.println("비소식이 없어요");
}