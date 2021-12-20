#ifndef OUTPUTDEVICE_H
#define OUTPUTDEVICE_H

#include "Observer.h"
#include "OutputProcessingUnit.h"
#include "..\Data-Structures\vector.h"

class OutputDevice : public Observer
{
public:
	OutputDevice(OutputProcessingUnit* opu);
	virtual ~OutputDevice();

	virtual void update() = 0;
	virtual void print() = 0;

protected:
	Vector<int>* processedData;
	OutputProcessingUnit* opu;
};
#endif // !OUTPUTDEVICE_H

