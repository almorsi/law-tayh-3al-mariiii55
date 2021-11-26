#ifndef FORMULATIONCOMMAND_H
#define FORMULATIONCOMMAND_H

#include "..\Defs.h"
#include "Command.h"

class FormulationCommand : public Command
{
public:
	FormulationCommand(/*StationData*,*/ MissionFormulationData);
	~FormulationCommand();

	virtual void execute();

private:
	MissionFormulationData mfd;
};

#endif // !FORMULATIONCOMMAND_H
