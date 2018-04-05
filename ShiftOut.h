#ifndef SHIFTOUT_H
#define SHIFTOUT_H
#include <RAGPIO.h>

class ShiftOut {
    public:
        ShiftOut(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin, uint8_t bitOrder);
        virtual ~ShiftOut();
        uint8_t operator = (uint8_t s);
        operator uint8_t() const {return m_state;}
        uint8_t value() {return m_state;}
        void setBitOrder(uint8_t bitOrder);

    protected:
        DigitalOut m_latchOut;
        DigitalOut m_clockOut;
        DigitalOut m_dataOut;
        uint8_t m_bitOrder;
        uint8_t m_state;

    private:
};

#endif // SHIFTOUT_H
