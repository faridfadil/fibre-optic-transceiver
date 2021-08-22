#include "TickSystem.h"


//this method is meant to be in the Update.
void TickSystem::startTickSystem()
{
	//increment the tickcount value by 1.
	(*TickSystem::pointerTickCount)++;
}

//Return the current tick count for conditional comparisons.
int TickSystem::getTickCount()
{
	//return the value stored at p_tickCount, or the value of tickCount (see TickSystem.h).
	return *TickSystem::pointerTickCount;
}

/*
setting the time after which the receiver should listen to the status of the photodiode
or the time after which the transmitter should send the subsequent signal (be it ON or OFF).
*/
void TickSystem::setTickThreshold(int* thresholdValue)
{
	TickSystem::tickThreshold = *thresholdValue;
}

//getter method that gets the value stored in p_tickThreshold or the value of tickThreshold.
int TickSystem::getTickThreshold()
{
	return *TickSystem::pointerTickThreshold;
}