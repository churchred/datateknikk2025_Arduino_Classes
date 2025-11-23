# LedController

## Description

`LedController` is a library that makes it easy to control LEDs with basic functions.

---

## Available Functions

| Function | Description |
|----------|-------------|
| `LedController(int pin)` | Creates an LED controller on the given pin. |
| `bool getState()` | Returns the current LED state (true = on). |
| `void toggleState()` | Flips the LED between on and off. |
| `void setState(bool state)` | Sets the LED on (true) or off (false). |

---

## Setup

**Wiring**

- LED → resistor → digital pin
- LED → GND(5V = 220ohm)

**Include the controller**

```cpp
#include "LedController.h"
```

**Create an instance**

```cpp
LedController led(6);
```

---

## Example

```cpp
#include <Arduino.h>
#include "LedController.h"

LedController led(6); // Digital pin 6

void setup() {
}

void loop() {

    // Toggle LED every half second
    led.toggleState();
    delay(500);
}
```

