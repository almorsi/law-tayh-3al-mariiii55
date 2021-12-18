#include"FileOutputDevice.h"

using namespace std;

FileOutputDevice::FileOutputDevice(OutputProcessingUnit* opu)
	: OutputDevice(opu)
{
}

FileOutputDevice::~FileOutputDevice() {}

void FileOutputDevice::update()
{
	processedData = opu->getProcessedData();
}

void FileOutputDevice::print()
{
	if (processedData->getFirst() == 0)
		return;

	ofstream outPut;
	outPut.open("OutputFiles/Output" + fileName + ".txt");

	outPut << "CD\tID\tFD\tWD\tED\n";
	for (int i = 0; i < processedData->getFirst(); i += 5)
	{
		outPut << processedData->getAt(i + 1) << '\t' << processedData->getAt(i + 2) << '\t'
			<< processedData->getAt(i + 3) << '\t' << processedData->getAt(i + 4) << '\t'
			<< processedData->getAt(i + 5) << endl;
	}

	int i = processedData->getFirst() + 1;
	outPut << "Missions: " << processedData->getFirst() << "[M:" << processedData->getAt(i)
		<< ", P:" << processedData->getAt(i + 1) << ", E:" << processedData->getAt(i + 2) << "]\n";
	outPut << "Rovers: " << processedData->getAt(i + 3) << "[M:" << processedData->getAt(i + 4)
		<< ", P:" << processedData->getAt(i + 5) << ", E:" << processedData->getAt(i + 6) << "]\n";
	outPut << "Avg Wait = " << processedData->getAt(i + 7) << "." << processedData->getAt(i + 8)
		<< ", Avg Exec = " << processedData->getAt(i + 9) << "." << processedData->getAt(i + 10) << endl;
	outPut << "Auto-promoted: " << processedData->getAt(i + 11) << "%" << endl;

	outPut.close();

	cout << "Simulation ends, Output file created\n";
}
