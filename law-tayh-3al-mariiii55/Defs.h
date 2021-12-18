#ifndef DEFS_H
#define DEFS_H
#include "..\law-tayh-3al-mariiii55\Data-Structures\SortedLinkedList.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\HeapNode.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\MaxHeap.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\DoublyLinkedList.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\Queue.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\Vector.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\Keyable.h"
//#include "commands/Command.h"
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
	NONE_MT = 0,
	MOUNTAIN_MISSION_MT,
	POLAR_MISSION_MT,
	EMERGENCY_MISSION_MT
};

struct MissionInputData
{
	MissionType missionType;
	int eventDay;
	int missionId;
	int targetLocation;
	int missionDuration;
	int daysToBePromoted;
	int significance;
};

enum RoverType
{
	NONE_RT = 0,
	MOUNTAIN_ROVER_RT,
	POLAR_ROVER_RT,
	EMERGENCY_ROVER_RT
};

class Mission;
class Rover;
class InExecution;
class Command;
struct StationData
{
	int currentDay;

	MaxHeap<Mission*> emergencyMissions;
	doublyLinkedList<Mission*> mountainMissions;
	Queue<Mission*> polarMissions;

	MaxHeap<Rover*> emergencyRovers;
	MaxHeap<Rover*> mountainRovers;
	MaxHeap<Rover*> polarRovers;

	MaxHeap<InExecution*> inexecutionsPairs;

	MaxHeap<Rover*> inCheckUp_ERovers;
	MaxHeap<Rover*> inCheckUp_MRovers;
	MaxHeap<Rover*> inCheckUp_PRovers;
	SortedLinkedList<Mission*> completedMissions;

	Queue<Command*> commands;
};


#endif // !DEFS_H