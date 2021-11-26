#include <cstdlib>
#include "FileInputDevice.h"

FileInputDevice::FileInputDevice()
	:
	fileState(false),
	parsedData(nullptr)
{
}

FileInputDevice::~FileInputDevice()
{
	if (canParseInputFromSource())
		fs.close();
}

void FileInputDevice::setInputSource(const char* fileName)
{
	fs.open(fileName, std::ios_base::in);
	if (fs.is_open())
		fileState = true;
}

bool FileInputDevice::canParseInputFromSource() const
{
	return fileState;
}

Vector<int>* FileInputDevice::getParsedInput()
{
	parseInput();
	return parsedData;
}

void FileInputDevice::parseInput()
{
	char c = '0';

	parsedData = new Vector<int>();
	
	int sum = 0;
	bool numFlag = false;
	while (c != EOF)
	{
		c = fs.get();
		while (isdigit(c))
		{
			sum = sum * 10 + (c - '0');
			numFlag = true;
			c = fs.get();
		}
		if (numFlag)
		{
			parsedData->insertEnd(sum);
			numFlag = false;
			sum = 0;
		}
		if (isalpha(c))
			parsedData->insertEnd(c);
	}
}
