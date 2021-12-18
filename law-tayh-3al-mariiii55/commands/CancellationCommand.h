#ifndef CANCELLATIONCOMMAND_H
#define CANCELLATIONCOMMAND_H
#include "Command.h"

class CancellationCommand : public Command
{
public:
	CancellationCommand(StationData*, MissionInputData);
	virtual ~CancellationCommand();

	virtual void execute();
};

#endif // !CANCELLATIONCOMMAND_H

