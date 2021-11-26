#ifndef PROMOTIONCOMMAND_H
#define PROMOTIONCOMMAND_H
#include "Command.h"

class PromotionCommand : public Command
{
public:
	PromotionCommand(/*StationData*, MissionData*/);
	virtual ~PromotionCommand();

	virtual void execute();

};
#endif // !PROMOTIONCOMMAND_H

