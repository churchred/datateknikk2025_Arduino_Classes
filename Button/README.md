# ButtonController

## Description

`ButtonController` is a library that simplifies using `INPUT_PULLUP` logic by providing a set of useful functions.

---

## Available Functions

| Function | Description |
|----------|-------------|
| `ButtonController(int pin)` | Creates a button on the given pin. |
| `bool isPressed()` | True while the button is held down. |
| `bool wasClicked()` | True once when the button is pressed. |
| `bool wasReleased()` | True once when the button is released. |
| `void setLock(bool state)` | Locks or unlocks the button. |

---


## Notes

- Uses pull-up logic: `LOW = pressed`, `HIGH = not pressed`.  
- Good for menus, input actions, and general button handling.
- No resistor is needed (internal pull-up is used)

---

## Setup

**Wiring**

- One side of the button → GND  
- Other side → Digital pin  

**Include the controller**

```cpp
#include "ButtonController.h"
```

**Create an instance**

```cpp
ButtonController button(3);
```

---

## Example

```cpp
#include <Arduino.h>
#include "ButtonController.h"

ButtonController button(3); // Digital pin 3

void setup() {
    Serial.begin(9600);
}

void loop() {

    // Check for click
    if (button.wasClicked()) {
        Serial.println("Button clicked!");
    }

    // Check for release
    if (button.wasReleased()) {
        Serial.println("Button released!");
    }

    // Check if the button is held down
    if (button.isPressed()) {
        Serial.println("Button is being held");
        delay(150); // Slow down prints
    }
}
```


