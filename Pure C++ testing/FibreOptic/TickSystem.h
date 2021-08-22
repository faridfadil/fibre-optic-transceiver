#pragma once
// tick system class
class TickSystem
{
private:
	int tickCount = 0;
	int* pointerTickCount = &tickCount;

	int tickThreshold;
	int* pointerTickThreshold = &tickThreshold;


public:
	void startTickSystem();
	int getTickCount();
	void setTickThreshold(int* thresholdValue);
	int getTickThreshold();


};

