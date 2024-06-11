#include <WiFiS3.h>

const char server[] = "api.openweathermap.org";
WiFiClient client;

String apiRequest(String query) {

  //http 통신
  if (client.connect(server, 80)) {
    client.print(String("GET ") + query + " HTTP/1.1\r\n" + "Host: " + server + "\r\n" + "Connection: close\r\n\r\n");
  }

  bool headersReceived = false;
  while (client.connected()) {
    while (client.available()) {
      String line = client.readStringUntil('\n');
      if (!headersReceived) {
        // 헤더 처리
        if (line == "\r") {
          headersReceived = true;
        }
      } else {
        // 본문 처리
        return line;
      }
    }
  }
}