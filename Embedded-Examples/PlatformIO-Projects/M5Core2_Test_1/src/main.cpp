#include <Arduino.h>

#include <M5Core2.h>

void setup(){
  Serial.begin(115200);
  M5.begin();
  M5.Lcd.print("Hello World!!");
}

void loop() {
  Serial.println("Hello!");
  delay(1000);
}
