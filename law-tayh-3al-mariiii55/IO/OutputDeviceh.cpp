#include "OutputDeviceh.h"

OutputDevice::OutputDevice(OutputProcessingUnit* opu)
	:
	opu(opu),
	processedData(nullptr)
{
}

OutputDevice::~OutputDevice()
{
}
