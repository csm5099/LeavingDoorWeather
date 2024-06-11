int sensorPin = A0;
int sensorValue = 0;

bool enter() {
  pinMode(sensorPin, INPUT);
  sensorValue = analogRead(sensorPin);
  
  // Serial.println(sensorValue);
  if (sensorValue <= 600) {
    Serial.println("Object Off");
    return false;
  } else {
    Serial.println("Object On");
    return true;
  }
}
