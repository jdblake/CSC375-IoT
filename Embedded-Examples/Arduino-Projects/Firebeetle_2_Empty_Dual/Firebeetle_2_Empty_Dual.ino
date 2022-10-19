TaskHandle_t Task1;

void Task1code(void *pvParameters ){

  while (1) {
    delay(100);
  }
}


void setup() {
  Serial.begin(115200);

  xTaskCreatePinnedToCore(Task1code,"Task1",10000,NULL,1,&Task1,0);           
  delay(500);
}

void loop() {
  
}
