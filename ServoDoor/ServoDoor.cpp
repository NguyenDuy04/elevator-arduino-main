#include "ServoDoor.h"

ServoDoor::ServoDoor(
    int pin,
    int openPos,
    int closePos
)
{
    servoPin = pin;
    openAngle = openPos;
    closeAngle = closePos;
    opened = false;
}

void ServoDoor::begin()
{
    doorServo.attach(servoPin);
    closeDoor();
}

void ServoDoor::openDoor()
{
    doorServo.write(openAngle);
    opened = true;
}

void ServoDoor::closeDoor()
{
    doorServo.write(closeAngle);
    opened = false;
}

bool ServoDoor::isOpened()
{
    return opened;
}