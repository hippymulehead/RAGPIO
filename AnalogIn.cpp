#include "AnalogIn.h"
#include "wiring_private.h"
#include <Arduino.h>

AnalogIn::AnalogIn(uint8_t pinToRead) {
    m_pin = pinToRead;
    #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        if (m_pin >= 54) pin -= 54; // allow for channel or pin numbers
    #elif defined(__AVR_ATmega32U4__)
        if (m_pin >= 18) pin -= 18; // allow for channel or pin numbers
    #elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__)
        if (m_pin >= 24) pin -= 24; // allow for channel or pin numbers
    #elif defined(analogPinToChannel) && (defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__))
        m_pin = analogPinToChannel(m_pin);
    #else
        if (m_pin >= 14) m_pin -= 14; // allow for channel or pin numbers
    #endif

    #if defined(__AVR_ATmega32U4__)
        m_pin = analogPinToChannel(m_pin);
        ADCSRB = (ADCSRB & ~(1 << MUX5)) | (((m_pin >> 3) & 0x01) << MUX5);
    #elif defined(ADCSRB) && defined(MUX5)
        ADCSRB = (ADCSRB & ~(1 << MUX5)) | ((m_(pin >> 3) & 0x01) << MUX5);
    #endif
}

AnalogIn::~AnalogIn() {
}

AnalogIn::operator int() const {
    uint8_t low, high;
    #if defined(ADMUX)
        ADMUX = (analog_reference << 6) | (m_pin & 0x07);
    #endif
    #if defined(ADCSRA) && defined(ADCL)
        sbi(ADCSRA, ADSC);
        while (bit_is_set(ADCSRA, ADSC));
        low  = ADCL;
        high = ADCH;
    #else
        low  = 0;
        high = 0;
    #endif
    if (m_isIntMapped == 1) {
        return (high << 8) | low;
    } else {
        return map(((high << 8) | low),m_low,m_high,m_iLowValue,m_iHighValue);
    }
}

AnalogIn::operator float() const {
    uint8_t low, high;
    #if defined(ADMUX)
        ADMUX = (analog_reference << 6) | (m_pin & 0x07);
    #endif
    #if defined(ADCSRA) && defined(ADCL)
        sbi(ADCSRA, ADSC);
        while (bit_is_set(ADCSRA, ADSC));
        low  = ADCL;
        high = ADCH;
    #else
        low  = 0;
        high = 0;
    #endif
    if (m_isFloatMapped == 1) {
        return map_to_float(((high << 8) | low),float(m_low),float(m_high),m_fLowValue,m_fHighValue);
    } else {
        int m_ret = (high << 8) | low;
        return float(m_ret);
    }
}

void AnalogIn::createIntMap(int lowValue, int highValue) {
    m_iLowValue = lowValue;
    m_iHighValue = highValue;
}

void AnalogIn::createFloatMap(float lowValue, float highValue) {
    m_fLowValue = lowValue;
    m_fHighValue = highValue;
}

void AnalogIn::setADCDepth(uint8_t bits) {
    switch(bits) {
        case 12: {m_high = 4095; break;}
        case 8: {m_high = 255;};
        default: {m_high = 1023;}
    }
}
