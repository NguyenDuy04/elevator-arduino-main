enum ElevatorState
{
WAIT_RFID,
IDLE,
MOVING_UP,
MOVING_DOWN,
DOOR_OPENING,
DOOR_OPEN,
DOOR_CLOSING
};

class ElevatorController
{
private:
MotorStepper* motor;
ServoDoor* door;
FloorSensors* sensors;
FloorLED* leds;
DisplayLCD* display;
FloorQueue* queue;

ElevatorState state;

bool authorized;

int currentFloor;
int targetFloor;

unsigned long doorTimer;

public:
ElevatorController(
MotorStepper* motor,
ServoDoor* door,
FloorSensors* sensors,
FloorLED* leds,
DisplayLCD* display,
FloorQueue* queue
);

void begin();

void authorize();
bool isAuthorized();

void processButtons();
void processQueue();

void update();

};

void ElevatorController::processButtons()
{
for(int i=0;i<4;i++)
{
if(mcp.digitalRead(i) == LOW)
{
queue->addRequest(i + 1);
}
}
}

void ElevatorController::processQueue()
{
if(!queue->hasRequest())
return;

targetFloor = queue->getNextFloor();

queue->clearRequest(targetFloor);

display->showFloor(
    currentFloor,
    targetFloor
);

if(targetFloor > currentFloor)
{
    motor->moveUp();
    state = MOVING_UP;
}
else if(targetFloor < currentFloor)
{
    motor->moveDown();
    state = MOVING_DOWN;
}
else
{
    state = DOOR_OPENING;
}

}