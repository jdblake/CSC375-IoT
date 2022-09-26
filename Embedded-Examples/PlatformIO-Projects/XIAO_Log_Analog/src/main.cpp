#include <Arduino.h>

#include <SPI.h>
#include <SD.h>
#include <PCF8563.h>
#include <U8x8lib.h>

PCF8563 rtc;
Time nowTime;
File dataFile;

const int chipSelect = 2;  // SD CS pin

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

// function to return timestamp string
String print_time(Time timestamp) {
  char message[120];

  int Year = timestamp.year;
  int Month = timestamp.month;
  int Day = timestamp.day;
  int Hour = timestamp.hour;
  int Minute = timestamp.minute;
  int Second = timestamp.second;

  sprintf(message, "%d-%d-%d,%02d:%02d:%02d", Month,Day,Year,Hour,Minute,Second);
  
  return message;
}

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  rtc.init();   //initialize RTC

  u8x8.begin();
  u8x8.setFont(u8x8_font_profont29_2x3_r);
  //u8x8.setFont(u8x8_font_chroma48medium8_r);   // choose a suitable font

  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
  
  nowTime = rtc.getTime();   //get current time

  //print current time
  Serial.print(nowTime.day);
  Serial.print("/");
  Serial.print(nowTime.month);
  Serial.print("/");
  Serial.print(nowTime.year);
  Serial.print(" ");
  Serial.print(nowTime.hour);
  Serial.print(":");
  Serial.print(nowTime.minute);
  Serial.print(":");
  Serial.println(nowTime.second);

}

void loop() {

      int sensorValue = analogRead(A0);

      // write to display
      u8x8.clear();
      u8x8.print(sensorValue);   

      // make a string for assembling the data to log:
      String dataString = "";

      // enter the timestamp
      nowTime = rtc.getTime();   //get current time 
      dataString += print_time(nowTime);
      dataString += ","; 
      dataString += String(sensorValue);

      // open the file. note that only one file can be open at a time,
      // so you have to close this one before opening another.
      File dataFile = SD.open("log0.csv", FILE_WRITE);

      // if the file is available, write to it:
      if (dataFile) {
        dataFile.println(dataString);
        dataFile.close();
        // print to the serial port too:
        Serial.println(dataString);
      } else
        Serial.println("error opening datalog.txt");

  delay(1000);

}