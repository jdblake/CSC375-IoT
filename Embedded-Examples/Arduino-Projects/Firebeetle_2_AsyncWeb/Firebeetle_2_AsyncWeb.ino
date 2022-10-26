#include "WiFi.h"
#include "ESPAsyncWebServer.h"
 
const char* ssid = "ESP32_AP";
const char* password =  "123456789";
 
AsyncWebServer server(80);
 
void setup(){
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println(WiFi.localIP());
 
  server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello World");
  });
  
  server.on("/goodbye", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Goodbye World");
  });
 
  server.begin();
}
 
void loop(){}
