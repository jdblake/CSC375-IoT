#include <Arduino.h>

#include <WiFi.h>
#include <esp_now.h>

// Node in peer MAC linked list
typedef struct peerNode {
  uint8_t addr[6];
  peerNode *next = NULL;
} peerNode;

// Head of peer linked list
peerNode *peerList;

// Function to convert uint8_t array MAC to string
void formatMacAddress(const uint8_t *macAddr, char *buffer, int maxLength)
{
  snprintf(buffer, maxLength, "%02x:%02x:%02x:%02x:%02x:%02x", macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
}

// Recursive function to print MAC addresses in linked list to the serial port
void dumpPeers(peerNode *cur) {

  // Recursively print peers to Serial

}

// Callback function for send process. Prints message success/failure message.
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {

  // Print message on send

}

// Callback function for receive process. Records peer if new. Responds on "Hello" messages.
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {

  // Process all incoming messages

}

void setup() {
  String msg = "Hello";

  // Set up Serial Monitor
  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_STA);

  // Initialize ESP-NOW
  if (esp_now_init() == ESP_OK)
  {
    Serial.println("ESP-NOW Init Success");
    esp_now_register_send_cb(OnDataSent);
    esp_now_register_recv_cb(OnDataRecv);
  }
  else
  {
    Serial.println("ESP-NOW Init Failed");
    delay(3000);
    ESP.restart();
  }

  // Broadcast 5 "Hello" messages

}

void loop() {

  // Do Nothing

}
