#include <DigitalIn.h>
#include <Arduino.h>

DigitalIn::DigitalIn() {
}

DigitalIn::DigitalIn(uint8_t pinNumber) {
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

void DigitalIn::setup(uint8_t pinNumber) {
    m_timer = digitalPinToTimer(pinNumber);
    m_bit = digitalPinToBitMask(pinNumber);
    m_port = digitalPinToPort(pinNumber);
}

uint8_t DigitalIn::value() {
    if (*portInputRegister(m_port) & m_bit) return HIGH;
    return LOW;
}
