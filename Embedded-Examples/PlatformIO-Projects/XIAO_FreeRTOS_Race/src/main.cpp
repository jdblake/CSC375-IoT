#include <Arduino.h>

#include <FreeRTOS_SAMD21.h>

int sum = 0;

void lowPriorityTask( void * parameter )
{
  char str[80];

  for(int i = 0; i < 5; i++){
    int cur = sum;
    vTaskDelay(random(800,1200));
    sprintf(str,"LOW: Adding 1 to %d to get %d",cur,cur+1);
    Serial.println(str);
    sum = cur+1;
  }
  Serial.println("LOW DONE");
  while (1) vTaskDelay(10);
}

void highPriorityTask( void * parameter )
{
  char str[80];

  for(int i = 0; i < 5; i++){
    int cur = sum;
    vTaskDelay(random(800,1200));
    sprintf(str,"HIGH: Adding 1 to %d to get %d",cur,cur+1);
    Serial.println(str);
    sum = cur+1;
  }
  Serial.println("HIGH DONE");
  while (1) vTaskDelay(10);
}

void setup() {
  Serial.begin(112500);

  while (!Serial) ;

  Serial.println("Test Starting");

  delay(1000);
  
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

  vTaskStartScheduler();

}

void loop() {
}
