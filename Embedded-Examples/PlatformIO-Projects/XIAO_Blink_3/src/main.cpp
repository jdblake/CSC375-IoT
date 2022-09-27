#include <Arduino.h>

#include <Arduino.h>
#include <Ticker.h>

void flip();

Ticker timer1(flip,200);

void flip() {
	int state = digitalRead(LED_BUILTIN);
	digitalWrite(LED_BUILTIN, !state);

}

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);

	timer1.start();
}

void loop() {
	timer1.update();
}