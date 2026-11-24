#include "FloorLED.h"

FloorLED::FloorLED(
    Adafruit_MCP23X17* expander
)
{
    mcp = expander;
}

void FloorLED::begin()
{
    for(int i = 8; i <= 11; i++)
    {
        mcp->pinMode(i, OUTPUT);
        mcp->digitalWrite(i, LOW);
    }
}

void FloorLED::updateFloorLed(int floor)
{
    for(int i = 8; i <= 11; i++)
    {
        mcp->digitalWrite(i, LOW);
    }

    switch(floor)
    {
        case 1:
            mcp->digitalWrite(8, HIGH);
            break;

        case 2:
            mcp->digitalWrite(9, HIGH);
            break;

        case 3:
            mcp->digitalWrite(10, HIGH);
            break;

        case 4:
            mcp->digitalWrite(11, HIGH);
            break;
    }
}