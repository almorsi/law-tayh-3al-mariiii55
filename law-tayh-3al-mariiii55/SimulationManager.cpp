#include "SimulationManager.h"
#include <cassert>

SimulationManager::SimulationManager()
	:
	stationData(nullptr),
	inputDevice(nullptr),
	outputProcssingUnit(nullptr),
	consoleOutputDevice(nullptr),
	fileOutputDevice(nullptr)
{
	inputDevice = new FileInputDevice();
	stationData = new StationData();
	outputProcssingUnit = new OutputProcessingUnit();

	assert(outputProcssingUnit);
	consoleOutputDevice = new ConsoleOutputDevice(outputProcssingUnit);
	fileOutputDevice = new FileOutputDevice(outputProcssingUnit);
}

SimulationManager::~SimulationManager()
{
	assert(!inputDevice);
	assert(!consoleOutputDevice);
	assert(!fileOutputDevice);

	if (stationData) delete stationData;
	if (outputProcssingUnit) delete outputProcssingUnit;
}

void SimulationManager::buildSimulationDataFromFileWithName(const char* fileName)
{
	assert(stationData);
	assert(inputDevice);

	inputDevice->setInputSource(fileName);
	if (inputDevice->canParseInputFromSource())
		IPU::buildStationData(stationData, inputDevice->getParsedInput());
	else
		assert(false);

	delete inputDevice;
	inputDevice = nullptr;
}

void SimulationManager::runSimulation(ConsoleRunMode crm)
{
	assert(stationData);
	assert(outputProcssingUnit);
	assert(consoleOutputDevice);

	if (crm == INTERACTIVE_CRM)  consoleOutputDevice->setBehaviour(new InteractiveConsoleBehaviour());
	else if (crm == STEP_CRM)	 consoleOutputDevice->setBehaviour(new StepConsoleBehaviour());
	else if (crm == SILENT_CRM)  consoleOutputDevice->setBehaviour(new SilentConsoleBehaviour());
	else assert(false);

	outputProcssingUnit->add(consoleOutputDevice);
	outputProcssingUnit->setProcessingBehavior(new consoleProcessingBehavior(stationData));

	while (!simulationFinished())
	{
		//do logical processing unit
		outputProcssingUnit->notify();
		consoleOutputDevice->print();
	}

	delete consoleOutputDevice;
	consoleOutputDevice = nullptr;

	outputProcssingUnit->remove();
}


void SimulationManager::writeOutputDataToFileWithName()
{
	assert(stationData);
	assert(outputProcssingUnit);
	assert(fileOutputDevice);

	outputProcssingUnit->add(fileOutputDevice);
	outputProcssingUnit->setProcessingBehavior(new fileProcessingBehavior(stationData));

	outputProcssingUnit->notify();
	fileOutputDevice->print();

	delete fileOutputDevice;
	fileOutputDevice = nullptr;

	outputProcssingUnit->remove();
}

bool SimulationManager::simulationFinished() const
{
	return true;// initialy to true until the logical processing unit is implemented
}
