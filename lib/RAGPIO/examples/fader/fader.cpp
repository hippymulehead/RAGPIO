#include <Arduino.h>
#include <RAGPIO.h>

AnalogOut LED1(12);
AnalogIn POT1(A0);

void setup() {
    LED1.setMap(0, 1023);
}

void loop() {
    LED1 = POT1;
}
