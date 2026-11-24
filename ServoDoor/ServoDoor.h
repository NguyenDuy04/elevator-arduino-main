#ifndef SERVO_DOOR_H
#define SERVO_DOOR_H

#include <Servo.h>

class ServoDoor {
private:
    Servo doorServo;

    int servoPin;
    int openAngle;
    int closeAngle;
    bool opened;

public:
    ServoDoor(
        int pin = 6,
        int openPos = 90,
        int closePos = 0
    );

    void begin();

    void openDoor();
    void closeDoor();

    bool isOpened();
};

#endif