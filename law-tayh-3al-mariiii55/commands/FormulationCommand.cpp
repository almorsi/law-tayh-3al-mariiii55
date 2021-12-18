#include "FormulationCommand.h"

FormulationCommand::FormulationCommand(MissionInputData mfd)
	:
	Command(mfd)
{
}

FormulationCommand::~FormulationCommand()
{
}

void FormulationCommand::execute(StationData* sd)
{
	/*should formulate and add a mission to its apropriate data structure in StationData*/
	/*don't forget to set the key*/
	switch (md.missionType)
	{
	case EMERGENCY_MISSION_MT:
		break;
	case POLAR_MISSION_MT:
		break;
	case MOUNTAIN_MISSION_MT:
		break;
	default:
		break;
	}
	
}
