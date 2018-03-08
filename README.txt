C++ GPIO for PlatformIO and Arduino

This is an attempt to speed up GPIO on Arduino as well as wrap it in a C++ methodology.
The digital in and out are faster than DigitalRead and DigitalWrite
The AnalogIn is faster than AnalogRead() by a little bit.
AnalogOut is the same speed as AnalogWrite() but was included to keep all GPIO in the same
methodology.

This code is mainly from the the Arduino source with some additions by myself where they were
needed.  

To use the lib, simple do this in your code

#include <RAGPIO.h>

This lib is acctually 4 libs that were inspired by how mbed does it's GPIO.

#### DigitalOut

Create an object
DigitalOut(int pinNumber, int value);
DigitalOut LED1(12,0);

Do a write
LED1 = 1;

Invert an out
LED1 = !LED1;

Check the current state
if (LED1) {
    Serial.print("The LED is on!\n");
}

Copy the state of one DigitalOut to another.
DigitalOut LED1(12,0);
DigitalOut LED2(11,0);

void setup() {
    LED2 = 1;
}

void loop() {
    LED1 = LED2.value();
}

#### DigitalIn

Create an object
DigitalIn button1(5);

Check the value
if (button1) {
    Serial.print("Button 1 is pressed");
}

Set a DigitalOut from a DigitalIn
LED1 = button1.value();

#### AnalogIn

Create an object
AnalogIn pot1(A0);

Read from the pot
int potValue = pot1;

Read from the pot in a mapped int range
int potValue = pot1.asMapped(0,10);

Read from the pot in a mapped float range
int potValue = pot1.asFloatMapped(0.0,5.0); //Shows voltage at pin.

#### AnalogOut (PWM)

Create an object
AnalogOut PWMLED(6);

Set a map on the pin to make writing inputs to the outputs more easy
PWMLED.setMap(0,1023); // Now you can do PWMLED = pot1;

Turn PWMLED all the way up without a map
PWMLED = 255;
With the above map
PWMLED = 1023;

Get the current value of the pin
int PWMValue = PWMLED.value();
