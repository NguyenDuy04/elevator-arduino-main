#include "MotorStepper.h"

MotorStepper::MotorStepper()
: stepper(
    AccelStepper::FULL4WIRE,
    2, 4, 3, 5
)
{
    movingUpFlag = false;
    movingDownFlag = false;
}

void MotorStepper::begin()
{
    stepper.setMaxSpeed(600);
    stepper.setAcceleration(300);
}

void MotorStepper::moveUp()
{
    movingUpFlag = true;
    movingDownFlag = false;

    stepper.moveTo(1000000);
}

void MotorStepper::moveDown()
{
    movingUpFlag = false;
    movingDownFlag = true;

    stepper.moveTo(-1000000);
}

void MotorStepper::stop()
{
    movingUpFlag = false;
    movingDownFlag = false;

    stepper.stop();
}

void MotorStepper::run()
{
    stepper.run();
}

bool MotorStepper::isMovingUp()
{
    return movingUpFlag;
}

bool MotorStepper::isMovingDown()
{
    return movingDownFlag;
}