#include <iostream>

#include "SilentConsoleBehaviour.h"

using namespace std;

void SilentConsoleBehaviour::print(Vector<int>*)
{
	using namespace std;

	if(n++ == 0)
		cout << "Silent Mode\n Simulation Starts...\n ";
}

