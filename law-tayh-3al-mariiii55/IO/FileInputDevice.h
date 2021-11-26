#ifndef FILEINPUTDEVICE_H
#define FILEINPUTDEVICE_H

#include <fstream>

#include "InputDevice.h"
#include "..\Data-Structures\vector.h"

class FileInputDevice : public InputDevice
{
public:
	FileInputDevice();
	~FileInputDevice();

	virtual void setInputSource(const char*);
	virtual bool canParseInputFromSource() const;
	virtual  Vector<int>* getParsedInput();

protected:
	virtual void parseInput();

private:
	Vector<int>* parsedData;
	std::fstream fs;
	bool fileState;
};
#endif // !FILEINPUTDEVICE_H

