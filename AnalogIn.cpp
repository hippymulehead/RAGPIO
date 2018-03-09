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
	return (high << 8) | low;
}

int AnalogIn::asMapped(int lowValue, int highValue) {
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
	return map(((high << 8) | low),0,1023,lowValue,highValue);
}

float AnalogIn::asFloatMapped(float lowValue, float highValue) {
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
	return map_to_float(((high << 8) | low),0,1023,lowValue,highValue);
}
