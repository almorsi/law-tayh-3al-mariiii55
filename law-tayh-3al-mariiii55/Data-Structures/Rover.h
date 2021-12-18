#ifndef ROVER
#define ROVER
#include "..\Defs.h"

class Rover :public Keyable
{
public:
	RoverType rovertype;
	int speed;
	int missionsToCheckUp;
	int checkUpDuration;
	Rover(RoverType rt, int s, int mtc, int cd)
		:rovertype(rt),
		speed(s),
		missionsToCheckUp(mtc),
		checkUpDuration(cd)
	{
		setKey(s);
	}
};

#endif 
