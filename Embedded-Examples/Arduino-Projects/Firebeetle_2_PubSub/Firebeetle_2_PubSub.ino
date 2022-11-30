#include <WiFi.h>
#include <PubSubClient.h>
#include <Ticker.h>
 
Ticker hallTicker;

// Replace the next variables with your SSID/Password combination
const char* ssid = "Omega-6CBE";
const char* password = "123456789";

// Add your MQTT Broker IP address, example:
//const char* mqtt_server = "192.168.1.144";
const char* mqtt_server = "192.168.3.1";

WiFiClient espClient;
PubSubClient client(espClient);
//long lastMsg = 0;
//char msg[50];
int value = 0;

// LED Pin
const int ledPin = 2;

void setup() {
  Serial.begin(115200);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(ledPin, OUTPUT);

  hallTicker.attach_ms(5000, publishHall);
}

void publishHall() {
  int val = hallRead();
  char tempString[8];

  sprintf(tempString,"%d",val);
  Serial.print("Hall: ");
  Serial.println(tempString);
  client.publish("firebeetle/hall", tempString);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if (String(topic) == "firebeetle/led") {
    Serial.print("Changing output to ");
    if(messageTemp == "1"){
      Serial.println("on");
      digitalWrite(ledPin, HIGH);
    }
    else if(messageTemp == "0"){
      Serial.println("off");
      digitalWrite(ledPin, LOW);
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("FirebeetleClient")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("firebeetle/led");
      client.subscribe("firebeetle/hello");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

}