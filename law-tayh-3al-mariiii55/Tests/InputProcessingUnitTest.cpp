#include <cassert>

#include "InputProcessingUnitTest.h"
#include "..\Defs.h"
#include "..\IO\InputProcessingUnit.h"
#include "..\Data-Structures\vector.h"
#include "..\commands\Command.h"
#include "..\Data-Structures\Rover.h"

InputProcessingUnitTest::InputProcessingUnitTest()
{
}

InputProcessingUnitTest::~InputProcessingUnitTest()
{
}

void InputProcessingUnitTest::runAllTests()
{
	sampleInputFile();
}

void InputProcessingUnitTest::sampleInputFile()
{
	Vector<int>* inputData = new Vector<int>();
	inputData->insertEnd(3); inputData->insertEnd(3); inputData->insertEnd(2);
	inputData->insertEnd(1); inputData->insertEnd(2); inputData->insertEnd(2);
	inputData->insertEnd(3); inputData->insertEnd(9); inputData->insertEnd(8); inputData->insertEnd(7);
	inputData->insertEnd(25);
	inputData->insertEnd(8);
	inputData->insertEnd('F'); inputData->insertEnd('M'); inputData->insertEnd(2); inputData->insertEnd(1);
	inputData->insertEnd(100); inputData->insertEnd(4); inputData->insertEnd(5);
	inputData->insertEnd('F'); inputData->insertEnd('M'); inputData->insertEnd(5); inputData->insertEnd(2);
	inputData->insertEnd(250); inputData->insertEnd(4); inputData->insertEnd(4);
	inputData->insertEnd('F'); inputData->insertEnd('E'); inputData->insertEnd(5); inputData->insertEnd(3);
	inputData->insertEnd(500); inputData->insertEnd(6); inputData->insertEnd(3);
	inputData->insertEnd('F'); inputData->insertEnd('P'); inputData->insertEnd(6); inputData->insertEnd(4);
	inputData->insertEnd(900); inputData->insertEnd(7); inputData->insertEnd(4);
	inputData->insertEnd('X'); inputData->insertEnd(10); inputData->insertEnd(1);
	inputData->insertEnd('F'); inputData->insertEnd('M'); inputData->insertEnd(18); inputData->insertEnd(5);
	inputData->insertEnd(560); inputData->insertEnd(5); inputData->insertEnd(9);
	inputData->insertEnd('P'); inputData->insertEnd(19); inputData->insertEnd(2);
	inputData->insertEnd('F'); inputData->insertEnd('P'); inputData->insertEnd(25); inputData->insertEnd(6);
	inputData->insertEnd(190); inputData->insertEnd(3); inputData->insertEnd(1);

	StationData* sd = new StationData();
	IPU::buildStationData(sd, inputData);

	assert(sd->commands.getLength() == 8);
	for (int i = 0; i < 8; i++)
		delete sd->commands.dequeue();

	assert(sd->mountainRovers.getSize() == 3);
	for (int i = 0; i < 3; i++)
		delete sd->mountainRovers.extractMax();

	assert(sd->polarRovers.getSize() == 3);
	for (int i = 0; i < 3; i++)
		delete sd->polarRovers.extractMax();

	assert(sd->emergencyRovers.getSize() == 2);
	for (int i = 0; i < 2; i++)
		delete sd->emergencyRovers.extractMax();

	delete sd;
	delete inputData;
}
