#ifndef COMMAND_H
#define COMMAND_H

#include "..\Defs.h"
//class StationData; should be included here

class Command
{
public:
	Command(/*StationData* sd, MissionInputData md*/)
		//:
		//sd(sd),
		//md(md)
	{
	}

	virtual ~Command(){}

	virtual void execute() = 0;
protected:
	//StationData* sd;
	//MissionInputData md;
};

#endif