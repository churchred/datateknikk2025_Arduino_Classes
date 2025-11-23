// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#include "SoilSensorController.h"

// Konstruktør – settes opp når objektet lages
SoilSensorController::SoilSensorController(int pin){
    pinMode(pin, INPUT);
    this->pin = pin;


}

// Getter for Pin value
int SoilSensorController::getPin(){
    return this->pin;
}

// Set minimum value (dry)
void SoilSensorController::setMin(int value) {
    this->minValue = value;
}

// Set maximum value (wet)
void SoilSensorController::setMax(int value) {
    this->maxValue = value;
}

// Set both min and max  values
void SoilSensorController::setRange(int minValue, int maxValue) {
    this->minValue = minValue;
    this->maxValue = maxValue;
}

// Read the sensor's current raw value (0–1023)
void SoilSensorController::readSensor() {
    lastReadValue = analogRead(pin);
}

// Read current moisture level as percentage (0–100%)
int SoilSensorController::getCurrentPercent() {

    // Convert lastReadValue to percent based on min/max-values
    int percent = map(lastReadValue, minValue, maxValue, 0, 100);

    // Clamp between 0 and 100
    // (Tips from StackOverflow because values can be sliglhy bigger or smaller than min/mix sometimess)
    return constrain(percent, 0, 100);
}
