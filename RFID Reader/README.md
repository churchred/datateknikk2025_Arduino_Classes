# RfidSensorController

## Description

`RfidSensorController` is a library that makes reading RFID tags easier by providing premade functions.

---

## Available Functions

| Function | Description                                                                  |
|----------|------------------------------------------------------------------------------|
| `RfidSensorController()` | Creates the RFID controller.                                                 |
| `void setup()` | Initializes SPI and the MFRC522 reader. Must be called in `setup()`.         |
| `int readCard()` | Reads a card if present. Returns: 0 = no card, 1 = allowed, 2 = not allowed. |

---

## Setup

**Wiring (SPI)**

| RFID Pin | Arduino |
|----------|---------|
| SDA      | 10      |
| SCK      | 13      |
| MOSI     | 11      |
| MISO     | 12      |
| RST      | 9       |
| 3.3V     | 3.3V    |
| GND      | GND     |

**Include the controller**

```cpp
#include "RfidSensorController.h"
```

**Create an instance**

```cpp
RfidSensorController rfid;
```

Call `rfid.setup()` in `setup()`.

---

## Example

```cpp
#include <Arduino.h>
#include "RfidSensorController.h"

RfidSensorController rfid;

void setup() {
    Serial.begin(9600);
    rfid.setup();
}

void loop() {

    int result = rfid.readCard();

    if (result == 1) {
        Serial.println("Allowed card");
    }
    else if (result == 2) {
        Serial.println("Unknown card");
    }

    delay(200);
}
```

---

## Notes

- Allowed UIDs are stored directly in the code inside the library.
- `readCard()` prints the UID of any detected card.