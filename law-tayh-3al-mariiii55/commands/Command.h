#ifndef COMMAND_H
#define COMMAND_H

//class StationData; should be included here

class Command
{
public:
	Command(/*StationData* sd*/)
		:
		//sd(sd)
	{
	}

	virtual ~Command(){}

	virtual void execute() = 0;
protected:
	//StationData* sd;
};

#endif