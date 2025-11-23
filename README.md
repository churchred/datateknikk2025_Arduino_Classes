# Arduino Sensor & Device Controller Library

This library provides simple controller classes for common Arduino sensors and devices.  
Each controller is easy to use, has clear function names, and includes a small example in its own README.

All controllers are designed to be user-friendly.

---

## Included Controllers

### Input Sensors
- **Button**
- **Light Sensor** – LDR
- **Motion Sensor** – PIR HC-SR501
- **Soil Sensor** - SparkFun Soil Moisture Sensor
- **Temperature Sensor** – BME280
- **Keypad** – 3x4 Keypad

### RFID
- **RFID Sensor** – RFID RC522

### Display
- **OLED Screen** – OLED BME12864-11

### Output Devices
- **LED**
- **Servo** – SG90 servo


---

## How to Use

1. Include the controller you need in your sketch:

```cpp
#include "ButtonController.h"
#include "LightSensorController.h"
#include "MotionSensorController.h"
#include "SoilSensorController.h"
#include "TemperatureSensorController.h"
#include "RfidSensorController.h"
#include "OledScreenController.h"
#include "LedController.h"
#include "ServoController.h"
