#ifndef ANALOGOUT_H
#define ANALOGOUT_H
#include <DigitalOut.h>

class AnalogOut
{
    public:
        AnalogOut(int pinNumber);
        virtual ~AnalogOut();
        int AnalogOut::operator= (int s);
        int value();
        void setMap(int lowValue, int highValue);

    protected:
        int             m_pin;
        int             m_state;
        int             m_s;
        int             m_low = 0;
        int             m_high = 255;
        DigitalOut      m_out;

    private:
};

#endif // ANALOGOUT_H
