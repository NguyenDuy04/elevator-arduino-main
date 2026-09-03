#ifndef MOTOR_STEPPER_H
#define MOTOR_STEPPER_H

#include <AccelStepper.h>

class MotorStepper {
private:
    AccelStepper stepper;
    bool movingUpFlag;
    bool movingDownFlag;

public:
    MotorStepper();

    void begin();

    void moveUp();
    void moveDown();
    void stop();

    void run();

    bool isMovingUp();
    bool isMovingDown();
};

#endif