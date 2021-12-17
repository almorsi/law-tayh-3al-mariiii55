#pragma once
#include "ConsoleBehaviour.h"
#include "..\Data-Structures\vector.h"

class SilentConsoleBehaviour : public ConsoleBehaviour
{
public:
	virtual void print(Vector<int>*);
};
