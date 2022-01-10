#include "IO/TestGenerator.h"
#include "SimulationManager.h"

int main(void)
{

	/******************************************************************
	 * will generate an input file in the format reqiured, 
	 * we can use this generated file to be the input of our simulation
	 */
	
	TestGenerator tg("test.txt");
	if (tg.canGenerateTestCase())
		tg.generateTestCase();
	
	

	/*****************************************************************/
	
	SimulationManager* simulaitonManager = new SimulationManager();
	simulaitonManager->buildSimulationDataFromFileWithName("test.txt");

	int x = 0;
	cout << "Please choose simulation mode:" << endl << "1-Silent mode" << endl << "2-Step mode" << endl << "3-Interactive mode" << endl;
	cin >> x;
	cout << endl;
	while (x != 1 && x != 2 && x != 3)
	{
			cout << "Wrong input please enter correct input: ";
			cin >> x;
			cout << endl;
	} 
	if (x == 1)
		simulaitonManager->runSimulation(SILENT_CRM);
	else if (x == 2)
		simulaitonManager->runSimulation(STEP_CRM);
	else if (x == 3)
		simulaitonManager->runSimulation(INTERACTIVE_CRM);

	simulaitonManager->writeOutputDataToFileWithName();
	delete simulaitonManager;

	return 0;
}
