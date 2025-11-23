// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#include "LightSensorController.h"

// Konstruktør – settes opp når objektet lages
LightSensorController::LightSensorController(int pin){
   pinMode(pin, INPUT);
   this->pin = pin;
}

// Gets the current temp from the sensor
int LightSensorController::getLightValue(){

    int lightValue = analogRead(this->pin);

    return lightValue;
}
