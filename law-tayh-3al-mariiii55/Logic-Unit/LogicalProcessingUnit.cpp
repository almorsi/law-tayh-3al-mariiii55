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
}
