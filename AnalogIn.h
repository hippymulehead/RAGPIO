#ifndef ANALOGIN_H
#define ANALOGIN_H
#include <Arduino.h>

class AnalogIn {
    public:
        AnalogIn();
        AnalogIn(uint8_t pinToRead);
        virtual ~AnalogIn();
        operator int() const;
        operator float() const;
        void createIntMap(int lowValue, int highValue);
        void createFloatMap(float lowValue, float highValue);
        void setADCDepth(uint8_t bits);

    protected:
        int         m_pin;
        uint8_t     analog_reference = DEFAULT;
        uint8_t     m_isIntMapped = 0;
        uint8_t     m_isFloatMapped = 0;
        int         m_low = 0;
        int         m_high = 1023;
        int         m_iLowValue = 0;
        int         m_iHighValue = 0;
        float       m_fLowValue = 0.0;
        float       m_fHighValue = 0.0;
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
