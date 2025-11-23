#include <Arduino.h>
#include <OledScreenController.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

OledScreenController::OledScreenController() :
    Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {
}

void OledScreenController::startDisplay() {

    // Checks if we have a screen connected or not
    if (!begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println(F("Could not find a OLED screen with the I2C protocol"));
        while (true);
    }

    // Starts up the screen
    Wire.beginTransmission(OLED_ADDR);
    Serial.println(F("OLED is operational!"));

    // Size and color are needed for the screen to work
    setTextColor(SSD1306_WHITE);
    setTextSize(textSize);
    clearDisplay();
}


void OledScreenController::draw(String text, int cursorY, bool update = false) {

    // Draws on the correct line
    // 8 is the height of 1 pixel text
    setCursor(0, cursorY*8*textSize);

    // What to write
    println(text);

    // If we want to update
    if (update) {
        display();
    }

}

// Fucntion to clear the screen
void OledScreenController::clear() {
    clearDisplay();
    setCursor(0, 0);
}
