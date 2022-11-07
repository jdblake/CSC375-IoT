#include <Arduino.h>

void formatMacAddress(const uint8_t *macAddr, char *buffer, int maxLength)
{
  snprintf(buffer, maxLength, "%02x:%02x:%02x:%02x:%02x:%02x", macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
}

void setup(){
  uint8_t addr[6];
  char mStr[18];
  Serial.begin(115200);
  Serial.println();

  // Get WiFi Station (Base)
  esp_read_mac(addr,ESP_MAC_WIFI_STA);
  formatMacAddress(addr,mStr,18);
  Serial.printf("STA: %s\n",mStr);

  // Get WiFi SoftAP
  esp_read_mac(addr,ESP_MAC_WIFI_SOFTAP);
  formatMacAddress(addr,mStr,18);
  Serial.printf("SOFTAP: %s\n",mStr);

  // Get Bluetooth
  esp_read_mac(addr,ESP_MAC_BT);
  formatMacAddress(addr,mStr,18);
  Serial.printf("BT: %s\n",mStr);

  // Get Ethernet
  esp_read_mac(addr,ESP_MAC_ETH);
  formatMacAddress(addr,mStr,18);
  Serial.printf("ETH: %s\n",mStr);
}
 
void loop(){

}