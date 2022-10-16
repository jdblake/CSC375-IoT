void setup() {
  Serial.begin(115200);
  while (!Serial) ;
  Serial.printf("setup() running on core %d\n",xPortGetCoreID());
}

void loop() {
  Serial.printf("loop() running on core %d\n",xPortGetCoreID());
  delay(1000);
}
