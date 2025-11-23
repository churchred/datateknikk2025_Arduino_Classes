// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#include "TemperatureSensorController.h"

// Konstruktør – settes opp når objektet lages
TemperatureSensorController::TemperatureSensorController(int pin){
    pinMode(pin, INPUT);
    this->pin = pin;
}

// Gets the current temp from the sensor
float TemperatureSensorController::getTemp(){

    int rawData = analogRead(this->pin);
    float voltage = rawData  * (5.0 / 1023.0);
    float temp = (voltage - 0.5) * 100.0;

    return temp;
}
