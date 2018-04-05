#include "ShiftIn.h"

ShiftIn::ShiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
    m_dataIn.setup(dataPin);
    m_clockOut.setup(clockPin,0);
    m_bitOrder = bitOrder;
}

ShiftIn::~ShiftIn() {

}

ShiftIn::operator uint8_t() const {
    uint8_t value = 0;
	uint8_t i;

	for (i = 0; i < 8; ++i) {
        m_clockOut = HIGH;
		if (m_bitOrder == LSBFIRST)
			value |= m_dataIn.value() << i;
		else
			value |= m_dataIn.value() << (7 - i);
			m_clockOut = LOW;
	}
	return value;
}

void ShiftIn::setBitOrder(uint8_t bitOrder) {
    m_bitOrder = bitOrder;
}
