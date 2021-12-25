#include "PromotionCommand.h"
#include "..\Data-Structures\StationData.h"
PromotionCommand::PromotionCommand(MissionInputData mpd)
:
Command(mpd)
{
}

PromotionCommand::~PromotionCommand()
{
}

void PromotionCommand::execute(StationData* sd)
{
	doublyNode<Mission*>* current = sd->mountainMissions.getHead();
	while (current)
	{
		if (current->getData()->mid.missionId == md.missionId)
		{
			sd->emergencyMissions.insert(current->getData());
			sd->mountainMissions.removeItem(current);
		}
	}
}
