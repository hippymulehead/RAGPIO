#include <Arduino.h>
#include <RAGPIO.h>

ShiftOut myReg(12,11,10,LSBFIRST);

void setup() {
}

void loop() {
    for (int i = 0; i < 256; i++) {
        myReg = i;
        delay(50);
    }
}
