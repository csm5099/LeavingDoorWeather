//openweathermap

String getAuthKey(){
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
  String AuthKey = getAuthKey();
  String nx = getNX();
  String ny = getNY();
  String excludeData = getExcludeData();


  String apiUrl = "http://api.openweathermap.org/data/3.0/onecall";
  apiUrl += "?lat=" + nx;
  apiUrl += "&lon=" + ny;
  apiUrl += "&exclude=" + excludeData;
  apiUrl += "&appid=" + AuthKey;

  return apiUrl;
}

String getAirAPIUrl(){
  String AuthKey = getAuthKey();
  String nx = getNX();
  String ny = getNY();
  
  String apiUrl = "http://api.openweathermap.org/data/2.5/air_pollution/forecast";
  apiUrl += "?lat=" + nx;
  apiUrl += "&lon=" + ny;
  apiUrl += "&appid=" + AuthKey;

  return apiUrl;
}