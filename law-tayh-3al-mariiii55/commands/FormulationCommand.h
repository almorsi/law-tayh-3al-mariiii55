#ifndef FORMULATIONCOMMAND_H
#define FORMULATIONCOMMAND_H

#include "..\Defs.h"
#include "Command.h"

class FormulationCommand : public Command
{
public:
	FormulationCommand(/*StationData*, MissionData*/);
	~FormulationCommand();

	virtual void execute();

private:
	MissionData mfd;
};

#endif // !FORMULATIONCOMMAND_H
