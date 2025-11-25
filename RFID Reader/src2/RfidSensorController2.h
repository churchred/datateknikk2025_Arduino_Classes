// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#ifndef RFID_SENSOR_CONTROLLER_H
#define RFID_SENSOR_CONTROLLER_H

#pragma once
#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>

// Pins for RFID
#define SDA_PIN 10
#define RST_PIN 9
#define MISO_PIN 11
#define MOSI_PIN 12
#define SCK_PIN 13


// En klasse som representerer en sensor
class RfidSensorController {
private:
    // How many codes do we have?
    static const int uidCount = 2;

    // Each registered valid code
    const byte codeRegister[uidCount][4] = {
        {0xE6, 0xCA, 0xE5, 0x00},  // E6 CA E5 00
        {0x99, 0xFC, 0xE7, 0x00},  // 99 FC E7 00
    };

    // Length of each UID in the register list
    const byte uidLengths[uidCount] = {4, 4};

    MFRC522 reader;

    // Check if code is allowed
    bool isAllowed(const byte* uid, byte length);

    // Prints the cards code
    void getCode(const byte* uid, byte length);

public:
    // Constructor
    RfidSensorController();

    // Sets up everything
    void setup();

    // Reads card if one is present
    int readCard();
};

#endif // RFID_SENSOR_CONTROLLER_H
