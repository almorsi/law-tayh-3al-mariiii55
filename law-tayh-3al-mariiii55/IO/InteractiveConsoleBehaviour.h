#pragma once
#include "ConsoleBehaviour.h"
#include "..\Data-Structures\vector.h"

class InteractiveConsoleBehaviour : public ConsoleBehaviour
{
public:
	virtual void print(Vector<int>*);
};
