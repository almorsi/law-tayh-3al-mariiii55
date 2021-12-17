#ifndef DEFS_H
#define DEFS_H
#include "Data-Structures/DataStructureDefinitions.cpp"

struct Range
{
	int min, max;
};

enum EventType
{
	NONE_ET,
	FORMULATION_ET,
	CANCELATION_ET,
	PROMOTION_ET
};

enum MissionType
{
	NONE_MT,
	EMERGENCY_MISSION_MT,
	POLAR_MISSION_MT,
	MOUNTAIN_MISSION_MT
};

struct MissionInputData
{
	MissionType missionType;
	int eventDay;
	int missionId;
	int targetLocation;
	int missionDuration;
	int significance;
};

struct Mission
{
	int ID;
	int compeletionDay;
	int formlationDay;
	int assignDay;
	int waitingDays;
	int inExecutionDays;
	MissionType type;
	int targetLocation;
	int missionDuration;
	int significance;
	int daysToBePromoted;

};
enum RoverType
{
	R_NONE_RT,
	R_EMERGENCY_MISSION_MT,
	R_POLAR_MISSION_MT,
	R_MOUNTAIN_MISSION_MT
};


struct Rover
{
	RoverType rovertype;
	int checkUpDuration;
	int speed;
	int missionsToCheckUp;
};


struct inExecute
{
	int daysToFinish;
	Mission* mission;
	Rover* rover;
};

struct stationData
{
	int currentDay;
	MaxHeap emergencyMissions;
	doublyLinkedList<Mission> mountainMissions;
	Queue<Mission> polarMissions;
	MaxHeap emergencyRovers;
	MaxHeap mountainRovers;
	MaxHeap polarRovers;
	MaxHeap InexecutionsPairs; //use negative values to revrse the use of maxHeap
	SortedLinkedList completedMissions;
};


#endif // !DEFS_H
