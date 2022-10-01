#include <Arduino.h>

void setup() {
  delay(5000);
  //Declaring LED pin as output
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  //Fading the LED
  for(int i=0; i<255; i++){
    analogWrite(LED_BUILTIN, i);
    delay(5);
  }
  for(int i=255; i>0; i--){
    analogWrite(LED_BUILTIN, i);
    delay(5);
  }
}