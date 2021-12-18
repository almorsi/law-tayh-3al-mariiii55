#include "PromotionCommand.h"

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
	//reomve the mission with id mcd.id from mountain mission data structure and add it to emergency mission's data structure
}
