#include <Arduino.h>

#include <M5Core2.h>

void vibration(int t) {
  M5.Axp.SetLDOEnable(3, true);
  delay(t);
  M5.Axp.SetLDOEnable(3, false);
}

void setup() {

  M5.begin();

/*
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setRotation(2);
  M5.Lcd.setCursor(130, 42);
  M5.Lcd.printf("2000ms");
  M5.Lcd.setCursor(130, 150);
  M5.Lcd.printf("1000ms");
  M5.Lcd.setCursor(150, 255);
  M5.Lcd.printf("500ms");
  delay(1000);
  */

}

void loop() {
  M5.update();
  if(M5.BtnA.wasPressed()) {
    Serial.println("A");
    vibration(500);
  }
  
  if(M5.BtnB.wasPressed()) {
    Serial.println("B");
    vibration(1000);
  }
  
  if(M5.BtnC.wasPressed()) {
    Serial.println("C");
    vibration(2000);
  }

}