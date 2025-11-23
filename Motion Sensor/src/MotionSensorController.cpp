#include "MotionSensorController.h"

MotionSensorController::MotionSensorController(int pin) {
    this->pin = pin;
    threshold = 500;
}

void MotionSensorController::setThreshold(int newThreshold) {
    threshold = newThreshold;
}

int MotionSensorController::getValue() {
    return analogRead(pin);
}

bool MotionSensorController::checkMotion() {
    int value = analogRead(this->pin);
    return (value < threshold);
}
