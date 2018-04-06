#ifndef SHIFTIN_H
#define SHIFTIN_H
#include <RAGPIO.h>

class ShiftIn {
    public:
        ShiftIn();
        ShiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);
        virtual ~ShiftIn();
        void setup(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);
        operator uint8_t() const;
        void setBitOrder(uint8_t bitOrder);

    protected:
        DigitalIn m_dataIn;
        DigitalOut m_clockOut;
        uint8_t m_bitOrder;

    private:
};

#endif // SHIFTIN_H
