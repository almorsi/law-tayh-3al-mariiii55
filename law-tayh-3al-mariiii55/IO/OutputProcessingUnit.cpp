#include "OutputProcessingUnit.h"

OutputProcessingUnit::OutputProcessingUnit()
	:
	processingBehavior(nullptr)
{
}

OutputProcessingUnit::~OutputProcessingUnit()
{
	setProcessingBehavior(nullptr);
}

void OutputProcessingUnit::notify()
{
	observer->update();
}

void OutputProcessingUnit::add(Observer* obs)
{
	observer = obs;
}

void OutputProcessingUnit::remove()
{
	observer = nullptr;
}

Vector<int>* OutputProcessingUnit::getProcessedData()
{
	return processingBehavior->process();
}

void OutputProcessingUnit::setProcessingBehavior(ProcessingBehaviour* ph)
{
	if (processingBehavior)
		delete processingBehavior;
	processingBehavior = ph;
}
