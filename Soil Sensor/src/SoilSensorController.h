#ifndef SOILSENSORCONTROLLER_H
#define SOILSENSORCONTROLLER_H

#pragma once
#include <Arduino.h>

// En klasse som representerer en sensor koblet til en analog pin
class SoilSensorController {
private:
    int pin;
    int minValue = 0;       // Most likely min value
    int maxValue = 1023;    // Most likely max value
    int lastReadValue;

public:
    // Constructor
    SoilSensorController(int pin);

    // Get the analog pin used by the sensor
    int getPin();

    // Set minimum calibration value (dry)
    void setMin(int value);

    // Set maximum calibration value (wet)
    void setMax(int value);

    // Set both min and max calibration values
    void setRange(int minValue, int maxValue);

    // Read the sensor's current raw value (0–1023)
    void readSensor();

    // Read current moisture level as percentage (0–100%)
    int getCurrentPercent();
};

#endif // SOILSENSORCONTROLLER_H
