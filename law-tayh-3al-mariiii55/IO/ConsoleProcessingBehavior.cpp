#include "ConsoleProcessingBehavior.h"

consoleProcessingBehavior::consoleProcessingBehavior(StationData* data):ProcessingBehaviour(data)
{}

Vector<int>* consoleProcessingBehavior::process()
{
	Vector<int>* consolData = new Vector<int>;

	consolData->insertBegin(mainData->currentDay);
	consolData->insertEnd(mainData->mountainMissions.getSize()+ mainData->emergencyMissions.getSize()+ mainData->polarMissions.getLength());
	if ((mainData->mountainMissions.getSize() + mainData->emergencyMissions.getSize() + mainData->polarMissions.getLength()) == 0)
		consolData->insertEnd(0);
	else
	{
	consolData->insertEnd(mainData->emergencyMissions.getSize());
	if ((mainData->emergencyMissions.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
	for (int i = 0; i < mainData->emergencyMissions.getSize(); i++)
	{
		consolData->insertEnd(mainData->emergencyMissions.getAt(i)->getKey());
	}
	}
	
	consolData->insertEnd(mainData->polarMissions.getLength());
	if ((mainData->polarMissions.getLength()) == 0)
		consolData->insertEnd(0);
	else
	{
	for (int i = 0; i < mainData->polarMissions.getLength(); i++)
	{
		consolData->insertEnd(mainData->polarMissions.dequeue()->getKey());
	}
	}

	consolData->insertEnd(mainData->mountainMissions.getSize());
	if ((mainData->mountainMissions.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
	doublyNode<Mission*>* h = mainData->mountainMissions.getHead();
	while (h)
	{
		consolData->insertEnd(h->getData()->getKey());
		h = h->getNext();
	}
	}
	}

	consolData->insertEnd(mainData->inexecutionsPairs.getSize());
	if ((mainData->inexecutionsPairs.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
	for (int i = 0; i < 2*(mainData->inexecutionsPairs.getSize()); i++)
	{
		consolData->insertEnd(mainData->inexecutionsPairs.getAt(i)->mission->getKey());
		consolData->insertEnd(mainData->inexecutionsPairs.getAt(i+1)->rover->getKey());
	}
	}


	consolData->insertEnd(mainData->emergencyRovers.getSize() + mainData->mountainRovers.getSize() + mainData->polarRovers.getSize());
	if ((mainData->emergencyRovers.getSize() + mainData->mountainRovers.getSize() + mainData->polarRovers.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
	consolData->insertEnd(mainData->emergencyRovers.getSize());
	if ((mainData->emergencyRovers.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
	for (int i = 0; i < mainData->emergencyRovers.getSize(); i++)
	{
		consolData->insertEnd(mainData->emergencyRovers.getAt(i)->getKey());
	}
	}

	consolData->insertEnd(mainData->polarRovers.getSize());
	if ((mainData->polarRovers.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
	for (int i = 0; i < mainData->polarRovers.getSize(); i++)
	{
		consolData->insertEnd(mainData->polarRovers.getAt(i)->getKey());
	}
	}

	consolData->insertEnd(mainData->mountainRovers.getSize());
	if ((mainData->mountainRovers.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
	for (int i = 0; i < mainData->mountainRovers.getSize(); i++)
	{
		consolData->insertEnd(mainData->mountainRovers.getAt(i)->getKey());
	}
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
