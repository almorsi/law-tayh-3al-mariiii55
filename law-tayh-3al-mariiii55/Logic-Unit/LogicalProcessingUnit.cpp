#include <cassert>
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
		sd->inexecutionsPairs.getAt(i)->increaseKeyBy(1);// key is negative

	retrieveRoversFromCheckUp();
	retrieveArrivedRovers();
	executeEvent();
	assignPairs();
}

void LogicaProcessingUnit::retrieveRoversFromCheckUp()
{
	Rover* rover;
	//key is negative checkupDuration in days
	for (long i = 0; i < sd->inCheckUp_ERovers.getSize(); i++)
		sd->inCheckUp_ERovers.getAt(i)->increaseKeyBy(1);
	for (long i = 0; i < sd->inCheckUp_MRovers.getSize(); i++)
		sd->inCheckUp_MRovers.getAt(i)->increaseKeyBy(1);
	for (long i = 0; i < sd->inCheckUp_PRovers.getSize(); i++)
		sd->inCheckUp_PRovers.getAt(i)->increaseKeyBy(1);

	while (!(sd->inCheckUp_ERovers.isEmpty())&&
		sd->inCheckUp_ERovers.getMax()->getKey() == 0)
	{
		rover = sd->inCheckUp_ERovers.extractMax();
		rover->setKey(rover->speed);
		rover->resetMissionsToCheckUp();
		sd->emergencyRovers.insert(rover);
	}
	while (!(sd->inCheckUp_MRovers.isEmpty())&&
		sd->inCheckUp_MRovers.getMax()->getKey() == 0)
	{
		rover = sd->inCheckUp_MRovers.extractMax();
		rover->setKey(rover->speed);
		rover->resetMissionsToCheckUp();
		sd->mountainRovers.insert(rover);
	}
	while (!(sd->inCheckUp_PRovers.isEmpty())&&
		sd->inCheckUp_PRovers.getMax()->getKey() == 0)
	{
		rover = sd->inCheckUp_PRovers.extractMax();
		rover->setKey(rover->speed);
		rover->resetMissionsToCheckUp();
		sd->polarRovers.insert(rover);
	}
}

void LogicaProcessingUnit::retrieveArrivedRovers()
{
	Mission* arrivedMission;
	Rover* arrivedRover;

	while (!(sd->inexecutionsPairs.isEmpty())&&
		sd->inexecutionsPairs.getMax()->getKey() == 0)
	{
		arrivedMission = sd->inexecutionsPairs.getMax()->mission;
		arrivedRover = sd->inexecutionsPairs.getMax()->rover;
		delete sd->inexecutionsPairs.extractMax();

		arrivedMission->compeletionDay = sd->currentDay;
		arrivedMission->setKey(arrivedMission->compeletionDay);
		sd->completedMissions.insert(arrivedMission);

		(arrivedRover->missionsToCheckUp)--;
		if (arrivedRover->missionsToCheckUp == 0)
		{
			arrivedRover->resetCheckUpDuration();
			arrivedRover->setKey(-(arrivedRover->checkUpDuration));// negative key
			if (arrivedRover->rovertype == EMERGENCY_ROVER_RT)
				sd->inCheckUp_ERovers.insert(arrivedRover);
			else if (arrivedRover->rovertype == MOUNTAIN_ROVER_RT)
				sd->inCheckUp_MRovers.insert(arrivedRover);
			else if (arrivedRover->rovertype == POLAR_ROVER_RT)
				sd->inCheckUp_PRovers.insert(arrivedRover);
			else
				assert(false);
		}
		else
		{
			if (arrivedRover->rovertype == EMERGENCY_ROVER_RT)
				sd->emergencyRovers.insert(arrivedRover);
			else if (arrivedRover->rovertype == MOUNTAIN_ROVER_RT)
				sd->mountainRovers.insert(arrivedRover);
			else if (arrivedRover->rovertype == POLAR_ROVER_RT)
				sd->polarRovers.insert(arrivedRover);
			else
				assert(false);
		}
	}
}

void LogicaProcessingUnit::executeEvent()
{
	Command* currentCommand;
	while (!(sd->commands.isEmpty()) &&
		sd->commands.getFront()->isTimeToExecute(sd->currentDay))
	{
		currentCommand = sd->commands.dequeue();
		currentCommand->execute(sd);
		delete currentCommand;
	}
}

void LogicaProcessingUnit::assignPairs()
{
}
