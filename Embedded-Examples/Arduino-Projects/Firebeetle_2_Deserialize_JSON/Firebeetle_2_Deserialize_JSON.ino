#include <ArduinoJson.h>

void setup() {
  // Initialize serial port
  Serial.begin(115200);
  while (!Serial) continue;

  StaticJsonDocument<64> doc;

  // StaticJsonDocument<N> allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  // DynamicJsonDocument doc(200);

  // JSON input string.
  //
  // Using a char[], as shown here, enables the "zero-copy" mode. This mode uses
  // the minimal amount of memory because the JsonDocument stores pointers to
  // the input buffer.
  // If you use another type of input, ArduinoJson must copy the strings from
  // the input to the JsonDocument, so you need to increase the capacity of the
  // JsonDocument.
  char json[] =
      "{\"MAC\":\"00:11:22:33:44:55\",\"dist\":80}";

  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, json);

  // Test if parsing succeeds.
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  const char* mac = doc["MAC"];
  int dist = doc["dist"];

  // Print values.
  Serial.printf("MAC: %s\n",mac);
  Serial.printf("dist: %d\n",dist);
}

void loop() {
  // not used in this example
}