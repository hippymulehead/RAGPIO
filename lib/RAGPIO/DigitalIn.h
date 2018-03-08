#ifndef DIGITALIN_H
#define DIGITALIN_H
#include <Arduino.h>

class DigitalIn
{
    public:
        DigitalIn(int pinNumber);
        virtual ~DigitalIn();
        operator int() const;
        int read();

    protected:
        uint8_t m_timer;
        uint8_t m_bit;
        uint8_t m_port;

    private:
};

#endif // DIGITALIN_H
