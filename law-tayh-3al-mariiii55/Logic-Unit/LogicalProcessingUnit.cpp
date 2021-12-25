#include "LogicalProcessingUnit.h"

LogicaProcessingUnit::LogicaProcessingUnit(StationData* stationDataPtr)
	:
	sd(stationDataPtr)
{
}

LogicaProcessingUnit::~LogicaProcessingUnit()
{
}

void LogicaProcessingUnit::updateStationData()
{
	(sd->currentDay)++;
	for (long i = 0; i < sd->inexecutionsPairs.getSize(); i++)
		sd->inexecutionsPairs.getAt(i)->decrementKeyBy(1);

	retrieveRoversFromCheckUp();
	retrieveArrivedRovers();
	executeEvent();
	assignPairs();
}

void LogicaProcessingUnit::retrieveRoversFromCheckUp()
{
}

void LogicaProcessingUnit::retrieveArrivedRovers()
{
}

void LogicaProcessingUnit::executeEvent()
{
}

void LogicaProcessingUnit::assignPairs()
{
	int inExday = 0;
	Mission* mis;
	Rover* rov;
	while (!sd->emergencyMissions.isEmpty())
	{
		mis = sd->emergencyMissions.getMax();
		mis->assignDay = sd->currentDay;
		mis->waitingDays = mis->assignDay - mis->formlationDay;
		if (!sd->emergencyRovers.isEmpty())
		{
			rov = sd->emergencyRovers.getMax();
			inExday = (2 * mis->mid.targetLocation / rov->speed) / 25 + mis->mid.missionDuration;
			InExecution* em = new InExecution(sd->emergencyMissions.extractMax(), sd->emergencyRovers.extractMax(), -1 * inExday);
			sd->inexecutionsPairs.insert(em);
		}
		else if (!sd->mountainRovers.isEmpty())
		{
			rov = sd->mountainRovers.getMax();
			inExday = (2 * mis->mid.targetLocation / rov->speed) / 25 + mis->mid.missionDuration;
			InExecution* em = new InExecution(sd->emergencyMissions.extractMax(), sd->mountainRovers.extractMax(), -1 * inExday);
			sd->inexecutionsPairs.insert(em);
		}
		else if (!sd->polarRovers.isEmpty())
			{
				rov = sd->polarRovers.getMax();
				inExday = (2 * mis->mid.targetLocation / rov->speed) / 25 + mis->mid.missionDuration;
				InExecution* em = new InExecution(sd->emergencyMissions.extractMax(), sd->polarRovers.extractMax(), -1 * inExday);
				sd->inexecutionsPairs.insert(em);
			}
		else
			return;
	}
	while(!sd->polarMissions.isEmpty()&& !sd->polarRovers.isEmpty())
	{
		mis = sd->polarMissions.getFront();
		mis->assignDay = sd->currentDay;
		mis->waitingDays = mis->assignDay - mis->formlationDay;
		rov = sd->polarRovers.getMax();
		inExday = (2 * mis->mid.targetLocation / rov->speed) / 25 + mis->mid.missionDuration;
		InExecution* em = new InExecution(sd->polarMissions.dequeue(), sd->polarRovers.extractMax(), -1 * inExday);
		sd->inexecutionsPairs.insert(em);
	}
	while(sd->mountainMissions.getSize() > 0)
	{
		if (!sd->mountainRovers.isEmpty())
		{
			doublyNode<Mission*>* h = sd->mountainMissions.getHead();
			mis = sd->mountainMissions.getHead()->getData();
			mis->assignDay = sd->currentDay;
			mis->waitingDays = mis->assignDay - mis->formlationDay;
			rov = sd->mountainRovers.getMax();
			inExday = (2 * mis->mid.targetLocation / rov->speed) / 25 + mis->mid.missionDuration;
			InExecution* em = new InExecution(mis, sd->mountainRovers.extractMax(), inExday);
			sd->mountainMissions.removeItem(h);
		}
		else if (!sd->emergencyRovers.isEmpty())
		{
			doublyNode<Mission*>* h = sd->mountainMissions.getHead();
			mis = sd->mountainMissions.getHead()->getData();
			mis->assignDay = sd->currentDay;
			mis->waitingDays = mis->assignDay - mis->formlationDay;
			rov = sd->emergencyRovers.getMax();
			inExday = (2 * mis->mid.targetLocation / rov->speed) / 25 + mis->mid.missionDuration;
			InExecution* em = new InExecution(mis, sd->emergencyRovers.extractMax(), inExday);
			sd->mountainMissions.removeItem(h);
		}
		else
			return;
	}
}
