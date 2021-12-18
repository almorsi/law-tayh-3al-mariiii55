#ifndef FILE_PROCESSING_BEHAVIOR
#define FILE_PROCESSING_BEHAVIOR
#include "ProcessingBehavior.h"

class fileProcessingBehavior :public processingBehaviour
{
public:
	fileProcessingBehavior(StationData* data);
	Vector<int>* process();
};

#endif // !FILE_PROCESSING_BEHAVIOR

