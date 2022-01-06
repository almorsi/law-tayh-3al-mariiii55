#include <cassert>
#include "ConsoleProcessingBehavior.h"

consoleProcessingBehavior::consoleProcessingBehavior(StationData* data) :ProcessingBehaviour(data)
{}

Vector<int>* consoleProcessingBehavior::process()
{
	Vector<int>* consolData = new Vector<int>;

	consolData->insertBegin(mainData->currentDay);

	int numOfWaitingMissions = mainData->mountainMissions.getSize() + 
								mainData->emergencyMissions.getSize() + 
									mainData->polarMissions.getLength();

	consolData->insertEnd(numOfWaitingMissions);


	if ((mainData->emergencyMissions.getSize()) == 0)
		consolData->insertEnd(0);
	else
	{
		consolData->insertEnd(mainData->emergencyMissions.getSize());
		for (int i = 0; i < mainData->emergencyMissions.getSize(); i++)					
			consolData->insertEnd(mainData->emergencyMissions.getAt(i)->mid.missionId);
	}

	Mission* poMission;

	if ((mainData->polarMissions.getLength()) == 0)
		consolData->insertEnd(0);
	else
	{
		consolData->insertEnd(mainData->polarMissions.getLength());
		for (int i = 0; i < mainData->polarMissions.getLength(); i++)
		{
			poMission= mainData->polarMissions.dequeue();
			consolData->insertEnd(poMission->mid.missionId);
			mainData->polarMissions.enqueue(poMission);
		}
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


	consolData->insertEnd(mainData->inexecutionsPairs.getSize());

	int emergenacyCounter = 0;
	int polarcounter = 0;
	int mountainCounter = 0;

	for (int i = 0; i < mainData->inexecutionsPairs.getSize(); i++)
	{
		if (mainData->inexecutionsPairs.getAt(i)->mission->mid.missionType == EMERGENCY_MISSION_MT)
			emergenacyCounter++;
	}
	consolData->insertEnd(emergenacyCounter);
	for (int i = 0; i < mainData->inexecutionsPairs.getSize(); i++)
	{
		if (mainData->inexecutionsPairs.getAt(i)->mission->mid.missionType == EMERGENCY_MISSION_MT)
		{
			consolData->insertEnd(mainData->inexecutionsPairs.getAt(i)->mission->mid.missionId);
			consolData->insertEnd(mainData->inexecutionsPairs.getAt(i)->rover->roverId);
		}
	}

	for (int i = 0; i < mainData->inexecutionsPairs.getSize(); i++)
	{
		if (mainData->inexecutionsPairs.getAt(i)->mission->mid.missionType == POLAR_MISSION_MT)
			polarcounter++;
	}
	consolData->insertEnd(polarcounter);
	for (int i = 0; i < mainData->inexecutionsPairs.getSize(); i++)
	{
		if (mainData->inexecutionsPairs.getAt(i)->mission->mid.missionType == POLAR_MISSION_MT)
		{
			consolData->insertEnd(mainData->inexecutionsPairs.getAt(i)->mission->mid.missionId);
			consolData->insertEnd(mainData->inexecutionsPairs.getAt(i)->rover->roverId);
		}
	}

	for (int i = 0; i < mainData->inexecutionsPairs.getSize(); i++)
	{
		if (mainData->inexecutionsPairs.getAt(i)->mission->mid.missionType == MOUNTAIN_MISSION_MT)
			mountainCounter++;
	}
	consolData->insertEnd(mountainCounter);
	for (int i = 0; i < mainData->inexecutionsPairs.getSize(); i++)
	{
		if (mainData->inexecutionsPairs.getAt(i)->mission->mid.missionType == MOUNTAIN_MISSION_MT)
		{
			consolData->insertEnd(mainData->inexecutionsPairs.getAt(i)->mission->mid.missionId);
			consolData->insertEnd(mainData->inexecutionsPairs.getAt(i)->rover->roverId);
		}
	}
	///////////////////////////////


	int numOfAvaliableRovers = mainData->emergencyRovers.getSize() + 
								mainData->mountainRovers.getSize() + 
								mainData->polarRovers.getSize();

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


	int numOfInCheckUpRovers =  mainData->inCheckUp_ERovers.getSize() + 
								mainData->inCheckUp_MRovers.getSize() + 
								mainData->inCheckUp_PRovers.getSize();

	consolData->insertEnd(numOfInCheckUpRovers);

	consolData->insertEnd(mainData->inCheckUp_ERovers.getSize());
	for (int i = 0; i < mainData->inCheckUp_ERovers.getSize(); i++)
		consolData->insertEnd(mainData->inCheckUp_ERovers.getAt(i)->roverId);
	
	consolData->insertEnd(mainData->inCheckUp_PRovers.getSize());
	for (int i = 0; i < mainData->inCheckUp_PRovers.getSize(); i++)
		consolData->insertEnd(mainData->inCheckUp_PRovers.getAt(i)->roverId);
	
	consolData->insertEnd(mainData->inCheckUp_MRovers.getSize());
	for (int i = 0; i < mainData->inCheckUp_MRovers.getSize(); i++)
		consolData->insertEnd(mainData->inCheckUp_MRovers.getAt(i)->roverId);
	

	consolData->insertEnd(mainData->completedMissions.getSize());
	Vector<int> completedEmergencyMissions;
	Vector<int> completedMountainMissions;
	Vector<int> completedPolarMissions;
	Node<Mission*>* a = mainData->completedMissions.getHead();
	//emerg, polar, mountain
	while (a)
	{
		if (a->getData()->mid.missionType == EMERGENCY_MISSION_MT)
			completedEmergencyMissions.insertEnd(a->getData()->mid.missionId);
		else if (a->getData()->mid.missionType == MOUNTAIN_MISSION_MT)
			completedMountainMissions.insertEnd(a->getData()->mid.missionId);
		else if (a->getData()->mid.missionType == POLAR_MISSION_MT)
			completedPolarMissions.insertEnd(a->getData()->mid.missionId);
		else
			assert(false);	
		a = a->getNext();
	}
	consolData->insertEnd(completedEmergencyMissions.getLength());
	for (int i = 0; i < completedEmergencyMissions.getLength(); i++)
		consolData->insertEnd(completedEmergencyMissions.getAt(i));

	consolData->insertEnd(completedPolarMissions.getLength());
	for (int i = 0; i < completedPolarMissions.getLength(); i++)
		consolData->insertEnd(completedPolarMissions.getAt(i));

	consolData->insertEnd(completedMountainMissions.getLength());
	for (int i = 0; i < completedMountainMissions.getLength(); i++)
		consolData->insertEnd(completedMountainMissions.getAt(i));

	return consolData;
}
