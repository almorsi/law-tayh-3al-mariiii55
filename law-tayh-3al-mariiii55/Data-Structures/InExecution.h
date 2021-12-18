#ifndef IN_EXECUTION
#define IN_EXECUTION
#include "..\Defs.h"

class InExecution :public Keyable
{
	//key in keyable class is days to finish
	Mission* mission;
	Rover* rover;
	InExecution(){}
};

#endif // !IN_EXECUTION

