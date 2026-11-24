#include "FloorSensors.h"
#include <Arduino.h>

FloorSensors::FloorSensors()
{
    sensorPins[0] = A0;
    sensorPins[1] = A1;
    sensorPins[2] = A2;
    sensorPins[3] = A3;
}

void FloorSensors::begin()
{
    for (int i = 0; i < 4; i++)
    {
        pinMode(sensorPins[i], INPUT);
    }
}

int FloorSensors::getCurrentFloor()
{
    for (int i = 0; i < 4; i++)
    {
        if (digitalRead(sensorPins[i]) == LOW)
        {
            return i + 1;
        }
    }

    return -1;
}