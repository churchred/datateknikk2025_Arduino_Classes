// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#include "ButtonController.h"

ButtonController::ButtonController(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT_PULLUP);
}


// Pressed down logic
bool ButtonController::isPressed() {

    // If locked, ignore all button presses
    if (locked){
        return false;
    }

    // Pull-up button: LOW = pressed, HIGH = not pressed
    return digitalRead(pin) == LOW;
}

// Single click logic
bool ButtonController::wasClicked() {
    // If locked, ignore all button presses
    if (locked) {
        return false;
    }

    // Gets current state of the button (LOW = pressed)
    bool currentState = digitalRead(pin);

    // Flag to see if we can click the button again
    bool clicked = false;

    // Sees if the button has was unpressed before pressin it
    if (lastState == HIGH && currentState == LOW) {
        clicked = true;
    }

    // Update last state
    lastState = currentState;

    return clicked;

}

// Single release logic
bool ButtonController::wasReleased() {
    // If locked, ignore all button releases
    if (locked) {
        return false;
    }

    // Gets current state of the button (LOW = pressed)
    bool currentState = digitalRead(pin);

    // Flag to see if the button was released
    bool released = false;

    // Check for transition: pressed -> unpressed (LOW -> HIGH)
    if (lastState == LOW && currentState == HIGH) {
        released = true;
    }

    // Update last state
    lastState = currentState;

    return released;
}


// Lock or unlock the button
void ButtonController::setLock(bool state) {
    locked = state;
}
