#pragma once
#include "..\Data-Structures\StationData.h"

class LogicaProcessingUnit
{
public:
	LogicaProcessingUnit(StationData*);
	~LogicaProcessingUnit();
	void updateStationData();

private:
	void retrieveRoversFromCheckUp();
	void retrieveArrivedRovers();
	void executeEvent();
	void assignPairs();

private:
	StationData* sd;
};
