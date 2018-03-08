#include <DigitalIn.h>
#include <Arduino.h>

DigitalIn::DigitalIn(int pinNumber) {
    m_timer = digitalPinToTimer(pinNumber);
    m_bit = digitalPinToBitMask(pinNumber);
    m_port = digitalPinToPort(pinNumber);
}

DigitalIn::~DigitalIn() {

}

DigitalIn::operator int() const {
    if (*portInputRegister(m_port) & m_bit) return HIGH;
    return LOW;
}

int DigitalIn::read() {
    if (*portInputRegister(m_port) & m_bit) return HIGH;
    return LOW;
}
