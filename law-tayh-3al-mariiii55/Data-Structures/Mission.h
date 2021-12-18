#ifndef MISSION
#define MISSION
#include "..\Defs.h"

class Mission :public Keyable
{
public:
	Mission(){}
	MissionInputData mid{NONE_MT, 0, 0, 0, 0, 0};
	int compeletionDay;
	int formlationDay;
	int assignDay;
	int waitingDays;
	int inExecutionDays;
	int daysToBePromoted;
};

#endif // !MISSIONS

