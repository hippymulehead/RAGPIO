#include <Arduino.h>
#include "DigitalOut.h"

DigitalOut::DigitalOut() {
}

DigitalOut::DigitalOut(uint8_t pinNumber) {
	m_bit = digitalPinToBitMask(pinNumber);
	m_port = digitalPinToPort(pinNumber);
	if (m_port == NOT_A_PIN) return;
    m_out = portOutputRegister(m_port);
    m_state = 0;
    pinMode(pinNumber, OUTPUT);
    if (m_state == LOW) {
		*m_out &= ~m_bit;
	} else {
		*m_out |= m_bit;
	}
}

DigitalOut::DigitalOut(uint8_t pinNumber, uint8_t value) {
	m_bit = digitalPinToBitMask(pinNumber);
	m_port = digitalPinToPort(pinNumber);
	if (m_port == NOT_A_PIN) return;
    m_out = portOutputRegister(m_port);
    m_state = value;
    pinMode(pinNumber, OUTPUT);
    if (m_state == LOW) {
		*m_out &= ~m_bit;
	} else {
		*m_out |= m_bit;
	}
}

DigitalOut::~DigitalOut() {
}

void DigitalOut::setup(uint8_t pinNumber, uint8_t value) {
	m_bit = digitalPinToBitMask(pinNumber);
	m_port = digitalPinToPort(pinNumber);
	if (m_port == NOT_A_PIN) return;
    m_out = portOutputRegister(m_port);
    m_state = value;
    pinMode(pinNumber, OUTPUT);
    if (m_state == LOW) {
		*m_out &= ~m_bit;
	} else {
		*m_out |= m_bit;
	}
}

int DigitalOut::operator= (int s) {
    m_state = s;
    if (m_state == LOW) {
		*m_out &= ~m_bit;
	} else {
		*m_out |= m_bit;
	}
    return m_state;
}
