#define PIR_MOTION_SENSOR D7 //Use pin 2 to receive the signal from the module
 
 
void setup()
{
    pinMode(PIR_MOTION_SENSOR, INPUT);
    Serial.begin(115200);  
 
}
 
void loop()
{
    if(digitalRead(PIR_MOTION_SENSOR))//if it detects the moving people?
        Serial.println("Hi, people is coming");
    else
        Serial.println("Watching");
 
 delay(200);
}
