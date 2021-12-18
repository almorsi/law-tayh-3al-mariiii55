#include "CancellationCommand.h"

CancellationCommand::CancellationCommand(MissionInputData mcd)
	:
	Command(mcd)
{
}

CancellationCommand::~CancellationCommand()
{
}

void CancellationCommand::execute(StationData* sd)
{
	//reomve the mission with id mcd.id from mountain mission data structure
}
