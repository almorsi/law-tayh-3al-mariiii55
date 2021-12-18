#include "ConsoleProcessingBehavior.h"

consoleProcessingBehavior::consoleProcessingBehavior(stationData* data):processingBehaviour(data)
{}

Vector<int>* consoleProcessingBehavior::process()
{
	Vector<int>* consolData = new Vector<int>;

	consolData->insertBegin(mainData->currentDay);
	consolData->insertEnd(mainData->mountainMissions.getSize()+ mainData->emergencyMissions.getSize()+ mainData->polarMissions.getLength());
	
	consolData->insertEnd(mainData->emergencyMissions.getSize());
	for (int i = 0; i < mainData->emergencyMissions.getSize(); i++)
	{
		//le7ad lma ammar yerod
	}
	
	consolData->insertEnd(mainData->polarMissions.getLength());
	for (int i = 0; i < mainData->polarMissions.getLength(); i++)
	{
		consolData->insertEnd(mainData->polarMissions.dequeue()->getKey());
	}
	
	consolData->insertEnd(mainData->mountainMissions.getSize());
	doublyNode<Mission*>* h = mainData->mountainMissions.getHead();
	while (h)
	{
		consolData->insertEnd(h->getData()->getKey());
		h = h->getNext();
	}
	
	consolData->insertEnd(0); //IN-Exe waiting for clarification 
	for (int i = 0; i < mainData->inexecutionsPairs.getSize(); i++)
	{
		//waiting for clarification
	}
	consolData->insertEnd(mainData->emergencyRovers.getSize() + mainData->mountainRovers.getSize() + mainData->polarRovers.getSize());
	
	consolData->insertEnd(mainData->emergencyRovers.getSize());
	for (int i = 0; i < mainData->emergencyRovers.getSize(); i++)
	{
		//waiting for ammar
	}

	consolData->insertEnd(mainData->polarRovers.getSize());
	for (int i = 0; i < mainData->polarRovers.getSize(); i++)
	{
		//waiting for ammar
	}

	consolData->insertEnd(mainData->mountainRovers.getSize());
	for (int i = 0; i < mainData->mountainRovers.getSize(); i++)
	{
		//waiting for ammar
	}
	
	//waiting to understand how is data organized 
	//checkUp Rovers
	
	consolData->insertEnd(mainData->completedMissions.getSize());
	Node* a = mainData->completedMissions.getHead();
	while (a)
	{
		consolData->insertEnd(a->getData()->getKey());
		a = a->getNext();
	}
	return consolData;
}
