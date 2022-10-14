#include <Arduino.h>

/*!
       This example is the ultrasonic distance measurement of the module.

       Copyright   [DFRobot](http://www.dfrobot.com), 2020
       Copyright   GNU Lesser General Public License

       version  V1.0
       date  29/10/2020
*/

#ifdef XIAO
#define TRIG_ECHO_PIN 10
#endif
#ifdef CORE2
#define TRIG_ECHO_PIN 11
#endif

#define    VELOCITY_TEMP(temp)       ( ( 331.5 + 0.6 * (float)( temp ) ) * 100 / 1000000.0 ) // The ultrasonic velocity (cm/us) compensated by temperature

uint16_t distance;
uint32_t pulseWidthUs;

void setup() {
  Serial.begin(115200);
  delay(100);
}

void loop() {
  int16_t  dist, temp;
  pinMode(TRIG_ECHO_PIN,OUTPUT);
  digitalWrite(TRIG_ECHO_PIN,LOW);

  digitalWrite(TRIG_ECHO_PIN,HIGH);//Set the trig pin High
  delayMicroseconds(10);     //Delay of 10 microseconds
  digitalWrite(TRIG_ECHO_PIN,LOW); //Set the trig pin Low

  pinMode(TRIG_ECHO_PIN,INPUT);//Set the pin to input mode
  pulseWidthUs = pulseIn(TRIG_ECHO_PIN,HIGH);//Detect the high level time on the echo pin, the output high level time represents the ultrasonic flight time (unit: us)

  distance = pulseWidthUs * VELOCITY_TEMP(20) / 2.0;//The distance can be calculated according to the flight time of ultrasonic wave,/
                                                    //and the ultrasonic sound speed can be compensated according to the actual ambient temperature
  Serial.print(distance, DEC);
  Serial.println("cm");
  delay(500);
}
