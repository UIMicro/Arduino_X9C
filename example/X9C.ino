#include "X9C.h"

X9C* res = nullptr;
void setup() {
    res = new X9C(A3, A4, A5);
    Serial.begin(230400);
    pinMode(A6, INPUT);
  // put your setup code here, to run once:
}

void loop() {
    for (int i = 0; i < 100; ++i) {
        res->setPos(i);
        delay(10);
    }
}
