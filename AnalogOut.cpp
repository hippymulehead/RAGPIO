#include <AnalogOut.h>
#include "wiring_private.h"
#include "pins_arduino.h"
#include <DigitalOut.h>

AnalogOut::AnalogOut() {
}

AnalogOut::AnalogOut(int pinNumber) {
    m_pin = pinNumber;
    pinMode(m_pin, OUTPUT);
    m_out.setup(m_pin, OUTPUT);
}

AnalogOut::~AnalogOut() {
}

int AnalogOut::value() {
    return m_s;
}

void AnalogOut::setMap(int lowValue, int highValue) {
    m_low = lowValue;
    m_high = highValue;
}

int AnalogOut::operator= (int s) {
    m_s = s;
    m_state = map(m_s,m_low,m_high,0,255);
    if (m_state == 0) {
		digitalWrite(m_pin, LOW);
	} else if (m_state == 255) {
		digitalWrite(m_pin, HIGH);
	} else {
		switch(digitalPinToTimer(m_pin)) {
			#if defined(TCCR0) && defined(COM00) && !defined(__AVR_ATmega8__)
			case TIMER0A:
				sbi(TCCR0, COM00);
				OCR0 = m_state;
				break;
			#endif

			#if defined(TCCR0A) && defined(COM0A1)
			case TIMER0A:
				sbi(TCCR0A, COM0A1);
				OCR0A = m_state;
				break;
			#endif

			#if defined(TCCR0A) && defined(COM0B1)
			case TIMER0B:
				sbi(TCCR0A, COM0B1);
				OCR0B = m_state;
				break;
			#endif

			#if defined(TCCR1A) && defined(COM1A1)
			case TIMER1A:
				sbi(TCCR1A, COM1A1);
				OCR1A = m_state;
				break;
			#endif

			#if defined(TCCR1A) && defined(COM1B1)
			case TIMER1B:
				sbi(TCCR1A, COM1B1);
				OCR1B = m_state;
				break;
			#endif

			#if defined(TCCR2) && defined(COM21)
			case TIMER2:
				sbi(TCCR2, COM21);
				OCR2 = m_state;
				break;
			#endif

			#if defined(TCCR2A) && defined(COM2A1)
			case TIMER2A:
				sbi(TCCR2A, COM2A1);
				OCR2A = m_state;
				break;
			#endif

			#if defined(TCCR2A) && defined(COM2B1)
			case TIMER2B:
				sbi(TCCR2A, COM2B1);
				OCR2B = m_state;
				break;
			#endif

			#if defined(TCCR3A) && defined(COM3A1)
			case TIMER3A:
				sbi(TCCR3A, COM3A1);
				OCR3A = m_state;
				break;
			#endif

			#if defined(TCCR3A) && defined(COM3B1)
			case TIMER3B:
				sbi(TCCR3A, COM3B1);
				OCR3B = m_state;
				break;
			#endif

			#if defined(TCCR3A) && defined(COM3C1)
			case TIMER3C:
				sbi(TCCR3A, COM3C1);
				OCR3C = m_state;
				break;
			#endif

			#if defined(TCCR4A)
			case TIMER4A:
				sbi(TCCR4A, COM4A1);
				#if defined(COM4A0)
				cbi(TCCR4A, COM4A0);
				#endif
				OCR4A = m_state;
				break;
			#endif

			#if defined(TCCR4A) && defined(COM4B1)
			case TIMER4B:
				sbi(TCCR4A, COM4B1);
				OCR4B = m_state;
				break;
			#endif

			#if defined(TCCR4A) && defined(COM4C1)
			case TIMER4C:
				sbi(TCCR4A, COM4C1);
				OCR4C = m_state;
				break;
			#endif

			#if defined(TCCR4C) && defined(COM4D1)
			case TIMER4D:
				sbi(TCCR4C, COM4D1);
				#if defined(COM4D0)
				cbi(TCCR4C, COM4D0);
				#endif
				OCR4D = m_state;
				break;
			#endif


			#if defined(TCCR5A) && defined(COM5A1)
			case TIMER5A:
				sbi(TCCR5A, COM5A1);
				OCR5A = m_state;
				break;
			#endif

			#if defined(TCCR5A) && defined(COM5B1)
			case TIMER5B:
				sbi(TCCR5A, COM5B1);
				OCR5B = m_state;
				break;
			#endif

			#if defined(TCCR5A) && defined(COM5C1)
			case TIMER5C:
				sbi(TCCR5A, COM5C1);
				OCR5C = m_state;
				break;
			#endif

			case NOT_ON_TIMER:
			default:
				if (m_state < 128) {
					digitalWrite(m_pin, LOW);
				} else {
					digitalWrite(m_pin, HIGH);
				}
		}
	}
    return m_state;
}
