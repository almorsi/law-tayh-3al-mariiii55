#ifndef MISSION
#define MISSION
#include "..\Defs.h"

class Mission :public Keyable
{
public:
	Mission(){}
	MissionType type;
	int ID;
	int compeletionDay;
	int formlationDay;
	int assignDay;
	int waitingDays;
	int inExecutionDays;
	int targetLocation;
	int missionDuration;
	int significance;
	int daysToBePromoted;
};

#endif // !MISSIONS

