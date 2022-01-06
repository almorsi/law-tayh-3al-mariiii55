#pragma once
#include "ConsoleBehaviour.h"
#include "..\Data-Structures\vector.h"

class SilentConsoleBehaviour : public ConsoleBehaviour
{
	int n = 0;
public:
	virtual void print(Vector<int>*);
};
