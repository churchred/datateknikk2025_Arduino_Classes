// ------------------------------------------------------------
//  Made by Kristoffer Kirkerød — 2025
// ------------------------------------------------------------

#include "RfidSensorController.h"

// Konstruktør – settes opp når objektet lages
//
RfidSensorController::RfidSensorController():reader(SDA_PIN, RST_PIN){

}


void RfidSensorController::setup(){
  SPI.begin();
  reader.PCD_Init();
}

// Logic for reading a card. This also checks it card is valid
//
int RfidSensorController::readCard() {

  // Checks to see if there is a card present or not
  if (!reader.PICC_IsNewCardPresent()) return 0;

  // Try to read data from the card
  if (!reader.PICC_ReadCardSerial()) return 0;

  // Save the UID length
  byte uidLength = reader.uid.size;

  // Reader internal UID pointer
  byte* uid = reader.uid.uidByte;

  // Prints the code if one is present
  if (uidLength != 0){
    Serial.print("Code: ");
    Serial.println(getCode(uid, uidLength));
  }

  // Stop communication with this card
  reader.PICC_HaltA();

  // Return whether this UID is allowed
  return (isAllowed(uid, uidLength) ? 1 : 2);
}


// Checks if card is valid or not
//
bool RfidSensorController::isAllowed(const byte* uid, byte len) {

  // Goes through every code in the register list.
  for (int i = 0; i < uidCount; i++) {

    // If UID length doesn't match expected length, skip
    if (len != uidLengths[i]) continue;

    // Makes a flag
    bool match = true;

    // Compare every byte until a mismatch is found
    for (byte j = 0; j < len; j++) {
      if (uid[j] != codeRegister[i][j]) {
        match = false;
        break;
      }
    }

    // UID matched one in list, then stop searching and return true
    if (match) return true;
  }

  // No UID matched
  return false;
}



void RfidSensorController::getCode(const byte* uid, byte len) {

  if (len == 0) {
    Serial.print(F("Ingen UID tilgjengelig"));
    return;
  }

  // Print each byte of UID in HEX
  for (byte i = 0; i < len; ++i) {

    if (i > 0) {
      Serial.print(':');  // separator
    }

    // Leading zero for single-digit HEX values
    if (uid[i] < 0x10) {
      Serial.print('0');
    }

    Serial.print(uid[i], HEX);
  }

  // New line for better readabbility
  Serial.println();
}
