#ifndef DIGITALOUT_H
#define DIGITALOUT_H
#include <Arduino.h>

class DigitalOut {
    public:
        DigitalOut();
        DigitalOut(uint8_t pinNumber);
        DigitalOut(uint8_t pinNumber, uint8_t value);
        virtual ~DigitalOut();
        void setup(uint8_t pinNumber, uint8_t value);
        int operator = (int s);
        int operator ! () const {return !m_state;}
        operator int() const {return m_state;}
        int value() {return m_state;}

    protected:
        uint8_t m_state;
    	uint8_t m_bit;
    	uint8_t m_port;
        volatile uint8_t *m_out;

    private:
};

#endif // DIGITALOUT_H
