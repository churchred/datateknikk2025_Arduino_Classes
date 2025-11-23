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
| `void draw(String text, int cursorY, bool update = false)` | Draws text on the chosen line. `cursorY` is the line number. `update=true` refreshes the screen immediately. |

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

    // Draw text on line 1 without updating the screen yet
    screen.draw("Line 1 text", 1);

    // Update the screen after drawing on multiple lines
    screen.draw("Line 2 text", 2, true);

    delay(1000);
}
```

---

## Notes

- `cursorY` selects the text line;
- Use `update = true` to refresh the display after writing your final line.
- The controller inherits from `Adafruit_SSD1306`, so make sure its included as well.