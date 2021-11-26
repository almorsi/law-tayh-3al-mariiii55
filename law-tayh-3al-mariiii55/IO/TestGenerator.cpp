#include <algorithm>
#include "TestGenerator.h"

TestGenerator::TestGenerator(const char* fileName)
	:
	rng(rd()),
	fileState(false),
	missionId(0),
	eventDay(0)
{
	fs.open(fileName, std::fstream::out | std::fstream::trunc);
	if (fs.is_open())
		fileState = true;

	if (canGenerateTestCase())
		fillInRanges();
}

TestGenerator::~TestGenerator()
{
	if (canGenerateTestCase())
		fs.close();
}

bool TestGenerator::canGenerateTestCase() const
{
	return fileState;
}

void TestGenerator::fillInRanges()
{
	rover = { 15, 30 };
	roverSpeed = { 10, 20 };//kilometeres/hour
	missionsBeforeCheckup = { 5, 20 };
	checkupDuration = { 5, 15 };//days
	missionsBeforeCheckup = { 5, 10 };
	autoPromotionLimit = { 10, 30 };//days
	numOfEvents = { 20, 50 };
	eventType = { 0, 2 };
	targetLocation = { 100, 1000 };//kilometers
	missionDuration = { 2, 15 };//days
	significance = { 1, 10 };
	daysBetweenEvents = { 1, 3 };
}

void TestGenerator::generateTestCase()
{
	int nEvents;
	int randomEventType;

	range = std::uniform_int_distribution<>(rover.min, rover.max);
	fs << range(rng) << '\t' << range(rng) << '\t' << range(rng) << '\n';

	range = std::uniform_int_distribution<>(roverSpeed.min, roverSpeed.max);
	fs << range(rng) << '\t' << range(rng) << '\t' << range(rng) << '\n';

	range = std::uniform_int_distribution<>(checkupDuration.min, checkupDuration.max);
	fs << range(rng) << '\t' << range(rng) << '\t' << range(rng) << '\t';
	range = std::uniform_int_distribution<>(missionsBeforeCheckup.min, missionsBeforeCheckup.max);
	fs << range(rng) << '\n';

	range = std::uniform_int_distribution<>(autoPromotionLimit.min, autoPromotionLimit.max);
	fs << range(rng) << '\n';

	range = std::uniform_int_distribution<>(numOfEvents.min, numOfEvents.max);
	nEvents = range(rng);
	fs << nEvents << '\n';

	range = std::uniform_int_distribution<>(eventType.min, eventType.max);
	while ((randomEventType = range(rng)) == CANCELATION_ET)
		;

	do
	{
		switch (randomEventType)
		{
		case FORMULATION_ET:
			addFormulationEvent();
			break;
		case CANCELATION_ET:
		{
			if (mountainMissionIds.getLength() < 3)
			{
				nEvents++;
				break;
			}

			addCancelationEvent();
			break;
		}
		case PROMOTION_ET:
		{
			if (mountainMissionIds.getLength() < 3)
			{
				nEvents++;
				break;
			}

			addPromotionEvent();
			break;
		}
		default:
			break;
		}

		range = std::uniform_int_distribution<>(eventType.min, eventType.max);
		randomEventType = range(rng);

	} while (--nEvents);

}

void TestGenerator::addFormulationEvent()
{
	missionId++;

	fs << 'F' << '\t';

	range = std::uniform_int_distribution<>(1, 3);
	switch (range(rng))
	{
	case 1:
		fs << 'M' << '\t';
		mountainMissionIds.insertEnd(missionId);
		break;
	case 2:
		fs << 'P' << '\t';
		break;
	case 3:
		fs << 'E' << '\t';
		break;
	default:
		break;
	}
	
	range = std::uniform_int_distribution<>(daysBetweenEvents.min, daysBetweenEvents.max);
	eventDay += range(rng); // get random incremental day that this event will occur in
	fs << eventDay << '\t';

	fs << missionId << '\t';

	range = std::uniform_int_distribution<>(targetLocation.min, targetLocation.max);
	fs << range(rng) << '\t';

	range = std::uniform_int_distribution<>(missionDuration.min, missionDuration.max);
	fs << range(rng) << '\t';

	range = std::uniform_int_distribution<>(significance.min, significance.max);
	fs << range(rng) << '\n';
}

void TestGenerator::addCancelationEvent()
{
	int missionIndexToDelete;

	fs << 'X' << '\t';	

	range = std::uniform_int_distribution<>(daysBetweenEvents.min, daysBetweenEvents.max);
	eventDay += range(rng); // get random incremental day that this event will occur in
	fs << eventDay << '\t';
	
	//get random index from the array and cancel that index
	range = std::uniform_int_distribution<>(0, mountainMissionIds.getLength() - 1);
	missionIndexToDelete = range(rng);
	fs << mountainMissionIds.getAt(missionIndexToDelete) << '\n';

	std::swap(mountainMissionIds.getAt(missionIndexToDelete), mountainMissionIds.getLast());
	mountainMissionIds.deleteEnd();
}

void TestGenerator::addPromotionEvent()
{
	int missionIndexToPromote;

	fs << 'P' << '\t';

	range = std::uniform_int_distribution<>(daysBetweenEvents.min, daysBetweenEvents.max);
	eventDay += range(rng); // get random incremental day that this event will occur in
	fs << eventDay << '\t';

	//get random index from the array and promote that index
	range = std::uniform_int_distribution<>(0, mountainMissionIds.getLength() - 1);
	missionIndexToPromote = range(rng);
	fs << mountainMissionIds.getAt(missionIndexToPromote) << '\n';

	std::swap(mountainMissionIds.getAt(missionIndexToPromote), mountainMissionIds.getLast());
	mountainMissionIds.deleteEnd();
}
