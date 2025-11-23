# SoilSensorController

## Description

`SoilSensorController` is a library that helps you read and use soil moisture data with simple functions.

---

## Available Functions

| Function | Description                                                  |
|----------|--------------------------------------------------------------|
| `SoilSensorController(int pin)` | Creates a soil sensor on the given analog pin.               |
| `void setMin(int value)` | Sets the dry calibration value.                              |
| `void setMax(int value)` | Sets the wet calibration value.                              |
| `void setRange(int minValue, int maxValue)` | Sets both dry and wet calibration values.                    |
| `void readSensor()` | Reads and stores the current raw sensor value.               |
| `int getCurrentPercent()` | Converts the last stored value into a 0–100% moisture level. |

---

## Setup

**Wiring**

- Sensor OUT → Analog pin (e.g., A2)
- Other sensor pins → 3.3V and GND
- Many soil sensors work best with short read intervals and long rest intervals

**Include the controller**

```cpp
#include "SoilSensorController.h"
```

**Create an instance**

```cpp
SoilSensorController soil(A2);
```

Set a calibration range if needed:

```cpp
soil.setRange(300, 800);
```

---

## Example

```cpp
#include <Arduino.h>
#include "SoilSensorController.h"

SoilSensorController soil(A2);

void setup() {
    Serial.begin(9600);

    // Calibrate dry/wet levels
    soil.setRange(300, 800);
}

void loop() {

    soil.readSensor(); // Capture and store the current raw value

    int percent = soil.getCurrentPercent();
    Serial.print("Soil moisture: ");
    Serial.print(percent);
    Serial.println("%");

    delay(500);
}
```

---

## Notes

- Calibration is important; readings vary by sensor model.
- `getCurrentPercent()` clamps values to a valid 0–100% range.
- Works well with capacitive soil moisture sensors.
