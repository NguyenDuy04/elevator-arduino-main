#include "Config.h"
#include "MotorStepper.h"
#include "ServoDoor.h"
#include "FloorSensors.h"
#include "FloorLED.h"
#include "DisplayLCD.h"
#include "FloorQueue.h"
#include "RFIDManager.h"
#include "ElevatorController.h"

MotorStepper motor;
ServoDoor door;
FloorSensors sensors;
FloorLED leds(&mcp);
DisplayLCD display;
FloorQueue queue;
RFIDManager rfid(0xDE,0xAD,0xBE,0xEF);

ElevatorController elevator(
&motor,
&door,
&sensors,
&leds,
&display,
&queue
);

void setup()
{
Wire.begin();

mcp.begin_I2C();

motor.begin();
door.begin();
sensors.begin();
leds.begin();
display.begin();
rfid.begin();

elevator.begin();

display.showMessage(
    "Scan RFID",
    "Waiting..."
);

}

void loop()
{
if(!elevator.isAuthorized())
{
if(rfid.isAuthorized())
{
elevator.authorize();
}

    return;
}

elevator.update();

}