#include <Arduino.h>
 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  //while (!Serial);
}
 
void loop() {
  delay(1000);
  Serial.println("ON");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  Serial.println("OFF");
  digitalWrite(LED_BUILTIN, LOW);
}