#ifndef FORMULATIONCOMMAND_H
#define FORMULATIONCOMMAND_H
#include "Command.h"

class FormulationCommand : public Command
{
public:
	FormulationCommand(/*StationData*, MissionData*/);
	virtual ~FormulationCommand();

	virtual void execute();
};

#endif // !FORMULATIONCOMMAND_H
