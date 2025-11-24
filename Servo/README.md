# ServoController

## Description

`ServoController` is a library that smoothly moves a servo toward a target angle at a chosen speed.
It does not cause delays in the code, because it uses `Millis()` to move incrementally at set intervals.

---

## Available Functions

| Function | Description |
|----------|-------------|
| ServoController(int pin) | Creates a servo controller and attaches a servo to the given pin. |
| void setSpeed(int speed) | Sets how fast the servo moves (1–10 degrees per update). |
| void setTargetPos(int targetPos) | Sets the servo’s target angle (0–180). |
| int getCurrentPos() | Returns the servo’s current angle. |
| void moveServo() | Moves the servo toward the target. Must run continuously in loop(). |

---

## Notes

- Uses `Millis()` to make sure it only updates every 15 ms.
- Speed is always clamped between 1–10.
- Target angle is always clamped between 0–180°.

---

## Setup

Wiring
- Servo signal → Digital pin
- Servo VCC → 5V
- Servo GND → GND

Include the controller  
`#include "ServoController.h"`

Create an instance  
`ServoController servo(9);`

---

## Example

    #include <Arduino.h>
    
    #include "ServoController.h"
    
    ServoController servo(9);
    
    void setup() {
        Serial.begin(9600);

        // Set wanted angle. Can be set anywhere after initialization. 
        servo.setTargetPos(100); 
    }
    
    void loop() {

        // The Servo will move towards and angle of 100 degrees, by
        // intervalls of 1 (the current speed) every 15ms.
        servo.moveServo();

    }
