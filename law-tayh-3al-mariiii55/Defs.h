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
};

#endif // !DEFS_H
