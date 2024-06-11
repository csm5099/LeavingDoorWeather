#include "gps.h"

//openweathermap
String getExcludeData() {
  return "current,minutely,daily,alerts";
}
String getApiKey() {
  return "c83a5af0e2aac2e215efa3230ba1dfa7";
}
String getWeatherEndpoint() {
  return "/data/3.0/onecall";
}
String getAirEndpoint() {
  return "/data/2.5/air_pollution/forecast";
}

String getWeatherQuery() {

  String endpoint = getWeatherEndpoint();

  String weatherQuery = "";
  weatherQuery += "?lat=" + getLat();
  weatherQuery += "&lon=" + getLon();
  weatherQuery += "&exclude=" + getExcludeData();
  weatherQuery += "&appid=" + getApiKey();

  return endpoint + weatherQuery;
}

String getAirAPIQuery() {

  String endpoint = getAirEndpoint();

  String airQuery = "";
  airQuery += "?lat=" + getLat();
  airQuery += "&lon=" + getLon();
  airQuery += "&appid=" + getApiKey();

  return endpoint + airQuery;
}