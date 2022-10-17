TaskHandle_t LED_Task;

//Blink_LED: blinks an LED every 1000 ms
void Blink_LED(void *pvParameters ){

  while (1) {
    Serial.printf("Blink_LED() running on core %d\n",xPortGetCoreID());
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  } 
}

void setup() {
  Serial.begin(115200);
  while (!Serial) ;
  pinMode(LED_BUILTIN, OUTPUT);
  
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Blink_LED,   /* Task function. */
                    "LED_Task",  /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &LED_Task,   /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  delay(500); 
}

void loop() {
  Serial.printf("Loop() running on core %d\n",xPortGetCoreID());
  delay(1000);
}
