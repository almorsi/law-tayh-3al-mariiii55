#ifndef CONSOLE_PROCESSING_BEHAVIOR
#define CONSOLE_PROCESSING_BEHAVIOR
#include "ProcessingBehavior.h"

class consoleProcessingBehavior :public processingBehaviour
{
public:
	consoleProcessingBehavior(stationData* data);
	Vector<int> process();
};
#endif 
