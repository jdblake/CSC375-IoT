void setup()
{
  // nothing to initialize
  Serial.begin(115200);
}
 
void loop()
{
 
  int value = analogRead(A4);

  Serial.println(value);
 
  delay(100);
}
