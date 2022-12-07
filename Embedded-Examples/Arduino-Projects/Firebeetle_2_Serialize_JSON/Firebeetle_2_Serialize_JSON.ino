#include <ArduinoJson.h>

void setup() {
  // Initialize Serial port
  Serial.begin(115200);
  while (!Serial) continue;

  // Allocate the JSON document
  StaticJsonDocument<64> doc;

  // Add values in the document
  //
  doc["MAC"] = "AA:AA:AA:AA:AA:AA";
  doc["dist"] = 75;

  // Generate the minified JSON and send it to the Serial port.
  //
  serializeJson(doc, Serial);

  // Start a new line
  Serial.println();

  // Generate the prettified JSON and send it to the Serial port.
  //
  serializeJsonPretty(doc, Serial);
}

void loop() {
  // not used in this example
}