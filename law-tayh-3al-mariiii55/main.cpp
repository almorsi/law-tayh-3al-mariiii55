#include "Tests/VectorTest.h"
#include "Tests/HeapNodeTest.h"
#include "Tests/MaxHeapTest.h"
#include "IO/TestGenerator.h"
#include "Tests/InputProcessingUnitTest.h"
#include "SimulationManager.h"

int main(void)
{
	VectorTest vt;
	vt.runAllTests();

	HeapNodeTest hnt;
	hnt.runAllTests();

	MaxHeapTest mht;
	mht.runAllTests();

	InputProcessingUnitTest iput;
	iput.runAllTests();


	/******************************************************************
	 * will generate an input file in the format reqiured, 
	 * we can use this generated file to be the input of our simulation
	 */
	/*
	TestGenerator tg("test.txt");
	if (tg.canGenerateTestCase())
		tg.generateTestCase();
	
	*/

	/*****************************************************************/
	
	SimulationManager* simulaitonManager = new SimulationManager();
	simulaitonManager->buildSimulationDataFromFileWithName("test.txt");

	int x = 0;
	cout << "Please choose simulation mode:" << endl << "1-Silent mode" << endl << "2-Step mode" << endl << "3-Interactive mode" << endl;
	cin >> x;
	cout << endl;
	do
	{
		if (x == 1)
			simulaitonManager->runSimulation(SILENT_CRM);
		else if (x == 2)
			simulaitonManager->runSimulation(STEP_CRM);
		else if (x == 3)
			simulaitonManager->runSimulation(INTERACTIVE_CRM);
		else
		{
			cout << "Wrong input please enter correct input: ";
			cin >> x;
			cout << endl;
		}
	} while (x != 1 && x != 2 && x != 3);

	simulaitonManager->writeOutputDataToFileWithName();
	delete simulaitonManager;

	return 0;
}