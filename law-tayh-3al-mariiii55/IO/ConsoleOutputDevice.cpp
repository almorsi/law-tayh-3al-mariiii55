#include "ConsoleOutputDevice.h"

ConsoleOutputDevice::ConsoleOutputDevice(OutputProcessingUnit* opu)
	:
	OutputDevice(opu),
	behaviour(nullptr)
{
}

ConsoleOutputDevice::~ConsoleOutputDevice()
{
	setBehaviour(nullptr);
}


void ConsoleOutputDevice::update()
{
	processedData = opu->getProcessedData();
}

void ConsoleOutputDevice::print()
{
	behaviour->print(processedData);
}

void ConsoleOutputDevice::setBehaviour(ConsoleBehaviour* beh)
{
	if (behaviour)
		delete behaviour;
	behaviour = beh;
}
