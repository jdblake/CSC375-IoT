#include <Arduino.h>

// Remote Control - As The Remote Device
//
// This script configures your Xiao to be remotely controlled by another Xiao.
//

#include <openmvrpc.h>
// The RPC library above provides mutliple classes for being cotnrolled over
// CAN, I2C, SPI, or Serial (UART).

const int ledPin =  LED_BUILTIN; //led attached to this pin

// We need to define a scratch buffer for holding messages. The maximum amount of data
// you may pass in any on direction is limited to the size of this buffer.

openmv::rpc_scratch_buffer<256> scratch_buffer; // All RPC objects share this buffer.

// The interface library executes call backs on this device which have to be registered
// before they can be called. To avoid dyanmic memory allocation we have to create a buffer
// with the maximum number of call backs we plan to support to hold the registrations.
//
// Note that callback registrations only work on the rpc interface that registered them.

openmv::rpc_callback_buffer<8> callback_buffer; // All RPC objects share this buffer.

///////////////////////////////////////////////////////////////
// Choose the interface you wish to be controlled over.
///////////////////////////////////////////////////////////////

// Uncomment the below line to setup for be controlled over a hardware UART.
//
openmv::rpc_hardware_serial_uart_slave interface(115200);

//////////////////////////////////////////////////////////////
// Call Backs
//////////////////////////////////////////////////////////////

size_t digital_read_example(void *out_data) {
    // Get what we want to return into a variable.
    uint8_t state = digitalRead(4);

    // Move that variable into a transmit buffer.
    memcpy(out_data, &state, sizeof(state));

    // Return how much we will send.
    return sizeof(state);
}

size_t analog_read_example(void *out_data) {
    // Get what we want to return into a variable.
    uint16_t state = analogRead(A0);

    // Move that variable into a transmit buffer.
    memcpy(out_data, &state, sizeof(state));

    // Return how much we will send.
    return sizeof(state);
}

void digital_write_example(void *in_data, size_t in_data_len) {
    // Create the primitive or complex data type on the stack.
    uint8_t state;

    // Check that we received the amount of data we expected.
    if (in_data_len != sizeof(state)) return;

    // Copy what we received into our data type container.
    memcpy(&state, in_data, sizeof(state));

//    Serial.print(F("Remote Button State: "));
//    Serial.println(state);
    
    // Use it now.
    digitalWrite(ledPin, state);
//    if (state > 0){
//      digitalWrite(ledPin, HIGH);  //LED off
//    } else {
//      digitalWrite(ledPin, LOW);   //LED on
//    }
}

void analog_write_example(void *in_data, size_t in_data_len) {
    // Create the primitive or complex data type on the stack.
    uint8_t state;

    // Check that we received the amount of data we expected.
    if (in_data_len != sizeof(state)) return;

    // Copy what we received into our data type container.
    memcpy(&state, in_data, sizeof(state));

    // Use it now.
    analogWrite(A1, state);
}

void serial_print_example(void *in_data, size_t in_data_len) {
    // Create the string on the stack (extra byte for the null terminator).
    char buff[in_data_len + 1]; memset(buff, 0, in_data_len + 1);

    // Copy what we received into our data type container.
    memcpy(buff, in_data, in_data_len);

    // Use it now.
    Serial.println(buff);
}

void setup() {

    // initialize the LED pin as an output:
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);

    // register callbacks
    interface.register_callback(F("digital_read"), digital_read_example);
    interface.register_callback(F("analog_read"), analog_read_example);
    interface.register_callback(F("digital_write"), digital_write_example);
    interface.register_callback(F("analog_write"), analog_write_example);
    interface.register_callback(F("serial_print"), serial_print_example);
         
    // Startup the RPC interface and a debug channel.
    interface.begin();
    Serial.begin(115200);
}

// Once all call backs have been registered we can start
// processing remote events.

void loop() {
     interface.loop();
}