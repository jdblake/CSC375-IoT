#include <Arduino.h>

// Demo code for Grove - Temperature Sensor V1.1/1.2
// Loovee @ 2015-8-26
 
#include <math.h>
 
const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k

#ifdef XIAO
const int pinTempSensor = 0;     // Grove - Temperature Sensor connect to pin 0
#endif
#ifdef CORE2
const int pinTempSensor = 36;     // Grove - Temperature Sensor connect to A0
#endif
 
void setup()
{
    Serial.begin(115200);
    analogReadResolution(12);
}
 
void loop()
{
    int a = analogRead(pinTempSensor);
 
    float R = 4095.0/a-1.0;
    R = R0*R;
 
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
 
    Serial.print("temperature = ");
    Serial.println(temperature);
 
    delay(1000);
}
