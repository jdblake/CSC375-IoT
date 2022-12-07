#include <Ticker.h>

int doPrint = 1;
 
Ticker periodicTicker;
Ticker onceTicker;
 
void periodicPrint(int print) {
  if (doPrint == 1)
    Serial.println("printing in periodic function.");
}
 
void oncePrint() {
  Serial.println("printing in once function.");
}
 
 
void setup() {
  Serial.begin(115200);

  pinMode(27, INPUT_PULLUP);
   
  periodicTicker.attach_ms(1000, periodicPrint, doPrint);
  onceTicker.once_ms(10000, oncePrint);
}

void loop() {
  doPrint = digitalRead(27);
  delay(10);
}
