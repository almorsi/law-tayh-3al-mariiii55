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
	int sum;
	char c;

	parsedData = new Vector<int>();
	
	do
	{
		sum = 0;
		c = fs.get();

		if (isdigit(c))
		{
			do{sum = sum * 10 + (c - '0');} 
			while ((c = fs.get()) != EOF && isdigit(c));
			parsedData->insertEnd(sum);
		}
		if (isalpha(c))
			parsedData->insertEnd(c);

	} while (c != EOF);
}
