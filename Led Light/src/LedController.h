#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#pragma once
#include <Arduino.h>

// En klasse for LED lys
class LedController {
private:
    int pin;

public:
    // Constructor
    LedController(int pin);

    // Get state (On/True or Off/False)
    bool getState();

    // Toggle
    void toggleState();

    // Turns on or off
    void setState(bool state);

};

#endif
