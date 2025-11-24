//
// Created by krist on 23.11.2025.
//

#include "ServoController.h"


// Constructor
ServoController::ServoController(int pin) {
    this->pin = pin;
    myservo.attach(pin);
    currentPos = myservo.read();
}


// Set the speed in which the servo moves
void ServoController::setSpeed(int speed) {

    // Stops it from being too low or too high
    this->speed = constrain(speed, 1, 10);
}


void ServoController::setTargetPos(int targetPos) {

    // It cant move beyond the scope of 0 and 180 degrees, so we limit it here
    this->targetPos = constrain(targetPos, 0, 180);
}

// Returns the current servo position in Degrees
int ServoController::getCurrentPos() {
    return currentPos;
}

// Must be run inside main loop in the main script
// Moves the servo where it needs to be, or does nothing if it
// is already there
void ServoController::moveServo() {

    // If the servo is where we want it to be
    if (targetPos == currentPos) {
        return;
    }

    // Gets the current time since Arduino tunred on
    unsigned long currentMillis = millis();

    // Only update every 15ms
    if (currentMillis - lastMillis < timeBetweenMovement) return;
    lastMillis = currentMillis;

    // Logic for moving FORWARDS
    if (currentPos < targetPos) {

        // Move current pos based on speed
        currentPos = currentPos + speed;

        // Check if we moves too far and set us back to target if so.
        if(currentPos > targetPos) {
            currentPos = targetPos;
        }

        // Move the Servo to new position (which is prev+speed)
        myservo.write(currentPos);
    }

    // Logic for moving BACKWARDS
    else if (currentPos > targetPos) {

        // Move current pos based on speed
        currentPos = currentPos - speed;

        // Check if we moves too far and set us back to target if so.
        if(currentPos < targetPos) {
            currentPos = targetPos;
        }

        // Move the Servo to new position (which is prev+speed)
        myservo.write(currentPos);
    }




}
