#include <cassert>
#include "Rover.h"

void Rover::resetMissionsToCheckUp()
{
	//assert(missionsToCheckUp == 0);
	missionsToCheckUp = defaultMissionsToCheckUp;
}

void Rover::resetCheckUpDuration()
{
	//assert(checkUpDuration == 0);
	checkUpDuration = defaultCheckUpDuration;
}
