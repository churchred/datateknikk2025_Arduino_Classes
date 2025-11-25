// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#ifndef OLEDSCREENCONTROLLER_H
#define OLEDSCREENCONTROLLER_H

// OLED Screen code
#include <Adafruit_SSD1306.h>

// Screen size
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64

// Used ONLY when initatizing
#define OLED_ADDR     0x3C
#define OLED_RESET    (-1)

class OledScreenController : public Adafruit_SSD1306 {
private:
    const int textSize = 1;

public:

    // Constructor
    OledScreenController();

    // Initializes the screen (USE IN SETUP)
    void startDisplay();

    // Clears the screen
    void clear();

    // Draw text (OVERLOADED)
    void draw(const char* text, int cursorX, int cursorY, bool update = false);

    // Draw int (OVERLOADED)
    void draw(int number, int cursorX, int cursorY, bool update = false);

    // Draw float (OVERLOADED)
    void draw(float number, int cursorX, int cursorY, bool update = false);

};

#endif // OLEDSCREENCONTROLLER_H
