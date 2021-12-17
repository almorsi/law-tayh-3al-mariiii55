#pragma once
#include "OutputDeviceh.h"
#include "ConsoleBehaviour.h"
class ConsoleOutputDevice : public OutputDevice
{
public:
	ConsoleOutputDevice(OutputProcessingUnit*);
	~ConsoleOutputDevice();

	virtual void update();
	virtual void print();
	void setBehaviour(ConsoleBehaviour*);
protected:
	ConsoleBehaviour* behaviour;
};
