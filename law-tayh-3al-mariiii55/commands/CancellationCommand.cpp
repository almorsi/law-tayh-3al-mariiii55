#include <cassert>

#include "CancellationCommand.h"
#include "..\Data-Structures\StationData.h"
#include "..\Data-Structures\Mission.h"
#include "..\Data-Structures\DoublyLinkedList.h"

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
	assert(md.eventDay == sd->currentDay);
	doublyNode<Mission*>* current = sd->mountainMissions.getHead();
	while (current)
	{
		if (current->getData()->mid.missionId == md.missionId)
		{
			 sd->mountainMissions.removeItem(current);
			break;
		}
		current = current->getNext();
	}
}
