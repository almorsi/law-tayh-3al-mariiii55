#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#include "..\Data-Structures\vector.h"
class InputDevice
{
public:
	InputDevice() {};
	virtual ~InputDevice() {};
	virtual void setInputSource(const char*) = 0;
	virtual bool canParseInputFromSource() const = 0;
	virtual Vector<int>* getParsedInput() = 0;

protected:
	virtual void parseInput() = 0;
};

#endif // !INPUTDEVICE_H

