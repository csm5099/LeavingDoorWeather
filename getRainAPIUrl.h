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

String getRainAPIUrl(){
  String rainAuthKey = getRainAuthKey();
  String excludeData = getExcludeData();
  String nx = getNX();
  String ny = getNY();

  // https://api.openweathermap.org/data/3.0/onecall?lat=37&lon=127&exclude=current,daily&appid=c83a5af0e2aac2e215efa3230ba1dfa7
  // https://api.openweathermap.org/data/3.0/onecall?lat=37&lon=127&exclude=current,daily&appid=c83a5af0e2aac2e215efa3230ba1dfa7

  String apiUrl = "https://api.openweathermap.org/data/3.0/onecall";
  apiUrl += "?lat=" + nx;
  apiUrl += "&lon=" + ny;
  apiUrl += "&exclude=" + excludeData;
  apiUrl += "&appid=" + rainAuthKey;

  return apiUrl;
}