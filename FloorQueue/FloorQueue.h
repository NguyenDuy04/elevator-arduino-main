#ifndef FLOOR_QUEUE_H
#define FLOOR_QUEUE_H

class FloorQueue
{
private:
bool requests[4];

public:
FloorQueue();

void addRequest(int floor);

bool hasRequest();

int getNextFloor();

void clearRequest(int floor);

};

#endif