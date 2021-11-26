#ifndef CANCELLATIONCOMMAND_H
#define CANCELLATIONCOMMAND_H
#include "Command.h"
#include "..\Defs.h"

class CancellationCommand : public Command
{
public:
	CancellationCommand(/*StationData*, MissionData mcd*/);
	virtual ~CancellationCommand();

	virtual void execute();

private:
	MissionData mcd;
};

#endif // !CANCELLATIONCOMMAND_H

