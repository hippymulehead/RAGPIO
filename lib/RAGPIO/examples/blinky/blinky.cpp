#include <Arduino.h>
#include <RAGPIO.h>

// setup pin 12 as a DigitalOut and turn it off
DigitalOut LED1(12,0);

void setup() {

}

// Make the connected LED blink on and off
void loop() {
    LED1 = !LED1;
    delay(100);
}
