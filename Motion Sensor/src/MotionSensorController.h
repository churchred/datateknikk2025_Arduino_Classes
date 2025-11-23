// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#ifndef MOTIONSENSORCONTROLLER_H
#define MOTIONSENSORCONTROLLER_H

#include <Arduino.h>

class MotionSensorController {

private:
    int pin;
    int threshold;

public:
    // Constructor takes the analog pin
    MotionSensorController(int pin);

    // Set a new threshold
    void setThreshold(int newThreshold);

    //
    int getValue();

    // Returns true if motion detected
    bool checkMotion();

};

#endif // MOTIONSENSORCONTROLLER_H
