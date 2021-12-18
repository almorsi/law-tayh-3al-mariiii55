#ifndef PROMOTIONCOMMAND_H
#define PROMOTIONCOMMAND_H
#include "Command.h"

class PromotionCommand : public Command
{
public:
	PromotionCommand(MissionInputData);
	virtual ~PromotionCommand();

	virtual void execute(StationData* sd);

};
#endif // !PROMOTIONCOMMAND_H

