#include <cassert>

#include "InputProcessingUnit.h"
#include "..\Data-Structures\Rover.h"
#include "..\commands\Command.h"
#include "..\commands\FormulationCommand.h"
#include "..\commands\CancellationCommand.h"
#include "..\commands\PromotionCommand.h"

#define NUM_OF_ROVER_TYPES 3

namespace IPU
{
	void buildStationData(StationData* sd, Vector<int>* inputData)
	{
		int i, j, autoPromotionLimit, numEvents;

		assert(MOUNTAIN_ROVER_RT == 1);
		assert(POLAR_ROVER_RT == 2);
		assert(EMERGENCY_ROVER_RT == 3);
		
		for (i = 0; i < NUM_OF_ROVER_TYPES; i++)
		{
			for (j = 0; j < inputData->getAt(i); j++)
			{

				Rover* rover = new Rover(RoverType(i + 1),
					inputData->getAt(i + 3),//speed
					inputData->getAt(6),//# of missions to checkup
					inputData->getAt(i + 7));// checkup duration

				if (i == 0)
					sd->mountainRovers.insert(rover);
				else if (i == 1)
					sd->polarRovers.insert(rover);
				else //i == 2
					sd->emergencyRovers.insert(rover);
			}
		}

		assert(MOUNTAIN_MISSION_MT == 1);
		assert(POLAR_MISSION_MT == 2);
		assert(EMERGENCY_MISSION_MT == 3);

		autoPromotionLimit = inputData->getAt(10);//days
		numEvents = inputData->getAt(11);

		for (i = 0, j = 12; i < numEvents; i++)
		{
			MissionInputData mid;
			char eventType = inputData->getAt(j++);
			
			if(eventType == 'F')
			{
				char missionType = inputData->getAt(j++);
				mid = { NONE_MT,
						inputData->getAt(j++), //event day
						inputData->getAt(j++), //ID
						inputData->getAt(j++), //target location
						inputData->getAt(j++), //mission duration
						autoPromotionLimit,
						inputData->getAt(j++) }; //significance

				if (missionType == 'M')
					mid.missionType = MOUNTAIN_MISSION_MT;
				else if (missionType == 'P')
					mid.missionType = POLAR_MISSION_MT;
				else //missionType == 'E'
					mid.missionType = EMERGENCY_MISSION_MT;

				sd->commands.enqueue(new FormulationCommand(mid));
			}
			else
			{
				mid.missionType = MOUNTAIN_MISSION_MT;
				mid.eventDay = inputData->getAt(j++);
				mid.missionId = inputData->getAt(j++);
				if (eventType == 'X')
					sd->commands.enqueue(new CancellationCommand(mid));
				else // eventType == 'P'
					sd->commands.enqueue(new PromotionCommand(mid));
			}

		}

	}

}
