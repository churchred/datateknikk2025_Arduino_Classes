// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#ifndef TEMPERATURESENSORCONTROLLER_H
#define TEMPERATURESENSORCONTROLLER_H

#pragma once
#include <Arduino.h>

// En klasse som representerer en sensor koblet til en analog pin
class TemperatureSensorController {
private:
    int pin;

public:
    // Constructor
    TemperatureSensorController(int pin);

    // Get temprature
    float getTemp();
};

#endif // TEMPERATURESENSORCONTROLLER_H
