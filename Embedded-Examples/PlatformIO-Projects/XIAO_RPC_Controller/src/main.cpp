#include <Arduino.h>

// Remote Control - As The Controller Device
//
// This script configures your Xiao to remotely control another Xiao.
//

#include <openmvrpc.h>
// The RPC library above provides mutliple classes for controlling an Arduino over
// CAN, I2C, SPI, or Serial (UART).

//initialize and declare variables
const int ledPin = LED_BUILTIN; //led attached to this pin
const int buttonPin = 2;     // the number of the pushbutton pin
uint8_t buttonState = LOW; //this variable tracks the state of the button, low if not pressed, high if pressed

// We need to define a scratch buffer for holding messages. The maximum amount of data
// you may pass in any on direction is limited to the size of this buffer.

openmv::rpc_scratch_buffer<256> scratch_buffer; // All RPC objects share this buffer.

///////////////////////////////////////////////////////////////
// Choose the interface you wish to control a Xiao over.
///////////////////////////////////////////////////////////////
// Uncomment the below line to setup your Xiao for controlling over a hardware UART.
//
openmv::rpc_hardware_serial_uart_master interface(115200);

void setup() {
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);

    Serial.begin(115200);
    while (!Serial) ;

    Serial.println("Connected");
    
    // Startup the RPC interface and a debug channel.
    interface.begin();

    Serial.println("Interface up");
}

//////////////////////////////////////////////////////////////
// Call Back Handlers
//////////////////////////////////////////////////////////////

// This example shows reading a Digital I/O pin remotely.
//
void digital_read_example() {
    uint8_t state;
    if (interface.call_no_args(F("digital_read"), &state, sizeof(state))) {
        Serial.print(F("Remote Digital I/O State: "));
        Serial.println(state);
    }
}

// This example shows reading an Analog I/O pin remotely.
//
void analog_read_example() {
    uint16_t state;
    if (interface.call_no_args(F("analog_read"), &state, sizeof(state))) {
        Serial.print(F("Remote Analog I/O State: "));
        Serial.println(state);
    }
}

// This example shows writing a Digital I/O pin remotely.
//
void digital_write_example(uint8_t state) {
    // static uint8_t state = 1;
    if (interface.call(F("digital_write"), &state, sizeof(state))) {
        //state = !state; // flip state for next time
//        Serial.print(F("Local Button State: "));
//        Serial.println(state);
    }
}

// This example shows writing an Analog I/O pin remotely.
//
void analog_write_example() {
    static uint8_t state = 0;
    if (interface.call(F("digital_write"), &state, sizeof(state))) {
        state = state + 1; // counts from 0 to 255 then rolls over
    }
}

void serial_print_example() {
    char *str = "Hello World!";
    interface.call(F("serial_print"), str, strlen(str));
}

void loop() {
  
    // digital_read_example();
    
    analog_read_example();

    buttonState = digitalRead(buttonPin);
    digitalWrite(ledPin, !buttonState);
    digital_write_example(buttonState);

    // analog_write_example();

    //serial_print_example();
    
}