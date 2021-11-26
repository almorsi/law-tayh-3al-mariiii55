#include "FormulationCommand.h"

FormulationCommand::FormulationCommand(/*StationData* sd,*/ MissionFormulationData mfd)
	:
	/*Command(sd),*/
	mfd(mfd)
{
}

FormulationCommand::~FormulationCommand()
{
}

void FormulationCommand::execute()
{
	/*shoud formulate and add a mission to its apropriate data structure in StationData*/
	switch (mfd.missionType)
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
