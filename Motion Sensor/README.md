# MotionSensorController

## Description

`MotionSensorController` is a library that makes working with motion sensors easier through simple helper functions.

---

## Available Functions

| Function | Description |
|----------|-------------|
| `MotionSensorController(int pin)` | Creates a motion sensor on the given analog pin. |
| `void setThreshold(int newThreshold)` | Sets the threshold for motion detection. |
| `int getValue()` | Returns the raw sensor reading (0–1023). |
| `bool checkMotion()` | Returns true if the reading is below the threshold. |

---

## Setup

**Wiring**

- Sensor output → Analog pin (e.g., A1)
- Other sensor pins to 5V and GND as required
- A LOW value means it detected motion.

**Include the controller**

```cpp
#include "MotionSensorController.h"
```

**Create an instance**

```cpp
MotionSensorController motion(A1);
motion.setThreshold(450); // Optional
```

---

## Example

```cpp
#include <Arduino.h>
#include "MotionSensorController.h"

MotionSensorController motion(A1);

void setup() {
    Serial.begin(9600);
    motion.setThreshold(450); // Optional: adjust sensitivity
}

void loop() {

    int rawValue = motion.getValue();
    Serial.print("Raw: ");
    Serial.println(rawValue);

    if (motion.checkMotion()) {
        Serial.println("Motion detected!");
    }

    delay(200);
}
```