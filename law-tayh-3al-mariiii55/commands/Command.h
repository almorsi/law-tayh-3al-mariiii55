#ifndef COMMAND_H
#define COMMAND_H
#include "..\Defs.h"
struct StationData;

class Command
{
public:
	Command( MissionInputData md)
		:
		md(md)
	{
	}

	virtual ~Command(){}

	virtual bool isTimeToExecute(const int) const;
	virtual void execute(StationData*) = 0;
protected:
	MissionInputData md;
};

#endif