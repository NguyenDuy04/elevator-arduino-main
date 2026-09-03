void ElevatorController::update()
{
motor->run();

processButtons();

int floor = sensors->getCurrentFloor();

if(floor > 0)
{
    currentFloor = floor;
    leds->updateFloorLed(floor);
}

switch(state)
{
    case IDLE:

        processQueue();
        break;

    case MOVING_UP:

        if(currentFloor == targetFloor)
        {
            motor->stop();
            state = DOOR_OPENING;
        }

        break;

    case MOVING_DOWN:

        if(currentFloor == targetFloor)
        {
            motor->stop();
            state = DOOR_OPENING;
        }

        break;

    case DOOR_OPENING:

        door->openDoor();

        display->showMessage(
            "Door Open",
            ""
        );

        doorTimer = millis();

        state = DOOR_OPEN;

        break;

    case DOOR_OPEN:

        if(millis() - doorTimer >= 3000)
        {
            state = DOOR_CLOSING;
        }

        break;

    case DOOR_CLOSING:

        door->closeDoor();

        display->showMessage(
            "Door Close",
            ""
        );

        state = IDLE;

        break;

    default:
        break;
}

}