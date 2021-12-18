#ifndef MISSION
#define MISSION
#include "..\Defs.h"

class Mission :public Keyable
{
public:
	MissionInputData mid{NONE_MT, 0, 0, 0, 0, 0};
	int compeletionDay;
	int formlationDay;
	int assignDay;
	int waitingDays;
	int inExecutionDays;
	int daysToBePromoted;
	
	Mission() :compeletionDay(0), formlationDay(0), assignDay(0),waitingDays(0),inExecutionDays(0),daysToBePromoted(0)
	{}
};

#endif // !MISSIONS

