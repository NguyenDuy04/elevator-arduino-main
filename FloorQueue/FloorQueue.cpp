#include "FloorQueue.h"

FloorQueue::FloorQueue()
{
for(int i=0;i<4;i++)
{
requests[i] = false;
}
}

void FloorQueue::addRequest(int floor)
{
if(floor < 1 || floor > 4)
return;

requests[floor - 1] = true;

}

bool FloorQueue::hasRequest()
{
for(int i=0;i<4;i++)
{
if(requests[i])
return true;
}

return false;

}

int FloorQueue::getNextFloor()
{
for(int i=0;i<4;i++)
{
if(requests[i])
{
return i + 1;
}
}

return -1;

}

void FloorQueue::clearRequest(int floor)
{
if(floor < 1 || floor > 4)
return;

requests[floor - 1] = false;

}