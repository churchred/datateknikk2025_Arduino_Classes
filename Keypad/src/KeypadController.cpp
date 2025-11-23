#include "KeypadController.h"

struct PinPair {
    int readPin;
    int drivePin;
};

static const int numberOfButtons = 12;

// Stores pin pairs for all 12 keys
static PinPair keypadLayout[numberOfButtons];

// All keypad symbols/buttons
static const char keys[numberOfButtons] = {
    '1','2','3',
    '4','5','6',
    '7','8','9',
    '*','0','#'
};

// Constructor takes in the pins, but does NOT use them yet
//
KeypadController::KeypadController(int p1,int p2,int p3,int p4,int p5,int p6,int p7) {
    pins[0] = p1;
    pins[1] = p2;
    pins[2] = p3;
    pins[3] = p4;
    pins[4] = p5;
    pins[5] = p6;
    pins[6] = p7;

}


// Set all pins as INPUT_PULLUP
//
void KeypadController::setAllInputPullup() {
    for (int i = 0; i < pinCount; i++) {
        pinMode(pins[i], INPUT_PULLUP);
    }
}



// Has the user press each key to map it.
// Is used becuase each keypad often is DIFFERENT
//
void KeypadController::keyMapping() {
    Serial.println("Press each key when prompted.\n");

    // Initialising all buttons with correct pin and as PULLUP
    setAllInputPullup();

    // Goes through each button
    for (int k = 0; k < numberOfButtons; k++) {

        // Prompts user to press a button
        Serial.print("Press key: ");
        Serial.println(keys[k]);

        // Falg so we know when to stop checking for keyinput for each key
        bool mapped = false;

        while (!mapped) {

            // Goes through EACH combo of drive and read and maps to correct button
            for (int driveIdx = 0; driveIdx < pinCount; driveIdx++) {

                // Sets all pins to pullup, and ONE to output and low.
                // In each loop, this gives us which pin to check
                for (int i = 0; i < pinCount; i++) {
                    if (i == driveIdx) {
                        pinMode(pins[i], OUTPUT);
                        digitalWrite(pins[i], LOW);
                    } else {
                        pinMode(pins[i], INPUT_PULLUP);
                    }
                }

                for (int readIdx = 0; readIdx < pinCount; readIdx++) {

                    // Cannot read from the same pin we are driving
                    if (readIdx == driveIdx) continue;

                    // Gets the read and drive pins in their own int var for easy reading
                    int readPin = pins[readIdx];
                    int drivePin = pins[driveIdx];

                    // LOW means active pin, only ONE pin is low at the time
                    if (digitalRead(readPin) == LOW) {

                        // Store mapping
                        keypadLayout[k].readPin  = readPin;
                        keypadLayout[k].drivePin = drivePin;

                        // Breaks the flag
                        mapped = true;

                        // Wait until key released
                        while (digitalRead(readPin) == LOW) delay(5);

                        // Prints out the info about the mapped pin
                        Serial.print("Mapped key: ");
                        Serial.print(keys[k]);
                        Serial.print(" -> drive: ");
                        Serial.print(drivePin);
                        Serial.print(" read: ");
                        Serial.println(readPin);

                        // Breaks the loop for this drive/read combo and goes to next one
                        break;
                    }
                }

                if (mapped) break;
            }

            delay(5); // Delay to save CPU power..
        }
    }

    Serial.println("\nMapping complete!");
}



// Uses mapped pairs to detect key press
char KeypadController::getKeyPressed() {

    // Reset pins before scanning
    setAllInputPullup();

    for (int i = 0; i < numberOfButtons; i++) {

        int drivePin = keypadLayout[i].drivePin;
        int readPin  = keypadLayout[i].readPin;

        // Drive the drivePin LOW
        pinMode(drivePin, OUTPUT);
        digitalWrite(drivePin, LOW);

        // Check if readPin goes LOW
        if (digitalRead(readPin) == LOW) {

            // Wait for release
            while (digitalRead(readPin) == LOW) delay(5);

            // Reset pin
            pinMode(drivePin, INPUT_PULLUP);

            return keys[i];
        }

        // Reset pin
        pinMode(drivePin, INPUT_PULLUP);
    }

    return 0; // No key pressed
}
