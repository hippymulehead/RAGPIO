#include "ShiftOut.h"

ShiftOut::ShiftOut() {
}

ShiftOut::ShiftOut(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin, uint8_t bitOrder) {
    m_latchOut.setup(latchPin,0);
    m_clockOut.setup(clockPin,0);
    m_dataOut.setup(dataPin,0);
    m_bitOrder = bitOrder;
    m_state = 0;
}

ShiftOut::~ShiftOut() {
}

void ShiftOut::setup(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin, uint8_t bitOrder) {
    m_latchOut.setup(latchPin,0);
    m_clockOut.setup(clockPin,0);
    m_dataOut.setup(dataPin,0);
    m_bitOrder = bitOrder;
    m_state = 0;
}

uint8_t ShiftOut::operator= (uint8_t s) {
    m_state = s;
    uint8_t i;
    m_latchOut = LOW;
	for (i = 0; i < 8; i++)  {
		if (m_bitOrder == LSBFIRST)
            m_dataOut = !!(m_state & (1 << i));
		else
            m_dataOut = !!(m_state & (1 << (7 - i)));

		m_clockOut = HIGH;
		m_clockOut = LOW;
	}
    m_latchOut = HIGH;
    return m_state;
}

void ShiftOut::setBitOrder(uint8_t bitOrder) {
    m_bitOrder = bitOrder;
}
