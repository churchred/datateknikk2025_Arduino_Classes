// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

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
    //Wire.beginTransmission(OLED_ADDR);
    Serial.println(F("OLED is operational!"));

    // Size and color are needed for the screen to work
    setTextColor(SSD1306_WHITE);
    setTextSize(textSize);
    clearDisplay();
}

// Fucntion to clear the screen
void OledScreenController::clear() {
    clearDisplay();
    setCursor(0, 0);
}

// Fucntion to clear the screen
void OledScreenController::update() {
    display();
}

// If we send in text strings
void OledScreenController::draw(const char* text, int x, int cursorY, bool update) {

    // cursorY * 8 because text height = 8px
    setCursor(x, cursorY * 8 * textSize);

    // Prints the text onto the screen at the cursor location
    println(text);

    // If update is true, then update the screen
    if (update) {
        this->update();
    }
}

// ------------------ 2) INTEGER ------------------

void OledScreenController::draw(int number, int x, int cursorY, bool update) {

    // BUffer to store chars (8 to be safe)
    char buffer[8];

    // integer -> char*
    itoa(number, buffer, 10);

    // Call the draw func again, just this time we send C-strings
    draw(buffer, x, cursorY, update);
}

// ------------------ 3) FLOAT ------------------

void OledScreenController::draw(float number, int x, int cursorY, bool update) {

    // Buffr to store chars (10 to be safe)
    char buffer[10];

    // Floats to C-String. Min 1 value before decimal-point, and its auto limited to 2 decimal points
    dtostrf(number, 1, 2, buffer);


    // Call the draw func again, just this time we send C-strings
    draw(buffer, x, cursorY, update);
}