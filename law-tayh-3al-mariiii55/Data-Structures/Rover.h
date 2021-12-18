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
};

#endif 
