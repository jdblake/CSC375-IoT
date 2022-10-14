#include <Arduino.h>

#ifdef XIAO
#define PIR_MOTION_SENSOR 2
#endif
#ifdef CORE2
#define PIR_MOTION_SENSOR 33
#endif
 
 
void setup()
{
    pinMode(PIR_MOTION_SENSOR, INPUT);
    Serial.begin(115200);  
 
}
 
void loop()
{
    if(digitalRead(PIR_MOTION_SENSOR))//if it detects the moving people?
        Serial.println("Hi,people is coming");
    else
        Serial.println("Watching");
 
 delay(200);
}
