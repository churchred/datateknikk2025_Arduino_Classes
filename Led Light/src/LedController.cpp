// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#include "LedController.h"

// Konstruktør – settes opp når objektet lages
LedController::LedController(int pin){
    pinMode(pin, OUTPUT);
    this->pin = pin;
}

// Gets the current state of the light
bool LedController::getState(){
    return digitalRead(this->pin);
}

// Toggle state of light
void LedController::toggleState(){
    digitalWrite(this->pin, !digitalRead(this->pin));
}

// Sets the current state of the light
void LedController::setState(bool state){
    digitalWrite(this->pin, state);
}
