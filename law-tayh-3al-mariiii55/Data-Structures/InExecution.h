#ifndef IN_EXECUTION
#define IN_EXECUTION
#include "..\Defs.h"

class InExecution :public Keyable
{
public:

	Mission* mission;
	Rover* rover;
	InExecution(Mission* m, Rover* r, int numDaysToFinish)
		:
		mission(m),
		rover(r)
	{
		setKey(numDaysToFinish);
	}
};

#endif // !IN_EXECUTION

