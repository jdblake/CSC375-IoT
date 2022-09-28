#include <Arduino.h>

#include <U8x8lib.h>
#include <PCF8563.h>
PCF8563 pcf;
#include <Wire.h>

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
//U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* clock=*/ PIN_WIRE_SCL, /* data=*/ PIN_WIRE_SDA, /* reset=*/ U8X8_PIN_NONE);   // OLEDs without Reset of the Display

void setup() {
  //Serial.begin(115200);
  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);   // choose a suitable font
  //u8x8.setFlipMode(1);
  Wire.begin();
  /*
  pcf.init();//initialize the clock
  pcf.stopClock();//stop the clock
  pcf.setYear(22);//set year
  pcf.setMonth(06);//set month
  pcf.setDay(20);//set dat
  pcf.setHour(13);//set hour
  pcf.setMinut(30);//set minut
  pcf.setSecond(0);//set second
  pcf.startClock();//start the clock
  */
}

void loop() {
  Time nowTime = pcf.getTime();//get current time

  u8x8.setCursor(0, 0);
  u8x8.print(nowTime.day);
  u8x8.print("/");
  u8x8.print(nowTime.month);
  u8x8.print("/");
  u8x8.print("20");
  u8x8.print(nowTime.year);
  u8x8.setCursor(0, 1);
  u8x8.print(nowTime.hour);
  u8x8.print(":");
  u8x8.print(nowTime.minute);
  u8x8.print(":");
  u8x8.print(nowTime.second);
  delay(1000);
}
