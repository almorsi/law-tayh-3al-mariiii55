#pragma once
#include "OutputProcessingUnit.h"
#include "..\Data-Structures\vector.h"

class ConsoleBehaviour
{
public:
	virtual void print(Vector<int>*) = 0;
};
