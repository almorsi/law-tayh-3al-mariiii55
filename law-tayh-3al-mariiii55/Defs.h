#ifndef DEFS_H
#define DEFS_H

struct Range
{
	int min, max;
};

enum ConsoleRunMode
{
	NONE_CRM,
	INTERACTIVE_CRM,
	STEP_CRM,
	SILENT_CRM
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

#endif // !DEFS_H
