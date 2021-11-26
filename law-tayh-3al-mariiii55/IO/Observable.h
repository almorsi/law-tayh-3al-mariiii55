#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "Observer.h"
class Observable
{
public:
	Observable()
	{
		observer = nullptr;
	}

	virtual ~Observable()
	{
	}

	virtual void notify() = 0;
	virtual void add(Observer*) = 0;
	virtual void remove(Observer*) = 0;

protected:
	Observer* observer;
};

#endif // !OBSERVABLE_H
