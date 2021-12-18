#include "FileProcessingBehavior.h"

fileProcessingBehavior::fileProcessingBehavior(StationData* data) :processingBehaviour(data)
{}

Vector<int>* fileProcessingBehavior::process()
{
	int m = 0;
	int p = 0;
	int e = 0;
	int Wait = 0;
	int Exec = 0;
	Vector<int>* fileData = new Vector<int>;

	fileData->insertEnd(mainData->completedMissions.getSize());

	Node<Mission*>* h = mainData->completedMissions.getHead();
	while (h)
	{
		fileData->insertEnd(h->getData()->compeletionDay);
		fileData->insertEnd(h->getData()->mid.missionId);
		fileData->insertEnd(h->getData()->formlationDay);
		fileData->insertEnd(h->getData()->waitingDays);
		fileData->insertEnd(h->getData()->mid.missionDuration);

		Wait += h->getData()->waitingDays;
		Exec += h->getData()->mid.missionDuration;

		if (h->getData()->mid.missionType == EMERGENCY_MISSION_MT)
			e++;
		else if (h->getData()->mid.missionType == POLAR_MISSION_MT)
			p++;
		else
			m++;
		h = h->getNext();
	}

	fileData->insertEnd(m);
	fileData->insertEnd(p);
	fileData->insertEnd(e);

	fileData->insertEnd(mainData->emergencyRovers.getSize() + mainData->emergencyRovers.getSize() + mainData->mountainRovers.getSize() + mainData->polarRovers.getSize() + mainData->inCheckUp_ERovers.getSize() + mainData->inCheckUp_MRovers.getSize() + mainData->inCheckUp_PRovers.getSize());
	fileData->insertEnd(mainData->mountainRovers.getSize() + mainData->inCheckUp_MRovers.getSize());
	fileData->insertEnd(mainData->polarRovers.getSize() + mainData->inCheckUp_PRovers.getSize());
	fileData->insertEnd(mainData->emergencyRovers.getSize() + mainData->inCheckUp_ERovers.getSize());

	float avgWait = float(Wait) / mainData->completedMissions.getSize();
	float avgExec = float(Exec) / mainData->completedMissions.getSize();
	fileData->insertEnd(int(avgWait));
	fileData->insertEnd((avgWait - int(avgWait)) * 100);
	fileData->insertEnd(int(avgExec));
	fileData->insertEnd((avgExec - int(avgExec)) * 100);

	float autoPromote = (mainData->mountainMissions.getSize() / 1) * 100;//instead of 1 waitning for atuomatically prommated missions 


	return fileData;
}