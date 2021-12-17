#pragma once
#include "ConsoleBehaviour.h"
#include "..\Data-Structures\vector.h"

class StepConsoleBehaviour : public ConsoleBehaviour
{
public:
	virtual void print(Vector<int>*);
};

