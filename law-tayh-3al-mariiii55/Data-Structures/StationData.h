#pragma once
#include "DoublyLinkedList.h"
#include "MaxHeap.h"
#include "Queue.h"
#include "SortedLinkedList.h"
#include "..\commands\Command.h"
#include "Mission.h"
#include "Rover.h"
#include "InExecution.h"

struct StationData
{
	int currentDay;
	int promotedMissions;

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