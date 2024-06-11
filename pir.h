int pirPin = 3;

bool pirSensor() {
  pinMode(pirPin, INPUT);
  int pirValue = digitalRead(pirPin);

  if (pirValue == HIGH) return true;
  else return false;
}