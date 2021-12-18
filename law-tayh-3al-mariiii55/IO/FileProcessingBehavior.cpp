#include "FileProcessingBehavior.h"

fileProcessingBehavior::fileProcessingBehavior(StationData* data) :processingBehaviour(data)
{}

Vector<int>* fileProcessingBehavior::process()
{
	Vector<int>* fileData = new Vector<int>;
	fileData->insertEnd(mainData->completedMissions.getSize());
	return fileData;
}