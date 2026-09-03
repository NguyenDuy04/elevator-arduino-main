#ifndef RFID_MANAGER_H
#define RFID_MANAGER_H

#include <SPI.h>
#include <MFRC522.h>

class RFIDManager
{
private:
MFRC522 rfid;

byte validUID[4];

public:
RFIDManager(
byte uid0,
byte uid1,
byte uid2,
byte uid3
);

void begin();

bool isAuthorized();

};

#endif