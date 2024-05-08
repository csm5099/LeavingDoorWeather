#include "apiRequest.h"
#include "getWeatherAPIUrl.h"
#include "isRain.h"
#include "isBurn.h"

void setup() {
  Serial.begin(9600);
  setup_apiRequest();
}

void loop() {
  rainFunc();
  uvFunc();
  delay(5000);
}

void rainFunc(){
  // api url 생성
  String rainAPIUrl = getWeatherAPIUrl();

  // api 요청 후 데이터 수집
  String rainJSON = apiRequest(rainAPIUrl);
  
  //데이터 가공, 비와 눈 소식 필터링
  boolean takeUmbrella = isRain(rainJSON);
  
  // 출력 장치 출력
  if(takeUmbrella == true) Serial.println("우산을 챙기세요");
  else Serial.println("비소식이 없어요");
}

void uvFunc(){
  // api url 생성
  String uvAPIUrl = getWeatherAPIUrl();

  // api 요청 후 데이터 수집
  String uvJSON = apiRequest(uvAPIUrl);
  
  //데이터 가공 자외선 수치 필터링
  boolean takeSunblock = isBurn(uvJSON);

  //출력 장치 출력
  if(takeSunblock == true) Serial.println("Put sunblock on!");
  else Serial.print("It's fine to skip putting sunblock on.");
}