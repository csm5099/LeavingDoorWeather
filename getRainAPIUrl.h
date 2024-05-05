String getRainAuthKey(){
  return "5TcF7qd9Ty23Be6nfS8tPA";
}
String getDataType(){
  return "JSON";
}
String getDate(){
  return "20240504";
}
String getTime(){
  return "0500";
}
String getNX(){
  return "37";
}
String getNY(){
  return "127";
}

String getRainAPIUrl(){
  String rainAuthKey = getRainAuthKey();
  String dataType = getDataType();
  String baseDate = getDate();
  String baseTime = getTime();
  String nx = getNX();
  String ny = getNY();

  String apiUrl = "http://apihub.kma.go.kr/api/typ02/openApi/VilageFcstInfoService_2.0/getVilageFcst";
  apiUrl += "?authKey=" + rainAuthKey;
  apiUrl += "&numOfRows=10";
  apiUrl += "&pageNo=1";
  apiUrl += "&dataType=" + dataType;
  apiUrl += "&base_date=" + baseDate;
  apiUrl += "&base_time=" + baseTime;
  apiUrl += "&nx=" + nx;
  apiUrl += "&ny=" + ny;

  return apiUrl;
}