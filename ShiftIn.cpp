#include "ShiftIn.h"

ShiftIn::ShiftIn() {
}

ShiftIn::ShiftIn(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin, uint8_t bitOrder) {
    m_dataIn.setup(dataPin);
    m_clockOut.setup(clockPin,0);
    m_latchOut.setup(latchPin,0);
    m_bitOrder = bitOrder;
}

ShiftIn::~ShiftIn() {
}

void ShiftIn::setup(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin, uint8_t bitOrder) {
    m_dataIn.setup(dataPin);
    m_clockOut.setup(clockPin,0);
    m_latchOut.setup(latchPin,0);
    m_bitOrder = bitOrder;
}

ShiftIn::operator uint8_t() const {
    uint8_t value = 0;
	uint8_t i;
    m_latchOut = LOW;
	for (i = 0; i < 8; ++i) {
        m_clockOut = HIGH;
		if (m_bitOrder == LSBFIRST)
			value |= m_dataIn.value() << i;
		else
			value |= m_dataIn.value() << (7 - i);
			m_clockOut = LOW;
	}
    m_latchOut = HIGH;
	return value;
}

void ShiftIn::setBitOrder(uint8_t bitOrder) {
    m_bitOrder = bitOrder;
}
