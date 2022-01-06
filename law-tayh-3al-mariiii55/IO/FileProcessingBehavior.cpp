#include "FileProcessingBehavior.h"

fileProcessingBehavior::fileProcessingBehavior(StationData* data) :ProcessingBehaviour(data)
{}

Vector<int>* fileProcessingBehavior::process()
{
	Vector<int>* fileData = new Vector<int>;
	int numMountainMissions, numPolarMissions, 
		numEmergMissions, numWaitingDays, 
		numExecutionDays, numMountainRovers, 
		numPolarRovers, numEmergRovers;
	float avgWait, avgExec, autoPromote;

	fileData->insertEnd(mainData->completedMissions.getSize());
	numMountainMissions = 
		numPolarMissions = 
		numEmergMissions = 
		numWaitingDays = 
		numExecutionDays = 
		numMountainRovers = 
		numPolarRovers = 
		numEmergRovers = 0;

	Node<Mission*>* temp = mainData->completedMissions.getHead();
	while (temp)
	{
		fileData->insertEnd(temp->getData()->compeletionDay);
		fileData->insertEnd(temp->getData()->mid.missionId);
		fileData->insertEnd(temp->getData()->formlationDay);
		fileData->insertEnd(temp->getData()->waitingDays);
		fileData->insertEnd(temp->getData()->mid.missionDuration);

		numWaitingDays += temp->getData()->waitingDays;
		numExecutionDays += temp->getData()->mid.missionDuration;

		if (temp->getData()->mid.missionType == EMERGENCY_MISSION_MT)
			numEmergMissions++;
		else if (temp->getData()->mid.missionType == POLAR_MISSION_MT)
			numPolarMissions++;
		else
			numMountainMissions++;

		temp = temp->getNext();
	}

	fileData->insertEnd(numEmergMissions + numPolarMissions + numMountainMissions);
	fileData->insertEnd(numMountainMissions);
	fileData->insertEnd(numPolarMissions);
	fileData->insertEnd(numEmergMissions);

	numMountainRovers = mainData->mountainRovers.getSize() + mainData->inCheckUp_MRovers.getSize();
	numPolarRovers = mainData->polarRovers.getSize() + mainData->inCheckUp_PRovers.getSize();
	numEmergRovers = mainData->emergencyRovers.getSize() + mainData->inCheckUp_ERovers.getSize();

	fileData->insertEnd(numMountainRovers + numPolarRovers + numEmergRovers);

	fileData->insertEnd(numMountainRovers);
	fileData->insertEnd(numPolarRovers);
	fileData->insertEnd(numEmergRovers);

	avgWait = float(numWaitingDays) / mainData->completedMissions.getSize();
	avgExec = float(numExecutionDays) / mainData->completedMissions.getSize();
	fileData->insertEnd(int(avgWait));
	fileData->insertEnd(int( ( avgWait - int(avgWait) ) * 100) );
	fileData->insertEnd(int(avgExec));
	fileData->insertEnd(int( ( avgExec - int(avgExec) ) * 100) );


	autoPromote = (mainData->promotedMissions/ float(numMountainMissions+
		                                            mainData->promotedMissions))* 100;
	fileData->insertEnd(int(autoPromote));

	return fileData;
}