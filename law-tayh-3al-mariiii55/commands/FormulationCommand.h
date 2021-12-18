#ifndef FORMULATIONCOMMAND_H
#define FORMULATIONCOMMAND_H
#include "Command.h"

class FormulationCommand : public Command
{
public:
	FormulationCommand(MissionInputData);
	virtual ~FormulationCommand();

	virtual void execute(StationData*);
};

#endif // !FORMULATIONCOMMAND_H
