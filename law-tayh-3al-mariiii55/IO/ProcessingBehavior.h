#ifndef PROCESSING_BEHAVIOR
#define PROCESSING_BEHAVIOR

#include "..\Defs.h"
#include "..\Data-Structures\Mission.h"
#include "..\Data-Structures\Rover.h"

class processingBehaviour
{
protected:
	StationData* mainData;
public:
	processingBehaviour(StationData* data) { mainData = data; }
	virtual Vector<int>* process() = 0;
	virtual ~processingBehaviour() {}
};

#endif 
