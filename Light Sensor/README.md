# LightSensorController

## Description

`LightSensorController` is a library that simplifies reading and using light sensor input on Arduino.

---

## Available Functions

| Function | Description |
|----------|-------------|
| `LightSensorController(int pin)` | Creates a light sensor on the given analog pin. |
| `int getLightValue()` | Returns the raw analog light value (0–1023). |

---

## Setup

**Wiring**

- Light sensor → Analog pin (e.g., A0)
- Use a voltage divider if required for your sensor type
- Connect remaining leads to 5V and GND as needed

**Include the controller**

```cpp
#include "LightSensorController.h"
```

**Create an instance**

```cpp
LightSensorController light(A0);
```

---

## Example

```cpp
#include <Arduino.h>
#include "LightSensorController.h"

LightSensorController light(A0);

void setup() {
    Serial.begin(9600);
}

void loop() {
    int value = light.getLightValue();
    Serial.println(value);
    delay(200);
}
```
