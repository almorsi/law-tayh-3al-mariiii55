#ifndef PROCESSING_BEHAVIOR
#define PROCESSING_BEHAVIOR

#include "..\Defs.h"
#include "..\Data-Structures\Mission.h"
#include "..\Data-Structures\Rover.h"
#include "..\Data-Structures\InExecution.h"
class ProcessingBehaviour
{
protected:
	StationData* mainData;
public:
	ProcessingBehaviour(StationData* data) { mainData = data; }
	virtual Vector<int>* process() = 0;
	virtual ~ProcessingBehaviour() {}
};

#endif 
