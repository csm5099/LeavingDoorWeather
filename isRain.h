boolean isRain(String rainCheck){
  if(rainCheck == "null") return NULL;
  if(rainCheck.toInt() >= 1 && rainCheck.toInt() <= 4 ){
    return true;
  }else if(rainCheck.toInt() == 0){
    return false;
  }else{
    return NULL;
  }
}