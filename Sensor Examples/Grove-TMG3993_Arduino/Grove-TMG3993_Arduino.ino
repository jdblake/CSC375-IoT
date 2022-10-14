#include <Wire.h>
 
#include "Seeed_TMG3993.h"
 
TMG3993 tmg3993;
 
void setup()
{
  Serial.begin(115200);
  while (!Serial) ;
  Serial.println("TMG3993 Proximity Example");
 
  Wire.begin();
 
  if (tmg3993.initialize() == false)
  {
    Serial.println("Device not found. Check wiring.");
    while (1);
  }
  tmg3993.setupRecommendedConfigForProximity();
  tmg3993.enableEngines(ENABLE_PON | ENABLE_PEN | ENABLE_PIEN);
}
 
void loop()
{
  if (tmg3993.getSTATUS() & STATUS_PVALID)
  {
    uint8_t proximity_raw = tmg3993.getProximityRaw();  //read the Proximity data will clear the status bit
    Serial.print("Proximity Raw: ");
    Serial.println(proximity_raw);
  }
  delay(1);
}
