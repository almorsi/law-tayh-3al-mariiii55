#ifndef SIMULATION_MANAGER_H
#define SIMULATION_MANAGER_H

#include "Defs.h"
#include "IO\FileInputDevice.h"
#include "IO\InputProcessingUnit.h"
#include "IO\OutputProcessingUnit.h"
#include "IO\ConsoleProcessingBehavior.h"
#include "IO\FileProcessingBehavior.h"
#include "IO\ConsoleOutputDevice.h"
#include "IO\FileOutputDevice.h"
#include "IO\InteractiveConsoleBehaviour.h"
#include "IO\SilentConsoleBehaviour.h"
#include "IO\StepConsoleBehaviour.h"
#include "Logic-Unit\LogicalProcessingUnit.h"

class SimulationManager
{
public:
	SimulationManager();
	~SimulationManager();

	void buildSimulationDataFromFileWithName(const char*);
	void runSimulation(ConsoleRunMode);
	void writeOutputDataToFileWithName();//need to pass a name to this function

private:
	bool simulationFinished() const;

private:
	StationData* stationData;
	InputDevice* inputDevice;
	LogicaProcessingUnit* logicalProcssingUnit;
	OutputProcessingUnit* outputProcssingUnit;
	ConsoleOutputDevice* consoleOutputDevice;
	FileOutputDevice* fileOutputDevice;
};

#endif // !SIMULATION_MANAGER_H
