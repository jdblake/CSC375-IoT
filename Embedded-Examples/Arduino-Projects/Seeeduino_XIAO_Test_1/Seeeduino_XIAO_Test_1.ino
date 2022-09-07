const int ledPin =  13;
 
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  while (!Serial);
}
 
void loop() {
  delay(1000);
  Serial.println("ON");
  digitalWrite(ledPin, HIGH);
  delay(1000);
  Serial.println("OFF");
  digitalWrite(ledPin, LOW);
}
