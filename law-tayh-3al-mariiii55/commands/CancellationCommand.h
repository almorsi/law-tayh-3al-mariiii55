#ifndef CANCELLATIONCOMMAND_H
#define CANCELLATIONCOMMAND_H
#include "Command.h"
#include "..\Data-Structures\StationData.h"
class CancellationCommand : public Command
{
public:
	CancellationCommand(MissionInputData);
	virtual ~CancellationCommand();

	virtual void execute(StationData*);
};

#endif // !CANCELLATIONCOMMAND_H

