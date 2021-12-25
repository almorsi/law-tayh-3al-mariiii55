#include <cassert>
#include "FormulationCommand.h"
#include "..\Data-Structures\Mission.h"
#include "..\Data-Structures\StationData.h"

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
	Mission* formulatedMission;

	assert(sd->currentDay == md.eventDay);
	
	formulatedMission = new Mission(md, -1, sd->currentDay, -1, -1, -1);
	switch (md.missionType)
	{
	case EMERGENCY_MISSION_MT:
		sd->emergencyMissions.insert(formulatedMission);
		break;
	case POLAR_MISSION_MT:
		sd->polarMissions.enqueue(formulatedMission);
		break;
	case MOUNTAIN_MISSION_MT:
		sd->mountainMissions.insertEnd(formulatedMission);
		break;
	default:
		assert(false);
		break;
	}

	return;
}
