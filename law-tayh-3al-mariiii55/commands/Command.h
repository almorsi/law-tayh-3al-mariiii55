#ifndef COMMAND_H
#define COMMAND_H

#include "..\Defs.h"

class Command
{
public:
	Command( MissionInputData md)
		:
		md(md)
	{
	}

	virtual ~Command(){}

	virtual void execute(StationData*) = 0;
protected:
	MissionInputData md;
};

#endif