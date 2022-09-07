#include <Arduino.h>

const int ledPin =  13;
 
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  while (!Serial);
}
 
void loop() {
  delay(100);
  Serial.println("ON");
  digitalWrite(ledPin, HIGH);
  delay(100);
  Serial.println("OFF");
  digitalWrite(ledPin, LOW);
}