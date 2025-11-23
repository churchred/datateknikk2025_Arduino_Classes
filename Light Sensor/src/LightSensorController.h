// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#ifndef LIGHTSENSORCONTROLLER_H
#define LIGHTSENSORCONTROLLER_H

#pragma once
#include <Arduino.h>

// En klasse som representerer en sensor koblet til en analog pin
class LightSensorController {
private:
    int pin;

public:
    // Constructor
    LightSensorController(int pin);

    // Get temprature
    int getLightValue();
};

#endif
