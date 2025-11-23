#ifndef KEYPADCONTROLLER_H
#define KEYPADCONTROLLER_H

#pragma once
#include <Arduino.h>

class KeypadController {
private:

    static const int pinCount = 7;
    int pins[pinCount];

    void setAllInputPullup();

public:
    // Constructor (7-pin keypad)
    KeypadController(int p1,int p2,int p3,int p4,int p5,int p6,int p7);

    // Key-mapping process
    // Maps each key because keypads are often different inside
    // Should run in setup <---
    void keyMapping();

    // Detects which key is pressed
    char getKeyPressed();
};

#endif
