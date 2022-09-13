#define BUTTON_PIN 27

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
    int value = digitalRead(BUTTON_PIN);
    Serial.print(value);
    delay(1000);
}
