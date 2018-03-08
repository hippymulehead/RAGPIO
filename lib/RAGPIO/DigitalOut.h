#ifndef DIGITALOUT_H
#define DIGITALOUT_H
#include <Arduino.h>

class DigitalOut {
    public:
        DigitalOut();
        DigitalOut(int pinNumber, int value);
        virtual ~DigitalOut();
        void setup(int pinNumber, int value);
        int operator = (int s);
        int operator ! () const {return !m_state;}
        operator int() const {return m_state;}
        int read() {return m_state;}

    protected:
        int m_state;
    	uint8_t m_bit;
    	uint8_t m_port;
        volatile uint8_t *m_out;

    private:
};

#endif // DIGITALOUT_H
