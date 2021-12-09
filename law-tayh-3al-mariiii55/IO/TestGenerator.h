#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

#include <fstream>
#include <random>

#include "..\Data-Structures\vector.h"
#include "..\Defs.h"

class TestGenerator
{
public:
	TestGenerator(const char*);
	~TestGenerator();

	bool canGenerateTestCase() const;
	void generateTestCase();

private:
	void fillInRanges();
	void addFormulationEvent();
	void addCancelationEvent();
	void addPromotionEvent();

private:

	std::fstream fs;

	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<> range;

	Vector<int> mountainMissionIds;

	bool fileState;
	int missionId;
	int eventDay;

	Range rover;
	Range roverSpeed;
	Range missionsBeforeCheckup;
	Range checkupDuration;
	Range autoPromotionLimit;
	Range numOfEvents;
	Range eventType;
	Range targetLocation;
	Range missionDuration;
	Range significance;
	Range daysBetweenEvents;
};

#endif 