#include <WiFi.h>

const char* ssid = "CSC375";
const char* password = "123456789";

void setup(){
    Serial.begin(115200);
    delay(1000);

    WiFi.mode(WIFI_STA);

    do {
      Serial.println("Connecting...");
      WiFi.disconnect();
      WiFi.begin(ssid, password);
      delay(5000);
    } while (WiFi.status() != WL_CONNECTED);

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());
}

void loop(){}