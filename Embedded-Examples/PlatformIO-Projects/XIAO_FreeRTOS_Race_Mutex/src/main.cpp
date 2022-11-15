#include <Arduino.h>

#include <FreeRTOS_SAMD21.h>

SemaphoreHandle_t xMutex;

int sum = 0;

void taskA( void * parameter )
{
  char str[80];

  for(int i = 0; i < 5; i++){
    Serial.println("taskA requests key");
    xSemaphoreTake( xMutex, portMAX_DELAY );
    Serial.println("taskA has key");    int cur = sum;
    vTaskDelay(random(800,1200));
    sprintf(str,"A: Adding 1 to %d to get %d",cur,cur+1);
    Serial.println(str);
    sum = cur+1;
    Serial.println("taskA releases key");
    xSemaphoreGive( xMutex );
    vTaskDelay(100);
  }
  Serial.println("LOW DONE");
  while (1) vTaskDelay(10);
}

void taskB( void * parameter )
{
  char str[80];

  for(int i = 0; i < 5; i++){
    Serial.println("taskB requests key");
    xSemaphoreTake( xMutex, portMAX_DELAY );
    Serial.println("taskB has key");
    int cur = sum;
    vTaskDelay(random(800,1200));
    sprintf(str,"B: Adding 1 to %d to get %d",cur,cur+1);
    Serial.println(str);
    sum = cur+1;
    Serial.println("taskB releases key");
    xSemaphoreGive( xMutex );
    vTaskDelay(100);
  }
  Serial.println("HIGH DONE");
  while (1) vTaskDelay(10);
}

void setup() {
  Serial.begin(112500);

  while (!Serial) ;

  Serial.println("Test Starting");

  delay(1000);

  xMutex = xSemaphoreCreateMutex();
  
  xTaskCreate(taskA,"taskA",1000,NULL,1,NULL);
  delay(500);
  xTaskCreate(taskB,"taskB",1000,NULL,1,NULL);

  vTaskStartScheduler();

}

void loop() {
}
