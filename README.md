# Arduino_X9C
A simple Arduino Library for X9C series Digitally Controlled Potentiometer

### Tested Hosts:
- Arduino nano ESP32
- Arduino nano

### Peripherals:
- X9C102
- X9C103
- X9C104
- X9C503

### Usage:
1. Put "X9C.h" and "X9C.cpp" in your project folder
2. Include "X9C.h" in your code
3. Create a X9C instance. For example, X9C* resistor = new X9C(CS_PIN, INC_PIN, UD_PIN);
4. Control resistor value using X9C::setPos() function. For example, resistor->setPos(50).
