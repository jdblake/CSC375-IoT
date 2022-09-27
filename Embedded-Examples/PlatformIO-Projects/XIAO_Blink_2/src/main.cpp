#include <Arduino.h>

unsigned long curTime;
int state = LOW;

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, state);
	curTime = millis();
}

void loop() {
	unsigned long diff = millis() - curTime;
	if (diff > 1000) {
		curTime = millis();
		state = !state;
		digitalWrite(LED_BUILTIN, state);
	}
}