#include <iostream>

#include "InteractiveConsoleBehaviour.h"

using namespace std;

void InteractiveConsoleBehaviour::print(Vector<int>* data)
{

	if (!data) return;

	long index = 0;

	cout << "Current Day: " << data->getAt(index++) << endl; // INDEX = 0

	cout << data->getAt(index) << " Waiting Missions";//1

	if (data->getAt(index++) > 0) //1
	{
		cout << ": ";
		if (data->getAt(index) > 0)//2
		{
			long counter = data->getAt(index++);//2, ASSUMING COUNTER = 3

			cout << "[" << data->getAt(index++); //3

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++); //4,5

			cout << "] ";
		}

		//6
		//POLAR MISSION

		if (data->getAt(index) > 0)//6
		{
			long counter = data->getAt(index++);//6, ASSUMING COUNTER = 3

			cout << "(" << data->getAt(index++); //7

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++); //8,9

			cout << ") ";
		}

		//10
		//MOUNTAIN MISSIONS

		if (data->getAt(index) > 0)//10
		{
			long counter = data->getAt(index++);//10, ASSUMING COUNTER = 3

			cout << "{" << data->getAt(index++); //11

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++); //12,13

			cout << "} ";
		}

		//14
	}
	else //2
		index += 3;//5, SKIP WAITING MISSIONS

	cout << endl << endl << data->getAt(index) << " In-Execution Missions/Rovers"; //14

	if (data->getAt(index++) > 0) //14
	{
		cout << ": ";
		if (data->getAt(index) > 0)//15
		{
			long counter = data->getAt(index++);// 15, ASSUMING COUNTER = 3

			cout << "[" << data->getAt(index++) << "/" << data->getAt(index++); //16/17

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++) << "/" << data->getAt(index++);  //18/19,20/21

			cout << "] ";
		}
		//22

		if (data->getAt(index) > 0)//22
		{
			long counter = data->getAt(index++);// 22, ASSUMING COUNTER = 3

			cout << "(" << data->getAt(index++) << "/" << data->getAt(index++); //23/24

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++) << "/" << data->getAt(index++);  //25/26,27/28

			cout << ") ";
		}
		//29

		if (data->getAt(index) > 0)//29
		{
			long counter = data->getAt(index++);// 29, ASSUMING COUNTER = 3

			cout << "{" << data->getAt(index++) << "/" << data->getAt(index++); //30/31

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++) << "/" << data->getAt(index++);  //32/33,34/35

			cout << "} ";
		}
		//36
	}
	else
		index += 3;

	// AVAILABLE ROVERS

	cout << endl << endl << data->getAt(index) << " Available Rovers";

	if (data->getAt(index++) > 0) 
	{
		cout << ": ";
		if (data->getAt(index) > 0)
		{
			long counter = data->getAt(index++);

			cout << "[" << data->getAt(index++); 

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++); 
			

			cout << "] ";
		}

		//POLAR Rovers

		if (data->getAt(index) > 0)//6
		{
			long counter = data->getAt(index++);

			cout << "(" << data->getAt(index++);

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++);

			cout << ") ";
		}


		//MOUNTAIN MISSIONS

		if (data->getAt(index) > 0)
		{
			long counter = data->getAt(index++);

			cout << "{" << data->getAt(index++);

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++);

			cout << "} ";
		}

		//14
	}
	else //2
		index += 3;

	//IN-CHECKUP ROVERS

	cout << endl << endl << data->getAt(index) << " In-Checkup Rovers";

	if (data->getAt(index++) > 0) //1
	{
		cout << ": ";
		if (data->getAt(index) > 0)//2
		{
			long counter = data->getAt(index++);

			cout << "[" << data->getAt(index++);

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++);

			cout << "] ";
		}

		//POLAR ROVERS

		if (data->getAt(index) > 0)
		{
			long counter = data->getAt(index++);

			cout << "(" << data->getAt(index++);

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++);

			cout << ") ";
		}

		//MOUNTAIN ROVERS

		if (data->getAt(index) > 0)//10
		{
			long counter = data->getAt(index++);

			cout << "{" << data->getAt(index++); 

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++);

			cout << "} ";
		}

		
	}
	else
		index += 3;

	//COMPLETED MISSIONS

	cout << endl << endl << data->getAt(index) << " Waiting Missions";

	if (data->getAt(index++) > 0)
	{
		cout << ": ";
		if (data->getAt(index) > 0)
		{
			long counter = data->getAt(index++);

			cout << "[" << data->getAt(index++); 

			for (int i = 0; i < counter - 1; i++)
			{
				cout << ", " << data->getAt(index++);
			}

			cout << "] ";
		}

		//POLAR MISSION

		if (data->getAt(index) > 0)//6
		{
			long counter = data->getAt(index++);

			cout << "(" << data->getAt(index++); 

			for (int i = 0; i < counter - 1; i++)
			{
				cout << ", " << data->getAt(index++);
			}

			cout << ") ";
		}

		//MOUNTAIN MISSIONS

		if (data->getAt(index) > 0)
		{
			long counter = data->getAt(index++);

			cout << "{" << data->getAt(index++);

			for (int i = 0; i < counter - 1; i++)
				cout << ", " << data->getAt(index++);

			cout << "} ";
		}
	}


}

