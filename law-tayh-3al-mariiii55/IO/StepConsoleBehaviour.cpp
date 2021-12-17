#include "StepConsoleBehaviour.h"

#include "InteractiveConsoleBehaviour.h"

void StepConsoleBehaviour::print(Vector<int>* data)
{
	InteractiveConsoleBehaviour* it = new InteractiveConsoleBehaviour();
	it->print(data);
	//sleep(1);
}

