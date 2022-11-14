// include libraries for FreeRTOS and semaphore
#include <Arduino_FreeRTOS.h>
#include "semphr.h"
// define two semaphore type variables. Because we will create two mutex
SemaphoreHandle_t xMutex;
SemaphoreHandle_t yMutex;

void setup()
{

  Serial.begin(9600); // Enable Serial communication
  xMutex = xSemaphoreCreateMutex(); // create mutex with name xMutex
  yMutex = xSemaphoreCreateMutex(); //  create mutex with name yMutex

  xTaskCreate(Task1, "Task1",100,NULL,1,NULL); // Create Task1 with priority 1 
  xSemaphoreGive(xMutex); // make available xMutex
  xSemaphoreGive(yMutex);  // make available yMutex

}

void loop(){}
void Task1(void *pvParameters)
{
  while(1)
  {
   xSemaphoreTake(xMutex,portMAX_DELAY); 
   Serial.println("Inside Task1");
   xTaskCreate(Task2, "Task2", 100,NULL,2,NULL);
   Serial.println("Task1 attempting to take yMutex");
   xSemaphoreTake(yMutex,portMAX_DELAY);
   xSemaphoreGive(xMutex);
   vTaskDelay(1);
  }
}
void Task2(void *pvParameters)
{
  while(1)
  {
    xSemaphoreTake(yMutex,portMAX_DELAY);
    Serial.println("Inside Task2");
    Serial.println("Task2 attempting to take xMutex");
    xSemaphoreTake(xMutex,portMAX_DELAY);
    xSemaphoreGive(yMutex);
    vTaskDelay(1);
  }
}