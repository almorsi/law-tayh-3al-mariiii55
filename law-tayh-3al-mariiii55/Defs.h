#ifndef DEFS_H
#define DEFS_H

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

#endif // !DEFS_H
