#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

void setup_apiRequest(){
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("wifi", "50995099");
  Serial.println(WiFiMulti.run());
  
}

void apiRequest(String apiUrl){
  if ((WiFiMulti.run() == WL_CONNECTED)) { //Check the current connection status
    Serial.println("Starting connection to server...");

    WiFiClient client;
    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    
    if (http.begin(client, apiUrl)) {  // HTTP

      Serial.print("[HTTP] GET...\n");
    
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.println("[HTTP] Unable to connect");
    }

    http.end(); //Free the resources
  } else {
    Serial.println("[HTTP] Unable to connect");
  }
}