#ifndef BUTTONCONTROLLER_H
#define BUTTONCONTROLLER_H

#include <Arduino.h>

// Class for a pull-up button
class ButtonController {
private:
    int pin;
    bool locked = false;   // Checks if button is locked or not
    bool lastState = HIGH; // Keeps track of last pressed state so a click only registeres once

public:
    // Constructor
    ButtonController(int pin);

    // Check if button is pressed (only true if not locked)
    bool isPressed();

    // Checks if the button was clicked
    bool wasClicked();

    // Checks if the button was released
    bool wasReleased();

    // Lock or unlock the button
    void setLock(bool state);
};

#endif
