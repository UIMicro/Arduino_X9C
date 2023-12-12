#ifndef _X9C_H
#define _X9C_H

#include "Arduino.h"

class X9C {
private:
    const int16_t lowerLimit = 0;
    const int16_t upperLimit = 99;
    double resistor;
    int8_t CS;
    int8_t INC;
    int8_t UD;
    int16_t wiperPos;
public:
    X9C(int8_t CS, int8_t INC, int8_t UD);
    void setPos(int16_t pos);
    int16_t getPos();
    void reset();
} ;

#endif