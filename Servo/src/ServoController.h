//
// Created by krist on 23.11.2025.
//

#ifndef CHURCHREDS_CLASSES_SERVO_H
#define CHURCHREDS_CLASSES_SERVO_H

#include <Servo.h>
#include <Arduino.h>

class ServoController {
private:

    // The actuall Servo class fron Arduino
    Servo myservo;
    int pin;

    // Movment stuff (in degrees)
    int targetPos = 0;  // Where you want to move to
    int currentPos;     // Current position (is set in the constructor)
    int speed = 1;      // Speed you move each interval

    // Keeps track of last movement
    unsigned long lastMillis = 0;
    int timeBetweenMovement = 15;

public:

    // Constructor
    ServoController(int pin);

    // Change speed (in degrees)
    void setSpeed(int speed);

    // Chose where, in degrees, you want it to move
    void setTargetPos(int targetPos);

    // Get the current pos
    int getCurrentPos();

    // This needs to be in the main loop always.
    // Does nothing if current and target pos are the same
    void moveServo();
};


#endif //CHURCHREDS_CLASSES_SERVO_H