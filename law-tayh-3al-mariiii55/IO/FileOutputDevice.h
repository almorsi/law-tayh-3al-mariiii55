#pragma once
#include<iostream>
#include<fstream>

#include"OutputDeviceh.h"

class FileOutputDevice : public OutputDevice
{
	std::string fileName = "results";
public:
	FileOutputDevice(OutputProcessingUnit*);
	~FileOutputDevice();

	virtual void update();
	virtual void print();

};