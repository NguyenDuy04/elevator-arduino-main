#ifndef FLOOR_LED_H
#define FLOOR_LED_H

#include "Adafruit_MCP23X17.h"

class FloorLED {
private:
    Adafruit_MCP23X17* mcp;

public:
    FloorLED(Adafruit_MCP23X17* expander);

    void begin();

    void updateFloorLed(int floor);
};

#endif