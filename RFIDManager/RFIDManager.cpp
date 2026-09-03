#include "RFIDManager.h"
#include "Config.h"

RFIDManager::RFIDManager(
byte uid0,
byte uid1,
byte uid2,
byte uid3
)
: rfid(RFID_SS_PIN, RFID_RST_PIN)
{
validUID[0] = uid0;
validUID[1] = uid1;
validUID[2] = uid2;
validUID[3] = uid3;
}

void RFIDManager::begin()
{
SPI.begin();
rfid.PCD_Init();
}

bool RFIDManager::isAuthorized()
{
if(!rfid.PICC_IsNewCardPresent())
return false;

if(!rfid.PICC_ReadCardSerial())
    return false;

for(byte i=0;i<4;i++)
{
    if(rfid.uid.uidByte[i] != validUID[i])
    {
        return false;
    }
}

return true;

}