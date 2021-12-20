#ifndef CONSOLE_PROCESSING_BEHAVIOR
#define CONSOLE_PROCESSING_BEHAVIOR
#include "ProcessingBehavior.h"

class consoleProcessingBehavior :public ProcessingBehaviour
{
public:
	consoleProcessingBehavior(StationData* data);
	Vector<int>* process();
};
#endif 
