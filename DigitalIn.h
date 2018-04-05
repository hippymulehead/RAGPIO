#ifndef DIGITALIN_H
#define DIGITALIN_H
#include <Arduino.h>

class DigitalIn
{
    public:
        DigitalIn();
        DigitalIn(uint8_t pinNumber);
        virtual ~DigitalIn();
        operator int() const;
        void setup(uint8_t pinNumber);
        uint8_t value();

    protected:
        uint8_t m_timer;
        uint8_t m_bit;
        uint8_t m_port;

    private:
};

#endif // DIGITALIN_H
