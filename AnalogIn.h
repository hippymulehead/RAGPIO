#ifndef ANALOGIN_H
#define ANALOGIN_H
#include <Arduino.h>

class AnalogIn {
    public:
        AnalogIn(uint8_t pinToRead);
        virtual ~AnalogIn();
        operator int() const;
        int asMapped(int lowValue, int highValue);
        float asFloatMapped(float lowValue, float highValue);

    protected:
        int         m_pin;
        uint8_t     analog_reference = DEFAULT;
        void analogReference(uint8_t mode) {
            analog_reference = mode;
        }
        float map_to_float(float x, float a, float b, float c, float d) {
            float f=x/(b-a)*(d-c)+c;
            return f;
        }

    private:

};

#endif // ANALOGIN_H
