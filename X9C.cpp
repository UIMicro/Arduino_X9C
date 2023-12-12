#include "X9C.h"

X9C::X9C(int8_t CS, int8_t INC, int8_t UD) : CS(CS), INC(INC), UD(UD) {
    pinMode(CS, OUTPUT);
    pinMode(INC, OUTPUT);
    pinMode(UD, OUTPUT);

    // initialize resistor value
    digitalWrite(INC, HIGH);
    digitalWrite(UD, HIGH);
    digitalWrite(CS, LOW);
    for (uint8_t i = lowerLimit; i <= upperLimit; ++i) {
        delay(1);
        digitalWrite(INC, LOW);
        delay(1);
        digitalWrite(INC, HIGH);
    }
    delay(1);
    digitalWrite(CS, HIGH);

    wiperPos = upperLimit;
}

void X9C::setPos(int16_t pos) {
    if (pos < lowerLimit) pos = lowerLimit;
    if (pos > upperLimit) pos = upperLimit;
    if (pos == wiperPos) return;
    int16_t pulseCount;
    if (pos < wiperPos) {
        pulseCount = wiperPos - pos;
        digitalWrite(UD, LOW);
    }
    else {
        pulseCount = pos - wiperPos;
        digitalWrite(UD, HIGH);
    }
    digitalWrite(INC, HIGH);
    digitalWrite(CS, LOW);
    for (int16_t i = 0; i < pulseCount; ++i) {
        delay(1);
        digitalWrite(INC, LOW);
        delay(1);
        digitalWrite(INC, HIGH);
    }
    delay(1);
    digitalWrite(CS, HIGH);
    wiperPos = pos;
}

int16_t X9C::getPos() {
    return wiperPos;
}

void X9C::reset() {
    wiperPos = lowerLimit;
    this->setPos(upperLimit);
}