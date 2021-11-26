#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H
class InputDevice
{
public:
	InputDevice() {};
	virtual ~InputDevice() {};
	virtual void setInputSource() = 0;
	virtual bool canParseInputFromSource() = 0;
	virtual void parseInput() = 0;
	virtual void getParsedInput() = 0;
};

#endif // !INPUTDEVICE_H

