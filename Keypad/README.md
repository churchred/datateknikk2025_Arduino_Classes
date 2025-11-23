# KeypadController

## Description

`KeypadController` is a library that simplifies using 3×4 keypads with Arduino.

---

## Available Functions

| Function | Description |
|----------|-------------|
| `KeypadController(int p1..p7)` | Creates a keypad controller using 7 digital pins. |
| `void keyMapping()` | Interactive mapping process — user presses each key when prompted. |
| `char getKeyPressed()` | Returns the character of the pressed key (`'0'–'9'`, `'*'`, `'#'`), or `""` if none. |

---

## Notes
 
- Mapping **must be done once**, in `setup()`.  
  - Mapping the keys like this is useful because each keypad is wired differently.
  - Follow the prompting in the terminal.
- Works with standard 12-key matrix keypads (3×4).

---

## Setup

### Wiring

Connect all **7 keypad wires** to **any 7 digital pins**, and provide the pin numbers in the constructor:

    KeypadController keypad(p1, p2, p3, p4, p5, p6, p7);

> No external resistors are needed — uses `INPUT_PULLUP`.

---

### Include the controller

    #include "KeypadController.h"

### Create an instance

    KeypadController keypad(2, 3, 4, 5, 6, 7, 8);

---

## Example

    #include <Arduino.h>
    #include "KeypadController.h"

    KeypadController keypad(2, 3, 4, 5, 6, 7, 8);

    void setup() {
        Serial.begin(9600);

        // Run interactive mapping (press keys when asked)
        keypad.keyMapping();
    }

    void loop() {
        char key = keypad.getKeyPressed();

        if (key != "") {
            Serial.print("Key pressed: ");
            Serial.println(key);
        }

        delay(50); // Avoid excessive polling
    }
