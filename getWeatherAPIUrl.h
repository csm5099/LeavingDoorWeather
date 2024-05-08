//openweathermap

String getRainAuthKey(){
  return "c83a5af0e2aac2e215efa3230ba1dfa7";
}
String getExcludeData(){
  return "current,daily";
}
String getNX(){
  return "37";
}
String getNY(){
  return "127";
}

String getWeatherAPIUrl(){
  String rainAuthKey = getRainAuthKey();
  String excludeData = getExcludeData();
  String nx = getNX();
  String ny = getNY();

  String apiUrl = "http://api.openweathermap.org/data/3.0/onecall";
  apiUrl += "?lat=" + nx;
  apiUrl += "&lon=" + ny;
  apiUrl += "&exclude=" + excludeData;
  apiUrl += "&appid=" + rainAuthKey;

  return apiUrl;
}