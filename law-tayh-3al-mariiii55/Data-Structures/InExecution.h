#ifndef IN_EXECUTION
#define IN_EXECUTION
#include "..\Defs.h"

class InExecution :public Keyable
{
public:
	//key in keyable class is days to finish
	Mission* mission;
	Rover* rover;
	InExecution():mission(NULL),rover(NULL)
	{}
};

#endif // !IN_EXECUTION

