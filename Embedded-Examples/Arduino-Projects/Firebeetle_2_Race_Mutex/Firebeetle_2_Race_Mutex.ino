SemaphoreHandle_t xMutex;

int sum = 0;

void setup() {
  Serial.begin(112500);
  /* create Mutex */
  xMutex = xSemaphoreCreateMutex();
  
  xTaskCreate(
      lowPriorityTask,           /* Task function. */
      "lowPriorityTask",        /* name of task. */
      1000,                    /* Stack size of task */
      NULL,                     /* parameter of the task */
      1,                        /* priority of the task */
      NULL);                    /* Task handle to keep track of created task */
  delay(500);
  /* let lowPriorityTask run first then create highPriorityTask */
  xTaskCreate(
      highPriorityTask,           /* Task function. */
      "highPriorityTask",        /* name of task. */
      1000,                    /* Stack size of task */
      NULL,                     /* parameter of the task */
      4,                        /* priority of the task */
      NULL);                    /* Task handle to keep track of created task */
}

void loop() {
}

void lowPriorityTask( void * parameter )
{
  char str[80];

  for(int i = 0;i < 5;i++){
    Serial.println("lowPriorityTask requests key");
    xSemaphoreTake( xMutex, portMAX_DELAY );
    Serial.println("lowPriorityTask has key");
    /* even low priority task delay high priority 
    still in Block state */
    int cur = sum;
    delay(random(800,1200));
    sprintf(str,"Adding 1 to %d to get %d",cur,cur+1);
    Serial.println(str);
    sum = cur+1;
    Serial.println("lowPriorityTask releases key");
    xSemaphoreGive( xMutex );
  }
  Serial.println("LOW DONE");
  while (1) delay(10);
}

void highPriorityTask( void * parameter )
{
  char str[80];

  for(int i = 0;i < 5;i++){
    Serial.println("highPriorityTask requests key");
    /* highPriorityTask wait until lowPriorityTask release key */
    xSemaphoreTake( xMutex, portMAX_DELAY );
    Serial.println("highPriorityTask has key");
    int cur = sum;
    delay(random(800,1200));
    sprintf(str,"Adding 1 to %d to get %d",cur,cur+1);
    Serial.println(str);
    sum = cur+1;
    Serial.println("highPriorityTask releases key");
    xSemaphoreGive( xMutex );
    /* delay so that lowPriorityTask has chance to run */
    delay(random(800,1200));
  }
  Serial.println("HIGH DONE");
  while (1) delay(10);
}