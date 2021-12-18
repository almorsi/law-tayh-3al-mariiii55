#ifndef DEFS_H
#define DEFS_H
#include "..\law-tayh-3al-mariiii55\Data-Structures\SortedLinkedList.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\HeapNode.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\MaxHeap.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\DoublyLinkedList.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\Queue.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\Vector.h"
#include "..\law-tayh-3al-mariiii55\Data-Structures\Keyable.h"
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

enum RoverType
{
	NONE_RT,
	EMERGENCY_ROVER_RT,
	POLAR_ROVER_RT,
	MOUNTAIN_ROVER_RT
};

class Mission;
class Rover;
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