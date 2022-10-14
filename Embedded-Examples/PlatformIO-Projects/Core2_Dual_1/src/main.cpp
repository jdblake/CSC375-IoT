#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) ;
  Serial.print("setup() running on core ");
  Serial.println(xPortGetCoreID());
}

void loop() {
  Serial.print("loop() running on core ");
  Serial.println(xPortGetCoreID());
  delay(3000);
}