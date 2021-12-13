#include <Wire.h>

void setup() {
    Wire.begin(8);                /* join i2c bus with address 8 */
    Wire.onReceive(receiveEvent); /* register receive event */
    Wire.onRequest(requestEvent); /* register request event */
    Serial.begin(9600);           /* start serial for debug */
    pinMode(13, OUTPUT);
}

void loop() {
    delay(100);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
    while (0 < Wire.available()) {
        int c = Wire.read();      /* receive byte as a character */
        if (c == 0) {
            Serial.println(c);
            digitalWrite(13, c);
        }
        if (c == 1) {
            Serial.println(c);
            digitalWrite(13, c);
        }
        //Serial.print(c);           /* print the character */
    }
    Serial.println();             /* to newline */
}

// function that executes whenever data is requested from master
void requestEvent() {
    Wire.write("Hello NodeMCU");  /*send string on request */
}