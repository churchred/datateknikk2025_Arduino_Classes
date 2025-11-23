# TemperatureSensorController

## Description

`TemperatureSensorController` is a library that simplifies reading temperature values from common temperature sensors.

---

## Available Functions

| Function | Description |
|----------|-------------|
| `TemperatureSensorController(int pin)` | Creates a temperature sensor on the given analog pin. |
| `float getTemp()` | Reads the current temperature in Celsius. |

---

## Setup

**Wiring (TMP36 example)**

- Left pin → 5V
- Middle pin → Analog pin (e.g., A3)
- Right pin → GND

**Include the controller**

```cpp
#include "TemperatureSensorController.h"
```

**Create an instance**

```cpp
TemperatureSensorController temp(A3);
```

---

## Example

```cpp
#include <Arduino.h>
#include "TemperatureSensorController.h"

TemperatureSensorController temp(A3);

void setup() {
    Serial.begin(9600);
}

void loop() {

    float t = temp.getTemp();

    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" C");

    delay(500);
}
```

---

## Notes

- The conversion formula assumes a TMP36 or similar analog temperature sensor.
- If your sensor outputs a different voltage curve, adjust the math accordingly.
- Returns temperature in degrees Celsius.
