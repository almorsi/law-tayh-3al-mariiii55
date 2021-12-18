#ifndef ROVER
#define ROVER
#include "..\Defs.h"

class Rover :public Keyable
{
public:
	RoverType rovertype;
	int checkUpDuration;
	int speed;
	int missionsToCheckUp;
	Rover():rovertype(NONE_RT),checkUpDuration(0),speed(0),missionsToCheckUp(0)
	{}
};

#endif 
