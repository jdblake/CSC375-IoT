#include <Arduino.h>

#include <M5Core2.h>

#include <NfcAdapter.h>
#include <PN532/PN532/PN532.h>

#include <PN532/PN532_HSU/PN532_HSU.h>

#include <SoftwareSerial.h>

PN532_HSU pn532hsu(Serial2);
NfcAdapter nfc(pn532hsu);

// char target[] = "04 CA B6 42 5C 64 80";

String cur;

void setup(void) {
    M5.begin();

    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(2);
    
    M5.Lcd.fillScreen(WHITE);
    delay(500);
    M5.Lcd.fillScreen(RED);
    delay(500);
    M5.Lcd.fillScreen(GREEN);
    delay(500);
    M5.Lcd.fillScreen(BLUE);
    delay(500);
    M5.Lcd.fillScreen(BLACK);
    delay(500);

    M5.Lcd.setCursor(10, 10);
    M5.Lcd.printf("Tag Reader!");

    nfc.begin();
}

void loop(void) {
    if (nfc.tagPresent()) {
        NfcTag tag = nfc.read();
        //if (!strcmp(target,tag.getUidString().c_str())) {
        if (cur.compareTo(tag.getUidString())) {
          cur = tag.getUidString();
          Serial.println(cur);
          M5.Lcd.fillScreen(BLACK);
          M5.Lcd.setCursor(10, 10);
          M5.Lcd.printf(cur.c_str());
        }
    }
}