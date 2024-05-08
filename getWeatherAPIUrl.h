#include "gps.h"

//openweathermap
String getAuthKey(){
  return "c83a5af0e2aac2e215efa3230ba1dfa7";
}
String getExcludeData(){
  return "current,daily";
}

String getWeatherAPIUrl(){
  String AuthKey = getAuthKey();
  String lat = getLat();
  String lon = getLon();
  String excludeData = getExcludeData();

  String apiUrl = "http://api.openweathermap.org/data/3.0/onecall";
  apiUrl += "?lat=" + lat;
  apiUrl += "&lon=" + lon;
  apiUrl += "&exclude=" + excludeData;
  apiUrl += "&appid=" + AuthKey;

  return apiUrl;
}

String getAirAPIUrl(){
  String AuthKey = getAuthKey();
  String lat = getLat();
  String lon = getLon();
  
  String apiUrl = "http://api.openweathermap.org/data/2.5/air_pollution/forecast";
  apiUrl += "?lat=" + lat;
  apiUrl += "&lon=" + lon;
  apiUrl += "&appid=" + AuthKey;

  return apiUrl;
}