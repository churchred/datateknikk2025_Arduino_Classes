# OledScreenController

## Description

`OledScreenController` is a library that simplifies displaying text on OLED screens with Arduino.
The display uses the default I2C address `0x3C` and a 128×64 resolution.

---

## Available Functions


| Function | Description |
|----------|-------------|
| `OledScreenController()` | Creates the OLED display controller. |
| `void startDisplay()` | Initializes the display. Must be called in `setup()`. |
| `void clear()` | Clears the display and resets the cursor. |
| `void draw(const char* text, int cursorX, int cursorY, bool update = false)` | Draws text at X/Y position. `cursorY` is the line number. |
| `void draw(int number, int cursorX, int cursorY, bool update = false)` | Draws an integer at X/Y position. |
| `void draw(float number, int cursorX, int cursorY, bool update = false)` | Draws a float at X/Y position with 2 decimals. |

---

## Setup

**Wiring (I2C)**

- SDA
- SCL
- 5V 
- GND

**Include the controller**

```cpp
#include "OledScreenController.h"
```

**Create an instance**

```cpp
OledScreenController screen;
```

Call `startDisplay()` in `setup()`.

---

## Example

```cpp
#include <Arduino.h>
#include "OledScreenController.h"

OledScreenController screen;

void setup() {
    Serial.begin(9600);

    screen.startDisplay();     // Initialize the display
    screen.clear();            // Clear display
}

void loop() {

    // Draw text at X=0, line 1
    screen.draw("Temp:", 0, 1);

    // Draw number next to it at X=40, same line
    // Some trial and error necesarry to find right X-cords
    screen.draw(23, 40, 1, true);

    delay(1000);
}
```

---

## Notes

- `cursorY` selects the text line;
- Use `update = true` to refresh the display after writing your final line.
- The controller inherits from `Adafruit_SSD1306`, so make sure its included as well.