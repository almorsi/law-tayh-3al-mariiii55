#ifndef VECTOR_TEST_H
#define VECTOR_TEST_H
#include <cassert>

#include "../Data-Structures/Vector.h"

class VectorTest
{
public:
	VectorTest();
	~VectorTest();
	void runAllTests();
private:
	void initializationTest();
	void insertFirstTestAfterInsertingOneLast();
	void getLengthTestWithoutInsertion();
	void getLengthTestAfterInsertingOneItem();
	void getLengthTestAfterInsertingTwoItems();
	void getCapacityTestWithoutInsertion();
	void insertBeginFiveTimesAndinsertEndFiveTimes();
	void insert1000ItemsAtTheBegining();
	void insertBeginTheninsertEnd100Times();
	void insertEnd1000Times();
	void insertOneItemAndTestGetAt0();
	void setAtShouldThrowExecptionAfterPassingInvalidIndex();
	void setAtShouldThrowExecptionAfterPassingValidIndexButInEmptyVector();
	void setAtShouldNotThrowExecptionAfterPassingValidIndex();
	void getFirstShouldThrowExecptionOnImptyVector();
	void getFirstShouldGetTheFirstItemAfterInsertingTowToTheBeggining();
	void setFirstShouldThrowExeceptionOnEmptyVector();
	void setFirstShouldNotThrowExeceptionOnValidVector();
	void InsertBeginThenDeleteBegin();
	void insert1000ThenDelete500();
	void deleteBeginShouldThrowExecptionIfDeletingMoreThanInserting();
	void insertEndThenDeleteEnd();
	void deleteEndShouldThrowExecptionOnDeletingFromEmptyVector();
	void insertBegin1000ThenDeleteEnd500();
	void deleteEndShouldThrowExecptionOnDeletingMoreThanInserting();
	void deleteTheSameAmountAsInserting();
	void getLastShouldThrowExecptionOnEmptyVector();
	void getLastShouldNotThrowExecptionOnNonEmptyVector();
	void setLastShouldThrowExectptionOnEmptyVector();
	void setLasatShouldNotThrowExecptionOnNonEmptyVector();
	void checkIfNumbersAreInCorrectSequence();
	void reverseTheSequenceAndCheckIfInNewCorrectSeqeunce();
};
#endif