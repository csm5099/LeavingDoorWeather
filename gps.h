#include <TinyGPS.h>
#include <SoftwareSerial.h>

//한국
// float flat = 37;
// float flon = 127;

//중국
float flat = 31;
float flon = 121;

//미국
// float flat = 40;
// float flon = -73;

//호주
// float flat = -27;
// float flon = 153;

//

String getLat() {
  return String(flat);
}
String getLon() {
  return String(flon);
}

// void getLocation() {
//   TinyGPS gps;
//   SoftwareSerial ss(4, 3);
//   ss.begin(9600);

//   bool newData = false;
//   unsigned long chars;
//   unsigned short sentences, failed;

//   for (unsigned long start = millis(); millis() - start < 1000;) {
//     while (ss.available()) {
//       char c = ss.read();
//       // Serial.write(c); // uncomment this line if you want to see the GPS data flowing
//       if (gps.encode(c))  // Did a new valid sentence come in?
//         newData = true;
//     }
//   }

//   if (newData) {
//     unsigned long age;
//     gps.f_get_position(&flat, &flon, &age);
//     Serial.print("LAT=");
//     Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
//     Serial.print(" LON=");
//     Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
//   }
// }