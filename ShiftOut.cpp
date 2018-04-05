#include "ShiftOut.h"

ShiftOut::ShiftOut(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin, uint8_t bitOrder) {
    m_latchOut.setup(latchPin,0);
    m_clockOut.setup(clockPin,0);
    m_dataOut.setup(dataPin,0);
    m_bitOrder = bitOrder;
    m_state = 0;
}

ShiftOut::~ShiftOut() {
}

uint8_t ShiftOut::operator= (uint8_t s) {
    m_state = s;
    uint8_t i;

	for (i = 0; i < 8; i++)  {
		if (m_bitOrder == LSBFIRST)
            m_dataOut = !!(m_state & (1 << i));
		else
            m_dataOut = !!(m_state & (1 << (7 - i)));

		m_clockOut = HIGH;
		m_clockOut = LOW;
	}
    return m_state;
}

void ShiftOut::setBitOrder(uint8_t bitOrder) {
    m_bitOrder = bitOrder;
}
