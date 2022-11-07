void setup() {
  pinMode(27, INPUT_PULLUP);
  pinMode(2, OUTPUT);
}

void loop() {
  int sensorVal = digitalRead(27);
  if (sensorVal == HIGH) {
    digitalWrite(2, LOW);
  } else {
    digitalWrite(2, HIGH);
  }
}
