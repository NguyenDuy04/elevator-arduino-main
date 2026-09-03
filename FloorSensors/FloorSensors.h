#ifndef FLOOR_SENSORS_H
#define FLOOR_SENSORS_H

class FloorSensors {
private:
    int sensorPins[4];

public:
    FloorSensors();

    void begin();

    int getCurrentFloor();
};

#endif