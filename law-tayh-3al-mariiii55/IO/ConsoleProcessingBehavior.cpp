#include "ConsoleProcessingBehavior.h"

consoleProcessingBehavior::consoleProcessingBehavior(StationData* data) :ProcessingBehaviour(data)
{}

Vector<int>* consoleProcessingBehavior::process()
{
	Vector<int>* consolData = new Vector<int>;

	consolData->insertBegin(mainData->currentDay);

	int numOfWaitingMissions = mainData->mountainMissions.getSize() + mainData->emergencyMissions.getSize() + mainData->polarMissions.getLength();

	consolData->insertEnd(numOfWaitingMissions);


	if ((mainData->emergencyMissions.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
		consolData->insertEnd(mainData->emergencyMissions.getSize());
		for (int i = 0; i < mainData->emergencyMissions.getSize(); i++)
			consolData->insertEnd(mainData->emergencyMissions.getAt(i)->mid.missionId);
	}

	if ((mainData->polarMissions.getLength()) == 0)
		consolData->insertEnd(0);
	else
	{
		consolData->insertEnd(mainData->polarMissions.getLength());
		for (int i = 0; i < mainData->polarMissions.getLength(); i++)
			consolData->insertEnd(mainData->polarMissions.getFront()->mid.missionId);
	}

	if ((mainData->mountainMissions.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
		consolData->insertEnd(mainData->mountainMissions.getSize());
		doublyNode<Mission*>* h = mainData->mountainMissions.getHead();
		while (h)
		{
			consolData->insertEnd(h->getData()->mid.missionId);
			h = h->getNext();
		}
	}

	//need refactoring
	consolData->insertEnd(mainData->inexecutionsPairs.getSize());
	if ((mainData->inexecutionsPairs.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
		for (int i = 0; i < mainData->inexecutionsPairs.getSize(); i++)
		{
			consolData->insertEnd(mainData->inexecutionsPairs.getAt(i)->mission->mid.missionId);
			consolData->insertEnd(mainData->inexecutionsPairs.getAt(i)->rover->roverId);
		}
	}
	///////////////////////////////


	int numOfAvaliableRovers = mainData->emergencyRovers.getSize() + mainData->mountainRovers.getSize() + mainData->polarRovers.getSize();
	consolData->insertEnd(numOfAvaliableRovers);
	if ((mainData->emergencyRovers.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
		consolData->insertEnd(mainData->emergencyRovers.getSize());
		for (int i = 0; i < mainData->emergencyRovers.getSize(); i++)
		{
			consolData->insertEnd(mainData->emergencyRovers.getAt(i)->roverId);
		}
	}

	if ((mainData->polarRovers.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
		consolData->insertEnd(mainData->polarRovers.getSize());
		for (int i = 0; i < mainData->polarRovers.getSize(); i++)
		{
			consolData->insertEnd(mainData->polarRovers.getAt(i)->roverId);
		}
	}

	if ((mainData->mountainRovers.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
		consolData->insertEnd(mainData->mountainRovers.getSize());
		for (int i = 0; i < mainData->mountainRovers.getSize(); i++)
		{
			consolData->insertEnd(mainData->mountainRovers.getAt(i)->roverId);
		}
	}


	consolData->insertEnd(mainData->inCheckUp_ERovers.getSize() + mainData->inCheckUp_MRovers.getSize() + mainData->inCheckUp_PRovers.getSize());
	if ((mainData->inCheckUp_ERovers.getSize() + mainData->inCheckUp_MRovers.getSize() + mainData->inCheckUp_PRovers.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
		consolData->insertEnd(mainData->inCheckUp_ERovers.getSize());
		if ((mainData->inCheckUp_ERovers.getSize()) == 0)
			consolData->insertEnd(0);
		else
		{
			for (int i = 0; i < mainData->inCheckUp_ERovers.getSize(); i++)
			{
				consolData->insertEnd(mainData->inCheckUp_ERovers.getAt(i)->getKey());
			}
		}

		consolData->insertEnd(mainData->inCheckUp_PRovers.getSize());
		if ((mainData->inCheckUp_PRovers.getSize()) == 0)
			consolData->insertEnd(0);
		else
		{
			for (int i = 0; i < mainData->inCheckUp_PRovers.getSize(); i++)
			{
				consolData->insertEnd(mainData->inCheckUp_PRovers.getAt(i)->getKey());
			}
		}

		consolData->insertEnd(mainData->inCheckUp_MRovers.getSize());
		if ((mainData->inCheckUp_MRovers.getSize()) == 0)
			consolData->insertEnd(0);
		else
		{
			for (int i = 0; i < mainData->inCheckUp_MRovers.getSize(); i++)
			{
				consolData->insertEnd(mainData->inCheckUp_MRovers.getAt(i)->getKey());
			}
		}
	}

	consolData->insertEnd(mainData->completedMissions.getSize());
	if ((mainData->completedMissions.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
		Node<Mission*>* a = mainData->completedMissions.getHead();
		while (a)
		{
			consolData->insertEnd(a->getData()->getKey());
			a = a->getNext();
		}
	}
	return consolData;
}
