#include "Step.h"
#include "Interactive.h"
void StepConsoleBehaviour::print(Vector<int>* data)
{
	InteractiveConsoleBehaviour* it = new InteractiveConsoleBehaviour();
	it->print(data);
	//sleep(1);
}
