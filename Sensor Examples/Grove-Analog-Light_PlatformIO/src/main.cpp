#include <Arduino.h>

#ifdef XIAO
#define INPUT_PIN 0
#endif
#ifdef CORE2
#define INPUT_PIN 36
#endif

void setup()
{
  Serial.begin(115200);
}
 
void loop()
{
  int value = analogRead(INPUT_PIN);
 
  Serial.println(value);

  delay(100);
}