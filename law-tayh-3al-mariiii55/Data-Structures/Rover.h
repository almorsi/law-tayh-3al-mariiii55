#ifndef ROVER
#define ROVER
#include "..\Defs.h"
#include "Keyable.h"
class Rover :public Keyable
{
private:
	int defaultMissionsToCheckUp;
	int defaultCheckUpDuration;
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
		setKey(speed);
		defaultMissionsToCheckUp = missionsToCheckUp;
		defaultCheckUpDuration = checkUpDuration;
	}
	void resetMissionsToCheckUp();
	void resetCheckUpDuration();
};

#endif 
