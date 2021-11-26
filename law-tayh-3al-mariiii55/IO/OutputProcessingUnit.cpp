#include "OutputProcessingUnit.h"

OutputProcessingUnit::OutputProcessingUnit()
	:
	processedData(nullptr)
{
}

OutputProcessingUnit::~OutputProcessingUnit()
{
	clearProcessedData();
}

void OutputProcessingUnit::notify()
{
	observer->update();
}

void OutputProcessingUnit::add(Observer* obs)
{
	observer = obs;
}

void OutputProcessingUnit::remove(Observer* obs)
{
	obs = nullptr;
}

Vector<int>* OutputProcessingUnit::getProcessedData()
{
	/*
	* this function should call its behavior either file or consle
	* after mohammed implements those behaviors then we can add
	* the behavior as its attribute by function setProcessingBehavior()
	* then we just
	* return processingBehavior->process(stationData*);
	*/
	return nullptr;
}

void OutputProcessingUnit::clearProcessedData()
{
	if (processedData)
	{
		delete processedData;
		processedData = nullptr;
	}
}
