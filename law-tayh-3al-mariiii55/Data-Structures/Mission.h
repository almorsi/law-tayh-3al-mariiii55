#ifndef MISSION
#define MISSION
#include "..\Defs.h"

class Mission :public Keyable
{
public:
	MissionInputData mid;
	int compeletionDay;
	int formlationDay;
	int assignDay;
	int waitingDays;
	int inExecutionDays;
	
	Mission(MissionInputData mid, int cd, int fd, int ad, int wd, int inexd) 
		:
		mid(mid),
		compeletionDay(cd), 
		formlationDay(fd), 
		assignDay(ad),
		waitingDays(wd),
		inExecutionDays(inexd)
	{
		//don't forget to set the key
	}
};

#endif // !MISSIONS

